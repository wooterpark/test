/* *****************************************************************************
 * BEGIN: Banner
 *-----------------------------------------------------------------------------
 *                                 ETAS GmbH
 *                      D-70469 Stuttgart, Borsigstr. 14
 *-----------------------------------------------------------------------------
 *    Administrative Information (automatically filled in by ISOLAR)         
 *-----------------------------------------------------------------------------
 * Name: Code-Frame generation feature
 * Description:
 * Version: 9.3
 *-----------------------------------------------------------------------------
 * END: Banner
 ******************************************************************************

 * Project : FOTON_VCU_May_31_BSW31
 * Component: /WdgM_SWC/WdgM_SWC
 * Runnable : All Runnables in SwComponent
 *****************************************************************************
 * Tool Version: ISOLAR-A V 9.0
 * Author: NHH1HC
 * Date : Wed Jun 13 17:53:14 2018
 ****************************************************************************/

#include "WdgM_SWC.h"


/*PROTECTED REGION ID(FileHeaderUserDefinedIncludes :RE_WdgM_SWC_10ms_func) ENABLED START */
/* Start of user defined includes  - Do not remove this comment */
/* End of user defined includes - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedConstants :RE_WdgM_SWC_10ms_func) ENABLED START */
/* Start of user defined constant definitions - Do not remove this comment */
/* End of user defined constant definitions - Do not remove this comment */
/*PROTECTED REGION END */
volatile uint8 WdgM_Test_testcase10ms=0U;//2
volatile uint8 WdgM_Test_testcase1ms=0;
volatile uint8 WdgM_Test_testcaseCore1=0;//3
uint8 WdgM_Test_result=0;
uint8 WdgM_Test_global=0;
uint8 WdgM_Test_cnt_wdg = 0;
/*PROTECTED REGION ID(FileHeaderUserDefinedVariables :RE_WdgM_SWC_10ms_func) ENABLED START */
/* Start of user variable defintions - Do not remove this comment  */
/* End of user variable defintions - Do not remove this comment  */
/*PROTECTED REGION END */
#define WdgM_SWC_START_SEC_CODE                   
#include "WdgM_SWC_MemMap.h"

FUNC (void, WdgM_SWC_CODE) RE_WdgM_SWC_10ms_func // return value & FctID 
(
		void
)
{

    WdgM_CheckpointIdType CheckpointID1;
    Std_ReturnType syncCall1;

    /* Local Data Declaration */

    /*PROTECTED REGION ID(UserVariables :RE_WdgM_SWC_10ms_func) ENABLED START */
    /* Start of user variable defintions - Do not remove this comment  */
    /* End of user variable defintions - Do not remove this comment  */
    /*PROTECTED REGION END */
    Std_ReturnType retValue = RTE_E_OK;

	WdgM_Test_cnt_wdg++;
	switch(WdgM_Test_testcase10ms)
	{
	    case 0:
	        WdgM_CheckpointReached(WdgMConf_WdgMSupervisedEntity_WdgMSE_Bsw , WdgMConf_WdgMCheckpoint_WdgMCheckpoint_10ms);
	        break;
        case 1:
            WdgM_CheckpointReached(WdgMConf_WdgMSupervisedEntity_WdgMSE_Bsw , WdgMConf_WdgMCheckpoint_WdgMCheckpoint_10ms);
            WdgM_CheckpointReached(WdgMConf_WdgMSupervisedEntity_WdgMSE_Bsw , WdgMConf_WdgMCheckpoint_WdgMCheckpoint_10ms);
            break;
        case 2:
            WdgM_SetMode(WdgMConf_WdgMMode_WdgMMode_Run,99);
            WdgM_Test_testcase10ms=0;
            break;
        case 3:
            WdgM_SetMode(WdgMConf_WdgMMode_WdgMMode_Sleep,99);
            WdgM_Test_testcase10ms=0;
            break;
        default:
            WdgM_Test_testcase10ms=0;
            break;
	}
}

FUNC (void, WdgM_SWC_CODE) RE_WdgM_SWC_1ms_Core0_func
(
		void
)
{
    static uint8 counter=0;
    switch(WdgM_Test_testcase1ms)
    {
        case 0:
            WdgM_CheckpointReached(WdgMConf_WdgMSupervisedEntity_WdgMSE_Bsw , WdgMConf_WdgMCheckpoint_WdgMCheckpoint_1ms);
            break;
        case 1:
            WdgM_Test_testcase1ms=2;
            counter=2;
            break;
        case 2:
            counter--;
            if(counter<1)
            {
                WdgM_Test_testcase1ms=0;
            }
            break;
        case 3:
            WdgM_CheckpointReached(WdgMConf_WdgMSupervisedEntity_WdgMSE_Bsw , WdgMConf_WdgMCheckpoint_WdgMCheckpoint_1ms);
            WdgM_CheckpointReached(WdgMConf_WdgMSupervisedEntity_WdgMSE_Bsw , WdgMConf_WdgMCheckpoint_WdgMCheckpoint_1ms);
            break;
        default:
            break;
    }
}


