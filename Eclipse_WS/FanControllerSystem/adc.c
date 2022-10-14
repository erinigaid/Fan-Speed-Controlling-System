/******************************************************************************
 *
 * Module		: ADC (Analog to Digital Converter)
 *
 * File Name	: adc.c
 *
 * Description	: source file for the adc driver - MCAL Layer
 *
 * Author		: Erini Sabry
 *
 * Date Created	: 06.10.2022
 *
 *******************************************************************************/


/*******************************************************************************
 *                                Linking Section - INCLUDES
 *******************************************************************************/
#include "adc.h"
#include "bit_math.h" /* To use the macros like SET_BIT */
#include "avr/io.h"

/*******************************************************************************
 *                                Functions Definition
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
void ADC_init(const ADC_ConfigType * a_Config_Ptr){
	/* ADMUX Register Bits Description:
	 * REFS1:0 = 00 for AREF,01 for AVCC 5v, 10 for Reserved, 11 for Internal 2.56v
	 * ADLAR   = 0 right adjusted, 1 left adjusted
	 * MUX4:0  = 00000 for channel 0 as initialization increment by 1 to increment the channel number
	 */
	ADMUX = 0;
	/* Configure the reference volt in the last 2 bits RESF1:0 */
	ADMUX = (((a_Config_Ptr->ref_volt) & 0x03) << REFS0);
	/* ADCSRA Register Bits
	 * Description:
	 * ADEN    = 0 Disable ADC,1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt, 1 Enable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger, 1 Enable Auto Trigger
	 * ADPS2:0 = 000 to choose ADC_Clock
	 */
	/*Configure the prescaler*/
	ADCSRA =  ((a_Config_Ptr->prescaler) & 0x07) | (1<<ADEN);

}

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
uint16 ADC_readChannel(uint8 a_channelNum)
{
	/* Input channel number must be from 0 --> 7 */
	a_channelNum &= 0x07;
	/* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX&= 0xE0;
	/* Choose the correct channel by setting the channel number in MUX4:0 bits */
	ADMUX = ADMUX | a_channelNum;
	/* Start conversion write '1' to ADSC */
	SET_BIT(ADCSRA,ADSC);
	/* Wait for conversion to complete, ADIF becomes '1' */
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	/* Clear ADIF by write '1' to it :) */
	SET_BIT(ADCSRA,ADIF);
	/* Read the digital value from the data register */
	return ADC;

}
