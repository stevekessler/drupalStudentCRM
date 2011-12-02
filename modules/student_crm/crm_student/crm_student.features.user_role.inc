<?php
/**
 * @file
 * crm_student.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function crm_student_user_default_roles() {
  $roles = array();

  // Exported role: advisor
  $roles['advisor'] = array(
    'name' => 'advisor',
    'weight' => '2',
  );

  return $roles;
}
