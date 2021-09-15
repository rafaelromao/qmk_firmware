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
#define LCTLT_T LCTL_T(KC_T)
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

#define MEH_ESC MEH_T(KC_ESC)
#define HYP_ENT ALL_T(KC_ENT)
#define SPC_MO3 LT(3,KC_SPC)
#define SPC_MO4 LT(4,KC_SPC)
#define SPC_MO2 LT(2,KC_SPC)
#define TAB_MO4 LT(4,KC_TAB)
#define BS_MO4 LT(4,KC_BSPC

#define LGUI_D LGUI(KC_D)
#define LGUI_E LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[COLEMAK] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_Q    , KC_W    , KC_F    , KC_P    , KC_G    , KC_MPLY , KC_MFFD , KC_J    , KC_L    , KC_U    , KC_Y    , KC_BSPC ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      LSFTT_A , LCTLT_R , LGUIT_S , LALTT_T , KC_D    , KC_VOLD , KC_VOLU , KC_H    , RALTT_N , RGUIT_E , RCTLT_I , RSFTT_O ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , LGUI_D  , LGUI_E  , KC_K    , KC_M    , KC_COMM , KC_DOT  , KC_SCLN ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_LCTL , KC_RGUI , KC_LALT , MEH_ESC , SPC_MO3 ,      SPC_MO4      , SPC_MO2 , HYP_ENT , KC_RSFT , KC_TAB  , OSL(2)) ,
 // |_______________________________________________________________________________________________________________________|

    [QWERTY] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_MPLY , KC_MFFD , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      LSFTT_A , LCTLT_S , LGUIT_D , LALTT_F , KC_G    , KC_VOLD , KC_VOLU , KC_H    , RALTT_J , RGUIT_K , RCTLT_L , RSFTT_BS,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , LGUI_D  , LGUI_E  , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SCLN ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_LCTL , KC_RGUI , KC_LALT , MEH_ESC , SPC_MO3 ,      SPC_MO4      , SPC_MO2 , HYP_ENT , KC_RSFT , KC_TAB  , OSL(2) ),
 // |_______________________________________________________________________________________________________________________|

    [SYMBOLS] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_CAPS , KC_LPRN , KC_RPRN , KC_DLR  , KC_PERC , XXXXXXX , XXXXXXX , KC_BSLS , KC_UNDS , KC_QUES , KC_SLSH , KC_MINS ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_AT   , KC_LCBR , KC_RCBR , KC_EQL  , KC_QUOT , XXXXXXX , XXXXXXX , KC_TILD , KC_AMPR , KC_DQUO , KC_ASTR , KC_PLUS ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_HASH , KC_LBRC , KC_RBRC , KC_EXLM , KC_CIRC , XXXXXXX , XXXXXXX , KC_GRV , KC_PIPE , KC_LT    , KC_GT   , KC_COLN ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      _______ , _______ , _______ , _______ , BS_MO4  ,       BS_MO4      , _______ , _______ , _______ , _______ , OSL(3) ),
 // |_______________________________________________________________________________________________________________________|

    [NUMBERS] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_PERC , XXXXXXX , XXXXXXX , KC_P7   , KC_P8   , KC_P9   , KC_PSLS , KC_MINS ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_COMM , XXXXXXX , XXXXXXX , KC_P4   , KC_P5   , KC_P6   , KC_PAST , KC_PLUS ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_DOT  , XXXXXXX , XXXXXXX , KC_P1   , KC_P2   , KC_P3   , KC_P0   , KC_PEQL ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      _______ , _______ , _______ , _______ , _______ ,      TAB_MO4      , TAB_MO4 , _______ , _______ , _______ , OSL(4) ),
 // |_______________________________________________________________________________________________________________________|

 	[NAVIGATION] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_APP  , KC_WH_D , KC_MS_U , KC_WH_U , DF(1)   , XXXXXXX , XXXXXXX , DF(0)   , KC_END  , KC_HOME , KC_INS  , KC_DEL  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_BTN2 , KC_MS_L , KC_MS_D , KC_MS_R , KC_BTN1 , XXXXXXX , XXXXXXX , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , KC_PSTE ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_LEAD , KC_ACL0 , KC_ACL1 , KC_ACL2 , TT(5)   , XXXXXXX , XXXXXXX , TT(4)   , KC_PGDN , KC_PGUP , KC_CUT  , KC_COPY ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      _______ , _______ , _______ , _______ , _______ ,      _______      , _______ , _______ , _______ , _______ , OSL(5) ),
 // |_______________________________________________________________________________________________________________________|

	[MAINTENANCE] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      RGB_TOG , RGB_MOD , BL_ON   , BL_OFF  , _______ , XXXXXXX , XXXXXXX , _______ , XXXXXXX , DEBUG   , EEP_RST , RESET   ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      RGB_VAI , RGB_HUI , RGB_SAI , RGB_SPI , TO(3)   , XXXXXXX , XXXXXXX , TO(2)   , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      RGB_VAD , RGB_HUD , RGB_SAD , RGB_SPD , _______ , XXXXXXX , XXXXXXX , _______ , SLEEP   , XXXXXXX , NK_ON   , NK_OFF  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      _______ , _______ , _______ , _______ , _______ ,      _______      , _______ , _______ , _______ , _______ , OSL(2)  )
 // |_______________________________________________________________________________________________________________________|
};
