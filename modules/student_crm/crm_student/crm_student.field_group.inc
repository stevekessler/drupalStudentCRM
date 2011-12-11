<?php
/**
 * @file
 * crm_student.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function crm_student_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|crm_core_contact|student|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'crm_core_contact';
  $field_group->bundle = 'student';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact information',
    'weight' => '10',
    'children' => array(
      0 => 'field_contact_email',
      1 => 'field_contact_phone',
      2 => 'field_contact_address',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_contact|crm_core_contact|student|form'] = $field_group;

  return $export;
}
