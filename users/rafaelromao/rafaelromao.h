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
#include "tapdance.h"

// Layers

enum layers {
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _FUNCTIONS,
  _MOUSE,
  _NAVIGATION,
  _NAVIGATION_CLONE,
  _MEDIA,
  _MAINTENANCE
};

// Custom keycodes

enum custom_keycodes {
    SS_BTIC = SAFE_RANGE,
    SS_DQUO,
    SS_SQUO,
    SS_CIRC,
    SS_TILD,
    SP_CAP,
    SP_MOD,
    TG_MD_G,
    TG_MD_C,
    TG_M_ON,
    TG_M_OF,
    SS_MODP,
    SS_MODM
};

// Mod-taps

#define LSFTT_S LSFT_T(KC_S)
#define LCTLT_D LCTL_T(KC_D)
#define LALTT_F LALT_T(KC_F)
#define LGUIT_V LGUI_T(KC_V)

#define LSFTT_R LSFT_T(KC_R)
#define LCTLT_S LCTL_T(KC_S)
#define LALTT_T LALT_T(KC_T)
#define LGUIT_D LGUI_T(KC_D)

#define RSFTT_L RSFT_T(KC_L)
#define RCTLT_K RCTL_T(KC_K)
#define RALTT_J RALT_T(KC_J)
#define RGUIT_M RGUI_T(KC_M)

#define RSFTT_I RSFT_T(KC_I)
#define RCTLT_E RCTL_T(KC_E)
#define RALTT_N RALT_T(KC_N)
#define RGUIT_H RGUI_T(KC_H)

// One-shot mods

#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)

// Layer-taps

#define MOU_CAP LT(_MOUSE, SP_CAP)
#define MOU_P0  LT(_MOUSE, KC_P0)
#define NAV_MOD LT(_NAVIGATION, SP_MOD)

#define RAI_SPC LT(_RAISE,KC_SPC)
#define LOW_SPC LT(_LOWER,KC_SPC)

#define KCZ_FUN LT(_FUNCTIONS, KC_Z)
#define SCL_MED LT(_MEDIA, KC_SCLN)

// Layer transitions

#define DF_QWE DF(_QWERTY)
#define DF_COL DF(_COLEMAK)
#define TO_RAI TO(_RAISE)
#define TG_RAI TG(_RAISE)
#define TT_RAI TT(_RAISE)
#define OS_RAI OSL(_RAISE)
#define TO_LOW TO(_LOWER)
#define TG_LOW TG(_LOWER)
#define TT_LOW TT(_LOWER)
#define OS_LOW OSL(_LOWER)
#define MO_NAV MO(_NAVIGATION)
#define TO_NAV TO(_NAVIGATION_CLONE)
#define TG_NAV TG(_NAVIGATION_CLONE)
#define MO_MOU MO(_MOUSE)
#define TO_MOU TO(_MOUSE)
#define TG_MOU TG(_MOUSE)
#define MO_MAI MO(_MAINTENANCE)
#define TO_MAI TO(_MAINTENANCE)
#define TO_MED TO(_MEDIA)
#define TG_MED TG(_MEDIA)
#define MO_FUN MO(_FUNCTIONS)
#define TO_FUN TO(_FUNCTIONS)
#define TG_FUN TG(_FUNCTIONS)

// Custom Shortcuts

#define HYPR_A HYPR(KC_A)
#define HYPR_V HYPR(KC_V)

// User data

typedef enum {
    MOD_CG_G,
    MOD_CG_C
} mod_cg_t;

typedef struct {
    mod_cg_t mod_cg;
    bool mouselayer;
    uint16_t capslock_timer;
} user_data_t;

// Keymap

#define ___________________QWERTY_L1___________________ KC_Q    , KC_W    , KC_E    , KC_R    , KC_T
#define ___________________QWERTY_L2___________________ KC_A    , LSFTT_S , LCTLT_D , LALTT_F , KC_G
#define ___________________QWERTY_L3___________________ KCZ_FUN , KC_X    , KC_C    , LGUIT_V , KC_B
#define ____QWERTY_L4____                                                             NAV_MOD , LOW_SPC

