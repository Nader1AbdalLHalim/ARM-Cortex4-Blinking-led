/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port_Lcfg.c
 *        \brief
 *
 *      \details  Source file for Port Module's user configurations at linking stage
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port_Cfg.h"
/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/* Description: Structure to describe each individual PIN contains:
 *	1. the Pin  Number  Which the pin belongs to. 0, 1, 2 or 3 .....7 .
 *  2. the Port Number PORT_A , PORT_B or PORT_C ....PORT_F .
 *  3. the Port pin Mode UART, Analog or Digital .....
 *	4. the Port pin Level Value High or Low .
 *  5. the Port Pin direction of pin --> INPUT or OUTPUT
 *  6. the Port Pin Internal atatch which can be pullup, pull down or open drain .
 *  7. the Port Pin ourput current
 */

/* PB structure used with Port_Init API */
const Port_ConfigType Port_Configurations =
	{	
	PIN0,
	PORT_A, 
	PINMODE_DIGITAL, 
	PIN_LEVEL_HIGH, 
	PIN_OUTPUT,
	PullUp, 
	PINOUTPUTCURRENT_2_MA
    };

/**********************************************************************************************************************
 *  END OF FILE: Port_Lcfg.c
 *********************************************************************************************************************/
