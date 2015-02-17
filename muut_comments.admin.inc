<?php
/**
 * @file
 * Admin functions for the Muut comments module.
 */

/**
 * Muut comments configuration form.
 */
function muut_comments_config_form($form, &$form_state) {

  $form['api'] = array(
    '#type' => 'fieldset',
    '#title' => t('Muut API configuration'),
  );

  $form['api']['muut_comments_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('API key'),
    '#default_value' => variable_get('muut_comments_api_key', ''),
    '#size' => 10,
    '#maxlength' => 10,
    '#description' => t('The Muut API key.'),
    '#required' => TRUE,
  );

  $form['api']['muut_comments_api_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Muut API key'),
    '#default_value' => variable_get('muut_comments_api_secret', ''),
    '#size' => 24,
    '#maxlength' => 24,
    '#description' => t('The Muut API secret.'),
    '#required' => TRUE,
  );

  $form['api']['wrapper']['muut_comments_community_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Muut community name'),
    '#default_value' => variable_get('muut_comments_community_name', ''),
    '#size' => 60,
    '#maxlength' => 60,
    '#description' => t('The name of your Muut community.'),
    '#required' => TRUE,
  );

  $form['api']['wrapper']['muut_comments_css'] = array(
    '#type' => 'checkbox',
    '#title' => t('Muut default CSS'),
    '#default_value' => variable_get('muut_comments_css', TRUE),
    '#description' => t('Include the default CSS from Muut CDN.'),
  );

  $form['fields'] = array(
    '#type' => 'fieldset',
    '#title' => t('Fields used to enable/disable comments'),
    '#description' => t('Only boolean fields can be assigned as the enable/disable field.'),
  );

  $form['fields']['muut_comments_enable_field'] = array('#tree' => TRUE);

  $default_values = variable_get('muut_comments_enable_field', array());

  $fields_info = field_info_instances('node');
  foreach ($fields_info as $bundle => $bundle_info) {
    $field_names = array('' => t('None'));
    foreach ($bundle_info as $field_name => $info) {
      $field_info = field_info_field($field_name);
      if ($field_info['type'] == 'list_boolean') {
        $field_names[$field_name] = $field_name;
      }
    }
    $form['fields']['muut_comments_enable_field'][$bundle] = array(
      '#type' => 'select',
      '#options' => $field_names,
      '#title' => t('Field for @bundle', array('@bundle' => $bundle)),
      '#default_value' => (empty($default_values[$bundle]) ? '' : $default_values[$bundle]),
    );
  }

  $form['user'] = array(
    '#type' => 'fieldset',
    '#title' => t('Fields used for user information'),
  );

  $fields_info = field_info_instances('user', 'user');
  $field_names = array('' => t('None'));
  foreach ($fields_info as $field_name => $info) {
    $field_info = field_info_field($field_name);
    if ($field_info['type'] == 'text') {
      $field_names[$field_name] = $field_name;
    }
  }
  $form['user']['muut_comments_displayname_field'] = array(
    '#type' => 'select',
    '#options' => $field_names,
    '#title' => t('Field for displayname'),
    '#default_value' => variable_get('muut_comments_displayname_field', ''),
    '#description' => t('Only textfields can be assigned as source of the displayname'),
  );

  return system_settings_form($form);
}
