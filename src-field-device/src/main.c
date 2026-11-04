#include "main.h"

#include <stdio.h>

#include "init/configure_uart.h"
#include "init/init.h"

int main(void) {
  INIT_InitSystem();

  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);

  HAL_Delay(1000);

  for (;;) {
    // printf("Hello, World!\n");
    // fflush(stdout);

    HAL_UART_Transmit(&logUart, "hi", 3, HAL_MAX_DELAY);

    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
    HAL_Delay(500);
  }
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line) {
}
#endif // USE_FULL_ASSERT
