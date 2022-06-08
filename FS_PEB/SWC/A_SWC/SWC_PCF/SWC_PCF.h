/*
 * File: SWC_PCF.h
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

#ifndef RTW_HEADER_SWC_PCF_h_
#define RTW_HEADER_SWC_PCF_h_
#include <math.h>
#ifndef SWC_PCF_COMMON_INCLUDES_
# define SWC_PCF_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_SWC_PCF.h"
#endif                                 /* SWC_PCF_COMMON_INCLUDES_ */

#include "SWC_PCF_types.h"

/* Macros for accessing real-time model data structure */

/* Block signals (default storage) */
typedef struct tag_B_SWC_PCF_T {
  iEDS_Enum_stEPPSm_def PcfStm_stPark; /* '<S118>/PcfStm_State' */
  iEDS_Enum_stEPPCtl_def PcfStm_stParkCtl;/* '<S118>/PcfStm_State' */
  boolean PcfDia_AutoP;                /* '<S131>/AutoPJudge' */
} B_SWC_PCF_T;

/* Block states (default storage) for system '<Root>' */
typedef struct tag_DW_SWC_PCF_T {
  float64 Delay_DSTATE;                /* '<S96>/Delay' */
  float64 UnitDelay3_DSTATE;           /* '<S98>/Unit Delay3' */
  float32 UnitDelay1_DSTATE;           /* '<S98>/Unit Delay1' */
  float32 UnitDelay_DSTATE_l;          /* '<S28>/Unit Delay' */
  float32 UnitDelay1_DSTATE_g;         /* '<S28>/Unit Delay1' */
  float32 UnitDelay_DSTATE_e;          /* '<S29>/Unit Delay' */
  float32 UnitDelay1_DSTATE_i;         /* '<S29>/Unit Delay1' */
  float32 UnitDelay_DSTATE_h;          /* '<S116>/Unit Delay' */
  float32 UnitDelay_DSTATE_n;          /* '<S44>/Unit Delay' */
  float32 UnitDelay1_DSTATE_c;         /* '<S44>/Unit Delay1' */
  float32 Delay3_DSTATE;               /* '<S77>/Delay3' */
  float32 Delay2_DSTATE;               /* '<S77>/Delay2' */
  float32 Delay1_DSTATE;               /* '<S77>/Delay1' */
  float32 RetryCounter;                /* '<S64>/ErrRetry' */
  uint16 UnitDelay1_DSTATE_o;          /* '<S97>/Unit Delay1' */
  uint16 UnitDelay_DSTATE_es;          /* '<S13>/Unit Delay' */
  uint16 UnitDelay_DSTATE_er;          /* '<S4>/Unit Delay' */
  uint16 UnitDelay_DSTATE_fb;          /* '<S15>/Unit Delay' */
  uint16 UnitDelay_DSTATE_c4;          /* '<S24>/Unit Delay' */
  uint16 UnitDelay_DSTATE_fr;          /* '<S71>/Unit Delay' */
  uint16 BCActime;                     /* '<S118>/PcfStm_State' */
  uint16 SLMotorAcctime;               /* '<S118>/PcfStm_State' */
  uint16 SLActime;                     /* '<S118>/PcfStm_State' */
  uint16 SLWaitime;                    /* '<S118>/PcfStm_State' */
  uint16 cntSLWaitRun;                 /* '<S118>/PcfStm_State' */
  uint16 cntSLWaitAcc;                 /* '<S118>/PcfStm_State' */
  uint16 Pausetime;                    /* '<S64>/ErrRetry' */
  uint8 UnitDelay2_DSTATE_b;           /* '<S98>/Unit Delay2' */
  uint8 UnitDelay2_DSTATE_j;           /* '<S97>/Unit Delay2' */
  uint8 UnitDelay_DSTATE_lu;           /* '<S14>/Unit Delay' */
  uint8 UnitDelay_DSTATE_c0;           /* '<S32>/Unit Delay' */
  uint8 UnitDelay_DSTATE_n5;           /* '<S31>/Unit Delay' */
  uint8 UnitDelay1_DSTATE_b;           /* '<S118>/Unit Delay1' */
  uint8 UnitDelay_DSTATE_ns;           /* '<S45>/Unit Delay' */
  uint8 UnitDelay1_DSTATE_m;           /* '<S4>/Unit Delay1' */
  boolean UnitDelay_DSTATE_en;         /* '<S7>/Unit Delay' */
  boolean UnitDelay1_DSTATE_l;         /* '<S6>/Unit Delay1' */
  boolean UnitDelay1_DSTATE_gw;        /* '<S13>/Unit Delay1' */
  boolean UnitDelay2_DSTATE_n;         /* '<S28>/Unit Delay2' */
  boolean UnitDelay2_DSTATE_c;         /* '<S29>/Unit Delay2' */
  boolean UnitDelay2_DSTATE_e;         /* '<S20>/Unit Delay2' */
  boolean UnitDelay1_DSTATE_ld;        /* '<S20>/Unit Delay1' */
  boolean UnitDelay2_DSTATE_k;         /* '<S118>/Unit Delay2' */
  boolean UnitDelay1_DSTATE_f;         /* '<S15>/Unit Delay1' */
  boolean UnitDelay3_DSTATE_m;         /* '<S15>/Unit Delay3' */
  boolean UnitDelay3_DSTATE_h;         /* '<S4>/Unit Delay3' */
  boolean UnitDelay2_DSTATE_ld;        /* '<S44>/Unit Delay2' */
  uint8 is_active_c2_SWC_PCF;          /* '<S118>/PcfStm_State' */
  uint8 is_c2_SWC_PCF;                 /* '<S118>/PcfStm_State' */
  uint8 is_ParkControl;                /* '<S118>/PcfStm_State' */
  uint8 is_NormalParkControl;          /* '<S118>/PcfStm_State' */
  uint8 is_RetryParkControl;           /* '<S118>/PcfStm_State' */
  uint8 is_SelfLearnControl;           /* '<S118>/PcfStm_State' */
  uint8 is_BlindParkControl;           /* '<S118>/PcfStm_State' */
  uint8 SLRetryTimes;                  /* '<S118>/PcfStm_State' */
  uint8 SLRunTimes;                    /* '<S118>/PcfStm_State' */
  uint8 stActJudge;                    /* '<S118>/PcfStm_State' */
  uint8 stPosHalt;                     /* '<S118>/PcfStm_State' */
  uint8 stRetry;                       /* '<S118>/PcfStm_State' */
  uint8 is_active_c1_SWC_PCF;          /* '<S131>/AutoPJudge' */
  uint8 is_c1_SWC_PCF;                 /* '<S131>/AutoPJudge' */
  uint8 is_active_c4_SWC_PCF;          /* '<S64>/ErrRetry' */
  uint8 is_c4_SWC_PCF;                 /* '<S64>/ErrRetry' */
  boolean BCRegflgP;                   /* '<S118>/PcfStm_State' */
  boolean RegflgP;                     /* '<S118>/PcfStm_State' */
  boolean ReleaseEmcy;                 /* '<S118>/PcfStm_State' */
  boolean Retry;                       /* '<S118>/PcfStm_State' */
  boolean SLDir;                       /* '<S118>/PcfStm_State' */
  boolean backstall;                   /* '<S118>/PcfStm_State' */
  boolean dir;                         /* '<S118>/PcfStm_State' */
  boolean flgFnhorRetry;               /* '<S118>/PcfStm_State' */
  boolean flgPosJudgeFnh;              /* '<S118>/PcfStm_State' */
} DW_SWC_PCF_T;

