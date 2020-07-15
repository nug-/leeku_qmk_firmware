// Default layer for L3 Finger65 (TX65)
#include QMK_KEYBOARD_H

#define LT_L1SP LT(_L1, KC_SPC) /* SPACE on tap, LAYER ONE on hold */

enum layers {
  _L0 = 0,
  _L1,
  _L2, /* Gaming layer */
  _L3, /* RESET layer */
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD,
  DOUBLE_TAP,
};

//Tap dance enums
enum {
  TCAP = 0,
};

int cur_dance (qk_tap_dance_state_t *state);

//for the x tap dance. Put it here so it can be used in any keymap
void x_finished (qk_tap_dance_state_t *state, void *user_data);
void x_reset (qk_tap_dance_state_t *state, void *user_data);

/* 
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │ESC│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ ( │ ) │ BKSPC │HOM│
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │ TAB │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │PGU│
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
 * │ FUNC │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ ENTER  │PGD│
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 * │ SHIFT  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │SHIFT │UP │END│ 
 * ├─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴──┬┴───┴┬──┴──┬───┼───┼───┤
 * │CTRL │GUI│ ALT │      SPACE (6u)       │ ALT │CTRL │LFT│DWN│RGT│
 * └─────┴───┴─────┴───────────────────────┴─────┴─────┴───┴───┴───┘
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_L0] = KEYMAP(
    KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_NO,   KC_BSPC, KC_HOME,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
    TD(TCAP), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NO,   KC_ENT,           KC_PGDN,
    KC_LSFT,  KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_END,
    KC_LCTL,  KC_LGUI, KC_LALT, KC_NO,                     LT_L1SP, KC_NO,   KC_RALT, KC_RCTL,                            KC_LEFT, KC_DOWN, KC_RGHT),
  
  [_L1] = KEYMAP(
    KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_DEL,  KC_DEL,
    _______,  _______, KC_UP,   _______, _______, _______, _______, _______, KC_PGUP, _______, _______, _______, _______, KC_INS,           KC_INS,
    _______,  KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_HOME, KC_PGDN, KC_END,  _______, _______, KC_NO,   _______,          KC_PSCR,
    _______,  KC_NO,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_PGUP, KC_DEL,
    _______,  _______, _______, KC_NO,                     _______, KC_NO,   _______, _______,                            KC_HOME, KC_PGDN, KC_END),

  [_L2] = KEYMAP(
    KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_NO,   KC_BSPC, KC_HOME,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
    _______,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NO,   KC_ENT,           KC_PGDN,
    KC_LSFT,  KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_END,
    KC_LCTL,  KC_NO,   KC_LALT, KC_NO,                     KC_SPC,  KC_NO,   KC_RALT, KC_RCTL,                            KC_LEFT, KC_DOWN, KC_RGHT),

  [_L3] = KEYMAP(
    RESET,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,
    _______,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,
    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,
    KC_NO,    KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO),
};

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    return DOUBLE_TAP;
  }
  else return 4; //magic number. At some point this method will expand to work for more presses
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
      layer_on(1); 
      break;
    case SINGLE_HOLD: 
      layer_on(1); 
      break;
    case DOUBLE_TAP: 
      layer_invert(2); 
      break;
  }
}

void x_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: 
      layer_off(1); 
      break;
    case SINGLE_HOLD: 
      layer_off(1); 
      break;
    case DOUBLE_TAP: 
      break;
  }
  xtap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TCAP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset)
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