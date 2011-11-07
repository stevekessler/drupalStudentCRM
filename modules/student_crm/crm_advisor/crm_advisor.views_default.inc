<?php
/**
 * @file
 * crm_advisor.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function crm_advisor_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'advisee_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Advisee list';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Your students';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'contact_id' => 'contact_id',
    'contact_image' => 'contact_image',
    'field_last_name' => 'field_last_name',
    'field_first_name' => 'field_first_name',
    'field_student_degrees' => 'field_student_degrees',
    'field_contact_email' => 'field_contact_email',
    'field_student_status' => 'field_student_status',
    'field_student_id' => 'field_student_id',
  );
  $handler->display->display_options['style_options']['default'] = 'field_last_name';
  $handler->display->display_options['style_options']['info'] = array(
    'contact_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'contact_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_student_degrees' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_contact_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_student_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_student_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: User: Relation: Advisor (user <-> crm_contact) */
  $handler->display->display_options['relationships']['relation_advisor_crm_contact']['id'] = 'relation_advisor_crm_contact';
  $handler->display->display_options['relationships']['relation_advisor_crm_contact']['table'] = 'users';
  $handler->display->display_options['relationships']['relation_advisor_crm_contact']['field'] = 'relation_advisor_crm_contact';
  $handler->display->display_options['relationships']['relation_advisor_crm_contact']['required'] = 0;
  $handler->display->display_options['relationships']['relation_advisor_crm_contact']['r_index'] = '-1';
  /* Field: CRM Contact: Contact ID */
  $handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['table'] = 'crm_contact';
  $handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['relationship'] = 'relation_advisor_crm_contact';
  /* Field: Contact: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'relation_advisor_crm_contact';
  $handler->display->display_options['fields']['field_last_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_last_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_last_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_last_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_last_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_last_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_last_name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_last_name']['field_api_classes'] = 0;
  /* Field: Contact: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'relation_advisor_crm_contact';
  $handler->display->display_options['fields']['field_first_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_first_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_first_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_first_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_first_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_first_name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_first_name']['field_api_classes'] = 0;
  /* Field: Contact: Degrees */
  $handler->display->display_options['fields']['field_student_degrees']['id'] = 'field_student_degrees';
  $handler->display->display_options['fields']['field_student_degrees']['table'] = 'field_data_field_student_degrees';
  $handler->display->display_options['fields']['field_student_degrees']['field'] = 'field_student_degrees';
  $handler->display->display_options['fields']['field_student_degrees']['relationship'] = 'relation_advisor_crm_contact';
  /* Field: Contact: Email address */
  $handler->display->display_options['fields']['field_contact_email']['id'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['table'] = 'field_data_field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['field'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['relationship'] = 'relation_advisor_crm_contact';
  $handler->display->display_options['fields']['field_contact_email']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_contact_email']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_contact_email']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_contact_email']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_contact_email']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['field_api_classes'] = 0;
  /* Field: Contact: Status */
  $handler->display->display_options['fields']['field_student_status']['id'] = 'field_student_status';
  $handler->display->display_options['fields']['field_student_status']['table'] = 'field_data_field_student_status';
  $handler->display->display_options['fields']['field_student_status']['field'] = 'field_student_status';
  $handler->display->display_options['fields']['field_student_status']['relationship'] = 'relation_advisor_crm_contact';
  $handler->display->display_options['fields']['field_student_status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_student_status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_student_status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_student_status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_student_status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_student_status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_student_status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_student_status']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_student_status']['field_api_classes'] = 0;
  /* Field: Contact: Student ID */
  $handler->display->display_options['fields']['field_student_id']['id'] = 'field_student_id';
  $handler->display->display_options['fields']['field_student_id']['table'] = 'field_data_field_student_id';
  $handler->display->display_options['fields']['field_student_id']['field'] = 'field_student_id';
  $handler->display->display_options['fields']['field_student_id']['relationship'] = 'relation_advisor_crm_contact';
  $handler->display->display_options['fields']['field_student_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_student_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_student_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_student_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_student_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_student_id']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_student_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_student_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_student_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_student_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_student_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_student_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_student_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_student_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_student_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_student_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_student_id']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_student_id']['field_api_classes'] = 0;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
  /* Filter criterion: Contact: Degrees (field_student_degrees) */
  $handler->display->display_options['filters']['field_student_degrees_tid']['id'] = 'field_student_degrees_tid';
  $handler->display->display_options['filters']['field_student_degrees_tid']['table'] = 'field_data_field_student_degrees';
  $handler->display->display_options['filters']['field_student_degrees_tid']['field'] = 'field_student_degrees_tid';
  $handler->display->display_options['filters']['field_student_degrees_tid']['relationship'] = 'relation_advisor_crm_contact';
  $handler->display->display_options['filters']['field_student_degrees_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_student_degrees_tid']['expose']['operator_id'] = 'field_student_degrees_tid_op';
  $handler->display->display_options['filters']['field_student_degrees_tid']['expose']['label'] = 'Degrees';
  $handler->display->display_options['filters']['field_student_degrees_tid']['expose']['operator'] = 'field_student_degrees_tid_op';
  $handler->display->display_options['filters']['field_student_degrees_tid']['expose']['identifier'] = 'field_student_degrees_tid';
  $handler->display->display_options['filters']['field_student_degrees_tid']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_student_degrees_tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_student_degrees_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_student_degrees_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_student_degrees_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_student_degrees_tid']['vocabulary'] = 'degrees';
  $handler->display->display_options['filters']['field_student_degrees_tid']['error_message'] = 0;
  /* Filter criterion: Contact: First Name (field_first_name) */
  $handler->display->display_options['filters']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['filters']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['relationship'] = 'relation_advisor_crm_contact';
  $handler->display->display_options['filters']['field_first_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator_id'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['label'] = 'First Name';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['identifier'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_first_name_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_first_name_value']['expose']['multiple'] = FALSE;
  /* Filter criterion: Contact: Last name (field_last_name) */
  $handler->display->display_options['filters']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['filters']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['relationship'] = 'relation_advisor_crm_contact';
  $handler->display->display_options['filters']['field_last_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator_id'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['label'] = 'Last name';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['identifier'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['multiple'] = FALSE;
  /* Filter criterion: Contact: Student ID (field_student_id) */
  $handler->display->display_options['filters']['field_student_id_value']['id'] = 'field_student_id_value';
  $handler->display->display_options['filters']['field_student_id_value']['table'] = 'field_data_field_student_id';
  $handler->display->display_options['filters']['field_student_id_value']['field'] = 'field_student_id_value';
  $handler->display->display_options['filters']['field_student_id_value']['relationship'] = 'relation_advisor_crm_contact';
  $handler->display->display_options['filters']['field_student_id_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_student_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_student_id_value']['expose']['operator_id'] = 'field_student_id_value_op';
  $handler->display->display_options['filters']['field_student_id_value']['expose']['label'] = 'Student ID';
  $handler->display->display_options['filters']['field_student_id_value']['expose']['operator'] = 'field_student_id_value_op';
  $handler->display->display_options['filters']['field_student_id_value']['expose']['identifier'] = 'field_student_id_value';
  $handler->display->display_options['filters']['field_student_id_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_student_id_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_student_id_value']['expose']['multiple'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'students/advisees';
  $translatables['advisee_list'] = array(
    t('Master'),
    t('Your students'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Advisor'),
    t('Contact ID'),
    t('Last name'),
    t('First Name'),
    t('Degrees'),
    t('Email address'),
    t('Status'),
    t('Student ID'),
    t('All'),
    t('Page'),
  );
  $export['advisee_list'] = $view;

  return $export;
}
