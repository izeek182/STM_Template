/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
typedef struct{
  int16_t X;
  int16_t Y;
  int16_t Z;
} gyro_t;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define accComMode_Pin GPIO_PIN_0
#define accComMode_GPIO_Port GPIOC
#define analogIn_Pin GPIO_PIN_0
#define analogIn_GPIO_Port GPIOA
#define analogOut_Pin GPIO_PIN_4
#define analogOut_GPIO_Port GPIOA
#define accAddr_Pin GPIO_PIN_14
#define accAddr_GPIO_Port GPIOB
#define accJmp_Pin GPIO_PIN_15
#define accJmp_GPIO_Port GPIOB
#define rLED_Pin GPIO_PIN_6
#define rLED_GPIO_Port GPIOC
#define bLED_Pin GPIO_PIN_7
#define bLED_GPIO_Port GPIOC
#define oLED_Pin GPIO_PIN_8
#define oLED_GPIO_Port GPIOC
#define gLED_Pin GPIO_PIN_9
#define gLED_GPIO_Port GPIOC
#define segClk_Pin GPIO_PIN_10
#define segClk_GPIO_Port GPIOC
#define segD_Pin GPIO_PIN_11
#define segD_GPIO_Port GPIOC
#define SegLock_Pin GPIO_PIN_12
#define SegLock_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */
void Blocking_I2C_Write(int addr,uint8_t*buffer, int length);
void Blocking_I2C_Read(int addr,uint8_t*buffer, int length);
void Non_Blocking_I2C_Write(int addr,uint8_t*buffer, int length);
void Non_Blocking_I2C_Read(int addr,uint8_t*buffer, int length);
gyro_t check_gyro();
void enable_gyro();
uint32_t I2C_Hold_For_Event(uint8_t cont_Msk,uint8_t Err_Msk);
void Blocking_I2C_WriteRead(int addr,uint8_t *writeBuf,int wl,uint8_t *readBuffer,int rl);
void I2C_Start(uint8_t addr,uint8_t length,uint8_t Mode);
void I2C_shutdown();
uint32_t I2C_Transmit_PostStart(uint8_t Err_Msk,uint8_t*buffer,uint32_t length);
uint32_t I2C_Receive_Post_Start(uint8_t Err_Msk,uint8_t*buffer,uint32_t length);
void I2C_Close();
uint8_t read_ADC();
void write_DAC(uint8_t val);
void calibrate_ADC();


/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
