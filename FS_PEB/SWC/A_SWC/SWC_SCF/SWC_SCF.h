/*
 * File: SWC_SCF.h
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

#ifndef RTW_HEADER_SWC_SCF_h_
#define RTW_HEADER_SWC_SCF_h_
#include <math.h>
#ifndef SWC_SCF_COMMON_INCLUDES_
# define SWC_SCF_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_SWC_SCF.h"
#endif                                 /* SWC_SCF_COMMON_INCLUDES_ */

#include "SWC_SCF_types.h"

/* Child system includes */
#include "SWC_SCF_EI09_EmDisChaFunction.h"

/* Macros for accessing real-time model data structure */

/* Exported data define */

/* Definition for custom storage class: Define */
#define PRV_ASCDWN                     2U                        /* Referenced by:
                                                                  * '<S3>/SCF_stSysDrvCtl_Switch'
                                                                  * '<S65>/PRV_ASCDWN'
                                                                  */

/* IGBT开关短路 */
#define PRV_ASCUP                      1U                        /* Referenced by: '<S65>/PRV_ASCUP' */
#define PRV_DisChgEnd                  2U                        /* Referenced by:
                                                                  * '<S3>/SCF_stSysDrvCtl_Switch'
                                                                  * '<S24>/PRV_DisChgEnd'
                                                                  * '<S53>/PRV_DisChgEnd'
                                                                  * '<S56>/PRV_DisChgEnd'
                                                                  * '<S60>/PRV_DisChgEnd2'
                                                                  */

/* 主动放电结束状态 */
#define PRV_DisChgFail                 3U                        /* Referenced by:
                                                                  * '<S3>/SCF_stSysDrvCtl_Switch'
                                                                  * '<S56>/PRV_DisChgEnd1'
                                                                  * '<S60>/PRV_DisChgEnd3'
                                                                  */

/* 主动放电超时状态 */
#define PRV_DisChgInAct                0U                        /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */

/* 主动放电未激活状态 */
#define PRV_DisChgReq                  4U                        /* Referenced by: '<S16>/PRV_DisChgReq' */

/* VCU主动放电控制模式请求 */
#define PRV_DisChgStart                1U                        /* Referenced by:
                                                                  * '<S3>/SCF_stSysDrvCtl_Switch'
                                                                  * '<S19>/Constant1'
                                                                  */

/* 主动放电开始状态 */
#define PRV_EstOfsFinish               1U                        /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */
#define PRV_EstOfsPreFinish            3U                        /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */
#define PRV_IGBTClose                  0U                        /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */

/* IGBT开关断开 */
#define PRV_MODE_NORMAL                3U                        /* Referenced by: '<S65>/PRV_MODE_NORMAL' */
#define PRV_MODE_UP_OFF_DOWN_OFF       0U                        /* Referenced by: '<S65>/PRV_MODE_UP_OFF_DOWN_OFF' */
#define PRV_MODE_UP_OFF_DOWN_ON        1U                        /* Referenced by: '<S65>/PRV_MODE_UP_OFF_DOWN_ON' */
#define PRV_MODE_UP_ON_DOWN_OFF        2U                        /* Referenced by: '<S65>/PRV_MODE_UP_ON_DOWN_OFF' */
#define PRV_OfsCalACC                  2U                        /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */

/* 初始角电机加速标定 */
#define PRV_OfsCalFW                   1U                        /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */

/* 初始角FreeWheel模式标定 */
#define PRV_OfsCalReq                  5U                        /* Referenced by:
                                                                  * '<S3>/SCF_stSysDrvCtl_Switch'
                                                                  * '<S27>/PRV_OfsCalReq'
                                                                  * '<S31>/PRV_OfsCalReq'
                                                                  */

/* VCU请求旋变初始角标定 */
#define PRV_OfsClbSud                  4U                        /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */
#define PRV_PWMrun                     3U                        /* Referenced by:
                                                                  * '<S3>/SCF_stSysDrvCtl_Switch'
                                                                  * '<S65>/PRV_PWMrun'
                                                                  * '<S66>/PRV_PWMrun'
                                                                  * '<S67>/PRV_PWMrun'
                                                                  */

/* IGBT正常导通 */
#define PRV_PreDrv_Fishd               5U                        /* Referenced by:
                                                                  * '<S3>/SCF_stSysDrvCtl_Switch'
                                                                  * '<S64>/PRV_PreDrv_Fishd'
                                                                  */
