/**
 ******************************************************************************
 * @file           :Stm32F103LIB.h
 * @author         : Amany_Elsedawy
 * @version        : 1.0
 * @date           : 8-12-2025
 * @brief          : Register definitions for STM32F103C8T6 peripherals
 * @note           : Built for STM32F103C8T6
 ******************************************************************************
 */

#ifndef  STM32F103c8t6LIB_H
#define  STM32F103c8t6_H

#include <stdint.h>



/******     APB2   Peripheral    Base    Address     ******/
/****  RCC  Base Address  ****/
#define  RCC_BASE_ADDRESS   0x40021000
/****  PWR  Base Address  ****/
#define  PWR_BASE_ADDRESS   0x40007000
/****  GPIOx   Base Address  ****/

#define GPIOA_BASE_ADDRESS    0x40010800
#define GPIOB_BASE_ADDRESS    0x40010C00
#define GPIOC_BASE_ADDRESS    0x40011000
#define GPIOD_BASE_ADDRESS    0x40011400
#define GPIOE_BASE_ADDRESS    0x40011800
#define GPIOF_BASE_ADDRESS    0x40011C00
#define GPIOG_BASE_ADDRESS    0x40012000

/****  AFIO   Base Address  ****/
#define AFIO_BASE_ADDRESS     0x40010000

/****    Systick timer    ****/
#define SYSTICK_BASE_ADDRESS  0xE000E010

 /******     RCC  Register Definition Structure     ******/

typedef struct{

    volatile uint32_t  RCC_CR;
	volatile uint32_t  RCC_CFGR;
	volatile uint32_t  RCC_CIR;
	volatile uint32_t  RCC_APB2RSTR;
	volatile uint32_t  RCC_APB1RSTR;
	volatile uint32_t  RCC_AHBENR;
	volatile uint32_t  RCC_APB2ENR;
	volatile uint32_t  RCC_APB1ENR;
	volatile uint32_t  RCC_BDCR;
	volatile uint32_t  RCC_CSR;
	volatile uint32_t  RCC_AHBSTR;
	volatile uint32_t  RCC_CFGR2;


}RCCF_REG_t;

/*create pointer to RCC REG*/
#define  RCC         ((RCCF_REG_t*)RCC_BASE_ADDRESS)
//volatile RCCF_REG_t * const RCC = (RCCF_REG_t*)(0x40021000 );


/******     AHB   Peripheral    Base    Address     ******/

typedef struct{

volatile  uint32_t  STK_CTRL;
volatile  uint32_t  STK_LOAD;
volatile  uint32_t  STK_VAL;
volatile  uint32_t  STK_CALIB;

}Systick_RegDef_t;

#define  STK      ((Systick_RegDef_t*)SYSTICK_BASE_ADDRESS)
/******     POWER  Register Definition Structure     ******/
typedef struct
{
    volatile uint32_t  PWR_CR;     // Power control register        (offset 0x00)
    volatile uint32_t  PWR_CSR;    // Power control/status register (offset 0x04)
   }PWR_REG_t;
   /******     APB1   Peripheral    Base    Address     ******/
   /*create pointer to RCC REG*/
#define  PWR   ((PWR_REG_t*)PWR_BASE_ADDRESS)

  // volatile PWR_REG_t * const PWR = (PWR_REG_t*)( 0x40007000);



   /******     GPIO  Register Definition Structure     ******/
   typedef struct{


	   volatile uint32_t CR[2];
       volatile uint32_t IDR;
	   volatile uint32_t ODR;
	   volatile uint32_t BSRR;
       volatile uint32_t BRR;
	   volatile uint32_t LCKR;

 }GPIO_RegDef_t;
   /******     AFIO  Register Definition Structure     ******/

typedef struct{

	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t MAPR2;





}AFIO_RegDef_t;



   /******     GPIO  peripheral Definition     ******/




   #define  GPIOA         ((GPIO_RegDef_t*)GPIOA_BASE_ADDRESS)
   #define  GPIOB         ((GPIO_RegDef_t*)GPIOB_BASE_ADDRESS)
   #define  GPIOC         ((GPIO_RegDef_t*)GPIOC_BASE_ADDRESS)
   #define  GPIOD         ((GPIO_RegDef_t*)GPIOD_BASE_ADDRESS)
   #define  GPIOE         ((GPIO_RegDef_t*)GPIOE_BASE_ADDRESS)
   #define  GPIOF         ((GPIO_RegDef_t*)GPIOF_BASE_ADDRESS)
   #define  GPIOG         ((GPIO_RegDef_t*)GPIOG_BASE_ADDRESS)

/******    AFIO Peripheral Definition    ******/
#define     AFIO           ((AFIO_RegDef_t*)AFIO_BASE_ADDRESS)


#endif
