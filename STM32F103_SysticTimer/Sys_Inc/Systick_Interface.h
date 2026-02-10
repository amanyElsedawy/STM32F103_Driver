/**
 ******************************************************************************
 * @file           : Systick_Interface.h
 * @author         : Amany_Elsedawy
 * @version        : 0.0
 * @date           : 18-12-2025
 * @brief          : Interface file for Sys Tick timer driver
 * @note           : Built for STM32F103C8T6
 ******************************************************************************
 */

#ifndef STM32F103_Systick_Interface_H
#define STM32F103_Systick_Interface_H

/* Includes */

#include <stdlib.h>

void Systick_DelayMS(uint32_t DelayTime);
void Systick_DelayuS(uint32_t DelayTime);


#endif
