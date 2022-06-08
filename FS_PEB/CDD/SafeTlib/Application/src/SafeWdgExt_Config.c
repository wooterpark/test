/*******************************************************************************
** Copyright (C) Infineon Technologies (2014)                                 *
*
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                           **
**  $FILENAME   : SafeWdgExt_Config.c $                                      **
**                                                                           **
**  $CC VERSION : \main\15 $                                                 **
**                                                                           **
**  $DATE       : 2015-12-21 $                                               **
**                                                                           **
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
**                 - Functionality for extlernal watchdog specific functions  **
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
#include "Irq.h"
#include "Mcal_Compiler.h"
#include "Sl_Timeout.h"
#include "SafeWdgExt_Config.h"
#include "Mcal_WdgLib.h"

#ifdef SWDG_EXT_CIC_WDG_ONLY
#include "ChipId.h"
#include "IfxStm_reg.h"
#include "IfxPort_reg.h"
#include "SafeWdgAscLin.h"
#include "IfxAsclin_reg.h"
#include "IfxSrc_reg.h"
#include "IfxGtm_reg.h"
#include "IfxGtm_regdef.h"

#endif /*SWDG_EXT_CIC_WDG_ONLY*/
#include "IfxDma_reg.h"
#if (defined SWDG_EXT_TLF_WDG_ONLY) || (defined SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG)
/* CCUCON0 bits: */
#define CCUCON0_BAUD2DIV_MASK   ( (uint32)0x000000F0U )
#define CCUCON0_BAUD2DIV_POS    ( 4 )
#define CCUCON0_UP_BIT          ( (uint32)0x40000000U )

/* MOD_SRC bits: */
#define SRC_SRE_POS             ( 10 )
#define SRC_TOS_POS             ( 11 )

#ifdef SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG /*Timer functions are required 
                                            only for Window wdg in WDI mode*/
#define IOCR_PC_MASK              ( (uint32)0x0000001FU )
#define IOCR_GPOUT_PP             ( (uint8)0x10U )
                                            
static void SafeWdgExtTlf_lSetupIocrPc (  Ifx_P* Port,uint8 Pin,uint8 Pc);
#endif /*SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG*/

#endif /* SWDG_EXT_TLF_WDG_ONLY -SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG*/
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/


/*******************************************************************************
**                   Function like macro definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

#ifdef SWDG_EXT_CIC_WDG_ONLY

/* Clear Interrupt flag */
#define SAFEWDGASCLIN_CLEAR_IRQFLAG        (0x0001u)

/* Configure Period for TOM channel-OSM (100 us wait) */
#if((CHIP_ID == 21U) || (CHIP_ID == 22U))
#define SAFEWDGCIC_TOM_CH_OSMWAIT_PERIOD   (0x1388u)
#else
#define SAFEWDGCIC_TOM_CH_OSMWAIT_PERIOD   (0x2710u)
#endif

#define SAFEWDGASCLIN_CFG_REF_NO           (0u)





#endif /*SWDG_EXT_CIC_WDG_ONLY*/
#define DMA_ENABLE_TIMEOUT                 (0x100u)


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
  
#define IFX_APPL_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"  


   /****************************************************************************
     ** Traceability      : [cover parentID=]        [/cover]                 **
     **                                                                       **
     ** Syntax           : void SafeWdgExt_Config_DMA (void)               **
     **                                                                       **
     **                                                                       **
     ** Service ID       : none                                               **
     **                                                                       **
     ** Sync/Async       : Synchronous                                        **
     **                                                                       **
     ** Reentrancy       : Non Reentrant                                      **
     **                                                                       **
     ** Parameters(in)   : none                                               **
     **                                                                       **
     ** Parameters (out) : none                                               **
     **                                                                       **
     ** Return value     : none                                               **
     **                                                                       **
     ** Description      : Configure DMA channel to tranmit data              **
     **                                                                       **
     **************************************************************************/
     void SafeWdgExt_Config_DMA(void)
     {
	    /* External Cic Watchdog Configuration */
        	 
          
		  uint32 Timeout = DMA_ENABLE_TIMEOUT;
          /* configure Transmit DMA channel */
          /* Check if DMA module is enabled. If not enable it. */

         if (DMA_CLC.B.DISS != 0U)
         {

              Mcal_ResetENDINIT();
              /* DMA clock control register. */
              DMA_CLC.B.DISR   = 0x0U;

             Mcal_SetENDINIT();

            do
            {
               Timeout = Timeout - 1U;
               /* wait until module is enabled */
            }while ((DMA_CLC.B.DISS == 1U) && (0U < Timeout));

         }
  } 
  
