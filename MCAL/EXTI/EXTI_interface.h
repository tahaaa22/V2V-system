/*
 * EXTI_interface.h
 *
 * Created: 8/31/2024 9:38:07 PM
 *  Author: AMIT
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


/* interrupt pins */

#define  INT0_      0 
#define  INT1_      1
#define  INT2_      2


/*SENES  control */


#define  LOW_LEVEL           0 
#define  ANY_LOGICAL_CHANGE  1 
#define  FALLIN_EDGE         2 
#define  RISING_EDGE         3




void EXTI_voidInit(u8 copy_u8interrupt_num  , u8 copy_senes) ; 

void EXTI0_voidEnable(void) ; 

void EXTI0_voidDisable(void) ; 

void EXTI1_voidEnable(void) ;

void EXTI1_voidDisable(void) ;

void EXTI2_voidEnable(void) ;

void EXTI2_voidDisable(void) ;

void EXTI_voidSetCallBack(void(*ptr) (void), u8 sw);
//void __vector_1(void (*INT0_ptr)(void));


#endif /* EXTI_INTERFACE_H_ */