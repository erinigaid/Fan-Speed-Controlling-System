 /******************************************************************************
 *
 * Module		: LCD
 *
 * File Name	: lcd.h
 *
 * Description	: Header file for the lcd driver - HAL Layer
 *
 * Author		: Erini Sabry
 *
 * Date Created	: 05.10.2022
 *
 *******************************************************************************/

/* Header file guard */

#ifndef LCD_H_
#define LCD_H_

/*******************************************************************************
 *                                Linking Section - INCLUDES
 *******************************************************************************/
#include "std_types.h"

/*******************************************************************************
 *                                Definitions & Configurations
 *******************************************************************************/
#define LCD_DATA_BITS_MODE 8
/* LCD HW Ports and Pins Ids */

#if((LCD_DATA_BITS_MODE != 4) && (LCD_DATA_BITS_MODE != 8))

#error "Number of Data bits should be equal to 4 or 8"

#endif

#define LCD_RS_PORT_ID                 PORTD_ID
#define LCD_RS_PIN_ID                  PIN0_ID

//#define LCD_RW_PORT_ID                 PORTD_ID
//#define LCD_RW_PIN_ID                  PIN1_ID

#define LCD_E_PORT_ID                  PORTD_ID
#define LCD_E_PIN_ID                   PIN2_ID

#define LCD_DATA_PORT_ID               PORTC_ID

#if (LCD_DATA_BITS_MODE == 4)

#define LCD_DB4_PIN_ID                 PIN3_ID
#define LCD_DB5_PIN_ID                 PIN4_ID
#define LCD_DB6_PIN_ID                 PIN5_ID
#define LCD_DB7_PIN_ID                 PIN6_ID

#endif

/* LCD Modes */
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32

/* LCD Commands */
#define LCD_CLEAR_DISPLAY                    0x01
#define LCD_RETURN_HOME                      0x02
#define LCD_SHIFT_CURSOR_LEFT			  	 0X04
#define LCD_SHIFT_DISPLAY_RIGHT     	 	 0X05
#define LCD_SHIFT_CURSOR_RIGHT       	 	 0X06
#define LCD_SHIFT_DISPLAY_LEFT      	  	 0X07
#define LCD_DISPLAY_OFF_CURSOR_OFF  	 	 0X08
#define LCD_DISPLAY_OFF_CURSOR_ON   	 	 0X0A
#define LCD_DISPLAY_ON_CURSOR_OFF	   	 	 0X0C
#define LCD_DISPLAY_ON_CURSOR_ON	   	 	 0X0E
#define LCD_DISPLAY_ON_CURSOR_BLINKING     	 0X0F
#define LCD_SHIFT_CURSOR_POSITION_LEFT   	 0X10
#define LCD_SHIFT_CURSOR_POSITION_RIGHT  	 0X14
#define LCD_SHIFT_ENTIRE_DISPLAY_LEFT    	 0X18
#define LCD_SHIFT_ENTIRE_DISPLAY_RIGHT   	 0X1C
#define LCD_CURSOR_FIRST_LINE  	             0x80
#define LCD_CURSOR_SECOND_LINE           	 0XC0
/*******************************************************************************
 *                              Functions Prototype (Public)
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
void LCD_init(void);

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
void LCD_sendCommand(uint8 a_command);

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
void LCD_displayCharacter(uint8 a_character);

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
void LCD_displayString(const uint8 *a_string_Ptr);

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
void LCD_moveCursor(uint8 a_row, uint8 a_col);

/*******************************************************************************
 * Function Name: LCD_displayStringRowColumn
 *
 * Description :
 * 		send array of characters to the connected port.
 *
 * Parameters:
 * 		uint8 row: specifying the row number
 * 		uint8 col: specifying the column number
 * 		const uint8 *string: constant array of characters
 *
 * Return: void type
 *
  *******************************************************************************/
void LCD_displayStringRowColumn(uint8 a_row,uint8 a_col,const uint8 *a_string_Ptr);

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
void LCD_intgerToString(uint32 a_data);

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
void LCD_clearScreen(void);

#endif /* LCD_H_ */
