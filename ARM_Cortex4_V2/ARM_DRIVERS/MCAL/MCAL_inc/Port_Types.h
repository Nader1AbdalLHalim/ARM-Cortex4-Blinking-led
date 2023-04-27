/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Types.h
 *       Module:  -
 *
 *  Description:  API Types Of Port Module      
 *  
 *********************************************************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* Type definition for Port_PinType used by the Port APIs */
typedef enum
{
PIN0,
PIN1,
PIN2,
PIN3,
PIN4,
PIN5,
PIN6,
PIN7
} PORT_PinType;


/* Type definition for Port_NumberType used by the Port APIs */
typedef enum 
{
	PORT_A, 
    PORT_B,
    PORT_C,
    PORT_D,
    PORT_E,
    PORT_F
} PORT_PORTNum;

/* Type definition for Port_PinDirectionType used by the Port APIs */
typedef enum 
{
    PIN_INPUT=0,
    PIN_OUTPUT
}Port_PinDirectionType;


/* Type definition for Port_PinModeType used by the Port APIs */
typedef enum 
{
    PINMODE_DIGITAL = 0,          /* This signal is controlled by Digital Module */
    PINMODE_ANALOG,               /* This signal is controlled by Analog Module */
    PINMODE_UART,                 /* This signal is controlled by UART Module */
    PINMODE_PWM,                  /* This signal is controlled by PWM Module */
    PINMODE_TIMER_CAPTURE,        /* This signal is controlled by Timer Capture Module*/ 
    PINMODE_TIMER_COMPARE,        /* This signal is controlled by Timer Compare Module */
    PINMODE_USB,                  /* This signal is controlled by USB Module */
    PINMODE_CAN,                  /* This signal is controlled by CAN Module */
    PINMODE_SSI,                  /* This signal is controlled by SSI Module*/
    PINMODE_I2C,                  /* This signal is controlled by I2C Module*/
    PINMODE_QEI,                  /* This signal is controlled by QEI Module*/
    PINMODE_NMI                  /* Non Muskable Interrupt*/
}Port_PinModeType;

/* Type definition for Port_PinInternalAttachType used by the Port APIs */
typedef enum InternalAttach
{
PullUp,
PullDown,
OpenDrain
}Port_InternalAttach;

/* Type definition for Port_PinOutputCurrentType used by the Port APIs */
typedef enum 
{
    PINOUTPUTCURRENT_2_MA = 0,
    PINOUTPUTCURRENT_4_MA,
    PINOUTPUTCURRENT_8_MA
}Port_PinOutputCurrentType;


/* Type definition for Port_PinLevelType used by the Port APIs */
typedef enum 
{
    PIN_LEVEL_LOW = 0,
    PIN_LEVEL_HIGH = 1
}Port_PinLevelType;




/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* PORT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Types.h
 *********************************************************************************************************************/
