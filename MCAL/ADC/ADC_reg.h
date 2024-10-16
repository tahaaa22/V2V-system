/*
 * ADC_reg.h
 *
 * Created: 9/7/2024 6:25:42 PM
 *  Author: AMIT
 */ 


#ifndef ADC_REG_H_
#define ADC_REG_H_


#define  ADMUX_REG               *((volatile u8*)0x27)
#define  ADCSRA_REG              *((volatile u8*)0x26)
#define  ADC_REG                *((volatile u16*)0x24) // ADCH +ADCL 

   


#endif /* ADC_REG_H_ */