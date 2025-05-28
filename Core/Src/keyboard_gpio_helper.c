//
// Created by Daniel Nuñez Villegas on 27/05/25.
//

#include "keyboard_gpio_helper.h"
#include <stdint.h>
#include "keyboard_matrix_definition.h"
#include "gpio.h"

static uint32_t keyboard_matrix_rcc_peripheral_clock_list[] =
    {
    KEYBOARD_MATRIX_PORT_RCC_1,
    KEYBOARD_MATRIX_PORT_RCC_2,
    KEYBOARD_MATRIX_PORT_RCC_3
    };

static GPIO_TypeDef *keyboard_matrix_row_pin_port_list[] =
    {
    KEYBOARD_MATRIX_ROW_PIN_9_PORT,
    KEYBOARD_MATRIX_ROW_PIN_10_PORT,
    KEYBOARD_MATRIX_ROW_PIN_11_PORT,
    KEYBOARD_MATRIX_ROW_PIN_13_PORT,
    KEYBOARD_MATRIX_ROW_PIN_14_PORT,
    KEYBOARD_MATRIX_ROW_PIN_16_PORT,
    KEYBOARD_MATRIX_ROW_PIN_17_PORT,
    KEYBOARD_MATRIX_ROW_PIN_20_PORT,
    };

static int keyboard_matrix_row_pin_number_list[] =
    {
    KEYBOARD_MATRIX_ROW_PIN_9_NUMBER,
    KEYBOARD_MATRIX_ROW_PIN_10_NUMBER,
    KEYBOARD_MATRIX_ROW_PIN_11_NUMBER,
    KEYBOARD_MATRIX_ROW_PIN_13_NUMBER,
    KEYBOARD_MATRIX_ROW_PIN_14_NUMBER,
    KEYBOARD_MATRIX_ROW_PIN_16_NUMBER,
    KEYBOARD_MATRIX_ROW_PIN_17_NUMBER,
    KEYBOARD_MATRIX_ROW_PIN_20_NUMBER,
    };

static GPIO_TypeDef *keyboard_matrix_column_pin_port_list[] =
    {
    KEYBOARD_MATRIX_COL_PIN_7_PORT,
    KEYBOARD_MATRIX_COL_PIN_8_PORT,
    KEYBOARD_MATRIX_COL_PIN_12_PORT,
    KEYBOARD_MATRIX_COL_PIN_15_PORT,
    KEYBOARD_MATRIX_COL_PIN_18_PORT,
    KEYBOARD_MATRIX_COL_PIN_19_PORT,
    KEYBOARD_MATRIX_COL_PIN_21_PORT,
    KEYBOARD_MATRIX_COL_PIN_22_PORT,
    KEYBOARD_MATRIX_COL_PIN_23_PORT,
    KEYBOARD_MATRIX_COL_PIN_24_PORT,
    KEYBOARD_MATRIX_COL_PIN_25_PORT,
    KEYBOARD_MATRIX_COL_PIN_26_PORT,
    KEYBOARD_MATRIX_COL_PIN_27_PORT,
    KEYBOARD_MATRIX_COL_PIN_28_PORT,
    KEYBOARD_MATRIX_COL_PIN_29_PORT,
    KEYBOARD_MATRIX_COL_PIN_30_PORT,
    KEYBOARD_MATRIX_COL_PIN_31_PORT,
    KEYBOARD_MATRIX_COL_PIN_32_PORT,
    };

static int keyboard_matrix_column_pin_number_list[] =
    {
    KEYBOARD_MATRIX_COL_PIN_7_NUMBER,
    KEYBOARD_MATRIX_COL_PIN_8_NUMBER,
    KEYBOARD_MATRIX_COL_PIN_12_NUMBER,
    KEYBOARD_MATRIX_COL_PIN_15_NUMBER,
    KEYBOARD_MATRIX_COL_PIN_18_NUMBER,
    KEYBOARD_MATRIX_COL_PIN_19_NUMBER,
    KEYBOARD_MATRIX_COL_PIN_21_NUMBER,
    KEYBOARD_MATRIX_COL_PIN_22_NUMBER,
    KEYBOARD_MATRIX_COL_PIN_23_NUMBER,
    KEYBOARD_MATRIX_COL_PIN_24_NUMBER,
    KEYBOARD_MATRIX_COL_PIN_25_NUMBER,
    KEYBOARD_MATRIX_COL_PIN_26_NUMBER,
    KEYBOARD_MATRIX_COL_PIN_27_NUMBER,
    KEYBOARD_MATRIX_COL_PIN_28_NUMBER,
    KEYBOARD_MATRIX_COL_PIN_29_NUMBER,
    KEYBOARD_MATRIX_COL_PIN_30_NUMBER,
    KEYBOARD_MATRIX_COL_PIN_31_NUMBER,
    KEYBOARD_MATRIX_COL_PIN_32_NUMBER,
    };
void configure_keyboard_clock_pins(void) {
    for (int i = 0; i < KEYBOARD_MATRIX_PORT_RCC_NUMBER; ++i) {
        enable_clock(keyboard_matrix_rcc_peripheral_clock_list[i]);
    }
}

void configure_keyboard_row_pins(void) {
    for (int i = 0; i < KEYBOARD_MATRIX_ROWS; ++i) {
        set_pin_output(keyboard_matrix_row_pin_port_list[i], keyboard_matrix_row_pin_number_list[i]);
    }
}

void configure_keyboard_column_pins(void) {
    for (int i = 0; i < KEYBOARD_MATRIX_COLS; ++i) {
        set_pin_input_pull_down(keyboard_matrix_column_pin_port_list[i], keyboard_matrix_column_pin_number_list[i]);
    }
}

void configure_keyboard_pins(void) {
    configure_keyboard_clock_pins();
    configure_keyboard_row_pins();
    configure_keyboard_column_pins();
}




