/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2012)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : SfrCmpTst.c $                                              **
**                                                                            **
**   $CC VERSION : \main\20 $                                                 **
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
**  DESCRIPTION  : SfrCmp test read the values of configured SFR register,    **
** apply a mask value and then compare them to an expected configuration value**
**    This file contains the single point fault metric SFR                    **
**                 Compare test                                               **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
 
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Mcal.h"
#include "SfrCmpTst.h"

#define IFX_SFRTST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                      Local Macro Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Local Type Definitions                                **
*******************************************************************************/

/*******************************************************************************
**                        Exported object definitions                          *
*******************************************************************************/

/*******************************************************************************
**                        Local object definitions                             *
*******************************************************************************/

/*******************************************************************************
**                        Imported function declarations                       *
*******************************************************************************/

/*******************************************************************************
**                        Local function prototypes                            *
*******************************************************************************/

static Sl_TstRsltType SfrTst_lSfrCmpTst
(
 const Sl_ParamSetType ParamSetIndex,
 uint32* const TstSignature
);

/*******************************************************************************
**                    Local inline function definitions                        *
*******************************************************************************/

/*******************************************************************************
**                    Configuration error checking                             *
*******************************************************************************/

/*******************************************************************************
**                         Function definitions                                *
*******************************************************************************/



/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax : Sl_TstRsltType SfrTst_SfrCmpTst                                   **
**          (const Sl_ParamSetType ParamSetIndex, const uint8 TstSeed,        **
**           uint32* const TstSignature)                                      **
**                                                                            **
** Description : This test checks the SFRs for unintended configuration       **
**               changes. To detect those changes the Sfr Cmp test does read  **
**               the contents of the configured registers, does apply a mask  **
**               to those values, which allows to ignore certain bits and     **
**               compares the masked values to the also configured expected   **
**               values. In case both values do not match, the test fails as  **
**               the actual configuration differs from the expected one.      **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Reentrant                                                      **
**                                                                            **
** Parameters (in) : ParamSetIndex - Identifies the parameter set to be used  **
**                                   for test execution                       **
**                   TstSeed - Seed to be used for generating the signature   **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value : SFR_CMP_SUCCESS       - Test succeeded                      **
**                SFR_CMP_INVPARAMERR   - Test failed because an invalid      **
**                                        parameter was supplied              **
**                SFR_CMP_RESGRx_REGyDM - Test failed because register given  **
**                                        by error doesn't contain the        **
**                                        expected value                      **
**                SFR_CMP_OVERLOAD      - Test did not start because there    **
**                                    are too many registers defined. This    **
**                                    test can handle 112 registers at most   **
**                                                                            **
*******************************************************************************/
Sl_TstRsltType SfrTst_SfrCmpTst
(
 const Sl_ParamSetType ParamSetIndex,
 const uint8 TstSeed,
 uint32* const TstSignature
)
{
  Sl_TstRsltType Result = SFR_CMP_NOTEXECUTED;

  /* Initialize Test Signature: */
  *TstSignature = (uint32)CRC32(TEST_ID_SFR_CMP_TST, TstSeed);

  /* Check for invalid ParamSetIndex */
  if (ParamSetIndex > (SFR_TST_CFG_PARAM_COUNT - 1U))
  {
    /*If invalid ParamSetIndex, report error*/
    Result = SFR_CMP_INVPARAMERR;
  }
  else
  {
    /* Compare actual register value against expected value */
    Result = SfrTst_lSfrCmpTst(ParamSetIndex, TstSignature);
  }
  return(Result);
}


