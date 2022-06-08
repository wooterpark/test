/*
***********************************************************************************************************************
* 
* Product Info
* Isolar version: ISOLAR-AB 4.0.2
* Product release version: RTA-BSW 3.1.0
* 
***********************************************************************************************************************
*/




/*
 **************************************************************************************************
 * Includes
 **************************************************************************************************
 */

#include "EcuM.h" /*BSW_HeaderInc_002*/

#include "EcuM_Callout.h"
#include "EcuM_RunTime.h" /*For run time measurement*/

/*Extern module Headers*/
#if(ECUM_CFG_MULTICORE_ENABLED == STD_ON)
#include "Os.h" /* required for Core Id Check */
#if (!defined(OS_AR_RELEASE_MAJOR_VERSION) || (OS_AR_RELEASE_MAJOR_VERSION != 4))
#error "AUTOSAR major version undefined or mismatched"
#endif
#if (!defined(OS_AR_RELEASE_MINOR_VERSION) || (OS_AR_RELEASE_MINOR_VERSION != 2))
#error "AUTOSAR minor version undefined or mismatched"
#endif
#endif/*ECUM_CFG_MULTICORE_ENABLED */


    
 #if (ECUM_INCLUDE_DET == STD_ON)
    #include "Det.h"
 #endif

 #include "DemApp.h"

 #include "Mcu.h"

 #include "McuFunc.h"

 #include "Port.h"

 #include "Can_17_MCanP.h"

 #include "Dio.h"

 #include "Fls.h"

 #include "VectorTable_Core0.h"

 #include "VectorTable_Core1.h"

 #include "VectorTable_Core2.h"

 #include "IrqSpi.h"

 #include "IrqDma.h"

 #include "IrqAscLin.h"

 #include "Pwm_17_Gtm.h"

 #include "Icu_17_GtmCcu6.h"

 #include "IoHwAb_ESR.h"

 #include "IoHwAb_Adc.h"

 #include "Dma.h"

 #include "Spi.h"

 #include "SpiApp.h"

 #include "Gpt.h"

 #include "IoHwAb_PWM.h"

 #include "IoHwAb_ICU.h"

 #include "Uart.h"

 #include "Dsadc.h"

 #include "Rdc.h"

 #include "GptApp.h"

 #include "Cpld.h"

 #include "PwsApp.h"

 #include "IoSigDio.h"

 #include "IoHwAb_ADC.h"

 #include "Pwm3ph.h"

 #include "PhcApp.h"

 #include "Epp_AdcApi.h"

 #include "IgbtDrvAppl.h"

 #include "CanNetWorkApp.h"

 #include "FlsLoader.h"

 #include "SnapshotFlsApp.h"

 #include "SnapshotCanApp.h"


#include "EcuM_Cfg_Startup.h"

 #include "Smu.h"
 #include "TLF35584.h"
 #include "TLF35584ErrHdl.h"
/*EcuM Private headers*/
#include "EcuM_Prv.h"

#include "L2Sample_FS.h"
#if ECUM_STARTUP_DURATION == TRUE /*will activate the Run time measurement*/

#define ECUM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "EcuM_Cfg_MemMap.h"

/*To store the start and End time EcuM_AL_DriverInitZero, EcuM_AL_DriverInitOne and EcuM_DeterminePbConfiguration
 * respectively*/

static VAR(EcuM_TimeTicks_tu64, ECUM_VAR_CLEARED_UNSPECIFIED)   EcuM_DriverInitZero_begin_ticks_u64;
static VAR(EcuM_TimeTicks_tu64, ECUM_VAR_CLEARED_UNSPECIFIED)   EcuM_DriverInitZero_end_ticks_u64;

            

static VAR(EcuM_TimeTicks_tu64, ECUM_VAR_CLEARED_UNSPECIFIED)   EcuM_DriverInitOne_begin_ticks_SlaveCore0_u64;
static VAR(EcuM_TimeTicks_tu64, ECUM_VAR_CLEARED_UNSPECIFIED)   EcuM_DriverInitOne_end_ticks_SlaveCore0_u64;

            

static VAR(EcuM_TimeTicks_tu64, ECUM_VAR_CLEARED_UNSPECIFIED)   EcuM_DriverInitOne_begin_ticks_SlaveCore1_u64;
static VAR(EcuM_TimeTicks_tu64, ECUM_VAR_CLEARED_UNSPECIFIED)   EcuM_DriverInitOne_end_ticks_SlaveCore1_u64;

            

static VAR(EcuM_TimeTicks_tu64, ECUM_VAR_CLEARED_UNSPECIFIED)   EcuM_DriverInitOne_begin_ticks_SlaveCore2_u64;
static VAR(EcuM_TimeTicks_tu64, ECUM_VAR_CLEARED_UNSPECIFIED)   EcuM_DriverInitOne_end_ticks_SlaveCore2_u64;

            
            
