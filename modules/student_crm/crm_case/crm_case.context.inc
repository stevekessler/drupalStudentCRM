<?php
/**
 * @file
 * crm_case.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function crm_case_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'case_page';
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
    'menu' => 'crm/search',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on the case page');
  t('cases');
  $export['case_page'] = $context;

  return $export;
}
