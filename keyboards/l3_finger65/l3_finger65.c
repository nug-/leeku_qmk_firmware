/*
Copyright 2017 Luiz Ribeiro <luizribeiro@gmail.com>
Modified 2018 Kenneth A. <github.com/krusli>

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

#include "l3_finger65.h"

#include <avr/pgmspace.h>

#include "action_layer.h"
#include "quantum.h"

#include "i2c.h"

// for keyboard subdirectory level init functions
// @Override
void matrix_init_kb(void) {
  // call user level keymaps, if any
  matrix_init_user();
}

void matrix_scan_kb(void) {
  matrix_scan_user();
  /* Nothing else for now. */
}

__attribute__((weak)) // overridable
void matrix_init_user(void) {

}

__attribute__((weak)) // overridable
void matrix_scan_user(void) {

}
