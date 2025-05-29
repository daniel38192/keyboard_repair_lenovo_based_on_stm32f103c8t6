//
// Created by Daniel Nuñez Villegas on 28/05/25.
//


#include "keyboard.h"

#include "keyboard_matrix_definition.h"

#include "keyboard_gpio_helper.h"

#include <stdint.h>

#include "hid_keycodes.h"
#include "usart.h"

#include "usbd_hid.h"

extern USBD_HandleTypeDef hUsbDeviceFS;

static struct keyboard_button keyboard_map[KEYBOARD_MATRIX_ROWS][KEYBOARD_MATRIX_COLS] = {
    //Row 1
    {{KEY, HID_KEY_KP_8}, {KEY, HID_KEY_KP_4}, {MODIFIER, HID_MODIFIER_LEFT_SHIFT}, {KEY, HID_KEY_TAB},  {KEY, HID_KEY_Y}, {KEY, HID_KEY_F3}, {KEY, HID_KEY_CAPS_LOCK}, {KEY, HID_KEY_T}, {KEY, HID_KEY_F7}, {KEY, HID_KEY_LEFT_BRACKET}, {KEY, HID_KEY_RIGHT_BRACKET}, {EMPTY, 0}, {EMPTY, 0}, {KEY, HID_KEY_NUM_LOCK}, {EMPTY, 0}, {EMPTY, 0}, {KEY, HID_KEY_BACKSPACE}, {EMPTY, 0}},
    //Row 2
    {{KEY, HID_KEY_KP_COMMA}, {KEY, HID_KEY_KP_3}, {EMPTY, 0}, {EMPTY, 0}, {KEY, HID_KEY_N}, {EMPTY, 0}, {EMPTY, 0}, {KEY, HID_KEY_B}, {EMPTY, 0}, {KEY, HID_KEY_SLASH}, {EMPTY, 0}, {EMPTY, 0}, {MODIFIER, HID_MODIFIER_RIGHT_ALT}, {KEY, HID_KEY_RIGHT_ARROW}, {KEY, HID_KEY_LEFT_ARROW}, {KEY, HID_KEY_DOWN_ARROW}, {KEY, HID_KEY_SPACE}, {EMPTY, 0} },
    //Row 3
    {{KEY, HID_KEY_KP_ENTER}, {KEY, HID_KEY_KP_ASTERISK}, {MODIFIER, HID_MODIFIER_RIGHT_SHIFT}, {KEY, HID_KEY_Z}, {KEY, HID_KEY_M}, {KEY, HID_KEY_C}, {KEY, HID_KEY_X}, {KEY, HID_KEY_V}, {KEY, HID_KEY_PERIOD}, {KEY, HID_KEY_BACKSLASH}, {KEY, HID_KEY_COMMA}, {MODIFIER, HID_MODIFIER_RIGHT_CTRL}, {EMPTY, 0}, {EMPTY, 0}, {KEY, HID_KEY_PRINT_SCREEN}, {EMPTY, 0}, {KEY, HID_KEY_ENTER}, {EMPTY, 0} },
    //Row 4.
    {{KEY, HID_KEY_KP_5}, {KEY, HID_KEY_KP_1}, {EMPTY, 0},  {KEY, HID_KEY_A}, {KEY, HID_KEY_J}, {KEY, HID_KEY_D}, {KEY, HID_KEY_S}, {KEY, HID_KEY_F}, {KEY, HID_KEY_L}, {KEY, HID_KEY_SEMICOLON}, {KEY, HID_KEY_K}, {EMPTY, 0}, {EMPTY, 0}, {EMPTY, 0}, {FUNCTION, 0}, {EMPTY, 0}, {EMPTY, 0}, {EMPTY, 0} },
    //Row 5.
    {{KEY, HID_KEY_KP_2}, {KEY, HID_KEY_KP_0}, {EMPTY, 0},  {KEY, HID_KEY_1},  {KEY, HID_KEY_7},  {KEY, HID_KEY_3},  {KEY, HID_KEY_2},  {KEY, HID_KEY_4},  {KEY, HID_KEY_9},  {KEY, HID_KEY_0},  {KEY, HID_KEY_8}, {EMPTY, 0},  {KEY, HID_KEY_INSERT},  {KEY, HID_KEY_F12 },  {KEY, HID_KEY_PAGE_UP},  {KEY, HID_KEY_F11},  {KEY, HID_KEY_F10},  {KEY, HID_KEY_PAGE_DOWN}},
    //Row 6
    {{KEY, HID_KEY_KP_MINUS}, {KEY, HID_KEY_KP_9}, {EMPTY, 0}, {KEY, HID_KEY_Q}, {KEY, HID_KEY_U}, {KEY, HID_KEY_E}, {KEY, HID_KEY_W}, {KEY, HID_KEY_R}, {KEY, HID_KEY_O}, {KEY, HID_KEY_P}, {KEY, HID_KEY_I}, {EMPTY, 0}, {KEY, HID_KEY_DELETE}, {EMPTY, 0}, {EMPTY, 0}, {EMPTY, 0}, {EMPTY, 0}, {MODIFIER, HID_MODIFIER_LEFT_GUI}},
    //Row 7.
    {{KEY, HID_KEY_KP_PLUS}, {KEY, HID_KEY_KP_6}, {EMPTY, 0}, {KEY, HID_KEY_GRAVE}, {KEY, HID_KEY_6}, {KEY, HID_KEY_F2}, {KEY, HID_KEY_F1}, {KEY, HID_KEY_5}, {KEY, HID_KEY_F8}, {KEY, HID_KEY_MINUS}, {KEY, HID_KEY_EQUAL}, {MODIFIER, HID_MODIFIER_LEFT_CTRL}, {EMPTY, 0}, {EMPTY, 0}, {KEY, HID_KEY_HOME}, {EMPTY, 0},  {KEY, HID_KEY_F9},  {KEY, HID_KEY_END} },
    //Row 8
    {{KEY, HID_KEY_KP_SLASH}, {KEY, HID_KEY_KP_7}, {EMPTY, 0}, {KEY, HID_KEY_ESCAPE}, {KEY, HID_KEY_H}, {KEY, HID_KEY_F4}, {KEY, HID_KEY_NON_US_HASH}, {KEY, HID_KEY_G},{EMPTY, 0},{KEY, HID_KEY_MUTE}, {KEY, HID_KEY_F6}, {EMPTY, 0}, {MODIFIER, HID_MODIFIER_LEFT_ALT}, {EMPTY, 0}, {KEY, HID_KEY_UP_ARROW}, {EMPTY, 0},  {KEY, HID_KEY_F5}, {EMPTY, 0}},
};

