/*
 * This is Os_Cfg.h, auto-generated for:
 *   Project: Os_Config
 *   Target:  TriCoreHighTec
 *   Variant: TC27xC
 *   Version: 5.0.21
 *   [$UKS 650]
 */
#ifndef OS_CFG_H
#define OS_CFG_H
/* -- Start expansion of <Os_Safe_Cfg.h> -- */
/* -- Start expansion of <Os_Target_Cfg.h> -- */
#define OS_TARGET_TRICOREHIGHTEC
#define OS_TRICORE_UNTRUSTED_MASK 0x1000U
#define OS_TRICORE_TRUSTEDWITHPROTECTION_MASK 0x2800U
#define OS_CAT1_TRACKER_DefaultInterruptHandler Os_RunningCat1ISR0
#define OS_CAT1_ID_DefaultInterruptHandler ((uint32)INVALID_ISR)
#define OS_INIT_SRC_GPSR02 (0x1401U)
#define OS_INIT_SRC_GPSR01 (0xc01U)
#define OS_INIT_SRC_GPSR00 (0x401U)
#define OS_INIT_SRC_STM0SR0 (0x402U)
#define OS_INIT_SRC_QSPI2ERR (0x403U)
#define OS_INIT_SRC_STM1SR0 (0x1404U)
#define OS_INIT_SRC_VADCG0SR1 (0x405U)
#define OS_INIT_SRC_VADCG1SR1 (0x406U)
#define OS_INIT_SRC_VADCG2SR1 (0x407U)
#define OS_INIT_SRC_VADCG3SR1 (0x408U)
#define OS_INIT_SRC_VADCG4SR1 (0x409U)
#define OS_INIT_SRC_VADCG5SR1 (0x40aU)
#define OS_INIT_SRC_DMACH30 (0x40bU)
#define OS_INIT_SRC_DMACH31 (0x40cU)
#define OS_INIT_SRC_GTMATOM32 (0x40dU)
#define OS_INIT_SRC_VADCG0SR0 (0x40eU)
#define OS_INIT_SRC_GTMTOM07 (0x140fU)
#define OS_INIT_SRC_DSADCSRM4 (0x410U)
#define OS_INIT_SRC_GTMATOM30 (0xc11U)
#define OS_INIT_SRC_GTMTOM01 (0xc12U)
#define OS_INIT_SRC_GTMTOM00 (0xc13U)
#define OS_INIT_SRC_GTMTOM26 (0xc14U)
#define OS_INIT_SRC_GTMTIM05 (0x1415U)
#define OS_INIT_SRC_SCUERU0 (0xc16U)
#define OS_VEC_Os_CrossCoreISR2 (1U)
#define OS_CORE_Os_CrossCoreISR2 (2U)
#define OS_VEC_Os_CrossCoreISR1 (1U)
#define OS_CORE_Os_CrossCoreISR1 (1U)
#define OS_VEC_Os_CrossCoreISR0 (1U)
#define OS_CORE_Os_CrossCoreISR0 (0U)
#define OS_VEC_SystemTimer_ISR (2U)
#define OS_CORE_SystemTimer_ISR (0U)
#define OS_VEC_QSPI2ERR_ISR (3U)
#define OS_CORE_QSPI2ERR_ISR (0U)
#define OS_VEC_STM_OsCounter_Core2 (4U)
#define OS_CORE_STM_OsCounter_Core2 (2U)
#define OS_VEC_ADC0SR1_ISR (5U)
#define OS_CORE_ADC0SR1_ISR (0U)
#define OS_VEC_ADC1SR1_ISR (6U)
#define OS_CORE_ADC1SR1_ISR (0U)
#define OS_VEC_ADC2SR1_ISR (7U)
#define OS_CORE_ADC2SR1_ISR (0U)
#define OS_VEC_ADC3SR1_ISR (8U)
#define OS_CORE_ADC3SR1_ISR (0U)
#define OS_VEC_ADC4SR1_ISR (9U)
#define OS_CORE_ADC4SR1_ISR (0U)
#define OS_VEC_ADC5SR1_ISR (10U)
#define OS_CORE_ADC5SR1_ISR (0U)
#define OS_VEC_DMACH30SR_ISR (11U)
#define OS_CORE_DMACH30SR_ISR (0U)
#define OS_VEC_DMACH31SR_ISR (12U)
#define OS_CORE_DMACH31SR_ISR (0U)
#define OS_VEC_GTMATOM3SR2_ISR (13U)
#define OS_CORE_GTMATOM3SR2_ISR (0U)
#define OS_VEC_ADC0SR0_ISR (14U)
#define OS_CORE_ADC0SR0_ISR (0U)
#define OS_VEC_GTMTOM0SR7_ISR (15U)
#define OS_CORE_GTMTOM0SR7_ISR (2U)
#define OS_VEC_DSADCSRM4_ISR (16U)
#define OS_CORE_DSADCSRM4_ISR (0U)
#define OS_VEC_WdgGptSrvISR (17U)
#define OS_CORE_WdgGptSrvISR (1U)
#define OS_VEC_GTMTOM0SR1_ISR (18U)
#define OS_CORE_GTMTOM0SR1_ISR (1U)
#define OS_VEC_GTMTOM0SR0_ISR (19U)
#define OS_CORE_GTMTOM0SR0_ISR (1U)
#define OS_VEC_GTMTOM2SR6_ISR (20U)
#define OS_CORE_GTMTOM2SR6_ISR (1U)
#define OS_VEC_GTMTIM0SR5_ISR (21U)
#define OS_CORE_GTMTIM0SR5_ISR (2U)
#define OS_VEC_SCUERUSR0_ISR (22U)
#define OS_CORE_SCUERUSR0_ISR (1U)
#define Os_Core0_SRN (SRC_GPSR00)
DECLARE_CAT1_ISR(Os_CrossCoreISR0);
#define Os_Core1_SRN (SRC_GPSR01)
DECLARE_CAT1_ISR(Os_CrossCoreISR1);
#define Os_Core2_SRN (SRC_GPSR02)
DECLARE_CAT1_ISR(Os_CrossCoreISR2);
#define OS_NUM_SRNS (465U)
DECLARE_CAT1_ISR(GTMTOM0SR1_ISR);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(GTMTOM0SR0_ISR);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(GTMTOM2SR6_ISR);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(GTMTIM0SR5_ISR);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(SCUERUSR0_ISR);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(NMI_Trap);  /* [$TargetHT 161] */
DECLARE_CAT1_ISR(DefaultInterruptHandler);

#define OS_CAT1_TRACKER_GTMTOM0SR1_ISR Os_RunningCat1ISR1
#define OS_CAT1_ID_GTMTOM0SR1_ISR (1U)
#define OS_CAT1_TRACKER_GTMTOM0SR0_ISR Os_RunningCat1ISR1
#define OS_CAT1_ID_GTMTOM0SR0_ISR (2U)
#define OS_CAT1_TRACKER_GTMTOM2SR6_ISR Os_RunningCat1ISR1
#define OS_CAT1_ID_GTMTOM2SR6_ISR (3U)
#define OS_CAT1_TRACKER_GTMTIM0SR5_ISR Os_RunningCat1ISR2
#define OS_CAT1_ID_GTMTIM0SR5_ISR (4U)
#define OS_CAT1_TRACKER_SCUERUSR0_ISR Os_RunningCat1ISR1
#define OS_CAT1_ID_SCUERUSR0_ISR (5U)
#define OS_CAT1_TRACKER_NMI_Trap Os_RunningCat1ISR0
#define OS_CAT1_ID_NMI_Trap (6U)

