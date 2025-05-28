//
// Created by Daniel Nuñez Villegas on 28/05/25.
//

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdint.h>
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

#endif //KEYBOARD_H
