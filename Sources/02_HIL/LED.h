/*
** Project: Calculator for KL25Z
** File   : LED.h
** Author : Ivan Valadez
** Date   : 6 - October - 2018
**
** Overview: Header file containing
**
** $Log$
*/
#ifndef LEDS_H_
#define LEDS_H_

#include "derivative.h"
#include "GPIO.h"

typedef enum
{
    eFALSE_LED = eFALSE_GPIO,
    eTRUE_LED = eTRUE_GPIO

}eSTATUS_LED_t;

typedef enum
{
    eRED_LED,
    eGREEN_LED,
    eBLUE_LED

}eCOLORS_LED_t;

typedef ePORTx_GPIO_t ePORTx_LED_t;

typedef ePINx_GPIO_t  ePINx_LED_t;

/*
** Initializes required leds on board KL25Z.
** Compare which led you want to use and then call a function of initialization
** from GPIO.h and its value of return will be the value of return of efInit_LED
*/
eSTATUS_LED_t efInit_LED   (eCOLORS_LED_t eColor);

/*
** Turn on the required led calling the function clear from GPIO.h
** This is because leds on KL25Z turn on with a logic 0
*/
void vfTurnOn_LED  (eCOLORS_LED_t eColor);

/*
** Turn off the required led calling the function set from GPIO.h
** This is because leds on KL25Z turn off with a logic 1
*/
void vfTurnOff_LED(eCOLORS_LED_t eColor);

/*
** Change the state of the required led calling the function
** Toggle from GPIO_driver.h
*/
void vfToggle_LED (eCOLORS_LED_t eColor);
/*
** Read the current state of the required led calling a function
** Read from GPIO.h
*/
eSTATUS_LED_t efRead_LED   (eCOLORS_LED_t eColor);

/*
** Makes a decrement count until get to 0
** It is for wasting time
*/
void vfdelay_BUTTON(uint32_t u32Time);

#endif /* LEDS_H_ */
