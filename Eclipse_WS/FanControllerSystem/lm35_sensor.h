 /******************************************************************************
 *
 * Module		: LM32 Temperature Sensor
 *
 * File Name	: lm32_sensor.h
 *
 * Description	: header file for the lm32 sensor driver - HAL Layer
 *
 * Author		: Erini Sabry
 *
 * Date Created	: 011.10.2022
 *
 *******************************************************************************/


/* Header file guard */
#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_


/*******************************************************************************
 *                                Linking Section - INCLUDES
 *******************************************************************************/
#include "std_types.h"

/*******************************************************************************
 *                                Definitions & Configurations
 *******************************************************************************/
#define SENSOR_CHANNEL_ID         2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

/*******************************************************************************
 *                              Functions Prototype
 *******************************************************************************/

/*******************************************************************************
 * Function Name: LM35_getTemperature
 *
 * Description :
 * 		calculate the temperature from the ADC digital value.
 *
 * Parameters: void
 *
 * Return:
 * 		uint8 tempValue: return an integer value of the temperature
 *
  *******************************************************************************/
uint8 LM35_getTemperature(void);

#endif /* LM35_SENSOR_H_ */

