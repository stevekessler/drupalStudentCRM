<?php

/**
 * @file
 * Access callback to tell if a user can edit their own case.
 */
class crm_case_handler_contact_access extends views_handler_filter_boolean_operator {
  function query() {
    $types = array();
    foreach (crm_case_get_types() as $type) {
      if ($type->data['contact_edit']) {
        $types[] = $type->type;
      }
    }
    $alias = $this->query->tables['crm_case']['crm_case']['alias'];
    $this->query->add_where($this->options['group'], "$alias.type", $types, 'IN');
  }
}