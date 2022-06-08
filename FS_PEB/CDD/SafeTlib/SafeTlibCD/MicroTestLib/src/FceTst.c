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
**   $FILENAME   : FceTst.c $                                                 **
**                                                                            **
**   $CC VERSION : \main\47 $                                                 **
**                                                                            **
**   $DATE       : 2018-02-22 $                                               **
**                                                                            **
**  VARIANT   : VariantLT                                                     **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - MTL functionality for FCE kernel Test                    **
**                                                                            **
**  SPECIFICATION(S) : Aurix_SafeTlib_DS_FCETest.docm                         **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "FceTst.h"
#include "IfxFce_reg.h"
#include "IfxSrc_reg.h"
#include "IfxFce_bf.h"
#include "IfxSrc_bf.h"
#include "Mcal.h"
#include "Sl_Ipc.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/* Number of data words for CRC calculation:     */
#define FCETST_PATTERN_LENGTH             ((uint8)17)

/* Initial CRC values:                           */
#define FCETST_INITIAL_VALUE8             ((uint8)0xFFU)
#define FCETST_INITIAL_VALUE16            ((uint16)0xFFFFU)
#define FCETST_INITIAL_VALUE32            ((uint32)0xFFFFFFFFU )



/* Access Code for write access to LENGTH and CHECK registers:    */
#define FCE_ACCESS_CODE                   ((uint32)0xFACECAFEU )

/* FCE KERNEL Number */
#define FCE_KERNEL0                       ((uint8)0x0) 
#define FCE_KERNEL1                       ((uint8)0x1) 
#define FCE_KERNEL2                       ((uint8)0x2) 
#define FCE_KERNEL3                       ((uint8)0x3) 

/* FCE Shift value Number */
#define FCE_BIT_SET_VALUE                 ((uint32)0x1) 

/* Timeout value for FCE Status register and interrupt flag register to get set   
 */
#define FCETST_TIMEOUT_VALUE               ( (uint32)0x00001000U )

/*  SRC Reserved bit mask                                                     */
#define FCETST_SRC_RES_MASK_32BIT   ( (unsigned_int)0x7FFFFFFFU )
/* set SRC.CLRR bit                                                         */
#define FCETST_SET_SRC_CLRR_BIT   ( (unsigned_int)0x02000000U )

#define IFX_FCETST_START_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"
/* Pointer to Ifx_FCE_IN0 */         
static volatile Ifx_FCE_IN0 * const FCE_REGMAP = 
                (volatile Ifx_FCE_IN0 *) ((volatile void *)&FCE0_IN0_IR);
#define IFX_FCETST_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/* Typedef:FceTst_BackupDataType, storage for the backup of the FCE kernel 
   registers */
typedef struct FceTst_BackupDataType
{
  uint32 FceClkBackup;    /* Storage for the backup of the  FCE CLC register */
  uint32 FceLengthBackup;/* Storage for the backup of the  FCE LENGTH register*/
  uint32 FceCheckBackup;  /* Storage for the backup of the  FCE CHECK register*/
  uint32 FceCrcBackup;    /* Storage for the backup of the  FCE CRC register */
  uint32 FceIrBackup;     /* Storage for the backup of the  FCE IR register */
  uint32 FceStsBackup;    /* Storage for the backup of the  FCE STS register */
  uint32 FceCfgBackup;    /* Storage for the backup of the  FCE CFG register */
  uint32 FceCtrBackup;    /* Storage for the backup of the  FCE CTR register */
  uint32 FceSrcBackup;
      
}FceTst_BackupDataType;
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/*Crc 8bit Test Pattern Initialization */
#define IFX_FCETST_START_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"
static const uint8 Fce_Crc8bitTestPattern[FCETST_PATTERN_LENGTH] =
  {
    0x19U,
    0xECU,
    0xD8U,
    0x45U,
    0xD1U,
    0xB0U,
    0x25U,
    0xBCU,
    0x3FU,
    0x5CU,
    0xE8U,
    0x19U,
    0xECU,
    0xD8U,
    0x45U,
    0xD1U,
    0x54U
  };
#define IFX_FCETST_STOP_SEC_CONST_8BIT_ASIL_B
#include "Ifx_MemMap.h"

/*Crc 16bit Test Pattern Initialization */
#define IFX_FCETST_START_SEC_CONST_16BIT_ASIL_B
#include "Ifx_MemMap.h"      
static const uint16 Fce_Crc16bitTestPattern[FCETST_PATTERN_LENGTH] =
   {
     0x6819U,
     0xA5ECU,
     0x57D8U,
     0xA845U,
     0x61D1U,
     0xC8B0U,
     0xA825U,
     0xB8BCU,
     0x0C3FU,
     0xF45CU,
     0x1DE8U,
     0x6819U,
     0xA5ECU,
     0x57D8U,
     0xA845U,
     0x61D1U,
     0x5E49U
   };  
#define IFX_FCETST_STOP_SEC_CONST_16BIT_ASIL_B
#include "Ifx_MemMap.h" 

/*Crc 32bit Test Pattern Initialization */
#define IFX_FCETST_START_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"    
static const uint32 Fce_Crc32bitTestPattern[FCETST_PATTERN_LENGTH] =
  {
    0x7D2B6819U,
    0xD728A5ECU,
    0xEE8057D8U,
    0x2E92A845U,
    0x289761D1U,
    0xC86CC8B0U,
    0xCD6BA825U,
    0x39D5B8BCU,
    0x7A160C3FU,
    0x2244F45CU,
    0x0F781DE8U,
    0x7D2B6819U,
    0xD728A5ECU,
    0xEE8057D8U,
    0x2E92A845U,
    0x289761D1U,
    0x6B3485FCU
  };   
#define IFX_FCETST_STOP_SEC_CONST_32BIT_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define IFX_FCETST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/* Local functions to check the CRC checksum value */                       
static Sl_TstRsltType Fce_lTestCrc8(uint32* const TstSignature,
                              uint8 Kernel,const Sl_ParamSetType ParamSetIndex);
static Sl_TstRsltType Fce_lTestCrc16(uint32* const TstSignature,
                              uint8 Kernel,const Sl_ParamSetType ParamSetIndex);
static Sl_TstRsltType Fce_lTestCrc32(uint32* const TstSignature,
                              uint8 Kernel,const Sl_ParamSetType ParamSetIndex);

/* Local functions to call all local FCE register functions */    
static Sl_TstRsltType Fce_lFceErrorCheck(uint32* const TstSignature,
                            uint8 Kernel, const Sl_ParamSetType ParamSetIndex);

/* Local functions to check FCE register error */                       
static Sl_TstRsltType Fce_lConfigErrorCheck
                       (uint32* const TstSignature,uint8 Kernel);
static Sl_TstRsltType Fce_lCheckRegisterMisMatch
                       (uint32* const TstSignature,uint8 Kernel);
static Sl_TstRsltType Fce_lCheckRegMisMatchErrInj
                       (uint32* const TstSignature,uint8 Kernel);
static Sl_TstRsltType Fce_lCheckRegMismatchError(uint32* const TstSignature,
                          uint8 Kernel,const Sl_ParamSetType ParamSetIndex);
