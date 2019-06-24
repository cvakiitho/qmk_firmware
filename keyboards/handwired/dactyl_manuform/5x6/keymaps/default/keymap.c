/* A standard layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _COMBO 3

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

//Tap Dance Declarations
enum {
  CT_FLSH = 0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 
 /* Base (qwerty)
 * ,----------------------------------------,                        ,----------------------------------------,
 * |   ~  |  !  |   @  |   #  |   $  |   %  |                        |   ^  |   &  |   *  |   (  |   )  |     |
 * |   `  |  1  |   2  |   3  |   4  |   5  |                        |   6  |   7  |   8  |   9  |   0  | BS  |
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * | TAB  |  q  |   w  |   e  |   r  |   t  |                        |   y  |   u  |   i  |   o  |   p  | \|  |
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * | ESC |  a  |   s  |   d  |   f  |   g   |                        |   h  |   j  |   k  |   l  |  ;:  | '"  |
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * |SHIFT |  z  |   x  |   c  |   v  |   b  |                        |   n  |   m  |   ,  |   .  |  /?  |SHIFT|
 * '------+-----+------+------+------+------'------+          '------+------+------+------+------+------+-----'
 *              | CTRL | OPT  | CMD | SPACE | RAISE|          | LOWER| SPACE|ENTER |  __  |   =  |
 *              '------+------'------+------'------+          '------'------+------'------+------'
 */

  [_QWERTY] = LAYOUT_5x6(
     KC_GRV , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSLS,
     KC_ESC , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
     KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
                     KC_LCTL,KC_LALT,KC_LCMD, KC_SPC, RAISE,            LOWER,KC_SPC, KC_ENT,KC_MINS,KC_EQL 
  ),

/*  Layer: LOWER (right opt) columns- num lock 
 * ,----------------------------------------,                        ,----------------------------------------,
 * |   ~  |  !  |   @  |   #  |   $  |   %  |                        |   ^  |   &  |   *  |   (  |   )  | DEL |
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * |      |     |      |      |      |  [   |                        |  ]   |      |      |      |      | +   |
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * |      | HOME| PGUP | PGDN |  END |  (   |                        |  <-  |   v  |   ^  |   -> |      | |   |
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * |      |     |      |      |      |      |                        |     |      |       |      |      | _   |
 * '------+-----+------+------+------+------'------+          '------+------+------+------+------+------+-----'
 *              |      |      |      |      |      |          |      |      |      |      |     | 
 *              '------+------'------+------'------+          '------'------+------'------+------'
 */
  [_LOWER] = LAYOUT_5x6(

     KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
     _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC,_______,_______,_______,_______,KC_PLUS,
     _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                        KC_LEFT,KC_DOWN, KC_UP ,KC_RGHT,_______,KC_PIPE, 
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,KC_UNDS,
                     _______,_______,_______,_______,_______,        _______,_______,_______,_______,_______

  ),

/* Layer: RAISE (left opt) function + navigation
 * ,----------------------------------------,                        ,----------------------------------------,
 * |  F12 |  F1 |  F2  |  F3  |  F4  |  F5  |                        |  F6  |  F7  |  F8  |  F9  |  F10 | F11 |
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * | TAB  |     |      |      | FLASH|  [   |                        |  ]   |      | NLOCK| INS  |SCRLCK| mute|
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * |      |     |  <<  | ()>  |  >>  |      |                        |  <-  |   v  |   ^  |   -> |      | vol+|
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * | CTRL |     |      |      |      |      |                        |     |      |       |      |    - | vol-|
 * '------+-----+------+------+------+------'------+          '------+------+------+------+------+------+-----'
 *              |      |      |      |      |      |          |      |      |      |      |     | 
 *              '------+------'------+------'------+          '------'------+------'------+------'
 */
  [_RAISE] = LAYOUT_5x6(
       KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
       _______,_______,_______,_______,TD(CT_FLSH),KC_LBRC,                        KC_RBRC,_______,KC_NLCK,KC_INS ,KC_SLCK,KC_MUTE,
       _______,_______,KC_MPRV,KC_MPLY,KC_MNXT,_______,                        KC_LEFT,KC_DOWN, KC_UP ,KC_RGHT,_______,KC_VOLU, 
       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,KC_VOLD,
               _______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______
  ),


/* Layer: COMBO - special keys
 * ,----------------------------------------,                        ,----------------------------------------,
 * |  F12 |  F1 |  F2  |  F3  |  F4  |  F5  |                        |  F6  |  F7  |  F8  |  F9  |  F10 | F11 |
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * |      |     |      |      |      | RESET|                        | RESET|      | NLOCK| INS  |SCRLCK| mute|
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * |      |     |      |      |      |      |                        |     |      |       |      |      | vol+|
 * |------+-----+------+------+------+------|                        |------+------+------+------+------+-----|
 * |      |     |      |      |      |      |                        |     |      |       |      |      | vol-|
 * '------+-----+------+------+------+------'------+          '------+------+------+------+------+------+-----'
 *              |      |      |      |      |      |          |      |      |      |      |     | 
 *              '------+------'------+------'------+          '------'------+------'------+------'
 */
  [_COMBO] = LAYOUT_5x6(
       KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
       _______,_______,_______,_______,_______, RESET,                         RESET,_______,KC_NLCK,KC_INS ,KC_SLCK,KC_MUTE,
       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,KC_VOLU,
       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,KC_VOLD,
               _______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _COMBO);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _COMBO);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _COMBO);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _COMBO);
      }
      return false;
      break;
    }
  return true;
};


// on the fourth tap, set the keyboard on flash state
void dance_flsh_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 4) {
    reset_keyboard();
  }
}

//All tap dance functions would go here. Only showing this one.
qk_tap_dance_action_t tap_dance_actions[] = {
  [CT_FLSH] = ACTION_TAP_DANCE_FN(dance_flsh_reset)
};