#ifndef SRITST_H
#define SRITST_H

/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : SriTst.h $                                                 **
**                                                                            **
**   $CC VERSION : \main\22 $                                                 **
**                                                                            **
**   $DATE       : 2015-07-24 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains declarations for SRI test.              **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Mcal.h"
#include "SriTst_Cfg.h"
#include "Compiler_Cfg.h"
#include "Sl_ErrorCodes.h"
#include "ChipId.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* SMU alarm timeout. The value was chosen based on following considerations:
 * The worst case number of SMU cycles before an alarm gets visible is
 * n * 2 + 20 (with n = max. number of simultaneous alarms). With a maximum
 * of 32 * 7 alarms and maximum clock ratio fSPB/fSRI = 1/4 this evaluates to
 * 1872 CPU clock cycles. To avoid the counting the number of instructions per
 * loop cycle, it is assumed that only one instruction is executed per loop
 * cycle and thus the number of CPU clock cycles is directly used as timeout
 * value:
 */
#define SRI_SMU_ALARM_TIMEOUT                      (2000U)
#define SRI_DMA_MODENABLE_TIMEOUT                  (0x100U)

/* XBAR_IDINTSAT bits for CPU0/1/2 DMI masters: */
#define SRI_XBAR_IDINTSAT_IDMCI12       ( 0x10000000U )   /* CPU0.DMI */
#if(MCAL_NO_OF_CORES > 1U)
#define SRI_XBAR_IDINTSAT_IDMCI8        ( 0x01000000U )   /* CPU1.DMI */
#if(MCAL_NO_OF_CORES == 3U)
#define SRI_XBAR_IDINTSAT_IDMCI10       ( 0x04000000U )   /* CPU2.DMI */
#endif /* (MCAL_NO_OF_CORES == 3U) */
#endif /* (MCAL_NO_OF_CORES > 1U) */

/* Memory for different devices  */
#if (CHIP_ID == 21U)
/*PSPR Address Range */
#define SRI_PSPR0_ADD_MIN       ( 0x70100000U )
#define SRI_PSPR0_ADD_MAX       ( 0x70101FFFU )
/*DSPR Address Range */
#define SRI_DSPR0_ADD_MIN       ( 0x70000000U )
#define SRI_DSPR0_ADD_MAX       ( 0x70015FFFU )
/*PFLASH Address Range */
#define SRI_PFLASH0_ADD_MIN     ( 0xA0000000U )
#define SRI_PFLASH0_ADD_MAX     ( 0xA007FFFFU )
/*DFLASH Address Range */
#define SRI_DFLASH0_ADD_MIN     ( 0xAF000000U )
#define SRI_DFLASH0_ADD_MAX     ( 0xAF00FFFFU )

#elif (CHIP_ID == 22U)
/*PSPR Address Range */
#define SRI_PSPR0_ADD_MIN       ( 0x70100000U )
#define SRI_PSPR0_ADD_MAX       ( 0x70101FFFU )
/*DSPR Address Range */
#define SRI_DSPR0_ADD_MIN       ( 0x70000000U )
#define SRI_DSPR0_ADD_MAX       ( 0x70015FFFU )
/*PFLASH Address Range */
#define SRI_PFLASH0_ADD_MIN     ( 0xA0000000U )
#define SRI_PFLASH0_ADD_MAX     ( 0xA00FFFFFU )
/*DFLASH Address Range */
#define SRI_DFLASH0_ADD_MIN     ( 0xAF000000U )
#define SRI_DFLASH0_ADD_MAX     ( 0xAF017FFFU )

#elif (CHIP_ID == 23U)
/*PSPR Address Range */
#define SRI_PSPR0_ADD_MIN       ( 0x70100000U )
#define SRI_PSPR0_ADD_MAX       ( 0x70101FFFU )
/*DSPR Address Range */
#define SRI_DSPR0_ADD_MIN       ( 0x70000000U )
#define SRI_DSPR0_ADD_MAX       ( 0x7002DFFFU )
/*PFLASH Address Range */
#define SRI_PFLASH0_ADD_MIN     ( 0xA0000000U )
#define SRI_PFLASH0_ADD_MAX     ( 0xA01FFFFFU )
/*DFLASH Address Range */
#define SRI_DFLASH0_ADD_MIN     ( 0xAF000000U )
#define SRI_DFLASH0_ADD_MAX     ( 0xAF01FFFFU )

