    /* Copyright 2018 REPLACE_WITH_YOUR_NAME
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at y our option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *)
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "config.h"

enum CustomLayers {
        _BASE = 0,
        _SYMB,  // symbols
        _FUNC,  // func keys
        _NUMS,  // num keypad on left side
        _NVMD   // media and navigation keys
};

enum CustomKeycodes {
        TWO_OR = SAFE_RANGE,
        L_BRK_SHIFT,
        R_BRK_SHIFT,
        L_PRT_CTRL,
        R_PRL_CLTR,
        L_SQPR_ALT,
        R_SQPR_ALT,
        TWO_AND,
        SG_QUOTE,
        DB_QUOTE,
        W_LS,
        W_LD,
        GO_L,
        W_RS,
        W_RD,
        GO_R
};

int isDefaultLayer = _BASE;
// KEYS SHORTCUTS
//#define OSM_LCTL  OSM(MOD_LCTL)
//#define OSM_LSFT  OSM(MOD_LSFT)
//#define OSM_LALT  OSM(MOD_LALT)
//#define OSM_LCSA  OSM(MOD_LCTL | MOD_LSFT | MOD_LALT)
#define TO_FUNC   TT(_FUNC)
#define TO_SYMB   TT(_SYMB)
#define NVMD_TAB  LT(_NVMD, KC_TAB)
#define NUMS_ESC  LT(_NUMS, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [_BASE] = LAYOUT(
                 NVMD_TAB,      KC_Q,     KC_W,    KC_E,     KC_R,      KC_T,    KC_EQL, /**/ KC_MINS,  KC_Y,       KC_U,     KC_I,     KC_O,     KC_P,    NUMS_ESC, \
                 L_PRT_CTRL,    KC_A,     KC_S,    KC_D,     KC_F,      KC_G,   KC_LBRC, /**/ KC_RBRC,  KC_H,       KC_J,     KC_K,     KC_L,     KC_SCLN, R_PRL_CLTR, \
                 L_BRK_SHIFT,   KC_Z,     KC_X,    KC_C,     KC_V,      KC_B,   KC_LGUI, /**/ KC_APP,   KC_N,       KC_M,     KC_COMM,  KC_DOT,   KC_SLSH, R_BRK_SHIFT, \
                 L_SQPR_ALT, KC_HOME,  KC_PGUP,  KC_END,  TO_FUNC,    KC_SPC,    KC_INS, /**/ KC_BSPC,  KC_ENT,     TO_SYMB,  KC_LEFT,  KC_UP,    KC_RGHT, R_SQPR_ALT,  \
                                       KC_PGDN,                                          /**/                                           KC_DOWN
        ),
        [_SYMB] = LAYOUT(   
                 KC_TAB,        KC_NO, SG_QUOTE,  KC_GRV,     TWO_OR,      KC_PIPE,     KC_NO, /**/ KC_NO,    KC_AMPR,    TWO_AND,  KC_QUOT,  DB_QUOTE, KC_NO,   KC_ESC,   \
                 L_PRT_CTRL,     KC_1,     KC_2,    KC_3,       KC_4,         KC_5,   KC_LPRN, /**/ KC_RPRN,  KC_6,       KC_7,     KC_8,     KC_9,     KC_0,    R_PRL_CLTR, \
                 L_BRK_SHIFT,   KC_NO,    KC_NO,   KC_NO,      KC_NO,        KC_NO,  SG_QUOTE, /**/ KC_NO,    KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,   R_BRK_SHIFT, \
                 L_SQPR_ALT,  KC_TRNS,  KC_TRNS, KC_TRNS,    KC_LALT,      KC_LSFT,     KC_NO, /**/ KC_NO,    KC_NO,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_BSLS, R_SQPR_ALT,  \
                                        KC_TRNS,                                               /**/                                           KC_TRNS
        ),
        [_FUNC] = LAYOUT(
                 KC_TAB,        KC_NO,   KC_F10,  KC_F11,   KC_F12,     KC_NO,    KC_APP, /**/ KC_LGUI,  KC_NO,      KC_F4,      KC_F5,    KC_F6,    KC_NO,     KC_ESC,   \
                 L_PRT_CTRL,    KC_NO,    KC_F7,   KC_F8,    KC_F9,     KC_NO,     KC_NO, /**/ KC_NO,    KC_NO,      KC_F1,      KC_F2,    KC_F3,    KC_NO,     R_PRL_CLTR, \
                 L_BRK_SHIFT,   KC_NO,    KC_NO,   KC_NO,    KC_NO,     KC_NO,     KC_NO, /**/ KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,     R_BRK_SHIFT, \
                 L_SQPR_ALT,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,     KC_NO,     KC_NO, /**/ KC_DEL,   KC_LSFT,  KC_LALT,    KC_TRNS,  KC_TRNS,    KC_TRNS,   R_SQPR_ALT,  \
                                        KC_TRNS,                                          /**/                                           KC_TRNS
        ),
        [_NUMS] = LAYOUT(
                    KC_NO,   KC_NO,     KC_7,    KC_8,     KC_9,   KC_MINS,    KC_NO, /**/ KC_NO,     KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_TRNS,  \
                    KC_NO,   KC_NO,     KC_4,    KC_5,     KC_6,    KC_DOT,    KC_NO, /**/ KC_NO,     KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,    \
                    KC_NO,   KC_NO,     KC_1,    KC_2,     KC_3,   KC_SLSH,    KC_NO, /**/ KC_NO,     KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,    \
                    KC_NO,   KC_NO,     KC_0,   KC_NO,    KC_NO,     KC_NO,    KC_NO, /**/ KC_NO,     KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,    \
                                       KC_NO,                                         /**/                                            KC_NO
        ),
        [_NVMD] = LAYOUT(
                  KC_TRNS,   KC_NO,    KC_NO,   KC_NO,    KC_NO,     KC_NO,    KC_NO, /**/ KC_NO,     KC_NO,      KC_NO,    KC_WH_U,  KC_NO,    KC_NO,   RESET,    \
                    KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO,     KC_NO,    KC_NO, /**/ KC_NO,     KC_NO,      KC_WH_L,  KC_WH_D,  KC_WH_R,  KC_NO,   KC_NO,    \
                  KC_WAKE,   KC_NO,    KC_NO,   KC_NO,    KC_NO,     KC_NO,    KC_NO, /**/ KC_NO,     KC_NO,      KC_NO,    KC_NO,    KC_MUTE,  KC_NO,   KC_NO,    \
                  KC_SLEP,   KC_NO,    KC_NO,   KC_NO,     W_LS,      W_LD,     GO_L, /**/  GO_R,     W_RD,       W_RS,     KC_MPRV,  KC_VOLU,  KC_MNXT, KC_MPLY,  \
                                       KC_NO,                                         /**/                                            KC_VOLD
        )
};

