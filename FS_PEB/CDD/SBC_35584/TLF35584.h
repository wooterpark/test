/*====================================================================================================================*/
/*
 *  @Copyright (C) 2017, 上海知从科技有限公司       Shanghai ZC Technology Co., Ltd.               All rights reserved.
 *
 *               This software is copyright protected and proprietary to Shanghai ZC Technology Co., Ltd.
 *               Shanghai ZC Technology Co., Ltd. grants to you only those rights as set out in the license conditions.
 *               All other rights remain with  Shanghai ZC Technology Co., Ltd.
 */
/**********************************************************************************************************************/
/*
 *	@file       <TLF35584.h>
 *  @brief      <TLF35584驱动模块>
 *
 *  <Compiler: HighTec GNU v4.9.4.0    MCU:TC39x>
 *
 *  @author     <谢江>
 *  @date       <2019-06-10>
 */
/*====================================================================================================================*/

/*====================================================================================================================*/
/*  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  			Change Id       Description
 *  01.00.00   2019-06-10  谢江                  -            Initial version
 *  01.01.01   2020-05-06  张善                  -            Integration with customer project.
 *  01.02.00   2020-05-09  张志强                 -           Add Cal_DiagCycle() function.
 *  													      Add SBC self test.
 *  01.03.00   2021-03-23  谢江                  -            Fix Self Test Bug.
 *  01.04.00   2021-06-12  谢江                  -            Fix TLF35584_RegInit() Bug,may cannot change to normal mode.
 *                                                            Fix LBIST Bug,may false in debug mode.
 *  01.05.00   2021-09-28  谢江                  -            Fix TLF35584_RegInit() Bug,delete 60us delay time.
 *                                                            Fix the problem that the SYSPCFG0 register cannot be configured。
 *                                                            Add FSP Selftest error code.                                             
 *  --------------------------------------------------------------------------------------------------------------------
 */

/*====================================================================================================================*/
#ifndef TLF35584_H_
#define TLF35584_H_

/*====================================================================================================================*/
/*                                                     Includes                                                       */
/*====================================================================================================================*/
#include "Std_Types.h"
#include "TLF35584_Cfg.h"
#include "WdgIf_Types.h"

/*====================================================================================================================*/
/*                                                 Macro Definitions                                                  */
/*====================================================================================================================*/
/* define TLF35584 Mode */
#define TLF35584_NONE                             (0U)
#define TLF35584_INIT                             (1U)
#define TLF35584_NORMAL                           (2U)
#define TLF35584_SLEEP                            (3U)
#define TLF35584_STBY                             (4U)
#define TLF35584_WAKE                             (5U)

/* define TLF35584 Mode Mask */
#define  TLF35584_SYSTEM_INT_MASK                 ((uint8)(0x01U))
#define  TLF35584_WAKE_INT_MASK                   ((uint8)(0x02U))
#define  TLF35584_SPI_INT_MASK                    ((uint8)(0x04U))
#define  TLF35584_MONITOR_INT_MASK                ((uint8)(0x08U))
#define  TLF35584_OVERT_WARN_INT_MASK             ((uint8)(0x10U))
#define  TLF35584_OVERT_FAIL_INT_MASK             ((uint8)(0x20U))
#define  TLF35584_ABIST_INT_MASK                  ((uint8)(0x40U))
#define  TLF35584_MISS_INT_MASK                   ((uint8)(0x80U))
#define  TLF35584_DOUBLE_BIT_ERR_MASK             ((uint8)(0x01U))
/******************************************************************************/

