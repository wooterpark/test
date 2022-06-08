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
**  $FILENAME   : RegAccProtTst.c $                                          **
**                                                                            **
**  $CC VERSION : \main\37 $                                                 **
**                                                                            **
**  $DATE       : 2018-02-22 $                                               **
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
**                 the CPU Register Access Protection.                        **
**                                                                            **
**  REFERENCE(S) : Aurix-HE_SafeTlib_DS_CPU_RegAcc_Prot_Test, v1.1            **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Mcal.h"
#include "RegAccProtTst.h"
#include "IfxCpu_reg.h"
#include "IfxCpu_bf.h"

/*******************************************************************************
**                      Local Macro Definitions                               **
*******************************************************************************/

/* ACCEN bitmasks for CPU0 DMI.NonSafe and CPU0 DMI.Safe Master TAG IDs:      */
#define REG_ACC_CPU0_NON_SAFE_DMI_ACCEN     ((uint32)0x00000001U )
#define REG_ACC_CPU0_SAFE_DMI_ACCEN         ((uint32)0x00000002U )

/* ACCEN bitmasks for CPU1 DMI.NonSafe and CPU1 DMI.Safe Master TAG IDs:      */
#define REG_ACC_CPU1_NON_SAFE_DMI_ACCEN     ((uint32)0x00000004U )
#define REG_ACC_CPU1_SAFE_DMI_ACCEN         ((uint32)0x00000008U )

/* ACCEN bitmasks for CPU2 DMI.NonSafe and CPU2 DMI.Safe Master TAG IDs:      */
#define REG_ACC_CPU2_NON_SAFE_DMI_ACCEN     ((uint32)0x00000010U )
#define REG_ACC_CPU2_SAFE_DMI_ACCEN         ((uint32)0x00000020U )

/* SMU alarm timeout. The value was chosen based on following considerations:
 * The worst case number of SMU cycles before an alarm gets visible is
 * n * 2 + 20 (with n = max. number of simultaneous alarms). With a maximum
 * of 32 * 7 alarms and maximum clock ratio fSPB/fSRI = 1/4 this evaluates to
 * 1872 CPU clock cycles. To avoid the counting the number of instructions per
 * loop cycle, it is assumed that only one instruction is executed per loop
 * cycle and thus the number of CPU clock cycles is directly used as timeout
 * value:
 */
#define REG_ACC_SMU_ALM_TIMEOUT             ((uint32)0x00002000U )
/*enable access for all masters*/
#define REG_ACC_ALL_MASTERS                 ((uint32)0xFFFFFFFFU)
#define REG_ACC_NON_SAFE_TASK               (0U)
#define REG_ACC_SAFE_TASK                   (1U)

#define ALLOW_ACCESS                         (TRUE)
#define DENY_ACCESS                          (FALSE)




/*******************************************************************************
**                      Local Type Definitions                                **
*******************************************************************************/

/* Storage for backup of the SMU CPUx MPU error alarm action.
 * (SMU Group x Alarm 1)
 */
typedef struct RegAccProtTst_BackupDataType
{
  Smu_AlarmActionType AlmActionBackupCpuMpu; /*Storage for backup of the
                        SMU CPUx MPU error alarm action. (SMU Group x Alarm 1)*/
  uint32 CpuSprotAccenaBackup; /* Storage for the backup of the current CPU
                                  Accena register */
}RegAccProtTst_BackupDataType;

/*******************************************************************************
**                        Exported object definitions                         **
*******************************************************************************/

/*******************************************************************************
**                        Local object definitions                            **
*******************************************************************************/

#define IFX_REGACCPROTTST_START_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"

/* Constant Non safe DMI Tag Id value for each core */
static const uint32 RegAccProtTst_kNonSafeDMIMasterEnable[MCAL_NO_OF_CORES] =
{
  REG_ACC_CPU0_NON_SAFE_DMI_ACCEN,
#if ( MCAL_NO_OF_CORES > 1U )  
  REG_ACC_CPU1_NON_SAFE_DMI_ACCEN,
#if ( MCAL_NO_OF_CORES == 3U )
  REG_ACC_CPU2_NON_SAFE_DMI_ACCEN
#endif
#endif
};

