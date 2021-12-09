<?php
/**
 * @file
 * Volume Pricing administration pages.
 */

/**
 * Implements hook_admin().
 *
 * Store-wide uc_volume-pricing settings.
 */
function uc_volume_pricing_admin() {
  $config = config('uc_volume_pricing.settings');
  $form = array();
  $form['#config'] = 'uc_volume_pricing.settings';

  $form['show_in_cart'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show possible savings message in cart review.'),
    '#default_value' => $config->get('show_in_cart'),
  );

  $form['cart_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Savings message.'),
    '#default_value' => $config->get('cart_message'),
    '#description' => t('Available tokens are: [remaining], [product_title] and [savings]'),
  );

  return system_settings_form($form);
}
