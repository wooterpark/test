/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2018)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : Mcu_Platform.c $                                           **
**                                                                            **
**  $CC VERSION : \main\62 $                                                 **
**                                                                            **
**  $DATE       : 2018-01-12 $                                               **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This file contains AURIX derivative (platform specific)     **
**                functionality of MCU driver.                                **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
  /* Inclusion of controller sfr file */
#include "IfxScu_reg.h"
#include "IfxScu_bf.h"
#include "Mcu.h"
#include "Mcu_Local.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/* MACRO for Hardware timeout */
#define MCU_ERAY_MAX_TIMEOUT                 ((uint32)0x000001FFU)

/* Mask Values to be verified in Mcu_InitCheck */
#define MCU_PMSWCR0_TRISTEN_LCK_CLRMASK      ((uint32)0x7FDFFFFFU)

/* MASK for CCUCON Registers divider values */
#define MCU_CCUCON0_MASK_CLOCK_DIVIDERS      ((uint32)0x033F0FFFU)
#define MCU_CCUCON1_MASK_CLOCK_DIVIDERS      ((uint32)0x0FFFFFFFU)
#define MCU_CCUCON2_MASK_CLOCK_DIVIDERS      ((uint32)0x0000000FU)
#define MCU_CCUCON5_MASK_CLOCK_DIVIDERS      ((uint32)0x000000FFU)
#define MCU_CCUCON6_MASK_CLOCK_DIVIDERS      ((uint32)0x0000003FU)
#define MCU_CCUCON7_MASK_CLOCK_DIVIDERS      ((uint32)0x0000003FU)
#define MCU_CCUCON8_MASK_CLOCK_DIVIDERS      ((uint32)0x0000003FU)
#define MCU_CCUCON3_MASK_CLOCK_DIVIDERS      ((uint32)0x00FFFFFFU)
#define MCU_CCUCON4_MASK_CLOCK_DIVIDERS      ((uint32)0x00FFFFFFU)

/* Reset Status types of MCU needed for internal use in a raw form */
/* ESR0 reset */
#define MCU_RAW_ESR0_RESET          ((Mcu_RawResetType)(0x00000001U))
/* ESR1 reset */
#define MCU_RAW_ESR1_RESET          ((Mcu_RawResetType)(0x00000002U))
/* SMU reset */
#define MCU_RAW_SMU_RESET           ((Mcu_RawResetType)(0x00000008U))
/* Software reset */
#define MCU_RAW_SW_RESET            ((Mcu_RawResetType)(0x00000010U))
/* STM0 Reset*/
#define MCU_RAW_STM0_RESET          ((Mcu_RawResetType)(0x00000020U))
/* STM1 Reset*/
#define MCU_RAW_STM1_RESET          ((Mcu_RawResetType)(0x00000040U))
/* STM2 Reset*/
#define MCU_RAW_STM2_RESET          ((Mcu_RawResetType)(0x00000080U))
/* Power On reset on battery connect*/
#define MCU_RAW_POWER_ON_RESET_1    ((Mcu_RawResetType)(0x13810000U))
/* Power On reset, Pulling down PORST Line */
#define MCU_RAW_POWER_ON_RESET_2    ((Mcu_RawResetType)(0x00010000U))
/*Cerberus System Reset*/
#define MCU_RAW_CB0_RESET           ((Mcu_RawResetType)(0x00040000U))
/*Cerberus Debug Reset*/
#define MCU_RAW_CB1_RESET           ((Mcu_RawResetType)(0x00080000U))
/*Cerberus Application Reset*/
#define MCU_RAW_CB3_RESET           ((Mcu_RawResetType)(0x00100000U))
/* Tuning Protection Reset*/
#define MCU_RAW_TP_RESET            ((Mcu_RawResetType)(0x00200000U))
/* EVR13 Reset*/
#define MCU_RAW_EVR13_RESET         ((Mcu_RawResetType)(0x00810000U))
/* EVR33 Reset*/
#define MCU_RAW_EVR33_RESET         ((Mcu_RawResetType)(0x01010000U))
/* Supply Watchdog Reset*/
#define MCU_RAW_SUPPLY_WDOG_RESET   ((Mcu_RawResetType)(0x02010000U))
/* Standby Regualtor Watchdog Reset*/
#define MCU_RAW_STBYR_RESET         ((Mcu_RawResetType)(0x10010000U))
#define MCU_CCUCON3_UP_CLEARMASK              0xBFFFFFFFU
#define MCU_CCUCON3_UP_SETMASK                0x40000000U
#define MCU_CCUCON0_UP_CLEARMASK              0xBFFFFFFFU
#define MCU_CCUCON1_UP_CLEARMASK              0xBFFFFFFFU
#define MCU_CCUCON2_UP_CLEARMASK              0xBFFFFFFFU
#define MCU_CCUCON5_UP_CLEARMASK              0xBFFFFFFFU
#define MCU_CCUCON0_UP_CLEARMASK1             0xBFFFFFFFU
#define MCU_CCUCON0_UP_SETMASK1               0x40000000U
#define MCU_CCUCON2_UP_CLEARMASK1             0xBFFFFFFFU
#define MCU_CCUCON2_UP_SETMASK1               0x40000000U
#define MCU_PLLERAYCON1_K1DIV_CLEARMASK       0xFF80FFFFU
#define MCU_PLLERAYCON0_VCOBYP_CLEARMASK      0xFFFFBFFEU
#define MCU_PLLERAYCON0_SETFINDIS_CLEARMASK   0xFFFFBFEFU
#define MCU_PLLERAYCON1_K2DIV_CLEARMASK       0xFFFFFF80U
#define MCU_PLLERAYCON1_K3DIV_CLEARMASK       0xFFFFF0FFU
#define MCU_PLLERAYCON0_PDIV_CLEARMASK        0xF0FFBFFFU
#define MCU_PLLERAYCON0_NDIV_CLEARMASK        0xFFFF81FFU
#define MCU_PLLERAYCON0_OSCDISCDIS_CLEARMASK  0xFFFFBFBFU
#define MCU_PLLERAYCON0_PLLPWD_CLEARMASK      0xFFFEBFFFU
#define MCU_PLLERAYCON0_PLLPWD_SETMASK        0x00000000U
#define MCU_PLLERAYCON0_CLRFINDIS_CLEARMASK   0xFFFFBFDFU
#define MCU_PLLERAYCON0_RESLD_CLEARMASK       0xFFFBBFFFU
#define MCU_PLLERAYCON0_VCOBYP_CLEARMASK1     0xFFFFBFFEU
#define MCU_PLLERAYCON0_OSCDISCDIS_CLEARMASK1 0xFFFFBFBFU
#define MCU_CCUCON_CLEARMASK                  0xFFFFFFFFU
#define MCU_OSCCON_CLEARMASK                  0xFFFFFFFFU
#define MCU_CCUCON_CLEARMASK1                 0xCFFFFFFFU
#define MCU_CCUCON_SETMASK                    0x40000000U
#define MCU_CCUCON_SETMASK1                   0x00000060U
#define MCU_OSCCON_SETMASK1                   0x00000060U
#define MCU_PLLCON0_CLEARMASK                 0xFFFFFFFFU
#define MCU_PLLERAYCON0_CLEARMASK             0xFFFFFFFFU
#define MCU_PLLCON0_SETMASK                   0x00000002U
#define MCU_PLLERAYCON0_SETMASK               0x00000002U
#define MCU_PLLCON0_CLEARMASK1                0xFFFEFFFFU
#define MCU_PLLERAYCON0_CLEARMASK1            0xFFFEBFFFU
#define MCU_PMSWCR1_CLEARMASK                 0x8FFFFFFFU
#define MCU_PMSWCR0_STANDBYRAM_MASK           0x00020000U
#define MCU_PMSWCR1_SETMASK                   0x08001000U

