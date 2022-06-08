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
**   $FILENAME   : CpuBusMpuLfmTst.c $                                        **
**                                                                            **
**   $CC VERSION : \main\56 $                                                 **
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


#include "IfxScu_reg.h"
#include "IfxCpu_reg.h"
#include "IfxCpu_bf.h"
#include "Mcal_TcLib.h"
#include "CpuBusMpuLfmTst.h"
#include "CpuBusMpuLfmTst_Cfg.h"
#include "ChipId.h"
#include "Mcal.h"

/*******************************************************************************
**                      Local Macro Definitions                               **
*******************************************************************************/
/* Timeout count for the SMU to detect the fault and raise the alarm @ low SPB**
** clock scenario */

/* BUS MPU LFM SMU alarm timeout. The value was chosen based on following 
 * considerations: The worst case number of SMU cycles before an alarm gets 
 * visible is n * 2 + 20 (with n = max. number of simultaneous alarms). 
 * With a maximum of 32 * 7 alarms and maximum clock ratio fSPB/fSRI = 1/6 this
 * evaluates to 2808 CPU clock cycles. Hence the Alarm timeout value chosen is   
 * 2000U and it is sufficient as there are more than one instruction executed
 * per loop cycle. */
 
#define BUSMPULFM_NO_FAULT_TIMEOUT          (2000U)

/* Definition of SMU alarm groups, alarm IDs and alarm status bits required
   by the Bus MPU test:
*/
#define CBM_SMU_ALM_NOT_SET            (0U)

/* ACCEN bit masks for CPUx DMI.NonSafe and CPUx DMI.Safe Master TAG IDs */
#define CBM_CPU0_NON_SAFE_DMI_ACCEN     ( 0x00000001U )
#define CBM_CPU1_NON_SAFE_DMI_ACCEN     ( 0x00000004U )
#define CBM_CPU2_NON_SAFE_DMI_ACCEN     ( 0x00000010U )

#define CBM_CPU0_SAFE_DMI_ACCEN         ( 0x00000002U )
#define CBM_CPU1_SAFE_DMI_ACCEN         ( 0x00000008U )
#define CBM_CPU2_SAFE_DMI_ACCEN         ( 0x00000020U )

/* Master Tag IDs of CPU0_DMI.NonSafe and CPU0_DMI.Safe: */
#define CBM_CPU0_DMI_NON_SAFE_TAG_ID    ( 0x00000000U )
#define CBM_CPU1_DMI_NON_SAFE_TAG_ID    ( 0x00000002U )
#define CBM_CPU2_DMI_NON_SAFE_TAG_ID    ( 0x00000004U )

#define CBM_CPU0_DMI_SAFE_TAG_ID        ( 0x00000001U )
#define CBM_CPU1_DMI_SAFE_TAG_ID        ( 0x00000003U )
#define CBM_CPU2_DMI_SAFE_TAG_ID        ( 0x00000005U )

/* Integrity error (IE) bit mask in PIETR register */
#define CBM_PIETR_INTEGRITYERR_MASK  (0x381DU)

/* IE_BS, IE_SP and IED bit mask in PIETR register */
/* (IED = 1, IE_C = 0, IE_S = 0, IE_BI = 0, IE_UNC = 0, IE_SP = 1, IE_BS = 1) */
#define CBM_PIETR_IE_BUS_SPMEM       (0x3001U)

/* PSPR base address for each core */
#define CORE0_PSPR_BASEADDR  (0x70100000U)
#if ( MCAL_NO_OF_CORES > 1U )  
#define CORE1_PSPR_BASEADDR  (0x60100000U)
#if ( MCAL_NO_OF_CORES > 2U )  
#define CORE2_PSPR_BASEADDR  (0x50100000U)
#endif
#endif

/* PSPR end address for each core */
#if((CHIP_ID == 23U) || (CHIP_ID == 22U) || (CHIP_ID == 21U))
#define CORE0_PSPR_ENDADDR  (0x70101FFFU)
#elif(CHIP_ID == 26U)
#define CORE0_PSPR_ENDADDR  (0x70103FFFU)
#elif(CHIP_ID == 27U)
#define CORE0_PSPR_ENDADDR  (0x70105FFFU)
#elif(CHIP_ID == 29U)
#define CORE0_PSPR_ENDADDR  (0x70107FFFU)
#endif

#if ( MCAL_NO_OF_CORES > 1U )  
#define CORE1_PSPR_ENDADDR  (0x60107FFFU)
#if ( MCAL_NO_OF_CORES > 2U )  
#define CORE2_PSPR_ENDADDR  (0x50107FFFU)
#endif
#endif

#define CBM_DMI_NON_SAFE_MASTER    0U
#define CBM_DMI_SAFE_MASTER        1U

#define CBM_CPU_MPU_SIZE           32U
#define CBM_SIZEOFWORD              4U
#define CBM_SHIFT0                  0U
#define CBM_SHIFT8                  8U
#define CBM_SHIFT16                 16U
#define CBM_SHIFT24                 24U

/*******************************************************************************
**                      Local Type Definitions                                **
*******************************************************************************/

typedef struct CpuBusMpu_RangeRegMap
{
  volatile Ifx_CPU_SPROT_RGN_LA RGNLA0;
  volatile Ifx_CPU_SPROT_RGN_UA RGNUA0;
  volatile Ifx_CPU_SPROT_RGN_ACCENA RGNACCENA0;
  volatile Ifx_CPU_SPROT_RGN_ACCENB RGNACCENB0;
  volatile Ifx_CPU_SPROT_RGN_LA RGNLA1;
  volatile Ifx_CPU_SPROT_RGN_UA RGNUA1;
  volatile Ifx_CPU_SPROT_RGN_ACCENA RGNACCENA1;
  volatile Ifx_CPU_SPROT_RGN_ACCENB RGNACCENB1;
  volatile Ifx_CPU_SPROT_RGN_LA RGNLA2;
  volatile Ifx_CPU_SPROT_RGN_UA RGNUA2;
  volatile Ifx_CPU_SPROT_RGN_ACCENA RGNACCENA2;
  volatile Ifx_CPU_SPROT_RGN_ACCENB RGNACCENB2;
  volatile Ifx_CPU_SPROT_RGN_LA RGNLA3;
  volatile Ifx_CPU_SPROT_RGN_UA RGNUA3;
  volatile Ifx_CPU_SPROT_RGN_ACCENA RGNACCENA3;
  volatile Ifx_CPU_SPROT_RGN_ACCENB RGNACCENB3;
  volatile Ifx_CPU_SPROT_RGN_LA RGNLA4;
  volatile Ifx_CPU_SPROT_RGN_UA RGNUA4;
  volatile Ifx_CPU_SPROT_RGN_ACCENA RGNACCENA4;
  volatile Ifx_CPU_SPROT_RGN_ACCENB RGNACCENB4;
  volatile Ifx_CPU_SPROT_RGN_LA RGNLA5;
  volatile Ifx_CPU_SPROT_RGN_UA RGNUA5;
  volatile Ifx_CPU_SPROT_RGN_ACCENA RGNACCENA5;
  volatile Ifx_CPU_SPROT_RGN_ACCENB RGNACCENB5;
  volatile Ifx_CPU_SPROT_RGN_LA RGNLA6;
  volatile Ifx_CPU_SPROT_RGN_UA RGNUA6;
  volatile Ifx_CPU_SPROT_RGN_ACCENA RGNACCENA6;
  volatile Ifx_CPU_SPROT_RGN_ACCENB RGNACCENB6;
  volatile Ifx_CPU_SPROT_RGN_LA RGNLA7;
  volatile Ifx_CPU_SPROT_RGN_UA RGNUA7;
  volatile Ifx_CPU_SPROT_RGN_ACCENA RGNACCENA7;
  volatile Ifx_CPU_SPROT_RGN_ACCENB RGNACCENB7;
}CpuBusMpu_RangeRegMapType;



