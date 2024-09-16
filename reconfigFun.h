#ifndef SDI_12_H
#define SDI_12_H

#include <stdint.h>
#include "stm32wlxx_hal.h"
/*
 * Prototipo della funzione che permette di cambiare le impostazioni del pin a seconda del parametro passato in input
 */
void Reconfigure_GPIO_Pins(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, int isOutput);

#endif
