<?php
/**
 * @file
 * crm_student.features.guiders_js_pack.inc
 */

/**
 * Implements hook_guiders_js_pack_features_default().
 */
function crm_student_guiders_js_pack_features_default() {
  $items = array(
    'homebox' => array(
      'name' => 'homebox',
      'title' => 'homebox',
      'path' => 'dashboard',
      'data' => 'a:13:{s:5:"title";s:7:"homebox";s:12:"machine_name";s:7:"homebox";s:4:"path";s:9:"dashboard";s:6:"active";i:1;s:5:"start";s:1:"3";s:10:"delay_time";s:4:"2000";s:10:"event_type";s:7:"onclick";s:12:"event_attach";s:11:"#content h2";s:6:"submit";s:9:"Save Pack";s:13:"form_build_id";s:48:"form-w30UyMMbUpv4OUYfZyoC6XJ--QzuMKDCKnLkP1XH6Bc";s:10:"form_token";s:43:"eMS4R3L9Q0FoXoXZnTt2udGIZPdIADwCbqDEB-L4EWc";s:7:"form_id";s:25:"guiders_js_packs_add_form";s:2:"op";s:9:"Save Pack";}',
      'guiders' => array(
        'your-dashboard' => array(
                             'name' => 'your-dashboard',
                             'title' => 'Your dashboard',
                             'weight' => '1',
                             'data' => 'a:14:{s:5:"title";s:14:"Your dashboard";s:12:"machine_name";s:14:"your-dashboard";s:4:"desc";a:2:{s:5:"value";s:243:"Your dashboard is a customizable homepage where you can place blocks of information such as a list of your advisees, a tracker of recent activity, and quick reports on how your students are doing. Click next to learn more about your dashboard.";s:6:"format";s:9:"full_html";}s:6:"attach";s:0:"";s:8:"position";s:0:"";s:5:"width";s:0:"";s:7:"overlay";i:1;s:5:"close";i:1;s:10:"buttons_fs";a:1:{i:0;a:1:{s:4:"name";s:4:"Next";}}s:6:"submit";s:11:"Save Guider";s:13:"form_build_id";s:48:"form-KttcNE8DCcgsc9oeCpKb7mX6F7sgK1cYTpUQBIbi5kA";s:10:"form_token";s:43:"c4OeWhyuWkDHLfRjwKcg2av5u4nFxe2xr7jpnsNWYAk";s:7:"form_id";s:19:"guiders_js_add_form";s:2:"op";s:11:"Save Guider";}',
                         ),
        'adding-a-new-block' => array(
                             'name' => 'adding-a-new-block',
                             'title' => 'Adding a new block',
                             'weight' => '2',
                             'data' => 'a:14:{s:5:"title";s:18:"Adding a new block";s:12:"machine_name";s:18:"adding-a-new-block";s:4:"desc";a:2:{s:5:"value";s:175:"To add a new block to your dashboard, click the <strong>Add a block</strong> link. You will see a list of available blocks that you can drag to any location on your dashboard.";s:6:"format";s:9:"full_html";}s:6:"attach";s:17:"#homebox-add-link";s:8:"position";s:2:"12";s:5:"width";s:0:"";s:7:"overlay";i:0;s:5:"close";i:1;s:10:"buttons_fs";a:1:{i:0;a:1:{s:4:"name";s:4:"Next";}}s:6:"submit";s:11:"Save Guider";s:13:"form_build_id";s:48:"form-k9LHT0Px6kmr62ioWP8HM9asfMGo0whFPqInqJdJK30";s:10:"form_token";s:43:"c4OeWhyuWkDHLfRjwKcg2av5u4nFxe2xr7jpnsNWYAk";s:7:"form_id";s:19:"guiders_js_add_form";s:2:"op";s:11:"Save Guider";}',
                         ),
        'closing-and-minimizing-blocks' => array(
                             'name' => 'closing-and-minimizing-blocks',
                             'title' => 'Closing and minimizing blocks',
                             'weight' => '3',
                             'data' => 'a:14:{s:5:"title";s:29:"Closing and minimizing blocks";s:12:"machine_name";s:29:"closing-and-minimizing-blocks";s:4:"desc";a:2:{s:5:"value";s:158:"To remove a block from your dashboard, use the "x" button on the right of the block. You can also minimize any block to save space by clicking the "-" button.";s:6:"format";s:9:"full_html";}s:6:"attach";s:19:".portlet-icon:first";s:8:"position";s:2:"12";s:5:"width";s:0:"";s:7:"overlay";i:0;s:5:"close";i:1;s:10:"buttons_fs";a:1:{i:0;a:1:{s:4:"name";s:5:"Close";}}s:6:"submit";s:11:"Save Guider";s:13:"form_build_id";s:48:"form--92q5L660130ZHFFp5nucY7GE950Zu2rUxY6GWfRmTA";s:10:"form_token";s:43:"c4OeWhyuWkDHLfRjwKcg2av5u4nFxe2xr7jpnsNWYAk";s:7:"form_id";s:19:"guiders_js_add_form";s:2:"op";s:11:"Save Guider";}',
                         ),
      ),
    ),
  );
  return $items;
}
