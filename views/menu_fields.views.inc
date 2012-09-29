<?php

function menu_fields_views_plugins() {
  return array(
    'argument default' => array(
      'menu_fields_current_mlid' => array(
        'title' => t('MLID from active trail'),
        'handler' => 'views_plugin_current_mlid',
        'path' => drupal_get_path('module', 'menu_fields') . '/views',
      ),
    ),
  );
}