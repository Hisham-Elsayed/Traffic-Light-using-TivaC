 /******************************************************************************
 *
 * Module: Timer
 *
 * File Name: Timer.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Timer0A and Timer1A Drivers
 *
 * Author: Team 19
 ******************************************************************************/
#include "std_types.h"

#ifndef TIMER_H
#define TIMER_H

/*************************** Definitions ******************************/

#define TIMER0A_PRIORITY_MASK  0x1FFFFFFF
#define TIMER0A_INTERRUPT_PRIORITY  4
#define TIMER0A_PRIORITY_BITS_POS   29

/*
#define TIMER1A_PRIORITY_MASK  0xFFFF1FFF
#define TIMER1A_INTERRUPT_PRIORITY  5
#define TIMER1A_PRIORITY_BITS_POS   13
*/

/*************************** Function Prototype ******************************/

/* Function used to Initialize TIMER0 A */
void Timer0A_Init();

void Timer0A_delayms(int time);


void Timer1A_Init();

void Timer1A_delayms(int time);





#endif


