/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/




#ifndef ECUM_CFG_STARTUP_H
#define ECUM_CFG_STARTUP_H

/**************************************************************************************************/
/* Preprocessor includes                                                                          */
/**************************************************************************************************/
#include "Os.h" /* this is specified by Coding guideline as <ExtModule>.h. required for AppModeType */
#if (!defined(OS_AR_RELEASE_MAJOR_VERSION) || (OS_AR_RELEASE_MAJOR_VERSION != 4))
	#error "AUTOSAR major version undefined or mismatched"
#endif
#if (!defined(OS_AR_RELEASE_MINOR_VERSION) || (OS_AR_RELEASE_MINOR_VERSION != 2))
	#error "AUTOSAR minor version undefined or mismatched"
#endif


#if (ECUM_INCLUDE_DET == STD_ON)
#include "Det.h"
#endif
#include "Mcu.h"
#include "Port.h"
#include "Can_17_MCanP.h"
#include "Dio.h"
#include "Fls.h"
#include "Pwm_17_Gtm.h"
#include "Icu_17_GtmCcu6.h"
#include "IoHwAb_Adc.h"
#include "Dma.h"
#include "Spi.h"
#include "Gpt.h"
#include "Uart.h"
#include "Dsadc.h"
#include "FlsLoader.h"
#include "BswM.h" /*Required for BswM init pointer used inside EcuM_Cfg_adrModuleInitRef_t*/
/***************************************************************************************************
* Generated type declarations
***************************************************************************************************/

typedef struct
{
    const Det_ConfigType *DetInitConfigPtr_cpst;
    const Mcu_ConfigType *McuInitConfigPtr_cpst;
    const Port_ConfigType *PortInitConfigPtr_cpst;
    const Can_17_MCanP_ConfigType *Can_17_MCanPInitConfigPtr_cpst;
    const Dio_ConfigType *DioInitConfigPtr_cpst;
    const Fls_ConfigType *FlsInitConfigPtr_cpst;
    const Pwm_17_Gtm_ConfigType *Pwm_17_GtmInitConfigPtr_cpst;
    const Icu_17_GtmCcu6_ConfigType *Icu_17_GtmCcu6InitConfigPtr_cpst;
    const IoHwAb_Adc_ConfigType *IoHwAb_AdcInitConfigPtr_cpst;
    const Dma_ConfigType *DmaInitConfigPtr_cpst;
    const Spi_ConfigType *SpiInitConfigPtr_cpst;
    const Gpt_ConfigType *GptInitConfigPtr_cpst;
    const Uart_ConfigType *UartInitConfigPtr_cpst;
    const Dsadc_ConfigType *DsadcInitConfigPtr_cpst;
    const FlsLoader_ConfigType *FlsLoaderInitConfigPtr_cpst;
    const BswM_ConfigType *BswM_InitConfigPtr_cpst; /* BswM_Init pointer*/
} EcuM_Cfg_adrModuleInitRef_t;

/* Structure holds the pointers passed to the Module Init Function */
typedef struct
{
    AppModeType DefaultAppMode;
    EcuM_ShutdownTargetInfoType DefaultShutdownTarget; /*Structure to hold the Default Shutdown Target*/
    EcuM_Cfg_adrModuleInitRef_t ModuleInitPtrPB; /*Structure to hold the post build configuration pointer of the modules*/
    const EcuM_Cfg_dataWkupPNCRefStruct_tst *adrWkupPNCRefs; /* Pointer to the PNC references associated with Wakeups */
    uint8 PostBuildHash[ECUM_CFG_LENGTH_OF_HASH];
} EcuM_ConfigType;

#define ECUM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "EcuM_Cfg_MemMap.h"


extern CONST( EcuM_ConfigType, ECUM_CONST ) EcuM_Config;


#define ECUM_NO_OF_ECUMCONFIGSETS 1

extern CONSTP2CONST(EcuM_ConfigType,AUTOMATIC,ECUM_CONST) EcuM_EcuMConfigurations_cpcast[ECUM_NO_OF_ECUMCONFIGSETS];

#define ECUM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "EcuM_Cfg_MemMap.h"

#endif /*ECUM_CFG_STARTUP_H*/


