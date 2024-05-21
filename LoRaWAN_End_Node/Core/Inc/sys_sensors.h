/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    sys_sensors.h
  * @author  MCD Application Team
  * @brief   Header for sensors application
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SENSORS_H__
#define __SENSORS_H__

#ifdef __cplusplus
extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/**
  * Sensor data parameters
  */

//OLD STRUCT
/*
typedef struct
{
  float pressure;
  float temperature;
  float humidity;
  int32_t latitude;
  int32_t longitude;
  int16_t altitudeGps;
  int16_t altitudeBar;
  //USER CODE BEGIN sensor_t //
  int terrain_humidity1;   //First analog sensor
  int terrain_humidity2;   //Second analog sensor
  // USER CODE END sensor_t //
} sensor_t;
*/

typedef struct
{
  float pressure;
  float temperature;
  float humidity;
  int32_t latitude;
  int32_t longitude;
  int16_t altitudeGps;
  int16_t altitudeBar;
  /* USER CODE BEGIN sensor_t */

  //teros12
  float teros12_vwc_raw_1;
  float teros12_vwc_raw_2;
  float teros12_vwc_raw_3;
  float teros12_vwc_raw_4;
  float teros12_vwc_raw_5;

  float teros12_temp_raw_1;
  float teros12_temp_raw_2;
  float teros12_temp_raw_3;
  float teros12_temp_raw_4;
  float teros12_temp_raw_5;

  //teros10
  uint16_t teros10_raw_vwc_1;
  uint16_t teros10_raw_vwc_2;
  uint16_t teros10_raw_vwc_3;
  uint16_t teros10_raw_vwc_4;
  uint16_t teros10_raw_vwc_5;

  //sen0308
  uint16_t sen0308_1;
  uint16_t sen0308_2;
  uint16_t sen0308_3;
  uint16_t sen0308_4;
  uint16_t sen0308_5;

  //soilwatch10
  uint16_t soilwatch10_1;
  uint16_t soilwatch10_2;
  uint16_t soilwatch10_3;
  uint16_t soilwatch10_4;
  uint16_t soilwatch10_5;


  /* USER CODE END sensor_t */
} sensor_t;

/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/

/* USER CODE BEGIN EC */
#if defined (SENSOR_ENABLED) && (SENSOR_ENABLED == 1) && defined (X_NUCLEO_IKS01A2)
#define HTS221_0    0U
#define LPS22HB_0   1U
#endif /* SENSOR_ENABLED & X_NUCLEO_IKS01A2 */
/* USER CODE END EC */

/* External variables --------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
/**
  * @brief  initialize the environmental sensor
  */
int32_t EnvSensors_Init(void);

/**
  * @brief  Environmental sensor  read.
  * @param  sensor_data sensor data
  */
int32_t EnvSensors_Read(sensor_t *sensor_data);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

#ifdef __cplusplus
}
#endif

#endif /* __SENSORS_H__ */
