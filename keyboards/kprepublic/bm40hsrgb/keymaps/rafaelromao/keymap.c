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
  FUCTIONS,
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

// #define OS_LSFT OSM(MOD_LSFT)
// #define OS_LCTL OSM(MOD_LCTL)
// #define OS_LALT OSM(MOD_LALT)
// #define OS_LGUI OSM(MOD_LGUI)

// #define OS_RSFT OSM(MOD_RSFT)
// #define OS_RCTL OSM(MOD_RCTL)
// #define OS_RALT OSM(MOD_RALT)
// #define OS_RGUI OSM(MOD_RGUI)

#define NAV_SPC LT(NAVIGATION,KC_SPC)
#define SYM_SPC LT(SYMBOLS,KC_SPC)
#define NUM_SPC LT(NUMBERS,KC_SPC)
#define MOU_SPC LT(MOUSE,KC_SPC)

#define TD_DCQ TD(DOT_COM_QWE)
#define TD_DCC TD(DOT_COM_COL)

#define MAI_ESC LT(MAINTENANCE,KC_ESC)
#define MAI_ENT LT(MAINTENANCE,KC_ENT)
#define FUN_BSP LT(FUCTIONS,KC_BSPC)
#define FUN_TAB LT(FUCTIONS,KC_TAB)

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
#define TO_FN TO(FUCTIONS)
#define TG_FN TG(FUCTIONS)
#define TO_MED TO(MEDIA)

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

// Oneshot (from https://github.com/callum-oakley/qmk_firmware/blob/master/users/callum)

typedef enum {
    os_up_unqueued,
    os_up_queued,
    os_down_unused,
    os_down_used,
} oneshot_state;

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_LSFT = SAFE_RANGE,
    OS_LCTL,
    OS_LALT,
    OS_LGUI,
    OS_RSFT,
    OS_RCTL,
    OS_RALT,
    OS_RGUI
};

void update_oneshot(
    oneshot_state *state,
    uint16_t mod,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
);

oneshot_state os_sft_state = os_up_unqueued;
oneshot_state os_ctl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_gui_state = os_up_unqueued;

// Combos

