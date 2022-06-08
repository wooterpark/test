/*
 * ComAppl_E2E.c
 *
 *  Created on: Dec 4, 2019
 *      Author: frank.zhang
 */

#include "Com.h"
#include "Com_PBCfg.h"
#include "ComAppl_E2E.h"
#include "E2E.h"
#include "ComAppl_ComStackAdapter_Utils.h"



#define  CALIB_START_SEC_CONST_8
#include "MemMap.h"
volatile const uint8 E2E_ProfileSelector_Cal = 0x03;
#define CALIB_STOP_SEC_CONST_8
#include "MemMap.h"
volatile uint8 E2E_ProfileSelector_C = 0x01;
uint8 E2E_ProfileSelector_flg_u8=0;

uint8 count_VCU_DC02_P02=0, count_VCU_DC02_P01=0, count_DC02_P02=0, count_DC02_P01=0;

E2E_P01ProtectStateType E2E_P01SenderState_DC02 ={ 0 /* Counter */};

/*
typedef struct
{
    uint8                   LastValidCounter;
    uint8                   MaxDeltaCounter;
    boolean                 WaitForFirstData;
    boolean                 NewDataAvailable;
    uint8                   LostData;
    E2E_P01CheckStatusType  Status;
    uint8                   SyncCounter;
    uint8                   NoNewOrRepeatedDataCounter;
} E2E_P01CheckStateType;
*/

E2E_P01CheckStateType E2E_P01ReceiverState_VCU_DC02=
{	0,//LastValidCounter
	0,//MaxDeltaCounter
	TRUE,//WaitForFirstData
	FALSE,//NewDataAvailable
	0,//LostData
	E2E_P02STATUS_NONEWDATA,//Status
	0,//SyncCounter
	0 //NoNewOrRepeatedDataCounter
};

/*
typedef struct
{
    uint16            CounterOffset;           bit Offset in MSB order
    uint16            CRCOffset;               bit offset in MSB order
    uint16            DataID;                  sender Identifier
    uint16            DataIDNibbleOffset;    bit Offset in MSB order for Profile 1C
    E2E_P01DataIDMode DataIDMode;              two byte, low byte, alternating
    uint16            DataLength;              length of data in bits
    uint8             MaxDeltaCounterInit;    maximum allowed gap, init value
    uint8             MaxNoNewOrRepeatedData; maximum of missing or repeated data
    uint8             SyncCounterInit;        number of data required for syncronization
} E2E_P01ConfigType;
*/

const E2E_P01ConfigType E2E_P01_StaticCfg_DC02 =
{
		16,//CounterOffset
		24,//CRCOffset
		0x12, /* DataID */
		0,//DataIDNibbleOffset
		E2E_P01_DATAID_BOTH, /* DataIDMode */
		32,//DataLength.signal length +crc+counter
		14, /* MaxDeltaCounterInit */
		1, /* MaxNoNewOrRepeatedData */
		0, /* SyncCounterInit */
};

const E2E_P01ConfigType E2E_P01_StaticCfg_VCU_DC02 =
{
		8,//CounterOffset
		16,//CRCOffset
		0x12, /* DataID */
		0,//DataIDNibbleOffset
		E2E_P01_DATAID_BOTH, /* DataIDMode */
		24,//DataLength
		1, /* MaxDeltaCounterInit */
		1, /* MaxNoNewOrRepeatedData */
		0, /* SyncCounterInit */
};


E2E_P02ProtectStateType E2E_P02SenderState_DC02={0x00};

/*
typedef struct
{
    uint8                   LastValidCounter;
    uint8                   MaxDeltaCounter;
    boolean                 WaitForFirstData;
    boolean                 NewDataAvailable;
    uint8                   LostData;
    E2E_P02CheckStatusType  Status;
    uint8                   SyncCounter;
    uint8                   NoNewOrRepeatedDataCounter;
} E2E_P02CheckStateType;
*/
E2E_P02CheckStateType E2E_P02ReceiverState_VCU_DC02=
{	0,//LastValidCounter
	0,// MaxDeltaCounter
	TRUE,//WaitForFirstData
	FALSE,//NewDataAvailable
	0, //LostData
	E2E_P02STATUS_NONEWDATA ,//Status
	0,//SyncCounter
	0//NoNewOrRepeatedDataCounter
};

/*
typedef struct
{
    uint16 DataLength;              length of data in bits
    uint8  DataIDList[16];          list of sender Identifier
    uint8  MaxDeltaCounterInit;      maximum allowed gap, init value
    uint8  MaxNoNewOrRepeatedData;   maximum of missing or repeated data
    uint8  SyncCounterInit;          number of data required for syncronization
    uint16 Offset ;                  offset of the E2E header in the Data[] array in bits.
                                     Currently not used it should be always set to 0.
} E2E_P02ConfigType;
*/

const E2E_P02ConfigType E2E_P02_StaticCfg_DC02 =
{
		16, 	/* DataLength  in bits*/
		{ 78, 206, 124, 3, 132, 58, 100, 23, 154, 160, 136, 220, 127, 93, 37, 11},	/* DataIDList[16] */
		1	,/* MaxDeltaCounterInit */
		1 , /* MaxNoNewOrRepeatedData */
		1, /* SyncCounterInit */
		0 /* Offset  */


};

