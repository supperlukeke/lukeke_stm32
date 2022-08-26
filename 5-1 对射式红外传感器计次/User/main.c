#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "CountSensor.h"

int main(void)
{
	OLED_Init();
	CountSensor_Init();
	OLED_ShowString(1,1,"Count:");
	while(1)
	{
		OLED_ShowNum(1,7,CountSensor_Count,5);
	}
}
