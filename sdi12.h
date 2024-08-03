#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <stdint.h>
#include "stm32wlxx_hal.h"

// Enum to define read errors
typedef enum {
    ReadError_None,
    ReadError_Timeout,
    ReadError_Pin,
    ReadError_WrongStopBit,
    ReadError_ParityBitMismatch,
    ReadError_BufferOverflow
} ReadError;

// Function prototypes
HAL_StatusTypeDef wake_up_sensors(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
HAL_StatusTypeDef write_command(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, const uint8_t* command, size_t length);
HAL_StatusTypeDef write_char(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t character);
uint8_t* read_response(uint8_t* buffer, size_t buffer_size, uint32_t timeout_ms, ReadError* error, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

// Utility function prototypes
uint8_t count_ones(uint8_t word);
uint8_t even_parity_bit(uint8_t word);

#endif // COMMUNICATION_H

