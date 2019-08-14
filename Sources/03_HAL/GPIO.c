/*
** Project: For KL25Z
** File   : GPIO.c
** Author : Ivan Valadez
** Date   : 14 - Agosto - 2019
**
** Overview: C file containing the functions for using GPIO pins from MCU KL25K of nxp
**
** $Log$
*/
#include "GPIO.h"

eSTATUS_GPIO_t efInit_GPIO  ( ePORTx_GPIO_t ePort, ePINx_GPIO_t ePin, eINOUT_GPIO_t eInOut )
{
    eSTATUS_GPIO_t eStatus = eFALSE_GPIO;

    switch(ePort){
    case ePORTA_GPIO:
        if(ePin == ePIN_1_GPIO  || ePin == ePIN_2_GPIO || ePin == ePIN_4_GPIO || ePin == ePIN_5_GPIO
        || ePin == ePIN_12_GPIO || ePin == ePIN_13_GPIO)
        {
            SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;                     //1 Enable clock for this port
            PORTA_PCR(ePin) = PORT_PCR_MUX(PORT_PCR_MUX_GPIO);  //2 Mode 1 for working as GPIO_vfInit
            GPIOA_PDOR &= ~(1<<ePin);                             //3 Make sure of initial value of the pin (write a zero)
            if(eINPUT_GPIO == eInOut)
            {
                GPIOA_PDDR &= ~(1<<ePin);                         //4 Define this pin as input
                eStatus = eTRUE_GPIO;
            }else if(eOUTPUT_GPIO == eInOut)
            {
                GPIOA_PDDR |= (1<<ePin);                     //4 Define this pin as output
                eStatus = eTRUE_GPIO;
            }else {}
        }else {}
        break;
    case ePORTB_GPIO:
        if(ePin == ePIN_0_GPIO || ePin == ePIN_1_GPIO || ePin == ePIN_2_GPIO  || ePin == ePIN_3_GPIO
        || ePin == ePIN_8_GPIO || ePin == ePIN_9_GPIO || ePin == ePIN_18_GPIO || ePin == ePIN_19_GPIO)
        {
            SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
            PORTB_PCR(ePin) = PORT_PCR_MUX(PORT_PCR_MUX_GPIO);
            GPIOB_PDOR &= ~(1<<ePin);
            if(eINPUT_GPIO == eInOut)
            {
                GPIOB_PDDR &= ~(1<<ePin);
                eStatus = eTRUE_GPIO;
            }else if(eOUTPUT_GPIO == eInOut)
            {
                GPIOB_PDDR |= (1<<ePin);
                eStatus = eTRUE_GPIO;
            }else {}
        }else {}
        break;
    case ePORTC_GPIO:
        if(ePin == ePIN_0_GPIO  || ePin == ePIN_1_GPIO  || ePin == ePIN_2_GPIO  || ePin == ePIN_3_GPIO
        || ePin == ePIN_4_GPIO  || ePin == ePIN_5_GPIO  || ePin == ePIN_6_GPIO  || ePin == ePIN_7_GPIO
        || ePin == ePIN_8_GPIO  || ePin == ePIN_9_GPIO  || ePin == ePIN_10_GPIO || ePin == ePIN_11_GPIO
        || ePin == ePIN_12_GPIO || ePin == ePIN_13_GPIO || ePin == ePIN_16_GPIO || ePin == ePIN_17_GPIO)
        {
            SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
            PORTC_PCR(ePin) = PORT_PCR_MUX(PORT_PCR_MUX_GPIO);
            GPIOC_PDOR &= ~(1<<ePin);
            if(eINPUT_GPIO == eInOut)
            {
                GPIOC_PDDR &= ~(1<<ePin);
                eStatus = eTRUE_GPIO;
            }else if(eOUTPUT_GPIO == eInOut)
            {
                GPIOC_PDDR |= (1<<ePin);
                eStatus = eTRUE_GPIO;
            }else {}
        }else {}
        break;
    case ePORTD_GPIO:
        if(ePin == ePIN_0_GPIO || ePin == ePIN_1_GPIO || ePin == ePIN_2_GPIO || ePin == ePIN_3_GPIO
        || ePin == ePIN_4_GPIO || ePin == ePIN_5_GPIO || ePin == ePIN_6_GPIO || ePin == ePIN_7_GPIO
        || ePin == ePIN_13_GPIO)
        {
            SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
            PORTD_PCR(ePin) = PORT_PCR_MUX(PORT_PCR_MUX_GPIO);
            GPIOD_PDOR &= ~(1<<ePin);
            if(eINPUT_GPIO == eInOut)
            {
                GPIOD_PDDR &= ~(1<<ePin);
                eStatus = eTRUE_GPIO;
            }else if(eOUTPUT_GPIO == eInOut)
            {
                GPIOD_PDDR |= (1<<ePin);
                eStatus = eTRUE_GPIO;
            }else {}
        }else {}
        break;
    case ePORTE_GPIO:
        if(ePin == ePIN_0_GPIO  || ePin == ePIN_1_GPIO  || ePin == ePIN_2_GPIO  || ePin == ePIN_3_GPIO
        || ePin == ePIN_4_GPIO  || ePin == ePIN_5_GPIO  || ePin == ePIN_20_GPIO || ePin == ePIN_21_GPIO
        || ePin == ePIN_22_GPIO || ePin == ePIN_23_GPIO || ePin == ePIN_29_GPIO || ePin == ePIN_30_GPIO)
        {
            SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
            PORTE_PCR(ePin) = PORT_PCR_MUX(PORT_PCR_MUX_GPIO);
            GPIOE_PDOR &= ~(1<<ePin);
            if(eINPUT_GPIO == eInOut)
            {
                GPIOE_PDDR &= ~(1<<ePin);
                eStatus = eTRUE_GPIO;
            }else if(eOUTPUT_GPIO == eInOut)
            {
                GPIOE_PDDR |= (1<<ePin);
                eStatus = eTRUE_GPIO;
            }else {}
        }else {}
        break;
    default: eStatus = eFALSE_GPIO;
        break;
    }//End switch

    return eStatus;

}

