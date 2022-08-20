/*
 * INT.c
 *
 * Created: 8/11/2022 3:55:24 PM
 *  Author: Ismail
 */ 

#include "INT.h"
#include "../STD_TYPES.h"
#include "../BIT_MATH.h"
#include "../regs.h"
#include "../DIO/DIO_interface.h"
#include "../../Application/app.h"
#include "../TIMERS/TIMERS.h"

u8 kawnter=0;

void en_global_INT()
{
	SET_BIT(SREG,7);
}
void INT_senseControl(u8 Intrpt,u8 mode)
{
	if (Intrpt==INT_0)
	{
		switch(mode)
		{
			case LOW_LVL:
			CLR_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
			break;
			case LGC_CHNG:
			SET_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
			break;
			case FAL_EDG:
			CLR_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
			break;
			case RIS_EDG:
			SET_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
			break;
		}
	}
	else if (Intrpt==INT_1)
	{
		switch(mode)
		{
			case LOW_LVL:
			CLR_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
			break;
			case LGC_CHNG:
			SET_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
			break;
			case FAL_EDG:
			CLR_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
			break;
			case RIS_EDG:
			SET_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
			break;
		}
	}
}
void en_external_INT(u8 Int)
{
	switch (Int)
	{
		case INT_0:
		SET_BIT(GICR,6);
		case INT_1:
		SET_BIT(GICR,7);
	}
}

ISR(EXT_INT_0)
{
	startTimer(PS64,60);
	if (DIO_GetPinValue(DIO_PORTD,DIO_PIN2)==DIO_LOW)
	{
		kawnter++;
	}
	if (kawnter==0)
	{
		
	
	if (LED_count==0)
	{
		DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_HIGH);//GRN pedsr
		startTimer(PS1024,20);
		DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_LOW);
	}
	else if (LED_count==1 ||LED_count==2||LED_count==3)
	{
		for (u8 i=0;i<10;i++)
		{
			DIO_SetPinValue(DIO_PORTB,DIO_PIN0,DIO_HIGH);
			DIO_togglepinvalue(DIO_PORTA,DIO_PIN1);
			DIO_togglepinvalue(DIO_PORTB,DIO_PIN1);
			startTimer(PS64,32);
		}
		DIO_SetPortValue(DIO_PORTA,0b00000001);
		DIO_SetPortValue(DIO_PORTB,0b00000100);
		startTimer(PS1024,20);
		DIO_SetPortValue(DIO_PORTA,0x00);
		DIO_SetPortValue(DIO_PORTB,0x00);
		
	}
	}
	kawnter=0;
}