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

#include "rafaelromao.h"

// Led update

__attribute__ ((weak)) bool led_update_user(led_t led_state) {
    check_start_capslock_timer(led_state.caps_lock);
    return true;
}

// Matrix scan

__attribute__ ((weak)) void matrix_scan_user(void) {
    check_disable_capslock();
}

// Custom keycodes

extern os_t os;

__attribute__ ((weak)) bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // Extend capslock timer
    switch (process_capslock_timer_extension(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process mouse layer
    switch (process_mouselayer(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process OS toggle
    switch (process_os_toggle(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process macros
    switch (process_macros(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    bool isMacOS = os.type == MACOS;
    bool isWindowsOrLinux = os.type == WINDOWS || os.type == LINUX;
    bool isOneShotCG = (isMacOS && (get_oneshot_mods() & MOD_MASK_GUI)) || (isWindowsOrLinux && (get_oneshot_mods() & MOD_MASK_CTRL)) ;
    bool isOneShotShift = get_oneshot_mods() & MOD_MASK_SHIFT || get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotCtrl = get_oneshot_mods() & MOD_MASK_CTRL || get_oneshot_locked_mods() & MOD_MASK_CTRL;
    bool isOneShotAlt = get_oneshot_mods() & MOD_MASK_ALT || get_oneshot_locked_mods() & MOD_MASK_ALT;
    bool isOneShotGui = get_oneshot_mods() & MOD_MASK_GUI || get_oneshot_locked_mods() & MOD_MASK_GUI;
    bool isAnyOneShot = isOneShotShift || isOneShotCtrl || isOneShotAlt || isOneShotGui || isOneShotCG;
    bool isShifted = isOneShotShift || get_mods() & MOD_MASK_SHIFT;
    bool isCapsLocked = host_keyboard_led_state().caps_lock;

    // Handle custom keycodes
    switch (keycode) {

        // Persistent default layers

        case DF_COL:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case DF_QWE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;

        // Shift+Backspace for Delete (when not one-shot)

        case KC_BSPC:
            if (record->event.pressed) {
                if (isShifted && !isOneShotShift) {
                    tap_code(KC_DEL);
                    return false;
                }
            }
            return true;

        // Custom one shot mod-taps

        case NAV_MOD:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (isAnyOneShot) {
                        uint8_t mods = 0;
                        if ((mods = get_oneshot_locked_mods())) {
                            clear_oneshot_locked_mods();
                        }
                        if ((mods = get_oneshot_mods())) {
                            clear_oneshot_mods();
                        }
                        if ((mods = get_mods())) {
                            unregister_mods(mods);
                        }
                    } else if (!isOneShotCG) {
                        if (isMacOS) {
                            add_oneshot_mods(MOD_BIT(KC_LGUI));
                        }
                        if (isWindowsOrLinux) {
                            add_oneshot_mods(MOD_BIT(KC_LCTL));
                        }
                    }
                }
                return false;
            }
            return true;

        case MOU_CAP:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (isCapsLocked) {
                        tap_code(KC_CAPS); // Disable capslock
                    } else {
                        if (!isOneShotShift) {
                            add_oneshot_mods(MOD_BIT(KC_LSFT));
                        } else {
                            del_oneshot_mods(MOD_BIT(KC_LSFT));
                            unregister_mods(MOD_BIT(KC_LSFT));
                            tap_code(KC_CAPS); // Enable capslock
                        }
                    }
                }
                return false;
            }

    }
    return true;
}

// Tap-hold configuration

__attribute__ ((weak)) bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    return get_hold_on_other_key_press_result(keycode);
}

__attribute__ ((weak)) bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    return get_tapping_force_hold_result(keycode);
}
