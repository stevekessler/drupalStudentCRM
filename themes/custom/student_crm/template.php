<?php

/**
*  Add more body classes for the toolbar
*/
function student_crm_preprocess_html(&$vars) {
  if(isset($vars['page']['tabs'])) {
    $vars['classes_array'][] = 'with-tabs';
  }
  if(!isset($vars['page']['sidebar_left']) && !isset($vars['page']['sidebar_right'])) {
    $vars['classes_array'][] = 'no-sidebars';
  }
  else {
    foreach($vars['classes_array'] as $k => $class) {
      if($class == 'no-sidebars') {
        unset($vars['classes_array'][$k]);
      }
    }
  }
}

/**
 * Add themed user info to activities.
 */
function student_crm_preprocess_entity(&$variables) {
  if($variables['elements']['#entity_type'] == 'crm_core_activity') {
    $variables['elements']['elements']['#template'] = 'templates/crm_core_activity';
    $activity = $variables['crm_core_activity'];
    $variables['content']['field_activity_participants'] = $variables['field_activity_participants'] = null;
    $variables['content']['field_activity_date'] = $variables['field_activity_date'] = null;
    
    if(isset($variables['content']['status_change'])) {
      $variables['status_change'] = $variables['content']['status_change'];
      unset($variables['content']['status_change']);
    }
    
    $author = user_load($activity->uid);
    $variables['date'] = format_date($activity->created, 'short');
    $variables['name'] = theme('username', array('account' => $author));
    $variables['submitted'] = t('By !username <span class="date">on !datetime</span>', array('!username' => $variables['name'], '!datetime' => $variables['date']));
    
    $picture = field_get_items('user', $author, 'field_user_picture');
    if ($picture[0]['uri']) {
      $variables['picture'] = theme('image_style', array('style_name' => 'history_small',
                                                       'path' => $picture[0]['uri'],
                                                       'alt' => strip_tags($variables['name'])));
    }
    $variables['contact_type'] = $variables['content']['field_activity_contact_method'][0]['#title'];
    unset($variables['content']['field_activity_contact_method']);
    $variables['content']['field_activity_notes']['#label_display'] = 'hidden';
    $variables['permalink'] = l(t('permalink'), 'crm/activity/'. $activity->activity_id);
    if(!$variables['page']) {
      $rendered_content = render($variables['content']);
      $trimmed_content = text_summary($rendered_content, 'full_html', 1000);
      if(strlen($trimmed_content) < strlen($rendered_content)) {
        $variables['show_trimmed'] = TRUE;
        $variables['read_more_link'] = l(t('Read more...'), 'crm/activity/'. $activity->activity_id);
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

/**
 * Implements theme_preprocess_node().
 * Remove submitted-by line completely - not needed in a CRM.
 */
function student_crm_preprocess_node(&$variables) {
  unset($variables['submitted']);
}