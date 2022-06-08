
/*******************************************************************************
** Copyright (C) Infineon Technologies (2016)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : RefApp.c $                                                 **
**                                                                            **
**   $CC VERSION : \main\155 $                                                **
**                                                                            **
**   $DATE       : 2018-04-25 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  COMPILER  : Tasking/GNU/Diab                                              **
**                                                                            **
**  AUTHOR    : SafeTlib Team                                                 **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY:                                                             **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - sample Demo Tests for all the SafeTlib modules                                    **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: Yes                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Mcal.h"
#include "Std_Types.h"
#include "IfxSmu_reg.h"
#include "IfxPort_reg.h"
#include "IfxScu_reg.h"
#include "IfxCpu_reg.h"
#include "IfxMtu_reg.h"
#include "IfxMc_bf.h"
#include "IfxMc_reg.h"
#include "TstM.h"
#include "SmuIntHandler.h"

/* Watchdog files are included only if Run time tests are enabled */
#if(SL_RUNTIME_TESTS == TRUE)
#include "SafeWdgIf.h"
#include "SafeWdgM.h"
  /* SafeWdgExt_Config.h is used for external watchdog configuration only */
  #ifndef SWDG_INT_WDG_ONLY
  #include "SafeWdgExt_Config.h"
  #endif /* ifndef SWDG_INT_WDG_ONLY*/
#endif /* (SL_RUNTIME_TESTS == TRUE) */


#include "AppCbk.h"
#include "RefApp.h"
#include "Mcal_Options.h"
#include "Sl_FlsErrPtrn.h"
#include "SramEccTst_MemDef.h"

#include "Mcu.h"
#include "Port.h"
#include "Dio.h"

#if((CHIP_ID != 21U) && (CHIP_ID != 22U))
#include "IfxEmem_reg.h"
#endif
/******************************************************************************
**                      Local Macro Definitions                              **
******************************************************************************/
#if (SAFETLIB_APPLN_DEBUG == FALSE) 
//#define print_f(x)
#endif
/*******************************************************************************
******                    Masks for LEDs on dev board            ***************
*******************************************************************************/

/*******************************************************************************
******                    CORE STARTUP SEQUENCE                  ***************
*******************************************************************************/
#if ((CHIP_ID == 21U) || (CHIP_ID == 22U))
/* TC21x / TC22x does not have EMEM, give invalid range to create a trap if
 * test case is executed on TC21x / TC22x by mistake:
 */
#define EMEM_START_ADDR             0x00000000U
#define EMEM_END_ADDR               0x00000008U
#elif ((CHIP_ID == 23U) || (CHIP_ID == 24U))
#define EMEM_START_ADDR             0xBF000000U
#define EMEM_END_ADDR               0xBF03FFFFU
#elif (CHIP_ID == 26U)
#define EMEM_START_ADDR             0xBF000000U
#define EMEM_END_ADDR               0xBF07FFFFU
#elif (CHIP_ID == 27U)
#define EMEM_START_ADDR             0xBF000000U
#define EMEM_END_ADDR               0xBF0FFFFFU
#elif (CHIP_ID == 29U)
#define EMEM_START_ADDR             0xBF000000U
#define EMEM_END_ADDR               0xBF1FFFFFU
#else
#error "Invalid CHIP_ID"
#endif

/* For 26x, 29x Master core is "Core1" */
#if (CHIP_ID == 26)
#define SLAVE_CORE_1      (0)
#elif (CHIP_ID == 29)
#define SLAVE_CORE_1      (0)
#define SLAVE_CORE_2      (2)

/* For 27x,24x,23x,22x,and 21x master core is "core0" */
#else
#if ( MCAL_NO_OF_CORES > 1U )
#define SLAVE_CORE_1      (0u)
#if ( MCAL_NO_OF_CORES == 3U )
#define SLAVE_CORE_2      (2u)
#endif /* ( MCAL_NO_OF_CORES == 3U ) */
#endif /* ( MCAL_NO_OF_CORES > 1U ) */
#endif /* ( MCAL_NO_OF_CORES > 1U ) */

/* CPU debug status register for core1 and core2 */
#if ( MCAL_NO_OF_CORES > 1U )
#define SLAVECORE1_DBGSR CPU0_DBGSR
#if ( MCAL_NO_OF_CORES == 3U )
#define SLAVECORE2_DBGSR CPU2_DBGSR
#endif /* ( MCAL_NO_OF_CORES == 3U ) */
#endif /* ( MCAL_NO_OF_CORES > 1U ) */



#define TC264           (0x60U)
#define TC265           (0x61U)
#define TC267           (0x66U)
#define TC264_ADAS      (0x68U)
#define TC260           (0x6FU)

#define TC275           (0x70U)
#define TC277           (0x71U)
#define TC275_AGBT      (0x73U)
#define TC270           (0x7FU)

#define TC297           (0x90U)
#define TC298           (0x91U) 
#define TC299           (0x96U)
#define TC297_ADAS      (0x98U) 

#define TC212           (0x12U)
#define TC213           (0x10U)
#define TC214           (0x11U)

#define TC222           (0x22U)
#define TC223           (0x20U)
#define TC224           (0x21U)

#define TC233           (0x30U)
#define TC234           (0x31U)
#define TC237           (0x32U) 



/*******************************************************************************
**********************       Watchdog info       ******************************
*******************************************************************************/
/* TLF macro definitions */
#if defined (SWDG_EXT_TLF_WDG_ONLY) || defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG)
	/* execution of runtime tests */
	#define DTI_TESTEXEC_SLICE              (0u)  
	/* service the watchdog */
	#define DTI_SERVICE_SLICE               (1u)  
	/* mandatory status request slice*/
	#define DTI_INFO_SLICE                  (2u)  
  /* optional user request slice*/
  #define DTI_USRREQ_SLICE                  (3u)
	/* 1333Hz = 0.75ms cycle time for each slice and 8 Slices result in (8 *0.75)6ms cycle Time for TLF */
	/* 1000Hz = 1ms cycle time for each slice and 6 Slices result in(6 *1)6ms cycle Time for TLF  for TLF */
	/* 833Hz  = 1.2ms cycle time for each slice and 5 Slices result in (5*1.2)6ms cycle Time for TLF */
	/* 666Hz  = 1.5ms cycle time for each slice and 4 Slices result in (4*1.5)6ms cycle Time for TLF */
	/* 600Hz  = 1.66ms cycle time for each slice and 3 Slices result in (3*1.66)4.98 cycle Time for TLF */
	/* 266Hz  = 3.75 ms cycle time for each slide and 4 slices result in (4*3.75) 15ms cycle time for TLF*/
	/* 200Hz  = 5 ms cycle time for each slide and 4 slices result in (4*5) 20ms cycle time for TLF*/
	/* 190Hz  = 5.26 ms cycle time for each slide and 4 slices result in (4*5.26) 21.04 ms cycle time for TLF*/ 
	/* This determines slice duration */
	#define RA_DTI_FREQ                     (190u) 
	/* No of slice in a DTI */
	#define RA_DTI_SLICES                   (4u)
	#define RA_WDG_INITCHKTASK_CYCLES_MAX         (1u)     
	/* from Not ready to active state */
	#define RA_WDG_ACTIVATETASK_CYCLES_MAX         (1u)
  /* max accepted consecutive communication failures during runtime */
  #define RA_JOBFAIL_MAX                  (5u)

  /* Sets wait time safety path check task */
  #define RA_WDG_SWITCHOFFTASK_CYCLES_MAX         (200u)

#endif /* if defined (SWDG_EXT_TLF_WDG_ONLY) || defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG)*/ 

/* CIC macro definitions */
#ifdef SWDG_EXT_CIC_WDG_ONLY
  /* Slice in SecureSPI mode only */
  #define DTI_SECSPI_USRREQ1_SLICE                (0U)
  #define DTI_SECSPI_USRREQ2_SLICE                (1U)
  #define DTI_SECSPI_USRREQ3_SLICE                (2U)
  #define DTI_SECSPI_USRREQ4_SLICE                (3U)
  #define DTI_SECSPI_USRREQ5_SLICE                (4U)
  /* execution of runtime tests */
  #define DTI_TESTEXEC_SLICE                      (0u)  
  /* service the watchdog */
  #define DTI_SERVICE_SLICE                       (1u)  
  /* optional slices for external watchog types */
  /*   !! do not change values !!            */

  /* optional user request slice*/
  #define DTI_USRREQ1_SLICE                       (2u)  
  /* mandatory status request slice*/
  #define DTI_INFO_SLICE                          (3u)       
  /* optional user request slice */
  #define DTI_USRREQ2_SLICE                       (4u)  
  /* 1333Hz = 0,75ms cycle time and 8 Slices result in 6ms cycle Time for CIC */
  /* 1000Hz =    1ms cycle time and 6 Slices result in 6ms cycle Time for CIC */
  /* 833Hz  =  1,2ms cycle time and 5 Slices result in 6ms cycle Time for CIC */
  /* 666Hz  =  1,5ms cycle time and 4 Slices result in 6ms cycle Time for CIC */
  /* This determines slice duration */
  #define RA_DTI_FREQ                             (833u)
  /* No of slice in a DTI */
  #define RA_DTI_SLICES                           (5u)
  /* max accepted consecutive communication failuresduring runtime */
  #define RA_JOBFAIL_MAX                          (5u)     
  /* upper limit for init cycles (Slice ticks) */
  /* values are examples only and depend on CIC configuration for 
    tripping state duration - adjustment for application required
  */ 
  /* Sets wait time safety path check task */ 
  #define RA_WDG_SWITCHOFFTASK_CYCLES_MAX         (400u)    
  /* Sets wait time from disabled to not ready task*/ 
  #define RA_WDG_INITCHKTASK_CYCLES_MAX           (400u)    
  /* Sets wait from Not ready to active state task */
  #define RA_WDG_ACTIVATETASK_CYCLES_MAX          (100u)    
  /* Sets wait from Not ready to secure spi task */
  #define RA_CICWDG_TASK_SECSPI_CYCLES_MAX        (100u) 
  /* Sets pause period while CIC executes BIST */
  #define RA_EXTCIC_PAUSE1_CYCLES                 (40u)      
  /* Sets pause period before moving to active state */
  #define RA_EXTCIC_PAUSE2_CYCLES                 (25u)      
  /* Configure to execute state check for CIC */
  #define RA_EXTCIC_STATE_CHECK                   (TRUE)   
  /*  Configure to execure SecureSPI task */ 
  #define RA_EXTCIC_SECCURESPI_CHECK              (TRUE)   
  /*  Configure to execure Temp Sequence Test */
  #define RA_EXTCIC_TEMPSEQTEST_ENABLED           (TRUE)  
 /* additional includes for the Cic watchdog */
  #include "SafeWdgExtCic_MF.h"
  #include "SafeWdgExtCic_UcHandler.h"
  /* This is used for Cic state check verification */
  boolean Cic_StateCheck_Over   =  FALSE;
  boolean RA_Cic_StateCheckDeInitCalled = FALSE;
  SafeWdgIf_ResultType GetCicTestResult = SWDG_JOB_FAILED;
#endif/*End of SWDG_EXT_CIC_WDG_ONLY*/

#if defined (SWDG_EXT_TLF_WDG_ONLY) || defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG)
#include "SafeWdgExtTlf.h"
#endif /*end of SWDG_EXT_TLF_WDG_ONLY || SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG */

/* Internal watchdog macro definitions */
#ifdef SWDG_INT_WDG_ONLY
 /* 333Hz  =  3.0ms cycle time and 2 Slices result in 6ms cycle Time for Intwdg */
 #define RA_DTI_FREQ                     (333u)
 /* Number of slices per DTI */
 #define RA_DTI_SLICES                   (2u)
 /* execution of runtime tests */
 #define DTI_TESTEXEC_SLICE              (0u)     
 /* service the watchdog */
 #define DTI_SERVICE_SLICE               (1u)     
 /* safety path check */
 #define RA_WDG_SWITCHOFFTASK_CYCLES_MAX         (1u)     
 /* from disabled to not ready */
 #define RA_WDG_INITCHKTASK_CYCLES_MAX         (1u)     
 /* from Not ready to active state */
 #define RA_WDG_ACTIVATETASK_CYCLES_MAX         (1u)     
#endif /* ifdef SWDG_INT_WDG_ONLY*/

/*******************************************************************************
*******************        Slave Core run time states        *******************
*******************************************************************************/
/* To provide synchronization between runtime tests in all the Cores */
#define RA_RUNTIME_PHASE_ACTIVE (1U)
#define RA_RUNTIME_PHASE_IDLE   (2U)
 
