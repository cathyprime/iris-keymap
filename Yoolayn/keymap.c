// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_QUOT, SC_LSPO, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, SC_RSPC, KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_BSPC, TO(_ADJUST), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS, KC_LALT, MO(_LOWER), KC_SPC, KC_ENT, KC_RALT, KC_LGUI),

	[_LOWER] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO, KC_LSFT, KC_LBRC, KC_RBRC, KC_EQL, KC_MINS, KC_QUOT, KC_QUOT, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_RSFT, KC_LCTL, KC_NO, KC_COMM, KC_DOT, KC_BSLS, KC_SLSH, KC_NO, KC_TRNS, KC_SLSH, KC_BSLS, KC_COMM, KC_DOT, KC_NO, KC_CAPS, KC_LALT, KC_TRNS, KC_SPC, KC_ESC, MO(_RAISE), KC_LGUI),

	[_RAISE] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_END, KC_NO, KC_NO, KC_HOME, KC_NO, KC_NO, KC_NO, KC_HOME, KC_NO, KC_NO, KC_NO, LCTL(KC_RGHT), KC_END, KC_NO, KC_NO, LCTL(KC_C), KC_PGUP, KC_NO, KC_NO, LCTL(KC_V), KC_PPLS, KC_NO, KC_HOME, KC_NO, KC_PGDN, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSPC, KC_NO, KC_NO, LCTL(KC_LEFT), KC_NO, KC_TRNS, KC_DEL, KC_BSPC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO),

	[_ADJUST] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, RGB_TOG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO, KC_NO, KC_PMNS, KC_PAST, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_NO, KC_MPLY, KC_NO, KC_NO, KC_NO, KC_NO, TO(_QWERTY), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};

bool rgb_matrix_indicators_user(void) {
    uint8_t layer = get_highest_layer(layer_state|default_layer_state);
    switch (layer) {
        case 0:
            rgb_matrix_set_color_all(120, 0, 127);
            break;
        case 1:
            rgb_matrix_set_color_all(127, 0, 0);
            break;
        case 2:
            rgb_matrix_set_color_all(0, 0, 127);
            break;
        case 3:
            rgb_matrix_set_color_all(0, 127, 127);
            break;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
