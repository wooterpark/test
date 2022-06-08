/*
 * Integration.c
 *
 *  Created on: Aug 11, 2017
 *      Author: puy1hc
 */
/*Includes*/
#include "SchM_Can_17_MCanP.h"
#include "IfxPort_reg.h"
#include "Os.h"
#include "Comm_EcuMBswM.h"
#include "Ecum_Types.h"
//#include "EcuM_PBCfg.h"
#include "EcuM.h"
#include "EcuM_Callout.h"
#include "Rte_Main.h"
#include "Integration.h"
#include "VectorTable_Core0.h"
#include "VectorTable_Core1.h"
#include "rba_Reset.h"
#include "Dma_Callout.h"

/*FJ 2020/02/16 START*/
/*If EcuM_OnGoOffOne() is not added via configuration then
 * hard coded callout stub will be enabled */
#ifndef ECUM_CFG_ON_GOOFFONE
/*Variable used to check,whether the execution reached the EcuM_OnGoOffOne() callout.*/
static volatile boolean EcuM_IsOnGoOffOneReached_b;
#endif
 /**********************************************************************************
   Function name    :  CanIf_MainFunction
   Description    :  Dummy for CanIf_Mainfunction.
   Parameter  (in)  :  None
   Parameter  (inout)  :  None
   Parameter  (out)  :  None
   Return value    :  None
   Remarks      :
 ***********************************************************************************/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
FUNC(void, CANIF_CODE) CanIf_MainFunction(void)
{
	return;
}
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
/**********************************************************************************
  Function name    :  VectorTable_Init
  Description    :  Wrapper for Os_InitializeVectorTable
  Parameter  (in)  :  None
  Parameter  (inout)  :  None
  Parameter  (out)  :  None
  Return value    :  None
  Remarks      :
***********************************************************************************/
#define CPU0_START_SEC_CODE
#include "MemMap.h"
FUNC(void, INIT_CODE) VectorTable_Init(sint8 coreID)
{
	Mcal_ResetCpuENDINIT(coreID);
	Os_InitializeVectorTable();
	Mcal_SetCpuENDINIT(coreID);
	return;
}
#define CPU0_STOP_SEC_CODE
#include "MemMap.h"

#define CPU0_START_SEC_CODE
#include "MemMap.h"
FUNC(void, INIT_CODE) VectorTable_Core0_Init(void)
{
	VectorTable_Init(0);
}
#define CPU0_STOP_SEC_CODE
#include "MemMap.h"

#define CPU1_START_SEC_CODE
#include "MemMap.h"
FUNC(void, INIT_CODE) VectorTable_Core1_Init(void)
{
	VectorTable_Init(1);
}
#define CPU1_STOP_SEC_CODE
#include "MemMap.h"


FUNC(void, INIT_CODE) VectorTable_Core2_Init(void)
{
	VectorTable_Init(2);
}

/**********************************************************************************
  Function name    :  EcuM_OnGoOffOne
  Description    :  This call allows the system designer to notify that the GO OFF I
              state is about to be entered.
  Parameter  (in)  :  None
  Parameter  (inout)  :  None
  Parameter  (out)  :  None
  Return value    :  None
  Remarks      :
***********************************************************************************/
FUNC(void , ECUM_CALLOUT_CODE) EcuM_OnGoOffOne(void )
{
    /*Update Flag variable to indicate that the execution reached the particular APi call.
     * Variable provided only for Debug purpose*/
//	All_ShutDown();//FJ 20200306
	EcuM_IsOnGoOffOneReached_b = TRUE;
}

/**********************************************************************************
  Function name    :  EcuM_AL_Reset
  Description    :  This callout shall take the code for resetting the ECU.
  Parameter  (in)  :  reset - Type of reset to be performed.
  Parameter  (inout)  :  None
  Parameter  (out)  :  None
  Return value    :  None
  Remarks      :
***********************************************************************************/

