/*
 * pwm_try.c
 *
 *  Created on: 14 Şub 2020
 *      Author: acakbudak
 */

#include "stm32f446re.h"


void delay(void)
{
	for(uint32_t i = 0 ; i < 100000/2 ; i ++);
}


int main(void)
{
	pwm_init();
	pwm_tim4_ch1_init();

	while(1)
	{
		for(uint16_t i=0; i<60000; i=i+100)
		{
		pwm_load(30000,i);
		delay();
		}

	}
	return 0;
}
