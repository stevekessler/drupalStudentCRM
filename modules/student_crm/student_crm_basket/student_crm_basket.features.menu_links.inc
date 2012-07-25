<?php
/**
 * @file
 * student_crm_basket.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function student_crm_basket_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-crm-navigation:crm/baskets
  $menu_links['menu-crm-navigation:crm/baskets'] = array(
    'menu_name' => 'menu-crm-navigation',
    'link_path' => 'crm/baskets',
    'router_path' => 'crm/baskets',
    'link_title' => 'Baskets',
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
    'weight' => '-46',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Baskets');


  return $menu_links;
}