/* -- End expansion of <Os_Target_Cfg.h> -- */
#define OS_NUM_APPMODES (2U)
#define OS_NUM_APPLICATIONS (3U)
#define OS_NUM_SPINLOCKS (4U)
#define OS_NUM_TRUSTED_FUNCTIONS (0U)
#define OS_NUM_IOC_CALLBACK_FUNCTIONS (Os_const_ioc_function_count)
#define OS_NUM_EVENTS (2U)
#define OS_NUM_TASKS (34U)
#define OS_NUM_ISRS (16U)
#define OS_NUM_RESOURCES (2U)
#define OS_NUM_ALARMS (1U)
#define OS_NUM_SCHEDULETABLES (1U)
#define OS_NUM_PERIPHERALAREAS (0U)
#define OS_NUM_TRACEPOINTS (3U)
#define OS_NUM_TASKTRACEPOINTS (0U)
#define OS_NUM_INTERVALS (0U)
#define OS_NUM_TRACECATEGORIES (0U)
#define OS_TRACE_CATEGORY_ALWAYS ((Os_TraceCategoriesType)(0x80000000UL))
#define OS_TRACE_CATEGORY_NEVER  ((Os_TraceCategoriesType)(0x00000000UL))
/* [MISRA 2012 Dir 4.9] */ /*lint -estring(9026, OS_TICKS2*) */
#define OS_NUM_COUNTERS (3U)
#define OSCYCLEDURATION (5) /* [$UKS 1224] */
#define OSCYCLESPERSECOND (200000000U) /* [$UKS 1225] */
#define OSSWTICKDURATION (10) /* [$UKS 1226] */
#define OSSWTICKSPERSECOND (100000000U) /* [$UKS 1227] */
#define OS_TICKS2NS_Rte_TOutCounter(ticks) ((PhysicalTimeType)((ticks) * 1000000000U /* Default: SecondsPerTick not set */)) /* [$UKS 843] */
#define OS_TICKS2US_Rte_TOutCounter(ticks) ((PhysicalTimeType)((ticks) * 1000000U /* Default: SecondsPerTick not set */)) /* [$UKS 843] */
#define OS_TICKS2MS_Rte_TOutCounter(ticks) ((PhysicalTimeType)((ticks) * 1000U /* Default: SecondsPerTick not set */)) /* [$UKS 843] */
#define OS_TICKS2SEC_Rte_TOutCounter(ticks) ((PhysicalTimeType)((ticks) * 1U /* Default: SecondsPerTick not set */)) /* [$UKS 843] */
#define OSMAXALLOWEDVALUE_Rte_TOutCounter (65535U) /* [$UKS 219] */
#define OSTICKSPERBASE_Rte_TOutCounter (1U) /* [$UKS 220] */
#define OSTICKDURATION_Rte_TOutCounter OS_TICKS2NS_Rte_TOutCounter(1U) /* [$UKS 221] */
#define OSMINCYCLE_Rte_TOutCounter (1U) /* [$UKS 222] */
#define OS_TICKS2NS_Rte_TickCounter(ticks) ((PhysicalTimeType)((ticks) * 1000000U)) /* [$UKS 843] */
#define OS_TICKS2US_Rte_TickCounter(ticks) ((PhysicalTimeType)((ticks) * 1000U)) /* [$UKS 843] */
#define OS_TICKS2MS_Rte_TickCounter(ticks) ((PhysicalTimeType)((ticks) * 1U)) /* [$UKS 843] */
#define OS_TICKS2SEC_Rte_TickCounter(ticks) ((PhysicalTimeType)((ticks) / 1000U)) /* [$UKS 843] */
#define OSMAXALLOWEDVALUE_Rte_TickCounter (65535U) /* [$UKS 219] */
#define OSTICKSPERBASE_Rte_TickCounter (1U) /* [$UKS 220] */
#define OSTICKDURATION_Rte_TickCounter OS_TICKS2NS_Rte_TickCounter(1U) /* [$UKS 221] */
#define OSMINCYCLE_Rte_TickCounter (1U) /* [$UKS 222] */
#define OS_TICKS2NS_SystemTimer(ticks) ((PhysicalTimeType)((ticks) * 10U)) /* [$UKS 843] */
#define OS_TICKS2US_SystemTimer(ticks) ((PhysicalTimeType)((ticks) / 100U)) /* [$UKS 843] */
#define OS_TICKS2MS_SystemTimer(ticks) ((PhysicalTimeType)((ticks) / 100000U)) /* [$UKS 843] */
#define OS_TICKS2SEC_SystemTimer(ticks) ((PhysicalTimeType)((ticks) / 100000000U)) /* [$UKS 843] */
#define OSMAXALLOWEDVALUE_SystemTimer (4294967295U) /* [$UKS 219] */
#define OSTICKSPERBASE_SystemTimer (1U) /* [$UKS 220] */
#define OSTICKDURATION_SystemTimer OS_TICKS2NS_SystemTimer(1U) /* [$UKS 221] */
#define OSMINCYCLE_SystemTimer (1U) /* [$UKS 222] */
#define OSMAXALLOWEDVALUE OSMAXALLOWEDVALUE_SystemCounter /* [$UKS 215] */
#define OSTICKSPERBASE OSTICKSPERBASE_SystemCounter /* [$UKS 216] */
#define OSMINCYCLE OSMINCYCLE_SystemCounter /* [$UKS 218] */
#define OSTICKDURATION OSTICKDURATION_SystemCounter /* [$UKS 217] */
#define OS_NUM_CORES (3U)
#define OS_NUM_OS_CORES (3U)
#define OS_CORE_ID_MASTER (0U)  /* [$UKS 1609] */
/* [$UKS 1611] */
#define OS_CORE_ID_0 (0U)
#define OS_CORE_ID_1 (1U)
#define OS_CORE_ID_2 (2U)















































