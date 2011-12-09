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

projects[context][subdir] = "contrib"
projects[context][version] = "3.0-beta2"

projects[chosen][subdir] = "contrib"
projects[chosen][version] = "1.0"

projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.x-dev"

projects[date][subdir] = "contrib"
projects[date][version] = "2.0-alpha4"

projects[email][subdir] = "contrib"
projects[email][version] = "1.x-dev"

projects[entity][subdir] = "contrib"
projects[entity][version] = "1.0-beta11"

projects[entityreference][subdir] = "contrib"
projects[entityreference][version] = "1.0-beta2"

projects[fancybox][subdir] = "contrib"
projects[fancybox][version] = "1.x-dev"

projects[features][subdir] = "contrib"
projects[features][version] = "1.x-dev"

projects[feeds][subdir] = "contrib"
projects[feeds][version] = "2.0-alpha4"

projects[field_group][subdir] = "contrib"
projects[field_group][version] = "1.1"

;projects[Guiders-JS][subdir] = "contrib"
;projects[Guiders-JS][version] = "1.x-dev"

projects[homebox][subdir] = "contrib"
projects[homebox][version] = "2.0-beta6"

;projects[interface][subdir] = "contrib"
;projects[interface][version] = "1.x-dev"

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

projects[name][subdir] = "contrib"
projects[name][version] = "1.x-dev"

projects[options_element][subdir] = "contrib"
projects[options_element][version] = "1.4"

projects[privatemsg][subdir] = "contrib"
projects[privatemsg][version] = "2.x-dev"

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

projects[webform][subdir] = "contrib"
projects[webform][version] = "3.13"

; Themes

projects[rubik][subdir] = "contrib"
projects[rubik][version] = "4.0-beta6"

projects[tao][subdir] = "contrib"
projects[tao][version] = "3.0-beta4"

; Modules in development

; Trellon CRM

projects[crm_core][type] = module
projects[crm_core][subdir] = "contrib"
projects[crm_core][version] = "1.x-dev"
projects[crm_core][download][type] = "git"
projects[crm_core][download][url] = "http://git.drupal.org/project/crm_core.git"
projects[crm_core][download][branch] = "master"

; Formalize module
projects[formalize][type] = module
projects[formalize][subdir] = "contrib"
projects[formalize][version] = "1.x-dev"
projects[formalize][download][type] = "git"
projects[formalize][download][url] = "http://git.drupal.org/project/formalize.git"
projects[formalize][download][branch] = "7.x-1.x"

; Fixed Guiders-JS module module
projects[guiders_js_fixed][type] = module
projects[guiders_js_fixed][subdir] = "contrib"
projects[guiders_js_fixed][version] = "1.x-dev"
projects[guiders_js_fixed][download][type] = "git"
projects[guiders_js_fixed][download][url] = "http://git.drupal.org/sandbox/kevee/1355900.git"
projects[guiders_js_fixed][download][branch] = "master"

; Webform submission entity module
projects[webform_submission_entity][type] = module
projects[webform_submission_entity][subdir] = "contrib"
projects[webform_submission_entity][version] = "1.x-dev"
projects[webform_submission_entity][download][type] = "git"
projects[webform_submission_entity][download][url] = "http://git.drupal.org/sandbox/kevee/1324794.git"
projects[webform_submission_entity][download][branch] = "master"

; Libraries

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

; Download the guidersJS library
libraries[guiders][download][type] = "get"
libraries[guiders][download][url] = "https://github.com/jeff-optimizely/Guiders-JS/tarball/master"
libraries[guiders][directory_name] = "guiders"
libraries[guiders][destination] = "libraries"

; Patches

projects[chosen][patch][] = http://drupal.org/files/issues/chosen-7.x-1.x-install_profile.patch
projects[cck_phone][patch][] = "http://drupal.org/files/issues/cck_phone_testing-1165464-2.patch"
projects[email][patch][] = "http://drupal.org/files/email_feeds_target-718414-36.patch"
projects[name][patch][] = "http://drupal.org/files/name_feeds_parser-1160190-3.patch"

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