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

/**
 * Implements hook_ctools_plugin_api().
 */
function student_crm_activity_mailer_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}
