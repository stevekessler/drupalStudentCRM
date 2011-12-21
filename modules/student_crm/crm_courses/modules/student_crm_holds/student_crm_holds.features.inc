<?php
/**
 * @file
 * student_crm_holds.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function student_crm_holds_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "relation" && $api == "relation_type_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function student_crm_holds_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function student_crm_holds_node_info() {
  $items = array(
    'hold_type' => array(
      'name' => t('Hold type'),
      'base' => 'node_content',
      'description' => t('A hold type is a description of a type of hold. These are only to describe the hold, including name and description, and is later related to a contact via a relation entity.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
