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
  $handler->display->display_options['title'] = 'CRM Tasks';
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
  /* Relationship: User: Relation: CRM Task (user -> relation) */
  $handler->display->display_options['relationships']['relation_base_left_crm_task']['id'] = 'relation_base_left_crm_task';
  $handler->display->display_options['relationships']['relation_base_left_crm_task']['table'] = 'users';
  $handler->display->display_options['relationships']['relation_base_left_crm_task']['field'] = 'relation_base_left_crm_task';
  $handler->display->display_options['relationships']['relation_base_left_crm_task']['label'] = 'CRM Task - relation';
  $handler->display->display_options['relationships']['relation_base_left_crm_task']['required'] = 1;
  /* Relationship: User: Relation: CRM Task (user <-> crm_activity) */
  $handler->display->display_options['relationships']['relation_crm_task_crm_activity']['id'] = 'relation_crm_task_crm_activity';
  $handler->display->display_options['relationships']['relation_crm_task_crm_activity']['table'] = 'users';
  $handler->display->display_options['relationships']['relation_crm_task_crm_activity']['field'] = 'relation_crm_task_crm_activity';
  $handler->display->display_options['relationships']['relation_crm_task_crm_activity']['label'] = 'CRM Task - activity';
  $handler->display->display_options['relationships']['relation_crm_task_crm_activity']['required'] = 0;
  /* Relationship: User: Relation: CRM Task (user <-> crm_case) */
  $handler->display->display_options['relationships']['relation_crm_task_crm_case']['id'] = 'relation_crm_task_crm_case';
  $handler->display->display_options['relationships']['relation_crm_task_crm_case']['table'] = 'users';
  $handler->display->display_options['relationships']['relation_crm_task_crm_case']['field'] = 'relation_crm_task_crm_case';
  $handler->display->display_options['relationships']['relation_crm_task_crm_case']['label'] = 'CRM Task - case';
  $handler->display->display_options['relationships']['relation_crm_task_crm_case']['required'] = 0;
  /* Relationship: User: Relation: CRM Task (user <-> crm_contact) */
  $handler->display->display_options['relationships']['relation_crm_task_crm_contact']['id'] = 'relation_crm_task_crm_contact';
  $handler->display->display_options['relationships']['relation_crm_task_crm_contact']['table'] = 'users';
  $handler->display->display_options['relationships']['relation_crm_task_crm_contact']['field'] = 'relation_crm_task_crm_contact';
  $handler->display->display_options['relationships']['relation_crm_task_crm_contact']['label'] = 'CRM Task - contact';
  $handler->display->display_options['relationships']['relation_crm_task_crm_contact']['required'] = 0;
  /* Relationship: User: Relation: CRM Task (user <-> node) */
  $handler->display->display_options['relationships']['relation_crm_task_node']['id'] = 'relation_crm_task_node';
  $handler->display->display_options['relationships']['relation_crm_task_node']['table'] = 'users';
  $handler->display->display_options['relationships']['relation_crm_task_node']['field'] = 'relation_crm_task_node';
  $handler->display->display_options['relationships']['relation_crm_task_node']['label'] = 'CRM Task - node';
  $handler->display->display_options['relationships']['relation_crm_task_node']['required'] = 0;
  /* Field: Actvity: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'crm_activity';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'relation_crm_task_crm_activity';
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
  /* Field: Case: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'crm_case';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'relation_crm_task_crm_case';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  /* Field: Contact: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'relation_crm_task_crm_contact';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_first_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_first_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_first_name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_first_name']['field_api_classes'] = 0;
  /* Field: Contact: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'relation_crm_task_crm_contact';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_last_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_last_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_last_name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_last_name']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'relation_crm_task_node';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = 1;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Name';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[title] [field_first_name] [field_last_name] [title_1] [name]';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'crm/tasks';
  $translatables['crm_tasks'] = array(
    t('Master'),
    t('CRM Tasks'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('CRM Task - relation'),
    t('CRM Task - activity'),
    t('CRM Task - case'),
    t('CRM Task - contact'),
    t('CRM Task - node'),
    t('Name'),
    t('[title] [field_first_name] [field_last_name] [title_1] [name]'),
    t('Due date'),
    t('Note'),
    t('All'),
    t('Page'),
  );
  $export['crm_tasks'] = $view;

  return $export;
}