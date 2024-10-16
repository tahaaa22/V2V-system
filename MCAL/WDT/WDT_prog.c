/*
 * WDT_prog.c
 *
 * Created: 9/27/2024 6:33:30 PM
 *  Author: Ahmed Taha
 */ 
#include "WDT_interface.h"


void WDT_voidStart(u8 time)
{
	 /* select prescaler  */
			  WDTCR_REG&=0b11111000;
		 	 WDTCR_REG|=time ;

	 SET_BIT(WDTCR_REG, 3);
	 
}

void WDT_voidStop()
{
	WDTCR_REG |= (1<<3) | (1<<4);
	/* Turn off WDT */
	WDTCR_REG = 0x00;
}