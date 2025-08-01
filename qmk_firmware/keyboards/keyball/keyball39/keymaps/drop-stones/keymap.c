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

#include "keymap.h"

//====================
// Keymaps
//====================

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [_BASE] = LAYOUT_right_ball(
    KC_Q          , KC_W          , KC_E          , KC_R          , KC_T          ,                                   KC_Y            , KC_U      , KC_I              , KC_O            , KC_P     ,
    LCTL_T(KC_A)  , KC_S          , KC_D          , KC_F          , KC_G          ,                                   KC_H            , KC_J      , KC_K              , KC_L            , RCTL_T(KC_SCLN)  ,
    KC_Z          , LGUI_T(KC_X)  , LALT_T(KC_C)  , KC_V          , KC_B          ,                                   KC_N            , KC_M      , RALT_T(KC_COMM)   , RGUI_T(KC_DOT)  , KC_SLSH  ,
    KC_LSFT       , KC_ESC        , MO(_MOUSE)    , LT(1, KC_TAB) , LT(2, KC_ENT) , LT(3, KC_DEL) , LT(2, KC_BSPC)  , LT(1, KC_SPACE) ,                                                   KC_RSFT
  ),

  // Symbol Layser
  [_SYMBOLS] = LAYOUT_right_ball(
    S(KC_1) , S(KC_2)    , S(KC_3)    , S(KC_4)    , S(KC_5)   ,                      S(KC_6)    , S(KC_7)    , S(KC_8)    , S(KC_9)   , S(KC_0)    ,
    _______ , S(KC_BSLS) , S(KC_LBRC) , S(KC_RBRC) , S(KC_EQL) ,                      KC_MINS    , S(KC_QUOT) , KC_QUOT    , S(KC_GRV) , S(KC_SCLN) ,
    _______ , KC_BSLS    , KC_LBRC    , KC_RBRC    , KC_EQL    ,                      S(KC_MINS) , KC_GRV     , S(KC_COMM) , S(KC_DOT) , S(KC_SLSH) ,
    _______ , _______    , _______    , _______    , _______   , _______  , _______ , _______    ,                                       _______
  ),

  // Number/Arrow Layer
  [_NUMBERS] = LAYOUT_right_ball(
    KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,                      KC_6    , KC_7    , KC_8    , KC_9    , KC_0    ,
    _______ , _______ , _______ , _______ , _______ ,                      KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , KC_QUOT ,
    _______ , _______ , _______ , _______ , _______ ,                      KC_HOME , KC_PGDN , KC_PGUP , KC_END  , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______  , _______ , _______ ,                               _______
  ),

  // Function Key Layer
  [_FUNCTIONS] = LAYOUT_right_ball(
    KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   ,                      KC_F6    , KC_F7    , KC_F8   , KC_F9   , KC_F10  ,
    KC_F11  , KC_F12  , KC_F13  , KC_F14  , KC_F15  ,                      KC_F16   , KC_F17   , KC_F18  , KC_F19  , KC_F20  ,
    _______ , _______ , _______ , _______ , _______ ,                      CPI_D100 , CPI_I100 , KC_VOLD , KC_VOLU , KC_MUTE ,
    _______ , _______ , _______ , _______ , _______ , _______  , _______ , _______  ,                                _______
  ),

  // Mouse Layer
  [_MOUSE] = LAYOUT_right_ball(
    _______ , _______ , _______ , _______ , _______ ,                       _______  , _______  , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ ,                       KC_WBAK  , KC_BTN1  , KC_BTN2 , KC_WFWD , _______ ,
    _______ , _______ , _______ , _______ , _______ ,                       _______  , _______  , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______  , _______ ,  _______  ,                                _______
  ),
};
// clang-format on

//====================
// Key Overrides
//====================

// LCTRL + Enter => LCTRL + Space
const key_override_t lctl_enter_to_space = ko_make_basic(MOD_BIT(KC_LCTL), LT(2, KC_ENT), LCTL(KC_SPACE));

// RALT + Enter => RALT + Space
const key_override_t ralt_enter_to_space = ko_make_basic(MOD_BIT(KC_RALT), LT(2, KC_ENT), RALT(KC_SPACE));

const key_override_t *key_overrides[] = {
    &lctl_enter_to_space,
    &ralt_enter_to_space
};
