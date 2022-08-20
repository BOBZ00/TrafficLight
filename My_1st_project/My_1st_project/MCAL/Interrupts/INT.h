/*
 * INT.h
 *
 * Created: 8/11/2022 3:55:13 PM
 *  Author: Ismail
 */ 
#include "../STD_TYPES.h"


#ifndef INT_H_
#define INT_H_

#define INT_0 0
#define INT_1 1

#define LOW_LVL 0
#define LGC_CHNG 1
#define FAL_EDG 2
#define RIS_EDG 3

#define EXT_INT_0 __vector_1
#define EXT_INT_1 __vector_2

#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)



void en_global_INT();
void INT_senseControl(u8 Intrpt,u8 mode);
void en_external_INT(u8 Int);


#endif /* INT_H_ */