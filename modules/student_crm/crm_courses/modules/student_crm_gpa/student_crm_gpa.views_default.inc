<?php
/**
 * @file
 * student_crm_gpa.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function student_crm_gpa_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'student_crm_gpa';
  $view->description = 'Shows GPA history for a student.';
  $view->tag = 'default';
  $view->base_table = 'crm_core_contact';
  $view->human_name = 'Student CRM GPA';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'GPA History';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view gpa data';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['group_rendered'] = 1;
  $handler->display->display_options['style_options']['columns'] = array(
    'field_gpa_cumulative' => 'field_gpa_cumulative',
    'field_gpa_term' => 'field_gpa_term',
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_gpa_cumulative' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_gpa_term' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
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
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No GPA history found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: CRM Contact: Relation: Term GPA (crm_core_contact -> relation) */
  $handler->display->display_options['relationships']['relation_base_left_term_gpa']['id'] = 'relation_base_left_term_gpa';
  $handler->display->display_options['relationships']['relation_base_left_term_gpa']['table'] = 'crm_core_contact';
  $handler->display->display_options['relationships']['relation_base_left_term_gpa']['field'] = 'relation_base_left_term_gpa';
  $handler->display->display_options['relationships']['relation_base_left_term_gpa']['required'] = 1;
  /* Relationship: Relation: Relation: Term GPA (relation -> taxonomy_term) */
  $handler->display->display_options['relationships']['relation_base_term_gpa_right_taxonomy_term']['id'] = 'relation_base_term_gpa_right_taxonomy_term';
  $handler->display->display_options['relationships']['relation_base_term_gpa_right_taxonomy_term']['table'] = 'relation';
  $handler->display->display_options['relationships']['relation_base_term_gpa_right_taxonomy_term']['field'] = 'relation_base_term_gpa_right_taxonomy_term';
  $handler->display->display_options['relationships']['relation_base_term_gpa_right_taxonomy_term']['relationship'] = 'relation_base_left_term_gpa';
  $handler->display->display_options['relationships']['relation_base_term_gpa_right_taxonomy_term']['label'] = 'Term GPA - term';
  $handler->display->display_options['relationships']['relation_base_term_gpa_right_taxonomy_term']['required'] = 0;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'relation_base_term_gpa_right_taxonomy_term';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 0;
  $handler->display->display_options['fields']['name']['convert_spaces'] = 0;
  /* Field: Relation: Term GPA */
  $handler->display->display_options['fields']['field_gpa_term']['id'] = 'field_gpa_term';
  $handler->display->display_options['fields']['field_gpa_term']['table'] = 'field_data_field_gpa_term';
  $handler->display->display_options['fields']['field_gpa_term']['field'] = 'field_gpa_term';
  $handler->display->display_options['fields']['field_gpa_term']['relationship'] = 'relation_base_left_term_gpa';
  $handler->display->display_options['fields']['field_gpa_term']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_gpa_term']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_gpa_term']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_gpa_term']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_gpa_term']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_gpa_term']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_gpa_term']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_gpa_term']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_gpa_term']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_gpa_term']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_gpa_term']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_gpa_term']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_gpa_term']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_gpa_term']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_gpa_term']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_gpa_term']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_gpa_term']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_gpa_term']['click_sort_column'] = array(
    0 => 'value',
  );
  $handler->display->display_options['fields']['field_gpa_term']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_gpa_term']['field_api_classes'] = 0;
  /* Field: Relation: Cumulative GPA */
  $handler->display->display_options['fields']['field_gpa_cumulative']['id'] = 'field_gpa_cumulative';
  $handler->display->display_options['fields']['field_gpa_cumulative']['table'] = 'field_data_field_gpa_cumulative';
  $handler->display->display_options['fields']['field_gpa_cumulative']['field'] = 'field_gpa_cumulative';
  $handler->display->display_options['fields']['field_gpa_cumulative']['relationship'] = 'relation_base_left_term_gpa';
  /* Sort criterion: Taxonomy term: Start date (field_term_start) */
  $handler->display->display_options['sorts']['field_term_start_value']['id'] = 'field_term_start_value';
  $handler->display->display_options['sorts']['field_term_start_value']['table'] = 'field_data_field_term_start';
  $handler->display->display_options['sorts']['field_term_start_value']['field'] = 'field_term_start_value';
  $handler->display->display_options['sorts']['field_term_start_value']['relationship'] = 'relation_base_term_gpa_right_taxonomy_term';
  $handler->display->display_options['sorts']['field_term_start_value']['order'] = 'DESC';
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
  $handler->display->display_options['path'] = 'crm/contact/%/gpa';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'GPA';
  $handler->display->display_options['menu']['weight'] = '0';
  $translatables['student_crm_gpa'] = array(
    t('Master'),
    t('GPA History'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('No GPA history found.'),
    t('Term GPA'),
    t('Term GPA - term'),
    t('Name'),
    t('Cumulative GPA'),
    t('All'),
    t('Page'),
  );
  $export['student_crm_gpa'] = $view;

  return $export;
}
