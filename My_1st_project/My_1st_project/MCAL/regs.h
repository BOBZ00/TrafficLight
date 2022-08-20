/*
 * regs.h
 *
 * Created: 8/3/2022 2:02:21 PM
 *  Author: Ismail
 */ 


#ifndef REGS_H_
#define REGS_H_

#include "STD_TYPES.h"
//*********DIO REGS*********//
//PORTA
#define PORTA *((volatile u8*)0x3B)
#define DDRA *((volatile u8*)0x3A)
#define PINA *((volatile u8*)0x39)

//PORTB
#define PORTB *((volatile u8*)0x38)
#define DDRB *((volatile u8*)0x37)
#define PINB *((volatile u8*)0x36)

//PORTC
#define PORTC *((volatile u8*)0x35)
#define DDRC *((volatile u8*)0x34)
#define PINC *((volatile u8*)0x33)

//PORTD
#define PORTD *((volatile u8*)0x32)
#define DDRD *((volatile u8*)0x31)
#define PIND *((volatile u8*)0x30)

//*********TIMER REGS*********//
#define TCCR0 *((volatile u8*)0x53)
#define TCNT0 *((volatile u8*)0x52)
#define TIFR *((volatile u8*)0x58)

//*********INTERRUPT REGS*********//
#define SREG *((volatile u8*)0x5F)//status register
#define MCUCR *((volatile u8*)0x55)//Interrupt sense control
#define GICR *((volatile u8*)0x5B)//Enable/Disable Interrupt
#define GIFR *((volatile u8*)0x5A)//Enable/Disable Interrupt


#endif /* REGS_H_ */