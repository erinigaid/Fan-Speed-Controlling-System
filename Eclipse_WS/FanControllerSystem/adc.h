/******************************************************************************
 *
 * Module		: ADC (Analog to Digital Converter)
 *
 * File Name	: adc.h
 *
 * Description	: header file for the adc driver - MCAL Layer
 *
 * Author		: Erini Sabry
 *
 * Date Created	: 06.10.2022
 *
 *******************************************************************************/

/* Header file guard */
#ifndef ADC_H_
#define ADC_H_


/*******************************************************************************
 *                                Linking Section - INCLUDES
 *******************************************************************************/
#include "std_types.h"

/*******************************************************************************
 *                                Definitions & Configurations
 *******************************************************************************/
#define ADC_MAX_VALUE   1023
#define ADC_REF_VOLTAGE 2.56
/*******************************************************************************
 *                               Types Declaration
 *******************************************************************************/

typedef enum
{
	AREF,
	AVCC,
	RESERVED,
	INTERNAL_VOLTAGE

}ADC_ReferenceVoltage;

typedef enum
{
	F_CPU_2 = 1,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128

}ADC_Prescaler;

typedef struct
{
	ADC_ReferenceVoltage ref_volt;
	ADC_Prescaler prescaler;

}ADC_ConfigType;

/*******************************************************************************
 *                              Functions Prototype
 *******************************************************************************/

/*******************************************************************************
 * Function Name: ADC_init
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
void ADC_init(const ADC_ConfigType * a_Config_Ptr);

/*******************************************************************************
 * Function Name: ADC_readChannel
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
uint16 ADC_readChannel(uint8 a_channelNum);

#endif /* ADC_H_ */

