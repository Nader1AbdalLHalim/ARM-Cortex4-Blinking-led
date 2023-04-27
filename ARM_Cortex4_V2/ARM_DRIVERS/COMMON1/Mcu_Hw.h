/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

 /* Structure to define Bit Fields of SysTick Control and Status Register*/
typedef struct
{
	uint32 ENABLES :1;
	uint32 INTEN   :1;
	uint32 CLK_SRC :1;
	uint32         :13;
	uint32 COUNT   :1;
	uint32 		   :15;
} STCTRL_BF;
typedef union
{
    uint32 R;
    STCTRL_BF B;
}STCTRL_Tag;
/*Structure to define Bit Fields of SysTick Reload Value Register (STRELOAD), offset 0x014*/
typedef struct
{
	uint32 RELOAD  :24;
	uint32 		   :8;
}STRELOAD_BF;

typedef union
{
	uint32 R;
	STRELOAD_BF B;
 }STRELOAD_Tag;
/*SysTick Current Value Register (STCURRENT), offset 0x018*/
typedef struct
{
	uint32 CURRENT		:24;
	uint32				:8;
}STCURRENT_BF;

typedef union
{
	uint32 R;
	STCURRENT_BF B;
}STCURRENT_Tag;







/* Structure to define Bit Fields of Software Trigger Interrupt  Register*/
typedef struct SWTRIG_BF
{
    uint32 INTID        :8;
    uint32              :24;

}SWTRIG_BF;

/* Structure to define Bit Fields of Interrupt Control and State Register*/
typedef struct INTCTRL_BF
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :8;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;

/* Structure to define Bit Fields of NVIC_PRIn Register*/
typedef struct
{
	uint32				:5;
	uint32 INTA			:3;
	uint32				:5;
	uint32 INTB			:3;
	uint32				:5;
	uint32 INTC			:3;
	uint32				:5;
	uint32 INTD			:3;
} NVIC_PRIx_BF;

/* Structure to define Bit Fields of System Handler Priority 1 Register*/
typedef struct SCB_SYSPRI1_BF
{
	uint32 				:5;
	sint8 MEM			:3;
	uint32				:5;
	sint8 BUS			:3;
	uint32				:5;
	sint8 USAGE		:3;
	uint32				:8;
} SCB_SYSPRI1_BF;	

/* Structure to define Bit Fields of System Handler Priority 2 Register*/
typedef struct SCB_SYSPRI2_BF
{
	uint32 				:29;
	sint8 SVC			:3;
} SCB_SYSPRI2_BF;	

/* Structure to define Bit Fields of System Handler Priority 3 Register*/
typedef struct SCB_SYSPRI3_BF
{
	uint32 				:5;
	sint8 DEBUG		:3;
	uint32				:13;
	sint8 PENDSV		:3;
	uint32				:5;
	sint32 TICK			:3;
} SCB_SYSPRI3_BF;	

/* Structure to define Bit Fields of System Handler Control and State Register*/
typedef struct SCB_SYSHNDCTRL_BF
{
	uint32 MEMA			:1;
	uint32 BUSA			:1;
	uint32 				:1;
	uint32 USGA			:1;
	uint32 				:3;
	uint32 SVCA			:1;
	uint32 MON			:1;
	uint32 				:1;
	uint32 PNDSV		:1;
	uint32 TICK			:1;
	uint32 USAGEP		:1;
	uint32 MEMP			:1;
	uint32 BUSP			:1;
	uint32 SVC			:1;
	uint32 MEM			:1;
	uint32 BUS			:1;
	uint32 USAGE		:1;
	uint32 				:13;
} SCB_SYSHNDCTRL_BF;











/* General-Purpose Input/Output Run Mode Clock Gating Control */
typedef struct RCGCGPIO_BF
{
	uint32 R0       :1;  /* GPIO Port A Run Mode Clock Gating Control */
    uint32 R1       :1;  /* GPIO Port B Run Mode Clock Gating Control */
    uint32 R2       :1;  /* GPIO Port C Run Mode Clock Gating Control */
    uint32 R3       :1;  /* GPIO Port D Run Mode Clock Gating Control */
    uint32 R4       :1;  /* GPIO Port E Run Mode Clock Gating Control */
    uint32 R5       :1;  /* GPIO Port F Run Mode Clock Gating Control */
    uint32          :27; /* ********************Reserved Bits******************** */

}RCGCGPIO_BF;

typedef union 
{
uint8 Z ;
RCGCGPIO_BF S;
}RCGCGPIO_Tag;


/* General-Purpose Input/Output Run Mode Clock Gating Control */
typedef struct GPIOHBCTL_BF
{
	uint32 PORTA       :1;  /* GPIO Port A Run Mode Clock Gating Control */
    uint32 PORTB       :1;  /* GPIO Port B Run Mode Clock Gating Control */
    uint32 PORTC       :1;  /* GPIO Port C Run Mode Clock Gating Control */
    uint32 PORTD       :1;  /* GPIO Port D Run Mode Clock Gating Control */
    uint32 PORTE       :1;  /* GPIO Port E Run Mode Clock Gating Control */
    uint32 PORTF       :1;  /* GPIO Port F Run Mode Clock Gating Control */
    uint32             :27; /* ********************Reserved Bits******************** */

}GPIOHBCTL_BF;

