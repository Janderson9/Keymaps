#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _Mac 0
#define _Windows 1
#define _FN1 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

// Tap Dance Definitions
enum tapdance {
    TD_HOME_END = 0,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Home, twice for PageUp
    [TD_HOME_END] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_END),
    // Tap once for End, twice for PageDown
    //[TD_END] = ACTION_TAP_DANCE_DOUBLE(KC_END, KC_PGDOWN)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
	
	/* all parenthesis are for held presses
	 * 0: _Mac
     * ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐      ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬───────────────────┬─────────┐
     * │ ESC(FN1)│ KC_1    │ KC_2    │ KC_3    │ KC_4    │ KC_5    │ KC_6    │      │ KC_7    │ KC_8    │ KC_9    │ KC_0    │ KC_MINS │ KC_EQL  │    KC_BSPC (2)    │ KC_DEL  │
     * ├─────────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┘ ┌────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬──────────────┼─────────┤
     * │   KC_TAB     │ KC_Q    │ KC_W    │ KC_E    │ KC_R    │ KC_T    │      │ KC_Y    │ KC_U    │ KC_I    │ KC_O    │ KC_P    │ KC_LBRC │ KC_RBRC │   KC_BSLS    │ BRT UP  │
     * ├──────────────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┐    └──┬──────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴──────────────┼─────────┤
     * │    KC_LGUI     │ KC_A    │ KC_S    │ KC_D    │ KC_F    │ KC_G    │       │KC_H    │ KC_J    │ KC_K    │ KC_L    │ KC_SCLN │ KC_QUOT │       KC_ENT         │ Home/End│
     * ├────────────────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┐  └──┬─────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────────────┬─────────┼─────────┤
     * │ KC_LSFT (Caps Lock) │ KC_Z    │ KC_X    │ KC_C    │ KC_V    │ KC_B    │     │  KC_N    │ KC_M    │ KC_COMM │ KC_DOT  │ KC_SLSH │     KC_RSFT     │ KC_UP   │ BRT DWN │
     * ├────────────┬────────┴───┬─────┴─────┬───┴────────┬┴─────────┴─────────┤     ├──────────┴─────────┴───────┬─┴───────┬─┴───────┬─┴───────┬─────────┼─────────┼─────────┤
     * │    _FN1    │   KC_LCTL  │   KC_LALT │   KC_LGUI  │   KC_SPC (2.25u)   │     │        KC_SPC (2.75u)      │ KC_RGUI │  COPY   │  PASTE  │ KC_LEFT │ KC_DOWN │ KC_RGHT │
     * └────────────┴────────────┴───────────┴────────────┴────────────────────┘     └────────────────────────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
     */
	 
	 
  [_Mac] = LAYOUT_65(
    LT(_FN1, KC_GESC), KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  _______,  KC_BSPC, KC_DEL,\
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_BRIGHTNESS_UP, \
    KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, TD(TD_HOME_END),\
    MT(MOD_LSFT, KC_CAPSLOCK), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP, KC_BRIGHTNESS_DOWN,\
    MO(_FN1), KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,          KC_SPC , _______, KC_RGUI, RGUI(KC_C),RGUI(KC_V), KC_LEFT, KC_DOWN, KC_RGHT
  ),
  
	/* 0: _Windows
     * ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐      ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬───────────────────┬─────────┐
     * │ ESC(FN1)│ KC_1    │ KC_2    │ KC_3    │ KC_4    │ KC_5    │ KC_6    │      │ KC_7    │ KC_8    │ KC_9    │ KC_0    │ KC_MINS │ KC_EQL  │    KC_BSPC (2)    │ KC_DEL  │
     * ├─────────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┘ ┌────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬──────────────┼─────────┤
     * │   KC_TAB     │ KC_Q    │ KC_W    │ KC_E    │ KC_R    │ KC_T    │      │ KC_Y    │ KC_U    │ KC_I    │ KC_O    │ KC_P    │ KC_LBRC │ KC_RBRC │   KC_BSLS    │ SCRL UP │
     * ├──────────────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┐    └──┬──────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴──────────────┼─────────┤
     * │    KC_LCTL     │ KC_A    │ KC_S    │ KC_D    │ KC_F    │ KC_G    │       │KC_H    │ KC_J    │ KC_K    │ KC_L    │ KC_SCLN │ KC_QUOT │       KC_ENT         │ Home/End│
     * ├────────────────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┐  └──┬─────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────────────┬─────────┼─────────┤
     * │ KC_LSFT (Caps Lock) │ KC_Z    │ KC_X    │ KC_C    │ KC_V    │ KC_B    │     │  KC_N    │ KC_M    │ KC_COMM │ KC_DOT  │ KC_SLSH │     KC_RSFT     │ KC_UP   │SCRL DOWN│
     * ├────────────┬────────┴───┬─────┴─────┬───┴────────┬┴─────────┴─────────┤     ├──────────┴─────────┴───────┬─┴───────┬─┴───────┬─┴───────┬─────────┼─────────┼─────────┤
     * │    _FN1    │   KC_LCTL  │  KC_LALT  │   KC_LGUI  │    KC_SPC (2.25u)  │     │        KC_SPC (2.75u)      │ SHFT+TAB│  COPY   │  PASTE  │ KC_LEFT │ KC_DOWN │ KC_RGHT │
     * └────────────┴────────────┴───────────┴────────────┴────────────────────┘     └────────────────────────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
     */
  
  [_Windows] = LAYOUT_65(
    LT(_FN1, KC_GESC), KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  _______,  KC_BSPC, KC_DEL,\
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_MS_WH_UP,\
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, TD(TD_HOME_END),\
    MT(MOD_LSFT, KC_CAPSLOCK), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP, KC_MS_WH_DOWN,\
    MO(_FN1), KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,          KC_SPC , _______, LSFT(KC_TAB), RCTL(KC_C),RCTL(KC_V), KC_LEFT, KC_DOWN, KC_RGHT
  ),

