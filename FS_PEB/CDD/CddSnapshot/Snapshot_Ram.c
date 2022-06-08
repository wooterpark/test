/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2018 by JEE.       All rights reserved.
** This software is copyright protected and proprietary to JEE.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with JEE.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \xx\xx$
* $Class_____: C$
* $Name______: Snapshot_Ram.c$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: Rory.Li$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION: Fault recording code
**----------------------------------------------------------------------------**
** HISTORY:
Version generation time: 2020-04-21 14:12:04, By Rory.Li
*******************************************************************************/

#include "Snapshot_MemFunc.h"
#include "Snapshot_Ram.h"

/* The integer Info: 100us */
typedef struct
{
    uint16 PreUdc;
    uint16 iU;
    uint16 iV;
    uint16 iW;
    uint16 ASP_agRtr;
} Prv_ConvFastInfo_S;

/* The integer Info: 10ms */
typedef struct
{
    uint16 VDD15L_Vol;
    uint16 UBR_Vol;
    uint16 VDD18L_Vol;
    uint16 VDD5T1_Vol;
    uint16 VDD5T2_Vol;
} Prv_ConvSlowInfo_S;

static Prv_ConvFastInfo_S Prv_DefConvFastInfo_S __attribute__ ((asection(".data.CPU2_unspec","f=aw"))) =
{
    0U, 0U, 0U, 0U, 0U
};

static Prv_ConvSlowInfo_S Prv_DefConvSlowInfo_S __attribute__ ((asection(".data.CPU2_unspec","f=aw"))) =
{
    0U, 0U, 0U, 0U, 0U
};

#pragma section ".rodata.Calib_32"
const volatile uint8 CAL_SnapshotRam_Enable_u8 = (uint8)1;
const volatile uint8 CAL_SnapshotRam_TriggerFault_u8 = (uint8)0;
#pragma section

static void Prv_ConvFastInfo(
                                const SnapshotFastRam_RteInfo_S *rteInfoPtr,
                                Prv_ConvFastInfo_S *convFastInfoPtr
                            );
static void Prv_ConvSlowInfo(
                                const SnapshotSlowRam_RteInfo_S *rteInfoPtr,
                                Prv_ConvSlowInfo_S *convSlowInfoPtr
                            );
static void Prv_WriteFastInfo(
                                 SnapshotRam_RamInfo_S *ramInfoPtr,
                                 const Prv_ConvFastInfo_S *convFastInfoPtr,
                                 uint8 faultFlag
                             );
static void Prv_WriteSlowInfo(
                                 SnapshotRam_RamInfo_S *ramInfoPtr,
                                 const Prv_ConvSlowInfo_S *convSlowInfoPtr,
                                 uint8 faultFlag
                             );

static const SnapshotRam_ConfigType_S *Prv_CfgTypePtr = NULL;

/*******************************************************************************
** Function Name : Prv_ConvFastInfo
** Parameter[in] : (1)SnapshotRam_RteInfo_S *, (2)Prv_ConvFastInfo_S *
** Parameter[out]: None
** Return Value  : None
** Note          : None
** Description   : 2020-04-21 14:12:04, By Rory.Li
*******************************************************************************/
static void Prv_ConvFastInfo(
                                const SnapshotFastRam_RteInfo_S *rteInfoPtr,
                                Prv_ConvFastInfo_S *convFastInfoPtr
                            )
{
    uint8 i = (uint8)5;
    uint16 *destPtr = &convFastInfoPtr->PreUdc;
    const float32 *srcPtr = &rteInfoPtr->FastVar0;
    const SnapshotRam_Coeff_S *coeffPtr = &Prv_CfgTypePtr->CFastVar0;

    while (i > 0U)
    {
        /* JEE_MISRA_RULE_10_08 It's allowed . */
        *destPtr = (uint16)(((*srcPtr) * coeffPtr->k) + (coeffPtr->b));
        destPtr++;
        srcPtr++;
        coeffPtr++;
        i--;
    }
}

