 /******************************************************************************
 *
 * Module		: LCD
 *
 * File Name	: lcd.c
 *
 * Description	: source file for the lcd driver - HAL Layer
 *
 * Author		: Erini Sabry
 *
 * Date Created	: 05.10.2022
 *
 *******************************************************************************/



/*******************************************************************************
 *                                Linking Section - INCLUDES
 *******************************************************************************/
#include "lcd.h"
#include "gpio.h"
#include <util/delay.h>
#include <stdlib.h>
##include "bit_math.h"

/*******************************************************************************
 *                                Functions Definition
 *******************************************************************************/

/*******************************************************************************
 * Function Name: LCD_init
 *
 * Description :
 * 		initializes the LCD
 *
 * Parameters: void
 *
 * Return: void type
 *
  *******************************************************************************/
void LCD_init(void)
{
	/* Configure the direction for RS and E pins as output pins */
	GPIO_setupPinDirection(LCD_RS_PORT_ID,LCD_RS_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_E_PORT_ID,LCD_E_PIN_ID,PIN_OUTPUT);

	_delay_ms(20);		/* LCD Power ON delay always > 15ms */

#if(LCD_DATA_BITS_MODE == 4)
	/* Configure 4 pins in the data port as output pins */
	GPIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,PIN_OUTPUT);

	/* Send for 4 bit initialization of LCD  */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);

	/* use 2-lines LCD + 4-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);

#elif(LCD_DATA_BITS_MODE == 8)
	/* Configure the data port as output port */
	GPIO_setupPortDirection(LCD_DATA_PORT_ID,PORT_OUTPUT);

	/* use 2-lines LCD + 8-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);

#endif

	LCD_sendCommand(LCD_DISPLAY_ON_CURSOR_OFF); /* cursor off */
	LCD_sendCommand(LCD_CLEAR_DISPLAY); /* clear LCD at the beginning */
}


/*******************************************************************************
 * Function Name: LCD_sendCommand
 *
 * Description :
 * 		send command to the connected port.
 *
 * Parameters:
 * 		uint8 a_command: Integer value to write in a port
 *
 * Return: void type
 *
  *******************************************************************************/
void LCD_sendCommand(uint8 a_command)
{
	GPIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_LOW); /* Instruction Mode RS=0 */
	_delay_ms(1); /* delay for processing Tas = 50ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

#if(LCD_DATA_BITS_MODE == 4)
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(a_command,4));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(a_command,5));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(a_command,6));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(a_command,7));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(a_command,0));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(a_command,1));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(a_command,2));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(a_command,3));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */

#elif(LCD_DATA_BITS_MODE == 8)
	GPIO_writePort(LCD_DATA_PORT_ID,a_command); /* out the required command to the data bus D0 --> D7 */
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
#endif
}

/*******************************************************************************
 * Function Name: LCD_displayCharacter
 *
 * Description :
 * 		send character to the connected port.
 *
 * Parameters:
 * 		uint8 a_character: Integer value (ASCII) to write in a port
 *
 * Return: void type
 *
  *******************************************************************************/
void LCD_displayCharacter(uint8 a_character)
{
	GPIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_HIGH); /* Data Mode RS=1 */
	_delay_ms(1); /* delay for processing Tas = 50ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

#if(LCD_DATA_BITS_MODE == 4)
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(a_character,4));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(a_character,5));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(a_character,6));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(a_character,7));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(a_character,0));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(a_character,1));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(a_character,2));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(a_character,3));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */

#elif(LCD_DATA_BITS_MODE == 8)
	GPIO_writePort(LCD_DATA_PORT_ID,a_character); /* out the required command to the data bus D0 --> D7 */
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
#endif
}

/*******************************************************************************
 * Function Name: LCD_displayString
 *
 * Description :
 * 		send array of characters to the connected port.
 *
 * Parameters:
 * 		const uint8 *a_string: constant array of characters
 *
 * Return: void type
 *
  *******************************************************************************/
void LCD_displayString(const uint8 *a_string_Ptr)
{
	int i;
	for(i = 0; a_string_Ptr[i] != '\0'; i++)
	{
		LCD_displayCharacter(a_string_Ptr[i]);
	}
}

/*******************************************************************************
 * Function Name: LCD_moveCursor
 *
 * Description :
 * 		move the cursor to a specified row and column index on the screen
 *
 * Parameters:
 * 		uint8 a_row: specifying the row number
 * 		uint8 a_col: specifying the column number
 *
 * Return: void type
 *
  *******************************************************************************/
void LCD_moveCursor(uint8 a_row, uint8 a_col)
{
	uint8 lcd_memory_address;

	/* Calculate the required address in the LCD DDRAM */
	switch(a_row)
	{
		case 0:
			lcd_memory_address=a_col;
				break;
		case 1:
			lcd_memory_address=a_col+0x40;
				break;
		case 2:
			lcd_memory_address=a_col+0x10;
				break;
		case 3:
			lcd_memory_address=a_col+0x50;
				break;
	}
	/* Move the LCD cursor to this specific address */
	LCD_sendCommand(lcd_memory_address | LCD_CURSOR_FIRST_LINE);
}

/*******************************************************************************
 * Function Name: LCD_displayStringRowColumn
 *
 * Description :
 * 		send array of characters to the connected port.
 *
 * Parameters:
 * 		uint8 a_row: specifying the row number
 * 		uint8 a_col: specifying the column number
 * 		const uint8 *a_string: constant array of characters
 *
 * Return: void type
 *
  *******************************************************************************/
void LCD_displayStringRowColumn(uint8 a_row,uint8 a_col,const uint8 *a_string_Ptr)
{
	LCD_moveCursor(a_row,a_col); /* go to to the required LCD position */
	LCD_displayString(a_string_Ptr); /* display the string */
}

/*******************************************************************************
 * Function Name: LCD_intgerToString
 *
 * Description :
 * 		Display the required decimal value on the screen
 *
 * Parameters:
 * 		uint32 a_data: Integer value to write in a port
 *
 * Return: void type
 *
  *******************************************************************************/
void LCD_intgerToString(uint32 a_data)
{
   char buff[16]; /* String to hold the ascii result */
   itoa(a_data,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
   LCD_displayString(buff); /* Display the string */
}

/*******************************************************************************
 * Function Name: LCD_clearScreen
 *
 * Description :
 * 		Send the clear screen command
 *
 * Parameters: void
 *
 * Return: void type
 *
  *******************************************************************************/
void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_DISPLAY); /* Send clear display command */
}