/* Constant Safe DMI Tag Id value for each core */
static const uint32 RegAccProtTst_kSafeDMIMasterEnable[MCAL_NO_OF_CORES] =
{
  REG_ACC_CPU0_SAFE_DMI_ACCEN,
#if ( MCAL_NO_OF_CORES > 1U )  
  REG_ACC_CPU1_SAFE_DMI_ACCEN,
#if ( MCAL_NO_OF_CORES == 3U )
  REG_ACC_CPU2_SAFE_DMI_ACCEN
#endif
#endif
};

#define IFX_REGACCPROTTST_STOP_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"


#define IFX_REGACCPROTTST_START_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"

/* Constant SMU alarms for Reg access violation for each core */
static const uint8 RegAccProtTst_kSmuAlmGrp[MCAL_NO_OF_CORES] =
{
  SMU_ALARM_GROUP0,
#if ( MCAL_NO_OF_CORES > 1U )    
  SMU_ALARM_GROUP1,
#if ( MCAL_NO_OF_CORES == 3U )
  SMU_ALARM_GROUP6
#endif
#endif
};

#define IFX_REGACCPROTTST_STOP_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_REGACCPROTTST_START_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

/*addresses for Access enable registers to verify register access protection*/
static  volatile Ifx_CPU_SPROT_ACCENA* const RegAccProtTst_ACCENARegGrp[MCAL_NO_OF_CORES] =
{
  &CPU0_SPROT_ACCENA,
#if ( MCAL_NO_OF_CORES > 1U )
  &CPU1_SPROT_ACCENA,
#if ( MCAL_NO_OF_CORES == 3U )
  &CPU2_SPROT_ACCENA
#endif
#endif
};

#define IFX_REGACCPROTTST_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                        Imported function declarations                      **
*******************************************************************************/

/*******************************************************************************
**                        Local function prototypes                           **
*******************************************************************************/
#define IFX_REGACCPROTTST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
static Sl_TstRsltType RegAccProtTst_lAccessControlTst
(
  boolean AccessControl, boolean CpuPsw
);
static Sl_TstRsltType RegAccProtTst_lEnableAccessToAllMasters
(
  uint32 AccEnable
);
static Sl_TstRsltType RegAccProtTst_lInit
(
 RegAccProtTst_BackupDataType* const BackupData
);

static Sl_TstRsltType RegAccProtTst_lRestore
(
 const RegAccProtTst_BackupDataType* const BackupData
);