/*******************************************************************************
** Traceability:                                                              **
**                                                                            **
** Syntax : Sl_TstRsltType SfrTst_lSfrCmpTst                                  **
**          (const Sl_ParamSetType ParamSetIndex, uint32* const TstSignature) **
**                                                                            **
**                                                                            **
** Description : This test checks the SFRs for unintended configuration       **
**               changes. To detect those changes the Sfr Cmp test does read  **
**               the contents of the configured registers, does apply a mask  **
**               to those values, which allows to ignore certain bits and     **
**               compares the masked values to the also configured expected   **
**               values. In case both values do not match, the test fails as  **
**               the actual configuration differs from the expected one.      **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy: Reentrant                                                      **
**                                                                            **
** Parameters (in) : ParamSetIndex - Identifies the parameter set to be used  **
**                                   for test execution                       **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value : SFR_CMP_SUCCESS       - Test succeeded                      **
**                SFR_CMP_RESGRx_REGyDM - Test failed because register given  **
**                                        by error doesn't contain the        **
**                                        expected value                      **
**                SFR_CMP_OVERLOAD      - Test did not start because there    **
**                                    are too many registers defined. This    **
**                                    test can handle 112 registers at most   **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SfrTst_lSfrCmpTst
(
 const Sl_ParamSetType ParamSetIndex,
 uint32* const TstSignature
)
{
  Sl_TstRsltType Result     = SFR_CMP_NOTEXECUTED;
  uint32 Mask               = 0U;
  uint32 CurrentRegValue    = 0U;
  uint32 ResultReg          = 0U;
  uint8  ShiftBy            = 0U;
  uint8  ResRegReset        = 0U;
  uint32 GroupCounter       = 0U;
  uint32 Index              = 0U;
  /*If number of registers to test is greater than maximum value of 112*/
  if (AllAvailableSets[ParamSetIndex].NumberOfRegisters2Test > REGCOUNT_MAX)
  {
    /* Report Overload error*/
    Result = SFR_CMP_OVERLOAD;
  }
  else
  {
    for(Index = 0U;
    Index < AllAvailableSets[ParamSetIndex].NumberOfRegisters2Test; Index++)
    {
          /*Obtain mask value*/
    Mask =
    AllAvailableSets[ParamSetIndex].RegisterSet2Test[Index].RegisterMask;
    /*Obtain current register value*/
    if ((AllAvailableSets[ParamSetIndex].RegisterSet2Test[Index].RegisterBitWidth) == STL_BIT_16)
    {                
    CurrentRegValue =
       *(volatile uint16 *)(AllAvailableSets[ParamSetIndex].RegisterSet2Test[Index].RegisterAddress);
    }
    else
    { 
    CurrentRegValue =
       *(volatile unsigned_int *)(AllAvailableSets[ParamSetIndex].RegisterSet2Test[Index].RegisterAddress);
	}
      CurrentRegValue = CurrentRegValue & Mask;
      /* Check if current value equals expected value */
      if( CurrentRegValue ==
      ((AllAvailableSets[ParamSetIndex].RegisterSet2Test[Index].RegisterValue)
      & Mask))
      {
        /*Store comparison pass in result register*/
        ResultReg = ResultReg | (CMP_PASS << ShiftBy);
        /*Check if the result stored is that of 7th register*/
        if(ResRegReset == 6U)
        {
          /*Calculate Test Signature*/
          *TstSignature = (uint32)CRC32(*TstSignature, ResultReg);
          ShiftBy = 0x0U;
          GroupCounter++;
          /*Increment group counter*/
          /* Overflow of ResultReg occurs when Index = 111 but no functional 
             impact as ResultReg is calculated in TstSignature before the 
             overflow happens */
          ResultReg = (GroupCounter << 28U);
          ResRegReset = 0U;
        }
        else
        {
          /*Shift value is incremented by 4 to store the next cmp result*/
          ShiftBy = ShiftBy + 4U;
          ResRegReset++;
          if((Index + 0x1U) >=
          (AllAvailableSets[ParamSetIndex].NumberOfRegisters2Test))
          {
            *TstSignature = (uint32)CRC32(*TstSignature, ResultReg);
          }
        }
      }
      else
      {
        /*Store comparison fail in result register*/
        ResultReg = ResultReg | (CMP_FAIL << ShiftBy);
        /*Error denoting register group and position is stored in Result */
        Result = (Sl_TstRsltType)
                   SFR_CMP_RESGRx_REGyDM(GroupCounter, (uint32)ResRegReset);
        /*Test Signature is calculated*/
        *TstSignature = (uint32)CRC32(*TstSignature, ResultReg);
        break;        
      }
    }
  }

  if(SFR_CMP_NOTEXECUTED == Result)
  {
    Result = SFR_CMP_SUCCESS;
  }
  *TstSignature = (uint32)CRC32(*TstSignature, Result);
  return (Result);
}


#define IFX_SFRTST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

