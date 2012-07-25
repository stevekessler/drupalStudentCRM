<?php
/**
 * @file
 * student_crm_basket.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function student_crm_basket_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'baskets';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Baskets';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Baskets';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['group_rendered'] = 1;
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
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
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_basket_users_target_id']['id'] = 'field_basket_users_target_id';
  $handler->display->display_options['relationships']['field_basket_users_target_id']['table'] = 'field_data_field_basket_users';
  $handler->display->display_options['relationships']['field_basket_users_target_id']['field'] = 'field_basket_users_target_id';
  $handler->display->display_options['relationships']['field_basket_users_target_id']['required'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['uid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['uid']['link_to_user'] = 1;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['fields']['uid_1']['table'] = 'users';
  $handler->display->display_options['fields']['uid_1']['field'] = 'uid';
  $handler->display->display_options['fields']['uid_1']['relationship'] = 'field_basket_users_target_id';
  $handler->display->display_options['fields']['uid_1']['label'] = '';
  $handler->display->display_options['fields']['uid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['uid_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uid_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uid_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['uid_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['uid_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['uid_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['uid_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uid_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uid_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uid_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uid_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['uid_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uid_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uid_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['uid_1']['link_to_user'] = 1;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Owner';
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
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: Content: Cases */
  $handler->display->display_options['fields']['field_basket_cases']['id'] = 'field_basket_cases';
  $handler->display->display_options['fields']['field_basket_cases']['table'] = 'field_data_field_basket_cases';
  $handler->display->display_options['fields']['field_basket_cases']['field'] = 'field_basket_cases';
  $handler->display->display_options['fields']['field_basket_cases']['label'] = '';
  $handler->display->display_options['fields']['field_basket_cases']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_basket_cases']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_basket_cases']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_basket_cases']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_basket_cases']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_basket_cases']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_basket_cases']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_basket_cases']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_basket_cases']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_basket_cases']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_basket_cases']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_basket_cases']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_basket_cases']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_basket_cases']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_basket_cases']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_basket_cases']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_basket_cases']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_basket_cases']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_basket_cases']['click_sort_column'] = 'target_id';
  $handler->display->display_options['fields']['field_basket_cases']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_basket_cases']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_basket_cases']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_basket_cases']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_basket_cases']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_basket_cases']['field_api_classes'] = 0;
  /* Field: Content: Contacts */
  $handler->display->display_options['fields']['field_basket_contacts']['id'] = 'field_basket_contacts';
  $handler->display->display_options['fields']['field_basket_contacts']['table'] = 'field_data_field_basket_contacts';
  $handler->display->display_options['fields']['field_basket_contacts']['field'] = 'field_basket_contacts';
  $handler->display->display_options['fields']['field_basket_contacts']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_basket_contacts']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_basket_contacts']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_basket_contacts']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_basket_contacts']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_basket_contacts']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_basket_contacts']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_basket_contacts']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_basket_contacts']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_basket_contacts']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_basket_contacts']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_basket_contacts']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_basket_contacts']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_basket_contacts']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_basket_contacts']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_basket_contacts']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_basket_contacts']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_basket_contacts']['click_sort_column'] = 'target_id';
  $handler->display->display_options['fields']['field_basket_contacts']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_basket_contacts']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_basket_contacts']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_basket_contacts']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_basket_contacts']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_basket_contacts']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'basket' => 'basket',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'crm/baskets';
  $translatables['baskets'] = array(
    t('Master'),
    t('Baskets'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('author'),
    t('User entity referenced from field_basket_users'),
    t('Description'),
    t('Owner'),
    t('Contacts'),
    t('Page'),
  );
  $export['baskets'] = $view;

  return $export;
}