static Sl_TstRsltType Fce_lCheckLengthError(uint32* const TstSignature,
                         uint8 Kernel,const Sl_ParamSetType ParamSetIndex);
static Sl_TstRsltType Fce_lCheckBusError                       
 (uint32* const TstSignature,uint8 Kernel,const Sl_ParamSetType ParamSetIndex);
static Sl_TstRsltType FceTst_lInit
(
FceTst_BackupDataType* const FceTst_BackupData, uint8 Kernel
);

static Sl_TstRsltType FceTst_lRestore
(
const FceTst_BackupDataType* const FceTst_BackupData, uint8 Kernel
);
                       
/*******************************************************************************
**                       Private Function Definitions                         **
*******************************************************************************/

/*******************************************************************************
** Syntax : Sl_TstRsltType FceTst_FceTst(const Sl_ParamSetType ParamSetIndex, **
**                         const uint8 TstSeed, uint32* const TstSignature)   **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  ParamSetIndex - Identifies the parameter set to be      **
**                    used for test execution.                                **
**                    TstSeed - Seed to be used for generating the signature  **
**                                                                            **
** Parameters (out) : TstSingature - Test signature generated by the test     **
**                                                                            **
** Return value    : FCETST_SUCCESS - Test succeeded                          **
**                   FCETST_FAILURE -Test failed due to an unspecified        **
**                   HW failure                                               **
**                   FCETST_RESOURCE_TIMEOUT -  Test failed due to            **
**                   Sl_GetSpinLock api returns E_NOT_OK                      **
**                   FCETST_CRC_MISMATCH_ERROR -  Test failed due to mismatch **
**                   in the software calculated and FCE calculated result     **
**                   FCETST_NO_CFGREG_MISMATCH_ERROR -  Test failed due to    **
**                   injected CFG register mismatch error is not occurred     **
**                   FCETST_NO_CHECKREG_MISMATCH_ERROR -  Test failed due to  **
**                   injected CHECK register mismatch error is not occurred   **
**                   FCETST_NO_CRC_MISMATCH_ERROR - Test failed due to        **
**                   injected CRC register mismatch error is not occurred     **
**                   FCETST_NO_LENGTH_ERROR - Test failed due to injected     **
**                   LENGTH register error is not occurred                    **
**                   FCETST_NO_BUS_ERROR -  Test failed due to injected BUS   **
**                   error is not occurred                                    **
**                                                                            **
** Description     : FceTst_FceTst - FCE Kernel 8/16/32 bit test              **
**                                                                            **
*******************************************************************************/
Sl_TstRsltType FceTst_FceTst(const Sl_ParamSetType ParamSetIndex,
                         const uint8 TstSeed, uint32* const TstSignature)
{
  uint32                    Dummy_Read;
  uint32                    FceKernel;
  FceTst_BackupDataType     BackupData;
  FceTst_BackupDataType     BackupData1;
  Sl_TstRsltType Result1 = FCETST_FAILURE;
  Sl_TstRsltType Result2 = FCETST_FAILURE;
  Sl_TstRsltType Result = FCETST_FAILURE;
    
  /* Initialize Test Signature:                                             */
  *TstSignature = (uint32)CRC32((uint32)TEST_ID_FCE_TST,(uint32)TstSeed);
  
  /* Parameter check:                                                        */
  if (ParamSetIndex < (Sl_ParamSetType)FCE_TST_CFG_PARAM_COUNT)
  {
    if(E_OK != (Std_ReturnType)Sl_GetSpinLock(SL_FCE_SPNLCK_ID,
                                   (uint32)SL_FCE_TIMEOUT))
    {
      Result = FCETST_RESOURCE_TIMEOUT;
    }
    else
    {
      /* Configured FceKernel 8-BIT/16-BIT/32-BIT kernel */
      FceKernel = FceTst_ConfigRoot[ParamSetIndex].FceTstKernelSel; 
  
      switch(FceKernel)
      { 
        case FCETST_8BIT_KERNEL_TEST:
          /* Test initialization:   */      
          Result = FceTst_lInit(&BackupData,FCE_KERNEL3);
        break;
        
        case FCETST_16BIT_KERNEL_TEST:
          /* Test initialization:   */      
          Result = FceTst_lInit(&BackupData,FCE_KERNEL2);
        break;
          
        case FCETST_32BIT_KERNEL_TEST:
          /* Test initialization:   */      
          Result1 = FceTst_lInit(&BackupData,FCE_KERNEL0);
          Result2 = FceTst_lInit(&BackupData1,FCE_KERNEL1);

          if (Result1 != FCETST_SUCCESS)
          {
            Result = Result1;
          }
          else if (Result2 != FCETST_SUCCESS)
          {
            Result = Result2;
          }
          else
          {
            Result = FCETST_SUCCESS;
          }
        break;
        
        default : 
          Result = FCETST_FAILURE;                
        break;          
      }/* End of switch condition */
      
      /* Fce_linit()  is success */
      if (FCETST_SUCCESS == Result)
      { 
        /* Enable FCE Module clock  */
        Mcal_ResetENDINIT();
        FCE_CLC.B.DISR = 0U;
        Mcal_SetENDINIT();
        Dummy_Read = FCE_CLC.U;   
        UNUSED_PARAMETER(Dummy_Read)

        if (0U != FCE_CLC.B.DISS)
        {
          Result = FCETST_FAILURE;   
        }
       
        if (Result == FCETST_SUCCESS)
        {
          switch(FceKernel)
          { 
            case FCETST_8BIT_KERNEL_TEST:
              Result1 = Fce_lTestCrc8(TstSignature,FCE_KERNEL3,ParamSetIndex);

              if (Result1 != FCETST_SUCCESS)
              {
                Result = Result1;
              }            
            break;
          
            case FCETST_16BIT_KERNEL_TEST:
              Result1 = Fce_lTestCrc16(TstSignature,FCE_KERNEL2,ParamSetIndex);
              if (Result1 != FCETST_SUCCESS)
              {
                Result = Result1;
              }             
            break;
            
            case FCETST_32BIT_KERNEL_TEST:
              Result1 = Fce_lTestCrc32(TstSignature,FCE_KERNEL0,ParamSetIndex);
              Result2 = Fce_lTestCrc32(TstSignature,FCE_KERNEL1,ParamSetIndex);

              if (Result1 != FCETST_SUCCESS)
              {
                Result = Result1;
              }
              else if (Result2 != FCETST_SUCCESS)
              {
                Result = Result2;
              }
              else
              {
                /* added for MISRA */
              }
            break;
          
            default : 
              Result = FCETST_FAILURE;        
            break; 
          }/* End of switch condition */
        }
      }   /* End of switch FCETST_SUCCESS Result */     
    
      switch(FceKernel)
      { 
        case FCETST_8BIT_KERNEL_TEST:
        /* Test restoration:  */
        Result1 = FceTst_lRestore(&BackupData, FCE_KERNEL3);
      
        /* If Result is failure the previous error code takes priority
        and return the value, not FceTst_lrestore error code value. */
        if (Result == FCETST_SUCCESS)
        {
          Result = Result1;
        }
        break;
      
        case FCETST_16BIT_KERNEL_TEST:
        /* Test restoration:  */
        Result1 = FceTst_lRestore(&BackupData, FCE_KERNEL2);
      
        /* If Result is failure the previous error code takes priority
           and return the value, not FceTst_lrestore error code value. */
        if (Result == FCETST_SUCCESS)
        {
          Result = Result1;
        }     
        break;
      
        case FCETST_32BIT_KERNEL_TEST:
        /* Test restoration:  */
        Result1 = FceTst_lRestore(&BackupData, FCE_KERNEL0);
        Result2 = FceTst_lRestore(&BackupData1, FCE_KERNEL1);
      
        /* If Result is failure the previous error code takes priority
           and return the value, not FceTst_lrestore error code value. */
        if (Result == FCETST_SUCCESS)
        {
          if (Result1 == FCETST_SUCCESS)
          {
            Result = Result2;
          }
          else
          {
            Result = Result1;
          }
        }
        break;
      
        default : 
          Result = FCETST_FAILURE;        
          break;                           
      }/* End of switch condition */  
      Sl_ReleaseSpinLock(SL_FCE_SPNLCK_ID);
    }     
  }
  else
  {
    Result = FCETST_INVPARAMERR;  
  }
     
  /* Calculate final test signature            */  
  *TstSignature = (uint32)(CRC32(*TstSignature, Result)); 
  
  return Result;
}
/*******************************************************************************
** Syntax : void Fce_lTestCrc8(uint32* const TstSignature,uint8 Kernel,       **
**                                 const Sl_ParamSetType ParamSetIndex)       **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  ParamSetIndex - Identifies the parameter set to be      **
**                    used for test execution.                                **
**                    Kernel - Fce Kernel number for 8-BIT Engine kernel is 3 **
**                                                                            **
** Parameters (out) : TstSingature - Test signature generated by the test     **
**                                                                            **
** Return value    : FCETST_SUCCESS - Test succeeded                          **
**                   FCETST_FAILURE -Test failed due to an unspecified        **
**                   HW failure                                               **
**                   FCETST_CRC_MISMATCH_ERROR -  Test failed due to mismatch **
**                   in the software calculated and FCE calculated result     **
**                   FCETST_NO_CFGREG_MISMATCH_ERROR -  Test failed due to    **
**                   injected CFG register mismatch error is not occurred     **
**                   FCETST_NO_CHECKREG_MISMATCH_ERROR -  Test failed due to  **
**                   injected CHECK register mismatch error is not occurred   **
**                   FCETST_NO_CRC_MISMATCH_ERROR - Test failed due to        **
**                   injected CRC register mismatch error is not occurred     **
**                   FCETST_NO_LENGTH_ERROR - Test failed due to injected     **
**                   LENGTH register error is not occurred                    **
**                                                                            **
** Description     : Fce_lTestCrc8 Test - FCE 8-bit kernel verification       **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType Fce_lTestCrc8(uint32* const TstSignature,uint8 Kernel,
                                    const Sl_ParamSetType ParamSetIndex)
{
  uint8     LoopCounter;
  Sl_TstRsltType    Result = FCETST_FAILURE;

  /* Configure FCE Kernel 0:                              */
  Mcal_ResetENDINIT();  
  /* CRC and ALR enabled */ 
  FCE_REGMAP[Kernel].CFG.U = 
      (uint32)( (FCE_BIT_SET_VALUE << IFX_FCE_CFG_CCE_OFF) |
                (FCE_BIT_SET_VALUE <<  IFX_FCE_CFG_ALR_OFF)); 
  Mcal_SetENDINIT();   
  FCE_REGMAP[Kernel].LENGTH.U = FCE_ACCESS_CODE;
  FCE_REGMAP[Kernel].LENGTH.U = (FCETST_PATTERN_LENGTH - 1U);
  FCE_REGMAP[Kernel].CHECK.U = FCE_ACCESS_CODE;
  FCE_REGMAP[Kernel].CHECK.U = 
           Fce_Crc8bitTestPattern[FCETST_PATTERN_LENGTH - 1U];
  FCE_REGMAP[Kernel].CRC.U = FCETST_INITIAL_VALUE8;

  /* Shift test data into the CRC Kernel:                       */
  for (LoopCounter = 0U; LoopCounter < (FCETST_PATTERN_LENGTH - 1U); 
       LoopCounter++)
  {
    FCE_REGMAP[Kernel].IR.U = Fce_Crc8bitTestPattern[LoopCounter];
  }

  /* Compare both CRC Results and check that automatic
     comparison works correctly:  */
  if (Fce_Crc8bitTestPattern[FCETST_PATTERN_LENGTH - 1U] == 
                                          FCE_REGMAP[Kernel].RES.U)
  {
    if (1U == FCE_REGMAP[Kernel].STS.B.CMF)
    {
      Result = FCETST_CRC_MISMATCH_ERROR;
    }
    else
    {   
      Result = Fce_lFceErrorCheck(TstSignature,Kernel,ParamSetIndex);
    }
  }
      
  /* Calculate final test signature      */  
  *TstSignature = (uint32)(CRC32(*TstSignature, Result)); 
  return Result;

}
/*******************************************************************************
** Syntax : void Fce_lTestCrc16(uint32* const TstSignature,uint8 Kernel,      **
**                                  const Sl_ParamSetType ParamSetIndex)      **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  ParamSetIndex - Identifies the parameter set to be      **
**                    used for test execution.                                **
**                    Kernel - Fce Kernel number for 16-BIT Engine kernel is 2**
**                                                                            **
** Parameters (out) : TstSingature - Test signature generated by the test     **
**                                                                            **
** Return value    : FCETST_SUCCESS - Test succeeded                          **
**                   FCETST_FAILURE -Test failed due to an unspecified        **
**                   HW failure                                               **
**                   FCETST_CRC_MISMATCH_ERROR -  Test failed due to mismatch **
**                   in the software calculated and FCE calculated result     **
**                   FCETST_NO_CFGREG_MISMATCH_ERROR -  Test failed due to    **
**                   injected CFG register mismatch error is not occurred     **
**                   FCETST_NO_CHECKREG_MISMATCH_ERROR -  Test failed due to  **
**                   injected CHECK register mismatch error is not occurred   **
**                   FCETST_NO_CRC_MISMATCH_ERROR - Test failed due to        **
**                   injected CRC register mismatch error is not occurred     **
**                   FCETST_NO_LENGTH_ERROR - Test failed due to injected     **
**                   LENGTH register error is not occurred                    **
**                                                                            **
** Description     : Fce_lTestCrc16 Test - FCE 16-bit kernel verification     **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType Fce_lTestCrc16(uint32* const TstSignature,uint8 Kernel,
                                     const Sl_ParamSetType ParamSetIndex)
{  
  uint8        LoopCounter;   
  Sl_TstRsltType   Result = FCETST_FAILURE;
    
    
  /* Configure FCE Kernel 0:                             */
  Mcal_ResetENDINIT();
   /* CRC and ALR enabled */ 
  FCE_REGMAP[Kernel].CFG.U = 
      (uint32)( (FCE_BIT_SET_VALUE << IFX_FCE_CFG_CCE_OFF) |
                (FCE_BIT_SET_VALUE <<  IFX_FCE_CFG_ALR_OFF)); 
   
  Mcal_SetENDINIT();
  FCE_REGMAP[Kernel].LENGTH.U = FCE_ACCESS_CODE;
  FCE_REGMAP[Kernel].LENGTH.U = (FCETST_PATTERN_LENGTH - 1U);
  FCE_REGMAP[Kernel].CHECK.U = FCE_ACCESS_CODE;
  FCE_REGMAP[Kernel].CHECK.U = 
              Fce_Crc16bitTestPattern[FCETST_PATTERN_LENGTH - 1U];
  FCE_REGMAP[Kernel].CRC.U = FCETST_INITIAL_VALUE16;
  
  /* Shift test data into the CRC Kernel:                        */
  for (LoopCounter = 0U; LoopCounter < (FCETST_PATTERN_LENGTH - 1U);
       LoopCounter++)
  {
    FCE_REGMAP[Kernel].IR.U = Fce_Crc16bitTestPattern[LoopCounter];
  }
  
  /* Compare both CRC Results and check that automatic 
      comparison works correctly: */
  if (Fce_Crc16bitTestPattern[FCETST_PATTERN_LENGTH - 1U] == 
                                          FCE_REGMAP[Kernel].RES.U)
  { 
    if (1U == FCE_REGMAP[Kernel].STS.B.CMF)
    {
      Result = FCETST_CRC_MISMATCH_ERROR;
    }
    else
    {   
      Result = Fce_lFceErrorCheck(TstSignature,Kernel,ParamSetIndex);
    }
  }
  
  /* Calculate final test signature                          */  
  *TstSignature = (uint32)(CRC32(*TstSignature, Result)); 
             
  return Result;
}
/*******************************************************************************
** Syntax : void Fce_lTestCrc32(uint32* const TstSignature,uint8 Kernel,      **
**                                  const Sl_ParamSetType ParamSetIndex)      **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  ParamSetIndex - Identifies the parameter set to be      **
**                    used for test execution.                                **
**                 Kernel - Fce Kernel number for 32-BIT Engine kernel is 0/1 **
**                                                                            **
** Parameters (out) : TstSingature - Test signature generated by the test     **
**                                                                            **
** Return value    : FCETST_SUCCESS - Test succeeded                          **
**                   FCETST_FAILURE -Test failed due to an unspecified        **
**                   HW failure                                               **
**                   FCETST_CRC_MISMATCH_ERROR -  Test failed due to mismatch **
**                   in the software calculated and FCE calculated result     **
**                   FCETST_NO_CFGREG_MISMATCH_ERROR -  Test failed due to    **
**                   injected CFG register mismatch error is not occurred     **
**                   FCETST_NO_CHECKREG_MISMATCH_ERROR -  Test failed due to  **
**                   injected CHECK register mismatch error is not occurred   **
**                   FCETST_NO_CRC_MISMATCH_ERROR - Test failed due to        **
**                   injected CRC register mismatch error is not occurred     **
**                   FCETST_NO_LENGTH_ERROR - Test failed due to injected     **
**                   LENGTH register error is not occurred                    **
**                   FCETST_NO_BUS_ERROR -  Test failed due to injected BUS   **
**                   error is not occurred                                    **
**                                                                            **
** Description     : Fce_lTestCrc32 Test - FCE 32-bit kernel verification     **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType Fce_lTestCrc32(uint32* const TstSignature,uint8 Kernel,
                                     const Sl_ParamSetType ParamSetIndex)
{
  uint8       LoopCounter;  
  Sl_TstRsltType    Result = FCETST_FAILURE;
     
   /* Configure FCE Kernel 0:                             */
   Mcal_ResetENDINIT();
    /* CRC and ALR enabled */ 
   FCE_REGMAP[Kernel].CFG.U = 
      (uint32)( (FCE_BIT_SET_VALUE << IFX_FCE_CFG_CCE_OFF) |
                (FCE_BIT_SET_VALUE <<  IFX_FCE_CFG_ALR_OFF));   
   Mcal_SetENDINIT();
   FCE_REGMAP[Kernel].LENGTH.U = FCE_ACCESS_CODE;
   FCE_REGMAP[Kernel].LENGTH.U = (FCETST_PATTERN_LENGTH - 1U);
   FCE_REGMAP[Kernel].CHECK.U = FCE_ACCESS_CODE;
   FCE_REGMAP[Kernel].CHECK.U = 
           Fce_Crc32bitTestPattern[FCETST_PATTERN_LENGTH - 1U];
   FCE_REGMAP[Kernel].CRC.U = FCETST_INITIAL_VALUE32;
  
   /* Shift test data into the CRC Kernel:  */
   for (LoopCounter = 0U; LoopCounter < (FCETST_PATTERN_LENGTH - 1U);
        LoopCounter++)
   {
    FCE_REGMAP[Kernel].IR.U = Fce_Crc32bitTestPattern[LoopCounter];
   }
  
   /* Compare both CRC Results and check that automatic 
      comparison works correctly:*/
    if (Fce_Crc32bitTestPattern[FCETST_PATTERN_LENGTH - 1U] == 
                                        FCE_REGMAP[Kernel].RES.U)
    { 
      if (1U == FCE_REGMAP[Kernel].STS.B.CMF)
      {
        Result = FCETST_CRC_MISMATCH_ERROR;
      }
      else
      {   
        Result = Fce_lFceErrorCheck(TstSignature,Kernel,ParamSetIndex);
      }
    }
  
   /* Calculate final test signature                                        */
   *TstSignature = (uint32)(CRC32(*TstSignature, Result)); 
    
  return Result;
}
/*******************************************************************************
** Syntax : void Fce_lFceErrorCheck(uint32* const TstSignature,uint8 Kernel,  **
**           const Sl_ParamSetType ParamSetIndex)                             **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  ParamSetIndex - Identifies the parameter set to be      **
**                    used for test execution.                                **
**                 Kernel - Fce Kernel number 0/1/2/3                         **
**                                                                            **
** Parameters (out) : TstSingature - Test signature generated by the test     **
**                                                                            **
** Return value    : FCETST_SUCCESS - Test succeeded                          **
**                   FCETST_FAILURE -Test failed due to an unspecified        **
**                   HW failure                                               **
**                   FCETST_CRC_MISMATCH_ERROR -  Test failed due to mismatch **
**                   in the software calculated and FCE calculated result     **
**                   FCETST_NO_CFGREG_MISMATCH_ERROR -  Test failed due to    **
**                   injected CFG register mismatch error is not occurred     **
**                   FCETST_NO_CHECKREG_MISMATCH_ERROR -  Test failed due to  **
**                   injected CHECK register mismatch error is not occurred   **
**                   FCETST_NO_CRC_MISMATCH_ERROR - Test failed due to        **
**                   injected CRC register mismatch error is not occurred     **
**                   FCETST_NO_LENGTH_ERROR - Test failed due to injected     **
**                   LENGTH register error is not occurred                    **
**                   FCETST_NO_BUS_ERROR -  Test failed due to injected BUS   **
**                   error is not occurred                                    **
** Description     : Fce_lFceErrorCheck  - local function for error check     **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType Fce_lFceErrorCheck(uint32* const TstSignature,
        uint8 Kernel,const Sl_ParamSetType ParamSetIndex)
{  
  Sl_TstRsltType  Result = FCETST_FAILURE;
  /* Test Configuration Register Mismatch Error:  */

  Result = Fce_lConfigErrorCheck(TstSignature,Kernel);


  /* Test Check Register Mismatch Error:  */
  if (FCETST_SUCCESS == Result)
  {
    Result = Fce_lCheckRegisterMisMatch(TstSignature,Kernel);     
  }

  /* Test CRC Mismatch Error using error injection Mechanism: */
  if (FCETST_SUCCESS == Result)
  {
    Result = Fce_lCheckRegMisMatchErrInj(TstSignature,Kernel);
  }

  /* Test CRC Mismatch Error using wrong check value: */
  if (FCETST_SUCCESS == Result)
  {
    Result = Fce_lCheckRegMismatchError(TstSignature,Kernel,ParamSetIndex);
  }

  /* Test Length Error:                               */
  if (FCETST_SUCCESS == Result)
  {
    Result = Fce_lCheckLengthError(TstSignature,Kernel,ParamSetIndex);
  } 
  
  /* Test Bus Error:                                  */
  if (FCETST_SUCCESS == Result)
  {
    if (FceTst_ConfigRoot[ParamSetIndex].FceTstKernelSel !=
                                               FCETST_8BIT_KERNEL_TEST)  
    {   
      Result = Fce_lCheckBusError(TstSignature,Kernel,ParamSetIndex);
    }
  }
  
  return Result;
}

