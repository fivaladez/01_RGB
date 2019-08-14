/*
** Project: Calculator for KL25Z
** File   : BUTTON_driver.c
** Author : Ivan Valadez
** Date   : 2 - October - 2018
**
** Overview: C file containing
**
** $Log$
*/

#include "BUTTON.h"

#define BUTTON_TIME_1S           (1800000u)
#define BUTTON_TIME_500MS        (900000u)
#define BUTTON_TIME_250MS        (450000u)
#define BUTTON_TIME_100MS        (180000u)

/*Original 2500*/
#define DEBOUNCING (20u)/*You must adjust the value according to the performance of the main code*/

void vfdelay_BUTTON(uint32_t u32Time)
{
    while(u32Time--);
}

eSTATUS_BUTTON_t efCreate_BUTTON  (sBUTTON_t *psButton, ePORTx_BUTTON_t ePort,ePINx_BUTTON_t ePin)
{
    eSTATUS_BUTTON_t eStatus = eFALSE_BUTTON;

    switch(ePort){
    case ePORTA_GPIO:
        /*Verify ePin is a valid direction to the corresponding port of board KL25Z*/
        if(ePin == ePIN_1_GPIO  || ePin == ePIN_2_GPIO || ePin == ePIN_4_GPIO || ePin == ePIN_5_GPIO ||
           ePin == ePIN_12_GPIO || ePin == ePIN_13_GPIO)
        {
            /*Calling Initialization of the pin*/
            if((eSTATUS_GPIO_t)eTRUE_BUTTON == efInit_GPIO( ePort, ePin, eINPUT_GPIO ) )
            {
                psButton -> ePort       = ePort;
                psButton -> ePin        = ePin;
                psButton -> u16Debounce = DEBOUNCING;   /*Initial value for ReadBUTTONNonBlocking*/
                psButton -> eState      = eNOT_PRESSED_BUTTTON; /*Initial state for ReadBUTTONNonBlocking*/

                eStatus = eTRUE_BUTTON;
            }else {}
        }else {}
        break;
    case ePORTB_GPIO:
        if(ePin == ePIN_0_GPIO || ePin == ePIN_1_GPIO || ePin == ePIN_2_GPIO || ePin == ePIN_3_GPIO ||
           ePin == ePIN_8_GPIO || ePin == ePIN_9_GPIO)
        {
            if((eSTATUS_GPIO_t)eTRUE_BUTTON == efInit_GPIO( ePort, ePin, eINPUT_GPIO ) )
            {
                psButton -> ePort       = ePort;
                psButton -> ePin        = ePin;
                psButton -> u16Debounce = DEBOUNCING;
                psButton -> eState      = eNOT_PRESSED_BUTTTON;

                eStatus = eTRUE_BUTTON;
            }else {}
        }else {}
        break;
    case ePORTC_GPIO:
        if(ePin == ePIN_0_GPIO  || ePin == ePIN_1_GPIO  || ePin == ePIN_2_GPIO  || ePin == ePIN_3_GPIO ||
           ePin == ePIN_4_GPIO  || ePin == ePIN_5_GPIO  || ePin == ePIN_6_GPIO  || ePin == ePIN_7_GPIO ||
           ePin == ePIN_8_GPIO  || ePin == ePIN_9_GPIO  || ePin == ePIN_10_GPIO || ePin == ePIN_11_GPIO||
           ePin == ePIN_12_GPIO || ePin == ePIN_13_GPIO || ePin == ePIN_16_GPIO || ePin == ePIN_17_GPIO)
        {
            if((eSTATUS_GPIO_t)eTRUE_BUTTON == efInit_GPIO( ePort, ePin, eINPUT_GPIO ) )
            {
                psButton -> ePort       = ePort;
                psButton -> ePin        = ePin;
                psButton -> u16Debounce = DEBOUNCING;
                psButton -> eState      = eNOT_PRESSED_BUTTTON;

                eStatus = eTRUE_BUTTON;
            }else {}
        }else {}
        break;
    case ePORTD_GPIO:
        if(ePin == ePIN_0_GPIO || ePin == ePIN_1_GPIO || ePin == ePIN_2_GPIO || ePin == ePIN_3_GPIO ||
           ePin == ePIN_4_GPIO || ePin == ePIN_5_GPIO || ePin == ePIN_6_GPIO || ePin == ePIN_7_GPIO)
        {
            if((eSTATUS_GPIO_t)eTRUE_BUTTON == efInit_GPIO( ePort, ePin, eINPUT_GPIO ) )
            {
                psButton -> ePort       = ePort;
                psButton -> ePin        = ePin;
                psButton -> u16Debounce = DEBOUNCING;
                psButton -> eState      = eNOT_PRESSED_BUTTTON;

                eStatus = eTRUE_BUTTON;
            }else {}
        }else {}
        break;
    case ePORTE_GPIO:
        if(ePin == ePIN_0_GPIO  || ePin == ePIN_1_GPIO  || ePin == ePIN_2_GPIO  || ePin == ePIN_3_GPIO  ||
           ePin == ePIN_4_GPIO  || ePin == ePIN_5_GPIO  || ePin == ePIN_20_GPIO || ePin == ePIN_21_GPIO ||
           ePin == ePIN_22_GPIO || ePin == ePIN_23_GPIO || ePin == ePIN_29_GPIO || ePin == ePIN_30_GPIO)
        {
            if((eSTATUS_GPIO_t)eTRUE_BUTTON == efInit_GPIO( ePort, ePin, eINPUT_GPIO ) )
            {
                psButton -> ePort       = ePort;
                psButton -> ePin        = ePin;
                psButton -> u16Debounce = DEBOUNCING;
                psButton -> eState      = eNOT_PRESSED_BUTTTON;

                eStatus = eTRUE_BUTTON;
            }else {}
        }else {}
        break;
    default:     eStatus = eFALSE_BUTTON;
    break;
    }

    return eStatus;
}

