/*
 * main.c
 *
 * Created: 8/17/2024 7:08:28 PM
 * Author : Youssef Bassem
 */ 

/* Section: Includes */
#include "main.h"




int main(void) {
	
	UART_voidInit();
	

	DC_MOTOR_voidMoveForward_1(70);
	DC_MOTOR_voidMoveForward_2(70);
	
	while(1){
		u8 data = UART_u8Rx();
		
		switch(data){
			case 's':
				DC_MOTOR_voidStop_1();
				DC_MOTOR_voidStop_2();
				LED_voidOn(DIO_PORTC,DIO_PIN2);
				break;
			case 'f':
				DC_MOTOR_voidMoveForward_1(70);
				DC_MOTOR_voidMoveForward_2(70);
				LED_voidOff(DIO_PORTC,DIO_PIN2);
				break;
				
			case 'r':
				DC_MOTOR_voidMoveForward_1(70);
				DC_MOTOR_voidStop_2();
				LED_voidOff(DIO_PORTC,DIO_PIN2);
				
				break;
			case 'l':
				DC_MOTOR_voidMoveForward_2(70);
				DC_MOTOR_voidStop_1();
				LED_voidOff(DIO_PORTC,DIO_PIN2);
			default: break;

		}
		
		
			
		
		
	}
	
	
}