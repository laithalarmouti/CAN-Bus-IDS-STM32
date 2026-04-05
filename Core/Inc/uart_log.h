#ifndef UART_LOG_H
#define UART_LOG_H

#include "stm32f4xx_hal.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void uart_log(UART_HandleTypeDef *huart, const char *msg);
void uart_log_fmt(UART_HandleTypeDef *huart, const char *fmt, ...);

#ifdef __cplusplus
}
#endif

#endif // UART_LOG_H
