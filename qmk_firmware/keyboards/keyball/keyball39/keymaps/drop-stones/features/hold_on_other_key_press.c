#ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#include <stdint.h>

#include "quantum.h"
#include "action_tapping.h"

// Dual-role keys perform hold action if a dual-role key and another key are pressed within tapping term
// and a dual-role key is released first
// https://docs.qmk.fm/#/tap_hold?id=tapping-term
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(1, KC_TAB): // Layer keys perform a hold action preferentially
    case LT(2, KC_ENTER):
    case LT(3, KC_DEL):
    case LT(1, KC_SPACE):
    case LT(2, KC_BSPC):
      return true;
    default:
      return false;
  }
}

#endif
