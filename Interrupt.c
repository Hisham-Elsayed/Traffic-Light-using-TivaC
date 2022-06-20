 /******************************************************************************
 *
 * Module: Interrupt
 *
 * File Name: Interrupt.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Interrupts
 *
 * Author: Team 19
 ******************************************************************************/
#include "Interrupt.h"
#include "DIO.h"
#include "Timer.h"
#include "tm4c123gh6pm.h"

/********************* Global Variables ******************/
uint8 flag_Car= 0;



void TIMER0_Handler()
{ 
  TIMER0_ICR_R = TIMER_ICR_TATOCINT; 
  
  flag_Car++;
 
   GPIO_PORTD_DATA_R = (GPIO_PORTD_DATA_R & 0xF9) | 0x04; /* Turn on NS Red Pedestrian Led and Turn off the Green Ped light */
   GPIO_PORTE_DATA_R = (GPIO_PORTE_DATA_R & 0xCF) | 0x20; /* Turn on EW Red Pedestrian Led and Turn off the Green Ped light */  
  
  /******************************* First Car Traffic Light (North to South) **********************/
  if (flag_Car < 5)
  {
  GPIO_PORTF_DATA_R = (GPIO_PORTF_DATA_R & 0xF1) | 0x08;   /* Turn on Green LED and disable the others */
  /* Keep The Red Light on in the other traffic */
   DIO_WritePin(PORTA_ID,PIN4_ID,LOGIC_HIGH);


  }
  if (flag_Car == 5)
  {
    /* Turn on Yellow LED and disable the others */
     DIO_WritePin(PORTD_ID,PIN7_ID,LOGIC_HIGH);
     GPIO_PORTF_DATA_R &= ~(1<<1);
      GPIO_PORTF_DATA_R &= ~(1<<3);

      /* Keep The Red Light on in the other traffic */
         DIO_WritePin(PORTA_ID,PIN4_ID,LOGIC_HIGH);
  
  }
  if (flag_Car == 7)
  {
     GPIO_PORTF_DATA_R = (GPIO_PORTF_DATA_R & 0xF1) | 0x02;  /* Turn on Red LED and disable the others */
     DIO_WritePin(PORTD_ID,PIN7_ID,LOGIC_LOW);
  }
    /******************************* Second Car Traffic Light (East to West) **********************/
  if (flag_Car < 12 && flag_Car > 7)
  {   
     GPIO_PORTA_DATA_R = (GPIO_PORTA_DATA_R & 0xE3) | 0x04;  /* Turn on Green LED in PORTA and disable the others */
  }
  if (flag_Car == 12)
  {     
     GPIO_PORTA_DATA_R = (GPIO_PORTA_DATA_R & 0xE3) | 0x08;/* Turn on Yellow LED in PORTA and disable the others */
  }
  if (flag_Car == 14)
  {
    GPIO_PORTA_DATA_R = (GPIO_PORTA_DATA_R & 0xE3) | 0x10;  /* Turn on Red LED in PORTA and disable the others */
    
    flag_Car =0;
  } 
}
 
