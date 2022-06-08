/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  :  TstHandler_PBCfg.c                                           **
**                                                                            **
**  DATE, TIME: 2021-09-22, 20:02:51                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : TstHandler.bmd                                    **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / GNU / Diab                                          **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Test Handler configuration generated out of ECU            **
**                 configuration file                                         **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "TstHandler_Cfg.h"

#define IFX_TSTHANDLER_START_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                      Private Macro definition                              **
*******************************************************************************/

/*******************************************************************************
**                      Configuration Options                                 **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Funtion Declarations                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#include "TstHandler.h"


static const Th_TestLibFuncPtrType Th_MTLFuncList_ConfigSet0_Core0[TH_TOTAL_TESTS] =
{
  /* 0 */ &CpuBusMpuLfmTst_LfmTest,
  /* 1 */ &IRTst_IRTst,
  /* 2 */ &SpbTst_PeripheralRegAccProtTst,
  /* 3 */ &SramEccTst_SramEccTst,
  /* 4 */ &SriTst_SriTst,
  /* 5 */ &RegAccProtTst_RegAccProtTst,
  /* 6 */ &TrapTst_TrapTst,
  /* 7 */ &WdgTst_WdgCpuTst,
  /* 8 */ &LockStepTst_LockStepTst,
  /* 9 */ &LmuRegAccProtTst_LmuRegAccProtTst,
};
static const Th_TestLibFuncPtrType Th_MTLFuncList_ConfigSet1_Core1[TH_TOTAL_TESTS] =
{
  /* 0 */ &CpuBusMpuLfmTst_LfmTest,
  /* 1 */ &CpuMpuTst_CpuMpuTst,
  /* 2 */ &DmaTst_CRCTst,
  /* 3 */ &DmaTst_TimestampTst,
  /* 4 */ &DmaTst_SafeLinkedListTst,
  /* 5 */ &FceTst_FceTst,
  /* 6 */ &IomTst_IomTst,
  /* 7 */ &IRTst_IRTst,
  /* 8 */ &LmuBusMpuLfmTst_LmuBusMpuLfmTst,
  /* 9 */ &PflashMonTst_PflashMonTst,
  /* 10 */ &PmuEccEdcTst_EccEdcTst,
  /* 11 */ &SfrTst_SfrCmpTst,
  /* 12 */ &SfrTst_SfrCrcTst,
  /* 13 */ &SmuTst_IrqTst,
  /* 14 */ &SmuTst_RtTst,
  /* 15 */ &SmuTst_NmiTst,
  /* 16 */ &SpbTst_PeripheralRegAccProtTst,
  /* 17 */ &SramEccTst_SramEccTst,
  /* 18 */ &SriTst_SriTst,
  /* 19 */ &RegAccProtTst_RegAccProtTst,
  /* 20 */ &TrapTst_TrapTst,
  /* 21 */ &ClkmTst_ClkmTst,
  /* 22 */ &VltmTst_VltmTst,
  /* 23 */ &WdgTst_WdgCpuTst,
  /* 24 */ &WdgTst_WdgSafetyTst,
  /* 25 */ &LockStepTst_LockStepTst,
  /* 26 */ &SpbTst_TimeoutTst,
  /* 27 */ &SffTst_SffTst,
  /* 28 */ &LmuRegAccProtTst_LmuRegAccProtTst,
  /* 29 */ &PhlSramTst_PhlSramTst,
};
static const Th_TestLibFuncPtrType Th_MTLFuncList_ConfigSet2_Core2[TH_TOTAL_TESTS] =
{
  /* 0 */ &CpuBusMpuLfmTst_LfmTest,
  /* 1 */ &IRTst_IRTst,
  /* 2 */ &SpbTst_PeripheralRegAccProtTst,
  /* 3 */ &SriTst_SriTst,
  /* 4 */ &RegAccProtTst_RegAccProtTst,
  /* 5 */ &TrapTst_TrapTst,
  /* 6 */ &WdgTst_WdgCpuTst,
  /* 7 */ &LmuRegAccProtTst_LmuRegAccProtTst,
};


