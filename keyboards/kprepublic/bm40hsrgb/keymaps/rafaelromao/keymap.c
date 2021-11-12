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

#include QMK_KEYBOARD_H
#include "rafaelromao.h"

#define LAYOUT_planck_mit_wrapper(...) LAYOUT_planck_mit(__VA_ARGS__)

// Keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

     [_QWERTY] = LAYOUT_planck_mit_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________QWERTY_L1___________________ , XXXXXXX , XXXXXXX , ___________________QWERTY_R1___________________,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________QWERTY_L2___________________ , XXXXXXX , XXXXXXX , ___________________QWERTY_R2___________________,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________QWERTY_L3___________________ , XXXXXXX , XXXXXXX , ___________________QWERTY_R3___________________,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________QWERTY_L4___________________ ,      XXXXXXX      , ___________________QWERTY_R4___________________),
 // |_______________________________________________________________________________________________________________________|

     [_COLEMAK] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_Q    , KC_W    , KC_F    , KC_P    , KC_B    , XXXXXXX , XXXXXXX , KC_J    , KC_L    , KC_U    , KC_Y    , KC_BSPC ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_A    , LSFTT_R , LCTLT_S , LALTT_T , KC_G    , XXXXXXX , XXXXXXX , KC_M    , RALTT_N , RCTLT_E , RSFTT_I , KC_O    ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_Z    , KC_X    , KC_C    , LGUIT_D , KC_V    , XXXXXXX , XXXXXXX , KC_K    , RGUIT_H , KC_COMM , KC_DOT  , KC_SCLN ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , NAV_MOD , LOW_SPC ,      XXXXXXX      , RAI_SPC , MOU_CAP , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_LOWER] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_AT   , KC_UNDS , KC_LCBR , KC_RCBR , SS_TILD , XXXXXXX , XXXXXXX , XXXXXXX , KC_P7   , KC_P8   , KC_P9   , TD_DCQ  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      SS_BTIC , SFT_SQU , CTL_DQU , ALT_AMP , KC_PIPE , XXXXXXX , XXXXXXX , XXXXXXX , RALTT_4 , RCTLT_5 , RSFTT_6 , TD_DCC  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      OS_FUN  , KC_BSLS , KC_LBRC , GUI_RBR , KC_HASH , XXXXXXX , XXXXXXX , XXXXXXX , RGUIT_1 , KC_P2   , KC_P3   , KC_P0   ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX  , _______ ,      XXXXXXX      , OS_RAI , OS_MOU  , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_RAISE] = LAYOUT_planck_mit(
 // |_______________________________ ________________________________________________________________________________________|
      _______ , _______ , _______ , KC_DQUO , _______ , XXXXXXX , XXXXXXX , SS_CIRC , KC_DLR  , KC_LPRN , KC_RPRN , KC_QUES ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      _______ , SFT_CIR , CTL_TIL , ALT_QUO , _______ , XXXXXXX , XXXXXXX , KC_PLUS , ALT_MIN , CTL_EQL , SFT_EXL , KC_SLSH ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      _______ , _______ , _______ , GUI_GRV , _______ , XXXXXXX , XXXXXXX , KC_PERC , GUI_AST , KC_LT   , KC_GT   , KC_COLN ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , OS_NAV  , OS_LOW  ,      XXXXXXX      , _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_FUNCTIONS] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_CAPS , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F7   , KC_F8   , KC_F9   , KC_F12  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , KC_LSFT , KC_LCTL , KC_LALT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F4   , KC_F5   , KC_F6   , KC_F11  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      _______ , XXXXXXX , XXXXXXX , KC_LGUI , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F1   , KC_F2   , KC_F3   , KC_F10  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,      XXXXXXX      , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_NAVIGATION] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_ESC  , XXXXXXX , KC_TAB  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_PGDN , KC_PGUP , KC_ENT  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , OS_LSFT , OS_LCTL , OS_LALT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      MO_MED  , XXXXXXX , XXXXXXX , OS_LGUI , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_INS  , KC_HOME , KC_END  , KC_DEL  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , XXXXXXX ,      XXXXXXX      , XXXXXXX , MO_MAI  , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_MOUSE] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_ESC  , XXXXXXX , KC_TAB  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_WH_D , KC_WH_U , KC_ENT  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , OS_LSFT , OS_LCTL , OS_LALT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_MS_L , KC_MS_D , KC_MS_U , KC_MS_R ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , OS_LGUI , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , CB_NONE , KC_BTN1 , KC_BTN2 , MO_MED ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , MO_MAI  , XXXXXXX ,      XXXXXXX      , XXXXXXX , _______ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_MEDIA] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_MSTP , KC_MNXT , KC_MPRV , KC_MPLY , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_MPLY , KC_MPRV , KC_MNXT , KC_MSTP ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_MUTE , KC_VOLU , KC_VOLD , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_VOLD , KC_VOLU , KC_MUTE ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      _______ , HYPR_V  , HYPR_A  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , HYPR_A  , HYPR_V  , _______ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , XXXXXXX ,      XXXXXXX      , XXXXXXX , _______ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_MAINTENANCE] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      XXXXXXX , RGB_TOG , RGB_MOD , XXXXXXX , EEP_RST , XXXXXXX , XXXXXXX , RESET   , XXXXXXX , CMB_TOG , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      RGB_VAI , RGB_HUI , RGB_SAI , MO_LAY  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , MO_LAY  , NK_TOGG , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      RGB_VAD , RGB_HUD , RGB_SAD , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_SLEP , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , XXXXXXX ,      XXXXXXX      , XXXXXXX , _______ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_LAYERS] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      XXXXXXX , XXXXXXX , DF_QWE  , TO_MAI  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , TO_MAI  , DF_COL  , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , TG_MD_G , _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ , TG_MD_C , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      TO_FUN  , XXXXXXX , XXXXXXX , TO_NAV  , TO_RAI  , XXXXXXX , XXXXXXX , TO_LOW  , TO_MOU  , XXXXXXX , XXXXXXX , TO_MED  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , XXXXXXX ,      XXXXXXX      , XXXXXXX , _______ , XXXXXXX , XXXXXXX , XXXXXXX)
 // |_______________________________________________________________________________________________________________________|

};

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

    bool isOneShotShift = get_oneshot_mods() & MOD_MASK_SHIFT || get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotCtrl = get_oneshot_mods() & MOD_MASK_CTRL || get_oneshot_locked_mods() & MOD_MASK_CTRL;
    bool isOneShotAlt = get_oneshot_mods() & MOD_MASK_ALT || get_oneshot_locked_mods() & MOD_MASK_ALT;
    bool isOneShotGui = get_oneshot_mods() & MOD_MASK_GUI || get_oneshot_locked_mods() & MOD_MASK_GUI;

    if (isOneShotShift) {
        rgb_matrix_set_color(13, RGB_WHITE);
    }
    if (isOneShotCtrl) {
        rgb_matrix_set_color(14, RGB_WHITE);
    }
    if (isOneShotAlt) {
        rgb_matrix_set_color(15, RGB_WHITE);
    }
    if (isOneShotGui) {
        rgb_matrix_set_color(27, RGB_WHITE);
    }

    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _LOWER:
            rgb_matrix_set_color(40, RGB_WHITE);
            break;
        case _RAISE:
            rgb_matrix_set_color(42, RGB_WHITE);
            break;
        case _MEDIA:
            rgb_matrix_set_color(24, RGB_WHITE);
            rgb_matrix_set_color(35, RGB_WHITE);
            break;
        case _FUNCTIONS:
            rgb_matrix_set_color(40, RGB_WHITE);
            rgb_matrix_set_color(42, RGB_WHITE);
            break;
        case _NAVIGATION:
            rgb_matrix_set_color(39, RGB_WHITE);
            break;
        case _MOUSE:
            rgb_matrix_set_color(43, RGB_WHITE);
            break;
        case _MAINTENANCE:
            rgb_matrix_set_color(39, RGB_WHITE);
            rgb_matrix_set_color(43, RGB_WHITE);
            rgb_matrix_set_color(7, RGB_RED);
            break;
        case _LAYERS:
            rgb_matrix_set_color(15, RGB_WHITE);
            rgb_matrix_set_color(20, RGB_WHITE);
            break;
        default:
            break;
    }
}
