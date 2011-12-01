<?php

function crm_student_admin_form() {
  $form = array();
  
  $message = variable_get('crm_student_welcome_page', '');
  
  $form['crm_student_welcome_page'] = array(
    '#type' => 'text_format',
    '#title' => 'Welcome page message',
    '#default_value' => (isset($message['value'])) ? $message['value'] : '',
    '#format' => (isset($message['format'])) ? $message['forma'] : NULL,
  );
  
  return system_settings_form($form);
}

function crm_student_admin_page() {
	drupal_add_css(drupal_get_path('module', 'crm_student') .'/css/crm_student.css');
	drupal_add_css(drupal_get_path('module', 'system') .'system.admin.css');
	$links = module_invoke_all('crm_student_admin_links');
	$result = array();
	foreach($links as $k => $link) {
		$result[$link['group']][$k] = l($link['title'], $link['href']) . '<div class="description">'. $link['description'];
	}
	foreach($result as $k => $r) {
		$result[$k] = array('title' => $k,
							'show' => TRUE,
							'content' => theme('item_list', array('items' => $r, 'attributes' => array('class' => array('admin-list')))));
	}
	return theme('admin_page', array('blocks' => $result));
}