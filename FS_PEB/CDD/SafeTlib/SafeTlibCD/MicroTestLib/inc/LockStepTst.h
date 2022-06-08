#ifndef LOCKSTEPTST_H
#define LOCKSTEPTST_H

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
**  $FILENAME   : LockStepTst.h $                                            **
**                                                                            **
**  $CC VERSION : \main\14 $                                                 **
**                                                                            **
**  $DATE       : 2018-02-22 $                                               **
**                                                                            **
**  VARIANT      : VariantPB                                                  **
**                                                                            **
**  PLATFORM     : Infineon Aurix                                             **
**                                                                            **
**  AUTHOR       : DL-BLR-ATV-STC                                             **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : The file contains declarations, typdefs and macros to      **
**                 make code independent of various devices for LockStepTst   **
**  REFERENCE(S) :                                                            **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "ChipId.h"
#include "Mcal_TcLib.h"
#include "Mcal_WdgLib.h"
#include "Sl_Timeout.h"
#include "Sl_ErrorCodes.h"
#include "IfxScu_reg.h"

/*******************************************************************************
**                      Typedefs                                              **
*******************************************************************************/
/*  To access core specific LockStep Comparator Logic CPU Control Register    */
typedef volatile struct
{
#if ( ( CHIP_ID == 22U ) || ( CHIP_ID == 23U ) || ( CHIP_ID == 21U ) )

  /* typedef Ifx_SCU_LCLCON0 is used for single-core variants. Covers TC22x,
   * TC23x                                                                    */
  Ifx_SCU_LCLCON0 SCULCLCON;

#else

  /* typedef Ifx_SCU_LCLCON is used for multi-core variants. Covers TC26x,
   * TC27x, TC29x                                                             */
  Ifx_SCU_LCLCON SCULCLCON;

#endif

}LockStepTst_RegMapType;




/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/* Placeholder to get proper index to access the element using core id        */
#define DUMMY_PLACEHOLDER 0U

/* Note: Use corresponding proper core value if core is LockStep enabled core.
 * Use invalid core id(4U) as value if core is not available or core is not
 * LockStep enabled core.                                                     */

/* TC22x - 1 Cores - LockStep Enabled? Core0 - Yes, Core1 - NA, Core2 - NA    */
#if (( CHIP_ID == 22U ) || ( CHIP_ID == 21U ))
  #define LOCKSTEPCORE_0  0U

/* TC23x - 1 Cores - LockStep Enabled? Core0 - Yes, Core1 - NA, Core2 - NA    */
#elif ( CHIP_ID == 23U )
  #define LOCKSTEPCORE_0  0U

/* TC26x - 2 Cores - LockStep Enabled? Core0 - No, Core1 - Yes, Core2 - NA    */
#elif ( CHIP_ID == 26U )
  #define LOCKSTEPCORE_0  4U
  #define LOCKSTEPCORE_1  1U

/* TC27x - 3 Cores - LockStep Enabled? Core0 - Yes, Core1 - Yes, Core2 - No   */
#elif ( CHIP_ID == 27U )
  #define LOCKSTEPCORE_0  0U
  #define LOCKSTEPCORE_1  1U
  #define LOCKSTEPCORE_2  4U

/* TC29x - 3 Cores - LockStep Enabled? Core0 - No, Core1 - Yes, Core2 - No    */
#elif ( CHIP_ID == 29U )
  #define LOCKSTEPCORE_0  4U
  #define LOCKSTEPCORE_1  1U
  #define LOCKSTEPCORE_2  4U

#endif /* CHIP_ID & DERIVATIVE */


#if ( ( CHIP_ID == 22U ) || ( CHIP_ID == 23U ) || ( CHIP_ID == 27U ) || ( CHIP_ID == 21U ) )
  /* LCL CPU Control Register CPU0                                            */
  #define CPU0_SCU_LCLCON0 ((volatile LockStepTst_RegMapType *) (volatile void *)(&SCU_LCLCON0))
#endif /*  CPU0 LockStep */
  /* LockStep Fault inject in CPU0                                            */
  #define CPU0_LOCKSTEP_FAULT_INJ ( (uint32)0x00000001U )
  /* LockStep Fault SMU alarm CPU0                                            */
  #define CPU0_SMU_LOCKSTEP_CMP_ERROR_GRP ((uint8)SMU_ALARM_GROUP0 )



#if ( ( CHIP_ID == 26U )|| ( CHIP_ID == 27U )|| ( CHIP_ID == 29U ) )
  /* LCL CPU Control Register CPU1                                            */
  #define CPU1_SCU_LCLCON1 ((volatile LockStepTst_RegMapType *) (volatile void *)(&SCU_LCLCON1))
#endif /*  CPU1 LockStep */
  /* LockStep Fault inject in CPU1                                            */
  #define CPU1_LOCKSTEP_FAULT_INJ ((uint32)0x00000002U )
  /* LockStep Fault SMU alarm CPU1                                            */
  #define CPU1_SMU_LOCKSTEP_CMP_ERROR_GRP ((uint8)SMU_ALARM_GROUP1 )



/* There is no device yet available with core2 checker core                   */

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/
#define IFX_LOCKSTEP_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
** Traceability      : [cover parentID=]        [/cover]                      **
**                                                                            **
** Syntax           : Sl_TstRsltType LockStepTst_LockStepTst                  **
**                                      (const Sl_ParamSetType ParamSetIndex, **
**                                       const uint8 TstSeed,                 **
**                                       uint32* const TstSignature);         **
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
**                                                                            **
** Parameters (out) : TstSignature : Test signature generated by the test     **
**                                                                            **
** Return value     : LOCKSTEP_SUCCESS - Test successed                       **
**                    <Error ID> - Type of error during test                  **
**                                                                            **
** Description      : API provided for the Lockstep monitor test.             **
**                                                                            **
*******************************************************************************/
extern Sl_TstRsltType LockStepTst_LockStepTst
(
    const Sl_ParamSetType ParamSetIndex,
    const uint8 TstSeed,
    uint32* const TstSignature
);
#define IFX_LOCKSTEP_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                Global Function like macro Definitions                      **
*******************************************************************************/


#endif /* LOCKSTEPTST_H */