/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_CODE_LIB
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(StatusType, OS_CODE) Os_IncrementCounter_Rte_TOutCounter(void);
extern FUNC(StatusType, OS_CODE) Os_IncrementCounter_Rte_TickCounter(void);
extern FUNC(StatusType, OS_CODE) Os_AdvanceCounter_SystemTimer(void);
extern FUNC(void, OS_CODE) Os_Entry_BSW_Idle_Task_Core0(void);
extern FUNC(void, OS_CODE) Os_Entry_BSW_Idle_Task_Core1(void);
extern FUNC(void, OS_CODE) Os_Entry_BSW_Idle_Task_Core2(void);
extern FUNC(void, OS_CODE) Os_Entry_SWC_1000ms_Task_Core1(void);
extern FUNC(void, OS_CODE) Os_Entry_SWC_100ms_Task_Core1(void);
extern FUNC(void, OS_CODE) Os_Entry_SWC_50ms_Task_Core1(void);
extern FUNC(void, OS_CODE) Os_Entry_SWC_20ms_Task_Core1(void);
extern FUNC(void, OS_CODE) Os_Entry_SWC_10ms_Task_Core1(void);
extern FUNC(void, OS_CODE) Os_Entry_BSW_10ms_Task_Core1(void);
extern FUNC(void, OS_CODE) Os_Entry_SWC_5ms_Task_Core1(void);
extern FUNC(void, OS_CODE) Os_Entry_BSW_5ms_Task_Core1(void);
extern FUNC(void, OS_CODE) Os_Entry_SWC_1ms_Task_Core1(void);
extern FUNC(void, OS_CODE) Os_Entry_BSW_1ms_Task_Core1(void);
extern FUNC(void, OS_CODE) Os_Entry_SWC_1000ms_Task_Core0(void);
extern FUNC(void, OS_CODE) Os_Entry_SWC_100ms_Task_Core0(void);
extern FUNC(void, OS_CODE) Os_Entry_SWC_50ms_Task_Core0(void);
extern FUNC(void, OS_CODE) Os_Entry_SWC_20ms_Task_Core0(void);
extern FUNC(void, OS_CODE) Os_Entry_SWC_10ms_Task_Core0(void);
extern FUNC(void, OS_CODE) Os_Entry_BSW_10ms_Task_Core0(void);
extern FUNC(void, OS_CODE) Os_Entry_SWC_5ms_Task_Core0(void);
extern FUNC(void, OS_CODE) Os_Entry_BSW_5ms_Task_Core0(void);
extern FUNC(void, OS_CODE) Os_Entry_BSW_2ms_Task_Core0(void);
extern FUNC(void, OS_CODE) Os_Entry_SWC_1ms_Task_Core0(void);
extern FUNC(void, OS_CODE) Os_Entry_BSW_1ms_Task_Core0(void);
extern FUNC(void, OS_CODE) Os_Entry_BSW_10ms_Task_Core2(void);
extern FUNC(void, OS_CODE) Os_Entry_Os_Init_Task_Core2(void);
extern FUNC(void, OS_CODE) Os_Entry_Os_Init_Task_Core1(void);
extern FUNC(void, OS_CODE) Os_Entry_Os_Init_Task_Core0(void);
extern FUNC(void, OS_CODE) Os_Entry_BSW_Interact_Task_0_Core0(void);
extern FUNC(void, OS_CODE) Os_Entry_BSW_Interact_Task_0_Core1(void);
extern FUNC(void, OS_CODE) Os_Entry_BSW_Interact_Task_0_Core2(void);
extern FUNC(void, OS_CODE) Os_Entry_BSW_Interact_Task_1_Core0(void);
extern FUNC(void, OS_CODE) Os_Entry_BSW_Interact_Task_1_Core1(void);
extern FUNC(void, OS_CODE) Os_Entry_BSW_Interact_Task_1_Core2(void);
extern FUNC(void, OS_CODE) Os_Entry_SystemTimer_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_QSPI2ERR_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_STM_OsCounter_Core2(void);
extern FUNC(void, OS_CODE) Os_Entry_ADC0SR1_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_ADC1SR1_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_ADC2SR1_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_ADC3SR1_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_ADC4SR1_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_ADC5SR1_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_DMACH30SR_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_DMACH31SR_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_GTMATOM3SR2_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_ADC0SR0_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_GTMTOM0SR7_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_DSADCSRM4_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_WdgGptSrvISR(void);
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_CODE_LIB
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_CANCEL_SYSTEMTIMER_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_CANCEL_SYSTEMTIMER_CODE) Os_Cbk_Cancel_SystemTimer(void);
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_CANCEL_SYSTEMTIMER_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_DISABLE_ADC0SR0_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_DISABLE_ADC0SR0_ISR_CODE) Os_Cbk_Disable_ADC0SR0_ISR(void) /* [$UKS 1142] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_DISABLE_ADC0SR0_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_DISABLE_ADC0SR1_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_DISABLE_ADC0SR1_ISR_CODE) Os_Cbk_Disable_ADC0SR1_ISR(void) /* [$UKS 1142] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_DISABLE_ADC0SR1_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_DISABLE_ADC1SR1_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_DISABLE_ADC1SR1_ISR_CODE) Os_Cbk_Disable_ADC1SR1_ISR(void) /* [$UKS 1142] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_DISABLE_ADC1SR1_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_DISABLE_ADC2SR1_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_DISABLE_ADC2SR1_ISR_CODE) Os_Cbk_Disable_ADC2SR1_ISR(void) /* [$UKS 1142] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_DISABLE_ADC2SR1_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_DISABLE_ADC3SR1_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_DISABLE_ADC3SR1_ISR_CODE) Os_Cbk_Disable_ADC3SR1_ISR(void) /* [$UKS 1142] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_DISABLE_ADC3SR1_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_DISABLE_ADC4SR1_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_DISABLE_ADC4SR1_ISR_CODE) Os_Cbk_Disable_ADC4SR1_ISR(void) /* [$UKS 1142] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_DISABLE_ADC4SR1_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_DISABLE_ADC5SR1_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_DISABLE_ADC5SR1_ISR_CODE) Os_Cbk_Disable_ADC5SR1_ISR(void) /* [$UKS 1142] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_DISABLE_ADC5SR1_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_DISABLE_DMACH30SR_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_DISABLE_DMACH30SR_ISR_CODE) Os_Cbk_Disable_DMACH30SR_ISR(void) /* [$UKS 1142] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_DISABLE_DMACH30SR_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_DISABLE_DMACH31SR_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_DISABLE_DMACH31SR_ISR_CODE) Os_Cbk_Disable_DMACH31SR_ISR(void) /* [$UKS 1142] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_DISABLE_DMACH31SR_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_DISABLE_DSADCSRM4_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_DISABLE_DSADCSRM4_ISR_CODE) Os_Cbk_Disable_DSADCSRM4_ISR(void) /* [$UKS 1142] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_DISABLE_DSADCSRM4_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_DISABLE_GTMATOM3SR2_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_DISABLE_GTMATOM3SR2_ISR_CODE) Os_Cbk_Disable_GTMATOM3SR2_ISR(void) /* [$UKS 1142] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_DISABLE_GTMATOM3SR2_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_DISABLE_GTMTIM0SR5_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_DISABLE_GTMTIM0SR5_ISR_CODE) Os_Cbk_Disable_GTMTIM0SR5_ISR(void) /* [$UKS 1142] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_DISABLE_GTMTIM0SR5_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_DISABLE_GTMTOM0SR0_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_DISABLE_GTMTOM0SR0_ISR_CODE) Os_Cbk_Disable_GTMTOM0SR0_ISR(void) /* [$UKS 1142] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_DISABLE_GTMTOM0SR0_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_DISABLE_GTMTOM0SR1_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_DISABLE_GTMTOM0SR1_ISR_CODE) Os_Cbk_Disable_GTMTOM0SR1_ISR(void) /* [$UKS 1142] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_DISABLE_GTMTOM0SR1_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_DISABLE_GTMTOM0SR7_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_DISABLE_GTMTOM0SR7_ISR_CODE) Os_Cbk_Disable_GTMTOM0SR7_ISR(void) /* [$UKS 1142] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_DISABLE_GTMTOM0SR7_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_DISABLE_GTMTOM2SR6_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_DISABLE_GTMTOM2SR6_ISR_CODE) Os_Cbk_Disable_GTMTOM2SR6_ISR(void) /* [$UKS 1142] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_DISABLE_GTMTOM2SR6_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_DISABLE_NMI_TRAP_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_DISABLE_NMI_TRAP_CODE) Os_Cbk_Disable_NMI_Trap(void) /* [$UKS 1142] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_DISABLE_NMI_TRAP_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_DISABLE_QSPI2ERR_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_DISABLE_QSPI2ERR_ISR_CODE) Os_Cbk_Disable_QSPI2ERR_ISR(void) /* [$UKS 1142] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_DISABLE_QSPI2ERR_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_DISABLE_SCUERUSR0_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_DISABLE_SCUERUSR0_ISR_CODE) Os_Cbk_Disable_SCUERUSR0_ISR(void) /* [$UKS 1142] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_DISABLE_SCUERUSR0_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_DISABLE_STM_OSCOUNTER_CORE2_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_DISABLE_STM_OSCOUNTER_CORE2_CODE) Os_Cbk_Disable_STM_OsCounter_Core2(void) /* [$UKS 1142] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_DISABLE_STM_OSCOUNTER_CORE2_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_DISABLE_SYSTEMTIMER_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_DISABLE_SYSTEMTIMER_ISR_CODE) Os_Cbk_Disable_SystemTimer_ISR(void) /* [$UKS 1142] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_DISABLE_SYSTEMTIMER_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_DISABLE_WDGGPTSRVISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_DISABLE_WDGGPTSRVISR_CODE) Os_Cbk_Disable_WdgGptSrvISR(void) /* [$UKS 1142] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_DISABLE_WDGGPTSRVISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_NOW_SYSTEMTIMER_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(TickType, OS_OS_CBK_NOW_SYSTEMTIMER_CODE) Os_Cbk_Now_SystemTimer(void);
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_NOW_SYSTEMTIMER_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_SET_SYSTEMTIMER_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_SET_SYSTEMTIMER_CODE) Os_Cbk_Set_SystemTimer(TickType Match);
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_SET_SYSTEMTIMER_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_STATE_SYSTEMTIMER_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_STATE_SYSTEMTIMER_CODE) Os_Cbk_State_SystemTimer(Os_CounterStatusRefType State);
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_STATE_SYSTEMTIMER_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_TERMINATED_ADC0SR0_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_TERMINATED_ADC0SR0_ISR_CODE) Os_Cbk_Terminated_ADC0SR0_ISR(void) /* [$UKS 1281] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_TERMINATED_ADC0SR0_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_TERMINATED_ADC0SR1_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_TERMINATED_ADC0SR1_ISR_CODE) Os_Cbk_Terminated_ADC0SR1_ISR(void) /* [$UKS 1281] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_TERMINATED_ADC0SR1_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_TERMINATED_ADC1SR1_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_TERMINATED_ADC1SR1_ISR_CODE) Os_Cbk_Terminated_ADC1SR1_ISR(void) /* [$UKS 1281] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_TERMINATED_ADC1SR1_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_TERMINATED_ADC2SR1_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_TERMINATED_ADC2SR1_ISR_CODE) Os_Cbk_Terminated_ADC2SR1_ISR(void) /* [$UKS 1281] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_TERMINATED_ADC2SR1_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_TERMINATED_ADC3SR1_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_TERMINATED_ADC3SR1_ISR_CODE) Os_Cbk_Terminated_ADC3SR1_ISR(void) /* [$UKS 1281] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_TERMINATED_ADC3SR1_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_TERMINATED_ADC4SR1_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_TERMINATED_ADC4SR1_ISR_CODE) Os_Cbk_Terminated_ADC4SR1_ISR(void) /* [$UKS 1281] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_TERMINATED_ADC4SR1_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_TERMINATED_ADC5SR1_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_TERMINATED_ADC5SR1_ISR_CODE) Os_Cbk_Terminated_ADC5SR1_ISR(void) /* [$UKS 1281] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_TERMINATED_ADC5SR1_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_TERMINATED_DMACH30SR_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_TERMINATED_DMACH30SR_ISR_CODE) Os_Cbk_Terminated_DMACH30SR_ISR(void) /* [$UKS 1281] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_TERMINATED_DMACH30SR_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_TERMINATED_DMACH31SR_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_TERMINATED_DMACH31SR_ISR_CODE) Os_Cbk_Terminated_DMACH31SR_ISR(void) /* [$UKS 1281] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_TERMINATED_DMACH31SR_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_TERMINATED_DSADCSRM4_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_TERMINATED_DSADCSRM4_ISR_CODE) Os_Cbk_Terminated_DSADCSRM4_ISR(void) /* [$UKS 1281] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_TERMINATED_DSADCSRM4_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_TERMINATED_GTMATOM3SR2_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_TERMINATED_GTMATOM3SR2_ISR_CODE) Os_Cbk_Terminated_GTMATOM3SR2_ISR(void) /* [$UKS 1281] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_TERMINATED_GTMATOM3SR2_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_TERMINATED_GTMTOM0SR7_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_TERMINATED_GTMTOM0SR7_ISR_CODE) Os_Cbk_Terminated_GTMTOM0SR7_ISR(void) /* [$UKS 1281] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_TERMINATED_GTMTOM0SR7_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_TERMINATED_QSPI2ERR_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_TERMINATED_QSPI2ERR_ISR_CODE) Os_Cbk_Terminated_QSPI2ERR_ISR(void) /* [$UKS 1281] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_TERMINATED_QSPI2ERR_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_TERMINATED_STM_OSCOUNTER_CORE2_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_TERMINATED_STM_OSCOUNTER_CORE2_CODE) Os_Cbk_Terminated_STM_OsCounter_Core2(void) /* [$UKS 1281] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_TERMINATED_STM_OSCOUNTER_CORE2_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_TERMINATED_SYSTEMTIMER_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_TERMINATED_SYSTEMTIMER_ISR_CODE) Os_Cbk_Terminated_SystemTimer_ISR(void) /* [$UKS 1281] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_TERMINATED_SYSTEMTIMER_ISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_OS_CBK_TERMINATED_WDGGPTSRVISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_OS_CBK_TERMINATED_WDGGPTSRVISR_CODE) Os_Cbk_Terminated_WdgGptSrvISR(void) /* [$UKS 1281] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_OS_CBK_TERMINATED_WDGGPTSRVISR_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_SHUTDOWNHOOK_OSAPPCORE0_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_SHUTDOWNHOOK_OSAPPCORE0_CODE) ShutdownHook_OsAppCore0(StatusType Error) /* [$UKS 405] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_SHUTDOWNHOOK_OSAPPCORE0_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_SHUTDOWNHOOK_OSAPPCORE1_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_SHUTDOWNHOOK_OSAPPCORE1_CODE) ShutdownHook_OsAppCore1(StatusType Error) /* [$UKS 405] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_SHUTDOWNHOOK_OSAPPCORE1_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_STARTUPHOOK_OSAPPCORE0_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_STARTUPHOOK_OSAPPCORE0_CODE) StartupHook_OsAppCore0(void) /* [$UKS 401] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_STARTUPHOOK_OSAPPCORE0_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_STARTUPHOOK_OSAPPCORE1_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(void, OS_STARTUPHOOK_OSAPPCORE1_CODE) StartupHook_OsAppCore1(void) /* [$UKS 401] */;
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_STARTUPHOOK_OSAPPCORE1_CODE
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */

/* -- End expansion of <Os_Safe_Cfg.h> -- */
/* -------- Time Monitoring --------- */
#define OS_TIME_MONITORING  /* [$UKS 959] */
/* -------- Time Recording --------- */
#define OS_ELAPSED_TIME_RECORDING

/* -------- AppMode declarations --------- */

/* ----- OS-Application declarations ----- */
#define OsAppCore0 ((ApplicationType)1U) /* [$UKS 412] */
#define OsAppCore1 ((ApplicationType)2U) /* [$UKS 412] */
#define OsAppCore2 ((ApplicationType)3U) /* [$UKS 412] */

/* ----- PeripheralArea declarations ----- */

/* ----- Spinlock declarations ----- */
#define Os_Spinlock_Core0Core1 ((SpinlockIdType)1U)
#define Os_Spinlock_Core0Core1Core2 ((SpinlockIdType)2U)
#define Os_Spinlock_Core0Core2 ((SpinlockIdType)3U)
#define Os_Spinlock_Core1Core2 ((SpinlockIdType)4U)

/* -------- Event declarations --------- */
#define Rte_Activity (1U)
#define Rte_Timeout (2U)
DeclareEvent(Rte_Activity)
DeclareEvent(Rte_Timeout)

/* -------- Task declarations --------- */
#define BSW_Idle_Task_Core0 (&Os_const_tasks0[0])
#define OS_CORE_FOR_BSW_Idle_Task_Core0 (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_BSW_Idle_Task_Core0 (0U) /* [$UKS 2007] */
#define OS_IMASK_FOR_BSW_Idle_Task_Core0 (0x8000U) /* [$UKS 2009] */
DeclareTask(BSW_Idle_Task_Core0)
#define BSW_Idle_Task_Core1 (&Os_const_tasks1[0])
#define OS_CORE_FOR_BSW_Idle_Task_Core1 (1U) /* [$UKS 1909] */
#define OS_TPL_FOR_BSW_Idle_Task_Core1 (0U) /* [$UKS 2007] */
#define OS_IMASK_FOR_BSW_Idle_Task_Core1 (0x8000U) /* [$UKS 2009] */
DeclareTask(BSW_Idle_Task_Core1)
#define BSW_Idle_Task_Core2 (&Os_const_tasks2[0])
#define OS_CORE_FOR_BSW_Idle_Task_Core2 (2U) /* [$UKS 1909] */
#define OS_TPL_FOR_BSW_Idle_Task_Core2 (0U) /* [$UKS 2007] */
#define OS_IMASK_FOR_BSW_Idle_Task_Core2 (0x8000U) /* [$UKS 2009] */
DeclareTask(BSW_Idle_Task_Core2)
#define SWC_1000ms_Task_Core1 (&Os_const_tasks1[1])
#define OS_CORE_FOR_SWC_1000ms_Task_Core1 (1U) /* [$UKS 1909] */
#define OS_TPL_FOR_SWC_1000ms_Task_Core1 (1U) /* [$UKS 2007] */
#define OS_IMASK_FOR_SWC_1000ms_Task_Core1 (0x8000U) /* [$UKS 2009] */
DeclareTask(SWC_1000ms_Task_Core1)
#define SWC_100ms_Task_Core1 (&Os_const_tasks1[2])
#define OS_CORE_FOR_SWC_100ms_Task_Core1 (1U) /* [$UKS 1909] */
#define OS_TPL_FOR_SWC_100ms_Task_Core1 (2U) /* [$UKS 2007] */
#define OS_IMASK_FOR_SWC_100ms_Task_Core1 (0x8000U) /* [$UKS 2009] */
DeclareTask(SWC_100ms_Task_Core1)
#define SWC_50ms_Task_Core1 (&Os_const_tasks1[3])
#define OS_CORE_FOR_SWC_50ms_Task_Core1 (1U) /* [$UKS 1909] */
#define OS_TPL_FOR_SWC_50ms_Task_Core1 (3U) /* [$UKS 2007] */
#define OS_IMASK_FOR_SWC_50ms_Task_Core1 (0x8000U) /* [$UKS 2009] */
DeclareTask(SWC_50ms_Task_Core1)
#define SWC_20ms_Task_Core1 (&Os_const_tasks1[4])
#define OS_CORE_FOR_SWC_20ms_Task_Core1 (1U) /* [$UKS 1909] */
#define OS_TPL_FOR_SWC_20ms_Task_Core1 (4U) /* [$UKS 2007] */
#define OS_IMASK_FOR_SWC_20ms_Task_Core1 (0x8000U) /* [$UKS 2009] */
DeclareTask(SWC_20ms_Task_Core1)
#define SWC_10ms_Task_Core1 (&Os_const_tasks1[5])
#define OS_CORE_FOR_SWC_10ms_Task_Core1 (1U) /* [$UKS 1909] */
#define OS_TPL_FOR_SWC_10ms_Task_Core1 (5U) /* [$UKS 2007] */
#define OS_IMASK_FOR_SWC_10ms_Task_Core1 (0x8000U) /* [$UKS 2009] */
DeclareTask(SWC_10ms_Task_Core1)
#define BSW_10ms_Task_Core1 (&Os_const_tasks1[6])
#define OS_CORE_FOR_BSW_10ms_Task_Core1 (1U) /* [$UKS 1909] */
#define OS_TPL_FOR_BSW_10ms_Task_Core1 (6U) /* [$UKS 2007] */
#define OS_IMASK_FOR_BSW_10ms_Task_Core1 (0x8000U) /* [$UKS 2009] */
DeclareTask(BSW_10ms_Task_Core1)
#define SWC_5ms_Task_Core1 (&Os_const_tasks1[7])
#define OS_CORE_FOR_SWC_5ms_Task_Core1 (1U) /* [$UKS 1909] */
#define OS_TPL_FOR_SWC_5ms_Task_Core1 (7U) /* [$UKS 2007] */
#define OS_IMASK_FOR_SWC_5ms_Task_Core1 (0x8000U) /* [$UKS 2009] */
DeclareTask(SWC_5ms_Task_Core1)
#define BSW_5ms_Task_Core1 (&Os_const_tasks1[8])
#define OS_CORE_FOR_BSW_5ms_Task_Core1 (1U) /* [$UKS 1909] */
#define OS_TPL_FOR_BSW_5ms_Task_Core1 (8U) /* [$UKS 2007] */
#define OS_IMASK_FOR_BSW_5ms_Task_Core1 (0x8000U) /* [$UKS 2009] */
DeclareTask(BSW_5ms_Task_Core1)
#define SWC_1ms_Task_Core1 (&Os_const_tasks1[9])
#define OS_CORE_FOR_SWC_1ms_Task_Core1 (1U) /* [$UKS 1909] */
#define OS_TPL_FOR_SWC_1ms_Task_Core1 (9U) /* [$UKS 2007] */
#define OS_IMASK_FOR_SWC_1ms_Task_Core1 (0x8000U) /* [$UKS 2009] */
DeclareTask(SWC_1ms_Task_Core1)
#define BSW_1ms_Task_Core1 (&Os_const_tasks1[10])
#define OS_CORE_FOR_BSW_1ms_Task_Core1 (1U) /* [$UKS 1909] */
#define OS_TPL_FOR_BSW_1ms_Task_Core1 (10U) /* [$UKS 2007] */
#define OS_IMASK_FOR_BSW_1ms_Task_Core1 (0x8000U) /* [$UKS 2009] */
DeclareTask(BSW_1ms_Task_Core1)
#define SWC_1000ms_Task_Core0 (&Os_const_tasks0[1])
#define OS_CORE_FOR_SWC_1000ms_Task_Core0 (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_SWC_1000ms_Task_Core0 (1U) /* [$UKS 2007] */
#define OS_IMASK_FOR_SWC_1000ms_Task_Core0 (0x8000U) /* [$UKS 2009] */
DeclareTask(SWC_1000ms_Task_Core0)
#define SWC_100ms_Task_Core0 (&Os_const_tasks0[2])
#define OS_CORE_FOR_SWC_100ms_Task_Core0 (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_SWC_100ms_Task_Core0 (2U) /* [$UKS 2007] */
#define OS_IMASK_FOR_SWC_100ms_Task_Core0 (0x8000U) /* [$UKS 2009] */
DeclareTask(SWC_100ms_Task_Core0)
#define SWC_50ms_Task_Core0 (&Os_const_tasks0[3])
#define OS_CORE_FOR_SWC_50ms_Task_Core0 (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_SWC_50ms_Task_Core0 (3U) /* [$UKS 2007] */
#define OS_IMASK_FOR_SWC_50ms_Task_Core0 (0x8000U) /* [$UKS 2009] */
DeclareTask(SWC_50ms_Task_Core0)
#define SWC_20ms_Task_Core0 (&Os_const_tasks0[4])
#define OS_CORE_FOR_SWC_20ms_Task_Core0 (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_SWC_20ms_Task_Core0 (4U) /* [$UKS 2007] */
#define OS_IMASK_FOR_SWC_20ms_Task_Core0 (0x8000U) /* [$UKS 2009] */
DeclareTask(SWC_20ms_Task_Core0)
#define SWC_10ms_Task_Core0 (&Os_const_tasks0[5])
#define OS_CORE_FOR_SWC_10ms_Task_Core0 (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_SWC_10ms_Task_Core0 (5U) /* [$UKS 2007] */
#define OS_IMASK_FOR_SWC_10ms_Task_Core0 (0x8000U) /* [$UKS 2009] */
DeclareTask(SWC_10ms_Task_Core0)
#define BSW_10ms_Task_Core0 (&Os_const_tasks0[6])
#define OS_CORE_FOR_BSW_10ms_Task_Core0 (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_BSW_10ms_Task_Core0 (6U) /* [$UKS 2007] */
#define OS_IMASK_FOR_BSW_10ms_Task_Core0 (0x8000U) /* [$UKS 2009] */
DeclareTask(BSW_10ms_Task_Core0)
#define SWC_5ms_Task_Core0 (&Os_const_tasks0[7])
#define OS_CORE_FOR_SWC_5ms_Task_Core0 (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_SWC_5ms_Task_Core0 (7U) /* [$UKS 2007] */
#define OS_IMASK_FOR_SWC_5ms_Task_Core0 (0x8000U) /* [$UKS 2009] */
DeclareTask(SWC_5ms_Task_Core0)
#define BSW_5ms_Task_Core0 (&Os_const_tasks0[8])
#define OS_CORE_FOR_BSW_5ms_Task_Core0 (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_BSW_5ms_Task_Core0 (8U) /* [$UKS 2007] */
#define OS_IMASK_FOR_BSW_5ms_Task_Core0 (0x8000U) /* [$UKS 2009] */
DeclareTask(BSW_5ms_Task_Core0)
#define BSW_2ms_Task_Core0 (&Os_const_tasks0[9])
#define OS_CORE_FOR_BSW_2ms_Task_Core0 (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_BSW_2ms_Task_Core0 (9U) /* [$UKS 2007] */
#define OS_IMASK_FOR_BSW_2ms_Task_Core0 (0x8000U) /* [$UKS 2009] */
DeclareTask(BSW_2ms_Task_Core0)
#define SWC_1ms_Task_Core0 (&Os_const_tasks0[10])
#define OS_CORE_FOR_SWC_1ms_Task_Core0 (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_SWC_1ms_Task_Core0 (10U) /* [$UKS 2007] */
#define OS_IMASK_FOR_SWC_1ms_Task_Core0 (0x8000U) /* [$UKS 2009] */
DeclareTask(SWC_1ms_Task_Core0)
#define BSW_1ms_Task_Core0 (&Os_const_tasks0[11])
#define OS_CORE_FOR_BSW_1ms_Task_Core0 (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_BSW_1ms_Task_Core0 (11U) /* [$UKS 2007] */
#define OS_IMASK_FOR_BSW_1ms_Task_Core0 (0x8000U) /* [$UKS 2009] */
DeclareTask(BSW_1ms_Task_Core0)
#define BSW_10ms_Task_Core2 (&Os_const_tasks2[1])
#define OS_CORE_FOR_BSW_10ms_Task_Core2 (2U) /* [$UKS 1909] */
#define OS_TPL_FOR_BSW_10ms_Task_Core2 (1U) /* [$UKS 2007] */
#define OS_IMASK_FOR_BSW_10ms_Task_Core2 (0x8000U) /* [$UKS 2009] */
DeclareTask(BSW_10ms_Task_Core2)
#define Os_Init_Task_Core2 (&Os_const_tasks2[2])
#define OS_CORE_FOR_Os_Init_Task_Core2 (2U) /* [$UKS 1909] */
#define OS_TPL_FOR_Os_Init_Task_Core2 (2U) /* [$UKS 2007] */
#define OS_IMASK_FOR_Os_Init_Task_Core2 (0x8000U) /* [$UKS 2009] */
DeclareTask(Os_Init_Task_Core2)
#define Os_Init_Task_Core1 (&Os_const_tasks1[11])
#define OS_CORE_FOR_Os_Init_Task_Core1 (1U) /* [$UKS 1909] */
#define OS_TPL_FOR_Os_Init_Task_Core1 (11U) /* [$UKS 2007] */
#define OS_IMASK_FOR_Os_Init_Task_Core1 (0x8000U) /* [$UKS 2009] */
DeclareTask(Os_Init_Task_Core1)
#define Os_Init_Task_Core0 (&Os_const_tasks0[12])
#define OS_CORE_FOR_Os_Init_Task_Core0 (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_Os_Init_Task_Core0 (12U) /* [$UKS 2007] */
#define OS_IMASK_FOR_Os_Init_Task_Core0 (0x8000U) /* [$UKS 2009] */
DeclareTask(Os_Init_Task_Core0)
#define BSW_Interact_Task_0_Core0 (&Os_const_tasks0[13])
#define OS_CORE_FOR_BSW_Interact_Task_0_Core0 (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_BSW_Interact_Task_0_Core0 (13U) /* [$UKS 2007] */
#define OS_IMASK_FOR_BSW_Interact_Task_0_Core0 (0x8000U) /* [$UKS 2009] */
DeclareTask(BSW_Interact_Task_0_Core0)
#define BSW_Interact_Task_0_Core1 (&Os_const_tasks1[12])
#define OS_CORE_FOR_BSW_Interact_Task_0_Core1 (1U) /* [$UKS 1909] */
#define OS_TPL_FOR_BSW_Interact_Task_0_Core1 (12U) /* [$UKS 2007] */
#define OS_IMASK_FOR_BSW_Interact_Task_0_Core1 (0x8000U) /* [$UKS 2009] */
DeclareTask(BSW_Interact_Task_0_Core1)
#define BSW_Interact_Task_0_Core2 (&Os_const_tasks2[3])
#define OS_CORE_FOR_BSW_Interact_Task_0_Core2 (2U) /* [$UKS 1909] */
#define OS_TPL_FOR_BSW_Interact_Task_0_Core2 (3U) /* [$UKS 2007] */
#define OS_IMASK_FOR_BSW_Interact_Task_0_Core2 (0x8000U) /* [$UKS 2009] */
DeclareTask(BSW_Interact_Task_0_Core2)
#define BSW_Interact_Task_1_Core0 (&Os_const_tasks0[14])
#define OS_CORE_FOR_BSW_Interact_Task_1_Core0 (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_BSW_Interact_Task_1_Core0 (14U) /* [$UKS 2007] */
#define OS_IMASK_FOR_BSW_Interact_Task_1_Core0 (0x8000U) /* [$UKS 2009] */
DeclareTask(BSW_Interact_Task_1_Core0)
#define BSW_Interact_Task_1_Core1 (&Os_const_tasks1[13])
#define OS_CORE_FOR_BSW_Interact_Task_1_Core1 (1U) /* [$UKS 1909] */
#define OS_TPL_FOR_BSW_Interact_Task_1_Core1 (13U) /* [$UKS 2007] */
#define OS_IMASK_FOR_BSW_Interact_Task_1_Core1 (0x8000U) /* [$UKS 2009] */
DeclareTask(BSW_Interact_Task_1_Core1)
#define BSW_Interact_Task_1_Core2 (&Os_const_tasks2[4])
#define OS_CORE_FOR_BSW_Interact_Task_1_Core2 (2U) /* [$UKS 1909] */
#define OS_TPL_FOR_BSW_Interact_Task_1_Core2 (4U) /* [$UKS 2007] */
#define OS_IMASK_FOR_BSW_Interact_Task_1_Core2 (0x8000U) /* [$UKS 2009] */
DeclareTask(BSW_Interact_Task_1_Core2)
/* [MISRA 2012 Dir 4.9] */ /*lint -estring(9026, OS_TPL_FOR_TASK, OS_IMASK_FOR_TASK) */
/* [MISRA 2012 Rule 20.10] */ /*lint -estring(9024, OS_TPL_FOR_TASK) */
#define OS_TPL_FOR_TASK(n) OS_TPL_FOR_##n  /* [$UKS 2008] */
/* [MISRA 2012 Rule 20.10] */ /*lint -estring(9024, OS_IMASK_FOR_TASK) */
#define OS_IMASK_FOR_TASK(n) OS_IMASK_FOR_##n  /* [$UKS 2010] */
/* [MISRA 2012 Dir 4.9] */ /*lint -estring(9026, OS_CORE_FOR_TASK) */
#define OS_CORE_FOR_TASK(t) (t)->core_id /* [$UKS 1921] */