/* Block signals (default storage) */
extern B_SWC_PCF_T SWC_PCF_B;

/* Block states (default storage) */
extern DW_SWC_PCF_T SWC_PCF_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern float32 VAR_PcfSig_Pos1_f32;    /* '<S99>/Product'
                                        * 1路位置信号
                                        */
extern float32 VAR_PcfSig_tMosPcf_f32; /* '<S112>/Add1'
                                        * Mos管温度
                                        */
extern float32 VAR_PcfSig_IsenPcf_f32; /* '<S106>/Product'
                                        * EPC工作电流
                                        */
extern float32 VAR_PcfSig_IsentMosPcf_f32;/* '<S111>/Add1' */
extern float32 VAR_PcfSig_IUBPcf_f32;  /* '<S108>/Add1' */
extern float32 VAR_PcfSig_IdcPcf_f32;  /* '<S87>/Switch' */
extern float32 VAR_PcfSig_Pos2_f32;    /* '<S100>/Product'
                                        * 2路位置信号
                                        */
extern float32 VAR_PcfSig_VehSpd_f32;  /* '<S89>/CAL_PcfSig_VehSpd_f32'
                                        * 车速信号
                                        */
extern float32 VAR_PcfSig_PosAimInP_f32;/* '<S114>/Add1'
                                         * 入P目标位置
                                         */
extern float32 VAR_PcfSig_PosAimOutP_f32;/* '<S114>/Add2'
                                          * 出P目标位置
                                          */
extern float32 VAR_PcfSig_nPcfMot_f32; /* '<S117>/Add1'
                                        * 执行器转速
                                        */
extern float32 VAR_PcfSig_VDD5Pcf_f32;
             /* '<S1>/RP_SWC_IoHwAb_ADC_BSW_VDD5PCF_IoHwAb_ADC_GetPhyVoltage' */
extern float32 VAR_PcfSig_UBRPcf_f32;
                 /* '<S1>/RP_SWC_IoHwAb_ADC_BSW_UBRPCF_IoHwAb_ADC_GetPhyVoltage'
                  * EPC工作电压
                  */
extern float32 VAR_PcfCtl_AimPosPID_f32;/* '<S74>/Merge' */
extern float32 VAR_PcfCtl_PosDif_f32;  /* '<S75>/Subtract' */
extern float32 VAR_PcfCtl_PosKp_f32;   /* '<S77>/Switch5' */
extern float32 VAR_PcfCtl_PosKi_f32;   /* '<S77>/Saturation1' */
extern float32 VAR_PcfCtl_PosKd_f32;   /* '<S77>/Switch1' */
extern float32 VAR_PcfCtl_PosPIDOut_f32;/* '<S77>/Saturation3' */
extern float32 VAR_PcfCtl_SoftDycPID_f32;/* '<S72>/Switch2' */
extern float32 VAR_PcfSig_DycLim_f32;  /* '<S113>/Saturation'
                                        * 占空比限制
                                        */
extern float32 VAR_PcfCtl_DycOutPID_f32;/* '<S72>/Product1' */
extern float32 VAR_PcfStm_SLPosReg_f32;/* '<S118>/PcfStm_State' */
extern float32 VAR_PcfStm_SLtrqDes_f32;/* '<S118>/PcfStm_State' */
extern uint16 VAR_PcfSig_TestTimes_u16;/* '<S97>/Switch1'
                                        * 出入P自动测试次数
                                        */
extern uint16 VAR_PcfStm_Actime_u16;   /* '<S118>/PcfStm_State' */
extern uint8 VAR_PcfDia_stSLActPos_u8; /* '<S22>/Merge' */
extern uint8 VAR_PcfDia_stActPos_u8;   /* '<S12>/Merge1' */
extern uint8 VAR_PcfDia_stRunTi_u8;    /* '<S23>/Merge' */
extern uint8 VAR_PcfSig_stParkCtlReq_u8;/* '<S94>/Switch' */
extern uint8 VAR_PcfDia_stUdc_u8;      /* '<S18>/Data Type Conversion'
                                        * EPC工作电压等级
                                        */
extern uint8 VAR_PcfStm_stPark_u8;     /* '<S118>/EnumToUint1' */
extern uint8 VAR_PcfStm_stParkCtl_u8;  /* '<S118>/EnumToUint2' */
extern uint8 VAR_PcfStm_BCstDiag_u8;   /* '<S118>/PcfStm_State' */
extern uint8 VAR_PcfStm_SLstDiag_u8;   /* '<S118>/PcfStm_State' */
extern uint8 VAR_PcfStm_SLstModeReq_u8;/* '<S118>/PcfStm_State' */
extern boolean VAR_PcfSig_flgP_b;      /* '<S92>/Switch'
                                        * 挡杆信号
                                        */
extern boolean VAR_PcfStm_flgActJudgeToSLRun_b;/* '<S121>/Logical Operator' */
extern boolean VAR_PcfDia_flgBCLocked_b;/* '<S13>/Switch12' */
extern boolean VAR_PcfSig_flgIoc_b;
                     /* '<S1>/RP_SWC_IoHwAb_DIO_Get_BSW_flgPcfOc_IoHwAb_DIO_Get'
                      * EPC电路过流信号
                      */
extern boolean VAR_PcfDia_flgHwIdcOv_b;/* '<S14>/Data Type Conversion1' */
extern boolean VAR_PcfDia_flgSenOv_b;  /* '<S32>/Data Type Conversion1' */
extern boolean VAR_PcfDia_flgSenVerFail_b;/* '<S31>/Data Type Conversion1' */
extern boolean VAR_PcfStm_flgBPCToFault_b;/* '<S122>/Logical Operator10' */
extern boolean VAR_PcfSig_flgKL15_b;   /* '<S104>/Switch'
                                        * KL15信号
                                        */
extern boolean VAR_PcfDia_flgCritSpd_b;/* '<S20>/Logical Operator' */
extern boolean VAR_PcfSig_flgBrake_b;  /* '<S91>/Switch'
                                        * 刹车状态信号
                                        */
extern boolean VAR_PcfSig_stDoor_b;    /* '<S95>/Switch'
                                        * 驾驶侧门状态信号
                                        */
extern boolean VAR_PcfStm_flgEnAutoInP_b;/* '<S132>/Switch' */
extern boolean VAR_PcfSig_flgACC_b;    /* '<S89>/CAL_PcfSig_flgACC_b'
                                        * 加速信号
                                        */
extern boolean VAR_PcfSig_flgPowerOn_b;/* '<S105>/Switch'
                                        * PowerOn使能信号
                                        */
