/*
 * app.c
 *
 * Created: 8/11/2022 3:42:14 PM
 *  Author: Ismail
 */ 
#include "app.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/BIT_MATH.h"
#include "../MCAL/STD_TYPES.h"
#include "../MCAL/TIMERS/TIMERS.h"
#include "../MCAL/Interrupts/INT.h"


void app()
{
	LED_count=0;
while(1){	
		if (LED_count==0)
		{
			DIO_SetPinValue(DIO_PORTA,1,DIO_LOW);//YELLOW_CAR
			DIO_SetPinValue(DIO_PORTA,0,DIO_HIGH);//RED-CAR
			startTimer(PS1024,20);
			LED_count=1;
		}
		else if (LED_count==1)
		{
			DIO_SetPinValue(DIO_PORTA,0,DIO_LOW);
			for (u8 i=0;i<10;i++)
			{
				DIO_togglepinvalue(DIO_PORTA,1);
				startTimer(PS64,32);
			}
			LED_count=2;
		}
		
		else if (LED_count==2)
		{
			DIO_SetPinValue(DIO_PORTA,1,DIO_LOW);
			DIO_SetPinValue(DIO_PORTA,2,DIO_HIGH);
			startTimer(PS1024,20);
			LED_count=3;
		}
		else if (LED_count==3)
		{
			DIO_SetPinValue(DIO_PORTA,2,DIO_LOW);
			for (u8 i=0;i<10;i++)
			{
				DIO_togglepinvalue(DIO_PORTA,1);
				startTimer(PS64,32);
			}
			LED_count=0;
			
		}
}
}