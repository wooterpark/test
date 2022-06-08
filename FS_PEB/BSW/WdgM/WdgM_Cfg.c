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
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "WdgM.h"
#include "Os.h"
#if (!defined(OS_AR_RELEASE_MAJOR_VERSION) || (OS_AR_RELEASE_MAJOR_VERSION != 4))
#error “AUTOSAR major version undefined or mismatched?
#endif
#if (!defined(OS_AR_RELEASE_MINOR_VERSION) || (OS_AR_RELEASE_MINOR_VERSION != 2))
#error “AUTOSAR minor version undefined or mismatched?
#endif
#include "WdgM_Prv.h"

/*
 ***************************************************************************************************
 * Variables
 ***************************************************************************************************
 */


#define WDGM_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
#include "WdgM_Cfg_MemMap.h"
#ifdef WDGM_DBG_TST_ENA
VAR(TickType, WDGM_VAR_FAST_CLEARED_UNSPECIFIED)  WdgM_RunningCounterValue[WDGM_MAX_DEADLINE_SUPERVISIONS];
#else
static VAR(TickType, WDGM_VAR_FAST_CLEARED_UNSPECIFIED) WdgM_RunningCounterValue[WDGM_MAX_DEADLINE_SUPERVISIONS];
#endif
#define WDGM_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
#include "WdgM_Cfg_MemMap.h"

#define WDGM_START_SEC_VAR_FAST_CLEARED_16
#include "WdgM_Cfg_MemMap.h"
#ifdef WDGM_DBG_TST_ENA
VAR(uint16, WDGM_VAR_FAST_CLEARED_16) WdgM_DeadlineIndices[2];
#else
static VAR(uint16, WDGM_VAR_FAST_CLEARED_16) WdgM_DeadlineIndices[2];
#endif
#define WDGM_STOP_SEC_VAR_FAST_CLEARED_16
#include "WdgM_Cfg_MemMap.h"



/*
 ***************************************************************************************************
 * Dynamic Variables
 ***************************************************************************************************
 */
#define WDGM_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
#include "WdgM_Cfg_MemMap.h"
/* TRACE[WDGM200] Values of local supervsion should be described in WdgM_LocalStatusType */
VAR(WdgM_SupervisedEntityDynType, WDGM_VAR_FAST_CLEARED_UNSPECIFIED) WdgM_SupervisedEntityDyn[2];  /* WDGM242 */
static VAR(WdgM_CheckpointDynType, WDGM_VAR_FAST_CLEARED_UNSPECIFIED) WdgM_CheckpointDyn[6];
#define WDGM_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
#include "WdgM_Cfg_MemMap.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/

#define WDGM_START_SEC_CONFIG_DATA_FAST_UNSPECIFIED
#include "WdgM_Cfg_MemMap.h"


CONST(WdgM_CheckpointType, WDGM_CONST_FAST_UNSPECIFIED) WdgM_Checkpoint[6] =
{	
	/* PtrToCheckpointDyn                          Comment */ 
	
	{   &WdgM_CheckpointDyn[0]                       /* WdgMSupervisedEntityId: 0, WdgMCheckpointId: 0 */        },
	{   &WdgM_CheckpointDyn[1]                       /* WdgMSupervisedEntityId: 0, WdgMCheckpointId: 1 */        },	
	{   &WdgM_CheckpointDyn[2]                       /* WdgMSupervisedEntityId: 1, WdgMCheckpointId: 0 */        },
	{   &WdgM_CheckpointDyn[3]                       /* WdgMSupervisedEntityId: 1, WdgMCheckpointId: 1 */        },
	{   &WdgM_CheckpointDyn[4]                       /* WdgMSupervisedEntityId: 1, WdgMCheckpointId: 2 */        },
	{   &WdgM_CheckpointDyn[5]                       /* WdgMSupervisedEntityId: 1, WdgMCheckpointId: 3 */        }
};


CONST(WdgM_SupervisedEntityType, WDGM_CONST_FAST_UNSPECIFIED) WdgM_SupervisedEntity[2]=
{	
    /* NoOfCheckpoint             PartionEnabled             TimerId                                        OsApplicationId                                PtrToCheckpoint                                PtrToSupervisedEntityDyn                        hasInternalGraph           idxInternalGraphCPProperty                       Comment */         
    
    {  2                        ,  FALSE                    ,  SystemTimer                                  ,  INVALID_OSAPPLICATION                        ,  &WdgM_Checkpoint[0]                          ,   &WdgM_SupervisedEntityDyn[0]                 ,  FALSE                    ,  0                            /* WdgMSupervisedEntityId: 0 */              },
    {  4                        ,  FALSE                    ,  WDGM_INVALID_TIMER_ID                        ,  INVALID_OSAPPLICATION                        ,  &WdgM_Checkpoint[2]                          ,   &WdgM_SupervisedEntityDyn[1]                 ,  TRUE                     ,  0                            /* WdgMSupervisedEntityId: 1 */              }
};

CONST(WdgM_InternalGraph_CPPropertyType, WDGM_CONST_FAST_UNSPECIFIED) WdgM_InternalGraph_CPProperty[4]=
{   
    /* PosinInternalGraph           noofdestCP                      idxofdestCP                     Comment */           
    
    {  WDGM_POSNGRAPH_INITIAL_E      , 1                             , 0                             /* WdgMSupervisedEntityId: 1, WdgMCheckpointId: 0 */        } ,
    {  WDGM_POSNGRAPH_INTERMEDIATE_E , 1                             , 1                             /* WdgMSupervisedEntityId: 1, WdgMCheckpointId: 1 */        } ,
    {  WDGM_POSNGRAPH_INTERMEDIATE_E , 1                             , 2                             /* WdgMSupervisedEntityId: 1, WdgMCheckpointId: 2 */        } ,
    {  WDGM_POSNGRAPH_FINAL_E        , 0                             , 0                             /* WdgMSupervisedEntityId: 1, WdgMCheckpointId: 3 */        } 
};

