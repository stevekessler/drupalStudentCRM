<?php
/**
 * @file
 * student_crm_activity.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function student_crm_activity_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'activity_form';
  $context->description = 'User is on an entity that tracks activities.';
  $context->tag = 'activities';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'crm/case/*' => 'crm/case/*',
        'crm/contact/*' => 'crm/contact/*',
        '~crm/contact/*/*' => '~crm/contact/*/*',
        '~*/edit' => '~*/edit',
        '~*/delete' => '~*/delete',
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
        'student_crm_activity-student_crm_activity_create' => array(
          'module' => 'student_crm_activity',
          'delta' => 'student_crm_activity_create',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on an entity that tracks activities.');
  t('activities');
  $export['activity_form'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crm_activity_list';
  $context->description = 'Activity list for contacts';
  $context->tag = 'activities';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'crm/contact/*' => 'crm/contact/*',
        '~crm/contact/*/*' => '~crm/contact/*/*',
        '~*/edit' => '~*/edit',
        '~*/delete' => '~*/delete',
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
        'views-crm_activities-block' => array(
          'module' => 'views',
          'delta' => 'crm_activities-block',
          'region' => 'content_bottom',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Activity list for contacts');
  t('activities');
  $export['crm_activity_list'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crm_case_activity_list';
  $context->description = 'Activity list for cases';
  $context->tag = 'activities';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'crm/case/*' => 'crm/case/*',
        '~*/edit' => '~*/edit',
        '~*/delete' => '~*/delete',
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
        'views-crm_activities-block_1' => array(
          'module' => 'views',
          'delta' => 'crm_activities-block_1',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Activity list for cases');
  t('activities');
  $export['crm_case_activity_list'] = $context;

  return $export;
}
