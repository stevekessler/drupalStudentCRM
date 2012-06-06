<?php

/**
 * @file
 * Access callback to tell if a user can view the current case in a view.
 */
class crm_case_handler_access extends views_handler_filter_boolean_operator {
  function query() {
    if (!user_access('administer crm_cases')) {
      global $user;
      $permissions = user_role_permissions($user->roles);
      $types = array();
      foreach ($permissions as $rid => $perms) {
        foreach ($perms as $name => $access) {
          if ($access && preg_match('/view any [^ ]+ crm_case/', $name)) {
            $types[] = preg_replace('/view any ([^ ]+) crm_case/', '\\1', $name);
          }
        }
      }
      $alias = $this->query->tables['crm_case']['crm_case']['alias'];
      $this->query->add_where($this->options['group'], "$alias.type", $types, 'IN');
    }
  }
}