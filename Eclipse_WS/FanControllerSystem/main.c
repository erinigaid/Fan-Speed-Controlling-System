 /******************************************************************************
 *
 * Module		: main
 *
 * File Name	: main.c
 *
 * Description	: source file for miniproject 3 - App Layer
 *
 * Author		: Erini Sabry
 *
 * Date Created	: 11.10.2022
 *
 *******************************************************************************/
#include "adc.h"
#include "dc_motor.h"
#include "lcd.h"
#include "lm35_sensor.h"

int main (void)
{
	uint8 temp = 0;

	ADC_ConfigType Configurations = {INTERNAL_VOLTAGE,F_CPU_8};
	ADC_init(&Configurations);

	LCD_init();
	LCD_moveCursor(1,3);
	LCD_displayString("Temp =    C");

	DcMotor_init();

	for(;;)
	{
		temp=LM35_getTemperature();
		LCD_moveCursor(0,3);
		if(temp < 30)
		{
			LCD_displayString("FAN is OFF");
			DcMotor_rotate(MOTOR_STOP,0);
		}

		else{
			LCD_displayString("FAN is ON ");
			if(temp >= 120)
			{

				DcMotor_rotate(MOTOR_CW,100);
			}
			else if(temp >= 90)
			{
				DcMotor_rotate(MOTOR_CW,75);
			}
			else if(temp >= 60)
			{
				DcMotor_rotate(MOTOR_CW,50);
			}
			else if(temp >= 30)
			{
				DcMotor_rotate(MOTOR_CW,25);
			}
		}

		LCD_moveCursor(1,10);
		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
		}
	}
}