/******************************************************************************
**                        Exported object definitions                         *
******************************************************************************/

/******************************************************************************
**                        Local object definitions                            *
******************************************************************************/


#define IFX_CPUBUSMPULFM_START_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

/* Starting address of each core SPROT register sets. */
static volatile CpuBusMpu_RangeRegMapType* const CBM_RGNRegGrp[] =
{
  (volatile CpuBusMpu_RangeRegMapType*)(volatile void *)(&CPU0_SPROT_RGN0_LA),
#if ( MCAL_NO_OF_CORES > 1U ) 
  (volatile CpuBusMpu_RangeRegMapType*)(volatile void *)(&CPU1_SPROT_RGN0_LA),
#if ( MCAL_NO_OF_CORES > 2U )   
  (volatile CpuBusMpu_RangeRegMapType*)(volatile void *)(&CPU2_SPROT_RGN0_LA)
#endif  
#endif  
};

#define IFX_CPUBUSMPULFM_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

#define IFX_CPUBUSMPULFM_START_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"

/* Bus MPU error SMU Alarm group for each core */
static const uint8 CBM_kSmuAlmGrp[] =
{
  SMU_ALARM_GROUP0,
  SMU_ALARM_GROUP1,
  SMU_ALARM_GROUP6
};

#define IFX_CPUBUSMPULFM_STOP_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"


/******************************************************************************
**                        Imported function declarations                      *
******************************************************************************/

/******************************************************************************
**                        Local function prototypes                           *
******************************************************************************/
#define IFX_CPUBUSMPULFM_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

static Sl_TstRsltType  CpuBusMpuLfmTst_lCheckConfig
(const uint8 CoreId,
 const Sl_ParamSetType ParamSetIndex
);

static Sl_TstRsltType CpuBusMpuLfmTst_lCheckStatus(uint8 CoreId);


static Sl_TstRsltType CpuBusMpuLfmTst_lInit
(const uint8 CoreId,
 const Sl_ParamSetType ParamSetIndex,
 CpuBusMpuLfmTst_BackupDataType*  BackupData
);

static Sl_TstRsltType CpuBusMpuLfmTst_lCheckAcc
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 CoreId,
  uint32 DmiAccEn,  
  uint32* const TstSignature
);

static void CpuBusMpuLfmTst_lSetupAccEn
(
  const uint32 AccEnable,
  const uint8 CoreId,
  uint32* const TstSignature
);

static Sl_TstRsltType CpuBusMpuLfmTst_lRestore
(
  const uint8 CoreId,
  const Sl_ParamSetType ParamSetIndex,
  CpuBusMpuLfmTst_BackupDataType*  BackupData  
);


static Sl_TstRsltType CpuBusMpuLfmTst_lCheckRangeError
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 CoreId,
  const uint8 RangeIdx,
  const boolean AccessExpected,
  volatile uint32 MasterTagId,
  uint32* const TstSignature
);

static Sl_TstRsltType CpuBusMpuLfmTst_lFillAndCmpRanges
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 CoreId,
  const boolean AccessExpected,
  const uint32 MasterTagId,
  uint32* const TstSignature
);

static Sl_TstRsltType CpuBusMpuLfmTst_lFillAndCmpRange
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 CoreId,
  const uint8 RangeIdx,
  const boolean AccessExpected,
  uint32* const TstSignature
);

static Sl_TstRsltType CpuBusMpuLfmTst_lCheckUnauthorizedAddr
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 CoreId,
  const uint32 MasterTagId,
  uint32* const TstSignature
);



/******************************************************************************
**                         Function definitions                               *
******************************************************************************/
/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : Sl_TstRsltType CpuBusMpuLfmTst_LfmTest                  **
**                    ( const Sl_ParamSetType ParamSetIndex,                  **
**                      const uint8 TstSeed,                                  **
**                      uint32* const TstSignature                            **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : ParamSetIndex - Identifies the configuration parameter  **
**                    set to be used for test execution                       **
**                    TstSeed - Seed to be used for generating the signature  **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the Test     **
**                                                                            **
** Return value     : Error information                                       **
**                                                                            **
** Description      : Test API performs the latent fault metric test of the   **
**                    CPU Bus Memory Protection Unit. It performs the         **
**                    necessary test initialization, performs the actual test **
**                    and cleans up resources used by the test.               **
*******************************************************************************/
Sl_TstRsltType CpuBusMpuLfmTst_LfmTest
( const Sl_ParamSetType ParamSetIndex,
  const uint8 TstSeed,
  uint32* const TstSignature
)
{
  CpuBusMpuLfmTst_BackupDataType CpuBusMpuLfmTstBackupData;
  Sl_TstRsltType    Result    = BUSMPULFM_NOTEXECUTED;
  Sl_TstRsltType    ResultTmp = BUSMPULFM_NOTEXECUTED;
  uint8             CoreId;
  uint32            DmiAccEnb;

  /* Initialize Test Signature:                                             */
  *TstSignature = (uint32)CRC32((uint32)TEST_ID_BUS_MPU_LFM_TST, (uint32)TstSeed);

  /* Read the core Id */
  CoreId = Mcal_GetCoreId();

  Result = CpuBusMpuLfmTst_lCheckConfig(CoreId,ParamSetIndex);

  if(Result == BUSMPULFM_SUCCESS)
  {
    Result = CpuBusMpuLfmTst_lCheckStatus(CoreId);
    if(Result == BUSMPULFM_SUCCESS)
    {
      Mcal_SuspendAllInterrupts();
      Result = CpuBusMpuLfmTst_lInit(CoreId,ParamSetIndex,&CpuBusMpuLfmTstBackupData);
      if(Result == BUSMPULFM_SUCCESS)
      {
          DmiAccEnb = CBM_DMI_NON_SAFE_MASTER; 
          Result = CpuBusMpuLfmTst_lCheckAcc(ParamSetIndex,
                                                         CoreId,
                                                         DmiAccEnb,
                                                         TstSignature
                                                         );
          if(Result == BUSMPULFM_SUCCESS)
          {
            DmiAccEnb = CBM_DMI_SAFE_MASTER;           
            Result = CpuBusMpuLfmTst_lCheckAcc(ParamSetIndex,
                                                        CoreId,
                                                        DmiAccEnb,
                                                        TstSignature
                                                        );

          }
      } /* lInit failed */
      ResultTmp = CpuBusMpuLfmTst_lRestore(CoreId,ParamSetIndex,&CpuBusMpuLfmTstBackupData);
      Mcal_ResumeAllInterrupts();
      if(Result == BUSMPULFM_SUCCESS)
      {
        Result  = ResultTmp;
      }
    }/* CheckStatus failed */
  } /* CheckConfig failed */

  *TstSignature = (uint32)CRC32(*TstSignature,Result);

  return Result;
}/* CpuBusMpuLfmTst_LfmTest */

/******************************************************************************
**                    Configuration error checking                            *
******************************************************************************/
/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType  CpuBusMpuLfmTst_lCheckConfig     **
**                    (const uint8 CoreId,                                    **
**                     const Sl_ParamSetType ParamSetIndex                    **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : CoreId - ID of the CPU core on which the test           **
**                             is executing                                   **
**                    ParamSetIndex - Identifies the configuration parameter  **
**                    set to be used for test execution                       **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Error information                                       **
**                                                                            **
** Description      : Checks whether the ParamSetIndex parameter is valid and **
**                    the configuration settings selected by the ParamSetIndex**
**                    parameter are also valid.                               **
*******************************************************************************/
static Sl_TstRsltType  CpuBusMpuLfmTst_lCheckConfig
(const uint8 CoreId,
 const Sl_ParamSetType ParamSetIndex
)
{
  Sl_TstRsltType Result = BUSMPULFM_NOTEXECUTED;
  uint32 LoopCnt;
  uint32 CheckAddress;

  /* Test Base address (PSPR) for each core */
  uint32 PSPR_StartAddr[MCAL_NO_OF_CORES] = 
                            {
                              CORE0_PSPR_BASEADDR,
                              #if(MCAL_NO_OF_CORES > 1U)
                              CORE1_PSPR_BASEADDR,
                              #if(MCAL_NO_OF_CORES > 2U)
                              CORE2_PSPR_BASEADDR
                              #endif
                              #endif
                            };

  /* Test End address (PSPR) for each core */
  uint32 PSPR_EndAddr[MCAL_NO_OF_CORES] = 
                           {
                             CORE0_PSPR_ENDADDR,
                             #if(MCAL_NO_OF_CORES > 1U)
                             CORE1_PSPR_ENDADDR,
                             #if(MCAL_NO_OF_CORES > 2U)
                             CORE2_PSPR_ENDADDR
                             #endif
                             #endif
                           };

  /* Input parameter check */
  if(ParamSetIndex >= (Sl_ParamSetType)CPUBUSMPU_LFM_TST_CFG_PARAM_COUNT)
  {
    Result = BUSMPULFM_INVPARAMERR;
  }
  else
  {
    /* Configured parameter (test address) check */
    for(LoopCnt = 0U; LoopCnt < (uint32)BUS_MPU_TEST_RANGE_COUNT; LoopCnt++)
    {
      CheckAddress =
      (uint32)CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][LoopCnt];

      if((CheckAddress < PSPR_StartAddr[CoreId]) ||
         (CheckAddress > (((PSPR_EndAddr[CoreId]) - CBM_CPU_MPU_SIZE)+1U))
        )
      {
        Result = BUSMPULFM_CONFIGERR;
        break;
      }
    }
    CheckAddress =
    (uint32)CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].UnauthorizedAddr[CoreId][0];

    if((CheckAddress < PSPR_StartAddr[CoreId]) ||
       (CheckAddress > (((PSPR_EndAddr[CoreId]) - CBM_CPU_MPU_SIZE) + 1U))
      )
    {
      Result = BUSMPULFM_CONFIGERR;
    }    
  }
  if(Result == BUSMPULFM_NOTEXECUTED)
  {
    Result = BUSMPULFM_SUCCESS;
  }

  return Result;
} /* CpuBusMpuLfmTst_lCheckConfig */