static const Th_TestlibTestSetType Th_PreRunTests_ConfigSet0_Core0[3][SL_MAX_TESTS_PRE_RUN_GRP]=
{
  {
    {SRAM_ECC_Cpu1_2_Test_ConfigSet0, 0U, 0U},
    {CPU_Register_Access_Protection_Test_ConfigSet0, 0U, 0U},
    {Lockstep_Test_ConfigSet0, 0U, 0U},
    {Trap_Test_ConfigSet0, 0U, 0U},
    {CPU_Bus_MPU_Test_ConfigSet0, 0U, 0U},
    {Interrupt_Router_Test_ConfigSet0, 0U, 0U},
    {Lmu_Register_Access_Protection_Test_ConfigSet0, 0U, 0U},
    {SPB_Register_Access_Protection_Test_ConfigSet0, 0U, 0U},
    {SRI_EDC_and_Bus_Error_Test_ConfigSet0, 0U, 0U},
    {TH_INVALID_TEST_ID, 0U, 0U},
  },
  {
    {TH_INVALID_TEST_ID, 0U, 0U},
    {TH_INVALID_TEST_ID, 0U, 0U},
    {TH_INVALID_TEST_ID, 0U, 0U},
    {TH_INVALID_TEST_ID, 0U, 0U},
    {TH_INVALID_TEST_ID, 0U, 0U},
    {TH_INVALID_TEST_ID, 0U, 0U},
    {TH_INVALID_TEST_ID, 0U, 0U},
    {TH_INVALID_TEST_ID, 0U, 0U},
    {TH_INVALID_TEST_ID, 0U, 0U},
    {TH_INVALID_TEST_ID, 0U, 0U},
  },
  {
    {CPU_Watchdog_Test_ConfigSet0, 0U, 0U},
    {TH_INVALID_TEST_ID, 0U, 0U},
    {TH_INVALID_TEST_ID, 0U, 0U},
    {TH_INVALID_TEST_ID, 0U, 0U},
    {TH_INVALID_TEST_ID, 0U, 0U},
    {TH_INVALID_TEST_ID, 0U, 0U},
    {TH_INVALID_TEST_ID, 0U, 0U},
    {TH_INVALID_TEST_ID, 0U, 0U},
    {TH_INVALID_TEST_ID, 0U, 0U},
    {TH_INVALID_TEST_ID, 0U, 0U},
  },
};



static const Th_TestlibTestSetType Th_PreRunTests_ConfigSet1_Core1[3][SL_MAX_TESTS_PRE_RUN_GRP]=
{
  {
    {PMU_ECC_and_EDC_Test_ConfigSet1, 0U, 0U},
    {SRAM_ECC_Cpu12_Test_ConfigSet1, 1U, 0U},
    {PFLASH_Monitor_Test_ConfigSet1, 0U, 0U},
    {SPB_Register_Access_Protection_Test_ConfigSet1, 0U, 0U},
    {SPB_Timeout_Test_ConfigSet1, 0U, 0U},
    {CPU_MPU_Test_ConfigSet1, 0U, 0U},
    {CPU_Bus_MPU_Test_ConfigSet1, 0U, 0U},
    {Input_Output_Monitor_Test_ConfigSet1, 0U, 0U},
    {SRI_EDC_and_Bus_Error_Test_ConfigSet1, 0U, 0U},
    {TH_INVALID_TEST_ID, 0U, 0U},
  },
  {
    {DMA_CRC_Test_ConfigSet1, 0U, 0U},
    {DMA_Safe_Linked_List_Test_ConfigSet1, 0U, 0U},
    {DMA_TIme_Stamp_Test_ConfigSet1, 0U, 0U},
    {Smu_Recovery_Timer_Test_ConfigSet1, 0U, 0U},
    {Interrupt_Router_Test_ConfigSet1, 0U, 0U},
    {Peripheral_SRAM_Test_ConfigSet1, 0U, 0U},
    {Flexible_CRC_Engine_Test_ConfigSet1, 0U, 0U},
    {Lmu_Bus_MPU_Test_ConfigSet1, 0U, 0U},
    {Lmu_Register_Access_Protection_Test_ConfigSet1, 0U, 0U},
    {Smu_Interrupt_Request_Test_ConfigSet1, 0U, 0U},
  },
  {
    {Voltage_Monitor_Test_ConfigSet1, 0U, 0U},
    {Trap_Test_ConfigSet1, 0U, 0U},
    {Lockstep_Test_ConfigSet1, 0U, 0U},
    {Clock_Monitor_Test_ConfigSet1, 0U, 0U},
    {CPU_Watchdog_Test_ConfigSet1, 0U, 0U},
    {Safety_Watchdog_Test_ConfigSet1, 0U, 0U},
    {CPU_Register_Access_Protection_Test_ConfigSet1, 0U, 0U},
    {Safety_Flip_Flop_Test_ConfigSet1, 0U, 0U},
    {Smu_Nmi_Test_ConfigSet1, 0U, 0U},
    {TH_INVALID_TEST_ID, 0U, 0U},
  },
};