/*******************************************************************************
** Function Name : Prv_ConvSlowInfo
** Parameter[in] : (1)SnapshotRam_RteInfo_S *, (2)Prv_ConvSlowInfo_S *
** Parameter[out]: None
** Return Value  : None
** Note          : None
** Description   : 2020-04-21 14:12:04, By Rory.Li
*******************************************************************************/
static void Prv_ConvSlowInfo(
                                const SnapshotSlowRam_RteInfo_S *rteInfoPtr,
                                Prv_ConvSlowInfo_S *convSlowInfoPtr
                            )
{
    uint8 i = (uint8)5;
    uint16 *destPtr = &convSlowInfoPtr->VDD15L_Vol;
    const float32 *srcPtr = &rteInfoPtr->SlowVar0;
    const SnapshotRam_Coeff_S *coeffPtr = &Prv_CfgTypePtr->CSlowVar0;

    while (i > 0U)
    {
        /* JEE_MISRA_RULE_10_08 It's allowed . */
        *destPtr = (uint16)(((*srcPtr) * coeffPtr->k) + (coeffPtr->b));
        destPtr++;
        srcPtr++;
        coeffPtr++;
        i--;
    }
}

/*******************************************************************************
** Function Name : Prv_WriteFastInfo
** Parameter[in] : (1)SnapshotRam_RamInfo_S *, (2)Prv_ConvFastInfo_S *, (3)Fault Flag
** Parameter[out]: None
** Return Value  : None
** Note          : None
** Description   : 2020-04-21 14:12:04, By Rory.Li
*******************************************************************************/
static void Prv_WriteFastInfo(
                                 SnapshotRam_RamInfo_S *ramInfoPtr,
                                 const Prv_ConvFastInfo_S *convFastInfoPtr,
                                 uint8 faultFlag
                             )
{
    switch (ramInfoPtr->FastInfo.Fsm)
    {
        case SNAPSHOT_RAM_BEFORE_FAULT:
        {
            Snapshot_MemCopy(
                                (uint8 *)&ramInfoPtr->FastInfo.Buffer[ramInfoPtr->FastInfo.BeforeFaultCnt][0],
                                (const uint8 *)&convFastInfoPtr->PreUdc,
                                ((uint32)SNAPSHOT_RAM_F_VAR_NUM << 1UL)
                            );
            ramInfoPtr->FastInfo.BeforeFaultCnt++;

            if (ramInfoPtr->FastInfo.BeforeFaultCnt >= SNAPSHOT_RAM_F_VAR_BUFFER_HALF_SIZE)
            {
                ramInfoPtr->FastInfo.BeforeFaultCnt = 0U;
            }

            if ((uint8)1 == faultFlag)
            {
                ramInfoPtr->FastInfo.Fsm = SNAPSHOT_RAM_AFTER_FAULT;
            }
            break;
        }
        case SNAPSHOT_RAM_AFTER_FAULT:
        {
            Snapshot_MemCopy(
                                (uint8 *)&ramInfoPtr->FastInfo.Buffer[ramInfoPtr->FastInfo.AfterFaultCnt][0],
                                (const uint8 *)&convFastInfoPtr->PreUdc,
                                ((uint32)SNAPSHOT_RAM_F_VAR_NUM << 1UL)
                            );
            ramInfoPtr->FastInfo.AfterFaultCnt++;

            if (ramInfoPtr->FastInfo.AfterFaultCnt >= SNAPSHOT_RAM_F_VAR_BUFFER_SIZE)
            {
                ramInfoPtr->FastInfo.Fsm = SNAPSHOT_RAM_LOCK_FAULT;
            }
            break;
        }
        default:
        {
            /* Intentionally Empty*/
            break;
        }
    }
}

