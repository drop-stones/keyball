/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_Q          , KC_W          , KC_E          , KC_R          , KC_T          ,                                   KC_Y            , KC_U      , KC_I              , KC_O            , KC_P     ,
    LCTL_T(KC_A)  , KC_S          , KC_D          , KC_F          , KC_G          ,                                   KC_H            , KC_J      , KC_K              , KC_L            , RCTL_T(KC_SCLN)  ,
    KC_Z          , LWIN_T(KC_X)  , LALT_T(KC_C)  , KC_V          , KC_B          ,                                   KC_N            , KC_M      , RALT_T(KC_COMM)   , RWIN_T(KC_DOT)  , KC_SLSH  ,
    KC_LSFT       , KC_ESC        , MO(4)         , LT(1, KC_TAB) , LT(2, KC_ENT) , LT(3, KC_DEL) , LT(2, KC_BSPC)  , LT(1, KC_SPACE) , _______   , _______           , _______         , KC_RSFT
  ),

  // Symbol Layser
  [1] = LAYOUT_universal(
    S(KC_1) , S(KC_2)    , S(KC_3)    , S(KC_4)    , S(KC_5)   ,                      S(KC_6)    , S(KC_7)    , S(KC_8)    , S(KC_9)   , S(KC_0)    ,
    _______ , S(KC_BSLS) , S(KC_LBRC) , S(KC_RBRC) , S(KC_EQL) ,                      KC_MINS    , S(KC_QUOT) , KC_QUOT    , S(KC_GRV) , S(KC_SCLN) ,
    _______ , KC_BSLS    , KC_LBRC    , KC_RBRC    , KC_EQL    ,                      S(KC_MINS) , KC_GRV     , S(KC_COMM) , S(KC_DOT) , S(KC_SLSH) ,
    _______ , _______    , _______    , _______    , _______   , _______  , _______ , _______    , _______    , _______    , _______   , _______
  ),

  // Number/Arrow Layer
  [2] = LAYOUT_universal(
    KC_1   , KC_2    , KC_3    , KC_4    , KC_5    ,                      KC_6    , KC_7    , KC_8    , KC_9    , KC_0    ,
    _______ , _______ , _______ , _______ , _______ ,                      KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , KC_QUOT ,
    _______ , _______ , _______ , _______ , _______ ,                      KC_HOME , KC_PGDN , KC_PGUP , KC_END  , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______  , _______ , _______ , _______ , _______ , _______ , _______
  ),

  // Function Key Layer
  [3] = LAYOUT_universal(
    KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   ,                      KC_F6    , KC_F7    , KC_F8   , KC_F9   , KC_F10  ,
    KC_F11  , KC_F12  , KC_F13  , KC_F14  , KC_F15  ,                      KC_F16   , KC_F17   , KC_F18  , KC_F19  , KC_F20  ,
    _______ , _______ , _______ , _______ , _______ ,                      CPI_D100 , CPI_I100 , KC_VOLD , KC_VOLU , KC_MUTE ,
    _______ , _______ , _______ , _______ , _______ , _______  , _______ , _______  , _______  , _______ , _______ , _______
  ),

  // Scroll/Mouse Layer
  [4] = LAYOUT_universal(
    _______ , _______ , _______ , _______ , _______ ,                       _______  , _______  , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,                       KC_WBAK  , KC_BTN1  , KC_BTN2 , KC_WFWD , _______ ,
    _______ , _______ , _______ , _______ , _______ ,                       _______  , _______  , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______  , _______ ,  _______  , _______  , _______ , _______ , _______
  ),

  // Auto Mouse Layer
  [5] = LAYOUT_universal(
    _______ , _______ , _______ , _______ , _______ ,                       _______  , _______  , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,                       KC_WBAK  , KC_BTN1  , KC_BTN2 , KC_WFWD , _______ ,
    _______ , _______ , _______ , _______ , _______ ,                       _______  , _______  , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______  , _______ ,  _______  , _______  , _______ , _______ , _______
  ),
};
// clang-format on

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

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

// ------------------------------------------------------------------------
// drop-stones' customizations
// ------------------------------------------------------------------------

// Programming the behavior of any keycodes
// https://docs.qmk.fm/#/custom_quantum_functions?id=programming-the-behavior-of-any-keycode
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(2, KC_ENTER):
            if (record->tap.count && record->event.pressed) {
                // CTRL/SHIFT/ALT/GUI + Enter => CTRL/SHIFT/ALT/GUI + Space
                if (get_mods() & MOD_MASK_CSAG) {
                    tap_code16(KC_SPACE);
                    return false;
                }
            }
    }
    return true;
};

#ifdef TAPPING_TERM_PER_KEY
#    include "action_tapping.h"
#    include <stdint.h>

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

#ifdef RETRO_TAPPING_PER_KEY
#    include "action_tapping.h"
#    include <stdint.h>

// Holding and releasing keys without pressing another key will result tapping
// https://docs.qmk.fm/#/tap_hold?id=retro-tapping
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return false;
    }
}
#endif

#ifdef PERMISSIVE_HOLD_PER_KEY
#    include "action_tapping.h"
#    include <stdint.h>

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

#ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#    include "action_tapping.h"
#    include <stdint.h>

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

#ifdef QUICK_TAP_TERM_PER_KEY
#    include "action_tapping.h"
#    include <stdint.h>

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

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
// https://docs.qmk.fm/#/feature_pointing_device?id=pointing-device-auto-mouse
void pointing_device_init_user(void) {
    set_auto_mouse_enable(true); // always required before the auto mouse feature will work
}
#endif
