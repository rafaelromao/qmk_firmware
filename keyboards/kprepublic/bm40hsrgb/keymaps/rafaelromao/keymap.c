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

#define LSFT_A LSFT_T(KC_A)
#define LCTL_R LCTL_T(KC_R)
#define LGUI_S LGUI_T(KC_S)
#define LALT_T LALT_T(KC_T)
#define LGUI_D LGUI_T(KC_D)
#define LALT_F LALT_T(KC_F)
#define RSFT_O RSFT_T(KC_O)
#define RCTL_I RCTL_T(KC_I)
#define RGUI_E RGUI_T(KC_E)
#define RALT_N RALT_T(KC_N)
#define RSFT_BS RSFT_T(KC_BSPC)
#define RCTL_L RCTL_T(KC_L)
#define RGUI_K RGUI_T(KC_K)
#define RALT_J RALT_T(KC_J)
#define MEH_ESC MEH_T(KC_ESC)
#define HYP_ENT ALL_T(KC_ENT)
#define SP_MO3 LT(3,KC_SPC)
#define SP_MO4 LT(4,KC_SPC)
#define SP_MO2 LT(2,KC_SPC)
#define TAB_MO4 LT(4,KC_TAB)
#define BS_MO4 LT(4,KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak */
	[0] = LAYOUT_planck_mit(
 // |----------------------------------------------------------------------------------------------------------------------------|
        KC_Q         , KC_W         , KC_F         , KC_P         , KC_G         , KC_MPLY      , KC_MFFD      , KC_J         , KC_L         , KC_U         , KC_Y         , KC_BSPC,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
        LSFT_T(KC_A) , LCTL_T(KC_R) , LGUI_T(KC_S) , LALT_T(KC_T) , KC_D         , KC_VOLD      , KC_VOLU      , KC_H         , RALT_T(KC_N) , RGUI_T(KC_E) , RCTL_T(KC_I) , RSFT_T(KC_O),
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
        KC_Z         , KC_X         , KC_C         , KC_V         , KC_B         , LGUI(KC_D)   , LGUI(KC_E)   , KC_K         , KC_M         , KC_COMM      , KC_DOT       , KC_SCLN,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
        KC_LCTL      , KC_RGUI      , KC_LALT      , MEH_T(KC_ESC), LT(3,KC_SPC) ,         LT(4,KC_SPC)        , LT(2,KC_SPC) , ALL_T(KC_ENT), KC_RSFT      , KC_TAB       , OSL(2)),
 // |----------------------------------------------------------------------------------------------------------------------------|

/* Qwerty */
    [1] = LAYOUT_planck_mit(
        KC_Q         , KC_W         , KC_E         , KC_R         , KC_T         , KC_MPLY      , KC_MFFD      , KC_Y         , KC_U         , KC_I         , KC_O         , KC_P,
        LSFT_T(KC_A) , LCTL_T(KC_S) , LGUI_T(KC_D) , LALT_T(KC_F) , KC_G         , KC_VOLD      , KC_VOLU      , KC_H         , RALT_T(KC_J) , RGUI_T(KC_K) , RCTL_T(KC_L) , RSFT_T(KC_BSPC),
        KC_Z         , KC_X         , KC_C         , KC_V         , KC_B         , LGUI(KC_D)   , LGUI(KC_E)   , KC_N         , KC_M         , KC_COMM      , KC_DOT       , KC_SCLN,
        KC_LCTL      , KC_RGUI      , KC_LALT      , MEH_T(KC_ESC), LT(3,KC_SPC) ,         LT(4,KC_SPC)        , LT(2,KC_SPC) , ALL_T(KC_ENT), KC_RSFT      , KC_TAB       , OSL(2)),

/* Symbols
 * |----------------------------------------------------------------------------------------------------------------------------|
 * |   Q    |   W    |   E    |   R    |   T    |  Play  |  Next  |   Y    |   U    |   I    |   O    |   P    |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * | Sht/A  | Ctl/S  | Gui/D  | Alt/F  |   G    |  Vol+  |  Vol-  |   H    | Alt/J  | Gui/K  | Ctl/L  | Sht/BS |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |   Z    |   X    |   C    |   V    |   B    |  Mic   |  Cam   |   N    |   M    |   ,    |   .    |   ;    |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |  Ctrl  |  Gui   |  Alt   | Mh/Esc | Num/Sp |    Nav/Space    | Sym/Sp | Hp/Ent |  Shft  |  Tab   | OSL(2) |
 * |----------------------------------------------------------------------------------------------------------------------------|
 */
    [2] = LAYOUT_planck_mit(
        KC_CAPS      , KC_LPRN      , KC_RPRN      , KC_DLR       , KC_PERC      , KC_NO      , KC_NO        , KC_BSLS      , KC_UNDS      , KC_QUES      , KC_SLSH      , KC_MINS,
        KC_AT        , KC_LCBR      , KC_RCBR      , KC_EQL       , KC_QUOT      , KC_NO      , KC_NO        , KC_TILD      , KC_AMPR      , KC_DQUO      , KC_ASTR      , KC_PLUS,
        KC_HASH      , KC_LBRC      , KC_RBRC      , KC_EXLM      , KC_CIRC      , KC_NO      , KC_NO        , KC_GRV       , KC_PIPE      , KC_LT        , KC_GT        , KC_COLN,
        -------      , -------      , -------      , -------      , LT(4,KC_BSPC)      ,          LT(4,KC_BSPC)           , -------      , -------      , -------      , -------      , OSL(3)),

