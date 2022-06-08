/*
 * File: SWC_HSPF.h
 *
 * Code generated for Simulink model 'SWC_HSPF'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Jan 19 14:59:09 2021
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_HSPF_h_
#define RTW_HEADER_SWC_HSPF_h_
#include <math.h>
#ifndef SWC_HSPF_COMMON_INCLUDES_
# define SWC_HSPF_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_SWC_HSPF.h"
#endif                                 /* SWC_HSPF_COMMON_INCLUDES_ */

#include "SWC_HSPF_types.h"

/* Macros for accessing real-time model data structure */

/* Exported data define */

/* Definition for custom storage class: Define */
#define CAL_Hspf_Failure_u8            3U                        /* Referenced by:
                                                                  * '<S21>/UIPhaSenOffCal'
                                                                  * '<S21>/VIPhaSenOffCal'
                                                                  * '<S21>/WIPhaSenOffCal'
                                                                  * '<S21>/CAL_Hspf_Failure_u8'
                                                                  */

/* 自检失败 */
#define CAL_Hspf_Succeed_u8            2U                        /* Referenced by:
                                                                  * '<S21>/UIPhaSenOffCal'
                                                                  * '<S21>/VIPhaSenOffCal'
                                                                  * '<S21>/WIPhaSenOffCal'
                                                                  * '<S21>/CAL_Hspf_Succeed_u8'
                                                                  */

/* 自检或标定成功 */
#define CAL_Hspf_Uncheck_u8            0U                        /* Referenced by:
                                                                  * '<S21>/UIPhaSenOffCal'
                                                                  * '<S21>/VIPhaSenOffCal'
                                                                  * '<S21>/WIPhaSenOffCal'
                                                                  * '<S21>/CAL_Hspf_Uncheck_u8'
                                                                  */

/* 自检未进行 */
#define GLB_HspfFlt_pi_f32             3.14159203F               /* Referenced by:
                                                                  * '<S30>/Constant2'
                                                                  * '<S49>/Constant2'
                                                                  * '<S50>/Constant2'
                                                                  * '<S51>/Constant2'
                                                                  * '<S54>/Constant2'
                                                                  * '<S56>/Constant2'
                                                                  * '<S57>/Constant2'
                                                                  * '<S58>/Constant2'
                                                                  * '<S59>/Constant2'
                                                                  * '<S60>/Constant2'
                                                                  * '<S62>/Constant2'
                                                                  * '<S63>/Constant2'
                                                                  */
#define PRV_CalFltFrq_10ms             100U                      /* Referenced by:
                                                                  * '<S7>/PRV_CalFltFrq_10ms_2'
                                                                  * '<S9>/PRV_CalFltFrq_10ms_1'
                                                                  * '<S9>/PRV_CalFltFrq_10ms_10'
                                                                  * '<S9>/PRV_CalFltFrq_10ms_11'
                                                                  * '<S9>/PRV_CalFltFrq_10ms_12'
                                                                  * '<S9>/PRV_CalFltFrq_10ms_13'
                                                                  * '<S9>/PRV_CalFltFrq_10ms_2'
                                                                  * '<S9>/PRV_CalFltFrq_10ms_3'
                                                                  * '<S9>/PRV_CalFltFrq_10ms_4'
                                                                  * '<S9>/PRV_CalFltFrq_10ms_5'
                                                                  * '<S9>/PRV_CalFltFrq_10ms_6'
                                                                  * '<S9>/PRV_CalFltFrq_10ms_7'
                                                                  */

/* Block signals (default storage) */
typedef struct tag_B_SWC_HSPF_T {
  float32 HSPF_iOffset;                /* '<S21>/WIPhaSenOffCal' */
  float32 HSPF_iOffset_i;              /* '<S21>/VIPhaSenOffCal' */
  float32 HSPF_iOffset_c;              /* '<S21>/UIPhaSenOffCal' */
  uint8 Switch;                        /* '<S21>/Switch' */
  uint8 Switch2;                       /* '<S21>/Switch2' */
  uint8 stiOfsClb;                     /* '<S21>/WIPhaSenOffCal' */
  uint8 stiOfsClb_n;                   /* '<S21>/VIPhaSenOffCal' */
  uint8 stiOfsClb_o;                   /* '<S21>/UIPhaSenOffCal' */
  boolean LogicalOperator2;            /* '<S21>/Logical Operator2' */
  boolean flgOfsClb;                   /* '<S21>/WIPhaSenOffCal' */
  boolean flgOfsClb_a;                 /* '<S21>/VIPhaSenOffCal' */
  boolean flgOfsClb_n;                 /* '<S21>/UIPhaSenOffCal' */
} B_SWC_HSPF_T;

