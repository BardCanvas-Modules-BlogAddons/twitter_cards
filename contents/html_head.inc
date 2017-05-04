<?php
/**
 * Styles and scripts for the module
 *
 * @package    BardCanvas
 * @subpackage twitter_cards
 * @author     Alejandro Caballero - lava.caballero@gmail.com
 *
 * @var config   $config
 * @var module   $this_module
 * @var template $template
 *
 * @var post_record  $post
 * @var media_record $item
 */

use hng2_base\config;
use hng2_base\module;
use hng2_base\template;
use hng2_media\media_record;
use hng2_modules\posts\post_record;

global $settings, $template;

if( $template->layout == "admin" ) return;
if( $template->layout == "embeddable" ) return;

if( $settings->get("modules:twitter_cards.twitter_site")    == "" ) return;
if( $settings->get("modules:twitter_cards.card_type")       == "" ) return;

$post = $template->get("current_post");
$item = $template->get("current_item");

$title       = "";
$description = "";
$image       = "";
if( $template->get("page_tag") == "home" )
{
    $title = $settings->get("engine.website_name");
    $image = "{$config->full_root_url}/{$settings->get("modules:twitter_cards.fallback_image")}";
}
elseif( $template->get("page_tag") == "single_post" )
{
    $title       = $post->title;
    $description = $post->excerpt;
    
    # TODO: Implement external user tags profile pic here
    $image       = "{$config->full_root_url}/{$post->featured_image_thumbnail}";
}
elseif( $template->get("page_tag") == "single_media_item" )
{
    $title       = $item->title;
    $description = $item->get_description_excerpt();
    $image       = $item->get_thumbnail_url(true);
}

if( empty($description) ) $description = $settings->get("modules:twitter_cards.home_description");
?>

<!-- [+] twitter_cards -->
<meta name="twitter:card"       content="<?= $settings->get("modules:twitter_cards.card_type") ?>">
<meta name="twitter:site"       content="<?= $settings->get("modules:twitter_cards.twitter_site") ?>">
<? if( ! empty($title)):       ?><meta name="twitter:title"       content="<?= htmlspecialchars($title) ?>"><? endif; ?>

<? if( ! empty($description)): ?><meta name="twitter:description" content="<?= htmlspecialchars($description) ?>"><? endif; ?>

<meta name="twitter:image"       content="<?= $image ?>">
<!-- [-] twitter_cards -->

