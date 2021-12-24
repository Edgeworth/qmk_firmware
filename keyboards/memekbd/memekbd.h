/* Copyright 2021 Edgeworth
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
         l00, l01, l02,           r00, r01, r02,      \
    l10, l11, l12, l13, l14, r10, r11, r12, r13, r14, \
    l20, l21, l22, l23, l24, r20, r21, r22, r23, r24, \
    l30, l31, l32, l33, l34, r30, r31, r32, r33, r34, \
    l40, l41, l42, l43, l44, r40, r41, r42, r43, r44 \
) { \
    { KC_NO, l00, l01, l02, KC_NO }, \
    { l10, l11, l12, l13, l14 }, \
    { l20, l21, l22, l23, l24 }, \
    { l30, l31, l32, l33, l34 }, \
    { l40, l41, l42, l43, l44 }, \
    { KC_NO, r00, r01, r02, KC_NO }, \
    { r10, r11, r12, r13, r14 }, \
    { r20, r21, r22, r23, r24 }, \
    { r30, r31, r32, r33, r34 }, \
    { r40, r41, r42, r43, r44 } \
}
