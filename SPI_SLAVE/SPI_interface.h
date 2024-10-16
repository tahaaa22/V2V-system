/*
 * SPI_interface.h
 *
 * Created: 9/28/2024 9:56:56 PM
 *  Author: Ahmed Taha
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "SPI_reg.h"
#include "BIT_MATH.h"
#include "STD_TYPE.h"
#include "DIO_interface.h"


#define  SPI_PORT       DIO_PORTB 
#define  MOSI_PIN       DIO_PIN5
#define  CLK_PIN        DIO_PIN7
#define  MISO_PIN       DIO_PIN6
#define  SS_PIN         DIO_PIN4

void SPI_Mastervoid_Init();

void SPI_Slavevoid_Init();

void SPI_voidMasterSendData(u8 u8_copyData);

u8 SPI_voidSlaveRecieveData();




#endif /* SPI_INTERFACE_H_ */