<?php
/**
 * @file
 * MailhandlerCommandsCRMActivity class.
 */

$plugin = array(
  'name' => 'Creates activities from email',
  'description' => 'Builds CRM Activities from emails.',
  'handler' => array(
    'class' => 'MailhandlerCommandsCRMActivity',
    'parent' => 'MailhandlerCommands',
  ),
  'file' => 'MailhandlerCommandsCRMActivity.class.php',
  'weight' => 30,
);
?>