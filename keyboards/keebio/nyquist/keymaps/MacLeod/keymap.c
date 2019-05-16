#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

#define MY_AT RALT(KC_2)
#define MY_MICR RALT(KC_M)
#define MY_EURO RALT(KC_4)
#define MY_APO RALT(KC_GRAVE) // `
#define CLEAN LCTL(LSFT(KC_I))
#define BUILD LCTL(LSFT(KC_N))
#define MY_BSLS RALT(KC_MINS)
#define MY_PIPE RALT(NO_AE)
#define RTABS LCTL(KC_PGDOWN)
#define LTABS LCTL(KC_PGUP)
#define CLTABS LCTL(KC_W)
#define NEWTABS LCTL(KC_T)
#define RETABS LCTL(S(KC_T))

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _NUMPAD 3
#define _ADJUST 16
#define _MOUSE 18
#define _GAME 36

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  NUMPAD,
  ADJUST,
  MOUSE,
  GAME,
  GAME_EXIT,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   §  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  Å   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ö  |  Ä   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  |Mouse |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | GUI  | Alt  |Lower |Space |Enter |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_GRV,              KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  LT(_NUMPAD,KC_ESC),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    NO_AA, \
  MT(MOD_LCTL,KC_TAB), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    NO_OSLH, NO_AE, \
  KC_LSFT,             KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  NO_MINS, MOUSE , \
  ADJUST,              KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),
[_GAME] = LAYOUT( \
  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    NO_AA, \
  KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    NO_OSLH, NO_AE, \
  KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  NO_MINS, GAME_EXIT , \
  ADJUST,    KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   "  |   #  |   ¤  |   %  |   &  |   /  |   (  |   )  |   =  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ½  |   %  |   !  |   €  |   $  |   *  |   \  |   ?  |   (  |   )  |   +  |  =   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |   ¨  |   ^  |   £  |   ^  |   ;  |   '  |   "  |   {  |   }  |   <  |  >   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |   µ  |   ¤  |   ;  |   :  |   #  |   @  |   [  |   ]  |   &  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  NO_TILD, KC_EXLM, NO_QUO2, KC_HASH, KC_DLR,   KC_PERC, KC_CIRC, NO_SLSH, NO_LPRN, NO_RPRN, NO_EQL , KC_BSPC, \
  KC_DEL,  KC_PERC, KC_EXLM, NO_EURO, NO_DLR,   NO_ASTR, NO_BSLS, NO_QUES, NO_LPRN, NO_RPRN, NO_PLUS, NO_EQL, \
  KC_TILD, NO_QUOT, NO_CIRC, NO_PND,  NO_CIRC,  NO_SCLN, KC_NUHS, NO_QUO2, NO_LCBR, NO_RCBR, NO_LESS, NO_GRTR, \
  _______, _______, NO_MU,   NO_BULT, NO_SCLN,  NO_COLN, KC_HASH, NO_AT,   NO_LBRC, NO_RBRC, NO_AMPR, NO_PIPE, \
  GAME,    _______, _______, _______, _______,  _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F11 |  F12 |      |      |      |      |      |      |      |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F6  |  F7  |  F8  |  F9  |  F10 |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,  KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_BSPC, \
  KC_DEL,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, KC_DEL, \
  XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, _______, _______, _______, _______, \
  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, _______, _______, _______, _______, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|RGB Tg|RGB Md|Hue Up|Hue Dn|Sat Up|Sat Dn|Val Up|Val Dn|      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty| Ins  | Home | PgUp | PSCR |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | End  | PgDo |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Home | PgUp | PgDo | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_F11,    KC_F12, \
  _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI,   _______,   KC_DEL, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  KC_INS,  KC_HOME,   KC_PGUP,   KC_PSCREEN, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_END,    KC_PGDOWN, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDOWN, KC_PGUP, KC_END \
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | ClTa | LTab | RTab | NewTa|      |   7  |   8  |   9  |   +  |  =   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      | ReTa |      |   4  |   5  |   6  |   -  |  *   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   0  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] =  LAYOUT( \
  XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,   KC_7,     KC_8, KC_9,    KC_0,    _______, \
  _______, XXXXXXX, CLTABS,  LTABS,   RTABS,   NEWTABS, XXXXXXX, KC_7,    KC_8, KC_9,    NO_PLUS, NO_EQL,  \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RETABS,  XXXXXXX, KC_4,    KC_5, KC_6,    NO_MINS, NO_ASTR, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_1,    KC_2, KC_3,    NO_BSLS, _______, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, KC_0, XXXXXXX, XXXXXXX, XXXXXXX \
),

/* Mouse (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |M.acl1|M.acl2|M.acl3|      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |M.Btn1| M.Up |M.Btn2| WheUp|      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | M.Le | M.Do | M.Ri | WheDo|      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] =  LAYOUT( \
  XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
)

};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case NUMPAD:
      if (record->event.pressed) {
        layer_on(_NUMPAD);
      } else {
        layer_off(_NUMPAD);
      }
      return false;
      break;
    case MOUSE:
      if (record->event.pressed) {
        layer_on(_MOUSE);
      } else {
        layer_off(_MOUSE);
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        layer_on(_GAME);
      //} else {
      //  layer_off(_MOUSE);
      }
      return false;
      break;
    case GAME_EXIT:
      if (record->event.pressed) {
        layer_on(_QWERTY);
      //} else {
      //  layer_off(_MOUSE);
      }
      return false;
      break;
  }
  return true;
}
