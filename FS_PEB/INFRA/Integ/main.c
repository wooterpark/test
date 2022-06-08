/*
 * Contains code for the "Hello World" example application
 *
 * Copyright ETAS GmbH 2016
 */
 
 /*includes*/
#include "Os.h"
#include "Std_Types.h"
#include "Rte.h"
#include "Rte_UserCfg.h"
#include "Port.h"
#include "IfxPort_reg.h"
#include "IfxStm_reg.h"
#include "IfxSrc_reg.h"
#include "EcuM.h"
#include "BswM.h"
#include "SchM_BswM.h"
#include "main.h"
#include "rba_BswSrv.h"
#include "rba_Reset.h"

/*Macro definitions*/

#define TIMER_MILLISECOND (OSSWTICKSPERSECOND/1000UL)

/* Global variables */
#define BSW_START_SEC_VAR_CLEARED_32
#include "Bsw_MemMap.h"
volatile uint32 Millisecond_count;
volatile uint32 STM_OsCounter_Core2_count;

#define BSW_STOP_SEC_VAR_CLEARED_32
#include "Bsw_MemMap.h"

/********************/
/* The main program */
/********************/
#define MAIN_START_SEC_CODE
#include "MemMap.h"
/*MISRA Dir-1.1, Rule 1.2, 10.4, 2.2, 8.5, 10.1 VIOLATION: This is a OS macro, This is a OS function*/
OS_MAIN()
{
	/*Invoking the ECUM Init for ECU Initialization, never return */
	if(rba_BswSrv_GetPhysCore()==0)
	{
		rba_Reset_Init();

	}
	EcuM_Init();
	while(1);
	return ;
}
#define MAIN_STOP_SEC_CODE
#include "MemMap.h"


  /*Periodic interrupt definition*/
#define STARTUP_START_SEC_CODE
#include "MemMap.h"

FUNC(void, OS_APPL_CODE) rba_OsShell_SystemTimerInit(void)
{
    TickType Now;

    /* Init Compare Match Control Register
    * Set the width of the relevant bits in registers STM0_CMP0 that is
    * taken for the compare operation and set the first bit location in
    * the 56-bit STM that is taken for the compare operation. */
    /* MSIZE0 = 31 -> CMP0[31:0] is used for compare */
    /* MR12 RULE 1.3, 13.2 VIOLATION: This false-positive situation is always detected for two rba_reg function macros because QAC could not evaluate the macro correctly due to redundant round braces. */
	STM0_CMCON.B.MSIZE0 = 31U;

    /* MSTART0 = 0 -> STM0[0] is the lowest bit number */
	STM0_CMCON.B.MSTART0 = 0U;
    /* Make sure old cmp register will not accidentally match */
    Now = (TickType) STM0_TIM0.U;
    STM0_CMP0.U = Now - 1u;

    /* Interrupt Control register */
    /* Reset potentially active compare match interrupts of CMP0 */
    STM0_ISCR.B.CMP0IRR=1;
    /* Clear potentially active service request immediately */
    SRC_STM_STM0_SR0.B.CLRR=1;

    /* The compare match interrupt output signal STMIR0 is activated on a
    * compare match event of compare register CMP0.
    * The signal STMIR0 is connected to the IR (Interrupt Router)
    * Service Request Control Register STM0SR0. */

    /* Select the interrupt output signal STMIR0 */
    STM0_ICR.B.CMP0OS=0;
    /* Enable the compare match interrupt with compare register CMP0 */
    STM0_ICR.B.CMP0EN=1;
    STM0_OCS.U = 0x12000000;

    /* Disable the service request during initialization. */
    SRC_STM_STM0_SR0.B.SRE=0;
}


