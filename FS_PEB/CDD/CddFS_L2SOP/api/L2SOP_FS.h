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
#ifndef L2SOP_FS_H_
#define L2SOP_FS_H_

#include"Platform_Types.h";
/*******************************************************************************
**                          Macro Definition                         		  **
*******************************************************************************/
#define PWM3PH_TOM_M0DULE         0U
#define PWM3PH_TOM_CHANNEL_UH     9U
#define PWM3PH_TOM_CHANNEL_UL     10U
#define PWM3PH_TOM_CHANNEL_VH     11U
#define PWM3PH_TOM_CHANNEL_VL     12U
#define PWM3PH_TOM_CHANNEL_WH     13U
#define PWM3PH_TOM_CHANNEL_WL     14U

#define PWM3PH_TOM_CHANNEL_ON          10001U
#define PWM3PH_TOM_CHANNEL_OFF         1U


#define PWM3PH_Shut_Of_Path_Success                 1U
#define PWM3PH_Shut_Of_Path_Fail                    2U
#define PWM3PH_Shut_Of_Path_UpOffDownOn             3U
#define PWM3PH_Shut_Of_Path_UpOffDownOn_Check       4U
#define PWM3PH_Shut_Of_Path_UpOnDownOff             5U
#define PWM3PH_Shut_Of_Path_UpOnDownOff_Check       6U
#define PWM3PH_Shut_Of_Path_Start                   7U
#define PWM3PH_Shut_Of_Path_Switch                  8U
#define PWM3PH_Shut_Of_Path_Stop                    9U


/*******************************************************************************
**                          Typedef Definition                         		  **
*******************************************************************************/
typedef enum
{
	Shut_OF_PATH_START    = 1,
    UPOFFDOWNON           = 2,
	UPOFFDOWNON_CHECK     = 3,
	Shut_OF_PATH_SWITCH   = 4,
    UPONDOWNOFF           = 5,
	UPONDOWNOFF_CHECK     = 6,
	CHECK_FAIL            = 7,
	CHECK_SUCCESS         = 8,
	Shut_OF_PATH_STOP     = 9
}Shut_Of_Path_E;


/*******************************************************************************
**                     Global Variables Definition              		      **
*******************************************************************************/
extern uint16 VAR_Shut_Of_Path_State_u16;

/*******************************************************************************
**                        Global Function Prototypes              	    	  **
*******************************************************************************/

/*******************************************************************************
** Function Name	: FS_Shut_Of_Path_L2
** Parameter[in] 	: None
** Parameter[out] 	: None
** Return Value	  	: None
** Note	  			: None
** Description	  	: L2 Function safety get RSLVEXCN sample
*******************************************************************************/
extern void FS_Shut_Of_Path_L2(void);

#endif
