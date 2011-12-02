<?php

/**
*  @file Views hooks
*/

/**
*  Implementation of hook_views_data
*/
function crm_tasks_views_data() {
  $data['crm_tasks']['table']['group'] = t('Site Data');
  $data['crm_tasks']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );
  
  $data['crm_tasks']['task_checkbox'] = array(
    'title' => t('Task checkbox'),
    'help' => t('Checkbox to mark or unmark tasks'),
    'field' => array(
      'handler' => 'views_handler_crm_tasks_mark_completed',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  return $data;
}
