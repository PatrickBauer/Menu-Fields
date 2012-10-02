<?php

/**
 * Default argument plugin to extract the first menu field in the active trail.
 */
 
 class views_plugin_current_mlid extends views_plugin_argument_default {
  function get_argument() {
    $menu = menu_get_active_trail();
    
    rsort($menu);
    foreach($menu as $item) {
      if(isset($item['mf_enabled']) && $item['mf_enabled'] && isset($item['mfid']) && $item['mfid'] > 0) {
        return $item['mfid'];
      }
    }
    
    return NULL;
  }
}
