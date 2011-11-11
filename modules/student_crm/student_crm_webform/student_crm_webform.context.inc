<?php
/**
 * @file
 * student_crm_webform.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function student_crm_webform_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'case_page_forms';
  $context->description = 'User is on the case page';
  $context->tag = 'cases';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'crm/case/*' => 'crm/case/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-form_submissions-block' => array(
          'module' => 'views',
          'delta' => 'form_submissions-block',
          'region' => 'sidebar_right',
          'weight' => '-19',
        ),
        'student_crm_webform-student_crm_webform_send_form' => array(
          'module' => 'student_crm_webform',
          'delta' => 'student_crm_webform_send_form',
          'region' => 'sidebar_right',
          'weight' => '-18',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on the case page');
  t('cases');
  $export['case_page_forms'] = $context;

  return $export;
}