void vfSetPin_GPIO   ( ePORTx_GPIO_t ePort, ePINx_GPIO_t ePin ) /*Write a 1*/
{
    switch(ePort){
    case ePORTA_GPIO: GPIOA_PDOR |= (1<<ePin);
        break;
    case ePORTB_GPIO: GPIOB_PDOR |= (1<<ePin);
        break;
    case ePORTC_GPIO: GPIOC_PDOR |= (1<<ePin);
        break;
    case ePORTD_GPIO: GPIOD_PDOR |= (1<<ePin);
        break;
    case ePORTE_GPIO: GPIOE_PDOR |= (1<<ePin);
        break;
    default:
        break;
    }//End switch
}

void vfClearPin_GPIO ( ePORTx_GPIO_t ePort, ePINx_GPIO_t ePin )/*Write a 0*/
{
    switch(ePort){
    case ePORTA_GPIO: GPIOA_PDOR &= ~(1<<ePin);
        break;
    case ePORTB_GPIO: GPIOB_PDOR &= ~(1<<ePin);
            break;
    case ePORTC_GPIO: GPIOC_PDOR &= ~(1<<ePin);
        break;
    case ePORTD_GPIO: GPIOD_PDOR &= ~(1<<ePin);
        break;
    case ePORTE_GPIO: GPIOE_PDOR &= ~(1<<ePin);
        break;
    default:
        break;
    }//End switch
}

