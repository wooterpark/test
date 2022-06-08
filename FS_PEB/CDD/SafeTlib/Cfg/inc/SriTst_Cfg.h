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
**  FILENAME  : SriTst_Cfg.h                                                  **
**                                                                            **
**  DATE, TIME: 2021-09-16, 09:33:10                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : SriTst.bmd /xdm                                   **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec /WindRiver                                  **
**                                                                            **
**  AUTHOR    : DL-BLR-ATV-STC                                                **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SriTst configuration header file                           **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef SRITST_CFG_H
#define SRITST_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/



/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/


/* Number of different test configuration sets */
#define SRI_EDC_BUSERR_TST_CFG_PARAM_COUNT        ( 1U )

/* These definitions are dependent on the user configuration.                 */
/* DMA Channel Configuration  */
#define DMA_CONFIG_SRI        (DMA_CHCFGR000)
/* DMA Channel Source Address            */
#define DMA_SOURCE_SRI        (DMA_SADR000)
/* DMA Channel Destination Address       */
#define DMA_DESTINATION_SRI   (DMA_DADR000)
/* DMA Channel Control/Status Register   */
#define DMA_CHCONTROL_SRI     (DMA_CHCSR000)
/* DMA Read Data CRC Register       */
#define DMA_RDATA_CRC_SRI     (DMA_RDCRCR000)
/* DMA Source and Destination Address CRC Register   */
#define DMA_SDADDR_CRC_SRI     (DMA_SDCRCR000)

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif  /* SRITST_CFG_H */
