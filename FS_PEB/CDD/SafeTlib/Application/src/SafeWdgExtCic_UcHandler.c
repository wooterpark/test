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
**   $FILENAME   : SafeWdgExtCic_UcHandler.c $                                **
**                                                                            **
**   $CC VERSION : \main\7 $                                                  **
**                                                                            **
**   $DATE       : 2016-02-25 $                                               **
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
**  DESCRIPTION  : This file contains the usecase for External CIC Watchdog   **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: Yes                                      **
**                                                                            **
*******************************************************************************/


/******************************************************************************
**                      Includes                                              *
******************************************************************************/
#include "Mcal.h"
#include "SafeWdgM.h"
#include "SafeWdgExtCic_UcHandler.h"
#include "TstM.h"
#include "AppCbk.h"

#ifdef SWDG_EXT_CIC_WDG_ONLY
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/* Size of the array */
#define WDGCICUC_TRIPCICARRAYSIZE    (0x4U)
/* Max 4 UR can be send at a time. UR size is 4 */
#define WDGCICUC_UR1ARRAYSIZE        (4u)
/* Max 4 UR can be send at a time. UR size is 4 */
#define WDGCICUC_UR2ARRAYSIZE        (2u)

/* SecureSPI Array Size */
#define WDGCICUC_URSSPIARRSIZ1        (2u)
#define WDGCICUC_URSSPIARRSIZ2        (2u)
#define WDGCICUC_URSSPIARRSIZ3        (4u)
#define WDGCICUC_URSSPIARRSIZ4        (4u)
#define WDGCICUC_URSSPIARRSIZ5        (2u)
/* Dummy byte */
#define WDGCICUC_WRDUMMYBYTE         (0xDDU)
/* Cmd to move cic from active to trip state */
#define WDGCICUC_WRDATAENTTRIP       (0x85u)
/* used in TempSeqTest */
#define WDGCICUC_DECSEQCNTERR        (0x02u)
/* Dummy byte */
#define WDGCICUC_WRDUMMYBYTE         (0xDDU)
/* Read CIC state*/
#define WDGCICUC_RDSTATE             (0x0007u)
/* Read CIC Error Count */
#define WDGCICUC_RDERRCNT            (0x0008u)
/* Read CIC SUM0 register */
#define WDGCICUC_RDSUM0              (0x0010u)
/* Read CIC SUM1 register */
#define WDGCICUC_RDSUM1              (0x0011u)
/* Read CIC version */
#define WDGCICUC_RDSVER              (0x002Cu)
/* CIC Write Command Mode */
#define WDGCICUC_WRCMDMODE           (0x0093u)
 
/* check trip counters, if != 0) */
/* min. expected Trip1 counter */
#define WDGCICUC_TRIP1CNTEXP         (2u)        
/* min. expected Trip2 counter */
#define WDGCICUC_TRIP2CNTEXP         (2u)        
/* min. expected Trip3 counter */
#define WDGCICUC_TRIP3CNTEXP         (2u)            
/* max cycles for state check */
#define WDGCICUC_STATECYCLEMAX       (60u)       


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static void SafeWdgExtCic_UcHandler_lMoveCICTripstate(void);

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
#define IFX_APPL_START_SEC_VAR_8BIT_ASIL_B
#include "Ifx_MemMap.h"

static uint8     SafeWdgCicUc_TSeqtest_Oldcount = 0;
static uint8     SafeWdgCicUc_TSeqtest_Newcount = 0;

static uint16    SafeWdgCicUc_Trip1Cnt;
static uint16    SafeWdgCicUc_Trip2Cnt;
static uint16    SafeWdgCicUc_Trip3Cnt;

#define IFX_APPL_STOP_SEC_VAR_8BIT_ASIL_B
#include "Ifx_MemMap.h"


#define IFX_APPL_START_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"

static boolean  SafeWdgCicUc_StateCheckDone  = FALSE;
static uint16   SafeWdgCicUc_CycleCnt        = 0u;
static uint32   SafeWdgCicUc_Seq_Test_Count  = 0u;

#define IFX_APPL_STOP_SEC_VAR_32BIT_ASIL_B
#include "Ifx_MemMap.h"


#define IFX_APPL_START_SEC_VAR_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"


/* store user requests */
SafeWdgIf_CmdType SafeWdgCicUc_TripCic[WDGCICUC_TRIPCICARRAYSIZE]=
{
        /* Send Cmd to move cic from Active to Trip state*/
        {WDGCICUC_WRCMDMODE, WDGCICUC_WRDATAENTTRIP}
};


