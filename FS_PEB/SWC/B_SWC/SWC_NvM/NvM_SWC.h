/*
 * NvM_SWC.h
 *
 *  Created on: Jan 16, 2017
 *      Author: OX81HC
 */

#ifndef NvM_SWC_H_
#define NvM_SWC_H_

/*********************** External function declaration******************/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NvM_SWC_PP_SWC_NvM_NvM_SLInPLimt(VAR(float32, AUTOMATIC) data);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NvM_SWC_PP_SWC_NvM_NvM_SLFnh(VAR(boolean, AUTOMATIC) data);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NvM_SWC_RP_SWC_PCF_PCF_flgSLWD(CONSTP2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) data);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_SWC_PCF_RP_SWC_NvM_NvM_SLInPLimt(CONSTP2VAR(float32, AUTOMATIC, RTE_APPL_DATA) data);

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NvM_SWC_PP_SWC_NvM_NvM_AngAutoClbOffset(VAR(float32, AUTOMATIC) data);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NvM_SWC_PP_SWC_NvM_NvM_flgAngAutoClbOffset(VAR(boolean, AUTOMATIC) data);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NvM_SWC_RP_SWC_RCF_RCF_flgOfsClbSucToNVM(CONSTP2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) data);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NvM_SWC_RP_SWC_RCF_RCF_AutoClbOffset(CONSTP2VAR(float32, AUTOMATIC, RTE_APPL_DATA) data);
/*Internal function declaration*/
void EPC_WriteBlock (void);
void RCF_WriteBlock(void);
void SWC_Write_Test(void);/*Test Code*/

boolean EPC2NvM_Write_Flg = FALSE;
float32 DatafromEPC = 10;
float32 DataToEPC = 11;
uint8 NvM_RetVal_u8 = E_NOT_OK;
boolean NvM2EPC_Write_OK_Flg = FALSE;

typedef enum NvM_Test_t{
	SWC_ZERO = 0,
	ASW_WRITE_BLOCK_1024,
	ASW_READ_BLOCK_1024,
	ASW_WRITE_REDUNDANT_BLOCK_1024,
	ASW_READ_REDUNDANT_BLOCK_1024,
	ASW_WRITE_ALL_BLKS_REQ,
	ASW_CORRUPT_ONE_BLOCK_OF_REDUNDANT_BLOCK_1024_1,
	ASW_CORRUPT_ONE_BLOCK_OF_REDUNDANT_BLOCK_1024_2,
	ASW_CORRUPT_TWO_BLOCK_OF_REDUNDANT_BLOCK_1024
}NvM_Test_t;

typedef enum request_result_t{
	REQUEST_OK,
	REQUEST_NOT_OK,
	REQUEST_PENDING,
	NOT_REQUEST,
}request_result_t;

typedef enum Flash_Erase_t{
	NOT_ERASE = 0,
	ERASE_BANK0,
	ERASE_BANK1,
	EEPROM_CE,
}Flash_Erase_t;

typedef enum NvM_SwcIModifyNvBlock_State_t{
	MDF_NONE,
	MDF_INIT_STATE,
	MDF_ERASE_BANK,
	MDF_MODIFY_DATA,
	MDF_UPDATE_DATA,
	MDF_UPDATE_MANANGMENT_INFO,
}MDF_State_t;

typedef enum NvM_SwcIModifyBothNvBlock_State_t{
	MODIFY_BOTH_NV_BLOCK_NONE,
	MODIFY_READ_BLOCK,
	MODIFY_BACKUP_BLOCK,
}MDF_Both_State_t;;

/*Test data*/
extern uint8 TEST_DATA_NVM_NATIVE_1024[1024];
extern uint8 TEST_DATA_NVM_REDUNDANT_1024[1024];

/*Internal test functions*/
#define NvM_SWC_START_SEC_CODE
#include "NvM_SWC_MemMap.h"
void UpdatePIMWithValue(uint8 *dst, uint32 length, uint8 Value) ;
#define NvM_SWC_STOP_SEC_CODE
#include "NvM_SWC_MemMap.h"

#define NvM_SWC_START_SEC_CODE
#include "NvM_SWC_MemMap.h"
void WriteAll_ImmediateBlock (void);
#define NvM_SWC_STOP_SEC_CODE
#include "NvM_SWC_MemMap.h"

#define NvM_SWC_START_SEC_CODE
#include "NvM_SWC_MemMap.h"
void ReadAll_ImmediateBlock (void);
#define NvM_SWC_STOP_SEC_CODE
#include "NvM_SWC_MemMap.h"

#define NvM_SWC_START_SEC_CODE
#include "NvM_SWC_MemMap.h"
uint8 NvM_SwcIModifyNvBlock(uint32 addr);
#define NvM_SWC_STOP_SEC_CODE
#include "NvM_SWC_MemMap.h"

#endif /* NvM_SWC_H_ */