#define PRV_PreDrv_LowPwrSetUp         1U                        /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */
#define PRV_PreDrv_SensCal             3U                        /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */
#define PRV_PreDrv_ShelfCheck          2U                        /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */
#define PRV_PreDrv_iMMO                4U                        /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */
#define PRV_PreDrv_iNiT                0U                        /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */
#define PRV_ScfSpdCtl                  2U                        /* Referenced by: '<S68>/PRV_SmgSysSpdCtl' */
#define PRV_ScfStopCtl                 0U                        /* Referenced by: '<S68>/PRV_SmgSysStopCtl' */
#define PRV_ScfTrqCtl                  1U                        /* Referenced by: '<S68>/PRV_SmgSysTrqCtl' */
#define PRV_ShutDownReq                7U                        /* Referenced by:
                                                                  * '<S46>/PRV_ShutDownReq'
                                                                  * '<S47>/PRV_ShutDownReq'
                                                                  * '<S55>/PRV_ShutDownReq'
                                                                  * '<S59>/PRV_ShutDownReq'
                                                                  */

/* VCU下电请求控制模式 */
#define PRV_TrqCtlReq                  2U                        /* Referenced by:
                                                                  * '<S3>/SCF_stSysDrvCtl_Switch'
                                                                  * '<S28>/PRV_UdcCtlReq5'
                                                                  * '<S32>/PRV_TrqCtlReq'
                                                                  */

/* VCU力矩环控制模式请求 */
#define PRV_UdcCtlBatReq               11U                       /* Referenced by:
                                                                  * '<S3>/SCF_stSysDrvCtl_Switch'
                                                                  * '<S28>/PRV_UdcCtlReq3'
                                                                  * '<S32>/PRV_UdcCtlBatReq'
                                                                  */

/* 有高压电池的电压控制请求 */
#define PRV_UdcCtlReq                  8U                        /* Referenced by:
                                                                  * '<S3>/SCF_stSysDrvCtl_Switch'
                                                                  * '<S28>/PRV_UdcCtlReq'
                                                                  * '<S32>/PRV_UdcCtlReq'
                                                                  */

/* 无高压电池电压控制模式 */
#define PRV_isCtlReq                   10U                       /* Referenced by:
                                                                  * '<S3>/SCF_stSysDrvCtl_Switch'
                                                                  * '<S28>/PRV_UdcCtlReq2'
                                                                  * '<S32>/PRV_isCtlReq'
                                                                  */

/* 电流环控制模式请求 */
#define PRV_nCtLintReq                 9U                        /* Referenced by:
                                                                  * '<S3>/SCF_stSysDrvCtl_Switch'
                                                                  * '<S28>/PRV_UdcCtlReq1'
                                                                  * '<S32>/PRV_nCtLintReq'
                                                                  */

/* VCU转速内环控制模式请求 */
#define PRV_nCtlExtReq                 1U                        /* Referenced by:
                                                                  * '<S3>/SCF_stSysDrvCtl_Switch'
                                                                  * '<S28>/PRV_UdcCtlReq4'
                                                                  * '<S32>/PRV_nCtlExtReq'
                                                                  */

/* VCU转速外环控制模式请求 */

/* Block signals (default storage) */
typedef struct tag_B_SWC_SCF_T {
  float32 TmpSignalConversionAtRP_SWC_HSP;
  iEDS_Enum_stSysCtl_def SCF_stSysCtl_en;/* '<S3>/SCF_stSysDrvCtl_Switch' */
  iEDS_Enum_stDrvCtl_def SCF_stDrvCtl_en;/* '<S3>/SCF_stSysDrvCtl_Switch' */
  uint8 TmpSignalConversionAtRP_SWC_VCF;
  uint8 SCF_stGateDrv;                 /* '<S3>/SCF_stSysDrvCtl_Switch' */
  uint8 SCF_stDisChg;                  /* '<S3>/SCF_stSysDrvCtl_Switch' */
  uint8 SCF_stPreDrvCtl;               /* '<S3>/SCF_stSysDrvCtl_Switch' */
  boolean SCF_flgActvDcha;             /* '<S3>/SCF_stSysDrvCtl_Switch' */
} B_SWC_SCF_T;

