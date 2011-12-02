<?php
/**
 * @file
 * crm_advisor.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function crm_advisor_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crm_advisor_student_page';
  $context->description = 'Advisor tools while viewing a student contact page';
  $context->tag = 'crm advisor';
  $context->conditions = array(
    'crm_context_condition_contact_type' => array(
      'values' => array(
        'student' => 'student',
      ),
      'options' => array(
        'contact_form' => '0',
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
        'crm_advisor-crm_advisor_select_advisor' => array(
          'module' => 'crm_advisor',
          'delta' => 'crm_advisor_select_advisor',
          'region' => 'page_tools',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Advisor tools while viewing a student contact page');
  t('crm advisor');
  $export['crm_advisor_student_page'] = $context;

  return $export;
}
