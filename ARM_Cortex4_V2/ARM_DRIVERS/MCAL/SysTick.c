/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SysTick.c
 *        \brief
 *
 *      \details Source File for SysTick Module's driver .
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "SysTick.h"
/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
/* Global pointer to function used to point upper layer functions
 * to be used in Call Back */
static  void (*g_SysTick_Call_Back_Ptr)(void) = NULL_PTR;

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

void SysTick_Init(const SysTick_ConfigType *ConfigPtr)
{

    /* Disable all the interrupts before initializations the timer module */
    INTERRUPTS_DISABLE();

    if (ConfigPtr->ClockSource == PRECISION_INERNAL_OSCILLATOR)
    {
        /* Precision internal oscillator (PIOSC) divided by 4 */
        STCTRL.B.CLK_SRC = 0;
    }
    else
    {
        /* System clock */
        STCTRL.B.CLK_SRC = 1;
    }

    /* Enable all the interrupts after initializations of SysTick Module  */
    INTERRUPTS_ENABLE();
}
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
void SysTick_EnableNotification(void)
{
    /* Enable SysTick Interrupt */
    STCTRL.B.INTEN = ENABLE;
}
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

void SysTick_DisableNotification(void)
{

    /* Disable SysTick Interrupt */
    STCTRL.B.INTEN = DISABLE;
}
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

SysTick_ValueType SysTick_GetTimeRemaining(void)
{

    return STCURRENT.B.CURRENT;
}

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

void SysTick_StartTimer(SysTick_ValueType Value)
{

   /* Load the value on SysTick  */
    STRELOAD.B.RELOAD = Value;

    /* Start the SysTick */
    STCTRL.B.ENABLES = ENABLE;
}

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

void SysTick_StopTimer(void)
{

    /* Stop the SysTick */
    STCTRL.B.ENABLES = DISABLE;
}

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

void SysTick_SetNotification(void)
{

    /* Check of the user filled the configuration Successfully*/
    if (NULL_PTR == SysTick_Config.Notification)
    {
        /* Configurations Error */
        return;
    }

    else
    {
        /* Configurations Successfully */
        /* No Action Required */
    }

    g_SysTick_Call_Back_Ptr = SysTick_Config.Notification;
}

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

void SysTick_Handler(void)
{
    /* Check if the SysTick_setCallBack is already called */
    if ( g_SysTick_Call_Back_Ptr != NULL_PTR )
    {
        /* call the functionusing call-back concept */
        (*g_SysTick_Call_Back_Ptr)();
    }

    else
    {
        /* Configurations Successfully */
        /* No Action Required */
    }
}
/**********************************************************************************************************************
 *  END OF FILE: SysTick.c
 *********************************************************************************************************************/
