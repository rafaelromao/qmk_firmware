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
  FUCTIONS1,
  FUCTIONS2,
  NAVIGATION,
  MOUSE,
  MEDIA,
  MAINTENANCE,
  LAYERS
};

// Custom keycodes

#define LSFTT_A LSFT_T(KC_A)
#define LCTLT_R LCTL_T(KC_R)
#define LALTT_S LALT_T(KC_S)
#define LGUIT_T LGUI_T(KC_T)

#define LCTLT_S LCTL_T(KC_S)
#define LALTT_D LALT_T(KC_D)
#define LGUIT_F LGUI_T(KC_F)

#define RSFTT_O RSFT_T(KC_O)
#define RCTLT_I RCTL_T(KC_I)
#define RALTT_E RALT_T(KC_E)
#define RGUIT_N RGUI_T(KC_N)

#define RCTLT_6 RCTL_T(KC_P6)
#define RALTT_5 RALT_T(KC_P5)
#define RGUIT_4 RGUI_T(KC_P4)

#define RSFTT_BS RSFT_T(KC_BSPC)
#define RCTLT_L RCTL_T(KC_L)
#define RALTT_K RALT_T(KC_K)
#define RGUIT_J RGUI_T(KC_J)

#define NAV_SPC LT(NAVIGATION,KC_SPC)
#define SYM_SPC LT(SYMBOLS,KC_SPC)
#define NUM_SPC LT(NUMBERS,KC_SPC)
#define MOU_SPC LT(MOUSE,KC_SPC)

#define SFT_DOT TD(SFT_DOT_COM)
#define SFT_ESC LSFT_T(KC_ESC)
#define SFT_ENT RSFT_T(KC_ENT)

#define MAI_ESC LT(MAINTENANCE,KC_ESC)
#define MAI_ENT LT(MAINTENANCE,KC_ENT)

#define HYPR_A HYPR(KC_A)
#define HYPR_V HYPR(KC_V)

#define DF_QWE DF(QWERTY)
#define DF_COL DF(COLEMAK)
#define TO_SYM TO(SYMBOLS)
#define OS_SYM OSL(SYMBOLS)
#define TO_NUM TO(NUMBERS)
#define TO_NAV TO(NAVIGATION)
#define TG_NAV TG(NAVIGATION)
#define TO_MOU TO(MOUSE)
#define TO_MAI TO(MAINTENANCE)
#define MO_MED MO(MEDIA)
#define MO_LAY MO(LAYERS)
#define TT_FN1 TT(FUCTIONS1)
#define TO_FN1 TO(FUCTIONS1)
#define TG_FN1 TG(FUCTIONS1)
#define TT_FN2 TT(FUCTIONS2)
#define TO_FN2 TO(FUCTIONS2)
#define TG_FN2 TG(FUCTIONS2)
#define TO_MED TO(MEDIA)
#define TO_ACC TO(ACCENTUATION)
#define TO_OP TO(OPERATIONS)

// Tap dance settings

typedef enum {
    TD_NONE,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP
} td_state_t;

typedef struct {
    td_state_t state;
} td_tap_t;

enum {
    SFT_DOT_COM
};

td_state_t dance_state(qk_tap_dance_state_t *state);

void dance_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_reset(qk_tap_dance_state_t *state, void *user_data);

// Combos