/*******************************************************************************
** Function Name : Prv_WriteSlowInfo
** Parameter[in] : (1)SnapshotRam_RamInfo_S *, (2)Prv_ConvSlowInfo_S *, (3)Fault Flag
** Parameter[out]: None
** Return Value  : None
** Note          : None
** Description   : 2020-04-21 14:12:04, By Rory.Li
*******************************************************************************/
static void Prv_WriteSlowInfo(
                                 SnapshotRam_RamInfo_S *ramInfoPtr,
                                 const Prv_ConvSlowInfo_S *convSlowInfoPtr,
                                 uint8 faultFlag
                             )
{
    switch (ramInfoPtr->SlowInfo.Fsm)
    {
        case SNAPSHOT_RAM_BEFORE_FAULT:
        {
            Snapshot_MemCopy(
                                (uint8 *)&ramInfoPtr->SlowInfo.Buffer[ramInfoPtr->SlowInfo.BeforeFaultCnt][0],
                                (const uint8 *)&convSlowInfoPtr->VDD15L_Vol,
                                ((uint32)SNAPSHOT_RAM_S_VAR_NUM << 1UL)
                            );
            ramInfoPtr->SlowInfo.BeforeFaultCnt++;

            if (ramInfoPtr->SlowInfo.BeforeFaultCnt >= SNAPSHOT_RAM_S_VAR_BUFFER_HALF_SIZE)
            {
                ramInfoPtr->SlowInfo.BeforeFaultCnt = 0U;
            }

            if ((uint8)1 == faultFlag)
            {
                ramInfoPtr->SlowInfo.Fsm = SNAPSHOT_RAM_AFTER_FAULT;
            }
            break;
        }
        case SNAPSHOT_RAM_AFTER_FAULT:
        {
            Snapshot_MemCopy(
                                (uint8 *)&ramInfoPtr->SlowInfo.Buffer[ramInfoPtr->SlowInfo.AfterFaultCnt][0],
                                (const uint8 *)&convSlowInfoPtr->VDD15L_Vol,
                                ((uint32)SNAPSHOT_RAM_S_VAR_NUM << 1UL)
                            );
            ramInfoPtr->SlowInfo.AfterFaultCnt++;

            if (ramInfoPtr->SlowInfo.AfterFaultCnt >= SNAPSHOT_RAM_S_VAR_BUFFER_SIZE)
            {
                ramInfoPtr->SlowInfo.Fsm = SNAPSHOT_RAM_LOCK_FAULT;
            }
            break;
        }
        default:
        {
            /* Intentionally Empty*/
            break;
        }
    }
}

/*******************************************************************************
** Function Name : SnapshotRam_UpdateFastInfo
** Parameter[in] : (1)SnapshotRam_RteInfo_S *
** Parameter[out]: None
** Return Value  : None
** Note          : None
** Description   : 2020-04-21 14:12:04, By Rory.Li
*******************************************************************************/
void SnapshotRam_UpdateFastInfo(const SnapshotFastRam_RteInfo_S *rteInfoPtr)
{
    uint8 faultFlag = (uint8)0;

    if ((uint8)1 == CAL_SnapshotRam_Enable_u8) /* Running Snapshot module */
    {
        /* JEE_MISRA_RULE_13_05 It's allowed . */
        if ((TRUE == EventFlag2FR_boolean) || ((uint8)1 == CAL_SnapshotRam_TriggerFault_u8))
        {
            faultFlag = (uint8)1;
        }

        Prv_ConvFastInfo(rteInfoPtr, &Prv_DefConvFastInfo_S);
        Prv_WriteFastInfo(Prv_CfgTypePtr->RamInfoPtr, &Prv_DefConvFastInfo_S, faultFlag);
    }
}

/*******************************************************************************
** Function Name : SnapshotRam_UpdateSlowInfo
** Parameter[in] : (1)SnapshotRam_RteInfo_S *
** Parameter[out]: None
** Return Value  : None
** Note          : None
** Description   : 2020-04-21 14:12:04, By Rory.Li
*******************************************************************************/
void SnapshotRam_UpdateSlowInfo(const SnapshotSlowRam_RteInfo_S *rteInfoPtr)
{
    uint8 faultFlag = (uint8)0;

    if ((uint8)1 == CAL_SnapshotRam_Enable_u8) /* Running Snapshot module */
    {
        /* JEE_MISRA_RULE_13_05 It's allowed . */
        if ((TRUE == EventFlag2FR_boolean) || ((uint8)1 == CAL_SnapshotRam_TriggerFault_u8))
        {
            faultFlag = (uint8)1;
        }

        Prv_ConvSlowInfo(rteInfoPtr, &Prv_DefConvSlowInfo_S);
        Prv_WriteSlowInfo(Prv_CfgTypePtr->RamInfoPtr, &Prv_DefConvSlowInfo_S, faultFlag);
    }
}

/*******************************************************************************
** Function Name : SnapshotRam_Init
** Parameter[in] : (1)const SnapshotRam_ConfigType_S *
** Parameter[out]: None
** Return Value  : (1)E_OK: Init successfully
** Note          : None
** Description   : Init function.
*******************************************************************************/
Std_ReturnType SnapshotRam_Init(const SnapshotRam_ConfigType_S *mCfgPtr)
{
    Std_ReturnType mStatus = E_NOT_OK;

    if (NULL != mCfgPtr)
    {
        Prv_CfgTypePtr = mCfgPtr;
        mStatus = E_OK;
    }

    return (mStatus);
}
