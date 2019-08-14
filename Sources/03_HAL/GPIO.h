/*
** Project: For KL25Z
** File   : GPIO.h
** Author : Ivan Valadez
** Date   : 14 - Agosto - 2019
**
** Overview: Header file
**
** $Log$
*/
#ifndef GPIO_H_
#define GPIO_H_

#include "derivative.h"

#define PORT_PCR_MUX_GPIO 1u

typedef enum
{
    ePORTA_GPIO,
    ePORTB_GPIO,
    ePORTC_GPIO,
    ePORTD_GPIO,
    ePORTE_GPIO

}ePORTx_GPIO_t;

typedef enum
{
    ePIN_0_GPIO,  ePIN_1_GPIO,  ePIN_2_GPIO,  ePIN_3_GPIO,
    ePIN_4_GPIO,  ePIN_5_GPIO,  ePIN_6_GPIO,  ePIN_7_GPIO,
    ePIN_8_GPIO,  ePIN_9_GPIO,  ePIN_10_GPIO, ePIN_11_GPIO,
    ePIN_12_GPIO, ePIN_13_GPIO, ePIN_14_GPIO, ePIN_15_GPIO,
    ePIN_16_GPIO, ePIN_17_GPIO, ePIN_18_GPIO, ePIN_19_GPIO,
    ePIN_20_GPIO, ePIN_21_GPIO, ePIN_22_GPIO, ePIN_23_GPIO,
    ePIN_29_GPIO, ePIN_30_GPIO

}ePINx_GPIO_t;

typedef enum
{
    eINPUT_GPIO,
    eOUTPUT_GPIO

}eINOUT_GPIO_t;

typedef enum
{
    eFALSE_GPIO,
    eTRUE_GPIO

}eSTATUS_GPIO_t;

typedef enum
{
    eLOW_GPIO  = 0,
    eHIGH_GPIO = 1

}eLOGIC_VAL_GPIO_t;

typedef unsigned char DATA_GPIO_t;

/*
** Initialize Clock, Port and Pin as an output or input and returns
** a confirmation of success if every process was made correctly
** or a confirmation of fail if the function couldn't complete the task
*/
eSTATUS_GPIO_t efInit_GPIO( ePORTx_GPIO_t ePort, ePINx_GPIO_t ePin, eINOUT_GPIO_t eInOut );

/*
** Writes a logic 1 in the port and pin that you pass as argument
*/
void vfSetPin_GPIO( ePORTx_GPIO_t ePort, ePINx_GPIO_t ePin );

/*
** Writes a logic 0 in the port and pin that you pass as argument
*/
void vfClearPin_GPIO( ePORTx_GPIO_t ePort, ePINx_GPIO_t ePin );

/*
** Toggle the value in the port and pin that you pass as argument
*/
void vfTogglePin_GPIO( ePORTx_GPIO_t ePort, ePINx_GPIO_t ePin );

/*
** Read the value logic of the required pin and return its status.
**    TRUE  = Logic 0
**    FALSE = Logic 1
*/
eSTATUS_GPIO_t efReadPin_GPIO( ePORTx_GPIO_t ePort, ePINx_GPIO_t ePin );

/*
** Writes a binary value (0 or 1) in the pin that you pass as argument
*/
void vfWritePin_GPIO( ePORTx_GPIO_t ePort, ePINx_GPIO_t ePin, eLOGIC_VAL_GPIO_t eValue );

/*
** Writes the value of a byte in the port you pass as argument
** NOTE: You will affect the complete register GPIOx_PDOR, so, be careful
*/
void vfWritePort_GPIO( ePORTx_GPIO_t ePort, DATA_GPIO_t Data );

#endif /* GPIO_H_ */