extern boolean VAR_PcfStm_flgDiaAutoP_b;/* '<S131>/Switch3' */
extern boolean VAR_PcfStm_flgEnAutoOutP_b;/* '<S133>/Switch' */
extern boolean VAR_PcfStm_flgFaultToBPC_b;/* '<S122>/Logical Operator9' */
extern boolean VAR_PcfDia_flgRunTiOv_b;/* '<S53>/Compare' */
extern boolean VAR_PcfDia_flgLocked_b; /* '<S15>/Switch12' */
extern boolean VAR_PcfDia_flgRetry_b;  /* '<S66>/Switch' */
extern boolean VAR_PcfDia_VDD5PcfErr_b;/* '<S45>/Data Type Conversion1' */
extern boolean VAR_PcfDia_flgRetryShield_b;/* '<S66>/Switch1' */
extern boolean VAR_PcfDia_flgFault_b;  /* '<S61>/Switch1' */
extern boolean VAR_PcfStm_flgFaultToParkCtl_b;/* '<S126>/Logical Operator3' */
extern boolean VAR_PcfStm_flgPCInPtoRun_b;/* '<S134>/Logical Operator' */
extern boolean VAR_PcfStm_flgNPCToStandby_b;/* '<S130>/Logical Operator2' */
extern boolean VAR_PcfStm_flgNPCToRPC_b;/* '<S123>/Logical Operator12' */
extern boolean VAR_PcfStm_flgSLAccToWait_b;/* '<S129>/Relational Operator1' */
extern boolean VAR_PcfStm_flgSLCToStandby_b;/* '<S130>/Logical Operator8' */
extern boolean VAR_PcfDia_flgUdcLoErr_b;/* '<S18>/Relational Operator'
                                         * 工作电压故障
                                         */
extern boolean VAR_PcfDia_flgtMosOv_b; /* '<S24>/Relational Operator2'
                                        * Mos管过温故障
                                        */
extern boolean VAR_PcfDiag_flgselfCkFnh_b;/* '<S59>/Logical Operator2' */
extern boolean VAR_PcfSig_NVMSLFnh_b;  /* '<S115>/Switch'
                                        * 自学习完成信号
                                        */
extern boolean VAR_PcfDia_flgAimInPRat_b;/* '<S17>/Logical Operator' */
extern boolean VAR_PcfStm_flgStandbyToNPC_b;/* '<S130>/Logical Operator1' */
extern boolean VAR_PcfStm_flgStandbyToSLC_b;/* '<S130>/Logical Operator6' */
extern boolean VAR_PcfDia_flgNPCActPos_b;/* '<S21>/Relational Operator15' */
extern boolean VAR_PcfStm_flgPCInitToInP_b;/* '<S125>/Logical Operator9' */
extern boolean VAR_PcfStm_flgPCInitToOutP_b;/* '<S125>/Logical Operator3' */
extern boolean VAR_PcfCtl_enMosPID_b;  /* '<S74>/Merge1' */
extern boolean VAR_PcfCtl_enMosOutPID_b;/* '<S73>/Logical Operator' */
extern boolean VAR_PcfCtl_DirOutPID_b; /* '<S72>/Relational Operator2' */
extern boolean VAR_PcfCtl_enMos_b;     /* '<S70>/Merge' */
extern boolean VAR_PcfDia_flgAllowPwmRun_b;/* '<S58>/Logical Operator1' */
extern boolean VAR_PcfDiag_flgselfCkErr_b;/* '<S59>/Logical Operator4' */
extern boolean VAR_PcfDia_flgShtDwnReq_b;/* '<S60>/Logical Operator' */
extern boolean VAR_PcfDia_flgUnexPosWarn_b;/* '<S62>/Logical Operator' */
extern boolean VAR_PcfCtl_ActFnh_b;    /* '<S76>/Switch' */
extern boolean VAR_PcfSig_flgBelt_b;   /* '<S94>/Constant'
                                        * 安全带状态信号
                                        */
extern boolean VAR_PcfStm_BCMotDir_b;  /* '<S118>/PcfStm_State' */
extern boolean VAR_PcfStm_BCenMos_b;   /* '<S118>/PcfStm_State' */
extern boolean VAR_PcfStm_MotDir_b;    /* '<S118>/PcfStm_State' */
extern boolean VAR_PcfStm_enMos_b;     /* '<S118>/PcfStm_State' */
extern boolean VAR_PcfStm_flgRetryFnh_b;/* '<S118>/PcfStm_State' */
extern boolean VAR_PcfStm_SLActDir_b;  /* '<S118>/PcfStm_State' */
extern boolean VAR_PcfStm_SLEnMotorAcc_b;/* '<S118>/PcfStm_State' */
extern boolean VAR_PcfStm_SLenMos_b;   /* '<S118>/PcfStm_State' */
extern boolean VAR_PcfStm_BCflgModeReq_b;/* '<S118>/PcfStm_State' */
extern boolean VAR_PcfStm_SLflgPosNvm_b;/* '<S118>/PcfStm_State' */
extern boolean VAR_PcfStm_flgAutoP_b;  /* '<S118>/PcfStm_State' */
extern boolean VAR_PcfDia_flgStallFault_b;/* '<S64>/ErrRetry' */
extern boolean VAR_PcfDia_flgstallPause_b;/* '<S64>/ErrRetry' */

/* Exported data declaration */
#pragma section ".rodata.Calib_32"

/* Declaration for custom storage class: iEDS_Parameter */
extern const volatile float32 CAL_PcfCtl_BCRunDyc_f32;
                            /* Referenced by: '<S81>/CAL_PcfCtl_BCRunDyc_f32' */

/* 盲控状态下给定的固定占空比 */
extern const volatile float32 CAL_PcfCtl_InitOutP_f32;
                            /* Referenced by: '<S79>/CAL_PcfCtl_InitOutP_f32' */
extern const volatile boolean CAL_PcfCtl_ManualDir_b;
                             /* Referenced by: '<S84>/CAL_PcfCtl_ManualDir_b' */

/* 开环控制输出转动方向 */
extern const volatile float32 CAL_PcfCtl_ManualDty_f32;
                           /* Referenced by: '<S84>/CAL_PcfCtl_ManualDty_f32' */

/* 开环控制输出占空比 */
extern const volatile boolean CAL_PcfCtl_ManualEn_b;
                              /* Referenced by: '<S84>/CAL_PcfCtl_ManualEn_b' */

/* 开环控制输出Mos管使能 */
extern const volatile float32 CAL_PcfCtl_PosKd_f32;
                               /* Referenced by: '<S77>/CAL_PcfCtl_PosKd_f32' */

/* 位置式PID控制Kd值 */
extern const volatile float32 CAL_PcfCtl_PosKi_f32;
                               /* Referenced by: '<S77>/CAL_PcfCtl_PosKi_f32' */

/* 位置式PID控制Ki值 */
extern const volatile float32 CAL_PcfCtl_PosKp_f32;
                               /* Referenced by: '<S77>/CAL_PcfCtl_PosKp_f32' */

/* 位置式PID控制Kp值 */
extern const volatile float32 CAL_PcfCtl_PrePos_f32;
                              /* Referenced by: '<S71>/CAL_PcfCtl_PrePos_f32' */

/* 动作完成检测精度 */
extern const volatile boolean CAL_PcfCtl_SLRunDir_b;
                              /* Referenced by: '<S82>/CAL_PcfCtl_SLRunDir_b' */

/* 自学习状态下朝出P极限位置转动方向 */
extern const volatile float32 CAL_PcfCtl_SLRunDyc_f32;
                            /* Referenced by: '<S82>/CAL_PcfCtl_SLRunDyc_f32' */

/* 自学习状态下给定的固定占空比 */
extern const volatile float32 CAL_PcfCtl_SLdeltaAimOutP_f32;
                      /* Referenced by: '<S78>/CAL_PcfCtl_SLdeltaAimOutP_f32' */
extern const volatile float32 CAL_PcfCtl_SoftDyc_f32;
                             /* Referenced by: '<S72>/CAL_PcfCtl_SoftDyc_f32' */

