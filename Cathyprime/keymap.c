#include QMK_KEYBOARD_H
#include "transactions.h"

#define _QWERTY 0
#define _COLEMAK 1
#define _SIGNS 2
#define _GAMING 3
#define _GAMOD 4
#define _LEADER 5

// qwerty homerow
#define QHRA LGUI_T(KC_A)
#define QHRS LSFT_T(KC_S)
#define QHRD LALT_T(KC_D)
#define QHRF LCTL_T(KC_F)

#define QHRJ    LGUI_T(KC_J)
#define QHRK    LCTL_T(KC_K)
#define QHRL    RSFT_T(KC_L)
#define QHRSCLN LALT_T(KC_SCLN)

// colemak homerow
#define CHRA LGUI_T(KC_A)
#define CHRR LSFT_T(KC_R)
#define CHRS LALT_T(KC_S)
#define CHRT LCTL_T(KC_T)

#define CHRN LGUI_T(KC_N)
#define CHRE RCTL_T(KC_E)
#define CHRO RSFT_T(KC_O)
#define CHRI LALT_T(KC_I)

#define TAB_SIG LT(_SIGNS, KC_TAB)

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    SIGNS,
    VIM,
    MODL
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  TG(_GAMING),
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
        CW_TOGG,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_QUOT,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSFT,   QHRA,    QHRS,    QHRD,    QHRF,    KC_G,                       KC_H,    QHRJ,    QHRK,    QHRL,  QHRSCLN, KC_RALT,
    // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE,  QK_LEAD,  KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
    // └────────┴────────┴────────┴────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                             KC_ESC, TAB_SIG,  KC_SPC,   KC_ENT, KC_BSPC,  KC_DEL
    //                                     └────────┴────────┴────────┘└────────┴────────┴────────┘
    ),
    [_COLEMAK] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  TG(_GAMING),
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
        CW_TOGG,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                       KC_J,    KC_L,    KC_U,    KC_Y,  KC_SCLN, KC_QUOT,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSFT,   CHRA,    CHRR,    CHRS,    CHRT,    KC_G,                       KC_M,    CHRN,    CHRE,    CHRI,    CHRO,  KC_RALT,
    // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,  KC_MUTE,  QK_LEAD,   KC_K,    KC_H,  KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
    // └────────┴────────┴────────┴────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                             KC_ESC,  TAB_SIG, KC_SPC,   KC_ENT, KC_BSPC,  KC_DEL
    //                                     └────────┴────────┴────────┘└────────┴────────┴────────┘
    ),
    [_SIGNS] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_CAPS,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_SLSH, KC_BSLS, KC_LBRC, KC_RBRC,  KC_NO,  KC_PGUP,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSFT, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR,  KC_DLR,                    KC_UNDS,  KC_EQL, KC_MINS, KC_PLUS,  KC_UP,  KC_PGDN,
    // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LCTL, KC_QUOT,  KC_LT,   KC_GT,   KC_DQT,  KC_NO,  KC_TRNS,  QK_LEAD,  KC_NO,   KC_NO,   KC_GRV, KC_LEFT, KC_DOWN, KC_RIGHT,
    // └────────┴────────┴────────┴────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                            KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
    //                                     └────────┴────────┴────────┘└────────┴────────┴────────┘
    ),
    [_GAMING] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_GRV,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TAB,   KC_T,    KC_Q,    KC_W,    KC_E,    KC_R,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_PPLS,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSFT,   KC_G,    KC_A,    KC_S,    KC_D,    KC_F,                       KC_H,    KC_J,    KC_K,    KC_L,   KC_UP,  TG(_GAMING),
    // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LCTL,   KC_B,    KC_Z,    KC_X,    KC_C,    KC_V,  KC_LALT,  QK_LEAD,   KC_N,    KC_M,  KC_COMM, KC_LEFT, KC_DOWN, KC_RGHT,
    // └────────┴────────┴────────┴────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                            KC_TAB,OSL(_GAMOD),KC_SPC,   KC_ENT, KC_BSPC, KC_LGUI
    //                                     └────────┴────────┴────────┘└────────┴────────┴────────┘
    ),
    [_GAMOD] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSFT,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LCTL,  KC_NO,   KC_NO,   KC_NO,  KC_MUTE,  KC_NO,  KC_TRNS,  QK_LEAD,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    // └────────┴────────┴────────┴────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                            KC_TRNS, KC_LCTL, KC_LCTL,  KC_TRNS, KC_TRNS, KC_TRNS
    //                                     └────────┴────────┴────────┘└────────┴────────┴────────┘
    ),
    [_LEADER] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_QUOT,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSFT,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN, CW_TOGG,
    // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_BSPC, QK_LEAD,   KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
    // └────────┴────────┴────────┴────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                            KC_LGUI,  KC_NO,   KC_SPC,   KC_ENT, KC_LSFT, KC_LALT
    //                                     └────────┴────────┴────────┘└────────┴────────┴────────┘
    )
};
// clang-format on

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TAB_SIG:
            return 100;
        default:
            return TAPPING_TERM;
    }
}