/* Block states (default storage) for system '<Root>' */
typedef struct tag_DW_SWC_HSPF_T {
  float64 UnitDelay_DSTATE;            /* '<S61>/Unit Delay' */
  float64 UnitDelay_DSTATE_a;          /* '<S26>/Unit Delay' */
  float64 UnitDelay_DSTATE_d;          /* '<S27>/Unit Delay' */
  float64 UnitDelay2_DSTATE;           /* '<S53>/Unit Delay2' */
  float64 UnitDelay2_DSTATE_i;         /* '<S55>/Unit Delay2' */
  float64 UnitDelay2_DSTATE_a;         /* '<S64>/Unit Delay2' */
  float64 UnitDelay1_DSTATE;           /* '<S20>/Unit Delay1' */
  float64 UnitDelay_DSTATE_c;          /* '<S25>/Unit Delay' */
  float64 UnitDelay_DSTATE_cf;         /* '<S29>/Unit Delay' */
  float64 UnitDelay_DSTATE_f;          /* '<S28>/Unit Delay' */
  float32 UnitDelay1_DSTATE_n;         /* '<S53>/Unit Delay1' */
  float32 UnitDelay_DSTATE_ci;         /* '<S54>/Unit Delay' */
  float32 UnitDelay1_DSTATE_m;         /* '<S55>/Unit Delay1' */
  float32 UnitDelay_DSTATE_g;          /* '<S56>/Unit Delay' */
  float32 UnitDelay1_DSTATE_g;         /* '<S64>/Unit Delay1' */
  float32 UnitDelay_DSTATE_j;          /* '<S57>/Unit Delay' */
  float32 UnitDelay_DSTATE_l;          /* '<S63>/Unit Delay' */
  float32 UnitDelay_DSTATE_n;          /* '<S50>/Unit Delay' */
  float32 UnitDelay_DSTATE_h;          /* '<S60>/Unit Delay' */
  float32 UnitDelay_DSTATE_dp;         /* '<S59>/Unit Delay' */
  float32 UnitDelay_DSTATE_b;          /* '<S49>/Unit Delay' */
  float32 UnitDelay_DSTATE_nl;         /* '<S58>/Unit Delay' */
  float32 UnitDelay_DSTATE_bm;         /* '<S51>/Unit Delay' */
  float32 UnitDelay_DSTATE_ji;         /* '<S62>/Unit Delay' */
  float32 UnitDelay_DSTATE_o;          /* '<S30>/Unit Delay' */
  float32 UnitDelay_DSTATE_i;          /* '<S31>/Unit Delay' */
  float32 UnitDelay1_DSTATE_e;         /* '<S31>/Unit Delay1' */
  float32 UnitDelay2_DSTATE_ix;        /* '<S31>/Unit Delay2' */
  float32 UnitDelay3_DSTATE_b;         /* '<S31>/Unit Delay3' */
  float32 UnitDelay4_DSTATE;           /* '<S31>/Unit Delay4' */
  float32 UnitDelay5_DSTATE;           /* '<S31>/Unit Delay5' */
  float32 UnitDelay6_DSTATE;           /* '<S31>/Unit Delay6' */
  float32 UnitDelay7_DSTATE;           /* '<S31>/Unit Delay7' */
  float32 UnitDelay8_DSTATE;           /* '<S31>/Unit Delay8' */
  uint32 iValSum;                      /* '<S21>/WIPhaSenOffCal' */
  uint32 iValSum_e;                    /* '<S21>/VIPhaSenOffCal' */
  uint32 iValSum_i;                    /* '<S21>/UIPhaSenOffCal' */
  uint16 UnitDelay_DSTATE_nh;          /* '<S43>/Unit Delay' */
  uint16 cntSelfChkTolCnt;             /* '<S21>/WIPhaSenOffCal' */
  uint16 cntSelfChkValCnt;             /* '<S21>/WIPhaSenOffCal' */
  uint16 cntSelfChkTolCnt_n;           /* '<S21>/VIPhaSenOffCal' */
  uint16 cntSelfChkValCnt_i;           /* '<S21>/VIPhaSenOffCal' */
  uint16 cntSelfChkTolCnt_f;           /* '<S21>/UIPhaSenOffCal' */
  uint16 cntSelfChkValCnt_n;           /* '<S21>/UIPhaSenOffCal' */
  boolean UnitDelay_DSTATE_iz;         /* '<S65>/Unit Delay' */
  boolean UnitDelay1_DSTATE_mm;        /* '<S26>/Unit Delay1' */
  boolean UnitDelay3_DSTATE_a5;        /* '<S26>/Unit Delay3' */
  boolean UnitDelay2_DSTATE_o;         /* '<S26>/Unit Delay2' */
  boolean UnitDelay_DSTATE_e;          /* '<S5>/Unit Delay' */
  boolean UnitDelay1_DSTATE_a;         /* '<S27>/Unit Delay1' */
  boolean UnitDelay3_DSTATE_e;         /* '<S27>/Unit Delay3' */
  boolean UnitDelay2_DSTATE_l;         /* '<S27>/Unit Delay2' */
  boolean UnitDelay4_DSTATE_c;         /* '<S53>/Unit Delay4' */
  boolean UnitDelay4_DSTATE_a;         /* '<S55>/Unit Delay4' */
  boolean UnitDelay4_DSTATE_e;         /* '<S64>/Unit Delay4' */
  boolean UnitDelay1_DSTATE_j;         /* '<S25>/Unit Delay1' */
  boolean UnitDelay3_DSTATE_pc;        /* '<S25>/Unit Delay3' */
  boolean UnitDelay2_DSTATE_ns;        /* '<S25>/Unit Delay2' */
  boolean UnitDelay1_DSTATE_i;         /* '<S29>/Unit Delay1' */
  boolean UnitDelay3_DSTATE_h;         /* '<S29>/Unit Delay3' */
  boolean UnitDelay2_DSTATE_f;         /* '<S29>/Unit Delay2' */
  boolean UnitDelay1_DSTATE_p;         /* '<S28>/Unit Delay1' */
  boolean UnitDelay3_DSTATE_m;         /* '<S28>/Unit Delay3' */
  boolean UnitDelay2_DSTATE_fs;        /* '<S28>/Unit Delay2' */
  uint8 is_active_c5_SWC_HSPF;         /* '<S21>/WIPhaSenOffCal' */
  uint8 is_c5_SWC_HSPF;                /* '<S21>/WIPhaSenOffCal' */
  uint8 is_active_c1_SWC_HSPF;         /* '<S21>/VIPhaSenOffCal' */
  uint8 is_c1_SWC_HSPF;                /* '<S21>/VIPhaSenOffCal' */
  uint8 is_active_c2_SWC_HSPF;         /* '<S21>/UIPhaSenOffCal' */
  uint8 is_c2_SWC_HSPF;                /* '<S21>/UIPhaSenOffCal' */
} DW_SWC_HSPF_T;