/******************************************************************************
**                    Local inline function definitions                       *
******************************************************************************/

/******************************************************************************
**                         Local function definitions                         *
******************************************************************************/
/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType CpuBusMpuLfmTst_lCheckStatus      **
**                                          (uint8 CoreId)                    **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : CoreId - ID of the CPU core on which the test           **
**                             is executing                                   **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Error information                                       **
**                                                                            **
** Description      :checks that the PIETR CSFR does not already hold         **
**                   information about a previous error, that the SMU is in   **
**                   RUN state and that the Memory Protection SMU alarm is    **
**                   not already set.                                         **
*******************************************************************************/
static Sl_TstRsltType CpuBusMpuLfmTst_lCheckStatus(uint8 CoreId)
{
  Ifx_CPU_PIETR Pietr;
  Sl_TstRsltType Result = BUSMPULFM_NOTEXECUTED;
  uint32 AlarmStatus;

  Pietr.U = (unsigned_int)MFCR(CPU_PIETR);

  if(0U != (uint32)(Pietr.B.IED))
  {
    /* Program integrity error condition detected */
    Result = BUSMPULFM_ERRINFO_PREVERR;
  }
  else if(SMU_RUN_STATE != Smu_GetSmuState())
  {
    Result = BUSMPULFM_SMU_STATEERR;
  }
  else if((Std_ReturnType)E_OK !=
          Smu_GetAlarmStatus(CBM_kSmuAlmGrp[CoreId],&AlarmStatus))
  {
    Result = BUSMPULFM_SMU_GETALMSTSERR;
  }
  /* Check for Alarm 1: MPU Error */
  else if((AlarmStatus & ((uint32)(((uint32)1U)<<((uint32)SMU_ALARM_1)))) != CBM_SMU_ALM_NOT_SET)
  {
    Result = BUSMPULFM_SMU_ALMSTSERR;
  }
  else
  {
    Result = BUSMPULFM_SUCCESS;
  }

  return Result;
} /* CpuBusMpuLfmTst_lCheckStatus */


