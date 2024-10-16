/*
 * UART_interface.h
 *
 * Created: 9/27/2024 9:48:18 PM
 *  Author: Ahmed Taha
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "UART_reg.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_interface.h"


void UART_voidInit();

u8 UART_u8RX();

void UART_voidTX(u8 transmitter);
 



#endif /* UART_INTERFACE_H_ */