static Sl_TstRsltType RegAccProtTst_lWaitForSmuAlarm
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
** Syntax : Sl_TstRsltType RegAccProtTst_RegAccProtTst                        **
**          (                                                                 **
**             const  Sl_ParamSetIndex ParamSetIndex,                         **
**             const  uint8 TstSeed,                                          **
**             uint32* const TstSignature                                     **
**          )                                                                 **
**                                                                            **
** Description : This test checks that the register protection scheme does    **
**               work as expected. To verify this, the following actions are  **
**               being executed:                                              **
**               • Allow all masters access to the protected registers        **
**               • Use different masters (Current CPU’s DMI safe and non-safe **
**                 master) and alter a protected register. Check that the     **
**                 register contents actually got changed.                    **
**               • Deny all masters, except one e.g CPU.DMI safe/non safe, to ** 
**                 access the protected registers                             **
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
** Return value : REGACC_SUCCESS     - Test succeeded                         **
**                                                                            **
**                REGACC_SMU_STATEERR - The test cannot be executed because   **
**                the SMU is in the wrong state                               **
**                                                                            **
**                REGACC_SMU_GETALMSTSERR - Test failed because getting the   **
**                SMU alarm status failed                                     **
**                                                                            **
**                REGACC_SMU_CLRALMSTSERR - The test failed because clearing  **
**                the SMU alarm failed.                                       **
**                                                                            **
**                REGACC_ SMU_ALMSTSERR - Test failed because there is already**
**                a watchdog alarm present within the SMU.                    **
**                                                                            **
**                REGACC_SMU_SETALMACTIONERR - Test failed because setting the**
**                SMU alarm action failed.                                    **
**                                                                            **
**                REGACC_SMU_GETALMACTIONERR - Test failed because getting the**
**                SMU alarm action failed.                                    **
**                                                                            **
**                REGACC_DENY_NOSMUALRM - Test failed because no SMU alarm    **
**                was generated also a not allowed master tried to write to a **
**                protected register.                                         **
**                                                                            **
**                REGACC_STUCKATFAULT - Test failed because there seems to be **
**                a stuck-at fault within the CPU’s ACCENA register           **
**                                                                            **
**                REGACC_ACCBLOCKED - The test failed because an attempt to   **
**                write to a protected register with a master that is allowed **
**                got anyway blocked                                          **
**                                                                            **
**                REGACC_ACCNOTBLOCKED - The test failed because an attempt   **
**                to write to a protected register with a master that is not  **
**                allowed  got not blocked                                    **
*******************************************************************************/
Sl_TstRsltType RegAccProtTst_RegAccProtTst
(
 const Sl_ParamSetType ParamSetIndex,
 const uint8 TstSeed,
 uint32* const TstSignature
)
{
  Sl_TstRsltType               Result;
  Sl_TstRsltType               ResultTmp;
  RegAccProtTst_BackupDataType BackupData;

  UNUSED_PARAMETER(ParamSetIndex)
  
  /* Initialize Test Signature:                                               */
  *TstSignature =
  (uint32)CRC32((uint32)TEST_ID_REG_ACC_PROT_TST, (uint32)TstSeed);
  /* Check if SMU is in RUN state                                             */
  if(SMU_RUN_STATE == Smu_GetSmuState())
  {
    /*Backup SMU alarms and SFR configs that will be modified*/
    Result = RegAccProtTst_lInit(&BackupData);
    if(Result == (Sl_TstRsltType)REGACC_SUCCESS)
    {
      /* Allow all masters to access protected registers                      */
      Result = RegAccProtTst_lAccessControlTst(ALLOW_ACCESS, REG_ACC_SAFE_TASK);
      *TstSignature = (uint32)CRC32(*TstSignature,ALLOW_ACCESS);    
      if(Result == (Sl_TstRsltType)REGACC_SUCCESS)
      {
        Result = RegAccProtTst_lAccessControlTst(ALLOW_ACCESS, REG_ACC_NON_SAFE_TASK);   
        *TstSignature = (uint32)CRC32(*TstSignature,ALLOW_ACCESS);  
        if(Result == (Sl_TstRsltType)REGACC_SUCCESS)
        {
          /* Deny access to protected registers except CPux.DMI*/
          Result = RegAccProtTst_lAccessControlTst(DENY_ACCESS, REG_ACC_SAFE_TASK);
          *TstSignature = (uint32)CRC32(*TstSignature,DENY_ACCESS);   
          if(Result == (Sl_TstRsltType)REGACC_SUCCESS)
          { 
            /* Deny access to protected registers except CPux.DMI*/
            Result = RegAccProtTst_lAccessControlTst(DENY_ACCESS, REG_ACC_NON_SAFE_TASK);
            *TstSignature = (uint32)CRC32(*TstSignature,DENY_ACCESS);
          }/*if(Result == (Sl_TstRsltType)REGACC_SUCCESS)*/
        }/*if(Result == (Sl_TstRsltType)REGACC_SUCCESS)*/
      }/*if(Result == (Sl_TstRsltType)REGACC_SUCCESS)*/
    }/*if(Result == (Sl_TstRsltType)REGACC_SUCCESS)*/
    ResultTmp = RegAccProtTst_lRestore(&BackupData);
    if(Result == REGACC_SUCCESS)
    {
      Result = ResultTmp;
    }/*if(Result == REGACC_SUCCESS)*/
    *TstSignature = (uint32)CRC32(*TstSignature,Result);
  }/*if(SMU_RUN_STATE == Smu_GetSmuState())*/
  else
  {
    Result = (Sl_TstRsltType)REGACC_SMU_STATEERR;
  }/*if(SMU_RUN_STATE == Smu_GetSmuState())*/

  return(Result);
}/*Sl_TstRsltType RegAccProtTst_RegAccProtTst*/


