#include "init.h"

#include "stm32c0xx_hal.h"
#include "private/configure_clock.h"
#include "private/configure_pins.h"
#include "private/configure_uart.h"

void INIT_InitSystem(void) {
    HAL_Init();

    INIT_ConfigureClockOrDie();
    INIT_ConfigurePins();

    INIT_ConfigureUartOrDie();
}