/* Block states (default storage) for system '<Root>' */
typedef struct tag_DW_SWC_SCF_T {
  iEDS_Enum_stSysCtl_def UnitDelay_DSTATE;/* '<S3>/Unit Delay' */
  iEDS_Enum_stDrvCtl_def UnitDelay4_DSTATE;/* '<S3>/Unit Delay4' */
  uint16 UnitDelay1_DSTATE_l;          /* '<S58>/Unit Delay1' */
  uint16 UnitDelay1_DSTATE_g;          /* '<S18>/Unit Delay1' */
  uint16 UnitDelay1_DSTATE_b;          /* '<S17>/Unit Delay1' */
  uint16 UnitDelay1_DSTATE_k;          /* '<S62>/Unit Delay1' */
  uint16 UnitDelay_DSTATE_g;           /* '<S48>/Unit Delay' */
  uint16 UnitDelay_DSTATE_p;           /* '<S51>/Unit Delay' */
  uint16 i;                            /* '<S3>/SCF_stSysDrvCtl_Switch' */
  uint8 UnitDelay1_DSTATE_e;           /* '<S3>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE;             /* '<S3>/Unit Delay2' */
  uint8 UnitDelay_DSTATE_n;            /* '<S66>/Unit Delay' */
  boolean UnitDelay2_DSTATE_l;         /* '<S58>/Unit Delay2' */
  boolean UnitDelay2_DSTATE_p;         /* '<S62>/Unit Delay2' */
  boolean UnitDelay_DSTATE_h;          /* '<S59>/Unit Delay' */
  boolean UnitDelay1_DSTATE_o;         /* '<S48>/Unit Delay1' */
  boolean UnitDelay_DSTATE_c;          /* '<S50>/Unit Delay' */
  boolean Delay_DSTATE;                /* '<S23>/Delay' */
  uint8 is_active_c187_SWC_SCF;        /* '<S3>/SCF_stSysDrvCtl_Switch' */
  uint8 is_c187_SWC_SCF;               /* '<S3>/SCF_stSysDrvCtl_Switch' */
  uint8 is_PreDrive;                   /* '<S3>/SCF_stSysDrvCtl_Switch' */
  uint8 is_PreDriveRun;                /* '<S3>/SCF_stSysDrvCtl_Switch' */
  uint8 is_Drive;                      /* '<S3>/SCF_stSysDrvCtl_Switch' */
  uint8 is_Normal;                     /* '<S3>/SCF_stSysDrvCtl_Switch' */
  uint8 is_OfstCal;                    /* '<S3>/SCF_stSysDrvCtl_Switch' */
  uint8 is_EparkCal;                   /* '<S3>/SCF_stSysDrvCtl_Switch' */
  uint8 is_Discharge;                  /* '<S3>/SCF_stSysDrvCtl_Switch' */
  uint8 is_Discha_HW;                  /* '<S3>/SCF_stSysDrvCtl_Switch' */
  boolean SCF_flgDrvCycle;             /* '<S3>/SCF_stSysDrvCtl_Switch' */
  boolean flgCtrlRun;                  /* '<S3>/SCF_stSysDrvCtl_Switch' */
  boolean SCF_flgFaultToDcha;          /* '<S3>/SCF_stSysDrvCtl_Switch' */
  DW_EI09_EmDisChaFunction_SWC__T EI09_EmDisChaFunction;/* '<S14>/EI09_EmDisChaFunction' */
} DW_SWC_SCF_T;

/* Invariant block signals (default storage) */
typedef struct {
  ConstB_EI09_EmDisChaFunction__T EI09_EmDisChaFunction;/* '<S14>/EI09_EmDisChaFunction' */
} ConstB_SWC_SCF_T;

/* Block signals (default storage) */
extern B_SWC_SCF_T SWC_SCF_B;

/* Block states (default storage) */
extern DW_SWC_SCF_T SWC_SCF_DW;
extern const ConstB_SWC_SCF_T SWC_SCF_ConstB;/* constant block i/o */

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern float32 VAR_Scf_DischaBeginUdc_f32;/* '<S19>/Switch' */
extern float32 VAR_Scf_DisChaUdcAfterDebounce_f32;/* '<S19>/Switch2' */
extern uint8 VAR_Scf_flgShutDwnOvtimErr_u8;/* '<S48>/Switch3'
                                            * 数据存储超时失败下电超时故障标志
                                            */
extern uint8 VAR_Scf_DchaCntAdd_u8;    /* '<S20>/Add2' */
extern uint8 VAR_Scf_DEMRunToDisChaFail_u8;/* '<S19>/Data Type Conversion' */
extern boolean VAR_Scf_flgTranPreDrvToDrv_b;/* '<S46>/Switch'
                                             * PreDrive模式跳转Drv模式使能
                                             */
extern boolean VAR_Scf_flgFimVCUComErr_b;
                     /* '<S1>/RP_SWC_FIM_VCUComTimeOut_GetFunctionPermission' */
extern boolean VAR_Scf_flgShtDwnByMcu_b;/* '<S56>/Logical Operator4' */
extern boolean VAR_Scf_VCUComErr_b;    /* '<S11>/Switch2'
                                        * 最终使用的VCU通讯故障标志
                                        */
extern boolean VAR_Scf_flgShtDwnByVcu_b;/* '<S55>/Switch5' */
extern boolean VAR_Scf_flgPostDrvReqWiDcha_b;/* '<S55>/Switch1'
                                              * 有主动放电时Drv进入PostDrv使能
                                              */
extern boolean VAR_Scf_flgPostDrvReqWoDcha_b;/* '<S57>/Logical Operator5'
                                              * 无主动放电时Drv进入PostDrv使能
                                              */
extern boolean VAR_Scf_flgTranDrvToPostDrv_b;/* '<S55>/Switch'
                                              * Drv模式跳转PostDrv模式使能
                                              */
extern boolean VAR_Scf_flgTranPreDrvToPostDrv_b;/* '<S47>/Logical Operator3'
                                                 * PreDrv模式跳转PostDrv模式使能
                                                 */
