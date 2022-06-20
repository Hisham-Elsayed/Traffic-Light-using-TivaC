/************************************
           TEAM 19 
***********************************/


#include "std_types.h"
 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 * Author: Team 19
 ******************************************************************************/

#ifndef DIO_H
#define DIO_H


/*************************** Types Declaration ******************************/
typedef enum
{
	PORT_INPUT,PORT_OUTPUT = 0xFFFFFFFF
}DIO_PortDirectionType;

/*************************** Function Prototype ******************************/
void DIO_Init(uint8 port_id,uint8 pin_id,uint8 direction);
void DIO_WritePin(uint8 port_id,uint8 pin_id,uint8 value);
void DIO_WritePort(uint8 port_id,uint8 value);
void DIO_SetupPortDirection(uint8 port_id,DIO_PortDirectionType Direction);



uint8 DIO_ReadPin(uint8 port_id, uint8 pin_id);
uint8 DIO_ReadPort(uint8 port_id);
/*****************************************************************************/

/*************************** Definitions ******************************/
#define PORTA_ID               1
#define PORTB_ID               2
#define PORTC_ID               3
#define PORTD_ID               4
#define PORTE_ID               5
#define PORTF_ID               6

#define PIN0_ID                0
#define PIN1_ID                1
#define PIN2_ID                2
#define PIN3_ID                3
#define PIN4_ID                4
#define PIN5_ID                5
#define PIN6_ID                6
#define PIN7_ID                7


#define LOGIC_HIGH             1
#define LOGIC_LOW              0

#define INPUT                  0
#define OUTPUT                 1

/* To Set all pins of PORT */
#define SET_PORT         0xFFFFFFFF
/* To Clear all pins of PORT */
#define CLEAR_PORT 0x00000000













#endif 