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
const uint16_t PROGMEM qwe_tab_combo[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM col_ent_combo[] = {RALTT_N, RCTLT_E, RSFTT_I, COMBO_END};
const uint16_t PROGMEM col_esc_combo[] = {LSFTT_R, LCTLT_S, LALTT_T, COMBO_END};
const uint16_t PROGMEM col_tab_combo[] = {KC_L, KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM low_fun_combo[] = {KC_P1, KC_P2, KC_P3, COMBO_END};
const uint16_t PROGMEM fun_tog_combo[] = {KC_F4, KC_F5, KC_F6, COMBO_END};
const uint16_t PROGMEM qwe_low_combo[] = {RGUIT_M, KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM col_low_combo[] = {RGUIT_H, KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM qwe_rai_combo[] = {KC_X, KC_C, LGUIT_V, COMBO_END};
const uint16_t PROGMEM col_rai_combo[] = {KC_X, KC_C, LGUIT_D, COMBO_END};
const uint16_t PROGMEM mou_nav_combo[] = {KC_INS, KC_HOME, KC_END, COMBO_END};
const uint16_t PROGMEM nav_tog_combo[] = {KC_LEFT, KC_DOWN, KC_UP, COMBO_END};
const uint16_t PROGMEM mou_tog_combo[] = {KC_MS_L, KC_MS_D, KC_MS_U, COMBO_END};
const uint16_t PROGMEM low_tog_combo[] = {KC_P4, KC_P5, KC_P6, COMBO_END};
const uint16_t PROGMEM rai_tog_combo[] = {KC_MINS, KC_EQL, KC_EXLM, COMBO_END};
const uint16_t PROGMEM med_tog_combo[] = {SS_MODM, KC_VOLD, KC_VOLU, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(qwe_ent_combo, KC_ENT),
  COMBO(qwe_esc_combo, KC_ESC),
  COMBO(qwe_tab_combo, KC_TAB),
  COMBO(col_ent_combo, KC_ENT),
  COMBO(col_esc_combo, KC_ESC),
  COMBO(col_tab_combo, KC_TAB),
  COMBO(low_fun_combo, TG_FUN),
  COMBO(fun_tog_combo, TG_FUN),
  COMBO(qwe_low_combo, TT_LOW),
  COMBO(col_low_combo, TT_LOW),
  COMBO(qwe_rai_combo, TT_RAI),
  COMBO(col_rai_combo, TT_RAI),
  COMBO(mou_nav_combo, TG_NAV),
  COMBO(nav_tog_combo, TG_NAV),
  COMBO(mou_tog_combo, TG_MOU),
  COMBO(low_tog_combo, TG_LOW),
  COMBO(rai_tog_combo, TG_RAI),
  COMBO(med_tog_combo, TG_MED)
};

// Custom handlers

static user_data_t user_data = {
    .mod_cg = MOD_CG_G,
    .mouselayer = true
};

__attribute__ ((weak)) bool process_record_user(uint16_t keycode, keyrecord_t *record) {

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

        // Shift+Backspace for Delete (when not one-shot)

        case KC_BSPC:
            if (record->event.pressed) {
                if (isShifted && !isOneShotShift) {
                    tap_code(KC_DEL);
                    return false;
                }
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

        // Enable/Disable the Mouse Layer

        case TG_M_ON:
            if (record->event.pressed) {
                user_data.mouselayer = true;
                layer_off(_MOUSE);
                layer_off(_NAVIGATION);
            }
            return false;

        case TG_M_OF:
            if (record->event.pressed) {
                user_data.mouselayer = false;
                layer_off(_MOUSE);
                layer_off(_NAVIGATION);
            }
            return false;

        // Custom one shot mod-taps

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
            // If it is starting or finishing holding, and the mouse layer is disabled,
            // activate or deactivate the navigation layer instead, otherwise continue with normal behavior
            if (!record->tap.count){
                if (!user_data.mouselayer) {
                    if (record->event.pressed) {
                        layer_on(_NAVIGATION);
                        return false;
                    } else {
                        layer_off(_NAVIGATION);
                        return false;
                    }
                }
            }
            return true;

        case MOU_P0:
            // If it is starting or finishing holding, and the mouse layer is disabled,
            // activate or deactivate the navigation layer instead, otherwise continue with normal behavior
            if (!record->tap.count){
                if (!user_data.mouselayer) {
                    if (record->event.pressed) {
                        layer_on(_NAVIGATION);
                        return false;
                    } else {
                        layer_off(_NAVIGATION);
                        return false;
                    }
                }
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

        case SS_MODP:
            if (record->event.pressed) {
                if (isCGModeG) {
                    SEND_STRING(SS_LGUI("+"));
                }
                else if (isCGModeC) {
                    SEND_STRING(SS_LCTL("+"));
                }
            }
            return false;
        case SS_MODM:
            if (record->event.pressed) {
                if (isCGModeG) {
                    SEND_STRING(SS_LGUI("-"));
                }
                else if (isCGModeC) {
                    SEND_STRING(SS_LCTL("-"));
                }
            }
            return false;

        // Force TT to toggle on single tap

        case TT_LOW:
        case TT_RAI:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    return false;
                }
            }
            return true;

        default:
            return true;
    }
}

// Tap-hold configuration

__attribute__ ((weak)) bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOW_SPC:
        case RAI_SPC:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
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
    [DOT_COM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_dot_com_finished, td_dot_com_reset),
    [MOU_B12] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mou_b12_finished, td_mou_b12_reset),
    [MOU_B34] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mou_b34_finished, td_mou_b34_reset)
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

void td_dot_com_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_DOT); break;
        case TD_DOUBLE_TAP: register_code(KC_COMM); break;
        default: break;
    }
}

void td_dot_com_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_DOT); break;
        case TD_DOUBLE_TAP: unregister_code(KC_COMM); break;
        default: break;
    }
}

void td_mou_b12_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_BTN1); break;
        case TD_SINGLE_HOLD: register_code(KC_BTN2); break;
        default: break;
    }
}

void td_mou_b12_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_BTN1); break;
        case TD_SINGLE_HOLD: unregister_code(KC_BTN2); break;
        default: break;
    }
}

void td_mou_b34_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_BTN3); break;
        case TD_SINGLE_HOLD: register_code(KC_BTN4); break;
        default: break;
    }
}

void td_mou_b34_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_BTN3); break;
        case TD_SINGLE_HOLD: unregister_code(KC_BTN4); break;
        default: break;
    }
}
