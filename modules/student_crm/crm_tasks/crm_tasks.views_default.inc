<?php
/**
 * @file
 * crm_tasks.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function crm_tasks_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'crm_tasks';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'CRM Tasks';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Tasks';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No tasks found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: User: Relation: CRM Task (user -> relation) */
  $handler->display->display_options['relationships']['relation_base_left_crm_task']['id'] = 'relation_base_left_crm_task';
  $handler->display->display_options['relationships']['relation_base_left_crm_task']['table'] = 'users';
  $handler->display->display_options['relationships']['relation_base_left_crm_task']['field'] = 'relation_base_left_crm_task';
  $handler->display->display_options['relationships']['relation_base_left_crm_task']['label'] = 'CRM Task - relation';
  $handler->display->display_options['relationships']['relation_base_left_crm_task']['required'] = 1;
  /* Relationship: Relation: Relation: CRM Task (relation -> node) */
  $handler->display->display_options['relationships']['relation_base_right_node']['id'] = 'relation_base_right_node';
  $handler->display->display_options['relationships']['relation_base_right_node']['table'] = 'relation';
  $handler->display->display_options['relationships']['relation_base_right_node']['field'] = 'relation_base_right_node';
  $handler->display->display_options['relationships']['relation_base_right_node']['relationship'] = 'relation_base_left_crm_task';
  $handler->display->display_options['relationships']['relation_base_right_node']['label'] = 'CRM Task - node';
  $handler->display->display_options['relationships']['relation_base_right_node']['required'] = 0;
  /* Field: Relation: Rid */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'relation';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['relationship'] = 'relation_base_left_crm_task';
  $handler->display->display_options['fields']['rid']['label'] = '';
  $handler->display->display_options['fields']['rid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['rid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['rid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['rid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['rid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['rid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['rid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['rid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['rid']['format_plural'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'relation_base_right_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Relation: Complete */
  $handler->display->display_options['fields']['field_task_complete']['id'] = 'field_task_complete';
  $handler->display->display_options['fields']['field_task_complete']['table'] = 'field_data_field_task_complete';
  $handler->display->display_options['fields']['field_task_complete']['field'] = 'field_task_complete';
  $handler->display->display_options['fields']['field_task_complete']['relationship'] = 'relation_base_left_crm_task';
  $handler->display->display_options['fields']['field_task_complete']['label'] = '';
  $handler->display->display_options['fields']['field_task_complete']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_task_complete']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_task_complete']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_task_complete']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_task_complete']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_task_complete']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['field_api_classes'] = 0;
  /* Field: Task operations: Task checkbox */
  $handler->display->display_options['fields']['task_checkbox']['id'] = 'task_checkbox';
  $handler->display->display_options['fields']['task_checkbox']['table'] = 'crm_tasks';
  $handler->display->display_options['fields']['task_checkbox']['field'] = 'task_checkbox';
  $handler->display->display_options['fields']['task_checkbox']['label'] = 'Done';
  $handler->display->display_options['fields']['task_checkbox']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['task_checkbox']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['task_checkbox']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['task_checkbox']['alter']['external'] = 0;
  $handler->display->display_options['fields']['task_checkbox']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['task_checkbox']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['task_checkbox']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['task_checkbox']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['task_checkbox']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['task_checkbox']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['task_checkbox']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['task_checkbox']['alter']['html'] = 0;
  $handler->display->display_options['fields']['task_checkbox']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['task_checkbox']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['task_checkbox']['hide_empty'] = 0;
  $handler->display->display_options['fields']['task_checkbox']['empty_zero'] = 0;
  $handler->display->display_options['fields']['task_checkbox']['hide_alter_empty'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Name';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_first_name] [field_last_name] [title]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Field: Relation: Due date */
  $handler->display->display_options['fields']['field_task_due']['id'] = 'field_task_due';
  $handler->display->display_options['fields']['field_task_due']['table'] = 'field_data_field_task_due';
  $handler->display->display_options['fields']['field_task_due']['field'] = 'field_task_due';
  $handler->display->display_options['fields']['field_task_due']['relationship'] = 'relation_base_left_crm_task';
  /* Field: Relation: Note */
  $handler->display->display_options['fields']['field_task_note']['id'] = 'field_task_note';
  $handler->display->display_options['fields']['field_task_note']['table'] = 'field_data_field_task_note';
  $handler->display->display_options['fields']['field_task_note']['field'] = 'field_task_note';
  $handler->display->display_options['fields']['field_task_note']['relationship'] = 'relation_base_left_crm_task';
  $handler->display->display_options['fields']['field_task_note']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_task_note']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_task_note']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_task_note']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_task_note']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_task_note']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_task_note']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_task_note']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_task_note']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_task_note']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_task_note']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_task_note']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_task_note']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_task_note']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_task_note']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_task_note']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_task_note']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_task_note']['field_api_classes'] = 0;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Relation: Relation type */
  $handler->display->display_options['filters']['relation_type']['id'] = 'relation_type';
  $handler->display->display_options['filters']['relation_type']['table'] = 'relation';
  $handler->display->display_options['filters']['relation_type']['field'] = 'relation_type';
  $handler->display->display_options['filters']['relation_type']['relationship'] = 'relation_base_left_crm_task';
  $handler->display->display_options['filters']['relation_type']['value'] = 'crm_task';
  /* Filter criterion: Relation: Complete (field_task_complete) */
  $handler->display->display_options['filters']['field_task_complete_value']['id'] = 'field_task_complete_value';
  $handler->display->display_options['filters']['field_task_complete_value']['table'] = 'field_data_field_task_complete';
  $handler->display->display_options['filters']['field_task_complete_value']['field'] = 'field_task_complete_value';
  $handler->display->display_options['filters']['field_task_complete_value']['relationship'] = 'relation_base_left_crm_task';
  $handler->display->display_options['filters']['field_task_complete_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_task_complete_value']['expose']['operator_id'] = 'field_task_complete_value_op';
  $handler->display->display_options['filters']['field_task_complete_value']['expose']['label'] = 'Completed';
  $handler->display->display_options['filters']['field_task_complete_value']['expose']['operator'] = 'field_task_complete_value_op';
  $handler->display->display_options['filters']['field_task_complete_value']['expose']['identifier'] = 'field_task_complete_value';
  $handler->display->display_options['filters']['field_task_complete_value']['expose']['reduce'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'crm/tasks';
  $handler->display->display_options['menu']['title'] = 'Tasks';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['tab_options']['title'] = 'Tasks';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Completed tasks';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Relation: Relation type */
  $handler->display->display_options['filters']['relation_type']['id'] = 'relation_type';
  $handler->display->display_options['filters']['relation_type']['table'] = 'relation';
  $handler->display->display_options['filters']['relation_type']['field'] = 'relation_type';
  $handler->display->display_options['filters']['relation_type']['relationship'] = 'relation_base_left_crm_task';
  $handler->display->display_options['filters']['relation_type']['value'] = 'crm_task';
  /* Filter criterion: Relation: Complete (field_task_complete) */
  $handler->display->display_options['filters']['field_task_complete_value']['id'] = 'field_task_complete_value';
  $handler->display->display_options['filters']['field_task_complete_value']['table'] = 'field_data_field_task_complete';
  $handler->display->display_options['filters']['field_task_complete_value']['field'] = 'field_task_complete_value';
  $handler->display->display_options['filters']['field_task_complete_value']['relationship'] = 'relation_base_left_crm_task';
  $handler->display->display_options['filters']['field_task_complete_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_task_complete_value']['expose']['operator_id'] = 'field_task_complete_value_op';
  $handler->display->display_options['filters']['field_task_complete_value']['expose']['label'] = 'Completed';
  $handler->display->display_options['filters']['field_task_complete_value']['expose']['operator'] = 'field_task_complete_value_op';
  $handler->display->display_options['filters']['field_task_complete_value']['expose']['identifier'] = 'field_task_complete_value';
  $handler->display->display_options['filters']['field_task_complete_value']['expose']['reduce'] = 0;
  $handler->display->display_options['path'] = 'crm/tasks/completed';
  $handler->display->display_options['menu']['title'] = 'Completed';
  $handler->display->display_options['menu']['weight'] = '0';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Your Tasks';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_task_complete' => 'field_task_complete',
    'rid' => 'rid',
    'mark_complete' => 'mark_complete',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['row_options']['separator'] = ' ';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Relation: Complete */
  $handler->display->display_options['fields']['field_task_complete']['id'] = 'field_task_complete';
  $handler->display->display_options['fields']['field_task_complete']['table'] = 'field_data_field_task_complete';
  $handler->display->display_options['fields']['field_task_complete']['field'] = 'field_task_complete';
  $handler->display->display_options['fields']['field_task_complete']['relationship'] = 'relation_base_left_crm_task';
  $handler->display->display_options['fields']['field_task_complete']['label'] = '';
  $handler->display->display_options['fields']['field_task_complete']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_task_complete']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_task_complete']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_task_complete']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_task_complete']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_task_complete']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_task_complete']['field_api_classes'] = 0;
  /* Field: Relation: Rid */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'relation';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['relationship'] = 'relation_base_left_crm_task';
  $handler->display->display_options['fields']['rid']['label'] = '';
  $handler->display->display_options['fields']['rid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['rid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['rid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['rid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['rid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['rid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['rid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['rid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['rid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['rid']['format_plural'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'NAME SOON';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  $translatables['crm_tasks'] = array(
    t('Master'),
    t('Tasks'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('No tasks found.'),
    t('CRM Task - relation'),
    t('CRM Task - node'),
    t('.'),
    t(','),
    t('Done'),
    t('Name'),
    t('[field_first_name] [field_last_name] [title]'),
    t('Due date'),
    t('Note'),
    t('All'),
    t('Completed'),
    t('Page'),
    t('Completed tasks'),
    t('Block'),
    t('Your Tasks'),
    t('NAME SOON'),
  );
  $export['crm_tasks'] = $view;

  return $export;
}
