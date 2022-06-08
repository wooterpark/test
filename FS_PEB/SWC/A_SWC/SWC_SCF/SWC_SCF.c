/*
 * File: SWC_SCF.c
 *
 * Code generated for Simulink model 'SWC_SCF'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Jan 20 16:15:29 2021
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWC_SCF.h"
#include "SWC_SCF_private.h"

/* Named constants for Chart: '<S3>/SCF_stSysDrvCtl_Switch' */
#define SWC_SCF_IN_Discha_End          ((uint8)1U)
#define SWC_SCF_IN_Discha_HW           ((uint8)1U)
#define SWC_SCF_IN_Discha_Inlit        ((uint8)2U)
#define SWC_SCF_IN_Discha_Outime       ((uint8)2U)
#define SWC_SCF_IN_Discha_Start        ((uint8)3U)
#define SWC_SCF_IN_Discharge           ((uint8)1U)
#define SWC_SCF_IN_Drive               ((uint8)1U)
#define SWC_SCF_IN_EparkCal            ((uint8)1U)
#define SWC_SCF_IN_Fault               ((uint8)2U)
#define SWC_SCF_IN_IdLe                ((uint8)2U)
#define SWC_SCF_IN_LowPower_SetUp      ((uint8)1U)
#define SWC_SCF_IN_Normal              ((uint8)2U)
#define SWC_SCF_IN_OfstCal             ((uint8)3U)
#define SWC_SCF_IN_PostDrive           ((uint8)3U)
#define SWC_SCF_IN_PreDrive            ((uint8)4U)
#define SWC_SCF_IN_PreDriveFish        ((uint8)1U)
#define SWC_SCF_IN_PreDriveInitial     ((uint8)2U)
#define SWC_SCF_IN_PreDriveRun         ((uint8)3U)
#define SWC_SCF_IN_Run                 ((uint8)4U)
#define SWC_SCF_IN_SLCalAcc            ((uint8)1U)
#define SWC_SCF_IN_SLCalFw             ((uint8)2U)
#define SWC_SCF_IN_SLCalInit           ((uint8)3U)
#define SWC_SCF_IN_SensCalFW           ((uint8)2U)
#define SWC_SCF_IN_ShelfCheck          ((uint8)3U)
#define SWC_SCF_IN_ShutDown            ((uint8)5U)
#define SWC_SCF_IN_Standby             ((uint8)5U)
#define SWC_SCF_IN_alOffsetAcc         ((uint8)1U)
#define SWC_SCF_IN_alOffsetFw          ((uint8)2U)
#define SWC_SCF_IN_alOffsetInit        ((uint8)3U)
#define SWC_SCF_IN_iMMO                ((uint8)4U)
#define SWC_SCF_IN_wait                ((uint8)4U)

/* Exported block signals */
float32 VAR_Scf_DischaBeginUdc_f32;    /* '<S19>/Switch' */
float32 VAR_Scf_DisChaUdcAfterDebounce_f32;/* '<S19>/Switch2' */
uint8 VAR_Scf_flgShutDwnOvtimErr_u8;   /* '<S48>/Switch3'
                                        * 数据存储超时失败下电超时故障标志
                                        */
uint8 VAR_Scf_DchaCntAdd_u8;           /* '<S20>/Add2' */
uint8 VAR_Scf_DEMRunToDisChaFail_u8;   /* '<S19>/Data Type Conversion' */
boolean VAR_Scf_flgTranPreDrvToDrv_b;  /* '<S46>/Switch'
                                        * PreDrive模式跳转Drv模式使能
                                        */
boolean VAR_Scf_flgFimVCUComErr_b;
                     /* '<S1>/RP_SWC_FIM_VCUComTimeOut_GetFunctionPermission' */
boolean VAR_Scf_flgShtDwnByMcu_b;      /* '<S56>/Logical Operator4' */
boolean VAR_Scf_VCUComErr_b;           /* '<S11>/Switch2'
                                        * 最终使用的VCU通讯故障标志
                                        */
boolean VAR_Scf_flgShtDwnByVcu_b;      /* '<S55>/Switch5' */
boolean VAR_Scf_flgPostDrvReqWiDcha_b; /* '<S55>/Switch1'
                                        * 有主动放电时Drv进入PostDrv使能
                                        */
boolean VAR_Scf_flgPostDrvReqWoDcha_b; /* '<S57>/Logical Operator5'
                                        * 无主动放电时Drv进入PostDrv使能
                                        */
boolean VAR_Scf_flgTranDrvToPostDrv_b; /* '<S55>/Switch'
                                        * Drv模式跳转PostDrv模式使能
                                        */
boolean VAR_Scf_flgTranPreDrvToPostDrv_b;/* '<S47>/Logical Operator3'
                                          * PreDrv模式跳转PostDrv模式使能
                                          */
boolean VAR_Scf_flgFimFaultLvFour_b;
                    /* '<S1>/RP_SWC_FIM_flgFaultLvFour_GetFunctionPermission' */
boolean VAR_Scf_flgFimFaultLvFive_b;
                    /* '<S1>/RP_SWC_FIM_flgFaultLvFive_GetFunctionPermission' */
boolean VAR_Scf_flgTranPostDrvToPreDrv_b;/* '<S63>/Logical Operator2'
                                          * PostDrv模式跳转PreDrv模式使能
                                          */
boolean VAR_Scf_flgFimReqFailr_b;
                       /* '<S1>/RP_SWC_FIM_ReqFailrMod_GetFunctionPermission' */
boolean VAR_Scf_flgTranPreDrvToFault_b;/* '<S64>/Logical Operator1'
                                        * PreDrv模式跳转Fault模式使能
                                        */
boolean VAR_Scf_flgFimDchaFailr_b;
                      /* '<S1>/RP_SWC_FIM_flgDchaFailr_GetFunctionPermission' */
boolean VAR_Scf_flgEmgReqInvDcha_b;    /* '<S13>/Switch' */
boolean VAR_Scf_flgTranDrvToFault_b;   /* '<S53>/Logical Operator3'
                                        * Drv模式跳转Fault模式使能
                                        */
boolean VAR_Scf_flgDchaVcuReq_b;       /* '<S16>/Logical Operator2' */
boolean VAR_Scf_nDchaAllw_b;           /* '<S15>/Relational Operator' */
boolean VAR_Scf_cntSigFit_b;           /* '<S18>/Relational Operator3' */
boolean VAR_Scf_flgVCUComErrDelay_b;   /* '<S17>/Relational Operator' */
boolean VAR_Scf_DisChaDetec_b;         /* '<S13>/Switch1' */
boolean VAR_Scf_flgReqInvDcha_b;       /* '<S13>/Switch2' */
boolean VAR_Scf_flgTranFaultToDcha_b;  /* '<S54>/Logical Operator2'
                                        * Fault模式跳转Dcha模式使能
                                        */
boolean VAR_Scf_flgTranFaultToPostDrv_b;/* '<S59>/Switch'
                                         * Fault模式跳转PostDrv模式使能
                                         */
boolean VAR_Scf_flgInitOut_b;          /* '<S50>/Logical Operator' */
boolean VAR_Scf_flgWakeNormal_b;       /* '<S44>/Logical Operator1' */
boolean VAR_Scf_flgNoWakeSou_b;        /* '<S51>/Relational Operator1' */
boolean VAR_Scf_flgWakeLoss_b;         /* '<S44>/Logical Operator5' */
boolean VAR_Scf_flgPostDrvDone_b;      /* '<S44>/Logical Operator3' */
boolean VAR_Scf_flgTranPostDrvToSutDwn_b;/* '<S45>/Logical Operator'
                                          * PostDrv模式跳转ShutDown模式使能
                                          */
boolean VAR_Scf_flgTranLoPowSetToDia_b;/* '<S34>/Logical Operator' */
boolean VAR_Scf_flgTranDiagToSenCal_b; /* '<S33>/Logical Operator' */
boolean VAR_Scf_flgTranSenCalToiMMO_b; /* '<S36>/Relational Operator' */
boolean VAR_Scf_flgTranPreDrvRunToFish_b;/* '<S35>/Relational Operator' */
boolean VAR_Scf_flgTranIdleToStb_b;    /* '<S25>/Logical Operator'
                                        * Idle状态跳转Standby状态使能
                                        */
boolean VAR_Scf_flgTranStbToIdle_b;    /* '<S30>/Relational Operator'
                                        * Standby状态跳转Idle状态使能
                                        */
boolean VAR_Scf_flgTranStbToRun_b;     /* '<S32>/Logical Operator'
                                        * Standby状态跳转Run状态使能
                                        */
boolean VAR_Scf_flgTranRunToStb_b;     /* '<S28>/Switch'
                                        * Run状态跳转Standby状态使能
                                        */
boolean VAR_Scf_flgTranStbToOfstCal_b; /* '<S31>/Relational Operator'
                                        * Standby状态跳转OfstCal状态使能
                                        */
boolean VAR_Scf_flgTranOfstCalToStb_b; /* '<S27>/Relational Operator'
                                        * OfstCal状态跳转Standby状态使能
                                        */
boolean VAR_Scf_flgTranNormalToDcha_b; /* '<S26>/Logical Operator'
                                        * Normal状态跳转Dischage状态使能
                                        */
boolean VAR_Scf_flgTranDchaToNormal_b; /* '<S24>/Logical Operator2'
                                        * Dischage状态跳转Normal状态使能
                                        */
boolean VAR_Scf_flgTranStbToSLCal_b;   /* '<S29>/Logical Operator' */
boolean VAR_Scf_flgTranSLCalToStb_b;   /* '<S29>/Logical Operator1' */
boolean VAR_Scf_flgTranSLInitToSLAcc_b;/* '<S29>/Logical Operator2' */
boolean VAR_Scf_flgTranSLInitToSLFw_b; /* '<S29>/Logical Operator3' */
boolean VAR_Scf_uDcLnkDiffUnLo_b;      /* '<S19>/Relational Operator5' */
boolean VAR_Scf_flgFimforFR_b;
                     /* '<S1>/RP_SWC_FIM_FiM_FlagforFR_GetFunctionPermission' */
boolean Var_Scf_flgDisChgFail_b;       /* '<S3>/SCF_stSysDrvCtl_Switch' */
boolean VAR_Scf_flgbt15first_b;        /* '<S49>/HSPF_bt15' */

/* Exported data definition */
#pragma section ".rodata.Calib_32"

/* Definition for custom storage class: iEDS_Parameter */
const volatile boolean CAL_SCF_flgUseSLCal_b = 0;
                              /* Referenced by: '<S29>/CAL_SCF_flgUseSLCal_b' */
const volatile boolean CAL_Scf_EmgDchabysiglordoubSwt_b = 1;
                /* Referenced by: '<S21>/CAL_Smgsys_EmgDchabysiglordoubSwt_b' */
const volatile uint8 CAL_Scf_FFActionArea2_u8 = 2U;
                           /* Referenced by: '<S66>/CAL_Scf_FFActionArea2_u8' */
const volatile uint8 CAL_Scf_FFActionArea3_u8 = 3U;
                           /* Referenced by: '<S66>/CAL_Scf_FFActionArea3_u8' */
const volatile uint8 CAL_Scf_FFActionDisab_u8 = 0U;
                           /* Referenced by: '<S66>/CAL_Scf_FFActionDisab_u8' */
const volatile float32 CAL_Scf_FLOATZERO_f32 = 2.0F;/* Referenced by:
                                                     * '<S33>/CAL_Scf_FLOATZERO_f32'
                                                     * '<S34>/CAL_Scf_FLOATZERO_f32'
                                                     */

/* 浮点零 */
const volatile boolean CAL_Scf_IntDchaSwt_b = 1;/* Referenced by:
                                                 * '<S55>/CAL_Scf_IntDchaSwt_b'
                                                 * '<S59>/CAL_Scf_IntDchaSwt_b'
                                                 */
const volatile uint8 CAL_Scf_LowPwrSetUpErr_u8 = 2U;
                          /* Referenced by: '<S64>/CAL_Scf_LowPwrSetUpErr_u8' */
const volatile uint8 CAL_Scf_LowPwrSetUpSud_u8 = 1U;
                          /* Referenced by: '<S34>/CAL_Scf_LowPwrSetUpSud_u8' */
const volatile uint8 CAL_Scf_SenChkErr_u8 = 3U;
                               /* Referenced by: '<S64>/CAL_Scf_SenChkErr_u8' */

/* 传感器标定失败状态 */
const volatile uint8 CAL_Scf_SenChkSud_u8 = 2U;/* Referenced by:
                                                * '<S35>/CAL_Scf_SenChkSud_u8'
                                                * '<S36>/CAL_Scf_SenChkSud_u8'
                                                */

/* 传感器标定成功状态 */
const volatile boolean CAL_Scf_ShtDwnReqByVcuSwt_b = 0;/* Referenced by:
                                                        * '<S46>/CAL_Scf_ShtDwnReqByVcuSwt_b'
                                                        * '<S55>/CAL_Scf_ShtDwnReqByVcuSwt_b'
                                                        * '<S59>/CAL_Scf_ShtDwnReqByVcuSwt_b'
                                                        */
const volatile uint8 CAL_Scf_StandbyVcuReq_u8 = 3U;
                           /* Referenced by: '<S63>/CAL_Scf_StandbyVcuReq_u8' */
const volatile uint8 CAL_Scf_ThreRuntoDischaFail_u8 = 20U;
                     /* Referenced by: '<S20>/CAL_Scf_ThreRuntoDischaFail_u8' */
const volatile float32 CAL_Scf_UdcLnkAbsDiffLim_f32 = 100.0F;
                    /* Referenced by: '<S19>/CAL_SmgSys_UdcLnkAbsDiffLim_f32' */
const volatile uint8 CAL_Scf_WithoutStatorCurrent_u8 = 0U;
                    /* Referenced by: '<S33>/CAL_Scf_WithoutStatorCurrent_u8' */

/* 无定子电流 */
const volatile uint8 CAL_Scf_cntDchaSigFit_u8 = 2U;/* Referenced by:
                                                    * '<S18>/CAL_SmgSys_cntDchaSigFit_u8'
                                                    * '<S22>/CAL_SmgSys_cntDchaSigFit_u8'
                                                    */
const volatile uint16 CAL_Scf_cntDisChgEnd_u16 = 300U;
                              /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */

/* 硬件放电结束时间计数器 */
const volatile uint16 CAL_Scf_cntDisChgOvTi_u16 = 200U;
                              /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */

/* 硬件放电超时计数器 */
const volatile uint16 CAL_Scf_cntPostDrvDone_u16 = 200U;
                      /* Referenced by: '<S48>/CAL_SmgSys_cntPostDrvDone_u16' */

/* PostDrive到PreDrv延时计数 */
const volatile uint16 CAL_Scf_cntVCUComErrLim_u16 = 200U;/* Referenced by:
                                                          * '<S17>/CAL_Scf_cntVCUComErrLim_u16'
                                                          * '<S58>/CAL_Scf_cntVCUComErrLim_u16'
                                                          * '<S62>/CAL_Scf_cntVCUComErrLim_u16'
                                                          */

/* VCU通信超时计数 */
const volatile uint16 CAL_Scf_cntWakeLoss_u16 = 100U;
                         /* Referenced by: '<S51>/CAL_SmgSys_cntWakeLoss_u16' */
const volatile float32 CAL_Scf_curSenChgToDrv_f32 = 50.0F;
                                     /* Referenced by: '<S10>/uDc_Spd_Is_Swt' */

/* 进入Drive模式的定子电流标定量 */
const volatile float32 CAL_Scf_curSenChgToPostDrv_f32 = 10.0F;
                                     /* Referenced by: '<S10>/uDc_Spd_Is_Swt' */

/* 跳出Drive模式的定子电流标定量 */
const volatile boolean CAL_Scf_flgActvSubNSwt_b = 0;
                        /* Referenced by: '<S43>/CAL_SmgSys_flgActvSubNSwt_b' */

/* Debug模式选择；1表示Dug,0表示非Dug */
const volatile boolean CAL_Scf_flgActvSubUSwt_b = 0;
                        /* Referenced by: '<S43>/CAL_SmgSys_flgActvSubUSwt_b' */

/* Debug模式选择；1表示Dug,0表示非Dug */
const volatile boolean CAL_Scf_flgActvSubisSwt_b = 0;
                       /* Referenced by: '<S43>/CAL_SmgSys_flgActvSubisSwt_b' */

/* Debug模式选择；1表示Dug,0表示非Dug */
const volatile boolean CAL_Scf_flgCanNmSwt_b = 1;
                              /* Referenced by: '<S45>/CAL_Scf_flgCanNmSwt_b' */
const volatile boolean CAL_Scf_flgDisChgReqSwt_b = 1;
                          /* Referenced by: '<S13>/CAL_Scf_flgDisChgReqSwt_b' */
const volatile boolean CAL_Scf_flgDrvToPostWihDisSwt_b = 1;/* Referenced by:
                                                            * '<S56>/CAL_Scf_flgDrvToPostWihDisSwt_b'
                                                            * '<S60>/CAL_Scf_flgDrvToPostWihDisSwt_b'
                                                            */
