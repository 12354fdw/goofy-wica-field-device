#include "init.h"

#include "private/configure_clock.h"
#include "private/configure_pins.h"
#include "private/configure_uart.h"

void INIT_InitSystem(void) {
    INIT_ConfigureClockOrDie();
    INIT_ConfigurePins();

    INIT_ConfigureUartOrDie();
}