#elif (CHIP_ID == 26U)
/*PSPR Address Range */
#define SRI_PSPR0_ADD_MIN       ( 0x70100000U )
#define SRI_PSPR0_ADD_MAX       ( 0x70103FFFU )
#define SRI_PSPR1_ADD_MIN       ( 0x60100000U )
#define SRI_PSPR1_ADD_MAX       ( 0x60107FFFU )
/*DSPR Address Range */
#define SRI_DSPR0_ADD_MIN       ( 0x70000000U )
#define SRI_DSPR0_ADD_MAX       ( 0x70011FFFU )
#define SRI_DSPR1_ADD_MIN       ( 0x60000000U )
#define SRI_DSPR1_ADD_MAX       ( 0x6001DFFFU )
/*PFLASH Address Range */
#define SRI_PFLASH0_ADD_MIN     ( 0xA0000000U )
#define SRI_PFLASH0_ADD_MAX     ( 0xA00FFFFFU )
#define SRI_PFLASH1_ADD_MIN     ( 0xA0100000U )
#define SRI_PFLASH1_ADD_MAX     ( 0xA027FFFFU )
/*DFLASH Address Range */
#define SRI_DFLASH0_ADD_MIN     ( 0xAF000000U )
#define SRI_DFLASH0_ADD_MAX     ( 0xAF0FFFFFU )
#define SRI_DFLASH1_ADD_MIN     ( 0xAF100000U )
#define SRI_DFLASH1_ADD_MAX     ( 0xAF103FFFU )

#elif (CHIP_ID == 27U)
/*PSPR Address Range */
#define SRI_PSPR0_ADD_MIN       ( 0x70100000U )
#define SRI_PSPR0_ADD_MAX       ( 0x70105FFFU )
#define SRI_PSPR1_ADD_MIN       ( 0x60100000U )
#define SRI_PSPR1_ADD_MAX       ( 0x60107FFFU )
#define SRI_PSPR2_ADD_MIN       ( 0x50100000U )
#define SRI_PSPR2_ADD_MAX       ( 0x50107FFFU )
/*DSPR Address Range */
#define SRI_DSPR0_ADD_MIN       ( 0x70000000U )
#define SRI_DSPR0_ADD_MAX       ( 0x7001BFFFU )
#define SRI_DSPR1_ADD_MIN       ( 0x60000000U )
#define SRI_DSPR1_ADD_MAX       ( 0x6001DFFFU )
#define SRI_DSPR2_ADD_MIN       ( 0x50000000U )
#define SRI_DSPR2_ADD_MAX       ( 0x5001DFFFU )
/*PFLASH Address Range */
#define SRI_PFLASH0_ADD_MIN     ( 0xA0000000U )
#define SRI_PFLASH0_ADD_MAX     ( 0xA01FFFFFU )
#define SRI_PFLASH1_ADD_MIN     ( 0xA0200000U )
#define SRI_PFLASH1_ADD_MAX     ( 0xA03FFFFFU )
/*DFLASH Address Range */
#define SRI_DFLASH0_ADD_MIN     ( 0xAF000000U )
#define SRI_DFLASH0_ADD_MAX     ( 0xAF103FFFU )
#define SRI_DFLASH1_ADD_MIN     ( 0xAF110000U )
#define SRI_DFLASH1_ADD_MAX     ( 0xAF11FFFFU )
/*LMU Address Range */
#define SRI_LMU_ADD_MIN         ( 0xB0000000U )
#define SRI_LMU_ADD_MAX         ( 0xB0007FFFU )

