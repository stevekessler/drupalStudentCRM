<?php
/**
 * @file
 * crm_student.relation_type_default.inc
 */

/**
 * Implements hook_relation_default_relation_types().
 */
function crm_student_relation_default_relation_types() {
  $export = array();

  $relation_type = new stdClass;
  $relation_type->disabled = FALSE; /* Edit this to true to make a default relation_type disabled initially */
  $relation_type->api_version = 1;
  $relation_type->relation_type = 'user_contact_record';
  $relation_type->label = 'User contact record';
  $relation_type->reverse_label = 'User contact record';
  $relation_type->directional = 0;
  $relation_type->transitive = 0;
  $relation_type->r_unique = 0;
  $relation_type->min_arity = 2;
  $relation_type->max_arity = 2;
  $relation_type->source_bundles = array(
    0 => 'crm_core_contact:*',
    1 => 'user:*',
  );
  $relation_type->target_bundles = array();
  $export['user_contact_record'] = $relation_type;

  return $export;
}