/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstResultType RegAccProtTst_lInit                              **
**          (RegAccProtTst_BackupDataType * const BackupData)                 **
**                                                                            **
** Description : Does a backup of the current SMU alarm actions and the SFR-  **
**               registers that will be overwritten by this test. It also     **
**               sets the SMU actions for the CPUx Mpu alarm to “no action”.  **
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
** Parameters (out): BackupData - Holds a backup of the                       **
**                   current SMU alarm action configuration of the SMU alarms **
**                   and the SFR configuration that will be changed by this   **
**                   test                                                     **
**                                                                            **
** Return value : REGACC_SUCCESS     - Test succeeded                         **
**                                                                            **
**                REGACC_SMU_GETALMSTSERR - Test failed because getting the   **
**                SMU alarm status failed                                     **
**                                                                            **
**                REGACC_SMU_CLRALMSTSERR - The test failed because clearing  **
**                the SMU alarm failed.                                       **
**                                                                            **
**                REGACC_SMU_ALMSTSERR - Test failed because there is already **
**                a watchdog alarm present within the SMU.                    **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType RegAccProtTst_lInit
(
 RegAccProtTst_BackupDataType* const BackupData
)
{
  Sl_TstRsltType      Result;
  uint32              AlmStatus;
  Smu_FSPActionType   FspActionDummy;
  uint8               CoreId;
  
  CoreId = Mcal_GetCoreId();
  /* Store CPUx_SPROT_ACCENA register */
  BackupData->CpuSprotAccenaBackup =
  RegAccProtTst_ACCENARegGrp[CoreId]->U;
  
  /* Get the SMU alarm action for Group 1 alarm 1 */
  if(E_OK != (Smu_GetAlarmAction(RegAccProtTst_kSmuAlmGrp[CoreId], SMU_ALARM_1,
  &BackupData->AlmActionBackupCpuMpu, &FspActionDummy)))
  {
    Result = REGACC_SMU_GETALMACTIONERR;
    /* Set to Invalid Alarm Action */
    BackupData->AlmActionBackupCpuMpu = SMU_INVALID_ALARM_ACTION;
  }  /*if(E_OK != (Smu_GetAlarmAction(RegAccProtTst_kSmuAlmGrp[CoreId], SMU_ALARM_1,
          &BackupData->AlmActionBackupCpuMpu, &FspActionDummy)))*/
  else
  {
    /* Get SMU Alarm Status and check operation was done properly*/
    if(E_OK !=
    (Smu_GetAlarmStatus(RegAccProtTst_kSmuAlmGrp[CoreId], &AlmStatus)))
    {
      Result = REGACC_SMU_GETALMSTSERR;
    }/*if(E_OK !=
       (Smu_GetAlarmStatus(RegAccProtTst_kSmuAlmGrp[CoreId], &AlmStatus)))*/
    else
    {
      /* Check if the SMU Alarm is present or not */
      if(0U != (AlmStatus & ((uint32)1U << SMU_ALARM_1)))
      {
        Result = REGACC_SMU_ALMSTSERR;
      }/*if(0U != (AlmStatus & ((uint32)1U << SMU_ALARM_1)))*/
      else
      {
        /*Set the CPU MPU alarm action to none and check if setting was fine */
        if(E_OK !=
        Smu_SetAlarmAction(RegAccProtTst_kSmuAlmGrp[CoreId], SMU_ALARM_1,
        SMU_ALARM_ACTION_NONE))
        {
          Result = REGACC_SMU_SETALMACTIONERR;
        }/*if(E_OK !=
              Smu_SetAlarmAction(RegAccProtTst_kSmuAlmGrp[CoreId], SMU_ALARM_1,
              SMU_ALARM_ACTION_NONE))*/
        else
        {
          Result = REGACC_SUCCESS;
        }/*if(E_OK !=
              Smu_SetAlarmAction(RegAccProtTst_kSmuAlmGrp[CoreId], SMU_ALARM_1,
              SMU_ALARM_ACTION_NONE))*/
      }/*if(0U != (AlmStatus & ((uint32)1U << SMU_ALARM_1)))*/
    }/*if(E_OK !=
       (Smu_GetAlarmStatus(RegAccProtTst_kSmuAlmGrp[CoreId], &AlmStatus)))*/
  }/*if(E_OK != (Smu_GetAlarmAction(RegAccProtTst_kSmuAlmGrp[CoreId], SMU_ALARM_1,
          &BackupData->AlmActionBackupCpuMpu, &FspActionDummy)))*/
  return(Result);
}/*static Sl_TstRsltType RegAccProtTst_lInit*/