SafeWdgIf_CmdType SafeWdgCicUc_UR1Cic[WDGCICUC_UR1ARRAYSIZE]=
{
    /* Check CIC state*/
    {WDGCICUC_RDSTATE,WDGCICUC_WRDUMMYBYTE},
    /* Read CIC SUM0 regsiter  */
    {WDGCICUC_RDSUM0, WDGCICUC_WRDUMMYBYTE},
    /* Read CIC SUM1 register  */
    {WDGCICUC_RDSUM1, WDGCICUC_WRDUMMYBYTE},
    /* Read CIC Error Count   */
    {WDGCICUC_RDERRCNT, WDGCICUC_WRDUMMYBYTE}

};

SafeWdgIf_CmdType SafeWdgCicUc_UR2Cic[WDGCICUC_UR2ARRAYSIZE]=
{
    /* Check CIC state*/
    {WDGCICUC_RDSVER,WDGCICUC_WRDUMMYBYTE},
    /* Read CIC SUM0 regsiter  */
    {WDGCICUC_RDSTATE, WDGCICUC_WRDUMMYBYTE}, 

};

SafeWdgIf_CmdType SafeWdgCicUc_UREntSecCmd1[WDGCICUC_URSSPIARRSIZ1]=
{    
    {0x07u,0x00u},
    {0x93u,0x94u},
};

SafeWdgIf_CmdType SafeWdgCicUc_UREntSecCmd2[WDGCICUC_URSSPIARRSIZ2]=
{    
    {0x02u,0xABu},
    {0xB6u, 0xA5u}
};

SafeWdgIf_CmdType SafeWdgCicUc_URSecSpiRead1[WDGCICUC_URSSPIARRSIZ3]=
{
    {0x00u,0x29u},
    {0x08u,0x00u},
    {0x01u,0x29u},
    {0x08u,0x00u}
};
SafeWdgIf_CmdType SafeWdgCicUc_URSecSpiRead2[WDGCICUC_URSSPIARRSIZ4]=
{
    {0xF0u,0xAFu},
    {0x08u,0x00u},
    {0xF1u, 0xAF},
    {0x08u, 0x00}
};
SafeWdgIf_CmdType SafeWdgCicUc_URSecSpiExit[WDGCICUC_URSSPIARRSIZ5]=
{
    {0x00u, 0x00u},
    {0x87,0x00}

};

#endif

#define IFX_APPL_STOP_SEC_VAR_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define IFX_APPL_START_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"

#ifdef SWDG_EXT_CIC_WDG_ONLY
/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : boolean                                                 **
**                          SafeWdgExtCic_UcHandler_VerifyCICStates(void)     **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : SWDG_JOB_FAILED:   Cic state verification not complete  **
**                    SWDG_JOB_Accepted: Cic State check specific job         **
**                                       in progress                          **
**                    SWDG_JOB_SUCCESS:  Cic state verification is complete   **
**                                       successfully                         ** 
**                                                                            **
** Description      : Test CIC Whether Cic moves through all the states       **
** -None              It returns                                              **
**                                                                            **
*******************************************************************************/
boolean SafeWdgExtCic_UcHandler_VerifyCICStates(void)
{
    boolean Finished = FALSE;
    
  SafeWdgIf_StateType CicState;
    
  CicState = SafeWdgM_GetState();
  
    switch (CicState.ExtWdgState)
    {
        case SAFEWDG_CIC_NR:
           
             break;
        case SAFEWDG_CIC_READY:
            /* add optional code for ready state check */
            break;

        case SAFEWDG_CIC_ACTIVE:
            /* Cmd cic to move to trip state from active state */
            SafeWdgExtCic_UcHandler_lMoveCICTripstate();
            /* add optional code for ready state check */
            break;

        case SAFEWDG_CIC_TRIPPING1:
            /* add optional code for ready state check */
            SafeWdgCicUc_Trip1Cnt++;
            break;
        case SAFEWDG_CIC_TRIPPING2:
            /* add optional code for ready state check */
            SafeWdgCicUc_Trip2Cnt++;
            break;
        case SAFEWDG_CIC_TRIPPING3:
            /* add optional code for ready state check */
            SafeWdgCicUc_Trip3Cnt++;
            break;

        case SAFEWDG_CIC_DISABLED:
            if (SafeWdgCicUc_StateCheckDone == FALSE)
            {
                /* Check, whether all expected Tripping states are reached */
                /* add optional code for ready state check */
                if (((WDGCICUC_TRIP1CNTEXP != 0x0) && (SafeWdgCicUc_Trip1Cnt < WDGCICUC_TRIP1CNTEXP))  ||
                    ((WDGCICUC_TRIP2CNTEXP != 0x0) && (SafeWdgCicUc_Trip2Cnt < WDGCICUC_TRIP2CNTEXP))  ||
                    ((WDGCICUC_TRIP3CNTEXP != 0x0) && (SafeWdgCicUc_Trip3Cnt < WDGCICUC_TRIP3CNTEXP)))       
                {
                    AppCbk_ErrorHandler(APLCBK_CIC_TRIP_FAIL);
                }
                else
                {                
                    /* Reinitialize cic again, mandatory */
                                        
                     SafeWdgM_DeInit();
                     SafeWdgCicUc_StateCheckDone = TRUE;
                     Finished = TRUE;                       
                    
                }               
            } 
            break;

         default:
            break;
    }

    /* optional check number of cycles for swtich off path check */
    if (SafeWdgCicUc_CycleCnt++ > WDGCICUC_STATECYCLEMAX)
    {
        AppCbk_ErrorHandler(APLCBK_CIC_CYCLE_FAIL);
    }

    return (Finished);
}


