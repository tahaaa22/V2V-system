/*
 * TIM0_prog.c
 *
 * Created: 9/13/2024 8:30:12 PM
 *  Author: AMIT
 */ 
#include "../../LIB/BIT_MATH.h" 
#include "../../LIB/STD_TYPE.h" 
#include "../../LIB/interrupt_vector.h"
#include "TIM0_reg.h" 
#include "TIM0_interface.h" 



void (*TIM0_PTR[2])(void)={null} ; 

void TIM0_voidInit( ){
	
		/* select prescaler  */
		TCCR0_REG&=0b11111000 ;
		TCCR0_REG|=TIM0_PRESCALER ;
	#if TIMER0_MODE == OV_MODE 
    /*select mode : normal mode  */	
	CLR_BIT(TCCR0_REG,3) ; 
	CLR_BIT(TCCR0_REG,6) ;
	/* enable overflow interrupt */
      SET_BIT(TIMSK_REG,0) ; 
#elif TIMER0_MODE == CTC_MODE 
   /*select mode : normal mode  */
   SET_BIT(TCCR0_REG,3) ;
   CLR_BIT(TCCR0_REG,6) ;
   /* SET OCR VAL */
   
   OCR0_REG=OCR_VAL ; 
   /* enable ctc interrupt */
   SET_BIT(TIMSK_REG,1) ;
   #endif 
	
}

void TIM0_voidStop(){
	
	TCCR0_REG=0x00 ; 
	
}


void TIM0_voidSetCallBack(void(*ptr)(void), u8 mode){
	
	switch(mode){
		
		case  OV_MODE : TIM0_PTR[0]=ptr ; break ; 
		case  CTC_MODE : TIM0_PTR[1]=ptr ; break ;
		
		
	}
	
	
	
}
                             /* 0 ----> 100 % */
void TIM0_voidFastPWM(u8 copy_u8dc){
	
	 /* select mode : fast pwm */
	 SET_BIT(TCCR0_REG,3) ;
	 SET_BIT(TCCR0_REG,6) ;
	 /* NON INVERTING */
	 CLR_BIT(TCCR0_REG,4) ; 
	 SET_BIT(TCCR0_REG,5) ; 
	 /* select prescaler  */
	 TCCR0_REG&=0b11111000 ;
	 TCCR0_REG|=TIM0_PRESCALER ;
	 /* SET ocr val */
	/* 
	    dc = ocr / 2res 
		ocr =dc* 2res /100
		ocr=dc*256/100
		ocr= dc*2.56 
	
	*/
	OCR0_REG=copy_u8dc*2.56 ; 
	
}


ISR(TIMER0_OVF){
	
	TIM0_PTR[0]() ; 
	

}

ISR(TIMER0_COMP){
	
	TIM0_PTR[1]() ;
	

}

