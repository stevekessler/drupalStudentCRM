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
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Your students';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'advise students';
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
  /* Relationship: User: Relation: Advisor (user -> relation) */
  $handler->display->display_options['relationships']['relation_base_left_advisor']['id'] = 'relation_base_left_advisor';
  $handler->display->display_options['relationships']['relation_base_left_advisor']['table'] = 'users';
  $handler->display->display_options['relationships']['relation_base_left_advisor']['field'] = 'relation_base_left_advisor';
  $handler->display->display_options['relationships']['relation_base_left_advisor']['required'] = 1;
  /* Relationship: Relation: Relation: Advisor (relation -> crm_core_contact) */
  $handler->display->display_options['relationships']['relation_base_advisor_right_crm_core_contact']['id'] = 'relation_base_advisor_right_crm_core_contact';
  $handler->display->display_options['relationships']['relation_base_advisor_right_crm_core_contact']['table'] = 'relation';
  $handler->display->display_options['relationships']['relation_base_advisor_right_crm_core_contact']['field'] = 'relation_base_advisor_right_crm_core_contact';
  $handler->display->display_options['relationships']['relation_base_advisor_right_crm_core_contact']['relationship'] = 'relation_base_left_advisor';
  $handler->display->display_options['relationships']['relation_base_advisor_right_crm_core_contact']['label'] = 'Advisor - contact';
  $handler->display->display_options['relationships']['relation_base_advisor_right_crm_core_contact']['required'] = 1;
  /* Field: CRM Contact: Contact ID */
  $handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['table'] = 'crm_core_contact';
  $handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['relationship'] = 'relation_base_advisor_right_crm_core_contact';
  $handler->display->display_options['fields']['contact_id']['label'] = '';
  $handler->display->display_options['fields']['contact_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['contact_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['contact_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['contact_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['contact_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contact_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['contact_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['contact_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['contact_id']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['contact_id']['link_to_contact'] = 0;
  /* Field: Contact: Name */
  $handler->display->display_options['fields']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['fields']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['relationship'] = 'relation_base_advisor_right_crm_core_contact';
  $handler->display->display_options['fields']['contact_name']['label'] = 'First Name';
  $handler->display->display_options['fields']['contact_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['contact_name']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['contact_name']['alter']['path'] = 'crm/contact/[contact_id]';
  $handler->display->display_options['fields']['contact_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['contact_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['contact_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['contact_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['contact_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['contact_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['contact_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['contact_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['contact_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['contact_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['contact_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['contact_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['contact_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['contact_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['contact_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['contact_name']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['contact_name']['type'] = 'name_default_given';
  $handler->display->display_options['fields']['contact_name']['field_api_classes'] = 0;
  /* Field: Contact: Name */
  $handler->display->display_options['fields']['contact_name_1']['id'] = 'contact_name_1';
  $handler->display->display_options['fields']['contact_name_1']['table'] = 'field_data_contact_name';
  $handler->display->display_options['fields']['contact_name_1']['field'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name_1']['relationship'] = 'relation_base_advisor_right_crm_core_contact';
  $handler->display->display_options['fields']['contact_name_1']['label'] = 'Last Name';
  $handler->display->display_options['fields']['contact_name_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['contact_name_1']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['contact_name_1']['alter']['path'] = 'crm/contact/[contact_id]';
  $handler->display->display_options['fields']['contact_name_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['contact_name_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['contact_name_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['contact_name_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['contact_name_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['contact_name_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['contact_name_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['contact_name_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['contact_name_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['contact_name_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['contact_name_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['contact_name_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['contact_name_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['contact_name_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['contact_name_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['contact_name_1']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['contact_name_1']['type'] = 'name_default_family';
  $handler->display->display_options['fields']['contact_name_1']['field_api_classes'] = 0;
  /* Field: Relation: Advisor type */
  $handler->display->display_options['fields']['field_advisor_type']['id'] = 'field_advisor_type';
  $handler->display->display_options['fields']['field_advisor_type']['table'] = 'field_data_field_advisor_type';
  $handler->display->display_options['fields']['field_advisor_type']['field'] = 'field_advisor_type';
  $handler->display->display_options['fields']['field_advisor_type']['relationship'] = 'relation_base_left_advisor';
  $handler->display->display_options['fields']['field_advisor_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_advisor_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_advisor_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_advisor_type']['click_sort_column'] = array(
    0 => 'tid',
  );
  $handler->display->display_options['fields']['field_advisor_type']['field_api_classes'] = 0;
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'students/advisees';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Advisees';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
  $handler->display->display_options['path'] = 'user/%/advisees';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Advisees';
  $handler->display->display_options['menu']['weight'] = '0';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: CRM Contact: Contact ID */
  $handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['table'] = 'crm_core_contact';
  $handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['relationship'] = 'relation_base_advisor_right_crm_core_contact';
  $handler->display->display_options['fields']['contact_id']['label'] = '';
  $handler->display->display_options['fields']['contact_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['contact_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['contact_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['contact_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['contact_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['contact_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contact_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['contact_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['contact_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['contact_id']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['contact_id']['link_to_contact'] = 0;
  /* Field: Relation: Advisor type */
  $handler->display->display_options['fields']['field_advisor_type']['id'] = 'field_advisor_type';
  $handler->display->display_options['fields']['field_advisor_type']['table'] = 'field_data_field_advisor_type';
  $handler->display->display_options['fields']['field_advisor_type']['field'] = 'field_advisor_type';
  $handler->display->display_options['fields']['field_advisor_type']['relationship'] = 'relation_base_left_advisor';
  $handler->display->display_options['fields']['field_advisor_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_advisor_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_advisor_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['click_sort_column'] = array(
    0 => 'tid',
  );
  $handler->display->display_options['fields']['field_advisor_type']['field_api_classes'] = 0;
  /* Field: Contact: Name */
  $handler->display->display_options['fields']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['fields']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['relationship'] = 'relation_base_advisor_right_crm_core_contact';
  $handler->display->display_options['fields']['contact_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['contact_name']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['contact_name']['alter']['path'] = 'crm/contact/[contact_id]';
  $handler->display->display_options['fields']['contact_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['contact_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['contact_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['contact_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['contact_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['contact_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['contact_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['contact_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['contact_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['contact_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['contact_name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['contact_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['contact_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['contact_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['contact_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['contact_name']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['contact_name']['type'] = 'name_default_short_full';
  $handler->display->display_options['fields']['contact_name']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['block_description'] = 'Advisee list';
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
    t('Advisor - contact'),
    t('First Name'),
    t('crm/contact/[contact_id]'),
    t('Last Name'),
    t('Advisor type'),
    t('All'),
    t('Page'),
    t('Advisees'),
    t('Block'),
    t('Name'),
    t('Advisee list'),
  );
  $export['advisee_list'] = $view;

  $view = new view;
  $view->name = 'crm_student_advisors';
  $view->description = 'Displays all advisors for a student.';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'CRM Student Advisors';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Advisors';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_user_name_first' => 'field_user_name_first',
    'field_user_name_last' => 'field_user_name_last',
    'field_advisor_type' => 'field_advisor_type',
  );
  $handler->display->display_options['row_options']['separator'] = ' ';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Relationship: User: Relation: Advisor (user -> relation) */
  $handler->display->display_options['relationships']['relation_base_left_advisor']['id'] = 'relation_base_left_advisor';
  $handler->display->display_options['relationships']['relation_base_left_advisor']['table'] = 'users';
  $handler->display->display_options['relationships']['relation_base_left_advisor']['field'] = 'relation_base_left_advisor';
  $handler->display->display_options['relationships']['relation_base_left_advisor']['required'] = 0;
  /* Relationship: Relation: Relation: Advisor (relation -> crm_core_contact) */
  $handler->display->display_options['relationships']['relation_base_advisor_right_crm_core_contact']['id'] = 'relation_base_advisor_right_crm_core_contact';
  $handler->display->display_options['relationships']['relation_base_advisor_right_crm_core_contact']['table'] = 'relation';
  $handler->display->display_options['relationships']['relation_base_advisor_right_crm_core_contact']['field'] = 'relation_base_advisor_right_crm_core_contact';
  $handler->display->display_options['relationships']['relation_base_advisor_right_crm_core_contact']['relationship'] = 'relation_base_left_advisor';
  $handler->display->display_options['relationships']['relation_base_advisor_right_crm_core_contact']['required'] = 0;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['uid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['uid']['link_to_user'] = 1;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_user_name_first']['id'] = 'field_user_name_first';
  $handler->display->display_options['fields']['field_user_name_first']['table'] = 'field_data_field_user_name_first';
  $handler->display->display_options['fields']['field_user_name_first']['field'] = 'field_user_name_first';
  $handler->display->display_options['fields']['field_user_name_first']['label'] = '';
  $handler->display->display_options['fields']['field_user_name_first']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_name_first']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_user_name_first']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_user_name_first']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_name_first']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_name_first']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_name_first']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_name_first']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_name_first']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_name_first']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_name_first']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_name_first']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_name_first']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_name_first']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_name_first']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_name_first']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_name_first']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_name_first']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_name_first']['field_api_classes'] = 0;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_user_name_last']['id'] = 'field_user_name_last';
  $handler->display->display_options['fields']['field_user_name_last']['table'] = 'field_data_field_user_name_last';
  $handler->display->display_options['fields']['field_user_name_last']['field'] = 'field_user_name_last';
  $handler->display->display_options['fields']['field_user_name_last']['label'] = '';
  $handler->display->display_options['fields']['field_user_name_last']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_name_last']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_user_name_last']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_user_name_last']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_name_last']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_name_last']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_name_last']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_name_last']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_name_last']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_name_last']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_name_last']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_name_last']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_name_last']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_name_last']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_name_last']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_name_last']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_name_last']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_name_last']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_name_last']['field_api_classes'] = 0;
  /* Field: Relation: Advisor type */
  $handler->display->display_options['fields']['field_advisor_type']['id'] = 'field_advisor_type';
  $handler->display->display_options['fields']['field_advisor_type']['table'] = 'field_data_field_advisor_type';
  $handler->display->display_options['fields']['field_advisor_type']['field'] = 'field_advisor_type';
  $handler->display->display_options['fields']['field_advisor_type']['relationship'] = 'relation_base_left_advisor';
  $handler->display->display_options['fields']['field_advisor_type']['label'] = '';
  $handler->display->display_options['fields']['field_advisor_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_advisor_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_advisor_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_advisor_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_advisor_type']['field_api_classes'] = 0;
  /* Contextual filter: CRM Contact: Contact ID */
  $handler->display->display_options['arguments']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['arguments']['contact_id']['table'] = 'crm_core_contact';
  $handler->display->display_options['arguments']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['arguments']['contact_id']['relationship'] = 'relation_base_advisor_right_crm_core_contact';
  $handler->display->display_options['arguments']['contact_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['contact_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['contact_id']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['contact_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['contact_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['contact_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['contact_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['contact_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['contact_id']['not'] = 0;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['crm_student_advisors'] = array(
    t('Master'),
    t('Advisors'),
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
    t('user/[uid]'),
    t('All'),
    t('Block'),
  );
  $export['crm_student_advisors'] = $view;

  return $export;
}
