/**
 ******************************************************************************
 * @file           : F103RCC_Interface.h
 * @author         : Amany_Elsedawy
 * @version        : 0.0
 * @date           : 14-10-2025
 * @brief          : Interface file for RCC driver
 * @note           : Built for STM32F103C8T6
 ******************************************************************************
 */

#ifndef STM32F103_RCC_Interface_H
#define STM32F103_RCC_Interface_H

//include STD library
#include"STD_TYPE.h"

#define TIMEOUT_HSI    500
#define TIMEOUT_HSE    1000
#define TIMEOUT_PLL    2000
#define TIMEOUT_LSE    10000
#define TIMEOUT_LSI    10000


#define HSI_CLK     0b00
#define HSE_CLK     0b01
#define PLL_CLK     0b10





typedef enum{

	RCC_HSI,
	RCC_HSE,
	RCC_HSE_BYP,
	RCC_PLL


}RCCF_ClockSource_t;

typedef enum{

	RCC_RTC_LSI,
	RCC_RTC_LSE,
	RCC_RTC_HSE_DIV_128


}RCCF_RTCSource_t;

typedef enum{

	RCC_Enable,
	RCC_Disable

}RCCF_ClockStatus_t;


typedef enum {
	RCC_PLL_MUL2 = 0b0000,
	RCC_PLL_MUL3 = 0b0001,
	RCC_PLL_MUL4 = 0b0010,
	RCC_PLL_MUL5 = 0b0011,
	RCC_PLL_MUL6 = 0b0100,
	RCC_PLL_MUL7 = 0b0101,
	RCC_PLL_MUL8 = 0b0110,
	RCC_PLL_MUL9 = 0b0111,
	RCC_PLL_MUL10 = 0b1000,
	RCC_PLL_MUL11 = 0b1001,
	RCC_PLL_MUL12 = 0b1010,
	RCC_PLL_MUL13 = 0b1011,
	RCC_PLL_MUL14 = 0b1100,
	RCC_PLL_MUL15 = 0b1101,
	RCC_PLL_MUL16 = 0b1110
} PLL_Mul_t;



typedef enum{
	RCC_HSI_DIV_2,
	RCC_HSE_DIV_1,
	RCC_HSE_DIV_2

}RCCF_PLLSrc_DIV_t;


// enum for AHB Peripheral
typedef enum{

	RCC_AHB_DMA1    = 0,   // Bit 0: DMA1 clock enable
	RCC_AHB_DMA2    = 1,   // Bit 1: DMA2 clock enable
	RCC_AHB_SRAM    = 2,   // Bit 2: SRAM interface clock enable
	// Bit 3 Reserved
	RCC_AHB_FLITF   = 4,   // Bit 4: FLITF clock enable
	// Bit 5 Reserved
	RCC_AHB_CRC     = 6,   // Bit 6: CRC clock enable
	// Bits 7:11 Reserved
	RCC_AHB_OTGFS   = 12,  // Bit 12: USB OTG FS clock enable
	// Bit 13 Reserved
	RCC_AHB_ETHMAC  = 14,  // Bit 14: Ethernet MAC clock enable
	RCC_AHB_ETHMACTX= 15,  // Bit 15: Ethernet MAC TX clock enable
	RCC_AHB_ETHMACRX= 16   // Bit 16: Ethernet MAC RX clock enable
	// Bits 17:31 Reserved


}RCCF_AHB_Periph_t;



// enum for APB1 Peripheral
typedef enum{
  RCC_APB1_TIM2EN= 0,//: Timer 2 clock enable
  RCC_APB1_TIM3EN= 1,//: Timer 3 clock enable
  RCC_APB1_TIM4EN= 2,//: Timer 4 clock enable
  RCC_APB1_TIM5EN= 3,//: Timer 5 clock enable
  RCC_APB1_TIM6EN= 4,//: Timer 6 clock enable
  RCC_APB1_TIM7EN= 5,//: Timer 7 clock enable
  //Bits 6:10 Reserved
  RCC_APB1_WWDGEN= 11,//: Window watchdog clock enable
  //Bits 12:13 Reserved
  RCC_APB1_SPI2EN= 14,//:  SPI 2 clock enable
  RCC_APB1_SPI3EN= 15,//:  SPI 3 clock enable
  //Bits 16 Reserved
  RCC_APB1_USART2EN= 17,//:  USART 2 clock enable
  RCC_APB1_USART3EN= 18,//:  USART 3 clock enable
  RCC_APB1_USART4EN= 19,//:  USART 4 clock enable
  RCC_APB1_USART5EN= 20,//:  USART 5 clock enable
  RCC_APB1_I2C1EN= 21,//:  I2C 1 clock enable
  RCC_APB1_I2C2EN= 22,//:  I2C 2 clock enable
  //Bits 23:24 Reserved
  RCC_APB1_CAN1EN=25,//: CAN1 clock enable
  RCC_APB1_CAN2EN=26,//: CAN2 clock enable
  RCC_APB1_BKPEN=27,//: Backup interface clock enable
  RCC_APB1_PWREN=28,//: Power interface clock enable
  RCC_APB1_DACEN=29//: DAC interface clock enable
//Bits 30:31 Reserved
}RCCF_APB1_Periph_t;

typedef enum
{
    RCC_APB2_AFIOEN   = 0,   // Alternate function I/O clock enable
    // Bit 1 Reserved
    RCC_APB2_IOPAEN   = 2,   // I/O port A clock enable
    RCC_APB2_IOPBEN   = 3,   // I/O port B clock enable
    RCC_APB2_IOPCEN   = 4,   // I/O port C clock enable
    RCC_APB2_IOPDEN   = 5,   // I/O port D clock enable
    RCC_APB2_IOPEEN   = 6,   // I/O port E clock enable
    // Bits 7-8 Reserved
    RCC_APB2_ADC1EN   = 9,   // ADC1 clock enable
    RCC_APB2_ADC2EN   = 10,  // ADC2 clock enable
    RCC_APB2_TIM1EN   = 11,  // TIM1 clock enable
    RCC_APB2_SPI1EN   = 12,  // SPI1 clock enable
    // Bit 13 Reserved
    RCC_APB2_USART1EN = 14   // USART1 clock enable
    // Bits 15-31 Reserved
} RCCF_APB2_Periph_t;


//function prototype to Enable/Disable CLK and set CLK source

u8 RCCF_SetClk(RCCF_ClockSource_t ClkSrc, RCCF_ClockStatus_t ClkStatus);

//function prototype to select system Clock(HSI / HSE / PLL)

u8 RCCF_SetSystemClock(RCCF_ClockSource_t ClkSrc);


//function prototype to set PLL configuration
u8 RCCF_PLLConfig(PLL_Mul_t PLLMull,RCCF_PLLSrc_DIV_t PllSrc);

//function prototype to Enable/Disable RTC CLK and set RTC CLK source
u8 RCCF_SetRTC_Clock(RCCF_RTCSource_t RTCSrc,RCCF_ClockStatus_t RTCStatus );

void RCCF_AHBEnableClock(RCCF_AHB_Periph_t peripheral);
void RCCF_AHBDisableClock(RCCF_AHB_Periph_t peripheral);

void RCCF_APB1EnableClock(RCCF_APB1_Periph_t peripheral);
void RCCF_APB1DisableClock(RCCF_APB1_Periph_t peripheral);


void RCCF_APB2EnableClock(RCCF_APB2_Periph_t peripheral);
void RCCF_APB2DisableClock(RCCF_APB2_Periph_t peripheral);


#endif
