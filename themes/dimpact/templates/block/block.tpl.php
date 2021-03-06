<?php

/**
 * @file
 * Default theme implementation to display a block.
 *
 * Available variables:
 * - $block->subject: Block title.
 * - $content: Block content.
 * - $block->module: Module that generated the block.
 * - $block->delta: An ID for the block, unique within each module.
 * - $block->region: The block region embedding the current block.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - block: The current template type, i.e., "theming hook".
 *   - block-[module]: The module generating the block. For example, the user module
 *     is responsible for handling the default user navigation block. In that case
 *     the class would be "block-user".
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $block_html_id: A valid HTML ID and guaranteed unique.
 *
 * @see template_preprocess()
 * @see template_preprocess_block()
 * @see template_process()
 */

$icon = '';
if (preg_match('|block-node-([0-9]+)|', $block_html_id, $matches)) {
  if ($node = node_load($matches[1])) {
    if ($node->type == 'editorial' && $field = field_get_items('node', $node, 'field_foto')) {
      $file_path = image_style_url('pictogram', $field[0]['uri']);

      $field_file_alt = $field[0]['field_file_image_alt_text']['und'][0]['safe_value'];
      $file_alt = isset($field_file_alt) ? $field_file_alt : "Pictogram";
      $field_file_title = $field[0]['field_file_image_title_text']['und'][0]['safe_value'];
      $file_title_att = isset($field_file_title) ? ' title="' . $field_file_title . '"' : "";

      $icon = '<img src="' . $file_path . '" class="pictogram" alt="' . $file_alt . '"' . $file_title_att . '>';
    }
  }
}

?>
<div<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <?php if (!empty($content_attributes)): ?><div<?php print $content_attributes; ?>><?php endif; ?>
    <?php if ($block->subject): ?>
      <h2<?php print $title_attributes; ?>><?php print $icon; ?><?php print $block->subject ?></h2>
    <?php endif;?>
    <?php print render($title_suffix); ?>
    <?php print $content; ?>
  <?php if (!empty($content_attributes)): ?></div><?php endif; ?>
  <div class="clearfix"></div>
</div>