/*
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
bool leader_mode = false;
bool capsWordStatus = false;

void update_caps(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data)
{
    capsWordStatus = *((const uint8_t*)in_data);
}

void update_leader(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data)
{
    leader_mode = *((const uint8_t*)in_data);
}

bool is_leader_active(void)
{
    return leader_mode;
}

/*
 * |00|01|02|03|04|05|          |39|38|37|36|35|34|
 * |11|10|09|08|07|06|          |40|41|42|43|44|45|
 * |12|13|14|15|16|17|          |51|50|49|48|47|46|
 * |23|22|21|20|19|18|27|    |61|52|53|54|55|56|57|
 *             |24|25|26|    |60|59|58|
 */

const uint8_t indexes[] = {24, 25, 26, 27, 61, 60, 59, 58};
const size_t numIndexes = sizeof(indexes) / sizeof(indexes[0]);

void cluster_color(void)
{
    if (is_leader_active() | leader_mode) {
        for (size_t i = 0; i < numIndexes; i++) {
            if (i >= 0 && i <= 3) {
                rgb_matrix_set_color(indexes[i], 0, 0, 25);
            } else {
                rgb_matrix_set_color(indexes[i], 25, 8, 0);
            }
        }
    } else if (is_caps_word_on() | capsWordStatus) {
        if (host_keyboard_led_state().caps_lock) {
            for (size_t i = 0; i < numIndexes; i++) {
                rgb_matrix_set_color(indexes[i], 22, 2, 6);
            }
        } else {
            for (size_t i = 0; i < numIndexes; i++) {
                rgb_matrix_set_color(indexes[i], 24, 21, 0);
            }
        }
    } else if (host_keyboard_led_state().caps_lock) {
        for (size_t i = 0; i < numIndexes; i++) {
            rgb_matrix_set_color(indexes[i], 0, 24, 0);
        }
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max)
{
    cluster_color();
    return true;
}

void housekeeping_task_user(void)
{
    if (is_keyboard_master()) {
        static uint32_t last_sync = 0;
        if (timer_elapsed32(last_sync) > 100) {
            bool active_caps = is_caps_word_on();
            bool active_leader = is_leader_active();
            transaction_rpc_send(CAPS_WORD_SYNC, sizeof(active_caps), &active_caps);
            transaction_rpc_send(LEADER_SYNC, sizeof(active_leader), &active_leader);
        }
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _QWERTY:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(198, 255, 200);
        case _COLEMAK:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(198, 255, 200);
            break;
        case _SIGNS:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(255, 255, 255);
            break;
        case _GAMING:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_PIXEL_RAIN);
            break;
    }
    return state;
}

// leader
void leader_start_user(void)
{
    leader_mode = true;
    layer_on(_LEADER);
}

void leader_end_user(void)
{
    leader_mode = false;
    layer_off(_LEADER);

    if (leader_sequence_one_key(QK_LEAD)) {
        return;

    } else if (leader_sequence_two_keys(KC_L, KC_G)) {
        layer_move(_GAMING);

    } else if (leader_sequence_two_keys(KC_L, KC_Q)) {
        layer_move(_QWERTY);

    } else if (leader_sequence_two_keys(KC_L, KC_C)) {
        layer_move(_COLEMAK);

    } else if (leader_sequence_two_keys(KC_T, KC_R)) {
        rgb_matrix_toggle();

    } else if (leader_sequence_two_keys(KC_T, KC_L)) {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_PIXEL_RAIN);
    }
}

void keyboard_post_init_user(void)
{
    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
    rgb_matrix_sethsv_noeeprom(198, 255, 200);
    rgb_matrix_set_speed(31);
    transaction_register_rpc(CAPS_WORD_SYNC, update_caps);
    transaction_register_rpc(LEADER_SYNC, update_leader);
}
