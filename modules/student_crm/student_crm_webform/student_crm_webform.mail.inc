<?php

/**
 * @file 
 * Functions dealing with sending emails about forms.
 */
 
/**
 * Sends an email with a link to complete a form.
 */
function student_crm_webform_send_email($entity_type, $entity, $field, $emails = FALSE) {
  $fields = field_info_instances();
  $field = $fields[$entity_type][$entity->type][$field];
  if (!$field || !isset($field['settings']['webform'])) {
    return FALSE;
  }
  $settings = $field['settings'];
  if (!$emails) {
    $emails = _student_crm_webform_get_field_email_addresses($field, $entity, 'crm_case');
  }
  $body = check_markup($field['settings']['email_body']['value'], $field['settings']['email_body']['format']);
  if ($entity_type == 'case') {
    $tokens = array('crm_contact' => crm_case_get_contact($entity),
                    'crm_case' => $entity);
  }
  else {
    $tokens = array($entity_type => $entity);
  }
  $tokens['webform'] = $field['settings']['webform'];
  $tokens['entity_type'] = $entity_type;
  $message['body'] = token_replace($body, $tokens);
  $message['subject'] = check_plain($field['settings']['email_subject']);
  foreach ($emails as $email) {
    drupal_mail('student_crm_webform', 'form_prompt', $email, language_default(), $message);
  }
  return $emails;
}

/**
 * Form for ad-hoc form sending form.
 */
function student_crm_webform_send_email_form() {
  $case = crm_case_get_item();
  
  $fields = field_info_instances();
  $fields = $fields['crm_case'][$case->type];
  $form_fields = array();
  $field_settings = array();
  foreach ($fields as $field_name => $field) {
    if ($field['settings']['webform']) {
      $form_fields[$field_name] = $field['label'];
      $field_settings[$field_name] = $field['settings']['email_address'];
    }
  }
  if (!count($form_fields)) {
    
    return array('message' => array('#markup' => 
                  '<div class="empty">' . t('No forms for this item') . '</div>'));
  }
  drupal_add_js(drupal_get_path('module', 'student_crm_webform') . '/js/student_crm_webform.send_form.js');
  drupal_add_js(array('studentCRMWebformSettings' => $field_settings), 'setting');
  $form = array();
  
  $form['case'] = array(
    '#type' => 'hidden',
    '#value' => $case->cid,
  );
  
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

/**
 * Validation for ad-hoc form sending form. Checks for valid emails.
 */
function student_crm_webform_send_email_form_validate($form, $form_state) {
  if (strlen(trim($form_state['values']['manual-email'])) != '' && !valid_email_address($form_state['values']['manual-email'])) {
    form_set_error('manual-email', t('The provided email address is not valid.'));
  }
}

/**
 * Form submit callback for ad-hoc form sending form.
 */
function student_crm_webform_send_email_form_submit($form, $form_state) {
  $case = crm_case_load($form_state['values']['case']);
  $email_addresses = student_crm_webform_send_email('crm_case', $case, $form_state['values']['field'], $form_state['values']['manual-email']);
  
  $case = crm_case_load($form_state['values']['case']);
  $fields = field_info_instances();
  $field = $fields['crm_case'][$case->type][$form_state['values']['field']];

  drupal_set_message(t('The form %form has been sent to: !email-addresses', array('%form' => $field['label'], '!email-addresses' => theme('item_list', array('items' => $email_addresses)))));
}

/**
 * Retrieves a list of email addresses that are attached to a field.
 */
function _student_crm_webform_get_field_email_addresses($field, $entity, $entity_type) {
  $emails = array();
  if ($field['settings']['email_address'] == 'manual') {
    return FALSE;
  }
  if ($field['settings']['email_address'] == 'field') {
    $items = field_get_items($entity_type, $entity, $field['settings']['email_field']);
    foreach ($items as $address) {
      $emails[$address['email']] = $address['email'];
    }
  }
  if ($field['settings']['email_address'] == 'contact') {
    $contact = crm_case_get_contact($case);
    $fields = field_info_instances();
    foreach ($fields['crm_contact'][$contact->type] as $field_name => $field) {
      if ($field['widget']['module'] == 'email') {
        $items = field_get_items('crm_contact', $contact, $field_name);
        foreach ($items as $address) {
          $emails[$address['email']] = $address['email'];
        }
      }
    }
  }
  return $emails;
}