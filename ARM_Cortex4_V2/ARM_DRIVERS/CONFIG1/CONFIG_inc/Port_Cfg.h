/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Cfg.h
 *       Module:  -
 *
 *  Description:  Port Module's user configurations      
 *  
 *********************************************************************************************************************/
#ifndef PORT_CFG_H
#define PORT_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Port_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*  Number of confuigered Pin*/
#define PORT_CONFIGURED_CHANNLES           (1)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* Data Structure required for initializing the Port Driver */
typedef struct Port_ConfigType
{
    uint8 PinNumber;
    uint8 PortNumber;
    uint8 PortPinMode; 
	uint8 PortPinLevelValue; 
	uint8 PortPinDirection;
    uint8 PortPinInternalAttach;
    uint8 PortPinOutputCurrent; 
}Port_ConfigType;


/* Extern PB structures to be used by Port  */
extern const Port_ConfigType Port_Configurations;
 
#endif  /* PORT_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Cfg.h
 *********************************************************************************************************************/
