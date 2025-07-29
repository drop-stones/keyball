#ifdef QUICK_TAP_TERM_PER_KEY

#include <stdint.h>

#include "quantum.h"
#include "action_tapping.h"

// When the user holds a key after tapping it, the tapping function is repeated by default, rather than activating the hold function.
// https://docs.qmk.fm/tap_hold#quick-tap-term
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(1, KC_TAB): // Tab/Space may be tapped quickly but frequently typed so disable them
    case LT(1, KC_SPACE):
    case LT(2, KC_ENTER): // Enter must not be tapped quickly
      return 0;
    case LT(2, KC_BSPC):  // Delete/BackSpace must be tapped quickly
    case LT(3, KC_DEL):
      return QUICK_TAP_TERM_PER_KEY - 20;
    default:
      return QUICK_TAP_TERM;
  }
}

#endif
