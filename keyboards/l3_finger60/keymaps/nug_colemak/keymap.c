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

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD,
  DOUBLE_TAP,
  DOUBLE_HOLD,
  TRIPLE_TAP,
};

//Tap dance enums
enum {
  X_CAPS = 0,
  Y_RALT,
  Z_TEST,
};

int cur_dance (qk_tap_dance_state_t *state);

//for the x tap dance. Put it here so it can be used in any keymap
void x_finished (qk_tap_dance_state_t *state, void *user_data);
void x_reset (qk_tap_dance_state_t *state, void *user_data);
void y_finished (qk_tap_dance_state_t *state, void *user_data);
void y_reset (qk_tap_dance_state_t *state, void *user_data);

/* 
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ESC│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ ( │ ) │ BKSPC │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │ TAB │ Q │ W │ F │ P │ G │ J │ L │ U │ Y │ ; │ [ │ ] │  \  │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │ FUNC │ A │ R │ S │ T │ D │ H │ N │ E │ I │ O │ ' │ ENTER  │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
 * │ SHIFT  │ Z │ X │ C │ V │ B │ K │ M │ , │ . │ / │SHIFT │FN │
 * ├─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬───┬─┴───┤
 * │CTRL │GUI│ ALT │         SPACE (7u)        │ ALT │GUI│CTRL │
 * └─────┴───┴─────┴───────────────────────────┴─────┴───┴─────┘
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_L0] = KEYMAP(
    KC_GESC,    KC_1,    KC_2,    KC_3,    KC_4,   KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,  KC_EQL,   KC_NO, KC_BSPC,
     KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,   KC_G,    KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_LBRC, KC_RBRC, KC_BSLS,         
 TD(X_CAPS),    KC_A,    KC_R,    KC_S,    KC_T,   KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,  KC_QUOT,   KC_NO,  KC_ENT,         
    KC_LSFT,   KC_NO,    KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    KC_K,    KC_M, KC_COMM,  KC_DOT,  KC_SLSH, LT_L1DE, RSFT_UA,
    KC_LCTL, KC_LGUI, KC_LALT,    KC_R, LT_L1SP,   KC_O, RALT_LA,   KC_NO,   KC_NO, RGUI_DA, RCTL_RA),

  [_L1] = KEYMAP(
     KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_F11,  KC_F12,  ______, KC_DEL,
     ______,  ______,   KC_UP,  ______,  ______, ______,  ______,  ______,   KC_UP,  ______,  ______,   ______,  ______,  KC_INS,        
     ______, KC_LEFT, KC_DOWN, KC_RGHT,  ______, ______,  ______, KC_LEFT, KC_DOWN, KC_RGHT,  ______,   ______,  ______,  ______,        
     ______,  ______,  ______,  ______,  ______, ______,  ______,  ______,  ______,  ______,  ______,   ______,  ______, KC_PGUP,
     ______,  ______,  ______,  ______,  ______, ______, KC_HOME,  ______,  ______, KC_PGDN,  KC_END),
};

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    if (state->interrupted || !state->pressed)  return DOUBLE_TAP;
    else return DOUBLE_HOLD;
  }
  else if (state->count == 3) {
    return TRIPLE_TAP;
  }
  else return 6; //magic number. At some point this method will expand to work for more presses
}

//instanalize an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};

//instanalize an instance of 'tap' for the 'y' tap dance.
static tap ytap_state = {
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
    case DOUBLE_TAP: /*gaming layer*/
      layer_invert(2); 
      break;
    case TRIPLE_TAP: /*reset layer*/
      layer_invert(3); 
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
    case TRIPLE_TAP: 
      break;
  }
  xtap_state.state = 0;
}

void y_finished (qk_tap_dance_state_t *state, void *user_data) {
  ytap_state.state = cur_dance(state);
  switch (ytap_state.state) {
    case SINGLE_TAP: 
      register_code(KC_RCTL);
      break;
    case SINGLE_HOLD: 
      register_code(KC_RCTL);
      break;
    case DOUBLE_TAP:
      register_code(KC_RALT);
      break;
    case DOUBLE_HOLD: 
      register_code(KC_RALT);
      break;
  }
}

void y_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (ytap_state.state) {
    case SINGLE_TAP:
      unregister_code(KC_RCTL);
      break;
    case SINGLE_HOLD: 
      unregister_code(KC_RCTL);
      break;
    case DOUBLE_TAP: 
      unregister_code(KC_RALT);
      break;
    case DOUBLE_HOLD: 
      unregister_code(KC_RALT);
      break;
  }
  ytap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [X_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset),
  [Y_RALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, y_finished, y_reset),
  [Z_TEST] = ACTION_TAP_DANCE_DOUBLE(KC_RCTL, KC_RALT),
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