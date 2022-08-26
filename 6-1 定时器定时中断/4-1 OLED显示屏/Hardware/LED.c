#include "stm32f10x.h"                  // Device header

/**
  *  @brief    LED端口初始化，A0~A6口
  *  @param	   无
  *  @retval   无
  */

void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_SetBits(GPIOA,GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6);
}

/**
  *  @brief    控制6位LED的亮灭
  *  @param	   Loacation    要亮的灯对应的端口号
*  @param	   State	 	LED的状态，0为亮，1为灭
  *  @retval
  */

void LED_Set(uint8_t Location,uint8_t State)
{
	if(State)
	{
		switch(Location)
		{
			case 0: GPIO_SetBits(GPIOA,GPIO_Pin_0);break;
			case 1: GPIO_SetBits(GPIOA,GPIO_Pin_1);break;
			case 2: GPIO_SetBits(GPIOA,GPIO_Pin_2);break;
			case 3: GPIO_SetBits(GPIOA,GPIO_Pin_3);break;
			case 4: GPIO_SetBits(GPIOA,GPIO_Pin_4);break;
			case 5: GPIO_SetBits(GPIOA,GPIO_Pin_5);break;
			case 6: GPIO_SetBits(GPIOA,GPIO_Pin_6);break;
		}
	}
	else
	{
		switch(Location)
		{
			case 0: GPIO_ResetBits(GPIOA,GPIO_Pin_0);break;
			case 1: GPIO_ResetBits(GPIOA,GPIO_Pin_1);break;
			case 2: GPIO_ResetBits(GPIOA,GPIO_Pin_2);break;
			case 3: GPIO_ResetBits(GPIOA,GPIO_Pin_3);break;
			case 4: GPIO_ResetBits(GPIOA,GPIO_Pin_4);break;
			case 5: GPIO_ResetBits(GPIOA,GPIO_Pin_5);break;
			case 6: GPIO_ResetBits(GPIOA,GPIO_Pin_6);break;
		}
	}
}

/**
  *  @brief    LED状态取反，通过读取输出寄存器的值
  *  @param	   无
  *  @retval   无
  */

void LED_Turn(void)
{
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_0) == 0)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_0);
	}
	else
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_0);
	}
}