extern boolean VAR_Scf_flgFimFaultLvFour_b;
                    /* '<S1>/RP_SWC_FIM_flgFaultLvFour_GetFunctionPermission' */
extern boolean VAR_Scf_flgFimFaultLvFive_b;
                    /* '<S1>/RP_SWC_FIM_flgFaultLvFive_GetFunctionPermission' */
extern boolean VAR_Scf_flgTranPostDrvToPreDrv_b;/* '<S63>/Logical Operator2'
                                                 * PostDrv模式跳转PreDrv模式使能
                                                 */
extern boolean VAR_Scf_flgFimReqFailr_b;
                       /* '<S1>/RP_SWC_FIM_ReqFailrMod_GetFunctionPermission' */
extern boolean VAR_Scf_flgTranPreDrvToFault_b;/* '<S64>/Logical Operator1'
                                               * PreDrv模式跳转Fault模式使能
                                               */
extern boolean VAR_Scf_flgFimDchaFailr_b;
                      /* '<S1>/RP_SWC_FIM_flgDchaFailr_GetFunctionPermission' */
extern boolean VAR_Scf_flgEmgReqInvDcha_b;/* '<S13>/Switch' */
extern boolean VAR_Scf_flgTranDrvToFault_b;/* '<S53>/Logical Operator3'
                                            * Drv模式跳转Fault模式使能
                                            */
extern boolean VAR_Scf_flgDchaVcuReq_b;/* '<S16>/Logical Operator2' */
extern boolean VAR_Scf_nDchaAllw_b;    /* '<S15>/Relational Operator' */
extern boolean VAR_Scf_cntSigFit_b;    /* '<S18>/Relational Operator3' */
extern boolean VAR_Scf_flgVCUComErrDelay_b;/* '<S17>/Relational Operator' */
extern boolean VAR_Scf_DisChaDetec_b;  /* '<S13>/Switch1' */
extern boolean VAR_Scf_flgReqInvDcha_b;/* '<S13>/Switch2' */
extern boolean VAR_Scf_flgTranFaultToDcha_b;/* '<S54>/Logical Operator2'
                                             * Fault模式跳转Dcha模式使能
                                             */
extern boolean VAR_Scf_flgTranFaultToPostDrv_b;/* '<S59>/Switch'
                                                * Fault模式跳转PostDrv模式使能
                                                */
extern boolean VAR_Scf_flgInitOut_b;   /* '<S50>/Logical Operator' */
extern boolean VAR_Scf_flgWakeNormal_b;/* '<S44>/Logical Operator1' */
extern boolean VAR_Scf_flgNoWakeSou_b; /* '<S51>/Relational Operator1' */
extern boolean VAR_Scf_flgWakeLoss_b;  /* '<S44>/Logical Operator5' */
extern boolean VAR_Scf_flgPostDrvDone_b;/* '<S44>/Logical Operator3' */
extern boolean VAR_Scf_flgTranPostDrvToSutDwn_b;/* '<S45>/Logical Operator'
                                                 * PostDrv模式跳转ShutDown模式使能
                                                 */
extern boolean VAR_Scf_flgTranLoPowSetToDia_b;/* '<S34>/Logical Operator' */
extern boolean VAR_Scf_flgTranDiagToSenCal_b;/* '<S33>/Logical Operator' */
extern boolean VAR_Scf_flgTranSenCalToiMMO_b;/* '<S36>/Relational Operator' */
extern boolean VAR_Scf_flgTranPreDrvRunToFish_b;/* '<S35>/Relational Operator' */
extern boolean VAR_Scf_flgTranIdleToStb_b;/* '<S25>/Logical Operator'
                                           * Idle状态跳转Standby状态使能
                                           */
extern boolean VAR_Scf_flgTranStbToIdle_b;/* '<S30>/Relational Operator'
                                           * Standby状态跳转Idle状态使能
                                           */
extern boolean VAR_Scf_flgTranStbToRun_b;/* '<S32>/Logical Operator'
                                          * Standby状态跳转Run状态使能
                                          */
extern boolean VAR_Scf_flgTranRunToStb_b;/* '<S28>/Switch'
                                          * Run状态跳转Standby状态使能
                                          */
extern boolean VAR_Scf_flgTranStbToOfstCal_b;/* '<S31>/Relational Operator'
                                              * Standby状态跳转OfstCal状态使能
                                              */
extern boolean VAR_Scf_flgTranOfstCalToStb_b;/* '<S27>/Relational Operator'
                                              * OfstCal状态跳转Standby状态使能
                                              */
extern boolean VAR_Scf_flgTranNormalToDcha_b;/* '<S26>/Logical Operator'
                                              * Normal状态跳转Dischage状态使能
                                              */
extern boolean VAR_Scf_flgTranDchaToNormal_b;/* '<S24>/Logical Operator2'
                                              * Dischage状态跳转Normal状态使能
                                              */