FUNC( void, ECUM_CALLOUT_CODE ) EcuM_AL_Reset( EcuM_ResetType reset )
{
	EcuM_ResetType local_Var;
	local_Var = reset;
	rba_Reset_Request(RBA_RESET_GRP_SYC_KL15RST_E, RBA_SYC_RESET_T15,(uint32)0x0000);
}

/**********************************************************************************
  Function name    :  EcuM_StartWakeupSources
  Description    :  This callout shall start the given wakeup source(s) so that they are ready to perform wakeup validation.
  Parameter  (in)  :  wakeupSource.
  Parameter  (inout)  :  None
  Parameter  (out)  :  None
  Return value    :  None
  Remarks      :
***********************************************************************************/

FUNC( void, ECUM_CALLOUT_CODE ) EcuM_StartWakeupSources( EcuM_WakeupSourceType wakeupSource )
{
	EcuM_WakeupSourceType local_Var;
	local_Var = wakeupSource;
}

/**********************************************************************************
  Function name    :  EcuM_CheckValidation
  Description    :  This callout is called by EcuM to validate Wakeup source. if a valid wakeup is detected it shall send report to EcuM via EcuM_ValidateWakeupEvent.
  Parameter  (in)  :  wakeupSource.
  Parameter  (inout)  :  None
  Parameter  (out)  :  None
  Return value    :  None
  Remarks      :
***********************************************************************************/

FUNC( void, ECUM_CALLOUT_CODE ) EcuM_CheckValidation( EcuM_WakeupSourceType wakeupSource )
{
	EcuM_WakeupSourceType local_Var;
	local_Var = wakeupSource;
}

/**********************************************************************************
  Function name    :  EcuM_StopWakeupSources
  Description    :  This callout shall stop the given wakeup source(s) after unsucessful wakeup validation..
  Parameter  (in)  :  wakeupSource.
  Parameter  (inout)  :  None
  Parameter  (out)  :  None
  Return value    :  None
  Remarks      :
***********************************************************************************/

FUNC( void, ECUM_CALLOUT_CODE ) EcuM_StopWakeupSources( EcuM_WakeupSourceType wakeupSource )
{
	EcuM_WakeupSourceType local_Var;
	local_Var = wakeupSource;
}

/**********************************************************************************
  Function name    :  EcuM_OnGoOffTwo
  Description    :  This call allows the system designer to notify that the GO OFF II
              state is about to be entered.
  Parameter  (in)  :  None
  Parameter  (inout)  :  None
  Parameter  (out)  :  None
  Return value    :  None
  Remarks      :
***********************************************************************************/
FUNC(void , ECUM_CALLOUT_CODE) EcuM_OnGoOffTwo(void )
{

}

/**********************************************************************************
  Function name    :  EcuM_AL_SwitchOff
  Description    :  This callout shall take the code for shutting off the power
              supply of the ECU. If the ECU cannot unpower itself, a reset
              may be an adequate reaction.
  Parameter  (in)  :  None
  Parameter  (inout)  :  None
  Parameter  (out)  :  None
  Return value    :  None
  Remarks      :
***********************************************************************************/
FUNC(void , ECUM_CALLOUT_CODE) EcuM_AL_SwitchOff(void )
{
	All_ShutDown();
}

/*************************************************************************************************
  Function name     :   EcuM_AL_SetProgrammableInterrupts

  Description       :   EcuM_AL_SetProgrammableInterrupts shall set the interrupts on ECUs with programmable
              interrupts.
  Parameter         :   none
  Return value      :   none

************************************************************************************/
FUNC(void , ECUM_CALLOUT_CODE) EcuM_AL_SetProgrammableInterrupts(void)
{

}