uint8_t keyboard_key_debounce[KEYBOARD_MATRIX_ROWS][KEYBOARD_MATRIX_COLS] = {0};



uint8_t report;

void send_keyboard_report(uint8_t keyBoardHIDsub[8]) {
    USBD_HID_SendReport(&hUsbDeviceFS, keyBoardHIDsub,8);
}

void software_debounce_keys(void) {
    for (int n_debouncing = 0; n_debouncing < DEBOUNCING_SCANNING_NUMBER; n_debouncing++) {
        struct keyboard_data keyboard_raw_values = read_keyboard();
        for (int rows = 0; rows < KEYBOARD_MATRIX_ROWS; rows++) {
            for (int cols = 0; cols < KEYBOARD_MATRIX_COLS; cols++) {
                if (keyboard_raw_values.data[rows][cols]) {
                    // Key is pressed, increment debounce counter
                    if (keyboard_key_debounce[rows][cols] < DEBOUNCING_SCANNING_NUMBER) {
                        keyboard_key_debounce[rows][cols]++;
                    }
                } else {
                    // Key is released, decrement debounce counter
                    if (keyboard_key_debounce[rows][cols] > 0) {
                        keyboard_key_debounce[rows][cols]--;
                    }
                }
            }
        }

    }
}

void send_keys_report_to_usb(void) {
    /* MODIFIER, RESERVED, KEYCODE1, KEYCODE2, KEYCODE3, KEYCODE4, KEYCODE5, KEYCODE6*/
    uint8_t keyBoardHIDsub[8] = {0};

    int keycode_count = 0;

    for (int rows = 0; rows < KEYBOARD_MATRIX_ROWS; ++rows) {
        for (int cols = 0; cols < KEYBOARD_MATRIX_COLS; ++cols) {
            if (keyboard_key_debounce[rows][cols] >= KEY_PRESSED_DEBOUNCING_MINIMUM_VALUE) {
                //the button was pressed
                //decide which type of button was pressed
                switch (keyboard_map[rows][cols].key_type) {
                    case KEY: {
                        if (keycode_count < 6) {
                            keyBoardHIDsub[keycode_count + 2] = keyboard_map[rows][cols].code;
                            keycode_count++;
                        }
                    } break;
                    case MODIFIER: {
                        keyBoardHIDsub[0] |= keyboard_map[rows][cols].code;
                    } break;
                    default: {
                        // Handle unexpected key_type (e.g., log for debugging)
                    } break;
                }
            }
        }
    }

    send_keyboard_report(keyBoardHIDsub);
}

void clear_keyboard_key_debounce_array(void) {
    for (int rows = 0; rows < KEYBOARD_MATRIX_ROWS; ++rows) {
        for (int cols = 0; cols < KEYBOARD_MATRIX_COLS; ++cols) {
            keyboard_key_debounce[rows][cols] = 0;
        }
    }
}


void scan_and_send_keys(void) {
    software_debounce_keys();
    send_keys_report_to_usb();
    clear_keyboard_key_debounce_array();
}

void print_software_debounce_keys(void) {

    software_debounce_keys();

    print("------------------------------------------------\n\r");

    for (int rows = 0; rows < KEYBOARD_MATRIX_ROWS; ++rows) {
        for (int cols = 0; cols < KEYBOARD_MATRIX_COLS; ++cols) {
            print_uint8_t(keyboard_key_debounce[rows][cols]);
            print("\t");
        }
        print("\n\r");
    }

    print("------------------------------------------------\n\r");

    clear_keyboard_key_debounce_array();
}


