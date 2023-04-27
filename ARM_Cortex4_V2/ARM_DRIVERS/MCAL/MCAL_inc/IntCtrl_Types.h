/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  Type Definition for Nvic Module     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define EXC_DISABLED  0
#define	EXC_ENABLED   1
#define INT_DISABLED  0
#define	INT_ENABLED   1
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/* Type definition for IntCtrl_PriorityLevel used by the NVIC APIs */
typedef uint8 IntCtrl_PriorityLevel;

/* Type definition for IntCtrl_ExceptionType used by the NVIC APIs
look at Table 2-8. Exception Types page 103 */
typedef enum IntCtrl_ExceptionType
{
	RESET                = 0,
	NMI                  = 1,
	HARD_FAULT           = 2,
	MEMORY_MANAGE_FAULT  = 3,
	BUS_FAULT            = 4,
	USAGE_FAULT          = 5,
	SVCALL               = 6,
	DEBUG_MONITOR        = 7,
	PENDSV               = 8,
	SYSTICK              = 9
} IntCtrl_ExceptionType;

/* Type definition for IntCtrl_InterruptType used by the NVIC APIs 
Table 2-9. Interrupts page 104*/
typedef enum IntCtrl_InterruptType
{
	/*** Bit Ports ***/
	GPIO_Port_A=0,
	GPIO_Port_B=1, 
	GPIO_Port_C=2,
	GPIO_Port_D=3,
	GPIO_Port_E=4,
	GPIO_Port_F=30,
	/*** Bit UART ***/
     UART0=5,
	 UART1=6,
	 UART2=33,
	 UART3=59, 
	 UART4=60, 
	 UART5=61, 
	 UART6=62, 
	 UART7=63,

	/*** Bit SSI ***/
    SSI0=7 ,
	SSI1=34,
	SSI2=57,
    SSI3=58,
    /*** Bit I2C ***/
    I2C0=8,
	I2C1=37,
	I2C2=68,
	I2C3=69,
	/*** Bit PWM ***/
	PWM0_FAULT=9,
	PWM1_FAULT=154,
	PWM0_Generator_0=10,
	PWM0_Generator_1=11,
	PWM0_Generator_2=12,
	PWM0_Generator_3=45,
	PWM1_Generator_0=134,
	PWM1_Generator_1=135,
	PWM1_Generator_2=136,
	PWM1_Generator_3=137,
	
	/*** Bit QEI ***/
    QEI0=13,
	QEI1=38,
	
	/*** Bit ADC SEQUENCE ***/
	ADC0_Sequence_0=14,
	ADC0_Sequence_1=15,
	ADC0_Sequence_2=16,
	ADC0_Sequence_3=17,
	ADC1_Sequence_0=48,
	ADC1_Sequence_1=49,
	ADC1_Sequence_2=50,
	ADC1_Sequence_3=51,
    
	/*** Bit ADC SEQUENCE ***/
    

	/*** 16/32-Bit Timers ***/
	TIMER_16_32_BIT_0A = 19,
	TIMER_16_32_BIT_0B = 20,
	TIMER_16_32_BIT_1A = 21,
	TIMER_16_32_BIT_1B = 22,
	TIMER_16_32_BIT_2A = 23,
	TIMER_16_32_BIT_2B = 24,
	TIMER_16_32_BIT_3A = 35,
	TIMER_16_32_BIT_3B = 36,
	TIMER_16_32_BIT_4A = 70,
	TIMER_16_32_BIT_4B = 71,
	TIMER_16_32_BIT_5A = 92,
	TIMER_16_32_BIT_5B = 93,
	
	/*** 32/64-Bit Timers ***/
	TIMER_32_64_BIT_0A = 94,
	TIMER_32_64_BIT_0B = 95,
	TIMER_32_64_BIT_1A = 96,
	TIMER_32_64_BIT_1B = 97,
	TIMER_32_64_BIT_2A = 98,
	TIMER_32_64_BIT_2B = 99,
	TIMER_32_64_BIT_3A = 100,
	TIMER_32_64_BIT_3B = 101,
	TIMER_32_64_BIT_4A = 102,
	TIMER_32_64_BIT_4B = 103,
	TIMER_32_64_BIT_5A = 104,
	TIMER_32_64_BIT_5B = 105
} IntCtrl_InterruptType;

/* Type definition for IntCtrl_ExceptionConfigType used by the NVIC APIs */
typedef struct IntCtrl_ExceptionConfigType
{
	uint8 ExceptionId;
	uint8 Level;
	sint8 Priority;

} IntCtrl_ExceptionConfigType;




/* Type definition for IntCtrl_InterruptConfigType used by the NVIC APIs */
typedef struct IntCtrl_InterruptConfigType
{
	uint8 interruptId;
	uint8 Level;
	uint8 Priority;

} IntCtrl_InterruptConfigType;


 
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
