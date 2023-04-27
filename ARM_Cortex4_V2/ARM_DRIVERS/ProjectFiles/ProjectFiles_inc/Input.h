
#ifndef Input_H_
#define Input_H_

/**********************************************************************************************************************
* INCLUDES
*********************************************************************************************************************/
 #include "Button.h"
 #include "ProjectFiles_Types.h"
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS PROTOTYPES
 *********************************************************************************************************************/

uint8 GetNumOfPresses( uint8 Port,Project_DeviceChannel MasterDeviceChannel
 ,Project_DeviceChannel MasterStatusChannel
 ,Project_DeviceChannel SlaveDeviceChannel , Project_DeviceChannel SlaveStatusChannel
 ,Project_DeviceChannel ButtonAttach );
#endif /* Input_H_ */
/**********************************************************************************************************************
*  END OF FILE: Input.h
*********************************************************************************************************************/