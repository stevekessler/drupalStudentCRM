<?php
/**
 * @file
 * crm_tasks.relation_type_default.inc
 */

/**
 * Implements hook_relation_default_relation_types().
 */
function crm_tasks_relation_default_relation_types() {
  $export = array();

  $relation_type = new stdClass;
  $relation_type->disabled = FALSE; /* Edit this to true to make a default relation_type disabled initially */
  $relation_type->api_version = 1;
  $relation_type->relation_type = 'crm_task';
  $relation_type->label = 'CRM Task';
  $relation_type->reverse_label = 'CRM Task';
  $relation_type->directional = 0;
  $relation_type->transitive = 0;
  $relation_type->r_unique = 0;
  $relation_type->min_arity = 2;
  $relation_type->max_arity = 2;
  $relation_type->source_bundles = array(
    0 => 'crm_contact:*',
    1 => 'crm_activity:*',
    2 => 'crm_case:*',
    3 => 'node:course',
    4 => 'user:*',
  );
  $relation_type->target_bundles = array();
  $export['crm_task'] = $relation_type;

  return $export;
}