<?php
/**
 * @file
 * crm_case.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function crm_case_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'crm_cases';
  $view->description = 'A search tool for finding and managing cases.';
  $view->tag = 'default';
  $view->base_table = 'crm_case';
  $view->human_name = 'CRM Cases';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Cases';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'open and close cases';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['group_rendered'] = 1;
  $handler->display->display_options['style_options']['columns'] = array(
    'cid' => 'cid',
    'contact_id' => 'contact_id',
    'name' => 'name',
    'type' => 'type',
    'contact_name' => 'contact_name',
    'contact_name_1' => 'contact_name_1',
    'created' => 'created',
    'field_student_id' => 'field_student_id',
    'edit_crm_case' => 'edit_crm_case',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'cid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'contact_id' => array(
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
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'contact_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'contact_name_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_student_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_crm_case' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'No cases found.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Case: Relation: CRM Contact Case (crm_case <-> crm_core_contact) */
  $handler->display->display_options['relationships']['relation_crm_contact_case_crm_core_contact']['id'] = 'relation_crm_contact_case_crm_core_contact';
  $handler->display->display_options['relationships']['relation_crm_contact_case_crm_core_contact']['table'] = 'crm_case';
  $handler->display->display_options['relationships']['relation_crm_contact_case_crm_core_contact']['field'] = 'relation_crm_contact_case_crm_core_contact';
  $handler->display->display_options['relationships']['relation_crm_contact_case_crm_core_contact']['required'] = 1;
  $handler->display->display_options['relationships']['relation_crm_contact_case_crm_core_contact']['r_index'] = '-1';
  /* Field: Case: Case ID */
  $handler->display->display_options['fields']['cid']['id'] = 'cid';
  $handler->display->display_options['fields']['cid']['table'] = 'crm_case';
  $handler->display->display_options['fields']['cid']['field'] = 'cid';
  /* Field: CRM Contact: Contact ID */
  $handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['table'] = 'crm_core_contact';
  $handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['relationship'] = 'relation_crm_contact_case_crm_core_contact';
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
  /* Field: Case: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'crm_case';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'crm/case/[cid]';
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
  /* Field: Case: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'crm_case';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = 1;
  /* Field: Contact: Name */
  $handler->display->display_options['fields']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['fields']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['relationship'] = 'relation_crm_contact_case_crm_core_contact';
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
  $handler->display->display_options['fields']['contact_name_1']['relationship'] = 'relation_crm_contact_case_crm_core_contact';
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
  /* Field: Case: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'crm_case';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Open date';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  /* Field: Contact: Student ID */
  $handler->display->display_options['fields']['field_student_id']['id'] = 'field_student_id';
  $handler->display->display_options['fields']['field_student_id']['table'] = 'field_data_field_student_id';
  $handler->display->display_options['fields']['field_student_id']['field'] = 'field_student_id';
  $handler->display->display_options['fields']['field_student_id']['relationship'] = 'relation_crm_contact_case_crm_core_contact';
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
  $handler->display->display_options['fields']['field_student_id']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_student_id']['field_api_classes'] = 0;
  /* Field: Case: Activity count */
  $handler->display->display_options['fields']['crm_case_activity_count']['id'] = 'crm_case_activity_count';
  $handler->display->display_options['fields']['crm_case_activity_count']['table'] = 'crm_case';
  $handler->display->display_options['fields']['crm_case_activity_count']['field'] = 'crm_case_activity_count';
  $handler->display->display_options['fields']['crm_case_activity_count']['label'] = 'Notes';
  $handler->display->display_options['fields']['crm_case_activity_count']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['crm_case_activity_count']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['crm_case_activity_count']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['crm_case_activity_count']['alter']['external'] = 0;
  $handler->display->display_options['fields']['crm_case_activity_count']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['crm_case_activity_count']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['crm_case_activity_count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['crm_case_activity_count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['crm_case_activity_count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['crm_case_activity_count']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['crm_case_activity_count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['crm_case_activity_count']['alter']['html'] = 0;
  $handler->display->display_options['fields']['crm_case_activity_count']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['crm_case_activity_count']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['crm_case_activity_count']['hide_empty'] = 0;
  $handler->display->display_options['fields']['crm_case_activity_count']['empty_zero'] = 0;
  $handler->display->display_options['fields']['crm_case_activity_count']['hide_alter_empty'] = 1;
  /* Field: Case: Edit Link */
  $handler->display->display_options['fields']['edit_crm_case']['id'] = 'edit_crm_case';
  $handler->display->display_options['fields']['edit_crm_case']['table'] = 'crm_case';
  $handler->display->display_options['fields']['edit_crm_case']['field'] = 'edit_crm_case';
  $handler->display->display_options['fields']['edit_crm_case']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_crm_case']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_crm_case']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_crm_case']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_crm_case']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_crm_case']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_crm_case']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_crm_case']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_crm_case']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_crm_case']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_crm_case']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_crm_case']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_crm_case']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_crm_case']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_crm_case']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_crm_case']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_crm_case']['hide_alter_empty'] = 1;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  /* Filter criterion: Case: Case ID */
  $handler->display->display_options['filters']['cid']['id'] = 'cid';
  $handler->display->display_options['filters']['cid']['table'] = 'crm_case';
  $handler->display->display_options['filters']['cid']['field'] = 'cid';
  $handler->display->display_options['filters']['cid']['group'] = 0;
  $handler->display->display_options['filters']['cid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['cid']['expose']['operator_id'] = 'cid_op';
  $handler->display->display_options['filters']['cid']['expose']['label'] = 'Case ID';
  $handler->display->display_options['filters']['cid']['expose']['operator'] = 'cid_op';
  $handler->display->display_options['filters']['cid']['expose']['identifier'] = 'cid';
  $handler->display->display_options['filters']['cid']['expose']['multiple'] = FALSE;
  /* Filter criterion: Case: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_case';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 0;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Case type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['type']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['type']['expose']['reduce'] = 0;
  /* Filter criterion: Contact: Name (contact_name:family) */
  $handler->display->display_options['filters']['contact_name_family']['id'] = 'contact_name_family';
  $handler->display->display_options['filters']['contact_name_family']['table'] = 'field_data_contact_name';
  $handler->display->display_options['filters']['contact_name_family']['field'] = 'contact_name_family';
  $handler->display->display_options['filters']['contact_name_family']['relationship'] = 'relation_crm_contact_case_crm_core_contact';
  $handler->display->display_options['filters']['contact_name_family']['operator'] = 'starts';
  $handler->display->display_options['filters']['contact_name_family']['group'] = 0;
  $handler->display->display_options['filters']['contact_name_family']['exposed'] = TRUE;
  $handler->display->display_options['filters']['contact_name_family']['expose']['operator_id'] = 'contact_name_family_op';
  $handler->display->display_options['filters']['contact_name_family']['expose']['label'] = 'Last name';
  $handler->display->display_options['filters']['contact_name_family']['expose']['operator'] = 'contact_name_family_op';
  $handler->display->display_options['filters']['contact_name_family']['expose']['identifier'] = 'contact_name_family';
  $handler->display->display_options['filters']['contact_name_family']['expose']['required'] = 0;
  $handler->display->display_options['filters']['contact_name_family']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['contact_name_family']['expose']['multiple'] = FALSE;
  /* Filter criterion: Contact: Name (contact_name:given) */
  $handler->display->display_options['filters']['contact_name_given']['id'] = 'contact_name_given';
  $handler->display->display_options['filters']['contact_name_given']['table'] = 'field_data_contact_name';
  $handler->display->display_options['filters']['contact_name_given']['field'] = 'contact_name_given';
  $handler->display->display_options['filters']['contact_name_given']['relationship'] = 'relation_crm_contact_case_crm_core_contact';
  $handler->display->display_options['filters']['contact_name_given']['operator'] = 'starts';
  $handler->display->display_options['filters']['contact_name_given']['group'] = 0;
  $handler->display->display_options['filters']['contact_name_given']['exposed'] = TRUE;
  $handler->display->display_options['filters']['contact_name_given']['expose']['operator_id'] = 'contact_name_given_op';
  $handler->display->display_options['filters']['contact_name_given']['expose']['label'] = 'First name';
  $handler->display->display_options['filters']['contact_name_given']['expose']['operator'] = 'contact_name_given_op';
  $handler->display->display_options['filters']['contact_name_given']['expose']['identifier'] = 'contact_name_given';
  $handler->display->display_options['filters']['contact_name_given']['expose']['required'] = 0;
  $handler->display->display_options['filters']['contact_name_given']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['contact_name_given']['expose']['multiple'] = FALSE;
  /* Filter criterion: Case: Case is open (case_status) */
  $handler->display->display_options['filters']['case_status_value']['id'] = 'case_status_value';
  $handler->display->display_options['filters']['case_status_value']['table'] = 'field_data_case_status';
  $handler->display->display_options['filters']['case_status_value']['field'] = 'case_status_value';
  $handler->display->display_options['filters']['case_status_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['case_status_value']['group'] = 0;
  /* Filter criterion: Contact: Student ID (field_student_id) */
  $handler->display->display_options['filters']['field_student_id_value']['id'] = 'field_student_id_value';
  $handler->display->display_options['filters']['field_student_id_value']['table'] = 'field_data_field_student_id';
  $handler->display->display_options['filters']['field_student_id_value']['field'] = 'field_student_id_value';
  $handler->display->display_options['filters']['field_student_id_value']['relationship'] = 'relation_crm_contact_case_crm_core_contact';
  $handler->display->display_options['filters']['field_student_id_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_student_id_value']['group'] = 0;
  $handler->display->display_options['filters']['field_student_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_student_id_value']['expose']['operator_id'] = 'field_student_id_value_op';
  $handler->display->display_options['filters']['field_student_id_value']['expose']['label'] = 'Student ID';
  $handler->display->display_options['filters']['field_student_id_value']['expose']['operator'] = 'field_student_id_value_op';
  $handler->display->display_options['filters']['field_student_id_value']['expose']['identifier'] = 'field_student_id_value';
  $handler->display->display_options['filters']['field_student_id_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_student_id_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_student_id_value']['expose']['multiple'] = FALSE;
  /* Filter criterion: Case: User has access to view case */
  $handler->display->display_options['filters']['case_access']['id'] = 'case_access';
  $handler->display->display_options['filters']['case_access']['table'] = 'crm_case';
  $handler->display->display_options['filters']['case_access']['field'] = 'case_access';
  $handler->display->display_options['filters']['case_access']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'crm/cases/open';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Open cases';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Open cases';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Case: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_case';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Case type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['type']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['type']['expose']['reduce'] = 0;
  /* Filter criterion: Contact: Name (contact_name:family) */
  $handler->display->display_options['filters']['contact_name_family']['id'] = 'contact_name_family';
  $handler->display->display_options['filters']['contact_name_family']['table'] = 'field_data_contact_name';
  $handler->display->display_options['filters']['contact_name_family']['field'] = 'contact_name_family';
  $handler->display->display_options['filters']['contact_name_family']['relationship'] = 'relation_crm_contact_case_crm_core_contact';
  $handler->display->display_options['filters']['contact_name_family']['operator'] = 'starts';
  $handler->display->display_options['filters']['contact_name_family']['exposed'] = TRUE;
  $handler->display->display_options['filters']['contact_name_family']['expose']['operator_id'] = 'contact_name_family_op';
  $handler->display->display_options['filters']['contact_name_family']['expose']['label'] = 'Last name';
  $handler->display->display_options['filters']['contact_name_family']['expose']['operator'] = 'contact_name_family_op';
  $handler->display->display_options['filters']['contact_name_family']['expose']['identifier'] = 'contact_name_family';
  $handler->display->display_options['filters']['contact_name_family']['expose']['required'] = 0;
  $handler->display->display_options['filters']['contact_name_family']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['contact_name_family']['expose']['multiple'] = FALSE;
  /* Filter criterion: Contact: Name (contact_name:given) */
  $handler->display->display_options['filters']['contact_name_given']['id'] = 'contact_name_given';
  $handler->display->display_options['filters']['contact_name_given']['table'] = 'field_data_contact_name';
  $handler->display->display_options['filters']['contact_name_given']['field'] = 'contact_name_given';
  $handler->display->display_options['filters']['contact_name_given']['relationship'] = 'relation_crm_contact_case_crm_core_contact';
  $handler->display->display_options['filters']['contact_name_given']['operator'] = 'starts';
  $handler->display->display_options['filters']['contact_name_given']['exposed'] = TRUE;
  $handler->display->display_options['filters']['contact_name_given']['expose']['operator_id'] = 'contact_name_given_op';
  $handler->display->display_options['filters']['contact_name_given']['expose']['label'] = 'First name';
  $handler->display->display_options['filters']['contact_name_given']['expose']['operator'] = 'contact_name_given_op';
  $handler->display->display_options['filters']['contact_name_given']['expose']['identifier'] = 'contact_name_given';
  $handler->display->display_options['filters']['contact_name_given']['expose']['required'] = 0;
  $handler->display->display_options['filters']['contact_name_given']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['contact_name_given']['expose']['multiple'] = FALSE;
  /* Filter criterion: Case: Case is open (case_status) */
  $handler->display->display_options['filters']['case_status_value']['id'] = 'case_status_value';
  $handler->display->display_options['filters']['case_status_value']['table'] = 'field_data_case_status';
  $handler->display->display_options['filters']['case_status_value']['field'] = 'case_status_value';
  $handler->display->display_options['filters']['case_status_value']['operator'] = 'not in';
  $handler->display->display_options['filters']['case_status_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Contact: Student ID (field_student_id) */
  $handler->display->display_options['filters']['field_student_id_value']['id'] = 'field_student_id_value';
  $handler->display->display_options['filters']['field_student_id_value']['table'] = 'field_data_field_student_id';
  $handler->display->display_options['filters']['field_student_id_value']['field'] = 'field_student_id_value';
  $handler->display->display_options['filters']['field_student_id_value']['relationship'] = 'relation_crm_contact_case_crm_core_contact';
  $handler->display->display_options['filters']['field_student_id_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_student_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_student_id_value']['expose']['operator_id'] = 'field_student_id_value_op';
  $handler->display->display_options['filters']['field_student_id_value']['expose']['label'] = 'Student ID';
  $handler->display->display_options['filters']['field_student_id_value']['expose']['operator'] = 'field_student_id_value_op';
  $handler->display->display_options['filters']['field_student_id_value']['expose']['identifier'] = 'field_student_id_value';
  $handler->display->display_options['filters']['field_student_id_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_student_id_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_student_id_value']['expose']['multiple'] = FALSE;
  $handler->display->display_options['path'] = 'crm/cases/closed';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Closed cases';
  $handler->display->display_options['menu']['weight'] = '10';

  /* Display: Page 2 */
  $handler = $view->new_display('page', 'Page 2', 'page_2');
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Case: Case ID */
  $handler->display->display_options['filters']['cid']['id'] = 'cid';
  $handler->display->display_options['filters']['cid']['table'] = 'crm_case';
  $handler->display->display_options['filters']['cid']['field'] = 'cid';
  $handler->display->display_options['filters']['cid']['group'] = 0;
  $handler->display->display_options['filters']['cid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['cid']['expose']['operator_id'] = 'cid_op';
  $handler->display->display_options['filters']['cid']['expose']['label'] = 'Case ID';
  $handler->display->display_options['filters']['cid']['expose']['operator'] = 'cid_op';
  $handler->display->display_options['filters']['cid']['expose']['identifier'] = 'cid';
  $handler->display->display_options['filters']['cid']['expose']['multiple'] = FALSE;
  /* Filter criterion: Case: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_case';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 0;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Case type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['type']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['type']['expose']['reduce'] = 0;
  /* Filter criterion: Contact: Name (contact_name:family) */
  $handler->display->display_options['filters']['contact_name_family']['id'] = 'contact_name_family';
  $handler->display->display_options['filters']['contact_name_family']['table'] = 'field_data_contact_name';
  $handler->display->display_options['filters']['contact_name_family']['field'] = 'contact_name_family';
  $handler->display->display_options['filters']['contact_name_family']['relationship'] = 'relation_crm_contact_case_crm_core_contact';
  $handler->display->display_options['filters']['contact_name_family']['operator'] = 'starts';
  $handler->display->display_options['filters']['contact_name_family']['group'] = 0;
  $handler->display->display_options['filters']['contact_name_family']['exposed'] = TRUE;
  $handler->display->display_options['filters']['contact_name_family']['expose']['operator_id'] = 'contact_name_family_op';
  $handler->display->display_options['filters']['contact_name_family']['expose']['label'] = 'Last name';
  $handler->display->display_options['filters']['contact_name_family']['expose']['operator'] = 'contact_name_family_op';
  $handler->display->display_options['filters']['contact_name_family']['expose']['identifier'] = 'contact_name_family';
  $handler->display->display_options['filters']['contact_name_family']['expose']['required'] = 0;
  $handler->display->display_options['filters']['contact_name_family']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['contact_name_family']['expose']['multiple'] = FALSE;
  /* Filter criterion: Contact: Name (contact_name:given) */
  $handler->display->display_options['filters']['contact_name_given']['id'] = 'contact_name_given';
  $handler->display->display_options['filters']['contact_name_given']['table'] = 'field_data_contact_name';
  $handler->display->display_options['filters']['contact_name_given']['field'] = 'contact_name_given';
  $handler->display->display_options['filters']['contact_name_given']['relationship'] = 'relation_crm_contact_case_crm_core_contact';
  $handler->display->display_options['filters']['contact_name_given']['operator'] = 'starts';
  $handler->display->display_options['filters']['contact_name_given']['group'] = 0;
  $handler->display->display_options['filters']['contact_name_given']['exposed'] = TRUE;
  $handler->display->display_options['filters']['contact_name_given']['expose']['operator_id'] = 'contact_name_given_op';
  $handler->display->display_options['filters']['contact_name_given']['expose']['label'] = 'First name';
  $handler->display->display_options['filters']['contact_name_given']['expose']['operator'] = 'contact_name_given_op';
  $handler->display->display_options['filters']['contact_name_given']['expose']['identifier'] = 'contact_name_given';
  $handler->display->display_options['filters']['contact_name_given']['expose']['required'] = 0;
  $handler->display->display_options['filters']['contact_name_given']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['contact_name_given']['expose']['multiple'] = FALSE;
  /* Filter criterion: Contact: Student ID (field_student_id) */
  $handler->display->display_options['filters']['field_student_id_value']['id'] = 'field_student_id_value';
  $handler->display->display_options['filters']['field_student_id_value']['table'] = 'field_data_field_student_id';
  $handler->display->display_options['filters']['field_student_id_value']['field'] = 'field_student_id_value';
  $handler->display->display_options['filters']['field_student_id_value']['relationship'] = 'relation_crm_contact_case_crm_core_contact';
  $handler->display->display_options['filters']['field_student_id_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_student_id_value']['group'] = 0;
  $handler->display->display_options['filters']['field_student_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_student_id_value']['expose']['operator_id'] = 'field_student_id_value_op';
  $handler->display->display_options['filters']['field_student_id_value']['expose']['label'] = 'Student ID';
  $handler->display->display_options['filters']['field_student_id_value']['expose']['operator'] = 'field_student_id_value_op';
  $handler->display->display_options['filters']['field_student_id_value']['expose']['identifier'] = 'field_student_id_value';
  $handler->display->display_options['filters']['field_student_id_value']['expose']['required'] = 0;
  $handler->display->display_options['filters']['field_student_id_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_student_id_value']['expose']['multiple'] = FALSE;
  $handler->display->display_options['path'] = 'crm/cases/all';
  $translatables['crm_cases'] = array(
    t('Master'),
    t('Cases'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('No cases found.'),
    t('CRM Contact Case'),
    t('Case ID'),
    t('.'),
    t(','),
    t('Name'),
    t('crm/case/[cid]'),
    t('Type'),
    t('First Name'),
    t('crm/contact/[contact_id]'),
    t('Last name'),
    t('Open date'),
    t('Student ID'),
    t('Notes'),
    t('Edit Link'),
    t('Case type'),
    t('First name'),
    t('Page'),
    t('Page 2'),
  );
  $export['crm_cases'] = $view;

  $view = new view;
  $view->name = 'crm_contact_cases';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'crm_case';
  $view->human_name = 'CRM Contact Cases';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Cases';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any crm_core_contact entity of bundle student';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No cases found.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Case: Relation: CRM Contact Case (crm_case <-> crm_core_contact) */
  $handler->display->display_options['relationships']['relation_crm_contact_case_crm_core_contact']['id'] = 'relation_crm_contact_case_crm_core_contact';
  $handler->display->display_options['relationships']['relation_crm_contact_case_crm_core_contact']['table'] = 'crm_case';
  $handler->display->display_options['relationships']['relation_crm_contact_case_crm_core_contact']['field'] = 'relation_crm_contact_case_crm_core_contact';
  $handler->display->display_options['relationships']['relation_crm_contact_case_crm_core_contact']['required'] = 0;
  $handler->display->display_options['relationships']['relation_crm_contact_case_crm_core_contact']['r_index'] = '-1';
  /* Field: Case: Case ID */
  $handler->display->display_options['fields']['cid']['id'] = 'cid';
  $handler->display->display_options['fields']['cid']['table'] = 'crm_case';
  $handler->display->display_options['fields']['cid']['field'] = 'cid';
  $handler->display->display_options['fields']['cid']['label'] = '';
  $handler->display->display_options['fields']['cid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['cid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['cid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['cid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['cid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['cid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['cid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['cid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['cid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['cid']['format_plural'] = 0;
  /* Field: Case: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'crm_case';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'crm/case/[case_id]';
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
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  /* Field: Case: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'crm_case';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Case type';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = 0;
  /* Field: Case: Case is open */
  $handler->display->display_options['fields']['case_status']['id'] = 'case_status';
  $handler->display->display_options['fields']['case_status']['table'] = 'field_data_case_status';
  $handler->display->display_options['fields']['case_status']['field'] = 'case_status';
  $handler->display->display_options['fields']['case_status']['label'] = 'Case status';
  $handler->display->display_options['fields']['case_status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['case_status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['case_status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['case_status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['case_status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['case_status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['case_status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['case_status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['case_status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['case_status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['case_status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['case_status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['case_status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['case_status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['case_status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['case_status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['case_status']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['case_status']['field_api_classes'] = 0;
  /* Contextual filter: CRM Contact: Contact ID */
  $handler->display->display_options['arguments']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['arguments']['contact_id']['table'] = 'crm_core_contact';
  $handler->display->display_options['arguments']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['arguments']['contact_id']['relationship'] = 'relation_crm_contact_case_crm_core_contact';
  $handler->display->display_options['arguments']['contact_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['contact_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['contact_id']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['contact_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['contact_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['contact_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['contact_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['contact_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['contact_id']['not'] = 0;
  /* Filter criterion: Case: User has access to view case */
  $handler->display->display_options['filters']['case_access']['id'] = 'case_access';
  $handler->display->display_options['filters']['case_access']['table'] = 'crm_case';
  $handler->display->display_options['filters']['case_access']['field'] = 'case_access';
  $handler->display->display_options['filters']['case_access']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Case: Case ID */
  $handler->display->display_options['fields']['cid']['id'] = 'cid';
  $handler->display->display_options['fields']['cid']['table'] = 'crm_case';
  $handler->display->display_options['fields']['cid']['field'] = 'cid';
  $handler->display->display_options['fields']['cid']['label'] = '';
  $handler->display->display_options['fields']['cid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['cid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['cid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['cid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['cid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['cid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['cid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['cid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['cid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['cid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['cid']['format_plural'] = 0;
  /* Field: Case: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'crm_case';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'crm/case/[case_id]';
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
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  /* Field: Case: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'crm_case';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Case type';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = 0;
  /* Field: Case: Case is open */
  $handler->display->display_options['fields']['case_status']['id'] = 'case_status';
  $handler->display->display_options['fields']['case_status']['table'] = 'field_data_case_status';
  $handler->display->display_options['fields']['case_status']['field'] = 'case_status';
  $handler->display->display_options['fields']['case_status']['label'] = 'Case status';
  $handler->display->display_options['fields']['case_status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['case_status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['case_status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['case_status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['case_status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['case_status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['case_status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['case_status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['case_status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['case_status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['case_status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['case_status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['case_status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['case_status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['case_status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['case_status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['case_status']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['case_status']['field_api_classes'] = 0;
  $handler->display->display_options['path'] = 'crm/contact/%/cases';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Cases';
  $handler->display->display_options['menu']['weight'] = '0';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Open Cases';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'link_crm_case' => 'link_crm_case',
    'type' => 'type',
  );
  $handler->display->display_options['row_options']['separator'] = ' - ';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Case: Link */
  $handler->display->display_options['fields']['link_crm_case']['id'] = 'link_crm_case';
  $handler->display->display_options['fields']['link_crm_case']['table'] = 'crm_case';
  $handler->display->display_options['fields']['link_crm_case']['field'] = 'link_crm_case';
  $handler->display->display_options['fields']['link_crm_case']['label'] = '';
  $handler->display->display_options['fields']['link_crm_case']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['link_crm_case']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['link_crm_case']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['link_crm_case']['alter']['external'] = 0;
  $handler->display->display_options['fields']['link_crm_case']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['link_crm_case']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['link_crm_case']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['link_crm_case']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['link_crm_case']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['link_crm_case']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['link_crm_case']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['link_crm_case']['alter']['html'] = 0;
  $handler->display->display_options['fields']['link_crm_case']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['link_crm_case']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['link_crm_case']['hide_empty'] = 0;
  $handler->display->display_options['fields']['link_crm_case']['empty_zero'] = 0;
  $handler->display->display_options['fields']['link_crm_case']['hide_alter_empty'] = 0;
  /* Field: Case: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'crm_case';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: CRM Contact: Contact ID */
  $handler->display->display_options['arguments']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['arguments']['contact_id']['table'] = 'crm_core_contact';
  $handler->display->display_options['arguments']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['arguments']['contact_id']['relationship'] = 'relation_crm_contact_case_crm_core_contact';
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
  /* Filter criterion: Case: Case is open (case_status) */
  $handler->display->display_options['filters']['case_status_value']['id'] = 'case_status_value';
  $handler->display->display_options['filters']['case_status_value']['table'] = 'field_data_case_status';
  $handler->display->display_options['filters']['case_status_value']['field'] = 'case_status_value';
  $handler->display->display_options['filters']['case_status_value']['operator'] = 'not in';
  $handler->display->display_options['filters']['case_status_value']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: Case: User has access to view case */
  $handler->display->display_options['filters']['case_access']['id'] = 'case_access';
  $handler->display->display_options['filters']['case_access']['table'] = 'crm_case';
  $handler->display->display_options['filters']['case_access']['field'] = 'case_access';
  $handler->display->display_options['filters']['case_access']['value'] = '1';

  /* Display: Case contact list */
  $handler = $view->new_display('block', 'Case contact list', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Case: Relation: CRM Contact Case (crm_case -> relation) */
  $handler->display->display_options['relationships']['relation_base_left_crm_contact_case']['id'] = 'relation_base_left_crm_contact_case';
  $handler->display->display_options['relationships']['relation_base_left_crm_contact_case']['table'] = 'crm_case';
  $handler->display->display_options['relationships']['relation_base_left_crm_contact_case']['field'] = 'relation_base_left_crm_contact_case';
  $handler->display->display_options['relationships']['relation_base_left_crm_contact_case']['required'] = 0;
  /* Relationship: Relation: Relation: CRM Contact Case (relation -> crm_core_contact) */
  $handler->display->display_options['relationships']['relation_base_crm_contact_case_right_crm_core_contact']['id'] = 'relation_base_crm_contact_case_right_crm_core_contact';
  $handler->display->display_options['relationships']['relation_base_crm_contact_case_right_crm_core_contact']['table'] = 'relation';
  $handler->display->display_options['relationships']['relation_base_crm_contact_case_right_crm_core_contact']['field'] = 'relation_base_crm_contact_case_right_crm_core_contact';
  $handler->display->display_options['relationships']['relation_base_crm_contact_case_right_crm_core_contact']['relationship'] = 'relation_base_left_crm_contact_case';
  $handler->display->display_options['relationships']['relation_base_crm_contact_case_right_crm_core_contact']['required'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: CRM Contact: Contact ID */
  $handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['table'] = 'crm_core_contact';
  $handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['relationship'] = 'relation_base_crm_contact_case_right_crm_core_contact';
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
  /* Field: Contact: Image */
  $handler->display->display_options['fields']['contact_image']['id'] = 'contact_image';
  $handler->display->display_options['fields']['contact_image']['table'] = 'field_data_contact_image';
  $handler->display->display_options['fields']['contact_image']['field'] = 'contact_image';
  $handler->display->display_options['fields']['contact_image']['relationship'] = 'relation_base_crm_contact_case_right_crm_core_contact';
  $handler->display->display_options['fields']['contact_image']['label'] = '';
  $handler->display->display_options['fields']['contact_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['contact_image']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['contact_image']['alter']['path'] = 'crm/contact/[contact_id]';
  $handler->display->display_options['fields']['contact_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['contact_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['contact_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['contact_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['contact_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['contact_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['contact_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['contact_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['contact_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['contact_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['contact_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contact_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['contact_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['contact_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['contact_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['contact_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['contact_image']['settings'] = array(
    'image_style' => 'contact_small',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['contact_image']['field_api_classes'] = 0;
  /* Field: Contact: Name */
  $handler->display->display_options['fields']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['fields']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['relationship'] = 'relation_base_crm_contact_case_right_crm_core_contact';
  $handler->display->display_options['fields']['contact_name']['label'] = '';
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
  $handler->display->display_options['fields']['contact_name']['element_type'] = 'h2';
  $handler->display->display_options['fields']['contact_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contact_name']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['contact_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['contact_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['contact_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['contact_name']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['contact_name']['type'] = 'name_default_full';
  $handler->display->display_options['fields']['contact_name']['settings'] = array(
    'markup' => 0,
  );
  $handler->display->display_options['fields']['contact_name']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Case: Case ID */
  $handler->display->display_options['arguments']['cid']['id'] = 'cid';
  $handler->display->display_options['arguments']['cid']['table'] = 'crm_case';
  $handler->display->display_options['arguments']['cid']['field'] = 'cid';
  $handler->display->display_options['arguments']['cid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['cid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['cid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['cid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['cid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['cid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['cid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['cid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['cid']['not'] = 0;
  $translatables['crm_contact_cases'] = array(
    t('Master'),
    t('Cases'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('No cases found.'),
    t('CRM Contact Case'),
    t('.'),
    t(','),
    t('crm/case/[case_id]'),
    t('Case type'),
    t('Case status'),
    t('All'),
    t('Page'),
    t('Block'),
    t('Open Cases'),
    t('Case contact list'),
    t('crm/contact/[contact_id]'),
  );
  $export['crm_contact_cases'] = $view;

  $view = new view;
  $view->name = 'crm_user_cases';
  $view->description = 'Lists the current user\'s open cases';
  $view->tag = 'default';
  $view->base_table = 'crm_case';
  $view->human_name = 'CRM User Cases';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Your cases';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Header message';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'Below is a list of cases about you that you are allowed to edit. You will only be able to edit a case while it is still open, you can view a list of your closed cases using the "Closed" tab below.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No results';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'Sorry, we couldn\'t find any cases for you. Sometimes cases are made private so only advisors and other users can view them.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Case: Relation: CRM Contact Case (crm_case <-> crm_core_contact) */
  $handler->display->display_options['relationships']['relation_crm_contact_case_crm_core_contact']['id'] = 'relation_crm_contact_case_crm_core_contact';
  $handler->display->display_options['relationships']['relation_crm_contact_case_crm_core_contact']['table'] = 'crm_case';
  $handler->display->display_options['relationships']['relation_crm_contact_case_crm_core_contact']['field'] = 'relation_crm_contact_case_crm_core_contact';
  $handler->display->display_options['relationships']['relation_crm_contact_case_crm_core_contact']['required'] = 0;
  $handler->display->display_options['relationships']['relation_crm_contact_case_crm_core_contact']['r_index'] = '-1';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_user_contact_user']['id'] = 'reverse_field_user_contact_user';
  $handler->display->display_options['relationships']['reverse_field_user_contact_user']['table'] = 'crm_core_contact';
  $handler->display->display_options['relationships']['reverse_field_user_contact_user']['field'] = 'reverse_field_user_contact_user';
  $handler->display->display_options['relationships']['reverse_field_user_contact_user']['relationship'] = 'relation_crm_contact_case_crm_core_contact';
  $handler->display->display_options['relationships']['reverse_field_user_contact_user']['required'] = 0;
  /* Field: Case: Case ID */
  $handler->display->display_options['fields']['cid']['id'] = 'cid';
  $handler->display->display_options['fields']['cid']['table'] = 'crm_case';
  $handler->display->display_options['fields']['cid']['field'] = 'cid';
  /* Field: Case: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'crm_case';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'crm/case/[cid]';
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
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  /* Field: Case: Edit Link */
  $handler->display->display_options['fields']['edit_crm_case']['id'] = 'edit_crm_case';
  $handler->display->display_options['fields']['edit_crm_case']['table'] = 'crm_case';
  $handler->display->display_options['fields']['edit_crm_case']['field'] = 'edit_crm_case';
  $handler->display->display_options['fields']['edit_crm_case']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_crm_case']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_crm_case']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['edit_crm_case']['alter']['path'] = 'crm/case/[case_id]?destination=<front>';
  $handler->display->display_options['fields']['edit_crm_case']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_crm_case']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_crm_case']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_crm_case']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_crm_case']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_crm_case']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_crm_case']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_crm_case']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_crm_case']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_crm_case']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_crm_case']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_crm_case']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_crm_case']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_crm_case']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_crm_case']['hide_alter_empty'] = 0;
  /* Field: Case: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'crm_case';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  /* Field: Case: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'crm_case';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last updated';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['changed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = 0;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'reverse_field_user_contact_user';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
  /* Filter criterion: Case: Case is open (case_status) */
  $handler->display->display_options['filters']['case_status_value']['id'] = 'case_status_value';
  $handler->display->display_options['filters']['case_status_value']['table'] = 'field_data_case_status';
  $handler->display->display_options['filters']['case_status_value']['field'] = 'case_status_value';
  $handler->display->display_options['filters']['case_status_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Case: Contact has access to case */
  $handler->display->display_options['filters']['case_contact_access']['id'] = 'case_contact_access';
  $handler->display->display_options['filters']['case_contact_access']['table'] = 'crm_case';
  $handler->display->display_options['filters']['case_contact_access']['field'] = 'case_contact_access';
  $handler->display->display_options['filters']['case_contact_access']['value'] = '1';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['crm_user_cases'] = array(
    t('Master'),
    t('Your cases'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Header message'),
    t('Below is a list of cases about you that you are allowed to edit. You will only be able to edit a case while it is still open, you can view a list of your closed cases using the "Closed" tab below.'),
    t('No results'),
    t('Sorry, we couldn\'t find any cases for you. Sometimes cases are made private so only advisors and other users can view them.'),
    t('CRM Contact Case'),
    t('User referencing Contact from field_user_contact'),
    t('Case ID'),
    t('.'),
    t(','),
    t('Name'),
    t('crm/case/[cid]'),
    t('Edit'),
    t('crm/case/[case_id]?destination=<front>'),
    t('Created'),
    t('Last updated'),
    t('All'),
    t('Block'),
  );
  $export['crm_user_cases'] = $view;

  return $export;
}
