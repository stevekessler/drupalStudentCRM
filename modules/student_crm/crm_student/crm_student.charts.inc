<?php

/**
 * @file
 * Chart tools for CRM
 */
 
/**
 * Draws a chart using Google Charts API
 */
function _crm_student_draw_chart($chart) {
  drupal_add_js('https://www.google.com/jsapi', 'external');
  $script = 'google.load("visualization", "1", {packages:["corechart"]});';
  drupal_add_js($script, array('type' => 'inline', 'scope' => 'footer'));
  
  return '<div id="' . $chart['id'] . '"></div>';
  
}