/*******************************************************************************
**----------------------------------------------------------------------------**
** Copyright (c) 2018 by JEE.		All rights reserved.
** This software is copyright protected and proprietary to JEE.
** JEE grants to you only those rights as set out in the license conditions.
** All other rights remain with JEE.
**----------------------------------------------------------------------------**
**
* Administrative Information
* $Namespace_: \xx\xx$
* $Class_____: C$
* $Name______: TJA1043_Drv.c$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: XM$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: Yes
**----------------------------------------------------------------------------**
** DESCRIPTION:
			The File incule TJA1043 Drive and CAN wakeup Control source code.
**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:  Initial version.

*******************************************************************************/
#include "Dio.h"
#include "BswM.h"
#include "Std_Types.h"
#include "TJA1043_Drv.h"
//#include "Com_CbkType.h"
#include "ComAppl_Cbk.h"

#pragma section ".rodata.Calib_32"
const volatile uint16 CAL_TimeLimit_au16[5] =
{
		0U,
		100U,
		500U,
		250U,
		100U,
};
#pragma section

static void TJA_Listen(void);
static void TJA_Normal(void);
static void TJA_GotoSleep(void);
static boolean PowerOnErrJudge(void);
static boolean LocalWakeUpJudge(void);
static boolean RemoteWakeUpJudge(void);
static boolean UniversalTimer(CANNET_STATE_E Index);

CanTrcv_S CanTrcv =
{
    {
        PowerOnErrJudge,
        LocalWakeUpJudge,
        RemoteWakeUpJudge,
    },
    {
        TJA_Listen,
        TJA_Normal,
        TJA_GotoSleep,
    },
    {
        0U,0U,0U,0U,0U
    },
    UniversalTimer,
    TJA_KEY_S,
    FALSE,
    POWER_ON_MODE
};


/*******************************************************************************
** Function Name : TJA_Listen
** Parameter[in] : void
** Parameter[out]: void
** Return Value  : void
** Note          : static function
** Description   : ListenOnly
*******************************************************************************/
static void TJA_Listen(void)
{
	Dio_WriteChannel(DioConf_DioChannel_DO_STBCAN_P23_5,STD_HIGH);
	Dio_WriteChannel(DioConf_DioChannel_DO_CAN0EN_P22_7,STD_LOW);
}

/*******************************************************************************
** Function Name : TJA_Normal
** Parameter[in] : void
** Parameter[out]: void
** Return Value  : void
** Note          : static function
** Description   : TJA_Normal
*******************************************************************************/
static void TJA_Normal(void)
{
	Dio_WriteChannel(DioConf_DioChannel_DO_STBCAN_P23_5,STD_HIGH);
	Dio_WriteChannel(DioConf_DioChannel_DO_CAN0EN_P22_7,STD_HIGH);
}

/*******************************************************************************
** Function Name : TJA_GotoSleep
** Parameter[in] : void
** Parameter[out]: void
** Return Value  : void
** Note          : static function
** Description   : GotoSleep
*******************************************************************************/
static void TJA_GotoSleep(void)
{
	Dio_WriteChannel(DioConf_DioChannel_DO_STBCAN_P23_5,STD_LOW);
	Dio_WriteChannel(DioConf_DioChannel_DO_CAN0EN_P22_7,STD_HIGH);
}

/*******************************************************************************
** Function Name : FirstPowerOnJudge
** Parameter[in] : void
** Parameter[out]: void
** Return Value  : void
** Note          : static function
** Description   : FirstPowerOnJudge
*******************************************************************************/
static boolean PowerOnErrJudge(void)
{
	boolean can0_State;
	if(STD_LOW == Dio_ReadChannel(DioConf_DioChannel_DI_CAN0ERR_P23_0))
	{
		can0_State=TRUE;
	}
	else
	{
		can0_State=FALSE;
	}
	return can0_State;
}

/*******************************************************************************
** Function Name : RemoteWakeUpJudge
** Parameter[in] : void
** Parameter[out]: void
** Return Value  : boolean
** Note          : static function
** Description   : RemoteWakeUpJudge
*******************************************************************************/
static boolean RemoteWakeUpJudge(void)
{
        boolean RemoteWakeUp_State;
	if(CanTrcv.RecNmFlag == TRUE)
	{
	    CanTrcv.RecNmFlag = FALSE;
	    CanTrcv.WakeUpSource = TJA_CAN_S;
            RemoteWakeUp_State=TRUE;
	}
	else
	{
                RemoteWakeUp_State=FALSE;		
	}
        return RemoteWakeUp_State;
}

