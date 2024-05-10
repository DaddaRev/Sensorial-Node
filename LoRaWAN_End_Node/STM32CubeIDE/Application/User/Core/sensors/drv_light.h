/*
 * drv_light.h
 *
 *  Created on: Nov 04, 2021
 *      Author: Andrea
 *
 *  sensor: TSL2561
 */

#ifndef DRV_LIGHT_H_
#define DRV_LIGHT_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32wlxx_hal.h"
#include "stm32wlxx_nucleo.h"

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
int32_t drv_Light_Enable(I2C_HandleTypeDef* p_handle);
float drv_Light_Read(I2C_HandleTypeDef* p_handle, float p_light);

/* Private defines -----------------------------------------------------------*/


#endif /* DRV_TEMP_ONBOARD_H_ */
