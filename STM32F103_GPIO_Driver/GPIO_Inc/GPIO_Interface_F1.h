
/**
 ******************************************************************************
 * @file           : GPIO_Interface.h
 * @author         : Amany_Elsedawy
 * @version        : 0.0
 * @date           : 10-12-2025
 * @brief          : Interface file for GPIO driver
 * @note           : Built for STM32NUCLEO F103CxTx
 ******************************************************************************
 */
#ifndef  GPIOF103_INTERFACE_H
#define  GPIOF103_INTERFACE_H



#include<stdint.h>


typedef enum{


	PORTA_F1=0,
	PORTB_F1,
	PORTC_F1,
	PORTD_F1,
	PORTE_F1,
	PORTF_F1,
	PORTG_F1

}GPIO_Port_F1_t;

typedef enum{



	PIN0_F1=0,
	PIN1_F1,
	PIN2_F1,
	PIN3_F1,
	PIN4_F1,
	PIN5_F1,
	PIN6_F1,
	PIN7_F1,
	PIN8_F1,
	PIN9_F1,
	PIN10_F1,
	PIN11_F1,
	PIN12_F1,
	PIN13_F1,
	PIN14_F1,
	PIN15_F1

}GPIO_Pin_F1_t;

typedef enum{


	PIN_LOW_F1=0,
	PIN_HIGH_F1

}GPIO_PinVal_F1_t;
typedef enum{

	INPUT_F1=0,
	OUTPUT_F1,

}GPIO_Mode_F1_t;


 typedef enum{

	 SPEED_10MHZ_F1 = 1,  /* 01 */
	 SPEED_2MHZ_F1  = 2,  /* 10 */
	 SPEED_50MHZ_F1 = 3   /* 11 */
	}GPIO_OutputSpeed_F1_t;


typedef enum{

	PUSH_PULL_F1=0,
	OPEN_DRAIN_F1,
	ALTERNATIVE_PUSH_PULL_F1,
	ALTERNATIVE_OPEN_DRAIN_F1,
	GPIO_OUTPUT_NOT_USED
}GPIO_OutputType_F1_t;

typedef  enum{

	 ANALOG=0,
	 FLOATING,
     PULLUP_DOWN,
	 GPIO_INPUT_NOT_USED

}GPIO_InputType_F1_t;

/***  AFIO OPTION ***/

typedef enum{

	Enable=0,
	Disable

}AFIO_EVCR_STATUS_t;

/***   OPTIONS  ***/

typedef  struct{
	GPIO_Port_F1_t Port_F1;
	GPIO_Pin_F1_t  PinNum_F1;
	GPIO_Mode_F1_t Mode_F1;
	GPIO_OutputSpeed_F1_t  Speed_F1;
	GPIO_OutputType_F1_t   OutPutType_F1;/*0push_pull,1open_drian,2altfun_pushpull,3altfun_opendrain*/
	GPIO_InputType_F1_t    InPutType_F1;/*0analog,1floating,2pullup_down*/

}GPIO_pinConfig_F1_t;

/***** GPIO   Function Prototype    ******/

uint8_t  GPIO_u8PinInit_F1( const GPIO_pinConfig_F1_t* PinConfig );

uint8_t   GPIO_u8SetPinValue_F1(GPIO_Port_F1_t Port, GPIO_Pin_F1_t PinNum,GPIO_PinVal_F1_t Pin_Val);

uint8_t   GPIO_u8TogglePinValue_F1(GPIO_Port_F1_t Port, GPIO_Pin_F1_t PinNum);

uint8_t   GPIO_u8ReadPinValue_F1(GPIO_Port_F1_t Port, GPIO_Pin_F1_t PinNum,GPIO_PinVal_F1_t* Pin_Val);

/***** AFIO   Function Prototype    ******/
/*
void AFIO_DIS_EnableEventOut(uint8_t port, uint8_t pin ,AFIO_EVCR_STATUS_t Status);
void AFIO_Remap(uint8_t peripheral, uint8_t remap_type);
void AFIO_ConfigEXTI(uint8_t exti_line, uint8_t port);
*/

#endif
