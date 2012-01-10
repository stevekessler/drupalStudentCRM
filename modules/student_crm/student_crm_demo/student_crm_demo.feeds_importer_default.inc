<?php
/**
 * @file
 * student_crm_demo.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function student_crm_demo_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'crm_demo_activities';
  $feeds_importer->config = array(
    'name' => 'Demo activities',
    'description' => 'Demonstration activity importer',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'StudentCRMActivityFeedsProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'student_id',
            'target' => 'student_id',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'activity_id',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'date',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'type',
            'target' => 'field_activity_contact_method',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'note',
            'target' => 'field_activity_notes',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'user',
            'target' => 'author_name',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
        'activity_type' => 'note',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['crm_demo_activities'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'crm_demo_addresses';
  $feeds_importer->config = array(
    'name' => 'Demo addresses',
    'description' => 'Sample importer of contact addresses',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'CRMStudentAddresses',
      'config' => array(
        'expire' => -1,
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'student_id',
            'target' => 'student_id',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'address_id',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'address_1',
            'target' => 'thoroughfare',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'city',
            'target' => 'locality',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'state',
            'target' => 'administrative_area',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'zip',
            'target' => 'postal_code',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
        'default_country' => 'US',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['crm_demo_addresses'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'crm_demo_advisors';
  $feeds_importer->config = array(
    'name' => 'Demo Advisor Feed',
    'description' => 'Sample importer of advisor relationships.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'CRMFeedsAdvisorRelationProcessor',
      'config' => array(
        'expire' => -1,
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'advisor_id',
            'target' => 'advisor_id',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'student_id',
            'target' => 'student_id',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => 0,
        'input_format' => NULL,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['crm_demo_advisors'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'crm_demo_cases';
  $feeds_importer->config = array(
    'name' => 'Demo cases',
    'description' => 'Demonstration case importer',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'CRMCaseFeedsProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'case_type' => 'simple_case',
        'mappings' => array(
          0 => array(
            'source' => 'case_id',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'student_id',
            'target' => 'student_id',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'date',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'description',
            'target' => 'field_case_description',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'author',
            'target' => 'author_name',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'title',
            'target' => 'name',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['crm_demo_cases'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'crm_demo_courses';
  $feeds_importer->config = array(
    'name' => 'Demo courses',
    'description' => 'Demo importer for course data.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'course',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'subject',
            'target' => 'field_course_prefix',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'term',
            'target' => 'field_course_term',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'number',
            'target' => 'field_course_number',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'section',
            'target' => 'field_course_section',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'id',
            'target' => 'guid',
            'unique' => 1,
          ),
          5 => array(
            'source' => 'title',
            'target' => 'field_course_title',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['crm_demo_courses'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'crm_demo_degrees';
  $feeds_importer->config = array(
    'name' => 'Demo Degrees',
    'description' => 'A demonstration taxonomy for degrees',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 'degrees',
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'name',
            'unique' => 0,
          ),
          1 => array(
            'source' => 'title',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'type',
            'target' => 'field_degree_type',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['crm_demo_degrees'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'crm_demo_enrollment';
  $feeds_importer->config = array(
    'name' => 'Demo enrollment',
    'description' => 'Course enrollment data.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'CRMFeedsCourseEnrollmentProcessor',
      'config' => array(
        'expire' => -1,
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'enrollment_id',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'student_id',
            'target' => 'student_id',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'course_id',
            'target' => 'course_id',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'enrolled',
            'target' => 'field_enrollment_status',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'grade_points',
            'target' => 'field_enrollment_grade_points',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'letter_grade',
            'target' => 'field_enrollment_grade_letter',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'units',
            'target' => 'field_enrollment_units',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => 0,
        'input_format' => NULL,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['crm_demo_enrollment'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'crm_demo_gpa';
  $feeds_importer->config = array(
    'name' => 'Demo GPA',
    'description' => 'Demonstration GPA importer',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'CRMFeedsGPAProcessor',
      'config' => array(
        'expire' => -1,
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'student_id',
            'target' => 'student_id',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'term',
            'target' => 'term_id',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'cumulative_gpa',
            'target' => 'field_gpa_cumulative',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'term_gpa',
            'target' => 'field_gpa_term',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => 0,
        'input_format' => NULL,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['crm_demo_gpa'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'crm_demo_holds';
  $feeds_importer->config = array(
    'name' => 'Demo holds',
    'description' => 'A demonstration importer for hold data.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'hold_type',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'name',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'code',
            'target' => 'field_hold_code',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'code',
            'target' => 'guid',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'description',
            'target' => 'body',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'severity',
            'target' => 'field_hold_severity',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['crm_demo_holds'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'crm_demo_levels';
  $feeds_importer->config = array(
    'name' => 'Demo student levels',
    'description' => 'A demonstration feed importer for student levels.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 'student_level',
        'mappings' => array(
          0 => array(
            'source' => 'name',
            'target' => 'name',
            'unique' => 0,
          ),
          1 => array(
            'source' => 'name',
            'target' => 'guid',
            'unique' => 1,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['crm_demo_levels'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'crm_demo_status';
  $feeds_importer->config = array(
    'name' => 'Demo Student Status',
    'description' => 'Import student statuses',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 'student_status',
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'name',
            'unique' => 0,
          ),
          1 => array(
            'source' => 'title',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'alert',
            'target' => 'field_status_alert',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['crm_demo_status'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'crm_demo_student_holds';
  $feeds_importer->config = array(
    'name' => 'Demo student holds',
    'description' => 'Demonstration importer for student holds.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'CRMFeedsHoldsProcessor',
      'config' => array(
        'expire' => -1,
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'student_hold_id',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'student_id',
            'target' => 'student_id',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'hold_code',
            'target' => 'hold_code',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'term',
            'target' => 'field_hold_term',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'date',
            'target' => 'field_hold_date_created:start',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => 0,
        'input_format' => NULL,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['crm_demo_student_holds'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'crm_demo_students';
  $feeds_importer->config = array(
    'name' => 'Demo Students',
    'description' => 'Demonstration import of students.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'CRMFeedsContactProcessor',
      'config' => array(
        'contact_type' => 'student',
        'expire' => '-1',
        'author' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'student_id',
            'target' => 'field_student_id',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'student_id',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'degree',
            'target' => 'field_student_degrees',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'email',
            'target' => 'field_contact_email',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'status',
            'target' => 'field_student_status',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'level',
            'target' => 'field_student_level',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'first_name',
            'target' => 'contact_name:given',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'last_name',
            'target' => 'contact_name:family',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['crm_demo_students'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'crm_demo_terms';
  $feeds_importer->config = array(
    'name' => 'Demo Terms',
    'description' => 'Imports term information.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 'term',
        'mappings' => array(
          0 => array(
            'source' => 'term',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'start',
            'target' => 'field_term_start:start',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'end',
            'target' => 'field_term_end:start',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'term',
            'target' => 'name',
            'unique' => 0,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['crm_demo_terms'] = $feeds_importer;

  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'crm_demo_users';
  $feeds_importer->config = array(
    'name' => 'Demo users',
    'description' => 'Imports users and makes them advisors.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          3 => '3',
          4 => 0,
        ),
        'status' => '1',
        'defuse_mail' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'sis_id',
            'target' => 'field_user_sis_id',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'login',
            'target' => 'name',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'pass',
            'target' => 'pass',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'first_name',
            'target' => 'field_user_name_first',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'last_name',
            'target' => 'field_user_name_last',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'email',
            'target' => 'mail',
            'unique' => 1,
          ),
        ),
        'update_existing' => 0,
        'input_format' => 'plain_text',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['crm_demo_users'] = $feeds_importer;

  return $export;
}
