#include QMK_KEYBOARD_H

layer_state_t layer_state_set_user(layer_state_t state) {
  set_auto_mouse_enable(true);
  return state;
}