/*******************************************************************************
** Syntax : static Sl_TstRsltType Fce_lConfigErrorCheck                       **
**                            (uint32* const TstSignature,uint8 Kernel)       **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) : Kernel - Fce Kernel number for 0/1/2/3                   **
**                                                                            **
** Parameters (out) : TstSingature - Test signature generated by the test     **
**                                                                            **
** Return value    : FCETST_SUCCESS - Test succeeded                          **
**                   FCETST_FAILURE -Test failed due to an unspecified        **
**                   HW failure                                               **
**                   FCETST_NO_CFGREG_MISMATCH_ERROR -  Test failed due to    **
**                   injected CFG register mismatch error is not occurred     **
**                                                                            **
** Description     : Test CFG Register Mismatch Error check                   **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType Fce_lConfigErrorCheck
                       (uint32* const TstSignature,uint8 Kernel)
{ 
  uint32      Timeout;  
  uint32      FceCefStatus;
  uint32      FceSrcSrrStatus;
  Sl_TstRsltType    Result = FCETST_FAILURE;
  
  /* SRC Register Reserved bit Should be 0 while writing and Clear error flag */
  SRC_FCE.U = ((SRC_FCE.U & FCETST_SRC_RES_MASK_32BIT) | (FCETST_SET_SRC_CLRR_BIT));
  FCE_REGMAP[Kernel].STS.B.CEF = 1U;
  FCE_REGMAP[Kernel].CTR.B.FRM_CFG = 1U;
  Mcal_ResetENDINIT();  
  FCE_REGMAP[Kernel].CFG.B.CEI = 1U;
  Mcal_SetENDINIT(); 
  
  Timeout = FCETST_TIMEOUT_VALUE;
  do
  {
    Timeout = Timeout - 1U;
    FceCefStatus = FCE_REGMAP[Kernel].STS.B.CEF;
    FceSrcSrrStatus = SRC_FCE.B.SRR;
  } while ((0U == FceCefStatus) && (0U == FceSrcSrrStatus)  && (Timeout > 0U));  
  FCE_REGMAP[Kernel].CTR.B.FRM_CFG = 0U;
  if (0U == FCE_REGMAP[Kernel].STS.B.CEF) 
  {
    Result = FCETST_NO_CFGREG_MISMATCH_ERROR;
  }
  else if (0U == SRC_FCE.B.SRR)
  {
    Result = FCETST_NOCFGREG_MISMAT_INTR_ERR; 
  }
  else
  {      
    Result = FCETST_SUCCESS;
  } 
  
  FCE_REGMAP[Kernel].STS.B.CEF = 1U;
  SRC_FCE.U = ((SRC_FCE.U & FCETST_SRC_RES_MASK_32BIT) | (FCETST_SET_SRC_CLRR_BIT));
    
   /* Calculate final test signature                                         */
  *TstSignature = (uint32)(CRC32(*TstSignature, Result)); 
  
  return Result;
}
/*******************************************************************************
** Syntax : static Sl_TstRsltType Fce_lCheckRegisterMisMatch                  **
**                            (uint32* const TstSignature,uint8 Kernel)       **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  Kernel - Fce Kernel number 0/1/2/3                      **
**                                                                            **
** Parameters (out) : TstSingature - Test signature generated by the test     **
**                                                                            **
** Return value    : FCETST_SUCCESS - Test succeeded                          **
**                   FCETST_FAILURE -Test failed due to an unspecified        **
**                   HW failure                                               **
**                   FCETST_NO_CHECKREG_MISMATCH_ERROR -  Test failed due to  **
**                   injected CHECK register mismatch error is not occurred   **
**                                                                            **
** Description     : Test CHECK Register Mismatch Error                       **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType Fce_lCheckRegisterMisMatch
                       (uint32* const TstSignature,uint8 Kernel)
{ 
  uint32      Timeout;  
  uint32      FceCefStatus;
  uint32      FceSrcSrrStatus;
  Sl_TstRsltType    Result = FCETST_FAILURE;
  
 /* SRC Register Reserved bit Should be 0 while writing and Clear error flag */
  SRC_FCE.U = ((SRC_FCE.U & FCETST_SRC_RES_MASK_32BIT) | (FCETST_SET_SRC_CLRR_BIT));
  FCE_REGMAP[Kernel].STS.B.CEF = 1U;  
  FCE_REGMAP[Kernel].CTR.B.FRM_CHECK = 1U;
  Mcal_ResetENDINIT();  
  FCE_REGMAP[Kernel].CFG.B.CEI = 1U;
  Mcal_SetENDINIT(); 
  
  Timeout = FCETST_TIMEOUT_VALUE;
  do
  {
    Timeout = Timeout - 1U;
    FceCefStatus = FCE_REGMAP[Kernel].STS.B.CEF;
    FceSrcSrrStatus = SRC_FCE.B.SRR;
  } while ((0U == FceCefStatus) && (0U == FceSrcSrrStatus) && (Timeout > 0U));
  FCE_REGMAP[Kernel].CTR.B.FRM_CHECK = 0U;
  if (0U == FCE_REGMAP[Kernel].STS.B.CEF)
  {
    Result = FCETST_NO_CHECKREG_MISMATCH_ERROR;
  }
  else if (0U == SRC_FCE.B.SRR)
  {
    Result = FCETST_NO_CHECKREG_MISMAT_INTR_ERR;
  }
  else
  {
    Result = FCETST_SUCCESS;
  }
  
  FCE_REGMAP[Kernel].STS.B.CEF = 1U;
  SRC_FCE.U = ((SRC_FCE.U & FCETST_SRC_RES_MASK_32BIT) | (FCETST_SET_SRC_CLRR_BIT));
  
  /* Calculate final test signature                                         */
  *TstSignature = (uint32)(CRC32(*TstSignature, Result)); 
  
  return Result;
}
/*******************************************************************************
** Syntax : static Sl_TstRsltType Fce_lCheckRegMisMatchErrInj                 **
**                            (uint32* const TstSignature,uint8 Kernel)       **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) : Kernel - Fce Kernel number 0/1/2/3                       **
**                                                                            **
** Parameters (out) : TstSingature - Test signature generated by the test     **
**                                                                            **
** Return value    : FCETST_SUCCESS - Test succeeded                          **
**                   FCETST_FAILURE -Test failed due to an unspecified        **
**                   HW failure                                               **
**                   FCETST_NO_CRC_MISMATCH_ERROR - Test failed due to        **
**                   injected CRC register mismatch error is not occurred     **
**                                                                            **
** Description     : Test CRC register Mismatch Error using error injection   **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType Fce_lCheckRegMisMatchErrInj
                       (uint32* const TstSignature,uint8 Kernel)
{ 
  uint32      Timeout;  
  uint32      FceCmfStatus;
  uint32      FceSrcSrrStatus;
  Sl_TstRsltType    Result = FCETST_FAILURE;
  
 /* SRC Register Reserved bit Should be 0 while writing and Clear error flag */
  SRC_FCE.U = ((SRC_FCE.U & FCETST_SRC_RES_MASK_32BIT) | (FCETST_SET_SRC_CLRR_BIT));
  FCE_REGMAP[Kernel].STS.B.CMF = 1U;  
  FCE_REGMAP[Kernel].CTR.B.FCM = 1U;  
  Mcal_ResetENDINIT();
  FCE_REGMAP[Kernel].CFG.B.CMI = 1U;
  Mcal_SetENDINIT();
  
  Timeout = FCETST_TIMEOUT_VALUE;
  do
  {
    Timeout = Timeout - 1U;
    FceCmfStatus = FCE_REGMAP[Kernel].STS.B.CMF;
    FceSrcSrrStatus = SRC_FCE.B.SRR;
  }while ((0U == FceCmfStatus) && (0U == FceSrcSrrStatus) && (Timeout > 0U));
  FCE_REGMAP[Kernel].CTR.B.FCM = 0U;
  if (0U == FCE_REGMAP[Kernel].STS.B.CMF)
  {
    Result = FCETST_NO_CRC_MISMATCH_ERROR;
  }
  else if(0U == SRC_FCE.B.SRR)
  {
    Result = FCETST_NO_CRC_MISMATCH_INTR_ERR;
  }
  else
  {
    Result = FCETST_SUCCESS;
  }
  FCE_REGMAP[Kernel].STS.B.CMF = 1U;
  SRC_FCE.U = ((SRC_FCE.U & FCETST_SRC_RES_MASK_32BIT) | (FCETST_SET_SRC_CLRR_BIT));
    
  
  /* Calculate final test signature                                         */  
  *TstSignature = (uint32)(CRC32(*TstSignature, Result)); 
  return Result;
}
/*******************************************************************************
** Syntax : static Sl_TstRsltType Fce_lCheckRegMismatchError (uint32* const   **
**      TstSignature,uint8 Kernel,,const Sl_ParamSetType ParamSetIndex)       **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  ParamSetIndex - Identifies the parameter set to be      **
**                    used for test execution.                                **
**                 Kernel - Fce Kernel number 0/1/2/3                         **
**                                                                            **
** Parameters (out) : TstSingature - Test signature generated by the test     **
**                                                                            **
** Return value    : FCETST_SUCCESS - Test succeeded                          **
**                   FCETST_FAILURE -Test failed due to an unspecified        **
**                   HW failure                                               **
**                   FCETST_NO_CRC_MISMATCH_ERROR - Test failed due to        **
**                   injected CRC register mismatch error is not occurred     **
**                                                                            **
** Description     : Test CRC Mismatch Error using wrong check value          **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType Fce_lCheckRegMismatchError(uint32* const TstSignature,
                               uint8 Kernel,const Sl_ParamSetType ParamSetIndex)
{ 
  uint32      Timeout;  
  uint8       LoopCounter;
  uint8       Crc8bitswcalval;
  uint16      Crc16bitswcalval;
  uint32      Crc32bitswcalval;
  uint32      FceKernel;
  uint32      FceCmfStatus;
  uint32      FceSrcSrrStatus;
  Sl_TstRsltType    Result = FCETST_FAILURE;     
  FceKernel = FceTst_ConfigRoot[ParamSetIndex].FceTstKernelSel;
  /* SRC Register Reserved bit Should be 0 while writing and Clear error flag */
  SRC_FCE.U = ((SRC_FCE.U & FCETST_SRC_RES_MASK_32BIT) | (FCETST_SET_SRC_CLRR_BIT));
  FCE_REGMAP[Kernel].STS.B.CMF = 1U;
  FCE_REGMAP[Kernel].CHECK.U = FCE_ACCESS_CODE;
  switch(FceKernel)
  { 
    case FCETST_8BIT_KERNEL_TEST:
      Crc8bitswcalval = 
           (uint8)(Fce_Crc8bitTestPattern[FCETST_PATTERN_LENGTH - 1U] + 1U);
      FCE_REGMAP[Kernel].CHECK.U = Crc8bitswcalval;
    break;
  
    case FCETST_16BIT_KERNEL_TEST:
      Crc16bitswcalval = 
           (uint16)(Fce_Crc16bitTestPattern[FCETST_PATTERN_LENGTH - 1U] + 1U);
      FCE_REGMAP[Kernel].CHECK.U = Crc16bitswcalval;
    break;
    
    case FCETST_32BIT_KERNEL_TEST:
      Crc32bitswcalval = 
           (uint32)(Fce_Crc32bitTestPattern[FCETST_PATTERN_LENGTH - 1U] + 1U);
      FCE_REGMAP[Kernel].CHECK.U = Crc32bitswcalval;
    break;
  
    default :                     
    break;    
  }/* End of switch condition */

   /* Shift test data into the CRC Kernel:                      */
   for (LoopCounter = 0U; LoopCounter < (FCETST_PATTERN_LENGTH - 1U);
        LoopCounter++)
   {
      switch(FceKernel)
      { 
        case FCETST_8BIT_KERNEL_TEST:
          FCE_REGMAP[Kernel].IR.U = Fce_Crc8bitTestPattern[LoopCounter];
        break;
      
        case FCETST_16BIT_KERNEL_TEST:
          FCE_REGMAP[Kernel].IR.U = Fce_Crc16bitTestPattern[LoopCounter];
        break;
        
        case FCETST_32BIT_KERNEL_TEST:
          FCE_REGMAP[Kernel].IR.U = Fce_Crc32bitTestPattern[LoopCounter];
        break;
      
        default :                        
        break;    
      }/* End of switch condition */
   }

   /* Wait for the CRC mismatch being reflected in the status register:*/
   Timeout = FCETST_TIMEOUT_VALUE;
   do
   {
     Timeout = Timeout - 1U;
   FceCmfStatus = FCE_REGMAP[Kernel].STS.B.CMF;
     FceSrcSrrStatus = SRC_FCE.B.SRR;
    } while ((0U == FceCmfStatus) && (0U == FceSrcSrrStatus) && (Timeout > 0U));
   if (0U == FCE_REGMAP[Kernel].STS.B.CMF)
   {
     Result = FCETST_NO_CRC_MISMATCH_ERROR;
   }
   else if(0U == SRC_FCE.B.SRR)
   {
     Result = FCETST_NO_CRC_MISMATCH_INTR_ERR;
   }
   else
   {
     Result = FCETST_SUCCESS;
   }
   FCE_REGMAP[Kernel].STS.B.CMF = 1U;  /* Clear error flag */
   /* SRC Register Reserved bit Should be 0 while writing and Clear error flag */
  SRC_FCE.U = ((SRC_FCE.U & FCETST_SRC_RES_MASK_32BIT) | (FCETST_SET_SRC_CLRR_BIT));
      
  /* Calculate final test signature                                         */
  *TstSignature = (uint32)(CRC32(*TstSignature, Result)); 
  return Result;
}
/*******************************************************************************
** Syntax : static Sl_TstRsltType Fce_lCheckLengthError  (uint32* const       **
**       TstSignature,uint8 Kernel,const Sl_ParamSetType ParamSetIndex)       **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  ParamSetIndex - Identifies the parameter set to be      **
**                    used for test execution.                                **
**                 Kernel - Fce Kernel number 0/1/2/3                         **
**                                                                            **
** Parameters (out) : TstSingature - Test signature generated by the test     **
**                                                                            **
** Return value    : FCETST_SUCCESS - Test succeeded                          **
**                   FCETST_FAILURE -Test failed due to an unspecified        **
**                   HW failure                                               **
**                   FCETST_NO_LENGTH_ERROR - Test failed due to injected     **
**                   LENGTH register error is not occurred                    **
**                                                                            **
** Description     : Fce_lCheckLengthError - LENGTH register error Test       **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType Fce_lCheckLengthError(uint32* const TstSignature,
                             uint8 Kernel, const Sl_ParamSetType ParamSetIndex)
{ 
  uint32      Timeout;  
  uint8       LoopCounter;
  uint32 FceKernel;  
  uint32      FceLefStatus;
  uint32      FceSrcSrrStatus;
  Sl_TstRsltType    Result = FCETST_FAILURE;
  FceKernel = FceTst_ConfigRoot[ParamSetIndex].FceTstKernelSel;
  /* SRC Register Reserved bit Should be 0 while writing and Clear error flag */
  SRC_FCE.U = ((SRC_FCE.U & FCETST_SRC_RES_MASK_32BIT) | (FCETST_SET_SRC_CLRR_BIT));  
  /* Disable Automatic Length Reload:                        */
  Mcal_ResetENDINIT();
  FCE_REGMAP[Kernel].CFG.B.ALR = 0U;
  FCE_REGMAP[Kernel].CFG.B.LEI = 1U;
  Mcal_SetENDINIT();   
  
  /* Clear error flag, if it was unexpectedly set before */
  FCE_REGMAP[Kernel].STS.B.LEF = 1U; 

  /* Shift test data into the FCE Kernel:                      */
  for (LoopCounter = 0U; LoopCounter < (FCETST_PATTERN_LENGTH - 1U); 
       LoopCounter++)
  {
     switch(FceKernel)
     { 
       case FCETST_8BIT_KERNEL_TEST:
         FCE_REGMAP[Kernel].IR.U = Fce_Crc8bitTestPattern[LoopCounter];
       break;
     
       case FCETST_16BIT_KERNEL_TEST:
         FCE_REGMAP[Kernel].IR.U = Fce_Crc16bitTestPattern[LoopCounter];
       break;
       
       case FCETST_32BIT_KERNEL_TEST:
         FCE_REGMAP[Kernel].IR.U = Fce_Crc32bitTestPattern[LoopCounter];
       break;
     
       default :
        break;    
     }/* End of switch condition */
   
  } /* End of For Loop*/

  /* Shift another word into the IR:                       */
  FCE_REGMAP[Kernel].IR.U = 0U;

  /* Wait for the Length Error Flag being set:            */
  Timeout = FCETST_TIMEOUT_VALUE;
  do
  {
    Timeout = Timeout - 1U;
    FceLefStatus = FCE_REGMAP[Kernel].STS.B.LEF;
    FceSrcSrrStatus = SRC_FCE.B.SRR;
  } while ((0U == FceLefStatus) && (0U == FceSrcSrrStatus) && (Timeout > 0U));
  if (0U == FCE_REGMAP[Kernel].STS.B.LEF)
  {
    Result = FCETST_NO_LENGTH_ERROR;
  }
  else if (0U == SRC_FCE.B.SRR)
  {
    Result = FCETST_NO_LENGTH_INTR_ERROR;
  }
  else
  {
    Result = FCETST_SUCCESS;
  }
  FCE_REGMAP[Kernel].STS.B.LEF = 1U;  /* Clear error flag         */
  SRC_FCE.U = ((SRC_FCE.U & FCETST_SRC_RES_MASK_32BIT) | (FCETST_SET_SRC_CLRR_BIT));
   
   /* Calculate final test signature                 */  
  *TstSignature = (uint32)(CRC32(*TstSignature, Result)); 
   return Result;
}
/*******************************************************************************
** Syntax : static Sl_TstRsltType Fce_lCheckBusError                          **
**                            (uint32* const TstSignature,uint8 Kernel,       **
**                                 const Sl_ParamSetType ParamSetIndex)       **
**                                                                            **
** Service ID:  none                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) : Kernel - Fce Kernel number 0/1                           **
**                                                                            **
** Parameters (out) : TstSingature - Test signature generated by the test     **
**                                                                            **
** Return value    : FCETST_SUCCESS - Test succeeded                          **
**                   FCETST_FAILURE -Test failed due to an unspecified        **
**                   HW failure                                               **
**                   FCETST_NO_BUS_ERROR -  Test failed due to injected BUS   **
**                   error is not occurred                                    **
**                                                                            **
** Description     : Fce_lCheckBusError - Bus Error Test                      **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType Fce_lCheckBusError
  (uint32* const TstSignature,uint8 Kernel, const Sl_ParamSetType ParamSetIndex)
{ 
  uint32      Timeout;  
  uint32      FceBefStatus;
  uint32      FceSrcSrrStatus;
  volatile uint16*  FCEIR_Ptr = NULL_PTR;
  volatile uint8*   FCEIR1_Ptr = NULL_PTR;
  Sl_TstRsltType    Result = FCETST_FAILURE;
  
  /* SRC Register Reserved bit Should be 0 while writing */
  SRC_FCE.U = ((SRC_FCE.U & FCETST_SRC_RES_MASK_32BIT) | (FCETST_SET_SRC_CLRR_BIT));
  FCE_REGMAP[Kernel].STS.B.BEF = 1U;  
  Mcal_ResetENDINIT();  
  FCE_REGMAP[Kernel].CFG.B.BEI = 1U;
  Mcal_SetENDINIT(); 

  if (FceTst_ConfigRoot[ParamSetIndex].FceTstKernelSel ==
                                               FCETST_32BIT_KERNEL_TEST)  
  {
    FCEIR_Ptr = (volatile uint16*)(volatile void*)&FCE_REGMAP[Kernel].IR.U;
    *FCEIR_Ptr = (uint16)0xDEAD;    /* 16bit access to IR           */
  }
  else if(FceTst_ConfigRoot[ParamSetIndex].FceTstKernelSel ==
                                                  FCETST_16BIT_KERNEL_TEST) 
  {
    FCEIR1_Ptr = (volatile uint8*)(volatile void*)&FCE_REGMAP[Kernel].IR.U;
    *FCEIR1_Ptr = (uint8)0xDE;    /* 8bit access to IR           */
  }
  else
  {
    /* Do Nothing, added for MISRA */
  }
  
  /* Wait for the Bus Error Flag being set:                    */
  Timeout = FCETST_TIMEOUT_VALUE;
  do
  {
    Timeout = Timeout - 1U;
    FceBefStatus = FCE_REGMAP[Kernel].STS.B.BEF;
    FceSrcSrrStatus = SRC_FCE.B.SRR;
  } while ((0U == FceBefStatus) && (0U == FceSrcSrrStatus) && (Timeout > 0U));
  if (0U == FCE_REGMAP[Kernel].STS.B.BEF)
  {
    Result = FCETST_NO_BUS_ERROR;
  }
  else if (0U == SRC_FCE.B.SRR)
  {
    Result = FCETST_NO_BUS_INTR_ERROR;
  }
  else
  {
    Result = FCETST_SUCCESS;
  }
  FCE_REGMAP[Kernel].STS.B.BEF = 1U;  /* Clear error flag   */
  SRC_FCE.U = ((SRC_FCE.U & FCETST_SRC_RES_MASK_32BIT) | (FCETST_SET_SRC_CLRR_BIT));
    
  /* Calculate final test signature     */  
  *TstSignature = (uint32)(CRC32(*TstSignature, Result)); 
  
  return Result;
}
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           :static Sl_TstRsltType FceTst_lInit                       **
**             (FceTst_BackupDataType* const FceTst_BackupData, uint8 Kernel) **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   :  FceTst_BackupData - pointer to FceTst BackupData       **
**                     Kernel - Fce Kernel Number                             **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : FECTST_SUCCESS - Test succeeded                         **
**                    <Error ID> - Type of error during test                  **
**                                                                            **
** Description      : Backup SFR that will be modified.                       **
**                                                                            **
*******************************************************************************/

