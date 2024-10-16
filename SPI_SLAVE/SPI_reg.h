/*
 * SPI_reg.h
 *
 * Created: 9/28/2024 9:56:34 PM
 *  Author: Ahmed Taha
 */ 


#ifndef SPI_REG_H_
#define SPI_REG_H_

#define SPCR_REG  *((volatile u8*) 0x2D)
#define SPSR_REG  *((volatile u8*) 0x2E)
#define SPDR_REG  *((volatile u8*) 0x2F)



#endif /* SPI_REG_H_ */