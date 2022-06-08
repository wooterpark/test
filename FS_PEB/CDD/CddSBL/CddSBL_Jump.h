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
* $Name______: CddSBL_Jump.h$
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
#ifndef _CDD_SBL_JUMP_H_
#define _CDD_SBL_JUMP_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"

typedef struct
{
    uint8 RxBuffer[8];
    uint8 TxBuffer[8];
    uint8 TxDatasStartingFlag;
    uint8 TxDatasFinishedFlag;
    uint16 TxCnt;
} CddSBL_RamInfo_S;

/*******************************************************************************
** Function Name	: CddSBL_Jump_TransmitDisable
** Parameter[in] 	: (1)CddSBL_RamInfo_S pointer
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	:
*******************************************************************************/
extern void CddSBL_Jump_TransmitDisable(CddSBL_RamInfo_S * ramInfoPtr);

/*******************************************************************************
** Function Name	: CddSBL_Jump_MainFunction
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note			  	: None
** Description	  	:
*******************************************************************************/
extern void CddSBL_Jump_MainFunction(void);

extern CddSBL_RamInfo_S CddSBL_DefRamInfo_S;

#ifdef __cplusplus
}
#endif

#endif
