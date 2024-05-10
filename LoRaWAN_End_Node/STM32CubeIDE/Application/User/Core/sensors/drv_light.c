/*
 * drv_light.c
 *
 *  Created on: Nov 04, 2021
 *      Author: Andrea
 *
 *  sensor: TSL2561
 */

#include "drv_light.h"
#include <stdio.h>


#define SNS_LIGHT_ADDR                      ( 0x29 << 1 )
#define SNS_LIGHT_CMD_REG                   ( 0xAC )
#define SNS_LIGHT_TIMEOUT                   ( 10000 )         // milliseconds



/**
 * Enable light sensor
 */
int32_t drv_Light_Enable(I2C_HandleTypeDef* p_handle)
{
	HAL_StatusTypeDef ret;

	uint8_t buf[2] = {0xA0, 0x03};

	ret = HAL_I2C_Master_Transmit(p_handle, SNS_LIGHT_ADDR, buf, 2, SNS_LIGHT_TIMEOUT);
}



/**
 * Read light sensor
 *
 * p_handle:   pointer to communication (I2C) structure
 * p_temp: 	   pointer to destination light intensity variable
 */
float drv_Light_Read(I2C_HandleTypeDef* p_handle, float p_light)
{
    HAL_StatusTypeDef ret;
    uint8_t buf[2];
    uint16_t tmp;

    /* Read light sensor */
    buf[0] = SNS_LIGHT_CMD_REG;

    ret = HAL_I2C_Master_Transmit(p_handle, SNS_LIGHT_ADDR, buf, 1, SNS_LIGHT_TIMEOUT);
    if (ret != HAL_OK)
    {
        return (int32_t)HAL_ERROR;
    }
    else
    {
        ret = HAL_I2C_Master_Receive(p_handle, SNS_LIGHT_ADDR, buf, 2, SNS_LIGHT_TIMEOUT);
        if (ret != HAL_OK)
        {
            return (int32_t)HAL_ERROR;
        }
        else
        {
            // debug
        	//printf("== Debug %d-%d\r\n", buf[0], buf[1]);
            tmp = ((uint16_t)buf[0] << 8) + buf[1];
            p_light = (float)tmp;
            return p_light;
        }
    }
}
