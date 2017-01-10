<?php

/**
 * @file
 * Definition of muut_comments_handler_muut_comments_count.
 */


/**
 * Create custom view field to show comments count
 */
class muut_comments_handler_muut_comments_count extends views_handler_field {

  function construct() {
    parent::construct();

    // Add nid as an additional field. This is a requirement for loading the
    // comments but might not always be available to us.
    $this->additional_fields['nid'] = array(
      'table' => 'node',
      'field' => 'nid',
    );
  }

  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  function query() {
    // Load additional fields.
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($data) {

    $output = '';

    // Get nid via get_value, don't just count on it being there in $data.
    $nid = $this->get_value($data, 'nid');

    $node = node_load($nid);
    $groups = og_get_entity_groups('node', $node);

    $comment_ids = array();
    if (!empty($groups['node'])) {
      foreach($groups['node'] as $group) {
        if ($node && $node->nid && muut_comments_enabled($node) && $group) {
          $comment_ids[] = $group . ':' . $node->nid;
        }
      }
    }
    if(!empty($comment_ids)) {
      $community_name = variable_get('muut_comments_community_name', '');
      drupal_add_js(drupal_get_path('module', 'muut_comments') . '/js/muut-comments-count.js');
      foreach($comment_ids as $comment_id) {
        $path = $community_name . '/comments/' . $comment_id;
        $output .= '<div id="muut-comments-count-list" class="muut-comments-count-list-element" data-path="' . $path . '"></div>';
      }
    }

    return $output;

  }

}
