 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 * Author: Team 19
 ******************************************************************************/


#include "bitwise_operation.h"
#include "tm4c123gh6pm.h"
#include "DIO.h"

/*************************** Function Definitions ******************************/

void DIO_Init(uint8 port_id,uint8 pin_id,uint8 direction)
{
  if((port_id<=PORTF_ID)&&(pin_id<=PIN7_ID))
  {
  switch (port_id)
  {
      /******* Port A *******/
  case PORTA_ID:
    Set_Bit(SYSCTL_RCGCGPIO_R,PIN0_ID);
    while((SYSCTL_PRGPIO_R&0x00000001) == 0){};
    GPIO_PORTA_LOCK_R = 0x4C4F434B;
    Set_Bit(GPIO_PORTA_CR_R,pin_id);
    if(direction==INPUT)
                      {
                    Clear_Bit(GPIO_PORTA_DIR_R,pin_id);
                }
              else if(direction==OUTPUT)
                {
                    Set_Bit(GPIO_PORTA_DIR_R,pin_id);
                }
                     if(pin_id==PIN0_ID || pin_id==PIN4_ID)
              {
                    Set_Bit(GPIO_PORTA_PUR_R,pin_id);
              }
              
                    Set_Bit(GPIO_PORTA_DEN_R,pin_id);
              break;
             /******* Port B *******/ 
    case PORTB_ID:
    Set_Bit(SYSCTL_RCGCGPIO_R,PIN1_ID);
    while((SYSCTL_PRGPIO_R&0x00000002) == 0){};
    GPIO_PORTB_LOCK_R = 0x4C4F434B;
    Set_Bit(GPIO_PORTB_CR_R,pin_id);
    if(direction==INPUT)
                      {
                    Clear_Bit(GPIO_PORTB_DIR_R,pin_id);
                }
              else if(direction==OUTPUT)
                {
                    Set_Bit(GPIO_PORTB_DIR_R,pin_id);
                }
                     if(pin_id==PIN0_ID || pin_id==PIN4_ID)
              {
                    Set_Bit(GPIO_PORTB_PUR_R,pin_id);
              }
              
                    Set_Bit(GPIO_PORTF_DEN_R,pin_id);
              break;
              /******* Port C *******/
                  case PORTC_ID:
    Set_Bit(SYSCTL_RCGCGPIO_R,PIN2_ID);
    while((SYSCTL_PRGPIO_R&0x00000004) == 0){};
    GPIO_PORTC_LOCK_R = 0x4C4F434B;
    Set_Bit(GPIO_PORTC_CR_R,pin_id);
    if(direction==INPUT)
                     {
                    Clear_Bit(GPIO_PORTC_DIR_R,pin_id);
                }
              else if(direction==OUTPUT)
                {
                    Set_Bit(GPIO_PORTC_DIR_R,pin_id);
                }
                     if(pin_id==PIN0_ID || pin_id==PIN4_ID)
              {
                    Set_Bit(GPIO_PORTC_PUR_R,pin_id);
              }
              
                    Set_Bit(GPIO_PORTC_DEN_R,pin_id);
              break;
              /******* Port D *******/
                  case PORTD_ID:
    Set_Bit(SYSCTL_RCGCGPIO_R,PIN3_ID);
    while((SYSCTL_PRGPIO_R&0x00000008) == 0){};
    GPIO_PORTD_LOCK_R = 0x4C4F434B;
    Set_Bit(GPIO_PORTD_CR_R,pin_id);
    if(direction==INPUT)
                     {
                    Clear_Bit(GPIO_PORTD_DIR_R,pin_id);
                }
              else if(direction==OUTPUT)
                {
                    Set_Bit(GPIO_PORTD_DIR_R,pin_id);
                }
                     if(pin_id==PIN0_ID || pin_id==PIN4_ID)
              {
                    Set_Bit(GPIO_PORTD_PUR_R,pin_id);
              }
              
                    Set_Bit(GPIO_PORTD_DEN_R,pin_id);
              break;
              /******* Port E *******/
          case PORTE_ID:
    Set_Bit(SYSCTL_RCGCGPIO_R,PIN4_ID);
    while((SYSCTL_PRGPIO_R&0x00000010) == 0){};
    GPIO_PORTE_LOCK_R = 0x4C4F434B;
    Set_Bit(GPIO_PORTE_CR_R,pin_id);
    if(direction==INPUT)
                    {
                    Clear_Bit(GPIO_PORTE_DIR_R,pin_id);
                }
              else if(direction==OUTPUT)
                {
                    Set_Bit(GPIO_PORTE_DIR_R,pin_id);
                }
                     if(pin_id==PIN0_ID || pin_id==PIN4_ID)
              {
                    Set_Bit(GPIO_PORTE_PUR_R,pin_id);
              }
              
                    Set_Bit(GPIO_PORTE_DEN_R,pin_id);
              break;
      /******* Port F *******/
                  case PORTF_ID:
    Set_Bit(SYSCTL_RCGCGPIO_R,PIN5_ID);
    while((SYSCTL_PRGPIO_R&0x00000020) == 0){};
    GPIO_PORTF_LOCK_R = 0x4C4F434B;
    Set_Bit(GPIO_PORTF_CR_R,pin_id);
    if(direction==INPUT)
                {
                    Clear_Bit(GPIO_PORTF_DIR_R,pin_id);
                }
              else if(direction==OUTPUT)
                {
                    Set_Bit(GPIO_PORTF_DIR_R,pin_id);
                }
                     if(pin_id==PIN0_ID || pin_id==PIN4_ID)
              {
                    Set_Bit(GPIO_PORTF_PUR_R,pin_id);
              }
              
                    Set_Bit(GPIO_PORTF_DEN_R,pin_id);
              break;
  }
  }
}

