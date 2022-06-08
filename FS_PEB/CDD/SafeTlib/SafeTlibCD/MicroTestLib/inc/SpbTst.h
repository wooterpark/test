#ifndef SPBTST_H
#define SPBTST_H
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
**   $FILENAME   : SpbTst.h $                                                 **
**                                                                            **
**   $CC VERSION : \main\15 $                                                 **
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
**  DESCRIPTION  : This file provides latent fault metric test routines for   **
**                 the SPB Peripheral Register Access Protection and Timeout. **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Platform_Types.h"
#include "Sl_Timeout.h"
#include "Sl_ErrorCodes.h"
#include "SmuInt.h"
#include "SpbTst_Cfg.h"
#include "Mcal.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Typedefs                                              **
*******************************************************************************/
typedef volatile unsigned_int *SpbTst_AccEnType[4];


/* Type defintion for SpbTst Configuration */
typedef struct SpbTst_ConfigType
{
   const SpbTst_AccEnType  * SpbPeripheralCfgPtr;
   uint8 SpbCount;
   const uint32 *SmuAlarm;
}SpbTst_ConfigType;


/* Storage for backup of the SPB Bus error alarm action.
 * Backup of <Peripheral>_CLC, <Peripheral>_ACCEN0, <Peripheral>_ACCEN0, 
 * CPUx_PSW and BTV backup
 */
typedef struct SpbRegAccProtTst_BackupDataType
{
  /*Storage for backup of the SMU SRI error alarm action*/
  Smu_AlarmActionType AlmActionBUSriBusError;
  /*Storage for backup of the SMU SPB error alarm action*/
  Smu_AlarmActionType AlmActionBUSpbBusError;
  /*Storage for backup of the SMU SPB RegAccProt error alarm action*/  
  Smu_AlarmActionType AlmActionBUSpbAccProtEnbError;   
  uint32 PeripheralClcBU;     
  uint32 PeripheralAccen0BU;
  uint32 PeripheralKernelBU;
  uint32 PswBU;
}SpbRegAccProtTst_BackupDataType;

/* Storage for backup of the SPB Bus error alarm action.
 * Backup of CAN_CLC, SBCU_CON, SBCU_ECON, SBCU_EADD and SBCU_EDAT backup
 */

typedef struct SpbTimeoutTst_BackupDataType
{
  /*Storage for backup of the SMU SPB error alarm action*/
  Smu_AlarmActionType AlmActionBUSpbBusError;

  uint32 MtuClcBU; 
  uint32 SbcuEconBU;
  uint32 SbcuEaddBU;
  uint32 SbcuEdatBU;
  uint32 PswBU;  
}SpbTimeoutTst_BackupDataType;
#define IFX_SPBTST_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
extern const SpbTst_ConfigType SpbTst_ConfigRoot[SPB_TST_CFG_PARAM_COUNT];
#define IFX_SPBTST_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/
#define IFX_SPBTST_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType SpbTst_PeripheralRegAccProtTst                  **
**          (                                                                 **
**             const  Sl_ParamSetIndex ParamSetIndex,                         **
**             const  uint8 TstSeed,                                          **
**             uint32* const TstSignature                                     **
**          )                                                                 **
**                                                                            **
** Description : This test checks that the register protection scheme does    **
**               work as expected. To verify this, the following actions are  **
**               being executed:                                              **
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
**                                                                            **
**                   TstSeed - Seed to be used for generating the signature   **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value : SPBREGACC_SUCCESS     - Test succeeded                      **
**                                                                            **
**                SPBREGACC_NOTEXECUTED - The test has not been executed or   **
**                at least was interrupted before a valid result could be     **
**                generated                                                   **
**                                                                            **
**                SPBREGACC_INVPARAMERR - Test failed because an invalid.     **
**                                                                            **
**                SPBREGACC_SMU_STATEERR - The test cannot be executed        **
**                because the SMU is in the wrong state                       **
**                                                                            **
**                SPBREGACC_SMU_GETALMSTSERR - Test failed because getting    **
**                the SMU alarm status failed                                 **
**                                                                            **
**                SPBREGACC_SMU_CLRALMSTSERR - The test failed because        **
**                clearing the SMU alarm failed.                              **
**                                                                            **
**                SPBREGACC_ SMU_ALMSTSERR - Test failed because there is     **
**                already a watchdog alarm present within the SMU.            **
**                                                                            **
**                SPBREGACC_SMU_SETALMACTIONERR - Test failed because setting **
**                the SMU alarm action failed.                                **
**                                                                            **
**                SPBREGACC_SMU_GETALMACTIONERR - Test failed because getting **
**                the SMU alarm action failed.                                **
**                                                                            **
**                SPBREGACC_DENY_NOSMUALRM - Test failed because no SMU alarm **
**                was generated also a not allowed master tried to write to a **
**                protected register.                                         **
**                                                                            **
**                SPBREGACC_STUCKATFAULT - Test failed because there seems    **
**                to be a stuck-at fault within the CPU’s ACCENA register     **
**                                                                            **
**                SPBREGACC_ACCBLOCKED - The test failed because an attempt to**
**                write to a protected register with a master that is allowed **
**                got anyway blocked                                          **
**                                                                            **
**                SPBREGACC_ACCNOTBLOCKED - The test failed because an attempt**
**                to write to a protected register with a master that is not  **
**                allowed  got not blocked                                    **
*******************************************************************************/
extern Sl_TstRsltType SpbTst_PeripheralRegAccProtTst
(
 const Sl_ParamSetType ParamSetIndex,
 const uint8 TstSeed,
 uint32* const TstSignature
);

