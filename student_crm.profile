<?php

if(!function_exists('profiler_v2')) {
  require_once('libraries/profiler/profiler.inc');
}

profiler_v2('student_crm');

/**
 * Implements hook_install_tasks().
 */
function student_crm_install_tasks_alter(&$tasks, $install_state) {
  return array('student_crm_final_setup' => array(),
    );
}

/**
 * Final site setup for the install profile.
 */
function student_crm_final_setup(&$install_state) {
  //Call the profiler profile complete function first
  profiler_install_profile_complete(&$install_state);
  //Give the super admin user the "advisor" role to make contexts happy.
  $user = user_load(1);
  foreach (user_roles() as $rid => $role) {
    if ($role == 'advisor') {
      $user->roles[$rid] = $role;
    }
  }
  user_save($user);
  
  $advisor = db_select('role', 'r')
             ->fields('r', array('rid'))
             ->condition('name', 'advisor')
             ->execute()
             ->fetchField();
  
  $unchecked_permissions = array('view any crm_core_contact entity of bundle student',
                                 'maintain own task list');
  if($advisor) {
    foreach($unchecked_permissions as $permission) {
      $fields = array('rid' => $advisor, 
                       'permission' => $permission,
                       'module' => 'crm_student');
      db_insert('role_permission')
        ->fields($fields)
        ->execute();
    }
  }
}