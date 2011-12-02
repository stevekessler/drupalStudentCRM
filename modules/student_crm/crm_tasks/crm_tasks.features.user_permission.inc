<?php
/**
 * @file
 * crm_tasks.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function crm_tasks_user_default_permissions() {
  $permissions = array();

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