/* 占空比输出延迟时间内输出的小占空比 */
extern const volatile boolean CAL_PcfCtl_flgFnhSwt_b;
                             /* Referenced by: '<S76>/CAL_PcfCtl_flgFnhSwt_b' */

/* 执行器动作完成信号标定量控制切换开关 */
extern const volatile boolean CAL_PcfCtl_flgFnh_b;
                                /* Referenced by: '<S76>/CAL_PcfCtl_flgFnh_b' */

/* 执行器动作完成信号标定量控制 */
extern const volatile boolean CAL_PcfCtl_flgManual_b;
                             /* Referenced by: '<S70>/CAL_PcfCtl_flgManual_b' */

/* 开环控制切换开关 */
extern const volatile float32 CAL_PcfCtl_intPIDdownlim_f32;/* Referenced by:
                                                            * '<S77>/Saturation1'
                                                            * '<S77>/Saturation2'
                                                            */

/* 位置PID积分输出下限阈值 */
extern const volatile float32 CAL_PcfCtl_intPIDuplim_f32;/* Referenced by:
                                                          * '<S77>/Saturation1'
                                                          * '<S77>/Saturation2'
                                                          */

/* 位置PID积分输出上限阈值 */
extern const volatile uint16 CAL_PcfCtl_timePrePos_u16;
                          /* Referenced by: '<S71>/CAL_PcfCtl_timePrePos_u16' */

/* 满足精度范围连续检测次数 */
extern const volatile float32 CAL_PcfDia_AimInPRatDown_f32;
                       /* Referenced by: '<S17>/CAL_PcfDia_AimInPRatDown_f32' */
extern const volatile float32 CAL_PcfDia_AimInPRatUp_f32;
                         /* Referenced by: '<S17>/CAL_PcfDia_AimInPRatUp_f32' */
extern const volatile float32 CAL_PcfDia_AimInPRdd_f32;
                           /* Referenced by: '<S12>/CAL_PcfDia_AimInPRdd_f32' */

/* 出P位置诊断允许余量redundancy */
extern const volatile float32 CAL_PcfDia_AimOutPRdd_f32;
                          /* Referenced by: '<S12>/CAL_PcfDia_AimOutPRdd_f32' */

/* 入P位置诊断允许余量redundancy */
extern const volatile uint16 CAL_PcfDia_BCLockedNum_u16;
                         /* Referenced by: '<S13>/CAL_PcfDia_BCLockedNum_u16' */

/* 盲控状态允许执行器转动的最大运行时间 */
extern const volatile float32 CAL_PcfDia_IdcLockedHiHyst_f32;/* Referenced by:
                                                              * '<S13>/CAL_PcfDia_IdcLockedHiHyst_f32'
                                                              * '<S15>/CAL_PcfDia_IdcLockedHiHyst_f32'
                                                              */

/* 堵转电流高限滞环阈值 */
extern const volatile float32 CAL_PcfDia_IdcLockedHi_f32;/* Referenced by:
                                                          * '<S13>/CAL_PcfDia_IdcLockedHi_f32'
                                                          * '<S15>/CAL_PcfDia_IdcLockedHi_f32'
                                                          */

/* 堵转电流高限阈值 */
extern const volatile uint16 CAL_PcfDia_LockedNum_u16;
                           /* Referenced by: '<S15>/CAL_PcfDia_LockedNum_u16' */

/* 堵转诊断次数对应堵转时间判断 */
extern const volatile float32 CAL_PcfDia_MinPosOutP_f32;
                          /* Referenced by: '<S21>/CAL_PcfDia_MinPosOutP_f32' */

/* 最小出P位置与齿顶堵转位置角度差 */
extern const volatile float32 CAL_PcfDia_PosDebounce_f32;/* Referenced by:
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
extern const volatile float32 CAL_PcfDia_PosHighset_f32;
                          /* Referenced by: '<S30>/CAL_PcfDia_PosHighset_f32' */

/* 位置传感器传输值上限阈值 */
extern const volatile float32 CAL_PcfDia_PosLowset_f32;
                           /* Referenced by: '<S30>/CAL_PcfDia_PosLowset_f32' */

/* 位置传感器传输值下限阈值 */
extern const volatile uint8 CAL_PcfDia_Retrytimes_u8;
                           /* Referenced by: '<S64>/CAL_PcfDia_Retrytimes_u8' */

/* 堵转允许重试次数 */
extern const volatile float32 CAL_PcfDia_SLInPDown_f32;
                           /* Referenced by: '<S22>/CAL_PcfDia_SLInPDown_f32' */

/* 正常入P位置下限 */
extern const volatile float32 CAL_PcfDia_SLInPLimt_f32;
                           /* Referenced by: '<S22>/CAL_PcfDia_SLInPLimt_f32' */

/* 无位置信号阈值 */
extern const volatile float32 CAL_PcfDia_SLInPUp_f32;
                             /* Referenced by: '<S22>/CAL_PcfDia_SLInPUp_f32' */

/* 正常入P位置上限 */
extern const volatile float32 CAL_PcfDia_SLOutPDown_f32;
                          /* Referenced by: '<S22>/CAL_PcfDia_SLOutPDown_f32' */

/* 正常出P位置下限 */
extern const volatile float32 CAL_PcfDia_SLOutPInit_f32;
                          /* Referenced by: '<S22>/CAL_PcfDia_SLOutPInit_f32' */

/* 执行器安装初始位置 */
extern const volatile float32 CAL_PcfDia_SLOutPUp_f32;
                            /* Referenced by: '<S22>/CAL_PcfDia_SLOutPUp_f32' */

/* 正常出P位置上限 */
extern const volatile float32 CAL_PcfDia_SpdHiHyst_f32;
                           /* Referenced by: '<S20>/CAL_PcfDia_SpdHiHyst_f32' */

/* 允许驻车车速上限滞环 */
extern const volatile float32 CAL_PcfDia_SpdHi_f32;
                               /* Referenced by: '<S20>/CAL_PcfDia_SpdHi_f32' */

/* 允许驻车车速上限 */
extern const volatile float32 CAL_PcfDia_UdcCANLowSet_f32;
                        /* Referenced by: '<S18>/CAL_PcfDia_UdcCANLowSet_f32' */

/* 电压设置值2欠压报警执行器停止工作只保持通讯 */
extern const volatile float32 CAL_PcfDia_UdcMotLowSet_f32;
                        /* Referenced by: '<S18>/CAL_PcfDia_UdcMotLowSet_f32' */

/* 电压设置值1执行器不工作 */
extern const volatile float32 CAL_PcfDia_UdcMotManSet_f32;
                        /* Referenced by: '<S18>/CAL_PcfDia_UdcMotManSet_f32' */

/* 电压设置值4执行器正常工作大于16V过压报警执行器工作 */
extern const volatile float32 CAL_PcfDia_UdcMotUVSet_f32;
                         /* Referenced by: '<S18>/CAL_PcfDia_UdcMotUVSet_f32' */

/* 电压设置值3欠压报警执行器工作 */
extern const volatile float32 CAL_PcfDia_VDD5Debounce_f32;/* Referenced by:
                                                           * '<S44>/CAL_PcfDia_VDD5Debounce_f1'
                                                           * '<S44>/CAL_PcfDia_VDD5Debounce_f2'
                                                           * '<S44>/CAL_PcfDia_VDD5Debounce_f3'
                                                           * '<S44>/CAL_PcfDia_VDD5Debounce_f32'
                                                           */

