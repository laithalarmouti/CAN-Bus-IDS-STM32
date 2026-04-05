#ifndef UART_FRAME_PARSER_H
#define UART_FRAME_PARSER_H

#include "can_driver.h"
#include "stm32f4xx_hal.h"

// Call this in main init to start UART1 reception
void UART_Parser_Init(UART_HandleTypeDef *huart);

// Call this in main loop — processes received bytes and injects frames
void UART_Parser_Process(void);

#endif
