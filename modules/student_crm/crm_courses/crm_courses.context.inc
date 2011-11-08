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
