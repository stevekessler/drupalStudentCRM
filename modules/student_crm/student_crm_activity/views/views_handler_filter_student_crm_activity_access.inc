<?php

class views_handler_filter_student_crm_activity_access extends views_handler_filter_boolean_operator {
  function query() {
    if (!user_access('administer crm activities')) {
      global $user;
      $permissions = user_role_permissions($user->roles);
      $types = array();
      foreach($permissions as $rid => $perms) {
        foreach($perms as $name => $access) {
          if($access && preg_match('/view any [^ ]+ crm_activity/', $name)) {
            $types[] = preg_replace('/view any ([^ ]+) crm_activity/', '\\1', $name);
          }
        }
      }
      $alias = $this->query->tables['crm_activity']['crm_activity']['alias'];
      $this->query->add_where($this->options['group'], "$alias.type", $types, 'IN');
    }
  }
}