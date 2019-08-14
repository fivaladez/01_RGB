/*
** Project: Calculator for KL25Z
** File   : Leds_driver.c
** Author : Ivan Valadez
** Date   : 6 - October - 2018
**
** Overview: C file containing
**
** $Log$
*/
#include "LED.h"

/* Ports and Pins from MCU KL25Z */
ePORTx_LED_t ePortRed_LED   = ePORTB_GPIO;
ePORTx_LED_t ePortGreen_LED = ePORTB_GPIO;
ePORTx_LED_t ePortBlue_LED  = ePORTD_GPIO;

ePINx_LED_t ePinRed_LED     = ePIN_18_GPIO;
ePINx_LED_t ePinGreen_LED   = ePIN_19_GPIO;
ePINx_LED_t ePinBlue_LED    = ePIN_1_GPIO;

eSTATUS_LED_t efInit_LED   (eCOLORS_LED_t eColor)
{
    eSTATUS_LED_t eStatus = eFALSE_LED;
    switch(eColor)
    {
    case eRED_LED:
        if((eStatus_GPIO_t)eTRUE_LED == efInit_GPIO(ePortRed_LED ,ePinRed_LED, eOUTPUT_GPIO))
        {
            eStatus = eTRUE_LED;
        }else {}
        break;
    case eGREEN_LED:
        if((eStatus_GPIO_t)eTRUE_LED == efInit_GPIO(ePortGreen_LED ,ePinGreen_LED, eOUTPUT_GPIO))
        {
            eStatus = eTRUE_LED;
        }else {}
        break;
    case eBLUE_LED:
        if((eStatus_GPIO_t)eTRUE_LED == efInit_GPIO(ePortBlue_LED ,ePinBlue_LED, eOUTPUT_GPIO))
        {
            eStatus = eTRUE_LED;
        }else {}
        break;
    default:
        break;
    }//End of switch

    return eStatus;
}

void vfTurnOn_LED (eCOLORS_LED_t eColor)
{
    switch(eColor)
    {
    case eRED_LED:
        vfClearPin_GPIO(ePortRed_LED ,ePinRed_LED);
        break;
    case eGREEN_LED:
        vfClearPin_GPIO(ePortGreen_LED ,ePinGreen_LED);
        break;
    case eBLUE_LED:
        vfClearPin_GPIO(ePortBlue_LED ,ePinBlue_LED);
        break;
    default:
        break;
    }//End of switch
}

void vfTurnOff_LED(eCOLORS_LED_t eColor)
{
    switch(eColor)
    {
    case eRED_LED:
        vfSetPin_GPIO(ePortRed_LED ,ePinRed_LED);
        break;
    case eGREEN_LED:
        vfSetPin_GPIO(ePortGreen_LED ,ePinGreen_LED);
        break;
    case eBLUE_LED:
        vfSetPin_GPIO(ePortBlue_LED ,ePinBlue_LED);
        break;
    default:
        break;
    }//End of switch
}

void vfToggle_LED (eCOLORS_LED_t eColor)
{
    switch(eColor)
    {
    case eRED_LED:
        vfTogglePin_GPIO(ePortRed_LED ,ePinRed_LED);
        break;
    case eGREEN_LED:
        vfTogglePin_GPIO(ePortGreen_LED ,ePinGreen_LED);
        break;
    case eBLUE_LED:
        vfTogglePin_GPIO(ePortBlue_LED ,ePinBlue_LED);
        break;
    default:
        break;
    }//End of switch
}

eSTATUS_LED_t efRead_LED   (eCOLORS_LED_t eColor)
{
    eSTATUS_LED_t eStatus = eFALSE_LED;

    switch(eColor)
    {
    case eRED_LED:
        if( (eStatus_GPIO_t)eTRUE_LED == efReadPin_GPIO(ePortRed_LED ,ePinRed_LED))
        {
            eStatus = eTRUE_LED;
        }else {}
        break;
    case eGREEN_LED:
        if( (eStatus_GPIO_t)eTRUE_LED == efReadPin_GPIO(ePortGreen_LED ,ePinGreen_LED))
        {
            eStatus = eTRUE_LED;
        }else {}
        break;
    case eBLUE_LED:
        if( (eStatus_GPIO_t)eTRUE_LED == efReadPin_GPIO(ePortBlue_LED ,ePinBlue_LED))
        {
            eStatus = eTRUE_LED;
        }else {}
        break;
    default: eStatus = eFALSE_LED;
        break;
    }//End of switch

    return eStatus;
}
