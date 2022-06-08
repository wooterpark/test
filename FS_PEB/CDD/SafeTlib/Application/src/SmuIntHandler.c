/*******************************************************************************
** Copyright (C) Infineon Technologies (2015)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**  $FILENAME   : SmuIntHandler.c $                                          **
**                                                                            **
**  $CC VERSION : \main\19 $                                                 **
**                                                                            **
**  $DATE       : 2016-04-07 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  COMPILER  : Tasking                                                       **
**                                                                            **
**  AUTHOR    : SafeTlib Team                                                 **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY:                                                             **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - functionality of SMU interrupt handling:                 **
**                      -> Configuring Type Of Service                        **
**                      -> Enabling SRE bit of respective SMU interrupt handlers
**                      -> Configuring interrupt priority                     **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: Yes                                      **
**                                                                            **
*******************************************************************************/

/******************************************************************************
**                      Includes                                              *
******************************************************************************/
#include "Std_Types.h"
#include "SmuIntHandler.h"
#include "Smu.h"
#include "IfxSmu_reg.h"
#include "IfxSrc_reg.h"
#include "Irq.h"
#include "Mcal_Compiler.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define SMU_INT0_PRIORITY 0xa
#define SMU_INT1_PRIORITY 0xb
#define SMU_INT2_PRIORITY 0xc
#define SMU_ENABLE_SRE    ((uint32)(0x400U))
#define SMU_TOS_CPU0      ((uint32)(0U))

#define SMU_INT_CLEAR     (1U)

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/


/*******************************************************************************
                      Global Variable Definitions                           **
*******************************************************************************/
#define IFX_APPL_START_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"

volatile uint32 SmuInt0Service;
volatile uint32 SmuInt1Service;
volatile uint32 SmuInt2Service;

#define IFX_APPL_STOP_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"


/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/



#define IFX_APPL_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#if 0
IFX_INTERRUPT(SMU_INT0_ISR, 0, SMU_INT0_PRIORITY)
{
    SRC_SMU0.B.CLRR = SMU_INT_CLEAR;
    SmuInt0Service = SMU_INT_SERVICE_TRUE;
}

IFX_INTERRUPT(SMU_INT1_ISR, 0, SMU_INT1_PRIORITY)
{
    ENABLE();
    SRC_SMU1.B.CLRR = SMU_INT_CLEAR;
    SmuInt1Service = SMU_INT_SERVICE_TRUE;
}

IFX_INTERRUPT(SMU_INT2_ISR, 0, SMU_INT2_PRIORITY)
{
    ENABLE();
    SRC_SMU1.B.CLRR = SMU_INT_CLEAR;
    SmuInt1Service = SMU_INT_SERVICE_TRUE;
}
#endif
/*******************************************************************************
** Traceability     : [cover parentID=]        [/cover]                       **
**                                                                            **
** Syntax           : void SMU_Setupinterrupt(void)                              **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters(in)   :  None                                                   **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      :   -> Configuring Type Of Service                        **
**                      -> Enabling SRE bit of respective SMU interrupt handlers
**                      -> Configuring interrupt priority                     **
**                                                                            **
*******************************************************************************/

void SMU_Setupinterrupt(void)
{
  SmuInt0Service = SMU_INT_SERVICE_FALSE;
  SmuInt1Service = SMU_INT_SERVICE_FALSE;
  SmuInt2Service = SMU_INT_SERVICE_FALSE;

  SRC_SMU0.U = (uint32)(SMU_TOS_CPU0 | SMU_ENABLE_SRE | SMU_INT0_PRIORITY);
  SRC_SMU1.U = (uint32)(SMU_TOS_CPU0 | SMU_ENABLE_SRE | SMU_INT1_PRIORITY);
  SRC_SMU2.U = (uint32)(SMU_TOS_CPU0 | SMU_ENABLE_SRE | SMU_INT2_PRIORITY);

  Irq_InstallInterruptHandler (SMU_INT0_PRIORITY, (uint32) &SMU_INT0_ISR);
  Irq_InstallInterruptHandler (SMU_INT1_PRIORITY, (uint32) &SMU_INT1_ISR);
  Irq_InstallInterruptHandler (SMU_INT2_PRIORITY, (uint32) &SMU_INT2_ISR);

} /* SMU_Setupinterrupt */

#define IFX_APPL_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
