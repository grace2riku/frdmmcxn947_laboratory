/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017, 2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "app.h"

#include "fsl_gpio.h"
#include "pin_mux.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */
int main(void)
{
    char ch;

    /* Init board hardware. */
    BOARD_InitHardware();

    PRINTF("hello world.\r\n");

    while (1)
    {
        ch = GETCHAR();
        PUTCHAR(ch);

        if ('r' == ch) {
			GPIO_PinWrite(BOARD_INITPINS_LED_RED_GPIO, BOARD_INITPINS_LED_RED_GPIO_PIN, 0);
			GPIO_PinWrite(BOARD_INITPINS_LED_GREEN_GPIO, BOARD_INITPINS_LED_GREEN_GPIO_PIN, 1);
			GPIO_PinWrite(BOARD_INITPINS_LED_BLUE_GPIO, BOARD_INITPINS_LED_BLUE_GPIO_PIN, 1);
        } else if ('g' == ch) {
			GPIO_PinWrite(BOARD_INITPINS_LED_RED_GPIO, BOARD_INITPINS_LED_RED_GPIO_PIN, 1);
			GPIO_PinWrite(BOARD_INITPINS_LED_GREEN_GPIO, BOARD_INITPINS_LED_GREEN_GPIO_PIN, 0);
			GPIO_PinWrite(BOARD_INITPINS_LED_BLUE_GPIO, BOARD_INITPINS_LED_BLUE_GPIO_PIN, 1);
        } else if ('b' == ch) {
			GPIO_PinWrite(BOARD_INITPINS_LED_RED_GPIO, BOARD_INITPINS_LED_RED_GPIO_PIN, 1);
			GPIO_PinWrite(BOARD_INITPINS_LED_GREEN_GPIO, BOARD_INITPINS_LED_GREEN_GPIO_PIN, 1);
			GPIO_PinWrite(BOARD_INITPINS_LED_BLUE_GPIO, BOARD_INITPINS_LED_BLUE_GPIO_PIN, 0);
        }
    }
}