void DIO_WritePin(uint8 port_id,uint8 pin_id,uint8 value)
{
  if (value == LOGIC_LOW)
  {
     switch(port_id)
                {
                case PORTA_ID: Clear_Bit(GPIO_PORTA_DATA_R, pin_id); 
                break;
                case PORTB_ID: Clear_Bit(GPIO_PORTB_DATA_R, pin_id); 
                break;
                case PORTC_ID: Clear_Bit(GPIO_PORTC_DATA_R, pin_id); 
                break;
                case PORTD_ID: Clear_Bit(GPIO_PORTD_DATA_R, pin_id); 
                break;
                case PORTE_ID: Clear_Bit(GPIO_PORTE_DATA_R, pin_id); 
                break;
                case PORTF_ID: Clear_Bit(GPIO_PORTF_DATA_R, pin_id); 
                break;
                }
  }
     else if (value == LOGIC_HIGH)
     {
        switch(port_id)
                {
                case PORTA_ID: Set_Bit(GPIO_PORTA_DATA_R, pin_id); 
                break;
                case PORTB_ID: Set_Bit(GPIO_PORTB_DATA_R, pin_id); 
                break;
                case PORTC_ID: Set_Bit(GPIO_PORTC_DATA_R, pin_id); 
                break;
                case PORTD_ID: Set_Bit(GPIO_PORTD_DATA_R, pin_id); 
                break;
                case PORTE_ID: Set_Bit(GPIO_PORTE_DATA_R, pin_id); 
                break;
                case PORTF_ID: Set_Bit(GPIO_PORTF_DATA_R, pin_id); 
                break;
                }
     }
  }

void DIO_WritePort(uint8 port_id,uint8 value)
{
  switch(port_id)
  {
                case PORTA_ID: 
                  GPIO_PORTA_DATA_R = value; 
                break;
                case PORTB_ID: 
                  GPIO_PORTB_DATA_R = value; 
                break;
                case PORTC_ID:
                  GPIO_PORTC_DATA_R = value; 
                break;
                case PORTD_ID:
                  GPIO_PORTD_DATA_R = value; 
                break;
                case PORTE_ID:
                  GPIO_PORTE_DATA_R = value; 
                break;
                case PORTF_ID: 
                  GPIO_PORTF_DATA_R = value; 
                break;
  }
}

uint8 DIO_ReadPin(uint8 port_id, uint8 pin_id)
{
  uint8 level=0;        // Set return value equal zero at the beginning //
  
      switch(port_id)
      {
        case PORTA_ID:
          level=Get_Bit(GPIO_PORTA_DATA_R,pin_id);
          break;
           case PORTB_ID:
          level=Get_Bit(GPIO_PORTA_DATA_R,pin_id);
          break;
           case PORTC_ID:
          level=Get_Bit(GPIO_PORTA_DATA_R,pin_id);
          break;
           case PORTD_ID:
          level=Get_Bit(GPIO_PORTA_DATA_R,pin_id);
          break;
           case PORTE_ID:
          level=Get_Bit(GPIO_PORTA_DATA_R,pin_id);
          break;
           case PORTF_ID:
          level=Get_Bit(GPIO_PORTA_DATA_R,pin_id);
          break;
      }
      return level;
}

uint8 DIO_ReadPort(uint8 port_id)
{
      uint8 level=0;
      switch(port_id)
      {
      case PORTA_ID: level = GPIO_PORTA_DATA_R; break;
      case PORTB_ID: level = GPIO_PORTB_DATA_R; break;
      case PORTC_ID: level = GPIO_PORTC_DATA_R; break;
      case PORTD_ID: level = GPIO_PORTD_DATA_R; break;
      case PORTE_ID: level = GPIO_PORTE_DATA_R; break;
      case PORTF_ID: level = GPIO_PORTF_DATA_R; break;
      }
      return level;
}

