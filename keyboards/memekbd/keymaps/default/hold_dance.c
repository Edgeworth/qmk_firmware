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

#include QMK_KEYBOARD_H
#include "hold_dance.h"

static uint16_t last_hd_keycode = 0;
static uint16_t max_idx = 0;

bool hold_dance_elapsed(hold_dance_state_t *state) {
    if (!state->running) return false;
    uint16_t elapsed = timer_elapsed(state->timer);
    return elapsed > TAPPING_TERM;
}

void finish_hold_dance(hold_dance_state_t *state) {
    add_mods(state->oneshot_mods);
    add_weak_mods(state->weak_mods);
    send_keyboard_report();

    bool hold = hold_dance_elapsed(state);
    if (hold)
        audio_play_click(0, NOTE_C5, 80);

    hold_dance_user_fn_t fn = hold ? state->on_hold : state->on_tap;
    fn(state->user_data);

    del_mods(state->oneshot_mods);
    del_weak_mods(state->weak_mods);
    send_keyboard_report();

    state->timer = 0;
    state->keycode = 0;
    state->running = false;
    state->oneshot_mods = 0;
    state->weak_mods = 0;
    last_hd_keycode = 0;
}

bool process_record_hold_dance(uint16_t keycode, keyrecord_t* record) {
    // Process interrupted hold-dance:
    for (uint16_t i = 0; i < max_idx; i++) {
        hold_dance_state_t* state = &hold_dance_states[i];
        // Hold-dance was interrupted by another key:
        if (state->running && last_hd_keycode != keycode) {
            finish_hold_dance(state);
            clear_weak_mods();
        }
    }

    // Process new hold-dance:
    if (keycode >= HOLD_DANCE && keycode <= HOLD_DANCE_MAX) {
        uint16_t idx = keycode - HOLD_DANCE;
        if (idx >= max_idx) max_idx = idx + 1;
        hold_dance_state_t* state = &hold_dance_states[idx];
        if (record->event.pressed) {
            // Started a hold-dance.
            state->timer = timer_read();
            state->keycode = keycode;
            state->running = true;
            state->oneshot_mods = get_oneshot_mods();
            state->weak_mods = get_mods() | get_weak_mods();
            last_hd_keycode = keycode;
        } else if (state->running) {
            // Ended a hold-dance.
            finish_hold_dance(state);

        }
    }
    return true;
}

void matrix_scan_hold_dance(void) {
    for (uint16_t i = 0; i < max_idx; i++) {
        hold_dance_state_t* state = &hold_dance_states[i];
        // If the key is pressed, check the timeout.
        if (hold_dance_elapsed(state))
            finish_hold_dance(state);
    }
}