/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstResultType RegAccProtTst_lRestore                           **
**         (const RegAccProtTst_BackupDataType * const BackupData)            **
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
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): BackupData - Holds a backup of the                       **
**                   SMU alarm action configuration of the SMU alarms         **
**                   and the SFR configuration that got overwritten by this   **
**                   test                                                     **
** Return value : REGACC_SUCCESS     - Test succeeded                         **
**                                                                            **
**                REGACC_SMU_SETALMACTIONERR - Test failed because setting the**
**                SMU alarm action failed.                                    **
**                                                                            **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType RegAccProtTst_lRestore
(
 const RegAccProtTst_BackupDataType* const BackupData
)
{
  Sl_TstRsltType      Result;
  uint8               CoreId;
  
  CoreId = Mcal_GetCoreId();
  
  /* Restore previously backed-up CPU0_SPROT_ACCENA value:                  */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  RegAccProtTst_ACCENARegGrp[CoreId]->U =
  BackupData->CpuSprotAccenaBackup;
  Mcal_SetSafetyENDINIT_Timed();

  /*Restore the stored SMU alarms */
  /* If restore was successful , send REGACC_SUCCESS*/
  if(E_OK!= Smu_SetAlarmAction(RegAccProtTst_kSmuAlmGrp[CoreId], SMU_ALARM_1,
            BackupData->AlmActionBackupCpuMpu))
  {
    Result = REGACC_SMU_SETALMACTIONERR;
  }/*if(E_OK!= Smu_SetAlarmAction(RegAccProtTst_kSmuAlmGrp[CoreId], SMU_ALARM_1,
            BackupData->AlmActionBackupCpuMpu))*/
  else
  {
    Result = REGACC_SUCCESS;
  }/*if(E_OK!= Smu_SetAlarmAction(RegAccProtTst_kSmuAlmGrp[CoreId], SMU_ALARM_1,
            BackupData->AlmActionBackupCpuMpu))*/
  
  return(Result);
}/*static Sl_TstRsltType RegAccProtTst_lRestore*/


