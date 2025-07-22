/* Copyright 2023 Brian Low
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

// keymap setting and etc...

// store the state
static bool _is_key_locked = false;

void keyboard_post_init_user(void) {
  // need to stop effects and animations
  rgb_matrix_mode(RGB_MATRIX_NONE);
  rgb_matrix_sethsv(HSV_OFF);
}

void rgb_matrix_indicators_user(void) {
  int key_index = 10; // set your key index here
  if (_is_key_locked) {
    rgb_matrix_set_color(key_index, RGB_WHITE);
  } else {
    rgb_matrix_set_color(key_index, RGB_BLACK);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_A: // set your keycode here
      if (record->event.pressed) {
        _is_key_locked = !_is_key_locked;
      }
      break;
  }
  return true;
}

 */
#include QMK_KEYBOARD_H
#include "keymap_extras/keymap_german.h"

enum sofle_layers {
    _NEO,
    _QWERTZ,
    _SYMB,
    _NAVNUM,
    _ADJUST,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 * NEO2 Basic Layer
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ADJ  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   X  |   V  |   L  |   C  |   W  |                    |   K  |   H  |   G  |   F  |   Q  |   ß  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   U  |   I  |   A  |   E  |   O  |-------.    ,-------|   S  |   N  |   R  |   T  |   D  |  Y   |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |LShift|   Ü  |   Ö  |   Ä  |   P  |   Z  |-------|    |-------|   B  |   M  |   ,  |   .  |   J  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LGUI | NAV  | SYM  | / Enter /       \Space \  | SYM  |  NAV | LALT | RCTL |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 [_NEO] = LAYOUT(
    TG(_ADJUST), KC_1,   KC_2,    KC_3,    KC_4,        KC_5,                               KC_6,     KC_7,         KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,      DE_X,   DE_V,    DE_L,    DE_C,        DE_W,                               DE_K,     DE_H,         DE_G,    DE_F,    DE_Q,    DE_SS,
    KC_ESC,      DE_U,   DE_I,    DE_A,    DE_E,        DE_O,                               DE_S,     DE_N,         DE_R,    DE_T,    DE_D,    DE_Y,
    KC_LSFT,     DE_UDIA,DE_ODIA, DE_ADIA, DE_P,        DE_Z,      KC_MUTE,        KC_MPLY, DE_B,     DE_M,         DE_COMM, DE_DOT,  DE_J,    KC_RSFT,
                         KC_LCTL, KC_LGUI, MO(_NAVNUM), MO(_SYMB), LSFT_T(KC_ENT), RSFT_T(KC_SPC),  MO(_SYMB), MO(_NAVNUM), KC_LALT, KC_RCTL
),
 */
[_NEO] = LAYOUT(
    TG(_ADJUST),       KC_1,         KC_2,    KC_3,    KC_4,   KC_5,                           KC_6,     KC_7,         KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,            DE_X,         DE_V,    DE_L,    DE_C,   DE_W,                           DE_K,     DE_H,         DE_G,    DE_F,    DE_Q,    DE_SS,
    LT(_SYMB, KC_ESC), LSFT_T(DE_U), DE_I,    DE_A,    DE_E,   DE_O,                           DE_S,     DE_N,         DE_R,    DE_T,    RSFT_T(DE_D),    LT(_SYMB, DE_Y),
    KC_LSFT,           DE_UDIA,      DE_ODIA, DE_ADIA, DE_P,   DE_Z,      KC_MUTE,    KC_MPLY, DE_B,     DE_M,         DE_COMM, DE_DOT,  DE_J,    KC_RSFT,
                         KC_LGUI, MO(_NAVNUM), MO(_SYMB), LSFT_T(KC_ENT), KC_LCTL,    KC_RCTL, RSFT_T(KC_SPC), MO(_SYMB), MO(_NAVNUM), KC_LALT
),

/* Keymap 1: Basic layer
 * QWERTZ Basic Layer
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ADJ  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Z  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |LShift|   Y  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LGUI | NAV  | SYM  | / Enter /       \Space \  | SYM  |  NAV | LALT | RCTL |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTZ] = LAYOUT(
    TG(_ADJUST), KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_GRV,
    KC_TAB,      KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                              KC_Z,     KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,      KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,     KC_Y,   KC_X,    KC_C,    KC_V,    KC_B,          KC_MUTE,   KC_MPLY, KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                         KC_LCTL, KC_LGUI, MO(_NAVNUM), MO(_SYMB), KC_ENT,    KC_SPC,  MO(_SYMB), MO(_NAVNUM), KC_LALT, KC_RCTL
),

 /* Keymap 2: Symbol layer
 * NEO2 Symbol Layer
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   €  |   _  |   [  |   ]  |   ^  |                    |   !  |   <  |   >  |   =  |   &  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   \  |   /  |   {  |   }  |   *  |-------.    ,-------|   ?  |   (  |   )  |   -  |   :  |  @   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   #  |   $  |   |  |   ~  |   `  |-------|    |-------|   +  |   %  |   "  |   '  |   ;  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_SYMB] = LAYOUT(
    KC_TRNS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,    KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_F11,
    KC_TRNS,   DE_EURO, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC,                    DE_EXLM,  DE_LABK,  DE_RABK, DE_EQL,  DE_AMPR,  KC_F12,
    KC_TRNS,   DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,                    DE_QUES,  DE_LPRN,  DE_RPRN, DE_MINS, DE_COLN,  DE_AT,
    KC_TRNS,   DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, DE_GRV,  KC_TRNS,  KC_TRNS, DE_PLUS,  DE_PERC,  DE_DQUO, DE_QUOT, DE_SCLN,  KC_TRNS,
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS
),

/* Keymap 3: Navigation/Numeric layer
 * NEO2 Navigation/Numeric Layer
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |   /  |   *  |   -  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | PGUP | BSPC |  UP  |  DEL | PGDN |                    |      |   7  |   8  |   9  |   +  |  −   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | HOME | LEFT | DOWN | RGHT | END  |-------.    ,-------|      |   4  |   5  |   6  |   ,  |  .   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |  TAB | INS  | ENTR |      |-------|    |-------|   :  |   1  |   2  |   3  |   ;  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \   0  \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NAVNUM] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,                   KC_TRNS,  KC_TRNS, DE_SLSH, DE_ASTR, DE_MINS,  KC_TRNS,
    KC_TRNS, KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,   KC_PGDN,                   KC_TRNS,  DE_7,    DE_8,    DE_9,    DE_PLUS,  DE_MINS,
    KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END,                    KC_TRNS,  DE_4,    DE_5,    DE_6,    DE_COMM,  DE_DOT,
    KC_TRNS, KC_TRNS, KC_TAB,  KC_INS,  KC_ENTER, KC_TRNS, KC_TRNS, KC_TRNS, DE_COLN,  DE_1,    DE_2,    DE_3,    DE_SCLN,  KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, DE_0,    DE_0,  KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 4: Presets / Mouse
 * Presets / Mouse
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      | RGB T| RGB> | RGB< |      |      |                    |      |      |      |      |      | BOOT |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | NEO  |      |      | MsUp |      |      |                    |      |      |      |      |      |CLEAR |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | QWERT|      | MsL  |MsDwn |  MsR |      |-------.    ,-------|      | Lclk | Rclk |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_ADJUST] = LAYOUT(
    KC_TRNS,     RM_TOGG, RM_NEXT, RM_PREV, KC_TRNS, KC_TRNS,               KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  QK_BOOT,
    DF(_NEO),    KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS,               KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  QK_CLEAR_EEPROM,
    DF(_QWERTZ), KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,               KC_TRNS,  KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
)

};

/* RGB Matrix
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  28  |  21  |  20  |  11  |  10  |  0   |                    |  29  |  39  |  40  |  49  |  50  |  58  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  27  |  22  |  19  |  12  |   9  |  1   |                    |  30  |  38  |  41  |  48  |  51  |  56  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  26  |  23  |  18  |  13  |   8  |  2   |-------.    ,-------|  31  |  37  |  42 |   47  |  52  |  55  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |  25  |  24  |  17  |  14  |   7  |  3   |-------|    |-------|  32  |  36  |  43  |  46  |  53  |  54  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /   4   /       \  33  \  |      |      |      |      |
 *            |  16  |  15  |   6  |   5  |/       /         \      \ |  34  |  35  |   44 |   45 |
 *            `----------------------------------'           '------''---------------------------'
 */

void keyboard_post_init_user(void) {
  // need to stop effects and animations
  rgb_matrix_mode(RGB_MATRIX_NONE);
  rgb_matrix_sethsv(HSV_OFF);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    //rgb_matrix_mode(RGB_MATRIX_NONE);
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _NEO:
            rgb_matrix_set_color(8, RGB_BLUE);
            rgb_matrix_set_color(13, RGB_BLUE);
            rgb_matrix_set_color(18, RGB_BLUE);
            rgb_matrix_set_color(23, RGB_BLUE);

            rgb_matrix_set_color(37, RGB_BLUE);
            rgb_matrix_set_color(42, RGB_BLUE);
            rgb_matrix_set_color(47, RGB_BLUE);
            rgb_matrix_set_color(52, RGB_BLUE);

            //rgb_matrix_set_color(50, RGB_BLUE);
            break;
        case _SYMB:
            rgb_matrix_set_color(37, RGB_BLACK);
            rgb_matrix_set_color(42, RGB_BLACK);
            rgb_matrix_set_color(47, RGB_BLACK);
            rgb_matrix_set_color(52, RGB_BLACK);
            rgb_matrix_set_color(9, RGB_YELLOW);
            rgb_matrix_set_color(12, RGB_YELLOW);
            break;
        case _NAVNUM:
            rgb_matrix_set_color(12, RGB_RED);
            rgb_matrix_set_color(13, RGB_RED);
            rgb_matrix_set_color(18, RGB_RED);
            rgb_matrix_set_color(8, RGB_RED);

            rgb_matrix_set_color(38, RGB_ORANGE);
            rgb_matrix_set_color(41, RGB_ORANGE);
            rgb_matrix_set_color(48, RGB_ORANGE);
            rgb_matrix_set_color(37, RGB_ORANGE);
            rgb_matrix_set_color(42, RGB_ORANGE);
            rgb_matrix_set_color(47, RGB_ORANGE);
            rgb_matrix_set_color(36, RGB_ORANGE);
            rgb_matrix_set_color(43, RGB_ORANGE);
            rgb_matrix_set_color(46, RGB_ORANGE);
            rgb_matrix_set_color(34, RGB_ORANGE);

             //rgb_matrix_set_color(50, RGB_RED);
            break;
        default:
            break;
    }

