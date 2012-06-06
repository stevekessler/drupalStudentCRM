<?php

/**
 * @file
 * Class definition of CRMFeedsAdvisorRelationProcessor.
 */
 
/**
 * Creates relations from feed items.
 */
class CRMFeedsAdvisorRelationProcessor extends FeedsProcessor {
  /**
   * Define entity type.
   */
  public function entityType() {
    return 'relation';
  }

  /**
   * Implements parent::entityInfo().
   */
  protected function entityInfo() {
    $info = parent::entityInfo();
    $info['label plural'] = t('Advisor records');
    return $info;
  }

  /**
   * Creates a new advisor relation in memory and returns it.
   */
  public function newRelation(FeedsSource $source, $item) {
    $contact = crm_core_contact_load($item['student_entity']);
    $relation = relation_create('advisor', array(
                    array('entity_type' => 'user',
                          'entity_bundle' => 'user', 
                          'entity_id' => $item['advisor_entity'],
                          'r_index' => 0,
                         ),
                    array('entity_type' => 'crm_core_contact',
                          'entity_bundle' => $contact->type, 
                          'entity_id' => $contact->contact_id,
                          'r_index' => 1,
                          ),
                    )
               );
    $relation->changed = REQUEST_TIME;
    $relation->created = REQUEST_TIME;
    $relation->language = LANGUAGE_NONE;
    $relation->uid = $item['advisor_entity'];
    return $relation;
  }
  