/* TLF35584 register addresses: */
#define TLF35584_REG_DEVCFG0                      ((uint8)0x00U)
#define TLF35584_REG_DEVCFG1                      ((uint8)0x01U)
#define TLF35584_REG_DEVCFG2                      ((uint8)0x02U)
#define TLF35584_REG_PROTCFG                      ((uint8)0x03U)
#define TLF35584_REG_SYSPCFG0                     ((uint8)0x04U)
#define TLF35584_REG_SYSPCFG1                     ((uint8)0x05U)
#define TLF35584_REG_WDCFG0                       ((uint8)0x06U)
#define TLF35584_REG_WDCFG1                       ((uint8)0x07U)
#define TLF35584_REG_FWDCFG                       ((uint8)0x08U)
#define TLF35584_REG_WWDCFG0                      ((uint8)0x09U)
#define TLF35584_REG_WWDCFG1                      ((uint8)0x0AU)
#define TLF35584_REG_RSYSPCFG0                    ((uint8)0x0BU)
#define TLF35584_REG_RSYSPCFG1                    ((uint8)0x0CU)
#define TLF35584_REG_RWDCFG0                      ((uint8)0x0DU)
#define TLF35584_REG_RWDCFG1                      ((uint8)0x0EU)
#define TLF35584_REG_RFWDCFG                      ((uint8)0x0FU)
#define TLF35584_REG_RWWDCFG0                     ((uint8)0x10U)
#define TLF35584_REG_RWWDCFG1                     ((uint8)0x11U)
#define TLF35584_REG_WKTIMCFG0                    ((uint8)0x12U)
#define TLF35584_REG_WKTIMCFG1                    ((uint8)0x13U)
#define TLF35584_REG_WKTIMCFG2                    ((uint8)0x14U)
#define TLF35584_REG_DEVCTRL                      ((uint8)0x15U)
#define TLF35584_REG_DEVCTRLN                     ((uint8)0x16U)
#define TLF35584_REG_WWDSCMD                      ((uint8)0x17U)
#define TLF35584_REG_FWDRSP                       ((uint8)0x18U)
#define TLF35584_REG_FWDRSPSYNC                   ((uint8)0x19U)
#define TLF35584_REG_SYSFAIL                      ((uint8)0x1AU)
#define TLF35584_REG_INITERR                      ((uint8)0x1BU)
#define TLF35584_REG_IF                           ((uint8)0x1CU)
#define TLF35584_REG_SYSSF                        ((uint8)0x1DU)
#define TLF35584_REG_WKSF                         ((uint8)0x1EU)
#define TLF35584_REG_SPISF                        ((uint8)0x1FU)
#define TLF35584_REG_MONSF0                       ((uint8)0x20U)
#define TLF35584_REG_MONSF1                       ((uint8)0x21U)
#define TLF35584_REG_MONSF2                       ((uint8)0x22U)
#define TLF35584_REG_MONSF3                       ((uint8)0x23U)
#define TLF35584_REG_OTFAIL                       ((uint8)0x24U)
#define TLF35584_REG_OTWRNSF                      ((uint8)0x25U)
#define TLF35584_REG_VMONSTAT                     ((uint8)0x26U)
#define TLF35584_REG_DEVSTAT                      ((uint8)0x27U)
#define TLF35584_REG_PROTSTAT                     ((uint8)0x28U)
#define TLF35584_REG_WWDSTAT                      ((uint8)0x29U)
#define TLF35584_REG_FWDSTAT0                     ((uint8)0x2AU)
#define TLF35584_REG_FWDSTAT1                     ((uint8)0x2BU)
#define TLF35584_REG_ABIST_CTRL0                  ((uint8)0x2CU)
#define TLF35584_REG_ABIST_CTRL1                  ((uint8)0x2DU)
#define TLF35584_REG_ABIST_SELECT0                ((uint8)0x2EU)
#define TLF35584_REG_ABIST_SELECT1                ((uint8)0x2FU)
#define TLF35584_REG_ABIST_SELECT2                ((uint8)0x30U)
#define TLF35584_REG_BCK_FREQ_CHANGE              ((uint8)0x31U)
#define TLF35584_REG_BCK_FRE_SPREAD               ((uint8)0x32U)
#define TLF35584_REG_BCK_MAIN_CTRL                ((uint8)0x33U)
#define TLF35584_REG_GTM                          ((uint8)0x3FU)

#ifdef TLF35584_DET_USED
#if (1U == TLF35584_DET_USED)

