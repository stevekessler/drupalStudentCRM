<?php
/**
 * @file
 * student_crm_gpa.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function student_crm_gpa_user_default_permissions() {
  $permissions = array();

  // Exported permission: view gpa data
  $permissions['view gpa data'] = array(
    'name' => 'view gpa data',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'student_crm_gpa',
  );

  return $permissions;
}
