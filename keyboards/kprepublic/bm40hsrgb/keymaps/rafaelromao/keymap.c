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
#include "rafaelromao.h"

#define LAYOUT_wrapper(...) LAYOUT_planck_mit(__VA_ARGS__)

// Keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

     [_QWERTY] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________QWERTY_L1___________________ , XXXXXXX , XXXXXXX , ___________________QWERTY_R1___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________QWERTY_L2___________________ , XXXXXXX , XXXXXXX , ___________________QWERTY_R2___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________QWERTY_L3___________________ , XXXXXXX , XXXXXXX , ___________________QWERTY_R3___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________QWERTY_L4___________________ ,      XXXXXXX      , ___________________QWERTY_R4___________________),
 // |_______________________________________________________________________________________________________________________|

     [_COLEMAK] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________COLEMAK_L1__________________ , XXXXXXX , XXXXXXX , ___________________COLEMAK_R1__________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________COLEMAK_L2__________________ , XXXXXXX , XXXXXXX , ___________________COLEMAK_R2__________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________COLEMAK_L3__________________ , XXXXXXX , XXXXXXX , ___________________COLEMAK_R3__________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________COLEMAK_L4__________________ ,      XXXXXXX      , ___________________COLEMAK_R4__________________),
 // |_______________________________________________________________________________________________________________________|

     [_LOWER] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________LOWER_L1____________________ , XXXXXXX , XXXXXXX , ___________________LOWER_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________LOWER_L2____________________ , XXXXXXX , XXXXXXX , ___________________LOWER_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________LOWER_L3____________________ , XXXXXXX , XXXXXXX , ___________________LOWER_R3____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________LOWER_L4____________________ ,      XXXXXXX      , ___________________LOWER_R4____________________),
 // |_______________________________________________________________________________________________________________________|

     [_RAISE] = LAYOUT_wrapper(
 // |_______________________________ ________________________________________________________________________________________|
      ___________________RAISE_L1____________________ , XXXXXXX , XXXXXXX , ___________________RAISE_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________RAISE_L2____________________ , XXXXXXX , XXXXXXX , ___________________RAISE_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________RAISE_L3____________________ , XXXXXXX , XXXXXXX , ___________________RAISE_R3____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________RAISE_L4____________________ ,      XXXXXXX      , ___________________RAISE_R4____________________),
 // |_______________________________________________________________________________________________________________________|

     [_FUNCTIONS] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________FUNCTIONS_L1________________ , XXXXXXX , XXXXXXX , ___________________FUNCTIONS_R1________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________FUNCTIONS_L2________________ , XXXXXXX , XXXXXXX , ___________________FUNCTIONS_R2________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________FUNCTIONS_L3________________ , XXXXXXX , XXXXXXX , ___________________FUNCTIONS_R3________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________FUNCTIONS_L4________________ ,      XXXXXXX      , ___________________FUNCTIONS_R4________________),
 // |_______________________________________________________________________________________________________________________|

     [_NAVIGATION] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________NAVIGATION_L1_______________ , XXXXXXX , XXXXXXX , ___________________NAVIGATION_R1_______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________NAVIGATION_L2_______________ , XXXXXXX , XXXXXXX , ___________________NAVIGATION_R2_______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________NAVIGATION_L3_______________ , XXXXXXX , XXXXXXX , ___________________NAVIGATION_R3_______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________NAVIGATION_L4_______________ ,      XXXXXXX      , ___________________NAVIGATION_R4_______________),
 // |_______________________________________________________________________________________________________________________|

     [_MOUSE] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________MOUSE_L1____________________ , XXXXXXX , XXXXXXX , ___________________MOUSE_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MOUSE_L2____________________ , XXXXXXX , XXXXXXX , ___________________MOUSE_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MOUSE_L3____________________ , XXXXXXX , XXXXXXX , ___________________MOUSE_R3____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MOUSE_L4____________________ ,      XXXXXXX      , ___________________MOUSE_R4____________________),
 // |_______________________________________________________________________________________________________________________|

     [_MEDIA] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________MEDIA_L1____________________ , XXXXXXX , XXXXXXX , ___________________MEDIA_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MEDIA_L2____________________ , XXXXXXX , XXXXXXX , ___________________MEDIA_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MEDIA_L3____________________ , XXXXXXX , XXXXXXX , ___________________MEDIA_R3____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MEDIA_L4____________________ ,      XXXXXXX      , ___________________MEDIA_R4____________________),
 // |_______________________________________________________________________________________________________________________|

     [_MAINTENANCE] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________MAINTENANCE_L1______________ , XXXXXXX , XXXXXXX , ___________________MAINTENANCE_R1______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MAINTENANCE_L2______________ , XXXXXXX , XXXXXXX , ___________________MAINTENANCE_R2______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MAINTENANCE_L3______________ , XXXXXXX , XXXXXXX , ___________________MAINTENANCE_R3______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MAINTENANCE_L4______________ ,      XXXXXXX      , ___________________MAINTENANCE_R4______________),
 // |_______________________________________________________________________________________________________________________|

     [_LAYERS] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________LAYERS_L1___________________ , XXXXXXX , XXXXXXX , ___________________LAYERS_R1___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________LAYERS_L2___________________ , XXXXXXX , XXXXXXX , ___________________LAYERS_R2___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________LAYERS_L3___________________ , XXXXXXX , XXXXXXX , ___________________LAYERS_R3___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________LAYERS_L4___________________ ,      XXXXXXX      , ___________________LAYERS_R4___________________)
 // |_______________________________________________________________________________________________________________________|

};

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
