
/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2021 by JEE.		All rights reserved.
** This software is copyright protected and proprietary to JEE.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with JEE.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \xx\xx$
* $Class_____: C$
* $Name______: Rdc_FS.h$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: XWL$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:
				Function Safety Level2 shut off path test.
**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:   initial version

*******************************************************************************/
#include "L2SOP_FS.h"
#include "Dio.h"
#include "IgbtDrv.h"

Shut_Of_Path_E  Shut_Of_Path_State= Shut_OF_PATH_START;
uint16 VAR_Shut_Of_Path_State_u16;
/*******************************************************************************
** Function Name	: FS_ShutOfpath_Start
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: FS_ShutOfpath_Start
*******************************************************************************/
void FS_ShutOfpath_Start(void)
{
	P02_OUT.B.P1=0x0u;
	P02_OUT.B.P2=0x0u;
	P02_OUT.B.P3=0x0u;
	P02_OUT.B.P4=0x0u;
	P02_OUT.B.P5=0x0u;
	P02_OUT.B.P6=0x0u;

	P02_IOCR0.B.PC1=0x10u;
	P02_IOCR0.B.PC2=0x10u;
	P02_IOCR0.B.PC3=0x10u;
	P02_IOCR4.B.PC4=0x10u;
	P02_IOCR4.B.PC5=0x10u;
	P02_IOCR4.B.PC6=0x10u;

	Shut_Of_Path_State = UPOFFDOWNON;
}

/*******************************************************************************
** Function Name	: FS_ShutOfpath_UPOFF_DOWNON
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: FS_ShutOfpath_UPOFF_DOWNON
*******************************************************************************/
void FS_ShutOfpath_UPOFF_DOWNON(void)
{
	P02_OUT.B.P1=0x0u;
	P02_OUT.B.P2=0x1u;
	P02_OUT.B.P3=0x0u;
	P02_OUT.B.P4=0x1u;
	P02_OUT.B.P5=0x0u;
	P02_OUT.B.P6=0x1u;

	Shut_Of_Path_State = UPOFFDOWNON_CHECK;
}

/*******************************************************************************
** Function Name	: FS_ShutOfpath_UPOFF_DOWNON_CHECK
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: FS_ShutOfpath_UPOFF_DOWNON_CHECK
*******************************************************************************/

void FS_ShutOfpath_UPOFF_DOWNON_CHECK(void)
{
	uint8 UH_State;
	uint8 UL_State;
	uint8 VH_State;
	uint8 VL_State;
	uint8 WH_State;
	uint8 WL_State;

	UH_State = P02_IN.B.P1;
	UL_State = P02_IN.B.P2;
	VH_State = P02_IN.B.P3;
	VL_State = P02_IN.B.P4;
	WH_State = P02_IN.B.P5;
	WL_State = P02_IN.B.P6;

//	UH_State = P10_IN.B.P3;
//	UL_State = P10_IN.B.P8;
//	VH_State = P13_IN.B.P1;
//	VL_State = P14_IN.B.P10;
//	WH_State = P15_IN.B.P7;
//	WL_State = P22_IN.B.P5;

	if((UH_State==0)&&(UL_State==1)&&(VH_State==0)&&(VL_State==1)&&(WH_State==0&&(WL_State==1)))
	{
		Shut_Of_Path_State = Shut_OF_PATH_SWITCH;
	}
	else
	{
		Shut_Of_Path_State = CHECK_FAIL;
	}
}

/*******************************************************************************
** Function Name	: FS_ShutOfpath_UPOFF_DOWNON_Switch
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: FS_ShutOfpath_UPOFF_DOWNON_Swith to FS_ShutOfpath_UPON_DOWNOFF
*******************************************************************************/
void FS_ShutOfpath_UPOFF_DOWNON_Switch(void)
{
	P02_OUT.B.P1=0x0u;
	P02_OUT.B.P2=0x0u;
	P02_OUT.B.P3=0x0u;
	P02_OUT.B.P4=0x0u;
	P02_OUT.B.P5=0x0u;   /*forbid High Voltage is On add the dead time */
	P02_OUT.B.P6=0x0u;

	Shut_Of_Path_State = UPONDOWNOFF;
}
/*******************************************************************************
** Function Name	: FS_ShutOfpath_UPON_DOWNOFF_CHECK
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: FS_ShutOfpath_UPON_DOWNOFF_CHECK
*******************************************************************************/
void FS_ShutOfpath_UPON_DOWNOFF_CHECK(void)
{
	uint8 UH_State;
	uint8 UL_State;
	uint8 VH_State;
	uint8 VL_State;
	uint8 WH_State;
	uint8 WL_State;

	UH_State = P02_IN.B.P1;
	UL_State = P02_IN.B.P2;
	VH_State = P02_IN.B.P3;
	VL_State = P02_IN.B.P4;
	WH_State = P02_IN.B.P5;
	WL_State = P02_IN.B.P6;

//	UH_State = P10_IN.B.P3;
//	UL_State = P10_IN.B.P8;
//	VH_State = P13_IN.B.P1;
//	VL_State = P14_IN.B.P10;
//	WH_State = P15_IN.B.P7;
//	WL_State = P22_IN.B.P5;

	if((UH_State==1)&&(UL_State==0)&&(VH_State==1)&&(VL_State==0)&&(WH_State==1&&(WL_State==0)))
	{
		Shut_Of_Path_State = Shut_OF_PATH_STOP ;
	}
	else
	{
		Shut_Of_Path_State = CHECK_FAIL;
	}
}