/*******************************************************************************
*******************          Other defines                   *******************
*******************************************************************************/
/* Default PLL frequency */
/* fPLL can be set via RefApp build batch file. If not set, then this default 
frequency is used */
#ifndef _RA_PLL_FREQ_
	#if((CHIP_ID == 21U) || (CHIP_ID == 22U))
	#define _RA_PLL_FREQ_ (100U)
	#else
	#define _RA_PLL_FREQ_ (200U)
	#endif
#endif

/* Default settings: ICACHE = ON, DCACHE = OFF, MPU = OFF */
/* _RA_CACHE_MPU_CFG_ = (XYZ)b ==> Z = ICACHE, Y = DCACHE, X = MPU */
#ifndef _RA_CACHE_MPU_CFG_
#define _RA_CACHE_MPU_CFG_ (0U)
#endif

/* Alarm ID used by core 0 */
#define REFAPP_STM_ALARM_ID_0       (0u)
/* Alarm ID used by core 1 */
#define REFAPP_STM_ALARM_ID_1       (1u)

#define SCU_PMCSR     							((volatile Ifx_SCU_PMCSR*)(void *)&SCU_PMCSR0)

/* Defining CPU Memory Protection Range  */
#define ADDRESS_SPACE_START         ( 0x00000000U )
#define ADDRESS_SPACE_END           ( 0xFFFFFFF8U )
/* Bit mask for selecting CPR0 in the CPXE_x:                               */
#define CPR0_SELECTION_MASK         ( 0x00000001U )
/* Bit mask for selecting DPR0 in DPRE_x and DPWE_x:                        */
#define DPR0_SELECTION_MASK         ( 0x00000001U )
/* PROTEN bit of the SYSCON CSFR:                                           */
#define SYSCON_PROT_EN_BIT          ( 0x00000002U )
/* Count used to get 1ms DTI*/
#define RA_DTIFREQ                  (1000U)


#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
#define DEBUG()  __debug()
#endif
#endif

#ifdef _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)
#define DEBUG() __asm__ volatile ("debug")
#endif
#endif

#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
#define DEBUG() __debug()
#define __debug _debug
#endif
#endif

/* Sram Memory to test */
#if (CHIP_ID == 26U)
#define MEM_TO_TEST     (0X00000004U)
#elif (CHIP_ID == 27U)
#define MEM_TO_TEST     (0X00001080U)
#elif (CHIP_ID == 29U)
#define MEM_TO_TEST     (0X00001004U)
#else
#define MEM_TO_TEST     (0X00000004U)  
#endif

/* test code added for Sram */
#define SRAMECCTST_MEMORY_COUNT_LOCAL            ((uint8)15U)
/* mask for core ID bits */
#define SRAM_CORE_ID_MASK               (3u)

/* mask for password Bits 2-7 */
#define SRAM_WDT_PASSWORD_LOWER_MASK    (0x000000FCu)

/* mask for password Bits 8-15 */
#define SRAM_WDT_PASSWORD_UPPER_MASK    (0x0000FF00u)

/* mask for password bits */
#define SRAM_WDT_PASSWORD_MASK          (SRAM_WDT_PASSWORD_LOWER_MASK | \
                                         SRAM_WDT_PASSWORD_UPPER_MASK)
/* mask for reload bits */
#define SRAM_WDT_RELOAD_MASK            (0xFFFF0000u)

/* mask for LCK and ENDINIT status bits */
#define SRAM_WDT_STATUS_MASK            (0x00000003u)

/* MCx_CONNFIG0 values: */
#define SRAM_CONFIG0_NUMACCS_1          (1U)
#define SRAM_CONFIG0_ACCSTYPE_RD        (1U)
#define SRAM_CONFIG0_ACCSTYPE_WR        (0U)
#define MC_MCONTROL_USERED_MSK          (1U)
#define MC_MCONTROL_USERED              (14U)

/* Reload value for watch dog in timeout mode */
#define SDWT_TIMEOUT_MODE_RELOAD        (0xFFFC0000u)

/* OSCU Control Register */
#define CBS_OCNTRL						(*((volatile uint32*)0xF000047Cu))

typedef struct SramEccErr_WdtContextType
{
  /* Backup of watchdog timer reload value and password: */
  uint32  WdtTimAndPw;
}SramEccErr_WdtContextType;

/******************************************************************************
**                        Imported declarations                              **
******************************************************************************/
extern void IrqStm_Init(void);

/******************************************************************************
**                        Local function prototypes                          **
******************************************************************************/
#define IFX_APPL_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#if(SL_RUNTIME_TESTS == TRUE)
static void RA_RunTimeTest(void);
extern void RA_SetupDTI(void);
static void RA_WdgService(void);
#if (IFX_MCAL_USED == STD_OFF)
static void RA_Tick(void);
static void RA_SysReset(void);
static void RA_WasteTime(void);
static boolean RA_Cycle(uint32 counter);
#ifdef SWDG_EXT_CIC_WDG_ONLY
#if (RA_EXTCIC_STATE_CHECK == TRUE)
static boolean RA_WdgCIC_SwitchOffPathTest(void);
#endif /*(RA_EXTCIC_STATE_CHECK == TRUE) */
#if (RA_EXTCIC_SECCURESPI_CHECK == TRUE) 
static boolean RA_WdgCIC_SecureSPI(void);
static boolean RA_SafeTLibMain_CICSecureSPI_Task(void);
#endif /* (RA_EXTCIC_SECCURESPI_CHECK == TRUE)*/
static boolean RA_WdgCIC_WaitForNR(void);
static boolean RA_WdgCIC_Activate(void);
static boolean RA_SafeTLibMain_ExtWdgSwitchOffTst_Task(void);
static boolean RA_SafeTLibMain_ExtWdgCICInitChk_Task(void);	  
#endif /* SWDG_EXT_CIC_WDG_ONLY */

#ifdef SWDG_EXT_TLF_WDG_ONLY
#if (SWDG_EXT_TLF_STATE_CHECK_ENABLED == TRUE)
static boolean RA_WdgTLF_SwitchOffPathTest(void);
#endif  /* (SWDG_EXT_TLF_STATE_CHECK_ENABLED == TRUE) */
static boolean RA_SafeTLibMain_ExtWdgSwitchOffTst_Task(void);
#endif /* SWDG_EXT_TLF_WDG_ONLY */

#if !defined (SWDG_EXT_TLF_WDG_ONLY) && \
    !defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG)
static boolean RA_SafeTLibMain_WdgActivate_Task(void);
#endif /* !defined (SWDG_EXT_TLF_WDG_ONLY) && \
          !defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG) */
#endif /* (IFX_MCAL_USED == STD_OFF) */
static void RA_PostRun(void);
void RA_DisableCyclicTest(void);
void RA_Run(void);
void SafeTLib_MainTask_Master_Runtime(void);
#endif /* (SL_RUNTIME_TESTS == TRUE) */
static void RA_InitClock(uint32 fPLL);
static void RA_SpecificCoreToggleLed(uint32 cycle,uint32 interval,uint32 lednum);
static void RA_RefAppInit(uint8 CacheMpuCfg);
#if ( MCAL_NO_OF_CORES > 1U ) 
static void RA_EnterIdleMode(uint32 CoreId);
static void RA_ExitIdleMode(uint32 CoreId);
void SAFET_core1_RunTimeTest(void);
#if ( MCAL_NO_OF_CORES == 3U )
void SAFET_core2_RunTimeTest(void);
#endif /* ( MCAL_NO_OF_CORES == 3U ) */
#endif /* ( MCAL_NO_OF_CORES > 1U )*/

/*test functions: sram test code */
static Ifx_MC* SramEccErr_lGetMc
(
  const uint8 MemIdx
);
#define IFX_APPL_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/******************************************************************************
**                        Local object definitions                            *
******************************************************************************/

#define IFX_APPL_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
#include "Ifx_MemMap.h"
static uint32 LedToggleMask  = 0U;       /* LED Toggle mask */
volatile uint32 CycleCount = 0U;  /* Number of system ticks since main loop started */
#if ( MCAL_NO_OF_CORES > 1U )
static volatile uint32 CycleCountSlaveCore1 = 0U;  
#if ( MCAL_NO_OF_CORES == 3U )
static volatile uint32 CycleCountSlaveCore2 = 0U; 
#endif /* ( MCAL_NO_OF_CORES == 3U )*/
#endif /* ( MCAL_NO_OF_CORES > 1U )*/
static uint32 TOGGLE_MASK_LED1 = 0U;
static uint32 TOGGLE_MASK_LED2 = 0U;
/* LED toggle counter */
static uint32 ToggleCount    = 0U;

#if (IFX_MCAL_USED == STD_OFF)
#if(SL_RUNTIME_TESTS == TRUE)
static uint32 CycleMax       = 0U;        /* max. number of cycles to run, 0 = run forever */
static volatile uint32 TimerFlag = 0U;   /* timer ticks, one tick is one DTI */
#if ( MCAL_NO_OF_CORES > 1U )
static volatile uint32 RA_LoopCount = 1U ;
#endif
#endif /* (SL_RUNTIME_TESTS == TRUE) */
#endif /* (IFX_MCAL_USED == STD_OFF) */
#define IFX_APPL_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_APPL_START_SEC_VAR_8BIT_ASIL_B
#include "Ifx_MemMap.h"
static volatile uint8  RA_gFlagCore0 ;
static volatile uint8  RA_gFlagCore1 ;
static volatile uint8  RA_gFlagCore2 ;
static volatile uint8  RA_Core0Wait ;
static volatile uint8  RA_Core1Wait ;
static volatile uint8  RA_Core2Wait ;
static volatile uint8  Core1_SwitchRunPhase;
static volatile uint8  Core2_SwitchRunPhase; 
#if(SL_RUNTIME_TESTS == TRUE)
#if ( MCAL_NO_OF_CORES > 1U )
static volatile uint8 RA_RunTime_State_SlaveCore1 ;
#if ( MCAL_NO_OF_CORES == 3U )
static volatile uint8 RA_RunTime_State_SlaveCore2 ;
#endif /* ( MCAL_NO_OF_CORES == 3U ) */
#endif  /* MCAL_NO_OF_CORES > 1U */
#if defined (SWDG_EXT_TLF_WDG_ONLY) || \
	    defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG)
/* Counter for failed TLF requests */
 static uint8            RA_JobFailedCnt;
#endif
#ifdef SWDG_EXT_CIC_WDG_ONLY
/* Counter for failed CIC requests */
 static uint8            RA_JobFailedCnt;
#endif  /* SWDG_EXT_CIC_WDG_ONLY */
#endif /* (SL_RUNTIME_TESTS == TRUE) */
#define IFX_APPL_STOP_SEC_VAR_8BIT_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_APPL_START_SEC_VAR_NONZERO_INIT_8BIT_ASIL_B
#include "Ifx_MemMap.h"
uint8 RA_CoreId2CfgSetIdx[MCAL_NO_OF_CORES] = {0};
#if(SL_RUNTIME_TESTS == TRUE)
#ifdef SWDG_EXT_CIC_WDG_ONLY
/* This is used for Cic state check verification */
 boolean RA_Cic_StateCheck_Over   =  FALSE;
#endif  /* SWDG_EXT_CIC_WDG_ONLY */
static uint8            DT_Slice = RA_DTI_SLICES-1u;
 /* Task is runnning  */
static boolean          TaskActive = FALSE;  
#endif /* (SL_RUNTIME_TESTS == TRUE) */
#define IFX_APPL_STOP_SEC_VAR_NONZERO_INIT_8BIT_ASIL_B
#include "Ifx_MemMap.h"
#if((IFX_MCAL_USED == STD_ON) && ((CHIP_ID == 26U) || (CHIP_ID == 29U)))
extern volatile uint32 StlEnCyle_Tst;
extern volatile uint32 StlDbCyle_Tst;
#endif
/******************************************************************************
**                         Function definitions                               *
******************************************************************************/
#define IFX_APPL_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*----------------------------------------------------------------------------*/

