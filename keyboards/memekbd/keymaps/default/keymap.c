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
#include QMK_KEYBOARD_H

#include "hold_dance.h"

enum {
    HT_A,
    HT_B,
    HT_C,
    HT_D,
    HT_E,
    HT_F,
    HT_G,
    HT_H,
    HT_I,
    HT_J,
    HT_K,
    HT_L,
    HT_M,
    HT_N,
    HT_O,
    HT_P,
    HT_R,
    HT_S,
    HT_T,
    HT_U,
    HT_V,
    HT_X,
    HT_Y
};

// Defines names for use in layer keycodes and the keymap
enum {
    LAYER_BASE,
    LAYER_SYM,
    LAYER_NAV,
    LAYER_FUNC,
    LAYER_QWERTY,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT(
        KC_Q,    KC_W,    HT(HT_E),HT(HT_R),HT(HT_T),HT(HT_Y),HT(HT_U),HT(HT_I),HT(HT_O),HT(HT_P),
        HT(HT_A),HT(HT_S),HT(HT_D),HT(HT_F),HT(HT_G),HT(HT_H),HT(HT_J),HT(HT_K),HT(HT_L),KC_SCLN,
        KC_Z,    HT(HT_X),HT(HT_C),HT(HT_V),HT(HT_B),HT(HT_N),HT(HT_M),KC_COMM, KC_DOT,  KC_SLSH,
        KC_LGUI, MO(LAYER_SYM), LSFT_T(KC_SPACE), LCTL_T(KC_BSPC), LALT_T(KC_ESCAPE),
        LALT_T(KC_ESCAPE), LCTL_T(KC_TAB), LSFT_T(KC_ENTER), MO(LAYER_NAV), KC_LGUI,
        KC_MPRV, TT(LAYER_QWERTY), KC_MPLY, KC_MNXT,
        LSFT(LCTL(KC_TAB)), KC_VOLU, KC_VOLD, LCTL(KC_TAB)
    ),
    [LAYER_SYM] = LAYOUT(
        KC_PIPE, KC_DQUO, KC_LCBR, KC_RCBR, KC_UNDS, KC_HASH, KC_7,    KC_8,    KC_9,    KC_EXLM,
        KC_AMPR, KC_QUOT, KC_LPRN, KC_RPRN, KC_EQL,  KC_0,    KC_4,    KC_5,    KC_6,    KC_MINS,
        KC_ASTR, KC_GRV,  KC_LBRC, KC_RBRC, KC_BSLS, KC_DLR,  KC_1,    KC_2,    KC_3,    KC_PLUS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(LAYER_FUNC), KC_TRNS,
        KC_TRNS, MO(LAYER_FUNC), KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [LAYER_NAV] = LAYOUT(
        KC_AT,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TILD,
        KC_PERC, KC_BTN2, KC_BTN3, KC_BTN1, KC_INS,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CIRC,
        KC_TRNS, KC_ACL2, KC_ACL1, KC_ACL0, KC_DEL,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS,
        KC_TRNS, MO(LAYER_FUNC), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, MO(LAYER_FUNC), KC_TRNS, KC_TRNS

    ),
    [LAYER_FUNC] = LAYOUT(
        KC_NO,   RGB_SAD, RGB_SAI, KC_MPRV, KC_MNXT, KC_PSCR, KC_F7,   KC_F8,   KC_F9,   KC_F12,
        RGB_TOG, RGB_VAD, RGB_VAI, KC_VOLD, KC_VOLU, KC_SCRL, KC_F4,   KC_F5,   KC_F6,   KC_F11,
        KC_TRNS, RGB_HUD, RGB_HUI, KC_MPLY, KC_MUTE, KC_PAUS, KC_F1,   KC_F2,   KC_F3,   KC_F10,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [LAYER_QWERTY] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_0,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7
    )
};

// Hold-dance setup:
typedef struct {
    uint16_t tap_keycode;
    uint16_t hold_keycode;
} hd_key_state;

void hd_on_tap(void *user_data) {
    hd_key_state* state = user_data;
    tap_code16(state->tap_keycode);
}

void hd_on_hold(void *user_data) {
    hd_key_state* state = user_data;
    tap_code16(state->hold_keycode);
}

hold_dance_state_t hold_dance_states[] = {
    [HT_A] = {
        .on_tap = hd_on_tap,
        .on_hold = hd_on_hold,
        .user_data = (void*)&((hd_key_state){KC_A, LCTL(KC_A)})
    },
    [HT_B] = {
        .on_tap = hd_on_tap,
        .on_hold = hd_on_hold,
        .user_data = (void*)&((hd_key_state){KC_B, LCTL(KC_B)})
    },
    [HT_C] = {
        .on_tap = hd_on_tap,
        .on_hold = hd_on_hold,
        .user_data = (void*)&((hd_key_state){KC_C, LCTL(KC_INS)})
    },
    [HT_D] = {
        .on_tap = hd_on_tap,
        .on_hold = hd_on_hold,
        .user_data = (void*)&((hd_key_state){KC_D, LCTL(KC_D)})
    },
    [HT_E] = {
        .on_tap = hd_on_tap,
        .on_hold = hd_on_hold,
        .user_data = (void*)&((hd_key_state){KC_E, LCTL(KC_E)})
    },
    [HT_F] = {
        .on_tap = hd_on_tap,
        .on_hold = hd_on_hold,
        .user_data = (void*)&((hd_key_state){KC_F, LCTL(KC_F)})
    },
    [HT_G] = {
        .on_tap = hd_on_tap,
        .on_hold = hd_on_hold,
        .user_data = (void*)&((hd_key_state){KC_G, LCTL(KC_G)})
    },
    [HT_H] = {
        .on_tap = hd_on_tap,
        .on_hold = hd_on_hold,
        .user_data = (void*)&((hd_key_state){KC_H, LCTL(KC_H)})
    },
    [HT_I] = {
        .on_tap = hd_on_tap,
        .on_hold = hd_on_hold,
        .user_data = (void*)&((hd_key_state){KC_I, LCTL(KC_I)})
    },
    [HT_J] = {
        .on_tap = hd_on_tap,
        .on_hold = hd_on_hold,
        .user_data = (void*)&((hd_key_state){KC_J, LCTL(KC_J)})
    },
    [HT_K] = {
        .on_tap = hd_on_tap,
        .on_hold = hd_on_hold,
        .user_data = (void*)&((hd_key_state){KC_K, LCTL(KC_K)})
    },
    [HT_L] = {
        .on_tap = hd_on_tap,
        .on_hold = hd_on_hold,
        .user_data = (void*)&((hd_key_state){KC_L, LCTL(KC_L)})
    },
    [HT_M] = {
        .on_tap = hd_on_tap,
        .on_hold = hd_on_hold,
        .user_data = (void*)&((hd_key_state){KC_M, LCTL(KC_M)})
    },
    [HT_N] = {
        .on_tap = hd_on_tap,
        .on_hold = hd_on_hold,
        .user_data = (void*)&((hd_key_state){KC_N, LCTL(KC_N)})
    },
    [HT_O] = {
        .on_tap = hd_on_tap,
        .on_hold = hd_on_hold,
        .user_data = (void*)&((hd_key_state){KC_O, LCTL(KC_O)})
    },
    [HT_P] = {
        .on_tap = hd_on_tap,
        .on_hold = hd_on_hold,
        .user_data = (void*)&((hd_key_state){KC_P, LCTL(KC_P)})
    },
    [HT_R] = {
        .on_tap = hd_on_tap,
        .on_hold = hd_on_hold,
        .user_data = (void*)&((hd_key_state){KC_R, LCTL(KC_R)})
    },
    [HT_S] = {
        .on_tap = hd_on_tap,
        .on_hold = hd_on_hold,
        .user_data = (void*)&((hd_key_state){KC_S, LCTL(KC_S)})
    },
    [HT_T] = {
        .on_tap = hd_on_tap,
        .on_hold = hd_on_hold,
        .user_data = (void*)&((hd_key_state){KC_T, LCTL(KC_T)})
    },
    [HT_U] = {
        .on_tap = hd_on_tap,
        .on_hold = hd_on_hold,
        .user_data = (void*)&((hd_key_state){KC_U, LCTL(KC_U)})
    },
    [HT_V] = {
        .on_tap = hd_on_tap,
        .on_hold = hd_on_hold,
        .user_data = (void*)&((hd_key_state){KC_V, LSFT(KC_INS)})
    },
    [HT_X] = {
        .on_tap = hd_on_tap,
        .on_hold = hd_on_hold,
        .user_data = (void*)&((hd_key_state){KC_X, LCTL(KC_X)})
    },
    [HT_Y] = {
        .on_tap = hd_on_tap,
        .on_hold = hd_on_hold,
        .user_data = (void*)&((hd_key_state){KC_Y, LCTL(KC_Y)})
    }
    // No Q, Z, or W.
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    return process_record_hold_dance(keycode, record);
}

void matrix_scan_user(void) {
    matrix_scan_hold_dance();
}

void keyboard_post_init_user(void) {
#if defined(CONSOLE_ENABLE)
    debug_enable = true;
    debug_matrix = true;
    debug_keyboard = true;
    debug_mouse = true;
#endif
}
