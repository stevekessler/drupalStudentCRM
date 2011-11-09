<?php
/**
 * @file
 * crm_courses.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function crm_courses_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crm_courses_contact';
  $context->description = 'User is viewing a student with course enrollments';
  $context->tag = 'crm_coures';
  $context->conditions = array(
    'crm_context_condition_contact_type' => array(
      'values' => array(
        'student' => 'student',
      ),
      'options' => array(
        'contact_form' => '1',
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
        'views-crm_course_students-block_1' => array(
          'module' => 'views',
          'delta' => 'crm_course_students-block_1',
          'region' => 'sidebar_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is viewing a student with course enrollments');
  t('crm_coures');
  $export['crm_courses_contact'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crm_courses_course';
  $context->description = 'User is on a course page.';
  $context->tag = 'crm_courses';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'course' => 'course',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-crm_course_students-block' => array(
          'module' => 'views',
          'delta' => 'crm_course_students-block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
    'menu' => 'crm/courses',
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on a course page.');
  t('crm_courses');
  $export['crm_courses_course'] = $context;

  return $export;
}
