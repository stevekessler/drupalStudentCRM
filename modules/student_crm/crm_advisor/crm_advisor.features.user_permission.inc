<?php
/**
 * @file
 * crm_advisor.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function crm_advisor_user_default_permissions() {
  $permissions = array();

  // Exported permission: access crm dashboard
  $permissions['access crm dashboard'] = array(
    'name' => 'access crm dashboard',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'crm_student',
  );

  // Exported permission: maintain own task list
  $permissions['maintain own task list'] = array(
    'name' => 'maintain own task list',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'crm_tasks',
  );

  return $permissions;
}
