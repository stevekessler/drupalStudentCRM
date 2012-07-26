<?php
/**
 * @file
 * student_crm_webform.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function student_crm_webform_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'form_submissions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'webform_submission_entity';
  $view->human_name = 'Form submissions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Form submissions';
  $handler->display->display_options['css_class'] = 'webform-entity-modal';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = 'webform_submission_entity_form_name';
  $handler->display->display_options['style_options']['group_rendered'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'webform_submission_entity_form_name' => 'webform_submission_entity_form_name',
    'counter' => 'counter',
    'link_webform_submission_entity' => 'link_webform_submission_entity',
  );
  $handler->display->display_options['row_options']['separator'] = ' - ';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Relationship: Webform Submission: Relation: Webform submission to entities (webform_submission_entity -&gt; crm_case) */
  $handler->display->display_options['relationships']['relation_webform_submission_to_entities_crm_case']['id'] = 'relation_webform_submission_to_entities_crm_case';
  $handler->display->display_options['relationships']['relation_webform_submission_to_entities_crm_case']['table'] = 'webform_submission_entity';
  $handler->display->display_options['relationships']['relation_webform_submission_to_entities_crm_case']['field'] = 'relation_webform_submission_to_entities_crm_case';
  $handler->display->display_options['relationships']['relation_webform_submission_to_entities_crm_case']['required'] = 0;
  $handler->display->display_options['relationships']['relation_webform_submission_to_entities_crm_case']['r_index'] = '-1';
  /* Field: Webform Submission: Form name */
  $handler->display->display_options['fields']['webform_submission_entity_form_name']['id'] = 'webform_submission_entity_form_name';
  $handler->display->display_options['fields']['webform_submission_entity_form_name']['table'] = 'webform_submission_entity';
  $handler->display->display_options['fields']['webform_submission_entity_form_name']['field'] = 'webform_submission_entity_form_name';
  $handler->display->display_options['fields']['webform_submission_entity_form_name']['label'] = '';
  $handler->display->display_options['fields']['webform_submission_entity_form_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['webform_submission_entity_form_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['webform_submission_entity_form_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['webform_submission_entity_form_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['webform_submission_entity_form_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['webform_submission_entity_form_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['webform_submission_entity_form_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['webform_submission_entity_form_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['webform_submission_entity_form_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['webform_submission_entity_form_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['webform_submission_entity_form_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['webform_submission_entity_form_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['webform_submission_entity_form_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['webform_submission_entity_form_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['webform_submission_entity_form_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['webform_submission_entity_form_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['webform_submission_entity_form_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['webform_submission_entity_form_name']['hide_alter_empty'] = 1;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['counter']['alter']['text'] = 'Submission #[counter]';
  $handler->display->display_options['fields']['counter']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['external'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['counter']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['counter']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['html'] = 0;
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['counter']['hide_empty'] = 0;
  $handler->display->display_options['fields']['counter']['empty_zero'] = 0;
  $handler->display->display_options['fields']['counter']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Webform Submission: Link */
  $handler->display->display_options['fields']['link_webform_submission_entity']['id'] = 'link_webform_submission_entity';
  $handler->display->display_options['fields']['link_webform_submission_entity']['table'] = 'webform_submission_entity';
  $handler->display->display_options['fields']['link_webform_submission_entity']['field'] = 'link_webform_submission_entity';
  $handler->display->display_options['fields']['link_webform_submission_entity']['label'] = '';
  $handler->display->display_options['fields']['link_webform_submission_entity']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['link_webform_submission_entity']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['link_webform_submission_entity']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['link_webform_submission_entity']['alter']['external'] = 0;
  $handler->display->display_options['fields']['link_webform_submission_entity']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['link_webform_submission_entity']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['link_webform_submission_entity']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['link_webform_submission_entity']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['link_webform_submission_entity']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['link_webform_submission_entity']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['link_webform_submission_entity']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['link_webform_submission_entity']['alter']['html'] = 0;
  $handler->display->display_options['fields']['link_webform_submission_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['link_webform_submission_entity']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['link_webform_submission_entity']['hide_empty'] = 0;
  $handler->display->display_options['fields']['link_webform_submission_entity']['empty_zero'] = 0;
  $handler->display->display_options['fields']['link_webform_submission_entity']['hide_alter_empty'] = 0;
  /* Contextual filter: Case: Case ID */
  $handler->display->display_options['arguments']['cid']['id'] = 'cid';
  $handler->display->display_options['arguments']['cid']['table'] = 'crm_case';
  $handler->display->display_options['arguments']['cid']['field'] = 'cid';
  $handler->display->display_options['arguments']['cid']['relationship'] = 'relation_webform_submission_to_entities_crm_case';
  $handler->display->display_options['arguments']['cid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['cid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['cid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['cid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['cid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['cid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['cid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['cid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['cid']['not'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Case form submissions';
  $translatables['form_submissions'] = array(
    t('Master'),
    t('Form submissions'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Webform submission to entities'),
    t('Submission #[counter]'),
    t('All'),
    t('Block'),
    t('Case form submissions'),
  );
  $export['form_submissions'] = $view;

  return $export;
}
