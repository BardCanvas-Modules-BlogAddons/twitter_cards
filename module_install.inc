<?php
/**
 * Module installation file
 *
 * @package    BardCanvas
 * @subpackage twitter_cards
 * @author     Alejandro Caballero - lava.caballero@gmail.com
 * 
 * Trailing vars:
 * @var string $module_install_action install, uninstall, enable, disable
 * @var array  $messages
 * @var array  $errors
 * @var module $this_module
 * @var module $current_module
 */

use hng2_base\module;

$init_settings = array(
    "modules:twitter_cards.render_on_posts"  => "true",
    "modules:twitter_cards.render_on_media"  => "true",
    "modules:twitter_cards.twitter_site"     => "",
    "modules:twitter_cards.card_type"        => "summary",
    "modules:twitter_cards.home_description" => "",
    "modules:twitter_cards.fallback_image"   => "",
    "modules:twitter_cards.image_size"       => "mobile-retina",
);

if( $module_install_action == "install" )
{
    foreach($init_settings as $key => $val) $settings->set($key, $val);
    
    return;
}

if( $module_install_action == "uninstall" )
{
    foreach($init_settings as $key => $val) $settings->set($key, "");
    
    return;
}
