<?php
/**
 * Posts extender: profile renderer below the post contents
 * 
 * @package    BardCanvas
 * @subpackage external_usertags
 * @author     Alejandro Caballero - lava.caballero@gmail.com
 * 
 * Imported globals:
 * @var post_record $post
 */

use hng2_modules\posts\post_record;

global $post, $settings;

if( empty($post) ) return;
if( $post->status != "published" ) return;

if( $settings->get("modules:twitter_cards.render_on_posts") != "true" ) return;

$twitter_site = $settings->get("modules:twitter_cards.twitter_site");
if( empty($twitter_site) ) return;

$author_name    = htmlspecialchars($post->author_display_name);
$post_title     = htmlspecialchars($post->title);
$category_text  = "[{$post->main_category_title}]";
$tweet_text     = trim("{$author_name}: {$post_title} {$category_text}");
$button_caption = $this_module->language->tweet_button_caption;
$data_via       = trim($twitter_site, "@");

echo "
    <p class='post_social_buttons' data-module='twitter_cards'>
        <a href='https://twitter.com/share' class='twitter-share-button' 
           data-url='{$post->get_permalink(true)}' data-text='{$tweet_text}' data-via='{$data_via}' 
           data-size='large'>$button_caption</a>
           <script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0],p=/^http:/.test(d.location)?'http':'https';
           if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src=p+'://platform.twitter.com/widgets.js';
           fjs.parentNode.insertBefore(js,fjs);}}(document, 'script', 'twitter-wjs');</script>
    </p>
";
