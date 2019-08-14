/*
** Project: Calculator for KL25Z
** File   : BUTTON_driver.h
** Author : Ivan Valadez
** Date   : 2 - October - 2018
**
** Overview: Header file containing
**
** $Log$
*/
#ifndef BUTTON_H_
#define BUTTON_H_

#include "derivative.h"
#include "GPIO.h"

typedef ePINx_GPIO_t   ePINx_BUTTON_t;

typedef ePORTx_GPIO_t  ePORTx_BUTTON_t;

typedef eINOUT_GPIO_t  eINOUT_BUTTON_t;

typedef enum
{
    eFALSE_BUTTON = eFALSE_GPIO,
    eTRUE_BUTTON = eTRUE_GPIO

}eSTATUS_BUTTON_t;

typedef enum
{
    ePRESSED_BUTTON,
    eNOT_PRESSED_BUTTTON

}eSTATE_BUTTON_t;

typedef struct
{
    ePORTx_BUTTON_t ePort;
    ePINx_BUTTON_t  ePin;
    eSTATE_BUTTON_t eState;
    uint16_t        u16Debounce;

}sBUTTON_t;

/*
** Initialize the port and pin as input that you will use as button.
** Also, verify the arguments passed are valid or not and returns
** a boolean value for success or fail of the process.
*/
eSTATUS_BUTTON_t efCreate_BUTTON  (sBUTTON_t *psButton, ePORTx_BUTTON_t ePort,ePINx_BUTTON_t ePin);

/*
** Read the value of the button that you create and return its state (Logic 1 or 0)
** Read twice the value to avoid some errors and use the function delay as a debouncer
** NOTE: Check configuration of GPIO.c to see if the button is pull-up or pull-down
*/
eSTATUS_BUTTON_t efRead_BUTTON    (sBUTTON_t *psButton);
/*
** Read the value of the button that you create and return its state (Logic 1 or 0)
** Also, the function it is not blocking. You MUST adapt the define DEBOUNCING
** The definition is not a time, it is a Iteration of the function.
** It determine the times you use this function and the value of the pin is still true
*/
eSTATUS_BUTTON_t efReadNonBlocking_BUTTON(sBUTTON_t *psButton);

#endif /* BUTTONS_DRIVER_H_ */
