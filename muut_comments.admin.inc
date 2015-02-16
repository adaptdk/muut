<?php

function muut_comments_config_form($form, &$form_state) {

  $form['muut_comments_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Muut API key'),
    '#default_value' => variable_get('muut_comments_api_key', ''),
    '#size' => 10,
    '#maxlength' => 10,
    '#description' => t('The Muut API key.'),
    '#required' => TRUE,
  );

  $form['muut_comments_api_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Muut API key'),
    '#default_value' => variable_get('muut_comments_api_secret', ''),
    '#size' => 24,
    '#maxlength' => 24,
    '#description' => t('The Muut API secret.'),
    '#required' => TRUE,
  );

  $form['muut_comments_community_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Muut community name'),
    '#default_value' => variable_get('muut_comments_community_name', ''),
    '#size' => 60,
    '#maxlength' => 60,
    '#description' => t('The name of your Muut community.'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}