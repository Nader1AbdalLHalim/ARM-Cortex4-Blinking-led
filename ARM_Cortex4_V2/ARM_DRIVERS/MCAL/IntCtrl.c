/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief
 *
 *      \details  IntCrtl Module's driver
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "IntCtrl.h"

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


void Intrupt_Init(void)
{
    uint8 counter = 0;
	
    /*Configure Grouping/SubGrouping System in APINT register in SCB
    this function take its configuration from InctCtrl.h */
    Set_Grouping_Priority ();
    
    for (counter = 0; counter < CONFIGURED_EXCEPTIONS_NUM; counter++)
    {
        /* Check if Exception enabled or disabled */
        if (IntCtrl_Config.Exceptions[counter].Level == EXC_DISABLED)
        {
            switch (IntCtrl_Config.Exceptions[counter].ExceptionId)
            {
            case RESET:
            case NMI:
            case HARD_FAULT:
                break; /* Can not disable this exceptions*/
            case MEMORY_MANAGE_FAULT:
                SCB_SYSHNDCTRL.MEM = 0;
                break;
            case BUS_FAULT:
                SCB_SYSPRI1.BUS = IntCtrl_Config.Exceptions[counter].Priority;
                SCB_SYSHNDCTRL.BUS = 1;
                break;
            case USAGE_FAULT:
                SCB_SYSPRI1.USAGE = IntCtrl_Config.Exceptions[counter].Priority;
                SCB_SYSHNDCTRL.USAGE = 1;
                break;
            case SVCALL:
                SCB_SYSPRI2.SVC = IntCtrl_Config.Exceptions[counter].Priority;
                break;
            case DEBUG_MONITOR:
                SCB_SYSPRI3.DEBUG = IntCtrl_Config.Exceptions[counter].Priority;
                break;
            case PENDSV:
                SCB_SYSPRI3.PENDSV = IntCtrl_Config.Exceptions[counter].Priority;
                break;
            case SYSTICK:
                SCB_SYSPRI3.TICK = IntCtrl_Config.Exceptions[counter].Priority;
                STCTRL.B.INTEN = 1;
                break;
            }
        }
        else if (IntCtrl_Config.Exceptions[counter].Level == EXC_ENABLED)
        {

            switch (IntCtrl_Config.Exceptions[counter].ExceptionId)
            {
            case RESET:
            case NMI:
            case HARD_FAULT:
                break;
            case MEMORY_MANAGE_FAULT:
                SCB_SYSPRI1.MEM = IntCtrl_Config.Exceptions[counter].Priority;
                SCB_SYSHNDCTRL.MEM = 1;
                break;
            case BUS_FAULT:
                SCB_SYSHNDCTRL.BUS = 0;
                break;
            case USAGE_FAULT:
                SCB_SYSHNDCTRL.USAGE = 0;
                break;
            case SVCALL:
                break;
            case DEBUG_MONITOR:
                break;
            case PENDSV:
                break;
            case SYSTICK:
                STCTRL.B.INTEN=0;
                break;
            }
        }
    }

    for (counter = 0; counter < CONFIGURED_INTERRUPTS_NUM; counter++)
    {
        /* Check if Interrupt enabled or disabled */
        if (IntCtrl_Config.Interrupts[counter].Level == INT_DISABLED)
        {
            IntCtrl_InterruptType IntruptNum = IntCtrl_Config.Interrupts[counter].interruptId;
            if(IntruptNum > 138)
            {
             DisableIntrupt( IntruptNum );
            }
            else
            {
                /* Interrupt Id error. */
            }
        }
        else if (IntCtrl_Config.Interrupts[counter].Level == INT_ENABLED)
        {
          IntCtrl_InterruptType IntruptNum = IntCtrl_Config.Interrupts[counter].interruptId;
          uint8 PriorityNum = IntCtrl_Config.Interrupts[counter].Priority;
            
            if(PriorityNum < 8 )
            {
            /* Assign the priority to the  interrupt */
            SetPriority( IntruptNum , PriorityNum);
            }
            else
            {
                /* Interrupt PriorityNum error. */
            }
            
            /* Enable the interrupt, by setting the corresponding bit in ENx */ 
            if(IntruptNum > 138)
            {
             EnableIntrupt( IntruptNum );
            }
            else
            {
                /* Interrupt Id error. */
            }
        }
    }
}

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
static void Set_Grouping_Priority(void)
{
#ifdef PRIORITY_GROUP_XXX
	SCB_APINT = (VECTKEY_APINT <<  VECTKEY_Position_APINT) | (0x00000000 << APINT_PRIGROUP_Position);
	
	#elif defined(PRIORITY_GROUP_XXY)
	SCB_APINT = (VECTKEY_APINT <<  VECTKEY_Position_APINT) | (0x00000005 << APINT_PRIGROUP_Position);
	
	#elif defined(PRIORITY_GROUP_XYY)
	SCB_APINT = (VECTKEY_APINT <<  VECTKEY_Position_APINT) | (0x00000006 << APINT_PRIGROUP_Position);
	
	#elif defined(PRIORITY_GROUP_YYY)
	SCB_APINT = (VECTKEY_APINT <<  VECTKEY_Position_APINT) | (0x00000007 << APINT_PRIGROUP_Position);
	#else
    #error "Invalid Priority Group/Subgroup"
    #endif
}
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

