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
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                            KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                            KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  ,
    KC_LCTL  , KC_LGUI  , KC_LALT  ,LT(1,KC_LNG2),LT(2,KC_SPC),LT(3,KC_LNG1),KC_BSPC,LT(2,KC_ENT),LT(1,KC_LNG2),KC_RALT,KC_RGUI, KC_RSFT
  ),

  [1] = LAYOUT_universal(
    S(KC_Q)   , S(KC_W) , S(KC_E)  , S(KC_R)  , S(KC_T)  ,                            S(KC_Y)  , S(KC_U)  , S(KC_I)  , S(KC_O)  , S(KC_P)  ,
    S(KC_A)   , S(KC_S) , S(KC_D)  , S(KC_F)  , S(KC_G)  ,                            S(KC_H)  , S(KC_J)  , S(KC_K)  , S(KC_L)  , KC_QUOT  ,
    S(KC_Z)   , S(KC_X) , S(KC_C)  , S(KC_V)  , S(KC_B)  ,                            S(KC_N)  , S(KC_M)  ,S(KC_COMM), S(KC_DOT),S(KC_SLSH),
    KC_LCTL   , KC_LGUI , KC_LALT  , _______  , _______  , _______  ,      _______  , _______  , _______  , KC_RALT  , KC_RGUI  , KC_RSFT
  ),

  [2] = LAYOUT_universal(
    _______   , KC_7    , KC_8     , KC_9     , _______  ,                            _______  , KC_LEFT  , KC_UP    , KC_RGHT  , _______  ,
    _______   , KC_4    , KC_5     , KC_6     ,S(KC_SCLN),                            KC_PGUP  , KC_BTN1  , KC_DOWN  , KC_BTN2  , KC_BTN3  ,
    _______   , KC_1    , KC_2     , KC_3     ,S(KC_MINS),                            KC_PGDN  , _______  , _______  , _______  , _______  ,
    _______   , KC_0    , KC_DOT   , _______  , _______  , _______  ,      KC_DEL   , _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  , _______  , _______  , _______  ,  _______  ,                           RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  ,  SCRL_DVI ,                           RGB_M_K  , RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  ,  SCRL_DVD ,                           CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
    QK_BOOT    , KBC_RST  , _______  , _______  ,  _______  , _______  ,     _______  , _______  , _______  , _______  , KBC_RST  , QK_BOOT
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
        case LSFT_T(KC_Z): // "z" are shift key but typed normally
            return TAPPING_TERM;
        case RSFT_T(KC_SLSH): // Shift keys are typed quickly
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

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
// https://docs.qmk.fm/#/feature_pointing_device?id=pointing-device-auto-mouse
void pointing_device_init_user(void) {
    set_auto_mouse_enable(true); // always required before the auto mouse feature will work
}
#endif
