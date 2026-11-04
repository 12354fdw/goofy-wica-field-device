#include "private/configure_clock.h"

#include "panic.h"
#include "stm32c0xx_hal_flash.h"
#include "stm32c0xx_hal_rcc.h"

void INIT_ConfigureClockOrDie(void) {
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /* Run the system from the internal HSI at its native 48 MHz (no /4).
     * This makes the real SYSCLK/HCLK/PCLK1 = 48 MHz, so the UART baud math
     * and the actual peripheral clock agree (previously the instrumentation
     * showed ~460800 baud, i.e. 48 MHz with a BRR computed for 12 MHz). */
    __HAL_FLASH_SET_LATENCY(FLASH_LATENCY_1);

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
        EarlyPanic();
    }

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                                |RCC_CLOCKTYPE_PCLK1;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
    RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK) {
        EarlyPanic();
    }
}
