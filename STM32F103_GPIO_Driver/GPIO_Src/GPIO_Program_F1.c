

/**
 ******************************************************************************
 * @file           : GPIO_Program.c
 * @author         : Amany_Elsedawy
 * @version        : 0.0
 * @date           : 10-12-2025
 * @brief          : PROGRAM file for GPIO driver
 * @note           : Built for STM32F103Cxtx
 ******************************************************************************
 */

#include<stdint.h>
#include"STD_TYPE.h"
/*Stm32F446xx Library*/
#include"Stm32F103LIB.h"
/*GPIO_FILES*/
#include"GPIO_Interface_F1.h"
#include"GPIO_Private_F1.h"

/**
 ******************************************************************************
 *@fn GPIO_u8PimInit
 *@brief the function initializes the GPIO pin according to the input parameters
 *@parameter[in] PinConfig :the initialization values of the pin
 *@retval ErrorStatus
 ******************************************************************************
 */
/*create array of pointer to structure that have GPIO_PORTS as pointer to REG Structure*/
static GPIO_RegDef_t* const GPIO_PORTS[GPIOF1_Peripheral_Num]={ GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF, GPIOG};
/*implement INIT Function*/
uint8_t  GPIO_u8PinInit_F1(const GPIO_pinConfig_F1_t* PinConfig ){
	/*define Local ERROR Status*/
	uint8_t LocalErrorStatus=STD_OK;
	if(PinConfig !=NULL){

		if(((PinConfig->Port_F1) <=PORTG_F1) && ((PinConfig->PinNum_F1)<=PIN15_F1)){
			/*init port of the pin*/
			GPIO_RegDef_t* GPIOx=	GPIO_PORTS[PinConfig->Port_F1];

			uint8_t Local_u8RegNum=(PinConfig->PinNum_F1)/ 8u;
			uint8_t Local_u8BitNum=(PinConfig->PinNum_F1) % 8;
			/*clear CR reg */
			(GPIOx->CR[Local_u8RegNum])&=~(CR_MASK<<(Local_u8BitNum*CR_PIN_ACCESS ));
			if((PinConfig->Mode_F1) == OUTPUT_F1){
				/*access output by speed direct*/
				(GPIOx->CR[Local_u8RegNum])|=((PinConfig-> Speed_F1)<<(Local_u8BitNum*CR_PIN_ACCESS));
				/*access output configurations in CFNy*/
				(GPIOx->CR[Local_u8RegNum])|=((PinConfig->OutPutType_F1)<<((Local_u8BitNum*CR_PIN_ACCESS)+CNF_PIN_ACCESS));


			}else if((PinConfig->Mode_F1) == INPUT_F1){
				/*access input as mode */
				(GPIOx->CR[Local_u8RegNum])|=((PinConfig->Mode_F1)<<(Local_u8BitNum*CR_PIN_ACCESS));
				/*access input configuration in CNFy*/
				(GPIOx->CR[Local_u8RegNum])|=((PinConfig-> InPutType_F1)<<((Local_u8BitNum*CR_PIN_ACCESS)+CNF_PIN_ACCESS));
			}


		}else{
			LocalErrorStatus=STD_NOK;
		}
	}else{
		LocalErrorStatus=NULL_PTR_ERR;
	}
	return LocalErrorStatus;

}
/**
 ******************************************************************************
 *@fn GPIO_u8SetPinValue
 *@brief the function output certain value on an output pin
 *@parameter[in] Port:the port number, get options @Port_t enum
 *@parameter[in] PinNum:the Pin number, get options @Pin_t enum
 *@parameter[in] PinVal:the output value, get options @PinVal_t enum
 *@retval ErrorStatus
 ******************************************************************************
 */
uint8_t   GPIO_u8SetPinValue_F1(GPIO_Port_F1_t Port, GPIO_Pin_F1_t PinNum,GPIO_PinVal_F1_t Pin_Val){


	/*define Local ERROR Status*/
	uint8_t LocalErrorStatus=STD_OK;
	if (Port >PORTG_F1 || PinNum > PIN15_F1 )
	{
		LocalErrorStatus = STD_NOK;
	}else{
		/*init port of the pin*/
		GPIO_RegDef_t* GPIOx=	GPIO_PORTS[Port];
		if(Pin_Val == PIN_LOW_F1){
			/*clear bit value from BITS 16:31 in BSRR register*/
			GPIOx->BSRR=(1U<< (PinNum+16));

		}else if(Pin_Val ==PIN_HIGH_F1 ){
			/*set bit value from BITS 0:15 in BSRR register*/
			GPIOx->BSRR=(1<< PinNum);//how to make sure put 1 here
		}
	}
	return LocalErrorStatus;
}

/**
 ******************************************************************************
 *@fn GPIO_u8TogglePinValue
 *@brief the function Toggle Output value
 *@parameter[in] Port:the port number, get options @Port_t enum
 *@parameter[in] PinNum:the Pin number, get options @Pin_t enum
 *@retval ErrorStatus
 ******************************************************************************
 */
uint8_t   GPIO_u8TogglePinValue_F1(GPIO_Port_F1_t Port, GPIO_Pin_F1_t PinNum){
	/*define Local ERROR Status*/
		uint8_t LocalErrorStatus=STD_OK;

		if (Port>PORTG_F1 || PinNum>PIN15_F1)
		{
			LocalErrorStatus = STD_NOK;
		}else{
			/*init port of the pin*/
			GPIO_RegDef_t* GPIOx=GPIO_PORTS[Port];
			GPIOx->ODR ^=(1U<< PinNum);

		}
		return LocalErrorStatus;



}

/**
 ******************************************************************************
 *@fn GPIO_u8ReadPinValue
 *@brief the function Read  value
 *@parameter[in] Port:the port number, get options @Port_t enum
 *@parameter[in] PinNum:the Pin number, get options @Pin_t enum
 *@parameter[in] pointer:the pointer ,get options @* Pin_Val enum
 *@retval ErrorStatus
 ******************************************************************************
 */
uint8_t   GPIO_u8ReadPinValue_F1(GPIO_Port_F1_t Port, GPIO_Pin_F1_t PinNum,GPIO_PinVal_F1_t* Pin_Val){
	/*define Local ERROR Status*/
		uint8_t LocalErrorStatus=STD_OK;

		if (Pin_Val == NULL || PinNum>PIN15_F1)
		{
			LocalErrorStatus = STD_NOK;
		}else{


			GPIO_RegDef_t* GPIOx=	GPIO_PORTS[Port];

			*Pin_Val=(GPIO_PinVal_F1_t)((GPIOx->IDR >> PinNum)&0x01);

		}
		return LocalErrorStatus;

}
