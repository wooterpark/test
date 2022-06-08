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
**  FILENAME  : SpbTst_LCfg.c                                                 **
**                                                                            **
**  DATE, TIME: 2021-09-16, 09:33:14                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DESCRIPTION : SpbTst.bmd/xdm                                   **
**                                                                            **
**  VARIANT   : VariantLinkTime                                               **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  COMPILER  : Tasking/GNU/Diab                                              **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SpbTst configuration                                       **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Include module header File */ 
#include "SpbTst_Cfg.h"
#include "SpbTst.h"

/* SPB test configuration:  */
/* Number of different test configuration sets */
#include "IfxCan_reg.h"
#include "IfxAsclin_reg.h"
#include "IfxQspi_reg.h"
#include "IfxGtm_reg.h"
#include "IfxMsc_reg.h"
#include "IfxEth_reg.h"
#include "IfxI2c_reg.h"
#include "IfxSent_reg.h"
#include "IfxEray_reg.h"
#include "IfxCcu6_reg.h"
#include "IfxPsi5_reg.h"
#include "IfxPsi5s_reg.h"
#include "IfxGpt12_reg.h"
#include "IfxPort_reg.h"
#include "IfxSmu_reg.h"
#include "IfxIom_reg.h"
#include "IfxFce_reg.h"
#include "IfxStm_reg.h"
#include "IfxInt_reg.h"
#include "IfxDsadc_reg.h"
#include "IfxVadc_reg.h"
#include "IfxScu_reg.h"
#include "IfxMtu_reg.h"
#include "IfxHssl_reg.h"
#include "IfxHsct_reg.h"
#include "IfxSbcu_reg.h"
#include "IfxDma_reg.h"
#include "IfxXbar_reg.h"
#include "IfxFlash_reg.h"
/*******************************************************************************
**                      Inclusion File Check                                  **
*******************************************************************************/


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
#define IFX_SPBTST_START_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
#include "Ifx_MemMap.h"
static unsigned_int Rmc_Not_Available = 0U;
static unsigned_int Rmc_Available = 1U;

#define IFX_SPBTST_STOP_SEC_VAR_NONZERO_INIT_32BIT_ASIL_B
#include "Ifx_MemMap.h"
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
#define IFX_SPBTST_START_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"


