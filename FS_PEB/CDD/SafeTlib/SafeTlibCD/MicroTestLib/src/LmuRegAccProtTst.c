/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2015)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : LmuRegAccProtTst.c $                                       **
**                                                                            **
**   $CC VERSION : \main\39 $                                                 **
**                                                                            **
**   $DATE       : 2015-11-13 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file provides latent fault metric test routines for   **
**                 the LMU Register Access Protection.                        **
**                                                                            **
**  SPECIFICATION(S) : Aurix_SafeTlib_DS_LMU_RegAcc_Prot_Test.docm            **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "LmuRegAccProtTst.h"
#include "IfxLmu_reg.h"
#include "IfxLmu_bf.h"
#include "IfxCpu_bf.h"
#include "IfxCpu_reg.h"
#include "Sl_Ipc.h"
#include "Mcal.h"
#include "IfxScu_reg.h"
#include "Mtl_Trap.h"
#include "IfxXbar_reg.h"
#include "IfxXbar_bf.h"
#include "IfxSrc_reg.h"
#include "IfxSrc_bf.h"

/*******************************************************************************
**                      Local Macro Definitions                               **
*******************************************************************************/

/* ACCEN bitmasks for CPU0 DMI.NonSafe and CPU0 DMI.Safe Master TAG IDs:      */
#define LMU_REG_ACC_CPU0_NON_SAFE_DMI_ACCEN     ( 0x00000001U )
#define LMU_REG_ACC_CPU0_SAFE_DMI_ACCEN         ( 0x00000002U )

/* ACCEN bitmasks for CPU1 DMI.NonSafe and CPU1 DMI.Safe Master TAG IDs:      */
#define LMU_REG_ACC_CPU1_NON_SAFE_DMI_ACCEN     ( 0x00000004U )
#define LMU_REG_ACC_CPU1_SAFE_DMI_ACCEN         ( 0x00000008U )

/* ACCEN bitmasks for CPU2 DMI.NonSafe and CPU2 DMI.Safe Master TAG IDs:      */
#define LMU_REG_ACC_CPU2_NON_SAFE_DMI_ACCEN     ( 0x00000010U )
#define LMU_REG_ACC_CPU2_SAFE_DMI_ACCEN         ( 0x00000020U )

#define LMU_REG_ACC_SMU_LMU_ERROR_GRP          ( (uint8)SMU_ALARM_GROUP2 )
#define LMU_REG_ACC_SMU_SRI_ERROR_GRP          ( (uint8)SMU_ALARM_GROUP3 )


/* Bitmask for setting / clearing the S bit (Safety Task Identifier)
 *  in the PSW:        */
#define LMU_REG_ACC_PSW_S_BIT  \
                  ((uint32)((uint32)1U << (uint32)(IFX_CPU_PSW_S_OFF) )) 

/* SMU alarm timeout. The value was chosen based on following considerations:
 * The worst case number of SMU cycles before an alarm gets visible is
 * n * 2 + 20 (with n = max. number of simultaneous alarms). With a maximum
 * of 32 * 7 alarms and maximum clock ratio fSPB/fSRI = 1/4 this evaluates to
 * 1872 CPU clock cycles. To avoid the counting the number of instructions per
 * loop cycle, it is assumed that only one instruction is executed per loop
 * cycle and thus the number of CPU clock cycles is directly used as timeout
 * value:
 */
#define LMU_REG_ACC_SMU_ALM_TIMEOUT             (2000U)

/* cerberus DMA access */
#define LMU_REG_ACC_CERBERUS_DMA_TAG            (0x0000000AU)

#define LMU_REG_ACC_ALLOW_ALL_SRI_MASTERS       (0xFFFFFFFFU)

#define LMU_ALLOW_SAFE_STATE_ENABLE_VAL         (0x0000000BU)

#define LMU_DENY_SAFE_STATE_ENABLE_VAL          (0x0000000CU)

#define LMU_DENY_SAFE_TASK_ENABLE_VAL           (0x0000000DU)

/* Trap classes and IDs: */
#define LMU_REG_TRAP_CLASS_NONE             ( 0x00U )
#define LMU_REG_TRAP_CLASS4                 ( 0x04U )
#define LMU_REG_TRAP_ID_NONE                ( 0x00U )
#define LMU_REG_TRAP_ID3                    ( 0x03U )

/* Clear SRC_XBARSRC Service Request Flag */
#define LMU_REG_ACC_XBARSRC_MASK           ((unsigned_int)0x293F1CFFU)
#define LMU_REG_ACC_XBARSRC_CLEAR_BITS     ((unsigned_int)0x02000000U)

/*******************************************************************************
**                      Local Type Definitions                                **
*******************************************************************************/
/* Storage for backup of the LMU MPU and SRI Bus error alarm action.
 * Backup of LMU_BUFCON0 and LMU_ACCEN0 and BTV backup
 */
typedef struct LmuRegAccProtTst_BackupDataType
{
  Smu_AlarmActionType AlmActionBackupLmuMpu; /*Storage for backup of the
                        SMU LMU MPU error alarm action*/
  Smu_AlarmActionType AlmActionBackupSriBus; /*Storage for backup of the
                        SRI Bus error alarm action*/  
  uint32 LmuBufcon0Backup;  /*Storage for backup of the LMU_BUFCON0 register*/
  uint32 LmuAccen0Backup;  /*Storage for backup of the LMU_ACCEN0 register*/
  uint32 ProtectionTrapRegistered;
}LmuRegAccProtTst_BackupDataType;


/*******************************************************************************
**                        Exported object definitions                         **
*******************************************************************************/

/*******************************************************************************
**                        Local object definitions                            **
*******************************************************************************/
#define IFX_LMUREGACCPROTTST_START_SEC_VAR_8BIT_CPU0_DSPR
#include "Ifx_MemMap.h"
static volatile uint8 LmuRegAccTst_DaeTrapCount;
#define IFX_LMUREGACCPROTTST_STOP_SEC_VAR_8BIT_CPU0_DSPR
#include "Ifx_MemMap.h"

#define IFX_LMUREGACCPROTTST_START_SEC_VAR_32BIT_CPU0_DSPR
#include "Ifx_MemMap.h"
static uint32  LmuRegAccTst_ExpectedTrapClass;
static uint32  LmuRegAccTst_ExpectedTrapId;
#define IFX_LMUREGACCPROTTST_STOP_SEC_VAR_32BIT_CPU0_DSPR
#include "Ifx_MemMap.h"

