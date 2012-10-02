<?php

/** 
 * Implementation of hook_views_plugins()
 */
function menu_fields_views_plugins() {
  return array(
    'argument default' => array(
      'menu_fields_current_mlid' => array(
        'title' => t('Menu Fields ID from active menuitem'),
        'handler' => 'views_plugin_current_mlid',
        'path' => drupal_get_path('module', 'menu_fields') . '/views',
      ),
    ),
  );
}