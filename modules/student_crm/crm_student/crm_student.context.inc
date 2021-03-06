<?php
/**
 * @file
 * crm_student.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function crm_student_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crm_anonymous_home';
  $context->description = 'Anonymous user is on the homepage.';
  $context->tag = 'crm_home';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'crm/home' => 'crm/home',
        '<front>' => '<front>',
      ),
    ),
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'user-login' => array(
          'module' => 'user',
          'delta' => 'login',
          'region' => 'sidebar_left',
          'weight' => '-10',
        ),
        'crm_student-crm_student_welcome' => array(
          'module' => 'crm_student',
          'delta' => 'crm_student_welcome',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Anonymous user is on the homepage.');
  t('crm_home');
  $export['crm_anonymous_home'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crm_authenticated_home';
  $context->description = 'Authenticated, non advisor user is on the homepage.';
  $context->tag = 'crm_home';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'crm/home' => 'crm/home',
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-crm_user_cases-block' => array(
          'module' => 'views',
          'delta' => 'crm_user_cases-block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Authenticated, non advisor user is on the homepage.');
  t('crm_home');
  $export['crm_authenticated_home'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crm_search';
  $context->description = 'Search context';
  $context->tag = 'crm';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
    'user' => array(
      'values' => array(
        'advisor' => 'advisor',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'crm_student-crm_student_search' => array(
          'module' => 'crm_student',
          'delta' => 'crm_student_search',
          'region' => 'header_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Search context');
  t('crm');
  $export['crm_search'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crm_search_page';
  $context->description = 'User is on the search page';
  $context->tag = 'crm';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'search_contacts' => 'search_contacts',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on the search page');
  t('crm');
  $export['crm_search_page'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crm_sitewide';
  $context->description = 'Site-wide settings for Student CRM';
  $context->tag = 'crm';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
    'user' => array(
      'values' => array(
        'advisor' => 'advisor',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-help' => array(
          'module' => 'system',
          'delta' => 'help',
          'region' => 'help',
          'weight' => '-10',
        ),
        'menu-menu-crm-navigation' => array(
          'module' => 'menu',
          'delta' => 'menu-crm-navigation',
          'region' => 'sidebar_left',
          'weight' => '-17',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Site-wide settings for Student CRM');
  t('crm');
  $export['crm_sitewide'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crm_sitewide_authenticated';
  $context->description = 'Any authenticated user is in the site.';
  $context->tag = 'crm';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'crm_student-crm_student_user_widget' => array(
          'module' => 'crm_student',
          'delta' => 'crm_student_user_widget',
          'region' => 'header_right',
          'weight' => '-3',
        ),
        'crm_student-crm_student_admin_link' => array(
          'module' => 'crm_student',
          'delta' => 'crm_student_admin_link',
          'region' => 'header_right',
          'weight' => '-2',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Any authenticated user is in the site.');
  t('crm');
  $export['crm_sitewide_authenticated'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crm_student_edit';
  $context->description = 'User is editing a student record';
  $context->tag = 'student';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'crm/contact/*/edit' => 'crm/contact/*/edit',
      ),
    ),
    'user' => array(
      'values' => array(
        'advisor' => 'advisor',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-crm_contact_fields-block' => array(
          'module' => 'views',
          'delta' => 'crm_contact_fields-block',
          'region' => 'content_top_wide',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is editing a student record');
  t('student');
  $export['crm_student_edit'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crm_student_view';
  $context->description = 'Viewing a student CRM contact';
  $context->tag = 'crm student';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'crm/contact/*' => 'crm/contact/*',
        '~crm/contact/*/edit' => '~crm/contact/*/edit',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'crm_case-crm_create_case' => array(
          'module' => 'crm_case',
          'delta' => 'crm_create_case',
          'region' => 'sidebar_left',
          'weight' => '3',
        ),
        'views-crm_contact_fields-block_2' => array(
          'module' => 'views',
          'delta' => 'crm_contact_fields-block_2',
          'region' => 'sidebar_right',
          'weight' => '-18',
        ),
        'views-crm_contact_cases-block' => array(
          'module' => 'views',
          'delta' => 'crm_contact_cases-block',
          'region' => 'sidebar_right',
          'weight' => '-17',
        ),
        'views-crm_contact_fields-block_1' => array(
          'module' => 'views',
          'delta' => 'crm_contact_fields-block_1',
          'region' => 'sidebar_right',
          'weight' => '-16',
        ),
        'views-crm_student_advisors-block' => array(
          'module' => 'views',
          'delta' => 'crm_student_advisors-block',
          'region' => 'sidebar_right',
          'weight' => '-15',
        ),
        'views-crm_contact_fields-block' => array(
          'module' => 'views',
          'delta' => 'crm_contact_fields-block',
          'region' => 'content_top_wide',
          'weight' => '-10',
        ),
      ),
    ),
    'menu' => 'crm/search',
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Viewing a student CRM contact');
  t('crm student');
  $export['crm_student_view'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'crm_user_page';
  $context->description = 'User is on a user\'s page';
  $context->tag = 'crm';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'advisor' => 'advisor',
      ),
    ),
    'user_page' => array(
      'values' => array(
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'all',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-crm_user_contact_records-block' => array(
          'module' => 'views',
          'delta' => 'crm_user_contact_records-block',
          'region' => 'sidebar_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('User is on a user\'s page');
  t('crm');
  $export['crm_user_page'] = $context;

  return $export;
}
