<?php

function crm_student_admin_form() {
  $form = array();
  
  $message = variable_get('crm_student_welcome_page', '');
  
  $form['crm_student_welcome_page'] = array(
    '#type' => 'text_format',
    '#title' => 'Email body',
    '#default_value' => (isset($message['value'])) ? $message['value'] : '',
    '#format' => (isset($message['format'])) ? $message['value'] : NULL,
  );
  
  return system_settings_form($form);
}