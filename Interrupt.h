 /******************************************************************************
 *
 * Module: Interrupt
 *
 * File Name: Interrupt.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Interrupts
 *
 * Author: Team 19
 ******************************************************************************/

#include "std_types.h"

#ifndef INTERRUPT_H
#define INTERRUPT_H


#define Enable_Exceptions()    __asm("CPSIE I") /* Change Processor state Interrupt Enable */
#define Wait_For_Interrupt()   __asm("WFI")     /* Wait For Interrupt */

void TIMER0_Handler();
void Pedestrian_NS();


void Pedestrian_Handler(void);



#endif