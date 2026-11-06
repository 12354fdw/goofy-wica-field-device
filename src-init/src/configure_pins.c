#include "private/configure_pins.h"

#include "stm32c0xx_hal_gpio.h"
#include "stm32c0xx_hal_rcc.h"

#define PIN_I2C_BUS_PWR  GPIO_PIN_0   // PA0
#define PIN_RF_DIO1      GPIO_PIN_1   // PA1
#define PIN_RF_NRST      GPIO_PIN_2   // PA2
#define PIN_RF_BUSY      GPIO_PIN_3   // PA3
#define PIN_RF_NSS       GPIO_PIN_4   // PA4
#define PIN_SPI_SCK      GPIO_PIN_5   // PA5
#define PIN_SPI_MISO     GPIO_PIN_6   // PA6
#define PIN_SPI_MOSI     GPIO_PIN_7   // PA7
#define PIN_STATUS_LED   GPIO_PIN_8   // PA8
#define PIN_LOG_TX       GPIO_PIN_9   // PA9
#define PIN_LOG_RX       GPIO_PIN_10  // PA10
#define PIN_I2C_SCL      GPIO_PIN_6   // PB6
#define PIN_I2C_SDA      GPIO_PIN_7   // PB7

void INIT_ConfigurePins(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_SYSCFG_CLK_ENABLE();

    // port remap
    SYSCFG->CFGR1 |= SYSCFG_CFGR1_PA11_RMP | SYSCFG_CFGR1_PA12_RMP;

    HAL_GPIO_WritePin(GPIOA, PIN_I2C_BUS_PWR | PIN_RF_NRST | PIN_RF_NSS
                             | PIN_STATUS_LED, GPIO_PIN_RESET);

    // status led
    GPIO_InitStruct.Pin = PIN_STATUS_LED;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // rf module gpio
    GPIO_InitStruct.Pin = PIN_RF_NRST | PIN_RF_NSS;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = PIN_RF_DIO1 | PIN_RF_BUSY;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // rf module
    GPIO_InitStruct.Pin = PIN_SPI_SCK | PIN_SPI_MISO | PIN_SPI_MOSI;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF0_SPI1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // i2c bus power
    GPIO_InitStruct.Pin = PIN_I2C_BUS_PWR;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // i2c1 bus
    GPIO_InitStruct.Pin = PIN_I2C_SCL | PIN_I2C_SDA;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF6_I2C1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    // uart debugging
    GPIO_InitStruct.Pin = PIN_LOG_TX | PIN_LOG_RX;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF1_USART1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}
