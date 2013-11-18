api = 2
core = 7.x
projects[drupal][type] = core
projects[drupal][patch][htaccess_iecompat] = patches/htaccess_iecompat.patch
projects[drupal][patch][htaccess_directories404] = patches/htaccess_directories404.patch
projects[drupal][patch][etag] = patches/etag.patch

; Modules
projects[admin_menu][subdir] = contrib
projects[admin_views][subdir] = contrib
projects[apachesolr][subdir] = contrib
projects[apachesolr_attachments][subdir] = contrib
projects[apachesolr_exclude_node][subdir] = contrib
projects[backup_migrate][subdir] = contrib
projects[better_formats][subdir] = contrib
projects[block_class][subdir] = contrib
projects[cck_blocks][subdir] = contrib
projects[context][subdir] = contrib
projects[context_entity_field][subdir] = contrib
projects[ctools][subdir] = contrib
projects[cs_adaptive_image][subdir] = contrib
projects[date][subdir] = contrib
projects[date][patch][1832544-2][url] = http://drupal.org/files/migrate_class_registration-1832544-2.patch
projects[date][patch][1832544-2][md5] = 0ba3ea17a06554841a6ba83cf432ba9b
projects[devel][subdir] = contrib
projects[diff][subdir] = contrib
projects[domain][subdir] = contrib
projects[domain][version] = "3.10"
projects[domaincontext][subdir] = contrib
projects[domain_taxonomy][subdir] = contrib
projects[domain_views][subdir] = contrib
projects[domain_views][version] = "1.5"
projects[domain_views][patch][multiple_values] = http://drupal.org/files/multiple-values-2029419-1.patch
projects[domain_xmlsitemap][subdir] = contrib
projects[domain_xmlsitemap][version] = "1.0-beta2"
projects[domaincontext][subdir] = contrib
projects[domaincontext][version] = "1.0-alpha1"
projects[dominion][subdir] = contrib
projects[dominion][revision] = fe839a9
projects[elysia_cron][subdir] = contrib
projects[email][subdir] = contrib
projects[empty_page][subdir] = contrib
projects[entity][subdir] = contrib
projects[entityreference][subdir] = contrib
projects[expire][subdir] = contrib
projects[extlink][subdir] = contrib
projects[facetapi][subdir] = contrib
projects[faq][subdir] = contrib
projects[features][subdir] = contrib
projects[features_extra][subdir] = contrib
projects[feeds][subdir] = contrib
projects[felix][subdir] = contrib
projects[felix][revision] = ebe1b1f
projects[fences][subdir] = contrib
projects[field_group][subdir] = contrib
projects[field_group_multiple][subdir] = contrib
projects[file_entity][subdir] = contrib
projects[file_entity][version] = "2.0-alpha2"
projects[flag][subdir] = contrib
projects[galleryformatter][subdir] = contrib
projects[gmap][subdir] = contrib
projects[google_analytics][subdir] = contrib
projects[hansel][subdir] = contrib
projects[hansel][revision] = 0715082
projects[homebox][subdir] = contrib
projects[homebox][revision] = 48e101a
projects[i18n][subdir] = contrib
projects[job_scheduler][subdir] = contrib
projects[jquery_update][subdir] = contrib
projects[jquery_update][revision] = baff5d1
projects[l10n_update][subdir] = contrib
projects[login_destination][subdir] = contrib
projects[libraries][subdir] = contrib
projects[lightbox2][subdir] = contrib
projects[link][subdir] = contrib
projects[linkit][subdir] = contrib
projects[location][subdir] = contrib
projects[mail_edit][subdir] = contrib
projects[mailchimp][subdir] = contrib
projects[masquerade][subdir] = contrib
projects[media][subdir] = contrib
projects[media][version] = "2.0-alpha2"
projects[media_youtube][subdir] = contrib
projects[media_youtube][revision] = 8afda26
projects[media_vimeo][subdir] = contrib
projects[memcache][subdir] = contrib
projects[menu_attributes][subdir] = contrib
projects[menu_block][subdir] = contrib
projects[menu_token][subdir] = contrib
projects[menuimage][subdir] = contrib
projects[metatag][subdir] = contrib
projects[module_filter][subdir] = contrib
;projects[modernizr][subdir] = contrib
projects[nodequeue][subdir] = contrib
projects[nodequeue][revision] = 70c0602
projects[nodequeue][patch][1154948][url] = http://drupal.org/files/taxonomy-sync-queue-1154948-15.patch
projects[nodequeue][patch][1154948][md5] = 2eae7ee249c90238cb0e8bfb6a98293b
projects[pathauto][subdir] = contrib
projects[pathauto_persist][subdir] = contrib
projects[pathologic][subdir] = contrib
projects[piwik][subdir] = contrib
projects[purge][subdir] = contrib
projects[quicktabs][subdir] = contrib
projects[remote_stream_wrapper][subdir] = contrib
projects[rules][subdir] = contrib
projects[static_404][subdir] = contrib
projects[site_map][subdir] = contrib
projects[scheduler][subdir] = contrib
projects[service_links][subdir] = contrib
projects[strongarm][subdir] = contrib
projects[submenutree][subdir] = contrib
projects[subscriptions][subdir] = contrib
projects[token][subdir] = contrib
projects[token][revision] = c5b20e0
projects[translation_helpers][subdir] = contrib
projects[transliteration][subdir] = contrib
projects[variable][subdir] = contrib
projects[views][subdir] = contrib
projects[views_bulk_operations][subdir] = contrib
projects[views_rss][subdir] = contrib
projects[webform][subdir] = contrib
projects[wikitools][subdir] = contrib
projects[workbench][subdir] = contrib
projects[workbench_moderation][subdir] = contrib
projects[wysiwyg][subdir] = contrib

; Themes
projects[] = rijkshuisstijl

; Rijkshuisstijl starterskit
libraries[starterskit][type] = "libraries"
libraries[starterskit][download][type] = "file"
libraries[starterskit][download][url] = "https://github.com/studiodumbar/starterskit-pb/zipball/1.2.3"

; CKEditor 3.6.2
libraries[ckeditor][download][type] = get
libraries[ckeditor][download][url] = http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.6.3/ckeditor_3.6.3.tar.gz

; Mailchimp
libraries[mailchimp][download][type] = "get"
libraries[mailchimp][download][url] = "http://apidocs.mailchimp.com/api/downloads/mailchimp-api-class.zip"
libraries[mailchimp][directory_name] = "mailchimp"
libraries[mailchimp][destination] = "libraries"

; Modernizr
;libraries[modernizr][download][type] = "get"
;libraries[modernizr][download][url] = "http://www.modernizr.com/downloads/modernizr-2.6.2.js"
;libraries[modernizr][directory_name] = "modernizr"
;libraries[modernizr][destination] = "libraries"
