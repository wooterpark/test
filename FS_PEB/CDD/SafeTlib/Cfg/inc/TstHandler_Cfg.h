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
**  FILENAME  :  TstHandler_Cfg.h                                             **
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
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : TstHandler configuration header file                       **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef TSTHANDLER_CFG_H
#define TSTHANDLER_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "CpuBusMpuLfmTst.h"
#include "IRTst.h"
#include "SpbTst.h"
#include "SramEccTst.h"
#include "SriTst.h"
#include "RegAccProtTst.h"
#include "TrapTst.h"
#include "WdgTst.h"
#include "LockStepTst.h"

#include "LmuRegAccProtTst.h"
#include "CpuMpuTst.h"
#include "DmaTst.h"
#include "FceTst.h"
#include "IomTst.h"
#include "LmuBusMpuLfmTst.h"
#include "PmuEccEdcTst.h"
#include "PflashMonTst.h"
#include "SfrCmpTst.h"
#include "SfrCrcTst.h"
#include "SmuTst.h"
#include "ClkmTst.h"
#include "VltmTst.h"
#include "SffTst.h"
#include "PhlSramTst.h"


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/* Master core Id */
#define SL_MASTER_CORE_ID (1U)


/* Maximum tests configured per group */
#define SL_MAX_TESTS_EARLY_PRE_RUN_GRP  (5U)
#define SL_MAX_TESTS_PRE_RUN_GRP        (10U)
#define SL_MAX_TESTS_RUN_TIME_GRP       (5U)
#define SL_MAX_TESTS_POST_RUN_GRP       (5U)


#define SL_CFG_COUNT (3U)

/* Maximum number of tests among arrays Th_MTLFuncList_Core<x> {x: Core id} */
#define TH_TOTAL_TESTS (30U)


/* Test index macros used to represent tests in array Th_MTLFuncList_Core0 */
#define  CPU_Bus_MPU_Test_ConfigSet0  (0U)
#define  Interrupt_Router_Test_ConfigSet0  (1U)
#define  SPB_Register_Access_Protection_Test_ConfigSet0  (2U)
#define  SRAM_ECC_Cpu1_2_Test_ConfigSet0  (3U)
#define  SRI_EDC_and_Bus_Error_Test_ConfigSet0  (4U)
#define  CPU_Register_Access_Protection_Test_ConfigSet0  (5U)
#define  Trap_Test_ConfigSet0  (6U)
#define  CPU_Watchdog_Test_ConfigSet0  (7U)
#define  Lockstep_Test_ConfigSet0  (8U)
#define  Lmu_Register_Access_Protection_Test_ConfigSet0  (9U)


/* Test index macros used to represent tests in array Th_MTLFuncList_Core1 */
#define  CPU_Bus_MPU_Test_ConfigSet1  (0U)
#define  CPU_MPU_Test_ConfigSet1  (1U)
#define  DMA_CRC_Test_ConfigSet1  (2U)
#define  DMA_TIme_Stamp_Test_ConfigSet1  (3U)
#define  DMA_Safe_Linked_List_Test_ConfigSet1  (4U)
#define  Flexible_CRC_Engine_Test_ConfigSet1  (5U)
#define  Input_Output_Monitor_Test_ConfigSet1  (6U)
#define  Interrupt_Router_Test_ConfigSet1  (7U)
#define  Lmu_Bus_MPU_Test_ConfigSet1  (8U)
#define  PFLASH_Monitor_Test_ConfigSet1  (9U)
#define  PMU_ECC_and_EDC_Test_ConfigSet1  (10U)
#define  SFR_Compare_Test_ConfigSet1  (11U)
#define  SFR_CRC_Test_ConfigSet1  (12U)
#define  Smu_Interrupt_Request_Test_ConfigSet1  (13U)
#define  Smu_Recovery_Timer_Test_ConfigSet1  (14U)
#define  Smu_Nmi_Test_ConfigSet1  (15U)
#define  SPB_Register_Access_Protection_Test_ConfigSet1  (16U)
#define  SRAM_ECC_Cpu12_Test_ConfigSet1  (17U)
#define  SRI_EDC_and_Bus_Error_Test_ConfigSet1  (18U)
#define  CPU_Register_Access_Protection_Test_ConfigSet1  (19U)
#define  Trap_Test_ConfigSet1  (20U)
#define  Clock_Monitor_Test_ConfigSet1  (21U)
#define  Voltage_Monitor_Test_ConfigSet1  (22U)
#define  CPU_Watchdog_Test_ConfigSet1  (23U)
#define  Safety_Watchdog_Test_ConfigSet1  (24U)
#define  Lockstep_Test_ConfigSet1  (25U)
#define  SPB_Timeout_Test_ConfigSet1  (26U)
#define  Safety_Flip_Flop_Test_ConfigSet1  (27U)
#define  Lmu_Register_Access_Protection_Test_ConfigSet1  (28U)
#define  Peripheral_SRAM_Test_ConfigSet1  (29U)


/* Test index macros used to represent tests in array Th_MTLFuncList_Core2 */
#define  CPU_Bus_MPU_Test_ConfigSet2  (0U)
#define  Interrupt_Router_Test_ConfigSet2  (1U)
#define  SPB_Register_Access_Protection_Test_ConfigSet2  (2U)
#define  SRI_EDC_and_Bus_Error_Test_ConfigSet2  (3U)
#define  CPU_Register_Access_Protection_Test_ConfigSet2  (4U)
#define  Trap_Test_ConfigSet2  (5U)
#define  CPU_Watchdog_Test_ConfigSet2  (6U)
#define  Lmu_Register_Access_Protection_Test_ConfigSet2  (7U)



#endif  /* TSTHANDLER_CFG_H */
