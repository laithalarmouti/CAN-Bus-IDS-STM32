#include "uart_frame_parser.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static UART_HandleTypeDef *parser_uart;
static uint8_t rx_byte;                  // single byte received via interrupt
static char    line_buf[64];             // accumulates one line
static uint8_t line_pos = 0;            // current position in line buffer

void UART_Parser_Init(UART_HandleTypeDef *huart)
{
    parser_uart = huart;
    // Start receiving one byte at a time via interrupt
    // HAL_UART_Receive_IT fires an interrupt every time one byte arrives
    HAL_UART_Receive_IT(parser_uart, &rx_byte, 1);
}

// This is called by the HAL UART interrupt callback
// It accumulates bytes into a line buffer until newline arrives
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1)
    {
        if (rx_byte == '\n')
        {
            // Null terminate the line
            line_buf[line_pos] = '\0';
            line_pos = 0;
        }
        else if (rx_byte != '\r' && line_pos < 63)
        {
            line_buf[line_pos++] = rx_byte;
        }

        // Re-arm the interrupt for the next byte
        HAL_UART_Receive_IT(parser_uart, &rx_byte, 1);
    }
}

void UART_Parser_Process(void)
{
    // Check if a complete line has arrived (null terminated, non-empty)
    if (line_buf[0] == '\0' || line_pos != 0) return;

    // Parse format: TYPE,ID,DLC,B0,B1,B2,B3,B4,B5,B6,B7
    // Example:      N,0316,8,05,21,68,09,21,21,00,6F
    char type;
    unsigned int can_id;
    unsigned int dlc;
    unsigned int data[8];

    int parsed = sscanf(line_buf,
        "%c,%x,%u,%x,%x,%x,%x,%x,%x,%x,%x",
        &type, &can_id, &dlc,
        &data[0], &data[1], &data[2], &data[3],
        &data[4], &data[5], &data[6], &data[7]);

    if (parsed == 11)
    {
        CAN_Frame_t frame;
        frame.can_id    = can_id;
        frame.dlc       = dlc;
        frame.timestamp = HAL_GetTick();
        for (int i = 0; i < 8; i++)
            frame.data[i] = (uint8_t)data[i];

        // Inject into ring buffer — same path as real CAN frames
        extern void CAN_Driver_RxHandler_Inject(CAN_Frame_t *f);
        CAN_Driver_RxHandler_Inject(&frame);
    }

    // Clear the line buffer for next frame
    line_buf[0] = '\0';
}
