<?php
/**
 * @file
 * crm_case_print.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function crm_case_print_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
