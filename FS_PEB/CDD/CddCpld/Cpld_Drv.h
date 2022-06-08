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
* $Name______: CPLD_Drv.h$
* $Variant___: 0.0.0$
* $Revision__: 0$
* $Author____: XM$
**
**----------------------------------------------------------------------------**
** MAY BE CHANGED BY USER [Yes/No]: No
**----------------------------------------------------------------------------**
** DESCRIPTION:
				The Cpld Drive head file.

**----------------------------------------------------------------------------**
** HISTORY:
V1.0.0:   Initial version.

*******************************************************************************/
#ifndef CPLD_DRV_H_
#define CPLD_DRV_H_

#include "Platform_Types.h"

typedef enum
{
    EI09 = 1,
    EI09G = 2,
    EI07X = 3,
    EI99 = 4
}Cpld_PlatformInfo_E;

typedef enum
{
    DemoA = 1,
    DemoB = 2,
    DemoC = 3
}Cpld_DemoStateInfo_E;

typedef enum
{
    TestVersion = 0,
    PublishVersion = 1
}Cpld_PublishState_E;

typedef enum
{
    Zero = 0,
    One
}Cpld_PariCheck_E;

typedef enum
{
    US18 = 0,
    US20 = 1,
    US22 = 2,
    US24 = 3,
    US26 = 4,
    US28 = 5,
    US30 = 6,
    US32 = 7
}Cpld_DeadTime_E;

typedef enum
{
	Cpld_Normal = 0,
	Cpld_Fault = 1
}Cpld_Fault_Info_E;

typedef enum
{
	Mcu_Clear_Cpld_Fault_Unfinish = 0,
	Mcu_Clear_Cpld_Fault_Finish = 1
}Clear_Fault_Flag_E;

typedef enum
{
	Tlf35584_SS1_Low = 0,
	Tlf35584_SS1_High = 1
}Tlf35584_SS1_Flag_E;

typedef enum
{
	Fully_Close = 0,
	Upper_ASC,
	Lower_ASC,
	Fully_Open
}Cpld_Pwm_Info_E;

typedef enum
{
	Cpld_Clear_Fault_Start = 0,
	Cpld_Clear_Fault_Stop,
	Cpld_Alive_Detect_Start,
	Cpld_Alive_Fault_Occur
}Cpld_Clear_Fault_Info_E;

typedef enum
{
	Read_Clear_Cpld_Fault_State=0,
	Read_TLF35584_SS1_State,
	Read_Cpld_Rx_State,
	Cpld_State_Fault_Occur,
	Cpld_State_Normal
}Cpld_State_Manegement_Info_E;

typedef uint8 Cpld_Reserved_E;
typedef uint8 Cpld_Versr_Info_E;
typedef uint8 Cpld_Cnt_Num_E;

typedef struct
{
    Cpld_PariCheck_E ParityCheck:1;
    Cpld_Cnt_Num_E  CountNum:3;    
    Tlf35584_SS1_Flag_E SS1Flag:1;
	Clear_Fault_Flag_E ClearFaultFlag:1;
    Cpld_Reserved_E ReservedBits:4;
    Cpld_Fault_Info_E SZTKTFault:1;
    Cpld_Fault_Info_E CpldExdClockErr:1;
    Cpld_Fault_Info_E LwBrgUnderVol:1;
    Cpld_Fault_Info_E UpBrgUnderVol:1;
    Cpld_Fault_Info_E LwBrgShortCru:1;
    Cpld_Fault_Info_E UpBrgShortCru:1;
    Cpld_Fault_Info_E IphOverCurrent:1;
    Cpld_Fault_Info_E UdcOverVoltage:1;
    Cpld_Fault_Info_E NENFault:1;   

    Cpld_Pwm_Info_E PwmDriveState:2;
    Cpld_Versr_Info_E CpldVersion:4;
    Cpld_PublishState_E PublishState:1;
    Cpld_DemoStateInfo_E DemoState:2;
    Cpld_PlatformInfo_E PlatformNum:4;
}Cpld_Rx_Bits_S;

typedef union
{
    Cpld_Rx_Bits_S Bit;
    uint32 All;
} Cpld_Rx_Analys_U;

typedef struct
{
    Cpld_DeadTime_E DeadTime:3;
    uint8 Reserved1:5;
    uint8 Reserved2:8;
    uint8 Reserved3:8;
}Cpld_Tx_Bits_S;

typedef union
{
    Cpld_Tx_Bits_S Bit;
    uint32 All;
} Cpld_Tx_Analys_U;

typedef struct
{
	uint8 ParityChkCnt;
	uint8 CpldAliveCnt;
	uint8 IphOverCurCnt;
	uint8 UdcOverVolCnt;
	uint8 ExdClockErrCnt;
	uint8 SPIComErrCnt;
	uint8 DIExdClockErrCnt;

	uint8 LwBrgUnderVolCnt;
	uint8 SZTKTFaultCnt;
	uint8 UpBrgUnderVolCnt;
	uint8 NENFaultCnt;
	uint8 LwBrgShortCruCnt;
	uint8 UpBrgShortCruCnt;
}Cpld_Comu_Cnt_S;

typedef struct
{
	uint8 CpldVersion;
	uint8 ProjectNum;
	uint8 PwmDriveState;
}Cpld_OutPut_S;

/*******************************************************************************
** Function Name : Std_Bilateral_Diag
** Parameter[in] : (1)input (2)up (3)low (4)count (5)output
** Parameter[out]: void
** Return Value  : void
** Note          : Specific function
** Description   : Diagnose whether the input data is overrun.
*******************************************************************************/
#define Std_Bilateral_Diag(value,up,low,cnt,output)             \
            if(((value) > (up)) || ((value) < (low)))           \
            {                                                   \
                (cnt)++;                                          \
                if((cnt) > 7U)                                    \
                {                                               \
                    (cnt) = 7U;                                   \
                    (output);                                     \
                }                                               \
            }else                                               \
            {                                                   \
                if((cnt) > 0U)                                    \
                {                                               \
                    (cnt)--;                                      \
                }                                               \
            }

/*******************************************************************************
** Function Name : Std_Equal_Diag
** Parameter[in] : (1)input (2)rightvalue (3)count (4)output
** Parameter[out]: void
** Return Value  : void
** Note          : Specific function
** Description   : Diagnose whether the input data is overrun.
*******************************************************************************/
#define Std_Equal_Diag(value,norm,cnt,output)           \
            if((value) != (norm))                       \
            {                                           \
                (cnt)++;                                  \
                if((cnt) > 7U)                            \
                {                                       \
                   (cnt) = 7U;                            \
                   (output);                              \
                }                                       \
            }else                                       \
            {                                           \
                if((cnt) > 0U)                            \
                {                                       \
                    (cnt)--;                              \
                }                                       \
            }

extern volatile uint8 VAR_Cpld_Normal_Work_u8;
extern void Cpld_Start_Clear_Fault(void);

extern void Cpld_Stop_Clear_Fault(void);

extern void Cpld_State_Management(void);

extern void Cpld_Clear_Fault_Management(void);

extern void Cpld_Com_Task(Cpld_OutPut_S *mOut);

#endif