#define MCU_PLLERAYSTAT_VCOLOCK_CLEARMASK     0x00000004U
#define MCU_PLLERAYCON0_SETFINDIS_BITPOS        4U
#define MCU_PLLERAYCON1_K3DIV_BITPOS            8U
#define MCU_PLLERAYCON0_PDIV_BITPOS             24U
#define MCU_PLLERAYCON0_NDIV_BITPOS             9U
#define MCU_PLLERAYCON0_OSCDISCDIS_BITPOS       6U
#define MCU_PLLERAYCON0_CLRFINDIS_BITPOS        5U
#define MCU_PLLERAYCON0_PLLPWD_BITPOS           16U
#define MCU_PLLERAYCON0_RESLD_BITPOS            18U
#define MCU_PLLERAYSTAT_VCOLOCK_BITPOS          2U
#define MCU_BITVAL_0                           (0U)
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define MCU_START_SEC_CODE
#include "MemMap.h"

#if (MCU_DISABLE_ERAY_PLL == STD_OFF)
/* ERAY PLL initialization function */
static Std_ReturnType Mcu_lErayPllClockInit(Mcu_ClockType ClockSetting);

/* Function to wait for VCO locking */
IFX_LOCAL_INLINE Std_ReturnType Mcu_lErayPllWaitVcoLock(void);
#endif

/* Functions to handle Standby Redundancy RAM */
static void Mcu_lHandleStandbyRAM(void);

/* Function to find the reset reason MCU_RESET_UNDEFINED/MCU_RESET_MULTIPLE */
IFX_LOCAL_INLINE Mcu_ResetType Mcu_lFindResetReason(Mcu_RawResetType \
                                                          RstReasonRaw);

#define MCU_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives
 is allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/


/*Memory Map of the MCU Code*/
#define MCU_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives
 is allowed only for MemMap.h*/
#include "MemMap.h"

#if (MCU_ENABLE_CLOCK_MONITORING == STD_ON)

/*******************************************************************************
** Traceability : [cover parentID=]                                           **
**                                                                            **
** Syntax : void Mcu_lInitClockMonitoring (void)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:    N/A                                                         **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non Reentrant                                               **
**                                                                            **
** Parameters (in):   None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value:    None                                                      **
**                                                                            **
** Description : This function enables the Clock monitoring unit and monitors **
**                 the safety relevant clocks if they cross the frequency     **
**                 thresholds. If an failure is detected by the Clock         **
**                 monitoring unit, it will raise an SMU alarm. It is assumed **
**                 that the SMU alarms for clock monitoring are configured.   **
**                                                                            **
*******************************************************************************/
void Mcu_lInitClockMonitoring(void)
{

  MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
  /*IFX_MISRA_RULE_11_05_STATUS=As per Misra rule 11.4, A cast should not
    be performed between a pointer to object type and a different pointer
    to object type. Driver requires such type castings wherever the
    register access is done. (void *) type casting is done to avoid 11.4,
    which introduced 11.5. However, volatile qualification of register
    is maintained with last type cast of every register access.*/
  if((Mcu_lInitCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON3.U))\
                                          != (uint32)MCU_BITVAL_0)
  {

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range*/
    MCU_SFR_INIT_WRITE32(SCU_CCUCON3.U,(unsigned_int)
                  (Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon3 &
                                          MCU_CCUCON3_MASK_CLOCK_DIVIDERS));
  }
  /*IFX_MISRA_RULE_11_05_STATUS=As per Misra rule 11.4, A cast should not
    be performed between a pointer to object type and a different pointer
    to object type. Driver requires such type castings wherever the
    register access is done. (void *) type casting is done to avoid 11.4,
    which introduced 11.5. However, volatile qualification of register
    is maintained with last type cast of every register access.*/
  if((Mcu_lInitCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON4.U))\
                                        != (uint32)MCU_BITVAL_0)
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
    PBConfigStructure and is within allowed range*/
    MCU_SFR_INIT_WRITE32(SCU_CCUCON4.U,(unsigned_int)
                (Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon4 &
                                        MCU_CCUCON4_MASK_CLOCK_DIVIDERS));
  }

  /* Single Update for all CCUCON3 & 4 registers*/
  /*IFX_MISRA_RULE_11_05_STATUS=As per Misra rule 11.4, A cast should not
    be performed between a pointer to object type and a different pointer
    to object type. Driver requires such type castings wherever the
    register access is done. (void *) type casting is done to avoid 11.4,
    which introduced 11.5. However, volatile qualification of register
    is maintained with last type cast of every register access.*/
  if((Mcu_lInitCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON3.U))\
                                        != (uint32)MCU_BITVAL_0)
  {
    MCU_SFR_INIT_MODIFY32(SCU_CCUCON3.U,MCU_CCUCON3_UP_CLEARMASK,\
                                                      MCU_CCUCON3_UP_SETMASK)
  }

  MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();


}/* End of Mcu_lInitClockMonitoring() */

#endif /*End Of MCU_ENABLE_CLOCK_MONITORING*/