#if(SL_RUNTIME_TESTS == TRUE)
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void RA_RunTimeTest()                            **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function, 
**                    Initializes SMU interrupts;
**                    Configures TOM channel to get transmission interrupt every 100us;
**                    DMA and Interrupt and configuration of external watchdog(s);
**                    
**                    Set up the diagnostic time interval using STM0 timer interrupt;
**                    Initializes watchdog(s) for runtime;
**                    Activate watchdog(s) for runtime;
**                    Execute Runtime tests and servicing of the watchdogs;
*********************************************************************************/  
static void RA_RunTimeTest()
{
    uint8 CoreId;
    CoreId = ((uint8)MFCR(CPU_CORE_ID) & (uint8)0x3U);
    if(SL_MASTER_CORE_ID == CoreId)
    { 
        /* Initialise SMU interupts */
        SMU_Setupinterrupt();
        #ifndef SWDG_INT_WDG_ONLY
        #ifdef SWDG_EXT_CIC_WDG_ONLY
        /*Configure TOM channel to get transmission interrupt every 100us */
        SafeWdgExt_Config_Timer();  
        #endif /* SWDG_EXT_CIC_WDG_ONLY */
        SafeWdgExt_Config_DMA();
        SafeWdgExt_Config_Irq();
        #endif  /* SWDG_INT_WDG_ONLY */

        #if (IFX_MCAL_USED == STD_OFF)  
        ENABLE();
        IrqStm_Init();
        
//        print_f("\n SafeTlib: Starting Run-time phase...");
        
        /* Setup the Diagnostic Time Interval */
        RA_SetupDTI();
        {
            /* counter for init cycles */
            /* To avoid compiler warning with Tasking 5.0, volatile qualifier 
               is used. */
            #if defined (SWDG_EXT_CIC_WDG_ONLY)  
            volatile uint16  WdgInitChkTaskCycles;
            #if (RA_EXTCIC_SECCURESPI_CHECK == TRUE) 
            volatile uint16  WdgTaskSecSPICycles;
            #endif /* #if (RA_EXTCIC_SECCURESPI_CHECK == TRUE)  */
            #endif /* #if defined (SWDG_EXT_CIC_WDG_ONLY) */

            #if defined (SWDG_EXT_CIC_WDG_ONLY) || defined (SWDG_INT_WDG_ONLY)  
            volatile uint16  WdgActivateTaskCycles;
            #endif
            #ifdef   SWDG_EXT_CIC_WDG_ONLY

            /* To avoid compiler warning with Tasking 5.0, volatile qualifier is used. 
            the Switchoff path test option can be disabled */
            volatile uint16  WdgSwitchOffTaskCycles;
            uint16  WdgExtCicPausecycles;
            #endif /* SWDG_EXT_CIC_WDG_ONLY */
            
            #ifdef SWDG_EXT_TLF_WDG_ONLY
            #if (SWDG_EXT_TLF_STATE_CHECK_ENABLED == TRUE)
            uint16  WdgSwitchOffTaskCycles;

              /* Task1 executes TLF state check verification use case if enabled */
              WdgSwitchOffTaskCycles = 0u;
              do
              {
                  RA_WasteTime();         /* wait for next Tick */
                  if (WdgSwitchOffTaskCycles++ > RA_WDG_SWITCHOFFTASK_CYCLES_MAX)
                  {
                      AppCbk_ErrorHandler(APLCBK_WDG_SWITCHOFFTASK_FAIL);
                  }
              } while (RA_SafeTLibMain_ExtWdgSwitchOffTst_Task() == FALSE);

              DT_Slice = RA_DTI_SLICES - 1u;
            #endif  /* #if (SWDG_EXT_TLF_STATE_CHECK_ENABLED == TRUE) */
            #endif /* #ifdef SWDG_EXT_TLF_WDG_ONLY */

            #ifdef SWDG_EXT_CIC_WDG_ONLY
            /*
             * This task is to ensure Watchdog is in proper initialized state
             * For CIC: The task ensures that Cic is in NR state. Ext CIC watchdog 
             * initialisation cycle to ensure that CIC has finally reached the 
             * "Not Ready" state. If required a Reset is sent to the CIC implicitly.
             */  
            WdgInitChkTaskCycles = 0u;
            do 
            {   
                RA_WasteTime();        /* wait for next Tick */
                if (WdgInitChkTaskCycles++ > RA_WDG_INITCHKTASK_CYCLES_MAX)
                {
                    AppCbk_ErrorHandler(APLCBK_WDG_INITCHKTASK_FAIL);           
                }
            } while (RA_SafeTLibMain_ExtWdgCICInitChk_Task() == FALSE);


               
            #if (RA_EXTCIC_SECCURESPI_CHECK == TRUE) 
            /*  
             * This task is used for secure spi mode
            * Before entering into secureSPI mode, CIC should be either in
            * NR state or Disable state
            */

            DT_Slice = RA_DTI_SLICES-1u;
            WdgTaskSecSPICycles = 0u;
            do 
            {  
                RA_WasteTime();         /* wait for next Tick */
                if (WdgTaskSecSPICycles++ > RA_CICWDG_TASK_SECSPI_CYCLES_MAX)
                {
                    AppCbk_ErrorHandler(APLCBK_CIC_SECSPI_FAIL);           
                }
            } while (RA_SafeTLibMain_CICSecureSPI_Task() == FALSE);
            /* 
            * The application should call Init again after exiting from SecureSPI 
            * mode 
            */	  

            /* initialise watchdog for runtime */
            SafeWdgM_Init(0);      
            #endif  /*  #if (RA_EXTCIC_SECCURESPI_CHECK == TRUE) */

            /* This Task executes state check verification use case if enabled  for the configured 
             external CIC61508 watchdog. It first checks CIC Init status, Once initialization is complete, 
             it executes SwtichoffPath Test
             */
             WdgSwitchOffTaskCycles = 0u;
             do 
             {  
                RA_WasteTime();         /* wait for next Tick */
                if (WdgSwitchOffTaskCycles++ > RA_WDG_SWITCHOFFTASK_CYCLES_MAX)
                {
                  AppCbk_ErrorHandler(APLCBK_WDG_SWITCHOFFTASK_FAIL);           
                }
             } while (RA_SafeTLibMain_ExtWdgSwitchOffTst_Task() == FALSE);

             #if (RA_EXTCIC_STATE_CHECK == TRUE) 
             /* 
             The Cic state check verification use case is complete and DeInit is called 
             to reset Cic to bring it back to NR state. 
             This pause simulate a delay after CIC reset request has been issued by call to
                  DeInit. It should at least provide the time required to
             process reset request (4 ms). Time delta between call to SafeTLib_MainTask_Master_Init2 
             can be as long as required. 
             */
             WdgExtCicPausecycles = 0u;
             while (WdgExtCicPausecycles++ < RA_EXTCIC_PAUSE1_CYCLES)
             {
                RA_WasteTime();         /* wait for next Tick */  
             }

             /* initialise watchdog for runtime */
             SafeWdgM_Init(0); 
             DT_Slice = RA_DTI_SLICES-1u;

             #endif  /* RA_EXTCIC_STATE_CHECK == TRUE */
             #endif  /* SWDG_EXT_CIC_WDG_ONLY */

             #if defined (SWDG_EXT_CIC_WDG_ONLY)
             #if ((RA_EXTCIC_SECCURESPI_CHECK == TRUE) || (RA_EXTCIC_STATE_CHECK == TRUE)) 
             /*
               * This task is to ensure Watchdog is in proper initialized state
              * For CIC: The task ensures that Cic is in NR state. Ext CIC watchdog 
              * initialisation cycle to ensure that CIC has finally reached the 
              * "Not Ready" state. If required a Reset is sent to the CIC implicitly.
              *
              * For Internal Watchdog: No action done. This is a dummy task
              */ 

             WdgInitChkTaskCycles = 0u;
             do 
             {  
                RA_WasteTime();        /* wait for next Tick */
                if (WdgInitChkTaskCycles++ > RA_WDG_INITCHKTASK_CYCLES_MAX)
                {
                  AppCbk_ErrorHandler(APLCBK_WDG_INITCHKTASK_FAIL);           
                }
             } while (RA_SafeTLibMain_ExtWdgCICInitChk_Task() == FALSE);
             #endif /*#if ((RA_EXTCIC_SECCURESPI_CHECK == TRUE) || (RA_EXTCIC_STATE_CHECK == TRUE)) */
             #endif /* #if defined (SWDG_EXT_CIC_WDG_ONLY)*/ 
             /* 
             * This pause simulate a delay after Not ready state is reached 
             * before applictaion switches over to cyclic run phase 
             */
             #ifdef SWDG_EXT_CIC_WDG_ONLY
             WdgExtCicPausecycles = 0u;
             while (WdgExtCicPausecycles++ < RA_EXTCIC_PAUSE2_CYCLES)
             {
                RA_WasteTime();         /* wait for next Tick */
             }
             #endif /* SWDG_EXT_CIC_WDG_ONLY */
             #if !defined (SWDG_EXT_TLF_WDG_ONLY) && \
                !defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG)
             /*
              * This task activate the Configured watchdog (External CIC or Internal watchdog)
             */
             WdgActivateTaskCycles = 0u;
             do 
             {  
                RA_WasteTime();         /* wait for next Tick */
                if (WdgActivateTaskCycles++ > RA_WDG_ACTIVATETASK_CYCLES_MAX)
                {
                  AppCbk_ErrorHandler(APLCBK_WDG_ACTIVATETASK_FAIL);           
                }
             } while (RA_SafeTLibMain_WdgActivate_Task() == FALSE);

             #endif /* !defined (SWDG_EXT_TLF_WDG_ONLY) && \
                      !defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG) */
        }   

        /*  
         *  In this task, watchdog is in active state and should be serviced 
         *  periodically it goes into safe state
        */
        while (RA_Cycle(CycleCount) == TRUE)
        {
          /* wait for next Tick */
          RA_WasteTime();
          SafeTLib_MainTask_Master_Runtime();      
        }
        RA_DisableCyclicTest();
        #endif   /* (IFX_MCAL_USED == STD_OFF) */ 
    }
} 
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void SafeTLib_MainTask_Master_Runtime()                 **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function Executes Run time tests of SafeTlib,
**                    Servicing of the watchdogs
*********************************************************************************/
void SafeTLib_MainTask_Master_Runtime()
{
  #ifdef SWDG_EXT_CIC_WDG_ONLY
  SafeWdgIf_ResultType JobStatus = SWDG_JOB_ACCEPTED;
	#endif

	#if defined (SWDG_EXT_TLF_WDG_ONLY) || \
	    defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG)
  SafeWdgIf_ResultType JobStatus = SWDG_JOB_ACCEPTED;
  #endif

	#ifdef SWDG_INT_WDG_ONLY
  #if(IFX_MCAL_USED == STD_ON)
	SafeWdgIf_StateType WdgState;	
  #endif
	#endif

	#if defined (SWDG_EXT_TLF_WDG_ONLY) || \
	    defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG)
	static boolean ActivateCalled = FALSE;
	SafeWdgIf_StateType WdgState;
	#endif /* defined (SWDG_EXT_TLF_WDG_ONLY) || \
            defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG) */

  /* Start cyclic execution */
  CycleCount++;               /* Update global tick number */

 
  #ifndef SWDG_EXT_CIC_WDG_ONLY
	#ifdef SWDG_INT_WDG_ONLY
  #if(IFX_MCAL_USED == STD_ON)
  /*Activate Internal watchdog*/
  {
//	 WdgState = SafeWdgM_GetState();
//	 if (WdgState.IntWdgState != (uint16)SAFEWDGINT_ACTIVE)
//	 {
//		SafeWdgM_Activate(); /* Activate internal watchdog only one time */
//	 }
  } 
  #endif  /* (IFX_MCAL_USED == STD_ON) */

  TaskActive = TRUE;    
  /* switch to next slice */
  DT_Slice = (DT_Slice+1) % RA_DTI_SLICES;

  /* synchronized execution of Test execution and CIC requests */
  switch (DT_Slice)
  {
   case DTI_TESTEXEC_SLICE:
     {
      RA_Run();                    /* Execute the Runtime Tests */
     }
     break;

   case DTI_SERVICE_SLICE:
     {
       RA_WdgService();                /* Service watchdog */
     }
     break;      

   default:
     break;
  }
  TaskActive = FALSE; 
	#endif	/* SWDG_INT_WDG_ONLY */ 

  #if defined (SWDG_EXT_TLF_WDG_ONLY) || \
      defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG)

	SafeWdgExtTlf_MainFunction();

	/* Activate External watchdog TLF Asynchronously in multiple steps */
	WdgState = SafeWdgM_GetState();
	if((WdgState.ExtWdgState == SAFEWDG_TLF_INIT) && (ActivateCalled == FALSE))
	{
		SafeWdgM_Activate();
    ActivateCalled = TRUE;
	}

  JobStatus = SafeWdgM_GetJobResult();
  if (JobStatus == SWDG_JOB_SUCCESS)
  {
      /* Previous job successful executed / accepted */
      if (RA_JobFailedCnt > 0)
      {
          /* Debounce failed Job request */
          RA_JobFailedCnt--;
      }
  }
  else if (JobStatus != SWDG_JOB_ACCEPTED)
  {
      /* Check failed Jobs */
      RA_JobFailedCnt++;
      if (RA_JobFailedCnt > RA_JOBFAIL_MAX)
      {
          /* Max number of successive failed jobs exceeded */
          AppCbk_ErrorHandler(APLCBK_TLF_MAXJOBS_FAIL);
      }
  }

  if (JobStatus != SWDG_JOB_ACCEPTED)
  {
      TaskActive = TRUE;    
  /* switch to next slice */
  DT_Slice = (DT_Slice+1) % RA_DTI_SLICES;
  /* synchronized execution of Test execution and CIC requests */
  switch (DT_Slice)
  {
      case DTI_TESTEXEC_SLICE:
      {
         SafeWdgExtTlf_UcHandler_SetTlfInfo(); /* Clear error and status flags*/
         RA_Run();                             /* Execute the Runtime Tests */
      }
      break;

      case DTI_SERVICE_SLICE:
      {
        #if (SWDG_EXT_TLF_SEQTEST_ENABLED == TRUE)
        SafeWdgExtTlf_UcHandler_TempSeqTest(); /* Inject errors */
        #endif /* (SWDG_EXT_TLF_SEQTEST_ENABLED == TRUE) */
        RA_WdgService();                      /* Service watchdog  */
      }

      break;      
      

      case DTI_INFO_SLICE: /*Info slice not required for internal wdg*/
      {
        SafeWdgIf_GetWdgInfo();
      }
      break;

      case DTI_USRREQ_SLICE: /* Info slice to get watchdog data */
      {
        SafeWdgExtTlf_UcHandler_GetTlfInfo(); /* Read error and status flags */
      }
      break;
      
      default:
      break;
  }
  TaskActive = FALSE; 
  } 
  #endif /* defined (SWDG_EXT_TLF_WDG_ONLY) || defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG) */
  #endif  /* ifndef SWDG_EXT_CIC_WDG_ONLY */
      
  #ifdef SWDG_EXT_CIC_WDG_ONLY
   
  TaskActive = TRUE;

    /* call main function on entry every Tick to update asynch transmit request results*/
  SafeWdgExtCic_MainFunction();
  JobStatus = SafeWdgM_GetJobResult();
  
  if(JobStatus == SWDG_JOB_SUCCESS)
  {
      /* previous job successful executed */
      if (RA_JobFailedCnt > 0u)
      {
          /* de-bounce failed Job request */
          RA_JobFailedCnt = 0u;
      }
  }
  else 
  {
      /* Job status accepted or check failed Jobs */
      RA_JobFailedCnt++;
      if (RA_JobFailedCnt > RA_JOBFAIL_MAX)
      {
          /* max number of successive failed jobs exceeded */
          AppCbk_ErrorHandler(APLCBK_CIC_MAXJOBS_FAIL);
      }
  }

  /* switch to next slice */
  DT_Slice = (DT_Slice+1) % RA_DTI_SLICES;

  /* synchronized execution of Test execution and CIC requests */
  switch (DT_Slice)
  {
    case DTI_TESTEXEC_SLICE:
  /* Execute the Runtime Tests */
     RA_Run();                    
      break;

    case DTI_SERVICE_SLICE:  
    #if (RA_EXTCIC_TEMPSEQTEST_ENABLED == TRUE)
      /* Temporal sequencer test for CIC*/
      SafeWdgExtCic_UcHandler_TempSeqTest();  
    #endif  
      /* Service watchdog  */
      RA_WdgService();                       
      break;

    case DTI_USRREQ1_SLICE:
      SafeWdgExtCic_UcHandler_URRun1();     /* optional user request set 1 */
      break;

    case DTI_INFO_SLICE:
      /* mandatory Get CIC info request */    
      SafeWdgM_GetWdgInfo(); 
      break;

    case DTI_USRREQ2_SLICE:
    #if(IFX_MCAL_USED == STD_OFF)
      SafeWdgExtCic_UcHandler_URRun2();   /* optional user request set 2 */
    #else
    { 
      SafeWdgIf_StateType CicState;
      
      CicState = SafeWdgM_GetState();
      if (CicState.ExtWdgState == SAFEWDG_CIC_READY)
      {
          SafeWdgM_Activate();   /* Activate cic if in ready state */
      } 
    }
    #endif
      break;

   default:
      break;
  }
  TaskActive = FALSE;  

  #endif  /* SWDG_EXT_CIC_WDG_ONLY */      

}/* void SafeTLib_MainTask_Master_Runtime() */

