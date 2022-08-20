/*
 * TIMERS.h
 *
 * Created: 8/10/2022 4:35:22 PM
 *  Author: Ismail
 */ 

#include "../STD_TYPES.h"

#ifndef TIMERS_H_
#define TIMERS_H_

#define normal 0
#define CTC 1
#define PWM 2
#define FastPWM 3

#define noPS 0
#define PS8 1
#define PS64 2
#define PS256 3
#define PS1024 4

#define NO_OVF 20

u8 overflows;

void set_TimerMode(u8 mode);
void set_TimerIntialValue(u32 Val);
void startTimer(u8 prescaler,u8 OVRFLW);




#endif /* TIMERS_H_ */