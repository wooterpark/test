/*
 * Stubs.h
 *
 *  Created on: Jul 29, 2017
 *      Author: puy1hc
 */

#ifndef INFRA_STUB_API_STUBS_H_
#define INFRA_STUB_API_STUBS_H_

extern FUNC(void, OS_CODE) Os_ShutdownAllCores(StatusType Error) /* [$UKS 1518] */;
extern	void	OSCallout_StopSystemTimer(void);

#define ECUM_MAINFUNCTION_TIMEOUT	20
#define ECUM_START_SEC_CODE
#include "EcuM_Cfg_MemMap.h"
extern void Loop_EcuM_MainFunction(void);
#define ECUM_STOP_SEC_CODE
#include "EcuM_Cfg_MemMap.h"

#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern void CanIf_MainFunction(void);
#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

#define CPU0_START_SEC_CODE
#include "MemMap.h"
FUNC(void, INIT_CODE) VectorTable_Init(sint8 coreID);
#define CPU0_STOP_SEC_CODE
#include "MemMap.h"

#endif /* INFRA_STUB_API_STUBS_H_ */
