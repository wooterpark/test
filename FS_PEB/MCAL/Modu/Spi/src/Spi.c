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
**   $FILENAME   : Spi.c $                                                    **
**                                                                            **
**   $CC VERSION : \main\295 $                                                **
**                                                                            **
**   $DATE       : 2018-03-28 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : This file contains                                         **
**                 - functionality of SPI Handler driver.                     **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**  TRACEABILITY: [cover parentID=
DS_NAS_SPI_PR131,DS_NAS_SPI_PR759_PR760_PR761,DS_NAS_SPI_PR624,
DS_AS_SPI075_SPI264,DS_NAS_SPI_PR115,DS_NAS_SPI_PR734,SAS_NAS_ALL_PR630_PR631,
SAS_NAS_SPI_PR912,DS_AS321_SPI191,DS_MCAL_SPI_9851,DS_NAS_SPI_PR2926,
SAS_NAS_ALL_PR749,SAS_NAS_ALL_PR70, SAS_NAS_ALL_PR1652,
DS_AS_SPI098, SAS_MCAL_SPI_9856,
DS_NAS_HE2_SPI_PR2957_1,DS_NAS_HE2_SPI_PR2957_2,DS_NAS_HE2_SPI_PR2957_3,
DS_NAS_HE2_SPI_PR2957_4,DS_NAS_HE2_SPI_PR2957_5,DS_NAS_HE2_SPI_PR2957_6,
DS_NAS_EP_SPI_PR2957_1,DS_NAS_EP_SPI_PR2957_2,DS_NAS_EP_SPI_PR2957_3,
DS_NAS_EP_SPI_PR2957_4,DS_NAS_EP_SPI_PR2957_5,DS_NAS_EP_SPI_PR2957_6,
SAS_MCAL_SPI_PR2967, DS_NAS_HE2_SPI_PR2966_2,DS_NAS_EP_SPI_PR2966_2,
DS_NAS_HE2_SPI_PR2981_1,DS_NAS_EP_SPI_PR2981_1, DS_NAS_HE2_SPI_PR3024,
DS_NAS_EP_SPI_PR3024]
**  [/cover]                                                                  **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "IfxQspi_reg.h"
#include "IfxQspi_bf.h"
#include "IfxDma_reg.h"
#include "IfxSrc_reg.h"
#include "IfxPort_reg.h"

/* Own header file, this includes Spi.h and Spi_Cfg.h */
#include "Spi_Local.h"

/* Include AS version specific header file */
#include "Spi_Ver.h"

/* Inclusion from Diagnostic Error Manager File */
/* The module shall include the Dem.h file.*/
#if ( (SPI_HW_ERROR_DEM_REPORT == ENABLE_DEM_REPORT) ||  \
      (SPI_DMA_ERROR_DEM_REPORT == ENABLE_DEM_REPORT) )
#include "Dem.h"
#endif

/*
  Exports specific definitions and services of the BSW Scheduler for SPI
*/
#include "SchM_Spi.h"

#if (SPI_SAFETY_ENABLE == STD_ON)
/* inclusion of Safety error report */
#include "SafetyReport.h"
#endif

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*
For internal debugging only;
*/

#ifdef IFX_SPI_DEBUG
extern volatile uint32 TestSpi_DebugMask;
#endif

/* Mask for 16 Bit Data in the Channel's Data Configuration variable.
i.e to determine if data width > 8 */
#define SPI_16BIT_DATAMASK ((uint16)(0x0008U))
/* Mask for 32 Bit Data in the Channel's Data Configuration variable.
i.e to determine if data width > 16 */
#define SPI_32BIT_DATAMASK ((uint16)(0x0010U))

#define SPI_LSB16BITS_MASK ((uint32)(0x0000FFFFU))
#define SPI_LASTCHNL_MASK  ((uint32)(0x00FF0000U))
#define SPI_MODULE_MASK    ((uint32)(0xFF000000U))
#define SPI_FRSTCHNL_MASK  ((uint32)(0xFF000000U))

#define SPI_LASTCH_SHIFTBITS ((uint32)(16U))
#define SPI_MODULE_SHIFTBITS ((uint32)(24U))
#define SPI_FRSTCH_SHIFTBITS ((uint32)(24U))

#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))

/* DMA Channel Control Setting for 16 Bit data Width */
#define SPI_DMA_CHDW_16BIT    (0x1U )

/* DMA Channel Control Setting for 32 Bit data Width */
#define SPI_DMA_CHDW_32BIT    (0x2U )

/* DMA Channel Control Setting for 8 Bit data Width */
#define SPI_DMA_CHDW_8BIT    (0x0U)

/* DMA Interrupt Category in Asyn Mode with Interrupts
  Interrupt trigger is generated and bit CHSRxz.ICH
  is set on changing the TCOUNT value and TCOUNT equals IRDV*/
#define SPI_DMA_INTCT         (2U)

/* DMA RX Channel Address Control Reg Value :
   Dest Address  Increment : 1*CHDW
   Src  Address  Increment : 0
   CBLD = 0xF; INCD =1; SMF = DMF = 0 i.e 1*CHDW (i.e.CHCRxz.CHDW)
*/
#define SPI_DMA_RX_ADRCR_NORML_TRANSFER (0x08B0F080U)

/* DMA RX Channel Address Control Reg Value :
   Dest Address  Increment : 0
   Src  Address  Increment : 0
   Used when read value is ignored i.e Destination ptr is NULL.
   CBLD = 0; INCD =1;SMF =0;
*/
#define SPI_DMA_RX_ADRCR_NULL_TRANSFER (SPI_DMA_RX_ADRCR_NORML_TRANSFER &\
                                   (~(uint32)0x0000F000U))

/* DMA TX Channel Address Control Reg Value :
   Src  Address  Increment : 1*CHDW
   Dest  Address  Increment : 0
   CBLS = 0xF; INCS =1; SMF = DMF = 1*CHDW
*/
#define SPI_DMA_TX_ADRCR_NORML_TRANSFER (0x08B00F08U)

/* DMA TX Channel Address Control Reg Value :
   Src  Address  Increment : 0
   Src  Address  Increment : 0
   Used for Transfer of Default Value. i.e Source ptr is NULL
*/
#define SPI_DMA_TX_ADRCR_NULL_TRANSFER (SPI_DMA_TX_ADRCR_NORML_TRANSFER &\
                                   (~(uint32)0x00000F00U))

#if (SPI_DMA_ADDRESS_ACCESS == STD_ON)
/* DMA Dummy Read Address Used if  Read Value is to be ignored, Address
translation not required for Tricore 1.6 */
#define SPI_DMA_DUMMY_RX_ADDRESS ((uint32)(&Spi_DMARXDummy))
#endif
/*(SPI_DMA_ADDRESS_ACCESS == STD_ON)*/

/* Value to indicate that the SPI Bus is Idle */
#define SPI_BUS_IDLE ((uint8)0xFFU)

/* Value to indicate that the Sequence is non active */
#define SPI_SEQ_IDLE_ID (0xFFU)
/* Value to indicate that the Job is non active */
#define SPI_JOB_IDLE_ID (0xFFFFU)

#endif
/* ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U) */

/* Mask that determines if the Sequence is pending or just cancelled in case
of Async transmit. The Mask is applied on Variable SeqStatus */
#define SPI_SEQ_BUSY_MASK (0x55555555U)

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0U) || (SPI_CHANNEL_BUFFERS_ALLOWED == 2U))
/* Total number of bits in variable that indicates channel lock status */
#define SPI_NUM_OF_BITS  ((uint8)8)
/* This macro to define the array size of ChannelWriteLock */
#define SPI_INDEX_OF_CHANNELLOCK   (3U)
#endif
 /*SPI_CHANNEL_BUFFERS_ALLOWED == 0 || SPI_CHANNEL_BUFFERS_ALLOWED == 2U*/

/* This macro is used to find the position of the sequence in the array
SeqStatus */
#define SPI_SEQUENCE_BIT_POSITION  ((uint8)15)
/* This macro to find the index for sequence in the array SeqStatus. */
#define SPI_SEQUENCE_INDEX   ((uint8)4)

/*
  This macro extracts the status of the seq from two bits
*/
#define SPI_SEQUENCE_STATUS_EXTRACT  (3U)
#define SPI_SEQUENCE_STATUS_BITMASK  (0x03U)

/* Bit masks to extract SEQ status from the packed variable SeqStatus */
#define SPI_SEQ0MASK (0x00000003U)
#define SPI_SEQ1MASK (0x0000000CU)
#define SPI_SEQ2MASK (0x00000030U)
#define SPI_SEQ3MASK (0x000000C0U)
#define SPI_SEQ4MASK (0x00000300U)
#define SPI_SEQ5MASK (0x00000C00U)
#define SPI_SEQ6MASK (0x00003000U)
#define SPI_SEQ7MASK (0x0000C000U)
#define SPI_SEQ8MASK (0x00030000U)
#define SPI_SEQ9MASK (0x000C0000U)
#define SPI_SEQ10MASK (0x00300000U)
#define SPI_SEQ11MASK (0x00C00000U)
#define SPI_SEQ12MASK (0x03000000U)
#define SPI_SEQ13MASK (0x0C000000U)
#define SPI_SEQ14MASK (0x30000000U)
#define SPI_SEQ15MASK (0xC0000000U)

/* Bit values for extract pending seq from SeqStatus */
#define SPI_SEQ0PENDING (0x00000001U)
#define SPI_SEQ1PENDING (0x00000004U)
#define SPI_SEQ2PENDING (0x00000010U)
#define SPI_SEQ3PENDING (0x00000040U)
#define SPI_SEQ4PENDING (0x00000100U)
#define SPI_SEQ5PENDING (0x00000400U)
#define SPI_SEQ6PENDING (0x00001000U)
#define SPI_SEQ7PENDING (0x00004000U)
#define SPI_SEQ8PENDING (0x00010000U)
#define SPI_SEQ9PENDING (0x00040000U)
#define SPI_SEQ10PENDING (0x00100000U)
#define SPI_SEQ11PENDING (0x00400000U)
#define SPI_SEQ12PENDING (0x01000000U)
#define SPI_SEQ13PENDING (0x04000000U)
#define SPI_SEQ14PENDING (0x10000000U)
#define SPI_SEQ15PENDING (0x40000000U)

/*
This macro is used to find the port number used by Chip select
*/
#define SPI_EXTRACT_PORT_ID  (4U)
/*
This macro is used to mask the selected port
*/
#define SPI_PORT_ID_MASK  (0x00FFU)
/*
This macro is used to mask the selected port pin
*/
#define SPI_PORT_PIN_MASK  (0x0FU)

/* The macro to check the multiple calls of Spi_Init.*/
#define SPI_DRIVER_INITIALIZED  ((uint8)1)
/* The macro to de initialize the driver on Spi_DeInit call.*/
#define SPI_DRIVER_DEINITIALIZED  ((uint8)0)

/*This macro is used for masking the address */
#define SPI_DMA_ADDRESS_MASK (0x00007FFFU)
/* This macro is used to check the DMA address overflow */
#define SPI_DMA_ADDRESS_OVERFLOW (0x00008000U)

/* This macro is used for masking DMA Error Status Register */
#define DMA_ERRSR_ERROR_MASK     (0x07330000U)

/*Macro to handle 16 bit data */
#define SPI_16BIT_DATA_ACCESS  (2U)

/*Macro to handle 32 bit data */
#define SPI_32BIT_DATA_ACCESS  (4U)

/*Macro to handle 8 bit data */
#define SPI_8BIT_DATA_ACCESS  (1U)

/* Macro to set the reset bits of port OMR register */
#define SPI_PORT_RESET_BITS    (16U)

/* Define to reset the QSPI module by setting GLOBALCON.RESETS bits */
#define SPI_QSPI_RESET_MODULE (0xF0000000U)

#define SPI_QSPI_RST_STATEMCHNEANDFIFO (0x7U)

#define SPI_QSPI_CLC_DISR_DISABLE (0x00000001U)

#define SPI_QSPI_GLOBCON_RSTVAL (0x000F30FFU)

#define SPI_QSPI_ECON_RSTVAL (0x00001450U)

#define SPI_QSPI_SSOC_RSTVAL (0x00000000U)

/* SPI Register Start Address Mapping */
#define SPI_HW_MODULE  ((volatile Ifx_QSPI*)(volatile void*) &(MODULE_QSPI0))

#define SPI_HWUNIT_MASK (0x0FU)
#define SPI_HWUNIT_CH_SHIFT (0x04U)

/* Defines for QSPI GLOBALCON Register */
#define SPI_QSPI_MASTER_SELECT (0x0U)
#define SPI_QSPI_LOOPBACK_DISABLE (0x0U)
#define SPI_QSPI_EXPECT_VALUE (15U)
#define SPI_QSPI_SI_DISABLE (0U)
#define SPI_QSPI_SRF_DISABLE (0U)
#define SPI_QSPI_MODULE_ENABLE (1U)

#if(SPI_RESET_SFR_INIT == STD_ON)
#define SPI_KERNEL_RESET_VALUE  (0x00000001U)
#define SPI_KERNEL_RESET_STATUS (0x00000002U)
#define SPI_DMA_RESET_VALUE     (0x00000000U)
#endif

/* Defines for QSPI ECON Register */
#define SPI_QSPI_CLOCKPHASE_MASK (0x01U)
#define SPI_QSPI_CLOCKPOL_MASK (0x01U)
#define SPI_QSPI_CLOCKPOL_SHIFT (0x01U)

  /* HW channels vary from 0 - 15
     but the ECON maps 8 - 15 to 0 to 7.   */
#define SPI_QSPI_HWCHANNELNO_MASK (0x7U)

/* Defines for QSPI GLOBALCON1 Register */
#define SPI_QSPI_ERRORENS_VALUE (0x17FU)

/* If the TXFIFO filling level is equal or less than this
threshold, than each move of an element from the
TXFIFO to the shift register triggers a transmit interrupt */
#define SPI_QSPI_TXFIFOINT_VALUE (0x0U)
/* If the RXFIFO filling level is equal or greater than this
threshold, than each move of an element from the shift
register to the FIFO triggers a receive interrupt */
#define SPI_QSPI_RXFIFOINT_VALUE (0x0U)
/* Enable the Interrupt */
#define SPI_QSPI_INT_ENABLE (0x1U)

/* Defines for QSPI BACONENTRY Register */
#define SPI_QSPI_TIMEDELAY_MASK (0x0007FFFEU)
#define SPI_QSPI_DL_BIT_SELECT (0U)

/* Defines for status register */
#define SPI_QSPI_ERRORSTATUS_MASK (0x079U)
/* Defines for slave status register, Rx Fifo and Baud rate */
#define SPI_QSPI_SLAVE_ERRORSTATUS_MASK (0x065U)

/* Defines for FLAGSCLEAR register */
#define SPI_QSPI_FLAGSCLEAR_VALUE (0x0FFFU)
#define SPI_QSPI_RXC_FLAGSCLEAR_VALUE (0x00000400U)
#define SPI_QSPI_TXC_FLAGSCLEAR_VALUE (0x00000200U)
#define SPI_QSPI_ERR_FLAGSCLEAR_VALUE (0x000001FFU)

/* Baudrate config parameter masks */
#define SPI_BAUDRATECONFIG_TQ_MASK (0x00FFU)
#define SPI_BAUDRATECONFIG_Q_MASK (0x003FU)
#define SPI_BAUDRATECONFIG_Q_SHIFT (8U)
#define SPI_BAUDRATECONFIG_A_MASK (0x0003U)
#define SPI_BAUDRATECONFIG_A_SHIFT (16U)
#define SPI_BAUDRATECONFIG_B_MASK (0x0003U)
#define SPI_BAUDRATECONFIG_B_SHIFT (18U)
#define SPI_BAUDRATECONFIG_C_MASK (0x0003U)
#define SPI_BAUDRATECONFIG_C_SHIFT (20U)

  /* HW channels vary from 0 - 15
     but the ECON maps 8 - 15 to 0 to 7.   */
#define SPI_CONFIG_HWCHANNELNO_MASK (0x0FU)
#define SPI_CONFIG_HWCHANNELNO_SHIFT (19U)
#define SPI_CONFIG_MSB_MASK (0x1U)
#define SPI_CONFIG_MSB_SHIFT (8U)
#define SPI_CONFIG_DATALENGTH_MASK (0x1FU)
#define SPI_CONFIG_TIMEDELAY_MASK (0x0007FFFFU)

/* Macros for transfer count shift. */
#define SPI_TRANSFERCOUNT_SHIFT_16BIT (1U)
#define SPI_TRANSFERCOUNT_SHIFT_32BIT (2U)
#define SPI_TRANSFERCOUNT_ONE (1U)

/* Macros for receive and Transmit completion status  */
#define SPI_TX_IN_PROGRESS (1U)
#define SPI_TX_COMPLETED (0U)
#define SPI_RX_IN_PROGRESS (1U)
#define SPI_RX_COMPLETED (0U)

/* Defines for Dem errors */
#define SPI_DEM_HW_ERROR (1U)
#define SPI_DEM_DMA_TRANSFER_ERROR (2U)

/* Fix JIRA 0000051047-129 */
/* Value should be similar to SPI_0_NOT_CONFIGURED in Spi_Cfg.h */
#define SPI_NOT_CONFIGURED (255U)

/*
This macro is used to Intialise the Temp varaiable which is needed for
 SSOC OEN Bit Channel configuration
*/
#define SPI_SSOC_OEN_CH_ZERO  ((uint32)(0x00010000U))

#if (SPI_SAFETY_ENABLE == STD_ON)
#if ( SPI_INITCHECK_API == STD_ON )
/* Compare value of the init check */
#define SPI_INITCHK_COMP_VALUE  (0xFFFFFFFFU)
#endif
/* ( SPI_INITCHECK_API == STD_ON ) */
#endif

#define SPI_SRC_QSPI_RX_SRE_CLEARMASK          (0x00000400U)
#define SPI_SRC_QSPI_TX_SRE_CLEARMASK          (0x00000400U)
#define SPI_STATUS_PT2F_CLEARMASK              (0x00001000U)
#define SPI_FLAGSCLEAR_PT2C_CLEARMASK          (0xFFFFFFFFU)
#define SPI_FLAGSCLEAR_PT2C_SETMASK            (0x00001000U)
#define SPI_STATUS_USRF_CLEARMASK              (0x00008000U)
#define SPI_FLAGSCLEAR_USRC_CLEARMASK          (0xFFFFFFFFU)
#define SPI_FLAGSCLEAR_USRC_SETMASK            (0x00001000U)
#define SPI_STATUS_PHASE_CLEARMASK             (0xF0000000U)
#define SPI_SRC_QSPI_ERR_SRE_CLEARMASK         (0x00000400U)
#define SPI_SRC_QSPI_ERR_CLEARMASK             (0x7FFFFBFFU)
#define SPI_SRC_QSPI_ERR_SETMASK               (0x52000000U)
#define SPI_STATUS_TXFIFOLEVEL_CLEARMASK       (0x00070000U)
#define SPI_STATUS_RXFIFOLEVEL_CLEARMASK       (0x00380000U)
#define SPI_CLC_DISS_CLEARMASK                 (0x00000002U)
#define SPI_GLOBALCONREG_MS_CLEARMASK          (0xF9FFFFFFU)
#define SPI_GLOBALCONREG_LB_CLEARMASK          (0xFFFFBFFFU)
#define SPI_GLOBALCONREG_SI_CLEARMASK          (0xFFFFFDFFU)
#define SPI_GLOBALCONREG_EXPECT_CLEARMASK      (0xFFFFFFFFU)
#define SPI_GLOBALCONREG_EXPECT_SETMASK        (0x00003C00U)
#define SPI_GLOBALCONREG_SRF_CLEARMASK         (0xFFDFFFFFU)
#define SPI_GLOBALCONREG_EN_CLEARMASK          (0xFFFFFFFFU)
#define SPI_GLOBALCONREG_EN_SETMASK            (0x01000000U)
#define SPI_GLOBALCONREG_TQ_CLEARMASK          (0xFFFFFF00U)
#define SPI_GLOBALCONREG_RESETS_CLEARMASK      (0x0FFFFFFFU)
#define SPI_GLOBALCONREG_RESETS_SETMASK        (0x00000000U)
#define SPI_GLOBALCON1REG_RESETS_CLEARMASK     (0xFFFFFE00U)
#define SPI_GLOBALCON1REG_TXFIFOINT_CLEARMASK  (0xFFFCFFFFU)
#define SPI_GLOBALCON1REG_RXFIFOINT_CLEARMASK  (0xFFF3FFFFU)
#define SPI_GLOBALCON1REG_TXEN_CLEARMASK       (0XFFFFFFFFU)
#define SPI_GLOBALCON1REG_TXEN_SETMASK         (0x00000200U)
#define SPI_GLOBALCON1REG_RXEN_CLEARMASK       (0xFFFFFFFFU)
#define SPI_GLOBALCON1REG_RXEN_SETMASK         (0x00000400U)
#define SPI_GLOBALCON1REG_PT2EN_CLEARMASK      (0xFFFFFFFFU)
#define SPI_GLOBALCON1REG_PT2EN_SETMASK        (0x00001000U)
#define SPI_GLOBALCON1REG_PT2_CLEARMASK        (0xFC7FFFFFU)
#define SPI_GLOBALCON1REG_PT2_SETMASK          (0x38000000U)
#define SPI_GLOBALCON1REG_USREN_CLEARMASK      (0xFFFFFFFFU)
#define SPI_GLOBALCON1REG_USREN_SETMASK        (0x00008000U)
#define SPI_GLOBALCON1REG_PT1_CLEARMASK        (0xFF8FFFFFU)
#define SPI_GLOBALCON1REG_PT1_SETMASK          (0x00600000U)
#define SPI_GLOBALCON1REG_RXFM_CLEARMASK       (0XCFFFFFFFU)
#define SPI_GLOBALCON1REG_RXFM_SETMASK         (0x10000000U)
#define SPI_GLOBALCON1REG_TXFM_CLEARMASK       (0xF3FFFFFFU)
#define SPI_GLOBALCON1REG_TXFM_SETMASK         (0x04000000U)
#define SPI_ECONREG_CPH_CLEARMASK              (0xFFFFEFFFU)
#define SPI_ECONREG_CPOL_CLEARMASK             (0xFFFFDFFFU)
#define SPI_ECONREG_PAREN_CLEARMASK            (0xFFFFBFFFU)
#define SPI_ECONREG_Q_CLEARMASK                (0xFFFFFFC0U)
#define SPI_ECONREG_Q_SETMASK                  (0x0000003FU)
#define SPI_ECONREG_A_CLEARMASK                (0xFFFFFF3FU)
#define SPI_ECONREG_A_SETMASK                  (0x000000C0U)
#define SPI_ECONREG_B_CLEARMASK                (0xFFFFFCFFU)
#define SPI_ECONREG_B_SETMASK                  (0x00000300U)
#define SPI_ECONREG_C_CLEARMASK                (0xFFFFF3FFU)
#define SPI_ECONREG_C_SETMASK                  (0x00000C00U)
#define SPI_BACONREG_LAST_CLEARMASK            (0xFFFFFFFFU)
#define SPI_BACONREG_LAST_CLEARMASK1           (0xFFFFFFFEU)
#define SPI_BACONREG_UINT_CLEARMASK            (0xFFFFFFFFU)
#define SPI_BACONREG_UINT_SETMASK              (0x00100000U)
#define SPI_BACONREG_UINT_CLEARMASK1           (0xFFEFFFFFU)
#define SPI_BACONREG_CS_CLEARMASK              (0x0FFFFFFFU)
#define SPI_BACONREG_MSB_CLEARMASK             (0xFFDFFFFFU)
#define SPI_BACONREG_BYTE_CLEARMASK            (0xFFBFFFFFU)
#define SPI_BACONREG_DL_CLEARMASK              (0xF07FFFFFU)
#define SPI_BACONREG_PARTYP_CLEARMASK          (0xFFF7FFFFU)
#define SPI_QSPI_ERR_CLEARMASK                 (0xFFFFFBFFU)
#define SPI_SRC_QSPI_RX_CLEARMASK              (0x7FFFFBFFU)
#define SPI_SRC_QSPI_RX_SETMASK                (0x52000000U)
#define SPI_SRC_QSPI_ERR_CLEARMASK1            (0x7FFFFFFFU)
#define SPI_SRC_QSPI_ERR_SETMASK1              (0x52000000U)
#define SPI_SRC_QSPI_TX_CLEARMASK              (0x7FFFFFFFU)
#define SPI_SRC_QSPI_TX_SETMASK1               (0x52000000U)
#define SPI_SRC_QSPI_TX_SETMASK2               (0x00000400U)
#define SPI_SRC_QSPI_PT_CLEARMASK              (0x7FFFFBFFU)
#define SPI_SRC_QSPI_PT_SETMASK                (0x52000000U)
#define SPI_SRC_QSPI_PT_CLEARMASK1             (0x00000400U)
#define SPI_SRC_QSPI_PT_CLEARMASK2             (0x7FFFFFFFU)
#define SPI_SRC_QSPI_PT_SETMASK1               (0x02000000U)
#define SPI_SRC_QSPI_PT_SETMASK3               (0x40000000U)
#define SPI_SRC_QSPI_U_CLEARMASK               (0x7FFFFBFFU)
#define SPI_SRC_QSPI_U_SETMASK                 (0x52000000U)
#define SPI_SRC_QSPI_U_CLEARMASK1              (0x7FFFFFFFU)
#define SPI_SRC_QSPI_U_SETMASK1                (0x02000000U)
#define SPI_SRC_QSPI_U_CLEARMASK2              (0X7FFFFBFFU)
#define SPI_SRC_QSPI_PT_CLEARMASK3             (0x00000400U)
#define SPI_SRC_QSPI_PT_CLEARMASK4             (0x7FFFFBFFU)
#define SPI_SRC_QSPI_TX_CLEARMASK1             (0x7FFFFBFFU)
#define SPI_SRC_QSPI_TX_SETMASK3               (0x52000000U)
#define SPI_SRC_QSPI_TX_SETMASK4             (0x42000000U)
#define SPI_SRC_QSPI_TX_SETMASK5             (0x04000000U)
#define SPI_SRC_QSPI_RX_CLEARMASK1           (0x7FFFFFFFU)
#define SPI_SRC_QSPI_RX_SETMASK1             (0x52000000U)
#define SPI_SRC_QSPI_ERR_CLEARMASK2          (0x7FFFFFFFU)
#define SPI_SRC_QSPI_ERR_SETMASK2            (0x52000000U)
#define SPI_SRC_QSPI_ERR_CLEARMASK3          (0x7FFFFFFFU)
#define SPI_SRC_QSPI_ERR_SETMASK3            (0x00000400U)
#define SPI_SRC_QSPI_RX_SETMASK2             (0x52000000U)
#define SPI_SRC_QSPI_RX_CLEARMASK3           (0x7FFFFFFFU)
#define SPI_SRC_QSPI_RX_SETMASK3             (0x00000400U)
#define SPI_SRC_QSPI_RX_CLEARMASK4           (0x7FFFFBFFU)
#define SPI_SRC_QSPI_RX_SETMASK4             (0x52000000U)
#define SPI_SRC_QSPI_RX_SETMASK5             (0x02000000U)
#define SPI_SRC_QSPI_RX_CLEARMASK6           (0x7FFFFBFFU)
#define SPI_SRC_QSPI_RX_SETMASK6             (0x40000000U)
#define SPI_SRC_QSPI_RX_SETMASK8             (0x00000400U)
#define SPI_SRC_QSPI_U_SETMASK4              (0x00000400U)
#define SPI_SRC_QSPI_RX_CLEARMASK7           (0x7FFFFFFFU)
#define SPI_SRC_QSPI_RX_SETMASK9             (0x02000000U)
#define SPI_DMACHADDR_CLEARMASK              (0x7FFFFFFFU)
#define SPI_DMACHADDR_SETMASK                (0x52000000U)
#define SPI_DMACHADDR_SETMASK1               (0x00000400U)
#define SPI_DMACHADDR_CLEARMASK1             (0x7FFFFBFFU)
#define SPI_REGADDRESS_CLEARMASK             (0x7FFFFFFFU)
#define SPI_REGADDRESS_SETMASK               (0x02000000U)
#define SPI_DMA_CHCSR_CLEARMASK              (0xFFFFFFFFU)
#define SPI_DMA_ADICR_CLEARMASK              (0xFFFFFFFFU)
#define SPI_DMA_ADICR_SETMASK                (0x00800000U)
#define SPI_DMA_ADICR_CLEARMASK1             (0xF3FFFFFFU)
#define SPI_DMA_CHCSR_SETMASK                (0x08000000U)
#define SPI_DMA_CHCSR_CLEARMASK1             (0xF7FFFFFFU)
#define SPI_DMA_TSR_CLEARMASK                (0xFFFFFFFFU)
#define SPI_DMA_TSR_SETMASK                  (0x00040000U)
#define SPI_DMA_ERRINTR_CLEARMASK            (0xFFFFFFFFU)
#define SPI_GLOBALCON_SETMASK                (0x0E000000U)
#define SPI_GLOBALCON_CLEARMASK              (0xEFFFFFFFU)
#define SPI_STATUS_CLEARMASK                 (0xF0000000U)
#define SPI_STATUS_CLEARMASK1                (0x00000200U)
#define SPI_STATUS_CLEARMASK2                (0x000001FFU)
#define SPI_STATUS_CLEARMASK3                (0x00000400U)
#define SPI_DMA_ADICR_CLEARMASK2             (0x00800000U)
#define SPI_DMA_ADICR_CLEARMASK3             (0x0C000000U)
#define SPI_GLOBALCON_CLEARMASK1             (0x7FFFFFFFU)
#define SPI_GLOBALCON_SETMASK1               (0x70000000U)
#define SPI_SSOC_OEN_CLEARMASK               (0x0000FFFFU)
#define SPI_SRC_DMACH0_SWSCLR_IOVCLR_SETMASK (0x52000400U)
#define SPI_SRC_DMACH0_SRE_CLEARMASK         (0x7FFFFBFFU)
#define SPI_SRC_DMACH0_CLEARMASK             (0x7FFFFFFFU)
#define SPI_SRC_DMACH0_CLRR_SETMASK          (0x02000000U)
#define SPI_SRC_DMACH0_SRR_CHECKMASK         (0x01000000U)
#define SPI_SRC_DMACH0_SRR_BITPOS        24U
#define SPI_STATUS_PHASE_BITPOS          28U
#define SPI_STATUS_TXFIFOLEVEL_BITPOS    16U
#define SPI_STATUS_USRF_BITPOS           15U
#define SPI_STATUS_RXFIFOLEVEL_BITPOS    19U
#define SPI_CLC_DISS_BITPOS              1U
#define SPI_SRC_QSPI_PT_BITPOS           10U
#define SPI_DMA_ADICR_BITPOS             26U
#define SPI_STATUS_BITPOS                28U
#define SPI_STATUS_TXF_BITPOS            9U
#define SPI_STATUS_RXF_BITPOS            10U
#define SPI_DMA_ADICR_ETRL_BITPOS        23U



/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 1U) || (SPI_CHANNEL_BUFFERS_ALLOWED == 2U))
/*
Type:Spi_EBBufferType.
The EB Buffer Parameters.This is required only if EB Buffer channels are
configured.
*/
typedef struct Spi_EBBuffer
{
  const Spi_DataType* SrcPtr;   /* Source pointer */
  Spi_DataType* DestPtr;        /* Destination pointer */
  Spi_NumberOfDataType Length;  /* Number of the data to be transmitted */
}Spi_EBBufferType;
#endif
/* (SPI_CHANNEL_BUFFERS_ALLOWED == 1U
          || SPI_CHANNEL_BUFFERS_ALLOWED == 2U) */

#if ((SPI_LEVEL_DELIVERED == 0U) || (SPI_LEVEL_DELIVERED == 2U))
#if(SPI_LEVEL2_ASYNC_ONLY == STD_OFF)
typedef struct Spi_SyncTransParam
{
  uint32 TransferCount;
  uint16 hwpin;
  Spi_ChannelType ChannelId;
  uint8 FirstChannel;
  uint8 IsLastChannel;
  uint8 Polarity;
}Spi_SyncTransParamType;
#endif /* SPI_LEVEL2_ASYNC_ONLY == STD_OFF */
#endif
/*((SPI_LEVEL_DELIVERED == 0U) || (SPI_LEVEL_DELIVERED == 2U))*/

/*******************************************************************************
**                 Private Function Declarations:
*******************************************************************************/
/*Memory Map of the SPI Code*/
#define SPI_START_SEC_CODE
/*
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"
#if ((SPI_LEVEL_DELIVERED == 0U) || (SPI_LEVEL_DELIVERED == 2U))
#if(SPI_LEVEL2_ASYNC_ONLY == STD_OFF)
/* Function to transmit a Job synchronously*/
static void Spi_lSyncStartJob(Spi_JobType JobId);

/*Function to transmit a channel synchronously*/
static void Spi_lSyncStartChannel(uint32 Module,
                 Spi_ChannelType ChannelId, uint32 LstChFrstChAndHwPin,
                 uint32 DelayAndHwChNo, uint8 polarity,
                 const Spi_JobConfigType* JobConfigPtr );
#endif /* SPI_LEVEL2_ASYNC_ONLY == STD_OFF */
#endif
/* ((SPI_LEVEL_DELIVERED == 0U) || (SPI_LEVEL_DELIVERED == 2U))*/

/* This function returns Nonzero value if is Module is Master*/
IFX_INLINE uint16 Spi_lModuleConfigured(uint8 Module);

/* This function returns Nonzero value if is Module is Master or slave*/
IFX_LOCAL_INLINE uint16 Spi_lAnyModuleConfigured(uint8 Module);

/* This function returns status of the configured SPI modules*/
static Spi_StatusType Spi_lGetHwStatus(uint8 ApiAccessId);

#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))

/* Function to transmit a Job Asynchronously*/
static void Spi_lStartJob(uint32 Module, Spi_JobType JobId, uint8 ApiAccessId);

/* Function to transmit a Job Synchronously*/
static void Spi_lStartChannel(uint32 Module, Spi_ChannelType Channel,
  uint8 IsLastChannel, uint32 DelayAndHwChNo, uint8 IsGpioCsFirstChannel,
  const Spi_JobConfigType* JobConfigPtr,uint8 ApiAccessId);

/* Error Handler for production errors detected by hardware. */
static void Spi_lErrorHandler(uint32 Module, uint32 DemError, uint8 \
                                                                   ApiAccessId);

/* Bus Handler for at the end of Job. Used in Async Mode*/
static void Spi_lBusHandler(uint32 Module, uint8 ApiAccessId);

/* This function returns id of the completed job */
IFX_LOCAL_INLINE uint16 Spi_lCompletedJobId
(
  const Spi_JobAndSeqAccessType *JobSeqDataPtr
);

/* returns the status of all the sequences that sharing the jobs */
static uint8 Spi_lSeqSharingJobStatus
(
  const Spi_SequenceConfigType* SeqConfigPtr
);

/* This function retuns Nonzero value if module configured as Async Bus */
/* Fix for AI00245697: Item.2 */
#if  (SPI_LEVEL_DELIVERED != 0U)
IFX_INLINE uint16 Spi_lModuleConfiguredAndAsync(uint8 Module);

/* This function returns Nonzero value if Module is Master or slave and
 they are configured for ASYNC Transmission */
IFX_LOCAL_INLINE uint16 Spi_lAnyModuleConfigAndAsync(uint8 Module);
#endif
/* (SPI_LEVEL_DELIVERED != 0U) */

#if (SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)
/* Function to push all the jobs in the local Queue to the actual queue*/
IFX_LOCAL_INLINE uint32 Spi_lStoreToArrayAndReturnCount
(
  uint16 CurrentIndex,
  uint16 *JobQueuePtr,
  uint8 *SeqQueuePtr,
  const Spi_JobAndSeqAccessType *JobSeqDataPtr
);

/* Function to push all the jobs into Queue*/
static void Spi_lCheckPushSeqJobsToQ(Spi_JobAndSeqAccessType* \
                  JobSeqDataPtr, uint32 JobCounter, Spi_SequenceType Sequence);
/*This function will goto the first interruptible seq in the seq queue */
IFX_LOCAL_INLINE uint16  Spi_lGotoFirstIntSeq
(
  uint16 SeqIndex,
  const Spi_JobAndSeqAccessType *JobSeqDataPtr
);
#endif
/*(SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)*/

#endif
/*((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))*/

/* Function to Enable Chip Select*/
static void Spi_lEnableChipSelect(uint16 CSPin, uint8 CSPolarity,
                                     Spi_HWUnitType  HwUnit, uint8 ApiAccessId);

/* Function to Disable Chip Select*/
static void Spi_lDisableChipSelect(uint16 CSPin, uint8 CSPolarity,
                                     Spi_HWUnitType  HwUnit, uint8 ApiAccessId);
IFX_LOCAL_INLINE void Spi_lDisableChipSelect_SV(uint16 CSPin, uint8 CSPolarity,
                                     Spi_HWUnitType  HwUnit, uint8 ApiAccessId);
#if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
#if (((SPI_LEVEL_DELIVERED == 1U) && \
(SPI_ASYNC_MODE_LEVEL1 == SPI_ASYNC_MODE_POLLING)) || \
(SPI_LEVEL_DELIVERED == 2U))
/* Function to check the DMA or SPI receive error during Spi_Mainfunction call*/
IFX_LOCAL_INLINE void Spi_lMainFunctionErrorCheck
(
  uint32 ErrorStatus,
  uint32 Module,
  Dma_ChannelType  DmaTxChannel,
  Dma_ChannelType  DmaRxChannel
);
#endif
#endif

/*(((SPI_LEVEL_DELIVERED == 1U) && \
(SPI_ASYNC_MODE_LEVEL1 == SPI_ASYNC_MODE_POLLING)) ||
(SPI_LEVEL_DELIVERED == 2U))*/

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0U) || (SPI_CHANNEL_BUFFERS_ALLOWED == 2U))
/* Function to clear the status variable ChannelWriteLock */
IFX_LOCAL_INLINE void Spi_lClearChannelWriteLock(void);
/* Function to update the 16 bit data in on a Spi_WriteIB call */
IFX_LOCAL_INLINE void Spi_lIBCopy16BitData
(
  uint16* BufferDataPtr16,
  const Spi_DataType* DataBufferPtr,
  uint32 IBEndIndex,
  Spi_ChannelType Channel
);
/* Function to update the 8 bit data in on a Spi_WriteIB call */
IFX_LOCAL_INLINE void Spi_lIBCopy8BitData
(
  Spi_DataType* BufferDataPtr8,
  const Spi_DataType* DataBufferPtr,
  uint32 IBEndIndex,
  Spi_ChannelType Channel
);
/* Function to update the 32 bit data in on a Spi_WriteIB call */
IFX_LOCAL_INLINE void Spi_lIBCopy32BitData
(
  uint32* BufferDataPtr32,
  const Spi_DataType* DataBufferPtr,
  uint32 IBEndIndex,
  Spi_ChannelType Channel
);
#endif
/* ((SPI_CHANNEL_BUFFERS_ALLOWED == 0)||(SPI_CHANNEL_BUFFERS_ALLOWED == 2U)) */

/* Function to clear Job Result status(SPI_JOB_OK) */
IFX_LOCAL_INLINE void Spi_lClearJobResultStatus(void);

/* Function to clear Sequence Status (SPI_SEQ_OK) */
IFX_LOCAL_INLINE void Spi_lClearSequenceStatus(void);

#if (SPI_DEV_ERROR_DETECT == STD_ON)
#if (SPI_DMA_ADDR_SIZE_ALIGN_CHECK == STD_ON)
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 1U) || (SPI_CHANNEL_BUFFERS_ALLOWED == 2U))
/*DMA Address range checking*/
IFX_LOCAL_INLINE uint8 Spi_lCheckDmaAddress\
(
  Spi_DataType* DestAddrPtr,
  const Spi_DataType* SrcAddrPtr,
  Spi_NumberOfDataType Length
);
#endif
/*(SPI_CHANNEL_BUFFERS_ALLOWED==1U)||(SPI_CHANNEL_BUFFERS_ALLOWED==2U)*/
#endif
/* SPI_DMA_ADDR_SIZE_ALIGN_CHECK */
#endif
/* SPI_DEV_ERROR_DETECT */

#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
#if (SPI_CANCEL_API == STD_ON)
/* Function to set the status of sequence cancelled to cancel */
IFX_LOCAL_INLINE void Spi_lSeqCancelled(Spi_JobAndSeqAccessType *JobSeqDataPtr);
#endif
/*(SPI_CANCEL_API == STD_ON)*/
#endif
/* (SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U) */

#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
#if (SPI_JOB_END_NOTIF_REQ == STD_ON)
/* Function to check job end notification is called */
IFX_LOCAL_INLINE void Spi_lJobEndNotif(const Spi_JobConfigType* JobEndNotifPtr);
#endif
#endif
/* (SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U) */

#if ((SPI_LEVEL_DELIVERED == 0U) || (SPI_LEVEL_DELIVERED == 2U))
#if(SPI_LEVEL2_ASYNC_ONLY == STD_OFF)

/* Function to transmit 32 bit data synchronously*/
static void Spi_lSyncTransmit32BitData(
  Ifx_QSPI* ModulePtr,
  const uint32* SourceDataPtr32,
  uint32* DestinationPtr32,
  Spi_SyncTransParamType Spi_SyncTransParams
);
/* Function to transmit 16 bit data synchronously*/
static void Spi_lSyncTransmit16BitData(
  Ifx_QSPI* ModulePtr,
  const uint16* SourceDataPtr16,
  uint16* DestinationPtr16,
  Spi_SyncTransParamType Spi_SyncTransParams
);
/* Function to transmit 8 bit data synchronously*/
static void Spi_lSyncTransmit8BitData(
  Ifx_QSPI* ModulePtr,
  const Spi_DataType* SourceDataPtr8,
  Spi_DataType* DestinationPtr8,
  Spi_SyncTransParamType Spi_SyncTransParams
);
static void Spi_lGpioCsHandle(uint16 hwpin,uint8 Polarity);
static void Spi_lClrPendingEvents(Ifx_QSPI* ModulePtr);
static void Spi_lSyncTransmit(Spi_SequenceType Sequence);

IFX_LOCAL_INLINE Std_ReturnType Spi_lSynTransErrCheck(
                                                     const Ifx_QSPI* ModulePtr);

#endif /* SPI_LEVEL2_ASYNC_ONLY == STD_OFF */
#endif
/*(SPI_LEVEL_DELIVERED == 0U) || (SPI_LEVEL_DELIVERED == 2U)*/

#if (SPI_DEV_ERROR_DETECT == STD_ON)
/* Function to check init called or not */
IFX_LOCAL_INLINE Std_ReturnType Spi_lGetDetInitStatus(uint8 ApiId);
#endif
/* (SPI_DEV_ERROR_DETECT == STD_ON) */

IFX_INLINE void Spi_lSetSeqStatus\
                                (Spi_SequenceType Seq,Spi_SeqResultType Status);
IFX_INLINE Spi_SeqResultType Spi_lGetSeqStatus(Spi_SequenceType Seq);

/* AI00245694 1,2: Fixed */
#if ((SPI_CANCEL_API == STD_ON) && (SPI_LEVEL_DELIVERED != 0U))
IFX_INLINE void  Spi_lClrSeqCancelStatus(Spi_SequenceType Seq);
IFX_INLINE void  Spi_lSetSeqCancelStatus(Spi_SequenceType Seq);
#endif

/* AI00245694 3,4,5: Fixed */
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0U) || (SPI_CHANNEL_BUFFERS_ALLOWED == 2U))
IFX_INLINE void  Spi_lClrChannelWriteLock(Spi_ChannelType Channel);
IFX_INLINE void  Spi_lSetChannelWriteLock(Spi_ChannelType Channel);
IFX_INLINE uint8  Spi_lGetChannelWriteLock(Spi_ChannelType Channel);
#endif

IFX_INLINE void Spi_lSetJobStatus(Spi_JobType Job, Spi_JobResultType Result);
IFX_INLINE void Spi_lSetSeqStatusAtomic(Spi_SequenceType Seq,
                              Spi_SeqResultType Status);
IFX_INLINE void Spi_lSetJobStatusAtomic(Spi_JobType Job,
                                                      Spi_JobResultType Result);
IFX_INLINE uint16 Spi_lGetCSPortOffset(uint16 CSId);
IFX_INLINE Ifx_P* Spi_lGetGpioAddr(uint16 PortNumber);
IFX_INLINE uint16 Spi_lGetCSPinOffset(uint16 CSId);

#if((SPI_CHANNEL_BUFFERS_ALLOWED == 1U) || (SPI_CHANNEL_BUFFERS_ALLOWED == 2U))
#if((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
IFX_INLINE Spi_DataType* Spi_lGetDmaDummyTxAddress(uint32 Module);
IFX_INLINE void Spi_lSetDmaDummyTxValue(uint32 Module, uint32 Value);
#endif
#endif

/* Function to get if any seq is pending from the set of 16 bit seq array */
IFX_LOCAL_INLINE  uint8 Spi_lGetSeqStatusInArray(uint32 SeqArrayVal);

#if((SPI_LEVEL_DELIVERED == 0U) || (SPI_LEVEL_DELIVERED == 2U))

#if((SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON))
#if(SPI_LEVEL2_ASYNC_ONLY == STD_OFF)
IFX_LOCAL_INLINE Std_ReturnType Spi_lSyncTransmitDetCheck
(
Spi_SequenceType Sequence
);
#endif /* SPI_LEVEL2_ASYNC_ONLY == STD_OFF */
#endif
#endif

IFX_INLINE uint8 Spi_lGetQmModuleVarIndex(uint32 Module);

#if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_ON)
IFX_INLINE uint8 Spi_lGetQmModuleVarIndexSeq(Spi_SequenceType SequenceId);
#endif

#if(SPI_SAFETY_ENABLE == STD_ON)
#if(SPI_INITCHECK_API == STD_ON)
static Std_ReturnType Spi_lInitGlobalVarCheck(void);
#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
static Std_ReturnType Spi_lHwDmaSfrInitCheck(void);
#endif
#endif
/* (SPI_INITCHECK_API == STD_ON) */
#endif

#if(SPI_LEVEL_DELIVERED != 0U)
IFX_LOCAL_INLINE void Spi_lSetAsyncBusStatus(Spi_StatusType SetStatusVal);
IFX_LOCAL_INLINE void Spi_lSetModAsyncBusStatus(Spi_StatusType SetStatusVal,
                                                                  uint8 Module);
IFX_LOCAL_INLINE void Spi_lSetSeqAsyncBusStatus(Spi_StatusType SetStatusVal,
                                                     Spi_SequenceType Sequence);

IFX_LOCAL_INLINE Spi_StatusType Spi_lGetModAsyncBusStatus(uint8 Module);
IFX_LOCAL_INLINE Spi_StatusType Spi_lGetSeqAsyncBusStatus
                                                    (Spi_SequenceType Sequence);
#endif
/*(SPI_LEVEL_DELIVERED != 0U)*/

/* Fixed for AI00248107 */
#if(SPI_LEVEL_DELIVERED == 2U)
IFX_LOCAL_INLINE Spi_StatusType Spi_lGetAsyncBusStatus(void);
#endif

/*******************************************************************************
**                      Hw  Apis                                              **
*******************************************************************************/
/* Function to initialise the Spi Hw */
static Std_ReturnType Spi_lHwInit(const Spi_ConfigType* ConfigPtr);
/* Function to de initialise Spi Hw */
static void Spi_lHwDeInit(void);
/* Function to check the Spi receive status parameters in Hw */
static uint32 Spi_lHwCheckRxStatus(volatile Ifx_QSPI* ModulePtr, \
                                                             uint8 ApiAccessId);
/* Function to check the Spi slave receive status parameters in Hw */

/* Fix for AI00245697: Item.1 */
#if (SPI_SLAVE_ENABLE == STD_ON)
IFX_LOCAL_INLINE uint32 Spi_lHwCheckSlaveRxStatus(volatile Ifx_QSPI* ModulePtr);
#endif

/* Function to set the Spi Job config parameters in Hw */
static void Spi_lHwSetJobConfig(volatile Ifx_QSPI* ModulePtr,
                                        const Spi_JobConfigType* JobConfigPtr);

#if(SPI_BAUDRATE_AT_RUNTIME == STD_OFF)

IFX_LOCAL_INLINE void Spi_lHwSetConfigExtn(const Spi_ConfigType* ConfigPtr);

#if (SPI_SAFETY_ENABLE == STD_ON)
#if (SPI_INITCHECK_API == STD_ON)
IFX_LOCAL_INLINE Std_ReturnType Spi_lHwCheckConfigExtn
                                            (const Spi_ConfigType* ConfigPtr);
#endif
#endif

#endif /* SPI_BAUDRATE_AT_RUNTIME == STD_OFF */

#if(SPI_RESET_SFR_INIT == STD_ON)
IFX_LOCAL_INLINE void Spi_lQSPIHwKernelReset(uint32 Module);
#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
static void Spi_lHwDmaResetSfr(void);
#endif
#endif

/* Function to set the Spi Channel configuration parameters in Hw */
static void Spi_lHwSetChannelConfig(volatile uint32 Module,
            const Spi_ChannelConfigType* ChannelConfigPtr, uint32 TransferCount,
            uint8 IsLastChannel, uint32 DelayAndHwChNo,
            const Spi_JobConfigType* JobConfigPtr);

#if (SPI_LEVEL_DELIVERED == 2U)
/* Function to Set the Asynchronous mode to Interrupt */
static void Spi_lHwSetAsyncModeToIntr(void);
/* Function to Set the Asynchronous mode to Polling mode */
static void Spi_lHwSetAsyncModeToPoll(void);
#endif

#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
/*Function to Initialise Dma Hw used for Spi during Hw initialisation*/
static void Spi_lHwDmaInit(void);
/*Function to De-Initialise Dma Hw used for Spi during Hw De-initialisation*/
static void Spi_lHwDmaDeInit(void);
/*Function to Start transfer of Dma Tx/Rx Channels */
static void Spi_lHwDmaStartTransferRuntime
(
const Spi_DataType* DmaTxSrcPtr, Spi_DataType* DmaRxDestPtr,
uint32 DmaTransferCount,
uint32 PackedVar,
const Spi_JobConfigType* JobConfigPtr
);
static void Spi_lHwDmaStartTransferIsr
(
const Spi_DataType* DmaTxSrcPtr, Spi_DataType* DmaRxDestPtr,
uint32 DmaTransferCount,
uint32 PackedVar,
const Spi_JobConfigType* JobConfigPtr
);

IFX_LOCAL_INLINE void Spi_lHwUpdateSourceReg(uint32 Module, uint16 DataWidth,
                            const Spi_DataType* DmaTxSrcPtr, uint8 ApiAccessId);
#endif

#if ( (SPI_SLAVE_ENABLE == STD_ON) || (SPI_LEVEL_DELIVERED == 1U) \
                                   || (SPI_LEVEL_DELIVERED == 2U))
static Dma_ErrorStatusType Spi_lDmaGetBothMoveEngErrFlags(uint8 \
                                                                   ApiAccessId);
#endif

/* Functions to Update the QSpi and Dma interrupts  */
#if (SPI_LEVEL_DELIVERED != 0U)
IFX_LOCAL_INLINE void Spi_lHwInitIntr(uint32 Module);
IFX_LOCAL_INLINE void Spi_lHwInitIntr_SV(uint32 Module);
IFX_LOCAL_INLINE void Spi_lHwInitDmaIntr(uint32 Module);
IFX_LOCAL_INLINE void Spi_lHwInitDmaIntr_SV(uint32 Module);
IFX_LOCAL_INLINE void Spi_lHwDeInitIntr(uint32 Module);
IFX_LOCAL_INLINE void Spi_lHwDeInitDmaIntr(uint32 Module);
IFX_LOCAL_INLINE void Spi_lHwDeInitDmaIntr_SV(uint32 Module);
IFX_LOCAL_INLINE void Spi_lHwSetQspiTxIntr(uint32 Module);
IFX_LOCAL_INLINE void Spi_lHwDmaClearIntr(Dma_ChannelType Channel);
static void Spi_lHwDisableQspiTxIntr(uint32 Module,uint8 ApiAccessId);
IFX_LOCAL_INLINE void Spi_lHwEnableQspiTxIntr(uint32 Module);
IFX_LOCAL_INLINE void Spi_lHwEnableQspiRxIntr(uint32 Module, uint8 ApiAccessId);
IFX_LOCAL_INLINE void Spi_lHwSendLastChannelData(uint32 Module, \
                                                             uint8 ApiAccessId);
IFX_LOCAL_INLINE void Spi_lHwEnableQspiErrIntr(uint32 Module, \
                                                             uint8 ApiAccessId);
IFX_LOCAL_INLINE void Spi_lHwDisableQspiPtIntr(uint32 Module);
IFX_LOCAL_INLINE void Spi_lHwDisableQspiPtIntr_SV(uint32 Module);
IFX_LOCAL_INLINE void Spi_lHwEnableQspiPtIntr(uint32 Module);
IFX_LOCAL_INLINE void Spi_lHwDisableQspiUsrIntr(uint32 Module,\
                                                             uint8 ApiAccessId);
IFX_LOCAL_INLINE void Spi_lHwDisableQspiUsrIntr_SV(uint32 Module);
IFX_LOCAL_INLINE void Spi_lHwEnableQspiUsrIntr(uint32 Module);
static void Spi_lDmaSetSourceAddr(Dma_ChannelType Channel,       \
                                             uint32 Address, uint8 ApiAccessId);
IFX_LOCAL_INLINE void Spi_lDmaChClrCtlCfgInit(Dma_ChannelType Channel);
IFX_LOCAL_INLINE void Spi_lDmaChClrCtlCfgDeinit(Dma_ChannelType Channel);
static void Spi_lDmaSetDestAddr(Dma_ChannelType Channel,         \
                                             uint32 Address, uint8 ApiAccessId);
IFX_LOCAL_INLINE void Spi_lDmaChClrIntrFlagsInit(Dma_ChannelType Channel);
IFX_LOCAL_INLINE void Spi_lDmaChClrIntrFlagsDeinit(Dma_ChannelType Channel);
IFX_LOCAL_INLINE void Spi_lDmaEnTransReqLostIntr(Dma_ChannelType Channel);
IFX_LOCAL_INLINE void Spi_lDmaCfgIntControl(Dma_ChannelType Channel,       \
                                                           uint32 value);
IFX_LOCAL_INLINE void Spi_lDmaEnableChIntrTrigger(Dma_ChannelType Channel);
IFX_LOCAL_INLINE void Spi_lDmaClrAdcr(Dma_ChannelType Channel);
IFX_LOCAL_INLINE void Spi_lDmaChClrIntctEtrlFlags(Dma_ChannelType Channel);
IFX_LOCAL_INLINE void Spi_lDmaDisableChIntrTrigger(Dma_ChannelType Channel);
IFX_LOCAL_INLINE void Spi_lDmaClrErrFlags(Dma_ChannelType Channel);
IFX_LOCAL_INLINE void Spi_lDmaCfgMeErrIntr(uint8 Enable);
#endif

#if ( (SPI_SLAVE_ENABLE == STD_ON) || (SPI_LEVEL_DELIVERED != 0U))
IFX_LOCAL_INLINE void Spi_lHwDisableQspiRxIntr(uint32 Module, \
                                                             uint8 ApiAccessId);
IFX_LOCAL_INLINE void Spi_lHwClearErrIntr(uint32 Module);
#endif

#if (SPI_LEVEL_DELIVERED == 2U)
IFX_LOCAL_INLINE void Spi_lHwDisableErrIntr(uint32 Module);
#endif

IFX_INLINE void Spi_lHwDisableModule(uint32 Module, uint8 ApiAccessId);
IFX_INLINE uint32 Spi_lHwGetModuleStatus(uint8 Module);
IFX_INLINE void SPI_lHwUpdateSrcRegister(Ifx_QSPI *ModulePtr, uint32 Value);
IFX_INLINE uint32 SPI_lHwReadDestRegister(const Ifx_QSPI *ModulePtr);
IFX_INLINE void SPI_lHwUpdateSrcRegViaModule(uint32 Module, uint32 Value, \
                                                             uint8 ApiAccessId);
IFX_INLINE void Spi_lHwClrQspiPendEvent(Ifx_QSPI *ModulePtr, uint8 ApiAccessId);
IFX_INLINE uint32 Spi_lHwGetTxStatus(const Ifx_QSPI *ModulePtr);
IFX_INLINE uint32 Spi_lHwGetRxStatus(const Ifx_QSPI *ModulePtr);

/*Removed UNUSED : AI00245695. Spi_lHwSetTxFifoLevel, Spi_lHwSetRxFifoLevel*/

static void Spi_lHwGpioSetPortPin(uint16 CSPin, uint8 CSPolarity, \
                                                             uint8 ApiAccessId);
IFX_INLINE uint32 Spi_lHwGetErrStatus(const Ifx_QSPI *ModulePtr);

/*Memory Map of the SPI Code*/
#define SPI_STOP_SEC_CODE
/*
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
allowed only for MemMap.h*/
#include "MemMap.h"
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*
  used for global or static variables (8 bits) that are initialized
  after every reset
*/
#define SPI_START_SEC_VAR_8BIT

/*
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"

#if (SPI_LEVEL_DELIVERED == 2U)
/* Vaiable that stores the status of the "Async Mode (Interrupt/Polling)" in
   Level 2 driver */
static uint8 Spi_AsyncMode;
#endif
/* (SPI_LEVEL_DELIVERED == 2U) */

/* Variable Stores the Number of IB Channels in the Configuration */
uint8 Spi_NoOfIBChannels;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
/* This variable is used to check the double initialisation */
static uint8 Spi_DriverState;
#endif
/*(SPI_DEV_ERROR_DETECT == STD_ON)*/

#if (SPI_PB_FIXEDADDR == STD_ON)
/*
  This variable is used to check if Init is called before any API called
  in case of fixed address feature used.
*/
static uint8 Spi_InitStatus;
#endif
/*(SPI_PB_FIXEDADDR == STD_ON)*/

#if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)
#if ((SPI_LEVEL_DELIVERED == 0U) || (SPI_LEVEL_DELIVERED == 2U))
#if(SPI_LEVEL2_ASYNC_ONLY == STD_OFF)
/* This is used in case of Concurrent Sync transmission to store the current
   hardware used*/
static uint8 Spi_CurHwUsed;
#endif
#endif
#endif

/*
  used for global or static variables (8 bits) that are initialized
  after every reset
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
#define SPI_STOP_SEC_VAR_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"

/*
 * To be used for all global or static variables (unspecified size )
 * that are never  initialized.
 */
#define SPI_START_SEC_VAR_UNSPECIFIED
/*
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 1U) || (SPI_CHANNEL_BUFFERS_ALLOWED == 2U))
/* EB Buffer Parameters are stored. Needed only when EB Buffer Channels are
   configured */
static Spi_EBBufferType Spi_EBBuffer[SPI_MAXIMUM_EB_CHANNELS];
#endif
/* (SPI_CHANNEL_BUFFERS_ALLOWED == 1U
          || SPI_CHANNEL_BUFFERS_ALLOWED == 2U) */

#if  (SPI_LEVEL_DELIVERED != 0U)
/* This is used to check the bus status to start the communication when first
Spi_AsyncTransmit called.*/
/*Fixed for AI00247957 */
#if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
#if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
static volatile Spi_StatusType Spi_AsyncBusStatus;
#else
static volatile Spi_StatusType Spi_AsyncBusStatus[SPI_NUM_QM_ASYNC_MASTERS];
#endif
#endif
#endif
/*(SPI_LEVEL_DELIVERED != 0U)*/

#if ( SPI_DEBUG_SUPPORT == STD_ON )
/* [cover parentID=DS_AS403_SPI367, DS_AS403_SPI363, DS_AS403_SPI366] */
/*IFX_MISRA_RULE_08_10_STATUS=Requirements SPI367, SPI363,SPI366.
                              External linkage is required.*/
volatile Spi_StatusType Spi_BusStatus;
/* [/cover] */
#else
static volatile Spi_StatusType Spi_BusStatus;
#endif

/* Global QM Variables  */
#if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
#if (SPI_LEVEL_DELIVERED != 0U)
#if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
static Spi_JobAndSeqAccessType Spi_QmJobAndSeqAccess;
#else
static Spi_JobAndSeqAccessType Spi_QmJobAndSeqAccess[SPI_NUM_QM_ASYNC_MASTERS];
#endif
static Spi_ChnlAccessType  Spi_QmChnlAccess[SPI_NUM_QM_ASYNC_MASTERS];
#endif
#endif

#if (SPI_QM_MASTER_MODULES_USED != 0U)
static Spi_QmSeqStatusType Spi_QmSeqStatus[SPI_SEQUENCE_QM_ARRAY_INDEX];
#endif

/*[/cover]*/

#define SPI_STOP_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"


/* The Source and Destination pointers passed to the SPI are
   handled by the DMA in the asynchronous mode. It is necessary
   that these variables full fill the following addressing constraints.
   1. In case of transfer width > 8, the data type is 16bits. Therefore
      it is necessary to have the source and destination pointers
      word aligned. (On a Even Boundary). Use of #pragma align 2 will
      ensure word alignment.
   2. DMA implements a Circular Buffer with a maximum width of 32KB.
      So the Src/Des Ptrs (Starting Address + Length Of data) should not
      span the 32KB Boundary if Sequential data are to be transferred.
      The start address of this section must be selected so that the
      variables do not exceed the 32KB boundary.
      [(DMA_Address & 0x00007FFFU) + Length <= 0x00008000U]

   So it has to be ensured that the section "SPI_START_SEC_VAR_DMA_ACCESS"
   full fills the above stated criteria*/
#define SPI_START_SEC_VAR_DMA_ACCESS
/*
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"

#if (SPI_CHANNEL_BUFFERS_ALLOWED != 1U)
static Spi_IBBufferAccessType Spi_IBBufferAccess;
#endif

#define SPI_STOP_SEC_VAR_DMA_ACCESS
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"

#define SPI_START_SEC_ASIL0_VAR_UNSPECIFIED
/*
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"

#if  (SPI_LEVEL_DELIVERED != 0U)
/* if ASIL master module is ASYNC */
#if (SPI_ASIL_MASTER_ASYNC_USED == STD_ON)
static volatile Spi_StatusType Spi_AsilAsyncBusStatus;
#endif
#endif
/*(SPI_LEVEL_DELIVERED != 0U)*/

/*[cover parentID=
DS_MCAL_SPI_9821,
SAS_MCAL_SPI_9846] */
/* Global ASIL Variables  */
#if (SPI_SAFETY_ENABLE == STD_ON)
  #if (SPI_LEVEL_DELIVERED != 0U)
  static Spi_JobAndSeqAccessType Spi_AsilJobAndSeqAccess;
  static Spi_ChnlAccessType     Spi_AsilChnlAccess[SPI_NUM_ASIL_MASTER_MODULES];
  #endif
  static Spi_AsilSeqStatusType Spi_AsilSeqStatus[SPI_SEQUENCE_ASIL_ARRAY_INDEX];
#endif
/*(SPI_SAFETY_ENABLE == STD_ON) */
/*[/cover]*/

#define SPI_STOP_SEC_ASIL0_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"

/*
 * To be used for all global or static variables (32 bits )
 * that have at least one of  the following properties
 * 1. accessed bitwise  2. frequently used
 * 3. high number of accesses in source code
 */
/* In addition note that these variables are also accessed by the LDMST and
   SWAP instruction. This instruction makes it mandatory for these variables to
   be 32 aligned and also be with in the first 16K boundary.
   The section "FAST" is always assigned to the near bss which ensures that the
   nearest memory is assigned for this variable. */
/* These variables must be initialized to 0 after every reset */
#define SPI_START_SEC_VAR_FAST_32BIT
/*
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"

#if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_OFF)
#if ((SPI_LEVEL_DELIVERED == 0U) || (SPI_LEVEL_DELIVERED == 2U))
#if(SPI_LEVEL2_ASYNC_ONLY == STD_OFF)
/* Resource Protection Flags for SPI Bus resource (using binary semaphore)
   This is used only in case of Sync Mode transmission */
static uint32 Spi_SyncLock;
#endif /* SPI_LEVEL2_ASYNC_ONLY == STD_OFF */
#endif
#endif
/* (SPI_LEVEL_DELIVERED == 0) || (SPI_LEVEL_DELIVERED == 2U) */

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 1U) || (SPI_CHANNEL_BUFFERS_ALLOWED == 2U))
/* The following dummy variables are needed only for EB Buffer channels*/
#if (SPI_LEVEL_DELIVERED != 0U)
/* Used Only in Async Mode when DMA is used.*/
/* Dummy Read Address if destination pointer of the EB channel is NULL */
static volatile uint32 Spi_DMARXDummy;

#endif
/* (SPI_LEVEL_DELIVERED != 0) */
#endif
/* (SPI_CHANNEL_BUFFERS_ALLOWED == 1U
          || SPI_CHANNEL_BUFFERS_ALLOWED == 2U) */

/*
  used for global or static variables (8 bits) that are initialized
  after every reset
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
#define SPI_STOP_SEC_VAR_FAST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"

/*
 * To be used for global or static variables (32 bits) that are initialized
 * after every reset (the normal case)
 */
#define SPI_START_SEC_VAR_32BIT

/*
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"
/* These variables must be initialized to 0 after every reset */

#if (SPI_PB_FIXEDADDR == STD_OFF)
/* Variable Holds the Configuration Pointer given in Spi_Init */
const Spi_ConfigType* Spi_kConfigPtr;
#endif
/*(SPI_PB_FIXEDADDR == STD_OFF)*/

/*
  used for global or static variables (8 bits) that are initialized
  after every reset
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
/* Global QM Variables  */
/* Variable to Hold Job Result. */
#if (SPI_QM_MASTER_MODULES_USED != 0U)
uint32 Spi_QmJobResult[SPI_JOB_QM_ARRAY_INDEX];
#endif

#define SPI_STOP_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"

#define SPI_START_SEC_ASIL0_VAR_32BIT
/*
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"
/* Global ASIL Variables  */
#if (SPI_SAFETY_ENABLE == STD_ON)
  /* Variable to Hold Job Result. */
  uint32 Spi_AsilJobResult[SPI_JOB_ASIL_ARRAY_INDEX];
#endif
/*(SPI_SAFETY_ENABLE == STD_ON) */
#define SPI_STOP_SEC_ASIL0_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"

/*
  To be used for global or static constants (32 bits)
 */
#define SPI_START_SEC_CONST_32BIT

/*
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"

#if (SPI_PB_FIXEDADDR == STD_ON)
/* Variable Holds the Configuration Pointer given in Spi_Init */
const Spi_ConfigType* const Spi_kConfigPtr = &Spi_ConfigRoot[0U];
#endif
/*(SPI_PB_FIXEDADDR == STD_ON)*/

#define SPI_STOP_SEC_CONST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*Memory Map of the SPI Code*/
#define SPI_START_SEC_CODE
/*
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
  allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI175_SPI298_SPI299,DS_AS_SPI012,
DS_AS_SPI015, DS_AS_SPI017,DS_AS_SPI082,DS_AS_SPI151,DS_AS_SPI233,
DS_AS_SPI234,DS_NAS_SPI_PR913, DS_NAS_HE2_SPI_PR3023, DS_NAS_EP_SPI_PR3023]
** Syntax : void Spi_Init(const Spi_ConfigType* ConfigPtr)                    **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x00                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  ConfigPtr - Pointer to configuration set                **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Driver Module Initialization function                        **
** Service for SPI initialization. The Initialization function                **
** initialize all SPI relevant registers with the values of the structure     **
** referenced by the parameter ConfigPtr.                                     **
** For Level2 this Function set the Handler/Driver Asynchronous Mechanism     **
** Mode in POLLING MODE and all the interrupts disabled                       **
*******************************************************************************/
#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
void Spi_Init(const Spi_ConfigType* ConfigPtr)
{
  uint32 Index;
  #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
  uint32 QmModIndex;
  #endif
  #if (SPI_CHANNEL_BUFFERS_ALLOWED != 1U)
  uint32 BufferIndex;
  const Spi_ChannelConfigType* ChannelConfigPtr;
  #endif

  Std_ReturnType ReturnStatus;

  #if ((SPI_CHANNEL_BUFFERS_ALLOWED == 1U) || \
       (SPI_CHANNEL_BUFFERS_ALLOWED == 2U))
  Spi_EBBufferType* EBBufferPtr;
  #endif
  /* ((SPI_CHANNEL_BUFFERS_ALLOWED == 1U) || \
       (SPI_CHANNEL_BUFFERS_ALLOWED == 2U)) */

  /* if DET detection or Safety switched On */
  #if ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) )
    ReturnStatus = E_OK;

  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  if (Spi_DriverState == SPI_DRIVER_INITIALIZED)
  {
    Det_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_INIT, SPI_E_ALREADY_INITIALIZED );

    ReturnStatus = E_NOT_OK;
  }
  else
  #endif
  /* (SPI_DEV_ERROR_DETECT == STD_ON) */

  /* The ConfigPtr is expected to be a NULL_PTR in case of Pre Compile Variant
     delivery */
  #if (SPI_PB_FIXEDADDR == STD_ON)
  if (Spi_kConfigPtr != ConfigPtr)
  #else
  if (ConfigPtr == NULL_PTR)
  #endif
  /*(SPI_PB_FIXEDADDR == STD_ON)*/
  {
    /* Report to  DET */
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    Det_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_INIT, SPI_E_PARAM_CONFIG );
    #endif
    /* (SPI_DEV_ERROR_DETECT == STD_ON) */

    #if (SPI_SAFETY_ENABLE == STD_ON)
    SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_INIT, SPI_E_PARAM_CONFIG );
     /* [cover parentID=DS_MCAL_SPI_9841_01][/cover] */
    #endif
    /* (SPI_SAFETY_ENABLE == STD_ON) */

    /* Return from Function upon error */
    ReturnStatus = E_NOT_OK;
  }
  else
  {
    /*Do Nothing*/
  } /* (Spi_kConfigPtr != ConfigPtr) */

  #if (SPI_SAFETY_ENABLE == STD_ON)
  if ((ReturnStatus == E_OK) &&
      (ConfigPtr->SafetyMarker != ((uint32)SPI_MODULE_ID << 16U)))
  {
    /* report to upper layer */
    SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_INIT, SPI_E_PARAM_CONFIG );
     /* [cover parentID=DS_MCAL_SPI_9841_01][/cover] */
    ReturnStatus = E_NOT_OK;
  }
  #endif
  /* (SPI_SAFETY_ENABLE == STD_ON) */

  if (ReturnStatus == E_OK)
  #endif
  /*( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) )  */
  {

    #if (SPI_PB_FIXEDADDR == STD_OFF)
    Spi_kConfigPtr = ConfigPtr;  /* Store ConfigPtr for use by APIs*/
    #endif

    #if (SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)
      /* Workaround for MISRA 2004 Rule 1.2 */
      Index = 0U;
      #if(SPI_MAX_JOB_TRIG_Q_LENGTH > 1U)
      do
      {
      #endif
        #if (SPI_SAFETY_ENABLE == STD_ON)
        Spi_AsilJobAndSeqAccess.JobQueueRearrange[Index]          = 0U;
        Spi_AsilJobAndSeqAccess.JobLinkedSequenceRearrange[Index] = 0U;
        #endif

        #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
        #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
        Spi_QmJobAndSeqAccess.JobQueueRearrange[Index]            = 0U;
        Spi_QmJobAndSeqAccess.JobLinkedSequenceRearrange[Index]   = 0U;
        #else
        QmModIndex = 0U;
        #if(SPI_NUM_QM_ASYNC_MASTERS > 1U)
        do
        {
        #endif
         Spi_QmJobAndSeqAccess[QmModIndex].JobQueueRearrange[Index] = 0U;
         Spi_QmJobAndSeqAccess[QmModIndex].JobLinkedSequenceRearrange[Index]= \
                                                                            0U;
        #if(SPI_NUM_QM_ASYNC_MASTERS > 1U)
          QmModIndex++;
        }while(QmModIndex < SPI_NUM_QM_ASYNC_MASTERS);
        #endif

        #endif
        #endif
      #if(SPI_MAX_JOB_TRIG_Q_LENGTH > 1U)
        Index++;
      }while(Index < SPI_MAX_JOB_TRIG_Q_LENGTH);
      #endif
    #endif
    /*(SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON) */

   /* Tx,Rx Dma Channel no's are copied to Global variable from Configuration*/
    Index = 0U;
    #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
    QmModIndex = 0U;
    #endif
    do
    {
      #if (SPI_SAFETY_ENABLE == STD_ON)
      if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)Index))
      {
         /*  NULL_PTR check is not needed since ASIL master is mandated to be
             configured for ASYNC transmission with valid DMA channels */

         /* SPI_NUM_ASIL_MASTER_MODULES is always 1 hence index of 0 is used */
         Spi_AsilChnlAccess[0U].DmaChannelIdx.TxDmaChannel =
            ConfigPtr->HWModuleConfigPtr[Index]->SpiDmaConfigPtr->TxDmaChannel;

         Spi_AsilChnlAccess[0U].DmaChannelIdx.RxDmaChannel =
            ConfigPtr->HWModuleConfigPtr[Index]->SpiDmaConfigPtr->RxDmaChannel;
      }
      else
      #endif
      {
        if(Spi_lModuleConfiguredAndAsync((uint8)Index) != 0U)
        {
          #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
          Spi_QmChnlAccess[QmModIndex].DmaChannelIdx.TxDmaChannel =
            ConfigPtr->HWModuleConfigPtr[Index]->SpiDmaConfigPtr->TxDmaChannel;

          Spi_QmChnlAccess[QmModIndex].DmaChannelIdx.RxDmaChannel =
            ConfigPtr->HWModuleConfigPtr[Index]->SpiDmaConfigPtr->RxDmaChannel;

          /* Increment only if module is configured as QM master module */
          QmModIndex++;
          #endif
        }
      }
      Index++;
    }while  (Index < SPI_MAX_HW_UNIT);

    /* HW initilisation */
    ReturnStatus = Spi_lHwInit(ConfigPtr);

    if(ReturnStatus == E_OK)
    {
      #if (SPI_SLAVE_ENABLE == STD_ON)
      ReturnStatus = ReturnStatus | Spi_lSlaveInit(ConfigPtr);

      if(ReturnStatus == E_OK)
      #endif
      {
    /*  ------------------------------------------------------------------ **
    **                 SPI Channel Initialization                          **
    **  ------------------------------------------------------------------ */
        /*
          This Init function shall define defaults values for needed
          parameters of the structure referenced by the ConfigPtr
        */
        Spi_NoOfIBChannels = 0U; /* Reset Number of IB Channels */
        Index = 0U;
        #if (SPI_CHANNEL_BUFFERS_ALLOWED != 1U)
        BufferIndex = 0U;
        ChannelConfigPtr = ConfigPtr->SpiChannelConfigPtr;
        #endif
        /* (SPI_CHANNEL_BUFFERS_ALLOWED != 1U) */

        do
        {
          #if (SPI_CHANNEL_BUFFERS_ALLOWED == 2U)
          if (ChannelConfigPtr->ChannelBufferType == SPI_IB_BUFFER)
          #endif
          /*(SPI_CHANNEL_BUFFERS_ALLOWED == 2U)*/
          #if (SPI_CHANNEL_BUFFERS_ALLOWED != 1U)
          {
            /* Store Buffer Offset Position for IB Channels */
            Spi_IBBufferAccess.IBBufferOffset[Index] = (uint16)BufferIndex;
            BufferIndex = BufferIndex + (uint32)ChannelConfigPtr->NoOfBuffers;
         /*Store the Maximum IB buffer channel for the current configuration */
            Spi_NoOfIBChannels++;
          }
       /*IFX_MISRA_RULE_17_04_STATUS="ChannelConfigPtr" Pointer arithmetic used
            due to PBConfigStructure and is within allowed range.*/
          ChannelConfigPtr++;
          #endif
          /*(SPI_CHANNEL_BUFFERS_ALLOWED != 1U)*/
          Index++;
        }while (Index < (uint32)ConfigPtr->NoOfChannels);
        /* loop to update the IB */

        #if (SPI_CHANNEL_BUFFERS_ALLOWED != 0U)
        /* Initailize Index to the last channel i.e Max Channel */
        Index = (uint32)ConfigPtr->NoOfChannels - (uint32)(Spi_NoOfIBChannels);
        do
        {
          Index--;
          EBBufferPtr = &(Spi_EBBuffer[Index]); /* Get EB_Buffer Pointer */
          EBBufferPtr->DestPtr = NULL_PTR;  /* Set EB Dest Pointer to NULL*/
          EBBufferPtr->SrcPtr  = NULL_PTR;  /* Set EB Src Pointer to NULL */
          EBBufferPtr->Length  = (Spi_NumberOfDataType)0; /*Set EB Length = 0*/
        }while (Index > 0U);
        #endif
        /*(SPI_CHANNEL_BUFFERS_ALLOWED != 0) */

      /*  ------------------------------------------------------------------ **
      **                 Global Variable Initialization                      **
      **  ------------------------------------------------------------------ */
       /*
         After having finished the module initialization,
        the SPI Handler/Driver state shall be set to SPI_IDLE and set the
        Sequences result shall be set to SPI_SEQ_OK and the jobs result
        shall be set to SPI_JOB_OK.
       */

        /* Set SPI Bus Status to Idle */
        Spi_lSetAsyncBusStatus((Spi_StatusType)SPI_IDLE);

        Spi_BusStatus = SPI_IDLE; /* Set SPI Bus Status to Idle */
        #if (SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)
          Index = ConfigPtr->NoOfSequences; /*Set Index to the last Sequence */
          do
          {
            Index--;
            /* Set each Sequence Status to SPI_SEQ_OK */
            #if (SPI_SAFETY_ENABLE == STD_ON)
            Spi_AsilJobAndSeqAccess.CurrentJobIndex[Index] = 0U;
            #endif

            #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
            #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
            Spi_QmJobAndSeqAccess.CurrentJobIndex[Index] = 0U;
            #else
            QmModIndex = 0U;
            #if(SPI_NUM_QM_ASYNC_MASTERS > 1U)
            do
            {
            #endif
              Spi_QmJobAndSeqAccess[QmModIndex].CurrentJobIndex[Index] = 0U;
            #if(SPI_NUM_QM_ASYNC_MASTERS > 1U)
              QmModIndex++;
            }while(QmModIndex < SPI_NUM_QM_ASYNC_MASTERS);
            #endif
            #endif
            /* SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF */
            #endif
            /* SPI_QM_ASYNC_MASTER_MODULES_USED != 0U */
          }while (Index > 0U);

        /* if SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_OFF */
        #else
          #if (SPI_SAFETY_ENABLE == STD_ON)
          Spi_AsilJobAndSeqAccess.CurrentJobIndex = 0U;
          #endif

          #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
          #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
          Spi_QmJobAndSeqAccess.CurrentJobIndex = 0U;
          #else
          QmModIndex = 0U;
          #if(SPI_NUM_QM_ASYNC_MASTERS > 1U)
          do
          {
          #endif
            Spi_QmJobAndSeqAccess[QmModIndex].CurrentJobIndex = 0U;
          #if(SPI_NUM_QM_ASYNC_MASTERS > 1U)
            QmModIndex++;
          }while(QmModIndex < SPI_NUM_QM_ASYNC_MASTERS);
          #endif

          #endif
          #endif
        #endif
        /*(SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)*/

        #if (SPI_CHANNEL_BUFFERS_ALLOWED != 1U)
        /* clear the status variable ChannelWriteLock */
        Spi_lClearChannelWriteLock();
        #endif
        /*(SPI_CHANNEL_BUFFERS_ALLOWED != 1U) */

        /* Job Result status to SPI_JOB_OK */
        Spi_lClearJobResultStatus();
        /* Sequence status to SPI_SEQ_OK */
        Spi_lClearSequenceStatus();

        /* Set Sequence Status to not active in the Sequence Queue */
        Index = 0U;
        #if(SPI_MAX_JOB_TRIG_Q_LENGTH > 1U)
        do
        {
        #endif
          #if (SPI_SAFETY_ENABLE == STD_ON)
          Spi_AsilJobAndSeqAccess.JobLinkedSeq[Index] = SPI_SEQ_IDLE_ID;
          Spi_AsilJobAndSeqAccess.JobQueue[Index]     = SPI_JOB_IDLE_ID;
          #endif

          #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
          #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
          Spi_QmJobAndSeqAccess.JobLinkedSeq[Index]   = SPI_SEQ_IDLE_ID;
          Spi_QmJobAndSeqAccess.JobQueue[Index]       = SPI_JOB_IDLE_ID;
          #else
          QmModIndex = 0U;
          #if(SPI_NUM_QM_ASYNC_MASTERS > 1U)
          do
          {
          #endif
            Spi_QmJobAndSeqAccess[QmModIndex].JobLinkedSeq[Index] = \
                                                               SPI_SEQ_IDLE_ID;
            Spi_QmJobAndSeqAccess[QmModIndex].JobQueue[Index] =     \
                                                               SPI_JOB_IDLE_ID;
          #if(SPI_NUM_QM_ASYNC_MASTERS > 1U)
            QmModIndex++;
          }while(QmModIndex < SPI_NUM_QM_ASYNC_MASTERS);
          #endif

          #endif
          #endif
        #if(SPI_MAX_JOB_TRIG_Q_LENGTH > 1U)
          Index++;
        }while (Index < SPI_MAX_JOB_TRIG_Q_LENGTH);
        #endif

        #if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_OFF)
          #if (SPI_LEVEL_DELIVERED == 2U)
           #if(SPI_LEVEL2_ASYNC_ONLY == STD_OFF)
           Spi_SyncLock = 0U;
           #endif /* SPI_LEVEL2_ASYNC_ONLY == STD_OFF */
          #endif
        #else
          #if (SPI_LEVEL_DELIVERED == 2U)
            #if(SPI_LEVEL2_ASYNC_ONLY == STD_OFF)
            Spi_CurHwUsed = 0U;
            #endif
          #endif
        #endif

        /*
          For LEVEL 2, this function sets the SPI
          Handler/Driver asynchronous mechanism mode to SPI_POLLING_MODE by
          default. Interrupts related to SPI busses shall be disabled.
        */
        #if (SPI_LEVEL_DELIVERED == 2U)
        Spi_AsyncMode = (uint8)SPI_POLLING_MODE;
        #endif
        /* (SPI_LEVEL_DELIVERED == 2U) */

        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        Spi_DriverState = SPI_DRIVER_INITIALIZED;
        #endif
        /*(SPI_DEV_ERROR_DETECT == STD_ON)*/

        #if (SPI_PB_FIXEDADDR == STD_ON)
        Spi_InitStatus = SPI_DRIVER_INITIALIZED;
        #endif
        /*(SPI_PB_FIXEDADDR == STD_ON)*/
      }
    }
    if(ReturnStatus == E_NOT_OK)
    {
      #if (SPI_DEV_ERROR_DETECT == STD_ON)
      Spi_DriverState = SPI_DRIVER_DEINITIALIZED;
      #endif
      /*(SPI_DEV_ERROR_DETECT == STD_ON)*/

      #if (SPI_PB_FIXEDADDR == STD_ON)
      Spi_InitStatus = SPI_DRIVER_DEINITIALIZED;
      #else
      Spi_kConfigPtr = NULL_PTR;
      #endif
      /*(SPI_PB_FIXEDADDR == STD_ON)*/

      #if (SPI_SAFETY_ENABLE == STD_ON)
      /* report to upper layer */
      SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
          SPI_SID_INIT, SPI_E_CLC_ERROR );
      #endif
    }
  }
}/* End of Function: Spi_Init */
#endif
/* (SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U) */

/*******************************************************************************
** Syntax : void Spi_Init(const Spi_ConfigType* ConfigPtr)                    **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x00                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  ConfigPtr - Pointer to configuration set                **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Driver Module Initialization function                        **
** Service for SPI initialization. The Initialization function                **
** initialize all SPI relevant registers with the values of the structure     **
** referenced by the parameter ConfigPtr.                                     **
*******************************************************************************/
#if (SPI_LEVEL_DELIVERED == 0U)
void Spi_Init(const Spi_ConfigType* ConfigPtr)
{
  #if (SPI_CHANNEL_BUFFERS_ALLOWED != 1U)
  uint32 BufferIndex;
  const Spi_ChannelConfigType* ChannelConfigPtr;
  #endif
  uint32 Index;
  #if (SPI_CHANNEL_BUFFERS_ALLOWED != 0U)
  Spi_EBBufferType* EBBufferPtr;
  #endif
  Std_ReturnType ReturnStatus;

  /* if DET detection or Safety switched On */
  #if ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) )
  ReturnStatus = E_OK;

  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  if ( Spi_DriverState == SPI_DRIVER_INITIALIZED )
  {

    Det_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_INIT, SPI_E_ALREADY_INITIALIZED );
    /* Return from Function upon error */
    ReturnStatus = E_NOT_OK;
  }
  else
  #endif
  /* (SPI_DEV_ERROR_DETECT == STD_ON) */

  /* The ConfigPtr is expected to be a NULL_PTR in case of Pre Compile Variant
     delivery */
  #if (SPI_PB_FIXEDADDR == STD_ON)
  if (Spi_kConfigPtr != ConfigPtr)
  #else
  if (ConfigPtr == NULL_PTR)
  #endif
  /*(SPI_PB_FIXEDADDR == STD_ON)*/
  {
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    Det_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_INIT, SPI_E_PARAM_CONFIG );
    #endif
    /* (SPI_DEV_ERROR_DETECT == STD_ON) */

    #if (SPI_SAFETY_ENABLE == STD_ON)
    SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_INIT, SPI_E_PARAM_CONFIG );
     /* [cover parentID=DS_MCAL_SPI_9841_01][/cover] */
    #endif
    /* (SPI_SAFETY_ENABLE == STD_ON) */

    /* Return from Function upon error */
    ReturnStatus = E_NOT_OK;
  }
  else
  {
    /*Do Nothing*/
  } /* (Spi_kConfigPtr != ConfigPtr)*/

  #if (SPI_SAFETY_ENABLE == STD_ON)
  if ((ReturnStatus == E_OK) &&
      (ConfigPtr->SafetyMarker != ((uint32)SPI_MODULE_ID << 16U)))
  {
    /* report to upper layer */
    SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_INIT, SPI_E_PARAM_CONFIG );
     /* [cover parentID=DS_MCAL_SPI_9841_01][/cover] */
    ReturnStatus = E_NOT_OK;
  }
  #endif
  /* (SPI_SAFETY_ENABLE == STD_ON) */

  if (ReturnStatus == E_OK)
  #endif
  /*( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) ) */
  {
    #if (SPI_PB_FIXEDADDR == STD_OFF)
    Spi_kConfigPtr = ConfigPtr;  /* Store ConfigPtr for use by APIs */
    #endif

    /* Spi HW initialisation */
    ReturnStatus = Spi_lHwInit(ConfigPtr);

    if(ReturnStatus == E_OK)
    {
      #if (SPI_SLAVE_ENABLE == STD_ON)
      ReturnStatus = ReturnStatus | Spi_lSlaveInit(ConfigPtr);

      if(ReturnStatus == E_OK)
      #endif
      {
    /*  ------------------------------------------------------------------ **
    **                 SPI Channel Initialization                          **
    **  ------------------------------------------------------------------ */
        /*
          This Init function shall define defaults values for needed
          parameters of the structure referenced by the ConfigPtr
        */
        Spi_NoOfIBChannels = 0U; /* Reset Number of IB Channels */
        Index = 0U;

        #if (SPI_CHANNEL_BUFFERS_ALLOWED != 1U)
        BufferIndex = 0U;
        ChannelConfigPtr = ConfigPtr->SpiChannelConfigPtr;
        #endif
        /* (SPI_CHANNEL_BUFFERS_ALLOWED != 1U) */
        do
        {
          #if (SPI_CHANNEL_BUFFERS_ALLOWED == 2U)
          if (ChannelConfigPtr->ChannelBufferType == SPI_IB_BUFFER)
          #endif
          /*(SPI_CHANNEL_BUFFERS_ALLOWED == 2U)*/
          #if (SPI_CHANNEL_BUFFERS_ALLOWED != 1U)
          {
            /* Store Buffer Offset Position for IB Channels */
            Spi_IBBufferAccess.IBBufferOffset[Index] = (uint16)BufferIndex;
            BufferIndex = BufferIndex + (uint32)ChannelConfigPtr->NoOfBuffers;
          /*Store the Maximum IB buffer Channel for the current configuration */
            Spi_NoOfIBChannels++;
          }
       /*IFX_MISRA_RULE_17_04_STATUS="ChannelConfigPtr" Pointer arithmetic used
            due to PBConfigStructure and is within allowed range.*/
          ChannelConfigPtr++;
          #endif
          /*(SPI_CHANNEL_BUFFERS_ALLOWED != 1U) */
          Index++;
        }while (Index < (uint32)ConfigPtr->NoOfChannels);

        #if (SPI_CHANNEL_BUFFERS_ALLOWED != 0U)
        /* Initialize Index to the last channel i.e Max Channel */
        Index = (uint32)ConfigPtr->NoOfChannels - (uint32)(Spi_NoOfIBChannels);
        do
        {
          Index--;
          EBBufferPtr = &(Spi_EBBuffer[Index]); /* Get EB_Buffer Pointer */
          EBBufferPtr->DestPtr = NULL_PTR; /* Set EB Dest Pointer to NULL */
          EBBufferPtr->SrcPtr  = NULL_PTR;  /* Set EB Source Pointer to NULL */
          EBBufferPtr->Length  = (Spi_NumberOfDataType)0; /*Set EB Length = 0*/
        }while (Index > 0U);
        #endif
        /*(SPI_CHANNEL_BUFFERS_ALLOWED != 0) */

      /*  ------------------------------------------------------------------ **
      **                 Global Variable Initialization                      **
      **  ------------------------------------------------------------------ */
      #if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_OFF)
       Spi_SyncLock = 0U;
      #else
       #if(SPI_LEVEL2_ASYNC_ONLY == STD_OFF)
       Spi_CurHwUsed = 0U;
       #endif
      #endif
       Spi_BusStatus = SPI_IDLE;
       /*
        After having finished the module initialization,
        the SPI Handler/Driver state shall be set to SPI_IDLE and set the
        Sequences result shall be set to SPI_SEQ_OK and the jobs result
        shall be set to SPI_JOB_OK.
       */
        #if (SPI_CHANNEL_BUFFERS_ALLOWED != 1U)
        /* Clear the status variable ChannelWriteLock */
        Spi_lClearChannelWriteLock();
        #endif
        /* (SPI_CHANNEL_BUFFERS_ALLOWED != 1U) */

        /* Set Job Result status to SPI_JOB_OK */
        Spi_lClearJobResultStatus();

        /* Set Sequence status to SPI_SEQ_OK */
        Spi_lClearSequenceStatus();

        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        Spi_DriverState = SPI_DRIVER_INITIALIZED;
        #endif
        /*(SPI_DEV_ERROR_DETECT == STD_ON)*/

        #if (SPI_PB_FIXEDADDR == STD_ON)
        Spi_InitStatus = SPI_DRIVER_INITIALIZED;
        #endif
        /*(SPI_PB_FIXEDADDR == STD_ON)*/
      }
    }
    if(ReturnStatus == E_NOT_OK)
    {
      #if (SPI_DEV_ERROR_DETECT == STD_ON)
      Spi_DriverState = SPI_DRIVER_DEINITIALIZED;
      #endif
      /*(SPI_DEV_ERROR_DETECT == STD_ON)*/

      #if (SPI_PB_FIXEDADDR == STD_ON)
      Spi_InitStatus = SPI_DRIVER_DEINITIALIZED;
      #else
      Spi_kConfigPtr = NULL_PTR;
      #endif
      /*(SPI_PB_FIXEDADDR == STD_ON)*/

      #if (SPI_SAFETY_ENABLE == STD_ON)
      /* report to upper layer */
      SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
            SPI_SID_INIT, SPI_E_CLC_ERROR );
      #endif
    }
  }
}/* End of Function: Spi_Init */
#endif
/*(SPI_LEVEL_DELIVERED == 0U)*/

/*******************************************************************************
** Traceability : [cover parentID=DS_MCAL_SPI_9802,DS_MCAL_SPI_9803,          **
DS_MCAL_SPI_9846,SAS_MCAL_SPI_9804,DS_NAS_SPI_PR123]                          **
**                                                                            **
** Syntax : Std_ReturnType Spi_InitCheck(const Spi_ConfigType* ConfigPtr)     **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  ConfigPtr - Pointer to configuration set                **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  Std_ReturnType                                          **
**                                                                            **
** Description      : This function checks is the initialization of the       **
**                    SPI hardware unit and driver done according to the      **
**                    configuration set referenced by ConfigPtr.              **
*******************************************************************************/
#if (SPI_SAFETY_ENABLE == STD_ON)
#if (SPI_INITCHECK_API == STD_ON)
Std_ReturnType Spi_InitCheck(const Spi_ConfigType* ConfigPtr)
{
  const Spi_HWModuleConfigType* HWModuleConfigPtr;
  uint32                        ReadValue;
  volatile uint32               CompareValue;
  uint8                         ModLoopCtr;
  Std_ReturnType                RetVal;

  CompareValue = SPI_INITCHK_COMP_VALUE;
  RetVal = E_NOT_OK;

  if (Spi_kConfigPtr == ConfigPtr)
  {
    /* fix for AI00238516 Point.1*/
    RetVal = E_OK;
    ModLoopCtr = 0U;

    /* To avoid multiple if conditions, storing in CompareFlag */
    /* Comparison to be done for initialization done by Spi_Init() */

    /* Check for all the SFRs common for all levels */
    do
    {
      if(Spi_lModuleConfigured((uint8)ModLoopCtr) != 0U)
      {
        HWModuleConfigPtr = (ConfigPtr->HWModuleConfigPtr[ModLoopCtr]);

       /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
          to efficiently access the SFRs of multiple QSPI Modules.*/
        ReadValue = (uint32)SPI_SFR_INIT_USER_MODE_READ32\
                                            (SPI_HW_MODULE[ModLoopCtr].CLC.U);
        CompareValue &= (ReadValue ^ ~((uint32)
                                             HWModuleConfigPtr->HWClkSetting));

        if(CompareValue != SPI_INITCHK_COMP_VALUE)
        {
           break;
        }

       /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
          to efficiently access the SFRs of multiple QSPI Modules.*/
        ReadValue = (uint32)SPI_SFR_INIT_USER_MODE_READ32\
                                        (SPI_HW_MODULE[ModLoopCtr].GLOBALCON.U);
        CompareValue &= (ReadValue ^ ~((uint32)SPI_QSPI_GLOBCON_RSTVAL));

       /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
          to efficiently access the SFRs of multiple QSPI Modules.*/
       ReadValue = (uint32)SPI_SFR_INIT_USER_MODE_READ32\
                                            (SPI_HW_MODULE[ModLoopCtr].PISEL.U);
       CompareValue &= (ReadValue ^ ~((uint32)HWModuleConfigPtr->HWPinSetting));

       /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
          to efficiently access the SFRs of multiple QSPI Modules.*/
       ReadValue = (uint32)SPI_SFR_INIT_USER_MODE_READ32\
                                            (SPI_HW_MODULE[ModLoopCtr].SSOC.U);
       CompareValue &= \
               (ReadValue ^ ~((uint32)HWModuleConfigPtr->HWCSPolaritySetting));

      }
      ModLoopCtr++;
    }while  (ModLoopCtr < SPI_MAX_HW_UNIT);

    if(CompareValue == SPI_INITCHK_COMP_VALUE)
    {
       #if(SPI_BAUDRATE_AT_RUNTIME == STD_OFF)
       /*Check the ECON register values */
       RetVal = RetVal | Spi_lHwCheckConfigExtn(ConfigPtr);
       #endif /* SPI_BAUDRATE_AT_RUNTIME == STD_OFF */

       #if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
       /* Checking DMA specific registers */
       RetVal = RetVal | Spi_lHwDmaSfrInitCheck();

       ModLoopCtr = 0U;
       do
       {
         if(Spi_lModuleConfiguredAndAsync((uint8)ModLoopCtr) != 0U)
         {
           /* write only - hence ignored
             IntrSrc.CLRR,SWSCLR and IOVCLR are write only bits */
           ReadValue = (uint32)((uint32)(SPI_IRQ_SFR_INIT_USER_MODE_READ32\
                                        (MODULE_SRC.QSPI.QSPI[ModLoopCtr].RX.U)\
                        & SPI_SRC_QSPI_RX_SRE_CLEARMASK)>>IFX_SRC_SRCR_SRE_OFF);
           CompareValue &= (ReadValue ^ ~((uint32)1U));

           ReadValue = (uint32)((uint32)(SPI_IRQ_SFR_INIT_USER_MODE_READ32\
                                        (MODULE_SRC.QSPI.QSPI[ModLoopCtr].TX.U)\
                        & SPI_SRC_QSPI_TX_SRE_CLEARMASK)>>IFX_SRC_SRCR_SRE_OFF);
           CompareValue &= (ReadValue ^ ~((uint32)0U));
         }
         ModLoopCtr++;
       }while(ModLoopCtr < SPI_MAX_HW_UNIT);
       #endif
       /* ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U)) */

       /* Check for all the global variables */
       RetVal = RetVal | Spi_lInitGlobalVarCheck();

       #if (SPI_DEV_ERROR_DETECT == STD_ON)
       CompareValue &= (((uint32)Spi_DriverState) ^
                                          (~(uint32)(SPI_DRIVER_INITIALIZED)));
       #endif
       /*(SPI_DEV_ERROR_DETECT == STD_ON)*/

       #if (SPI_PB_FIXEDADDR == STD_ON)
       CompareValue &= (((uint32)Spi_InitStatus) ^
                                          (~(uint32)(SPI_DRIVER_INITIALIZED)));
       #endif
       /*(SPI_PB_FIXEDADDR == STD_ON)*/

       #if (SPI_SLAVE_ENABLE == STD_ON)
       RetVal = RetVal | Spi_lSlaveInitCheck(ConfigPtr);
       #endif
    }
    if ( (CompareValue != SPI_INITCHK_COMP_VALUE) || (RetVal != E_OK) )
    {
      RetVal = E_NOT_OK;
    }
  }
  return RetVal;
}/* End of Function: Spi_InitCheck */
#endif
/* (SPI_INITCHECK_API == STD_ON) */
#endif
/* (SPI_SAFETY_ENABLE == STD_ON) */

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI176_SPI300_SPI303,DS_AS_SPI021_1,
DS_AS_SPI022,DS_AS_SPI046_1_SPI242_1,DS_AS_SPI256_1,
DS_AS_SPI252_1,DS_AS_SPI301,DS_AS_SPI302,DS_AS_SPI253]                        **
** Syntax : Std_ReturnType Spi_DeInit (void)                                  **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  1                                                             **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK: de-initialisation command has been accepted.       **
**                   E_NOT_OK: de-initialisation command has not been accepted**
**                                                                            **
** Description : Service For SPI Deinitialization                             **
**                                                                            **
*******************************************************************************/
Std_ReturnType Spi_DeInit(void)
{
  uint32 RetVal;
  uint32 Index;
  const Spi_JobConfigType* JobConfigPtr;

  #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
  #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_ON)
  uint32 QmModIndex;
  #endif
  #endif

  #if (SPI_DEV_ERROR_DETECT != STD_ON)
  RetVal = E_OK;
  #endif

  /* API  called before initialization */
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  RetVal = Spi_lGetDetInitStatus(SPI_SID_DEINIT);
  if (RetVal == E_OK)
  #endif
  {
    /* In case of a SPI_BUSY state, command shall be rejected  */
    if (Spi_lGetHwStatus(SPI_DEINIT_ACCESS) == SPI_IDLE)
    {

      /* Set Index to Last Job in the array */
      Index = (uint32)Spi_kConfigPtr->NoOfJobs;
      do
      {
        Index--;
        /* Get Job Configuration based on Job Index */
        /*IFX_MISRA_RULE_17_04_STATUS="SpiJobConfigPtr" Pointer arithmetic used
          due to PBConfigStructure and is within allowed range.*/
        JobConfigPtr = &(Spi_kConfigPtr->SpiJobConfigPtr[Index]);
        /* Disable Chip Select for each Job is the CS is configured */
        if (JobConfigPtr->CSPin != SPI_CS_NONE)
        {
          Spi_lDisableChipSelect_SV(JobConfigPtr->CSPin,\
                                         JobConfigPtr->CSPolarity,\
                                       JobConfigPtr->HwUnit,SPI_DEINIT_ACCESS);
        }
      }while (Index > 0U);

      /* Spi HW De-Initialisation */
      Spi_lHwDeInit();

      /* The SPI Handler/Driver state is set to SPI_UNINIT */
      /*Set Status to indicate that de-initialization is done*/
      #if (SPI_PB_FIXEDADDR == STD_OFF)
      Spi_kConfigPtr = NULL_PTR;        /* Reset Global Config Pointer */
      #endif

      #if (SPI_LEVEL_DELIVERED != 0U)
        Spi_lSetAsyncBusStatus((Spi_StatusType)SPI_IDLE);
        #if (SPI_SAFETY_ENABLE == STD_ON)
          Spi_AsilJobAndSeqAccess.StartIndexExtractJobId = 0U;
          Spi_AsilJobAndSeqAccess.EndIndex               = 0U;
        #endif
        #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
        #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
          Spi_QmJobAndSeqAccess.StartIndexExtractJobId   = 0U;
          Spi_QmJobAndSeqAccess.EndIndex                 = 0U;
        #else
        QmModIndex = 0U;
        #if(SPI_NUM_QM_ASYNC_MASTERS > 1U)
        do
        {
        #endif
          Spi_QmJobAndSeqAccess[QmModIndex].StartIndexExtractJobId   = 0U;
          Spi_QmJobAndSeqAccess[QmModIndex].EndIndex                 = 0U;
        #if(SPI_NUM_QM_ASYNC_MASTERS > 1U)
          QmModIndex++;
        }while(QmModIndex < SPI_NUM_QM_ASYNC_MASTERS);
        #endif

        #endif
        #endif
      #endif
      /*(SPI_LEVEL_DELIVERED != 0)*/

    #if(SPI_SLAVE_ENABLE == STD_ON)
    Spi_lSlaveDeInit();
    #endif

      Spi_BusStatus = SPI_IDLE;
      #if (SPI_DEV_ERROR_DETECT == STD_ON)
      Spi_DriverState = SPI_DRIVER_DEINITIALIZED;
      #endif
      /*(SPI_DEV_ERROR_DETECT == STD_ON)*/

      #if (SPI_PB_FIXEDADDR == STD_ON)
      Spi_InitStatus = SPI_DRIVER_DEINITIALIZED;
      #endif
      /*(SPI_PB_FIXEDADDR == STD_ON)*/

    }/*(Spi_lGetHwStatus(SPI_DEINIT_ACCESS) != SPI_BUS_BUSY)*/
    else
    {
      RetVal = E_NOT_OK;
    }
  }
  return (Std_ReturnType)RetVal;
} /* End of Function: Spi_DeInit */

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI177_SPI304_SPI307,
DS_AS_SPI046_2_SPI242_2,DS_AS_SPI256_2,DS_AS_SPI018,DS_AS_SPI023
,DS_AS_SPI024,DS_AS_SPI137,DS_AS_SPI305,DS_AS_SPI306
, DS_AS_SPI004_1_SPI031_1,DS_MCAL_SPI_9010_2]                                 **
** Syntax : Std_ReturnType Spi_WriteIB                                        **
** (                                                                          **
**   Spi_ChannelType Channel,                                                 **
**   const Spi_DataType* DataBufferPtr                                        **
** )                                                                          **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x02                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Channel - Channel ID.                                    **
**                   DataBufferPtr - Pointer to source data buffer            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK - Write command has been accepted.                  **
**                   E_NOT_OK - Write command has not been accepted.          **
**                                                                            **
** Description : Service for writing one or more data to an IB                **
** SPI Handler/Driver Channel specified by parameter.                         **
** In case of 16bit Channel Data Width the DataBufferPtr must be 16bit aligned**
** This function is pre compile time configurable by the parameter:           **
** SPI_CHANNEL_BUFFERS_ALLOWED.This service is only relevant for Channels with**
** IB.                                                                        **
** Different Jobs, consequently also Sequences, can have in common            **
** Channels. But, the use of those shared Channels is restricted. Read and    **
** Write functions can not guarantee the data integrity while Channel data is **
** being transmitted. User must ensure that Read and/or Write functions are   **
** not called during transmission.                                            **
*******************************************************************************/
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0U)||(SPI_CHANNEL_BUFFERS_ALLOWED == 2U))
Std_ReturnType Spi_WriteIB
(
  Spi_ChannelType Channel,
  const Spi_DataType *DataBufferPtr
)
{
  Std_ReturnType RetVal;
  uint32 IBStartIndex;
  uint32 IBEndIndex;
  const Spi_ChannelConfigType* ChannelConfigPtr;
  uint32* BufferDataPtr32;
  uint16* BufferDataPtr16;
  Spi_DataType* BufferDataPtr8;

  #if ((SPI_DEV_ERROR_DETECT == STD_OFF) && (SPI_SAFETY_ENABLE == STD_ON))
  RetVal = E_OK;
  #endif

  #if ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) )
  /* API  called before initialization */
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  RetVal = Spi_lGetDetInitStatus(SPI_SID_WRITEIB);
  #endif
  /*Channel not an IB Channel and is not within
    0 to SPI_MAX_IB_CHANNELS*/

  #if (!((SPI_DEV_ERROR_DETECT == STD_OFF) && (SPI_SAFETY_ENABLE == STD_ON)))
   if ((E_OK == RetVal) &&
       (Channel >= (Spi_ChannelType)Spi_NoOfIBChannels))
  #else
   if (Channel >= (Spi_ChannelType)Spi_NoOfIBChannels)
  #endif
  {
    /* Report to DET */
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    Det_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_WRITEIB, SPI_E_PARAM_CHANNEL );
    #endif

    #if (SPI_SAFETY_ENABLE == STD_ON)
    SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_WRITEIB, SPI_E_PARAM_CHANNEL );
     /* [cover parentID=DS_MCAL_SPI_9841_02][/cover] */
    #endif

    /* In case of DET or safety error, Service is Rejected */
    RetVal = E_NOT_OK;
  }

  #if (SPI_SAFETY_ENABLE == STD_ON)
  if((RetVal == E_OK) && (DataBufferPtr != ((Spi_DataType*)0)))
  {
     /* fix for AI00238516 Point.3*/
    /*IFX_MISRA_RULE_17_04_STATUS="SpiChannelConfigPtr" Pointer arithmetic used
       due to PBConfigStructure and is within allowed range.*/
    /*IFX_MISRA_RULE_17_04_STATUS="SpiChannelConfigPtr" Pointer arithmetic used
       due to PBConfigStructure and is within allowed range.*/
     /*IFX_MISRA_RULE_17_04_STATUS="DataBufferPtr" Pointer arithmetic used due
       to BufferStructure and is within allowed range.*/
     if (( DataBufferPtr[(&(Spi_kConfigPtr->\
                               SpiChannelConfigPtr[Channel]))->NoOfBuffers]
      !=  (&(Spi_kConfigPtr->SpiChannelConfigPtr[Channel]))->ChnlBufferMarker))
     {
       /* report to upper layer */
       SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
           SPI_SID_WRITEIB, SPI_E_PARAM_SRC_POINTER );
        /* [cover parentID=DS_MCAL_SPI_9841_03][/cover] */
       RetVal = E_NOT_OK;
     }
     else
     {
       /* do nothing */
     }
  }
  #endif
  /* (SPI_SAFETY_ENABLE == STD_ON) */

  if (RetVal == E_OK)
  #endif
  /* ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) ) */
  {
    RetVal = E_NOT_OK;  /* Initialize Return Value to E_NOT_OK */

    /*IFX_MISRA_RULE_17_04_STATUS="SpiChannelConfigPtr" Pointer arithmetic used
      due to PBConfigStructure and is within allowed range.*/
    ChannelConfigPtr = &(Spi_kConfigPtr->SpiChannelConfigPtr[Channel]);

    /* Enter Critical Section: EnterKey-A */
    SchM_Enter_Spi_WriteIB();
    /* Channel Not Locked */
    if (Spi_lGetChannelWriteLock(Channel) == 0U)
    {
      Spi_lSetChannelWriteLock(Channel);       /* Lock Channel */
      /*Note: Channel is Locked to make the function reentrant on the same
        Channel */
      /* Exit Critical Section asap for minimal blocking time: ExitKey-A1*/
      SchM_Exit_Spi_WriteIB();

      RetVal = E_OK;
      /* This service shall take over the given parameters, and save the
      pointed data to the internal buffer defined with Spi_init()*/

      /* Get Offset in IB Buffer For this channel */
      IBStartIndex = (uint32)Spi_IBBufferAccess.IBBufferOffset[Channel];

      /* Get Loop End Condition */
      IBEndIndex =  (uint32)ChannelConfigPtr->NoOfBuffers;

      if(ChannelConfigPtr->DataConfig & SPI_32BIT_DATAMASK) /* Data =32 Bits */
      {
        /* If this pointer is null,
        the default transmit value of this channel will be used instead.*/

        /* Get Pointer to the Buffer Start Location */
        BufferDataPtr32 = (uint32*)(void*)
        (&Spi_IBBufferAccess.IBBuffer[IBStartIndex]);

        Spi_lIBCopy32BitData(BufferDataPtr32,DataBufferPtr,IBEndIndex,Channel);
      }
      else if (ChannelConfigPtr->DataConfig & SPI_16BIT_DATAMASK)
      {
        /* Data = 16 Bits */
        /* If this pointer is null,
        the default transmit value of this channel will be used instead.*/

        /* Get Pointer to the Buffer Start Location */
        BufferDataPtr16 = (uint16*)(void*)
        (&Spi_IBBufferAccess.IBBuffer[IBStartIndex]);

        Spi_lIBCopy16BitData(BufferDataPtr16,DataBufferPtr,IBEndIndex,Channel);
      }
      else
      {
        /* 8 Bit Data */
        /* Get Pointer to the Buffer Start Location */
        BufferDataPtr8 = (&Spi_IBBufferAccess.IBBuffer[IBStartIndex]);

        Spi_lIBCopy8BitData(BufferDataPtr8,DataBufferPtr,IBEndIndex,Channel);
      } /* if(ChannelConfigPtr->DataConfig & SPI_32BIT_DATAMASK) */

      /* Enter Critical Section */
      SchM_Enter_Spi_WriteIB();

      Spi_lClrChannelWriteLock(Channel);
      /* Exit Critical Section */
      SchM_Exit_Spi_WriteIB();
    } /* End of if(Spi_lGetChannelWriteLock(Channel) == 0) */
    else
    {
      /* Exit Critical Section asap for minimal blocking time: ExitKey-A2 */
      SchM_Exit_Spi_WriteIB();
    }
  }
  return (Std_ReturnType)RetVal;
} /* End of Function Spi_WriteIB */
#endif
/*SPI_CHANNEL_BUFFERS_ALLOWED == 0||SPI_CHANNEL_BUFFERS_ALLOWED == 2U*/

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI178_SPI308,
DS_AS_SPI046_3_SPI242_3,DS_AS_SPI256_3,DS_AS_SPI004_2_SPI031_2,
DS_AS_SPI081,DS_AS_SPI086,DS_AS_SPI116,
DS_AS_SPI124,DS_AS_SPI127,DS_AS_SPI133,
DS_AS_SPI243,DS_AS_SPI246,DS_AS_SPI309,DS_AS_SPI310,DS_AS_SPI311,
DS_AS_SPI032_1, DS_AS_SPI155_1,DS_AS_SPI238_1,DS_AS_SPI254_1,
DS_AS_SPI020_1,DS_AS_SPI157,DS_AS_SPI266,DS_AS_SPI055,DS_NAS_SPI_PR88,
DS_NAS_SPI_PR100, DS_NAS_SPI_PR101,DS_AS403_SPI194]                           **
** Syntax : Std_ReturnType Spi_AsyncTransmit                                  **
** (                                                                          **
**   Spi_SequenceType Sequence                                                **
** )                                                                          **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x03                                                          **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Sequence - Sequnece ID.                                  **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK - Transmission command has been accepted.           **
**                   E_NOT_OK - Transmission command has been accepted.       **
**                                                                            **
** Description : AsyncService to transmit data on the SPI bus.                **
** This service take over the given parameter, initiate a transmission,       **
** and set the SPI Handler/Driver status to SPI_BUSY, set the sequence result **
** to SPI_SEQ_PENDING, set the first job result to SPI_JOB_PENDING and return.**
** This function is pre compile time selectable by the configuration          **
** parameter:SPI_LEVEL_DELIVERED. This function is only relevant for          **
** LEVEL 1 and LEVEL 2.                                                       **
** The function allows transmitting more than one Sequence at the             **
** same time. That means during a Sequence on-going transmission, all requests**
** to transmit another Sequence shall be evaluated, using the                 **
** lead Job, for an acceptance if different SPI buses or for set to           **
** pending state for transmission later.                                      **
** This method shall be called after a Spi_SetupEB method for EB Channels or  **
** Spi_WriteIB method for IB Channels but before the Spi_ReadIB method.       **
*******************************************************************************/
/*[cover parentID=DS_AS_SPI109_1*/
#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
/* [/cover]*/
Std_ReturnType Spi_AsyncTransmit(Spi_SequenceType Sequence)
{
  Spi_JobAndSeqAccessType   *JobSeqDataPtr;
  uint32 RetVal;
  const Spi_SequenceConfigType* ParamSeqConfigPtr;
  uint32 HWUnit;
  uint32 SeqJobSharingStatus;
  uint16 JobId;
  uint16 FirstJobInQueue;
  #if (SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_OFF)
  uint16 Index;
  #endif
  /*(SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_OFF)*/
  uint32 JobCounter;
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  uint8 IsQAvail;
  #endif

  #if ((SPI_DEV_ERROR_DETECT == STD_OFF) && (SPI_SAFETY_ENABLE == STD_ON))
  RetVal = E_OK;
  #endif

  #if ((SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON))
  JobSeqDataPtr = NULL_PTR; /* To remove warning: Possibly Uninitialised */
  #endif

  #if ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) )
  /* API called before initialization */
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  RetVal = Spi_lGetDetInitStatus(SPI_SID_ASYNCTRANSMIT);
  #endif

    /*
    Sequence shall be within the specified range of
    values (Sync Seq Limit to SPI_MAX_SEQUENCE )
    */
  #if (SPI_LEVEL_DELIVERED == 2U)

  #if (!((SPI_DEV_ERROR_DETECT == STD_OFF) && (SPI_SAFETY_ENABLE == STD_ON)))
  if ((RetVal == E_OK) &&
         ((Sequence >= Spi_kConfigPtr->NoOfSequences)
         || (Sequence < Spi_kConfigPtr->NoOfSyncSequences)))
  #else
  if (((Sequence >= Spi_kConfigPtr->NoOfSequences)
         || (Sequence < Spi_kConfigPtr->NoOfSyncSequences)))
  #endif
  {
    /* Report to DET */
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    Det_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
       SPI_SID_ASYNCTRANSMIT, SPI_E_PARAM_SEQ );
    #endif

    #if (SPI_SAFETY_ENABLE == STD_ON)
    SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_ASYNCTRANSMIT, SPI_E_PARAM_SEQ );
    /* [cover parentID=DS_MCAL_SPI_9841_04][/cover] */
    #endif

    /* In case of DET or Safety error, Service is Rejected */
    RetVal = E_NOT_OK;
  }
  #else
  #if (!((SPI_DEV_ERROR_DETECT == STD_OFF) && (SPI_SAFETY_ENABLE == STD_ON)))
  if ((RetVal == E_OK) && (Sequence >= Spi_kConfigPtr->NoOfSequences))
  #else
  if (Sequence >= Spi_kConfigPtr->NoOfSequences)
  #endif
  {
    /* Report to DET */
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    Det_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_ASYNCTRANSMIT, SPI_E_PARAM_SEQ );
    #endif

    #if (SPI_SAFETY_ENABLE == STD_ON)
    SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_ASYNCTRANSMIT, SPI_E_PARAM_SEQ );
     /* [cover parentID=DS_MCAL_SPI_9841_04][/cover] */
    #endif

    /* In case of DET or Safety error, Service is Rejected */
    RetVal = E_NOT_OK;
  }
  #endif
  /*(SPI_LEVEL_DELIVERED == 2U)*/

    if(RetVal == E_OK)
    {
      #if (SPI_SAFETY_ENABLE == STD_ON)
        if( SPI_ASIL_SEQUENCE == Spi_lGetSequenceKind(Sequence) )
        {
          JobSeqDataPtr = &Spi_AsilJobAndSeqAccess;
        }
        else
        {
          #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
          #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
          JobSeqDataPtr = &Spi_QmJobAndSeqAccess;
          #else
          JobSeqDataPtr = &Spi_QmJobAndSeqAccess[  \
                                        Spi_lGetQmModuleVarIndexSeq(Sequence)];
          #endif
          #endif
          /* Do nothing if QM modules are NOT Used */
        }
      #else
      {
        #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
        JobSeqDataPtr = &Spi_QmJobAndSeqAccess;
        #else
        JobSeqDataPtr = &Spi_QmJobAndSeqAccess[   \
                                        Spi_lGetQmModuleVarIndexSeq(Sequence)];
        #endif
      }
      #endif

      /*IFX_MISRA_RULE_17_04_STATUS="SpiSequenceConfigPtr" Pointer arithmetic
        used due to PBConfigStructure and is within allowed range.*/
      ParamSeqConfigPtr = &(Spi_kConfigPtr->SpiSequenceConfigPtr[Sequence]);

     /* DET for the non availability of Job Queue when a new sequence arrives*/
      #if (SPI_DEV_ERROR_DETECT == STD_ON)
     /* Enter Critical Section: EnterKey-B */
      SchM_Enter_Spi_AsyncTransmit();
      IsQAvail = Spi_lIsQueueAvailable(ParamSeqConfigPtr->JobsInParamSeq,
                                       JobSeqDataPtr);
      if (IsQAvail == E_NOT_OK)
      {
        /* Exit Critical Section asap for minimal blocking time: ExitKey-B1*/
        SchM_Exit_Spi_AsyncTransmit();
        Det_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_ASYNCTRANSMIT, SPI_E_QUEUE_FULL );
        /* In case of DET, Service is Rejected */
        RetVal = E_NOT_OK;
      }
      #endif
    }
    else
    {
     ParamSeqConfigPtr = NULL_PTR;
    }

#else
    /* else condition for
     ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) )
    initialise parameters which are not initalised if error checks are OFF */
    /* fix for AI00238517 Point.1 Dead code */
    #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
    JobSeqDataPtr = &Spi_QmJobAndSeqAccess;
    #else
    JobSeqDataPtr = &Spi_QmJobAndSeqAccess[\
                                        Spi_lGetQmModuleVarIndexSeq(Sequence)];
    #endif
   /*IFX_MISRA_RULE_17_04_STATUS="SpiSequenceConfigPtr" Pointer arithmetic used
      due to PBConfigStructure and is within allowed range.*/
    ParamSeqConfigPtr = &(Spi_kConfigPtr->SpiSequenceConfigPtr[Sequence]);

#endif
 /* ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) ) */

#if ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) )
  if (RetVal == E_OK)
#endif
 /* ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) ) */
  {
    RetVal = E_NOT_OK;

    /*IFX_MISRA_RULE_17_04_STATUS="JobLinkPtr" Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
   JobId = ParamSeqConfigPtr->JobLinkPtr[0U]; /*Get First Job of the Sequence*/
    /* Get SPI Bus */
    /*IFX_MISRA_RULE_17_04_STATUS="SpiJobConfigPtr" Pointer arithmetic used due
      to PBConfigStructure and is within allowed range.*/
    HWUnit = Spi_kConfigPtr->SpiJobConfigPtr[JobId].HwUnit;
    HWUnit &= SPI_HWUNIT_MASK;

    JobCounter = 0U;

    /* Sequence is not already pending */
    /* Check if Sequence Requested shares a job with another sequences
    that is in state SPI_SEQ_PENDING */
    #if (SPI_DEV_ERROR_DETECT == STD_OFF)
    SchM_Enter_Spi_AsyncTransmit(); /* Enter Critical Section: EnterKey-C */
    if (Spi_lIsQueueAvailable(ParamSeqConfigPtr->JobsInParamSeq,JobSeqDataPtr)\
                                                             == E_OK)

    #endif
    {
      /* If the requested Sequence is already in the state SPI_SEQ_PENDING
       the SPI Handler/Driver does not take in account this new request and
       this service returns value E_NOT_OK. According to [SPI100],
       the SPI Handler/Driver shall report the SPI_E_SEQ_PENDING error.
       If the requested Sequence shares Jobs with another sequence
       that is in the state SPI_SEQ_PENDING, the SPI Handler/Driver does not
       take in account this new request and this service returns value E_NOT_OK
       The SPI Handler/Driver shall report the
       SPI_E_SEQ_PENDING error.*/
       /* ParamSeqConfigPtr->SeqSharingJobs : Holds for each sequence all the
       other sequences that shares a job with this sequence. The current
       sequence is also set.
       SeqStatus : Holds all pending sequences */
      if (SPI_SEQ_PENDING != (Spi_lGetSeqStatus(Sequence)))
      {
        SeqJobSharingStatus = Spi_lSeqSharingJobStatus(ParamSeqConfigPtr);
      }
      else
      {
        SeqJobSharingStatus = 1U;
      }/*(SPI_SEQ_PENDING != (Spi_lGetSeqStatus(Sequence)))*/

      if (SeqJobSharingStatus == 0U)
      {
        RetVal = E_OK;
        /* Set Sequence Status to Pending */
        /* set the sequence result to SPI_SEQ_PENDING */
        Spi_lSetSeqStatus(Sequence, SPI_SEQ_PENDING);
        /* If the bus attached to the lead job is free, start transmission
         immediately */
        #if (SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_OFF)
        Index = JobSeqDataPtr->EndIndex;

        do
        {
          /* extract each job id from the sequence */
         /*IFX_MISRA_RULE_17_04_STATUS="JobLinkPtr" Pointer arithmetic used due
            to PBConfigStructure and is within allowed range.*/
          JobId = ParamSeqConfigPtr->JobLinkPtr[JobCounter];
          JobSeqDataPtr->JobQueue[Index] = JobId;
          JobSeqDataPtr->JobLinkedSeq[Index] = Sequence;

          Spi_lSetJobStatusAtomic(JobId,SPI_JOB_QUEUED );
          JobCounter++;
          Index = Spi_lIncrementAndRoundIndex(Index);
        /*IFX_MISRA_RULE_17_04_STATUS="JobLinkPtr" Pointer arithmetic used due
          to PBConfigStructure and is within allowed range.*/
        }while (ParamSeqConfigPtr->JobLinkPtr[JobCounter] != \
                                                 SPI_JOB_LINK_DELIMITER);
        JobSeqDataPtr->EndIndex = Index;
        #else
        do
        {
          /* extract each job id from the sequence */
         /*IFX_MISRA_RULE_17_04_STATUS="JobLinkPtr" Pointer arithmetic used due
            to PBConfigStructure and is within allowed range.*/
          JobId = ParamSeqConfigPtr->JobLinkPtr[JobCounter];
          Spi_lSetJobStatusAtomic(JobId, SPI_JOB_QUEUED );
          JobCounter++;
        /*IFX_MISRA_RULE_17_04_STATUS="JobLinkPtr" Pointer arithmetic used due
          to PBConfigStructure and is within allowed range.*/
        }while (ParamSeqConfigPtr->JobLinkPtr[JobCounter] != \
                                                 SPI_JOB_LINK_DELIMITER);
        #endif
        /*(SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_OFF)*/

        #if (SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)
        Spi_lIntSeqAsyncTransmit(Sequence,JobSeqDataPtr);
        #endif
        /*(SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)*/
        if (SPI_IDLE == Spi_lGetSeqAsyncBusStatus(Sequence))
        {
          /* Store the pending Sequence and its first Job in the SPI Bus */
          /* set the SPI Handler/Driver status to SPI_BUSY */
          Spi_lSetSeqAsyncBusStatus((Spi_StatusType)SPI_BUSY, Sequence);
          Spi_BusStatus = SPI_BUSY;

          /* To start the first job transmission */
          FirstJobInQueue = JobSeqDataPtr->JobQueue[0U];
          /* Set First Job Index in the Status Array */
          #if (SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_OFF)
          JobSeqDataPtr->CurrentJobIndex = 0U;
          /* Set First Job Index in the Status Array */
          #else /* (SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON) */
          JobSeqDataPtr->CurrentJobIndex[Sequence] = 0U;
          #endif

          #if (SPI_CANCEL_API == STD_ON)
          Spi_lClrSeqCancelStatus(Sequence);
          #endif
          /* (SPI_CANCEL_API == STD_ON) */

          /* Id should be incremented first and Job should be started.
             Reason:
             For an empty Queue, a request comes with no of jobs that is
             equal to the Queue size, in this scenario, the Queue should
             be assigned to full status before starting a job.
           */
          JobSeqDataPtr->StartIndexExtractJobId++;
          /* If there is only one job to be processed, increment the EndIndex
             initially itself to identify that only one job is present and
             further job processing will be stopped.
          */
          #if ( (SPI_MAXIMUM_JOB == 1U) && (SPI_MAX_JOB_TRIG_Q_LENGTH == 1U) )
          JobSeqDataPtr->EndIndex++;
          #endif
          Spi_lStartJob(HWUnit, FirstJobInQueue, SPI_RUNTIME_ACCESS);
        } /*(Spi_AsyncBusStatus == SPI_BUS_IDLE)*/
        else
        {
          #if (SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)
          /* Set First Job Index in the Status Array */
          JobSeqDataPtr->CurrentJobIndex[Sequence] = 0U;
          #endif
        }/*(Spi_AsyncBusStatus == SPI_BUS_IDLE)*/
        /* Exit Critical Section asap for minimal blocking time: ExitKey-C1*/
        SchM_Exit_Spi_AsyncTransmit();
      }/*(!(SeqJobSharingStatus))*/
      else
      {
        /* Exit Critical Section asap for minimal blocking time: ExitKey-B2*/
        SchM_Exit_Spi_AsyncTransmit();
        #if (SPI_DEV_ERROR_DETECT == STD_ON)
        /* Sequence is already pending, return E_NOT_OK */
          /* Report to DET */
        Det_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_ASYNCTRANSMIT, SPI_E_SEQ_PENDING );
        #endif
        /* SPI_DEV_ERROR_DETECT */
      }/*(!(SeqJobSharingStatus))*/
    }/*IsQAvail == E_OK*/
    #if (SPI_DEV_ERROR_DETECT == STD_OFF)
    else
    {
      /* Exit Critical Section asap for minimal blocking time: ExitKey-C2*/
      SchM_Exit_Spi_AsyncTransmit();
    }
    #endif
  }
  return (Std_ReturnType)RetVal;
}
#endif
 /* SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U */

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI179_SPI312,
DS_AS_SPI046_4_SPI242_4,DS_AS_SPI256_4,
DS_AS_SPI004_3_SPI031_3,DS_AS_SPI016_SPI315,DS_AS_SPI138,
DS_AS_SPI313_SPI314]                                                          **
** Syntax : Std_ReturnType Spi_ReadIB (                                       **
**                                    Spi_ChannelType Channel,                **
**                                    Spi_DataType *DataBufferPtr             **
**                                 )                                          **
** [/cover]                                                                   **
** Service ID:  0x04                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Channel - Channel ID.                                    **
**                   DataBufferPtr - Pointer to destination data buffer in RAM**
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK - Read command has been accepted.                   **
**                   E_NOT_OK - Read command has not been accepted.           **
**                                                                            **
** Description : Service for reading synchronously one or more                **
** data from an IB SPI Handler/Driver Channel specified by parameter.         **
** In case of 16bit Channel Data Width the DataBufferPtr must be 16bit aligned**
** Different Jobs, consequently also Sequences, can have in common            **
** Channels. But, the use of those shared Channels is restricted. Read and    **
** Write functions can not guarantee the data integrity while Channel data is **
** being transmitted. User must ensure that Read and/or Write functions are   **
** not called during transmission.                                            **
** This method shall be called after one Transmit method call to have         **
** relevant data within IB Channel.                                           **
*******************************************************************************/
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0U)||(SPI_CHANNEL_BUFFERS_ALLOWED == 2U))
Std_ReturnType Spi_ReadIB
(
  Spi_ChannelType Channel,
  Spi_DataType* DataBufferPtr
)
{

  volatile uint32 IBReadBufferStartIndex;
  volatile uint32 IBReadBufferEndIndex;
  const Spi_ChannelConfigType* ChannelConfigPtr;
  uint32* BufferDataPtr32;
  uint16* BufferDataPtr16;
  Spi_DataType* BufferDataPtr8;
  Std_ReturnType RetVal;

  #if ((SPI_DEV_ERROR_DETECT == STD_OFF) && (SPI_SAFETY_ENABLE == STD_ON))
  RetVal = E_OK;
  #elif (SPI_DEV_ERROR_DETECT == STD_OFF)
  RetVal = E_OK;
  #endif

  #if ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) )
  /* API  called before initialization */
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  RetVal = Spi_lGetDetInitStatus(SPI_SID_READIB);
  #endif

  /*
    Channel not an IB Channel and is not within 0 to SPI_MAX_CHANNEL
  */
 #if (!((SPI_DEV_ERROR_DETECT == STD_OFF) && (SPI_SAFETY_ENABLE == STD_ON)))
  if ((E_OK == RetVal) &&
      (Channel >= (Spi_ChannelType)Spi_NoOfIBChannels))
 #else
  if (Channel >= (Spi_ChannelType)Spi_NoOfIBChannels)
 #endif
  {
    /* Report to DET */
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    Det_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_READIB, SPI_E_PARAM_CHANNEL );
    #endif

    #if (SPI_SAFETY_ENABLE == STD_ON)
    SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_READIB, SPI_E_PARAM_CHANNEL );
     /* [cover parentID=DS_MCAL_SPI_9841_05][/cover] */
    #endif

    /* In case of DET or safety error, Service is Rejected */
    RetVal = E_NOT_OK;
  }

  #if (SPI_SAFETY_ENABLE == STD_ON)
  if(RetVal == E_OK)
  {
    if(DataBufferPtr == ((Spi_DataType*)0U))
    {
       SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
           SPI_SID_READIB, SPI_E_PARAM_DEST_POINTER );
       /* [cover parentID=DS_MCAL_SPI_9841_06][/cover] */
       RetVal = E_NOT_OK;
    }
    else
    {
       /* fix for AI00238516 Point.3*/
       /*IFX_MISRA_RULE_17_04_STATUS="SpiChannelConfigPtr" Pointer arithmetic
         used due to PBConfigStructure and is within allowed range.*/
       /*IFX_MISRA_RULE_17_04_STATUS="SpiChannelConfigPtr" Pointer arithmetic
         used due to PBConfigStructure and is within allowed range.*/
      /*IFX_MISRA_RULE_17_04_STATUS="DataBufferPtr" Pointer arithmetic used due
         to BufferStructure and is within allowed range.*/
       if (DataBufferPtr[(&(Spi_kConfigPtr->\
                                SpiChannelConfigPtr[Channel]))->NoOfBuffers]
        != (&(Spi_kConfigPtr->SpiChannelConfigPtr[Channel]))->ChnlBufferMarker)
       {
          /* report to upper layer */
          SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
            SPI_SID_READIB, SPI_E_PARAM_DEST_POINTER );
          /* [cover parentID=DS_MCAL_SPI_9841_06][/cover] */
          RetVal = E_NOT_OK;
       }
    }
  }
  #endif
  /* (SPI_SAFETY_ENABLE == STD_ON) */

  if (RetVal == E_OK)
  #endif
  /*( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) )*/
  {
    /*IFX_MISRA_RULE_17_04_STATUS="SpiChannelConfigPtr" Pointer arithmetic used
      due to PBConfigStructure and is within allowed range.*/
    ChannelConfigPtr = &(Spi_kConfigPtr->SpiChannelConfigPtr[Channel]);
    /* Get IB Buffer Offset for the Channel in the IB Buffer */
    IBReadBufferStartIndex = ((uint32)Spi_IBBufferAccess.IBBufferOffset[Channel]
                               + (uint32)SPI_MAXIMUM_IB_BUFFER_SIZE);

    /* Get Loop End Condition */
    IBReadBufferEndIndex = (uint32)ChannelConfigPtr->NoOfBuffers;

    /* Data is 32 Bits */
    if (ChannelConfigPtr->DataConfig & SPI_32BIT_DATAMASK)
    {
      /* Get Pointer to the Buffer Start Location */
      BufferDataPtr32 = (uint32*)(void*)
      (&Spi_IBBufferAccess.IBBuffer[IBReadBufferStartIndex]);

      do
      {
        *((uint32*)(void*)DataBufferPtr) = *BufferDataPtr32;
        /*IFX_MISRA_RULE_17_04_STATUS="DataBufferPtr" Pointer arithmetic used
          due to BufferStructure and is within allowed range.*/
        DataBufferPtr = DataBufferPtr + SPI_32BIT_DATA_ACCESS;
        /*IFX_MISRA_RULE_17_04_STATUS="BufferDataPtr32" Pointer arithmetic used
          due to BufferStructure and is within allowed range.*/
        BufferDataPtr32++;
        IBReadBufferEndIndex = IBReadBufferEndIndex - \
                                              (uint32)SPI_32BIT_DATA_ACCESS;
      }while (IBReadBufferEndIndex > 0U);

    }
    else if (ChannelConfigPtr->DataConfig & SPI_16BIT_DATAMASK)
    {
      /* The channel data to be transmitted shall be copied in
      1 entry deep internal buffers by channel. */

      /* Get Pointer to the Buffer Start Location */
      BufferDataPtr16 = (uint16*)(void*)
      (&Spi_IBBufferAccess.IBBuffer[IBReadBufferStartIndex]);

      do
      {
        *((uint16*)(void*)DataBufferPtr) = *BufferDataPtr16;
        /*IFX_MISRA_RULE_17_04_STATUS="DataBufferPtr" Pointer arithmetic used
          due to BufferStructure and is within allowed range.*/
        DataBufferPtr = DataBufferPtr + SPI_16BIT_DATA_ACCESS;
        /*IFX_MISRA_RULE_17_04_STATUS="BufferDataPtr16" Pointer arithmetic used
          due to BufferStructure and is within allowed range.*/
        BufferDataPtr16++;
        IBReadBufferEndIndex = IBReadBufferEndIndex - \
                                              (uint32)SPI_16BIT_DATA_ACCESS;
      }while (IBReadBufferEndIndex > 0U);
    }
    else
    {
      /* Data Width is 8 Bit Data */
      /* Get Pointer to the Buffer Start Location */
      BufferDataPtr8 = (&Spi_IBBufferAccess.IBBuffer[IBReadBufferStartIndex]);

      do
      {
        *((uint8*)(void*)DataBufferPtr) = *BufferDataPtr8;
        /*IFX_MISRA_RULE_17_04_STATUS="DataBufferPtr" Pointer arithmetic used
          due to BufferStructure and is within allowed range.*/
        DataBufferPtr++;
        /*IFX_MISRA_RULE_17_04_STATUS="BufferDataPtr8" Pointer arithmetic used
          due to BufferStructure and is within allowed range.*/
        BufferDataPtr8++;
        IBReadBufferEndIndex--;
      }while (IBReadBufferEndIndex > 0U);
    }/*(ChannelConfigPtr->DataConfig & SPI_32BIT_DATAMASK)*/
  }
  return RetVal;
} /* End of Function: Spi_ReadIB */
#endif
 /*SPI_CHANNEL_BUFFERS_ALLOWED == 0||SPI_CHANNEL_BUFFERS_ALLOWED == 2U*/

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI180_SPI316,
DS_AS_SPI046_5_SPI242_5,DS_AS_SPI256_5,DS_AS_SPI155_2,
DS_AS_SPI058_SPI318, DS_AS_SPI060_SPI240,DS_AS_SPI067,DS_AS_SPI139,
DS_AS_SPI258_SPI317, DS_MCAL_SPI_9010_1]                                      **
** Syntax : Std_ReturnType Spi_SetupEB                                        **
** (                                                                          **
**   Spi_ChannelType Channel,                                                 **
**   const Spi_DataType* SrcDataBufferPtr,                                    **
**   Spi_DataType* DesDataBufferPtr,                                          **
**   Spi_NumberOfDataType Length                                              **
** )                                                                          **
** [/cover]                                                                   **
** Service ID:  0x05                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Channel - Channel ID.                                    **
**                   SrcDataBufferPtr - Pointer to Source data buffer         **
**                   DesDataBufferPtr - Pointer to Destination data buffer    **
**                   Length - Length of the data to be transmitted from       **
**                   SrcdataBufferPtr and/or received from DesDataBufferPtr   **
**                   Min.: 1                                                  **
**                   Max.: Max of data specified at configuration for         **
**                   this channel                                             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK - Setup command has been accepted.                  **
**                   E_NOT_OK - Setup command has not been accepted.          **
**                                                                            **
** Description : Service to setup the buffers and the length of data          **
** for the EB SPI Handler/Driver Channel specified.                           **
** This service shall update the buffer pointers and lengh attributes         **
** of the specified Channel with the provided values. As these attributes are **
** persistent, they will be used for all succeeding calls to one Transmit     **
** method (for the specified Channel).                                        **
** To transmit a variable number of data, it is mandatory to call             **
** Spi_SetupBuffers function to store new parameters within SPI Handler/Driver**
** before each Spi_Transmit function calls.                                   **
** To transmit a constant number of data, it is only mandatory to call        **
** Spi_SetupBuffers function to store parameters within SPI Handler/Driver    **
** before the first Spi_Transmit function call.                               **
** For EB Channels the application shall provide the buffering,               **
** and shall take care of the consistency of the data in the buffer during    **
** transmission. The size of the Channel buffer is either fixed or variable.  **
** A maximum size for the Channel buffer is fixed by configuration,           **
** but the size of the buffer provided by the User can change.                **
** In case of 16 bit Channel Data Width, The SrcDataBufferPtr and             **
** DesDataBufferPtr must be 16bit aligned.                                    **
** Different Jobs, consequently also Sequences, can have in common            **
** Channels. But, the use of those shared Channels is restricted. Read and    **
** Write functions can not guarantee the data integrity while Channel data is **
** being transmitted. User must ensure that Read and/or Write functions are   **
** not called during transmission.                                            **
** This method shall be called one time for all Channels with EB              **
** declared before to call a Transmit method for them.                        **
**                                                                            **
*******************************************************************************/
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 1U)||(SPI_CHANNEL_BUFFERS_ALLOWED == 2U))
Std_ReturnType Spi_SetupEB
(
  Spi_ChannelType Channel,
  const Spi_DataType* SrcDataBufferPtr,
  Spi_DataType* DesDataBufferPtr,
  Spi_NumberOfDataType Length
)
{
  uint32 RetVal;
  uint16 DataConfig;
  #if (SPI_SAFETY_ENABLE == STD_ON)
  uint16 BufferLength;
  #endif
  Spi_EBBufferType* EBBufferPtr;

  #if ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) )
  uint32 TransferCount = 0U;
  DataConfig = 0U;
  #endif

  #if (SPI_SAFETY_ENABLE == STD_ON)
  BufferLength = 0U;
  #endif

  #if ((SPI_DEV_ERROR_DETECT == STD_OFF) && (SPI_SAFETY_ENABLE == STD_ON))
  RetVal = E_OK;
  #endif

#if ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) )

  /* API called before initialization */
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  RetVal = Spi_lGetDetInitStatus(SPI_SID_SETUPEB);
  #endif

  /*Channel not an IB Channel and is not within 0
    to SPI_MAX_CHANNEL*/
 #if(!((SPI_DEV_ERROR_DETECT == STD_OFF) && (SPI_SAFETY_ENABLE == STD_ON)))
  if ((RetVal == E_OK) &&
      ((Channel < (Spi_ChannelType)Spi_NoOfIBChannels) ||
      (Channel >= Spi_kConfigPtr->NoOfChannels)))
 #else
  if ((Channel < (Spi_ChannelType)Spi_NoOfIBChannels) ||
      (Channel >= Spi_kConfigPtr->NoOfChannels))
 #endif
  {
    /* Report to DET */
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    Det_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_SETUPEB, SPI_E_PARAM_CHANNEL );
    #endif

    #if (SPI_SAFETY_ENABLE == STD_ON)
    SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_SETUPEB, SPI_E_PARAM_CHANNEL );
     /* [cover parentID=DS_MCAL_SPI_9841_07][/cover] */
    #endif

    RetVal = E_NOT_OK;
  }
  /*Length of data shall be within the
    specified buffer maximum values*/
  else
  {
    #if(!((SPI_DEV_ERROR_DETECT == STD_OFF) && (SPI_SAFETY_ENABLE == STD_ON)))
    if(RetVal == E_OK)
    {
    #endif
    /*IFX_MISRA_RULE_17_04_STATUS="SpiChannelConfigPtr" Pointer arithmetic used
      due to PBConfigStructure and is within allowed range.*/
    DataConfig = Spi_kConfigPtr->SpiChannelConfigPtr[Channel].DataConfig ;

    /* Data Width > 16 bits */
    if (DataConfig   & SPI_32BIT_DATAMASK)
    {
      /* Length/4U */
      /*IFX_MISRA_RULE_17_04_STATUS="SpiChannelConfigPtr" Pointer arithmetic
        used due to PBConfigStructure and is within allowed range.*/
      TransferCount =
      ((uint32)Spi_kConfigPtr->SpiChannelConfigPtr[Channel].NoOfBuffers >>
                                    SPI_TRANSFERCOUNT_SHIFT_32BIT);
      #if (SPI_SAFETY_ENABLE == STD_ON)
      BufferLength = Length << SPI_TRANSFERCOUNT_SHIFT_32BIT;
      #endif
    }
    else if (DataConfig & SPI_16BIT_DATAMASK)
    {
      /* Length/2U */
      /*IFX_MISRA_RULE_17_04_STATUS="SpiChannelConfigPtr" Pointer arithmetic
        used due to PBConfigStructure and is within allowed range.*/
      TransferCount =
        ((uint32)Spi_kConfigPtr->SpiChannelConfigPtr[Channel].NoOfBuffers >>
                                     SPI_TRANSFERCOUNT_SHIFT_16BIT);
      #if (SPI_SAFETY_ENABLE == STD_ON)
      BufferLength = Length << SPI_TRANSFERCOUNT_SHIFT_16BIT;
      #endif
    }
    else
    {
      /*IFX_MISRA_RULE_17_04_STATUS="SpiChannelConfigPtr" Pointer arithmetic
        used due to PBConfigStructure and is within allowed range.*/
      TransferCount =
               (uint32)Spi_kConfigPtr->SpiChannelConfigPtr[Channel].NoOfBuffers;
      #if (SPI_SAFETY_ENABLE == STD_ON)
      BufferLength = Length;
      #endif
    }
    #if(!((SPI_DEV_ERROR_DETECT == STD_OFF) && (SPI_SAFETY_ENABLE == STD_ON)))
    }
    #endif

 #if(!((SPI_DEV_ERROR_DETECT == STD_OFF) && (SPI_SAFETY_ENABLE == STD_ON)))
    if ((RetVal == E_OK) &&
        ((Length > TransferCount) ||(Length < (Spi_NumberOfDataType)1U)))
 #else
    if ((Length > TransferCount) ||(Length < (Spi_NumberOfDataType)1U))
 #endif
    {
      /* Report to DET */
      #if (SPI_DEV_ERROR_DETECT == STD_ON)
      Det_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_SETUPEB, SPI_E_PARAM_LENGTH );
      #endif

      #if (SPI_SAFETY_ENABLE == STD_ON)
      SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_SETUPEB, SPI_E_PARAM_LENGTH );
     /* [cover parentID=DS_MCAL_SPI_9841_10][/cover] */
      #endif

      RetVal = E_NOT_OK;
    }
  }

  /* DMA implements a Circular Buffer with a maximum width of 32KB.
     So the Src/Des Ptrs should not span the 32KB Boundary if Sequential
    data are to be transferred. This address alignment is checked */
  #if (SPI_DMA_ADDR_SIZE_ALIGN_CHECK == STD_ON)
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  if (RetVal == E_OK)
  {
    RetVal= Spi_lCheckDmaAddress(DesDataBufferPtr,SrcDataBufferPtr,Length);
  }
  #endif
  #endif
 /* (SPI_DMA_ADDR_SIZE_ALIGN_CHECK == STD_ON) */

  #if (SPI_SAFETY_ENABLE == STD_ON)
  /* fix for AI00238516 Point.2*/
  if ((RetVal == E_OK) && (SrcDataBufferPtr != ((Spi_DataType*)0)))
  {
    /*IFX_MISRA_RULE_17_04_STATUS="SrcDataBufferPtr" Pointer arithmetic used due
      to BufferStructure and is within allowed range.*/
    /*IFX_MISRA_RULE_17_04_STATUS="SpiChannelConfigPtr" Pointer arithmetic used
      due to PBConfigStructure and is within allowed range.*/
    if( SrcDataBufferPtr[BufferLength] !=
          (&(Spi_kConfigPtr->SpiChannelConfigPtr[Channel]))->ChnlBufferMarker)
    {
      /* report to upper layer */
      SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_SETUPEB, SPI_E_PARAM_SRC_POINTER );
       /* [cover parentID=DS_MCAL_SPI_9841_08][/cover] */
     RetVal = E_NOT_OK;
    }
    else
    {
      /* do nothing */
    }
  }
  else
  {
    /* Do Nothing */
  }
  /*Bug fix as per JIRA: 0000051261-288*/
  /*Changed else if to if to verify safety buffer marker in reception buffer
    also.*/
  /*IFX_MISRA_RULE_17_04_STATUS="DesDataBufferPtr" Pointer arithmetic used due
    to BufferStructure and is within allowed range.*/
  /*IFX_MISRA_RULE_17_04_STATUS="SpiChannelConfigPtr" Pointer arithmetic used
    due to PBConfigStructure and is within allowed range.*/
  if ((RetVal == E_OK) && (DesDataBufferPtr != ((Spi_DataType*)0)) &&
         (DesDataBufferPtr[BufferLength] !=
          (&(Spi_kConfigPtr->SpiChannelConfigPtr[Channel]))->ChnlBufferMarker))
  {
    /* report to upper layer */
    SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_SETUPEB, SPI_E_PARAM_DEST_POINTER );
     /* [cover parentID=DS_MCAL_SPI_9841_09][/cover] */
    RetVal = E_NOT_OK;
  }
  else
  {
    /* Do Nothing */
  }
  #endif
  /* (SPI_SAFETY_ENABLE == STD_ON) */

#else
  /* else condition for
   ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) )
  initialise parameters which are not initalised if error checks are OFF */
  RetVal = E_OK;
  /*IFX_MISRA_RULE_17_04_STATUS="SpiChannelConfigPtr" Pointer arithmetic used
    due to PBConfigStructure and is within allowed range.*/
  DataConfig = Spi_kConfigPtr->SpiChannelConfigPtr[Channel].DataConfig ;
#endif
  /* (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) )*/

  #if( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) )
  if (RetVal == E_OK)
  #endif
  /* (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) )*/
  {
  /* Subtract the number of IB Channel from the Channel parameter to
     get offset of EB Channel from 0 */
  Channel = Channel - Spi_NoOfIBChannels;

  EBBufferPtr = &(Spi_EBBuffer[Channel]); /* Get EB Buffer Pointer */

  EBBufferPtr->SrcPtr  = SrcDataBufferPtr;
  EBBufferPtr->DestPtr = DesDataBufferPtr;

  if (DataConfig & SPI_32BIT_DATAMASK)
  {
    /* Length*4U */
    Length =
    (Spi_NumberOfDataType)((uint32)Length << SPI_TRANSFERCOUNT_SHIFT_32BIT);
  }
  else if (DataConfig & SPI_16BIT_DATAMASK)
  {
    /* Length*2U */
    Length =
     (Spi_NumberOfDataType)((uint32)Length << SPI_TRANSFERCOUNT_SHIFT_16BIT);
  }
  else
  {
    /*Do Nothing*/
  }

  EBBufferPtr->Length  = Length;
  }
  return (Std_ReturnType)RetVal;

} /* End of Function: Spi_SetUpEB */

#endif
/* SPI_CHANNEL_BUFFERS_ALLOWED == 1U ||SPI_CHANNEL_BUFFERS_ALLOWED == 2U */

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI181_SPI319,
DS_AS_SPI046_6_SPI242_6,
DS_AS_SPI256_6,DS_AS_SPI025_SPI259_SPI320_SPI345_SPI346_SPI347]               **
** Syntax : Spi_StatusType Spi_GetStatus(void)                                **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x06                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Spi_StatusType                                           **
**                                                                            **
** Description : This service return the SPI Handler/Driver status.           **
**                                                                            **
*******************************************************************************/
Spi_StatusType Spi_GetStatus(void)
{
  Spi_StatusType RetVal;

  RetVal = Spi_lGetHwStatus(SPI_RUNTIME_ACCESS);

  return RetVal;
} /* End of Function: Spi_GetStatus */

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI182_SPI321,
DS_AS_SPI046_7_SPI242_7, DS_AS_SPI256_7,DS_AS_SPI032_5,
DS_AS_SPI254_2,DS_AS_SPI026_SPI237_SPI261_SPI322_SPI350]                      **
** Syntax : Spi_JobResultType Spi_GetJobResult(Spi_JobType Job)               **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x07                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Job - Job ID. An invalid job ID will                     **
**                   return an undefined result.                              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Spi_JobResultType                                        **
**                                                                            **
** Description : This service return the last transmission result             **
** of the specified Job.                                                      **
** The user call Spi_GetJobResult() method to know if the Job                 **
** transmission succeeded (SPI_JOB_OK) or failed (SPI_JOB_FAILED)             **
   or pending (SPI_JOB_PENDING)                                               **
**                                                                            **
*******************************************************************************/
Spi_JobResultType Spi_GetJobResult(Spi_JobType Job)
{
  Spi_JobResultType RetVal;

  #if ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) )
  /*  API  called before initialization */
  RetVal = SPI_JOB_OK;

  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  if (E_NOT_OK == Spi_lGetDetInitStatus(SPI_SID_GETJOBRESULT))
  {
    /* In case of DET, Service is Rejected */
    RetVal = SPI_JOB_FAILED;
  }
  #endif

  /*
  Job shall be within the specified range of
  values (0 to Maximum number of jobs )
  */
 #if (SPI_DEV_ERROR_DETECT == STD_ON)
  if ((RetVal != SPI_JOB_FAILED) &&
       (Job >= Spi_kConfigPtr->NoOfJobs))
 #else
  if (Job >= Spi_kConfigPtr->NoOfJobs)
 #endif
  {
      /* Report to DET */
      #if (SPI_DEV_ERROR_DETECT == STD_ON)
      Det_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_GETJOBRESULT, SPI_E_PARAM_JOB );
      #endif

      #if (SPI_SAFETY_ENABLE == STD_ON)
      SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_GETJOBRESULT, SPI_E_PARAM_JOB );
     /* [cover parentID=DS_MCAL_SPI_9841_11][/cover] */
      #endif

      /* In case of DET or Safety error, Service is Rejected */
      RetVal = SPI_JOB_FAILED;
  }

  /*
  This service shall return the last transmission
  result of the specified Job.
  */
  if (RetVal != SPI_JOB_FAILED)
  #endif
 /* ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) ) */
  {
    RetVal = (Spi_JobResultType)Spi_lGetJobStatus(Job);
  }
  return RetVal;

} /* End of Function: Spi_GetJobResult */

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI183_SPI323,
DS_AS_SPI046_8_SPI242_8,DS_AS_SPI256_8,DS_AS_SPI032_3,
DS_AS_SPI238_2,DS_AS_SPI254_3,
DS_AS_SPI039_SPI042_SPI324_SPI351_SPI352_SPI353_SPI354]                       **
** Syntax : Spi_SeqResultType Spi_GetSequenceResult(Spi_SequenceType Sequence)**
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x08                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Sequence - Sequence ID. An invalid sequence ID will      **
**                   return an undefined result.                              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Spi_SeqResultType                                        **
**                                                                            **
** Description : This service return the last transmission result             **
** of the specified Sequence                                                  **
** The user call Spi_GetSequenceResult() method to know if the                **
** full Sequence transmission succeeded (SPI_SEQ_OK) or failed.               **
**                                                                            **
*******************************************************************************/
Spi_SeqResultType Spi_GetSequenceResult(Spi_SequenceType Sequence)
{
  Spi_SeqResultType RetVal = SPI_SEQ_OK;

  #if ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) )

  /* API  called before initialization */
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  if (E_NOT_OK == Spi_lGetDetInitStatus(SPI_SID_GETSEQUENCERESULT))
  {
    /* In case of DET, Service is Rejected */
    RetVal = SPI_SEQ_FAILED;
  }
  #endif

  /*
  Sequence shall be within the specified range of
  values (0 to SPI_MAX_SEQUENCE )
  */
 #if (SPI_DEV_ERROR_DETECT == STD_ON)
  if ((RetVal != SPI_SEQ_FAILED) &&
      (Sequence >= Spi_kConfigPtr->NoOfSequences))
 #else
  if (Sequence >= Spi_kConfigPtr->NoOfSequences)
 #endif
  {
    /* Report to DET */
    #if (SPI_DEV_ERROR_DETECT == STD_ON)
    Det_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_GETSEQUENCERESULT, SPI_E_PARAM_SEQ );
    #endif

    #if (SPI_SAFETY_ENABLE == STD_ON)
    SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_GETSEQUENCERESULT, SPI_E_PARAM_SEQ );
     /* [cover parentID=DS_MCAL_SPI_9841_12][/cover] */
    #endif

    /* In case of DET or Safety error, Service is Rejected */
    RetVal = SPI_SEQ_FAILED;
  }

  /*
    This service shall return the last transmission result of the
    specified Sequence.
  */
  /* SeqStatus : Holds the result of all sequences */
  /*
    SeqCancelStatus : Holds the last cancel status of the sequence until it
    is started again
  */
  if (RetVal != SPI_SEQ_FAILED)
  #endif
  /* ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) ) */
  {
    #if(SPI_LEVEL_DELIVERED != 0U)

    #if ((SPI_CANCEL_API == STD_ON) && (SPI_LEVEL_DELIVERED != 0U))
    uint16 Index;
    #endif

    #if (SPI_SAFETY_ENABLE == STD_ON)
    {
      /* ASIL or QM sequence index from map configuration*/
      #if ((SPI_CANCEL_API == STD_ON) && (SPI_LEVEL_DELIVERED != 0U))
      Index = (uint16)
              ((uint16)Spi_kConfigPtr->SpiMapConfigPtr->SeqIndex[Sequence]
              >> SPI_SEQUENCE_INDEX);
      #endif
    }
    #else
    {
      /* if safety is OFF then map config is absent */
      #if ((SPI_CANCEL_API == STD_ON) && (SPI_LEVEL_DELIVERED != 0U))
      Index = (uint16)((uint16)Sequence
              >> SPI_SEQUENCE_INDEX);
      #endif
    }
    #endif
    #endif

    /* Disable intr to protect SeqCancelStatus */
    SchM_Enter_Spi_GetSequenceResult();

    /*
    This handling is valid only for Async Modes. The shadow veriable
    SeqCancelStatus is not used in Sync Mode
    */
    #if (SPI_SAFETY_ENABLE == STD_ON)
      if( SPI_ASIL_SEQUENCE == Spi_lGetSequenceKind(Sequence) )
      {
          #if ((SPI_CANCEL_API == STD_ON) && (SPI_LEVEL_DELIVERED != 0U))
          RetVal = (Spi_SeqResultType)\
                          (((Spi_AsilSeqStatus[Index].AsilSeqStatus |\
                             Spi_AsilSeqStatus[Index].AsilSeqCancelStatus) >> \
                            (SPI_SEQUENCE_STATUS_BITS * (Sequence & \
                             SPI_SEQUENCE_BIT_POSITION))) & \
                           SPI_SEQUENCE_STATUS_EXTRACT);
          #else
          RetVal = Spi_lGetSeqStatus(Sequence);
          #endif
          /* ((SPI_CANCEL_API == STD_ON) && (SPI_LEVEL_DELIVERED != 0)) */
      }
      else
      {
        #if ((SPI_CANCEL_API == STD_ON) && (SPI_LEVEL_DELIVERED != 0U))
        #if (SPI_QM_MASTER_MODULES_USED != 0U)
        RetVal = (Spi_SeqResultType)\
                        (((Spi_QmSeqStatus[Index].QmSeqStatus |\
                           Spi_QmSeqStatus[Index].QmSeqCancelStatus) >>\
                          (SPI_SEQUENCE_STATUS_BITS * (Sequence & \
                           SPI_SEQUENCE_BIT_POSITION))) & \
                         SPI_SEQUENCE_STATUS_EXTRACT);
        #endif
        #else
        RetVal = Spi_lGetSeqStatus(Sequence);
        #endif
        /* ((SPI_CANCEL_API == STD_ON) && (SPI_LEVEL_DELIVERED != 0)) */
      }
    #else
    {
        #if ((SPI_CANCEL_API == STD_ON) && (SPI_LEVEL_DELIVERED != 0U))
        RetVal = (Spi_SeqResultType)\
                        (((Spi_QmSeqStatus[Index].QmSeqStatus |\
                           Spi_QmSeqStatus[Index].QmSeqCancelStatus) >>\
                          (SPI_SEQUENCE_STATUS_BITS * (Sequence & \
                           SPI_SEQUENCE_BIT_POSITION))) & \
                         SPI_SEQUENCE_STATUS_EXTRACT);
        #else
        RetVal = Spi_lGetSeqStatus(Sequence);
        #endif
        /* ((SPI_CANCEL_API == STD_ON) && (SPI_LEVEL_DELIVERED != 0)) */
    }
    #endif
    /* (SPI_SAFETY_ENABLE == STD_ON) */

    /* Exit Critical Section */
    SchM_Exit_Spi_GetSequenceResult();
  }
  return RetVal;

} /* End of Function: Spi_GetSequenceResult */

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI185_SPI327,
DS_AS_SPI046_10_SPI242_10,DS_AS_SPI256_10,DS_AS_SPI032_2,
DS_AS_SPI238_3,DS_AS_SPI254_4,
DS_AS_SPI134_SPI136_SPI245_SPI285_SPI328_SPI329_SPI330,
DS_AS4XX_SPI135,DS_AS3XX_SPI135 ]                                             **
** Syntax : Std_ReturnType Spi_SyncTransmit                                   **
**          (                                                                 **
**            Spi_SequenceType Sequence                                       **
**          )                                                                 **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x0A                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Sequence - Sequnece ID.                                  **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK - Transmission command has been accepted.           **
**                   E_NOT_OK - Transmission command has been accepted.       **
**                                                                            **
** Description :  Sync Service to transmit data on the SPI bus .              **
** This service shall take over the given parameter, initiate a transmission, **
** and set the SPI Handler/Driver status to SPI_BUSY, set the sequence result **
** to SPI_SEQ_PENDING, set the first job result to SPI_JOB_PENDING and return.**
** The LEVEL 0 SPI Handler/Driver shall offer a synchronous transfer          **
** service for SPI busses. When there is no on-going Sequence transmission,   **
** the SPI Handler/Driver shall be in idle state (SPI_IDLE).                  **
**  Hence, the LEVEL 0 SPI Handler/Driver shall not allow transmitting        **
** more than one Sequence at the same time. That means during a Sequence      **
** on-going transmission, all requests to transmit another Sequence shall be  **
** rejected.                                                                  **
** The LEVEL 2 SPI Handler/Driver shall offer a synchronous transfer          **
** service for a dedicated SPI bus and it shall also offer an asynchronous    **
** transfer service for others SPI busses. When there is no on-going Sequence **
** transmission, the SPI Handler/Driver shall be in idle state (SPI_IDLE).    **
*******************************************************************************/
/*[cover parentID=DS_AS_SPI109_2*/
#if ((SPI_LEVEL_DELIVERED == 0U) || (SPI_LEVEL_DELIVERED == 2U))
/* [/cover]*/
#if(SPI_LEVEL2_ASYNC_ONLY == STD_OFF)
Std_ReturnType Spi_SyncTransmit(Spi_SequenceType Sequence)
{

  Std_ReturnType RetVal;
  #if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_OFF)
  uint32 Synclock;
  #else
  uint32 TempHwUse = 0U;
  #endif

  #if ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) )
  RetVal = Spi_lSyncTransmitDetCheck(Sequence);

  if (RetVal == E_OK)
  #endif
  /* ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) ) */
  {

    #if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_OFF)
    /* The synchronous service is already started. No other
     sequences can be started. This is implemented using a binary semaphore
     mechanism*/
    Synclock = (uint32)Mcal_LockResource(&Spi_SyncLock);
    /* No other Sync transmission is in progress */
    if (Synclock != MCAL_RESOURCE_BUSY)
    {
      /* Set Return Value to E_OK to indicate sucess of function*/
      RetVal = E_OK;
      Spi_lSyncTransmit(Sequence);
      /* Release the lock so that other sequence can be started */
      Mcal_UnlockResource(&Spi_SyncLock);
      #if (SPI_LEVEL_DELIVERED == 2U)
      Spi_BusStatus = Spi_lGetSeqAsyncBusStatus(Sequence);
      #else
      Spi_BusStatus = SPI_IDLE;
      #endif
    }
    else
    {
      RetVal  = E_NOT_OK;
    }
    #else /* i.e else of SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON */
    SchM_Enter_Spi_SyncTransmit();

    /* check if Currently HwBuses for given seq are Free */
    /*IFX_MISRA_RULE_17_04_STATUS="SpiSequenceConfigPtr" Pointer arithmetic used
      due to PBConfigStructure and is within allowed range.*/
    if ((Spi_kConfigPtr->SpiSequenceConfigPtr[Sequence].HwModuleUsed &
                 Spi_CurHwUsed ) == 0U)
    {
      /* Update the Current Hw used variable */
      /*IFX_MISRA_RULE_17_04_STATUS="SpiSequenceConfigPtr" Pointer arithmetic
        used due to PBConfigStructure and is within allowed range.*/
      Spi_CurHwUsed |=
        Spi_kConfigPtr->SpiSequenceConfigPtr[Sequence].HwModuleUsed;
      TempHwUse = 1U;
    }

    /* Release the lock so that other sequence on different bus can be started*/
    SchM_Exit_Spi_SyncTransmit();
    /* if Hw bus is free continue */

    if (TempHwUse == 1U)
    {
      /* Set Return Value to E_OK to indicate sucess of function*/
      RetVal = E_OK;
      Spi_BusStatus = SPI_BUSY;
      Spi_lSyncTransmit(Sequence);
      /* Clear the Current Hw used bus variable. */
      /*IFX_MISRA_RULE_17_04_STATUS="SpiSequenceConfigPtr" Pointer arithmetic
        used due to PBConfigStructure and is within allowed range.*/
      Spi_CurHwUsed &= (uint8)
        ~Spi_kConfigPtr->SpiSequenceConfigPtr[Sequence].HwModuleUsed;
      if (Spi_CurHwUsed == 0U)
      {
        #if (SPI_LEVEL_DELIVERED == 2U)
        Spi_BusStatus = Spi_lGetSeqAsyncBusStatus(Sequence);
        #else
        Spi_BusStatus = SPI_IDLE;
        #endif
      }
    }
    else
    {
      /* Hw Bus is not available */
      RetVal = E_NOT_OK;
    }
    #endif

   #if (SPI_DEV_ERROR_DETECT == STD_ON)
   if (RetVal == E_NOT_OK)
   {
     /*
     If a request is done while a Sequence is on transmission, the SPI
     Handler/Driver does not take in account this new request and this service
     returns value E_NOT_OK. The SPI Handler/Driver shall
     report the SPI_E_SEQ_IN_PROCESS error.
     */
     /* Report to DET */
     Det_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_SYNCTRANSMIT, SPI_E_SEQ_IN_PROCESS );
   }
   #endif
   /* SPI_DEV_ERROR_DETECT */
  } /* (RetVal == E_OK) */
  return(RetVal);
}
#endif /* SPI_LEVEL2_ASYNC_ONLY == STD_OFF */
#endif /* SPI_LEVEL2_ASYNC_ONLY == STD_OFF */
 /* ((SPI_LEVEL_DELIVERED == 0) || (SPI_LEVEL_DELIVERED == 2U)) */

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI186_SPI331,
DS_AS_SPI046_11_SPI242_11, DS_AS_SPI256_11,
DS_AS_SPI141_SPI142_SPI143_SPI241_SPI260_SPI287_SPI288_SPI332_SPI348_SPI349]  **
** Syntax:          Spi_StatusType Spi_GetHWUnitStatus                        **
**                  (                                                         **
**                     Spi_HWUnitType        HWUnit                           **
**                   )                                                        **
** [/cover]                                                                   **
** Service ID:       0x0B                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  HWUnit- SPI Bus identifier                               **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :This service return the status of the specified               **
** SPI Hardware microcontroller peripheral.The user call Spi_GetHWUnitStatus()**
** method to know if the specified SPI Hardware microcontroller peripheral    **
** is SPI_IDLE or SPI_BUSY.                                                   **
** This function is pre compile time configurable                             **
** On / Off by the configuration parameter: SPI_HW_STATUS_API.                **
** Note that the HW Bus is busy only if a Job is running on it.If the HW Bus  **
** is Idle it can be assumed that no job is running on it currently but a job **
** could be pending and can be scheduled to run on the bus later              **
*******************************************************************************/
#if (SPI_HW_STATUS_API == STD_ON)
Spi_StatusType Spi_GetHWUnitStatus(Spi_HWUnitType HWUnit)
{
  Spi_StatusType RetVal;
  uint8 Module ;
  RetVal = SPI_IDLE;
  Module = HWUnit & SPI_HWUNIT_MASK;

  #if (SPI_PB_FIXEDADDR == STD_OFF)
  if ((Module >= (uint32)SPI_MAX_HW_UNIT) ||
                                   (Spi_kConfigPtr == NULL_PTR))
  #endif
 /*(SPI_PB_FIXEDADDR == STD_OFF)*/
  #if (SPI_PB_FIXEDADDR == STD_ON)
  if ((Module >= (uint32)SPI_MAX_HW_UNIT) || \
                              (Spi_InitStatus == SPI_DRIVER_DEINITIALIZED))
  #endif
 /*(SPI_PB_FIXEDADDR == STD_OFF)*/
  {
    #if ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) )
    /* HWUnit shall be within the specified range of values.
       Related error value: SPI_E_PARAM_UNIT. Otherwise, the service is not
       done and the return value shall be SPI_UNINIT.*/
    if (Module >= (uint32)SPI_MAX_HW_UNIT)
    {
      /* Report to DET */
      #if (SPI_DEV_ERROR_DETECT == STD_ON)
      Det_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_GETHWUNIITSTATUS, SPI_E_PARAM_UNIT );
      #endif

      #if (SPI_SAFETY_ENABLE == STD_ON)
      SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_GETHWUNIITSTATUS, SPI_E_PARAM_UNIT );
     /* [cover parentID=DS_MCAL_SPI_9841_14][/cover] */
      #endif
    }
    #endif
   /* ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) ) */
    RetVal = SPI_UNINIT;
  }
  /* The Spi HW is busy with Job Transmission if the "EN" bit is set */
  else if (0U != Spi_lHwGetModuleStatus(Module))
  {
    RetVal = SPI_BUSY;
  }
  else
  {
    /* RetVal is SPI_IDLE  */
  }

  return RetVal;

} /* End of Function: Spi_GetHWUnitStatus */
#endif
/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI187_SPI333,
DS_AS_SPI046_12_SPI242_12,
DS_AS_SPI256_12,DS_AS_SPI032_4,DS_AS_SPI238_4,
DS_AS_SPI144_SPI145_1_SPI146_SPI334 ]                                         **
** Syntax:           void Spi_Cancel                                          **
**                   (                                                        **
**                     Spi_SequenceType        Sequence                       **
**                   )                                                        **
** [/cover]                                                                   **
**                                                                            **
**                                                                            **
** Service ID:       0x0C                                                     **
**                                                                            **
** Sync/Async:       Asynchronous                                             **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  Sequence                                                 **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description : This service cancel the specified on-going                   **
** sequence transmission without cancelling any Job transmission and the SPI  **
** Handler/Driver will set the sequence result to SPI_SEQ_CANCELLED.          **
** The SPI Handler/Driver is not responsible on external devices damages or   **
** undefined state due to cancelling a sequence transmission. It is up to the **
** user to be aware of what user is doing!                                    **
*******************************************************************************/
#if (SPI_CANCEL_API == STD_ON)
void Spi_Cancel(Spi_SequenceType Sequence)
{
  #if (SPI_LEVEL_DELIVERED != 0U)
  Spi_JobAndSeqAccessType   *JobSeqDataPtr;
  const Spi_SequenceConfigType* ParamSeqConfigPtr;
  uint32 JobCounter;
  Spi_JobType JobId;
  #endif

  #if (SPI_SEQ_END_NOTIF_REQ == STD_ON)
  const Spi_SequenceConfigType* SeqConfigPtr;
  #endif

  #if ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) )
  uint8 RetVal = E_OK;
  /* API  called before initialization */
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  Spi_SeqResultType GetSeqStatus;
  RetVal = Spi_lGetDetInitStatus(SPI_SID_CANCEL);
  if (RetVal == E_OK)
  #endif
  /* (SPI_DEV_ERROR_DETECT == STD_ON) */
  {
    /*
    Sequence shall be within the specified range of
    values (0 to SPI_MAX_SEQUENCE )
    */
    /* If the sequence is not a valid sequence Id a DET is issued */
    /* If the user tries to cancel a non-pending sequence a DET is issued */
    if (Sequence >= Spi_kConfigPtr->NoOfSequences)
    {
      /* Report to DET */
      #if (SPI_DEV_ERROR_DETECT == STD_ON)
      Det_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_CANCEL, SPI_E_PARAM_SEQ );
      #endif

      #if (SPI_SAFETY_ENABLE == STD_ON)
      SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_CANCEL, SPI_E_PARAM_SEQ );
     /* [cover parentID=DS_MCAL_SPI_9841_15][/cover] */
      #endif

      /* In case of DET or Safety error, Service is Rejected */
      RetVal = E_NOT_OK;
    }
    else
    {
      #if (SPI_DEV_ERROR_DETECT == STD_ON)
      GetSeqStatus = Spi_lGetSeqStatus(Sequence);
      if( GetSeqStatus != SPI_SEQ_PENDING)
      {
        /* Report to DET */
        Det_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_CANCEL, SPI_E_PARAM_SEQ );

        /* In case of DET or Safety error, Service is Rejected */
        RetVal = E_NOT_OK;
      }
      else
      #endif
      {
        RetVal = E_OK;
      }
    }
  }
  #endif
 /*( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) )*/

  #if((SPI_SAFETY_ENABLE == STD_ON) && (SPI_QM_ASYNC_MASTER_MODULES_USED == 0U))
  #if (SPI_LEVEL_DELIVERED != 0U)
  JobSeqDataPtr = NULL_PTR; /* To remove warning: Possibly Uninitialised*/
  #endif
  #endif

  #if ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) )
  if (RetVal == E_OK)
  #endif
  {
    #if (SPI_LEVEL_DELIVERED != 0U)
    #if (SPI_SAFETY_ENABLE == STD_ON)
      if( SPI_ASIL_SEQUENCE == Spi_lGetSequenceKind(Sequence) )
      {
        JobSeqDataPtr = &Spi_AsilJobAndSeqAccess;
      }
      else
      {
        #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
        #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
        JobSeqDataPtr = &Spi_QmJobAndSeqAccess;
        #else
        JobSeqDataPtr = &Spi_QmJobAndSeqAccess[\
                                        Spi_lGetQmModuleVarIndexSeq(Sequence)];
        #endif
        #endif
        /* Do nothing if QM modules are NOT Used */
      }
    #else
      {
        #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
        JobSeqDataPtr = &Spi_QmJobAndSeqAccess;
        #else
        JobSeqDataPtr = &Spi_QmJobAndSeqAccess[\
                                        Spi_lGetQmModuleVarIndexSeq(Sequence)];
        #endif
      }
    #endif
    #endif

    /* Semaphore to protect SeqCancelStatus */
    SchM_Enter_Spi_Cancel();

    /* Set Sequence Cancelled */
    Spi_lSetSeqStatus(Sequence, SPI_SEQ_CANCELED);
    #if (SPI_LEVEL_DELIVERED != 0U) /*Used Only in Async Mode*/
    /* If the Sequence is not the current running sequence, then set the
       sequence to OK so that it can be started again */
    #if (SPI_LEVEL_DELIVERED == 2U)

    if (   (Sequence !=
            JobSeqDataPtr->JobLinkedSeq[JobSeqDataPtr->StartIndexExtractJobId])
        && (Sequence >= Spi_kConfigPtr->NoOfSyncSequences)
      )
    {
      Spi_lSetSeqStatus(Sequence, SPI_SEQ_OK);
      /* Set the Shadow Flag to indicate that the sequence is cancelled for the
       status functions.
       This is need because the main status variable SeqStatus is set
       to SPI_SEQ_OK so that the cancelled sequence can be started again.
       Also the cancelled sequence does not block other sequences that
       shares a job with this sequence */
      Spi_lSetSeqCancelStatus(Sequence);
    }
    #else
    if ( (Sequence !=
          JobSeqDataPtr->JobLinkedSeq[JobSeqDataPtr->StartIndexExtractJobId])
      )
    {
      Spi_lSetSeqStatus(Sequence, SPI_SEQ_OK);
      /* Set the Shadow Flag to indicate that the sequence is cancelled for the
       status functions.
       This is need because the main status variable SeqStatus is set
       to SPI_SEQ_OK so that the cancelled sequence can be started again.
       Also the cancelled sequence does not block other sequences that
       shares a job with this sequence */
      Spi_lSetSeqCancelStatus(Sequence);
    }
    #endif
      /* Set the status of All queued Jobs in that seq to ok */
      /*IFX_MISRA_RULE_17_04_STATUS="SpiSequenceConfigPtr" Pointer arithmetic
        used due to PBConfigStructure and is within allowed range.*/
      ParamSeqConfigPtr = &(Spi_kConfigPtr->SpiSequenceConfigPtr[Sequence]);
      JobCounter = 0U;

      /*IFX_MISRA_RULE_17_04_STATUS="JobLinkPtr" Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      while (
      JobSeqDataPtr->JobQueue[JobSeqDataPtr->StartIndexExtractJobId] !=
                   ParamSeqConfigPtr->JobLinkPtr[JobCounter])
      {
        /*IFX_MISRA_RULE_17_04_STATUS="JobLinkPtr" Pointer arithmetic used due
          to PBConfigStructure and is within allowed range.*/
        if (ParamSeqConfigPtr->JobLinkPtr[JobCounter] == \
                                                 SPI_JOB_LINK_DELIMITER)
        {
          break;
        }
        JobCounter++;
      }

        /*IFX_MISRA_RULE_17_04_STATUS="JobLinkPtr" Pointer arithmetic used due
          to PBConfigStructure and is within allowed range.*/
        while (ParamSeqConfigPtr->JobLinkPtr[JobCounter] != \
                                                 SPI_JOB_LINK_DELIMITER)
        {
          /* extract each job id from the sequence */
         /*IFX_MISRA_RULE_17_04_STATUS="JobLinkPtr" Pointer arithmetic used due
            to PBConfigStructure and is within allowed range.*/
          JobId = ParamSeqConfigPtr->JobLinkPtr[JobCounter];

          Spi_lSetJobStatusAtomic(JobId,SPI_JOB_OK );
          JobCounter++;
        }
    #endif
    #if (SPI_SLAVE_ENABLE == STD_ON)
    Spi_lSlaveCancel(Sequence);
    #endif
 /*(SPI_LEVEL_DELIVERED != 0)*/

    /* Exit Critical Section */
    SchM_Exit_Spi_Cancel();

    #if (SPI_SEQ_END_NOTIF_REQ == STD_ON)
   /*IFX_MISRA_RULE_17_04_STATUS="SpiSequenceConfigPtr" Pointer arithmetic used
      due to PBConfigStructure and is within allowed range.*/
    SeqConfigPtr = &(Spi_kConfigPtr->SpiSequenceConfigPtr[Sequence]);
    if (SeqConfigPtr->SeqEndNotification != NULL_PTR)
    {
      /*After the seq is cancelled if the
      corresponding "End Seq Notification" is configured as non null
      pointer, it shall be called.*/
      (SeqConfigPtr->SeqEndNotification)();
    }/*(SeqConfigPtr->SeqEndNotification != NULL_PTR)*/
    #endif
 /*(SPI_SEQ_END_NOTIF_REQ == STD_ON)*/
  }
}
#endif
 /* SPI_CANCEL_API = STD_ON */

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI188_SPI335_SPI172,
DS_AS_SPI046_13_SPI242_13,DS_AS_SPI256_13,DS_AS_SPI155_3,
DS_AS_SPI152_SPI154_SPI156_SPI171_SPI336_SPI337_SPI338_SPI362,
DS_AS_SPI361 ]                                                                **
** Syntax:          Std_ReturnType Spi_SetAsyncMode                           **
**                  (                                                         **
**                    Spi_AsyncModeType        Mode                           **
**                  )                                                         **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       0x0D                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       Non reentrant                                            **
**                                                                            **
** Parameters (in):  Mode                                                     **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     E_OK -     command has been accepted.                    **
**                   E_NOT_OK - command has not been accepted.                **
**                                                                            **
** Description : This function is pre compile time selectable by the          **
** configuration parameter: SPI_LEVEL_DELIVERED. This function is only        **
** relevant for LEVEL 2 and implemented with one polling mechanism mode and   **
** one with interrupt mechanism mode for SPI busses handled asynchronously.   **
** Both mechanisms are selectable during execution time .                     **
*******************************************************************************/
#if (SPI_LEVEL_DELIVERED == 2U)
Std_ReturnType Spi_SetAsyncMode(Spi_AsyncModeType Mode)
{
  Std_ReturnType RetValue = E_OK;
  Spi_StatusType Temp;

  #if ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) )

  /* API  called before initialization */
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  if (Spi_lGetDetInitStatus(SPI_SID_SETAYNCMODE) == E_NOT_OK)
  {
    RetValue = E_NOT_OK;
  }
  else
  {
    RetValue = E_OK;
  }
  #endif

  #if (SPI_SAFETY_ENABLE == STD_ON)
  if ((Mode != (Spi_AsyncModeType)SPI_ASYNC_MODE_POLLING) &&
      (Mode != (Spi_AsyncModeType)SPI_ASYNC_MODE_INTERRUPT))
  {
    /* report to upper layer */
    SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_SETAYNCMODE, SPI_E_PARAM_MODE );
     /* [cover parentID=DS_MCAL_SPI_9841_16][/cover] */
    RetValue = E_NOT_OK;
  }
  #endif
  /* (SPI_SAFETY_ENABLE == STD_ON) */

  if (RetValue == E_OK)
  #endif
  /*( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) )*/
  {
    /* If a request is done while the SPI Handler/Driver status is not in
       SPI_IDLE, it does not take in account this new request, the mode is kept
       as it is and this service returns value E_NOT_OK.*/

    Temp = Spi_GetStatus();

    if ( Temp == SPI_IDLE)
    {
      Spi_AsyncMode = (uint8)(Mode);
      /* If the Mode Requested is Interrupt Mode */
      if (Mode == (Spi_AsyncModeType)SPI_INTERRUPT_MODE)
      {
        /* Configure Spi Hw/s for Interrupt Mode  */
        Spi_lHwSetAsyncModeToIntr();
      }
      else /* Polling Mode */
      {
        /* Configure Spi Hw/s for Polling Mode  */
        Spi_lHwSetAsyncModeToPoll();
      }
      RetValue = E_OK;
    }
    else if(SPI_BUSY != Spi_lGetAsyncBusStatus())
    {
      Spi_AsyncMode = (uint8)(Mode);
      /* If the Mode Requested is Interrupt Mode */
      if (Mode == (Spi_AsyncModeType)SPI_INTERRUPT_MODE)
      {
        /* Configure Spi Hw/s for Interrupt Mode  */
        Spi_lHwSetAsyncModeToIntr();
      }
      else /* Polling Mode */
      {
        /* Configure Spi Hw/s for Polling Mode  */
        Spi_lHwSetAsyncModeToPoll();
      }
      RetValue = E_OK;
    }
    else
    {
      RetValue = E_NOT_OK;
    }
  }
  return (Std_ReturnType)RetValue;
}
#endif
 /* SPI_LEVEL_DELIVERED == 2U */

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI189,
DS_AS_SPI155_4,DS_AS_SPI007_2 ]                                               **
** Syntax           : void Spi_MainFunction_Handling(void)                    **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x10                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Timing           : Fixed Cyclic                                            **
**                    The user has to determine the cycle rate depending upon **
**                    the baud rate of the transmission and frequency of the  **
**                    job scheduling required.                                **
**                                                                            **
** Description      : This function replaces the interrupt mechanism used     **
** to handle jobs on the bus. The function polls for the completion of a      **
** channel transmission (a DMA Tansaction) and calls the                      **
** function:SpilBusHandler. In addition this function also checks for errors  **
** (production) on the SPI bus and performs the needed error handling (calls  **
** Spi_lErrorHandler)                                                         **
*******************************************************************************/
#if (((SPI_LEVEL_DELIVERED == 1U) && \
(SPI_ASYNC_MODE_LEVEL1 == SPI_ASYNC_MODE_POLLING)) \
|| (SPI_LEVEL_DELIVERED == 2U))
#if((SPI_QM_ASYNC_MASTER_MODULES_USED != 0U))
void Spi_MainFunction_Handling(void)
{

  uint32 DmaErrorstatus;
  Dma_ChannelType  DmaTransmitChannel;
  Dma_ChannelType  DmaReceiveChannel;

  uint32 ModLoopCtr = 0U;

  uint32 QmModIndex = 0U;

  #if (SPI_LEVEL_DELIVERED == 2U)
  if (Spi_AsyncMode == (uint8) SPI_POLLING_MODE)
  {
  #endif
 /*(SPI_LEVEL_DELIVERED == 2U)*/

  do
  {
    if(Spi_lModuleConfiguredAndAsync((uint8)ModLoopCtr) != 0U)
    {
       DmaTransmitChannel = \
                       Spi_QmChnlAccess[QmModIndex].DmaChannelIdx.TxDmaChannel;
       DmaReceiveChannel  = \
                       Spi_QmChnlAccess[QmModIndex].DmaChannelIdx.RxDmaChannel;
       /* Increment only if  QM master module is configured as ASYNC  */
       QmModIndex++;
       DmaErrorstatus =(uint32)SPI_SFR_RUNTIME_MCAL_DMAGETTRANSREQLOSTFLAG\
                                                           (DmaTransmitChannel);
       DmaErrorstatus |= Spi_lDmaGetBothMoveEngErrFlags(SPI_RUNTIME_ACCESS);
       DmaErrorstatus |= (uint32)SPI_SFR_RUNTIME_MCAL_DMAGETTRANSREQLOSTFLAG\
                                                            (DmaReceiveChannel);
       Spi_lMainFunctionErrorCheck(DmaErrorstatus,ModLoopCtr,\
                                         DmaTransmitChannel,DmaReceiveChannel);
    }
    else
    {
      /* Do nothing if QSPI module is not configured */
    }
    ModLoopCtr++;
  }while (ModLoopCtr < SPI_MAX_HW_UNIT);

  #if (SPI_LEVEL_DELIVERED == 2U)
  }
  #endif
}
#endif
#endif
/* (SPI_LEVEL_DELIVERED == 1U &&
SPI_ASYNC_MODE_LEVEL1 == SPI_ASYNC_MODE_POLLING) ||
(SPI_LEVEL_DELIVERED == 2U) */

/*******************************************************************************
** Traceability : [cover parentID=DS_MCAL_SPI_0402_1]                         **
**                                                                            **
** Syntax : void Spi_IsrDmaQspiTx(uint32 Module)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant for the same QSPI bus                          **
**              Re-entrant for different QSPI bus(AsyncParallelTransmit)      **
**                                                                            **
** Parameters (in) : Module : Hardware unit used. Qspix                       **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine should be called in the TX-Dma Channel          **
** (Transaction complete / Error) Interrupt of QSPIx Module when              **
**  no Dma Error has occured.                                                 **
** This function  disables the Tx-Dma Channel interrupt and                   **
** also the Qspi Tx interrupt. Then it sets the BACON.LAST to 1               **
** and updates the last word to be transmitted on Qspix Hw. This transfers    **
** [i.e TX] the last word of Last Channel of job and puts the Chipselect to   **
** inactive state                                                             **
**                                                                            **
*******************************************************************************/
#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
void Spi_IsrDmaQspiTx(uint32 Module)
{
  Dma_ChannelType DmaTxChannel = DMA_CHANNEL_INVALID;
  uint32 DmaTxIntrStatus;

  /*Update the DATAENTRY = last_word, BACON. LAST = 1.
    (It will be called before the DMA RX channel ISR for the last channel.
    It transfers [TX] the last word of Last Channel of job and puts the
    Chipselect to inactive state)
  */
  #if (SPI_SAFETY_ENABLE == STD_ON)
  if ( 0U == (Spi_lModuleConfiguredAndAsync( (uint8)Module )))
  {
    /* report to upper layer */
    SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
         SPI_SID_ISRDMAQSPITX, SPI_E_PARAM_MODULE );
    /* [cover parentID=DS_MCAL_SPI_9841_17][/cover] */
  }/* Spi_lModuleConfiguredAndAsync() */
  else
  #endif
  /* (SPI_SAFETY_ENABLE == STD_ON) */
  {
    #if (SPI_SAFETY_ENABLE == STD_ON)
    if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)Module))
    {
      DmaTxChannel = Spi_AsilChnlAccess[0].DmaChannelIdx.TxDmaChannel;
    }
    else
    {
      #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
      DmaTxChannel = Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)].\
                                                   DmaChannelIdx.TxDmaChannel;
      #endif
      /* Do nothing if QM modules are NOT Used */
    }
    #else
    {
      DmaTxChannel = Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)].\
                                                   DmaChannelIdx.TxDmaChannel;
    }
    #endif

    /* Check ICH bit being Set for DMA TX channel */
    DmaTxIntrStatus = Mcal_DmaGetTransferIntStatus(DmaTxChannel);

    /* AoU : Interrupt Source Check */
    if(DmaTxIntrStatus == 1U)
    {
      /* DISABLE TX-DMA intr */
      Mcal_DmaDisableIntr(DmaTxChannel);
      /* Disable QSPI TX Interrupt */
      Spi_lHwDisableQspiTxIntr(Module, SPI_ISR_ACCESS);
      /* Clear/Reset Channel Interrupt control register */
      Mcal_DmaChClrIntctEtrlFlags(DmaTxChannel);
      Mcal_DmaChClrIntrFlags(DmaTxChannel);
      /* Update Bacon & data reg if status changes to expect */
      /* SRE bit is enabled but BaconReg.B.UINT controls the service request */
      Spi_lHwEnableQspiUsrIntr(Module);
    }
    else
    {
      #if (SPI_SAFETY_ENABLE == STD_ON)
      SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
           SPI_SID_ISRDMAQSPITX, SPI_E_INTR_SRC_ERROR);
      #endif
      /* Interrupt Source check failed */
    }
  }
} /* end of  Spi_IsrDmaQspiTx */
/*******************************************************************************
** Traceability : [cover parentID=DS_MCAL_SPI_0402_1]                         **
**                                                                            **
** Syntax : void Spi_IsrDmaQspiTxRuntime(uint32 Module)                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant for the same QSPI bus                          **
**              Re-entrant for different QSPI bus(AsyncParallelTransmit)      **
**                                                                            **
** Parameters (in) : Module : Hardware unit used. Qspix                       **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine should be called in the TX-Dma Channel          **
** (Transaction complete / Error) Interrupt of QSPIx Module when              **
**  no Dma Error has occured.                                                 **
** This function  disables the Tx-Dma Channel interrupt and                   **
** also the Qspi Tx interrupt. Then it sets the BACON.LAST to 1               **
** and updates the last word to be transmitted on Qspix Hw. This transfers    **
** [i.e TX] the last word of Last Channel of job and puts the Chipselect to   **
** inactive state                                                             **
**                                                                            **
*******************************************************************************/
#if (((SPI_LEVEL_DELIVERED == 1U) && \
(SPI_ASYNC_MODE_LEVEL1 == SPI_ASYNC_MODE_POLLING)) || \
(SPI_LEVEL_DELIVERED == 2U))
#if((SPI_QM_ASYNC_MASTER_MODULES_USED != 0U))
void Spi_IsrDmaQspiTxRuntime(uint32 Module)
{
  #if(SPI_LEVEL_DELIVERED == 2U)
  volatile Ifx_QSPI* ModulePtr;
  #endif
  Dma_ChannelType DmaTxChannel = DMA_CHANNEL_INVALID;
  uint32 DmaTxIntrStatus;

  /*Update the DATAENTRY = last_word, BACON. LAST = 1.
    (It will be called before the DMA RX channel ISR for the last channel.
    It transfers [TX] the last word of Last Channel of job and puts the
    Chipselect to inactive state)
  */
  #if (SPI_SAFETY_ENABLE == STD_ON)
  if ( 0U == (Spi_lModuleConfiguredAndAsync( (uint8)Module )))
  {
    /* report to upper layer */
    SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
         SPI_SID_ISRDMAQSPITXRUNTIME, SPI_E_PARAM_MODULE );
    /* [cover parentID=DS_MCAL_SPI_9841_17][/cover] */
  }/* Spi_lModuleConfiguredAndAsync() */
  else
  #endif
  /* (SPI_SAFETY_ENABLE == STD_ON) */
  {
    #if (SPI_SAFETY_ENABLE == STD_ON)
    if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)Module))
    {
      DmaTxChannel = Spi_AsilChnlAccess[0].DmaChannelIdx.TxDmaChannel;
    }
    else
    {
      #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
      DmaTxChannel = Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)].\
                                                   DmaChannelIdx.TxDmaChannel;
      #endif
      /* Do nothing if QM modules are NOT Used */
    }
    #else
    {
      DmaTxChannel = Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)].\
                                                   DmaChannelIdx.TxDmaChannel;
    }
    #endif

      /* Check ICH bit being Set for DMA TX channel */
      DmaTxIntrStatus = (uint32)SPI_SFR_RUNTIME_MCAL_DMAGETTRANSFERINTSTATUS\
                                                                 (DmaTxChannel);

    /* AoU : Interrupt Source Check */
    if(DmaTxIntrStatus == 1U)
    {
        /* DISABLE TX-DMA intr */
        SPI_SFR_RUNTIME_MCAL_DMADISABLEINTR(DmaTxChannel);
        /* Disable QSPI TX Interrupt */
        Spi_lHwDisableQspiTxIntr(Module, SPI_RUNTIME_ACCESS);
        /* Clear/Reset Channel Interrupt control register */
        SPI_SFR_RUNTIME_MCAL_DMACHCLRINTCTETRLFLAGS(DmaTxChannel);
        SPI_SFR_RUNTIME_MCAL_DMACHCLRINTRFLAGS(DmaTxChannel);
      /* Update Bacon & data reg if status changes to expect */
      /* SRE bit is enabled but BaconReg.B.UINT controls the service request */
      #if(SPI_LEVEL_DELIVERED == 2U)

      /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic
       is used to efficiently access the SFRs of multiple QSPI Modules.*/
       ModulePtr =  &(SPI_HW_MODULE[Module]);

       SPI_SFR_RUNTIME_USER_MODE_WRITE32(ModulePtr->BACONENTRY.U,\
               (SPI_SFR_RUNTIME_USER_MODE_READ32(ModulePtr->BACON.U) | 1U));
       /* Write to Spi Hw DATAENTRY register */
       Spi_lHwSendLastChannelData(Module, SPI_RUNTIME_ACCESS);
      #else
      Spi_lHwEnableQspiUsrIntr(Module);
      #endif
    }
    else
    {
      #if (SPI_SAFETY_ENABLE == STD_ON)
      SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
           SPI_SID_ISRDMAQSPITXRUNTIME, SPI_E_INTR_SRC_ERROR);
      #endif
      /* Interrupt Source check failed */
    }
  }
} /* end of  Spi_IsrDmaQspiTxRuntime */
#endif
#endif

/*******************************************************************************
** Traceability : [cover parentID=DS_MCAL_SPI_0402_3]                         **
** Syntax : void Spi_IsrQspiPt(uint32 Module)                                 **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant for the same QSPI bus                          **
**              Re-entrant for different QSPI bus(AsyncParallelTransmit)      **
**                                                                            **
** Parameters (in) : Module : Hardware unit used. Qspix                       **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine should be called in the Phase transition 2 (PT2)**
**  Interrupt of QSPIx Module.                                                **
*******************************************************************************/
void Spi_IsrQspiPt(uint32 Module)
{
   volatile Ifx_QSPI* ModulePtr;

   #if (SPI_SAFETY_ENABLE == STD_ON)
   if (0U == (Spi_lModuleConfiguredAndAsync( (uint8)Module )))
   {
     /* report to upper layer */
     SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
         SPI_SID_ISRQSPIPT, SPI_E_PARAM_MODULE );
     /* [cover parentID=DS_MCAL_SPI_9841_19][/cover] */
   }
   else
   #endif
   /* (SPI_SAFETY_ENABLE == STD_ON) */
   {
 /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used to
   efficiently access the SFRs of multiple QSPI Modules.*/
     ModulePtr = &(SPI_HW_MODULE[Module]);

     /* AoU : Interrupt Source Check */
     if(ModulePtr->STATUS.B.PT2F == 1U)
     { /* Clear the flag */
       ModulePtr->FLAGSCLEAR.B.PT2C = 1U;
       Spi_lBusHandler(Module, SPI_ISR_ACCESS);
     }
     else
     {
       #if (SPI_SAFETY_ENABLE == STD_ON)
       SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
           SPI_SID_ISRQSPIPT, SPI_E_INTR_SRC_ERROR);
       #endif
       /* Interrupt Source check failed */
     }
   }
}

/*******************************************************************************
** Traceability : [cover parentID=DS_MCAL_SPI_0402_4]                         **
** Syntax : void Spi_IsrQspiUsr(uint32 Module)                                **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant for the same QSPI bus                          **
**              Re-entrant for different QSPI bus(AsyncParallelTransmit)      **
**                                                                            **
** Parameters (in) : Module : Hardware unit used. Qspix                       **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine should be called in the User interrupt (PT1)    **
**  of QSPIx Module.                                                          **
*******************************************************************************/
void Spi_IsrQspiUsr(uint32 Module)
{
  volatile Ifx_QSPI* ModulePtr;

   #if (SPI_SAFETY_ENABLE == STD_ON)
   if (0U == (Spi_lModuleConfiguredAndAsync( (uint8)Module )))
   {
     /* report to upper layer */
     SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
         SPI_SID_ISRQSPIUSR, SPI_E_PARAM_MODULE );
     /* [cover parentID=DS_MCAL_SPI_9841_20][/cover] */
   }
   else
   #endif
   /* (SPI_SAFETY_ENABLE == STD_ON) */
   {
  /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used to
    efficiently access the SFRs of multiple QSPI Modules.*/
     ModulePtr =  &(SPI_HW_MODULE[Module]);

     /* AoU : Interrupt Source Check */
     if(ModulePtr->STATUS.B.USRF == 1U)
     {
       Spi_lHwDisableQspiUsrIntr(Module,SPI_ISR_ACCESS);

       ModulePtr->BACONENTRY.U= ModulePtr->BACON.U | 1U;

       /* Write to Spi Hw DATAENTRY register */
       Spi_lHwSendLastChannelData(Module, SPI_ISR_ACCESS);

       /* Not cleared immediately after checking since,
          Hardware sets the Flag as the DNA(Data Not Available Phase)
          persists till we put the last data into the buffer */
       /* Clear the Flag */
       ModulePtr->FLAGSCLEAR.B.USRC = 1U;
     }
     else
     {
       #if (SPI_SAFETY_ENABLE == STD_ON)
       SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
           SPI_SID_ISRQSPIUSR, SPI_E_INTR_SRC_ERROR);
       #endif
       /* Interrupt Source check failed */
     }
   }
}

#endif
 /* (SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U) */

/*******************************************************************************
** Traceability : [cover parentID=DS_MCAL_SPI_0402_2]                         **
** Syntax : void Spi_IsrQspiError(uint32 Module)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant for the same QSPI bus                          **
**              Re-entrant for different QSPI bus(AsyncParallelTransmit)      **
**                                                                            **
** Parameters (in) : Module : Hardware unit used. Qspix                       **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine should be called in the Error Interrupt of      **
** QSPIx Module.                                                              **
** This interrupt occurs in case of Receive / Phase Errors.                   **
** This interrupt is mapped to the node: QSPIx_ESRC                           **
** This function calls the                                                    **
** DEM with Error Code  - SPI_DEM_HW_ERROR (SPI007)                           **
** Additionally it sets the Job and Sequence Status to SPI_JOB_FAILED,        **
** SPI_SEQUENCE_FAILED respectively. Also it calls the Job end and sequence   **
** end notification if configured.CS is also Disabled.                        **
**                                                                            **
*******************************************************************************/
/* Fixed for AI00248112 */
#if ((SPI_LEVEL_DELIVERED != 0U) || (SPI_SLAVE_ENABLE == STD_ON))
void Spi_IsrQspiError(uint32 Module)
{
   #if ((SPI_SAFETY_ENABLE == STD_ON) && (SPI_LEVEL_DELIVERED != 0U))
   if (0U == (Spi_lAnyModuleConfigAndAsync( (uint8)Module )))
   {
     /* report to upper layer */
     SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
         SPI_SID_ISRQSPIERROR, SPI_E_PARAM_MODULE );
     /* [cover parentID=DS_MCAL_SPI_9841_18][/cover] */
   }
   else
   #endif
   /* ((SPI_SAFETY_ENABLE == STD_ON) && (SPI_LEVEL_DELIVERED != 0U)) */
   {

     /* HW Error Detected, Call DEM, Set Job and Seq Status to Failed.
       Call Notification if configured. */
     /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used to
       efficiently access the SFRs of multiple QSPI Modules.*/
     if (Spi_lHwCheckRxStatus((&(SPI_HW_MODULE[Module])), \
                                          SPI_ISR_ACCESS))/* if receive error */
     {
       #if(SPI_SLAVE_ENABLE == STD_ON)
       if(Module != SPI_SLAVE_MODULE_INDEX)
       {
       #endif
         #if(SPI_LEVEL_DELIVERED != 0U)
         if (SPI_BUSY == Spi_lGetModAsyncBusStatus((uint8)Module))
         {
           Spi_lErrorHandler(Module, (uint32)SPI_DEM_HW_ERROR, SPI_ISR_ACCESS);
         }
         else
         {
           Spi_lHwClearErrIntr(Module); /* Clear error intr */
           /* Disable QSPI TX Interrupt */
           Spi_lHwDisableQspiTxIntr(Module, SPI_ISR_ACCESS);
           Spi_lHwDisableQspiRxIntr(Module, SPI_ISR_ACCESS);
           Spi_lHwDisableQspiErrIntr(Module);
           /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is
             used to efficiently access the SFRs of multiple QSPI Modules.*/
           Spi_lHwClrQspiPendEvent(&(SPI_HW_MODULE[Module]), SPI_ISR_ACCESS);
           /* Disable module */
           Spi_lHwDisableModule(Module, SPI_ISR_ACCESS);
           #if (SPI_HW_ERROR_DEM_REPORT == ENABLE_DEM_REPORT)
           /* Dem for receive error*/
           Dem_ReportErrorStatus(SPI_E_HARDWARE_ERROR,DEM_EVENT_STATUS_FAILED);
           #endif
         }
         #endif
         /*(SPI_LEVEL_DELIVERED != 0U)*/
       #if(SPI_SLAVE_ENABLE == STD_ON)
       }
       else
       {
           Spi_lSlaveErrorHandler(Module,(uint32)SPI_DEM_HW_ERROR,\
                                                                SPI_ISR_ACCESS);
           Spi_lHwClearErrIntr(Module); /* Clear error intr */
           Spi_lHwDisableQspiRxIntr(Module, SPI_ISR_ACCESS);
           Spi_lHwDisableQspiErrIntr(Module);
           /* Disable module */
           Spi_lHwDisableModule(Module, SPI_ISR_ACCESS);

           #if (SPI_HW_ERROR_DEM_REPORT == ENABLE_DEM_REPORT)
           /* Dem for receive error*/
             Dem_ReportErrorStatus(SPI_E_HARDWARE_ERROR,
                      DEM_EVENT_STATUS_FAILED);
           #endif
       }
       #endif
     }
     else
     {
       #if (SPI_SAFETY_ENABLE == STD_ON)
       SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
           SPI_SID_ISRQSPIERROR, SPI_E_INTR_SRC_ERROR);
       #endif
       /* Interrupt Source check failed */
     }
  }
}
#endif
 /* ((SPI_LEVEL_DELIVERED != 0U) || (SPI_SLAVE_ENABLE == STD_ON))*/

/*******************************************************************************
** Traceability : [cover parentID=DS_MCAL_SPI_0402_5]                         **
** Syntax : void Spi_IsrDmaQspiRx(uint32 Module)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant for the same QSPI bus                          **
**              Re-entrant for different QSPI bus(AsyncParallelTransmit)      **
**                                                                            **
** Parameters (in) : Module : Hardware unit used. Qspix                       **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine should be called in the Rx-DMA Channel          **
** (Transaction complete / Error) Interrupt of QSPIx Module when              **
**  no Dma Error has occured.                                                 **
** This function does the following activities:                               **
** 1. Sets up a new DMA transaction for the next channels in the Channel Link.**
** 2. If the channel transmitted is the last channel in a job link, and the   **
**    Sequences is not interruptible, the next job in the Job link is setup   **
**    If the Sequence is interrupible, the scheduler to schedule              **
**    the next job based on priority is called.                               **
** 3. At the end of the job if configured, a job end notification is called.  **
** 4. At the end of the Sequence, if configured, a seq end notification       **
**    is called.                                                              **
**                                                                            **
*******************************************************************************/
#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
void Spi_IsrDmaQspiRx(uint32 Module)
{

  Spi_JobAndSeqAccessType  *JobSeqDataPtr;
  Spi_ChnlAccessType      *ChnlAccDataPtr;
  uint32 Err;
  Dma_ChannelType DmaRxChannel;
  uint16 JobId;
  uint16 SICompletedJob;
  const Spi_JobConfigType* JobConfigPtr;
  Spi_ChannelType ChannelId;

  #if(SPI_SLAVE_ENABLE == STD_ON)
  if(Module != SPI_SLAVE_MODULE_INDEX)
  #endif
  {
    #if((SPI_SAFETY_ENABLE == STD_ON) && (SPI_QM_ASYNC_MASTER_MODULES_USED==0U))
    JobSeqDataPtr  = NULL_PTR; /* To remove warning: Possibly Uninitialised*/
    ChnlAccDataPtr = NULL_PTR; /* To remove warning: Possibly Uninitialised*/
    #endif
    #if (SPI_SAFETY_ENABLE == STD_ON)
    if (0U == (Spi_lModuleConfiguredAndAsync( (uint8)Module )))
    {
      /* report to upper layer */
      SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
          SPI_SID_ISRDMAQSPIRX, SPI_E_PARAM_MODULE );
      /* [cover parentID=DS_MCAL_SPI_9841_21][/cover] */
    }
    else
    #endif
    /* (SPI_SAFETY_ENABLE == STD_ON) */
    {
      #if (SPI_SAFETY_ENABLE == STD_ON)
      if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)Module))
      {
        JobSeqDataPtr  = &Spi_AsilJobAndSeqAccess;
        ChnlAccDataPtr = &Spi_AsilChnlAccess[0U];
      } /* SPI_ASIL_MASTER check  */
      else
      {
        #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
        #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
        JobSeqDataPtr  = &Spi_QmJobAndSeqAccess;
        #else
        JobSeqDataPtr =&Spi_QmJobAndSeqAccess[Spi_lGetQmModuleVarIndex(Module)];
        #endif
        ChnlAccDataPtr = &Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)];
        #endif
        /* Do nothing if QM modules are NOT Used */
      }/* else part of SPI_ASIL_MASTER check  */
      #else /* SPI_SAFETY_ENABLE = STD_OFF */
      {
        #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
        JobSeqDataPtr  = &Spi_QmJobAndSeqAccess;
        #else
        JobSeqDataPtr =&Spi_QmJobAndSeqAccess[Spi_lGetQmModuleVarIndex(Module)];
        #endif
        ChnlAccDataPtr = &Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)];
      }
      #endif
      /* end of SPI_SAFETY_ENABLE = STD_ON  */

      /* Call the Bus Handler only if the Bus is busy */
      if (SPI_BUSY == Spi_lGetModAsyncBusStatus((uint8)Module))
      {
        DmaRxChannel  = ChnlAccDataPtr->DmaChannelIdx.RxDmaChannel;
        Err = Mcal_DmaGetTransferIntStatus(DmaRxChannel);

        /* Check ICH bit being Set for DMA TX channel */
        if(Err == 1U)
        {
           Mcal_DmaChClrIntrFlags(DmaRxChannel);
       /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
            to efficiently access the SFRs of multiple QSPI Modules.*/
          Err = Spi_lHwCheckRxStatus(&(SPI_HW_MODULE[Module]), SPI_ISR_ACCESS);
          if (Err == 0U)
          {
            SICompletedJob = Spi_lCompletedJobId(JobSeqDataPtr);
            /* last job completed */
            /* extract the completed Job Id */
            JobId = JobSeqDataPtr->JobQueue[SICompletedJob];
            /*IFX_MISRA_RULE_17_04_STATUS="SpiJobConfigPtr" Pointer arithmetic
              used due to PBConfigStructure and is within allowed range.*/
            JobConfigPtr = &(Spi_kConfigPtr->SpiJobConfigPtr[JobId]);
         /*IFX_MISRA_RULE_17_04_STATUS="CurrentChannelIndex" Pointer arithmetic
              used due to PBConfigStructure and is within allowed range.*/
            ChannelId = JobConfigPtr->\
                      ChannelLinkPtr[ChnlAccDataPtr->CurrentChannelIndex + 1U];
            if (ChannelId != SPI_CHANNEL_LINK_DELIMITER)
            {
              Spi_lBusHandler(Module, SPI_ISR_ACCESS);
            } /* end of ChannelId != SPI_CHANNEL_LINK_DELIMITER */
            else
            {
              /*(SPI_LEVEL_DELIVERED == 2U)*/
               Spi_lHwEnableQspiPtIntr(Module);
            } /* end of else part ChannelId != SPI_CHANNEL_LINK_DELIMITER  */
          } /* Err == 0U  */
          else
          {
            Spi_lErrorHandler(Module, (uint32)SPI_DEM_HW_ERROR, SPI_ISR_ACCESS);
          } /* end of else part of Err ==0U  */
        }
        else
        {
          #if (SPI_SAFETY_ENABLE == STD_ON)
          SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
             SPI_SID_ISRDMAQSPIRX, SPI_E_INTR_SRC_ERROR);
          #endif
          /* Interrupt Source check failed */
        }
      }/*  end of SPI_BUSY == Spi_lGetModAsyncBusStatus((uint8)Module) */
    } /* end of else Spi_lModuleConfiguredAndAsync )*/
  } /* end of (Module != SPI_SLAVE_MODULE_INDEX)  */
  #if(SPI_SLAVE_ENABLE == STD_ON)
  else
  {
    /*Err = Mcal_DmaGetTransferIntStatus(DmaRxChannel);*/
    Err = Spi_lSlaveDmaGetTxIntStatus();

    /* Check ICH bit being Set for DMA TX channel */
    if(Err == 1U)
    {
      Spi_lSlaveDmaClrIntrFlag();
      /* Call the SPI Slave Bus Handler only if the Bus is busy */
    /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used to
        efficiently access the SFRs of multiple QSPI Modules.*/
      Err = Spi_lHwCheckSlaveRxStatus(&(SPI_HW_MODULE[Module]));
      if (Err == 0U)
      {
        Spi_lSlaveBusHandler(Module,SPI_ISR_ACCESS);
      }
      else
      {
        Spi_lSlaveErrorHandler(Module,(uint32)SPI_DEM_HW_ERROR,SPI_ISR_ACCESS);
      }
    }
    else
    {
      /* Interrupt Source check failed */
      #if (SPI_SAFETY_ENABLE == STD_ON)
      SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_ISRDMAQSPIRX, SPI_E_INTR_SRC_ERROR);
      #endif
    }
  } /* end of else part of  (Module != SPI_SLAVE_MODULE_INDEX) */
  #endif
} /* end of Spi_IsrDmaQspiRx */
#endif
 /* (SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U) */

#if ((SPI_LEVEL_DELIVERED == 0U) && (SPI_SLAVE_ENABLE == STD_ON))
/*******************************************************************************
** Traceability : [cover parentID=DS_MCAL_SPI_0402_5]                         **
** Syntax : void Spi_IsrDmaQspiRx(uint32 Module)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant for the same QSPI bus                          **
**              Re-entrant for different QSPI bus(AsyncParallelTransmit)      **
**                                                                            **
** Parameters (in) : Module : Hardware unit used. Qspix                       **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine is used only for SYNC MASTER and SLAVE enabled  **
**                                                                            **
*******************************************************************************/
void Spi_IsrDmaQspiRx(uint32 Module)
{
  uint32 Err;
  if (SPI_SLAVE_MODULE_INDEX != Module)
  {
    /* report to upper layer */
    SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
         SPI_SID_ISRDMAQSPIRX, SPI_E_PARAM_MODULE );
    /* [cover parentID=DS_MCAL_SPI_9841_23][/cover] */
  }
  else
  {
    Err = Spi_lSlaveDmaGetTxIntStatus();

    /* Check ICH bit being Set for DMA TX channel */
    if(Err == 1U)
    {
      Spi_lSlaveDmaClrIntrFlag();
    /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used to
        efficiently access the SFRs of multiple QSPI Modules.*/
      Err = Spi_lHwCheckSlaveRxStatus(&(SPI_HW_MODULE[Module]));
      if (Err == 0U)
      {
        Spi_lSlaveBusHandler(Module,SPI_ISR_ACCESS);
      }
      else
      {
        Spi_lSlaveErrorHandler(Module,(uint32)SPI_DEM_HW_ERROR,SPI_ISR_ACCESS);
      }
    }
    else
    {
      /* Interrupt Source check failed */
      #if (SPI_SAFETY_ENABLE == STD_ON)
      SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
          SPI_SID_ISRDMAQSPIRX, SPI_E_INTR_SRC_ERROR);
      #endif
    }
  }
}

/*******************************************************************************
** Traceability : [cover parentID=DS_MCAL_SPI_9004]                           **
** Syntax : void Spi_IsrDmaError(uint32 Module)                               **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant for the same QSPI bus                          **
**              Re-entrant for different QSPI bus(AsyncParallelTransmit)      **
**                                                                            **
** Parameters (in) : Module                                                   **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine is used only for SYNC MASTER and SLAVE enabled  **
**                                                                            **
*******************************************************************************/
void Spi_IsrDmaError(uint32 Module)
{
  if (SPI_SLAVE_MODULE_INDEX != Module)
  {
    /* report to upper layer */
    SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
         SPI_SID_ISRDMAERROR, SPI_E_PARAM_MODULE );
    /* [cover parentID=DS_MCAL_SPI_9841_23][/cover] */
  }
  else
  {
    Spi_lHwDisableQspiRxIntr(Module, SPI_ISR_ACCESS);
    Spi_lSlaveErrorHandler(Module,(uint32)SPI_DEM_DMA_TRANSFER_ERROR,\
                                                                SPI_ISR_ACCESS);
  }
}

/*******************************************************************************
** Syntax : uint32 Spi_IsrCheckDmaError(uint32 Module)                        **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant for the same QSPI bus                          **
**              Re-entrant for different QSPI bus(AsyncParallelTransmit)      **
**                                                                            **
** Parameters (in) : Module                                                   **
**                                                                            **
** Parameters (out): Error status                                             **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine is used only for ASYNC MASTER and SLAVE enabled **
*******************************************************************************/
uint32 Spi_IsrCheckDmaError(uint32 Module)
{
  uint32 DmaRxErrorstatus;
  uint32 Result;
  Dma_ChannelType DmaReceiveChannel;
  uint32  DmaRxIntrStatus;

  if (SPI_SLAVE_MODULE_INDEX != Module)
  {
    /* report to upper layer */
    SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
         SPI_SID_ISRCHECKDMAERROR, SPI_E_PARAM_MODULE );
    /* [cover parentID=DS_MCAL_SPI_9841_23][/cover] */

    Result = 1U;
  }
  else
  {
    DmaReceiveChannel = Spi_SlaveChnlAccess[0U].DmaChannelIdx.RxDmaChannel;
    /* Get status of Error Flags For QSPIx Rx-DMA Channels */
    DmaRxErrorstatus = Mcal_DmaGetTransReqLostFlag(DmaReceiveChannel);
    DmaRxErrorstatus |= Spi_lDmaGetBothMoveEngErrFlags(SPI_ISR_ACCESS);
    if (DmaRxErrorstatus != 0U )
    {
      Mcal_DmaClrErrFlags(DmaReceiveChannel);
    }

    /* Check ICH bit being Set for DMA RX channel */
    DmaRxIntrStatus = Mcal_DmaGetTransferIntStatus(DmaReceiveChannel);

    if((DmaRxIntrStatus == 1U) && (DmaRxErrorstatus != 0U))
    {
      /* Clear/Reset Channel Interrupt control register */
      Mcal_DmaChClrIntrFlags(DmaReceiveChannel);
      Result = DmaRxErrorstatus;
    }
    else
    {
      /* ICH bit will be cleared in Tx/Rx */
      Result = 0U;
    }
  }
  return Result;
}
#endif
/* ((SPI_LEVEL_DELIVERED == 0U) && (SPI_SLAVE_ENABLE == STD_ON)) */

/*******************************************************************************
** Traceability : [cover parentID=DS_MCAL_SPI_9004]                           **
** Syntax : void Spi_IsrDmaError(uint32 Module)                               **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant for the same QSPI bus                          **
**              Re-entrant for different QSPI bus(AsyncParallelTransmit)      **
**                                                                            **
** Parameters (in) : Module                                                   **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine should be called in the TX/Rx Dma Channel       **
** (Transaction complete / Error) Interrupt of QSPIx Module when              **
**  a Dma Error has occured.                                                  **
** This interrupt occurs in case of DMA Error, when a trigger request is lost.**
** This function calls the                                                    **
** DEM with Error Code  - SPI_DEM_DMA_TRANSFER_ERROR.                         **
** Additionally it sets the Job and Sequence Status to SPI_JOB_FAILED,        **
** SPI_SEQUENCE_FAILED respectively. Also it calls the Job end and sequence   **
** end notification if configured. CS is also Disabled. It also disables the  **
** Qspi Tx interrupt in case if it's enabled.                                 **
**                                                                            **
*******************************************************************************/
#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
void Spi_IsrDmaError(uint32 Module)
{
  #if(SPI_SLAVE_ENABLE == STD_ON)
  if(Module != SPI_SLAVE_MODULE_INDEX)
  #endif
  {
    #if (SPI_SAFETY_ENABLE == STD_ON)
    if (0U == (Spi_lModuleConfiguredAndAsync( (uint8)Module )))
    {
      /* report to upper layer */
      SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
         SPI_SID_ISRDMAERROR, SPI_E_PARAM_MODULE );
      /* [cover parentID=DS_MCAL_SPI_9841_23][/cover] */
    }
    else
    #endif
    {
      /* Call the Error Handler only if the Bus is busy */
      if (SPI_BUSY == Spi_lGetModAsyncBusStatus((uint8)Module))
      {
        Spi_lHwDisableQspiRxIntr(Module, SPI_ISR_ACCESS);
        Spi_lErrorHandler(Module,(uint32)SPI_DEM_DMA_TRANSFER_ERROR, \
                                                                SPI_ISR_ACCESS);
      }
      else
      {
        Spi_lHwDisableQspiTxIntr(Module, SPI_ISR_ACCESS); /* Disable Tx Intr */
        #if (SPI_DMA_ERROR_DEM_REPORT == ENABLE_DEM_REPORT)
        /* Dem for DMA error */
        Dem_ReportErrorStatus(SPI_E_DMA_TRANSFER, \
               DEM_EVENT_STATUS_FAILED);
        #endif
      }
   }
  }
  #if(SPI_SLAVE_ENABLE == STD_ON)
  else
  {
    Spi_lHwDisableQspiRxIntr(Module, SPI_ISR_ACCESS);
    Spi_lSlaveErrorHandler(Module,(uint32)SPI_DEM_DMA_TRANSFER_ERROR,\
                                                                SPI_ISR_ACCESS);
  }
  #endif
}

/*******************************************************************************
** Syntax : uint32 Spi_IsrCheckDmaError(uint32 Module)                        **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant for the same QSPI bus                          **
**              Re-entrant for different QSPI bus(AsyncParallelTransmit)      **
**                                                                            **
** Parameters (in) : Module                                                   **
**                                                                            **
** Parameters (out): Error status                                             **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine should be called in the TX/Rx Dma Channel       **
** (Transaction complete / Error) Interrupt of QSPIx Module .                 **
** This interrupt checks if there is an error in Dma  interrupt               **
** It also clears the error flags and returns the Error status                **
*******************************************************************************/
uint32 Spi_IsrCheckDmaError(uint32 Module)
{
  uint32 DmaTxErrorstatus;
  uint32 DmaRxErrorstatus;
  uint32 Result;
  Dma_ChannelType DmaTransmitChannel;
  Dma_ChannelType DmaReceiveChannel;
  uint32  DmaTxIntrStatus;
  uint32  DmaRxIntrStatus;

  #if((SPI_SAFETY_ENABLE == STD_ON) && (SPI_QM_ASYNC_MASTER_MODULES_USED ==0U))
  DmaReceiveChannel = DMA_CHANNEL_INVALID;
  DmaTransmitChannel = DMA_CHANNEL_INVALID;
  #endif

  #if(SPI_SLAVE_ENABLE == STD_ON)
  if(Module != SPI_SLAVE_MODULE_INDEX)
  #endif
  {
    #if (SPI_SAFETY_ENABLE == STD_ON)
    if (0U == (Spi_lModuleConfiguredAndAsync( (uint8)Module )))
    {
      /* report to upper layer */
       SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
           SPI_SID_ISRCHECKDMAERROR, SPI_E_PARAM_MODULE );
       Result = 1U;
      /* [cover parentID=DS_MCAL_SPI_9841_22][/cover] */
    }/* Spi_lModuleConfiguredAndAsync() */
    else
    #endif
    /* (SPI_SAFETY_ENABLE == STD_ON) */
    {
      #if (SPI_SAFETY_ENABLE == STD_ON)
      if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)Module))
      {
        DmaReceiveChannel = Spi_AsilChnlAccess[0U].DmaChannelIdx.RxDmaChannel;
        DmaTransmitChannel = Spi_AsilChnlAccess[0U].DmaChannelIdx.TxDmaChannel;
      }
      else
      {
        #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
        DmaReceiveChannel = Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)].\
                                          DmaChannelIdx.RxDmaChannel;
        DmaTransmitChannel = Spi_QmChnlAccess \
                              [Spi_lGetQmModuleVarIndex(Module)].\
                                          DmaChannelIdx.TxDmaChannel;
        #endif
        /* Do nothing if QM modules are NOT Used */
      }
      #else
      {
        DmaReceiveChannel = Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)].\
                                          DmaChannelIdx.RxDmaChannel;
        DmaTransmitChannel =
            Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)].DmaChannelIdx. \
                                                               TxDmaChannel;
      }
      #endif

      /* Get status of Error Flags For QSPIx Rx-DMA Channels */
      DmaRxErrorstatus = Mcal_DmaGetTransReqLostFlag(DmaReceiveChannel);
      DmaRxErrorstatus |= Spi_lDmaGetBothMoveEngErrFlags(SPI_ISR_ACCESS);
      if (DmaRxErrorstatus != 0U )
      {
        Mcal_DmaClrErrFlags(DmaReceiveChannel);
      }

      /* Check ICH bit being Set for DMA RX channel */
      DmaRxIntrStatus = Mcal_DmaGetTransferIntStatus(DmaReceiveChannel);

      /* Get status of Error Flags For QSPIx Tx-DMA Channels */
      DmaTxErrorstatus = Mcal_DmaGetTransReqLostFlag(DmaTransmitChannel);
      if (DmaTxErrorstatus != 0U  )
      {
        Mcal_DmaClrErrFlags(DmaTransmitChannel);
      }

      /* Check ICH bit being Set for DMA TX channel */
      DmaTxIntrStatus = Mcal_DmaGetTransferIntStatus(DmaTransmitChannel);

      if(((DmaRxIntrStatus == 1U) && (DmaRxErrorstatus != 0U )) || \
         ((DmaTxIntrStatus == 1U) && (DmaTxErrorstatus != 0U)))
      {
        /* Clear/Reset Channel Interrupt control register */
        Mcal_DmaChClrIntrFlags(DmaReceiveChannel);
        Mcal_DmaChClrIntrFlags(DmaTransmitChannel);
        Result = DmaTxErrorstatus | DmaRxErrorstatus;
      }
      else
      {
        Result = 0U;
      }
    }/* end of else part of Spi_lModuleConfiguredAndAsync */
  } /* (Module != SPI_SLAVE_MODULE_INDEX) */
  #if(SPI_SLAVE_ENABLE == STD_ON)
  else
  {
    DmaReceiveChannel = Spi_SlaveChnlAccess[0U].DmaChannelIdx.RxDmaChannel;
    /* Get status of Error Flags For QSPIx Rx-DMA Channels */
    DmaRxErrorstatus = Mcal_DmaGetTransReqLostFlag(DmaReceiveChannel);
    DmaRxErrorstatus |= Spi_lDmaGetBothMoveEngErrFlags(SPI_ISR_ACCESS);
    if (DmaRxErrorstatus != 0U )
    {
      Mcal_DmaClrErrFlags(DmaReceiveChannel);
    }

    /* Check ICH bit being Set for DMA RX channel */
    DmaRxIntrStatus = Mcal_DmaGetTransferIntStatus(DmaReceiveChannel);

    if((DmaRxIntrStatus == 1U) && (DmaRxErrorstatus != 0U))
    {
      /* Clear/Reset Channel Interrupt control register */
      Mcal_DmaChClrIntrFlags(DmaReceiveChannel);
      Result = DmaRxErrorstatus;
    }
    else
    {
      Result = 0U;
    }
  } /* end of (SPI_SLAVE_ENABLE == STD_ON)  */
  #endif
  return (Result);
}

#endif
 /* (SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U) */

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI020_4]                             **
** Syntax : static void Spi_lEnableChipSelect                                 **
**                                (uint16 CSPin, uint8 CSPolarity,            **
**                                 Spi_HWUnitType  HwUnit,                    **
**                                 uint8  ApiAccessId)                        **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : CSPin : CS Pin Offset                                    **
**                   CSPolarity : CS Active Level Polarity.                   **
**                   ApiAccessId : API access type                            **
**                   HwUnit : Hardware unit Number  and channel               **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : Enables the CS Pin according to the Polarity Requested.      **
**                                                                            **
**                                                                            **
*******************************************************************************/
static void Spi_lEnableChipSelect(uint16 CSPin, uint8 CSPolarity,
                                      Spi_HWUnitType  HwUnit, uint8 ApiAccessId)
{
  #if (SPI_LEVEL_DELIVERED != 0U)
  Spi_ChnlAccessType *ChnlAccDataPtr;
  #endif

  uint32 temp;
  uint8 Channel_select;
  uint32 Module ;

  #if (SPI_LEVEL_DELIVERED != 0U)
  #if((SPI_SAFETY_ENABLE == STD_ON) && (SPI_QM_ASYNC_MASTER_MODULES_USED == 0U))
  ChnlAccDataPtr = NULL_PTR; /* To remove warning: Possibly Uninitialised*/
  #endif
  #endif

  /* CS_VIA_PERIPHERAL_ENGINE - SPI HW IP drives the chip select */
  if (CSPin == SPI_CS_HW)
  {
    Channel_select = ((HwUnit >> SPI_HWUNIT_CH_SHIFT) & SPI_HWUNIT_MASK );

    Module = ((uint8)HwUnit);
    Module = Module & SPI_HWUNIT_MASK;

    temp = SPI_SSOC_OEN_CH_ZERO;

    /* SLSO.OEN CS enable */
    temp  =  temp << Channel_select;
    if (ApiAccessId == SPI_RUNTIME_ACCESS)
    {
      /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
        to efficiently access the SFRs of multiple QSPI Modules.*/
      SPI_SFR_RUNTIME_MODIFY32\
                   (SPI_HW_MODULE[Module].SSOC.U,SPI_SSOC_OEN_CLEARMASK,temp)
    }
    else
    {
     /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
        to efficiently access the SFRs of multiple QSPI Modules.*/
    /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
        to efficiently access the SFRs of multiple QSPI Modules.*/
    SPI_HW_MODULE[Module].SSOC.U =(unsigned_int)((SPI_HW_MODULE[Module].SSOC.U \
                        & SPI_SSOC_OEN_CLEARMASK )| (unsigned_int) temp);
    }
    UNUSED_PARAMETER(CSPolarity)
  }
  else
  {
    /*If SpiEnableCs is false then Spi_lEnableChipSelect will not be called */

    /* Note: Spi_AsilChnlAccess/Spi_QmChnlAccess is not needed for level 0
     MISRA Rule 8.7 is removed by using SPI_LEVEL_DELIVERED != 0U */
    #if  (SPI_LEVEL_DELIVERED != 0U)
     Module = ((uint8)HwUnit);
     Module = Module & SPI_HWUNIT_MASK;

    #if (SPI_SAFETY_ENABLE == STD_ON)
      if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)Module))
      {
        ChnlAccDataPtr = &Spi_AsilChnlAccess[0U];
      }
      else
      {
        #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
        ChnlAccDataPtr = &Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)];
        #endif
        /* Do nothing if QM modules are NOT Used */
      }
    #else
        ChnlAccDataPtr = &Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)];
    #endif

     /* save pin polarity  */
    CSPolarity = (CSPolarity == (uint8)0U) ? (uint8)1U : (uint8)0U;
    ChnlAccDataPtr->GpioPortPin = (uint16)((uint16)CSPolarity << 15U)  ;
    ChnlAccDataPtr->GpioPortPin |= CSPin ;
    #endif
    UNUSED_PARAMETER(ApiAccessId)
  }

}

/*******************************************************************************
** Syntax : static void Spi_lDisableChipSelect(uint16 CSPin,                  **
**           uint8 CSPolarity, Spi_HWUnitType  HwUnit, uint8 ApiAccessId)     **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : CSPin : CS Pin Offset                                    **
**                   CSPolarity : CS Active Level Polarity.                   **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : Disables the CS Pin opposite to the Polarity Requested.      **
**                                                                            **
**                                                                            **
*******************************************************************************/
static void Spi_lDisableChipSelect(uint16 CSPin, uint8 CSPolarity,
                                      Spi_HWUnitType  HwUnit, uint8 ApiAccessId)
{
  uint32 Module;

  if (CSPin == SPI_CS_HW)
  {
    Module = ((uint8)HwUnit);
    Module = Module & SPI_HWUNIT_MASK;

#if (SPI_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
    if (ApiAccessId == SPI_RUNTIME_ACCESS)
    {
      /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
       to efficiently access the SFRs of multiple QSPI Modules.*/
      SPI_SFR_RUNTIME_MODIFY32(SPI_HW_MODULE[Module].SSOC.U, \
                                     SPI_SSOC_OEN_CLEARMASK,(uint32)0U)
    }
    else
#endif /*(SPI_USER_MODE_RUNTIME_API_ENABLE == STD_ON)*/
    {
      /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
       to efficiently access the SFRs of multiple QSPI Modules.*/
      /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
       to efficiently access the SFRs of multiple QSPI Modules.*/
      SPI_HW_MODULE[Module].SSOC.U = \
       (unsigned_int)  (SPI_HW_MODULE[Module].SSOC.U & SPI_SSOC_OEN_CLEARMASK);

    }
  }
  else
  {
    /* if (CSPin != SPI_CS_NONE) */

    Spi_lHwGpioSetPortPin(CSPin, CSPolarity, ApiAccessId);
  }
#if (SPI_USER_MODE_RUNTIME_API_ENABLE == STD_OFF)
UNUSED_PARAMETER(ApiAccessId)
#endif
}

/*******************************************************************************
** Syntax : IFX_LOCAL_INLINE void Spi_lDisableChipSelect_SV(uint16 CSPin,     **
**               uint8 CSPolarity, Spi_HWUnitType  HwUnit, uint8 ApiAccessId) **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : CSPin : CS Pin Offset                                    **
**                   CSPolarity : CS Active Level Polarity.                   **
**                   ApiAccessId : Api access type                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : Disables the CS Pin opposite to the Polarity Requested.      **
**                                                                            **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lDisableChipSelect_SV(uint16 CSPin, uint8 CSPolarity,
                                    Spi_HWUnitType  HwUnit, uint8 ApiAccessId)
{
  uint32 Channel_select;
  uint32 Module;
  uint32 Temp;

  if (CSPin == SPI_CS_HW)
  {
    Module = ((uint8)HwUnit);
    Module = Module & SPI_HWUNIT_MASK;

    Channel_select = (uint8)HwUnit ;
    Channel_select = Channel_select >> SPI_HWUNIT_CH_SHIFT ;
    Channel_select &= SPI_HWUNIT_MASK;

    Temp = (uint32)16U + (uint32)Channel_select;
    /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
     to efficiently access the SFRs of multiple QSPI Modules.*/
    SPI_SFR_DEINIT_MCAL_SETATOMIC\
                (((sint32 *)(void*)&(SPI_HW_MODULE[Module].SSOC.U)),(uint32)0U,\
                                                                (sint32)Temp,1);
  }
  else
  {
    /* if (CSPin != SPI_CS_NONE) */
    Module = ((uint8)HwUnit);
    Module = Module & SPI_HWUNIT_MASK;

    Channel_select = (uint8)HwUnit ;
    Channel_select = Channel_select >> SPI_HWUNIT_CH_SHIFT ;
    Channel_select &= SPI_HWUNIT_MASK;

    Temp = (uint32)16U + (uint32)Channel_select;
    /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
     to efficiently access the SFRs of multiple QSPI Modules.*/
    SPI_SFR_DEINIT_MCAL_SETATOMIC\
                (((sint32 *)(void*)&(SPI_HW_MODULE[Module].SSOC.U)),(uint32)0U,\
                                                                (sint32)Temp,1);
    Spi_lHwGpioSetPortPin(CSPin,CSPolarity, ApiAccessId);
  }
}

#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
#if (SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)
/*******************************************************************************
** Syntax : void Spi_lIntSeqAsyncTransmit( Spi_SequenceType Sequence,         **
**                               Spi_JobAndSeqAccessType *JobSeqDataPtr )     **
**                                                                            **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Sequence : Sequence number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This function will populate the Queue depending upon the     **
**               priority of jobs. updating the jobs also depends on the      **
**               previously loaded sequences are interruptible or not.        **
**                                                                            **
*******************************************************************************/
void Spi_lIntSeqAsyncTransmit( Spi_SequenceType Sequence,
                               Spi_JobAndSeqAccessType *JobSeqDataPtr )
{
  const Spi_SequenceConfigType* ParamSeqConfigPtr;
  uint32 SubstituteCount;
  uint32 Count;
  uint32 JobCounter;
  uint16 StoreIndex;
  uint16 CurrentIndex;
  uint16 JobIdInJobQueue;
  uint16 Index;
  uint16 JobId;
  uint8 PriorityOfJobInJobQ;
  uint8 PriorityOfJobInCurrentSeq;

  /*IFX_MISRA_RULE_17_04_STATUS="SpiSequenceConfigPtr" Pointer arithmetic used
    due to PBConfigStructure and is within allowed range.*/
  ParamSeqConfigPtr = &(Spi_kConfigPtr->SpiSequenceConfigPtr[Sequence]);
  Index = JobSeqDataPtr->StartIndexExtractJobId;
  /* Move till the first interruptible sequece */
  Index = Spi_lGotoFirstIntSeq(Index,JobSeqDataPtr);
  if (Index == JobSeqDataPtr->EndIndex)
  {
    /* have already reached the end of Q;
      just fill in the new jobs of sequence to Q
      Move the end index appropriately*/
    Spi_lCheckPushSeqJobsToQ(JobSeqDataPtr,(uint32)0,Sequence);
  }
  else
  {
    /* SeqIdin Q is already known */
    JobCounter = 0U;
    StoreIndex = Index;
    if (ParamSeqConfigPtr->InterruptibleSequence == SPI_SEQ_INT_TRUE)
    {
      /*(do while A)*/
      do
      {
        StoreIndex = Index;
        /* extract job id from the current sequence */
        /*IFX_MISRA_RULE_17_04_STATUS="JobLinkPtr" Pointer arithmetic used due
          to PBConfigStructure and is within allowed range.*/
        JobId = ParamSeqConfigPtr->JobLinkPtr[JobCounter];
        /*
        Job in the current seq has higher priority load the job into the
        local job queue, other wise load the job from the Queue into the
        local job Queue
        */
        JobIdInJobQueue = JobSeqDataPtr->JobQueue[Index];
        /*IFX_MISRA_RULE_17_04_STATUS="SpiJobConfigPtr" Pointer arithmetic used
          due to PBConfigStructure and is within allowed range.*/
        PriorityOfJobInJobQ = \
                Spi_kConfigPtr->SpiJobConfigPtr[JobIdInJobQueue].JobPriority;
        /*IFX_MISRA_RULE_17_04_STATUS="SpiJobConfigPtr" Pointer arithmetic used
          due to PBConfigStructure and is within allowed range.*/
        PriorityOfJobInCurrentSeq = \
                          Spi_kConfigPtr->SpiJobConfigPtr[JobId].JobPriority;
        if (PriorityOfJobInCurrentSeq > PriorityOfJobInJobQ)
        {
          CurrentIndex = Index;
          /* MISRA violation 1.2: Taking address of near auto variable  */
          SubstituteCount = Spi_lStoreToArrayAndReturnCount(CurrentIndex,
                                &JobSeqDataPtr->JobQueueRearrange[0U],
                                &JobSeqDataPtr->JobLinkedSequenceRearrange[0U],
                                JobSeqDataPtr);

          /* Place the Job in Queue exactly at the position
             where priority is lower.
             This is denoted by Store index */
          JobSeqDataPtr->JobQueue[StoreIndex] = JobId;
          JobSeqDataPtr->JobLinkedSeq[StoreIndex] = Sequence;
          /* Increment Store index */
          StoreIndex = Spi_lIncrementAndRoundIndex(StoreIndex);
          /* From Store index, fill the Queue with remaining jobs
          that was previously stored in a local array */
          CurrentIndex = StoreIndex;
          for (Count = 0U; Count <  SubstituteCount; Count++)
          {
            JobSeqDataPtr->JobQueue[CurrentIndex] =
                                       JobSeqDataPtr->JobQueueRearrange[Count];
            JobSeqDataPtr->JobLinkedSeq[CurrentIndex] =
                              JobSeqDataPtr->JobLinkedSequenceRearrange[Count];
            CurrentIndex = Spi_lIncrementAndRoundIndex(CurrentIndex);
          }
          /* Move end index by 1 as one extra job is placed
             and also IncrementAndRound the same*/
          JobSeqDataPtr->EndIndex = Spi_lIncrementAndRoundIndex
                                        (JobSeqDataPtr->EndIndex);
          JobCounter++;
        }
        else
        {
          /* Increment and Circle Back to zero */
          Index = Spi_lIncrementAndRoundIndex(Index);
        }/*(PriorityOfJobInCurrentSeq > PriorityOfJobInJobQ*/
      /*IFX_MISRA_RULE_17_04_STATUS="JobLinkPtr" Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      }while ((Index != JobSeqDataPtr->EndIndex) && \
                             ((ParamSeqConfigPtr->JobLinkPtr[JobCounter]) != \
                                    SPI_JOB_LINK_DELIMITER));  /*do while A */
            /*Push the sequence jobs to Q at the end */
      Spi_lCheckPushSeqJobsToQ(JobSeqDataPtr,JobCounter,Sequence);
    }
    else
    {
      CurrentIndex = Index;
      /*MISRA violation 1.2: Taking address of near auto variable  */
      SubstituteCount = Spi_lStoreToArrayAndReturnCount(CurrentIndex,
                                &JobSeqDataPtr->JobQueueRearrange[0U],
                                &JobSeqDataPtr->JobLinkedSequenceRearrange[0U],
                                JobSeqDataPtr);

      do
      {
        /*IFX_MISRA_RULE_17_04_STATUS="JobLinkPtr" Pointer arithmetic used due
          to PBConfigStructure and is within allowed range.*/
        JobSeqDataPtr->JobQueue[StoreIndex] = ParamSeqConfigPtr->\
                                          JobLinkPtr[JobCounter];
        JobSeqDataPtr->JobLinkedSeq[StoreIndex] = Sequence;
        StoreIndex = Spi_lIncrementAndRoundIndex(StoreIndex);
        JobCounter++;
        /* New entry to the Queue ; increment Spi_EndIndex as well */
        /* Move end index by 1 as one extra job is placed
             and also IncrementAndRound the same*/
        JobSeqDataPtr->EndIndex = Spi_lIncrementAndRoundIndex(
                                                   JobSeqDataPtr->EndIndex);
      /*IFX_MISRA_RULE_17_04_STATUS="JobLinkPtr" Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      }while (ParamSeqConfigPtr->JobLinkPtr[JobCounter] != \
                                          SPI_JOB_LINK_DELIMITER);
      CurrentIndex = StoreIndex;
      for (Count = 0U; Count < SubstituteCount; Count++)
      {
        JobSeqDataPtr->JobQueue[CurrentIndex] =
                                       JobSeqDataPtr->JobQueueRearrange[Count];
        JobSeqDataPtr->JobLinkedSeq[CurrentIndex] =
                              JobSeqDataPtr->JobLinkedSequenceRearrange[Count];
        CurrentIndex = Spi_lIncrementAndRoundIndex(CurrentIndex);
      }
    }/*(ParamSeqConfigPtr->InterruptibleSequence == SPI_SEQ_INT_TRUE)*/
  }/*(Index == JobSeqDataPtr->EndIndex)*/
}

/*******************************************************************************
** Syntax : IFX_LOCAL_INLINE uint16  Spi_lGotoFirstIntSeq(uint16 SeqIndex,    **
                                  Spi_JobAndSeqAccessType *JobSeqDataPtr)     **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : SeqIndex : index value pointing the seq id in the Seq    **
**                   Queue                                                    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : seq id                                                   **
**                                                                            **
** Description : This function will goto the first interruptible seq          **
**               in the seq queue.                                            **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE uint16  Spi_lGotoFirstIntSeq
(
  uint16 SeqIndex,
  const Spi_JobAndSeqAccessType *JobSeqDataPtr
)
{
  const Spi_SequenceConfigType* SeqInterruptiblePtr;
  uint8 Seqbool;
  uint8  SeqIdInQ;

  /* Move till the first interruptible sequece */
  Seqbool = SPI_SEQ_INT_FALSE;
  while ( (SeqIndex != JobSeqDataPtr->EndIndex) &&
          (Seqbool != SPI_SEQ_INT_TRUE) )
  {
    SeqIdInQ = JobSeqDataPtr->JobLinkedSeq[SeqIndex];
    /*IFX_MISRA_RULE_17_04_STATUS="SpiSequenceConfigPtr" Pointer arithmetic used
      due to PBConfigStructure and is within allowed range.*/
    SeqInterruptiblePtr = &(Spi_kConfigPtr->SpiSequenceConfigPtr[SeqIdInQ]);
    Seqbool = SeqInterruptiblePtr->InterruptibleSequence;
    if (Seqbool == SPI_SEQ_INT_FALSE)
    {
      SeqIndex = Spi_lIncrementAndRoundIndex(SeqIndex);
    }
    else
    {
      Seqbool = SPI_SEQ_INT_TRUE;
    }
  }
  return SeqIndex;
}
#endif
 /*(SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)*/
#endif
 /*((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))*/

/*******************************************************************************
** Syntax : IFX_LOCAL_INLINE Std_ReturnType Spi_lSyncTransmitDetCheck(        **
**                                             Spi_SequenceType Sequence)     **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Sequence : Sequence ID                                   **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Std_ReturnType                                           **
**                                                                            **
** Description : This function will check for DET errors and report them in   **
**                Spi_SyncTransmit function                                   **
*******************************************************************************/
#if ((SPI_LEVEL_DELIVERED == 0U) || (SPI_LEVEL_DELIVERED == 2U))
#if ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) )
#if (SPI_LEVEL2_ASYNC_ONLY == STD_OFF)
IFX_LOCAL_INLINE Std_ReturnType Spi_lSyncTransmitDetCheck
(
Spi_SequenceType Sequence
)
{
  Std_ReturnType RetVal = E_OK;

  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  /* API  called before initialization */
  RetVal = Spi_lGetDetInitStatus(SPI_SID_SYNCTRANSMIT);
  #endif

    /*
    Sequence shall be within the specified range of
    values (0 to SPI_MAX_SEQUENCE )
    */
#if (SPI_LEVEL_DELIVERED == 2U)
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
    if ((RetVal == E_OK) &&
        (Sequence >= Spi_kConfigPtr->NoOfSyncSequences))
  #else
    if (Sequence >= Spi_kConfigPtr->NoOfSyncSequences)
  #endif
#else
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
    if ((RetVal == E_OK) &&
        (Sequence >= Spi_kConfigPtr->NoOfSequences))
  #else
    if (Sequence >= Spi_kConfigPtr->NoOfSequences)
  #endif
#endif
    {
      /* Report to DET */
      #if (SPI_DEV_ERROR_DETECT == STD_ON)
      Det_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_SYNCTRANSMIT, SPI_E_PARAM_SEQ );
      #endif

      #if (SPI_SAFETY_ENABLE == STD_ON)
      SafeMcal_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_SYNCTRANSMIT, SPI_E_PARAM_SEQ );
     /* [cover parentID=DS_MCAL_SPI_9841_13][/cover] */
      #endif
      /* In case of DET or Safety error, Service is Rejected */
      RetVal = E_NOT_OK;
    }
    else
    {
      /*Do Nothing */
    }
  return RetVal;
}
#endif /* SPI_LEVEL2_ASYNC_ONLY == STD_OFF */
#endif
/*( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_SAFETY_ENABLE == STD_ON) ) */
#endif
/* ((SPI_LEVEL_DELIVERED == 0U) || (SPI_LEVEL_DELIVERED == 2U)) */

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI020_2, DS_AS_SPI263_1]             **
** Syntax : static void Spi_lStartJob                                         **
** (                                                                          **
**   uint32 Module,                                                           **
**   Spi_JobType Job,                                                         **
**   uint8 ApiAccessId                                                        **
** )                                                                          **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant  (for different JobIds)                            **
**                                                                            **
** Parameters (in) : Module - ModuleId                                        **
**                   Job    - JobId                                           **
                     ApiAccessId - API access type                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
**                                                                            **
** Description : Sets up the SPI HW According to Job Parameters.              **
**               Enables CS                                                   **
**               Enables CLK to CS Timing.                                    **
**               Call to Start Channel                                        **
*******************************************************************************/
#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
static void Spi_lStartJob(uint32 Module, Spi_JobType JobId, uint8 ApiAccessId)
{
  Spi_ChnlAccessType       *ChnlAccDataPtr;
  const Spi_JobConfigType* JobConfigPtr;
  Spi_ChannelType Channel;
  Ifx_QSPI* ModulePtr;
  uint32 DelayAndHwChNo;
  uint8 IsGpioCsFirstChannel;

  #if((SPI_SAFETY_ENABLE == STD_ON) && (SPI_QM_ASYNC_MASTER_MODULES_USED == 0U))
  ChnlAccDataPtr = NULL_PTR; /* To remove warning: Possibly Uninitialised*/
  #endif

  #if (SPI_SAFETY_ENABLE == STD_ON)
    if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)Module))
    {
      ChnlAccDataPtr = &Spi_AsilChnlAccess[0U];
    }
    else
    {
      #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
      ChnlAccDataPtr = &Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)];
      #endif
      /* Do nothing if QM modules are NOT Used */
    }
  #else
    {
      ChnlAccDataPtr = &Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)];
    }
  #endif

 /*IFX_MISRA_RULE_17_04_STATUS="SpiJobConfigPtr" Pointer arithmetic used due to
    PBConfigStructure and is within allowed range.*/
  JobConfigPtr = &(Spi_kConfigPtr->SpiJobConfigPtr[JobId]);
  ChnlAccDataPtr->CurrentChannelIndex = 0U;
  /*IFX_MISRA_RULE_17_04_STATUS="ChannelLinkPtr" Pointer arithmetic used due to
    PBConfigStructure and is within allowed range.*/
  Channel = JobConfigPtr->ChannelLinkPtr[0U];
  /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used to
    efficiently access the SFRs of multiple QSPI Modules.*/
  ModulePtr =  &(SPI_HW_MODULE[Module]);

  /* set the first job result to SPI_JOB_PENDING */
  Spi_lSetJobStatusAtomic(JobId,SPI_JOB_PENDING);

  /* Configure the Job parameters like Mod En, baudrate (TQ, Q, A, B, C),
     Event enable (Error enable, TxEn, Rxen,
     EXPECT  = max_value, clock Phase & polarity
     Delay Parameters (Lead,Trail,Idle)
  */
  Spi_lHwSetJobConfig(ModulePtr, JobConfigPtr);

  Spi_lHwEnableQspiRxIntr(Module,ApiAccessId);

  #if (SPI_LEVEL_DELIVERED == 2U)
  if (Spi_AsyncMode != (uint8) SPI_POLLING_MODE)
  #endif
 /*(SPI_LEVEL_DELIVERED == 2U)*/
  {
    Spi_lHwEnableQspiErrIntr(Module, ApiAccessId);
  }
  /* The Chip Select (CS) is attached to the Job definition. Chip Select
  shall be handled during Job transmission and shall be released at the end of
  it.This Chip Select handling shall be done according to the Job configuration
  parameters. */
  IsGpioCsFirstChannel = 0U;
  if (JobConfigPtr->CSPin != SPI_CS_NONE)
  {
    /* Enable Chip Select beginning of Job Transmission*/
    Spi_lEnableChipSelect(JobConfigPtr->CSPin,JobConfigPtr->CSPolarity,
                          JobConfigPtr->HwUnit, ApiAccessId);
    if (JobConfigPtr->CSPin != SPI_CS_HW)
    {
      IsGpioCsFirstChannel = 1U;
    }
  }
  else
  {
    /*Do Nothing*/
  }/*(JobConfigPtr->CSPin != SPI_CS_NONE)*/

  DelayAndHwChNo = JobConfigPtr->TimeDelayConfig |
              (( ((uint32)JobConfigPtr->HwUnit >> SPI_HWUNIT_CH_SHIFT)
              &  SPI_HWUNIT_MASK) <<   SPI_CONFIG_HWCHANNELNO_SHIFT);

  /*IFX_MISRA_RULE_17_04_STATUS="ChannelLinkPtr" Pointer arithmetic used due to
    PBConfigStructure and is within allowed range.*/
  if (JobConfigPtr->ChannelLinkPtr[1U] == SPI_CHANNEL_LINK_DELIMITER)
  {
    /* Last Channel */
    Spi_lStartChannel(Module, Channel, 1U, DelayAndHwChNo,
                                IsGpioCsFirstChannel, JobConfigPtr,ApiAccessId);
  }
  else
  {
    /* Not last channel */
    Spi_lStartChannel(Module, Channel, 0U, DelayAndHwChNo,
                                IsGpioCsFirstChannel, JobConfigPtr,ApiAccessId);
  }

}
#endif
 /* (SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U) */

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI035_SPI036, DS_AS_SPI020_3,        **
DS_AS_SPI028_1_SPI030_1]                                                      **
** Syntax : static void Spi_lStartChannel                                     **
** (                                                                          **
**   uint32 Module, Spi_ChannelType Channel,                                  **
**   uint8 IsLastChannel, uint32 DelayAndHwChNo, uint8 IsGpioCsFirstChannel,  **
**   const Spi_JobConfigType* JobConfigPtr )                                  **
** )                                                                          **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant (for different channel Ids)                        **
**                                                                            **
** Parameters (in) :   Module - ModuleId                                      **
**                     Channel    - ChannelId                                 **
**                     IsLastChannel    - IsLastChannel of job                **
**                     DelayAndHwChNo    - packed variable delay and ch no    **
**                     IsGpioCsFirstChannel    - is first channel             **
**                     JobConfigPtr    - Job pointer                          **
**                     ApiAccessId   - API access type                        **
**                                                                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :                                                          **
**                                                                            **
**                                                                            **
** Description :  Configures the DMA Channels for SPI Communication.          **
**                Trigger DMA Transaction.                                    **
**                                                                            **
*******************************************************************************/
#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
static void Spi_lStartChannel(uint32 Module, Spi_ChannelType Channel,
        uint8 IsLastChannel, uint32 DelayAndHwChNo, uint8 IsGpioCsFirstChannel,
        const Spi_JobConfigType* JobConfigPtr,uint8 ApiAccessId )
{
  Spi_ChnlAccessType *ChnlAccDataPtr;
  const Spi_ChannelConfigType* ChannelConfigPtr;
  const Spi_DataType* DmaSrcPtr;
  Spi_DataType *DmaDestPtr;
  uint32 DmaTransferCount;
  uint32 PackedVar;
  #if (SPI_CHANNEL_BUFFERS_ALLOWED != 0U)
  Spi_EBBufferType* EBBufferPtr;
  #endif
  /* (SPI_CHANNEL_BUFFERS_ALLOWED != 0) */

  #if((SPI_SAFETY_ENABLE == STD_ON) && (SPI_QM_ASYNC_MASTER_MODULES_USED == 0U))
  ChnlAccDataPtr = NULL_PTR; /* To remove warning: Possibly Uninitialised*/
  #endif

  #if (SPI_SAFETY_ENABLE == STD_ON)
  if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)Module))
  {
    ChnlAccDataPtr = &Spi_AsilChnlAccess[0U];
  }
  else
  {
    /*comment */
    #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
    ChnlAccDataPtr = &Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)];
    #endif
    /* Do nothing if QM modules are NOT Used */
  }
  #else
  {
    ChnlAccDataPtr = &Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)];
  }
  #endif

  /*IFX_MISRA_RULE_17_04_STATUS="SpiChannelConfigPtr" Pointer arithmetic used
    due to PBConfigStructure and is within allowed range.*/
  ChannelConfigPtr = &(Spi_kConfigPtr->SpiChannelConfigPtr[Channel]);

  #if (SPI_CHANNEL_BUFFERS_ALLOWED == 2U)
  if (ChannelConfigPtr->ChannelBufferType == SPI_EB_BUFFER)
  #endif
 /* (SPI_CHANNEL_BUFFERS_ALLOWED == 2U) */

  #if (SPI_CHANNEL_BUFFERS_ALLOWED != 0U)
  {
    /* Get Eb Channel Position */
    Channel = Channel - (Spi_ChannelType)Spi_NoOfIBChannels;
    EBBufferPtr = &(Spi_EBBuffer[Channel]);
    DmaSrcPtr  = EBBufferPtr->SrcPtr;
    DmaDestPtr = EBBufferPtr->DestPtr;
    DmaTransferCount  = (uint32)EBBufferPtr->Length;

    if (DmaDestPtr == NULL_PTR)
    {
      /* Dest Ptr is NULL. Read data is ignored */
      /*IFX_MISRA_RULE_11_01_STATUS=Typecasting SPI_DMA_DUMMY_RX_ADDRESS to
        Spi_DataType* is unvoidable.
        DmaDestPtr is later used for SFR assignment.*/
      /*IFX_MISRA_RULE_11_03_STATUS=Type cast to Spi_DataType* is unavoidable*/
      DmaDestPtr =  (Spi_DataType*)SPI_DMA_DUMMY_RX_ADDRESS;
    }

    if (DmaSrcPtr == NULL_PTR)
    {
      /* Src Ptr is NULL. Configured Default Data is
         transmitted */
      Spi_lSetDmaDummyTxValue(Module, ChannelConfigPtr->DefaultData);
      DmaSrcPtr = Spi_lGetDmaDummyTxAddress(Module);
    }
  }
  #endif
  /*(SPI_CHANNEL_BUFFERS_ALLOWED != 0)*/

  #if (SPI_CHANNEL_BUFFERS_ALLOWED == 2U)
  else  /* IB Buffer */
  #endif
 /* (SPI_CHANNEL_BUFFERS_ALLOWED == 2U) */
  #if (SPI_CHANNEL_BUFFERS_ALLOWED != 1U)
  {
    /* The channel data received shall be stored in 1 entry deep
       internal buffers by channel.
       The channel data to be transmitted shall be copied in 1 entry
       deep internal buffers by channel. The SPI Handler/Driver is not able to
       prevent the overwriting of these "transmit" buffers by users during
       transmissions */
    /*IFX_MISRA_RULE_11_01_STATUS=Typecasting Spi_IBBufferAccess to uint32
      is unvoidable. DmaSrcPtr is later used for SFR assignment.*/
    /*IFX_MISRA_RULE_11_01_STATUS=Typecasting Spi_IBBufferAccess to
      Spi_DataType* is unvoidable. DmaSrcPtr is later used for SFR assignment.*/
    /*IFX_MISRA_RULE_11_03_STATUS=Type cast to Spi_DataType* is unavoidable*/
    /*IFX_MISRA_RULE_11_03_STATUS=Type cast to uint32 is unavoidable*/
    DmaSrcPtr = (const Spi_DataType*)((uint32)(&(Spi_IBBufferAccess. \
                 IBBuffer[Spi_IBBufferAccess.IBBufferOffset[Channel]])));
    DmaDestPtr = &Spi_IBBufferAccess.IBBuffer[Spi_IBBufferAccess.\
                 IBBufferOffset[Channel] + SPI_MAXIMUM_IB_BUFFER_SIZE];
    DmaTransferCount = (uint32)ChannelConfigPtr->NoOfBuffers;
  }
  #endif
  /*(SPI_CHANNEL_BUFFERS_ALLOWED != 1U) */

  if (IsLastChannel)
  {
    /* Enter Critical Section */
    SchM_Enter_Spi_AsyncTransmit();

    ChnlAccDataPtr->LastChannelData.DataWidth = ChannelConfigPtr->DataConfig &
                                                   SPI_CONFIG_DATALENGTH_MASK;

    /* This should be b'fore the Dmatransfer count re-adjustment wrt datawidth
        since DmaSrcPtr is of type uint8*
       Adjustment is -1 or -2 or -4 based on DataWidth  */

   /* Note 960: Violates MISRA Required Rule 11.5
     attempt to cast away const/volatile from a pointer or reference
    */
#if (SPI_CHANNEL_BUFFERS_ALLOWED != 0U)
    if  (DmaSrcPtr == Spi_lGetDmaDummyTxAddress(Module))
    {
      /*IFX_MISRA_RULE_11_05_STATUS="DmaSrcPtr" attempt to cast away
        volatile in terms of pointer access.*/
      ChnlAccDataPtr->LastChannelData.LastDataPtr =
             (uint32 *)(void *)((Spi_DataType *)(void *)DmaSrcPtr) ;
    }
    else
#endif
    {
      if (ChannelConfigPtr->DataConfig & SPI_32BIT_DATAMASK)
      {
        /*IFX_MISRA_RULE_11_05_STATUS="DmaSrcPtr" attempt to cast away
          volatile in terms of pointer access.*/
        /*IFX_MISRA_RULE_17_04_STATUS="LastDataPtr" Pointer arithmetic used due
          to BufferStructure and is within allowed range.*/
        ChnlAccDataPtr->LastChannelData.LastDataPtr =
                 (uint32 *)(void *)((Spi_DataType *)(void *)DmaSrcPtr +
                                (DmaTransferCount - SPI_32BIT_DATA_ACCESS)) ;
      }
      else if (ChannelConfigPtr->DataConfig & SPI_16BIT_DATAMASK)
      {
        /*IFX_MISRA_RULE_11_05_STATUS="DmaSrcPtr" attempt to cast away
          volatile in terms of pointer access.*/
        /*IFX_MISRA_RULE_17_04_STATUS="LastDataPtr" Pointer arithmetic used due
          to BufferStructure and is within allowed range.*/
        ChnlAccDataPtr->LastChannelData.LastDataPtr =
           (uint32 *)(void *)((Spi_DataType *)(void *)DmaSrcPtr +
                                (DmaTransferCount - SPI_16BIT_DATA_ACCESS)) ;
      }
      else
      {
        /*IFX_MISRA_RULE_11_05_STATUS="DmaSrcPtr" attempt to cast away
          volatile in terms of pointer access.*/
        /*IFX_MISRA_RULE_17_04_STATUS="LastDataPtr" Pointer arithmetic used due
          to BufferStructure and is within allowed range.*/
        ChnlAccDataPtr->LastChannelData.LastDataPtr =
         (uint32 *)(void *)((Spi_DataType *)(void *)DmaSrcPtr +
                                (DmaTransferCount - SPI_8BIT_DATA_ACCESS) );
      }
    }

    /* Exit Critical Section */
    SchM_Exit_Spi_AsyncTransmit();
  }

  /*Data Width > 16 bits*/
  if (ChannelConfigPtr->DataConfig & SPI_32BIT_DATAMASK)
  {
    /* DmaTransferCount is div by 4 to convert transfers as 32 bit from 8 bit */
    DmaTransferCount = (DmaTransferCount >> SPI_TRANSFERCOUNT_SHIFT_32BIT) ;
  }
  /*Data Width > 8 bits*/
  else if (ChannelConfigPtr->DataConfig & SPI_16BIT_DATAMASK)
  {
    /* DmaTransferCount is div by 2 to convert transfers as 16 bit from 8 bit */
    DmaTransferCount = (DmaTransferCount >> SPI_TRANSFERCOUNT_SHIFT_16BIT) ;
  }
  else
  {
    /*Do Nothing*/
  }

  Spi_lHwSetChannelConfig(Module, ChannelConfigPtr, DmaTransferCount,
                                  IsLastChannel, DelayAndHwChNo, JobConfigPtr);

  /* Module is uint32 but QSPI modules are not more than 6 hence only the
      LSB8bits contains the module number*/
  /* Pack Module, IsLastChannel, ChannelConfigPtr->DataConfig to one variable */
  PackedVar = (uint32)(Module << SPI_MODULE_SHIFTBITS);
  PackedVar = (uint32)(PackedVar |
                              ((uint32)IsLastChannel << SPI_LASTCH_SHIFTBITS));
  PackedVar = (uint32)(PackedVar |
                                  (uint32)ChannelConfigPtr->DataConfig);

  /* Fix for UTP: AI00243434
   GPIO Chipselect followed by DMA transfer does not cause data loss; However
   it induces more delay than the configured lead delays. This limitation
   is mentioned in the User manual.

  If DMA is started first followed by GPIO Chipselect the delay could be much
  closer to the configured values however it could cause data loss.(AI00132984)
  */

  /* If Cs is via gpio, Enable CS*/
  if (IsGpioCsFirstChannel == 1U)
  {
    Spi_lHwGpioSetPortPin((ChnlAccDataPtr->GpioPortPin & 0x7FFFU),
                      (uint8)((ChnlAccDataPtr->GpioPortPin >> 15U) & 0x0001U), \
                                                                   ApiAccessId);
  }

  if(ApiAccessId == SPI_RUNTIME_ACCESS)
  {
    /* Start Dma Transfer */
    Spi_lHwDmaStartTransferRuntime( DmaSrcPtr, DmaDestPtr,
                          DmaTransferCount, PackedVar, JobConfigPtr);
  }
  else
  {
    /* Start Dma Transfer */
    Spi_lHwDmaStartTransferIsr( DmaSrcPtr, DmaDestPtr,
                          DmaTransferCount, PackedVar, JobConfigPtr);
  }
}
#endif
 /* (SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U) */

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI059_SPI293,DS_AS_SPI267_1
DS_AS_SPI006_1,DS_AS_SPI007_1 ]                                               **
** Syntax           : static void Spi_lErrorHandler                           **
**                    (                                                       **
**                      uint32 Module                                         **
**                      uint32 DemError                                       **
**                      uint8  ApiAccessId                                    **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : Module- SPI Bus Id.                                     **
**                    DemError -DemError Id to be reported                    **
**                    ApiAccessId   - API access type                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : On hardware error detection the current Sequence        **
** is stopped and an error is reported to the error hook of the DET or to the **
** DEM as configured. The state of Job will be SPI_JOB_FAILED and the state   **
** of Sequence will be SPI_SEQ_FAILED.                                        **
** Calls the Job/Sequence End Notification if configured                      **
** The detection of production code errors cannot be switched off.            **
*******************************************************************************/
#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
static void Spi_lErrorHandler(uint32 Module, uint32 DemError, uint8 ApiAccessId)
{
  Spi_JobAndSeqAccessType *JobSeqDataPtr;
  const Spi_JobConfigType*    JobConfigPtr;
  Spi_JobType JobId;
  uint16 CompletedJobSeqIndex;
  #if (SPI_SEQ_END_NOTIF_REQ == STD_ON)
  const Spi_SequenceConfigType* SeqConfigPtr;
  #endif
  uint16 CsPinLocal;
  Spi_SequenceType SeqId;
  Ifx_QSPI* ModulePtr;
  uint16 ExtractJobId;
  uint16 EndIndex;
  uint32 HWUnit;
  uint8 Seqbool;
  uint8 NextSeqId;
  uint16 StartIndex;

  #if((SPI_SAFETY_ENABLE == STD_ON) && (SPI_QM_ASYNC_MASTER_MODULES_USED == 0U))
  JobSeqDataPtr  = NULL_PTR; /* To remove warning: Possibly Uninitialised*/
  #endif

  #if (SPI_SAFETY_ENABLE == STD_ON)
    /* if module is ASIL */
    if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)Module))
    {
      JobSeqDataPtr = &Spi_AsilJobAndSeqAccess;
    }
    else
    {
      #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
      #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
      JobSeqDataPtr = &Spi_QmJobAndSeqAccess;
      #else
      JobSeqDataPtr = &Spi_QmJobAndSeqAccess[Spi_lGetQmModuleVarIndex(Module)];
      #endif
      #endif
      /* Do nothing if QM modules are NOT Used */
    }
  #else
    {
      #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
      JobSeqDataPtr = &Spi_QmJobAndSeqAccess;
      #else
      JobSeqDataPtr =&Spi_QmJobAndSeqAccess[Spi_lGetQmModuleVarIndex(Module)];
      #endif
    }
  #endif

  /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used to
    efficiently access the SFRs of multiple QSPI Modules.*/
  ModulePtr =  &(SPI_HW_MODULE[Module]);

  /* Production relevant errors shall be reported to the Diagnostic
     Event Manager (DEM). They shall not be used as the return value of the
     called function.*/
  if (DemError == (uint32)SPI_DEM_HW_ERROR)
  {
    #if (SPI_HW_ERROR_DEM_REPORT == ENABLE_DEM_REPORT)
    /* Dem for receive error*/
      Dem_ReportErrorStatus(SPI_E_HARDWARE_ERROR,
               DEM_EVENT_STATUS_FAILED);
    #endif
  }
  else
  {
    /* if DemError == (uint32)SPI_DEM_DMA_TRANSFER_ERROR */
    #if (SPI_DMA_ERROR_DEM_REPORT == ENABLE_DEM_REPORT)
    /* Dem for DMA error */
      Dem_ReportErrorStatus(SPI_E_DMA_TRANSFER,
               DEM_EVENT_STATUS_FAILED);

    #endif
  }

  CompletedJobSeqIndex = Spi_lCompletedJobId(JobSeqDataPtr);
  /* last job completed */
  /* extract the completed Job Id */
  JobId = JobSeqDataPtr->JobQueue[CompletedJobSeqIndex];
  SeqId = (uint8)JobSeqDataPtr->JobLinkedSeq[CompletedJobSeqIndex];

  /* Indicate Failure in Job */
  Spi_lSetJobStatusAtomic(JobId, SPI_JOB_FAILED);
  /* Set Sequence to Idle to indicate that another Transmission can be
     Started on any other sequence that shared a job with this sequence */
  Spi_lSetSeqStatusAtomic(SeqId, SPI_SEQ_FAILED);

  /*IFX_MISRA_RULE_17_04_STATUS="SpiJobConfigPtr" Pointer arithmetic used due to
    PBConfigStructure and is within allowed range.*/
  JobConfigPtr = &(Spi_kConfigPtr->SpiJobConfigPtr[JobId]);
  #if (SPI_SEQ_END_NOTIF_REQ == STD_ON)
  /*IFX_MISRA_RULE_17_04_STATUS="SpiSequenceConfigPtr" Pointer arithmetic used
    due to PBConfigStructure and is within allowed range.*/
  SeqConfigPtr = &(Spi_kConfigPtr->SpiSequenceConfigPtr[SeqId]);
  #endif

  CsPinLocal = JobConfigPtr->CSPin;

  /* Disable Chip Select */
  if (SPI_CS_NONE != CsPinLocal)
  {
    Spi_lDisableChipSelect(CsPinLocal,JobConfigPtr->CSPolarity,
                           JobConfigPtr->HwUnit, ApiAccessId);
  }
  Spi_lHwDisableQspiTxIntr(Module, ApiAccessId); /* Disable Tx Intr */
  Spi_lHwClrQspiPendEvent(ModulePtr, ApiAccessId); /* Clear error intr */
  Spi_lHwDisableModule(Module, ApiAccessId);

  Spi_lHwDisableQspiRxIntr(Module, ApiAccessId);
  Spi_lHwDisableQspiErrIntr(Module);

  /*Fix for AI00254397 */
  SchM_Enter_Spi_AsyncTransmit(); /* Enter Critical Section: EnterKey-D */
  StartIndex = JobSeqDataPtr->StartIndexExtractJobId ;
  Seqbool = 0U;
  while ((StartIndex != JobSeqDataPtr->EndIndex) && (Seqbool == 0U))
  {
    NextSeqId = JobSeqDataPtr->JobLinkedSeq[StartIndex];
    if (Spi_lGetSeqStatus(NextSeqId) == SPI_SEQ_FAILED)
    {
      StartIndex = Spi_lIncrementAndRoundIndex(StartIndex);

    }
    else
    {
      Seqbool = 1U;
    }
  }
  JobSeqDataPtr->StartIndexExtractJobId = StartIndex;

      #if (SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)
      JobSeqDataPtr->CurrentJobIndex[SeqId] = 0U;
      #else
      JobSeqDataPtr->CurrentJobIndex = 0U;
      #endif
 /*(SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)*/

    /* The variables are read into local variables to remove Misra 1.2 */
    ExtractJobId = JobSeqDataPtr->StartIndexExtractJobId;
    EndIndex = JobSeqDataPtr->EndIndex;

    if (ExtractJobId != EndIndex)
    {
      JobId = JobSeqDataPtr->JobQueue[JobSeqDataPtr->StartIndexExtractJobId];
      /*
         Get SPI Bus. The SPI bus is extracted from each job .
      */
      /*IFX_MISRA_RULE_17_04_STATUS="SpiJobConfigPtr" Pointer arithmetic used
        due to PBConfigStructure and is within allowed range.*/
      HWUnit = (uint32 )Spi_kConfigPtr->SpiJobConfigPtr[JobId].HwUnit &
                        SPI_HWUNIT_MASK;

      JobSeqDataPtr->StartIndexExtractJobId = \
            Spi_lIncrementAndRoundIndex(JobSeqDataPtr->StartIndexExtractJobId);
      /* Exit Critical Section asap for minimal blocking time: ExitKey-D1*/
      SchM_Exit_Spi_AsyncTransmit();
      Spi_lStartJob(HWUnit, JobId, ApiAccessId);
    }
    else
    {
      Spi_lSetModAsyncBusStatus((Spi_StatusType)SPI_IDLE,(uint8)Module);
      Spi_BusStatus = SPI_IDLE;
      JobSeqDataPtr->EndIndex = 0U;
      JobSeqDataPtr->StartIndexExtractJobId = 0U;
      /* Exit Critical Section asap for minimal blocking time: ExitKey-D2*/
      SchM_Exit_Spi_AsyncTransmit();
    }/*(ExtractJobId != EndIndex)*/

   /* Call Notification if configured. */
  #if (SPI_JOB_END_NOTIF_REQ == STD_ON)
  if (JobConfigPtr->JobEndNotification != NULL_PTR)
  {
    (JobConfigPtr->JobEndNotification)();
  }
  #endif
 /*(SPI_JOB_END_NOTIF_REQ == STD_ON)*/

  #if (SPI_SEQ_END_NOTIF_REQ == STD_ON)
  if (SeqConfigPtr->SeqEndNotification != NULL_PTR)
  {
    (SeqConfigPtr->SeqEndNotification)();
  }
  #endif
 /*(SPI_SEQ_END_NOTIF_REQ == STD_ON)*/
}
#endif
 /* (SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U) */

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI263_2,
DS_AS_SPI054_SPI057_SPI071_SPI073_SPI088_SPI119_SPI120_SPI268_SPI281
DS_AS_SPI292,DS_AS_SPI014_SPI269_SPI270,DS_AS_SPI145_2 ]                      **
** Syntax           : static void Spi_lBusHandler                             **
**                    (                                                       **
**                      uint32 Module, uint8 ApiAccessId                      **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : Module- SPI Bus Id.                                     **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : The Bus handler performs the following:                 **
** 1.Starts next Channel Transmission                                         **
** 2.If the last channel is reached starts next Job transmission.(Schedule    **
** function is called)                                                        **
** 3.If the last job is reached starts next pending sequence transmission.    **
** (Schedule function is called)                                              **
** 4.Calls the job end and sequence end notification if                       **
** configured                                                                 **
*******************************************************************************/
#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
static void Spi_lBusHandler(uint32 Module, uint8 ApiAccessId)
{
  Spi_JobAndSeqAccessType  *JobSeqDataPtr;
  Spi_ChnlAccessType       *ChnlAccDataPtr;
  uint32 HWUnit;
  uint16 JobId;
  uint16 SICompletedJob;
  Spi_SequenceType CompletedJobSeqId;
  Spi_ChannelType ChannelId;
  uint16 ExtractJobId;
  uint16 EndIndex;
  #if ((SPI_JOB_END_NOTIF_REQ == STD_ON) || (SPI_SEQ_END_NOTIF_REQ == STD_ON))
  volatile  Spi_JobType JobIndex;
  #endif
  const Spi_JobConfigType* JobConfigPtr;
  const Spi_SequenceConfigType* SeqConfigPtr;
  uint8 IsLastChannel;
  Ifx_QSPI* ModulePtr;
  uint32 DelayAndHwChNo;

  #if((SPI_SAFETY_ENABLE == STD_ON) && (SPI_QM_ASYNC_MASTER_MODULES_USED == 0U))
  JobSeqDataPtr  = NULL_PTR; /* To remove warning: Possibly Uninitialised*/
  ChnlAccDataPtr = NULL_PTR; /* To remove warning: Possibly Uninitialised*/
  #endif

  #if (SPI_SAFETY_ENABLE == STD_ON)
    /* if module is ASIL */
    if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)Module))
    {
      JobSeqDataPtr  = &Spi_AsilJobAndSeqAccess;
      ChnlAccDataPtr = &Spi_AsilChnlAccess[0U];
    }
    else
    {
      #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
      #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
      JobSeqDataPtr = &Spi_QmJobAndSeqAccess;
      #else
      JobSeqDataPtr = &Spi_QmJobAndSeqAccess[Spi_lGetQmModuleVarIndex(Module)];
      #endif
      ChnlAccDataPtr = &Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)];
      #endif
      /* Do nothing if QM modules are NOT Used */
    }
  #else
    {
      #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
      JobSeqDataPtr = &Spi_QmJobAndSeqAccess;
      #else
      JobSeqDataPtr = &Spi_QmJobAndSeqAccess[Spi_lGetQmModuleVarIndex(Module)];
      #endif
      ChnlAccDataPtr = &Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)];
    }
  #endif

  /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used to
    efficiently access the SFRs of multiple QSPI Modules.*/
  ModulePtr =  &(SPI_HW_MODULE[Module]);

  SICompletedJob = Spi_lCompletedJobId(JobSeqDataPtr);
  /* last job completed */
  /* extract the completed Job Id */
  JobId = JobSeqDataPtr->JobQueue[SICompletedJob];
  /* Increment Channel Index to the next Channel in the Job Link */
  ChnlAccDataPtr->CurrentChannelIndex++;
  /*IFX_MISRA_RULE_17_04_STATUS="SpiJobConfigPtr" Pointer arithmetic used due to
    PBConfigStructure and is within allowed range.*/
  JobConfigPtr = &(Spi_kConfigPtr->SpiJobConfigPtr[JobId]);
  /*IFX_MISRA_RULE_17_04_STATUS="ChannelLinkPtr" Pointer arithmetic used due to
    PBConfigStructure and is within allowed range.*/
  ChannelId = JobConfigPtr->ChannelLinkPtr[ChnlAccDataPtr->CurrentChannelIndex];

  /*Last Channel already transmitted. i.e end of job/seq*/
  if (ChannelId == SPI_CHANNEL_LINK_DELIMITER)
  {
    if (JobConfigPtr->CSPin != SPI_CS_NONE)
    {
      /* Release Chip Select at end of Job Transmission*/
      Spi_lDisableChipSelect(JobConfigPtr->CSPin,JobConfigPtr->CSPolarity,
                              JobConfigPtr->HwUnit, ApiAccessId);
    }

    #if (SPI_LEVEL_DELIVERED == 2U)
    if (Spi_AsyncMode != (uint8)SPI_POLLING_MODE)
    #endif
 /*(SPI_LEVEL_DELIVERED == 2U)*/
    {
      Spi_lHwDisableQspiErrIntr(Module);

      Spi_lHwDisableQspiPtIntr(Module);

    }
    Spi_lHwDisableQspiTxIntr(Module, ApiAccessId);
    Spi_lHwDisableQspiUsrIntr(Module, ApiAccessId);
    Spi_lHwDisableQspiRxIntr(Module, ApiAccessId);
    Spi_lHwClrQspiPendEvent(ModulePtr, ApiAccessId); /* Clear error intr */

    Spi_lSetJobStatusAtomic(JobId, SPI_JOB_OK);
    CompletedJobSeqId = JobSeqDataPtr->JobLinkedSeq[SICompletedJob];
    /*IFX_MISRA_RULE_17_04_STATUS="SpiSequenceConfigPtr" Pointer arithmetic used
      due to PBConfigStructure and is within allowed range.*/
    SeqConfigPtr = &(Spi_kConfigPtr->SpiSequenceConfigPtr[CompletedJobSeqId]);

    #if (SPI_CANCEL_API == STD_ON)
    Spi_lSeqCancelled(JobSeqDataPtr);
    #endif
    /*(SPI_CANCEL_API == STD_ON)*/

    #if (SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)
    /* Increment Job Index to the next Job in the Job Link */
    JobSeqDataPtr->CurrentJobIndex[CompletedJobSeqId]++ ;
    #if ((SPI_JOB_END_NOTIF_REQ == STD_ON) || (SPI_SEQ_END_NOTIF_REQ == STD_ON))
    JobIndex = JobSeqDataPtr->CurrentJobIndex[CompletedJobSeqId];
    #endif
    #else
    JobSeqDataPtr->CurrentJobIndex++;
    #if ((SPI_JOB_END_NOTIF_REQ == STD_ON) || (SPI_SEQ_END_NOTIF_REQ == STD_ON))
    JobIndex = JobSeqDataPtr->CurrentJobIndex;
    #endif
    #endif
    /*(SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)*/

    #if (SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)
    /*IFX_MISRA_RULE_17_04_STATUS="CurrentJobIndex" Pointer arithmetic used due
      to PBConfigStructure and is within allowed range.*/
    if (
    SeqConfigPtr->JobLinkPtr[JobSeqDataPtr->CurrentJobIndex[CompletedJobSeqId]]\
                                                  ==    SPI_JOB_LINK_DELIMITER)
    #else
    /*IFX_MISRA_RULE_17_04_STATUS="JobLinkPtr" Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    if (SeqConfigPtr->JobLinkPtr[JobSeqDataPtr->CurrentJobIndex] == \
                                                      SPI_JOB_LINK_DELIMITER)
    #endif
    /*(SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)*/
    {
      #if (SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)
      JobSeqDataPtr->CurrentJobIndex[CompletedJobSeqId] = 0U;
      #else
      JobSeqDataPtr->CurrentJobIndex = 0U;
      #endif
      /*(SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)*/
      /* Set Sequence to Idle to indicate that another Transmission can be
         Started on any other sequence that shared a job with this sequence */
      Spi_lSetSeqStatusAtomic(CompletedJobSeqId, SPI_SEQ_OK);
    }

   /* AI00239711:JobEnd notification must be called before starting next job*/
   /*
    This check is for the last job or job of the current ongoing sequence and to
    provide the SeqEndNotification and JobEndNotification if configured
    */
    #if ((SPI_JOB_END_NOTIF_REQ == STD_ON) || (SPI_SEQ_END_NOTIF_REQ == STD_ON))
    /*IFX_MISRA_RULE_17_04_STATUS="JobLinkPtr" Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    if (SeqConfigPtr->JobLinkPtr[JobIndex] == SPI_JOB_LINK_DELIMITER)
    {

      /*If a callback notification is configured as null pointer,
       no callback shall be executed.*/
      #if (SPI_JOB_END_NOTIF_REQ == STD_ON)
      Spi_lJobEndNotif(JobConfigPtr);
      #endif
      /*(SPI_JOB_END_NOTIF_REQ == STD_ON)*/
       /*If a callback notification is configured as null pointer,
        no callback shall be executed.*/
      #if (SPI_SEQ_END_NOTIF_REQ == STD_ON)
      if (SeqConfigPtr->SeqEndNotification != NULL_PTR)
      {
        /*At the end of a Seq transmission if the
        corresponding "End Seq Notification" is configured as non null
        pointer, it shall be called.*/
        (SeqConfigPtr->SeqEndNotification)();
      }/*(SeqConfigPtr->SeqEndNotification != NULL_PTR)*/
      #endif
      /*(SPI_SEQ_END_NOTIF_REQ == STD_ON)*/
    }
    else
    {
      #if (SPI_JOB_END_NOTIF_REQ == STD_ON)
        Spi_lJobEndNotif(JobConfigPtr);
      #endif
      /*(SPI_JOB_END_NOTIF_REQ == STD_ON)*/
    }
    #endif
    /*((SPI_JOB_END_NOTIF_REQ == STD_ON) ||
                                          (SPI_SEQ_END_NOTIF_REQ == STD_ON))*/

    /*Fix for AI00254397 */
    SchM_Enter_Spi_AsyncTransmit(); /* Enter Critical Section: EnterKey-E */
    /* The variables are read into local variables to remove Misra 1.2 */
    ExtractJobId = JobSeqDataPtr->StartIndexExtractJobId;
    EndIndex = JobSeqDataPtr->EndIndex;

    if (ExtractJobId != EndIndex)
    {
      JobId = JobSeqDataPtr->JobQueue[JobSeqDataPtr->StartIndexExtractJobId];
      /*
         Get SPI Bus. The SPI bus is extracted from each job .
      */
      /*IFX_MISRA_RULE_17_04_STATUS="SpiJobConfigPtr" Pointer arithmetic used
        due to PBConfigStructure and is within allowed range.*/
      HWUnit = (uint32 )Spi_kConfigPtr->SpiJobConfigPtr[JobId].HwUnit &
                        SPI_HWUNIT_MASK;
      JobSeqDataPtr->StartIndexExtractJobId = \
      Spi_lIncrementAndRoundIndex(JobSeqDataPtr->StartIndexExtractJobId);
      /* Exit Critical Section asap for minimal blocking time: ExitKey-E1*/
      SchM_Exit_Spi_AsyncTransmit();
      Spi_lStartJob(HWUnit, JobId, ApiAccessId);
    }
    else
    {
      Spi_lSetModAsyncBusStatus((Spi_StatusType)SPI_IDLE,(uint8)Module);
      Spi_BusStatus = SPI_IDLE;
      JobSeqDataPtr->EndIndex = 0U;
      JobSeqDataPtr->StartIndexExtractJobId = 0U;
      /* Exit Critical Section asap for minimal blocking time: ExitKey-E2*/
      SchM_Exit_Spi_AsyncTransmit();
    }/*(ExtractJobId != EndIndex)*/

  }/*(ChannelId == SPI_CHANNEL_LINK_DELIMITER)*/
  else
  {
    /* Next channel is last channel */
    /*IFX_MISRA_RULE_17_04_STATUS="CurrentChannelIndex" Pointer arithmetic used
      due to PBConfigStructure and is within allowed range.*/
    if (JobConfigPtr->ChannelLinkPtr[ChnlAccDataPtr->CurrentChannelIndex + 1U]
                      == SPI_CHANNEL_LINK_DELIMITER)
    {
      IsLastChannel = 1U;
    }
    else
    {
      IsLastChannel = 0U;
    }

    DelayAndHwChNo = JobConfigPtr->TimeDelayConfig|
         ((((uint32)JobConfigPtr->HwUnit >> SPI_HWUNIT_CH_SHIFT) &
         SPI_HWUNIT_MASK) <<  SPI_CONFIG_HWCHANNELNO_SHIFT);

    Spi_lStartChannel(Module, ChannelId, IsLastChannel, DelayAndHwChNo,
                                                  0U, JobConfigPtr,ApiAccessId);
  }
}
#endif
/* (SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U) */

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI263_3,DS_AS_SPI267_2,
DS_AS_SPI286,DS_AS_SPI006_2]                                                  **
** Syntax : static void Spi_lSyncStartJob                                     **
** (                                                                          **
**   Spi_JobType Job                                                          **
** )                                                                          **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant  (for different JobIds)                            **
**                                                                            **
** Parameters (in) : Job - JobId                                              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
**                                                                            **
** Description : Sets up the SPI HW According to Job Parameters.              **
**               Enables CS                                                   **
**               CLK to CS Timing.                                            **
**               Call to Start Channel                                        **
*******************************************************************************/
#if ((SPI_LEVEL_DELIVERED == 0U) || (SPI_LEVEL_DELIVERED == 2U))
#if(SPI_LEVEL2_ASYNC_ONLY == STD_OFF)
static void Spi_lSyncStartJob(Spi_JobType JobId)
{

  const Spi_JobConfigType* JobConfigPtr;
  Spi_ChannelType ChannelId;
  Ifx_QSPI* ModulePtr;
  uint32 ChannelIndex;
  uint32 LstChFrstChAndHwPin;
  uint32 DelayAndHwChNo;
  uint32 ReadValue;
  uint8  firstchannel;
  uint8  lastchannel;
  uint16 HwPin;
  volatile uint32 cntr;
  cntr = SPI_LOOPCNTR_MAX;
  ReadValue = 0U;
  firstchannel = 1U;

  /*IFX_MISRA_RULE_17_04_STATUS="SpiJobConfigPtr" Pointer arithmetic used due to
    PBConfigStructure and is within allowed range.*/
  JobConfigPtr = &(Spi_kConfigPtr->SpiJobConfigPtr[JobId]);

  /* Get the Spi Bus of the Job */
  /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used to
    efficiently access the SFRs of multiple QSPI Modules.*/
  ModulePtr = &(SPI_HW_MODULE[JobConfigPtr->HwUnit & SPI_HWUNIT_MASK]);

  /* Configure Baudrate, CLK POL, PHASE  */
  Spi_lHwSetJobConfig(ModulePtr, JobConfigPtr);

  /* Set Job Status to Pending */
  Spi_lSetJobStatus(JobId,SPI_JOB_PENDING);

  /* The Chip Select (CS) is attached to the Job definition. Chip Select
  shall be handled during Job transmission and shall be released at the end of
  it.This Chip Select handling shall be done according to the Job configuration
  parameters. */
  if (JobConfigPtr->CSPin == SPI_CS_HW)
  {
    Spi_lEnableChipSelect(JobConfigPtr->CSPin,JobConfigPtr->CSPolarity,
                          JobConfigPtr->HwUnit, SPI_RUNTIME_ACCESS);
  }

  /* Initialize Channel Index to the first Channel */
  ChannelIndex = 0U;
    /*
   Get the Channel Id of the first Channel from Job link,
   Channel Id corresponds to the array index of struct: Spi_ChannelConfig
  */
  /*IFX_MISRA_RULE_17_04_STATUS="ChannelLinkPtr" Pointer arithmetic used due to
    PBConfigStructure and is within allowed range.*/
  ChannelId = JobConfigPtr->ChannelLinkPtr[ChannelIndex];

  do
  {
    DelayAndHwChNo = JobConfigPtr->TimeDelayConfig |
    ( ( ((uint32)JobConfigPtr->HwUnit >> SPI_HWUNIT_CH_SHIFT) &
          SPI_HWUNIT_MASK) << SPI_CONFIG_HWCHANNELNO_SHIFT);

    /*IFX_MISRA_RULE_17_04_STATUS="ChannelLinkPtr" Pointer arithmetic used due
      to PBConfigStructure and is within allowed range.*/
    if (JobConfigPtr->ChannelLinkPtr[ChannelIndex + 1U] ==
                   SPI_CHANNEL_LINK_DELIMITER)
    {

      lastchannel = 1U;
    }
    else
    {
      lastchannel = 0U;
    }

    HwPin = JobConfigPtr->CSPin;
    /* pack three variables into single variable */
    LstChFrstChAndHwPin = (uint32)(
                               ((uint32)firstchannel << SPI_FRSTCH_SHIFTBITS)
                             | (((uint32)lastchannel  << SPI_LASTCH_SHIFTBITS)
                                |(uint32)HwPin));

    /* Start Channel Transmission */
    Spi_lSyncStartChannel(((uint32)JobConfigPtr->HwUnit & SPI_HWUNIT_MASK),
                    ChannelId, LstChFrstChAndHwPin, DelayAndHwChNo,
                    JobConfigPtr->CSPolarity, JobConfigPtr);

    firstchannel = 0U;

    /* Get next channel index */
    ChannelIndex++;
    /* Get  next channel from the Job Link */
    /*IFX_MISRA_RULE_17_04_STATUS="ChannelLinkPtr" Pointer arithmetic used due
      to PBConfigStructure and is within allowed range.*/
    ChannelId = JobConfigPtr->ChannelLinkPtr[ChannelIndex];
    /* if receive error */
    if (Spi_lHwCheckRxStatus(ModulePtr, SPI_RUNTIME_ACCESS))
    {
      #if (SPI_HW_ERROR_DEM_REPORT == ENABLE_DEM_REPORT)
      /* Dem for receive error*/
      Dem_ReportErrorStatus(SPI_E_HARDWARE_ERROR,DEM_EVENT_STATUS_FAILED);
      #endif
      ChannelId = SPI_CHANNEL_LINK_DELIMITER;
      Spi_lSetJobStatus(JobId,SPI_JOB_FAILED);
    }
  }while (ChannelId != SPI_CHANNEL_LINK_DELIMITER);/* The last Channel
                                                       is not reached */
  /* Disable Chip Select at end of Transmission or on Error */
  if (JobConfigPtr->CSPin != SPI_CS_NONE)
  {
    /* Wait till the trailing delay is over */
    /* PHASE == 5 changed to PHASE <=5 due to JIRA 0000054991-31 */
    do
    {
      ReadValue = (uint32)SPI_SFR_RUNTIME_USER_MODE_READ32(ModulePtr->STATUS.U);
      cntr--;
      if (cntr == 0U)
      {
        break;
      }
    }
    while ((((ReadValue & SPI_STATUS_PHASE_CLEARMASK)\
                 >>SPI_STATUS_PHASE_BITPOS) > 0U) && (((ReadValue & \
                SPI_STATUS_PHASE_CLEARMASK)>>SPI_STATUS_PHASE_BITPOS) <= 5U));
    /* Release Chip Select at end of Job Transmission*/
    Spi_lDisableChipSelect(JobConfigPtr->CSPin,JobConfigPtr->CSPolarity,
                           JobConfigPtr->HwUnit, SPI_RUNTIME_ACCESS);
  }
  UNUSED_PARAMETER(ReadValue)
}
#endif /* SPI_LEVEL2_ASYNC_ONLY == STD_OFF */
#endif
 /* ((SPI_LEVEL_DELIVERED == 0) || (SPI_LEVEL_DELIVERED == 2U)) */

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI028_2_SPI030_2]                    **
** Syntax : static void Spi_lSyncStartChannel                                 **
** (                                                                          **
**   uint32 Module,                                                           **
**   Spi_ChannelType ChannelId,                                               **
**   uint32 LstChFrstChAndHwPin,                                              **
**   uint32 DelayAndHwChNo,                                                   **
**   uint8 polarity                                                           **
**   const Spi_JobConfigType* JobConfigPtr )                                  **
** )                                                                          **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant (for different channel Ids)                        **
**                                                                            **
** Parameters (in) :   Module - ModuleId                                      **
**                     Channel    - ChannelId                                 **
**                     LstChFrstChAndHwPin   - packed variable                **
**                     DelayAndHwChNo    - packed variable delay and ch no    **
**                     polarity    - polarity                                 **
**                     JobConfigPtr    - Job pointer                          **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :                                                          **
**                                                                            **
**                                                                            **
** Description :  Get the Channel Buffers.(Handling of 32, 16 bit and 8 bit   **
**                buffers)                                                    **
**                Set up Channel Data proporties on the Spi Hw Module         **
**                Wait for the transmission of the word to be completed       **
**                Loop until all words/channellength are transmitted          **
*******************************************************************************/
#if ((SPI_LEVEL_DELIVERED == 0U) || (SPI_LEVEL_DELIVERED == 2U))
#if(SPI_LEVEL2_ASYNC_ONLY == STD_OFF)
static void Spi_lSyncStartChannel
(
  uint32 Module,
  Spi_ChannelType ChannelId,
  uint32 LstChFrstChAndHwPin,
  uint32 DelayAndHwChNo,
  uint8 polarity,
  const Spi_JobConfigType* JobConfigPtr
)
{
  const Spi_ChannelConfigType* ChannelConfigPtr;
  Spi_SyncTransParamType Spi_SyncTransParameters;
  uint32 TransferCount;
  const uint32* SrcDataPtr32;
  const uint16* SrcDataPtr16;
  const Spi_DataType* SrcDataPtr8;
  uint32* DesDataPtr32;
  uint16* DesDataPtr16;
  Spi_DataType* DesDataPtr8;
  Ifx_QSPI *ModulePtr;
  uint8 IsLastChannel;
  uint8 FirstChannel;
  uint16 hwpin;

  /* If EB Channel type is configured */
  #if (SPI_CHANNEL_BUFFERS_ALLOWED != 0U)
  Spi_EBBufferType* EBBufferPtr;
  Spi_ChannelType EBChannelId;
  #endif
  /*(SPI_CHANNEL_BUFFERS_ALLOWED != 0) */

  /* Extract variables from packed variable */
  IsLastChannel = (uint8) ((LstChFrstChAndHwPin & SPI_LASTCHNL_MASK) >>
                                                         SPI_LASTCH_SHIFTBITS);
  FirstChannel  = (uint8) ((LstChFrstChAndHwPin & SPI_FRSTCHNL_MASK) >>
                                                         SPI_FRSTCH_SHIFTBITS);
  hwpin         = (uint16)(LstChFrstChAndHwPin & SPI_LSB16BITS_MASK);

  /* Initialize Buffer Pointers */
  SrcDataPtr32 = NULL_PTR;
  SrcDataPtr16 = NULL_PTR;
  SrcDataPtr8  = NULL_PTR;
  DesDataPtr32 = NULL_PTR;
  DesDataPtr16 = NULL_PTR;
  DesDataPtr8  = NULL_PTR;

  /*IFX_MISRA_RULE_17_04_STATUS="SpiChannelConfigPtr" Pointer arithmetic used
    due to PBConfigStructure and is within allowed range.*/
  ChannelConfigPtr = &(Spi_kConfigPtr->SpiChannelConfigPtr[ChannelId]);
  /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used to
    efficiently access the SFRs of multiple QSPI Modules.*/
  ModulePtr =   &(SPI_HW_MODULE[Module]);

  #if (SPI_CHANNEL_BUFFERS_ALLOWED == 2U)
  if (ChannelConfigPtr->ChannelBufferType == SPI_EB_BUFFER)
  #endif
 /* (SPI_CHANNEL_BUFFERS_ALLOWED == 2U) */

  #if (SPI_CHANNEL_BUFFERS_ALLOWED != 0U)
  /* EB Channel Type handling */
  {
    /*Get EB Channel Position */
    EBChannelId = ChannelId - Spi_NoOfIBChannels;
    EBBufferPtr = &(Spi_EBBuffer[EBChannelId]);
    TransferCount = EBBufferPtr->Length;

    if (ChannelConfigPtr->DataConfig & SPI_32BIT_DATAMASK)
    {
      SrcDataPtr32 = (const uint32*)(const void*)EBBufferPtr->SrcPtr;
      DesDataPtr32 = (uint32*)(void*)EBBufferPtr->DestPtr;
    }
    /* Data is 16 Bits */
    else if (ChannelConfigPtr->DataConfig & SPI_16BIT_DATAMASK)
    {
      SrcDataPtr16 = (const uint16*)(const void*)EBBufferPtr->SrcPtr;
      DesDataPtr16 = (uint16*)(void*)EBBufferPtr->DestPtr;
    }
    else
    {
      /* Data = 8 Bits */
      SrcDataPtr8 = EBBufferPtr->SrcPtr;
      DesDataPtr8 = EBBufferPtr->DestPtr;
    }
  }/*(ChannelConfigPtr->ChannelBufferType == SPI_EB_BUFFER)*/
  #endif
  /*(SPI_CHANNEL_BUFFERS_ALLOWED != 0) */

  #if (SPI_CHANNEL_BUFFERS_ALLOWED == 2U)
  else
  #endif
 /* (SPI_CHANNEL_BUFFERS_ALLOWED == 2U) */
  #if (SPI_CHANNEL_BUFFERS_ALLOWED != 1U)
  /*IB Channel Type Handling */
  {
    /* The channel data received shall be stored in 1 entry deep
       internal buffers by channel.
       The channel data to be transmitted shall be copied in 1 entry
       deep internal buffers by channel. The SPI Handler/Driver is not able to
       prevent the overwriting of these "transmit" buffers by users during
       transmissions */
    TransferCount = (uint32)ChannelConfigPtr->NoOfBuffers;
    /* Data is 32 Bits */
    if (ChannelConfigPtr->DataConfig & SPI_32BIT_DATAMASK)
    {
      /*IFX_MISRA_RULE_11_01_STATUS=Typecasting Spi_IBBufferAccess to uint32
        is unvoidable. SrcDataPtr32 is later used for SFR assignment.*/
      /*IFX_MISRA_RULE_11_01_STATUS=Typecasting Spi_IBBufferAccess to const
        uint32* is unvoidable. DesDataPtr32 is later used for SFR assignment.*/
      /*IFX_MISRA_RULE_11_03_STATUS=Type cast to uint32* is unavoidable*/
      /*IFX_MISRA_RULE_11_03_STATUS=Type cast to uint32 is unavoidable*/
      SrcDataPtr32 = (const uint32*)(((uint32)(&(Spi_IBBufferAccess. \
                    IBBuffer[Spi_IBBufferAccess.IBBufferOffset[ChannelId]]))));

      /*IFX_MISRA_RULE_11_05_STATUS="SrcDataPtr32" attempt to cast away
        volatile in terms of pointer access.*/
      /*IFX_MISRA_RULE_17_04_STATUS="DesDataPtr32" Pointer arithmetic used due
        to BufferStructure and is within allowed range.*/
      DesDataPtr32 = (uint32*)(void*)((uint8 *)(void*)SrcDataPtr32 +\
                                                 (SPI_MAXIMUM_IB_BUFFER_SIZE));
    }
    else if (ChannelConfigPtr->DataConfig & SPI_16BIT_DATAMASK)
    {
      /*IFX_MISRA_RULE_11_01_STATUS=Typecasting Spi_IBBufferAccess to uint32
        is unvoidable. SrcDataPtr16 is later used for SFR assignment.*/
      /*IFX_MISRA_RULE_11_01_STATUS=Typecasting Spi_IBBufferAccess to const
        uint16* is unvoidable. SrcDataPtr16 is later used for SFR assignment.*/
      /*IFX_MISRA_RULE_11_03_STATUS=Type cast to uint16* is unavoidable*/
      /*IFX_MISRA_RULE_11_03_STATUS=Type cast to uint32 is unavoidable*/
      SrcDataPtr16 = (const uint16*)(((uint32)(&(Spi_IBBufferAccess. \
                    IBBuffer[Spi_IBBufferAccess.IBBufferOffset[ChannelId]]))));

      /*IFX_MISRA_RULE_11_05_STATUS="SrcDataPtr16" attempt to cast away
        volatile in terms of pointer access.*/
      /*IFX_MISRA_RULE_17_04_STATUS="DesDataPtr16" Pointer arithmetic used due
        to BufferStructure and is within allowed range.*/
      DesDataPtr16 = (uint16*)(void*)((uint8 *)(void*)SrcDataPtr16 +\
                                                (SPI_MAXIMUM_IB_BUFFER_SIZE ));
    }
    else
    {
      /* Data is 8 Bits */
      /*IFX_MISRA_RULE_11_01_STATUS=Typecasting Spi_IBBufferAccess to uint32 is
        unvoidable. SrcDataPtr8 is later used for SFR assignment.*/
      /*IFX_MISRA_RULE_11_01_STATUS=Typecasting Spi_IBBufferAccess to
        const Spi_DataType* is unvoidable.
        SrcDataPtr8 is later used for SFR assignment.*/
      /*IFX_MISRA_RULE_11_03_STATUS=Type cast to uint32 is unavoidable*/
      /*IFX_MISRA_RULE_11_03_STATUS=Type cast to Spi_DataType* is unavoidable*/
      SrcDataPtr8 = (const Spi_DataType*)(((uint32)(&(Spi_IBBufferAccess.
                    IBBuffer[Spi_IBBufferAccess.IBBufferOffset[ChannelId]]))));
      /*IFX_MISRA_RULE_11_05_STATUS="SrcDataPtr8" attempt to cast away
        volatile in terms of pointer access.*/
      /*IFX_MISRA_RULE_17_04_STATUS="DesDataPtr8" Pointer arithmetic used due to
        BufferStructure and is within allowed range.*/
      DesDataPtr8 = (Spi_DataType*)(void*)(SrcDataPtr8 +\
                                                   SPI_MAXIMUM_IB_BUFFER_SIZE);
    }
  }/*IB Channel Type Handling */
  #endif
  /*(SPI_CHANNEL_BUFFERS_ALLOWED != 1U) */

  /* Workaround for RSM error not more than 5 params to function */
  Spi_SyncTransParameters.TransferCount = TransferCount;
  Spi_SyncTransParameters.hwpin         = hwpin;
  Spi_SyncTransParameters.ChannelId     = ChannelId;
  Spi_SyncTransParameters.FirstChannel  = FirstChannel;
  Spi_SyncTransParameters.IsLastChannel = IsLastChannel;
  Spi_SyncTransParameters.Polarity      = polarity;

  if (ChannelConfigPtr->DataConfig & SPI_32BIT_DATAMASK)
  {
    Spi_lHwSetChannelConfig(Module, ChannelConfigPtr,
               TransferCount >> SPI_TRANSFERCOUNT_SHIFT_32BIT,
               IsLastChannel, DelayAndHwChNo, JobConfigPtr);
    Spi_lSyncTransmit32BitData(ModulePtr,SrcDataPtr32,\
                        DesDataPtr32, Spi_SyncTransParameters);
  }
  else if (ChannelConfigPtr->DataConfig & SPI_16BIT_DATAMASK)
  /* Handling when  Data width is 16 Bits  */
  {
    Spi_lHwSetChannelConfig(Module, ChannelConfigPtr,
               TransferCount >> SPI_TRANSFERCOUNT_SHIFT_16BIT,
               IsLastChannel, DelayAndHwChNo, JobConfigPtr);
    Spi_lSyncTransmit16BitData(ModulePtr,SrcDataPtr16,\
                          DesDataPtr16, Spi_SyncTransParameters);
  }
  else
  {
    /* Handling when Data Width is 8 Bits */
    Spi_lHwSetChannelConfig(Module, ChannelConfigPtr,
                               TransferCount, IsLastChannel, DelayAndHwChNo,
                               JobConfigPtr);
    Spi_lSyncTransmit8BitData(ModulePtr,SrcDataPtr8,\
                          DesDataPtr8,Spi_SyncTransParameters);

  }/*(ChannelConfigPtr->DataConfig & SPI_32BIT_DATAMASK)*/
}
#endif /* SPI_LEVEL2_ASYNC_ONLY == STD_OFF */
#endif
 /* ((SPI_LEVEL_DELIVERED == 0) || (SPI_LEVEL_DELIVERED == 2U)) */

/*******************************************************************************
** Syntax : IFX_LOCAL_INLINE uint16 Spi_lModuleConfigured(uint8 Module)       **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) :   uint8 Module                                           **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :                                                          **
**                                                                            **
** Description :  returns Non zero value if module configured as Master       **
*******************************************************************************/
IFX_INLINE uint16 Spi_lModuleConfigured(uint8 Module)
{
  uint16 RetVal = 1U;

  #if(SPI_SLAVE_ENABLE == STD_ON)
  if(SPI_SLAVE_MODULE_INDEX == Module)
  { /* should skip for Slave module */
    RetVal = (uint16)0U;
  }
  else
  #endif
  {
    if((Spi_kConfigPtr->HWModuleConfigPtr[Module])->HWClkSetting
                                               == SPI_NOT_CONFIGURED)
    {
      RetVal = 0U;
    }
  }
  return RetVal;
}

/*******************************************************************************
** Syntax : IFX_LOCAL_INLINE uint16 Spi_lAnyModuleConfigured(uint8 Module)    **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) :   uint8 Module                                           **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :                                                          **
**                                                                            **
** Description : returns Non zero value if module configured for Master/Slave **
*******************************************************************************/
IFX_LOCAL_INLINE uint16 Spi_lAnyModuleConfigured(uint8 Module)
{
   uint16 RetVal = 0U;

  #if(SPI_SLAVE_ENABLE == STD_ON)
  if(SPI_SLAVE_MODULE_INDEX == Module)
  {
    RetVal = (uint16)1U;
  }
  else
  #endif
  {
    if((Spi_kConfigPtr->HWModuleConfigPtr[Module])->HWClkSetting
                                                  != SPI_NOT_CONFIGURED)
    {
      RetVal = 1U;
    }
  }
  return RetVal;
}

/* Fix for AI00245697: Item.2 */
#if  (SPI_LEVEL_DELIVERED != 0U)
/*******************************************************************************
** Syntax: IFX_LOCAL_INLINE uint16 Spi_lModuleConfiguredAndAsync(uint8 Module)**
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) :   uint8 Module                                           **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :                                                          **
**                                                                            **
** Description :  returns Non zero value if module configured as ASYNC Bus    **
*******************************************************************************/
IFX_INLINE uint16 Spi_lModuleConfiguredAndAsync(uint8 Module)
{
  uint16 RetVal = 0U;

  #if(SPI_SLAVE_ENABLE == STD_ON)
  /* should skip for Slave module */
  if(SPI_SLAVE_MODULE_INDEX != Module)
  #endif
  {
    if((Spi_kConfigPtr->HWModuleConfigPtr[Module])->HWClkSetting
                                                   != SPI_NOT_CONFIGURED)
    {
      RetVal = (uint16)((uint16)((1UL) << (Module))
                                            & ((uint16)SPI_ASYNC_MODULES));
    }
  }
  return RetVal;
}

/*******************************************************************************
** Syntax : IFX_LOCAL_INLINE uint16 Spi_lAnyModuleConfigAndAsync(uint8 Module)**
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) :   uint8 Module                                           **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :                                                          **
**                                                                            **
** Description : returns Non zero value if any module configured as ASYNC Bus **
*******************************************************************************/
IFX_LOCAL_INLINE uint16 Spi_lAnyModuleConfigAndAsync(uint8 Module)
{
  uint16 RetVal = 0U;
  #if(SPI_SLAVE_ENABLE == STD_ON)
  if(SPI_SLAVE_MODULE_INDEX == Module)
  {
    RetVal = (uint16)1U;
  }
  else
  #endif
  {
    if((Spi_kConfigPtr->HWModuleConfigPtr[Module])->HWClkSetting
                                                    != SPI_NOT_CONFIGURED)
    {
      RetVal = (uint16)((uint16)((1UL) << (Module))
                                            & ((uint16)SPI_ASYNC_MODULES));
    }
  }
  return RetVal;
}

#endif
 /* (SPI_LEVEL_DELIVERED != 0U) */

/*******************************************************************************
** Syntax : IFX_LOCAL_INLINE Spi_StatusType Spi_lGetHwStatus                  **
**  (uint8 ApiAccessId)                                                       **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : ApiAccessId- API access type                             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :   Spi_StatusType                                         **
**                                                                            **
** Description :  returns status of the configured SPI modules                **
*******************************************************************************/
static Spi_StatusType Spi_lGetHwStatus(uint8 ApiAccessId)
{
  uint32 temp;
  Spi_StatusType RetVal;

  #if (SPI_SAFETY_ENABLE == STD_ON)
  uint32 SeqStatusAsil = 0U;
  #endif
  #if (SPI_QM_MASTER_MODULES_USED != 0U)
  uint32 SeqStatusQm = 0U;
  #endif

  #if (SPI_SAFETY_ENABLE == STD_ON)
  Spi_StatusType SequenceStatusAsil = (Spi_StatusType)0U;
  #endif
  #if (SPI_QM_MASTER_MODULES_USED != 0U)
  Spi_StatusType SequenceStatusQm = (Spi_StatusType)0U;
  #endif
  Spi_StatusType SequenceStatus = (Spi_StatusType)0U;
  uint8 Index;

  Index = 0U;

  #if (SPI_PB_FIXEDADDR == STD_OFF)
  if (Spi_kConfigPtr == NULL_PTR)
  {
    RetVal = SPI_UNINIT;
  }
  #else
  if (Spi_InitStatus == SPI_DRIVER_DEINITIALIZED)
  {
    RetVal = SPI_UNINIT;
  }
  #endif
 /*(SPI_PB_FIXEDADDR == STD_ON)*/
  else
  {
    RetVal = SPI_IDLE;

    #if (SPI_SAFETY_ENABLE == STD_ON)
    #if (SPI_SEQUENCE_ASIL_ARRAY_INDEX > 1U)
    do
    {
    #endif
      SeqStatusAsil = Spi_AsilSeqStatus[Index].AsilSeqStatus;
      temp = SeqStatusAsil & SPI_SEQ_BUSY_MASK;

      if (temp != 0U)
      {
        if( Spi_lGetSeqStatusInArray(SeqStatusAsil))
        {
           /*if any of the seq pending */
           SequenceStatusAsil = (Spi_StatusType)1U;
           #if (SPI_SEQUENCE_ASIL_ARRAY_INDEX > 1U)
           break;
           #endif
        }
      }
    #if (SPI_SEQUENCE_ASIL_ARRAY_INDEX > 1U)
      Index++;
    }while (Index < SPI_SEQUENCE_ASIL_ARRAY_INDEX);
    #endif

    /* Clear so that QM status check loop is not effected */
    #if (SPI_QM_MASTER_MODULES_USED != 0U)
    #if (SPI_SEQUENCE_QM_ARRAY_INDEX > 1U)
    Index = 0U;
    #endif
    #endif
    /* (SPI_QM_MASTER_MODULES_USED != 0U) */
    #endif
    /* (SPI_SAFETY_ENABLE == STD_ON) */

    #if (SPI_QM_MASTER_MODULES_USED != 0U)
    #if (SPI_SEQUENCE_QM_ARRAY_INDEX > 1U)
    do
    {
    #endif
      SeqStatusQm = Spi_QmSeqStatus[Index].QmSeqStatus;
      temp = SeqStatusQm & SPI_SEQ_BUSY_MASK;

      if (temp != 0U)
      {
        if( Spi_lGetSeqStatusInArray(SeqStatusQm))
        {
           /*if any of the seq pending */
           SequenceStatusQm = (Spi_StatusType)1U;
           #if (SPI_SEQUENCE_QM_ARRAY_INDEX > 1U)
           break;
           #endif
        }
      }
    #if (SPI_SEQUENCE_QM_ARRAY_INDEX > 1U)
      Index++;
    }while (Index < SPI_SEQUENCE_QM_ARRAY_INDEX);
    #endif
    #endif
    /* (SPI_QM_MASTER_MODULES_USED != 0U) */

    #if (SPI_SAFETY_ENABLE == STD_ON)
      #if (SPI_QM_MASTER_MODULES_USED == 0U)
      /* Safety on and No QM modules */
      SequenceStatus = SequenceStatusAsil;
      #else
      /* Safety on and QM modules then take QM
      modules status into acccount */
      if( (SequenceStatusAsil == (Spi_StatusType)1U) ||
                                      (SequenceStatusQm == (Spi_StatusType)1U))
      {
        SequenceStatus = (Spi_StatusType)1U;
      }
      else
      {
        /*Do Nothing*/
      }
      #endif
    #else
       /* Safety Off then only QM modules are taken into account */
       SequenceStatus = SequenceStatusQm;
    #endif

    if (SequenceStatus == (Spi_StatusType)1U)
    {
      RetVal = SPI_BUSY;
    }
    else
    {
      Index = 0U;
      /* Check for all the SFRs common for all levels */
      do
      {
        if(Spi_lAnyModuleConfigured((uint8)Index) != 0U)
        {
          if (ApiAccessId == SPI_DEINIT_ACCESS)
          {
            /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is
              used to efficiently access the SFRs of multiple QSPI Modules.*/
            temp = ((uint32)((uint32)(SPI_SFR_DEINIT_USER_MODE_READ32\
                   (SPI_HW_MODULE[Index].STATUS.U))&SPI_STATUS_PHASE_CLEARMASK)\
                                                     >>SPI_STATUS_PHASE_BITPOS);
          }
          else
          {
            /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is
              used to efficiently access the SFRs of multiple QSPI Modules.*/
            temp = ((uint32)((uint32)(SPI_SFR_RUNTIME_USER_MODE_READ32\
                   (SPI_HW_MODULE[Index].STATUS.U))&SPI_STATUS_PHASE_CLEARMASK)\
                                                     >>SPI_STATUS_PHASE_BITPOS);
          }
          if(temp != 0U)
          {
            RetVal = SPI_BUSY;
            break;
          }
        }
        Index++;
      }while  (Index < SPI_MAX_HW_UNIT);
    }
  }
  return RetVal;
} /* End of Function: Spi_lGetHwStatus */

#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
#if (SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)
/*******************************************************************************
** Syntax : static void Spi_lCheckPushSeqJobsToQ                              **
** (                                                                          **
** const Spi_SequenceConfigType* SeqConfigPtr,                                **
** uint32 JobCounter,                                                         **
** Spi_SequenceType Sequence                                                  **
** )                                                                          **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) :   Spi_SequenceConfigType* SeqConfigPtr                   **
**                     uint32 JobCounter                                      **
**                     Spi_SequenceType Sequence                              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :                                                          **
**                                                                            **
**                                                                            **
** Description :  This will push all the jobs into Queue                      **
*******************************************************************************/
static void Spi_lCheckPushSeqJobsToQ
(
Spi_JobAndSeqAccessType* JobSeqDataPtr,
uint32 JobCounter,
Spi_SequenceType Sequence
)
{
  const Spi_SequenceConfigType* SeqConfigPtr;

  /*IFX_MISRA_RULE_17_04_STATUS="SpiSequenceConfigPtr" Pointer arithmetic used
    due to PBConfigStructure and is within allowed range.*/
  SeqConfigPtr = &(Spi_kConfigPtr->SpiSequenceConfigPtr[Sequence]);

  /*IFX_MISRA_RULE_17_04_STATUS="JobLinkPtr" Pointer arithmetic used due to
    PBConfigStructure and is within allowed range.*/
  while (SeqConfigPtr->JobLinkPtr[JobCounter] != SPI_JOB_LINK_DELIMITER)
  {
    /*IFX_MISRA_RULE_17_04_STATUS="JobLinkPtr" Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    JobSeqDataPtr->JobQueue[JobSeqDataPtr->EndIndex] =
                                          SeqConfigPtr->JobLinkPtr[JobCounter];
    JobSeqDataPtr->JobLinkedSeq[JobSeqDataPtr->EndIndex] = Sequence;

    /*Fix for AI00254397 */
    SchM_Enter_Spi_AsyncTransmit();
    JobSeqDataPtr->EndIndex++;
    if (JobSeqDataPtr->EndIndex == SPI_MAX_JOB_TRIG_Q_LENGTH)
    {
      JobSeqDataPtr->EndIndex = 0U;
    }
    SchM_Exit_Spi_AsyncTransmit();
    JobCounter++;
  }
}

/*******************************************************************************
** Syntax : IFX_LOCAL_INLINE uint32 Spi_lStoreToArrayAndReturnCount           **
** (                                                                          **
**   uint16 CurrentIndex,                                                     **
**   uint16 *JobQueuePtr,                                                     **
**   uint8 *SeqQueuePtr,                                                      **
**   Spi_JobAndSeqAccessType *JobSeqDataPtr                                   **
** )                                                                          **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant (for different channel Ids)                        **
**                                                                            **
** Parameters (in) :   uint16 CurrentIndex                                    **
**                     uint16 *JobQueuePtr                                    **
**                     uint8 *SeqQueuePtr                                     **
**                     Spi_JobAndSeqAccessType *JobSeqDataPtr                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :                                                          **
**                                                                            **
** Description :  This will push all the jobs in the local Queue to actual    **
**                queue                                                       **
*******************************************************************************/
IFX_LOCAL_INLINE uint32 Spi_lStoreToArrayAndReturnCount
(
uint16 CurrentIndex,
uint16 *JobQueuePtr,
uint8 *SeqQueuePtr,
const Spi_JobAndSeqAccessType *JobSeqDataPtr
)
{

  uint32 Counter;
  Counter = 0U;

  while (CurrentIndex != JobSeqDataPtr->EndIndex)
  {
    /*IFX_MISRA_RULE_17_04_STATUS="JobQueue" Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    JobQueuePtr[Counter] = JobSeqDataPtr->JobQueue[CurrentIndex];
    /*IFX_MISRA_RULE_17_04_STATUS="JobLinkedSeq" Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    SeqQueuePtr[Counter] = JobSeqDataPtr->JobLinkedSeq[CurrentIndex];
    Counter++;
    CurrentIndex = Spi_lIncrementAndRoundIndex(CurrentIndex);
  }
  return Counter;
}
#endif
 /*(SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)*/

#endif
  /*((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))*/

#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U)|| \
          (SPI_SLAVE_ENABLE == STD_ON))
/*******************************************************************************
** Syntax : Std_ReturnType Spi_lIsQueueAvailable                              **
** (                                                                          **
**    uint16 Jobs,                                                            **
**    Spi_JobAndSeqAccessType *JobSeqDataPtr                                  **
** )                                                                          **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant (for different channel Ids)                        **
**                                                                            **
** Parameters (in) :   uint16 Jobs                                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    :                                                          **
**                                                                            **
**                                                                            **
** Description :  This will increment the queue index and wrap around when    **
**                Queue length reached(if the jobs already in the Queue       **
                  finished).                                                  **
*******************************************************************************/
Std_ReturnType Spi_lIsQueueAvailable
(
  uint16 Jobs, const Spi_JobAndSeqAccessType *JobSeqDataPtr
)
{
  uint16 StartIndex;
  uint16 EndIndex;
  uint16 Slots;
  Std_ReturnType ReturnValue;
  /*Fix for AI00253040 */
  StartIndex = JobSeqDataPtr->StartIndexExtractJobId;
  EndIndex = JobSeqDataPtr->EndIndex;

  if (StartIndex == EndIndex)
  {
    Slots = SPI_MAX_JOB_TRIG_Q_LENGTH;
  }
  else if (StartIndex < EndIndex)
  {
    Slots = (SPI_MAX_JOB_TRIG_Q_LENGTH - EndIndex) + (StartIndex - 1U);
  }
  else
  {
    Slots = StartIndex - EndIndex;
    Slots = Slots - 1U;
  }

  if (Slots >= Jobs)
  {
    ReturnValue = E_OK;
  }
  else
  {
    ReturnValue = E_NOT_OK;
  }
  return ReturnValue;
}
/*******************************************************************************
** Syntax           : void Spi_lHwDisableQspiErrIntr(uint32 Module)           **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Disable Spi Hw error    Interrupt           **
*******************************************************************************/
void Spi_lHwDisableQspiErrIntr(uint32 Module)
{

 if(((uint32)((uint32)\
       SPI_IRQ_SFR_RUNTIME_USER_MODE_READ32(MODULE_SRC.QSPI.QSPI[Module].ERR.U)\
                & SPI_SRC_QSPI_ERR_SRE_CLEARMASK)>>IFX_SRC_SRCR_SRE_OFF)  == 1U)
  {
    /* Set SRC.IOVCLR, SRC.SWSCLR, SRC.CLRR */
    /* Clear SRC.SRE */
    /*Reserve bit access is ensured for SRC_QSPImERR register*/
    SPI_IRQ_SFR_RUNTIME_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].ERR.U,\
                            SPI_SRC_QSPI_ERR_CLEARMASK,SPI_SRC_QSPI_ERR_SETMASK)
  }
}
#endif
  /*((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U) || \
        (SPI_SLAVE_ENABLE == STD_ON))*/

/*******************************************************************************
** Syntax : IFX_LOCAL_INLINE void Spi_lMainFunctionErrorCheck (               **
**                                            uint32 ErrorStatus,             **
**                                            uint32 Module,                  **
**                                            Dma_ChannelType DmaTxChannel,   **
**                                            Dma_ChannelType DmaRxChannel )  **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non-Re-entrant                                                **
**                                                                            **
** Parameters (in) : ErrorStatus : Error status                               **
**                   Module : Hw module no.                                   **
**                   DmaTxChannel : Dma channel no used for QSPI transmit.    **
**                   DmaRxChannel : Dma channel no used for QSPI receive.     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : Enables the CS Pin according to the Polarity Requested.      **
**                                                                            **
*******************************************************************************/
#if (((SPI_LEVEL_DELIVERED == 1U) && \
(SPI_ASYNC_MODE_LEVEL1 == SPI_ASYNC_MODE_POLLING)) || \
(SPI_LEVEL_DELIVERED == 2U))
#if((SPI_QM_ASYNC_MASTER_MODULES_USED != 0U))
/* Function to check the DMA or SPI receive error during Spi_Mainfunction call*/
IFX_LOCAL_INLINE void Spi_lMainFunctionErrorCheck
(
  uint32 ErrorStatus,
  uint32 Module,
  Dma_ChannelType DmaTxChannel,
  Dma_ChannelType DmaRxChannel
)
{
  volatile Ifx_QSPI* ModulePtr;
  Spi_JobAndSeqAccessType  *JobSeqDataPtr;
  Spi_ChnlAccessType       *ChnlAccDataPtr;
  uint32 DemError;
  uint32 RxIntStatus = 0U;
  uint32 TxIntStatus = 0U;
  const Spi_JobConfigType* JobConfigPtr;
  uint16 SICompletedJob;
  uint16 JobId;
  uint8 IsLastChannel;
  Spi_ChannelType ChannelId;

  IsLastChannel = 0U;

  #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
  JobSeqDataPtr  = &Spi_QmJobAndSeqAccess;
  #else
  JobSeqDataPtr = &Spi_QmJobAndSeqAccess[Spi_lGetQmModuleVarIndex(Module)];
  #endif
  ChnlAccDataPtr = &Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)];

  if (SPI_BUSY == Spi_lGetModAsyncBusStatus((uint8)Module))
  {
    /* if QSPIx Receive error */
    /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used to
      efficiently access the SFRs of multiple QSPI Modules.*/
    if (Spi_lHwCheckRxStatus(&(SPI_HW_MODULE[Module]), SPI_RUNTIME_ACCESS))
    {
      /* Report Production errors to DEM */
      DemError = (uint32)SPI_DEM_HW_ERROR;
      Spi_lErrorHandler(Module, DemError, SPI_RUNTIME_ACCESS);
    }
    else if (ErrorStatus != 0U) /* DMA Error */
    {
      /* Clear Dma Error Flags */
      SPI_SFR_RUNTIME_MCAL_DMACLRERRFLAGS(DmaRxChannel);
      SPI_SFR_RUNTIME_MCAL_DMACLRERRFLAGS(DmaTxChannel);
      /* Report Production errors to DEM */
      DemError = (uint32)SPI_DEM_DMA_TRANSFER_ERROR;
      Spi_lErrorHandler(Module, DemError, SPI_RUNTIME_ACCESS);
    }
    /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used to
      efficiently access the SFRs of multiple QSPI Modules.*/
    else if (((uint32)((uint32)SPI_SFR_RUNTIME_USER_MODE_READ32\
           (SPI_HW_MODULE[Module].STATUS.U) & SPI_STATUS_TXFIFOLEVEL_CLEARMASK)\
                                         >>SPI_STATUS_TXFIFOLEVEL_BITPOS) == 0U)
    {  /* No Error/s */
      /* The Tx fifo level is not zero which means previous transmission is
         still in progress. So, further process will be in next cycle */

      SICompletedJob = Spi_lCompletedJobId(JobSeqDataPtr);
      /* last job completed */
      /* extract the completed Job Id */
      JobId = JobSeqDataPtr->JobQueue[SICompletedJob];

      /*IFX_MISRA_RULE_17_04_STATUS="SpiJobConfigPtr" Pointer arithmetic used
        due to PBConfigStructure and is within allowed range.*/
      JobConfigPtr = &(Spi_kConfigPtr->SpiJobConfigPtr[JobId]);
      /*IFX_MISRA_RULE_17_04_STATUS="CurrentChannelIndex" Pointer arithmetic
        used due to PBConfigStructure and is within allowed range.*/
      ChannelId =
        JobConfigPtr->ChannelLinkPtr[ChnlAccDataPtr->CurrentChannelIndex + 1U];

      if (ChannelId == SPI_CHANNEL_LINK_DELIMITER)
      {
          IsLastChannel = 1U;
      }
      TxIntStatus = (uint32)SPI_SFR_RUNTIME_MCAL_DMAGETTRANSFERINTSTATUS\
                                                                (DmaTxChannel);
      RxIntStatus = (uint32)SPI_SFR_RUNTIME_MCAL_DMAGETTRANSFERINTSTATUS\
                                                                (DmaRxChannel);

      if (IsLastChannel == 0U)
      {
        if (TxIntStatus)
        {
          /* Clear/Reset Channel Interrupt control register */
          SPI_SFR_RUNTIME_MCAL_DMACHCLRINTRFLAGS(DmaTxChannel);
          /* Clear/Reset Channel Interrupt control register */
          SPI_SFR_RUNTIME_MCAL_DMACHCLRINTCTETRLFLAGS(DmaTxChannel);
        }
        if (RxIntStatus)
        {
          /* Clear/Reset Channel Interrupt control register */
          SPI_SFR_RUNTIME_MCAL_DMACHCLRINTRFLAGS(DmaRxChannel);
          Spi_lBusHandler(Module, SPI_RUNTIME_ACCESS);
        }
      }
      else /* Last Channel */
      {
        if (RxIntStatus)
        {
          /* Clear/Reset Channel Interrupt control register */
          SPI_SFR_RUNTIME_MCAL_DMACHCLRINTRFLAGS(DmaRxChannel);
          Spi_lBusHandler(Module, SPI_RUNTIME_ACCESS);
        }
        else if (TxIntStatus)
        {

          if(JobConfigPtr->ChannelBasedChipSelect == 0U)
          {
    /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used to
        efficiently access the SFRs of multiple QSPI Modules.*/
             ModulePtr =  &(SPI_HW_MODULE[Module]);
             if(((uint32)((uint32)SPI_SFR_RUNTIME_USER_MODE_READ32\
                                                      (ModulePtr->STATUS.U) & \
                      SPI_STATUS_USRF_CLEARMASK)>>SPI_STATUS_USRF_BITPOS) == 1U)
             {
               /* Transfer Count > 1 */
               Spi_IsrDmaQspiTxRuntime(Module);
             }
          }
          else
          {
             /* If SpiChannelBasedCS is ON, then no need
                to manual transfer of last byte  */

             /* Clear/Reset Channel Interrupt control register */
             SPI_SFR_RUNTIME_MCAL_DMACHCLRINTRFLAGS(DmaTxChannel);

             /* DISABLE TX-DMA intr */
             SPI_SFR_RUNTIME_MCAL_DMADISABLEINTR(DmaTxChannel);

             /* Clear/Reset Channel Interrupt control register */
            SPI_SFR_RUNTIME_MCAL_DMACHCLRINTCTETRLFLAGS(DmaTxChannel);
          }
        }
        else
        {
          /*Do Nothing */
        }
      } /* if (!IsLastChannel) */
    }
    else
    {
      /*Do Nothing */
    }/*if(  Spi_lHwCheckRxStatus() ) */
  }/*(Spi_AsyncBusStatus != SPI_BUS_IDLE)*/
}
#endif
#endif

/*(((SPI_LEVEL_DELIVERED == 1U) && \
(SPI_ASYNC_MODE_LEVEL1 == SPI_ASYNC_MODE_POLLING)) ||
(SPI_LEVEL_DELIVERED == 2U))*/

/*******************************************************************************
** Syntax : IFX_LOCAL_INLINE void Spi_lClearChannelWriteLock(void)            **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : None.                                                    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : clear the status variable ChannelWriteLock.                  **
**                                                                            **
*******************************************************************************/
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0U) || (SPI_CHANNEL_BUFFERS_ALLOWED == 2U))
IFX_LOCAL_INLINE void Spi_lClearChannelWriteLock(void)
{
  uint32 IndexValue;
  IndexValue = 0U;
#if (SPI_WRITELOCK_INDEX > 1U)
  do
  {
#endif
    /* Clear the Status Variable */
    Spi_IBBufferAccess.ChannelWriteLock[IndexValue] = 0U;
#if (SPI_WRITELOCK_INDEX > 1U)
    IndexValue++;
  }while (IndexValue < SPI_WRITELOCK_INDEX);
#endif
}
#endif
/*((SPI_CHANNEL_BUFFERS_ALLOWED == 0)||(SPI_CHANNEL_BUFFERS_ALLOWED == 2U))*/

/*******************************************************************************
** Syntax : IFX_LOCAL_INLINE void Spi_lClearJobResultStatus(void)             **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : None.                                                    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : Function to Set Job Result status to SPI_JOB_OK.             **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lClearJobResultStatus(void)
{
  #if (SPI_SAFETY_ENABLE == STD_ON)
  uint16 IndexAsil;
  #endif

  #if (SPI_QM_MASTER_MODULES_USED != 0U)
  uint16 IndexQm;
  #endif

  #if (SPI_SAFETY_ENABLE == STD_ON)
      IndexAsil = 0U;
    #if (SPI_JOB_ASIL_ARRAY_INDEX > 1U)
      do
      {
    #endif
        /*Set Job Result status to SPI_JOB_OK */
        Spi_AsilJobResult[IndexAsil] = 0U;
    #if (SPI_JOB_ASIL_ARRAY_INDEX > 1U)
        IndexAsil++;
      }while (IndexAsil < SPI_JOB_ASIL_ARRAY_INDEX);
    #endif
  #endif

  #if (SPI_QM_MASTER_MODULES_USED != 0U)
      IndexQm = 0U;
  #if (SPI_JOB_QM_ARRAY_INDEX > 1U)
    do
    {
  #endif
      Spi_QmJobResult[IndexQm] = 0U; /* Set Job Result status to SPI_JOB_OK */
  #if (SPI_JOB_QM_ARRAY_INDEX > 1U)
      IndexQm++;
    }while (IndexQm < SPI_JOB_QM_ARRAY_INDEX);
  #endif
  #endif
}

/*******************************************************************************
** Syntax : IFX_LOCAL_INLINE void Spi_lClearSequenceStatus(void)              **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : None.                                                    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : Function to Set Job Result status to SPI_SEQ_OK.             **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lClearSequenceStatus(void)
{
  #if (SPI_SAFETY_ENABLE == STD_ON)
  uint32 IndexValueAsil;
  #endif

  #if (SPI_QM_MASTER_MODULES_USED != 0U)
  uint32 IndexValueQm;
  #endif
 
  #if (SPI_SAFETY_ENABLE == STD_ON)
       IndexValueAsil = 0U;
  #if (SPI_SEQUENCE_ASIL_ARRAY_INDEX > 1U)
    do
    {
  #endif
      /* Set Sequence Status SPI_SEQ_OK */
      Spi_AsilSeqStatus[IndexValueAsil].AsilSeqStatus = 0U;
      #if ((SPI_CANCEL_API == STD_ON) && (SPI_LEVEL_DELIVERED != 0U))
      /* Clear the Status Variable */
      Spi_AsilSeqStatus[IndexValueAsil].AsilSeqCancelStatus = 0U;
      #endif
      /* ((SPI_CANCEL_API == STD_ON) && (SPI_LEVEL_DELIVERED != 0)) */
  #if (SPI_SEQUENCE_ASIL_ARRAY_INDEX > 1U)
      IndexValueAsil++;
    }while (IndexValueAsil < SPI_SEQUENCE_ASIL_ARRAY_INDEX);
  #endif
  #endif
  /* (SPI_SAFETY_ENABLE == STD_ON)  */

  #if (SPI_QM_MASTER_MODULES_USED != 0U)
      IndexValueQm = 0U;
  #if (SPI_SEQUENCE_QM_ARRAY_INDEX > 1U)
    do
    {
  #endif
      /* Set Sequence Status SPI_SEQ_OK */
      Spi_QmSeqStatus[IndexValueQm].QmSeqStatus = 0U;
      #if ((SPI_CANCEL_API == STD_ON) && (SPI_LEVEL_DELIVERED != 0U))
      /* Clear the Status Variable */
      Spi_QmSeqStatus[IndexValueQm].QmSeqCancelStatus = 0U;
      #endif
      /* ((SPI_CANCEL_API == STD_ON) && (SPI_LEVEL_DELIVERED != 0)) */
  #if (SPI_SEQUENCE_QM_ARRAY_INDEX > 1U)
      IndexValueQm++;
    }while (IndexValueQm < SPI_SEQUENCE_QM_ARRAY_INDEX);
  #endif
  #endif

}

/*******************************************************************************
** Syntax : static uint8 Spi_lSeqSharingJobStatus                             **
** (                                                                          **
**   Spi_SequenceConfigType* SeqConfigPtr                                     **
** )                                                                          **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : SeqConfigPtr - sequence configuration                    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : return 1: jobs are shared across sequences               **
**                                                                            **
**                                                                            **
** Description : returns value 1, on finding the jobs shared by the sequences **
*******************************************************************************/
#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
static uint8 Spi_lSeqSharingJobStatus
(
  const Spi_SequenceConfigType* SeqConfigPtr
)
{

  uint32 Index;
  Spi_SequenceType SeqId;
  uint8 JobSharingStatus;

  Index = 0U;
  JobSharingStatus = 0U;
  if (SeqConfigPtr->SeqSharingJobs != NULL_PTR)
  {
    do
    {
     /*IFX_MISRA_RULE_17_04_STATUS="SeqSharingJobs" Pointer arithmetic used due
        to PBConfigStructure and is within allowed range.*/
      SeqId = (Spi_SequenceType)SeqConfigPtr->SeqSharingJobs[Index];
      if (SPI_SEQ_PENDING == Spi_lGetSeqStatus(SeqId))
      {
        JobSharingStatus = 1U;
      }
      Index++;
    /*IFX_MISRA_RULE_17_04_STATUS="SeqSharingJobs" Pointer arithmetic used due
      to PBConfigStructure and is within allowed range.*/
    }while ((SeqConfigPtr->SeqSharingJobs[Index] != \
                   SPI_SHARED_JOBS_DELIMITER) && (JobSharingStatus == 0U));
  }/*(ParamSeqConfigPtr->SeqSharingJobs != NULL_PTR)*/
  return JobSharingStatus;
}
#endif
 /* (SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U) */

#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 0U)||(SPI_CHANNEL_BUFFERS_ALLOWED == 2U))
/*******************************************************************************
** Syntax : IFX_LOCAL_INLINE  void Spi_lIBCopy16BitData                       **
** (                                                                          **
**   uint16* BufferDataPtr16,                                                 **
**   const Spi_DataType *DataBufferPtr,                                       **
**   uint32 IBEndIndex,
**   Spi_ChannelType Channel                                                  **
** )                                                                          **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : BufferDataPtr16 - Destination buffer pointer             **
**                   DataBufferPtr - Source pointer                           **
**                   IBEndIndex - No of buffers                               **
**                   Channel - Channel id                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
**                                                                            **
** Description : Copies the 16bit data to the internal buffer                 **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lIBCopy16BitData
(
  uint16* BufferDataPtr16,
  const Spi_DataType *DataBufferPtr,
  uint32 IBEndIndex,
  Spi_ChannelType Channel
)
{
  const Spi_ChannelConfigType* IBChannelConfigPtr;

  /*IFX_MISRA_RULE_17_04_STATUS="SpiChannelConfigPtr" Pointer arithmetic used
    due to PBConfigStructure and is within allowed range.*/
  IBChannelConfigPtr = &(Spi_kConfigPtr->SpiChannelConfigPtr[Channel]);
  if (DataBufferPtr == NULL_PTR)
  {
    do
    {
      *BufferDataPtr16 = (uint16)IBChannelConfigPtr->DefaultData;
      /*IFX_MISRA_RULE_17_04_STATUS="BufferDataPtr16" Pointer arithmetic used
        due to BufferStructure and is within allowed range.*/
      BufferDataPtr16++;
      IBEndIndex = IBEndIndex - (uint32)SPI_16BIT_DATA_ACCESS;
    }while (IBEndIndex > 0U);
  }
  else
  {
    do
    {
      *BufferDataPtr16 = *((const uint16 *)(const void*)DataBufferPtr);
      /*IFX_MISRA_RULE_17_04_STATUS="BufferDataPtr16" Pointer arithmetic used
        due to BufferStructure and is within allowed range.*/
      BufferDataPtr16++;
      /*IFX_MISRA_RULE_17_04_STATUS="DataBufferPtr" Pointer arithmetic used due
        to BufferStructure and is within allowed range.*/
      DataBufferPtr = DataBufferPtr + (Spi_DataType)SPI_16BIT_DATA_ACCESS;
      IBEndIndex = IBEndIndex - SPI_16BIT_DATA_ACCESS;
    }while (IBEndIndex > 0U);
   }
}

/*******************************************************************************
** Syntax : IFX_LOCAL_INLINE  void Spi_lIBCopy8BitData                        **
** (                                                                          **
**   uint8* BufferDataPtr8,                                                   **
**   const Spi_DataType *DataBufferPtr,                                       **
**   uint32 IBEndIndex,                                                       **
**   Spi_ChannelType Channel                                                  **
** )                                                                          **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : BufferDataPtr8 - Destination buffer pointer              **
**                   DataBufferPtr - Source pointer                           **
**                   IBEndIndex - No of buffers                               **
**                   Channel - Channel id                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
**                                                                            **
** Description : Copies the 8bit data to the internal buffer                  **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lIBCopy8BitData
(
  Spi_DataType* BufferDataPtr8,
  const Spi_DataType *DataBufferPtr,
  uint32 IBEndIndex,
  Spi_ChannelType Channel
)
{
  const Spi_ChannelConfigType* IBChannelConfigPtr;

  /*IFX_MISRA_RULE_17_04_STATUS="SpiChannelConfigPtr" Pointer arithmetic used
    due to PBConfigStructure and is within allowed range.*/
  IBChannelConfigPtr = &(Spi_kConfigPtr->SpiChannelConfigPtr[Channel]);
  if (DataBufferPtr == NULL_PTR)
  {
    do
    {
      *BufferDataPtr8 = (Spi_DataType)IBChannelConfigPtr->DefaultData;
      /*IFX_MISRA_RULE_17_04_STATUS="BufferDataPtr8" Pointer arithmetic used due
        to BufferStructure and is within allowed range.*/
      BufferDataPtr8++;
      IBEndIndex--;
    }while (IBEndIndex > 0U);
  }
  else
  {
    do
    {
      *BufferDataPtr8 = *DataBufferPtr;
      /*IFX_MISRA_RULE_17_04_STATUS="DataBufferPtr" Pointer arithmetic used due
        to BufferStructure and is within allowed range.*/
      DataBufferPtr++;
      /*IFX_MISRA_RULE_17_04_STATUS="BufferDataPtr8" Pointer arithmetic used due
        to BufferStructure and is within allowed range.*/
      BufferDataPtr8++;
      IBEndIndex--;
    }while (IBEndIndex > 0U);
  }
}

/*******************************************************************************
** Syntax : IFX_LOCAL_INLINE  void Spi_lIBCopy32BitData                       **
** (                                                                          **
**   uint32* BufferDataPtr32,                                                 **
**   const Spi_DataType *DataBufferPtr,                                       **
**   uint32 IBEndIndex,                                                       **
**   Spi_ChannelType Channel                                                  **
** )                                                                          **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : BufferDataPtr16 - Destination buffer pointer             **
**                   DataBufferPtr - Source pointer                           **
**                   IBEndIndex - No of buffers                               **
**                   Channel - Channel id                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
**                                                                            **
** Description : Copies the 32bit data to the internal buffer                 **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lIBCopy32BitData
(
  uint32* BufferDataPtr32,
  const Spi_DataType *DataBufferPtr,
  uint32 IBEndIndex,
  Spi_ChannelType Channel
)
{
  const Spi_ChannelConfigType* IBChannelConfigPtr;

  /*IFX_MISRA_RULE_17_04_STATUS="SpiChannelConfigPtr" Pointer arithmetic used
    due to PBConfigStructure and is within allowed range.*/
  IBChannelConfigPtr = &(Spi_kConfigPtr->SpiChannelConfigPtr[Channel]);
  if (DataBufferPtr == NULL_PTR)
  {
    do
    {
      *BufferDataPtr32 = (uint32)IBChannelConfigPtr->DefaultData;
      /*IFX_MISRA_RULE_17_04_STATUS="BufferDataPtr32" Pointer arithmetic used
        due to BufferStructure and is within allowed range.*/
      BufferDataPtr32++;
      IBEndIndex = IBEndIndex - (uint32)SPI_32BIT_DATA_ACCESS;
    }while (IBEndIndex > 0U);
  }
  else
  {
    do
    {
      *BufferDataPtr32 = *((const uint32 *)(const void*)DataBufferPtr);
      /*IFX_MISRA_RULE_17_04_STATUS="BufferDataPtr32" Pointer arithmetic used
        due to BufferStructure and is within allowed range.*/
      BufferDataPtr32++;
      /*IFX_MISRA_RULE_17_04_STATUS="DataBufferPtr" Pointer arithmetic used due
        to BufferStructure and is within allowed range.*/
      DataBufferPtr = DataBufferPtr + (Spi_DataType)SPI_32BIT_DATA_ACCESS;
      IBEndIndex = IBEndIndex - SPI_32BIT_DATA_ACCESS;
    }while (IBEndIndex > 0U);
   }
}

#endif
/*(SPI_CHANNEL_BUFFERS_ALLOWED == 0)||(SPI_CHANNEL_BUFFERS_ALLOWED == 2U)) */

/*******************************************************************************
** Syntax : IFX_LOCAL_INLINE uint8 Spi_lCheckDmaAddress                       **
** (                                                                          **
**   Spi_DataType* DestAddrPtr,                                               **
**   const Spi_DataType* SrcAddrPtr,                                          **
**   Spi_NumberOfDataType Length                                              **
** )                                                                          **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : SeqConfigPtr - sequence configuration                    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : return 1: jobs are shared across sequences               **
**                                                                            **
**                                                                            **
** Description : Checks for the correctness of DMA address and returns        **
**                       error flag on address overflow                       **
*******************************************************************************/
#if (SPI_DEV_ERROR_DETECT == STD_ON)
#if (SPI_DMA_ADDR_SIZE_ALIGN_CHECK == STD_ON)
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 1U) || (SPI_CHANNEL_BUFFERS_ALLOWED == 2U))
/*DMA Address range checking*/
IFX_LOCAL_INLINE uint8 Spi_lCheckDmaAddress
(
  Spi_DataType* DestAddrPtr,
  const Spi_DataType* SrcAddrPtr,
  Spi_NumberOfDataType Length
)
{
  uint8 ErrFlag;
  const Spi_DataType* DMAAddress;

  ErrFlag = 0U; /* Initialize error flag */
  if (DestAddrPtr == NULL_PTR)        /* Read Mode */
  {
    DMAAddress = SrcAddrPtr;
  }
  else if (SrcAddrPtr == NULL_PTR)    /*  Write Mode  */
  {
    DMAAddress = DestAddrPtr;
  }
  else
  {
    /*IFX_MISRA_RULE_11_01_STATUS=Typecasting DestAddrPtr to uint32 is
      unvoidable. DMAAddress is later used for SFR assignment.*/
    /*IFX_MISRA_RULE_11_01_STATUS=Typecasting SrcAddrPtr to uint32 is
      unvoidable. DMAAddress is later used for SFR assignment.*/
    /*IFX_MISRA_RULE_11_03_STATUS=Type cast to uint32 is unavoidable*/
    /*IFX_MISRA_RULE_11_03_STATUS=Type cast to uint32 is unavoidable*/
    DMAAddress = (((uint32)DestAddrPtr & SPI_DMA_ADDRESS_MASK) > \
      ((uint32)SrcAddrPtr & SPI_DMA_ADDRESS_MASK)) ? \
      DestAddrPtr : SrcAddrPtr;
  }
  /*IFX_MISRA_RULE_11_01_STATUS=Typecasting DMAAddress to uint32 is unvoidable.
    DMAAddress is later used for SFR assignment.*/
  /*IFX_MISRA_RULE_11_01_STATUS=Typecasting DMAAddress to Spi_DataType* is
    unvoidable. DMAAddress is later used for SFR assignment.*/
  /*IFX_MISRA_RULE_11_03_STATUS=Type cast to Spi_DataType* is unavoidable*/
  /*IFX_MISRA_RULE_11_03_STATUS=Type cast to uint32 is unavoidable*/
  DMAAddress = (Spi_DataType*)(((uint32)DMAAddress & \
                           SPI_DMA_ADDRESS_MASK) + (uint32)Length);

  /*IFX_MISRA_RULE_11_01_STATUS=Typecasting DMAAddress to uint32 is unvoidable.
    DMAAddress is later used for SFR assignment.*/
  /*IFX_MISRA_RULE_11_03_STATUS=Type cast to uint32 is unavoidable*/
  if ((uint32)DMAAddress > SPI_DMA_ADDRESS_OVERFLOW)
  {
    /* Report to DET */
    Det_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        SPI_SID_SETUPEB, SPI_E_DMA_ADR_ALIGN_ERROR );
    ErrFlag = 1U;
  }
  return ErrFlag;
}
#endif
 /*(SPI_CHANNEL_BUFFERS_ALLOWED==1U)||(SPI_CHANNEL_BUFFERS_ALLOWED==2U)*/
#endif
 /* SPI_DMA_ADDR_SIZE_ALIGN_CHECK */
#endif
 /* SPI_DEV_ERROR_DETECT */

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE uint16 Spi_lCompletedJobId(            **
**                       Spi_JobAndSeqAccessType *JobSeqDataPtr)              **
**                                                                            **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : None.                                                   **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : This function returns the id of the completed job       **
*******************************************************************************/
#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
IFX_LOCAL_INLINE uint16 Spi_lCompletedJobId
(
  const Spi_JobAndSeqAccessType *JobSeqDataPtr
)
{
  uint16 CompletedJobId;

  if (JobSeqDataPtr->StartIndexExtractJobId == 0U)
  {
    CompletedJobId = (SPI_MAX_JOB_TRIG_Q_LENGTH - 1U);
  }
  else
  {
    CompletedJobId = (JobSeqDataPtr->StartIndexExtractJobId - 1U);
  }

  return CompletedJobId;
}
#endif
 /* (SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U) */

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Spi_lSeqCancelled(                **
                           Spi_JobAndSeqAccessType *JobSeqDataPtr)            **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : None.                                                   **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to set the status of sequence cancelled to     **
**                    cancel                                                  **
*******************************************************************************/
#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
#if (SPI_CANCEL_API == STD_ON)
IFX_LOCAL_INLINE void Spi_lSeqCancelled(Spi_JobAndSeqAccessType *JobSeqDataPtr)
{
  uint8 Seqbool;
  uint8 NextSeqId;
  uint16 StartIndex;

  /*Fix for AI00254397 */
  SchM_Enter_Spi_Cancel();
  StartIndex = JobSeqDataPtr->StartIndexExtractJobId ;
  Seqbool = 0U;
  while ((StartIndex != JobSeqDataPtr->EndIndex) && (Seqbool == 0U))
  {
    NextSeqId = JobSeqDataPtr->JobLinkedSeq[StartIndex];
    if (Spi_lGetSeqStatus(NextSeqId) == SPI_SEQ_CANCELED)
    {
      Spi_lSetSeqCancelStatus(NextSeqId);
      StartIndex = Spi_lIncrementAndRoundIndex(StartIndex);

    }
    else
    {
      Seqbool = 1U;
    }
  }
  JobSeqDataPtr->StartIndexExtractJobId = StartIndex;
  SchM_Exit_Spi_Cancel();
}
#endif
 /*(SPI_CANCEL_API == STD_ON)*/
#endif
 /* (SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U) */

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Spi_lJobEndNotif                  **
**                    (                                                       **
**                      const Spi_JobConfigType* JobEndNotifPtr               **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : JobEndNotifPtr - Job configuration.                     **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to check job end notification is called        **
*******************************************************************************/
#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
#if (SPI_JOB_END_NOTIF_REQ == STD_ON)
IFX_LOCAL_INLINE void Spi_lJobEndNotif(const Spi_JobConfigType* JobEndNotifPtr)
{
  if (JobEndNotifPtr->JobEndNotification != NULL_PTR)
  {
    /*At the end of a Job transmission if the corresponding
    "End Job Notification" is configured as non null pointer,
    it shall be called.*/
    (JobEndNotifPtr->JobEndNotification)();
  }
}
#endif
#endif
 /* (SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U) */

#if ((SPI_LEVEL_DELIVERED == 0U) || (SPI_LEVEL_DELIVERED == 2U))
#if(SPI_LEVEL2_ASYNC_ONLY == STD_OFF)
/*******************************************************************************
** Traceability : [cover parentID=DS_MCAL_SPI_9009]                           **
** Syntax : IFX_LOCAL_INLINE Std_ReturnType Spi_lSynTransErrCheck(const       **
**                                           Ifx_QSPI* ModulePtr)             **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Std_ReturnType                                           **
**                                                                            **
**                                                                            **
** Description :  Returns E_OK if all the global variable values are          **
**                as initialised else returns E_NOT_OK                        **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE Std_ReturnType Spi_lSynTransErrCheck(const Ifx_QSPI* ModulePtr)
{
  uint32 LoopCounter;
  Std_ReturnType RetVal;
  RetVal = E_OK;
  /* Wait until the data is transmitted /Received. Wait for the receive
        completion event */
  /* Wait for Data Tx */
  LoopCounter = SPI_SYNCTRANSMIT_TIMEOUT_COUNTER;
  while ((Spi_lHwGetTxStatus(ModulePtr) == SPI_TX_IN_PROGRESS)
            && (LoopCounter != 0U) )
  {
    if (Spi_lHwGetErrStatus(ModulePtr) != 0U)
    {
      break;
    }
    LoopCounter--;
  }
  if (LoopCounter != 0U)
  {
    LoopCounter = SPI_SYNCTRANSMIT_TIMEOUT_COUNTER;
  }
  /* Wait for Data Rx */
  while ((((SPI_SFR_RUNTIME_USER_MODE_READ32(ModulePtr->STATUS.U) & \
    SPI_STATUS_RXFIFOLEVEL_CLEARMASK)>>SPI_STATUS_RXFIFOLEVEL_BITPOS) == 0U) &&\
                                                           (LoopCounter != 0U) )
  {
    if (Spi_lHwGetErrStatus(ModulePtr) != 0U)
    {
      break;
    }
    LoopCounter--;
  }
  if ((Spi_lHwGetErrStatus(ModulePtr) != 0U) || (LoopCounter == 0U))
  {
    RetVal = E_NOT_OK;
  }
   return (RetVal);
}  /* end of Spi_lSynTransErrCheck */

/*******************************************************************************
** Syntax : static void Spi_lSyncTransmit16BitData                            **
** (                                                                          **
**   Ifx_QSPI* ModulePtr,                                                     **
**   const uint16* SourceDataPtr16,                                           **
**   uint16* DestinationPtr16,                                                **
**   Spi_SyncTransParamType Spi_SyncTransParams                               **
** )                                                                          **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : ModulePtr - Hw module pointer                            **
**                   SourceDataPtr16 - Data to be transmitted                 **
**                   DestinationPtr16 - received data                         **
**                   Spi_SyncTransParams - Sync Transmit prameters            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : return 1: jobs are shared across sequences               **
**                                                                            **
**                                                                            **
** Description : Function to transmit 16 bit data synchronously               **
*******************************************************************************/
static void Spi_lSyncTransmit16BitData
(
  Ifx_QSPI* ModulePtr,
  const uint16* SourceDataPtr16,
  uint16* DestinationPtr16,
  Spi_SyncTransParamType Spi_SyncTransParams
)
{
  Std_ReturnType RetVal;
  uint32 TransferCount;
  Spi_ChannelType ChannelId;
  uint8 FirstChannel;
  uint8 IsLastChannel;
  uint16 hwpin;
  uint8 Polarity;

  #if (SPI_CHANNEL_BUFFERS_ALLOWED != 0U)
  const Spi_ChannelConfigType* ChannelConfigPtr;
  uint32 DefaultValue;
  volatile uint32 DummyRead;
  #endif

  TransferCount = Spi_SyncTransParams.TransferCount;
  hwpin         = Spi_SyncTransParams.hwpin;
  ChannelId     = Spi_SyncTransParams.ChannelId;
  FirstChannel  = Spi_SyncTransParams.FirstChannel;
  IsLastChannel = Spi_SyncTransParams.IsLastChannel;
  Polarity      = Spi_SyncTransParams.Polarity;

  #if (SPI_CHANNEL_BUFFERS_ALLOWED != 0U)
  /*IFX_MISRA_RULE_17_04_STATUS="SpiChannelConfigPtr" Pointer arithmetic used
    due to PBConfigStructure and is within allowed range.*/
  ChannelConfigPtr = &(Spi_kConfigPtr->SpiChannelConfigPtr[ChannelId]);
  DummyRead    = 0U;
  /*
    Src Ptr is NULL. Configured Default Data is
    transmitted
  */
  DefaultValue = ChannelConfigPtr->DefaultData;
  #else
  UNUSED_PARAMETER(ChannelId)
  #endif
 /*(SPI_CHANNEL_BUFFERS_ALLOWED != 0)*/

  do
  {
    Spi_lClrPendingEvents(ModulePtr);
    /*block interrupts until chip select*/
    SchM_Enter_Spi_SyncTransmit();
    if (FirstChannel == 1U)
    {
      FirstChannel = 0U;
      /* Fix for JIRA: 0000054991-31
       GPIO Chipselect followed by Data transfer does not cause data loss;
       However it induces more delay than the configured lead delays.
       This limitation is mentioned in the User manual.

       If Data is started first followed by GPIO Chipselect the delay could
       be much closer to the configured values however it could cause data loss.
      */
      Spi_lGpioCsHandle(hwpin,Polarity);
    }
    /* If EB Channel type is configured */
    #if (SPI_CHANNEL_BUFFERS_ALLOWED != 0U)
    if (SourceDataPtr16 != NULL_PTR)
    {
      SPI_lHwUpdateSrcRegister(ModulePtr, (uint32)((uint16)*SourceDataPtr16));
      /*IFX_MISRA_RULE_17_04_STATUS="SourceDataPtr16" Pointer arithmetic used
        due to BufferStructure and is within allowed range.*/
      SourceDataPtr16++;
    }
    else
    {
      SPI_lHwUpdateSrcRegister(ModulePtr, (uint32) ((uint16) DefaultValue));
    }
    #else /* Only IB Channel Type  SPI_CHANNEL_BUFFERS_ALLOWED == 0 */
    SPI_lHwUpdateSrcRegister(ModulePtr, (uint32)((uint16)*SourceDataPtr16));
    /*IFX_MISRA_RULE_17_04_STATUS="SourceDataPtr16" Pointer arithmetic used due
      to BufferStructure and is within allowed range.*/
    SourceDataPtr16++;
    #endif
    /*(SPI_CHANNEL_BUFFERS_ALLOWED != 0) */

    SchM_Exit_Spi_SyncTransmit();

    RetVal = Spi_lSynTransErrCheck(ModulePtr);
    if (RetVal != E_OK)
    {
      TransferCount = 0U;
    }
    else
    {
      /* If EB Channel type is configured */
      #if (SPI_CHANNEL_BUFFERS_ALLOWED != 0U)
      /* Dest Ptr is NULL. Read data is ignored */
      if (DestinationPtr16 != NULL_PTR)
      {
        *DestinationPtr16 = (uint16)SPI_lHwReadDestRegister(ModulePtr);
       /*IFX_MISRA_RULE_17_04_STATUS="DestinationPtr16" Pointer arithmetic used
          due to BufferStructure and is within allowed range.*/
        DestinationPtr16++;
      }
      else
      {
        /* Dummy Read to prevent receive error */
        DummyRead = (uint32)SPI_lHwReadDestRegister(ModulePtr);
        UNUSED_PARAMETER(DummyRead)
      }
      #else /* Only IB Channel Type  SPI_CHANNEL_BUFFERS_ALLOWED == 0 */
      *DestinationPtr16 = (uint16)SPI_lHwReadDestRegister(ModulePtr);
      /*IFX_MISRA_RULE_17_04_STATUS="DestinationPtr16" Pointer arithmetic used
        due to BufferStructure and is within allowed range.*/
      DestinationPtr16++;
      #endif

      /* (SPI_CHANNEL_BUFFERS_ALLOWED != 0) */
      /* In 16 bit handling, each transfer is 2 bytes */
      TransferCount = TransferCount - SPI_16BIT_DATA_ACCESS;
      if ((IsLastChannel == 1U) &&
          (TransferCount == SPI_16BIT_DATA_ACCESS))
      {
        /*updated register BACONENTRY*/
        SPI_SFR_RUNTIME_USER_MODE_WRITE32(ModulePtr->BACONENTRY.U,\
                   (SPI_SFR_RUNTIME_USER_MODE_READ32(ModulePtr->BACON.U) | 1U));

      }
    }
  }while (TransferCount > 0U); /* End of Channel buffer length */
}

/*******************************************************************************
** Syntax : static void Spi_lSyncTransmit8BitData                             **
** (                                                                          **
**   Ifx_QSPI* ModulePtr,                                                     **
**   const Spi_DataType* SourceDataPtr8,                                      **
**   Spi_DataType* DestinationPtr8,                                           **
**   Spi_SyncTransParamType Spi_SyncTransParams                               **
** )                                                                          **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : ModulePtr - Hw module pointer                            **
**                   SourceDataPtr8 - Data to be transmitted                  **
**                   DestinationPtr8 - received data                          **
**                   Spi_SyncTransParams - Sync Transmit prameters            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : return 1: jobs are shared across sequences               **
**                                                                            **
**                                                                            **
** Description : Function to transmit 8 bit data synchronously                **
*******************************************************************************/
static void Spi_lSyncTransmit8BitData
(
  Ifx_QSPI* ModulePtr,
  const Spi_DataType* SourceDataPtr8,
  Spi_DataType* DestinationPtr8,
  Spi_SyncTransParamType Spi_SyncTransParams
)
{
  Std_ReturnType RetVal;
  uint32 TransferCount;
  Spi_ChannelType ChannelId;
  uint8 FirstChannel;
  uint8 IsLastChannel;
  uint16 hwpin;
  uint8 Polarity;

  #if (SPI_CHANNEL_BUFFERS_ALLOWED != 0U)
  const Spi_ChannelConfigType* ChannelConfigPtr;
  uint32 DefaultValue;
  volatile uint32 DummyRead;
  #endif

  TransferCount = Spi_SyncTransParams.TransferCount;
  hwpin         = Spi_SyncTransParams.hwpin;
  ChannelId     = Spi_SyncTransParams.ChannelId;
  FirstChannel  = Spi_SyncTransParams.FirstChannel;
  IsLastChannel = Spi_SyncTransParams.IsLastChannel;
  Polarity      = Spi_SyncTransParams.Polarity;

  #if (SPI_CHANNEL_BUFFERS_ALLOWED != 0U)
  /*IFX_MISRA_RULE_17_04_STATUS="SpiChannelConfigPtr" Pointer arithmetic used
    due to PBConfigStructure and is within allowed range.*/
  ChannelConfigPtr = &(Spi_kConfigPtr->SpiChannelConfigPtr[ChannelId]);
  DummyRead    = 0U;

  DefaultValue = (uint8)ChannelConfigPtr->DefaultData;
  #else
  UNUSED_PARAMETER(ChannelId)
  #endif
 /*(SPI_CHANNEL_BUFFERS_ALLOWED != 0)*/

  do
  {
    Spi_lClrPendingEvents(ModulePtr);
    /*block interrupts until chip select*/
    SchM_Enter_Spi_SyncTransmit();
    if (FirstChannel == 1U)
    {
      FirstChannel = 0U;
      /* Fix for JIRA: 0000054991-31
       GPIO Chipselect followed by Data transfer does not cause data loss;
       However it induces more delay than the configured lead delays.
       This limitation is mentioned in the User manual.

       If Data is started first followed by GPIO Chipselect the delay could
       be much closer to the configured values however it could cause data loss.
      */
      Spi_lGpioCsHandle(hwpin,Polarity);
    }
    /* If EB Channel type is configured */
    #if (SPI_CHANNEL_BUFFERS_ALLOWED != 0U)

    if (SourceDataPtr8 != NULL_PTR)
    {
      SPI_lHwUpdateSrcRegister(ModulePtr, (uint32)((uint8)*SourceDataPtr8));
      /*IFX_MISRA_RULE_17_04_STATUS="SourceDataPtr8" Pointer arithmetic used due
        to BufferStructure and is within allowed range.*/
      SourceDataPtr8++;
    }
    else
    {
      SPI_lHwUpdateSrcRegister(ModulePtr, DefaultValue);
    }
    #else /* Only IB Channel Type  SPI_CHANNEL_BUFFERS_ALLOWED == 0 */
    SPI_lHwUpdateSrcRegister(ModulePtr, (uint32)((uint8)*SourceDataPtr8));
    /*IFX_MISRA_RULE_17_04_STATUS="SourceDataPtr8" Pointer arithmetic used due
      to BufferStructure and is within allowed range.*/
    SourceDataPtr8++;
    #endif
    /*(SPI_CHANNEL_BUFFERS_ALLOWED != 0) */

    SchM_Exit_Spi_SyncTransmit();

    RetVal = Spi_lSynTransErrCheck(ModulePtr);
    if (RetVal != E_OK)
    {
      TransferCount = 0U;
    }
    else
    {
      /* If EB Channel type is configured */
      #if (SPI_CHANNEL_BUFFERS_ALLOWED != 0U)
      /* Dest Ptr is NULL. Read data is ignored */
      if (DestinationPtr8 != NULL_PTR)
      {
        *DestinationPtr8 = (Spi_DataType)SPI_lHwReadDestRegister(ModulePtr);
        /*IFX_MISRA_RULE_17_04_STATUS="DestinationPtr8" Pointer arithmetic used
          due to BufferStructure and is within allowed range.*/
        DestinationPtr8++;
      }
      else
      {
        /* Dummy Read to prevent receive error */
        DummyRead = (uint32)SPI_lHwReadDestRegister(ModulePtr);
        UNUSED_PARAMETER(DummyRead)
      }
      #else  /* Only IB Channel Type  SPI_CHANNEL_BUFFERS_ALLOWED == 0 */
      *DestinationPtr8 = (Spi_DataType)SPI_lHwReadDestRegister(ModulePtr);
      /*IFX_MISRA_RULE_17_04_STATUS="DestinationPtr8" Pointer arithmetic used
        due to BufferStructure and is within allowed range.*/
      DestinationPtr8++;
      #endif
      /*(SPI_CHANNEL_BUFFERS_ALLOWED != 0) */
      TransferCount-- ;
      if ((IsLastChannel == 1U) &&
        (TransferCount == 1U))
      {
          /*updated register BACONENTRY*/
        SPI_SFR_RUNTIME_USER_MODE_WRITE32(ModulePtr->BACONENTRY.U,\
             (SPI_SFR_RUNTIME_USER_MODE_READ32(ModulePtr->BACON.U) |1U));
      }
    }
  }while (TransferCount > 0U); /* End of Channel buffer length */
}
/*******************************************************************************
** Syntax : static void Spi_lSyncTransmit32BitData                            **
** (                                                                          **
**   Ifx_QSPI* ModulePtr,                                                     **
**   const uint32* SourceDataPtr32,                                           **
**   uint32* DestinationPtr32,                                                **
**   Spi_SyncTransParamType Spi_SyncTransParams                               **
** )                                                                          **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : ModulePtr - Hw module pointer                            **
**                   SourceDataPtr32 - Data to be transmitted                 **
**                   DestinationPtr32 - received data                         **
**                   Spi_SyncTransParams - Sync Transmit prameters            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : return 1: jobs are shared across sequences               **
**                                                                            **
**                                                                            **
** Description : Function to transmit 32 bit data synchronously               **
*******************************************************************************/
static void Spi_lSyncTransmit32BitData
(
  Ifx_QSPI* ModulePtr,
  const uint32* SourceDataPtr32,
  uint32* DestinationPtr32,
  Spi_SyncTransParamType Spi_SyncTransParams
)
{
  Std_ReturnType RetVal;
  uint32 TransferCount;
  Spi_ChannelType ChannelId;
  uint8 FirstChannel;
  uint8 IsLastChannel;
  uint16 hwpin;
  uint8 Polarity;

  #if (SPI_CHANNEL_BUFFERS_ALLOWED != 0U)
  const Spi_ChannelConfigType* ChannelConfigPtr;
  uint32 DefaultValue;
  volatile uint32 DummyRead;
  #endif

  TransferCount = Spi_SyncTransParams.TransferCount;
  hwpin         = Spi_SyncTransParams.hwpin;
  ChannelId     = Spi_SyncTransParams.ChannelId;
  FirstChannel  = Spi_SyncTransParams.FirstChannel;
  IsLastChannel = Spi_SyncTransParams.IsLastChannel;
  Polarity      = Spi_SyncTransParams.Polarity;

  #if (SPI_CHANNEL_BUFFERS_ALLOWED != 0U)
  /*IFX_MISRA_RULE_17_04_STATUS="SpiChannelConfigPtr" Pointer arithmetic used
    due to PBConfigStructure and is within allowed range.*/
  ChannelConfigPtr = &(Spi_kConfigPtr->SpiChannelConfigPtr[ChannelId]);
  DummyRead    = 0U;
  /*
    Src Ptr is NULL. Configured Default Data is
    transmitted
  */
  DefaultValue = ChannelConfigPtr->DefaultData;
  #else
  UNUSED_PARAMETER(ChannelId)
  #endif
 /*(SPI_CHANNEL_BUFFERS_ALLOWED != 0)*/

  do
  {
    Spi_lClrPendingEvents(ModulePtr);
    /*block interrupts until chip select*/
    SchM_Enter_Spi_SyncTransmit();
    if (FirstChannel == 1U)
    {
      FirstChannel = 0U;
      /* Fix for JIRA: 0000054991-31
       GPIO Chipselect followed by Data transfer does not cause data loss;
       However it induces more delay than the configured lead delays.
       This limitation is mentioned in the User manual.

       If Data is started first followed by GPIO Chipselect the delay could
       be much closer to the configured values however it could cause data loss.
      */
      Spi_lGpioCsHandle(hwpin,Polarity);
    }

    /* If EB Channel type is configured */
    #if (SPI_CHANNEL_BUFFERS_ALLOWED != 0U)
    if (SourceDataPtr32 != NULL_PTR)
    {
      SPI_lHwUpdateSrcRegister(ModulePtr, (*SourceDataPtr32));
      /*IFX_MISRA_RULE_17_04_STATUS="SourceDataPtr32" Pointer arithmetic used
        due to BufferStructure and is within allowed range.*/
      SourceDataPtr32++;
    }
    else
    {
      SPI_lHwUpdateSrcRegister(ModulePtr, DefaultValue);
    }
    #else /* Only IB Channel Type  SPI_CHANNEL_BUFFERS_ALLOWED == 0 */
    SPI_lHwUpdateSrcRegister(ModulePtr,(*SourceDataPtr32));
    /*IFX_MISRA_RULE_17_04_STATUS="SourceDataPtr32" Pointer arithmetic used due
      to BufferStructure and is within allowed range.*/
    SourceDataPtr32++;
    #endif
    /*(SPI_CHANNEL_BUFFERS_ALLOWED != 0) */

    SchM_Exit_Spi_SyncTransmit();

    RetVal = Spi_lSynTransErrCheck(ModulePtr);
    if (RetVal != E_OK)
    {
      TransferCount = 0U;
    }
    else
    {
      /* If EB Channel type is configured */
      #if (SPI_CHANNEL_BUFFERS_ALLOWED != 0U)
      /* Dest Ptr is NULL. Read data is ignored */
      if (DestinationPtr32 != NULL_PTR)
      {
        *DestinationPtr32 = (uint32)SPI_lHwReadDestRegister(ModulePtr);
       /*IFX_MISRA_RULE_17_04_STATUS="DestinationPtr32" Pointer arithmetic used
          due to BufferStructure and is within allowed range.*/
        DestinationPtr32++;
      }
      else
      {
        /* Dummy Read to prevent receive error */
        DummyRead = (uint32)SPI_lHwReadDestRegister(ModulePtr);
        UNUSED_PARAMETER(DummyRead)
      }
      #else /* Only IB Channel Type  SPI_CHANNEL_BUFFERS_ALLOWED == 0 */
      *DestinationPtr32 = SPI_lHwReadDestRegister(ModulePtr);
      /*IFX_MISRA_RULE_17_04_STATUS="DestinationPtr32" Pointer arithmetic used
        due to BufferStructure and is within allowed range.*/
      DestinationPtr32++;
      #endif
      /* (SPI_CHANNEL_BUFFERS_ALLOWED != 0) */
      /* In 32 bit handling, each transfer is 4 bytes */
      TransferCount = TransferCount - SPI_32BIT_DATA_ACCESS;
      if ((IsLastChannel == 1U) &&
        (TransferCount == SPI_32BIT_DATA_ACCESS))
      {
        /*updated register BACONENTRY*/
        SPI_SFR_RUNTIME_USER_MODE_WRITE32(ModulePtr->BACONENTRY.U,\
                   (SPI_SFR_RUNTIME_USER_MODE_READ32(ModulePtr->BACON.U) | 1U));
      }
    }
  }while (TransferCount > 0U); /* End of Channel buffer length */
}
/*******************************************************************************
** Syntax : static void Spi_lGpioCsHandle                                     **
** (                                                                          **
**   uint16 hwpin,                                                            **
**   uint8 Polarity                                                           **
** )                                                                          **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : hwpin - Hardware pin details                             **
**                   Polarity - Polarity                                      **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Function invoked from Spi_lSyncTransmit32BitData/            **
                 Spi_lSyncTransmit16BitData/Spi_lSyncTransmit8BitData         **
                 for GPIO CS handle                                           **
*******************************************************************************/
static void Spi_lGpioCsHandle(uint16 hwpin,uint8 Polarity)
{
    if ((hwpin != SPI_CS_HW) && (hwpin != SPI_CS_NONE))
    {
      Polarity = (Polarity == (uint8)0U) ? (uint8)1U : (uint8)0U;
      Spi_lHwGpioSetPortPin(hwpin, Polarity, SPI_RUNTIME_ACCESS);
    }
}
/*******************************************************************************
** Syntax : static void Spi_lClrPendingEvents                                 **
** (                                                                          **
**   Ifx_QSPI* ModulePtr                                                      **
** )                                                                          **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : ModulePtr - Hw module pointer                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Function invoked from Spi_lSyncTransmit32BitData/            **
                 Spi_lSyncTransmit16BitData/Spi_lSyncTransmit8BitData         **
                 for clearing pending events                                  **
*******************************************************************************/
static void Spi_lClrPendingEvents(Ifx_QSPI* ModulePtr)
{
  /* Clear any pending receive event */
  if (Spi_lHwGetRxStatus(ModulePtr) == SPI_RX_IN_PROGRESS)
  {
    /*updated register FLAGSCLEAR.Reserve bit access
    is ensured for FLAGSCLEAR register*/
    SPI_SFR_RUNTIME_USER_MODE_WRITE32(ModulePtr->FLAGSCLEAR.U,\
             (SPI_QSPI_RXC_FLAGSCLEAR_VALUE | SPI_QSPI_ERR_FLAGSCLEAR_VALUE));
  }
  if (Spi_lHwGetTxStatus(ModulePtr) == SPI_TX_IN_PROGRESS)
  {
    /*updated register FLAGSCLEAR.Reserve bit access
    is ensured for FLAGSCLEAR register*/
    SPI_SFR_RUNTIME_USER_MODE_WRITE32(ModulePtr->FLAGSCLEAR.U,\
             (SPI_QSPI_TXC_FLAGSCLEAR_VALUE | SPI_QSPI_ERR_FLAGSCLEAR_VALUE));
  }
}
/*******************************************************************************
** Syntax : void Spi_lSyncTransmit(Spi_SequenceType Sequence)                 **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Sequence - Sequnece ID.                                  **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None.                                                    **
**                   E_NOT_OK - Transmission command has been accepted.       **
**                                                                            **
** Description :  Local function to process Sync transmit.                    **
**                                                                            **
*******************************************************************************/
static void Spi_lSyncTransmit(Spi_SequenceType Sequence)
{
  const Spi_SequenceConfigType* SeqConfigPtr;
  Spi_JobType JobId;
  uint32 JobIndex;
  #if (SPI_CANCEL_API == STD_ON)
  uint8 SeqIdCancelled;
  #endif
  /* (SPI_CANCEL_API == STD_ON) */

      Spi_BusStatus = SPI_BUSY;

      /* Get the pointer to the Sequence configuration */
      /*IFX_MISRA_RULE_17_04_STATUS="SpiSequenceConfigPtr" Pointer arithmetic
        used due to PBConfigStructure and is within allowed range.*/
      SeqConfigPtr = &(Spi_kConfigPtr->SpiSequenceConfigPtr[Sequence]);
      /* Set Sequence Status to Pending */
      Spi_lSetSeqStatusAtomic(Sequence, SPI_SEQ_PENDING);

      /* Initialize Job Index to the first Job */
      JobIndex = 0U;
      /* Get the Job Id of the first Job from sequence link,
         Job Id corresponds to the array index of struct: Spi_JobConfig */
      /*IFX_MISRA_RULE_17_04_STATUS="JobLinkPtr" Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      JobId = SeqConfigPtr->JobLinkPtr[JobIndex];
      do
      {
        /* Start Job Transmission */
        Spi_lSyncStartJob(JobId);
        /* Check for Job Failure due to production error */
        if (Spi_lGetJobStatus(JobId) == SPI_JOB_FAILED)
        {
          /* Set Sequence to failed status */
          Spi_lSetSeqStatusAtomic(Sequence, SPI_SEQ_FAILED);
          /* Set Job to Last Job Id to exit loop*/
          JobId = SPI_JOB_LINK_DELIMITER;
        }
        else
        {
          /* Set Job Status to OK */
          Spi_lSetJobStatusAtomic(JobId, SPI_JOB_OK);
          /* Get next Job index */
          JobIndex++;
          /* Get  Job from the Sequence Link */
         /*IFX_MISRA_RULE_17_04_STATUS="JobLinkPtr" Pointer arithmetic used due
            to PBConfigStructure and is within allowed range.*/
          JobId = SeqConfigPtr->JobLinkPtr[JobIndex];
        }
        #if (SPI_CANCEL_API == STD_ON)
        SeqIdCancelled = (uint8)Spi_lGetSeqStatus(Sequence);
        /* Set all QUEUED Jobs status to OK */
        if (SPI_SEQ_CANCELED == (Spi_SeqResultType)SeqIdCancelled)
        {
          while (JobId != SPI_JOB_LINK_DELIMITER)
          {
            Spi_lSetJobStatusAtomic(JobId, SPI_JOB_OK );
            JobIndex++;
            /* Get  Job from the Sequence Link */
            /*IFX_MISRA_RULE_17_04_STATUS="JobLinkPtr" Pointer arithmetic used
              due to PBConfigStructure and is within allowed range.*/
            JobId = SeqConfigPtr->JobLinkPtr[JobIndex];
          }
        }
        #endif
        /* (SPI_CANCEL_API == STD_ON) */
      } while(JobId != SPI_JOB_LINK_DELIMITER); /*The last job is not reached*/

      /* Check if the Sequence is still in pending state:
         i.e Not failed/cancelled */
      if (Spi_lGetSeqStatus(Sequence) == SPI_SEQ_PENDING)
      {
        Spi_lSetSeqStatusAtomic(Sequence, SPI_SEQ_OK);
      }

}
#endif /* SPI_LEVEL2_ASYNC_ONLY == STD_OFF */
#endif
/*((SPI_LEVEL_DELIVERED == 0U) || (SPI_LEVEL_DELIVERED == 2U))*/

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE Std_ReturnType Spi_lGetDetInitStatus(  **
**                                                             uint8 ApiId)   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : ApiId: API ID                                           **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : return the status of DET check for Init.                **
**                                                                            **
** Description      : Function to check Init function called or not           **
*******************************************************************************/
#if (SPI_DEV_ERROR_DETECT == STD_ON)
IFX_LOCAL_INLINE Std_ReturnType Spi_lGetDetInitStatus(uint8 ApiId)
{
  Std_ReturnType ReturnStatus;
  ReturnStatus = E_OK;

  #if (SPI_PB_FIXEDADDR == STD_OFF)
  if (Spi_kConfigPtr == NULL_PTR)
  {
    /* Report to DET */
    Det_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        ApiId, SPI_E_UNINIT );
    ReturnStatus = E_NOT_OK;
  }
  #endif
 /*(SPI_PB_FIXEDADDR == STD_OFF)*/

  #if (SPI_PB_FIXEDADDR == STD_ON)
  if (Spi_InitStatus == SPI_DRIVER_DEINITIALIZED)
  {
    /* Report to DET */
    Det_ReportError( SPI_MODULE_ID, SPI_INSTANCE_ID,
        ApiId, SPI_E_UNINIT );
    ReturnStatus = E_NOT_OK;
  }
  #endif
 /*(SPI_PB_FIXEDADDR == STD_OFF)*/

  return ReturnStatus;
}
#endif
 /* (SPI_DEV_ERROR_DETECT == STD_ON) */

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE uint8 Spi_lGetSeqStatusInArray         **
**                       (uint32 SeqArrayVal)                                 **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : SeqArrayVal: Variable packed with 16 sequence status    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : return the status whether any seq is pending.           **
**                                                                            **
** Description      : Function to check if any seq is pending in the          **
**                    given 16 sequences                                      **
*******************************************************************************/
IFX_LOCAL_INLINE uint8 Spi_lGetSeqStatusInArray(uint32 SeqArrayVal)
{
  uint8 RetVal = 0U;
  if(
       ((SeqArrayVal & SPI_SEQ0MASK) == SPI_SEQ0PENDING) ||
       ((SeqArrayVal & SPI_SEQ1MASK) == SPI_SEQ1PENDING) ||
       ((SeqArrayVal & SPI_SEQ2MASK) == SPI_SEQ2PENDING) ||
       ((SeqArrayVal & SPI_SEQ3MASK) == SPI_SEQ3PENDING) ||
       ((SeqArrayVal & SPI_SEQ4MASK) == SPI_SEQ4PENDING) ||
       ((SeqArrayVal & SPI_SEQ5MASK) == SPI_SEQ5PENDING) ||
       ((SeqArrayVal & SPI_SEQ6MASK) == SPI_SEQ6PENDING) ||
       ((SeqArrayVal & SPI_SEQ7MASK) == SPI_SEQ7PENDING) ||
       ((SeqArrayVal & SPI_SEQ8MASK) == SPI_SEQ8PENDING) ||
       ((SeqArrayVal & SPI_SEQ9MASK) == SPI_SEQ9PENDING) ||
       ((SeqArrayVal & SPI_SEQ10MASK) == SPI_SEQ10PENDING) ||
       ((SeqArrayVal & SPI_SEQ11MASK) == SPI_SEQ11PENDING) ||
       ((SeqArrayVal & SPI_SEQ12MASK) == SPI_SEQ12PENDING) ||
       ((SeqArrayVal & SPI_SEQ13MASK) == SPI_SEQ13PENDING) ||
       ((SeqArrayVal & SPI_SEQ14MASK) == SPI_SEQ14PENDING) ||
       ((SeqArrayVal & SPI_SEQ15MASK) == SPI_SEQ15PENDING)
     )
     {
        RetVal = 1U;
     }
  return RetVal;
}

/*******************************************************************************
**                            Spi Hw Apis                                     **
*******************************************************************************/
#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI013]
** Syntax           : static void Spi_lHwInit                                 **
**                    (                                                       **
**                      const Spi_ConfigType* ConfigPtr                       **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : ConfigPtr - Pointer to configuration set.               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to initialise the QSPI Hw (Level 1 & 2)        **
*******************************************************************************/
static Std_ReturnType Spi_lHwInit(const Spi_ConfigType* ConfigPtr)
{
  volatile uint32 ReadBack;
  uint32 ModLoopCtr;
  const Spi_HWModuleConfigType* HWModuleConfigPtr;
  Std_ReturnType RetVal = E_OK;

  #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
  #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_ON)
  uint32 QmModIndex;
  #endif
  #endif

/*  ------------------------------------------------------------------ **
**                 Spi Hw Module Initialization                        **
**  ------------------------------------------------------------------ */

  #if (SPI_SAFETY_ENABLE == STD_ON)
   Spi_AsilJobAndSeqAccess.StartIndexExtractJobId = 0U;
   Spi_AsilJobAndSeqAccess.EndIndex = 0U;
  #endif

  #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
  #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
  Spi_QmJobAndSeqAccess.StartIndexExtractJobId = 0U;
  Spi_QmJobAndSeqAccess.EndIndex = 0U;
  #else
  QmModIndex = 0U;
  #if(SPI_NUM_QM_ASYNC_MASTERS > 1U)
  do
  {
  #endif
    Spi_QmJobAndSeqAccess[QmModIndex].StartIndexExtractJobId = 0U;
    Spi_QmJobAndSeqAccess[QmModIndex].EndIndex = 0U;
  #if(SPI_NUM_QM_ASYNC_MASTERS > 1U)
    QmModIndex++;
  }while(QmModIndex < SPI_NUM_QM_ASYNC_MASTERS);
  #endif

  #endif
  #endif

  /* Enter Critical Section */
  SchM_Enter_Spi_Init();



  ModLoopCtr = 0U;
  do
  {
    if(Spi_lModuleConfigured((uint8)ModLoopCtr) != 0U)
    {
      /* Get QSPIx Configuration Pointer */
      HWModuleConfigPtr = (ConfigPtr->HWModuleConfigPtr[ModLoopCtr]);

      /* Reset End Init Protection to access regsiters */
      SPI_SFR_INIT_RESETENDINIT();

      /* SPI QSPIx Module Initialisation within end init protection */
      /* Initialize CLC Register - Enable QSPI Module, Set Sleep Settings */
      /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
        to efficiently access the SFRs of multiple QSPI Modules.*/
      SPI_SFR_INIT_WRITE32(SPI_HW_MODULE[ModLoopCtr].CLC.U,\
                                              HWModuleConfigPtr->HWClkSetting);

      /* Set End Init Protection */
      SPI_SFR_INIT_SETENDINIT();
      /* Fix for CPU Bug CPU_TC.H002 */
      /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
        to efficiently access the SFRs of multiple QSPI Modules.*/
      ReadBack = (uint32)(((uint32)SPI_SFR_INIT_USER_MODE_READ32\
                   (SPI_HW_MODULE[ModLoopCtr].CLC.U)) & SPI_CLC_DISS_CLEARMASK)\
                                                          >>SPI_CLC_DISS_BITPOS;

      #if(IFX_SPI_DEBUG_CLC == STD_ON)
      ReadBack |= Spi_IfxDebugStatus;
      #endif

      if(ReadBack == 1U)
      {
         RetVal = E_NOT_OK;
         break;
      }

#if(SPI_RESET_SFR_INIT == STD_ON)
      Spi_lQSPIHwKernelReset(ModLoopCtr);
#endif /* Reset at Init ON */
    }
    ModLoopCtr++;
  }while (ModLoopCtr < SPI_MAX_HW_UNIT);


  if(RetVal == E_OK)
  {
    /* SPI QSPIx Module Initialisation outside end init protection */
    ModLoopCtr = 0U;
    do
    {
      if(Spi_lModuleConfigured((uint8)ModLoopCtr) != 0U)
      {
        HWModuleConfigPtr = ConfigPtr->HWModuleConfigPtr[ModLoopCtr];
        /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
          to efficiently access the SFRs of multiple QSPI Modules.*/
        SPI_SFR_INIT_WRITE32(SPI_HW_MODULE[ModLoopCtr].\
                                            GLOBALCON.U,SPI_QSPI_RESET_MODULE);
        /* Select Lines (A/B) for MISO */
        /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
          to efficiently access the SFRs of multiple QSPI Modules.*/
        SPI_SFR_INIT_WRITE32(SPI_HW_MODULE[ModLoopCtr].PISEL.U,\
                                    (uint32)(HWModuleConfigPtr->HWPinSetting));

       /* Initialize SSOC Register - Active output level (AOL) setting as per
         configured values */
      /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
        to efficiently access the SFRs of multiple QSPI Modules.*/
      SPI_SFR_INIT_WRITE32(SPI_HW_MODULE[ModLoopCtr].SSOC.U,\
                                       HWModuleConfigPtr->HWCSPolaritySetting);
      }
      ModLoopCtr++;
    }while (ModLoopCtr < SPI_MAX_HW_UNIT);

   #if(SPI_BAUDRATE_AT_RUNTIME == STD_OFF)
    /*Set the ECON register values */
    Spi_lHwSetConfigExtn(ConfigPtr);
   #endif /* SPI_BAUDRATE_AT_RUNTIME == STD_OFF */

   #if(SPI_RESET_SFR_INIT == STD_ON)
    Spi_lHwDmaResetSfr();
   #endif /* Reset at Init ON */

    Spi_lHwDmaInit();

    ModLoopCtr = 0U;
    do
    {
      if(Spi_lModuleConfiguredAndAsync((uint8)ModLoopCtr) != 0U)
      {
        Spi_lHwInitIntr_SV(ModLoopCtr);
      }
      ModLoopCtr++;
    }while (ModLoopCtr < SPI_MAX_HW_UNIT);
  }
  /* Exit Critical Section */
  SchM_Exit_Spi_Init();

  return RetVal;
}
#endif

/*******************************************************************************
** Syntax           : static void Spi_lHwInit                                 **
**                    (                                                       **
**                      const Spi_ConfigType* ConfigPtr                       **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : ConfigPtr - Pointer to configuration set.               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to initialise the QSPI Hw (Level 0)            **
*******************************************************************************/
#if (SPI_LEVEL_DELIVERED == 0U)
static Std_ReturnType Spi_lHwInit(const Spi_ConfigType* ConfigPtr)
{
  volatile uint32 ReadBack;
  uint32 ModLoopCtr;
  const Spi_HWModuleConfigType* HWModuleConfigPtr;
  Std_ReturnType RetVal = E_OK;

/*  ------------------------------------------------------------------ **
**                 Spi Hw Module Initialization                        **
**  ------------------------------------------------------------------ */
  /* Enter Critical Section */
  SchM_Enter_Spi_Init();


  ModLoopCtr = 0U;
  do
  {
    if(Spi_lModuleConfigured((uint8)ModLoopCtr) != 0U)
    {
      /* Get QSPIx Configuration Pointer */
      HWModuleConfigPtr = (ConfigPtr->HWModuleConfigPtr[ModLoopCtr]) ;

     /* Reset End Init Protection to access regsiters */
     SPI_SFR_INIT_RESETENDINIT();

      /* SPI QSPIx Module Initialisation within end init protection */
      /* Initialize CLC Register - Enable QSPIx Module, Set Sleep Settings */
      /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
        to efficiently access the SFRs of multiple QSPI Modules.*/
      SPI_SFR_INIT_WRITE32(SPI_HW_MODULE[ModLoopCtr].CLC.U,\
                                            HWModuleConfigPtr->HWClkSetting);

      /* Set End Init Protection */
      SPI_SFR_INIT_SETENDINIT();

      /* Fix for CPU Bug CPU_TC.H002 */
      /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
        to efficiently access the SFRs of multiple QSPI Modules.*/
      ReadBack = (uint32)(((uint32)SPI_SFR_INIT_USER_MODE_READ32\
                  (SPI_HW_MODULE[ModLoopCtr].CLC.U)) & SPI_CLC_DISS_CLEARMASK)\
                                                          >>SPI_CLC_DISS_BITPOS;

      #if(IFX_SPI_DEBUG_CLC == STD_ON)
      ReadBack |= Spi_IfxDebugStatus;
      #endif

      if(ReadBack == 1U)
      {
         RetVal = E_NOT_OK;
         break;
      }

#if(SPI_RESET_SFR_INIT == STD_ON)
      Spi_lQSPIHwKernelReset(ModLoopCtr);
#endif /* Reset at Init ON */
    }
    ModLoopCtr++;
  }while (ModLoopCtr < SPI_MAX_HW_UNIT);

  /* Exit Critical Section */
  SchM_Exit_Spi_Init();

  if(RetVal == E_OK)
  {
    ModLoopCtr = 0U;
    do
    {
      if(Spi_lModuleConfigured((uint8)ModLoopCtr) != 0U)
      {
        HWModuleConfigPtr = ConfigPtr->HWModuleConfigPtr[ModLoopCtr];
        /*updated register GLOBALCON*/
        /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
          to efficiently access the SFRs of multiple QSPI Modules.*/
        SPI_SFR_INIT_WRITE32(SPI_HW_MODULE[ModLoopCtr].\
                                            GLOBALCON.U,SPI_QSPI_RESET_MODULE);

        /* Select Lines (A/B) for MISO */
        /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
          to efficiently access the SFRs of multiple QSPI Modules.*/
        SPI_SFR_INIT_WRITE32(SPI_HW_MODULE[ModLoopCtr].PISEL.U,\
                                    (uint32)(HWModuleConfigPtr->HWPinSetting));
        /* Initialize SSOC Register - Active output level (AOL) setting as per
         configured values */
       /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
         to efficiently access the SFRs of multiple QSPI Modules.*/
        SPI_SFR_INIT_WRITE32(SPI_HW_MODULE[ModLoopCtr].SSOC.U,\
                                      HWModuleConfigPtr->HWCSPolaritySetting);
      }
      ModLoopCtr++;
    }while (ModLoopCtr < SPI_MAX_HW_UNIT);

   #if(SPI_BAUDRATE_AT_RUNTIME == STD_OFF)
    /*Set the ECON register values */
    Spi_lHwSetConfigExtn(ConfigPtr);
   #endif /* SPI_BAUDRATE_AT_RUNTIME == STD_OFF */
  }
  return RetVal;
}
#endif
/* SPI_LEVEL_DELIVERED == 0U */

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI021_2_SPI252_2]                    **
** Syntax           : static void Spi_lHwDeInit                               **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : None.                                                   **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to De-initialise the QSPI Hw                   **
*******************************************************************************/
static void Spi_lHwDeInit(void)
{
  uint32 ModLoopCtr;
  #if (SPI_LEVEL_DELIVERED != 0U) /*Used Only in Async Mode*/
  uint16 Index;
  #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
  uint16 QmModIndex;
  #endif
  #endif
  Ifx_QSPI* ModulePtr;
  uint8 HwChnlIdx;

  /* SPI HW is set to a state comparable to PowerOnReset State */
  /* QSPIx Deinitialization */
  ModLoopCtr = 0U;
  do
  {
    if(Spi_lModuleConfigured((uint8)ModLoopCtr) != 0U)
    {
      #if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
      Spi_lHwDisableQspiPtIntr_SV(ModLoopCtr);
      Spi_lHwDisableQspiUsrIntr_SV(ModLoopCtr);
      #endif

      /* Reset SSOC Register values */
      /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
        to efficiently access the SFRs of multiple QSPI Modules.*/
      SPI_SFR_DEINIT_WRITE32(SPI_HW_MODULE[ModLoopCtr].SSOC.U,\
                                                        SPI_QSPI_SSOC_RSTVAL);
      /* Reset QSPI module by setting GLOBALCON.RESETS bits */
      /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
        to efficiently access the SFRs of multiple QSPI Modules.*/
      SPI_SFR_DEINIT_WRITE32(SPI_HW_MODULE[ModLoopCtr].GLOBALCON.U,\
                                                        SPI_QSPI_RESET_MODULE);

      #if (SPI_LEVEL_DELIVERED != 0U) /*Used Only in Async Mode*/
        /* Reset the QSPIx SRC register/s */
        Spi_lHwDeInitIntr(ModLoopCtr);
      #endif

      /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
        to efficiently access the SFRs of multiple QSPI Modules.*/
      ModulePtr =  &(SPI_HW_MODULE[ModLoopCtr]);
      for(HwChnlIdx = 0U; HwChnlIdx < 8U; HwChnlIdx++)
      {
        SPI_SFR_DEINIT_WRITE32(ModulePtr->ECON[HwChnlIdx].U,\
                                                        SPI_QSPI_ECON_RSTVAL);
      }
    }
    ModLoopCtr++;
  }while (ModLoopCtr < SPI_MAX_HW_UNIT);

  #if (SPI_LEVEL_DELIVERED != 0U) /*Used Only in Async Mode*/
  Spi_lHwDmaDeInit();
  #endif

  /* Deinit of Regsisters within End Init Protection */
  /* Enter Crtical Section */
  SchM_Enter_Spi_DeInit();

  /* Disable the module and reset clock settings */
  ModLoopCtr = 0U;
  do
  {
    if(Spi_lModuleConfigured((uint8)ModLoopCtr) != 0U)
    {
      /* Reset End Init Protection to access regsiters */
      SPI_SFR_DEINIT_RESETENDINIT();
      /* Set DISR to Disable the Module */
      /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
        to efficiently access the SFRs of multiple QSPI Modules.*/
      SPI_SFR_DEINIT_WRITE32(SPI_HW_MODULE[ModLoopCtr].CLC.U,\
                                                    SPI_QSPI_CLC_DISR_DISABLE);
      SPI_SFR_DEINIT_SETENDINIT();     /* Set  End Init Protection */
    }
    ModLoopCtr++;
  }while (ModLoopCtr < SPI_MAX_HW_UNIT);

  #if (SPI_LEVEL_DELIVERED != 0U) /*Used Only in Async Mode*/
  #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
  QmModIndex = 0U;
  #endif
  Index =0U;
  do
  {
      #if (SPI_SAFETY_ENABLE == STD_ON)
      if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)Index))
      {
        Spi_AsilChnlAccess[0].DmaChannelIdx.RxDmaChannel = DMA_CHANNEL_INVALID;
        Spi_AsilChnlAccess[0].DmaChannelIdx.TxDmaChannel = DMA_CHANNEL_INVALID;
      }
      else
      {
        #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
        if(Spi_lModuleConfiguredAndAsync((uint8)Index) != 0U)
        {
          Spi_QmChnlAccess[QmModIndex].DmaChannelIdx.RxDmaChannel = \
                                                           DMA_CHANNEL_INVALID;

          Spi_QmChnlAccess[QmModIndex].DmaChannelIdx.TxDmaChannel = \
                                                           DMA_CHANNEL_INVALID;

          /* Increment only if module is configured as QM master module */
          QmModIndex++;
        }
        #endif
      }
      #else
      {
        if(Spi_lModuleConfiguredAndAsync((uint8)Index) != 0U)
        {
          Spi_QmChnlAccess[QmModIndex].DmaChannelIdx.RxDmaChannel = \
                                                           DMA_CHANNEL_INVALID;

          Spi_QmChnlAccess[QmModIndex].DmaChannelIdx.TxDmaChannel = \
                                                           DMA_CHANNEL_INVALID;

          /* Increment only if module is configured as QM master module */
          QmModIndex++;
        }
      }
      #endif

    Index++;
  }while  (Index < SPI_MAX_HW_UNIT);
  #endif

  /* Exit Critical Section */
  SchM_Exit_Spi_DeInit();
}

#if (SPI_LEVEL_DELIVERED == 2U)
/*******************************************************************************
** Syntax           : static void Spi_lHwSetAsyncModeToIntr(void)             **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : None.                                                   **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Set the Asynchronous mode to Interrupt      **
**                    The function deos the below.                            **
**                    Activate Ch interrupt trigger,                          **
**                    enable & configure Dma, QSPIx Tx/Rx/Err interrupt/s,    **
**                    Channel interrupt control register is set               **
*******************************************************************************/
static void Spi_lHwSetAsyncModeToIntr(void)
{
  uint32 ModLoopCtr;
  Dma_ChannelType  DmaReceiveChannel;
  #if((SPI_QM_ASYNC_MASTER_MODULES_USED != 0U))
  uint32 QmModIndex = 0U;
  #endif

  #if((SPI_SAFETY_ENABLE == STD_ON) && (SPI_QM_ASYNC_MASTER_MODULES_USED == 0U))
  DmaReceiveChannel = DMA_CHANNEL_INVALID;
  /* To remove warning: Possibly Uninitialised*/
  #endif

  /* If QSPIx Channel is Used for Asynchronous TransmissIon,
     then switch it to interrupt mode by doing below.
     Activate Ch interrupt trigger,
     enable & configure Dma, QSPIx Tx/Rx/Err interrupt/s,
     Channel interrupt control register is set
  */

  ModLoopCtr = 0U;
  do
  {
   if(Spi_lModuleConfiguredAndAsync((uint8)ModLoopCtr) != 0U)
   {
     #if (SPI_SAFETY_ENABLE == STD_ON)
     if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)ModLoopCtr))
     {
       DmaReceiveChannel  = Spi_AsilChnlAccess[0U].DmaChannelIdx.RxDmaChannel;
     }
     else
     {
       #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
       DmaReceiveChannel  = \
                       Spi_QmChnlAccess[QmModIndex].DmaChannelIdx.RxDmaChannel;

       /* Increment only if  QM master module is configured as ASYNC  */
       QmModIndex++;
       #endif
     }
     #else
     {
       DmaReceiveChannel  = \
                       Spi_QmChnlAccess[QmModIndex].DmaChannelIdx.RxDmaChannel;

       /* Increment only if  QM master module is configured as ASYNC  */
       QmModIndex++;
     }
     #endif

     /* Set Interrupt Control */
     SPI_SFR_RUNTIME_MCAL_DMACFGINTCONTROL\
                                            (DmaReceiveChannel, SPI_DMA_INTCT);
     /* Enable RX DMA Ch Interrupt Only
        (TXDMA intr will be enabled for last channel only) */
     SPI_SFR_RUNTIME_MCAL_DMAENABLECHINTRTRIGGER(DmaReceiveChannel);
     /* Enable DMA Interrupt */
     Spi_lHwInitDmaIntr(ModLoopCtr);
     /* Configure Qspix Rx/Tx/Err interrupts */
     Spi_lHwInitIntr(ModLoopCtr);
   }
   else
   {
     /* Do nothing if QSPI module is not configured */
   }
   ModLoopCtr++;
  }while (ModLoopCtr < SPI_MAX_HW_UNIT);
}
/*******************************************************************************
** Syntax           : static void Spi_lHwSetAsyncModeToPoll(void)             **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : None.                                                   **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Set the Asynchronous mode to Polling mode   **
**                    The function deos the below.                            **
**                    De-Activate Ch interrupt trigger,                       **
**                    Disable Dma, QSPIx Tx/Rx/Err interrupt/s,               **
**                    Channel interrupt control register is Cleared           **
*******************************************************************************/
static void Spi_lHwSetAsyncModeToPoll(void)
{
  uint32 ModLoopCtr;
  Dma_ChannelType  DmaReceiveChannel;
  #if((SPI_QM_ASYNC_MASTER_MODULES_USED != 0U))
  uint32 QmModIndex = 0U;
  #endif

  #if((SPI_SAFETY_ENABLE == STD_ON) && (SPI_QM_ASYNC_MASTER_MODULES_USED == 0U))
  DmaReceiveChannel = DMA_CHANNEL_INVALID;
  /* To remove warning: Possibly Uninitialised*/
  #endif

  /* If QSPIx Channel is Used for Asynchronous Transmission,
     then switch it to polling mode by doing below.
     De-activate Ch interrupt trigger,
     Disable Dma, QSPIx Tx/Rx/Err interrupt/s,
     Channel interrupt control register is cleared
  */

  ModLoopCtr = 0U;
  do
  {
    if(Spi_lModuleConfiguredAndAsync((uint8)ModLoopCtr) != 0U)
    {
      #if (SPI_SAFETY_ENABLE == STD_ON)
      if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)ModLoopCtr))
      {
        DmaReceiveChannel  = Spi_AsilChnlAccess[0U].DmaChannelIdx.RxDmaChannel;
      }
      else
      {
        #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
        DmaReceiveChannel  = \
                      Spi_QmChnlAccess[QmModIndex].DmaChannelIdx.RxDmaChannel;

        /* Increment only if  QM master module is configured as ASYNC  */
        QmModIndex++;
        #endif
      }
      #else
      {
        DmaReceiveChannel  = \
                      Spi_QmChnlAccess[QmModIndex].DmaChannelIdx.RxDmaChannel;

        /* Increment only if  QM master module is configured as ASYNC  */
        QmModIndex++;
      }
      #endif

      /* Disable Dma intr to Core. */
      SPI_SFR_RUNTIME_MCAL_DMADISABLECHINTRTRIGGER(DmaReceiveChannel);
      /* Disable DMA Interrupt */
      Spi_lHwDeInitDmaIntr(ModLoopCtr);
      /* Disable QSPI Error Interrupt */
      Spi_lHwDisableErrIntr(ModLoopCtr);
    }
    else
    {
      /* Do nothing if QSPI module is not configured */
    }
    ModLoopCtr++;
  }while (ModLoopCtr < SPI_MAX_HW_UNIT);
}
#endif
/*******************************************************************************
** Syntax           : static uint32 Spi_lHwCheckRxStatus                      **
** (                                                                          **
**   Ifx_QSPI* ModulePtr, uint8 ApiAccessId                                   **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : ModulePtr     : Hw module pointer.                      **
**                  : ApiAccessId   : API access type                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Qspi Error status.                                      **
**                                                                            **
** Description      : Function to check the Qspi Receive Error status         **
*******************************************************************************/
static uint32 Spi_lHwCheckRxStatus(volatile Ifx_QSPI* ModulePtr, \
                                                              uint8 ApiAccessId)
{
  uint32 returnval;
  volatile uint32 temp;
  returnval = 0U;
#if ((SPI_USER_MODE_RUNTIME_API_ENABLE == STD_ON) && \
                                  (SPI_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON))
  if (ApiAccessId == SPI_RUNTIME_ACCESS)
  {
    /* if receive error */
    temp = (uint32)SPI_SFR_RUNTIME_USER_MODE_READ32(ModulePtr->STATUS.U);

    /* Clear the Error Flag/s.Reserve bit access
     is ensured for FLAGSCLEAR register */
    SPI_SFR_RUNTIME_USER_MODE_WRITE32(ModulePtr->FLAGSCLEAR.U,\
                                                     SPI_QSPI_FLAGSCLEAR_VALUE);
  }
  else
#endif
  {
    /* if receive error */
    temp = ModulePtr->STATUS.U;

    /* Clear the Error Flag/s */
    ModulePtr->FLAGSCLEAR.U = SPI_QSPI_FLAGSCLEAR_VALUE;
  }
#if ((SPI_USER_MODE_RUNTIME_API_ENABLE == STD_OFF) || \
                                 (SPI_RUNNING_IN_USER_0_MODE_ENABLE == STD_OFF))
    UNUSED_PARAMETER(ApiAccessId)
#endif
  if ( temp & SPI_QSPI_ERRORSTATUS_MASK )
  {
    returnval = 1U;
  }
  return returnval;
}

#if (SPI_SLAVE_ENABLE == STD_ON)
/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE uint32 Spi_lHwCheckSlaveRxStatus       **
** (                                                                          **
**   Ifx_QSPI* ModulePtr,                                                     **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : ModulePtr - Hw module pointer.                          **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Qspi Error status.                                      **
**                                                                            **
** Description      : Function to check the Qspi Receive Error status         **
*******************************************************************************/
IFX_LOCAL_INLINE uint32 Spi_lHwCheckSlaveRxStatus(volatile Ifx_QSPI* ModulePtr)
{
  uint32 returnval;
  volatile uint32 temp;
  returnval = 0U;

  /* if receive error */
  temp = ModulePtr->STATUS.U;

  /* Clear the Error Flag/s .Reserve bit access
   is ensured for FLAGSCLEAR register */
  ModulePtr->FLAGSCLEAR.U = SPI_QSPI_FLAGSCLEAR_VALUE;
  if ( temp & SPI_QSPI_SLAVE_ERRORSTATUS_MASK )
  {
    returnval = 1U;
  }
  return returnval;
}
#endif

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI020_5, DS_NAS_HE2_SPI_PR3047,
**                       DS_NAS_EP_SPI_PR3047]                                **
** Syntax           : static void Spi_lHwSetJobConfig                         **
** (                                                                          **
**   Ifx_QSPI* ModulePtr,                                                     **
**   const Spi_JobConfigType* JobConfigPtr                                    **
** )                                                                          **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : ModulePtr - Hw module pointer.                          **
**                    BaudRateConfig - Packed variable for Baud Rate          **
                                  Configuration Parameters TQ, Q, A, B, C     **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Set the Job Configuration Parameters        **
*******************************************************************************/
static void Spi_lHwSetJobConfig(volatile Ifx_QSPI* ModulePtr,
                                       const Spi_JobConfigType* JobConfigPtr)
{

  /* Packed variable for Baud Rate Configuration Parameters TQ, Q, A, B, C
  BaudRateConfig : ECON
  bit 0-5: Q
  bit 6-7 : A
  bit 8-9 : B
  bit 10-11 : C
  BaudRateConfig : GLOBALCON
  bit 0-7: TQ
  */

  Ifx_QSPI_GLOBALCON GlobalConReg;
  Ifx_QSPI_GLOBALCON1 GlobalCon1Reg;
  uint32 BaudRateConfigVal;
  uint16 Tqval;

#if(SPI_BAUDRATE_AT_RUNTIME == STD_ON)
  Ifx_QSPI_ECON EconReg;
  uint16 Qval;
  uint8 Aval, Bval, Cval;
  uint8 HwChannelno;
#endif /* SPI_BAUDRATE_AT_RUNTIME == STD_ON */

  /*
  Baudrate or SCLK = 1 /( (1/fQSPI) * GLOBALCON.TQ * ECONz.Q *[A+B+C]) bps
  GLOBALCON.TQ : Global Time Quantum - Common n-divider scaling the baud rates
           of all channels in direction of higher or lower baud rates
           0 = div by 1, 255 = div by 256
  ECONz.Q : Time Quantum - Defines the time quantum length used by A, B, and C
            to define the baud rate and duty cycle
            6b'000000 =  1, 6b'111111 = 64

  BaudRateConfig :
  bit 0-7: TQ
  bit 8-13 : Q
  bit 16-17 : A
  bit 18-19 : B
  bit 20-21 : C
  */

  BaudRateConfigVal = JobConfigPtr->BaudRateConfig;
  /*AI00249920: ECON is setup in Spi_Init() */
  Tqval = (uint16)((uint16)BaudRateConfigVal & SPI_BAUDRATECONFIG_TQ_MASK);

  GlobalConReg.U = \
              (uint32)SPI_SFR_RUNTIME_USER_MODE_READ32(ModulePtr->GLOBALCON.U);
  GlobalCon1Reg.U = \
             (uint32)SPI_SFR_RUNTIME_USER_MODE_READ32(ModulePtr->GLOBALCON1.U);

  GlobalConReg.B.MS = SPI_QSPI_MASTER_SELECT;   /* QSPI as master */
  GlobalConReg.B.LB = SPI_QSPI_LOOPBACK_DISABLE;   /* loop back disabled */
  GlobalConReg.B.SI = SPI_QSPI_SI_DISABLE;   /* Status Injection disabled. */
  GlobalConReg.B.EXPECT = SPI_QSPI_EXPECT_VALUE;   /*  expect time to Max */
  GlobalConReg.B.SRF = SPI_QSPI_SRF_DISABLE;    /* dont Stop on RXFIFO full. */
  GlobalConReg.B.EN = SPI_QSPI_MODULE_ENABLE;
  GlobalConReg.B.TQ = Tqval;

  /* Ensuring no resets */
  GlobalConReg.B.RESETS = 0U;
  GlobalCon1Reg.B.ERRORENS = SPI_QSPI_ERRORENS_VALUE;
  GlobalCon1Reg.B.TXFIFOINT = SPI_QSPI_TXFIFOINT_VALUE;
  GlobalCon1Reg.B.RXFIFOINT = SPI_QSPI_RXFIFOINT_VALUE;
  GlobalCon1Reg.B.TXEN = SPI_QSPI_INT_ENABLE;
  GlobalCon1Reg.B.RXEN = SPI_QSPI_INT_ENABLE;
  GlobalCon1Reg.B.PT2EN = 1U;
  GlobalCon1Reg.B.PT2 = 5U; /* EOF event*/
  GlobalCon1Reg.B.USREN = 1U;
  GlobalCon1Reg.B.PT1 = 6U; /* DNA or start of expect */
  GlobalCon1Reg.B.RXFM = 1U; /* Single Move Mode */
  GlobalCon1Reg.B.TXFM = 1U; /* Single Move Mode */

#if(SPI_BAUDRATE_AT_RUNTIME == STD_ON)

  Qval = ((uint16)(BaudRateConfigVal >> SPI_BAUDRATECONFIG_Q_SHIFT)
                            & SPI_BAUDRATECONFIG_Q_MASK);
  Aval = ((uint8)(BaudRateConfigVal >> SPI_BAUDRATECONFIG_A_SHIFT)
                            & SPI_BAUDRATECONFIG_A_MASK);
  Bval = ((uint8)(BaudRateConfigVal >> SPI_BAUDRATECONFIG_B_SHIFT)
                            & SPI_BAUDRATECONFIG_B_MASK);
  Cval = ((uint8)(BaudRateConfigVal >> SPI_BAUDRATECONFIG_C_SHIFT)
                            & SPI_BAUDRATECONFIG_C_MASK);
  /* HW channels vary from 0 - 15
     but the ECON maps 8 - 15 to 0 to 7.   */
  HwChannelno = ((uint8)(JobConfigPtr->HwUnit) >> SPI_HWUNIT_CH_SHIFT);

  EconReg.U = (uint32)SPI_SFR_RUNTIME_USER_MODE_READ32\
                (ModulePtr->ECON[HwChannelno & SPI_QSPI_HWCHANNELNO_MASK].U);

  EconReg.B.CPH = (((uint8)(JobConfigPtr->ShiftClkConfig))
                                               & SPI_QSPI_CLOCKPHASE_MASK);
  EconReg.B.CPOL = ((uint8)((JobConfigPtr->ShiftClkConfig)
                     >> SPI_QSPI_CLOCKPOL_SHIFT) & SPI_QSPI_CLOCKPOL_MASK);

  if(((uint8)JobConfigPtr->ParitySelection) == SPI_QSPI_PARITY_UNUSED)
  {
    /* Transmit/Receive parity Disabled */
    EconReg.B.PAREN = SPI_QSPI_PARITY_DISABLE;
  }
  else
  {
    /* Transmit/Receive parity Enabled */
    EconReg.B.PAREN = SPI_QSPI_PARITY_ENABLE;
  }

  /* Configure the ECON Baudrate params */
  EconReg.B.Q = (uint8)Qval;
  EconReg.B.A = (uint8)Aval;
  EconReg.B.B = (uint8)Bval;
  EconReg.B.C = (uint8)Cval;


  SPI_SFR_RUNTIME_MODIFY32(ModulePtr->ECON[HwChannelno &\
               SPI_QSPI_HWCHANNELNO_MASK].U,(uint32)EconReg.U,(uint32)EconReg.U)

#endif /* SPI_BAUDRATE_AT_RUNTIME == STD_ON */

  /* ModulePtr->GLOBALCON.U = GlobalConReg.U; */

  SPI_SFR_RUNTIME_MODIFY32(ModulePtr->GLOBALCON.U,\
                                  (uint32)GlobalConReg.U,(uint32)GlobalConReg.U)

  /* ModulePtr->GLOBALCON1.U = GlobalCon1Reg.U; */

  SPI_SFR_RUNTIME_MODIFY32(ModulePtr->GLOBALCON1.U,\
                                (uint32)GlobalCon1Reg.U,(uint32)GlobalCon1Reg.U)
   /*Reserve bit access is ensured for FLAGSCLEAR register*/
  SPI_SFR_RUNTIME_USER_MODE_WRITE32(ModulePtr->FLAGSCLEAR.U,\
                                                   (SPI_QSPI_FLAGSCLEAR_VALUE));
}

/*******************************************************************************
** Traceability : []                                                          **
** Syntax           : IFX_LOCAL_INLINE void Spi_lHwSetConfigExtn              **
** (                                                                          **
**   const Spi_ConfigType* ConfigPtr                                          **
** )                                                                          **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : ConfigPtr  -   init config pointer                      **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Set the ECON register Parameters            **
*******************************************************************************/
#if(SPI_BAUDRATE_AT_RUNTIME == STD_OFF)
IFX_LOCAL_INLINE void Spi_lHwSetConfigExtn(const Spi_ConfigType* ConfigPtr)
{
    Ifx_QSPI* ModulePtr;
    uint8 HwChannelno;
    uint8 Module;
    uint8 EconCntr;

    EconCntr = 0U;
    do
    {
      /*IFX_MISRA_RULE_17_04_STATUS="SpiBaudrateEconPtr" Pointer arithmetic is
      used to efficiently access the SFRs of multiple QSPI Modules.*/
      Module = ((ConfigPtr->SpiBaudrateEconPtr)[EconCntr].QSPIHwUnit
                                                           & SPI_HWUNIT_MASK);
      /*IFX_MISRA_RULE_17_04_STATUS="SpiBaudrateEconPtr" Pointer arithmetic is
      used to efficiently access the SFRs of multiple QSPI Modules.*/
      HwChannelno = ((((ConfigPtr->SpiBaudrateEconPtr)[EconCntr].QSPIHwUnit) \
                         >> SPI_HWUNIT_CH_SHIFT) & SPI_QSPI_HWCHANNELNO_MASK);

      /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is
      used to efficiently access the SFRs of multiple QSPI Modules.*/
      ModulePtr =  &(SPI_HW_MODULE[Module]);

      /* Write parameters to ECON register */
      /*IFX_MISRA_RULE_17_04_STATUS="SpiBaudrateEconPtr" Pointer arithmetic is
      used to efficiently access the SFRs of multiple QSPI Modules.*/
      SPI_SFR_INIT_WRITE32(ModulePtr->ECON[HwChannelno].U,
                            (ConfigPtr->SpiBaudrateEconPtr)[EconCntr].EconVal);
      EconCntr++;
    }while(EconCntr < ConfigPtr->NoOfEconReg);
}

#if (SPI_SAFETY_ENABLE == STD_ON)
#if (SPI_INITCHECK_API == STD_ON)
/*******************************************************************************
** Traceability : []                                                          **
** Syntax           : IFX_LOCAL_INLINE Std_ReturnType Spi_lHwCheckConfigExtn  **
** (                                                                          **
**   const Spi_ConfigType* ConfigPtr                                          **
** )                                                                          **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : ConfigPtr  -   init config pointer                      **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : E_OK if ECON registers match else E_NOT_OK.             **
**                                                                            **
** Description      : Function to Check the ECON register Parameters          **
*******************************************************************************/
IFX_LOCAL_INLINE Std_ReturnType Spi_lHwCheckConfigExtn
(
   const Spi_ConfigType* ConfigPtr
)
{
    Ifx_QSPI* ModulePtr;
    Ifx_QSPI_ECON EconReg;
    uint8 HwChannelno;
    Std_ReturnType RetVal;
    uint32 ReadValue;
    volatile uint32 CompareValue;
    uint8 Module;
    uint8 EconCntr;

    CompareValue = SPI_INITCHK_COMP_VALUE;
    RetVal = E_OK;
    EconCntr = 0U;

    do
    {
 /*IFX_MISRA_RULE_17_04_STATUS="SpiBaudrateEconPtr" Pointer arithmetic is used
       to efficiently access the SFRs of multiple QSPI Modules.*/
      Module = ((ConfigPtr->SpiBaudrateEconPtr)[EconCntr].QSPIHwUnit
                                                           & SPI_HWUNIT_MASK);
/*IFX_MISRA_RULE_17_04_STATUS="SpiBaudrateEconPtr" Pointer arithmetic is used
       to efficiently access the SFRs of multiple QSPI Modules.*/
      HwChannelno = ((((ConfigPtr->SpiBaudrateEconPtr)[EconCntr].QSPIHwUnit)\
                         >> SPI_HWUNIT_CH_SHIFT) & SPI_QSPI_HWCHANNELNO_MASK);

      /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
       to efficiently access the SFRs of multiple QSPI Modules.*/
      ModulePtr =  &(SPI_HW_MODULE[Module]);

      /*check if respective ECONz sfr value matches*/
      ReadValue = (uint32)SPI_SFR_INIT_USER_MODE_READ32(ModulePtr->\
                                                           ECON[HwChannelno].U);

      /* Read parameters of ECON register */
/*IFX_MISRA_RULE_17_04_STATUS="SpiBaudrateEconPtr" Pointer arithmetic is used
       to efficiently access the SFRs of multiple QSPI Modules.*/
      EconReg.U = (ConfigPtr->SpiBaudrateEconPtr)[EconCntr].EconVal;

      CompareValue &= (ReadValue ^ ~((uint32)EconReg.U));

      if(CompareValue != SPI_INITCHK_COMP_VALUE)
      {
        RetVal = E_NOT_OK;
        break;
      }
      EconCntr++;
    }while(EconCntr < ConfigPtr->NoOfEconReg);

    return(RetVal);
}
#endif
#endif
#endif /* SPI_BAUDRATE_AT_RUNTIME == STD_OFF */

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_HE2_SPI_PR3018, DS_NAS_EP_SPI_PR3018]**
** Syntax           : IFX_LOCAL_INLINE void Spi_lQSPIHwKernelReset            **
** (                                                                          **
**   uint32 Module                                                            **
** )                                                                          **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module.                                     **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Function to reset the SFRs used by SPI driver           **
*******************************************************************************/
#if(SPI_RESET_SFR_INIT == STD_ON)
IFX_LOCAL_INLINE void Spi_lQSPIHwKernelReset(uint32 Module)
{
  volatile uint32 Readback;
  uint32 LoopCounter;

  /* Reset End Init Protection to access regsiters */
   SPI_SFR_INIT_RESETENDINIT();
  /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used to
    efficiently access the SFRs of multiple QSPI Modules.*/
  SPI_SFR_INIT_WRITE32(SPI_HW_MODULE[Module].KRST0.U,SPI_KERNEL_RESET_VALUE);
  /* Set End Init Protection */
  SPI_SFR_INIT_SETENDINIT();
  /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
    to efficiently access the SFRs of multiple QSPI Modules.*/
  Readback = SPI_SFR_INIT_USER_MODE_READ32(SPI_HW_MODULE[Module].KRST0.U);

  /* Reset End Init Protection to access regsiters */
   SPI_SFR_INIT_RESETENDINIT();
  /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used to
    efficiently access the SFRs of multiple QSPI Modules.*/
  SPI_SFR_INIT_WRITE32(SPI_HW_MODULE[Module].KRST1.U,SPI_KERNEL_RESET_VALUE);

  /* Set End Init Protection */
  SPI_SFR_INIT_SETENDINIT();
  /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
    to efficiently access the SFRs of multiple QSPI Modules.*/
  Readback = (uint32)SPI_SFR_INIT_USER_MODE_READ32\
                                                (SPI_HW_MODULE[Module].KRST1.U);

  LoopCounter = SPI_KERNEL_RESET_WAIT_COUNT;

  do
  {
    LoopCounter--;
    #if (IFX_SPI_DEBUG_RST == STD_ON)
    Readback = Spi_IfxDebugStatus;
    #else
    /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic
      is used to efficiently access the SFRs of multiple QSPI Modules.*/
    Readback = (uint32)SPI_SFR_INIT_USER_MODE_READ32\
                                                (SPI_HW_MODULE[Module].KRST0.U);
    #endif
  }while((Readback != SPI_KERNEL_RESET_STATUS) && (LoopCounter > 0U));

  /* Reset End Init Protection to access regsiters */
   SPI_SFR_INIT_RESETENDINIT();

  /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic
    is used to efficiently access the SFRs of multiple QSPI Modules.*/
  SPI_SFR_INIT_WRITE32(SPI_HW_MODULE[Module].KRSTCLR.U,SPI_KERNEL_RESET_VALUE);

  /* Set End Init Protection */
  SPI_SFR_INIT_SETENDINIT();

  /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
    to efficiently access the SFRs of multiple QSPI Modules.*/
  Readback = (uint32)SPI_SFR_INIT_USER_MODE_READ32\
                                             (SPI_HW_MODULE[Module].KRSTCLR.U);

  UNUSED_PARAMETER(Readback)
}
#endif /* SPI_RESET_SFR_INIT == STD_ON*/

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI020_6]                             **
** Syntax           : static void Spi_lHwSetChannelConfig                     **
** (  volatile uint32 Module,                                                 **
**    const Spi_ChannelConfigType* ChannelConfigPtr, uint32 TransferCount,    **
**    uint8 IsLastChannel, uint32 DelayAndHwChNo,                             **
**    const Spi_JobConfigType* JobConfigPtr);                                 **
** )                                                                          **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module .                                    **
**                    DataConfig  -   Data Config parameters                  **
**                    TransferCount  -   Transfer Count                       **
**                    IsLastChannel  -   Is it Last Channel                   **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Set the Channel Configuration Parameters    **
*******************************************************************************/
static void Spi_lHwSetChannelConfig(volatile uint32 Module,
           const Spi_ChannelConfigType* ChannelConfigPtr, uint32 TransferCount,
                uint8 IsLastChannel, uint32 DelayAndHwChNo,
                const Spi_JobConfigType* JobConfigPtr)
{
  /* DataConfig contains MSB, DL,Byte, */
  Ifx_QSPI_BACON BaconReg;
  volatile Ifx_QSPI* ModulePtr;
  uint32 TimeDelay;
  uint32 Temp;

  /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used to
    efficiently access the SFRs of multiple QSPI Modules.*/
  ModulePtr = &(SPI_HW_MODULE[Module]);
   /*Reserve bit access is ensured for FLAGSCLEAR register*/
  SPI_SFR_RUNTIME_USER_MODE_WRITE32(ModulePtr->FLAGSCLEAR.U,\
                                                    SPI_QSPI_FLAGSCLEAR_VALUE);

  BaconReg.U = (uint32)SPI_SFR_RUNTIME_USER_MODE_READ32(ModulePtr->BACON.U);

  if ((IsLastChannel == 1U) && (TransferCount == SPI_TRANSFERCOUNT_ONE))
  {
    /* last ch value with TC == 1  */
    BaconReg.B.LAST = 1U;
  }
  else
  {
    if ( JobConfigPtr->ChannelBasedChipSelect == 1U )
    {
      BaconReg.B.LAST = 1U;
    }
    else
    {
      BaconReg.B.LAST = 0U;
    }
    #if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
      Spi_lHwEnableQspiTxIntr(Module);
    #endif
  }

  if((IsLastChannel == 1U) && (JobConfigPtr->ChannelBasedChipSelect == 0U ))
  {
    /*User Interrupt at the PT1 Event in subsequent frames (1 = disabled)*/
    BaconReg.B.UINT = 1U;
  }
  else
  {
    /*User Interrupt at the PT1 Event in subsequent frames (0 = enabled)*/
    BaconReg.B.UINT = 0U;
  }

  /* TimeDelay
   bit 0 : Reserved
   bit 1-3: IPRE
   bit 4-6: IDLE
   bit 7-9: LPRE
   bit 10-12: LEAD
   bit 13-15: TPRE
   bit 16-18: TRAIL
   bit 19-31: Reserved
  */
  TimeDelay = DelayAndHwChNo & SPI_CONFIG_TIMEDELAY_MASK;

  Temp = BaconReg.U ;
  Temp = Temp & (~SPI_QSPI_TIMEDELAY_MASK) ;
  Temp = Temp | TimeDelay;
  BaconReg.U = Temp;

  /* Channel select */
  BaconReg.B.CS  = (uint8)(DelayAndHwChNo >> SPI_CONFIG_HWCHANNELNO_SHIFT);

  BaconReg.B.MSB = (uint8)(ChannelConfigPtr->DataConfig >> SPI_CONFIG_MSB_SHIFT)
                     & SPI_CONFIG_MSB_MASK ; /* 1 = MSB or 0 = LSB */

  BaconReg.B.BYTE = SPI_QSPI_DL_BIT_SELECT; /* 1 = bytes or  0 = bits */
  /* data length in bits  */
  BaconReg.B.DL = ((uint8)ChannelConfigPtr->DataConfig &
                                                   SPI_CONFIG_DATALENGTH_MASK);

  if ( JobConfigPtr->ParitySelection != SPI_QSPI_PARITY_UNUSED )
  {
    BaconReg.B.PARTYP = (uint8)(JobConfigPtr->ParitySelection);
  }
  else
  {
    /*Do Nothing since parity is not enabled in ECONz register*/
  }

  SPI_SFR_RUNTIME_USER_MODE_WRITE32(ModulePtr->BACONENTRY.U,BaconReg.U);
}

/*******************************************************************************
**                            Qspi Interrupt configuration APIs               **
*******************************************************************************/
#if (SPI_LEVEL_DELIVERED == 2U)
/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Spi_lHwDisableErrIntr             **
** (                                                                          **
**   uint32 Module                                                            **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
**                    Value  - Enable/Disable Interrupt                       **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Enable/Disable Spi Hw Error Interrupt       **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lHwDisableErrIntr(uint32 Module)
{
  /*Reserve bit access is ensured for SRC_QSPImERR register*/
  SPI_IRQ_SFR_RUNTIME_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].ERR.U,\
                                                     SPI_QSPI_ERR_CLEARMASK,0U)
}
#endif
/* SPI_LEVEL_DELIVERED == 2U */

#if ( (SPI_SLAVE_ENABLE == STD_ON) || (SPI_LEVEL_DELIVERED != 0U))
/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Spi_lHwDisableQspiRxIntr(         **
**                      uint32 Module, uint8 ApiAccessId)                     **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
                    : ApiAccessId   - API access type                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Disable Spi Hw Rx       Interrupt           **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lHwDisableQspiRxIntr(uint32 Module, uint8 ApiAccessId)
{
#if (SPI_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
  uint32 RxSreStatus;
  if (ApiAccessId == SPI_RUNTIME_ACCESS)
  {
    #ifdef IFX_SPI_DEBUG
    RxSreStatus = (((uint32)((uint32)(SPI_IRQ_SFR_RUNTIME_USER_MODE_READ32\
          (MODULE_SRC.QSPI.QSPI[Module].RX.U)) & SPI_SRC_QSPI_RX_SRE_CLEARMASK)\
                            >>IFX_SRC_SRCR_SRE_OFF) & TestSpi_DebugMask);
    #else
    RxSreStatus = ((uint32)((uint32)(SPI_IRQ_SFR_RUNTIME_USER_MODE_READ32\
          (MODULE_SRC.QSPI.QSPI[Module].RX.U)) & SPI_SRC_QSPI_RX_SRE_CLEARMASK)\
                                                 >>IFX_SRC_SRCR_SRE_OFF);
    #endif
    if (1U == RxSreStatus)
    {
      /* Set SRC.IOVCLR, SRC.SWSCLR, SRC.CLRR */
      /* Clear SRC.SRE */
     /*Reserve bit access is ensured for SRC_QSPImRX register*/
      SPI_IRQ_SFR_RUNTIME_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].RX.U,\
                              SPI_SRC_QSPI_RX_CLEARMASK,SPI_SRC_QSPI_RX_SETMASK)
    }
  }
  else
#endif
  {
    if(((uint32)((uint32)(MODULE_SRC.QSPI.QSPI[Module].RX.U) & \
                    SPI_SRC_QSPI_RX_SRE_CLEARMASK)>>IFX_SRC_SRCR_SRE_OFF) == 1U)
    {
      /* Set SRC.IOVCLR, SRC.SWSCLR, SRC.CLRR */
      /* Clear SRC.SRE */
     /*Reserve bit access is ensured for SRC_QSPImRX register*/
      MODULE_SRC.QSPI.QSPI[Module].RX.U = ((MODULE_SRC.QSPI.QSPI[Module].RX.U)\
                         & SPI_SRC_QSPI_RX_CLEARMASK) | SPI_SRC_QSPI_RX_SETMASK;
    }
  }
#if (SPI_USER_MODE_RUNTIME_API_ENABLE == STD_OFF)
UNUSED_PARAMETER(ApiAccessId)
#endif
}

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Spi_lHwClearErrIntr               **
** (                                                                          **
**   uint32 Module,                                                           **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Clear QSpi Hw Error Interrupt               **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lHwClearErrIntr(uint32 Module)
{

  /* Clear the QSPI Error interrupt */
  /*Reserve bit access is ensured for SRC_QSPImERR register*/
  /* Set SRC.IOVCLR, SRC.SWSCLR, SRC.CLRR */

  MODULE_SRC.QSPI.QSPI[Module].ERR.U = ((MODULE_SRC.QSPI.QSPI[Module].ERR.U) \
                     & SPI_SRC_QSPI_ERR_CLEARMASK1) | SPI_SRC_QSPI_ERR_SETMASK1;
}
#endif
/*( (SPI_SLAVE_ENABLE == STD_ON) || (SPI_LEVEL_DELIVERED != 0U))*/

#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Spi_lHwEnableQspiTxIntr(          **
**                                                         uint32 Module)     **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Enable Spi Hw Transmit Interrupt            **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lHwEnableQspiTxIntr(uint32 Module)
{
  /* Set SRC.IOVCLR, SRC.SWSCLR, SRC.CLRR */
  /*Reserve bit access is ensured for SRC_QSPImTX register*/
  SPI_IRQ_SFR_RUNTIME_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].TX.U,\
                            SPI_SRC_QSPI_TX_CLEARMASK,SPI_SRC_QSPI_TX_SETMASK1)
  SPI_IRQ_SFR_RUNTIME_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].TX.U,\
                            SPI_SRC_QSPI_TX_CLEARMASK,SPI_SRC_QSPI_TX_SETMASK2)
}

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Spi_lHwEnableQspiPtIntr           **
** (                                                                          **
**   uint32 Module                                                            **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Enable Spi Hw PT Interrupt                  **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lHwEnableQspiPtIntr(uint32 Module)
{

  /*  Enable intr */
  /*  MODULE_SRC.QSPI.QSPI[Module].PT.B.SRE  = 1U; */
  /*This fn is called from the isr, so macros are not used for regster write*/
  /*Reserve bit access is ensured for SRC_QSPImPT register*/
    MODULE_SRC.QSPI.QSPI[Module].PT.U = ((MODULE_SRC.QSPI.QSPI[Module].PT.U)\
                    & SPI_SRC_QSPI_PT_CLEARMASK2) | SPI_SRC_QSPI_TX_SETMASK2;
}

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Spi_lHwDisableQspiPtIntr          **
** (                                                                          **
**   uint32 Module                                                            **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
                    : ApiAccessId   - API access type                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Disable Spi Hw PT Interrupt                 **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lHwDisableQspiPtIntr(uint32 Module)
{
  if(((uint32)((uint32)(MODULE_SRC.QSPI.QSPI[Module].PT.U) & \
                  SPI_SRC_QSPI_PT_CLEARMASK1)>>SPI_SRC_QSPI_PT_BITPOS)  == 1U)
  {
    /* Set SRC.IOVCLR, SRC.SWSCLR, SRC.CLRR */
    /* Clear SRC.SRE */
    /*Reserve bit access is ensured for SRC_QSPImPT register*/
    MODULE_SRC.QSPI.QSPI[Module].PT.U = ((MODULE_SRC.QSPI.QSPI[Module].PT.U)\
                        & SPI_SRC_QSPI_PT_CLEARMASK) |SPI_SRC_QSPI_PT_SETMASK;
  }
}

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Spi_lHwDisableQspiPtIntr_SV       **
** (                                                                          **
**   uint32 Module                                                            **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Disable Spi Hw PT Interrupt                 **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lHwDisableQspiPtIntr_SV(uint32 Module)
{
  if(((uint32)(((uint32)SPI_IRQ_SFR_DEINIT_USER_MODE_READ32\
     (MODULE_SRC.QSPI.QSPI[Module].PT.U)) & SPI_SRC_QSPI_PT_CLEARMASK1)\
                                               >>SPI_SRC_QSPI_PT_BITPOS)  == 1U)
  {
    /*Reserve bit access is ensured for SRC_QSPImPT register*/
    SPI_IRQ_SFR_DEINIT_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].PT.U,\
                            SPI_SRC_QSPI_PT_CLEARMASK2,SPI_SRC_QSPI_PT_SETMASK)
    SPI_IRQ_SFR_DEINIT_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].PT.U,\
                                                  SPI_SRC_QSPI_PT_CLEARMASK4,0U)
    /*  Disable intr */
  }
}

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Spi_lHwEnableQspiUsrIntr          **
** (                                                                          **
**   uint32 Module                                                            **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Enable Spi Hw Usr Interrupt                 **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lHwEnableQspiUsrIntr(uint32 Module)
{
  /* Enable intr */
    MODULE_SRC.QSPI.QSPI[Module].U.U |= SPI_SRC_QSPI_U_SETMASK4;
}

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Spi_lHwDisableQspiUsrIntr         **
** (                                                                          **
**   uint32 Module, uint8 ApiAccessId                                         **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
                    : ApiAccessId   - API access type                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Disable Spi Hw Usr Interrupt                **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lHwDisableQspiUsrIntr(uint32 Module, \
                                                              uint8 ApiAccessId)
{
#if (SPI_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
  if (ApiAccessId == SPI_RUNTIME_ACCESS)
  {
    /* Set SRC.IOVCLR, SRC.SWSCLR, SRC.CLRR */
    /* Clear SRC.SRE */
    /*Reserve bit access is ensured for SRC_QSPImU register*/
      SPI_IRQ_SFR_RUNTIME_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].U.U,\
                                SPI_SRC_QSPI_U_CLEARMASK,SPI_SRC_QSPI_U_SETMASK)
  }
  else
#endif
  {
    /* Set SRC.IOVCLR, SRC.SWSCLR, SRC.CLRR */
    /* Clear SRC.SRE */
    /*Reserve bit access is ensured for SRC_QSPImU register*/
    MODULE_SRC.QSPI.QSPI[Module].U.U = ((MODULE_SRC.QSPI.QSPI[Module].U.U) & \
                             SPI_SRC_QSPI_U_CLEARMASK) | SPI_SRC_QSPI_U_SETMASK;
  }
#if (SPI_USER_MODE_RUNTIME_API_ENABLE == STD_OFF)
UNUSED_PARAMETER(ApiAccessId)
#endif
}

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Spi_lHwDisableQspiUsrIntr_SV      **
** (                                                                          **
**   uint32 Module                                                            **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Disable Spi Hw Usr Interrupt                **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lHwDisableQspiUsrIntr_SV(uint32 Module)
{
    /*Reserve bit access is ensured for SRC_QSPImU register*/
  SPI_IRQ_SFR_DEINIT_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].U.U,\
                             SPI_SRC_QSPI_U_CLEARMASK1,SPI_SRC_QSPI_U_SETMASK)
  SPI_IRQ_SFR_DEINIT_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].U.U,\
                                                   SPI_SRC_QSPI_U_CLEARMASK2,0U)
    /*  Disable intr */
}

/*******************************************************************************
** Syntax           : static void Spi_lHwDisableQspiTxIntr                    **
** (                                                                          **
**   uint32 Module, uint8 ApiAccessId                                         **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
**                  : ApiAccessId   : API access type                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Disable Spi Hw Transmit Interrupt           **
*******************************************************************************/
static void Spi_lHwDisableQspiTxIntr(uint32 Module, uint8 ApiAccessId)
{
#if (SPI_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
  if (ApiAccessId == SPI_RUNTIME_ACCESS)
  {
    if(((uint32)((uint32)(SPI_IRQ_SFR_RUNTIME_USER_MODE_READ32\
             (MODULE_SRC.QSPI.QSPI[Module].PT.U)) & SPI_SRC_QSPI_PT_CLEARMASK3)\
                                                  >>IFX_SRC_SRCR_SRE_OFF) == 1U)
    {
      /* Set SRC.IOVCLR, SRC.SWSCLR, SRC.CLRR */
      /* Clear SRC.SRE */

      /*Reserve bit access is ensured for SRC_QSPImTX register*/
      SPI_IRQ_SFR_RUNTIME_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].TX.U,\
                            SPI_SRC_QSPI_TX_CLEARMASK1,SPI_SRC_QSPI_TX_SETMASK3)
    }
  }
  else
#endif
  {
    if(((uint32)((uint32)(MODULE_SRC.QSPI.QSPI[Module].PT.U) & \
                       SPI_SRC_QSPI_PT_CLEARMASK3)>>IFX_SRC_SRCR_SRE_OFF) == 1U)
    {
      /* Set SRC.IOVCLR, SRC.SWSCLR, SRC.CLRR */
      /* Clear SRC.SRE */

      /*Reserve bit access is ensured for SRC_QSPImTX register*/
      MODULE_SRC.QSPI.QSPI[Module].TX.U  = ((MODULE_SRC.QSPI.QSPI[Module].TX.U)\
                      & SPI_SRC_QSPI_TX_CLEARMASK1) | SPI_SRC_QSPI_TX_SETMASK3;
    }
  }
#if (SPI_USER_MODE_RUNTIME_API_ENABLE == STD_OFF)
UNUSED_PARAMETER(ApiAccessId)
#endif
}

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Spi_lHwSetQspiTxIntr              **
** (                                                                          **
**   uint32 Module                                                            **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Triggers Spi Hw Transmit Interrupt          **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lHwSetQspiTxIntr(uint32 Module)
{
  /* Set SRC.IOVCLR, SRC.SWSCLR, SRC.CLRR */
  /*Reserve bit access is ensured for SRC_QSPImTX register*/
    SPI_IRQ_SFR_RUNTIME_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].TX.U,\
                            SPI_SRC_QSPI_TX_CLEARMASK,SPI_SRC_QSPI_TX_SETMASK4)

  /* SETR=1 and CLRR=1 should not be done together(results in no effect)*/

    SPI_IRQ_SFR_RUNTIME_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].TX.U,\
                            SPI_SRC_QSPI_TX_CLEARMASK,SPI_SRC_QSPI_TX_SETMASK5)
}

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Spi_lHwEnableQspiRxIntr           **
** (                                                                          **
**   uint32 Module, uint8 ApiAccessId                                         **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
                    : ApiAccessId   - API access type                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Enable Spi Hw Rx Interrupt                  **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lHwEnableQspiRxIntr(uint32 Module, uint8 ApiAccessId)
{
  if (ApiAccessId == SPI_RUNTIME_ACCESS)
  {
    /* Set SRC.IOVCLR, SRC.SWSCLR, SRC.CLRR */
    /*Reserve bit access is ensured for SRC_QSPImRX register*/
    SPI_IRQ_SFR_RUNTIME_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].RX.U,\
                            SPI_SRC_QSPI_RX_CLEARMASK1,SPI_SRC_QSPI_RX_SETMASK1)
    SPI_IRQ_SFR_RUNTIME_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].RX.U,\
                            SPI_SRC_QSPI_RX_CLEARMASK1,SPI_SRC_QSPI_RX_SETMASK3)
  }
  else
  {
    /* Set SRC.IOVCLR, SRC.SWSCLR, SRC.CLRR */
    /*Reserve bit access is ensured for SRC_QSPImRX register*/
    MODULE_SRC.QSPI.QSPI[Module].RX.U = ((MODULE_SRC.QSPI.QSPI[Module].RX.U) \
                       & SPI_SRC_QSPI_RX_CLEARMASK1) | SPI_SRC_QSPI_RX_SETMASK1;
    MODULE_SRC.QSPI.QSPI[Module].RX.U = ((MODULE_SRC.QSPI.QSPI[Module].RX.U) \
                       & SPI_SRC_QSPI_RX_CLEARMASK1) | SPI_SRC_QSPI_RX_SETMASK3;
  }
}

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Spi_lHwEnableQspiErrIntr          **
** (                                                                          **
**   uint32 Module, uint8 ApiAccessId                                         **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
                    : ApiAccessId   - API access type                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Enable Spi Hw Rx Interrupt                  **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lHwEnableQspiErrIntr(uint32 Module, uint8 ApiAccessId)
{
  if (ApiAccessId == SPI_RUNTIME_ACCESS)
  {
    /* Set SRC.IOVCLR, SRC.SWSCLR, SRC.CLRR */
    /*Reserve bit access is ensured for SRC_QSPImERR register*/
    SPI_IRQ_SFR_RUNTIME_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].ERR.U,\
                          SPI_SRC_QSPI_ERR_CLEARMASK2,SPI_SRC_QSPI_ERR_SETMASK2)
    SPI_IRQ_SFR_RUNTIME_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].ERR.U,\
                         SPI_SRC_QSPI_ERR_CLEARMASK3,SPI_SRC_QSPI_ERR_SETMASK3)
  }
  else
  {
    /* Set SRC.IOVCLR, SRC.SWSCLR, SRC.CLRR */
    /*Reserve bit access is ensured for SRC_QSPImERR register*/
    MODULE_SRC.QSPI.QSPI[Module].ERR.U = ((MODULE_SRC.QSPI.QSPI[Module].ERR.U)\
                     & SPI_SRC_QSPI_ERR_CLEARMASK2) | SPI_SRC_QSPI_ERR_SETMASK2;
    MODULE_SRC.QSPI.QSPI[Module].ERR.U = ((MODULE_SRC.QSPI.QSPI[Module].ERR.U)\
                     & SPI_SRC_QSPI_ERR_CLEARMASK3) | SPI_SRC_QSPI_ERR_SETMASK3;
  }
}

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Spi_lHwInitIntr                   **
** (                                                                          **
**   uint32 Module                                                            **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Initialise Spi Hw Interrupts during         **
**                    Hw initialisation                                       **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lHwInitIntr(uint32 Module)
{
  /* Set SRC.IOVCLR, SRC.SWSCLR, SRC.CLRR, SRC.SRE*/
  SPI_IRQ_SFR_RUNTIME_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].RX.U,\
                            SPI_SRC_QSPI_RX_CLEARMASK3,SPI_SRC_QSPI_RX_SETMASK4)
   /*  Enable intr */
  SPI_IRQ_SFR_RUNTIME_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].RX.U,\
                      SPI_SRC_QSPI_RX_CLEARMASK3,SPI_SRC_QSPI_RX_SETMASK3)


   /* Set SRC.IOVCLR, SRC.SWSCLR, SRC.CLRR */
  /* Clear SRC.SRE */
  /* QSPI Tx intr (i.e SRE bit) to DMA is not enabled at the beginning. */
   SPI_IRQ_SFR_RUNTIME_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].TX.U,\
                            SPI_SRC_QSPI_TX_CLEARMASK1,SPI_SRC_QSPI_TX_SETMASK3)
}

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Spi_lHwInitIntr_SV                **
** (                                                                          **
**   uint32 Module                                                            **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Initialise Spi Hw Interrupts during         **
**                    Hw initialisation                                       **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lHwInitIntr_SV(uint32 Module)
{
   /*Reserve bit access is ensured for SRC_QSPImRX register*/

  SPI_IRQ_SFR_INIT_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].RX.U,\
                            SPI_SRC_QSPI_RX_CLEARMASK3,SPI_SRC_QSPI_RX_SETMASK4)
   /*  Enable intr */
  SPI_IRQ_SFR_INIT_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].RX.U,\
                     SPI_SRC_QSPI_RX_CLEARMASK3,SPI_SRC_QSPI_RX_SETMASK3)


  /* QSPI Tx intr (i.e SRE bit) to DMA is not enabled at the beginning. */
  /*Reserve bit access is ensured for SRC_QSPImTX register*/

   SPI_IRQ_SFR_INIT_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].TX.U,\
                            SPI_SRC_QSPI_RX_CLEARMASK4,SPI_SRC_QSPI_RX_SETMASK4)

}

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Spi_lHwDeInitIntr                 **
** (                                                                          **
**   uint32 Module                                                            **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to De-Initialise Spi Hw Interrupts during      **
**                    Hw De-initialisation                                    **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lHwDeInitIntr(uint32 Module)
{
  /*Reserve bit access is ensured for SRC_QSPImRX register*/
  SPI_IRQ_SFR_DEINIT_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].RX.U,\
                           SPI_SRC_QSPI_RX_CLEARMASK7,SPI_SRC_QSPI_RX_SETMASK9)
  SPI_IRQ_SFR_DEINIT_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].RX.U,\
                                                 SPI_SRC_QSPI_RX_CLEARMASK6,0U)
  /*Reserve bit access is ensured for SRC_QSPImTX register*/
  SPI_IRQ_SFR_DEINIT_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].TX.U,\
                           SPI_SRC_QSPI_RX_CLEARMASK7,SPI_SRC_QSPI_RX_SETMASK9)
  SPI_IRQ_SFR_DEINIT_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].TX.U,\
                                                 SPI_SRC_QSPI_RX_CLEARMASK6,0U)
   /*Reserve bit access is ensured for SRC_QSPImERR register*/
  SPI_IRQ_SFR_DEINIT_MODIFY32(MODULE_SRC.QSPI.QSPI[Module].ERR.U,\
                                                 SPI_SRC_QSPI_RX_CLEARMASK6,0U)
}
#endif
/*(SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U)*/

/*******************************************************************************
**                            Dma Hw Apis                                     **
*******************************************************************************/

#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
/*******************************************************************************
** Syntax           : static void Spi_lHwDmaInit                              **
** (                                                                          **
**   void                                                                     **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : None.                                                   **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Initialise Dma Hw used for Spi during       **
**                    Hw initialisation                                       **
*******************************************************************************/
static void Spi_lHwDmaInit(void)
{
  uint32 ModLoopCtr;
  #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
  uint32 QmModIndex;
  #endif
  Dma_ChannelType DmaTransmitChannel;
  Dma_ChannelType DmaReceiveChannel;
  uint32 Address;

  Spi_lDmaCfgMeErrIntr(1U);
  #if ((SPI_SAFETY_ENABLE == STD_ON) && (SPI_QM_ASYNC_MASTER_MODULES_USED ==0U))
  DmaReceiveChannel = DMA_CHANNEL_INVALID;
  DmaTransmitChannel = DMA_CHANNEL_INVALID;
  #endif

  ModLoopCtr = 0U;
  #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
  QmModIndex = 0U;
  #endif
  do
  {
    if(Spi_lModuleConfiguredAndAsync((uint8)ModLoopCtr) != 0U)
    {
      #if (SPI_SAFETY_ENABLE == STD_ON)
      if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)ModLoopCtr))
      {
        DmaTransmitChannel = Spi_AsilChnlAccess[0U].DmaChannelIdx.TxDmaChannel;
        DmaReceiveChannel  = Spi_AsilChnlAccess[0U].DmaChannelIdx.RxDmaChannel;
      }
      else
      {
        #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
        DmaTransmitChannel = \
                       Spi_QmChnlAccess[QmModIndex].DmaChannelIdx.TxDmaChannel;
        DmaReceiveChannel  = \
                       Spi_QmChnlAccess[QmModIndex].DmaChannelIdx.RxDmaChannel;
        /* Increment only if  QM master module is configured as ASYNC  */
        QmModIndex++;
        #endif
      }
      #else
      {
        DmaTransmitChannel = \
                       Spi_QmChnlAccess[QmModIndex].DmaChannelIdx.TxDmaChannel;
        DmaReceiveChannel  = \
                       Spi_QmChnlAccess[QmModIndex].DmaChannelIdx.RxDmaChannel;
        /* Increment only if  QM master module is configured as ASYNC  */
        QmModIndex++;
      }
      #endif

      /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
        to efficiently access the SFRs of multiple QSPI Modules.*/
      Address = ((uint32)&(SPI_HW_MODULE[ModLoopCtr].RXEXIT.U));

      /* Set Source Address */
      Spi_lDmaSetSourceAddr(DmaReceiveChannel, Address, SPI_INIT_ACCESS);

      /* Init channel control register */
      Spi_lDmaChClrCtlCfgInit(DmaReceiveChannel);
      /* Set Destination Address */
      /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
        to efficiently access the SFRs of multiple QSPI Modules.*/
      Spi_lDmaSetDestAddr(DmaTransmitChannel,
           (uint32)&(SPI_HW_MODULE[ModLoopCtr].DATAENTRY[0U]), SPI_INIT_ACCESS);
      /* Init channel control register */
      Spi_lDmaChClrCtlCfgInit(DmaTransmitChannel);

      Spi_lDmaChClrIntrFlagsInit(DmaTransmitChannel);
      Spi_lDmaChClrIntrFlagsInit(DmaReceiveChannel);

      /* DMA Error Initialization */
      Spi_lDmaEnTransReqLostIntr(DmaReceiveChannel);
      Spi_lDmaEnTransReqLostIntr(DmaTransmitChannel);

      /* Set Interrupt Control  */
      Spi_lDmaCfgIntControl(DmaReceiveChannel, SPI_DMA_INTCT);

      #if ((SPI_LEVEL_DELIVERED == 1U) && \
                   (SPI_ASYNC_MODE_LEVEL1 == SPI_ASYNC_MODE_INTERRUPT))
      /* Enable RX DMA Ch Interrupt Only
      (TXDMA intr will be enabled for last channel only) */
      Spi_lDmaEnableChIntrTrigger(DmaReceiveChannel);

      Spi_lHwInitDmaIntr_SV(ModLoopCtr);
      #endif
    }
    else
    {
      /* Do nothing if QSPI module is not configured */
    }
    ModLoopCtr++;
  }while (ModLoopCtr < SPI_MAX_HW_UNIT);
}

/*******************************************************************************
** Syntax           : static void Spi_lHwDmaResetSfr                          **
** (                                                                          **
**   void                                                                     **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : None.                                                   **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to reset Dma SFRs used for Spi during          **
**                    Hw initialisation                                       **
*******************************************************************************/
#if(SPI_RESET_SFR_INIT == STD_ON)
static void Spi_lHwDmaResetSfr(void)
{
  uint32 ModLoopCtr;
  #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
  uint32 QmModIndex;
  #endif
  Dma_ChannelType DmaTransmitChannel;
  Dma_ChannelType DmaReceiveChannel;

  SPI_DMA_SFR_INIT_WRITE32(MODULE_DMA.ERRINTR.U,SPI_DMA_RESET_VALUE);

  #if ((SPI_SAFETY_ENABLE == STD_ON) && (SPI_QM_ASYNC_MASTER_MODULES_USED ==0U))
  DmaReceiveChannel = DMA_CHANNEL_INVALID;
  DmaTransmitChannel = DMA_CHANNEL_INVALID;
  #endif

  ModLoopCtr = 0U;
  #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
  QmModIndex = 0U;
  #endif
  do
  {
    if(Spi_lModuleConfiguredAndAsync((uint8)ModLoopCtr) != 0U)
    {
      #if (SPI_SAFETY_ENABLE == STD_ON)
      if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)ModLoopCtr))
      {
        DmaTransmitChannel = Spi_AsilChnlAccess[0U].DmaChannelIdx.TxDmaChannel;
        DmaReceiveChannel  = Spi_AsilChnlAccess[0U].DmaChannelIdx.RxDmaChannel;
      }
      else
      {
        #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
        DmaTransmitChannel = \
                       Spi_QmChnlAccess[QmModIndex].DmaChannelIdx.TxDmaChannel;
        DmaReceiveChannel  = \
                       Spi_QmChnlAccess[QmModIndex].DmaChannelIdx.RxDmaChannel;
        /* Increment only if  QM master module is configured as ASYNC  */
        QmModIndex++;
        #endif
      }
      #else
      {
        DmaTransmitChannel = \
                       Spi_QmChnlAccess[QmModIndex].DmaChannelIdx.TxDmaChannel;
        DmaReceiveChannel  = \
                       Spi_QmChnlAccess[QmModIndex].DmaChannelIdx.RxDmaChannel;
        /* Increment only if  QM master module is configured as ASYNC  */
        QmModIndex++;
      }
      #endif
      /* Reset Tx DMA channel specific SFRs */
      SPI_DMA_SFR_INIT_WRITE32(MODULE_DMA.CH[DmaTransmitChannel].\
                                                  ADICR.U,SPI_DMA_RESET_VALUE);
      SPI_DMA_SFR_INIT_WRITE32(MODULE_DMA.CH[DmaTransmitChannel].\
                                                  CHCSR.U,SPI_DMA_RESET_VALUE);
      /*Reserve bit access is ensured for DMA_TSRz register*/
      SPI_DMA_SFR_INIT_WRITE32(MODULE_DMA.TSR[DmaTransmitChannel].U,\
                                                        SPI_DMA_RESET_VALUE);
      SPI_DMA_SFR_INIT_WRITE32(MODULE_DMA.CH[DmaTransmitChannel].\
                                                    SADR.U,SPI_DMA_RESET_VALUE);
      SPI_DMA_SFR_INIT_WRITE32(MODULE_DMA.CH[DmaTransmitChannel].\
                                                CHCFGR.U,SPI_DMA_RESET_VALUE);
      SPI_DMA_SFR_INIT_WRITE32(MODULE_DMA.CH[DmaTransmitChannel].\
                                                    DADR.U,SPI_DMA_RESET_VALUE);
      /* Reset Rx DMA channel specific SFRs */
      SPI_DMA_SFR_INIT_WRITE32(MODULE_DMA.CH[DmaReceiveChannel].\
                                                ADICR.U,SPI_DMA_RESET_VALUE);
      SPI_DMA_SFR_INIT_WRITE32(MODULE_DMA.CH[DmaReceiveChannel].\
                                                CHCSR.U,SPI_DMA_RESET_VALUE);
      /*Reserve bit access is ensured for DMA_TSRz register*/
      SPI_DMA_SFR_INIT_WRITE32(MODULE_DMA.TSR[DmaReceiveChannel].\
                                                        U,SPI_DMA_RESET_VALUE);
      SPI_DMA_SFR_INIT_WRITE32(MODULE_DMA.CH[DmaReceiveChannel].SADR.\
                                                        U,SPI_DMA_RESET_VALUE);
      SPI_DMA_SFR_INIT_WRITE32(MODULE_DMA.CH[DmaReceiveChannel].CHCFGR\
                                                        .U,SPI_DMA_RESET_VALUE);
      SPI_DMA_SFR_INIT_WRITE32(MODULE_DMA.CH[DmaReceiveChannel].\
                                                    DADR.U,SPI_DMA_RESET_VALUE);
    }
    else
    {
      /* Do nothing if QSPI module is not configured */
    }
    ModLoopCtr++;
  }while (ModLoopCtr < SPI_MAX_HW_UNIT);
}
#endif /* Reset at Init ON */

/*******************************************************************************
** Syntax           : static void Spi_lHwDmaDeInit                            **
** (                                                                          **
**   void                                                                     **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : None.                                                   **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to De-Initialise Dma Hw used for Spi during    **
**                    Hw De-initialisation                                    **
*******************************************************************************/
static void Spi_lHwDmaDeInit(void)
{
  Dma_ChannelType dma_channelno_tx;
  Dma_ChannelType dma_channelno_rx;
  uint32 ModLoopCtr;
  #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
  uint32 QmModIndex;
  #endif

  #if((SPI_SAFETY_ENABLE == STD_ON) && (SPI_QM_ASYNC_MASTER_MODULES_USED ==0U))
  dma_channelno_tx = DMA_CHANNEL_INVALID;
  dma_channelno_rx = DMA_CHANNEL_INVALID;
  #endif

  ModLoopCtr = 0U;
  #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
  QmModIndex = 0U;
  #endif
  do
  {
    if(Spi_lModuleConfiguredAndAsync((uint8)ModLoopCtr) != 0U)
    {
      #if (SPI_SAFETY_ENABLE == STD_ON)
      if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)ModLoopCtr))
      {
        dma_channelno_tx  = Spi_AsilChnlAccess[0U].DmaChannelIdx.TxDmaChannel;
        dma_channelno_rx  = Spi_AsilChnlAccess[0U].DmaChannelIdx.RxDmaChannel;
      }
      else
      {
        #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
        dma_channelno_tx = \
                       Spi_QmChnlAccess[QmModIndex].DmaChannelIdx.TxDmaChannel;
        dma_channelno_rx  = \
                       Spi_QmChnlAccess[QmModIndex].DmaChannelIdx.RxDmaChannel;
        /* Increment only if  QM master module is configured as ASYNC  */
        QmModIndex++;
        #endif
      }
      #else
      {
        dma_channelno_tx = \
                       Spi_QmChnlAccess[QmModIndex].DmaChannelIdx.TxDmaChannel;
        dma_channelno_rx  = \
                       Spi_QmChnlAccess[QmModIndex].DmaChannelIdx.RxDmaChannel;
        /* Increment only if  QM master module is configured as ASYNC  */
        QmModIndex++;
      }
      #endif

      Spi_lDmaChClrCtlCfgDeinit(dma_channelno_rx);
      Spi_lDmaChClrCtlCfgDeinit(dma_channelno_tx);
      Spi_lDmaSetSourceAddr(dma_channelno_rx, 0U, SPI_DEINIT_ACCESS);
      Spi_lDmaSetSourceAddr(dma_channelno_tx, 0U, SPI_DEINIT_ACCESS);
      Spi_lDmaSetDestAddr(dma_channelno_rx, 0U, SPI_DEINIT_ACCESS);
      Spi_lDmaSetDestAddr(dma_channelno_tx, 0U, SPI_DEINIT_ACCESS);
      Spi_lDmaClrAdcr(dma_channelno_rx);
      Spi_lDmaClrAdcr(dma_channelno_tx);

      Spi_lDmaChClrIntctEtrlFlags(dma_channelno_rx);
      Spi_lDmaChClrIntctEtrlFlags(dma_channelno_tx);
      Spi_lDmaDisableChIntrTrigger(dma_channelno_rx);
      Spi_lDmaChClrIntrFlagsDeinit(dma_channelno_rx);
      Spi_lDmaChClrIntrFlagsDeinit(dma_channelno_tx);
      Spi_lHwDeInitDmaIntr_SV(ModLoopCtr);

      /* Clear DMA Error Status Reg for Transaction Lost Error */
      Spi_lDmaClrErrFlags(dma_channelno_rx);
      Spi_lDmaClrErrFlags(dma_channelno_tx);
    }
    else
    {
      /* Do nothing if QSPI module is not configured */
    }
    ModLoopCtr++;
  }while (ModLoopCtr < SPI_MAX_HW_UNIT);
  return ;
}

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Spi_lHwSendLastChannelData        **
** (                                                                          **
**   uint32 Module, uint8 ApiAccessId                                         **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : Module - Module no.                                     **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to update the Last word of a job in Qspi Hw.   **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lHwSendLastChannelData(uint32 Module, \
                                                              uint8 ApiAccessId)
{
  volatile uint32 Temp;
  Spi_ChnlAccessType *ChnlAccDataPtr;

  #if((SPI_SAFETY_ENABLE == STD_ON) && (SPI_QM_ASYNC_MASTER_MODULES_USED == 0U))
  ChnlAccDataPtr = NULL_PTR; /* To remove warning: Possibly Uninitialised*/
  #endif

  #if (SPI_SAFETY_ENABLE == STD_ON)
  if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)Module))
  {
    ChnlAccDataPtr = &Spi_AsilChnlAccess[0U];
  }
  else
  {
    #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
    ChnlAccDataPtr = &Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)];
    #endif
    /* Do nothing if QM modules are NOT Used */
  }
  #else
  {
    ChnlAccDataPtr = &Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)];
  }
  #endif

  if (ChnlAccDataPtr->LastChannelData.DataWidth & SPI_32BIT_DATAMASK)
  {
    Temp = (uint32)
            (*((uint32 *)(void *)ChnlAccDataPtr->LastChannelData.LastDataPtr));
    SPI_lHwUpdateSrcRegViaModule(Module, Temp, ApiAccessId);
  }
  else if (ChnlAccDataPtr->LastChannelData.DataWidth & SPI_16BIT_DATAMASK)
  {
    Temp = (uint32)(uint16)
            (*((uint16 *)(void *)ChnlAccDataPtr->LastChannelData.LastDataPtr));
    SPI_lHwUpdateSrcRegViaModule(Module, Temp, ApiAccessId);
  }
  else
  {
    Temp = (uint32)(uint8)
             (*((uint8 *)(void *)ChnlAccDataPtr->LastChannelData.LastDataPtr));
    SPI_lHwUpdateSrcRegViaModule(Module, Temp, ApiAccessId);
  }
}

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI020_7]                             **
** Syntax           : static void Spi_lHwDmaStartTransferRuntime              **
** (                                                                          **
**    const Spi_DataType* DmaTxSrcPtr, Spi_DataType* DmaRxDestPtr,            **
**    uint32 DmaTransferCount,                                                **
**    uint32 PackedVar,                                                       **
**    const Spi_JobConfigType* JobConfigPtr                                   **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  :                                                         **
**                    DmaTxSrcPtr - Tx-Dma Channel Source Pointer             **
**                    DmaRxDestPtr - Rx-Dma Channel Destination Pointer       **
**                    DmaTransferCount - Dma Transfer Count                   **
**                    LastChAndDataWidth - Packed variable                    **
**          PackedVar Lower 16 bits(0x0000FFFF) represent IsLastChannel       **
**          PackedVar bit16 to 23  (0x00FF0000) represent DataWidth           **
**          PackedVar bit24 to 31  (0xFF000000) represent Module              **
**                    JobConfigPtr - job pointer                              **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Start transfer of Dma Tx/Rx Channels.       **
*******************************************************************************/
static void Spi_lHwDmaStartTransferRuntime
(
const Spi_DataType* DmaTxSrcPtr, Spi_DataType* DmaRxDestPtr,
uint32 DmaTransferCount,
uint32 PackedVar,
const Spi_JobConfigType* JobConfigPtr
)
{
  Dma_ChannelType DmaRxChannel;
  Dma_ChannelType DmaTxChannel;
  uint32 DmaTxTransferCount;
  uint32 DmaRxAddressControlRegVal;
  uint32 DmaTxAddressControlRegVal;
  uint32 isDmaTxReqd;
  uint32 DmaDataWidth;
  uint16 DataWidth;
  uint8  IsLastChannel;
  uint32 Module;

  #if ((SPI_SAFETY_ENABLE == STD_ON) && (SPI_QM_ASYNC_MASTER_MODULES_USED ==0U))
  DmaTxChannel = DMA_CHANNEL_INVALID;
  DmaRxChannel = DMA_CHANNEL_INVALID;
  #endif

  Module        = (uint32)((PackedVar & SPI_MODULE_MASK ) >>
                                                         SPI_MODULE_SHIFTBITS);
  DataWidth     = (uint16) (PackedVar & SPI_LSB16BITS_MASK );
  IsLastChannel =  (uint8)((PackedVar & SPI_LASTCHNL_MASK) >>
                                                         SPI_LASTCH_SHIFTBITS);

   #if (SPI_SAFETY_ENABLE == STD_ON)
   if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)Module))
   {
      DmaTxChannel = Spi_AsilChnlAccess[0U].DmaChannelIdx.TxDmaChannel;
      DmaRxChannel = Spi_AsilChnlAccess[0U].DmaChannelIdx.RxDmaChannel;
   }
   else
   {
     #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
     DmaTxChannel = Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)].\
                                                    DmaChannelIdx.TxDmaChannel;
     DmaRxChannel = Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)].\
                                                    DmaChannelIdx.RxDmaChannel;
     #endif
     /* Do nothing if QM modules are NOT Used */
   }
   #else
   {
     DmaTxChannel = Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)].\
                                                    DmaChannelIdx.TxDmaChannel;
     DmaRxChannel = Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)].\
                                                    DmaChannelIdx.RxDmaChannel;
   }
   #endif

/* For LAST WORD of Last channel of current job, Set BACON.LAST =1
   Then only CS deactivation will happen otherwise, it waits for data. So
   last word transfer will be transmitted manually in Spi_IsrDmaQspiTx()

   For last channel, TX-DmaTransferCount will be one less and the
   Tx-Dma interrupt is activated if actual DmaTransfercount >1.
   If the DmaTransferCount = 1, then Dma for Tx channel is not used
   since it's the last word. Here data is transmitted manually
   by writing to Qspi src register

   RX-Dmatransfercount is actual always.
*/

    /* NOT Last channel */
  if (IsLastChannel == 0U)
  {
    /* Only Tx-Dma transfer is needed but
     TX-DMA Intr is not needed for Not Last Channel.
    */
    isDmaTxReqd = 1U;
    DmaTxTransferCount = DmaTransferCount;
  }
  else
  {
    if ( JobConfigPtr->ChannelBasedChipSelect == 0U )
    {
      DmaTxTransferCount = DmaTransferCount - SPI_TRANSFERCOUNT_ONE;
    }
    else
    {
      DmaTxTransferCount = DmaTransferCount ;
    }

    /* last channel with Transfer count > 1 */
    if (DmaTransferCount > SPI_TRANSFERCOUNT_ONE)
    {
      isDmaTxReqd = 1U;

      /* Enable TX-DMA Intr */
      Spi_lHwDmaClearIntr(DmaTxChannel);
      /* Set Interrupt Control */
      SPI_SFR_RUNTIME_MCAL_DMACFGINTCONTROL\
                                                (DmaTxChannel,SPI_DMA_INTCT);
      /* Channel Interrupt trigger activated */
      SPI_SFR_RUNTIME_MCAL_DMAENABLECHINTRTRIGGER(DmaTxChannel);
      #if (SPI_LEVEL_DELIVERED == 2U)
      if (Spi_AsyncMode != (uint8) SPI_POLLING_MODE)
      #endif
      {
        SPI_SFR_RUNTIME_MCAL_DMAENABLEINTR(DmaTxChannel);
        /* Enable DmaTxChannel Interrupt */
      }
    }
    else
    {
      /* last channel with TC =1, no need of TX-DMA.
         just 1 word transfer.
       */
      isDmaTxReqd = 0U;
    }
  }

  /*IFX_MISRA_RULE_11_01_STATUS=Typecasting DmaRxDestPtr to uint32 is
    unvoidable. DmaRxDestPtr is later used for SFR assignment.*/
  /*IFX_MISRA_RULE_11_03_STATUS=Type cast to uint32 is unavoidable*/
  SPI_SFR_RUNTIME_MCAL_DMASETDESTADDR(DmaRxChannel,(uint32)DmaRxDestPtr);

  DmaRxAddressControlRegVal = SPI_DMA_RX_ADRCR_NORML_TRANSFER;
  DmaTxAddressControlRegVal = SPI_DMA_TX_ADRCR_NORML_TRANSFER;
  #if (SPI_CHANNEL_BUFFERS_ALLOWED != 0U)
    /*IFX_MISRA_RULE_11_01_STATUS=Typecasting SPI_DMA_DUMMY_RX_ADDRESS to
      Spi_DataType * is unvoidable. SPI_DMA_DUMMY_RX_ADDRESS is later used
      for SFR assignment.*/
    /*IFX_MISRA_RULE_11_03_STATUS=Type cast to Spi_DataType * is unavoidable*/
    if (DmaRxDestPtr == (Spi_DataType *)SPI_DMA_DUMMY_RX_ADDRESS)
    {
      /* Dest Ptr is NULL. Read data is ignored */
      DmaRxAddressControlRegVal = SPI_DMA_RX_ADRCR_NULL_TRANSFER;
    }
    if (DmaTxSrcPtr == Spi_lGetDmaDummyTxAddress(Module))
    {
      /* Src Ptr is NULL. Configured Default Data is
         transmitted */
      DmaTxAddressControlRegVal = SPI_DMA_TX_ADRCR_NULL_TRANSFER;
    }
  #endif

  /* Set Address Ctr Reg RX*/
  SPI_SFR_RUNTIME_MCAL_DMASETADICR\
                                      (DmaRxChannel,DmaRxAddressControlRegVal);

  /* Clear Pending Interrupt */
  Spi_lHwDmaClearIntr(DmaRxChannel);

  if (isDmaTxReqd == 1U)
  {
    /* Set Address Ctr Reg TX*/
    SPI_SFR_RUNTIME_MCAL_DMASETADICR\
                                       (DmaTxChannel,DmaTxAddressControlRegVal);
  }

  if ( DataWidth & SPI_32BIT_DATAMASK)
  {
    DmaDataWidth = SPI_DMA_CHDW_32BIT;
  }
  else if ( DataWidth & SPI_16BIT_DATAMASK)
  {
    DmaDataWidth = SPI_DMA_CHDW_16BIT;
  }
  else
  {
    DmaDataWidth = SPI_DMA_CHDW_8BIT;
  }

  /* SetChannel Control Reg : RX */
  SPI_SFR_RUNTIME_MCAL_DMASETTXCOUNT(DmaRxChannel, DmaTransferCount);
  SPI_SFR_RUNTIME_MCAL_DMASETDATAWIDTH(DmaRxChannel, DmaDataWidth);

  /* SetChannel Control Reg : TX */
  if(isDmaTxReqd == 1U)
  {
    /* Note 960: Violates MISRA Required Rule 11.5
      attempt to cast away const/volatile from a pointer or reference
    */
    /*IFX_MISRA_RULE_11_01_STATUS=Typecasting DmaTxSrcPtr to uint32 is
      unvoidable. DmaTxSrcPtr is later used for SFR assignment.*/
    /*IFX_MISRA_RULE_11_03_STATUS=Type cast to uint32 * is unavoidable*/
    SPI_SFR_RUNTIME_MCAL_DMASETSOURCEADDR(DmaTxChannel,
                       (uint32)((const uint32 *)(const void *)DmaTxSrcPtr));

    SPI_SFR_RUNTIME_MCAL_DMASETTXCOUNT(DmaTxChannel,DmaTxTransferCount);
    SPI_SFR_RUNTIME_MCAL_DMASETDATAWIDTH(DmaTxChannel,DmaDataWidth);
  }

  /* Set Hardware Trigger Request on the Channels */
  SPI_SFR_RUNTIME_MCAL_DMAENABLEHWTRANSFER(DmaRxChannel);

  if (isDmaTxReqd == 1U)
  {
    SPI_SFR_RUNTIME_MCAL_DMAENABLEHWTRANSFER(DmaTxChannel);

    /* Manual QSPI TX intr trigger. This triggers the Tx-Dma transfer.
      This is required since the QSPI Tx interrupt is triggered only if the
      Data is shifted from FIFO to shift register,
      which requires to write the first data into FIFO.
    */
    Spi_lHwSetQspiTxIntr(Module);
  }
  else
  {
    /* Send the data. */
    Spi_lHwUpdateSourceReg(Module, DataWidth, DmaTxSrcPtr, SPI_RUNTIME_ACCESS);
  }
}

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_SPI020_7]                             **
** Syntax           : static void Spi_lHwDmaStartTransferIsr                  **
** (                                                                          **
**    const Spi_DataType* DmaTxSrcPtr, Spi_DataType* DmaRxDestPtr,            **
**    uint32 DmaTransferCount,                                                **
**    uint32 PackedVar,                                                       **
**    const Spi_JobConfigType* JobConfigPtr                                   **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  :                                                         **
**                    DmaTxSrcPtr - Tx-Dma Channel Source Pointer             **
**                    DmaRxDestPtr - Rx-Dma Channel Destination Pointer       **
**                    DmaTransferCount - Dma Transfer Count                   **
**                    LastChAndDataWidth - Packed variable                    **
**          PackedVar Lower 16 bits(0x0000FFFF) represent IsLastChannel       **
**          PackedVar bit16 to 23  (0x00FF0000) represent DataWidth           **
**          PackedVar bit24 to 31  (0xFF000000) represent Module              **
**                    JobConfigPtr - job pointer                              **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Start transfer of Dma Tx/Rx Channels.       **
*******************************************************************************/
static void Spi_lHwDmaStartTransferIsr
(
const Spi_DataType* DmaTxSrcPtr, Spi_DataType* DmaRxDestPtr,
uint32 DmaTransferCount,
uint32 PackedVar,
const Spi_JobConfigType* JobConfigPtr
)
{
  Dma_ChannelType DmaRxChannel;
  Dma_ChannelType DmaTxChannel;
  uint32 DmaTxTransferCount;
  uint32 DmaRxAddressControlRegVal;
  uint32 DmaTxAddressControlRegVal;
  uint32 isDmaTxReqd;
  uint32 DmaDataWidth;
  uint16 DataWidth;
  uint8  IsLastChannel;
  uint32 Module;

  #if ((SPI_SAFETY_ENABLE == STD_ON) && (SPI_QM_ASYNC_MASTER_MODULES_USED ==0U))
  DmaTxChannel = DMA_CHANNEL_INVALID;
  DmaRxChannel = DMA_CHANNEL_INVALID;
  #endif

  Module        = (uint32)((PackedVar & SPI_MODULE_MASK ) >>
                                                         SPI_MODULE_SHIFTBITS);
  DataWidth     = (uint16) (PackedVar & SPI_LSB16BITS_MASK );
  IsLastChannel =  (uint8)((PackedVar & SPI_LASTCHNL_MASK) >>
                                                         SPI_LASTCH_SHIFTBITS);

   #if (SPI_SAFETY_ENABLE == STD_ON)
   if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)Module))
   {
      DmaTxChannel = Spi_AsilChnlAccess[0U].DmaChannelIdx.TxDmaChannel;
      DmaRxChannel = Spi_AsilChnlAccess[0U].DmaChannelIdx.RxDmaChannel;
   }
   else
   {
     #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
     DmaTxChannel = Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)].\
                                                    DmaChannelIdx.TxDmaChannel;
     DmaRxChannel = Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)].\
                                                    DmaChannelIdx.RxDmaChannel;
     #endif
     /* Do nothing if QM modules are NOT Used */
   }
   #else
   {
     DmaTxChannel = Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)].\
                                                    DmaChannelIdx.TxDmaChannel;
     DmaRxChannel = Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)].\
                                                    DmaChannelIdx.RxDmaChannel;
   }
   #endif

/* For LAST WORD of Last channel of current job, Set BACON.LAST =1
   Then only CS deactivation will happen otherwise, it waits for data. So
   last word transfer will be transmitted manually in Spi_IsrDmaQspiTx()

   For last channel, TX-DmaTransferCount will be one less and the
   Tx-Dma interrupt is activated if actual DmaTransfercount >1.
   If the DmaTransferCount = 1, then Dma for Tx channel is not used
   since it's the last word. Here data is transmitted manually
   by writing to Qspi src register

   RX-Dmatransfercount is actual always.
*/

    /* NOT Last channel */
  if (IsLastChannel == 0U)
  {
    /* Only Tx-Dma transfer is needed but
     TX-DMA Intr is not needed for Not Last Channel.
    */
    isDmaTxReqd = 1U;
    DmaTxTransferCount = DmaTransferCount;
  }
  else
  {
    if ( JobConfigPtr->ChannelBasedChipSelect == 0U )
    {
      DmaTxTransferCount = DmaTransferCount - SPI_TRANSFERCOUNT_ONE;
    }
    else
    {
      DmaTxTransferCount = DmaTransferCount ;
    }

    /* last channel with Transfer count > 1 */
    if (DmaTransferCount > SPI_TRANSFERCOUNT_ONE)
    {
      isDmaTxReqd = 1U;

      /* Enable TX-DMA Intr */
      Spi_lHwDmaClearIntr(DmaTxChannel);
      /* Set Interrupt Control */
      Mcal_DmaCfgIntControl(DmaTxChannel,SPI_DMA_INTCT);
      /* Channel Interrupt trigger activated */
      Mcal_DmaEnableChIntrTrigger(DmaTxChannel);
      /* Enable DmaTxChannel Interrupt */
      Mcal_DmaEnableIntr(DmaTxChannel);
    }
    else
    {
      /* last channel with TC =1, no need of TX-DMA.
         just 1 word transfer.
       */
      isDmaTxReqd = 0U;
    }
  }

  /*IFX_MISRA_RULE_11_01_STATUS=Typecasting DmaRxDestPtr to uint32 is
    unvoidable. DmaRxDestPtr is later used for SFR assignment.*/
  /*IFX_MISRA_RULE_11_03_STATUS=Type cast to uint32 is unavoidable*/
  Mcal_DmaSetDestAddr(DmaRxChannel, (uint32)DmaRxDestPtr);

  DmaRxAddressControlRegVal = SPI_DMA_RX_ADRCR_NORML_TRANSFER;
  DmaTxAddressControlRegVal = SPI_DMA_TX_ADRCR_NORML_TRANSFER;
  #if (SPI_CHANNEL_BUFFERS_ALLOWED != 0U)
    /*IFX_MISRA_RULE_11_01_STATUS=Typecasting SPI_DMA_DUMMY_RX_ADDRESS to
      Spi_DataType * is unvoidable. SPI_DMA_DUMMY_RX_ADDRESS is later used
      for SFR assignment.*/
    /*IFX_MISRA_RULE_11_03_STATUS=Type cast to Spi_DataType * is unavoidable*/
    if (DmaRxDestPtr == (Spi_DataType *)SPI_DMA_DUMMY_RX_ADDRESS)
    {
      /* Dest Ptr is NULL. Read data is ignored */
      DmaRxAddressControlRegVal = SPI_DMA_RX_ADRCR_NULL_TRANSFER;
    }
    if (DmaTxSrcPtr == Spi_lGetDmaDummyTxAddress(Module))
    {
      /* Src Ptr is NULL. Configured Default Data is
         transmitted */
      DmaTxAddressControlRegVal = SPI_DMA_TX_ADRCR_NULL_TRANSFER;
    }
  #endif

  /* Set Address Ctr Reg RX*/
  Mcal_DmaSetAdicr(DmaRxChannel, DmaRxAddressControlRegVal);

  /* Clear Pending Interrupt */
  Spi_lHwDmaClearIntr(DmaRxChannel);

  if (isDmaTxReqd == 1U)
  {
    /* Set Address Ctr Reg TX*/
    Mcal_DmaSetAdicr(DmaTxChannel, DmaTxAddressControlRegVal);
  }

  if ( DataWidth & SPI_32BIT_DATAMASK)
  {
    DmaDataWidth = SPI_DMA_CHDW_32BIT;
  }
  else if ( DataWidth & SPI_16BIT_DATAMASK)
  {
    DmaDataWidth = SPI_DMA_CHDW_16BIT;
  }
  else
  {
    DmaDataWidth = SPI_DMA_CHDW_8BIT;
  }

  /* SetChannel Control Reg : RX */
  Mcal_DmaSetTxCount(DmaRxChannel, DmaTransferCount);
  Mcal_DmaSetDataWidth(DmaRxChannel, DmaDataWidth);

  /* SetChannel Control Reg : TX */
  if(isDmaTxReqd == 1U)
  {
    /* Note 960: Violates MISRA Required Rule 11.5
      attempt to cast away const/volatile from a pointer or reference
    */
    /*IFX_MISRA_RULE_11_01_STATUS=Typecasting DmaTxSrcPtr to uint32 is
      unvoidable. DmaTxSrcPtr is later used for SFR assignment.*/
    /*IFX_MISRA_RULE_11_03_STATUS=Type cast to uint32 * is unavoidable*/
    Mcal_DmaSetSourceAddr(DmaTxChannel,
                       (uint32)((const uint32 *)(const void *)DmaTxSrcPtr));

    Mcal_DmaSetTxCount(DmaTxChannel, DmaTxTransferCount);
    Mcal_DmaSetDataWidth(DmaTxChannel, DmaDataWidth);
  }

  /* Set Hardware Trigger Request on the Channels */
  Mcal_DmaEnableHwTransfer(DmaRxChannel);

  if (isDmaTxReqd == 1U)
  {
    Mcal_DmaEnableHwTransfer(DmaTxChannel);

    /* Manual QSPI TX intr trigger. This triggers the Tx-Dma transfer.
      This is required since the QSPI Tx interrupt is triggered only if the
      Data is shifted from FIFO to shift register,
      which requires to write the first data into FIFO.
    */
    Spi_lHwSetQspiTxIntr(Module);
  }
  else
  {
    /* Send the data. */
    Spi_lHwUpdateSourceReg(Module, DataWidth, DmaTxSrcPtr, SPI_ISR_ACCESS);
  }
}
/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Spi_lHwUpdateSourceReg            **
** (                                                                          **
**   uint32 Module,                                                           **
**   uint16 DataWidth,                                                        **
**   const Spi_DataType* DmaTxSrcPtr,                                         **
**   uint8 ApiAccessId                                                        **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw Module.                                     **
**                    DmaTxSrcPtr - Tx-Dma Channel Source Pointer             **
**                    DataWidth - DataWidth of Tx/Rx Dma channels             **
                      ApiAccessId   - API access type                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to write the QSPI TX Fifo based on Datawidth.  **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lHwUpdateSourceReg(uint32 Module, uint16 DataWidth,
                             const Spi_DataType* DmaTxSrcPtr, uint8 ApiAccessId)
{
   /* Note 960: Violates MISRA Required Rule 11.5
     attempt to cast away const/volatile from a pointer or reference
    */
    if (DataWidth & SPI_32BIT_DATAMASK)
    {
      SPI_lHwUpdateSrcRegViaModule(Module,
                     *((const uint32 *)(const void *)DmaTxSrcPtr), ApiAccessId);
    }
    else if (DataWidth & SPI_16BIT_DATAMASK)
    {
      SPI_lHwUpdateSrcRegViaModule(Module,
      (uint32)(uint16)(*((const uint16 *)(const void *)DmaTxSrcPtr)), \
                                                                   ApiAccessId);
    }
    else
    {
      SPI_lHwUpdateSrcRegViaModule(Module,
           (uint32)(uint8) (*((const uint8 *)(const void *)DmaTxSrcPtr)), \
                                                                   ApiAccessId);
    }
}

/*******************************************************************************
**                            Dma Interrupt Configuration Apis                **
*******************************************************************************/
/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Spi_lHwInitDmaIntr                **
** (                                                                          **
**   uint32 Module                                                            **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Initialise Dma Hw Interrupts                **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lHwInitDmaIntr(uint32 Module)
{
  uint32 TxChannelOffset;
  uint32 RxChannelOffset;
  volatile uint32 *DmaChAddr;

  #if((SPI_SAFETY_ENABLE == STD_ON) && (SPI_QM_ASYNC_MASTER_MODULES_USED ==0U))
  RxChannelOffset = (uint32)DMA_CHANNEL_INVALID;
  TxChannelOffset = (uint32)DMA_CHANNEL_INVALID;
  #endif

  #if (SPI_SAFETY_ENABLE == STD_ON)
  if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)Module))
  {
    TxChannelOffset = (uint32)Spi_AsilChnlAccess[0U].DmaChannelIdx.TxDmaChannel;
    RxChannelOffset = (uint32)Spi_AsilChnlAccess[0U].DmaChannelIdx.RxDmaChannel;
  }
  else
  {
    #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
    TxChannelOffset = (uint32)Spi_QmChnlAccess[\
                  Spi_lGetQmModuleVarIndex(Module)].DmaChannelIdx.TxDmaChannel;
    RxChannelOffset = (uint32)Spi_QmChnlAccess[\
                  Spi_lGetQmModuleVarIndex(Module)].DmaChannelIdx.RxDmaChannel;
    #endif
    /* Do nothing if QM modules are NOT Used */
  }
  #else
  {
    TxChannelOffset = (uint32)Spi_QmChnlAccess[\
                  Spi_lGetQmModuleVarIndex(Module)].DmaChannelIdx.TxDmaChannel;
    RxChannelOffset = (uint32)Spi_QmChnlAccess[\
                  Spi_lGetQmModuleVarIndex(Module)].DmaChannelIdx.RxDmaChannel;
  }
  #endif

  /*IFX_MISRA_RULE_17_04_STATUS="SRC_DMACH0ADDR" Pointer arithmetic is used
   to efficiently access the SFRs of multiple QSPI Modules.*/
  DmaChAddr = (volatile uint32 *)(volatile void *)(SRC_DMACH0ADDR +           \
                                                         RxChannelOffset);

  /* Set SRC.IOVCLR, SRC.SWSCLR, SRC.CLRR, SRC.SRE*/

  SPI_IRQ_SFR_RUNTIME_MODIFY32(*DmaChAddr,SPI_DMACHADDR_CLEARMASK,\
                                                          SPI_DMACHADDR_SETMASK)

  SPI_IRQ_SFR_RUNTIME_MODIFY32(*DmaChAddr,SPI_DMACHADDR_CLEARMASK,\
                                                         SPI_DMACHADDR_SETMASK1)

  /*IFX_MISRA_RULE_17_04_STATUS="SRC_DMACH0ADDR" Pointer arithmetic is used
    to efficiently access the SFRs of multiple QSPI Modules.*/
  DmaChAddr = (volatile uint32 *)(volatile void *)(SRC_DMACH0ADDR +           \
                                                         TxChannelOffset);

    /* Set SRC.IOVCLR, SRC.SWSCLR, SRC.CLRR */
    /* Clear SRC.SRE */
   SPI_IRQ_SFR_RUNTIME_MODIFY32(*DmaChAddr,SPI_DMACHADDR_CLEARMASK1,\
                                                          SPI_DMACHADDR_SETMASK)
}

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Spi_lHwInitDmaIntr_SV             **
** (                                                                          **
**   uint32 Module                                                            **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Initialise Dma Hw Interrupts                **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lHwInitDmaIntr_SV(uint32 Module)
{
  /*Ifx_SRC_SRCR_Bits IntrSrc;*/
  uint32 TxChannelOffset,IntrSrc;
  uint32 RxChannelOffset;
  volatile Ifx_SRC_SRCR_Bits *MoveEngCh0BaseAddr;

  #if ((SPI_SAFETY_ENABLE == STD_ON) && (SPI_QM_ASYNC_MASTER_MODULES_USED ==0U))
  RxChannelOffset = (uint32)DMA_CHANNEL_INVALID;
  TxChannelOffset = (uint32)DMA_CHANNEL_INVALID;
  #endif

  #if (SPI_SAFETY_ENABLE == STD_ON)
  if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)Module))
  {
    TxChannelOffset = (uint32)Spi_AsilChnlAccess[0U].DmaChannelIdx.TxDmaChannel;
    RxChannelOffset = (uint32)Spi_AsilChnlAccess[0U].DmaChannelIdx.RxDmaChannel;
  }
  else
  {
    #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
    TxChannelOffset = (uint32)Spi_QmChnlAccess[\
                  Spi_lGetQmModuleVarIndex(Module)].DmaChannelIdx.TxDmaChannel;
    RxChannelOffset = (uint32)Spi_QmChnlAccess[\
                  Spi_lGetQmModuleVarIndex(Module)].DmaChannelIdx.RxDmaChannel;
    #endif
    /* Do nothing if QM modules are NOT Used */
  }
  #else
  {
    TxChannelOffset = (uint32)Spi_QmChnlAccess[\
                  Spi_lGetQmModuleVarIndex(Module)].DmaChannelIdx.TxDmaChannel;
    RxChannelOffset = (uint32)Spi_QmChnlAccess[\
                  Spi_lGetQmModuleVarIndex(Module)].DmaChannelIdx.RxDmaChannel;
  }
  #endif

  MoveEngCh0BaseAddr = SRC_DMACH0ADDR;

  /*IFX_MISRA_RULE_17_04_STATUS="MoveEngCh0BaseAddr" Pointer arithmetic is used
    to efficiently access the SFRs of multiple QSPI Modules.*/
  IntrSrc = SPI_IRQ_SFR_INIT_USER_MODE_READ32(*((volatile uint32*)\
                         (volatile void*)MoveEngCh0BaseAddr + RxChannelOffset));
  /*IntrSrc.CLRR = 1U;
  IntrSrc.SWSCLR = 1U;
  IntrSrc.IOVCLR = 1U;
  IntrSrc.SRE = 1U;*/ /*  Enable intr */
  IntrSrc |= SPI_SRC_DMACH0_SWSCLR_IOVCLR_SETMASK;
  IntrSrc &= SPI_SRC_DMACH0_CLEARMASK;

  /*IFX_MISRA_RULE_17_04_STATUS="MoveEngCh0BaseAddr" Pointer arithmetic is used
    to efficiently access the SFRs of multiple QSPI Modules.*/
  SPI_IRQ_SFR_INIT_WRITE32(*((volatile uint32 *)(volatile void *)\
                                MoveEngCh0BaseAddr + RxChannelOffset), IntrSrc);

  /*IFX_MISRA_RULE_17_04_STATUS="MoveEngCh0BaseAddr" Pointer arithmetic is used
    to efficiently access the SFRs of multiple QSPI Modules.*/
  IntrSrc = SPI_IRQ_SFR_INIT_USER_MODE_READ32(*((volatile uint32 *)\
                        (volatile void *)MoveEngCh0BaseAddr + TxChannelOffset));
  /*IntrSrc.CLRR = 1U;
  IntrSrc.SWSCLR = 1U;
  IntrSrc.IOVCLR = 1U;
  IntrSrc.SRE = 0U;*/ /*  Disable intr */
  IntrSrc |= SPI_SRC_DMACH0_SWSCLR_IOVCLR_SETMASK;
  IntrSrc &= SPI_SRC_DMACH0_SRE_CLEARMASK;

  /*IFX_MISRA_RULE_17_04_STATUS="MoveEngCh0BaseAddr" Pointer arithmetic is used
    to efficiently access the SFRs of multiple QSPI Modules.*/
  SPI_IRQ_SFR_INIT_WRITE32(*((volatile uint32 *)(volatile void *)\
                                MoveEngCh0BaseAddr + TxChannelOffset), IntrSrc);
}

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Spi_lHwDeInitDmaIntr              **
** (                                                                          **
**   uint32 Module                                                            **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to De-Initialise Dma Hw Interrupts             **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lHwDeInitDmaIntr(uint32 Module)
{
  uint32 TxChannelOffset;
  uint32 RxChannelOffset;
  volatile uint32 *DmaChAddr;

  #if((SPI_SAFETY_ENABLE == STD_ON) && (SPI_QM_ASYNC_MASTER_MODULES_USED ==0U))
  TxChannelOffset = (uint32)DMA_CHANNEL_INVALID;
  RxChannelOffset = (uint32)DMA_CHANNEL_INVALID;
  #endif

  #if (SPI_SAFETY_ENABLE == STD_ON)
  if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)Module))
  {
    TxChannelOffset = (uint32)Spi_AsilChnlAccess[0].DmaChannelIdx.TxDmaChannel;
    RxChannelOffset = (uint32)Spi_AsilChnlAccess[0].DmaChannelIdx.RxDmaChannel;
  }
  else
  {
    #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
    TxChannelOffset = (uint32)Spi_QmChnlAccess[\
                  Spi_lGetQmModuleVarIndex(Module)].DmaChannelIdx.TxDmaChannel;
    RxChannelOffset = (uint32)Spi_QmChnlAccess[\
                  Spi_lGetQmModuleVarIndex(Module)].DmaChannelIdx.RxDmaChannel;
    #endif
    /* Do nothing if QM modules are NOT Used */
  }
  #else
  {
    TxChannelOffset = (uint32)Spi_QmChnlAccess[\
                  Spi_lGetQmModuleVarIndex(Module)].DmaChannelIdx.TxDmaChannel;
    RxChannelOffset = (uint32)Spi_QmChnlAccess[\
                  Spi_lGetQmModuleVarIndex(Module)].DmaChannelIdx.RxDmaChannel;
  }
  #endif

  /*IFX_MISRA_RULE_17_04_STATUS="SRC_DMACH0ADDR" Pointer arithmetic is used
     to efficiently access the SFRs of multiple QSPI Modules.*/
  DmaChAddr = (volatile uint32 *)(volatile void *)(SRC_DMACH0ADDR +           \
                                                         RxChannelOffset);

  /* Set SRC.IOVCLR, SRC.SWSCLR, SRC.CLRR */
  /* Clear SRC.SRE */

  SPI_IRQ_SFR_RUNTIME_MODIFY32(*DmaChAddr,SPI_DMACHADDR_CLEARMASK1,\
                                                        SPI_DMACHADDR_SETMASK)

  /*IFX_MISRA_RULE_17_04_STATUS="SRC_DMACH0ADDR" Pointer arithmetic is used
     to efficiently access the SFRs of multiple QSPI Modules.*/
  DmaChAddr = (volatile uint32 *)(volatile void *)(SRC_DMACH0ADDR +           \
                                                         TxChannelOffset);

  SPI_IRQ_SFR_RUNTIME_MODIFY32(*DmaChAddr,SPI_DMACHADDR_CLEARMASK1,\
                                                        SPI_DMACHADDR_SETMASK)
}

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Spi_lHwDeInitDmaIntr_SV           **
** (                                                                          **
**   uint32 Module                                                            **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to De-Initialise Dma Hw Interrupts             **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lHwDeInitDmaIntr_SV(uint32 Module)
{
  /*Ifx_SRC_SRCR_Bits IntrSrc;*/
  uint32 TxChannelOffset,IntrSrc;
  uint32 RxChannelOffset;
  volatile Ifx_SRC_SRCR_Bits *MoveEngCh0BaseAddr;

  #if ((SPI_SAFETY_ENABLE == STD_ON) && (SPI_QM_ASYNC_MASTER_MODULES_USED ==0U))
  TxChannelOffset = (uint32)DMA_CHANNEL_INVALID;
  RxChannelOffset = (uint32)DMA_CHANNEL_INVALID;
  #endif

  #if (SPI_SAFETY_ENABLE == STD_ON)
  if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)Module))
  {
     TxChannelOffset = (uint32)Spi_AsilChnlAccess[0].DmaChannelIdx.TxDmaChannel;
     RxChannelOffset = (uint32)Spi_AsilChnlAccess[0].DmaChannelIdx.RxDmaChannel;
  }
  else
  {
    #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
    TxChannelOffset = (uint32)Spi_QmChnlAccess[\
                  Spi_lGetQmModuleVarIndex(Module)].DmaChannelIdx.TxDmaChannel;
    RxChannelOffset = (uint32)Spi_QmChnlAccess[\
                  Spi_lGetQmModuleVarIndex(Module)].DmaChannelIdx.RxDmaChannel;
    #endif
    /* Do nothing if QM modules are NOT Used */
  }
  #else
  {
    TxChannelOffset = (uint32)Spi_QmChnlAccess[\
                  Spi_lGetQmModuleVarIndex(Module)].DmaChannelIdx.TxDmaChannel;
    RxChannelOffset = (uint32)Spi_QmChnlAccess[\
                  Spi_lGetQmModuleVarIndex(Module)].DmaChannelIdx.RxDmaChannel;
  }
  #endif

  MoveEngCh0BaseAddr = SRC_DMACH0ADDR;

  /*IFX_MISRA_RULE_17_04_STATUS="MoveEngCh0BaseAddr" Pointer arithmetic is used
    to efficiently access the SFRs of multiple QSPI Modules.*/
  IntrSrc = SPI_IRQ_SFR_DEINIT_USER_MODE_READ32(*((volatile uint32*)\
                        (volatile void*)MoveEngCh0BaseAddr + RxChannelOffset));
  /*IntrSrc.CLRR = 1U;  Clear SRR
  IntrSrc.SRE = 0U;*/
  IntrSrc |= SPI_SRC_DMACH0_CLRR_SETMASK;
  IntrSrc &= SPI_SRC_DMACH0_SRE_CLEARMASK;
  /*IFX_MISRA_RULE_17_04_STATUS="MoveEngCh0BaseAddr" Pointer arithmetic is used
    to efficiently access the SFRs of multiple QSPI Modules.*/
  SPI_IRQ_SFR_DEINIT_WRITE32(*((volatile uint32*)\
                (volatile void*)MoveEngCh0BaseAddr + RxChannelOffset),IntrSrc);

  /*IFX_MISRA_RULE_17_04_STATUS="MoveEngCh0BaseAddr" Pointer arithmetic is used
    to efficiently access the SFRs of multiple QSPI Modules.*/
  IntrSrc = SPI_IRQ_SFR_DEINIT_USER_MODE_READ32(*((volatile uint32*)\
                        (volatile void*)MoveEngCh0BaseAddr + TxChannelOffset));
  /*IntrSrc.CLRR = 1U;  Clear SRR
  IntrSrc.SRE = 0U;*/
  IntrSrc |= SPI_SRC_DMACH0_CLRR_SETMASK;
  IntrSrc &= SPI_SRC_DMACH0_SRE_CLEARMASK;
  /*IFX_MISRA_RULE_17_04_STATUS="MoveEngCh0BaseAddr" Pointer arithmetic is used
    to efficiently access the SFRs of multiple QSPI Modules.*/
  SPI_IRQ_SFR_DEINIT_WRITE32(*((volatile uint32 *)(volatile void *)\
                                 MoveEngCh0BaseAddr + TxChannelOffset),IntrSrc);
}

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Spi_lHwDmaClearIntr               **
** (                                                                          **
**   uint32 Module                                                            **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Hw module no.                                  **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to Clear Dma Hw channel Interrupt              **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lHwDmaClearIntr(Dma_ChannelType Channel)
{
  /*Ifx_SRC_SRCR_Bits IntrSrc;*/
  uint32 IntrSrc;
  volatile Ifx_SRC_SRCR_Bits *MoveEngCh0BaseAddr;
  volatile uint32 *RegAddress;
  SPI_SFR_RUNTIME_MCAL_DMACHCLRINTCTETRLFLAGS(Channel);
  SPI_SFR_RUNTIME_MCAL_DMACHCLRINTRFLAGS(Channel);
  /* Set Interrupt Control */
  SPI_SFR_RUNTIME_MCAL_DMACFGINTCONTROL(Channel,SPI_DMA_INTCT);

  MoveEngCh0BaseAddr = SRC_DMACH0ADDR;

  /*IFX_MISRA_RULE_17_04_STATUS="MoveEngCh0BaseAddr" Pointer arithmetic is used
    to efficiently access the SFRs of multiple QSPI Modules.*/
  IntrSrc = SPI_IRQ_SFR_RUNTIME_USER_MODE_READ32(*((volatile uint32*)\
                          (volatile void*)MoveEngCh0BaseAddr + (uint8)Channel));
  if (((IntrSrc & SPI_SRC_DMACH0_SRR_CHECKMASK)\
                                             >>SPI_SRC_DMACH0_SRR_BITPOS) == 1U)
  {
    /* IntrSrc.CLRR = 1U; */
  /*IFX_MISRA_RULE_17_04_STATUS="MoveEngCh0BaseAddr" Pointer arithmetic is used
     to efficiently access the SFRs of multiple QSPI Modules.*/
    MoveEngCh0BaseAddr =
    ((volatile Ifx_SRC_SRCR_Bits*)(volatile void*)MoveEngCh0BaseAddr +   \
                                                         (uint8)Channel);
    RegAddress = ((volatile uint32*)(volatile void*)MoveEngCh0BaseAddr);
    SPI_IRQ_SFR_RUNTIME_MODIFY32(*RegAddress,SPI_REGADDRESS_CLEARMASK,\
                                                        SPI_REGADDRESS_SETMASK)
  }
}

/*******************************************************************************
** Traceability     :                                                         **
** Syntax           : static void Spi_lDmaSetSourceAddr                       **
** (                                                                          **
**   Dma_ChannelType Channel, uint32 Address, uint8 ApiAccessId               **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Channel - Dma channel no.                               **
**                    Address - Source address                                **
                      ApiAccessId - API access type                           **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Update the Dma Source address register.                 **
*******************************************************************************/
static void Spi_lDmaSetSourceAddr(Dma_ChannelType Channel,
                                              uint32 Address, uint8 ApiAccessId)
{
  uint32 RemapAddress;
  RemapAddress = Mcal_GetDsprReMapAddress(Address);
  if (ApiAccessId == SPI_INIT_ACCESS)
  {
    SPI_DMA_SFR_INIT_WRITE32(MODULE_DMA.CH[Channel].SADR.U,\
                                                        (uint32)RemapAddress);
  }
  else
  {
    SPI_DMA_SFR_DEINIT_WRITE32(MODULE_DMA.CH[Channel].SADR.U,\
                                                        (uint32)RemapAddress);
  }
}

/*******************************************************************************
** Traceability     :                                                         **
** Syntax           :  IFX_LOCAL_INLINE void Spi_lDmaChClrCtlCfgInit          **
** (                                                                          **
**   Dma_ChannelType Channel                                                  **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Channel - Dma channel no.                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Clear the bitfields pertaining to different Channel     **
**                    control registers.                                      **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lDmaChClrCtlCfgInit(Dma_ChannelType Channel)
{
  uint32 ltemp;

  SPI_DMA_SFR_INIT_WRITE32(MODULE_DMA.CH[Channel].CHCFGR.U,\
                                                    SPI_DMA_CHCFGR_RESETVAL);
   /*Reserve bit access is ensured for DMA_CHCSRz register*/
  SPI_DMA_SFR_INIT_MODIFY32(MODULE_DMA.CH[Channel].CHCSR.U,\
                                                SPI_DMA_CHCSR_SCH_CLR_MASK,0U)

  ltemp = (uint32)SPI_DMA_SFR_INIT_USER_MODE_READ32(MODULE_DMA.TSR[Channel].U);
  /* Clear ECH bit, Set DCH bit */
  ltemp &= (uint32)(~((uint32)1U << IFX_DMA_TSR_ECH_OFF));
  ltemp |= ((uint32)1U << IFX_DMA_TSR_DCH_OFF);
  /* Reset */
  /*Reserve bit access is ensured for DMA_TSRz register*/
  SPI_DMA_SFR_INIT_WRITE32(MODULE_DMA.TSR[Channel].U,ltemp);
}
/*******************************************************************************
** Traceability     :                                                         **
** Syntax           :  IFX_LOCAL_INLINE void Spi_lDmaChClrCtlCfgDeinit        **
** (                                                                          **
**   Dma_ChannelType Channel                                                  **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Channel - Dma channel no.                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Clear the bitfields pertaining to different Channel     **
**                    control registers.                                      **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lDmaChClrCtlCfgDeinit(Dma_ChannelType Channel)
{
  uint32 ltemp;

  SPI_DMA_SFR_DEINIT_WRITE32(MODULE_DMA.CH[Channel].CHCFGR.U,\
                                                    SPI_DMA_CHCFGR_RESETVAL);
   /*Reserve bit access is ensured for DMA_CHCSRz register*/
  SPI_DMA_SFR_DEINIT_MODIFY32(MODULE_DMA.CH[Channel].CHCSR.U,\
                                                SPI_DMA_CHCSR_SCH_CLR_MASK,0U)

  ltemp =\
  (uint32)SPI_DMA_SFR_DEINIT_USER_MODE_READ32(MODULE_DMA.TSR[Channel].U);
  /* Clear ECH bit, Set DCH bit */
  ltemp &= (uint32)(~((uint32)1U << IFX_DMA_TSR_ECH_OFF));
  ltemp |= ((uint32)1U << IFX_DMA_TSR_DCH_OFF);
  /* Reset */
  /*Reserve bit access is ensured for DMA_TSRz register*/
  SPI_DMA_SFR_DEINIT_WRITE32(MODULE_DMA.TSR[Channel].U,ltemp);
}
/*******************************************************************************
** Traceability     :                                                         **
** Syntax           : static void Spi_lDmaSetDestAddr                         **
** (                                                                          **
**   Dma_ChannelType Channel, uint32 Address, uint8 ApiAccessId               **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Channel - Dma channel no.                               **
**                    Address - Destination address                           **
**                    ApiAccessId - API access type                           **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Update the Dma Destination address register.            **
*******************************************************************************/
static void Spi_lDmaSetDestAddr(Dma_ChannelType Channel,
                                              uint32 Address, uint8 ApiAccessId)
{
  uint32 RemapAddress;
  RemapAddress = (uint32)Mcal_GetDsprReMapAddress(Address);
  if (ApiAccessId == SPI_INIT_ACCESS)
  {
    SPI_DMA_SFR_INIT_WRITE32(MODULE_DMA.CH[Channel].DADR.U,\
                                                        (uint32)RemapAddress);
  }
  else
  {
    SPI_DMA_SFR_DEINIT_WRITE32(MODULE_DMA.CH[Channel].DADR.U,\
                                                        (uint32)RemapAddress);
  }
}

/*******************************************************************************
** Traceability     :                                                         **
** Syntax           :  IFX_LOCAL_INLINE void Spi_lDmaChClrIntrFlagsInit       **
** (                                                                          **
**   Dma_ChannelType Channel                                                  **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Channel - Dma channel no.                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Clear WRP Buffer Interrupt, Dma Channel Interrupt and   **
**                    TRL flags.                                              **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lDmaChClrIntrFlagsInit(Dma_ChannelType Channel)
{
  /*Reserve bit access is ensured for DMA_CHCSRz register*/
  SPI_DMA_SFR_INIT_MODIFY32(MODULE_DMA.CH[Channel].CHCSR.U,\
                           SPI_DMA_CHCSR_CLEARMASK,SPI_DMA_CHCSR_CLR_INTFLAGS)
  /*Reserve bit access is ensured for DMA_TSRz register*/
  SPI_DMA_SFR_INIT_MODIFY32(MODULE_DMA.TSR[Channel].U,\
                             SPI_DMA_CHCSR_CLEARMASK,SPI_DMA_TSR_CLR_INTFLAGS)
}
/*******************************************************************************
** Traceability     :                                                         **
** Syntax           :  IFX_LOCAL_INLINE void Spi_lDmaChClrIntrFlagsDeinit     **
** (                                                                          **
**   Dma_ChannelType Channel                                                  **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Channel - Dma channel no.                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Clear WRP Buffer Interrupt, Dma Channel Interrupt and   **
**                    TRL flags.                                              **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lDmaChClrIntrFlagsDeinit(Dma_ChannelType Channel)
{
  /*Reserve bit access is ensured for DMA_CHCSRz register*/
  SPI_DMA_SFR_DEINIT_MODIFY32(MODULE_DMA.CH[Channel].CHCSR.U,\
                           SPI_DMA_CHCSR_CLEARMASK,SPI_DMA_CHCSR_CLR_INTFLAGS)
  /*Reserve bit access is ensured for DMA_TSRz register*/
  SPI_DMA_SFR_DEINIT_MODIFY32(MODULE_DMA.TSR[Channel].U,\
                             SPI_DMA_CHCSR_CLEARMASK,SPI_DMA_TSR_CLR_INTFLAGS)
}
/*******************************************************************************
** Traceability     :                                                         **
** Syntax           :  IFX_LOCAL_INLINE void Spi_lDmaEnTransReqLostIntr       **
** (                                                                          **
**   uint32 DmaChannel                                                        **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : DmaChannel - Dma channel no.                            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to enable the Dma Error interrupt.             **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lDmaEnTransReqLostIntr(Dma_ChannelType Channel)
{
  /* DMA Error (Transaction req lost intr) enable  */
  SPI_DMA_SFR_INIT_MODIFY32(MODULE_DMA.CH[Channel].ADICR.U,\
                                  SPI_DMA_ADICR_CLEARMASK,SPI_DMA_ADICR_SETMASK)
}

/*******************************************************************************
** Traceability     :                                                         **
** Syntax           :  IFX_LOCAL_INLINE void Spi_lDmaCfgIntControl            **
** (                                                                          **
**   Dma_ChannelType Channel                                                  **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Channel - Dma channel no.                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Configures Channel Interrupt Control with the
**                    given value                                             **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lDmaCfgIntControl(Dma_ChannelType Channel,
                                                  uint32 value)
{
  value = value & IFX_DMA_BLK_ME_ADICR_INTCT_MSK;
  SPI_DMA_SFR_INIT_MODIFY32(MODULE_DMA.CH[Channel].ADICR.U,\
              SPI_DMA_ADICR_CLEARMASK1,((uint32)value&3U)<<SPI_DMA_ADICR_BITPOS)
}

/*******************************************************************************
** Traceability     :                                                         **
** Syntax           :  IFX_LOCAL_INLINE void Spi_lDmaEnableChIntrTrigger      **
** (                                                                          **
**   Dma_ChannelType Channel                                                  **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Channel - Dma channel no.                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Enable the Channel Interrupt Trigger.                   **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lDmaEnableChIntrTrigger(Dma_ChannelType Channel)
{
    /*Reserve bit access is ensured for DMA_CHCSRz register*/
  SPI_DMA_SFR_INIT_MODIFY32(MODULE_DMA.CH[Channel].CHCSR.U,\
                                  SPI_DMA_CHCSR_CLEARMASK,SPI_DMA_CHCSR_SETMASK)
}

/*******************************************************************************
** Traceability     :                                                         **
** Syntax           :  void Spi_lDmaClrAdcr                                   **
** (                                                                          **
**   Dma_ChannelType Channel                                                  **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Channel - Dma channel no.                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Clear the Address control part of ADICR .               **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lDmaClrAdcr(Dma_ChannelType Channel)
{
  SPI_DMA_SFR_DEINIT_MODIFY32(MODULE_DMA.CH[Channel].ADICR.U,\
                                                    SPI_ADDR_CTRL_RESETVAL,0U)
}

/*******************************************************************************
** Traceability     :                                                         **
** Syntax           :  IFX_LOCAL_INLINE void Spi_lDmaChClrIntctEtrlFlags      **
** (                                                                          **
**   Dma_ChannelType Channel                                                  **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Channel - Dma channel no.                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Clear the Channel Interrupt control flags.              **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lDmaChClrIntctEtrlFlags(Dma_ChannelType Channel)
{
  SPI_DMA_SFR_DEINIT_MODIFY32(MODULE_DMA.CH[Channel].ADICR.U,\
                                            SPI_ADICR_INTCT_ETRL_CLR_MASK,0U)
}

/*******************************************************************************
** Traceability     :                                                         **
** Syntax           :  IFX_LOCAL_INLINE void Spi_lDmaDisableChIntrTrigger     **
** (                                                                          **
**   Dma_ChannelType Channel                                                  **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Channel - Dma channel no.                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Disables the Channel Interrupt Trigger.                 **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lDmaDisableChIntrTrigger
(
  Dma_ChannelType Channel
)
{
    /*Reserve bit access is ensured for DMA_CHCSRz register*/
  SPI_DMA_SFR_DEINIT_MODIFY32(MODULE_DMA.CH[Channel].CHCSR.U,\
                                                   SPI_DMA_CHCSR_CLEARMASK1,0U)
}

/*******************************************************************************
** Traceability     :                                                         **
** Syntax           :  IFX_LOCAL_INLINE void Spi_lDmaClrErrFlags              **
** (                                                                          **
**   Dma_ChannelType Channel                                                  **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Channel - Dma channel no.                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Clear the Transaction request flag.                     **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lDmaClrErrFlags(Dma_ChannelType Channel)
{
    /*Reserve bit access is ensured for DMA_TSRz register*/
  SPI_DMA_SFR_DEINIT_MODIFY32(MODULE_DMA.TSR[Channel].U,\
                                     SPI_DMA_TSR_CLEARMASK,SPI_DMA_TSR_SETMASK)
}

/*******************************************************************************
** Traceability     :                                                         **
** Syntax           : IFX_LOCAL_INLINE void Spi_lDmaCfgMeErrIntr(uint8 Enable)**
** (                                                                          **
**   uint32 Enable                                                            **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Enable :  1 - Enable ME Error Interrupt.  0 - Disable   **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Function to enable/Disable the Dma ME Error interrupt.  **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lDmaCfgMeErrIntr(uint8 Enable)
{
  /* DMA ME Eror Intr enable/Disable  */
  /* Errata fix,.. DMA_TC.016 in BC step
    Byte and Half-word Write Accesses to specific Registers not supported
  */
  SPI_DMA_SFR_INIT_MODIFY32(MODULE_DMA.ERRINTR.U,\
                                              SPI_DMA_ERRINTR_CLEARMASK,Enable)
}
#endif
/* #if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U)) */

#if ( (SPI_SLAVE_ENABLE == STD_ON) || (SPI_LEVEL_DELIVERED == 1U) \
                                   || (SPI_LEVEL_DELIVERED == 2U))
/*******************************************************************************
** Syntax           : static Dma_ErrorStatusType                              **
**                          Spi_lDmaGetBothMoveEngErrFlags(uint8 ApiAccessId) **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : ApiAccessId   : API access type                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Dma_ErrorStatusType - Dma error status.                 **
**                                                                            **
** Description      : Checks for move engine 0 and 1 error flags.             **
*******************************************************************************/
static Dma_ErrorStatusType Spi_lDmaGetBothMoveEngErrFlags(uint8 \
                                                                    ApiAccessId)
{
  /*
  The Error Status Register indicates if the DMA controller could
  not answer to a request because the previous request was not terminated.
  It detects following MEx errors
  SER (Source Error), DER (Destination Error)
  FPIER (FPI Bus Error), SRIER (SRI Bus Error), PERER (Peripheral Error)
  Return:
  0 : indicates No Error
  1 : indicates Error occured
  */
  Dma_ErrorStatusType ErrValue;
  uint32 DmaMovEnErrBits;
#if ((SPI_USER_MODE_RUNTIME_API_ENABLE == STD_ON) && \
                                  (SPI_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON))
  if (ApiAccessId == SPI_RUNTIME_ACCESS)
  {
    DmaMovEnErrBits  = (uint32)((uint32)(SPI_DMA_SFR_RUNTIME_USER_MODE_READ32\
                   (MODULE_DMA.BLK0.ERRSR.U)) & (uint32)(DMA_ERRSR_ERROR_MASK));
    DmaMovEnErrBits |= (uint32)((uint32)(SPI_DMA_SFR_RUNTIME_USER_MODE_READ32\
                   (MODULE_DMA.BLK1.ERRSR.U)) & (uint32)(DMA_ERRSR_ERROR_MASK));
  }
  else
#endif
  {
    DmaMovEnErrBits  = (uint32)((uint32)(MODULE_DMA.BLK0.ERRSR.U) &
                                               (uint32)(DMA_ERRSR_ERROR_MASK));
    DmaMovEnErrBits |= (uint32)((uint32)(MODULE_DMA.BLK1.ERRSR.U) &
                                               (uint32)(DMA_ERRSR_ERROR_MASK));
  }
#if ((SPI_USER_MODE_RUNTIME_API_ENABLE == STD_OFF) || \
                                 (SPI_RUNNING_IN_USER_0_MODE_ENABLE == STD_OFF))
    UNUSED_PARAMETER(ApiAccessId)
#endif
  ErrValue = (DmaMovEnErrBits > 0U) ? 1U : 0U;

  return(ErrValue);
}
#endif
/* #if ( (SPI_SLAVE_ENABLE == STD_ON) || (SPI_LEVEL_DELIVERED == 1U) \
                                      || (SPI_LEVEL_DELIVERED == 2U)) */
/*******************************************************************************
** Syntax           :  IFX_INLINE void Spi_lSetSeqStatus                      **
** (                                                                          **
**   Spi_SequenceType Seq, Spi_SeqResultType Status                           **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : Seq - Seq Id                                            **
**                Status - Sequence status                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Set the sequence status                                 **
*******************************************************************************/
IFX_INLINE void Spi_lSetSeqStatus(Spi_SequenceType Seq,
                                                      Spi_SeqResultType Status)
{
  uint8 Index;

  #if (SPI_SAFETY_ENABLE == STD_ON)
  {
    /* ASIL or QM sequence index from map configuration*/
    Index = (uint8)(Spi_kConfigPtr->SpiMapConfigPtr->SeqIndex[Seq]
            >> SPI_SEQUENCE_INDEX);
  }
  #else
  {
    /* if safety is OFF then map config is absent */
    Index = (uint8)(Seq
            >> SPI_SEQUENCE_INDEX);
  }
  #endif

  #if (SPI_SAFETY_ENABLE == STD_ON)
    if( SPI_ASIL_SEQUENCE == Spi_lGetSequenceKind(Seq) )
    {
      Spi_AsilSeqStatus[Index].AsilSeqStatus =     \
         (Spi_AsilSeqStatus[Index].AsilSeqStatus & \
          ~((uint32)SPI_SEQUENCE_STATUS_EXTRACT << \
        (SPI_SEQUENCE_STATUS_BITS * ((Seq) & SPI_SEQUENCE_BIT_POSITION)))) | \
           ((uint32)((uint32)Status & SPI_SEQUENCE_STATUS_BITMASK) << \
            (SPI_SEQUENCE_STATUS_BITS * ((Seq) & SPI_SEQUENCE_BIT_POSITION)));
    }
    else
    {
      #if (SPI_QM_MASTER_MODULES_USED != 0U)
      Spi_QmSeqStatus[Index].QmSeqStatus =     \
         (Spi_QmSeqStatus[Index].QmSeqStatus & \
          ~((uint32)SPI_SEQUENCE_STATUS_EXTRACT << \
        (SPI_SEQUENCE_STATUS_BITS * ((Seq) & SPI_SEQUENCE_BIT_POSITION)))) | \
           ((uint32)((uint32)Status & SPI_SEQUENCE_STATUS_BITMASK) << \
            (SPI_SEQUENCE_STATUS_BITS * ((Seq) & SPI_SEQUENCE_BIT_POSITION)));
      #endif
      /* Do nothing if QM modules are NOT Used */
    }
  #else
  {
      Spi_QmSeqStatus[Index].QmSeqStatus =     \
         (Spi_QmSeqStatus[Index].QmSeqStatus & \
          ~((uint32)SPI_SEQUENCE_STATUS_EXTRACT << \
        (SPI_SEQUENCE_STATUS_BITS * ((Seq) & SPI_SEQUENCE_BIT_POSITION)))) | \
           ((uint32)((uint32)Status & SPI_SEQUENCE_STATUS_BITMASK) << \
            (SPI_SEQUENCE_STATUS_BITS * ((Seq) & SPI_SEQUENCE_BIT_POSITION)));
  }
  #endif
}

/*******************************************************************************
** Syntax           :  IFX_INLINE Spi_SeqResultType Spi_lGetSeqStatus         **
** (                                                                          **
**   Spi_SequenceType Seq                                                     **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Seq - Seq Id                                            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : sequence result.                                        **
**                                                                            **
** Description      : Returns the sequence status                             **
*******************************************************************************/
IFX_INLINE Spi_SeqResultType Spi_lGetSeqStatus(Spi_SequenceType Seq)
{
  Spi_SeqResultType RetVal = SPI_SEQ_OK;
  uint8 Index;

  #if (SPI_SAFETY_ENABLE == STD_ON)
  {
    /* ASIL or QM sequence index from map configuration*/
    Index = (uint8)(Spi_kConfigPtr->SpiMapConfigPtr->SeqIndex[Seq]
            >> SPI_SEQUENCE_INDEX);
  }
  #else
  {
    /* if safety is OFF then map config is absent */
    Index = (uint8)(Seq
            >> SPI_SEQUENCE_INDEX);
  }
  #endif

  #if (SPI_SAFETY_ENABLE == STD_ON)
    if( SPI_ASIL_SEQUENCE == Spi_lGetSequenceKind(Seq) )
    {
      RetVal = (Spi_SeqResultType)((Spi_AsilSeqStatus[Index].AsilSeqStatus >>
       (SPI_SEQUENCE_STATUS_BITS * ((uint32)Seq &  SPI_SEQUENCE_BIT_POSITION)))
      & SPI_SEQUENCE_STATUS_EXTRACT);
    }
    else
    {
      #if (SPI_QM_MASTER_MODULES_USED != 0U)
      RetVal = (Spi_SeqResultType)((Spi_QmSeqStatus[Index].QmSeqStatus >>
       (SPI_SEQUENCE_STATUS_BITS * ((uint32)Seq &  SPI_SEQUENCE_BIT_POSITION)))
      & SPI_SEQUENCE_STATUS_EXTRACT);
      #endif
      /* Do nothing if QM modules are NOT Used */
    }
  #else
  {
      RetVal = (Spi_SeqResultType)((Spi_QmSeqStatus[Index].QmSeqStatus >>
       (SPI_SEQUENCE_STATUS_BITS * ((uint32)Seq &  SPI_SEQUENCE_BIT_POSITION)))
      & SPI_SEQUENCE_STATUS_EXTRACT);
  }
  #endif

   return RetVal;
}

/*******************************************************************************
** Syntax           :  IFX_INLINE void Spi_lSetJobStatusAtomic                **
** (                                                                          **
**   Spi_JobType Job, Spi_JobResultType Result                                **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Job - Job Id                                            **
**                Result - job result                                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : sequence result.                                        **
**                                                                            **
** Description      : set the Job result atomically                           **
*******************************************************************************/
IFX_INLINE void Spi_lSetJobStatusAtomic(Spi_JobType Job,
                                                      Spi_JobResultType Result)
{
  uint16 Index;
  uint32 Temp;

  #if (SPI_SAFETY_ENABLE == STD_ON)
  {
    /* ASIL or QM job index from map configuration*/
    Index = (uint16)(Spi_kConfigPtr->SpiMapConfigPtr->JobIndex[Job]
            >> SPI_JOB_INDEX);
  }
  #else
  {
    /* if safety is OFF then map config is absent */
    Index = (uint16)(Job
            >> SPI_JOB_INDEX);
  }
  #endif

  Temp = ((uint32)SPI_JOB_STATUS_BITS *
                       (uint32)((uint32)(Job) & (uint32)SPI_JOB_BIT_POSITION));

  #if (SPI_SAFETY_ENABLE == STD_ON)
    if( SPI_ASIL_JOB == Spi_lGetJobKind(Job) )
    {
        Mcal_SetAtomic(
           (sint32*)(void*) &Spi_AsilJobResult[Index],\
           (uint32)(Result),\
           (sint32)Temp,\
           2);
    }
    else
    {
        #if (SPI_QM_MASTER_MODULES_USED != 0U)
        Mcal_SetAtomic(
           (sint32*)(void*) &Spi_QmJobResult[Index],\
           (uint32)(Result),\
           (sint32)Temp,\
           2);
        #endif
        /* Do nothing if QM modules are NOT Used */
    }
  #else
    {
        Mcal_SetAtomic(
           (sint32*)(void*) &Spi_QmJobResult[Index],\
           (uint32)(Result),\
           (sint32)Temp,\
           2);
    }
  #endif
}

/*******************************************************************************
** Syntax           :  IFX_INLINE void Spi_lSetSeqStatusAtomic                **
** (                                                                          **
**   Spi_SequenceType Seq, Spi_SeqResultType Status                           **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Seq - Sequence Id                                       **
**                Result - Sequence result                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : sequence result.                                        **
**                                                                            **
** Description      : set the Sequence result atomically                      **
*******************************************************************************/
IFX_INLINE void Spi_lSetSeqStatusAtomic(Spi_SequenceType Seq,
                              Spi_SeqResultType Status)
{
  uint16 Index;
  uint32 Temp;

  #if (SPI_SAFETY_ENABLE == STD_ON)
  {
    /* ASIL or QM sequence index from map configuration*/
    Index = (uint16)((uint16)Spi_kConfigPtr->SpiMapConfigPtr->SeqIndex[Seq]
            >> SPI_SEQUENCE_INDEX);
  }
  #else
  {
    /* if safety is OFF then map config is absent */
    Index = (uint16)((uint16)Seq
            >> SPI_SEQUENCE_INDEX);
  }
  #endif

  Temp = ((uint32)SPI_SEQUENCE_STATUS_BITS *
                  (uint32)((uint32)(Seq) & (uint32)SPI_SEQUENCE_BIT_POSITION));

  #if (SPI_SAFETY_ENABLE == STD_ON)
    if( SPI_ASIL_SEQUENCE == Spi_lGetSequenceKind(Seq) )
    {
        Mcal_SetAtomic(
       (sint32*)(void*) &Spi_AsilSeqStatus[Index].AsilSeqStatus,
       (uint32)(Status),
       (sint32)Temp,
       2);
    }
    else
    {
        #if (SPI_QM_MASTER_MODULES_USED != 0U)
        Mcal_SetAtomic(
       (sint32*)(void*) &Spi_QmSeqStatus[Index].QmSeqStatus,
       (uint32)(Status),
       (sint32)Temp,
       2);
       #endif
       /* Do nothing if QM modules are NOT Used */
    }
  #else
    {
       Mcal_SetAtomic(
       (sint32*)(void*) &Spi_QmSeqStatus[Index].QmSeqStatus,
       (uint32)(Status),
       (sint32)Temp,
       2);
    }
  #endif
}

#if ((SPI_LEVEL_DELIVERED == 0U) || (SPI_LEVEL_DELIVERED == 2U))
/*******************************************************************************
** Syntax           :  IFX_INLINE void Spi_lSetJobStatus                      **
** (                                                                          **
**   Spi_JobType Job, Spi_JobResultType Result                                **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : Job - Job Id                                            **
**                Result - job result                                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : sequence result.                                        **
**                                                                            **
** Description      : set the Job result                                      **
*******************************************************************************/
IFX_INLINE void Spi_lSetJobStatus(Spi_JobType Job, Spi_JobResultType Result)
{
  uint16 Index ;

  #if (SPI_SAFETY_ENABLE == STD_ON)
  {
    /* ASIL or QM Job index from map configuration*/
    Index = (uint16)(Spi_kConfigPtr->SpiMapConfigPtr->JobIndex[Job]
            >> SPI_JOB_INDEX);
  }
  #else
  {
    /* if safety is OFF then map config is absent */
    Index = (uint16)(Job
            >> SPI_JOB_INDEX);
  }
  #endif

  #if (SPI_SAFETY_ENABLE == STD_ON)
    if( SPI_ASIL_JOB == Spi_lGetJobKind(Job) )
    {
      Spi_AsilJobResult[Index] = (Spi_AsilJobResult[Index] & \
      ~((uint32)SPI_JOB_STATUS_EXTRACT << (SPI_JOB_STATUS_BITS * \
        ((Job) & SPI_JOB_BIT_POSITION)))) |\
       ((uint32)(Result) << (SPI_JOB_STATUS_BITS * \
        ((Job) & SPI_JOB_BIT_POSITION)));
    }
    else
    {
      #if (SPI_QM_MASTER_MODULES_USED != 0U)
      Spi_QmJobResult[Index] = (Spi_QmJobResult[Index] & \
      ~((uint32)SPI_JOB_STATUS_EXTRACT << (SPI_JOB_STATUS_BITS * \
        ((Job) & SPI_JOB_BIT_POSITION)))) |\
       ((uint32)(Result) << (SPI_JOB_STATUS_BITS * \
        ((Job) & SPI_JOB_BIT_POSITION)));
      #endif
      /* If QM Master modules is 0  */
    }
  #else
  {
      Spi_QmJobResult[Index] = (Spi_QmJobResult[Index] & \
      ~((uint32)SPI_JOB_STATUS_EXTRACT << (SPI_JOB_STATUS_BITS * \
        ((Job) & SPI_JOB_BIT_POSITION)))) |\
       ((uint32)(Result) << (SPI_JOB_STATUS_BITS * \
        ((Job) & SPI_JOB_BIT_POSITION)));
  }
  #endif

}
#endif
/* ((SPI_LEVEL_DELIVERED == 0) || (SPI_LEVEL_DELIVERED == 2U)) */

#if((SPI_CHANNEL_BUFFERS_ALLOWED == 0U) || (SPI_CHANNEL_BUFFERS_ALLOWED == 2U))
/*******************************************************************************
** Syntax           :  IFX_INLINE uint8  Spi_lGetChannelWriteLock             **
** (                                                                          **
**   Spi_ChannelType Channel                                                  **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Channel - Channel Id                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Lock Status of a Channel.                               **
**                                                                            **
** Description      : Get the Lock Status of a Channel. The Lock is used as a **
**            binary semaphore. Each Bit in the variable represents a Channel **
*******************************************************************************/
IFX_INLINE uint8  Spi_lGetChannelWriteLock(Spi_ChannelType Channel)
{
  uint8 Index;
  uint8 Temp;

  Index = Channel >> SPI_INDEX_OF_CHANNELLOCK;
  Temp = (uint8)(Spi_IBBufferAccess.ChannelWriteLock[Index] & \
         ((uint32)1U << ((Channel) & (SPI_NUM_OF_BITS - 1U))));

  return Temp;
}

/*******************************************************************************
** Syntax           :  IFX_INLINE void  Spi_lSetChannelWriteLock              **
** (                                                                          **
**   Spi_ChannelType Channel                                                  **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Channel - Channel Id                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Set the Lock Status of a Channel. The Lock is used as a **
**            binary semaphore. Each Bit in the variable represents a Channel **
*******************************************************************************/
IFX_INLINE void  Spi_lSetChannelWriteLock(Spi_ChannelType Channel)
{
  uint16 Index;
  uint32 Temp;

  Index = (uint16)Channel >> SPI_INDEX_OF_CHANNELLOCK;
  Temp = SPI_NUM_OF_BITS - 1U;
  Temp =  Channel & Temp;
  Spi_IBBufferAccess.ChannelWriteLock[Index] |= (uint8)((uint32)1U <<  Temp);
}

/*******************************************************************************
** Syntax           :  IFX_INLINE void  Spi_lClrChannelWriteLock              **
** (                                                                          **
**   Spi_ChannelType Channel                                                  **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Channel - Channel Id                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Clear the Lock Status of a Channel.                     **
*******************************************************************************/
IFX_INLINE void  Spi_lClrChannelWriteLock(Spi_ChannelType Channel)
{
  uint16 Index;

  Index = (uint16)Channel >> SPI_INDEX_OF_CHANNELLOCK;

  Spi_IBBufferAccess.ChannelWriteLock[Index] &= \
     (uint8)(~((uint32)1U << (Channel & (SPI_NUM_OF_BITS - 1U))));
}
#endif
/* ((SPI_CHANNEL_BUFFERS_ALLOWED == 0U) ||
          (SPI_CHANNEL_BUFFERS_ALLOWED == 2U))*/

#if ((SPI_CANCEL_API == STD_ON) && (SPI_LEVEL_DELIVERED != 0U))
/*******************************************************************************
** Syntax           :  IFX_INLINE void  Spi_lSetSeqCancelStatus               **
** (                                                                          **
**   Spi_SequenceType Seq                                                     **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : Seq - Sequence Id                                       **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Set Sequence to Canceled State                          **
*******************************************************************************/
IFX_INLINE void  Spi_lSetSeqCancelStatus(Spi_SequenceType Seq)
{
  uint16 Index;

  #if (SPI_SAFETY_ENABLE == STD_ON)
  {
    /* ASIL or QM sequence index from map configuration*/
    Index = (uint16)((uint16)Spi_kConfigPtr->SpiMapConfigPtr->SeqIndex[Seq] \
            >> SPI_SEQUENCE_INDEX);
  }
  #else
  {
    /* if safety is OFF then map config is absent */
    Index = (uint16)((uint16)Seq
            >> SPI_SEQUENCE_INDEX);
  }
  #endif

  #if (SPI_SAFETY_ENABLE == STD_ON)
    if( SPI_ASIL_SEQUENCE == Spi_lGetSequenceKind(Seq) )
    {
      Spi_AsilSeqStatus[Index].AsilSeqCancelStatus = \
        Spi_AsilSeqStatus[Index].AsilSeqCancelStatus |\
       ((uint32)SPI_SEQ_CANCELED << (SPI_SEQUENCE_STATUS_BITS * \
       (Seq & SPI_SEQUENCE_BIT_POSITION)));
    }
    else
    {
      #if (SPI_QM_MASTER_MODULES_USED != 0U)
      Spi_QmSeqStatus[Index].QmSeqCancelStatus = \
        Spi_QmSeqStatus[Index].QmSeqCancelStatus |\
       ((uint32)SPI_SEQ_CANCELED << (SPI_SEQUENCE_STATUS_BITS * \
       (Seq & SPI_SEQUENCE_BIT_POSITION)));
      #endif
      /* Do nothing if QM modules are NOT Used */
    }
  #else
  {
    Spi_QmSeqStatus[Index].QmSeqCancelStatus = \
      Spi_QmSeqStatus[Index].QmSeqCancelStatus |\
     ((uint32)SPI_SEQ_CANCELED << (SPI_SEQUENCE_STATUS_BITS * \
     (Seq & SPI_SEQUENCE_BIT_POSITION)));
  }
  #endif
}

/*******************************************************************************
** Syntax           :  IFX_INLINE void  Spi_lClrSeqCancelStatus               **
** (                                                                          **
**   Spi_SequenceType Seq                                                     **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : Seq - Sequence Id                                       **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Clear Sequence Canceled State                           **
*******************************************************************************/
IFX_INLINE void  Spi_lClrSeqCancelStatus(Spi_SequenceType Seq)
{
  uint16 Index;

  #if (SPI_SAFETY_ENABLE == STD_ON)
  {
    /* ASIL or QM sequence index from map configuration*/
    Index = (uint16)((uint16)Spi_kConfigPtr->SpiMapConfigPtr->SeqIndex[Seq] \
            >> SPI_SEQUENCE_INDEX);
  }
  #else
  {
    /* if safety is OFF then map config is absent */
    Index = (uint16)((uint16)Seq
            >> SPI_SEQUENCE_INDEX);
  }
  #endif

  #if (SPI_SAFETY_ENABLE == STD_ON)
    if( SPI_ASIL_SEQUENCE == Spi_lGetSequenceKind(Seq) )
    {
      Spi_AsilSeqStatus[Index].AsilSeqCancelStatus = \
        Spi_AsilSeqStatus[Index].AsilSeqCancelStatus & \
        (~((uint32)SPI_SEQ_CANCELED << (SPI_SEQUENCE_STATUS_BITS * \
        (Seq & SPI_SEQUENCE_BIT_POSITION))));
    }
    else
    {
      #if (SPI_QM_MASTER_MODULES_USED != 0U)
      Spi_QmSeqStatus[Index].QmSeqCancelStatus = \
        Spi_QmSeqStatus[Index].QmSeqCancelStatus & \
        (~((uint32)SPI_SEQ_CANCELED << (SPI_SEQUENCE_STATUS_BITS * \
        (Seq & SPI_SEQUENCE_BIT_POSITION))));
      #endif
      /* Do nothing if QM modules are NOT Used */
    }
  #else
  {
    Spi_QmSeqStatus[Index].QmSeqCancelStatus = \
      Spi_QmSeqStatus[Index].QmSeqCancelStatus & \
      (~((uint32)SPI_SEQ_CANCELED << (SPI_SEQUENCE_STATUS_BITS * \
      (Seq & SPI_SEQUENCE_BIT_POSITION))));
  }
  #endif

}
#endif
/* ((SPI_CANCEL_API == STD_ON) && (SPI_LEVEL_DELIVERED != 0)) */

/*******************************************************************************
** Syntax           :  IFX_INLINE uint16 Spi_lGetCSPinOffset                  **
** (                                                                          **
**   uint16 CSId                                                              **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : CSId - ChipSelect PinId                                 **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Pin number.                                             **
**                                                                            **
** Description      : Extract pin number from ChipSelect Id                   **
*******************************************************************************/
IFX_INLINE uint16 Spi_lGetCSPinOffset(uint16 CSId)
{
  uint16 Temp;
  Temp = (uint16)(CSId & SPI_PORT_PIN_MASK);
  return Temp;
}

/*******************************************************************************
** Syntax           :  IFX_INLINE Ifx_P* Spi_lGetGpioAddr                     **
** (                                                                          **
**   uint16 PortNumber                                                        **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : PortNumber - port no                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Gpio register address.                                  **
**                                                                            **
** Description      : Returns the Gpio register address of the given port     **
*******************************************************************************/
IFX_INLINE Ifx_P* Spi_lGetGpioAddr(uint16 PortNumber)
{
  Ifx_P *Temp;

  /*IFX_MISRA_RULE_17_04_STATUS="P00_OUT" Pointer arithmetic is used to
    efficiently access the SFRs of multiple QSPI Modules.*/
  Temp = &(*((Ifx_P *)(void *)&P00_OUT +  \
                                          (((PortNumber/10U)*16U) +        \
                                           (PortNumber%10U)                \
                                          )                                \
                                        )                                  \
                                      );
  return Temp;
}

/*******************************************************************************
** Syntax           :  IFX_INLINE uint16 Spi_lGetCSPortOffset                 **
** (                                                                          **
**   uint16 CSId                                                              **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : CSId - ChipSelect PortId                                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Port number.                                            **
**                                                                            **
** Description      : Extract Port number from ChipSelect Id                  **
*******************************************************************************/
IFX_INLINE uint16 Spi_lGetCSPortOffset(uint16 CSId)
{
  uint16 Temp;

  Temp = (CSId >> SPI_EXTRACT_PORT_ID) &  SPI_PORT_ID_MASK;
  return Temp;
}

#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
#if ((SPI_CHANNEL_BUFFERS_ALLOWED == 1U) || (SPI_CHANNEL_BUFFERS_ALLOWED == 2U))
/*******************************************************************************
** Syntax           :  IFX_INLINE Spi_DataType* Spi_lGetDmaDummyTxAddress     **
** (                                                                          **
**   uint32 Module                                                            **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Module no                                      **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Dummy Address.                                          **
**                                                                            **
** Description      : Get DMA dummy Address needed for Default value          **
**                   Transmission when Data Source pointer is NULL            **
*******************************************************************************/
#if (SPI_DMA_ADDRESS_ACCESS == STD_ON)
/*Dma address translation not required for Tricore 1.6 */
IFX_INLINE Spi_DataType* Spi_lGetDmaDummyTxAddress(uint32 Module)
{
  Spi_ChnlAccessType *ChnlAccDataPtr;
  Spi_DataType *Temp;

  #if((SPI_SAFETY_ENABLE == STD_ON) && (SPI_QM_ASYNC_MASTER_MODULES_USED == 0U))
  ChnlAccDataPtr = NULL_PTR; /* To remove warning: Possibly Uninitialised*/
  #endif

  #if (SPI_SAFETY_ENABLE == STD_ON)
  if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)Module))
  {
    ChnlAccDataPtr = &Spi_AsilChnlAccess[0U];
  }
  else
  {
    #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
    ChnlAccDataPtr = &Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)];
    #endif
    /* Do nothing if QM modules are NOT Used */
  }
  #else
  {
    ChnlAccDataPtr = &Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)];
  }
  #endif

  Temp = (Spi_DataType *)(void*)&ChnlAccDataPtr->DMATXDummy;

  return Temp;
}
#endif
/*(SPI_DMA_ADDRESS_ACCESS == STD_ON)*/
/*******************************************************************************
** Syntax           :  IFX_INLINE void Spi_lSetDmaDummyTxValue                **
** (                                                                          **
**   uint32 Module, uint32 Value                                              **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Module no                                      **
**                Value - value to be written.                                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Set Default value to the dummy adress. Used during      **
**                   DMA Transmission when the source pointer is NULL.        **
*******************************************************************************/
IFX_INLINE void Spi_lSetDmaDummyTxValue(uint32 Module, uint32 Value)
{
  Spi_ChnlAccessType *ChnlAccDataPtr;

  #if((SPI_SAFETY_ENABLE == STD_ON) && (SPI_QM_ASYNC_MASTER_MODULES_USED == 0U))
  ChnlAccDataPtr = NULL_PTR; /* To remove warning: Possibly Uninitialised*/
  #endif

  #if (SPI_SAFETY_ENABLE == STD_ON)
  if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)Module))
  {
    ChnlAccDataPtr = &Spi_AsilChnlAccess[0U];
  }
  else
  {
    #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
    ChnlAccDataPtr = &Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)];
    #endif
    /* Do nothing if QM modules are NOT Used */
  }
  #else
  {
    ChnlAccDataPtr = &Spi_QmChnlAccess[Spi_lGetQmModuleVarIndex(Module)];
  }
  #endif

  ChnlAccDataPtr->DMATXDummy = (Value);
}
#endif
/*((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))*/
#endif

/*******************************************************************************
** Syntax           :  IFX_INLINE void Spi_lHwDisableModule                   **
** (                                                                          **
**   uint32 Module, uint8 ApiAccessId                                         **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Module no                                      **
                    : ApiAccessId   - API access type                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Disable the Module at the end of Job transmission.      **
*******************************************************************************/
IFX_INLINE void Spi_lHwDisableModule(uint32 Module, uint8 ApiAccessId)
{
#if (SPI_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
  if (ApiAccessId == SPI_RUNTIME_ACCESS)
  {
    /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
      to efficiently access the SFRs of multiple QSPI Modules.*/
    SPI_SFR_RUNTIME_MODIFY32(SPI_HW_MODULE[(uint8)Module].GLOBALCON.U,\
                                SPI_GLOBALCON_CLEARMASK1,SPI_GLOBALCON_SETMASK1)
  }
  else
#endif
  {
    /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
      to efficiently access the SFRs of multiple QSPI Modules.*/
    /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
      to efficiently access the SFRs of multiple QSPI Modules.*/
    SPI_HW_MODULE[(uint8)Module].GLOBALCON.U =\
     ((SPI_HW_MODULE[(uint8)Module].GLOBALCON.U) & SPI_GLOBALCON_CLEARMASK1) |\
                                                         SPI_GLOBALCON_SETMASK1;
  }
#if (SPI_USER_MODE_RUNTIME_API_ENABLE == STD_OFF)
UNUSED_PARAMETER(ApiAccessId)
#endif
}

/*******************************************************************************
** Syntax           :  IFX_INLINE uint32 Spi_lHwGetModuleStatus               **
** (                                                                          **
**   uint32 Module                                                            **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Module no                                      **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Return the Module enable status                         **
*******************************************************************************/
IFX_INLINE uint32 Spi_lHwGetModuleStatus(uint8 Module)
{
  uint32 Temp;
  /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used to
    efficiently access the SFRs of multiple QSPI Modules.*/
  Temp = (uint32)((SPI_SFR_RUNTIME_USER_MODE_READ32\
   (SPI_HW_MODULE[Module].STATUS.U) & SPI_STATUS_CLEARMASK)>>SPI_STATUS_BITPOS);
  return Temp;
}

/*******************************************************************************
** Syntax           :  IFX_INLINE void SPI_lHwUpdateSrcRegister               **
** (                                                                          **
**   Ifx_QSPI *ModulePtr, uint32 Value                                        **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : ModulePtr - Module base address                         **
**                    Value - Data to be written to source address            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Update the Qspi source address with the data to be      **
**                     sent on spi bus                                        **
*******************************************************************************/
IFX_INLINE void SPI_lHwUpdateSrcRegister(Ifx_QSPI *ModulePtr, uint32 Value)
{
  SPI_SFR_RUNTIME_USER_MODE_WRITE32(ModulePtr->DATAENTRY[0].U,Value);
}

/*******************************************************************************
** Syntax           :  IFX_INLINE void SPI_lHwUpdateSrcRegViaModule           **
** (                                                                          **
**   uint32 Module, uint32 Value, uint8 ApiAccessId                           **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : Module - Module no                                      **
**                  : Value - Data to be written to source address            **
                    : ApiAccessId   - API access type                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Update the Qspi source address with the data to be      **
**                     sent on spi bus                                        **
*******************************************************************************/
IFX_INLINE void SPI_lHwUpdateSrcRegViaModule(uint32 Module, uint32 Value,\
                                                              uint8 ApiAccessId)
{
  if (ApiAccessId == SPI_RUNTIME_ACCESS)
  {
    /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used to
     efficiently access the SFRs of multiple QSPI Modules.*/
    SPI_SFR_RUNTIME_USER_MODE_WRITE32(SPI_HW_MODULE[Module].DATAENTRY[0].U,\
                                                                         Value);
  }
  else
  {
    /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used to
     efficiently access the SFRs of multiple QSPI Modules.*/
    SPI_HW_MODULE[Module].DATAENTRY[0].U = Value;
  }
}

/*******************************************************************************
** Syntax           :  IFX_INLINE uint32 SPI_lHwReadDestRegister              **
** (                                                                          **
**   Ifx_QSPI *ModulePtr                                                      **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : ModulePtr - Module base address                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Data read from  destination address.                    **
**                                                                            **
** Description      : Read the Qspi destination address which contains        **
**                    the data received on Spi bus                            **
*******************************************************************************/
IFX_INLINE uint32 SPI_lHwReadDestRegister(const Ifx_QSPI *ModulePtr)
{
  uint32 Temp;
  Temp = (uint32)SPI_SFR_RUNTIME_USER_MODE_READ32(ModulePtr->RXEXIT.U);
  return Temp;
}

/*******************************************************************************
** Syntax           :  IFX_INLINE void Spi_lHwClrQspiPendEvent                **
** (                                                                          **
**   Ifx_QSPI *ModulePtr, uint8 ApiAccessId                                   **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : ModulePtr - Module base address                         **
                    : ApiAccessId   - API access type                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Clear Pending events in HW                              **
*******************************************************************************/
IFX_INLINE void Spi_lHwClrQspiPendEvent(Ifx_QSPI *ModulePtr, uint8 ApiAccessId)
{
#if ((SPI_USER_MODE_RUNTIME_API_ENABLE == STD_ON) && \
                               (SPI_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON))
  if (ApiAccessId == SPI_RUNTIME_ACCESS)
  {
    /*Reserve bit access is ensured for FLAGSCLEAR register*/
    SPI_SFR_RUNTIME_USER_MODE_WRITE32(ModulePtr->FLAGSCLEAR.U,\
                                                     SPI_QSPI_FLAGSCLEAR_VALUE);
  }
  else
#endif
  {
    /*Reserve bit access is ensured for FLAGSCLEAR register*/
    ModulePtr->FLAGSCLEAR.U = SPI_QSPI_FLAGSCLEAR_VALUE;
  }
#if ((SPI_USER_MODE_RUNTIME_API_ENABLE == STD_OFF) || \
                                 (SPI_RUNNING_IN_USER_0_MODE_ENABLE == STD_OFF))
    UNUSED_PARAMETER(ApiAccessId)
#endif
}

/*******************************************************************************
** Syntax           :  IFX_INLINE uint32 Spi_lHwGetTxStatus                   **
** (                                                                          **
**   Ifx_QSPI *ModulePtr                                                      **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : ModulePtr - Module base address                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : SPI_TX_IN_PROGRESS: TX on going.                        **
**                   SPI_TX_COMPLETED:Tx completed                            **
**                                                                            **
** Description      : return the Tx completion status                         **
*******************************************************************************/
IFX_INLINE uint32 Spi_lHwGetTxStatus(const Ifx_QSPI *ModulePtr)
{
  uint32 Temp;
  uint32 RetVal;
  #if (IFX_SPI_DEBUG_TX == STD_ON)
  Temp = Spi_IfxDebugStatus;
  UNUSED_PARAMETER(ModulePtr)
  #else
  Temp =  (uint32)(((SPI_SFR_RUNTIME_USER_MODE_READ32(ModulePtr->STATUS.U)) & \
                       (uint32)SPI_STATUS_CLEARMASK1) >> SPI_STATUS_TXF_BITPOS);
  #endif
  if (Temp == 0U)
  {
    RetVal = SPI_TX_IN_PROGRESS; /* Tx on going */
  }
  else
  {
    RetVal = SPI_TX_COMPLETED; /* Tx completed */
  }

  return RetVal;
}

/*******************************************************************************
** Syntax           :  IFX_INLINE uint32 Spi_lHwGetErrStatus                  **
** (                                                                          **
**   Ifx_QSPI *ModulePtr                                                      **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : ModulePtr - Module base address                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Error Flags of status register.                         **
**                                                                            **
** Description      : return the error status of QSPI                         **
*******************************************************************************/
IFX_INLINE uint32 Spi_lHwGetErrStatus(const Ifx_QSPI *ModulePtr)
{
  volatile uint32 Temp;
  Temp = ((uint32)(((uint32)SPI_SFR_RUNTIME_USER_MODE_READ32\
                              (ModulePtr->STATUS.U)) & SPI_STATUS_CLEARMASK2));
  #if (IFX_SPI_DEBUG_ERR == STD_ON)
  Temp = Spi_IfxDebugStatus;
  #endif
  return Temp;
}

/*******************************************************************************
** Syntax           :  IFX_INLINE uint32 Spi_lHwGetRxStatus                   **
** (                                                                          **
**   Ifx_QSPI *ModulePtr                                                      **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : ModulePtr - Module base address                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : SPI_RX_IN_PROGRESS: RX on going.                        **
**                   SPI_RX_COMPLETED:Rx completed                            **
**                                                                            **
** Description      : return the Rx completion status                         **
*******************************************************************************/
IFX_INLINE uint32 Spi_lHwGetRxStatus(const Ifx_QSPI *ModulePtr)
{
  uint32 Temp;
  uint32 RetVal;

  Temp = (uint32)(((uint32)SPI_SFR_RUNTIME_USER_MODE_READ32\
         (ModulePtr->STATUS.U)) & SPI_STATUS_CLEARMASK3)>>SPI_STATUS_RXF_BITPOS;
  if (Temp == 0U)
  {
    RetVal = SPI_RX_IN_PROGRESS; /* Tx on going */
  }
  else
  {
    RetVal = SPI_RX_COMPLETED; /* Tx completed */
  }
  return RetVal;
}

/*******************************************************************************
** Syntax           :  static void Spi_lHwGpioSetPortPin                      **
** (                                                                          **
**   uint16 CSPin, uint8 CSPolarity, uint8 ApiAccessId                        **
** )                                                                          **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Asynchronous                                            **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : CSPin - Chipselect pin no                               **
**                  : CSPolarity - Chipselect polarity                        **
**                  : ApiAccessId   - API access type                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
**                                                                            **
** Description      : Set the Gpio Port Pin to given value                    **
*******************************************************************************/
static void Spi_lHwGpioSetPortPin(uint16 CSPin, uint8 CSPolarity, uint8 \
                                                                    ApiAccessId)
{
  Ifx_P* GetPortAddressPtr;
  uint32 Temp;

  Temp =  (uint32)SPI_PORT_RESET_BITS * CSPolarity;
  Temp += Spi_lGetCSPinOffset(CSPin);

  GetPortAddressPtr = Spi_lGetGpioAddr(Spi_lGetCSPortOffset(CSPin));
  Temp = (uint32)1U << Temp;
  #if (SPI_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  #if (SPI_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
  if (ApiAccessId == SPI_RUNTIME_ACCESS)
  {
    SPI_PORT_SFR_RUNTIME_USER_MODE_WRITE32(GetPortAddressPtr->OMR.U,Temp);
  }
  else
  #endif /*(SPI_USER_MODE_RUNTIME_API_ENABLE == STD_ON)*/
  #if (SPI_USER_MODE_DEINIT_API_ENABLE == STD_ON)
  if (ApiAccessId == SPI_DEINIT_ACCESS)
  {
    SPI_PORT_SFR_DEINIT_USER_MODE_WRITE32(GetPortAddressPtr->OMR.U,Temp);
  }
  else
  #endif /*(SPI_USER_MODE_DEINIT_API_ENABLE == STD_ON)*/
  #endif /*(SPI_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)*/
  {
    GetPortAddressPtr->OMR.U = Temp;
    UNUSED_PARAMETER(ApiAccessId)
  }
}

/*******************************************************************************
** Syntax : uint8 Spi_lGetModuleKind                                          **
** (                                                                          **
**   uint8 Module                                                             **
** )                                                                          **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : uint8                                                    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : uint8 ( SPI_ASIL_MASTER/SPI_QML_MASTER )                 **
**                                                                            **
** Description :  Returns if the Module is QM or ASIL Master                  **
**                                                                            **
**                                                                            **
*******************************************************************************/
#if (SPI_SAFETY_ENABLE == STD_ON)
/* AI00237167: Windriver compiler bug workaround. IFX_INLINE removed */
uint8 Spi_lGetModuleKind(uint8 Module)
{
  uint8 RetVal;
  /* if module belongs to ASIL master */
  if (((uint32)SPI_ASIL_MASTER_MODULE_USED & ((uint32)0x01U << Module)) != 0U)
  {
    RetVal = SPI_ASIL_MASTER;
  }
  else
  {
    RetVal = SPI_QM_MASTER;
  }
  return RetVal;
}
#endif

/*******************************************************************************
** Syntax : Spi_SafetyJobType Spi_lGetJobKind                                 **
** (                                                                          **
**   Spi_JobType JobId                                                        **
** )                                                                          **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Spi_JobType                                              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Spi_SafetyJobType ( SPI_ASIL_JOB/SPI_QM_JOB )            **
**                                                                            **
** Description :  Returns if the Job belongs to is QM or ASIL                 **
**                                                                            **
**                                                                            **
*******************************************************************************/
#if (SPI_SAFETY_ENABLE == STD_ON)
Spi_SafetyJobType Spi_lGetJobKind (Spi_JobType JobId )
{
  Spi_SafetyJobType RetVal;
  uint8 Module;

  /* Spi HW Unit bit[3:0]: holds the hardware module no */
 /*IFX_MISRA_RULE_17_04_STATUS="SpiJobConfigPtr" Pointer arithmetic used due to
    PBConfigStructure and is within allowed range.*/
  Module = (Spi_kConfigPtr->SpiJobConfigPtr[JobId].HwUnit & SPI_HWUNIT_MASK);

  if(SPI_ASIL_MASTER == Spi_lGetModuleKind(Module))
  {
    RetVal = SPI_ASIL_JOB;
  }
  else
  {
    RetVal = SPI_QM_JOB;
  }
  return RetVal;
}
#endif

/*******************************************************************************
** Syntax : Spi_SafetySeqType Spi_lGetSequenceKind                            **
** (                                                                          **
**   Spi_SequenceType SequenceId                                              **
** )                                                                          **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Spi_SafetySeqType                                        **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Spi_SafetySeqType                                        **
**                                                                            **
**                                                                            **
** Description :  Returns if the sequence is of QM or ASIL type               **
**                                                                            **
**                                                                            **
*******************************************************************************/
#if (SPI_SAFETY_ENABLE == STD_ON)
Spi_SafetySeqType Spi_lGetSequenceKind (Spi_SequenceType SequenceId )
{
  const Spi_SequenceConfigType* ParamSeqConfigPtr;
  Spi_JobType JobId;
  Spi_SafetySeqType RetVal;
  uint8 Module;

  /*IFX_MISRA_RULE_17_04_STATUS="SpiSequenceConfigPtr" Pointer arithmetic used
    due to PBConfigStructure and is within allowed range.*/
  ParamSeqConfigPtr = &(Spi_kConfigPtr->SpiSequenceConfigPtr[SequenceId]);

  /*IFX_MISRA_RULE_17_04_STATUS="JobLinkPtr" Pointer arithmetic used due to
    PBConfigStructure and is within allowed range.*/
  JobId = ParamSeqConfigPtr->JobLinkPtr[0U]; /* First Job Of sequence */

  /* Spi HW Unit bit[3:0]: holds the hardware module no */
 /*IFX_MISRA_RULE_17_04_STATUS="SpiJobConfigPtr" Pointer arithmetic used due to
    PBConfigStructure and is within allowed range.*/
  Module = (Spi_kConfigPtr->SpiJobConfigPtr[JobId].HwUnit & SPI_HWUNIT_MASK);

  if(SPI_ASIL_MASTER == Spi_lGetModuleKind(Module))
  {
    RetVal = SPI_ASIL_SEQUENCE;
  }
  else
  {
    RetVal = SPI_QM_SEQUENCE;
  }
  return RetVal;
}
#endif

/*******************************************************************************
** Syntax : IFX_INLINE uint8 Spi_lGetQmModuleVarIndex(uint32 Module)          **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : uint32 Module                                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : uint8 : index of QM variable(Spi_ChnlAccessType)         **
**                           of the module                                    **
**                                                                            **
**                                                                            **
** Description :  Returns index of QM variable(Spi_ChnlAccessType)            **
**                           of the module                                    **
**                                                                            **
*******************************************************************************/
IFX_INLINE uint8 Spi_lGetQmModuleVarIndex(uint32 Module)
{
  uint8  Index,LowerQmModuleCnt;
  uint32 QmMasterModulesUsed;

  LowerQmModuleCnt = 0U;
  /* Workaround for Misra rule 13.7 */
  #if (SPI_LEVEL_DELIVERED != 0U)
  if(Spi_lModuleConfiguredAndAsync((uint8)Module) != 0U)
  {
    #if (SPI_SAFETY_ENABLE == STD_ON)
      /* Take only QM modules configured as ASYNC
      SPI_QM_MASTER_MODULES_USED -> excludes Safety master of SYNC/ASYNC kind
      SPI_ASYNC_MODULES -> excludes Sync modules
      AND of both give ASYNC QM modules used */
      QmMasterModulesUsed = SPI_QM_MASTER_MODULES_USED & SPI_ASYNC_MODULES;
    #else
      QmMasterModulesUsed = SPI_ASYNC_MODULES;
    #endif
  }
  else
  #endif
  {
    QmMasterModulesUsed = SPI_QM_MASTER_MODULES_USED;
  }

  /* count the number of bits which are SET below Module*/
  for( Index = 0U; Index < Module; Index++ )
  {
    if((QmMasterModulesUsed >> Index) & 0x01U)
    {
      if(Spi_lModuleConfigured((uint8)Index) != 0U)
      {
        LowerQmModuleCnt++;
      }
    }
  }
  return LowerQmModuleCnt;
}

#if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_ON)
/*******************************************************************************
** Syntax : IFX_INLINE uint8 Spi_lGetQmModuleVarIndexSeq                      **
**                                   (Spi_SequenceType SequenceId)            **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Spi_SequenceType SequenceId                              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : uint8 : index of QM variable(Spi_JobAndSeqAccessType)    **
**                           of the module                                    **
**                                                                            **
**                                                                            **
** Description :  Returns index of QM variable(Spi_JobAndSeqAccessType)       **
**                           of the module                                    **
**                                                                            **
*******************************************************************************/
IFX_INLINE uint8 Spi_lGetQmModuleVarIndexSeq(Spi_SequenceType SequenceId)
{
  const Spi_SequenceConfigType* ParamSeqConfigPtr;
  Spi_JobType JobId;
  uint8 Module;

  /*IFX_MISRA_RULE_17_04_STATUS="SpiSequenceConfigPtr" Pointer arithmetic used
    due to PBConfigStructure and is within allowed range.*/
  ParamSeqConfigPtr = &(Spi_kConfigPtr->SpiSequenceConfigPtr[SequenceId]);

  /*IFX_MISRA_RULE_17_04_STATUS="JobLinkPtr" Pointer arithmetic used due to
    PBConfigStructure and is within allowed range.*/
  JobId = ParamSeqConfigPtr->JobLinkPtr[0U]; /* First Job Of sequence */

  /* Spi HW Unit bit[3:0]: holds the hardware module no */
  /*IFX_MISRA_RULE_17_04_STATUS="SpiJobConfigPtr" Pointer arithmetic used due to
    PBConfigStructure and is within allowed range.*/
  Module = (Spi_kConfigPtr->SpiJobConfigPtr[JobId].HwUnit & SPI_HWUNIT_MASK);

  return Spi_lGetQmModuleVarIndex((uint32)Module);
}
#endif

#if  (SPI_LEVEL_DELIVERED != 0U)
/*******************************************************************************
** Syntax : IFX_LOCAL_INLINE void Spi_lSetAsyncBusStatus                      **
**                                               (Spi_StatusType SetStatusVal)**
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Spi_StatusType SetStatusVal                              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description :  Sets both QM and ASIL AsyncBusStatus with SetStatusVal      **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lSetAsyncBusStatus(Spi_StatusType SetStatusVal)
{
  #if(SPI_ASYNC_PARALLEL_TRANSMIT == STD_ON)  \
        && (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
  uint8 QmModIndex;
  #endif

  #if (SPI_ASIL_MASTER_ASYNC_USED == STD_ON)
  Spi_AsilAsyncBusStatus = SetStatusVal;
  #endif
  #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
  #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
    Spi_AsyncBusStatus = SetStatusVal;
  #else
  QmModIndex = 0U;
  #if(SPI_NUM_QM_ASYNC_MASTERS > 1U)
  do
  {
  #endif
    Spi_AsyncBusStatus[QmModIndex] = SetStatusVal;
  #if(SPI_NUM_QM_ASYNC_MASTERS > 1U)
    QmModIndex++;
  }while(QmModIndex < SPI_NUM_QM_ASYNC_MASTERS);
  #endif

  #endif
  #endif
  /* (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U) */
}

/*******************************************************************************
** Syntax : IFX_LOCAL_INLINE void Spi_lSetModAsyncBusStatus                   **
**                                 (Spi_StatusType SetStatusVal, uint8 Module)**
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Spi_StatusType SetStatusVal, uint8 Module                **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description :  Sets QM/ASIL AsyncBusStatus based on module                 **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lSetModAsyncBusStatus(Spi_StatusType SetStatusVal,
                                                                  uint8 Module)
{
  /* if ASIL master module is ASYNC */
  #if  ((SPI_ASIL_MASTER_ASYNC_USED == STD_ON) && \
       (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U))

  if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)Module))
  {
    Spi_AsilAsyncBusStatus = SetStatusVal;
  }
  else
  {
    #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
    Spi_AsyncBusStatus = SetStatusVal;
    #else
    Spi_AsyncBusStatus[Spi_lGetQmModuleVarIndex((uint32)Module)] = SetStatusVal;
    #endif
  }
  #elif (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
   #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
  Spi_AsyncBusStatus = SetStatusVal;
   #else
  Spi_AsyncBusStatus[Spi_lGetQmModuleVarIndex((uint32)Module)] = SetStatusVal;
   #endif
  UNUSED_PARAMETER(Module)
  #else
  Spi_AsilAsyncBusStatus = SetStatusVal;
  UNUSED_PARAMETER(Module)
  #endif
}

/*******************************************************************************
** Syntax : IFX_LOCAL_INLINE void Spi_lSetSeqAsyncBusStatus                   **
**                     (Spi_StatusType SetStatusVal,Spi_SequenceType Sequence)**
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : Spi_StatusType SetStatusVal, Spi_SequenceType Sequence   **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description :  Sets QM/ASIL AsyncBusStatus based on Sequence               **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE void Spi_lSetSeqAsyncBusStatus(Spi_StatusType SetStatusVal,
                                                     Spi_SequenceType Sequence)
{
  #if  ((SPI_ASIL_MASTER_ASYNC_USED == STD_ON) && \
       (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U))

  if( SPI_ASIL_SEQUENCE == Spi_lGetSequenceKind(Sequence) )
  {
    Spi_AsilAsyncBusStatus = SetStatusVal;
  }
  else
  {
    #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
    Spi_AsyncBusStatus = SetStatusVal;
    #else
    Spi_AsyncBusStatus[Spi_lGetQmModuleVarIndexSeq(Sequence)] = SetStatusVal;
    #endif
  }
  #elif (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
    #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
    Spi_AsyncBusStatus = SetStatusVal;
    #else
    Spi_AsyncBusStatus[Spi_lGetQmModuleVarIndexSeq(Sequence)] = SetStatusVal;
    #endif
  UNUSED_PARAMETER(Sequence)
  #else
  Spi_AsilAsyncBusStatus = SetStatusVal;
  UNUSED_PARAMETER(Sequence)
  #endif
}

/*******************************************************************************
** Syntax : IFX_LOCAL_INLINE Spi_StatusType Spi_lGetAsyncBusStatus(void)      **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Spi_StatusType                                           **
**                                                                            **
** Description :  Returns QM and ASIL AsyncBusStatus whichever is higher      **
*******************************************************************************/
IFX_LOCAL_INLINE Spi_StatusType Spi_lGetAsyncBusStatus(void)
{
  Spi_StatusType RetVal,RetVal1,RetVal2;
  #if((SPI_ASYNC_PARALLEL_TRANSMIT == STD_ON) \
               && (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U))
  uint8 QmModIndex;
  #endif

  #if (SPI_ASIL_MASTER_ASYNC_USED == STD_OFF)
  RetVal1 = (Spi_StatusType)SPI_UNINIT;
  #endif

  #if ((SPI_QM_ASYNC_MASTER_MODULES_USED == 0U) || \
       (SPI_ASYNC_PARALLEL_TRANSMIT == STD_ON))
  RetVal2 = (Spi_StatusType)SPI_UNINIT;
  #endif

  /* if ASIL master module is ASYNC */
  #if (SPI_ASIL_MASTER_ASYNC_USED == STD_ON)
  RetVal1 = Spi_AsilAsyncBusStatus;
  #endif

  #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
  #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
  RetVal2 = Spi_AsyncBusStatus;
  #else
  QmModIndex = 0U;
  #if(SPI_NUM_QM_ASYNC_MASTERS > 1U)
  do
  {
  #endif
    if(Spi_AsyncBusStatus[QmModIndex] > RetVal2)
    {
      RetVal2 = Spi_AsyncBusStatus[QmModIndex];
    }
  #if(SPI_NUM_QM_ASYNC_MASTERS > 1U)
    QmModIndex++;
  }while(QmModIndex < SPI_NUM_QM_ASYNC_MASTERS);
  #endif

  #endif
  #endif

  if(RetVal2 > RetVal1)
  {
    RetVal = RetVal2;
  }
  else
  {
    RetVal = RetVal1;
  }
  return (RetVal);
}

/*******************************************************************************
** Syntax : IFX_LOCAL_INLINE Spi_StatusType Spi_lGetModAsyncBusStatus         **
**                                                              (uint8 Module)**
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Spi_StatusType                                           **
**                                                                            **
** Description :  Returns QM and ASIL AsyncBusStatus based on Module          **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE Spi_StatusType Spi_lGetModAsyncBusStatus(uint8 Module)
{
  Spi_StatusType RetVal;
  #if  ((SPI_ASIL_MASTER_ASYNC_USED == STD_ON) && \
       (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U))

  if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)Module))
  {
    RetVal = Spi_AsilAsyncBusStatus;
  }
  else
  {
    #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
    RetVal = Spi_AsyncBusStatus;
    #else
    RetVal = Spi_AsyncBusStatus[Spi_lGetQmModuleVarIndex((uint32)Module)];
    #endif
  }
  #elif (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
    #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
    RetVal = Spi_AsyncBusStatus;
    #else
    RetVal = Spi_AsyncBusStatus[Spi_lGetQmModuleVarIndex((uint32)Module)];
    #endif
    UNUSED_PARAMETER(Module)
  #else
  RetVal = Spi_AsilAsyncBusStatus;
  UNUSED_PARAMETER(Module)
  #endif
  return (RetVal);
}

/*******************************************************************************
** Syntax : IFX_LOCAL_INLINE Spi_StatusType Spi_lGetSeqAsyncBusStatus         **
**                                                 (Spi_SequenceType Sequence)**
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Spi_StatusType                                           **
**                                                                            **
** Description :  Returns QM and ASIL AsyncBusStatus based on Module          **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE Spi_StatusType Spi_lGetSeqAsyncBusStatus
                                                    (Spi_SequenceType Sequence)
{
  Spi_StatusType RetVal;
  #if ((SPI_ASIL_MASTER_ASYNC_USED == STD_ON) && \
       (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U))
  if( SPI_ASIL_SEQUENCE == Spi_lGetSequenceKind(Sequence))
  {
    RetVal = Spi_AsilAsyncBusStatus;
  }
  else
  {
    #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
    RetVal = Spi_AsyncBusStatus;
    #else
    RetVal = Spi_AsyncBusStatus[Spi_lGetQmModuleVarIndexSeq(Sequence)];
    #endif
  }
  #elif (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
    #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
    RetVal = Spi_AsyncBusStatus;
    #else
    RetVal = Spi_AsyncBusStatus[Spi_lGetQmModuleVarIndexSeq(Sequence)];
    #endif
    UNUSED_PARAMETER(Sequence)
  #else
  RetVal = Spi_AsilAsyncBusStatus;
  UNUSED_PARAMETER(Sequence)
  #endif
  return (RetVal);
}
#endif
/*(SPI_LEVEL_DELIVERED != 0U)*/

/*******************************************************************************
** Syntax : static Std_ReturnType Spi_lHwDmaSfrInitCheck(void)                **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Std_ReturnType                                           **
**                                                                            **
**                                                                            **
** Description :  Returns E_OK if all the sfr values are as initialised       **
**                else returns E_NOT_OK                                       **
**                                                                            **
*******************************************************************************/
#if (SPI_SAFETY_ENABLE == STD_ON)
#if ( SPI_INITCHECK_API == STD_ON )
#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))
static Std_ReturnType Spi_lHwDmaSfrInitCheck(void)
{
  uint32            ModLoopCtr;
  #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
  uint32            QmModIndex;
  #endif
  Ifx_SRC_SRCR IntrSrc;
  volatile Ifx_SRC_SRCR_Bits *MoveEngCh0BaseAddr;
  Dma_ChannelType   DmaTransmitChannel;
  Dma_ChannelType   DmaReceiveChannel;
  uint32            Address,RemapAddress;
  uint32            ReadValue;
  volatile uint32   CompareValue;
  Std_ReturnType    RetVal;

  #if ((SPI_SAFETY_ENABLE == STD_ON) && (SPI_QM_ASYNC_MASTER_MODULES_USED ==0U))
  DmaTransmitChannel = DMA_CHANNEL_INVALID;
  DmaReceiveChannel = DMA_CHANNEL_INVALID;
  #endif

  MoveEngCh0BaseAddr = SRC_DMACH0ADDR;
  RetVal = E_NOT_OK;
  CompareValue = SPI_INITCHK_COMP_VALUE;

  ModLoopCtr = 0U;
  #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
  QmModIndex = 0U;
  #endif
  do
  {
    if(Spi_lModuleConfiguredAndAsync((uint8)ModLoopCtr) != 0U)
    {
      if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)ModLoopCtr))
      {
        DmaTransmitChannel = Spi_AsilChnlAccess[0U].DmaChannelIdx.TxDmaChannel;
        DmaReceiveChannel  = Spi_AsilChnlAccess[0U].DmaChannelIdx.RxDmaChannel;
      }
      else
      {
        #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
        DmaTransmitChannel = \
                       Spi_QmChnlAccess[QmModIndex].DmaChannelIdx.TxDmaChannel;
        DmaReceiveChannel  = \
                       Spi_QmChnlAccess[QmModIndex].DmaChannelIdx.RxDmaChannel;
        /* Increment only if  QM master module is configured as ASYNC  */
        QmModIndex++;
        #endif
      }

      /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
        to efficiently access the SFRs of multiple QSPI Modules.*/
      Address = ((uint32)&(SPI_HW_MODULE[ModLoopCtr].RXEXIT.U));

      /* Check Source Address */
      RemapAddress = (uint32)Mcal_GetDsprReMapAddress(Address);
      ReadValue = (uint32)(SPI_DMA_SFR_INIT_USER_MODE_READ32(MODULE_DMA.CH\
                                                   [DmaReceiveChannel].SADR.U));
      CompareValue &= (ReadValue ^ ~(RemapAddress));

      /* Check channel control register */
      ReadValue = (uint32)(SPI_DMA_SFR_INIT_USER_MODE_READ32(MODULE_DMA.\
                                            CH[DmaReceiveChannel].CHCFGR.U));
      CompareValue &= (ReadValue ^ ~((uint32)DMA_CHCFGR_RESETVAL));

      /* Check Destination Address */
      /*IFX_MISRA_RULE_17_04_STATUS="SPI_HW_MODULE" Pointer arithmetic is used
        to efficiently access the SFRs of multiple QSPI Modules.*/
      RemapAddress = Mcal_GetDsprReMapAddress(((uint32)&
                                   (SPI_HW_MODULE[ModLoopCtr].DATAENTRY[0])));
      ReadValue = (uint32)(SPI_DMA_SFR_INIT_USER_MODE_READ32\
                                    (MODULE_DMA.CH[DmaTransmitChannel].DADR.U));
      CompareValue &= (ReadValue ^ ~(RemapAddress));

      /* Check channel control register */
      ReadValue = (uint32)(SPI_DMA_SFR_INIT_USER_MODE_READ32\
                                  (MODULE_DMA.CH[DmaTransmitChannel].CHCFGR.U));
      CompareValue &= (ReadValue ^ ~((uint32)DMA_CHCFGR_RESETVAL));

      /* DMA Error Initialization */
      ReadValue = ((uint32)(((uint32)SPI_DMA_SFR_INIT_USER_MODE_READ32\
        (MODULE_DMA.CH[DmaReceiveChannel].ADICR.U)) & SPI_DMA_ADICR_CLEARMASK2)\
                                                   >>SPI_DMA_ADICR_ETRL_BITPOS);
      CompareValue &= (ReadValue ^ ~((uint32)1U));

      ReadValue = ((uint32)(((uint32)SPI_DMA_SFR_INIT_USER_MODE_READ32\
       (MODULE_DMA.CH[DmaTransmitChannel].ADICR.U)) & SPI_DMA_ADICR_CLEARMASK2)\
                                                   >>SPI_DMA_ADICR_ETRL_BITPOS);
      CompareValue &= (ReadValue ^ ~((uint32)1U));

      /* Check Interrupt Control  */
      ReadValue = ((uint32)(((uint32)SPI_DMA_SFR_INIT_USER_MODE_READ32\
        (MODULE_DMA.CH[DmaReceiveChannel].ADICR.U)) & SPI_DMA_ADICR_CLEARMASK3)\
                                                        >>SPI_DMA_ADICR_BITPOS);
      CompareValue &= (ReadValue ^ ~((uint32)SPI_DMA_INTCT));

      /* The following registers are updated for INTERRUPT mode only and not
      applicable for POLLING MODE. However when safety is ON it is mandated
      that the user switches to INTERRUPT mode immediately after initalisation
      and before Spi_InitCheck is called */

      #if ( ((SPI_LEVEL_DELIVERED == 1U) &&                                 \
             (SPI_ASYNC_MODE_LEVEL1 == SPI_ASYNC_MODE_INTERRUPT))           \
             || (SPI_LEVEL_DELIVERED == 2U))
      /*Check the DMA SRE for aync modules only */
      /*IFX_MISRA_RULE_17_04_STATUS="MoveEngCh0BaseAddr" Pointer arithmetic is
        used to efficiently access the SFRs of multiple QSPI Modules.*/
      IntrSrc.U =(unsigned_int)SPI_IRQ_SFR_INIT_USER_MODE_READ32\
                                             ((*(((volatile Ifx_SRC_SRCR*)\
                   (volatile void*)MoveEngCh0BaseAddr) + DmaReceiveChannel)).U);
      ReadValue = (uint32)IntrSrc.B.SRE;
      CompareValue &= (ReadValue ^ ~((uint32)1U));

      /*IFX_MISRA_RULE_17_04_STATUS="MoveEngCh0BaseAddr" Pointer arithmetic is
        used to efficiently access the SFRs of multiple QSPI Modules.*/
      IntrSrc.U =(unsigned_int)SPI_IRQ_SFR_INIT_USER_MODE_READ32\
                                              ((*(((volatile Ifx_SRC_SRCR*)\
                  (volatile void*)MoveEngCh0BaseAddr) + DmaTransmitChannel)).U);
      ReadValue = (uint32)IntrSrc.B.SRE;
      CompareValue &= (ReadValue ^ ~((uint32)0U));
      #endif
    }
    else
    {
      /* Do nothing if QSPI module is not configured */
    }
    ModLoopCtr++;
  }while (ModLoopCtr < SPI_MAX_HW_UNIT);

  if (CompareValue == SPI_INITCHK_COMP_VALUE)
  {
    RetVal = E_OK;
  }
  return RetVal;
}
#endif
#endif
/* ( SPI_INITCHECK_API == STD_ON )*/
#endif
/* (SPI_SAFETY_ENABLE == STD_ON)*/

/*******************************************************************************
** Syntax : static Std_ReturnType Spi_lInitGlobalVarCheck(void)               **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Std_ReturnType                                           **
**                                                                            **
**                                                                            **
** Description :  Returns E_OK if all the global variable values are          **
**                as initialised else returns E_NOT_OK                        **
**                                                                            **
*******************************************************************************/
#if (SPI_SAFETY_ENABLE == STD_ON)
#if ( SPI_INITCHECK_API == STD_ON )
static Std_ReturnType Spi_lInitGlobalVarCheck(void)
{
  #if (SPI_CHANNEL_BUFFERS_ALLOWED != 1U)
  uint32 BufferIndex = 0U;
  const Spi_ChannelConfigType* ChannelConfigPtr;
  #endif

  uint32            Index = 0U;
  #if(SPI_LEVEL_DELIVERED != 0U)
  uint32            ModLoopCtr;
  #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
  uint32            QmModIndex;
  #endif
  #endif

  #if (SPI_CHANNEL_BUFFERS_ALLOWED != 1U)
  uint32            CompareCtr = 0U;
  #endif

  uint32            ReadValue;
  volatile uint32   CompareValue;
  Std_ReturnType    RetVal;

  CompareValue = SPI_INITCHK_COMP_VALUE;
  RetVal = E_NOT_OK;

  #if(SPI_LEVEL_DELIVERED != 0U)
  ModLoopCtr = 0U;
  #endif

#if (SPI_LEVEL_DELIVERED == 0U)

  #if (SPI_CHANNEL_BUFFERS_ALLOWED != 1U)
  ChannelConfigPtr = Spi_kConfigPtr->SpiChannelConfigPtr;
  #endif

  do
  {
    #if (SPI_CHANNEL_BUFFERS_ALLOWED == 2U)
    if (ChannelConfigPtr->ChannelBufferType == SPI_IB_BUFFER)
    #endif
    /*(SPI_CHANNEL_BUFFERS_ALLOWED == 2U)*/
    #if (SPI_CHANNEL_BUFFERS_ALLOWED != 1U)
    {
      /* Check the Stored Buffer Offset Position for IB Channels */
      ReadValue = (uint32)BufferIndex;
      CompareValue &= (ReadValue ^ ~((uint32)Spi_IBBufferAccess.\
                                                       IBBufferOffset[Index]));
      BufferIndex = BufferIndex + (uint32)ChannelConfigPtr->NoOfBuffers;

      CompareCtr++; /*count the number of IB channels to compare later */
    }
   /*IFX_MISRA_RULE_17_04_STATUS="ChannelConfigPtr" Pointer arithmetic used due
      to PBConfigStructure and is within allowed range.*/
    ChannelConfigPtr++;
    #endif
    /*(SPI_CHANNEL_BUFFERS_ALLOWED != 1U) */
    Index++;
  }while (Index < (uint32)Spi_kConfigPtr->NoOfChannels);

  #if (SPI_CHANNEL_BUFFERS_ALLOWED != 1U)
  ReadValue = (uint32)CompareCtr;
  CompareValue &= (ReadValue ^ ~((uint32)Spi_NoOfIBChannels));
  #endif

  #if (SPI_CHANNEL_BUFFERS_ALLOWED != 1U)
  Index = 0U;
  #if(SPI_WRITELOCK_INDEX >1U)
  do
  {
  #endif
    ReadValue = (uint32)0U;
    CompareValue &= (ReadValue ^ ~((uint32)Spi_IBBufferAccess.\
                                                     ChannelWriteLock[Index]));
  #if(SPI_WRITELOCK_INDEX >1U)
    Index++;
  }while (Index < SPI_WRITELOCK_INDEX);
  #endif
  #endif

#endif
/* (SPI_LEVEL_DELIVERED == 0U) */

#if ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))

  #if (SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)
  Index = 0U;
  #if(SPI_MAX_JOB_TRIG_Q_LENGTH > 1U)
  do
  {
  #endif
    ReadValue = (uint32)0U;
    CompareValue &= (ReadValue ^ ~((uint32)Spi_AsilJobAndSeqAccess.\
                                                    JobQueueRearrange[Index]));

    ReadValue = (uint32)0U;
    CompareValue &= (ReadValue ^ ~((uint32)Spi_AsilJobAndSeqAccess.\
                                           JobLinkedSequenceRearrange[Index]));
    #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
    #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
    ReadValue = (uint32)0U;
    CompareValue &= (ReadValue ^ ~((uint32)Spi_QmJobAndSeqAccess.\
                                                    JobQueueRearrange[Index]));

    ReadValue = (uint32)0U;
    CompareValue &= (ReadValue ^ ~((uint32)Spi_QmJobAndSeqAccess.\
                                           JobLinkedSequenceRearrange[Index]));
    #else
    QmModIndex = 0U;
    #if(SPI_NUM_QM_ASYNC_MASTERS > 1U)
    do
    {
    #endif
      ReadValue = (uint32)0U;
      CompareValue &= (ReadValue ^ ~((uint32)Spi_QmJobAndSeqAccess[QmModIndex].\
                                                    JobQueueRearrange[Index]));

      ReadValue = (uint32)0U;
      CompareValue &= (ReadValue ^ ~((uint32)Spi_QmJobAndSeqAccess[QmModIndex].\
                                           JobLinkedSequenceRearrange[Index]));
    #if(SPI_NUM_QM_ASYNC_MASTERS > 1U)
      QmModIndex++;
    }while(QmModIndex < SPI_NUM_QM_ASYNC_MASTERS);
    #endif

    #endif
    #endif
  #if(SPI_MAX_JOB_TRIG_Q_LENGTH > 1U)
    Index++;
  }while(Index < SPI_MAX_JOB_TRIG_Q_LENGTH);
  #endif
  #endif

  #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
  QmModIndex = 0U;
  #endif

  do
  {
    if(SPI_ASIL_MASTER == Spi_lGetModuleKind((uint8)ModLoopCtr))
    {
      /* SPI_NUM_ASIL_MASTER_MODULES is always 1 hence index of 0 is used */
      ReadValue = (uint32)(Spi_kConfigPtr->HWModuleConfigPtr[ModLoopCtr]->\
                                                SpiDmaConfigPtr->TxDmaChannel);
      CompareValue &= (ReadValue ^ ~((uint32)Spi_AsilChnlAccess[0U].\
                                                  DmaChannelIdx.TxDmaChannel));

      ReadValue = (uint32)(Spi_kConfigPtr->HWModuleConfigPtr[ModLoopCtr]->\
                                                SpiDmaConfigPtr->RxDmaChannel);
      CompareValue &= (ReadValue ^ ~((uint32)Spi_AsilChnlAccess[0U].\
                                                  DmaChannelIdx.RxDmaChannel));
    }
    else
    {
      #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
      /* fix for AI00238517 Point.7*/
      if(Spi_lModuleConfiguredAndAsync((uint8)ModLoopCtr) != 0U)
      {
        ReadValue = (uint32)(Spi_kConfigPtr->HWModuleConfigPtr[ModLoopCtr]->\
                                              SpiDmaConfigPtr->TxDmaChannel);
        CompareValue &= (ReadValue ^ ~((uint32)Spi_QmChnlAccess[QmModIndex].\
                                                DmaChannelIdx.TxDmaChannel));

        ReadValue = (uint32)(Spi_kConfigPtr->HWModuleConfigPtr[ModLoopCtr]->\
                                              SpiDmaConfigPtr->RxDmaChannel);
        CompareValue &= (ReadValue ^ ~((uint32)Spi_QmChnlAccess[QmModIndex].\
                                                DmaChannelIdx.RxDmaChannel));

        /* Increment only if module is configured as QM master module */
        QmModIndex++;
      }
      else
      {
        /* Do Nothing */
      }
      #endif
      /*(SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)  */
    }
    ModLoopCtr++;
  }while  (ModLoopCtr < SPI_MAX_HW_UNIT);

  #if (SPI_CHANNEL_BUFFERS_ALLOWED != 1U)
    ChannelConfigPtr = Spi_kConfigPtr->SpiChannelConfigPtr;
  #endif

  #if (SPI_CHANNEL_BUFFERS_ALLOWED != 1U)
  CompareCtr = 0U;
  #endif
  Index = 0U;
  do
  {
    #if (SPI_CHANNEL_BUFFERS_ALLOWED == 2U)
    if (ChannelConfigPtr->ChannelBufferType == SPI_IB_BUFFER)
    #endif
    /*(SPI_CHANNEL_BUFFERS_ALLOWED == 2U)*/
    #if (SPI_CHANNEL_BUFFERS_ALLOWED != 1U)
    {
      /* Check the Stored Buffer Offset Position for IB Channels */
      ReadValue = (uint32)BufferIndex;
      CompareValue &= (ReadValue ^ ~((uint32)Spi_IBBufferAccess.\
                                                       IBBufferOffset[Index]));
      BufferIndex = BufferIndex + (uint32)ChannelConfigPtr->NoOfBuffers;

      CompareCtr++; /*count the number of IB channels to compare later */
    }
    /*IFX_MISRA_RULE_17_04_STATUS="ChannelConfigPtr" Pointer arithmetic used due
      to PBConfigStructure and is within allowed range.*/
    ChannelConfigPtr++;
    #endif
    /*(SPI_CHANNEL_BUFFERS_ALLOWED != 1U) */
    Index++;
  }while (Index < (uint32)Spi_kConfigPtr->NoOfChannels);

  #if (SPI_CHANNEL_BUFFERS_ALLOWED != 1U)
  ReadValue = (uint32)CompareCtr;
  CompareValue &= (ReadValue ^ ~((uint32)Spi_NoOfIBChannels));
  #endif

  #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
  #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
  ReadValue = (uint32)Spi_AsyncBusStatus;
  CompareValue &= (ReadValue ^ ~((uint32)SPI_IDLE));
  #else
  QmModIndex = 0U;
  #if(SPI_NUM_QM_ASYNC_MASTERS > 1U)
  do
  {
  #endif
    ReadValue = (uint32)Spi_AsyncBusStatus[QmModIndex];
    CompareValue &= (ReadValue ^ ~((uint32)SPI_IDLE));
  #if(SPI_NUM_QM_ASYNC_MASTERS > 1U)
    QmModIndex++;
  }while(QmModIndex < SPI_NUM_QM_ASYNC_MASTERS);
  #endif

  #endif
  #endif

  /* if ASIL master module is ASYNC */
  #if (SPI_ASIL_MASTER_ASYNC_USED == STD_ON)
  ReadValue = (uint32)Spi_AsilAsyncBusStatus;
  CompareValue &= (ReadValue ^ ~((uint32)SPI_IDLE));
  #endif

  #if (SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)
  Index = Spi_kConfigPtr->NoOfSequences; /* Set Index to the last Sequence */
  do
  {
    Index--;

    ReadValue = (uint32)0U;
    CompareValue &= (ReadValue ^ ~((uint32)Spi_AsilJobAndSeqAccess.\
                                                      CurrentJobIndex[Index]));

    #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
    #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
    ReadValue = (uint32)0U;
    CompareValue &= (ReadValue ^ ~((uint32)Spi_QmJobAndSeqAccess.\
                                                      CurrentJobIndex[Index]));
    #else
    QmModIndex = 0U;
    #if(SPI_NUM_QM_ASYNC_MASTERS > 1U)
    do
    {
    #endif
      ReadValue = (uint32)0U;
      CompareValue &= (ReadValue ^ ~((uint32)Spi_QmJobAndSeqAccess[QmModIndex].\
                                                      CurrentJobIndex[Index]));
    #if(SPI_NUM_QM_ASYNC_MASTERS > 1U)
      QmModIndex++;
    }while(QmModIndex < SPI_NUM_QM_ASYNC_MASTERS);
    #endif

    #endif
    #endif
  }while (Index > 0U);
  #else
    ReadValue = (uint32)0U;
    CompareValue &= (ReadValue ^ ~((uint32)Spi_AsilJobAndSeqAccess.\
                                                             CurrentJobIndex));

    #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
    #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
    ReadValue = (uint32)0U;
    CompareValue &= (ReadValue ^ ~((uint32)Spi_QmJobAndSeqAccess.\
                                                             CurrentJobIndex));
    #else
    QmModIndex = 0U;
    #if(SPI_NUM_QM_ASYNC_MASTERS > 1U)
    do
    {
    #endif
      ReadValue = (uint32)0U;
      CompareValue &= (ReadValue ^ ~((uint32)Spi_QmJobAndSeqAccess[QmModIndex].\
                                                             CurrentJobIndex));
    #if(SPI_NUM_QM_ASYNC_MASTERS > 1U)
      QmModIndex++;
    }while(QmModIndex < SPI_NUM_QM_ASYNC_MASTERS);
    #endif

    #endif
    #endif
  #endif
  /*(SPI_INTERRUPTABLE_SEQUENCE_ALLOWED == STD_ON)*/

  #if (SPI_CHANNEL_BUFFERS_ALLOWED != 1U)
  Index = 0U;
  #if (SPI_WRITELOCK_INDEX > 1U)
  do
  {
  #endif
    ReadValue = (uint32)0U;
    CompareValue &= (ReadValue ^ ~((uint32)Spi_IBBufferAccess.\
                                                     ChannelWriteLock[Index]));
  #if (SPI_WRITELOCK_INDEX > 1U)
    Index++;
  }while (Index < SPI_WRITELOCK_INDEX);
  #endif
  #endif

  #if (SPI_LEVEL_DELIVERED == 2U)

  /* init sets the value to Polling user is expected to set it as
  SPI_ASYNC_MODE_INTERRUPT before starting any safety transmissions */
  ReadValue = (uint32)SPI_ASYNC_MODE_INTERRUPT;
  CompareValue &= (ReadValue ^ ~((uint32)Spi_AsyncMode));
  #endif
  /* (SPI_LEVEL_DELIVERED == 2U) */

#endif
/* ((SPI_LEVEL_DELIVERED == 1U) || (SPI_LEVEL_DELIVERED == 2U))  */

  /* The following global variables are common to all levels */
  ReadValue = (uint32)Spi_BusStatus;
  CompareValue &= (ReadValue ^ ~((uint32)SPI_IDLE));

  Index = 0U;
  #if (SPI_JOB_ASIL_ARRAY_INDEX > 1U)
  do
  {
  #endif
    ReadValue = (uint32)0U;
    CompareValue &= (ReadValue ^ ~((uint32)Spi_AsilJobResult[Index]));
  #if (SPI_JOB_ASIL_ARRAY_INDEX > 1U)
    Index++;
  }while (Index < SPI_JOB_ASIL_ARRAY_INDEX);
  #endif

  #if (SPI_QM_MASTER_MODULES_USED != 0U)
  Index = 0U;
  #if (SPI_JOB_QM_ARRAY_INDEX > 1U)
  do
  {
  #endif
    ReadValue = (uint32)0U;
    CompareValue &= (ReadValue ^ ~((uint32)Spi_QmJobResult[Index]));
  #if (SPI_JOB_QM_ARRAY_INDEX > 1U)
    Index++;
  }while (Index < SPI_JOB_QM_ARRAY_INDEX);
  #endif
  #endif

  Index = 0U;
  #if (SPI_SEQUENCE_ASIL_ARRAY_INDEX > 1U)
  do
  {
  #endif
    ReadValue = (uint32)0U;
    CompareValue &= (ReadValue ^ ~((uint32)Spi_AsilSeqStatus[Index].\
                                                               AsilSeqStatus));

    #if ((SPI_CANCEL_API == STD_ON) && (SPI_LEVEL_DELIVERED != 0U))
    /* Clear the Status Variable */
    ReadValue = (uint32)0U;
    CompareValue &= (ReadValue ^ ~((uint32)Spi_AsilSeqStatus[Index].\
                                                         AsilSeqCancelStatus));
    #endif
  #if (SPI_SEQUENCE_ASIL_ARRAY_INDEX > 1U)
    Index++;
  }while (Index < SPI_SEQUENCE_ASIL_ARRAY_INDEX);
  #endif

  #if (SPI_QM_MASTER_MODULES_USED != 0U)
  Index = 0U;
  #if (SPI_SEQUENCE_QM_ARRAY_INDEX > 1U)
  do
  {
  #endif
    ReadValue = (uint32)0U;
    CompareValue &= (ReadValue ^ ~((uint32)Spi_QmSeqStatus[Index].\
                                                                 QmSeqStatus));

    #if ((SPI_CANCEL_API == STD_ON) && (SPI_LEVEL_DELIVERED != 0U))
    /* Clear the Status Variable */
    ReadValue = (uint32)0U;
    CompareValue &= (ReadValue ^ ~((uint32)Spi_QmSeqStatus[Index].\
                                                           QmSeqCancelStatus));
    #endif
  #if (SPI_SEQUENCE_QM_ARRAY_INDEX > 1U)
    Index++;
  }while (Index < SPI_SEQUENCE_QM_ARRAY_INDEX);
  #endif
  #endif

  #if  (SPI_LEVEL_DELIVERED != 0U)
  Index = 0U;
  #if(SPI_MAX_JOB_TRIG_Q_LENGTH > 1U)
  do
  {
  #endif
    ReadValue = (uint32)SPI_SEQ_IDLE_ID;
    CompareValue &= (ReadValue ^ ~((uint32)Spi_AsilJobAndSeqAccess.\
                                                         JobLinkedSeq[Index]));

    ReadValue = (uint32)SPI_JOB_IDLE_ID;
    CompareValue &= (ReadValue ^ ~((uint32)Spi_AsilJobAndSeqAccess.\
                                                             JobQueue[Index]));

    #if (SPI_QM_ASYNC_MASTER_MODULES_USED != 0U)
    #if (SPI_ASYNC_PARALLEL_TRANSMIT == STD_OFF)
    ReadValue = (uint32)SPI_SEQ_IDLE_ID;
    CompareValue &= (ReadValue ^ ~((uint32)Spi_QmJobAndSeqAccess.\
                                                         JobLinkedSeq[Index]));

    ReadValue = (uint32)SPI_JOB_IDLE_ID;
    CompareValue &= (ReadValue ^ ~((uint32)Spi_QmJobAndSeqAccess.\
                                                             JobQueue[Index]));
    #else
    QmModIndex = 0U;
    #if(SPI_NUM_QM_ASYNC_MASTERS > 1U)
    do
    {
    #endif
      ReadValue = (uint32)SPI_SEQ_IDLE_ID;
      CompareValue &= (ReadValue ^ ~((uint32)Spi_QmJobAndSeqAccess[QmModIndex].\
                                                         JobLinkedSeq[Index]));

      ReadValue = (uint32)SPI_JOB_IDLE_ID;
      CompareValue &= (ReadValue ^ ~((uint32)Spi_QmJobAndSeqAccess[QmModIndex].\
                                                             JobQueue[Index]));
    #if(SPI_NUM_QM_ASYNC_MASTERS > 1U)
      QmModIndex++;
    }while(QmModIndex < SPI_NUM_QM_ASYNC_MASTERS);
    #endif

    #endif
    #endif

  #if(SPI_MAX_JOB_TRIG_Q_LENGTH > 1U)
    Index++;
  }while (Index < SPI_MAX_JOB_TRIG_Q_LENGTH);
  #endif
  #endif

  if (CompareValue == SPI_INITCHK_COMP_VALUE)
  {
    RetVal = E_OK;
  }
  return RetVal;
}
#endif
#endif
/* (SPI_SAFETY_ENABLE == STD_ON)*/

/*Memory Map of the SPI Code*/
#define SPI_STOP_SEC_CODE
/*
  Allows to map variables, constants and code of modules to individual
  memory sections.
*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
**                            General Notes                                   **
*******************************************************************************/