/* 位置传感器5V供电电压故障Debounce次数 */
extern const volatile float32 CAL_PcfDia_VDD5Highset_f32;
                         /* Referenced by: '<S19>/CAL_PcfDia_VDD5Highset_f32' */

/* 位置传感器5V供电电压上限阈值 */
extern const volatile float32 CAL_PcfDia_VDD5Lowset_f32;
                          /* Referenced by: '<S19>/CAL_EpcDia_VDD5Lowset_f32' */

/* 位置传感器5V供电电压下限阈值 */
extern const volatile uint16 CAL_PcfDia_cntNorAct_u16;
                           /* Referenced by: '<S23>/CAL_PcfDia_cntNorAct_u16' */

/* 执行器出入P正常运行时间 */
extern const volatile uint16 CAL_PcfDia_cntOverAct_u16;
                          /* Referenced by: '<S23>/CAL_PcfDia_cntOverAct_u16' */

/* 执行器出入P最大允许运行时间 */
extern const volatile boolean CAL_PcfDia_flgBCLockedSwt_b;
                         /* Referenced by: '<S13>/CAL_PcfDia_flgBCstallSwt_b' */
extern const volatile boolean CAL_PcfDia_flgBCLocked_b;
                            /* Referenced by: '<S13>/CAL_PcfDia_flgBCstall_b' */
extern const volatile boolean CAL_PcfDia_flgFaultSwt_b;
                           /* Referenced by: '<S61>/CAL_PcfDia_flgFaultSwt_b' */

/* EPC故障状态标定量控制切换开关 */
extern const volatile boolean CAL_PcfDia_flgFault_b;
                              /* Referenced by: '<S61>/CAL_PcfDia_flgFault_b' */

/* EPC故障状态标定量控制 */
extern const volatile boolean CAL_PcfDia_flgLocked_b;
                             /* Referenced by: '<S15>/CAL_PcfDia_flgLocked_b' */
extern const volatile boolean CAL_PcfDia_flgLockedlSwt_b;
                         /* Referenced by: '<S15>/CAL_PcfDia_flgLockedlSwt_b' */
extern const volatile boolean CAL_PcfDia_flgRetrySwt_b;
                           /* Referenced by: '<S66>/CAL_PcfDia_flgRetrySwt_b' */

/* 堵转重试标定量控制切换开关 */
extern const volatile boolean CAL_PcfDia_flgRetry_b;
                              /* Referenced by: '<S66>/CAL_PcfDia_flgRetry_b' */

/* 堵转重试标定量控制 */
extern const volatile float32 CAL_PcfDia_nMechHiHyst_f32;
                         /* Referenced by: '<S20>/CAL_PcfDia_nMechHiHyst_f32' */

/* 用电机转速判断速度阈值上限滞环 */
extern const volatile float32 CAL_PcfDia_nMechHi_f32;
                             /* Referenced by: '<S20>/CAL_PcfDia_nMechHi_f32' */

/* 用电机转速判断速度阈值上限 */
extern const volatile float32 CAL_PcfDia_nMotLockedLowHyst_f32;
                   /* Referenced by: '<S15>/CAL_PcfDia_nMotLockedLowHyst_f32' */

/* 堵转转速高限滞环阈值 */
extern const volatile float32 CAL_PcfDia_nMotLockedLow_f32;
                       /* Referenced by: '<S15>/CAL_PcfDia_nMotLockedLow_f32' */

/* 堵转转速高限阈值 */
extern const volatile float32 CAL_PcfDia_posSenHiRngSet_f32;
                     /* Referenced by: '<S30>/CAL_EPcfDia_posSenHiRngSet_f32' */

/* 两路传感器Pos值运行最大误差范围 */
extern const volatile float32 CAL_PcfDia_tMosHighSet_f32;
                         /* Referenced by: '<S24>/CAL_PcfDia_tMosHighSet_f32' */

/* MOS管温度上限值 */
extern const volatile float32 CAL_PcfDia_tMosLowSet_f32;
                          /* Referenced by: '<S24>/CAL_PcfDia_tMosLowSet_f32' */

/* MOS管温度下限值 */
extern const volatile uint16 CAL_PcfDia_tMosNum_u16;
                             /* Referenced by: '<S24>/CAL_PcfDia_tMosNum_u16' */

/* MOS管温度故障诊断次数 */
extern const volatile uint16 CAL_PcfDia_tRetry_u16;
                              /* Referenced by: '<S64>/CAL_PcfDia_tRetry_u16' */

/* 堵转重试等待时间 */
extern const volatile float32 CAL_PcfSig_AimInPLimt_f32;
                         /* Referenced by: '<S114>/CAL_PcfSig_AimInPLimt_f32' */

/* 入P极限位置标定量 */
extern const volatile float32 CAL_PcfSig_AngMotPos_f32;
                          /* Referenced by: '<S116>/CAL_PcfSig_AngMotPos_f32' */

/* 有效运行区间占整圈比例 */
extern const volatile float32 CAL_PcfSig_GernMot_f32;
                            /* Referenced by: '<S116>/CAL_PcfSig_GernMot_f32' */

/* 电机到输出端减速比 */
extern const volatile float32 CAL_PcfSig_IUBPcfFltCoe_f32;
                       /* Referenced by: '<S108>/CAL_PcfSig_IUBEpcFltCoe_f32' */
extern const volatile float32 CAL_PcfSig_IUBSet_f32;
                             /* Referenced by: '<S101>/CAL_PcfSig_IUBSet_f32' */

/* 给定电流值 */
extern const volatile float32 CAL_PcfSig_IdcDycX_Idc_af32[4];
                                      /* Referenced by: '<S113>/Idcdyc_Table' */

/* 电流限占空比查表 */
extern const volatile float32 CAL_PcfSig_IdcDycY_dyc_af32[4];
                                      /* Referenced by: '<S113>/Idcdyc_Table' */

/* 电流限占空比阈值 */
extern const volatile float32 CAL_PcfSig_PosCnvFac_f32;/* Referenced by:
                                                        * '<S99>/CAL_PcfSig_Pos2CnvFac_f32'
                                                        * '<S100>/CAL_PcfSig_PosCnvFac_f32'
                                                        */

/* EPC执行器位置信号精度系数 */
extern const volatile float32 CAL_PcfSig_PosOffset_f32;/* Referenced by:
                                                        * '<S99>/CAL_EpcSig_Pos2Offset_f32'
                                                        * '<S100>/CAL_PcfSig_PosOffset_f32'
                                                        */

/* EPC执行器位置信号偏移量系数 */
extern const volatile uint16 CAL_PcfSig_TimesTestP_u16;
                           /* Referenced by: '<S93>/CAL_PcfSig_TimesTestP_u1' */

/* 出入P自动测试次数设置 */
extern const volatile float32 CAL_PcfSig_UdcDycX_Udc_af32[20];
                                      /* Referenced by: '<S113>/Udcdyc_Table' */

/* UKL30限占空比查表 */
extern const volatile float32 CAL_PcfSig_UdcDycY_dyc_af32[20];
                                      /* Referenced by: '<S113>/Udcdyc_Table' */

/* UKL30限占空比阈值 */
extern const volatile float32 CAL_PcfSig_VehSpd_f32;
                              /* Referenced by: '<S89>/CAL_PcfSig_VehSpd_f32' */

