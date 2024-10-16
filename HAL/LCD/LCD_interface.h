/*
 * LCD_interface.h
 *
 * Created: 8/23/2024 7:19:11 PM
 *  Author: AMIT
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


/*LCD MODES */

#define  _4_BITMODE     0 
#define  _8_BITMODE     1

#define  LCD_MODE   _4_BITMODE



void LCD_voidInit(void) ; 

void LCD_voidSendCommand( u8 copy_u8command) ; 
void LCD_voidSendData( u8 copy_u8data) ;

void LCD_voidSendString(u8*str) ; 
//void LCD_voidSendNumber(u8 number);
void LCD_SendNumber(u32 num, u8 x, u8 y);
void LCD_voidGoToXY(u8 x, u8 y);
void LCD_voidClear(void);
void LCD_voidDrawData(u8 pattern, u8*data, u8 x, u8 y);

#endif /* LCD_INTERFACE_H_ */