#ifdef TAPPING_TERM_PER_KEY

#include <stdint.h>

#include "quantum.h"
#include "action_tapping.h"

// Time to determines what is a tap and what is a hold
// https://docs.qmk.fm/#/tap_hold?id=tapping-term
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LWIN_T(KC_X): // Win keys are not typed quickly
    case RWIN_T(KC_DOT):
      return 200;
    default:
      return TAPPING_TERM;
  }
}

#endif
