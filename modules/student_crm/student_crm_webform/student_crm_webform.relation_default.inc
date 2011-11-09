<?php
/**
 * @file
 * student_crm_webform.relation_default.inc
 */

/**
 * Implements hook_relation_default_relation_types().
 */
function student_crm_webform_relation_default_relation_types() {
  $export = array();

  $relation_type = new stdClass;
  $relation_type->disabled = FALSE; /* Edit this to true to make a default relation_type disabled initially */
  $relation_type->api_version = 1;
  $relation_type->relation_type = 'case_webform';
  $relation_type->label = 'Case Webform Relationshiop';
  $relation_type->reverse_label = 'Webform for case';
  $relation_type->directional = 1;
  $relation_type->transitive = 0;
  $relation_type->r_unique = 0;
  $relation_type->min_arity = 2;
  $relation_type->max_arity = 2;
  $export['case_webform'] = $relation_type;

  $relation_type = new stdClass;
  $relation_type->disabled = FALSE; /* Edit this to true to make a default relation_type disabled initially */
  $relation_type->api_version = 1;
  $relation_type->relation_type = 'webform_submission_to_entities';
  $relation_type->label = 'Webform submission to entities';
  $relation_type->reverse_label = '';
  $relation_type->directional = 1;
  $relation_type->transitive = 0;
  $relation_type->r_unique = 0;
  $relation_type->min_arity = 2;
  $relation_type->max_arity = 2;
  $export['webform_submission_to_entities'] = $relation_type;

  return $export;
}
