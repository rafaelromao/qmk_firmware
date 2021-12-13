/* Copyright 2021 Rafael Romão https://github.com/rafaelromao
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

#define _CAPSLOCK_TIMER_H

#include QMK_KEYBOARD_H

#ifndef _PROCESS_RECORD_RESULT_H
#include "process_record_result.h"
#endif

typedef struct {
    uint16_t timer;
} capslock_timer_t;

void check_start_capslock_timer(bool isCapsLocked);
void check_disable_capslock(void);
process_record_result_t process_capslock_timer_extension(uint16_t keycode, keyrecord_t *record);