/* 0: _FN1
     * ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐      ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬───────────────────┬─────────┐
     * │ KC_TILD │ KC_F1   │ KC_F2   │ KC_F3   │ KC_F4   │ KC_F5   │ KC_F6   │      │ KC_F7   │ KC_F8   │ KC_F9   │ KC_F10  │ KC_F11  │ KC_F12  │    KC_BSPC (2)    │  MUTE   │
     * ├─────────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┘ ┌────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬──────────────┼─────────┤
     * │   _______    │ _______ │  KC_UP  │ _______ │ _______ │ _______ │      │ _______ │ _______ │ _______ │ _______ │ _______ │ _______ │ _______ │   _______    │  VOL UP │
     * ├──────────────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┐    └──┬──────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴──────────────┼─────────┤
     * │    _______     │ KC_LEFT │ KC_DOWN │ KC_RIGHT│ _______ │ _______ │       │ ______ │ _______ │ _______ │ _______ │ _______ │ _______ │       _______        │ HOME/END│
     * ├────────────────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┐  └──┬─────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────────────┬─────────┼─────────┤
     * │       _______       │ _______ │ _______ │ _______ │ _______ │ _______ │     │  _______ │ _______ │ _______ │ _______ │ _______ │     KC_RSFT     │ KC_UP   │ VOL DOWN│
     * ├────────────┬────────┴───┬─────┴─────┬───┴────────┬┴─────────┴─────────┤     ├──────────┴─────────┴───────┬─┴───────┬─┴───────┬─┴───────┬─────────┼─────────┼─────────┤
     * │   _______  │ WIN LAYER  │  KC_LALT  │   KC_LGUI  │ SYSTEM WAKE (2.25u)│     │    SYSTEM SLEEP (2.75u)    │ _______ │  REDO   │   UNDO  │ _______ │ _______ │ _______ │
     * └────────────┴────────────┴───────────┴────────────┴────────────────────┘     └────────────────────────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
	 */
	 
	 
  [_FN1] = LAYOUT_65(
    KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  KC_BSPC,  KC_AUDIO_MUTE,\
    _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_AUDIO_VOL_UP,\
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_MPLY,\
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_AUDIO_VOL_DOWN, \
    _______, DF(_Windows), _______, DF(_Mac),  KC_SYSTEM_WAKE,           KC_SYSTEM_SLEEP, _______, _______, RCTL(KC_Y), RCTL(KC_Z), _______, _______, _______
  )
};