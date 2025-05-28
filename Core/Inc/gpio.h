//
// Created by Daniel Nuñez Villegas on 27/05/25.
//

#ifndef GPIO_H
#define GPIO_H

#include "stm32f103xb.h"

void set_pin_output(GPIO_TypeDef * GPIOPORT, int pin);

void set_pin_input_pull_down(GPIO_TypeDef  * GPIOPORT, int pin);

void write_pin(GPIO_TypeDef * GPIOPORT, int pin, int value);

void enable_clock(uint32_t rcc_gpio_clock);

#endif //GPIO_H