/*******************************************************************************
** Syntax : Std_ReturnType Mcu_lPlatformInit (void)                           **
**                                                                            **
** Service ID:    None                                                        **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non-reentrant                                               **
**                                                                            **
** Parameters (in):   None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value:  E_OK if successful else E_NOT_OK                            **
**                                                                            **
** Description :  This service shall initialize platform specific             **
**                functionality.                                              **
**                                                                            **
*******************************************************************************/
Std_ReturnType Mcu_lPlatformInit(void)
{
  Std_ReturnType RetValue = E_OK;

  MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
  /*IFX_MISRA_RULE_11_05_STATUS=As per Misra rule 11.4, A cast should not
    be performed between a pointer to object type and a different pointer
    to object type. Driver requires such type castings wherever the
    register access is done. (void *) type casting is done to avoid 11.4,
    which introduced 11.5. However, volatile qualification of register
    is maintained with last type cast of every register access.*/
  if((Mcu_lInitCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON0.U))\
                                          != (uint32)MCU_BITVAL_0)
  {

    /* Initialize all clock dividers */
    /*Reserve bit access is ensured for CCUCON0 register*/
    MCU_SFR_INIT_MODIFY32(SCU_CCUCON0.U,MCU_CCUCON0_UP_CLEARMASK,0U)

  }
  /*Reserve bit access is ensured for CCUCON0 register*/
  /*IFX_MISRA_RULE_11_05_STATUS=As per Misra rule 11.4, A cast should not
    be performed between a pointer to object type and a different pointer
    to object type. Driver requires such type castings wherever the
    register access is done. (void *) type casting is done to avoid 11.4,
    which introduced 11.5. However, volatile qualification of register
    is maintained with last type cast of every register access.*/
  if((Mcu_lInitCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON0.U))\
                                         != (uint32)MCU_BITVAL_0)
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
     PBConfigStructure and is within allowed range*/
    MCU_SFR_INIT_WRITE32(SCU_CCUCON0.U,(unsigned_int)\
    ((Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon0) &\
    MCU_CCUCON0_MASK_CLOCK_DIVIDERS));
  }
  MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();

  MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
  /*IFX_MISRA_RULE_11_05_STATUS=As per Misra rule 11.4, A cast should not
    be performed between a pointer to object type and a different pointer
    to object type. Driver requires such type castings wherever the
    register access is done. (void *) type casting is done to avoid 11.4,
    which introduced 11.5. However, volatile qualification of register
    is maintained with last type cast of every register access.*/
  if((Mcu_lInitCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON1.U))\
                                          != (uint32)MCU_BITVAL_0)
  {

    MCU_SFR_INIT_MODIFY32(SCU_CCUCON1.U,MCU_CCUCON1_UP_CLEARMASK,0U)
  }
  /*IFX_MISRA_RULE_11_05_STATUS=As per Misra rule 11.4, A cast should not
    be performed between a pointer to object type and a different pointer
    to object type. Driver requires such type castings wherever the
    register access is done. (void *) type casting is done to avoid 11.4,
    which introduced 11.5. However, volatile qualification of register
    is maintained with last type cast of every register access.*/
  if((Mcu_lInitCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON1.U))\
                                         != (uint32)MCU_BITVAL_0)
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
     PBConfigStructure and is within allowed range*/
    MCU_SFR_INIT_WRITE32(SCU_CCUCON1.U,(unsigned_int)\
     (((Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon1) &\
       MCU_CCUCON1_MASK_CLOCK_DIVIDERS)|MCU_INSEL_IS_FOSC0_AS_SOURCE));
  }
  MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();


  MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
  /*IFX_MISRA_RULE_11_05_STATUS=As per Misra rule 11.4, A cast should not
    be performed between a pointer to object type and a different pointer
    to object type. Driver requires such type castings wherever the
    register access is done. (void *) type casting is done to avoid 11.4,
    which introduced 11.5. However, volatile qualification of register
    is maintained with last type cast of every register access.*/
  if((Mcu_lInitCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON2.U))\
                                          != (uint32)MCU_BITVAL_0)
  {
    MCU_SFR_INIT_MODIFY32(SCU_CCUCON2.U,MCU_CCUCON2_UP_CLEARMASK,0U)
  }
  /*IFX_MISRA_RULE_11_05_STATUS=As per Misra rule 11.4, A cast should not
    be performed between a pointer to object type and a different pointer
    to object type. Driver requires such type castings wherever the
    register access is done. (void *) type casting is done to avoid 11.4,
    which introduced 11.5. However, volatile qualification of register
    is maintained with last type cast of every register access.*/
  if((Mcu_lInitCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON2.U))\
                                         != (uint32)MCU_BITVAL_0)
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
     PBConfigStructure and is within allowed range*/
    MCU_SFR_INIT_WRITE32(SCU_CCUCON2.U,(unsigned_int)\
       ((Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon2) &\
           MCU_CCUCON2_MASK_CLOCK_DIVIDERS));
  }
  MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();

  MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
  /*IFX_MISRA_RULE_11_05_STATUS=As per Misra rule 11.4, A cast should not
    be performed between a pointer to object type and a different pointer
    to object type. Driver requires such type castings wherever the
    register access is done. (void *) type casting is done to avoid 11.4,
    which introduced 11.5. However, volatile qualification of register
    is maintained with last type cast of every register access.*/
  if((Mcu_lInitCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON5.U))\
                                          != (uint32)MCU_BITVAL_0)
  {

    /*Reserve bit access is ensured for CCUCON5 register*/
    MCU_SFR_INIT_MODIFY32(SCU_CCUCON5.U,MCU_CCUCON5_UP_CLEARMASK,\
                                                       MCU_CCUCON5_BIT6_SETMASK)
  }
  /*Reserve bit access is ensured for CCUCON5 register*/
  /*IFX_MISRA_RULE_11_05_STATUS=As per Misra rule 11.4, A cast should not
    be performed between a pointer to object type and a different pointer
    to object type. Driver requires such type castings wherever the
    register access is done. (void *) type casting is done to avoid 11.4,
    which introduced 11.5. However, volatile qualification of register
    is maintained with last type cast of every register access.*/
  if((Mcu_lInitCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON5.U))\
                                          != (uint32)MCU_BITVAL_0)
  {
   /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
     PBConfigStructure and is within allowed range*/
   MCU_SFR_INIT_WRITE32(SCU_CCUCON5.U,((unsigned_int)\
                  (Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon5)));
  }
  MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();

  MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
  /*IFX_MISRA_RULE_11_05_STATUS=As per Misra rule 11.4, A cast should not
    be performed between a pointer to object type and a different pointer
    to object type. Driver requires such type castings wherever the
    register access is done. (void *) type casting is done to avoid 11.4,
    which introduced 11.5. However, volatile qualification of register
    is maintained with last type cast of every register access.*/
  if((Mcu_lInitCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON0.U))\
                                          != (uint32)MCU_BITVAL_0)
  {
    /* Single Update for all CCUCON0,1,5 registers*/
    /*Reserve bit access is ensured for CCUCON0 register*/
    MCU_SFR_INIT_MODIFY32(SCU_CCUCON0.U,MCU_CCUCON0_UP_CLEARMASK1,\
                                                    MCU_CCUCON0_UP_SETMASK1)
  }
  /* Single Update for all CCUCON2 registers*/
  /*IFX_MISRA_RULE_11_05_STATUS=As per Misra rule 11.4, A cast should not
    be performed between a pointer to object type and a different pointer
    to object type. Driver requires such type castings wherever the
    register access is done. (void *) type casting is done to avoid 11.4,
    which introduced 11.5. However, volatile qualification of register
    is maintained with last type cast of every register access.*/
  if((Mcu_lInitCcuconLckBitCheck((volatile uint32 *)(void *)&SCU_CCUCON2.U))\
                                        != (uint32)MCU_BITVAL_0)
  {
    MCU_SFR_INIT_MODIFY32(SCU_CCUCON2.U,MCU_CCUCON2_UP_CLEARMASK1,\
                                                      MCU_CCUCON2_UP_SETMASK1)
  }
  MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();

  MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range*/
  MCU_SFR_INIT_WRITE32(SCU_CCUCON6.U,(unsigned_int)\
     ((Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon6) &\
                 MCU_CCUCON6_MASK_CLOCK_DIVIDERS));

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range*/
  MCU_SFR_INIT_WRITE32(SCU_CCUCON7.U,(unsigned_int)
        ((Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon7) &\
                           MCU_CCUCON7_MASK_CLOCK_DIVIDERS));

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range*/
  MCU_SFR_INIT_WRITE32(SCU_CCUCON8.U,(unsigned_int)
      ((Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon8) &\
                           MCU_CCUCON8_MASK_CLOCK_DIVIDERS));

  /* ERAY PLL block is put into the Power Saving Mode */
  /*Reserve bit access is ensured for PLLERAYCON0 register*/
  MCU_SFR_INIT_MODIFY32(SCU_PLLERAYCON0.U,MCU_PLLERAYCON0_PLLPWD_CLEARMASK,0U)

  MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();

  #if (MCU_DISABLE_ERAY_PLL == STD_OFF)
  /* Initialize ERAY sampling clock */
  RetValue = Mcu_lErayPllClockInit((Mcu_ClockType)Mcu_ClockSetting);
  #endif

  return RetValue;
}/*End of Mcu_lPlatformInit()*/

/*******************************************************************************
** Syntax : Mcu_ResetType Mcu_lFindResetReason                                **
**             (                                                              **
**                    Mcu_RawResetType RstReasonRaw                           **
**             )                                                              **
**                                                                            **
** Service ID:    None                                                        **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non-reentrant                                               **
**                                                                            **
** Parameters (in):   RstReasonRaw - Raw reset value                          **
**                                                                            **
** Parameters (out):  Type of reset occurred of Mcu_ResetType                 **
**                                                                            **
** Return value:      None                                                    **
**                                                                            **
** Description :  This service shall return the type of reset occurred        **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE Mcu_ResetType Mcu_lFindResetReason(Mcu_RawResetType \
                                                          RstReasonRaw)
{
  Mcu_ResetType RstReason;
  /* Check whether the reset reason was cold power on reset or warm power on
     reset */
  if(((RstReasonRaw & MCU_RAW_POWER_ON_RESET_1) == (MCU_RAW_POWER_ON_RESET_1))
   || ((RstReasonRaw & MCU_RAW_POWER_ON_RESET_2) == (MCU_RAW_POWER_ON_RESET_2)))
  {
    RstReason = MCU_RESET_MULTIPLE;
  }
  else
  {
    RstReason = MCU_RESET_UNDEFINED;
  }
  return (RstReason);
}

