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

// Like tap-dance, but only supports single tap or hold. Doesn't have latency
// for single taps.

#define HOLD_DANCE (SAFE_RANGE)
#define HOLD_DANCE_MAX (SAFE_RANGE + 0xff)
#define HT(keycode) (keycode + HOLD_DANCE)

typedef void (*hold_dance_user_fn_t)(void* user_data);

typedef struct {
    hold_dance_user_fn_t on_tap;
    hold_dance_user_fn_t on_hold;
    void* user_data;
    uint16_t timer;
    uint16_t keycode;
    bool running;
    uint8_t oneshot_mods;
    uint8_t weak_mods;
} hold_dance_state_t;

extern hold_dance_state_t hold_dance_states[];

bool process_record_hold_dance(uint16_t keycode, keyrecord_t* record);
void matrix_scan_hold_dance(void);
