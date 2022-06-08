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
* $Name______: Snapshot_DFls.h$
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
#ifndef _SNAPSHOT_DFLS_H_
#define _SNAPSHOT_DFLS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "Fls_17_Pmu.h"

#define SNAPSHOT_DFLS_BURST_PAGE_SIZE                 (32UL)
#define SNAPSHOT_DFLS_BURST_PAGE_SIZE_P_MASK          (0x1FUL)
#define SNAPSHOT_DFLS_BURST_PAGE_SIZE_N_MASK          (0xFFFFFFE0UL)

/*******************************************************************************
 *                          DFlash sector address: NvM
*******************************************************************************/
#define SNAPSHOT_DFLS_SECTOR_00                       (0xAF000000UL)
#define SNAPSHOT_DFLS_SECTOR_01                       (0xAF002000UL)
#define SNAPSHOT_DFLS_SECTOR_02                       (0xAF004000UL)
#define SNAPSHOT_DFLS_SECTOR_03                       (0xAF006000UL)
#define SNAPSHOT_DFLS_SECTOR_04                       (0xAF008000UL)
#define SNAPSHOT_DFLS_SECTOR_05                       (0xAF00A000UL)
#define SNAPSHOT_DFLS_SECTOR_06                       (0xAF00C000UL)
#define SNAPSHOT_DFLS_SECTOR_07                       (0xAF00E000UL)

#define SNAPSHOT_DFLS_SECTOR_08                       (0xAF010000UL)
#define SNAPSHOT_DFLS_SECTOR_09                       (0xAF012000UL)
#define SNAPSHOT_DFLS_SECTOR_10                       (0xAF014000UL)
#define SNAPSHOT_DFLS_SECTOR_11                       (0xAF016000UL)
#define SNAPSHOT_DFLS_SECTOR_12                       (0xAF018000UL)
#define SNAPSHOT_DFLS_SECTOR_13                       (0xAF01A000UL)
#define SNAPSHOT_DFLS_SECTOR_14                       (0xAF01C000UL)
#define SNAPSHOT_DFLS_SECTOR_15                       (0xAF01E000UL)

#define SNAPSHOT_DFLS_SECTOR_16                       (0xAF020000UL)
#define SNAPSHOT_DFLS_SECTOR_17                       (0xAF022000UL)
#define SNAPSHOT_DFLS_SECTOR_18                       (0xAF024000UL)
#define SNAPSHOT_DFLS_SECTOR_19                       (0xAF026000UL)
#define SNAPSHOT_DFLS_SECTOR_20                       (0xAF028000UL)
#define SNAPSHOT_DFLS_SECTOR_21                       (0xAF02A000UL)
#define SNAPSHOT_DFLS_SECTOR_22                       (0xAF02C000UL)
#define SNAPSHOT_DFLS_SECTOR_23                       (0xAF02E000UL)

/*******************************************************************************
 *                          DFlash sector address: Snapshot
*******************************************************************************/
#define SNAPSHOT_DFLS_SECTOR_24                       (0xAF030000UL)
#define SNAPSHOT_DFLS_SECTOR_25                       (0xAF032000UL)
#define SNAPSHOT_DFLS_SECTOR_26                       (0xAF034000UL)
#define SNAPSHOT_DFLS_SECTOR_27                       (0xAF036000UL)
#define SNAPSHOT_DFLS_SECTOR_28                       (0xAF038000UL)
#define SNAPSHOT_DFLS_SECTOR_29                       (0xAF03A000UL)
#define SNAPSHOT_DFLS_SECTOR_30                       (0xAF03C000UL)
#define SNAPSHOT_DFLS_SECTOR_31                       (0xAF03E000UL)

#define SNAPSHOT_DFLS_SECTOR_32                       (0xAF040000UL)
#define SNAPSHOT_DFLS_SECTOR_33                       (0xAF042000UL)
#define SNAPSHOT_DFLS_SECTOR_34                       (0xAF044000UL)
#define SNAPSHOT_DFLS_SECTOR_35                       (0xAF046000UL)
#define SNAPSHOT_DFLS_SECTOR_36                       (0xAF048000UL)
#define SNAPSHOT_DFLS_SECTOR_37                       (0xAF04A000UL)
#define SNAPSHOT_DFLS_SECTOR_38                       (0xAF04C000UL)
#define SNAPSHOT_DFLS_SECTOR_39                       (0xAF04E000UL)

#define SNAPSHOT_DFLS_SECTOR_40                       (0xAF050000UL)
#define SNAPSHOT_DFLS_SECTOR_41                       (0xAF052000UL)
#define SNAPSHOT_DFLS_SECTOR_42                       (0xAF054000UL)
#define SNAPSHOT_DFLS_SECTOR_43                       (0xAF056000UL)
#define SNAPSHOT_DFLS_SECTOR_44                       (0xAF058000UL)
#define SNAPSHOT_DFLS_SECTOR_45                       (0xAF05A000UL)
#define SNAPSHOT_DFLS_SECTOR_46                       (0xAF05C000UL)
#define SNAPSHOT_DFLS_SECTOR_47                       (0xAF05E000UL)

/*******************************************************************************
** Function Name : Snapshot_DFls_ChkOperError
** Parameter[in] : None
** Parameter[out]: None
** Return Value  : (1)OPER error status
** Note          :
** Description   :
*******************************************************************************/
extern uint32 Snapshot_DFls_ChkOperError(void);

/*******************************************************************************
** Function Name : Snapshot_DFls_HWBusyCheck
** Parameter[in] : None
** Parameter[out]: None
** Return Value  : (1)Dflash busy status
** Note          :
** Description   :
*******************************************************************************/
extern uint32 Snapshot_DFls_HWBusyCheck(void);

/*******************************************************************************
** Function Name : Snapshot_DFls_EraseMultipleSectors
** Parameter[in] : (1)sector address, (2)the no.of sectors to be erased
** Parameter[out]: None
** Return Value  : Std_ReturnType: E_OK/E_NOT_OK
** Note          :
** Description   :
*******************************************************************************/
extern Std_ReturnType Snapshot_DFls_EraseSectors(uint32 sectorAddress, uint32 numSector);

/*******************************************************************************
** Function Name : Snapshot_DFls_WriteBurst
** Parameter[in] : (1)pageAddress, (2)programDataPtr
** Parameter[out]: None
** Return Value  : Std_ReturnType: E_OK/E_NOT_OK
** Note          :
** Description   :
*******************************************************************************/
extern Std_ReturnType Snapshot_DFls_WriteBurst(
                                                  uint32 pageAddress,
                                                  const Fls_AddressType* programDataPtr
                                              );

/*******************************************************************************
** Function Name : Snapshot_DFls_DisableEccTrap
** Parameter[in] : None
** Parameter[out]: None
** Return Value  : None
** Note          :
** Description   :
*******************************************************************************/
extern void Snapshot_DFls_DisableEccTrap(void);

/*******************************************************************************
** Function Name : Snapshot_DFls_EnableEccTrap
** Parameter[in] : None
** Parameter[out]: None
** Return Value  : None
** Note          :
** Description   :
*******************************************************************************/
extern void Snapshot_DFls_EnableEccTrap(void);

#ifdef __cplusplus
}
#endif

#endif
