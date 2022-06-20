 /******************************************************************************
 *
 * Module: Leds
 *
 * File Name: Leds.c
 *
 * Description: Source file for Leds Driver
 *
 * Author: Team 19
 ******************************************************************************/
#include "Leds.h"
#include "DIO.h"
#include "tm4c123gh6pm.h"

/*************************** Function Definitions ******************************/
void PORTA_Init()
{
  /* East to West car traffic light */
  DIO_Init(PORTA_ID,PIN2_ID,OUTPUT);
  DIO_Init(PORTA_ID,PIN3_ID,OUTPUT);
  DIO_Init(PORTA_ID,PIN4_ID,OUTPUT);
}

void PORTF_Init()
{
  /* Yellow LED in NS traffic */
  DIO_Init(PORTD_ID,PIN7_ID,OUTPUT);
  
  DIO_Init(PORTF_ID,PIN1_ID,OUTPUT);
  DIO_Init(PORTF_ID,PIN2_ID,OUTPUT);
  DIO_Init(PORTF_ID,PIN3_ID,OUTPUT);
  
  DIO_Init(PORTF_ID,PIN0_ID,INPUT); 
  GPIO_PORTF_IM_R   |= (1<<0);       /* Enable Interrupt on PF0 pin */  
  GPIO_PORTF_IS_R    &= ~(1<<0);      /* PF0 detect edges */
  GPIO_PORTF_IBE_R   &= ~(1<<0);      /* PF0 will detect a certain edge */
  GPIO_PORTF_IEV_R   &= ~(1<<0);      /* PF0 will detect a falling edge */
  GPIO_PORTF_ICR_R   |= (1<<0);       /* Clear Trigger flag for PF0 (Interupt Flag) */
  GPIO_PORTF_IM_R   |= (1<<0);       /* Enable Interrupt on PF0 pin */  
  
  DIO_Init(PORTF_ID,PIN4_ID,INPUT); 
  GPIO_PORTF_IM_R   |= (1<<0);       /* Enable Interrupt on PF0 pin */  
  GPIO_PORTF_IS_R    &= ~(1<<4);      /* PF4 detect edges */
  GPIO_PORTF_IBE_R   &= ~(1<<4);      /* PF4 will detect a certain edge */
  GPIO_PORTF_IEV_R   &= ~(1<<4);      /* PF4 will detect a falling edge */
  GPIO_PORTF_ICR_R   |= (1<<4);       /* Clear Trigger flag for PF4 (Interupt Flag) */
  GPIO_PORTF_IM_R    |= (1<<4);       /* Enable Interrupt on PF4 pin */
  
  
  /* Set GPIO PORTF priotiy as 2 by set Bit number 21, 22 and 23 with value 2 */
  NVIC_PRI7_R = (NVIC_PRI7_R & GPIO_PORTF_PRIORITY_MASK) | (GPIO_PORTF_INTERRUPT_PRIORITY<<GPIO_PORTF_PRIORITY_BITS_POS); 
  NVIC_EN0_R= 1<<30;  /* Enable NVIC Interrupt for GPIO PORTF by set bit number 30 in EN0 Register */
}

void Ped_N_S()
{
  
  DIO_Init(PORTD_ID,PIN1_ID,OUTPUT); // Green NS Ped //
  DIO_Init(PORTD_ID,PIN2_ID,OUTPUT); // Red NS Ped //
  
}

void Ped_E_W()
{
  DIO_Init(PORTE_ID,PIN4_ID,OUTPUT); // Green EW Ped //
  DIO_Init(PORTE_ID,PIN5_ID,OUTPUT); // Red EW Ped //
}
