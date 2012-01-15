<?php

function crm_tasks_admin_form() {
  $form = array();
  
  $options = array();
  
  for ($i = 1; $i < 25; $i++) {
    $options[$i] = format_date(strtotime($i .':00'), 'custom', 'g:i a');
  }
  
  $form['crm_tasks_enable_mail'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable sending reminder emails about tasks'),
    '#description' => t('When checked, users will receive a daily email reminding them of pending checklist items.'),
    '#default_value' => variable_get('crm_tasks_enable_mail', 0),
  );
  
  $form['crm_tasks_cron_time'] = array(
    '#type' => 'select',
    '#title' => t('Hour of the day to start sending noticiations about tasks'),
    '#options' => $options,
    '#default_value' => variable_get('crm_tasks_cron_time', 8),
  );
  
  return system_settings_form($form);
}