/* SpbTest configuration  */
static const SpbTst_AccEnType SpbPeripheralCfgPtr_1[] =
{
  /* Number of different test configuration sets */
  {&CAN_CLC.U, &CAN_ACCEN0.U, &CAN_MCR.U, &Rmc_Not_Available},
  {&ASCLIN0_CLC.U, &ASCLIN0_ACCEN0.U, &ASCLIN0_DATCON.U, &Rmc_Not_Available},
  {&ASCLIN1_CLC.U, &ASCLIN1_ACCEN0.U, &ASCLIN1_DATCON.U, &Rmc_Not_Available},
  {&ASCLIN2_CLC.U, &ASCLIN2_ACCEN0.U, &ASCLIN2_DATCON.U, &Rmc_Not_Available},
  {&ASCLIN3_CLC.U, &ASCLIN3_ACCEN0.U, &ASCLIN3_DATCON.U, &Rmc_Not_Available},
  {&QSPI0_CLC.U, &QSPI0_ACCEN0.U, &QSPI0_PISEL.U, &Rmc_Not_Available},
  {&QSPI1_CLC.U, &QSPI1_ACCEN0.U, &QSPI1_PISEL.U, &Rmc_Not_Available},
  {&QSPI2_CLC.U, &QSPI2_ACCEN0.U, &QSPI2_PISEL.U, &Rmc_Not_Available},
  {&QSPI3_CLC.U, &QSPI3_ACCEN0.U, &QSPI3_PISEL.U, &Rmc_Not_Available},
  {&GTM_CLC.U, &GTM_ACCEN0.U, &GTM_KRST0.U, &Rmc_Not_Available},
  {&MSC0_CLC.U, &MSC0_ACCEN0.U, &MSC0_ICR.U, &Rmc_Not_Available},
  {&MSC1_CLC.U, &MSC1_ACCEN0.U, &MSC1_ICR.U, &Rmc_Not_Available},
  {&ETH_CLC.U, &ETH_ACCEN0.U, &ETH_KRST0.U, &Rmc_Not_Available},
  {&I2C0_CLC.U, &I2C0_ACCEN0.U, &I2C0_KRST0.U, &Rmc_Available},
  {&SENT_CLC.U, &SENT_ACCEN0.U, &SENT_FDR.U, &Rmc_Available},
  {&ERAY0_CLC.U, &ERAY0_ACCEN0.U, &ERAY0_KRST0.U, &Rmc_Available},
  {&CCU60_CLC.U, &CCU60_ACCEN0.U, &CCU60_KRST0.U, &Rmc_Not_Available},
  {&CCU61_CLC.U, &CCU61_ACCEN0.U, &CCU61_KRST0.U, &Rmc_Not_Available},
  {&PSI5_CLC.U, &PSI5_ACCEN0.U, &PSI5_KRST0.U, &Rmc_Not_Available},
  {&PSI5S_CLC.U, &PSI5S_ACCEN0.U, &PSI5S_KRST0.U, &Rmc_Not_Available},
  {&GPT120_CLC.U, &GPT120_ACCEN0.U, &GPT120_KRST0.U, &Rmc_Not_Available},
  {NULL_PTR, &P00_ACCEN0.U, &P00_OUT.U, &Rmc_Not_Available},
  {NULL_PTR, &P01_ACCEN0.U, &P01_OUT.U, &Rmc_Not_Available},
  {NULL_PTR, &P02_ACCEN0.U, &P02_OUT.U, &Rmc_Not_Available},
  {NULL_PTR, &P10_ACCEN0.U, &P10_OUT.U, &Rmc_Not_Available},
  {NULL_PTR, &P11_ACCEN0.U, &P11_OUT.U, &Rmc_Not_Available},
  {NULL_PTR, &P12_ACCEN0.U, &P12_OUT.U, &Rmc_Not_Available},
  {NULL_PTR, &P13_ACCEN0.U, &P13_OUT.U, &Rmc_Not_Available},
  {NULL_PTR, &P14_ACCEN0.U, &P14_OUT.U, &Rmc_Not_Available},
  {NULL_PTR, &P15_ACCEN0.U, &P15_OUT.U, &Rmc_Not_Available},
  {NULL_PTR, &P20_ACCEN0.U, &P20_OUT.U, &Rmc_Not_Available},
  {NULL_PTR, &P21_ACCEN0.U, &P21_OUT.U, &Rmc_Not_Available},
  {NULL_PTR, &P22_ACCEN0.U, &P22_OUT.U, &Rmc_Not_Available},
  {NULL_PTR, &P23_ACCEN0.U, &P23_OUT.U, &Rmc_Not_Available},
  {NULL_PTR, &P32_ACCEN0.U, &P32_OUT.U, &Rmc_Not_Available},
  {NULL_PTR, &P33_ACCEN0.U, &P33_OUT.U, &Rmc_Not_Available},
  {NULL_PTR, &P34_ACCEN0.U, &P34_OUT.U, &Rmc_Not_Available},
  {NULL_PTR, &P40_ACCEN0.U, &P40_IOCR0.U, &Rmc_Not_Available},
  {&SMU_CLC.U, &SMU_ACCEN0.U, &SMU_CMD.U, &Rmc_Not_Available},
  {&IOM_CLC.U, &IOM_ACCEN0.U, &IOM_KRST0.U, &Rmc_Available},
  {&FCE_CLC.U, &FCE_ACCEN0.U, &FCE_IR0.U, &Rmc_Not_Available},
  {&STM0_CLC.U, &STM0_ACCEN0.U, &STM0_KRST0.U, &Rmc_Not_Available},
  {&STM1_CLC.U, &STM1_ACCEN0.U, &STM1_KRST0.U, &Rmc_Not_Available},
  {&STM2_CLC.U, &STM2_ACCEN0.U, &STM2_KRST0.U, &Rmc_Not_Available},
  {NULL_PTR, &INT_ACCEN00.U, &INT_SRB0.U, &Rmc_Not_Available},
  {NULL_PTR, &INT_ACCEN10.U, &INT_ECR0.U, &Rmc_Not_Available},
  {&DSADC_CLC.U, &DSADC_ACCEN0.U, &DSADC_GLOBCFG.U, &Rmc_Not_Available},
  {&VADC_CLC.U, &VADC_ACCEN0.U, &VADC_GLOBCFG.U, &Rmc_Not_Available},
  {NULL_PTR, &SCU_ACCEN0.U, &SCU_LCLTEST.U, &Rmc_Not_Available},
  {&MTU_CLC.U, &MTU_ACCEN0.U, &MTU_MEMTEST0.U, &Rmc_Not_Available},
  {&HSSL_CLC.U, &HSSL_ACCEN0.U, &HSSL_KRST0.U, &Rmc_Not_Available},
  {&HSCT_CLC.U, &HSCT_ACCEN0.U, &HSCT_KRST0.U, &Rmc_Not_Available},
  {NULL_PTR, &SBCU_ACCEN0.U, &SBCU_CON.U, &Rmc_Not_Available},
  {&DMA_CLC.U, &DMA_ACCEN00.U, &DMA_MEMCON.U, &Rmc_Not_Available},
  {NULL_PTR, &XBAR_ACCEN0.U, &XBAR_ARBCON0.U, &Rmc_Not_Available},
  {NULL_PTR, &FLASH0_ACCEN0.U, &FLASH0_FPRO.U, &Rmc_Not_Available},
};


static const uint32 SmuAlarm_1[] =
{
  /* Number of different test configuration sets */
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_ACC_ENB_ERR_STS,
  SPBTST_SPB_ACC_ENB_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SPB_BUS_ERR_STS,
  SPBTST_SRI_BUS_ERR_STS,
  SPBTST_SRI_BUS_ERR_STS,

};
/* The index given in the API function is used to choose which */
/* configuration is used from config root                 */
const SpbTst_ConfigType SpbTst_ConfigRoot[1] =
{
  {
    SpbPeripheralCfgPtr_1,
    56U,
    SmuAlarm_1
  }

};
#define IFX_SPBTST_STOP_SEC_LINKTIMECFG_ASIL_B
#include "Ifx_MemMap.h"



/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
