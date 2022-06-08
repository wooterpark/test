/*******************************************************************************
** Copyright (C) Infineon Technologies (2015)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**  $FILENAME   : AppCbk.h $                                                 **
**                                                                            **
**  $CC VERSION : \main\19 $                                                 **
**                                                                            **
**  $DATE       : 2018-02-22 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  COMPILER  : Tasking, GNU, WindRiver                                                       **
**                                                                            **
**  AUTHOR    : SafeTlib Team                                                 **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY:                                                             **
**                                                                            **
**  DESCRIPTION  : This file contains support definitons used by AppCbk.c file                                         **
**                                                      **
**                                                                            **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: Yes                                      **
**                                                                            **
*******************************************************************************/

#ifndef APL_CBK_H
#define APL_CBK_H

/* To enable prints for debugging */
#define SAFETLIB_APPLN_DEBUG             TRUE

typedef uint32 ApplCbk_ErrorIdType;
/* Different error scenarios at different phases of SafeTlib */
#define APLCBK_PRERUN_INIT_FAIL         ((ApplCbk_ErrorIdType)0x00U)
#define APLCBK_SWDGM_INIT_FAIL          ((ApplCbk_ErrorIdType)0x01U)
#define APLCBK_SWDGIF_SERV_FAIL         ((ApplCbk_ErrorIdType)0x02U)
#define APLCBK_TSTM_INIT_FAIL           ((ApplCbk_ErrorIdType)0x03U)
#define APLCBK_POSTRUN_TST_FAIL         ((ApplCbk_ErrorIdType)0x04U)
#define APLCBK_WDG_SERV_FAIL            ((ApplCbk_ErrorIdType)0x05U)
#define APLCBK_WDG_DISABLE_STATE        ((ApplCbk_ErrorIdType)0x06U)
#define APLCBK_TST_MNG_FAIL             ((ApplCbk_ErrorIdType)0x07U)
#define APLCBK_RUNTIM_DTI_OVRSHOOT      ((ApplCbk_ErrorIdType)0x08U)
#define APLCBK_TST_SEED_CORPT           ((ApplCbk_ErrorIdType)0x09U)
#define APLCBK_NEW_SEED_FAIL            ((ApplCbk_ErrorIdType)0x0AU)
#define APLCBK_INV_SEEDSIG_FAIL         ((ApplCbk_ErrorIdType)0x0BU)
#define APLCBK_WDGIF_SERV_FAIL          ((ApplCbk_ErrorIdType)0x0CU)
#define APLCBK_SWDGIF_INIT_FAIL         ((ApplCbk_ErrorIdType)0x0DU)
#define APLCBK_SWDGIF_ACT_FAIL          ((ApplCbk_ErrorIdType)0x0EU)
#define APLCBK_SWDGIF_GTSED_FAIL        ((ApplCbk_ErrorIdType)0x0FU)
#define APLCBK_SMU_SET_ALARM_FAIL       ((ApplCbk_ErrorIdType)0x10U)
#define APLCBK_SL_INIT_FAIL             ((ApplCbk_ErrorIdType)0x11U)
#define APLCBK_WDGM_GET_SEED_FAIL       ((ApplCbk_ErrorIdType)0x12U)
#define APLCBK_SL_PRE_RUN_TST_FAIL      ((ApplCbk_ErrorIdType)0x13U)
#define APLCBK_SL_SWITCH_PHASE_FAIL     ((ApplCbk_ErrorIdType)0x14U)
#define APLCBK_TSTM_INV_SEED_SIG_FAIL   ((ApplCbk_ErrorIdType)0x15U)
#define APLCBK_SL_RUN_TST_FAIL          ((ApplCbk_ErrorIdType)0x16U)
#define APLCBK_SL_POST_RUN_TST_FAIL     ((ApplCbk_ErrorIdType)0x17U)
#define APLCBK_TSTM_INVALID_PHASE       ((ApplCbk_ErrorIdType)0x18U)
#define APLCBK_SWDGIF_GETSTATE_FAIL     ((ApplCbk_ErrorIdType)0x19U)
#define APLCBK_SL_EARLYPRE_RUN_TST_FAIL ((ApplCbk_ErrorIdType)0x1AU)
#define APLCBK_SWDGIF_CHMOD_FAIL        ((ApplCbk_ErrorIdType)0x1BU)
#define APLCBK_CIC_USRCMD_FAIL          ((ApplCbk_ErrorIdType)0x1CU)
#define APLCBK_SWDGM_REINIT_FAIL        ((ApplCbk_ErrorIdType)0x1DU)
#define APLCBK_ERR_INJ_FAIL             ((ApplCbk_ErrorIdType)0x1EU)
#define APLCBK_ERR_SPINLOCK_FAIL        ((ApplCbk_ErrorIdType)0x1FU)
#define APLCBK_ERR_TASK_BUDGET_OVRRUN   ((ApplCbk_ErrorIdType)0x20U)
#define APLCBK_CIC_TRIP_FAIL            ((ApplCbk_ErrorIdType)0x21U)
#define APLCBK_CIC_CYCLE_FAIL           ((ApplCbk_ErrorIdType)0x22U)
#define APLCBK_CIC_MAXJOBS_FAIL         ((ApplCbk_ErrorIdType)0x23U)
#define APLCBK_CIC_GETINFO_FAIL         ((ApplCbk_ErrorIdType)0x24U)
#define APLCBK_CIC_VERSION_FAIL         ((ApplCbk_ErrorIdType)0x25U)
#define APLCBK_WDG_SWITCHOFFTASK_FAIL   ((ApplCbk_ErrorIdType)0x26U)
#define APLCBK_WDG_INITCHKTASK_FAIL     ((ApplCbk_ErrorIdType)0x27U)
#define APLCBK_WDG_ACTIVATETASK_FAIL    ((ApplCbk_ErrorIdType)0x28U)
#define APLCBK_WDG_SPIERR_FAIL          ((ApplCbk_ErrorIdType)0x29U)
#define APLCBK_TLF_MAXJOBS_FAIL         ((ApplCbk_ErrorIdType)0x2AU)
#define APLCBK_TLF_ABIST_FAIL           ((ApplCbk_ErrorIdType)0x2BU)
#define APLCBK_CIC_SECSPI_FAIL          ((ApplCbk_ErrorIdType)0x2CU)

#define IFX_APPL_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/* prototype of AppCbk_ErrorHandler API */
extern void AppCbk_ErrorHandler(ApplCbk_ErrorIdType ErrorId);
#define IFX_APPL_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#endif
