/*
 * Copyright (C)  2016 Freie Universität Berlin
 *                2016 Inria
 *                2020 Gunar Schorcht
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     boards_waveshare_nrf52840_eval_kit
 * @{
 *
 * @file
 * @brief       Board specific configuration for the Arduino API
 *
 * @author      Hauke Petersen  <hauke.petersen@fu-berlin.de>
 * @author      Alexandre Abadie  <alexandre.abadie@inria.fr>
 * @author      Gunar Schorcht <gunar@schorcht.net>
 */

#ifndef ARDUINO_BOARD_H
#define ARDUINO_BOARD_H

#include "arduino_pinmap.h"
#include "periph/pwm.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   The on-board LED is connected to Arduino pin 20 on this board
 */
#define ARDUINO_LED         (20)

/**
 * @brief   Look-up table for the Arduino's digital pins
 */
static const gpio_t arduino_pinmap[] = {
    ARDUINO_PIN_0,
    ARDUINO_PIN_1,
    ARDUINO_PIN_2,
    ARDUINO_PIN_3,
    ARDUINO_PIN_4,
    ARDUINO_PIN_5,
    ARDUINO_PIN_6,
    ARDUINO_PIN_7,
    ARDUINO_PIN_8,
    ARDUINO_PIN_9,
    ARDUINO_PIN_10,
    ARDUINO_PIN_11,
    ARDUINO_PIN_12,
    ARDUINO_PIN_13,
    ARDUINO_PIN_A0,
    ARDUINO_PIN_A1,
    ARDUINO_PIN_A2,
    ARDUINO_PIN_A3,
    ARDUINO_PIN_A4,
    ARDUINO_PIN_A5,
    ARDUINO_PIN_20,
    ARDUINO_PIN_21,
    ARDUINO_PIN_22,
    ARDUINO_PIN_23
};

/**
 * @brief   Look-up table for the Arduino's analog pins
 */
static const adc_t arduino_analog_map[] = {
    ARDUINO_A0,
    ARDUINO_A1,
    ARDUINO_A2,
    ARDUINO_A3,
    ARDUINO_A4,
    ARDUINO_A5,
};

/**
 * @brief   PWM frequency
 */
#define ARDUINO_PWM_FREQU       (15625U)

/**
 * @brief   List of PWM GPIO mappings
 */
static const arduino_pwm_t arduino_pwm_list[] = {
    { .pin = 3, .dev = PWM_DEV(0), .chan = 0 },
    { .pin = 5, .dev = PWM_DEV(0), .chan = 1 },
    { .pin = 6, .dev = PWM_DEV(0), .chan = 2 },
    { .pin = 9, .dev = PWM_DEV(0), .chan = 3 },
    { .pin = 20, .dev = PWM_DEV(1), .chan = 0 },
    { .pin = 21, .dev = PWM_DEV(1), .chan = 1 },
    { .pin = 22, .dev = PWM_DEV(1), .chan = 2 },
    { .pin = 23, .dev = PWM_DEV(1), .chan = 3 },
};

#ifdef __cplusplus
}
#endif

#endif /* ARDUINO_BOARD_H */
/** @} */
