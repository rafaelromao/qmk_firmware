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

#define MOU_CAP LT(_MOUSE, SP_CAP)
#define NAV_MOD LT(_NAVIGATION, SP_MOD)

#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)

#define RAI_SPC LT(_RAISE,KC_SPC)
#define LOW_SPC LT(_LOWER,KC_SPC)

#define TD_DCQ TD(DOT_COM_QWE)
#define TD_DCC TD(DOT_COM_COL)

#define HYPR_A HYPR(KC_A)
#define HYPR_V HYPR(KC_V)

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

// User data
typedef enum {
    MOD_CG_G,
    MOD_CG_C
} mod_cg_t;

typedef struct {
    mod_cg_t mod_cg;
} user_data_t;

// Combos

const uint16_t PROGMEM qwe_ent_combo[] = {RALTT_J, RCTLT_K, RSFTT_L, COMBO_END};
const uint16_t PROGMEM qwe_esc_combo[] = {LSFTT_S, LCTLT_D, LALTT_F, COMBO_END};
const uint16_t PROGMEM qw1_tab_combo[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM qw2_tab_combo[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM col_ent_combo[] = {RALTT_N, RCTLT_E, RSFTT_I, COMBO_END};
const uint16_t PROGMEM col_esc_combo[] = {LSFTT_R, LCTLT_S, LALTT_T, COMBO_END};
const uint16_t PROGMEM co1_tab_combo[] = {KC_W, KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM co2_tab_combo[] = {KC_L, KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM low_adj_combo[] = {RGUIT_1, KC_P2, KC_P3, COMBO_END};
const uint16_t PROGMEM adj_tog_combo[] = {KC_F4, KC_F5, KC_F6, COMBO_END};
const uint16_t PROGMEM qwe_low_combo[] = {RGUIT_M, KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM col_low_combo[] = {RGUIT_H, KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM qwe_rai_combo[] = {KC_X, KC_C, LGUIT_V, COMBO_END};
const uint16_t PROGMEM col_rai_combo[] = {KC_X, KC_C, LGUIT_D, COMBO_END};
const uint16_t PROGMEM qr1_sho_combo[] = {KC_W, KC_E , KC_DQUO , COMBO_END};
const uint16_t PROGMEM cr1_sho_combo[] = {KC_W, KC_F , KC_DQUO , COMBO_END};
const uint16_t PROGMEM rs2_sho_combo[] = {KC_DLR, KC_LPRN, KC_RPRN, COMBO_END};
const uint16_t PROGMEM ls1_sho_combo[] = {KC_UNDS, KC_LCBR, KC_RCBR, COMBO_END};
const uint16_t PROGMEM ls2_sho_combo[] = {KC_P7, KC_P8, KC_P9, COMBO_END};
const uint16_t PROGMEM mou_nav_combo[] = {CB_NONE, KC_BTN1, KC_BTN2, COMBO_END};
const uint16_t PROGMEM nav_tog_combo[] = {KC_LEFT, KC_DOWN, KC_UP, COMBO_END};
const uint16_t PROGMEM mou_tog_combo[] = {KC_MS_L, KC_MS_D, KC_MS_U, COMBO_END};
const uint16_t PROGMEM lo1_tog_combo[] = {SFT_SQU, CTL_DQU, ALT_AMP, COMBO_END};
const uint16_t PROGMEM lo2_tog_combo[] = {RALTT_4, RCTLT_5, RSFTT_6, COMBO_END};
const uint16_t PROGMEM ra1_tog_combo[] = {SFT_CIR, CTL_TIL, ALT_QUO, COMBO_END};
const uint16_t PROGMEM ra2_tog_combo[] = {ALT_MIN, CTL_EQL, SFT_EXL, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(qwe_ent_combo, KC_ENT),
  COMBO(qwe_esc_combo, KC_ESC),
  COMBO(qw1_tab_combo, KC_TAB),
  COMBO(qw2_tab_combo, KC_TAB),
  COMBO(col_ent_combo, KC_ENT),
  COMBO(col_esc_combo, KC_ESC),
  COMBO(co1_tab_combo, KC_TAB),
  COMBO(co2_tab_combo, KC_TAB),
  COMBO(low_adj_combo, TG_FUN),
  COMBO(adj_tog_combo, TG_FUN),
  COMBO(qwe_low_combo, TG_LOW),
  COMBO(col_low_combo, TG_LOW),
  COMBO(qwe_rai_combo, TG_RAI),
  COMBO(col_rai_combo, TG_RAI),
  COMBO(qr1_sho_combo, SH_OS),
  COMBO(cr1_sho_combo, SH_OS),
  COMBO(rs2_sho_combo, SH_OS),
  COMBO(ls1_sho_combo, SH_OS),
  COMBO(ls2_sho_combo, SH_OS),
  COMBO(mou_nav_combo, TG_NAV),
  COMBO(nav_tog_combo, TG_NAV),
  COMBO(mou_tog_combo, TG_MOU),
  COMBO(lo1_tog_combo, TG_LOW),
  COMBO(lo2_tog_combo, TG_LOW),
  COMBO(ra1_tog_combo, TG_RAI),
  COMBO(ra2_tog_combo, TG_RAI)
};

// Keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

     [_QWERTY] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , XXXXXXX , XXXXXXX , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_A    , LSFTT_S , LCTLT_D , LALTT_F , KC_G    , XXXXXXX , XXXXXXX , KC_H    , RALTT_J , RCTLT_K , RSFTT_L , KC_BSPC ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_Z    , KC_X    , KC_C    , LGUIT_V , KC_B    , XXXXXXX , XXXXXXX , KC_N    , RGUIT_M , KC_COMM , KC_DOT  , KC_SCLN ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , NAV_MOD , LOW_SPC ,      XXXXXXX      , RAI_SPC , MOU_CAP , XXXXXXX , XXXXXXX , XXXXXXX),
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

// Custom keycodes

static user_data_t user_data = {
    .mod_cg = MOD_CG_G
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    bool isQwerty = biton32(default_layer_state) == _QWERTY;
    bool isColemak = biton32(default_layer_state) == _COLEMAK;
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

        // Shift+Backspace for Delete

        case KC_BSPC:
            if (record->event.pressed) {
                if (isShifted) {
                    tap_code(KC_DEL);
                    return false;
                }
                return true;
            }

        // Non-basic mod-taps

        case GUI_AST:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    tap_code16(KC_ASTR);
                }
                return false;
            }
            return true;

        case SFT_EXL:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    tap_code16(KC_EXLM);
                }
                return false;
            }
            return true;

        case SFT_SQU:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    SEND_STRING("' ");
                }
                return false;
            }
            return true;

        case CTL_DQU:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    SEND_STRING("\" ");
                }
                return false;
            }
            return true;

        case ALT_AMP:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    tap_code16(KC_AMPR);
                }
                return false;
            }
            return true;

        case SFT_CIR:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    tap_code16(KC_CIRC);
                }
                return false;
            }
            return true;

        case CTL_TIL:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    tap_code16(KC_TILD);
                }
                return false;
            }
            return true;

        case GUI_GRV:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    tap_code16(KC_GRV);
                }
                return false;
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

        // Custom one shot mod-taps

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
            return true;

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

        // Tap dance

        case TD_DCQ:
            if (isColemak) {
                if (record->event.pressed) {
                    register_code(KC_BSPC);
                } else {
                    unregister_code(KC_BSPC);
                }
                return false;
            } else {
                return true;
            }
        case TD_DCC:
            if (isQwerty) {
                if (record->event.pressed) {
                    register_code(KC_BSPC);
                } else {
                    unregister_code(KC_BSPC);
                }
                return false;
            } else {
                return true;
            }

        default:
            return true;
    }
}