/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType RegAccProtTst_lAccessControlTst                    **
**          (boolean AccessControl, boolean CpuPsw)                           **
**                                                                            **
**                                                                            **
** Description : This function does control the access to the protected       **
**               registers. Depending on input parameters                     **
**              CpuPsw- it switches CPU to CPUx.DMI safe/non-safe             **
**              AccessControl- It enables access to protected registers       **
**              After that it tries to alter a protected register             **
**              In case:                                                      **
**              AccessControl - ALLOW_ACCESS, access to all masters is allowed**
**              AccessControl - DENY_ACCESS,  access to present CPUx.DMI      **
**                              masters is actually blocked and that an SMU   **
**                              alarm was raised.                             **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : AccessControl - ALLOW/DENY ACCESS                        **
**                  CpuPsw         - CPU state to be set safe/Non Safe        **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value : REGACC_SUCCESS     - Test succeeded                         **
**                                                                            **
**                REGACC_STUCKATFAULT - Test failed because there seems to be **
**                a stuck-at fault within the CPU’s ACCENA register           **
**                                                                            **
**                REGACC_ACCNOTBLOCKED - The test failed because an attempt   **
**                to write to a protected register with a master that is not  **
**                allowed got not blocked                                     **
**                                                                            **
**                REGACC_ACCBLOCKED - The test failed because an attempt      **
**                to write to a protected register with a master got blocked  **
**                when access to all masters is enabled                       **
*******************************************************************************/
static Sl_TstRsltType RegAccProtTst_lAccessControlTst
(
 boolean AccessControl, boolean CpuPsw
)

{
  Sl_TstRsltType      Result;
  Sl_TstRsltType      ResultTmp;
  uint32              Temp;
  uint32              AccEnable;
  uint8               CoreId;
  
  CoreId = Mcal_GetCoreId();
  
  if(CpuPsw == REG_ACC_NON_SAFE_TASK)
  {
    /* Switch processor status to non-safe task */
    Temp = (uint32)MFCR(CPU_PSW);
    Temp &= ((uint32)~(((uint32)1U << (uint32)IFX_CPU_PSW_S_OFF)));
    MTCR(CPU_PSW, Temp);
  }/*if(CpuPsw == REG_ACC_NON_SAFE_TASK)*/
  else
  {
    /* Switch processor status to safe task */
    Temp = (uint32)MFCR(CPU_PSW);
    Temp |= (((uint32)1U << (uint32)IFX_CPU_PSW_S_OFF));
    MTCR(CPU_PSW, Temp); 
  }/*if(CpuPsw == REG_ACC_NON_SAFE_TASK)*/
  
  if(AccessControl == ALLOW_ACCESS)
  {
    AccEnable =  REG_ACC_ALL_MASTERS;
  }/*if(AccessControl == ALLOW_ACCESS)*/
  else if(CpuPsw == REG_ACC_NON_SAFE_TASK)
  {
    AccEnable = RegAccProtTst_kSafeDMIMasterEnable[CoreId];
  }/*else if(CpuPsw == REG_ACC_NON_SAFE_TASK)*/
  else
  {
    AccEnable = RegAccProtTst_kNonSafeDMIMasterEnable[CoreId];
  }/*if(AccessControl == ALLOW_ACCESS)*/

  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  RegAccProtTst_ACCENARegGrp[CoreId]->U = AccEnable;
  Mcal_SetSafetyENDINIT_Timed();

  /* Check that ACCENA actually got written:                                */
  if (AccEnable ==  RegAccProtTst_ACCENARegGrp[CoreId]->U)
  {
    /* Set all bits in CPU0_SPROT_ACCEN0  */
    Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
    RegAccProtTst_ACCENARegGrp[CoreId]->U = REG_ACC_ALL_MASTERS;
    Mcal_SetSafetyENDINIT_Timed();
    if(AccessControl == DENY_ACCESS)
    {
      if(RegAccProtTst_ACCENARegGrp[CoreId]->U == REG_ACC_ALL_MASTERS)
      {
        Result = REGACC_ACCNOTBLOCKED;      
      }/*if(RegAccProtTst_ACCENARegGrp[CoreId]->U == REG_ACC_ALL_MASTERS)*/
      else
      {
        Result = RegAccProtTst_lWaitForSmuAlarm();
      }/*if(RegAccProtTst_ACCENARegGrp[CoreId]->U == REG_ACC_ALL_MASTERS)*/
      ResultTmp = RegAccProtTst_lEnableAccessToAllMasters(AccEnable);
      MTCR(CPU_PIETR, 0U);
      if(Result == REGACC_SUCCESS)
      {
        Result = ResultTmp;
      }/*if(Result == REGACC_SUCCESS)*/
    }/*if(AccessControl == DENY_ACCESS)*/
    else
    {
      if(RegAccProtTst_ACCENARegGrp[CoreId]->U == REG_ACC_ALL_MASTERS)
      {
        Result = REGACC_SUCCESS;      
      }/*if(RegAccProtTst_ACCENARegGrp[CoreId]->U == REG_ACC_ALL_MASTERS)*/
      else
      {
        Result = REGACC_ACCBLOCKED;
      }/*if(RegAccProtTst_ACCENARegGrp[CoreId]->U == REG_ACC_ALL_MASTERS)*/
    }/*if(AccessControl == DENY_ACCESS)*/
  }/*if (AccEnable ==  RegAccProtTst_ACCENARegGrp[CoreId]->U)*/
  else
  {
    Result = REGACC_STUCKATFAULT;
  }/*if (AccEnable ==  RegAccProtTst_ACCENARegGrp[CoreId]->U)*/

  return(Result);
}/*static Sl_TstRsltType RegAccProtTst_lAccessControlTst
                                            (
                                             boolean AccessControl, boolean CpuPsw
                                            )*/


