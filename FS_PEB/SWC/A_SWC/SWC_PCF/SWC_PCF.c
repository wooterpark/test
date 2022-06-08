/*
 * File: SWC_PCF.c
 *
 * Code generated for Simulink model 'SWC_PCF'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Jan 16 13:41:43 2021
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWC_PCF.h"
#include "SWC_PCF_private.h"
#include "look1_iflf_binlcpw.h"
#include "look1_iflf_binlxpw.h"

/* Named constants for Chart: '<S64>/ErrRetry' */
#define SWC_PCF_IN_Init                ((uint8)1U)
#define SWC_PCF_IN_NO_ACTIVE_CHILD     ((uint8)0U)
#define SWC_PCF_IN_Pause               ((uint8)2U)
#define SWC_PCF_IN_Retry               ((uint8)3U)
#define SWC_PCF_IN_StallFault          ((uint8)4U)

/* Named constants for Chart: '<S131>/AutoPJudge' */
#define SWC_PCF_IN_JudgeAutoOutP       ((uint8)1U)
#define SWC_PCF_IN_JudgeOutP           ((uint8)2U)
#define SWC_PCF_IN_JudgeStandby        ((uint8)3U)

/* Named constants for Chart: '<S118>/PcfStm_State' */
#define SWC_PCF_IN_BCFault             ((uint8)1U)
#define SWC_PCF_IN_BCInP               ((uint8)2U)
#define SWC_PCF_IN_BCInit              ((uint8)3U)
#define SWC_PCF_IN_BCOutP              ((uint8)4U)
#define SWC_PCF_IN_BCRun               ((uint8)5U)
#define SWC_PCF_IN_BlindParkControl    ((uint8)1U)
#define SWC_PCF_IN_Fault               ((uint8)2U)
#define SWC_PCF_IN_Init_g              ((uint8)3U)
#define SWC_PCF_IN_NormalParkControl   ((uint8)1U)
#define SWC_PCF_IN_PCInP               ((uint8)1U)
#define SWC_PCF_IN_PCInit              ((uint8)2U)
#define SWC_PCF_IN_PCOutP              ((uint8)3U)
#define SWC_PCF_IN_PCRun               ((uint8)4U)
#define SWC_PCF_IN_ParkControl         ((uint8)4U)
#define SWC_PCF_IN_RCInP               ((uint8)1U)
#define SWC_PCF_IN_RCInit              ((uint8)2U)
#define SWC_PCF_IN_RCOutP              ((uint8)3U)
#define SWC_PCF_IN_RCRun               ((uint8)4U)
#define SWC_PCF_IN_RCSuccess           ((uint8)5U)
#define SWC_PCF_IN_RetryParkControl    ((uint8)2U)
#define SWC_PCF_IN_SLActJudge          ((uint8)1U)
#define SWC_PCF_IN_SLFault             ((uint8)2U)
#define SWC_PCF_IN_SLFnh               ((uint8)3U)
#define SWC_PCF_IN_SLInit              ((uint8)4U)
#define SWC_PCF_IN_SLMotorAcc          ((uint8)5U)
#define SWC_PCF_IN_SLRetry             ((uint8)6U)
#define SWC_PCF_IN_SLRun               ((uint8)7U)
#define SWC_PCF_IN_SLWait              ((uint8)8U)
#define SWC_PCF_IN_SLockedPosJudge     ((uint8)9U)
#define SWC_PCF_IN_SelfCheck           ((uint8)5U)
#define SWC_PCF_IN_SelfLearnControl    ((uint8)3U)
#define SWC_PCF_IN_Standby             ((uint8)4U)

/* Exported block signals */
float32 VAR_PcfSig_Pos1_f32;           /* '<S99>/Product'
                                        * 1路位置信号
                                        */
float32 VAR_PcfSig_tMosPcf_f32;        /* '<S112>/Add1'
                                        * Mos管温度
                                        */
float32 VAR_PcfSig_IsenPcf_f32;        /* '<S106>/Product'
                                        * EPC工作电流
                                        */
float32 VAR_PcfSig_IsentMosPcf_f32;    /* '<S111>/Add1' */
float32 VAR_PcfSig_IUBPcf_f32;         /* '<S108>/Add1' */
float32 VAR_PcfSig_IdcPcf_f32;         /* '<S87>/Switch' */
float32 VAR_PcfSig_Pos2_f32;           /* '<S100>/Product'
                                        * 2路位置信号
                                        */
float32 VAR_PcfSig_VehSpd_f32;         /* '<S89>/CAL_PcfSig_VehSpd_f32'
                                        * 车速信号
                                        */
float32 VAR_PcfSig_PosAimInP_f32;      /* '<S114>/Add1'
                                        * 入P目标位置
                                        */
float32 VAR_PcfSig_PosAimOutP_f32;     /* '<S114>/Add2'
                                        * 出P目标位置
                                        */
float32 VAR_PcfSig_nPcfMot_f32;        /* '<S117>/Add1'
                                        * 执行器转速
                                        */
float32 VAR_PcfSig_VDD5Pcf_f32;
             /* '<S1>/RP_SWC_IoHwAb_ADC_BSW_VDD5PCF_IoHwAb_ADC_GetPhyVoltage' */
float32 VAR_PcfSig_UBRPcf_f32;
                 /* '<S1>/RP_SWC_IoHwAb_ADC_BSW_UBRPCF_IoHwAb_ADC_GetPhyVoltage'
                  * EPC工作电压
                  */
float32 VAR_PcfCtl_AimPosPID_f32;      /* '<S74>/Merge' */
float32 VAR_PcfCtl_PosDif_f32;         /* '<S75>/Subtract' */
float32 VAR_PcfCtl_PosKp_f32;          /* '<S77>/Switch5' */
float32 VAR_PcfCtl_PosKi_f32;          /* '<S77>/Saturation1' */
float32 VAR_PcfCtl_PosKd_f32;          /* '<S77>/Switch1' */
float32 VAR_PcfCtl_PosPIDOut_f32;      /* '<S77>/Saturation3' */
float32 VAR_PcfCtl_SoftDycPID_f32;     /* '<S72>/Switch2' */
float32 VAR_PcfSig_DycLim_f32;         /* '<S113>/Saturation'
                                        * 占空比限制
                                        */
float32 VAR_PcfCtl_DycOutPID_f32;      /* '<S72>/Product1' */
float32 VAR_PcfStm_SLPosReg_f32;       /* '<S118>/PcfStm_State' */
float32 VAR_PcfStm_SLtrqDes_f32;       /* '<S118>/PcfStm_State' */
uint16 VAR_PcfSig_TestTimes_u16;       /* '<S97>/Switch1'
                                        * 出入P自动测试次数
                                        */
uint16 VAR_PcfStm_Actime_u16;          /* '<S118>/PcfStm_State' */
uint8 VAR_PcfDia_stSLActPos_u8;        /* '<S22>/Merge' */
uint8 VAR_PcfDia_stActPos_u8;          /* '<S12>/Merge1' */
uint8 VAR_PcfDia_stRunTi_u8;           /* '<S23>/Merge' */
uint8 VAR_PcfSig_stParkCtlReq_u8;      /* '<S94>/Switch' */
uint8 VAR_PcfDia_stUdc_u8;             /* '<S18>/Data Type Conversion'
                                        * EPC工作电压等级
                                        */
uint8 VAR_PcfStm_stPark_u8;            /* '<S118>/EnumToUint1' */
uint8 VAR_PcfStm_stParkCtl_u8;         /* '<S118>/EnumToUint2' */
uint8 VAR_PcfStm_BCstDiag_u8;          /* '<S118>/PcfStm_State' */
uint8 VAR_PcfStm_SLstDiag_u8;          /* '<S118>/PcfStm_State' */
uint8 VAR_PcfStm_SLstModeReq_u8;       /* '<S118>/PcfStm_State' */
boolean VAR_PcfSig_flgP_b;             /* '<S92>/Switch'
                                        * 挡杆信号
                                        */
boolean VAR_PcfStm_flgActJudgeToSLRun_b;/* '<S121>/Logical Operator' */
boolean VAR_PcfDia_flgBCLocked_b;      /* '<S13>/Switch12' */
boolean VAR_PcfSig_flgIoc_b;
                     /* '<S1>/RP_SWC_IoHwAb_DIO_Get_BSW_flgPcfOc_IoHwAb_DIO_Get'
                      * EPC电路过流信号
                      */
boolean VAR_PcfDia_flgHwIdcOv_b;       /* '<S14>/Data Type Conversion1' */
boolean VAR_PcfDia_flgSenOv_b;         /* '<S32>/Data Type Conversion1' */
boolean VAR_PcfDia_flgSenVerFail_b;    /* '<S31>/Data Type Conversion1' */
boolean VAR_PcfStm_flgBPCToFault_b;    /* '<S122>/Logical Operator10' */
boolean VAR_PcfSig_flgKL15_b;          /* '<S104>/Switch'
                                        * KL15信号
                                        */
boolean VAR_PcfDia_flgCritSpd_b;       /* '<S20>/Logical Operator' */
boolean VAR_PcfSig_flgBrake_b;         /* '<S91>/Switch'
                                        * 刹车状态信号
                                        */
boolean VAR_PcfSig_stDoor_b;           /* '<S95>/Switch'
                                        * 驾驶侧门状态信号
                                        */
boolean VAR_PcfStm_flgEnAutoInP_b;     /* '<S132>/Switch' */
boolean VAR_PcfSig_flgACC_b;           /* '<S89>/CAL_PcfSig_flgACC_b'
                                        * 加速信号
                                        */
boolean VAR_PcfSig_flgPowerOn_b;       /* '<S105>/Switch'
                                        * PowerOn使能信号
                                        */
boolean VAR_PcfStm_flgDiaAutoP_b;      /* '<S131>/Switch3' */
boolean VAR_PcfStm_flgEnAutoOutP_b;    /* '<S133>/Switch' */
boolean VAR_PcfStm_flgFaultToBPC_b;    /* '<S122>/Logical Operator9' */
boolean VAR_PcfDia_flgRunTiOv_b;       /* '<S53>/Compare' */
boolean VAR_PcfDia_flgLocked_b;        /* '<S15>/Switch12' */
boolean VAR_PcfDia_flgRetry_b;         /* '<S66>/Switch' */
boolean VAR_PcfDia_VDD5PcfErr_b;       /* '<S45>/Data Type Conversion1' */
boolean VAR_PcfDia_flgRetryShield_b;   /* '<S66>/Switch1' */
boolean VAR_PcfDia_flgFault_b;         /* '<S61>/Switch1' */
boolean VAR_PcfStm_flgFaultToParkCtl_b;/* '<S126>/Logical Operator3' */
boolean VAR_PcfStm_flgPCInPtoRun_b;    /* '<S134>/Logical Operator' */
boolean VAR_PcfStm_flgNPCToStandby_b;  /* '<S130>/Logical Operator2' */
boolean VAR_PcfStm_flgNPCToRPC_b;      /* '<S123>/Logical Operator12' */
boolean VAR_PcfStm_flgSLAccToWait_b;   /* '<S129>/Relational Operator1' */
boolean VAR_PcfStm_flgSLCToStandby_b;  /* '<S130>/Logical Operator8' */
boolean VAR_PcfDia_flgUdcLoErr_b;      /* '<S18>/Relational Operator'
                                        * 工作电压故障
                                        */
boolean VAR_PcfDia_flgtMosOv_b;        /* '<S24>/Relational Operator2'
                                        * Mos管过温故障
                                        */
boolean VAR_PcfDiag_flgselfCkFnh_b;    /* '<S59>/Logical Operator2' */
boolean VAR_PcfSig_NVMSLFnh_b;         /* '<S115>/Switch'
                                        * 自学习完成信号
                                        */
boolean VAR_PcfDia_flgAimInPRat_b;     /* '<S17>/Logical Operator' */
boolean VAR_PcfStm_flgStandbyToNPC_b;  /* '<S130>/Logical Operator1' */
boolean VAR_PcfStm_flgStandbyToSLC_b;  /* '<S130>/Logical Operator6' */
boolean VAR_PcfDia_flgNPCActPos_b;     /* '<S21>/Relational Operator15' */
boolean VAR_PcfStm_flgPCInitToInP_b;   /* '<S125>/Logical Operator9' */
boolean VAR_PcfStm_flgPCInitToOutP_b;  /* '<S125>/Logical Operator3' */
boolean VAR_PcfCtl_enMosPID_b;         /* '<S74>/Merge1' */
boolean VAR_PcfCtl_enMosOutPID_b;      /* '<S73>/Logical Operator' */
boolean VAR_PcfCtl_DirOutPID_b;        /* '<S72>/Relational Operator2' */
boolean VAR_PcfCtl_enMos_b;            /* '<S70>/Merge' */
boolean VAR_PcfDia_flgAllowPwmRun_b;   /* '<S58>/Logical Operator1' */
boolean VAR_PcfDiag_flgselfCkErr_b;    /* '<S59>/Logical Operator4' */
boolean VAR_PcfDia_flgShtDwnReq_b;     /* '<S60>/Logical Operator' */
boolean VAR_PcfDia_flgUnexPosWarn_b;   /* '<S62>/Logical Operator' */
boolean VAR_PcfCtl_ActFnh_b;           /* '<S76>/Switch' */
boolean VAR_PcfSig_flgBelt_b;          /* '<S94>/Constant'
                                        * 安全带状态信号
                                        */
boolean VAR_PcfStm_BCMotDir_b;         /* '<S118>/PcfStm_State' */
boolean VAR_PcfStm_BCenMos_b;          /* '<S118>/PcfStm_State' */
boolean VAR_PcfStm_MotDir_b;           /* '<S118>/PcfStm_State' */
boolean VAR_PcfStm_enMos_b;            /* '<S118>/PcfStm_State' */
boolean VAR_PcfStm_flgRetryFnh_b;      /* '<S118>/PcfStm_State' */
boolean VAR_PcfStm_SLActDir_b;         /* '<S118>/PcfStm_State' */
boolean VAR_PcfStm_SLEnMotorAcc_b;     /* '<S118>/PcfStm_State' */
boolean VAR_PcfStm_SLenMos_b;          /* '<S118>/PcfStm_State' */
boolean VAR_PcfStm_BCflgModeReq_b;     /* '<S118>/PcfStm_State' */
boolean VAR_PcfStm_SLflgPosNvm_b;      /* '<S118>/PcfStm_State' */
boolean VAR_PcfStm_flgAutoP_b;         /* '<S118>/PcfStm_State' */
boolean VAR_PcfDia_flgStallFault_b;    /* '<S64>/ErrRetry' */
boolean VAR_PcfDia_flgstallPause_b;    /* '<S64>/ErrRetry' */

/* Exported data definition */
#pragma section ".rodata.Calib_32"

/* Definition for custom storage class: iEDS_Parameter */
const volatile float32 CAL_PcfCtl_BCRunDyc_f32 = 0.85F;
                            /* Referenced by: '<S81>/CAL_PcfCtl_BCRunDyc_f32' */

/* 盲控状态下给定的固定占空比 */
const volatile float32 CAL_PcfCtl_InitOutP_f32 = 0.85F;
                            /* Referenced by: '<S79>/CAL_PcfCtl_InitOutP_f32' */
const volatile boolean CAL_PcfCtl_ManualDir_b = 0;
                             /* Referenced by: '<S84>/CAL_PcfCtl_ManualDir_b' */

/* 开环控制输出转动方向 */
const volatile float32 CAL_PcfCtl_ManualDty_f32 = 0.0F;
                           /* Referenced by: '<S84>/CAL_PcfCtl_ManualDty_f32' */

/* 开环控制输出占空比 */
const volatile boolean CAL_PcfCtl_ManualEn_b = 0;
                              /* Referenced by: '<S84>/CAL_PcfCtl_ManualEn_b' */

/* 开环控制输出Mos管使能 */
const volatile float32 CAL_PcfCtl_PosKd_f32 = 3.5F;
                               /* Referenced by: '<S77>/CAL_PcfCtl_PosKd_f32' */

/* 位置式PID控制Kd值 */
const volatile float32 CAL_PcfCtl_PosKi_f32 = 0.001F;
                               /* Referenced by: '<S77>/CAL_PcfCtl_PosKi_f32' */

/* 位置式PID控制Ki值 */
const volatile float32 CAL_PcfCtl_PosKp_f32 = 19.0F;
                               /* Referenced by: '<S77>/CAL_PcfCtl_PosKp_f32' */

/* 位置式PID控制Kp值 */
const volatile float32 CAL_PcfCtl_PrePos_f32 = 0.008F;
                              /* Referenced by: '<S71>/CAL_PcfCtl_PrePos_f32' */

/* 动作完成检测精度 */
const volatile boolean CAL_PcfCtl_SLRunDir_b = 0;
                              /* Referenced by: '<S82>/CAL_PcfCtl_SLRunDir_b' */

/* 自学习状态下朝出P极限位置转动方向 */
const volatile float32 CAL_PcfCtl_SLRunDyc_f32 = 1.0F;
                            /* Referenced by: '<S82>/CAL_PcfCtl_SLRunDyc_f32' */

/* 自学习状态下给定的固定占空比 */
const volatile float32 CAL_PcfCtl_SLdeltaAimOutP_f32 = 0.32F;
                      /* Referenced by: '<S78>/CAL_PcfCtl_SLdeltaAimOutP_f32' */
const volatile float32 CAL_PcfCtl_SoftDyc_f32 = 0.1F;
                             /* Referenced by: '<S72>/CAL_PcfCtl_SoftDyc_f32' */

/* 占空比输出延迟时间内输出的小占空比 */
const volatile boolean CAL_PcfCtl_flgFnhSwt_b = 0;
                             /* Referenced by: '<S76>/CAL_PcfCtl_flgFnhSwt_b' */

/* 执行器动作完成信号标定量控制切换开关 */
const volatile boolean CAL_PcfCtl_flgFnh_b = 0;
                                /* Referenced by: '<S76>/CAL_PcfCtl_flgFnh_b' */

/* 执行器动作完成信号标定量控制 */
const volatile boolean CAL_PcfCtl_flgManual_b = 0;
                             /* Referenced by: '<S70>/CAL_PcfCtl_flgManual_b' */

/* 开环控制切换开关 */
const volatile float32 CAL_PcfCtl_intPIDdownlim_f32 = -1000.0F;/* Referenced by:
                                                                * '<S77>/Saturation1'
                                                                * '<S77>/Saturation2'
                                                                */

/* 位置PID积分输出下限阈值 */
const volatile float32 CAL_PcfCtl_intPIDuplim_f32 = 1000.0F;/* Referenced by:
                                                             * '<S77>/Saturation1'
                                                             * '<S77>/Saturation2'
                                                             */

/* 位置PID积分输出上限阈值 */
const volatile uint16 CAL_PcfCtl_timePrePos_u16 = 10U;
                          /* Referenced by: '<S71>/CAL_PcfCtl_timePrePos_u16' */

/* 满足精度范围连续检测次数 */
const volatile float32 CAL_PcfDia_AimInPRatDown_f32 = 0.275F;
                       /* Referenced by: '<S17>/CAL_PcfDia_AimInPRatDown_f32' */
const volatile float32 CAL_PcfDia_AimInPRatUp_f32 = 0.375F;
                         /* Referenced by: '<S17>/CAL_PcfDia_AimInPRatUp_f32' */
const volatile float32 CAL_PcfDia_AimInPRdd_f32 = 0.04F;
                           /* Referenced by: '<S12>/CAL_PcfDia_AimInPRdd_f32' */

/* 出P位置诊断允许余量redundancy */
const volatile float32 CAL_PcfDia_AimOutPRdd_f32 = 0.04F;
                          /* Referenced by: '<S12>/CAL_PcfDia_AimOutPRdd_f32' */

/* 入P位置诊断允许余量redundancy */
const volatile uint16 CAL_PcfDia_BCLockedNum_u16 = 30U;
                         /* Referenced by: '<S13>/CAL_PcfDia_BCLockedNum_u16' */

/* 盲控状态允许执行器转动的最大运行时间 */
const volatile float32 CAL_PcfDia_IdcLockedHiHyst_f32 = 7.5F;/* Referenced by:
                                                              * '<S13>/CAL_PcfDia_IdcLockedHiHyst_f32'
                                                              * '<S15>/CAL_PcfDia_IdcLockedHiHyst_f32'
                                                              */

/* 堵转电流高限滞环阈值 */
const volatile float32 CAL_PcfDia_IdcLockedHi_f32 = 8.5F;/* Referenced by:
                                                          * '<S13>/CAL_PcfDia_IdcLockedHi_f32'
                                                          * '<S15>/CAL_PcfDia_IdcLockedHi_f32'
                                                          */

/* 堵转电流高限阈值 */
const volatile uint16 CAL_PcfDia_LockedNum_u16 = 30U;
                           /* Referenced by: '<S15>/CAL_PcfDia_LockedNum_u16' */

/* 堵转诊断次数对应堵转时间判断 */
const volatile float32 CAL_PcfDia_MinPosOutP_f32 = 0.19F;
                          /* Referenced by: '<S21>/CAL_PcfDia_MinPosOutP_f32' */

/* 最小出P位置与齿顶堵转位置角度差 */
const volatile float32 CAL_PcfDia_PosDebounce_f32 = 3.0F;/* Referenced by:
                                                          * '<S28>/CAL_PcfDia_PosDebounce_f32'
                                                          * '<S28>/CAL_PcfDia_PosDebounce_f321'
                                                          * '<S28>/CAL_PcfDia_PosDebounce_f322'
                                                          * '<S28>/CAL_PcfDia_PosDebounce_f323'
                                                          * '<S29>/CAL_PcfDia_PosDebounce_f32'
                                                          * '<S29>/CAL_PcfDia_PosDebounce_f321'
                                                          * '<S29>/CAL_PcfDia_PosDebounce_f322'
                                                          * '<S29>/CAL_PcfDia_PosDebounce_f323'
                                                          */

/* 位置传感器故障诊断Debounce次数 */
const volatile float32 CAL_PcfDia_PosHighset_f32 = 1.0F;
                          /* Referenced by: '<S30>/CAL_PcfDia_PosHighset_f32' */

/* 位置传感器传输值上限阈值 */
const volatile float32 CAL_PcfDia_PosLowset_f32 = 0.0F;
                           /* Referenced by: '<S30>/CAL_PcfDia_PosLowset_f32' */

/* 位置传感器传输值下限阈值 */
const volatile uint8 CAL_PcfDia_Retrytimes_u8 = 3U;
                           /* Referenced by: '<S64>/CAL_PcfDia_Retrytimes_u8' */

/* 堵转允许重试次数 */
const volatile float32 CAL_PcfDia_SLInPDown_f32 = 0.26F;
                           /* Referenced by: '<S22>/CAL_PcfDia_SLInPDown_f32' */

/* 正常入P位置下限 */
const volatile float32 CAL_PcfDia_SLInPLimt_f32 = 0.02F;
                           /* Referenced by: '<S22>/CAL_PcfDia_SLInPLimt_f32' */

/* 无位置信号阈值 */
const volatile float32 CAL_PcfDia_SLInPUp_f32 = 0.36F;
                             /* Referenced by: '<S22>/CAL_PcfDia_SLInPUp_f32' */

/* 正常入P位置上限 */
const volatile float32 CAL_PcfDia_SLOutPDown_f32 = 0.575F;
                          /* Referenced by: '<S22>/CAL_PcfDia_SLOutPDown_f32' */

/* 正常出P位置下限 */
const volatile float32 CAL_PcfDia_SLOutPInit_f32 = 0.8F;
                          /* Referenced by: '<S22>/CAL_PcfDia_SLOutPInit_f32' */

/* 执行器安装初始位置 */
const volatile float32 CAL_PcfDia_SLOutPUp_f32 = 0.675F;
                            /* Referenced by: '<S22>/CAL_PcfDia_SLOutPUp_f32' */

/* 正常出P位置上限 */
const volatile float32 CAL_PcfDia_SpdHiHyst_f32 = 4.5F;
                           /* Referenced by: '<S20>/CAL_PcfDia_SpdHiHyst_f32' */

/* 允许驻车车速上限滞环 */
const volatile float32 CAL_PcfDia_SpdHi_f32 = 5.0F;
                               /* Referenced by: '<S20>/CAL_PcfDia_SpdHi_f32' */

/* 允许驻车车速上限 */
const volatile float32 CAL_PcfDia_UdcCANLowSet_f32 = 6.0F;
                        /* Referenced by: '<S18>/CAL_PcfDia_UdcCANLowSet_f32' */

/* 电压设置值2欠压报警执行器停止工作只保持通讯 */
const volatile float32 CAL_PcfDia_UdcMotLowSet_f32 = 9.0F;
                        /* Referenced by: '<S18>/CAL_PcfDia_UdcMotLowSet_f32' */

/* 电压设置值1执行器不工作 */
const volatile float32 CAL_PcfDia_UdcMotManSet_f32 = 12.0F;
                        /* Referenced by: '<S18>/CAL_PcfDia_UdcMotManSet_f32' */

/* 电压设置值4执行器正常工作大于16V过压报警执行器工作 */
const volatile float32 CAL_PcfDia_UdcMotUVSet_f32 = 16.0F;
                         /* Referenced by: '<S18>/CAL_PcfDia_UdcMotUVSet_f32' */

/* 电压设置值3欠压报警执行器工作 */
const volatile float32 CAL_PcfDia_VDD5Debounce_f32 = 3.0F;/* Referenced by:
                                                           * '<S44>/CAL_PcfDia_VDD5Debounce_f1'
                                                           * '<S44>/CAL_PcfDia_VDD5Debounce_f2'
                                                           * '<S44>/CAL_PcfDia_VDD5Debounce_f3'
                                                           * '<S44>/CAL_PcfDia_VDD5Debounce_f32'
                                                           */

/* 位置传感器5V供电电压故障Debounce次数 */
const volatile float32 CAL_PcfDia_VDD5Highset_f32 = 5.2F;
                         /* Referenced by: '<S19>/CAL_PcfDia_VDD5Highset_f32' */

