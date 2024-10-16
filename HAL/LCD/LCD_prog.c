/*
 * LCD_prog.c
 *
 * Created: 8/23/2024 7:20:13 PM
 *  Author: AMIT
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"

#define  F_CPU 16000000UL 
#include <util/delay.h>


void LCD_voidSHD( u8 data){
	
	u8 LCD_arr[4]={LCD_D4_PIN,LCD_D5_PIN,LCD_D6_PIN,LCD_D7_PIN} ; 
	u8 loc_in=0 ; 
	
	for (loc_in=0 ; loc_in<4 ;loc_in++)
	{
		
		  DIO_voidSetPinVal(LCD_DPORT,LCD_arr[loc_in],GET_BIT(data,loc_in)) ; 
		
	}
		
	
}

void LCD_SendNumber(u32 num, u8 x, u8 y)
{
	if(num == 0)
	{
		LCD_voidGoToXY(x,y);
		LCD_voidSendData(0 + '0');
		return;
	}
	u8 result[10]= {0};
	u8 i = 0;
	u8 is_negative = 0;
	
	if(num < 0)
	{
	is_negative = 1;
	num = -num;
	}
	
	while(num)
	{
		result[i] = (num % 10) + '0';
		num = num/10;
		i++;
	}
	
	if(is_negative)
	result[++i] = '-';


// now you need to revers the string
if(num != 0) 
for(u8 j =0, k = i - 1; j < k ; j++, k--)
{
	u8 temp = result[j];
	result[j] = result[k];
	result[k] = temp;
}

LCD_voidGoToXY(x,y);
LCD_voidSendString(result);
}

void LCD_voidSendEnablePluse(){
	
	
	/* Send enbal  pulse */
	DIO_voidSetPinVal(LCD_CPORT,LCD_EN_PIN,HIGH) ;
	_delay_ms(2) ;
	DIO_voidSetPinVal(LCD_CPORT,LCD_EN_PIN,LOW) ;
}

void LCD_voidInit(void){
	    
		  _delay_ms(40) ; 
		  
		  #if LCD_MODE == _8_BITMODE 
		  /*send command function set */
		  LCD_voidSendCommand(0b00111000) ; 
		  
		  #elif LCD_MODE == _4_BITMODE 
		  
		   LCD_voidSHD(0b0010) ; 
		   LCD_voidSendEnablePluse() ; 
		   LCD_voidSHD(0b0010) ;
		   LCD_voidSendEnablePluse() ;
		   LCD_voidSHD(0b1000) ;
		   LCD_voidSendEnablePluse() ;
		  #endif 
		  /*send command display on/off  */
		  LCD_voidSendCommand(0b00001100) ;
		  /*send command CLR*/
		  LCD_voidSendCommand(1) ; 
		 
	
}

void LCD_voidSendCommand( u8 copy_u8command){
	
	   /* set rs pin as low to send command */
	   DIO_voidSetPinVal(LCD_CPORT,LCD_RS_PIN,LOW) ; 
	   /* set rw pin as low to write */
	   DIO_voidSetPinVal(LCD_CPORT,LCD_RW_PIN,LOW) ;
	    
       /* send command */
	   #if LCD_MODE == _8_BITMODE	
	   DIO_voidSetPortval(LCD_DPORT,copy_u8command) ;   
         LCD_voidSendEnablePluse(); 
	                                    
	  #elif LCD_MODE ==_4_BITMODE 
	     LCD_voidSHD(copy_u8command>>4) ; 
		 LCD_voidSendEnablePluse() ; 
		 LCD_voidSHD(copy_u8command) ; 
		 LCD_voidSendEnablePluse() ;
	 #endif 	 
	     	 
	   
       
	    	
	
	
	
	
}
void LCD_voidSendData( u8 copy_u8data){
	
	 /* set rs pin as low to send data */
	 DIO_voidSetPinVal(LCD_CPORT,LCD_RS_PIN,HIGH) ;
	 /* set rw pin as low to write */
	 DIO_voidSetPinVal(LCD_CPORT,LCD_RW_PIN,LOW) ;
	     /* send command */
	     #if LCD_MODE == _8_BITMODE
	     DIO_voidSetPortval(LCD_DPORT,copy_u8data) ;
	     LCD_voidSendEnablePluse();
	     
	     #elif LCD_MODE ==_4_BITMODE
	     LCD_voidSHD(copy_u8data>>4) ;   
	     LCD_voidSendEnablePluse() ;
	     LCD_voidSHD(copy_u8data) ;
	     LCD_voidSendEnablePluse() ;
	     #endif
	
	
}


void LCD_voidSendString(u8* str){
	
	 u8 i=0 ; 
	while(str[i] !='\0'){
		
		LCD_voidSendData(str[i]) ; 
		i++;
		
	}
}

void LCD_voidGoToXY(u8 x, u8 y)
{
	u8 address = x+ y * 0x40;
	SET_BIT(address,7);
	LCD_voidSendCommand(address);
	
}

void LCD_voidClear(void)
{
	u8 address = 0x00;
	SET_BIT(address,0);
	LCD_voidSendCommand(address); 
}


void LCD_voidDrawData(u8 pattern, u8*data, u8 x, u8 y)
{
u8 address = pattern * 8;
CLR_BIT(address, 7);
SET_BIT(address, 6);

LCD_voidSendCommand(address);

for(u8 i =0 ; i < 8 ; i++)
{
LCD_voidSendData(data[i]);
}

LCD_voidGoToXY(x,y);
LCD_voidSendData(pattern);
}