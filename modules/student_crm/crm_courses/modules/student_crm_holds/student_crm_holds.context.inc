<?php
/**
 * @file
 * student_crm_holds.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function student_crm_holds_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crm_holds_student_page';
  $context->description = 'User is viewing a student page';
  $context->tag = 'student_crm_holds';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'crm/contact/*' => 'crm/contact/*',
      ),
    ),
    'user' => array(
      'values' => array(
        'advisor' => 'advisor',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-crm_student_holds-block_1' => array(
          'module' => 'views',
          'delta' => 'crm_student_holds-block_1',
          'region' => 'content_top_wide',
          'weight' => '27',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is viewing a student page');
  t('student_crm_holds');
  $export['crm_holds_student_page'] = $context;

  return $export;
}
