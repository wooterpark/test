/****************************************************************************
 *                                 ETAS GmbH
 *                      D-70469 Stuttgart, Borsigstr. 14
 *****************************************************************************/

#include "std_types.h"
#include "NvM.h"
#include "Rte_Type.h"
#include "Rte_NvM_SWC_Type.h"
#include "NvM_Prv.h"
#include "NvM_Integration.h"
/***************************************************************************************************
 Function name    : Nvm_SingleBlockCallback_RestoreDefaultData
 Syntax           : void  Nvm_SingleBlockCallback_RestoreDefaultData(uint8 ServiceId, NvM_RequestResultType JobResult)
 Description      : This function is implemented to restore default data from rom block to ram block in case block status is invalid
 the first time NvM read is performed with blank memory in flash
 Parameter        : uint8 ServiceId, NvM_RequestResultType JobResult
 Return value     : none
 ***************************************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_Cfg_MemMap.h"
FUNC(void, NVM_CBK_CODE) Nvm_SingleBlockCallback_RestoreDefaultData(uint8 ServiceId, NvM_RequestResultType JobResult)
{
	if(((ServiceId == (uint8)NVM_SERVICE_ID_READ_ALL )||(ServiceId == (uint8)NVM_SERVICE_ID_READ_BLOCK))&& (JobResult == (NvM_RequestResultType)MEMIF_BLOCK_INVALID))
	{
		uint8 *destptr = NvM_Prv_Main_st.adrActiveRamBlock_rMwM_pu8; /*get active ram block in current block*/
		/* MISRA RULE 11.5 VIOLATION:  We cast from  a pointer to void to a pointer to object type in order to get the data*/
		const uint8 *srcptr = (const uint8 *)NvM_Prv_BlockDescriptors_acst[NvM_Prv_Main_st.idActiveBlockCfg_rMwM_u16].adrRomBlock_pcv; /*get configured address of rom block*/
		uint16 blocksize = (uint16)*NvM_Prv_BlockDescriptors_acst[NvM_Prv_Main_st.idActiveBlockCfg_rMwM_u16].nrBlockBytes_pu16; /*get size of active block*/
		if((destptr != NULL)&&(srcptr != NULL)) /*only perform restore action when ram block is available and rom block is configured*/
		{
			while(blocksize > 0U){
				*destptr = *srcptr;
				destptr++;
				srcptr++;
				blocksize--;
			}
			NvM_Prv_stBlock_rAwAM_au8[NvM_Prv_Main_st.idActiveBlockCfg_rMwM_u16] &= (uint8) ~(NVM_BLOCK_STATE_RAM_VALID); /*please note that this is used only use if RAM block is permanence*/
			NvM_Prv_stRequestResult_rAwAM_au8[NvM_Prv_Main_st.idActiveBlockCfg_rMwM_u16] = NVM_REQ_RESTORED_FROM_ROM;
		}
	}
}
#define NVM_STOP_SEC_CODE
#include "NvM_Cfg_MemMap.h"

/***************************************************************************************************
 Function name    : NvM_SingleBlockCallback_NativeBlock_1024
 Syntax           : void  NvM_SingleBlockCallback_NativeBlock_1024(uint8 ServiceId, NvM_RequestResultType JobResult)
 Description      : Single Block Callback for block NativeBlock_1024
 Parameter        : uint8 ServiceId, NvM_RequestResultType JobResult
 Return value     : none
 ***************************************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_Cfg_MemMap.h"
FUNC(void, NVM_CBK_CODE) NvM_SingleBlockCallback_NativeBlock_1024(uint8 ServiceId, NvM_RequestResultType JobResult)
{
	Nvm_SingleBlockCallback_RestoreDefaultData(ServiceId,JobResult);
}
#define NVM_STOP_SEC_CODE
#include "NvM_Cfg_MemMap.h"

/***************************************************************************************************
 Function name    : NvM_SingleBlockCallback_RedundantBlock_1024
 Syntax           : void  NvM_SingleBlockCallback_RedundantBlock_1024(uint8 ServiceId, NvM_RequestResultType JobResult)
 Description      : Single Block Callback for block RedundantBlock_1024
 Parameter        : uint8 ServiceId, NvM_RequestResultType JobResult
 Return value     : none
 ***************************************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_Cfg_MemMap.h"
FUNC(void, NVM_CBK_CODE) NvM_SingleBlockCallback_RedundantBlock_1024(uint8 ServiceId, NvM_RequestResultType JobResult)
{
	Nvm_SingleBlockCallback_RestoreDefaultData(ServiceId,JobResult);
}
#define NVM_STOP_SEC_CODE
#include "NvM_Cfg_MemMap.h"
