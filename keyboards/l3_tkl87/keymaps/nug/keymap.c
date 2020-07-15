#include QMK_KEYBOARD_H

#define ______ KC_TRNS
#define LT_L1SP LT(_L1, KC_SPC) /* SPACE on tap, LAYER ONE on hold */
#define TG_L2 TG(_L2) /* toggle LAYER TWO (Gaming layer) */

enum layers {
  _L0 = 0,
  _L1,
  _L2,
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  TRIPLE_TAP = 4,
};

//Tap dance enums
enum {
  X_GUI = 0,
};

int cur_dance (qk_tap_dance_state_t *state);

//for the x tap dance. Put it here so it can be used in any keymap
void x_finished (qk_tap_dance_state_t *state, void *user_data);
void x_reset (qk_tap_dance_state_t *state, void *user_data);

/* 
 * ┌───┬──┬───┬───┬───┬───┬─┬───┬───┬───┬───┬──┬───┬───┬───┬───┐ ┌───┬───┬───┐
 * │ESC│  │F1 │F2 │F3 │F4 │ │F5 │F6 │F7 │ F8│  │F9 │F10│F11│F12│ │PRS│SCR│PAU│
 * └───┴──┴───┴───┴───┴───┴─┴───┴───┴───┴───┴──┴───┴───┴───┴───┘ └───┴───┴───┘
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐
 * │ ~ │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ ( │ ) │ BKSPC │ │INS│HOM│PGU│
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤
 * │ TAB │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │ │DEL│END│PGD│
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘
 * │ FUNC │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ ENTER  │ 
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤     ┌───┐
 * │ SHIFT  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │SHIFT │FN │     │UP │ 
 * ├─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬───┬─┴───┤ ┌───┼───┼───┐
 * │CTRL │GUI│ ALT │         SPACE (7u)        │ ALT │GUI│CTRL │ │LFT│DWN│RGT│
 * └─────┴───┴─────┴───────────────────────────┴─────┴───┴─────┘ └───┴───┴───┘
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_L0] = KEYMAP(
     KC_ESC,   KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,                   KC_PSCR, KC_SLCK, KC_PAUS,
     KC_GRV,    KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL,   KC_NO, KC_BSPC,  KC_INS, KC_HOME, KC_PGUP,
     KC_TAB,    KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSLS,           KC_DEL,  KC_END, KC_PGDN,
  TD(X_GUI),    KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,   KC_NO,  KC_ENT,
    KC_LSFT,   KC_NO,    KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,                              KC_UP,
    KC_LCTL, KC_LGUI, KC_LALT,                         LT_L1SP,                   KC_RALT, KC_RGUI, KC_RCTL,                            KC_LEFT, KC_DOWN, KC_RGHT),

  [_L1] = KEYMAP(
     ______,  ______,  ______,  ______, ______, ______, ______,  ______,  ______,  ______,  ______,  ______,  ______,                    ______,  ______,  ______,
     ______,  ______,  ______,  ______, ______, ______, ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,
     ______,  ______,   KC_UP,  ______, ______, ______, ______,  ______, KC_PGUP,  ______,  ______,  ______,  ______,  ______,           ______,  ______,  ______,
     ______, KC_LEFT, KC_DOWN, KC_RGHT, ______, ______, ______, KC_HOME, KC_PGDN,  KC_END,  ______,  ______,  ______,  ______,
     ______,  ______,  ______,  ______, ______, ______, ______,  ______,  ______,  ______,  ______,  ______,  ______,                            KC_PGUP,
     ______,  ______,  ______,                          ______,                    ______,  ______,  ______,                            KC_HOME, KC_PGDN,  KC_END),

  [_L2] = KEYMAP(
     KC_ESC,   KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,                   KC_PSCR, KC_SLCK, KC_PAUS,
     KC_GRV,    KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL,  ______, KC_BSPC,  KC_INS, KC_HOME, KC_PGUP,
     KC_TAB,    KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSLS,           KC_DEL,  KC_END, KC_PGDN,
     ______,    KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  ______,  KC_ENT,
    KC_LSFT,  ______,    KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,                              KC_UP,
    KC_LCTL,   KC_NO, KC_LALT,                          KC_SPC,                   KC_RALT, KC_RGUI, KC_RCTL,                            KC_LEFT, KC_DOWN, KC_RGHT),
};

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    return DOUBLE_TAP;
  }
  else if (state->count == 3) {
    return TRIPLE_TAP;
  }
  else return 5; //magic number. At some point this method will expand to work for more presses
}

//instanalize an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};

void x_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: 
      register_code(KC_LGUI); 
      break;
    case SINGLE_HOLD: 
      register_code(KC_LGUI); 
      break;
    case DOUBLE_TAP: 
      layer_on(1); 
      break;
    case TRIPLE_TAP: 
      layer_invert(2); 
      break;
  }
}

void x_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: 
      unregister_code(KC_LGUI); 
      break;
    case SINGLE_HOLD: 
      unregister_code(KC_LGUI); 
      break;
    case DOUBLE_TAP: 
      layer_off(1); 
      break;
    case TRIPLE_TAP: 
      break;
  }
  xtap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [X_GUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,x_finished, x_reset)
};

uint32_t layer_state_set_user(uint32_t state) {
  switch(biton32(state)) {
  case _L1:
    led_off();
    rgb_on();
    break;
  case _L2:
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