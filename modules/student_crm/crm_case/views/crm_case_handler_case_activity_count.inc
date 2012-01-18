<?php

/**
 * This field handler shows the number of activities on a case
 */
class crm_case_handler_case_activity_count extends crm_case_handler_link_field {
  
  function construct() {
    parent::construct();
    $this->additional_fields['cid'] = 'cid';
  }
  
  function render($values) {
    $query = db_select('field_data_endpoints', 'e')
              ->condition('entity_type', 'relation')
              ->condition('bundle', 'crm_core_activity')
              ->condition('endpoints_entity_type', 'crm_case')
              ->condition('endpoints_entity_id', $values->cid)
              ->fields('e', array('endpoints_entity_id'));
    return $query->countQuery()->execute()->fetchField();
  }
}
