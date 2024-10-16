/*
 * DC_MOTOR_interface.h
 *
 * Created: 9/20/2024 7:38:19 PM
 *  Author: Ahmed Taha
 */ 


#ifndef DC_MOTOR_INTERFACE_H_
#define DC_MOTOR_INTERFACE_H_
#include "../../LIB/STD_TYPE.h"



void DC_MOTOR_CW(u8 speed);

void DC_MOTOR_ACW(u8 speed);

void DC_MOTOR_Stop();



#endif /* DC_MOTOR_INTERFACE_H_ */