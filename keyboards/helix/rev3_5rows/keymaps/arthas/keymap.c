/* Copyright 2020 yushakobo
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
#include "layer_number.h"

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    RGBRST = SAFE_RANGE
};

#define LOWER TT(_LOWER)
#define TG_LOW TG(_LOWER)
#define RAISE MO(_RAISE)
#define LAUNCH MO(_LAUNCH)

#define LAYOUT_wrapper(...)    LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | GEsc |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | F19  |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   [  |   ]  |   N  |   M  |   ,  |   .  |   /  |SftEnt|
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Ctrl | Lower| GUI  | Alt  |Launch|Raise |Space |Space |Raise |Launch| RAlt | Menu |Lower |RCtrl |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT( \
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
      KC_F19,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT, \
      KC_LCTL, LOWER,   KC_LGUI, KC_LALT, LAUNCH, RAISE,    KC_SPC,  KC_SPC,  RAISE,   LAUNCH,  KC_RALT, KC_APP,  LOWER,   KC_RCTL \
    ),
  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             | Prev | Next | Mute | Vol- | Vol+ | Play |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |G Tab |  F6  |  F7  |  F8  |  F9  |  F10 |             |      |  Up  |      | Home | PgUp |PtrSc |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |TG Low|      |      |      |  F11 |  F12 |             | Left | Down |Right | End  | PgDn |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      | WBAK | WFWD |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  #define GUI_TAB LGUI(KC_TAB)

  [_LOWER] = LAYOUT( \
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, \
      GUI_TAB, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                    XXXXXXX, KC_UP,   XXXXXXX, KC_HOME, KC_PGUP, KC_PSCR, \
      TG_LOW,  XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,  KC_F12,                    KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_PGDN, XXXXXXX, \
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WBAK, KC_WFWD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
      ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   `  |      |      |      |      |      |             |      |      |      |      |      | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |   +  |   _  |             |   _  |   +  |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |   =  |   -  |             |   -  |   =  |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT( \
      KC_GRV,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,  \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PLUS, KC_UNDS,                   KC_UNDS, KC_PLUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_EQL,  KC_MINS,                   KC_MINS, KC_EQL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
      ),

  /* Launch (Start or focus)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      | FFOX |TBIRD |TGRAM |FRANZ |SPTFY |             | FFDE |SLACK |DBEAV |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |FILES |      |      |      |VWIKI |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |TORREN| STREM|      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */

#define FIREFOX LGUI(KC_F1)
#define THUNDER LGUI(KC_F2)
#define TELEGRM LGUI(KC_F3)
#define FRANZ LGUI(KC_F4)
#define SPOTIFY LGUI(KC_F5)
#define FILEEXP LGUI(KC_F6)
#define VIMWIKI LGUI(KC_F10)
#define TORRENT LGUI(KC_F11)
#define STREMIO LGUI(KC_F12)

#define FFDEVED SGUI(KC_F1)
#define SLACK SGUI(KC_F2)
#define DBEAVER SGUI(KC_F3)

  [_LAUNCH] =  LAYOUT( \
      XXXXXXX, FIREFOX, THUNDER, TELEGRM, FRANZ,   SPOTIFY,                   FFDEVED, SLACK,   DBEAVER, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, FILEEXP, XXXXXXX, XXXXXXX, XXXXXXX, VIMWIKI,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, TORRENT, STREMIO, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
      ),

#define KP_EQ____SLASH____ASTER KC_KP_EQUAL, KC_KP_SLASH, KC_KP_ASTERISK
#define KP_MINUS KC_KP_MINUS
#define KP_PLUS KC_KP_PLUS
#define KP_DOT KC_KP_DOT
#define KP_ENTER KC_KP_ENTER

  /* Keypad (Lower + Launch)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |Nlock |      |   =  |   /  |   *  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |   7  |   8  |   9  |   -  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |   4  |   5  |   6  |   +  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      | Shift| Shift|      |      |      |      |      |      |   1  |   2  |   3  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |   0  |   0  |   .  |Enter |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_KEYPAD] =  LAYOUT_wrapper( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_NLCK, XXXXXXX, KP_EQ____SLASH____ASTER,   KC_BSPC, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, KP_MINUS,\
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, KP_PLUS, \
      _______, XXXXXXX, KC_LSFT, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, KP_ENTER,\
      _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_KP_0, KC_KP_0, KP_DOT,  KP_ENTER \
      ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      | CAPS |Insert| Pause|
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | Reset|RGBRST|EEPRST|      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |RGB ON| HUE+ | SAT+ | VAL+ |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | MODE | HUE- | SAT- | VAL- |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ADJUST] =  LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS, KC_INS,  KC_PAUS, \
      XXXXXXX, RESET,   RGBRST,  EEP_RST, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
      )

};

// Light LEDs 18 to 31 and 50 to 63 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM rgb_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {18, 14, HSV_RED},      // Light 14 LEDs, starting with LED 18
    {50, 14, HSV_RED}       // Light 14 LEDs, starting with LED 50
);

// Light LEDs 25 to 31 and 57 to 63 in purple when keyboard layer Adjust is active
const rgblight_segment_t PROGMEM rgb_adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {25, 7, HSV_PURPLE},
    {57, 7, HSV_PURPLE}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_capslock_layer,
    rgb_adjust_layer
);


void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t previous_state = _QWERTY;
uint8_t default_hue = 168;
uint8_t default_sat = 51;
uint8_t default_val = 51;

void set_default_color(void) {
    if (previous_state == default_layer_state || get_highest_layer(previous_state) == _ADJUST) {
        default_hue = rgblight_get_hue();
        default_sat = rgblight_get_sat();
        default_val = rgblight_get_val();
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    state = update_tri_layer_state(state, _LOWER, _LAUNCH, _KEYPAD);

    switch (get_highest_layer(state)) {
    case _LOWER:
        set_default_color();
        rgblight_sethsv_noeeprom(106, 255, 69);
        break;
    case _RAISE:
        set_default_color();
        rgblight_sethsv_noeeprom(43, 255, 69);
        break;
    case _LAUNCH:
        set_default_color();
        rgblight_sethsv_noeeprom(180, 255, 69);
        break;
    default: //  for any other layers, or the default layer
        rgblight_sethsv_noeeprom(default_hue, default_sat, default_val);
        break;
    }

    rgblight_set_layer_state(1, layer_state_cmp(state, _ADJUST));

    previous_state = state;
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGBRST:
        #ifdef RGBLIGHT_ENABLE
            if (record->event.pressed) {
                eeconfig_update_rgblight_default();
                rgblight_enable();
            }
        #endif
            break;
    }

    return true;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}