/* -------- ISR declarations --------- */
#define SystemTimer_ISR (&Os_const_isrs[0U])
#define OS_IMASK_FOR_SystemTimer_ISR (0x8002U) /* [$UKS 2009] */
#define OS_CORE_FOR_SystemTimer_ISR (0U) /* [$UKS 1909] */
DeclareISR(SystemTimer_ISR)
#define QSPI2ERR_ISR (&Os_const_isrs[1U])
#define OS_IMASK_FOR_QSPI2ERR_ISR (0x8003U) /* [$UKS 2009] */
#define OS_CORE_FOR_QSPI2ERR_ISR (0U) /* [$UKS 1909] */
DeclareISR(QSPI2ERR_ISR)
#define STM_OsCounter_Core2 (&Os_const_isrs[2U])
#define OS_IMASK_FOR_STM_OsCounter_Core2 (0x8004U) /* [$UKS 2009] */
#define OS_CORE_FOR_STM_OsCounter_Core2 (2U) /* [$UKS 1909] */
DeclareISR(STM_OsCounter_Core2)
#define ADC0SR1_ISR (&Os_const_isrs[3U])
#define OS_IMASK_FOR_ADC0SR1_ISR (0x8005U) /* [$UKS 2009] */
#define OS_CORE_FOR_ADC0SR1_ISR (0U) /* [$UKS 1909] */
DeclareISR(ADC0SR1_ISR)
#define ADC1SR1_ISR (&Os_const_isrs[4U])
#define OS_IMASK_FOR_ADC1SR1_ISR (0x8006U) /* [$UKS 2009] */
#define OS_CORE_FOR_ADC1SR1_ISR (0U) /* [$UKS 1909] */
DeclareISR(ADC1SR1_ISR)
#define ADC2SR1_ISR (&Os_const_isrs[5U])
#define OS_IMASK_FOR_ADC2SR1_ISR (0x8007U) /* [$UKS 2009] */
#define OS_CORE_FOR_ADC2SR1_ISR (0U) /* [$UKS 1909] */
DeclareISR(ADC2SR1_ISR)
#define ADC3SR1_ISR (&Os_const_isrs[6U])
#define OS_IMASK_FOR_ADC3SR1_ISR (0x8008U) /* [$UKS 2009] */
#define OS_CORE_FOR_ADC3SR1_ISR (0U) /* [$UKS 1909] */
DeclareISR(ADC3SR1_ISR)
#define ADC4SR1_ISR (&Os_const_isrs[7U])
#define OS_IMASK_FOR_ADC4SR1_ISR (0x8009U) /* [$UKS 2009] */
#define OS_CORE_FOR_ADC4SR1_ISR (0U) /* [$UKS 1909] */
DeclareISR(ADC4SR1_ISR)
#define ADC5SR1_ISR (&Os_const_isrs[8U])
#define OS_IMASK_FOR_ADC5SR1_ISR (0x800AU) /* [$UKS 2009] */
#define OS_CORE_FOR_ADC5SR1_ISR (0U) /* [$UKS 1909] */
DeclareISR(ADC5SR1_ISR)
#define DMACH30SR_ISR (&Os_const_isrs[9U])
#define OS_IMASK_FOR_DMACH30SR_ISR (0x800BU) /* [$UKS 2009] */
#define OS_CORE_FOR_DMACH30SR_ISR (0U) /* [$UKS 1909] */
DeclareISR(DMACH30SR_ISR)
#define DMACH31SR_ISR (&Os_const_isrs[10U])
#define OS_IMASK_FOR_DMACH31SR_ISR (0x800CU) /* [$UKS 2009] */
#define OS_CORE_FOR_DMACH31SR_ISR (0U) /* [$UKS 1909] */
DeclareISR(DMACH31SR_ISR)
#define GTMATOM3SR2_ISR (&Os_const_isrs[11U])
#define OS_IMASK_FOR_GTMATOM3SR2_ISR (0x800DU) /* [$UKS 2009] */
#define OS_CORE_FOR_GTMATOM3SR2_ISR (0U) /* [$UKS 1909] */
DeclareISR(GTMATOM3SR2_ISR)
#define ADC0SR0_ISR (&Os_const_isrs[12U])
#define OS_IMASK_FOR_ADC0SR0_ISR (0x800EU) /* [$UKS 2009] */
#define OS_CORE_FOR_ADC0SR0_ISR (0U) /* [$UKS 1909] */
DeclareISR(ADC0SR0_ISR)
#define GTMTOM0SR7_ISR (&Os_const_isrs[13U])
#define OS_IMASK_FOR_GTMTOM0SR7_ISR (0x800FU) /* [$UKS 2009] */
#define OS_CORE_FOR_GTMTOM0SR7_ISR (2U) /* [$UKS 1909] */
DeclareISR(GTMTOM0SR7_ISR)
#define DSADCSRM4_ISR (&Os_const_isrs[14U])
#define OS_IMASK_FOR_DSADCSRM4_ISR (0x8010U) /* [$UKS 2009] */
#define OS_CORE_FOR_DSADCSRM4_ISR (0U) /* [$UKS 1909] */
DeclareISR(DSADCSRM4_ISR)
#define WdgGptSrvISR (&Os_const_isrs[15U])
#define OS_IMASK_FOR_WdgGptSrvISR (0x8011U) /* [$UKS 2009] */
#define OS_CORE_FOR_WdgGptSrvISR (1U) /* [$UKS 1909] */
DeclareISR(WdgGptSrvISR)
/* [MISRA 2012 Dir 4.9] */ /*lint -estring(9026, OS_CORE_FOR_ISR) */
/* [MISRA 2012 Rule 20.10] */ /*lint -estring(9024, OS_CORE_FOR_ISR) */
#define OS_CORE_FOR_ISR(i) OS_CORE_FOR_##i /* [$UKS 1922] */
/* [MISRA 2012 Dir 4.9] */ /*lint -estring(9026, OS_IMASK_FOR_ISR) */
/* [MISRA 2012 Rule 20.10] */ /*lint -estring(9024, OS_IMASK_FOR_ISR) */
#define OS_IMASK_FOR_ISR(n) OS_IMASK_FOR_##n  /* [$UKS 2011] */

