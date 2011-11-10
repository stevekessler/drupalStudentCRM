<?php
/**
 * @file
 * crm_tasks.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function crm_tasks_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-crm-navigation:crm/tasks
  $menu_links['menu-crm-navigation:crm/tasks'] = array(
    'menu_name' => 'menu-crm-navigation',
    'link_path' => 'crm/tasks',
    'router_path' => 'crm',
    'link_title' => 'Tasks',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Tasks');


  return $menu_links;
}
