<?php

/**
 * @file
 * Functions to handle block callbacks.
 */

/**
 * Block render callback for the create case form.
 */
function crm_case_blocks_crm_create_case() {
  foreach (crm_case_get_types() as $type) {
    $type_name = check_plain($type->type);
    if (user_access("edit any $type_name crm_case")) {
      return array('subject' => 'Open new case',
               'content' => drupal_get_form('_crm_case_blocks_crm_create_case_form'));
    }
  }
}

/**
 * Form callback for generating the new case form.
 */
function _crm_case_blocks_crm_create_case_form() {
  $form = array();
  
  $types = array();
  
  foreach (crm_case_get_types() as $type) {
      $type_name = check_plain($type->type);
      if (user_access("edit any $type_name crm_case")) {
        $types[$type->type] = $type->label;
      }
    }
  
  $form['case_type'] = array(
    '#type' => 'select',
    '#title' => 'Select case type',
    '#options' => $types,
  );
  
  $contact = menu_get_object('crm_core_contact', 2);
  if ($contact) {
    $form['contact'] = array(
      '#type' => 'hidden',
      '#value' => $contact->contact_id
      );
  }
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Open case',
  );
  
  return $form;
}

/**
 * Submit callback for the new case form.
 */
function _crm_case_blocks_crm_create_case_form_submit($form, $form_state) {
  drupal_goto('crm/case/add/' . 
        check_plain($form_state['values']['case_type']) . '/' . 
        check_plain($form_state['values']['contact']));
}