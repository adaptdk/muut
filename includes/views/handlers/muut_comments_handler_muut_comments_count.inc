<?php

/**
 * @file
 * Definition of muut_comments_handler_muut_comments_count.
 */


/**
 * Create custom view field to show comments count
 */
class muut_comments_handler_muut_comments_count extends views_handler_field {

  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  function query() {
    // do nothing -- to override the parent query.
  }

  function render($data) {

    $node = node_load($data->nid);
    $og_group = field_get_items('node', $node, 'og_group_ref');
    $og_group = reset($og_group);

    if ($node && $node->nid && muut_comments_enabled($node) && $og_group['target_id']) {
      $comment_id = $og_group['target_id'] . ':' . $node->nid;
    } else {
      return;
    }

    drupal_add_js(drupal_get_path('module', 'muut_comments') . '/js/muut-comments-count.js');

    $community_name = variable_get('muut_comments_community_name', '');
    $path = $community_name . '/comments/' . $comment_id;

    $output = '<div id="muut-comments-count-list" class="muut-comments-count-list-element" data-path="' . $path . '"></div>';
    return $output;
  }

}