/*******************************************************************************
** Syntax : Mcu_ResetType Mcu_lGetPlatformRstReason                           **
**             (                                                              **
**                  Mcu_RawResetType RstReasonRaw                             **
**              )                                                             **
**                                                                            **
** Service ID:    None                                                        **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non-reentrant                                               **
**                                                                            **
** Parameters (in):   RstReasonRaw - Raw reset value                          **
**                                                                            **
** Parameters (out):  Type of reset occurred of Mcu_ResetType                 **
**                                                                            **
** Return value:      None                                                    **
**                                                                            **
** Description :  This service shall return the type of reset occurred        **
**                                                                            **
*******************************************************************************/
Mcu_ResetType Mcu_lGetPlatformRstReason(Mcu_RawResetType RstReasonRaw)
{
  Mcu_ResetType ResetValueToUser;

  /* Map the same to a value understandable by the user and which is in
  tandem with the one published in XDM */
  switch(RstReasonRaw)
  {
    case MCU_RAW_ESR0_RESET:
    {
      ResetValueToUser = MCU_ESR0_RESET;
      break;
    }
    case MCU_RAW_ESR1_RESET:
    {
      ResetValueToUser = MCU_ESR1_RESET;
      break;
    }
    case MCU_RAW_SMU_RESET:
    {
      ResetValueToUser = MCU_SMU_RESET;
      break;
    }
    case MCU_RAW_SW_RESET:
    {
      ResetValueToUser = MCU_SW_RESET;
      break;
    }
    case MCU_RAW_STM0_RESET:
    {
      ResetValueToUser = MCU_STM0_RESET;
      break;
    }
    case MCU_RAW_STM1_RESET:
    {
      ResetValueToUser = MCU_STM1_RESET;
      break;
    }
    case MCU_RAW_STM2_RESET:
    {
      ResetValueToUser = MCU_STM2_RESET;
      break;
    }
    case MCU_RAW_POWER_ON_RESET_1:
    case MCU_RAW_POWER_ON_RESET_2:
    {
      ResetValueToUser = MCU_POWER_ON_RESET;
      break;
    }
    case MCU_RAW_CB0_RESET:
    {
      ResetValueToUser = MCU_CB0_RESET;
      break;
    }
    case MCU_RAW_CB1_RESET:
    {
      ResetValueToUser = MCU_CB1_RESET;
      break;
    }
    case MCU_RAW_CB3_RESET:
    {
      ResetValueToUser = MCU_CB3_RESET;
      break;
    }
    case MCU_RAW_TP_RESET:
    {
      ResetValueToUser = MCU_TP_RESET;
      break;
    }
    case MCU_RAW_EVR13_RESET:
    {
      ResetValueToUser = MCU_EVR13_RESET;
      break;
    }
    case MCU_RAW_EVR33_RESET:
    {
      ResetValueToUser = MCU_EVR33_RESET;
      break;
    }
    case MCU_RAW_SUPPLY_WDOG_RESET:
    {
      ResetValueToUser = MCU_SUPPLY_WDOG_RESET;
      break;
    }
    case MCU_RAW_STBYR_RESET:
    {
      ResetValueToUser = MCU_STBYR_RESET;
      break;
    }
    default:
    {
      /* if none of the above match, check whether the reset reason is
                                   MCU_RESET_UNDEFINED or  MCU_RESET_MULTIPLE */
      ResetValueToUser = Mcu_lFindResetReason(RstReasonRaw);
      break;
    }
  }

  return (ResetValueToUser);
}/*End of Mcu_lGetPlatformRstReason()*/

#if (MCU_DISABLE_ERAY_PLL == STD_OFF)
/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_MCU_PR122_1]                         **
** Syntax : Std_ReturnType Mcu_lErayPllClockInit(Mcu_ClockType ClockSetting)  **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  E_OK if successful else E_NOT_OK                            **
**                                                                            **
** Description : Local function to initialize ERAY PLL                        **
**                                                                            **
*******************************************************************************/
static Std_ReturnType Mcu_lErayPllClockInit(Mcu_ClockType ClockSetting)
{
  uint32 ErayPllDelay;
  Std_ReturnType ErrorFlag;
  uint8 PllNdiv;
  uint8 PllK2div;
  uint8 PllK3div;
  uint8 PllPdiv;

  /*Store PLL Divider values in local variables*/
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range*/
  PllNdiv =Mcu_kConfigPtr->\
             ClockCfgPtr[ClockSetting].MCU_ErayPllDivValues.McuErayNDivider;

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range*/
  PllK2div = Mcu_kConfigPtr->\
             ClockCfgPtr[ClockSetting].MCU_ErayPllDivValues.McuErayK2Divider;

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range*/
  PllK3div = Mcu_kConfigPtr->\
             ClockCfgPtr[ClockSetting].MCU_ErayPllDivValues.McuErayK3Divider;
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range*/
  PllPdiv = Mcu_kConfigPtr->\
             ClockCfgPtr[ClockSetting].MCU_ErayPllDivValues.McuErayPDivider;

  /* delay count value is configured using parameter McuErayPllInitDelay.
  User to configure such that value of macro MCU_CONF_DELAY_ERAY_PLL is
  1000 or more to reach 10us delay as in errata */
  ErayPllDelay = MCU_CONF_DELAY_ERAY_PLL;

  /* Errata: PLL_ERAY_TC.001(PLL_ERAY initialization after cold power-up) */
  MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
  /*Reserve bit access is ensured for PLLERAYCON0 register*/
  /* set PLL_ERAY to power saving mode */
  /* Set PLLPWD(bit 16) to 0*/
  MCU_SFR_INIT_MODIFY32(SCU_PLLERAYCON0.U,MCU_PLLERAYCON0_PLLPWD_CLEARMASK,\
                                                 MCU_PLLERAYCON0_PLLPWD_SETMASK)
  MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();

  /* delay */
  for(;ErayPllDelay > 0U;ErayPllDelay--)
  {
    NOP();
  }

  MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
  /*Reserve bit access is ensured for PLLERAYCON0 register*/
  /* Set PLL_ERAY Power Saving Mode to normal behaviour */
  /* Set PLLPWD(bit 16) to 1*/
  MCU_SFR_INIT_MODIFY32(SCU_PLLERAYCON0.U,MCU_PLLERAYCON0_PLLPWD_CLEARMASK,\
                                      (uint32)1U<<MCU_PLLERAYCON0_PLLPWD_BITPOS)
  MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();
  /* ----- End of Errata PLL_ERAY_TC.001 workaround ----- */

  MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
  /* Enter Prescalar mode */
  /* Update K and N dividers */
  MCU_SFR_INIT_MODIFY32(SCU_PLLERAYCON1.U,MCU_PLLERAYCON1_K1DIV_CLEARMASK,0U)

  /*Reserve bit access is ensured for PLLERAYCON0 register*/
  MCU_SFR_INIT_MODIFY32(SCU_PLLERAYCON0.U,MCU_PLLERAYCON0_VCOBYP_CLEARMASK,1U)

  /*Reserve bit access is ensured for PLLERAYCON0 register*/
  MCU_SFR_INIT_MODIFY32(SCU_PLLERAYCON0.U,MCU_PLLERAYCON0_SETFINDIS_CLEARMASK,\
                                           1U<<MCU_PLLERAYCON0_SETFINDIS_BITPOS)
  MCU_SFR_INIT_MODIFY32(SCU_PLLERAYCON1.U,MCU_PLLERAYCON1_K2DIV_CLEARMASK,\
                                                                    PllK2div)
  MCU_SFR_INIT_MODIFY32(SCU_PLLERAYCON1.U,MCU_PLLERAYCON1_K3DIV_CLEARMASK,\
                                 (uint32)PllK3div<<MCU_PLLERAYCON1_K3DIV_BITPOS)

  /*Reserve bit access is ensured for PLLERAYCON0 register*/
  MCU_SFR_INIT_MODIFY32(SCU_PLLERAYCON0.U,MCU_PLLERAYCON0_PDIV_CLEARMASK,\
                                   (uint32)PllPdiv<<MCU_PLLERAYCON0_PDIV_BITPOS)

  /*Reserve bit access is ensured for PLLERAYCON0 register*/
  MCU_SFR_INIT_MODIFY32(SCU_PLLERAYCON0.U,MCU_PLLERAYCON0_NDIV_CLEARMASK,\
                                   (uint32)PllNdiv<<MCU_PLLERAYCON0_NDIV_BITPOS)
  /* Enter normal mode */

  /* In case of a PLL loss-of-lock bit PLLERAYSTAT.FINDIS is not set.
  i.e., The input clock from the oscillator is connected to the VCO part,
  in case of a PLL loss-of-lock bit */
  /*Reserve bit access is ensured for PLLERAYCON0 register*/
  MCU_SFR_INIT_MODIFY32(SCU_PLLERAYCON0.U,MCU_PLLERAYCON0_OSCDISCDIS_CLEARMASK,\
                                          1U<<MCU_PLLERAYCON0_OSCDISCDIS_BITPOS)

  /* The input clock from the oscillator is connected to the VCO part */
  /*Reserve bit access is ensured for PLLERAYCON0 register*/
  MCU_SFR_INIT_MODIFY32(SCU_PLLERAYCON0.U,MCU_PLLERAYCON0_CLRFINDIS_CLEARMASK,\
                                           1U<<MCU_PLLERAYCON0_CLRFINDIS_BITPOS)

  /*
    RESLD = 1     ==> Restart VCO lock detection
    CLRFINDIS = 1 ==> Connect OSC to PLL
    PLLPWD = 1    ==> PLL Power Saving Mode : Normal behaviour
    NDIV = FR_17_ERAY_PLL_NDIV (Pre-compile parameter)
  */
  /*Reserve bit access is ensured for PLLERAYCON0 register*/
  /* restart the VCO lock detection */
  MCU_SFR_INIT_MODIFY32(SCU_PLLERAYCON0.U,MCU_PLLERAYCON0_RESLD_CLEARMASK,\
                                     (uint32)1U << MCU_PLLERAYCON0_RESLD_BITPOS)

   /* Set the ENDINIT bit in the WDT_CON0 register again
  to enable the write-protection and to prevent a time-out */
  MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();

  /* Wait for ERAY PLL VCO locking */
  ErrorFlag = Mcu_lErayPllWaitVcoLock();

  /*By Pass VCO only if PLL is locked*/
  if(ErrorFlag == E_OK)
  {
    /* Clear the ENDINIT bit in the WDT_CON0 register in order
    to disable the write-protection for registers protected
    via the EndInit feature */
    MCU_SFR_INIT_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);

    /*Bypass VCO*/
    /*Reserve bit access is ensured for PLLERAYCON0 register*/
    MCU_SFR_INIT_MODIFY32(SCU_PLLERAYCON0.U,\
                                        MCU_PLLERAYCON0_VCOBYP_CLEARMASK1,0U)

    /* In case of a PLL loss-of-lock bit PLLERAYSTAT.FINDIS is set.
    i.e., The input clock from the oscillator is disconnected
    from the VCO part, in case of a PLL loss-of-lock bit */
    /*Reserve bit access is ensured for PLLERAYCON0 register*/
    MCU_SFR_INIT_MODIFY32(SCU_PLLERAYCON0.U,\
                                    MCU_PLLERAYCON0_OSCDISCDIS_CLEARMASK1,0U)

    /* Set the ENDINIT bit in the WDT_CON0 register again
    to enable the write-protection and to prevent a time-out */
    MCU_SFR_INIT_SETSAFETYENDINIT_TIMED();
  }
  return(ErrorFlag);
}/*End of Mcu_lErayPllClockInit()*/

