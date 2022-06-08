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
**  $FILENAME   : IRTst.c $                                                  **
**                                                                            **
**  $CC VERSION : \main\55 $                                                 **
**                                                                            **
**  $DATE       : 2018-02-22 $                                               **
**                                                                            **
**  VARIANT     : VariantPB                                                   **
**                                                                            **
**  PLATFORM    : Infineon AURIX                                              **
**                                                                            **
**  COMPILER    : Tasking                                                     **
**                                                                            **
**  AUTHOR      : SafeTlib Team                                               **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  TRACEABILITY:                                                             **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - MTL functionality for Interrupt Router Test              **
**                                                                            **
**  REFERENCE(S) : Aurix_SafeTlib_DS_IRTest                                   **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "ChipId.h"
#include "IfxSrc_bf.h"
#include "IfxCpu_bf.h"
#include "IfxInt_bf.h"
#include "IfxSmu_bf.h"
#include "IfxCpu_reg.h"
#include "IfxSrc_reg.h"
#include "IfxSmu_reg.h"
#include "IfxInt_reg.h"
#include "Smu.h"
#include "SmuInt.h"
#include "Sl_Ipc.h"
#include "IRTst.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

#define IRTST_ZERO (0x00U)
#define IRTST_ONE (0x01U)

/* Invalid code id                                                            */
#define IRTST_INV_CORE_ID (0x04U)

/* Placeholder to get proper index to access the element using core id        */
#define DUMMY_PLACEHOLDER 0U

/* Service request is enabled                                                 */
#define IRTST_SRC_ENABLE_SRE ((uint32)(((uint32)IFX_SRC_SRCR_SRE_MSK) << \
                                                ((uint32)IFX_SRC_SRCR_SRE_OFF)))

/* Set request set bit                                                        */
#define IRTST_SRC_SET_SETR ((uint16)((((uint32)IFX_SRC_SRCR_SETR_MSK) << \
                                ((uint32)IFX_SRC_SRCR_SETR_OFF)) >> (uint32)16))

/* SMU AG2[25] IR EDC alarm mask                                              */
#define IRTST_SMU_IR_EDC_ALARM (((uint32)IFX_SMU_AG_SF25_MSK) << \
                                                  ((uint32)IFX_SMU_AG_SF25_OFF))

/* IR EDC SMU alarm                                                           */
#define IRTST_SMU_ALARM_ID (SMU_ALARM_25)

/* Use of definitions from _bf results in violation: Overflow in computing
 * constant for operation: 'shift left' [MISRA 2004 Rule 12.11, advisory]
*/
/* Clear error status in Error Control Register                               */
#define IRTST_CLR_ECR_STAT ( 0x80000000U )

/*  SRC ECC mask                                                              */
#define IRTST_SRC_ECC_MASK   ( (uint16)IFX_SRC_SRCR_ECC_MSK )

/*  SRC Reserved bit mask                                                     */
#define IRTST_SRC_RES_MASK_16BIT   ( (uint16)0x7FFFU )
#define IRTST_SRC_RES_MASK_32BIT   ( (uint32)0x7FFFFFFFU )

/* set SRC.SWSCLR bit                                                         */
#define IRTST_SET_SRC_SWSCLR_BIT   ( (uint32)0x40000000U )

/* Set DMA as the Type of Service Control                                     */
#define IRTST_DMA_TOS (3U)
#define IRTST_SET_DMA_TOS ((uint8)(((uint8)IRTST_DMA_TOS) & \
                                                 ((uint8)IFX_SRC_SRCR_TOS_MSK)))

/* DMA selected in the IR configuration to use as service provider            */
#define IRTST_DMA_CONFIG_ENABLED ((uint32)1U)

/* SMU alarm timeout. The value was chosen based on following considerations:
 * The worst case number of SMU cycles before an alarm gets visible is
 * n * 2 + 20 (with n = max. number of simultaneous alarms). With a maximum
 * of 32 * 7 alarms and maximum clock ratio fSPB/fSRI = 1/4 this evaluates to
 * 1872 CPU clock cycles. To avoid the counting the number of instructions per
 * loop cycle, it is assumed that only one instruction is executed per loop
 * cycle and thus the number of CPU clock cycles is directly used as timeout
 * value:
 */
