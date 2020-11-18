#ifndef UART_H_
#define UART_H_

#define hWifi    huart2
#define hMonitor huart3
#define QUEUE_BUFFER_LENGTH 1024

typedef struct
{
    int head, tail, data;
    uint8_t Buffer[QUEUE_BUFFER_LENGTH];
}UARTQUEUE, * pUARTQUEUE;

extern UART_HandleTypeDef huart3;

extern UARTQUEUE WifiQueue;

void InitUartQueue(pUARTQUEUE pQueue);
void PutDataToUartQueue(pUARTQUEUE pQueue, uint8_t data);
uint8_t GetDataFromUartQueue(pUARTQUEUE pQueue);

#endif /* UART_H_ */
