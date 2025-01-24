/*
 * main.c
 *
 * Created: 8/17/2024 7:08:28 PM
 * Author : Youssef Bassem
 */ 

/* Section: Includes */
#include "main.h"

void Car_Move_Forward(){
	DC_MOTOR_voidMoveForward_1(90);
	DC_MOTOR_voidMoveForward_2(90);

	
}

void Car_Stop(){
	DC_MOTOR_voidStop_1();
	DC_MOTOR_voidStop_2();

	
}

void Car_Move_Right(){
	DC_MOTOR_voidMoveForward_1(90); 
	DC_MOTOR_voidStop_2();
	_delay_ms(1000);
			
}

void Car_Move_Left(){
	
	DC_MOTOR_voidStop_1();
	DC_MOTOR_voidMoveForward_2(90);
	_delay_ms(1000);
	
	
}


void setupConnection(){
	// Enter AT mode
	DIO_voidSetPinDir(DIO_PORTB,DIO_PIN0,OUTPUT);
	DIO_voidSetPinVal(DIO_PORTB,DIO_PIN0,HIGH);//PULL KEY PIN HIGH
	_delay_ms(1000);
	
	UART_voidSendString("AT\r\n");// Test Command
	_delay_ms(1000); 
	
	UART_voidSendString("AT+ROLE=1\r\n");//Set as master
	_delay_ms(1000);
	UART_voidSendString("AT+CMODE=1\r\n"); // Allow connection to any address
	_delay_ms(1000);
	
	DIO_voidSetPinVal(DIO_PORTB,DIO_PIN0,LOW);// Exit AT mode
	_delay_ms(1000);
	
}

void CheckObstacle(){
	UART_voidTx('s');
	Car_Stop();
	SERVO_MOTOR_voidRotateWithDegree(-90);
	_delay_ms(1000);
	u16 dist_left = ULTRASONIC_u16GetDistance();
	_delay_ms(300);
	SERVO_MOTOR_voidRotateWithDegree(90);
	_delay_ms(1000);
	u16 dist_right = ULTRASONIC_u16GetDistance();
	_delay_ms(300);
	SERVO_MOTOR_voidRotateWithDegree(0);
	_delay_ms(1000);
	
	if ((dist_right > dist_left) && dist_right > 10)
	{
		UART_voidTx('r');
		Car_Move_Right();
	}else if ((dist_right < dist_left) && dist_left > 10)
	{
		UART_voidTx('l');
		Car_Move_Left();
	}
}

int main(void) {
	
	DIO_voidSetPinDir(DIO_PORTD,DIO_PIN5,OUTPUT);
	UART_voidInit();
	
	setupConnection();
	
	Car_Move_Forward();
			
	u16 dist = 0;
	
	while(1){
		
		dist = ULTRASONIC_u16GetDistance();
		
		
		_delay_ms(10);
		if (dist < 10)
		{
			CheckObstacle();
			
			
		}else if(dist > 10){
			UART_voidTx('f');
			Car_Move_Forward();
			LED_voidOff(DIO_PORTC,DIO_PIN2);
		
		}
	}
		
		
			
		
		
	
	
	
}