/* 位置传感器5V供电电压上限阈值 */
const volatile float32 CAL_PcfDia_VDD5Lowset_f32 = 4.8F;
                          /* Referenced by: '<S19>/CAL_EpcDia_VDD5Lowset_f32' */

/* 位置传感器5V供电电压下限阈值 */
const volatile uint16 CAL_PcfDia_cntNorAct_u16 = 60U;
                           /* Referenced by: '<S23>/CAL_PcfDia_cntNorAct_u16' */

/* 执行器出入P正常运行时间 */
const volatile uint16 CAL_PcfDia_cntOverAct_u16 = 100U;
                          /* Referenced by: '<S23>/CAL_PcfDia_cntOverAct_u16' */

/* 执行器出入P最大允许运行时间 */
const volatile boolean CAL_PcfDia_flgBCLockedSwt_b = 0;
                         /* Referenced by: '<S13>/CAL_PcfDia_flgBCstallSwt_b' */
const volatile boolean CAL_PcfDia_flgBCLocked_b = 0;
                            /* Referenced by: '<S13>/CAL_PcfDia_flgBCstall_b' */
const volatile boolean CAL_PcfDia_flgFaultSwt_b = 0;
                           /* Referenced by: '<S61>/CAL_PcfDia_flgFaultSwt_b' */

/* EPC故障状态标定量控制切换开关 */
const volatile boolean CAL_PcfDia_flgFault_b = 0;
                              /* Referenced by: '<S61>/CAL_PcfDia_flgFault_b' */

/* EPC故障状态标定量控制 */
const volatile boolean CAL_PcfDia_flgLocked_b = 0;
                             /* Referenced by: '<S15>/CAL_PcfDia_flgLocked_b' */
const volatile boolean CAL_PcfDia_flgLockedlSwt_b = 0;
                         /* Referenced by: '<S15>/CAL_PcfDia_flgLockedlSwt_b' */
const volatile boolean CAL_PcfDia_flgRetrySwt_b = 1;
                           /* Referenced by: '<S66>/CAL_PcfDia_flgRetrySwt_b' */

/* 堵转重试标定量控制切换开关 */
const volatile boolean CAL_PcfDia_flgRetry_b = 0;
                              /* Referenced by: '<S66>/CAL_PcfDia_flgRetry_b' */

/* 堵转重试标定量控制 */
const volatile float32 CAL_PcfDia_nMechHiHyst_f32 = 280.0F;
                         /* Referenced by: '<S20>/CAL_PcfDia_nMechHiHyst_f32' */

/* 用电机转速判断速度阈值上限滞环 */
const volatile float32 CAL_PcfDia_nMechHi_f32 = 300.0F;
                             /* Referenced by: '<S20>/CAL_PcfDia_nMechHi_f32' */

/* 用电机转速判断速度阈值上限 */
const volatile float32 CAL_PcfDia_nMotLockedLowHyst_f32 = 35.0F;
                   /* Referenced by: '<S15>/CAL_PcfDia_nMotLockedLowHyst_f32' */

/* 堵转转速高限滞环阈值 */
const volatile float32 CAL_PcfDia_nMotLockedLow_f32 = 30.0F;
                       /* Referenced by: '<S15>/CAL_PcfDia_nMotLockedLow_f32' */

/* 堵转转速高限阈值 */
const volatile float32 CAL_PcfDia_posSenHiRngSet_f32 = 0.05F;
                     /* Referenced by: '<S30>/CAL_EPcfDia_posSenHiRngSet_f32' */

/* 两路传感器Pos值运行最大误差范围 */
const volatile float32 CAL_PcfDia_tMosHighSet_f32 = 120.0F;
                         /* Referenced by: '<S24>/CAL_PcfDia_tMosHighSet_f32' */

/* MOS管温度上限值 */
const volatile float32 CAL_PcfDia_tMosLowSet_f32 = -50.0F;
                          /* Referenced by: '<S24>/CAL_PcfDia_tMosLowSet_f32' */

/* MOS管温度下限值 */
const volatile uint16 CAL_PcfDia_tMosNum_u16 = 6U;
                             /* Referenced by: '<S24>/CAL_PcfDia_tMosNum_u16' */

/* MOS管温度故障诊断次数 */
const volatile uint16 CAL_PcfDia_tRetry_u16 = 50U;
                              /* Referenced by: '<S64>/CAL_PcfDia_tRetry_u16' */

/* 堵转重试等待时间 */
const volatile float32 CAL_PcfSig_AimInPLimt_f32 = 0.31F;
                         /* Referenced by: '<S114>/CAL_PcfSig_AimInPLimt_f32' */

/* 入P极限位置标定量 */
const volatile float32 CAL_PcfSig_AngMotPos_f32 = 1.874F;
                          /* Referenced by: '<S116>/CAL_PcfSig_AngMotPos_f32' */

/* 有效运行区间占整圈比例 */
const volatile float32 CAL_PcfSig_GernMot_f32 = 222.18F;
                            /* Referenced by: '<S116>/CAL_PcfSig_GernMot_f32' */

/* 电机到输出端减速比 */
const volatile float32 CAL_PcfSig_IUBPcfFltCoe_f32 = 1.0F;
                       /* Referenced by: '<S108>/CAL_PcfSig_IUBEpcFltCoe_f32' */
const volatile float32 CAL_PcfSig_IUBSet_f32 = 0.0F;
                             /* Referenced by: '<S101>/CAL_PcfSig_IUBSet_f32' */

/* 给定电流值 */
const volatile float32 CAL_PcfSig_IdcDycX_Idc_af32[4] = { 1.0F, 1.0F, 1.0F, 1.0F
} ;                                   /* Referenced by: '<S113>/Idcdyc_Table' */

/* 电流限占空比查表 */
const volatile float32 CAL_PcfSig_IdcDycY_dyc_af32[4] = { 0.0F, 7.2F, 20.0F,
  50.0F } ;                           /* Referenced by: '<S113>/Idcdyc_Table' */

/* 电流限占空比阈值 */
const volatile float32 CAL_PcfSig_PosCnvFac_f32 = 0.000244F;/* Referenced by:
                                                             * '<S99>/CAL_PcfSig_Pos2CnvFac_f32'
                                                             * '<S100>/CAL_PcfSig_PosCnvFac_f32'
                                                             */

/* EPC执行器位置信号精度系数 */
const volatile float32 CAL_PcfSig_PosOffset_f32 = 0.0F;/* Referenced by:
                                                        * '<S99>/CAL_EpcSig_Pos2Offset_f32'
                                                        * '<S100>/CAL_PcfSig_PosOffset_f32'
                                                        */

/* EPC执行器位置信号偏移量系数 */
const volatile uint16 CAL_PcfSig_TimesTestP_u16 = 15U;
                           /* Referenced by: '<S93>/CAL_PcfSig_TimesTestP_u1' */

/* 出入P自动测试次数设置 */
const volatile float32 CAL_PcfSig_UdcDycX_Udc_af32[20] = { 1.0F, 1.0F, 1.0F,
  1.0F, 0.98F, 0.93F, 0.9F, 0.88F, 0.86F, 0.85F, 0.83F, 0.8F, 0.78F, 0.75F,
  0.73F, 0.7F, 0.7F, 0.7F, 0.6F, 0.5F } ;
                                      /* Referenced by: '<S113>/Udcdyc_Table' */

/* UKL30限占空比查表 */
const volatile float32 CAL_PcfSig_UdcDycY_dyc_af32[20] = { 0.0F, 6.0F, 8.5F,
  9.0F, 9.5F, 10.0F, 10.5F, 11.0F, 11.5F, 12.0F, 12.5F, 13.0F, 13.5F, 14.0F,
  14.5F, 15.0F, 15.5F, 16.0F, 16.5F, 20.0F } ;
                                      /* Referenced by: '<S113>/Udcdyc_Table' */

/* UKL30限占空比阈值 */
const volatile float32 CAL_PcfSig_VehSpd_f32 = 0.0F;
                              /* Referenced by: '<S89>/CAL_PcfSig_VehSpd_f32' */

/* 车速信号标定量给定 */
const volatile float32 CAL_PcfSig_deltaAimInP_f32 = 0.015F;
                        /* Referenced by: '<S114>/CAL_PcfSig_deltaAimInP_f32' */

/* 入P目标位置与极限位置的余量 */
const volatile float32 CAL_PcfSig_deltaAimOutP_f32 = 0.305F;
                       /* Referenced by: '<S114>/CAL_PcfSig_deltaAimOutP_f32' */

/* 出P位置到入P位置转动范围 */
const volatile float32 CAL_PcfSig_factMosFlt_f32 = 0.1F;
                         /* Referenced by: '<S107>/CAL_PcfSig_factMosFlt_f32' */

/* Mos管温度滤波系数 */
const volatile boolean CAL_PcfSig_flgACC_b = 0;
                                /* Referenced by: '<S89>/CAL_PcfSig_flgACC_b' */

/* 加速信号标定量给定 */
const volatile boolean CAL_PcfSig_flgAimInPLimtSwt_b = 1;
                     /* Referenced by: '<S114>/CAL_PcfSig_flgAimInPLimtSwt_b' */

/* 入P极限位置标定量控制切换开关 */
const volatile boolean CAL_PcfSig_flgBrakeSwt_b = 0;
                           /* Referenced by: '<S91>/CAL_PcfSig_flgBrakeSwt_b' */

/* 刹车信号标定量控制切换开关 */
const volatile uint8 CAL_PcfSig_flgBrake_u8 = 0U;
                             /* Referenced by: '<S91>/CAL_PcfSig_flgBrake_u8' */

/* 刹车信号标定量控制 */
const volatile boolean CAL_PcfSig_flgIUBSwt_b = 0;
                            /* Referenced by: '<S101>/CAL_PcfSig_flgIUBSwt_b' */

/* 切换使用给定电流值 */
const volatile boolean CAL_PcfSig_flgKL15Swt_b = 0;
                           /* Referenced by: '<S104>/CAL_PcfSig_flgKL15Swt_b' */

/* KL15信号标定量控制切换开关 */
const volatile boolean CAL_PcfSig_flgKL15_b = 0;
                              /* Referenced by: '<S104>/CAL_PcfSig_flgKL15_b' */

/* KL15信号标定量控制 */
const volatile boolean CAL_PcfSig_flgNVMSLFnhSwt_b = 1;
                       /* Referenced by: '<S115>/CAL_PcfSig_flgNVMSLFnhSwt_b' */

/* NVM输出自学习完成标志位标定量控制切换开关 */
const volatile boolean CAL_PcfSig_flgNVMSLFnh_b = 1;
                          /* Referenced by: '<S115>/CAL_PcfSig_flgNVMSLFnh_b' */

/* NVM输出自学习完成标志位标定量控制 */
const volatile boolean CAL_PcfSig_flgPSwt_b = 0;
                              /* Referenced by: '<S92>/CAL_EpcSig_flgPSwt_b1' */

/* 挡杆P信号标定量控制切换开关 */
const volatile boolean CAL_PcfSig_flgP_b = 0;
                                 /* Referenced by: '<S92>/CAL_PcfSig_flgP_b1' */

/* 挡杆P信号标定量控制 */
const volatile boolean CAL_PcfSig_flgPowerOnSwt_b = 1;
                        /* Referenced by: '<S105>/CAL_PcfSig_flgPowerOnSwt_b' */

/* EPC工作电路使能信号标定量控制切换开关 */
const volatile boolean CAL_PcfSig_flgPowerOn_b = 0;
                           /* Referenced by: '<S105>/CAL_PcfSig_flgPowerOn_b' */

/* EPC工作电路使能信号标定量控制 */
const volatile boolean CAL_PcfSig_flgTestPSwt_b = 0;
                          /* Referenced by: '<S93>/CAL_PcfSig_flgTestPSwt_b1' */

/* 出入P自动测试切换开关 */
const volatile boolean CAL_PcfSig_flgUseISENorIUB_b = 1;
                       /* Referenced by: '<S87>/CAL_PcfSig_flgUseISENorIUB_b' */
const volatile boolean CAL_PcfSig_flgstBeltSwt_b = 0;
                          /* Referenced by: '<S94>/CAL_PcfSig_flgstBeltSwt_b' */

/* 驾驶侧安全带信号标定量控制切换开关 */
const volatile boolean CAL_PcfSig_flgstDoorSwt_b = 0;
                          /* Referenced by: '<S95>/CAL_PcfSig_flgstDoorSwt_b' */

/* 驾驶侧门信号标定量控制切换开关 */
const volatile float32 CAL_PcfSig_iSENCnvFac_f32 = 0.01213F;
                         /* Referenced by: '<S106>/CAL_PcfSig_iSENCnvFac_f32' */

/* EPC工作电流AD转换系数 */
const volatile float32 CAL_PcfSig_iSENFltCoe_f32 = 1.0F;
                         /* Referenced by: '<S111>/CAL_PcfSig_iSENFltCoe_f32' */

/* EPC工作电流滤波系数 */
const volatile float32 CAL_PcfSig_nMotFltCoe_f32 = 0.5F;
                         /* Referenced by: '<S117>/CAL_PcfSig_nMotFltCoe_f32' */

/* 执行器电机转速滤波系数 */
const volatile uint8 CAL_PcfSig_stBelt_u8 = 0U;
                               /* Referenced by: '<S94>/CAL_PcfSig_stBelt_u8' */

/* 驾驶侧安全带信号标定量控制 */
const volatile uint8 CAL_PcfSig_stDoor_u8 = 0U;
                               /* Referenced by: '<S95>/CAL_PcfSig_stDoor_u8' */

/* 驾驶侧门信号标定量控制 */
const volatile float32 CAL_PcfSig_tDelayTestP_f32 = 2.0F;
                          /* Referenced by: '<S93>/CAL_PcfSig_tDelayTestP_f1' */

/* 出入P自动测试延迟时间 */
const volatile float32 CAL_PcfSig_tMosDycX_tMos_af32[6] = { 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F } ;              /* Referenced by: '<S113>/tMosdyc_Table1' */

/* Mos管温度限占空比查表 */
const volatile float32 CAL_PcfSig_tMosDycY_dyc_af32[6] = { -50.0F, -41.0F,
  -35.0F, 120.0F, 130.0F, 180.0F } ;/* Referenced by: '<S113>/tMosdyc_Table1' */

/* Mos管温度限占空比阈值 */
const volatile float32 CAL_PcfSig_tMosiSENcof_tCof_af32[10] = { 1.16F, 1.16F,
  1.16F, 1.15F, 1.15F, 1.15F, 1.12F, 1.1F, 1.1F, 1.08F } ;
                                  /* Referenced by: '<S110>/tMosIdcCof_Table' */

/* Mos管温度电流补偿系数查表 */
const volatile float32 CAL_PcfSig_tMosiSENcof_tMos_af32[10] = { -35.0F, -20.0F,
  -5.0F, 0.0F, 15.0F, 30.0F, 45.0F, 60.0F, 80.0F, 100.0F } ;
                                  /* Referenced by: '<S110>/tMosIdcCof_Table' */

/* Mos管温度电流补偿系数阈值 */
const volatile float32 CAL_PcfSig_tMosiSENofs_tCof_af32[10] = { 370.0F, 360.0F,
  350.0F, 335.0F, 320.0F, 310.0F, 300.0F, 285.0F, 275.0F, 265.0F } ;
                               /* Referenced by: '<S110>/tMosIdcOffset_Table' */

const volatile float32 CAL_PcfSig_tMosiSENofs_tMos_af32[10] = { -35.0F, -20.0F,
  -5.0F, 0.0F, 15.0F, 30.0F, 45.0F, 60.0F, 80.0F, 100.0F } ;
                               /* Referenced by: '<S110>/tMosIdcOffset_Table' */

/* EPC工作电流AD偏移系数 */
const volatile uint16 CAL_PcfStm_BCActimeLimt_u16 = 150U;
                       /* Referenced by: '<S119>/CAL_PcfStm_BCActimeLimt_u16' */

/* 盲控动作时间阈值 */
const volatile float32 CAL_PcfStm_SLAccSpdUp_f32 = 45.0F;
                         /* Referenced by: '<S119>/CAL_PcfStm_SLAccSpdUp_f32' */

/* 电机转动速度阈值 */
const volatile float32 CAL_PcfStm_SLAccTrqDes_f32 = 4.0F;
                        /* Referenced by: '<S119>/CAL_PcfStm_SLAccTrqDes_f32' */

/* 电机转动加速扭矩 */
const volatile float32 CAL_PcfStm_SLActRunSpdUp_f32 = 5.0F;
                         /* Referenced by: '<S119>/CAL_PcfStm_SLActRunUp_f32' */

/* 驻车执行器动作时最低电机速度阈值 */
const volatile uint16 CAL_PcfStm_SLActimeLimt_u16 = 150U;
                       /* Referenced by: '<S119>/CAL_PcfStm_SLActimeLimt_u16' */

/* 执行单次标定动作时间阈值 */
const volatile uint16 CAL_PcfStm_SLMotorAcctimeLimt_u16 = 300U;
                 /* Referenced by: '<S119>/CAL_PcfStm_SLMotorAcctimeLimt_u16' */

/* 位置标定时电机转动时间阈值 */
const volatile uint8 CAL_PcfStm_SLRetryTimesLimt_u8 = 4U;
                    /* Referenced by: '<S119>/CAL_PcfStm_SLRetryTimesLimt_u8' */

/* 执行器标定重试次数阈值 */
const volatile uint8 CAL_PcfStm_SLRunTimesLimt_u8 = 10U;
                      /* Referenced by: '<S119>/CAL_PcfStm_SLRunTimesLimt_u8' */

/* 执行器标定动作次数阈值 */
const volatile uint16 CAL_PcfStm_SLWaitimeLimt_u16 = 200U;
                      /* Referenced by: '<S119>/CAL_PcfStm_SLWaitimeLimt_u16' */

/* 电机转动结束后等待电机静止时间 */
const volatile uint16 CAL_PcfStm_cntSLWaitRunLimt_u16 = 150U;
                   /* Referenced by: '<S119>/CAL_PcfStm_cntSLWaitRunLimt_u16' */

/* 进入动作的等待时间 */
const volatile boolean CAL_PcfStm_flgTestPSwt_b = 0;
                          /* Referenced by: '<S133>/CAL_PcfStm_flgTestPSwt_b' */

/* 出入P自动测试切换开关 */
const volatile boolean CAL_PcfStm_flgUseAutoBackP_b = 0;
                      /* Referenced by: '<S119>/CAL_PcfStm_flgUseAutoBackP_b' */

/* 是否启用自动出入P功能 */
const volatile boolean CAL_PcfStm_flgUseBlindCtl_b = 0;
                       /* Referenced by: '<S119>/CAL_PcfStm_flgUseBlindCtl_b' */

/* 是否启用盲控功能 */
const volatile boolean CAL_PcfStm_flgUseFaultRec_b = 0;
                       /* Referenced by: '<S119>/CAL_PcfStm_flgUseFaultRec_b' */

/* 是否启用故障恢复功能 */
const volatile boolean CAL_PcfStm_flgUseRPC_b = 0;
                            /* Referenced by: '<S119>/CAL_PcfStm_flgUseRPC_b' */

/* 是否启用堵转重试功能 */
const volatile boolean CAL_PcfStm_flgUseSLC_b = 0;
                            /* Referenced by: '<S119>/CAL_PcfStm_flgUseSLC_b' */

/* 是否启用位置自学习功能 */
#pragma section

/* Block signals (default storage) */
B_SWC_PCF_T SWC_PCF_B;

/* Block states (default storage) */
DW_SWC_PCF_T SWC_PCF_DW;

/* Forward declaration for local functions */
static void SWC_PCF_enter_internal_Standby(void);
static sint32 safe_cast_to_iEDS_Enum_stEPPSm_(sint32 input);
static void SWC_PCF_NormalParkControl(void);
static void SWC_P_enter_internal_SLActJudge(void);
static void SWC_PCF_enter_internal_SLFault(void);
static void SWC_PCF_SelfLearnControl(void);
static void SWC_P_exit_internal_ParkControl(void);
static void SWC_PCF_enter_internal_Init(void);
static void SWC_PCF_ParkControl(const boolean *RelationalOperator1, const
  boolean *LogicalOperator2, const boolean *LogicalOperator1);

/*
 * Output and update for action system:
 *    '<S22>/If Action Subsystem'
 *    '<S23>/If Action Subsystem1'
 */
void SWC_PCF_IfActionSubsystem(uint8 *rty_Out1)
{
  /* SignalConversion generated from: '<S46>/Out1' incorporates:
   *  Constant: '<S46>/Constant'
   */
  *rty_Out1 = 1U;
}

/*
 * Output and update for action system:
 *    '<S22>/If Action Subsystem1'
 *    '<S23>/If Action Subsystem2'
 */
void SWC_PCF_IfActionSubsystem1(uint8 *rty_Out1)
{
  /* SignalConversion generated from: '<S47>/Out1' incorporates:
   *  Constant: '<S47>/Constant'
   */
  *rty_Out1 = 2U;
}

/* Function for Chart: '<S118>/PcfStm_State' */
static void SWC_PCF_enter_internal_Standby(void)
{
  VAR_PcfStm_enMos_b = false;
  VAR_PcfStm_Actime_u16 = 0U;
  VAR_PcfStm_SLstModeReq_u8 = 0U;
  VAR_PcfStm_SLenMos_b = false;
  VAR_PcfStm_SLflgPosNvm_b = false;
  VAR_PcfStm_SLPosReg_f32 = 0.0F;
  VAR_PcfStm_SLEnMotorAcc_b = false;
  VAR_PcfStm_SLtrqDes_f32 = 0.0F;
  VAR_PcfStm_BCenMos_b = false;
  VAR_PcfStm_BCflgModeReq_b = false;
  SWC_PCF_B.PcfStm_stPark = stPark_Standby;
  SWC_PCF_B.PcfStm_stParkCtl = stParkCtl_Halt;
}

static sint32 safe_cast_to_iEDS_Enum_stEPPSm_(sint32 input)
{
  sint32 y;

  /* Initialize output value to default value for iEDS_Enum_stEPPSm_def (stPark_Init) */
  y = 0;
  if ((input >= 0) && (input <= 28)) {
    /* Set output value to input value if it is a member of iEDS_Enum_stEPPSm_def */
    y = input;
  }

  return y;
}

/* Function for Chart: '<S118>/PcfStm_State' */
static void SWC_PCF_NormalParkControl(void)
{
  sint32 tmp;
  boolean guard1 = false;
  boolean guard2 = false;
  if (VAR_PcfStm_flgNPCToStandby_b) {
    SWC_PCF_DW.is_NormalParkControl = SWC_PCF_IN_NO_ACTIVE_CHILD;
    SWC_PCF_DW.is_ParkControl = SWC_PCF_IN_Standby;
    SWC_PCF_enter_internal_Standby();
  } else if (VAR_PcfStm_flgNPCToRPC_b) {
    SWC_PCF_DW.is_NormalParkControl = SWC_PCF_IN_NO_ACTIVE_CHILD;
    SWC_PCF_DW.is_ParkControl = SWC_PCF_IN_RetryParkControl;
    SWC_PCF_DW.is_RetryParkControl = SWC_PCF_IN_RCInit;
    VAR_PcfStm_enMos_b = false;
    SWC_PCF_DW.ReleaseEmcy = false;
    VAR_PcfStm_Actime_u16 = 0U;
    VAR_PcfStm_flgRetryFnh_b = false;
    SWC_PCF_DW.backstall = false;
    SWC_PCF_DW.Retry = false;
    SWC_PCF_B.PcfStm_stPark = stPark_RPCInit;
    SWC_PCF_B.PcfStm_stParkCtl = stParkCtl_Retry;
  } else {
    guard1 = false;
    guard2 = false;
    switch (SWC_PCF_DW.is_NormalParkControl) {
     case SWC_PCF_IN_PCInP:
      if ((VAR_PcfStm_flgPCInPtoRun_b && SWC_PCF_DW.RegflgP) ||
          VAR_PcfStm_flgEnAutoOutP_b) {
        VAR_PcfStm_flgAutoP_b = false;
        SWC_PCF_DW.dir = false;
        guard1 = true;
      } else {
        if (VAR_PcfSig_flgP_b) {
          VAR_PcfStm_flgAutoP_b = false;
          if (!VAR_PcfSig_flgP_b) {
            guard1 = true;
          }
        }
      }
      break;

     case SWC_PCF_IN_PCInit:
      if (VAR_PcfStm_flgPCInitToInP_b) {
        SWC_PCF_DW.is_NormalParkControl = SWC_PCF_IN_PCInP;
        VAR_PcfStm_enMos_b = false;
        SWC_PCF_DW.RegflgP = true;
        SWC_PCF_B.PcfStm_stPark = stPark_NPCInP;
      } else {
        if (VAR_PcfStm_flgPCInitToOutP_b) {
          SWC_PCF_DW.is_NormalParkControl = SWC_PCF_IN_PCOutP;
          VAR_PcfStm_enMos_b = false;
          SWC_PCF_DW.RegflgP = false;
          SWC_PCF_B.PcfStm_stPark = stPark_NPCOutP;
        }
      }
      break;

     case SWC_PCF_IN_PCOutP:
      if (VAR_PcfStm_flgEnAutoInP_b) {
        VAR_PcfStm_flgAutoP_b = true;
        SWC_PCF_DW.dir = true;
        guard2 = true;
      } else {
        if (VAR_PcfSig_flgP_b) {
          SWC_PCF_DW.dir = true;
          guard2 = true;
        }
      }
      break;

     default:
      /* case IN_PCRun: */
      tmp = VAR_PcfStm_Actime_u16 + 1;
      if (tmp > 65535) {
        tmp = 65535;
      }

      VAR_PcfStm_Actime_u16 = (uint16)tmp;

      /* UnitDelay: '<S7>/Unit Delay' */
      if (SWC_PCF_DW.UnitDelay_DSTATE_en && (!SWC_PCF_DW.RegflgP)) {
        SWC_PCF_DW.is_NormalParkControl = SWC_PCF_IN_PCInP;
        VAR_PcfStm_enMos_b = false;
        SWC_PCF_DW.RegflgP = true;
        SWC_PCF_B.PcfStm_stPark = stPark_NPCInP;
      } else {
        if (SWC_PCF_DW.UnitDelay_DSTATE_en && SWC_PCF_DW.RegflgP) {
          SWC_PCF_DW.is_NormalParkControl = SWC_PCF_IN_PCOutP;
          VAR_PcfStm_enMos_b = false;
          SWC_PCF_DW.RegflgP = false;
          SWC_PCF_B.PcfStm_stPark = stPark_NPCOutP;
        }
      }

      /* End of UnitDelay: '<S7>/Unit Delay' */
      break;
    }

    if (guard2) {
      SWC_PCF_DW.is_NormalParkControl = SWC_PCF_IN_PCRun;
      VAR_PcfStm_enMos_b = true;
      VAR_PcfStm_MotDir_b = SWC_PCF_DW.dir;
      VAR_PcfStm_Actime_u16 = 0U;
      SWC_PCF_B.PcfStm_stPark = stPark_NPCRun;
    }

    if (guard1) {
      SWC_PCF_DW.is_NormalParkControl = SWC_PCF_IN_PCRun;
      VAR_PcfStm_enMos_b = true;
      VAR_PcfStm_MotDir_b = SWC_PCF_DW.dir;
      VAR_PcfStm_Actime_u16 = 0U;
      SWC_PCF_B.PcfStm_stPark = stPark_NPCRun;
    }
  }
}

