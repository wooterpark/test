/****************************************************************************
 *                                 ETAS GmbH
 *                      D-70469 Stuttgart, Borsigstr. 14
 *****************************************************************************/

#include "NvM.h"
#include "Rte_NvM_Type.h"
#include "Fls.h"
#include "NvM_Integration.h"

#define NVM_START_SEC_VAR_CLEARED_16
#include "NvM_Cfg_MemMap.h"
uint16 ReadAllcounter = 0, WriteAllcounter = 0;
#define NVM_STOP_SEC_VAR_CLEARED_16
#include "NvM_Cfg_MemMap.h"

/***************************************************************************************************
 Function name    : IC_BswM_NvM_ReadAll
 Syntax           : void  IC_BswM_NvM_ReadAll(none)
 Description      : Callback function for NvM Read All
 Parameter        : none
 Return value     : none
 ***************************************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_Cfg_MemMap.h"
void IC_BswM_NvM_ReadAll ( void )
{
	NvM_Rb_StatusType status_NvM;
	MemIf_StatusType stMemIf_en;
	Std_ReturnType returnvalue;

	NvM_ReadAll();
	/* disable detection and report of timeout for FLS */
	Fls_ControlTimeoutDet(0);
	do
	{
		NvM_MainFunction();
		MemIf_Rb_MainFunction();
		returnvalue = NvM_Rb_GetStatus(&status_NvM);
		stMemIf_en = MemIf_Rb_GetStatus();
		ReadAllcounter++;
	} while ( (status_NvM == NVM_RB_STATUS_BUSY ) || (stMemIf_en == MEMIF_BUSY));
	/*Read All immediate block*/
	ReadAll_ImmediateBlock();
	do
	{
		NvM_MainFunction();
		MemIf_Rb_MainFunction();
		returnvalue = NvM_Rb_GetStatus(&status_NvM);
		stMemIf_en = MemIf_Rb_GetStatus();
		ReadAllcounter++;
	} while ( (status_NvM == NVM_RB_STATUS_BUSY ) || (stMemIf_en == MEMIF_BUSY));
	/* enable detection and report of timeout for FLS */
	Fls_ControlTimeoutDet(1);
}
#define NVM_STOP_SEC_CODE
#include "NvM_Cfg_MemMap.h"

/***************************************************************************************************
 Function name    : IC_BswM_NvM_WriteAll
 Syntax           : void  IC_BswM_NvM_WriteAll(none)
 Description      : Callback function for NvM Write All
 Parameter        : none
 Return value     : none
 ***************************************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_Cfg_MemMap.h"
void IC_BswM_NvM_WriteAll ( void )
{
	NvM_Rb_StatusType status_NvM;
	MemIf_StatusType stMemIf_en;
	Std_ReturnType returnvalue;

	NvM_WriteAll();
	/*
	 * Here RTE scheduling is stopped, so WdgM won't be triggered anymore.
	 * we need to prevent the Wdg from reseting the CPU.
	 * WDG_SLOW_MODE so Wdg increases the hardware timeout period
	 */
	//WdgIf_SetMode(0, WDGIF_SLOW_MODE);
	/*
	 * gives sometime to perform WriteAll command
	 */
	//WdgIf_SetTriggerCondition(0, 2000);
	/* disable detection and report of timeout for FLS */
	Fls_ControlTimeoutDet(0);
	do
	{
		NvM_MainFunction();
		MemIf_Rb_MainFunction();

		returnvalue = NvM_Rb_GetStatus(&status_NvM);
		stMemIf_en = MemIf_Rb_GetStatus();
		WriteAllcounter++;
	} while ( (status_NvM == NVM_RB_STATUS_BUSY ) || (stMemIf_en == MEMIF_BUSY));
	WriteAll_ImmediateBlock();
	do
	{
		NvM_MainFunction();
		MemIf_Rb_MainFunction();

		returnvalue = NvM_Rb_GetStatus(&status_NvM);
		stMemIf_en = MemIf_Rb_GetStatus();
		WriteAllcounter++;
	} while ( (status_NvM == NVM_RB_STATUS_BUSY ) || (stMemIf_en == MEMIF_BUSY));
	/* enable detection and report of timeout for FLS */
	Fls_ControlTimeoutDet(1);
}
#define NVM_STOP_SEC_CODE
#include "NvM_Cfg_MemMap.h"
