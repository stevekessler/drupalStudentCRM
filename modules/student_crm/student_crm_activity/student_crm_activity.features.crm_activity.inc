<?php
/**
 * @file
 * student_crm_activity.features.crm_activity.inc
 */

/**
 * Implements hook_crm_features_activity_defaults().
 */
function student_crm_activity_crm_features_activity_defaults() {
  $items = array(
    'note' => array(
      'type' => t('note'),
      'label' => 'Note',
      'description' => '',
    ),
  );
  return $items;
}
