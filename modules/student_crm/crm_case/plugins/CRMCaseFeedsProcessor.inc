<?php

/**
 * @file
 * Class definition of CRMCaseFeedsProcessor.
 */
 
/**
 * Creates activities from feed items.
 */
class CRMCaseFeedsProcessor extends FeedsProcessor {
  /**
   * Define entity type.
   */
  public function entityType() {
    return 'crm_case';
  }

  /**
   * Implements parent::entityInfo().
   */
  protected function entityInfo() {
    $info = parent::entityInfo();
    $info['label plural'] = t('Activity records');
    return $info;
  }

  /**
   * Creates a new crm_case crm_case in memory and returns it.
   */
  public function newCase(FeedsSource $source, $item) {
      $crm_case = crm_case_create(array('type' => $this->config['case_type'], 'name' => $item['name']));
      $crm_case->crm_contact_id = $item['student_entity'];
      if($item['author_name']) {
        $author = db_select('users', 'u')
                  ->fields('u', array('uid'))
                  ->condition('u.name', $item['author_name'])
                  ->execute()
                  ->fetchField();
        if($author) {
          $crm_case->uid = $author;
        }
      }
      return $crm_case;
  }
  
  protected function newEntity(FeedsSource $source) {
  
    return null;
  }
  
  private function getTargetEntity($id, $type) {
    return db_select('feeds_item', 'i')
             ->condition('i.entity_type', $type)
             ->condition('i.guid', $id)
             ->fields('i', array('entity_id'))
             ->execute()
             ->fetchField();
  }
  
  public function process(FeedsSource $source, FeedsParserResult $parser_result) {
    $state = $source->state(FEEDS_PROCESS);
    $mappings = $this->config['mappings'];
    foreach($mappings as $map) {
      if($map['target'] == 'student_id') {
        $student_id_key = $map['source'];
      }
      if($map['target'] == 'author_name') {
        $author_name_key = $map['source'];
      }
      if($map['target'] == 'name') {
        $name_key = $map['source'];
      }
    }
    while ($item = $parser_result->shiftItem()) {
      $item['author_name'] = $item[$author_name_key];
      $item['name'] = $item[$name_key];
      $item['student_entity'] = $this->getTargetEntity($item[$student_id_key], 'crm_core_contact');
      if (!($entity_id = $this->existingEntityId($source, $parser_result)) ||
           ($this->config['update_existing'] != FEEDS_SKIP_EXISTING)) {

        // Only proceed if item has actually changed.
        $hash = $this->hash($item);
        if (!empty($entity_id) && $hash == $this->getHash($entity_id)) {
          continue;
        }
        
        try {
          // Assemble crm_case, map item to it, save.
          if (empty($entity_id)) {
            $entity = $this->newCase($source, $item);
            $this->newItemInfo($entity, $source->feed_nid, $hash);
          }
          else {
            $entity = $this->entityLoad($source, $entity_id);
            // The feeds_item table is always updated with the info for the most recently processed entity.
            // The only carryover is the entity_id.
            $this->newItemInfo($entity, $source->feed_nid, $hash);
            $entity->feeds_item->entity_id = $entity_id;
          }
          $this->map($source, $parser_result, $entity);
          $this->entityValidate($entity);
          $this->entitySave($entity);

          // Track progress.
          if (empty($entity_id)) {
            $state->created++;
          }
          else {
            $state->updated++;
          }
        }
        catch (Exception $e) {
          $state->failed++;
          drupal_set_message($e->getMessage(), 'warning');
          $message = $e->getMessage();
          $message .= '<h3>Original item</h3>';
          $message .= '<pre>' . var_export($item, TRUE) . '</pre>';
          $message .= '<h3>Entity</h3>';
          $message .= '<pre>' . var_export($entity, TRUE) . '</pre>';
          $source->log('import', $message, array(), WATCHDOG_ERROR);
        }
      }
    }

    // Set messages if we're done.
    if ($source->progressImporting() != FEEDS_BATCH_COMPLETE) {
      return;
    }
    $info = $this->entityInfo();
    $tokens = array(
      '@entity' => strtolower($info['label']),
      '@entities' => strtolower($info['label plural']),
    );
    $messages = array();
    if ($state->created) {
      $messages[] = array(
       'message' => format_plural(
          $state->created,
          'Created @number @entity.',
          'Created @number @entities.',
          array('@number' => $state->created) + $tokens
        ),
      );
    }
    if ($state->updated) {
      $messages[] = array(
       'message' => format_plural(
          $state->updated,
          'Updated @number @entity.',
          'Updated @number @entities.',
          array('@number' => $state->updated) + $tokens
        ),
      );
    }
    if ($state->failed) {
      $messages[] = array(
       'message' => format_plural(
          $state->failed,
          'Failed importing @number @entity.',
          'Failed importing @number @entities.',
          array('@number' => $state->failed) + $tokens
        ),
        'level' => WATCHDOG_ERROR,
      );
    }
    if (empty($messages)) {
      $messages[] = array(
        'message' => t('There are no new @entities.', array('@entities' => strtolower($info['label plural']))),
      );
    }
    foreach ($messages as $message) {
      drupal_set_message($message['message']);
      $source->log('import', $message['message'], array(), isset($message['level']) ? $message['level'] : WATCHDOG_INFO);
    }
  }