/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType CpuBusMpuLfmTst_lInit             **
**                    (const uint8 CoreId,                                    **
**                     const Sl_ParamSetType ParamSetIndex,                   **
**                     CpuBusMpuLfmTst_BackupDataType* BackupData             **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : CoreId - ID of the CPU core on which the test           **
**                             is executing                                   **
**                    ParamSetIndex - Identifies the parameter set to be used **
**                    for test execution                                      **
**                                                                            **
** Parameters (out): BackupData - Holds a backup of the                       **
**                   current SMU alarm action configuration of the SMU alarms **
**                   and the SFR configuration that will be changed by this   **
**                   test                                                     **
**                                                                            **
** Return value     : Error information                                       **
**                                                                            **
** Description      : Backs up the status of all SFRs and SMU alarm actions   **
**                    modified by the test, sets up all eight CPU Bus memory  **
**                    protection ranges to point to the PSPR used for testing **
**                    and sets the CPU Bus MPU alarm action to ‘none’.        **
**                    Furthermore all modified SFRs are read back in order to **
**                    ensure that the expected value has actually be written. **
*******************************************************************************/
static Sl_TstRsltType CpuBusMpuLfmTst_lInit
(const uint8 CoreId,
 const Sl_ParamSetType ParamSetIndex,
 CpuBusMpuLfmTst_BackupDataType* BackupData
)
{
  Sl_TstRsltType Result = BUSMPULFM_NOTEXECUTED;
  Smu_FSPActionType fspActionDummy;
  uint32 RangeIdx, WordIndex;
  uint32* Source;
  uint32* Dest;  
  

  for (RangeIdx = 0U; RangeIdx < BUS_MPU_TEST_RANGE_COUNT; RangeIdx++)
  {
    /* Backup memory given in configuration */
    Source = &(BackupData->CpuBusMpuLfmTst_BackupMemory[CoreId][BUS_MPU_TEST_RANGE_COUNT*RangeIdx]);
    Dest = CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][RangeIdx];
    for(WordIndex = 0U; WordIndex < (BUS_MPU_TEST_RANGE_SIZE/CBM_SIZEOFWORD); WordIndex++)
    {
      Source[WordIndex] = Dest[WordIndex];

    }
  }

  /* Backup RGNLAx / RGNUAx registers */
  BackupData->RGNLA0 =
      (uint32)CBM_RGNRegGrp[CoreId]->RGNLA0.U;

  BackupData->RGNUA0 =
      CBM_RGNRegGrp[CoreId]->RGNUA0.U;

  BackupData->RGNLA1 =
      CBM_RGNRegGrp[CoreId]->RGNLA1.U;
  BackupData->RGNUA1 =
      CBM_RGNRegGrp[CoreId]->RGNUA1.U;

  BackupData->RGNLA2 =
      CBM_RGNRegGrp[CoreId]->RGNLA2.U;
  BackupData->RGNUA2 =
      CBM_RGNRegGrp[CoreId]->RGNUA2.U;

  BackupData->RGNLA3 =
      CBM_RGNRegGrp[CoreId]->RGNLA3.U;
  BackupData->RGNUA3 =
      CBM_RGNRegGrp[CoreId]->RGNUA3.U;

  BackupData->RGNLA4 =
      CBM_RGNRegGrp[CoreId]->RGNLA4.U;
  BackupData->RGNUA4 =
      CBM_RGNRegGrp[CoreId]->RGNUA4.U;

  BackupData->RGNLA5 =
      CBM_RGNRegGrp[CoreId]->RGNLA5.U;
  BackupData->RGNUA5 =
      CBM_RGNRegGrp[CoreId]->RGNUA5.U;

  BackupData->RGNLA6 =
        CBM_RGNRegGrp[CoreId]->RGNLA6.U;
  BackupData->RGNUA6 =
        CBM_RGNRegGrp[CoreId]->RGNUA6.U;

  BackupData->RGNLA7 =
        CBM_RGNRegGrp[CoreId]->RGNLA7.U;
  BackupData->RGNUA7 =
        CBM_RGNRegGrp[CoreId]->RGNUA7.U;

    /* Backup RGNACCENAx registers */
  BackupData->RGNACCENA0 =
      CBM_RGNRegGrp[CoreId]->RGNACCENA0.U;
  BackupData->RGNACCENA1 =
      CBM_RGNRegGrp[CoreId]->RGNACCENA1.U;
  BackupData->RGNACCENA2 =
      CBM_RGNRegGrp[CoreId]->RGNACCENA2.U;
  BackupData->RGNACCENA3 =
      CBM_RGNRegGrp[CoreId]->RGNACCENA3.U;
  BackupData->RGNACCENA4 =
      CBM_RGNRegGrp[CoreId]->RGNACCENA4.U;
  BackupData->RGNACCENA5 =
      CBM_RGNRegGrp[CoreId]->RGNACCENA5.U;
  BackupData->RGNACCENA6 =
      CBM_RGNRegGrp[CoreId]->RGNACCENA6.U;
  BackupData->RGNACCENA7 =
      CBM_RGNRegGrp[CoreId]->RGNACCENA7.U;

    /* Backup SMU alarm action */
  BackupData->AlmAction = SMU_INVALID_ALARM_ACTION;

  if (E_OK != Smu_GetAlarmAction(CBM_kSmuAlmGrp[CoreId],
                                 (uint8)SMU_ALARM_1,
                                 &(BackupData->AlmAction),
                                 &fspActionDummy))
  {
    Result = BUSMPULFM_SMU_GETALMACTIONERR;
  }
  else
  {
    Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);

    /* Setup address ranges for testing */
    CBM_RGNRegGrp[CoreId]->RGNLA0.U =
    (unsigned_int)CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][0];
    CBM_RGNRegGrp[CoreId]->RGNUA0.U =
    (unsigned_int)CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][0] +
    (unsigned_int)BUS_MPU_TEST_RANGE_SIZE;

    CBM_RGNRegGrp[CoreId]->RGNLA1.U =
    (unsigned_int)CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][1];
    CBM_RGNRegGrp[CoreId]->RGNUA1.U =
    (unsigned_int)CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][1] +
    (unsigned_int)BUS_MPU_TEST_RANGE_SIZE;

    CBM_RGNRegGrp[CoreId]->RGNLA2.U =
    (unsigned_int)CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][2];
    CBM_RGNRegGrp[CoreId]->RGNUA2.U =
    (unsigned_int) CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][2] +
    (unsigned_int)BUS_MPU_TEST_RANGE_SIZE;

    CBM_RGNRegGrp[CoreId]->RGNLA3.U =
    (unsigned_int)CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][3];
    CBM_RGNRegGrp[CoreId]->RGNUA3.U =
    (unsigned_int)CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][3] +
    (unsigned_int)BUS_MPU_TEST_RANGE_SIZE;

    CBM_RGNRegGrp[CoreId]->RGNLA4.U =
    (unsigned_int)CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][4];
    CBM_RGNRegGrp[CoreId]->RGNUA4.U =
    (unsigned_int)CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][4] +
    (unsigned_int)BUS_MPU_TEST_RANGE_SIZE;

    CBM_RGNRegGrp[CoreId]->RGNLA5.U =
    (unsigned_int)CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][5];
    CBM_RGNRegGrp[CoreId]->RGNUA5.U =
    (unsigned_int)CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][5] +
    (unsigned_int)BUS_MPU_TEST_RANGE_SIZE;

    CBM_RGNRegGrp[CoreId]->RGNLA6.U =
    (unsigned_int)CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][6];
    CBM_RGNRegGrp[CoreId]->RGNUA6.U =
    (unsigned_int)CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][6] +
    (unsigned_int)BUS_MPU_TEST_RANGE_SIZE;

    CBM_RGNRegGrp[CoreId]->RGNLA7.U =
    (unsigned_int)CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][7];
    CBM_RGNRegGrp[CoreId]->RGNUA7.U =
    (unsigned_int)CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][7] +
    (unsigned_int)BUS_MPU_TEST_RANGE_SIZE;

    Mcal_SetSafetyENDINIT_Timed();


    if(E_OK != Smu_SetAlarmAction(CBM_kSmuAlmGrp[CoreId],
                                  (uint8)SMU_ALARM_1,
                                  SMU_ALARM_ACTION_NONE)
      )
    {
      Result = BUSMPULFM_SMU_SETALMACTIONERR;
    }
    else
    {
      Result = BUSMPULFM_SUCCESS;
    }

  }
  return Result;
} /* CpuBusMpuLfmTst_lInit */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType CpuBusMpuLfmTst_lCheckAcc         **
**                    (const Sl_ParamSetType ParamSetIndex,                   **
**                     const uint8 CoreId,                                    **
**                     uint32 DmiAccEn,                                       **
**                     uint32* const TstSignature                             **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : CoreId - ID of the CPU core on which the test           **
**                             is executing                                   **
**                    ParamSetIndex - Identifies the parameter set to be used **
**                    for test execution                                      **
**                     DmiAccEn - Master for which access is to be enabled    **
** Parameters (out) : TstSignature - Test signature generated by the Test     **
**                                                                            **
** Return value     : Error information                                       **
**                                                                            **
** Description      : Enables access to test memory in PSPR for the DMI-      **
**                    safe/non-safe master and checks that access is granted to**
**                     master that is enabled as per DmiAccEn, denied to other** 
**                    other master and reported error information is consistent**
*******************************************************************************/
static Sl_TstRsltType CpuBusMpuLfmTst_lCheckAcc
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 CoreId,
  uint32 DmiAccEn,
  uint32* const TstSignature
)
{
  Sl_TstRsltType Result    = BUSMPULFM_NOTEXECUTED;
  uint32 RangeIdx;
  uint32 WordIndex;
  uint32* DestAddress;
  uint32 Temp;
  uint32 AccEnb;
  uint32 DmiTagId;


  /* Constant Non safe DMI ACCEN value for each core */
  uint32 CBM_kNonSafeDMIAccEn[] =
  {
    CBM_CPU0_NON_SAFE_DMI_ACCEN,
    CBM_CPU1_NON_SAFE_DMI_ACCEN,
    CBM_CPU2_NON_SAFE_DMI_ACCEN
  };
  /* Constant Safe DMI ACCEN value for each core */
  uint32 CBM_kSafeDMIAccEn[] =
  {
    CBM_CPU0_SAFE_DMI_ACCEN,
    CBM_CPU1_SAFE_DMI_ACCEN,
    CBM_CPU2_SAFE_DMI_ACCEN
  };
  /* Constant Non safe DMI Tag Id value for each core */
  uint32 CBM_kNonSafeDMITagId[] =
  {
    CBM_CPU0_DMI_NON_SAFE_TAG_ID,
    CBM_CPU1_DMI_NON_SAFE_TAG_ID,
    CBM_CPU2_DMI_NON_SAFE_TAG_ID
  };

  /* Constant Safe DMI Tag Id value for each core */
  uint32 CBM_kSafeDMITagId[] =
  {
    CBM_CPU0_DMI_SAFE_TAG_ID,
    CBM_CPU1_DMI_SAFE_TAG_ID,
    CBM_CPU2_DMI_SAFE_TAG_ID
  };
    /* Fill the test memory to value 0 */
  for (RangeIdx = 0U; RangeIdx < BUS_MPU_TEST_RANGE_COUNT; RangeIdx++)
  {
    /* Backup memory given in configuration */
    DestAddress = CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][RangeIdx];
    for(WordIndex = 0U; WordIndex < (BUS_MPU_TEST_RANGE_SIZE/4U); WordIndex++)
    {
      DestAddress[WordIndex] = 0U;

    }
  }

  if(DmiAccEn == CBM_DMI_NON_SAFE_MASTER)
  {
    AccEnb = CBM_kNonSafeDMIAccEn[CoreId];
    DmiTagId = CBM_kNonSafeDMITagId[CoreId];
    /* Switch processor status to Non safe task:                */
    Temp = (uint32)MFCR(CPU_PSW);
    Temp &= (~(((uint32)1U << (uint32)IFX_CPU_PSW_S_OFF)));
    MTCR(CPU_PSW, Temp);
  }
  else
  {
    AccEnb = CBM_kSafeDMIAccEn[CoreId];
    DmiTagId = CBM_kSafeDMITagId[CoreId];
    /* Switch processor status to safe task:                */
    Temp = (uint32)MFCR(CPU_PSW);
    Temp |= (((uint32)1U << (uint32)IFX_CPU_PSW_S_OFF));
    MTCR(CPU_PSW, Temp);
  }

  CpuBusMpuLfmTst_lSetupAccEn(AccEnb,
                              CoreId,
                              TstSignature
                              );
  Result = CpuBusMpuLfmTst_lFillAndCmpRanges(ParamSetIndex,
                                                CoreId,
                                                TRUE,
                                                DmiTagId,
                                                TstSignature
                                                );
  if(BUSMPULFM_SUCCESS == Result)
  {
    Result = CpuBusMpuLfmTst_lCheckUnauthorizedAddr(ParamSetIndex,
                                              CoreId,
                                              DmiTagId,
                                              TstSignature
                                              );

  }
  
  if(BUSMPULFM_SUCCESS == Result)
  {
    /* Fill the test memory to value 0 */
    /* Fill the test memory to value 0 */
    for (RangeIdx = 0U; RangeIdx < BUS_MPU_TEST_RANGE_COUNT; RangeIdx++)
    {
      /* Backup memory given in configuration */
      DestAddress = CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][RangeIdx];
      for(WordIndex = 0U; WordIndex < (BUS_MPU_TEST_RANGE_SIZE/CBM_SIZEOFWORD); WordIndex++)
      {
        DestAddress[WordIndex] = 0U;

      }
    }
    if(DmiAccEn == CBM_DMI_NON_SAFE_MASTER)
    {
      DmiTagId = CBM_kSafeDMITagId[CoreId];
      /* Switch processor status to safe task:                */
      Temp = (uint32)MFCR(CPU_PSW);
      Temp |= (((uint32)1U << (uint32)IFX_CPU_PSW_S_OFF));
      MTCR(CPU_PSW, Temp);
    }
    else
    {
      DmiTagId = CBM_kNonSafeDMITagId[CoreId];
      /* Switch processor status to Non safe task:                */
      Temp = (uint32)MFCR(CPU_PSW);
      Temp &= (~(((uint32)1U << (uint32)IFX_CPU_PSW_S_OFF)));
      MTCR(CPU_PSW, Temp);
    }
    Result = CpuBusMpuLfmTst_lFillAndCmpRanges(ParamSetIndex,
                                                   CoreId,
                                                   FALSE,
                                                   DmiTagId,
                                                   TstSignature
                                                   );

  }


  return Result;
} /* CpuBusMpuLfmTst_lCheckAcc */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType CpuBusMpuLfmTst_lSetupAccEn       **
**                    (const uint32 AccEnable,                                **
**                     const uint8 CoreId,                                    **
**                     uint32* const TstSignature                             **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : CoreId - ID of the CPU core on which the test           **
**                             is executing                                   **
**                    AccEnable - Access enable mask that specifies for which **
**                                masters access is to be enabled; this value **
**                                is directly written to                      **
**                                CPUx_SPROT_RGNy_ACCENA                      **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the Test     **
**                                                                            **
** Return value     : Error information                                       **
**                                                                            **
** Description      : Sets up the access enable registers                     **
**                    CPUx_SPROT_RGNy_ACCENA to a caller-supplied value and   **
**                    checks that those values have actually be written by    **
**                    reading them back.                                      **
*******************************************************************************/
static void CpuBusMpuLfmTst_lSetupAccEn
(
  const uint32 AccEnable,
  const uint8 CoreId,
  uint32* const TstSignature
)
{

  uint32 Signature = 0U;

  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);

  /* Allow access to master as per parameter AccEnable and deny for all other masters */
  CBM_RGNRegGrp[CoreId]->RGNACCENA0.U = AccEnable;

  CBM_RGNRegGrp[CoreId]->RGNACCENA1.U = AccEnable;

  CBM_RGNRegGrp[CoreId]->RGNACCENA2.U = AccEnable;

  CBM_RGNRegGrp[CoreId]->RGNACCENA3.U = AccEnable;

  CBM_RGNRegGrp[CoreId]->RGNACCENA4.U = AccEnable;

  CBM_RGNRegGrp[CoreId]->RGNACCENA5.U = AccEnable;

  CBM_RGNRegGrp[CoreId]->RGNACCENA6.U = AccEnable;

  CBM_RGNRegGrp[CoreId]->RGNACCENA7.U = AccEnable;

  Mcal_SetSafetyENDINIT_Timed();


  Signature += CBM_RGNRegGrp[CoreId]->RGNACCENA0.U;
  Signature += CBM_RGNRegGrp[CoreId]->RGNACCENA1.U;
  Signature += CBM_RGNRegGrp[CoreId]->RGNACCENA2.U;
  Signature += CBM_RGNRegGrp[CoreId]->RGNACCENA3.U;
  Signature += CBM_RGNRegGrp[CoreId]->RGNACCENA4.U;
  Signature += CBM_RGNRegGrp[CoreId]->RGNACCENA5.U;
  Signature += CBM_RGNRegGrp[CoreId]->RGNACCENA6.U;
  Signature += CBM_RGNRegGrp[CoreId]->RGNACCENA7.U;

  *TstSignature = (uint32)CRC32(*TstSignature, Signature);


} /* CpuBusMpuLfmTst_lSetupAccEn */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType CpuBusMpuLfmTst_lRestore          **
**                    (const uint8 CoreId)                                    **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : CoreId - ID of the CPU core on which the test           **
**                             is executing                                   **
**                    ParamSetIndex - Identifies the parameter set to be used **
**                    for test execution                                      **
**                                                                            **
** Parameters (out): BackupData - Holds a backup of the                       **
**                   current SMU alarm action configuration of the SMU alarms **
**                   and the SFR configuration that will be changed by this   **
**                   test                                                     **
**                                                                            **
** Return value     : Error information                                       **
**                                                                            **
** Description      : Sets up the access enable registers                     **
**                    CPUx_SPROT_RGNy_ACCENA to a caller-supplied value and   **
**                    checks that those values have actually be written by    **
**                    reading them back.                                      **
*******************************************************************************/
static Sl_TstRsltType CpuBusMpuLfmTst_lRestore
(const uint8 CoreId,
 const Sl_ParamSetType ParamSetIndex,
 CpuBusMpuLfmTst_BackupDataType* BackupData 
)

