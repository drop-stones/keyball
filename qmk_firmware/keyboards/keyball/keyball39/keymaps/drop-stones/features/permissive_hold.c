#ifdef PERMISSIVE_HOLD_PER_KEY

#include <stdint.h>

#include "quantum.h"
#include "action_tapping.h"

// Dual-role keys perform hold action if a dual-role key and another key are pressed within tapping term
// and another key is released first
// https://docs.qmk.fm/#/tap_hold?id=tapping-term
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
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
