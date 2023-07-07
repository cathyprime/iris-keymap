#include QMK_KEYBOARD_H
#include "transactions.h"

#define _QWERTY 0
#define _SIGNS 1
#define _VIM 2
#define _MUSIC 3
#define _GAMING 4
#define _GAMING2 5
#define _FPS 6

enum custom_keycodes {
        QWERTY = SAFE_RANGE,
        SIGNS,
        VIM,
        MODL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

        [_QWERTY] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_QUOT,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    SC_LSPO,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN, SC_RSPC,
// ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_BSPC, QK_LEAD,   KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
// └────────┴────────┴────────┴────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                        KC_LALT,   MODL,   KC_SPC,   KC_ENT,OSM(MOD_RALT),KC_LGUI
//                                     └────────┴────────┴────────┘└────────┴────────┴────────┘
        ),

        [_SIGNS] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LSFT, KC_LBRC, KC_RBRC,  KC_EQL, KC_MINS, KC_QUOT,                    KC_QUOT, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_RSFT,
// ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LCTL,  KC_NO,  KC_COMM,  KC_DOT, KC_BSLS, KC_SLSH,  KC_NO,   QK_LEAD, KC_SLSH, KC_BSLS, KC_COMM,  KC_DOT,  KC_NO,  CW_TOGG,
// └────────┴────────┴────────┴────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                         KC_LALT, KC_TRNS, KC_SPC,   KC_ESC,   MO(2), KC_LGUI
//                                     └────────┴────────┴────────┘└────────┴────────┴────────┘
         ),

        [_VIM] = LAYOUT(
// ┌────────┬────────┬──────────────┬────────┬────────┬─────────────┐                  ┌──────────┬────────┬────────┬────────┬──────────┬────────┐
     KC_NO,   KC_NO,      KC_NO,      KC_END,  KC_NO,      KC_NO,                        KC_HOME,   KC_NO,   KC_NO,   KC_NO,   KC_HOME,   KC_NO,
// ├────────┼────────┼──────────────┼────────┼────────┼─────────────┤                  ├──────────┼────────┼────────┼────────┼──────────┼────────┤
     KC_NO,   KC_NO,  LCTL(KC_RGHT),  KC_END,  KC_NO,      KC_NO,                      LCTL(KC_C), KC_PGUP,  TO(0),   KC_NO, LCTL(KC_V), KC_PPLS,
// ├────────┼────────┼──────────────┼────────┼────────┼─────────────┤                  ├──────────┼────────┼────────┼────────┼──────────┼────────┤
    KC_LSFT, KC_HOME,     KC_NO,     KC_PGDN,  KC_NO,      KC_NO,                        KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT,  KC_NO,   KC_RSFT,
// ├────────┼────────┼──────────────┼────────┼────────┼─────────────┼────────┐┌────────┼──────────┼────────┼────────┼────────┼──────────┼────────┤
     KC_NO,   KC_NO,     KC_BSPC,     KC_NO,  KC_LSFT, LCTL(KC_LEFT), KC_NO,   QK_LEAD,   KC_DEL,  KC_BSPC,  KC_NO,   KC_NO,    KC_NO,    KC_NO,
// └────────┴────────┴──────────────┴────────┼────────┼─────────────┼────────┤├────────┼──────────┼────────┼────────┴────────┴──────────┴────────┘
                                               KC_NO,     KC_TRNS,    KC_NO,    KC_NO,   KC_TRNS,   KC_NO
//                                           └────────┴─────────────┴────────┘└────────┴──────────┴────────┘
        ),

        [_MUSIC] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    RGB_TOG,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,  KC_NO,                      KC_NO,  KC_PMNS, KC_PAST,  KC_NO,   KC_NO,   KC_NO,
// ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    KC_MUTE,  KC_NO,  KC_MPLY,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_LEAD,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
// └────────┴────────┴────────┴────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                         KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO
//                                     └────────┴────────┴────────┘└────────┴────────┴────────┘
         ),
        [_GAMING] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_GRV,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_QUOT,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LSFT,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN, SC_RSPC,
// ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LALT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   OSL(5),  QK_LEAD,   KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
// └────────┴────────┴────────┴────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                        KC_LCTL,  KC_SPC,  KC_TAB,   KC_ENT, KC_BSPC, KC_LGUI
//                                     └────────┴────────┴────────┘└────────┴────────┴────────┘
        ),
        [_GAMING2] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
// ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   TO(4),    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
// └────────┴────────┴────────┴────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                         TO(4),   TO(4),   TO(4),    TO(4),   TO(4),   TO(4)
//                                     └────────┴────────┴────────┘└────────┴────────┴────────┘
        ),
        [_FPS] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_GRV,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,   KC_T,    KC_Q,    KC_W,    KC_E,    KC_R,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_QUOT,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LSFT,   KC_G,    KC_A,    KC_S,    KC_D,    KC_F,                       KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN, SC_RSPC,
// ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    KC_LALT,   KC_B,    KC_Z,    KC_X,    KC_C,    KC_V,   OSL(5),  QK_LEAD,   KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
// └────────┴────────┴────────┴────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                         KC_TAB, KC_LCTL,  KC_SPC,   KC_ENT, KC_BSPC, KC_LGUI
//                                     └────────┴────────┴────────┘└────────┴────────┴────────┘
        )
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

// layer lighting
bool capsWordStatus = false;

void updateStatus(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
        const uint8_t* in_data_ptr = (const uint8_t*)in_data;
        capsWordStatus = *in_data_ptr;
}

void capsLock(void) {
        uint8_t indexes[] = {58, 59, 60, 61, 24, 25, 26, 27};
        size_t numIndexes = sizeof(indexes) / sizeof(indexes[0]);

        if (host_keyboard_led_state().caps_lock) {
                for (size_t i = 0; i < numIndexes; i++) {
                        rgb_matrix_set_color(indexes[i], 0, 24, 0);
                }
        } else if (is_caps_word_on() | capsWordStatus) {
                for (size_t i = 0; i < numIndexes; i++) {
                        rgb_matrix_set_color(indexes[i], 24, 21, 0);
                }
        }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
        capsLock();
        return true;
}

void caps_word_set_user(bool active) {
        transaction_rpc_send(CAPS_WORD_SYNC, sizeof(active), &active);
}

layer_state_t layer_state_set_user(layer_state_t state) {
        switch (get_highest_layer(state)) {
                case 0:
                        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
                        rgb_matrix_sethsv_noeeprom(210, 255, 200);
                        break;
                case 1:
                        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
                        rgb_matrix_sethsv_noeeprom(255, 255, 255);
                        break;
                case 2:
                        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
                        rgb_matrix_sethsv_noeeprom(170, 255, 255);
                        break;
                case 3:
                        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
                        rgb_matrix_sethsv_noeeprom(120, 175, 255);
                        break;
                case 4:
                        rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
                        break;
                case 6:
                        rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
                        break;
        }
        return state;
}

// leader
void leader_start_user(void) {
        layer_move(0);
}

void leader_end_user(void) {
        if (leader_sequence_one_key(KC_V)) {
                layer_move(_VIM);
        } else if (leader_sequence_one_key(KC_M)) {
                layer_move(_MUSIC);
        } else if (leader_sequence_one_key(KC_G)) {
                layer_move(_GAMING);
        } else if (leader_sequence_one_key(KC_Q)) {
                layer_move(_QWERTY);
        } else if (leader_sequence_three_keys(KC_F, KC_P, KC_S)) {
                layer_move(_FPS);
        }
}

void keyboard_post_init_user(void) {
        rgb_matrix_enable_noeeprom();
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
        rgb_matrix_sethsv_noeeprom(210, 255, 200);
        rgb_matrix_set_speed(31);
        transaction_register_rpc(CAPS_WORD_SYNC, updateStatus);
}

