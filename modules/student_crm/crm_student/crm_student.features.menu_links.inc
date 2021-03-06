<?php
/**
 * @file
 * crm_student.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function crm_student_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-crm-navigation:crm/search
  $menu_links['menu-crm-navigation:crm/search'] = array(
    'menu_name' => 'menu-crm-navigation',
    'link_path' => 'crm/search',
    'router_path' => 'crm/search',
    'link_title' => 'Students',
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
    'weight' => '-49',
  );
  // Exported menu link: menu-crm-navigation:dashboard
  $menu_links['menu-crm-navigation:dashboard'] = array(
    'menu_name' => 'menu-crm-navigation',
    'link_path' => 'dashboard',
    'router_path' => 'dashboard',
    'link_title' => 'Dashboard',
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
    'weight' => '-50',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Dashboard');
  t('Students');


  return $menu_links;
}
