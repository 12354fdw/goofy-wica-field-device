#include "main.h"

#include "init/init.h"

int main(void) {
  INIT_InitSystem();

  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);

  for (;;) {
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
    HAL_Delay(100);
  }
}

void Error_Handler(void) {
  __disable_irq();
  while (1)
  {
  }
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line) {
}
#endif // USE_FULL_ASSERT
