<?php
/**
 * @file
 * student_crm_activity_mailer.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function student_crm_activity_mailer_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'crm_activity_mail_handler';
  $feeds_importer->config = array(
    'name' => 'Activity Mail Handler',
    'description' => 'Handles importing activities via sent mail.',
    'fetcher' => array(
      'plugin_key' => 'MailhandlerFetcher',
      'config' => array(
        'filter' => 'all',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'MailhandlerParser',
      'config' => array(
        'if_auth_fails' => 'remove',
        'default_commands' => 'status: 1',
        'available_commands' => 'status',
        'command_plugin' => array(
          0 => 'MailhandlerCommandsDefault',
          1 => 'MailhandlerCommandsFiles',
          2 => 'MailhandlerCommandsHeaders',
        ),
        'authenticate_plugin' => 'MailhandlerAuthenticateDefault',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'StudentCRMActivityEmailFeedsProcessor',
      'config' => array(
        'expire' => -1,
        'author' => 0,
        'activity_type' => 'email_activity',
        'mappings' => array(
          0 => array(
            'source' => 'toaddress',
            'target' => 'contact_email',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'ccaddress',
            'target' => 'contact_email',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'bccaddress',
            'target' => 'contact_email',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'origbody',
            'target' => 'field_activity_note',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'attachments',
            'target' => 'field_activity_attachments',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'senderaddress',
            'target' => 'author_email',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => 0,
        'input_format' => NULL,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '900',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['crm_activity_mail_handler'] = $feeds_importer;

  return $export;
}
