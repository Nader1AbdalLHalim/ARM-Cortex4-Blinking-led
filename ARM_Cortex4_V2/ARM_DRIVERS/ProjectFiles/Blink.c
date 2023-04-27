/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Blink.c
 *        \brief
 *
 *      \details Source File for Blink Service .
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Blink.h"
/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

static uint8 Led_Status = LED_STATUS_OFF;

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


void Blinking_Start(Dio_PortType Port,Led_Type LedId, uint32 Time_On, uint32 Time_OFF)
{

	if (Led_Status != LED_STATUS_OFF)
	{
		
		Led_On(LedId,Port);
		SysTick_StartTimer(Time_On);
		Led_Status = LED_STATUS_ON;
	}

	while (Led_Status == LED_STATUS_ON)
		;

	if (Led_Status != LED_STATUS_ON)
	{
		Led_Off(LedId,Port);
		SysTick_StartTimer(Time_OFF);
		Led_Status = LED_STATUS_OFF;
	}

	while (Led_Status == LED_STATUS_OFF)
		;

	return;
}


void Blinking_Stop(uint8 Port,Led_Type LedId)
{
	/* Stop Blinking*/
	Led_Off(LedId,Port);
	return;
}


void Blinking_Change_Status(void)
{
	if (Led_Status == LED_STATUS_ON)
	{
		Led_Status=LED_STATUS_OFF;
	}
	else
	{
		Led_Status=LED_STATUS_ON;
	}
}
/**********************************************************************************************************************
 *  END OF FILE: Blink.c
 *********************************************************************************************************************/
