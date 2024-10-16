/*
 * SPI_prog.c
 *
 * Created: 9/28/2024 9:57:13 PM
 *  Author: Ahmed Taha
 */ 

#include "SPI_interface.h"

void SPI_Mastervoid_Init()
{
	DIO_voidSetPinDir(SPI_PORT,MOSI_PIN,OUTPUT);
	DIO_voidSetPinDir(SPI_PORT,CLK_PIN,OUTPUT);
	DIO_voidSetPinDir(SPI_PORT,MISO_PIN,INPUT);
	DIO_voidSetPinDir(SPI_PORT,SS_PIN,OUTPUT);

	/* Enable SPI, Master, set clock rate fck/128 */
	SPCR_REG = (1<<6)|(1<<4)|(1<<1)|(1<<0);
	
}

void SPI_Slavevoid_Init()
{
	DIO_voidSetPinDir(SPI_PORT,MOSI_PIN,INPUT);
	DIO_voidSetPinDir(SPI_PORT,CLK_PIN,INPUT);
	DIO_voidSetPinDir(SPI_PORT,MISO_PIN,OUTPUT);
	DIO_voidSetPinDir(SPI_PORT,SS_PIN,INPUT);
	/*Enable SPI,clr for slave*/
	SPCR_REG = (1<<6)|(0<<4);
}

void SPI_voidMasterSendData(u8 u8_copyData)
{
	/*start transmission*/
	SPDR_REG = u8_copyData;
	/*wait for transmission*/
	while(!(SPSR_REG & (1<<7)));
}

u8 SPI_voidSlaveRecieveData()
{
		/*wait for receiving*/
		while(!(SPSR_REG & (1<<7)));
		return SPDR_REG;
}