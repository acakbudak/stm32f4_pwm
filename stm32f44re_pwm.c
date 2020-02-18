/*
 * stm32f44re_pwm.c
 *
 *  Created on: 14 Şub 2020
 *      Author: acakbudak
 */

#include "stm32f44re_pwm.h"


//gpio port B configurations for tim4 channel 1 output
void pwm_tim4_ch1_init(void)
{
	RCC->AHB1ENR |= (1 << 1);

	GPIOB->MODER |= (2 << 12);
	GPIOB->PUPDR &= ~(1 << 12);
	GPIOB->OSPEEDR |= (2 << 12);
	GPIOB->AFR[0] |= (2 << 24);

}

//implemention of tim4
void pwm_init(void)
{
	RCC->APB1ENR |= (1 << 2);


	TIM4->CR1 |= (1 << 0);
	TIM4->CR1 &= ~(1 << 4);
	TIM4->CR1 &= ~(3 << 5);


	TIM4->EGR |= (1 << 0);

	TIM4->CCER &= ~(1 << 0);  // disable cc1
	TIM4->CCMR1 &= ~(1 << 0);
	TIM4->CCMR1 |= (6 << 4);
	TIM4->CCMR1 |= (1 << 3);

	TIM4->CCER &= ~(1 << 1);
	TIM4->CCER |= (1 << 0); 	// enable cc1


}

/*
 * the pwm signal changes with the value of arr and ccr1
 */
void pwm_load(uint16_t arr, uint16_t ccr1)
{
	//TIM4->PSC=psc;
	TIM4->ARR = arr;
	TIM4->CCR1 = ccr1;

}