typedef union
{
 uint8 Q ;
 GPIOHBCTL_BF W;	
}GPIOHBCTL_Tag ;
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
 
 /* Define CPU Clock with 16 MHz*/
#define F_CPU																	(16000000U)


/* Base address of ARM Cortex M4 Core Peripherals SysTick, NVIC, MPU, FPU and SCB registers */
#define CORTEXM4_PERI_BASE_ADDRESS             (0xE000E000)


/*===========================================================*
 *                   System Timer (SysTick) REGISTERS        *
 *========================================================== */
 /* SysTick Control and Status Register */
#define STCTRL                           (*((volatile STCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x010)))
/* SysTick Reload Value Register */
#define STRELOAD                         (*((volatile STRELOAD_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x014)))
/* SysTick Current Value Register */
#define STCURRENT                        (*((volatile STCURRENT_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x018)))

/*///////////////////NVIC/////////////////////////////////////////////////*/

/*Software Trigger Interrupt Register*/

#define  NVIC_SWTRIG                           (*((volatile SWTRIG_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0xF00)))



/*===========================================================
             System Control Block (SCB) REGISTERS           
 ========================================================== */

/* Auxiliary Control Register */ 
#define SCB_ACTLR                           (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x008)))
/* CPU ID Base Register */ 
#define SCB_CPUID                           (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD00)))
/* Interrupt Control and State Register */
#define SCB_INTCTRL                         (*((volatile INTCTRL_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04)))
/*  Vector Table Offset Register */
#define SCB_VTABLE                          (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD08)))
/*  Application Interrupt and Reset Control Register */
#define SCB_APINT                           (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C)))
/* System Control Register */
#define SCB_SYSCTRL                         (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD10)))
/* Configuration and Control Register */
#define SCB_CFGCTRL                         (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD14)))

/* System Handler Priority 1 Register  look at page 170
The SYSPRI1 register configures the priority level, 0 to 7 of the usage fault, bus fault, and memory
management fault exception handlers. This register is byte-accessible */
#define SCB_SYSPRI1                         (*((volatile SCB_SYSPRI1_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0xD18)))

/* System Handler Priority 2 Register look at page 171
The SYSPRI2 register configures the priority level, 0 to 7 of the SVCall handler. This register is
byte-accessible. */
#define SCB_SYSPRI2                         (*((volatile SCB_SYSPRI2_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0xD1C)))

/* System Handler Priority 3 Register look at page 172 
The SYSPRI3 register configures the priority level, 0 to 7 of the SysTick exception and PendSV
handlers. This register is byte-accessible */
#define SCB_SYSPRI3                         (*((volatile SCB_SYSPRI3_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0xD20)))

/*  System Handler Control and State Register Look at page 173
The SYSHNDCTRL register enables the system handlers, and indicates the pending status of the
usage fault, bus fault, memory management fault, and SVC exceptions as well as the active status
of the system handlers.*/
#define SCB_SYSHNDCTRL                      (*((volatile SCB_SYSHNDCTRL_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0xD24)))

/*  Configurable Fault Status Register */
#define SCB_FAULTSTAT                       (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD28)))
/*  Hard Fault Status Register */
#define SCB_HFAULTSTAT                      (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD2C)))
/* Memory Management Fault Address Register */
#define SCB_MMADDR                          (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD34)))
/* Bus Fault Address Register */
#define SCB_FAULTADDR                       (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD38)))
 
 /*===========================================================*
 *            System Control REGISTERS                        *
 *========================================================== */
/* Base address of System Control registers */
#define SYSTEM_CONTROL_PERI_BASE_ADDRESS          (0x400FE000)
#define SYSTEM_CONTROL_REG_SRWTIMER                         (*((volatile SRWTIMER_BF*)(SYSTEM_CONTROL_PERI_BASE_ADDRESS+0x55C)))
#define SYSTEM_CONTROL_REG_RCGCWD                           (*((volatile RCGCWD_BF*)(SYSTEM_CONTROL_PERI_BASE_ADDRESS+0x600)))
#define SYSTEM_CONTROL_REG_RCGCTIMER                        (*((volatile RCGCTIMER_BF*)(SYSTEM_CONTROL_PERI_BASE_ADDRESS+0x604)))
/*The RCGCGPIO register provides software the capability to enable and disable GPIO modules in
Run mode PAGE->340*/
#define SC_RCGCGPIO                         (*((volatile RCGCGPIO_Tag*)(SYSTEM_CONTROL_PERI_BASE_ADDRESS+0x608)))
/*This register controls which internal bus is used to access each GPIO port PAGE->258*/
#define SC_GPIOHBCTL                        (*((volatile GPIOHBCTL_Tag*)(SYSTEM_CONTROL_PERI_BASE_ADDRESS+0x06C)))
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
