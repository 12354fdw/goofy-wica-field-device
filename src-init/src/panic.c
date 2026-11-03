#include "panic.h"

#include "stm32c0xx_hal.h"
#include "stm32c0xx/stm32c051xx.h"

void EarlyPanic(void) {
    // enable PA
    RCC->IOPENR |= RCC_IOPENR_GPIOAEN;
    __DSB();

    // set PA8 to OUT
    GPIOA->MODER &= ~(GPIO_MODER_MODE8_Msk);
    GPIOA->MODER |= (1 << GPIO_MODER_MODE8_Pos);

    // blink PA8 very quickly
    for (;;) {
        GPIOA->ODR ^= GPIO_ODR_OD8;
        for (volatile int i = 0; i < 75000; i++) {
            __NOP();
        }
    }
}

// TODO: make it print to UART
void PANIC(char* reason) {
    for (;;) {
        HAL_Delay(100);
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
    }
}