<?php

/**
 * @file
 * ah_admin.form.inc
 */

/**
 * Admin form.
 *
 * @return array
 *   Returns admin form.
 */
function ah_dirt_recipe_admin() {
  $form = array();
  $form['ah_recipes_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('API Key'),
    '#default_value' => variable_get('ah_recipes_api_key', ''),
    '#description' => t('API Key to access Recipes'),
  );
  $form['ah_dirt_recipe_recipes_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Recipes URL'),
    '#default_value' => variable_get('ah_dirt_recipe_recipes_url', 'http://dev-hermeneutica-d7.pantheon.berkeley.edu'),
    '#description' => t('URL of Recipe site.'),
  );
  $form['ah_dirt_recipe_recipes_site_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name of Recipes site'),
    '#default_value' => variable_get('ah_dirt_recipe_recipes_site_name', 'Recipes'),
    '#description' => t('Name of Recipes site supplying recipe information.'),
  );
  $form['ah_dirt_recipe_recipes_rest_path'] = array(
    '#type' => 'textfield',
    '#title' => t('REST Path'),
    '#default_value' => variable_get('ah_dirt_recipe_recipes_rest_path', 'rest'),
    '#description' => t('rest path - as provided by DHCommon administrator'),
  );
  $form['ah_dirt_recipe_recipes_alias'] = array(
    '#type' => 'textfield',
    '#title' => t('Alias'),
    '#default_value' => variable_get('ah_dirt_recipe_recipes_alias', 'recipe'),
    '#description' => t('alias - as provided by DHCommon administrator'),
  );
  $form['ah_dirt_recipe_recipes_taxonomy'] = array(
    '#type' => 'textfield',
    '#title' => t('Taxonomy'),
    '#default_value' => variable_get('ah_dirt_recipe_recipes_taxonomy', 'tools'),
    '#description' => t('taxonomy - as provided by DHCommon administrator'),
  );
  $form['ah_dirt_recipe_recipes_site_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Project Site Name'),
    '#default_value' => variable_get('ah_dirt_recipe_recipes_site_name', 'Recipes'),
    '#description' => t('Name of the site providing recipe information'),
  );
  $form['ah_dirt_recipe_recipe_count'] = array(
    '#type' => 'textfield',
    '#title' => t('Recipe Count'),
    '#default_value' => variable_get('ah_dirt_recipe_recipe_count', 5),
    '#description' => t('Maximum number of recipes to be shown in Recipes Tab on term view.'),
  );
  $form['ah_dirt_recipe_recipes_sort'] = array(
    '#type' => 'radios',
    '#title' => t('Sort by'),
    '#default_value' => variable_get('ah_dirt_recipe_recipes_sort', 'timestamp'),
    '#description' => t('Sort field for returned results'),
    '#options' => array(
      'timestamp' => t('Timestamp'),
      'title' => t('Title'),
    ),
  );
  return system_settings_form($form);
}
