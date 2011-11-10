<?php
/**
 * @file
 * crm_tasks.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function crm_tasks_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "relation" && $api == "relation_type_default") {
    return array("version" => "1");
  }
}
