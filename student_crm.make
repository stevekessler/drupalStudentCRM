; Make file for student_crm profile.

projects[drupal][type] = core
core = 7.x
api = 2


;Adding the profiler module
;Profiler is in dev and we can't patch libraries, so including it in the repository for now
;libraries[profiler][download][type] = "get"
;libraries[profiler][download][url] = "http://ftp.drupal.org/files/projects/profiler-7.x-2.x-dev.tar.gz"
;libraries[profiler][destination] = "libraries/profiler"

projects[admin_menu][subdir] = "contrib"
projects[admin_menu][version] = "3.0-rc1"

projects[addressfield][subdir] = "contrib"
projects[addressfield][version] = "1.0-beta2"

projects[auto_nodetitle][subdir] = "contrib"
projects[auto_nodetitle][version] = "1.0"

projects[better_formats][subdir] = "contrib"
projects[better_formats][version] = "1.x-dev"

projects[cck_phone][subdir] = "contrib"
projects[cck_phone][version] = "1.x-dev"

projects[conditional_fields][subdir] = "contrib"
projects[conditional_fields][version] = "3.x-dev"

projects[context][subdir] = "contrib"
projects[context][version] = "3.0-beta2"

projects[chosen][subdir] = "contrib"
projects[chosen][version] = "1.0"

projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.x-dev"

projects[crm_core][subdir] = "contrib"
projects[crm_core][version] = "1.x-dev"

projects[date][subdir] = "contrib"
projects[date][version] = "2.0-alpha4"

projects[email][subdir] = "contrib"
projects[email][version] = "1.x-dev"

projects[entity][subdir] = "contrib"
projects[entity][version] = "1.0-beta11"

projects[entityreference][subdir] = "contrib"
projects[entityreference][version] = "1.0-beta3"

projects[fancybox][subdir] = "contrib"
projects[fancybox][version] = "1.x-dev"

projects[features][subdir] = "contrib"
projects[features][version] = "1.x-dev"

projects[feeds][subdir] = "contrib"
projects[feeds][version] = "2.0-alpha4"

projects[feeds_tamper][subdir] = "contrib"
projects[feeds_tamper][version] = "1.0-beta3"

projects[field_group][subdir] = "contrib"
projects[field_group][version] = "1.1"

projects[homebox][subdir] = "contrib"
projects[homebox][version] = "2.0-beta6"

projects[interface][subdir] = "contrib"
projects[interface][version] = "1.x-dev"

projects[job_scheduler][subdir] = "contrib"
projects[job_scheduler][version] = "2.0-alpha2"

projects[libraries][subdir] = "contrib"
projects[libraries][version] = "1.0"

projects[link][subdir] = "contrib"
projects[link][version] = "1.0-beta1"

projects[notifications][subdir] = "contrib"
projects[notifications][version] = "1.0-alpha1"

projects[mailhandler][subdir] = "contrib"
projects[mailhandler][version] = "2.0-rc1"

projects[messaging][subdir] = "contrib"
projects[messaging][version] = "1.0-alpha1"

;projects[name][subdir] = "contrib"
;projects[name][version] = "1.x-dev"

projects[options_element][subdir] = "contrib"
projects[options_element][version] = "1.4"

projects[relation][subdir] = "contrib"
projects[relation][version] = "1.x-dev"

projects[rules][subdir] = "contrib"
projects[rules][version] = "2.0"

projects[token][subdir] = "contrib"
projects[token][version] = "1.0-beta7"

projects[views][subdir] = "contrib"
projects[views][version] = "3.x-dev"

projects[views_bulk_operations][subdir] = "contrib"
projects[views_bulk_operations][version] = "3.0-beta3"

projects[views_exposed_groups][subdir] = "contrib"
projects[views_exposed_groups][version] = "1.x-dev"

projects[views_datasource][subdir] = "contrib"
projects[views_datasource][version] = "1.x-dev"

projects[webform][subdir] = "contrib"
projects[webform][version] = "3.13"

projects[webform_submission_entity][subdir] = "contrib"
projects[webform_submission_entity][version] = "1.x-dev"

; Themes

projects[rubik][subdir] = "contrib"
projects[rubik][version] = "4.0-beta6"

projects[tao][subdir] = "contrib"
projects[tao][version] = "3.0-beta4"

; Modules in development

; Formalize module
projects[formalize][type] = module
projects[formalize][subdir] = "contrib"
projects[formalize][version] = "1.x-dev"
projects[formalize][download][type] = "git"
projects[formalize][download][url] = "http://git.drupal.org/project/formalize.git"
projects[formalize][download][branch] = "7.x-1.x"

; Name module
projects[name][type] = module
projects[name][subdir] = "contrib"
projects[name][version] = "1.x-dev"
projects[name][download][type] = "git"
projects[name][download][url] = "http://git.drupal.org/project/name.git"
projects[name][download][branch] = "7.x-1.x"

; Libraries

; Download the chosen library

libraries[chosen][download][type] = "get"
libraries[chosen][download][url] = "https://github.com/harvesthq/chosen/zipball/master"
libraries[chosen][directory_name] = "chosen"
libraries[chosen][destination] = "libraries"

; Download fancybox library
libraries[fancybox][download][type] = "get"
libraries[fancybox][download][url] = "http://fancybox.googlecode.com/files/jquery.fancybox-1.3.4.zip"
libraries[fancybox][directory_name] = "fancybox"
libraries[fancybox][destination] = "libraries"

; Download the Formalize library
libraries[formalize][download][type] = "get"
libraries[formalize][download][url] = "https://github.com/nathansmith/formalize/tarball/master"
libraries[formalize][directory_name] = "formalize"
libraries[formalize][destination] = "libraries"

; Patches

projects[chosen][patch][] = http://drupal.org/files/issues/chosen-7.x-1.x-install_profile.patch
projects[cck_phone][patch][] = "http://drupal.org/files/cck_phone_feeds-1160186-2.patch"
projects[crm_core][patch][] = "http://drupal.org/files/crm_core_activity_access-1399920-1.patch"
projects[email][patch][] = "http://drupal.org/files/email_feeds_target-718414-36.patch"
projects[fancybox][patch][] = "http://drupal.org/files/fancybox_library_sub_folder.patch"
projects[name][patch][] = "http://drupal.org/files/name_fullname_search-1369618-3.patch"

; Hosted modules
projects[views_savedsearches][type] = module
projects[views_savedsearches][subdir] = "contrib"
projects[views_savedsearches][version] = "7.x-dev"
projects[views_savedsearches][download][type] = "file"
projects[views_savedsearches][download][url] = "http://s4.csumb.edu/hosted_modules/views_savedsearches.tar.gz"

projects[relation][type] = module
projects[relation][subdir] = "contrib"
projects[relation][version] = "7.x-dev"
projects[relation][download][type] = "file"
projects[relation][download][url] = "http://webprojects.csumb.edu/crm/downloads/relation.tar.gz"