CONST(WdgM_CheckpointIdType,WDGM_CONST_FAST_UNSPECIFIED)WdgM_InternalGraph_DestCheckpoints[3]=
{   
    /* DestCPID                           Comment */ 
    1                             ,/* WdgMSupervisedEntityId: 1, WdgMSourceCheckpointId: 0 */   
    2                             ,/* WdgMSupervisedEntityId: 1, WdgMSourceCheckpointId: 1 */   
    3                              /* WdgMSupervisedEntityId: 1, WdgMSourceCheckpointId: 2 */    
};
CONST(WdgM_AliveSupervisionType, WDGM_CONST_FAST_UNSPECIFIED) WdgM_AliveSupervision[1] =
{
    /* MinMargin          MaxMargin                  AliveSupervisionCheckpointId     SupervisedEntityId              ExpectedAliveIndications   SupervisionReferenceCycle   Comment */ 
   
    {   1                   ,  1                   ,  0                              ,  0                             ,  9                       ,  10                       /* WdgMMode: 1  AliveSuperVision: WdgMAliveSE_Core0_10ms */                     }
};


CONST(WdgM_DeadlineSupervisionType, WDGM_CONST_FAST_UNSPECIFIED) WdgM_DeadlineSupervision[1] =
{
    /* StartCheckpointId                StopCheckpointId                 SupervisedEntityId(WDGM313)     DeadlineMin(in Counter ticks)   DeadlineMax(in Counter ticks)   Comment */                                    
	
    {   1                              ,  1                              ,  0                             ,  50000                        ,  190000                       /* WdgMMode: 1  DeadlineSuperVision: WdgMDeadlineSupervision */                 }        
};


CONST(WdgM_LocalStatusParamsType, WDGM_CONST_FAST_UNSPECIFIED) WdgM_LocalStatusParams[2] =
{
    /* FailedAliveSupervisionRefCycleTol               SupervisedEntityId                              Comment */                                    
    
    {   0                                            ,  0                                              /* WdgMMode: 1  WdgMLocalStatusParams: WdgMLocalStatusParams */                 },
    {   0                                            ,  1                                              /* WdgMMode: 1  WdgMLocalStatusParams: WdgMLocalStatusParams_0 */               }  
};


CONST(WdgM_TriggerType, WDGM_CONST_FAST_UNSPECIFIED) WdgM_Trigger[1] =
{
    /* TriggerConditionValue(in mili seconds)          DeviceIdx                                       TriggerModeType             Comment */                                    
    
    {   100                                          ,  WdgIfConf_WdgIfDevice_WdgIfExtDev            ,  WDGIF_FAST_MODE            /* WdgMMode: 1  WdgMTrigger: WdgMTrigger_ExtDog */                              } 
};


CONST(WdgM_PrvModeType, WDGM_CONST_FAST_UNSPECIFIED) WdgM_PrvMode[3] =
{	    /* ExpiredSupervisionCycleTol                    SupervisionCycle(in mili seconds)               NoOfAliveSupervision                            NoOfDeadlineSupervision                         NoOfLocalStatusParams                           NoOfTrigger                                     PtrToAliveSupervision                           PtrToDeadlineSupervision                        PtrToLocalStatusParams                          PtrToTrigger                                    Comment */                                    
    
    {   0                                            ,  WDGM_SUPERVISION_CYCLE_0                     ,  0                                            ,  0                                            ,  0                                            ,  0                                            ,  NULL_PTR                                     ,  NULL_PTR                                     ,  NULL_PTR                                     ,  NULL_PTR                                       /* WdgMMode: WdgMMode_Init */                },
    {   0                                            ,  WDGM_SUPERVISION_CYCLE_0                     ,  1                                            ,  1                                            ,  2                                            ,  1                                            ,  &WdgM_AliveSupervision[0]                    ,  &WdgM_DeadlineSupervision[0]                 ,  &WdgM_LocalStatusParams[0]                   ,  &WdgM_Trigger[0]                               /* WdgMMode: WdgMMode_Run */                 },
    {   0                                            ,  WDGM_SUPERVISION_CYCLE_0                     ,  0                                            ,  0                                            ,  0                                            ,  0                                            ,  NULL_PTR                                     ,  NULL_PTR                                     ,  NULL_PTR                                     ,  NULL_PTR                                       /* WdgMMode: WdgMMode_Sleep */               }
};

CONST(WdgM_ConfigType, WDGM_CONST_FAST_UNSPECIFIED)  WdgM_Config =
{
    0                                                           , /* InitialMode */
    3                                                           , /* NoOfMode */
    WDGM_INVALID_DEM_EVENT_ID                                   , /* ErrorImproperCaller */
    WDGM_INVALID_DEM_EVENT_ID                                   , /* ErrorSupervision */
    WDGM_INVALID_DEM_EVENT_ID                                   , /* ErrorSetMode */
    &WdgM_RunningCounterValue[0]                                , /* PtrToRunningCounterValue */
    &WdgM_DeadlineIndices[0]                                    , /* PtrToDeadlineIndices */
    &WdgM_PrvMode[0]                                              /* PtrToMode */
};


#define      WDGM_STOP_SEC_CONFIG_DATA_FAST_UNSPECIFIED
#include "WdgM_Cfg_MemMap.h"

