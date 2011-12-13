<?php
/**
 * @file
 * crm_advisor.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function crm_advisor_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-crm-navigation:students/advisees
  $menu_links['menu-crm-navigation:students/advisees'] = array(
    'menu_name' => 'menu-crm-navigation',
    'link_path' => 'students/advisees',
    'router_path' => 'students/advisees',
    'link_title' => 'Advisees',
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
    'weight' => '-47',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Advisees');


  return $menu_links;
}