/*******************************************************************************
** Syntax : IFX_LOCAL_INLINE Std_ReturnType Mcu_lErayPllWaitVcoLock(void)     **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  none                                                        **
**                                                                            **
** Description : Function to wait for ERAY PLL VCO locking                    **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE Std_ReturnType Mcu_lErayPllWaitVcoLock(void)
{
  Std_ReturnType ErrorFlag;
  uint32 TimeOutCount;

  ErrorFlag = E_OK;
  TimeOutCount = MCU_ERAY_MAX_TIMEOUT;
  do
  {
    TimeOutCount-- ;
  } while ((((MCU_SFR_INIT_USER_MODE_READ32(SCU_PLLERAYSTAT.U) &\
         MCU_PLLERAYSTAT_VCOLOCK_CLEARMASK)>>MCU_PLLERAYSTAT_VCOLOCK_BITPOS) \
                                                 != 1U) && (TimeOutCount > 0U));
  if (TimeOutCount == 0U)
  {
    ErrorFlag = E_NOT_OK;
    #if (MCU_E_ERAY_TIMEOUT_DEM_REPORT == MCU_ENABLE_DEM_REPORT)
    Dem_ReportErrorStatus(MCU_E_ERAY_TIMEOUT, DEM_EVENT_STATUS_FAILED);
    #endif /*  #if (MCU_E_ERAY_TIMEOUT_DEM_REPORT == MCU_ENABLE_DEM_REPORT) */
  }
  return(ErrorFlag);
}/*End of Mcu_lErayPllWaitVcoLock()*/
#endif
/*******************************************************************************
** Syntax : void Mcu_lHandleStandbyRAM(void)                                  **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  none                                                        **
**                                                                            **
** Description : Function to handle Standby redundancy data                   **
**                                                                            **
*******************************************************************************/
static void Mcu_lHandleStandbyRAM(void)
{
  uint32 LoopCtr;
  uint32 *RARPtr;
  /*IFX_MISRA_RULE_11_01_STATUS=Cast from unsigned int to pointer, this is
     required to assign the ram base address to local variable to access
     ram memory.*/
  /*IFX_MISRA_RULE_11_03_STATUS=Cast from unsigned int to pointer, this is
     required to assign the ram base address to local variable to access
     ram memory.*/
  RARPtr = (uint32*)MCU_STANDBY_DSPR0_RAR_AREA;

  /* Read sequentially from DSPR0 reserved area used by firmware
   * to store corrected redundancy data (RAR)
   */
  for (LoopCtr = 0U; LoopCtr < MCU_STANDBY_DSPR0_RAR_SIZE; LoopCtr++)
  {
    if ((*RARPtr != 0xFFFFFFFFU) && (*RARPtr != 0x0U))
    {
      uint32 *AddrPtr;
      /* Use this as an address */
      /*IFX_MISRA_RULE_11_01_STATUS=cast from unsigned int to pointer, this is
      required to assign the ram base address to local variable to access
      ram memory.*/
      /*IFX_MISRA_RULE_11_03_STATUS=cast from unsigned int to pointer, this is
      required to assign the ram base address to local variable to access
      ram memory.*/
      AddrPtr = (uint32 *)(*RARPtr);
      /* Read the data and store it back in DSPR0 */
      *RARPtr = *AddrPtr;
    }
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used as its an effiecient
    way to access consecutive memory locations*/
    RARPtr++;
  }
}/*End of Mcu_lHandleStandbyRAM()*/

/*******************************************************************************
** Syntax : void Mcu_lSetIdleMode(uint8 CoreId)                               **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): CoreId - Core Id                                          **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  none                                                        **
**                                                                            **
** Description : Function to enter Idle mode for CoreId                       **
**                                                                            **
*******************************************************************************/
void Mcu_lSetIdleMode(uint8 CoreId)
{

  uint8 CoreSelect,SystemModeSel;

  CoreSelect = (uint8)(1U << CoreId);

  SystemModeSel=\
             (uint8)((uint32)(MCU_SFR_RUNTIME_USER_MODE_READ32(SCU_PMSWCR1.U) \
                              >> IFX_SCU_PMSWCR1_CPUIDLSEL_OFF) &             \
                     (uint32)IFX_SCU_PMSWCR1_CPUIDLSEL_MSK);

  if((CoreSelect == SystemModeSel) ||\
     (MCU_INDIVIDUAL_CORE_IDLE_MODE == SystemModeSel))
  {
    #if (MCU_SAFETY_ENABLE == STD_ON)
    MCU_RESETENDINIT(MCU_SID_SETMODE);
    #else
    MCU_SFR_RUNTIME_RESETENDINIT();
    #endif
    MCU_SFR_RUNTIME_MODIFY32(MODULE_SCU.PMCSR[CoreId].U,~(((uint32) \
          (~(MCU_IDLE+1U)) & (uint32)IFX_SCU_PMCSR_REQSLP_MSK)<<    \
           IFX_SCU_PMCSR_REQSLP_OFF),((uint32)(MCU_IDLE+1U) &       \
           IFX_SCU_PMCSR_REQSLP_MSK)<<IFX_SCU_PMCSR_REQSLP_OFF)

    #if (MCU_SAFETY_ENABLE == STD_ON)
    MCU_SETENDINIT(MCU_SID_SETMODE);
    #else
    MCU_SFR_RUNTIME_SETENDINIT();
    #endif
  }

}/*End of Mcu_lSetIdleMode()*/

