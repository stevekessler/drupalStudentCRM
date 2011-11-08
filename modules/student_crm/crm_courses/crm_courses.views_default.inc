<?php
/**
 * @file
 * crm_courses.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function crm_courses_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'crm_student_courses';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'CRM Student Courses';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CRM Student Courses';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_course_term' => 'field_course_term',
    'field_course_prefix' => 'field_course_prefix',
    'field_course_number' => 'field_course_number',
    'field_course_section' => 'field_course_section',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = 'field_course_prefix';
  $handler->display->display_options['style_options']['info'] = array(
    'field_course_term' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_course_prefix' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_course_number' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_course_section' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Field: Content: Term */
  $handler->display->display_options['fields']['field_course_term']['id'] = 'field_course_term';
  $handler->display->display_options['fields']['field_course_term']['table'] = 'field_data_field_course_term';
  $handler->display->display_options['fields']['field_course_term']['field'] = 'field_course_term';
  $handler->display->display_options['fields']['field_course_term']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_course_term']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_course_term']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_course_term']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_course_term']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_course_term']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_course_term']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_course_term']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_course_term']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_course_term']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_course_term']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_course_term']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_course_term']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_course_term']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_course_term']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_course_term']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_course_term']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_course_term']['field_api_classes'] = 0;
  /* Field: Content: Course prefix */
  $handler->display->display_options['fields']['field_course_prefix']['id'] = 'field_course_prefix';
  $handler->display->display_options['fields']['field_course_prefix']['table'] = 'field_data_field_course_prefix';
  $handler->display->display_options['fields']['field_course_prefix']['field'] = 'field_course_prefix';
  $handler->display->display_options['fields']['field_course_prefix']['label'] = 'Prefix';
  $handler->display->display_options['fields']['field_course_prefix']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_course_prefix']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_course_prefix']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_course_prefix']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_course_prefix']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_course_prefix']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_course_prefix']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_course_prefix']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_course_prefix']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_course_prefix']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_course_prefix']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_course_prefix']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_course_prefix']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_course_prefix']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_course_prefix']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_course_prefix']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_course_prefix']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_course_prefix']['field_api_classes'] = 0;
  /* Field: Content: Course number */
  $handler->display->display_options['fields']['field_course_number']['id'] = 'field_course_number';
  $handler->display->display_options['fields']['field_course_number']['table'] = 'field_data_field_course_number';
  $handler->display->display_options['fields']['field_course_number']['field'] = 'field_course_number';
  $handler->display->display_options['fields']['field_course_number']['label'] = 'Number';
  $handler->display->display_options['fields']['field_course_number']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_course_number']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_course_number']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_course_number']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_course_number']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_course_number']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_course_number']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_course_number']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_course_number']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_course_number']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_course_number']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_course_number']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_course_number']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_course_number']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_course_number']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_course_number']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_course_number']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_course_number']['field_api_classes'] = 0;
  /* Field: Content: Section number */
  $handler->display->display_options['fields']['field_course_section']['id'] = 'field_course_section';
  $handler->display->display_options['fields']['field_course_section']['table'] = 'field_data_field_course_section';
  $handler->display->display_options['fields']['field_course_section']['field'] = 'field_course_section';
  $handler->display->display_options['fields']['field_course_section']['label'] = 'Section';
  $handler->display->display_options['fields']['field_course_section']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_course_section']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_course_section']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_course_section']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_course_section']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_course_section']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_course_section']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_course_section']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_course_section']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_course_section']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_course_section']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_course_section']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_course_section']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_course_section']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_course_section']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_course_section']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_course_section']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_course_section']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_course_section']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Content: Course prefix (field_course_prefix) */
  $handler->display->display_options['sorts']['field_course_prefix_value']['id'] = 'field_course_prefix_value';
  $handler->display->display_options['sorts']['field_course_prefix_value']['table'] = 'field_data_field_course_prefix';
  $handler->display->display_options['sorts']['field_course_prefix_value']['field'] = 'field_course_prefix_value';
  /* Sort criterion: Content: Course number (field_course_number) */
  $handler->display->display_options['sorts']['field_course_number_value']['id'] = 'field_course_number_value';
  $handler->display->display_options['sorts']['field_course_number_value']['table'] = 'field_data_field_course_number';
  $handler->display->display_options['sorts']['field_course_number_value']['field'] = 'field_course_number_value';
  /* Sort criterion: Content: Section number (field_course_section) */
  $handler->display->display_options['sorts']['field_course_section_value']['id'] = 'field_course_section_value';
  $handler->display->display_options['sorts']['field_course_section_value']['table'] = 'field_data_field_course_section';
  $handler->display->display_options['sorts']['field_course_section_value']['field'] = 'field_course_section_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course' => 'course',
  );
  /* Filter criterion: Content: Course number (field_course_number) */
  $handler->display->display_options['filters']['field_course_number_value']['id'] = 'field_course_number_value';
  $handler->display->display_options['filters']['field_course_number_value']['table'] = 'field_data_field_course_number';
  $handler->display->display_options['filters']['field_course_number_value']['field'] = 'field_course_number_value';
  $handler->display->display_options['filters']['field_course_number_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_course_number_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_number_value']['expose']['operator_id'] = 'field_course_number_value_op';
  $handler->display->display_options['filters']['field_course_number_value']['expose']['label'] = 'Number';
  $handler->display->display_options['filters']['field_course_number_value']['expose']['operator'] = 'field_course_number_value_op';
  $handler->display->display_options['filters']['field_course_number_value']['expose']['identifier'] = 'field_course_number_value';
  $handler->display->display_options['filters']['field_course_number_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_course_number_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_course_number_value']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Course prefix (field_course_prefix) */
  $handler->display->display_options['filters']['field_course_prefix_value']['id'] = 'field_course_prefix_value';
  $handler->display->display_options['filters']['field_course_prefix_value']['table'] = 'field_data_field_course_prefix';
  $handler->display->display_options['filters']['field_course_prefix_value']['field'] = 'field_course_prefix_value';
  $handler->display->display_options['filters']['field_course_prefix_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_prefix_value']['expose']['operator_id'] = 'field_course_prefix_value_op';
  $handler->display->display_options['filters']['field_course_prefix_value']['expose']['label'] = 'Prefix';
  $handler->display->display_options['filters']['field_course_prefix_value']['expose']['operator'] = 'field_course_prefix_value_op';
  $handler->display->display_options['filters']['field_course_prefix_value']['expose']['identifier'] = 'field_course_prefix_value';
  $handler->display->display_options['filters']['field_course_prefix_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_course_prefix_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_course_prefix_value']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Section number (field_course_section) */
  $handler->display->display_options['filters']['field_course_section_value']['id'] = 'field_course_section_value';
  $handler->display->display_options['filters']['field_course_section_value']['table'] = 'field_data_field_course_section';
  $handler->display->display_options['filters']['field_course_section_value']['field'] = 'field_course_section_value';
  $handler->display->display_options['filters']['field_course_section_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_section_value']['expose']['operator_id'] = 'field_course_section_value_op';
  $handler->display->display_options['filters']['field_course_section_value']['expose']['label'] = 'Section';
  $handler->display->display_options['filters']['field_course_section_value']['expose']['operator'] = 'field_course_section_value_op';
  $handler->display->display_options['filters']['field_course_section_value']['expose']['identifier'] = 'field_course_section_value';
  $handler->display->display_options['filters']['field_course_section_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_course_section_value']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Term (field_course_term) */
  $handler->display->display_options['filters']['field_course_term_tid']['id'] = 'field_course_term_tid';
  $handler->display->display_options['filters']['field_course_term_tid']['table'] = 'field_data_field_course_term';
  $handler->display->display_options['filters']['field_course_term_tid']['field'] = 'field_course_term_tid';
  $handler->display->display_options['filters']['field_course_term_tid']['value'] = '';
  $handler->display->display_options['filters']['field_course_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_course_term_tid']['expose']['operator_id'] = 'field_course_term_tid_op';
  $handler->display->display_options['filters']['field_course_term_tid']['expose']['label'] = 'Term';
  $handler->display->display_options['filters']['field_course_term_tid']['expose']['operator'] = 'field_course_term_tid_op';
  $handler->display->display_options['filters']['field_course_term_tid']['expose']['identifier'] = 'field_course_term_tid';
  $handler->display->display_options['filters']['field_course_term_tid']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_course_term_tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_course_term_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_course_term_tid']['vocabulary'] = 'term';
  $handler->display->display_options['filters']['field_course_term_tid']['error_message'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'crm/courses';
  $translatables['crm_student_courses'] = array(
    t('Master'),
    t('CRM Student Courses'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Term'),
    t('Prefix'),
    t('Number'),
    t('Section'),
    t('Title'),
    t('Page'),
  );
  $export['crm_student_courses'] = $view;

  return $export;
}