extern boolean VAR_Scf_flgTranStbToSLCal_b;/* '<S29>/Logical Operator' */
extern boolean VAR_Scf_flgTranSLCalToStb_b;/* '<S29>/Logical Operator1' */
extern boolean VAR_Scf_flgTranSLInitToSLAcc_b;/* '<S29>/Logical Operator2' */
extern boolean VAR_Scf_flgTranSLInitToSLFw_b;/* '<S29>/Logical Operator3' */
extern boolean VAR_Scf_uDcLnkDiffUnLo_b;/* '<S19>/Relational Operator5' */
extern boolean VAR_Scf_flgFimforFR_b;
                     /* '<S1>/RP_SWC_FIM_FiM_FlagforFR_GetFunctionPermission' */
extern boolean Var_Scf_flgDisChgFail_b;/* '<S3>/SCF_stSysDrvCtl_Switch' */
extern boolean VAR_Scf_flgbt15first_b; /* '<S49>/HSPF_bt15' */

/* Exported data declaration */
#pragma section ".rodata.Calib_32"

/* Declaration for custom storage class: iEDS_Parameter */
extern const volatile boolean CAL_SCF_flgUseSLCal_b;
                              /* Referenced by: '<S29>/CAL_SCF_flgUseSLCal_b' */
extern const volatile boolean CAL_Scf_EmgDchabysiglordoubSwt_b;
                /* Referenced by: '<S21>/CAL_Smgsys_EmgDchabysiglordoubSwt_b' */
extern const volatile uint8 CAL_Scf_FFActionArea2_u8;
                           /* Referenced by: '<S66>/CAL_Scf_FFActionArea2_u8' */
extern const volatile uint8 CAL_Scf_FFActionArea3_u8;
                           /* Referenced by: '<S66>/CAL_Scf_FFActionArea3_u8' */
extern const volatile uint8 CAL_Scf_FFActionDisab_u8;
                           /* Referenced by: '<S66>/CAL_Scf_FFActionDisab_u8' */
extern const volatile float32 CAL_Scf_FLOATZERO_f32;/* Referenced by:
                                                     * '<S33>/CAL_Scf_FLOATZERO_f32'
                                                     * '<S34>/CAL_Scf_FLOATZERO_f32'
                                                     */

/* 浮点零 */
extern const volatile boolean CAL_Scf_IntDchaSwt_b;/* Referenced by:
                                                    * '<S55>/CAL_Scf_IntDchaSwt_b'
                                                    * '<S59>/CAL_Scf_IntDchaSwt_b'
                                                    */
extern const volatile uint8 CAL_Scf_LowPwrSetUpErr_u8;
                          /* Referenced by: '<S64>/CAL_Scf_LowPwrSetUpErr_u8' */
extern const volatile uint8 CAL_Scf_LowPwrSetUpSud_u8;
                          /* Referenced by: '<S34>/CAL_Scf_LowPwrSetUpSud_u8' */
extern const volatile uint8 CAL_Scf_SenChkErr_u8;
                               /* Referenced by: '<S64>/CAL_Scf_SenChkErr_u8' */

/* 传感器标定失败状态 */
extern const volatile uint8 CAL_Scf_SenChkSud_u8;/* Referenced by:
                                                  * '<S35>/CAL_Scf_SenChkSud_u8'
                                                  * '<S36>/CAL_Scf_SenChkSud_u8'
                                                  */

/* 传感器标定成功状态 */
extern const volatile boolean CAL_Scf_ShtDwnReqByVcuSwt_b;/* Referenced by:
                                                           * '<S46>/CAL_Scf_ShtDwnReqByVcuSwt_b'
                                                           * '<S55>/CAL_Scf_ShtDwnReqByVcuSwt_b'
                                                           * '<S59>/CAL_Scf_ShtDwnReqByVcuSwt_b'
                                                           */
extern const volatile uint8 CAL_Scf_StandbyVcuReq_u8;
                           /* Referenced by: '<S63>/CAL_Scf_StandbyVcuReq_u8' */
extern const volatile uint8 CAL_Scf_ThreRuntoDischaFail_u8;
                     /* Referenced by: '<S20>/CAL_Scf_ThreRuntoDischaFail_u8' */
extern const volatile float32 CAL_Scf_UdcLnkAbsDiffLim_f32;
                    /* Referenced by: '<S19>/CAL_SmgSys_UdcLnkAbsDiffLim_f32' */
extern const volatile uint8 CAL_Scf_WithoutStatorCurrent_u8;
                    /* Referenced by: '<S33>/CAL_Scf_WithoutStatorCurrent_u8' */

/* 无定子电流 */
extern const volatile uint8 CAL_Scf_cntDchaSigFit_u8;/* Referenced by:
                                                      * '<S18>/CAL_SmgSys_cntDchaSigFit_u8'
                                                      * '<S22>/CAL_SmgSys_cntDchaSigFit_u8'
                                                      */
extern const volatile uint16 CAL_Scf_cntDisChgEnd_u16;
                              /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */

