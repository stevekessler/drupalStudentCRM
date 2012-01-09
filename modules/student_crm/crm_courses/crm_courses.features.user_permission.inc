<?php
/**
 * @file
 * crm_courses.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function crm_courses_user_default_permissions() {
  $permissions = array();

  // Exported permission: access course enrollment information
  $permissions['access course enrollment information'] = array(
    'name' => 'access course enrollment information',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'crm_courses',
  );

  return $permissions;
}
