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

#include "leader.h"

LEADER_EXTERNS();

void process_leader_dictionary(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_SCLN) {
            tap_code16(KC_END);
            tap_code(KC_SCLN);
        }

        SEQ_ONE_KEY(KC_I) {
            tap_code16(KC_END);
            tap_code(KC_SPC);
            tap_code16(KC_LCBR);
        }

        SEQ_ONE_KEY(KC_U) {
            tap_code16(KC_END);
            tap_code(KC_SPC);
            tap_code16(KC_LCBR);
        }
    }
}

void leader_start(void) {
}

void leader_end(void) {
}
