 /******************************************************************************
 *
 * Module		: Timer0 PWM
 *
 * File Name	: pwm.c
 *
 * Description	: source file for the pwm driver - MCAL Layer
 *
 * Author		: Erini Sabry
 *
 * Date Created	: 011.10.2022
 *
 *******************************************************************************/


/*******************************************************************************
 *                                Linking Section - INCLUDES
 *******************************************************************************/
#include "pwm.h"
#include "gpio.h"
#include "avr/io.h"

/*******************************************************************************
 *                                Functions Definition
 *******************************************************************************/

/*******************************************************************************
 * Function Name: Timer0_PWM_Mode_Init
 *
 * Description :
 * 		initializes Timer 0 PWM Mode
 *
 * Parameters:
 * 		uint8DutyCycle: integer value to set the compare value
 *
 * Return: void type
 *
  *******************************************************************************/
void PWM_Timer0_Start(uint8 a_dutyCycle)
{
	TCNT0 = 0; /* Set Timer Initial Value to 0 */
	OCR0 = a_dutyCycle; //Set Compare value

	/* Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC */
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<CS01) | (1<<COM01);
}
