/*
 * KEYPAD_prog.c
 *
 * Created: 8/30/2024 7:10:39 PM
 *  Author: AMIT
 */ 

#include "../../LIB/BIT_MATH.h" 
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "KEYPAD_config.h"



u8 KEYPAD_ARR[4][4]={{1,2,3,'+'},
	                 {4,5,6,'-'},
                     {7,8,9,'C'},
                     {'*',0,'=','D'} }; 

void KEYPAD_voidInit(void){
	
	  u8 ROW_ARR[4]={KEYPAD_R0_PIN,KEYPAD_R1_PIN,KEYPAD_R2_PIN,KEYPAD_R3_PIN} ; 
	  u8 COL_ARR[4]={KEYPAD_C0_PIN,KEYPAD_C1_PIN,KEYPAD_C2_PIN,KEYPAD_C3_PIN} ;
	  u8 loc_in=0 ; 
	  
	  for (loc_in=0 ; loc_in<4;loc_in++)
	  {
		   /* make rows as input high to enable internal pullup */
		   DIO_voidSetPinDir(KEYPAD_ROW_PORT,ROW_ARR[loc_in],INPUT) ;
		  DIO_voidSetPinVal(KEYPAD_ROW_PORT,ROW_ARR[loc_in],HIGH) ;
		  
		  /* MAKE COL AS OUTPUT HIGH */
		     DIO_voidSetPinDir(KEYPAD_COL_PORT,COL_ARR[loc_in],OUTPUT) ;
		     DIO_voidSetPinVal(KEYPAD_COL_PORT,COL_ARR[loc_in],HIGH) ;
	
	
	  }
	
}

u8 KEYPAD_u8GetKey(void){
	 u8 ROW_ARR[4]={KEYPAD_R0_PIN,KEYPAD_R1_PIN,KEYPAD_R2_PIN,KEYPAD_R3_PIN} ;
	 u8 COL_ARR[4]={KEYPAD_C0_PIN,KEYPAD_C1_PIN,KEYPAD_C2_PIN,KEYPAD_C3_PIN} ;
	 u8 LOC_row=0 ;
	 u8 LOC_col=0 ;
	 u8 loc_val=0xff ; 
	 for (LOC_col=0 ;LOC_col<4;LOC_col++ )
	 {
		 /* make the current col as low  */
		 DIO_voidSetPinVal(KEYPAD_COL_PORT,COL_ARR[LOC_col],LOW) ; 
		 for (LOC_row=0; LOC_row<4;LOC_row++)
		 {
			 if (DIO_u8ReadPinVal(KEYPAD_ROW_PORT,ROW_ARR[LOC_row])==0)
			 {
				 loc_val=KEYPAD_ARR[LOC_row][LOC_col] ; 
				 while(DIO_u8ReadPinVal(KEYPAD_ROW_PORT,ROW_ARR[LOC_row])==0); 
				      
					  return loc_val ; 
			 }

			 
		 }
		 
		 DIO_voidSetPinVal(KEYPAD_COL_PORT,COL_ARR[LOC_col],HIGH) ; 
		 
	 }
	 
	
	

	return loc_val ;  
}