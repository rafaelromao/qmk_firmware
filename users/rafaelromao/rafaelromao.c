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

// Combos

const uint16_t PROGMEM qwe_ent_combo[] = {RALTT_J, RCTLT_K, RSFTT_L, COMBO_END};
const uint16_t PROGMEM qwe_esc_combo[] = {LSFTT_S, LCTLT_D, LALTT_F, COMBO_END};
const uint16_t PROGMEM qw1_tab_combo[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM qw2_tab_combo[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM col_ent_combo[] = {RALTT_N, RCTLT_E, RSFTT_I, COMBO_END};
const uint16_t PROGMEM col_esc_combo[] = {LSFTT_R, LCTLT_S, LALTT_T, COMBO_END};
const uint16_t PROGMEM co1_tab_combo[] = {KC_W, KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM co2_tab_combo[] = {KC_L, KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM low_adj_combo[] = {RGUIT_1, KC_P2, KC_P3, COMBO_END};
const uint16_t PROGMEM adj_tog_combo[] = {KC_F4, KC_F5, KC_F6, COMBO_END};
const uint16_t PROGMEM qwe_low_combo[] = {RGUIT_M, KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM col_low_combo[] = {RGUIT_H, KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM qwe_rai_combo[] = {KC_X, KC_C, LGUIT_V, COMBO_END};
const uint16_t PROGMEM col_rai_combo[] = {KC_X, KC_C, LGUIT_D, COMBO_END};
const uint16_t PROGMEM qr1_sho_combo[] = {KC_W, KC_E , KC_DQUO , COMBO_END};
const uint16_t PROGMEM cr1_sho_combo[] = {KC_W, KC_F , KC_DQUO , COMBO_END};
const uint16_t PROGMEM rs2_sho_combo[] = {KC_DLR, KC_LPRN, KC_RPRN, COMBO_END};
const uint16_t PROGMEM ls1_sho_combo[] = {KC_UNDS, KC_LCBR, KC_RCBR, COMBO_END};
const uint16_t PROGMEM ls2_sho_combo[] = {KC_P7, KC_P8, KC_P9, COMBO_END};
const uint16_t PROGMEM mou_nav_combo[] = {CB_NONE, KC_BTN1, KC_BTN2, COMBO_END};
const uint16_t PROGMEM nav_tog_combo[] = {KC_LEFT, KC_DOWN, KC_UP, COMBO_END};
const uint16_t PROGMEM mou_tog_combo[] = {KC_MS_L, KC_MS_D, KC_MS_U, COMBO_END};
const uint16_t PROGMEM lo1_tog_combo[] = {SFT_SQU, CTL_DQU, ALT_AMP, COMBO_END};
const uint16_t PROGMEM lo2_tog_combo[] = {RALTT_4, RCTLT_5, RSFTT_6, COMBO_END};
const uint16_t PROGMEM ra1_tog_combo[] = {SFT_CIR, CTL_TIL, ALT_QUO, COMBO_END};
const uint16_t PROGMEM ra2_tog_combo[] = {ALT_MIN, CTL_EQL, SFT_EXL, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(qwe_ent_combo, KC_ENT),
  COMBO(qwe_esc_combo, KC_ESC),
  COMBO(qw1_tab_combo, KC_TAB),
  COMBO(qw2_tab_combo, KC_TAB),
  COMBO(col_ent_combo, KC_ENT),
  COMBO(col_esc_combo, KC_ESC),
  COMBO(co1_tab_combo, KC_TAB),
  COMBO(co2_tab_combo, KC_TAB),
  COMBO(low_adj_combo, TG_FUN),
  COMBO(adj_tog_combo, TG_FUN),
  COMBO(qwe_low_combo, TG_LOW),
  COMBO(col_low_combo, TG_LOW),
  COMBO(qwe_rai_combo, TG_RAI),
  COMBO(col_rai_combo, TG_RAI),
  COMBO(qr1_sho_combo, SH_OS),
  COMBO(cr1_sho_combo, SH_OS),
  COMBO(rs2_sho_combo, SH_OS),
  COMBO(ls1_sho_combo, SH_OS),
  COMBO(ls2_sho_combo, SH_OS),
  COMBO(mou_nav_combo, TG_NAV),
  COMBO(nav_tog_combo, TG_NAV),
  COMBO(mou_tog_combo, TG_MOU),
  COMBO(lo1_tog_combo, TG_LOW),
  COMBO(lo2_tog_combo, TG_LOW),
  COMBO(ra1_tog_combo, TG_RAI),
  COMBO(ra2_tog_combo, TG_RAI)
};

// Custom handlers

static user_data_t user_data = {
    .mod_cg = MOD_CG_G
};

__attribute__ ((weak)) bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    bool isQwerty = biton32(default_layer_state) == _QWERTY;
    bool isColemak = biton32(default_layer_state) == _COLEMAK;
    bool isCGModeG = user_data.mod_cg == MOD_CG_G;
    bool isCGModeC = user_data.mod_cg == MOD_CG_C;
    bool isOneShotCG = (isCGModeG && (get_oneshot_mods() & MOD_MASK_GUI)) || (isCGModeC && (get_oneshot_mods() & MOD_MASK_CTRL)) ;
    bool isOneShotShift = get_oneshot_mods() & MOD_MASK_SHIFT || get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotCtrl = get_oneshot_mods() & MOD_MASK_CTRL || get_oneshot_locked_mods() & MOD_MASK_CTRL;
    bool isOneShotAlt = get_oneshot_mods() & MOD_MASK_ALT || get_oneshot_locked_mods() & MOD_MASK_ALT;
    bool isOneShotGui = get_oneshot_mods() & MOD_MASK_GUI || get_oneshot_locked_mods() & MOD_MASK_GUI;
    bool isAnyOneShot = isOneShotShift || isOneShotCtrl || isOneShotAlt || isOneShotGui || isOneShotCG;
    bool isShifted = isOneShotShift || get_mods() & MOD_MASK_SHIFT;

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

        // Shift+Backspace for Delete

        case KC_BSPC:
            if (record->event.pressed) {
                if (isShifted) {
                    tap_code(KC_DEL);
                    return false;
                }
                return true;
            }

        // Non-basic mod-taps

        case SFT_EXL:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    tap_code16(KC_EXLM);
                }
                return false;
            }
            return true;

        case SFT_SQU:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    SEND_STRING("' ");
                }
                return false;
            }
            return true;

        case CTL_DQU:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    SEND_STRING("\" ");
                }
                return false;
            }
            return true;

        case ALT_AMP:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    tap_code16(KC_AMPR);
                }
                return false;
            }
            return true;

        case SFT_CIR:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    tap_code16(KC_CIRC);
                }
                return false;
            }
            return true;

        case CTL_TIL:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    tap_code16(KC_TILD);
                }
                return false;
            }
            return true;

        case GUI_GRV:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    tap_code16(KC_GRV);
                }
                return false;
            }
            return true;

        // Change Gui/Ctrl mode

        case TG_MD_G:
            if (record->event.pressed) {
                user_data.mod_cg = MOD_CG_G;
            }
            return false;

        case TG_MD_C:
            if (record->event.pressed) {
                user_data.mod_cg = MOD_CG_C;
            }
            return false;

        // Custom one shot mod-taps

        case MOU_CAP:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (host_keyboard_led_state().caps_lock) {
                        tap_code(KC_CAPS);
                    } else {
                        if (!isOneShotShift) {
                            add_oneshot_mods(MOD_BIT(KC_LSFT));
                        } else {
                            del_oneshot_mods(MOD_BIT(KC_LSFT));
                            unregister_mods(MOD_BIT(KC_LSFT));
                            tap_code(KC_CAPS);
                        }
                    }
                }
                return false;
            }
            return true;

        case NAV_MOD:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (isAnyOneShot) {
                        uint8_t mods = 0;
                        if ((mods = get_oneshot_mods())) {
                            clear_oneshot_mods();
                            unregister_mods(mods);
                        }
                        if ((mods = get_oneshot_locked_mods())) {
                            clear_oneshot_locked_mods();
                            unregister_mods(mods);
                        }
                    } else if (!isOneShotCG) {
                        if (isCGModeG) {
                            add_oneshot_mods(MOD_BIT(KC_LGUI));
                        }
                        if (isCGModeC) {
                            add_oneshot_mods(MOD_BIT(KC_LCTL));
                        }
                    }
                }
                return false;
            }
            return true;

        // Macros

        case SS_BTIC:
            if (record->event.pressed) {
                SEND_STRING("` ");
            }
            return false;
        case SS_DQUO:
            if (record->event.pressed) {
                SEND_STRING("\" ");
            }
            return false;
        case SS_SQUO:
            if (record->event.pressed) {
                SEND_STRING("' ");
            }
            return false;
        case SS_CIRC:
            if (record->event.pressed) {
                SEND_STRING("^ ");
            }
            return false;
        case SS_TILD:
            if (record->event.pressed) {
                SEND_STRING("~ ");
            }
            return false;

        // Tap dance

        case TD_DCQ:
            if (isColemak) {
                if (record->event.pressed) {
                    register_code(KC_BSPC);
                } else {
                    unregister_code(KC_BSPC);
                }
                return false;
            } else {
                return true;
            }
        case TD_DCC:
            if (isQwerty) {
                if (record->event.pressed) {
                    register_code(KC_BSPC);
                } else {
                    unregister_code(KC_BSPC);
                }
                return false;
            } else {
                return true;
            }

        default:
            return true;
    }
}

