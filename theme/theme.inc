<?php

/**
 * @file
 * Theming and preprocessing functions.
 */

/**
 * Implements hook_preprocess().
 */
function ah_dirt_recipe_preprocess_dirt_recipes_item(array &$variables) {
  $path = drupal_get_path('module', 'ah_dirt_recipe');
  drupal_add_css("$path/css/dirt_recipes.css");
  $base = variable_get('ah_dirt_recipe_recipes_url', 'http://dev-hermeneutica-d7.pantheon.berkeley.edu/');
  $title = $variables['title'];
  $nid = $variables['nid'];
  $variables['link'] = l($title, "$base/node/$nid");
}

/**
 * Implements hook_preprocess().
 */
function ah_dirt_recipe_preprocess_dirt_recipes_block(array &$variables) {
  $max_count = variable_get('ah_dirt_recipe_recipe_count', 5);
  $path = drupal_get_path('module', 'ah_dirt_recipe');
  drupal_add_css("$path/css/recipes_dirt.css");
  $objects = $variables['objects'];
  $recipe_links = array();
  $site = variable_get('ah_dirt_recipe_recipes_site_name', 'Recipes');
  $title = $variables['title'];
  $variables['intro'] = t('The following recipes on @site use @tool.', array('@site' => $site, '@tool' => $title));
  foreach ($objects as $object) {
    foreach ($object as $key => $value) {
      $converted_object[$key] = $value;
    }
    $recipe_links[] = theme('dirt_recipes_item', $converted_object);
  }
  $variables['recipe_links'] = $recipe_links;
  $count = count($recipe_links);
  $shown = $count;
  if ($count > $max_count) {
    $variables['recipes_links'] = array_slice($recipe_links, 0, $max_count);
    $shown = $max_count;
  }
  $variables['overflow'] = '';
  $variables['count'] = '';
  if ($shown < $count) {
    $variables['count'] = t("Showing @sub of @all", array('@sub' => $shown, '@all' => $count));
  }
  $site_name = variable_get('ah_dirt_recipe_recipes_site_name', 'DHCommons');
  $site_url = variable_get('ah_dirt_recipe_recipes_url', 'http://recipes.org') . "/tools/$title";
  $variables['overflow'] = l(t("See all @all on @sitename", array('@all' => $count, '@sitename' => $site_name)), $site_url);
}
