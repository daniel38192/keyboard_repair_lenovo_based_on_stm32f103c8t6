//
// Created by Daniel Nuñez Villegas on 27/05/25.
//
#pragma once

#include <stm32f1xx.h>

#ifndef KEYBOARD_MATRIX_DEFINITION_H
#define KEYBOARD_MATRIX_DEFINITION_H

/* Keyboard matrix gpio rcc ports */

#define KEYBOARD_MATRIX_PORT_RCC_NUMBER 3

#define KEYBOARD_MATRIX_PORT_RCC_1 RCC_APB2ENR_IOPAEN
#define KEYBOARD_MATRIX_PORT_RCC_2 RCC_APB2ENR_IOPBEN
#define KEYBOARD_MATRIX_PORT_RCC_3 RCC_APB2ENR_IOPCEN

/* keyboard matrix definition */

#define KEYBOARD_MATRIX_ROWS 8
#define KEYBOARD_MATRIX_COLS 18

/* Pin STM32 definition for the keyboard matrix */

/* Rows */

// Row 1
#define KEYBOARD_MATRIX_ROW_PIN_9_PORT GPIOB
#define KEYBOARD_MATRIX_ROW_PIN_9_NUMBER 13

// Row 2
#define KEYBOARD_MATRIX_ROW_PIN_10_PORT GPIOB
#define KEYBOARD_MATRIX_ROW_PIN_10_NUMBER 1

// Row 3
#define KEYBOARD_MATRIX_ROW_PIN_11_PORT GPIOB
#define KEYBOARD_MATRIX_ROW_PIN_11_NUMBER 14

// Row 4
#define KEYBOARD_MATRIX_ROW_PIN_13_PORT GPIOB
#define KEYBOARD_MATRIX_ROW_PIN_13_NUMBER 15

// Row 5
#define KEYBOARD_MATRIX_ROW_PIN_14_PORT GPIOA
#define KEYBOARD_MATRIX_ROW_PIN_14_NUMBER 7

// Row 6
#define KEYBOARD_MATRIX_ROW_PIN_16_PORT GPIOA
#define KEYBOARD_MATRIX_ROW_PIN_16_NUMBER 6

// Row 7
#define KEYBOARD_MATRIX_ROW_PIN_17_PORT GPIOA
#define KEYBOARD_MATRIX_ROW_PIN_17_NUMBER 15

// Row 8
#define KEYBOARD_MATRIX_ROW_PIN_20_PORT GPIOA
#define KEYBOARD_MATRIX_ROW_PIN_20_NUMBER 4

/* Columns */

//Column 1
#define KEYBOARD_MATRIX_COL_PIN_7_PORT GPIOB
#define KEYBOARD_MATRIX_COL_PIN_7_NUMBER 12


//Column 2
#define KEYBOARD_MATRIX_COL_PIN_8_PORT GPIOB
#define KEYBOARD_MATRIX_COL_PIN_8_NUMBER 10

//Column 3
#define KEYBOARD_MATRIX_COL_PIN_12_PORT GPIOB
#define KEYBOARD_MATRIX_COL_PIN_12_NUMBER 0

//Column 4
#define KEYBOARD_MATRIX_COL_PIN_15_PORT GPIOA
#define KEYBOARD_MATRIX_COL_PIN_15_NUMBER 8

//Column 5
#define KEYBOARD_MATRIX_COL_PIN_18_PORT GPIOA
#define KEYBOARD_MATRIX_COL_PIN_18_NUMBER 5

//Column 6
#define KEYBOARD_MATRIX_COL_PIN_19_PORT GPIOB
#define KEYBOARD_MATRIX_COL_PIN_19_NUMBER 3

//Column 7
#define KEYBOARD_MATRIX_COL_PIN_21_PORT GPIOB
#define KEYBOARD_MATRIX_COL_PIN_21_NUMBER 4

//Column 8
#define KEYBOARD_MATRIX_COL_PIN_22_PORT GPIOA
#define KEYBOARD_MATRIX_COL_PIN_22_NUMBER 3

//Column 9
#define KEYBOARD_MATRIX_COL_PIN_23_PORT GPIOB
#define KEYBOARD_MATRIX_COL_PIN_23_NUMBER 5

//Column 10
#define KEYBOARD_MATRIX_COL_PIN_24_PORT GPIOA
#define KEYBOARD_MATRIX_COL_PIN_24_NUMBER 2

//Column 11
#define KEYBOARD_MATRIX_COL_PIN_25_PORT GPIOB
#define KEYBOARD_MATRIX_COL_PIN_25_NUMBER 6

//Column 12
#define KEYBOARD_MATRIX_COL_PIN_26_PORT GPIOA
#define KEYBOARD_MATRIX_COL_PIN_26_NUMBER 1

//Column 13
#define KEYBOARD_MATRIX_COL_PIN_27_PORT GPIOB
#define KEYBOARD_MATRIX_COL_PIN_27_NUMBER 7

//Column 14
#define KEYBOARD_MATRIX_COL_PIN_28_PORT GPIOA
#define KEYBOARD_MATRIX_COL_PIN_28_NUMBER 0

//Column 15
#define KEYBOARD_MATRIX_COL_PIN_29_PORT GPIOB
#define KEYBOARD_MATRIX_COL_PIN_29_NUMBER 8

//Column 16
#define KEYBOARD_MATRIX_COL_PIN_30_PORT GPIOC
#define KEYBOARD_MATRIX_COL_PIN_30_NUMBER 15

//Column 17
#define KEYBOARD_MATRIX_COL_PIN_31_PORT GPIOB
#define KEYBOARD_MATRIX_COL_PIN_31_NUMBER 9

//Column 18
#define KEYBOARD_MATRIX_COL_PIN_32_PORT GPIOC
#define KEYBOARD_MATRIX_COL_PIN_32_NUMBER 14

#endif //KEYBOARD_MATRIX_DEFINITION_H
