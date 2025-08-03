#include QMK_KEYBOARD_H

#include "keymap.h"

bool is_key_tapped(keyrecord_t *record) {
  return record->event.pressed && !record->tap.interrupted && record->tap.count > 0;
}

bool is_mod_held(uint16_t mod) {
  return (get_mods() & MOD_BIT(mod)) != 0;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MO(_MOUSE): // Mouse scroll mode
      if (record->event.pressed) {
        keyball_set_scroll_mode(true);
      } else {
        keyball_set_scroll_mode(false);
      }
      return true;
    case LT(2, KC_ENT): // Modifier + Enter => Modifier + Space
      // Don't use key overrides to act as the LT(2) key when held down
      if (is_key_tapped(record) && (is_mod_held(KC_LCTL) || is_mod_held(KC_RALT))) {
        tap_code(KC_SPACE);
        return false; // Prevent default processing of this keycode
      }
      return true;
    default:
      return true; // Process other keycodes normally
  }
}
