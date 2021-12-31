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

// Split key options:
#define F_SCL 400000
#define RGBLIGHT_SPLIT          // Synchronize RGB light modes

// RGB lighting options
#define RGBLED_NUM 48              // Total number of LEDs on both sides
#define RGBLIGHT_DISABLE_KEYCODES  // Only use RGB lighting for showing layers etc.

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
