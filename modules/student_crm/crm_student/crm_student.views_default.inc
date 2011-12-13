<?php
/**
 * @file
 * crm_student.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function crm_student_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'crm_contact_fields';
  $view->description = 'Fields for the contact page';
  $view->tag = 'default';
  $view->base_table = 'crm_core_contact';
  $view->human_name = 'CRM Contact Fields';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'contact-fields';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'contact_image' => 'contact_image',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Field: Contact: Image */
  $handler->display->display_options['fields']['contact_image']['id'] = 'contact_image';
  $handler->display->display_options['fields']['contact_image']['table'] = 'field_data_contact_image';
  $handler->display->display_options['fields']['contact_image']['field'] = 'contact_image';
  $handler->display->display_options['fields']['contact_image']['label'] = '';
  $handler->display->display_options['fields']['contact_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['contact_image']['alter']['make_link'] = 0;
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
  $handler->display->display_options['fields']['contact_image']['element_type'] = '0';
  $handler->display->display_options['fields']['contact_image']['element_label_type'] = '0';
  $handler->display->display_options['fields']['contact_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contact_image']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['contact_image']['element_wrapper_class'] = 'contact-image';
  $handler->display->display_options['fields']['contact_image']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['contact_image']['hide_empty'] = 1;
  $handler->display->display_options['fields']['contact_image']['empty_zero'] = 1;
  $handler->display->display_options['fields']['contact_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['contact_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['contact_image']['settings'] = array(
    'image_style' => 'contact_full',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['contact_image']['field_api_classes'] = 0;
  /* Field: Contact: Name */
  $handler->display->display_options['fields']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['fields']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['label'] = '';
  $handler->display->display_options['fields']['contact_name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['contact_name']['alter']['make_link'] = 0;
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
  $handler->display->display_options['fields']['contact_name']['element_type'] = 'h1';
  $handler->display->display_options['fields']['contact_name']['element_class'] = 'contact-name';
  $handler->display->display_options['fields']['contact_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contact_name']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['contact_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['contact_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['contact_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['contact_name']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['contact_name']['type'] = 'name_default_short_full';
  $handler->display->display_options['fields']['contact_name']['field_api_classes'] = 0;
  /* Field: Contact: Class level */
  $handler->display->display_options['fields']['field_student_level']['id'] = 'field_student_level';
  $handler->display->display_options['fields']['field_student_level']['table'] = 'field_data_field_student_level';
  $handler->display->display_options['fields']['field_student_level']['field'] = 'field_student_level';
  $handler->display->display_options['fields']['field_student_level']['label'] = '';
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
  $handler->display->display_options['fields']['field_student_level']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_student_level']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_student_level']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_student_level']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_student_level']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_student_level']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_student_level']['field_api_classes'] = 0;
  /* Field: Contact: Degrees */
  $handler->display->display_options['fields']['field_student_degrees']['id'] = 'field_student_degrees';
  $handler->display->display_options['fields']['field_student_degrees']['table'] = 'field_data_field_student_degrees';
  $handler->display->display_options['fields']['field_student_degrees']['field'] = 'field_student_degrees';
  $handler->display->display_options['fields']['field_student_degrees']['label'] = '';
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
  $handler->display->display_options['fields']['field_student_degrees']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_student_degrees']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_student_degrees']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_student_degrees']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_student_degrees']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_student_degrees']['field_api_classes'] = 0;
  /* Field: Contact: Tags */
  $handler->display->display_options['fields']['field_student_tags']['id'] = 'field_student_tags';
  $handler->display->display_options['fields']['field_student_tags']['table'] = 'field_data_field_student_tags';
  $handler->display->display_options['fields']['field_student_tags']['field'] = 'field_student_tags';
  $handler->display->display_options['fields']['field_student_tags']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_student_tags']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_student_tags']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_student_tags']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_student_tags']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_student_tags']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_student_tags']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_student_tags']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_student_tags']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_student_tags']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_student_tags']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_student_tags']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_student_tags']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_student_tags']['element_class'] = 'tags';
  $handler->display->display_options['fields']['field_student_tags']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_student_tags']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_student_tags']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_student_tags']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_student_tags']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_student_tags']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_student_tags']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_student_tags']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_student_tags']['multi_type'] = 'ul';
  $handler->display->display_options['fields']['field_student_tags']['separator'] = ' ';
  $handler->display->display_options['fields']['field_student_tags']['field_api_classes'] = 0;
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

  /* Display: Student name */
  $handler = $view->new_display('block', 'Student name', 'block');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'contact-fields contact-header';

  /* Display: Student fields */
  $handler = $view->new_display('block', 'Student fields', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Basic information';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['class'] = 'contact-field-list';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_student_id' => 'field_student_id',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['field_student_id']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_student_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_student_id']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_student_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_student_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_student_id']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_student_id']['field_api_classes'] = 0;
  /* Field: Contact: Email address */
  $handler->display->display_options['fields']['field_contact_email']['id'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['table'] = 'field_data_field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['field'] = 'field_contact_email';
  $handler->display->display_options['fields']['field_contact_email']['label'] = 'Email';
  $handler->display->display_options['fields']['field_contact_email']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_contact_email']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_contact_email']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_contact_email']['element_class'] = 'easy-copy';
  $handler->display->display_options['fields']['field_contact_email']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_contact_email']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_contact_email']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_contact_email']['type'] = 'email_plain';
  $handler->display->display_options['fields']['field_contact_email']['field_api_classes'] = 0;

  /* Display: Student status */
  $handler = $view->new_display('block', 'Student status', 'block_2');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Contact: Status (field_student_status) */
  $handler->display->display_options['relationships']['field_student_status_tid']['id'] = 'field_student_status_tid';
  $handler->display->display_options['relationships']['field_student_status_tid']['table'] = 'field_data_field_student_status';
  $handler->display->display_options['relationships']['field_student_status_tid']['field'] = 'field_student_status_tid';
  $handler->display->display_options['relationships']['field_student_status_tid']['required'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Alert level */
  $handler->display->display_options['fields']['field_status_alert']['id'] = 'field_status_alert';
  $handler->display->display_options['fields']['field_status_alert']['table'] = 'field_data_field_status_alert';
  $handler->display->display_options['fields']['field_status_alert']['field'] = 'field_status_alert';
  $handler->display->display_options['fields']['field_status_alert']['relationship'] = 'field_student_status_tid';
  $handler->display->display_options['fields']['field_status_alert']['label'] = '';
  $handler->display->display_options['fields']['field_status_alert']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_status_alert']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_status_alert']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_status_alert']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_status_alert']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_status_alert']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_status_alert']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_status_alert']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_status_alert']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_status_alert']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_status_alert']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_status_alert']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_status_alert']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_status_alert']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_status_alert']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_status_alert']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_status_alert']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_status_alert']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_status_alert']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_status_alert']['field_api_classes'] = 0;
  /* Field: Contact: Status */
  $handler->display->display_options['fields']['field_student_status']['id'] = 'field_student_status';
  $handler->display->display_options['fields']['field_student_status']['table'] = 'field_data_field_student_status';
  $handler->display->display_options['fields']['field_student_status']['field'] = 'field_student_status';
  $handler->display->display_options['fields']['field_student_status']['label'] = '';
  $handler->display->display_options['fields']['field_student_status']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_student_status']['alter']['text'] = '<div class="student-status student-status-[field_status_alert]">[field_student_status]</div>';
  $handler->display->display_options['fields']['field_student_status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_student_status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_student_status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_student_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_student_status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_student_status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_student_status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_student_status']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_student_status']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_student_status']['field_api_classes'] = 0;
  $translatables['crm_contact_fields'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Tags'),
    t('All'),
    t('Student name'),
    t('Student fields'),
    t('Basic information'),
    t('Student ID'),
    t('Email'),
    t('Student status'),
    t('term from field_student_status'),
    t('<div class="student-status student-status-[field_status_alert]">[field_student_status]</div>'),
  );
  $export['crm_contact_fields'] = $view;

  $view = new view;
  $view->name = 'crm_user_contact_records';
  $view->description = 'Lists all contact records attached to a user.';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'CRM User Contact Records';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Contact Records';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'contact_id' => 'contact_id',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'type' => 'type',
  );
  $handler->display->display_options['row_options']['separator'] = ' - ';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No contact records found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_user_contact_target_id']['id'] = 'field_user_contact_target_id';
  $handler->display->display_options['relationships']['field_user_contact_target_id']['table'] = 'field_data_field_user_contact';
  $handler->display->display_options['relationships']['field_user_contact_target_id']['field'] = 'field_user_contact_target_id';
  $handler->display->display_options['relationships']['field_user_contact_target_id']['required'] = 0;
  /* Field: CRM Contact: Contact ID */
  $handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['table'] = 'crm_core_contact';
  $handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['relationship'] = 'field_user_contact_target_id';
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
  /* Field: Contact: Name */
  $handler->display->display_options['fields']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['fields']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['relationship'] = 'field_user_contact_target_id';
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
  $handler->display->display_options['fields']['contact_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contact_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['contact_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['contact_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['contact_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['contact_name']['click_sort_column'] = 'title';
  $handler->display->display_options['fields']['contact_name']['field_api_classes'] = 0;
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
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
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

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'User contact records';
  $translatables['crm_user_contact_records'] = array(
    t('Master'),
    t('Contact Records'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('No contact records found.'),
    t('Contact entity referenced from field_user_contact'),
    t('crm/contact/[contact_id]'),
    t('All'),
    t('Block'),
    t('User contact records'),
  );
  $export['crm_user_contact_records'] = $view;

  $view = new view;
  $view->name = 'search_contacts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'crm_core_contact';
  $view->human_name = 'Search students';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search Students';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'contact_id' => 'contact_id',
    'field_first_name' => 'field_first_name',
    'contact_image' => 'contact_image',
    'field_last_name' => 'field_last_name',
    'field_student_status' => 'field_student_status',
    'field_student_id' => 'field_student_id',
    'field_student_degrees' => 'field_student_degrees',
  );
  $handler->display->display_options['style_options']['default'] = 'field_last_name';
  $handler->display->display_options['style_options']['info'] = array(
    'contact_id' => array(
      'sortable' => 0,
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
    'contact_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_student_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_student_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_student_degrees' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'No students found.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Field: CRM Contact: Contact ID */
  $handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['table'] = 'crm_core_contact';
  $handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
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
  $handler->display->display_options['fields']['contact_id']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['contact_id']['link_to_contact'] = 0;
  /* Field: Contact: Name */
  $handler->display->display_options['fields']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['fields']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name']['label'] = 'Last Name';
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
  $handler->display->display_options['fields']['contact_name']['type'] = 'name_default_family';
  $handler->display->display_options['fields']['contact_name']['field_api_classes'] = 0;
  /* Field: Contact: Name */
  $handler->display->display_options['fields']['contact_name_1']['id'] = 'contact_name_1';
  $handler->display->display_options['fields']['contact_name_1']['table'] = 'field_data_contact_name';
  $handler->display->display_options['fields']['contact_name_1']['field'] = 'contact_name';
  $handler->display->display_options['fields']['contact_name_1']['label'] = 'First name';
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
  $handler->display->display_options['fields']['contact_name_1']['type'] = 'name_default_given';
  $handler->display->display_options['fields']['contact_name_1']['field_api_classes'] = 0;
  /* Field: Contact: Image */
  $handler->display->display_options['fields']['contact_image']['id'] = 'contact_image';
  $handler->display->display_options['fields']['contact_image']['table'] = 'field_data_contact_image';
  $handler->display->display_options['fields']['contact_image']['field'] = 'contact_image';
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
  $handler->display->display_options['fields']['contact_image']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['contact_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['contact_image']['settings'] = array(
    'image_style' => 'contact_small',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['contact_image']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['field_student_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_student_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_student_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_student_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_student_id']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_student_id']['field_api_classes'] = 0;
  /* Field: Contact: Status */
  $handler->display->display_options['fields']['field_student_status']['id'] = 'field_student_status';
  $handler->display->display_options['fields']['field_student_status']['table'] = 'field_data_field_student_status';
  $handler->display->display_options['fields']['field_student_status']['field'] = 'field_student_status';
  $handler->display->display_options['fields']['field_student_status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_student_status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_student_status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_student_status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_student_status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_student_status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_student_status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_student_status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_student_status']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_student_status']['field_api_classes'] = 0;
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
  /* Filter criterion: CRM Contact: Contact Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'crm_core_contact';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = 'Student';
  /* Filter criterion: Contact: Degrees (field_student_degrees) */
  $handler->display->display_options['filters']['field_student_degrees_tid']['id'] = 'field_student_degrees_tid';
  $handler->display->display_options['filters']['field_student_degrees_tid']['table'] = 'field_data_field_student_degrees';
  $handler->display->display_options['filters']['field_student_degrees_tid']['field'] = 'field_student_degrees_tid';
  $handler->display->display_options['filters']['field_student_degrees_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_student_degrees_tid']['expose']['operator_id'] = 'field_student_degrees_tid_op';
  $handler->display->display_options['filters']['field_student_degrees_tid']['expose']['label'] = 'Degree';
  $handler->display->display_options['filters']['field_student_degrees_tid']['expose']['operator'] = 'field_student_degrees_tid_op';
  $handler->display->display_options['filters']['field_student_degrees_tid']['expose']['identifier'] = 'field_student_degrees_tid';
  $handler->display->display_options['filters']['field_student_degrees_tid']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_student_degrees_tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_student_degrees_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_student_degrees_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_student_degrees_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_student_degrees_tid']['vocabulary'] = 'degrees';
  $handler->display->display_options['filters']['field_student_degrees_tid']['error_message'] = 1;
  /* Filter criterion: Contact: Status (field_student_status) */
  $handler->display->display_options['filters']['field_student_status_tid']['id'] = 'field_student_status_tid';
  $handler->display->display_options['filters']['field_student_status_tid']['table'] = 'field_data_field_student_status';
  $handler->display->display_options['filters']['field_student_status_tid']['field'] = 'field_student_status_tid';
  $handler->display->display_options['filters']['field_student_status_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_student_status_tid']['expose']['operator_id'] = 'field_student_status_tid_op';
  $handler->display->display_options['filters']['field_student_status_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_student_status_tid']['expose']['operator'] = 'field_student_status_tid_op';
  $handler->display->display_options['filters']['field_student_status_tid']['expose']['identifier'] = 'field_student_status_tid';
  $handler->display->display_options['filters']['field_student_status_tid']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_student_status_tid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_student_status_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_student_status_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_student_status_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_student_status_tid']['vocabulary'] = 'student_status';
  $handler->display->display_options['filters']['field_student_status_tid']['error_message'] = 1;
  /* Filter criterion: Contact: Name */
  $handler->display->display_options['filters']['contact_name']['id'] = 'contact_name';
  $handler->display->display_options['filters']['contact_name']['table'] = 'field_data_contact_name';
  $handler->display->display_options['filters']['contact_name']['field'] = 'contact_name';
  $handler->display->display_options['filters']['contact_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['contact_name']['expose']['operator_id'] = 'contact_name_op';
  $handler->display->display_options['filters']['contact_name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['contact_name']['expose']['operator'] = 'contact_name_op';
  $handler->display->display_options['filters']['contact_name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['contact_name']['expose']['multiple'] = FALSE;

  /* Display: Search page */
  $handler = $view->new_display('page', 'Search page', 'page');
  $handler->display->display_options['path'] = 'crm/search';
  $translatables['search_contacts'] = array(
    t('Master'),
    t('Search Students'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('No students found.'),
    t('Last Name'),
    t('crm/contact/[contact_id]'),
    t('First name'),
    t('Student ID'),
    t('Status'),
    t('Level'),
    t('Degrees'),
    t('Degree'),
    t('Name'),
    t('Search page'),
  );
  $export['search_contacts'] = $view;

  return $export;
}