// Tap-hold configuration

__attribute__ ((weak)) bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RSFTT_6:
        case RCTLT_5:
        case RALTT_4:
        case RGUIT_1:
            return true;
        default:
            return false;
    }
}

__attribute__ ((weak)) bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFTT_S:
        case LCTLT_D:
        case LALTT_F:
        case LGUIT_V:
        case LSFTT_R:
        case LCTLT_S:
        case LALTT_T:
        case LGUIT_D:
        case RSFTT_L:
        case RCTLT_K:
        case RALTT_J:
        case RGUIT_M:
        case RSFTT_I:
        case RCTLT_E:
        case RALTT_N:
        case RGUIT_H:
            return true;
        default:
            return false;
    }
}

// Tap dance

static td_tap_t tap_state = {
    .state = TD_NONE
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [DOT_COM_QWE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_dcq_finished, td_dcq_reset),
    [DOT_COM_COL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_dcc_finished, td_dcc_reset)
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

void td_dcq_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    bool isQwerty = biton32(default_layer_state) == _QWERTY;
    if (isQwerty) {
        switch (tap_state.state) {
            case TD_SINGLE_TAP: register_code(KC_DOT); break;
            case TD_DOUBLE_TAP: register_code(KC_COMM); break;
            default: break;
        }
    }
}

void td_dcq_reset(qk_tap_dance_state_t *state, void *user_data) {
    bool isQwerty = biton32(default_layer_state) == _QWERTY;
    if (isQwerty) {
        switch (tap_state.state) {
            case TD_SINGLE_TAP: unregister_code(KC_DOT); break;
            case TD_DOUBLE_TAP: unregister_code(KC_COMM); break;
            default: break;
        }
    }
    tap_state.state = TD_NONE;
}

void td_dcc_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    bool isColemak = biton32(default_layer_state) == _COLEMAK;
    if (isColemak) {
        switch (tap_state.state) {
            case TD_SINGLE_TAP: register_code(KC_DOT); break;
            case TD_DOUBLE_TAP: register_code(KC_COMM); break;
            default: break;
        }
    }
}

void td_dcc_reset(qk_tap_dance_state_t *state, void *user_data) {
    bool isColemak = biton32(default_layer_state) == _COLEMAK;
    if (isColemak) {
        switch (tap_state.state) {
            case TD_SINGLE_TAP: unregister_code(KC_DOT); break;
            case TD_DOUBLE_TAP: unregister_code(KC_COMM); break;
            default: break;
        }
    }
    tap_state.state = TD_NONE;
}
