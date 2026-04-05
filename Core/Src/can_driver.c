#ifdef __cplusplus
extern "C" {
#endif

#include "can_driver.h"
#include "stm32f4xx.h"

// ── Ring Buffer Instance ───────────────────────────────────────────────────────
static CAN_RingBuffer_t rx_buffer = {0};

// ── CAN Driver Init ────────────────────────────────────────────────────────────
void CAN_Driver_Init(void)
{
    // Step 1: Enable clocks
    RCC->APB1ENR |= RCC_APB1ENR_CAN1EN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // Step 2: Configure PA11 (CAN_RX) and PA12 (CAN_TX) as Alternate Function
    GPIOA->MODER &= ~(0xF << 22);
    GPIOA->MODER |=  (0xA << 22);
    GPIOA->OSPEEDR |= (0xF << 22);
    GPIOA->PUPDR &= ~(0xF << 22);
    GPIOA->PUPDR |=  (0x1 << 22);
    GPIOA->AFR[1] &= ~(0xFF << 12);
    GPIOA->AFR[1] |=  (0x99 << 12);

    // Step 3: Enter CAN Initialization Mode
    CAN1->MCR &= ~CAN_MCR_SLEEP;
    CAN1->MCR |=  CAN_MCR_INRQ;
    while (!(CAN1->MSR & CAN_MSR_INAK));

    // Step 4: Configure Bit Timing for 500 kbit/s
    // APB1 = 45MHz, Prescaler=9, BS1=8, BS2=1
    CAN1->BTR = (0 << 24) |
                (0 << 20) |
                (7 << 16) |
                (8);

    // Step 5: Configure CAN Filter — accept all frames
    CAN1->FMR  |=  CAN_FMR_FINIT;
    CAN1->FA1R &= ~(1 << 0);
    CAN1->FS1R |=  (1 << 0);
    CAN1->FM1R &= ~(1 << 0);
    CAN1->sFilterRegister[0].FR1 = 0x00000000;
    CAN1->sFilterRegister[0].FR2 = 0x00000000;
    CAN1->FA1R |=  (1 << 0);
    CAN1->FMR  &= ~CAN_FMR_FINIT;

    // Step 6: Enable RX FIFO0 interrupt
    CAN1->IER |= CAN_IER_FMPIE0;

    // Step 7: Enable CAN1 RX0 interrupt in NVIC
    HAL_NVIC_SetPriority(CAN1_RX0_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(CAN1_RX0_IRQn);

    // Step 8: Leave Initialization Mode
    CAN1->MCR &= ~CAN_MCR_INRQ;
    while (CAN1->MSR & CAN_MSR_INAK);
}

// ── RX Interrupt Handler ───────────────────────────────────────────────────────
void CAN_Driver_RxHandler(void)
{
    if (CAN1->RF0R & CAN_RF0R_FMP0)
    {
        if (rx_buffer.count < CAN_RX_BUFFER_SIZE)
        {
            CAN_Frame_t *f = &rx_buffer.frames[rx_buffer.head];

            if (CAN1->sFIFOMailBox[0].RIR & CAN_RI0R_IDE)
            {
                f->can_id = (CAN1->sFIFOMailBox[0].RIR >> 3) & 0x1FFFFFFF;
            }
            else
            {
                f->can_id = (CAN1->sFIFOMailBox[0].RIR >> 21) & 0x7FF;
            }

            f->dlc = CAN1->sFIFOMailBox[0].RDTR & 0x0F;
            f->timestamp = HAL_GetTick();

            f->data[0] = (CAN1->sFIFOMailBox[0].RDLR >>  0) & 0xFF;
            f->data[1] = (CAN1->sFIFOMailBox[0].RDLR >>  8) & 0xFF;
            f->data[2] = (CAN1->sFIFOMailBox[0].RDLR >> 16) & 0xFF;
            f->data[3] = (CAN1->sFIFOMailBox[0].RDLR >> 24) & 0xFF;
            f->data[4] = (CAN1->sFIFOMailBox[0].RDHR >>  0) & 0xFF;
            f->data[5] = (CAN1->sFIFOMailBox[0].RDHR >>  8) & 0xFF;
            f->data[6] = (CAN1->sFIFOMailBox[0].RDHR >> 16) & 0xFF;
            f->data[7] = (CAN1->sFIFOMailBox[0].RDHR >> 24) & 0xFF;

            rx_buffer.head = (rx_buffer.head + 1) % CAN_RX_BUFFER_SIZE;
            rx_buffer.count++;
        }

        CAN1->RF0R |= CAN_RF0R_RFOM0;
    }
}

// ── Get Frame from Ring Buffer ─────────────────────────────────────────────────
uint8_t CAN_Driver_GetFrame(CAN_Frame_t *frame)
{
    if (rx_buffer.count == 0) return 0;

    *frame = rx_buffer.frames[rx_buffer.tail];

    rx_buffer.tail = (rx_buffer.tail + 1) % CAN_RX_BUFFER_SIZE;

    __disable_irq();
    rx_buffer.count--;
    __enable_irq();

    return 1;
}
//TEST INJECTION
void CAN_Driver_RxHandler_Inject(CAN_Frame_t *frame)
{
    if (rx_buffer.count < CAN_RX_BUFFER_SIZE)
    {
        rx_buffer.frames[rx_buffer.head] = *frame;
        rx_buffer.head = (rx_buffer.head + 1) % CAN_RX_BUFFER_SIZE;
        rx_buffer.count++;
    }
}

#ifdef __cplusplus
}
#endif
