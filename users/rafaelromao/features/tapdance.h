/* Copyright 2021 Rafael Romão @rafaelromao
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

#include QMK_KEYBOARD_H

#include "../definitions/keycodes.h"
#include "os_toggle.h"
#include "default_mod_key.h"

enum {
    DOT_COM,
    MOU_B13,
    MOU_B24,
    INJ_LEF,
    INJ_RIG
};

#define TD_DOT  TD(DOT_COM)
#define TD_MB13 TD(MOU_B13)
#define TD_MB24 TD(MOU_B24)
#define TD_IJLE TD(INJ_LEF)
#define TD_IJRI TD(INJ_RIG)

typedef enum {
    TD_NONE,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD
} td_state_t;

typedef struct {
    td_state_t state;
} td_tap_t;

td_state_t dance_state(qk_tap_dance_state_t *state);

void td_dot_com_finished(qk_tap_dance_state_t *state, void *user_data);
void td_dot_com_reset(qk_tap_dance_state_t *state, void *user_data);

void td_mou_b13_finished(qk_tap_dance_state_t *state, void *user_data);
void td_mou_b13_reset(qk_tap_dance_state_t *state, void *user_data);
void td_mou_b24_finished(qk_tap_dance_state_t *state, void *user_data);
void td_mou_b24_reset(qk_tap_dance_state_t *state, void *user_data);

void td_inj_lef(qk_tap_dance_state_t *state, void *user_data);
void td_inj_rig(qk_tap_dance_state_t *state, void *user_data);
