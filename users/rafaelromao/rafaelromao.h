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
    MT_ASTR,
    MT_EXLM,
    MT_AMPR,
    MT_CIRC,
    MT_TILD,
    MT_GRV,
    SP_CAP,
    SP_MOD,
    TG_MD_G,
    TG_MD_C,
    CB_NONE
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
#define GUI_AST RGUI_T(MT_ASTR)

#define SFT_SQU RSFT_T(SS_SQUO)
#define CTL_DQU RCTL_T(SS_DQUO)
#define ALT_AMP RALT_T(MT_AMPR)
#define GUI_RBR RGUI_T(KC_RBRC)

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
#define OS_RAI OSL(_RAISE)
#define TO_LOW TO(_LOWER)
#define TG_LOW TG(_LOWER)
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
#define MO_MED MO(_MEDIA)
#define TO_MED TO(_MEDIA)
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
