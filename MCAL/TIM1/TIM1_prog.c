/*
 * TIM1_prog.c
 *
 * Created: 9/14/2024 9:40:39 PM
 *  Author: AMIT
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "TIM1_interface.h" 
#include "TIM1_reg.h"







void TIMER1_voidStart(void){
	/* select mode : normal mode  */
	
	CLR_BIT(TCCR1A_REG,0) ;
	CLR_BIT(TCCR1A_REG,1) ;
	CLR_BIT(TCCR1B_REG,3) ;
	CLR_BIT(TCCR1B_REG,4) ;
	
	/* select prescaler */
	
	TCCR1B_REG&=0b11111000 ;
	TCCR1B_REG|=TIM1_PRESCALER ;
	
	
}
void TIMER1_voidRest(void){
	
	
	TCNT1_REG=0x0000 ; 
}

u16 TIMER1_u16ReadVal() {
	
	return TCNT1_REG ; 
}






void TIMER1_voidFastPWM10BitRes(u8 copy_u8_pin , u8 copy_u8_duty){
	
	/* select mode : fast pwm 10 bit res */
	
	SET_BIT(TCCR1A_REG,0) ; 
	SET_BIT(TCCR1A_REG,1) ;
    SET_BIT(TCCR1B_REG,3) ;
    CLR_BIT(TCCR1B_REG,4) ;
	
	/* select prescaler */
     
	 TCCR1B_REG&=0b11111000 ; 
	 TCCR1B_REG|=TIM1_PRESCALER ; 
	 
	 switch(copy_u8_pin){
		 
		 
		 case OC1A_PIN : 
		                 /* non inverting */
						 CLR_BIT(TCCR1A_REG,6) ; 
						 SET_BIT(TCCR1A_REG,7) ;
						 
						 OCR1A_REG = copy_u8_duty*10.24 ;  break;
		 case OC1B_PIN :
		                        /* non inverting */
		                        CLR_BIT(TCCR1A_REG,4) ;
		                        SET_BIT(TCCR1A_REG,5) ;
		 
		 OCR1B_REG = copy_u8_duty*10.24 ;  break;				 
	 }
	 
		
	
}

void TIMER1_voidFastPWMICR1(){
	/* select mode : fast pwm  icr1  */
	
	CLR_BIT(TCCR1A_REG,0) ;
	SET_BIT(TCCR1A_REG,1) ;
	SET_BIT(TCCR1B_REG,3) ;
	SET_BIT(TCCR1B_REG,4) ;
	/* select prescaler */
	TCCR1B_REG&=0b11111000 ;
	TCCR1B_REG|=_8_PRESCALER ;
	  /* non inverting */
	  CLR_BIT(TCCR1A_REG,6) ;
	  SET_BIT(TCCR1A_REG,7) ;
	/* SET TOP VAL */
	
	ICR1_REG=40000 ; 	
}

void TIMER1_voidSetOCRVal(u16  copy_u16_val) {
	
	OCR1A_REG = copy_u16_val ; 
}