/* Function for Chart: '<S118>/PcfStm_State' */
static void SWC_P_enter_internal_SLActJudge(void)
{
  boolean guard1 = false;
  SWC_PCF_B.PcfStm_stPark = stPark_SLActJudge;
  SWC_PCF_DW.cntSLWaitRun = 0U;
  guard1 = false;
  if (SWC_PCF_DW.stPosHalt == 0) {
    if (VAR_PcfDia_stSLActPos_u8 == 7) {
      SWC_PCF_DW.SLDir = false;
      SWC_PCF_DW.stActJudge = 1U;
      VAR_PcfStm_SLstModeReq_u8 = 3U;
    } else if (VAR_PcfDia_stSLActPos_u8 != 7) {
      SWC_PCF_DW.SLDir = true;
      SWC_PCF_DW.stRetry = 2U;
      SWC_PCF_DW.stActJudge = 2U;
      VAR_PcfStm_SLstModeReq_u8 = 2U;
      SWC_PCF_DW.flgFnhorRetry = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    switch (SWC_PCF_DW.stPosHalt) {
     case 1:
      SWC_PCF_DW.SLDir = true;
      SWC_PCF_DW.stActJudge = 2U;
      VAR_PcfStm_SLstModeReq_u8 = 1U;
      SWC_PCF_DW.flgFnhorRetry = false;
      break;

     case 2:
      SWC_PCF_DW.SLDir = true;
      SWC_PCF_DW.stActJudge = 2U;
      VAR_PcfStm_SLstModeReq_u8 = 2U;
      SWC_PCF_DW.flgFnhorRetry = true;
      break;

     case 3:
      SWC_PCF_DW.SLDir = false;
      SWC_PCF_DW.stActJudge = 1U;
      VAR_PcfStm_SLstModeReq_u8 = 3U;
      break;
    }
  }
}

/* Function for Chart: '<S118>/PcfStm_State' */
static void SWC_PCF_enter_internal_SLFault(void)
{
  VAR_PcfStm_SLEnMotorAcc_b = false;
  VAR_PcfStm_SLtrqDes_f32 = 0.0F;
  VAR_PcfStm_SLenMos_b = false;
  VAR_PcfStm_SLstModeReq_u8 = 0U;
  SWC_PCF_DW.flgPosJudgeFnh = false;
  SWC_PCF_DW.SLActime = 0U;
  SWC_PCF_DW.stRetry = 0U;
  SWC_PCF_DW.SLMotorAcctime = 0U;
  SWC_PCF_DW.SLRunTimes = 0U;
  SWC_PCF_DW.SLWaitime = 0U;
  SWC_PCF_DW.SLRetryTimes = 0U;
  SWC_PCF_B.PcfStm_stPark = stPark_SLFault;
}

/* Function for Chart: '<S118>/PcfStm_State' */
static void SWC_PCF_SelfLearnControl(void)
{
  sint32 tmp;
  boolean guard1 = false;
  boolean guard2 = false;
  if (VAR_PcfStm_flgSLCToStandby_b) {
    SWC_PCF_DW.is_SelfLearnControl = SWC_PCF_IN_NO_ACTIVE_CHILD;
    SWC_PCF_DW.is_ParkControl = SWC_PCF_IN_Standby;
    SWC_PCF_enter_internal_Standby();
  } else {
    guard1 = false;
    guard2 = false;
    switch (SWC_PCF_DW.is_SelfLearnControl) {
     case SWC_PCF_IN_SLActJudge:
      if (VAR_PcfDia_stSLActPos_u8 == 1) {
        VAR_PcfStm_SLstDiag_u8 = 1U;
        SWC_PCF_DW.is_SelfLearnControl = SWC_PCF_IN_SLFault;
        SWC_PCF_enter_internal_SLFault();
      } else {
        tmp = SWC_PCF_DW.cntSLWaitRun + 1;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_PCF_DW.cntSLWaitRun = (uint16)tmp;

        /* Constant: '<S119>/CAL_PcfStm_cntSLWaitRunLimt_u16' */
        if ((SWC_PCF_DW.cntSLWaitRun > CAL_PcfStm_cntSLWaitRunLimt_u16) &&
            VAR_PcfStm_flgActJudgeToSLRun_b) {
          SWC_PCF_DW.is_SelfLearnControl = SWC_PCF_IN_SLRun;
          VAR_PcfStm_SLenMos_b = true;
          VAR_PcfStm_SLActDir_b = SWC_PCF_DW.SLDir;
          SWC_PCF_DW.SLActime = 0U;
          tmp = SWC_PCF_DW.SLRunTimes + 1;
          if (tmp > 255) {
            tmp = 255;
          }

          SWC_PCF_DW.SLRunTimes = (uint8)tmp;
          SWC_PCF_B.PcfStm_stPark = stPark_SLRun;
        }
      }
      break;

     case SWC_PCF_IN_SLFault:
     case SWC_PCF_IN_SLFnh:
      break;

     case SWC_PCF_IN_SLInit:
      SWC_PCF_DW.is_SelfLearnControl = SWC_PCF_IN_SLActJudge;
      SWC_P_enter_internal_SLActJudge();
      break;

     case SWC_PCF_IN_SLMotorAcc:
      tmp = SWC_PCF_DW.SLMotorAcctime + 1;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_PCF_DW.SLMotorAcctime = (uint16)tmp;

      /* Constant: '<S119>/CAL_PcfStm_SLMotorAcctimeLimt_u16' */
      if (SWC_PCF_DW.SLMotorAcctime > CAL_PcfStm_SLMotorAcctimeLimt_u16) {
        VAR_PcfStm_SLstDiag_u8 = 2U;
        SWC_PCF_DW.is_SelfLearnControl = SWC_PCF_IN_SLFault;
        SWC_PCF_enter_internal_SLFault();
      } else {
        if (VAR_PcfStm_flgSLAccToWait_b) {
          SWC_PCF_DW.is_SelfLearnControl = SWC_PCF_IN_SLWait;
          VAR_PcfStm_SLtrqDes_f32 = 0.0F;
          SWC_PCF_DW.SLWaitime = 0U;
          VAR_PcfStm_SLEnMotorAcc_b = false;
          SWC_PCF_B.PcfStm_stPark = stPark_SLWait;
        }
      }

      /* End of Constant: '<S119>/CAL_PcfStm_SLMotorAcctimeLimt_u16' */
      break;

     case SWC_PCF_IN_SLRetry:
      /* Constant: '<S119>/CAL_PcfStm_SLRetryTimesLimt_u8' */
      if (SWC_PCF_DW.SLRetryTimes >= CAL_PcfStm_SLRetryTimesLimt_u8) {
        VAR_PcfStm_SLstDiag_u8 = 6U;
        SWC_PCF_DW.is_SelfLearnControl = SWC_PCF_IN_SLFault;
        SWC_PCF_enter_internal_SLFault();
      } else if (SWC_PCF_DW.stRetry == 2) {
        SWC_PCF_DW.stPosHalt = 3U;
        SWC_PCF_DW.is_SelfLearnControl = SWC_PCF_IN_SLActJudge;
        SWC_P_enter_internal_SLActJudge();
      } else {
        tmp = SWC_PCF_DW.cntSLWaitAcc + 1;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_PCF_DW.cntSLWaitAcc = (uint16)tmp;

        /* Constant: '<S119>/CAL_PcfStm_cntSLWaitRunLimt_u16' */
        if ((SWC_PCF_DW.cntSLWaitAcc > CAL_PcfStm_cntSLWaitRunLimt_u16) &&
            (SWC_PCF_DW.stRetry == 1) && (VAR_PcfDia_stSLActPos_u8 == 7)) {
          SWC_PCF_DW.is_SelfLearnControl = SWC_PCF_IN_SLMotorAcc;

          /* Constant: '<S119>/CAL_PcfStm_SLAccTrqDes_f32' */
          VAR_PcfStm_SLtrqDes_f32 = CAL_PcfStm_SLAccTrqDes_f32;
          SWC_PCF_DW.SLMotorAcctime = 0U;
          VAR_PcfStm_SLEnMotorAcc_b = true;
          SWC_PCF_B.PcfStm_stPark = stPark_SLMotorAcc;
        }
      }

      /* End of Constant: '<S119>/CAL_PcfStm_SLRetryTimesLimt_u8' */
      break;

     case SWC_PCF_IN_SLRun:
      if (SWC_PCF_DW.SLRunTimes >= CAL_PcfStm_SLRunTimesLimt_u8) {
        VAR_PcfStm_SLstDiag_u8 = 3U;
        guard1 = true;
      } else {
        tmp = SWC_PCF_DW.SLActime + 1;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_PCF_DW.SLActime = (uint16)tmp;
        if (SWC_PCF_DW.SLActime > CAL_PcfStm_SLActimeLimt_u16) {
          VAR_PcfStm_SLstDiag_u8 = 4U;
          guard1 = true;
        } else if (VAR_PcfDia_flgLocked_b && (SWC_PCF_DW.stActJudge == 1)) {
          SWC_PCF_DW.flgPosJudgeFnh = false;
          SWC_PCF_DW.is_SelfLearnControl = SWC_PCF_IN_SLockedPosJudge;
          VAR_PcfStm_SLenMos_b = false;
          VAR_PcfStm_SLstModeReq_u8 = 0U;
          if (VAR_PcfDia_stSLActPos_u8 >= 4) {
            SWC_PCF_DW.stPosHalt = 2U;
            SWC_PCF_DW.stRetry = 2U;
            SWC_PCF_B.PcfStm_stPark = stPark_SLPosMid;
            SWC_PCF_DW.flgPosJudgeFnh = true;
          } else if (VAR_PcfDia_stSLActPos_u8 <= 2) {
            SWC_PCF_DW.stPosHalt = 2U;
            SWC_PCF_DW.stRetry = 1U;
            SWC_PCF_B.PcfStm_stPark = stPark_SLPosAlve;
            SWC_PCF_DW.flgPosJudgeFnh = true;
          } else {
            if (VAR_PcfDia_stSLActPos_u8 == 3) {
              VAR_PcfStm_SLPosReg_f32 = VAR_PcfSig_Pos1_f32;
              VAR_PcfStm_SLflgPosNvm_b = true;
              SWC_PCF_DW.stPosHalt = 1U;
              SWC_PCF_DW.stRetry = 0U;
              SWC_PCF_B.PcfStm_stPark = stPark_SLPosSuc;
              SWC_PCF_DW.flgPosJudgeFnh = true;
            }
          }
        } else {
          if (SWC_PCF_DW.UnitDelay_DSTATE_en && (SWC_PCF_DW.stActJudge == 2)) {
            if (SWC_PCF_DW.flgFnhorRetry) {
              if (VAR_PcfDia_stSLActPos_u8 != 7) {
                VAR_PcfStm_SLstDiag_u8 = 7U;
                guard1 = true;
              } else if (VAR_PcfDia_stSLActPos_u8 == 7) {
                SWC_PCF_DW.is_SelfLearnControl = SWC_PCF_IN_SLRetry;
                VAR_PcfStm_SLenMos_b = false;
                VAR_PcfStm_SLstModeReq_u8 = 0U;
                SWC_PCF_DW.cntSLWaitAcc = 0U;
                SWC_PCF_B.PcfStm_stPark = stPark_SLRetry;
                tmp = SWC_PCF_DW.SLRetryTimes + 1;
                if (tmp > 255) {
                  tmp = 255;
                }

                SWC_PCF_DW.SLRetryTimes = (uint8)tmp;
              } else {
                guard2 = true;
              }
            } else {
              guard2 = true;
            }
          }
        }
      }
      break;

     case SWC_PCF_IN_SLWait:
      tmp = SWC_PCF_DW.SLWaitime + 1;
      if (tmp > 65535) {
        tmp = 65535;
      }

      SWC_PCF_DW.SLWaitime = (uint16)tmp;

      /* Constant: '<S119>/CAL_PcfStm_SLWaitimeLimt_u16' */
      if (SWC_PCF_DW.SLWaitime > CAL_PcfStm_SLWaitimeLimt_u16) {
        SWC_PCF_DW.stPosHalt = 3U;
        SWC_PCF_DW.is_SelfLearnControl = SWC_PCF_IN_SLActJudge;
        SWC_P_enter_internal_SLActJudge();
      }

      /* End of Constant: '<S119>/CAL_PcfStm_SLWaitimeLimt_u16' */
      break;

     default:
      /* case IN_SLockedPosJudge: */
      if (SWC_PCF_DW.flgPosJudgeFnh) {
        SWC_PCF_DW.is_SelfLearnControl = SWC_PCF_IN_SLActJudge;
        SWC_P_enter_internal_SLActJudge();
      }
      break;
    }

    if (guard2) {
      if (!SWC_PCF_DW.flgFnhorRetry) {
        if (VAR_PcfDia_stSLActPos_u8 != 5) {
          VAR_PcfStm_SLstDiag_u8 = 5U;
          guard1 = true;
        } else {
          if (VAR_PcfDia_stSLActPos_u8 == 5) {
            SWC_PCF_DW.is_SelfLearnControl = SWC_PCF_IN_SLFnh;
            VAR_PcfStm_SLenMos_b = false;
            VAR_PcfStm_SLEnMotorAcc_b = false;
            VAR_PcfStm_SLstModeReq_u8 = 0U;
            SWC_PCF_B.PcfStm_stPark = stPark_SLFnh;
          }
        }
      }
    }

    if (guard1) {
      SWC_PCF_DW.is_SelfLearnControl = SWC_PCF_IN_SLFault;
      SWC_PCF_enter_internal_SLFault();
    }
  }
}

/* Function for Chart: '<S118>/PcfStm_State' */
static void SWC_P_exit_internal_ParkControl(void)
{
  SWC_PCF_DW.is_NormalParkControl = SWC_PCF_IN_NO_ACTIVE_CHILD;
  SWC_PCF_DW.is_RetryParkControl = SWC_PCF_IN_NO_ACTIVE_CHILD;
  SWC_PCF_DW.is_SelfLearnControl = SWC_PCF_IN_NO_ACTIVE_CHILD;
  SWC_PCF_DW.is_ParkControl = SWC_PCF_IN_NO_ACTIVE_CHILD;
}

/* Function for Chart: '<S118>/PcfStm_State' */
static void SWC_PCF_enter_internal_Init(void)
{
  VAR_PcfStm_enMos_b = false;
  VAR_PcfStm_Actime_u16 = 0U;
  VAR_PcfStm_SLstModeReq_u8 = 0U;
  VAR_PcfStm_SLenMos_b = false;
  VAR_PcfStm_SLstDiag_u8 = 0U;
  VAR_PcfStm_SLflgPosNvm_b = false;
  VAR_PcfStm_SLPosReg_f32 = 0.0F;
  VAR_PcfStm_SLEnMotorAcc_b = false;
  VAR_PcfStm_SLtrqDes_f32 = 0.0F;
  VAR_PcfStm_BCenMos_b = false;
  VAR_PcfStm_BCflgModeReq_b = false;
  VAR_PcfStm_BCstDiag_u8 = 0U;
  SWC_PCF_B.PcfStm_stPark = stPark_Init;
  SWC_PCF_B.PcfStm_stParkCtl = stParkCtl_Halt;
}

/* Function for Chart: '<S118>/PcfStm_State' */
static void SWC_PCF_ParkControl(const boolean *RelationalOperator1, const
  boolean *LogicalOperator2, const boolean *LogicalOperator1)
{
  sint32 tmp;
  boolean tmp_0;
  boolean guard1 = false;
  if (VAR_PcfDia_flgFault_b) {
    SWC_P_exit_internal_ParkControl();
    SWC_PCF_DW.is_c2_SWC_PCF = SWC_PCF_IN_Fault;
    VAR_PcfStm_enMos_b = false;
    VAR_PcfStm_SLenMos_b = false;
    VAR_PcfStm_BCenMos_b = false;
    VAR_PcfStm_SLEnMotorAcc_b = false;
    VAR_PcfStm_SLtrqDes_f32 = 0.0F;
    VAR_PcfStm_SLstModeReq_u8 = 0U;
    VAR_PcfStm_SLflgPosNvm_b = false;
    SWC_PCF_B.PcfStm_stPark = stPark_Fault;
    SWC_PCF_B.PcfStm_stParkCtl = stParkCtl_Halt;
  } else if (*RelationalOperator1) {
    SWC_P_exit_internal_ParkControl();
    SWC_PCF_DW.is_c2_SWC_PCF = SWC_PCF_IN_Init_g;
    SWC_PCF_enter_internal_Init();
  } else {
    guard1 = false;
    switch (SWC_PCF_DW.is_ParkControl) {
     case SWC_PCF_IN_NormalParkControl:
      SWC_PCF_NormalParkControl();
      break;

     case SWC_PCF_IN_RetryParkControl:
      if (SWC_PCF_DW.ReleaseEmcy) {
        SWC_PCF_DW.is_RetryParkControl = SWC_PCF_IN_NO_ACTIVE_CHILD;
        SWC_PCF_DW.is_ParkControl = SWC_PCF_IN_NormalParkControl;
        SWC_PCF_DW.is_NormalParkControl = SWC_PCF_IN_PCInit;
        VAR_PcfStm_enMos_b = false;
        VAR_PcfStm_flgAutoP_b = false;
        VAR_PcfStm_Actime_u16 = 0U;
        SWC_PCF_DW.ReleaseEmcy = false;
        SWC_PCF_B.PcfStm_stPark = stPark_NPCInit;
        SWC_PCF_B.PcfStm_stParkCtl = stParkCtl_Normal;
      } else {
        switch (SWC_PCF_DW.is_RetryParkControl) {
         case SWC_PCF_IN_RCInP:
          if (*LogicalOperator2) {
            SWC_PCF_DW.dir = false;
            SWC_PCF_DW.Retry = true;
            SWC_PCF_DW.is_RetryParkControl = SWC_PCF_IN_RCRun;
            VAR_PcfStm_enMos_b = true;
            VAR_PcfStm_MotDir_b = SWC_PCF_DW.dir;
            VAR_PcfStm_Actime_u16 = 0U;
            SWC_PCF_B.PcfStm_stPark = stPark_RPCRun;
          }
          break;

         case SWC_PCF_IN_RCInit:
          if (!VAR_PcfDia_flgstallPause_b) {
            if (*LogicalOperator1) {
              SWC_PCF_DW.dir = false;
              SWC_PCF_DW.backstall = true;
              guard1 = true;
            } else {
              if (*LogicalOperator2) {
                SWC_PCF_DW.dir = true;
                SWC_PCF_DW.backstall = true;
                guard1 = true;
              }
            }
          }
          break;

         case SWC_PCF_IN_RCOutP:
          if (*LogicalOperator1) {
            SWC_PCF_DW.dir = true;
            SWC_PCF_DW.Retry = true;
            SWC_PCF_DW.is_RetryParkControl = SWC_PCF_IN_RCRun;
            VAR_PcfStm_enMos_b = true;
            VAR_PcfStm_MotDir_b = SWC_PCF_DW.dir;
            VAR_PcfStm_Actime_u16 = 0U;
            SWC_PCF_B.PcfStm_stPark = stPark_RPCRun;
          }
          break;

         case SWC_PCF_IN_RCRun:
          if (VAR_PcfDia_flgstallPause_b) {
            SWC_PCF_DW.is_RetryParkControl = SWC_PCF_IN_RCInit;
            VAR_PcfStm_enMos_b = false;
            SWC_PCF_DW.ReleaseEmcy = false;
            VAR_PcfStm_Actime_u16 = 0U;
            VAR_PcfStm_flgRetryFnh_b = false;
            SWC_PCF_DW.backstall = false;
            SWC_PCF_DW.Retry = false;
            SWC_PCF_B.PcfStm_stPark = stPark_RPCInit;
            SWC_PCF_B.PcfStm_stParkCtl = stParkCtl_Retry;
          } else {
            tmp = VAR_PcfStm_Actime_u16 + 1;
            if (tmp > 65535) {
              tmp = 65535;
            }

            VAR_PcfStm_Actime_u16 = (uint16)tmp;

            /* UnitDelay: '<S7>/Unit Delay' */
            if (SWC_PCF_DW.UnitDelay_DSTATE_en) {
              tmp_0 = !SWC_PCF_DW.Retry;
              if ((!SWC_PCF_DW.dir) && tmp_0 && SWC_PCF_DW.backstall) {
                SWC_PCF_DW.is_RetryParkControl = SWC_PCF_IN_RCOutP;
                VAR_PcfStm_enMos_b = false;
                SWC_PCF_DW.backstall = false;
                SWC_PCF_DW.Retry = false;
                SWC_PCF_B.PcfStm_stPark = stPark_RPCOutP;
              } else if (SWC_PCF_DW.dir && tmp_0 && SWC_PCF_DW.backstall) {
                SWC_PCF_DW.is_RetryParkControl = SWC_PCF_IN_RCInP;
                VAR_PcfStm_enMos_b = false;
                SWC_PCF_DW.backstall = false;
                SWC_PCF_DW.Retry = false;
                SWC_PCF_B.PcfStm_stPark = stPark_RPCInP;
              } else {
                if (SWC_PCF_DW.Retry && (!SWC_PCF_DW.backstall)) {
                  SWC_PCF_DW.is_RetryParkControl = SWC_PCF_IN_RCSuccess;
                  VAR_PcfStm_enMos_b = false;
                  VAR_PcfStm_flgRetryFnh_b = true;
                  SWC_PCF_DW.ReleaseEmcy = true;
                  SWC_PCF_B.PcfStm_stPark = stPark_RPCSuc;
                }
              }
            }

            /* End of UnitDelay: '<S7>/Unit Delay' */
          }
          break;

         default:
          /* case IN_RCSuccess: */
          break;
        }
      }
      break;

     case SWC_PCF_IN_SelfLearnControl:
      SWC_PCF_SelfLearnControl();
      break;

     default:
      /* case IN_Standby: */
      if (VAR_PcfStm_flgStandbyToNPC_b) {
        SWC_PCF_DW.is_ParkControl = SWC_PCF_IN_NormalParkControl;
        SWC_PCF_DW.is_NormalParkControl = SWC_PCF_IN_PCInit;
        VAR_PcfStm_enMos_b = false;
        VAR_PcfStm_flgAutoP_b = false;
        VAR_PcfStm_Actime_u16 = 0U;
        SWC_PCF_DW.ReleaseEmcy = false;
        SWC_PCF_B.PcfStm_stPark = stPark_NPCInit;
        SWC_PCF_B.PcfStm_stParkCtl = stParkCtl_Normal;
      } else {
        if (VAR_PcfStm_flgStandbyToSLC_b) {
          SWC_PCF_DW.is_ParkControl = SWC_PCF_IN_SelfLearnControl;
          SWC_PCF_DW.is_SelfLearnControl = SWC_PCF_IN_SLInit;
          SWC_PCF_DW.stRetry = 0U;
          VAR_PcfStm_SLstDiag_u8 = 0U;
          SWC_PCF_DW.stPosHalt = 0U;
          VAR_PcfStm_SLenMos_b = false;
          VAR_PcfStm_SLstModeReq_u8 = 0U;
          SWC_PCF_DW.SLRetryTimes = 0U;
          SWC_PCF_DW.SLActime = 0U;
          SWC_PCF_DW.SLMotorAcctime = 0U;
          SWC_PCF_DW.SLWaitime = 0U;
          SWC_PCF_DW.SLRunTimes = 0U;
          VAR_PcfStm_SLtrqDes_f32 = 0.0F;
          VAR_PcfStm_SLEnMotorAcc_b = false;
          VAR_PcfStm_SLPosReg_f32 = 0.0F;
          VAR_PcfStm_SLflgPosNvm_b = false;
          SWC_PCF_DW.stActJudge = 0U;
          SWC_PCF_B.PcfStm_stPark = (iEDS_Enum_stEPPSm_def)
            safe_cast_to_iEDS_Enum_stEPPSm_((sint32)stParkCtl_SelfLearn);
          SWC_PCF_B.PcfStm_stParkCtl = stParkCtl_SelfLearn;
        }
      }
      break;
    }

    if (guard1) {
      SWC_PCF_DW.is_RetryParkControl = SWC_PCF_IN_RCRun;
      VAR_PcfStm_enMos_b = true;
      VAR_PcfStm_MotDir_b = SWC_PCF_DW.dir;
      VAR_PcfStm_Actime_u16 = 0U;
      SWC_PCF_B.PcfStm_stPark = stPark_RPCRun;
    }
  }
}

/* Model step function for TID1 */
void SWC_PCF_10ms(void)                /* Explicit Task: RE_SWC_PCF_10ms */
{
  /* local block i/o variables */
  boolean rtb_TmpSignalConversionAtRP_SWC;
  uint8 tmpRead;
  uint8 tmpRead_0;
  float32 tmpRead_1;
  float32 rtb_Switch;
  boolean rtb_enSelfcheck;
  uint8 rtb_Switch3_b;
  float32 rtb_Abs_i;
  boolean rtb_LogicalOperator_da;
  boolean rtb_RelationalOperator_k4;
  float32 rtb_CAL_PcfCtl_PosKp_f32;
  float32 rtb_Subtract_i;
  boolean rtb_ParkHard;
  uint8 rtb_Switch2_en;
  boolean RelationalOperator1;
  boolean LogicalOperator2;
  boolean LogicalOperator1;
  sint32 tmp;
  boolean VAR_PcfStm_flgStandbyToNPC_b_tm;
  boolean VAR_PcfStm_flgFaultToParkCtl_b_;

  /* Inport: '<Root>/RP_SWC_Epark_Epark_posPcf' */
  Rte_Read_RP_SWC_Epark_Epark_posPcf(&rtb_CAL_PcfCtl_PosKp_f32);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_PCF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_PCF_10ms_sys'
   */
  /* Product: '<S99>/Product' incorporates:
   *  Constant: '<S99>/CAL_EpcSig_Pos2Offset_f32'
   *  Constant: '<S99>/CAL_PcfSig_Pos2CnvFac_f32'
   *  Sum: '<S99>/Subtract'
   */
  VAR_PcfSig_Pos1_f32 = (rtb_CAL_PcfCtl_PosKp_f32 - CAL_PcfSig_PosOffset_f32) *
    CAL_PcfSig_PosCnvFac_f32;

  /* RelationalOperator: '<S96>/Relational Operator' incorporates:
   *  UnitDelay: '<S6>/Unit Delay'
   */
  rtb_enSelfcheck = (VAR_PcfStm_stPark_u8 == 5);

  /* Switch: '<S96>/Switch3' incorporates:
   *  Constant: '<S96>/OutPtoInP'
   *  RelationalOperator: '<S96>/Relational Operator1'
   *  Switch: '<S96>/Switch4'
   *  UnitDelay: '<S6>/Unit Delay'
   *  UnitDelay: '<S96>/Delay'
   */
  if (rtb_enSelfcheck) {
    SWC_PCF_DW.Delay_DSTATE = 1.0;
  } else {
    if (VAR_PcfStm_stPark_u8 == 6) {
      /* Switch: '<S96>/Switch4' incorporates:
       *  Constant: '<S96>/InPtoOutP'
       *  UnitDelay: '<S96>/Delay'
       */
      SWC_PCF_DW.Delay_DSTATE = 0.0;
    }
  }

  /* End of Switch: '<S96>/Switch3' */

  /* Switch: '<S98>/Switch3' incorporates:
   *  UnitDelay: '<S96>/Delay'
   */
  rtb_Switch3_b = (uint8)(SWC_PCF_DW.Delay_DSTATE != 0.0);

  /* Switch: '<S98>/Switch2' incorporates:
   *  Constant: '<S93>/CAL_PcfSig_tDelayTestP_f1'
   *  RelationalOperator: '<S98>/Relational Operator1'
   *  Saturate: '<S98>/Saturation'
   *  UnitDelay: '<S98>/Unit Delay1'
   *  UnitDelay: '<S98>/Unit Delay2'
   */
  if (rtb_Switch3_b != SWC_PCF_DW.UnitDelay2_DSTATE_b) {
    VAR_PcfSig_DycLim_f32 = CAL_PcfSig_tDelayTestP_f32;
  } else if (SWC_PCF_DW.UnitDelay1_DSTATE > 100.0F) {
    /* Saturate: '<S98>/Saturation' */
    VAR_PcfSig_DycLim_f32 = 100.0F;
  } else if (SWC_PCF_DW.UnitDelay1_DSTATE < -0.1F) {
    /* Saturate: '<S98>/Saturation' */
    VAR_PcfSig_DycLim_f32 = -0.1F;
  } else {
    /* Saturate: '<S98>/Saturation' incorporates:
     *  UnitDelay: '<S98>/Unit Delay1'
     */
    VAR_PcfSig_DycLim_f32 = SWC_PCF_DW.UnitDelay1_DSTATE;
  }

  /* End of Switch: '<S98>/Switch2' */

  /* Sum: '<S98>/Sum1' incorporates:
   *  Constant: '<S98>/step'
   *  UnitDelay: '<S98>/Unit Delay1'
   */
  SWC_PCF_DW.UnitDelay1_DSTATE = VAR_PcfSig_DycLim_f32 - 0.01F;

  /* Switch: '<S98>/Switch1' incorporates:
   *  Constant: '<S98>/substep'
   *  RelationalOperator: '<S98>/Relational Operator'
   *  UnitDelay: '<S96>/Delay'
   *  UnitDelay: '<S98>/Unit Delay1'
   *  UnitDelay: '<S98>/Unit Delay3'
   */
  if (SWC_PCF_DW.UnitDelay1_DSTATE <= -0.01F) {
    SWC_PCF_DW.UnitDelay3_DSTATE = SWC_PCF_DW.Delay_DSTATE;
  }

  /* End of Switch: '<S98>/Switch1' */

  /* Switch: '<S97>/Switch2' incorporates:
   *  UnitDelay: '<S98>/Unit Delay3'
   */
  rtb_Switch2_en = (uint8)(SWC_PCF_DW.UnitDelay3_DSTATE != 0.0);

  /* Switch: '<S97>/Switch1' incorporates:
   *  Constant: '<S93>/CAL_PcfSig_flgTestPSwt_b1'
   *  Constant: '<S97>/Constant1'
   */
  if (CAL_PcfSig_flgTestPSwt_b) {
    /* Switch: '<S97>/Switch3' incorporates:
     *  RelationalOperator: '<S97>/Relational Operator1'
     *  UnitDelay: '<S97>/Unit Delay2'
     */
    if (rtb_Switch2_en > SWC_PCF_DW.UnitDelay2_DSTATE_j) {
      /* Sum: '<S97>/Add' incorporates:
       *  Constant: '<S97>/Constant3'
       *  UnitDelay: '<S97>/Unit Delay'
       */
      SWC_PCF_DW.UnitDelay1_DSTATE_o = (uint16)(VAR_PcfSig_TestTimes_u16 + 1U);

      /* Switch: '<S97>/Switch6' incorporates:
       *  Constant: '<S97>/UpperLimit'
       *  RelationalOperator: '<S97>/Relational Operator5'
       */
      if (SWC_PCF_DW.UnitDelay1_DSTATE_o > 65500) {
        SWC_PCF_DW.UnitDelay1_DSTATE_o = 65500U;
      }

      /* End of Switch: '<S97>/Switch6' */
    }

    /* End of Switch: '<S97>/Switch3' */
    VAR_PcfSig_TestTimes_u16 = SWC_PCF_DW.UnitDelay1_DSTATE_o;
  } else {
    VAR_PcfSig_TestTimes_u16 = 0U;
  }

  /* End of Switch: '<S97>/Switch1' */

  /* SignalConversion generated from: '<S1>/RP_SWC_Com_Com_VCU06_Park_read' incorporates:
   *  Inport: '<Root>/RP_SWC_Com_Com_VCU06_Park'
   */
  Rte_Read_RP_SWC_Com_Com_VCU06_Park(&rtb_TmpSignalConversionAtRP_SWC);

  /* Switch: '<S92>/Switch' incorporates:
   *  Constant: '<S92>/CAL_EpcSig_flgPSwt_b1'
   *  Constant: '<S92>/CAL_PcfSig_flgP_b1'
   *  Constant: '<S93>/CAL_PcfSig_flgTestPSwt_b1'
   *  Switch: '<S93>/Switch5'
   */
  if (CAL_PcfSig_flgPSwt_b) {
    VAR_PcfSig_flgP_b = CAL_PcfSig_flgP_b;
  } else if (CAL_PcfSig_flgTestPSwt_b) {
    /* Switch: '<S93>/Switch6' incorporates:
     *  Constant: '<S93>/CAL_PcfSig_TimesTestP_u1'
     *  Logic: '<S97>/Logical Operator'
     *  RelationalOperator: '<S97>/Relational Operator2'
     *  Switch: '<S93>/Switch5'
     *  UnitDelay: '<S98>/Unit Delay3'
     */
    if (VAR_PcfSig_TestTimes_u16 < CAL_PcfSig_TimesTestP_u16) {
      VAR_PcfSig_flgP_b = (SWC_PCF_DW.UnitDelay3_DSTATE != 0.0);
    } else {
      VAR_PcfSig_flgP_b = rtb_TmpSignalConversionAtRP_SWC;
    }

    /* End of Switch: '<S93>/Switch6' */
  } else {
    /* Switch: '<S93>/Switch5' */
    VAR_PcfSig_flgP_b = rtb_TmpSignalConversionAtRP_SWC;
  }

  /* End of Switch: '<S92>/Switch' */

  /* If: '<S22>/If' incorporates:
   *  Constant: '<S22>/CAL_PcfDia_SLInPDown_f32'
   *  Constant: '<S22>/CAL_PcfDia_SLInPLimt_f32'
   *  Constant: '<S22>/CAL_PcfDia_SLInPUp_f32'
   *  Constant: '<S22>/CAL_PcfDia_SLOutPDown_f32'
   *  Constant: '<S22>/CAL_PcfDia_SLOutPInit_f32'
   *  Constant: '<S22>/CAL_PcfDia_SLOutPUp_f32'
   */
  if (VAR_PcfSig_Pos1_f32 <= CAL_PcfDia_SLInPLimt_f32) {
    /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem' incorporates:
     *  ActionPort: '<S46>/Action Port'
     */
    SWC_PCF_IfActionSubsystem(&VAR_PcfDia_stSLActPos_u8);

    /* End of Outputs for SubSystem: '<S22>/If Action Subsystem' */
  } else if (VAR_PcfSig_Pos1_f32 <= CAL_PcfDia_SLInPDown_f32) {
    /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S47>/Action Port'
     */
    SWC_PCF_IfActionSubsystem1(&VAR_PcfDia_stSLActPos_u8);

    /* End of Outputs for SubSystem: '<S22>/If Action Subsystem1' */
  } else if (VAR_PcfSig_Pos1_f32 <= CAL_PcfDia_SLInPUp_f32) {
    /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S49>/Action Port'
     */
    /* SignalConversion generated from: '<S49>/Out1' incorporates:
     *  Constant: '<S49>/Constant'
     */
    VAR_PcfDia_stSLActPos_u8 = 3U;

    /* End of Outputs for SubSystem: '<S22>/If Action Subsystem3' */
  } else if (VAR_PcfSig_Pos1_f32 <= CAL_PcfDia_SLOutPDown_f32) {
    /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S48>/Action Port'
     */
    /* SignalConversion generated from: '<S48>/Out1' incorporates:
     *  Constant: '<S48>/Constant'
     */
    VAR_PcfDia_stSLActPos_u8 = 4U;

    /* End of Outputs for SubSystem: '<S22>/If Action Subsystem2' */
  } else if (VAR_PcfSig_Pos1_f32 <= CAL_PcfDia_SLOutPUp_f32) {
    /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S50>/Action Port'
     */
    /* SignalConversion generated from: '<S50>/Out1' incorporates:
     *  Constant: '<S50>/Constant'
     */
    VAR_PcfDia_stSLActPos_u8 = 5U;

    /* End of Outputs for SubSystem: '<S22>/If Action Subsystem4' */
  } else if (VAR_PcfSig_Pos1_f32 <= CAL_PcfDia_SLOutPInit_f32) {
    /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S51>/Action Port'
     */
    /* SignalConversion generated from: '<S51>/Out1' incorporates:
     *  Constant: '<S51>/Constant'
     */
    VAR_PcfDia_stSLActPos_u8 = 6U;

    /* End of Outputs for SubSystem: '<S22>/If Action Subsystem5' */
  } else {
    /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S52>/Action Port'
     */
    /* SignalConversion generated from: '<S52>/Out1' incorporates:
     *  Constant: '<S52>/Constant'
     */
    VAR_PcfDia_stSLActPos_u8 = 7U;

    /* End of Outputs for SubSystem: '<S22>/If Action Subsystem6' */
  }

  /* End of If: '<S22>/If' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_PCF_10ms' */

  /* Inport: '<Root>/RP_SWC_HSPF_HSPF_nSlowFlt' */
  Rte_Read_RP_SWC_HSPF_HSPF_nSlowFlt(&rtb_Switch);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_PCF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_PCF_10ms_sys'
   */
  /* Abs: '<S121>/Abs' incorporates:
   *  Abs: '<S129>/Abs'
   *  Abs: '<S20>/Abs1'
   *  Sum: '<S88>/Add'
   */
  rtb_CAL_PcfCtl_PosKp_f32 = fabsf(rtb_Switch);
  rtb_Switch = rtb_CAL_PcfCtl_PosKp_f32;

  /* Logic: '<S121>/Logical Operator' incorporates:
   *  Abs: '<S121>/Abs'
   *  Constant: '<S119>/CAL_PcfStm_SLActRunUp_f32'
   *  Constant: '<S121>/Constant'
   *  RelationalOperator: '<S121>/Relational Operator'
   *  RelationalOperator: '<S121>/Relational Operator1'
   */
  VAR_PcfStm_flgActJudgeToSLRun_b = ((VAR_PcfDia_stSLActPos_u8 != 1) &&
    (rtb_CAL_PcfCtl_PosKp_f32 <= CAL_PcfStm_SLActRunSpdUp_f32));

  /* FunctionCaller: '<S1>/RP_SWC_IoHwAb_ADC_BSW_tEpc_IoHwAb_ADC_GetPhyVoltage' incorporates:
   *  Constant: '<S1>/Constant3'
   */
  Rte_Call_RP_SWC_IoHwAb_ADC_BSW_tEpc_IoHwAb_ADC_GetPhyVoltage(28, &rtb_Switch);

  /* LookupNDDirect: '<S107>/MotTemHig_Table' incorporates:
   *  Gain: '<S107>/ADotMos'
   *
   * About '<S107>/MotTemHig_Table':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  rtb_Switch *= 0.25F;
  if (rtb_Switch > 1023.0F) {
    rtb_Switch = 1023.0F;
  } else {
    if (rtb_Switch < 0.0F) {
      rtb_Switch = 0.0F;
    }
  }

  /* Sum: '<S112>/Add1' incorporates:
   *  Constant: '<S107>/CAL_PcfSig_factMosFlt_f32'
   *  Constant: '<S107>/CAL_PcfSig_tMosY_af32'
   *  Constant: '<S112>/Constant3'
   *  LookupNDDirect: '<S107>/MotTemHig_Table'
   *  Product: '<S112>/Product1'
   *  Product: '<S112>/Product2'
   *  Sum: '<S112>/Subtract'
   *
   * About '<S107>/MotTemHig_Table':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  VAR_PcfSig_tMosPcf_f32 = (1.0F - CAL_PcfSig_factMosFlt_f32) *
    VAR_PcfSig_tMosPcf_f32 + rtCP_CAL_PcfSig_tMosY_af32_Valu[(sint32)rtb_Switch]
    * CAL_PcfSig_factMosFlt_f32;

  /* Switch: '<S110>/Switch' incorporates:
   *  Constant: '<S110>/Constant'
   *  Lookup_n-D: '<S110>/tMosIdcOffset_Table'
   *  UnitDelay: '<S6>/Unit Delay1'
   */
  if (SWC_PCF_DW.UnitDelay1_DSTATE_l) {
    rtb_Switch = look1_iflf_binlxpw(VAR_PcfSig_tMosPcf_f32, ((const float32 *)
      &(CAL_PcfSig_tMosiSENofs_tMos_af32[0])), ((const float32 *)
      &(CAL_PcfSig_tMosiSENofs_tCof_af32[0])), 9U);
  } else {
    rtb_Switch = 0.0F;
  }

  /* End of Switch: '<S110>/Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_PCF_10ms' */

  /* Inport: '<Root>/RP_SWC_Epark_Epark_iPcf' */
  Rte_Read_RP_SWC_Epark_Epark_iPcf(&tmpRead_1);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_PCF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_PCF_10ms_sys'
   */
  /* Product: '<S106>/Product' incorporates:
   *  Constant: '<S106>/CAL_PcfSig_iSENCnvFac_f32'
   *  Sum: '<S106>/Subtract'
   */
  VAR_PcfSig_IsenPcf_f32 = (tmpRead_1 - rtb_Switch) * CAL_PcfSig_iSENCnvFac_f32;

  /* Sum: '<S111>/Add1' incorporates:
   *  Constant: '<S111>/CAL_PcfSig_iSENFltCoe_f32'
   *  Constant: '<S111>/Constant3'
   *  Lookup_n-D: '<S110>/tMosIdcCof_Table'
   *  Product: '<S109>/Product'
   *  Product: '<S111>/Product1'
   *  Product: '<S111>/Product2'
   *  Sum: '<S111>/Subtract'
   */
  VAR_PcfSig_IsentMosPcf_f32 = look1_iflf_binlxpw(VAR_PcfSig_tMosPcf_f32, ((
    const float32 *)&(CAL_PcfSig_tMosiSENcof_tMos_af32[0])), ((const float32 *)
    &(CAL_PcfSig_tMosiSENcof_tCof_af32[0])), 9U) * VAR_PcfSig_IsenPcf_f32 *
    CAL_PcfSig_iSENFltCoe_f32 + (1.0F - CAL_PcfSig_iSENFltCoe_f32) *
    VAR_PcfSig_IsentMosPcf_f32;

  /* FunctionCaller: '<S1>/RP_SWC_IoHwAb_ADC_BSW_IUBPCF_IoHwAb_ADC_GetPhyVoltage' incorporates:
   *  Constant: '<S1>/Constant7'
   */
  Rte_Call_RP_SWC_IoHwAb_ADC_BSW_IUBPCF_IoHwAb_ADC_GetPhyVoltage(5, &rtb_Switch);

  /* Switch: '<S101>/Switch' incorporates:
   *  Constant: '<S101>/CAL_PcfSig_IUBSet_f32'
   *  Constant: '<S101>/CAL_PcfSig_flgIUBSwt_b'
   */
  if (CAL_PcfSig_flgIUBSwt_b) {
    rtb_Switch = CAL_PcfSig_IUBSet_f32;
  }

  /* End of Switch: '<S101>/Switch' */

  /* Sum: '<S108>/Add1' incorporates:
   *  Constant: '<S108>/CAL_PcfSig_IUBEpcFltCoe_f32'
   *  Constant: '<S108>/Constant3'
   *  Product: '<S108>/Product1'
   *  Product: '<S108>/Product2'
   *  Sum: '<S108>/Subtract'
   */
  VAR_PcfSig_IUBPcf_f32 = (1.0F - CAL_PcfSig_IUBPcfFltCoe_f32) *
    VAR_PcfSig_IUBPcf_f32 + rtb_Switch * CAL_PcfSig_IUBPcfFltCoe_f32;

  /* Switch: '<S87>/Switch' incorporates:
   *  Constant: '<S87>/CAL_PcfSig_flgUseISENorIUB_b'
   */
  if (CAL_PcfSig_flgUseISENorIUB_b) {
    VAR_PcfSig_IdcPcf_f32 = VAR_PcfSig_IsentMosPcf_f32;
  } else {
    VAR_PcfSig_IdcPcf_f32 = VAR_PcfSig_IUBPcf_f32;
  }

  /* End of Switch: '<S87>/Switch' */

  /* Abs: '<S13>/Abs' incorporates:
   *  Abs: '<S15>/Abs'
   */
  rtb_Switch = fabsf(VAR_PcfSig_IdcPcf_f32);

  /* Switch: '<S13>/Switch7' incorporates:
   *  Abs: '<S13>/Abs'
   *  Constant: '<S13>/CAL_PcfDia_IdcLockedHiHyst_f32'
   *  Constant: '<S13>/CAL_PcfDia_IdcLockedHi_f32'
   *  Constant: '<S13>/Constant6'
   *  RelationalOperator: '<S13>/Relational Operator1'
   *  RelationalOperator: '<S13>/Relational Operator7'
   *  UnitDelay: '<S13>/Unit Delay1'
   */
  if (rtb_Switch >= CAL_PcfDia_IdcLockedHi_f32) {
    SWC_PCF_DW.UnitDelay1_DSTATE_gw = true;
  } else {
    SWC_PCF_DW.UnitDelay1_DSTATE_gw = ((rtb_Switch >
      CAL_PcfDia_IdcLockedHiHyst_f32) && SWC_PCF_DW.UnitDelay1_DSTATE_gw);
  }

  /* End of Switch: '<S13>/Switch7' */

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S13>/Constant2'
   *  UnitDelay: '<S13>/Unit Delay'
   *  UnitDelay: '<S13>/Unit Delay1'
   */
  if (SWC_PCF_DW.UnitDelay1_DSTATE_gw) {
    /* Sum: '<S13>/Add' incorporates:
     *  Constant: '<S13>/Constant3'
     *  UnitDelay: '<S13>/Unit Delay'
     */
    SWC_PCF_DW.UnitDelay_DSTATE_es++;

    /* Switch: '<S13>/Switch6' incorporates:
     *  Constant: '<S13>/Constant12'
     *  RelationalOperator: '<S13>/Relational Operator5'
     *  UnitDelay: '<S13>/Unit Delay'
     */
    if (SWC_PCF_DW.UnitDelay_DSTATE_es > 65500) {
      SWC_PCF_DW.UnitDelay_DSTATE_es = 65500U;
    }

    /* End of Switch: '<S13>/Switch6' */
  } else {
    SWC_PCF_DW.UnitDelay_DSTATE_es = 0U;
  }

  /* End of Switch: '<S13>/Switch' */

  /* Switch: '<S13>/Switch12' incorporates:
   *  Constant: '<S13>/CAL_PcfDia_BCLockedNum_u16'
   *  Constant: '<S13>/CAL_PcfDia_flgBCstallSwt_b'
   *  Constant: '<S13>/CAL_PcfDia_flgBCstall_b'
   *  RelationalOperator: '<S13>/Relational Operator2'
   *  UnitDelay: '<S13>/Unit Delay'
   */
  if (CAL_PcfDia_flgBCLockedSwt_b) {
    VAR_PcfDia_flgBCLocked_b = CAL_PcfDia_flgBCLocked_b;
  } else {
    VAR_PcfDia_flgBCLocked_b = (SWC_PCF_DW.UnitDelay_DSTATE_es >=
      CAL_PcfDia_BCLockedNum_u16);
  }

  /* End of Switch: '<S13>/Switch12' */

  /* FunctionCaller: '<S1>/RP_SWC_IoHwAb_DIO_Get_BSW_flgPcfOc_IoHwAb_DIO_Get' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  Rte_Call_RP_SWC_IoHwAb_DIO_Get_BSW_flgPcfOc_IoHwAb_DIO_Get(3,
    &VAR_PcfSig_flgIoc_b);

  /* Saturate: '<S14>/Saturation' incorporates:
   *  Logic: '<S87>/Logical Operator'
   *  Sum: '<S14>/Add'
   *  UnitDelay: '<S14>/Unit Delay'
   */
  if ((uint8)((uint32)VAR_PcfSig_flgIoc_b + SWC_PCF_DW.UnitDelay_DSTATE_lu) < 1)
  {
    SWC_PCF_DW.UnitDelay_DSTATE_lu = 0U;
  } else {
    SWC_PCF_DW.UnitDelay_DSTATE_lu = 1U;
  }

  /* End of Saturate: '<S14>/Saturation' */

  /* DataTypeConversion: '<S14>/Data Type Conversion1' incorporates:
   *  UnitDelay: '<S14>/Unit Delay'
   */
  VAR_PcfDia_flgHwIdcOv_b = (SWC_PCF_DW.UnitDelay_DSTATE_lu != 0);

  /* Switch: '<S28>/Switch2' incorporates:
   *  Constant: '<S28>/CAL_PcfDia_PosDebounce_f321'
   *  Constant: '<S28>/Constant7'
   *  Constant: '<S30>/CAL_PcfDia_PosHighset_f32'
   *  Constant: '<S30>/CAL_PcfDia_PosLowset_f32'
   *  Gain: '<S28>/Gain1'
   *  Logic: '<S30>/Logical Operator1'
   *  RelationalOperator: '<S28>/Relational Operator'
   *  RelationalOperator: '<S30>/Relational Operator'
   *  RelationalOperator: '<S30>/Relational Operator1'
   *  Sum: '<S28>/Subtract'
   *  Switch: '<S28>/Switch3'
   *  UnitDelay: '<S28>/Unit Delay1'
   */
  if ((VAR_PcfSig_Pos1_f32 > CAL_PcfDia_PosHighset_f32) || (VAR_PcfSig_Pos1_f32 <
       CAL_PcfDia_PosLowset_f32)) {
    /* Switch: '<S28>/Switch4' incorporates:
     *  Constant: '<S28>/CAL_PcfDia_PosDebounce_f32'
     *  Constant: '<S28>/Constant6'
     *  RelationalOperator: '<S28>/Relational Operator1'
     *  Sum: '<S28>/Add1'
     *  UnitDelay: '<S28>/Unit Delay'
     *  UnitDelay: '<S28>/Unit Delay1'
     */
    if (SWC_PCF_DW.UnitDelay_DSTATE_l + 1.0F <= CAL_PcfDia_PosDebounce_f32) {
      SWC_PCF_DW.UnitDelay1_DSTATE_g = SWC_PCF_DW.UnitDelay_DSTATE_l + 1.0F;
    } else {
      SWC_PCF_DW.UnitDelay1_DSTATE_g = CAL_PcfDia_PosDebounce_f32;
    }

    /* End of Switch: '<S28>/Switch4' */
  } else if (SWC_PCF_DW.UnitDelay1_DSTATE_g - 1.0F >=
             -CAL_PcfDia_PosDebounce_f32) {
    /* Switch: '<S28>/Switch3' incorporates:
     *  Constant: '<S28>/Constant7'
     *  Sum: '<S28>/Subtract'
     *  UnitDelay: '<S28>/Unit Delay1'
     */
    SWC_PCF_DW.UnitDelay1_DSTATE_g--;
  } else {
    SWC_PCF_DW.UnitDelay1_DSTATE_g = -CAL_PcfDia_PosDebounce_f32;
  }

  /* End of Switch: '<S28>/Switch2' */

  /* Switch: '<S28>/Switch5' incorporates:
   *  Constant: '<S28>/CAL_PcfDia_PosDebounce_f322'
   *  Constant: '<S28>/CAL_PcfDia_PosDebounce_f323'
   *  Constant: '<S28>/Constant11'
   *  Gain: '<S28>/Gain2'
   *  RelationalOperator: '<S28>/Relational Operator2'
   *  RelationalOperator: '<S28>/Relational Operator3'
   *  UnitDelay: '<S28>/Unit Delay1'
   *  UnitDelay: '<S28>/Unit Delay2'
   */
  if (SWC_PCF_DW.UnitDelay1_DSTATE_g >= CAL_PcfDia_PosDebounce_f32) {
    SWC_PCF_DW.UnitDelay2_DSTATE_n = true;
  } else {
    SWC_PCF_DW.UnitDelay2_DSTATE_n = ((SWC_PCF_DW.UnitDelay1_DSTATE_g >
      -CAL_PcfDia_PosDebounce_f32) && SWC_PCF_DW.UnitDelay2_DSTATE_n);
  }

  /* End of Switch: '<S28>/Switch5' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_PCF_10ms' */

  /* Inport: '<Root>/RP_SWC_Epark_Epark_posPcfMon' */
  Rte_Read_RP_SWC_Epark_Epark_posPcfMon(&rtb_Abs_i);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_PCF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_PCF_10ms_sys'
   */
  /* Saturate: '<S32>/Saturation' incorporates:
   *  Sum: '<S32>/Add'
   *  Switch: '<S32>/Switch'
   *  UnitDelay: '<S28>/Unit Delay2'
   *  UnitDelay: '<S32>/Unit Delay'
   */
  if ((uint8)((uint32)SWC_PCF_DW.UnitDelay2_DSTATE_n +
              SWC_PCF_DW.UnitDelay_DSTATE_c0) < 1) {
    SWC_PCF_DW.UnitDelay_DSTATE_c0 = 0U;
  } else {
    SWC_PCF_DW.UnitDelay_DSTATE_c0 = 1U;
  }

  /* End of Saturate: '<S32>/Saturation' */

  /* DataTypeConversion: '<S32>/Data Type Conversion1' incorporates:
   *  UnitDelay: '<S32>/Unit Delay'
   */
  VAR_PcfDia_flgSenOv_b = (SWC_PCF_DW.UnitDelay_DSTATE_c0 != 0);

  /* Product: '<S100>/Product' incorporates:
   *  Constant: '<S100>/CAL_PcfSig_PosCnvFac_f32'
   *  Constant: '<S100>/CAL_PcfSig_PosOffset_f32'
   *  Sum: '<S100>/Subtract'
   */
  VAR_PcfSig_Pos2_f32 = (rtb_Abs_i - CAL_PcfSig_PosOffset_f32) *
    CAL_PcfSig_PosCnvFac_f32;

  /* Switch: '<S29>/Switch2' incorporates:
   *  Abs: '<S30>/Abs'
   *  Constant: '<S29>/CAL_PcfDia_PosDebounce_f321'
   *  Constant: '<S29>/Constant7'
   *  Constant: '<S30>/CAL_EPcfDia_posSenHiRngSet_f32'
   *  Gain: '<S29>/Gain1'
   *  RelationalOperator: '<S29>/Relational Operator'
   *  RelationalOperator: '<S30>/Relational Operator2'
   *  Sum: '<S29>/Subtract'
   *  Sum: '<S30>/Add'
   *  Switch: '<S29>/Switch3'
   *  UnitDelay: '<S29>/Unit Delay1'
   */
  if (fabsf(VAR_PcfSig_Pos1_f32 - VAR_PcfSig_Pos2_f32) >=
      CAL_PcfDia_posSenHiRngSet_f32) {
    /* Switch: '<S29>/Switch4' incorporates:
     *  Constant: '<S29>/CAL_PcfDia_PosDebounce_f32'
     *  Constant: '<S29>/Constant6'
     *  RelationalOperator: '<S29>/Relational Operator1'
     *  Sum: '<S29>/Add1'
     *  UnitDelay: '<S29>/Unit Delay'
     *  UnitDelay: '<S29>/Unit Delay1'
     */
    if (SWC_PCF_DW.UnitDelay_DSTATE_e + 1.0F <= CAL_PcfDia_PosDebounce_f32) {
      SWC_PCF_DW.UnitDelay1_DSTATE_i = SWC_PCF_DW.UnitDelay_DSTATE_e + 1.0F;
    } else {
      SWC_PCF_DW.UnitDelay1_DSTATE_i = CAL_PcfDia_PosDebounce_f32;
    }

    /* End of Switch: '<S29>/Switch4' */
  } else if (SWC_PCF_DW.UnitDelay1_DSTATE_i - 1.0F >=
             -CAL_PcfDia_PosDebounce_f32) {
    /* Switch: '<S29>/Switch3' incorporates:
     *  Constant: '<S29>/Constant7'
     *  Sum: '<S29>/Subtract'
     *  UnitDelay: '<S29>/Unit Delay1'
     */
    SWC_PCF_DW.UnitDelay1_DSTATE_i--;
  } else {
    SWC_PCF_DW.UnitDelay1_DSTATE_i = -CAL_PcfDia_PosDebounce_f32;
  }

  /* End of Switch: '<S29>/Switch2' */

  /* Switch: '<S29>/Switch5' incorporates:
   *  Constant: '<S29>/CAL_PcfDia_PosDebounce_f322'
   *  Constant: '<S29>/CAL_PcfDia_PosDebounce_f323'
   *  Constant: '<S29>/Constant11'
   *  Gain: '<S29>/Gain2'
   *  RelationalOperator: '<S29>/Relational Operator2'
   *  RelationalOperator: '<S29>/Relational Operator3'
   *  UnitDelay: '<S29>/Unit Delay1'
   *  UnitDelay: '<S29>/Unit Delay2'
   */
  if (SWC_PCF_DW.UnitDelay1_DSTATE_i >= CAL_PcfDia_PosDebounce_f32) {
    SWC_PCF_DW.UnitDelay2_DSTATE_c = true;
  } else {
    SWC_PCF_DW.UnitDelay2_DSTATE_c = ((SWC_PCF_DW.UnitDelay1_DSTATE_i >
      -CAL_PcfDia_PosDebounce_f32) && SWC_PCF_DW.UnitDelay2_DSTATE_c);
  }

  /* End of Switch: '<S29>/Switch5' */

  /* Saturate: '<S31>/Saturation' incorporates:
   *  Sum: '<S31>/Add'
   *  Switch: '<S31>/Switch'
   *  UnitDelay: '<S29>/Unit Delay2'
   *  UnitDelay: '<S31>/Unit Delay'
   */
  if ((uint8)((uint32)SWC_PCF_DW.UnitDelay2_DSTATE_c +
              SWC_PCF_DW.UnitDelay_DSTATE_n5) < 1) {
    SWC_PCF_DW.UnitDelay_DSTATE_n5 = 0U;
  } else {
    SWC_PCF_DW.UnitDelay_DSTATE_n5 = 1U;
  }

  /* End of Saturate: '<S31>/Saturation' */

  /* DataTypeConversion: '<S31>/Data Type Conversion1' incorporates:
   *  UnitDelay: '<S31>/Unit Delay'
   */
  VAR_PcfDia_flgSenVerFail_b = (SWC_PCF_DW.UnitDelay_DSTATE_n5 != 0);

  /* Logic: '<S122>/Logical Operator10' incorporates:
   *  Constant: '<S119>/CAL_PcfStm_flgUseBlindCtl_b'
   *  Logic: '<S122>/Logical Operator11'
   *  RelationalOperator: '<S122>/Relational Operator1'
   *  RelationalOperator: '<S122>/Relational Operator15'
   *  RelationalOperator: '<S122>/Relational Operator16'
   */
  VAR_PcfStm_flgBPCToFault_b = (VAR_PcfDia_flgHwIdcOv_b ||
    (!CAL_PcfStm_flgUseBlindCtl_b) || ((!VAR_PcfDia_flgSenOv_b) &&
    (!VAR_PcfDia_flgSenVerFail_b)));

  /* FunctionCaller: '<S1>/RP_SWC_IoHwAb_DIO_Get_BSW_bt15_IoHwAb_DIO_Get' incorporates:
   *  Constant: '<S1>/Constant5'
   */
  Rte_Call_RP_SWC_IoHwAb_DIO_Get_BSW_bt15_IoHwAb_DIO_Get(341, &rtb_enSelfcheck);

  /* Switch: '<S104>/Switch' incorporates:
   *  Constant: '<S104>/CAL_PcfSig_flgKL15Swt_b'
   *  Constant: '<S104>/CAL_PcfSig_flgKL15_b'
   */
  if (CAL_PcfSig_flgKL15Swt_b) {
    VAR_PcfSig_flgKL15_b = CAL_PcfSig_flgKL15_b;
  } else {
    VAR_PcfSig_flgKL15_b = rtb_enSelfcheck;
  }

  /* End of Switch: '<S104>/Switch' */

  /* Constant: '<S89>/CAL_PcfSig_VehSpd_f32' */
  VAR_PcfSig_VehSpd_f32 = CAL_PcfSig_VehSpd_f32;

  /* Abs: '<S20>/Abs' */
  rtb_Abs_i = fabsf(VAR_PcfSig_VehSpd_f32);

  /* Switch: '<S20>/Switch' incorporates:
   *  Constant: '<S20>/CAL_PcfDia_SpdHiHyst_f32'
   *  Constant: '<S20>/CAL_PcfDia_SpdHi_f32'
   *  Constant: '<S20>/Constant5'
   *  RelationalOperator: '<S20>/Relational Operator'
   *  RelationalOperator: '<S20>/Relational Operator1'
   *  UnitDelay: '<S20>/Unit Delay2'
   */
  if (rtb_Abs_i >= CAL_PcfDia_SpdHi_f32) {
    SWC_PCF_DW.UnitDelay2_DSTATE_e = true;
  } else {
    SWC_PCF_DW.UnitDelay2_DSTATE_e = ((rtb_Abs_i > CAL_PcfDia_SpdHiHyst_f32) &&
      SWC_PCF_DW.UnitDelay2_DSTATE_e);
  }

  /* End of Switch: '<S20>/Switch' */

  /* Switch: '<S20>/Switch2' incorporates:
   *  Constant: '<S20>/CAL_PcfDia_nMechHiHyst_f32'
   *  Constant: '<S20>/CAL_PcfDia_nMechHi_f32'
   *  Constant: '<S20>/Constant2'
   *  RelationalOperator: '<S20>/Relational Operator2'
   *  RelationalOperator: '<S20>/Relational Operator3'
   *  UnitDelay: '<S20>/Unit Delay1'
   */
  if (rtb_CAL_PcfCtl_PosKp_f32 >= CAL_PcfDia_nMechHi_f32) {
    SWC_PCF_DW.UnitDelay1_DSTATE_ld = true;
  } else {
    SWC_PCF_DW.UnitDelay1_DSTATE_ld = ((rtb_CAL_PcfCtl_PosKp_f32 >
      CAL_PcfDia_nMechHiHyst_f32) && SWC_PCF_DW.UnitDelay1_DSTATE_ld);
  }

  /* End of Switch: '<S20>/Switch2' */

  /* Logic: '<S20>/Logical Operator' incorporates:
   *  UnitDelay: '<S20>/Unit Delay1'
   *  UnitDelay: '<S20>/Unit Delay2'
   */
  VAR_PcfDia_flgCritSpd_b = (SWC_PCF_DW.UnitDelay2_DSTATE_e ||
    SWC_PCF_DW.UnitDelay1_DSTATE_ld);

  /* Switch: '<S91>/Switch' incorporates:
   *  Constant: '<S91>/CAL_PcfSig_flgBrakeSwt_b'
   *  Constant: '<S91>/CAL_PcfSig_flgBrake_u8'
   *  DataTypeConversion: '<S90>/Data Type Conversion1'
   *  Inport: '<Root>/RP_SWC_Com_Com_VCU06_stBreak'
   */
  if (CAL_PcfSig_flgBrakeSwt_b) {
    VAR_PcfSig_flgBrake_b = (CAL_PcfSig_flgBrake_u8 != 0);
  } else {
    Rte_Read_RP_SWC_Com_Com_VCU06_stBreak(&tmpRead);
    VAR_PcfSig_flgBrake_b = (tmpRead != 0);
  }

  /* End of Switch: '<S91>/Switch' */

  /* Switch: '<S95>/Switch' incorporates:
   *  Constant: '<S95>/CAL_PcfSig_flgstDoorSwt_b'
   *  Constant: '<S95>/CAL_PcfSig_stDoor_u8'
   *  DataTypeConversion: '<S90>/Data Type Conversion2'
   *  Inport: '<Root>/RP_SWC_Com_Com_VCU06_stDoor'
   */
  if (CAL_PcfSig_flgstDoorSwt_b) {
    VAR_PcfSig_stDoor_b = (CAL_PcfSig_stDoor_u8 != 0);
  } else {
    Rte_Read_RP_SWC_Com_Com_VCU06_stDoor(&tmpRead_0);
    VAR_PcfSig_stDoor_b = (tmpRead_0 != 0);
  }

  /* End of Switch: '<S95>/Switch' */

  /* If: '<S132>/If' */
  if (VAR_PcfSig_flgKL15_b) {
    /* Outputs for IfAction SubSystem: '<S132>/If Action Subsystem' incorporates:
     *  ActionPort: '<S137>/Action Port'
     */
    /* Logic: '<S137>/Logical Operator' incorporates:
     *  Logic: '<S137>/Logical Operator1'
     *  Logic: '<S137>/Logical Operator2'
     */
    rtb_enSelfcheck = ((!VAR_PcfSig_flgP_b) && VAR_PcfSig_flgBelt_b &&
                       VAR_PcfSig_flgBrake_b && VAR_PcfSig_stDoor_b &&
                       (!VAR_PcfDia_flgCritSpd_b));

    /* End of Outputs for SubSystem: '<S132>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S132>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S138>/Action Port'
     */
    /* Logic: '<S138>/Logical Operator' incorporates:
     *  Logic: '<S138>/Logical Operator1'
     *  Logic: '<S138>/Logical Operator2'
     */
    rtb_enSelfcheck = ((!VAR_PcfDia_flgCritSpd_b) && (!VAR_PcfSig_flgP_b));

    /* End of Outputs for SubSystem: '<S132>/If Action Subsystem1' */
  }

  /* End of If: '<S132>/If' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_PCF_10ms' */

  /* Inport: '<Root>/RP_SWC_NvM_NvM_SLInPLimt' */
  Rte_Read_RP_SWC_NvM_NvM_SLInPLimt(&rtb_Subtract_i);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_PCF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_PCF_10ms_sys'
   */
  /* Switch: '<S132>/Switch' incorporates:
   *  Constant: '<S119>/CAL_PcfStm_flgUseAutoBackP_b'
   */
  VAR_PcfStm_flgEnAutoInP_b = (CAL_PcfStm_flgUseAutoBackP_b && rtb_enSelfcheck);

  /* Constant: '<S89>/CAL_PcfSig_flgACC_b' */
  VAR_PcfSig_flgACC_b = CAL_PcfSig_flgACC_b;

  /* Switch: '<S114>/Switch' incorporates:
   *  Constant: '<S114>/CAL_PcfSig_AimInPLimt_f32'
   *  Constant: '<S114>/CAL_PcfSig_flgAimInPLimtSwt_b'
   */
  if (CAL_PcfSig_flgAimInPLimtSwt_b) {
    rtb_Subtract_i = CAL_PcfSig_AimInPLimt_f32;
  }

  /* End of Switch: '<S114>/Switch' */

  /* Sum: '<S114>/Add1' incorporates:
   *  Constant: '<S114>/CAL_PcfSig_deltaAimInP_f32'
   */
  VAR_PcfSig_PosAimInP_f32 = rtb_Subtract_i + CAL_PcfSig_deltaAimInP_f32;

  /* Sum: '<S114>/Add2' incorporates:
   *  Constant: '<S114>/CAL_PcfSig_deltaAimOutP_f32'
   */
  VAR_PcfSig_PosAimOutP_f32 = VAR_PcfSig_PosAimInP_f32 +
    CAL_PcfSig_deltaAimOutP_f32;

  /* If: '<S12>/If' incorporates:
   *  Constant: '<S12>/CAL_PcfDia_AimInPRdd_f32'
   *  Constant: '<S12>/CAL_PcfDia_AimOutPRdd_f32'
   *  Sum: '<S12>/Subtract'
   *  Sum: '<S12>/Subtract1'
   */
  if (VAR_PcfSig_Pos1_f32 >= VAR_PcfSig_PosAimOutP_f32 -
      CAL_PcfDia_AimOutPRdd_f32) {
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    /* SignalConversion generated from: '<S25>/PcfDiag_ActorPos' incorporates:
     *  Constant: '<S25>/Constant'
     */
    VAR_PcfDia_stActPos_u8 = 0U;

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem' */
  } else if (VAR_PcfSig_Pos1_f32 <= VAR_PcfSig_PosAimInP_f32 +
             CAL_PcfDia_AimInPRdd_f32) {
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    /* SignalConversion generated from: '<S26>/PcfDiag_ActorPos' incorporates:
     *  Constant: '<S26>/Constant'
     */
    VAR_PcfDia_stActPos_u8 = 1U;

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    /* SignalConversion generated from: '<S27>/PcfDiag_ActorPos' incorporates:
     *  Constant: '<S27>/Constant'
     */
    VAR_PcfDia_stActPos_u8 = 2U;

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem2' */
  }

  /* End of If: '<S12>/If' */

  /* FunctionCaller: '<S1>/RP_SWC_IoHwAb_DIO_Get_BSW_EnPcfEFUSE_IoHwAb_DIO_Get' incorporates:
   *  Constant: '<S1>/Constant10'
   */
  Rte_Call_RP_SWC_IoHwAb_DIO_Get_BSW_EnPcfEFUSE_IoHwAb_DIO_Get(356,
    &rtb_enSelfcheck);

  /* Switch: '<S105>/Switch' incorporates:
   *  Constant: '<S105>/CAL_PcfSig_flgPowerOnSwt_b'
   *  Constant: '<S105>/CAL_PcfSig_flgPowerOn_b'
   */
  if (CAL_PcfSig_flgPowerOnSwt_b) {
    VAR_PcfSig_flgPowerOn_b = CAL_PcfSig_flgPowerOn_b;
  } else {
    VAR_PcfSig_flgPowerOn_b = rtb_enSelfcheck;
  }

  /* End of Switch: '<S105>/Switch' */

  /* Chart: '<S131>/AutoPJudge' incorporates:
   *  Constant: '<S119>/CAL_PcfStm_flgUseFaultRec_b'
   */
  if (SWC_PCF_DW.is_active_c1_SWC_PCF == 0U) {
    SWC_PCF_DW.is_active_c1_SWC_PCF = 1U;
    SWC_PCF_DW.is_c1_SWC_PCF = SWC_PCF_IN_JudgeStandby;
    SWC_PCF_B.PcfDia_AutoP = false;
  } else {
    switch (SWC_PCF_DW.is_c1_SWC_PCF) {
     case SWC_PCF_IN_JudgeAutoOutP:
      if (VAR_PcfSig_flgP_b) {
        SWC_PCF_DW.is_c1_SWC_PCF = SWC_PCF_IN_JudgeOutP;
        SWC_PCF_B.PcfDia_AutoP = false;
      } else {
        if ((!VAR_PcfSig_flgPowerOn_b) || CAL_PcfStm_flgUseFaultRec_b) {
          SWC_PCF_DW.is_c1_SWC_PCF = SWC_PCF_IN_JudgeStandby;
          SWC_PCF_B.PcfDia_AutoP = false;
        }
      }
      break;

     case SWC_PCF_IN_JudgeOutP:
      if ((!VAR_PcfSig_flgPowerOn_b) || CAL_PcfStm_flgUseFaultRec_b) {
        SWC_PCF_DW.is_c1_SWC_PCF = SWC_PCF_IN_JudgeStandby;
        SWC_PCF_B.PcfDia_AutoP = false;
      }
      break;

     default:
      /* case IN_JudgeStandby: */
      if (VAR_PcfSig_flgPowerOn_b && (!CAL_PcfStm_flgUseFaultRec_b)) {
        if ((!VAR_PcfSig_flgP_b) && (VAR_PcfDia_stActPos_u8 == 1)) {
          SWC_PCF_DW.is_c1_SWC_PCF = SWC_PCF_IN_JudgeAutoOutP;
          SWC_PCF_B.PcfDia_AutoP = true;
        } else {
          if (VAR_PcfSig_flgP_b) {
            SWC_PCF_DW.is_c1_SWC_PCF = SWC_PCF_IN_JudgeOutP;
            SWC_PCF_B.PcfDia_AutoP = false;
          }
        }
      }
      break;
    }
  }

  /* End of Chart: '<S131>/AutoPJudge' */

  /* Switch: '<S131>/Switch3' incorporates:
   *  Constant: '<S136>/Constant'
   *  RelationalOperator: '<S136>/Compare'
   *  UnitDelay: '<S118>/Unit Delay1'
   */
  VAR_PcfStm_flgDiaAutoP_b = ((SWC_PCF_DW.UnitDelay1_DSTATE_b == 6) &&
    SWC_PCF_B.PcfDia_AutoP);

  /* Switch: '<S133>/Switch' incorporates:
   *  Constant: '<S119>/CAL_PcfStm_flgUseAutoBackP_b'
   *  Constant: '<S133>/Constant2'
   */
  if (CAL_PcfStm_flgUseAutoBackP_b) {
    /* Switch: '<S133>/Switch1' incorporates:
     *  Constant: '<S133>/Constant'
     *  Logic: '<S133>/Logical Operator1'
     */
    if (VAR_PcfStm_flgDiaAutoP_b || SWC_PCF_DW.UnitDelay2_DSTATE_k) {
      /* Switch: '<S133>/Switch2' incorporates:
       *  Constant: '<S133>/CAL_PcfStm_flgTestPSwt_b'
       *  Constant: '<S133>/Constant1'
       *  Logic: '<S133>/Logical Operator2'
       *  Logic: '<S133>/Logical Operator3'
       *  Logic: '<S133>/Logical Operator4'
       *  Logic: '<S133>/Logical Operator5'
       *  Logic: '<S133>/Logical Operator6'
       */
      if (CAL_PcfStm_flgTestPSwt_b) {
        VAR_PcfStm_flgEnAutoOutP_b = true;
      } else {
        VAR_PcfStm_flgEnAutoOutP_b = ((!VAR_PcfDia_flgCritSpd_b) &&
          (!VAR_PcfSig_stDoor_b) && (VAR_PcfSig_flgBrake_b ||
          VAR_PcfSig_flgACC_b) && (!VAR_PcfSig_flgP_b) && VAR_PcfSig_flgKL15_b);
      }

      /* End of Switch: '<S133>/Switch2' */
    } else {
      VAR_PcfStm_flgEnAutoOutP_b = false;
    }

    /* End of Switch: '<S133>/Switch1' */
  } else {
    VAR_PcfStm_flgEnAutoOutP_b = false;
  }

  /* End of Switch: '<S133>/Switch' */

  /* Logic: '<S122>/Logical Operator9' incorporates:
   *  Constant: '<S119>/CAL_PcfStm_flgUseBlindCtl_b'
   *  Logic: '<S122>/Logical Operator'
   *  RelationalOperator: '<S122>/Relational Operator5'
   */
  VAR_PcfStm_flgFaultToBPC_b = ((!VAR_PcfDia_flgHwIdcOv_b) &&
    (VAR_PcfDia_flgSenVerFail_b || VAR_PcfDia_flgSenOv_b) &&
    CAL_PcfStm_flgUseBlindCtl_b);

  /* If: '<S23>/If' incorporates:
   *  Constant: '<S23>/CAL_PcfDia_cntNorAct_u16'
   *  Constant: '<S23>/CAL_PcfDia_cntOverAct_u16'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  if (SWC_PCF_DW.UnitDelay_DSTATE_er <= CAL_PcfDia_cntNorAct_u16) {
    /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem' incorporates:
     *  ActionPort: '<S54>/Action Port'
     */
    /* SignalConversion generated from: '<S54>/Out1' incorporates:
     *  Constant: '<S54>/Constant'
     */
    VAR_PcfDia_stRunTi_u8 = 0U;

    /* End of Outputs for SubSystem: '<S23>/If Action Subsystem' */
  } else if (SWC_PCF_DW.UnitDelay_DSTATE_er <= CAL_PcfDia_cntOverAct_u16) {
    /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S55>/Action Port'
     */
    SWC_PCF_IfActionSubsystem(&VAR_PcfDia_stRunTi_u8);

    /* End of Outputs for SubSystem: '<S23>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S56>/Action Port'
     */
    SWC_PCF_IfActionSubsystem1(&VAR_PcfDia_stRunTi_u8);

    /* End of Outputs for SubSystem: '<S23>/If Action Subsystem2' */
  }

  /* End of If: '<S23>/If' */

  /* RelationalOperator: '<S53>/Compare' incorporates:
   *  Constant: '<S53>/Constant'
   */
  VAR_PcfDia_flgRunTiOv_b = (VAR_PcfDia_stRunTi_u8 >= 2);

  /* Switch: '<S15>/Switch7' incorporates:
   *  Constant: '<S15>/CAL_PcfDia_IdcLockedHiHyst_f32'
   *  Constant: '<S15>/CAL_PcfDia_IdcLockedHi_f32'
   *  Constant: '<S15>/Constant6'
   *  RelationalOperator: '<S15>/Relational Operator1'
   *  RelationalOperator: '<S15>/Relational Operator7'
   *  UnitDelay: '<S15>/Unit Delay1'
   */
  if (rtb_Switch >= CAL_PcfDia_IdcLockedHi_f32) {
    SWC_PCF_DW.UnitDelay1_DSTATE_f = true;
  } else {
    SWC_PCF_DW.UnitDelay1_DSTATE_f = ((rtb_Switch >
      CAL_PcfDia_IdcLockedHiHyst_f32) && SWC_PCF_DW.UnitDelay1_DSTATE_f);
  }

  /* End of Switch: '<S15>/Switch7' */

  /* Sum: '<S117>/Add1' incorporates:
   *  Constant: '<S116>/CAL_PcfSig_AngMotPos_f32'
   *  Constant: '<S116>/CAL_PcfSig_GernMot_f32'
   *  Constant: '<S117>/CAL_PcfSig_nMotFltCoe_f32'
   *  Constant: '<S117>/Constant3'
   *  Gain: '<S116>/Gain'
   *  Product: '<S116>/Divide'
   *  Product: '<S116>/Product2'
   *  Product: '<S117>/Product1'
   *  Product: '<S117>/Product2'
   *  Sum: '<S116>/Subtract'
   *  Sum: '<S117>/Subtract'
   *  UnitDelay: '<S116>/Unit Delay'
   */
  VAR_PcfSig_nPcfMot_f32 = (VAR_PcfSig_Pos1_f32 - SWC_PCF_DW.UnitDelay_DSTATE_h)
    * 100.0F / CAL_PcfSig_AngMotPos_f32 * CAL_PcfSig_GernMot_f32 *
    CAL_PcfSig_nMotFltCoe_f32 + (1.0F - CAL_PcfSig_nMotFltCoe_f32) *
    VAR_PcfSig_nPcfMot_f32;

  /* Abs: '<S15>/Abs1' */
  rtb_Switch = fabsf(VAR_PcfSig_nPcfMot_f32);

  /* Switch: '<S15>/Switch9' incorporates:
   *  Constant: '<S15>/CAL_PcfDia_nMotLockedLowHyst_f32'
   *  Constant: '<S15>/CAL_PcfDia_nMotLockedLow_f32'
   *  Constant: '<S15>/Constant8'
   *  RelationalOperator: '<S15>/Relational Operator8'
   *  RelationalOperator: '<S15>/Relational Operator9'
   *  UnitDelay: '<S15>/Unit Delay3'
   */
  if (rtb_Switch <= CAL_PcfDia_nMotLockedLow_f32) {
    SWC_PCF_DW.UnitDelay3_DSTATE_m = true;
  } else {
    SWC_PCF_DW.UnitDelay3_DSTATE_m = ((rtb_Switch <
      CAL_PcfDia_nMotLockedLowHyst_f32) && SWC_PCF_DW.UnitDelay3_DSTATE_m);
  }

  /* End of Switch: '<S15>/Switch9' */

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S15>/Constant2'
   *  Logic: '<S15>/Logical Operator1'
   *  UnitDelay: '<S15>/Unit Delay'
   *  UnitDelay: '<S15>/Unit Delay1'
   *  UnitDelay: '<S15>/Unit Delay3'
   */
  if (SWC_PCF_DW.UnitDelay1_DSTATE_f && SWC_PCF_DW.UnitDelay3_DSTATE_m) {
    /* Sum: '<S15>/Add' incorporates:
     *  Constant: '<S15>/Constant3'
     *  UnitDelay: '<S15>/Unit Delay'
     */
    SWC_PCF_DW.UnitDelay_DSTATE_fb++;

    /* Switch: '<S15>/Switch6' incorporates:
     *  Constant: '<S15>/Constant12'
     *  RelationalOperator: '<S15>/Relational Operator5'
     *  UnitDelay: '<S15>/Unit Delay'
     */
    if (SWC_PCF_DW.UnitDelay_DSTATE_fb > 65500) {
      SWC_PCF_DW.UnitDelay_DSTATE_fb = 65500U;
    }

    /* End of Switch: '<S15>/Switch6' */
  } else {
    SWC_PCF_DW.UnitDelay_DSTATE_fb = 0U;
  }

  /* End of Switch: '<S15>/Switch' */

  /* Switch: '<S15>/Switch12' incorporates:
   *  Constant: '<S15>/CAL_PcfDia_flgLocked_b'
   *  Constant: '<S15>/CAL_PcfDia_flgLockedlSwt_b'
   *  Switch: '<S15>/Switch1'
   *  UnitDelay: '<S4>/Unit Delay4'
   */
  if (CAL_PcfDia_flgLockedlSwt_b) {
    VAR_PcfDia_flgLocked_b = CAL_PcfDia_flgLocked_b;
  } else if (VAR_PcfCtl_ActFnh_b) {
    /* Switch: '<S15>/Switch1' incorporates:
     *  Constant: '<S15>/Constant4'
     */
    VAR_PcfDia_flgLocked_b = false;
  } else {
    /* Switch: '<S15>/Switch1' incorporates:
     *  Constant: '<S15>/CAL_PcfDia_LockedNum_u16'
     *  RelationalOperator: '<S15>/Relational Operator2'
     *  UnitDelay: '<S15>/Unit Delay'
     */
    VAR_PcfDia_flgLocked_b = (SWC_PCF_DW.UnitDelay_DSTATE_fb >=
      CAL_PcfDia_LockedNum_u16);
  }

  /* End of Switch: '<S15>/Switch12' */

  /* Switch: '<S65>/Switch' incorporates:
   *  Constant: '<S65>/Constant'
   *  Constant: '<S65>/stParkCtl_Blind'
   *  Constant: '<S65>/stParkCtl_Selflearn'
   *  Logic: '<S65>/Logical Operator'
   *  Logic: '<S65>/Logical Operator3'
   *  RelationalOperator: '<S65>/Relational Operator'
   *  RelationalOperator: '<S65>/Relational Operator1'
   */
  if ((VAR_PcfStm_stParkCtl_u8 == 3) || (VAR_PcfStm_stParkCtl_u8 == 4)) {
    rtb_enSelfcheck = false;
  } else {
    rtb_enSelfcheck = (VAR_PcfDia_flgRunTiOv_b || VAR_PcfDia_flgLocked_b);
  }

  /* End of Switch: '<S65>/Switch' */

  /* Switch: '<S66>/Switch' incorporates:
   *  Constant: '<S66>/CAL_PcfDia_flgRetrySwt_b'
   *  Constant: '<S66>/CAL_PcfDia_flgRetry_b'
   */
  if (CAL_PcfDia_flgRetrySwt_b) {
    VAR_PcfDia_flgRetry_b = CAL_PcfDia_flgRetry_b;
  } else {
    VAR_PcfDia_flgRetry_b = rtb_enSelfcheck;
  }

  /* End of Switch: '<S66>/Switch' */

  /* Chart: '<S64>/ErrRetry' incorporates:
   *  Constant: '<S64>/CAL_PcfDia_Retrytimes_u8'
   *  Constant: '<S64>/CAL_PcfDia_tRetry_u16'
   *  UnitDelay: '<S4>/Unit Delay3'
   */
  if (SWC_PCF_DW.is_active_c4_SWC_PCF == 0U) {
    SWC_PCF_DW.is_active_c4_SWC_PCF = 1U;
    SWC_PCF_DW.is_c4_SWC_PCF = SWC_PCF_IN_Init;
    SWC_PCF_DW.Pausetime = 0U;
    SWC_PCF_DW.RetryCounter = 0.0F;
    VAR_PcfDia_flgstallPause_b = false;
  } else {
    switch (SWC_PCF_DW.is_c4_SWC_PCF) {
     case SWC_PCF_IN_Init:
      if (VAR_PcfDia_flgRetry_b) {
        SWC_PCF_DW.is_c4_SWC_PCF = SWC_PCF_IN_Pause;
        VAR_PcfDia_flgstallPause_b = true;
        SWC_PCF_DW.Pausetime = 0U;
      }
      break;

     case SWC_PCF_IN_Pause:
      if (SWC_PCF_DW.UnitDelay3_DSTATE_h) {
        SWC_PCF_DW.is_c4_SWC_PCF = SWC_PCF_IN_Init;
        SWC_PCF_DW.Pausetime = 0U;
        SWC_PCF_DW.RetryCounter = 0.0F;
        VAR_PcfDia_flgstallPause_b = false;
      } else if (SWC_PCF_DW.RetryCounter >= CAL_PcfDia_Retrytimes_u8) {
        SWC_PCF_DW.is_c4_SWC_PCF = SWC_PCF_IN_StallFault;
        VAR_PcfDia_flgStallFault_b = true;
      } else {
        tmp = SWC_PCF_DW.Pausetime + 1;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_PCF_DW.Pausetime = (uint16)tmp;
        if (SWC_PCF_DW.Pausetime >= CAL_PcfDia_tRetry_u16) {
          SWC_PCF_DW.is_c4_SWC_PCF = SWC_PCF_IN_Retry;
          SWC_PCF_DW.Pausetime = 0U;
          SWC_PCF_DW.RetryCounter++;
          VAR_PcfDia_flgstallPause_b = ((VAR_PcfDia_flgRetry_b ||
            (SWC_PCF_DW.RetryCounter > CAL_PcfDia_Retrytimes_u8)) &&
            VAR_PcfDia_flgstallPause_b);
        }
      }
      break;

     case SWC_PCF_IN_Retry:
      if (SWC_PCF_DW.UnitDelay3_DSTATE_h) {
        SWC_PCF_DW.is_c4_SWC_PCF = SWC_PCF_IN_Init;
        SWC_PCF_DW.Pausetime = 0U;
        SWC_PCF_DW.RetryCounter = 0.0F;
        VAR_PcfDia_flgstallPause_b = false;
      } else {
        if (VAR_PcfDia_flgRetry_b && (SWC_PCF_DW.RetryCounter <=
             CAL_PcfDia_Retrytimes_u8)) {
          SWC_PCF_DW.is_c4_SWC_PCF = SWC_PCF_IN_Pause;
          VAR_PcfDia_flgstallPause_b = true;
          SWC_PCF_DW.Pausetime = 0U;
        }
      }
      break;

     default:
      /* case IN_StallFault: */
      break;
    }
  }

  /* End of Chart: '<S64>/ErrRetry' */

  /* FunctionCaller: '<S1>/RP_SWC_IoHwAb_ADC_BSW_VDD5PCF_IoHwAb_ADC_GetPhyVoltage' incorporates:
   *  Constant: '<S1>/Constant8'
   */
  Rte_Call_RP_SWC_IoHwAb_ADC_BSW_VDD5PCF_IoHwAb_ADC_GetPhyVoltage(27,
    &VAR_PcfSig_VDD5Pcf_f32);

  /* Switch: '<S44>/Switch2' incorporates:
   *  Constant: '<S19>/CAL_EpcDia_VDD5Lowset_f32'
   *  Constant: '<S19>/CAL_PcfDia_VDD5Highset_f32'
   *  Constant: '<S44>/CAL_PcfDia_VDD5Debounce_f1'
   *  Constant: '<S44>/Constant7'
   *  Gain: '<S44>/Gain1'
   *  Logic: '<S19>/Logical Operator1'
   *  RelationalOperator: '<S19>/Relational Operator'
   *  RelationalOperator: '<S19>/Relational Operator1'
   *  RelationalOperator: '<S44>/Relational Operator'
   *  Sum: '<S44>/Subtract'
   *  Switch: '<S44>/Switch3'
   *  UnitDelay: '<S44>/Unit Delay1'
   */
  if ((VAR_PcfSig_VDD5Pcf_f32 > CAL_PcfDia_VDD5Highset_f32) ||
      (VAR_PcfSig_VDD5Pcf_f32 < CAL_PcfDia_VDD5Lowset_f32)) {
    /* Switch: '<S44>/Switch4' incorporates:
     *  Constant: '<S44>/CAL_PcfDia_VDD5Debounce_f32'
     *  Constant: '<S44>/Constant6'
     *  RelationalOperator: '<S44>/Relational Operator1'
     *  Sum: '<S44>/Add1'
     *  UnitDelay: '<S44>/Unit Delay'
     *  UnitDelay: '<S44>/Unit Delay1'
     */
    if (SWC_PCF_DW.UnitDelay_DSTATE_n + 1.0F <= CAL_PcfDia_VDD5Debounce_f32) {
      SWC_PCF_DW.UnitDelay1_DSTATE_c = SWC_PCF_DW.UnitDelay_DSTATE_n + 1.0F;
    } else {
      SWC_PCF_DW.UnitDelay1_DSTATE_c = CAL_PcfDia_VDD5Debounce_f32;
    }

    /* End of Switch: '<S44>/Switch4' */
  } else if (SWC_PCF_DW.UnitDelay1_DSTATE_c - 1.0F >=
             -CAL_PcfDia_VDD5Debounce_f32) {
    /* Switch: '<S44>/Switch3' incorporates:
     *  Constant: '<S44>/Constant7'
     *  Sum: '<S44>/Subtract'
     *  UnitDelay: '<S44>/Unit Delay1'
     */
    SWC_PCF_DW.UnitDelay1_DSTATE_c--;
  } else {
    SWC_PCF_DW.UnitDelay1_DSTATE_c = -CAL_PcfDia_VDD5Debounce_f32;
  }

  /* End of Switch: '<S44>/Switch2' */

  /* Switch: '<S44>/Switch5' incorporates:
   *  Constant: '<S44>/CAL_PcfDia_VDD5Debounce_f2'
   *  Constant: '<S44>/CAL_PcfDia_VDD5Debounce_f3'
   *  Constant: '<S44>/Constant11'
   *  Gain: '<S44>/Gain2'
   *  RelationalOperator: '<S44>/Relational Operator2'
   *  RelationalOperator: '<S44>/Relational Operator3'
   *  UnitDelay: '<S44>/Unit Delay1'
   *  UnitDelay: '<S44>/Unit Delay2'
   */
  if (SWC_PCF_DW.UnitDelay1_DSTATE_c >= CAL_PcfDia_VDD5Debounce_f32) {
    SWC_PCF_DW.UnitDelay2_DSTATE_ld = true;
  } else {
    SWC_PCF_DW.UnitDelay2_DSTATE_ld = ((SWC_PCF_DW.UnitDelay1_DSTATE_c >
      -CAL_PcfDia_VDD5Debounce_f32) && SWC_PCF_DW.UnitDelay2_DSTATE_ld);
  }

  /* End of Switch: '<S44>/Switch5' */

  /* Saturate: '<S45>/Saturation' incorporates:
   *  Sum: '<S45>/Add'
   *  Switch: '<S45>/Switch'
   *  UnitDelay: '<S44>/Unit Delay2'
   *  UnitDelay: '<S45>/Unit Delay'
   */
  if ((uint8)((uint32)SWC_PCF_DW.UnitDelay2_DSTATE_ld +
              SWC_PCF_DW.UnitDelay_DSTATE_ns) < 1) {
    SWC_PCF_DW.UnitDelay_DSTATE_ns = 0U;
  } else {
    SWC_PCF_DW.UnitDelay_DSTATE_ns = 1U;
  }

  /* End of Saturate: '<S45>/Saturation' */

  /* DataTypeConversion: '<S45>/Data Type Conversion1' incorporates:
   *  UnitDelay: '<S45>/Unit Delay'
   */
  VAR_PcfDia_VDD5PcfErr_b = (SWC_PCF_DW.UnitDelay_DSTATE_ns != 0);

  /* Switch: '<S66>/Switch1' incorporates:
   *  Constant: '<S66>/CAL_PcfDia_flgRetrySwt_b'
   */
  VAR_PcfDia_flgRetryShield_b = (CAL_PcfDia_flgRetrySwt_b && rtb_enSelfcheck);

  /* Switch: '<S61>/Switch1' incorporates:
   *  Constant: '<S61>/CAL_PcfDia_flgFaultSwt_b'
   *  Constant: '<S61>/CAL_PcfDia_flgFault_b'
   *  Logic: '<S61>/Logical Operator'
   */
  if (CAL_PcfDia_flgFaultSwt_b) {
    VAR_PcfDia_flgFault_b = CAL_PcfDia_flgFault_b;
  } else {
    VAR_PcfDia_flgFault_b = (VAR_PcfDia_flgSenVerFail_b ||
      VAR_PcfDia_flgHwIdcOv_b || VAR_PcfDia_flgStallFault_b ||
      VAR_PcfDia_flgSenOv_b || VAR_PcfDia_VDD5PcfErr_b ||
      VAR_PcfDia_flgRunTiOv_b || VAR_PcfDia_flgRetryShield_b);
  }

  /* End of Switch: '<S61>/Switch1' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_PCF_10ms' */

  /* Inport: '<Root>/RP_SWC_Com_Com_VCU06_stBelt' */
  Rte_Read_RP_SWC_Com_Com_VCU06_stBelt(&VAR_PcfSig_stParkCtlReq_u8);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_PCF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_PCF_10ms_sys'
   */
  /* RelationalOperator: '<S126>/Relational Operator7' */
  VAR_PcfStm_flgFaultToParkCtl_b_ = !VAR_PcfDia_flgFault_b;

  /* Logic: '<S126>/Logical Operator3' incorporates:
   *  Constant: '<S119>/CAL_PcfStm_flgUseFaultRec_b'
   */
  VAR_PcfStm_flgFaultToParkCtl_b = (VAR_PcfStm_flgFaultToParkCtl_b_ &&
    CAL_PcfStm_flgUseFaultRec_b);

  /* RelationalOperator: '<S134>/Relational Operator7' */
  LogicalOperator2 = !SWC_PCF_DW.UnitDelay2_DSTATE_k;

  /* RelationalOperator: '<S134>/Relational Operator5' */
  LogicalOperator1 = !VAR_PcfSig_flgP_b;

  /* Logic: '<S134>/Logical Operator' incorporates:
   *  RelationalOperator: '<S134>/Relational Operator16'
   */
  VAR_PcfStm_flgPCInPtoRun_b = (LogicalOperator1 && LogicalOperator2 &&
    (!VAR_PcfStm_flgDiaAutoP_b));

  /* Switch: '<S94>/Switch' incorporates:
   *  Constant: '<S94>/CAL_PcfSig_flgstBeltSwt_b'
   *  Constant: '<S94>/CAL_PcfSig_stBelt_u8'
   *  Inport: '<Root>/RP_SWC_Com_Com_VCU06_stBelt'
   */
  if (CAL_PcfSig_flgstBeltSwt_b) {
    VAR_PcfSig_stParkCtlReq_u8 = CAL_PcfSig_stBelt_u8;
  }

  /* End of Switch: '<S94>/Switch' */

  /* Logic: '<S130>/Logical Operator2' incorporates:
   *  Constant: '<S130>/PCInit'
   *  Constant: '<S130>/PCOutP'
   *  Constant: '<S130>/PCRun'
   *  Constant: '<S130>/SLCReq2'
   *  Logic: '<S130>/Logical Operator4'
   *  Logic: '<S130>/Logical Operator5'
   *  Logic: '<S130>/Logical Operator7'
   *  RelationalOperator: '<S130>/Relational Operator10'
   *  RelationalOperator: '<S130>/Relational Operator11'
   *  RelationalOperator: '<S130>/Relational Operator12'
   *  RelationalOperator: '<S130>/Relational Operator8'
   *  RelationalOperator: '<S130>/Relational Operator9'
   *  UnitDelay: '<S118>/Unit Delay1'
   */
  VAR_PcfStm_flgNPCToStandby_b = (((VAR_PcfSig_stParkCtlReq_u8 == 1) &&
    (SWC_PCF_DW.UnitDelay1_DSTATE_b != 7)) || (VAR_PcfDia_flgCritSpd_b &&
    ((SWC_PCF_DW.UnitDelay1_DSTATE_b == 4) || (SWC_PCF_DW.UnitDelay1_DSTATE_b ==
    5))));

  /* RelationalOperator: '<S127>/Relational Operator1' */
  RelationalOperator1 = !VAR_PcfSig_flgPowerOn_b;

  /* Logic: '<S123>/Logical Operator12' incorporates:
   *  Constant: '<S119>/CAL_PcfStm_flgUseRPC_b'
   *  Constant: '<S123>/PCRun'
   *  RelationalOperator: '<S123>/Relational Operator17'
   *  RelationalOperator: '<S123>/Relational Operator18'
   *  UnitDelay: '<S118>/Unit Delay1'
   */
  VAR_PcfStm_flgNPCToRPC_b = (VAR_PcfDia_flgstallPause_b &&
    (SWC_PCF_DW.UnitDelay1_DSTATE_b == 7) && CAL_PcfStm_flgUseRPC_b);

  /* RelationalOperator: '<S129>/Relational Operator1' incorporates:
   *  Constant: '<S119>/CAL_PcfStm_SLAccSpdUp_f32'
   */
  VAR_PcfStm_flgSLAccToWait_b = (rtb_CAL_PcfCtl_PosKp_f32 >=
    CAL_PcfStm_SLAccSpdUp_f32);

  /* Logic: '<S130>/Logical Operator8' incorporates:
   *  Constant: '<S119>/CAL_PcfStm_flgUseSLC_b'
   *  Constant: '<S130>/SLCReq3'
   *  RelationalOperator: '<S130>/Relational Operator13'
   *  RelationalOperator: '<S130>/Relational Operator14'
   */
  VAR_PcfStm_flgSLCToStandby_b = ((!CAL_PcfStm_flgUseSLC_b) ||
    (VAR_PcfSig_stParkCtlReq_u8 != 1));

  /* RelationalOperator: '<S59>/Relational Operator' incorporates:
   *  Constant: '<S59>/stPark_SelfCheck'
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  rtb_enSelfcheck = (SWC_PCF_DW.UnitDelay1_DSTATE_m == 1);

  /* FunctionCaller: '<S1>/RP_SWC_IoHwAb_ADC_BSW_UBRPCF_IoHwAb_ADC_GetPhyVoltage' incorporates:
   *  Constant: '<S1>/Constant6'
   */
  Rte_Call_RP_SWC_IoHwAb_ADC_BSW_UBRPCF_IoHwAb_ADC_GetPhyVoltage(10,
    &VAR_PcfSig_UBRPcf_f32);

  /* If: '<S18>/If' incorporates:
   *  Constant: '<S18>/CAL_PcfDia_UdcCANLowSet_f32'
   *  Constant: '<S18>/CAL_PcfDia_UdcMotLowSet_f32'
   *  Constant: '<S18>/CAL_PcfDia_UdcMotManSet_f32'
   *  Constant: '<S18>/CAL_PcfDia_UdcMotUVSet_f32'
   */
  if (VAR_PcfSig_UBRPcf_f32 <= CAL_PcfDia_UdcCANLowSet_f32) {
    /* Outputs for IfAction SubSystem: '<S18>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S37>/Action Port'
     */
    /* DataTypeConversion: '<S18>/Data Type Conversion' incorporates:
     *  Constant: '<S43>/Constant'
     *  SignalConversion generated from: '<S37>/PCFDIA_stUdc'
     */
    VAR_PcfDia_stUdc_u8 = (uint8)PCFuDc_serlowfail;

    /* End of Outputs for SubSystem: '<S18>/If Action Subsystem4' */
  } else if (VAR_PcfSig_UBRPcf_f32 <= CAL_PcfDia_UdcMotLowSet_f32) {
    /* Outputs for IfAction SubSystem: '<S18>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S36>/Action Port'
     */
    /* DataTypeConversion: '<S18>/Data Type Conversion' incorporates:
     *  Constant: '<S42>/Constant'
     *  SignalConversion generated from: '<S36>/PCFDIA_stUdc'
     */
    VAR_PcfDia_stUdc_u8 = (uint8)PCFuDc_norlowfail;

    /* End of Outputs for SubSystem: '<S18>/If Action Subsystem3' */
  } else if (VAR_PcfSig_UBRPcf_f32 <= CAL_PcfDia_UdcMotManSet_f32) {
    /* Outputs for IfAction SubSystem: '<S18>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    /* DataTypeConversion: '<S18>/Data Type Conversion' incorporates:
     *  Constant: '<S41>/Constant'
     *  SignalConversion generated from: '<S35>/PCFDIA_stUdc'
     */
    VAR_PcfDia_stUdc_u8 = (uint8)PCFuDc_normal;

    /* End of Outputs for SubSystem: '<S18>/If Action Subsystem2' */
  } else if (VAR_PcfSig_UBRPcf_f32 <= CAL_PcfDia_UdcMotUVSet_f32) {
    /* Outputs for IfAction SubSystem: '<S18>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    /* DataTypeConversion: '<S18>/Data Type Conversion' incorporates:
     *  Constant: '<S40>/Constant'
     *  SignalConversion generated from: '<S34>/PCFDIA_stUdc'
     */
    VAR_PcfDia_stUdc_u8 = (uint8)PCFuDc_norhighfail;

    /* End of Outputs for SubSystem: '<S18>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S18>/If Action Subsystem' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    /* DataTypeConversion: '<S18>/Data Type Conversion' incorporates:
     *  Constant: '<S39>/Constant'
     *  SignalConversion generated from: '<S33>/PCFDIA_stUdc'
     */
    VAR_PcfDia_stUdc_u8 = (uint8)PCFuDc_serhighfail;

    /* End of Outputs for SubSystem: '<S18>/If Action Subsystem' */
  }

  /* End of If: '<S18>/If' */

  /* RelationalOperator: '<S18>/Relational Operator' incorporates:
   *  Constant: '<S18>/Below9V'
   */
  VAR_PcfDia_flgUdcLoErr_b = (VAR_PcfDia_stUdc_u8 <= 1);

  /* Switch: '<S24>/Switch' incorporates:
   *  Constant: '<S24>/CAL_PcfDia_tMosHighSet_f32'
   *  Constant: '<S24>/CAL_PcfDia_tMosLowSet_f32'
   *  Constant: '<S24>/Constant2'
   *  Logic: '<S24>/Logical Operator'
   *  RelationalOperator: '<S24>/Relational Operator'
   *  RelationalOperator: '<S24>/Relational Operator1'
   *  UnitDelay: '<S24>/Unit Delay'
   */
  if ((CAL_PcfDia_tMosHighSet_f32 <= VAR_PcfSig_tMosPcf_f32) ||
      (VAR_PcfSig_tMosPcf_f32 <= CAL_PcfDia_tMosLowSet_f32)) {
    /* Sum: '<S24>/Add' incorporates:
     *  Constant: '<S24>/Constant4'
     *  UnitDelay: '<S24>/Unit Delay'
     */
    SWC_PCF_DW.UnitDelay_DSTATE_c4++;

    /* Switch: '<S24>/Switch1' incorporates:
     *  Constant: '<S24>/Constant5'
     *  RelationalOperator: '<S24>/Relational Operator3'
     *  UnitDelay: '<S24>/Unit Delay'
     */
    if (SWC_PCF_DW.UnitDelay_DSTATE_c4 > 1000) {
      SWC_PCF_DW.UnitDelay_DSTATE_c4 = 1000U;
    }

    /* End of Switch: '<S24>/Switch1' */
  } else {
    SWC_PCF_DW.UnitDelay_DSTATE_c4 = 0U;
  }

  /* End of Switch: '<S24>/Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_PCF_10ms' */

  /* Inport: '<Root>/RP_SWC_NvM_NvM_SLFnh' */
  Rte_Read_RP_SWC_NvM_NvM_SLFnh(&VAR_PcfSig_NVMSLFnh_b);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_PCF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_PCF_10ms_sys'
   */
  /* RelationalOperator: '<S24>/Relational Operator2' incorporates:
   *  Constant: '<S24>/CAL_PcfDia_tMosNum_u16'
   *  UnitDelay: '<S24>/Unit Delay'
   */
  VAR_PcfDia_flgtMosOv_b = (SWC_PCF_DW.UnitDelay_DSTATE_c4 >=
    CAL_PcfDia_tMosNum_u16);

  /* Logic: '<S59>/Logical Operator' */
  rtb_LogicalOperator_da = (VAR_PcfDia_flgUdcLoErr_b || VAR_PcfDia_flgtMosOv_b ||
    VAR_PcfDia_flgHwIdcOv_b || VAR_PcfDia_flgSenVerFail_b ||
    VAR_PcfDia_flgSenOv_b || VAR_PcfDia_VDD5PcfErr_b);

  /* Logic: '<S59>/Logical Operator2' incorporates:
   *  Logic: '<S59>/Logical Operator1'
   */
  VAR_PcfDiag_flgselfCkFnh_b = (rtb_enSelfcheck && (!rtb_LogicalOperator_da));

  /* Switch: '<S115>/Switch' incorporates:
   *  Constant: '<S115>/CAL_PcfSig_flgNVMSLFnhSwt_b'
   *  Constant: '<S115>/CAL_PcfSig_flgNVMSLFnh_b'
   *  Inport: '<Root>/RP_SWC_NvM_NvM_SLFnh'
   */
  if (CAL_PcfSig_flgNVMSLFnhSwt_b) {
    VAR_PcfSig_NVMSLFnh_b = CAL_PcfSig_flgNVMSLFnh_b;
  }

  /* End of Switch: '<S115>/Switch' */

  /* Logic: '<S17>/Logical Operator' incorporates:
   *  Constant: '<S17>/CAL_PcfDia_AimInPRatDown_f32'
   *  Constant: '<S17>/CAL_PcfDia_AimInPRatUp_f32'
   *  RelationalOperator: '<S17>/Relational Operator'
   *  RelationalOperator: '<S17>/Relational Operator1'
   */
  VAR_PcfDia_flgAimInPRat_b = ((VAR_PcfSig_PosAimInP_f32 <=
    CAL_PcfDia_AimInPRatUp_f32) && (VAR_PcfSig_PosAimInP_f32 >=
    CAL_PcfDia_AimInPRatDown_f32));

  /* Chart: '<S118>/PcfStm_State' incorporates:
   *  RelationalOperator: '<S130>/Relational Operator6'
   */
  VAR_PcfStm_flgStandbyToNPC_b_tm = !VAR_PcfDia_flgCritSpd_b;

  /* Logic: '<S130>/Logical Operator1' incorporates:
   *  Constant: '<S130>/SLCReq'
   *  RelationalOperator: '<S130>/Relational Operator2'
   */
  VAR_PcfStm_flgStandbyToNPC_b = (VAR_PcfSig_NVMSLFnh_b &&
    (VAR_PcfSig_stParkCtlReq_u8 != 1) && VAR_PcfStm_flgStandbyToNPC_b_tm &&
    VAR_PcfDia_flgAimInPRat_b);

  /* Logic: '<S130>/Logical Operator6' incorporates:
   *  Constant: '<S119>/CAL_PcfStm_flgUseSLC_b'
   *  Constant: '<S130>/SLCReq1'
   *  RelationalOperator: '<S130>/Relational Operator4'
   */
  VAR_PcfStm_flgStandbyToSLC_b = ((VAR_PcfSig_stParkCtlReq_u8 == 1) &&
    VAR_PcfStm_flgStandbyToNPC_b_tm && CAL_PcfStm_flgUseSLC_b);

  /* Logic: '<S125>/Logical Operator' incorporates:
   *  Constant: '<S125>/PCInit'
   *  RelationalOperator: '<S125>/Relational Operator5'
   *  RelationalOperator: '<S125>/Relational Operator7'
   *  UnitDelay: '<S118>/Unit Delay1'
   */
  rtb_RelationalOperator_k4 = ((!VAR_PcfDia_flgstallPause_b) &&
    (SWC_PCF_DW.UnitDelay1_DSTATE_b == 4) && VAR_PcfStm_flgStandbyToNPC_b_tm);

  /* RelationalOperator: '<S21>/Relational Operator15' incorporates:
   *  Constant: '<S21>/CAL_PcfDia_MinPosOutP_f32'
   *  Sum: '<S21>/Add'
   */
  VAR_PcfDia_flgNPCActPos_b = (VAR_PcfSig_Pos1_f32 >= VAR_PcfSig_PosAimInP_f32 +
    CAL_PcfDia_MinPosOutP_f32);

  /* Logic: '<S125>/Logical Operator9' incorporates:
   *  RelationalOperator: '<S125>/Relational Operator20'
   */
  VAR_PcfStm_flgPCInitToInP_b = (rtb_RelationalOperator_k4 &&
    (!VAR_PcfDia_flgNPCActPos_b));

  /* Logic: '<S125>/Logical Operator3' incorporates:
   *  RelationalOperator: '<S125>/Relational Operator16'
   */
  VAR_PcfStm_flgPCInitToOutP_b = (rtb_RelationalOperator_k4 &&
    VAR_PcfDia_flgNPCActPos_b);

  /* Logic: '<S128>/Logical Operator2' */
  LogicalOperator2 = (LogicalOperator2 && LogicalOperator1);

  /* Logic: '<S128>/Logical Operator1' incorporates:
   *  Logic: '<S128>/Logical Operator'
   *  RelationalOperator: '<S128>/Relational Operator2'
   *  RelationalOperator: '<S128>/Relational Operator5'
   */
  LogicalOperator1 = ((SWC_PCF_DW.UnitDelay2_DSTATE_k && LogicalOperator1) ||
                      VAR_PcfSig_flgP_b);

  /* Chart: '<S118>/PcfStm_State' incorporates:
   *  Constant: '<S119>/CAL_PcfStm_BCActimeLimt_u16'
   *  RelationalOperator: '<S127>/Relational Operator'
   */
  if (SWC_PCF_DW.is_active_c2_SWC_PCF == 0U) {
    SWC_PCF_DW.is_active_c2_SWC_PCF = 1U;
    SWC_PCF_DW.is_c2_SWC_PCF = SWC_PCF_IN_Init_g;
    SWC_PCF_enter_internal_Init();
  } else {
    switch (SWC_PCF_DW.is_c2_SWC_PCF) {
     case SWC_PCF_IN_BlindParkControl:
      if (VAR_PcfStm_flgBPCToFault_b) {
        SWC_PCF_DW.is_BlindParkControl = SWC_PCF_IN_NO_ACTIVE_CHILD;
        SWC_PCF_DW.is_c2_SWC_PCF = SWC_PCF_IN_Fault;
        VAR_PcfStm_enMos_b = false;
        VAR_PcfStm_SLenMos_b = false;
        VAR_PcfStm_BCenMos_b = false;
        VAR_PcfStm_SLEnMotorAcc_b = false;
        VAR_PcfStm_SLtrqDes_f32 = 0.0F;
        VAR_PcfStm_SLstModeReq_u8 = 0U;
        VAR_PcfStm_SLflgPosNvm_b = false;
        SWC_PCF_B.PcfStm_stPark = stPark_Fault;
        SWC_PCF_B.PcfStm_stParkCtl = stParkCtl_Halt;
      } else {
        switch (SWC_PCF_DW.is_BlindParkControl) {
         case SWC_PCF_IN_BCFault:
          break;

         case SWC_PCF_IN_BCInP:
          if (!VAR_PcfSig_flgP_b) {
            VAR_PcfStm_BCflgModeReq_b = true;
            SWC_PCF_DW.is_BlindParkControl = SWC_PCF_IN_BCRun;
            VAR_PcfStm_BCenMos_b = true;
            VAR_PcfStm_BCMotDir_b = true;
            SWC_PCF_DW.BCActime = 0U;
            SWC_PCF_B.PcfStm_stPark = stPark_BCRun;
          }
          break;

         case SWC_PCF_IN_BCInit:
          if ((!VAR_PcfDia_flgCritSpd_b) && (!VAR_PcfSig_flgP_b)) {
            SWC_PCF_DW.is_BlindParkControl = SWC_PCF_IN_BCOutP;
            VAR_PcfStm_BCenMos_b = false;
            SWC_PCF_DW.BCRegflgP = false;
            SWC_PCF_B.PcfStm_stPark = stPark_BCOutP;
          } else {
            if (VAR_PcfStm_flgStandbyToNPC_b_tm && VAR_PcfSig_flgP_b) {
              SWC_PCF_DW.is_BlindParkControl = SWC_PCF_IN_BCInP;
              VAR_PcfStm_BCenMos_b = false;
              SWC_PCF_DW.BCRegflgP = true;
              SWC_PCF_B.PcfStm_stPark = stPark_BCInP;
            }
          }
          break;

         case SWC_PCF_IN_BCOutP:
          if (VAR_PcfDia_flgCritSpd_b) {
            SWC_PCF_DW.is_BlindParkControl = SWC_PCF_IN_BCInit;
            VAR_PcfStm_BCenMos_b = false;
            VAR_PcfStm_BCflgModeReq_b = false;
            SWC_PCF_DW.BCActime = 0U;
            VAR_PcfStm_BCstDiag_u8 = 0U;
            SWC_PCF_B.PcfStm_stPark = stPark_BCInit;
            SWC_PCF_B.PcfStm_stParkCtl = stParkCtl_Blind;
          } else {
            if (VAR_PcfSig_flgP_b) {
              VAR_PcfStm_BCflgModeReq_b = true;
              SWC_PCF_DW.is_BlindParkControl = SWC_PCF_IN_BCRun;
              VAR_PcfStm_BCenMos_b = true;
              VAR_PcfStm_BCMotDir_b = false;
              SWC_PCF_DW.BCActime = 0U;
              SWC_PCF_B.PcfStm_stPark = stPark_BCRun;
            }
          }
          break;

         default:
          /* case IN_BCRun: */
          tmp = SWC_PCF_DW.BCActime + 1;
          if (tmp > 65535) {
            tmp = 65535;
          }

          SWC_PCF_DW.BCActime = (uint16)tmp;
          if (VAR_PcfDia_flgBCLocked_b && SWC_PCF_DW.BCRegflgP) {
            VAR_PcfStm_BCflgModeReq_b = false;
            SWC_PCF_DW.is_BlindParkControl = SWC_PCF_IN_BCOutP;
            VAR_PcfStm_BCenMos_b = false;
            SWC_PCF_DW.BCRegflgP = false;
            SWC_PCF_B.PcfStm_stPark = stPark_BCOutP;
          } else if (VAR_PcfDia_flgBCLocked_b && (!SWC_PCF_DW.BCRegflgP)) {
            VAR_PcfStm_BCflgModeReq_b = false;
            SWC_PCF_DW.is_BlindParkControl = SWC_PCF_IN_BCInP;
            VAR_PcfStm_BCenMos_b = false;
            SWC_PCF_DW.BCRegflgP = true;
            SWC_PCF_B.PcfStm_stPark = stPark_BCInP;
          } else {
            if (SWC_PCF_DW.BCActime > CAL_PcfStm_BCActimeLimt_u16) {
              SWC_PCF_DW.is_BlindParkControl = SWC_PCF_IN_BCFault;
              VAR_PcfStm_BCenMos_b = false;
              VAR_PcfStm_BCstDiag_u8 = 1U;
              VAR_PcfStm_BCflgModeReq_b = false;
              SWC_PCF_DW.BCActime = 0U;
              SWC_PCF_B.PcfStm_stPark = stPark_BCFault;
            }
          }
          break;
        }
      }
      break;

     case SWC_PCF_IN_Fault:
      if (VAR_PcfStm_flgFaultToParkCtl_b) {
        SWC_PCF_DW.is_c2_SWC_PCF = SWC_PCF_IN_ParkControl;
        SWC_PCF_DW.is_ParkControl = SWC_PCF_IN_Standby;
        SWC_PCF_enter_internal_Standby();
      } else {
        if (VAR_PcfStm_flgFaultToBPC_b) {
          SWC_PCF_DW.is_c2_SWC_PCF = SWC_PCF_IN_BlindParkControl;
          SWC_PCF_DW.is_BlindParkControl = SWC_PCF_IN_BCInit;
          VAR_PcfStm_BCenMos_b = false;
          VAR_PcfStm_BCflgModeReq_b = false;
          SWC_PCF_DW.BCActime = 0U;
          VAR_PcfStm_BCstDiag_u8 = 0U;
          SWC_PCF_B.PcfStm_stPark = stPark_BCInit;
          SWC_PCF_B.PcfStm_stParkCtl = stParkCtl_Blind;
        }
      }
      break;

     case SWC_PCF_IN_Init_g:
      if (VAR_PcfSig_flgPowerOn_b) {
        SWC_PCF_DW.is_c2_SWC_PCF = SWC_PCF_IN_SelfCheck;
        SWC_PCF_B.PcfStm_stPark = stPark_SelfCheck;
        SWC_PCF_B.PcfStm_stParkCtl = stParkCtl_Halt;
      }
      break;

     case SWC_PCF_IN_ParkControl:
      SWC_PCF_ParkControl(&RelationalOperator1, &LogicalOperator2,
                          &LogicalOperator1);
      break;

     default:
      /* case IN_SelfCheck: */
      if (VAR_PcfDiag_flgselfCkFnh_b) {
        SWC_PCF_DW.is_c2_SWC_PCF = SWC_PCF_IN_ParkControl;
        SWC_PCF_DW.is_ParkControl = SWC_PCF_IN_Standby;
        SWC_PCF_enter_internal_Standby();
      }
      break;
    }
  }

  /* If: '<S74>/If' incorporates:
   *  Constant: '<S74>/closeLoop_0d6x'
   *  Constant: '<S74>/closeLoop_0d85'
   *  Inport: '<S78>/SLenMos'
   *  Inport: '<S79>/SLenMos'
   *  Inport: '<S80>/PcfStm_enMC'
   *  RelationalOperator: '<S74>/Relational Operator'
   *  RelationalOperator: '<S74>/Relational Operator1'
   *  Switch: '<S80>/Switch'
   */
  if (VAR_PcfStm_SLstModeReq_u8 == 1) {
    /* Outputs for IfAction SubSystem: '<S74>/If Action Subsystem' incorporates:
     *  ActionPort: '<S78>/Action Port'
     */
    /* Sum: '<S78>/Add' incorporates:
     *  Constant: '<S78>/CAL_PcfCtl_SLdeltaAimOutP_f32'
     */
    VAR_PcfCtl_AimPosPID_f32 = VAR_PcfStm_SLPosReg_f32 +
      CAL_PcfCtl_SLdeltaAimOutP_f32;
    VAR_PcfCtl_enMosPID_b = VAR_PcfStm_SLenMos_b;

    /* End of Outputs for SubSystem: '<S74>/If Action Subsystem' */
  } else if (VAR_PcfStm_SLstModeReq_u8 == 2) {
    /* Outputs for IfAction SubSystem: '<S74>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S79>/Action Port'
     */
    /* SignalConversion generated from: '<S79>/AimPos' incorporates:
     *  Constant: '<S79>/CAL_PcfCtl_InitOutP_f32'
     */
    VAR_PcfCtl_AimPosPID_f32 = CAL_PcfCtl_InitOutP_f32;
    VAR_PcfCtl_enMosPID_b = VAR_PcfStm_SLenMos_b;

    /* End of Outputs for SubSystem: '<S74>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S74>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S80>/Action Port'
     */
    if (VAR_PcfStm_MotDir_b) {
      /* Switch: '<S80>/Switch' */
      VAR_PcfCtl_AimPosPID_f32 = VAR_PcfSig_PosAimInP_f32;
    } else {
      /* Switch: '<S80>/Switch' */
      VAR_PcfCtl_AimPosPID_f32 = VAR_PcfSig_PosAimOutP_f32;
    }

    VAR_PcfCtl_enMosPID_b = VAR_PcfStm_enMos_b;

    /* End of Outputs for SubSystem: '<S74>/If Action Subsystem2' */
  }

  /* End of If: '<S74>/If' */

  /* Sum: '<S75>/Subtract' */
  VAR_PcfCtl_PosDif_f32 = VAR_PcfCtl_AimPosPID_f32 - VAR_PcfSig_Pos1_f32;

  /* Switch: '<S71>/Switch' incorporates:
   *  Abs: '<S71>/Abs'
   *  Constant: '<S71>/CAL_PcfCtl_PrePos_f32'
   *  Constant: '<S71>/Constant2'
   *  RelationalOperator: '<S71>/Relational Operator'
   *  UnitDelay: '<S71>/Unit Delay'
   */
  if (fabsf(VAR_PcfCtl_PosDif_f32) < CAL_PcfCtl_PrePos_f32) {
    /* Sum: '<S71>/Add1' incorporates:
     *  UnitDelay: '<S71>/Unit Delay'
     */
    SWC_PCF_DW.UnitDelay_DSTATE_fr++;

    /* Switch: '<S71>/Switch1' incorporates:
     *  Constant: '<S71>/PcfCtl_timAdjlim'
     *  RelationalOperator: '<S71>/Relational Operator2'
     *  UnitDelay: '<S71>/Unit Delay'
     */
    if (SWC_PCF_DW.UnitDelay_DSTATE_fr >= 1000) {
      SWC_PCF_DW.UnitDelay_DSTATE_fr = 1000U;
    }

    /* End of Switch: '<S71>/Switch1' */
  } else {
    SWC_PCF_DW.UnitDelay_DSTATE_fr = 0U;
  }

  /* End of Switch: '<S71>/Switch' */

  /* RelationalOperator: '<S71>/Relational Operator1' incorporates:
   *  Constant: '<S71>/CAL_PcfCtl_timePrePos_u16'
   *  UnitDelay: '<S71>/Unit Delay'
   */
  VAR_PcfCtl_ActFnh_b = (SWC_PCF_DW.UnitDelay_DSTATE_fr >=
    CAL_PcfCtl_timePrePos_u16);

  /* Logic: '<S73>/Logical Operator' incorporates:
   *  Logic: '<S73>/Logical Operator1'
   */
  VAR_PcfCtl_enMosOutPID_b = ((!VAR_PcfCtl_ActFnh_b) && VAR_PcfCtl_enMosPID_b);

  /* Logic: '<S69>/Logical Operator' */
  RelationalOperator1 = !VAR_PcfCtl_enMosOutPID_b;

  /* Gain: '<S77>/CAL_PcfCtl_PosKp_f32' */
  rtb_CAL_PcfCtl_PosKp_f32 = CAL_PcfCtl_PosKp_f32 * VAR_PcfCtl_PosDif_f32;

  /* Switch: '<S77>/Switch5' incorporates:
   *  Constant: '<S77>/Constant'
   *  Constant: '<S77>/Constant3'
   *  Gain: '<S77>/CAL_PcfCtl_PosKi_f32'
   *  Sum: '<S77>/Add2'
   *  Switch: '<S77>/Switch2'
   *  UnitDelay: '<S77>/Delay2'
   */
  if (RelationalOperator1) {
    VAR_PcfCtl_PosKp_f32 = 0.0F;
    rtb_Switch = 0.0F;
  } else {
    VAR_PcfCtl_PosKp_f32 = rtb_CAL_PcfCtl_PosKp_f32;

    /* Switch: '<S77>/Switch3' incorporates:
     *  Abs: '<S77>/Abs'
     *  Constant: '<S77>/Constant2'
     *  Constant: '<S77>/Constant4'
     *  RelationalOperator: '<S77>/Operator1'
     *  UnitDelay: '<S77>/Delay3'
     */
    if (fabsf(SWC_PCF_DW.Delay3_DSTATE) >= 1.0F) {
      rtb_Subtract_i = 0.0F;
    } else {
      rtb_Subtract_i = rtb_CAL_PcfCtl_PosKp_f32;
    }

    /* End of Switch: '<S77>/Switch3' */
    rtb_Switch = CAL_PcfCtl_PosKi_f32 * rtb_Subtract_i +
      SWC_PCF_DW.Delay2_DSTATE;
  }

  /* End of Switch: '<S77>/Switch5' */

  /* Saturate: '<S77>/Saturation1' */
  if (rtb_Switch > CAL_PcfCtl_intPIDuplim_f32) {
    VAR_PcfCtl_PosKi_f32 = CAL_PcfCtl_intPIDuplim_f32;
  } else if (rtb_Switch < CAL_PcfCtl_intPIDdownlim_f32) {
    VAR_PcfCtl_PosKi_f32 = CAL_PcfCtl_intPIDdownlim_f32;
  } else {
    VAR_PcfCtl_PosKi_f32 = rtb_Switch;
  }

  /* End of Saturate: '<S77>/Saturation1' */

  /* Gain: '<S77>/CAL_PcfCtl_PosKd_f32' */
  rtb_CAL_PcfCtl_PosKp_f32 *= CAL_PcfCtl_PosKd_f32;

  /* Switch: '<S77>/Switch1' incorporates:
   *  Constant: '<S77>/Constant1'
   *  Sum: '<S77>/Add3'
   *  UnitDelay: '<S77>/Delay1'
   */
  if (RelationalOperator1) {
    VAR_PcfCtl_PosKd_f32 = 0.0F;
  } else {
    VAR_PcfCtl_PosKd_f32 = rtb_CAL_PcfCtl_PosKp_f32 - SWC_PCF_DW.Delay1_DSTATE;
  }

  /* End of Switch: '<S77>/Switch1' */

  /* Sum: '<S77>/Add' incorporates:
   *  UnitDelay: '<S77>/Delay3'
   */
  SWC_PCF_DW.Delay3_DSTATE = (VAR_PcfCtl_PosKp_f32 + VAR_PcfCtl_PosKi_f32) +
    VAR_PcfCtl_PosKd_f32;

  /* Saturate: '<S77>/Saturation3' incorporates:
   *  UnitDelay: '<S77>/Delay3'
   */
  if (SWC_PCF_DW.Delay3_DSTATE > 1.0F) {
    VAR_PcfCtl_PosPIDOut_f32 = 1.0F;
  } else if (SWC_PCF_DW.Delay3_DSTATE < -1.0F) {
    VAR_PcfCtl_PosPIDOut_f32 = -1.0F;
  } else {
    VAR_PcfCtl_PosPIDOut_f32 = SWC_PCF_DW.Delay3_DSTATE;
  }

  /* End of Saturate: '<S77>/Saturation3' */

  /* Sum: '<S72>/Subtract' incorporates:
   *  UnitDelay: '<S72>/Unit Delay2'
   */
  rtb_Subtract_i = VAR_PcfCtl_PosPIDOut_f32 - VAR_PcfCtl_SoftDycPID_f32;

  /* Switch: '<S72>/Switch2' incorporates:
   *  Constant: '<S72>/CAL_PcfCtl_SoftDyc_f32'
   *  RelationalOperator: '<S72>/Relational Operator'
   *  Sum: '<S72>/Add1'
   *  UnitDelay: '<S72>/Unit Delay2'
   */
  if (rtb_Subtract_i <= CAL_PcfCtl_SoftDyc_f32) {
    /* Switch: '<S72>/Switch3' incorporates:
     *  Product: '<S72>/Product'
     *  RelationalOperator: '<S72>/Relational Operator1'
     *  Sum: '<S72>/Add2'
     *  UnitDelay: '<S72>/Unit Delay2'
     */
    if (-rtb_Subtract_i <= CAL_PcfCtl_SoftDyc_f32) {
      VAR_PcfCtl_SoftDycPID_f32 = VAR_PcfCtl_PosPIDOut_f32;
    } else {
      VAR_PcfCtl_SoftDycPID_f32 -= CAL_PcfCtl_SoftDyc_f32;
    }

    /* End of Switch: '<S72>/Switch3' */
  } else {
    VAR_PcfCtl_SoftDycPID_f32 += CAL_PcfCtl_SoftDyc_f32;
  }

  /* End of Switch: '<S72>/Switch2' */

  /* Lookup_n-D: '<S113>/Idcdyc_Table' */
  VAR_PcfSig_DycLim_f32 = look1_iflf_binlcpw(VAR_PcfSig_IdcPcf_f32, ((const
    float32 *)&(CAL_PcfSig_IdcDycY_dyc_af32[0])), ((const float32 *)
    &(CAL_PcfSig_IdcDycX_Idc_af32[0])), 3U);

  /* Lookup_n-D: '<S113>/tMosdyc_Table1' */
  rtb_Subtract_i = look1_iflf_binlcpw(VAR_PcfSig_nPcfMot_f32, ((const float32 *)
    &(CAL_PcfSig_tMosDycY_dyc_af32[0])), ((const float32 *)
    &(CAL_PcfSig_tMosDycX_tMos_af32[0])), 5U);

  /* Switch: '<S113>/Switch' incorporates:
   *  RelationalOperator: '<S113>/Relational Operator2'
   */
  if (VAR_PcfSig_DycLim_f32 > rtb_Subtract_i) {
    VAR_PcfSig_DycLim_f32 = rtb_Subtract_i;
  }

  /* End of Switch: '<S113>/Switch' */

  /* Lookup_n-D: '<S113>/Udcdyc_Table' */
  rtb_Subtract_i = look1_iflf_binlcpw(VAR_PcfSig_UBRPcf_f32, ((const float32 *)
    &(CAL_PcfSig_UdcDycY_dyc_af32[0])), ((const float32 *)
    &(CAL_PcfSig_UdcDycX_Udc_af32[0])), 19U);

  /* Switch: '<S113>/Switch1' incorporates:
   *  RelationalOperator: '<S113>/Relational Operator3'
   */
  if (VAR_PcfSig_DycLim_f32 > rtb_Subtract_i) {
    VAR_PcfSig_DycLim_f32 = rtb_Subtract_i;
  }

  /* End of Switch: '<S113>/Switch1' */

  /* Saturate: '<S113>/Saturation' */
  if (VAR_PcfSig_DycLim_f32 > 1.0F) {
    VAR_PcfSig_DycLim_f32 = 1.0F;
  } else {
    if (VAR_PcfSig_DycLim_f32 < 0.0F) {
      VAR_PcfSig_DycLim_f32 = 0.0F;
    }
  }

  /* End of Saturate: '<S113>/Saturation' */

  /* Switch: '<S72>/Switch' incorporates:
   *  Abs: '<S72>/Abs1'
   *  Constant: '<S72>/Constant2'
   */
  if (VAR_PcfCtl_enMosOutPID_b) {
    rtb_Subtract_i = fabsf(VAR_PcfCtl_SoftDycPID_f32);
  } else {
    rtb_Subtract_i = 0.0F;
  }

  /* End of Switch: '<S72>/Switch' */

  /* Product: '<S72>/Product1' */
  VAR_PcfCtl_DycOutPID_f32 = rtb_Subtract_i * VAR_PcfSig_DycLim_f32;

  /* RelationalOperator: '<S72>/Relational Operator2' incorporates:
   *  Constant: '<S72>/Constant1'
   */
  VAR_PcfCtl_DirOutPID_b = (VAR_PcfCtl_SoftDycPID_f32 >= 0.0F);

  /* If: '<S70>/If' incorporates:
   *  Constant: '<S70>/CAL_PcfCtl_flgManual_b'
   *  Inport: '<S81>/BC_enMos'
   *  Inport: '<S82>/SL_enMos'
   *  Inport: '<S83>/PID_enMos'
   *  RelationalOperator: '<S70>/Relational Operator'
   */
  if (CAL_PcfCtl_flgManual_b) {
    /* Outputs for IfAction SubSystem: '<S70>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S84>/Action Port'
     */
    /* SignalConversion generated from: '<S84>/enMos' incorporates:
     *  Constant: '<S84>/CAL_PcfCtl_ManualEn_b'
     */
    VAR_PcfCtl_enMos_b = CAL_PcfCtl_ManualEn_b;

    /* Outport: '<Root>/PP_SWC_PCF_PCF_dycPWM' incorporates:
     *  Constant: '<S84>/CAL_PcfCtl_ManualDty_f32'
     *  SignalConversion generated from: '<S84>/Dyc'
     */
    (void) Rte_Write_PP_SWC_PCF_PCF_dycPWM(CAL_PcfCtl_ManualDty_f32);

    /* Outport: '<Root>/PP_SWC_PCF_PCF_MotDir' incorporates:
     *  Constant: '<S84>/CAL_PcfCtl_ManualDir_b'
     *  SignalConversion generated from: '<S84>/Dir'
     */
    (void) Rte_Write_PP_SWC_PCF_PCF_MotDir(CAL_PcfCtl_ManualDir_b);

    /* End of Outputs for SubSystem: '<S70>/If Action Subsystem4' */
  } else if (VAR_PcfStm_BCflgModeReq_b) {
    /* Outputs for IfAction SubSystem: '<S70>/If Action Subsystem' incorporates:
     *  ActionPort: '<S81>/Action Port'
     */
    /* Outport: '<Root>/PP_SWC_PCF_PCF_dycPWM' incorporates:
     *  Constant: '<S81>/CAL_PcfCtl_BCRunDyc_f32'
     *  SignalConversion generated from: '<S81>/Dyc'
     */
    (void) Rte_Write_PP_SWC_PCF_PCF_dycPWM(CAL_PcfCtl_BCRunDyc_f32);
    VAR_PcfCtl_enMos_b = VAR_PcfStm_BCenMos_b;

    /* Outport: '<Root>/PP_SWC_PCF_PCF_MotDir' incorporates:
     *  Inport: '<S81>/BC_Dir'
     *  Inport: '<S81>/BC_enMos'
     */
    (void) Rte_Write_PP_SWC_PCF_PCF_MotDir(VAR_PcfStm_BCMotDir_b);

    /* End of Outputs for SubSystem: '<S70>/If Action Subsystem' */
  } else if (VAR_PcfStm_SLstModeReq_u8 == 3) {
    /* Outputs for IfAction SubSystem: '<S70>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S82>/Action Port'
     */
    /* Outport: '<Root>/PP_SWC_PCF_PCF_dycPWM' incorporates:
     *  Constant: '<S82>/CAL_PcfCtl_SLRunDyc_f32'
     *  SignalConversion generated from: '<S82>/Dyc'
     */
    (void) Rte_Write_PP_SWC_PCF_PCF_dycPWM(CAL_PcfCtl_SLRunDyc_f32);

    /* Outport: '<Root>/PP_SWC_PCF_PCF_MotDir' incorporates:
     *  Constant: '<S82>/CAL_PcfCtl_SLRunDir_b'
     *  SignalConversion generated from: '<S82>/Dir'
     */
    (void) Rte_Write_PP_SWC_PCF_PCF_MotDir(CAL_PcfCtl_SLRunDir_b);
    VAR_PcfCtl_enMos_b = VAR_PcfStm_SLenMos_b;

    /* End of Outputs for SubSystem: '<S70>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S70>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S83>/Action Port'
     */
    VAR_PcfCtl_enMos_b = VAR_PcfCtl_enMosOutPID_b;

    /* Outport: '<Root>/PP_SWC_PCF_PCF_dycPWM' incorporates:
     *  Inport: '<S83>/PID_Dyc'
     *  Inport: '<S83>/PID_enMos'
     */
    (void) Rte_Write_PP_SWC_PCF_PCF_dycPWM(VAR_PcfCtl_DycOutPID_f32);

    /* Outport: '<Root>/PP_SWC_PCF_PCF_MotDir' incorporates:
     *  Inport: '<S83>/PID_Dir'
     */
    (void) Rte_Write_PP_SWC_PCF_PCF_MotDir(VAR_PcfCtl_DirOutPID_b);

    /* End of Outputs for SubSystem: '<S70>/If Action Subsystem2' */
  }

  /* End of If: '<S70>/If' */

  /* FunctionCaller: '<S1>/RP_SWC_IoHwAb_DIO_Set_PCF_enMos_IoHwAb_DIO_Set' incorporates:
   *  Constant: '<S1>/Constant'
   */
  Rte_Call_RP_SWC_IoHwAb_DIO_Set_PCF_enMos_IoHwAb_DIO_Set(0, VAR_PcfCtl_enMos_b);

  /* Logic: '<S58>/Logical Operator1' incorporates:
   *  Constant: '<S58>/Fault'
   *  Constant: '<S58>/InP'
   *  Constant: '<S58>/PcfStm_BCInP'
   *  Constant: '<S58>/PcfStm_BCRun'
   *  Constant: '<S58>/PcfStm_Blind'
   *  Constant: '<S58>/PcfStm_Halt'
   *  Constant: '<S58>/PcfStm_Normal'
   *  Constant: '<S58>/PosOutP'
   *  Constant: '<S58>/Run'
   *  Logic: '<S58>/Logical Operator'
   *  Logic: '<S58>/Logical Operator2'
   *  Logic: '<S58>/Logical Operator3'
   *  Logic: '<S58>/Logical Operator4'
   *  RelationalOperator: '<S58>/Relational Operator10'
   *  RelationalOperator: '<S58>/Relational Operator11'
   *  RelationalOperator: '<S58>/Relational Operator12'
   *  RelationalOperator: '<S58>/Relational Operator13'
   *  RelationalOperator: '<S58>/Relational Operator14'
   *  RelationalOperator: '<S58>/Relational Operator4'
   *  RelationalOperator: '<S58>/Relational Operator7'
   *  RelationalOperator: '<S58>/Relational Operator8'
   *  RelationalOperator: '<S58>/Relational Operator9'
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  VAR_PcfDia_flgAllowPwmRun_b = ((VAR_PcfDia_stActPos_u8 == 0) &&
    VAR_PcfStm_flgFaultToParkCtl_b_ && (((VAR_PcfStm_stParkCtl_u8 == 0) &&
    (SWC_PCF_DW.UnitDelay1_DSTATE_m != 8)) || ((VAR_PcfStm_stParkCtl_u8 == 1) &&
    (SWC_PCF_DW.UnitDelay1_DSTATE_m != 7) && (SWC_PCF_DW.UnitDelay1_DSTATE_m !=
    6)) || ((VAR_PcfStm_stParkCtl_u8 == 4) && (SWC_PCF_DW.UnitDelay1_DSTATE_m !=
    26) && (SWC_PCF_DW.UnitDelay1_DSTATE_m != 27))));

  /* Logic: '<S59>/Logical Operator4' */
  VAR_PcfDiag_flgselfCkErr_b = (rtb_enSelfcheck && rtb_LogicalOperator_da);

  /* Logic: '<S60>/Logical Operator' incorporates:
   *  Constant: '<S60>/PcfStm_BCRun'
   *  Constant: '<S60>/PcfStm_Blind'
   *  Constant: '<S60>/PcfStm_Halt'
   *  Constant: '<S60>/PcfStm_Normal'
   *  Constant: '<S60>/Run'
   *  Logic: '<S60>/Logical Operator1'
   *  Logic: '<S60>/Logical Operator4'
   *  RelationalOperator: '<S60>/Relational Operator'
   *  RelationalOperator: '<S60>/Relational Operator12'
   *  RelationalOperator: '<S60>/Relational Operator13'
   *  RelationalOperator: '<S60>/Relational Operator7'
   *  RelationalOperator: '<S60>/Relational Operator8'
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  VAR_PcfDia_flgShtDwnReq_b = (VAR_PcfDia_flgFault_b || (VAR_PcfStm_stParkCtl_u8
    == 0) || ((VAR_PcfStm_stParkCtl_u8 == 1) && (SWC_PCF_DW.UnitDelay1_DSTATE_m
    != 7)) || ((VAR_PcfStm_stParkCtl_u8 == 4) && (VAR_PcfStm_stParkCtl_u8 != 27)));

  /* Outport: '<Root>/PP_SWC_PCF_PCF_flgShtDwnReq' incorporates:
   *  Logic: '<S11>/Logical Operator'
   */
  (void) Rte_Write_PP_SWC_PCF_PCF_flgShtDwnReq(VAR_PcfDia_flgShtDwnReq_b);

  /* Outport: '<Root>/PP_SWC_PCF_PCF_flgAllowPwmRun' incorporates:
   *  Logic: '<S11>/Logical Operator1'
   */
  (void) Rte_Write_PP_SWC_PCF_PCF_flgAllowPwmRun(VAR_PcfDia_flgAllowPwmRun_b);

  /* Logic: '<S62>/Logical Operator' incorporates:
   *  Constant: '<S62>/EpcStm_Run'
   *  Constant: '<S62>/NotInPorOutP'
   *  Constant: '<S62>/PcfStm_Halt'
   *  Constant: '<S62>/PcfStm_Normal'
   *  Logic: '<S62>/Logical Operator1'
   *  RelationalOperator: '<S62>/Relational Operator'
   *  RelationalOperator: '<S62>/Relational Operator1'
   *  RelationalOperator: '<S62>/Relational Operator2'
   *  RelationalOperator: '<S62>/Relational Operator3'
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  VAR_PcfDia_flgUnexPosWarn_b = ((VAR_PcfDia_stActPos_u8 == 2) &&
    (SWC_PCF_DW.UnitDelay1_DSTATE_m != 7) && ((VAR_PcfStm_stParkCtl_u8 == 0) ||
    (VAR_PcfStm_stParkCtl_u8 == 1)));

  /* Switch: '<S76>/Switch' incorporates:
   *  Constant: '<S76>/CAL_PcfCtl_flgFnhSwt_b'
   *  Constant: '<S76>/CAL_PcfCtl_flgFnh_b'
   */
  if (CAL_PcfCtl_flgFnhSwt_b) {
    VAR_PcfCtl_ActFnh_b = CAL_PcfCtl_flgFnh_b;
  }

  /* End of Switch: '<S76>/Switch' */

  /* Switch: '<S77>/Switch4' incorporates:
   *  Gain: '<S77>/Gain'
   *  Saturate: '<S77>/Saturation2'
   *  UnitDelay: '<S77>/Delay2'
   */
  if (RelationalOperator1) {
    SWC_PCF_DW.Delay2_DSTATE = 0.0F;
  } else if (rtb_Switch > CAL_PcfCtl_intPIDuplim_f32) {
    /* Saturate: '<S77>/Saturation2' */
    SWC_PCF_DW.Delay2_DSTATE = CAL_PcfCtl_intPIDuplim_f32;
  } else if (rtb_Switch < CAL_PcfCtl_intPIDdownlim_f32) {
    /* Saturate: '<S77>/Saturation2' */
    SWC_PCF_DW.Delay2_DSTATE = CAL_PcfCtl_intPIDdownlim_f32;
  } else {
    /* Saturate: '<S77>/Saturation2' */
    SWC_PCF_DW.Delay2_DSTATE = rtb_Switch;
  }

  /* End of Switch: '<S77>/Switch4' */

  /* DataTypeConversion: '<S118>/EnumToUint1' */
  VAR_PcfStm_stPark_u8 = (uint8)SWC_PCF_B.PcfStm_stPark;

  /* DataTypeConversion: '<S118>/EnumToUint2' */
  VAR_PcfStm_stParkCtl_u8 = (uint8)SWC_PCF_B.PcfStm_stParkCtl;

  /* Outport: '<Root>/PP_SWC_PCF_PCF_stParkCtl' incorporates:
   *  Sum: '<S8>/Add2'
   */
  (void) Rte_Write_PP_SWC_PCF_PCF_stParkCtl(VAR_PcfStm_stParkCtl_u8);

  /* Outport: '<Root>/PP_SWC_PCF_PCF_Status' incorporates:
   *  DataTypeConversion: '<S8>/EnumToUint1'
   */
  (void) Rte_Write_PP_SWC_PCF_PCF_Status(VAR_PcfStm_stPark_u8);

  /* Outport: '<Root>/PP_SWC_PCF_PCF_Pos1' incorporates:
   *  Constant: '<S8>/Constant7'
   *  Product: '<S8>/Product1'
   */
  (void) Rte_Write_PP_SWC_PCF_PCF_Pos1(VAR_PcfSig_Pos1_f32 * 100.0F);

  /* Switch: '<S139>/Switch1' incorporates:
   *  Constant: '<S139>/Constant2'
   *  Constant: '<S139>/Constant3'
   */
  if (VAR_PcfDia_flgRunTiOv_b) {
    tmpRead = 3U;
  } else {
    tmpRead = 2U;
  }

  /* End of Switch: '<S139>/Switch1' */

  /* FunctionCaller: '<S1>/RP_SWC_Dem_PCF_ActOvTiErr_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_PCF_ActOvTiErr_SetEventStatus(tmpRead);

  /* Switch: '<S139>/Switch7' incorporates:
   *  Constant: '<S139>/Constant14'
   *  Constant: '<S139>/Constant15'
   */
  if (VAR_PcfDia_flgHwIdcOv_b) {
    tmpRead = 3U;
  } else {
    tmpRead = 2U;
  }

  /* End of Switch: '<S139>/Switch7' */

  /* FunctionCaller: '<S1>/RP_SWC_Dem_PCF_IdcOvErr_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_PCF_IdcOvErr_SetEventStatus(tmpRead);

  /* Switch: '<S139>/Switch5' incorporates:
   *  Constant: '<S139>/Constant10'
   *  Constant: '<S139>/Constant11'
   */
  if (VAR_PcfDiag_flgselfCkErr_b) {
    tmpRead = 3U;
  } else {
    tmpRead = 2U;
  }

  /* End of Switch: '<S139>/Switch5' */

  /* FunctionCaller: '<S1>/RP_SWC_Dem_PCF_SelfcheckErr_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_PCF_SelfcheckErr_SetEventStatus(tmpRead);

  /* Switch: '<S139>/Switch6' incorporates:
   *  Constant: '<S139>/Constant12'
   *  Constant: '<S139>/Constant13'
   */
  if (VAR_PcfDia_flgSenVerFail_b) {
    tmpRead = 3U;
  } else {
    tmpRead = 2U;
  }

  /* End of Switch: '<S139>/Switch6' */

  /* FunctionCaller: '<S1>/RP_SWC_Dem_PCF_SenClbErr_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_PCF_SenClbErr_SetEventStatus(tmpRead);

  /* Switch: '<S139>/Switch3' incorporates:
   *  Constant: '<S139>/Constant6'
   *  Constant: '<S139>/Constant7'
   */
  if (VAR_PcfDia_flgSenOv_b) {
    tmpRead = 3U;
  } else {
    tmpRead = 2U;
  }

  /* End of Switch: '<S139>/Switch3' */

  /* FunctionCaller: '<S1>/RP_SWC_Dem_PCF_SenOvErr_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_PCF_SenOvErr_SetEventStatus(tmpRead);

  /* Switch: '<S139>/Switch' incorporates:
   *  Constant: '<S139>/Constant'
   *  Constant: '<S139>/Constant1'
   */
  if (VAR_PcfDia_flgStallFault_b) {
    tmpRead = 3U;
  } else {
    tmpRead = 2U;
  }

  /* End of Switch: '<S139>/Switch' */

  /* FunctionCaller: '<S1>/RP_SWC_Dem_PCF_StallRetryErr_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_PCF_StallRetryErr_SetEventStatus(tmpRead);

  /* Switch: '<S139>/Switch2' incorporates:
   *  Constant: '<S139>/Constant4'
   *  Constant: '<S139>/Constant5'
   */
  if (VAR_PcfDia_flgLocked_b) {
    tmpRead = 3U;
  } else {
    tmpRead = 2U;
  }

  /* End of Switch: '<S139>/Switch2' */

  /* FunctionCaller: '<S1>/RP_SWC_Dem_PCF_StallWarn_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_PCF_StallWarn_SetEventStatus(tmpRead);

  /* Switch: '<S139>/Switch4' incorporates:
   *  Constant: '<S139>/Constant8'
   *  Constant: '<S139>/Constant9'
   */
  if (VAR_PcfDia_flgUnexPosWarn_b) {
    tmpRead = 3U;
  } else {
    tmpRead = 2U;
  }

  /* End of Switch: '<S139>/Switch4' */

  /* FunctionCaller: '<S1>/RP_SWC_Dem_PCF_UnexpPosErr_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_PCF_UnexpPosErr_SetEventStatus(tmpRead);

  /* FunctionCaller: '<S1>/RP_SWC_IoHwAb_DIO_Get_BSW_ParkHard_IoHwAb_DIO_Get' incorporates:
   *  Constant: '<S1>/Constant9'
   */
  Rte_Call_RP_SWC_IoHwAb_DIO_Get_BSW_ParkHard_IoHwAb_DIO_Get(369, &rtb_ParkHard);

  /* Update for UnitDelay: '<S7>/Unit Delay' */
  SWC_PCF_DW.UnitDelay_DSTATE_en = VAR_PcfCtl_ActFnh_b;

  /* Update for UnitDelay: '<S98>/Unit Delay2' */
  SWC_PCF_DW.UnitDelay2_DSTATE_b = rtb_Switch3_b;

  /* Update for UnitDelay: '<S97>/Unit Delay2' */
  SWC_PCF_DW.UnitDelay2_DSTATE_j = rtb_Switch2_en;

  /* Update for UnitDelay: '<S97>/Unit Delay1' */
  SWC_PCF_DW.UnitDelay1_DSTATE_o = VAR_PcfSig_TestTimes_u16;

  /* Update for UnitDelay: '<S6>/Unit Delay1' incorporates:
   *  DataTypeConversion: '<S70>/Data Type Conversion'
   */
  SWC_PCF_DW.UnitDelay1_DSTATE_l = VAR_PcfCtl_enMos_b;

  /* Update for UnitDelay: '<S28>/Unit Delay' incorporates:
   *  UnitDelay: '<S28>/Unit Delay1'
   */
  SWC_PCF_DW.UnitDelay_DSTATE_l = SWC_PCF_DW.UnitDelay1_DSTATE_g;

  /* Update for UnitDelay: '<S29>/Unit Delay' incorporates:
   *  UnitDelay: '<S29>/Unit Delay1'
   */
  SWC_PCF_DW.UnitDelay_DSTATE_e = SWC_PCF_DW.UnitDelay1_DSTATE_i;

  /* Update for UnitDelay: '<S118>/Unit Delay1' */
  SWC_PCF_DW.UnitDelay1_DSTATE_b = VAR_PcfStm_stPark_u8;

  /* Update for UnitDelay: '<S118>/Unit Delay2' */
  SWC_PCF_DW.UnitDelay2_DSTATE_k = VAR_PcfStm_flgAutoP_b;

  /* Update for UnitDelay: '<S4>/Unit Delay' */
  SWC_PCF_DW.UnitDelay_DSTATE_er = VAR_PcfStm_Actime_u16;

  /* Update for UnitDelay: '<S116>/Unit Delay' */
  SWC_PCF_DW.UnitDelay_DSTATE_h = VAR_PcfSig_Pos1_f32;

  /* Update for UnitDelay: '<S4>/Unit Delay3' */
  SWC_PCF_DW.UnitDelay3_DSTATE_h = VAR_PcfStm_flgRetryFnh_b;

  /* Update for UnitDelay: '<S44>/Unit Delay' incorporates:
   *  UnitDelay: '<S44>/Unit Delay1'
   */
  SWC_PCF_DW.UnitDelay_DSTATE_n = SWC_PCF_DW.UnitDelay1_DSTATE_c;

  /* Update for UnitDelay: '<S4>/Unit Delay1' */
  SWC_PCF_DW.UnitDelay1_DSTATE_m = VAR_PcfStm_stPark_u8;

  /* Update for UnitDelay: '<S77>/Delay1' */
  SWC_PCF_DW.Delay1_DSTATE = rtb_CAL_PcfCtl_PosKp_f32;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_PCF_10ms' */

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_PCF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_PCF_10ms_sys'
   */
  /* Outport: '<Root>/PP_SWC_PCF_PCF_iPcf' incorporates:
   *  Constant: '<S8>/Constant6'
   *  Product: '<S8>/Product'
   */
  (void) Rte_Write_PP_SWC_PCF_PCF_iPcf(VAR_PcfStm_SLPosReg_f32 * 10.0F);

  /* Outport: '<Root>/PP_SWC_PCF_PCF_enMos' incorporates:
   *  DataTypeConversion: '<S70>/Data Type Conversion'
   */
  (void) Rte_Write_PP_SWC_PCF_PCF_enMos(VAR_PcfCtl_enMos_b);

  /* Outport: '<Root>/PP_SWC_PCF_PCF_flgSLWD' incorporates:
   *  Logic: '<S8>/Logical Operator'
   */
  (void) Rte_Write_PP_SWC_PCF_PCF_flgSLWD(VAR_PcfStm_SLflgPosNvm_b);

  /* Outport: '<Root>/PP_SWC_PCF_PCF_SLInPLimt' incorporates:
   *  Sum: '<S8>/Add'
   */
  (void) Rte_Write_PP_SWC_PCF_PCF_SLInPLimt(VAR_PcfStm_SLPosReg_f32);

  /* Outport: '<Root>/PP_SWC_PCF_PCF_SLEnMotorAcc' incorporates:
   *  Logic: '<S8>/Logical Operator1'
   */
  (void) Rte_Write_PP_SWC_PCF_PCF_SLEnMotorAcc(VAR_PcfStm_SLEnMotorAcc_b);

  /* Outport: '<Root>/PP_SWC_PCF_PCF_SLtrqDes' incorporates:
   *  Sum: '<S8>/Add3'
   */
  (void) Rte_Write_PP_SWC_PCF_PCF_SLtrqDes(VAR_PcfStm_SLtrqDes_f32);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_PCF_10ms' */

  /* Outport: '<Root>/PP_SWC_PCF_PCF_SLInPLimtPos' */
  (void) Rte_Write_PP_SWC_PCF_PCF_SLInPLimtPos(0.0F);
}

/* Model initialize function */
void SWC_PCF_Init(void)
{
  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_PCF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_PCF_10ms_sys'
   */
  /* SystemInitialize for Chart: '<S118>/PcfStm_State' */
  SWC_PCF_B.PcfStm_stPark = stPark_Init;
  SWC_PCF_B.PcfStm_stParkCtl = stParkCtl_Halt;

  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_PCF_10ms' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
