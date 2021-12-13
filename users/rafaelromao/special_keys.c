/* Copyright 2021 RVafael Romão https://github.com/rafaelromao
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

#include "special_keys.h"

extern os_t os;

process_record_result_t process_special_keys(uint16_t keycode, keyrecord_t *record) {

    bool isMacOS = os.type == MACOS;
    bool isWindowsOrLinux = os.type == WINDOWS || os.type == LINUX;
    bool isOneShotDefaultMod = (isMacOS && (get_oneshot_mods() & MOD_MASK_GUI)) || (isWindowsOrLinux && (get_oneshot_mods() & MOD_MASK_CTRL)) ;
    bool isOneShotShift = get_oneshot_mods() & MOD_MASK_SHIFT || get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotCtrl = get_oneshot_mods() & MOD_MASK_CTRL || get_oneshot_locked_mods() & MOD_MASK_CTRL;
    bool isOneShotAlt = get_oneshot_mods() & MOD_MASK_ALT || get_oneshot_locked_mods() & MOD_MASK_ALT;
    bool isOneShotGui = get_oneshot_mods() & MOD_MASK_GUI || get_oneshot_locked_mods() & MOD_MASK_GUI;
    bool isAnyOneShot = isOneShotShift || isOneShotCtrl || isOneShotAlt || isOneShotGui || isOneShotDefaultMod;
    bool isCapsLocked = host_keyboard_led_state().caps_lock;

    switch (keycode) {

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
                    } else if (!isOneShotDefaultMod) {
                        if (isMacOS) {
                            add_oneshot_mods(MOD_BIT(KC_LGUI));
                        }
                        if (isWindowsOrLinux) {
                            add_oneshot_mods(MOD_BIT(KC_LCTL));
                        }
                    }
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }
            return PROCESS_RECORD_RETURN_TRUE;

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
                return PROCESS_RECORD_RETURN_FALSE;
            }

    }

    return PROCESS_RECORD_CONTINUE;
}
