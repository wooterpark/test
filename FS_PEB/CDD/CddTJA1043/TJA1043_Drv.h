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
* $Name______: TJA1043_Drv.h$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: XM$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:
	The File incule TJA1043 Drive and CAN wakeup Control Data declaration.
**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:   Initial version.

*******************************************************************************/
#ifndef _TJA1043_Drv_H_
#define _TJA1043_Drv_H_

#include "Platform_Types.h"

#define TJA_NONE_S    0U
#define TJA_CAN_S     1U
#define TJA_KEY_S     2U

#define TJA_START_TX  3U
#define TJA_STOP_TX   6U

#define FIRST_PWEON_SCAN  0U
#define LOCAL_WAKEUP_SCAN  1U
#define REMOTE_WAKEUP_SCAN  2U

#define LISTENONLY  0U
#define NORMAL      1U
#define PRESLEEP    2U

typedef enum
{
    POWER_ON_MODE = 0,
    REMOTEWA_MODE = 1,
    LOCALWA_MODE = 2,
    NORMAL_MODE = 3,
    PRESLEEP_MODE = 4,
    SLEEP_MODE = 5
}CANNET_STATE_E;

typedef void (*TJA_WakeAction)(void);
typedef boolean (*TJA_WakeScan)(void);
typedef boolean (*TJA_Timer)(CANNET_STATE_E Index);

typedef struct
{
    TJA_WakeScan Scan[3];
    TJA_WakeAction Action[3];
    uint16 TimeBase[5];
    TJA_Timer Timer;

    uint8 WakeUpSource;
    uint8 RecNmFlag;
    CANNET_STATE_E CanNetSts;
}CanTrcv_S;

typedef struct
{
	uint8 WakeupSorce;
}CanTrcv_OutPut_S;

extern CanTrcv_S CanTrcv;

extern void CanTrcv_Sleep(void);
extern void CanTrcv_Init(void);
extern void CanTrcv_Set(CanTrcv_OutPut_S * mOut);

#endif
