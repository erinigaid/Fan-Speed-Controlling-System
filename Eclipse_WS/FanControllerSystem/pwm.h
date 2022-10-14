 /******************************************************************************
 *
 * Module		: Timer0 PWM
 *
 * File Name	: pwm.h
 *
 * Description	: header file for the pwm driver - MCAL Layer
 *
 * Author		: Erini Sabry
 *
 * Date Created	: 011.10.2022
 *
 *******************************************************************************/


/* Header file guard */
#ifndef PWM_H_
#define PWM_H_


/*******************************************************************************
 *                                Linking Section - INCLUDES
 *******************************************************************************/
#include "std_types.h"
/*******************************************************************************
 *                                Definitions & Configurations
 *******************************************************************************/
#define TIMER0_TOP_VALUE (0xFF)

/*******************************************************************************
 *                              Functions Prototype
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
void PWM_Timer0_Start(uint8 DutyCycle);

#endif /* PWM_H_ */

