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

#define _MACROS_H

#include QMK_KEYBOARD_H

#ifndef _KEYCODES_H
#include "../definitions/keycodes.h"
#endif

#ifndef _PROCESS_RECORD_RESULT_H
#include "process_record_result.h"
#endif

#ifndef _OS_TOGGLE_H
#include "os_toggle.h"
#endif

process_record_result_t process_macros(uint16_t keycode, keyrecord_t *record);
