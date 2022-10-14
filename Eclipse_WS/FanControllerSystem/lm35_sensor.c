 /******************************************************************************
 *
 * Module		: LM32 Temperature Sensor
 *
 * File Name	: lm32_sensor.c
 *
 * Description	: source file for the lm32 sensor driver - HAL Layer
 *
 * Author		: Erini Sabry
 *
 * Date Created	: 011.10.2022
 *
 *******************************************************************************/


/*******************************************************************************
 *                                Linking Section - INCLUDES
 *******************************************************************************/
#include "lm35_sensor.h"
#include "adc.h"

/*******************************************************************************
 *                                Functions Definition
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
uint8 LM35_getTemperature(void)
{
	uint8 tempValue = 0;

	uint16 adcValue = 0;

	/* Read ADC channel where the temperature sensor is connected */
	adcValue = ADC_readChannel(SENSOR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value*/
	tempValue = (uint8)(((uint32)adcValue * SENSOR_MAX_TEMPERATURE * ADC_REF_VOLTAGE)/(ADC_MAX_VALUE * SENSOR_MAX_VOLT_VALUE));

	return tempValue;
}
