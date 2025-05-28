//
// Created by Daniel Nuñez Villegas on 28/05/25.
//

#ifndef KEYBOARD_HELPER_H
#define KEYBOARD_HELPER_H
#include "keyboard_matrix_definition.h"

struct keyboard_row_data {
    int column_data[KEYBOARD_MATRIX_COLS];
};

void configure_keyboard_pins(void);

#endif //KEYBOARD_HELPER_H
