#include "main.h"

#include <stdio.h>

#include "init/configure_uart.h"
#include "init/init.h"
#include "init/panic.h"

int main(void) {
    INIT_InitSystem();

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);

    HAL_Delay(1000);

    printf("Hello, World!\n");
    PANIC("not finished!");


    for (;;) {
        // if (HAL_UART_Transmit(&logUart, "hi", 3, HAL_MAX_DELAY) != HAL_OK) EarlyPanic();

        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
        HAL_Delay(500);
    }
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line) {
}
#endif // USE_FULL_ASSERT
