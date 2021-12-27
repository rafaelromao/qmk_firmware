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

#include "combos.h"

const uint16_t PROGMEM qwe_esc_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM qwe_sav_combo[] = {LSFTT_S, LCTLT_D, COMBO_END};
const uint16_t PROGMEM qwe_tab_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM qwe_ent_combo[] = {RCTLT_K, RSFTT_L, COMBO_END};

const uint16_t PROGMEM col_esc_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM col_sav_combo[] = {LSFTT_R, LCTLT_S, COMBO_END};
const uint16_t PROGMEM col_tab_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM col_ent_combo[] = {RCTLT_E, RSFTT_I, COMBO_END};

const uint16_t PROGMEM low_fun_combo[] = {KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM bas_low_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM bas_rai_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM mou_nav_combo[] = {KC_HOME, KC_END, COMBO_END};

const uint16_t PROGMEM fun_tog_combo[] = {KC_F5, KC_F6, COMBO_END};
const uint16_t PROGMEM nav_tog_combo[] = {KC_DOWN, KC_UP, COMBO_END};
const uint16_t PROGMEM mou_tog_combo[] = {KC_MS_D, KC_MS_U, COMBO_END};
const uint16_t PROGMEM low_tog_combo[] = {KC_5, KC_6, COMBO_END};
const uint16_t PROGMEM rai_tog_combo[] = {KC_EQL, KC_EXLM, COMBO_END};
const uint16_t PROGMEM med_tog_combo[] = {KC_VOLD, KC_VOLU, COMBO_END};

const uint16_t PROGMEM lqw_sal_combo[] = {KCA_FUN, LSFTT_S, COMBO_END};
const uint16_t PROGMEM lqw_pas_combo[] = {LCTLT_D, LALTT_F, COMBO_END};
const uint16_t PROGMEM lqw_cut_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM lqw_cop_combo[] = {KC_C, LGUIT_V, COMBO_END};

const uint16_t PROGMEM lco_sal_combo[] = {KCA_FUN, LSFTT_R, COMBO_END};
const uint16_t PROGMEM lco_pas_combo[] = {LCTLT_S, LALTT_T, COMBO_END};
const uint16_t PROGMEM lco_cop_combo[] = {KC_C, LGUIT_D, COMBO_END};

const uint16_t PROGMEM rqw_sal_combo[] = {RSFTT_L, UND_MED, COMBO_END};
const uint16_t PROGMEM rqw_pas_combo[] = {RALTT_J, RCTLT_K, COMBO_END};
const uint16_t PROGMEM rqw_cut_combo[] = {KC_DOT, KC_SCLN, COMBO_END};
const uint16_t PROGMEM rqw_cop_combo[] = {RGUIT_M, KC_COMM, COMBO_END};

const uint16_t PROGMEM rco_sal_combo[] = {RSFTT_I, KCO_MED, COMBO_END};
const uint16_t PROGMEM rco_pas_combo[] = {RALTT_N, RCTLT_E, COMBO_END};
const uint16_t PROGMEM rco_cop_combo[] = {RGUIT_H, KC_COMM, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(qwe_esc_combo, KC_ESC),
  COMBO(qwe_sav_combo, CB_SAV),
  COMBO(qwe_tab_combo, KC_TAB),
  COMBO(qwe_ent_combo, KC_ENT),

  COMBO(col_esc_combo, KC_ESC),
  COMBO(col_sav_combo, CB_SAV),
  COMBO(col_tab_combo, KC_TAB),
  COMBO(col_ent_combo, KC_ENT),

  COMBO(low_fun_combo, TG_FUN),
  COMBO(fun_tog_combo, TG_FUN),
  COMBO(bas_low_combo, TT_LOW),
  COMBO(bas_rai_combo, TT_RAI),
  COMBO(mou_nav_combo, TO_NAV),

  COMBO(nav_tog_combo, TG_NAV),
  COMBO(mou_tog_combo, TG_MOU),
  COMBO(low_tog_combo, TG_LOW),
  COMBO(rai_tog_combo, TG_RAI),
  COMBO(med_tog_combo, TG_MED),

  COMBO(lqw_sal_combo, CB_SAL),
  COMBO(lqw_pas_combo, CB_PAST),
  COMBO(lqw_cut_combo, CB_CUT),
  COMBO(lqw_cop_combo, CB_COPY),

  COMBO(lco_sal_combo, CB_SAL),
  COMBO(lco_pas_combo, CB_PAST),
  COMBO(lco_cop_combo, CB_COPY),

  COMBO(rqw_sal_combo, CB_SAL),
  COMBO(rqw_pas_combo, CB_PAST),
  COMBO(rqw_cut_combo, CB_CUT),
  COMBO(rqw_cop_combo, CB_COPY),

  COMBO(rco_sal_combo, CB_SAL),
  COMBO(rco_pas_combo, CB_PAST),
  COMBO(rco_cop_combo, CB_COPY),
};

extern os_t os;

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    uint16_t key;
    uint8_t idx = 0;
    bool combo_must_tap = false;
    while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        switch (key) {
            case QK_MOD_TAP...QK_MOD_TAP_MAX:
            case QK_LAYER_TAP...QK_LAYER_TAP_MAX:
            case QK_MOMENTARY...QK_MOMENTARY_MAX:
                combo_must_tap = true;
                break;
            default:
                combo_must_tap = false;
                break;
        }
        if (!combo_must_tap) {
            return false;
        }
        idx += 1;
    }
    return combo_must_tap;
}

process_record_result_t process_combos(uint16_t keycode, keyrecord_t *record) {

    bool isWindowsOrLinux = os.type == WINDOWS || os.type == LINUX;
    bool isOneShotShift = get_oneshot_mods() & MOD_MASK_SHIFT || get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isShifted = isOneShotShift || get_mods() & MOD_MASK_SHIFT;

    switch (keycode) {

        case CB_SAL:
            if (record->event.pressed) {
                clear_any_mods();
                if (isWindowsOrLinux | isShifted) {
                    SEND_STRING(SS_LCTL("a"));
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }

        case CB_SAV:
            if (record->event.pressed) {
                clear_any_mods();
                if (isWindowsOrLinux | isShifted) {
                    SEND_STRING(SS_LCTL("s"));
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }

        case CB_CUT:
            if (record->event.pressed) {
                clear_any_mods();
                if (isWindowsOrLinux | isShifted) {
                    SEND_STRING(SS_LCTL("x"));
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }

        case CB_COPY:
            if (record->event.pressed) {
                clear_any_mods();
                if (isWindowsOrLinux | isShifted) {
                    SEND_STRING(SS_LCTL("c"));
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }

        case CB_PAST:
            if (record->event.pressed) {
                clear_any_mods();
                if (isWindowsOrLinux | isShifted) {
                    SEND_STRING(SS_LCTL("v"));
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }

    }

    return PROCESS_RECORD_CONTINUE;
}
