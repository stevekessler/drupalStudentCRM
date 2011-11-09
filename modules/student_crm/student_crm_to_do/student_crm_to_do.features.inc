<?php
/**
 * @file
 * student_crm_to_do.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function student_crm_to_do_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "relation" && $api == "relation_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "relation" && $api == "relation_type_default") {
    return array("version" => "1");
  }
}
