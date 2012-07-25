<?php

/**
*  @file Views hooks
*/

/**
*  Implementation of hook_views_data
*/
function student_crm_basket_views_data() {
  $data['crm_basket_options']['table']['group'] = t('Student CRM Basket');
  $data['crm_basket_options']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );
  
  $data['crm_basket_options']['basket_options'] = array(
    'title' => t('Remove from basket'),
    'help' => t('Remove from basket link'),
    'field' => array(
      'handler' => 'views_handler_student_crm_basket_remove',
      'click sortable' => FALSE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  return $data;
}