/* Numbers
 * |----------------------------------------------------------------------------------------------------------------------------|
 * |   Q    |   W    |   E    |   R    |   T    |  Play  |  Next  |   Y    |   U    |   I    |   O    |   P    |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * | Sht/A  | Ctl/S  | Gui/D  | Alt/F  |   G    |  Vol+  |  Vol-  |   H    | Alt/J  | Gui/K  | Ctl/L  | Sht/BS |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |   Z    |   X    |   C    |   V    |   B    |  Mic   |  Cam   |   N    |   M    |   ,    |   .    |   ;    |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |  Ctrl  |  Gui   |  Alt   | Mh/Esc | Num/Sp |    Nav/Space    | Sym/Sp | Hp/Ent |  Shft  |  Tab   | OSL(2) |
 * |----------------------------------------------------------------------------------------------------------------------------|
 */
    [3] = LAYOUT_planck_mit(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_PERC, KC_NO, KC_NO, KC_P7, KC_P8, KC_P9, KC_PSLS, KC_MINS,
        KC_F5, KC_F6, KC_F7, KC_F8, KC_COMM, KC_NO, KC_NO, KC_P4, KC_P5, KC_P6, KC_PAST, KC_PLUS,
        KC_F9, KC_F10, KC_F11, KC_F12, KC_DOT, KC_NO, KC_NO, KC_P1, KC_P2, KC_P3, KC_P0, KC_PEQL,
        -------, -------, -------, -------, -------, LT(4,KC_TAB), LT(4,KC_TAB), -------, -------, -------, OSL(4)),

/* Navigation
 * |----------------------------------------------------------------------------------------------------------------------------|
 * |   Q    |   W    |   E    |   R    |   T    |  Play  |  Next  |   Y    |   U    |   I    |   O    |   P    |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * | Sht/A  | Ctl/S  | Gui/D  | Alt/F  |   G    |  Vol+  |  Vol-  |   H    | Alt/J  | Gui/K  | Ctl/L  | Sht/BS |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |   Z    |   X    |   C    |   V    |   B    |  Mic   |  Cam   |   N    |   M    |   ,    |   .    |   ;    |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |  Ctrl  |  Gui   |  Alt   | Mh/Esc | Num/Sp |    Nav/Space    | Sym/Sp | Hp/Ent |  Shft  |  Tab   | OSL(2) |
 * |----------------------------------------------------------------------------------------------------------------------------|
 */
 	[4] = LAYOUT_planck_mit(KC_APP, KC_WH_D, KC_MS_U, KC_WH_U, DF(1), KC_NO, KC_NO, DF(0), KC_END, KC_HOME, KC_INS, KC_DEL, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_PSTE, KC_LEAD, KC_ACL0, KC_ACL1, KC_ACL2, TT(5), KC_NO, KC_NO, TT(4), KC_PGDN, KC_PGUP, KC_CUT, KC_COPY, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, OSL(5)),
/* Maintenance
 * |----------------------------------------------------------------------------------------------------------------------------|
 * |   Q    |   W    |   E    |   R    |   T    |  Play  |  Next  |   Y    |   U    |   I    |   O    |   P    |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * | Sht/A  | Ctl/S  | Gui/D  | Alt/F  |   G    |  Vol+  |  Vol-  |   H    | Alt/J  | Gui/K  | Ctl/L  | Sht/BS |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |   Z    |   X    |   C    |   V    |   B    |  Mic   |  Cam   |   N    |   M    |   ,    |   .    |   ;    |
 * |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
 * |  Ctrl  |  Gui   |  Alt   | Mh/Esc | Num/Sp |    Nav/Space    | Sym/Sp | Hp/Ent |  Shft  |  Tab   | OSL(2) |
 * |----------------------------------------------------------------------------------------------------------------------------|
 */
	[5] = LAYOUT_planck_mit(RGB_TOG, RGB_MOD, BL_ON, BL_OFF, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO, DEBUG, EEP_RST, RESET, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, TO(3), KC_NO, KC_NO, TO(2), KC_NO, KC_NO, KC_NO, KC_NO, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, KC_TRNS, KC_NO, KC_NO, KC_TRNS, SLEEP, KC_NO, NK_ON, NK_OFF, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};
