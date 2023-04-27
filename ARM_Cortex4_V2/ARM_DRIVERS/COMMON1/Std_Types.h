/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Std_Types.h
 *    Component:  -
 *       Module:  -
 *
 *  Description:  Provision of Standard Types
 *
 *********************************************************************************************************************/



#ifndef STD_TYPES_H
#define STD_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

# include "Platform_Types.h"
# include "Compiler.h"
#include "CommonMacros.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define STD_HIGH        0x01U       /* Standard HIGH  Physical state 5V or 3.3V*/
#define STD_LOW         0x00U       /* Standard LOW   Physical state 0V  */

#define STD_ACTIVE      0x01U       /* Logical state active */
#define STD_IDLE        0x00U       /* Logical state idle */

#define STD_ON          0x01U       /* Standard ON */
#define STD_OFF         0x00U       /* Standard OFF */




/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*
 *  Describes the standard Return Type Definitions used in the project
 */
typedef uint8  Std_ReturnType;
#define E_OK            ((Std_ReturnType)0x00U)      /* Function Return OK */
#define E_NOT_OK        ((Std_ReturnType)0x01U)      /* Function Return NOT OK */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* STD_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
