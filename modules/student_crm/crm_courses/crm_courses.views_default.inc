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
  $view->base_table = 'crm_core_contact';
  $view->human_name = 'CRM Course students';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Students';
  $handler->display->display_options['css_class'] = 'quicksearch';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
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
  /* Relationship: CRM Contact: Relation: Enrollment (crm_core_contact -> relation) */
  $handler->display->display_options['relationships']['relation_base_left_enrollment']['id'] = 'relation_base_left_enrollment';
  $handler->display->display_options['relationships']['relation_base_left_enrollment']['table'] = 'crm_core_contact';
  $handler->display->display_options['relationships']['relation_base_left_enrollment']['field'] = 'relation_base_left_enrollment';
  $handler->display->display_options['relationships']['relation_base_left_enrollment']['label'] = 'Enrollment - relation';
  $handler->display->display_options['relationships']['relation_base_left_enrollment']['required'] = 0;
  /* Relationship: Relation: Relation: Enrollment (relation -> node) */
  $handler->display->display_options['relationships']['relation_base_enrollment_right_node']['id'] = 'relation_base_enrollment_right_node';
  $handler->display->display_options['relationships']['relation_base_enrollment_right_node']['table'] = 'relation';
  $handler->display->display_options['relationships']['relation_base_enrollment_right_node']['field'] = 'relation_base_enrollment_right_node';
  $handler->display->display_options['relationships']['relation_base_enrollment_right_node']['relationship'] = 'relation_base_left_enrollment';
  $handler->display->display_options['relationships']['relation_base_enrollment_right_node']['label'] = 'Enrollment - node';
  $handler->display->display_options['relationships']['relation_base_enrollment_right_node']['required'] = 0;
  /* Field: CRM Contact: Contact ID */
  $handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['table'] = 'crm_core_contact';
  $handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
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
  $handler->display->display_options['fields']['contact_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['contact_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['contact_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['contact_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['contact_id']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['contact_id']['link_to_contact'] = 0;
  /* Field: Contact: Name */
  $handler->display->display_options['fields']['contact_name_1']['id'] = 'contact_name_1';
  $handler->display->display_options['fields']['contact_name_1']['table'] = 'field_data_contact_name';
  $handler->display->display_options['fields']['contact_name_1']['field'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name_1']['label'] = 'Last name';
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
  /* Field: Contact: Name */
  $handler->display->display_options['fields']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['fields']['contact_name']['field'] = 'contact_name';
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
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'relation_base_enrollment_right_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;

  /* Display: Students page */
  $handler = $view->new_display('page', 'Students page', 'page');
  $handler->display->display_options['path'] = 'node/%/students';

  /* Display: Course page */
  $handler = $view->new_display('block', 'Course page', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Students';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'relation_base_enrollment_right_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;

  /* Display: Student page */
  $handler = $view->new_display('block', 'Student page', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Current Courses';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No courses found';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: CRM Contact: Relation: Enrollment (crm_core_contact -> relation) */
  $handler->display->display_options['relationships']['relation_base_left_enrollment']['id'] = 'relation_base_left_enrollment';
  $handler->display->display_options['relationships']['relation_base_left_enrollment']['table'] = 'crm_core_contact';
  $handler->display->display_options['relationships']['relation_base_left_enrollment']['field'] = 'relation_base_left_enrollment';
  $handler->display->display_options['relationships']['relation_base_left_enrollment']['label'] = 'Enrollment - relation';
  $handler->display->display_options['relationships']['relation_base_left_enrollment']['required'] = 1;
  /* Relationship: Relation: Relation: Enrollment (relation -> node) */
  $handler->display->display_options['relationships']['relation_base_enrollment_right_node']['id'] = 'relation_base_enrollment_right_node';
  $handler->display->display_options['relationships']['relation_base_enrollment_right_node']['table'] = 'relation';
  $handler->display->display_options['relationships']['relation_base_enrollment_right_node']['field'] = 'relation_base_enrollment_right_node';
  $handler->display->display_options['relationships']['relation_base_enrollment_right_node']['relationship'] = 'relation_base_left_enrollment';
  $handler->display->display_options['relationships']['relation_base_enrollment_right_node']['label'] = 'Enrollment - node';
  $handler->display->display_options['relationships']['relation_base_enrollment_right_node']['required'] = 1;
  /* Relationship: Content: Term (field_course_term) */
  $handler->display->display_options['relationships']['field_course_term_tid']['id'] = 'field_course_term_tid';
  $handler->display->display_options['relationships']['field_course_term_tid']['table'] = 'field_data_field_course_term';
  $handler->display->display_options['relationships']['field_course_term_tid']['field'] = 'field_course_term_tid';
  $handler->display->display_options['relationships']['field_course_term_tid']['relationship'] = 'relation_base_enrollment_right_node';
  $handler->display->display_options['relationships']['field_course_term_tid']['required'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'relation_base_enrollment_right_node';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Course number */
  $handler->display->display_options['fields']['field_course_number']['id'] = 'field_course_number';
  $handler->display->display_options['fields']['field_course_number']['table'] = 'field_data_field_course_number';
  $handler->display->display_options['fields']['field_course_number']['field'] = 'field_course_number';
  $handler->display->display_options['fields']['field_course_number']['relationship'] = 'relation_base_enrollment_right_node';
  $handler->display->display_options['fields']['field_course_number']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_number']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_course_number']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_course_number']['alter']['path'] = 'node/[nid]';
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
  /* Field: Content: Course prefix */
  $handler->display->display_options['fields']['field_course_prefix']['id'] = 'field_course_prefix';
  $handler->display->display_options['fields']['field_course_prefix']['table'] = 'field_data_field_course_prefix';
  $handler->display->display_options['fields']['field_course_prefix']['field'] = 'field_course_prefix';
  $handler->display->display_options['fields']['field_course_prefix']['relationship'] = 'relation_base_enrollment_right_node';
  $handler->display->display_options['fields']['field_course_prefix']['label'] = '';
  $handler->display->display_options['fields']['field_course_prefix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_prefix']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_course_prefix']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_course_prefix']['alter']['path'] = 'node/[nid]';
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
  $handler->display->display_options['fields']['field_course_prefix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_prefix']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_course_prefix']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_course_prefix']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_course_prefix']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_course_prefix']['field_api_classes'] = 0;
  /* Field: Content: Section number */
  $handler->display->display_options['fields']['field_course_section']['id'] = 'field_course_section';
  $handler->display->display_options['fields']['field_course_section']['table'] = 'field_data_field_course_section';
  $handler->display->display_options['fields']['field_course_section']['field'] = 'field_course_section';
  $handler->display->display_options['fields']['field_course_section']['relationship'] = 'relation_base_enrollment_right_node';
  $handler->display->display_options['fields']['field_course_section']['label'] = 'Course';
  $handler->display->display_options['fields']['field_course_section']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_course_section']['alter']['text'] = '[field_course_prefix] [field_course_number]: [field_course_section]';
  $handler->display->display_options['fields']['field_course_section']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_course_section']['alter']['path'] = 'node/[nid]';
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
  $handler->display->display_options['fields']['field_course_section']['click_sort_column'] = array(
    0 => 'value',
  );
  $handler->display->display_options['fields']['field_course_section']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_course_section']['field_api_classes'] = 0;
  /* Field: Relation: Units */
  $handler->display->display_options['fields']['field_enrollment_units']['id'] = 'field_enrollment_units';
  $handler->display->display_options['fields']['field_enrollment_units']['table'] = 'field_data_field_enrollment_units';
  $handler->display->display_options['fields']['field_enrollment_units']['field'] = 'field_enrollment_units';
  $handler->display->display_options['fields']['field_enrollment_units']['relationship'] = 'relation_base_left_enrollment';
  $handler->display->display_options['fields']['field_enrollment_units']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_enrollment_units']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_enrollment_units']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_enrollment_units']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_enrollment_units']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_enrollment_units']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_enrollment_units']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_enrollment_units']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_enrollment_units']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_enrollment_units']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_enrollment_units']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_enrollment_units']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_enrollment_units']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_enrollment_units']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_enrollment_units']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_enrollment_units']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_enrollment_units']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_enrollment_units']['click_sort_column'] = array(
    0 => 'value',
  );
  $handler->display->display_options['fields']['field_enrollment_units']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_enrollment_units']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_enrollment_units']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Course number (field_course_number) */
  $handler->display->display_options['sorts']['field_course_number_value']['id'] = 'field_course_number_value';
  $handler->display->display_options['sorts']['field_course_number_value']['table'] = 'field_data_field_course_number';
  $handler->display->display_options['sorts']['field_course_number_value']['field'] = 'field_course_number_value';
  $handler->display->display_options['sorts']['field_course_number_value']['relationship'] = 'relation_base_enrollment_right_node';
  /* Sort criterion: Content: Course prefix (field_course_prefix) */
  $handler->display->display_options['sorts']['field_course_prefix_value']['id'] = 'field_course_prefix_value';
  $handler->display->display_options['sorts']['field_course_prefix_value']['table'] = 'field_data_field_course_prefix';
  $handler->display->display_options['sorts']['field_course_prefix_value']['field'] = 'field_course_prefix_value';
  $handler->display->display_options['sorts']['field_course_prefix_value']['relationship'] = 'relation_base_enrollment_right_node';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy term: End date (field_term_end) */
  $handler->display->display_options['filters']['field_term_end_value']['id'] = 'field_term_end_value';
  $handler->display->display_options['filters']['field_term_end_value']['table'] = 'field_data_field_term_end';
  $handler->display->display_options['filters']['field_term_end_value']['field'] = 'field_term_end_value';
  $handler->display->display_options['filters']['field_term_end_value']['relationship'] = 'field_course_term_tid';
  $handler->display->display_options['filters']['field_term_end_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_term_end_value']['default_date'] = 'now';
  /* Filter criterion: Taxonomy term: Start date (field_term_start) */
  $handler->display->display_options['filters']['field_term_start_value']['id'] = 'field_term_start_value';
  $handler->display->display_options['filters']['field_term_start_value']['table'] = 'field_data_field_term_start';
  $handler->display->display_options['filters']['field_term_start_value']['field'] = 'field_term_start_value';
  $handler->display->display_options['filters']['field_term_start_value']['relationship'] = 'field_course_term_tid';
  $handler->display->display_options['filters']['field_term_start_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_term_start_value']['default_date'] = 'now';
  $handler->display->display_options['block_description'] = 'Current courses';

  /* Display: Enrollment history */
  $handler = $view->new_display('page', 'Enrollment history', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = 'field_course_term';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_course_number' => 'field_course_number',
    'field_course_prefix' => 'field_course_prefix',
    'field_course_section' => 'field_course_section',
    'field_course_term' => 'field_course_term',
  );
  $handler->display->display_options['style_options']['default'] = 'field_course_prefix';
  $handler->display->display_options['style_options']['info'] = array(
    'field_course_number' => array(
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
    'field_course_section' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_course_term' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No courses found';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: CRM Contact: Relation: Enrollment (crm_core_contact -> relation) */
  $handler->display->display_options['relationships']['relation_base_left_enrollment']['id'] = 'relation_base_left_enrollment';
  $handler->display->display_options['relationships']['relation_base_left_enrollment']['table'] = 'crm_core_contact';
  $handler->display->display_options['relationships']['relation_base_left_enrollment']['field'] = 'relation_base_left_enrollment';
  $handler->display->display_options['relationships']['relation_base_left_enrollment']['required'] = 1;
  /* Relationship: Relation: Relation: Enrollment (relation -> node) */
  $handler->display->display_options['relationships']['relation_base_enrollment_right_node']['id'] = 'relation_base_enrollment_right_node';
  $handler->display->display_options['relationships']['relation_base_enrollment_right_node']['table'] = 'relation';
  $handler->display->display_options['relationships']['relation_base_enrollment_right_node']['field'] = 'relation_base_enrollment_right_node';
  $handler->display->display_options['relationships']['relation_base_enrollment_right_node']['relationship'] = 'relation_base_left_enrollment';
  $handler->display->display_options['relationships']['relation_base_enrollment_right_node']['label'] = 'Enrollment - course';
  $handler->display->display_options['relationships']['relation_base_enrollment_right_node']['required'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Course number */
  $handler->display->display_options['fields']['field_course_number']['id'] = 'field_course_number';
  $handler->display->display_options['fields']['field_course_number']['table'] = 'field_data_field_course_number';
  $handler->display->display_options['fields']['field_course_number']['field'] = 'field_course_number';
  $handler->display->display_options['fields']['field_course_number']['relationship'] = 'relation_base_enrollment_right_node';
  $handler->display->display_options['fields']['field_course_number']['label'] = '';
  $handler->display->display_options['fields']['field_course_number']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['field_course_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_number']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_course_number']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_course_number']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_course_number']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_course_number']['field_api_classes'] = 0;
  /* Field: Content: Course prefix */
  $handler->display->display_options['fields']['field_course_prefix']['id'] = 'field_course_prefix';
  $handler->display->display_options['fields']['field_course_prefix']['table'] = 'field_data_field_course_prefix';
  $handler->display->display_options['fields']['field_course_prefix']['field'] = 'field_course_prefix';
  $handler->display->display_options['fields']['field_course_prefix']['relationship'] = 'relation_base_enrollment_right_node';
  $handler->display->display_options['fields']['field_course_prefix']['label'] = '';
  $handler->display->display_options['fields']['field_course_prefix']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['field_course_prefix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_prefix']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_course_prefix']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_course_prefix']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_course_prefix']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_course_prefix']['field_api_classes'] = 0;
  /* Field: Content: Section number */
  $handler->display->display_options['fields']['field_course_section']['id'] = 'field_course_section';
  $handler->display->display_options['fields']['field_course_section']['table'] = 'field_data_field_course_section';
  $handler->display->display_options['fields']['field_course_section']['field'] = 'field_course_section';
  $handler->display->display_options['fields']['field_course_section']['relationship'] = 'relation_base_enrollment_right_node';
  $handler->display->display_options['fields']['field_course_section']['label'] = 'Course';
  $handler->display->display_options['fields']['field_course_section']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_course_section']['alter']['text'] = '[field_course_prefix] [field_course_number] [field_course_section]';
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
  /* Field: Content: Course title */
  $handler->display->display_options['fields']['field_course_title']['id'] = 'field_course_title';
  $handler->display->display_options['fields']['field_course_title']['table'] = 'field_data_field_course_title';
  $handler->display->display_options['fields']['field_course_title']['field'] = 'field_course_title';
  $handler->display->display_options['fields']['field_course_title']['relationship'] = 'relation_base_enrollment_right_node';
  $handler->display->display_options['fields']['field_course_title']['label'] = 'Title';
  $handler->display->display_options['fields']['field_course_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_course_title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_course_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_course_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_course_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_course_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_course_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_course_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_course_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_course_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_course_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_course_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_course_title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_course_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_course_title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_course_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_course_title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_course_title']['field_api_classes'] = 0;
  /* Field: Relation: Units */
  $handler->display->display_options['fields']['field_enrollment_units']['id'] = 'field_enrollment_units';
  $handler->display->display_options['fields']['field_enrollment_units']['table'] = 'field_data_field_enrollment_units';
  $handler->display->display_options['fields']['field_enrollment_units']['field'] = 'field_enrollment_units';
  $handler->display->display_options['fields']['field_enrollment_units']['relationship'] = 'relation_base_left_enrollment';
  $handler->display->display_options['fields']['field_enrollment_units']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_enrollment_units']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_enrollment_units']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_enrollment_units']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_enrollment_units']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_enrollment_units']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_enrollment_units']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_enrollment_units']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_enrollment_units']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_enrollment_units']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_enrollment_units']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_enrollment_units']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_enrollment_units']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_enrollment_units']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_enrollment_units']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_enrollment_units']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_enrollment_units']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_enrollment_units']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_enrollment_units']['field_api_classes'] = 0;
  /* Field: Relation: Grade points */
  $handler->display->display_options['fields']['field_enrollment_grade_points']['id'] = 'field_enrollment_grade_points';
  $handler->display->display_options['fields']['field_enrollment_grade_points']['table'] = 'field_data_field_enrollment_grade_points';
  $handler->display->display_options['fields']['field_enrollment_grade_points']['field'] = 'field_enrollment_grade_points';
  $handler->display->display_options['fields']['field_enrollment_grade_points']['relationship'] = 'relation_base_left_enrollment';
  $handler->display->display_options['fields']['field_enrollment_grade_points']['label'] = '';
  $handler->display->display_options['fields']['field_enrollment_grade_points']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_enrollment_grade_points']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_enrollment_grade_points']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_enrollment_grade_points']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_enrollment_grade_points']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_enrollment_grade_points']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_enrollment_grade_points']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_enrollment_grade_points']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_enrollment_grade_points']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_enrollment_grade_points']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_enrollment_grade_points']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_enrollment_grade_points']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_enrollment_grade_points']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_enrollment_grade_points']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_enrollment_grade_points']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_enrollment_grade_points']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_enrollment_grade_points']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_enrollment_grade_points']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_enrollment_grade_points']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_enrollment_grade_points']['field_api_classes'] = 0;
  /* Field: Relation: Letter grade */
  $handler->display->display_options['fields']['field_enrollment_grade_letter']['id'] = 'field_enrollment_grade_letter';
  $handler->display->display_options['fields']['field_enrollment_grade_letter']['table'] = 'field_data_field_enrollment_grade_letter';
  $handler->display->display_options['fields']['field_enrollment_grade_letter']['field'] = 'field_enrollment_grade_letter';
  $handler->display->display_options['fields']['field_enrollment_grade_letter']['relationship'] = 'relation_base_left_enrollment';
  $handler->display->display_options['fields']['field_enrollment_grade_letter']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_enrollment_grade_letter']['alter']['text'] = '[field_enrollment_grade_letter] ([field_enrollment_grade_points])';
  $handler->display->display_options['fields']['field_enrollment_grade_letter']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_enrollment_grade_letter']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_enrollment_grade_letter']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_enrollment_grade_letter']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_enrollment_grade_letter']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_enrollment_grade_letter']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_enrollment_grade_letter']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_enrollment_grade_letter']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_enrollment_grade_letter']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_enrollment_grade_letter']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_enrollment_grade_letter']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_enrollment_grade_letter']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_enrollment_grade_letter']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_enrollment_grade_letter']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_enrollment_grade_letter']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_enrollment_grade_letter']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_enrollment_grade_letter']['field_api_classes'] = 0;
  /* Field: Content: Term */
  $handler->display->display_options['fields']['field_course_term']['id'] = 'field_course_term';
  $handler->display->display_options['fields']['field_course_term']['table'] = 'field_data_field_course_term';
  $handler->display->display_options['fields']['field_course_term']['field'] = 'field_course_term';
  $handler->display->display_options['fields']['field_course_term']['relationship'] = 'relation_base_enrollment_right_node';
  $handler->display->display_options['fields']['field_course_term']['exclude'] = TRUE;
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
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
  $handler->display->display_options['path'] = 'crm/contact/%/courses';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Courses';
  $handler->display->display_options['menu']['weight'] = '0';
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
    t('Enrollment - relation'),
    t('Enrollment - node'),
    t('Contact ID'),
    t('Last name'),
    t('crm/contact/[contact_id]'),
    t('First Name'),
    t('Level'),
    t('Degrees'),
    t('Student ID'),
    t('All'),
    t('Students page'),
    t('Course page'),
    t('Student page'),
    t('Current Courses'),
    t('No courses found'),
    t('term from field_course_term'),
    t('Course number'),
    t('node/[nid]'),
    t('Course'),
    t('[field_course_prefix] [field_course_number]: [field_course_section]'),
    t('Units'),
    t('Current courses'),
    t('Enrollment history'),
    t('Enrollment'),
    t('Enrollment - course'),
    t('[field_course_prefix] [field_course_number] [field_course_section]'),
    t('Title'),
    t('Letter grade'),
    t('[field_enrollment_grade_letter] ([field_enrollment_grade_points])'),
    t('Term'),
  );
  $export['crm_course_students'] = $view;

  $view = new view;
  $view->name = 'crm_student_courses';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'CRM Courses';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CRM Student Courses';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
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
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
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
  $handler->display->display_options['fields']['field_course_term']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_course_term']['field_api_classes'] = 0;
  /* Field: Content: Course prefix */
  $handler->display->display_options['fields']['field_course_prefix']['id'] = 'field_course_prefix';
  $handler->display->display_options['fields']['field_course_prefix']['table'] = 'field_data_field_course_prefix';
  $handler->display->display_options['fields']['field_course_prefix']['field'] = 'field_course_prefix';
  $handler->display->display_options['fields']['field_course_prefix']['label'] = 'Prefix';
  $handler->display->display_options['fields']['field_course_prefix']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_course_prefix']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_course_prefix']['alter']['path'] = 'node/[nid]';
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
  $handler->display->display_options['fields']['field_course_number']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_course_number']['alter']['path'] = 'node/[nid]';
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
  $handler->display->display_options['fields']['field_course_section']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_course_section']['alter']['path'] = 'node/[nid]';
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
  /* Field: Content: Course title */
  $handler->display->display_options['fields']['field_course_title']['id'] = 'field_course_title';
  $handler->display->display_options['fields']['field_course_title']['table'] = 'field_data_field_course_title';
  $handler->display->display_options['fields']['field_course_title']['field'] = 'field_course_title';
  $handler->display->display_options['fields']['field_course_title']['label'] = 'Title';
  $handler->display->display_options['fields']['field_course_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_course_title']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_course_title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_course_title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_course_title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_course_title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_course_title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_course_title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_course_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_course_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_course_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_course_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_course_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_course_title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_course_title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_course_title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_course_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_course_title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_course_title']['field_api_classes'] = 0;
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
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Courses';
  $handler->display->display_options['path'] = 'crm/courses';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
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
    t('node/[nid]'),
    t('Number'),
    t('Section'),
    t('Title'),
    t('Page'),
    t('Courses'),
    t('Block'),
  );
  $export['crm_student_courses'] = $view;

  return $export;
}