/*******************************************************************************
** Syntax : void Mcu_lSetSleepMode(uint8 CoreId)                              **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): CoreId - Core Id                                          **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  none                                                        **
**                                                                            **
** Description : Function to enter Sleep mode for CoreId                      **
**                                                                            **
*******************************************************************************/
void Mcu_lSetSleepMode(uint8 CoreId)
{
  uint8 CoreSelect,SystemModeSel;

  CoreSelect = (uint8)(1U << CoreId);

  SystemModeSel=\
              (uint8)((uint32)(MCU_SFR_RUNTIME_USER_MODE_READ32(SCU_PMSWCR1.U) \
                               >> IFX_SCU_PMSWCR1_CPUSEL_OFF) &                \
                      (uint32)IFX_SCU_PMSWCR1_CPUSEL_MSK);

  if((CoreSelect == SystemModeSel) ||\
     (MCU_UNANIMOUS_SEL_SYSTEM_MODE == SystemModeSel))
  {
    /* Write PMCSR[Core].REQSLP */
    #if (MCU_SAFETY_ENABLE == STD_ON)
    MCU_RESETENDINIT(MCU_SID_SETMODE);
    #else
    MCU_SFR_RUNTIME_RESETENDINIT();
    #endif
    MCU_SFR_RUNTIME_MODIFY32(MODULE_SCU.PMCSR[CoreId].U,~(((uint32) \
         (~(MCU_SLEEP+1U)) & (uint32)IFX_SCU_PMCSR_REQSLP_MSK)<<    \
            IFX_SCU_PMCSR_REQSLP_OFF),((uint32)(MCU_SLEEP+1U) &     \
             IFX_SCU_PMCSR_REQSLP_MSK)<<IFX_SCU_PMCSR_REQSLP_OFF)

    #if (MCU_SAFETY_ENABLE == STD_ON)
    MCU_SETENDINIT(MCU_SID_SETMODE);
    #else
    MCU_SFR_RUNTIME_SETENDINIT();
    #endif
  }
}/*End of Mcu_lSetSleepMode()*/

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_MCU_PR2869_PR2875_PR2877,
  DS_NAS_MCU_PR2870, DS_NAS_MCU_PR2870_1, DS_NAS_MCU_PR2874]