#define ___________________QWERTY_R1___________________ KC_Y    , KC_U    , KC_I    , KC_O    , KC_P
#define ___________________QWERTY_R2___________________ KC_H    , RALTT_J , RCTLT_K , RSFTT_L , KC_BSPC
#define ___________________QWERTY_R3___________________ KC_N    , RGUIT_M , KC_COMM , KC_DOT  , SCL_MED
#define ____QWERTY_R4____                               RAI_SPC , MOU_CAP

#define ___________________COLEMAK_L1__________________ KC_Q    , KC_W    , KC_F    , KC_P    , KC_B
#define ___________________COLEMAK_L2__________________ KC_A    , LSFTT_R , LCTLT_S , LALTT_T , KC_G
#define ___________________COLEMAK_L3__________________ KCZ_FUN , KC_X    , KC_C    , LGUIT_D , KC_V
#define ____COLEMAK_L4___                                                             NAV_MOD , LOW_SPC

#define ___________________COLEMAK_R1__________________ KC_J    , KC_L    , KC_U    , KC_Y    , KC_BSPC
#define ___________________COLEMAK_R2__________________ KC_M    , RALTT_N , RCTLT_E , RSFTT_I , KC_O
#define ___________________COLEMAK_R3__________________ KC_K    , RGUIT_H , KC_COMM , KC_DOT  , SCL_MED
#define ____COLEMAK_R4___                               RAI_SPC , MOU_CAP

#define ___________________LOWER_L1____________________ KC_AT   , KC_UNDS , KC_LPRN , KC_RPRN , SS_TILD
#define ___________________LOWER_L2____________________ SS_BTIC , SS_DQUO , SS_SQUO , KC_AMPR , KC_PIPE
#define ___________________LOWER_L3____________________ XXXXXXX , KC_BSLS , KC_LBRC , KC_RBRC , KC_HASH
#define ____LOWER_L4_____                                                             _______ , XXXXXXX

#define ___________________LOWER_R1____________________ XXXXXXX , KC_P7 , KC_P8   , KC_P9   , KC_BSPC
#define ___________________LOWER_R2____________________ XXXXXXX , KC_P4 , KC_P5   , KC_P6   , KC_BSPC
#define ___________________LOWER_R3____________________ XXXXXXX , KC_P1 , KC_P2   , KC_P3   , TD_DOT
#define ____LOWER_R4_____                               OS_RAI  , MOU_P0

#define ___________________RAISE_L1____________________ XXXXXXX , XXXXXXX , _______ , KC_DQUO , XXXXXXX
#define ___________________RAISE_L2____________________ _______ , KC_CIRC , KC_TILD , KC_QUOT , XXXXXXX
#define ___________________RAISE_L3____________________ XXXXXXX , XXXXXXX , _______ , KC_GRV  , XXXXXXX
#define ____RAISE_L4_____                                                             _______ , OS_LOW

#define ___________________RAISE_R1____________________ SS_CIRC , KC_DLR  , KC_LCBR , KC_RCBR , KC_QUES
#define ___________________RAISE_R2____________________ KC_PLUS , KC_MINS , KC_EQL  , KC_EXLM , KC_PERC
#define ___________________RAISE_R3____________________ KC_ASTR , KC_SLSH , KC_LT   , KC_GT   , KC_COLN
#define ____RAISE_R4_____                               XXXXXXX , _______

#define ___________________FUNCTIONS_L1________________ KC_CAPS , XXXXXXX , KC_APP  , XXXXXXX , XXXXXXX
#define ___________________FUNCTIONS_L2________________ XXXXXXX , KC_LSFT , KC_LCTL , KC_LALT , XXXXXXX
#define ___________________FUNCTIONS_L3________________ XXXXXXX , XXXXXXX , XXXXXXX , KC_LGUI , XXXXXXX
#define ____FUNCTIONS_L4_                                                             _______ , XXXXXXX

#define ___________________FUNCTIONS_R1________________ XXXXXXX , KC_F7   , KC_F8   , KC_F9   , KC_F12
#define ___________________FUNCTIONS_R2________________ XXXXXXX , KC_F4   , KC_F5   , KC_F6   , KC_F11
#define ___________________FUNCTIONS_R3________________ XXXXXXX , KC_F1   , KC_F2   , KC_F3   , KC_F10
#define ____FUNCTIONS_R4_                               XXXXXXX , _______

