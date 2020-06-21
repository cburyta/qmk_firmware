/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _NAV,
  _ADJUST,
  _BLANK
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// Dashes (macOS)
#define KC_NDSH LALT(KC_MINS)
#define KC_MDSH S(LALT(KC_MINS))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *      ,-----------------------------------------------------------------------------------.
 *      | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 *      |------+------+------+------+------+------+------+------+------+------+------+------|
 * CTRL | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | ENT  | CTRL
 *      |------+------+------+------+------+------+------+------+------+------+------+------|
 *   (  | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |  )
 *      |------+------+------+------+------+------+------+------+------+------+------+------|
 *   [  | Brite| Hypr | Alt  | GUI  |Lower | Bksp |Space |Raise | GUI  | Alt  | Hypr |Right |  ]
 *      `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,               KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,               KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOTE,
    MT(MOD_LCTL, KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,               KC_J,    KC_K,    KC_L,    KC_SCLN, MT(MOD_RCTL, KC_ENT),
    KC_LSPO,              KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,               KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
    MT(BACKLIT, KC_LBRC), KC_HYPR, KC_LALT, KC_LGUI, LOWER,   KC_BSPC, LT(_NAV, KC_SPC),   RAISE,   KC_RGUI, KC_RALT, KC_HYPR, MT(BACKLIT, KC_RBRC)
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  ~   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  #   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  1   |   2  |  3   |  4   |  5   |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  -   |  =   |  `   |  \   |  :   |   –  |   —  |   ,  |   .  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |******|      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_HASH,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
    _______, KC_MINS, KC_EQL,  KC_GRV,  KC_BSLS, KC_COLN,  KC_NDSH,  KC_MDSH,  KC_COMM,  KC_DOT,   KC_SLSH,  _______,
    _______, _______, _______, _______, _______, _______,  _______,  _______,  KC_MNXT,  KC_VOLD,  KC_VOLU,  KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  | F11  | F12  | F13  | F14  | F15  | F16  | F17  | F18  | F19  | F20  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  !   |  @   |  #   |  $   |  $   |  ^   |   &  |   *  |   {  |   }  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  _   |  +   |  ~   |  |   |  :   |  –   |   —  |   ,  |   .  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |  Del |  Del |******|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,    KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_HASH,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, _______,
    _______, KC_UNDS, KC_PLUS, KC_TILD, KC_PIPE, KC_COLN,   KC_NDSH, KC_MDSH, KC_COMM, KC_DOT,  KC_SLSH, _______,
    _______, _______, _______, _______, _______, KC_DEL,    KC_DEL,  _______, _______, _______, _______, _______
),

/* Nav
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Home | PGUP | PGDN | End  |   L  |   D  |   U  |  R   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |Cmd+L |Cmd+D |Cmd+U |Cmd+R | Alt+L| Alt+D| Alt+U| Alt+R|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_planck_grid(
    _______, _______, _______,       _______,     _______,       _______,       _______,       _______,       _______,     _______,       _______, _______,
    _______, _______, KC_HOME,       KC_PGUP,     KC_PGDN,       KC_END,        KC_LEFT,       KC_DOWN,       KC_UP,       KC_RGHT,       _______, _______,
    _______, _______, LGUI(KC_LEFT), LGUI(KC_UP), LGUI(KC_DOWN), LGUI(KC_RGHT), LALT(KC_LEFT), LALT(KC_DOWN), LALT(KC_UP), LALT(KC_RGHT), _______, _______,
    _______, _______, _______,       _______,     _______,       _______,       _______,       _______,       _______,     _______,       _______, _______
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______,  _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* Utility, for testing and debugging.
 */
[_BLANK] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
