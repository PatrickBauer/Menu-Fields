<?php

/**
 * @file
 * Contains the user from URL argument default plugin.
 */

/**
 * Default argument plugin to extract a user via menu_get_object.
 */
 
 class views_plugin_current_mlid extends views_plugin_argument_default {
  function get_argument() {
    $menu = menu_get_active_trail();
    
    rsort($menu);
    foreach($menu as $item) {
      if(isset($item['mfid']) && intval($item['mfid']) > 0) {
        return $item['mfid'];
      }
    }
    
    return NULL;
  }
}