eSTATUS_BUTTON_t efRead_BUTTON    (sBUTTON_t *psButton)
{
    eSTATUS_BUTTON_t eStatus = eFALSE_BUTTON;

    if( (eSTATUS_GPIO_t)eTRUE_BUTTON  == efReadPin_GPIO(psButton->ePort,psButton->ePin))
    {
        vfdelay_BUTTON(BUTTON_TIME_100MS);
        if((eSTATUS_GPIO_t)eTRUE_BUTTON == efReadPin_GPIO(psButton->ePort,psButton->ePin))
        {
            eStatus = eTRUE_BUTTON;
        }else {}
    }else {}

    return eStatus;
}

eSTATUS_BUTTON_t efReadNonBlocking_BUTTON(sBUTTON_t *psButton)
{
    eSTATUS_BUTTON_t eStatus = eFALSE_BUTTON;

    if( (eSTATUS_GPIO_t)eTRUE_BUTTON == efReadPin_GPIO( psButton->ePort, psButton->ePin ) )
    {    /* The variable eState determine if the button already was mark as TRUE
          * and it makes that the count and the process do not have to start again
          * */
        if( ePRESSED_BUTTON != psButton->eState )
        {
            if( 0 < (psButton -> u16Debounce) )
            {
                (psButton -> u16Debounce)--;
                psButton->eState = eNOT_PRESSED_BUTTTON;
            }else
            {
                (psButton -> u16Debounce) = DEBOUNCING;
                eStatus = eTRUE_BUTTON;
                psButton -> eState = ePRESSED_BUTTON;/*To end this state*/
            }
        }else
        {
            /*Keep in this state of COMPLETE and return a TRUE*/
            eStatus = eTRUE_BUTTON;
        }

    }else
    {
        (psButton -> u16Debounce) = DEBOUNCING;
        psButton->eState = eNOT_PRESSED_BUTTTON;
    }

    return eStatus;
}
