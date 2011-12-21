<?php

class views_handler_crm_tasks_mark_completed extends views_handler_field {

  function render($values) {
    drupal_add_js(drupal_get_path('module', 'crm_tasks') .'/js/crm_tasks.views.js');
    drupal_add_css(drupal_get_path('module', 'crm_tasks') .'/css/crm_tasks.css');
    $checkbox = array('data-rid' => $values->relation_users_rid,
                      'class'    => array('crm-task-mark'),
                     );
    if ($values->field_field_task_complete[0]['raw']['value']) {
      $checkbox['checked'] = 'checked';
    }
    return theme('checkbox', array('element' => array('#attributes' => $checkbox)));
  }
  
  function query() {
    
  }
}