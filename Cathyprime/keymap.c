#include QMK_KEYBOARD_H
#include "transactions.h"

#pragma region DEBUG
#ifdef CONSOLE_ENABLE

#include "print.h"
#define GET_MACRO(_1, _2, NAME, ...) NAME
#include <string.h>

#define __FILENAME__ "keymap.c"

#define DEBUG_LOG1(x) print(__FILENAME__":"STR(__LINE__)":" x"\n")
#define DEBUG_LOGM(x, ...) uprintf(__FILENAME__":"STR(__LINE__)":"x"\n", __VA_ARGS__)

#define log_msg(...) GET_MACRO(__VA_ARGS__, DEBUG_LOGM, DEBUG_LOG1)(__VA_ARGS__)
#define log_expr(expr) DEBUG_LOG1(#expr)

#else
#define log_msg(...)
#define log_expr(expr)
#endif
#pragma endregion DEBUG

enum layers {
    _QWERTY,
    _SIGNS,
    _GAMING,
    _GAMOD,
};

// #define MY_PURPLE 136, 255, 255
#define MY_PURPLE 198, 255, 200

// #define MY_RED    194, 255, 255
#define MY_RED    255, 255, 255

#define MY_YELLOW 42, 255, 255

#define TAB_SIG LT(_SIGNS, KC_TAB)
#define ESC_ALT MT(MOD_LALT, KC_ESC)
#define TAB_GUI MT(MOD_LGUI, KC_TAB)

volatile bool can_rgb = false;
#define RGB_SYNC_RETRY_INTERVAL 100
#define GAMING_RAIN_DELAY 120
#define rgb_set_mode(mode) do { if (can_rgb) rgb_matrix_mode_noeeprom(mode); } while(0)
#define rgb_set_color(...) do { if (can_rgb) rgb_matrix_sethsv_noeeprom(__VA_ARGS__); } while(0)
#define rgb_enable()       do { if (can_rgb) rgb_matrix_enable_noeeprom(); } while(0)
#define rgb_toggle()       do { if (can_rgb) rgb_matrix_toggle(); } while(0)

#define DELAYED_ACTION_READY(action, delay) ((action).pending && timer_elapsed((action).timer) > (delay))
typedef struct {
    uint16_t timer;
    bool pending;
} delayed_action_t;

static delayed_action_t rgb_sync = (delayed_action_t) {
    .timer = 0,
    .pending = false
};

static delayed_action_t gaming_rain = (delayed_action_t) {
    .timer = 0,
    .pending = false
};

enum custom_keycodes {
    MUTE_RGB = SAFE_RANGE,
    GAMING_TG
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
        TAB_GUI,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_QUOT,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSFT,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN, KC_RALT,
    // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, GAMING_TG,MUTE_RGB, KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
    // └────────┴────────┴────────┴────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                            ESC_ALT, TAB_SIG,  KC_SPC,   KC_ENT, KC_BSPC, KC_LGUI
    //                                     └────────┴────────┴────────┘└────────┴────────┴────────┘
    ),
    [_SIGNS] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_CAPS, CW_TOGG,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_SLSH, KC_BSLS, KC_LBRC, KC_RBRC, KC_PGDN, KC_PGUP,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSFT, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR,  KC_DLR,                    KC_UNDS,  KC_EQL, KC_MINS, KC_HOME,  KC_UP,  KC_END,
    // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LCTL, KC_QUOT,  KC_LT,   KC_GT,   KC_MUTE, KC_NO,  KC_TRNS,  MUTE_RGB, KC_NO,  KC_PLUS,  KC_GRV, KC_LEFT, KC_DOWN, KC_RIGHT,
    // └────────┴────────┴────────┴────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                            ESC_ALT, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_DEL,  KC_TRNS
    //                                     └────────┴────────┴────────┘└────────┴────────┴────────┘
    ),
    [_GAMING] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_GRV,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_PPLS,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LCTL,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,   KC_UP,  KC_RSFT,
    // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, GAMING_TG,MUTE_RGB, KC_N,    KC_M,  KC_COMM, KC_LEFT, KC_DOWN, KC_RGHT,
    // └────────┴────────┴────────┴────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                           KC_LALT, MO(_GAMOD),KC_SPC,   KC_ENT, KC_BSPC, KC_ESC
    //                                     └────────┴────────┴────────┘└────────┴────────┴────────┘
    ),
    [_GAMOD] = LAYOUT(
    // ┌────────┬────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
         KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    // ├────────┼────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS,  KC_NO,   KC_NO,   KC_NO,  KC_MUTE,  KC_NO,  KC_TRNS,  MUTE_RGB, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    // └────────┴────────┴────────┴────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┴────────┴────────┴────────┘
                                            ESC_ALT, KC_TRNS, KC_LCTL,  KC_TRNS,  KC_DEL, KC_TRNS
    //                                     └────────┴────────┴────────┘└────────┴────────┴────────┘
    )
};
// clang-format on

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode) {
        case TAB_SIG: return 100;
        default:      return TAPPING_TERM;
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

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max)
{
    static const uint8_t cluster_leds[] = {24, 25, 26, 27, 61, 60, 59, 58};

    if (!can_rgb) return true;
    if (host_keyboard_led_state().caps_lock) {
        for (size_t i = 0; i < ARRAY_SIZE(cluster_leds); i++) {
            RGB_MATRIX_INDICATOR_SET_COLOR(cluster_leds[i], 0, 24, 0);
        }
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state))
    {
        case _QWERTY: {
            gaming_rain.pending = false;
            rgb_set_mode(RGB_MATRIX_SOLID_REACTIVE);
            rgb_set_color(MY_PURPLE);
        } break;
        case _SIGNS: {
            gaming_rain.pending = false;
            rgb_set_mode(RGB_MATRIX_SOLID_REACTIVE);
            rgb_set_color(MY_RED);
        } break;
    }
    return state;
}