const volatile boolean CAL_Scf_flgEmgDisChgReqSwt_b = 1;
                       /* Referenced by: '<S13>/CAL_Scf_flgEmgDisChgReqSwt_b' */
const volatile boolean CAL_Scf_flgEpcShutdownSwt_b = 1;
                        /* Referenced by: '<S45>/CAL_Scf_flgEpcShutdownSwt_b' */
const volatile boolean CAL_Scf_flgIntVcuComErr_b = 0;
                       /* Referenced by: '<S11>/CAL_SmgSys_flgIntVcuComErr_b' */
const volatile boolean CAL_Scf_flgIntVcuComSwt_b = 1;
                       /* Referenced by: '<S11>/CAL_SmgSys_flgIntVcuComSwt_b' */
const volatile boolean CAL_Scf_flgJumpRunBy15Swt_b = 0;
                        /* Referenced by: '<S28>/CAL_Scf_flgJumpRunBy15Swt_b' */
const volatile boolean CAL_Scf_flgOfsClbSwt_b = 0;/* Referenced by: '<S32>/Constant' */
const volatile boolean CAL_Scf_flgPcfAllowPwmRunSwt_b = 0;/* Referenced by: '<S32>/Constant2' */
const volatile float32 CAL_Scf_iSubSttrisVal_f32 = 5.0F;
                       /* Referenced by: '<S43>/CAL_SmgSys_iSubSttrisVal_f32' */

/* 进Drive模式定子电流标定量 */
const volatile float32 CAL_Scf_nAllwPwrDcha_f32 = 50.0F;/* Referenced by:
                                                         * '<S15>/CAL_SmgSys_nAllwPwrDcha_f32'
                                                         * '<S16>/CAL_Scf_nAllwPwrDcha_f32'
                                                         */
const volatile float32 CAL_Scf_nPsmThresToDrv_f32 = 500.0F;
                                     /* Referenced by: '<S10>/uDc_Spd_Is_Swt' */

/* 进入Drive模式的转速标定量 */
const volatile float32 CAL_Scf_nPsmThresToPostDrv_f32 = 50.0F;
                                     /* Referenced by: '<S10>/uDc_Spd_Is_Swt' */

/* 跳出Drive模式进PostDrive的转速标定量 */
const volatile float32 CAL_Scf_nRunTostb_f32 = 4000.0F;
                              /* Referenced by: '<S28>/CAL_Scf_nRunTostb_f32' */

/* 从run退出到Standby的速度阈值 */
const volatile float32 CAL_Scf_nSafeLoSpdMaxLim_f32 = 20.0F;
                              /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */

/* 最低的安全转速限制进Free自动模式 */
const volatile float32 CAL_Scf_nSafeLoSpdMinLim_f32 = 5.0F;
                              /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */

/* 最低的安全转速限制进ASC */
const volatile float32 CAL_Scf_nSafeMaxLim_f32 = 50.0F;
                              /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */

/* 大于该转速进ASC */
const volatile float32 CAL_Scf_nSafeMinLim_f32 = 20.0F;
                              /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */

/* 小于该转速进Free模式 */
const volatile float32 CAL_Scf_nSafeTestMaxLim_f32 = 2000.0F;
                              /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */

/* TestBanch进开管速度值 */
const volatile float32 CAL_Scf_nSafeTestMinLim_f32 = 1500.0F;
                              /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */

/* TestBanch进关管速度值 */
const volatile float32 CAL_Scf_nSnsrClbFw_f32 = 20.0F;/* Referenced by:
                                                       * '<S33>/CAL_SmgSys_nSnsrClbFw_f32'
                                                       * '<S34>/CAL_Scf_nSnsrClbFw_f32'
                                                       */

/* 进SensCalFW电机转速标定量 */
const volatile float32 CAL_Scf_nSubPsmSpdVal_f32 = 50.0F;
                       /* Referenced by: '<S43>/CAL_SmgSys_nSubPsmSpdVal_f32' */

/* 进Drive模式电机转速标定量 */
const volatile float32 CAL_Scf_uAllwPwrDcha_f32 = 60.0F;/* Referenced by:
                                                         * '<S15>/CAL_SmgSys_uAllwPwrDcha_f32'
                                                         * '<S16>/CAL_SmgSys_uAllwPwrDcha_f32'
                                                         */
const volatile float32 CAL_Scf_uDisChgEnd_f32 = 50.0F;
                              /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */

/* 主动放电结束电压标定量 */
const volatile float32 CAL_Scf_uDisChgOutTim_f32 = 60.0F;
                              /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */

/* 放电超时电压判断 */
const volatile float32 CAL_Scf_uSafeVolt_f32 = 60.0F;
                              /* Referenced by: '<S24>/CAL_Scf_uSafeVolt_f32' */
const volatile float32 CAL_Scf_uSubHiVoltVal_f32 = 10.0F;
                       /* Referenced by: '<S43>/CAL_SmgSys_uSubHiVoltVal_f32' */

/* 进Drive模式母线电压标定量 */
const volatile float32 CAL_Scf_uTnetHysToDrv_f32 = 100.0F;
                                     /* Referenced by: '<S10>/uDc_Spd_Is_Swt' */

/* 进入Drive模式的电压标定量 */
const volatile float32 CAL_Scf_uTnetHysToPostDrv_f32 = 45.0F;
                                     /* Referenced by: '<S10>/uDc_Spd_Is_Swt' */

/* 跳出Drive模式进PostDrive的电压标定量 */
const volatile float32 CAL_Scf_udcPrechgFail_f32 = 200.0F;
                          /* Referenced by: '<S23>/CAL_Scf_udcPrechgFail_f32' */
const volatile float32 CAL_Scf_udcPrechgFish_f32 = 250.0F;
                          /* Referenced by: '<S23>/CAL_Scf_udcPrechgFish_f32' */

/* 预充电压门限 */
#pragma section

/* Block signals (default storage) */
B_SWC_SCF_T SWC_SCF_B;

/* Block states (default storage) */
DW_SWC_SCF_T SWC_SCF_DW;

/* Forward declaration for local functions */
static uint8 SWC_SCF_GateDrvCalcn(float32 HSPF_nSlowFltAbs, uint8 stGateDrv1);
static iEDS_Enum_stDrvCtl_def SWC_SCF_DrvRunCtl(boolean RunFlg, uint8
  VCF_DrvCtlReq);
static void SWC_SCF_exit_internal_Normal(void);
static void SWC_SCF_Normal(const float32 *Abs);
static uint8 SWC_SCF_PreDrv_GateDrv(float32 HSPF_nSlowFltAbs, float64 stGateDrv1);
static void SWC_SCF_Drive(const float32 *Abs);

/* Function for Chart: '<S3>/SCF_stSysDrvCtl_Switch' */
static uint8 SWC_SCF_GateDrvCalcn(float32 HSPF_nSlowFltAbs, uint8 stGateDrv1)
{
  uint8 ReqGateDrv;
  if (stGateDrv1 == ((uint8)PRV_PWMrun)) {
    ReqGateDrv = ((uint8)PRV_ASCDWN);
  } else {
    ReqGateDrv = stGateDrv1;
  }

  if (HSPF_nSlowFltAbs > CAL_Scf_nSafeLoSpdMaxLim_f32) {
    if (HSPF_nSlowFltAbs > CAL_Scf_nSafeMaxLim_f32) {
      ReqGateDrv = ((uint8)PRV_ASCDWN);
    } else {
      if (HSPF_nSlowFltAbs < CAL_Scf_nSafeMinLim_f32) {
        ReqGateDrv = ((uint8)PRV_IGBTClose);
      }
    }
  } else {
    if (HSPF_nSlowFltAbs < CAL_Scf_nSafeLoSpdMinLim_f32) {
      ReqGateDrv = ((uint8)PRV_IGBTClose);
    }
  }

  return ReqGateDrv;
}

/* Function for Chart: '<S3>/SCF_stSysDrvCtl_Switch' */
static iEDS_Enum_stDrvCtl_def SWC_SCF_DrvRunCtl(boolean RunFlg, uint8
  VCF_DrvCtlReq)
{
  iEDS_Enum_stDrvCtl_def stMotCtlRun;
  stMotCtlRun = Drv_Initial;
  if (RunFlg) {
    switch (VCF_DrvCtlReq) {
     case ((uint8)PRV_TrqCtlReq):
      stMotCtlRun = Drv_TrqCtl;
      break;

     case ((uint8)PRV_nCtlExtReq):
      stMotCtlRun = Drv_nCtlExt;
      break;

     case ((uint8)PRV_nCtLintReq):
      stMotCtlRun = Drv_nCtlInt;
      break;

     case ((uint8)PRV_isCtlReq):
      stMotCtlRun = Drv_IsCtl;
      break;

     case ((uint8)PRV_UdcCtlBatReq):
      stMotCtlRun = Drv_UdcBatCtl;
      break;

     case ((uint8)PRV_UdcCtlReq):
      stMotCtlRun = Drv_UdcCtl;
      break;

     default:
      stMotCtlRun = Drv_Run;
      break;
    }
  }

  return stMotCtlRun;
}

/* Function for Chart: '<S3>/SCF_stSysDrvCtl_Switch' */
static void SWC_SCF_exit_internal_Normal(void)
{
  SWC_SCF_DW.is_EparkCal = 0;
  SWC_SCF_DW.is_OfstCal = 0;
  SWC_SCF_DW.is_Normal = 0;
}

/* Function for Chart: '<S3>/SCF_stSysDrvCtl_Switch' */
static void SWC_SCF_Normal(const float32 *Abs)
{
  uint8 tmpRead;
  uint8 tmpRead_0;
  if (VAR_Scf_flgTranNormalToDcha_b || SWC_SCF_DW.SCF_flgFaultToDcha) {
    SWC_SCF_exit_internal_Normal();
    SWC_SCF_DW.is_Drive = SWC_SCF_IN_Discharge;
    SWC_SCF_B.SCF_stDrvCtl_en = Drv_Discharge;
    SWC_SCF_DW.is_Discharge = SWC_SCF_IN_Discha_Inlit;
    Var_Scf_flgDisChgFail_b = false;
    SWC_SCF_B.SCF_stDisChg = ((uint8)PRV_DisChgInAct);
    SWC_SCF_B.SCF_flgActvDcha = false;
    SWC_SCF_B.SCF_stGateDrv = ((uint8)PRV_IGBTClose);
  } else {
    switch (SWC_SCF_DW.is_Normal) {
     case SWC_SCF_IN_EparkCal:
      if (VAR_Scf_flgTranSLCalToStb_b) {
        SWC_SCF_DW.is_EparkCal = 0;
        SWC_SCF_DW.is_Normal = SWC_SCF_IN_Standby;
        SWC_SCF_DW.flgCtrlRun = false;
        SWC_SCF_B.SCF_stDrvCtl_en = Drv_Standby;
        SWC_SCF_B.SCF_stGateDrv = SWC_SCF_GateDrvCalcn(*Abs,
          SWC_SCF_B.SCF_stGateDrv);
      } else {
        switch (SWC_SCF_DW.is_EparkCal) {
         case SWC_SCF_IN_SLCalAcc:
          if (VAR_Scf_flgTranSLInitToSLFw_b) {
            SWC_SCF_DW.is_EparkCal = SWC_SCF_IN_SLCalFw;
            SWC_SCF_B.SCF_stDrvCtl_en = Drv_EparkCalFw;
            SWC_SCF_B.SCF_stGateDrv = ((uint8)PRV_IGBTClose);
          }
          break;

         case SWC_SCF_IN_SLCalFw:
          if (VAR_Scf_flgTranSLInitToSLAcc_b) {
            SWC_SCF_DW.is_EparkCal = SWC_SCF_IN_SLCalAcc;
            SWC_SCF_B.SCF_stDrvCtl_en = Drv_EparkCalAcc;
            SWC_SCF_B.SCF_stGateDrv = ((uint8)PRV_PWMrun);
          }
          break;

         default:
          /* case IN_SLCalInit: */
          if (VAR_Scf_flgTranSLInitToSLFw_b) {
            SWC_SCF_DW.is_EparkCal = SWC_SCF_IN_SLCalFw;
            SWC_SCF_B.SCF_stDrvCtl_en = Drv_EparkCalFw;
            SWC_SCF_B.SCF_stGateDrv = ((uint8)PRV_IGBTClose);
          } else {
            if (VAR_Scf_flgTranSLInitToSLAcc_b) {
              SWC_SCF_DW.is_EparkCal = SWC_SCF_IN_SLCalAcc;
              SWC_SCF_B.SCF_stDrvCtl_en = Drv_EparkCalAcc;
              SWC_SCF_B.SCF_stGateDrv = ((uint8)PRV_PWMrun);
            }
          }
          break;
        }
      }
      break;

     case SWC_SCF_IN_IdLe:
      SWC_SCF_B.SCF_stGateDrv = SWC_SCF_GateDrvCalcn(*Abs,
        SWC_SCF_B.SCF_stGateDrv);
      if (VAR_Scf_flgTranIdleToStb_b) {
        SWC_SCF_DW.is_Normal = SWC_SCF_IN_Standby;
        SWC_SCF_DW.flgCtrlRun = false;
        SWC_SCF_B.SCF_stDrvCtl_en = Drv_Standby;
        SWC_SCF_B.SCF_stGateDrv = SWC_SCF_GateDrvCalcn(*Abs,
          SWC_SCF_B.SCF_stGateDrv);
      }
      break;

     case SWC_SCF_IN_OfstCal:
      if (VAR_Scf_flgTranOfstCalToStb_b) {
        SWC_SCF_DW.is_OfstCal = 0;
        SWC_SCF_DW.is_Normal = SWC_SCF_IN_Standby;
        SWC_SCF_DW.flgCtrlRun = false;
        SWC_SCF_B.SCF_stDrvCtl_en = Drv_Standby;
        SWC_SCF_B.SCF_stGateDrv = SWC_SCF_GateDrvCalcn(*Abs,
          SWC_SCF_B.SCF_stGateDrv);
      } else {
        /* Inport: '<Root>/RP_SWC_RCF_RCF_stAgRtrOfsCal' */
        Rte_Read_RP_SWC_RCF_RCF_stAgRtrOfsCal(&tmpRead);

        /* Inport: '<Root>/RP_SWC_RCF_RCF_stEstAlRtrOfs' */
        Rte_Read_RP_SWC_RCF_RCF_stEstAlRtrOfs(&tmpRead_0);
        switch (SWC_SCF_DW.is_OfstCal) {
         case SWC_SCF_IN_alOffsetAcc:
          if ((SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF == ((uint8)
                PRV_OfsCalReq)) && ((tmpRead == ((uint8)PRV_OfsCalFW)) ||
               (tmpRead == ((uint8)PRV_OfsClbSud)))) {
            SWC_SCF_DW.is_OfstCal = SWC_SCF_IN_alOffsetFw;
            SWC_SCF_B.SCF_stDrvCtl_en = Drv_OffsetFw;
            SWC_SCF_B.SCF_stGateDrv = ((uint8)PRV_IGBTClose);
          }
          break;

         case SWC_SCF_IN_alOffsetFw:
          if ((SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF == ((uint8)
                PRV_OfsCalReq)) && (tmpRead == ((uint8)PRV_OfsCalACC))) {
            SWC_SCF_DW.is_OfstCal = SWC_SCF_IN_alOffsetAcc;
            SWC_SCF_B.SCF_stDrvCtl_en = Drv_OffsetAcc;
            SWC_SCF_B.SCF_stGateDrv = ((uint8)PRV_PWMrun);
          }
          break;

         case SWC_SCF_IN_alOffsetInit:
          if (tmpRead_0 == ((uint8)PRV_EstOfsPreFinish)) {
            SWC_SCF_DW.is_OfstCal = SWC_SCF_IN_wait;
            SWC_SCF_B.SCF_stGateDrv = ((uint8)PRV_IGBTClose);
          } else {
            switch (tmpRead) {
             case ((uint8)PRV_OfsCalACC):
              SWC_SCF_DW.is_OfstCal = SWC_SCF_IN_alOffsetAcc;
              SWC_SCF_B.SCF_stDrvCtl_en = Drv_OffsetAcc;
              SWC_SCF_B.SCF_stGateDrv = ((uint8)PRV_PWMrun);
              break;

             case ((uint8)PRV_OfsCalFW):
              SWC_SCF_DW.is_OfstCal = SWC_SCF_IN_alOffsetFw;
              SWC_SCF_B.SCF_stDrvCtl_en = Drv_OffsetFw;
              SWC_SCF_B.SCF_stGateDrv = ((uint8)PRV_IGBTClose);
              break;
            }
          }
          break;

         default:
          /* case IN_wait: */
          if (tmpRead_0 == ((uint8)PRV_EstOfsFinish)) {
            SWC_SCF_DW.is_OfstCal = SWC_SCF_IN_alOffsetAcc;
            SWC_SCF_B.SCF_stDrvCtl_en = Drv_OffsetAcc;
            SWC_SCF_B.SCF_stGateDrv = ((uint8)PRV_PWMrun);
          }
          break;
        }
      }
      break;

     case SWC_SCF_IN_Run:
      SWC_SCF_B.SCF_stDrvCtl_en = SWC_SCF_DrvRunCtl(SWC_SCF_DW.flgCtrlRun,
        SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF);
      SWC_SCF_B.SCF_stGateDrv = ((uint8)PRV_PWMrun);
      if (VAR_Scf_flgTranRunToStb_b) {
        SWC_SCF_DW.is_Normal = SWC_SCF_IN_Standby;
        SWC_SCF_DW.flgCtrlRun = false;
        SWC_SCF_B.SCF_stDrvCtl_en = Drv_Standby;
        SWC_SCF_B.SCF_stGateDrv = SWC_SCF_GateDrvCalcn(*Abs,
          SWC_SCF_B.SCF_stGateDrv);
      }
      break;

     default:
      /* case IN_Standby: */
      if (VAR_Scf_flgTranStbToIdle_b) {
        SWC_SCF_DW.is_Normal = SWC_SCF_IN_IdLe;
        SWC_SCF_B.SCF_stDrvCtl_en = Drv_IdLe;
        SWC_SCF_B.SCF_stGateDrv = SWC_SCF_GateDrvCalcn(*Abs,
          SWC_SCF_B.SCF_stGateDrv);
        SWC_SCF_B.SCF_stDisChg = ((uint8)PRV_DisChgInAct);
        SWC_SCF_B.SCF_flgActvDcha = false;
        Var_Scf_flgDisChgFail_b = false;
      } else {
        SWC_SCF_B.SCF_stGateDrv = SWC_SCF_GateDrvCalcn(*Abs,
          SWC_SCF_B.SCF_stGateDrv);
        if (VAR_Scf_flgTranStbToOfstCal_b) {
          SWC_SCF_DW.is_Normal = SWC_SCF_IN_OfstCal;
          SWC_SCF_DW.is_OfstCal = SWC_SCF_IN_alOffsetInit;
          SWC_SCF_B.SCF_stDrvCtl_en = Drv_OffsetCal;
          SWC_SCF_B.SCF_stGateDrv = ((uint8)PRV_PWMrun);
        } else {
          SWC_SCF_B.SCF_stGateDrv = SWC_SCF_GateDrvCalcn(*Abs,
            SWC_SCF_B.SCF_stGateDrv);
          if (VAR_Scf_flgTranStbToRun_b) {
            SWC_SCF_DW.is_Normal = SWC_SCF_IN_Run;
            SWC_SCF_B.SCF_stDrvCtl_en = Drv_Run;
            SWC_SCF_DW.flgCtrlRun = true;
            SWC_SCF_B.SCF_stGateDrv = ((uint8)PRV_PWMrun);
          } else {
            SWC_SCF_B.SCF_stGateDrv = SWC_SCF_GateDrvCalcn(*Abs,
              SWC_SCF_B.SCF_stGateDrv);
            if (VAR_Scf_flgTranStbToSLCal_b) {
              SWC_SCF_DW.is_Normal = SWC_SCF_IN_EparkCal;
              SWC_SCF_DW.is_EparkCal = SWC_SCF_IN_SLCalInit;
              SWC_SCF_B.SCF_stDrvCtl_en = Drv_EparkCalInit;
              SWC_SCF_B.SCF_stGateDrv = ((uint8)PRV_IGBTClose);
            }
          }
        }
      }
      break;
    }
  }
}

