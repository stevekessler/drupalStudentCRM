<?php
/**
 * @file
 * crm_case_print.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function crm_case_print_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'student_crm_case_print_block';
  $context->description = 'Adds the print button to cases';
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
        'crm_case_print-crm_case_print_link' => array(
          'module' => 'crm_case_print',
          'delta' => 'crm_case_print_link',
          'region' => 'page_tools',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds the print button to cases');
  t('cases');
  $export['student_crm_case_print_block'] = $context;

  return $export;
}
