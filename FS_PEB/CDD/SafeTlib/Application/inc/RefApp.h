/*******************************************************************************
** Copyright (C) Infineon Technologies (2012)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**  $FILENAME   : RefApp.h $                                                 **
**                                                                            **
**  $CC VERSION : \main\14 $                                                 **
**                                                                            **
**  $DATE       : 2018-02-22 $                                               **
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
**                 - Reference application                                    **
**                                                                            **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: Yes                                      **
**                                                                            **
*******************************************************************************/

#ifndef _REFAPP_H
#define _REFAPP_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "ChipId.h"
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define PLL_VCO_LOCK_TIMEOUT        ((uint32)0x00080000U)


/*This value is used to mask all values except for SW reset*/
#define MCU_RESET_MASK                 (0x038AU)

  /*This value is used to get the system timer configuration*/
#define MCU_STM_MASK                   (0x10000U)

  /*This value masks the reset status register*/
#define MCU_RESET_REASON_MASK          (0x13BD00FBU)

  /*Pdiv shift value*/
#define MCU_PDIV_SHIFT_VALUE           (24U)

  /*Ndiv shift value*/
#define MCU_NDIV_SHIFT_VALUE           (9U)

  /*Delay in Microseconds for Mcu_InitClock and Mcu_DistributePllClock*/
#define MCU_DELAY                      (20UL)

/* Macro to check the call for Mcu_Init.*/
#define MCU_DRIVER_INITIALIZED         (1U)

/* When setting a bit to '1', this can be used */
#define MCU_BITVAL_1 (1U)

/* When setting a bit to '0', this can be used */
#define MCU_BITVAL_0 (0U)


/*SCU_CCUCON0.CLKSEL = PLL as source (29th & 28th bit = 0 & 1 respectively)*/
#define MCU_CLKSEL_IS_PLL_AS_SOURCE ((unsigned_int)0x1U << 28)


/*SCU_CCUCON1.INSEL = ext osc = Fosc0 (29th & 28th bit = 0 & 1 respectively)*/
#define MCU_INSEL_IS_FOSC0_AS_SOURCE ((unsigned_int)0x1U << 28)


/* SCU_CCUCON1.UP = 1 to update the CCU registers (30th bit = 1) */
#define MCU_UP_IS_SET_TO_UPDATE ((unsigned_int)0x1U << 30)

/* Mask and Bit position to expose the OSCVAL bits */
#define MCU_OSCCON_B_OSCVAL_MASK (~(unsigned_int)(0x001F0000U))
#define MCU_OSCCON_B_OSCVAL_BITPOS (16U)

/* Mask to isolate the PDIV and NDIV fields in PLLCON0 */
#define  MCU_PLLCON0_PDIV_NDIV_MASK (0x0F00FF00U)

/* Used to reset the VCOPWD bit in PLLCON0 SFR */
#define MCU_VCOPWD_IS_SET_TO_NORMAL (~((unsigned_int)1U<<1))

/* Used to reset the PLLPWD bit in PLLCON0 SFR */
#define MCU_PLLPWD_IS_SET_TO_NORMAL ((unsigned_int)1U<<16)

/* Used to check the oscillator for PLL Valid Low Status Bit in OSCCON SFR*/
#define MCU_PLLLV_STATUS_CHECK ((unsigned_int)1U<<1)

/* Used to check the oscillator for PLL Valid High Status Bit in OSCCON SFR*/
#define MCU_PLLHV_STATUS_CHECK ((unsigned_int)1U<<8)

/*Used for the delay after performing reset */
#define MCU_PERFORM_RESET_DELAY (90000U)

/* Reset LCK, UP and INSEL fields of SCU_CCUCON1 sfr*/
#define MCU_RESET_LCK_UP_INSEL (0x0fffffffU)

/* Dealy for validating the frequency of PLL */
#define MCU_VALIDATE_PLL_FREQUENCY_DELAY (640U)

/* Mask for VCO bypass status check */
#define MCU_PLLSTAT_MASK_VCOBYST (0x01U)

/* Selection bit for normal mode in PLL status register */
#define MCU_PLLSTAT_NORMAL_MODE (0x00U)

/* Mask for K1DIV of PLLCON1 register */
#define MCU_PLLCON1_MASK_K1DIV (0xffU)

/* Field of K1DIV of PLLCON1 register */
#define MCU_PLLCON1_FIELD_K1DIV (16U)

/* Value of K1DIV of PLLCON1 register */
#define MCU_PLLCON1_VALUE_K1DIV (1U)

/* Mask for K1DIV of PLLCON1 register */
#define MCU_PLLCON1_MASK_K1DIV_FIELD (0x7fU)

/* Reset UP field of CCUCON0 sfr */
#define MCU_CCUCON_RESET_UP (0xBFFFFFFFU)

/* Mask FSIDIV, FSI2DIV, SPBDIV, SRIDIV, BAUD2DIV and BAUD1DIV of CCUCON0 sfr */
#define MCU_CCUCON0_MASK_CLOCK_DIVIDERS (0x0FFFFFFFU)

/* Mask dividers of CCUCON1 sfr */
#define MCU_CCUCON1_MASK_CLOCK_DIVIDERS (0x0FFFFFFFU)




/* Reset LCK, UP and CLKSEL fields of SCU_CCUCON0 sfr*/
#define MCU_RESET_LCK_UP_CLKSEL (0x0fffffffU)

/* Delay for normal mode selection */
#define MCU_DELAY_FOR_NORMAL_MODE_SELECTION (100U)

/* MACRO for Hardware timeout */
#define MCU_MAX_TIMEOUT         ((uint32)0xFFFFFFFFU)

/* Mask for SMU alarms configuration related to PLL and OSC */
#define MCU_PLL_OSC_SMU_MASK    ((uint32)0x00000007U)

#define MCU_OSCVAL_REG_VALUE  (0x7U)
#define IFX_APPL_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
extern void     RA_Stop     (void);
#define IFX_APPL_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
#endif
