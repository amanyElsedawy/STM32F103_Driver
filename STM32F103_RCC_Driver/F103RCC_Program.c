/**
 ******************************************************************************
 * @file           : F103RCC_Program.c
 * @author         : Amany_Elsedawy
 * @version        : 0.0
 * @date           : 14-10-2025
 * @brief          : Main program body for RCC driver
 * @note           : Built for STM32F103C8T6
 ******************************************************************************
 */

//include STD library
#include"STD_TYPE.h"

#include"F103RCC_Interface.h"

#include"Stm32F103_Registers.h"

#include"F103RCC_Private.h"



//function to Enable/Disable CLK & set CLK source

u8 RCCF_SetClk(RCCF_ClockSource_t ClkSrc, RCCF_ClockStatus_t ClkStatus){
	//create error status variable
	u8 LocalErrorStatus = STD_OK;
	u32 counter=0;
	//check CLK on or off
	if(ClkStatus==RCC_Enable){
		//switch which type of RCC Source select

		switch(ClkSrc){

		case RCC_HSI:
			//set pin 0 in CR to enable HSI
			RCC->RCC_CR |=(1<<0);
			//wait for HSI flag
			while(!(RCC->RCC_CR&(1<<1))){
				counter++;
				if(counter>TIMEOUT_HSI){
					LocalErrorStatus = STD_NOK;
					break;
				}
			}

			break;
		case RCC_HSE:

			//set pin 16 in CR to enable HSE
			RCC->RCC_CR |=(1<<16);
			while(!(RCC->RCC_CR&(1<<17))){
				counter++;
				if(counter>TIMEOUT_HSE){
					LocalErrorStatus = STD_NOK;
					break;
				}
			}

			break;
		case RCC_HSE_BYP:
			//Disable HSE first before changing bypass
			RCC->RCC_CR &=~(1<<16);
			//set pin 18 in CR to enable HSE_BYPASS
			RCC->RCC_CR |=(1<<18);
			// Enable HSE again (now in bypass mode)
			RCC->RCC_CR |=(1<<16);
			while(!(RCC->RCC_CR&(1<<17))){
				counter++;
				if(counter>TIMEOUT_HSE){
					LocalErrorStatus = STD_NOK;
					break;
				}
			}
			break;
		case RCC_PLL:
			//set pin 0 in CR to enable PLL
			RCC->RCC_CR |=(1<<24);
			u32 counter=0;
			//wait for PLL flag
			while(!(RCC->RCC_CR&(1<<25))){
				counter++;
				if(counter>TIMEOUT_PLL){
					LocalErrorStatus = STD_NOK;
					break;
				}
			}



			break;
		default:
			LocalErrorStatus=STD_NOK;
			break;
		}

	}else if(ClkStatus==RCC_Disable){
		switch(ClkSrc){

		case RCC_HSI:
			//CLEAR pin 0 in CR to enable HSI
			RCC->RCC_CR &=~(1<<0);


			break;
		case RCC_HSE:
			//CLEAR pin 16 in CR to enable HSE
			RCC->RCC_CR &=~(1<<16);
			break;
		case RCC_HSE_BYP:
			//Disable two pin for HSE bypass
			RCC->RCC_CR &=~(1<<16);
			RCC->RCC_CR &=~(1<<18);

			break;
		case RCC_PLL:
			//set pin 0 in CR to enable PLL
			RCC->RCC_CR &=~(1<<24);

			break;
		default:
			LocalErrorStatus=STD_NOK;
			break;

		}
	}

	return  LocalErrorStatus;
}


//function to select system Clock(HSI / HSE / PLL) by SWITCH MUX after enable SRC

u8 RCCF_SetSystemClock(RCCF_ClockSource_t ClkSrc){
	//create error status variable
	u8 LocalErrorStatus = STD_OK;

	switch(ClkSrc){
	//SW by bit 0 & 1 in RCC_CFGR Register

	case RCC_HSI:

		//clear sw bits first any select
		RCC->RCC_CFGR &=~(0b11<<0);
		RCC->RCC_CFGR |=HSI_CLK  ;

		break;
	case RCC_HSE:
		RCC->RCC_CFGR &=~(0b11<<0);
		RCC->RCC_CFGR |=HSE_CLK  ;

		break;


	case  RCC_PLL:
		RCC->RCC_CFGR &=~(0b11<<0);
		RCC->RCC_CFGR |=PLL_CLK  ;

		break;
	default:



		LocalErrorStatus = STD_NOK;
		break;
	}

	return LocalErrorStatus;

}




//LOOK u have MULL Options from 4 to 9 Available
//function to config PLL configuration
u8 RCCF_PLLConfig(PLL_Mul_t PLLMull,RCCF_PLLSrc_DIV_t PllSrc){


	u8 LocalErrorStatus = STD_OK;
	//check for PLL is off before config
	if((RCC->RCC_CR>>24)&1){

		return STD_NOK;//PLL must disable first
	}

	//clear for BITS[18-21] first
	RCC->RCC_CFGR &=~(0b1111<<18);
	//set PLL MULL
	RCC->RCC_CFGR |=(PLLMull<<18);

	switch(PllSrc){

	case RCC_HSI_DIV_2:
		RCC->RCC_CFGR &=~(1<<16);

		break;
	case RCC_HSE_DIV_1:
		RCC->RCC_CFGR |=(1<<16);
		RCC->RCC_CFGR &=~(1<<17);

		break;
	case RCC_HSE_DIV_2:
		RCC->RCC_CFGR |=(1<<16);
		RCC->RCC_CFGR |=(1<<17);


		break;
	default:
		LocalErrorStatus = STD_NOK;
		break;
	}

	return   LocalErrorStatus;

}

