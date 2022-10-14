 /******************************************************************************
 *
 * Module		: GPIO
 *
 * File Name	: gpio.h
 *
 * Description	: Header file for the AVR GPIO driver - MCAL Layer
 *
 * Author		: Erini Sabry
 * 
 * Date Created	: 23.9.2022
 *
 *******************************************************************************/

/* Header file guard */
#ifndef GPIO_H_
#define GPIO_H_

/*******************************************************************************
 *                                Linking Section - INCLUDES
 *******************************************************************************/
#include "std_types.h"

/*******************************************************************************
 *                                Definitions & Configurations
 *******************************************************************************/
#define NUM_OF_PORTS           4
#define NUM_OF_PINS_PER_PORT   8

#define PORTA_ID               0
#define PORTB_ID               1
#define PORTC_ID               2
#define PORTD_ID               3

#define PIN0_ID                0
#define PIN1_ID                1
#define PIN2_ID                2
#define PIN3_ID                3
#define PIN4_ID                4
#define PIN5_ID                5
#define PIN6_ID                6
#define PIN7_ID                7

/* Definition for PORTA Registers */
#define PORTA_REG	(*(volatile uint8 * const)0x003B)
#define DDRA_REG	(*(volatile uint8 * const)0x003A)
#define PINA_REG 	(*(volatile const uint8 * const)0x0039)

/* Definition for PORTB Registers */
#define PORTB_REG	(*(volatile uint8 * const)0x0038)
#define DDRB_REG	(*(volatile uint8 * const)0x0037)
#define PINB_REG 	(*(volatile const uint8 * const)0x0036)

/* Definition for PORTC Registers */
#define PORTC_REG	(*(volatile uint8 * const)0x0035)
#define DDRC_REG	(*(volatile uint8 * const)0x0034)
#define PINC_REG 	(*(volatile const uint8 * const)0x0033)

/* Definition for PORTD Registers */
#define PORTD_REG	(*(volatile uint8 * const)0x0032)
#define DDRD_REG	(*(volatile uint8 * const)0x0031)
#define PIND_REG 	(*(volatile const uint8 * const)0x0030)

/*******************************************************************************
 *                               Types Declaration - ENUMS
 *******************************************************************************/
typedef enum
{
	PIN_INPUT,PIN_OUTPUT
}GPIO_PinDirectionType;

typedef enum
{
	PORT_INPUT,PORT_OUTPUT=0xFF
}GPIO_PortDirectionType;

/*******************************************************************************
 *                              Functions Prototype
 *******************************************************************************/

/*******************************************************************************
 * Function Name: GPIO_setupPinDirection
 * Description :
 * 		Setup the direction of the required pin input/output.
 * 		If the input port number or pin number are not correct, The function will not handle the request.
 * Parameters:
 * 		uint8 port_num: Integer value to the port id
 * 		uint8 pin_num: Integer value to the pin id
 * 		GPIO_PinDirectionType direction: Enum value can be 0 for input and 1 for output
 * Return: void type
 *
 *******************************************************************************/
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction);


/*******************************************************************************
 * Function Name: GPIO_writePin
 * Description :
 * 		Write the value Logic High or Logic Low on the required pin.
 * 		If the input port number or pin number are not correct, The function will not handle the request.
 * 		If the pin is input, this function will enable/disable the internal pull-up resistor.
 * Parameters:
 * 		uint8 port_num: Integer value to the port id
 * 		uint8 pin_num:  Integer value to the pin id
 * 		uint8 value: 	Integer value to write in a pin
 * Return: void type
 *
 *******************************************************************************/
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value);


/*******************************************************************************
 * Function Name: GPIO_readPin
 * Description :
 * 		Read and return the value for the required pin, it should be Logic High or Logic Low.
 * 		If the input port number or pin number are not correct, The function will return Logic Low.
 * Parameters:
 * 		uint8 port_num: Integer value to the port id
 * 		uint8 pin_num: Integer value to the pin id
 * Return:
 * 		pinReadValue: Integer read from a pin
 *
 *******************************************************************************/
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num);


/*******************************************************************************
 * Function Name: GPIO_setupPortDirection
 * Description :
 *		 Setup the direction of the required port all pins input/output.
 * 		 If the direction value is PORT_INPUT all pins in this port should be input pins.
 * 		 If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * 		 If the input port number is not correct, The function will not handle the request.
 * Parameters:
 * 		uint8 port_num: Integer value to the port id
 * 		GPIO_PinDirectionType direction: Enum value can be 0 for input and 1 for output
 * Return: void type
 *
 *******************************************************************************/
void GPIO_setupPortDirection(uint8 port_num, uint8 direction);


/*******************************************************************************
 * Function Name: GPIO_writePort
 * Description :
 * 		Write the value on the required port.
 * 		If any pin in the port is output pin the value will be written.
 * 		If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * 		If the input port number is not correct, The function will not handle the request.
 * Parameters:
 * 		uint8 port_num: Integer value to the port id
 * 		uint8 value: Integer value to write in a port
 * Return: void type
 *
 *******************************************************************************/
void GPIO_writePort(uint8 port_num, uint8 value);


/*******************************************************************************
 * Function Name: GPIO_readPort
 * Description :
 * 		Read and return the value of the required port.
 * 		If the input port number is not correct, The function will return ZERO value.
 * Parameters:
 * 		uint8 port_num: Integer value to the port id
 * Return:
 * 		pinReadValue: Integer read from a port
 *
 *******************************************************************************/
uint8 GPIO_readPort(uint8 port_num);

#endif /* GPIO_H_ */