/* Block signals (default storage) */
extern B_SWC_HSPF_T SWC_HSPF_B;

/* Block states (default storage) */
extern DW_SWC_HSPF_T SWC_HSPF_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern float32 VAR_Bsw_Hwver_f32;
               /* '<S1>/RP_SWC_IoHwAb_ADC_BSW_HwVer_IoHwAb_ADC_GetPhyVoltage' */
extern float32 VAR_Hspf_tDBCTempU_f32; /* '<S53>/Switch2' */
extern float32 VAR_Hspf_tDBCTempV_f32; /* '<S55>/Switch2' */
extern float32 VAR_Hspf_tDBCTempW_f32; /* '<S64>/Switch2' */
extern float32 VAR_Bsw_tCoolantTemp_f32;
        /* '<S1>/RP_SWC_IoHwAb_ADC_BSW_tCoolantTemp_IoHwAb_ADC_GetPhyVoltage' */
extern float32 VAR_Hspf_uKl30_f32;
               /* '<S1>/RP_SWC_IoHwAb_ADC_BSW_uKl30_IoHwAb_ADC_GetPhyVoltage' */
extern float32 VAR_Hspf_tCoolantTemp_f32;/* '<S52>/tCoolantTem_Table' */
extern float32 VAR_Hspf_tDrvBoardTemp_f32;/* '<S48>/PCBTem_Table' */
extern float32 VAR_Hspf_uDcLnk_f32;    /* '<S9>/Gain' */
extern uint16 VAR_Bsw_tStrrTemp1_u16;  /* '<S9>/Data Type Conversion1' */
extern uint16 VAR_Bsw_tStrrTemp2_u16;  /* '<S9>/Data Type Conversion' */
extern uint16 VAR_Bsw_tDBCTempU_u16;   /* '<S9>/Gain1' */
extern uint16 VAR_Bsw_tDBCTempV_u16;   /* '<S9>/Gain2' */
extern uint16 VAR_Bsw_tDBCTempW_u16;   /* '<S9>/Gain3' */
extern uint16 VAR_Bsw_tDrvBoardTemp_u16;/* '<S9>/Gain4' */
extern sint16 VAR_Hspf_tStrrTemp1_s16; /* '<S65>/Switch' */
extern sint16 VAR_Hspf_tStrrTemp2_s16; /* '<S61>/Switch' */
extern uint8 VAR_Hspf_stVerChk_u8;     /* '<S43>/Switch4' */
extern uint8 VAR_Hspf_VerMatchFailureErr_u8;/* '<S43>/Add1' */
extern uint8 VAR_Hspf_HWVer_u8;        /* '<S43>/Data Type Conversion' */
extern boolean VAR_Hspf_bSwtTempSttr1_b;/* '<S65>/Logical Operator' */
extern boolean VAR_Hspf_bSwtTempSttr2_b;/* '<S61>/Logical Operator' */
extern boolean VAR_Bsw_INV_Open_b;
                /* '<S1>/RP_SWC_IoHwAb_DIO_Get_BSW_flgMcuOpen_IoHwAb_DIO_Get' */
