/*
 * NvM_Integration.h
 *
 *  Created on: Aug 9, 2017
 *      Author: NAI1HC
 */

#ifndef INFRA_STUB_SRC_NVM_INTEGRATION_H_
#define INFRA_STUB_SRC_NVM_INTEGRATION_H_

#define BSW_START_SEC_CONST_UNSPECIFIED
#include "Bsw_MemMap.h"
/*default data for block native 1024 bytes*/
extern const uint8 ROM_NVM_NATIVE_1024[1024];
extern const uint8 ROM_NVM_REDUNDANT_1024[1024];
#define BSW_STOP_SEC_CONST_UNSPECIFIED
#include "Bsw_MemMap.h"

#define NVM_START_SEC_VAR_CLEARED_16
#include "NvM_Cfg_MemMap.h"
extern uint16 ReadAllcounter, WriteAllcounter;
#define NVM_STOP_SEC_VAR_CLEARED_16
#include "NvM_Cfg_MemMap.h"

#define NVM_START_SEC_CODE
#include "NvM_Cfg_MemMap.h"
extern void ReadAll_ImmediateBlock(void);
#define NVM_STOP_SEC_CODE
#include "NvM_Cfg_MemMap.h"

#define NVM_START_SEC_CODE
#include "NvM_Cfg_MemMap.h"
extern void WriteAll_ImmediateBlock(void);
#define NVM_STOP_SEC_CODE
#include "NvM_Cfg_MemMap.h"

#define NVM_START_SEC_CODE
#include "NvM_Cfg_MemMap.h"
extern void IC_BswM_NvM_ReadAll ( void );
extern void IC_BswM_NvM_WriteAll ( void );
#define NVM_STOP_SEC_CODE
#include "NvM_Cfg_MemMap.h"

#define NVM_START_SEC_CODE
#include "NvM_Cfg_MemMap.h"
FUNC(void, NVM_CBK_CODE) Nvm_SingleBlockCallback_RestoreDefaultData(uint8 ServiceId, NvM_RequestResultType JobResult);
FUNC(void, NVM_CBK_CODE) NvM_SingleBlockCallback_NativeBlock_1024(uint8 ServiceId, NvM_RequestResultType JobResult);
FUNC(void, NVM_CBK_CODE) NvM_SingleBlockCallback_RedundantBlock_1024(uint8 ServiceId, NvM_RequestResultType JobResult);
#define NVM_STOP_SEC_CODE
#include "NvM_Cfg_MemMap.h"
#endif /* INFRA_STUB_SRC_NVM_INTEGRATION_H_ */
