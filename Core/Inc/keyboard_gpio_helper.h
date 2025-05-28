//
// Created by Daniel Nuñez Villegas on 28/05/25.
//

#ifndef KEYBOARD_HELPER_H
#define KEYBOARD_HELPER_H
#include <stdint.h>
#include "keyboard_matrix_definition.h"

struct keyboard_row_data {
    uint32_t column_data[KEYBOARD_MATRIX_COLS];
};

void configure_keyboard_pins(void);

struct keyboard_row_data read_keyboard_row(int row);

#endif //KEYBOARD_HELPER_H
