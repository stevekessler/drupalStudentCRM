<?php
/**
 * @file
 * student_crm_demo.features.inc
 */

/**
 * Implements hook_default_crm_case_type().
 */
function student_crm_demo_default_crm_case_type() {
  $items = array();
  $items['simple_case'] = entity_import('crm_case_type', '{
    "type" : "simple_case",
    "label" : "Simple case",
    "weight" : "0",
    "data" : "",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function student_crm_demo_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}
