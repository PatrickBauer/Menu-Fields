<?php

/**
 * Default argument plugin to extract the first menu field in the active trail.
 */
 
 class views_plugin_current_mlid extends views_plugin_argument_default {
  function get_argument() {
    return menu_fields_get_active_mfid();
  }
}
