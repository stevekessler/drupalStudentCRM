<?php
/**
 * @file
 * student_crm_activity.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function student_crm_activity_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'crm_activities';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'crm_activity';
  $view->human_name = 'CRM Activities';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Notes';
  $handler->display->display_options['css_class'] = 'ajax-loaded-view';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'default';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No notes yet! Use the above form to create a new note about this person.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Activities: Relation: CRM Activity (crm_activity <-> crm_contact) */
  $handler->display->display_options['relationships']['relation_crm_activity_crm_contact']['id'] = 'relation_crm_activity_crm_contact';
  $handler->display->display_options['relationships']['relation_crm_activity_crm_contact']['table'] = 'crm_activity';
  $handler->display->display_options['relationships']['relation_crm_activity_crm_contact']['field'] = 'relation_crm_activity_crm_contact';
  $handler->display->display_options['relationships']['relation_crm_activity_crm_contact']['required'] = 0;
  $handler->display->display_options['relationships']['relation_crm_activity_crm_contact']['r_index'] = '-1';
  /* Sort criterion: Activities: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'crm_activity';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: CRM Contact: Contact ID */
  $handler->display->display_options['arguments']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['arguments']['contact_id']['table'] = 'crm_contact';
  $handler->display->display_options['arguments']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['arguments']['contact_id']['relationship'] = 'relation_crm_activity_crm_contact';
  $handler->display->display_options['arguments']['contact_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['contact_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['contact_id']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['contact_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['contact_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['contact_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['contact_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['contact_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['contact_id']['not'] = 0;
  /* Filter criterion: Activities: User has access to view activity */
  $handler->display->display_options['filters']['activity_access']['id'] = 'activity_access';
  $handler->display->display_options['filters']['activity_access']['table'] = 'crm_activity';
  $handler->display->display_options['filters']['activity_access']['field'] = 'activity_access';
  $handler->display->display_options['filters']['activity_access']['value'] = '1';

  /* Display: Contact activities */
  $handler = $view->new_display('block', 'Contact activities', 'block');

  /* Display: Case activities */
  $handler = $view->new_display('block', 'Case activities', 'block_1');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No notes yet! Use the above form to create a new note about this case.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Activities: Relation: CRM Activity (crm_activity <-> crm_case) */
  $handler->display->display_options['relationships']['relation_crm_activity_crm_case']['id'] = 'relation_crm_activity_crm_case';
  $handler->display->display_options['relationships']['relation_crm_activity_crm_case']['table'] = 'crm_activity';
  $handler->display->display_options['relationships']['relation_crm_activity_crm_case']['field'] = 'relation_crm_activity_crm_case';
  $handler->display->display_options['relationships']['relation_crm_activity_crm_case']['required'] = 0;
  $handler->display->display_options['relationships']['relation_crm_activity_crm_case']['r_index'] = '-1';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Case: Case ID */
  $handler->display->display_options['arguments']['cid']['id'] = 'cid';
  $handler->display->display_options['arguments']['cid']['table'] = 'crm_case';
  $handler->display->display_options['arguments']['cid']['field'] = 'cid';
  $handler->display->display_options['arguments']['cid']['relationship'] = 'relation_crm_activity_crm_case';
  $handler->display->display_options['arguments']['cid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['cid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['cid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['cid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['cid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['cid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['cid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['cid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['cid']['not'] = 0;
  $translatables['crm_activities'] = array(
    t('Master'),
    t('Notes'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('No notes yet! Use the above form to create a new note about this person.'),
    t('CRM Activity'),
    t('All'),
    t('Contact activities'),
    t('Case activities'),
    t('No notes yet! Use the above form to create a new note about this case.'),
  );
  $export['crm_activities'] = $view;

  return $export;
}
