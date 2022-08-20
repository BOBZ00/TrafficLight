/*
 * My_1st_project.c
 *
 * Created: 8/2/2022 10:52:42 PM
 * Author : Ismail
 */ 

//#include <avr/io.h>

#include "MCAL/regs.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/TIMERS/TIMERS.h"
#include "MCAL/STD_TYPES.h"
#include "MCAL/BIT_MATH.h"
#include "Application/app.h"
#include "MCAL/Interrupts/INT.h"


//*********PORTA for cars*********//
//*********PORTB for pedestrians*********//

int main(void)
{
	set_TimerMode(normal);
	set_TimerIntialValue(12);
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT);
	
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN1,DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN2,DIO_OUTPUT);
	
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN0,DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN1,DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN2,DIO_OUTPUT);	
	
	
	en_global_INT();
	INT_senseControl(INT_0,FAL_EDG);
	en_external_INT(INT_0);
	
    while (1) 
    {
		app();
	/*	if (LED_count==0)
		{
			DIO_SetPinValue(DIO_PORTA,2,DIO_LOW);
			DIO_SetPinValue(DIO_PORTB,0,DIO_LOW);
			DIO_SetPinValue(DIO_PORTA,0,DIO_HIGH);
			DIO_SetPinValue(DIO_PORTB,2,DIO_HIGH);
			startTimer(PS1024);
			LED_count=1;
		}
		else if (LED_count==1)
		{
			DIO_SetPinValue(DIO_PORTA,0,DIO_LOW);
			DIO_SetPinValue(DIO_PORTB,2,DIO_LOW);
			DIO_togglepinvalue(DIO_PORTA,1);
			DIO_togglepinvalue(DIO_PORTB,1);
			startTimer(PS1024);
			LED_count=2;
		}
		
		else if (LED_count==2)
		{
			DIO_SetPinValue(DIO_PORTA,1,DIO_LOW);
			DIO_SetPinValue(DIO_PORTB,1,DIO_LOW);
			DIO_SetPinValue(DIO_PORTA,2,DIO_HIGH);
			DIO_SetPinValue(DIO_PORTB,0,DIO_HIGH);
			startTimer(PS1024);
			LED_count=0;
		}*/
		
	
	}
}