/*----------------------------------------------------------------------------*/
/*
 * Run Task1 for the configured watchdog
 */
#if defined(SWDG_EXT_CIC_WDG_ONLY) || \
    defined(SWDG_EXT_TLF_WDG_ONLY)
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : boolean RA_SafeTLibMain_ExtWdgSwitchOffTst_Task(void)   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function Executes,
**                    CIC state check verification use case;
**                    TLF state check verification use case.
******************************************************************************/
boolean RA_SafeTLibMain_ExtWdgSwitchOffTst_Task(void)
{
  boolean Result = FALSE;

   #ifdef SWDG_EXT_CIC_WDG_ONLY

      #if (RA_EXTCIC_STATE_CHECK == TRUE)
      /* This task runs CIC state check verification usecase.
       * Ext CIC watchdog first initialisation cycle allows to cycle through all CIC states
       * until disabled state for safety path check.
       * Finally a Reset request is sent to the CIC.
       * CIC will be left in "Wait for reset" if state check was requested 
       * This init cycle might be omitted if no state check is required.
       */
      Result = RA_WdgCIC_SwitchOffPathTest();
     #else 
      Result = TRUE;
     #endif  /* (RA_EXTCIC_STATE_CHECK == TRUE) */
   #endif /* SWDG_EXT_CIC_WDG_ONLY */
   
  #ifdef SWDG_EXT_TLF_WDG_ONLY
    #if (SWDG_EXT_TLF_STATE_CHECK_ENABLED == TRUE)
      /* This task runs TLF state check verification use case.
       * This init cycle might be omitted if no state check is required.
       */
      Result = RA_WdgTLF_SwitchOffPathTest();
    #else
      Result = TRUE;
    #endif  /* #if (SWDG_EXT_TLF_STATE_CHECK_ENABLED == TRUE) */
  #endif /* SWDG_EXT_TLF_WDG_ONLY */

  #ifdef SWDG_INT_WDG_ONLY
  Result = TRUE;
  #endif  /* SWDG_INT_WDG_ONLY */
   return Result;
}
#endif /* defined(SWDG_EXT_CIC_WDG_ONLY) || \
          defined(SWDG_EXT_TLF_WDG_ONLY) */


 #ifdef SWDG_EXT_CIC_WDG_ONLY
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : boolean RA_SafeTLibMain_ExtWdgCICInitChk_Task(void)     **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function Executes RA_WdgCIC_WaitForNR()function
*******************************************************************************/
boolean RA_SafeTLibMain_ExtWdgCICInitChk_Task(void)
{
  boolean Result = FALSE;
  /*
  * This task ensures that Cic is in NR state 
  * after init is called
  */ 
  Result = RA_WdgCIC_WaitForNR();
  return Result;
}
#endif /*  #ifdef SWDG_EXT_CIC_WDG_ONLY */

#if !defined (SWDG_EXT_TLF_WDG_ONLY) && \
    !defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG)
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : boolean RA_SafeTLibMain_WdgActivate_Task(void)          **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function activates watchdog(s)
*******************************************************************************/
boolean RA_SafeTLibMain_WdgActivate_Task(void)
{
  boolean Result = FALSE;

   #ifdef SWDG_EXT_CIC_WDG_ONLY
   /*
    *  This tasks moves Cic in active state
  */
   Result = RA_WdgCIC_Activate();
   #endif /* SWDG_EXT_CIC_WDG_ONLY */
   #ifndef SWDG_EXT_CIC_WDG_ONLY
   #ifdef SWDG_INT_WDG_ONLY
   /*Activate Internal watchdog*/
//   SafeWdgM_Activate();
   #endif /* SWDG_INT_WDG_ONLY */
   Result = TRUE;   
   #endif  /* SWDG_EXT_CIC_WDG_ONLY */
   return Result;
}
#endif /* !defined (SWDG_EXT_TLF_WDG_ONLY) && \
          !defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG) */