** Syntax : void Mcu_lSetStandbyMode(uint8 CoreId)                            **
** [/cover]                                                                   **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): CoreId - Core Id                                          **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  none                                                        **
**                                                                            **
** Description : Function to enter Standby mode for CoreId                    **
**                                                                            **
*******************************************************************************/
void Mcu_lSetStandbyMode(uint8 CoreId)
{
  uint32 LoopCtr;
  uint32 CrcValue;
  uint32 *RARPtr;
  uint8 CoreSelect;
  uint8 SystemModeSel;

  CoreSelect = (uint8)(1U << CoreId);

  SystemModeSel=(uint8)((uint32)\
    (MCU_SFR_RUNTIME_USER_MODE_READ32(SCU_PMSWCR1.U) \
         >>IFX_SCU_PMSWCR1_CPUSEL_OFF) & (uint32)IFX_SCU_PMSWCR1_CPUSEL_MSK);

  /* Configure Standby only if enabled
   * and the core is authorized to enter system to standby
   */
  if( (Mcu_kConfigPtr->StandbyCfgPtr != NULL_PTR) && \
      ((CoreSelect == SystemModeSel) || \
       (MCU_UNANIMOUS_SEL_SYSTEM_MODE == SystemModeSel)))
  {
    /* Copying the RAM redundancy data only if standby RAM is configured */
    if((Mcu_kConfigPtr->StandbyCfgPtr->PMSWCR0 & MCU_PMSWCR0_STANDBYRAM_MASK)\
       != 0U)
    {
      /* Handle RAM redundancy data */
      Mcu_lHandleStandbyRAM();
      /* Calculate and store CRC at the end of RAR area */
      if (Mcu_kConfigPtr->StandbyCfgPtr->CrcCheckEnable == (uint8)TRUE)
      {
        CrcValue = 0U;
        /*IFX_MISRA_RULE_11_01_STATUS=Cast from unsigned int to pointer, this is
           required to assign the ram base address to local variable to access
           ram memory*/
        /*IFX_MISRA_RULE_11_03_STATUS=Cast from unsigned int to pointer, this is
           required to assign the ram base address to local variable to access
           ram memory*/
        RARPtr = (uint32*)MCU_STANDBY_DSPR0_RAR_AREA;
        for (LoopCtr = 0U; LoopCtr < MCU_STANDBY_DSPR0_RAR_SIZE; LoopCtr++)
        {
          CrcValue = (uint32) CRC32((uint32)CrcValue, (uint32)*RARPtr);
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
          efficiently access the consecutive memory locations*/
          RARPtr++;
        }
        /* Store the caluclated CRC at the end of RAR area */
        *RARPtr = CrcValue;
      }
    }

    #if (MCU_ENABLE_CLOCK_MONITORING == STD_ON)
    /* Disable the clock monitoring unit, Clear CCUCON3 and CCUCON4 */
    #if (MCU_SAFETY_ENABLE == STD_ON)
    MCU_SAFETY_RESETSAFETYENDINIT_TIMED(MCU_SID_SETMODE,\
                                  MCU_SAFETY_ENDINT_TIMEOUT);
    #else
    MCU_SFR_RUNTIME_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
    #endif
    /*IFX_MISRA_RULE_11_05_STATUS=As per Misra rule 11.4, A cast should not
      be performed between a pointer to object type and a different pointer
      to object type. Driver requires such type castings wherever the
      register access is done. (void *) type casting is done to avoid 11.4,
      which introduced 11.5. However, volatile qualification of register
      is maintained with last type cast of every register access.*/
    if((Mcu_lRuntimeCcuconLckBitCheck\
                                   ((volatile uint32 *)(void *)&SCU_CCUCON3.U))\
       != (uint32)MCU_BITVAL_0)
    {
      MCU_SFR_RUNTIME_WRITE32(SCU_CCUCON3.U,0U);
    }
    /*IFX_MISRA_RULE_11_05_STATUS=As per Misra rule 11.4, A cast should not
      be performed between a pointer to object type and a different pointer
      to object type. Driver requires such type castings wherever the
      register access is done. (void *) type casting is done to avoid 11.4,
      which introduced 11.5. However, volatile qualification of register
      is maintained with last type cast of every register access.*/
    if((Mcu_lRuntimeCcuconLckBitCheck\
                                   ((volatile uint32 *)(void *)&SCU_CCUCON4.U))\
       != (uint32)MCU_BITVAL_0)
    {
      MCU_SFR_RUNTIME_WRITE32(SCU_CCUCON4.U,0U);
    }
    /* Single Update for all CCUCON3 & 4 registers via CCUCON4.UP*/
    /*IFX_MISRA_RULE_11_05_STATUS=As per Misra rule 11.4, A cast should not
      be performed between a pointer to object type and a different pointer
      to object type. Driver requires such type castings wherever the
      register access is done. (void *) type casting is done to avoid 11.4,
      which introduced 11.5. However, volatile qualification of register
      is maintained with last type cast of every register access.*/
    if((Mcu_lRuntimeCcuconLckBitCheck\
                                   ((volatile uint32 *)(void *)&SCU_CCUCON4.U))\
       != (uint32)MCU_BITVAL_0)
    {
      MCU_SFR_RUNTIME_MODIFY32(SCU_CCUCON4.U,MCU_CCUCON_CLEARMASK,\
                                                             MCU_CCUCON_SETMASK)
    }
    #if (MCU_SAFETY_ENABLE == STD_ON)
    MCU_SAFETY_SETSAFETYENDINIT_TIMED(MCU_SID_SETMODE);
    #else
    MCU_SFR_RUNTIME_SETSAFETYENDINIT_TIMED();
    #endif

    #endif
    /*Select Back-up clock as the source for all clocks */
    #if (MCU_SAFETY_ENABLE == STD_ON)
    MCU_SAFETY_RESETSAFETYENDINIT_TIMED(MCU_SID_SETMODE,\
                                              MCU_SAFETY_ENDINT_TIMEOUT);
    #else
    MCU_SFR_RUNTIME_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
    #endif
    /*Select Back-up clock as the source for all clocks */
    /*Reserve bit access is ensured for CCUCON0 register*/
    /*IFX_MISRA_RULE_11_05_STATUS=As per Misra rule 11.4, A cast should not
      be performed between a pointer to object type and a different pointer
      to object type. Driver requires such type castings wherever the
      register access is done. (void *) type casting is done to avoid 11.4,
      which introduced 11.5. However, volatile qualification of register
      is maintained with last type cast of every register access.*/
    if((Mcu_lRuntimeCcuconLckBitCheck\
                                   ((volatile uint32 *)(void *)&SCU_CCUCON0.U))\
       != (uint32)MCU_BITVAL_0)
    {
      MCU_SFR_RUNTIME_MODIFY32(SCU_CCUCON0.U,MCU_CCUCON_CLEARMASK1,0U)
    }
    /* Back-up clock is used as clock source is transferred to the CCU.*/
    /*IFX_MISRA_RULE_11_05_STATUS=As per Misra rule 11.4, A cast should not
      be performed between a pointer to object type and a different pointer
      to object type. Driver requires such type castings wherever the
      register access is done. (void *) type casting is done to avoid 11.4,
      which introduced 11.5. However, volatile qualification of register
      is maintained with last type cast of every register access.*/
    if((Mcu_lRuntimeCcuconLckBitCheck\
                                   ((volatile uint32 *)(void *)&SCU_CCUCON1.U))\
       != (uint32)MCU_BITVAL_0)
    {
      MCU_SFR_RUNTIME_MODIFY32(SCU_CCUCON1.U,MCU_CCUCON_CLEARMASK1,0U)
    }
    /* Update for CCUCON0 and CCUCON1 via CCUCON1.UP*/
    /*IFX_MISRA_RULE_11_05_STATUS=As per Misra rule 11.4, A cast should not
      be performed between a pointer to object type and a different pointer
      to object type. Driver requires such type castings wherever the
      register access is done. (void *) type casting is done to avoid 11.4,
      which introduced 11.5. However, volatile qualification of register
      is maintained with last type cast of every register access.*/
    if((Mcu_lRuntimeCcuconLckBitCheck\
                                   ((volatile uint32 *)(void *)&SCU_CCUCON1.U))\
       != (uint32)MCU_BITVAL_0)
    {
      MCU_SFR_RUNTIME_MODIFY32(SCU_CCUCON1.U,MCU_CCUCON_CLEARMASK,\
                                                            MCU_CCUCON_SETMASK)
    }
    /* Disable Oscillator and put PLL/ERAY_PLL to power saving mode */
    #if (MCU_SAFETY_ENABLE == STD_ON)
    MCU_SAFETY_SETSAFETYENDINIT_TIMED(MCU_SID_SETMODE);
    #else
    MCU_SFR_RUNTIME_SETSAFETYENDINIT_TIMED();
    #endif

    #if (MCU_SAFETY_ENABLE == STD_ON)
    MCU_SAFETY_RESETSAFETYENDINIT_TIMED(MCU_SID_SETMODE,\
                             MCU_SAFETY_ENDINT_TIMEOUT);
    #else
    MCU_SFR_RUNTIME_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
    #endif
    MCU_SFR_RUNTIME_MODIFY32(SCU_OSCCON.U,MCU_OSCCON_CLEARMASK,\
                                                            MCU_OSCCON_SETMASK1)
    /* VCO in Power Saving Mode */

    MCU_SFR_RUNTIME_MODIFY32(SCU_PLLCON0.U,MCU_PLLCON0_CLEARMASK,\
                                                            MCU_PLLCON0_SETMASK)

    /*Reserve bit access is ensured for PLLERAYCON0 register*/
    MCU_SFR_RUNTIME_MODIFY32(SCU_PLLERAYCON0.U,MCU_PLLERAYCON0_CLEARMASK,\
                                                        MCU_PLLERAYCON0_SETMASK)
    #if (MCU_SAFETY_ENABLE == STD_ON)
    MCU_SAFETY_SETSAFETYENDINIT_TIMED(MCU_SID_SETMODE);
    #else
    MCU_SFR_RUNTIME_SETSAFETYENDINIT_TIMED();
    #endif

    #if (MCU_SAFETY_ENABLE == STD_ON)
    MCU_SAFETY_RESETSAFETYENDINIT_TIMED(MCU_SID_SETMODE,\
                                           MCU_SAFETY_ENDINT_TIMEOUT);
    #else
    MCU_SFR_RUNTIME_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
    #endif
    /* PLL block is put into the Power Saving Mode */

    MCU_SFR_RUNTIME_MODIFY32(SCU_PLLCON0.U,MCU_PLLCON0_CLEARMASK1,0U)

    /*Reserve bit access is ensured for PLLERAYCON0 register*/
    MCU_SFR_RUNTIME_MODIFY32(SCU_PLLERAYCON0.U,MCU_PLLERAYCON0_CLEARMASK1,0U)

    /*Set STBYEVEN to enable write to STBYEV*/
    /* Configure IRADIS bit to disable Idle Request Acknowledge sequence
    activation for fast Standby Mode entry. This ensures that standby
    request is not blocked by a pending reset request/sequence*/


    MCU_SFR_RUNTIME_MODIFY32(SCU_PMSWCR1.U,MCU_PMSWCR1_CLEARMASK,\
                                                            MCU_PMSWCR1_SETMASK)

    #if (MCU_SAFETY_ENABLE == STD_ON)
    MCU_SAFETY_SETSAFETYENDINIT_TIMED(MCU_SID_SETMODE);
    #else
    MCU_SFR_RUNTIME_SETSAFETYENDINIT_TIMED();
    #endif

    /* Request the Standy mode */
    #if (MCU_SAFETY_ENABLE == STD_ON)
    MCU_SAFETY_RESETSAFETYENDINIT_TIMED(MCU_SID_SETMODE,\
                                              MCU_SAFETY_ENDINT_TIMEOUT);
    #else
    MCU_SFR_RUNTIME_RESETSAFETYENDINIT_TIMED(MCU_SAFETY_ENDINT_TIMEOUT);
    #endif

    MCU_SFR_RUNTIME_MODIFY32(MODULE_SCU.PMCSR[CoreId].U,\
              ~(((uint32)~(MCU_STANDBY+1U) &\
                       IFX_SCU_PMCSR_REQSLP_MSK)<<IFX_SCU_PMCSR_REQSLP_OFF),\
               ((uint32)(MCU_STANDBY+1U) & (uint32)IFX_SCU_PMCSR_REQSLP_MSK)\
                                  <<IFX_SCU_PMCSR_REQSLP_OFF)

    #if (MCU_SAFETY_ENABLE == STD_ON)
    MCU_SAFETY_SETSAFETYENDINIT_TIMED(MCU_SID_SETMODE);
    #else
    MCU_SFR_RUNTIME_SETSAFETYENDINIT_TIMED();
    #endif
  }
}/*End of Mcu_lSetStandbyMode()*/

#if (MCU_CRC_HW_USED == STD_ON)
/*******************************************************************************
** Syntax : Std_ReturnType Mcu_lCrcPlatformInit (void)                        **
**                                                                            **
** Service ID:    None                                                        **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non-reentrant                                               **
**                                                                            **
** Parameters (in):   None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :    E_OK - if initialization is success                   **
**                      E_NOT_OK - if initialization  fails                   **
**                                                                            **
** Description :  This service shall verify the platform specific             **
**                Crc initialization done by MCU.                             **
**                                                                            **
*******************************************************************************/
Std_ReturnType Mcu_lCrcPlatformInit(void)
{
  Std_ReturnType RetVal;
  /* Call the CRC_init */
  RetVal = Mcu_lCrcInit();

return(RetVal);
} /*End of Mcu_lCrcInit()*/
#endif

