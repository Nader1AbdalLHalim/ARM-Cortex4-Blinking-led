/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SysTick_Lcfg.c
 *        \brief
 *
 *      \details  Source file for SysTick Module's user configurations at linking stage
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "SysTick.h"
#include "SysTick_Cfg.h"
/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/*Call back function to be executed in ISR for Timer0 .*/
void SysTick_Notification(void)
{

}
/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

SysTick_ConfigType SysTick_Config = 
{
	16, 
	0x00FFFFFF,
	SysTick_Notification,
	0,
	PRECISION_INERNAL_OSCILLATOR, 
};

/**********************************************************************************************************************
 *  END OF FILE: SysTick_Lcfg.c
 *********************************************************************************************************************/
