/*
   Copyright 2018 Luca Masera

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

#pragma once

#include "config_common.h"


/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0001
#define MANUFACTURER    Luca Masera
#define PRODUCT         Split58

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 14

#define MATRIX_ROW_PINS {B0, B1, B2, B3}
#define MATRIX_COL_PINS    {B5, B6, F7, F6, F5, F4, F1, C7, C6, D3, D2, D1, D0, B7}

/* COL2ROW, ROW2COL, or CUSTOM_MATRIX */
#define DIODE_DIRECTION COL2ROW

#define TAPPING_TERM 200
//#define PERMISSIVE_HOLD
//#define IGNORE_MOD_TAP_INTERRUPT
#define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped this number of times again. */
#define ONESHOT_TIMEOUT 1500
#define TAPPING_TOGGLE 3

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

#define RGB_DI_PIN D5
#define RGBLED_NUM 8
