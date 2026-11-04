#include "init.h"

#include "panic.h"
#include "stm32c0xx_hal.h"
#include "private/configure_clock.h"
#include "private/configure_pins.h"
#include "../include/init/configure_uart.h"

void INIT_InitSystem(void) {
    if (HAL_Init() != HAL_OK) EarlyPanic();

    INIT_ConfigureClockOrDie();
    INIT_ConfigurePins();

    INIT_ConfigureUartOrDie();
}
