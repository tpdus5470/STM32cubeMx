#include "stm32f1xx_hal.h"

#include "uart.h"

UARTQUEUE WifiQueue;

void InitUartQueue(pUARTQUEUE pQueue)
{
    pQueue->data = pQueue->head = pQueue->tail = 0;
}

void PutDataToUartQueue(pUARTQUEUE pQueue, uint8_t data)
{
    if (pQueue->data == QUEUE_BUFFER_LENGTH)
        GetDataFromUartQueue(pQueue);
    pQueue->Buffer[pQueue->head++] = data;
    if (pQueue->head == QUEUE_BUFFER_LENGTH) pQueue->head = 0;
    pQueue->data++;
}

uint8_t GetDataFromUartQueue(pUARTQUEUE pQueue)
{
    uint8_t ch;

    ch = pQueue->Buffer[pQueue->tail++];
    if (pQueue->tail == QUEUE_BUFFER_LENGTH) pQueue->tail = 0;
    pQueue->data--;
    HAL_Delay(1);
    return ch;
}