static Sl_TstRsltType FceTst_lInit
(
FceTst_BackupDataType* const FceTst_BackupData, uint8 Kernel
)
{
  Sl_TstRsltType    Result = FCETST_FAILURE;
  
  /* Store Fce Test register */  
  FceTst_BackupData->FceClkBackup = FCE_CLC.U;
  FceTst_BackupData->FceLengthBackup = FCE_REGMAP[Kernel].LENGTH.U;
  FceTst_BackupData->FceCheckBackup = FCE_REGMAP[Kernel].CHECK.U;
  FceTst_BackupData->FceCrcBackup = FCE_REGMAP[Kernel].CRC.U;
  FceTst_BackupData->FceIrBackup = FCE_REGMAP[Kernel].IR.U;
  FceTst_BackupData->FceStsBackup = FCE_REGMAP[Kernel].STS.U;
  FceTst_BackupData->FceCfgBackup = FCE_REGMAP[Kernel].CFG.U;
  FceTst_BackupData->FceCtrBackup = FCE_REGMAP[Kernel].CTR.U;  
  FceTst_BackupData->FceSrcBackup = SRC_FCE.U;    
  if(FCE_REGMAP[Kernel].STS.U != 0x0U)
  {
    Result = FCETST_INIT_FAILURE;
  }
  else
  {
    Result = FCETST_SUCCESS;
  }
  
  return Result;  
}

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : static Sl_TstRsltType FceTst_lRestore                   **
**                   (const FceTst_BackupDataType*                            **
**                    const FceTst_BackupData, uint8 Kernel)                  **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : ParamSetIndex : Identifies the parameter set to be      **
**                                    used for test execution                 **
**                    TstSeed : Seed to be used for generating the signature  **
**                    Kernel: Kernel number                                   **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : FCETST_SUCCESS - Test succeeded                         **
**                    <Error ID> - Type of error during test                  **
**                                                                            **
** Description      : Restore modified SFR                                    **
**                                                                            **
*******************************************************************************/

