<?php
/**
 * @file
 * student_crm_webform.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function student_crm_webform_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "relation" && $api == "relation_default") {
    return array("version" => "1");
  }
}