    /*
    if (HAS_FLAGS(g_led_config.flags[35], LED_FLAG_MODIFIER)) { // LED 35 = erste LED rechts
        rgb_matrix_set_color(35, 255, 0, 0); // Leuchtet rot
    }
  rgb_matrix_set_color(8, RGB_WHITE);
  rgb_matrix_set_color(13, RGB_WHITE);
  rgb_matrix_set_color(18, RGB_WHITE);
  rgb_matrix_set_color(23, RGB_WHITE);
  rgb_matrix_set_color(30, RGB_WHITE);
  rgb_matrix_set_color(36, RGB_BLACK);

    rgb_matrix_set_color(30, RGB_WHITE);
    rgb_matrix_set_color(0, RGB_WHITE);
    rgb_matrix_set_color(29, RGB_BLACK);
  
  for (uint8_t i = led_min; i < 35; i++) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _NEO:
            rgb_matrix_set_color(i, RGB_BLUE);
            break;
        case _SYMB:
            rgb_matrix_set_color(i, RGB_YELLOW);
            break;
        default:
            break;
    }
  }
*/
   return false;
}


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_NEO] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(LGUI(LCTL(KC_LEFT)), LGUI(LCTL(KC_RGHT))) }, // LSFT(LCTL(KC_LEFT))
    [_QWERTZ] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [_SYMB] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [_NAVNUM] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [_ADJUST] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
};
#endif
