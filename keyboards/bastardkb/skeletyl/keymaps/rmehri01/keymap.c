/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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

#include "swapper.h"

enum layers {
    BASE,
    SYM,
    NAV,
    FUN,
    GAMING,
};

enum keycodes {
    SW_WIN = SAFE_RANGE, // Switch to next window         (cmd-tab)

    GAMING_ON,
    GAMING_OFF,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
               KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,    KC_L,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                         KC_D,    KC_H,    KC_T,    KC_N,    KC_S,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
               KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LSFT, KC_LCTL, MO(NAV),    MO(SYM),  KC_SPC, KC_RSFT
                                      //`--------------------------'  `--------------------------'
  ),

  [NAV] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                  KC_7,    KC_5,    KC_3,    KC_1,    KC_9,                         KC_8,    KC_0,    KC_2,    KC_4,    KC_6,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         OSM(MOD_LCTL),OSM(MOD_LALT),OSM(MOD_LGUI),OSM(MOD_LSFT),XXXXXXX,        XXXXXXX,  SW_WIN,   KC_UP,  KC_ENT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    MO(FUN),  KC_TAB, KC_BSPC
                                      //`--------------------------'  `--------------------------'
  ),

  [SYM] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
               KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
               KC_SLSH, KC_LPRN, KC_RPRN,  KC_EQL, KC_LBRC,                      KC_RBRC,OSM(MOD_RSFT),OSM(MOD_RGUI),OSM(MOD_RALT),OSM(MOD_RCTL),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
               KC_QUES, KC_LCBR, KC_RCBR, KC_PLUS, KC_TILD,                      KC_BSLS, XXXXXXX, KC_PIPE, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_GRV, KC_MINS, MO(FUN),    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [FUN] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                KC_F12,   KC_F7,   KC_F8,   KC_F9, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                KC_F11,   KC_F4,   KC_F5,   KC_F6, XXXXXXX,              KC_PRINT_SCREEN, KC_VOLU, KC_BRMU, XXXXXXX,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                KC_F10,   KC_F1,   KC_F2,   KC_F3, XXXXXXX,                      KC_CAPS, KC_VOLD, KC_BRMD, XXXXXXX,GAMING_ON,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
  [GAMING] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                  KC_Q,    KC_W,    KC_E,    KC_R,    KC_Y,                         KC_Y,    KC_U,    KC_I,    KC_O, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                KC_GRV,  KC_SPC,  KC_TAB,LALT(KC_R),  KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT,GAMING_OFF,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             KC_1,    KC_2,    KC_3,  LGUI(KC_TAB),KC_SPC,KC_RSFT
                                      //`--------------------------'  `--------------------------'
  ),
};
// clang-format on

const uint16_t PROGMEM ht_combo[]   = {KC_H, KC_T, COMBO_END};
combo_t                key_combos[] = {
    COMBO(ht_combo, KC_ESC),
};

bool sw_win_active  = false;
bool sw_lang_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(&sw_win_active, KC_LGUI, KC_TAB, SW_WIN, keycode, record);

    switch (keycode) {
        case GAMING_ON:
            if (record->event.pressed) {
                layer_on(GAMING);
            }
            return false;
        case GAMING_OFF:
            if (record->event.pressed) {
                layer_off(GAMING);
            }
            return false;
    }

    return true;
}
