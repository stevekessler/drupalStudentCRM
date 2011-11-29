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

  

  return $permissions;
}