const uint16_t PROGMEM qwe_ent_combo[] = {RGUIT_J, RALTT_K, RCTLT_L, COMBO_END};
const uint16_t PROGMEM qwe_esc_combo[] = {LCTLT_S, LALTT_D, LGUIT_F, COMBO_END};
const uint16_t PROGMEM qwe_tab_combo[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM col_ent_combo[] = {RGUIT_N, RALTT_E, RCTLT_I, COMBO_END};
const uint16_t PROGMEM col_esc_combo[] = {LCTLT_R, LALTT_S, LGUIT_T, COMBO_END};
const uint16_t PROGMEM col_tab_combo[] = {KC_L, KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM num_fn1_combo[] = {RGUIT_4, RALTT_5, RCTLT_6, COMBO_END};
const uint16_t PROGMEM fn1_fn2_combo[] = {KC_F4, KC_F5, KC_F6, COMBO_END};
const uint16_t PROGMEM fn2_tog_combo[] = {KC_F10, KC_F11, KC_F12, COMBO_END};
const uint16_t PROGMEM fn1_tog_combo[] = {KC_F1, KC_F2, KC_F3, COMBO_END};
const uint16_t PROGMEM num_sym_combo[] = {KC_P1, KC_P2, KC_P3, COMBO_END};
const uint16_t PROGMEM rsy_sho_combo[] = {KC_PERC, KC_LT, KC_GT, COMBO_END};
const uint16_t PROGMEM lsy_sho_combo[] = {KC_LBRC, KC_RBRC, KC_BSLS, COMBO_END};
const uint16_t PROGMEM num_sho_combo[] = {KC_P7, KC_P8, KC_P9, COMBO_END};
const uint16_t PROGMEM mou_nav_combo[] = {KC_ACL0, KC_ACL1, KC_ACL2, COMBO_END};
const uint16_t PROGMEM nav_tog_combo[] = {KC_INS , KC_PGDN , KC_PGUP, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(qwe_ent_combo, KC_ENT),
  COMBO(qwe_esc_combo, KC_ESC),
  COMBO(qwe_tab_combo, KC_TAB),
  COMBO(col_ent_combo, KC_ENT),
  COMBO(col_esc_combo, KC_ESC),
  COMBO(col_tab_combo, KC_TAB),
  COMBO(num_fn1_combo, TG_FN1),
  COMBO(fn1_fn2_combo, TG_FN2),
  COMBO(fn2_tog_combo, TG_FN2),
  COMBO(fn1_tog_combo, TG_FN1),
  COMBO(num_sym_combo, OS_SYM),
  COMBO(rsy_sho_combo, SH_OS),
  COMBO(lsy_sho_combo, SH_OS),
  COMBO(num_sho_combo, SH_OS),
  COMBO(mou_nav_combo, TG_NAV),
  COMBO(nav_tog_combo, TG_NAV)
};

// Keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

     [QWERTY] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , XXXXXXX , XXXXXXX , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      LSFTT_A , LCTLT_S , LALTT_D , LGUIT_F , KC_G    , XXXXXXX , XXXXXXX , KC_H    , RGUIT_J , RALTT_K , RCTLT_L , RSFTT_BS,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , XXXXXXX , XXXXXXX , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SCLN ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , NAV_SPC , SYM_SPC ,      XXXXXXX      , NUM_SPC , MOU_SPC , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [COLEMAK] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_Q    , KC_W    , KC_F    , KC_P    , KC_B    , XXXXXXX , XXXXXXX , KC_J    , KC_L    , KC_U    , KC_Y    , KC_BSPC ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      LSFTT_A , LCTLT_R , LALTT_S , LGUIT_T , KC_G    , XXXXXXX , XXXXXXX , KC_M    , RGUIT_N , RALTT_E , RCTLT_I , RSFTT_O ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_Z    , KC_X    , KC_C    , KC_D    , KC_V    , XXXXXXX , XXXXXXX , KC_K    , KC_H    , KC_COMM , KC_DOT  , KC_SCLN ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , NAV_SPC , SYM_SPC ,      XXXXXXX      , NUM_SPC , MOU_SPC , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [NUMBERS] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      XXXXXXX , KC_TILD , KC_QUOT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_P7   , KC_P8   , KC_P9   , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_SLSH , KC_ASTR , KC_MINS , KC_PLUS , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , RGUIT_4 , RALTT_5 , RCTLT_6 , SFT_DOT ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      TT_FN1  , KC_GRV  , KC_CIRC , TT_FN2  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_P1   , KC_P2   , KC_P3   , KC_P0   ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , KC_BSPC ,      XXXXXXX      , _______ , _______ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [SYMBOLS] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      XXXXXXX , KC_LCBR , KC_RCBR , KC_UNDS , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_DLR  , KC_QUES , KC_HASH , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_EXLM , KC_LPRN , KC_RPRN , KC_EQL  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_AMPR , KC_DQUO , KC_AT   , KC_PIPE ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      SH_OS   , KC_LBRC , KC_RBRC , KC_BSLS , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_PERC , KC_LT   , KC_GT   , KC_COLN ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , _______ ,      XXXXXXX      , KC_TAB  , _______ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [FUCTIONS1] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F7   , KC_F8   , KC_F9   , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_LSFT , KC_LCTL , KC_LALT , KC_LGUI , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F4   , KC_F5   , KC_F6   , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , TT_FN2  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F1   , KC_F2   , KC_F3   , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , _______ ,      XXXXXXX      , _______ , _______ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [FUCTIONS2] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_LSFT , KC_LCTL , KC_LALT , KC_LGUI , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F10  , KC_F11  , KC_F12  , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , _______ ,      XXXXXXX      , _______ , _______ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [NAVIGATION] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      XXXXXXX , KC_LOCK , KC_LEAD , KC_CAPS , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_TAB  , KC_END  , KC_HOME , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      SFT_ESC , KC_LCTL , KC_LALT , KC_LGUI , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , MO_MED  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_INS  , KC_PGDN , KC_PGUP , KC_DEL  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , _______ ,      XXXXXXX      , _______ , MAI_ENT , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [MOUSE] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      XXXXXXX , KC_BTN2 , KC_BTN1 , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_WH_D , KC_WH_U , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_MS_L , KC_MS_U , KC_MS_D , KC_MS_R , KC_GRV  , XXXXXXX , XXXXXXX , XXXXXXX , KC_RGUI , KC_RALT , KC_RCTL , SFT_ENT ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_ACL0 , KC_ACL1 , KC_ACL2 , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , MAI_ESC , _______ ,      XXXXXXX      , _______ , _______ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [MEDIA] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , HYPR_A  , HYPR_V  , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_MUTE , KC_VOLD , KC_VOLU , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_MPLY , KC_MPRV , KC_MNXT , KC_MSTP ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , _______ ,      XXXXXXX      , _______ , _______ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [MAINTENANCE] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      XXXXXXX , RGB_TOG , RGB_MOD , CMB_TOG , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , EEP_RST , RESET   , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      RGB_VAI , RGB_HUI , RGB_SAI , MO_LAY  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , DEBUG   , BL_ON   , BL_OFF  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      RGB_VAD , RGB_HUD , RGB_SAD , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_SLEP , NK_ON   , NK_OFF  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , _______ ,      XXXXXXX      , _______ , _______ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [LAYERS] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , TO_MED  , TO_MAI  , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      DF_QWE  , DF_COL  , XXXXXXX , _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , TO_SYM  , TO_NUM  , TO_NAV  , TO_MOU  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , TO_FN1  , TO_FN2  , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , _______ ,      XXXXXXX      , _______ , _______ , XXXXXXX , XXXXXXX , XXXXXXX)
 // |_______________________________________________________________________________________________________________________|

};

