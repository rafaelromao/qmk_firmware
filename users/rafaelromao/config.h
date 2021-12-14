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

// Optimization to save memory
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// Make it easier to work with tap hold
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define ONESHOT_TAP_TOGGLE 2
#define ONESHOT_TIMEOUT 1500
#define TAPPING_TOGGLE 1
#define TAPPING_TERM 175

// Configure combos
#define COMBO_COUNT 18
#define COMBO_TERM 40
#define EXTRA_SHORT_COMBOS
#define COMBO_STRICT_TIMER

// Mouse key speed and acceleration.
#define MOUSEKEY_DELAY 100
#define MOUSEKEY_INTERVAL 10
#define MOUSEKEY_MOVE_DELTA 5
#define MOUSEKEY_MAX_SPEED 10
#define MOUSEKEY_TIME_TO_MAX 25
#define MOUSEKEY_WHEEL_DELAY 100
#define MOUSEKEY_WHEEL_INTERVAL 100
#define MOUSEKEY_WHEEL_MAX_SPEED 20
#define MOUSEKEY_WHEEL_TIME_TO_MAX 10
