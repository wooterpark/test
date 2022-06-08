/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2018 by JEE.        All rights reserved.
** This software is copyright protected and proprietary to JEE.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with JEE.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \xx\xx$
* $Class_____: C$
* $Name______: Snapshot_DFls.c$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: Rory.Li$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:
**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:   Initial version.

*******************************************************************************/
#include "IfxFlash_reg.h"
#include "Snapshot_DFls.h"

#define PRV_DFLS_BASE_ADDRESS            (0xAF000000UL)
#define PRV_DFLS_TWO_WORDS               (2UL)
#define PRV_DFLS_LOAD_PAGE_SIZE          (8UL)

/*
 * 1.Dflash busy status
 * 2.Operational error
 */
#define PRV_DFLS_D0BUSY                  (0x00000002UL)
#define PRV_DFLS_OPER_ERROR              (0x00000800UL)

#pragma section ".CPU0_PSPR_PRG" awx
static void Pvr_DFls_EraseCmdCycles(uint32 sectorAddress, uint32 numSector);
static void Pvr_DFls_EnterPageMode(void);
static void Pvr_DFls_LoadPage(const Fls_AddressType* programDataPtr);
static void Pvr_DFls_WriteBurstCmdCycles(
                                            uint32 pageAddress,
                                            const Fls_AddressType* programDataPtr
                                        );

/*******************************************************************************
** Function Name : Pvr_DFls_EraseCmdCycles
** Parameter[in] : (1)sector address, (2)the no.of sectors to be erased
** Parameter[out]: None
** Return Value  : None
** Note          : None
** Description   : Erase command cycles.
*******************************************************************************/
static void Pvr_DFls_EraseCmdCycles(uint32 sectorAddress, uint32 numSector)
{
    /* JEE_MISRA_RULE_11_04 It's allowed . */
    volatile uint32 *addr1 = (volatile uint32 *)(PRV_DFLS_BASE_ADDRESS | 0xAA50UL);
    /* JEE_MISRA_RULE_11_04 It's allowed . */
    volatile uint32 *addr2 = (volatile uint32 *)(PRV_DFLS_BASE_ADDRESS | 0xAA58UL);
    /* JEE_MISRA_RULE_11_04 It's allowed . */
    volatile uint32 *addr3 = (volatile uint32 *)(PRV_DFLS_BASE_ADDRESS | 0xAAA8UL);
    /* JEE_MISRA_RULE_11_04 It's allowed . */
    volatile uint32 *addr4 = (volatile uint32 *)(PRV_DFLS_BASE_ADDRESS | 0xAAA8UL);

    *addr1 = sectorAddress;
    *addr2 = numSector;
    *addr3 = 0x80UL;
    *addr4 = 0x50UL;
    DSYNC();
}

/*******************************************************************************
** Function Name : Pvr_DFls_EnterPageMode
** Parameter[in] : None
** Parameter[out]: None
** Return Value  : None
** Note          : None
** Description   : Enter PageMode command cycles.
*******************************************************************************/
static void Pvr_DFls_EnterPageMode(void)
{
    /* JEE_MISRA_RULE_11_04 It's allowed . */
    volatile uint32 *addr1 = (volatile uint32 *)(PRV_DFLS_BASE_ADDRESS | 0x5554UL);

    *addr1 = 0x5DUL; /* PFlash: 0x50, DFlash: 0x5D */
    DSYNC();
}

/*******************************************************************************
** Function Name : Pvr_DFls_LoadPage
** Parameter[in] : (1)programDataPtr
** Parameter[out]: None
** Return Value  : None
** Note          : None
** Description   : Load page command cycles.
*******************************************************************************/
static void Pvr_DFls_LoadPage(const Fls_AddressType* programDataPtr)
{
    /* JEE_MISRA_RULE_11_04 It's allowed . */
    volatile uint32 *addr1 = (volatile uint32 *)(PRV_DFLS_BASE_ADDRESS | 0x55F0UL);

    *addr1 = *programDataPtr;
    *(addr1 + 1) = *(programDataPtr + 1U);
    DSYNC();
}

/*******************************************************************************
** Function Name : Pvr_DFls_WriteBurstCmdCycles
** Parameter[in] : (1)pageAddress, (2)programDataPtr
** Parameter[out]: None
** Return Value  : None
** Note          : None
** Description   : Write burst command cycles.
*******************************************************************************/
static void Pvr_DFls_WriteBurstCmdCycles(
                                            uint32 pageAddress,
                                            const Fls_AddressType* programDataPtr
                                        )
{
    uint32 InnerCount;
    /* JEE_MISRA_RULE_11_04 It's allowed . */
    volatile uint32 *addr1 = (volatile uint32 *)(PRV_DFLS_BASE_ADDRESS | 0xAA50UL);
    /* JEE_MISRA_RULE_11_04 It's allowed . */
    volatile uint32 *addr2 = (volatile uint32 *)(PRV_DFLS_BASE_ADDRESS | 0xAA58UL);
    /* JEE_MISRA_RULE_11_04 It's allowed . */
    volatile uint32 *addr3 = (volatile uint32 *)(PRV_DFLS_BASE_ADDRESS | 0xAAA8UL);
    /* JEE_MISRA_RULE_11_04 It's allowed . */
    volatile uint32 *addr4 = (volatile uint32 *)(PRV_DFLS_BASE_ADDRESS | 0xAAA8UL);
    const Fls_AddressType* pdata;

    pdata = programDataPtr;
    InnerCount = (FLS_BURST_PAGE_SIZE / PRV_DFLS_LOAD_PAGE_SIZE);

    while(InnerCount != 0U)
    {
        /* Load the data */
        Pvr_DFls_LoadPage(pdata);
        pdata += PRV_DFLS_TWO_WORDS;
        InnerCount--;
    }

    *addr1 = pageAddress;
    *addr2 = 0x00UL;
    *addr3 = 0xA0UL;
    *addr4 = 0x7AUL;
    DSYNC();
}
#pragma section

