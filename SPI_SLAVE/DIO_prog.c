/*
 * DIO_prog.c
 *
 * Created: 8/17/2024 7:17:42 PM
 *  Author: AMIT
 */ 

#include "BIT_MATH.h"
#include "STD_TYPE.h"
#include "DIO_interface.h" 
#include "DIO_reg.h"


void DIO_voidSetPinDir(u8 copy_u8port, u8 copy_u8pin , u8 copy_u8dir) {
	
	
	
	         if (copy_u8dir == OUTPUT || copy_u8dir==INPUT)
	         {
	        
	           if (copy_u8dir==OUTPUT)
	           {
				   switch(copy_u8port){
					   
					   case DIO_PORTA : SET_BIT(DDRA_REG,copy_u8pin) ;break ; 
					   case DIO_PORTB:  SET_BIT(DDRB_REG,copy_u8pin) ;break ; 
					   case DIO_PORTC: SET_BIT(DDRC_REG,copy_u8pin) ; break ; 
					   case DIO_PORTD: SET_BIT(DDRD_REG,copy_u8pin) ; break ;   
				   }   
	           }
	           else if (copy_u8dir==INPUT)
	           {
				   switch(copy_u8port){
					   
					   case DIO_PORTA :CLR_BIT(DDRA_REG,copy_u8pin) ;break ;
					   case DIO_PORTB: CLR_BIT(DDRB_REG,copy_u8pin) ;break ;
					   case DIO_PORTC: CLR_BIT(DDRC_REG,copy_u8pin) ; break ;
					   case DIO_PORTD: CLR_BIT(DDRD_REG,copy_u8pin) ; break ;
				   }
	           }
			   else{
				   // do thing 
			   }
	 }
	 else{
		 
		  // error 
		 
	 }
	
	
}


void DIO_voidSetPinVal(u8 copy_u8port, u8 copy_u8pin , u8 copy_u8val){
	
	     
	            if (copy_u8val==HIGH)
	            {
					
					switch(copy_u8port){
						
					case DIO_PORTA :SET_BIT(PORTA_REG,copy_u8pin) ;break ;
					case DIO_PORTB: SET_BIT(PORTB_REG,copy_u8pin) ;break ;
					case DIO_PORTC: SET_BIT(PORTC_REG,copy_u8pin) ; break ;
					case DIO_PORTD: SET_BIT(PORTD_REG,copy_u8pin) ; break ;
					}
				}
				else if (copy_u8val==LOW)
				{
					switch(copy_u8port){
						
						case DIO_PORTA :CLR_BIT(PORTA_REG,copy_u8pin) ;break ;
						case DIO_PORTB: CLR_BIT(PORTB_REG,copy_u8pin) ;break ;
						case DIO_PORTC: CLR_BIT(PORTC_REG,copy_u8pin) ; break ;
						case DIO_PORTD: CLR_BIT(PORTD_REG,copy_u8pin) ; break ;
					}
				}
					else{
						// do nothing 
					}
					
					
				}
					


void DIO_voidTogglePinVal(u8 copy_u8port, u8 copy_u8pin ){
	
	       switch(copy_u8port){
			   
			  case DIO_PORTA :TOGGLE_BIT(PORTA_REG,copy_u8pin) ;break ;
			  case DIO_PORTB: TOGGLE_BIT(PORTB_REG,copy_u8pin) ;break ;
			  case DIO_PORTC: TOGGLE_BIT(PORTC_REG,copy_u8pin) ; break ;
			  case DIO_PORTD: TOGGLE_BIT(PORTD_REG,copy_u8pin) ; break ; 
			   
			   
		   }
	
}
				
				
u8 DIO_u8ReadPinVal(u8 copy_u8port, u8 copy_u8pin){
	
	   u8 LOC_u8val=0 ; 
	   
	    switch(copy_u8port){
		    
		    case DIO_PORTA :LOC_u8val=GET_BIT(PINA_REG,copy_u8pin) ;break ;
		    case DIO_PORTB: LOC_u8val=GET_BIT(PINB_REG,copy_u8pin) ;break ;
		    case DIO_PORTC: LOC_u8val=GET_BIT(PINC_REG,copy_u8pin) ; break ;
		    case DIO_PORTD: LOC_u8val=GET_BIT(PIND_REG,copy_u8pin) ; break ;
		    
		    
	    }
	return LOC_u8val ; 
}



void DIO_voidSetPortDir(u8 copy_u8port,u8 copy_u8dir) {
	
	
	   switch(copy_u8port){
		   
		  case DIO_PORTA: DDRA_REG=copy_u8dir ; break; 
		  case DIO_PORTB: DDRB_REG=copy_u8dir ; break;
		  case DIO_PORTC: DDRC_REG=copy_u8dir ; break ; 
		  case DIO_PORTD: DDRD_REG=copy_u8dir ; break ;
	   }
}
void DIO_voidSetPortval(u8 copy_u8port,u8 copy_u8val){
	
	
	 switch(copy_u8port){
		 
		 case DIO_PORTA: PORTA_REG=copy_u8val ; break;
		 case DIO_PORTB: PORTB_REG=copy_u8val ; break;
		 case DIO_PORTC: PORTC_REG=copy_u8val ; break ;
		 case DIO_PORTD: PORTD_REG=copy_u8val ; break ;
		 
		 
	 }
	 
}			