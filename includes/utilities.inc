<?php

/**
 * @file
 * Utility functions.
 */

/**
 * Retrieves DHCommons data through REST.
 *
 * @global url $base_url
 *
 * @param string $title
 *   Name of recipe to be returned
 */
function ah_dirt_recipe_recipes_fetch($title = NULL) {
  $recipes_url = variable_get('ah_dirt_recipe_recipes_url', 'http://dev.recipes.org');
  $rest_path = variable_get('ah_dirt_recipe_recipes_rest_path', 'rest');
  $alias = variable_get('ah_dirt_recipe_recipes_alias', 'recipe');
  $url = "$recipes_url/$rest_path/$alias";
  $api_key = variable_get('ah_recipes_api_key', '');
  $taxonomy = variable_get('ah_dirt_recipe_recipes_taxonomy', 'tools_used');
  $sort = variable_get('ah_dirt_recipe_recipes_sort', 'timestamp');
  $post_data = array(
    'api-key' => $api_key,
    'tool_name' => $title,
    'taxonomy' => $taxonomy,
    'sort' => $sort,
  );
  $data = http_build_query($post_data, '', '&');
  $options = array(
    'headers' => array(
      'Accept' => 'application/json',
      'Content-Type' => 'application/x-www-form-urlencoded'),
    'method' => 'POST',
    'data' => $data,
  );
  $response = drupal_http_request($url . '/fetch', $options);
  if (!$response || floor($response->code / 100) != 2) {
    watchdog('agile_dirt_recipes', 'Check REST connectivity');
    return;
  }
  $objects = json_decode($response->data);
  if ($objects) {
    return theme('dirt_recipes_block', array('objects' => $objects, 'title' => $title));
  }
}

/**
 * Initiates rest call to retrieve recipes.
 */
function ah_dirt_recipe_get_recipes() {
  $query = $_GET['q'];
  $source = drupal_lookup_path("source", $query);
  $path = $source ? $source : $query;
  $node = menu_get_object("node", 1, $path);
  return ah_dirt_recipe_recipes_fetch($node->title);
}
