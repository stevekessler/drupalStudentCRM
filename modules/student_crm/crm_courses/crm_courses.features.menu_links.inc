<?php
/**
 * @file
 * crm_courses.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function crm_courses_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-crm-navigation:crm/courses
  $menu_links['menu-crm-navigation:crm/courses'] = array(
    'menu_name' => 'menu-crm-navigation',
    'link_path' => 'crm/courses',
    'router_path' => 'crm/courses',
    'link_title' => 'Courses',
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
  t('Courses');


  return $menu_links;
}
