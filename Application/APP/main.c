/*
 * main.c
 *
 * Created: 8/17/2024 7:08:28 PM
 * Author : Youssef Bassem
 */ 

/* Section: Includes */
#include "main.h"




int main(void) {
	
	DIO_voidSetPortDir(LCD_DPORT,0XF0);
	DIO_voidSetPortDir(LCD_CPORT,0X0E);
	LCD_voidInit();
	
	
	
	while(1) {
	
		u16 dist = ULTRASONIC_u16GetDistance();
		
		LCD_voidGoto(0,0);
		LCD_voidSendNum(dist);
		
		if (dist < 10)
		{
		LCD_voidClearScreen();
		
			LED_voidOn(DIO_PORTC,DIO_PIN2);
		}else{
			LED_voidOff(DIO_PORTC,DIO_PIN2);
			
		}

		
	}


}