/* 车速信号标定量给定 */
extern const volatile float32 CAL_PcfSig_deltaAimInP_f32;
                        /* Referenced by: '<S114>/CAL_PcfSig_deltaAimInP_f32' */

/* 入P目标位置与极限位置的余量 */
extern const volatile float32 CAL_PcfSig_deltaAimOutP_f32;
                       /* Referenced by: '<S114>/CAL_PcfSig_deltaAimOutP_f32' */

/* 出P位置到入P位置转动范围 */
extern const volatile float32 CAL_PcfSig_factMosFlt_f32;
                         /* Referenced by: '<S107>/CAL_PcfSig_factMosFlt_f32' */

/* Mos管温度滤波系数 */
extern const volatile boolean CAL_PcfSig_flgACC_b;
                                /* Referenced by: '<S89>/CAL_PcfSig_flgACC_b' */

/* 加速信号标定量给定 */
extern const volatile boolean CAL_PcfSig_flgAimInPLimtSwt_b;
                     /* Referenced by: '<S114>/CAL_PcfSig_flgAimInPLimtSwt_b' */

/* 入P极限位置标定量控制切换开关 */
extern const volatile boolean CAL_PcfSig_flgBrakeSwt_b;
                           /* Referenced by: '<S91>/CAL_PcfSig_flgBrakeSwt_b' */

/* 刹车信号标定量控制切换开关 */
extern const volatile uint8 CAL_PcfSig_flgBrake_u8;
                             /* Referenced by: '<S91>/CAL_PcfSig_flgBrake_u8' */

/* 刹车信号标定量控制 */
extern const volatile boolean CAL_PcfSig_flgIUBSwt_b;
                            /* Referenced by: '<S101>/CAL_PcfSig_flgIUBSwt_b' */

/* 切换使用给定电流值 */
extern const volatile boolean CAL_PcfSig_flgKL15Swt_b;
                           /* Referenced by: '<S104>/CAL_PcfSig_flgKL15Swt_b' */

/* KL15信号标定量控制切换开关 */
extern const volatile boolean CAL_PcfSig_flgKL15_b;
                              /* Referenced by: '<S104>/CAL_PcfSig_flgKL15_b' */

/* KL15信号标定量控制 */
extern const volatile boolean CAL_PcfSig_flgNVMSLFnhSwt_b;
                       /* Referenced by: '<S115>/CAL_PcfSig_flgNVMSLFnhSwt_b' */

/* NVM输出自学习完成标志位标定量控制切换开关 */
extern const volatile boolean CAL_PcfSig_flgNVMSLFnh_b;
                          /* Referenced by: '<S115>/CAL_PcfSig_flgNVMSLFnh_b' */

/* NVM输出自学习完成标志位标定量控制 */
extern const volatile boolean CAL_PcfSig_flgPSwt_b;
                              /* Referenced by: '<S92>/CAL_EpcSig_flgPSwt_b1' */

/* 挡杆P信号标定量控制切换开关 */
extern const volatile boolean CAL_PcfSig_flgP_b;
                                 /* Referenced by: '<S92>/CAL_PcfSig_flgP_b1' */

/* 挡杆P信号标定量控制 */
extern const volatile boolean CAL_PcfSig_flgPowerOnSwt_b;
                        /* Referenced by: '<S105>/CAL_PcfSig_flgPowerOnSwt_b' */

/* EPC工作电路使能信号标定量控制切换开关 */
extern const volatile boolean CAL_PcfSig_flgPowerOn_b;
                           /* Referenced by: '<S105>/CAL_PcfSig_flgPowerOn_b' */

/* EPC工作电路使能信号标定量控制 */
extern const volatile boolean CAL_PcfSig_flgTestPSwt_b;
                          /* Referenced by: '<S93>/CAL_PcfSig_flgTestPSwt_b1' */

/* 出入P自动测试切换开关 */
extern const volatile boolean CAL_PcfSig_flgUseISENorIUB_b;
                       /* Referenced by: '<S87>/CAL_PcfSig_flgUseISENorIUB_b' */
extern const volatile boolean CAL_PcfSig_flgstBeltSwt_b;
                          /* Referenced by: '<S94>/CAL_PcfSig_flgstBeltSwt_b' */

/* 驾驶侧安全带信号标定量控制切换开关 */
extern const volatile boolean CAL_PcfSig_flgstDoorSwt_b;
                          /* Referenced by: '<S95>/CAL_PcfSig_flgstDoorSwt_b' */

/* 驾驶侧门信号标定量控制切换开关 */
extern const volatile float32 CAL_PcfSig_iSENCnvFac_f32;
                         /* Referenced by: '<S106>/CAL_PcfSig_iSENCnvFac_f32' */

/* EPC工作电流AD转换系数 */
extern const volatile float32 CAL_PcfSig_iSENFltCoe_f32;
                         /* Referenced by: '<S111>/CAL_PcfSig_iSENFltCoe_f32' */

/* EPC工作电流滤波系数 */
extern const volatile float32 CAL_PcfSig_nMotFltCoe_f32;
                         /* Referenced by: '<S117>/CAL_PcfSig_nMotFltCoe_f32' */

/* 执行器电机转速滤波系数 */
extern const volatile uint8 CAL_PcfSig_stBelt_u8;
                               /* Referenced by: '<S94>/CAL_PcfSig_stBelt_u8' */

/* 驾驶侧安全带信号标定量控制 */
extern const volatile uint8 CAL_PcfSig_stDoor_u8;
                               /* Referenced by: '<S95>/CAL_PcfSig_stDoor_u8' */

/* 驾驶侧门信号标定量控制 */
extern const volatile float32 CAL_PcfSig_tDelayTestP_f32;
                          /* Referenced by: '<S93>/CAL_PcfSig_tDelayTestP_f1' */

/* 出入P自动测试延迟时间 */
extern const volatile float32 CAL_PcfSig_tMosDycX_tMos_af32[6];
                                    /* Referenced by: '<S113>/tMosdyc_Table1' */

/* Mos管温度限占空比查表 */
extern const volatile float32 CAL_PcfSig_tMosDycY_dyc_af32[6];
                                    /* Referenced by: '<S113>/tMosdyc_Table1' */

/* Mos管温度限占空比阈值 */
extern const volatile float32 CAL_PcfSig_tMosiSENcof_tCof_af32[10];
                                  /* Referenced by: '<S110>/tMosIdcCof_Table' */

/* Mos管温度电流补偿系数查表 */
extern const volatile float32 CAL_PcfSig_tMosiSENcof_tMos_af32[10];
                                  /* Referenced by: '<S110>/tMosIdcCof_Table' */

/* Mos管温度电流补偿系数阈值 */
extern const volatile float32 CAL_PcfSig_tMosiSENofs_tCof_af32[10];
                               /* Referenced by: '<S110>/tMosIdcOffset_Table' */
extern const volatile float32 CAL_PcfSig_tMosiSENofs_tMos_af32[10];
                               /* Referenced by: '<S110>/tMosIdcOffset_Table' */

/* EPC工作电流AD偏移系数 */
extern const volatile uint16 CAL_PcfStm_BCActimeLimt_u16;
                       /* Referenced by: '<S119>/CAL_PcfStm_BCActimeLimt_u16' */