/* -------- Resource declarations --------- */
#define RTE_RESOURCE (&Os_const_resources[0U])
DeclareResource(RTE_RESOURCE)
#define Rte_EA_BSWImpl4_CanTp_EXCLUSIVE_AREA (&Os_const_resources[1U])
DeclareResource(Rte_EA_BSWImpl4_CanTp_EXCLUSIVE_AREA)

/* -------- Counter declarations --------- */
#define Rte_TOutCounter (&Os_const_counters[0U])
DeclareCounter(Rte_TOutCounter)
#define Rte_TickCounter (&Os_const_counters[1U])
DeclareCounter(Rte_TickCounter)
#define SystemTimer (&Os_const_counters[2U])
DeclareCounter(SystemTimer)

/* -------- Alarm declaration --------- */
#define Rte_TimeoutAlarm1 (0U)
DeclareAlarm(Rte_TimeoutAlarm1)

/* -------- ScheduleTable declaration --------- */
#define Rte_ScheduleTable (&Os_const_scheduletables[0U])
#define OS_DURATION_Rte_ScheduleTable (1000000U)
DeclareScheduleTable(Rte_ScheduleTable)

/* -------- Tracepoint declarations --------- */
#define OSApp_OsAppCore0 (1U)
#define OSApp_OsAppCore1 (2U)
#define OSApp_OsAppCore2 (3U)