#ifdef SWDG_EXT_CIC_WDG_ONLY
#if (RA_EXTCIC_SECCURESPI_CHECK == TRUE)
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : boolean RA_SafeTLibMain_CICSecureSPI_Task(void)         **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function run CIC SecureSPI Task
*******************************************************************************/   
boolean RA_SafeTLibMain_CICSecureSPI_Task(void)
{
  volatile boolean Result = FALSE;
  #ifdef SWDG_EXT_CIC_WDG_ONLY
  /*
  *  This tasks moves Cic in active state
  */
  Result = RA_WdgCIC_SecureSPI();
  #endif /* SWDG_EXT_CIC_WDG_ONLY */   
  return Result;
}
#endif  
#endif
/* Main function for SafeTLib Master to be called every Tick 
   Used with external CIC safety watchdog during INIT1 phase
   used for executing the optional safety path check
*/
#ifdef SWDG_EXT_CIC_WDG_ONLY
#if (RA_EXTCIC_SECCURESPI_CHECK == TRUE) 
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : boolean RA_WdgCIC_SecureSPI(void)                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function runs CIC SecureSPI use case
*******************************************************************************/
boolean RA_WdgCIC_SecureSPI(void)
{
  static volatile boolean entersecspi = FALSE;
  static volatile boolean checkcompletestatus = FALSE;
  SafeWdgIf_ResultType JobStatus = SWDG_JOB_ACCEPTED;
  TaskActive = TRUE;
  /* call main function on entry every Tick to update async transmit request results*/ 
  SafeWdgExtCic_MainFunction();
  JobStatus = SafeWdgM_GetJobResult();
  if(JobStatus == SWDG_JOB_SUCCESS)
  {
    /* previous job successful executed  */
    if (RA_JobFailedCnt > 0)
    {
      /* debounce failed Job request */
       RA_JobFailedCnt = 0u;
    }
  }
  else 
  {
    /* Job status accepted or check failed Jobs */
    RA_JobFailedCnt++;
    if (RA_JobFailedCnt > RA_JOBFAIL_MAX)
    {
      /* max number of successive failed jobs exceeded */
      AppCbk_ErrorHandler(APLCBK_CIC_MAXJOBS_FAIL);           
    }
  }  
  DT_Slice = (DT_Slice+1) % RA_DTI_SLICES;
  switch (DT_Slice)
  {
      case DTI_SECSPI_USRREQ1_SLICE:
          if(checkcompletestatus == FALSE)
          {
             /* Send first command to enter into Secure SPI mode */
            SafeWdgExtCic_UcHandler_UREntSecCmd1();    
          }
          else
          {
            if(checkcompletestatus == TRUE)
            {
            entersecspi = TRUE;
            } 
          }   
                      
          break;
  
      case DTI_SECSPI_USRREQ2_SLICE:
          /* Send next two command and dummy command to enter 
           * into secure spi mode 
           */
          SafeWdgExtCic_UcHandler_UREntSecCmd2();              
          break;
  
      case DTI_SECSPI_USRREQ3_SLICE:
          /* Send User Request to read data in secure spi mode */
          SafeWdgExtCic_UcHandler_ReadInSecSpi1();                              
          break;
  
      case DTI_SECSPI_USRREQ4_SLICE:   
          /* Send User Request to read data in secure spi mode */   
          SafeWdgExtCic_UcHandler_ReadInSecSpi2();
          break;
  
      case DTI_SECSPI_USRREQ5_SLICE:
          SafeWdgExtCic_UcHandler_URSecSpiExit(); 
          checkcompletestatus = TRUE;           
          break;
  
      default:
          break;
  }

  TaskActive = FALSE;
  return (entersecspi);
} 

  #endif /* #if (RA_EXTCIC_SECCURESPI_CHECK == TRUE)  */
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : boolean RA_WdgCIC_SwitchOffPathTest(void)               **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function verifies the working of CIC state machine
*******************************************************************************/  
boolean RA_WdgCIC_SwitchOffPathTest(void)
{

 /* To avoid compiler warning with Tasking 5.0, volatile qualifier 
    is used 
 */   
    volatile boolean CICResetRequested = FALSE;
    SafeWdgIf_StateType CicState;
    SafeWdgIf_ResultType JobStatus = SWDG_JOB_ACCEPTED;
  
  
    TaskActive = TRUE;

    /* call main function on entry every Tick to update asynch transmit request results*/
    
  SafeWdgExtCic_MainFunction();
  CicState = SafeWdgM_GetState();
  JobStatus = SafeWdgM_GetJobResult();

    if (CICResetRequested != TRUE)
    {
        if ((CicState.ExtWdgState == SAFEWDG_CIC_UNKNOWN) && (RA_Cic_StateCheckDeInitCalled == FALSE))
        {
          /*  GetJobResult != accepted or success */
            if((JobStatus != SWDG_JOB_ACCEPTED) && (JobStatus != SWDG_JOB_SUCCESS))
            {
                /* init Job failed, no communication possible */
                AppCbk_ErrorHandler(APLCBK_SWDGIF_INIT_FAIL);           
            }
        }
        else
        {           
            DT_Slice = (DT_Slice+1) % RA_DTI_SLICES;

            switch (DT_Slice)
            {
            case DTI_TESTEXEC_SLICE:
               RA_Run();             /* Execute the Runtime Tests */
                break;

            case DTI_SERVICE_SLICE:  
               RA_WdgService();         /* Service watchdog  */         
                break;

            case DTI_USRREQ1_SLICE:
                if (CicState.ExtWdgState == SAFEWDG_CIC_READY)
                {
                    SafeWdgM_Activate();  /* Activate cic if in ready state */
                }
                 RA_Cic_StateCheckDeInitCalled = SafeWdgExtCic_UcHandler_VerifyCICStates();
                break;

            case DTI_INFO_SLICE:
                 if(RA_Cic_StateCheckDeInitCalled == FALSE)
                 {
                   /* mandatory Get CIC info request */
                   SafeWdgM_GetWdgInfo(); 
                 }
                 else
                 {
                    CICResetRequested = TRUE; 
                 }                   
                break;

            case DTI_USRREQ2_SLICE:
                break;

            default:
                break;
            }
        }   
    }
    TaskActive = FALSE;
    return (CICResetRequested);
} 

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : boolean RA_WdgCIC_WaitForNR(void)                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Main function for SafeTLib Master to be called every Tick 
**                    Used with external CIC safety watchdog during INIT2 phase
**                    used to ensure Not Ready state after Reset / CIC Reset
*******************************************************************************/
boolean RA_WdgCIC_WaitForNR(void)
{
    boolean NotReady = FALSE;
    SafeWdgIf_StateType CicState;
    SafeWdgIf_ResultType JobStatus = SWDG_JOB_ACCEPTED;
  

    TaskActive = TRUE;

    /* call main function on entry every Tick to update asynch transmit request results*/

  
  SafeWdgExtCic_MainFunction();
  CicState = SafeWdgM_GetState();
  
  JobStatus = SafeWdgM_GetJobResult();
  
    if (CicState.ExtWdgState == SAFEWDG_CIC_NR)
    {
        NotReady = TRUE;       /* Not ready state reached */
    }
    else
    {
        
      if((JobStatus != SWDG_JOB_ACCEPTED) && (JobStatus != SWDG_JOB_SUCCESS))
        {
            /* init Job failed, no communication possible */
            AppCbk_ErrorHandler(APLCBK_SWDGIF_INIT_FAIL);           
        }
    }
    TaskActive = FALSE;
    return (NotReady);
} 

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : boolean RA_WdgCIC_Activate(void)                        **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Main function for SafeTLib Master to be called every Tick 
**                    Used with external CIC safety watchdog during INIT3 phase
**                    Moves CIC from NotReady to Active state.
**                    After calling this function the CIC must be serviced within the expected
**                    watchdog time interval by calling cyclically the function 
**                    SafeTLib_MainTask_Master_Runtime
*******************************************************************************/
boolean RA_WdgCIC_Activate(void)
{
    boolean activated = FALSE;
    SafeWdgIf_StateType CicState;
    /*SafeWdgIf_ResultType JobStatus;*/
    SafeWdgIf_ResultType JobStatus = SWDG_JOB_ACCEPTED;


    TaskActive = TRUE;

    /* call main function on entry every Tick to update async transmit request results*/ 
  
  SafeWdgExtCic_MainFunction();
  CicState = SafeWdgM_GetState();
  
  JobStatus = SafeWdgM_GetJobResult();
  

  if(JobStatus == SWDG_JOB_SUCCESS)
  /*if (JobStatus == E_OK)*/
    {
        /* previous job successful executed  */
        if (RA_JobFailedCnt > 0)
        {
            /* debounce failed Job request */
             RA_JobFailedCnt = 0u;
        }
    }
    else 
    {
        /* Job status accepted or check failed Jobs */
        RA_JobFailedCnt++;
        if (RA_JobFailedCnt > RA_JOBFAIL_MAX)
        {
            /* max number of successive failed jobs exceeded */
            AppCbk_ErrorHandler(APLCBK_CIC_MAXJOBS_FAIL);           
        }
    }  

    if (CicState.ExtWdgState == SAFEWDG_CIC_ACTIVE)
    {
        activated = TRUE;       /* initialisation is finished */
    }
    else
    {
        DT_Slice = (DT_Slice+1) % RA_DTI_SLICES;

        switch (DT_Slice)
        {
        case DTI_TESTEXEC_SLICE:
           RA_Run();              /* Execute the Runtime Tests */
            break;

        case DTI_SERVICE_SLICE:
            RA_WdgService();         /* Service watchdog  */
            break;

        case DTI_USRREQ1_SLICE:
            if (CicState.ExtWdgState == SAFEWDG_CIC_READY)
            {
                SafeWdgM_Activate();   /* Activate cic if in ready state */
            }
            else
            {
                SafeWdgExtCic_UcHandler_URInit1();   /* optional user request set 1 */
            }
            break;

        case DTI_INFO_SLICE:
             /* mandatory Get CIC info request */
         SafeWdgM_GetWdgInfo();            
             break;

        case DTI_USRREQ2_SLICE:
            SafeWdgExtCic_UcHandler_URInit2();      /* optional user request set 2 */
            break;

        default:
            break;
        }
    }
    TaskActive = FALSE;
    return (activated);
} 

#endif /* SWDG_EXT_CIC_WDG_ONLY */

#ifdef SWDG_EXT_TLF_WDG_ONLY
#if (SWDG_EXT_TLF_STATE_CHECK_ENABLED == TRUE)

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : boolean RA_WdgTLF_SwitchOffPathTest(void)               **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : RA_WdgTLF_SwitchOffPathTest:
**                    Executes switch off path test on the TLF35584 and inject FWD and WWD errors
**                    to check for correct error counter increment.
**                    Test sequence:
**                     INIT
**                     Activate -> NORMAL
**                     ABIST Test -> WAKE
**                     Inject Error FWD -> WAKE
**                     Inject Error WWD -> WAKE
**                     Activate -> NORMAL
*******************************************************************************/
boolean RA_WdgTLF_SwitchOffPathTest(void)
{
  static boolean        SwOffActivateCalled = (boolean)FALSE;
  static boolean        InjectErrorDone     = (boolean)FALSE;
  static boolean        AbistDone           = (boolean)FALSE;
  boolean               WdgServiceReq       = (boolean)FALSE;

  SafeWdgIf_ResultType  JobStatus           = SWDG_JOB_ACCEPTED;
  SafeWdgIf_StateType   WdgState;

  SafeWdgExtTlf_MainFunction();

  /* Activate External watchdog TLF Asynchronously in multiple steps */
  WdgState = SafeWdgM_GetState();

  if ( WdgState.ExtWdgState == SAFEWDG_TLF_INIT )
  {
    if (SwOffActivateCalled == FALSE)
    {
      SafeWdgM_Activate();
      SwOffActivateCalled = TRUE;
    }
  }

  JobStatus = SafeWdgM_GetJobResult();
  if (JobStatus == SWDG_JOB_SUCCESS)
  {
    /* Previous job successful executed / accepted */
    if (RA_JobFailedCnt > 0)
    {
      /* Debounce failed Job request */
      RA_JobFailedCnt--;
    }
  }
  else if (JobStatus != SWDG_JOB_ACCEPTED)
  {
    /* Check failed Jobs */
    RA_JobFailedCnt++;
    if (RA_JobFailedCnt > RA_JOBFAIL_MAX)
    {
      /* Max number of successive failed jobs exceeded */
      AppCbk_ErrorHandler(APLCBK_TLF_MAXJOBS_FAIL);
    }
  }

  if (JobStatus != SWDG_JOB_ACCEPTED)
  {
    /* Switch to next slice */
    DT_Slice = (DT_Slice + 1) % RA_DTI_SLICES;
    /* Synchronized execution of Test execution and TLF requests */
    switch (DT_Slice)
    {
      case DTI_TESTEXEC_SLICE:
      {
        RA_Run();          /* Execute the Runtime Tests for proper signature*/
        AbistDone = SafeWdgExtTlf_UcHandler_Abist();   /* Exec ABIST Handler slice */
      }
      break;

      case DTI_SERVICE_SLICE:
      {
        InjectErrorDone = SafeWdgExtTlf_UcHandler_ErrInject(AbistDone,
                                                            &WdgServiceReq);
        if (WdgServiceReq == (boolean)TRUE)
        {
          RA_WdgService();
        }
      }
      break;

      case DTI_INFO_SLICE: /*Info slice not required for internal wdg*/
      {
        SafeWdgIf_GetWdgInfo();
      }
      break;

      default:
      {
        /* Execute ABIST Handler slice */
        AbistDone = SafeWdgExtTlf_UcHandler_Abist();
      }
      break;
    }
  }

  return (InjectErrorDone);
}

#endif /* (SWDG_EXT_TLF_STATE_CHECK_ENABLED == TRUE) */
#endif /* #ifdef SWDG_EXT_TLF_WDG_ONLY*/
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void RA_Run(void)                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function executes the run time tests of SafeTlib
*******************************************************************************/
void RA_Run(void)
{
#if ( MCAL_NO_OF_CORES > 1U )
  RA_RunTime_State_SlaveCore1 = RA_RUNTIME_PHASE_ACTIVE ;
#if ( MCAL_NO_OF_CORES == 3U )
  RA_RunTime_State_SlaveCore2 = RA_RUNTIME_PHASE_ACTIVE ;
#endif /* ( MCAL_NO_OF_CORES == 3U ) */
#endif /* ( MCAL_NO_OF_CORES > 1U ) */  

  /* Execute the Runtime Tests*/
  TstM_Run();



}
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void RA_SetupDTI(void)                                  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function Set up and start 
**                    the diagnostic test interval for runtime
*******************************************************************************/ 
void RA_SetupDTI(void)
{
  uint32 StmTicks, Result = E_NOT_OK;
	uint32 MemsToTest;
	uint8 LCount;
  Ifx_MC* Mc;  
  #ifndef SWDG_INT_WDG_ONLY
  SafeWdgExt_Config_Port();
  #endif
  MemsToTest = MEM_TO_TEST;
  /*test code to disable address error notifications */
  for (LCount = 0U; LCount < SRAMECCTST_MEMORY_COUNT_LOCAL; LCount++)
  {
   /* Check if memory testing is enabled */
   if ((MemsToTest &((uint32)1U << LCount)) > (uint32)0U)
   {
	Mc = SramEccErr_lGetMc(LCount);	
    Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT); 
    Mc->ECCD.B.AENE = 0U;
    Mcal_SetSafetyENDINIT_Timed(); 	
    }
  }		

  
  
	/* Switch SafeTlib phase of master core to SL_RUN : 
	This code snippet moved here to make Mcal and SafeTlib Integration works fine. 
	Previously it is called before RA_RunTimeTest() which is fine for Standalone SafeTlib but It will cause a problem while Integrating with Mcal.*/
	Result = Sl_SwitchTstPhase(SL_RUN);
	if(E_OK != Result)
	{
	  AppCbk_ErrorHandler(APLCBK_SL_SWITCH_PHASE_FAIL);
	}
  /* STM number of ticks for 1ms */

  StmTicks = Get_Fstm()/RA_DTI_FREQ;
  
  /* Slave cores wait for DTI cycle to begin */
  /* Wait for other cores to finish run-time tests */
#if ( MCAL_NO_OF_CORES > 1U )
  RA_RunTime_State_SlaveCore1 = RA_RUNTIME_PHASE_IDLE;
#if ( MCAL_NO_OF_CORES == 3U )
  RA_RunTime_State_SlaveCore2 = RA_RUNTIME_PHASE_IDLE;
#endif /* ( MCAL_NO_OF_CORES == 3U ) */
#endif /* ( MCAL_NO_OF_CORES > 1U ) */  

  #if(IFX_MCAL_USED == STD_OFF)
  TimerFlag = 0U;              
  #endif
  /* initialise watchdog for runtime */
