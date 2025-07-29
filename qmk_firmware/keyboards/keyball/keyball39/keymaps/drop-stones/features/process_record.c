#include "quantum.h"

// Programming the behavior of any keycodes
// https://docs.qmk.fm/#/custom_quantum_functions?id=programming-the-behavior-of-any-keycode
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(2, KC_ENTER):
      if (record->tap.count && record->event.pressed) {
        // LCTRL/RALT + Enter => LCTRL/RALT + Space
        if (get_mods() & (MOD_BIT(KC_LCTL) | MOD_BIT(KC_RALT))) {
          tap_code16(KC_SPACE);
          return false;
        }
      }
  }
  return true;
};