/*DET Api ID*/
#define TLF35584_ROT_SELF_TEST                    ((uint8)1U)
#define TLF35584_LOGIC_SELF_TEST                  ((uint8)2U)
#define TLF35584_ANALOG_SELF_TEST                 ((uint8)3U)
#define TLF35584_INITIALIZATION                   ((uint8)4U)
#define TLF35584_GET_INTERRUPT                    ((uint8)5U)
#define TLF35584_SET_SLEEP_TIME                   ((uint8)6U)
#define TLF35584_GO_TO_STANDBY                    ((uint8)7U)
#define TLF35584_SERVICE_WDG                      ((uint8)8U)
#define TLF35584_POWER_OFF_RECOVERY               ((uint8)9U)
#define TLF35584_GETVERSIONINFO                   ((uint8)10U)

/*DET Error ID*/
#define TLF35584_ROT_INIT_ERR                     ((uint8)1U)
#define TLF35584_ROT_START_ERR                    ((uint8)2U)
#define TLF35584_ROT_STOP_ERR                     ((uint8)3U)
#define TLF35584_ROT_NO_RESET_ERR                 ((uint8)4U)
#define TLF35584_FWD_INTERRUPT_ERR                ((uint8)5U)
#define TLF35584_FWD_SAFETY_ERR                   ((uint8)6U)
#define TLF35584_WWD_SAFETY_ERR                   ((uint8)7U)
#define TLF35584_ABIST_SAFETY_PATH_ERR            ((uint8)8U)
#define TLF35584_ABIST_SAFETY_COMP_ERR            ((uint8)9U)
#define TLF35584_ABIST_INT_PATH_ERR               ((uint8)10U)
#define TLF35584_ABIST_INT_COMP_ERR               ((uint8)11U)
#define TLF35584_ABIST_SET_MODE_ERR               ((uint8)12U)
#define TLF35584_INIT_CONFIG_ERR                  ((uint8)13U)
#define TLF35584_INIT_SET_MODE_ERR                ((uint8)14U)
#define TLF35584_GET_INTERRUPT_ERR                ((uint8)15U)
#define TLF35584_SET_SLEEP_TIME_ERR               ((uint8)16U)
#define TLF35584_SERVICE_WDG_ERR                  ((uint8)17U)
#define TLF35584_GO_TO_STANDBY_ERR                ((uint8)18U)
#define TLF35584_POWER_OFF_ERR                    ((uint8)19U)
#define TLF35584_WWD_INTERRUPT_ERR                ((uint8)20U)
#define TLF35584_PARAM_POINTER_ERR                ((uint8)21U)

#endif
#endif

/*====================================================================================================================*/
/*                                                Typedef Definitions                                                 */
/*====================================================================================================================*/
typedef uint16 TLF35584_SelfTestType;
typedef uint16  TLF35584_RawResetType;
typedef uint32 TLF35584_InterruptType;

typedef enum
{
    TLF35584_STANDBY_RESET = 0x00U,
    TLF35584_HARD_RESET = 0x01U,
    TLF35584_SOFT_RESET = 0x02U,
    TLF35584_ERR_RESET = 0x03U,
    TLF35584_FWD_RESET = 0x04U,
    TLF35584_WWD_RESET = 0x05U,
    TLF35584_VMON_RESET = 0x06U,
    TLF35584_MULT_RESET = 0x07U,
    TLF35584_INIT_FAILURE = 0x08U,
    TLF35584_VMON_FAILURE = 0x09U,
    TLF35584_OTF_FAILURE = 0x0AU,
    TLF35584_VOLTSELERR_FAILURE = 0x0BU
}TLF35584_ResetType;

typedef struct
{
    uint8    ReqCmd;         /* requested user command to ext. watch dog */
    uint8    UserData;       /* send/receive back data for this operation */
}TLF35584_CmdType;

typedef struct
{
	uint16 TLF35584_TxBuffer[TLF35584_MAX_EBBUFF];
	uint16 TLF35584_RxBuffer[TLF35584_MAX_EBBUFF];
	uint8 Count;
}TLF35584_DataType;

typedef struct
{
	uint8 DEVCFG0Value;
	uint8 DEVCFG1Value;
	uint8 DEVCFG2Value;
	uint8 SYSPCFG0Value;
	uint8 SYSPCFG1Value;
	uint8 WDCFG0Value;
	uint8 WDCFG1Value;
	uint8 FWDCFGValue;
	uint8 WWDCFG0Value;
	uint8 WWDCFG1Value;
}TLF35584_ConfigType;

