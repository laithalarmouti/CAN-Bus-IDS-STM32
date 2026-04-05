#ifndef CAN_DRIVER_H
#define CAN_DRIVER_H

#include "stm32f4xx.h"
#include <stdint.h>

typedef struct {
    uint32_t timestamp;
    uint32_t can_id;
    uint8_t  dlc;
    uint8_t  data[8];
} CAN_Frame_t;

#define CAN_RX_BUFFER_SIZE 32

typedef struct {
    CAN_Frame_t frames[CAN_RX_BUFFER_SIZE];
    volatile uint8_t head;
    volatile uint8_t tail;
    volatile uint8_t count;
} CAN_RingBuffer_t;

// TEST INJECTION
void CAN_Driver_RxHandler_Inject(CAN_Frame_t *frame);

#ifdef __cplusplus
extern "C" {
#endif

void    CAN_Driver_Init(void);
void    CAN_Driver_RxHandler(void);
uint8_t CAN_Driver_GetFrame(CAN_Frame_t *frame);

#ifdef __cplusplus
}
#endif

#endif // CAN_DRIVER_H
