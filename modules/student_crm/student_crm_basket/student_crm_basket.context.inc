<?php
/**
 * @file
 * student_crm_basket.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function student_crm_basket_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crm_basket';
  $context->description = 'User is on a CRM page where a user can add the page to a basket.';
  $context->tag = 'crm_basket';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'crm/case/*' => 'crm/case/*',
        'crm/contact/*' => 'crm/contact/*',
        '~crm/contact/*/*' => '~crm/contact/*/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'student_crm_basket-add_item' => array(
          'module' => 'student_crm_basket',
          'delta' => 'add_item',
          'region' => 'page_tools',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on a CRM page where a user can add the page to a basket.');
  t('crm_basket');
  $export['crm_basket'] = $context;

  return $export;
}
