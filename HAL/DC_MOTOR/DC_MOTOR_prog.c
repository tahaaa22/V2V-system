/*
 * DC_MOTOR_prog.c
 *
 * Created: 9/20/2024 7:38:45 PM
 *  Author: Ahmed Taha
 */ 

#include "DC_MOTOR_interface.h"
#include "DC_MOTOR_config.h"
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/TIM1/TIM1_interface.h"

void DC_MOTOR_CW(u8 speed)
{
	DIO_voidSetPinDir(H_EN_PORT,H_EN1_REG,OUTPUT);
	
	DIO_voidSetPinDir(H_A_PORT,H_A1_REG,OUTPUT);
	
	DIO_voidSetPinDir(H_A_PORT,H_A2_REG,OUTPUT);
			
			
	DIO_voidSetPinVal(H_A_PORT,H_A1_REG,HIGH);
	DIO_voidSetPinVal(H_A_PORT,H_A2_REG,LOW);
	
	TIMER1_voidFastPWM10BitRes(1,speed);
}

void DC_MOTOR_ACW(u8 speed)
{
	
}

void DC_MOTOR_Stop()
{
	
}