  /**
   * Loads an existing crm_case crm_case.
   *
   * If the update existing method is not FEEDS_UPDATE_EXISTING, only the crm_case crm_case
   * table will be loaded, foregoing the crm_case_load API for better performance.
   */
  protected function entityLoad(FeedsSource $source, $cid) {
    if ($this->config['update_existing'] == FEEDS_UPDATE_EXISTING) {
      $crm_case = crm_case_load($cid, NULL, TRUE);
    }
    else {
      // We're replacing the existing crm_case crm_case. Only save the absolutely necessary.
      $crm_case = db_query("SELECT created, cid, vid, type FROM {crm_case} WHERE cid = :cid", array(':cid' => $cid))->fetchObject();
      $crm_case->uid = $this->config['author'];
    }
    // Populate properties that are set by crm_case crm_case_object_prepare().
    if ($this->config['update_existing'] == FEEDS_UPDATE_EXISTING) {
      $crm_case->log = 'Updated by CRMFeedsCourseEnrollmentProcessor';
    }
    else {
      $crm_case->log = 'Replaced by CRMFeedsCourseEnrollmentProcessor';
    }
    return $crm_case;
  }

  /**
   * Save a crm_case crm_case.
   */
  public function entitySave($entity) {
    $contact = crm_core_contact_load($entity->crm_contact_id);
    crm_case_save($entity);
    
    $relation = relation_create('crm_contact_case', array(
                    array('entity_type' => 'crm_case',
                          'entity_bundle' => $entity->type,
                          'entity_id' => $entity->cid,
                          'r_index' => 0,
                          ),
                    array('entity_type' => 'crm_core_contact',
                          'entity_bundle' => $contact->type, 
                          'entity_id' => $contact->contact_id,
                          'r_index' => 1,
                          )
                          )
               );
    $relation->changed = REQUEST_TIME;
    $relation->created = REQUEST_TIME;
    $relation->language = LANGUAGE_NONE;
    relation_save($relation);
  }

  /**
   * Delete a series of activities.
   */
  protected function entityDeleteMultiple($cids) {
    crm_case_multiple_delete($cids);
  }

  /**
   * Implement expire().
   *
   * @todo: move to processor stage?
   */
  public function expire($time = NULL) {
    if ($time === NULL) {
      $time = $this->expiryTime();
    }
    if ($time == FEEDS_EXPIRE_NEVER) {
      return;
    }
    $count = $this->getLimit();
    $activities = db_query_range("SELECT c.cid FROM {crm_case} c JOIN {feeds_item} fi ON fi.entity_type = 'crm_case' AND c.cid = fi.entity_id WHERE fi.id = :id AND c.created < :created", 0, $count, array(':id' => $this->id, ':created' => REQUEST_TIME - $time));
    $cids = array();
    foreach ($activities as $crm_case) {
      $cids[$crm_case->cid] = $crm_case->cid;
    }
    $this->entityDeleteMultiple($cids);
    if (db_query_range("SELECT 1 FROM {crm_case} c JOIN {feeds_item} fi ON fi.entity_type = 'crm_case' AND c.cid = fi.entity_id WHERE fi.id = :id AND c.created < :created", 0, 1, array(':id' => $this->id, ':created' => REQUEST_TIME - $time))->fetchField()) {
      return FEEDS_BATCH_ACTIVE;
    }
    return FEEDS_BATCH_COMPLETE;
  }

  /**
   * Return expiry time.
   */
  public function expiryTime() {
    return $this->config['expire'];
  }
  
  /**
   * Overcide parent::configDefaults().
   */
  public function configDefaults() {
    return array(
      'expire' => FEEDS_EXPIRE_NEVER,
      'author' => 0,
      'case_type' => 'note',
    ) + parent::configDefaults();
  }

