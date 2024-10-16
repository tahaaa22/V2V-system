/*
 * EXTI_prog.c
 *
 * Created: 8/31/2024 9:38:31 PM
 *  Author: AMIT
 */ 
#include "../../LIB/BIT_MATH.h" 
#include "../../LIB/STD_TYPE.h" 
#include "EXTI_interface.h" 
#include "EXTI_reg.h" 

void (*INT_ptr[3]) (void) = {null};


void EXTI_voidInit(u8 copy_u8interrupt_num  , u8 copy_senes){
	
	switch(copy_u8interrupt_num){
		
		case  INT0_  :  
		              if (copy_senes==LOW_LEVEL)
		              {
						  CLR_BIT(MCUCR_REG,0) ; 
						  CLR_BIT(MCUCR_REG,1) ;
		              }
		              else if (copy_senes==ANY_LOGICAL_CHANGE)
		              {
						    SET_BIT(MCUCR_REG,0) ;
						    CLR_BIT(MCUCR_REG,1) ;
		              }
					  else if (copy_senes==FALLIN_EDGE)
					  {
						  CLR_BIT(MCUCR_REG,0) ;
						  SET_BIT(MCUCR_REG,1) ;
					  }
					  else if (copy_senes==RISING_EDGE)
					  {
						  SET_BIT(MCUCR_REG,0) ;
						  SET_BIT(MCUCR_REG,1) ;
					  }
					  else{
						  //do nothing 
					  }
		              break; 
	case  INT1_  :
	if (copy_senes==LOW_LEVEL)
	{
		CLR_BIT(MCUCR_REG,2) ;
		CLR_BIT(MCUCR_REG,3) ;
	}
	else if (copy_senes==ANY_LOGICAL_CHANGE)
	{
		SET_BIT(MCUCR_REG,2) ;
		CLR_BIT(MCUCR_REG,3) ;
	}
	else if (copy_senes==FALLIN_EDGE)
	{
		CLR_BIT(MCUCR_REG,2) ;
		SET_BIT(MCUCR_REG,3) ;
	}
	else if (copy_senes==RISING_EDGE)
	{
		SET_BIT(MCUCR_REG,2) ;
		SET_BIT(MCUCR_REG,3) ;
	}
	else{
		//do nothing
	}
	break;				  

	case INT2_ : 
	            
				 if (copy_senes==FALLIN_EDGE)
				 {
					 CLR_BIT(MCUCSR_REG,6) ; 
					 
				 }
	             else if (copy_senes==RISING_EDGE)
	             {
					 SET_BIT(MCUCSR_REG,6) ; 
	             }
	              break; 
	}
	
}

void EXTI0_voidEnable(void){
	
	SET_BIT(GICR_REG,6) ; 
}

void EXTI0_voidDisable(void){
	CLR_BIT(GICR_REG,6) ; 
}



void EXTI1_voidEnable(void){
	
	SET_BIT(GICR_REG,7) ;
}

void EXTI1_voidDisable(void){
	CLR_BIT(GICR_REG,7) ;
}


void EXTI2_voidEnable(void){
	
	SET_BIT(GICR_REG,5) ;
}

void EXTI2_voidDisable(void){
	CLR_BIT(GICR_REG,5) ;
}


void EXTI_voidSetCallBack(void(*ptr) (void), u8 sw)
{
	switch(sw)
	{
		case 0: INT_ptr[0] = ptr; break;
		case 1: INT_ptr[1] = ptr; break;
		case 2: INT_ptr[2] = ptr; break;
		
	}
}

void __vector_1 (void) __attribute__((signal));
void __vector_1(void)
{
	INT_ptr[0]();
	
}

void __vector_2 (void) __attribute__((signal));
void __vector_2(void)
{
		INT_ptr[1]();
	//DIO_voidSetPinVal(DIO_PORTC, DIO_PIN7,HIGH);
	
}

void __vector_3 (void) __attribute__((signal));
void __vector_3(void)
{
		INT_ptr[2]();
	//DIO_voidSetPinVal(DIO_PORTD, DIO_PIN3,HIGH);
	
}
