<?php
/**
 * @file
 * student_crm_holds.features.inc
 */

/**
 * Implements hook_node_info().
 */
function student_crm_holds_node_info() {
  $items = array(
    'hold_type' => array(
      'name' => t('Hold type'),
      'base' => 'node_content',
      'description' => t('A hold type is a description of a type of hold. These are only to describe the hold, including name and description, and is later related to a contact via a relation entity.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