typedef struct {
    bool new_state;
    bool written;
} acknowledgement_t;

static void update_rgb_slave_handler(uint8_t in_buflen, const void *in_data, uint8_t out_buflen, void *out_data)
{
    can_rgb = *(const bool*)in_data;
    *(acknowledgement_t*)out_data = (acknowledgement_t) {
        .new_state = can_rgb,
        .written = true
    };
}

// true -> both master and slave are updated
// false -> transaction either not suceeded or slave didn't update it confirm the update
// even when false, the slave might've updated it
static bool update_rgb(bool new_state)
{
    if (!is_keyboard_master()) return false;

    can_rgb = new_state;
    acknowledgement_t response = { .written = false };

    bool success = transaction_rpc_exec(
        RGB_STATE,
        sizeof(new_state), &new_state,
        sizeof(response), &response
    );

    return success
        && response.written
        && response.new_state == new_state;
}

void housekeeping_task_user(void)
{
    if (!is_keyboard_master()) return;

    if (DELAYED_ACTION_READY(rgb_sync, RGB_SYNC_RETRY_INTERVAL)) {
        rgb_sync.pending = !update_rgb(can_rgb);
        rgb_sync.timer = timer_read();
    }

    if (DELAYED_ACTION_READY(gaming_rain, GAMING_RAIN_DELAY)) {
        gaming_rain.pending = false;
        rgb_set_mode(RGB_MATRIX_PIXEL_RAIN);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    log_msg("process_record_user");
    static uint16_t mute_timer;

    switch (keycode) {
        case GAMING_TG: {
            if (record->event.pressed) {
                layer_invert(_GAMING);
                if (layer_state_is(_GAMING)) {
                    rgb_set_mode(RGB_MATRIX_SOLID_REACTIVE);
                    rgb_set_color(MY_YELLOW);
                    gaming_rain.timer = timer_read();
                    gaming_rain.pending = true;
                } else {
                    gaming_rain.pending = false;
                }
            }
            return false;
        } break;
        case MUTE_RGB: {
            if (record->event.pressed) {
                mute_timer = timer_read();
                return false;
            }
            if (timer_elapsed(mute_timer) < TAPPING_TERM)
                tap_code(KC_MUTE);
            else
                rgb_toggle();

            return false;
        } break;
        default: break;
    }

    return true;
}

bool shutdown_user(bool)
{
    rgb_sync.pending = false;
    update_rgb(false);
    return true;
}

void keyboard_post_init_user(void)
{
    transaction_register_rpc(RGB_STATE, update_rgb_slave_handler);
    if (is_keyboard_master()) {
        rgb_sync.pending = !update_rgb(true);
        rgb_sync.timer = timer_read();
    }
    #ifdef CONSOLE_ENABLE
    debug_enable = true;
    #endif
    rgb_enable();
    rgb_set_mode(RGB_MATRIX_SOLID_REACTIVE);
    rgb_set_color(MY_PURPLE);
    rgb_matrix_set_speed(31);
}
