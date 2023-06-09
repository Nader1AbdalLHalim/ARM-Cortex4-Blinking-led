
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "APP1.h"
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


int main(void)
{
uint32 TimeOn, TimeOff;	
	/* Intialize all modules according to user configurations */
	System_Start();
 uint32 TArgetAddress= GPIO_A_AHB+GPIODIR_OFFSET;
//SET_BIT(GET_REGISTER((volatile uint8 *)TArgetAddress, uint32, GPIODIR_OFFSET),0);
WRITE_BIT(TArgetAddress, 0,HIGH)

	/* Get Blinking Time On from User*/
	TimeOn = Time_GetOn();
  TimeOn =Time_GetTimerTicks(TimeOn); 
	
	/* Get Blinking Time Off from user */
  TimeOff = Time_GetOff();
	TimeOff =Time_GetTimerTicks(TimeOff);

	while (1)
	{
		Blinking_Start(PORT_A,LED, TimeOn, TimeOff);
	}
}

/**********************************************************************************************************************
 *  END OF FILE: App.c
 *********************************************************************************************************************/
