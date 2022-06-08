/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2019 by Jee.		All rights reserved.
** This software is copyright protected and proprietary to Jee.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with Jee.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \Prv\IgbtDrv$
* $Class_____: C$
* $Name______: IgbtDrv.c$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: LQ$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:
** 1EDI2002AS Driver
*******************************************************************************
* $History__:$
* V0.0.0      2019.10.03 		LQ
*  N: new created
*******************************************************************************/

#ifndef IGBTDRV_TYPES_H_
#define IGBTDRV_TYPES_H_

/*******************************************************************************
**                      Other Header File Inclusion                           **
*******************************************************************************/
#include "Std_Types.h"

typedef struct IgbtDrv_CategoryA
{
	unsigned int Desaturation:1;			/*integrated desaturation*/
	unsigned int Overcurrent:1;				/*integrated Over Current*/
	unsigned int ExternalEnable:1;			/*the signal at pin EN/FEN */
	unsigned int OutputStageTristate:1;		/*Output Stage Monitoring*/
	unsigned int Reserved5:1;				/* 	*/
	unsigned int Reserved6:1;				/* 	*/
	unsigned int Reserved7:1;				/* 	*/
	unsigned int Reserved8:1;				/* 	*/
	unsigned int Reserved9:1;				/* 	*/
	unsigned int Reserved10:1;				/* 	*/
	unsigned int Reserved11:1;				/* 	*/
	unsigned int Reserved12:1;				/* 	*/
	unsigned int Reserved13:1;				/* 	*/
	unsigned int Reserved14:1;				/* 	*/
	unsigned int Reserved15:1;				/* 	*/
	unsigned int Reserved16:1;				/* 	*/
}IgbtDrv_CategoryAType;

typedef struct IgbtDrv_CategoryB
{
	unsigned int UVLO1:1;					/*Vcc1 < V_UVLO1L(4.4V)  	*/
	unsigned int UVLO2:1;					/*VCC2 < V_UVLO2L(11.7V) 	*/
	unsigned int OVLO2:1;					/*VCC2 > V_OVLO2H(19.14V)   */
	unsigned int UVLO3:1;					/*VEE2 < V_UVLO3L(-11.02V)  */
	unsigned int OVLO3:1;					/*VEE2 > V_OVLO3H(-3.99V)   */
	unsigned int PrimaryComError:1;			/*Communication Error Primary Flag	 */
	unsigned int SecondaryComError:1;		/*Communication Error Secondary Flag */
	unsigned int OscillatorErr:1;			/*Oscillator Open/short detection on pin IREF1/IREF2	*/
	unsigned int Reserved9:1;				/* 	*/
	unsigned int Reserved10:1;				/* 	*/
	unsigned int Reserved11:1;				/* 	*/
	unsigned int Reserved12:1;				/* 	*/
	unsigned int Reserved13:1;				/* 	*/
	unsigned int Reserved14:1;				/* 	*/
	unsigned int Reserved15:1;				/* 	*/
	unsigned int Reserved16:1;				/* 	*/
}IgbtDrv_CategoryBType;

typedef struct IgbtDrv_CategoryC
{
	unsigned int UVLO1:1;					/*Vcc1 < V_UVLO1L(4.4V)  	*/
	unsigned int UVLO2:1;					/*VCC2 < V_UVLO2L(11.7V) 	*/
	unsigned int OVLO2:1;					/*VCC2 > V_OVLO2H(19.14V)   */
	unsigned int UVLO3:1;					/*VEE2 < V_UVLO3L(-11.02V)  */
	unsigned int OVLO3:1;					/*VEE2 > V_OVLO3H(-3.99V)   */
	unsigned int PrimaryComError:1;			/*Communication Error Primary Flag	 */
	unsigned int SecondaryComError:1;		/*Communication Error Secondary Flag */
	unsigned int OscillatorErr:1;			/*Oscillator Open/short detection on pin IREF1/IREF2	*/
	unsigned int Reserved9:1;				/* 	*/
	unsigned int Reserved10:1;				/* 	*/
	unsigned int Reserved11:1;				/* 	*/
	unsigned int Reserved12:1;				/* 	*/
	unsigned int Reserved13:1;				/* 	*/
	unsigned int Reserved14:1;				/* 	*/
	unsigned int Reserved15:1;				/* 	*/
	unsigned int Reserved16:1;				/* 	*/
}IgbtDrv_CategoryCType;

typedef struct IgbtDrv_CategoryD
{
	unsigned int UVLO1:1;					/*Vcc1 < V_UVLO1L(4.4V)  	*/
	unsigned int UVLO2:1;					/*VCC2 < V_UVLO2L(11.7V) 	*/
	unsigned int OVLO2:1;					/*VCC2 > V_OVLO2H(19.14V)   */
	unsigned int UVLO3:1;					/*VEE2 < V_UVLO3L(-11.02V)  */
	unsigned int OVLO3:1;					/*VEE2 > V_OVLO3H(-3.99V)   */
	unsigned int PrimaryComError:1;			/*Communication Error Primary Flag	 */
	unsigned int SecondaryComError:1;		/*Communication Error Secondary Flag */
	unsigned int OscillatorErr:1;			/*Oscillator Open/short detection on pin IREF1/IREF2	*/
	unsigned int Reserved9:1;				/* 	*/
	unsigned int Reserved10:1;				/* 	*/
	unsigned int Reserved11:1;				/* 	*/
	unsigned int Reserved12:1;				/* 	*/
	unsigned int Reserved13:1;				/* 	*/
	unsigned int Reserved14:1;				/* 	*/
	unsigned int Reserved15:1;				/* 	*/
	unsigned int Reserved16:1;				/* 	*/
}IgbtDrv_CategoryDType;

