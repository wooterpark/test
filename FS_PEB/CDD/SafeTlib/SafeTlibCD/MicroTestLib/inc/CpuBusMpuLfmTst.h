#ifndef CPUBUSMPULFMTST_H
#define CPUBUSMPULFMTST_H

/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : CpuBusMpuLfmTst.h $                                        **
**                                                                            **
**   $CC VERSION : \main\13 $                                                 **
**                                                                            **
**   $DATE       : 2018-02-22 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains a latent fault metric test for the CPU  **
**                 Bus Memory Protection Unit.                                **
**                                                                            **
**  REFERENCE(S) : Aurix-HE_SafeTlib_DS_CPU_BusMpuTest, v0.2                  **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Platform_Types.h"
#include "Sl_Timeout.h"
#include "Sl_ErrorCodes.h"
#include "SmuInt.h"
#include "Mcal.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/


/* Total number of memory test ranges (do not change!):                     */
#define BUS_MPU_TEST_RANGE_COUNT                    ( 8U )

/* Size of single memory range for testing in bytes (= granularity of the CPU
   Bus Protection; do not change unless the granularity of the MPU has changed):
*/
#define BUS_MPU_TEST_RANGE_SIZE                 ( 32U )

/*******************************************************************************
**                      Typedefs                                              **
*******************************************************************************/
typedef struct CpuBusMpuLfmTst_ConfigType
{
  uint32 * TestMemory[MCAL_NO_OF_CORES][8U];
  uint32 * UnauthorizedAddr[MCAL_NO_OF_CORES][1U];

}CpuBusMpuLfmTst_ConfigType;

typedef struct CpuBusMpuLfmTst_BackupDataType
{
  uint32 RGNLA0;
  uint32 RGNUA0;
  uint32 RGNLA1;
  uint32 RGNUA1;
  uint32 RGNLA2;
  uint32 RGNUA2;
  uint32 RGNLA3;
  uint32 RGNUA3;
  uint32 RGNLA4;
  uint32 RGNUA4;
  uint32 RGNLA5;
  uint32 RGNUA5;
  uint32 RGNLA6;
  uint32 RGNUA6;
  uint32 RGNLA7;
  uint32 RGNUA7;
  uint32 RGNACCENA0;
  uint32 RGNACCENA1;
  uint32 RGNACCENA2;
  uint32 RGNACCENA3;
  uint32 RGNACCENA4;
  uint32 RGNACCENA5;
  uint32 RGNACCENA6;
  uint32 RGNACCENA7;
  uint32 CpuBusMpuLfmTst_BackupMemory[MCAL_NO_OF_CORES][64U];  
  Smu_AlarmActionType AlmAction;
}CpuBusMpuLfmTst_BackupDataType;
/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/
#define IFX_CPUBUSMPULFM_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/* Test API:                                                                */
extern Sl_TstRsltType CpuBusMpuLfmTst_LfmTest
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 TstSeed,
  uint32* const TstSignature
);
#define IFX_CPUBUSMPULFM_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                Global Function like macro Definitions                      **
*******************************************************************************/

#endif /* BUSMPULFMTST_H */

