<?php

/**
 * @file
 * Views definitions for muut_comments module.
 */

/**
 * Implements hook_views_data().
 */

function muut_comments_views_data() {
  $data = array();
  $data['node']['muut_comments_count'] = array(
    'title' => t('Muut blog post comments count'),
    'help' => t('Show muut comments count for blog post in view'),
    'field' => array(
      'handler' => 'muut_comments_handler_muut_comments_count',
    ),
  );
  return $data;
}

/**
 * Implementation of hook_views_handlers()
 */
function muut_comments_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'muut_comments') . '/includes/views/handlers',
    ),
    'handlers' => array(
      // The name of my handler
      'dsr_blog_handler_muut_comments_count' => array(
        // The name of the handler we are extending.
        'parent' => 'views_handler_field_node',
      ),
    ),
  );
}