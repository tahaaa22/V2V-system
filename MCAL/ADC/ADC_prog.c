/*
 * ADC_prog.c
 *
 * Created: 9/7/2024 6:25:59 PM
 *  Author: AMIT
 */ 

#include "../../LIB/BIT_MATH.h" 
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "ADC_interface.h" 
#include "ADC_reg.h"





void ADC_voidInit(void){
	
	/*select Reference : AVCC with external capacitor at AREF pin*/
	   SET_BIT(ADMUX_REG,6) ; 
	   CLR_BIT(ADMUX_REG,7) ;
	   /*set  prescaler : 128 */
	  ADCSRA_REG&=0b11111000 ;           
	  ADCSRA_REG|=ADC_PRESCALER   ; 
	/* Enable ADC */
	SET_BIT(ADCSRA_REG,7) ; 
	
}

u16 ADC_u16ReadChannel(u8 copy_u8channel){
	
	 /* select channel */
	ADMUX_REG&=0b11100000 ; 
	ADMUX_REG|=copy_u8channel ; 
  
       /* ADC Start Conversion */
     SET_BIT(ADCSRA_REG,6) ; 
	 while(GET_BIT(ADCSRA_REG,4)==0) ; 
	 
	 return ADC_REG ; 
		   
}
