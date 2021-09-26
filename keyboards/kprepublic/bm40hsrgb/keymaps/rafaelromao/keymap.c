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
  BASE,
  NUMBERS,
  SYMBOLS,
  NAVIGATION,
  MOUSE,
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

#define LCGT_NO MT(MOD_LCTL | MOD_LGUI, KC_NO)
#define LSGT_NO LSG_T(KC_NO)
#define LAGT_NO LAG_T(KC_NO)
#define MEHT_NO MEH_T(KC_NO)
#define HYPT_NO HYPR_T(KC_NO)

#define NAV_ESC LT(NAVIGATION,KC_ESC)
#define NUM_SPC LT(NUMBERS,KC_SPC)
#define SYM_SPC LT(SYMBOLS,KC_SPC)
#define MOU_ENT LT(MOUSE,KC_ENT)
#define NUM_BSP LT(NUMBERS,KC_BSPC)
#define SYM_TAB LT(SYMBOLS,KC_TAB)

#define MAI_ESC LT(MAINTENANCE,KC_ESC)
#define MAI_ENT LT(MAINTENANCE,KC_ENT)

#define HYPR_A HYPR(KC_A)
#define HYPR_V HYPR(KC_V)

#define OSL_SYM OSL(SYMBOLS)
#define OSL_NUM OSL(NUMBERS)
#define OSL_NAV OSL(NAVIGATION)
#define OSL_MOU OSL(MOUSE)
#define OSL_MAI OSL(MAINTENANCE)

#define TO_SYM TO(SYMBOLS)
#define TO_NUM TO(NUMBERS)
#define TO_NAV TO(NAVIGATION)
#define TO_MOU TO(MOUSE)
#define TO_MAI TO(MAINTENANCE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

     [BASE] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_MPLY , KC_MNXT , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      LSFTT_A , LCTLT_S , LGUIT_D , LALTT_F , KC_G    , KC_VOLD , KC_VOLU , KC_H    , RALTT_J , RGUIT_K , RCTLT_L , RSFTT_BS,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      LSGT_Z  , LCGT_X  , MEHT_C  , LAGT_V  , HYPT_B  , HYPR_A  , HYPR_V  , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SCLN ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_RSFT , KC_LCTL , KC_RGUI , NAV_ESC , NUM_SPC ,       KC_SPC      , SYM_SPC , MOU_ENT , KC_LALT , KC_TAB  , OSL_NUM),
 // |_______________________________________________________________________________________________________________________|

     [NUMBERS] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      XXXXXXX , KC_F1   , KC_F2   , KC_F3   , KC_F4   , XXXXXXX , XXXXXXX , XXXXXXX , KC_P7   , KC_P8   , KC_P9   , XXXXXXX , 
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , KC_F5   , KC_F6   , KC_F7   , KC_F8   , XXXXXXX , XXXXXXX , XXXXXXX , KC_P4   , KC_P5   , KC_P6   , KC_PDOT ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , KC_F9   , KC_F10  , KC_F11  , KC_F12  , XXXXXXX , XXXXXXX , XXXXXXX , KC_P1   , KC_P2   , KC_P3   , KC_P0   ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      _______ , _______ , _______ , _______ , _______ ,      KC_TAB       , SYM_TAB , _______ , _______ , _______ , OSL_SYM),
 // |_______________________________________________________________________________________________________________________|

     [SYMBOLS] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      XXXXXXX , KC_LCBR , KC_RCBR , KC_DLR  , KC_PERC , XXXXXXX , XXXXXXX , KC_BSLS , KC_UNDS , KC_LT   , KC_GT   , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_AT   , KC_LPRN , KC_RPRN , KC_EQL  , KC_QUOT , XXXXXXX , XXXXXXX , KC_TILD , KC_AMPR , KC_DQUO , KC_ASTR , KC_PLUS ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_HASH , KC_LBRC , KC_RBRC , KC_EXLM , KC_CIRC , XXXXXXX , XXXXXXX , KC_COLN , KC_PIPE , KC_QUES , KC_SLSH , KC_MINS ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      _______ , _______ , _______ , _______ , NUM_BSP ,      KC_BSPC      , _______ , _______ , _______ , _______ , OSL_NAV),
 // |_______________________________________________________________________________________________________________________|

 	[NAVIGATION] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      XXXXXXX , C(KC_X) , C(KC_C) , C(KC_V) , KC_LOCK , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_END  , KC_HOME , XXXXXXX ,  
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_LSFT , KC_LCTL , KC_LGUI , KC_LALT , KC_LEAD , XXXXXXX , XXXXXXX , XXXXXXX , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      LSGT_NO , LCGT_NO , MEHT_NO , LAGT_NO , HYPT_NO , XXXXXXX , XXXXXXX , XXXXXXX , KC_INS  , KC_PGDN , KC_PGUP , KC_DEL  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      _______ , _______ , _______ , _______ , _______ ,      KC_SPC       , _______ , MAI_ENT , _______ , _______ , OSL_MOU),
 // |_______________________________________________________________________________________________________________________|

 	[MOUSE] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      XXXXXXX , XXXXXXX , KC_MS_U , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_END  , KC_HOME , KC_INS  , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_BTN2 , KC_MS_L , KC_MS_D , KC_MS_R , KC_GRV  , XXXXXXX , XXXXXXX , XXXXXXX , KC_ACL0 , KC_ACL1 , KC_ACL2 , KC_BTN1 ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_LSFT , KC_LCTL , KC_LGUI , KC_LALT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      _______ , _______ , _______ , MAI_ESC , _______ ,      KC_SPC       , _______ , _______ , _______ , _______ , OSL_MAI),
 // |_______________________________________________________________________________________________________________________|

	[MAINTENANCE] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      XXXXXXX , XXXXXXX , RGB_TOG , RGB_MOD , TO_MAI  , XXXXXXX , XXXXXXX , RESET   , DEBUG   , EEP_RST , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      RGB_VAI , RGB_HUI , RGB_SAI , RGB_SPI , TO_NUM  , XXXXXXX , XXXXXXX , TO_SYM  , XXXXXXX , XXXXXXX , BL_ON   , BL_OFF  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      RGB_VAD , RGB_HUD , RGB_SAD , RGB_SPD , TO_NAV  , XXXXXXX , XXXXXXX , TO_MOU  , KC_SLEP , XXXXXXX , NK_ON   , NK_OFF  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      _______ , _______ , _______ , _______ , _______ ,      KC_SPC       , _______ , _______ , _______ , _______ , OSL_NUM)
 // |_______________________________________________________________________________________________________________________|

};

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

     if (host_keyboard_led_state().caps_lock) {
         rgb_matrix_set_color(7, RGB_WHITE);
     }

     switch(get_highest_layer(layer_state|default_layer_state)) {
          case SYMBOLS:
               rgb_matrix_set_color(19, RGB_WHITE);
               break;
          case NUMBERS:
               rgb_matrix_set_color(16, RGB_WHITE);
               break;
          case NAVIGATION:
               rgb_matrix_set_color(28, RGB_WHITE);
               break;
          case MOUSE:
               rgb_matrix_set_color(31, RGB_WHITE);
               break;
          case MAINTENANCE:
               rgb_matrix_set_color(4, RGB_WHITE);
               rgb_matrix_set_color(7, RGB_RED);
               break;
          default:
               break;
    }
}
