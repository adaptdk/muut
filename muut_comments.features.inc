<?php
/**
 * @file
 * muut_comments.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function muut_comments_image_default_styles() {
  $styles = array();

  // Exported image style: muut.
  $styles['muut'] = array(
    'label' => 'muut',
    'effects' => array(
      15 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 32,
          'height' => 32,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
