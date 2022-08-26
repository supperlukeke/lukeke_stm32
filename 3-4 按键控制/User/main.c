#include "stm32f10x.h"                  // Device header
#include "LED.h"
#include "Key.h"

uint8_t KeyNum,Count;

int main(void)
{
	LED_Init();
	Key_Init();
	LED_Set(0,0);
	while(1)
	{
		KeyNum = Key_Get_Num();
		if(KeyNum == 2)
		{
			LED_Set(Count,1);
			Count++;
			if(Count>6)
			{
				LED_Set(Count,1);
				Count = 0;
			}
			LED_Set(Count,0);
		}
		if(KeyNum == 1)
		{
			if(Count==0)
			{
				LED_Set(Count,1);
				Count = 7;
			}
			LED_Set(Count,1);
			Count--;
			LED_Set(Count,0);
		}
	}
}
