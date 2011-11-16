<?php
/**
 * @file
 * student_crm_activity.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function student_crm_activity_taxonomy_default_vocabularies() {
  return array(
    'activity_types' => array(
      'name' => 'Activity types',
      'machine_name' => 'activity_types',
      'description' => 'Categorizes activity types.',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