extern boolean VAR_Bsw_Motor_Open_b;
              /* '<S1>/RP_SWC_IoHwAb_DIO_Get_BSW_flgMotorOpen_IoHwAb_DIO_Get' */
extern boolean VAR_Hspf_tDBCCmpErrDelay_b;/* '<S20>/Relational Operator' */
extern boolean VAR_Bsw_Wake_b;
                      /* '<S1>/RP_SWC_IoHwAb_DIO_Get_BSW_Wake_IoHwAb_DIO_Get' */
extern boolean VAR_Bsw_bt15_b;
                      /* '<S1>/RP_SWC_IoHwAb_DIO_Get_BSW_bt15_IoHwAb_DIO_Get' */
extern boolean VAR_Bsw_Crash_b;
                  /* '<S1>/RP_SWC_IoHwAb_DIO_Get_BSW_flgCrash_IoHwAb_DIO_Get' */
extern boolean VAR_Hspf_flgSttr2NoErr_b;/* '<S11>/Logical Operator1' */
extern boolean VAR_Hspf_flgSttr1NoErr_b;/* '<S11>/Logical Operator' */

/* Exported data declaration */
#pragma section ".rodata.Calib_32"

/* Declaration for custom storage class: iEDS_Parameter */
extern const volatile float32 CAL_Hspf_CPLDProjectNumTable_af32[6];
                                  /* Referenced by: '<S43>/2-D Lookup Table1' */

/* CPLD项目号 */
extern const volatile float32 CAL_Hspf_CltInletTempFltFrq_f32;
                     /* Referenced by: '<S9>/CAL_Hspf_CltInletTempFltFrq_f32' */
extern const volatile float32 CAL_Hspf_CodeCpldSwMatchTable_af32[28];
                                  /* Referenced by: '<S43>/2-D Lookup Table2' */

/* 软件和CPLD软件版本号匹配表 */
extern const volatile float32 CAL_Hspf_CodeDataMatchTable_af32[42];
                                   /* Referenced by: '<S43>/2-D Lookup Table' */

/* 软件和数据匹配表 */
extern const volatile float32 CAL_Hspf_CodeHvMcuMatchTable_af32[42];
                                  /* Referenced by: '<S43>/2-D Lookup Table3' */

/* 软件和高压MCU版本号匹配表 */
extern const volatile float32 CAL_Hspf_CodeTable_af32[7];/* Referenced by:
                                                          * '<S43>/2-D Lookup Table'
                                                          * '<S43>/2-D Lookup Table2'
                                                          * '<S43>/2-D Lookup Table3'
                                                          */

/* 软件版本号 */
extern const volatile float32 CAL_Hspf_CpldSwTable_af32[4];
                                  /* Referenced by: '<S43>/2-D Lookup Table2' */

/* CPLD软件版本 */
extern const volatile uint8 CAL_Hspf_CrashChkAddCnt_u8;
                         /* Referenced by: '<S25>/CAL_Hspf_CrashChkAddCnt_u8' */
extern const volatile uint8 CAL_Hspf_CrashChkCntHiLim_u8;
                       /* Referenced by: '<S25>/CAL_Hspf_CrashChkCntHiLim_u8' */
extern const volatile sint8 CAL_Hspf_CrashChkCntLoLim_s8;
                       /* Referenced by: '<S25>/CAL_Hspf_CrashChkCntLoLim_s8' */
extern const volatile sint8 CAL_Hspf_CrashChkSubCnt_s8;
                         /* Referenced by: '<S25>/CAL_Hspf_CrashChkSubCnt_u8' */
extern const volatile uint8 CAL_Hspf_DBCTempROCLimChkCnt_u8;/* Referenced by:
                                                             * '<S53>/CAL_Hspf_DBCTempROCLimChkCnt_u8'
                                                             * '<S55>/CAL_Hspf_DBCTempROCLimChkCnt_u8'
                                                             * '<S64>/CAL_Hspf_DBCTempROCLimChkCnt_u8'
                                                             */
extern const volatile float32 CAL_Hspf_DataTable_af32[6];
                                   /* Referenced by: '<S43>/2-D Lookup Table' */

/* 数据版本号 */
extern const volatile float32 CAL_Hspf_HvMcuTable_af32[6];
                                  /* Referenced by: '<S43>/2-D Lookup Table3' */

/* 高压MCU版本号 */
extern const volatile float32 CAL_Hspf_HwAnalHwVerMatchTable_af32[12];
                                  /* Referenced by: '<S43>/2-D Lookup Table4' */

/* 硬件匹配表 */
extern const volatile float32 CAL_Hspf_HwAnalTable_af32[2];
                                  /* Referenced by: '<S43>/2-D Lookup Table4' */