/**********************************************************************************
  Function name    :  EcuM_DeterminePbConfiguration
  Description    :  This callout should evaluate some condition, like port pin or
              NVRAM value, to determine which post-build configuration shall
              be used in the remainder of the startup process. It shall load
              this configuration data into a piece of memory that is accessible
              by all BSW modules and shall return a pointer to the EcuM post-build
              configuration as a base for all BSW module post-build configrations.
  Parameter  (in)  :  None
  Parameter  (inout)  :  None
  Parameter  (out)  :  None
  Return value    :  EcuM_ConfigType*
  Remarks      :
***********************************************************************************/
FUNC(const EcuM_ConfigType * , ECUM_CALLOUT_CODE) EcuM_DeterminePbConfiguration(void )
{
  return (&EcuM_Config);	/* CIX2SGH */
}
/*************************************************************************************************
  Function name     :   EcuM_ErrorHook

  Description       :   In case of serious error conditions like consistancy check failure or
              Ram check failure, ecuM will initiate this call. In such situations it is not possible to
              continue processing and Ecu has to be stopped.
  Parameter         :   Std_ReturnType reason
  Return value      :   none

************************************************************************************/

FUNC(void , ECUM_CALLOUT_CODE) EcuM_ErrorHook(uint16 reason )
{
	uint16 local_Var;
	local_Var = reason;
}

/**********************************************************************************
  Function name     :   EcuM_SwitchOsAppMode
  Description       :   This will be called from Master and Slave core Init api's. This is required for CalWup functionality.
                        In Master core this will be started after starting all cores
                        In Master and Slave core this will be called just before OS Start.
  Parameter (in)    :   None
  Parameter (inout) :   None
  Parameter (out)   :   None
  Return value      :   None
  Remarks           :
***********************************************************************************/

FUNC(void, ECUM_CALLOUT_CODE) EcuM_SwitchOsAppMode(void)
{

}


 /**********************************************************************************
   Function name    :  EcuM_CheckWakeup
   Description    :  this will be called from the corresponding driver when a wakeup is detected .
   Parameter  (in)  :  wakeupSource.
   Parameter  (inout)  :  None
   Parameter  (out)  :  None
   Return value    :  None
   Remarks      :
 ***********************************************************************************/

FUNC( void, ECUM_CALLOUT_CODE ) EcuM_CheckWakeup( EcuM_WakeupSourceType wakeupSource )
{
	EcuM_WakeupSourceType local_Var;
	local_Var = wakeupSource;
}

/**********************************************************************************
  Function name    :  Os_ShutdownAllCores
  Description    :  this will be called from the corresponding driver when a wakeup is detected .
  Parameter  (in)  :  wakeupSource.
  Parameter  (inout)  :  None
  Parameter  (out)  :  None
  Return value    :  None
  Remarks      :
***********************************************************************************/
extern FUNC(void, OS_CODE) Os_ShutdownAllCores(StatusType Error) /* [$UKS 1518] */
{
	StatusType Status_Type;
	Status_Type = Error;
	OSCallout_StopSystemTimer();
	ShutdownHook(Status_Type);
}

/********************************************************************************************************************
Function Name:		OSCallout_StopSystemTimer
Parameter[in]:		None
Parameter[out]:		None
Return Value:		None
Description:		停止系统定时器
|*******************************************************************************************************************/
void	OSCallout_StopSystemTimer(void)
{
	STM0_ISCR.B.CMP0IRR = 1;		//清除匹配标志
	STM0_ICR.B.CMP0EN = 0;			//关闭匹配中断
}

/**********************************************************************************
   Function name    :  Loop_EcuM_MainFunction
   Description      :   call EcuM_Mainfuntion in Shutdown sequence due to RTE was disable. And Core0 have
   	   	   	   	   	   	   to wait for Slave cores shutdown.
   Parameter  (in)  :
   Parameter  (inout)  :  None
   Parameter  (out)  :  None
   Return value    :  None
   Remarks      :
 ***********************************************************************************/
#define ECUM_START_SEC_CODE
#include "EcuM_Cfg_MemMap.h"
FUNC( void, ECUM_CALLOUT_CODE ) Loop_EcuM_MainFunction(void)
{
	uint8 timeout = 0;
	while (timeout < ECUM_MAINFUNCTION_TIMEOUT)
	{
		EcuM_MainFunction();
		timeout++;

	}
}
void Dma_ErrorCallOut(uint8 channel,uint8 id_err)
{

}

#define ECUM_STOP_SEC_CODE
#include "EcuM_Cfg_MemMap.h"
