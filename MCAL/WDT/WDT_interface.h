/*
 * WDT_interface.h
 *
 * Created: 9/27/2024 6:33:15 PM
 *  Author: Ahmed Taha
 */ 


#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_
#include "WDT_reg.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_interface.h"

/*select prescaler */

#define  _16_3PRESCALER      1
#define  _32_5PRESCALER      2
#define  _65PRESCALER      3
#define  _0_13PRESCALER     4
#define  _0_26PRESCALER     5
#define  _0_52PRESCALER     6
#define  _1PRESCALER        7
#define  _2_1PRESCALER    8

#define  WDT_PRESCALER    _0.26PRESCALER


void WDT_voidStart(u8 time);

void WDT_voidStop();


#endif /* WDT_INTERFACE_H_ */