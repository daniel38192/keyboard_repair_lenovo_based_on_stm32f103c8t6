//
// Created by Daniel Nuñez Villegas on 28/05/25.
//

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdint.h>

#define DEBOUNCING_SCANNING_NUMBER 20

#define KEY_PRESSED_DEBOUNCING_MINIMUM_VALUE 17

enum HID_KEY_TYPE {
    MODIFIER,
    KEY,
    FUNCTION,
    EMPTY
};

struct keyboard_button {
    enum HID_KEY_TYPE key_type;
    uint8_t code;
};

void print_software_debounce_keys(void);

void scan_and_send_keys(void);

#endif //KEYBOARD_H
