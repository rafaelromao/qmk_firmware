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

// Layers

enum layers {
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _FUNCTIONS,
  _NAVIGATION,
  _MOUSE,
  _MEDIA,
  _MAINTENANCE,
  _LAYERS
};

// Custom keycodes

enum custom_keycodes {
    SS_BTIC = SAFE_RANGE,
    SS_DQUO,
    SS_SQUO,
    SS_CIRC,
    SS_TILD,
    MT_EXLM,
    MT_AMPR,
    MT_CIRC,
    MT_TILD,
    MT_GRV,
    SP_CAP,
    SP_MOD,
    TG_MD_G,
    TG_MD_C,
    CB_NONE,
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

#define RSFTT_6 RSFT_T(KC_P6)
#define RCTLT_5 RCTL_T(KC_P5)
#define RALTT_4 RALT_T(KC_P4)
#define RGUIT_1 RGUI_T(KC_P1)

#define SFT_EXL RSFT_T(MT_EXLM)
#define CTL_EQL RCTL_T(KC_EQL)
#define ALT_MIN RALT_T(KC_MINS)
#define GUI_SLS RGUI_T(KC_SLSH)

#define SFT_SQU LSFT_T(SS_SQUO)
#define CTL_DQU LCTL_T(SS_DQUO)
#define ALT_AMP LALT_T(MT_AMPR)
#define GUI_RBR LGUI_T(KC_RBRC)

#define SFT_CIR LSFT_T(MT_CIRC)
#define CTL_TIL LCTL_T(MT_TILD)
#define ALT_QUO LALT_T(KC_QUOT)
#define GUI_GRV LGUI_T(MT_GRV)

// One-shot mods

#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)

// Layer-taps

#define MOU_CAP LT(_MOUSE, SP_CAP)
#define NAV_MOD LT(_NAVIGATION, SP_MOD)

#define RAI_SPC LT(_RAISE,KC_SPC)
#define LOW_SPC LT(_LOWER,KC_SPC)

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
#define TO_NAV TO(_NAVIGATION)
#define TG_NAV TG(_NAVIGATION)
#define OS_NAV OSL(_NAVIGATION)
#define MO_MOU MO(_MOUSE)
#define TO_MOU TO(_MOUSE)
#define TG_MOU TG(_MOUSE)
#define OS_MOU OSL(_MOUSE)
#define MO_MAI MO(_MAINTENANCE)
#define TO_MAI TO(_MAINTENANCE)
#define TT_MED TT(_MEDIA)
#define TO_MED TO(_MEDIA)
#define TG_MED TG(_MEDIA)
#define MO_LAY MO(_LAYERS)
#define MO_FUN MO(_FUNCTIONS)
#define TO_FUN TO(_FUNCTIONS)
#define TG_FUN TG(_FUNCTIONS)
#define OS_FUN OSL(_FUNCTIONS)

// Custom Shortcuts

#define HYPR_A HYPR(KC_A)
#define HYPR_V HYPR(KC_V)

// Tap dance

#define TD_DCQ TD(DOT_COM_QWE)
#define TD_DCC TD(DOT_COM_COL)

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

td_state_t dance_state(qk_tap_dance_state_t *state);
void td_dcq_finished(qk_tap_dance_state_t *state, void *user_data);
void td_dcq_reset(qk_tap_dance_state_t *state, void *user_data);
void td_dcc_finished(qk_tap_dance_state_t *state, void *user_data);
void td_dcc_reset(qk_tap_dance_state_t *state, void *user_data);

enum {
    DOT_COM_QWE,
    DOT_COM_COL
};

// User data

typedef enum {
    MOD_CG_G,
    MOD_CG_C
} mod_cg_t;

typedef struct {
    mod_cg_t mod_cg;
} user_data_t;

// Keymap

#define ___________________QWERTY_L1___________________ KC_Q    , KC_W    , KC_E    , KC_R    , KC_T
#define ___________________QWERTY_L2___________________ KC_A    , LSFTT_S , LCTLT_D , LALTT_F , KC_G
#define ___________________QWERTY_L3___________________ KC_Z    , KC_X    , KC_C    , LGUIT_V , KC_B
#define ____QWERTY_L4____                                                             NAV_MOD , LOW_SPC

#define ___________________QWERTY_R1___________________ KC_Y    , KC_U    , KC_I    , KC_O    , KC_P
#define ___________________QWERTY_R2___________________ KC_H    , RALTT_J , RCTLT_K , RSFTT_L , KC_BSPC
#define ___________________QWERTY_R3___________________ KC_N    , RGUIT_M , KC_COMM , KC_DOT  , KC_SCLN
#define ____QWERTY_R4____                               RAI_SPC , MOU_CAP

#define ___________________COLEMAK_L1__________________ KC_Q    , KC_W    , KC_F    , KC_P    , KC_B
#define ___________________COLEMAK_L2__________________ KC_A    , LSFTT_R , LCTLT_S , LALTT_T , KC_G
#define ___________________COLEMAK_L3__________________ KC_Z    , KC_X    , KC_C    , LGUIT_D , KC_V
#define ____COLEMAK_L4___                                                             NAV_MOD , LOW_SPC

#define ___________________COLEMAK_R1__________________ KC_J    , KC_L    , KC_U    , KC_Y    , KC_BSPC
#define ___________________COLEMAK_R2__________________ KC_M    , RALTT_N , RCTLT_E , RSFTT_I , KC_O
#define ___________________COLEMAK_R3__________________ KC_K    , RGUIT_H , KC_COMM , KC_DOT  , KC_SCLN
#define ____COLEMAK_R4___                               RAI_SPC , MOU_CAP

#define ___________________LOWER_L1____________________ KC_AT   , KC_UNDS , KC_LCBR , KC_RCBR , SS_TILD
#define ___________________LOWER_L2____________________ SS_BTIC , SFT_SQU , CTL_DQU , ALT_AMP , KC_PIPE
#define ___________________LOWER_L3____________________ OS_FUN  , KC_BSLS , KC_LBRC , GUI_RBR , KC_HASH
#define ____LOWER_L4_____                                                             XXXXXXX , _______

#define ___________________LOWER_R1____________________ XXXXXXX , KC_P7   , KC_P8   , KC_P9   , TD_DCQ
#define ___________________LOWER_R2____________________ XXXXXXX , RALTT_4 , RCTLT_5 , RSFTT_6 , TD_DCC
#define ___________________LOWER_R3____________________ XXXXXXX , RGUIT_1 , KC_P2   , KC_P3   , KC_P0
#define ____LOWER_R4_____                               OS_RAI  , OS_MOU

#define ___________________RAISE_L1____________________ _______ , _______ , _______ , KC_DQUO , _______
#define ___________________RAISE_L2____________________ _______ , SFT_CIR , CTL_TIL , ALT_QUO , _______
#define ___________________RAISE_L3____________________ _______ , _______ , _______ , GUI_GRV , _______
#define ____RAISE_L4_____                                                             OS_NAV  , OS_LOW

#define ___________________RAISE_R1____________________ SS_CIRC , KC_DLR  , KC_LPRN , KC_RPRN , KC_QUES
#define ___________________RAISE_R2____________________ KC_PLUS , ALT_MIN , CTL_EQL , SFT_EXL , KC_PERC
#define ___________________RAISE_R3____________________ KC_ASTR , GUI_SLS , KC_LT   , KC_GT   , KC_COLN
#define ____RAISE_R4_____                               _______ , XXXXXXX

#define ___________________FUNCTIONS_L1________________ KC_CAPS , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define ___________________FUNCTIONS_L2________________ XXXXXXX , KC_LSFT , KC_LCTL , KC_LALT , XXXXXXX
#define ___________________FUNCTIONS_L3________________ _______ , XXXXXXX , XXXXXXX , KC_LGUI , XXXXXXX
#define ____FUNCTIONS_L4_                                                             XXXXXXX , XXXXXXX

#define ___________________FUNCTIONS_R1________________ XXXXXXX , KC_F7   , KC_F8   , KC_F9   , KC_F12
#define ___________________FUNCTIONS_R2________________ XXXXXXX , KC_F4   , KC_F5   , KC_F6   , KC_F11
#define ___________________FUNCTIONS_R3________________ XXXXXXX , KC_F1   , KC_F2   , KC_F3   , KC_F10
#define ____FUNCTIONS_R4_ XXXXXXX , XXXXXXX

#define ___________________NAVIGATION_L1_______________ KC_ESC  , XXXXXXX , KC_TAB  , XXXXXXX , XXXXXXX
#define ___________________NAVIGATION_L2_______________ XXXXXXX , OS_LSFT , OS_LCTL , OS_LALT , XXXXXXX
#define ___________________NAVIGATION_L3_______________ TT_MED  , XXXXXXX , XXXXXXX , OS_LGUI , XXXXXXX
#define __NAVIGATION_L4__                                                             _______ , XXXXXXX

#define ___________________NAVIGATION_R1_______________ XXXXXXX , XXXXXXX , KC_PGDN , KC_PGUP , KC_ENT
#define ___________________NAVIGATION_R2_______________ XXXXXXX , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
#define ___________________NAVIGATION_R3_______________ XXXXXXX , KC_INS  , KC_HOME , KC_END  , KC_DEL
#define __NAVIGATION_R4__                               XXXXXXX , MO_MAI

#define ___________________MOUSE_L1____________________ KC_ESC  , XXXXXXX , KC_TAB  , XXXXXXX , XXXXXXX
#define ___________________MOUSE_L2____________________ XXXXXXX , OS_LSFT , OS_LCTL , OS_LALT , XXXXXXX
#define ___________________MOUSE_L3____________________ XXXXXXX , XXXXXXX , XXXXXXX , OS_LGUI , XXXXXXX
#define ____MOUSE_L4_____                                                             MO_MAI  , XXXXXXX

#define ___________________MOUSE_R1____________________ XXXXXXX , XXXXXXX , KC_WH_D , KC_WH_U , KC_ENT
#define ___________________MOUSE_R2____________________ XXXXXXX , KC_MS_L , KC_MS_D , KC_MS_U , KC_MS_R
#define ___________________MOUSE_R3____________________ XXXXXXX , CB_NONE , KC_BTN1 , KC_BTN2 , TT_MED
#define ____MOUSE_R4_____                               XXXXXXX , _______

#define ___________________MEDIA_L1____________________ KC_MSTP , KC_MNXT , KC_MPRV , KC_MPLY , XXXXXXX
#define ___________________MEDIA_L2____________________ KC_MUTE , KC_VOLU , KC_VOLD , SS_MODM , SS_MODP
#define ___________________MEDIA_L3____________________ _______ , HYPR_V  , HYPR_A  , XXXXXXX , XXXXXXX
#define ____MEDIA_L4_____                                                             _______ , XXXXXXX

#define ___________________MEDIA_R1____________________ XXXXXXX , KC_MPLY , KC_MPRV , KC_MNXT , KC_MSTP
#define ___________________MEDIA_R2____________________ SS_MODP , SS_MODM , KC_VOLD , KC_VOLU , KC_MUTE
#define ___________________MEDIA_R3____________________ XXXXXXX , XXXXXXX , HYPR_A  , HYPR_V  , _______
#define ____MEDIA_R4_____                               XXXXXXX , _______

#define ___________________MAINTENANCE_L1______________ XXXXXXX , RGB_TOG , RGB_MOD , XXXXXXX , EEP_RST
#define ___________________MAINTENANCE_L2______________ RGB_VAI , RGB_HUI , RGB_SAI , MO_LAY  , XXXXXXX
#define ___________________MAINTENANCE_L3______________ RGB_VAD , RGB_HUD , RGB_SAD , XXXXXXX , XXXXXXX
#define __MAINTENANCE_L4_                                                             _______ , XXXXXXX

#define ___________________MAINTENANCE_R1______________ RESET   , XXXXXXX , CMB_TOG , XXXXXXX , XXXXXXX
#define ___________________MAINTENANCE_R2______________ XXXXXXX , MO_LAY  , NK_TOGG , XXXXXXX , XXXXXXX
#define ___________________MAINTENANCE_R3______________ XXXXXXX , XXXXXXX , KC_SLEP , XXXXXXX , XXXXXXX
#define __MAINTENANCE_R4_                               XXXXXXX , _______

#define ___________________LAYERS_L1___________________ XXXXXXX , XXXXXXX , DF_QWE  , TO_MAI  , XXXXXXX
#define ___________________LAYERS_L2___________________ XXXXXXX , XXXXXXX , TG_MD_G , _______ , XXXXXXX
#define ___________________LAYERS_L3___________________ TO_FUN  , XXXXXXX , XXXXXXX , TO_NAV  , TO_RAI
#define ____LAYERS_L4____                                                             _______ , XXXXXXX

#define ___________________LAYERS_R1___________________ XXXXXXX , TO_MAI  , DF_COL  , XXXXXXX , XXXXXXX
#define ___________________LAYERS_R2___________________ XXXXXXX , _______ , TG_MD_C , XXXXXXX , XXXXXXX
#define ___________________LAYERS_R3___________________ TO_LOW  , TO_MOU  , XXXXXXX , XXXXXXX , TO_MED
#define ____LAYERS_R4____                               XXXXXXX , _______
