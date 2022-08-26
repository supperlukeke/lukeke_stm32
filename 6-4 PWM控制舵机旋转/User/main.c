#include "stm32f10x.h"                  // Device header
#include "Key.h"
#include "Servo.h"
#include "OLED.h"

uint8_t KeyNum;
float Angle;

int main(void)
{
	Servo_Init();
	Key_Init();
	OLED_Init();
	
	OLED_ShowString(1,1,"Angle:");
	
	while(1)
	{
		KeyNum = Key_Get_Num();
		if(KeyNum == 1)
		{
			Angle += 30;
			if(Angle > 180)
			{
				Angle = 0;
			}
		}
		Servo_SetAngle(Angle);
		OLED_ShowNum(1,7,Angle,3);
	}
}