/* 盲控动作时间阈值 */
extern const volatile float32 CAL_PcfStm_SLAccSpdUp_f32;
                         /* Referenced by: '<S119>/CAL_PcfStm_SLAccSpdUp_f32' */

/* 电机转动速度阈值 */
extern const volatile float32 CAL_PcfStm_SLAccTrqDes_f32;
                        /* Referenced by: '<S119>/CAL_PcfStm_SLAccTrqDes_f32' */

/* 电机转动加速扭矩 */
extern const volatile float32 CAL_PcfStm_SLActRunSpdUp_f32;
                         /* Referenced by: '<S119>/CAL_PcfStm_SLActRunUp_f32' */

/* 驻车执行器动作时最低电机速度阈值 */
extern const volatile uint16 CAL_PcfStm_SLActimeLimt_u16;
                       /* Referenced by: '<S119>/CAL_PcfStm_SLActimeLimt_u16' */

/* 执行单次标定动作时间阈值 */
extern const volatile uint16 CAL_PcfStm_SLMotorAcctimeLimt_u16;
                 /* Referenced by: '<S119>/CAL_PcfStm_SLMotorAcctimeLimt_u16' */

/* 位置标定时电机转动时间阈值 */
extern const volatile uint8 CAL_PcfStm_SLRetryTimesLimt_u8;
                    /* Referenced by: '<S119>/CAL_PcfStm_SLRetryTimesLimt_u8' */

/* 执行器标定重试次数阈值 */
extern const volatile uint8 CAL_PcfStm_SLRunTimesLimt_u8;
                      /* Referenced by: '<S119>/CAL_PcfStm_SLRunTimesLimt_u8' */

/* 执行器标定动作次数阈值 */
extern const volatile uint16 CAL_PcfStm_SLWaitimeLimt_u16;
                      /* Referenced by: '<S119>/CAL_PcfStm_SLWaitimeLimt_u16' */

/* 电机转动结束后等待电机静止时间 */
extern const volatile uint16 CAL_PcfStm_cntSLWaitRunLimt_u16;
                   /* Referenced by: '<S119>/CAL_PcfStm_cntSLWaitRunLimt_u16' */

/* 进入动作的等待时间 */
extern const volatile boolean CAL_PcfStm_flgTestPSwt_b;
                          /* Referenced by: '<S133>/CAL_PcfStm_flgTestPSwt_b' */

/* 出入P自动测试切换开关 */
extern const volatile boolean CAL_PcfStm_flgUseAutoBackP_b;
                      /* Referenced by: '<S119>/CAL_PcfStm_flgUseAutoBackP_b' */

/* 是否启用自动出入P功能 */
extern const volatile boolean CAL_PcfStm_flgUseBlindCtl_b;
                       /* Referenced by: '<S119>/CAL_PcfStm_flgUseBlindCtl_b' */

/* 是否启用盲控功能 */
extern const volatile boolean CAL_PcfStm_flgUseFaultRec_b;
                       /* Referenced by: '<S119>/CAL_PcfStm_flgUseFaultRec_b' */

/* 是否启用故障恢复功能 */
extern const volatile boolean CAL_PcfStm_flgUseRPC_b;
                            /* Referenced by: '<S119>/CAL_PcfStm_flgUseRPC_b' */

/* 是否启用堵转重试功能 */
extern const volatile boolean CAL_PcfStm_flgUseSLC_b;
                            /* Referenced by: '<S119>/CAL_PcfStm_flgUseSLC_b' */

