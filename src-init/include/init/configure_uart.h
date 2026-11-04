//
// Created by _12354fdw on 11/3/26.
//

#ifndef CONFIGURE_UART_H
#define CONFIGURE_UART_H
#include "stm32c0xx_hal_uart.h"

void INIT_ConfigureUartOrDie(void);

extern UART_HandleTypeDef logUart;

#endif //CONFIGURE_UART_H