/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : void ExtCic_Handler_lMoveCICstate                       **
**                    (void)                                                  **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
**                                                                            **
** Description      : Initialise SafeWDG CD of type ConfigType.               **
** -None                                                                      **
**                                                                            **
*******************************************************************************/
static void SafeWdgExtCic_UcHandler_lMoveCICTripstate(void)
{
    /* send request to CIC */
    SafeWdgM_UserRequest(SafeWdgCicUc_TripCic, 1u ); 
  
} 



/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : void ExtCic_Handler_TempSeqTest (void)                  **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
**                                                                            **
** Description      : Initialise SafeWDG CD of type ConfigType.               **
** -None                                                                      **
**                                                                            **
*******************************************************************************/
void SafeWdgExtCic_UcHandler_TempSeqTest(void)
{



    if(SafeWdgCicUc_Seq_Test_Count == WDGH_CIC_SERVICE_COUNT)
    {

        /* Store the counter value before injecting error. Inject error during this cycle.
         * This will decrement pass counter value after it is serviced
         */
         SafeWdgM_GetErrCntr(&SafeWdgCicUc_TSeqtest_Oldcount);

         /* Invalidate generated signature, Send wrong signature */
         TstM_InvalidateData();


     } /* if(SafeWdgM_CIC_Seq_Test_Count == WDGH_CIC_SERVICE_COUNT) */

     if(SafeWdgCicUc_Seq_Test_Count == WDGH_CIC_SERVICE_COUNT + 1u)
     {
         /* Get new sequence count after error is injected in the last cycle  */
         SafeWdgM_GetErrCntr(&SafeWdgCicUc_TSeqtest_Newcount);

         /* Verify Pass sequence counter status in this (next) cycle */
         if(SafeWdgCicUc_TSeqtest_Newcount > 
                       (SafeWdgCicUc_TSeqtest_Oldcount - WDGCICUC_DECSEQCNTERR))
         {
           /* Temporal sequencer test failed */
           AppCbk_ErrorHandler(APLCBK_SWDGIF_ACT_FAIL);

         }

         /* Reset counter */
         SafeWdgCicUc_Seq_Test_Count = 0;

      } /* if(SafeWdgM_CIC_Seq_Test_Count == 101u) */

     /* Increment counter, used for temporal sequencer test */
     SafeWdgCicUc_Seq_Test_Count++;


} /* SafeWdgIf_ResultType ExtCic_Handler_TempSeqTest
                                          (uint8 Start_location, uint8 size) */

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : void ExtCic_UserRequest_Init1 (void)                    **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
**                                                                            **
** Description      : Execute user request 1 during INIT phase                **
** -None                                                                      **
**                                                                            **
*******************************************************************************/
void  SafeWdgExtCic_UcHandler_URInit1(void)
{
    /* clear read back data */
    SafeWdgCicUc_UR1Cic[0].UserData = 0x00u;
    SafeWdgCicUc_UR1Cic[1].UserData = 0x00u;
    SafeWdgCicUc_UR1Cic[2].UserData = 0x00u;
    SafeWdgCicUc_UR1Cic[3].UserData = 0x00u;

    /* Send User Request */
    SafeWdgM_UserRequest(SafeWdgCicUc_UR1Cic, WDGCICUC_UR1ARRAYSIZE); 
    
}

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : void ExtCic_UserRequest_Init2 (void)                    **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
**                                                                            **
** Description      : Execute user request 2 during INIT phase                **
** -None                                                                      **
**                                                                            **
*******************************************************************************/
void  SafeWdgExtCic_UcHandler_URInit2(void)
{
    /* clear read back data */
    SafeWdgCicUc_UR2Cic[0].UserData = 0x00u;
    SafeWdgCicUc_UR2Cic[1].UserData = 0x00u;

    /* Send User Request */
    SafeWdgM_UserRequest(SafeWdgCicUc_UR2Cic, WDGCICUC_UR2ARRAYSIZE);     
}


