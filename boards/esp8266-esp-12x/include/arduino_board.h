/*
 * Copyright (C)  2018 Gunar Schorcht
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     boards_esp8266_esp-12x
 * @{
 *
 * @file
 * @brief       Board specific configuration for the Arduino API
 *
 * @author      Gunar Schorcht <gunar@schorcht.net>
 */

#ifndef ARDUINO_BOARD_H
#define ARDUINO_BOARD_H

#include "periph/gpio.h"
#include "periph/adc.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   The on-board LED is connected to GPIO2 (Arduino pin 3) on this board
 */
#define ARDUINO_LED     (3)

/**
 * @brief   Look-up table for the Arduino's digital pins
 */
static const gpio_t arduino_pinmap[] = {
    GPIO1,      /* ARDUINO_PIN_0 (RxD) */
    GPIO3,      /* ARDUINO_PIN_1 (TxD) */
    GPIO0,      /* ARDUINO_PIN_2 */
    GPIO2,      /* ARDUINO_PIN_3 */
    #if defined(CONFIG_FLASHMODE_QIO) || defined(CONFIG_FLASHMODE_QOUT)
    GPIO9,      /* ARDUINO_PIN_4 */
    GPIO10,     /* ARDUINO_PIN_5 */
    #else
    GPIO_UNDEF, /* ARDUINO_PIN_4 */
    GPIO_UNDEF, /* ARDUINO_PIN_5 */
    #endif
    GPIO_UNDEF, /* ARDUINO_PIN_6 */
    GPIO_UNDEF, /* ARDUINO_PIN_7 */
    GPIO_UNDEF, /* ARDUINO_PIN_8 */
    GPIO_UNDEF, /* ARDUINO_PIN_9 */
    GPIO15,     /* ARDUINO_PIN_10 (CS0)  */
    GPIO13,     /* ARDUINO_PIN_11 (MOSI) */
    GPIO12,     /* ARDUINO_PIN_12 (MISO) */
    GPIO14,     /* ARDUINO_PIN_13 (SCK)  */
    GPIO_UNDEF, /* ARDUINO_PIN_A0 */
    GPIO_UNDEF, /* ARDUINO_PIN_A1 */
    GPIO_UNDEF, /* ARDUINO_PIN_A2 */
    GPIO_UNDEF, /* ARDUINO_PIN_A3 */
    GPIO4,      /* ARDUINO_PIN_A4 (SDA) */
    GPIO5,      /* ARDUINO_PIN_A5 (SCL) */
};

/**
 * @brief   Look-up table for the Arduino's analog pins
 */
static const adc_t arduino_analog_map[] = {
};

#ifdef __cplusplus
}
#endif

#endif /* ARDUINO_BOARD_H */
/** @} */