void SetPriority (IntCtrl_InterruptType IntruptNum,uint32 PriorityNum)
 {
	uint32 i = IntruptNum/4;
   if( IntruptNum == 4*i)        /*5->7 bits*/ 
   {
	 switch(PriorityNum)
	  {
		case 0:
        /*do nothing*/
		break;
		case 1 :
		SET_BIT(PRIX(i),5); /*0b001 priority 1*/  
		break;
		case 2 :
    SET_BIT(PRIX(i),6);  /*0b010 priority 2*/
    break;
		case 3 :
		SET_BIT(PRIX(i),5); /*0b001 priority */ 
	  SET_BIT(PRIX(i),6); /*0b011 priority 3*/ 
    break;
		case 4 :
		SET_BIT(PRIX(i),7); /*0b100 priority 4*/ 
		break;
		case 5 :
		SET_BIT(PRIX(i),5); /* 0b001 priority */
	  SET_BIT(PRIX(i),7); /*0b101 priority 5*/  
		break;
		case 6 :
		SET_BIT(PRIX(i),6); /*//0b011 priority */ 
		SET_BIT(PRIX(i),7); /*0b110 priority 6*/ 
		break;
		case 7 :
		SET_BIT(PRIX(i),5); /*0b011 priority */ 
		SET_BIT(PRIX(i),6); /*0b110 priority */ 
	  SET_BIT(PRIX(i),7); /*0b111 priority 7*/ 
		break;
	  }
   }
   
   else if(IntruptNum == 4*i + 1) /*13->15*/
   {
	  switch(PriorityNum)
	  {
		case 0:
    /*do nothing*/
		break;
		case 1 :
		SET_BIT(PRIX(i),13);  /*0b001 priority 1*/ 
		break;
		case 2 :
    SET_BIT(PRIX(i),14);  /*0b010 priority 2*/ 
    break;
		case 3 :
		SET_BIT(PRIX(i),13);  /*0b001 priority*/ 
	  SET_BIT(PRIX(i),14); /*0b011 priority 3*/
    break;
		case 4 :
		SET_BIT(PRIX(i),15);  /*0b100 priority 4*/ 
		break;
		case 5 :
		SET_BIT(PRIX(i),13);  /*0b001 priority */
	  SET_BIT(PRIX(i),15);  /*0b101 priority 5*/
		break;
		case 6 :
		SET_BIT(PRIX(i),14);  /*0b011 priority*/
		SET_BIT(PRIX(i),15);  /*0b110 priority 6*/
		break;
		case 7 :
		SET_BIT(PRIX(i),13);  /*0b011 priority */
		SET_BIT(PRIX(i),14);  /*0b110 priority*/   
	  SET_BIT(PRIX(i),15);  /* 0b111 priority 7 */
		break;
	  }
    
   }
   
   else if (IntruptNum == 4*i + 2)  /*23->25*/
   {
	  switch(PriorityNum)
	  {
		case 0:
    /*do nothing*/
		break;
		case 1 :
		SET_BIT(PRIX(i),23);  /*0b001 priority 1*/
		break;
		case 2 :
    SET_BIT(PRIX(i),24);  /*0b010 priority 2*/
     break;
		case 3 :
		SET_BIT(PRIX(i),23);  /*0b001 priority*/ 
	  SET_BIT(PRIX(i),24);  /*0b011 priority 3*/
    break;
		case 4 :
		SET_BIT(PRIX(i),25);  /*0b100 priority 4*/
		break;
		case 5 :
		SET_BIT(PRIX(i),23);  /*0b001 priority */
	  SET_BIT(PRIX(i),25);  /*0b101 priority 5*/
		break;
		case 6 :
		SET_BIT(PRIX(i),24);  /*0b011 priority*/ 
		SET_BIT(PRIX(i),25);  /*0b110 priority 6*/
		break;
		case 7 :
		SET_BIT(PRIX(i),23);  /*0b011 priority*/ 
		SET_BIT(PRIX(i),24);  /*0b110 priority*/   
	  SET_BIT(PRIX(i),25); /*0b111 priority 7*/
		break;
	  }

	   
   }

   else if (IntruptNum == 4*i + 3)  /*29->31*/ 
   {
	 
	 switch(PriorityNum)
	  {
		case 0:
        /*do nothing*/
		break;
		case 1 :
		SET_BIT(PRIX(i),29);  /*0b001 priority 1*/
		break;
		case 2 :
    SET_BIT(PRIX(i),30); /* //0b010 priority 2*/
    break;
		case 3 :
		SET_BIT(PRIX(i),29);   /* //0b001 priority */
	  SET_BIT(PRIX(i),30); /* //0b011 priority 3*/
    break;
		case 4 :
		SET_BIT(PRIX(i),31); /* //0b100 priority 4 */
		break;
		case 5 :
		SET_BIT(PRIX(i),29); /* //0b001 priority */
	  SET_BIT(PRIX(i),31); /* //0b101 priority 5*/
		break;
		case 6 :
		SET_BIT(PRIX(i),30); /* //0b011 priority */
		SET_BIT(PRIX(i),31); /* //0b110 priority 6*/
		break;
		case 7 :
		SET_BIT(PRIX(i),29); /* //0b011 priority */
		SET_BIT(PRIX(i),30); /* //0b110 priority */  
	  SET_BIT(PRIX(i),31); /* //0b111 priority 7*/
		break;
	  }

   }
   else
   {
	/*error handling*/
   }

 }

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
void EnableIntrupt(IntCtrl_InterruptType IntruptNum)
{
uint32 n = IntruptNum/32;
uint32 BitNum = IntruptNum - 32*n ;
SET_BIT(ENX(n),BitNum);
}
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
void DisableIntrupt(IntCtrl_InterruptType IntruptNum)
 {
  uint32 n = IntruptNum/32;
uint32 BitNum = IntruptNum - 32*n ;
SET_BIT(DISX(n),BitNum);
 }
/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