void Pedestrian_NS()
{
 
  /* Save Last status of every LED in both traffic lights */
    uint32 ledStateG1 = DIO_ReadPin(PORTF_ID,PIN3_ID);
    uint32 ledStateY1 = DIO_ReadPin(PORTD_ID,PIN7_ID);
    uint32 ledStateR1 = DIO_ReadPin(PORTF_ID,PIN1_ID);
      
    uint32 ledStateG2 = DIO_ReadPin(PORTA_ID,PIN1_ID);
    uint32 ledStateY2 = DIO_ReadPin(PORTA_ID,PIN2_ID);
    uint32 ledStateR2 = DIO_ReadPin(PORTA_ID,PIN3_ID);
    
  /* Turn off North to South Traffic Lights except the Red Light */
   GPIO_PORTF_DATA_R = (GPIO_PORTF_DATA_R & 0xF1) | 0x02;  /* Turn on Red LED and disable the others */

GPIO_PORTD_DATA_R = (GPIO_PORTD_DATA_R & 0xF9) | 0x02; /* Turn on Green Pedestrian Led and Turn off the Red Ped light */

GPIO_PORTE_DATA_R = (GPIO_PORTE_DATA_R & 0xCF) | 0x20; /* Turn on Red ped light only in EW */

  /* Wait two seconds */
   Timer1A_delayms(1000);
   Timer1A_delayms(1000);
   
GPIO_PORTD_DATA_R = (GPIO_PORTD_DATA_R & 0xF9) | 0x04; /* Turn on Red Pedestrian Led (North to South) and Turn off the Green Ped light */    
   
   
/* Start from Where the leds had left off */
DIO_WritePin(PORTF_ID,PIN3_ID,ledStateG1);
DIO_WritePin(PORTD_ID,PIN7_ID,ledStateY1);
DIO_WritePin(PORTF_ID,PIN1_ID,ledStateR1);

DIO_WritePin(PORTA_ID,PIN1_ID,ledStateG2);
DIO_WritePin(PORTA_ID,PIN2_ID,ledStateY2);
DIO_WritePin(PORTA_ID,PIN3_ID,ledStateR2);
}

void Pedestrian_EW()
{
  /* Save Last status of every LED in both traffic lights */
    uint8 ledStateG1 = DIO_ReadPin(PORTF_ID,PIN3_ID);
    uint32 ledStateY1 = DIO_ReadPin(PORTD_ID,PIN7_ID);
    uint8 ledStateR1 = DIO_ReadPin(PORTF_ID,PIN1_ID);
      
    uint32 ledStateG2 = DIO_ReadPin(PORTA_ID,PIN1_ID);
    uint32 ledStateY2 = DIO_ReadPin(PORTA_ID,PIN2_ID);
    uint32 ledStateR2 = DIO_ReadPin(PORTA_ID,PIN3_ID);

    /* Turn off East to West Traffic Lights except the Red Light */
   GPIO_PORTA_DATA_R = (GPIO_PORTA_DATA_R & 0xE3) | 0x10;  /* Turn on Red LED in PORTA and disable the others */

   
   GPIO_PORTD_DATA_R = (GPIO_PORTD_DATA_R & 0xF9) | 0x04; /* Turn on Red Pedestrian Led (North to South) and Turn off the Green Ped light */
   GPIO_PORTE_DATA_R = (GPIO_PORTE_DATA_R & 0xCF) | 0x10; /* Turn on Green Pedestrian Led and Turn off the Red Ped light */
      
   /* Wait two seconds */
   Timer1A_delayms(1000);
   Timer1A_delayms(1000);
   
   GPIO_PORTE_DATA_R = (GPIO_PORTE_DATA_R & 0xCF) | 0x20; /* Turn on Red Pedestrian Led and Turn off the Green Ped light */  
  
   
   
   /* Start from Where the leds had left off */
   DIO_WritePin(PORTF_ID,PIN3_ID,ledStateG1);
   DIO_WritePin(PORTD_ID,PIN7_ID,ledStateY1);
   DIO_WritePin(PORTF_ID,PIN1_ID,ledStateR1);

   DIO_WritePin(PORTA_ID,PIN1_ID,ledStateG2);
   DIO_WritePin(PORTA_ID,PIN2_ID,ledStateY2);
   DIO_WritePin(PORTA_ID,PIN3_ID,ledStateR2);
}


void Pedestrian_Handler()
{ 
  
    if ( GPIO_PORTF_MIS_R & 0x10)
  {
   
     Pedestrian_EW();  
      GPIO_PORTF_ICR_R   |= (1<<4);  /* Clear Trigger flag for PF4 (Interupt Flag) */
     
  }
   else if ( GPIO_PORTF_MIS_R & 0x01  )
  {
     
       Pedestrian_NS();
      GPIO_PORTF_ICR_R   |= (1<<0);  /* Clear Trigger flag for PF0 (Interupt Flag) */
  }
  
  
}
  