/* 解析匹配 */
extern const volatile float32 CAL_Hspf_HwVerTable_af32[6];
                                  /* Referenced by: '<S43>/2-D Lookup Table4' */

/* 硬件版本号 */
extern const volatile uint8 CAL_Hspf_INVOpenChkAddCnt_u8;
                       /* Referenced by: '<S26>/CAL_Hspf_INVOpenChkAddCnt_u8' */
extern const volatile uint8 CAL_Hspf_INVOpenChkCntHiLim_u8;
                     /* Referenced by: '<S26>/CAL_Hspf_INVOpenChkCntHiLim_u8' */
extern const volatile sint8 CAL_Hspf_INVOpenChkCntLoLim_s8;
                     /* Referenced by: '<S26>/CAL_Hspf_INVOpenChkCntLoLim_s8' */
extern const volatile sint8 CAL_Hspf_INVOpenChkSubCnt_s8;
                       /* Referenced by: '<S26>/CAL_Hspf_INVOpenChkSubCnt_s8' */
extern const volatile uint64 CAL_Hspf_McuName_u64;
                               /* Referenced by: '<S43>/CAL_Hspf_McuName_u64' */

/* 6位MCU规范命名解析的十进制数 */
extern const volatile uint8 CAL_Hspf_MotTemHigTable_af32[1024];/* Referenced by:
                                                                * '<S61>/Constant'
                                                                * '<S65>/Constant'
                                                                */
extern const volatile sint8 CAL_Hspf_MotTemLowTable_af32[1024];/* Referenced by:
                                                                * '<S61>/Constant1'
                                                                * '<S65>/Constant1'
                                                                */
extern const volatile uint8 CAL_Hspf_MotorOpenChkAddCnt_u8;
                     /* Referenced by: '<S27>/CAL_Hspf_MotorOpenChkAddCnt_u8' */
extern const volatile uint8 CAL_Hspf_MotorOpenChkCntHiLim_u8;
                   /* Referenced by: '<S27>/CAL_Hspf_MotorOpenChkCntHiLim_u8' */
extern const volatile sint8 CAL_Hspf_MotorOpenChkCntLoLim_s8;
                   /* Referenced by: '<S27>/CAL_Hspf_MotorOpenChkCntLoLim_s8' */
extern const volatile sint8 CAL_Hspf_MototOpenChkSubCnt_s8;
                     /* Referenced by: '<S27>/CAL_Hspf_MototOpenChkSubCnt_s8' */
extern const volatile uint8 CAL_Hspf_Multiple_u8;/* Referenced by:
                                                  * '<S30>/CAL_Hspf_Multiple_u8'
                                                  * '<S49>/CAL_Hspf_Multiple_u8'
                                                  * '<S50>/CAL_Hspf_Multiple_u8'
                                                  * '<S51>/CAL_Spf_Multiple_u8'
                                                  * '<S54>/CAL_Hspf_Multiple_u8'
                                                  * '<S56>/CAL_Hspf_Multiple_u8'
                                                  * '<S57>/CAL_Hspf_Multiple_u8'
                                                  * '<S58>/CAL_Hspf_Multiple_u8'
                                                  * '<S59>/CAL_Hspf_Multiple_u8'
                                                  * '<S60>/CAL_Spf_Multiple_u8'
                                                  * '<S62>/CAL_Hspf_Multiple_u8'
                                                  * '<S63>/CAL_Hspf_Multiple_u8'
                                                  */

/* 信号采样频率 */
extern const volatile float32 CAL_Hspf_ProjectNumMatchTable_af32[42];
                                  /* Referenced by: '<S43>/2-D Lookup Table1' */

/* 项目匹配表 */
extern const volatile float32 CAL_Hspf_ProjectNuminSWTable_af32[7];
                                  /* Referenced by: '<S43>/2-D Lookup Table1' */

/* 解析出来的项目号 */
extern const volatile uint64 CAL_Hspf_Tc277Name_u64;/* Referenced by:
                                                     * '<S43>/CAL_Hspf_Tc277Name_u64'
                                                     * '<S43>/CAL_Hspf_Tc277Name_u64_2'
                                                     * '<S43>/CAL_Hspf_Tc277Name_u64_3'
                                                     * '<S43>/CAL_Hspf_Tc277Name_u64_4'
                                                     */

/* 8位软件规范命名解析的十进制数 */
extern const volatile float32 CAL_Hspf_TmpCoolanTjFltFrq_f32;
                             /* Referenced by: '<S7>/CAL_Hspf_TmpUFltFrq_f32' */

/* 估算水温滤波频率 */
extern const volatile float32 CAL_Hspf_TmpUFltFrq_f32;
                             /* Referenced by: '<S9>/CAL_Hspf_TmpUFltFrq_f32' */

