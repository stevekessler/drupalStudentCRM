<?php

/**
 * @file
 * Admin form for CRM history
 */
/**
 * Form callback for the admin settings form.
 */
function crm_history_admin_form() {
  $form = array();
  
  $form['crm_history_max_items'] = array(
    '#type' => 'select',
    '#title' => 'Maximum number of items to show in history',
    '#options' => drupal_map_assoc(array(3, 5, 7, 10)),
    '#default_value' => variable_get('crm_history_max_items', 5),
  );
  
  return system_settings_form($form);
}