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
#include "quantum_keycodes.h"
#include "keyball44.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    _______  , KC_Q         , KC_W         , KC_E          , KC_R          , KC_T          ,                   KC_Y           , KC_U            , KC_I            , KC_O           , KC_P            , _______ ,
    _______  , LCTL_T(KC_A) , KC_S         , KC_D          , KC_F          , KC_G          ,                   KC_H           , KC_J            , KC_K            , KC_L           , RCTL_T(KC_SCLN) , _______ ,
    _______  , LSFT_T(KC_Z) , LWIN_T(KC_X) , LALT_T(KC_C)  , KC_V          , KC_B          ,                   KC_N           , KC_M            , RALT_T(KC_COMM) , RWIN_T(KC_DOT) , RSFT_T(KC_SLSH) , _______ ,
               KC_LWIN      , KC_LALT      , LT(1, KC_TAB) , LT(2, KC_ENT) , LT(3, KC_DEL) ,                   LT(2, KC_BSPC) , LT(1, KC_SPACE) , _______         , _______        , KC_ESC
  ),

  [1] = LAYOUT_universal(
    _______  ,  S(KC_1) , S(KC_2)    , S(KC_3)    , S(KC_4)    , S(KC_5)   ,                    S(KC_6)    , S(KC_7)    , S(KC_8)    , S(KC_9)   , S(KC_0)    , _______ ,
    _______  ,  _______ , S(KC_BSLS) , S(KC_LBRC) , S(KC_RBRC) , S(KC_EQL) ,                    KC_MINS    , S(KC_QUOT) , KC_QUOT    , S(KC_GRV) , S(KC_SCLN) , _______ ,
    _______  ,  _______ , KC_BSLS    , KC_LBRC    , KC_RBRC    , KC_EQL    ,                    S(KC_MINS) , KC_GRV     , S(KC_COMM) , S(KC_DOT) , S(KC_SLSH) , _______ ,
                _______ , _______    , _______    , _______    , _______   ,                    _______    , _______    , _______    , _______   , _______
  ),

  [2] = LAYOUT_universal(
    _______  ,  KC_1   , KC_2    , KC_3    , KC_4    , KC_5    ,                    KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , _______ ,
    _______  , _______ , _______ , _______ , _______ , _______ ,                    KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , KC_QUOT , _______ ,
    _______  , _______ , _______ , _______ , _______ , _______ ,                    KC_HOME , KC_PGDN , KC_PGUP , KC_END  , _______ , _______ ,
               _______ , _______ , _______ , _______ , _______ ,                    _______ , _______ , _______ , _______ , _______
  ),

  [3] = LAYOUT_universal(
    _______  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   ,                    KC_F6    , KC_F7    , KC_F8   , KC_F9   , KC_F10  , _______ ,
    _______  , KC_F11  , KC_F12  , KC_F13  , KC_F14  , KC_F15  ,                    KC_F16   , KC_F17   , KC_F18  , KC_F19  , KC_F20  , _______ ,
    _______  , _______ , _______ , _______ , _______ , _______ ,                    CPI_D100 , CPI_I100 , KC_VOLD , KC_VOLU , KC_MUTE , _______ ,
               _______ , _______ , _______ , _______ , _______ ,                    _______  , _______  , _______ , _______ , _______
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
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
                // CTRL + Enter => CTRL + Space
                if (get_mods() == MOD_BIT(KC_LCTL)) {
                    tap_code16(KC_SPACE);
                    return false;
                }

                // ALT + Enter => ALT + Space
                if (get_mods() == MOD_BIT(KC_RALT)) {
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
        case LSFT_T(KC_Z): // Shift keys are typed quickly
        case RSFT_T(KC_SLSH):
            return 100;
        case LWIN_T(KC_X): // Win keys are not typed quickly
        case RWIN_T(KC_DOT):
            return 250;
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
        case LCTL_T(KC_A): // CTRL/ALT/SHIFT keys perform a tap action unless another key is pressed
        case LSFT_T(KC_Z):
        case LALT_T(KC_C):
        case RCTL_T(KC_SCLN):
        case RSFT_T(KC_SLSH):
        case RALT_T(KC_COMM):
            return true;
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