/*******************************************************************************
** Function Name	: FS_ShutOfpath_STOP
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: FS_ShutOfpath_STOP
*******************************************************************************/
void FS_ShutOfpath_STOP(void)
{
	P02_OUT.B.P1=0x0u;
	P02_OUT.B.P2=0x0u;
	P02_OUT.B.P3=0x0u;
	P02_OUT.B.P4=0x0u;
	P02_OUT.B.P5=0x0u;
	P02_OUT.B.P6=0x0u;

	P02_IOCR0.B.PC1=0x11u;
	P02_IOCR0.B.PC2=0x11u;
	P02_IOCR0.B.PC3=0x11u;
	P02_IOCR4.B.PC4=0x11u;
	P02_IOCR4.B.PC5=0x11u;
	P02_IOCR4.B.PC6=0x11u;

	Shut_Of_Path_State = CHECK_SUCCESS;
}
/*******************************************************************************
** Function Name	: FS_ShutOfpath_UPOFF_DOWNON
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: FS_ShutOfpath_UPOFF_DOWNON
*******************************************************************************/
void FS_ShutOfpath_UPON_DOWNOFF(void)
{
	P02_OUT.B.P1=0x1u;
	P02_OUT.B.P2=0x0u;
	P02_OUT.B.P3=0x1u;
	P02_OUT.B.P4=0x0u;
	P02_OUT.B.P5=0x1u;
	P02_OUT.B.P6=0x0u;

	Shut_Of_Path_State = UPONDOWNOFF_CHECK;
}

/*******************************************************************************
** Function Name	: FS_Shut_Of_Path_L2
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: L2 Function safety get RSLVEXCN sample
*******************************************************************************/
void FS_Shut_Of_Path_L2(void)
{
	if(VAR_Igbt_Normal_State_u16==1U)
	{
	switch(Shut_Of_Path_State)
		{
	     case Shut_OF_PATH_START :
	     {
	    	 FS_ShutOfpath_Start();
	    	 VAR_Shut_Of_Path_State_u16 =  PWM3PH_Shut_Of_Path_Start;
	     }
	     break;
	     case UPOFFDOWNON :
		 {
			 FS_ShutOfpath_UPOFF_DOWNON();
			 VAR_Shut_Of_Path_State_u16 =  PWM3PH_Shut_Of_Path_UpOffDownOn;
		 }
		 break;
	     case UPOFFDOWNON_CHECK :
	     {
	    	 FS_ShutOfpath_UPOFF_DOWNON_CHECK();
	    	 VAR_Shut_Of_Path_State_u16 =  PWM3PH_Shut_Of_Path_UpOffDownOn_Check;
	     }
	     break;
	     case Shut_OF_PATH_SWITCH :
	     {
	    	 FS_ShutOfpath_UPOFF_DOWNON_Switch();
	    	 VAR_Shut_Of_Path_State_u16 =  PWM3PH_Shut_Of_Path_Switch;
	     }
	     break;
	     case UPONDOWNOFF :
	     {
	    	 FS_ShutOfpath_UPON_DOWNOFF();
	    	 VAR_Shut_Of_Path_State_u16 =  PWM3PH_Shut_Of_Path_UpOnDownOff;
	     }
	     break;
	     case UPONDOWNOFF_CHECK :
	     {
	    	 FS_ShutOfpath_UPON_DOWNOFF_CHECK();
	    	 VAR_Shut_Of_Path_State_u16 =  PWM3PH_Shut_Of_Path_UpOnDownOff_Check;
	     }
	     break;
	     case Shut_OF_PATH_STOP :
	     {
	    	 FS_ShutOfpath_STOP();
	    	 VAR_Shut_Of_Path_State_u16 =  PWM3PH_Shut_Of_Path_Stop;
	     }
	     break;
	     case CHECK_FAIL :
	     {
	    	 VAR_Shut_Of_Path_State_u16 =  PWM3PH_Shut_Of_Path_Fail;
	     }
	     break;
	     case CHECK_SUCCESS :
	     {
	    	 VAR_Shut_Of_Path_State_u16 =  PWM3PH_Shut_Of_Path_Success;
	     }
	     break;
		}
	}


}
