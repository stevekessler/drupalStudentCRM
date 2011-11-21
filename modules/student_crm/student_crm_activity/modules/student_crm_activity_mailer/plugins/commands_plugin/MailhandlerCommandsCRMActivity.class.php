<?php
/**
 * @file
 * MailhandlerCommandsMyCustomCommand class.
 */

class MailhandlerCommandsCRMActivity extends MailhandlerCommands {

  /**
   * Parse the subject for a Case ID.
   */
  function process(&$message, $source) {

    $splitmail = array();
    $splitmail = explode("-----(Please reply above this line)-----",$message['origbody']);

    //strip everything after this text
    $message['origbody'] = $splitmail[0];

    //grab case_id from subject line
    $message['case_id'] = substr($message['subject'], strpos($message['subject'], 'case #') + 6);
  }

  function getMappingSources() {
    $sources = array();

      $sources['case_id'] = array(
        'title' => t('Case ID'),
        'description' => t('The original Case ID'),
      );
    return $sources;
  }
}
?>