/*
 * TIMER_reg.h
 *
 * Created: 9/13/2024 8:22:57 PM
 *  Author: Ahmed Taha
 */ 


#ifndef TIM0_REG_H_
#define TIM0_REG_H_

#define OCR0_REG *((volatile u8*)0x5C)
#define TIMSK_REG *((volatile u8*)0x59)
#define TIFR_REG *((volatile u8*)0x58)
#define TCCR0_REG *((volatile u8*)0x53)
#define TCNT0_REG *((volatile u8*) 0x52)




#endif /* TIMER_REG_H_ */