/*******************************************************************************
**                        Imported function declarations                      **
*******************************************************************************/

#define IFX_LMUREGACCPROTTST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                        Local function prototypes                           **
*******************************************************************************/

static boolean LmuRegAccProtTst_lProtectionTrapHandler(const uint32 TrapId);

static Sl_TstRsltType LmuRegAccProtTst_lInit
(
 LmuRegAccProtTst_BackupDataType* const LmuRegAccProtTst_BackupData
);

static Sl_TstRsltType LmuRegAccProtTst_lRestore
(
 const LmuRegAccProtTst_BackupDataType* const LmuRegAccProtTst_BackupData
);

static Sl_TstRsltType LmuRegAccProtTst_lAllowAccTst
(
 uint32* const TstSignature
);

static Sl_TstRsltType LmuRegAccProtTst_lDenyAccTst
(
 uint32* const TstSignature,
 const uint8 CoreId
);

static Sl_TstRsltType LmuRegAccProtTst_lDenyAccSafeTst
(
 uint32* const TstSignature,
 const uint8 CoreId
);

static Sl_TstRsltType LmuRegAccProtTst_lDenyAccNonSafeTst
(
 uint32* const TstSignature,
 const uint8 CoreId
);

static boolean LmuRegAccProtTst_lSetAccEnNonSafeTask
(
 const uint32 Value
);

static boolean LmuRegAccProtTst_lSetAccEnSafeTask
(
 const uint32 Value
);

static Sl_TstRsltType LmuRegAccProtTst_lWaitForSmuAlarm
(
 void
);

/******************************************************************************
**                    Local inline function definitions                       *
******************************************************************************/



/******************************************************************************
**                    Configuration error checking                            *
******************************************************************************/

/******************************************************************************
**                         Function definitions                               *
******************************************************************************/

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax :       Sl_TstRsltType LmuRegAccProtTst_LmuRegAccProtTst            **
**                (                                                           **
**                 const Sl_ParamSetType ParamSetIndex,                       **
**                 const uint8 TstSeed,                                       **
**                 uint32* const TstSignature                                 **
**                )                                                           **    
**                                                                            **
**                                                                            **
** Description : This test checks that the register protection scheme for LMU **
                 does work as expected. To verify this, the following         **
         actions are being executed:                                          **            
