<?php

function student_crm_webform_send_email($entity_type, $entity, $field) {
  $fields = field_info_instances();
  $field = $fields[$entity_type][$entity->type][$field];
  if(!$field || !isset($field['settings']['webform'])) {
    return false;
  }
  $settings = $field['settings'];
}

function student_crm_webform_send_email_form() {
  $case = crm_case_get_item();
  if(!$case) {
    return null;
  }
  
  
  $fields = field_info_instances();
  $fields = $fields['crm_case'][$case->type];
  $form_fields = array();
  $field_settings = array();
  foreach($fields as $field_name => $field) {
    if($field['settings']['webform']) {
      $form_fields[$field_name] = $field['label'];
      $field_settings[$field_name] = $field['settings']['email_address'];
    }
  }
  if(!count($form_fields)) {
    return array('message' => array('#value' => 
                  '<div class="empty">'. t('No forms for this item') .'</div>'));
  }
  drupal_add_js(drupal_get_path('module', 'student_crm_webform') .'/js/student_crm_webform.send_form.js');
  drupal_add_js(array('studentCRMWebformSettings' => $field_settings), 'setting');
  $form = array();
  
  $form['field'] = array(
    '#type' => 'select',
    '#title' => 'Select the type of form to send',
    '#options' => $form_fields,
  );
  
  $form['manual-email'] = array(
    '#type' => 'textfield',
    '#title' => 'Email address',
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Send form',
  );
  
  return $form;
}