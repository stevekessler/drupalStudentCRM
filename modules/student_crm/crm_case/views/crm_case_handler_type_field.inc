<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 */


class crm_case_handler_type_field extends crm_case_handler_link_field {
  function construct() {
    parent::construct();
    $this->additional_fields['type'] = 'type';
  }


  function render($values) {
    $type = crm_case_get_types($values->crm_case_type);
    return $type->label;
  }
}
