/*
 * UART_reg.h
 *
 * Created: 9/27/2024 9:47:20 PM
 *  Author: Ahmed Taha
 */ 


#ifndef UART_REG_H_
#define UART_REG_H_


#define UDR_REG     *((volatile u8*) 0x2C)
#define UCSRA_REG   *((volatile u8*) 0x2B)
#define UCSRB_REG   *((volatile u8*) 0x2A)
#define UBRRL_REG   *((volatile u8*) 0x29)
#define UCSRC_REG   *((volatile u8*) 0x40)
#define UBRRH_REG   *((volatile u8*) 0x40)
//#define RXEN_PIN




#endif /* UART_REG_H_ */