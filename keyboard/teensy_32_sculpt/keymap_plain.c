/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

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

#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"

// Microsoft Sculpt keymap definition macro
#define KEYMAP( \
         K01,      K03, K04, K05,      K06, K07, K08, K09, K0A, K0B, K0C,                     \
         K12,      K14, K15, K16,      K17, K18, K19, K1A, K1B, K1C, K1D,      K1F,           \
         K23,      K25, K26, K27,      K28,      K2A, K2B, K2C, K2D, K2E,      K30,           \
         K34,      K36, K37, K38,      K39, K3A, K3B, K3C, K3D, K3E, K3F,      K41,           \
                   K46, K47, K48, K49,      K4B, K4C, K4D, K4E, K4F, K50,           K53,      \
         K56, K57, K58, K59, K5A,      K5B,      K5D, K5E, K5F, K60, K61, K62,                \
    K66, K67,      K69, K6A,                K6D, K6E, K6F, K70,                          K76, \
         K78,      K7A, K7B, K7C,      K7D, K7E, K7F, K80, K81, K82, K83,      K85            \
) { \
    { KC_NO,    KC_##K01, KC_NO,    KC_##K03, KC_##K04, KC_##K05, KC_NO,    KC_##K06, KC_##K07, KC_##K08, KC_##K09, KC_##K0A, KC_##K0B, KC_##K0C, KC_NO,    KC_NO,    KC_NO,    KC_NO   }, \
    { KC_NO,    KC_##K12, KC_NO,    KC_##K14, KC_##K15, KC_##K16, KC_NO,    KC_##K17, KC_##K18, KC_##K19, KC_##K1A, KC_##K1B, KC_##K1C, KC_##K1D, KC_NO,    KC_##K1F, KC_NO,    KC_NO   }, \
    { KC_NO,    KC_##K23, KC_NO,    KC_##K25, KC_##K26, KC_##K27, KC_NO,    KC_##K28, KC_NO,    KC_##K2A, KC_##K2B, KC_##K2C, KC_##K2D, KC_##K2E, KC_NO,    KC_##K30, KC_NO,    KC_NO   }, \
    { KC_NO,    KC_##K34, KC_NO,    KC_##K36, KC_##K37, KC_##K38, KC_NO,    KC_##K39, KC_##K3A, KC_##K3B, KC_##K3C, KC_##K3D, KC_##K3E, KC_##K3F, KC_NO,    KC_##K41, KC_NO,    KC_NO   }, \
    { KC_NO,    KC_NO,    KC_NO,    KC_##K46, KC_##K47, KC_##K48, KC_##K49, KC_NO,    KC_##K4B, KC_##K4C, KC_##K4D, KC_##K4E, KC_##K4F, KC_##K50, KC_NO,    KC_NO,    KC_##K53, KC_NO   }, \
    { KC_NO,    KC_##K56, KC_##K57, KC_##K58, KC_##K59, KC_##K5A, KC_NO,    KC_##K5B, KC_NO,    KC_##K5D, KC_##K5E, KC_##K5F, KC_##K60, KC_##K61, KC_##K62, KC_NO,    KC_NO,    KC_NO   }, \
    { KC_##K66, KC_##K67, KC_NO,    KC_##K69, KC_##K6A, KC_NO,    KC_NO,    KC_NO,    KC_##K6D, KC_##K6E, KC_##K6F, KC_##K70, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_##K76 }, \
    { KC_NO,    KC_##K78, KC_NO,    KC_##K7A, KC_##K7B, KC_##K7C, KC_NO,    KC_##K7D, KC_##K7E, KC_##K7F, KC_##K80, KC_##K81, KC_##K82, KC_##K83, KC_NO,    KC_##K85, KC_NO,    KC_NO   }  \
}

static const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwertz */
	KEYMAP(
        PAUS, DEL, 0, 9, 8, BSPC, 7, TAB, Q, 2, 1, \
        PGUP, F12,LBRC,MINS,RBRC, INS, Y, F5, F3, W, 4, F6, \
        HOME, CALC, P, O, I, U, R, E, CAPS, 3, T, \
        SLCK, ENT, SCLN, L, K, BSLS, J, F, D, NONUS_BSLASH, A, LGUI, \
        FN1, SLSH, QUOT, RALT, LEFT, H, G, F4, S, ESC, LALT, \
        END, RSFT, PGDN, NONUS_HASH, DOT, COMM, M, V, C, X, Z, LSFT, \
        RCTL, RGHT, UP, DOWN, SPC, N, B, SPC, LCTL, \
        PSCR, F11, EQL, F9, F8, F10, F7, 5, F2, F1, GRV, 6)
};

static const action_t fn_actions[] = {
};

/* translates key to keycode */
uint8_t keymap_key_to_keycode(uint8_t layer, keypos_t key)
{
    return keymaps[(layer)][(key.row)][(key.col)];
}

/* translates Fn keycode to action */
action_t keymap_fn_to_action(uint8_t keycode)
{
    return fn_actions[FN_INDEX(keycode)];
}
