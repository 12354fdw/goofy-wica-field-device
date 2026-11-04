#include "../include/init/configure_uart.h"

#include <stdio.h>

#include "panic.h"
#include "stm32c0xx_hal.h"

#define BAUD_RATE 115200

UART_HandleTypeDef logUart = {0};

void INIT_ConfigureUartOrDie(void) {
    __HAL_RCC_USART1_CLK_ENABLE();

    logUart.Instance = USART1;
    logUart.Init.BaudRate = BAUD_RATE;
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

int __io_putchar(int ch) {
    uint8_t byte = (uint8_t)ch;
    return HAL_UART_Transmit(&logUart, &byte, 1, HAL_MAX_DELAY) == HAL_OK ? ch : EOF;
}