  protected function newEntity(FeedsSource $source) {
  
    return NULL;
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

    while ($item = $parser_result->shiftItem()) {
      $item['advisor_entity'] = $this->getTargetEntity($item['advisor_id'], 'user');
      $item['student_entity'] = $this->getTargetEntity($item['student_id'], 'crm_core_contact');
      if ($item['advisor_entity'] && $item['student_entity'] && !($entity_id = $this->existingEntityId($source, $parser_result)) ||
           ($this->config['update_existing'] != FEEDS_SKIP_EXISTING)) {

        // Only proceed if item has actually changed.
        $hash = $this->hash($item);
        if (!empty($entity_id) && $hash == $this->getHash($entity_id)) {
          continue;
        }
        
        try {
          // Assemble relation, map item to it, save.
          if (empty($entity_id)) {
            $entity = $this->newRelation($source, $item);
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
   * Loads an existing advisor relation.
   *
   * If the update existing method is not FEEDS_UPDATE_EXISTING, only the advisor relation
   * table will be loaded, foregoing the relation_load API for better performance.
   */
  protected function entityLoad(FeedsSource $source, $relation_id) {
    if ($this->config['update_existing'] == FEEDS_UPDATE_EXISTING) {
      $relation = relation_load($relation_id, NULL, TRUE);
    }
    else {
      // We're replacing the existing advisor relation. Only save the absolutely necessary.
      $relation = db_query("SELECT created, rid, vid, type FROM {relation} WHERE rid = :rid", array(':rid' => $relation_id))->fetchObject();
      $relation->uid = $this->config['author'];
    }
    // Populate properties that are set by advisor relation_object_prepare().
    return $relation;
  }

  /**
   * Save a advisor relation.
   */
  public function entitySave($entity) {
    relation_save($entity);
  }

  /**
   * Delete a series of relations.
   */
  protected function entityDeleteMultiple($relation_ids) {
    relation_multiple_delete($relation_ids);
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
    $relations = db_query_range("SELECT c.rid FROM {relation} c JOIN {feeds_item} fi ON fi.entity_type = 'relation' AND c.rid = fi.entity_id WHERE fi.id = :id AND c.created < :created", 0, $count, array(':id' => $this->id, ':created' => REQUEST_TIME - $time));
    $relation_ids = array();
    foreach ($relations as $relation) {
      $relation_ids[$relation->rid] = $relation->rid;
    }
    $this->entityDeleteMultiple($relation_ids);
    if (db_query_range("SELECT 1 FROM {relation} c JOIN {feeds_item} fi ON fi.entity_type = 'relation' AND c.rid = fi.entity_id WHERE fi.id = :id AND c.created < :created", 0, 1, array(':id' => $this->id, ':created' => REQUEST_TIME - $time))->fetchField()) {
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
   * Override parent::configDefaults().
   */
  public function configDefaults() {
    return array(
      'expire' => FEEDS_EXPIRE_NEVER,
      'author' => 0,
    ) + parent::configDefaults();
  }

  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);
    
    $author = user_load($this->config['author']);
    $form['author'] = array(
      '#type' => 'textfield',
      '#title' => t('Author'),
      '#description' => t('Select the author of the relations to be created - leave empty to assign "anonymous".'),
      '#autocomplete_path' => 'user/autocomplete',
      '#default_value' => empty($author->name) ?  'anonymous' : check_plain($author->name),
    );
    $period = drupal_map_assoc(array(FEEDS_EXPIRE_NEVER, 3600, 10800, 21600, 43200, 86400, 259200, 604800, 2592000, 2592000 * 3, 2592000 * 6, 31536000), 'feeds_format_expire');
    $form['expire'] = array(
      '#type' => 'select',
      '#title' => t('Expire relations'),
      '#options' => $period,
      '#description' => t('Select after how much time relations should be deleted. The advisor relation\'s published date will be used for determining the advisor relation\'s age, see Mapping settings.'),
      '#default_value' => $this->config['expire'],
    );
    $form['update_existing']['#options'] = array(
      FEEDS_SKIP_EXISTING => 'Do not update existing relations',
      FEEDS_REPLACE_EXISTING => 'Replace existing relations',
      FEEDS_UPDATE_EXISTING => 'Update existing relations (slower than replacing them)',
    );
    return $form;
  }

  /**
   * Override parent::configFormValidate().
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
   * Override setTargetElement to operate on a target item that is a advisor relation.
   */
  public function setTargetElement(FeedsSource $source, $target_relation, $target_element, $value) {
    switch ($target_element) {
      case 'created':
        $target_relation->created = feeds_to_unixtime($value, REQUEST_TIME);
        break;
      case 'feeds_source':
        // Get the class of the feed advisor relation importer's fetcher and set the source
        // property. See feeds_advisor relation_update() how $relation->feeds gets stored.
        if ($id = feeds_get_importer_id('advisor')) {
          $class = get_class(feeds_importer($id)->fetcher);
          $target_relation->feeds[$class]['source'] = $value;
          // This effectively suppresses 'import on submission' feature.
          // See feeds_advisor relation_insert().
          $target_relation->feeds['suppress_import'] = TRUE;
        }
        break;
      default:
        parent::setTargetElement($source, $target_relation, $target_element, $value);
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
        'description' => t('Whether a advisor relation is published or not. 1 stands for published, 0 for not published.'),
      ),
      'created' => array(
        'name' => t('Published date'),
        'description' => t('The UNIX time when a advisor relation has been created.'),
      ),
      'student_id' => array(
        'name' => t('Student ID'),
        'description' => t('The ID of the student.'),
      ),
      'advisor_id' => array(
        'name' => t('Advisor Unique ID'),
        'description' => t('Unique ID of the advisor.'),
      ),
    );

    // If the target content type is a Feed advisor relation, expose its source field.
    if ($id = feeds_get_importer_id('advisor')) {
      $name = feeds_importer($id)->config['name'];
      $targets['feeds_source'] = array(
        'name' => t('Feed source'),
        'description' => t('The relation created by this processor is a Feed Node, it represents a source itself. Depending on the fetcher selected on the importer "@importer", this field is expected to be for example a URL or a path to a file.', array('@importer' => $name)),
        'optional_unique' => TRUE,
      );
    }

    // Let other modules expose mapping targets.
    self::loadMappers();
    feeds_alter('feeds_processor_targets', $targets, 'relation', 'advisor');

    return $targets;
  }

  /**
   * Get rid of an existing feed item advisor relation if available.
   */
  protected function existingEntityId(FeedsSource $source, FeedsParserResult $result) {
    if ($relation_id = parent::existingEntityId($source, $result)) {
      return $relation_id;
    }

    // Iterate through all unique targets and test whether they do already
    // exist in the database.
    foreach ($this->uniqueTargets($source, $result) as $target => $value) {
      switch ($target) {
        case 'rid':
          $relation_id = db_query("SELECT rid FROM {relation} WHERE rid = :rid", array(':rid' => $value))->fetchField();
          break;
        case 'feeds_source':
          if ($id = feeds_get_importer_id('advisor')) {
            $relation_id = db_query("SELECT fs.feed_rid FROM {relation} c JOIN {feeds_source} fs ON c.rid = fs.feed_rid WHERE fs.id = :id AND fs.source = :source", array(':id' => $id, ':source' => $value))->fetchField();
          }
          break;
      }
      if ($relation_id) {
        // Return with the first rid found.
        return $relation_id;
      }
    }
    return 0;
  }
}
