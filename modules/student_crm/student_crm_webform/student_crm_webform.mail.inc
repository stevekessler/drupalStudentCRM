<?php

/**
 * @file 
 * Functions dealing with sending emails about forms.
 */
 
/**
 * Sends an email with a link to complete a form.
 */
function student_crm_webform_send_email($entity_type, $entity, $field, $emails = FALSE, $insert = TRUE) {
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
  if ($entity_type == 'crm_case') {
    $tokens = array('crm_core_contact' => crm_case_get_contact($entity),
                    'crm_case' => $entity);
    $entity_id = $entity->cid;
  }
  else {
    $tokens = array($entity_type => $entity);
    $entity_id = $entity->contact_id;
  }
  $tokens['webform'] = $field['settings']['webform'];
  $tokens['entity_type'] = $entity_type;
  if ($entity_type == 'crm_case') {
    $tokens['crm_core_contact'] = crm_case_get_contact($entity);
  }
  
  foreach ($emails as $email) {
    $tokens['email'] = $email;
    $message['body'] = token_replace($body, $tokens);
    $message['subject'] = token_replace(check_plain($field['settings']['email_subject']), $tokens);
    if(!$insert) {
      $message['subject'] = t('Reminder: @subject', array('@subject' => $message['subject']));
    }
    drupal_mail('student_crm_webform', 'form_prompt', $email, language_default(), $message);
    if ($field['settings']['email_reminder'] && $insert) {
     $fields = array('entity_type' => $entity_type,
                  'entity_id' => $entity_id,
                  'entity_field' => $field['field_name'],
                  'email' => $email,
                  'send_date' => time() + $field['settings']['email_reminder'],
                  'reminders_sent' => 0,
                  );
      db_insert('student_crm_webform')
        ->fields($fields)
        ->execute();
    }
  }
  return $emails;
}

/**
 * Form for ad-hoc form sending contact form.
 */
function student_crm_webform_send_contact_email_form() {
  $contact = menu_get_object('crm_core_contact', 2);
  $email = field_get_items('crm_core_contact', $contact, 'field_contact_email');
  drupal_add_js(drupal_get_path('module', 'student_crm_webform') . '/js/student_crm_webform.send_form.js');
  $form = array();
  
  $form['contact'] = array(
    '#type' => 'hidden',
    '#value' => $contact->crm_contact_id,
  );
  
  $form['webform'] = array(
    '#type' => 'textfield',
    '#title' => 'Form',
    '#autocomplete_path' => 'ajax/crm/webform-list',
    '#required' => TRUE,
  );
  
  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => 'Send form to',
    '#default_value' => $email[0]['email'],
    '#required' => TRUE,
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
function student_crm_webform_send_contact_email_form_validate($form, $form_state) {
  if (!valid_email_address($form_state['values']['email'])) {
    form_set_error('email', t('The provided email address is not valid.'));
  }
}

/**
 * Form submit callback for ad-hoc form sending form.
 */
function student_crm_webform_send_contact_email_form_submit($form, $form_state) {
  $contact = crm_core_contact_load($form_state['values']['contact']);
  $email_addresses = student_crm_webform_send_email('crm_core_contact', $contact, $form_state['values']['field'], $form_state['values']['manual-email']);
  
  $case = crm_case_load($form_state['values']['case']);
  $fields = field_info_instances();
  $field = $fields['crm_case'][$case->type][$form_state['values']['field']];

  drupal_set_message(t('The form %form has been sent to: !email-addresses', array('%form' => $field['label'], '!email-addresses' => theme('item_list', array('items' => $email_addresses)))));
}

/**
 * Form for ad-hoc form sending form.
 */
function student_crm_webform_send_email_form() {
  $case = menu_get_object('crm_case', 2);
  
  $fields = field_info_instances();
  $fields = $fields['crm_case'][$case->type];
  $form_fields = array();
  $field_settings = array();
  if (!$fields) {
    return null;
  }
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
  $emails = ($form_state['values']['manual-email'])
            ? array($form_state['values']['manual-email'])
            : FALSE;
  $email_addresses = student_crm_webform_send_email('crm_case', $case, $form_state['values']['field'], $emails);
  
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
    foreach ($fields['crm_core_contact'][$contact->type] as $field_name => $field) {
      if ($field['widget']['module'] == 'email') {
        $items = field_get_items('crm_core_contact', $contact, $field_name);
        foreach ($items as $address) {
          $emails[$address['email']] = $address['email'];
        }
      }
    }
  }
  return $emails;
}

/**
 * Page to manage reminders for a case.
 */
function student_crm_webform_reminder_manage($case_id) {
  $case = crm_case_load($case_id);
  $rows = array();
  $reminders = db_select('student_crm_webform', 'w')
                ->condition('entity_type', 'crm_case')
                ->condition('entity_id', $case_id)
                ->fields('w')
                ->execute()
                ->fetchAll();
  $fields = field_info_instances();
  $header = array(t('Email address'), t('Field'), t('Reminders sent'), t('Last sent'), t('Delete'));
  foreach($reminders as $reminder) {
    $rows[] = array($reminder->email,
                    $fields['crm_case'][$case->type][$reminder->entity_field]['label'],
                    $reminder->reminders_sent,
                    format_date($reminder->send_date),
                    l(t('Delete'), 'crm/case/' . $case->cid . '/reminders/delete/' . $reminder->email . '/' . $reminder->entity_field));
  }
  return theme('table', array('header' => $header, 'rows' => $rows));
}

function student_crm_webform_reminder_manage_delete($form, &$form_state, $case_id, $email, $field) {
  $form_state['case_id'] = $case_id;
  $form_state['field'] = $field;
  $form_state['email'] = $email;
  $fields = field_info_instances();
  $case = crm_case_load($case_id);
  $field = $fields['crm_case'][$case->type][$field]['label'];
  $form = confirm_form($form,
    t('Are you sure you want to delete the reminder for %field to !email?', array('%field' => $field, '!email' => $email)),
    'crm/case/'. $case->cid .'/reminders',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );
  
  return $form;
}

function student_crm_webform_reminder_manage_delete_submit($form, &$form_state) {
  db_delete('student_crm_webform')
        ->condition('entity_type', 'crm_case')
        ->condition('entity_id', $form_state['case_id'])
        ->condition('entity_field', $form_state['field'])
        ->condition('email', $form_state['email'])
        ->execute();
  drupal_set_message(t('The email reminder has been deleted'));
  drupal_goto('crm/case/'. $form_state['case_id']);
}