#include "stm32f10x.h"                  // Device header

/*
	PWM频率：Frequency = CK_PSC/(PSC+1)/(ARR+1)
	PWM占空比：Duty = CCR/(ARR+1)
	PWM分辨率：Reso = 1/(ARR+1)
*/
void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruture;
	GPIO_InitStruture.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruture.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruture.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruture);
	
	TIM_InternalClockConfig(TIM2);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 100 -1;		//ARR 周期
	TIM_TimeBaseInitStructure.TIM_Prescaler = 720 -1;		//PSC 预装值
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);
	
	TIM_OCInitTypeDef TIM_OCInitStrusture;
	TIM_OCStructInit(&TIM_OCInitStrusture);

	TIM_OCInitStrusture.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStrusture.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStrusture.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStrusture.TIM_Pulse = 0;		//CCR 
	TIM_OC1Init(TIM2,&TIM_OCInitStrusture);
	
	TIM_Cmd(TIM2,ENABLE);
}

void PWM_SetCompare1(uint16_t Compare)
{
	TIM_SetCompare1(TIM2,Compare);
}
