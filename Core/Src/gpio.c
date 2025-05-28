//
// Created by Daniel Nuñez Villegas on 27/05/25.
//

#include "stm32f1xx.h"

void set_pin_output(GPIO_TypeDef  * GPIOPORT, const int pin) {
    //Configure port
    if (pin <= 7) {
        //Clear mode bits
        GPIOPORT -> CRL &= ~(0x3 << (pin*4));
        //Output mode max speed 10mhz
        GPIOPORT -> CRL |= 0x1 << (pin*4);
        //General pruporse output push pull
        GPIOPORT -> CRL &= ~(0x3 << (pin*4 + 2));
    } else {
        GPIOPORT -> CRH &= ~(0x3 << (pin*4 - 32));

        GPIOPORT -> CRH |= 0x1 << (pin*4 - 32);

        GPIOPORT -> CRH &= ~(0x3 << (pin*4 + 2 - 32));
    }
}

void set_pin_input_pull_down(GPIO_TypeDef  * GPIOPORT, const int pin) {
    //Configure port
    if (pin <= 7) {
        //Input mode
        GPIOPORT -> CRL &= ~(0x3 << (pin*4));

        //Clear CNF bits
        GPIOPORT -> CRL &= ~(0x3 << (pin*4 + 2));

        //Input with pull-up pull-down
        GPIOPORT -> CRL |= 0x2 << (pin*4 + 2);
    } else {
        GPIOPORT -> CRH &= ~(0x3 << (pin*4 - 32));

        GPIOPORT -> CRH &= ~(0x3 << (pin*4 + 2 - 32));

        GPIOPORT -> CRH |= 0x2 << (pin*4 + 2 - 32);
    }

    // pull down
    GPIOPORT -> ODR &= ~(1 << pin);
}

void write_pin(GPIO_TypeDef * GPIOPORT, const int pin, const int value) {
    if (value) {
        GPIOPORT -> BSRR = 0x1 << pin;
    } else {
        GPIOPORT -> BSRR = 0x1 << (pin + 16);
    }
}

uint32_t read_pin(GPIO_TypeDef * GPIOPORT, const int pin) {
    return GPIOPORT -> IDR & (0x1 << pin);
}

void enable_clock(const uint32_t rcc_gpio_clock) {
    RCC -> APB2ENR |= rcc_gpio_clock; //Enable GPIO clock
}
