/*
Copyright 2021 Edgeworth

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

#include "config_common.h"

// USB Device descriptor parameter
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x0EDC
#define DEVICE_VER 0x0002
#define MANUFACTURER Edgeworth
#define PRODUCT memekbd

// Key matrix options:
#define MATRIX_ROWS 10
#define MATRIX_COLS 5
#define MATRIX_ROW_PINS \
    { F4, F5, F6, F7, B1 }
#define MATRIX_COL_PINS \
    { D4, C6, D7, E6, B4 }
#define DIODE_DIRECTION COL2ROW

// Split key options:
#define USE_I2C
#define F_SCL 400000
#define SPLIT_MODS_ENABLE       // Send key data to other side - needed for RGB.
#define SPLIT_TRANSPORT_MIRROR  // Send key data to other side - needed for RGB.
#define RGBLIGHT_SPLIT          // Synchronize RGB light modes
#define RGBLED_SPLIT \
    { 24, 24 }            // Number of RGB LEDS (left, right).
#define SPLIT_USB_DETECT  // Detect which side is the main side via USB.

// RGB lighting options
#define RGB_DI_PIN D3              // LED data pin
#define RGBLED_NUM 48              // Total number of LEDs on both sides
#define RGBLIGHT_LIMIT_VAL 40      // Limit maximum brightness to keep power usage lower.
#define RGBLIGHT_SLEEP             // Switch off RGB when host sleeps.
#define RGBLIGHT_DISABLE_KEYCODES  // Only use RGB lighting for showing layers etc.
#define RGBLIGHT_LAYERS            // Change RGB lighting depending on the layer.
#define RGBLIGHT_MAX_LAYERS 5      // 5 layers max
#define RGBLIGHT_DEFAULT_HUE 128

#define LED_LAYOUT( \
    l00, l01, l02, l03, l04, r00, r01, r02, r03, r04, \
    l10, l11, l12, l13, l14, r10, r11, r12, r13, r14, \
    l20, l21, l22, l23, l24, r20, r21, r22, r23, r24, \
    l30, l31, l32, l33, l34, r30, r31, r32, r33, r34, \
    l40, l41, l42, l43,      r40, r41, r42, r43       \
) { \
    l00, l01, l02, l03, l04, \
    l10, l11, l12, l13, l14, \
    l20, l21, l22, l23, l24, \
    l30, l31, l32, l33, l34, \
    l40, l41, l42, l43,      \
    r00, r01, r02, r03, r04, \
    r10, r11, r12, r13, r14, \
    r20, r21, r22, r23, r24, \
    r30, r31, r32, r33, r34, \
    r40, r41, r42, r43       \
}


#define RGBLIGHT_LED_MAP LED_LAYOUT( \
    0,  1,  2, 3, 4,       24, 25, 26, 27, 28, \
    5,  6,  7, 8, 9,       29, 30, 31, 32, 33, \
    10, 11, 12, 13, 14,    34, 35, 36, 37, 38, \
    15, 16, 17, 18, 19,    39, 40, 41, 42, 43, \
    20, 21, 22, 23,        44, 45, 46, 47      \
)

// Audio options:
#define AUDIO_PIN B5
#define AUDIO_INIT_DELAY  // Delay a bit at startup to fix audio issues from USB startup

#ifdef AUDIO_ENABLE
// #define STARTUP_SONG SONG(NO_SOUND)
// #define GOODBYE_SONG SONG(NO_SOUND)
#endif  // AUDIO_ENABLE

// Poll at 1000 Hz
#define USB_POLLING_INTERVAL_MS 1

// Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed
#define DEBOUNCE 8

// Disable these deprecated features by default.
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// Key typing features:

#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 180
#define PERMISSIVE_HOLD
