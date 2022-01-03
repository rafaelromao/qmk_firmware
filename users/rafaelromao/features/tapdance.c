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

#include QMK_KEYBOARD_H

#include "tapdance.h"

extern os_t os;

static td_tap_t tap_state = {
    .state = TD_NONE
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [DOT_COM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_dot_com_finished, td_dot_com_reset),
    [MOU_B13] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mou_b13_finished, td_mou_b13_reset),
    [MOU_B24] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mou_b24_finished, td_mou_b24_reset),
    [INJ_LEF] = ACTION_TAP_DANCE_FN(td_inj_lef),
    [INJ_RIG] = ACTION_TAP_DANCE_FN(td_inj_rig)
};

__attribute__ ((weak)) td_state_t dance_state(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return TD_SINGLE_TAP;
         else
            return TD_SINGLE_HOLD;
    } else if (state->count > 1) {
        if (state->interrupted)
            return TD_SINGLE_TAP;
        if (state->pressed)
            return TD_DOUBLE_HOLD;
        else
            return TD_DOUBLE_TAP;
    }
    return TD_SINGLE_TAP;
}

// Decimal Separators

void td_dot_com_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_DOT); break;
        case TD_DOUBLE_TAP: register_code(KC_COMM); break;
        case TD_SINGLE_HOLD: layer_on(_MEDIA);
        default: break;
    }
}

void td_dot_com_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_DOT); break;
        case TD_DOUBLE_TAP: unregister_code(KC_COMM); break;
        case TD_SINGLE_HOLD: layer_off(_MEDIA);
        default: break;
    }
}

// Mouse buttons

void td_mou_b13_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_BTN1); break;
        case TD_DOUBLE_TAP: register_code(KC_BTN3); break;
        default: break;
    }
}

void td_mou_b13_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_BTN1); break;
        case TD_DOUBLE_TAP: unregister_code(KC_BTN3); break;
        default: break;
    }
}

void td_mou_b24_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_BTN2); break;
        case TD_DOUBLE_TAP: register_code(KC_BTN4); break;
        default: break;
    }
}

void td_mou_b24_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_BTN2); break;
        case TD_DOUBLE_TAP: unregister_code(KC_BTN4); break;
        default: break;
    }
}

// IntelliJ Most Common Shortcuts

void td_inj_lef(qk_tap_dance_state_t *state, void *user_data) {

    tap_state.state = dance_state(state);
    bool isWindowsOrLinux = os.type == WINDOWS || os.type == LINUX;
    bool isOneShotShift = get_oneshot_mods() & MOD_MASK_SHIFT || get_oneshot_locked_mods() & MOD_MASK_SHIFT;

    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            if (isWindowsOrLinux | isOneShotShift) {
                SEND_STRING(SS_LCTL("1"));
            } else {
                SEND_STRING(SS_LGUI("1"));
                break;
            }
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_LCTL);
            tap_code16(KC_LCTL);
            break;
        case TD_SINGLE_HOLD:
            SEND_STRING(SS_LALT(SS_TAP(X_F7)));
            break;
        default: break;
    }
}

void td_inj_rig(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            SEND_STRING(SS_LALT(SS_TAP(X_ENT)));
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_LSFT);
            tap_code16(KC_LSFT);
            break;
        case TD_SINGLE_HOLD:
            SEND_STRING(SS_TAP(X_F2));
            break;
        default: break;
    }
}

