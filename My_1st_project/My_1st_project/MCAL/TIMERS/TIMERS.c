/*
 * TIMERS.c
 *
 * Created: 8/10/2022 4:35:35 PM
 *  Author: Ismail
 */ 
#include "../BIT_MATH.h"
#include "../STD_TYPES.h"
#include "TIMERS.h"
#include "../regs.h"

void set_TimerMode(u8 mode)
{
	switch(mode)
	{
		case normal:
		TCCR0=0x00;
		break;
		case CTC:
		SET_BIT(TCCR0,3);
		CLR_BIT(TCCR0,6);
		break;
		case PWM:
		CLR_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);
		break;
		case FastPWM:
		SET_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);
		break;
	}
}
void set_TimerIntialValue(u32 Val)
{
	TCNT0=Val;
}
void startTimer(u8 prescaler,u8 OVRFLW)
{
	overflows=0;
	switch(prescaler)
	{
		case noPS:
		SET_BIT(TCCR0,0);
		CLR_BIT(TCCR0,1);
		CLR_BIT(TCCR0,2);
		break;
		
		case PS8:
		CLR_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		CLR_BIT(TCCR0,2);
		break;
		
		case PS64:
		SET_BIT(TCCR0,0);
		SET_BIT(TCCR0,1);
		CLR_BIT(TCCR0,2);
		break;
		
		case PS256:
		SET_BIT(TCCR0,0);
		CLR_BIT(TCCR0,1);
		CLR_BIT(TCCR0,2);
		break;
		
		case PS1024:
		SET_BIT(TCCR0,0);
		CLR_BIT(TCCR0,1);
		SET_BIT(TCCR0,2);
		break;
	}
	while(overflows<OVRFLW)
	{
		while(GET_BIT(TIFR,0)==0);
		SET_BIT(TIFR,0);
		overflows++;
	}
	TCCR0=0x00;
	overflows=0;

	
}