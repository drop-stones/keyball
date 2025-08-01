#include QMK_KEYBOARD_H

#include "keymap.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MO(_MOUSE):
      if (record->event.pressed) {
        keyball_set_scroll_mode(true);
      } else {
        keyball_set_scroll_mode(false);
      }
      return true;
    default:
      return true; // Process other keycodes normally
  }
}
