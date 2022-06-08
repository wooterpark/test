#ifndef VLTMTST_H_INCLUDED
#define VLTMTST_H_INCLUDED
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
**   $FILENAME   : VltmTst.h $                                                **
**                                                                            **
**   $CC VERSION : \main\23 $                                                 **
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
**  DESCRIPTION  : This file contains declarations for voltage monitor test.  **
**                                                                            **
**  REFERENCE(S) : Aurix-HE_SafeTlib_DS_VoltageMonitor, v1.7                  **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Platform_Types.h"
#include "Sl_Timeout.h"
#include "Compiler_Cfg.h"
#include "Sl_ErrorCodes.h"
#include "SmuInt.h"
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
#define VLTMTST_TIMEOUT          (2000U)

/* Reset value of EVRMONCTRL register 
SWDUVMOD[21:20] -(10)B: An under-voltage event is triggered when the threshold  
is crossed in a higher to lower voltage transition
SWDOVMOD[17:16] -(01)B: An over-voltage event is triggered when the threshold  
is crossed in a lower to higher voltage transition
EVR33UVMOD[13:12]-(10)B:An under-voltage event is triggered when the threshold  
is crossed in a higher to lower voltage transition
EVR33OVMOD[9:8]  -(01)B:An over-voltage event is triggered when the threshold  
is crossed in a lower to higher voltage transition
EVR13UVMOD[5:4] -(10)B: An under-voltage event is triggered when the threshold  
is crossed in a higher to lower voltage transition
EVR13OVMOD[1:0] -(01)B:An over-voltage event is triggered when the threshold  
is crossed in a lower to higher voltage transition      */

#if ((CHIP_ID == 26U ) || (CHIP_ID == 27U ) || (CHIP_ID == 29U ))
#define VLTM_EVRMONCTRL_RESET     (0x00212121U)
#elif ( (CHIP_ID == 21U ) || (CHIP_ID == 22U) || (CHIP_ID == 23U ))
#define VLTM_EVRMONCTRL_RESET     (0x00210021U)
#endif

/*  Values of VLTM_EVRMON_MAX and VLTM_EVRMON_MIN are used  
    to create the Under-voltage and Over-voltage conditions  */
#if ((CHIP_ID == 26U ) || (CHIP_ID == 27U ) || (CHIP_ID == 29U ))	
#define VLTM_EVRMON_MAX           (0x00FFFFFFU)
#elif ( (CHIP_ID == 21U ) || (CHIP_ID == 22U) || (CHIP_ID == 23U ))
#define VLTM_EVRMON_MAX           (0x00FF00FFU)
#endif

#define VLTM_EVRMON_MIN           (0x00000000U)

/* lock bit in EVRMONCTRL register */
#define VLTM_EVRMONCTRL_SLCK      (0x40000000U)

/* Value used to clear the Under-voltage event in EVR during power-on condition 
     when external voltage (VEXT) is 3.3V         */
#define VLTM_SWDUVVAL_VEXT3V3       ((uint8)0x80)

#if ((CHIP_ID == 26U ) || (CHIP_ID == 27U ) || (CHIP_ID == 29U ))
#define VLTM_VEXT_MONITOR      (TRUE)
#elif ( (CHIP_ID == 21U ) || (CHIP_ID == 22U) || (CHIP_ID == 23U ) )
#define VLTM_VEXT_MONITOR      (FALSE)
#endif

/* SMU Alarm Group IndexBit definitions:      */
#define SMU_SCU_EVR_GRP             ( (uint8)SMU_ALARM_GROUP3 )

/* SMU Alarm Index definitions:       */
#define SMU_SCU_EVR_VDD_UV          ( (uint8)SMU_ALARM_11 )
#define SMU_SCU_EVR_VDD_OV          ( (uint8)SMU_ALARM_12 )

#if ((CHIP_ID == 26U ) || (CHIP_ID == 27U ) || (CHIP_ID == 29U ))
#define SMU_SCU_EVR_VDDP3_UV        ( (uint8)SMU_ALARM_13 )
#define SMU_SCU_EVR_VDDP3_OV        ( (uint8)SMU_ALARM_14 )
#define SMU_SCU_EVR_VEXT_UV         ( (uint8)SMU_ALARM_15 )
#define SMU_SCU_EVR_VEXT_OV         ( (uint8)SMU_ALARM_16 )
#elif ( (CHIP_ID == 21U ) || (CHIP_ID == 22U) || (CHIP_ID == 23U) )
#define SMU_SCU_EVR_VDDP3_UV        ( (uint8)SMU_ALARM_15 )
#define SMU_SCU_EVR_VDDP3_OV        ( (uint8)SMU_ALARM_16 )
#endif

