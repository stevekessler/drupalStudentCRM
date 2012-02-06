<?php

/**
 * @file
 * Class definition of CRMStudentAddresses.
 */
 
/**
 * Creates relations from feed items.
 */
class CRMStudentAddresses extends FeedsProcessor {
  /**
   * Define entity type.
   */
  public function entityType() {
    return 'crm_core_contact_address';
  }

  /**
   * Implements parent::entityInfo().
   */
  protected function entityInfo() {
    $info = parent::entityInfo();
    $info['label plural'] = t('Contact addresses');
    return $info;
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
    foreach ($mappings as $map) {
      if ($map['target'] == 'student_id') {
        $student_id_key = $map['source'];
      }
    }
    while ($item = $parser_result->shiftItem()) {
      $address = array();
      foreach ($mappings as $mapping) {
        $address[$mapping['target']] = $item[$mapping['source']];
      }
      if (!$address['country']) {
        $address['country'] = $this->config['default_country'];
      }
      $address['contact_entity'] = $this->getTargetEntity($item[$student_id_key], 'crm_core_contact');
      if (!$address_id = $this->existingEntityId($source, $parser_result) && $address['thoroughfare'] && $address['contact_entity']) {

        // Only proceed if item has actually changed.
        $hash = md5($address['guid']);
        if ($hash == $this->getHash($address['guid'])) {
          continue;
        }
        
        try {
          $entity = crm_core_contact_load($address['contact_entity']);
          $language = ($entity->language) ? $entity->language : LANGUAGE_NONE;
          foreach($entity->field_contact_address[$language] as $k => $existing_address) {
            unset($existing_address['country']);
            $delete = true;
            foreach($existing_address as $type => $value) {
              if($value) {
                $delete = false;
                continue;
              }
            }
            if($delete) {
              unset($entity->field_contact_address[$language][$k]);
            }
          }
          $entity->field_contact_address[$language][] = $address;
          crm_core_contact_save($entity);
          $feed_item = (object)array(
                          'feeds_item' => array(
                            'entity_id' => $entity->contact_id,
                            'guid' => $address['guid'],
                            'entity_type' => 'crm_core_contact_address',
                            'feed_nid' => 0,
                            'url' => '',
                            'hash' => md5($address['guid']),
                          ),
                          
                        );
          feeds_item_info_insert($feed_item, $address['guid']);
          $state->updated++;
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
      $relation = db_query("SELECT created, rid, vid, type FROM {crm_core_contact} WHERE rid = :rid", array(':rid' => $relation_id))->fetchObject();
      $relation->uid = $this->config['author'];
    }
    // Populate properties that are set by advisor relation_object_prepare().
    return $relation;
  }

  /**
   * Save a advisor relation.
   */
  public function entitySave($entity) {

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
    $relations = db_query_range("SELECT c.rid FROM {crm_core_contact} c JOIN {feeds_item} fi ON fi.entity_type = 'relation' AND c.rid = fi.entity_id WHERE fi.id = :id AND c.created < :created", 0, $count, array(':id' => $this->id, ':created' => REQUEST_TIME - $time));
    $relation_ids = array();
    foreach ($relations as $relation) {
      $relation_ids[$relation->rid] = $relation->rid;
    }
    $this->entityDeleteMultiple($relation_ids);
    if (db_query_range("SELECT 1 FROM {crm_core_contact} c JOIN {feeds_item} fi ON fi.entity_type = 'relation' AND c.rid = fi.entity_id WHERE fi.id = :id AND c.created < :created", 0, 1, array(':id' => $this->id, ':created' => REQUEST_TIME - $time))->fetchField()) {
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
      'default_country' => 'US',
    ) + parent::configDefaults();
  }

  /**
   * Override parent::configForm().
   */
  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);
    
    $form['default_country'] = array(
      '#type' => 'textfield',
      '#title' => t('Default country code'),
      '#description' => t('Provide the default country code if no code is available.'),
      '#default_value' => $this->config['default_country'],
    );
    
    return $form;
  }

  /**
   * Override parent::configFormValidate().
   */
  public function configFormValidate(&$values) {

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
        if ($id = feeds_get_importer_id('address')) {
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
      'country' => array(
        'name' => t('Country'),
        'description' => t('The two-letter country code.'),
      ),
      'administrative_area' => array(
        'name' => t('Administrative area (state)'),
      ),
      'sub_administrative_area' => array(
        'name' => t('Sub-administrative area'),
      ),
      'locality' => array(
        'name' => t('Locality (city)'),
        'description' => t('The two-letter country code.'),
      ),
      'dependent_locality' => array(
        'name' => t('Dependent locality'),
      ),
      'postal_code' => array(
        'name' => t('Postal code'),
      ),
      'thoroughfare' => array(
        'name' => t('Thoroughfare (Street address)'),
      ),
      'sub_premise' => array(
        'name' => t('Sub-Premise'),
      ),
      'organisation_name' => array(
        'name' => t('Organization name'),
      ),
    );

    // If the target content type is a Feed advisor relation, expose its source field.
    if ($id = feeds_get_importer_id('address')) {
      $name = feeds_importer($id)->config['name'];
      $targets['feeds_source'] = array(
        'name' => t('Feed source'),
        'description' => t('The relation created by this processor is a Feed Node, it represents a source itself. Depending on the fetcher selected on the importer "@importer", this field is expected to be for example a URL or a path to a file.', array('@importer' => $name)),
        'optional_unique' => TRUE,
      );
    }

    // Let other modules expose mapping targets.
    self::loadMappers();
    
    return $targets;
  }

  /**
   * Get rid of an existing feed item advisor relation if available.
   */
  protected function existingEntityId(FeedsSource $source, FeedsParserResult $result) {
    if ($relation_id = parent::existingEntityId($source, $result)) {
      return $relation_id;
    }
    foreach($this->uniqueTargets($source, $result) as $target => $value) {
      $address_id = db_select('feeds_item', 'i')
             ->condition('i.entity_type', 'crm_core_contact_address')
             ->condition('i.guid', $value)
             ->fields('i', array('entity_id'))
             ->execute()
             ->fetchField();
      if($address_id) {
        return $address_id;
      }
    }
    // Iterate through all unique targets and test whether they do already
    // exist in the database.
    foreach ($this->uniqueTargets($source, $result) as $target => $value) {
      switch ($target) {
        case 'rid':
          $relation_id = db_query("SELECT rid FROM {crm_core_contact} WHERE rid = :rid", array(':rid' => $value))->fetchField();
          break;
        case 'feeds_source':
          if ($id = feeds_get_importer_id('address')) {
            $relation_id = db_query("SELECT fs.feed_rid FROM {crm_core_contact} c JOIN {feeds_source} fs ON c.rid = fs.feed_rid WHERE fs.id = :id AND fs.source = :source", array(':id' => $id, ':source' => $value))->fetchField();
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
