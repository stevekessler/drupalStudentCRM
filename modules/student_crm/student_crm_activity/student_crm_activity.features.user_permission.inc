<?php
/**
 * @file
 * student_crm_activity.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function student_crm_activity_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer crm activities
  $permissions['administer crm activities'] = array(
    'name' => 'administer crm activities',
    'roles' => array(),
  );

  // Exported permission: administer crm_activity types
  $permissions['administer crm_activity types'] = array(
    'name' => 'administer crm_activity types',
    'roles' => array(),
  );

  // Exported permission: edit any note crm_activity
  $permissions['edit any note crm_activity'] = array(
    'name' => 'edit any note crm_activity',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'crm_activity',
  );

  // Exported permission: view any note crm_activity
  $permissions['view any note crm_activity'] = array(
    'name' => 'view any note crm_activity',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'crm_activity',
  );

  return $permissions;
}
