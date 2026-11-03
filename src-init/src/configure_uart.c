#include "private/configure_uart.h"

#include "stm32c0xx_hal_rcc.h"
#include "stm32c0xx_hal_uart.h"
#include "init/panic.h"

static UART_HandleTypeDef logUart;

void INIT_ConfigureUartOrDie(void) {
    __HAL_RCC_USART1_CLK_ENABLE();

    logUart.Instance = USART1;
    logUart.Init.BaudRate = 115200;
    logUart.Init.WordLength = UART_WORDLENGTH_8B;
    logUart.Init.StopBits = UART_STOPBITS_1;
    logUart.Init.Parity = UART_PARITY_NONE;
    logUart.Init.Mode = UART_MODE_TX_RX;
    logUart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    logUart.Init.OverSampling = UART_OVERSAMPLING_16;
    logUart.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
    logUart.Init.ClockPrescaler = UART_PRESCALER_DIV1;
    logUart.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;


    if (HAL_UART_Init(&logUart) != HAL_OK) {
        EarlyPanic();
    }
}
