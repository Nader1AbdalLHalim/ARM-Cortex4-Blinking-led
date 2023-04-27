/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief
 *
 *      \details Port Module's driver
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Port.h"

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
/* what it will do :
# Enable  Advanced High Performance Bus for reqiured Port
# Enable GPIO Clock
# Get the Base Address of GPIO
# Enable GPIO PORT Digital Mode
# Set Port Pins Direction
# Set Port Pins Output Current
# Set Port Pins Level
*/

void Port_Init(const Port_ConfigType *ConfigPtr)
{
    /* Iterator Counter used to iterate on the array of the configuration strucrtues of all configures of Port Driver */
    uint8 counter = 0;

    /* Base Address of GPT Peripheral*/
    volatile uint32 *TargetAddress = NULL_PTR;

    if ( ConfigPtr == NULL_PTR )
    {
        return; /*Configurations Error .*/ 
    }

    else
    {
        /* No Action Required */
    }

    for (counter = 0; counter < PORT_CONFIGURED_CHANNLES; counter++)
    {

        switch (ConfigPtr->PortNumber)
        {
        case PORT_A:
            /* Enable GPIO PORT_A Advanced High Performance Bus*/
            SC_GPIOHBCTL.W.PORTA = ENABLE;
            /* Enable GPIO PORT_A Clock*/
            SC_RCGCGPIO.S.R0 = ENABLE;
            /* Get the Base Address of GPIO PORT_A Module*/
            TargetAddress = (volatile uint32 *)GPIO_A_AHB;
            break;
        
        case PORT_B:
            /* Enable GPIO PORT_B Advanced High Performance Bus*/
            SC_GPIOHBCTL.W.PORTB = ENABLE;
            /* Enable GPIO PORT_B Clock*/
             SC_RCGCGPIO.S.R1 = ENABLE;
            /* Get the Base Address of GPIO PORT_B Module*/
            TargetAddress = (volatile uint32 *)GPIO_B_AHB;
            break;
        
        case PORT_C:
            /* Enable GPIO PORT_C Advanced High Performance Bus*/
            SC_GPIOHBCTL.W.PORTC = ENABLE;
            /* Enable GPIO PORT_C Clock*/
            SC_RCGCGPIO.S.R2 = ENABLE;
            /* Get the Base Address of GPIO PORT_C Module*/
            TargetAddress =(volatile uint32 *)GPIO_C_AHB;
            break;
				
        case PORT_D:
            /* Enable GPIO PORT_D Advanced High Performance Bus*/
            SC_GPIOHBCTL.W.PORTD = ENABLE;

            /* Enable GPIO PORT_D Clock*/
            SC_RCGCGPIO.S.R3 = ENABLE;

            /* Get the Base Address of GPIO PORT_D Module*/
            TargetAddress =(volatile uint32 *)GPIO_D_AHB;
            break;
				
        case PORT_E:
            /* Enable GPIO PORT_E Advanced High Performance Bus*/
            SC_GPIOHBCTL.W.PORTE = ENABLE;

            /* Enable GPIO PORT_E Clock*/
            SC_RCGCGPIO.S.R4 = ENABLE;

            /* Get the Base Address of GPIO PORT_E Module*/
            TargetAddress =(volatile uint32 *)GPIO_E_AHB;
            break;
				
        case PORT_F:
            /* Enable GPIO PORT_F Advanced High Performance Bus*/
            SC_GPIOHBCTL.W.PORTF = ENABLE;

            /* Enable GPIO PORT_F Clock*/
            SC_RCGCGPIO.S.R5 = ENABLE;

            /* Get the Base Address of GPIO PORT_F Module*/
            TargetAddress =(volatile uint32 *)GPIO_F_AHB;
            break;
				
        default:
            /* No Action Required */
            break;
        }

        /* Check of the user filled the configuration Successfully*/
        if (NULL_PTR == TargetAddress)
        {
            /* Configurations Error */
            return ;
        }

        else
        {
            /* Configurations Successfully */
            /* No Action Required */
        }
        /********************************Enable GPIO PORT Digital Mode **********************************/
        if (ConfigPtr->PortPinMode == PINMODE_DIGITAL)
        {                   
					TargetAddress+=GPIODEN_OFFSET; 
					WRITE_BIT(TargetAddress,ConfigPtr->PinNumber,LOW)
				}
        else
        {
            /* No Action Required */
        }

        /********************************Set Port Pins Direction**********************************/
        if (ConfigPtr->PortPinDirection == PIN_OUTPUT)
        {
          TargetAddress+=GPIODIR_OFFSET; 
				//GET_REGISTER(TargetAddress, uint32, GPIODIR_OFFSET);
				//	SET_BIT(GET_REGISTER(TargetAddress, uint32, GPIODIR_OFFSET), ConfigPtr->PinNumber);
			  //SET_BIT(GET_REGISTER((volatile uint8 *)TargetAddress, uint32, GPIODIR_OFFSET), ConfigPtr->PinNumber);
				 WRITE_BIT(TargetAddress,0 ,HIGH)
        }
        else if (ConfigPtr->PortPinDirection == PIN_INPUT)
        {                    
					TargetAddress+=GPIODIR_OFFSET; 
					WRITE_BIT(TargetAddress, ConfigPtr->PinNumber,LOW)

        }
        else
        {
            /* No Action Required */
        }
        /********************************Set Port Pins Output Current**************************/
        if (ConfigPtr->PortPinOutputCurrent == PINOUTPUTCURRENT_2_MA)
        {
          TargetAddress += GPIODR2R_OFFSET;  
					WRITE_BIT(TargetAddress, ConfigPtr->PinNumber,HIGH)
        }
        else if (ConfigPtr->PortPinOutputCurrent == PINOUTPUTCURRENT_4_MA)
        {
          TargetAddress += GPIODR4R_OFFSET;   
					WRITE_BIT(TargetAddress, ConfigPtr->PinNumber,HIGH)
        }
        else if (ConfigPtr->PortPinOutputCurrent == PINOUTPUTCURRENT_8_MA)
        {
          TargetAddress += GPIODR8R_OFFSET;   
					WRITE_BIT(TargetAddress, ConfigPtr->PinNumber,HIGH)
        }
        else
        {
            /* No Action Required */
        }

        /********************************Set Port Pins Internal Resitors **************************/
        if (ConfigPtr->PortPinInternalAttach == OpenDrain)
        {
          TargetAddress += GPIOODR_OFFSET;  
					WRITE_BIT(TargetAddress, ConfigPtr->PinNumber,HIGH)
        }
        else if (ConfigPtr->PortPinInternalAttach == PullUp)
        {
          TargetAddress += GPIOPUR_OFFSET;   
					WRITE_BIT(TargetAddress, ConfigPtr->PinNumber,HIGH)
        }
        else if (ConfigPtr->PortPinInternalAttach == PullDown)
        {
          TargetAddress += GPIOPDR_OFFSET;   
					WRITE_BIT(TargetAddress, ConfigPtr->PinNumber,HIGH)
        }
        else
        {
            /* No Action Required */
        }

        /********************************Set Port Pins Level**********************************/
        if (ConfigPtr->PortPinLevelValue == PIN_LEVEL_HIGH)
        {
           TargetAddress+=GPIODATA_OFFSET; 
					WRITE_BIT(TargetAddress, ConfigPtr->PinNumber,HIGH)
        }
        else if (ConfigPtr->PortPinLevelValue == PIN_LEVEL_LOW)
        {
          TargetAddress+=GPIODATA_OFFSET ; 
					WRITE_BIT(TargetAddress, ConfigPtr->PinNumber,LOW)
        }
        else
        {
            /* No Action Required */
        }
    }
}

/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/
