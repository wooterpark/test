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
**  $FILENAME   : SafeWdgExtCic_Helper.c $                                   **
**                                                                           **
**  $CC VERSION : \main\4 $                                                  **
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
#include "SafeWdgExtCic_Helper.h"

#ifdef SWDG_EXT_CIC_WDG_ONLY
#include "ChipId.h"
#include "IfxStm_reg.h"
#include "IfxPort_reg.h"
#include "SafeWdgAscLin.h"
#include "IfxAsclin_reg.h"
#include "IfxSrc_reg.h"
#include "IfxGtm_reg.h"
#include "IfxGtm_regdef.h"
#include "IfxDma_reg.h"
#endif

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

#endif

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

#define IFX_APPL_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"  

#ifdef SWDG_EXT_CIC_WDG_ONLY
   
    /***************************************************************************
    ** Traceability      : [cover parentID=]        [/cover]                  **
    **                                                                        **
    ** Syntax           : void SafeWdgExt_Helper_EnableTOMChOSM(void)         **
    **                                                                        **
    ** Service ID       : none                                                **
    **                                                                        **
    ** Sync/Async       : Synchronous                                         **
    **                                                                        **
    ** Reentrancy       : Non Reentrant                                       **
    **                                                                        **
    ** Parameters(in)   : None                                                **
    **                                                                        **
    ** Parameters (out) : none                                                **
    **                                                                        **
    ** Return value     : none                                                **
    **                                                                        **
    ** Description      : Enable single shot mode of TOM channel              **
    **                    This is a callback function                         **
    ***************************************************************************/
    void SafeWdgExtCic_Helper_EnableTOMChOSM(void)
    {

       /*  continuous mode */
       
       /* clear pedning interrupt */
       MODULE_GTM.TOM[0].CH0.IRQ_NOTIFY.B.CCU0TC = 
                                                    SAFEWDGASCLIN_CLEAR_IRQFLAG;      
       MODULE_SRC.GTM.GTM[0].TOM[0][0].B.CLRR = 0x01u;
       /* Enable Interrupt */
       MODULE_SRC.GTM.GTM[0].TOM[0][0].B.SRE = 0x01u;      
      

    } /* SafeWdgExt_Helper_EnableTOMChOSM */


   /****************************************************************************
   ** Traceability      : [cover parentID=]        [/cover]                   **
   **                                                                         **
   ** Syntax           : void SafeWdgExt_Helper_DisableTOMChOSM(void)         **
   **                                                                         **
   ** Service ID       : none                                                 **
   **                                                                         **
   ** Sync/Async       : Synchronous                                          **
   **                                                                         **
   ** Reentrancy       : Non Reentrant                                        **
   **                                                                         **
   ** Parameters(in)   : None                                                 **
   **                                                                         **
   ** Parameters (out) : none                                                 **
   **                                                                         **
   ** Return value     : none                                                 **
   **                                                                         **
   ** Description      : Disable TOM channel. This is a call back function.   **
   **                                                                         **
   ****************************************************************************/
   void SafeWdgExtCic_Helper_DisableTOMChOSM(void)
   {     
     /* Disable Interrupt */
     MODULE_SRC.GTM.GTM[0].TOM[0][0].B.SRE = 0x00u;
      
   }  


#endif /* SWDG_EXT_CIC_WDG_ONLY */

#define IFX_APPL_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"
