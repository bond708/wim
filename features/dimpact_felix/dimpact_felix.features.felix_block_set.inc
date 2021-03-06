<?php
/**
 * @file
 * dimpact_felix.features.felix_block_set.inc
 */

/**
 * Implements hook_felix_default_block_sets().
 */
function dimpact_felix_felix_default_block_sets() {
  $sets = array();
  $sets['default'] = array(
    'name' => 'default',
    'title' => 'default',
    'blocks' => array(
      0 => array(
        'module' => 'block',
        'delta' => 6,
      ),
      1 => array(
        'module' => 'custom_lists',
        'delta' => '*',
      ),
      2 => array(
        'module' => 'mailchimp_lists',
        'delta' => '*',
      ),
      3 => array(
        'module' => 'menu',
        'delta' => 'menu-toptaken',
      ),
      4 => array(
        'module' => 'menu_block',
        'delta' => 1,
      ),
      5 => array(
        'module' => 'quicktabs',
        'delta' => 'nieuws_agenda',
      ),
      6 => array(
        'module' => 'submenutree',
        'delta' => 1,
      ),
      7 => array(
        'module' => 'submenutree',
        'delta' => 2,
      ),
      8 => array(
        'module' => 'twitter_filter_words',
        'delta' => '*',
      ),
      9 => array(
        'module' => 'views',
        'delta' => '-exp-announcements-page',
      ),
      10 => array(
        'module' => 'views',
        'delta' => 'agenda-block_1',
      ),
      11 => array(
        'module' => 'views',
        'delta' => 'agenda-block_2',
      ),
      12 => array(
        'module' => 'views',
        'delta' => 'berichten-block_1',
      ),
      13 => array(
        'module' => 'views',
        'delta' => 'bestanden-block_1',
      ),
      14 => array(
        'module' => 'views',
        'delta' => 'blogs-block_1',
      ),
      15 => array(
        'module' => 'views',
        'delta' => 'carrousel_keuze-block',
      ),
      16 => array(
        'module' => 'views',
        'delta' => 'carrousel_keuze-block_1',
      ),
      17 => array(
        'module' => 'views',
        'delta' => 'carrousel_keuze-block_2',
      ),
      18 => array(
        'module' => 'views',
        'delta' => 'favorieten-block_1',
      ),
      19 => array(
        'module' => 'views',
        'delta' => 'foto_album-block_1',
      ),
      20 => array(
        'module' => 'views',
        'delta' => 'foto_album-block_2',
      ),
      21 => array(
        'module' => 'views',
        'delta' => 'ibabs-block_1',
      ),
      22 => array(
        'module' => 'views',
        'delta' => 'ibabs-block_2',
      ),
      23 => array(
        'module' => 'views',
        'delta' => 'marktplaats-block_1',
      ),
      24 => array(
        'module' => 'views',
        'delta' => 'marktplaats-block_2',
      ),
      25 => array(
        'module' => 'views',
        'delta' => 'marktplaats-block_3',
      ),
      26 => array(
        'module' => 'views',
        'delta' => 'marktplaats-block_4',
      ),
      27 => array(
        'module' => 'views',
        'delta' => 'marktplaats-block_5',
      ),
      28 => array(
        'module' => 'views',
        'delta' => 'nieuws-block_1',
      ),
      29 => array(
        'module' => 'views',
        'delta' => 'nieuws-block_2',
      ),
      30 => array(
        'module' => 'views',
        'delta' => 'nieuws-block_3',
      ),
      31 => array(
        'module' => 'views',
        'delta' => 'nodequeue_carousel_9_3-block',
      ),
      32 => array(
        'module' => 'views',
        'delta' => 'nodequeue_carousel_9_3-block_1',
      ),
      33 => array(
        'module' => 'views',
        'delta' => 'nodequeue_carousel_9_3-block_2',
      ),
      34 => array(
        'module' => 'views',
        'delta' => 'personen-block_1',
      ),
      35 => array(
        'module' => 'views',
        'delta' => 'personen-block_2',
      ),
      36 => array(
        'module' => 'views',
        'delta' => 'personen_intranet-block_1',
      ),
      37 => array(
        'module' => 'views',
        'delta' => 'producten-block_1',
      ),
      38 => array(
        'module' => 'views',
        'delta' => 'producten-block_2',
      ),
      39 => array(
        'module' => 'views',
        'delta' => 'updates-block_1',
      ),
      40 => array(
        'module' => 'views',
        'delta' => 'veelgestelde_vragen-faq_recent',
      ),
      41 => array(
        'module' => 'views',
        'delta' => 'voorpagina_banners-block_1',
      ),
      42 => array(
        'module' => 'views',
        'delta' => 'weblog-block',
      ),
    ),
    'nodetypes' => array(
      0 => array(
        'nodetype' => 'editorial',
      ),
      1 => array(
        'nodetype' => 'poll',
      ),
      2 => array(
        'nodetype' => 'slide',
      ),
      3 => array(
        'nodetype' => 'webform',
      ),
    ),
    'viewmodes' => array(
      0 => array(
        'viewmode' => 'full',
      ),
      1 => array(
        'viewmode' => 'slide_312',
      ),
      2 => array(
        'viewmode' => 'slide_412',
      ),
      3 => array(
        'viewmode' => 'slide_812',
      ),
      4 => array(
        'viewmode' => 'slide_912',
      ),
      5 => array(
        'viewmode' => 'teaser',
      ),
      6 => array(
        'viewmode' => 'volle_breedte',
      ),
    ),
  );
  $sets['footer-blokken'] = array(
    'name' => 'footer-blokken',
    'title' => 'Footer blokken',
    'blocks' => array(
      0 => array(
        'module' => 'dominion_social',
        'delta' => 'links',
      ),
    ),
    'nodetypes' => array(
      0 => array(
        'nodetype' => 'editorial',
      ),
    ),
    'viewmodes' => array(
      0 => array(
        'viewmode' => 'full',
      ),
      1 => array(
        'viewmode' => 'slide_312',
      ),
      2 => array(
        'viewmode' => 'slide_412',
      ),
      3 => array(
        'viewmode' => 'slide_812',
      ),
      4 => array(
        'viewmode' => 'slide_912',
      ),
      5 => array(
        'viewmode' => 'teaser',
      ),
      6 => array(
        'viewmode' => 'volle_breedte',
      ),
    ),
  );
  return $sets;
}