/* Temperature filter cut off frequency */
extern const volatile float32 CAL_Hspf_TmpVFltFrq_f32;
                             /* Referenced by: '<S9>/CAL_Hspf_TmpVFltFrq_f32' */
extern const volatile float32 CAL_Hspf_TmpWFltFrq_f32;
                             /* Referenced by: '<S9>/CAL_Hspf_TmpWFltFrq_f32' */
extern const volatile uint16 CAL_Hspf_VerChkTime_u16;/* Referenced by: '<S45>/Constant' */

/* 软件匹配超时 */
extern const volatile uint8 CAL_Hspf_VerMatchFailure_u8;/* Referenced by:
                                                         * '<S43>/CAL_Hspf_VerMatchFailure_u8'
                                                         * '<S43>/CAL_Spf_VerMatchFailure_u8'
                                                         */

/* 自检失败 */
extern const volatile uint8 CAL_Hspf_VerMatchSucceed_u8;
                        /* Referenced by: '<S43>/CAL_Hspf_VerMatchSucceed_u8' */

/* 自检成功 */
extern const volatile uint8 CAL_Hspf_VerMatchTimeOutErr_u8;/* Referenced by: '<S43>/Constant11 ' */

/* 自检进行中 */
extern const volatile uint8 CAL_Hspf_VerMatchUncheck_u8;/* Referenced by:
                                                         * '<S42>/Constant'
                                                         * '<S43>/CAL_Hspf_VerMatchUncheck_u8'
                                                         * '<S44>/Constant'
                                                         */

/* 自检未进行 */
extern const volatile uint8 CAL_Hspf_bt15ChkAddCnt_u8;/* Referenced by:
                                                       * '<S28>/CAL_Hspf_bt15ChkAddCnt_u8'
                                                       * '<S29>/CAL_Hspf_bt15ChkAddCnt_u8'
                                                       */

/* 点火信号确认上加个数 */
extern const volatile uint8 CAL_Hspf_bt15ChkCntHiLim_u8;/* Referenced by:
                                                         * '<S28>/CAL_Hspf_bt15ChkCntHiLim_u8'
                                                         * '<S29>/CAL_Hspf_bt15ChkCntHiLim_u8'
                                                         */

/* 点火信号确认上限限值 */
extern const volatile sint8 CAL_Hspf_bt15ChkCntLoLim_s8;/* Referenced by:
                                                         * '<S28>/CAL_Hspf_bt15ChkCntLoLim_s8'
                                                         * '<S29>/CAL_Hspf_bt15ChkCntLoLim_s8'
                                                         */

/* 点火信号消除下限限值 */
extern const volatile sint8 CAL_Hspf_bt15ChkSubCnt_s8;/* Referenced by:
                                                       * '<S28>/CAL_Hspf_bt15ChkSubCnt_s8'
                                                       * '<S29>/CAL_Hspf_bt15ChkSubCnt_s8'
                                                       */

/* 点火信号确认下减个数 */
extern const volatile uint16 CAL_Hspf_cntIPhCalOffTolCnt_u16;
                     /* Referenced by: '<S21>/CAL_CSP_cntIPhCalOffTolCnt_u16' */

/* 相电流采样总计数 */
extern const volatile uint16 CAL_Hspf_cntIPhCalOffValCnt_u16;
                     /* Referenced by: '<S21>/CAL_CSP_cntIPhCalOffValCnt_u16' */

/* 相电流采样有效计数 */
extern const volatile float32 CAL_Hspf_iDcLnkEstFltFrq_f32;
                      /* Referenced by: '<S9>/CAL_Hspf_CltInletTempFltFrq_f1' */

/* 母线电流慢滤波值 */
extern const volatile uint16 CAL_Hspf_iPhaHighSet_u16;
                           /* Referenced by: '<S21>/CAL_Hspf_iPhaHighSet_u16' */

/* 相电流采样有效上限 */
extern const volatile uint16 CAL_Hspf_iPhaLowSet_u16;
                            /* Referenced by: '<S21>/CAL_Hspf_iPhaLowSet_u16' */

/* 相电流采样有效下限 */
extern const volatile float32 CAL_Hspf_nFltFrq_f32;
                                /* Referenced by: '<S9>/CAL_Hspf_nFltFrq_f32' */

/* 电机转速慢滤波截止频率  */
extern const volatile uint8 CAL_Hspf_stPreDrvCtl_u8;
                            /* Referenced by: '<S21>/CAL_Hspf_stPreDrvCtl_u8' */
extern const volatile float32 CAL_Hspf_tCoolantFltFrq_f32;
                         /* Referenced by: '<S9>/CAL_Hspf_tCoolantFltFrq_f32' */

