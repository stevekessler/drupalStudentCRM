<?php
/**
 * @file
 * crm_case.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function crm_case_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-crm-navigation:crm/cases
  $menu_links['menu-crm-navigation:crm/cases'] = array(
    'menu_name' => 'menu-crm-navigation',
    'link_path' => 'crm/cases',
    'router_path' => 'crm/cases',
    'link_title' => 'Cases',
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
    'weight' => '-48',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Cases');


  return $menu_links;
}