typedef	struct								/**/
{
	uint8	RegBits;				    	/**/
	uint8   Reg_ShortName ;					/**/
	uint16  Reg_Value[6u];					/**/
}IgbtDrv_RegStatusType;

typedef	struct											/**/
{
	uint8	RegBits;				    				/**/
	uint8   Reg_ShortName ;								/**/
	uint16   Reg_Value;									/**/
	void	(*pfun_IgbtDrv)(uint16,uint16,boolean);	    /**/

}IgbtDrv_RegCfgType;

typedef enum
{
	 IgbtDrv_OpmNone_e=-1,
	 IgbtDrv_Opm0_e=0,
	 IgbtDrv_Opm1_e,
	 IgbtDrv_Opm2_e,
	 IgbtDrv_Opm3_e,
	 IgbtDrv_Opm4_e,
	 IgbtDrv_Opm5_e,
	 IgbtDrv_Opm6_e
} IgbtDrv_ChipOpm;

/* (Finite State Machine)Total state machine type */
typedef enum
{
	InitSeqMode  		= 0,
	InitCheckSeqMode  	= 1,
	RunTimeMode  		= 2,
	ErrorHandlingMode   = 3
} IgbtDrv_FSM_ModeType;

/* (Finite State Machine)Working mode substate machine type */
typedef enum
{
	ResetChipMode       				= 0,
	ReadPrimaryReadyStatusMode          = 1,
	CheckPrimaryStatus1Mode    			= 2,	/*Distinguish between IgbtDrv_FSM_RunTimeModeType*/
	ReadSecondaryReadyStatusMode 		= 3,
	ClearFlags1Mode 					= 4,	/*Distinguish between IgbtDrv_FSM_InitSeqCheckModeType*/
	CheckDeviceIDMode 					= 5,
	EnterConfigMode 					= 6,
	VerifyOPM2Mode 						= 7,
	ConfigDeviceMode 					= 8,
	SystemTestMode 						= 9
} IgbtDrv_FSM_InitSeqModeType;

/* (Finite State Machine)Working mode substate machine type */
typedef enum
{
	ExitConfigModeMode       	= 0,
	VerifyOPM3Mode          	= 1,
	VerifyConfigMode    		= 2,
	ConfigurationJudgeMode 		= 3,
	CheckDeviceStatusMode 		= 4,
	VerifyStatus1Mode 			= 5,
	ClearFlags2Mode 			= 6,			/*Distinguish between IgbtDrv_FSM_InitSeqCheckModeType*/
	GotoOPM4Mode 				= 7
} IgbtDrv_FSM_InitSeqCheckModeType;

/*(Finite State Machine)Working mode substate machine type */
typedef enum
{
	CheckPrimaryStatus2Mode      = 0,			/*Distinguish between IgbtDrv_FSM_InitSeqCheckModeType*/
	VerifyStatusMode          	= 1,
	RuntimeErrorDetectedMode    = 2
} IgbtDrv_FSM_RunTimeModeType;

/* (Finite State Machine)Working mode substate machine type */
typedef enum
{
	LMIErrMode      		= 0,
	InitErrMode          	= 1,
	EventsClassAErrMode     = 2,
	EventsClassBErrMode 	= 3,
	RuntimeErrMode 			= 4
} IgbtDrv_FSM_ErrorHandlingModeType;

typedef enum
{
	None_Err                     = 0,
	ResetChipMode_Err               ,
	ReadPrimaryReadyStatusMode_Err  ,
	CheckPrimaryStatus1Mode_Err    	,
	ReadSecondaryReadyStatusMode_Err ,
	ClearFlags1Mode_Err 			,
	CheckDeviceIDMode_Err 			,
	EnterConfigMode_Err 			,
	VerifyOPM2Mode_Err 				,
	ConfigDeviceMode_Err 			,
	SystemTestMode_Err 				,

	ExitConfigModeMode_Err       	,
	VerifyOPM3Mode_Err          	,
	VerifyConfigMode_Err    		,
	ConfigurationJudgeMode_Err 		,
	CheckDeviceStatusMode_Err 		,
	VerifyStatus1Mode_Err 			,
	ClearFlags2Mode_Err 			,
	GotoOPM4Mode_Err 				,

	CheckPrimaryStatus2Mode_Err      ,
	VerifyStatusMode_Err          	,
	RuntimeErrorDetectedMode_Err    ,

	IgbtDrv_init_Err

} IgbtDrvErrType;

/* (Finite State Machine)Running structure */
typedef struct{
	IgbtDrv_FSM_ModeType 				Mode;
	IgbtDrv_FSM_InitSeqModeType 		InitSeqMode;
	IgbtDrv_FSM_InitSeqCheckModeType    InitSeqCheckMode;
	IgbtDrv_FSM_RunTimeModeType			RunTimeMode;
	IgbtDrv_FSM_ErrorHandlingModeType   ErrorHandlingMode;
} IgbtDrv_FSM_RamParamType;

/* (Finite State Machine)Function pointer type */
typedef void (*IgbtDrv_FunFSM_Type)(void);

/* (Finite State Machine)Configuration structure*/
typedef struct
{
	IgbtDrv_FunFSM_Type		IgbtDrv_ModuleFSM_pa[4u];
	IgbtDrv_FunFSM_Type  	IgbtDrv_InitSeqStepFSM_pa[10u];
	IgbtDrv_FunFSM_Type 	IgbtDrv_InitCheckSeqStepFSM_pa[8u];
	IgbtDrv_FunFSM_Type		IgbtDrv_RunTimeStepFSM_pa[3u];
	IgbtDrv_FunFSM_Type	 	IgbtDrv_ErrorHandlingFSM_pa[5u];
} IgbtDrv_FSM_FlsParamType;



#endif /* IGBTDRV_TYPES_H_ */
