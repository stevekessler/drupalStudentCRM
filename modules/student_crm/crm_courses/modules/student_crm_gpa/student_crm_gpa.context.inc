<?php
/**
 * @file
 * student_crm_gpa.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function student_crm_gpa_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crm_student_gpa';
  $context->description = 'Display most recent GPA data on a student\'s page';
  $context->tag = 'student';
  $context->conditions = array(
    'crm_core_contact_context_condition_contact_type' => array(
      'values' => array(
        'student' => 'student',
      ),
      'options' => array(
        'contact_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-student_crm_gpa-block_1' => array(
          'module' => 'views',
          'delta' => 'student_crm_gpa-block_1',
          'region' => 'sidebar_right',
          'weight' => '-13',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Display most recent GPA data on a student\'s page');
  t('student');
  $export['crm_student_gpa'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crm_student_gpa_page';
  $context->description = 'User is on the GPA history page';
  $context->tag = 'crm';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'student_crm_gpa:page' => 'student_crm_gpa:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'student_crm_gpa-student_crm_gpa_graph' => array(
          'module' => 'student_crm_gpa',
          'delta' => 'student_crm_gpa_graph',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on the GPA history page');
  t('crm');
  $export['crm_student_gpa_page'] = $context;

  return $export;
}