const uint16_t PROGMEM qwe_ent_combo[] = {RGUIT_J, RALTT_K, RCTLT_L, COMBO_END};
const uint16_t PROGMEM qwe_esc_combo[] = {LCTLT_S, LALTT_D, LGUIT_F, COMBO_END};
const uint16_t PROGMEM qwe_tab_combo[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM col_ent_combo[] = {RGUIT_N, RALTT_E, RCTLT_I, COMBO_END};
const uint16_t PROGMEM col_esc_combo[] = {LCTLT_R, LALTT_S, LGUIT_T, COMBO_END};
const uint16_t PROGMEM col_tab_combo[] = {KC_L, KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM num_fun_combo[] = {RGUIT_4, RALTT_5, RCTLT_6, COMBO_END};
const uint16_t PROGMEM fun_tog_combo[] = {KC_F4, KC_F5, KC_F6, COMBO_END};
const uint16_t PROGMEM num_sym_combo[] = {KC_P1, KC_P2, KC_P3, COMBO_END};
const uint16_t PROGMEM rsy_sho_combo[] = {KC_DLR, KC_QUES, KC_HASH, COMBO_END};
const uint16_t PROGMEM lsy_sho_combo[] = {KC_LCBR, KC_RCBR, KC_UNDS, COMBO_END};
const uint16_t PROGMEM rnu_sho_combo[] = {KC_P7, KC_P8, KC_P9, COMBO_END};
const uint16_t PROGMEM lnu_sho_combo[] = {KC_CIRC, KC_TILD, KC_GRV , COMBO_END};
const uint16_t PROGMEM mou_nav_combo[] = {OS_RGUI, OS_RALT, OS_RCTL, COMBO_END};
const uint16_t PROGMEM nav_tog_combo[] = {KC_LEFT, KC_DOWN, KC_UP, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(qwe_ent_combo, KC_ENT),
  COMBO(qwe_esc_combo, KC_ESC),
  COMBO(qwe_tab_combo, KC_TAB),
  COMBO(col_ent_combo, KC_ENT),
  COMBO(col_esc_combo, KC_ESC),
  COMBO(col_tab_combo, KC_TAB),
  COMBO(num_fun_combo, TG_FN),
  COMBO(fun_tog_combo, TG_FN),
  COMBO(num_sym_combo, OS_SYM),
  COMBO(rsy_sho_combo, SH_OS),
  COMBO(lsy_sho_combo, SH_OS),
  COMBO(rnu_sho_combo, SH_OS),
  COMBO(lnu_sho_combo, SH_OS),
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
      XXXXXXX , KC_CIRC , KC_TILD , KC_GRV  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_P7   , KC_P8   , KC_P9   , TD_DCQ  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_SLSH , KC_ASTR , KC_MINS , KC_PLUS , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , RGUIT_4 , RALTT_5 , RCTLT_6 , TD_DCC  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , KC_C    , KC_QUOT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_P1   , KC_P2   , KC_P3   , KC_P0   ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , FUN_BSP ,      XXXXXXX      , _______ , _______ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [SYMBOLS] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      XXXXXXX , KC_LCBR , KC_RCBR , KC_UNDS , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_DLR  , KC_QUES , KC_HASH , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_EXLM , KC_LPRN , KC_RPRN , KC_EQL  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_AMPR , KC_DQUO , KC_AT   , KC_PIPE ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_CAPS , KC_LBRC , KC_RBRC , KC_BSLS , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_PERC , KC_LT   , KC_GT   , KC_COLN ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , _______ ,      XXXXXXX      , FUN_TAB , _______ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [FUCTIONS] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F7   , KC_F8   , KC_F9   , KC_F12  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_LSFT , KC_LCTL , KC_LALT , KC_LGUI , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F4   , KC_F5   , KC_F6   , KC_F11  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_F1   , KC_F2   , KC_F3   , KC_F10  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , _______ ,      XXXXXXX      , _______ , _______ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [NAVIGATION] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_ESC  , KC_LOCK , KC_LEAD , KC_TAB  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_TAB  , KC_END  , KC_HOME , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      OS_LSFT , OS_LCTL , OS_LALT , OS_LGUI , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , MO_MED  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_INS  , KC_PGDN , KC_PGUP , KC_DEL  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , _______ ,      XXXXXXX      , _______ , MAI_ENT , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [MOUSE] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      XXXXXXX , KC_BTN2 , KC_BTN1 , KC_TAB  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_TAB  , KC_WH_D , KC_WH_U , KC_ENT  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_MS_L , KC_MS_U , KC_MS_D , KC_MS_R , KC_GRV  , XXXXXXX , XXXXXXX , XXXXXXX , OS_RGUI , OS_RALT , OS_RCTL , OS_RSFT ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , MO_MED  , KC_ACL0 , KC_ACL1 , KC_ACL2 ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , MAI_ESC , _______ ,      XXXXXXX      , _______ , _______ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [MEDIA] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      KC_MSTP , KC_MNXT , KC_MPRV , KC_MPLY , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_MPLY , KC_MPRV , KC_MNXT , KC_MSTP ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_MUTE , KC_VOLU , KC_VOLD , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_VOLD , KC_VOLU , KC_MUTE ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , HYPR_V  , HYPR_A  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , HYPR_A  , HYPR_V  , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , _______ ,      XXXXXXX      , _______ , _______ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [MAINTENANCE] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      XXXXXXX , RGB_TOG , RGB_MOD , CMB_TOG , EEP_RST , XXXXXXX , XXXXXXX , RESET   , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      RGB_VAI , RGB_HUI , RGB_SAI , MO_LAY  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , MO_LAY  , DEBUG   , BL_ON   , BL_OFF  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      RGB_VAD , RGB_HUD , RGB_SAD , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_SLEP , NK_ON   , NK_OFF  ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , _______ ,      XXXXXXX      , _______ , _______ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [LAYERS] = LAYOUT_planck_mit(
 // |_______________________________________________________________________________________________________________________|
      XXXXXXX , XXXXXXX , DF_QWE  , TO_MED  , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , TO_MAI  , DF_COL  , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , TO_FN   , XXXXXXX , XXXXXXX , XXXXXXX , _______ , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , TO_NAV  , TO_SYM  , XXXXXXX , XXXXXXX , TO_NUM  , TO_MOU  , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _______ , _______ ,      XXXXXXX      , _______ , _______ , XXXXXXX , XXXXXXX , XXXXXXX)
 // |_______________________________________________________________________________________________________________________|

};

// Custom keycodes

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // Persistent default layers

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

    // One shot

    update_oneshot(
        &os_sft_state, KC_LSFT, OS_LSFT,
        keycode, record
    );
    update_oneshot(
        &os_ctl_state, KC_LCTL, OS_LCTL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_LALT,
        keycode, record
    );
    update_oneshot(
        &os_gui_state, KC_LGUI, OS_LGUI,
        keycode, record
    );
    update_oneshot(
        &os_sft_state, KC_RSFT, OS_RSFT,
        keycode, record
    );
    update_oneshot(
        &os_ctl_state, KC_RCTL, OS_RCTL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_RALT, OS_RALT,
        keycode, record
    );
    update_oneshot(
        &os_gui_state, KC_RGUI, OS_RGUI,
        keycode, record
    );
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
        rgb_matrix_set_color(3, RGB_RED);
    }

    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(24, RGB_RED);
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
            rgb_matrix_set_color(32, RGB_WHITE);
            break;
        case FUCTIONS:
            rgb_matrix_set_color(40, RGB_WHITE);
            rgb_matrix_set_color(42, RGB_WHITE);
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
            rgb_matrix_set_color(7, RGB_RED);
            break;
        case LAYERS:
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
    bool isQwerty = biton32(default_layer_state) == QWERTY;
    if (isQwerty) {
        switch (tap_state.state) {
            case TD_SINGLE_TAP: register_code(KC_DOT); break;
            case TD_DOUBLE_TAP: register_code(KC_COMM); break;
            default: break;
        }
    } else {
        switch (tap_state.state) {
            case TD_SINGLE_TAP:
            case TD_DOUBLE_HOLD:
                register_code(KC_BSPC); break;
            default: break;
        }
    }
}

