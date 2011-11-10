<?php
/**
 * @file
 * crm_tasks.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function crm_tasks_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crm_tasks_block';
  $context->description = 'User is on a CRM page where a user can create a task.';
  $context->tag = 'crm_tasks';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'course' => 'course',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'crm/case/*' => 'crm/case/*',
        'crm/contact/*' => 'crm/contact/*',
        'crm/activity/*' => 'crm/activity/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'crm_tasks-crm_tasks_new_task' => array(
          'module' => 'crm_tasks',
          'delta' => 'crm_tasks_new_task',
          'region' => 'sidebar_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on a CRM page where a user can create a task.');
  t('crm_tasks');
  $export['crm_tasks_block'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crm_tasks_frontpage';
  $context->description = 'User is on a frontpage and should see their tasks.';
  $context->tag = 'crm_tasks';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
        'crm/home' => 'crm/home',
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-crm_tasks-block_1' => array(
          'module' => 'views',
          'delta' => 'crm_tasks-block_1',
          'region' => 'sidebar_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on a frontpage and should see their tasks.');
  t('crm_tasks');
  $export['crm_tasks_frontpage'] = $context;

  return $export;
}
