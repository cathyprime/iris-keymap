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

        [_QWERTY] = LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_QUOT, SC_LSPO, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, SC_RSPC, KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_BSPC, TO(3), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS, KC_LALT, MO(1), KC_SPC, KC_ENT, KC_RALT, KC_LGUI),

        [_LOWER] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO, KC_LSFT, KC_LBRC, KC_RBRC, KC_EQL, KC_MINS, KC_QUOT, KC_QUOT, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_RSFT, KC_LCTL, KC_NO, KC_COMM, KC_DOT, KC_BSLS, KC_SLSH, KC_NO, KC_TRNS, KC_SLSH, KC_BSLS, KC_COMM, KC_DOT, KC_NO, KC_CAPS, KC_LALT, KC_TRNS, KC_SPC, KC_ESC, MO(2), KC_LGUI),

        [_RAISE] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_END, KC_NO, KC_NO, KC_HOME, KC_NO, KC_NO, KC_NO, KC_HOME, KC_NO, KC_NO, KC_NO, LCTL(KC_RGHT), KC_END, KC_NO, KC_NO, LCTL(KC_C), KC_PGUP, KC_NO, KC_NO, LCTL(KC_V), KC_PPLS, KC_NO, KC_HOME, KC_NO, KC_PGDN, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSPC, KC_NO, KC_NO, LCTL(KC_LEFT), KC_NO, KC_TRNS, KC_DEL, KC_BSPC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO),

        [_ADJUST] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, RGB_TOG, RGB_RMOD, RGB_MOD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO, KC_NO, KC_PMNS, KC_PAST, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_NO, KC_MPLY, KC_NO, KC_NO, KC_NO, KC_NO, TO(0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};

/**
* Here's an LED number guide:
* FRONT
* Left Hand                    Right Hand
* |00|01|02|03|04|05|          |39|38|37|36|35|34|
* |11|10|09|08|07|06|          |40|41|42|43|44|45|
* |12|13|14|15|16|17|          |51|50|49|48|47|46|
* |23|22|21|20|19|18|27|    |61|52|53|54|55|56|57|
*             |24|25|26|    |60|59|58|
* REVERSE
* Right Hand                   Left Hand
* |65|--|--|66|--|67|          |33|--|32|--|--|31|
* |--|--|--|--|--|--|          |--|--|--|--|--|--|
* |--|--|--|--|--|--|          |--|--|--|--|--|--|
* |64|--|--|63|--|--|--|    |--|--|--|29|--|--|30|
*             |--|62|--|    |--|28|--|
*/

typedef struct {
        uint8_t r;
        uint8_t g;
        uint8_t b;
} LayerColor;

LayerColor layer0_color = {24, 0, 24};
LayerColor layer1_color = {24, 0, 0};
LayerColor layer2_color = {0, 0, 24};
LayerColor layer3_color = {0, 24, 24};
LayerColor capsLock_color = {0, 24, 0};

void capsLock(uint8_t r, uint8_t g, uint8_t b) {
        uint8_t indexes[] = {58, 59, 60, 61, 24, 25, 26, 27};
        size_t numIndexes = sizeof(indexes) / sizeof(indexes[0]);

        if (host_keyboard_led_state().caps_lock) {
                for (size_t i = 0; i < numIndexes; i++) {
                        rgb_matrix_set_color(indexes[i], capsLock_color.r, capsLock_color.g, capsLock_color.b);
                }
        } else {
                for (size_t i = 0; i < numIndexes; i++) {
                        rgb_matrix_set_color(indexes[i], r, g, b);
                }
        }
}

layer_state_t layer_state_set_user(layer_state_t state) {
        switch (get_highest_layer(state)) {
                case 0:
                        rgb_matrix_sethsv_noeeprom(210, 255, 200);
                        break;
                case 1:
                        rgb_matrix_sethsv_noeeprom(255, 255, 255);
                        break;
                case 2:
                        rgb_matrix_sethsv_noeeprom(170, 255, 255);
                        break;
                case 3:
                        rgb_matrix_sethsv_noeeprom(120, 175, 255);
                        break;
        }
        return state;
}

void keyboard_post_init_user(void) {
        rgb_matrix_enable_noeeprom();
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
        rgb_matrix_sethsv_noeeprom(210, 255, 200);
}

/* bool rgb_matrix_indicators_user(void) { */
/*         rgb_matrix_get_mode(); */
/*         LayerColor currentColor; */
/**/
/*         switch(get_highest_layer(layer_state|default_layer_state)) { */
/*                 case 0: */
/*                         currentColor = layer0_color; */
/*                         break; */
/*                 case 1: */
/*                         currentColor = layer1_color; */
/*                         break; */
/*                 case 2: */
/*                         currentColor = layer2_color; */
/*                         break; */
/*                 case 3: */
/*                         currentColor = layer3_color; */
/*                         break; */
/*         } */
/**/
/*         rgb_matrix_set_color_all(currentColor.r, currentColor.g, currentColor.b); */
/*         capsLock(currentColor.r, currentColor.g, currentColor.b); */
/**/
/*         return true; */
/* } */

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
