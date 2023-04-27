/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief
 *
 *      \details  Dio Module's driver
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Dio.h"
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

Dio_LevelType Dio_ReadChannel(Dio_PortType Port,Dio_PortType Pin)
{

    /* Intial Value for Output Level*/
  uint32 x; 
	Dio_LevelType outputLevel = DIO_LEVEL_HIGH;
  if(Port==PORT_A || Port==PORT_B || Port==PORT_C || Port==PORT_D  || Port==PORT_E  || Port==PORT_F)  
  {
    /* Check if the used channel is within the valid range */
    if (Pin > DIO_CONFIGURED_CHANNLES)
    {

        return DIO_LEVEL_ERROR;
    }
    else
    {
     switch(Port)
        {
         case PORT_A: Port=GPIO_A_AHB; break;
         case PORT_B: Port=GPIO_B_AHB; break;
         case PORT_C: Port=GPIO_C_AHB; break; 
         case PORT_D: Port=GPIO_D_AHB; break;
         case PORT_E: Port=GPIO_E_AHB; break;
         case PORT_F: Port=GPIO_F_AHB; break;
        }
		x=BIT_IS_SET(GET_REG(Port+GPIODATA_OFFSET),Pin);
      if(x==0) outputLevel=DIO_LEVEL_LOW;
      else if (x==1) outputLevel=DIO_LEVEL_HIGH;
      else outputLevel =  DIO_LEVEL_ERROR;
        /* No Action Required */
    }
  }
  else
  {
        outputLevel =  DIO_Port_LEVEL_ERROR;
  }
    return outputLevel;
}

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

Dio_LevelType Dio_WriteChannel(Dio_PortType Port,Dio_ChannelType Pin, Dio_LevelType Level)
{
    /* Check if the used channel is within the valid range */
    Dio_LevelType outputLevel = DIO_LEVEL_HIGH;
        /* Check if the used Port is within the valid range */
    if(Port==PORT_A || Port==PORT_B || Port==PORT_C || Port==PORT_D  || Port==PORT_E  || Port==PORT_F)
        {
            if( Pin > DIO_CONFIGURED_CHANNLES)
            {
              outputLevel = DIO_LEVEL_ERROR;
            }
            else
            {
              switch(Port)
              {
                case PORT_A: Port=GPIO_A_AHB; break;
                case PORT_B: Port=GPIO_B_AHB; break;
                case PORT_C: Port=GPIO_C_AHB; break; 
                case PORT_D: Port=GPIO_D_AHB; break;
                case PORT_E: Port=GPIO_E_AHB; break;
                case PORT_F: Port=GPIO_F_AHB; break;
              }

               WRITE_BIT((Port+GPIODATA_OFFSET),Pin,Level)
            }
        }
        else
        {
            outputLevel = DIO_Port_LEVEL_ERROR;
        }
        return outputLevel;
    }

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

Dio_PortType Dio_ReadPort(Dio_PortType Port)
{
    /* Intial Value for port Output Level*/
    Dio_PortType outputPort=0;
    if(Port==PORT_A || Port==PORT_B || Port==PORT_C || Port==PORT_D  || Port==PORT_E  || Port==PORT_F)
    {
      switch(Port)
        {
         case PORT_A: Port=GPIO_A_AHB; break;
         case PORT_B: Port=GPIO_B_AHB; break;
         case PORT_C: Port=GPIO_C_AHB; break; 
         case PORT_D: Port=GPIO_D_AHB; break;
         case PORT_E: Port=GPIO_E_AHB; break;
         case PORT_F: Port=GPIO_F_AHB; break;
        } 
       outputPort =  GET_REG( Port+GPIODATA_OFFSET);
    }
    else 
    {
        /*/* Error In Port Number Configuration */
    }
    return outputPort ;
}

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

Dio_LevelType  Dio_WritePort(Dio_PortType Port, Dio_PortLevelType value)
{
Dio_LevelType outputPort = DIO_LEVEL_HIGH;

    if(Port==PORT_A || Port==PORT_B || Port==PORT_C || Port==PORT_D  || Port==PORT_E  || Port==PORT_F)
    {
      switch(Port)
        {
         case PORT_A: Port=GPIO_A_AHB; break;
         case PORT_B: Port=GPIO_B_AHB; break;
         case PORT_C: Port=GPIO_C_AHB; break; 
         case PORT_D: Port=GPIO_D_AHB; break;
         case PORT_E: Port=GPIO_E_AHB; break;
         case PORT_F: Port=GPIO_F_AHB; break;
        }
      WRITE_REG((Port+GPIODATA_OFFSET),value);
    }
    else 
    {
        outputPort = DIO_Port_LEVEL_ERROR;
    }
    return outputPort;
}

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

Dio_LevelType Dio_FlipChannel(Dio_PortType Port,Dio_ChannelType Pin)
{
 
	Dio_LevelType outputLevel = DIO_LEVEL_HIGH;
    if(Port==PORT_A || Port==PORT_B || Port==PORT_C || Port==PORT_D  || Port==PORT_E  || Port==PORT_F )
        {
            if( Pin > DIO_CONFIGURED_CHANNLES)
            {
              outputLevel = DIO_LEVEL_ERROR;
            }
            else
            {
              switch(Port)
              {
                case PORT_A: Port=GPIO_A_AHB; break;
                case PORT_B: Port=GPIO_B_AHB; break;
                case PORT_C: Port=GPIO_C_AHB; break; 
                case PORT_D: Port=GPIO_D_AHB; break;
                case PORT_E: Port=GPIO_E_AHB; break;
                case PORT_F: Port=GPIO_F_AHB; break;
              }
              TOGGLE_BIT_32((Port+GPIODATA_OFFSET),Pin);
            }
        }
        else
        {
            outputLevel = DIO_Port_LEVEL_ERROR;
        }
        return outputLevel;
    
}

/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