#define ___________________MOUSE_L1____________________ KC_ESC  , XXXXXXX , KC_TAB  , XXXXXXX , XXXXXXX
#define ___________________MOUSE_L2____________________ XXXXXXX , OS_LSFT , OS_LCTL , OS_LALT , KC_BTN1
#define ___________________MOUSE_L3____________________ XXXXXXX , XXXXXXX , XXXXXXX , OS_LGUI , KC_BTN2
#define ____MOUSE_L4_____                                                             MO_MAI  , XXXXXXX

#define ___________________MOUSE_R1____________________ XXXXXXX , XXXXXXX , KC_WH_D , KC_WH_U , KC_ENT
#define ___________________MOUSE_R2____________________ TD_MB13 , KC_MS_L , KC_MS_D , KC_MS_U , KC_MS_R
#define ___________________MOUSE_R3____________________ TD_MB24 , KC_INS  , KC_HOME , KC_END  , KC_DEL
#define ____MOUSE_R4_____                               XXXXXXX , _______

#define ___________________NAVIGATION_L1_______________ KC_ESC  , XXXXXXX , KC_TAB  , XXXXXXX , XXXXXXX
#define ___________________NAVIGATION_L2_______________ XXXXXXX , OS_LSFT , OS_LCTL , OS_LALT , XXXXXXX
#define ___________________NAVIGATION_L3_______________ XXXXXXX , XXXXXXX , XXXXXXX , OS_LGUI , XXXXXXX
#define __NAVIGATION_L4__                                                             MO_MAI  , XXXXXXX

#define ___________________NAVIGATION_R1_______________ XXXXXXX , XXXXXXX , KC_PGDN , KC_PGUP , KC_ENT
#define ___________________NAVIGATION_R2_______________ XXXXXXX , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
#define ___________________NAVIGATION_R3_______________ XXXXXXX , KC_INS  , KC_HOME , KC_END  , KC_DEL
#define __NAVIGATION_R4__                               XXXXXXX , MO_MAI

#define ___________________MEDIA_L1____________________ RGB_TOG , RGB_HUD , RGB_HUI , RGB_MOD , XXXXXXX
#define ___________________MEDIA_L2____________________ XXXXXXX , RGB_VAD , RGB_VAI , XXXXXXX , XXXXXXX
#define ___________________MEDIA_L3____________________ XXXXXXX , RGB_SAD , RGB_SAI , XXXXXXX , XXXXXXX
#define ____MEDIA_L4_____                                                             _______ , XXXXXXX

#define ___________________MEDIA_R1____________________ XXXXXXX , KC_MPLY , KC_MPRV , KC_MNXT , KC_MSTP
#define ___________________MEDIA_R2____________________ SS_MODP , SS_MODM , KC_VOLD , KC_VOLU , KC_MUTE
#define ___________________MEDIA_R3____________________ XXXXXXX , XXXXXXX , HYPR_A  , HYPR_V  , XXXXXXX
#define ____MEDIA_R4_____                               XXXXXXX , _______

#define ___________________MAINTENANCE_L1______________ XXXXXXX , XXXXXXX , DF_QWE  , XXXXXXX , EEP_RST
#define ___________________MAINTENANCE_L2______________ XXXXXXX , XXXXXXX , TG_MD_G , TG_M_ON , XXXXXXX
#define ___________________MAINTENANCE_L3______________ TO_FUN  , XXXXXXX , KC_PWR  , TO_NAV  , TO_LOW
#define __MAINTENANCE_L4_                                                             _______ , XXXXXXX

#define ___________________MAINTENANCE_R1______________ RESET   , XXXXXXX , DF_COL  , XXXXXXX , XXXXXXX
#define ___________________MAINTENANCE_R2______________ XXXXXXX , TG_M_OF , TG_MD_C , XXXXXXX , XXXXXXX
#define ___________________MAINTENANCE_R3______________ TO_RAI  , TO_MOU  , KC_SLEP , XXXXXXX , TO_MED
#define __MAINTENANCE_R4_                               XXXXXXX , _______
