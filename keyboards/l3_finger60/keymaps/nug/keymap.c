#include QMK_KEYBOARD_H

#define ______ KC_TRNS
#define TT_L1 TT(_L1) /* toggle LAYER ONE on double tap, LAYER ONE on hold */
#define LT_L1SP LT(_L1, KC_SPC) /* SPACE on tap, LAYER ONE on hold */
#define LT_L1DE LT(_L1, KC_DEL) /* DELETE on tap, LAYER ONE on hold */
#define RCTL_RA RCTL_T(KC_RGHT) /* Right arrow on tap, CTRL on hold */
#define RSFT_UA RSFT_T(KC_UP)   /* Up arrow on tap, SHIFT on hold */
#define RALT_LA RALT_T(KC_LEFT) /* Left arrow on tap, ALT on hold */
#define RGUI_DA RGUI_T(KC_DOWN) /* Down arrow on tap, GUI on hold */

enum layers {
  _L0 = 0,
  _L1,
};

/* 
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ESC│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ ( │ ) │ BKSPC │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │ TAB │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │ FUNC │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ ENTER  │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
 * │ SHIFT  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │SHIFT │FN │
 * ├─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬───┬─┴───┤
 * │CTRL │GUI│ ALT │         SPACE (7u)        │ ALT │GUI│CTRL │
 * └─────┴───┴─────┴───────────────────────────┴─────┴───┴─────┘
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_L0] = KEYMAP(
    KC_GESC,    KC_1,    KC_2,    KC_3,    KC_4,   KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,  KC_EQL,   KC_NO, KC_BSPC,
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_LBRC, KC_RBRC, KC_BSLS,         
      TT_L1,    KC_A,    KC_S,    KC_D,    KC_F,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,   KC_NO,  KC_ENT,         
    KC_LSFT,   KC_NO,    KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT,  KC_SLSH, LT_L1DE, RSFT_UA,
    KC_LCTL, KC_LGUI, KC_LALT,    KC_R, LT_L1SP,   KC_O, RALT_LA,   KC_NO,   KC_NO, RGUI_DA, RCTL_RA),

  [_L1] = KEYMAP(
     KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_F11,  KC_F12,  ______, KC_DEL,
     ______,  ______,   KC_UP,  ______,  ______, ______,  ______,  ______, KC_PGUP,  ______,  ______,   ______,  ______,  KC_INS,        
     ______, KC_LEFT, KC_DOWN, KC_RGHT,  ______, ______,  ______, KC_HOME, KC_PGDN,  KC_END,  ______,   ______,  ______,  ______,        
     ______,  ______,  ______,  ______,  ______, ______,  ______,  ______,  ______,  ______,  ______,   ______,  ______, KC_PGUP,
     ______,  ______,  ______,  ______,  ______, ______, KC_HOME,  ______,  ______, KC_PGDN,  KC_END),
};


uint32_t layer_state_set_user(uint32_t state) {
  switch(biton32(state)) {
  case _L1:
    led_on();
    rgb_off();
    break;
  default:
    led_off();
    rgb_off();
    break;
  }
  return state;
}