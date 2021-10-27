/* Copyright 2021 Rafael Romão
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

// Layers

enum layers {
  QWERTY,
  COLEMAK,
  NUMBERS,
  SYMBOLS,
  FUCTIONS,
  NAVIGATION,
  MOUSE,
  MEDIA,
  MAINTENANCE,
  LAYERS
};

// Custom keycodes

#define SFT_SLS LSFT_T(KC_SLSH)

#define LCTLT_S LCTL_T(KC_S)
#define LSFTT_D LSFT_T(KC_D)
#define LALTT_F LALT_T(KC_F)
#define LGUIT_V LGUI_T(KC_V)

#define LCTLT_R LCTL_T(KC_R)
#define LSFTT_S LSFT_T(KC_S)
#define LALTT_T LALT_T(KC_T)
#define LGUIT_D LGUI_T(KC_D)

#define RCTLT_L RCTL_T(KC_L)
#define RSFTT_K RSFT_T(KC_K)
#define RALTT_J RALT_T(KC_J)
#define RGUIT_M RGUI_T(KC_M)

#define RCTLT_I RCTL_T(KC_I)
#define RSFTT_E RSFT_T(KC_E)
#define RALTT_N RALT_T(KC_N)
#define RGUIT_H RGUI_T(KC_H)

#define RCTLT_6 RCTL_T(KC_P6)
#define RSFTT_5 RSFT_T(KC_P5)
#define RALTT_4 RALT_T(KC_P4)
#define RGUIT_1 RGUI_T(KC_P1)

#define OS_LCTL OSM(MOD_LCTL)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)

#define OS_RCTL OSM(MOD_RCTL)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_RALT OSM(MOD_RALT)
#define OS_RGUI OSM(MOD_RGUI)

#define SFT_MIN LSFT_T(KC_MINS)

#define SYM_SPC LT(SYMBOLS,KC_SPC)
#define NUM_SPC LT(NUMBERS,KC_SPC)

#define TD_DCQ TD(DOT_COM_QWE)
#define TD_DCC TD(DOT_COM_COL)

#define HYPR_A HYPR(KC_A)
#define HYPR_V HYPR(KC_V)

#define DF_QWE DF(QWERTY)
#define DF_COL DF(COLEMAK)
#define TO_SYM TO(SYMBOLS)
#define OS_SYM OSL(SYMBOLS)
#define OS_NUM OSL(NUMBERS)
#define TO_NUM TO(NUMBERS)
#define MO_NAV MO(NAVIGATION)
#define TO_NAV TO(NAVIGATION)
#define TG_NAV TG(NAVIGATION)
#define MO_MOU MO(MOUSE)
#define TO_MOU TO(MOUSE)
#define MO_MAI MO(MAINTENANCE)
#define TO_MAI TO(MAINTENANCE)
#define MO_MED MO(MEDIA)
#define TO_MED TO(MEDIA)
#define MO_LAY MO(LAYERS)
#define MO_FUN MO(FUCTIONS)
#define TO_FUN TO(FUCTIONS)
#define TG_FUN TG(FUCTIONS)

enum custom_keycodes {
    SS_BTIC = SAFE_RANGE,
    SS_DQUO,
    SS_SQUO,
    SS_CIRC,
    SS_TILD
};

// Tap dance settings

typedef enum {
    TD_NONE,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD
} td_state_t;

typedef struct {
    td_state_t state;
} td_tap_t;

enum {
    DOT_COM_QWE,
    DOT_COM_COL
};

td_state_t dance_state(qk_tap_dance_state_t *state);

// Combos

const uint16_t PROGMEM qwe_ent_combo[] = {RALTT_J, RSFTT_K, RCTLT_L, COMBO_END};
const uint16_t PROGMEM qwe_esc_combo[] = {LCTLT_S, LSFTT_D, LALTT_F, COMBO_END};
const uint16_t PROGMEM qw1_tab_combo[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM qw2_tab_combo[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM col_ent_combo[] = {RALTT_N, RSFTT_E, RCTLT_I, COMBO_END};
const uint16_t PROGMEM col_esc_combo[] = {LCTLT_R, LSFTT_S, LALTT_T, COMBO_END};
const uint16_t PROGMEM co1_tab_combo[] = {KC_W, KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM co2_tab_combo[] = {KC_L, KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM num_fun_combo[] = {RALTT_4, RSFTT_5, RCTLT_6, COMBO_END};
const uint16_t PROGMEM fun_tog_combo[] = {KC_F4, KC_F5, KC_F6, COMBO_END};
const uint16_t PROGMEM qwe_num_combo[] = {KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM col_num_combo[] = {KC_X, KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM num_sym_combo[] = {KC_P1, KC_P2, KC_P3, COMBO_END};
const uint16_t PROGMEM qwe_sym_combo[] = {KC_M, KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM col_sym_combo[] = {KC_H, KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM rsy_sho_combo[] = {KC_DLR, KC_LPRN, KC_RPRN, COMBO_END};
const uint16_t PROGMEM lsy_sho_combo[] = {KC_UNDS, KC_LCBR, KC_RCBR, COMBO_END};
const uint16_t PROGMEM rnu_sho_combo[] = {KC_P7, KC_P8, KC_P9, COMBO_END};
const uint16_t PROGMEM lnu_sho_combo[] = {KC_CIRC, KC_TILD, KC_GRV , COMBO_END};
const uint16_t PROGMEM mou_nav_combo[] = {OS_RALT, OS_RSFT, OS_RCTL, COMBO_END};
const uint16_t PROGMEM nav_tog_combo[] = {KC_LEFT, KC_DOWN, KC_UP, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(qwe_ent_combo, KC_ENT),
  COMBO(qwe_esc_combo, KC_ESC),
  COMBO(qw1_tab_combo, KC_TAB),
  COMBO(qw2_tab_combo, KC_TAB),
  COMBO(col_ent_combo, KC_ENT),
  COMBO(col_esc_combo, KC_ESC),
  COMBO(co1_tab_combo, KC_TAB),
  COMBO(co2_tab_combo, KC_TAB),
  COMBO(num_fun_combo, TG_FUN),
  COMBO(fun_tog_combo, TG_FUN),
  COMBO(qwe_num_combo, OS_NUM),
  COMBO(col_num_combo, OS_NUM),
  COMBO(num_sym_combo, OS_SYM),
  COMBO(qwe_sym_combo, OS_SYM),
  COMBO(col_sym_combo, OS_SYM),
  COMBO(rsy_sho_combo, SH_OS),
  COMBO(lsy_sho_combo, SH_OS),
  COMBO(rnu_sho_combo, SH_OS),
  COMBO(lnu_sho_combo, SH_OS),
  COMBO(mou_nav_combo, TG_NAV),
  COMBO(nav_tog_combo, TG_NAV)
};

// Keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

     [QWERTY] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , XXXXXXX , XXXXXXX , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_A    , LCTLT_S , LSFTT_D , LALTT_F , KC_G    , XXXXXXX , XXXXXXX , KC_H    , RALTT_J , RSFTT_K , RCTLT_L , KC_BSPC ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_Z    , KC_X    , KC_C    , LGUIT_V , KC_B    , XXXXXXX , XXXXXXX , KC_N    , RGUIT_M , KC_COMM , KC_DOT  , KC_SCLN ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , MO_NAV  , SYM_SPC ,      XXXXXXX      , NUM_SPC , MO_MOU  , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [COLEMAK] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_Q    , KC_W    , KC_F    , KC_P    , KC_B    , XXXXXXX , XXXXXXX , KC_J    , KC_L    , KC_U    , KC_Y    , KC_BSPC ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_A    , LCTLT_R , LSFTT_S , LALTT_T , KC_G    , XXXXXXX , XXXXXXX , KC_M    , RALTT_N , RSFTT_E , RCTLT_I , KC_O    ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_Z    , KC_X    , KC_C    , LGUIT_D , KC_V    , XXXXXXX , XXXXXXX , KC_K    , RGUIT_H , KC_COMM , KC_DOT  , KC_SCLN ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , MO_NAV  , SYM_SPC ,      XXXXXXX      , NUM_SPC , MO_MOU  , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [NUMBERS] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      XXXXXXX , KC_CIRC , KC_TILD , KC_GRV  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_P7   , KC_P8   , KC_P9   , TD_DCQ  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_SLSH , KC_ASTR , KC_MINS , KC_PLUS , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , RALTT_4 , RSFTT_5 , RCTLT_6 , TD_DCC  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , KC_DQUO , KC_C    , KC_QUOT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , RGUIT_1 , KC_P2   , KC_P3   , KC_P0   ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , MO_FUN  ,      XXXXXXX      , _______ , _______ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [SYMBOLS] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_AT   , KC_UNDS , KC_LCBR , KC_RCBR , SS_CIRC , XXXXXXX , XXXXXXX , SS_TILD , KC_DLR  , KC_LPRN , KC_RPRN , KC_QUES ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_SLSH , KC_ASTR , SFT_MIN , KC_EQL  , KC_EXLM , XXXXXXX , XXXXXXX , KC_PIPE , KC_AMPR , SS_DQUO , SS_SQUO , SS_BTIC ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_HASH , KC_BSLS , KC_LBRC , KC_RBRC , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_PERC , KC_LT   , KC_GT   , KC_COLN ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , _______ ,      XXXXXXX      , MO_FUN  , _______ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [FUCTIONS] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_CAPS , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F7   , KC_F8   , KC_F9   , KC_F12  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , KC_LCTL , KC_LSFT , KC_LALT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F4   , KC_F5   , KC_F6   , KC_F11  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , KC_LGUI , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F1   , KC_F2   , KC_F3   , KC_F10  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , _______ ,      XXXXXXX      , _______ , _______ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [NAVIGATION] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_ESC  , XXXXXXX , XXXXXXX , KC_TAB  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_TAB  , KC_END  , KC_HOME , KC_ENT  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , OS_LCTL , OS_LSFT , OS_LALT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      MO_MED  , XXXXXXX , XXXXXXX , OS_LGUI , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_INS  , KC_PGDN , KC_PGUP , KC_DEL  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , _______ ,      XXXXXXX      , _______ , MO_MAI  , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [MOUSE] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_ESC  , KC_BTN2 , KC_BTN1 , KC_TAB  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_TAB  , KC_WH_D , KC_WH_U , KC_ENT  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_MS_L , KC_MS_U , KC_MS_D , KC_MS_R , KC_GRV  , XXXXXXX , XXXXXXX , XXXXXXX , OS_RALT , OS_RSFT , OS_RCTL , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , OS_RGUI , XXXXXXX , XXXXXXX , MO_MED ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , MO_MAI  , _______ ,      XXXXXXX      , _______ , _______ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [MEDIA] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_MSTP , KC_MNXT , KC_MPRV , KC_MPLY , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_MPLY , KC_MPRV , KC_MNXT , KC_MSTP ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_MUTE , KC_VOLU , KC_VOLD , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_VOLD , KC_VOLU , KC_MUTE ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , HYPR_V  , HYPR_A  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , HYPR_A  , HYPR_V  , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , _______ ,      XXXXXXX      , _______ , _______ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [MAINTENANCE] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      XXXXXXX , RGB_TOG , RGB_MOD , XXXXXXX , EEP_RST , XXXXXXX , XXXXXXX , RESET   , XXXXXXX , CMB_TOG , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      RGB_VAI , RGB_HUI , RGB_SAI , MO_LAY  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , MO_LAY  , NK_TOGG , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      RGB_VAD , RGB_HUD , RGB_SAD , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_SLEP , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , _______ ,      XXXXXXX      , _______ , _______ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [LAYERS] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      XXXXXXX , XXXXXXX , DF_QWE  , TO_MAI  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , TO_MAI  , DF_COL  , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , TO_FUN  , XXXXXXX , XXXXXXX , TO_FUN  , _______ , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      TO_MED  , XXXXXXX , XXXXXXX , TO_NAV  , TO_SYM  , XXXXXXX , XXXXXXX , TO_NUM  , TO_MOU  , XXXXXXX , XXXXXXX , TO_MED  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , _______ ,      XXXXXXX      , _______ , _______ , XXXXXXX , XXXXXXX , XXXXXXX)
 // |_______________________________________________________________________________________________________________________|

};

// Custom keycodes

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    bool isQwerty = biton32(default_layer_state) == QWERTY;
    bool isColemak = biton32(default_layer_state) == COLEMAK;

    switch (keycode) {

        // Persistent default layers

        case DF_COL:
            if (record->event.pressed) {
                set_single_persistent_default_layer(COLEMAK);
            }
            return false;
        case DF_QWE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(QWERTY);
            }
            return false;

        // String delimiters

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

        case TD_DCC:
            if (isQwerty) {
                if (record->event.pressed) {
                    register_code(KC_BSPC);
                } else {
                    unregister_code(KC_BSPC);
                }
                return false;
            }
        case TD_DCQ:
            if (isColemak) {
                if (record->event.pressed) {
                    register_code(KC_BSPC);
                } else {
                    unregister_code(KC_BSPC);
                }
                return false;
            }

        default:
            return true;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RCTLT_6:
        case RSFTT_5:
        case RALTT_4:
        case RGUIT_1:
            return true;
        default:
            return false;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTLT_S:
        case LSFTT_D:
        case LALTT_F:
        case LGUIT_V:
        case LCTLT_R:
        case LSFTT_S:
        case LALTT_T:
        case LGUIT_D:
        case RCTLT_L:
        case RSFTT_K:
        case RALTT_J:
        case RGUIT_M:
        case RCTLT_I:
        case RSFTT_E:
        case RALTT_N:
        case RGUIT_H:
            return true;
        default:
            return false;
    }
}

// Swap Hands

const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
  {{11, 0}, {10, 0}, {9, 0}, {8, 0}, {7, 0}, {6, 0}, {5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
  {{11, 1}, {10, 1}, {9, 1}, {8, 1}, {7, 1}, {6, 1}, {5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
  {{11, 2}, {10, 2}, {9, 2}, {8, 2}, {7, 2}, {6, 2}, {5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
  {{11, 3}, {10, 3}, {9, 3}, {8, 3}, {7, 3}, {6, 3}, {5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
};

// RGB Indicators

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    if (!is_combo_enabled()) {
        rgb_matrix_set_color(9, RGB_RED);
    }

    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(0, RGB_RED);
    }

    switch(get_highest_layer(layer_state|default_layer_state)) {
        case SYMBOLS:
            rgb_matrix_set_color(40, RGB_WHITE);
            break;
        case NUMBERS:
            rgb_matrix_set_color(42, RGB_WHITE);
            break;
        case MEDIA:
            rgb_matrix_set_color(24, RGB_WHITE);
            rgb_matrix_set_color(35, RGB_WHITE);
            break;
        case FUCTIONS:
            rgb_matrix_set_color(40, RGB_WHITE);
            rgb_matrix_set_color(42, RGB_WHITE);
            break;
        case NAVIGATION:
            rgb_matrix_set_color(39, RGB_WHITE);
            break;
        case MOUSE:
            rgb_matrix_set_color(43, RGB_WHITE);
            break;
        case MAINTENANCE:
            rgb_matrix_set_color(39, RGB_WHITE);
            rgb_matrix_set_color(43, RGB_WHITE);
            rgb_matrix_set_color(7, RGB_RED);
            break;
        case LAYERS:
            rgb_matrix_set_color(15, RGB_WHITE);
            rgb_matrix_set_color(20, RGB_WHITE);
            break;
        default:
            break;
    }
}

// Tap dance

td_state_t dance_state(qk_tap_dance_state_t *state) {
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

static td_tap_t tap_state = {
    .state = TD_NONE
};

void td_dcq_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    bool isQwerty = biton32(default_layer_state) == QWERTY;
    if (isQwerty) {
        switch (tap_state.state) {
            case TD_SINGLE_TAP: register_code(KC_DOT); break;
            case TD_DOUBLE_TAP: register_code(KC_COMM); break;
            default: break;
        }
    } else {
        switch (tap_state.state) {
            default:
                register_code(KC_BSPC); break;
        }
    }
}

void td_dcq_reset(qk_tap_dance_state_t *state, void *user_data) {
    bool isQwerty = biton32(default_layer_state) == QWERTY;
    if (isQwerty) {
        switch (tap_state.state) {
            case TD_SINGLE_TAP: unregister_code(KC_DOT); break;
            case TD_DOUBLE_TAP: unregister_code(KC_COMM); break;
            default: break;
        }
    } else {
        switch (tap_state.state) {
            default:
                unregister_code(KC_BSPC); break;
        }
    }
    tap_state.state = TD_NONE;
}

void td_dcc_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    bool isColemak = biton32(default_layer_state) == COLEMAK;
    if (isColemak) {
        switch (tap_state.state) {
            case TD_SINGLE_TAP: register_code(KC_DOT); break;
            case TD_DOUBLE_TAP: register_code(KC_COMM); break;
            default: break;
        }
    } else {
        switch (tap_state.state) {
            default:
                register_code(KC_BSPC); break;
        }
    }
}

void td_dcc_reset(qk_tap_dance_state_t *state, void *user_data) {
    bool isColemak = biton32(default_layer_state) == COLEMAK;
    if (isColemak) {
        switch (tap_state.state) {
            case TD_SINGLE_TAP: unregister_code(KC_DOT); break;
            case TD_DOUBLE_TAP: unregister_code(KC_COMM); break;
            default: break;
        }
    } else {
        switch (tap_state.state) {
            default:
                unregister_code(KC_BSPC); break;
        }
    }
    tap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [DOT_COM_QWE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_dcq_finished, td_dcq_reset),
    [DOT_COM_COL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_dcc_finished, td_dcc_reset)
};