// combo
// definitions

enum combo_events {
        GAMING_ESC,
        FPS_ESC,
        GAMING_X,
        GAMING_SUPER,
        ALL_CAPSLOCK,
};

const uint16_t PROGMEM gaming_esc[] = {KC_GRV, KC_Q, COMBO_END};
const uint16_t PROGMEM fps_esc[] = {KC_GRV, KC_T, COMBO_END};
const uint16_t PROGMEM gaming_x[] = {KC_Z, KC_C, COMBO_END};
const uint16_t PROGMEM gaming_super[] = {KC_LALT, KC_SPC, COMBO_END};
const uint16_t PROGMEM all_capslock[] = {KC_LSFT, CW_TOGG, COMBO_END};

combo_t key_combos[] = {
        [GAMING_ESC] = COMBO_ACTION(gaming_esc),
        [FPS_ESC] = COMBO_ACTION(fps_esc),
        [GAMING_X] = COMBO_ACTION(gaming_x),
        [GAMING_SUPER] = COMBO_ACTION(gaming_super),
        [ALL_CAPSLOCK] = COMBO_ACTION(all_capslock),
};

//results
void process_combo_event(uint16_t combo_index, bool pressed) {
        switch (combo_index) {
                case GAMING_ESC:
                        if(pressed) {
                                tap_code16(KC_ESC);
                        }
                        break;
                case FPS_ESC:
                        if(pressed) {
                                tap_code16(KC_ESC);
                        }
                        break;
                case GAMING_X:
                        if (pressed) {
                                tap_code16(KC_X);
                        }
                        break;
                case GAMING_SUPER:
                        if (pressed) {
                                tap_code16(KC_LGUI);
                                tap_code16(KC_LGUI);
                        }
                        break;
                case ALL_CAPSLOCK:
                        if (pressed) {
                                tap_code16(KC_CAPS);
                        }
                        break;
        }
}

//restrictions
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
        switch (combo_index) {
                case GAMING_ESC:
                        return layer_state_is(4) || layer_state_is(6);
                        break;
                case GAMING_X:
                        return layer_state_is(4) || layer_state_is(6);
                        break;
                case GAMING_SUPER:
                        return layer_state_is(4) || layer_state_is(6);
                        break;
        }
        return true;
}

void modl(void) {
        if (get_mods() & MOD_BIT(KC_RALT)) {
                layer_on(2);
        } else {
                layer_on(1);
        }
}

// auto generated by json2c i think? and then edited by me
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
        switch (keycode) {
                case 0:
                        if (record->event.pressed) {
                                set_single_persistent_default_layer(_QWERTY);
                        }
                        return false;
                        break;
                case 1:
                        if (record->event.pressed) {
                                layer_on(_SIGNS);
                                update_tri_layer(_SIGNS, _VIM, _MUSIC);
                        } else {
                                layer_off(_SIGNS);
                                update_tri_layer(_SIGNS, _VIM, _MUSIC);
                        }
                        return false;
                        break;
                case 2:
                        if (record->event.pressed) {
                                layer_on(_VIM);
                                update_tri_layer(_SIGNS, _VIM, _MUSIC);
                        } else {
                                layer_off(_VIM);
                                update_tri_layer(_SIGNS, _VIM, _MUSIC);
                        }
                        return false;
                        break;
                case 3:
                        if (record->event.pressed) {
                                layer_on(_MUSIC);
                        } else {
                                layer_off(_MUSIC);
                        }
                        return false;
                        break;
                case MODL:
                        if (record->event.pressed) {
                                layer_on(1);
                                if (get_mods() & MOD_BIT(KC_RALT)) {
                                        layer_on(2);
                                }
                                return false;
                        } else {
                                layer_off(1);
                        }
                        break;
                case OSM(MOD_RALT):
                        if (!record->event.pressed & layer_state_is(2)) {
                                layer_off(2);
                        }
                        break;
        }
        return true;
}