/* Function for Chart: '<S3>/SCF_stSysDrvCtl_Switch' */
static uint8 SWC_SCF_PreDrv_GateDrv(float32 HSPF_nSlowFltAbs, float64 stGateDrv1)
{
  uint8 PreDrv_GateDrv;
  if (HSPF_nSlowFltAbs > CAL_Scf_nSafeTestMaxLim_f32) {
    PreDrv_GateDrv = ((uint8)PRV_ASCDWN);
  } else if (HSPF_nSlowFltAbs < CAL_Scf_nSafeTestMinLim_f32) {
    PreDrv_GateDrv = ((uint8)PRV_IGBTClose);
  } else if (stGateDrv1 < 256.0) {
    if (stGateDrv1 >= 0.0) {
      PreDrv_GateDrv = (uint8)stGateDrv1;
    } else {
      PreDrv_GateDrv = 0U;
    }
  } else {
    PreDrv_GateDrv = MAX_uint8_T;
  }

  return PreDrv_GateDrv;
}

/* Function for Chart: '<S3>/SCF_stSysDrvCtl_Switch' */
static void SWC_SCF_Drive(const float32 *Abs)
{
  sint32 tmp;
  boolean guard1 = false;
  boolean guard2 = false;
  if (VAR_Scf_flgTranDrvToFault_b) {
    SWC_SCF_DW.is_Discha_HW = 0;
    SWC_SCF_DW.is_Discharge = 0;
    SWC_SCF_exit_internal_Normal();
    SWC_SCF_DW.is_Drive = 0;
    SWC_SCF_DW.is_c187_SWC_SCF = SWC_SCF_IN_Fault;
    SWC_SCF_B.SCF_stSysCtl_en = FaultMod;
    SWC_SCF_B.SCF_stDrvCtl_en = Drv_Failure;
    SWC_SCF_B.SCF_stGateDrv = SWC_SCF_PreDrv_GateDrv(*Abs, (float64)
      SWC_SCF_B.SCF_stGateDrv);
  } else if (VAR_Scf_flgTranDrvToPostDrv_b) {
    SWC_SCF_DW.is_Discha_HW = 0;
    SWC_SCF_DW.is_Discharge = 0;
    SWC_SCF_exit_internal_Normal();
    SWC_SCF_DW.is_Drive = 0;
    SWC_SCF_DW.is_c187_SWC_SCF = SWC_SCF_IN_PostDrive;
    SWC_SCF_B.SCF_stSysCtl_en = PostDriveMod;
    SWC_SCF_B.SCF_stGateDrv = SWC_SCF_PreDrv_GateDrv(*Abs, (float64)
      SWC_SCF_B.SCF_stGateDrv);
  } else if (SWC_SCF_DW.is_Drive == SWC_SCF_IN_Discharge) {
    if (VAR_Scf_flgTranDchaToNormal_b) {
      SWC_SCF_DW.is_Discha_HW = 0;
      SWC_SCF_DW.is_Discharge = 0;
      SWC_SCF_DW.is_Drive = SWC_SCF_IN_Normal;
      SWC_SCF_DW.is_Normal = SWC_SCF_IN_IdLe;
      SWC_SCF_B.SCF_stDrvCtl_en = Drv_IdLe;
      SWC_SCF_B.SCF_stGateDrv = SWC_SCF_GateDrvCalcn(*Abs,
        SWC_SCF_B.SCF_stGateDrv);
      SWC_SCF_B.SCF_stDisChg = ((uint8)PRV_DisChgInAct);
      SWC_SCF_B.SCF_flgActvDcha = false;
      Var_Scf_flgDisChgFail_b = false;
    } else if (SWC_SCF_DW.is_Discharge == SWC_SCF_IN_Discha_HW) {
      switch (SWC_SCF_DW.is_Discha_HW) {
       case SWC_SCF_IN_Discha_End:
       case SWC_SCF_IN_Discha_Outime:
        break;

       default:
        /* case IN_Discha_Start: */
        tmp = SWC_SCF_DW.i + 1;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_SCF_DW.i = (uint16)tmp;
        guard1 = false;
        guard2 = false;
        if (SWC_SCF_DW.i >= CAL_Scf_cntDisChgOvTi_u16) {
          if (SWC_SCF_B.TmpSignalConversionAtRP_SWC_HSP >
              CAL_Scf_uDisChgOutTim_f32) {
            SWC_SCF_DW.is_Discha_HW = SWC_SCF_IN_Discha_Outime;
            SWC_SCF_DW.i = 0U;
            Var_Scf_flgDisChgFail_b = true;
            SWC_SCF_B.SCF_flgActvDcha = false;
            SWC_SCF_B.SCF_stGateDrv = ((uint8)PRV_IGBTClose);
            SWC_SCF_B.SCF_stDisChg = ((uint8)PRV_DisChgFail);
          } else if (SWC_SCF_B.TmpSignalConversionAtRP_SWC_HSP <=
                     CAL_Scf_uDisChgEnd_f32) {
            guard1 = true;
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          if (SWC_SCF_DW.i >= CAL_Scf_cntDisChgEnd_u16) {
            guard1 = true;
          }
        }

        if (guard1) {
          SWC_SCF_DW.is_Discha_HW = SWC_SCF_IN_Discha_End;
          SWC_SCF_DW.i = 0U;
          SWC_SCF_B.SCF_flgActvDcha = false;
          SWC_SCF_B.SCF_stGateDrv = ((uint8)PRV_IGBTClose);
          SWC_SCF_B.SCF_stDisChg = ((uint8)PRV_DisChgEnd);
        }
        break;
      }
    } else {
      /* case IN_Discha_Inlit: */
      SWC_SCF_DW.is_Discharge = SWC_SCF_IN_Discha_HW;
      SWC_SCF_DW.is_Discha_HW = SWC_SCF_IN_Discha_Start;
      SWC_SCF_DW.i = 0U;
      Var_Scf_flgDisChgFail_b = false;
      SWC_SCF_B.SCF_flgActvDcha = true;
      SWC_SCF_B.SCF_stGateDrv = ((uint8)PRV_PWMrun);
      SWC_SCF_B.SCF_stDisChg = ((uint8)PRV_DisChgStart);
    }
  } else {
    /* case IN_Normal: */
    SWC_SCF_Normal(Abs);
  }
}

/* Model step function for TID1 */
void SWC_SCF_10ms(void)                /* Explicit Task: RE_SWC_SCF_10ms */
{
  /* local block i/o variables */
  boolean rtb_TmpSignalConversionAtRP_S_b;
  boolean rtb_TmpSignalConversionAtRP__jt;
  boolean tmpRead;
  uint8 tmpRead_0;
  boolean tmpRead_1;
  boolean tmpRead_2;
  boolean rtb_TmpSignalConversionAtRP_S_o;
  boolean rtb_TmpSignalConversionAtRP__on;
  boolean rtb_TmpSignalConversionAtRP_S_i;
  float32 rtb_TmpSignalConversionAtRP_SWC;
  float32 rtb_SpeedTemp;
  boolean rtb_flgReqAllwDrvByN;
  float32 rtb_IsTemp;
  float32 rtb_TmpSignalConversionAtRP_S_p;
  boolean rtb_flgReqAllwDrvByIs;
  float32 rtb_UdcTemp;
  boolean rtb_flgReqAllwDrvByUTnet;
  boolean rtb_Switch1_b;
  uint8 rtb_TmpSignalConversionAtRP__gi;
  uint8 rtb_TmpSignalConversionAtRP_S_j;
  boolean rtb_LogicalOperator2_l;
  boolean rtb_TmpSignalConversionAtRP_S_l;
  boolean rtb_TmpSignalConversionAtRP_S_f;
  boolean rtb_TmpSignalConversionAtRP_S_g;
  uint8 rtb_TmpSignalConversionAtRP__jm;
  boolean rtb_TmpSignalConversionAtRP__kb;
  uint16 rtb_TmpSignalConversionAtRP__lv;
  boolean VAR_Scf_flgShtDwnByMcu_b_tmp_tm;
  boolean VAR_Scf_flgShtDwnByMcu_b_tmp__0;
  boolean VAR_Scf_flgShtDwnByMcu_b_tmp__1;
  boolean VAR_Scf_flgTranPreDrvToFault_b_;
  boolean VAR_Scf_flgShtDwnByMcu_b_tmp;
  boolean VAR_Scf_flgShtDwnByMcu_b_tmp__2;

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_SCF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_SCF_10ms_sys'
   */
  /* SignalConversion generated from: '<S1>/RP_SWC_VCF_VCF_stModeReq_read' incorporates:
   *  Inport: '<Root>/RP_SWC_VCF_VCF_stModeReq'
   */
  Rte_Read_RP_SWC_VCF_VCF_stModeReq(&SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF);

  /* SignalConversion generated from: '<S1>/RP_SWC_HSPF_HSPF_Wake_read' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_Wake'
   */
  Rte_Read_RP_SWC_HSPF_HSPF_Wake(&rtb_TmpSignalConversionAtRP__on);

  /* SignalConversion generated from: '<S1>/RP_SWC_HSPF_HSPF_bt15_read' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_bt15'
   */
  Rte_Read_RP_SWC_HSPF_HSPF_bt15(&rtb_TmpSignalConversionAtRP_S_i);

  /* SignalConversion generated from: '<S1>/RP_SWC_Tja1043_Tja1043_flgCAN_WakeUp_read' incorporates:
   *  Inport: '<Root>/RP_SWC_Tja1043_Tja1043_flgCAN_WakeUp'
   */
  Rte_Read_RP_SWC_Tja1043_Tja1043_flgCAN_WakeUp(&rtb_TmpSignalConversionAtRP_S_o);

  /* Switch: '<S46>/Switch' incorporates:
   *  Constant: '<S46>/CAL_Scf_ShtDwnReqByVcuSwt_b'
   *  Constant: '<S46>/PRV_ShutDownReq'
   *  Logic: '<S46>/Logical Operator'
   *  Logic: '<S46>/Logical Operator1'
   *  RelationalOperator: '<S46>/Relational Operator'
   *  RelationalOperator: '<S46>/Relational Operator1'
   */
  if (CAL_Scf_ShtDwnReqByVcuSwt_b) {
    VAR_Scf_flgTranPreDrvToDrv_b = ((SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF
      != ((uint8)PRV_ShutDownReq)) && (rtb_TmpSignalConversionAtRP__on ||
      rtb_TmpSignalConversionAtRP_S_i || rtb_TmpSignalConversionAtRP_S_o));
  } else {
    VAR_Scf_flgTranPreDrvToDrv_b = (rtb_TmpSignalConversionAtRP__on ||
      rtb_TmpSignalConversionAtRP_S_i || rtb_TmpSignalConversionAtRP_S_o);
  }

  /* End of Switch: '<S46>/Switch' */

  /* SignalConversion generated from: '<S1>/RP_SWC_HSPF_HSPF_uDcLnkSlowFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_uDcLnkSlowFlt'
   */
  Rte_Read_RP_SWC_HSPF_HSPF_uDcLnkSlowFlt
    (&SWC_SCF_B.TmpSignalConversionAtRP_SWC_HSP);

  /* SignalConversion generated from: '<S1>/RP_SWC_HSPF_HSPF_nSlowFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_nSlowFlt'
   */
  Rte_Read_RP_SWC_HSPF_HSPF_nSlowFlt(&rtb_TmpSignalConversionAtRP_SWC);

  /* Abs: '<S4>/Abs1' incorporates:
   *  Abs: '<S3>/Abs'
   */
  rtb_TmpSignalConversionAtRP_SWC = fabsf(rtb_TmpSignalConversionAtRP_SWC);

  /* FunctionCaller: '<S1>/RP_SWC_FIM_VCUComTimeOut_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_VCUComTimeOut_GetFunctionPermission
    (&VAR_Scf_flgFimVCUComErr_b);

  /* Chart: '<S10>/uDc_Spd_Is_Swt' incorporates:
   *  UnitDelay: '<S3>/Unit Delay'
   */
  if (SWC_SCF_DW.UnitDelay_DSTATE == DriveMod) {
    rtb_UdcTemp = CAL_Scf_uTnetHysToPostDrv_f32;
    rtb_SpeedTemp = CAL_Scf_nPsmThresToPostDrv_f32;
    rtb_IsTemp = CAL_Scf_curSenChgToPostDrv_f32;
  } else {
    rtb_UdcTemp = CAL_Scf_uTnetHysToDrv_f32;
    rtb_SpeedTemp = CAL_Scf_nPsmThresToDrv_f32;
    rtb_IsTemp = CAL_Scf_curSenChgToDrv_f32;
  }

  /* End of Chart: '<S10>/uDc_Spd_Is_Swt' */

  /* Logic: '<S43>/Logical Operator7' incorporates:
   *  Abs: '<S4>/Abs1'
   *  Constant: '<S43>/CAL_SmgSys_flgActvSubNSwt_b'
   *  Constant: '<S43>/CAL_SmgSys_nSubPsmSpdVal_f32'
   *  Logic: '<S43>/Logical Operator4'
   *  Logic: '<S43>/Logical Operator5'
   *  Logic: '<S43>/Logical Operator6'
   *  RelationalOperator: '<S43>/Relational Operator2'
   *  RelationalOperator: '<S43>/Relational Operator3'
   */
  rtb_flgReqAllwDrvByN = (((rtb_TmpSignalConversionAtRP_SWC >= rtb_SpeedTemp) &&
    (!CAL_Scf_flgActvSubNSwt_b)) || (CAL_Scf_flgActvSubNSwt_b &&
    (CAL_Scf_nSubPsmSpdVal_f32 >= rtb_SpeedTemp)));

  /* SignalConversion generated from: '<S1>/RP_SWC_MPC_MPC_IsFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MPC_MPC_IsFlt'
   */
  Rte_Read_RP_SWC_MPC_MPC_IsFlt(&rtb_TmpSignalConversionAtRP_S_p);

  /* Logic: '<S43>/Logical Operator11' incorporates:
   *  Constant: '<S43>/CAL_SmgSys_flgActvSubisSwt_b'
   *  Constant: '<S43>/CAL_SmgSys_iSubSttrisVal_f32'
   *  Logic: '<S43>/Logical Operator10'
   *  Logic: '<S43>/Logical Operator8'
   *  Logic: '<S43>/Logical Operator9'
   *  RelationalOperator: '<S43>/Relational Operator4'
   *  RelationalOperator: '<S43>/Relational Operator5'
   */
  rtb_flgReqAllwDrvByIs = (((rtb_TmpSignalConversionAtRP_S_p >= rtb_IsTemp) && (
    !CAL_Scf_flgActvSubisSwt_b)) || (CAL_Scf_flgActvSubisSwt_b &&
    (CAL_Scf_iSubSttrisVal_f32 >= rtb_IsTemp)));

  /* Logic: '<S43>/Logical Operator3' incorporates:
   *  Constant: '<S43>/CAL_SmgSys_flgActvSubUSwt_b'
   *  Constant: '<S43>/CAL_SmgSys_uSubHiVoltVal_f32'
   *  Logic: '<S43>/Logical Operator'
   *  Logic: '<S43>/Logical Operator1'
   *  Logic: '<S43>/Logical Operator2'
   *  RelationalOperator: '<S43>/Relational Operator'
   *  RelationalOperator: '<S43>/Relational Operator1'
   */
  rtb_flgReqAllwDrvByUTnet = (((SWC_SCF_B.TmpSignalConversionAtRP_SWC_HSP >=
    rtb_UdcTemp) && (!CAL_Scf_flgActvSubUSwt_b)) || (CAL_Scf_flgActvSubUSwt_b &&
    (CAL_Scf_uSubHiVoltVal_f32 >= rtb_UdcTemp)));

  /* Switch: '<S56>/Switch' incorporates:
   *  Constant: '<S56>/CAL_Scf_flgDrvToPostWihDisSwt_b'
   *  Constant: '<S56>/PRV_DisChgEnd'
   *  Constant: '<S56>/PRV_DisChgEnd1'
   *  Logic: '<S56>/Logical Operator1'
   *  Logic: '<S56>/Logical Operator2'
   *  RelationalOperator: '<S56>/Relational Operator5'
   *  RelationalOperator: '<S56>/Relational Operator6'
   *  RelationalOperator: '<S56>/Relational Operator7'
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  if (CAL_Scf_flgDrvToPostWihDisSwt_b) {
    VAR_Scf_flgTranPreDrvToFault_b_ = ((SWC_SCF_DW.UnitDelay1_DSTATE_e ==
      ((uint8)PRV_DisChgEnd)) || (SWC_SCF_DW.UnitDelay1_DSTATE_e == ((uint8)
      PRV_DisChgFail)));
  } else {
    VAR_Scf_flgTranPreDrvToFault_b_ = ((SWC_SCF_DW.UnitDelay1_DSTATE_e ==
      ((uint8)PRV_DisChgEnd)) || (SWC_SCF_DW.UnitDelay1_DSTATE_e == ((uint8)
      PRV_DisChgFail)) || (!rtb_flgReqAllwDrvByUTnet));
  }

  /* End of Switch: '<S56>/Switch' */

  /* RelationalOperator: '<S56>/Relational Operator1' */
  VAR_Scf_flgShtDwnByMcu_b_tmp_tm = !rtb_TmpSignalConversionAtRP__on;

  /* RelationalOperator: '<S56>/Relational Operator2' */
  VAR_Scf_flgShtDwnByMcu_b_tmp__0 = !rtb_TmpSignalConversionAtRP_S_i;

  /* RelationalOperator: '<S56>/Relational Operator' */
  VAR_Scf_flgShtDwnByMcu_b_tmp__1 = !rtb_TmpSignalConversionAtRP_S_o;

  /* Logic: '<S56>/Logical Operator6' incorporates:
   *  Logic: '<S57>/Logical Operator2'
   *  Logic: '<S61>/Logical Operator6'
   *  Switch: '<S59>/Switch'
   */
  rtb_LogicalOperator2_l = (VAR_Scf_flgShtDwnByMcu_b_tmp__1 &&
    VAR_Scf_flgShtDwnByMcu_b_tmp_tm && VAR_Scf_flgShtDwnByMcu_b_tmp__0);

  /* RelationalOperator: '<S56>/Relational Operator3' */
  rtb_Switch1_b = !rtb_flgReqAllwDrvByN;

  /* RelationalOperator: '<S56>/Relational Operator4' */
  VAR_Scf_flgShtDwnByMcu_b_tmp__2 = !rtb_flgReqAllwDrvByIs;

  /* Logic: '<S56>/Logical Operator' incorporates:
   *  Logic: '<S56>/Logical Operator6'
   *  Logic: '<S60>/Logical Operator'
   */
  VAR_Scf_flgShtDwnByMcu_b_tmp = (rtb_LogicalOperator2_l && rtb_Switch1_b &&
    VAR_Scf_flgShtDwnByMcu_b_tmp__2);

  /* Logic: '<S56>/Logical Operator4' incorporates:
   *  Logic: '<S56>/Logical Operator'
   */
  VAR_Scf_flgShtDwnByMcu_b = (VAR_Scf_flgShtDwnByMcu_b_tmp &&
    VAR_Scf_flgTranPreDrvToFault_b_);

  /* Switch: '<S11>/Switch2' incorporates:
   *  Constant: '<S11>/CAL_SmgSys_flgIntVcuComErr_b'
   *  Constant: '<S11>/CAL_SmgSys_flgIntVcuComSwt_b'
   */
  if (CAL_Scf_flgIntVcuComSwt_b) {
    VAR_Scf_VCUComErr_b = CAL_Scf_flgIntVcuComErr_b;
  } else {
    VAR_Scf_VCUComErr_b = VAR_Scf_flgFimVCUComErr_b;
  }

  /* End of Switch: '<S11>/Switch2' */

  /* Switch: '<S58>/Switch2' incorporates:
   *  Constant: '<S58>/Constant4'
   *  Sum: '<S58>/Add'
   *  Switch: '<S58>/Switch3'
   *  UnitDelay: '<S58>/Unit Delay1'
   *  UnitDelay: '<S58>/Unit Delay2'
   */
  if (VAR_Scf_VCUComErr_b) {
    SWC_SCF_DW.UnitDelay1_DSTATE_l = 0U;
  }

  SWC_SCF_DW.UnitDelay1_DSTATE_l = (uint16)((uint32)
    SWC_SCF_DW.UnitDelay1_DSTATE_l + !SWC_SCF_DW.UnitDelay2_DSTATE_l);

  /* End of Switch: '<S58>/Switch2' */

  /* RelationalOperator: '<S58>/Relational Operator2' incorporates:
   *  Constant: '<S58>/CAL_Scf_cntVCUComErrLim_u16'
   *  UnitDelay: '<S58>/Unit Delay1'
   *  UnitDelay: '<S58>/Unit Delay2'
   */
  SWC_SCF_DW.UnitDelay2_DSTATE_l = (SWC_SCF_DW.UnitDelay1_DSTATE_l >=
    CAL_Scf_cntVCUComErrLim_u16);

  /* Switch: '<S55>/Switch5' incorporates:
   *  Constant: '<S55>/PRV_ShutDownReq'
   *  RelationalOperator: '<S55>/Relational Operator1'
   *  Switch: '<S55>/Switch3'
   *  UnitDelay: '<S58>/Unit Delay2'
   */
  if (VAR_Scf_VCUComErr_b) {
    VAR_Scf_flgShtDwnByVcu_b = (SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF ==
      ((uint8)PRV_ShutDownReq));
  } else {
    if (SWC_SCF_DW.UnitDelay2_DSTATE_l) {
      /* Switch: '<S55>/Switch3' */
      VAR_Scf_flgShtDwnByVcu_b = VAR_Scf_flgShtDwnByMcu_b;
    }
  }

  /* End of Switch: '<S55>/Switch5' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_SCF_10ms' */

  /* Inport: '<Root>/RP_SWC_CSPF_CSPF_RecflgDchaReq' */
  Rte_Read_RP_SWC_CSPF_CSPF_RecflgDchaReq(&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_SCF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_SCF_10ms_sys'
   */
  /* Switch: '<S55>/Switch1' incorporates:
   *  Constant: '<S55>/CAL_Scf_ShtDwnReqByVcuSwt_b'
   */
  if (CAL_Scf_ShtDwnReqByVcuSwt_b) {
    VAR_Scf_flgPostDrvReqWiDcha_b = VAR_Scf_flgShtDwnByVcu_b;
  } else {
    VAR_Scf_flgPostDrvReqWiDcha_b = VAR_Scf_flgShtDwnByMcu_b;
  }

  /* End of Switch: '<S55>/Switch1' */

  /* RelationalOperator: '<S57>/Relational Operator5' */
  rtb_flgReqAllwDrvByUTnet = !rtb_flgReqAllwDrvByUTnet;

  /* Logic: '<S57>/Logical Operator5' incorporates:
   *  Logic: '<S57>/Logical Operator1'
   *  Logic: '<S57>/Logical Operator3'
   *  RelationalOperator: '<S57>/Relational Operator3'
   *  RelationalOperator: '<S57>/Relational Operator4'
   */
  VAR_Scf_flgPostDrvReqWoDcha_b = ((rtb_LogicalOperator2_l &&
    (!rtb_flgReqAllwDrvByN) && (!rtb_flgReqAllwDrvByIs)) ||
    (rtb_LogicalOperator2_l && rtb_flgReqAllwDrvByUTnet));

  /* Switch: '<S55>/Switch' incorporates:
   *  Constant: '<S55>/CAL_Scf_IntDchaSwt_b'
   */
  if (CAL_Scf_IntDchaSwt_b) {
    VAR_Scf_flgTranDrvToPostDrv_b = VAR_Scf_flgPostDrvReqWiDcha_b;
  } else {
    VAR_Scf_flgTranDrvToPostDrv_b = VAR_Scf_flgPostDrvReqWoDcha_b;
  }

  /* End of Switch: '<S55>/Switch' */

  /* Logic: '<S47>/Logical Operator1' incorporates:
   *  Logic: '<S45>/Logical Operator2'
   */
  rtb_flgReqAllwDrvByN = (VAR_Scf_flgShtDwnByMcu_b_tmp_tm &&
    VAR_Scf_flgShtDwnByMcu_b_tmp__0);

  /* Logic: '<S47>/Logical Operator3' incorporates:
   *  Constant: '<S47>/PRV_ShutDownReq'
   *  Logic: '<S47>/Logical Operator1'
   *  Logic: '<S47>/Logical Operator2'
   *  RelationalOperator: '<S47>/Relational Operator1'
   */
  VAR_Scf_flgTranPreDrvToPostDrv_b =
    (((SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF == ((uint8)PRV_ShutDownReq)) ||
      (rtb_flgReqAllwDrvByN && VAR_Scf_flgShtDwnByMcu_b_tmp__1)) &&
     rtb_flgReqAllwDrvByUTnet);

  /* FunctionCaller: '<S1>/RP_SWC_FIM_flgFaultLvFour_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_flgFaultLvFour_GetFunctionPermission
    (&VAR_Scf_flgFimFaultLvFour_b);

  /* FunctionCaller: '<S1>/RP_SWC_FIM_flgFaultLvFive_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_flgFaultLvFive_GetFunctionPermission
    (&VAR_Scf_flgFimFaultLvFive_b);

  /* Logic: '<S63>/Logical Operator2' incorporates:
   *  Constant: '<S63>/CAL_Scf_StandbyVcuReq_u8'
   *  Logic: '<S63>/Logical Operator1'
   *  Logic: '<S63>/Logical Operator3'
   *  RelationalOperator: '<S63>/Relational Operator'
   */
  VAR_Scf_flgTranPostDrvToPreDrv_b = ((rtb_TmpSignalConversionAtRP__on ||
    rtb_TmpSignalConversionAtRP_S_i || rtb_TmpSignalConversionAtRP_S_o ||
    (SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF == CAL_Scf_StandbyVcuReq_u8)) &&
    VAR_Scf_flgFimFaultLvFour_b && VAR_Scf_flgFimFaultLvFive_b);

  /* SignalConversion generated from: '<S1>/RP_SWC_LvPower_LvPower_stLowpowerUp_read' incorporates:
   *  Inport: '<Root>/RP_SWC_LvPower_LvPower_stLowpowerUp'
   */
  Rte_Read_RP_SWC_LvPower_LvPower_stLowpowerUp(&rtb_TmpSignalConversionAtRP__gi);

  /* SignalConversion generated from: '<S1>/RP_SWC_HSPF_HSPF_stIphaOffCal_read' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_stIphaOffCal'
   */
  Rte_Read_RP_SWC_HSPF_HSPF_stIphaOffCal(&rtb_TmpSignalConversionAtRP_S_j);

  /* FunctionCaller: '<S1>/RP_SWC_FIM_ReqFailrMod_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_ReqFailrMod_GetFunctionPermission
    (&VAR_Scf_flgFimReqFailr_b);

  /* RelationalOperator: '<S64>/Relational Operator5' */
  VAR_Scf_flgTranPreDrvToFault_b_ = !VAR_Scf_flgFimReqFailr_b;

  /* Logic: '<S64>/Logical Operator1' incorporates:
   *  Constant: '<S64>/CAL_Scf_LowPwrSetUpErr_u8'
   *  Constant: '<S64>/CAL_Scf_SenChkErr_u8'
   *  Constant: '<S64>/PRV_PreDrv_Fishd'
   *  Logic: '<S64>/Logical Operator'
   *  RelationalOperator: '<S64>/Relational Operator1'
   *  RelationalOperator: '<S64>/Relational Operator2'
   *  RelationalOperator: '<S64>/Relational Operator3'
   *  UnitDelay: '<S3>/Unit Delay3'
   */
  VAR_Scf_flgTranPreDrvToFault_b = ((rtb_TmpSignalConversionAtRP__gi ==
    CAL_Scf_LowPwrSetUpErr_u8) || (rtb_TmpSignalConversionAtRP_S_j ==
    CAL_Scf_SenChkErr_u8) || ((SWC_SCF_B.SCF_stPreDrvCtl == ((uint8)
    PRV_PreDrv_Fishd)) && VAR_Scf_flgTranPreDrvToFault_b_));

  /* FunctionCaller: '<S1>/RP_SWC_FIM_flgDchaFailr_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_flgDchaFailr_GetFunctionPermission
    (&VAR_Scf_flgFimDchaFailr_b);

  /* SignalConversion generated from: '<S1>/RP_SWC_HSPF_HSPF_flgCrash_read' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_flgCrash'
   */
  Rte_Read_RP_SWC_HSPF_HSPF_flgCrash(&rtb_TmpSignalConversionAtRP_S_b);

  /* SignalConversion generated from: '<S1>/RP_SWC_CSPF_CSPF_RecflgCrash_read' incorporates:
   *  Inport: '<Root>/RP_SWC_CSPF_CSPF_RecflgCrash'
   */
  Rte_Read_RP_SWC_CSPF_CSPF_RecflgCrash(&rtb_TmpSignalConversionAtRP__jt);

  /* Outputs for Atomic SubSystem: '<S14>/EI09_EmDisChaFunction' */
  SWC_SCF_EI09_EmDisChaFunction(rtb_TmpSignalConversionAtRP_S_b,
    rtb_TmpSignalConversionAtRP__jt, &rtb_flgReqAllwDrvByIs,
    &SWC_SCF_DW.EI09_EmDisChaFunction);

  /* End of Outputs for SubSystem: '<S14>/EI09_EmDisChaFunction' */

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S13>/CAL_Scf_flgEmgDisChgReqSwt_b'
   */
  VAR_Scf_flgEmgReqInvDcha_b = (CAL_Scf_flgEmgDisChgReqSwt_b &&
    rtb_flgReqAllwDrvByIs);

  /* Logic: '<S53>/Logical Operator3' incorporates:
   *  Constant: '<S53>/PRV_DisChgEnd'
   *  Constant: '<S53>/iEDS_Enum_stDrvCtl_def.Drv_Discharge'
   *  Logic: '<S53>/Logical Operator1'
   *  Logic: '<S53>/Logical Operator2'
   *  RelationalOperator: '<S53>/Relational Operator1'
   *  RelationalOperator: '<S53>/Relational Operator3'
   *  RelationalOperator: '<S53>/Relational Operator6'
   *  UnitDelay: '<S3>/Unit Delay1'
   *  UnitDelay: '<S3>/Unit Delay4'
   */
  VAR_Scf_flgTranDrvToFault_b = ((VAR_Scf_flgTranPreDrvToFault_b_ &&
    ((SWC_SCF_DW.UnitDelay4_DSTATE != Drv_Discharge) ||
     (SWC_SCF_DW.UnitDelay1_DSTATE_e == ((uint8)PRV_DisChgEnd)))) ||
    (!VAR_Scf_flgFimDchaFailr_b) || VAR_Scf_flgEmgReqInvDcha_b);

  /* Logic: '<S16>/Logical Operator2' incorporates:
   *  Abs: '<S4>/Abs1'
   *  Constant: '<S16>/CAL_Scf_nAllwPwrDcha_f32'
   *  Constant: '<S16>/CAL_SmgSys_uAllwPwrDcha_f32'
   *  Constant: '<S16>/PRV_DisChgReq'
   *  Logic: '<S16>/Logical Operator1'
   *  RelationalOperator: '<S16>/Relational Operator'
   *  RelationalOperator: '<S16>/Relational Operator1'
   *  RelationalOperator: '<S16>/Relational Operator2'
   */
  VAR_Scf_flgDchaVcuReq_b = (((SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF ==
    ((uint8)PRV_DisChgReq)) || tmpRead) && (rtb_TmpSignalConversionAtRP_SWC <=
    CAL_Scf_nAllwPwrDcha_f32) && (SWC_SCF_B.TmpSignalConversionAtRP_SWC_HSP >=
    CAL_Scf_uAllwPwrDcha_f32));

  /* RelationalOperator: '<S15>/Relational Operator' incorporates:
   *  Abs: '<S4>/Abs1'
   *  Constant: '<S15>/CAL_SmgSys_nAllwPwrDcha_f32'
   */
  VAR_Scf_nDchaAllw_b = (rtb_TmpSignalConversionAtRP_SWC <=
    CAL_Scf_nAllwPwrDcha_f32);

  /* Switch: '<S18>/Switch3' incorporates:
   *  Constant: '<S15>/CAL_SmgSys_uAllwPwrDcha_f32'
   *  Constant: '<S15>/Constant1'
   *  Constant: '<S18>/Constant8'
   *  Logic: '<S15>/Logical Operator'
   *  Logic: '<S15>/Logical Operator4'
   *  RelationalOperator: '<S15>/Relational Operator1'
   *  RelationalOperator: '<S15>/Relational Operator2'
   *  UnitDelay: '<S18>/Unit Delay1'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  if (VAR_Scf_nDchaAllw_b && (SWC_SCF_DW.UnitDelay_DSTATE == DriveMod) &&
      (VAR_Scf_flgShtDwnByMcu_b_tmp__0 && VAR_Scf_flgShtDwnByMcu_b_tmp_tm) &&
      (SWC_SCF_B.TmpSignalConversionAtRP_SWC_HSP >= CAL_Scf_uAllwPwrDcha_f32)) {
    /* Sum: '<S18>/Sum' incorporates:
     *  UnitDelay: '<S18>/Unit Delay1'
     *  UnitDelay: '<S18>/Unit Delay2'
     */
    SWC_SCF_DW.UnitDelay1_DSTATE_g = (uint16)((uint32)!VAR_Scf_cntSigFit_b +
      SWC_SCF_DW.UnitDelay1_DSTATE_g);

    /* Switch: '<S18>/Switch2' incorporates:
     *  Constant: '<S18>/Constant6'
     *  RelationalOperator: '<S18>/Relational Operator2'
     *  UnitDelay: '<S18>/Unit Delay1'
     */
    if (SWC_SCF_DW.UnitDelay1_DSTATE_g >= 65535) {
      SWC_SCF_DW.UnitDelay1_DSTATE_g = MAX_uint16_T;
    }

    /* End of Switch: '<S18>/Switch2' */
  } else {
    SWC_SCF_DW.UnitDelay1_DSTATE_g = 0U;
  }

  /* End of Switch: '<S18>/Switch3' */

  /* RelationalOperator: '<S18>/Relational Operator3' incorporates:
   *  Constant: '<S18>/CAL_SmgSys_cntDchaSigFit_u8'
   *  Product: '<S18>/Product1'
   *  UnitDelay: '<S18>/Unit Delay1'
   */
  VAR_Scf_cntSigFit_b = (SWC_SCF_DW.UnitDelay1_DSTATE_g >=
    CAL_Scf_cntDchaSigFit_u8);

  /* Switch: '<S17>/Switch2' incorporates:
   *  Constant: '<S17>/Constant4'
   *  Sum: '<S17>/Add'
   *  Switch: '<S17>/Switch3'
   *  UnitDelay: '<S17>/Unit Delay1'
   */
  if (VAR_Scf_VCUComErr_b) {
    SWC_SCF_DW.UnitDelay1_DSTATE_b = 0U;
  }

  SWC_SCF_DW.UnitDelay1_DSTATE_b = (uint16)((uint32)
    SWC_SCF_DW.UnitDelay1_DSTATE_b + !VAR_Scf_flgVCUComErrDelay_b);

  /* End of Switch: '<S17>/Switch2' */

  /* RelationalOperator: '<S17>/Relational Operator' incorporates:
   *  Constant: '<S17>/CAL_Scf_cntVCUComErrLim_u16'
   *  UnitDelay: '<S17>/Unit Delay1'
   */
  VAR_Scf_flgVCUComErrDelay_b = (SWC_SCF_DW.UnitDelay1_DSTATE_b >=
    CAL_Scf_cntVCUComErrLim_u16);

  /* Switch: '<S13>/Switch1' incorporates:
   *  Constant: '<S13>/CAL_Scf_flgDisChgReqSwt_b'
   *  Constant: '<S13>/DisChgShut'
   *  Logic: '<S13>/Logical Operator'
   */
  if (CAL_Scf_flgDisChgReqSwt_b) {
    /* Switch: '<S12>/Switch' incorporates:
     *  Switch: '<S12>/Switch1'
     */
    if (VAR_Scf_VCUComErr_b) {
      VAR_Scf_flgTranPreDrvToFault_b_ = VAR_Scf_flgDchaVcuReq_b;
    } else {
      VAR_Scf_flgTranPreDrvToFault_b_ = (VAR_Scf_flgVCUComErrDelay_b &&
        VAR_Scf_cntSigFit_b);
    }

    /* End of Switch: '<S12>/Switch' */
    VAR_Scf_DisChaDetec_b = (SWC_SCF_ConstB.EI09_EmDisChaFunction.Constant ||
      VAR_Scf_flgTranPreDrvToFault_b_);
  } else {
    VAR_Scf_DisChaDetec_b = false;
  }

  /* End of Switch: '<S13>/Switch1' */

  /* Switch: '<S13>/Switch2' */
  VAR_Scf_flgReqInvDcha_b = ((!VAR_Scf_flgEmgReqInvDcha_b) &&
    VAR_Scf_DisChaDetec_b);

  /* Logic: '<S54>/Logical Operator2' incorporates:
   *  Logic: '<S26>/Logical Operator'
   */
  VAR_Scf_flgTranFaultToDcha_b = (VAR_Scf_flgReqInvDcha_b &&
    VAR_Scf_flgFimDchaFailr_b);

  /* Switch: '<S60>/Switch' incorporates:
   *  Constant: '<S60>/CAL_Scf_flgDrvToPostWihDisSwt_b'
   *  Constant: '<S60>/PRV_DisChgEnd2'
   *  Constant: '<S60>/PRV_DisChgEnd3'
   *  Logic: '<S60>/Logical Operator3'
   *  Logic: '<S60>/Logical Operator5'
   *  RelationalOperator: '<S60>/Relational Operator10'
   *  RelationalOperator: '<S60>/Relational Operator11'
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  if (CAL_Scf_flgDrvToPostWihDisSwt_b) {
    VAR_Scf_flgTranPreDrvToFault_b_ = ((SWC_SCF_DW.UnitDelay1_DSTATE_e ==
      ((uint8)PRV_DisChgEnd)) || (SWC_SCF_DW.UnitDelay1_DSTATE_e == ((uint8)
      PRV_DisChgFail)));
  } else {
    VAR_Scf_flgTranPreDrvToFault_b_ = ((SWC_SCF_DW.UnitDelay1_DSTATE_e ==
      ((uint8)PRV_DisChgEnd)) || (SWC_SCF_DW.UnitDelay1_DSTATE_e == ((uint8)
      PRV_DisChgFail)) || rtb_flgReqAllwDrvByUTnet);
  }

  /* End of Switch: '<S60>/Switch' */

  /* Logic: '<S60>/Logical Operator4' */
  VAR_Scf_flgTranFaultToPostDrv_b = (VAR_Scf_flgShtDwnByMcu_b_tmp &&
    VAR_Scf_flgTranPreDrvToFault_b_);

  /* Switch: '<S62>/Switch2' incorporates:
   *  Constant: '<S62>/Constant4'
   *  Sum: '<S62>/Add'
   *  Switch: '<S62>/Switch3'
   *  UnitDelay: '<S62>/Unit Delay1'
   *  UnitDelay: '<S62>/Unit Delay2'
   */
  if (VAR_Scf_VCUComErr_b) {
    SWC_SCF_DW.UnitDelay1_DSTATE_k = 0U;
  }

  SWC_SCF_DW.UnitDelay1_DSTATE_k = (uint16)((uint32)
    SWC_SCF_DW.UnitDelay1_DSTATE_k + !SWC_SCF_DW.UnitDelay2_DSTATE_p);

  /* End of Switch: '<S62>/Switch2' */

  /* RelationalOperator: '<S62>/Relational Operator2' incorporates:
   *  Constant: '<S62>/CAL_Scf_cntVCUComErrLim_u16'
   *  UnitDelay: '<S62>/Unit Delay1'
   *  UnitDelay: '<S62>/Unit Delay2'
   */
  SWC_SCF_DW.UnitDelay2_DSTATE_p = (SWC_SCF_DW.UnitDelay1_DSTATE_k >=
    CAL_Scf_cntVCUComErrLim_u16);

  /* Switch: '<S59>/Switch5' incorporates:
   *  Constant: '<S59>/PRV_ShutDownReq'
   *  RelationalOperator: '<S59>/Relational Operator1'
   *  Switch: '<S59>/Switch3'
   *  UnitDelay: '<S59>/Unit Delay'
   *  UnitDelay: '<S62>/Unit Delay2'
   */
  if (VAR_Scf_VCUComErr_b) {
    SWC_SCF_DW.UnitDelay_DSTATE_h = (SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF ==
      ((uint8)PRV_ShutDownReq));
  } else {
    if (SWC_SCF_DW.UnitDelay2_DSTATE_p) {
      /* Switch: '<S59>/Switch3' incorporates:
       *  UnitDelay: '<S59>/Unit Delay'
       */
      SWC_SCF_DW.UnitDelay_DSTATE_h = VAR_Scf_flgTranFaultToPostDrv_b;
    }
  }

  /* End of Switch: '<S59>/Switch5' */

  /* Switch: '<S59>/Switch' incorporates:
   *  Constant: '<S59>/CAL_Scf_IntDchaSwt_b'
   *  Logic: '<S61>/Logical Operator'
   *  Logic: '<S61>/Logical Operator3'
   *  Logic: '<S61>/Logical Operator5'
   */
  if (CAL_Scf_IntDchaSwt_b) {
    /* Switch: '<S59>/Switch1' incorporates:
     *  Constant: '<S59>/CAL_Scf_ShtDwnReqByVcuSwt_b'
     *  UnitDelay: '<S59>/Unit Delay'
     */
    if (CAL_Scf_ShtDwnReqByVcuSwt_b) {
      VAR_Scf_flgTranFaultToPostDrv_b = SWC_SCF_DW.UnitDelay_DSTATE_h;
    }

    /* End of Switch: '<S59>/Switch1' */
  } else {
    VAR_Scf_flgTranFaultToPostDrv_b = ((rtb_LogicalOperator2_l && rtb_Switch1_b &&
      VAR_Scf_flgShtDwnByMcu_b_tmp__2) || (rtb_LogicalOperator2_l &&
      rtb_flgReqAllwDrvByUTnet));
  }

  /* SignalConversion generated from: '<S1>/RP_SWC_Snapshot_Snapshot_flgPostDrvDone_read' incorporates:
   *  Inport: '<Root>/RP_SWC_Snapshot_Snapshot_flgPostDrvDone'
   */
  Rte_Read_RP_SWC_Snapshot_Snapshot_flgPostDrvDone
    (&rtb_TmpSignalConversionAtRP_S_l);

  /* Logic: '<S44>/Logical Operator2' */
  rtb_LogicalOperator2_l = (rtb_TmpSignalConversionAtRP_S_o ||
    rtb_TmpSignalConversionAtRP_S_i || rtb_TmpSignalConversionAtRP__on);

  /* Logic: '<S50>/Logical Operator' incorporates:
   *  UnitDelay: '<S50>/Unit Delay'
   */
  VAR_Scf_flgInitOut_b = !SWC_SCF_DW.UnitDelay_DSTATE_c;

  /* Outputs for Enabled SubSystem: '<S44>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S49>/Enable'
   */
  /* Logic: '<S44>/Logical Operator' incorporates:
   *  Inport: '<S49>/HSPF_bt15'
   */
  if (VAR_Scf_flgInitOut_b && rtb_LogicalOperator2_l) {
    /* SignalConversion generated from: '<S49>/flgInit' incorporates:
     *  Constant: '<S49>/Constant'
     *  UnitDelay: '<S50>/Unit Delay'
     */
    SWC_SCF_DW.UnitDelay_DSTATE_c = true;
    VAR_Scf_flgbt15first_b = true;
  }

  /* End of Logic: '<S44>/Logical Operator' */
  /* End of Outputs for SubSystem: '<S44>/Enabled Subsystem' */

  /* RelationalOperator: '<S44>/Relational Operator1' incorporates:
   *  Constant: '<S44>/PostDriveMod'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  rtb_Switch1_b = (SWC_SCF_DW.UnitDelay_DSTATE == PostDriveMod);

  /* RelationalOperator: '<S44>/Relational Operator' */
  rtb_TmpSignalConversionAtRP_S_o = !rtb_TmpSignalConversionAtRP_S_l;

  /* Logic: '<S44>/Logical Operator1' */
  VAR_Scf_flgWakeNormal_b = (VAR_Scf_flgbt15first_b && rtb_Switch1_b &&
    rtb_TmpSignalConversionAtRP_S_o);

  /* Switch: '<S51>/Switch1' incorporates:
   *  Constant: '<S51>/Constant3'
   *  RelationalOperator: '<S52>/Compare'
   *  UnitDelay: '<S51>/Unit Delay'
   */
  if (!rtb_LogicalOperator2_l) {
    /* Sum: '<S51>/Sum' incorporates:
     *  UnitDelay: '<S51>/Unit Delay'
     *  UnitDelay: '<S51>/Unit Delay1'
     */
    SWC_SCF_DW.UnitDelay_DSTATE_p = (uint16)((uint32)!VAR_Scf_flgNoWakeSou_b +
      SWC_SCF_DW.UnitDelay_DSTATE_p);

    /* Switch: '<S51>/Switch' incorporates:
     *  Constant: '<S51>/Constant1'
     *  RelationalOperator: '<S51>/Relational Operator'
     *  UnitDelay: '<S51>/Unit Delay'
     */
    if (SWC_SCF_DW.UnitDelay_DSTATE_p >= 65535) {
      SWC_SCF_DW.UnitDelay_DSTATE_p = MAX_uint16_T;
    }

    /* End of Switch: '<S51>/Switch' */
  } else {
    SWC_SCF_DW.UnitDelay_DSTATE_p = 0U;
  }

  /* End of Switch: '<S51>/Switch1' */

  /* RelationalOperator: '<S51>/Relational Operator1' incorporates:
   *  Constant: '<S51>/CAL_SmgSys_cntWakeLoss_u16'
   *  Product: '<S51>/Product'
   *  UnitDelay: '<S51>/Unit Delay'
   */
  VAR_Scf_flgNoWakeSou_b = (SWC_SCF_DW.UnitDelay_DSTATE_p >=
    CAL_Scf_cntWakeLoss_u16);

  /* Logic: '<S44>/Logical Operator5' */
  VAR_Scf_flgWakeLoss_b = (rtb_Switch1_b && rtb_TmpSignalConversionAtRP_S_o &&
    VAR_Scf_flgNoWakeSou_b);

  /* Logic: '<S44>/Logical Operator4' */
  rtb_LogicalOperator2_l = (VAR_Scf_flgWakeNormal_b || VAR_Scf_flgWakeLoss_b);

  /* Switch: '<S48>/Switch1' incorporates:
   *  Constant: '<S48>/Constant3'
   *  UnitDelay: '<S48>/Unit Delay'
   */
  if (rtb_LogicalOperator2_l) {
    /* Sum: '<S48>/Sum' incorporates:
     *  UnitDelay: '<S48>/Unit Delay'
     *  UnitDelay: '<S48>/Unit Delay1'
     */
    SWC_SCF_DW.UnitDelay_DSTATE_g = (uint16)((uint32)
      !SWC_SCF_DW.UnitDelay1_DSTATE_o + SWC_SCF_DW.UnitDelay_DSTATE_g);

    /* Switch: '<S48>/Switch' incorporates:
     *  Constant: '<S48>/Constant1'
     *  RelationalOperator: '<S48>/Relational Operator'
     *  UnitDelay: '<S48>/Unit Delay'
     */
    if (SWC_SCF_DW.UnitDelay_DSTATE_g >= 65535) {
      SWC_SCF_DW.UnitDelay_DSTATE_g = MAX_uint16_T;
    }

    /* End of Switch: '<S48>/Switch' */
  } else {
    SWC_SCF_DW.UnitDelay_DSTATE_g = 0U;
  }

  /* End of Switch: '<S48>/Switch1' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_SCF_10ms' */

  /* Inport: '<Root>/RP_SWC_PCF_PCF_flgShtDwnReq' */
  Rte_Read_RP_SWC_PCF_PCF_flgShtDwnReq(&tmpRead_1);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_SCF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_SCF_10ms_sys'
   */
  /* RelationalOperator: '<S48>/Relational Operator1' incorporates:
   *  Constant: '<S48>/CAL_SmgSys_cntPostDrvDone_u16'
   *  Product: '<S48>/Product'
   *  UnitDelay: '<S48>/Unit Delay'
   *  UnitDelay: '<S48>/Unit Delay1'
   */
  SWC_SCF_DW.UnitDelay1_DSTATE_o = (SWC_SCF_DW.UnitDelay_DSTATE_g >=
    CAL_Scf_cntPostDrvDone_u16);

  /* Switch: '<S48>/Switch3' incorporates:
   *  Constant: '<S48>/Constant2'
   *  Constant: '<S48>/Constant6'
   *  UnitDelay: '<S48>/Unit Delay1'
   */
  if (SWC_SCF_DW.UnitDelay1_DSTATE_o) {
    VAR_Scf_flgShutDwnOvtimErr_u8 = 3U;
  } else {
    VAR_Scf_flgShutDwnOvtimErr_u8 = 2U;
  }

  /* End of Switch: '<S48>/Switch3' */

  /* Logic: '<S44>/Logical Operator3' incorporates:
   *  Constant: '<S44>/Constant1'
   *  RelationalOperator: '<S44>/Relational Operator2'
   */
  VAR_Scf_flgPostDrvDone_b = ((VAR_Scf_flgShutDwnOvtimErr_u8 == 3) ||
    rtb_TmpSignalConversionAtRP_S_l);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_SCF_10ms' */

  /* Inport: '<Root>/RP_SWC_MDF_MDF_stFrwhl' */
  Rte_Read_RP_SWC_MDF_MDF_stFrwhl(&tmpRead_0);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_SCF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_SCF_10ms_sys'
   */
  /* Switch: '<S45>/Switch' incorporates:
   *  Constant: '<S45>/CAL_Scf_flgCanNmSwt_b'
   *  Constant: '<S45>/Constant'
   */
  if (!CAL_Scf_flgCanNmSwt_b) {
    VAR_Scf_flgShtDwnByMcu_b_tmp__1 = true;
  }

  /* End of Switch: '<S45>/Switch' */

  /* Logic: '<S45>/Logical Operator' incorporates:
   *  Constant: '<S45>/CAL_Scf_flgEpcShutdownSwt_b'
   *  Switch: '<S45>/Switch1'
   */
  VAR_Scf_flgTranPostDrvToSutDwn_b = (VAR_Scf_flgPostDrvDone_b &&
    rtb_flgReqAllwDrvByN && (CAL_Scf_flgEpcShutdownSwt_b || tmpRead_1) &&
    VAR_Scf_flgShtDwnByMcu_b_tmp__1);

  /* SignalConversion generated from: '<S1>/RP_SWC_Igbt_Igbt_flgGateDrvRdyLs_read' incorporates:
   *  Inport: '<Root>/RP_SWC_Igbt_Igbt_flgGateDrvRdyLs'
   */
  Rte_Read_RP_SWC_Igbt_Igbt_flgGateDrvRdyLs(&rtb_TmpSignalConversionAtRP_S_f);

  /* SignalConversion generated from: '<S1>/RP_SWC_Igbt_Igbt_flgGateDrvRdyHs_read' incorporates:
   *  Inport: '<Root>/RP_SWC_Igbt_Igbt_flgGateDrvRdyHs'
   */
  Rte_Read_RP_SWC_Igbt_Igbt_flgGateDrvRdyHs(&rtb_TmpSignalConversionAtRP_S_g);

  /* Logic: '<S34>/Logical Operator' incorporates:
   *  Abs: '<S4>/Abs1'
   *  Constant: '<S34>/CAL_Scf_FLOATZERO_f32'
   *  Constant: '<S34>/CAL_Scf_LowPwrSetUpSud_u8'
   *  Constant: '<S34>/CAL_Scf_nSnsrClbFw_f32'
   *  Logic: '<S25>/Logical Operator'
   *  RelationalOperator: '<S34>/Relational Operator1'
   *  RelationalOperator: '<S34>/Relational Operator2'
   *  RelationalOperator: '<S34>/Relational Operator3'
   */
  rtb_TmpSignalConversionAtRP_S_f = (rtb_TmpSignalConversionAtRP_S_f &&
    rtb_TmpSignalConversionAtRP_S_g);
  VAR_Scf_flgTranLoPowSetToDia_b = (rtb_TmpSignalConversionAtRP_S_f &&
    (rtb_TmpSignalConversionAtRP_SWC <= CAL_Scf_nSnsrClbFw_f32) &&
    (rtb_TmpSignalConversionAtRP_S_p <= CAL_Scf_FLOATZERO_f32) &&
    (rtb_TmpSignalConversionAtRP__gi == CAL_Scf_LowPwrSetUpSud_u8));

  /* Logic: '<S33>/Logical Operator' incorporates:
   *  Abs: '<S4>/Abs1'
   *  Constant: '<S33>/CAL_Scf_FLOATZERO_f32'
   *  Constant: '<S33>/CAL_Scf_WithoutStatorCurrent_u8'
   *  Constant: '<S33>/CAL_SmgSys_nSnsrClbFw_f32'
   *  RelationalOperator: '<S33>/Relational Operator'
   *  RelationalOperator: '<S33>/Relational Operator1'
   *  RelationalOperator: '<S33>/Relational Operator2'
   */
  VAR_Scf_flgTranDiagToSenCal_b = ((tmpRead_0 == CAL_Scf_WithoutStatorCurrent_u8)
    && (rtb_TmpSignalConversionAtRP_SWC <= CAL_Scf_nSnsrClbFw_f32) &&
    (rtb_TmpSignalConversionAtRP_S_p <= CAL_Scf_FLOATZERO_f32));

  /* RelationalOperator: '<S36>/Relational Operator' incorporates:
   *  Constant: '<S36>/CAL_Scf_SenChkSud_u8'
   */
  VAR_Scf_flgTranSenCalToiMMO_b = (rtb_TmpSignalConversionAtRP_S_j ==
    CAL_Scf_SenChkSud_u8);

  /* RelationalOperator: '<S35>/Relational Operator' incorporates:
   *  Constant: '<S35>/CAL_Scf_SenChkSud_u8'
   */
  VAR_Scf_flgTranPreDrvRunToFish_b = (rtb_TmpSignalConversionAtRP_S_j ==
    CAL_Scf_SenChkSud_u8);

  /* Switch: '<S23>/Switch' incorporates:
   *  Constant: '<S23>/CAL_Scf_udcPrechgFail_f32'
   *  Constant: '<S23>/CAL_Scf_udcPrechgFish_f32'
   *  Constant: '<S23>/Constant1'
   *  Delay: '<S23>/Delay'
   *  RelationalOperator: '<S23>/Relational Operator'
   *  RelationalOperator: '<S23>/Relational Operator1'
   */
  if (SWC_SCF_B.TmpSignalConversionAtRP_SWC_HSP >= CAL_Scf_udcPrechgFish_f32) {
    SWC_SCF_DW.Delay_DSTATE = true;
  } else {
    SWC_SCF_DW.Delay_DSTATE = ((SWC_SCF_B.TmpSignalConversionAtRP_SWC_HSP >
      CAL_Scf_udcPrechgFail_f32) && SWC_SCF_DW.Delay_DSTATE);
  }

  /* End of Switch: '<S23>/Switch' */

  /* Logic: '<S25>/Logical Operator' incorporates:
   *  Logic: '<S25>/Logical Operator1'
   */
  VAR_Scf_flgTranIdleToStb_b = (rtb_TmpSignalConversionAtRP_S_f &&
    (rtb_TmpSignalConversionAtRP__on || rtb_TmpSignalConversionAtRP_S_i) &&
    SWC_SCF_DW.Delay_DSTATE);

  /* RelationalOperator: '<S30>/Relational Operator' */
  VAR_Scf_flgTranStbToIdle_b = !SWC_SCF_DW.Delay_DSTATE;

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S32>/Constant'
   *  Constant: '<S32>/Constant1'
   *  Inport: '<Root>/RP_SWC_NvM_NvM_flgAngAutoClbOffset'
   */
  if (CAL_Scf_flgOfsClbSwt_b) {
    Rte_Read_RP_SWC_NvM_NvM_flgAngAutoClbOffset(&rtb_TmpSignalConversionAtRP_S_o);
  } else {
    rtb_TmpSignalConversionAtRP_S_o = true;
  }

  /* End of Switch: '<S32>/Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_SCF_10ms' */

  /* Inport: '<Root>/RP_SWC_PCF_PCF_flgAllowPwmRun' */
  Rte_Read_RP_SWC_PCF_PCF_flgAllowPwmRun(&tmpRead_2);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_SCF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_SCF_10ms_sys'
   */
  /* Logic: '<S32>/Logical Operator' incorporates:
   *  Constant: '<S32>/Constant2'
   *  Constant: '<S32>/PRV_TrqCtlReq'
   *  Constant: '<S32>/PRV_UdcCtlBatReq'
   *  Constant: '<S32>/PRV_UdcCtlReq'
   *  Constant: '<S32>/PRV_isCtlReq'
   *  Constant: '<S32>/PRV_nCtLintReq'
   *  Constant: '<S32>/PRV_nCtlExtReq'
   *  Logic: '<S32>/Logical Operator2'
   *  RelationalOperator: '<S32>/Relational Operator'
   *  RelationalOperator: '<S32>/Relational Operator2'
   *  RelationalOperator: '<S32>/Relational Operator3'
   *  RelationalOperator: '<S32>/Relational Operator4'
   *  RelationalOperator: '<S32>/Relational Operator5'
   *  RelationalOperator: '<S32>/Relational Operator6'
   *  Switch: '<S32>/Switch1'
   */
  VAR_Scf_flgTranStbToRun_b = (((SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF ==
    ((uint8)PRV_UdcCtlReq)) || (SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF ==
    ((uint8)PRV_nCtLintReq)) || (SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF ==
    ((uint8)PRV_isCtlReq)) || (SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF ==
    ((uint8)PRV_UdcCtlBatReq)) || (SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF ==
    ((uint8)PRV_nCtlExtReq)) || (SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF ==
    ((uint8)PRV_TrqCtlReq))) && rtb_TmpSignalConversionAtRP_S_o &&
    rtb_TmpSignalConversionAtRP_S_i && ((!CAL_Scf_flgPcfAllowPwmRunSwt_b) ||
    tmpRead_2));

  /* Switch: '<S28>/Switch' incorporates:
   *  Abs: '<S4>/Abs1'
   *  Constant: '<S28>/CAL_Scf_flgJumpRunBy15Swt_b'
   *  Constant: '<S28>/CAL_Scf_nRunTostb_f32'
   *  Constant: '<S28>/PRV_UdcCtlReq'
   *  Constant: '<S28>/PRV_UdcCtlReq1'
   *  Constant: '<S28>/PRV_UdcCtlReq2'
   *  Constant: '<S28>/PRV_UdcCtlReq3'
   *  Constant: '<S28>/PRV_UdcCtlReq4'
   *  Constant: '<S28>/PRV_UdcCtlReq5'
   *  Logic: '<S28>/Logical Operator'
   *  Logic: '<S28>/Logical Operator1'
   *  Logic: '<S28>/Logical Operator2'
   *  RelationalOperator: '<S28>/Relational Operator'
   *  RelationalOperator: '<S28>/Relational Operator1'
   *  RelationalOperator: '<S28>/Relational Operator2'
   *  RelationalOperator: '<S28>/Relational Operator3'
   *  RelationalOperator: '<S28>/Relational Operator4'
   *  RelationalOperator: '<S28>/Relational Operator5'
   *  RelationalOperator: '<S28>/Relational Operator6'
   */
  if (CAL_Scf_flgJumpRunBy15Swt_b) {
    VAR_Scf_flgTranRunToStb_b = (VAR_Scf_flgShtDwnByMcu_b_tmp__0 ||
      ((SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF != ((uint8)PRV_UdcCtlReq)) &&
       (SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF != ((uint8)PRV_nCtLintReq)) &&
       (SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF != ((uint8)PRV_isCtlReq)) &&
       (SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF != ((uint8)PRV_UdcCtlBatReq)) &&
       (SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF != ((uint8)PRV_nCtlExtReq)) &&
       (SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF != ((uint8)PRV_TrqCtlReq)) &&
       (rtb_TmpSignalConversionAtRP_SWC <= CAL_Scf_nRunTostb_f32)));
  } else {
    VAR_Scf_flgTranRunToStb_b = ((SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF !=
      ((uint8)PRV_UdcCtlReq)) && (SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF !=
      ((uint8)PRV_nCtLintReq)) && (SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF !=
      ((uint8)PRV_isCtlReq)) && (SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF !=
      ((uint8)PRV_UdcCtlBatReq)) && (SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF
      != ((uint8)PRV_nCtlExtReq)) && (SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF
      != ((uint8)PRV_TrqCtlReq)) && (rtb_TmpSignalConversionAtRP_SWC <=
      CAL_Scf_nRunTostb_f32));
  }

  /* End of Switch: '<S28>/Switch' */

  /* RelationalOperator: '<S31>/Relational Operator' incorporates:
   *  Constant: '<S31>/PRV_OfsCalReq'
   */
  VAR_Scf_flgTranStbToOfstCal_b = (SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF ==
    ((uint8)PRV_OfsCalReq));

  /* RelationalOperator: '<S27>/Relational Operator' incorporates:
   *  Constant: '<S27>/PRV_OfsCalReq'
   */
  VAR_Scf_flgTranOfstCalToStb_b = (SWC_SCF_B.TmpSignalConversionAtRP_SWC_VCF !=
    ((uint8)PRV_OfsCalReq));

  /* Logic: '<S26>/Logical Operator' */
  VAR_Scf_flgTranNormalToDcha_b = VAR_Scf_flgTranFaultToDcha_b;

  /* Logic: '<S24>/Logical Operator2' incorporates:
   *  Constant: '<S24>/CAL_Scf_uSafeVolt_f32'
   *  Constant: '<S24>/PRV_DisChgEnd'
   *  Logic: '<S24>/Logical Operator'
   *  RelationalOperator: '<S24>/Relational Operator'
   *  RelationalOperator: '<S24>/Relational Operator1'
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  VAR_Scf_flgTranDchaToNormal_b = (((SWC_SCF_B.TmpSignalConversionAtRP_SWC_HSP <=
    CAL_Scf_uSafeVolt_f32) || (SWC_SCF_DW.UnitDelay1_DSTATE_e == ((uint8)
    PRV_DisChgEnd))) && VAR_Scf_flgFimFaultLvFour_b &&
    rtb_TmpSignalConversionAtRP_S_i);

  /* SignalConversion generated from: '<S1>/RP_SWC_PCF_PCF_stParkCtl_read' incorporates:
   *  Inport: '<Root>/RP_SWC_PCF_PCF_stParkCtl'
   */
  Rte_Read_RP_SWC_PCF_PCF_stParkCtl(&rtb_TmpSignalConversionAtRP__jm);

  /* Logic: '<S29>/Logical Operator' incorporates:
   *  Constant: '<S29>/CAL_SCF_flgUseSLCal_b'
   *  Constant: '<S29>/SLCtl'
   *  RelationalOperator: '<S29>/Relational Operator'
   */
  VAR_Scf_flgTranStbToSLCal_b = ((rtb_TmpSignalConversionAtRP__jm == 3) &&
    CAL_SCF_flgUseSLCal_b);

  /* Logic: '<S29>/Logical Operator1' incorporates:
   *  Constant: '<S29>/CAL_SCF_flgUseSLCal_b'
   *  Constant: '<S29>/SLCtl'
   *  RelationalOperator: '<S29>/Relational Operator1'
   *  RelationalOperator: '<S29>/Relational Operator2'
   */
  VAR_Scf_flgTranSLCalToStb_b = ((rtb_TmpSignalConversionAtRP__jm != 3) ||
    (!CAL_SCF_flgUseSLCal_b));

  /* SignalConversion generated from: '<S1>/RP_SWC_PCF_PCF_SLEnMotorAcc_read' incorporates:
   *  Inport: '<Root>/RP_SWC_PCF_PCF_SLEnMotorAcc'
   */
  Rte_Read_RP_SWC_PCF_PCF_SLEnMotorAcc(&rtb_TmpSignalConversionAtRP__kb);

  /* SignalConversion generated from: '<S1>/RP_SWC_PCF_PCF_Status_read' incorporates:
   *  Inport: '<Root>/RP_SWC_PCF_PCF_Status'
   */
  Rte_Read_RP_SWC_PCF_PCF_Status(&rtb_TmpSignalConversionAtRP__lv);

  /* Logic: '<S29>/Logical Operator2' incorporates:
   *  Constant: '<S29>/Constant2'
   *  RelationalOperator: '<S29>/Relational Operator3'
   *  RelationalOperator: '<S29>/Relational Operator4'
   */
  VAR_Scf_flgTranSLInitToSLAcc_b = (rtb_TmpSignalConversionAtRP__kb &&
    (rtb_TmpSignalConversionAtRP__lv == 20));

  /* Logic: '<S29>/Logical Operator3' incorporates:
   *  Constant: '<S29>/Constant3'
   *  RelationalOperator: '<S29>/Relational Operator5'
   *  RelationalOperator: '<S29>/Relational Operator6'
   */
  VAR_Scf_flgTranSLInitToSLFw_b = ((!rtb_TmpSignalConversionAtRP__kb) ||
    (rtb_TmpSignalConversionAtRP__lv != 20));

  /* Chart: '<S3>/SCF_stSysDrvCtl_Switch' */
  if (SWC_SCF_DW.is_active_c187_SWC_SCF == 0U) {
    SWC_SCF_DW.is_active_c187_SWC_SCF = 1U;
    SWC_SCF_DW.SCF_flgDrvCycle = false;
    SWC_SCF_DW.is_c187_SWC_SCF = SWC_SCF_IN_PreDrive;
    SWC_SCF_DW.is_PreDrive = SWC_SCF_IN_PreDriveInitial;
    SWC_SCF_B.SCF_stSysCtl_en = PreDriveMod;
    SWC_SCF_B.SCF_stGateDrv = ((uint8)PRV_IGBTClose);
    SWC_SCF_B.SCF_stDrvCtl_en = Drv_Initial;
    SWC_SCF_B.SCF_stDisChg = ((uint8)PRV_DisChgInAct);
    SWC_SCF_B.SCF_flgActvDcha = false;
    Var_Scf_flgDisChgFail_b = false;
    SWC_SCF_B.SCF_stPreDrvCtl = ((uint8)PRV_PreDrv_iNiT);
  } else {
    switch (SWC_SCF_DW.is_c187_SWC_SCF) {
     case SWC_SCF_IN_Drive:
      SWC_SCF_Drive(&rtb_TmpSignalConversionAtRP_SWC);
      break;

     case SWC_SCF_IN_Fault:
      SWC_SCF_B.SCF_stGateDrv = SWC_SCF_PreDrv_GateDrv
        (rtb_TmpSignalConversionAtRP_SWC, (float64)SWC_SCF_B.SCF_stGateDrv);
      if (VAR_Scf_flgTranFaultToDcha_b) {
        SWC_SCF_DW.SCF_flgFaultToDcha = true;
        SWC_SCF_DW.is_c187_SWC_SCF = SWC_SCF_IN_Drive;
        SWC_SCF_B.SCF_stSysCtl_en = DriveMod;
        SWC_SCF_DW.is_Drive = SWC_SCF_IN_Normal;
        SWC_SCF_DW.is_Normal = SWC_SCF_IN_IdLe;
        SWC_SCF_B.SCF_stDrvCtl_en = Drv_IdLe;
        SWC_SCF_B.SCF_stGateDrv = SWC_SCF_GateDrvCalcn
          (rtb_TmpSignalConversionAtRP_SWC, SWC_SCF_B.SCF_stGateDrv);
        SWC_SCF_B.SCF_stDisChg = ((uint8)PRV_DisChgInAct);
        SWC_SCF_B.SCF_flgActvDcha = false;
        Var_Scf_flgDisChgFail_b = false;
      } else {
        SWC_SCF_B.SCF_stGateDrv = SWC_SCF_PreDrv_GateDrv
          (rtb_TmpSignalConversionAtRP_SWC, (float64)SWC_SCF_B.SCF_stGateDrv);
        if (VAR_Scf_flgTranFaultToPostDrv_b) {
          SWC_SCF_DW.is_c187_SWC_SCF = SWC_SCF_IN_PostDrive;
          SWC_SCF_B.SCF_stSysCtl_en = PostDriveMod;
          SWC_SCF_B.SCF_stGateDrv = SWC_SCF_PreDrv_GateDrv
            (rtb_TmpSignalConversionAtRP_SWC, (float64)SWC_SCF_B.SCF_stGateDrv);
        }
      }
      break;

     case SWC_SCF_IN_PostDrive:
      SWC_SCF_B.SCF_stGateDrv = SWC_SCF_PreDrv_GateDrv
        (rtb_TmpSignalConversionAtRP_SWC, (float64)SWC_SCF_B.SCF_stGateDrv);
      if (VAR_Scf_flgTranPostDrvToPreDrv_b) {
        SWC_SCF_DW.is_c187_SWC_SCF = SWC_SCF_IN_PreDrive;
        SWC_SCF_DW.is_PreDrive = SWC_SCF_IN_PreDriveInitial;
        SWC_SCF_B.SCF_stSysCtl_en = PreDriveMod;
        SWC_SCF_B.SCF_stGateDrv = ((uint8)PRV_IGBTClose);
        SWC_SCF_B.SCF_stDrvCtl_en = Drv_Initial;
        SWC_SCF_B.SCF_stDisChg = ((uint8)PRV_DisChgInAct);
        SWC_SCF_B.SCF_flgActvDcha = false;
        Var_Scf_flgDisChgFail_b = false;
        SWC_SCF_B.SCF_stPreDrvCtl = ((uint8)PRV_PreDrv_iNiT);
      } else {
        SWC_SCF_B.SCF_stGateDrv = SWC_SCF_PreDrv_GateDrv
          (rtb_TmpSignalConversionAtRP_SWC, (float64)SWC_SCF_B.SCF_stGateDrv);
        if (VAR_Scf_flgTranPostDrvToSutDwn_b) {
          SWC_SCF_DW.is_c187_SWC_SCF = SWC_SCF_IN_ShutDown;
          SWC_SCF_B.SCF_stSysCtl_en = ShutDownMod;
          SWC_SCF_B.SCF_stGateDrv = SWC_SCF_PreDrv_GateDrv
            (rtb_TmpSignalConversionAtRP_SWC, (float64)SWC_SCF_B.SCF_stGateDrv);
        }
      }
      break;

     case SWC_SCF_IN_PreDrive:
      if (VAR_Scf_flgTranPreDrvToFault_b) {
        SWC_SCF_DW.is_PreDriveRun = 0;
        SWC_SCF_DW.is_PreDrive = 0;
        SWC_SCF_DW.is_c187_SWC_SCF = SWC_SCF_IN_Fault;
        SWC_SCF_B.SCF_stSysCtl_en = FaultMod;
        SWC_SCF_B.SCF_stDrvCtl_en = Drv_Failure;
        SWC_SCF_B.SCF_stGateDrv = SWC_SCF_PreDrv_GateDrv
          (rtb_TmpSignalConversionAtRP_SWC, (float64)SWC_SCF_B.SCF_stGateDrv);
      } else if (VAR_Scf_flgTranPreDrvToDrv_b && (SWC_SCF_B.SCF_stPreDrvCtl ==
                  ((uint8)PRV_PreDrv_Fishd))) {
        SWC_SCF_DW.is_PreDriveRun = 0;
        SWC_SCF_DW.is_PreDrive = 0;
        SWC_SCF_DW.is_c187_SWC_SCF = SWC_SCF_IN_Drive;
        SWC_SCF_B.SCF_stSysCtl_en = DriveMod;
        SWC_SCF_DW.is_Drive = SWC_SCF_IN_Normal;
        SWC_SCF_DW.is_Normal = SWC_SCF_IN_IdLe;
        SWC_SCF_B.SCF_stDrvCtl_en = Drv_IdLe;
        SWC_SCF_B.SCF_stGateDrv = SWC_SCF_GateDrvCalcn
          (rtb_TmpSignalConversionAtRP_SWC, SWC_SCF_B.SCF_stGateDrv);
        SWC_SCF_B.SCF_stDisChg = ((uint8)PRV_DisChgInAct);
        SWC_SCF_B.SCF_flgActvDcha = false;
        Var_Scf_flgDisChgFail_b = false;
      } else if (VAR_Scf_flgTranPreDrvToPostDrv_b) {
        SWC_SCF_DW.is_PreDriveRun = 0;
        SWC_SCF_DW.is_PreDrive = 0;
        SWC_SCF_DW.is_c187_SWC_SCF = SWC_SCF_IN_PostDrive;
        SWC_SCF_B.SCF_stSysCtl_en = PostDriveMod;
        SWC_SCF_B.SCF_stGateDrv = SWC_SCF_PreDrv_GateDrv
          (rtb_TmpSignalConversionAtRP_SWC, (float64)SWC_SCF_B.SCF_stGateDrv);
      } else {
        switch (SWC_SCF_DW.is_PreDrive) {
         case SWC_SCF_IN_PreDriveFish:
          SWC_SCF_B.SCF_stGateDrv = SWC_SCF_PreDrv_GateDrv
            (rtb_TmpSignalConversionAtRP_SWC, (float64)SWC_SCF_B.SCF_stGateDrv);
          SWC_SCF_DW.is_PreDrive = SWC_SCF_IN_PreDriveFish;
          SWC_SCF_DW.SCF_flgDrvCycle = true;
          SWC_SCF_B.SCF_stPreDrvCtl = ((uint8)PRV_PreDrv_Fishd);
          break;

         case SWC_SCF_IN_PreDriveInitial:
          if (!SWC_SCF_DW.SCF_flgDrvCycle) {
            SWC_SCF_DW.is_PreDrive = SWC_SCF_IN_PreDriveRun;
            SWC_SCF_DW.is_PreDriveRun = SWC_SCF_IN_LowPower_SetUp;
            SWC_SCF_B.SCF_stPreDrvCtl = ((uint8)PRV_PreDrv_LowPwrSetUp);
          } else {
            SWC_SCF_DW.is_PreDrive = SWC_SCF_IN_PreDriveFish;
            SWC_SCF_DW.SCF_flgDrvCycle = true;
            SWC_SCF_B.SCF_stPreDrvCtl = ((uint8)PRV_PreDrv_Fishd);
          }
          break;

         default:
          /* case IN_PreDriveRun: */
          SWC_SCF_B.SCF_stGateDrv = SWC_SCF_PreDrv_GateDrv
            (rtb_TmpSignalConversionAtRP_SWC, (float64)SWC_SCF_B.SCF_stGateDrv);
          if (VAR_Scf_flgTranPreDrvRunToFish_b && (SWC_SCF_B.SCF_stPreDrvCtl ==
               ((uint8)PRV_PreDrv_iMMO))) {
            SWC_SCF_DW.is_PreDriveRun = 0;
            SWC_SCF_DW.is_PreDrive = SWC_SCF_IN_PreDriveFish;
            SWC_SCF_DW.SCF_flgDrvCycle = true;
            SWC_SCF_B.SCF_stPreDrvCtl = ((uint8)PRV_PreDrv_Fishd);
          } else {
            switch (SWC_SCF_DW.is_PreDriveRun) {
             case SWC_SCF_IN_LowPower_SetUp:
              SWC_SCF_B.SCF_stGateDrv = SWC_SCF_PreDrv_GateDrv
                (rtb_TmpSignalConversionAtRP_SWC, (float64)
                 SWC_SCF_B.SCF_stGateDrv);
              if (VAR_Scf_flgTranLoPowSetToDia_b) {
                SWC_SCF_DW.is_PreDriveRun = SWC_SCF_IN_ShelfCheck;
                SWC_SCF_B.SCF_stPreDrvCtl = ((uint8)PRV_PreDrv_ShelfCheck);
              }
              break;

             case SWC_SCF_IN_SensCalFW:
              SWC_SCF_B.SCF_stGateDrv = SWC_SCF_PreDrv_GateDrv
                (rtb_TmpSignalConversionAtRP_SWC, (float64)
                 SWC_SCF_B.SCF_stGateDrv);
              if (VAR_Scf_flgTranSenCalToiMMO_b) {
                SWC_SCF_DW.is_PreDriveRun = SWC_SCF_IN_iMMO;
                SWC_SCF_B.SCF_stPreDrvCtl = ((uint8)PRV_PreDrv_iMMO);
              }
              break;

             case SWC_SCF_IN_ShelfCheck:
              SWC_SCF_B.SCF_stGateDrv = SWC_SCF_PreDrv_GateDrv
                (rtb_TmpSignalConversionAtRP_SWC, (float64)
                 SWC_SCF_B.SCF_stGateDrv);
              if (VAR_Scf_flgTranDiagToSenCal_b) {
                SWC_SCF_DW.is_PreDriveRun = SWC_SCF_IN_SensCalFW;
                SWC_SCF_B.SCF_stPreDrvCtl = ((uint8)PRV_PreDrv_SensCal);
              }
              break;

             default:
              /* case IN_iMMO: */
              break;
            }
          }
          break;
        }
      }
      break;

     default:
      /* case IN_ShutDown: */
      break;
    }
  }

  /* End of Chart: '<S3>/SCF_stSysDrvCtl_Switch' */

  /* Switch: '<S3>/Switch1' incorporates:
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S3>/Constant3'
   */
  if (Var_Scf_flgDisChgFail_b) {
    rtb_TmpSignalConversionAtRP__gi = 3U;
  } else {
    rtb_TmpSignalConversionAtRP__gi = 2U;
  }

  /* End of Switch: '<S3>/Switch1' */

  /* FunctionCaller: '<S1>/RP_SWC_DEM_SCF_DisChgOvTiFail_SetEventStatus' */
  Rte_Call_RP_SWC_DEM_SCF_DisChgOvTiFail_SetEventStatus
    (rtb_TmpSignalConversionAtRP__gi);

  /* FunctionCaller: '<S1>/RP_SWC_DEM_SCF_LowPwrShtDwnOvTiFail_SetEventStatus' */
  Rte_Call_RP_SWC_DEM_SCF_LowPwrShtDwnOvTiFail_SetEventStatus
    (VAR_Scf_flgShutDwnOvtimErr_u8);

  /* Logic: '<S19>/Logical Operator' incorporates:
   *  Constant: '<S19>/Constant1'
   *  RelationalOperator: '<S19>/Relational Operator'
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  rtb_TmpSignalConversionAtRP_S_o = (VAR_Scf_cntSigFit_b &&
    (SWC_SCF_DW.UnitDelay1_DSTATE_e == ((uint8)PRV_DisChgStart)));

  /* Switch: '<S19>/Switch' incorporates:
   *  Constant: '<S20>/Constant3'
   *  Switch: '<S20>/Switch2'
   */
  if (rtb_TmpSignalConversionAtRP_S_o) {
    /* Switch: '<S20>/Switch3' incorporates:
     *  Constant: '<S20>/Constant4'
     *  RelationalOperator: '<S20>/Relational Operator7'
     *  UnitDelay: '<S20>/Unit Delay3'
     */
    if (VAR_Scf_DchaCntAdd_u8 >= 255) {
      VAR_Scf_DchaCntAdd_u8 = MAX_uint8_T;
    }

    /* End of Switch: '<S20>/Switch3' */
  } else {
    VAR_Scf_DischaBeginUdc_f32 = SWC_SCF_B.TmpSignalConversionAtRP_SWC_HSP;
    VAR_Scf_DchaCntAdd_u8 = 0U;
  }

  /* End of Switch: '<S19>/Switch' */

  /* Sum: '<S20>/Add2' incorporates:
   *  Switch: '<S20>/Switch1'
   */
  VAR_Scf_DchaCntAdd_u8 = (uint8)((uint32)rtb_TmpSignalConversionAtRP_S_o +
    VAR_Scf_DchaCntAdd_u8);

  /* Switch: '<S19>/Switch2' incorporates:
   *  Constant: '<S19>/Constant3'
   *  Constant: '<S20>/CAL_Scf_ThreRuntoDischaFail_u8'
   *  RelationalOperator: '<S20>/Relational Operator6'
   */
  if (VAR_Scf_DchaCntAdd_u8 >= CAL_Scf_ThreRuntoDischaFail_u8) {
    VAR_Scf_DisChaUdcAfterDebounce_f32 =
      SWC_SCF_B.TmpSignalConversionAtRP_SWC_HSP;
  } else {
    VAR_Scf_DisChaUdcAfterDebounce_f32 = 0.0F;
  }

  /* End of Switch: '<S19>/Switch2' */

  /* RelationalOperator: '<S19>/Relational Operator5' incorporates:
   *  Abs: '<S19>/Abs'
   *  Constant: '<S19>/CAL_SmgSys_UdcLnkAbsDiffLim_f32'
   *  Sum: '<S19>/Add'
   */
  VAR_Scf_uDcLnkDiffUnLo_b = (fabsf(VAR_Scf_DischaBeginUdc_f32 -
    VAR_Scf_DisChaUdcAfterDebounce_f32) <= CAL_Scf_UdcLnkAbsDiffLim_f32);

  /* Logic: '<S19>/Logical Operator1' */
  rtb_TmpSignalConversionAtRP_S_o = (rtb_TmpSignalConversionAtRP_S_o &&
    VAR_Scf_uDcLnkDiffUnLo_b);

  /* DataTypeConversion: '<S19>/Data Type Conversion' */
  VAR_Scf_DEMRunToDisChaFail_u8 = rtb_TmpSignalConversionAtRP_S_o;

  /* FunctionCaller: '<S1>/RP_SWC_DEM_SCF_RunToDisChaFail_SetEventStatus' incorporates:
   *  Constant: '<S19>/Constant'
   *  Sum: '<S19>/Add1'
   */
  Rte_Call_RP_SWC_DEM_SCF_RunToDisChaFail_SetEventStatus((uint8)
    (VAR_Scf_DEMRunToDisChaFail_u8 + 2U));

  /* FunctionCaller: '<S1>/RP_SWC_FIM_FiM_FlagforFR_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_FiM_FlagforFR_GetFunctionPermission(&VAR_Scf_flgFimforFR_b);

  /* Logic: '<S66>/Logical Operator1' */
  rtb_TmpSignalConversionAtRP__kb = !VAR_Scf_flgFimforFR_b;

  /* RelationalOperator: '<S66>/Operator2' incorporates:
   *  Constant: '<S66>/iEDS_Enum_stDrvCtl_def.Drv_Failure'
   */
  rtb_TmpSignalConversionAtRP_S_i = (SWC_SCF_B.SCF_stDrvCtl_en == Drv_Failure);

  /* Switch: '<S66>/Switch2' incorporates:
   *  Constant: '<S66>/Constant'
   *  Constant: '<S66>/PRV_PWMrun'
   *  Logic: '<S66>/Logical Operator'
   *  RelationalOperator: '<S66>/Operator1'
   *  UnitDelay: '<S3>/Unit Delay2'
   *  UnitDelay: '<S66>/Unit Delay'
   */
  if ((SWC_SCF_DW.UnitDelay2_DSTATE == ((uint8)PRV_PWMrun)) &&
      rtb_TmpSignalConversionAtRP__kb && rtb_TmpSignalConversionAtRP_S_i) {
    SWC_SCF_DW.UnitDelay_DSTATE_n = 1U;
  }

  /* End of Switch: '<S66>/Switch2' */

  /* Switch: '<S66>/Switch' incorporates:
   *  Logic: '<S66>/Logical Operator2'
   *  Switch: '<S66>/Switch1'
   *  UnitDelay: '<S66>/Unit Delay'
   */
  if (SWC_SCF_DW.UnitDelay_DSTATE_n != 0) {
    /* Outport: '<Root>/PP_SWC_SCF_SCF_stFFAction' incorporates:
     *  Constant: '<S66>/CAL_Scf_FFActionArea2_u8'
     */
    (void) Rte_Write_PP_SWC_SCF_SCF_stFFAction(CAL_Scf_FFActionArea2_u8);
  } else if (rtb_TmpSignalConversionAtRP_S_i && rtb_TmpSignalConversionAtRP__kb &&
             SWC_SCF_DW.Delay_DSTATE) {
    /* Outport: '<Root>/PP_SWC_SCF_SCF_stFFAction' incorporates:
     *  Constant: '<S66>/CAL_Scf_FFActionArea3_u8'
     *  Switch: '<S66>/Switch1'
     */
    (void) Rte_Write_PP_SWC_SCF_SCF_stFFAction(CAL_Scf_FFActionArea3_u8);
  } else {
    /* Outport: '<Root>/PP_SWC_SCF_SCF_stFFAction' incorporates:
     *  Constant: '<S66>/CAL_Scf_FFActionDisab_u8'
     *  Switch: '<S66>/Switch1'
     */
    (void) Rte_Write_PP_SWC_SCF_SCF_stFFAction(CAL_Scf_FFActionDisab_u8);
  }

  /* End of Switch: '<S66>/Switch' */

  /* Switch: '<S65>/Switch2' incorporates:
   *  Constant: '<S65>/PRV_ASCDWN'
   *  Constant: '<S65>/PRV_ASCUP'
   *  Constant: '<S65>/PRV_PWMrun'
   *  RelationalOperator: '<S65>/Relational Operator'
   *  RelationalOperator: '<S65>/Relational Operator1'
   *  RelationalOperator: '<S65>/Relational Operator2'
   *  Switch: '<S65>/Switch1'
   *  Switch: '<S65>/Switch3'
   */
  if (SWC_SCF_B.SCF_stGateDrv == ((uint8)PRV_PWMrun)) {
    /* Outport: '<Root>/PP_SWC_SCF_SCF_stPwmMode' incorporates:
     *  Constant: '<S65>/PRV_MODE_NORMAL'
     */
    (void) Rte_Write_PP_SWC_SCF_SCF_stPwmMode(((uint8)PRV_MODE_NORMAL));
  } else if (SWC_SCF_B.SCF_stGateDrv == ((uint8)PRV_ASCDWN)) {
    /* Outport: '<Root>/PP_SWC_SCF_SCF_stPwmMode' incorporates:
     *  Constant: '<S65>/PRV_MODE_UP_OFF_DOWN_ON'
     *  Switch: '<S65>/Switch3'
     */
    (void) Rte_Write_PP_SWC_SCF_SCF_stPwmMode(((uint8)PRV_MODE_UP_OFF_DOWN_ON));
  } else if (SWC_SCF_B.SCF_stGateDrv == ((uint8)PRV_ASCUP)) {
    /* Outport: '<Root>/PP_SWC_SCF_SCF_stPwmMode' incorporates:
     *  Constant: '<S65>/PRV_MODE_UP_ON_DOWN_OFF'
     *  Switch: '<S65>/Switch1'
     *  Switch: '<S65>/Switch3'
     */
    (void) Rte_Write_PP_SWC_SCF_SCF_stPwmMode(((uint8)PRV_MODE_UP_ON_DOWN_OFF));
  } else {
    /* Outport: '<Root>/PP_SWC_SCF_SCF_stPwmMode' incorporates:
     *  Constant: '<S65>/PRV_MODE_UP_OFF_DOWN_OFF'
     *  Switch: '<S65>/Switch1'
     *  Switch: '<S65>/Switch3'
     */
    (void) Rte_Write_PP_SWC_SCF_SCF_stPwmMode(((uint8)PRV_MODE_UP_OFF_DOWN_OFF));
  }

  /* End of Switch: '<S65>/Switch2' */

  /* RelationalOperator: '<S67>/Operator1' incorporates:
   *  Constant: '<S67>/PRV_PWMrun'
   */
  rtb_TmpSignalConversionAtRP_S_o = (SWC_SCF_B.SCF_stGateDrv == ((uint8)
    PRV_PWMrun));

  /* Outport: '<Root>/PP_SWC_SCF_SCF_flginitPI' incorporates:
   *  Logic: '<S67>/Operator'
   */
  (void) Rte_Write_PP_SWC_SCF_SCF_flginitPI(!rtb_TmpSignalConversionAtRP_S_o);

  /* Outport: '<Root>/PP_SWC_SCF_SCF_flgEnDchaToMc' incorporates:
   *  Constant: '<S67>/Constant'
   *  Logic: '<S67>/Operator8'
   *  RelationalOperator: '<S67>/Relational Operator'
   */
  (void) Rte_Write_PP_SWC_SCF_SCF_flgEnDchaToMc(rtb_TmpSignalConversionAtRP_S_o &&
    (SWC_SCF_B.SCF_stDrvCtl_en == Drv_Discharge));

  /* Switch: '<S68>/Switch' incorporates:
   *  Constant: '<S68>/Constant'
   *  Constant: '<S68>/Constant1'
   *  Constant: '<S68>/Constant2'
   *  Constant: '<S68>/Constant3'
   *  Logic: '<S68>/Logical Operator'
   *  Logic: '<S68>/Logical Operator1'
   *  RelationalOperator: '<S68>/Relational Operator'
   *  RelationalOperator: '<S68>/Relational Operator1'
   *  RelationalOperator: '<S68>/Relational Operator2'
   *  RelationalOperator: '<S68>/Relational Operator3'
   *  Switch: '<S68>/Switch1'
   */
  if ((SWC_SCF_B.SCF_stDrvCtl_en == Drv_TrqCtl) || (SWC_SCF_B.SCF_stDrvCtl_en ==
       Drv_OffsetAcc)) {
    /* Outport: '<Root>/PP_SWC_SCF_SCF_stModeReqToTdc' incorporates:
     *  Constant: '<S68>/PRV_SmgSysTrqCtl'
     */
    (void) Rte_Write_PP_SWC_SCF_SCF_stModeReqToTdc(((uint8)PRV_ScfTrqCtl));
  } else if ((SWC_SCF_B.SCF_stDrvCtl_en == Drv_nCtlExt) ||
             (SWC_SCF_B.SCF_stDrvCtl_en == Drv_nCtlInt)) {
    /* Outport: '<Root>/PP_SWC_SCF_SCF_stModeReqToTdc' incorporates:
     *  Constant: '<S68>/PRV_SmgSysSpdCtl'
     *  Switch: '<S68>/Switch1'
     */
    (void) Rte_Write_PP_SWC_SCF_SCF_stModeReqToTdc(((uint8)PRV_ScfSpdCtl));
  } else {
    /* Outport: '<Root>/PP_SWC_SCF_SCF_stModeReqToTdc' incorporates:
     *  Constant: '<S68>/PRV_SmgSysStopCtl'
     *  Switch: '<S68>/Switch1'
     */
    (void) Rte_Write_PP_SWC_SCF_SCF_stModeReqToTdc(((uint8)PRV_ScfStopCtl));
  }

  /* End of Switch: '<S68>/Switch' */

  /* Outport: '<Root>/PP_SWC_SCF_SCF_flgUdcLowToTpc' incorporates:
   *  Constant: '<S70>/Constant'
   *  Constant: '<S70>/Constant1'
   *  Constant: '<S70>/Constant2'
   *  Constant: '<S70>/Constant3'
   *  Constant: '<S70>/Constant4'
   *  Constant: '<S70>/Constant5'
   *  Constant: '<S70>/Constant6'
   *  Logic: '<S70>/Logical Operator'
   *  RelationalOperator: '<S70>/Relational Operator'
   *  RelationalOperator: '<S70>/Relational Operator1'
   *  RelationalOperator: '<S70>/Relational Operator2'
   *  RelationalOperator: '<S70>/Relational Operator3'
   *  RelationalOperator: '<S70>/Relational Operator4'
   *  RelationalOperator: '<S70>/Relational Operator5'
   *  RelationalOperator: '<S70>/Relational Operator6'
   */
  (void) Rte_Write_PP_SWC_SCF_SCF_flgUdcLowToTpc((SWC_SCF_B.SCF_stDrvCtl_en ==
    Drv_TrqCtl) || (SWC_SCF_B.SCF_stDrvCtl_en == Drv_OffsetAcc) ||
    (SWC_SCF_B.SCF_stDrvCtl_en == Drv_nCtlExt) || (SWC_SCF_B.SCF_stDrvCtl_en ==
    Drv_nCtlInt) || (SWC_SCF_B.SCF_stDrvCtl_en == Drv_IsCtl) ||
    (SWC_SCF_B.SCF_stDrvCtl_en == Drv_UdcCtl) || (SWC_SCF_B.SCF_stDrvCtl_en ==
    Drv_UdcBatCtl));

  /* Outport: '<Root>/PP_SWC_SCF_SCF_flgEmgReqInvDcha' incorporates:
   *  Logic: '<S4>/Logical Operator'
   */
  (void) Rte_Write_PP_SWC_SCF_SCF_flgEmgReqInvDcha(VAR_Scf_flgEmgReqInvDcha_b);

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  SWC_SCF_DW.UnitDelay_DSTATE = SWC_SCF_B.SCF_stSysCtl_en;

  /* Update for UnitDelay: '<S3>/Unit Delay1' */
  SWC_SCF_DW.UnitDelay1_DSTATE_e = SWC_SCF_B.SCF_stDisChg;

  /* Update for UnitDelay: '<S3>/Unit Delay4' */
  SWC_SCF_DW.UnitDelay4_DSTATE = SWC_SCF_B.SCF_stDrvCtl_en;

  /* Update for UnitDelay: '<S3>/Unit Delay2' */
  SWC_SCF_DW.UnitDelay2_DSTATE = SWC_SCF_B.SCF_stGateDrv;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_SCF_10ms' */

  /* Outport: '<Root>/PP_SWC_SCF_SCF_flgDataStrgBgnToBsw' */
  (void) Rte_Write_PP_SWC_SCF_SCF_flgDataStrgBgnToBsw(rtb_LogicalOperator2_l);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_SCF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_SCF_10ms_sys'
   */
  /* Outport: '<Root>/PP_SWC_SCF_SCF_stSysCtl' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  (void) Rte_Write_PP_SWC_SCF_SCF_stSysCtl((uint8)SWC_SCF_B.SCF_stSysCtl_en);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_SCF_10ms' */

  /* Outport: '<Root>/PP_SWC_SCF_SCF_stGateDrv' */
  (void) Rte_Write_PP_SWC_SCF_SCF_stGateDrv(SWC_SCF_B.SCF_stGateDrv);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_SCF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_SCF_10ms_sys'
   */
  /* Outport: '<Root>/PP_SWC_SCF_SCF_stDrvCtl' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   */
  (void) Rte_Write_PP_SWC_SCF_SCF_stDrvCtl((uint8)SWC_SCF_B.SCF_stDrvCtl_en);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_SCF_10ms' */

  /* Outport: '<Root>/PP_SWC_SCF_SCF_stDisChg' */
  (void) Rte_Write_PP_SWC_SCF_SCF_stDisChg(SWC_SCF_B.SCF_stDisChg);

  /* Outport: '<Root>/PP_SWC_SCF_SCF_stPreDrvCtl' */
  (void) Rte_Write_PP_SWC_SCF_SCF_stPreDrvCtl(SWC_SCF_B.SCF_stPreDrvCtl);

  /* Outport: '<Root>/PP_SWC_SCF_SCF_bHvReady' */
  (void) Rte_Write_PP_SWC_SCF_SCF_bHvReady(SWC_SCF_DW.Delay_DSTATE);

  /* Outport: '<Root>/PP_SWC_SCF_SCF_flgActvDcha' */
  (void) Rte_Write_PP_SWC_SCF_SCF_flgActvDcha(SWC_SCF_B.SCF_flgActvDcha);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_SCF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_SCF_10ms_sys'
   */
  /* Outport: '<Root>/PP_SWC_SCF_SCF_FIM_ReqFailrMod' incorporates:
   *  Constant: '<S69>/Constant'
   *  RelationalOperator: '<S69>/Relational Operator'
   */
  (void) Rte_Write_PP_SWC_SCF_SCF_FIM_ReqFailrMod(SWC_SCF_B.SCF_stDrvCtl_en ==
    Drv_Failure);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_SCF_10ms' */
}

/* Model initialize function */
void SWC_SCF_Init(void)
{
  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_SCF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_SCF_10ms_sys'
   */
  /* SystemInitialize for Chart: '<S3>/SCF_stSysDrvCtl_Switch' */
  SWC_SCF_B.SCF_stSysCtl_en = PreDriveMod;
  SWC_SCF_B.SCF_stDrvCtl_en = Drv_Initial;

  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_SCF_10ms' */

  /* SystemInitialize for Outport: '<Root>/PP_SWC_SCF_SCF_stGateDrv' */
  (void) Rte_Write_PP_SWC_SCF_SCF_stGateDrv(SWC_SCF_B.SCF_stGateDrv);

  /* SystemInitialize for Outport: '<Root>/PP_SWC_SCF_SCF_stDisChg' */
  (void) Rte_Write_PP_SWC_SCF_SCF_stDisChg(SWC_SCF_B.SCF_stDisChg);

  /* SystemInitialize for Outport: '<Root>/PP_SWC_SCF_SCF_stPreDrvCtl' */
  (void) Rte_Write_PP_SWC_SCF_SCF_stPreDrvCtl(SWC_SCF_B.SCF_stPreDrvCtl);

  /* SystemInitialize for Outport: '<Root>/PP_SWC_SCF_SCF_flgActvDcha' */
  (void) Rte_Write_PP_SWC_SCF_SCF_flgActvDcha(SWC_SCF_B.SCF_flgActvDcha);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