#ifdef SWDG_EXT_CIC_WDG_ONLY
   /*******************************************************************************
    ** Traceability      : [cover parentID=]        [/cover]                      **
    **                                                                            **
    ** Syntax           : void SafeWdgExt_Config_Timer (void)                     **
    **                                                                            **
    **                                                                            **
    ** Service ID       : none                                                    **
    **                                                                            **
    ** Sync/Async       : Synchronous                                             **
    **                                                                            **
    ** Reentrancy       : Non Reentrant                                           **
    **                                                                            **
    ** Parameters(in)   : none                                                    **
    **                                                                            **
    ** Parameters (out) : none                                                    **
    **                                                                            **
    ** Return value     : none                                                    **
    **                                                                            **
    ** Description      : Configure TOM channel from GTM module                   **
    **                                                                            **
    *******************************************************************************/
    void SafeWdgExt_Config_Timer(void)
    {
        /* Enable GTM Module */
        Mcal_ResetENDINIT();
        MODULE_GTM.CLC.B.DISR = 0x0;
        Mcal_SetENDINIT();

        /* CMU Clock Initialization, system clock is selected as the clock source */
        MODULE_GTM.CMU.FXCLK.CTRL.B.FXCLK_SEL = 0x0;

        /* Enable the clock to TOM channel*/
        MODULE_GTM.CMU.CLK_EN.B.EN_FXCLK = 0x02;

        /* TOM0 CHANNEL0 Initialization */

        /* select clock divider as 2^0 */
        MODULE_GTM.TOM[0].CH0.CTRL.B.CLK_SRC_SR = 0x00;

        /* Force Update to update the CLK_SRC Register */
        MODULE_GTM.TOM[0].TGC0_FUPD_CTRL.B.FUPD_CTRL0 = 0x02;

        MODULE_GTM.TOM[0].CH0.CTRL.B.SL = 0x1;

        /* Reset when counter matches CM0 */
        MODULE_GTM.TOM[0].CH0.CTRL.B.RST_CCU0 = 0;

        /* Host Trigger to start TGC0 operation. This is Global TGC0 control register */
        MODULE_GTM.TOM[0].TGC0_GLB_CTRL.B.HOST_TRIG = 0x01;

        /* Configure Period (100 us, Clock Frequency is 100MHz) for Tom interrupt */
        MODULE_GTM.TOM[0].CH0.CM0.B.CM0 = SAFEWDGCIC_TOM_CH_OSMWAIT_PERIOD;

        /* Set Duty cycle to 0% */
        MODULE_GTM.TOM[0].CH0.CM1.B.CM1 = 0x0;       
     
   }
 	#endif	   

#ifdef SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG
static void SafeWdgExtTlf_lSetupIocrPc(Ifx_P* Port, uint8 Pin, uint8 Pc)
{
  uint8 PcShift;

  /* Calculate number of bits to shift the given PC value left: */
  PcShift = Pin % (uint8)4U;
  PcShift *= (uint8)8U;
  PcShift += (uint8)3U;

  /* Select correct IOCRx register: */
  if (Pin >= 12U)
  {
    /* Setup port I/O control in IOCR12: */
    Port->IOCR12.U &= ~(IOCR_PC_MASK << PcShift);
    Port->IOCR12.U |= (uint32)Pc << PcShift;
  } /* if (Pin >= 12U) */
  else if (Pin >= 8U)
  {
    /* Setup port I/O control in IOCR8: */
    Port->IOCR8.U &= ~(IOCR_PC_MASK << PcShift);
    Port->IOCR8.U |= (uint32)Pc << PcShift;
  } /* else if (Pin >= 8U) */
  else if (Pin >= 4U)
  {
    /* Setup port I/O control in IOCR4: */
    Port->IOCR4.U &= ~(IOCR_PC_MASK << PcShift);
    Port->IOCR4.U |= (uint32)Pc << PcShift;
  } /* else if (Pin >= 4U) */
  else
  {
    /* Setup port I/O control in IOCR0: */
    Port->IOCR0.U &= ~(IOCR_PC_MASK << PcShift);
    Port->IOCR0.U |= (uint32)Pc << PcShift;
  } /* if (Pin < 4U) */
} /* SafeWdgExtTlf_lSetupIocrPc */

