<?php
/**
 * @file
 * student_crm_basket.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function student_crm_basket_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function student_crm_basket_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function student_crm_basket_node_info() {
  $items = array(
    'basket' => array(
      'name' => t('Basket'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Basket name'),
      'help' => '',
    ),
  );
  return $items;
}
