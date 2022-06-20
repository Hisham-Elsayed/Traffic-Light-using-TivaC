 /******************************************************************************
 *
 * Module: Application
 *
 * File Name: main.c
 *
 * Description: Application file for Traffic Light Project
 *
 * Author: Team 19
 ******************************************************************************/
#include "tm4c123gh6pm.h"
#include "Timer.h"
#include "DIO.h"
#include "Interrupt.h"
#include "Leds.h"




int main()
{
   PORTA_Init();
   PORTF_Init();
   Ped_N_S();
   Ped_E_W();
   
   Timer0A_Init();
   Timer1A_Init();
    
   Timer0A_delayms(1000);
   Timer1A_delayms(1000);
 
   Enable_Exceptions();
   
   /* Disable All Leds at the beginning */
   GPIO_PORTF_DATA_R =0;
   GPIO_PORTA_DATA_R =0;
   GPIO_PORTD_DATA_R = 0;
   GPIO_PORTE_DATA_R = 0;
   
  
  while(1)
  {
    Wait_For_Interrupt();
  }
}