static Sl_TstRsltType FceTst_lRestore
(
const FceTst_BackupDataType* const FceTst_BackupData, uint8 Kernel
)
{
  Sl_TstRsltType    Result = FCETST_FAILURE;
  
  if(FCE_REGMAP[Kernel].STS.U != 0x0U)
  {
    Result = FCETST_RESTORE_FAILURE;
  }
  else
  {
    Result = FCETST_SUCCESS;
  } 
  /* Restore previously backed-up Fce Test Register*/
  
  FCE_REGMAP[Kernel].CRC.U = FceTst_BackupData->FceCrcBackup;
  FCE_REGMAP[Kernel].IR.U =  FceTst_BackupData->FceIrBackup;  
  FCE_REGMAP[Kernel].STS.U = FceTst_BackupData->FceStsBackup;  
  FCE_REGMAP[Kernel].CTR.U = FceTst_BackupData->FceCtrBackup; 
  FCE_REGMAP[Kernel].LENGTH.U = FCE_ACCESS_CODE;
  FCE_REGMAP[Kernel].LENGTH.U = FceTst_BackupData->FceLengthBackup;
  FCE_REGMAP[Kernel].CHECK.U = FCE_ACCESS_CODE;
  FCE_REGMAP[Kernel].CHECK.U = FceTst_BackupData->FceCheckBackup;  
  Mcal_ResetENDINIT();  
  FCE_REGMAP[Kernel].CFG.U = FceTst_BackupData->FceCfgBackup;     
  SRC_FCE.U = FceTst_BackupData->FceSrcBackup;  
  /* Restore Fce Clock */
   if ((Kernel == FCE_KERNEL1) || (Kernel == FCE_KERNEL2) || 
                                     (Kernel == FCE_KERNEL3))
  {
    FCE_CLC.U = FceTst_BackupData->FceClkBackup; 
  }
  Mcal_SetENDINIT();
  
  return Result;
}


#define IFX_FCETST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