//  SafeWdgM_Init(0);

  #if(IFX_MCAL_USED == STD_OFF)
  /* Set up DTI of 1 ms using STM on master core . STM frequencey is considered as 50 Mhz.*/
  Test_Time_SetAlarm(REFAPP_STM_ALARM_ID_0, 0, StmTicks , RA_Tick);
  #else
  Test_Time_SetAlarm(REFAPP_STM_ALARM_ID_0, 0, StmTicks , SafeTLib_MainTask_Master_Runtime);
  #endif 
   
}

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void RA_PostRun(void)                            **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function executes the post run tests of SafeTlib.
*******************************************************************************/ 
static void RA_PostRun(void)
{
  TstM_PostRun();
}

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void RA_WdgService(void)                         **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function executes watchdog(s) servicing functionality
*******************************************************************************/ 
static void RA_WdgService(void)
{
    #if ( MCAL_NO_OF_CORES > 1U )
    while(RA_RunTime_State_SlaveCore1 != RA_RUNTIME_PHASE_IDLE)
	  {;}
    #if ( MCAL_NO_OF_CORES == 3U )
    while(RA_RunTime_State_SlaveCore2 != RA_RUNTIME_PHASE_IDLE)
	  {;}
    #endif /* ( MCAL_NO_OF_CORES == 3U ) */
    #endif /* ( MCAL_NO_OF_CORES > 1U ) */ 
   
//   SafeWdgM_Service();
}

#if (IFX_MCAL_USED == STD_OFF)
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static boolean RA_Cycle(uint32 counter)                 **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : uint32 counter                                          **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : boolean                                                 **
**                                                                            **
** Description      : This function checks whether runtime times to be executed
**                    for infinite time or for finite number of times (CycleMax times)
*******************************************************************************/ 
static boolean RA_Cycle(uint32 counter)
{
    boolean Result = TRUE;
    if ((CycleMax > 0u) &&  (counter >= CycleMax))
    {
        Result = FALSE;
    }

    return (Result);
}

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void RA_WasteTime(void)                          **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This is a waste time function, waiting for the TimerFlag
**                    to be set to 1U.
*******************************************************************************/ 
static void RA_WasteTime(void)
{

    while (TimerFlag == 0u) {;}
    TimerFlag = 0u;
}

#endif

#if (IFX_MCAL_USED == STD_OFF)
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void RA_Tick(void)                               **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This is ISR routine of STM0 timer interrupt
*******************************************************************************/
static void RA_Tick(void)
{
    if (TaskActive == TRUE)
    {
        /* TimerEvent already happened during task execution -> task budget overrun */
        AppCbk_ErrorHandler(APLCBK_ERR_TASK_BUDGET_OVRRUN);
    }
     TimerFlag = 1u;
}



/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void RA_SysReset(void)                           **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function requests system reset.
*******************************************************************************/ 
static void RA_SysReset(void)
{
    
    /* execute system reset */
    Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
    SCU_RSTCON.B.SW = 1u;
    SCU_SWRSTCON.B.SWRSTREQ = 1u;
    Mcal_SetSafetyENDINIT_Timed();
}
#endif

#endif /* #if(SL_RUNTIME_TESTS == TRUE) */


/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void RA_Stop(void)                                      **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function is used to stop in an endless loop
*******************************************************************************/ 
void RA_Stop(void)
{
  volatile uint32 LoopCount = 1U ;
  while (LoopCount == 1)
  {
    DEBUG();                  /* Implicitly signal a breakpoint to the debugger */
  }
}

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static void RA_InitClock(uint32 fPLL)                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : uint32 fPLL                                                   **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function initialize clock system,
**                    Frequencies configured in this function are, fSource = 100Mhz, 
**                    fSRI = 100Mhz, fSPB = 50Mhz, FSTM = 50Mhz 
*******************************************************************************/ 
static void RA_InitClock(uint32 fPLL)
{
  uint32 AG3CF0_Status;
  uint32 AG3CF1_Status;
  uint32 AG3CF2_Status;
  uint32 SmuStatus_Temp;
  uint32 TimeoutCtr;
  uint32 Pllcon0;
  
  /* Divider values for default PLL freq = 100MHz */
  uint32 Pdivider  = 0U; 
  uint32 Ndivider  = 24U; 
  uint32 K2divider = 4U;  

  AG3CF0_Status = (((uint32)SMU_AGCF3_0.U) & MCU_PLL_OSC_SMU_MASK);
  AG3CF1_Status = (((uint32)SMU_AGCF3_1.U) & MCU_PLL_OSC_SMU_MASK);
  AG3CF2_Status = (((uint32)SMU_AGCF3_2.U) & MCU_PLL_OSC_SMU_MASK);

  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  SMU_KEYS.U = (uint32)0x000000bc;
  /*Clear all SMU alarms for PLL and OSC*/
  SmuStatus_Temp = (((uint32)SMU_AGCF3_0.U) & (~MCU_PLL_OSC_SMU_MASK));
  SMU_AGCF3_0.U = SmuStatus_Temp;
  SmuStatus_Temp = (((uint32)SMU_AGCF3_1.U) & (~MCU_PLL_OSC_SMU_MASK));
  SMU_AGCF3_1.U = SmuStatus_Temp;
  SmuStatus_Temp =  (((uint32)SMU_AGCF3_2.U) & (~MCU_PLL_OSC_SMU_MASK));
  SMU_AGCF3_2.U = SmuStatus_Temp;
  Mcal_SetSafetyENDINIT_Timed();

  /* Clear the ENDINIT bit in the WDT_CON0 register in order
  to disable the write-protection for registers protected
  via the EndInit feature */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);

  /* Fosc0 is used as clock source and a new complete parameter set is
     transferred o the CCU. Both registers CCUCON0 and 1 content is
     taken by CCU => INSEL=01b and UP=01b*/
  SCU_CCUCON1.U = (SCU_CCUCON1.U & MCU_RESET_LCK_UP_INSEL) |
                     MCU_INSEL_IS_FOSC0_AS_SOURCE | MCU_UP_IS_SET_TO_UPDATE;
  /* VCO is configured in normal behaviour => VCOPWD=00b
     PLLPWD is configured in normal behaviour => PLLPWD=01b  */
  SCU_PLLCON0.U = (SCU_PLLCON0.U & MCU_VCOPWD_IS_SET_TO_NORMAL) |
                     MCU_PLLPWD_IS_SET_TO_NORMAL;
  /* OSCVAL  defines the divider value that generates  the reference clock
  that is supervised by the oscillator watchdog.
  fOSC / (OSCVAL + 1) ~ 2.5Mhz*/
  SCU_OSCCON.U = (SCU_OSCCON.U & MCU_OSCCON_B_OSCVAL_MASK) |
            ((unsigned_int)MCU_OSCVAL_REG_VALUE << MCU_OSCCON_B_OSCVAL_BITPOS);


  /* The Oscillator Watchdog of the PLL is cleared and restarted */
  SCU_OSCCON.B.OSCRES = 1U; 

  /* Set the ENDINIT bit in the WDT_CON0 register again
  to enable the write-protection and to prevent a time-out */
  Mcal_SetSafetyENDINIT_Timed();

  /* Time-out counter to come out of while loop in case the
     OSC frequency is not usable */
  TimeoutCtr = MCU_VALIDATE_PLL_FREQUENCY_DELAY;
  /* wait until PLLLV and PLLHV flags are set */
  while(((((SCU_OSCCON.U) &
       (unsigned_int)(MCU_PLLLV_STATUS_CHECK | MCU_PLLHV_STATUS_CHECK)) !=
       ((unsigned_int)(MCU_PLLLV_STATUS_CHECK | MCU_PLLHV_STATUS_CHECK))))
       && (TimeoutCtr > 0UL))
       {
        --TimeoutCtr;
       }

  /* Clear the ENDINIT bit in the WDT_CON0 register in order
  to disable the write-protection for registers protected
  via the EndInit feature */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);

  /*Enter Pre-scalar mode*/
  /* Set VCOBYP = 1* and configure K1DIV with 1*/
  SCU_PLLCON1.B.K1DIV = MCU_BITVAL_1;

  /* In case of a PLL loss-of-lock bit PLLSTAT.FINDIS is set*/
  SCU_PLLCON0.B.OSCDISCDIS = 0U;
  /* PLL is configured into Prescaler Mode; VCO is bypassed*/
  SCU_PLLCON0.B.VCOBYP = 1U;
  /* Bit PLLSTAT.FINDIS is set. The input clock from the oscillator is
     disconnected from the VCO part.*/
  SCU_PLLCON0.B.SETFINDIS = 1U;

  switch (fPLL)
  {
    case  50U:  Pdivider = 1U; Ndivider = 44U; K2divider = 8U ; break ;
    case 100U:  Pdivider = 0U; Ndivider = 24U; K2divider = 4U ; break ;
    case 150U:  Pdivider = 1U; Ndivider = 44U; K2divider = 2U ; break ;
    case 200U:  Pdivider = 0U; Ndivider = 29U; K2divider = 2U ; break ;
    case 250U:  Pdivider = 0U; Ndivider = 24U; K2divider = 4U ; break ;
    case 300U:  Pdivider = 0U; Ndivider = 29U; K2divider = 1U ; break ;
  }  
    
  /* Calculate Pllcon0 value from PDIV and NDIV */
  Pllcon0 = ((Pdivider << MCU_PDIV_SHIFT_VALUE)|(Ndivider << MCU_NDIV_SHIFT_VALUE));
             
  /* Configure PDIV, NDIV and first intermediate step value of K2 */
  SCU_PLLCON0.U = (SCU_PLLCON0.U  & ~MCU_PLLCON0_PDIV_NDIV_MASK) |
                    (unsigned_int)Pllcon0;
  SCU_PLLCON1.B.K2DIV = K2divider;

  /* restart the VCO lock detection */
  SCU_PLLCON0.B.RESLD = 1U;
  /* The input clock from the oscillator is connected to the VCO part */
  SCU_PLLCON0.B.CLRFINDIS = 1U;

  /* SCU_CCUCON0.B.UP = 0; */
  SCU_CCUCON0.U = SCU_CCUCON0.U & MCU_CCUCON_RESET_UP;

  /* SCU_CCUCON0.B.CLKSEL = 0x01; */
  SCU_CCUCON0.U = SCU_CCUCON0.U | MCU_CLKSEL_IS_PLL_AS_SOURCE;

  /* Configure SRIDIV, SPBDIV, FSIDIV */
  SCU_CCUCON0.U = (unsigned_int)
  (((uint32) (1UL)  |   /* CPU0 divider */
          (1UL<<8)  |   /* SRI divider */
          (2UL<<16) |   /* SPB divider for SPB clock */
          (2UL<<20) |   /* FSI2 divider for SPB clock */
          (2UL<<24) |   /* FSI divider for FSI clock */
          (3UL<<26)     /* Backup clock is used as ADC CLK */
        ) &
          (unsigned_int)MCU_CCUCON0_MASK_CLOCK_DIVIDERS) |MCU_CLKSEL_IS_PLL_AS_SOURCE;



  /*     SCU_CCUCON0.B.UP=1; */
  SCU_CCUCON0.U = SCU_CCUCON0.U | MCU_UP_IS_SET_TO_UPDATE;

  /* SCU_CCUCON1.B.UP = 0; */
  SCU_CCUCON1.U = (SCU_CCUCON1.U & MCU_CCUCON_RESET_UP);

  /* Configure MAXDIV, STMDIV, GTMDIV */
  SCU_CCUCON1.U = (unsigned_int)
  (((uint32) (1UL)     |   /* MAX divider for MAX clock */
          (1UL<<4)  |   /* ERAY divider for ERAY clock */
          (2UL<<8)  |   /* STM divider for STM clock */
          (2UL<<12) |   /* GTM divider for GTM clock */
          (0UL<<16)         /* ETH divider for ETH clock */
  ) &
  (unsigned_int)MCU_CCUCON1_MASK_CLOCK_DIVIDERS)|MCU_INSEL_IS_FOSC0_AS_SOURCE;

  /* SCU_CCUCON1.B.UP=1; */
  SCU_CCUCON1.U = SCU_CCUCON1.U | MCU_UP_IS_SET_TO_UPDATE;

   /*Not required to configure CCUCON2 for A-step.
    As, Fbbb is unavailable, MCDS & Ref CLock should work on default
    divider values.*/

  /* Set the ENDINIT bit in the WDT_CON0 register again
  to enable the write-protection and to prevent a time-out */
  Mcal_SetSafetyENDINIT_Timed();

  /*Restore the SMU Status*/
  Mcal_ResetENDINIT();
  /*Clear any SMU TRAP request*/
  SCU_TRAPCLR.B.SMUT = 1U;
  Mcal_SetENDINIT();

  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  SMU_KEYS.U = (uint32)0x000000bcU;
  SMU_CMD.U = (uint32)0x00000005U;
  /*Clear SMU alarms. To clear alarms SET the corresponding bit to 1.*/
  SMU_AG3.U = MCU_PLL_OSC_SMU_MASK;
  /*Restore SMU alarm configuration for PLL & OSC*/
  SmuStatus_Temp = (((uint32)SMU_AGCF3_0.U) | AG3CF0_Status);
  SMU_AGCF3_0.U = SmuStatus_Temp;
  SmuStatus_Temp = (((uint32)SMU_AGCF3_1.U) | AG3CF1_Status);
  SMU_AGCF3_1.U = SmuStatus_Temp;
  SmuStatus_Temp = (((uint32)SMU_AGCF3_2.U) | AG3CF2_Status);
  SMU_AGCF3_2.U = SmuStatus_Temp;
  Mcal_SetSafetyENDINIT_Timed();

  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  /* Wait until the VCO becomes locked */
  while(SCU_PLLSTAT.B.VCOLOCK==0)
  {;}
  SCU_PLLCON0.B.VCOBYP=0;                 /* Disable the VCO Bypass Mode */
  /* Wait until normal mode is entered */
  while(SCU_PLLSTAT.B.VCOBYST==1)
  {;}
  SCU_PLLCON0.B.OSCDISCDIS=0;             /* Automatic oscillator disconnect enabled */
  Mcal_SetSafetyENDINIT_Timed();
}

