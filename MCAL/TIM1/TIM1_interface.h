/*
 * TIM1_interface.h
 *
 * Created: 9/14/2024 9:40:10 PM
 *  Author: AMIT
 */ 


#ifndef TIM1_INTERFACE_H_
#define TIM1_INTERFACE_H_

/* select prescaler */

#define  NO_PRESCALER      0x01
#define  _8_PRESCALER      0x02
#define  _64_PRESCALER     0x03
#define  _256_PRESCALER    0x04
#define  _1024_PRESCALER   0x05

#define TIM1_PRESCALER      _8_PRESCALER




/* pwm pins */
#define  OC1A_PIN      0
#define  OC1B_PIN      1



void TIMER1_voidStart(void) ; 
void TIMER1_voidRest(void) ; 

u16 TIMER1_u16ReadVal() ; 



void TIMER1_voidFastPWM10BitRes(u8 copy_u8_pin , u8 copy_u8_duty) ;

void TIMER1_voidFastPWMICR1() ;

void TIMER1_voidSetOCRVal(u16  copy_u16_val) ; 





#endif /* TIM1_INTERFACE_H_ */