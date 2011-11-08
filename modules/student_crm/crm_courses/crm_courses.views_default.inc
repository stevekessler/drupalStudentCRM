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
  $view->name = 'crm_course_students';
  $view->description = 'Provides a listing of all students within a course.';
  $view->tag = 'default';
  $view->base_table = 'crm_contact';
  $view->human_name = 'CRM Course students';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Students';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '300';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_last_name' => 'field_last_name',
    'field_first_name' => 'field_first_name',
    'field_student_level' => 'field_student_level',
    'field_student_degrees' => 'field_student_degrees',
    'field_student_id' => 'field_student_id',
  );
  $handler->display->display_options['style_options']['default'] = 'field_last_name';
  $handler->display->display_options['style_options']['info'] = array(
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
    'field_student_level' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_student_degrees' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_student_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
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
  $handler->display->display_options['empty']['area']['content'] = 'No students found';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: CRM Contact: Relation: Enrollment (crm_contact <-> node) */
  $handler->display->display_options['relationships']['relation_enrollment_node']['id'] = 'relation_enrollment_node';
  $handler->display->display_options['relationships']['relation_enrollment_node']['table'] = 'crm_contact';
  $handler->display->display_options['relationships']['relation_enrollment_node']['field'] = 'relation_enrollment_node';
  $handler->display->display_options['relationships']['relation_enrollment_node']['required'] = 1;
  $handler->display->display_options['relationships']['relation_enrollment_node']['r_index'] = '0';
  /* Field: Contact: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
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
  /* Field: Contact: Class level */
  $handler->display->display_options['fields']['field_student_level']['id'] = 'field_student_level';
  $handler->display->display_options['fields']['field_student_level']['table'] = 'field_data_field_student_level';
  $handler->display->display_options['fields']['field_student_level']['field'] = 'field_student_level';
  $handler->display->display_options['fields']['field_student_level']['label'] = 'Level';
  $handler->display->display_options['fields']['field_student_level']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_student_level']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_student_level']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_student_level']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_student_level']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_student_level']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_student_level']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_student_level']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_student_level']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_student_level']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_student_level']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_student_level']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_student_level']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_student_level']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_student_level']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_student_level']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_student_level']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_student_level']['field_api_classes'] = 0;
  /* Field: Contact: Degrees */
  $handler->display->display_options['fields']['field_student_degrees']['id'] = 'field_student_degrees';
  $handler->display->display_options['fields']['field_student_degrees']['table'] = 'field_data_field_student_degrees';
  $handler->display->display_options['fields']['field_student_degrees']['field'] = 'field_student_degrees';
  $handler->display->display_options['fields']['field_student_degrees']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_student_degrees']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_student_degrees']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_student_degrees']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_student_degrees']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_student_degrees']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_student_degrees']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['field_api_classes'] = 0;
  /* Field: Contact: Student ID */
  $handler->display->display_options['fields']['field_student_id']['id'] = 'field_student_id';
  $handler->display->display_options['fields']['field_student_id']['table'] = 'field_data_field_student_id';
  $handler->display->display_options['fields']['field_student_id']['field'] = 'field_student_id';
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
  $handler->display->display_options['fields']['field_student_id']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_student_id']['element_class'] = 'easy-copy';
  $handler->display->display_options['fields']['field_student_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_student_id']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_student_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_student_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_student_id']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_student_id']['field_api_classes'] = 0;
  /* Sort criterion: Contact: Last name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Sort criterion: Contact: First Name (field_first_name) */
  $handler->display->display_options['sorts']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['sorts']['field_first_name_value']['field'] = 'field_first_name_value';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'relation_enrollment_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Filter criterion: CRM Contact: Contact Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_contact';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'student' => 'student',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'node/%/students';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Students';
  $translatables['crm_course_students'] = array(
    t('Master'),
    t('Students'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('No students found'),
    t('Enrollment'),
    t('Last name'),
    t('First Name'),
    t('Level'),
    t('Degrees'),
    t('Student ID'),
    t('All'),
    t('Page'),
    t('Block'),
  );
  $export['crm_course_students'] = $view;

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