/*******************************************************************************
** Function Name : LocalWakeUpJudge
** Parameter[in] : void
** Parameter[out]: void
** Return Value  : boolean Key state.
** Note          : static function.
** Description   : LocalWakeUpJudge
*******************************************************************************/
static boolean LocalWakeUpJudge(void)
{
	uint8 mResult = Dio_ReadChannel(DioConf_DioChannel_DI_KL15_P21_5);
	if(STD_HIGH == mResult)
	{
	    CanTrcv.WakeUpSource = TJA_KEY_S;
	}
    return(mResult);
}

/*******************************************************************************
** Function Name : UniversalTimer
** Parameter[in] : index
** Parameter[out]: none
** Return Value  : void
** Note          : just like the name.
** Description   : UniversalTimer
*******************************************************************************/
static boolean UniversalTimer(CANNET_STATE_E Index)
{
	uint8 mResult = FALSE;
	uint8 mIndex = (uint8)Index;
	uint16* Timer = &CanTrcv.TimeBase[0U];

	if(Timer[mIndex] >= CAL_TimeLimit_au16[mIndex])
	{
        mResult = TRUE;
        Timer[mIndex] = 0U;
	}
	else
	{
	    Timer[mIndex] ++;
	}
	return(mResult);
}

/*******************************************************************************
** Function Name : CanTrcv_Set
** Parameter[in] : none
** Parameter[out]: none
** Return Value  : void
** Note          : 2ms
** Description   : To Implement CAN PowerDown control.
*******************************************************************************/
void CanTrcv_Set(CanTrcv_OutPut_S * mOut)
{
      CanTrcv.RecNmFlag = VAR_ComRecNmFlag_u8;
 //     VAR_ComRecNmFlag_u8 = FALSE;

	switch(CanTrcv.CanNetSts)
	{
		case POWER_ON_MODE:
            CanTrcv.Action[NORMAL]();
            if(TRUE==CanTrcv.Scan[LOCAL_WAKEUP_SCAN]())
            {
                CanTrcv.CanNetSts = LOCALWA_MODE;
            }
			else if(TRUE==CanTrcv.Scan[REMOTE_WAKEUP_SCAN]())
			{
				CanTrcv.CanNetSts = REMOTEWA_MODE;
			}
			else
			{
				CanTrcv.CanNetSts = LOCALWA_MODE;
			}
			break;
		case REMOTEWA_MODE:
			if(TRUE==CanTrcv.Timer(REMOTEWA_MODE))
			{
				CanTrcv.CanNetSts = LOCALWA_MODE;
			}
			break;
		case LOCALWA_MODE:
			if(TRUE==CanTrcv.Timer(LOCALWA_MODE))
			{
				CanTrcv.CanNetSts = NORMAL_MODE;
			}
			break;
		case NORMAL_MODE:
			if(TRUE==CanTrcv.Scan[LOCAL_WAKEUP_SCAN]())
			{
				CanTrcv.CanNetSts = LOCALWA_MODE;
				CanTrcv.TimeBase[NORMAL_MODE] = 0;
			}
			else if(TRUE==CanTrcv.Scan[REMOTE_WAKEUP_SCAN]())
			{
				CanTrcv.CanNetSts = REMOTEWA_MODE;
				CanTrcv.TimeBase[NORMAL_MODE] = 0;
			}
			else
			{
				if(TRUE==CanTrcv.Timer(NORMAL_MODE))
				{
					CanTrcv.CanNetSts = PRESLEEP_MODE;
				}
			}
			break;
		case PRESLEEP_MODE:
			if(TRUE==CanTrcv.Timer(PRESLEEP_MODE))
			{
				CanTrcv.CanNetSts = SLEEP_MODE;
				CanTrcv.WakeUpSource = TJA_NONE_S;
				CanTrcv.Action[PRESLEEP]();
			}
			break;
		case SLEEP_MODE:
		    break;
		default:
		    break;
	}

	mOut->WakeupSorce = CanTrcv.WakeUpSource;
}

/*******************************************************************************
** Function Name : CanTrcv_Init
** Parameter[in] : CanTrcv_S * mCanTrcv
** Parameter[out]: none
** Return Value  : void
** Note          : init
** Description   : init the CANnetwork
*******************************************************************************/
void CanTrcv_Init(void)
{
	if(CanTrcv.Scan[LOCAL_WAKEUP_SCAN]() == FALSE)
	{
	    CanTrcv.WakeUpSource = TJA_CAN_S;
	}

	CanTrcv.Action[LISTENONLY]();
}


/*******************************************************************************
** Function Name : CanTrcv_Init
** Parameter[in] : CanTrcv_S * mCanTrcv
** Parameter[out]: none
** Return Value  : void
** Note          : init
** Description   : init the CANnetwork
*******************************************************************************/
void CanTrcv_Sleep(void)
{
    CanTrcv.Action[PRESLEEP]();
}
