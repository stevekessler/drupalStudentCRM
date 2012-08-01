<?php
/**
 * @file
 * student_crm_gpa.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function student_crm_gpa_field_default_fields() {
  $fields = array();

  // Exported field: 'relation-term_gpa-field_gpa_cumulative'
  $fields['relation-term_gpa-field_gpa_cumulative'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_gpa_cumulative',
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'number',
      'settings' => array(
        'decimal_separator' => '.',
      ),
      'translatable' => '0',
      'type' => 'number_float',
    ),
    'field_instance' => array(
      'bundle' => 'term_gpa',
      'default_value' => array(
        0 => array(
          'value' => '0',
        ),
      ),
      'deleted' => '0',
      'description' => 'The total computed GPA for the related term.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 2,
            'thousand_separator' => ' ',
          ),
          'type' => 'number_decimal',
          'weight' => 1,
        ),
      ),
      'entity_type' => 'relation',
      'field_name' => 'field_gpa_cumulative',
      'label' => 'Cumulative GPA',
      'required' => 0,
      'settings' => array(
        'max' => '',
        'min' => '0',
        'prefix' => '',
        'suffix' => ' GPA',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'relation-term_gpa-field_gpa_term'
  $fields['relation-term_gpa-field_gpa_term'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_gpa_term',
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'number',
      'settings' => array(
        'decimal_separator' => '.',
      ),
      'translatable' => '0',
      'type' => 'number_float',
    ),
    'field_instance' => array(
      'bundle' => 'term_gpa',
      'default_value' => array(
        0 => array(
          'value' => '0',
        ),
      ),
      'deleted' => '0',
      'description' => 'The total GPA for just the current term.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 2,
            'thousand_separator' => ' ',
          ),
          'type' => 'number_decimal',
          'weight' => 2,
        ),
      ),
      'entity_type' => 'relation',
      'field_name' => 'field_gpa_term',
      'label' => 'Term GPA',
      'required' => 0,
      'settings' => array(
        'max' => '',
        'min' => '0',
        'prefix' => '',
        'suffix' => ' GPA',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '2',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Cumulative GPA');
  t('Term GPA');
  t('The total GPA for just the current term.');
  t('The total computed GPA for the related term.');

  return $fields;
}
