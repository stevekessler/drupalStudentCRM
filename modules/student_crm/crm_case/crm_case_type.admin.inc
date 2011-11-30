<?php

/**
 * @file
 * Model type editing UI.
 */

/**
 * Generates the crm_case type editing form.
 */
function crm_case_type_form($form, &$form_state, $crm_case_type, $op = 'edit') {
  if ($op == 'clone') {
    $crm_case_type->label .= ' (cloned)';
    $crm_case_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $crm_case_type->label,
    '#description' => t('The human-readable name of this crm_case type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($crm_case_type->type) ? $crm_case_type->type : '',
    '#maxlength' => 32,
//    '#disabled' => $crm_case_type->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'crm_case_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this crm_case type. It must only contain lowercase letters, numbers, and underscores.'),
  );
  
  $instructions = $crm_case_type->data['instructions'];
  $form['instructions'] = array(
    '#type' => 'text_format',
    '#title' => t('Form instructions'),
    '#description' => t('Additional instructions that appear on the top of the case form.'),
    '#default_value' => (isset($instructions['value'])) ? $instructions['value'] : '',
    '#format' => (isset($instructions['format'])) ? $instructions['format'] : NULL,
  );
  
  $form['contact_edit'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow contacts to edit their own cases.'),
    '#description' => t('When checked, contacts with this case type will be able to edit it.'),
    '#default_value' => ($crm_case_type->data['contact_edit']) ? TRUE : FALSE,
  );
  
  $form['email'] = array(
    '#type' => 'fieldset',
    '#title' => 'Email options',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  
  $form['email']['email_contact'] = array(
    '#type' => 'checkbox',
    '#title' => t('Email contact on case creation'),
    '#description' => t('Enable sending the related contact an email upon case creation.'),
    '#default_value' => $crm_case_type->data['email_contact'],
  );
  
  $form['email']['email_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Email subject'),
    '#description' => t('Subject of email to send to the contact.'),
    '#default_value' => $crm_case_type->data['email_subject'],
  );
  
  $email = $crm_case_type->data['email_body'];
  $form['email']['email_body'] = array(
    '#type' => 'text_format',
    '#title' => t('Email body'),
    '#description' => t('Email body to send to the contact.'),
    '#default_value' => (isset($email['value'])) ? $email['value'] : '',
    '#format' => (isset($email['format'])) ? $email['format'] : NULL,
  );
  
  if (module_exists('token')) {
    $form['email']['email_tokens'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array('crm_case', 'crm_contact'),
    );
  }

  
  $form['data']['#tree'] = TRUE;

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save case type'),
    '#weight' => 40,
  );

  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function crm_case_type_form_submit(&$form, &$form_state) {
  $crm_case_type = entity_ui_form_submit_build_entity($form, $form_state);
  if(!$crm_case_type->id) {
    crm_case_add_status_field($crm_case_type);
  }
  $crm_case_type->data['instructions'] = $crm_case_type->instructions;
  $crm_case_type->data['email_contact'] = $crm_case_type->email_contact;
  $crm_case_type->data['email_subject'] = $crm_case_type->email_subject;
  $crm_case_type->data['email_body'] = $crm_case_type->email_body;
  $crm_case_type->data['contact_edit'] = $crm_case_type->contact_edit;
  $crm_case_type->save();
  $form_state['redirect'] = 'crm/admin/case/types';
}

/**
 * Form API submit callback for the delete button.
 */
function crm_case_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'crm/admin/case/types/' . $form_state['crm_case_type']->type . '/delete';
}