/* 硬件放电结束时间计数器 */
extern const volatile uint16 CAL_Scf_cntDisChgOvTi_u16;
                              /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */

/* 硬件放电超时计数器 */
extern const volatile uint16 CAL_Scf_cntPostDrvDone_u16;
                      /* Referenced by: '<S48>/CAL_SmgSys_cntPostDrvDone_u16' */

/* PostDrive到PreDrv延时计数 */
extern const volatile uint16 CAL_Scf_cntVCUComErrLim_u16;/* Referenced by:
                                                          * '<S17>/CAL_Scf_cntVCUComErrLim_u16'
                                                          * '<S58>/CAL_Scf_cntVCUComErrLim_u16'
                                                          * '<S62>/CAL_Scf_cntVCUComErrLim_u16'
                                                          */

/* VCU通信超时计数 */
extern const volatile uint16 CAL_Scf_cntWakeLoss_u16;
                         /* Referenced by: '<S51>/CAL_SmgSys_cntWakeLoss_u16' */
extern const volatile float32 CAL_Scf_curSenChgToDrv_f32;
                                     /* Referenced by: '<S10>/uDc_Spd_Is_Swt' */

/* 进入Drive模式的定子电流标定量 */
extern const volatile float32 CAL_Scf_curSenChgToPostDrv_f32;
                                     /* Referenced by: '<S10>/uDc_Spd_Is_Swt' */

/* 跳出Drive模式的定子电流标定量 */
extern const volatile boolean CAL_Scf_flgActvSubNSwt_b;
                        /* Referenced by: '<S43>/CAL_SmgSys_flgActvSubNSwt_b' */

/* Debug模式选择；1表示Dug,0表示非Dug */
extern const volatile boolean CAL_Scf_flgActvSubUSwt_b;
                        /* Referenced by: '<S43>/CAL_SmgSys_flgActvSubUSwt_b' */

/* Debug模式选择；1表示Dug,0表示非Dug */
extern const volatile boolean CAL_Scf_flgActvSubisSwt_b;
                       /* Referenced by: '<S43>/CAL_SmgSys_flgActvSubisSwt_b' */

/* Debug模式选择；1表示Dug,0表示非Dug */
extern const volatile boolean CAL_Scf_flgCanNmSwt_b;
                              /* Referenced by: '<S45>/CAL_Scf_flgCanNmSwt_b' */
extern const volatile boolean CAL_Scf_flgDisChgReqSwt_b;
                          /* Referenced by: '<S13>/CAL_Scf_flgDisChgReqSwt_b' */
extern const volatile boolean CAL_Scf_flgDrvToPostWihDisSwt_b;/* Referenced by:
                                                               * '<S56>/CAL_Scf_flgDrvToPostWihDisSwt_b'
                                                               * '<S60>/CAL_Scf_flgDrvToPostWihDisSwt_b'
                                                               */
extern const volatile boolean CAL_Scf_flgEmgDisChgReqSwt_b;
                       /* Referenced by: '<S13>/CAL_Scf_flgEmgDisChgReqSwt_b' */
extern const volatile boolean CAL_Scf_flgEpcShutdownSwt_b;
                        /* Referenced by: '<S45>/CAL_Scf_flgEpcShutdownSwt_b' */
extern const volatile boolean CAL_Scf_flgIntVcuComErr_b;
                       /* Referenced by: '<S11>/CAL_SmgSys_flgIntVcuComErr_b' */
extern const volatile boolean CAL_Scf_flgIntVcuComSwt_b;
                       /* Referenced by: '<S11>/CAL_SmgSys_flgIntVcuComSwt_b' */
extern const volatile boolean CAL_Scf_flgJumpRunBy15Swt_b;
                        /* Referenced by: '<S28>/CAL_Scf_flgJumpRunBy15Swt_b' */
extern const volatile boolean CAL_Scf_flgOfsClbSwt_b;/* Referenced by: '<S32>/Constant' */
extern const volatile boolean CAL_Scf_flgPcfAllowPwmRunSwt_b;/* Referenced by: '<S32>/Constant2' */
extern const volatile float32 CAL_Scf_iSubSttrisVal_f32;
                       /* Referenced by: '<S43>/CAL_SmgSys_iSubSttrisVal_f32' */

/* 进Drive模式定子电流标定量 */
extern const volatile float32 CAL_Scf_nAllwPwrDcha_f32;/* Referenced by:
                                                        * '<S15>/CAL_SmgSys_nAllwPwrDcha_f32'
                                                        * '<S16>/CAL_Scf_nAllwPwrDcha_f32'
                                                        */
extern const volatile float32 CAL_Scf_nPsmThresToDrv_f32;
                                     /* Referenced by: '<S10>/uDc_Spd_Is_Swt' */

/* 进入Drive模式的转速标定量 */
extern const volatile float32 CAL_Scf_nPsmThresToPostDrv_f32;
                                     /* Referenced by: '<S10>/uDc_Spd_Is_Swt' */

