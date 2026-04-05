#include "uart_log.h"
#include <stdarg.h>   // needed for variable arguments (the ... in uart_log_fmt)
#include <stdio.h>    // needed for vsnprintf()
#include <string.h>   // needed for strlen()

// A fixed size buffer where we build our message before sending
// 256 bytes is enough for our log lines
#define LOG_BUF_SIZE 256

void uart_log(UART_HandleTypeDef *huart, const char *msg)
{
    // HAL_UART_Transmit() sends bytes over UART
    // huart         → which UART peripheral to use
    // (uint8_t*)msg → the message bytes to send
    // strlen(msg)   → how many bytes to send
    // 100           → timeout in milliseconds — give up after 100ms
    HAL_UART_Transmit(huart, (uint8_t*)msg, strlen(msg), 100);
}

void uart_log_fmt(UART_HandleTypeDef *huart, const char *fmt, ...)
{
    char buf[LOG_BUF_SIZE];   // temporary buffer to build the message

    // va_list, va_start, va_end handle the variable arguments (the ...)
    // This is the standard C way to accept an unknown number of arguments
    va_list args;
    va_start(args, fmt);   // initialise args to point after fmt

    // vsnprintf() works like printf() but writes into buf instead of screen
    // LOG_BUF_SIZE - 1 → leave 1 byte for null terminator, never overflow
    vsnprintf(buf, LOG_BUF_SIZE - 1, fmt, args);

    va_end(args);   // clean up the va_list

    // now send the formatted string over UART
    uart_log(huart, buf);
}