const E2E_P02ConfigType E2E_P02_StaticCfg_VCU_DC02 =
{
		8, 	/* DataLength  in bits*/
		{ 78, 206, 124, 3, 132, 58, 100, 23, 154, 160, 136, 220, 127, 93, 37, 11},	/* DataIDList[16] */
		1	,/* MaxDeltaCounterInit */
		1 , /* MaxNoNewOrRepeatedData */
		1, /* SyncCounterInit */
		0 /* Offset  */
};


FUNC(boolean,COM_CODE) Com_RxCbk_VCU_DC02(VAR(PduIdType, AUTOMATIC) id, P2CONST(uint8, AUTOMATIC, COM_APPL_CONST) ptr)
{
	Std_ReturnType error, temporary_return;

		/*Use E2E_ProfileSelector to select the profile used for E2E protection*/

	    uint8 signal_u8;
		uint8 data_au8[4];
		/*E2E Profile 2 Selected*/
		uint8 rxCheckSum;
		uint8 aliveCounter;
		aliveCounter=ComAppl_UnPackSignal(ptr,51,4,FALSE,8);
		rxCheckSum=ComAppl_UnPackSignal(ptr,63,8,FALSE,8);
		/*choose VCU_DC02_DesMinLv bit position is 15, bit length is 8, for e2e*/
		signal_u8=ComAppl_UnPackSignal(ptr,15,8,FALSE,8);
		temporary_return = TRUE;
		if (E2E_ProfileSelector_C == 0x02){
			data_au8[0]=rxCheckSum;
			data_au8[1]=aliveCounter;
			data_au8[2]=signal_u8;
			E2E_P02ReceiverState_VCU_DC02.NewDataAvailable = TRUE;
			error = E2E_P02Check(&E2E_P02_StaticCfg_VCU_DC02,&E2E_P02ReceiverState_VCU_DC02,data_au8);

			count_VCU_DC02_P02++;

			if ((error == 0) && ((E2E_P02ReceiverState_VCU_DC02.Status == E2E_P02STATUS_OK) ||
								 (E2E_P02ReceiverState_VCU_DC02.Status == E2E_P02STATUS_OKSOMELOST) ||
								 (E2E_P02ReceiverState_VCU_DC02.Status == E2E_P02STATUS_INITIAL))) {
				temporary_return = TRUE;
			}
			else{
				temporary_return = FALSE;
			}

		}
		else if (E2E_ProfileSelector_C == 0x01){
			/*E2E Profile 1 Selected*/
			data_au8[0]=signal_u8;
			data_au8[1]=aliveCounter;
			data_au8[2]=rxCheckSum;
			E2E_P01ReceiverState_VCU_DC02.NewDataAvailable = TRUE;
			error = E2E_P01Check(&E2E_P01_StaticCfg_VCU_DC02,&E2E_P01ReceiverState_VCU_DC02,ptr);
			count_VCU_DC02_P01++;
			if ((error == 0) && ((E2E_P01ReceiverState_VCU_DC02.Status == E2E_P01STATUS_OK) ||
								 (E2E_P01ReceiverState_VCU_DC02.Status == E2E_P01STATUS_OKSOMELOST) ||
								 (E2E_P01ReceiverState_VCU_DC02.Status == E2E_P01STATUS_INITIAL))) {
				temporary_return = TRUE;
			}
			else{
				temporary_return = FALSE;
			}
		}

		return temporary_return;
}


FUNC(boolean,COM_CODE) Com_TxCbk_DC02(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
	Std_ReturnType error,temporary_return;
		temporary_return = TRUE;
		/*Use E2E_ProfileSelector to select the profile used for E2E protection*/
	    E2E_ProfileSelector_flg_u8 =E2E_ProfileSelector_C;
		/*choose DC02_MaxLvCurr for E2E,bit position is 27 ,length is 12*/
		uint16 signal_u16=ComAppl_UnPackSignal(ptr,27,12,FALSE,8);

		if (E2E_ProfileSelector_C == 0x02){
			/*E2E Profile 2 Selected*/\
			uint8 data_au8[4];
			data_au8[0]=0;//crc
			data_au8[1]=0;//counter
			data_au8[2]=(uint8)(signal_u16&0xffu);
			data_au8[3]=(uint8)((signal_u16>>8)&0xffu);
			error = E2E_P02Protect(&E2E_P02_StaticCfg_DC02,&E2E_P02SenderState_DC02,data_au8);
			count_DC02_P02++;

			if (error == 0){
				temporary_return = TRUE;
				ComAppl_PackSignal(ptr,data_au8[1],51,4,FALSE,8);//counter
				ComAppl_PackSignal(ptr,data_au8[0],63,8,FALSE,8);//crc
			}
			else{
				temporary_return = error;
			}
		}
		else if (E2E_ProfileSelector_C == 0x01){
			/*E2E Profile 1 Selected*/
			uint8 data_au8[4];
			data_au8[0]=(uint8)(signal_u16&0xffu);
			data_au8[1]=(uint8)((signal_u16>>8)&0xffu);
			data_au8[2]=0;//counter
			data_au8[3]=0;//crc
			error = E2E_P01Protect(&E2E_P01_StaticCfg_DC02,&E2E_P01SenderState_DC02,data_au8);
			count_DC02_P01++;

			if (error == 0){
				temporary_return = TRUE;
				ComAppl_PackSignal(ptr,data_au8[2],51,4,FALSE,8);//counter
				ComAppl_PackSignal(ptr,data_au8[3],63,8,FALSE,8);//crc
			}
			else{
				temporary_return = error;
			}

		}

		return temporary_return;
}
