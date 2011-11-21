<?php
/**
 * @file
 * student_crm_activity_mailer.features.inc
 */

/**
 * Implements hook_default_crm_activity_type().
 */
function student_crm_activity_mailer_default_crm_activity_type() {
  $items = array();
  $items['email_activity'] = entity_import('crm_activity_type', '{
    "type" : "email_activity",
    "label" : "Email activity",
    "weight" : "0",
    "data" : "",
    "rdf_mapping" : []
  }');
  return $items;
}