/*====================================================================================================================*/
/*                                           Global Variable Declarations                                             */
/*====================================================================================================================*/
extern boolean VAR_TLF35584_InitFinish_Flag_b;
extern boolean VAR_TLF35584_SelfTestFinish_Flag_b;
/* TLF35584 interrupt flag. Used to check INT interrupt trigger */
extern volatile uint8 TLF35584_Interrupt;

/* TLF35584 self test result. TLF35584_SelfTest() result is stored in TLF35584_SelfTestError. */
extern uint16 TLF35584_SelfTestError;

/* TLF35584 register value. TLF35584_GetInterruptStatus() result is stored in TLF35584_Reg */
extern uint8 TLF35584_Reg[TLF35584_MAX_ADDRESS];

/* TLF35584 SYSFAIL to OTWRNSF register value, TLF35584_GetResetStatus() result is store in TLF35584_ResetStatus. */
extern uint8 TLF35584_ResetStatus[12U];

/* TLF35584 SYSFAIL register value, TLF35584_GetSysFailDoubleBitErr() result is store in TLF35584_SysFailDoubleBitErr. */
extern boolean TLF35584_SysFailDoubleBitErr;

extern const TLF35584_ConfigType TLF35584_Config;

/*====================================================================================================================*/
/*                                           Global Function Declarations                                             */
/*====================================================================================================================*/
extern void TLF35584_SetSelfTestReslutFlag(void);

extern boolean TLF35584_GetSelfTestReslutFlag(void);

extern void TLF35584_ClearSelfTestReslutFlag(void);

extern void TLF35584_SetInitFinishFlag(void);

extern boolean TLF35584_GetInitFinishFlag(void);

extern void TLF35584_ClearInitFinishFlag(void);

extern Std_ReturnType TLF35584_Read(TLF35584_CmdType DataBuf[], uint8 Count);

extern Std_ReturnType TLF35584_Write(const TLF35584_CmdType DataBuf[], uint8 Count);

extern void TLF35584_ConfigInit(TLF35584_ConfigType* ConfigPtr);

extern Std_ReturnType TLF35584_GetInterruptStatus(uint8 GetAllFlag);

extern Std_ReturnType TLF35584_SetSleepTime(uint32 Minute);

extern Std_ReturnType TLF35584_GoToStandby(void);

extern Std_ReturnType TLF35584_GoToNormal(void);

#ifdef TLF35584_SELF_TEST
#if (1U == TLF35584_SELF_TEST)
extern void TLF35584_ABISTSelfTestISR(void);

extern TLF35584_SelfTestType TLF35584_FSPSelfTest(void);

extern TLF35584_SelfTestType TLF35584_LogicSelfTest(void);

extern TLF35584_SelfTestType TLF35584_AnalogSelfTest(void);

extern TLF35584_SelfTestType TLF35584_SelfTest(void);
#endif
#endif

extern Std_ReturnType TLF35584_ServiceWWD(void);

extern Std_ReturnType TLF35584_DisableFWD(void);

extern Std_ReturnType TLF35584_EnableFWD(void);

extern Std_ReturnType TLF35584_ServiceFWD(void);

extern Std_ReturnType TLF35584_RegInit(const TLF35584_ConfigType* ConfigPtr);

extern TLF35584_ResetType TLF35584_GetResetReason(void);

extern TLF35584_RawResetType TLF35584_GetResetRaw(void);

extern Std_ReturnType TLF35584_GetInterruptRaw(uint8 *InterruptFlag);

extern Std_ReturnType TLF35584_ControlStby(uint8 contrlStbyState);

extern Std_ReturnType TLF35584_GetStbyState(uint8 *stbyState);

extern Std_ReturnType TLF35584_SetMode(const WdgIf_ModeType Mode);

extern void TLF35584_SetTriggerCondition(const uint16 timeout);

extern void TLF35584_GetVersionInfo(Std_VersionInfoType* versioninfo);

extern void TLF35584_Init(const TLF35584_ConfigType* ConfigPtr);

extern void TLF35584_ShutDown(void);
#endif /* TLF35584_H_ */