//function to Enable/Disable RTC CLK and set RTC CLK source& select the clock source for the RTC.
u8 RCCF_SetRTC_Clock(RCCF_RTCSource_t RTCSrc,RCCF_ClockStatus_t RTCStatus ){

	//create error status variable
	u8 LocalErrorStatus = STD_OK;
	u32 counter=0;
	// Enable power interface clock (needed for backup domain)
	RCC->RCC_APB1ENR |= (1 << 28);

	// Enable access to backup domain (DBP bit in PWR_CR)
	PWR->PWR_CR |= (1 << 8);

	//check CLK on or off
	if( RTCStatus ==RCC_Enable){
       //enable RTC CLOCK
		RCC->RCC_CSR |=(1<<15);
		switch( RTCSrc){

		case RCC_RTC_LSI:
			//set on LSI BIT
			RCC->RCC_CSR |=(1<<0);
			//wait for Flag
			while(!( RCC->RCC_CSR &(1<<1))){
				counter++;
				if(counter> TIMEOUT_LSI ){
					LocalErrorStatus = STD_NOK;
					break;
				}
			}
			//clear 2 Bits[8,9] for RTC selection
			(RCC->RCC_BDCR)&=~(0b11<<8);
			//set RTC_LSI as Clock Source for RTC
			(RCC->RCC_BDCR)|=(0b10<<8);

			break;
		case RCC_RTC_LSE:

			//set on LSE BIT
			RCC->RCC_BDCR |=(1<<0);
			//wait for Flag
			while(!( RCC->RCC_BDCR &(1<<1))){
				counter++;
				if(counter> TIMEOUT_LSE ){
					LocalErrorStatus = STD_NOK;
					break;
				}
			}
			//clear 2 Bits[8,9] for RTC selection
			(RCC->RCC_BDCR)&=~(0b11<<8);
			//set RTC_LSE as Clock Source for RTC
			(RCC->RCC_BDCR)|=(0b01<<8);


			break;
		case RCC_RTC_HSE_DIV_128:
			//set pin 16 in CR to enable HSE
			RCC->RCC_CR |=(1<<16);
			while(!(RCC->RCC_CR&(1<<17))){
				counter++;
				if(counter>TIMEOUT_HSE){
					LocalErrorStatus = STD_NOK;
					break;
				}
			}
			//clear 2 Bits[8,9] for RTC selection
			(RCC->RCC_BDCR)&=~(0b11<<8);
			//set HSE_DIV_128 as Clock Source for RTC
			(RCC->RCC_BDCR)|=(0b11<<8);


			break;
		default:
			LocalErrorStatus=STD_NOK;
			break;


		}

	}else if(RTCStatus==RCC_Disable){
		// Disable RTC clock
		 RCC->RCC_BDCR &= ~(1 << 15);
		switch(RTCSrc){

		case RCC_RTC_LSI:
			//Clear LSI BIT
			RCC->RCC_CSR&=~(1<<0);

			break;
		case  RCC_RTC_LSE:

			//Clear  LSE BIT
			RCC->RCC_BDCR &=~(1<<0);

		case RCC_RTC_HSE_DIV_128:
			//set pin 16 in CR to enable HSE
			RCC->RCC_CR &=~(1<<16);
			break;
		default:
			LocalErrorStatus=STD_NOK;

		}
	}

	return  LocalErrorStatus;;

}
//function to enable peripheral that inside AHB REG
void RCCF_AHBEnableClock(RCCF_AHB_Periph_t peripheral){
	RCC->RCC_AHBENR |=(1<<peripheral);

}
//function to disable peripheral that inside AHB REG
void RCCF_AHBDisableClock(RCCF_AHB_Periph_t peripheral){

	RCC->RCC_AHBENR &=~(1<<peripheral);

}
//function to enable peripheral that inside APB1 REG
void RCCF_APB1EnableClock(RCCF_APB1_Periph_t peripheral){
	RCC->RCC_APB1ENR |=(1<<peripheral);

}
//function to disable peripheral that inside APB REG
void RCCF_APB1DisableClock(RCCF_APB1_Periph_t peripheral){
	RCC->RCC_APB1ENR &=~(1<<peripheral);

}

//function to enable peripheral that inside APB2 REG

void RCCF_APB2EnableClock(RCCF_APB2_Periph_t peripheral){

	RCC->RCC_APB2ENR |=(1<<peripheral);

}
//function to disable peripheral that inside APB2 REG
void RCCF_APB2DisableClock(RCCF_APB2_Periph_t peripheral){


	RCC->RCC_APB2ENR &=~(1<<peripheral);

}