static const Th_TestlibTestSetType Th_RuntimeTests_ConfigSet1_Core1[1][SL_MAX_TESTS_RUN_TIME_GRP]=
{
  {
    {SFR_Compare_Test_ConfigSet1, 0U, 0U},
    {SFR_CRC_Test_ConfigSet1, 0U, 0U},
    {TH_INVALID_TEST_ID, 0U, 0U},
    {TH_INVALID_TEST_ID, 0U, 0U},
    {TH_INVALID_TEST_ID, 0U, 0U},
  },
};


static const Th_TestlibTestSetType Th_PreRunTests_ConfigSet2_Core2[1][SL_MAX_TESTS_PRE_RUN_GRP]=
{
  {
    {CPU_Register_Access_Protection_Test_ConfigSet2, 0U, 0U},
    {CPU_Watchdog_Test_ConfigSet2, 0U, 0U},
    {Trap_Test_ConfigSet2, 0U, 0U},
    {CPU_Bus_MPU_Test_ConfigSet2, 0U, 0U},
    {Interrupt_Router_Test_ConfigSet2, 0U, 0U},
    {Lmu_Register_Access_Protection_Test_ConfigSet2, 0U, 0U},
    {SPB_Register_Access_Protection_Test_ConfigSet2, 0U, 0U},
    {SRI_EDC_and_Bus_Error_Test_ConfigSet2, 0U, 0U},
    {TH_INVALID_TEST_ID, 0U, 0U},
    {TH_INVALID_TEST_ID, 0U, 0U},
  },
};


/* Test Handler Module Configuration */
const Sl_ConfigType Sl_ConfigRoot[3] = 
{
  /* ConfigSet for core 0*/
  {
    /* Pointer to Early Pre-run Test configuration */
    NULL_PTR,
    /* Pointer to Pre-run Test configuration */
    *Th_PreRunTests_ConfigSet0_Core0,
    /* Pointer to Run time Test configuration */
    NULL_PTR,
    /* Pointer to Post-run Test configuration */
    NULL_PTR,
    /* Start of array of TestLib function pointers  */
    &Th_MTLFuncList_ConfigSet0_Core0[0],
    /* Address of SMU configuration for pre-run phase For Slave core, it is NULL_PTR */
    NULL_PTR,
    /* Address of SMU configuration for pre-run phase For Slave core, it is NULL_PTR */
    NULL_PTR,
    /* Number of early pre-run test groups  */
    0U,
    /* Number of pre-run test groups  */
    3U,
    /* Number of run-time test groups  */
    0U,
    /* Number of post-run test groups  */
    0U,
    /* Core Id to which this config set corresponds to */
    0U
  },
  /* ConfigSet for core 1*/
  {
    /* Pointer to Early Pre-run Test configuration */
    NULL_PTR,
    /* Pointer to Pre-run Test configuration */
    *Th_PreRunTests_ConfigSet1_Core1,
    /* Pointer to Run time Test configuration */
    *Th_RuntimeTests_ConfigSet1_Core1,
    /* Pointer to Post-run Test configuration */
    NULL_PTR,
    /* Start of array of TestLib function pointers  */
    &Th_MTLFuncList_ConfigSet1_Core1[0],
    /* Address of SMU configuration for pre-run phase */
    &Smu_ConfigRoot[SmuConfigSet_0],
    /* Address of SMU configuration for runtime phase*/
    &Smu_ConfigRoot[SmuConfigSet_1],
    /* Number of early pre-run test groups  */
    0U,
    /* Number of pre-run test groups  */
    3U,
    /* Number of run-time test groups  */
    1U,
    /* Number of post-run test groups  */
    0U,
    /* Core Id to which this config set corresponds to */
    1U
  },
  /* ConfigSet for core 2*/
  {
    /* Pointer to Early Pre-run Test configuration */
    NULL_PTR,
    /* Pointer to Pre-run Test configuration */
    *Th_PreRunTests_ConfigSet2_Core2,
    /* Pointer to Run time Test configuration */
    NULL_PTR,
    /* Pointer to Post-run Test configuration */
    NULL_PTR,
    /* Start of array of TestLib function pointers  */
    &Th_MTLFuncList_ConfigSet2_Core2[0],
    /* Address of SMU configuration for pre-run phase For Slave core, it is NULL_PTR */
    NULL_PTR,
    /* Address of SMU configuration for pre-run phase For Slave core, it is NULL_PTR */
    NULL_PTR,
    /* Number of early pre-run test groups  */
    0U,
    /* Number of pre-run test groups  */
    1U,
    /* Number of run-time test groups  */
    0U,
    /* Number of post-run test groups  */
    0U,
    /* Core Id to which this config set corresponds to */
    2U
  },
};
#define IFX_TSTHANDLER_STOP_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"