#if (MCU_SAFETY_ENABLE == STD_ON)
/*******************************************************************************
** Syntax : Std_ReturnType Mcu_lPlatformInitCheck (void)                      **
**                                                                            **
** Service ID:    None                                                        **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non-reentrant                                               **
**                                                                            **
** Parameters (in):   None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :    E_OK - if initialization comparison is success        **
**                      E_NOT_OK - if initialization comparison fails         **
**                                                                            **
** Description :  This service shall verify the platform specific             **
**                initialization done by MCU.                                 **
**                                                                            **
*******************************************************************************/
Std_ReturnType Mcu_lPlatformInitCheck(void)
{
  Std_ReturnType ErrorFlag;
  uint32         TempFlag;
  uint32         TempFlag1;
  volatile uint32 CompareFlag = 0xFFFFFFFFU;

  ErrorFlag = E_OK;

  if (Mcu_kConfigPtr->StandbyCfgPtr != NULL_PTR)
  {
    /* Read PMSWCR0 register and clear TRISTEN and LCK bits */
    TempFlag = (uint32)(MCU_SFR_INIT_USER_MODE_READ32(SCU_PMSWCR0.U)) &\
                        MCU_PMSWCR0_TRISTEN_LCK_CLRMASK;
    /* Read configuration value, clear the tristate bitfields, since this
      is write only bit */
    TempFlag1 = Mcu_kConfigPtr->StandbyCfgPtr->PMSWCR0 &\
                        MCU_PMSWCR0_TRISTEN_LCK_CLRMASK;

    CompareFlag &= (TempFlag ^ ~TempFlag1);
  }

  TempFlag = MCU_CCUCON0_MASK_CLOCK_DIVIDERS | MCU_CLKSEL_IS_PLL_AS_SOURCE;
  TempFlag1 = MCU_SFR_INIT_USER_MODE_READ32(SCU_CCUCON0.U);
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range*/
  CompareFlag &= (TempFlag1 & TempFlag) ^
     ~((Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon0 |
        MCU_CLKSEL_IS_PLL_AS_SOURCE)
        & TempFlag);

  TempFlag = MCU_CCUCON1_MASK_CLOCK_DIVIDERS | MCU_INSEL_IS_FOSC0_AS_SOURCE;
  TempFlag1 = MCU_SFR_INIT_USER_MODE_READ32(SCU_CCUCON1.U);
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range*/
  CompareFlag &= (TempFlag1 & TempFlag) ^
     ~((Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon1 |
        MCU_INSEL_IS_FOSC0_AS_SOURCE)
        & TempFlag);

  TempFlag = MCU_CCUCON2_MASK_CLOCK_DIVIDERS;
  TempFlag1 = MCU_SFR_INIT_USER_MODE_READ32(SCU_CCUCON2.U);
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range*/
  CompareFlag &= (TempFlag1 & TempFlag) ^
     ~(Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon2 & TempFlag);

  TempFlag = MCU_CCUCON5_MASK_CLOCK_DIVIDERS;
  TempFlag1 = MCU_SFR_INIT_USER_MODE_READ32(SCU_CCUCON5.U);
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range*/
  CompareFlag &= (TempFlag1 & TempFlag) ^
     ~(Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon5 & TempFlag);

  TempFlag = MCU_CCUCON6_MASK_CLOCK_DIVIDERS;
   TempFlag1 = MCU_SFR_INIT_USER_MODE_READ32(SCU_CCUCON6.U);
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range*/
  CompareFlag &= (TempFlag1 & TempFlag) ^
     ~(Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon6 & TempFlag);

  TempFlag = MCU_CCUCON7_MASK_CLOCK_DIVIDERS;
    TempFlag1 = MCU_SFR_INIT_USER_MODE_READ32(SCU_CCUCON7.U);
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range*/
  CompareFlag &= (TempFlag1 & TempFlag) ^
     ~(Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon7 & TempFlag);

  TempFlag = MCU_CCUCON8_MASK_CLOCK_DIVIDERS;
   TempFlag1 = MCU_SFR_INIT_USER_MODE_READ32(SCU_CCUCON8.U);
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range*/
  CompareFlag &= (TempFlag1 & TempFlag) ^
     ~(Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon8 & TempFlag);

  #if (MCU_ENABLE_CLOCK_MONITORING == STD_ON)
  /* Verify Clock monitoring registers */
  TempFlag = MCU_CCUCON3_MASK_CLOCK_DIVIDERS;
     TempFlag1 = MCU_SFR_INIT_USER_MODE_READ32(SCU_CCUCON3.U);
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
     PBConfigStructure and is within allowed range*/
  CompareFlag &= (TempFlag1 & TempFlag) ^
      ~(Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon3 & TempFlag);

  TempFlag = MCU_CCUCON4_MASK_CLOCK_DIVIDERS;
  TempFlag1 = MCU_SFR_INIT_USER_MODE_READ32(SCU_CCUCON4.U);
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
     PBConfigStructure and is within allowed range*/
  CompareFlag &= (TempFlag1 & TempFlag) ^
      ~(Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].Ccucon4 & TempFlag);

  #endif

  #if (MCU_DISABLE_ERAY_PLL == STD_OFF)
  /* Verify PLL Eray settings */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range*/
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range*/
  TempFlag = ((uint32)Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
              MCU_ErayPllDivValues.McuErayPDivider << 24U) |\
            ((uint32)Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
              MCU_ErayPllDivValues.McuErayNDivider << 9U) |\
             MCU_PLLPWD_IS_SET_TO_NORMAL;
  TempFlag1 = MCU_SFR_INIT_USER_MODE_READ32(SCU_PLLERAYCON0.U);
  CompareFlag &= (TempFlag1 ^ ~TempFlag);

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range*/
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range*/
  TempFlag = ((uint32)Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
              MCU_ErayPllDivValues.McuErayK3Divider << 8U) |\
             (uint32)Mcu_kConfigPtr->ClockCfgPtr[Mcu_ClockSetting].\
              MCU_ErayPllDivValues.McuErayK2Divider;
  TempFlag1 = MCU_SFR_INIT_USER_MODE_READ32(SCU_PLLERAYCON1.U);
  CompareFlag &= (TempFlag1 ^ ~TempFlag);
  #endif

  if (CompareFlag != 0xFFFFFFFFU)
  {
    ErrorFlag = E_NOT_OK;
  }

  return ErrorFlag;
}/*End of Mcu_lPlatformInitCheck()*/
#if (MCU_CRC_HW_USED == STD_ON)
/*******************************************************************************
** Syntax : Std_ReturnType Mcu_lCrcPlatformInitCheck (void)                   **
**                                                                            **
** Service ID:    None                                                        **
**                                                                            **
** Sync/Async:    Synchronous                                                 **
**                                                                            **
** Reentrancy:    Non-reentrant                                               **
**                                                                            **
** Parameters (in):   None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :    E_OK - if initialization comparison is success        **
**                      E_NOT_OK - if initialization comparison fails         **
**                                                                            **
** Description :  This service shall verify the platform specific             **
**                Crc initialization done by MCU.                             **
**                                                                            **
*******************************************************************************/
Std_ReturnType Mcu_lCrcPlatformInitCheck(void)
{

  Std_ReturnType TempErrFlag = E_OK;
  /* Call the CRC_init check */
  TempErrFlag |= Mcu_lCrcInitCheck();

  return TempErrFlag;
}/*End of Mcu_lCrcPlatformInitCheck()*/
#endif /*End Of MCU_CRC_HW_USED*/

#endif /*End Of MCU_SAFETY_ENABLE*/

#define MCU_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives
 is allowed only for MemMap.h*/
#include "MemMap.h"