static VAR(EcuM_TimeTicks_tu64, ECUM_VAR_CLEARED_UNSPECIFIED)   EcuM_DriverInitOne_begin_ticks_u64;
static VAR(EcuM_TimeTicks_tu64, ECUM_VAR_CLEARED_UNSPECIFIED)   EcuM_DriverInitOne_end_ticks_u64;
VAR(EcuM_TimeTicks_tu64, ECUM_VAR_CLEARED_UNSPECIFIED)   EcuM_DeterminePbConfiguration_begin_ticks_u64;
VAR(EcuM_TimeTicks_tu64, ECUM_VAR_CLEARED_UNSPECIFIED)   EcuM_DeterminePbConfiguration_end_ticks_u64;

#define ECUM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "EcuM_Cfg_MemMap.h"


#define ECUM_START_SEC_VAR_CLEARED_32
#include "EcuM_Cfg_MemMap.h"
/*To store the Duration of EcuM_AL_DriverInitZero, EcuM_AL_DriverInitOne and EcuM_DeterminePbConfiguration
 * respectively*/

static VAR(uint32, ECUM_VAR_CLEARED_32)              EcuM_DriverInitZero_delta_us_u32;  

            

static VAR(uint32, ECUM_VAR_CLEARED_32)              EcuM_DriverInitOne_delta_us_SlaveCore0_u32;

            

static VAR(uint32, ECUM_VAR_CLEARED_32)              EcuM_DriverInitOne_delta_us_SlaveCore1_u32;

            

static VAR(uint32, ECUM_VAR_CLEARED_32)              EcuM_DriverInitOne_delta_us_SlaveCore2_u32;

            
            
static VAR(uint32, ECUM_VAR_CLEARED_32)             EcuM_DriverInitOne_delta_us_u32;
static VAR(uint32, ECUM_VAR_CLEARED_32)              EcuM_DriverInitOne_LastReset_begin_us_u32;
static VAR(uint32, ECUM_VAR_CLEARED_32)              EcuM_DeterminePbConfiguration_delta_us_u32;

static VAR(uint32, ECUM_VAR_CLEARED_32)              EcuM_DriverInitZero_LastReset_begin_us_u32;

static VAR(uint32, ECUM_VAR_CLEARED_32)              EcuM_DeterminePbConfiguration_LastReset_begin_us_u32;

#define ECUM_STOP_SEC_VAR_CLEARED_32
#include "EcuM_Cfg_MemMap.h"

#endif /*ECUM_STARTUP_DURATION*/

/*************************************************************************************************
                            CALLOUTS
*************************************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "EcuM_Cfg_MemMap.h"
/************************************************************************************************
  Function name     :   EcuM_AL_DriverInitZero
  Description       :   This callout shall provide driver initialization and other hardware-related
                        startup activities for loading the post-build configuration data. Beware:
                        Here only pre-compile and link-time configurable modules may be used.
  Parameter (in)    :   None
  Parameter (inout) :   None
  Parameter (out)   :   None
  Return value      :   None
  Remarks           :
************************************************************************************************/

FUNC(void , ECUM_CODE) EcuM_AL_DriverInitZero(void)
{
#if ECUM_STARTUP_DURATION == TRUE /*will activate the Run time measurement*/
    EcuM_DriverInitZero_begin_ticks_u64    =   EcuM_GetTicks();
#endif /*ECUM_STARTUP_DURATION*/


#if ECUM_STARTUP_DURATION == TRUE /*will activate the Run time measurement*/
    EcuM_DriverInitZero_end_ticks_u64    =   EcuM_GetTicks();
#endif /*ECUM_STARTUP_DURATION*/
}

/**********************************************************************************
  Function name     :   EcuM_AL_DriverInitOne
  Description       :   This callout shall provide driver initialization and other
                        hardware-related startup activities in case of a power on reset.
  Parameter (in)    :   ConfigPtr
  Parameter (inout) :   None
 ***********************************************************************************/

