//
// Created by Daniel Nuñez Villegas on 28/05/25.
//

#ifndef KEYBOARD_HELPER_H
#define KEYBOARD_HELPER_H
#include <stdbool.h>
#include <stdint.h>
#include "keyboard_matrix_definition.h"

struct keyboard_data {
    bool data[KEYBOARD_MATRIX_ROWS][KEYBOARD_MATRIX_COLS];
};

void configure_keyboard_pins(void);

struct keyboard_data read_keyboard();

#endif //KEYBOARD_HELPER_H
