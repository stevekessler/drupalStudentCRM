<?php
/**
 * @file
 * student_crm_activity_mail_log.features.inc
 */

/**
 * Implements hook_default_crm_core_activity_type().
 */
function student_crm_activity_mail_log_default_crm_core_activity_type() {
  $items = array();
  $items['email_log'] = entity_import('crm_core_activity_type', '{
    "type" : "email_log",
    "label" : "Email log",
    "weight" : 0,
    "description" : "A log of an email being sent to a contact. When an email is sent from CRM, we check if the contact exists, and if so, add the mail to their record.",
    "rdf_mapping" : []
  }');
  return $items;
}
