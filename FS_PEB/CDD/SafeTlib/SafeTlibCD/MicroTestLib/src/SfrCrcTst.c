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
**   $FILENAME   : SfrCrcTst.c $                                              **
**                                                                            **
**   $CC VERSION : \main\17 $                                                 **
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
**  DESCRIPTION  : SfrCrc test read the contents of the configured registers, **
** apply a mask and then calculate a CRC checksum overall of them and compare **
** this checksum to an expected CRC checksum.                                 **
** This file contains the single point fault metric SFR test                  **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Mcal.h"
#include "SfrCrcTst.h"
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

static Sl_TstRsltType SfrTst_lSfrCrcTst
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
** Syntax : Sl_TstRsltType SfrTst_SfrCrcTst                                   **
** 			(const Sl_ParamSetType ParamSetIndex,const uint8 TstSeed,             **
**          uint32* const TstSignature)                                       **
**                                                                            **
**                                                                            **
** Description : This test checks the SFRs for unintended configuration       **
**               changes. To detect those changes the Sfr Crc test does read  **
**               the contents of the configured registers, does apply a mask  **
**               to those values, which allows to ignore certain bits and     **
**               then does calculate a CRC checksum over all configured       **
**               registers. If the calculated final CRC checksum does not     **
**               match the expected (configured) one, the test fails because  **
**               the actual configuration does not match with the expected    **
**               one.                                                         **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:     Reentrant                                                  **
**                                                                            **
** Parameters (in) : ParamSetIndex - Identifies the parameter set to be used  **
**                                   for test execution                       **
**                   TstSeed - Seed to be used for generating the signature   **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value : SFR_CRC_SUCCESS           - Test succeeded                  **
**                SFR_CRC_INVPARAMERR       - Test failed because an invalid  **
**                                        parameter was supplied              **
**                                        supplied                            **
**                SFR_CRC_DATAMISSMATCH - Test failed because the calculated  **
**                                        CRC checksum does not match the     **
**                                        expected one. Therefore at least    **
**                                        one monitored SFR must have been    **
**                                        changed.                            **
**                                                                            **
*******************************************************************************/
Sl_TstRsltType SfrTst_SfrCrcTst
(
 const Sl_ParamSetType ParamSetIndex,
 const uint8 TstSeed,
 uint32* const TstSignature
)
{
  Sl_TstRsltType Result = SFR_CRC_SUCCESS ;


  /* Initialize Test Signature:                                               */
  *TstSignature = (uint32)CRC32(TEST_ID_SFR_CRC_TST, TstSeed);

  /* Check for invalid ParamSetIndex                                          */
  if(ParamSetIndex > (SFR_TST_CFG_PARAM_COUNT - 1U))
  {
    /*If invalid ParamSetIndex, report error*/
    Result = SFR_CRC_INVPARAMERR;
  }
  else
  {
    /*Compare actual CRC value against expected CRC value*/
    Result = SfrTst_lSfrCrcTst(ParamSetIndex, TstSignature);
  }
  return(Result);
}



/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType SfrTst_lSfrCrcTst                                  **
**          (const Sl_ParamSetType ParamSetIndex, uint32* const TstSignature) **
**                                                                            **
** Description : This test checks the SFRs for unintended configuration       **
**               changes. To detect those changes the Sfr Crc test does read  **
**               the contents of the configured registers, does apply a mask  **
**               to those values, which allows to ignore certain bits and     **
**               then does calculate a CRC checksum over all configured       **
**               registers. If the calculated final CRC checksum does not     **
**               match the expected (configured) one, the test fails because  **
**               the actual configuration does not match with the expected    **
**               one                                                          **
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
** Return value : SFR_CRC_SUCCESS       - Test succeeded                      **
**                SFR_CRC_DATAMISSMATCH - Test failed because the calculated  **
**                                        CRC checksum does not match the     **
**                                        expected one. Therefore at least one**
**                                        monitored SFR must have been changed**
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType SfrTst_lSfrCrcTst
(
 const Sl_ParamSetType ParamSetIndex,
 uint32* const TstSignature
)
{
  Sl_TstRsltType Result          = SFR_CRC_NOTEXECUTED;
  uint32         CalculatedCRC   = 0xFFFFFFFFU;
  uint32         CurrentRegValue = 0U;
  uint32         Mask            = 0U;
  uint32         Index           = 0U;


  for(Index = 0U; Index < AllAvailableSets[ParamSetIndex].NumberOfRegisters2Test;
      Index++)
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

    /* Calculate the test signature*/
    *TstSignature = (uint32)CRC32(*TstSignature, CurrentRegValue);
    /* Calculate the CRC*/
    CalculatedCRC = (uint32)CRC32(CalculatedCRC, CurrentRegValue);
  }

  /* If the calculated CRC doesn't match the expected CRC */
  if (AllAvailableSets[ParamSetIndex].ExpectedCRCResult != CalculatedCRC)
  {
    /* Report CRC mismatch */
    Result = SFR_CRC_DATAMISSMATCH;
  }
  else
  {
    Result = SFR_CRC_SUCCESS;
  }
  *TstSignature = (uint32)CRC32(*TstSignature, Result);
  return (Result);
}


#define IFX_SFRTST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