/* 冷却水滤波截止频率 */
extern const volatile uint16 CAL_Hspf_tDBCCmpTime_u16;/* Referenced by: '<S20>/Constant' */
extern const volatile uint8 CAL_Hspf_tDBCTempROCLim_u8;/* Referenced by:
                                                        * '<S53>/CAL_Hspf_tDBCTempROCLim_u8'
                                                        * '<S55>/CAL_Hspf_tDBCTempROCLim_u8'
                                                        * '<S64>/CAL_Hspf_tDBCTempROCLim_u8'
                                                        */
extern const volatile uint8 CAL_Hspf_tDBCtempOffset_u8;
                          /* Referenced by: '<S12>/CAL_SDF_tDBCtempOffset_u8' */

/* IGBT温度偏差阈值 */
extern const volatile float32 CAL_Hspf_tStrrTmp1FltFrq_f32;
                        /* Referenced by: '<S9>/CAL_Hspf_tStrrTmp1FltFrq_f32' */
extern const volatile float32 CAL_Hspf_tStrrTmp2FltFrq_f32;
                        /* Referenced by: '<S9>/CAL_Hspf_tStrrTmp2FltFrq_f32' */
extern const volatile float32 CAL_Hspf_tSwtTempSttrHiLim_f32;/* Referenced by:
                                                              * '<S61>/CAL_Hspf_tSwtTempSttrHiLim_f32'
                                                              * '<S65>/CAL_Hspf_tSwtTempSttrHiLim_f32'
                                                              */
extern const volatile float32 CAL_Hspf_tSwtTempSttrLoLim_f32;/* Referenced by:
                                                              * '<S61>/CAL_Hspf_tSwtTempSttrLoLim_f32'
                                                              * '<S65>/CAL_Hspf_tSwtTempSttrLoLim_f32'
                                                              */
extern const volatile float32 CAL_Hspf_uDcLnkFltFrq_f32;
                           /* Referenced by: '<S9>/CAL_Hspf_uDcLnkFltFrq_f32' */

/* 母线电压慢滤波截止频率  */
extern const volatile float32 CAL_Hspf_uKl30FltFrq_f32;
                            /* Referenced by: '<S9>/CAL_Hspf_uKl30FltFrq_f32' */

