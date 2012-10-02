<?php

/**
 * Default argument plugin to extract the first menu field in the active trail.
 */
 
 class views_plugin_current_mlid extends views_plugin_argument_default {
  function get_argument() {
    $menu = menu_get_active_trail();
    
    //sort backwards
    rsort($menu); 
    
    //special links (e.g. user/%) -  check the menu links table for the request_path()
    if((isset($menu[0]['mfid']) && !$menu[0]['mfid']) || $menu[0]['href'] == '<front>') {
      //get path
      $path = request_path();
     
      //check for frontpage
      if($menu[0]['href'] == '<front>') {
        $path = '<front>';
      }
          
      //lookup the database
      $query = db_select('menu_links', 'ml')
                ->fields('ml')
                ->condition('ml.link_path', $path);
 
      if ($item = $query->execute()->fetchAssoc()) {
        $menu[0] = $item;
      }
    }
   
    //run through each menu item and try to find any entity (inheritance) 
    foreach($menu as $item) {
      //check for override
      if(isset($item['mf_override']) && $item['mf_override']) {
        continue;
      } 
    
      //if enabled and entity id found
      if(isset($item['mf_enabled']) && $item['mf_enabled'] && isset($item['mfid']) && $item['mfid'] > 0) {
        return $item['mfid'];
      }
    }
    
    return NULL;
  }
}
