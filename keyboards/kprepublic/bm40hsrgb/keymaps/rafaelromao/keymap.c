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

enum layers {
  COLEMAK,
  QWERTY,
  SYMBOLS,
  NUMBERS,
  NAVIGATION,
  MAINTENANCE
};

#define LSFTT_A LSFT_T(KC_A)
#define LCTLT_R LCTL_T(KC_R)
#define LGUIT_S LGUI_T(KC_S)
#define LALTT_T LALT_T(KC_T)

#define LCTLT_S LCTL_T(KC_S)
#define LGUIT_D LGUI_T(KC_D)
#define LALTT_F LALT_T(KC_F)

#define RSFTT_O RSFT_T(KC_O)
#define RCTLT_I RCTL_T(KC_I)
#define RGUIT_E RGUI_T(KC_E)
#define RALTT_N RALT_T(KC_N)

#define RSFTT_BS RSFT_T(KC_BSPC)
#define RCTLT_L RCTL_T(KC_L)
#define RGUIT_K RGUI_T(KC_K)
#define RALTT_J RALT_T(KC_J)

#define LSGT_Z LSG_T(KC_Z)
#define LCGT_X MT(MOD_LCTL | MOD_LGUI, KC_X)
#define MEHT_C MEH_T(KC_C)
#define LAGT_V LAG_T(KC_V)
#define HYPT_B HYPR_T(KC_B)

#define NAV_ESC LT(NAVIGATION,KC_ESC)
#define NAV_ENT LT(NAVIGATION,KC_ENT)
#define NUM_SPC LT(NUMBERS,KC_SPC)
#define NAV_SPC LT(NAVIGATION,KC_SPC)
#define SYM_SPC LT(SYMBOLS,KC_SPC)
#define MAI_TAB LT(MAINTENANCE,KC_TAB)
#define MAI_BS LT(MAINTENANCE,KC_BSPC)

#define LGUI_D LGUI(KC_D)
#define LGUI_E LGUI(KC_E)

#define OSL_SYM OSL(SYMBOLS)
#define OSL_NUM OSL(NUMBERS)
#define OSL_NAV OSL(NAVIGATION)
#define OSL_MAI OSL(MAINTENANCE)

