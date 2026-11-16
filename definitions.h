#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__

#include <SimpleUART.h>
#include <SimpleGPIO.h>
#include "esp_timer.h"
#include "esp_log.h"
#include <string.h>


#define UART_TX GPIO_NUM_17
#define UART_RX GPIO_NUM_16
#define BAUD_RATE 9600

#define DEVICE_NAME "ESP_A"

SimpleUART uart(BAUD_RATE, UART_NUM_2, UART_TX, UART_RX);


char mensaje[64];
char recibido[64];

int64_t ultimo_envio;

int64_t dt = 1000000LL;


#endif // __DEFINITIONS_H__