#endif  
  


  /*****************************************************************************
  ** Traceability      : [cover parentID=]        [/cover]                    **
  **                                                                          **
  ** Syntax           : void SafeWdgExt_Config_Port (void)                    **
  **                                                                          **
  ** Service ID       : none                                                  **
  **                                                                          **
  ** Sync/Async       : Synchronous                                           **
  **                                                                          **
  ** Reentrancy       : Non Reentrant                                         **
  **                                                                          **
  ** Parameters(in)   : none                                                  **
  **                                                                          **
  ** Parameters (out) : none                                                  **
  **                                                                          **
  ** Return value     : none                                                  **
  **                                                                          **
  ** Description      : Configure ASCLIN / QSPI Port for communication with   **
  **                    CIC/ TLF.
  **                                                                          **
  ****************************************************************************/
 void SafeWdgExt_Config_Port(void)
{
   /* Configuration for External Cic Watchdog  */ 
   #ifdef SWDG_EXT_CIC_WDG_ONLY

     if (SafeWdgAscLin_ConfigRoot[SAFEWDGASCLIN_CFG_REF_NO].AscLinModule == &MODULE_ASCLIN1)
       {
            /* setup port configuration for ASCLIN1  */
            P15_IOCR4.B.PC5 = 0x12u;         /* ATX1 (TxData line) */
            P15_IOCR0.B.PC0 = 0x16u;         /* ASCLK1 (Clock)  */
            P20_IOCR8.B.PC8 = 0x12u;         /* SLSO1 (slave select) */
            P15_IOCR0.B.PC1 = 0x00u;         /* ARX1 set as input  */

       }
 #if((CHIP_ID != 21U) && (CHIP_ID != 22U) && (CHIP_ID != 23U))   
	   if (SafeWdgAscLin_ConfigRoot[SAFEWDGASCLIN_CFG_REF_NO].AscLinModule == &MODULE_ASCLIN3)
       {

           /* setup port configuration for ASCLIN3  */
           P00_IOCR0.B.PC0 = 0x13u;         /* ATX3 (TxData line) */
           P00_IOCR0.B.PC2 = 0x12u;         /* SCLK3 (Clock)  */
           P00_IOCR0.B.PC3 = 0x12u;         /* SLSO3 (slave select) */
           P00_IOCR0.B.PC1 = 0x00u;         /* ARX1 set as input  */

       }
#endif
   #endif
   
   /* Configuration for TLF Watchdog */
   #if defined (SWDG_EXT_TLF_WDG_ONLY) || defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG)  
       /* setup port configuration for QSPI0  */
        P20_IOCR4.B.PC6  =  0x13u;        /* SLSOx (slave select) */
        P20_IOCR8.B.PC11 =   0x13u;       /* SCLK (Clock)  */
        P20_IOCR12.B.PC14 = 0x13u;        /* MTSR (Master transmit slave receive line) */
        P33_IOCR4.B.PC5 = 0x12u;         
       /*SLSO pin for 22x target P33.5*/
       /*Setup WDI pin*/
       #ifdef SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG
       /*Setup WDI pin as IO pin. Currently P20.9 is configured as WDI pin*/
       SafeWdgExtTlf_lSetupIocrPc(&MODULE_P20,9,IOCR_GPOUT_PP);
       #endif

      
      Mcal_ResetENDINIT();/*Set to Speed grade 1 - Highest*/
      P20_PDR1.B.PD12 = 0x0u;
      P20_PDR1.B.PD14 = 0x0u;
      P20_PDR1.B.PD11 = 0x0u;
      P20_PDR0.B.PD7 = 0x0u;  
      Mcal_SetENDINIT();
   #endif
}


  /*******************************************************************************
  ** Traceability      : [cover parentID=]        [/cover]                      **
  **                                                                            **
  ** Syntax           : void SafeWdgExt_Config_Irq(void)                        **
  **                                                                            **
  ** Service ID       : none                                                    **
  **                                                                            **
  ** Sync/Async       : Synchronous                                             **
  **                                                                            **
  ** Reentrancy       : Non Reentrant                                           **
  **                                                                            **
  ** Parameters(in)   : None                                                    **
  **                                                                            **
  ** Parameters (out) : none                                                    **
  **                                                                            **
  ** Return value     : none                                                    **
  **                                                                            **
  ** Description      : Setup interrupt for receive transaction finished        **
  **                                                                            **
  *******************************************************************************/
 void SafeWdgExt_Config_Irq(void)
{

  /* Configuration for External Cic Watchdog  */ 
  #ifdef SWDG_EXT_CIC_WDG_ONLY
  
        /* Configure and Set up Interrupt for DMA transation */
        GTM_IRQ_MODE.U = 0x2;
        /*GTM_TOMi_Chi_IRQ_MODE = 0x2;*/
        MODULE_GTM.TOM[0].CH0.IRQ_MODE.U = 0x2;           
        
        /* Configure interrupt condition (CN0>=CM0) */
        MODULE_GTM.TOM[0].CH0.IRQ_NOTIFY.B.CCU0TC = 0x1;

        /* Interrupt is not required for CM1  */
        MODULE_GTM.TOM[0].CH0.IRQ_NOTIFY.B.CCU1TC = 0x0;

        /* Enable configured interrupt */
        MODULE_GTM.TOM[0].CH0.IRQ_EN.U = 0x1;

        /* Disable the output on pin */
        MODULE_GTM.TOM[0].TGC0_OUTEN_STAT.B.OUTEN_STAT0 = 0x01;


        /* Enable Interrupt, Set priority, Select TOS */
        MODULE_SRC.GTM.GTM[0].TOM[0][0].U = (0x0003 << 11u) | (0u << 10u)
                          | IRQ_GTM_TOM0_SR0_PRIO;
        /*  continuous mode */

        /* Initialize CN0 before enabling the Tom channel */
        MODULE_GTM.TOM[0].CH0.CN0.U=0x0u;

        /*Enable Tom channel */
        MODULE_GTM.TOM[0].TGC0_ENDIS_STAT.B.ENDIS_STAT0 = 0x02; 
        
  
#endif
  
  /* Configuration for TLF Watchdog */
  #if defined (SWDG_EXT_TLF_WDG_ONLY) || defined (SWDG_INT_CNR_WDG_EXT_TLF_WINDOW_WDG)
  SRC_QSPI0RX.U |= (IRQ_QSPI0_RX_TOS) | (1u << SRC_SRE_POS) | IRQ_QSPI0_RX_PRIO;
  Irq_InstallInterruptHandler(IRQ_QSPI0_RX_PRIO,(uint32)SafeWdgQspi_IsrTxRx);
  /* Setup fBAUD2 in CCUCON0 register */
  Mcal_ResetSafetyENDINIT_Timed(SL_SAFETY_ENDINT_TIMEOUT);
  SCU_CCUCON0.U &= ~CCUCON0_BAUD2DIV_MASK;
  SCU_CCUCON0.U |= (((uint32)10u) << CCUCON0_BAUD2DIV_POS) & CCUCON0_BAUD2DIV_MASK;
  SCU_CCUCON0.U |= CCUCON0_UP_BIT;
  Mcal_SetSafetyENDINIT_Timed();
  #endif
}


#define IFX_APPL_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"