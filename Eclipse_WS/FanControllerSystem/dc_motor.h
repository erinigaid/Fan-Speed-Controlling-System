 /******************************************************************************
 *
 * Module		: DC Motor
 *
 * File Name	: dc_motor.h
 *
 * Description	: header file for the DC Motor driver - HAL Layer
 *
 * Author		: Erini Sabry
 *
 * Date Created	: 011.10.2022
 *
 *******************************************************************************/


/* Header file guard */
#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_


/*******************************************************************************
 *                                Linking Section - INCLUDES
 *******************************************************************************/

#include "std_types.h"
#include "gpio.h"


/*******************************************************************************
 *                                Definitions & Configurations
 *******************************************************************************/

#define DCMOTOR_MAX_SPEED 		100

#define DCMOTOR_PORT 	  		PORTB_ID
#define DCMOTOR_INP1_PIN		PIN1_ID /*DC H-Bridge input pin 1*/
#define DCMOTOR_INP2_PIN 		PIN2_ID /*DC H-Bridge input pin 2*/
#define DCMOTOR_EN_PIN			PIN3_ID


/*******************************************************************************
 *                               Types Declaration
 *******************************************************************************/

typedef enum
{
	MOTOR_STOP , MOTOR_CW, MOTOR_ACW
}DcMotor_State;

/*******************************************************************************
 *                              Functions Prototype
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
void DcMotor_init(void);

/*******************************************************************************
 * Function Name: DcMotor_Rotate
 *
 * Description :
 * 		reading a digital value from a specific ADC channel
 *
 * Parameters:
 * 		uint8 channel_num integer value to specify the channel number to read in the ADC
 *
 * Return:
 * 		uint16 ADC the converted data in digital form
 *
  *******************************************************************************/
void DcMotor_rotate(DcMotor_State state,uint8 a_speed);

#endif /* DC_MOTOR_H_ */

