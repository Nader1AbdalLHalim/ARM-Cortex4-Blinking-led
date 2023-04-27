/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Input.c
 *  Module:  	  Input
 *  Description:  Source file for Input Service
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Ahmed Alaa
 *	Date:		  27/07/2022
 *********************************************************************************************************************/

/**********************************************************************************************************************
*  INCLUDES
*********************************************************************************************************************/
#include "Input.h"
#include "Led.h"
#include "CommonMacros.h"

/**********************************************************************************************************************
 *  STATIC GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/*
function arguements
# MasterDeviceChannel:The device which will start listening to the input pulses
#MasterStatusChannel:The device will make a slight response for the master to give the app some interactivity
# SlaveDeviceChannel:The device which will trigger the input pulses
#SlaveStatusChannel:The device will make a slight response for the slave to give the app some interactivity
# ButtonAttach:Identification for the connection type (PULL_UP or PULL_DOWN)
*/
uint8 GetNumOfPresses( uint8 Port,Project_DeviceChannel MasterDeviceChannel
 ,Project_DeviceChannel MasterStatusChannel
 ,Project_DeviceChannel SlaveDeviceChannel , Project_DeviceChannel SlaveStatusChannel
 ,Project_DeviceChannel ButtonAttach )
{
uint8 pulses = 0;
int i;	
	/* Don't advance until the user give an acka that he will enter an input */
	while (Button_Read(Port,MasterDeviceChannel, ButtonAttach) == BUTTON_RELEASED);
	
	/* Let the user now, we were listening to him */
	Led_On(MasterStatusChannel,Port);
	
	/* wait a little bit */
	
	for(i=0; i < 1000000; i++);
	
	/* Revert all changes */
	Led_Off(MasterStatusChannel,Port);
	
	for(;;)
	{
		if (Button_Read(Port,MasterDeviceChannel, ButtonAttach) == BUTTON_PRESSED)
		{
			/* Let the user now, we were listening to him */
			Led_On(MasterStatusChannel,Port);
			
			/* wait a little bit */
			for( i = 0; i < 1000000; i++)
			
			/* Revert all changes */
	        Led_Off(MasterStatusChannel,Port);
			
			break;
		}
		else if (Button_Read(Port,SlaveDeviceChannel, ButtonAttach) == BUTTON_PRESSED)
		{
			/* Let the user now, we are listening to him */
			Led_On(SlaveStatusChannel,Port);
			
			/* wait a little bit */
			for(i = 0; i < 1000000; i++);
			
			/* Revert all changes */
			Led_Off(SlaveStatusChannel,Port);
			
			/* Accumulate the number of pulses */
			pulses++;
		}
	}
	
	/* wait a little bit */
	for(i = 0; i < 1000000; i++);
	
	/* Pass the number of pulses */
	return pulses;
}
