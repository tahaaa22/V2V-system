/*
 * main.c
 *
 * Created: 8/17/2024 7:08:28 PM
 * Author : Youssef Bassem
 */ 

/* Section: Includes */
#include "main.h"




int main(void) {
		
	
	DC_MOTOR_voidMoveForward_1(90);
	DC_MOTOR_voidMoveForward_2(90);
// 	
	
	while(1) {
		
		
		u16 dist = ULTRASONIC_u16GetDistance();
	
		
		_delay_ms(100);
		if (dist < 10)
		{
	
			DC_MOTOR_voidStop_1();
			DC_MOTOR_voidStop_2();
			LED_voidOn(DIO_PORTC,DIO_PIN2);
		}else{
			DC_MOTOR_voidMoveForward_1(90);
			DC_MOTOR_voidMoveForward_2(90);
			LED_voidOff(DIO_PORTC,DIO_PIN2);
			
		}

	}


}