#if ( MCAL_NO_OF_CORES > 1U )
/*----------------------------------------------------------------------------*/
/* Put another core into idle mode */
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void RA_Stop(void)                                      **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : uint32 core                                             **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function Put another core into idle mode
*******************************************************************************/
static void RA_EnterIdleMode(uint32 CoreId)
{
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  SCU_PMCSR[CoreId].B.REQSLP = 1;
  Mcal_SetSafetyENDINIT_Timed();
}

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void RA_Stop(void)                                      **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : uint32 CoreId                                           **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function bring another core out of idle mode
*******************************************************************************/
static void RA_ExitIdleMode(uint32 CoreId)
{
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  SCU_PMCSR[CoreId].B.REQSLP = 0;
  Mcal_SetSafetyENDINIT_Timed();
}
#endif

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void RA_Stop(void)                                      **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function initializes port for print
*******************************************************************************/
void RA_PrintSetup()
{
  Test_InitTime();
  /* Initialize port for print */
  /* MiniUSB serial port */
  P15_IOCR0.B.PC2 = 0x12;
  Mcal_ResetENDINIT();
  P15_PDR0.U = 0x00;
  P15_PDR1.U = 0x00;
  Mcal_SetENDINIT();
  
  /* Serial communication port on UVP board */
  /* P20.10 ALT2 out, push-pull mode (note: open-drain doesn't work) */
  P20_IOCR8.B.PC10 = 0x12;
  
  RA_InitClock(_RA_PLL_FREQ_);
}

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void RA_Stop(void)                                      **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : uint8 CoreId                                            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Reference Application - Demonstrate SafeTLib usage
*******************************************************************************/
void SafeTlib_main(uint8 CoreId)
{
  #if((CHIP_ID !=21) && (CHIP_ID !=22))  
  uint32* ptr;
  uint32  arr[] = {0x20202020U, 0x20202020U};   
  #endif

  Std_ReturnType Result = E_NOT_OK ;
  
  Sl_FlsPrgRsltType ErrInjResult = SL_PROG_FAIL_PF0;
  #if((CHIP_ID !=21) && (CHIP_ID !=22))  
  volatile uint8 ed_device;    
  #endif
#if (MCAL_NO_OF_CORES > 1U)  
  if ( (CoreId == 0U) && (SL_MASTER_CORE_ID == 1U))
  {
    CPU1_DBGSR.U = 0x14;
  }
#if (MCAL_NO_OF_CORES == 3U)
  if ( (CoreId == 0U) && (SL_MASTER_CORE_ID == 2U))
  {
    CPU2_DBGSR.U = 0x14;
  }  
#endif
#endif  
  Mcal_ResetENDINIT();
  CBS_OCNTRL = 0x00003000U;
  Mcal_SetENDINIT();
/*******************************************************************************
************************MASTER CORE  *******************************
*******************************************************************************/
  if (CoreId == SL_MASTER_CORE_ID)
  {
    /*test code --Sram */
    volatile uint32 dummy;
    uint32 MemsToTest;
    uint8 LoopCOunt;
    Ifx_MC* Mc;

    Mcal_ResetENDINIT();
    MTU_CLC.B.DISR = 0U;
    Mcal_SetENDINIT();

    dummy =  MTU_CLC.U; 
    UNUSED_PARAMETER(dummy)
    MemsToTest = MEM_TO_TEST;
    for (LoopCOunt = 0U; LoopCOunt < SRAMECCTST_MEMORY_COUNT_LOCAL; LoopCOunt++)
    {
      /* Check if memory testing is enabled: */
      if ((MemsToTest &((uint32)1U << LoopCOunt)) > (uint32)0U)
      {
        Mc = SramEccErr_lGetMc(LoopCOunt);	
        Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);  
        Mc->ECCD.B.AENE = 0U;
        Mcal_SetSafetyENDINIT_Timed();	
      }
    }
    #if (MCAL_NO_OF_CORES > 1U)
    if( SL_MASTER_CORE_ID == 1)
    {    
      RA_EnterIdleMode(SLAVE_CORE_1);
    }
    #endif
    RA_gFlagCore0 = 0 ;
    RA_gFlagCore1 = 0 ;
    RA_gFlagCore2 = 0 ;
    RA_Core0Wait = 0 ;
    RA_Core1Wait = 0 ;
    RA_Core2Wait = 0 ;    
    Core1_SwitchRunPhase = 0; 
    Core2_SwitchRunPhase = 0;
    
    RA_PrintSetup();

    RA_RefAppInit(_RA_CACHE_MPU_CFG_);

    #if (SAFETLIB_APPLN_DEBUG == TRUE) 
//    print_f("\n Master Core [Core %d] execution started...",CoreId);
    #endif
    
    /* Establish mapping from CoreId to Sl_ConfigRoot[] array index */
    RA_CoreId2CfgSetIdx[Sl_ConfigRoot[0].CoreId] = 0 ;
#if ( MCAL_NO_OF_CORES > 1U )
    RA_CoreId2CfgSetIdx[Sl_ConfigRoot[1].CoreId] = 1 ;
#if ( MCAL_NO_OF_CORES == 3U )
    RA_CoreId2CfgSetIdx[Sl_ConfigRoot[2].CoreId] = 2 ;  
#endif /* ( MCAL_NO_OF_CORES == 3U ) */
#endif /* ( MCAL_NO_OF_CORES > 1U ) */    
    
    /****Below API is called to inject errors in flash for PMU ECC EDC Test*/
    ErrInjResult = Sl_ChkProgErrorPattern();
    if(ErrInjResult != SL_PROG_DONE)
    {
//      print_f("\n Error Injection for PMU ECC EDC Test Failed");
      AppCbk_ErrorHandler(APLCBK_ERR_INJ_FAIL);
    }
  
    /**** STEP 1: Early Pre-run initialisation ******************************/
    Result = Sl_PreInit(&Sl_ConfigRoot[RA_CoreId2CfgSetIdx[CoreId]]);
    if(Result == E_NOT_OK)
    {
//      print_f("\n PreRun Initialization Failed");
      AppCbk_ErrorHandler(APLCBK_PRERUN_INIT_FAIL);
    }
    
    /**** STEP 2: Early Pre-run test execution ******************************/
    TstM_EarlyPreRunTst();  
    
    /**** STEP 3: TstM, SafeTlib Init execution (AUTOSAR flow can start here)**/
    TstM_Init();

    /**** STEP 5: Pre-run test execution (Single core active)  ****************/
    /* Invalidate seed, test results and test signatures for pre-run phase */
    TstM_InvalidateData();

	
    /*test code --- Enable address error notification  */	
	
    for (LoopCOunt = 0U; LoopCOunt < SRAMECCTST_MEMORY_COUNT_LOCAL; LoopCOunt++)
    {
     /* Check if memory testing is enabled: */
     if ((MemsToTest &((uint32)1U << LoopCOunt)) > (uint32)0U)
     {
        Mc = SramEccErr_lGetMc(LoopCOunt);	
        Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT); 
        Mc->ECCD.B.AENE = 1U;
        Mcal_SetSafetyENDINIT_Timed(); 	
      }
    }
	 #if((CHIP_ID !=21) && (CHIP_ID !=22))  
      ed_device = SCU_CHIPID.B.EEA;
	  if (1 == ed_device)
	  {
  
           Mcal_ResetENDINIT();
		   EMEM_CLC.U   = 0x00000000u;	   
		   /*AVC: wait until the module is started by the CLC write*/
		   while(1u==(EMEM_CLC.U&0x00000001));
		   
		   /*Standard init procedure as calibration mem*/   
		   EMEM_SBRCTR.U     = 0x00000002u;
		   EMEM_SBRCTR.U     = 0x00000006u;
		   EMEM_SBRCTR.U     = 0x0000000Eu;
		   
		   /* ADM sector of EMEM is activated i.e. 1st Megabyte */
		   EMEM_TILECONFIG.U = 0x00000000u;
		   
			 #if(CHIP_ID == 29)
		   /* XAM sector of EMEM is activated i.e. 2nd Megabyte */
			EMEM_TILECONFIGXM.U = 0x00000000u;
			#endif
			/*AVC: activate the clock for the MTU*/
		   /*MTU_CLC.U = 0x00000000u;*/
		   /*ReEnable watchdog*/
		   Mcal_SetENDINIT();
  /* Fill the whole EMEM with a pattern: */
  for (ptr = (uint32*)EMEM_START_ADDR; ptr < (uint32*)EMEM_END_ADDR; ptr += 2)
  {
    MEMWRITE64(ptr, arr);
  }			   
	  }
 #endif	
    /* Run tests that require other cores to be in halt/idle state */
    TstM_PreRunTst(0,1);
    
    RA_gFlagCore0 = 1 ; 

#if ( MCAL_NO_OF_CORES > 1U )        
    /**** STEP 6: a) Activate SLAVE CORE 1 (i.e put to running state) *********/
    if (SL_MASTER_CORE_ID == 1)
    {
      RA_ExitIdleMode(SLAVE_CORE_1);
    } 
    else
    {
      SLAVECORE1_DBGSR.U  = 0x14U;
    }
    
  /**** STEP 6: b)  Wait until "Master Core Wait" is finished.  *************/
    while(RA_gFlagCore1 == 0)
    {;}

//    print_f("\n Back to slave core 2...");
#endif    

#if ( MCAL_NO_OF_CORES == 1U )     
    /* Enable the flags to proceed for processors having only single core */
    RA_gFlagCore1 = 1 ; 
    RA_gFlagCore2 = 1 ; 
    Core1_SwitchRunPhase = 1;
    Core2_SwitchRunPhase = 1;
#endif

    /*--------------------------------------*/


    /* 
      At this point of time other cores are in RUN state.
      Tests may run in parallel to tests on other cores.
    */
    TstM_PreRunTst(2,2);
    RA_Core0Wait = 1;
#if ( MCAL_NO_OF_CORES == 1U )
    RA_Core1Wait = 1;    
    RA_Core2Wait = 1;
#endif    
    /*--------------------------------------*/
    
    /**** STEP 9: Wait till all cores have finished execution of Pre run tests  ***************/
    while((RA_Core0Wait ==0) || (RA_Core1Wait ==0) ||(RA_Core2Wait ==0))
	{;}

    /**** STEP 10: Pre-run test signature verification (of all cores)  *********/    
    TstM_CheckPreRunTestResult();
    
//    print_f("\n SafeTlib: Early pre-run and Pre-run phase complete for all cores.");
    /* Port33.8 Setup */
    Mcal_ResetENDINIT();
    P33_IOCR8.U = 0x80;
    P33_OUT.U = 0;
    Mcal_SetENDINIT();

    /* Enable SMU to control the error pin */
    Result = Smu_SetupErrorPin();
    
    if (Result != E_OK)
    {
//      print_f("\n SafeTlib: Smu_SetupErrorPin failed.");
      RA_Stop();      
    }    
    /* Wait until core1 and core2 has switched its phase to run-time */
    while((Core1_SwitchRunPhase == 0U) || (Core2_SwitchRunPhase == 0U))
	{;}
    /**** STEP 11: Runtime test execution (multi cores active)  ***************/    
    #if(SL_RUNTIME_TESTS == TRUE)
    //RA_RunTimeTest();
    Sl_SwitchTstPhase(SL_RUN);
    
    #if (IFX_MCAL_USED == STD_OFF)
