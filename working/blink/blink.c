/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"

#define PICO_DEFAULT_SPI_RX_PIN   12 
#define PICO_DEFAULT_SPI_TX_PIN   11 
#define PICO_DEFAULT_SPI_SCK_PIN  10 
#define PICO_DEFAULT_SPI_CSN_PIN  9 
#define PICO_DEFAULT_LED_PIN 13

int main() {
#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#else
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
    }
#endif
}
