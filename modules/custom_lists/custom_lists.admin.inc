<?php
/**
 * Callback for 'admin/structure/lists'.
 */
function custom_lists_admin() {
  // Setup some default data.
  $domain = domain_get_domain();
  $types = node_type_get_names();
  $lists = custom_lists_get();

  // Setup the rows to show in the table.
  $rows = array();
  foreach ($lists as $list_key => $list) {
    if ($list['domain_id'] == $domain['domain_id']) {
      $row = array();
      $row[] = $list['title'];
      $row[] = l($list['path'], $list['path']);
      $row[] = $list['items'];
      $row[] = ucfirst($list['type']);

      $data = array();
      if ($list['type'] == 'content') {
        if ($list['node-type'] != '_any') {
          $data[] = t('Type: !type', array('!type' => $types[$list['node-type']]));
        }
        if (!empty($list['taxonomy'])) {
          $term = taxonomy_term_load($list['taxonomy']);
          $data[] = t('Taxonomy: !term', array('!term' => l($term->name, 'taxonomy/term/' . $term->tid)));
        }
      }
      else if ($list['type'] == 'menu') {
        $menu_item = menu_link_load($list['menu-item']);
        $data[] = t('Menu parent: !parent', array('!parent' => l($menu_item['link_title'], $menu_item['link_path'])));
      }
      $row[] = implode(',', $data);

      $row[] = l(t('Edit'), 'admin/structure/lists/edit/' . $list_key) . ' | ' . l(t('Delete'), 'admin/structure/lists/delete/' . $list_key);

      $rows[] = $row;
    }
  }

  return theme('table', array('header' => array(t('TItle'), t('Path'), t('# Items'), t('Type'), t('Data'), t('Operations')), 'rows' => $rows));
}

/**
 * Callback for 'admin/structure/lists/delete/%id
 */
function custom_lists_delete_form($form, &$form_state, $list_key) {
  $lists = custom_lists_get();
  $form['#listkey'] = $list_key;

  return confirm_form($form, t('Are you sure you want to delete the list !list?', array('!list' => $lists[$list_key]['path'])), 'admin/structure/lists');
}

function custom_lists_delete_form_submit($form, &$form_state) {
  custom_lists_delete($form['#listkey']);
  drupal_set_message(t('The list has been removed.'));
  $form_state['redirect'] = 'admin/structure/lists';
}

/**
 * Form for the add list.
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function custom_lists_list_form($form, &$form_state, $list_key = NULL) {
  $list = array();

  if ($list_key) {
    $lists = custom_lists_get();
    $list = $lists[$list_key];
  }

  $form['general'] = array(
    '#type' => 'fieldset',
    '#title' => t('General'),
    '#tree' => FALSE,
    '#attached' => array(
      'css' => array(
        drupal_get_path('module', 'custom_lists') . '/custom_lists.css',
      ),
      'js' => array(
        drupal_get_path('module', 'custom_lists') . '/custom_lists.js',
      ),
    ),
  );

  $form['general']['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Page Title'),
    '#size' => 30,
    '#required' => TRUE,
    '#default_value' => !empty($list['title']) ? $list['title']: '',
  );
  $form['general']['path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path'),
    '#required' => TRUE,
    '#size' => 30,
    '#default_value' => !empty($list['path']) ? $list['path']: '',
  );
  $form['general']['items'] = array(
    '#type' => 'textfield',
    '#title' => t('# Items'),
    '#required' => TRUE,
    '#default_value' => !empty($list['items']) ? $list['items']: 10,
    '#size' => 5,
  );

  $form['general']['type'] = array(
    '#type' => 'select',
    '#title' => t('Type'),
    '#options' => array(
      'content' => t('Content'),
      'menu' => t('Menu'),
    ),
    '#default_value' => !empty($list['type']) ? $list['type']: 'content',
  );

  $form['general']['provide-block'] = array(
    '#type' => 'checkbox',
    '#title' => t('Provide block'),
    '#default_value' => !empty($list['provide-block']) ? $list['provide-block']: FALSE,
  );

  $form['type-settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Settings'),
    '#tree' => FALSE,
  );

  // Node type data.
  $types = node_type_get_names();
  $form['type-settings']['node-type'] = array(
    '#type' => 'select',
    '#title' => t('Nodetype'),
    '#options' => array('_any' => t('Any')) + node_type_get_names(),
    '#default_value' => !empty($list['node-type']) ? $list['node-type']: '_any',
  );
  $def_taxonomy = '';
  if (!empty($list['taxonomy'])) {
    $term = taxonomy_term_load($list['taxonomy']);
    $def_taxonomy = $term->name;
  }
  $form['type-settings']['taxonomy'] = array(
    '#type' => 'textfield',
    '#title' => t('Term'),
    '#autocomplete_path' => 'custom_lists/taxonomy/autocomplete',
    '#maxlength' => 255,
    '#default_value' => $def_taxonomy,
  );
  $form['type-settings']['sort'] = array(
    '#type' => 'select',
    '#title' => t('Sort'),
    '#options' => array(
      'created_desc' => t('Post date: newest first'),
      'created_asc' => t('Post date: oldest first'),
      'changed_desc' => t('Changed date: newest first'),
      'changed_asc' => t('Changed date: oldest first'),
      'title_asc' => t('Title: ascending'),
      'title_desc' => t('Title: descending'),
    ),
    '#default_value' => !empty($list['sort']) ? $list['sort']: '',
  );

  // Menu type data.
  // Generate a list of possible parents (not including this link or descendants).
  $options = _custom_lists_menu_options();
  $form['type-settings']['menu-item'] = array(
    '#type' => 'select',
    '#title' => t('Menu Parent'),
    '#options' => $options,
    '#attributes' => array('class' => array('menu-title-select')),
    '#default_value' => !empty($list['menu-item']) ? $list['menu-item']: '',
  );

  // Init message.
  $form['intro'] = array(
    '#type' => 'fieldset',
    '#title' => t('Introduction text'),
    '#tree' => FALSE,
  );
  $form['intro']['intro-text'] = array(
    '#type' => 'text_format',
    '#format' => 'filtered_html',
    '#default_value' => !empty($list['intro-text']) ? $list['intro-text']: '',
  );

  $form['actions'] = array(
    '#type' => 'actions',
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  $form['actions']['cancel'] = array(
    '#type' => 'markup',
    '#markup' => l(t('Cancel'), 'admin/structure/lists'),
  );

  return $form;
}

/**
 * Submit handler.
 */
