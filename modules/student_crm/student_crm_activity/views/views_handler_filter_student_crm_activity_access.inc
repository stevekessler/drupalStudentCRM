<?php

/**
 * @file
 * Views access plugin to make sure that a user can view an activity attached to a case or contact.
 */
class views_handler_filter_student_crm_activity_access extends views_handler_filter_boolean_operator {
  function query() {
    if (!user_access('administer crm activities') && !user_access('view any crm_core_activity entity')) {
      global $user;
      $permissions = user_role_permissions($user->roles);
      $types = array();
      foreach ($permissions as $rid => $perms) {
        foreach ($perms as $name => $access) {
          if ($access && preg_match('/view any crm_core_activity entity of bundle [^ ]+/', $name)) {
            $types[] = preg_replace('/view any crm_core_activity entity of bundle ([^ ]+)/', '\\1', $name);
          }
        }
      }
      $alias = $this->query->tables['crm_core_activity']['crm_core_activity']['alias'];
      $this->query->add_where($this->options['group'], "$alias.type", $types, 'IN');
    }
  }
}