void vfTogglePin_GPIO( ePORTx_GPIO_t ePort, ePINx_GPIO_t ePin )
{
    switch(ePort){
    case ePORTA_GPIO: GPIOA_PDOR ^= (1<<ePin);
        break;
    case ePORTB_GPIO: GPIOB_PDOR ^= (1<<ePin);
        break;
    case ePORTC_GPIO: GPIOC_PDOR ^= (1<<ePin);
        break;
    case ePORTD_GPIO: GPIOD_PDOR ^= (1<<ePin);
        break;
    case ePORTE_GPIO: GPIOE_PDOR ^= (1<<ePin);
        break;
    default:
        break;
    }//End switch
}

eSTATUS_GPIO_t efReadPin_GPIO( ePORTx_GPIO_t ePort, ePINx_GPIO_t ePin )
{
    eSTATUS_GPIO_t eStatus = eFALSE_GPIO;

    switch(ePort){/*    Possible results: 1 or 0    */
    case ePORTA_GPIO: eStatus = ((GPIOA_PDIR &= (1 << ePin)) >> ePin);
        break;
    case ePORTB_GPIO: eStatus = ((GPIOB_PDIR &= (1 << ePin)) >> ePin);
        break;
    case ePORTC_GPIO: eStatus = ((GPIOC_PDIR &= (1 << ePin)) >> ePin);
        break;
    case ePORTD_GPIO: eStatus = ((GPIOD_PDIR &= (1 << ePin)) >> ePin);
        break;
    case ePORTE_GPIO: eStatus = ((GPIOE_PDIR &= (1 << ePin)) >> ePin);
        break;
    default:     eStatus = eFALSE_GPIO;
        break;
    }

    if(0 == eStatus)
    {
        eStatus = eTRUE_GPIO;
    }else if(1 == eStatus)
    {
        eStatus = eFALSE_GPIO;
    }

    return eStatus;
}

void vfWritePin_GPIO( ePORTx_GPIO_t ePort, ePINx_GPIO_t ePin, eLOGIC_VAL_GPIO_t eValue )
{
    switch(ePort){
    case ePORTA_GPIO:
        if( eLOW_GPIO == eValue )
        {
            GPIOA_PDOR &= ~(1<<ePin);
        }else if( eHIGH_GPIO == eValue )
        {
            GPIOA_PDOR |= (1<<ePin);
        }
        break;
    case ePORTB_GPIO:
        if( eLOW_GPIO == eValue )
        {
            GPIOB_PDOR &= ~(1<<ePin);
        }else if( eHIGH_GPIO == eValue )
        {
            GPIOB_PDOR |= (1<<ePin);
        }
        break;
    case ePORTC_GPIO:
        if( eLOW_GPIO == eValue )
        {
            GPIOC_PDOR &= ~(1<<ePin);
        }else if( eHIGH_GPIO == eValue )
        {
            GPIOC_PDOR |= (1<<ePin);
        }
        break;
    case ePORTD_GPIO:
        if( eLOW_GPIO == eValue )
        {
            GPIOD_PDOR &= ~(1<<ePin);
        }else if( eHIGH_GPIO == eValue )
        {
            GPIOD_PDOR |= (1<<ePin);
        }
        break;
    case ePORTE_GPIO:
        if( eLOW_GPIO == eValue )
        {
            GPIOE_PDOR &= ~(1<<ePin);
        }else if( eHIGH_GPIO == eValue )
        {
            GPIOE_PDOR |= (1<<ePin);
        }
        break;
    default: /*Do nothing*/
        break;
    }//End switch
}

void vfWritePort_GPIO( ePORTx_GPIO_t ePort, DATA_GPIO_t Data )
{
    switch(ePort){
    case ePORTA_GPIO: GPIOA_PDOR = Data;
        break;
    case ePORTB_GPIO: GPIOB_PDOR = Data;
        break;
    case ePORTC_GPIO: GPIOC_PDOR = Data;
        break;
    case ePORTD_GPIO: GPIOD_PDOR = Data;
        break;
    case ePORTE_GPIO: GPIOE_PDOR = Data;
        break;
    default:
        break;
    }
}