function custom_lists_list_form_submit($form, &$form_state) {
  $domain = domain_get_domain();
  $list_key = md5($domain['domain_id'] . '-' . $form_state['values']['path']);

  // Get taxonomy term id.
  if (!empty($form_state['values']['taxonomy'])) {
    $terms = taxonomy_get_term_by_name($form_state['values']['taxonomy']);
    $form_state['values']['taxonomy'] = key($terms);
  }

  // Empty some useless data.
  if ($form_state['values']['type'] == 'content') {
    $form_state['values']['menu-item'] = NULL;
  }
  else if ($form_state['values']['type'] == 'menu') {
    $form_state['values']['node-type'] = NULL;
  }

  // Setup list data.
  $list = array(
    'path' => $form_state['values']['path'],
    'title' => $form_state['values']['title'],
    'items' => $form_state['values']['items'],
    'type' => $form_state['values']['type'],
    'provide-block' => $form_state['values']['provide-block'],
    'node-type' => $form_state['values']['node-type'],
    'taxonomy' => $form_state['values']['taxonomy'],
    'sort' => $form_state['values']['sort'],
    'menu-item' => $form_state['values']['menu-item'],
    'intro-text' => $form_state['values']['intro-text']['value'],
    'domain_id' => $domain['domain_id'],
  );

  drupal_set_message(t('The list has been added.'));
  custom_lists_add($list_key, $list);
  $form_state['redirect'] = 'admin/structure/lists';
}

/**
 * Page callback: Outputs JSON for taxonomy autocomplete suggestions.
 *
 * This is copied from taxonomy_autocomplete but rewritten so it doesn't
 * need a field to exists.
 */
function custom_lists_taxonomy_autocomplete($term_search = '', $node_type = '') {
  // Part of the criteria for the query come from the field's own settings.
  /* $vids = array();
   $vocabularies = taxonomy_vocabulary_get_names();
   foreach ($vocabularies as $voc) {
     $vids[] = $voc->vid;
   } */

  $query = db_select('taxonomy_term_data', 't');
  $query->addTag('translatable');
  $query->addTag('term_access');

  // Select rows that match by term name.
  $tags_return = $query
    ->fields('t', array('tid', 'name'))
    //  ->condition('t.vid', $vids)
    ->condition('t.name', '%' . db_like($term_search) . '%', 'LIKE')
    ->range(0, 10)
    ->execute()
    ->fetchAllKeyed();

  foreach ($tags_return as $tid => $name) {
    $n = $name;
    // Term names containing commas or quotes must be wrapped in quotes.
    if (strpos($name, ',') !== FALSE || strpos($name, '"') !== FALSE) {
      $n = '"' . str_replace('"', '""', $name) . '"';
    }
    $term_matches[$n] = check_plain($name);
  }

  drupal_json_output($term_matches);
}

/**
 * Helper function to retrieve all menu item options which should atleast
 * have one child.
 *
 * @return array
 */
function _custom_lists_menu_options() {
  $options = array();

  $menus = menu_get_menus();
  foreach ($menus as $menu_name => $menu) {
    if (in_array($menu_name, variable_get('custom_lists_exclude_menus', array('management', 'navigation', 'user-menu')))) {
      continue;
    }

    $options[$menu] = array();

    $tree = menu_tree_all_data($menu_name, NULL);
    foreach ($tree as $link) {
      $options[$menu] += _custom_lists_menu_options_filter($link);
    }

    if (empty($options[$menu])) {
      unset($options[$menu]);
    }
  }

  return $options;
}

/**
 * Helper function for _custom_lists_menu_options() to be able to filter
 * recursively.
 *
 * @param $link
 * @param string $prefix
 * @return array
 */
function _custom_lists_menu_options_filter($link, $prefix = '') {
  if (empty($link['below'])) {
    // If we do not have any childs we are not an option.
    return array();
  }

  $options = array();
  $options[$link['link']['mlid']] = $prefix . $link['link']['link_title'] . ' (' . count($link['below']) . ')';

  $sub_prefix = $prefix . $link['link']['link_title'] . '--';

  foreach ($link['below'] as $sublink) {
    $options += _custom_lists_menu_options_filter($sublink, $sub_prefix);
  }

  return $options;
}