/*******************************************************************************
** Function Name : Snapshot_DFls_ChkOperError
** Parameter[in] : None
** Parameter[out]: None
** Return Value  : (1)OPER error status
** Note          : None
** Description   : Check operation error.
*******************************************************************************/
uint32 Snapshot_DFls_ChkOperError(void)
{
    uint32 RetVal;
    /* JEE_MISRA_RULE_11_04 It's allowed . */
    RetVal = ((uint32)FLS_SFR_RUNTIME_USER_MODE_READ32(FLASH0_FSR.U) & PRV_DFLS_OPER_ERROR);
    return (RetVal);
}

/*******************************************************************************
** Function Name : Snapshot_DFls_HWBusyCheck
** Parameter[in] : None
** Parameter[out]: None
** Return Value  : (1)Dflash busy status
** Note          : None
** Description   : Hardware busy check.
*******************************************************************************/
uint32 Snapshot_DFls_HWBusyCheck(void)
{
    uint32 RetVal;
    /* JEE_MISRA_RULE_11_04 It's allowed . */
    RetVal = ((uint32)FLS_SFR_RUNTIME_USER_MODE_READ32(FLASH0_FSR.U) & PRV_DFLS_D0BUSY);
    return (RetVal);
}

/*******************************************************************************
** Function Name : Snapshot_DFls_EraseMultipleSectors
** Parameter[in] : (1)sector address, (2)the no.of sectors to be erased
** Parameter[out]: None
** Return Value  : Std_ReturnType: E_OK/E_NOT_OK
** Note          : None
** Description   : Erase multiple sectors.
*******************************************************************************/
Std_ReturnType Snapshot_DFls_EraseSectors(uint32 sectorAddress, uint32 numSector)
{
    Std_ReturnType mStatus = E_NOT_OK;
    uint32 InnerCount = 0UL;

    if (0UL == Snapshot_DFls_ChkOperError())
    {
        if (0UL == Snapshot_DFls_HWBusyCheck())
        {
            /* Enters critical section */
            SuspendAllInterrupts();

            Pvr_DFls_EraseCmdCycles(sectorAddress, numSector);
            /* JEE_MISRA_RULE_11_04 It's allowed . */
            while((((FLS_SFR_RUNTIME_USER_MODE_READ32(FLASH0_FSR.U) & \
                     FLS_FSR_ERASE_MASK) >> FLS_FSR_ERASE_BITPOS) != 1U) && \
                  (InnerCount < FLS_CMDCYCLE_TIMEOUT))
            {
                InnerCount++;
            }

            /* Exits critical section */
            ResumeAllInterrupts();

            mStatus = E_OK;
        }
    }

    return (mStatus);
}

/*******************************************************************************
** Function Name : Snapshot_DFls_WriteBurst
** Parameter[in] : (1)pageAddress, (2)programDataPtr
** Parameter[out]: None
** Return Value  : Std_ReturnType: E_OK/E_NOT_OK
** Note          : None
** Description   : Write burst.
*******************************************************************************/
Std_ReturnType Snapshot_DFls_WriteBurst(
                                           uint32 pageAddress,
                                           const Fls_AddressType* programDataPtr
                                       )
{
    Std_ReturnType mStatus = E_NOT_OK;
    uint32 InnerCount1 = 0UL, InnerCount2 = 0UL;

    if (0UL == Snapshot_DFls_ChkOperError())
    {
        if (0UL == Snapshot_DFls_HWBusyCheck())
        {
            /* Enters critical section */
            SuspendAllInterrupts();

            Pvr_DFls_EnterPageMode();
            /* JEE_MISRA_RULE_11_04 It's allowed . */
            while((((FLS_SFR_RUNTIME_USER_MODE_READ32(FLASH0_FSR.U) & \
                     FLS_FSR_DFPAGE_MASK) >> FLS_FSR_DFPAGE_BITPOS) != 1U) && \
                  (InnerCount1 < FLS_CMDCYCLE_TIMEOUT))
            {
                InnerCount1++;
            }

            Pvr_DFls_WriteBurstCmdCycles(pageAddress, programDataPtr);
            /* JEE_MISRA_RULE_11_04 It's allowed . */
            while((((FLS_SFR_RUNTIME_USER_MODE_READ32(FLASH0_FSR.U) & \
                     FLS_FSR_PROG_MASK) >> FLS_FSR_PROG_BITPOS) != 1U) && \
                  (InnerCount2 < FLS_CMDCYCLE_TIMEOUT))
            {
                InnerCount2++;
            }

            /* Exits critical section */
            ResumeAllInterrupts();

            mStatus = E_OK;
        }
    }

    return (mStatus);
}

/*******************************************************************************
** Function Name : Snapshot_DFls_DisableEccTrap
** Parameter[in] : None
** Parameter[out]: None
** Return Value  : None
** Note          : None
** Description   : Disable Ecc Trap.
*******************************************************************************/
void Snapshot_DFls_DisableEccTrap(void)
{
    /* JEE_MISRA_RULE_11_04 It's allowed . */
    FLASH0_MARD.U |= 0x00008000UL;
}

/*******************************************************************************
** Function Name : Snapshot_DFls_EnableEccTrap
** Parameter[in] : None
** Parameter[out]: None
** Return Value  : None
** Note          : None
** Description   : Enable Ecc Trap.
*******************************************************************************/
void Snapshot_DFls_EnableEccTrap(void)
{
    /* JEE_MISRA_RULE_11_04 It's allowed . */
    FLASH0_MARD.U &= ~0x00008000UL;
}
