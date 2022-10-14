/******************************************************************************
 *
 * Module		: DC Motor
 *
 * File Name	: dc_motor.c
 *
 * Description	: source file for the DC Motor driver - HAL Layer
 *
 * Author		: Erini Sabry
 *
 * Date Created	: 011.10.2022
 *
 *******************************************************************************/


/*******************************************************************************
 *                                Linking Section - INCLUDES
 *******************************************************************************/

#include "dc_motor.h"
#include "pwm.h"

/*******************************************************************************
 *                                Functions Definition
 *******************************************************************************/


/*******************************************************************************
 * Function Name: DcMotor_Init
 *
 * Description :
 * 		initializes the ADC
 *
 * Parameters:
 * 		const ADC_ConfigType * Config_Ptr: const ptr to struct
 *
 * Return: void type
 *
  *******************************************************************************/
void DcMotor_init(void)
{
	GPIO_setupPinDirection(DCMOTOR_PORT,DCMOTOR_EN_PIN,PIN_INPUT);

	GPIO_setupPinDirection(DCMOTOR_PORT,DCMOTOR_INP1_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(DCMOTOR_PORT,DCMOTOR_INP2_PIN,PIN_OUTPUT);

	GPIO_writePin(DCMOTOR_PORT,DCMOTOR_INP1_PIN,LOGIC_LOW);
	GPIO_writePin(DCMOTOR_PORT,DCMOTOR_INP2_PIN,LOGIC_LOW);
}

/*******************************************************************************
 * Function Name: DcMotor_Rotate
 *
 * Description :
 * 		rotating the dc motor in a specific direction
 *
 * Parameters:
 * 		DCMotor_State state: to control the state of the motor
 * 		uint8 a_speed: a variable to control the speed of the motor
 *
 * Return: void
 *
  *******************************************************************************/
void DcMotor_rotate(DcMotor_State state,uint8 a_speed)
{
	uint8 dutyCycle = ((float32) a_speed / DCMOTOR_MAX_SPEED) * TIMER0_TOP_VALUE;
	switch (state)
	{
	case MOTOR_STOP:
		GPIO_writePin(DCMOTOR_PORT,DCMOTOR_INP1_PIN,LOGIC_LOW);
		GPIO_writePin(DCMOTOR_PORT,DCMOTOR_INP2_PIN,LOGIC_LOW);
		break;

	case MOTOR_CW:
		GPIO_writePin(DCMOTOR_PORT,DCMOTOR_INP1_PIN,LOGIC_LOW);
		GPIO_writePin(DCMOTOR_PORT,DCMOTOR_INP2_PIN,LOGIC_HIGH);
		break;

	case MOTOR_ACW:
		GPIO_writePin(DCMOTOR_PORT,DCMOTOR_INP1_PIN,LOGIC_HIGH);
		GPIO_writePin(DCMOTOR_PORT,DCMOTOR_INP2_PIN,LOGIC_LOW);
		break;
	}
		PWM_Timer0_Start(dutyCycle);

}