#define IRTST_SMU_ALARM_TIMEOUT ((uint32)2000U)

/* Invalid service provider value                                             */
#define IRTST_INVALID_SRC_TOS (0x04U)

/* LASR PN ID Mask                                                            */
#define IRTST_ICU_LASR_ID_PN_MSK  ( \
       (((uint32)IFX_INT_ICU_LASR_ID_MSK << (uint32)IFX_INT_ICU_LASR_ID_OFF) | \
        ((uint32)IFX_INT_ICU_LASR_PN_MSK << (uint32)IFX_INT_ICU_LASR_PN_OFF)) )

/* Error Capture Register (ECR)*/

#define IRTST_CPU0_INT_ICU_ECR (&INT_ECR0)

#if ( MCAL_NO_OF_CORES > 1U )
#define IRTST_CPU1_INT_ICU_ECR (&INT_ECR1)
#endif

#if ( MCAL_NO_OF_CORES > 2U )
#define IRTST_CPU2_INT_ICU_ECR (&INT_ECR2)
#endif

#if ( ( CHIP_ID == 26U ) || ( CHIP_ID == 27U ) || ( CHIP_ID == 29U ))
#define IRTST_DMA_INT_ICU_ECR  (&INT_ECR3)
#else
#define IRTST_DMA_INT_ICU_ECR  (&INT_ECR1)
#endif /*  CPU */

/* Last Acknowledged Service Request Register (LASR)                          */
#define IRTST_CPU0_INT_LASR (&INT_LASR0)

#if ( MCAL_NO_OF_CORES > 1U )
#define IRTST_CPU1_INT_LASR (&INT_LASR1)
#endif

#if ( MCAL_NO_OF_CORES > 2U )
#define IRTST_CPU2_INT_LASR (&INT_LASR2)
#endif

#if ( ( CHIP_ID == 26U ) || ( CHIP_ID == 27U ) || ( CHIP_ID == 29U ))
#define IRTST_DMA_INT_LASR  (&INT_LASR3)
#else
#define IRTST_DMA_INT_LASR  (&INT_LASR1)
#endif /*  CPU */

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/



/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
#define IFX_IRTST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static void IRTst_lInit
(
  uint32* const IRTst_lBivBackup, uint32* const IRTst_lIcrBackup
);

static void IRTst_lRestore
(
    const uint32 IRTst_lBivBackup, const uint32 IRTst_lIcrBackup
);

static Sl_TstRsltType IRTst_lExecuteTest
(
  uint32* const TstSignature,
  const uint8 ServiceRequestPriority,
  const uint32 TypeOfService
);

static Sl_TstRsltType IRTst_lExecuteFaultInjTest
(
  uint32* const TstSignature,
	const uint32 TypeOfService,
	const uint8 ServiceRequestPriority
);


/*******************************************************************************
**                       Private Function Definitions                         **
*******************************************************************************/