#pragma section

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S32>/Data Type Duplicate' : Unused code path elimination
 * Block '<S32>/Data Type Propagation' : Unused code path elimination
 * Block '<S66>/Data Type Duplicate' : Unused code path elimination
 * Block '<S66>/Data Type Propagation' : Unused code path elimination
 * Block '<S67>/Data Type Duplicate' : Unused code path elimination
 * Block '<S67>/Data Type Propagation' : Unused code path elimination
 * Block '<S68>/Data Type Duplicate' : Unused code path elimination
 * Block '<S68>/Data Type Propagation' : Unused code path elimination
 * Block '<S69>/Data Type Duplicate' : Unused code path elimination
 * Block '<S69>/Data Type Propagation' : Unused code path elimination
 * Block '<S70>/Data Type Duplicate' : Unused code path elimination
 * Block '<S70>/Data Type Propagation' : Unused code path elimination
 * Block '<S71>/Data Type Duplicate' : Unused code path elimination
 * Block '<S71>/Data Type Propagation' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Data Type Propagation' : Unused code path elimination
 * Block '<S73>/Data Type Duplicate' : Unused code path elimination
 * Block '<S73>/Data Type Propagation' : Unused code path elimination
 * Block '<S74>/Data Type Duplicate' : Unused code path elimination
 * Block '<S74>/Data Type Propagation' : Unused code path elimination
 * Block '<S75>/Data Type Duplicate' : Unused code path elimination
 * Block '<S75>/Data Type Propagation' : Unused code path elimination
 * Block '<S76>/Data Type Duplicate' : Unused code path elimination
 * Block '<S76>/Data Type Propagation' : Unused code path elimination
 * Block '<S43>/Data Type Conversion9' : Eliminate redundant data type conversion
 * Block '<S61>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S65>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'SWC_HSPF'
 * '<S1>'   : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys'
 * '<S2>'   : 'SWC_HSPF/RE_SWC_HSPF_Init'
 * '<S3>'   : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem'
 * '<S4>'   : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_GsDia'
 * '<S5>'   : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_SelfTest'
 * '<S6>'   : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_SigDebounce'
 * '<S7>'   : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_TjProcess'
 * '<S8>'   : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_VerChk'
 * '<S9>'   : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt'
 * '<S10>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_GsDia/HSPF_Motor_INV_OpenDia'
 * '<S11>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_GsDia/HSPF_sttrTempDia'
 * '<S12>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_GsDia/HSPF_tDBCTempDia'
 * '<S13>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_GsDia/HSPF_Motor_INV_OpenDia/HSPF_INVOpenWarn1'
 * '<S14>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_GsDia/HSPF_Motor_INV_OpenDia/HSPF_MotorOpenErr'
 * '<S15>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_GsDia/HSPF_Motor_INV_OpenDia/HSPF_INVOpenWarn1/Compare To Zero'
 * '<S16>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_GsDia/HSPF_Motor_INV_OpenDia/HSPF_MotorOpenErr/Compare To Zero'
 * '<S17>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_GsDia/HSPF_sttrTempDia/SttrTempPro'
 * '<S18>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_GsDia/HSPF_tDBCTempDia/Compare To Constant'
 * '<S19>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_GsDia/HSPF_tDBCTempDia/Compare To Constant1'
 * '<S20>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_GsDia/HSPF_tDBCTempDia/ErrDelay'
 * '<S21>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_SelfTest/IPhaSenOffCal1'
 * '<S22>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_SelfTest/IPhaSenOffCal1/UIPhaSenOffCal'
 * '<S23>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_SelfTest/IPhaSenOffCal1/VIPhaSenOffCal'
 * '<S24>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_SelfTest/IPhaSenOffCal1/WIPhaSenOffCal'
 * '<S25>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_SigDebounce/HSPF_CrashDebounce'
 * '<S26>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_SigDebounce/HSPF_INV_OpenDebounce'
 * '<S27>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_SigDebounce/HSPF_Motor_OpenDebounce'
 * '<S28>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_SigDebounce/HSPF_WakeDebounce'
 * '<S29>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_SigDebounce/HSPF_bt15Debounce'
 * '<S30>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_TjProcess/HSPF_tDBCTempUFilter'
 * '<S31>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_TjProcess/increaseFlt'
 * '<S32>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_TjProcess/HSPF_tDBCTempUFilter/Saturation Dynamic'
 * '<S33>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_TjProcess/increaseFlt/MAX'
 * '<S34>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_TjProcess/increaseFlt/MAX1'
 * '<S35>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_TjProcess/increaseFlt/MAX2'
 * '<S36>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_TjProcess/increaseFlt/MAX3'
 * '<S37>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_TjProcess/increaseFlt/MAX4'
 * '<S38>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_TjProcess/increaseFlt/MAX5'
 * '<S39>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_TjProcess/increaseFlt/MAX6'
 * '<S40>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_TjProcess/increaseFlt/MAX7'
 * '<S41>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_TjProcess/increaseFlt/MAX8'
 * '<S42>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_VerChk/Compare To Constant7'
 * '<S43>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_VerChk/HspfVerChk'
 * '<S44>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_VerChk/HspfVerChk/Compare To Constant'
 * '<S45>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_VerChk/HspfVerChk/Compare To Constant1'
 * '<S46>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_VerChk/HspfVerChk/Compare To Zero8'
 * '<S47>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/HSPF_VerChk/HspfVerChk/Compare To Zero9'
 * '<S48>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/DrvBoardTemp'
 * '<S49>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/HSPF_nFilter'
 * '<S50>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/HSPF_tCoolantFilter'
 * '<S51>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/HSPF_tCoolantFilter2'
 * '<S52>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/HSPF_tCoolantTemp'
 * '<S53>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/HSPF_tDBCTempUCnv'
 * '<S54>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/HSPF_tDBCTempUFilter'
 * '<S55>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/HSPF_tDBCTempVCnv'
 * '<S56>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/HSPF_tDBCTempVFilter'
 * '<S57>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/HSPF_tDBCTempWFilter'
 * '<S58>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/HSPF_tDrvBoardTemp'
 * '<S59>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/HSPF_tStrrTemp1Filter'
 * '<S60>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/HSPF_tStrrTemp2Filter'
 * '<S61>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/HSPF_tSttrTemp2Cnv'
 * '<S62>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/HSPF_uDcLnkFilter'
 * '<S63>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/HSPF_uKl30Filter'
 * '<S64>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/SPF_tDBCTempWCnv'
 * '<S65>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/SPF_tSttrTemp1Cnv'
 * '<S66>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/HSPF_nFilter/Saturation Dynamic'
 * '<S67>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/HSPF_tCoolantFilter/Saturation Dynamic'
 * '<S68>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/HSPF_tCoolantFilter2/Saturation Dynamic'
 * '<S69>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/HSPF_tDBCTempUFilter/Saturation Dynamic'
 * '<S70>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/HSPF_tDBCTempVFilter/Saturation Dynamic'
 * '<S71>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/HSPF_tDBCTempWFilter/Saturation Dynamic'
 * '<S72>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/HSPF_tDrvBoardTemp/Saturation Dynamic'
 * '<S73>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/HSPF_tStrrTemp1Filter/Saturation Dynamic'
 * '<S74>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/HSPF_tStrrTemp2Filter/Saturation Dynamic'
 * '<S75>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/HSPF_uDcLnkFilter/Saturation Dynamic'
 * '<S76>'  : 'SWC_HSPF/RE_SWC_HSPF_10ms_sys/Subsystem/SPF_SigFlt/HSPF_uKl30Filter/Saturation Dynamic'
 */
#endif                                 /* RTW_HEADER_SWC_HSPF_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
