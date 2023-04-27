/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  SysTick_Cfg.h
 *       Module:  -
 *
 *  Description:  User configurations for SysTick Module .    
 *  
 *********************************************************************************************************************/
#ifndef SYSTICK_CFG_H
#define SYSTICK_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "SysTick_Types.h"

void SysTick_Notification(void);

/* Extern PB structures to be used by SysTick  */
extern SysTick_ConfigType SysTick_Config;
 
#endif  /* SYSTICK_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: SysTick_Cfg.h
 *********************************************************************************************************************/