/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType RegAccProtTst_lEnableAccessToAllMasters            **
**          (uint32 AccessEnable)                                             **
**                                                                            **
**                                                                            **
** Description : This function switches CPU to CPUx.DMI safe/non-safe         **
**               depending on input parameter AccEnable. After that it Enables**
**               access for all master by writing all FFs into register       **
**               CPUx_SPROT_ACCENA                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Non reentrant                                                  **
**                                                                            **
** Parameters (in) : AccEnable - Present Access Control Setting               **
** Parameters (out) : None                                                    **
** Return value : REGACC_SUCCESS     - Test succeeded                         **
**                                                                            **
**                REGACC_STUCKATFAULT - Test failed because there seems to be **
**                a stuck-at fault within the CPU’s ACCENA register           **
*******************************************************************************/
static Sl_TstRsltType RegAccProtTst_lEnableAccessToAllMasters(uint32 AccEnable)
{
  uint32              Temp;
  Sl_TstRsltType      Result;
  uint8               CoreId;
  
  CoreId = Mcal_GetCoreId();
  
  if(AccEnable == RegAccProtTst_kNonSafeDMIMasterEnable[CoreId])
  {
    /* Switch processor status to non-safe task */
    Temp = (uint32)MFCR(CPU_PSW);
    Temp &= ((uint32)~(((uint32)1U << (uint32)IFX_CPU_PSW_S_OFF)));
    MTCR(CPU_PSW, Temp);
  }/*if(AccEnable == RegAccProtTst_kNonSafeDMIMasterEnable[CoreId])*/
  else
  {
    /* Switch processor status to safe task */
    Temp = (uint32)MFCR(CPU_PSW);
    Temp |= (((uint32)1U << (uint32)IFX_CPU_PSW_S_OFF));
    MTCR(CPU_PSW, Temp); 
  } /*if(AccEnable == RegAccProtTst_kNonSafeDMIMasterEnable[CoreId])*/ 
  /* Set all bits in CPU0_SPROT_ACCEN0  */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  RegAccProtTst_ACCENARegGrp[CoreId]->U = REG_ACC_ALL_MASTERS;
  Mcal_SetSafetyENDINIT_Timed();  
  if(RegAccProtTst_ACCENARegGrp[CoreId]->U == REG_ACC_ALL_MASTERS)
  {
    Result = REGACC_SUCCESS;  
  }/*if(RegAccProtTst_ACCENARegGrp[CoreId]->U == REG_ACC_ALL_MASTERS)*/
  else
  {
    Result = REGACC_STUCKATFAULT;  
  }/*if(RegAccProtTst_ACCENARegGrp[CoreId]->U == REG_ACC_ALL_MASTERS)*/
  return(Result);
}
/*static Sl_TstRsltType RegAccProtTst_lEnableAccessToAllMasters(uint32 AccEnable)*/

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType RegAccProtTst_lWaitForSmuAlarm(void)               **
**                                                                            **
** Description : This function does wait for the SMU MPU alarm of the current **
**               tested CPU that is raised if an access to a protected        **
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
** Return value : REGACC_SUCCESS     - Test succeeded                         **
**                                                                            **
**                REGACC_NOTEXECUTED - The test has not been executed or at   **
**                least was interrupted before a valid result could be        **
**                generated                                                   **
**                                                                            **
**                REGACC_SMU_CLRALMSTSERR - The test failed because clearing  **
**                the SMU alarm failed.                                       **
**                                                                            **
**                REGACC_SMU_GETALMACTIONERR - Test failed because getting the**
**                SMU alarm action failed.                                    **
**                                                                            **
**                REGACC_DENY_NOSMUALRM - Test failed because no SMU alarm    **
**                was generated also a not allowed master tried to write to a **
**                protected register.                                         **
*******************************************************************************/
static Sl_TstRsltType RegAccProtTst_lWaitForSmuAlarm(void)
{
  uint32             AlmStatus = 0U;
  uint32             Timeout   = REG_ACC_SMU_ALM_TIMEOUT;
  Sl_TstRsltType     Result    = REGACC_NOTEXECUTED;
  uint8              CoreId;
  
  CoreId = Mcal_GetCoreId();

  /* Wait till the Alarm is set */
  while((0U == (AlmStatus & ((uint32)1U << SMU_ALARM_1))) && ((Timeout) > 0U))
  {
    Timeout--;
    if (E_OK != Smu_GetAlarmStatus(RegAccProtTst_kSmuAlmGrp[CoreId],
    &AlmStatus))
    {
      AlmStatus = 0U;
      Timeout = 0U;
      Result = REGACC_SMU_GETALMACTIONERR;
    }/*if (E_OK != Smu_GetAlarmStatus(RegAccProtTst_kSmuAlmGrp[CoreId],
    &AlmStatus))*/
  }/*while((0U == (AlmStatus & ((uint32)1U << SMU_ALARM_1))) && ((Timeout) > 0U))*/
  /* Check if Alarm is set before*/
  if (0U != (AlmStatus & ((uint32)1U << SMU_ALARM_1)))
  {
    /* If Alarm was set, the clear the alarm */
    if(E_OK == Smu_ClearAlarmStatus(RegAccProtTst_kSmuAlmGrp[CoreId],
    SMU_ALARM_1))
    {
      Result = REGACC_SUCCESS;
    }/*if(E_OK == Smu_ClearAlarmStatus(RegAccProtTst_kSmuAlmGrp[CoreId],
                                       SMU_ALARM_1))*/
    else
    {
      Result = REGACC_SMU_CLRALMSTSERR;
    }/*if(E_OK == Smu_ClearAlarmStatus(RegAccProtTst_kSmuAlmGrp[CoreId],
                                       SMU_ALARM_1))*/
  }/*if (0U != (AlmStatus & ((uint32)1U << SMU_ALARM_1)))*/
  /* No alarm was set*/
  else
  {
    if(Result == REGACC_NOTEXECUTED)
    {
      Result = REGACC_DENY_NOSMUALRM;
    }/*if(Result == REGACC_NOTEXECUTED)*/
  }/*if (0U != (AlmStatus & ((uint32)1U << SMU_ALARM_1)))*/
  return(Result);
}/*static Sl_TstRsltType RegAccProtTst_lWaitForSmuAlarm(void)*/


#define IFX_REGACCPROTTST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
