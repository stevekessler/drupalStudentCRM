<?php
/**
 * @file
 * crm_student.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function crm_student_user_default_permissions() {
  $permissions = array();

  // Exported permission: access content
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      0 => 'advisor',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: access student_crm dashboard
  $permissions['access student_crm dashboard'] = array(
    'name' => 'access student_crm dashboard',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'crm_student',
  );

  // Exported permission: access user profiles
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'user',
  );

  // Exported permission: administer features
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(),
  );

  // Exported permission: administer feeds
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(),
  );

  // Exported permission: administer relation types
  $permissions['administer relation types'] = array(
    'name' => 'administer relation types',
    'roles' => array(),
  );

  // Exported permission: administer taxonomy
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(),
  );

  // Exported permission: administer users
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(),
  );

  // Exported permission: advise students
  $permissions['advise students'] = array(
    'name' => 'advise students',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'crm_advisor',
  );

  // Exported permission: bypass node access
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(),
  );

  // Exported permission: complete crm webforms
  $permissions['complete crm webforms'] = array(
    'name' => 'complete crm webforms',
    'roles' => array(
      0 => 'advisor',
      1 => 'anonymous user',
    ),
    'module' => 'student_crm_webform',
  );

  // Exported permission: create relations
  $permissions['create relations'] = array(
    'name' => 'create relations',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'relation',
  );

  // Exported permission: create tasks for other users
  $permissions['create tasks for other users'] = array(
    'name' => 'create tasks for other users',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'crm_tasks',
  );

  // Exported permission: create webform content
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any webform content
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own webform content
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(),
  );

  // Exported permission: delete relations
  $permissions['delete relations'] = array(
    'name' => 'delete relations',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'relation',
  );

  // Exported permission: edit any webform content
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own webform content
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(),
  );

  // Exported permission: edit relations
  $permissions['edit relations'] = array(
    'name' => 'edit relations',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'relation',
  );

  // Exported permission: export relation types
  $permissions['export relation types'] = array(
    'name' => 'export relation types',
    'roles' => array(),
  );

  // Exported permission: manage features
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(),
  );

  // Exported permission: open and close cases
  $permissions['open and close cases'] = array(
    'name' => 'open and close cases',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'crm_case',
  );

  // Exported permission: show format tips
  $permissions['show format tips'] = array(
    'name' => 'show format tips',
    'roles' => array(),
  );

  // Exported permission: show more format tips link
  $permissions['show more format tips link'] = array(
    'name' => 'show more format tips link',
    'roles' => array(),
  );

  // Exported permission: track user history
  $permissions['track user history'] = array(
    'name' => 'track user history',
    'roles' => array(
      0 => 'advisor',
    ),
    'module' => 'crm_history',
  );

  // Exported permission: use text format filtered_html
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      0 => 'advisor',
      1 => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format full_html
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(),
  );

  return $permissions;
}