void matrix_init_user(void) {
        rgblight_enable_noeeprom();
}



void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

        static uint16_t my_lCtrl_timer;
        static uint16_t my_rCtrl_timer;
        static uint16_t my_lShift_timer;
        static uint16_t my_rShift_timer;
        static uint16_t my_lAlt_timer;
        static uint16_t my_rAlt_timer;
        
        
        switch (keycode) {
        case NUMS_ESC:  
        case KC_ESC:
                if (record->event.pressed) {
                /*
                        if ((get_oneshot_mods ()) && !has_oneshot_mods_timed_out ()) {
                            clear_oneshot_mods ();
                            
                            return false;
                        }
                 */      
                        if (isDefaultLayer != _BASE) {
                            layer_off(isDefaultLayer);
                              
                            return false;
                        }
                }
                break;
                
      case L_BRK_SHIFT:
                if(record->event.pressed) {
                        my_lShift_timer = timer_read();
                        register_code(KC_LSFT); // Change the key to be held here
                } else {
                        unregister_code(KC_LSFT); // Change the key that was held here, too!
                        if (timer_elapsed(my_lShift_timer) < TAPPING_TERM) {
                                SEND_STRING("{"); // Change the character(s) to be sent on tap here
                        }
                }
                return false; // We handled this keypress
                break;

      case R_BRK_SHIFT:
                if(record->event.pressed) {
                        my_rShift_timer = timer_read();
                        register_code(KC_RSFT); // Change the key to be held here
                } else {
                        unregister_code(KC_RSFT); // Change the key that was held here, too!
                        if (timer_elapsed(my_rShift_timer) < TAPPING_TERM) {
                                SEND_STRING("}"); // Change the character(s) to be sent on tap here
                        }
                }
                return false; // We handled this keypress
                break;

      case L_PRT_CTRL:
                if(record->event.pressed) {
                        my_lCtrl_timer = timer_read();
                        register_code(KC_LCTL); // Change the key to be held here
                } else {
                        unregister_code(KC_LCTL); // Change the key that was held here, too!
                        if (timer_elapsed(my_lCtrl_timer) < TAPPING_TERM) {
                                SEND_STRING("("); // Change the character(s) to be sent on tap here
                        }
                }
                return false; // We handled this keypress
                break;

      case R_PRL_CLTR:
                if(record->event.pressed) {
                        my_rCtrl_timer = timer_read();
                        register_code(KC_RCTL); // Change the key to be held here
                } else {
                        unregister_code(KC_RCTL); // Change the key that was held here, too!
                        if (timer_elapsed(my_rCtrl_timer) < TAPPING_TERM) {
                                SEND_STRING(")"); // Change the character(s) to be sent on tap here
                        }
                }
                return false; // We handled this keypress
                break;

      case L_SQPR_ALT:
                if(record->event.pressed) {
                        my_lAlt_timer = timer_read();
                        register_code(KC_LALT); // Change the key to be held here
                } else {
                        unregister_code(KC_LALT); // Change the key that was held here, too!
                        if (timer_elapsed(my_lAlt_timer) < TAPPING_TERM) {
                                SEND_STRING("["); // Change the character(s) to be sent on tap here
                        }
                }
                return false; // We handled this keypress
                break;

      case R_SQPR_ALT:
                if(record->event.pressed) {
                        my_rAlt_timer = timer_read();
                        register_code(KC_ALGR); // Change the key to be held here
                } else {
                        unregister_code(KC_ALGR); // Change the key that was held here, too!
                        if (timer_elapsed(my_rAlt_timer) < TAPPING_TERM) {
                                SEND_STRING("]"); // Change the character(s) to be sent on tap here
                        }
                }
                return false; // We handled this keypress
                break;

        case TWO_AND:
                if (record->event.pressed) {
                        SEND_STRING(" && ");
                }
                break;

        case TWO_OR:
                if (record->event.pressed) {
                        SEND_STRING(" || ");
                }
                break;

        case SG_QUOTE:
                if (record->event.pressed) {
                        SEND_STRING("' ");
                }
                break;

        case DB_QUOTE:
                if (record->event.pressed) {
                        SEND_STRING("\" ");
                }
                break;

        case W_LS:
                if (record->event.pressed) {
                        SEND_STRING(SS_DOWN(X_LCTRL));
                        SEND_STRING(SS_DOWN(X_LALT));
                        SEND_STRING(SS_DOWN(X_LSHIFT));
                        SEND_STRING(SS_DOWN(X_LGUI));
                        SEND_STRING(SS_TAP(X_LEFT));
                        SEND_STRING(SS_UP(X_LGUI));
                        SEND_STRING(SS_UP(X_LSHIFT));
                        SEND_STRING(SS_UP(X_LALT));
                        SEND_STRING(SS_UP(X_LCTRL));
                }
                break;

        case W_RS:
                if (record->event.pressed) {
                        SEND_STRING(SS_DOWN(X_LCTRL));
                        SEND_STRING(SS_DOWN(X_LALT));
                        SEND_STRING(SS_DOWN(X_LSHIFT));
                        SEND_STRING(SS_DOWN(X_LGUI));
                        SEND_STRING(SS_TAP(X_RIGHT));
                        SEND_STRING(SS_UP(X_LGUI));
                        SEND_STRING(SS_UP(X_LSHIFT));
                        SEND_STRING(SS_UP(X_LALT));
                        SEND_STRING(SS_UP(X_LCTRL));
                }
                break;

        case W_LD:
                if (record->event.pressed) {
                        SEND_STRING(SS_DOWN(X_LCTRL));
                        SEND_STRING(SS_DOWN(X_LSHIFT));
                        SEND_STRING(SS_DOWN(X_LALT));
                        SEND_STRING(SS_TAP(X_LEFT));
                        SEND_STRING(SS_UP(X_LALT));
                        SEND_STRING(SS_UP(X_LSHIFT));
                        SEND_STRING(SS_UP(X_LCTRL));
                }
                break;

        case W_RD:
                if (record->event.pressed) {
                        SEND_STRING(SS_DOWN(X_LCTRL));
                        SEND_STRING(SS_DOWN(X_LSHIFT));
                        SEND_STRING(SS_DOWN(X_LALT));
                        SEND_STRING(SS_TAP(X_RIGHT));
                        SEND_STRING(SS_UP(X_LALT));
                        SEND_STRING(SS_UP(X_LSHIFT));
                        SEND_STRING(SS_UP(X_LCTRL));
                }
                break;

        case GO_L:
                if (record->event.pressed) {
                        SEND_STRING(SS_DOWN(X_LCTRL));
                        SEND_STRING(SS_DOWN(X_LALT));
                        SEND_STRING(SS_TAP(X_LEFT));
                        SEND_STRING(SS_UP(X_LALT));
                        SEND_STRING(SS_UP(X_LCTRL));
                }
                break;

        case GO_R:
                if (record->event.pressed) {
                        SEND_STRING(SS_DOWN(X_LCTRL));
                        SEND_STRING(SS_DOWN(X_LALT));
                        SEND_STRING(SS_TAP(X_RIGHT));
                        SEND_STRING(SS_UP(X_LALT));
                        SEND_STRING(SS_UP(X_LCTRL));
                }
                break;
        }

        return true;
};