void td_dcq_reset(qk_tap_dance_state_t *state, void *user_data) {
    bool isQwerty = biton32(default_layer_state) == QWERTY;
    if (isQwerty) {
        switch (tap_state.state) {
            case TD_SINGLE_TAP: unregister_code(KC_DOT); break;
            case TD_DOUBLE_TAP: unregister_code(KC_COMM); break;
            default: break;
        }
    } else {
        switch (tap_state.state) {
            case TD_SINGLE_TAP:
            case TD_DOUBLE_HOLD:
                unregister_code(KC_BSPC); break;
            default: break;
        }
    }
    tap_state.state = TD_NONE;
}

void td_dcc_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    bool isColemak = biton32(default_layer_state) == COLEMAK;
    if (isColemak) {
        switch (tap_state.state) {
            case TD_SINGLE_TAP: register_code(KC_DOT); break;
            case TD_DOUBLE_TAP: register_code(KC_COMM); break;
            case TD_SINGLE_HOLD: register_code(KC_RSFT); break;
            default: break;
        }
    } else {
        switch (tap_state.state) {
            case TD_SINGLE_TAP:
            case TD_DOUBLE_HOLD:
                register_code(KC_BSPC); break;
            case TD_SINGLE_HOLD: register_code(KC_RSFT); break;
            default: break;
        }
    }
}

void td_dcc_reset(qk_tap_dance_state_t *state, void *user_data) {
    bool isColemak = biton32(default_layer_state) == COLEMAK;
    if (isColemak) {
        switch (tap_state.state) {
            case TD_SINGLE_TAP: unregister_code(KC_DOT); break;
            case TD_DOUBLE_TAP: unregister_code(KC_COMM); break;
            case TD_SINGLE_HOLD: unregister_code(KC_RSFT); break;
            default: break;
        }
    } else {
        switch (tap_state.state) {
            case TD_SINGLE_TAP:
            case TD_DOUBLE_HOLD:
                unregister_code(KC_BSPC); break;
            case TD_SINGLE_HOLD: unregister_code(KC_RSFT); break;
            default: break;
        }
    }
    tap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [DOT_COM_QWE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_dcq_finished, td_dcq_reset),
    [DOT_COM_COL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_dcc_finished, td_dcc_reset)
};

// Oneshot

bool is_oneshot_cancel_key(uint16_t keycode) {
    return false;
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    return true;
}

void update_oneshot(
    oneshot_state *state,
    uint16_t mod,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            // Trigger keydown
            if (*state == os_up_unqueued) {
                register_code(mod);
            }
            *state = os_down_unused;
        } else {
            // Trigger keyup
            switch (*state) {
            case os_down_unused:
                // If we didn't use the mod while trigger was held, queue it.
                *state = os_up_queued;
                break;
            case os_down_used:
                // If we did use the mod while trigger was held, unregister it.
                *state = os_up_unqueued;
                unregister_code(mod);
                break;
            default:
                break;
            }
        }
    } else {
        if (record->event.pressed) {
            if (is_oneshot_cancel_key(keycode) && *state != os_up_unqueued) {
                // Cancel oneshot on designated cancel keydown.
                *state = os_up_unqueued;
                unregister_code(mod);
            }
        } else {
            if (!is_oneshot_ignored_key(keycode)) {
                // On non-ignored keyup, consider the oneshot used.
                switch (*state) {
                case os_down_unused:
                    *state = os_down_used;
                    break;
                case os_up_queued:
                    *state = os_up_unqueued;
                    unregister_code(mod);
                    break;
                default:
                    break;
                }
            }
        }
    }
}
