/*
 * ADC_interface.h
 *
 * Created: 9/7/2024 6:25:31 PM
 *  Author: AMIT
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_



/*select prescaler */

#define  _2PRESCALER      1 
#define  _4PRESCALER      2
#define  _8PRESCALER      3
#define  _16PRESCALER     4
#define  _32PRESCALER     5
#define  _64PRESCALER     6
#define  _128PRESCALER    7 


#define  ADC_PRESCALER    _128PRESCALER

/*adc channel */

#define  ADC0_       0
#define  ADC1_       1
#define  ADC2_       2
#define  ADC3_       3
#define  ADC4_       4
#define  ADC5_       5
#define  ADC6_       6
#define  ADC7_       7




void ADC_voidInit(void) ; 

u16 ADC_u16ReadChannel(u8 copy_u8channel) ; 


#endif /* ADC_INTERFACE_H_ */