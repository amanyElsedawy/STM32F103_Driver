/**
 ******************************************************************************
 * @file           :Stm32F103_Registers.h
 * @author         : Amany_Elsedawy
 * @version        : 0.0
 * @date           : 14-10-2025
 * @brief          : Register definitions for STM32F103C8T6 peripherals
 * @note           : Built for STM32F103C8T6
 ******************************************************************************
 */

#ifndef STM32F103_REG_H
#define STM32F103_REG_H


//include STD library
#include"STD_TYPE.h"

//create structure of RCC registers
typedef struct{

	volatile u32 RCC_CR;
	volatile u32 RCC_CFGR;
	volatile u32 RCC_CIR;
	volatile u32 RCC_APB2RSTR;
	volatile u32 RCC_APB1RSTR;
	volatile u32 RCC_AHBENR;
	volatile u32 RCC_APB2ENR;
	volatile u32 RCC_APB1ENR;
	volatile u32 RCC_BDCR;
	volatile u32 RCC_CSR;
	volatile u32 RCC_AHBSTR;
	volatile u32 RCC_CFGR2;


}RCCF_REG_t;

//create pointer to RCC REG
volatile RCCF_REG_t * const RCC = (RCCF_REG_t*)(0x40021000 );


typedef struct
{
    volatile u32 PWR_CR;     // Power control register        (offset 0x00)
    volatile u32 PWR_CSR;    // Power control/status register (offset 0x04)
   }PWR_REG_t;
   //create pointer to RCC REG
   volatile PWR_REG_t * const PWR = (PWR_REG_t*)( 0x40007000);
#endif