#elif (CHIP_ID == 29U)
/*PSPR Address Range */
#define SRI_PSPR0_ADD_MIN       ( 0x70100000U )
#define SRI_PSPR0_ADD_MAX       ( 0x70107FFFU )
#define SRI_PSPR1_ADD_MIN       ( 0x60100000U )
#define SRI_PSPR1_ADD_MAX       ( 0x60107FFFU )
#define SRI_PSPR2_ADD_MIN       ( 0x50100000U )
#define SRI_PSPR2_ADD_MAX       ( 0x50107FFFU )
/*DSPR Address Range */
#define SRI_DSPR0_ADD_MIN       ( 0x70000000U )
#define SRI_DSPR0_ADD_MAX       ( 0x7001DFFFU )
#define SRI_DSPR1_ADD_MIN       ( 0x60000000U )
#define SRI_DSPR1_ADD_MAX       ( 0x6003BFFFU )
#define SRI_DSPR2_ADD_MIN       ( 0x50000000U )
#define SRI_DSPR2_ADD_MAX       ( 0x5003BFFFU )
/*PFLASH Address Range */
#define SRI_PFLASH0_ADD_MIN     ( 0xA0000000U )
#define SRI_PFLASH0_ADD_MAX     ( 0xA01FFFFFU )
#define SRI_PFLASH1_ADD_MIN     ( 0xA0200000U )
#define SRI_PFLASH1_ADD_MAX     ( 0xA03FFFFFU )
#define SRI_PFLASH2_ADD_MIN     ( 0xA0400000U )
#define SRI_PFLASH2_ADD_MAX     ( 0xA05FFFFFU )
#define SRI_PFLASH3_ADD_MIN     ( 0xA0600000U )
#define SRI_PFLASH3_ADD_MAX     ( 0xA07FFFFFU )
/*DFLASH Address Range */
#define SRI_DFLASH0_ADD_MIN     ( 0xAF000000U )
#define SRI_DFLASH0_ADD_MAX     ( 0xAF103FFFU )
#define SRI_DFLASH1_ADD_MIN     ( 0xAF110000U )
#define SRI_DFLASH1_ADD_MAX     ( 0xAF11FFFFU )
/*LMU Address Range */
#define SRI_LMU_ADD_MIN         ( 0xB0000000U )
#define SRI_LMU_ADD_MAX         ( 0xB0007FFFU )

#endif /* (CHIP_ID == 29U) */


/*******************************************************************************
**                      Typedefs                                              **
*******************************************************************************/

typedef struct SriTst_Config
{
    uint8      LmuTstEN[MCAL_NO_OF_CORES];
    uint8      PmuDFlashTstEN[MCAL_NO_OF_CORES];
    uint8      PmuPFlashTstEN[MCAL_NO_OF_CORES];
    uint8      DmaTstEN[MCAL_NO_OF_CORES];
    uint8      XbarTstEN[MCAL_NO_OF_CORES];
    uint32*    SriTstPSPRTstAdr[MCAL_NO_OF_CORES];
    uint32*    SriTstDSPRTstAdr[MCAL_NO_OF_CORES];
    uint32*    SriTstLMUTstAdr[MCAL_NO_OF_CORES];
    uint32*    SriTstDFlashTstAdr[MCAL_NO_OF_CORES];
    uint32*    SriTstPFlashTstAdr[MCAL_NO_OF_CORES];

} SriTst_ConfigType;

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

#define IFX_SRI_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"

/* Exported SRI test configuration:                                           */
extern const SriTst_ConfigType SriTst_ConfigRoot[SRI_EDC_BUSERR_TST_CFG_PARAM_COUNT];

#define IFX_SRI_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/
#define IFX_SRI_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

extern Sl_TstRsltType  SriTst_SriTst(const Sl_ParamSetType ParamSetIndex,
                                     const uint8 TstSeed,
                                     uint32* const TstSignature);

#define IFX_SRI_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                Global Function like macro Definitions                      **
*******************************************************************************/

#endif /* SRITST_H */