volatile Std_ReturnType WdgM_Test_Logical_Return;
FUNC (void, WdgM_SWC_CODE) RE_WdgM_SWC_10ms_Core1_func
(
        void
)
{
    static uint8 index=0;
    if(WdgM_Test_testcaseCore1==1)
    {
        switch (index)
        {
            case 1:
                WdgM_Test_Logical_Return=WdgM_CheckpointReached(WdgMConf_WdgMSupervisedEntity_WdgMSE_Core1 , WdgMConf_WdgMCheckpoint_WdgMCP_Logical_Cp0);
                index=0;
                break;
            case 2:
                WdgM_Test_Logical_Return=WdgM_CheckpointReached(WdgMConf_WdgMSupervisedEntity_WdgMSE_Core1 , WdgMConf_WdgMCheckpoint_WdgMCP_Logical_Cp1);
                index=0;
                break;
            case 3:
                WdgM_Test_Logical_Return=WdgM_CheckpointReached(WdgMConf_WdgMSupervisedEntity_WdgMSE_Core1 , WdgMConf_WdgMCheckpoint_WdgMCP_Logical_Cp2);
                index=0;
                break;
            case 4:
                WdgM_Test_Logical_Return=WdgM_CheckpointReached(WdgMConf_WdgMSupervisedEntity_WdgMSE_Core1 , WdgMConf_WdgMCheckpoint_WdgMCP_Logical_Cp3);
                index=0;
                break;
            default:
                index=0;
                break;
        }
    }
    else if(WdgM_Test_testcaseCore1==2)
    {
        switch (index )
        {
        case 1:
            WdgM_Test_Logical_Return=WdgM_CheckpointReached(WdgMConf_WdgMSupervisedEntity_WdgMSE_Core1 , WdgMConf_WdgMCheckpoint_WdgMCP_Logical_Cp3);
            index=0;
            break;
        case 2:
            WdgM_Test_Logical_Return=WdgM_CheckpointReached(WdgMConf_WdgMSupervisedEntity_WdgMSE_Core1 , WdgMConf_WdgMCheckpoint_WdgMCP_Logical_Cp2);
            index=0;
            break;
        case 3:
            WdgM_Test_Logical_Return=WdgM_CheckpointReached(WdgMConf_WdgMSupervisedEntity_WdgMSE_Core1 , WdgMConf_WdgMCheckpoint_WdgMCP_Logical_Cp0);
            index=0;
            break;
        case 4:
            WdgM_Test_Logical_Return=WdgM_CheckpointReached(WdgMConf_WdgMSupervisedEntity_WdgMSE_Core1 , WdgMConf_WdgMCheckpoint_WdgMCP_Logical_Cp1);
               index=0;
               break;
        default:
            index=0;
            break;
        }
    }
}

FUNC (void, WdgM_SWC_CODE) RE_WdgM_SWC_10ms_Core0_func // return value & FctID
(
        void
)
{
	static uint8 index=0;
	if(WdgM_Test_testcaseCore1==3)
	{
		switch (index )
		{
		   case 0:
			   WdgM_Test_Logical_Return=WdgM_CheckpointReached(WdgMConf_WdgMSupervisedEntity_WdgMSE_Core1 , WdgMConf_WdgMCheckpoint_WdgMCP_Logical_Cp0);
			   index++;
			   break;
		   case 1:
			   WdgM_Test_Logical_Return=WdgM_CheckpointReached(WdgMConf_WdgMSupervisedEntity_WdgMSE_Core1 , WdgMConf_WdgMCheckpoint_WdgMCP_Logical_Cp1);
			   index++;
			   break;
		   case 2:
			   WdgM_Test_Logical_Return=WdgM_CheckpointReached(WdgMConf_WdgMSupervisedEntity_WdgMSE_Core1 , WdgMConf_WdgMCheckpoint_WdgMCP_Logical_Cp2);
			   index++;
			   break;
		   case 3:
			   WdgM_Test_Logical_Return=WdgM_CheckpointReached(WdgMConf_WdgMSupervisedEntity_WdgMSE_Core1 , WdgMConf_WdgMCheckpoint_WdgMCP_Logical_Cp3);
			   index=0;
			   break;
		   default:
			   break;
		}
	}
	else if(WdgM_Test_testcaseCore1==4)
	{
		switch (index )
		{
		   case 0:
		       WdgM_Test_Logical_Return= WdgM_CheckpointReached(WdgMConf_WdgMSupervisedEntity_WdgMSE_Core1 , WdgMConf_WdgMCheckpoint_WdgMCP_Logical_Cp3);
		       index++;
		       break;
		   case 1:
		       WdgM_Test_Logical_Return=WdgM_CheckpointReached(WdgMConf_WdgMSupervisedEntity_WdgMSE_Core1 , WdgMConf_WdgMCheckpoint_WdgMCP_Logical_Cp2);
		       index++;
		       break;
		   case 2:
		       WdgM_Test_Logical_Return= WdgM_CheckpointReached(WdgMConf_WdgMSupervisedEntity_WdgMSE_Core1 , WdgMConf_WdgMCheckpoint_WdgMCP_Logical_Cp0);
		       index++;
		       break;
		   case 3:
		       WdgM_Test_Logical_Return= WdgM_CheckpointReached(WdgMConf_WdgMSupervisedEntity_WdgMSE_Core1 , WdgMConf_WdgMCheckpoint_WdgMCP_Logical_Cp1);
		       index=0;
		       break;
		   default:
		       break;
		}
	}
}

#define WdgM_SWC_STOP_SEC_CODE                       
#include "WdgM_SWC_MemMap.h"
