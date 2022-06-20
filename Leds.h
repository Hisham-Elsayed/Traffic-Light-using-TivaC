 /******************************************************************************
 *
 * Module: Leds
 *
 * File Name: Leds.h
 *
 * Description: Header file for Leds Driver
 *
 * Author: Team 19
 ******************************************************************************/
#include "std_types.h"

#ifndef LEDS_H
#define LEDS_H

/*************************** Definitions ******************************/
#define GPIO_PORTF_PRIORITY_MASK      0xFF1FFFFF
#define GPIO_PORTF_PRIORITY_BITS_POS  21
#define GPIO_PORTF_INTERRUPT_PRIORITY 2


/*************************** Function Prototype ******************************/
/* Fucntion for initializing PORTA LEDS (PA2,PA3 and PA4) */
void PORTA_Init();

/* Fucntion for initializing PORTF LEDS (PF1,PF2 and PF3) */
void PORTF_Init();



#endif