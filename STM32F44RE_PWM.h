/*
 * stm32f44re_pwm.h
 *
 *  Created on: 14 Şub 2020
 *      Author: acakbudak
 */

#ifndef INC_STM32F44RE_PWM_H_
#define INC_STM32F44RE_PWM_H_


#include "stm32f446re.h"


#define TIM4_BASE      0x40000800U

#define TIM4	((TIM_Reg_Def*)TIM4_BASE)

typedef struct
{
	__vo uint32_t	CR1;
	__vo uint32_t	CR2;
	__vo uint32_t	SMCR;
	__vo uint32_t	DIER;
	__vo uint32_t	SR;
	__vo uint32_t	EGR;
	__vo uint32_t	CCMR1;
	__vo uint32_t	CCMR2;
	__vo uint32_t	CCER;
	__vo uint32_t	CNT;
	__vo uint32_t	PSC;
	__vo uint32_t	ARR;
	 	 uint32_t	RES1;
	__vo uint32_t	CCR1;
	__vo uint32_t	CCR2;
	__vo uint32_t	CCR3;
	__vo uint32_t	CCR4;
		 uint32_t	RES2;
	__vo uint32_t	DCR;
	__vo uint32_t	DMAR;
	__vo uint32_t	OR;


}TIM_Reg_Def;


void pwm_init(void);
void pwm_tim4_ch1_init(void);
void pwm_load(uint16_t arr, uint16_t ccr1);


#endif /* INC_STM32F44RE_PWM_H_ */