/* 跳出Drive模式进PostDrive的转速标定量 */
extern const volatile float32 CAL_Scf_nRunTostb_f32;
                              /* Referenced by: '<S28>/CAL_Scf_nRunTostb_f32' */

/* 从run退出到Standby的速度阈值 */
extern const volatile float32 CAL_Scf_nSafeLoSpdMaxLim_f32;
                              /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */

/* 最低的安全转速限制进Free自动模式 */
extern const volatile float32 CAL_Scf_nSafeLoSpdMinLim_f32;
                              /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */

/* 最低的安全转速限制进ASC */
extern const volatile float32 CAL_Scf_nSafeMaxLim_f32;
                              /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */

/* 大于该转速进ASC */
extern const volatile float32 CAL_Scf_nSafeMinLim_f32;
                              /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */

/* 小于该转速进Free模式 */
extern const volatile float32 CAL_Scf_nSafeTestMaxLim_f32;
                              /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */

/* TestBanch进开管速度值 */
extern const volatile float32 CAL_Scf_nSafeTestMinLim_f32;
                              /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */

/* TestBanch进关管速度值 */
extern const volatile float32 CAL_Scf_nSnsrClbFw_f32;/* Referenced by:
                                                      * '<S33>/CAL_SmgSys_nSnsrClbFw_f32'
                                                      * '<S34>/CAL_Scf_nSnsrClbFw_f32'
                                                      */

/* 进SensCalFW电机转速标定量 */
extern const volatile float32 CAL_Scf_nSubPsmSpdVal_f32;
                       /* Referenced by: '<S43>/CAL_SmgSys_nSubPsmSpdVal_f32' */

/* 进Drive模式电机转速标定量 */
extern const volatile float32 CAL_Scf_uAllwPwrDcha_f32;/* Referenced by:
                                                        * '<S15>/CAL_SmgSys_uAllwPwrDcha_f32'
                                                        * '<S16>/CAL_SmgSys_uAllwPwrDcha_f32'
                                                        */
extern const volatile float32 CAL_Scf_uDisChgEnd_f32;
                              /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */

/* 主动放电结束电压标定量 */
extern const volatile float32 CAL_Scf_uDisChgOutTim_f32;
                              /* Referenced by: '<S3>/SCF_stSysDrvCtl_Switch' */

/* 放电超时电压判断 */
extern const volatile float32 CAL_Scf_uSafeVolt_f32;
                              /* Referenced by: '<S24>/CAL_Scf_uSafeVolt_f32' */
extern const volatile float32 CAL_Scf_uSubHiVoltVal_f32;
                       /* Referenced by: '<S43>/CAL_SmgSys_uSubHiVoltVal_f32' */

/* 进Drive模式母线电压标定量 */
extern const volatile float32 CAL_Scf_uTnetHysToDrv_f32;
                                     /* Referenced by: '<S10>/uDc_Spd_Is_Swt' */

/* 进入Drive模式的电压标定量 */
extern const volatile float32 CAL_Scf_uTnetHysToPostDrv_f32;
                                     /* Referenced by: '<S10>/uDc_Spd_Is_Swt' */

/* 跳出Drive模式进PostDrive的电压标定量 */
extern const volatile float32 CAL_Scf_udcPrechgFail_f32;
                          /* Referenced by: '<S23>/CAL_Scf_udcPrechgFail_f32' */
extern const volatile float32 CAL_Scf_udcPrechgFish_f32;
                          /* Referenced by: '<S23>/CAL_Scf_udcPrechgFish_f32' */

