/*
This is the c configuration file for the keymap

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

#pragma once

//====================
// Split Keyboard
//====================

// Side with lower matrix grid numbers is always recognized as the left hand
#define SPLIT_HAND_MATRIX_GRID_LOW_IS_LEFT

//====================
// Pointing Device
//====================

// Enable Automatic Mouse Layer
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE

//====================
// Tapping Term
//====================

// Wait n (ms) before key-up event (unregister_code) after key-down event (register code)
// This value is default in keyball39
#define TAP_CODE_DELAY 5

//====================
// Tapping Term
//====================

// Global settings in ms
#define TAPPING_TERM 150
#define TAPPING_TERM_PER_KEY

//====================
// Permissive Hold
//====================

#define PERMISSIVE_HOLD_PER_KEY

//====================
// Hold On Other Key Press
//====================

#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

//====================
// Quick Tap Term
//====================

#define QUICK_TAP_TERM 120
#define QUICK_TAP_TERM_PER_KEY

//====================
// Caps Word
//====================

// Activate Caps Word by pressing Left Shift + Right Shift
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

//====================
// VIA/VIAL
//====================

// Defines the number of layers that are available
#define DYNAMIC_KEYMAP_LAYER_COUNT 5
