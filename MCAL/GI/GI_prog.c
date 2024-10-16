/*
 * GI_prog.c
 *
 * Created: 8/31/2024 8:58:34 PM
 *  Author: Ahmed Taha
 */ 

#include "GI_interface.h"
#include "GI_reg.h"


void GI_voidEnable()
{
	SET_BIT(SREG_REG,GI_BIT);
	//__asm volatile("SEI");
}



void GI_voidDisable()
{
	CLR_BIT(SREG_REG,GI_BIT);
	//__asm volatile("CLI");
}