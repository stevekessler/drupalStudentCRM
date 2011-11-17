<?php

/**
*  Add more body classes for the toolbar
*/
function student_crm_preprocess_html(&$vars) {
  if(isset($vars['page']['tabs'])) {
    $vars['classes_array'][] = 'with-tabs';
  }
}

/**
 * Add themed user info to activities.
 */
function student_crm_preprocess_entity(&$variables) {
  if($variables['elements']['#entity_type'] == 'crm_activity') {
    $activity = $variables['crm_activity'];
    $author = user_load($variables['crm_activity']->uid);
    $variables['date'] = format_date($variables['crm_activity']->created, 'short');
    $variables['submitted'] = t('By !username <span class="date">on !datetime</span>', array('!username' => $variables['name'], '!datetime' => $variables['date']));
    
    $picture = field_get_items('user', $author, 'field_user_picture');
    $image_path = ($picture[0]['uri'])
             ? $picture[0]['uri']
             : 'public://default_images/generic_person.png';
    $variables['picture'] = theme('image_style', array('style_name' => 'history_small',
                                                       'path' => $image_path,
                                                       'alt' => strip_tags($variables['name'])));
    $variables['contact_type'] = $variables['content']['field_activity_contact_method'][0]['#title'];
    unset($variables['content']['field_activity_contact_method']);
    
    $variables['permalink'] = l(t('permalink'), 'crm/activity/'. $activity->crm_activity_id);
    if(!$variables['page']) {
      $rendered_content = render($variables['content']);
      $trimmed_content = text_summary($rendered_content, 'full_html', 1000);
      if(strlen($trimmed_content) < strlen($rendered_content)) {
        $variables['show_trimmed'] = TRUE;
        $variables['read_more_link'] = l(t('Read more...'), 'crm/activity/'. $activity->crm_activity_id);
      }
    }
  }
}

/**
*	Override the status messages to place a container div within them
*/
function student_crm_status_messages($variables) {
  $display = $variables['display'];
  $output = '';

  $status_heading = array(
    'status' => t('Status message'), 
    'error' => t('Error message'), 
    'warning' => t('Warning message'),
  );
  foreach (drupal_get_messages($display) as $type => $messages) {
    $output .= "<div class=\"messages $type\">\n";
    $output .= "<div class=\"container\">\n";
    $output .= "<div class=\"message-icon\"></div>";
    if (!empty($status_heading[$type])) {
      $output .= '<h2 class="element-invisible">' . $status_heading[$type] . "</h2>\n";
    }
    if (count($messages) > 1) {
      $output .= " <ul>\n";
      foreach ($messages as $message) {
        $output .= '  <li>' . $message . "</li>\n";
      }
      $output .= " </ul>\n";
    }
    else {
      $output .= $messages[0];
    }
    $output .= "</div>\n";
    $output .= "</div>\n";
  }
  return $output;
}
