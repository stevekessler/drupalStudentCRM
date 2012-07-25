<?php

/**
 * @file
 * A views handler that renders a checkbox on the view and marks the task as complete.
 */
class views_handler_student_crm_basket_remove extends views_handler_field {

  function render($values) {
    drupal_add_js(drupal_get_path('module', 'student_crm_basket') . '/js/student_crm_basket.js');
    $node = menu_get_object();
    if($values->cid) {
      $type = 'crm_case';
      $id = $values->cid;
    }
    elseif($values->contact_id) {
      $type = 'crm_core_contact';
      $id = $values->contact_id;
    }
    else {
      return;
    }
    return l(t('Remove'), 'node/'. $node->nid .'/basket/remove/'. $type .'/'. $id, array('attributes' => array('class' => array('basket-link', 'basket-remove'))));
  }
  
  function query() {
    
  }
}