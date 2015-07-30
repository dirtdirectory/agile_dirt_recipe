<?php
/**
 * @file
 * Template for full block.
 */
?>
<div class ="recipes_results_block">
  <p class ="dh_commons_intro">
    <?php print $intro; ?>
  </p>

  <ul class ="recipe_links">
    <?php foreach ($variables['recipe_links'] as $recipe_link): ?>
      <li class ="recipe_link"><?php print $recipe_link; ?></li>
    <?php endforeach; ?>
  </ul>
  <div class ="recipes_message"><?php print $count; ?></div>
  <div class ="recipes_message"><?php print $overflow; ?></div>
</div>