/*******************************************************************************
** Traceability: [cover parentID= <id_1>, <id_2>]                             **
**                                                                            **
** Syntax : Sl_TstRsltType SpbTst_TimeoutTst                                  **
**          (                                                                 **
**             const  Sl_ParamSetIndex ParamSetIndex,                         **
**             const  uint8 TstSeed,                                          **
**             uint32* const TstSignature                                     **
**          )                                                                 **
**                                                                            **
** Description : This test checks the timeout of SPB bus.                     **
**               To verify this, the following actions are being executed:    **
**               • Choose the peripheral as CAN.                              **
**                 Enable the module by seeting clock.                        **
**               • Set the TOUT as 0x01 in SBCU_CON register.                 **
**               • Read the CAN Message Object.                               **
**               • Verify the content of SBCU_ECON register and Alarm 3[31]   **
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
**                   Note: This parameter is ignored because no configuration **
**                   is required for this test. It is only defined for        **
**                   reasons of compatibility with APIs of other MTL tests.   **
**                                                                            **
**                   TstSeed - Seed to be used for generating the signature   **
**                                                                            **
** Parameters (out): TstSignature - Test signature generated by the test      **
**                                                                            **
** Return value : SPBTIMEOUT_SUCCESS     - Test succeeded                     **
**                                                                            **
**                SPBTIMEOUT_NOTEXECUTED - The test has not been executed     **
**                or at least was interrupted before a valid result could be  **
**                generated                                                   **
**                                                                            **
**                SPBTIMEOUT_SMU_STATEERR - The test cannot be executed       **
**                because the SMU is in the wrong state                       **
**                                                                            **
**                SPBTIMEOUT_SMU_GETALMSTSERR - Test failed because getting   **
**                the SMU alarm status failed                                 **
**                                                                            **
**                SPBTIMEOUT_SMU_CLRALMSTSERR - The test failed because       **
**                clearing the SMU alarm failed.                              **
**                                                                            **
**                SPBTIMEOUT_SMU_ALMSTSERR - Test failed because there is     **
**                already a watchdog alarm present within the SMU.            **
**                                                                            **
**                SPBTIMEOUT_SMU_SETALMACTIONERR - Test failed because        **
**                setting the SMU alarm action failed.                        **
**                                                                            **
**                SPBTIMEOUT_SMU_GETALMACTIONERR - Test failed because        **
**                getting the SMU alarm action failed.                        **
**                                                                            **
**                SPBTIMEOUT_RESOURCE_TIMEOUT - Test failed because           **
**                resource allocation action failed.                          **
**                                                                            **
**                SPBTIMEOUT_TRAP_FAILURE - Test failed because of            **
**                TRAP action failed.                                         **
**                                                                            **
**                SPBTIMEOUT_BUSERROR_TIMEOUT - Test failed because           **
**                getting the SPB Error timeout                               **
*******************************************************************************/
extern Sl_TstRsltType SpbTst_TimeoutTst
(
 const Sl_ParamSetType ParamSetIndex,
 const uint8 TstSeed,
 uint32* const TstSignature
);
#define IFX_SPBTST_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                Global Function like macro Definitions                      **
*******************************************************************************/

#endif /* SPBTST_H */