/* 是否启用位置自学习功能 */
#pragma section

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S38>/Add' : Unused code path elimination
 * Block '<S38>/Constant' : Unused code path elimination
 * Block '<S57>/Add' : Unused code path elimination
 * Block '<S57>/Constant' : Unused code path elimination
 * Block '<S91>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S92>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S94>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S95>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S99>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S100>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S101>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S102>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S103>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S104>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S105>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S106>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S107>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S114>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S115>/Data Type Conversion' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SWC_PCF'
 * '<S1>'   : 'SWC_PCF/RE_SWC_PCF_10ms_sys'
 * '<S2>'   : 'SWC_PCF/RE_SWC_PCF_Init'
 * '<S3>'   : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms'
 * '<S4>'   : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis'
 * '<S5>'   : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_PWMControl'
 * '<S6>'   : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess'
 * '<S7>'   : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_StateManagement'
 * '<S8>'   : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/SignalOutPut'
 * '<S9>'   : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag'
 * '<S10>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis'
 * '<S11>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Compound_Diagnosis'
 * '<S12>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/ActorPosDiag'
 * '<S13>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/BlindCtlStallDiag'
 * '<S14>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/IocDiag'
 * '<S15>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/NormalStallDiag'
 * '<S16>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/SenDemDiag'
 * '<S17>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/Subsystem'
 * '<S18>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/UdcDiag'
 * '<S19>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/VDD5VDiag'
 * '<S20>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/flgCritSpdDiag'
 * '<S21>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/flgNPCActPosDiag'
 * '<S22>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/stSLActPosDiag'
 * '<S23>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/tActDiag'
 * '<S24>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/tMosDiag'
 * '<S25>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/ActorPosDiag/If Action Subsystem'
 * '<S26>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/ActorPosDiag/If Action Subsystem1'
 * '<S27>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/ActorPosDiag/If Action Subsystem2'
 * '<S28>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/SenDemDiag/Debounce1'
 * '<S29>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/SenDemDiag/Debounce2'
 * '<S30>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/SenDemDiag/PosDiag'
 * '<S31>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/SenDemDiag/latch1'
 * '<S32>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/SenDemDiag/latch2'
 * '<S33>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/UdcDiag/If Action Subsystem'
 * '<S34>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/UdcDiag/If Action Subsystem1'
 * '<S35>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/UdcDiag/If Action Subsystem2'
 * '<S36>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/UdcDiag/If Action Subsystem3'
 * '<S37>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/UdcDiag/If Action Subsystem4'
 * '<S38>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/UdcDiag/Terminator_u8'
 * '<S39>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/UdcDiag/If Action Subsystem/Enumerated Constant'
 * '<S40>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/UdcDiag/If Action Subsystem1/Enumerated Constant'
 * '<S41>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/UdcDiag/If Action Subsystem2/Enumerated Constant'
 * '<S42>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/UdcDiag/If Action Subsystem3/Enumerated Constant'
 * '<S43>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/UdcDiag/If Action Subsystem4/Enumerated Constant'
 * '<S44>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/VDD5VDiag/Debounce2'
 * '<S45>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/VDD5VDiag/latch1'
 * '<S46>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/stSLActPosDiag/If Action Subsystem'
 * '<S47>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/stSLActPosDiag/If Action Subsystem1'
 * '<S48>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/stSLActPosDiag/If Action Subsystem2'
 * '<S49>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/stSLActPosDiag/If Action Subsystem3'
 * '<S50>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/stSLActPosDiag/If Action Subsystem4'
 * '<S51>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/stSLActPosDiag/If Action Subsystem5'
 * '<S52>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/stSLActPosDiag/If Action Subsystem6'
 * '<S53>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/tActDiag/Compare To Constant'
 * '<S54>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/tActDiag/If Action Subsystem'
 * '<S55>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/tActDiag/If Action Subsystem1'
 * '<S56>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/tActDiag/If Action Subsystem2'
 * '<S57>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Basic_Diagnosis/tActDiag/Terminator_u1'
 * '<S58>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Compound_Diagnosis/AllowPwmRunDiag'
 * '<S59>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Compound_Diagnosis/CheckSelfDiag'
 * '<S60>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Compound_Diagnosis/DwnReqDiag'
 * '<S61>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Compound_Diagnosis/FaultDiag'
 * '<S62>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Compound_Diagnosis/PosErrDiag'
 * '<S63>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Compound_Diagnosis/RetryDiag'
 * '<S64>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Compound_Diagnosis/StallRetry'
 * '<S65>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Compound_Diagnosis/RetryDiag/Subsystem'
 * '<S66>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Compound_Diagnosis/RetryDiag/Swt'
 * '<S67>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_Diagnosis/PCF_Diag/Compound_Diagnosis/StallRetry/ErrRetry'
 * '<S68>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_PWMControl/PcfCtl_MotorControl'
 * '<S69>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_PWMControl/PcfCtl_MotorControl/PcfCtl_Ctl'
 * '<S70>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_PWMControl/PcfCtl_MotorControl/PcfCtl_Swt'
 * '<S71>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_PWMControl/PcfCtl_MotorControl/PcfCtl_Ctl/Act_Fin'
 * '<S72>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_PWMControl/PcfCtl_MotorControl/PcfCtl_Ctl/DycProcess'
 * '<S73>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_PWMControl/PcfCtl_MotorControl/PcfCtl_Ctl/PID_Enable'
 * '<S74>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_PWMControl/PcfCtl_MotorControl/PcfCtl_Ctl/PcfCtl_enMosandAimPos'
 * '<S75>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_PWMControl/PcfCtl_MotorControl/PcfCtl_Ctl/Ref'
 * '<S76>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_PWMControl/PcfCtl_MotorControl/PcfCtl_Ctl/Swt'
 * '<S77>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_PWMControl/PcfCtl_MotorControl/PcfCtl_Ctl/posititional_PID'
 * '<S78>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_PWMControl/PcfCtl_MotorControl/PcfCtl_Ctl/PcfCtl_enMosandAimPos/If Action Subsystem'
 * '<S79>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_PWMControl/PcfCtl_MotorControl/PcfCtl_Ctl/PcfCtl_enMosandAimPos/If Action Subsystem1'
 * '<S80>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_PWMControl/PcfCtl_MotorControl/PcfCtl_Ctl/PcfCtl_enMosandAimPos/If Action Subsystem2'
 * '<S81>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_PWMControl/PcfCtl_MotorControl/PcfCtl_Swt/If Action Subsystem'
 * '<S82>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_PWMControl/PcfCtl_MotorControl/PcfCtl_Swt/If Action Subsystem1'
 * '<S83>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_PWMControl/PcfCtl_MotorControl/PcfCtl_Swt/If Action Subsystem2'
 * '<S84>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_PWMControl/PcfCtl_MotorControl/PcfCtl_Swt/If Action Subsystem4'
 * '<S85>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig'
 * '<S86>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_001'
 * '<S87>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_002'
 * '<S88>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_003'
 * '<S89>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_001/Pending_signal'
 * '<S90>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_001/VCU_signal'
 * '<S91>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_001/VCU_signal/flgBrake'
 * '<S92>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_001/VCU_signal/flgP'
 * '<S93>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_001/VCU_signal/flgP_In'
 * '<S94>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_001/VCU_signal/stBelt'
 * '<S95>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_001/VCU_signal/stDoor'
 * '<S96>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_001/VCU_signal/flgP_In/Status_flgP'
 * '<S97>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_001/VCU_signal/flgP_In/TimesCalc'
 * '<S98>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_001/VCU_signal/flgP_In/change_Delay'
 * '<S99>'  : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_002/EpcPos1'
 * '<S100>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_002/EpcPos2'
 * '<S101>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_002/IUBEpc'
 * '<S102>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_002/UBREpc'
 * '<S103>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_002/VDD5Epc'
 * '<S104>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_002/flgKL15'
 * '<S105>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_002/flgPowerOn'
 * '<S106>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_002/iEpc'
 * '<S107>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_002/tEpc'
 * '<S108>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_002/IUBEpc/flt1'
 * '<S109>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_002/iEpc/Subsystem'
 * '<S110>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_002/iEpc/Subsystem1'
 * '<S111>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_002/iEpc/Subsystem/flt1'
 * '<S112>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_002/tEpc/flt'
 * '<S113>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_003/DycLim'
 * '<S114>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_003/NVMAimOutP'
 * '<S115>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_003/NVMSLFnh'
 * '<S116>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_003/nMotCalc'
 * '<S117>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_SignalProcess/PCF_Sig/PcfSig_003/nMotCalc/flt1'
 * '<S118>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_StateManagement/Pcf_Stm'
 * '<S119>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_StateManagement/Pcf_Stm/PcfStm_Judgment'
 * '<S120>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_StateManagement/Pcf_Stm/PcfStm_State'
 * '<S121>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_StateManagement/Pcf_Stm/PcfStm_Judgment/ActJudgeToSLRun'
 * '<S122>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_StateManagement/Pcf_Stm/PcfStm_Judgment/FaultToBPC'
 * '<S123>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_StateManagement/Pcf_Stm/PcfStm_Judgment/NPCToRPC'
 * '<S124>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_StateManagement/Pcf_Stm/PcfStm_Judgment/PCInPorOutPToRun'
 * '<S125>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_StateManagement/Pcf_Stm/PcfStm_Judgment/PCInitToInPorOutP'
 * '<S126>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_StateManagement/Pcf_Stm/PcfStm_Judgment/ParkToFault'
 * '<S127>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_StateManagement/Pcf_Stm/PcfStm_Judgment/Power_ONorOFF'
 * '<S128>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_StateManagement/Pcf_Stm/PcfStm_Judgment/RCInPorOutP'
 * '<S129>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_StateManagement/Pcf_Stm/PcfStm_Judgment/SLAccToWait'
 * '<S130>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_StateManagement/Pcf_Stm/PcfStm_Judgment/StndbyToSLCorNPC'
 * '<S131>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_StateManagement/Pcf_Stm/PcfStm_Judgment/PCInPorOutPToRun/DiaAutoP'
 * '<S132>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_StateManagement/Pcf_Stm/PcfStm_Judgment/PCInPorOutPToRun/EnAutoInP'
 * '<S133>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_StateManagement/Pcf_Stm/PcfStm_Judgment/PCInPorOutPToRun/EnAutoOutP'
 * '<S134>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_StateManagement/Pcf_Stm/PcfStm_Judgment/PCInPorOutPToRun/InPtoRun'
 * '<S135>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_StateManagement/Pcf_Stm/PcfStm_Judgment/PCInPorOutPToRun/DiaAutoP/AutoPJudge'
 * '<S136>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_StateManagement/Pcf_Stm/PcfStm_Judgment/PCInPorOutPToRun/DiaAutoP/stPCF_InP'
 * '<S137>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_StateManagement/Pcf_Stm/PcfStm_Judgment/PCInPorOutPToRun/EnAutoInP/If Action Subsystem'
 * '<S138>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/PCF_StateManagement/Pcf_Stm/PcfStm_Judgment/PCInPorOutPToRun/EnAutoInP/If Action Subsystem1'
 * '<S139>' : 'SWC_PCF/RE_SWC_PCF_10ms_sys/PCF_10ms/SignalOutPut/Subsystem'
 */
#endif                                 /* RTW_HEADER_SWC_PCF_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
