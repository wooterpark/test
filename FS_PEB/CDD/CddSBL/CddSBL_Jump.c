/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2018 by JEE.		All rights reserved.
** This software is copyright protected and proprietary to JEE.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with JEE.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \xx\xx$
* $Class_____: C$
* $Name______: CddSBL_Jump.c$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: LM$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION: System Bootloader jump code.
**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:   Initial version.

*******************************************************************************/

#include "Mcu.h"
#include "CddSBL_Jump.h"
#include "BswM.h"
#include "Com_PBcfg.h"
#include "rba_Reset.h"

volatile uint32 Prv_Jump_JumpToSblFlag_u32 __attribute__ ((asection(".data.JumpToSBL_Flag", "f=aw"))) = 0UL;

CddSBL_RamInfo_S CddSBL_DefRamInfo_S =
{
    {(uint8)0},
    {(uint8)0},
    (uint8)0,
    (uint8)0,
    0U
};

static void Prv_Jump_GroupTransmitEn(uint8 enableFlag);
static void Prv_Jump_SetSysBootResetFlag(uint8 *mRxBufferPtr, uint8 *mTxBufferPtr);
static void Prv_Jump_SysBootReset(void);

/*******************************************************************************
** Function Name	: Prv_Jump_GroupTransmitEn
** Parameter[in] 	: (1)Enable flag
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	:
*******************************************************************************/
static void Prv_Jump_GroupTransmitEn(uint8 enableFlag)
{
    if ((uint8)1 == enableFlag)
    {
        /* Enable Transmit */
        BswM_RequestMode(
                            BSWM_CFG_USERID_BSWM_MRP_STARTPDUGROUP_SYS,
                            RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_STARTUP_TWO
                        );
    }
    else
    {
        /* Disable Transmit */
        BswM_RequestMode(
                            BSWM_CFG_USERID_BSWM_MRP_STOPPDUGROUP_SYS,
                            RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_STARTUP_TWO
                        );
    }
}

/*******************************************************************************
** Function Name : Prv_Jump_SetSysBootResetFlag
** Parameter[in] : (1)Receive buffer pointer
** Parameter[out]: (2)Send buffer pointer
** Return Value  : None
** Note          :
** Description   : Set System Bootloader Reset Flag.
*******************************************************************************/
static void Prv_Jump_SetSysBootResetFlag(uint8 *mRxBufferPtr, uint8 *mTxBufferPtr)
{
    if (((uint8)0x02 == mRxBufferPtr[0]) && ((uint8)0x10 == mRxBufferPtr[1]) && (((uint8)0x03 == mRxBufferPtr[2])))
    {
        mTxBufferPtr[0] = (uint8)0x06;
        mTxBufferPtr[1] = (uint8)0x50;
        mTxBufferPtr[2] = (uint8)0x03;
        mTxBufferPtr[3] = (uint8)0x00;
        mTxBufferPtr[4] = (uint8)0x32;
        mTxBufferPtr[5] = (uint8)0x01;
        mTxBufferPtr[6] = (uint8)0x90;
        mTxBufferPtr[7] = (uint8)0x00;
        Prv_Jump_GroupTransmitEn((uint8)1);
        CddSBL_DefRamInfo_S.TxDatasStartingFlag = (uint8)1;

        Prv_Jump_JumpToSblFlag_u32 = 0x5A5A5A5AUL;
        mRxBufferPtr[0] = (uint8)0;
        mRxBufferPtr[1] = (uint8)0;
        mRxBufferPtr[2] = (uint8)0;
        mRxBufferPtr[3] = (uint8)0;
        mRxBufferPtr[4] = (uint8)0;
        mRxBufferPtr[5] = (uint8)0;
        mRxBufferPtr[6] = (uint8)0;
        mRxBufferPtr[7] = (uint8)0;
    }
}

/*******************************************************************************
** Function Name : Prv_Jump_SysBootReset
** Parameter[in] : None
** Parameter[out]: None
** Return Value  : None
** Note          :
** Description   : System Bootloader Reset.
*******************************************************************************/
static void Prv_Jump_SysBootReset(void)
{
    if ((uint8)1 == CddSBL_DefRamInfo_S.TxDatasFinishedFlag)
    {
        if (0x5A5A5A5AUL == Prv_Jump_JumpToSblFlag_u32)
        {
//        	Pws_CoreCfg(WDGIF_OFF_MODE);
        	Tlf35584SafeWdg_FunctionClosed();/*LQ 20201028*/
            CddSBL_DefRamInfo_S.TxDatasFinishedFlag = (uint8)0;
            rba_Reset_Request(RBA_RESET_GRP_SOFTRESET_E,SWRESET_UPPER_COMPUTER_SERVICES,(uint32)0x0000);
        }
    }
}

/*******************************************************************************
** Function Name	: CddSBL_Jump_TransmitDisable
** Parameter[in] 	: (1)CddSBL_RamInfo_S pointer
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	:
*******************************************************************************/
void CddSBL_Jump_TransmitDisable(CddSBL_RamInfo_S * ramInfoPtr)
{
    if ((uint8)1 == ramInfoPtr->TxDatasStartingFlag)
    {
        ramInfoPtr->TxCnt++;

	    if (ramInfoPtr->TxCnt >= 1U)
	    {
	        ramInfoPtr->TxCnt = 0U;
	        Prv_Jump_GroupTransmitEn((uint8)0);
	        ramInfoPtr->TxDatasStartingFlag = (uint8)0;
	        ramInfoPtr->TxDatasFinishedFlag = (uint8)1;
	    }
    }
}

/*******************************************************************************
** Function Name	: CddSBL_Jump_MainFunction
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	:
*******************************************************************************/
void CddSBL_Jump_MainFunction(void)
{
    Prv_Jump_SetSysBootResetFlag(&CddSBL_DefRamInfo_S.RxBuffer[0], &CddSBL_DefRamInfo_S.TxBuffer[0]);
    Prv_Jump_SysBootReset();
}