// Tap-hold configuration

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RSFTT_6:
        case RCTLT_5:
        case RALTT_4:
        case RGUIT_1:
            return true;
        default:
            return false;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
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
    bool isQwerty = biton32(default_layer_state) == _QWERTY;
    if (isQwerty) {
        switch (tap_state.state) {
            case TD_SINGLE_TAP: register_code(KC_DOT); break;
            case TD_DOUBLE_TAP: register_code(KC_COMM); break;
            default: break;
        }
    }
}

void td_dcq_reset(qk_tap_dance_state_t *state, void *user_data) {
    bool isQwerty = biton32(default_layer_state) == _QWERTY;
    if (isQwerty) {
        switch (tap_state.state) {
            case TD_SINGLE_TAP: unregister_code(KC_DOT); break;
            case TD_DOUBLE_TAP: unregister_code(KC_COMM); break;
            default: break;
        }
    }
    tap_state.state = TD_NONE;
}

void td_dcc_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    bool isColemak = biton32(default_layer_state) == _COLEMAK;
    if (isColemak) {
        switch (tap_state.state) {
            case TD_SINGLE_TAP: register_code(KC_DOT); break;
            case TD_DOUBLE_TAP: register_code(KC_COMM); break;
            default: break;
        }
    }
}

void td_dcc_reset(qk_tap_dance_state_t *state, void *user_data) {
    bool isColemak = biton32(default_layer_state) == _COLEMAK;
    if (isColemak) {
        switch (tap_state.state) {
            case TD_SINGLE_TAP: unregister_code(KC_DOT); break;
            case TD_DOUBLE_TAP: unregister_code(KC_COMM); break;
            default: break;
        }
    }
    tap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [DOT_COM_QWE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_dcq_finished, td_dcq_reset),
    [DOT_COM_COL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_dcc_finished, td_dcc_reset)
};
