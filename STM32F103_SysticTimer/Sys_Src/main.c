#include <stdint.h>
#include "GPIO_Interface_F1.h"
#include"F103RCC_Interface.h"
#include"Systick_Interface.h"

/*array of structures which initialize pins*/
GPIO_pinConfig_F1_t leds[] = {
		{PORTA_F1, PIN2_F1, OUTPUT_F1, SPEED_2MHZ_F1, PUSH_PULL_F1, GPIO_INPUT_NOT_USED},
		{PORTB_F1, PIN4_F1, OUTPUT_F1, SPEED_2MHZ_F1, PUSH_PULL_F1, GPIO_INPUT_NOT_USED}
};

#define LED_COUNT  (sizeof(leds)/sizeof(leds[0]))
int main(void){

	RCCF_SetClk(RCC_HSE,RCC_Enable );
	RCCF_SetSystemClock(RCC_HSE);
	RCCF_APB2EnableClock( RCC_APB2_IOPAEN);
	RCCF_APB2EnableClock( RCC_APB2_IOPBEN);

	for(int i = 0; i < LED_COUNT; i++)
	{
		GPIO_u8PinInit_F1(&leds[i]);
	}

	while(1){

		GPIO_u8SetPinValue_F1(PORTA_F1, PIN2_F1, PIN_HIGH_F1);
		GPIO_u8SetPinValue_F1(PORTB_F1, PIN4_F1, PIN_HIGH_F1);
		Systick_DelayMS(2000);
		GPIO_u8SetPinValue_F1(PORTA_F1, PIN2_F1, PIN_LOW_F1);
		GPIO_u8SetPinValue_F1(PORTB_F1, PIN4_F1, PIN_LOW_F1);
		Systick_DelayMS(2000);


	}

}
