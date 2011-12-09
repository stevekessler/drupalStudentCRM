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
      'auto_start' => '1',
      'guiders' => array(
        'your-dashboard' => array(
                             'name' => 'your-dashboard',
                             'title' => 'Your dashboard',
                             'data' => 'a:14:{s:5:"title";s:14:"Your dashboard";s:12:"machine_name";s:14:"your-dashboard";s:4:"desc";a:2:{s:5:"value";s:243:"Your dashboard is a customizable homepage where you can place blocks of information such as a list of your advisees, a tracker of recent activity, and quick reports on how your students are doing. Click next to learn more about your dashboard.";s:6:"format";s:13:"filtered_html";}s:6:"attach";s:0:"";s:8:"position";s:0:"";s:5:"width";s:0:"";s:7:"overlay";i:0;s:5:"close";i:1;s:10:"buttons_fs";a:1:{i:0;a:1:{s:4:"name";s:4:"Next";}}s:6:"submit";s:11:"Save Guider";s:13:"form_build_id";s:48:"form-RSuIG440-q9e5HwEcmOgMAVqaIOLDBVZ0BPPfNs3z6s";s:10:"form_token";s:43:"aup1x6WE_dvTC7WtsiExEfTPDXijOtSuxr3_rYxT0vE";s:7:"form_id";s:19:"guiders_js_add_form";s:2:"op";s:11:"Save Guider";}',
                         ),
        'adding-a-new-block' => array(
                             'name' => 'adding-a-new-block',
                             'title' => 'Adding a new block',
                             'data' => 'a:14:{s:5:"title";s:18:"Adding a new block";s:12:"machine_name";s:18:"adding-a-new-block";s:4:"desc";a:2:{s:5:"value";s:175:"To add a new block to your dashboard, click the <strong>Add a block</strong> link. You will see a list of available blocks that you can drag to any location on your dashboard.";s:6:"format";s:13:"filtered_html";}s:6:"attach";s:17:"#homebox-add-link";s:8:"position";s:1:"6";s:5:"width";s:0:"";s:7:"overlay";i:0;s:5:"close";i:1;s:10:"buttons_fs";a:1:{i:0;a:1:{s:4:"name";s:4:"Next";}}s:6:"submit";s:11:"Save Guider";s:13:"form_build_id";s:48:"form-qmCvz31yC6jaIm0hkXZbVfKHnyokZPoN3j9TqEnGGTg";s:10:"form_token";s:43:"aup1x6WE_dvTC7WtsiExEfTPDXijOtSuxr3_rYxT0vE";s:7:"form_id";s:19:"guiders_js_add_form";s:2:"op";s:11:"Save Guider";}',
                         ),
        'closing-and-minimizing-blocks' => array(
                             'name' => 'closing-and-minimizing-blocks',
                             'title' => 'Closing and minimizing blocks',
                             'data' => 'a:14:{s:5:"title";s:29:"Closing and minimizing blocks";s:12:"machine_name";s:29:"closing-and-minimizing-blocks";s:4:"desc";a:2:{s:5:"value";s:158:"To remove a block from your dashboard, use the "x" button on the right of the block. You can also minimize any block to save space by clicking the "-" button.";s:6:"format";s:13:"filtered_html";}s:6:"attach";s:19:".portlet-icon:first";s:8:"position";s:2:"12";s:5:"width";s:0:"";s:7:"overlay";i:0;s:5:"close";i:1;s:10:"buttons_fs";a:1:{i:0;a:1:{s:4:"name";s:5:"Close";}}s:6:"submit";s:11:"Save Guider";s:13:"form_build_id";s:48:"form-QGcfwzY2iAZzlSAxLVIXQdIkmo3Xm--7THvfAtK6AaM";s:10:"form_token";s:43:"aup1x6WE_dvTC7WtsiExEfTPDXijOtSuxr3_rYxT0vE";s:7:"form_id";s:19:"guiders_js_add_form";s:2:"op";s:11:"Save Guider";}',
                         ),
      ),
    ),
  );
  return $items;
}