/* -------- TaskTracepoint declarations --------- */

/* -------- Interval declarations --------- */

/* -------- Filtered APIs --------- */
#define Os_LogTracepoint(TpointID,Category) /* never */
#define Os_LogTracepointValue(TpointID,Value,Category) /* never */
#define Os_LogTracepointData(TpointID,Data,Length,Category) /* never */
#define Os_LogTaskTracepoint(TTpointID,Category) /* never */
#define Os_LogTaskTracepointValue(TTpointID,Value,Category) /* never */
#define Os_LogTaskTracepointData(TTpointID,Data,Length,Category) /* never */
#define Os_LogIntervalStart(IntervalID,Category) /* never */
#define Os_LogIntervalStartValue(IntervalID,Value,Category) /* never */
#define Os_LogIntervalStartData(IntervalID,Data,Length,Category) /* never */
#define Os_LogIntervalEnd(IntervalID,Category) /* never */
#define Os_LogIntervalEndValue(IntervalID,Value,Category) /* never */
#define Os_LogIntervalEndData(IntervalID,Data,Length,Category) /* never */
#ifndef OS_TRACE_NAMESPACE_PURE /* [$UKS 1154] */
/* [MISRA 2012 Dir 4.9] */ /*lint -estring(9026, LogTrace*, LogTaskTrace*, LogInterval*) */  #define LogTracepoint(TpointID,Category) Os_LogTracepoint(TpointID,Category)
  #define LogTracepointValue(TpointID,Value,Category) Os_LogTracepointValue(TpointID,Value,Category)
  #define LogTracepointData(TpointID,Data,Length,Category) Os_LogTracepointData(TpointID,Data,Length,Category)
  #define LogTaskTracepoint(TTpointID,Category) Os_LogTaskTracepoint(TTpointID,Category)
  #define LogTaskTracepointValue(TTpointID,Value,Category) Os_LogTaskTracepointValue(TTpointID,Value,Category)
  #define LogTaskTracepointData(TTpointID,Data,Length,Category) Os_LogTaskTracepointData(TTpointID,Data,Length,Category)
  #define LogIntervalStart(IntervalID,Category) Os_LogIntervalStart(IntervalID,Category)
  #define LogIntervalStartValue(IntervalID,Value,Category) Os_LogIntervalStartValue(IntervalID,Value,Category)
  #define LogIntervalStartData(IntervalID,Data,Length,Category) Os_LogIntervalStartData(IntervalID,Data,Length,Category)
  #define LogIntervalEnd(IntervalID,Category) Os_LogIntervalEnd(IntervalID,Category)
  #define LogIntervalEndValue(IntervalID,Value,Category) Os_LogIntervalEndValue(IntervalID,Value,Category)
  #define LogIntervalEndData(IntervalID,Data,Length,Category) Os_LogIntervalEndData(IntervalID,Data,Length,Category)