/*Startup hook for enableing the periodic interrupt*/
FUNC(void, OS_CALLOUT_CODE) StartupHook(void)
{
	if(GetCoreID()==0)
	{
		rba_OsShell_SystemTimerInit();
	}
	else if(GetCoreID()==2)
	{

		/*Core2 Timer Interrupt STM1SR0*/

		/* Configure 32 bit compares on the lowest 32 bits of the STM */
		STM1_CMCON.B.MSIZE0 = 31U;
		STM1_CMCON.B.MSTART0 = 0U;

		/* Set compare register to period value */
		STM1_CMP0.U = STM1_TIM0.U + TIMER_MILLISECOND;

		/* Reset the interrupt pending flag */
		STM1_ISCR.B.CMP0IRR = 1;

		/* Enable compare interrupt */
		STM1_ICR.B.CMP0EN = 1;

		/* Enable suspend for system timer */
		STM1_OCS.U = 0x12000000;
	}
}

FUNC(void, OS_APPL_CODE) rba_OsShell_SystemTimer_Isr(void)
{

    /* Clear the just triggered interrupt of CMP0 */
    STM0_ISCR.B.CMP0IRR=1;

    /* Call RTA-OS Callback */
    /* The API call Os_AdvanceCounter_SystemTimer tells RTA-OS that
     * the match value has been reached. The Os_AdvanceCounter_SystemTimer
     * API call cause the next alarm and/or expiry point to be processed
     * and will set up the next match value by calling the
     * callback Os_Cbk_Set_SystemTimer.
     */

    /* MR12 RULE 17.7 VIOLATION: in some config-variants the macro returns a value which is not used here */
    Millisecond_count++;
    Os_AdvanceCounter_SystemTimer();
}

/*!
 ********************************************************************
 * \brief       Hardware counter set, RTA-OS callback of SystemTimer
 *
 * \param       Match:   the absolute value of the counter at which an
 *                       action should take place.
 *
 * \return      void
 *
 * This callback sets up the state for an interrupt to occur when the next action
 * is due. The callback is passed the absolute value of the counter at which an
 * action should take place. For Alarm-counters, this callback is used in two distinct
 * cases:
 * 1. Starting:  Setting the initial interrupt source when a schedule table
 *               or an alarm is started on the counter.
 * 2. Resetting: Shortening the time to the next counter expiry.
 *
 * The second case is needed because you can, for example, make a
 * SetRelAlarm(WakeUp, 100) call when the next interrupt is due in
 * more than 100 ticks.
 ********************************************************************
 */

FUNC(void, OS_APPL_CODE) Os_Cbk_Set_SystemTimer(TickType Match)
{
    TickType Now;

    /* lock Interrupts */
    DisableAllInterrupts();
    {
        /* Make sure old cmp register will not accidentally match */
        Now = (TickType) STM0_TIM0.U;
        STM0_CMP0.U = Now - 1u;

        /* Clear interrupt request of CMP0. This does not clear a potentially pending Interrupt (SRC.SRR),
           but we don't want to clear this Interrupt, because the SystemTimer might be used for
           more than one Scheduling Tables. */
        STM0_ISCR.B.CMP0IRR=1;

        /* Write the match value to the STM-Compare Register */
        STM0_CMP0.U = Match;

        /* Enable the service request */
        SRC_STM_STM0_SR0.B.SRE=1;

        /* trigger interrupt immediately, if match is in the past */
        Now = (TickType) STM0_TIM0.U;
        if ((Now-Match) < (Match-Now))
        {
            /* Clear interrupt request of CMP0 */
            STM0_ISCR.B.CMP0IRR=1;
            /* Clear service request immediately */
            SRC_STM_STM0_SR0.B.CLRR=1;
            /* Set service request immediately */
            SRC_STM_STM0_SR0.B.SETR=1;
        }

        /* Notification of Match value for rba_FrOsSync */

    }
    /* release Interrupts */
    EnableAllInterrupts();
}


/*!
 ********************************************************************
 * \brief       system timer counter now value, RTA-OS callback
 *
 * \param       void
 *
 * \return      the current value of the system timer counter
 *
 * This callback needs to return the current value of the system timer counter.
 * This is used for the GetCounterValue() API call of the OS
 ********************************************************************
 */

