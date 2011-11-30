<?php
/**
 * @file
 * crm_case.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function crm_case_field_default_fields() {
  $fields = array();

  // Exported field: 'relation-crm_case_activity-endpoints'
  $fields['relation-crm_case_activity-endpoints'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'endpoints',
      'foreign keys' => array(),
      'indexes' => array(
        'relation' => array(
          0 => 'entity_type',
          1 => 'entity_id',
          2 => 'r_index',
        ),
      ),
      'module' => 'relation_endpoint',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'relation_endpoint',
    ),
    'field_instance' => array(
      'bundle' => 'crm_case_activity',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'relation_endpoint',
          'settings' => array(),
          'type' => 'relation_endpoint',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'relation',
      'field_name' => 'endpoints',
      'label' => 'endpoints',
      'required' => FALSE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'relation_endpoint',
        'settings' => array(),
        'type' => 'relation_endpoint',
        'weight' => 0,
      ),
    ),
  );

  // Exported field: 'relation-crm_contact_case-endpoints'
  $fields['relation-crm_contact_case-endpoints'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'endpoints',
      'foreign keys' => array(),
      'indexes' => array(
        'relation' => array(
          0 => 'entity_type',
          1 => 'entity_id',
          2 => 'r_index',
        ),
      ),
      'module' => 'relation_endpoint',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'relation_endpoint',
    ),
    'field_instance' => array(
      'bundle' => 'crm_contact_case',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'relation_endpoint',
          'settings' => array(),
          'type' => 'relation_endpoint',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'relation',
      'field_name' => 'endpoints',
      'label' => 'endpoints',
      'required' => FALSE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'relation_endpoint',
        'settings' => array(),
        'type' => 'relation_endpoint',
        'weight' => 0,
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Case is open');
  t('endpoints');

  return $fields;
}