// Custom keycodes

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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
    default:
      return true;
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
         rgb_matrix_set_color(3, RGB_PURPLE);
     }

     if (host_keyboard_led_state().caps_lock) {
         rgb_matrix_set_color(3, RGB_RED);
     }

     switch(get_highest_layer(layer_state|default_layer_state)) {
          case SYMBOLS:
               rgb_matrix_set_color(40, RGB_WHITE);
               break;
          case NUMBERS:
               rgb_matrix_set_color(42, RGB_WHITE);
               break;
          case MEDIA:
               rgb_matrix_set_color(27, RGB_WHITE);
               break;
          case FUCTIONS1:
               rgb_matrix_set_color(24, RGB_WHITE);
               break;
          case FUCTIONS2:
               rgb_matrix_set_color(27, RGB_WHITE);
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
               rgb_matrix_set_color(10, RGB_RED);
               break;
          case LAYERS:
               rgb_matrix_set_color(15, RGB_WHITE);
               break;
          default:
               break;
    }
}

// Tap dance for dot/comma/shift

td_state_t dance_state(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return TD_SINGLE_TAP;
        else
            return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        return TD_DOUBLE_TAP;
    }
    return TD_SINGLE_TAP;
}

static td_tap_t tap_state = {
    .state = TD_NONE
};

void dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_DOT); break;
        case TD_SINGLE_HOLD: register_code(KC_RSFT); break;
        case TD_DOUBLE_TAP: register_code(KC_COMM); break;
        case TD_NONE: break;
    }
}

void dance_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_DOT); break;
        case TD_SINGLE_HOLD: unregister_code(KC_RSFT); break;
        case TD_DOUBLE_TAP: unregister_code(KC_COMM); break;
        case TD_NONE: break;
    }
    tap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [SFT_DOT_COM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_finished, dance_reset)
};