void oneshot_mods_changed_kb(uint8_t mods) {
        if (mods & MOD_MASK_SHIFT) {
                rgblight_setrgb_at(40, 0, 0, 3);
        }
        if (mods & MOD_MASK_CTRL) {
                rgblight_setrgb_at(0, 140, 0, 2);
        }
        if (mods & MOD_MASK_ALT) {
                rgblight_setrgb_at(0, 140, 0, 4);
        }

        if (!mods) {
                rgblight_setrgb_at(0, 0, 0, 2);
                rgblight_setrgb_at(0, 0, 0, 3);
                rgblight_setrgb_at(0, 0, 0, 4);
        }
}

void oneshot_locked_mods_changed_kb(uint8_t mods) {
        if (mods & MOD_MASK_SHIFT) {
                rgblight_setrgb_at(110, 0, 0, 3);
        }
        if (mods & MOD_MASK_CTRL) {
                rgblight_setrgb_at(0, 255, 0, 2);
        }
        if (mods & MOD_MASK_ALT) {
                rgblight_setrgb_at(0, 255, 0, 4);
        }

        if (!mods) {
                rgblight_setrgb_at(0, 0, 0, 2);
                rgblight_setrgb_at(0, 0, 0, 3);
                rgblight_setrgb_at(0, 0, 0, 4);
        }
}


uint32_t layer_state_set_user(uint32_t state) {
        // icekeys_led_off();

        uint8_t layer = biton32(state);
        switch (layer) {
        case _SYMB:
                isDefaultLayer = _SYMB;
                rgblight_setrgb_at(40, 0, 0, 1);
                break;
        case _FUNC:
                isDefaultLayer = _FUNC;
                rgblight_setrgb_at(40, 0, 0, 5);
                break;
        case _NUMS:
                isDefaultLayer = _NUMS;
                rgblight_setrgb_at(0, 255, 0, 0);
                break;
        case _NVMD:
                isDefaultLayer = _NVMD;
                rgblight_setrgb_at(0, 255, 0, 6);
                break;
        // case 2:
        // break;
        default:
                isDefaultLayer = _BASE;
                rgblight_setrgb_at(0, 0, 0, 0);
                rgblight_setrgb_at(0, 0, 0, 1);
                rgblight_setrgb_at(0, 0, 0, 5);
                rgblight_setrgb_at(0, 0, 0, 6);
                break;
        }

        return state;
}