{
  Sl_TstRsltType    Result = BUSMPULFM_NOTEXECUTED;
  uint32 RangeIdx, WordIndex;
  uint32* Source;
  uint32* Dest; 

 
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  /* Restore all RGNLAx and RGNUAx registers to the backup values */

  CBM_RGNRegGrp[CoreId]->RGNLA0.U = BackupData->RGNLA0;
  CBM_RGNRegGrp[CoreId]->RGNUA0.U = BackupData->RGNUA0;

  CBM_RGNRegGrp[CoreId]->RGNLA1.U = BackupData->RGNLA1;
  CBM_RGNRegGrp[CoreId]->RGNUA1.U = BackupData->RGNUA1;

  CBM_RGNRegGrp[CoreId]->RGNLA2.U = BackupData->RGNLA2;
  CBM_RGNRegGrp[CoreId]->RGNUA2.U = BackupData->RGNUA2;

  CBM_RGNRegGrp[CoreId]->RGNLA3.U = BackupData->RGNLA3;
  CBM_RGNRegGrp[CoreId]->RGNUA3.U = BackupData->RGNUA3;

  CBM_RGNRegGrp[CoreId]->RGNLA4.U = BackupData->RGNLA4;
  CBM_RGNRegGrp[CoreId]->RGNUA4.U = BackupData->RGNUA4;

  CBM_RGNRegGrp[CoreId]->RGNLA5.U = BackupData->RGNLA5;
  CBM_RGNRegGrp[CoreId]->RGNUA5.U = BackupData->RGNUA5;

  CBM_RGNRegGrp[CoreId]->RGNLA6.U = BackupData->RGNLA6;
  CBM_RGNRegGrp[CoreId]->RGNUA6.U = BackupData->RGNUA6;

  CBM_RGNRegGrp[CoreId]->RGNLA7.U = BackupData->RGNLA7;
  CBM_RGNRegGrp[CoreId]->RGNUA7.U = BackupData->RGNUA7;

  /* Restore all RGNACCENAx registers to the backup values:                 */

  CBM_RGNRegGrp[CoreId]->RGNACCENA0.U = BackupData->RGNACCENA0;

  CBM_RGNRegGrp[CoreId]->RGNACCENA1.U = BackupData->RGNACCENA1;

  CBM_RGNRegGrp[CoreId]->RGNACCENA2.U = BackupData->RGNACCENA2;

  CBM_RGNRegGrp[CoreId]->RGNACCENA3.U = BackupData->RGNACCENA3;

  CBM_RGNRegGrp[CoreId]->RGNACCENA4.U = BackupData->RGNACCENA4;

  CBM_RGNRegGrp[CoreId]->RGNACCENA5.U = BackupData->RGNACCENA5;

  CBM_RGNRegGrp[CoreId]->RGNACCENA6.U = BackupData->RGNACCENA6;

  CBM_RGNRegGrp[CoreId]->RGNACCENA7.U = BackupData->RGNACCENA7;

  Mcal_SetSafetyENDINIT_Timed();
  for (RangeIdx = 0U; RangeIdx < BUS_MPU_TEST_RANGE_COUNT; RangeIdx++)
  {
    /* Restore memory given in configuration */
    Dest  = CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][RangeIdx];
    Source = &(BackupData->CpuBusMpuLfmTst_BackupMemory[CoreId][(BUS_MPU_TEST_RANGE_COUNT*RangeIdx)]);
    for(WordIndex= 0U; WordIndex < (BUS_MPU_TEST_RANGE_SIZE/CBM_SIZEOFWORD); WordIndex++)
    {
      Dest[WordIndex]  = Source[WordIndex];

    }
  }  

  /* Restore SMU alarm action:                                              */
  if (SMU_INVALID_ALARM_ACTION != BackupData->AlmAction)
  {
    if (E_OK != Smu_SetAlarmAction(CBM_kSmuAlmGrp[CoreId],
                                   (uint8)SMU_ALARM_1,
                                   BackupData->AlmAction))
    {
      Result = BUSMPULFM_SMU_SETALMACTIONERR;
    }
    else
    {
      Result = BUSMPULFM_SUCCESS;
    }
  }
  else
  {
    Result = BUSMPULFM_SMU_GETALMACTIONERR;
  }
  return Result;
} /* CpuBusMpuLfmTst_lRestore */