#define DF_QWER DF(QWERTY)
#define DF_COLE DF(COLEMAK)
#define TO_QWER TO(QWERTY)
#define TO_COLE TO(COLEMAK)
#define TO_SYM TO(SYMBOLS)
#define TO_NUM TO(NUMBERS)
#define TO_NAV TO(NAVIGATION)
#define TO_MAI TO(MAINTENANCE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[COLEMAK] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_Q    , KC_W    , KC_F    , KC_P    , KC_G    , KC_MPLY , KC_MFFD , KC_J    , KC_L    , KC_U    , KC_Y    , KC_BSPC ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      LSFTT_A , LCTLT_R , LGUIT_S , LALTT_T , KC_D    , KC_VOLD , KC_VOLU , KC_H    , RALTT_N , RGUIT_E , RCTLT_I , RSFTT_O ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      LSGT_Z  , LCGT_X  , MEHT_C  , LAGT_V  , HYPT_B  , LGUI_D  , LGUI_E  , KC_K    , KC_M    , KC_COMM , KC_DOT  , KC_SCLN ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_LCTL , KC_RGUI , KC_LALT , NAV_ESC , NUM_SPC ,      KC_SPC       , SYM_SPC , NAV_ENT , KC_RSFT , KC_TAB  , OSL_SYM),
 // |_______________________________________________________________________________________________________________________|

    [QWERTY] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_MPLY , KC_MFFD , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      LSFTT_A , LCTLT_S , LGUIT_D , LALTT_F , KC_G    , KC_VOLD , KC_VOLU , KC_H    , RALTT_J , RGUIT_K , RCTLT_L , RSFTT_BS,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      LSGT_Z  , LCGT_X  , MEHT_C  , LAGT_V  , HYPT_B  , LGUI_D  , LGUI_E  , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SCLN ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_LCTL , KC_RGUI , KC_LALT , NAV_ESC , NUM_SPC ,      KC_SPC       , SYM_SPC , NAV_ENT , KC_RSFT , KC_TAB  , OSL_SYM),
 // |_______________________________________________________________________________________________________________________|

    [SYMBOLS] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_CAPS , KC_LCBR , KC_RCBR , KC_DLR  , KC_PERC , XXXXXXX , XXXXXXX , KC_BSLS , KC_UNDS , KC_QUES , KC_SLSH , KC_MINS ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_AT   , KC_LPRN , KC_RPRN , KC_EQL  , KC_QUOT , XXXXXXX , XXXXXXX , KC_TILD , KC_AMPR , KC_DQUO , KC_ASTR , KC_PLUS ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_HASH , KC_LBRC , KC_RBRC , KC_EXLM , KC_CIRC , XXXXXXX , XXXXXXX , KC_GRV , KC_PIPE , KC_LT    , KC_GT   , KC_COLN ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      _______ , _______ , _______ , _______ , MAI_BS  ,      KC_BSPC      , _______ , _______ , _______ , _______ , OSL_NUM),
 // |_______________________________________________________________________________________________________________________|

    [NUMBERS] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_PERC , XXXXXXX , XXXXXXX , KC_P7   , KC_P8   , KC_P9   , KC_PSLS , KC_MINS ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_COMM , XXXXXXX , XXXXXXX , KC_P4   , KC_P5   , KC_P6   , KC_PAST , KC_PLUS ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_DOT  , XXXXXXX , XXXXXXX , KC_P1   , KC_P2   , KC_P3   , KC_P0   , KC_EQL  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      _______ , _______ , _______ , _______ , _______ ,      KC_TAB       , MAI_TAB , _______ , _______ , _______ , OSL_NAV),
 // |_______________________________________________________________________________________________________________________|

 	[NAVIGATION] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_APP  , KC_WH_D , KC_MS_U , KC_WH_U , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_END  , KC_HOME , KC_INS  , KC_DEL  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_BTN2 , KC_MS_L , KC_MS_D , KC_MS_R , KC_BTN1 , XXXXXXX , XXXXXXX , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , KC_PSTE ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_LEAD , KC_ACL0 , KC_ACL1 , KC_ACL2 , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_PGDN , KC_PGUP , KC_CUT  , KC_COPY ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      _______ , _______ , _______ , _______ , _______ ,      KC_SPC       , _______ , _______ , _______ , _______ , OSL_MAI),
 // |_______________________________________________________________________________________________________________________|

	[MAINTENANCE] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      RGB_TOG , RGB_MOD , XXXXXXX , DF_QWER , TO_QWER , XXXXXXX , XXXXXXX , TO_COLE , DF_COLE , DEBUG   , EEP_RST , RESET   ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      RGB_VAI , RGB_HUI , RGB_SAI , RGB_SPI , TO_NUM  , XXXXXXX , XXXXXXX , TO_SYM  , XXXXXXX , XXXXXXX , BL_ON   , BL_OFF  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      RGB_VAD , RGB_HUD , RGB_SAD , RGB_SPD , TO_MAI  , XXXXXXX , XXXXXXX , TO_NAV  , KC_SLEP , XXXXXXX , NK_ON   , NK_OFF  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      _______ , _______ , _______ , _______ , _______ ,      KC_SPC       , _______ , _______ , _______ , _______ , OSL_SYM)
 // |_______________________________________________________________________________________________________________________|
};

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

     if (host_keyboard_led_state().caps_lock) {
         RGB_MATRIX_INDICATOR_SET_COLOR(0, 255, 255, 255);
     } else {
         RGB_MATRIX_INDICATOR_SET_COLOR(0, 0, 0, 0);
     }

     switch(get_highest_layer(layer_state|default_layer_state)) {
          case QWERTY:
               rgb_matrix_set_color(4, RGB_WHITE);
               break;
          case COLEMAK:
               rgb_matrix_set_color(7, RGB_WHITE);
               break;
          case SYMBOLS:
               rgb_matrix_set_color(19, RGB_WHITE);
               break;
          case NUMBERS:
               rgb_matrix_set_color(16, RGB_WHITE);
               break;
          case NAVIGATION:
               rgb_matrix_set_color(31, RGB_WHITE);
               break;
          case MAINTENANCE:
               rgb_matrix_set_color(28, RGB_RED);
               break;
          default:
               break;
    }
}