/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : void ExtCic_UserRequest_Run1 (void)                    **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
**                                                                            **
** Description      : Execute user request 1 during Run phase                 **
** -None                                                                      **
**                                                                            **
*******************************************************************************/
void  SafeWdgExtCic_UcHandler_URRun1(void)
{

    /* clear read back data */
    SafeWdgCicUc_UR1Cic[0].UserData = 0x00u;
    SafeWdgCicUc_UR1Cic[1].UserData = 0x00u;
    SafeWdgCicUc_UR1Cic[2].UserData = 0x00u;
    SafeWdgCicUc_UR1Cic[3].UserData = 0x00u;
    
    /* send user request */
    SafeWdgM_UserRequest(SafeWdgCicUc_UR1Cic, WDGCICUC_UR1ARRAYSIZE); 

}

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : void ExtCic_UserRequest_Run2 (void)                    **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
**                                                                            **
** Description      : Execute user request 2 during Run phase                 **
** -None                                                                      **
**                                                                            **
*******************************************************************************/
void  SafeWdgExtCic_UcHandler_URRun2(void)
{

    /* clear read back data */
    SafeWdgCicUc_UR2Cic[0].UserData = 0x00u;
    SafeWdgCicUc_UR2Cic[1].UserData = 0x00u;    
    
    /* send user request */
    SafeWdgM_UserRequest(SafeWdgCicUc_UR2Cic, WDGCICUC_UR2ARRAYSIZE); 

}

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : void SafeWdgExtCic_UcHandler_UREntSecCmd1 (void)        **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
**                                                                            **
** Description      :  Send first command to enter into Secure SPI mode       **
** -None                                                                      **
**                                                                            **
*******************************************************************************/
void SafeWdgExtCic_UcHandler_UREntSecCmd1(void)
{
  
  /* Send first command to enter into Secure SPI mode */
  SafeWdgM_UserRequest(SafeWdgCicUc_UREntSecCmd1, WDGCICUC_URSSPIARRSIZ1); 

}
/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : void SafeWdgExtCic_UcHandler_UREntSecCmd2(void)         **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
**                                                                            **
** Description      : Send next two command and dummy command to enter into   **
**                    secure spi mode                                         **
*******************************************************************************/
void SafeWdgExtCic_UcHandler_UREntSecCmd2(void)
{
  
  /* Send next two command and dummy command to enter into secure spi mode */
  SafeWdgM_UserRequest(SafeWdgCicUc_UREntSecCmd2, WDGCICUC_URSSPIARRSIZ2); 

}
/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : void SafeWdgExtCic_UcHandler_SendURInSecSpi(void)       **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
**                                                                            **
** Description      : Send User Request  to read data in secure spi mode      **
** -None                                                                      **
**                                                                            **
*******************************************************************************/
void SafeWdgExtCic_UcHandler_ReadInSecSpi1(void)
{
  
  /* Send User Request to read data in secure spi mode */
  SafeWdgM_UserRequest(SafeWdgCicUc_URSecSpiRead1, WDGCICUC_URSSPIARRSIZ3);  

}
/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : void SafeWdgExtCic_UcHandler_SendURInSecSpi(void)       **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
**                                                                            **
** Description      : Send User Request  to read data in secure spi mode      **
** -None                                                                      **
**                                                                            **
*******************************************************************************/
void SafeWdgExtCic_UcHandler_ReadInSecSpi2(void)
{
  
  /* Send User Request to read data in secure spi mode */
  SafeWdgM_UserRequest(SafeWdgCicUc_URSecSpiRead2, WDGCICUC_URSSPIARRSIZ4);  

}
/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : void SafeWdgExtCic_UcHandler_URSecSpiExit(void)         **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters (in)  : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
**                                                                            **
** Description      : Execute user request to exit from secure spi            **
** -None                                                                      **
**                                                                            **
*******************************************************************************/
void SafeWdgExtCic_UcHandler_URSecSpiExit(void)
{  
  /* Send User Request to exit from secure spi  */
  SafeWdgM_UserRequest(SafeWdgCicUc_URSecSpiExit, WDGCICUC_URSSPIARRSIZ5);  

}
#endif /* defined (SWDG_EXT_CIC_WDG_ONLY) */

#define IFX_APPL_STOP_SEC_CODE_ASIL_B
#include "Ifx_MemMap.h"



