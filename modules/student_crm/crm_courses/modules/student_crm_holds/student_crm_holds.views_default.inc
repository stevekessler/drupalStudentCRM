<?php
/**
 * @file
 * student_crm_holds.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function student_crm_holds_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'crm_student_holds';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'crm_core_contact';
  $view->human_name = 'CRM Student holds';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CRM Student holds';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = 'field_hold_term';
  $handler->display->display_options['style_options']['group_rendered'] = 1;
  $handler->display->display_options['style_options']['columns'] = array(
    'body' => 'body',
    'field_hold_code' => 'field_hold_code',
    'field_hold_severity' => 'field_hold_severity',
    'title' => 'title',
    'field_hold_date_closed' => 'field_hold_date_closed',
    'field_hold_date_created' => 'field_hold_date_created',
    'field_hold_term' => 'field_hold_term',
  );
  $handler->display->display_options['style_options']['default'] = 'field_hold_date_created';
  $handler->display->display_options['style_options']['info'] = array(
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_hold_code' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_hold_severity' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_hold_date_closed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_hold_date_created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_hold_term' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: CRM Contact: Relation: Hold (crm_core_contact -> relation) */
  $handler->display->display_options['relationships']['relation_base_left_hold']['id'] = 'relation_base_left_hold';
  $handler->display->display_options['relationships']['relation_base_left_hold']['table'] = 'crm_core_contact';
  $handler->display->display_options['relationships']['relation_base_left_hold']['field'] = 'relation_base_left_hold';
  $handler->display->display_options['relationships']['relation_base_left_hold']['required'] = 1;
  /* Relationship: Relation: Relation: Hold (relation -> node) */
  $handler->display->display_options['relationships']['relation_base_hold_right_node']['id'] = 'relation_base_hold_right_node';
  $handler->display->display_options['relationships']['relation_base_hold_right_node']['table'] = 'relation';
  $handler->display->display_options['relationships']['relation_base_hold_right_node']['field'] = 'relation_base_hold_right_node';
  $handler->display->display_options['relationships']['relation_base_hold_right_node']['relationship'] = 'relation_base_left_hold';
  $handler->display->display_options['relationships']['relation_base_hold_right_node']['label'] = 'Hold - hold type';
  $handler->display->display_options['relationships']['relation_base_hold_right_node']['required'] = 1;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'relation_base_hold_right_node';
  /* Field: Content: Code */
  $handler->display->display_options['fields']['field_hold_code']['id'] = 'field_hold_code';
  $handler->display->display_options['fields']['field_hold_code']['table'] = 'field_data_field_hold_code';
  $handler->display->display_options['fields']['field_hold_code']['field'] = 'field_hold_code';
  $handler->display->display_options['fields']['field_hold_code']['relationship'] = 'relation_base_hold_right_node';
  $handler->display->display_options['fields']['field_hold_code']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_hold_code']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_hold_code']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_hold_code']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_hold_code']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_hold_code']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_hold_code']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_hold_code']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_hold_code']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_hold_code']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_hold_code']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_hold_code']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_hold_code']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_hold_code']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_hold_code']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_hold_code']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_hold_code']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_hold_code']['field_api_classes'] = 0;
  /* Field: Content: Severity */
  $handler->display->display_options['fields']['field_hold_severity']['id'] = 'field_hold_severity';
  $handler->display->display_options['fields']['field_hold_severity']['table'] = 'field_data_field_hold_severity';
  $handler->display->display_options['fields']['field_hold_severity']['field'] = 'field_hold_severity';
  $handler->display->display_options['fields']['field_hold_severity']['relationship'] = 'relation_base_hold_right_node';
  $handler->display->display_options['fields']['field_hold_severity']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_hold_severity']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_hold_severity']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_hold_severity']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_hold_severity']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_hold_severity']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_hold_severity']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_hold_severity']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_hold_severity']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_hold_severity']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_hold_severity']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_hold_severity']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_hold_severity']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_hold_severity']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_hold_severity']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_hold_severity']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_hold_severity']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_hold_severity']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'relation_base_hold_right_node';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Relation: Closed date */
  $handler->display->display_options['fields']['field_hold_date_closed']['id'] = 'field_hold_date_closed';
  $handler->display->display_options['fields']['field_hold_date_closed']['table'] = 'field_data_field_hold_date_closed';
  $handler->display->display_options['fields']['field_hold_date_closed']['field'] = 'field_hold_date_closed';
  $handler->display->display_options['fields']['field_hold_date_closed']['relationship'] = 'relation_base_left_hold';
  /* Field: Relation: Created date */
  $handler->display->display_options['fields']['field_hold_date_created']['id'] = 'field_hold_date_created';
  $handler->display->display_options['fields']['field_hold_date_created']['table'] = 'field_data_field_hold_date_created';
  $handler->display->display_options['fields']['field_hold_date_created']['field'] = 'field_hold_date_created';
  $handler->display->display_options['fields']['field_hold_date_created']['relationship'] = 'relation_base_left_hold';
  $handler->display->display_options['fields']['field_hold_date_created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_hold_date_created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_hold_date_created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_hold_date_created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_hold_date_created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_hold_date_created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_hold_date_created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_hold_date_created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_hold_date_created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_hold_date_created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_hold_date_created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_hold_date_created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_hold_date_created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_hold_date_created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_hold_date_created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_hold_date_created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_hold_date_created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_hold_date_created']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_hold_date_created']['field_api_classes'] = 0;
  /* Field: Relation: Term */
  $handler->display->display_options['fields']['field_hold_term']['id'] = 'field_hold_term';
  $handler->display->display_options['fields']['field_hold_term']['table'] = 'field_data_field_hold_term';
  $handler->display->display_options['fields']['field_hold_term']['field'] = 'field_hold_term';
  $handler->display->display_options['fields']['field_hold_term']['relationship'] = 'relation_base_left_hold';
  $handler->display->display_options['fields']['field_hold_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_hold_term']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_hold_term']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_hold_term']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_hold_term']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_hold_term']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_hold_term']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_hold_term']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_hold_term']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_hold_term']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_hold_term']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_hold_term']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_hold_term']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_hold_term']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_hold_term']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_hold_term']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_hold_term']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_hold_term']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_hold_term']['field_api_classes'] = 0;
  /* Contextual filter: CRM Contact: Contact ID */
  $handler->display->display_options['arguments']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['arguments']['contact_id']['table'] = 'crm_core_contact';
  $handler->display->display_options['arguments']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['arguments']['contact_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['contact_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['contact_id']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['contact_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['contact_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['contact_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['contact_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['contact_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['contact_id']['not'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'crm/contact/%/holds';
  $translatables['crm_student_holds'] = array(
    t('Master'),
    t('CRM Student holds'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Hold'),
    t('Hold - hold type'),
    t('Body'),
    t('Code'),
    t('Severity'),
    t('Title'),
    t('Closed date'),
    t('Created date'),
    t('Term'),
    t('All'),
    t('Page'),
  );
  $export['crm_student_holds'] = $view;

  return $export;
}