#endif

#define OS_IMASK_FOR_GTMTOM0SR1_ISR (0x8012U) /* [$UKS 2009] */
#define Os_Cat1_GTMTOM0SR1_ISR (52U)
#define OS_CORE_FOR_GTMTOM0SR1_ISR (1U) /* [$UKS 1909] */
#define OS_IMASK_FOR_GTMTOM0SR0_ISR (0x8013U) /* [$UKS 2009] */
#define Os_Cat1_GTMTOM0SR0_ISR (53U)
#define OS_CORE_FOR_GTMTOM0SR0_ISR (1U) /* [$UKS 1909] */
#define OS_IMASK_FOR_GTMTOM2SR6_ISR (0x8014U) /* [$UKS 2009] */
#define Os_Cat1_GTMTOM2SR6_ISR (54U)
#define OS_CORE_FOR_GTMTOM2SR6_ISR (1U) /* [$UKS 1909] */
#define OS_IMASK_FOR_GTMTIM0SR5_ISR (0x8015U) /* [$UKS 2009] */
#define Os_Cat1_GTMTIM0SR5_ISR (55U)
#define OS_CORE_FOR_GTMTIM0SR5_ISR (2U) /* [$UKS 1909] */
#define OS_IMASK_FOR_SCUERUSR0_ISR (0x8016U) /* [$UKS 2009] */
#define Os_Cat1_SCUERUSR0_ISR (56U)
#define OS_CORE_FOR_SCUERUSR0_ISR (1U) /* [$UKS 1909] */
#define OS_IMASK_FOR_NMI_Trap (0x80FFU) /* [$UKS 2009] */
#define Os_Cat1_NMI_Trap (57U)
#define OS_CORE_FOR_NMI_Trap (0U) /* [$UKS 1909] */
/* [MISRA 2012 Rule 1.3] */ /*lint -estring(9023, Os_LogCat1ISRStart) */
/* [MISRA 2012 Rule 20.10] */ /*lint -esym(9024, Os_LogCat1ISRStart) */
#define Os_LogCat1ISRStart(IsrId)  /* [$UKS 1036] [$UKS 1037] [$UKS 1177] */
/* [MISRA 2012 Rule 1.3] */ /*lint -estring(9023, Os_LogCat1ISREnd) */
/* [MISRA 2012 Rule 20.10] */ /*lint -esym(9024, Os_LogCat1ISREnd) */
#define Os_LogCat1ISREnd(IsrId)  /* [$UKS 1038] [$UKS 1039] [$UKS 1178] */

#ifndef OS_TRACE_NAMESPACE_PURE /* [$UKS 1154] */
  #define LogCat1ISRStart Os_LogCat1ISRStart
  #define LogCat1ISREnd Os_LogCat1ISREnd
#endif
#endif /* OS_CFG_H */