/* 预充电压门限 */
#pragma section

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
 * '<Root>' : 'SWC_SCF'
 * '<S1>'   : 'SWC_SCF/RE_SWC_SCF_10ms_sys'
 * '<S2>'   : 'SWC_SCF/RE_SWC_SCF_Init'
 * '<S3>'   : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl'
 * '<S4>'   : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms'
 * '<S5>'   : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_stSysDrvCtl_Switch'
 * '<S6>'   : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SigMap'
 * '<S7>'   : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_DchaCtl_10ms'
 * '<S8>'   : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_DrvTrans'
 * '<S9>'   : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_PreDrvTrans'
 * '<S10>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans'
 * '<S11>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_VCUComErrSwt'
 * '<S12>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_DchaCtl_10ms/CmftDchaCtl'
 * '<S13>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_DchaCtl_10ms/DchagFunCoord'
 * '<S14>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_DchaCtl_10ms/EmDchaCtl'
 * '<S15>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_DchaCtl_10ms/CmftDchaCtl/DchaMcuReqWiRelay'
 * '<S16>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_DchaCtl_10ms/CmftDchaCtl/DchaReqByVCU'
 * '<S17>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_DchaCtl_10ms/CmftDchaCtl/VCUComErrDelay'
 * '<S18>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_DchaCtl_10ms/CmftDchaCtl/DchaMcuReqWiRelay/FaultCheck8'
 * '<S19>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_DchaCtl_10ms/CmftDchaCtl/DchaMcuReqWiRelay/RunToDisChaErr'
 * '<S20>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_DchaCtl_10ms/CmftDchaCtl/DchaMcuReqWiRelay/RunToDisChaErr/TimeAdding'
 * '<S21>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_DchaCtl_10ms/EmDchaCtl/EI09_EmDisChaFunction'
 * '<S22>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_DchaCtl_10ms/EmDchaCtl/EI09_EmDisChaFunction/FaultCheck8'
 * '<S23>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_DrvTrans/HvStateJudg'
 * '<S24>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_DrvTrans/TranDchaToNormal'
 * '<S25>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_DrvTrans/TranIdleToStb'
 * '<S26>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_DrvTrans/TranNormalToDcha'
 * '<S27>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_DrvTrans/TranOfstCalToStb'
 * '<S28>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_DrvTrans/TranRunToStb'
 * '<S29>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_DrvTrans/TranStbToEPP'
 * '<S30>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_DrvTrans/TranStbToIdle'
 * '<S31>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_DrvTrans/TranStbToOfstCal'
 * '<S32>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_DrvTrans/TranStbToRun'
 * '<S33>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_PreDrvTrans/TranDiagToSenCal'
 * '<S34>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_PreDrvTrans/TranLoPowSetToDiag'
 * '<S35>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_PreDrvTrans/TranPreDrvRunToFish'
 * '<S36>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_PreDrvTrans/TranSenCalToiMMO'
 * '<S37>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/ShutDownOverTime&TranPostDrvToShutDown'
 * '<S38>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/TranDrvToFail&TranFaultToDcha'
 * '<S39>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/TranDrvToPostDrv'
 * '<S40>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/TranFaultToPostDrv'
 * '<S41>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/TranPostDrvToPreDrive&TranPreDrvToFail'
 * '<S42>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/uDc_Spd_Is_Swt'
 * '<S43>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/uDc_n_Is_Limit'
 * '<S44>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/ShutDownOverTime&TranPostDrvToShutDown/ShutDownOverTime'
 * '<S45>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/ShutDownOverTime&TranPostDrvToShutDown/TranPostDrvToShutDown'
 * '<S46>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/ShutDownOverTime&TranPostDrvToShutDown/TranPreDrvToDrv'
 * '<S47>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/ShutDownOverTime&TranPostDrvToShutDown/TranPreDrvToPostDrv'
 * '<S48>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/ShutDownOverTime&TranPostDrvToShutDown/ShutDownOverTime/CntShutDownTime'
 * '<S49>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/ShutDownOverTime&TranPostDrvToShutDown/ShutDownOverTime/Enabled Subsystem'
 * '<S50>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/ShutDownOverTime&TranPostDrvToShutDown/ShutDownOverTime/Subsystem'
 * '<S51>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/ShutDownOverTime&TranPostDrvToShutDown/ShutDownOverTime/WakeLost'
 * '<S52>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/ShutDownOverTime&TranPostDrvToShutDown/ShutDownOverTime/WakeLost/Compare To Zero'
 * '<S53>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/TranDrvToFail&TranFaultToDcha/TranDrvToFail'
 * '<S54>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/TranDrvToFail&TranFaultToDcha/TranFaultToDcha'
 * '<S55>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/TranDrvToPostDrv/DrvToPostDrvReqCoord'
 * '<S56>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/TranDrvToPostDrv/PostDrvReqWiDcha'
 * '<S57>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/TranDrvToPostDrv/PostDrvReqWoDcha'
 * '<S58>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/TranDrvToPostDrv/DrvToPostDrvReqCoord/VcuComErr_Delay'
 * '<S59>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/TranFaultToPostDrv/FaultToPostDrvReqCoord'
 * '<S60>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/TranFaultToPostDrv/PostDrvReqWiDcha'
 * '<S61>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/TranFaultToPostDrv/PostDrvReqWoDcha'
 * '<S62>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/TranFaultToPostDrv/FaultToPostDrvReqCoord/VcuComErr_Delay1'
 * '<S63>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/TranPostDrvToPreDrive&TranPreDrvToFail/TranPostDrvToPreDrive'
 * '<S64>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SCF_SigInp_10ms/SCF_SysTrans/TranPostDrvToPreDrive&TranPreDrvToFail/TranPreDrvToFail'
 * '<S65>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SigMap/BSW_stGateDrvCtl'
 * '<S66>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SigMap/FRActionLogic'
 * '<S67>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SigMap/ToMc_stModCtl'
 * '<S68>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SigMap/ToTdc_stModCtl'
 * '<S69>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SigMap/ToTdc_stModCtl1'
 * '<S70>'  : 'SWC_SCF/RE_SWC_SCF_10ms_sys/SCF_Ctl/SigMap/ToTpc_flgudcLow'
 */
#endif                                 /* RTW_HEADER_SWC_SCF_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