/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           :static Sl_TstRsltType CpuBusMpuLfmTst_lCheckRangeError   **
**                    (const Sl_ParamSetType ParamSetIndex,                   **
**                     const uint8 CoreId,                                    **
**                     const uint8 RangeIdx,                                  **
**                     const boolean AccessExpected,                          **
**                     volatile uint32 MasterTagId,                           **
**                     uint32* const TstSignature                             **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : CoreId - ID of the CPU core on which the test           **
**                    is executing                                            **
**                    ParamSetIndex - Identifies the parameter set to be      **
**                    used for test execution                                 **
**                    RangeIdx - Identifies the test memory range in PSPR for **
**                    which to check for an error                             **
**                    MasterTagId - Master Tag ID that is expected to be      **
**                    reported in the error information register in case      **
**                    access to the memory ranges was blocked                 **
**                    AccessExpected - TRUE/FALSE, based in access is         **
**                                     allowed or not                         **
** Parameters (out) : TstSignature - Test signature generated by the Test     **
**                                                                            **
** Return value     : Error information                                       **
**                                                                            **
** Description      : checks whether an access to a test memory range was     **
**                    granted or denied as expected. If the access was        **
**                    expected to be granted, it checks that no SMU alarm was **
**                    triggered and that the PIETR register does not contain  **
**                    any error information. If access was indeed expected to **
**                    be denied, it checks that a SMU alarm was triggered and **
**                    that the PIETR and PIEAR registers hold the expected    **
**                    cause of error.                                         **
**                    Furthermore it clears CPU MPU  SMU alarms.              **
*******************************************************************************/
static Sl_TstRsltType CpuBusMpuLfmTst_lCheckRangeError
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 CoreId,
  const uint8 RangeIdx,
  const boolean AccessExpected,
  volatile uint32 MasterTagId,
  uint32* const TstSignature
)
{

  Sl_TstRsltType Result = BUSMPULFM_NOTEXECUTED;
  uint32 SmuAlarmStatus;
  Ifx_CPU_PIETR   Pietr;
  Ifx_CPU_DIEAR   Piear;

  if(E_OK != Smu_GetAlarmStatus(CBM_kSmuAlmGrp[CoreId],&SmuAlarmStatus))
  {
    Result = BUSMPULFM_SMU_GETALMSTSERR;
  }
  else
  {
    SmuAlarmStatus = (SmuAlarmStatus & ((uint32)(((uint32)1U)<<((uint32)SMU_ALARM_1))));

    if(TRUE == AccessExpected)
    {
      if(SmuAlarmStatus != 0U)
      {
        /* Alarm is set */
        Result = BUSMPULFM_SMU_ALMSTSERR;
      } 
      else
      {
        Pietr.U = (unsigned_int)MFCR(CPU_PIETR);
        if(0U != (uint32)(Pietr.B.IED))
        {
          Result = BUSMPULFM_ERRINFO_PREVERR;
        }
        else
        {
          Result = BUSMPULFM_SUCCESS;
        }
      }
    }
    else /* AccessExpected is FALSE*/
    {
      if(SmuAlarmStatus == 0U)
      {
        /* Alarm is not set */
        Result = BUSMPULFM_SMU_ALMSTSERR;
      }
      else
      {
        Pietr.U = (unsigned_int)MFCR(CPU_PIETR);
        if((Pietr.U & (unsigned_int)CBM_PIETR_INTEGRITYERR_MASK) != (unsigned_int)CBM_PIETR_IE_BUS_SPMEM)
        {
          /* No intended integrity error detected */
          Result = BUSMPULFM_ERRINFO_CAUSE;
        }
        else if((uint32)(Pietr.B.E_INFO) != MasterTagId)
        {
          Result = BUSMPULFM_ERRINFO_MASTERTAG;
        }
        else
        {
          Piear.U = (unsigned_int)MFCR(CPU_PIEAR);
          if(Piear.U !=
             (unsigned_int)CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][RangeIdx])
          {
            Result = BUSMPULFM_ERRINFO_ADDRESS;
          }
          else /* No expected error */
          {
            /* Error information registers hold the expected values, clear them*/
            Pietr.B.IED = 0U;
            MTCR(CPU_PIETR, Pietr.U);
            if(E_OK !=
               Smu_ClearAlarmStatus(CBM_kSmuAlmGrp[CoreId],(uint8)SMU_ALARM_1))
            {
              Result = BUSMPULFM_SMU_CLRALMSTSERR;
            }
            else
            {
              Result = BUSMPULFM_SUCCESS;
            }
          }
        }
      }
    }
    /* Test Signature */
    *TstSignature = (uint32)CRC32(*TstSignature,SmuAlarmStatus);
  }

  return Result;
} /* CpuBusMpuLfmTst_lCheckRangeError */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           :static Sl_TstRsltType CpuBusMpuLfmTst_lFillAndCmpRanges  **
**                    (const Sl_ParamSetType ParamSetIndex,                   **
**                     const uint8 CoreId,                                    **
**                     const boolean AccessExpected,                          **
**                     volatile uint32 MasterTagId,                           **
**                     uint32* const TstSignature                             **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : CoreId - ID of the CPU core on which the test           **
**                    is executing                                            **
**                    ParamSetIndex - Identifies the parameter set to be      **
**                    used for test execution                                 **
**                    MasterTagId - Master Tag ID that is expected to be      **
**                    reported in the error information register in case      **
**                    access to the memory ranges was blocked                 **
**                    AccessExpected - TRUE/FALSE, based in access is         **
**                                     allowed or not                         **
** Parameters (out) : TstSignature - Test signature generated by the Test     **
**                                                                            **
** Return value     : Error information                                       **
**                                                                            **
** Description      : Fills all protected memory ranges with test patterns    **
**                    and checks whether or not data has been written by      **
**                    reading back all data and comparing it to the test      **
**                    patterns again. Furthermore it checks whether the       **
**                    SMU MPU status corresponds to the expected granting or  **
**                    denial of access. In case of a blocked access also the  **
**                    error information provided by PIETR and PIEAR is        **
**                    compared to the expected cause of error.                **
*******************************************************************************/
static Sl_TstRsltType CpuBusMpuLfmTst_lFillAndCmpRanges
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 CoreId,
  const boolean AccessExpected,
  const uint32 MasterTagId,
  uint32* const TstSignature
)
{
  Sl_TstRsltType Result    = BUSMPULFM_NOTEXECUTED;
  Sl_TstRsltType ResultTmp = BUSMPULFM_NOTEXECUTED;
  uint8 RangeIdx;

   for (RangeIdx = 0U; RangeIdx < (uint8)BUS_MPU_TEST_RANGE_COUNT; RangeIdx++)
   {
     if (BUSMPULFM_NOTEXECUTED == Result)
     {
       ResultTmp = CpuBusMpuLfmTst_lFillAndCmpRange(ParamSetIndex,
                                                    CoreId,
                                                    RangeIdx,
                                                    AccessExpected,
                                                    TstSignature
                                                    );

       if(BUSMPULFM_SUCCESS == ResultTmp)
       {
         ResultTmp = CpuBusMpuLfmTst_lCheckRangeError(ParamSetIndex,
                                                      CoreId,
                                                      RangeIdx,
                                                      AccessExpected,
                                                      MasterTagId,
                                                      TstSignature
                                                      );
         if(BUSMPULFM_SUCCESS != ResultTmp)
         {
           Result = ResultTmp;
         }
       }
       else
       {
         Result = ResultTmp;
       }
     }
   }

   if(Result == BUSMPULFM_NOTEXECUTED)
   {
     Result = BUSMPULFM_SUCCESS;
   }

   return Result;
} /* CpuBusMpuLfmTst_lFillAndCmpRanges */

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           :static Sl_TstRsltType CpuBusMpuLfmTst_lFillAndCmpRange   **
**                    (const Sl_ParamSetType ParamSetIndex,                   **
**                     const uint8 CoreId,                                    **
**                     const uint8 RangeIdx,                                  **
**                     uint32* const TstSignature                             **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : CoreId - ID of the CPU core on which the test           **
**                    is executing                                            **
**                    ParamSetIndex - Identifies the parameter set to be      **
**                    used for test execution                                 **
**                    RangeIdx - Index of the memory range to fill and compare**
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the Test     **
**                                                                            **
** Return value     : Error information                                       **
**                                                                            **
** Description      : Fills all protected memory ranges with test patterns    **
**                    and checks whether or not data has been written by      **
**                    reading back all data and comparing it to the test      **
**                    patterns again. Furthermore it checks whether the       **
**                    SMU MPU status corresponds to the expected granting or  **
**                    denial of access. In case of a blocked access also the  **
**                    error information provided by PIETR and PIEAR is        **
**                    compared to the expected cause of error.                **
*******************************************************************************/
static Sl_TstRsltType CpuBusMpuLfmTst_lFillAndCmpRange
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 CoreId,
  const uint8 RangeIdx,
  const boolean AccessExpected,
  uint32* const TstSignature
)
{
  Sl_TstRsltType Result = BUSMPULFM_NOTEXECUTED;
  /* For GNU compiler options, this should be volatile */
  volatile uint32 i;
  uint32 Loop;
  uint32 signature = 0U;
  uint32 WordIndex;
  uint32* DestAddress;
  /* Fill memory range with test pattern:*/
  const uint32 CBM_kTestPattern[] =
  {
    0x12345678U,  /* [0] */
    0x23456789U,  /* [1] */
    0x3456789aU,  /* [2] */
    0x456789abU,  /* [3] */
    0x56789abcU,  /* [4] */
    0x6789abcdU,  /* [5] */
    0x789abcdeU,  /* [6] */
    0x89abcdefU   /* [7] */
  };  

  /* Backup memory given in configuration */
  DestAddress = CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][RangeIdx];

  for(WordIndex = 0U; WordIndex < (BUS_MPU_TEST_RANGE_SIZE/CBM_SIZEOFWORD); WordIndex++)
  {
    DestAddress[WordIndex] = CBM_kTestPattern[WordIndex];

  }
  if(TRUE == AccessExpected)
  {
    for(i = 0U; i < ((uint32)BUS_MPU_TEST_RANGE_SIZE / CBM_SIZEOFWORD); i++)
    {
      Loop = i;
      if(CBM_kTestPattern[Loop]
          != CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][RangeIdx][Loop])
      {
        Result = (BUSMPULFM_ACCDENY_ERR(RangeIdx));
        break;
      }
      signature = signature ^ (CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][RangeIdx][Loop]) ;
    }
  }
  else
  {
    for(i = 0U; i < (BUS_MPU_TEST_RANGE_SIZE / CBM_SIZEOFWORD); i++)
    {
      Loop = i;
      if(CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][RangeIdx][Loop]
          != 0U)
      {
        Result = (BUSMPULFM_ACCGRANT_ERR(RangeIdx));
        break;
      }

      signature = signature ^ (CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].TestMemory[CoreId][RangeIdx][Loop]) ;
    }
  }
  signature = signature ^ (((uint32)RangeIdx << CBM_SHIFT0) + ((uint32)RangeIdx << CBM_SHIFT8) +
                       ((uint32)RangeIdx << CBM_SHIFT16) + ((uint32)RangeIdx << CBM_SHIFT24));

  *TstSignature = (uint32)CRC32(*TstSignature,signature);
  if(BUSMPULFM_NOTEXECUTED == Result)
  {
    Result = BUSMPULFM_SUCCESS;
  }

  return Result;
} /* CpuBusMpuLfmTst_lFillAndCmpRange */



