/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// Original Key
#define MT_SS       MT(MOD_LSFT, KC_SPACE)

// if you forget key code, show https://docs.qmk.fm/#/keycodes
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    QK_GESC  , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_EQUAL ,
    KC_DEL   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_MINS  ,
    KC_TAB   , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_QUOTE ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_BSLS  ,              KC_NUHS, KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RSFT  ,
    KC_LCTL  , KC_LCTL  , KC_LALT  , KC_LGUI,LT(1,KC_LNG2),MT_SS    ,LT(3,KC_LNG1),           KC_BSPC,LT(2,KC_ENT)                               , KC_RALT  , RALT(KC_SPC)
  ),

  [1] = LAYOUT(
    _______  , S(KC_1)  , S(KC_2)  , S(KC_3)  , S(KC_4)  , S(KC_5)  ,                                  S(KC_6)  , S(KC_7)  , S(KC_8)  , S(KC_9)  , S(KC_0)  ,S(KC_EQUAL),
    S(KC_DEL), S(KC_Q)  , S(KC_W)  , S(KC_E)  , S(KC_R)  , S(KC_T)  ,                                  S(KC_Y)  , S(KC_U)  , S(KC_I)  , S(KC_O)  , S(KC_P)  ,S(KC_MINS),
    S(KC_TAB), S(KC_A)  , S(KC_S)  , S(KC_D)  , S(KC_F)  , S(KC_G)  ,                                  S(KC_H)  , S(KC_J)  , S(KC_K)  , S(KC_L)  ,S(KC_SCLN),S(KC_QUOTE)  ,
    _______  , S(KC_Z)  , S(KC_X)  , S(KC_C)  , S(KC_V)  , S(KC_B)  ,S(KC_BSLS),           S(KC_NUHS), S(KC_N)  , S(KC_M)  ,S(KC_COMM), S(KC_DOT),S(KC_SLSH),S(KC_RSFT),
    _______  ,S(KC_LCTL),S(KC_LALT),S(KC_LGUI), _______  , _______  , _______  ,            _______  , _______                                   , S(KC_RALT), KC_PSCR
  ),

  [2] = LAYOUT(
    _______  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , DF(0)   ,
    _______  , _______  , KC_7     , KC_8     , KC_9     , XXXXXXX  ,                                  KC_PGUP  , KC_DOWN  , XXXXXXX  , KC_F11   , KC_F12   , DF(2)   ,
    _______  , _______  , KC_4     , KC_5     , KC_6     , XXXXXXX  ,                                  KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , XXXXXXX  , XXXXXXX ,
    _______  , _______  , KC_1     , KC_2     , KC_3     , KC_LBRC  , S(KC_9)  ,            S(KC_0)  , KC_RBRC  , KC_BTN1  , KC_BTN1  , KC_BTN2  , KC_BTN3  , SCRL_MO,
    _______  , _______  , KC_0     , KC_DOT   , _______  , _______  , _______  ,             KC_DEL  , _______                                   , _______  , KC_PSCR
  ),

  [3] = LAYOUT(
    RGB_TOG  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KBC_RST  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , XXXXXXX  , XXXXXXX  ,                                  CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE , KBC_RST  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , XXXXXXX  , XXXXXXX  ,                                  XXXXXXX  , SCRL_DVI , SCRL_DVD , XXXXXXX  , XXXXXXX  , XXXXXXX  ,
    _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  , SCRL_MO  , SCRL_TO  , XXXXXXX  ,            XXXXXXX  , XXXXXXX  , KC_BTN1  , KC_BTN1  , KC_BTN2  , KC_BTN3  , XXXXXXX  ,
    _______  , _______  , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , _______  ,            _______  , KC_BSPC                                   , _______  , KC_PSCR
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
