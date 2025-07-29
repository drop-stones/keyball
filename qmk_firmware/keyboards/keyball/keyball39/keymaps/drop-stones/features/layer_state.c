#include QMK_KEYBOARD_H

layer_state_t layer_state_set_user(layer_state_t state) {
  if (get_highest_layer(state) == 4) {
    // Auto enable scroll mode when the highest layer is 4
    keyball_set_scroll_mode(true);
    if (get_auto_mouse_enable() == true) {
      // Disable auto mouse layer to enable scroll
      set_auto_mouse_enable(false);
    }
  } else {
    // Reset default settings
    keyball_set_scroll_mode(false);
    if (get_auto_mouse_enable() == false) {
      set_auto_mouse_enable(true);
    }
  }
  return state;
}