**               • Allow all masters access to the protected registers        **
**               • Use different masters (Current CPU’s DMI safe and non-safe **
**                 master) and alter a protected register. Check that the     **
**                 register contents actually got changed.                    **
**               • Deny all masters, except CPU.DMI, to access                **
**                 the protected registers                                    **
**               • Try to alter protected registers with different masters    **
**                 (Current CPU’s DMI safe and non-safe master) and check     **
**                 that each time a SMU alarm is generated.                   **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : ParamSetIndex - Identifies the parameter set to be used  **
**                                   for test execution                       **
**                   Note: This parameter is ignored and should always be set **
**                   to zero. It is only defined for reasons of compatibility **
**                   with APIs of other MTL tests                             **
**                                                                            **
**                   TstSeed - Seed to be used for generating the signature   **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value : LMUREGACC_SUCCESS     - Test succeeded                      **
**                                                                            **
**                LMUREGACC_NOTEXECUTED - The test has not been executed or at**
**                least was interrupted before a valid result could be        **
**                generated                                                   **
**                                                                            **
**                LMUREGACC_SMU_STATEERR - The test cannot be executed because**
**                the SMU is in the wrong state                               **
**                                                                            **
**                LMUREGACC_SMU_GETALMSTSERR - Test failed because getting the**
**                SMU alarm status failed                                     **
**                                                                            **
**                LMUREGACC_SMU_CLRALMSTSERR -The test failed because clearing**
**                the SMU alarm failed.                                       **
**                                                                            **
**                LMUREGACC_ SMU_ALMSTSERR - Test failed because there is     **
**                already a watchdog alarm present within the SMU.            **
**                                                                            **
**                LMUREGACC_SMU_SETALMACTIONERR - Test failed because setting **
**                SMU alarm action failed.                                    **
**                                                                            **
**                LMUREGACC_SMU_GETALMACTIONERR - Test failed because getting **
**                SMU alarm action failed.                                    **
**                                                                            **
**                LMUREGACC_STUCKATFAULT - Test failed because there seems to **
**                a stuck-at fault within the CPU’s ACCENA register           **
**                                                                            **
**                LMUREGACC_ACCBLOCKED - The test failed because an attempt to**
**                write to a protected register with a master that is allowed **
**                got anyway blocked                                          **
**                                                                            **
**                LMUREGACC_ACCNOTBLOCKED - The test failed because an attempt**
**                to write to a protected register with a master that is not  **
**                allowed  got not blocked                                    **
**                                                                            **
**                LMUREGACC_TRAPERROR - Test failed because expected number   ** 
**                of traps did not occur                                      **
**                                                                            **
**                LMUREGACC_RESOURCE_TIMEOUT - Test failed because acquiring  **
**                exclusive access to a shared resource timed out             **
*******************************************************************************/
Sl_TstRsltType LmuRegAccProtTst_LmuRegAccProtTst
(
 const Sl_ParamSetType ParamSetIndex,
 const uint8 TstSeed,
 uint32* const TstSignature
)
{
  uint8                     CoreId;
  Sl_TstRsltType            Result    = (Sl_TstRsltType)LMUREGACC_NOTEXECUTED;
  Sl_TstRsltType            TmpResult1 = (Sl_TstRsltType)LMUREGACC_NOTEXECUTED;
  Sl_TstRsltType            TmpResult2 = (Sl_TstRsltType)LMUREGACC_NOTEXECUTED;
  LmuRegAccProtTst_BackupDataType LmuRegAccProtTst_BackupData;
  
  UNUSED_PARAMETER(ParamSetIndex)

  /* Read the core Id */
  CoreId = Mcal_GetCoreId();

  /* Initialize Test Signature:                                             */
  *TstSignature =
  (uint32)CRC32((uint32)TEST_ID_LMU_REG_ACC_PROT_TST,(uint32)TstSeed);
  /* Check if SMU is in RUN state                                           */
  if(SMU_RUN_STATE == Smu_GetSmuState())
  {
    if(E_OK != (Std_ReturnType)Sl_GetSpinLock(SL_LMU_SPNLCK_ID,
                                    (uint32)SL_LMU_TIMEOUT))
    {
      Result = LMUREGACC_RESOURCE_TIMEOUT;
    }
    else 
    {
      if(E_OK != (Std_ReturnType)Sl_GetSpinLock(SL_SMUALRMGRP3_BIT30_SPNLCK_ID,
                                         (uint32)SL_SMUALRMGRP3_BIT30_TIMEOUT))
      {
        Result = LMUREGACC_RESOURCE_TIMEOUT;
      }  
      else
      {
        /* Backup SMU alarms and SFR configs that will be modified */
        TmpResult1 = LmuRegAccProtTst_lInit(&LmuRegAccProtTst_BackupData);
        if(TmpResult1 == (Sl_TstRsltType)LMUREGACC_SUCCESS)
        {
          /* Allow all masters to access protected registers               */
          TmpResult1 = LmuRegAccProtTst_lAllowAccTst(TstSignature);
          if(TmpResult1 == (Sl_TstRsltType)LMUREGACC_SUCCESS)
          {
            /* Deny access to protected registers except CPux.DMI*/
            TmpResult1 = LmuRegAccProtTst_lDenyAccTst(TstSignature,CoreId);
          }
        }
        /* Restore stored SMU alarms and SFR configurations                 */
        TmpResult2 = LmuRegAccProtTst_lRestore(&LmuRegAccProtTst_BackupData);

        if((LMUREGACC_SUCCESS == TmpResult1) && 
                        (LMUREGACC_SUCCESS == TmpResult2))
        {
          Result = LMUREGACC_SUCCESS;
        }
        else
        {
          if(LMUREGACC_SUCCESS != TmpResult1)
          { 
            Result = TmpResult1 ;
          }
          else
          {
            Result = TmpResult2 ;
          }
        }
    Sl_ReleaseSpinLock(SL_SMUALRMGRP3_BIT30_SPNLCK_ID);
     }    
    Sl_ReleaseSpinLock(SL_LMU_SPNLCK_ID);
   }    
  }
  else
  {
    Result = (Sl_TstRsltType)LMUREGACC_SMU_STATEERR;
  }
  /* Calculate final test signature                                         */
  *TstSignature = (uint32)CRC32(*TstSignature,Result);
  return(Result);
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : static boolean LmuRegAccProtTst_lProtectionTrapHandler            **
**               (const uint32 TrapId)                                        **
**                                                                            **
** Description : Handles Class 4 traps which are generated during illegal     **
**               write to protected LMU registers                             **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : TrapId - Trap Identification Number (TIN) of the trap    **
**                            that is to be handled                           **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value : None                                                        **
**                                                                            **
*******************************************************************************/
static boolean LmuRegAccProtTst_lProtectionTrapHandler(const uint32 TrapId)
{
  
  boolean TrapExpected = (boolean)FALSE;
  
   /* Check if TIN = 3 and this trap is currently expected: */
  if ((LMU_REG_TRAP_ID3 == TrapId) &&
      (LMU_REG_TRAP_CLASS4 == LmuRegAccTst_ExpectedTrapClass) &&
      (LMU_REG_TRAP_ID3 == LmuRegAccTst_ExpectedTrapId))
  {
    TrapExpected = (boolean)TRUE;

    /* Clear expected trap class and ID: */
    LmuRegAccTst_ExpectedTrapClass = LMU_REG_TRAP_CLASS_NONE;
    LmuRegAccTst_ExpectedTrapId = LMU_REG_TRAP_ID_NONE;

    if (LmuRegAccTst_DaeTrapCount < (uint8)0xFF)
    {
      LmuRegAccTst_DaeTrapCount += 1U;
    } /* if (LmuRegAccTst_DaeTrapCount < (uint8)0xFF) */

    /* Clear DAE Trap request                          */
    MTCR(CPU_DATR, 0x0U);
  } /* if ((LMU_REG_TRAP_ID3 == TrapId) &&
           (LMU_REG_TRAP_CLASS4 == Lmu_ExpectedTrapClass) &&
           (LMU_REG_TRAP_ID3 == Lmu_ExpectedTrapId)) */
  else
  {
    LmuRegAccTst_DaeTrapCount = 0U;
  } /* if ((LMU_REG_TRAP_ID3 != TrapId) ||
           (LMU_REG_TRAP_CLASS4 != Lmu_ExpectedTrapClass) ||
           (LMU_REG_TRAP_ID3 != Lmu_ExpectedTrapId)) */

  return TrapExpected;  
}
/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstResultType LmuRegAccProtTst_lInit                           **
**          (LmuRegAccProtTst_BackupDataType *                                **
**          const LmuRegAccProtTst_BackupData)                                **
**                                                                            **
** Description : Does a backup of the current SMU alarm actions and the       **
**               SFR- registers that will be overwritten by this test. It     **
**         also sets the SMU actions for the LMU Mpu and SRI Bus alarm        **
**         to “no action”.  It also registers the Trap Class 4 for trap       **
**         handling                                                           **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): LmuRegAccProtTst_BackupData - Holds a backup of the      **
**                   current SMU alarm action configuration of the SMU alarms **
**                   and the SFR configuration that will be changed by this   **
**                   test                                                     **
**                                                                            **
** Return value : LMUREGACC_SUCCESS     - Test succeeded                      **
**                                                                            **
**                LMUREGACC_NOTEXECUTED - The test has not been executed or at**
**                least was interrupted before a valid result could be        **
**                generated                                                   **
**                                                                            **
**                LMUREGACC_SMU_GETALMSTSERR - Test failed because getting the**
**                SMU alarm status failed                                     **
**                                                                            **
**                LMUREGACC_SMU_CLRALMSTSERR -The test failed because clearing**
**                the SMU alarm failed.                                       **
**                                                                            **
**                LMUREGACC_SMU_ALMSTSERR - Test failed because there is      **
**                already a watchdog alarm present within the SMU.            **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType LmuRegAccProtTst_lInit
(
 LmuRegAccProtTst_BackupDataType* const LmuRegAccProtTst_BackupData
)
{
  uint32              AlmStatus;
  Smu_FSPActionType   FspActionDummy;
  TRAP_ErrorType      TrapRegResult;  
  Sl_TstRsltType      Result  = LMUREGACC_NOTEXECUTED;

  LmuRegAccTst_DaeTrapCount = 0x0U;
  
  /* Store LMU_ACCEN0 register */
  LmuRegAccProtTst_BackupData->LmuAccen0Backup = LMU_ACCEN0.U;

  /* Store LMU_BUFCON0 register */
  LmuRegAccProtTst_BackupData->LmuBufcon0Backup = LMU_BUFCON0.U;
  
  /* No trap expected yet. Initialize expected trap class and ID:           */
  LmuRegAccTst_ExpectedTrapClass = LMU_REG_TRAP_CLASS_NONE;
  LmuRegAccTst_ExpectedTrapId = LMU_REG_TRAP_ID_NONE;
  
  /* Initialize status flags for registration of trap handlers:             */
  LmuRegAccProtTst_BackupData->ProtectionTrapRegistered = (boolean)FALSE;

  if(E_OK != (Smu_GetAlarmAction(LMU_REG_ACC_SMU_LMU_ERROR_GRP, SMU_ALARM_16,
  &LmuRegAccProtTst_BackupData->AlmActionBackupLmuMpu, &FspActionDummy)))
  {
    Result = LMUREGACC_SMU_GETALMACTIONERR;
    /* Set to Invalid Alarm Action */
    LmuRegAccProtTst_BackupData->AlmActionBackupLmuMpu =
    SMU_INVALID_ALARM_ACTION;
  }

  if(E_OK != (Smu_GetAlarmAction(LMU_REG_ACC_SMU_SRI_ERROR_GRP, SMU_ALARM_30,
  &LmuRegAccProtTst_BackupData->AlmActionBackupSriBus, &FspActionDummy)))
  {
    Result = LMUREGACC_SMU_GETALMACTIONERR;
    /* Set to Invalid Alarm Action */
    LmuRegAccProtTst_BackupData->AlmActionBackupSriBus =
    SMU_INVALID_ALARM_ACTION;
  }

  /* Get the SMU alarm action for Group 2 alarm 16 and Group 3 alarm 30 */
  if(Result == LMUREGACC_NOTEXECUTED)
  {
    /* Get SMU Alarm Status of Group2 and check operation was done properly*/
    if(E_OK !=
    (Smu_GetAlarmStatus(LMU_REG_ACC_SMU_LMU_ERROR_GRP, &AlmStatus)))
    {
      Result = LMUREGACC_SMU_GETALMSTSERR;
    }

    /* Check if the SMU Alarm is present or not */
    else if(0U != (AlmStatus & ((uint32)1U << SMU_ALARM_16)))
    {
      Result = LMUREGACC_SMU_ALMSTSERR;
    }
	
	else
	{
	  /* added for MISRA */
	}

    /* Get SMU Alarm Status of Group2 and check operation was done properly*/
    if(E_OK !=
    (Smu_GetAlarmStatus(LMU_REG_ACC_SMU_SRI_ERROR_GRP, &AlmStatus)))
    {
      Result = LMUREGACC_SMU_GETALMSTSERR;
    }

    /* Check if the SMU Alarm is present or not */
    else if(0U != (AlmStatus & ((uint32)1U << SMU_ALARM_30)))
    {
      Result = LMUREGACC_SMU_ALMSTSERR;
    }
	
	else
	{
	  /* added for MISRA */
	}

    if(Result == LMUREGACC_NOTEXECUTED)
    {
      /*Set the LMU MPU alarm action to none and check if setting was fine */
      if(E_OK !=
      Smu_SetAlarmAction(LMU_REG_ACC_SMU_LMU_ERROR_GRP, SMU_ALARM_16,
      SMU_ALARM_ACTION_NONE))
      {
        Result = LMUREGACC_SMU_SETALMACTIONERR;
      }

      /*Set the LMU MPU alarm action to none and check if setting was fine */
      if(E_OK !=
      Smu_SetAlarmAction(LMU_REG_ACC_SMU_SRI_ERROR_GRP, SMU_ALARM_30,
      SMU_ALARM_ACTION_NONE))
      {
        Result = LMUREGACC_SMU_SETALMACTIONERR;
      }
    }
  }
  
   if(Result == LMUREGACC_NOTEXECUTED)
   {
     /* Register protection error and bus error trap handlers:               */
     TrapRegResult = TRAP_RegisterTrapHandler(LMU_REG_TRAP_CLASS4,
                                     &LmuRegAccProtTst_lProtectionTrapHandler);
     if(TRAP_E_SUCCESS == TrapRegResult)
     {
       LmuRegAccProtTst_BackupData->ProtectionTrapRegistered = (boolean)TRUE;
       Result = LMUREGACC_SUCCESS;
     } /* if (TRAP_E_SUCCESS == Result) */
     else
     {
       Result = LMUREGACC_TRAPERROR;
     } /* if (TRAP_E_SUCCESS != Result) */
   } /* if(Result == LMUREGACC_NOTEXECUTED) */
  return(Result);
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstResultType LmuRegAccProtTst_lRestore                        **
**         (const LmuRegAccProtTst_BackupDataType *                           **
**         const RegAccProt_BackupData)                                       **
**                                                                            **
** Description : Restores the SMU alarm actions and the SFR register          **
**               configuration  that have been changed during this test       **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in):  LmuRegAccProtTst_BackupData - Holds a backup of the      **
**                   SMU alarm action configuration of the SMU alarms         **
**                   and the SFR configuration that got overwritten by this   **
**                   test                                                     **
**                                                                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value : LMUREGACC_SUCCESS     - Test succeeded                      **
**                                                                            **
**                LMUREGACC_NOTEXECUTED - The test has not been executed or at**
**                least was interrupted before a valid result could be        **
**                generated                                                   **
**                                                                            **
**                LMUREGACC_SMU_SETALMACTIONERR - Test failed because setting **
**                the SMU alarm action failed.                                **
**                                                                            **
**                                                                            **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType LmuRegAccProtTst_lRestore
(
 const LmuRegAccProtTst_BackupDataType* const LmuRegAccProtTst_BackupData
)
{
  Sl_TstRsltType      Result  = LMUREGACC_NOTEXECUTED;

  /* Restore previously backed-up LMU_ACCEN0 value:                  */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  LMU_ACCEN0.U = LmuRegAccProtTst_BackupData->LmuAccen0Backup;
  Mcal_SetSafetyENDINIT_Timed();

  /* Restore previously backed-up LMU_BUFCON0 value:       */
  Mcal_ResetENDINIT();
  LMU_BUFCON0.U =  LmuRegAccProtTst_BackupData->LmuBufcon0Backup;
  Mcal_SetENDINIT();
 
  /*Restore the stored SMU alarms (LMU MPU and SRI Bus)*/
  if (LmuRegAccProtTst_BackupData->AlmActionBackupLmuMpu != SMU_INVALID_ALARM_ACTION)
  {
    if(E_OK != Smu_SetAlarmAction(LMU_REG_ACC_SMU_LMU_ERROR_GRP, SMU_ALARM_16,
    LmuRegAccProtTst_BackupData->AlmActionBackupLmuMpu))
    {
      Result = LMUREGACC_SMU_SETALMACTIONERR;
    }
  }
  
  if (LmuRegAccProtTst_BackupData->AlmActionBackupSriBus != SMU_INVALID_ALARM_ACTION)
  {
    if(E_OK != Smu_SetAlarmAction(LMU_REG_ACC_SMU_SRI_ERROR_GRP, SMU_ALARM_30,
    LmuRegAccProtTst_BackupData->AlmActionBackupSriBus))
    {
      Result = LMUREGACC_SMU_SETALMACTIONERR;
    }
  } 
  if ((boolean)FALSE != LmuRegAccProtTst_BackupData->ProtectionTrapRegistered)
  {
    if (TRAP_E_SUCCESS != TRAP_UnregisterTrapHandler(LMU_REG_TRAP_CLASS4))
    {
      Result = LMUREGACC_TRAPERROR;
    } /*if(TRAP_E_SUCCESS != TRAP_UnregisterTrapHandler(LMU_REG_TRAP_CLASS4))*/
  } /* if (FALSE != LmuRegAccProtTst_BackupData->ProtectionTrapRegistered) */
    
  /* Clearing the INTACK bit set by the test in Arbiter Control Register 4  */
  XBAR_ARBCON4.U |=(unsigned_int)((unsigned_int)IFX_XBAR_ARBCON_INTACK_MSK <<
  (unsigned_int)IFX_XBAR_ARBCON_INTACK_OFF);
  
  /* Clearing the PRSCI4 bit set by the test in Arbiter Interrupt Status 
     Register */
  XBAR_INTSAT.U = ((uint32)1U << IFX_XBAR_INTSAT_PRSCI4_OFF);
  
 /* Clearing the SRI service request set by the test in SRC_XBARSRC Register */
  SRC_XBARSRC.U = ((SRC_XBARSRC.U & LMU_REG_ACC_XBARSRC_MASK) | (LMU_REG_ACC_XBARSRC_CLEAR_BITS));
  
  /* If restore was successful , send LMUREGACC_SUCCESS*/
  if(Result == LMUREGACC_NOTEXECUTED)
  {   
    Result = LMUREGACC_SUCCESS;   
  }
  return(Result);
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType LmuRegAccProtTst_lAllowAccTst                      **
**          (uint32* const TstSignature)                                      **
**                                                                            **
** Description : This function does allow all masters access to the protected **
**               registers. To check for a possible stuck-at fault it does    **
**               read back the configuration register and check whether it    **
**               contains the expected value. After that it tries to alter a  **
**               protected register with two different masters                **
**               (CPUx.DMI safe and non-safe) and checks that those write     **
**               accesses get not blocked.                                    **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value : LMUREGACC_SUCCESS     - Test succeeded                      **
**                                                                            **
**                LMUREGACC_NOTEXECUTED - The test has not been executed or at**
**                least was interrupted before a valid result could be        **
**                generated                                                   **
**                                                                            **
**                LMUREGACC_STUCKATFAULT - Test failed because there seems to **
**                be a stuck-at fault within the CPU’s ACCENA register        **
**                                                                            **
**                LMUREGACC_ACCBLOCKED - The test failed because an attempt to**
**                write to a protected register with a master that is allowed **
**                got anyway blocked                                          **
**                                                                            **
**                LMUREGACC_TRAPERROR - Test failed because expected number   ** 
**                of traps did not occur                                      **
**                                                                            **
*******************************************************************************/

static Sl_TstRsltType LmuRegAccProtTst_lAllowAccTst
(
 uint32* const TstSignature
)
{
  Sl_TstRsltType      Result    = LMUREGACC_NOTEXECUTED;
  boolean             TmpResult = (boolean)FALSE;

  /* Allow all the masters to access protected registers */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  LMU_ACCEN0.U = LMU_REG_ACC_ALLOW_ALL_SRI_MASTERS;
  Mcal_SetSafetyENDINIT_Timed();

  /* Check for Stuck at fault in CPUx_SPROT_ACCENA register */
  if(LMU_ACCEN0.U == LMU_REG_ACC_ALLOW_ALL_SRI_MASTERS)
  {
    /* Write the new value in to LMU_BUFCON0 register */
    Mcal_ResetENDINIT();
    LMU_BUFCON0.U = 0x0U; /*set it to some value other than LMU_REG_ACC_CERBERUS_DMA_TAG*/
    Mcal_SetENDINIT();  
    /* Change CPU state to non-safe state and try to write into a register */
    TmpResult = 
          LmuRegAccProtTst_lSetAccEnNonSafeTask(LMU_REG_ACC_CERBERUS_DMA_TAG);
    *TstSignature = (uint32)CRC32((uint32)*TstSignature,(uint32)TmpResult);
    /* if write is successful */
    if((boolean)TRUE == TmpResult)
    {
      /* Change CPU state to safe state and try to write into a register */
      TmpResult = 
           LmuRegAccProtTst_lSetAccEnSafeTask(LMU_ALLOW_SAFE_STATE_ENABLE_VAL);
      *TstSignature = (uint32)CRC32((uint32)*TstSignature,(uint32)TmpResult);
      /* if access is blocked , set to LMUREGACC_ACCBLOCKED */
      if((boolean)TRUE == TmpResult)
      {
        if(LmuRegAccTst_DaeTrapCount != 0x0U)      
        {
          Result = LMUREGACC_TRAPERROR;
        }
      }
      else
      {
        Result = LMUREGACC_ACCBLOCKED;
      }     
    }
    else
    {
      Result = LMUREGACC_ACCBLOCKED;
    }
  }
  else
  {
    Result = LMUREGACC_STUCKATFAULT;
  }
  if(Result == LMUREGACC_NOTEXECUTED)
  {
    Result = LMUREGACC_SUCCESS;
  }
  return(Result);
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType LmuRegAccProtTst_lDenyAccTst                       **
**          (uint32* const TstSignature, const uint8 CoreId)                  **
**                                                                            **
** Description : This function does deny the access to the protected          **
**               registers except CPUx.DMI. To check for a                    **
**               possible stuck-at fault it does read back the configuration  **
**               register and check whether it contains the expected value.   **
**               After that it tries to alter a protected register with two   **
**               different masters (CPUx.DMI safe and non-safe) and checks    **
**               that those write accesses get actually blocked.              **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value : LMUREGACC_SUCCESS     - Test succeeded                      **
**                                                                            **
**                LMUREGACC_NOTEXECUTED - The test has not been executed or at**
**                least was interrupted before a valid result could be        **
**                generated                                                   **
**                                                                            **
**                LMUREGACC_ACCBLOCKED - The test failed because an attempt to**
**                write to a protected register with a master that is not     **
**                allowed  got not blocked                                    **
**                                                                            **
**                LMUREGACC_STUCKATFAULT - Test failed because there seems to **
**                be a stuck-at fault within the CPU’s ACCENA register        **
**                                                                            **
**                LMUREGACC_TRAPERROR - Test failed because expected number   ** 
**                of traps did not occur                                      **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType LmuRegAccProtTst_lDenyAccTst
(
 uint32* const TstSignature,
 const uint8 CoreId
)
{
  Sl_TstRsltType      Result    = LMUREGACC_NOTEXECUTED;
  Sl_TstRsltType      TmpResult = LMUREGACC_NOTEXECUTED;
  /* Deny access to protected registers except CPUx.DMI safe */
  TmpResult = LmuRegAccProtTst_lDenyAccNonSafeTst(TstSignature,CoreId);

  if(TmpResult == LMUREGACC_SUCCESS)
  {
    /* Deny access to protected registers except CPUx.DMI nonsafe */
    Result = LmuRegAccProtTst_lDenyAccSafeTst(TstSignature,CoreId);
  }
  else
  {
    Result = TmpResult;
  }
  return(Result);
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType LmuRegAccProtTst_lDenyAccSafeTst                   **
**          (uint32* const TstSignature, const uint8 CoreId)                  **
**                                                                            **
**                                                                            **
** Description : This function does deny the access to the protected          **
**               registers except CPUx.DMI non-safe. After that               **
**               it tries to alter a protected register with CPUx.DMI         **
**               safe master and checks that those write access gets          **
**               actually blocked and that an SMU alarm was raised.           **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value : LMUREGACC_SUCCESS     - Test succeeded                      **
**                                                                            **
**                LMUREGACC_NOTEXECUTED - The test has not been executed or at**
**                least was interrupted before a valid result could be        **
**                generated                                                   **
**                                                                            **
**                LMUREGACC_STUCKATFAULT - Test failed because there seems to **
**                be a stuck-at fault within the CPU’s ACCENA register        **
**                                                                            **
**                LMUREGACC_ACCNOTBLOCKED - The test failed because an attempt**
**                to write to a protected register with a master that is not  **
**                allowed got not blocked                                     **
**                                                                            **
**                LMUREGACC_TRAPERROR - Test failed because expected number   ** 
**                of traps did not occur                                      **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType LmuRegAccProtTst_lDenyAccSafeTst
(
 uint32* const TstSignature,
 const uint8 CoreId
)

{
  uint32              Temp;
  Sl_TstRsltType      Result    = LMUREGACC_NOTEXECUTED;
  boolean             TmpResult = (boolean)FALSE;
  
  /* Non safe DMI Tag Id value for each core */
  uint32 LmuRegAccProtTst_kNonSafeDMIMasterEnable[] =
  {
    LMU_REG_ACC_CPU0_NON_SAFE_DMI_ACCEN,
    LMU_REG_ACC_CPU1_NON_SAFE_DMI_ACCEN,
    LMU_REG_ACC_CPU2_NON_SAFE_DMI_ACCEN
  };

  /* Switch processor status to non-safe task  */
  Temp = (uint32)MFCR(CPU_PSW);
  Temp &= (~LMU_REG_ACC_PSW_S_BIT);
  MTCR(CPU_PSW, Temp);

  /* Block all masters except CPU0 DMI.Non-safe            */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  LMU_ACCEN0.U = LmuRegAccProtTst_kNonSafeDMIMasterEnable[CoreId];
  Mcal_SetSafetyENDINIT_Timed();

  /* Check that ACCENA actually got written:                                */
  if (LmuRegAccProtTst_kNonSafeDMIMasterEnable[CoreId] == LMU_ACCEN0.U)
  {
    /* If the LmuRegAccTst_DaeTrapCount is not zero an unexpected trap 
       must have occurred*/
    if (LmuRegAccTst_DaeTrapCount != 0x0U)
    {
      Result = LMUREGACC_TRAPERROR;
    }
    else
    {        
      /* Trap expected here. expected trap class and ID is updated   */
      LmuRegAccTst_ExpectedTrapClass = LMU_REG_TRAP_CLASS4;
      LmuRegAccTst_ExpectedTrapId = LMU_REG_TRAP_ID3;
  
      /* Change CPU state to safe state and try to write into a register */
      TmpResult = 
           LmuRegAccProtTst_lSetAccEnSafeTask(LMU_DENY_SAFE_STATE_ENABLE_VAL);

      *TstSignature = (uint32)CRC32((uint32)*TstSignature, (uint32)TmpResult);
      /* Check that trap has occurred */
      if(LmuRegAccTst_DaeTrapCount == 1U)
      {
        /* If access is denied, allow all masters to access protected registers 
        and wait for SMU alarm */
        if((boolean)FALSE == TmpResult)
        {
          Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
          LMU_ACCEN0.U = LMU_REG_ACC_ALLOW_ALL_SRI_MASTERS;
          Mcal_SetSafetyENDINIT_Timed();

          Result = LmuRegAccProtTst_lWaitForSmuAlarm();
          /* Clear LmuRegAccTst_DaeTrapCount                                 */
          LmuRegAccTst_DaeTrapCount = 0x0U;          
        }
        else
        {
          Result = LMUREGACC_ACCNOTBLOCKED;
        }
      }
      else
      {
        Result = LMUREGACC_TRAPERROR;
      }
   } /*(Result != LMUREGACC_TRAPERROR) */
    
  } /* (LmuRegAccProtTst_kNonSafeDMIMasterEnable[CoreId] == LMU_ACCEN0.U) */
  else
  {
    Result = LMUREGACC_STUCKATFAULT;
  }
  
  return(Result);
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType LmuRegAccProtTst_lDenyAccNonSafeTst                **
**          (uint32* const TstSignature, const uint8 CoreId)                  **
**                                                                            **
**                                                                            **
** Description : This function does deny the access to the protected          **
**               registers except CPUx.DMI safe. After that it                **
**               tries to alter a protected register with CPUx.DMI non-safe   **
**               master and checks that those write access gets actually      **
**               blocked and that an SMU alarm was raised.                    **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value : LMUREGACC_SUCCESS     - Test succeeded                      **
**                                                                            **
**                LMUREGACC_NOTEXECUTED - The test has not been executed or at**
**                least was interrupted before a valid result could be        **
**                generated                                                   **
**                                                                            **
**                LMUREGACC_STUCKATFAULT - Test failed because there seems to **
**                be stuck-at fault within the CPU’s ACCENA register          **
**                                                                            **
**                LMUREGACC_ACCNOTBLOCKED - The test failed because an attempt**
**                to write to a protected register with a master that is not  **
**                allowed got not blocked                                     **
**                                                                            **
**                LMUREGACC_TRAPERROR - Test failed because expected number   ** 
**                of traps did not occur                                      **
**                                                                            **
*******************************************************************************/

static Sl_TstRsltType LmuRegAccProtTst_lDenyAccNonSafeTst
(
 uint32* const TstSignature,
 const uint8 CoreId
)
{
  uint32                 Temp;
  Sl_TstRsltType         Result    = LMUREGACC_NOTEXECUTED;
  boolean                TmpResult = (boolean)FALSE;
  
  /* Safe DMI Tag Id value for each core */
  uint32 LmuRegAccProtTst_kSafeDMIMasterEnable[] =
  {
    LMU_REG_ACC_CPU0_SAFE_DMI_ACCEN,
    LMU_REG_ACC_CPU1_SAFE_DMI_ACCEN,
    LMU_REG_ACC_CPU2_SAFE_DMI_ACCEN
  };

  /* Switch processor status to safe task    */
  Temp = (uint32)MFCR(CPU_PSW);
  Temp |= LMU_REG_ACC_PSW_S_BIT;
  MTCR(CPU_PSW, Temp);

  /* Block all masters except CPU0 DMI.Safe                 */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  LMU_ACCEN0.U = LmuRegAccProtTst_kSafeDMIMasterEnable[CoreId];
  Mcal_SetSafetyENDINIT_Timed();

  /* Check that ACCENA actually got written:                                */
  if (LmuRegAccProtTst_kSafeDMIMasterEnable[CoreId] == LMU_ACCEN0.U)
  {
    /* If the LmuRegAccTst_DaeTrapCount isn't zero an unexpected
       trap must have occurred*/
    if (LmuRegAccTst_DaeTrapCount != 0U)
    {
      Result = LMUREGACC_TRAPERROR;
    }
    else
    {
      /* Trap expected here. expected trap class and ID is updated   */
      LmuRegAccTst_ExpectedTrapClass = LMU_REG_TRAP_CLASS4;
      LmuRegAccTst_ExpectedTrapId = LMU_REG_TRAP_ID3;
  
      /* Change CPU state to non-safe state and try to write into a register.
      Making the unsuccessful write to LMU_BUFCON0 will cause  DAE trap. */  
      TmpResult = 
         LmuRegAccProtTst_lSetAccEnNonSafeTask(LMU_DENY_SAFE_TASK_ENABLE_VAL);

      *TstSignature = (uint32)CRC32((uint32)*TstSignature, (uint32)TmpResult);
    
      /* If access is denied, allow all masters to access protected registers
         and wait for SMU alarm */
      if(LmuRegAccTst_DaeTrapCount == 1U)
      {
        if((boolean)FALSE == TmpResult)
        {
          Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
          /* This allows all masters to access the SFRs. */
          LMU_ACCEN0.U = LMU_REG_ACC_ALLOW_ALL_SRI_MASTERS;
          Mcal_SetSafetyENDINIT_Timed();
      
          Result = LmuRegAccProtTst_lWaitForSmuAlarm();
      
          /* Clear DAE TrapCounter                                           */
         LmuRegAccTst_DaeTrapCount = 0x0U;         
        }
        else
        {
          Result = LMUREGACC_ACCNOTBLOCKED;
        }
      }
      else
      {
        Result = LMUREGACC_TRAPERROR;
      }
    }  /* (Result != LMUREGACC_TRAPERROR) */
  } /* (LmuRegAccProtTst_kSafeDMIMasterEnable[CoreId] == LMU_ACCEN0.U) */
  else
  {
    Result = LMUREGACC_STUCKATFAULT;
  }

  return(Result);
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : boolean LmuRegAccProtTst_lSetAccEnNonSafeTask(const uint32 Value) **
**                                                                            **
** Description : Switches the CPU status to non-safe task and tries to write  **
**               a new value to the LMU_BUFCON0 register.                     **
**               Dependent of the current configuration this write will be    **
**               blocked or granted.                                          **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : Value - The new value that will be written to register   **
**                   LMU_BUFCON0                                              **
**                                                                            **
** Parameters (out):                                                          **
**                                                                            **
** Return value : TRUE - if write access was granted,                         **
**                FALSE - if write access was blocked                         **
**                                                                            **
*******************************************************************************/
static boolean LmuRegAccProtTst_lSetAccEnNonSafeTask
(
 const uint32 Value
)
{
  uint32  Temp;
  boolean Result = (boolean)FALSE;

  /* Switch processor status to non-safe task */
  Temp = (uint32)MFCR(CPU_PSW);
  Temp &= (~LMU_REG_ACC_PSW_S_BIT);
  MTCR(CPU_PSW, Temp);
  
  /* Write the new value in to LMU_BUFCON0 register */
  Mcal_ResetENDINIT();
  LMU_BUFCON0.U = Value;
  Mcal_SetENDINIT();

  /* Read back LMU_BUFCON0 and check that write access was granted/blocked */
  if (Value == LMU_BUFCON0.U)
  {
    Result = (boolean)TRUE;
  }

  return Result;
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : boolean LmuRegAccProtTst_lSetAccEnSafeTask(const uint32 Value)    **
**                                                                            **
** Description : Switches the CPU status to safe task and tries to write a    **
**               new value to the LMU_BUFCON0 register.                       **
**               Dependent of the current configuration this write will be    **
**               blocked or granted.                                          **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : Value - The new value that will be written to register   **
**                   LMU_BUFCON0                                              **
**                                                                            **
** Parameters (out):                                                          **
**                                                                            **
** Return value : TRUE - if write access was granted,                         **
**                FALSE - if write access was blocked                         **
**                                                                            **
*******************************************************************************/
static boolean LmuRegAccProtTst_lSetAccEnSafeTask
(
 const uint32 Value
)
{
  uint32    Temp;
  boolean Result = (boolean)FALSE;

  /* Switch processor status to safe task */
  Temp = (uint32)MFCR(CPU_PSW);
  Temp |= LMU_REG_ACC_PSW_S_BIT;
  MTCR(CPU_PSW, Temp);

  Mcal_ResetENDINIT();
  LMU_BUFCON0.U = Value;
  Mcal_SetENDINIT();

  /* Read back LMU_BUFCON0 and check that write access was blocked */
  if (Value == LMU_BUFCON0.U)
  {
    Result = (boolean)TRUE;
  }

  return Result;
}

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType LmuRegAccProtTst_lWaitForSmuAlarm(void)            **
**                                                                            **
** Description : This function does wait for the SMU MPU alarm of the current **
**               tested LMU that is raised if an access to a protected        **
**               register is made from a master that is not allowed to do     **
**               such an access. If the SMU alarm is not being                **
**               generated / reported within a given amount of time the       **
**               function returns a fail.                                     **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value : LMUREGACC_SUCCESS     - Test succeeded                      **
**                                                                            **
**                LMUREGACC_NOTEXECUTED - The test has not been executed or at**
**                least was interrupted before a valid result could be        **
**                generated                                                   **
**                                                                            **
**                LMUREGACC_SMU_CLRALMSTSERR - The test failed because        **
**                clearing the SMU alarm failed.                              **
**                                                                            **
**                                                                            **
**                LMUREGACC_SMU_GETALMACTIONERR - Test failed because getting **
**                SMU alarm action failed.                                    **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType LmuRegAccProtTst_lWaitForSmuAlarm(void)
{
  uint32          AlmStatus1 = 0U;
  uint32          AlmStatus2 = 0U;
  uint32          Timeout    = LMU_REG_ACC_SMU_ALM_TIMEOUT;
  Sl_TstRsltType  Result     = LMUREGACC_NOTEXECUTED;
  
  /* Wait till the Alarm is set for LMU MPU */
  while((0U == (AlmStatus1 & ((uint32)1U << SMU_ALARM_16))) && ((Timeout) > 0U))
  {
    Timeout--;
    if (E_OK != Smu_GetAlarmStatus(LMU_REG_ACC_SMU_LMU_ERROR_GRP,
    &AlmStatus1))
    {
      AlmStatus1 = 0U;
      Timeout = 0U;
      Result = LMUREGACC_SMU_GETALMSTSERR;
    }
  }

  /* Timeout delay value is intialized again for the alarm to occur*/
  Timeout   = LMU_REG_ACC_SMU_ALM_TIMEOUT;
  
  /* Wait till the Alarm is set for SRI Bus*/
  while((0U == (AlmStatus2 & ((uint32)1U << SMU_ALARM_30))) && ((Timeout) > 0U))
  {
    Timeout--;
    if (E_OK != Smu_GetAlarmStatus(LMU_REG_ACC_SMU_SRI_ERROR_GRP,
    &AlmStatus2))
    {
      AlmStatus2 = 0U;
      Timeout = 0U;
      Result = LMUREGACC_SMU_GETALMSTSERR;
    }
  }
  
  /* Check if Alarm is set before */
  if (0U != (AlmStatus1 & ((uint32)1U << SMU_ALARM_16)))     
  {
    /* If Alarm was set, then clear the alarm */
    if(E_OK != Smu_ClearAlarmStatus(LMU_REG_ACC_SMU_LMU_ERROR_GRP,
    SMU_ALARM_16))
    {
      Result = LMUREGACC_SMU_CLRALMSTSERR;
    }    
  } /* if (0U != (AlmStatus1 & ((uint32)1U << SMU_ALARM_16))) */
  else
  {
    if (LMUREGACC_SMU_GETALMSTSERR != Result)
	{
      Result = LMUREGACC_SMU_ALMSTSERR; 
	}    
  }
  
  /* Check if Alarm is set before */
  if (0U != (AlmStatus2 & ((uint32)1U << SMU_ALARM_30)))
  {
    /* If Alarm was set, then clear the alarm */
    if(E_OK != Smu_ClearAlarmStatus(LMU_REG_ACC_SMU_SRI_ERROR_GRP,
        SMU_ALARM_30))
    {
      Result = LMUREGACC_SMU_CLRALMSTSERR;
    }
  } /* if (0U != (AlmStatus2 & ((uint32)1U << SMU_ALARM_30))) */  
  else
  {
    if (LMUREGACC_SMU_GETALMSTSERR != Result)
	{
      Result = LMUREGACC_SMU_ALMSTSERR; 
	}
  }

  /* No alarm was set*/
  if(Result == LMUREGACC_NOTEXECUTED)
  {
    Result = LMUREGACC_SUCCESS;
  } /* if(Result == LMUREGACC_NOTEXECUTED) */
  
  return(Result);
}


#define IFX_LMUREGACCPROTTST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
