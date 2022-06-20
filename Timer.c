 /******************************************************************************
 *
 * Module: Timer
 *
 * File Name: Timer.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Timer0A and Timer1A Drivers
 *
 * Author: Team 19
 ******************************************************************************/



#include "tm4c123gh6pm.h"
#include "std_types.h"
#include "Timer.h"
/*************************** Function Definitions ******************************/
void Timer0A_Init()
{
    /* Steps:
   * 1- Set RCGCTIMER to TIMER A
     2- Disable Timer before Initialization
     3- 32-bit mode TIMER
     4- Set TIMER A mode Register (TAMR) to 0x02 --> (Count Down),Periodic
     5- Set Timer A CTL Register to 0x03 --> Set TAEN to 1 (Timer A is enabled and begins counting)
                                             Set TASTALL to 1 (Timer A freezes counting while the processor is halted by the debugger)                                          
  */
    SYSCTL_RCGCTIMER_R |= 0x01;
    TIMER0_CTL_R = 0;
    TIMER0_CFG_R = 0;
    TIMER0_TAMR_R |= 0x02;
    TIMER0_CTL_R |= 0x03;
    
     /* Assign priority level 4 to the TIMER 0A Interrupt */
    NVIC_PRI4_R =  (NVIC_PRI4_R & TIMER0A_PRIORITY_MASK ) | (TIMER0A_INTERRUPT_PRIORITY << TIMER0A_PRIORITY_BITS_POS );
}

void Timer0A_delayms(int time)
{
  TIMER0_CTL_R = 0;  /* Disable TIMER before Initialization */
  TIMER0_TAILR_R = 16000 * time -1;  /* Enable TIMER0 internal load register */
  TIMER0_ICR_R= 0x01;  /* Clear Timer Timeout flag (Clear Interrupt) */
  TIMER0_IMR_R = 0x01;
  TIMER0_CTL_R |= 0x03;
  NVIC_EN0_R = 1<<19;
  
  
  
}

void Timer1A_Init()
{
    /* Steps:
   * 1- Set RCGCTIMER to TIMER A
     2- Disable Timer before Initialization
     3- 32-bit mode TIMER
     4- Set TIMER A mode Register (TAMR) to 0x02 --> (Count Down),Periodic
     5- Set Timer A CTL Register to 0x03 --> Set TAEN to 1 (Timer A is enabled and begins counting)
                                             Set TASTALL to 1 (Timer A freezes counting while the processor is halted by the debugger)                                          
  */
    SYSCTL_RCGCTIMER_R |= 0x02;
    TIMER1_CTL_R = 0;
    TIMER1_CFG_R = 0;
    TIMER1_TAMR_R |= 0x02;
    TIMER1_CTL_R |= 0x03;
}

void Timer1A_delayms(int time)
{
  TIMER1_CTL_R = 0;  /* Disable TIMER before Initialization */
  TIMER1_TAILR_R = 16000 * time -1;  /* Enable TIMER1 internal load register */
  TIMER1_ICR_R= 0x01;  /* Clear Timer Timeout flag (Clear Interrupt) */  
  TIMER1_CTL_R |= 0x03;
  while((TIMER1_RIS_R & 0x1) == 0); /* Wait for flag to be 1 */   
}





