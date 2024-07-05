/*
 *  Copyright (C) 2018-2021 Texas Instruments Incorporated
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <drivers/gpio.h>
#include <kernel/dpl/AddrTranslateP.h>
#include <kernel/dpl/DebugP.h>
#include "drivers/hw_include/am64x_am243x/cslr_soc_baseaddress.h"
#include "ti_drivers_open_close.h"
#include "ti_board_open_close.h"

#include "led.h"

void hello_world_main(void *args)
{
    unsigned long gpio_port_address = CSL_MCU_GPIO0_BASE;
    uint32_t i = 0u;
    /* Open drivers to open the UART driver for console */
    Drivers_open();
    Board_driversOpen();

    DebugP_log("Blinking a led!\n");
    DebugP_log("Address of the gpio port %d\n", gpio_port_address);
    DebugP_log("Address of the pad address%d\n", 0x04084014);

    ledDriverInit((uint16_t *)gpio_port_address, REGULAR);

    while (i < 10)
    {
        GPIO_pinWriteHigh(gpio_port_address, 5);
        // ledTurnOn(LED1);
        //*address = 1;
        ClockP_sleep(2);
        // ledTurnOff(LED1);
        //*address = 0;
        GPIO_pinWriteLow(gpio_port_address, 5);
        ClockP_sleep(2);
        ++i;
    }

    Board_driversClose();
    Drivers_close();
}
