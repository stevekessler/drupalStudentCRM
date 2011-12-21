<?php

if(!function_exists('profiler_v2')) {
  require_once('libraries/profiler/profiler.inc');
}

profiler_v2('student_crm');

/**
 * Implements hook_install_tasks().
 */
function student_crm_install_tasks() {
  return array('student_crm_final_setup' => array(),
    );
}

/**
 * Final site setup for the install profile.
 */
function student_crm_final_setup() {
  //Give the super admin user the "advisor" role to make contexts happy.
  $user = user_load(1);
  foreach(user_roles() as $rid => $role) {
    if($role == 'advisor') {
      $user->roles[$rid] = $role;
    }
  }
  user_save($user);
}