void DIO_SetupPortDirection(uint8 port_id, DIO_PortDirectionType Direction)
{
  if (port_id <= PORTF_ID)
  {
    switch (port_id)
    {
      /******* Port A *******/
    case PORTA_ID:
      {           
    Set_Bit(SYSCTL_RCGCGPIO_R,PIN0_ID);
    while((SYSCTL_PRGPIO_R&0x00000001) == 0){};
    GPIO_PORTA_LOCK_R = 0x4C4F434B;
    GPIO_PORTA_CR_R = PORT_OUTPUT;
    if(Direction== PORT_INPUT)
                      {
                     GPIO_PORTA_DIR_R = CLEAR_PORT;
                     GPIO_PORTA_PUR_R = SET_PORT;
                }
              else if(Direction==PORT_OUTPUT)
                {
                    GPIO_PORTA_DIR_R = SET_PORT;
                }
                    GPIO_PORTA_DEN_R = SET_PORT;
              break;
      }
      /******* Port B *******/
    case PORTB_ID:
      {           
    Set_Bit(SYSCTL_RCGCGPIO_R,PIN1_ID);
    while((SYSCTL_PRGPIO_R&0x00000002) == 0){};
    GPIO_PORTB_LOCK_R = 0x4C4F434B;
    GPIO_PORTB_CR_R = PORT_OUTPUT;
    if(Direction== PORT_INPUT)
                      {
                     GPIO_PORTB_DIR_R = CLEAR_PORT;
                     GPIO_PORTB_PUR_R = SET_PORT;
                }
              else if(Direction==PORT_OUTPUT)
                {
                    GPIO_PORTB_DIR_R = SET_PORT;
                }
                    GPIO_PORTB_DEN_R = SET_PORT;
              break;
      }
    /******* Port C *******/
    case PORTC_ID:
      {           
    Set_Bit(SYSCTL_RCGCGPIO_R,PIN2_ID);
    while((SYSCTL_PRGPIO_R&0x00000004) == 0){};
    GPIO_PORTC_LOCK_R = 0x4C4F434B;
    GPIO_PORTC_CR_R = PORT_OUTPUT;
    if(Direction== PORT_INPUT)
                      {
                     GPIO_PORTC_DIR_R = CLEAR_PORT;
                     GPIO_PORTC_PUR_R = SET_PORT;
                }
              else if(Direction==PORT_OUTPUT)
                {
                    GPIO_PORTC_DIR_R = SET_PORT;
                }
                    GPIO_PORTC_DEN_R = SET_PORT;
              break;
      }
      /******* Port D *******/
    case PORTD_ID:
      {           
    Set_Bit(SYSCTL_RCGCGPIO_R,PIN3_ID);
    while((SYSCTL_PRGPIO_R&0x00000008) == 0){};
    GPIO_PORTD_LOCK_R = 0x4C4F434B;
    GPIO_PORTD_CR_R = PORT_OUTPUT;
    if(Direction== PORT_INPUT)
                      {
                     GPIO_PORTD_DIR_R = CLEAR_PORT;
                     GPIO_PORTD_PUR_R = SET_PORT;
                }
              else if(Direction==PORT_OUTPUT)
                {
                    GPIO_PORTD_DIR_R = SET_PORT;
                }
                    GPIO_PORTD_DEN_R = SET_PORT;
              break;
      }
      /******* Port E *******/
    case PORTE_ID:
      {           
    Set_Bit(SYSCTL_RCGCGPIO_R,PIN4_ID);
    while((SYSCTL_PRGPIO_R&0x00000010) == 0){};
    GPIO_PORTE_LOCK_R = 0x4C4F434B;
    GPIO_PORTE_CR_R = PORT_OUTPUT;
    if(Direction== PORT_INPUT)
                      {
                     GPIO_PORTE_DIR_R = CLEAR_PORT;
                     GPIO_PORTE_PUR_R = SET_PORT;
                }
              else if(Direction==PORT_OUTPUT)
                {
                    GPIO_PORTE_DIR_R = SET_PORT;
                }
                    GPIO_PORTE_DEN_R = SET_PORT;
              break;
      }
      /******* Port F *******/
    case PORTF_ID:
      {           
    Set_Bit(SYSCTL_RCGCGPIO_R,PIN5_ID);
    while((SYSCTL_PRGPIO_R&0x00000020) == 0){};
    GPIO_PORTF_LOCK_R = 0x4C4F434B;
    GPIO_PORTF_CR_R = PORT_OUTPUT;
    if(Direction== PORT_INPUT)
                      {
                     GPIO_PORTF_DIR_R = CLEAR_PORT;
                     GPIO_PORTF_PUR_R = SET_PORT;
                }
              else if(Direction==PORT_OUTPUT)
                {
                    GPIO_PORTF_DIR_R = SET_PORT;
                }
                    GPIO_PORTF_DEN_R = SET_PORT;
              break;
      }
    }
  }
}

      
        
      
      
      
      
      
      
      
      
      
      
      
      
      