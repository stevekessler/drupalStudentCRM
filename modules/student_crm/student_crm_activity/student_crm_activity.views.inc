<?php

/**
*  @file Views hooks
*/

/**
*  Implementation of hook_views_data
*/
function student_crm_activity_views_data() {
  $data['crm_core_activity']['table']['group'] = t('Activities');
  $data['crm_core_activity']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );
  
  $data['crm_core_activity']['activity_access'] = array(
    'title' => t('User has access to view activity'),
    'help' => t('Hides activities that users don not have access to view.'),
    'filter' => array(
      'handler' => 'views_handler_filter_student_crm_activity_access',
    ),
  );
  
  return $data;
}

