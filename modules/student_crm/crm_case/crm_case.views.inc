<?php

/**
 * @file
 * Providing extra functionality for the Model UI via views.
 */


/**
 * Implements hook_views_data()
 */
function crm_case_views_data_alter(&$data) { 
  $data['crm_case']['link_crm_case'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a link to the case.'),
      'handler' => 'crm_case_handler_link_field',
    ),
  );
  $data['crm_case']['edit_crm_case'] = array(
    'field' => array(
      'title' => t('Edit Link'),
      'help' => t('Provide a link to the edit form for the case.'),
      'handler' => 'crm_case_handler_edit_link_field',
    ),
  );
  $data['crm_case']['delete_crm_case'] = array(
    'field' => array(
      'title' => t('Delete Link'),
      'help' => t('Provide a link to delete the case.'),
      'handler' => 'crm_case_handler_delete_link_field',
    ),
  );
  $data['crm_case']['crm_case_activity_count'] = array(
    'field' => array(
      'title' => t('Activity count'),
      'help' => t('Provide a number of activities on a case.'),
      'handler' => 'crm_case_handler_case_activity_count',
    ),
  );
  $data['crm_case']['type']['field']['handler'] = 'crm_case_handler_type_field';
  // This content of this field are decided based on the menu structure that
  // follows crm_cases/crm_case/%crm_case_id/op
  $data['crm_case']['operations'] = array(
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all operations available for this case.'),
      'handler' => 'crm_case_handler_crm_case_operations_field',
    ),
  );
  
  $data['crm_case']['created']['field']['handler'] = 'views_handler_field_date';
  $data['crm_case']['changed']['field']['handler'] = 'views_handler_field_date';
  
  $data['crm_case']['case_access'] = array(
    'title' => t('User has access to view case'),
    'help' => t('Hides cases that users don not have access to view.'),
    'filter' => array(
      'handler' => 'crm_case_handler_access',
    ),
  );
  $data['crm_case']['case_contact_access'] = array(
    'title' => t('Contact has access to case'),
    'help' => t('Hides cases that a contact cannot edit.'),
    'filter' => array(
      'handler' => 'crm_case_handler_contact_access',
    ),
  );
}