/* SMU Alarm Status Bit definitions:    */
#define SMU_SCU_EVR_VDD_UV_STS      ( (uint32)((uint32)1U << (uint8)SMU_SCU_EVR_VDD_UV   ))
#define SMU_SCU_EVR_VDD_OV_STS      ( (uint32)((uint32)1U << (uint8)SMU_SCU_EVR_VDD_OV   ))
#define SMU_SCU_EVR_VDDP3_UV_STS    ( (uint32)((uint32)1U  << (uint8)SMU_SCU_EVR_VDDP3_UV))
#define SMU_SCU_EVR_VDDP3_OV_STS    ( (uint32)((uint32)1U << (uint8)SMU_SCU_EVR_VDDP3_OV ))

#if ((CHIP_ID == 26U ) || (CHIP_ID == 27U ) || (CHIP_ID == 29U ))
#define SMU_SCU_EVR_VEXT_UV_STS     ( (uint32)((uint32)1U << (uint8)SMU_SCU_EVR_VEXT_UV) )
#define SMU_SCU_EVR_VEXT_OV_STS     ( (uint32)((uint32)1U << (uint8)SMU_SCU_EVR_VEXT_OV) )
#endif

#if ((CHIP_ID == 26U ) || (CHIP_ID == 27U ) || (CHIP_ID == 29U ))
/* Under-voltage Alarms VDD:AG3[11], VDDP3: AG3[13], VEXT:AG3[15]  */
#define SMU_VLTM_UV_ALARMS          ( SMU_SCU_EVR_VDD_UV_STS |\
                                      SMU_SCU_EVR_VDDP3_UV_STS |\
                                      SMU_SCU_EVR_VEXT_UV_STS)  

#elif ( (CHIP_ID == 21U ) || (CHIP_ID == 22U) || (CHIP_ID == 23U) )
/* Under-voltage Alarms VDD:AG3[11], VDDP3:AG3[15]  */
#define SMU_VLTM_UV_ALARMS          ( SMU_SCU_EVR_VDD_UV_STS |\
                                      SMU_SCU_EVR_VDDP3_UV_STS)
#endif

#if ((CHIP_ID == 26U ) || (CHIP_ID == 27U ) || (CHIP_ID == 29U ))
/* Over-voltage Alarms VDD:AG3[12], VDDP3: AG3[14], VEXT:AG3[16]   */                                              
#define SMU_VLTM_OV_ALARMS          ( SMU_SCU_EVR_VDD_OV_STS |\
                                      SMU_SCU_EVR_VDDP3_OV_STS |\
                                      SMU_SCU_EVR_VEXT_OV_STS )                                                                  

#elif ( (CHIP_ID == 21U ) || (CHIP_ID == 22U) || (CHIP_ID == 23U) )
/* Over-voltage Alarms VDD:AG3[12], VDDP3:AG3[16]   */                                              
#define SMU_VLTM_OV_ALARMS          ( SMU_SCU_EVR_VDD_OV_STS |\
                                      SMU_SCU_EVR_VDDP3_OV_STS)
#endif                    
     
/* Both Under-voltage and Over-voltage Alarms  */       
#define SMU_VLTM_ALARMS             ( SMU_VLTM_UV_ALARMS | SMU_VLTM_OV_ALARMS )


/*******************************************************************************
**                      Typedefs                                              **
*******************************************************************************/
/* Type definition of backup data structure of SMU Alarm Actions
 * modified for the test */
typedef struct VltmTst_BackupData
{
  /* EVR1.3V digital under voltage alarm */
  Smu_AlarmActionType AlmActionBackupVDD_UV;
  /* EVR1.3V digital over voltage alarm */
  Smu_AlarmActionType AlmActionBackupVDD_OV;
  /* EVR3.3V under voltage alarm */
  Smu_AlarmActionType AlmActionBackupVDDP3_UV;
  /* EVR3.3V over voltage alarm */
  Smu_AlarmActionType AlmActionBackupVDDP3_OV;
#if ((CHIP_ID == 26U ) || (CHIP_ID == 27U ) || (CHIP_ID == 29U ))
  /* Primary (5V) Input supply under voltage alarm */
  Smu_AlarmActionType AlmActionBackupVEXT_UV;
  /* Primary (5V) Input supply over voltage alarm */
  Smu_AlarmActionType AlmActionBackupVEXT_OV;
#endif
  /* Storage for the EVROVMON register contents */
  uint32 EvrOvMon_Backup;
  /* Storage for the EVRUVMON register contents */
  uint32 EvrUvMon_Backup;
  /* Storage for EVRMONCTRL register contents */
  uint32 EvrMonCtrl_Backup;
  /* Combined result of the backup of SMU alarm actions */
  Std_ReturnType GetAlmActionResult;
} VltmTst_BackupDataType;
/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/
#define IFX_VLTM_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
extern Sl_TstRsltType  VltmTst_VltmTst(const Sl_ParamSetType ParamSetIndex,
                                       const uint8 TstSeed,
                                       uint32* const TstSignature);
#define IFX_VLTM_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                Global Function like macro Definitions                      **
*******************************************************************************/


#endif /* VLTMTST_H_INCLUDED */