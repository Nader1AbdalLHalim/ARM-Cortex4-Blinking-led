/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  System.c
 *        \brief
 *
 *      \details Source File for System Service .
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "System.h"
/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/


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

void System_Start(void)
{
    /* Intialize Port Driver*/
	Port_Init(&Port_Configurations);

     /* Intialize NVIC Driver */
    Intrupt_Init();

    /* Intialize SysTick Driver*/
    SysTick_Init(&SysTick_Config);

     SysTick_Config.Notification = &Blinking_Change_Status;

     SysTick_SetNotification();

    /* Enable SysTick Intrrupt*/
    SysTick_EnableNotification();
}




/**********************************************************************************************************************
 *  END OF FILE: System.c
 *********************************************************************************************************************/