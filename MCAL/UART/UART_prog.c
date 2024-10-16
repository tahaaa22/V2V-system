/*
 * UART_prog.c
 *
 * Created: 9/28/2024 6:43:52 PM
 *  Author: AMIT
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "UART_interface.h"
#include "UART_reg.h"




void UART_voidInit(void){
	
	u8 loc_u8temp=0 ; 
	/* set Boud rate  : FS : 16MHZ  , 9600 */
	  
	    UBRRL_REG=103 ; 
	 /* set bit 7 to write in UCSRC REG */
	 
	 SET_BIT(loc_u8temp,7) ; 
	 /* char size : 8 bit */	
	  SET_BIT(loc_u8temp,1) ; 
	  SET_BIT(loc_u8temp,2) ;
	  UCSRC_REG=loc_u8temp ; 
	  
	/* ENABLR TX & RX */
	SET_BIT(UCSRB_REG,3) ; 
	SET_BIT(UCSRB_REG,4) ;
	
}
void UART_voidTX(u8 copy_u8data){
	
	UDR_REG=copy_u8data ; 
	while(GET_BIT(UCSRA_REG,5)==0) ; 
	
	
}
u8 UART_u8RX(void){
	
	while(GET_BIT(UCSRA_REG,7)==0) ; 
	return UDR_REG ; 
}