/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static void IRTst_lInit                                 **
**                    (                                                       **
**                      uint32* const IRTst_lBivBackup,                       **
**                      uint32* const IRTst_lIcrBackup                        **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : IRTst_lBivBackup: BIV backup value                      **
**                    IRTst_lIcrBackup: ICR backup value                      **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function creates a backup of current BIV, ICR and  **
**                    switches the BIV to a interrupt vector table dedicated  **
**                    to the IR test.                                         **
*******************************************************************************/

static void IRTst_lInit
(
  uint32* const IRTst_lBivBackup, uint32* const IRTst_lIcrBackup
)
{
  uint32 CpuBivVal = IRTST_ZERO;

  /* Backup BIV                                                               */
  *IRTst_lBivBackup = (uint32)MFCR(CPU_BIV);

  /* Backup ICR                                                               */
  *IRTst_lIcrBackup = (uint32)MFCR(CPU_ICR);

  /* Disable the write-protection for registers                               */
  Mcal_ResetENDINIT();

  /* Switch BIV to dedicated IR test BIV                                      */
  CpuBivVal = ((uint32)((uint32)&IRTst_inttab) |(uint32)(IFX_CPU_BIV_VSS_MSK));
  MTCR(CPU_BIV, CpuBivVal);

  /* Enable the write-protection for registers                                */
  Mcal_SetENDINIT();

  /* Enable Global Interrupt Flag irrespective of it's current state          */
  ENABLE();
}

/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : void IRTst_lRestore                                     **
**                    (                                                       **
**                      const uint32 IRTst_lBivBackup,                        **
**                      const uint32 IRTst_lIcrBackup                         **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters(in)   : IRTst_lBivBackup: BIV backup value                      **
**                    IRTst_lIcrBackup: ICR backup value                      **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function restores the ICR and interrupt vector     **
**                    table to what it has been before the IR test was called.**
*******************************************************************************/

static void IRTst_lRestore
(
    const uint32 IRTst_lBivBackup, const uint32 IRTst_lIcrBackup
)
{
  /* Restore original BIV                                                   */
  Mcal_ResetENDINIT();
  MTCR(CPU_BIV, IRTst_lBivBackup);
  Mcal_SetENDINIT();

  /* Restore original ICR                                                   */
  MTCR(CPU_ICR, IRTst_lIcrBackup);
}


/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType IRTst_lExecuteTest                **
**                    (                                                       **
**                      uint32* const TstSignature,                           **
**                      const uint8 ServiceRequestPriority,                   **
**                      const uint32 TypeOfService                            **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters(in)   : ServiceRequestPriority: Service Request Priority Number **
**                    TypeOfService: Service provider selection               **
**                                                                            **
** Parameters (out) : TstSignature : Test signature generated by the test     **
**                                                                            **
** Return value     : IRTST_SUCCESS - Test succeeded                          **
**                    IRTST_SMU_GETALMSTSERR - The test failed because        **
**                    getting the alarm status failed                         **
**                    IRTST_SMU_ALMSTSERR - The test failed because there is  **
**                    already an SMU alarm present.                           **
**                    IRTST_SMU_GETALMACTIONERR - The test failed because     **
**                    getting an SMU alarm action failed.                     **
**                    IRTST_SMU_SETALMACTIONERR - The test failed because     **
**                    setting an SMU alarm action failed.                     **
**                    IRTST_NOTEXECUTED - This error should never be returned.**
**                    If it is returned anyhow, this indicates a severe       **
**                    malfunction of program execution.                       **
**                                                                            **
** Description      : This function calls functions which perform IR EDC      **
**                    mechanism test with and without fault injection         **
**                    respectively.                                           **
**                    Function starts with check IR EDC alarm. If alarm       **
**                    already set error is reported. SMU alarms action is set **
**                    to none by backup of the existing action which is used  **
**                    for the test. Backup of SRC register used for the test  **
**                    is taken to restore during end of the test.             **
**                    Finally calls functions which perform IR EDC mechanism  **
**                    test by configuring SRN with SRPN, TOS and SRE          **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType IRTst_lExecuteTest
(
  uint32* const TstSignature,
  const uint8 ServiceRequestPriority,
  const uint32 TypeOfService
)
{
  Sl_TstRsltType Result = IRTST_NOTEXECUTED;
  uint32 AlarmStatus = IRTST_ZERO;
  Smu_AlarmActionType SmuAlmActBak_Ag2Alm25;
  uint32 SrcRegisterBackup = IRTST_ZERO;
  uint32 SetSrcTosSrpn = IRTST_ZERO;
  uint32 SetSrcSre = IRTST_ZERO;

  /* Fsp action will not be overwritten and hence doesn't need to be saved    */
  Smu_FSPActionType FspDummy = IRTST_ZERO;

  /* SRC_CPU0SBSRC Service Request Control registers are used for testing     */

  /* Check IR EDC  alarm already set                              */
  if( E_OK != (Smu_GetAlarmStatus(SMU_ALARM_GROUP2, &AlarmStatus)) )
  {/* Status check call failed report error                                   */
    Result = IRTST_SMU_GETALMSTSERR;
  }
  else
  { /* Check for SMU alarm AG2[25]                                            */
    if( (AlarmStatus & IRTST_SMU_IR_EDC_ALARM) == IRTST_SMU_IR_EDC_ALARM )
    {/* The test failed because there is already an SMU alarm present.        */
      Result = IRTST_SMU_ALMSTSERR;
    }
    else
    {
      /* Back up of SMU alarms action which is used for IRTst AG2[25]         */
      if( E_OK != (Smu_GetAlarmAction( SMU_ALARM_GROUP2, SMU_ALARM_25,
                             &SmuAlmActBak_Ag2Alm25,
                             &FspDummy
                                     )
                  )
        )
      {/* getting SMU alarm action failed                                     */
          Result = IRTST_SMU_GETALMACTIONERR;
      }
      else
      {/* Set the SMU alarm action to none                                    */
        if( E_OK != (Smu_SetAlarmAction(SMU_ALARM_GROUP2, SMU_ALARM_25,
        SMU_ALARM_ACTION_NONE)))
        {/* Setting SMU alarm action to none failed                           */
          Result = IRTST_SMU_SETALMACTIONERR;
        }
        else
        {
          /* Backup the of Src register                         */
          SrcRegisterBackup = (uint32)(SRC_CPU0SBSRC.U & 
                                          IRTST_SRC_RES_MASK_32BIT);
          /* Taking current TOS and SRPN                                      */
          SetSrcTosSrpn = (uint32)( (uint32)(TypeOfService <<
                        IFX_SRC_SRCR_TOS_OFF) | (uint32)ServiceRequestPriority);

          /* Enable SRE in SRC                                                */
          SetSrcSre = (uint32)( SetSrcTosSrpn | IRTST_SRC_ENABLE_SRE);

          /* Configure IR Interrupts with TOS SRPN, Enable interrupt request  */
          SRC_CPU0SBSRC.U =  SetSrcSre;

          /* Test execution with fault injection                              */
          Result = IRTst_lExecuteFaultInjTest( TstSignature, TypeOfService,
          		                                        ServiceRequestPriority);

          /* Restore SMU alarm action with backup                           */
          if( E_OK != (Smu_SetAlarmAction(SMU_ALARM_GROUP2, SMU_ALARM_25,
                                                    SmuAlmActBak_Ag2Alm25)))
          { /* Restoration of SMU alarm action failed                       */
            if(Result == IRTST_SUCCESS)
            {/* Update result to IRTST_SMU_SETALMACTIONERR if
                IRTst_lExecuteFaultInjTest returned IRTST_SUCCESS           */
              Result = IRTST_SMU_SETALMACTIONERR;
            }
          }

          /* Restore SRC register                                             */
          SRC_CPU0SBSRC.U = SrcRegisterBackup;
        }
      }
    }
  }

  return Result;
}


/*******************************************************************************
** Traceability     : [cover parentID=]          [/cover]                     **
**                                                                            **
** Syntax           : static Sl_TstRsltType IRTst_lExecuteFaultInjTest        **
**                    (                                                       **
**                      uint32* const TstSignature,                           **
**                      const uint32 TypeOfService,                           **
**                      const uint8 ServiceRequestPriority                    **
**                    )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : TypeOfService: Interrupt service provider               **
**                                                                            **
** Parameters (out) : TstSignature : Test signature generated by the test     **
**                                                                            **
** Return value     : IRTST_SUCCESS - Test succeeded                          **
**                    IRTST_SMU_GETALMSTSERR - The test failed because        **
**                    getting the alarm status failed                         **
**                    IRTST_SMU_CLRALMSTSERR - Test failed because clearing   **
**                    SMU alarm failed                                        **
**                    IRTST_ERROR_ICU - Test failed because of an error in    **
**                    interrupt processing                                    **
**                    IRTST_NO_SMUALRM - Test failed because integrity error  **
**                    not singled to SMU                                      **
**                    IRTST_NOTEXECUTED - This error should never be returned.**
**                    If it is returned anyhow, this indicates a severe       **
**                    malfunction of program execution                        **
**                                                                            **
** Description      : The backup of ECC calculated by the hardware is taken   **
**                    to restore the original ECC during the test. Test is    **
**                    performed on the statically selected SRN, SRPN          **
**                    considering service provider CPU.                       **
**                    Fault inject test done by toggling all bits of the ECC  **
**                    field of the SRN. Software interrupts is generated with **
**                    fault injection of ECC and SMU IR EDC alarm is checked. **
**                    For interrupt generated with fault, ECC Integrity error **
**                    should be signaled and SMU IR EDC alarm should be       **
**                    raised. To complete test on SRN interrupt, SMU alarm,   **
**                    error status are cleared and backed up ECC is restored. **
**                    It is checked that the interrupt priority number and    **
**                    SRN ID match the one used to trigger the interrupt,     **
**                    otherwise an error is reported. Interrupt sticky bit    **
**                    is cleared if interrupt initiation is from Request      **
**                    Set Bit.                                                **
**                    SMU alarm is checked for every interrupt. If SMU alarm  **
**                    is not detected for interrupt with fault injection,     **
**                    the faulty condition is reported.                       **
**                                                                            **
*******************************************************************************/
static Sl_TstRsltType IRTst_lExecuteFaultInjTest
(
  uint32* const TstSignature,
  const uint32 TypeOfService,
  const uint8 ServiceRequestPriority
)
{
  Sl_TstRsltType Result = IRTST_NOTEXECUTED;
  uint16 CorruptEcc = (uint16)IRTST_ZERO;
  uint32 AlarmStatus = IRTST_ZERO;
  uint32 Timeout = IRTST_SMU_ALARM_TIMEOUT;
  uint32 SrcPnId = IRTST_ZERO;
  uint32 LasrPnId = IRTST_ZERO;
  volatile uint16* const SrcCpu0Sbsrc = (volatile uint16*)(volatile void*)
  		                            (&SRC_CPU0SBSRC.U);
  uint32 Read_SrcValue = IRTST_ZERO;

  /* Core specific Error Capture Register (ECR)                               */
  volatile Ifx_INT_ICU_ECR* IRTst_INT_ICU_ECRGrp[] =
  {

    IRTST_CPU0_INT_ICU_ECR,

#if ( MCAL_NO_OF_CORES > 1U )
    IRTST_CPU1_INT_ICU_ECR,
#else
    /* for device 21x, 22x, 23x and 24x                                       */
    IRTST_DMA_INT_ICU_ECR,
#endif /*  CPU */

#if ( MCAL_NO_OF_CORES > 2U )
    IRTST_CPU2_INT_ICU_ECR,
#else
  /* Placeholder to get proper index to access the element using core id      */
    (volatile Ifx_INT_ICU_ECR*)DUMMY_PLACEHOLDER,
#endif /*  CPU  */

    IRTST_DMA_INT_ICU_ECR
  };

  /* Core specific Last Acknowledged Service Request Register (LASR)          */
  volatile Ifx_INT_ICU_LASR* IRTst_INT_LASRGrp[] =
  {
    IRTST_CPU0_INT_LASR,

#if ( MCAL_NO_OF_CORES > 1U )
    IRTST_CPU1_INT_LASR,
#else
    /* for device 21x, 22x, 23x and 24x                                       */
    IRTST_DMA_INT_LASR,
#endif /*  CPU  */

#if ( MCAL_NO_OF_CORES > 2U )
    IRTST_CPU2_INT_LASR,
#else
  /* Placeholder to get proper index to access the element using core id      */
    (volatile Ifx_INT_ICU_LASR*)DUMMY_PLACEHOLDER,
#endif /*  CPU  */

    IRTST_DMA_INT_LASR
  };

  /* Corrupt calculated ECC by toggling all bits.                             */
  CorruptEcc = (SrcCpu0Sbsrc[1] ^ IRTST_SRC_ECC_MASK);

  /* The SRC.ECC bit field will be updated under the following conditions:
   * • write or Read-Modify-Write to SRC[31:0]
   * • write to SRC[15:0] (16-bit write)
   * • write to SRC[15:8] or write to SRC[7:0] (byte write)
   * In case of a 32 bit write to SRC, the ECC bit field will be updated with
   * the calculated ECC, the data written to ECC bit field will be ignored.   */

  /* Corrupt the ECC                                                          */
  SrcCpu0Sbsrc[1] = (uint16)(CorruptEcc & IRTST_SRC_RES_MASK_16BIT);

  /* Trigger software Interrupt                                               */
  SrcCpu0Sbsrc[1] = (uint16)((SrcCpu0Sbsrc[1] & IRTST_SRC_RES_MASK_16BIT) | 
                                                   IRTST_SRC_SET_SETR);

  /* Check IR EDC SMU alarm by Waiting for the requested SMU alarm to become
   * signaled.                                                                */
  while ((Timeout > IRTST_ZERO) &&
  		                   (IRTST_ZERO == (AlarmStatus & IRTST_SMU_IR_EDC_ALARM)))
  {
    Timeout--;

    /* Get IR EDC SMU alarm status.                      */
    if (E_OK != Smu_GetAlarmStatus(SMU_ALARM_GROUP2, &AlarmStatus))
    {/* Status check call failed reset alarm status, timeout and report error */
      AlarmStatus = IRTST_ZERO;
      Timeout = IRTST_ZERO;
      Result = IRTST_SMU_GETALMSTSERR;
    }
  }

  /* Update signature with IR EDC alarm status                                */
  *TstSignature = (uint32)CRC32(*TstSignature,
                                (AlarmStatus & IRTST_SMU_IR_EDC_ALARM));

  if( Result == IRTST_NOTEXECUTED )
  {
    /* Check IR EDC SMU alarm                                                 */
    if( (AlarmStatus & IRTST_SMU_IR_EDC_ALARM) == IRTST_SMU_IR_EDC_ALARM )
    {
      /* Clear Alarm Status                                                   */
      if(E_OK != (Smu_ClearAlarmStatus(SMU_ALARM_GROUP2,
                                                           IRTST_SMU_ALARM_ID)))
      {
        Result = IRTST_SMU_CLRALMSTSERR;
      }
      else
      {
        /* Check of interrupt PN and ID match the one used to trigger the
         * interrupt                                                          */
      	SrcPnId = ((uint32)IRTST_ZERO << (uint32)IFX_INT_ICU_LASR_ID_OFF) |
      			      ((uint32)ServiceRequestPriority <<
      			      		(uint32)IFX_INT_ICU_LASR_PN_OFF);
        LasrPnId = IRTst_INT_LASRGrp[TypeOfService]->U &
        		                                       IRTST_ICU_LASR_ID_PN_MSK;

        if(SrcPnId == LasrPnId)
        {
          /* Check for interrupt due to request set bit SETR                  */
          if(SRC_CPU0SBSRC.B.SWS == IRTST_ONE)
          {
            /* Clear SW sticky bit (ensuring bit 32 is 0 while writing)       */
            Read_SrcValue = (uint32)((SRC_CPU0SBSRC.U 
                      & IRTST_SRC_RES_MASK_32BIT) | IRTST_SET_SRC_SWSCLR_BIT);
            SRC_CPU0SBSRC.U = Read_SrcValue;

            /* Fault injection test execution successful                      */
            Result =  IRTST_SUCCESS;
          }
          else
          {/* Test failed due to error in interrupt processing.               */
          	Result = IRTST_ERROR_ICU;
          }
        }
        else
        {/* Test failed due to error in interrupt processing.                 */
          Result = IRTST_ERROR_ICU;
        }
        /* clear error status                                                 */
        IRTst_INT_ICU_ECRGrp[TypeOfService]->U = IRTST_CLR_ECR_STAT;
      }
    }
    else
    {/* Detection of faulty condition in IR ECC mechanism unsuccessful        */
      Result =  IRTST_NO_SMUALRM;
    }
  }

  /* Update Test Signature with result                                        */
  *TstSignature = (uint32)CRC32(*TstSignature, Result);

  return Result;
}

/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : Sl_TstRsltType IRTst_IRTst                              **
**                    (                                                       **
**                      const Sl_ParamSetType ParamSetIndex,                  **
**                      const uint8 TstSeed,                                  **
**                      uint32* const TstSignature                            **
                      )                                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters(in)   : ParamSetIndex : Identifies the parameter set to be      **
**                                    used for test execution                 **
**                    TstSeed : Seed to be used for generating the signature  **
**                                                                            **
** Parameters (out) : TstSignature : Test signature generated by the test     **
**                                                                            **
** Return value     : IRTST_SUCCESS - Test succeeded                          **
**                    IRTST_NOTEXECUTED - This error should never be returned.**
**                    If it is returned anyhow, this indicates a severe       **
**                    malfunction of program execution.                       **
**                    IRTST_INVPARAM - Test failed because an invalid         **
**                    parameter was supplied.                                 **
**                    IRTST_SMU_CLRALMSTSERR - Clear SMU alarm status failed. **
**                    IRTST_SMU_GETALMSTSERR - The test failed because getting**
**                    the alarm status failed                                 **
**                    IRTST_SMU_GETALMACTIONERR - The test failed because     **
**                    getting an SMU alarm action failed.                     **
**                    IRTST_SMU_SETALMACTIONERR - The test failed because     **
**                    setting an SMU alarm action failed.                     **
**                    IRTST_SMU_ALMSTSERR - The test failed because there is  **
**                    already an SMU alarm present.                           **
**                    IRTST_SMU_STATEERR - The test failed because SMU is     **
**                    not in run state.                                       **
**                    IRTST_NO_SMUALRM - Test failed because a integrity error**
**                    not singled to SMU.                                     **
**                    IRTST_ERROR_ICU - Test failed due to error in interrupt **
**                    processing.                                             **
**                                                                            **
** Description      : IRTst_IRTest is the only API provided by the test. It   **
**                    calls the test initialization function for setting up a **
**                    dedicated BIV, then triggers interrupts with and without**
**                    fault of ECC field to test ECC checker mechanism.       **
**                    Finally restores the BIV by calling the test restoration**
**                    function.                                               **
*******************************************************************************/
Sl_TstRsltType IRTst_IRTst( const Sl_ParamSetType ParamSetIndex,
                               const uint8 TstSeed,
                               uint32* const TstSignature )

{
  Sl_TstRsltType Result = IRTST_NOTEXECUTED;
  uint32 IRTst_lBivBackup = IRTST_ZERO;
  uint32 IRTst_lIcrBackup = IRTST_ZERO;
  uint8 CoreId = (uint8)IRTST_INV_CORE_ID;

  /* Initialize with service request priority number                          */
  uint8 ServiceRequestPriority = (uint8)IRTST_ONE;

  /* Initialize with invalid service provider value                           */
  uint32 TypeOfService = IRTST_INVALID_SRC_TOS;

  /* Read the core Id                                                         */
  CoreId = Mcal_GetCoreId();

  /* Initialize Test Signature with test id and test seed                     */
  *TstSignature = (uint32)CRC32((uint32)TEST_ID_IR_TST, (uint32)TstSeed);

    /* Validate the configuration parameter                                   */
  if(ParamSetIndex > (IRTST_CFG_PARAM_COUNT-IRTST_ONE))
  {
    Result = IRTST_INVPARAM;
  }
  else /* Valid configuration parameter                                      */
  {
    /* Check if the SMU is in RUN state. Otherwise report failure            */
    if (SMU_RUN_STATE == Smu_GetSmuState())
    {
      /* Test initialization                                                 */
      IRTst_lInit(&IRTst_lBivBackup, &IRTst_lIcrBackup);

      /* Set service provider to core ID                                     */
      TypeOfService = (uint32)(CoreId);

      /* Test execution with CPUx as TOS                                     */
      Result = IRTst_lExecuteTest( TstSignature,
                      ServiceRequestPriority, TypeOfService );

      /* Check and test execution with DMA as TOS                            */
      if(IRTst_ConfigRoot[ParamSetIndex].DmaSelect ==
                               IRTST_DMA_CONFIG_ENABLED)
      {/* Check test execution with CPUx as TOS successful                   */
        if(IRTST_SUCCESS == Result)
        {
          /* Set Type of Service DMA                                         */
          TypeOfService = (uint32)IRTST_SET_DMA_TOS;

          /* DMA Channel Number is the SRPN */
          ServiceRequestPriority =
                  (uint8)IRTst_ConfigRoot[ParamSetIndex].DmaChannel;

          /* Execute test on ECC mechanism                                */
          Result = IRTst_lExecuteTest( TstSignature,
                      ServiceRequestPriority, TypeOfService );
        }
      }

      /* Restores the ICR and interrupt vector table                      */
      IRTst_lRestore(IRTst_lBivBackup, IRTst_lIcrBackup);
    }
    else
    {/* SMU is not in RUN state.                                          */
      Result = IRTST_SMU_STATEERR;
    }
  }

  /* Update test signature with result                                   */
  *TstSignature = (uint32)CRC32(*TstSignature, Result);

  return Result;
}


#define IFX_IRTST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
