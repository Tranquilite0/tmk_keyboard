/*
Copyright 2011 Jun Wako <wakojun@gmail.com>

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

#ifndef CONFIG_H
#define CONFIG_H

/* controller configuration */
#include "controller_teensy.h"

#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0ADB
#define DEVICE_VER      0x0101
#define MANUFACTURER    t.m.k.
#define PRODUCT         ADB keyboard converter
#define DESCRIPTION     convert ADB keyboard to USB

/* matrix size */
#define MATRIX_ROWS 16  // keycode bit: 3-0
#define MATRIX_COLS 8   // keycode bit: 6-4

/* Locking Caps Lock support */
#define MATRIX_HAS_LOCKING_CAPS

#define MATRIX_ROW(code)    ((code)>>3&0x0F)
#define MATRIX_COL(code)    ((code)&0x07)


/* mouse keys */
#ifdef MOUSEKEY_ENABLE
#   define MOUSEKEY_DELAY_TIME 192
#endif


/* ADB port setting */
#define ADB_PORT        PORTF
#define ADB_PIN         PINF
#define ADB_DDR         DDRF
#define ADB_DATA_BIT    0
//#define ADB_PSW_BIT     1       // optional

/* key combination for command */
#include "adb.h"
#include "matrix.h"
#define IS_COMMAND() ( \
    matrix_is_on(MATRIX_ROW(ADB_POWER), MATRIX_COL(ADB_POWER)) \
)

#endif
