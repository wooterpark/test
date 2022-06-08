/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Fls_17_Pmu_PBCfg.c $                                       **
**                                                                           **
**  $CC VERSION : \main\46 $                                                 **
**                                                                           **
**  DATE, TIME: 2021-09-29, 16:08:33                                         **
**                                                                           **
**  GENERATOR : Build b141014-0350                                           **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : FLS configuration generated out of ECU configuration      **
**                   file (Fls_17_Pmu.bmd)                                   **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Include Flash Module File */
#include "Fls_17_Pmu.h"
#include "Fls_17_Pmu_ac.h"
/* Include Diagnostic Error Manager Header */
#include "Dem.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/* Job End Notification Function is not configured */

/* Job Error Notification Function is not configured */

/* Illegal State Notification function is not configured */

/*******************************************************************************
**                      Global Constant Definitions                          **
*******************************************************************************/

#define FLS_17_PMU_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/* Fls State Variable structure */
#if(FLS_DEBUG_SUPPORT == STD_OFF)
static Fls_17_Pmu_StateType  FlsStateVar = {.FlsJobType={0}};
#else
Fls_17_Pmu_StateType  FlsStateVar = {.FlsJobType={0}};
#endif

#define FLS_17_PMU_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define FLS_17_PMU_START_SEC_POSTBUILDCFG
#include "MemMap.h"

const Fls_17_Pmu_ConfigType Fls_17_Pmu_ConfigRoot[] = 
{
  {
    /* Fls state variable structure */
    &FlsStateVar,

    /* Maximum number of bytes to Read in one cycle */
    /* Fast Mode */
    64U,
    /* Normal Mode */
    32U,

    /* Job End Notification */
    /*IFX_MISRA_RULE_11_01_STATUS=Address is stored as a pointer*/
    /*IFX_MISRA_RULE_11_03_STATUS=Address is stored as a pointer*/
    (Fls_NotifFunctionPtrType)0,

    /* Job Error Notification */
    /*IFX_MISRA_RULE_11_01_STATUS=Address is stored as a pointer*/
    /*IFX_MISRA_RULE_11_03_STATUS=Address is stored as a pointer*/
    (Fls_NotifFunctionPtrType)0,

    /* Illegal State Notification */
    /*IFX_MISRA_RULE_11_01_STATUS=Address is stored as a pointer*/
    /*IFX_MISRA_RULE_11_03_STATUS=Address is stored as a pointer*/
    (Fls_NotifFunctionPtrType)0,

    /*Wait state configuration for Read access and error correction */
    (((uint32)FLS_WAIT_STATE_READACCESS9 << 6U) | 
      ((uint32)FLS_WAIT_STATE_ERRORCORRECTION1 << 12U) ),

    /*Flash access code address in RAM */ 
    (Fls_WriteCmdPtrType)(void*)&Fls_WriteCmdCycles,
    /*Flash access code address in RAM */
    (Fls_EraseCmdPtrType)(void*)&Fls_EraseCmdCycles,




/* Default mode of FLS driver */
MEMIF_MODE_FAST
  }
};


#define FLS_17_PMU_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

