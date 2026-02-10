/**
 ******************************************************************************
 * @file           : Systick_Program.h
 * @author         : Amany_Elsedawy
 * @version        : 0.0
 * @date           : 18-12-2025
 * @brief          : Program.c file for Sys Tick timer driver
 * @note           : Built for STM32F103C8T6
 ******************************************************************************
 */

/* Includes */

#include <stdlib.h>
#include"Stm32F103LIB.h"
#include"Systick_Interface.h"

#define AHB         0
#define  AHB_DIV8       1
#define STC_CLK_SOURCE   AHB
#define HCLK_MHZ 8   /* Configured CLKSRC as real clk u select in RCC*/

void Systick_DelayMS(uint32_t DelayTime){
	uint32_t reload_val;

	if(STC_CLK_SOURCE ==AHB ){
		/* loading =8000*DelayTime in mile sec*/
		reload_val = HCLK_MHZ * 1000 * DelayTime;
		/*Select AHB  as clock source, enable counter*/
		STK->STK_CTRL = (1<<2) | (1<<0);

	}else if(STC_CLK_SOURCE == AHB_DIV8){
		/* loading =1000*DelayTime in mile sec*/
		reload_val = (HCLK_MHZ/8) * 1000 * DelayTime;
		/*Select  AHB/8 as clock source, enable counter*/
		STK->STK_CTRL =  (1<<0);

	}
	STK->STK_LOAD = reload_val - 1;
	STK->STK_VAL  = 0;          /* reset counter*/
	/*polling for flag*/
	while(!((STK->STK_CTRL)&(1<<16)));
	/* Disable SysTick*/
	STK->STK_CTRL = 0;



}
void Systick_DelayuS(uint32_t DelayTime){

	uint32_t reload_val;

		if(STC_CLK_SOURCE ==AHB ){
			/* loading =8000*DelayTime in mile sec*/
			reload_val = HCLK_MHZ * DelayTime;
			/*Select AHB  as clock source, enable counter*/
			STK->STK_CTRL = (1<<2) | (1<<0);

		}else if(STC_CLK_SOURCE == AHB_DIV8){
			/* loading =1000*DelayTime in mile sec*/
			reload_val = (HCLK_MHZ/8)  * DelayTime;
			/*Select  AHB/8 as clock source, enable counter*/
			STK->STK_CTRL =  (1<<0);

		}
		STK->STK_LOAD = reload_val - 1;
		STK->STK_VAL  = 0;          /* reset counter*/
		/*polling for flag*/
		while(!((STK->STK_CTRL)&(1<<16)));
		/* Disable SysTick*/
		STK->STK_CTRL = 0;


}