/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           :static Sl_TstRsltType
**                                  CpuBusMpuLfmTst_lCheckUnauthorizedAddr    **
**                    (const Sl_ParamSetType ParamSetIndex,                   **
**                     const uint8 CoreId,                                    **
**                     const uint32 MasterTagId,                              **
**                     uint32* const TstSignature                             **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Re-entrant                                          **
**                                                                            **
** Parameters(in)   : CoreId - ID of the CPU core on which the test           **
**                    is executing                                            **
**                    ParamSetIndex - Identifies the parameter set to be      **
**                    used for test execution                                 **
**                    MasterTagId - Master Tag ID that is expected to be      **
**                    reported in the error information register in case      **
**                    access to the memory ranges was blocked                 **
**                                                                            **
** Parameters (out) : TstSignature - Test signature generated by the Test     **
**                                                                            **
** Return value     : Error information                                       **
**                                                                            **
** Description      : Performs a write access to an address not covered by    **
**                    any memory protection range and checks that this        **
**                    unauthorized access triggers an SMU alarm.              **
*******************************************************************************/
static Sl_TstRsltType CpuBusMpuLfmTst_lCheckUnauthorizedAddr
(
  const Sl_ParamSetType ParamSetIndex,
  const uint8 CoreId,
  const uint32 MasterTagId,
  uint32* const TstSignature
)
{
  Sl_TstRsltType     Result    = BUSMPULFM_NOTEXECUTED;
  uint32             AlmStatus = 0U;
  volatile uint32*   TestAddress;
  uint32             TestAddressBackup;
  uint32             Timeout;
  
  Ifx_CPU_PIETR   Pietr;
  Ifx_CPU_DIEAR   Piear;


  TestAddress = *CpuBusMpuLfmTst_ConfigRoot[ParamSetIndex].UnauthorizedAddr[CoreId];
  TestAddressBackup = *TestAddress;
  /* Invert 32bit value at location TestAddress */
  *TestAddress = ~(TestAddressBackup);


  /* ISYNC is required to be sure that PIETR and PIEAR are updated before     */
  /* reading them.                                                            */
  ISYNC();

  Pietr.U = (unsigned_int)MFCR(CPU_PIETR);
  Piear.U = (unsigned_int)MFCR(CPU_PIEAR);

  /*delay has been Introduced for the SMU to recognise the fault and raise 
  the alarm @ low SPB clock scenario*/
    Timeout = 0U;
    while((Timeout < BUSMPULFM_NO_FAULT_TIMEOUT) && 
    ((AlmStatus & ((uint32)1U << SMU_ALARM_1)) == 0U ))
    {
	  Timeout++;
      if(E_OK != Smu_GetAlarmStatus(CBM_kSmuAlmGrp[CoreId], &AlmStatus))
      {
        Result = BUSMPULFM_SMU_GETALMSTSERR;      
        break;
	  }  
    }
    if(Result != BUSMPULFM_SMU_GETALMSTSERR)
	{
      if((AlmStatus & ((uint32)1U << SMU_ALARM_1)) == 0U )
      {
         Result = BUSMPULFM_SMU_ALMSTSERR;
      }
      else if((Pietr.U & (unsigned_int)CBM_PIETR_INTEGRITYERR_MASK) != 
	  (unsigned_int)CBM_PIETR_IE_BUS_SPMEM)
      {
        Result = BUSMPULFM_ERRINFO_CAUSE;
      }
      else if((uint32)(Pietr.B.E_INFO) != MasterTagId)
      {
        Result = BUSMPULFM_ERRINFO_MASTERTAG;
      }
      else if(Piear.U != (unsigned_int)TestAddress)
      {
        Result = BUSMPULFM_ERRINFO_ADDRESS;
      }
      else if(TestAddressBackup!= *TestAddress)
      {
        Result = (BUSMPULFM_ACCGRANT_ERR(0U));
      }
      else
      {
        Pietr.B.IED = 0U;
        MTCR(CPU_PIETR, Pietr.U);
        if(E_OK != 
	    Smu_ClearAlarmStatus(CBM_kSmuAlmGrp[CoreId],(uint8)SMU_ALARM_1))
        {
          Result = BUSMPULFM_SMU_CLRALMSTSERR;
        }
      }
    }	  

  *TstSignature = 
  (uint32)CRC32(*TstSignature, (AlmStatus & ((uint32)1U << SMU_ALARM_1)));

  if(BUSMPULFM_NOTEXECUTED == Result)
  {
    Result = BUSMPULFM_SUCCESS;
  }

  return Result;
}/*CpuBusMpuLfmTst_lCheckUnauthorizedAddr*/

#define IFX_CPUBUSMPULFM_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
