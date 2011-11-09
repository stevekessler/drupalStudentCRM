<?php
/**
 * @file
 * student_crm_to_do.relation_default.inc
 */

/**
 * Implements hook_relation_default_relation_types().
 */
function student_crm_to_do_relation_default_relation_types() {
  $export = array();

  $relation_type = new stdClass;
  $relation_type->disabled = FALSE; /* Edit this to true to make a default relation_type disabled initially */
  $relation_type->api_version = 1;
  $relation_type->relation_type = 'to_do_item';
  $relation_type->label = 'To-do item';
  $relation_type->reverse_label = 'To-do target';
  $relation_type->directional = 1;
  $relation_type->transitive = 0;
  $relation_type->r_unique = 0;
  $relation_type->min_arity = 2;
  $relation_type->max_arity = 2;
  $export['to_do_item'] = $relation_type;

  return $export;
}