FUNC(TickType, OS_APPL_CODE) Os_Cbk_Now_SystemTimer(void)
{
    return( (TickType) STM0_TIM0.U );
}


/*!
 ********************************************************************
 * \brief       system timer counter state, RTA-OS callback
 *
 * \param       State:   state of the counter
 *
 * \return      void
 *
 * This callback returns whether the next action on the counter is pending
 * or not and, if the action is not pending, the number of ticks remaining
 * until the match value is reached.
 ********************************************************************
 */

FUNC(void, OS_APPL_CODE) Os_Cbk_State_SystemTimer(Os_CounterStatusRefType State)
{
    State->Delay = (TickType) (STM0_CMP0.U - STM0_TIM0.U);

    /* Check if Counter is enabled */
    if(SRC_STM_STM0_SR0.B.SRE)
    {
        State->Running = TRUE;
    }
    else
    {
        State->Running = FALSE;
    }

    /* Check if Counter is pending */
    if(SRC_STM_STM0_SR0.B.SRR)
    {
        State->Pending = TRUE;
    }
    else
    {
        State->Pending = FALSE;
    }
}


/*!
 ********************************************************************
 * \brief       cancel system timer counter, RTA-OS callback
 *
 * \param       void
 *
 * \return      void
 *
 * This callback must clear any pending interrupt for your counter
 * and ensure that the interrupt cannot become pending until a
 * Os_Cbk_Set_SystemTimer() call is made.
 ********************************************************************
 */

FUNC(void, OS_APPL_CODE) Os_Cbk_Cancel_SystemTimer(void)
{

    DisableAllInterrupts();
    {
        /* Disable service request node */
        SRC_STM_STM0_SR0.B.SRE=0;
        //(void) SRC.STM[0].SR0;                  //read forces that ClrBit SRE has stored in register
        (void) SRC_STM_STM0_SR0.U;
        /* Clear interrupt request of CMP0 */
        STM0_ISCR.B.CMP0IRR=1;
        /* Clear service request immediately */
        SRC_STM_STM0_SR0.B.CLRR=1;
    }
    /* release Interrupts */
    EnableAllInterrupts();
}

#define STARTUP_STOP_SEC_CODE
#include "MemMap.h"


void STM1_Isr_Core2_Proc(void)
{
	StatusType status;
	STM_OsCounter_Core2_count++;
	STM1_CMP0.U = STM1_CMP0.U + TIMER_MILLISECOND;
	STM1_ISCR.B.CMP0IRR = 1;
	if (Millisecond_count == 1000U)
	{
		Millisecond_count = 0U;
	}
	{
		STM1_CMP0.U = STM1_TIM0.U + TIMER_MILLISECOND;
	/* Increment from timer so that breakpoints won't cause an issue in samples */
		SRC_STM1SR0.B.CLRR = 1;
	}
}

/******************************************************************/
/*ECU startp two for initilize the BSW Modules*/
void Bsw_StartUp_Core0_Proc(void)
{
	uint8 idx = 0;

	EcuM_StartupTwo();

	SchM_IModeInit();

	for (idx=0;idx<20;idx++)
		BswM_MainFunction();

	StartScheduleTableRel( Rte_ScheduleTable, (TickType)1u ) ;

}
void Bsw_StartUp_Core1_Proc(void)
{

}

void Bsw_StartUp_Core2_Proc(void)
{

}



/* Default Interrupt handler for unknown IR source */
#define CAT1_ISR_START_SEC_CODE
#include "MemMap.h"
CAT1_ISR(DefaultInterruptHandler)
{
	for (;;)
	{
	/* Loop forever */
	}
}
#define CAT1_ISR_STOP_SEC_CODE
#include "MemMap.h"
/**************************************************************************************************/
