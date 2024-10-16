/*
 * TIM0_interface.h
 *
 * Created: 9/13/2024 8:29:24 PM
 *  Author: AMIT
 */ 


#ifndef TIM0_INTERFACE_H_
#define TIM0_INTERFACE_H_

/*  timer0 prescaler */

#define  NO_PRESCLAER         1 
#define  _8_PRESCLAER         2 
#define  _64_PRESCLAER        3
#define  _256_PRESCLAER       4
#define  _1024_PRESCLAER      5

#define  TIM0_PRESCALER      _64_PRESCLAER

/* TIMER0 MODE */

#define  OV_MODE     0 
#define  CTC_MODE    1 


#define  TIMER0_MODE      CTC_MODE

/* ocr val */
#define  OCR_VAL   250 



void TIM0_voidInit() ; 
void TIM0_voidStop() ; 
void TIM0_voidSetCallBack(void(*ptr)(void), u8 mode) ; 

void TIM0_voidFastPWM(u8 copy_u8dc) ; 

#endif /* TIM0_INTERFACE_H_ */