  /**
   * Overcide parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);
    
    $author = user_load($this->config['author']);
    $form['author'] = array(
      '#type' => 'textfield',
      '#title' => t('Author'),
      '#description' => t('Select the author of the activities to be created - leave empty to assign "anonymous".'),
      '#autocomplete_path' => 'user/autocomplete',
      '#default_value' => empty($author->name) ?  'anonymous' : check_plain($author->name),
    );
    
    $case_types = crm_case_get_types();
    $types = array();
    foreach($case_types as $type) {
      $types[$type->type] = $type->label;
    }
    $form['case_type'] = array(
      '#type' => 'select',
      '#title' => t('Activity type'),
      '#description' => t('Select the type of activities to create..', array('!feed_id' => $this->id)),
      '#options' => $types,
      '#default_value' => $this->config['case_type'],
    );
    $period = drupal_map_assoc(array(FEEDS_EXPIRE_NEVER, 3600, 10800, 21600, 43200, 86400, 259200, 604800, 2592000, 2592000 * 3, 2592000 * 6, 31536000), 'feeds_format_expire');
    $form['expire'] = array(
      '#type' => 'select',
      '#title' => t('Expire activities'),
      '#options' => $period,
      '#description' => t('Select after how much time activities should be deleted. The crm_case crm_case\'s published date will be used for determining the crm_case crm_case\'s age, see Mapping settings.'),
      '#default_value' => $this->config['expire'],
    );
    $form['update_existing']['#options'] = array(
      FEEDS_SKIP_EXISTING => 'Do not update existing activities',
      FEEDS_REPLACE_EXISTING => 'Replace existing activities',
      FEEDS_UPDATE_EXISTING => 'Update existing activities (slower than replacing them)',
    );
    return $form;
  }

  /**
   * Overcide parent::configFormValidate().
   */
  public function configFormValidate(&$values) {
    if ($author = user_load_by_name($values['author'])) {
      $values['author'] = $author->uid;
    }
    else {
      $values['author'] = 0;
    }
  }

  /**
   * Reschedule if expiry time changes.
   */
  public function configFormSubmit(&$values) {
    if ($this->config['expire'] != $values['expire']) {
      feeds_reschedule($this->id);
    }
    parent::configFormSubmit($values);
  }

  /**
   * Overcide setTargetElement to operate on a target item that is a crm_case crm_case.
   */
  public function setTargetElement(FeedsSource $source, $target_crm_case, $target_element, $value) {
    switch ($target_element) {
      case 'created':
        $target_crm_case->created = feeds_to_unixtime($value, REQUEST_TIME);
        break;
      case 'feeds_source':
        // Get the class of the feed crm_case crm_case importer's fetcher and set the source
        // property. See feeds_crm_case crm_case_update() how $crm_case->feeds gets stored.
        if ($id = feeds_get_importer_id('crm_case')) {
          $class = get_class(feeds_importer($id)->fetcher);
          $target_crm_case->feeds[$class]['source'] = $value;
          // This effectively suppresses 'import on submission' feature.
          // See feeds_crm_case crm_case_insert().
          $target_crm_case->feeds['suppress_import'] = TRUE;
        }
        break;
      default:
        parent::setTargetElement($source, $target_crm_case, $target_element, $value);
        break;
    }
  }

  /**
   * Return available mapping targets.
   */
  public function getMappingTargets() {
    $targets = parent::getMappingTargets();
    
    $targets += array(
      'status' => array(
        'name' => t('Published status'),
        'description' => t('Whether a crm_case crm_case is published or not. 1 stands for published, 0 for not published.'),
      ),
      'created' => array(
        'name' => t('Published date'),
        'description' => t('The UNIX time when a crm_case crm_case has been created.'),
      ),
      'name' => array(
        'name' => t('Case name'),
        'description' => t('The name of the case.'),
      ),
      'student_id' => array(
        'name' => t('Student ID'),
        'description' => t('The ID of the student.'),
      ),
      'author_name' => array(
        'name' => t('Author username'),
        'description' => t('The username of the author.'),
      ),
    );

    // If the target content type is a Feed crm_case crm_case, expose its source field.
    if ($id = feeds_get_importer_id('crm_case')) {
      $name = feeds_importer($id)->config['name'];
      $targets['feeds_source'] = array(
        'name' => t('Feed source'),
        'description' => t('The activity created by this processor is a Feed Node, it represents a source itself. Depending on the fetcher selected on the importer "@importer", this field is expected to be for example a URL or a path to a file.', array('@importer' => $name)),
        'optional_unique' => TRUE,
      );
    }

    // Let other modules expose mapping targets.
    self::loadMappers();
    feeds_alter('feeds_processor_targets', $targets, 'crm_case', $this->config['case_type']);

    return $targets;
  }

  /**
   * Get cid of an existing feed item crm_case crm_case if available.
   */
  protected function existingEntityId(FeedsSource $source, FeedsParserResult $result) {
    if ($cid = parent::existingEntityId($source, $result)) {
      return $cid;
    }

    // Iterate through all unique targets and test whether they do already
    // exist in the database.
    foreach ($this->uniqueTargets($source, $result) as $target => $value) {
      switch ($target) {
        case 'cid':
          $cid = db_query("SELECT cid FROM {crm_case} WHERE cid = :cid", array(':cid' => $value))->fetchField();
          break;
        case 'feeds_source':
          if ($id = feeds_get_importer_id('crm_case')) {
            $cid = db_query("SELECT fs.feed_cid FROM {crm_case} c JOIN {feeds_source} fs ON c.cid = fs.feed_cid WHERE fs.id = :id AND fs.source = :source", array(':id' => $id, ':source' => $value))->fetchField();
          }
          break;
      }
      if ($cid) {
        // Return with the first cid found.
        return $cid;
      }
    }
    return 0;
  }
}
