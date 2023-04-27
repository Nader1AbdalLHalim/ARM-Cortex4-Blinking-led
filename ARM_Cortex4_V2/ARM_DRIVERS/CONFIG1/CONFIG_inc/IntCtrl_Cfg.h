/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Cfg.h
 *       Module:  -
 *
 *  Description:  NVIC Module's configurations    
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_CFG_H
#define INTCTRL_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
 /* Number Of Confguired Exception */
#define CONFIGURED_EXCEPTIONS_NUM							(10)
/* Number Of Confguired Interrupts */
#define CONFIGURED_INTERRUPTS_NUM							(24)
/*$$$$$$$$$$$$$$$$$ FOR APINT API $$$$$$$$$$$$$$$$$
here we can determine Interrupt Priority Levels look at page 164
and according to our option the function Set_Grouping_Priority
will access APINT Register
*/

/*
 *Interrupt Control Priority Grouping
 *Options:
 *1- PRIORITY_GROUP_XXX :		xxx 0->7 Group , 0 subgroup 
 *2- PRIORITY_GROUP_XXY :		xxy 0->4 Group , 0->1 subgroup
 *3- PRIORITY_GROUP_XYY :		xyy 0->1 Group , 0->4 subgroup
 *4- PRIORITY_GROUP_YYY  :		yyy 0 Group , 0->7 subgroup
*/  
#define PRIORITY_GROUP_YYY

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* Data Structure required for initializing the NVIC Driver */
typedef struct
{
	IntCtrl_ExceptionConfigType Exceptions[CONFIGURED_EXCEPTIONS_NUM];
	IntCtrl_InterruptConfigType Interrupts[CONFIGURED_INTERRUPTS_NUM];
} IntCtrl_ConfigType;


/* Extern PB structures to be used by NVIC  */
extern const IntCtrl_ConfigType IntCtrl_Config;
#endif  /* INTCTRL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/