//    print_f("\n SafeTlib: Run time phase completed. Issuing software reset...  ");
    RA_SysReset(); 
    #endif
    #else
    /* Wait forever */
    RA_Core0Wait = 0;
    RA_InitLed();
    while(RA_Core0Wait ==0)
    {
      RA_SpecificCoreToggleLed(CycleCount,MASTER_CORE_LED_BLINK_INTERVAL,MASTER_CORE_LED);
      #if ( MCAL_NO_OF_CORES > 1U )      
      RA_SpecificCoreToggleLed(CycleCount,SLAVE_CORE1_LED_BLINK_INTERVAL,SLAVE_CORE1_LED);
      #if ( MCAL_NO_OF_CORES == 3U )  
      RA_SpecificCoreToggleLed(CycleCount,SLAVE_CORE2_LED_BLINK_INTERVAL,SLAVE_CORE2_LED);
      #endif
      #endif
    }
    #endif /* (SL_RUNTIME_TESTS == TRUE)*/
  }

#if ( MCAL_NO_OF_CORES > 1U )    
/*******************************************************************************
*****************               SLAVE CORE 1                 *******************
*******************************************************************************/
  if(CoreId == SLAVE_CORE_1)
  {    
    while(RA_gFlagCore0 == 0)
	{;}

    #if (SAFETLIB_APPLN_DEBUG == TRUE) 
//    print_f("\n Slave Core [Core %d] execution started...", CoreId);
    #endif
    
    RA_RefAppInit(_RA_CACHE_MPU_CFG_);
    /**** STEP 1: Put the calling core (MASTER core) to IDLE state  ***********/
    
    /* Put Master Core into IDLE mode */
    RA_EnterIdleMode(SL_MASTER_CORE_ID);

    /**** STEP 2: SafeTlib initialisation on Slave Core 1  ********************/
    TstM_Init();     
    
    /**** STEP 3: Pre-run test execution (Single core active) *****************/
    /* Invalidate seed, test results and test signatures for pre-run phase */
    TstM_InvalidateData();

    /* Run tests that require other cores to be in halt/idle state */
    TstM_PreRunTst(0,1);

    TstM_CheckPreRunTestResult();

    RA_gFlagCore1 = 1 ;

#if ( MCAL_NO_OF_CORES == 3U )   
    /**** STEP 4: a) Activate SLAVE CORE 2 (i.e put to running state) *********/
    SLAVECORE2_DBGSR.U  = 0x14U;
    
    /**** STEP 4: b)  Wait until "SLAVE Core 1 Wait" is finished **************/
    while(RA_gFlagCore2 == 0)
	{;}
#endif
    

#if ( MCAL_NO_OF_CORES == 2U )   
    /* Enable the flags to proceed for processors having only two cores */
    RA_gFlagCore2 = 1 ; 
    Core2_SwitchRunPhase = 1;
#endif 
    /**** STEP 4: c)  Activate the Master Core  */
    RA_ExitIdleMode(SL_MASTER_CORE_ID);
    
    /**** STEP 5: Pre-run test execution (Multi cores active)  ****************/
    /* Run tests that do NOT require other cores to be in halt/idle state */
    TstM_PreRunTst(2,2);
    RA_Core1Wait = 1;
#if ( MCAL_NO_OF_CORES == 2U )
    RA_Core2Wait = 1;
#endif    
    TstM_CheckPreRunTestResult();
    /****  Wait till all cores have finished execution of Pre run tests  ***************/
    while((RA_Core0Wait ==0) || (RA_Core1Wait ==0) ||(RA_Core2Wait ==0))
	{;}
    /**** STEP 6: Indicate Slave Core 1 is ready to move to RUN phase  ********/
    /* Restore BTV for core 1 */
    Sl_SwitchTstPhase(SL_RUN);
//    ENABLE();
    Core1_SwitchRunPhase = 1U;
    /**** STEP 7: Runtime test execution (multi cores active)*****************/
    #if(SL_RUNTIME_TESTS == TRUE)
    #if (IFX_MCAL_USED == STD_OFF)
    SAFET_core1_RunTimeTest();
    #endif
    #endif
  }

/*******************************************************************************
********************          SLAVE CORE 2             *************************
*******************************************************************************/

#if ( MCAL_NO_OF_CORES == 3U )   
  if(CoreId == SLAVE_CORE_2)
  { 
    /* wait for core 0 to be up and running */
    while(RA_gFlagCore0 == 0)
	{;}
    
    /* Wait until core 1 puts core 0 into idle mode */
    while(RA_gFlagCore1 == 0)
	{;}

    #if (SAFETLIB_APPLN_DEBUG == TRUE) 
//    print_f("\n Slave Core 2 [Core %d] execution started...", CoreId);
    #endif


    RA_RefAppInit(_RA_CACHE_MPU_CFG_);
    
    /**** STEP 1: Put the calling core (SLAVE core 1) to IDLE state***********/
    RA_EnterIdleMode(SLAVE_CORE_1);
    
    /**** STEP 2: SafeTlib initialisation on Slave Core 2  ********************/
    TstM_Init();
    
    /**** STEP 3: Pre-run test execution (Single core active) *****************/
    /* Invalidate seed, test results and test signatures for pre-run phase */
    TstM_InvalidateData();
    /* Run tests that require other cores to be in halt/idle state */
    TstM_PreRunTst(0,1);
    
    TstM_CheckPreRunTestResult();
    
    /**** STEP 4: a) No further cores to activate & No need of wait*/
    RA_gFlagCore2 = 1 ;   
    
    /**** STEP 4: b)  Activate the Calling Core*/
    /* Exit idle mode for Core 1 */
    RA_ExitIdleMode(SLAVE_CORE_1);    
    
    /**** STEP 5: Pre-run test execution (Multi cores active)  ****************/
    TstM_PreRunTst(2,2);
    RA_Core2Wait = 1;
    /****  Wait till all cores have finished execution of Pre run tests   ***************/
    while((RA_Core0Wait ==0) || (RA_Core1Wait ==0) ||(RA_Core2Wait ==0))
	{;}
    /**** STEP 6: Indicate Slave Core 2 is ready to move to RUN phase  ********/
    Sl_SwitchTstPhase(SL_RUN);
//    ENABLE();
    Core2_SwitchRunPhase = 1U;
    #if(SL_RUNTIME_TESTS == TRUE)
    /**** STEP 7: Runtime test execution (multi cores active)   ***************/
    #if (IFX_MCAL_USED == STD_OFF)
    SAFET_core2_RunTimeTest();
    #endif
    #endif
  }
#endif  /* ( MCAL_NO_OF_CORES == 3U ) */
#endif /* ( MCAL_NO_OF_CORES > 1U )  */
}

#if(SL_RUNTIME_TESTS == TRUE)
#if ( MCAL_NO_OF_CORES > 1U )    
 
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void SAFET_core1_RunTimeTest(void)                      **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : SafeTlib Run time tests of Core1; calling from Mcal container
                      in case of Mcal-SafeTlib Integration.
*******************************************************************************/
void SAFET_core1_RunTimeTest(void)
{
  while((RA_Core0Wait ==0) || (RA_Core1Wait ==0) ||(RA_Core2Wait ==0))
  {;}

  #if (IFX_MCAL_USED == STD_OFF)
  while (RA_LoopCount == 1)
  {
  #endif
    if(RA_RunTime_State_SlaveCore1 == RA_RUNTIME_PHASE_ACTIVE)
    {
      
      /* Execute the Runtime Tests  */
      TstM_Run();         
      CycleCountSlaveCore1++;
      RA_RunTime_State_SlaveCore1 = RA_RUNTIME_PHASE_IDLE ;
    }
  #if (IFX_MCAL_USED == STD_OFF)  
  }
  #endif

}

#if ( MCAL_NO_OF_CORES == 3U )   
 
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void RA_Stop(void)                                      **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : SafeTlib Run time tests of Core2; calling from Mcal container
                      in case of Mcal-SafeTlib Integration. 
*******************************************************************************/
void SAFET_core2_RunTimeTest(void)
{    
  while((RA_Core0Wait ==0) || (RA_Core1Wait ==0) ||(RA_Core2Wait ==0))
  {;}
  #if (IFX_MCAL_USED == STD_OFF)
  while (RA_LoopCount == 1)
  {
  #endif
    if(RA_RunTime_State_SlaveCore2 == RA_RUNTIME_PHASE_ACTIVE)
    {
      /* Execute the Runtime Tests  */
      TstM_Run();
      CycleCountSlaveCore2++;
      RA_RunTime_State_SlaveCore2 = RA_RUNTIME_PHASE_IDLE ;
    }
  #if (IFX_MCAL_USED == STD_OFF)  
  }
  #endif
}
#endif  /* ( MCAL_NO_OF_CORES == 3U ) */
#endif /* ( MCAL_NO_OF_CORES > 1U )  */
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void RA_Stop(void)                                      **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function disables the cyclic tests

*******************************************************************************/
void RA_DisableCyclicTest(void)
{
  Test_Time_DeInitAlarm(REFAPP_STM_ALARM_ID_0);
  Test_Time_DeInitAlarm(REFAPP_STM_ALARM_ID_1);

  RA_PostRun();
//  print_f("\n SafeTlib: Post-run phase complete.");
  CycleCount = 0u;
#if((IFX_MCAL_USED == STD_ON) && ((CHIP_ID == 26U) || (CHIP_ID == 29U)))
/*Poll until both the Flags are set to 0 by Core0 during 
  Mcal+STL Integration on TC26x and TC29x
  to enable again the Cyclic tests in Core1*/
  while(StlEnCyle_Tst || StlDbCyle_Tst);
  #endif
}
#else
void SAFET_core2_RunTimeTest(void)
{
}

void SAFET_core1_RunTimeTest(void)
{
}
#endif

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void RA_Stop(void)                                      **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Function to set ICACHE, DCACHE and MPU on/off
                      Values for i/p parameter CacheMpuCfg:
                      000b : all off
                      001b : ICACHE on,  DCACHE off, MPU off
                      010b : ICACHE off, DCACHE on,  MPU off
                      100b : ICACHE off, DCACHE off, MPU on
                      111b : ICACHE on, DCACHE on, MPU on

*******************************************************************************/   
void RA_RefAppInit(uint8 CacheMpuCfg)
{
  uint32 Temp = 0u;
  
  if(CacheMpuCfg != 0)
  {
    Mcal_ResetENDINIT();
    if((CacheMpuCfg & 0x1) != 0)
    {
      /* Enable ICACHE memory */
      MTCR(CPU_PCON0,0);
      ISYNC();
    }
    else
    {
      /* Disable ICACHE memory */
      MTCR(CPU_PCON0,2U);
      ISYNC();
    }
    
    if((CacheMpuCfg & 0x2) != 0)
    {
      /* Enable DCACHE memory */
      MTCR(CPU_DCON0,0);
      ISYNC();
      DSYNC();
    }
    else
    {
      /* Disable DCACHE memory */
      MTCR(CPU_DCON0,2U);
      ISYNC();
      DSYNC();
    }
    Mcal_SetENDINIT();
    if((CacheMpuCfg & 0x4) != 0)
    {
      /* Enable read and write access to the whole address space */    
      MTCR(CPU_DPR0_L, ADDRESS_SPACE_START);
      MTCR(CPU_DPR0_U, ADDRESS_SPACE_END);
      MTCR(CPU_DPRE0, DPR0_SELECTION_MASK);
      MTCR(CPU_DPWE0, DPR0_SELECTION_MASK);
      MTCR(CPU_DPRE1, DPR0_SELECTION_MASK);
      MTCR(CPU_DPWE1, DPR0_SELECTION_MASK);

      MTCR(CPU_CPR0_L, ADDRESS_SPACE_START);
      MTCR(CPU_CPR0_U, ADDRESS_SPACE_END);
      MTCR(CPU_CPXE1, CPR0_SELECTION_MASK);
      MTCR(CPU_CPXE0, CPR0_SELECTION_MASK);
      
      Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
      /* Enable Memory Protection System */
      Temp = (uint32)MFCR(CPU_SYSCON);
      Temp |= (uint32)SYSCON_PROT_EN_BIT;
      MTCR(CPU_SYSCON, Temp);
  Mcal_SetSafetyENDINIT_Timed();
    }
  }
}


/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void RA_Stop(void)                                      **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : uint8 MemIdx                                            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Test functions :Sram Test code

*******************************************************************************/
static Ifx_MC* SramEccErr_lGetMc
(
  const uint8 MemIdx
)
{
  uint8   McIdx;
  Ifx_MC* Result;

  McIdx = SramEccTst_kMcTable[MemIdx];
  Result = (Ifx_MC*)((uint32)&MODULE_MC0 + ((uint32)0x100U * (uint32)McIdx));

  return Result;
}

#define IFX_APPL_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"


