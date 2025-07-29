#ifdef RETRO_TAPPING_PER_KEY

#include <stdint.h>

#include "quantum.h"
#include "action_tapping.h"

// Holding and releasing keys without pressing another key will result tapping
// https://docs.qmk.fm/#/tap_hold?id=retro-tapping
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    default:
      return false;
  }
}

#endif