FUNC(void , ECUM_CODE) EcuM_AL_DriverInitOne( P2CONST (EcuM_ConfigType, AUTOMATIC, ECUM_APPL_CONST) ConfigPtr )
{
    

    
            
 /* MR12 RULE 8.4 VIOLATION: The declaration of GetCoreID is expected from Os */
if (GetCoreID() == 0)/*Driver Init for OsCoreId 0*/
    {
    #if ECUM_STARTUP_DURATION == TRUE /*will activate the Run time measurement*/
    EcuM_DriverInitOne_begin_ticks_SlaveCore0_u64    =   EcuM_GetTicks();
#endif /*ECUM_STARTUP_DURATION*/
        
        
                    #if (ECUM_INCLUDE_DET == STD_ON)
                    (void)Det_Init(ConfigPtr->ModuleInitPtrPB.DetInitConfigPtr_cpst);
                    #endif
                    (void)DemApp_PreInit();
                    (void)Mcu_Init(ConfigPtr->ModuleInitPtrPB.McuInitConfigPtr_cpst);
                    (void)McuFunc_InitializeClock();
                    #if 0
                    SER_Initial_Handshake_Execute();/*LQ ETK*/
                    #endif
                    (void)Port_Init(ConfigPtr->ModuleInitPtrPB.PortInitConfigPtr_cpst);
                    (void)Can_17_MCanP_Init(ConfigPtr->ModuleInitPtrPB.Can_17_MCanPInitConfigPtr_cpst);
                    (void)Dio_Init(ConfigPtr->ModuleInitPtrPB.DioInitConfigPtr_cpst);
                    (void)Fls_Init(ConfigPtr->ModuleInitPtrPB.FlsInitConfigPtr_cpst);
                    (void)VectorTable_Core0_Init();
                    (void)IrqSpi_Init();
                    (void)IrqDma_Init();
					(void)Rdc_FS_ISR_init();
                    (void)IrqAscLin_Init();
                    (void)Pwm_17_Gtm_Init(ConfigPtr->ModuleInitPtrPB.Pwm_17_GtmInitConfigPtr_cpst);
                    (void)Icu_17_GtmCcu6_Init(ConfigPtr->ModuleInitPtrPB.Icu_17_GtmCcu6InitConfigPtr_cpst);
                    (void)IoHwAb_ESR_Init();
                    (void)IoHwAb_Adc_Init(ConfigPtr->ModuleInitPtrPB.IoHwAb_AdcInitConfigPtr_cpst);
                    (void)Dma_Init(ConfigPtr->ModuleInitPtrPB.DmaInitConfigPtr_cpst);
                    (void)Spi_Init(ConfigPtr->ModuleInitPtrPB.SpiInitConfigPtr_cpst);
                    (void)SpiApp_SetAsyncMode();
                    (void)Gpt_Init(ConfigPtr->ModuleInitPtrPB.GptInitConfigPtr_cpst);
                    (void)IoHwAb_PWM_StartGenerat();
                    (void)IoHwAb_ICU_StartMeasurement();
                    (void)Rdc_FS_init();
                    (void)Uart_Init(ConfigPtr->ModuleInitPtrPB.UartInitConfigPtr_cpst);
                    (void)Dsadc_Init(ConfigPtr->ModuleInitPtrPB.DsadcInitConfigPtr_cpst);
                    (void)FS_SetTimerTrigger_init();
                    (void)Rdc_Init();
                    (void)FS_Dsadc_SampleVW_Init();
                    (void)SWC_TRSP_initialize();
                    (void)SWC_TCF_initialize();
                    (void)SWC_SWD_initialize();
                    (void)SWC_STM_initialize();
					(void)SWC_ADM_initialize();
					(void)SWC_FRP_initialize();
                    (void)GptApp_EnableNotification();
                    (void)GptApp_StartTimer();

                    (void)PwsApp_ChipInit();
                    (void)IoSigDio_Init();
                    (void)IoHwAb_ADC_StartConversion();
                    (void)Pwm3ph_Init();
                    (void)PhcApp_Init();
                    (void)Pwm3ph_EnableIsrTrigger();
                    (void)Epp_AdcApi_Init();
//                    (void)IgbtDrvAppl_init();
                    (void)CanNetWorkApp_Init();
                    (void)FlsLoader_Init(ConfigPtr->ModuleInitPtrPB.FlsLoaderInitConfigPtr_cpst);
                    (void)SnapshotFlsApp_Init();
                    (void)SnapshotCanApp_Init();
            
        

      
#if ECUM_STARTUP_DURATION == TRUE /*will activate the Run time measurement*/
       
    EcuM_DriverInitOne_end_ticks_SlaveCore0_u64    =   EcuM_GetTicks();
    EcuM_DriverInitOne_delta_us_SlaveCore0_u32 = EcuM_GetDuration(EcuM_DriverInitOne_end_ticks_SlaveCore0_u64,EcuM_DriverInitOne_begin_ticks_SlaveCore0_u64);
       

#endif /*ECUM_STARTUP_DURATION*/
     

    }
    
    
            
 /* MR12 RULE 8.4 VIOLATION: The declaration of GetCoreID is expected from Os */
if (GetCoreID() == 1)/*Driver Init for OsCoreId 1*/
    {
    #if ECUM_STARTUP_DURATION == TRUE /*will activate the Run time measurement*/
    EcuM_DriverInitOne_begin_ticks_SlaveCore1_u64    =   EcuM_GetTicks();
#endif /*ECUM_STARTUP_DURATION*/
        
        
                    (void)VectorTable_Core1_Init();
                    (void)IgbtDrvAppl_init();
                    (void)IoHwAb_SZTKT_PWM_StartGenerat();
					TLF35584ErrHdl_Init();

                    TLF35584_Init(&TLF35584_Config);		
      
#if ECUM_STARTUP_DURATION == TRUE /*will activate the Run time measurement*/
       
    EcuM_DriverInitOne_end_ticks_SlaveCore1_u64    =   EcuM_GetTicks();
    EcuM_DriverInitOne_delta_us_SlaveCore1_u32 = EcuM_GetDuration(EcuM_DriverInitOne_end_ticks_SlaveCore1_u64,EcuM_DriverInitOne_begin_ticks_SlaveCore1_u64);
       

#endif /*ECUM_STARTUP_DURATION*/
     

    }
    
    
            
 /* MR12 RULE 8.4 VIOLATION: The declaration of GetCoreID is expected from Os */
if (GetCoreID() == 2)/*Driver Init for OsCoreId 2*/
    {
    #if ECUM_STARTUP_DURATION == TRUE /*will activate the Run time measurement*/
    EcuM_DriverInitOne_begin_ticks_SlaveCore2_u64    =   EcuM_GetTicks();
#endif /*ECUM_STARTUP_DURATION*/
        
        
                    (void)VectorTable_Core2_Init();
            
        

      
#if ECUM_STARTUP_DURATION == TRUE /*will activate the Run time measurement*/
       
    EcuM_DriverInitOne_end_ticks_SlaveCore2_u64    =   EcuM_GetTicks();
    EcuM_DriverInitOne_delta_us_SlaveCore2_u32 = EcuM_GetDuration(EcuM_DriverInitOne_end_ticks_SlaveCore2_u64,EcuM_DriverInitOne_begin_ticks_SlaveCore2_u64);
       

#endif /*ECUM_STARTUP_DURATION*/
     

    }
    
    
            
 /* MR12 RULE 8.4 VIOLATION: The declaration of GetCoreID is expected from Os */
if (GetCoreID() == ECUM_CFG_STARTUP_CORE)/*Driver Init for OsCoreId ECUM_CFG_STARTUP_CORE*/
    {
    #if ECUM_STARTUP_DURATION == TRUE /*will activate the Run time measurement*/
    EcuM_DriverInitOne_begin_ticks_u64    =   EcuM_GetTicks();
#endif /*ECUM_STARTUP_DURATION*/
        
        
            
        

      
#if ECUM_STARTUP_DURATION == TRUE /*will activate the Run time measurement*/
 
    EcuM_DriverInitOne_end_ticks_u64    =   EcuM_GetTicks();

    EcuM_DriverInitZero_delta_us_u32 = EcuM_GetDuration(EcuM_DriverInitZero_end_ticks_u64,EcuM_DriverInitZero_begin_ticks_u64);
    EcuM_DriverInitZero_LastReset_begin_us_u32 = EcuM_GetTicksSinceLastReset(EcuM_DriverInitZero_begin_ticks_u64);
    EcuM_DriverInitOne_delta_us_u32 = EcuM_GetDuration(EcuM_DriverInitOne_end_ticks_u64,EcuM_DriverInitOne_begin_ticks_u64);
    EcuM_DriverInitOne_LastReset_begin_us_u32 = EcuM_GetTicksSinceLastReset(EcuM_DriverInitOne_begin_ticks_u64);
    EcuM_DeterminePbConfiguration_delta_us_u32 = EcuM_GetDuration(EcuM_DeterminePbConfiguration_end_ticks_u64,EcuM_DeterminePbConfiguration_begin_ticks_u64);
    EcuM_DeterminePbConfiguration_LastReset_begin_us_u32 = EcuM_GetTicksSinceLastReset(EcuM_DeterminePbConfiguration_begin_ticks_u64);
        

#endif /*ECUM_STARTUP_DURATION*/
     

    }
    

}

#if ECUM_SLEEP_SUPPORT_ENABLE
/**********************************************************************************
  Function name     :   EcuM_AL_DriverRestart
  Description       :   This callout shall provide driver re initialization and other
                        hardware-related startup activities in Wakeup Case.
  Parameter (in)    :   ConfigPtr
  Parameter (inout) :   None
 ***********************************************************************************/

FUNC(void , ECUM_CODE) EcuM_AL_DriverRestart( P2CONST (EcuM_ConfigType, AUTOMATIC, ECUM_APPL_CONST) ConfigPtr )
{
}
#endif
#define ECUM_STOP_SEC_CALLOUT_CODE
#include "EcuM_Cfg_MemMap.h"

