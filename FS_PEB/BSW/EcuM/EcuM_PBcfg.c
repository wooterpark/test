/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/




/*****************************************************************************************************
* 									Includes
*****************************************************************************************************/
#include "EcuM.h" /*BSW_HeaderInc_002*/
#include "EcuM_Cfg_Startup.h"

/*****************************************************************************************************
* 									Post Build  Constant - Definition
*****************************************************************************************************/

/***************************************************************************************************
Container Name	  :	EcuM_ConfigType
Description		  :	Contains all post build parameters.
***************************************************************************************************/
#define ECUM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "EcuM_Cfg_MemMap.h"



CONST( EcuM_ConfigType, ECUM_CONST ) EcuM_Config =
{
    OSDEFAULTAPPMODE,
	{
        ECUM_SHUTDOWN_TARGET_OFF    ,        0    ,    
#if (ECUM_STARTUP_DURATION == TRUE) /*will activate the Run time measurement*/
 0x00, 
 0x00
#else
 0x00
#endif//ECUM_STARTUP_DURATION
	}, /* DefaultShutdownTarget */
	{
            NULL_PTR    /*   Det    */,
            &Mcu_Config    /*   Mcu    */,
            &Port_Config    /*   Port    */,
            &Can_17_MCanP_Config    /*   Can_17_MCanP    */,
            &Dio_Config    /*   Dio    */,
            &Fls_Config    /*   Fls    */,
            &Pwm_17_Gtm_Config    /*   Pwm_17_Gtm    */,
            &Icu_17_GtmCcu6_Config    /*   Icu_17_GtmCcu6    */,
            &IoHwAb_Adc_Config    /*   IoHwAb_Adc    */,
            &Dma_Config    /*   Dma    */,
            &Spi_Config    /*   Spi    */,
            &Gpt_Config    /*   Gpt    */,
            &Uart_Config    /*   Uart    */,
            &Dsadc_Config    /*   Dsadc    */,
            NULL_PTR    /*   FlsLoader    */,
        
    &BswM_Config    /*BswM*/
    },
        &EcuM_Cfg_dataWkupPNCRef_cast[0], /* Pointer which refers to ComMPNC references associated with wakeups */
    {
        0xD4 , 0x1D , 0x8C , 0xD9 , 0x8F , 0x00 , 0xB2 , 0x04 , 0xE9 , 0x80 , 0x09 , 0x98 , 0xEC , 0xF8 , 0x42 , 0x7E
    }
};


/* The order in the array is generated according to the alphabetically sorted EcuM configuration. */
CONSTP2CONST(EcuM_ConfigType,AUTOMATIC,ECUM_CONST) EcuM_EcuMConfigurations_cpcast[ECUM_NO_OF_ECUMCONFIGSETS]=
{

    &EcuM_Config
};

#define ECUM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "EcuM_Cfg_MemMap.h"

