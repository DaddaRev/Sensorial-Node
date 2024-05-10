/*
 * drv_hts221.h
 */

#include "drv_hts221.h"
#include "stm32wlxx_nucleo_bus.h"
#include "hts221.h"

static HTS221_Object_t HTS221_OB_Handle;
static HTS221_IO_t HTS221_IO_Handle;

void HTS221_USER_Init(void)
{
	float dr=-1;
	HTS221_IO_Handle.Address=0xBE;
	HTS221_IO_Handle.BusType=0;
	HTS221_IO_Handle.WriteReg=BSP_I2C2_WriteReg;
	HTS221_IO_Handle.ReadReg=BSP_I2C2_ReadReg;

	HTS221_RegisterBusIO(&HTS221_OB_Handle, &HTS221_IO_Handle);
	HTS221_HUM_Enable(&HTS221_OB_Handle);
	HTS221_TEMP_Enable(&HTS221_OB_Handle);
	HTS221_TEMP_SetOutputDataRate(&HTS221_OB_Handle, 1);
	HTS221_TEMP_GetOutputDataRate(&HTS221_OB_Handle, &dr);
}
float HTS221_Read_Temperature(void)
{
	float hts221_temp=0;
	HTS221_TEMP_GetTemperature(&HTS221_OB_Handle, &hts221_temp);
	return hts221_temp;
}
float HTS221_Read_Humidity(void)
{
	float hts221_humi=0;
	HTS221_HUM_GetHumidity(&HTS221_OB_Handle, &hts221_humi);
	return hts221_humi;
}
