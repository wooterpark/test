/*
 * File: SWC_TPC.h
 *
 * Code generated for Simulink model 'SWC_TPC'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Fri Jan 15 14:28:54 2021
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_TPC_h_
#define RTW_HEADER_SWC_TPC_h_
#include <math.h>
#ifndef SWC_TPC_COMMON_INCLUDES_
# define SWC_TPC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_SWC_TPC.h"
#endif                                 /* SWC_TPC_COMMON_INCLUDES_ */

#include "SWC_TPC_types.h"

/* Macros for accessing real-time model data structure */

/* Exported data define */

/* Definition for custom storage class: Define */
#define GLB_TpcCod_BwELect_u8          3U                        /* Referenced by: '<S50>/GLB_TpcCod_BwELect_u8' */

/* 后退电动（第三象限） */
#define GLB_TpcCod_BwGene_u8           2U                        /* Referenced by: '<S48>/GLB_TpcCod_BwGene_u8' */

/* 后退发电（第二象限） */
#define GLB_TpcCod_FwELect_u8          1U                        /* Referenced by:
                                                                  * '<S8>/GLB_TpcCod_FwELect_u8'
                                                                  * '<S27>/GLB_TpcCod_FwELect_u8'
                                                                  * '<S47>/GLB_TpcCod_FwELect_u8'
                                                                  * '<S54>/GLB_TpcCod_FwELect_u8'
                                                                  */

/* 前进电动（第一象限） */
#define GLB_TpcCod_FwGene_u8           4U                        /* Referenced by:
                                                                  * '<S8>/GLB_TpcCod_FwGene_u8'
                                                                  * '<S27>/GLB_TpcCod_FwGene_u8'
                                                                  * '<S49>/GLB_TpcCod_FwGene_u8'
                                                                  * '<S54>/GLB_TpcCod_FwGene_u8'
                                                                  */

/* 前进发电（第四象限） */
#define GLB_TpcCod_MotorBw_u8          2U                        /* Referenced by:
                                                                  * '<S44>/GLB_TpcCod_MotorBw_u8'
                                                                  * '<S45>/GLB_TpcCod_MotorBw_u8'
                                                                  */

/* 转速后退 */
#define GLB_TpcCod_MotorFw_u8          1U                        /* Referenced by:
                                                                  * '<S44>/GLB_TpcCod_MotorFw_u8'
                                                                  * '<S45>/GLB_TpcCod_MotorFw_u8'
                                                                  */

/* 转速前进 */
#define GLB_TpcCod_MotorStop_u8        0U                        /* Referenced by:
                                                                  * '<S27>/GLB_TpcCod_MotorStop_u8'
                                                                  * '<S45>/GLB_TpcCod_MotorStop_u8'
                                                                  * '<S37>/GLB_TpcCod_MotorStop_u8'
                                                                  * '<S38>/GLB_TpcCod_MotorStop_u8'
                                                                  * '<S39>/GLB_TpcCod_MotorStop_u8'
                                                                  * '<S41>/GLB_TpcCod_MotorStop_u8'
                                                                  * '<S42>/GLB_TpcCod_MotorStop_u8'
                                                                  * '<S43>/GLB_TpcCod_MotorStop_u8'
                                                                  */

/* 转速静止 */
#define GLB_TpcCod_NegvTrq_u8          2U                        /* Referenced by:
                                                                  * '<S44>/GLB_TpcCod_NegvTrq_u8'
                                                                  * '<S46>/GLB_TpcCod_NegvTrq_u8'
                                                                  */

/* 扭矩后退 */
#define GLB_TpcCod_PosvTrq_u8          1U                        /* Referenced by:
                                                                  * '<S44>/GLB_TpcCod_PosvTrq_u8'
                                                                  * '<S46>/GLB_TpcCod_PosvTrq_u8'
                                                                  */

/* 扭矩前进 */
#define GLB_TpcCod_ZeroTrq_u8          0U                        /* Referenced by: '<S46>/GLB_TpcCod_ZeroTrq_u8' */

/* 扭矩静止 */
#define GLB_Tpc_MaximumPower_f32       150.0F                    /* Referenced by:
                                                                  * '<S117>/GLB_Tpc_MaximumPower_f32'
                                                                  * '<S177>/GLB_Tpc_MaximumPower_f32'
                                                                  */

/* 全局最大功率 */
#define GLB_Tpc_MaximumTorque_f32      310.0F                    /* Referenced by:
                                                                  * '<S105>/GLB_Tpc_MaximumTorque_f1'
                                                                  * '<S105>/GLB_Tpc_MaximumTorque_f32'
                                                                  * '<S117>/GLB_Tpc_MaximumTorque_f32'
                                                                  * '<S37>/GLB_Tpc_MaximumTorque_f32'
                                                                  * '<S38>/GLB_Tpc_MaximumTorque_f32'
                                                                  * '<S39>/GLB_Tpc_MaximumTorque_f32'
                                                                  * '<S41>/GLB_Tpc_MaximumTorque_f32'
                                                                  * '<S42>/GLB_Tpc_MaximumTorque_f32'
                                                                  * '<S43>/GLB_Tpc_MaximumTorque_f32'
                                                                  */

/* 全局最大扭矩 */

/* Block states (default storage) for system '<Root>' */
typedef struct tag_DW_SWC_TPC_T {
  float32 UnitDelay1_DSTATE;           /* '<S202>/Unit Delay1' */
  float32 UnitDelay2_DSTATE;           /* '<S203>/Unit Delay2' */
  float32 UnitDelay1_DSTATE_c;         /* '<S209>/Unit Delay1' */
  float32 UnitDelay2_DSTATE_b;         /* '<S216>/Unit Delay2' */
  float32 UnitDelay1_DSTATE_e;         /* '<S220>/Unit Delay1' */
  float32 UnitDelay2_DSTATE_m;         /* '<S217>/Unit Delay2' */
  float32 UnitDelay1_DSTATE_h;         /* '<S236>/Unit Delay1' */
  float32 UnitDelay2_DSTATE_bo;        /* '<S234>/Unit Delay2' */
  float32 UnitDelay1_DSTATE_n;         /* '<S241>/Unit Delay1' */
  float32 UnitDelay2_DSTATE_a;         /* '<S235>/Unit Delay2' */
  float32 UnitDelay1_DSTATE_a;         /* '<S132>/Unit Delay1' */
  float32 UnitDelay2_DSTATE_k;         /* '<S131>/Unit Delay2' */
  float32 UnitDelay2_DSTATE_mz;        /* '<S130>/Unit Delay2' */
  float32 UnitDelay1_DSTATE_b;         /* '<S164>/Unit Delay1' */
  float32 UnitDelay2_DSTATE_l;         /* '<S125>/Unit Delay2' */
  float32 UnitDelay2_DSTATE_c;         /* '<S174>/Unit Delay2' */
  float32 UnitDelay2_DSTATE_d;         /* '<S124>/Unit Delay2' */
  float32 UnitDelay2_DSTATE_g;         /* '<S182>/Unit Delay2' */
  float32 UnitDelay_DSTATE_eh;         /* '<S15>/Unit Delay' */
  float32 Delay1_DSTATE;               /* '<S15>/Delay1' */
  float32 Delay10_DSTATE[2];           /* '<S15>/Delay10' */
  float32 Delay9_DSTATE[3];            /* '<S15>/Delay9' */
  float32 Delay7_DSTATE[4];            /* '<S15>/Delay7' */
  float32 Delay6_DSTATE[5];            /* '<S15>/Delay6' */
  float32 Delay5_DSTATE[6];            /* '<S15>/Delay5' */
  float32 Delay4_DSTATE[7];            /* '<S15>/Delay4' */
  float32 Delay3_DSTATE[8];            /* '<S15>/Delay3' */
  float32 Delay2_DSTATE[9];            /* '<S15>/Delay2' */
  float32 UnitDelay3_DSTATE;           /* '<S105>/Unit Delay3' */
  float32 UnitDelay2_DSTATE_al;        /* '<S105>/Unit Delay2' */
  float32 UnitDelay_DSTATE_hx;         /* '<S21>/Unit Delay' */
  float32 UnitDelay_DSTATE_gh;         /* '<S22>/Unit Delay' */
  float32 Is_Sum;                      /* '<S105>/Chart' */
  uint16 UnitDelay_DSTATE_k;           /* '<S154>/Unit Delay' */
  uint16 UnitDelay_DSTATE_gd;          /* '<S163>/Unit Delay' */
  uint16 UnitDelay_DSTATE_di;          /* '<S173>/Unit Delay' */
  uint16 UnitDelay_DSTATE_c;           /* '<S181>/Unit Delay' */
  uint16 Cnt2L;                        /* '<S7>/Chart' */
  uint16 Cnt4L;                        /* '<S7>/Chart' */
  uint16 Cnt6L;                        /* '<S7>/Chart' */
  boolean UnitDelay_DSTATE_au;         /* '<S187>/Unit Delay' */
  boolean UnitDelay_DSTATE_l;          /* '<S121>/Unit Delay' */
  boolean UnitDelay_DSTATE_kx;         /* '<S178>/Unit Delay' */
  boolean UnitDelay1_DSTATE_ew;        /* '<S181>/Unit Delay1' */
  boolean UnitDelay_DSTATE_de;         /* '<S120>/Unit Delay' */
  boolean UnitDelay_DSTATE_kk;         /* '<S16>/Unit Delay' */
  boolean UnitDelay_DSTATE_m;          /* '<S105>/Unit Delay' */
  boolean UnitDelay_DSTATE_in;         /* '<S19>/Unit Delay' */
  boolean UnitDelay_DSTATE_kxy;        /* '<S20>/Unit Delay' */
  uint8 is_active_c7_SWC_TPC;          /* '<S235>/PowerSaveMod_tRiseIGBT' */
  uint8 is_c7_SWC_TPC;                 /* '<S235>/PowerSaveMod_tRiseIGBT' */
  uint8 is_active_c6_SWC_TPC;          /* '<S234>/PowerSaveMod_tIGBT' */
  uint8 is_c6_SWC_TPC;                 /* '<S234>/PowerSaveMod_tIGBT' */
  uint8 is_active_c18_SWC_TPC;         /* '<S217>/PowerSaveMod_tRiseDbc' */
  uint8 is_c18_SWC_TPC;                /* '<S217>/PowerSaveMod_tRiseDbc' */
  uint8 is_active_c16_SWC_TPC;         /* '<S216>/PowerSaveMod_tDbc' */
  uint8 is_c16_SWC_TPC;                /* '<S216>/PowerSaveMod_tDbc' */
  uint8 is_active_c22_SWC_TPC;         /* '<S203>/PowerSaveMod_tCoolant' */
  uint8 is_c22_SWC_TPC;                /* '<S203>/PowerSaveMod_tCoolant' */
  uint8 is_active_c12_SWC_TPC;         /* '<S131>/PowerSaveMod_tSttr' */
  uint8 is_c12_SWC_TPC;                /* '<S131>/PowerSaveMod_tSttr' */
  uint8 is_active_c14_SWC_TPC;         /* '<S130>/PowerSaveMod_tRiseIGBT' */
  uint8 is_c14_SWC_TPC;                /* '<S130>/PowerSaveMod_tRiseIGBT' */
  uint8 is_active_c19_SWC_TPC;         /* '<S7>/Chart' */
  uint8 is_c19_SWC_TPC;                /* '<S7>/Chart' */
} DW_SWC_TPC_T;

/* Block states (default storage) */
extern DW_SWC_TPC_T SWC_TPC_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern float32 VAR_TpcTmp_tCoolantTempFlt_f32;/* '<S202>/Add3' */
extern float32 VAR_TpcTmp_CofDertTCoolantSave1_f32;
                                    /* '<S203>/CoolantTempDeratingSave1Table' */
extern float32 VAR_TpcTmp_CofDertTCoolantSave2_f32;
                                    /* '<S203>/CoolantTempDeratingSave2Table' */
extern float32 VAR_TpcTmp_CofDertTcoolant_f32;/* '<S203>/Switch1'
                                               * 冷却水温度限扭Derating系数
                                               */
extern float32 VAR_TpcTmp_tDbcMax_f32; /* '<S212>/Switch1'
                                        * 三相Dbc温度最大值
                                        */
extern float32 VAR_TpcTmp_tDbcTempFlt_f32;/* '<S209>/Add3' */
extern float32 VAR_TpcTmp_CofDertTDbcSave1_f32;/* '<S216>/DbcTempDeratingSave1Table' */
extern float32 VAR_TpcTmp_CofDertTDbcSave2_f32;/* '<S216>/DbcTempDeratingSave2Table' */
extern float32 VAR_TpcTmp_CofDertDbc_f32;/* '<S216>/Switch1' */
extern float32 VAR_TpcTmp_tRiseDbc_f32;/* '<S217>/Add' */
extern float32 VAR_TpcTmp_tRiseDbcFlt_f32;/* '<S220>/Add3' */
extern float32 VAR_TpcTmp_CofDertTRiseDbcSave1_f32;
                                    /* '<S217>/DbcRiseTempDeratingSave1Table' */
extern float32 VAR_TpcTmp_CofDertTRiseDbcSave2_f32;
                                    /* '<S217>/DbcRiseTempDeratingSave2Table' */
extern float32 VAR_TpcTmp_CofDertTRiseDbc_f32;/* '<S217>/Switch1' */
extern float32 VAR_TpcTmp_CofDertTdrvboard_f32;/* '<S228>/DrvBoardTempDeratingTable'
                                                * 驱动板温度限扭Derating系数
                                                */
extern float32 VAR_TpcTmp_tIGBTTempFlt_f32;/* '<S236>/Add3' */
extern float32 VAR_TpcTmp_CofDertTIGBTSave1_f32;/* '<S234>/IGBTTempDeratingSave1Table' */
extern float32 VAR_TpcTmp_CofDertTIGBTSave2_f32;/* '<S234>/IGBTTempDeratingSave2Table' */
extern float32 VAR_TpcTmp_CofDertIGBT_f32;/* '<S234>/Switch1' */
extern float32 VAR_TpcTmp_tRiseIGBT_f32;/* '<S235>/Add' */
extern float32 VAR_TpcTmp_tRiseIGBTFlt_f32;/* '<S241>/Add3' */
extern float32 VAR_TpcTmp_CofDertTRiseIGBTSave1_f32;
                                   /* '<S235>/IGBTRiseTempDeratingSave1Table' */
extern float32 VAR_TpcTmp_CofDertTRiseIGBTSave2_f32;
                                   /* '<S235>/IGBTRiseTempDeratingSave2Table' */
extern float32 VAR_TpcTmp_CofDertTRiseIGBT_f32;/* '<S235>/Switch1' */
extern float32 VAR_TpcMot_tSttrTempFlt_f32;/* '<S132>/Add3' */
extern float32 VAR_TpcMot_CofDertTSttrSave1_f32;/* '<S131>/SttrTempDeratingSave1Table' */
extern float32 VAR_TpcMot_CofDertTSttrSave2_f32;/* '<S131>/SttrTempDeratingSave2Table' */
extern float32 VAR_TpcMot_CofDertTsttr_f32;/* '<S131>/Switch1'
                                            * 定子温度限扭derating系数
                                            */
extern float32 VAR_TpcMot_tRiseSttr_f32;/* '<S130>/Add' */
extern float32 VAR_TpcMot_CofDertTRiseSttrSave1_f32;
                                   /* '<S130>/SttrRiseTempDeratingSave1Table' */
extern float32 VAR_TpcMot_CofDertTRiseSttrSave2_f32;
                                   /* '<S130>/SttrRiseTempDeratingSave2Table' */
extern float32 VAR_TpcMot_CofDertTRiseSttr_f32;/* '<S130>/Switch1' */
extern float32 VAR_TpcSmp_iDcLnkMax_f32;/* '<S188>/Switch2'
                                         * 限幅的电池允许最大放电电流
                                         */
extern float32 VAR_TpcSmp_cofDertOvrCurtElec_f32;/* '<S151>/BusCurrentDertElecTable'
                                                  * 母线过流线性降电动功率derating系数
                                                  */
extern float32 VAR_tpcsmp_yiDelay_f32; /* '<S155>/Unit Delay' */
extern float32 VAR_TpcSmp_ElecPwrAlowMax_f32;/* '<S152>/Divide'
                                              * 电池允许最大放电功率
                                              */
extern float32 VAR_TpcSmp_ErrElecOvrCurt_f32;/* '<S152>/Add'
                                              * 过流降电动功率PI模块差值输入
                                              */
extern float32 VAR_tpcsmp_KiProduct_f32;/* '<S155>/Product1' */
extern float32 VAR_tpcsmp_KiProductSum_f32;/* '<S155>/Add6' */
extern float32 VAR_tpcsmp_KpProduct_f32;/* '<S155>/Product' */
extern float32 VAR_tpcsmp_KpProductSau_f32;/* '<S156>/Switch2' */
extern float32 VAR_tpcsmp_PIOutput_f32;/* '<S155>/Add3' */
extern float32 VAR_tpcsmp_PwrLoss_f32; /* '<S152>/Switch1' */
extern float32 VAR_tpcsmp_AddPwrElecOvrCurt_f32;/* '<S152>/Switch' */
extern float32 VAR_tpcsmp_RefPwrElecOvrCurt_f32;/* '<S152>/Add1' */
extern float32 VAR_TpcSmp_ElecPwrPIDertOvrCurt_f32;/* '<S155>/Add7'
                                                    * 母线过流PI降电动功率
                                                    */
extern float32 VAR_TpcSmp_iDcLnkMin_f32;/* '<S189>/Switch2'
                                         * 限幅的电池允许最大充电电流
                                         */
extern float32 VAR_TpcSmp_cofDertOvrCurtGen_f32;/* '<S160>/BusCurrentDertGenTable'
                                                 * 母线过流线性降发电功率derating系数
                                                 */
extern float32 VAR_TpcSmp_GenPwrAlowMax_f32;/* '<S161>/Abs' */
extern float32 VAR_TpcSmp_ErrGenOvrCurt_f32;/* '<S161>/Add' */
extern float32 VAR_tpcsmp_PwrLossGen_f32;/* '<S161>/Switch1' */
extern float32 VAR_tpcsmp_RefPwrGenOvrCurt_f32;/* '<S161>/Add1' */
extern float32 VAR_TpcSmp_uDcLnkMax_f32;/* '<S190>/Switch2'
                                         * 限幅的电池允许最大充电电压
                                         */
extern float32 VAR_TpcSmp_cofDertOvrVoltGen_f32;/* '<S171>/BusVoltageDertGenTable'
                                                 * 母线过压线性降发电功率derating系数
                                                 */
extern float32 VAR_TpcMot_TrqGenExCOrg_f32;/* '<S116>/Negate' */
extern float32 VAR_TpcMot_TrqElecExCOrg_f32;/* '<S116>/ElecExCTable' */
extern float32 VAR_TpcMot_TrqGenExC_f32;/* '<S116>/Switch1'
                                         * 外特性限制发电扭矩
                                         */
extern float32 VAR_TpcMot_GenPwrRef_f32;/* '<S117>/Switch1'
                                         * TpcMot限扭基准发电功率
                                         */
extern float32 VAR_TpcSmp_uDcLnkMin_f32;/* '<S191>/Switch2'
                                         * 限幅的电池允许最小放电电压
                                         */
extern float32 VAR_TpcSmp_cofDertUdrVoltElec_f32;/* '<S179>/BusVoltageDertElecTable'
                                                  * 母线欠压线性降电动功率derating系数
                                                  */
extern float32 VAR_TpcMot_TrqElecExC_f32;/* '<S116>/Switch'
                                          * 外特性限制电动扭矩
                                          */
extern float32 VAR_TpcMot_ElecPwrRef_f32;/* '<S117>/Switch'
                                          * TpcMot限扭基准电动功率
                                          */
extern float32 VAR_TpcSmp_ElecPwrPIDertUdrVolt_f32;/* '<S184>/Switch2'
                                                    * 母线欠压PI降电动功率
                                                    */
extern float32 VAR_TpcCod_PowerAdd_f32;/* '<S15>/Add' */
extern float32 VAR_TpcCod_PowerIncreaseRate_f32;/* '<S15>/Divide1' */
extern float32 VAR_TpcCod_CoolantFlowFinReq_f32;/* '<S7>/Switch' */
extern float32 VAR_TpcMot_ElecTrqRef_f32;/* '<S117>/Switch2'
                                          * TpcMot模块基准电动扭矩
                                          */
extern float32 VAR_TpcMot_ElecTrqLimTsttrWoRamp_f32;/* '<S129>/Product' */
extern float32 VAR_TpcMot_ElecTrqLimTsttr_f32;/* '<S127>/Switch2'
                                               * 定子温度限扭电动扭矩
                                               */
extern float32 VAR_TpcTmp_ElecTrqLimTdbcWoRamp_f32;/* '<S215>/Product' */
extern float32 VAR_TpcTmp_ElecTrqLimTdbc_f32;/* '<S213>/Switch2'
                                              * Dbc温度限扭电动扭矩
                                              */
extern float32 VAR_TpcTmp_ElecTrqLimTcoolant_f32;/* '<S200>/Product'
                                                  * 冷却水温度限扭电动扭矩
                                                  */
extern float32 VAR_TpcTmp_ElecTrqLimTdrvboard_f32;/* '<S228>/Product'
                                                   * 驱动板温度限扭电动扭矩
                                                   */
extern float32 VAR_TpcTmp_ElecTrqLimTIGBTWoRamp_f32;/* '<S231>/Product' */
extern float32 VAR_TpcTmp_ElecTrqLimTIGBT_f32;/* '<S232>/Switch2' */
extern float32 VAR_TpcSmp_cofDertOvrSpdElecQuad1_f32;/* '<S185>/OvSpdDertQurd1Table'
                                                      * 超速限扭第一象限查表Derating系数
                                                      */
extern float32 VAR_TpcSmp_cofDertOvrSpdElecQuad3_f32;/* '<S185>/OvSpdDertQurd3Table'
                                                      * 超速限扭第三象限查表Derating系数
                                                      */
extern float32 VAR_TpcSmp_ElecTrqLimOvrSpd_f32;/* '<S185>/Product'
                                                * 超速限扭电动扭矩
                                                */
extern float32 VAR_TpcMot_GenTrqRef_f32;/* '<S117>/Switch3'
                                         * TpcMot模块基准发电扭矩
                                         */
extern float32 VAR_tpcsmp_ElecPwrDert_f32;/* '<S153>/Product' */
extern float32 VAR_TpcSmp_ElecPwrLinearDertOvrCurt_f32;/* '<S151>/Product'
                                                        * 母线过流线性降电动功率
                                                        */
extern float32 VAR_TpcSmp_ElecPwrLimOvrCurt_f32;/* '<S149>/Switch1'
                                                 * 母线过流降电动功率
                                                 */
extern float32 VAR_TpcCod_ElecTrqCalcOvrCurt_f32;/* '<S37>/Switch1'
                                                  * 过流降电动功率值计算扭矩
                                                  */
extern float32 VAR_TpcSmp_ElecPwrLinearDertUdrVolt_f32;/* '<S179>/Product'
                                                        * 母线欠压线性降电动功率
                                                        */
extern float32 VAR_TpcSmp_ElecPwrLimUdrVolt_f32;/* '<S177>/Switch1'
                                                 * 母线欠压降电动功率
                                                 */
extern float32 VAR_TpcCod_ElecTrqCalcUdrVolt_f32;/* '<S38>/Switch1'
                                                  * 欠压降电动功率值计算扭矩
                                                  */
extern float32 VAR_TpcCod_ElecTrqCalcDiag_f32;/* '<S39>/Switch1'
                                               * 故障等级降电动功率值计算扭矩
                                               */
extern float32 VAR_TpcMot_GenTrqLimTsttrWoRamp_f32;/* '<S129>/Product1' */
extern float32 VAR_TpcMot_GenTrqLimTsttr_f32;/* '<S128>/Switch2'
                                              * 定子温度限扭发电扭矩
                                              */
extern float32 VAR_TpcTmp_GenTrqLimTdbcWoRamp_f32;/* '<S215>/Product1' */
extern float32 VAR_TpcTmp_GenTrqLimTdbc_f32;/* '<S214>/Switch2'
                                             * Dbc温度限扭发电扭矩
                                             */
extern float32 VAR_TpcTmp_GenTrqLimTcoolant_f32;/* '<S200>/Product1'
                                                 * 冷却水温度限扭发电扭矩
                                                 */
extern float32 VAR_TpcTmp_GenTrqLimTdrvboard_f32;/* '<S228>/Product1'
                                                  * 驱动板温度限扭发电扭矩
                                                  */
extern float32 VAR_TpcTmp_GenTrqLimTIGBTWoRamp_f32;/* '<S231>/Product1' */
extern float32 VAR_TpcTmp_GenTrqLimTIGBT_f32;/* '<S233>/Switch2' */
extern float32 VAR_TpcSmp_cofDertOvrSpdGenQuad4_f32;/* '<S185>/OvSpdDertQurd4Table'
                                                     * 超速限扭第四象限查表Derating系数
                                                     */
extern float32 VAR_TpcSmp_cofDertOvrSpdGenQuad2_f32;/* '<S185>/OvSpdDertQurd2Table'
                                                     * 超速限扭第二象限查表Derating系数
                                                     */
extern float32 VAR_TpcSmp_GenTrqLimOvrSpd_f32;/* '<S185>/Product1'
                                               * 超速限扭发电扭矩
                                               */
extern float32 VAR_tpcsmp_GenPwrDert_f32;/* '<S162>/Product' */
extern float32 VAR_TpcSmp_GenPwrPIDertOvrCurt_f32;/* '<S164>/Gain10'
                                                   * 母线过流PI降发电功率
                                                   */
extern float32 VAR_TpcSmp_GenPwrLinearDertOvrCurt_f32;/* '<S160>/Product'
                                                       * 母线过流线性降发电功率
                                                       */
extern float32 VAR_TpcSmp_GenPwrLimOvrCurt_f32;/* '<S158>/Switch1'
                                                * 母线过流降发电功率
                                                */
extern float32 VAR_TpcCod_GenTrqCalcOvrCurt_f32;/* '<S41>/Switch1'
                                                 * 过流降发电功率值计算扭矩
                                                 */
extern float32 VAR_TpcSmp_GenPwrLinearDertOvrVolt_f32;/* '<S171>/Product'
                                                       * 母线过压线性降发电功率
                                                       */
extern float32 VAR_TpcSmp_GenPwrPIDertOvrVolt_f32;/* '<S174>/Gain6'
                                                   * 母线过压PI降发电功率
                                                   */
extern float32 VAR_TpcSmp_GenPwrLimOvrVolt_f32;/* '<S169>/Switch'
                                                * 母线过压降发电功率
                                                */
extern float32 VAR_TpcCod_GenTrqCalcOvrVolt_f32;/* '<S42>/Switch1'
                                                 * 欠压降发电功率值计算扭矩
                                                 */
extern float32 VAR_TpcCod_GenTrqCalcDiag_f32;/* '<S43>/Switch1'
                                              * 故障等级降发电功率值计算扭矩
                                              */
extern float32 VAR_TpcSmp_TrqMaxCanSet_f32;/* '<S144>/Switch'
                                            * CAN指令限扭最大扭矩
                                            */
extern float32 VAR_TpcSmp_TrqMinCanSet_f32;/* '<S144>/Switch1'
                                            * CAN指令限扭最小扭矩
                                            */
extern float32 VAR_TpcBlk_IsValid_f32; /* '<S105>/Divide' */
extern float32 VAR_Tpcblk_TrqLim_f32;  /* '<S105>/Switch2' */
extern float32 VAR_Tpcblk_TrqLim01_f32;/* '<S105>/Switch6' */
extern float32 VAR_Tpcblk_TrqMax_f32;  /* '<S105>/Switch4' */
extern float32 VAR_Tpcblk_TrqMin_f32;  /* '<S105>/Product1' */
extern float32 VAR_tpcsmp_posOutputjudge_f32;/* '<S155>/Switch2' */
extern float32 VAR_tpcsmp_negOutputjudge_f32;/* '<S155>/Switch3' */
extern float32 VAR_tpcsmp_yi_f32;      /* '<S155>/Switch' */
extern float32 VAR_TpcFuv_ElecTrqLimDiag_f32;/* '<S111>/tpcfuv_TorqLim'
                                              * 故障等级限扭电动扭矩
                                              */
extern float32 VAR_TpcFuv_GenTrqLimDiag_f32;/* '<S111>/tpcfuv_TorqLim'
                                             * 故障等级限扭发电扭矩
                                             */
extern float32 VAR_TpcFuv_ElecPwrLimDiag_f32;/* '<S111>/tpcfuv_PwrLim'
                                              * 故障等级限扭电动功率
                                              */
extern float32 VAR_TpcFuv_GenPwrLimDiag_f32;/* '<S111>/tpcfuv_PwrLim'
                                             * 故障等级限扭发电功率
                                             */
extern float32 VAR_TpcBlk_IsSum_f32;   /* '<S105>/Chart' */
extern float32 VAR_TpcCod_GenTrqLim_f32;/* '<S34>/GetMaxValue'
                                         * 发电扭矩限值
                                         */
extern float32 VAR_TpcCod_ElecTrqLim_f32;/* '<S33>/GetMinValue'
                                          * 电动扭矩限值
                                          */
extern float32 VAR_TpcCod_CoolantFlowReq_f32;/* '<S7>/Chart' */
extern sint16 VAR_TpcTmp_tCoolTempFlt_u16;/* '<S109>/Data Type Conversion' */
extern sint16 VAR_TpcTmp_TCoolStableDiff_u16;/* '<S202>/Switch2' */
extern sint16 VAR_TpcTmp_tDbcTempFlt_u16;/* '<S209>/Data Type Conversion' */
extern sint16 VAR_TpcTmp_TDbcStableDiff_u16;/* '<S209>/Switch2' */
extern sint16 VAR_TpcTmp_tDbcRiseTempFlt_u16;/* '<S220>/Data Type Conversion' */
extern sint16 VAR_TpcTmp_TDbcRiseStableDiff_u16;/* '<S220>/Switch2' */
extern sint16 VAR_TpcTmp_tIgbtTempFlt_u16;/* '<S236>/Data Type Conversion' */
extern sint16 VAR_TpcTmp_TIgbtStableDiff_u16;/* '<S236>/Switch2' */
extern sint16 VAR_TpcTmp_tIgbtRiseTempFlt_u16;/* '<S241>/Data Type Conversion' */
extern sint16 VAR_TpcTmp_TIgbtRiseStableDiff_u16;/* '<S241>/Switch2' */
//extern sint16 VAR_TpcMot_tSttrTempFlt_u16;/* '<S132>/Data Type Conversion' */
extern sint16 VAR_TpcMot_TsttrStableDiff_u16;/* '<S132>/Switch2' */
extern uint8 VAR_TpcSmp_SpdOvHiLimErrState_u8;/* '<S186>/Add3'
                                               * DEM触发状态_超速故障
                                               */
extern uint8 VAR_TpcSmp_SpdOvHiWarnState_u8;/* '<S186>/Add2'
                                             * DEM触发状态_超速报警
                                             */
extern uint8 VAR_TpcTmp_TCoolantOvHiWarnState_u8;/* '<S199>/Add'
                                                  * DEM触发状态_冷却水过温报警
                                                  */
extern uint8 VAR_TpcTmp_TDbcOvHiWarnState_u8;/* '<S210>/Add'
                                              * DEM触发状态_DBC过温报警
                                              */
extern uint8 VAR_TpcTmp_TDbcOvLoWarnState_u8;/* '<S210>/Add1'
                                              * DEM触发状态_DBC温度过低报警
                                              */
extern uint8 VAR_TpcTmp_TDbcUHiLimErrState_u8;/* '<S210>/Add2'
                                               * DEM触发状态_U相过温故障
                                               */
extern uint8 VAR_TpcTmp_TDbcULoLimErrState_u8;/* '<S210>/Add3'
                                               * DEM触发状态_U相温度过低故障
                                               */
extern uint8 VAR_TpcTmp_TDbcVHiLimErrState_u8;/* '<S210>/Add4'
                                               * DEM触发状态_V相过温故障
                                               */
extern uint8 VAR_TpcTmp_TDbcVLoLimErrState_u8;/* '<S210>/Add5'
                                               * DEM触发状态_V相温度过低故障
                                               */
extern uint8 VAR_TpcTmp_TDbcWHiLimErrState_u8;/* '<S210>/Add6'
                                               * DEM触发状态_W相过温故障
                                               */
extern uint8 VAR_TpcTmp_TDbcWLoLimErrState_u8;/* '<S210>/Add7'
                                               * DEM触发状态_W相温度过低故障
                                               */
extern uint8 VAR_TpcTmp_TDrvBoardOvHiWarnState_u8;/* '<S227>/Add'
                                                   * DEM触发状态_驱动板过温报警
                                                   */
extern uint8 VAR_TpcTmp_TIGBTOvHiErrState_u8;/* '<S230>/Add2' */
extern uint8 VAR_TpcTmp_TIGBTOvHiWarnState_u8;/* '<S230>/Add' */
extern uint8 VAR_TpcTmp_TIGBTOvLoWarnState_u8;/* '<S230>/Add1' */
extern uint8 VAR_TpcMot_TSttrOvHiLimErrState_u8;/* '<S126>/Add1'
                                                 * DEM触发状态_定子过温故障
                                                 */
extern uint8 VAR_TpcMot_TSttrOvHiWarnState_u8;/* '<S126>/Add'
                                               * DEM触发状态_定子过温报警
                                               */
extern uint8 VAR_TpcMot_TSttrOvLoWarnState_u8;/* '<S126>/Add2'
                                               * DEM触发状态_定子温度过低报警
                                               */
extern uint8 VAR_TpcSmp_iDcLnkOvCLimErrState_u8;/* '<S146>/Add1'
                                                 * DEM触发状态_过流故障
                                                 */
extern uint8 VAR_TpcSmp_iDcLnkOvcWarnState_u8;/* '<S146>/Add'
                                               * DEM触发状态_过流报警
                                               */
extern uint8 VAR_TpcSmp_uDcLnkOvVLimErrState_u8;/* '<S170>/Add1'
                                                 * DEM触发状态_过压故障
                                                 */
extern uint8 VAR_TpcSmp_uDcLnkOvWarnState_u8;/* '<S170>/Add'
                                              * DEM触发状态_过压报警
                                              */
extern uint8 VAR_TpcSmp_uDcLnkUnVLimErrState_u8;/* '<S178>/Add1'
                                                 * DEM触发状态_欠压故障
                                                 */
extern uint8 VAR_TpcSmp_uDcLnkUnvWarnState_u8;/* '<S178>/Add'
                                               * DEM触发状态_欠压报警
                                               */
extern uint8 VAR_TpcTmp_tRiseIGBTOperationMode_u8;/* '<S235>/PowerSaveMod_tRiseIGBT' */
extern uint8 VAR_TpcTmp_tIGBTOperationMode_u8;/* '<S234>/PowerSaveMod_tIGBT' */
extern uint8 VAR_TpcTmp_tRiseDbcOperationMode_u8;/* '<S217>/PowerSaveMod_tRiseDbc' */
extern uint8 VAR_TpcTmp_tDbcOperationMode_u8;/* '<S216>/PowerSaveMod_tDbc' */
extern uint8 VAR_TpcTmp_tCoolantOperationMode_u8;/* '<S203>/PowerSaveMod_tCoolant' */
extern uint8 VAR_TpcMot_tSttrOperationMode_u8;/* '<S131>/PowerSaveMod_tSttr' */
extern uint8 VAR_TpcMot_tRiseSttrOperationMode_u8;/* '<S130>/PowerSaveMod_tRiseIGBT' */
extern boolean VAR_TpcTmp_flgTrqLimTcoolantActv_b;/* '<S201>/Relational Operator'
                                                   * 冷却水温度限扭触发状态标志位
                                                   */
extern boolean VAR_TpcTmp_flgTrqLimTdbcActv_b;/* '<S211>/Relational Operator'
                                               * Dbc温度限扭触发状态标志位
                                               */
extern boolean VAR_TpcTmp_flgTrqLimTdrvboardActv_b;/* '<S229>/Relational Operator'
                                                    * 驱动板温度限扭触发状态标志位
                                                    */
extern boolean VAR_TpcTmp_flgTrqLimTIGBTActv_b;/* '<S237>/Relational Operator' */
extern boolean VAR_TpcMot_flgTrqLimTsttrActv_b;/* '<S133>/Relational Operator'
                                                * 定子温度限扭触发状态标志位
                                                */
extern boolean VAR_TpcSmp_flgLinearDertOvrCurtElec_b;/* '<S151>/Relational Operator'
                                                      * 母线过流线性降电动功率触发状态标志位
                                                      */
extern boolean VAR_TpcSmp_flgPIDertOvrCurtElec_b;/* '<S155>/Relational Operator5'
                                                  * 母线过流PI降电动功率触发状态标志位
                                                  */
extern boolean VAR_TpcSmp_flgElecPwrLimOvrCurtActv_b;/* '<S154>/Relational Operator1'
                                                      * 母线过流降电动功率触发状态标志
                                                      */
extern boolean VAR_TpcSmp_flgLinearDertOveCurtGen_b;/* '<S160>/Relational Operator'
                                                     * 母线过流线性降发电功率触发状态标志位
                                                     */
extern boolean VAR_TpcSmp_flgPIDertOvrCurtGen_b;/* '<S164>/Relational Operator5'
                                                 * 母线过流PI降发电功率触发状态标志位
                                                 */
extern boolean VAR_TpcSmp_flgGenPwrLimCurtActv_b;/* '<S163>/Relational Operator1'
                                                  * 母线过流降发电功率触发状态标志
                                                  */
extern boolean VAR_TpcSmp_flgLinearDertOvrVoltGen_b;/* '<S171>/Relational Operator'
                                                     * 母线过压线性降发电功率触发状态标志位
                                                     */
extern boolean VAR_TpcMot_flgStartExcLimRamp_b;/* '<S116>/Switch2' */
extern boolean VAR_TpcSmp_flgPIDertOvrVoltGen_b;/* '<S174>/Relational Operator5'
                                                 * 母线过压PI降发电功率触发状态标志位
                                                 */
extern boolean VAR_TpcSmp_flgGenPwrLimOvrVoltActv_b;/* '<S173>/Relational Operator1'
                                                     * 母线过压降发电功率触发状态标志
                                                     */
extern boolean VAR_TpcSmp_flgLinearDertUdrVoltElec_b;/* '<S179>/Relational Operator'
                                                      * 母线欠压线性降电动功率触发状态标志位
                                                      */
extern boolean VAR_TpcSmp_flgPIDertUdrVoltElec_b;/* '<S182>/Relational Operator5'
                                                  * 母线欠压PI降电动功率触发状态标志位
                                                  */
extern boolean VAR_TpcSmp_flgElecPwrLimUdrVoltActv_b;/* '<S177>/Logical Operator1'
                                                      * 母线欠压降电动功率触发状态标志
                                                      */
extern boolean VAR_TpcCod_flgMotorElecMode_b;/* '<S8>/Logical Operator'
                                              * 电机处于电动模式标志位
                                              */
extern boolean VAR_TpcFuv_FimTrqLimLv1_b;/* '<S112>/Logical Operator'
                                          * 一级故障限扭矩FIM状态
                                          */
extern boolean VAR_TpcFuv_FimTrqLimLv2_b;/* '<S112>/Logical Operator1'
                                          * 二级故障限扭矩FIM状态
                                          */
extern boolean VAR_TpcFuv_FimTrqLimLv3_b;/* '<S112>/Logical Operator2'
                                          * 三级故障限扭矩FIM状态
                                          */
extern boolean VAR_TpcFuv_FimTrqLimLv4_b;/* '<S112>/Logical Operator3'
                                          * 四级故障限扭矩FIM状态
                                          */
extern boolean VAR_TpcFuv_FimPwrLimLv1_b;/* '<S112>/Logical Operator4'
                                          * 一级故障限功率FIM状态
                                          */
extern boolean VAR_TpcFuv_FimPwrLimLv2_b;/* '<S112>/Logical Operator5'
                                          * 二级故障限功率FIM状态
                                          */
extern boolean VAR_TpcFuv_FimPwrLimLv3_b;/* '<S112>/Logical Operator6'
                                          * 三级故障限功率FIM状态
                                          */
extern boolean VAR_TpcFuv_FimPwrLimLv4_b;/* '<S112>/Logical Operator7'
                                          * 四级故障限功率FIM状态
                                          */
extern boolean VAR_TpcSmp_flgElecTrqLimOvrSpdActv_b;/* '<S185>/Relational Operator5'
                                                     * 超速降电动扭矩触发状态标志位
                                                     */
extern boolean VAR_TpcSmp_flgGenTrqLimOvrSpdActv_b;/* '<S185>/Relational Operator7'
                                                    * 超速降发电扭矩触发状态标志位
                                                    */
extern boolean VAR_tpccod_flgMaxDertExCTrq_b;/* '<S56>/Switch' */
extern boolean VAR_tpccod_flgMaxDertStrTemp_b;/* '<S64>/Switch1' */
extern boolean VAR_tpccod_flgMaxDertTempDBC_b;/* '<S61>/Switch2' */
extern boolean VAR_tpccod_flgMaxDertTCoolant_b;/* '<S60>/Switch3' */
extern boolean VAR_tpccod_flgMaxDertTDrvBoard_b;/* '<S62>/Switch4' */
extern boolean VAR_tpccod_flgMaxDertTIGBT_b;/* '<S63>/Switch4' */
extern boolean VAR_tpccod_flgMaxDertMtrSpd_b;/* '<S58>/Switch5' */
extern boolean VAR_tpccod_flgMaxDertOvrIdc_b;/* '<S57>/Switch6' */
extern boolean VAR_tpccod_flgMaxDertUndrUdc_b;/* '<S65>/Switch7' */
extern boolean VAR_tpccod_flgMaxDertOvrUdc_b;/* '<S59>/Switch8' */
extern boolean VAR_tpccod_flgMaxDertCAN_b;/* '<S66>/Relational Operator' */
extern boolean VAR_tpccod_flgMinDertExCTrq_b;/* '<S56>/Switch9' */
extern boolean VAR_tpccod_flgMinDertStrTemp_b;/* '<S64>/Switch10' */
extern boolean VAR_tpccod_flgMinDertTempDBC_b;/* '<S61>/Switch11' */
extern boolean VAR_tpccod_flgMinDertTCoolant_b;/* '<S60>/Switch12' */
extern boolean VAR_tpccod_flgMinDertTDrvBoard_b;/* '<S62>/Switch13' */
extern boolean VAR_tpccod_flgMinDertTIGBT_b;/* '<S63>/Switch13' */
extern boolean VAR_tpccod_flgMinDertMtrSpd_b;/* '<S58>/Switch14' */
extern boolean VAR_tpccod_flgMinDertOvrIdc_b;/* '<S57>/Switch15' */
extern boolean VAR_tpccod_flgMinDertUndrUdc_b;/* '<S65>/Switch16' */
extern boolean VAR_tpccod_flgMinDertOvrUdc_b;/* '<S59>/Switch17' */
extern boolean VAR_tpccod_flgMinDertCAN_b;/* '<S67>/Relational Operator' */

/* Exported data declaration */
#pragma section ".rodata.Calib_32"

/* Declaration for custom storage class: iEDS_Parameter */
extern const volatile uint16 CAL_TpcBlk_BlkRevTimSet_u16;
                       /* Referenced by: '<S105>/CAL_TpcBlk_BlkRevTimSet_u16' */
extern const volatile uint16 CAL_TpcBlk_BlkTimSet_u16;
                          /* Referenced by: '<S105>/CAL_TpcBlk_BlkTimSet_u16' */
extern const volatile float32 CAL_TpcBlk_MtrBlkIsFirstSet_f32;/* Referenced by:
                                                               * '<S105>/Chart'
                                                               * '<S105>/CAL_TpcBlk_MtrBlkIsFirstSet_f32'
                                                               */
extern const volatile float32 CAL_TpcBlk_MtrBlkIsSecondSet_f32;/* Referenced by:
                                                                * '<S105>/Chart'
                                                                * '<S105>/CAL_TpcBlk_MtrBlkIsSecondSet_f32'
                                                                */
extern const volatile float32 CAL_TpcBlk_MtrBlkSpdHighSet_f32;
                   /* Referenced by: '<S105>/CAL_TpcBlk_MtrBlkSpdHighSet_f32' */
extern const volatile float32 CAL_TpcBlk_MtrBlkSpdLowSet_f32;
                    /* Referenced by: '<S105>/CAL_TpcBlk_MtrBlkSpdLowSet_f32' */
extern const volatile float32 CAL_TpcBlk_TrqBlkStab_f32;
                         /* Referenced by: '<S105>/CAL_TpcBlk_TrqBlkStab_f32' */
extern const volatile float32 CAL_TpcBlk_TrqDecRamp_f32;
                         /* Referenced by: '<S105>/CAL_TpcBlk_TrqDecRamp_f32' */
extern const volatile float32 CAL_TpcBlk_TrqIncRamp_f32;
                         /* Referenced by: '<S105>/CAL_TpcBlk_TrqIncRamp_f32' */
extern const volatile boolean CAL_TpcBlk_flgEnBlkFun_b;
                          /* Referenced by: '<S105>/CAL_TpcBlk_flgEnBlkFun_b' */
extern const volatile uint16 CAL_TpcCod_CntHysteresislop_u16;/* Referenced by: '<S7>/Chart' */
extern const volatile float32 CAL_TpcCod_CoolFlow1LReq_f32;
                        /* Referenced by: '<S7>/CAL_TpcCod_CoolFlow1LReq_f32' */
extern const volatile float32 CAL_TpcCod_CoolFlow2LTableX_Udc_af32[5];/* Referenced by: '<S7>/CoolantFlow2L' */
extern const volatile float32 CAL_TpcCod_CoolFlow2LTableY_Spd_af32[8];/* Referenced by: '<S7>/CoolantFlow2L' */
extern const volatile float32 CAL_TpcCod_CoolFlow2LTableZ_Trq_af32[40];/* Referenced by: '<S7>/CoolantFlow2L' */
extern const volatile float32 CAL_TpcCod_CoolFlow4LTableX_Udc_af32[5];/* Referenced by: '<S7>/CoolantFlow4L' */
extern const volatile float32 CAL_TpcCod_CoolFlow4LTableY_Spd_af32[8];/* Referenced by: '<S7>/CoolantFlow4L' */
extern const volatile float32 CAL_TpcCod_CoolFlow4LTableZ_Trq_af32[40];/* Referenced by: '<S7>/CoolantFlow4L' */
extern const volatile float32 CAL_TpcCod_CoolFlow6LTableX_Udc_af32[5];/* Referenced by: '<S7>/CoolantFlow6L' */
extern const volatile float32 CAL_TpcCod_CoolFlow6LTableY_Spd_af32[8];/* Referenced by: '<S7>/CoolantFlow6L' */
extern const volatile float32 CAL_TpcCod_CoolFlow6LTableZ_Trq_af32[40];/* Referenced by: '<S7>/CoolantFlow6L' */
extern const volatile boolean CAL_TpcCod_FlgUseTrqLimRampSet_b;
                    /* Referenced by: '<S8>/CAL_TpcCod_FlgUseTrqLimRampSet_b' */
extern const volatile boolean CAL_TpcCod_IGBTSampErr_b;
                            /* Referenced by: '<S7>/CAL_TpcCod_IGBTSampErr_b' */
extern const volatile boolean CAL_TpcCod_MotorSampErr_b;
                           /* Referenced by: '<S7>/CAL_TpcCod_MotorSampErr_b' */
extern const volatile boolean CAL_TpcCod_MotorStallWarn_b;
                         /* Referenced by: '<S7>/CAL_TpcCod_MotorStallWarn_b' */
extern const volatile float32 CAL_TpcCod_NTCHighTemp_f32;
                         /* Referenced by: '<S16>/CAL_TpcCod_NTCHighTemp_f32' */
extern const volatile float32 CAL_TpcCod_NTCLowTemp_f32;
                          /* Referenced by: '<S16>/CAL_TpcCod_NTCLowTemp_f32' */
extern const volatile float32 CAL_TpcCod_NegSpdDirStop_f32;
                       /* Referenced by: '<S45>/CAL_TpcCod_NegSpdDirStop_f32' */

/* 电机转速判定为0阈值下限 */
extern const volatile float32 CAL_TpcCod_NegTrqDirStop_f32;
                       /* Referenced by: '<S46>/CAL_TpcCod_NegTrqDirStop_f32' */

/* 电机扭矩判定为0阈值下限 */
extern const volatile float32 CAL_TpcCod_PosSpdDirStop_f32;
                       /* Referenced by: '<S45>/CAL_TpcCod_PosSpdDirStop_f32' */

/* 电机转速判定为0阈值上限 */
extern const volatile float32 CAL_TpcCod_PosSpdHold_f32;/* Referenced by:
                                                         * '<S17>/Chart'
                                                         * '<S18>/Chart'
                                                         * '<S24>/CAL_TpcCod_PosSpdHold_f32'
                                                         * '<S26>/CAL_TpcCod_PosSpdHold_f32'
                                                         */

/* 扭矩限值Mapping的转速阈值下限 */
extern const volatile float32 CAL_TpcCod_PosSpdStart_f32;/* Referenced by:
                                                          * '<S17>/Chart'
                                                          * '<S18>/Chart'
                                                          * '<S24>/CAL_TpcCod_PosSpdStart_f32'
                                                          * '<S26>/CAL_TpcCod_PosSpdStart_f32'
                                                          */

/* 扭矩限值Mapping的转速阈值上限 */
extern const volatile float32 CAL_TpcCod_PosTrqDirStop_f32;
                       /* Referenced by: '<S46>/CAL_TpcCod_PosTrqDirStop_f32' */

/* 电机扭矩判定为0阈值上限 */
extern const volatile float32 CAL_TpcCod_PowIncRatLim_f32;/* Referenced by: '<S7>/Chart' */
extern const volatile float32 CAL_TpcCod_TrqRelay_f32;/* Referenced by: '<S7>/Chart' */
extern const volatile float32 CAL_TpcFuv_CofPwrLimLv1_f32;
                       /* Referenced by: '<S111>/CAL_TpcFuv_CofPwrLimLv1_f32' */

/* 一级故障功率限值系数 */
extern const volatile float32 CAL_TpcFuv_CofPwrLimLv2_f32;
                       /* Referenced by: '<S111>/CAL_TpcFuv_CofPwrLimLv2_f32' */

/* 二级故障功率限值系数 */
extern const volatile float32 CAL_TpcFuv_CofPwrLimLv3_f32;
                       /* Referenced by: '<S111>/CAL_TpcFuv_CofPwrLimLv3_f32' */

/* 三级故障功率限值系数 */
extern const volatile float32 CAL_TpcFuv_CofPwrLimLv4_f32;
                       /* Referenced by: '<S111>/CAL_TpcFuv_CofPwrLimLv4_f32' */

/* 四级故障功率限值系数 */
extern const volatile float32 CAL_TpcFuv_CofTrqLimLv1_f32;
                       /* Referenced by: '<S111>/CAL_TpcFuv_CofTrqLimLv1_f32' */

/* 一级故障扭矩限值系数 */
extern const volatile float32 CAL_TpcFuv_CofTrqLimLv2_f32;
                       /* Referenced by: '<S111>/CAL_TpcFuv_CofTrqLimLv2_f32' */

/* 二级故障扭矩限值系数 */
extern const volatile float32 CAL_TpcFuv_CofTrqLimLv3_f32;
                       /* Referenced by: '<S111>/CAL_TpcFuv_CofTrqLimLv3_f32' */

/* 三级故障扭矩限值系数 */
extern const volatile float32 CAL_TpcFuv_CofTrqLimLv4_f32;
                       /* Referenced by: '<S111>/CAL_TpcFuv_CofTrqLimLv4_f32' */

/* 四级故障扭矩限值系数 */
extern const volatile float32 CAL_TpcMot_ExCElecTableX_Udc_af32[10];
                                      /* Referenced by: '<S116>/ElecExCTable' */

/* 外特性查表母线电压输入-电动模式 */
extern const volatile float32 CAL_TpcMot_ExCElecTableY_Spd_af32[17];
                                      /* Referenced by: '<S116>/ElecExCTable' */

/* 外特性查表电机转速输入-电动模式 */
extern const volatile float32 CAL_TpcMot_ExCElecTableZ_Trq_af32[170];
                                      /* Referenced by: '<S116>/ElecExCTable' */

/* 外特性查表扭矩输出-电动模式 */
extern const volatile float32 CAL_TpcMot_ExCGenTableX_Udc_af32[10];/* Referenced by: '<S116>/GenExCTable' */

/* 外特性查表母线电压输入-发电模式 */
extern const volatile float32 CAL_TpcMot_ExCGenTableY_Spd_af32[17];/* Referenced by: '<S116>/GenExCTable' */

/* 外特性查表电机转速输入-发电模式 */
extern const volatile float32 CAL_TpcMot_ExCGenTableZ_Trq_af32[170];/* Referenced by: '<S116>/GenExCTable' */

/* 外特性查表扭矩输出-发电模式 */
extern const volatile float32 CAL_TpcMot_SttrChgTempDownDiff_f32;/* Referenced by: '<S139>/Constant' */
extern const volatile float32 CAL_TpcMot_SttrChgTempUpDiff_f32;/* Referenced by: '<S138>/Constant' */
extern const volatile float32 CAL_TpcMot_SttrTempAdds_f32;
                       /* Referenced by: '<S119>/CAL_TpcMot_SttrTempAdds_f32' */
extern const volatile float32 CAL_TpcMot_SttrTempDecDiff_f32;
                    /* Referenced by: '<S119>/CAL_TpcMot_SttrTempDecDiff_f32' */

/* 定子温度下降步长 */
extern const volatile float32 CAL_TpcMot_SttrTempKp_f32;
                         /* Referenced by: '<S119>/CAL_TpcMot_SttrTempKp_f32' */
extern const volatile float32 CAL_TpcMot_SttrTempMinus_f32;
                      /* Referenced by: '<S119>/CAL_TpcMot_SttrTempMinus_f32' */
extern const volatile float32 CAL_TpcMot_SttrTempRiseDiff_f32;
                   /* Referenced by: '<S119>/CAL_TpcMot_SttrTempRiseDiff_f32' */
extern const volatile boolean CAL_TpcMot_flgPwrRefSwt_b;
                         /* Referenced by: '<S117>/CAL_TpcMot_flgPwrRefSwt_b' */

/* 使用外特性功率标志-tpcmot */
extern const volatile boolean CAL_TpcMot_flgTrqRefSwt_b;
                         /* Referenced by: '<S117>/CAL_TpcMot_flgTrqRefSwt_b' */

/* 使用外特性扭矩标志-tpcmot */
extern const volatile float32 CAL_TpcMot_tRiseSttrDertSave1TableX_tSttr_af32[9];
                    /* Referenced by: '<S130>/SttrRiseTempDeratingSave1Table' */
extern const volatile float32 CAL_TpcMot_tRiseSttrDertSave1TableY_Cof_af32[9];
                    /* Referenced by: '<S130>/SttrRiseTempDeratingSave1Table' */
extern const volatile float32 CAL_TpcMot_tRiseSttrDertSave2TableX_tSttr_af32[9];
                    /* Referenced by: '<S130>/SttrRiseTempDeratingSave2Table' */
extern const volatile float32 CAL_TpcMot_tRiseSttrDertSave2TableY_Cof_af32[9];
                    /* Referenced by: '<S130>/SttrRiseTempDeratingSave2Table' */
extern const volatile float32 CAL_TpcMot_tRiseSttrTraNormalToSave1_f32;
                            /* Referenced by: '<S130>/PowerSaveMod_tRiseIGBT' */
extern const volatile float32 CAL_TpcMot_tRiseSttrTraSave1ToNormal_f32;
                            /* Referenced by: '<S130>/PowerSaveMod_tRiseIGBT' */
extern const volatile float32 CAL_TpcMot_tRiseSttrTraSave1ToSave2_f32;
                            /* Referenced by: '<S130>/PowerSaveMod_tRiseIGBT' */
extern const volatile float32 CAL_TpcMot_tRiseSttrTraSave2ToOverheating_f32;
                            /* Referenced by: '<S130>/PowerSaveMod_tRiseIGBT' */
extern const volatile float32 CAL_TpcMot_tSttrDertSave1TableX_tSttr_af32[9];
                        /* Referenced by: '<S131>/SttrTempDeratingSave1Table' */
extern const volatile float32 CAL_TpcMot_tSttrDertSave1TableY_Cof_af32[9];
                        /* Referenced by: '<S131>/SttrTempDeratingSave1Table' */
extern const volatile float32 CAL_TpcMot_tSttrDertSave2TableX_tSttr_af32[9];
                        /* Referenced by: '<S131>/SttrTempDeratingSave2Table' */
extern const volatile float32 CAL_TpcMot_tSttrDertSave2TableY_Cof_af32[9];
                        /* Referenced by: '<S131>/SttrTempDeratingSave2Table' */
extern const volatile float32 CAL_TpcMot_tSttrHiLim_f32;
                         /* Referenced by: '<S126>/CAL_TpcMot_tSttrHiLim_f32' */

/* 定子温度过高故障阈值 */
extern const volatile float32 CAL_TpcMot_tSttrLoLim_f32;
                         /* Referenced by: '<S126>/CAL_TpcMot_tSttrLoLim_f32' */

/* 定子温度过低报警阈值 */
extern const volatile float32 CAL_TpcMot_tSttrTraNormalToSave1_f32;
                                /* Referenced by: '<S131>/PowerSaveMod_tSttr' */
extern const volatile float32 CAL_TpcMot_tSttrTraSave1ToNormal_f32;
                                /* Referenced by: '<S131>/PowerSaveMod_tSttr' */
extern const volatile float32 CAL_TpcMot_tSttrTraSave1ToSave2_f32;
                                /* Referenced by: '<S131>/PowerSaveMod_tSttr' */
extern const volatile float32 CAL_TpcMot_tSttrTraSave2ToOverheating_f32;
                                /* Referenced by: '<S131>/PowerSaveMod_tSttr' */
extern const volatile float32 CAL_TpcMot_tSttrTrqLimRamp_f32;/* Referenced by:
                                                              * '<S119>/CAL_TpcMot_tSttrTrqLimRamp_f1'
                                                              * '<S119>/CAL_TpcMot_tSttrTrqLimRamp_f32'
                                                              */

/* 定子温度扭矩限值slop */
extern const volatile uint8 CAL_TpcSmp_CntElecOvrCurt_u8;
                      /* Referenced by: '<S149>/CAL_TpcSmp_CntElecOvrCurt_u8' */

/* 电动过流derating触发标志Debounce模块计数 */
extern const volatile uint8 CAL_TpcSmp_CntElecUdrVolt_u8;
                      /* Referenced by: '<S177>/CAL_TpcSmp_CntElecUdrVolt_u8' */

/* 电动欠压derating触发标志Debounce模块计数 */
extern const volatile uint8 CAL_TpcSmp_CntGenOvrCurt_u8;
                       /* Referenced by: '<S158>/CAL_TpcSmp_CntGenOvrCurt_u8' */

/* 发电过流derating触发标志Debounce模块计数 */
extern const volatile uint8 CAL_TpcSmp_CntGenOvrVolt_u8;
                       /* Referenced by: '<S169>/CAL_TpcSmp_CntGenOvrVolt_u8' */

/* 发电过压derating触发标志Debounce模块计数 */
extern const volatile boolean CAL_TpcSmp_CurtModeSelc_b;/* Referenced by:
                                                         * '<S149>/CAL_TpcSmp_CurtModeSelc_b'
                                                         * '<S158>/CAL_TpcSmp_CurtModeSelc_b'
                                                         */
extern const volatile float32 CAL_TpcSmp_ElecOvrCurtKi_f32;
                      /* Referenced by: '<S152>/CAL_TpcSmp_ElecOvrCurtKi_f32' */

/* 电动过流限功率PI模块Ki */
extern const volatile float32 CAL_TpcSmp_ElecOvrCurtKp_f32;
                      /* Referenced by: '<S152>/CAL_TpcSmp_ElecOvrCurtKp_f32' */

/* 电动过流限功率PI模块Kp */
extern const volatile float32 CAL_TpcSmp_ElecOvrCurtypLim_f32;
                   /* Referenced by: '<S152>/CAL_TpcSmp_ElecOvrCurtypLim_f32' */

/* 电动过流限功率PI模块限幅 */
extern const volatile float32 CAL_TpcSmp_ElecUdrVoltKi_f32;
                      /* Referenced by: '<S180>/CAL_TpcSmp_ElecUdrVoltKi_f32' */

/* 电动欠压限功率PI模块Ki */
extern const volatile float32 CAL_TpcSmp_ElecUdrVoltKp_f32;
                      /* Referenced by: '<S180>/CAL_TpcSmp_ElecUdrVoltKp_f32' */

/* 电动欠压限功率PI模块Kp */
extern const volatile float32 CAL_TpcSmp_ElecUdrVoltypLim_f32;
                   /* Referenced by: '<S180>/CAL_TpcSmp_ElecUdrVoltypLim_f32' */

/* 电动欠压限功率PI模块限幅 */
extern const volatile uint8 CAL_TpcSmp_FacElecOvrCurt_u8;
                      /* Referenced by: '<S149>/CAL_TpcSmp_FacElecOvrCurt_u8' */

/* 电动过流derating触发标志Debounce模块系数 */
extern const volatile uint8 CAL_TpcSmp_FacElecUdrVolt_u8;
                      /* Referenced by: '<S177>/CAL_TpcSmp_FacElecUdrVolt_u8' */

/* 电动欠压derating触发标志Debounce模块系数 */
extern const volatile uint8 CAL_TpcSmp_FacGenOvrCurt_u8;
                       /* Referenced by: '<S158>/CAL_TpcSmp_FacGenOvrCurt_u8' */

/* 发电过流derating触发标志Debounce模块系数 */
extern const volatile uint8 CAL_TpcSmp_FacGenOvrVolt_u8;
                       /* Referenced by: '<S169>/CAL_TpcSmp_FacGenOvrVolt_u8' */

/* 发电过压derating触发标志Debounce模块系数 */
extern const volatile float32 CAL_TpcSmp_GenOvrCurtKi_f32;
                       /* Referenced by: '<S161>/CAL_TpcSmp_GenOvrCurtKi_f32' */

/* 发电过流限功率PI模块Ki */
extern const volatile float32 CAL_TpcSmp_GenOvrCurtKp_f32;
                       /* Referenced by: '<S161>/CAL_TpcSmp_GenOvrCurtKp_f32' */

/* 发电过流限功率PI模块Kp */
extern const volatile float32 CAL_TpcSmp_GenOvrCurtypLim_f32;
                    /* Referenced by: '<S161>/CAL_TpcSmp_GenOvrCurtypLim_f32' */

/* 发电过流限功率PI模块限幅 */
extern const volatile float32 CAL_TpcSmp_GenOvrVoltKi_f32;
                       /* Referenced by: '<S172>/CAL_TpcSmp_GenOvrVoltKi_f32' */

/* 发电过压限功率PI模块Ki */
extern const volatile float32 CAL_TpcSmp_GenOvrVoltKp_f32;
                       /* Referenced by: '<S172>/CAL_TpcSmp_GenOvrVoltKp_f32' */

/* 发电过压限功率PI模块Kp */
extern const volatile float32 CAL_TpcSmp_GenOvrVoltypLim_f32;
                    /* Referenced by: '<S172>/CAL_TpcSmp_GenOvrVoltypLim_f32' */

/* 发电过压限功率PI模块限幅 */
extern const volatile float32 CAL_TpcSmp_OvSpdWarnHiLim_f32;
                     /* Referenced by: '<S186>/CAL_TpcSmp_OvSpdWarnHiLim_f32' */

/* 电机转速超速报警触发阈值 */
extern const volatile float32 CAL_TpcSmp_OvSpdWarnLoLim_f32;
                     /* Referenced by: '<S186>/CAL_TpcSmp_OvSpdWarnLoLim_f32' */

/* 电机转速超速报警恢复阈值 */
extern const volatile float32 CAL_TpcSmp_OvrCurtLimElecTableX_iDc_af32[5];
                           /* Referenced by: '<S151>/BusCurrentDertElecTable' */

/* 电动过流线性降功率查表电流输入 */
extern const volatile float32 CAL_TpcSmp_OvrCurtLimElecTableY_Cof_af32[5];
                           /* Referenced by: '<S151>/BusCurrentDertElecTable' */

/* 电动过流线性降功率查表derating系数输出 */
extern const volatile float32 CAL_TpcSmp_OvrCurtLimGenTableX_iDc_af32[5];
                            /* Referenced by: '<S160>/BusCurrentDertGenTable' */

/* 发电过流线性降功率查表电流输入 */
extern const volatile float32 CAL_TpcSmp_OvrCurtLimGenTableY_Cof_af32[5];
                            /* Referenced by: '<S160>/BusCurrentDertGenTable' */

/* 发电过流线性降功率查表derating系数输出 */
extern const volatile float32 CAL_TpcSmp_OvrSpdQurd1TableX_Spd_af32[7];
                               /* Referenced by: '<S185>/OvSpdDertQurd1Table' */

/* 超速限扭转速输入_第一象限 */
extern const volatile float32 CAL_TpcSmp_OvrSpdQurd1TableY_Cof_af32[7];
                               /* Referenced by: '<S185>/OvSpdDertQurd1Table' */

/* 超速限扭系数输出_第一象限 */
extern const volatile float32 CAL_TpcSmp_OvrSpdQurd2TableX_Spd_af32[7];
                               /* Referenced by: '<S185>/OvSpdDertQurd2Table' */

/* 超速限扭转速输入_第二象限 */
extern const volatile float32 CAL_TpcSmp_OvrSpdQurd2TableY_Cof_af32[7];
                               /* Referenced by: '<S185>/OvSpdDertQurd2Table' */

/* 超速限扭系数输出_第二象限 */
extern const volatile float32 CAL_TpcSmp_OvrSpdQurd3TableX_Spd_af32[7];
                               /* Referenced by: '<S185>/OvSpdDertQurd3Table' */

/* 超速限扭转速输入_第三象限 */
extern const volatile float32 CAL_TpcSmp_OvrSpdQurd3TableY_Cof_af32[7];
                               /* Referenced by: '<S185>/OvSpdDertQurd3Table' */

/* 超速限扭系数输出_第三象限 */
extern const volatile float32 CAL_TpcSmp_OvrSpdQurd4TableX_Spd_af32[7];
                               /* Referenced by: '<S185>/OvSpdDertQurd4Table' */

/* 超速限扭转速输入_第四象限 */
extern const volatile float32 CAL_TpcSmp_OvrSpdQurd4TableY_Cof_af32[7];
                               /* Referenced by: '<S185>/OvSpdDertQurd4Table' */

/* 超速限扭系数输出_第四象限 */
extern const volatile float32 CAL_TpcSmp_OvrVoltGenTableX_uDc_af32[5];
                            /* Referenced by: '<S171>/BusVoltageDertGenTable' */

/* 过压线性降功率查表电压输入 */
extern const volatile float32 CAL_TpcSmp_OvrVoltGenTableY_Cof_af32[5];
                            /* Referenced by: '<S171>/BusVoltageDertGenTable' */

/* 过压线性降功率查表derating系数输出 */
extern const volatile float32 CAL_TpcSmp_PwrAddMaxGen_f32;
                       /* Referenced by: '<S161>/CAL_TpcSmp_PwrAddMaxGen_f32' */
extern const volatile float32 CAL_TpcSmp_PwrAddMax_f32;
                          /* Referenced by: '<S152>/CAL_TpcSmp_PwrAddMax_f32' */

/* 电动过流测试补偿功率 */
extern const volatile float32 CAL_TpcSmp_SystemEffiElec_f32;
                     /* Referenced by: '<S153>/CAL_TpcSmp_SystemEffiElec_f32' */
extern const volatile float32 CAL_TpcSmp_SystemEffiGen_f32;
                      /* Referenced by: '<S162>/CAL_TpcSmp_SystemEffiGen_f32' */
extern const volatile float32 CAL_TpcSmp_ThresOverSpd_f32;
                       /* Referenced by: '<S186>/CAL_TpcSmp_ThresOverSpd_f32' */

/* 电机转速超速故障阈值 */
extern const volatile float32 CAL_TpcSmp_TrqAddMaxGen_f32;
                       /* Referenced by: '<S161>/CAL_TpcSmp_TrqAddMaxGen_f32' */
extern const volatile float32 CAL_TpcSmp_TrqAddMax_f32;
                          /* Referenced by: '<S152>/CAL_TpcSmp_TrqAddMax_f32' */

/* 电动过流测试补偿扭矩 */
extern const volatile float32 CAL_TpcSmp_UdrVoltElecTableX_uDc_af32[5];
                           /* Referenced by: '<S179>/BusVoltageDertElecTable' */

/* 欠压线性降功率查表电压输入 */
extern const volatile float32 CAL_TpcSmp_UdrVoltElecTableY_Cof_af32[5];
                           /* Referenced by: '<S179>/BusVoltageDertElecTable' */

/* 欠压线性降功率查表derating系数输出 */
extern const volatile boolean CAL_TpcSmp_flgUsePwrLossGen_b;
                     /* Referenced by: '<S161>/CAL_TpcSmp_flgUsePwrLossGen_b' */
extern const volatile boolean CAL_TpcSmp_flgUsePwrLoss_b;
                        /* Referenced by: '<S152>/CAL_TpcSmp_flgUsePwrLoss_b' */
extern const volatile float32 CAL_TpcSmp_iDcLnkMaxMax_f32;
                       /* Referenced by: '<S143>/CAL_TpcSmp_iDcLnkMaxMax_f32' */

/* 电池允许最大电流最大值 */
extern const volatile float32 CAL_TpcSmp_iDcLnkMaxMin_f32;
                       /* Referenced by: '<S143>/CAL_TpcSmp_iDcLnkMaxMin_f32' */

/* 电池允许最大电流最小值 */
extern const volatile float32 CAL_TpcSmp_iDcLnkMinMax_f32;
                       /* Referenced by: '<S143>/CAL_TpcSmp_iDcLnkMinMax_f32' */

/* 电池允许最小电流最大值 */
extern const volatile float32 CAL_TpcSmp_iDcLnkMinMin_f32;
                       /* Referenced by: '<S143>/CAL_TpcSmp_iDcLnkMinMin_f32' */

/* 电池允许最小电流最小值 */
extern const volatile float32 CAL_TpcSmp_iDcLnkOvCElecLim_f32;
                   /* Referenced by: '<S146>/CAL_TpcSmp_iDcLnkOvCElecLim_f32' */

/* 母线电流电动过流故障阈值 */
extern const volatile float32 CAL_TpcSmp_iDcLnkOvCGenLim_f32;
                    /* Referenced by: '<S146>/CAL_TpcSmp_iDcLnkOvCGenLim_f32' */

/* 母线电流发电过流故障阈值 */
extern const volatile uint8 CAL_TpcSmp_nCtlExtReq_u8;/* Referenced by: '<S192>/Constant' */

/* VCU请求外部速度环控制 */
extern const volatile uint8 CAL_TpcSmp_nCtlIntReq_u8;/* Referenced by: '<S193>/Constant' */

/* VCU请求内部速度环控制 */
extern const volatile float32 CAL_TpcSmp_uDcLnkMaxMax_f32;
                       /* Referenced by: '<S143>/CAL_TpcSmp_uDcLnkMaxMax_f32' */

/* 电池允许最大电压最大值 */
extern const volatile float32 CAL_TpcSmp_uDcLnkMaxMin_f32;
                       /* Referenced by: '<S143>/CAL_TpcSmp_uDcLnkMaxMin_f32' */

/* 电池允许最大电压最小值 */
extern const volatile float32 CAL_TpcSmp_uDcLnkMinMax_f32;
                       /* Referenced by: '<S143>/CAL_TpcSmp_uDcLnkMinMax_f32' */

/* 电池允许最小电压最大值 */
extern const volatile float32 CAL_TpcSmp_uDcLnkMinMin_f32;
                       /* Referenced by: '<S143>/CAL_TpcSmp_uDcLnkMinMin_f32' */

/* 电池允许最小电压最小值 */
extern const volatile float32 CAL_TpcSmp_uDcLnkOvVLim_f32;
                       /* Referenced by: '<S170>/CAL_TpcSmp_uDcLnkOvVLim_f32' */

/* 母线电压过压故障阈值 */
extern const volatile float32 CAL_TpcSmp_uDcLnkUnVLim_f32;
                       /* Referenced by: '<S178>/CAL_TpcSmp_uDcLnkUnVLim_f32' */

/* 母线电压欠压故障阈值 */
extern const volatile float32 CAL_TpcTmp_CoolChgTempDownDiff_f32;/* Referenced by: '<S205>/Constant' */
extern const volatile float32 CAL_TpcTmp_CoolChgTempUpDiff_f32;/* Referenced by: '<S204>/Constant' */
extern const volatile float32 CAL_TpcTmp_CoolTempAdds_f32;
                       /* Referenced by: '<S200>/CAL_TpcTmp_CoolTempAdds_f32' */
extern const volatile float32 CAL_TpcTmp_CoolTempDecDiff_f32;
                    /* Referenced by: '<S200>/CAL_TpcTmp_CoolTempDecDiff_f32' */
extern const volatile float32 CAL_TpcTmp_CoolTempKp_f32;
                         /* Referenced by: '<S200>/CAL_TpcTmp_CoolTempKp_f32' */
extern const volatile float32 CAL_TpcTmp_CoolTempMinus_f32;
                      /* Referenced by: '<S200>/CAL_TpcTmp_CoolTempMinus_f32' */
extern const volatile float32 CAL_TpcTmp_CoolTempRiseDiff_f32;
                   /* Referenced by: '<S200>/CAL_TpcTmp_CoolTempRiseDiff_f32' */
extern const volatile float32 CAL_TpcTmp_DBCRiseTempAdds_f32;
                    /* Referenced by: '<S217>/CAL_TpcTmp_DBCRiseTempAdds_f32' */
extern const volatile float32 CAL_TpcTmp_DBCRiseTempDecDiff_f32;
                 /* Referenced by: '<S217>/CAL_TpcTmp_DBCRiseTempDecDiff_f32' */
extern const volatile float32 CAL_TpcTmp_DBCRiseTempKp_f32;
                      /* Referenced by: '<S217>/CAL_TpcTmp_DBCRiseTempKp_f32' */
extern const volatile float32 CAL_TpcTmp_DBCRiseTempMinus_f32;
                   /* Referenced by: '<S217>/CAL_TpcTmp_DBCRiseTempMinus_f32' */
extern const volatile float32 CAL_TpcTmp_DBCRiseTempRiseDiff_f32;
                /* Referenced by: '<S217>/CAL_TpcTmp_DBCRiseTempRiseDiff_f32' */
extern const volatile float32 CAL_TpcTmp_DBCTempAdds_f32;
                        /* Referenced by: '<S195>/CAL_TpcTmp_DBCTempAdds_f32' */
extern const volatile float32 CAL_TpcTmp_DBCTempDecDiff_f32;
                     /* Referenced by: '<S195>/CAL_TpcTmp_DBCTempDecDiff_f32' */
extern const volatile float32 CAL_TpcTmp_DBCTempKp_f32;
                          /* Referenced by: '<S195>/CAL_TpcTmp_DBCTempKp_f32' */
extern const volatile float32 CAL_TpcTmp_DBCTempMinus_f32;
                       /* Referenced by: '<S195>/CAL_TpcTmp_DBCTempMinus_f32' */
extern const volatile float32 CAL_TpcTmp_DBCTempRiseDiff_f32;
                    /* Referenced by: '<S195>/CAL_TpcTmp_DBCTempRiseDiff_f32' */
extern const volatile float32 CAL_TpcTmp_DbcChgTempDownDiff_f32;/* Referenced by: '<S226>/Constant' */
extern const volatile float32 CAL_TpcTmp_DbcChgTempUpDiff_f32;/* Referenced by: '<S225>/Constant' */
extern const volatile float32 CAL_TpcTmp_DbcRiseChgTempDownDiff_f32;/* Referenced by: '<S224>/Constant' */
extern const volatile float32 CAL_TpcTmp_DbcRiseChgTempUpDiff_f32;/* Referenced by: '<S223>/Constant' */
extern const volatile float32 CAL_TpcTmp_IGBRiseTTempAdds_f32;
                   /* Referenced by: '<S235>/CAL_TpcTmp_IGBRiseTTempAdds_f32' */
extern const volatile float32 CAL_TpcTmp_IGBTRiseTempDecDiff_f32;
                /* Referenced by: '<S235>/CAL_TpcTmp_IGBTRiseTempDecDiff_f32' */
extern const volatile float32 CAL_TpcTmp_IGBTRiseTempKp_f32;
                     /* Referenced by: '<S235>/CAL_TpcTmp_IGBTRiseTempKp_f32' */
extern const volatile float32 CAL_TpcTmp_IGBTRiseTempMinus_f32;
                  /* Referenced by: '<S235>/CAL_TpcTmp_IGBTRiseTempMinus_f32' */
extern const volatile float32 CAL_TpcTmp_IGBTRiseTempRiseDiff_f32;
               /* Referenced by: '<S235>/CAL_TpcTmp_IGBTRiseTempRiseDiff_f32' */
extern const volatile float32 CAL_TpcTmp_IGBTTempAdds_f32;
                       /* Referenced by: '<S197>/CAL_TpcTmp_IGBTTempAdds_f32' */
extern const volatile float32 CAL_TpcTmp_IGBTTempDecDiff_f32;
                    /* Referenced by: '<S197>/CAL_TpcTmp_IGBTTempDecDiff_f32' */
extern const volatile float32 CAL_TpcTmp_IGBTTempKp_f32;
                         /* Referenced by: '<S197>/CAL_TpcTmp_IGBTTempKp_f32' */
extern const volatile float32 CAL_TpcTmp_IGBTTempMinus_f32;
                      /* Referenced by: '<S197>/CAL_TpcTmp_IGBTTempMinus_f32' */
extern const volatile float32 CAL_TpcTmp_IGBTTempRiseDiff_f32;
                   /* Referenced by: '<S197>/CAL_TpcTmp_IGBTTempRiseDiff_f32' */
extern const volatile float32 CAL_TpcTmp_IgbtChgTempDownDiff_f32;/* Referenced by: '<S246>/Constant' */
extern const volatile float32 CAL_TpcTmp_IgbtChgTempUpDiff_f32;/* Referenced by: '<S245>/Constant' */
extern const volatile float32 CAL_TpcTmp_IgbtRiseChgTempDownDiff_f32;/* Referenced by: '<S244>/Constant' */
extern const volatile float32 CAL_TpcTmp_IgbtRiseChgTempUpDiff_f32;/* Referenced by: '<S243>/Constant' */
extern const volatile float32 CAL_TpcTmp_tCoolantDertSave1TableX_tSttr_af32[9];
                     /* Referenced by: '<S203>/CoolantTempDeratingSave1Table' */
extern const volatile float32 CAL_TpcTmp_tCoolantDertSave1TableY_Cof_af32[9];
                     /* Referenced by: '<S203>/CoolantTempDeratingSave1Table' */
extern const volatile float32 CAL_TpcTmp_tCoolantDertSave2TableX_tSttr_af32[9];
                     /* Referenced by: '<S203>/CoolantTempDeratingSave2Table' */
extern const volatile float32 CAL_TpcTmp_tCoolantDertSave2TableY_Cof_af32[9];
                     /* Referenced by: '<S203>/CoolantTempDeratingSave2Table' */
extern const volatile float32 CAL_TpcTmp_tCoolantTraNormalToSave1_f32;
                             /* Referenced by: '<S203>/PowerSaveMod_tCoolant' */
extern const volatile float32 CAL_TpcTmp_tCoolantTraSave1ToNormal_f32;
                             /* Referenced by: '<S203>/PowerSaveMod_tCoolant' */
extern const volatile float32 CAL_TpcTmp_tCoolantTraSave1ToSave2_f32;
                             /* Referenced by: '<S203>/PowerSaveMod_tCoolant' */
extern const volatile float32 CAL_TpcTmp_tCoolantTraSave2ToOverheating_f32;
                             /* Referenced by: '<S203>/PowerSaveMod_tCoolant' */
extern const volatile float32 CAL_TpcTmp_tDBCTrqLimRamp_f32;/* Referenced by:
                                                             * '<S195>/CAL_TpcTmp_tDBCTrqLimRamp_f1'
                                                             * '<S195>/CAL_TpcTmp_tDBCTrqLimRamp_f32'
                                                             */
extern const volatile float32 CAL_TpcTmp_tDbcDertSave1TableX_tSttr_af32[9];
                         /* Referenced by: '<S216>/DbcTempDeratingSave1Table' */
extern const volatile float32 CAL_TpcTmp_tDbcDertSave1TableY_Cof_af32[9];
                         /* Referenced by: '<S216>/DbcTempDeratingSave1Table' */
extern const volatile float32 CAL_TpcTmp_tDbcDertSave2TableX_tSttr_af32[9];
                         /* Referenced by: '<S216>/DbcTempDeratingSave2Table' */
extern const volatile float32 CAL_TpcTmp_tDbcDertSave2TableY_Cof_af32[9];
                         /* Referenced by: '<S216>/DbcTempDeratingSave2Table' */
extern const volatile float32 CAL_TpcTmp_tDbcTempUHiLim_f32;
                     /* Referenced by: '<S210>/CAL_TpcTmp_tDbcTempUHiLim_f32' */

/* U相温度超高限 */
extern const volatile float32 CAL_TpcTmp_tDbcTempULoLim_f32;
                     /* Referenced by: '<S210>/CAL_TpcTmp_tDbcTempULoLim_f32' */

/* U相温度超低限 */
extern const volatile float32 CAL_TpcTmp_tDbcTempVHiLim_f32;
                     /* Referenced by: '<S210>/CAL_TpcTmp_tDbcTempVHiLim_f32' */

/* V相温度超高限 */
extern const volatile float32 CAL_TpcTmp_tDbcTempVLoLim_f32;
                     /* Referenced by: '<S210>/CAL_TpcTmp_tDbcTempVLoLim_f32' */

/* V相温度超低限 */
extern const volatile float32 CAL_TpcTmp_tDbcTempWHiLim_f32;
                     /* Referenced by: '<S210>/CAL_TpcTmp_tDbcTempWHiLim_f32' */

/* W相温度超高限 */
extern const volatile float32 CAL_TpcTmp_tDbcTempWLoLim_f32;
                     /* Referenced by: '<S210>/CAL_TpcTmp_tDbcTempWLoLim_f32' */

/* W相温度超低限 */
extern const volatile float32 CAL_TpcTmp_tDbcThrPhLoLim_f32;
                     /* Referenced by: '<S210>/CAL_TpcTmp_tDbcThrPhLoLim_f32' */

/* DBC温度过低报警阈值 */
extern const volatile float32 CAL_TpcTmp_tDbcTraNormalToSave1_f32;
                                 /* Referenced by: '<S216>/PowerSaveMod_tDbc' */
extern const volatile float32 CAL_TpcTmp_tDbcTraSave1ToNormal_f32;
                                 /* Referenced by: '<S216>/PowerSaveMod_tDbc' */
extern const volatile float32 CAL_TpcTmp_tDbcTraSave1ToSave2_f32;
                                 /* Referenced by: '<S216>/PowerSaveMod_tDbc' */
extern const volatile float32 CAL_TpcTmp_tDbcTraSave2ToOverheating_f32;
                                 /* Referenced by: '<S216>/PowerSaveMod_tDbc' */
extern const volatile float32 CAL_TpcTmp_tDrvboardDertTableX_tDrv_af32[9];
                         /* Referenced by: '<S228>/DrvBoardTempDeratingTable' */

/* 驱动板温度查表温度输入 */
extern const volatile float32 CAL_TpcTmp_tDrvboardDertTableY_Cof_af32[9];
                         /* Referenced by: '<S228>/DrvBoardTempDeratingTable' */

/* 驱动板温度查表derating系数输出 */
extern const volatile float32 CAL_TpcTmp_tIGBTDertSave1TableX_tSttr_af32[9];
                        /* Referenced by: '<S234>/IGBTTempDeratingSave1Table' */
extern const volatile float32 CAL_TpcTmp_tIGBTDertSave1TableY_Cof_af32[9];
                        /* Referenced by: '<S234>/IGBTTempDeratingSave1Table' */
extern const volatile float32 CAL_TpcTmp_tIGBTDertSave2TableX_tSttr_af32[9];
                        /* Referenced by: '<S234>/IGBTTempDeratingSave2Table' */
extern const volatile float32 CAL_TpcTmp_tIGBTDertSave2TableY_Cof_af32[9];
                        /* Referenced by: '<S234>/IGBTTempDeratingSave2Table' */
extern const volatile float32 CAL_TpcTmp_tIGBTTempHiLim_f32;
                     /* Referenced by: '<S230>/CAL_TpcTmp_tIGBTTempHiLim_f32' */
extern const volatile float32 CAL_TpcTmp_tIGBTTempLoLim_f32;
                     /* Referenced by: '<S230>/CAL_TpcTmp_tIGBTTempLoLim_f32' */
extern const volatile float32 CAL_TpcTmp_tIGBTTraNormalToSave1_f32;
                                /* Referenced by: '<S234>/PowerSaveMod_tIGBT' */
extern const volatile float32 CAL_TpcTmp_tIGBTTraSave1ToNormal_f32;
                                /* Referenced by: '<S234>/PowerSaveMod_tIGBT' */
extern const volatile float32 CAL_TpcTmp_tIGBTTraSave1ToSave2_f32;
                                /* Referenced by: '<S234>/PowerSaveMod_tIGBT' */
extern const volatile float32 CAL_TpcTmp_tIGBTTraSave2ToOverheating_f32;
                                /* Referenced by: '<S234>/PowerSaveMod_tIGBT' */
extern const volatile float32 CAL_TpcTmp_tIGBTTrqLimRamp_f32;/* Referenced by:
                                                              * '<S197>/CAL_TpcTmp_tIGBTTrqLimRamp_f1'
                                                              * '<S197>/CAL_TpcTmp_tIGBTTrqLimRamp_f32'
                                                              */
extern const volatile float32 CAL_TpcTmp_tRiseDbcDertSave1TableX_tSttr_af32[9];
                     /* Referenced by: '<S217>/DbcRiseTempDeratingSave1Table' */
extern const volatile float32 CAL_TpcTmp_tRiseDbcDertSave1TableY_Cof_af32[9];
                     /* Referenced by: '<S217>/DbcRiseTempDeratingSave1Table' */
extern const volatile float32 CAL_TpcTmp_tRiseDbcDertSave2TableX_tSttr_af32[9];
                     /* Referenced by: '<S217>/DbcRiseTempDeratingSave2Table' */
extern const volatile float32 CAL_TpcTmp_tRiseDbcDertSave2TableY_Cof_af32[9];
                     /* Referenced by: '<S217>/DbcRiseTempDeratingSave2Table' */
extern const volatile float32 CAL_TpcTmp_tRiseDbcTraNormalToSave1_f32;
                             /* Referenced by: '<S217>/PowerSaveMod_tRiseDbc' */
extern const volatile float32 CAL_TpcTmp_tRiseDbcTraSave1ToNormal_f32;
                             /* Referenced by: '<S217>/PowerSaveMod_tRiseDbc' */
extern const volatile float32 CAL_TpcTmp_tRiseDbcTraSave1ToSave2_f32;
                             /* Referenced by: '<S217>/PowerSaveMod_tRiseDbc' */
extern const volatile float32 CAL_TpcTmp_tRiseDbcTraSave2ToOverheating_f32;
                             /* Referenced by: '<S217>/PowerSaveMod_tRiseDbc' */
extern const volatile float32 CAL_TpcTmp_tRiseIGBTDertSave1TableX_tSttr_af32[9];
                    /* Referenced by: '<S235>/IGBTRiseTempDeratingSave1Table' */
extern const volatile float32 CAL_TpcTmp_tRiseIGBTDertSave1TableY_Cof_af32[9];
                    /* Referenced by: '<S235>/IGBTRiseTempDeratingSave1Table' */
extern const volatile float32 CAL_TpcTmp_tRiseIGBTDertSave2TableX_tSttr_af32[9];
                    /* Referenced by: '<S235>/IGBTRiseTempDeratingSave2Table' */
extern const volatile float32 CAL_TpcTmp_tRiseIGBTDertSave2TableY_Cof_af32[9];
                    /* Referenced by: '<S235>/IGBTRiseTempDeratingSave2Table' */
extern const volatile float32 CAL_TpcTmp_tRiseIGBTTraNormalToSave1_f32;
                            /* Referenced by: '<S235>/PowerSaveMod_tRiseIGBT' */
extern const volatile float32 CAL_TpcTmp_tRiseIGBTTraSave1ToNormal_f32;
                            /* Referenced by: '<S235>/PowerSaveMod_tRiseIGBT' */
extern const volatile float32 CAL_TpcTmp_tRiseIGBTTraSave1ToSave2_f32;
                            /* Referenced by: '<S235>/PowerSaveMod_tRiseIGBT' */
extern const volatile float32 CAL_TpcTmp_tRiseIGBTTraSave2ToOverheating_f32;
                            /* Referenced by: '<S235>/PowerSaveMod_tRiseIGBT' */
extern const volatile uint8 CAL_Tpc_NormalMode_u8;/* Referenced by:
                                                   * '<S130>/PowerSaveMod_tRiseIGBT'
                                                   * '<S130>/CAL_Tpc_NormalMode_u8'
                                                   * '<S131>/PowerSaveMod_tSttr'
                                                   * '<S131>/CAL_Tpc_NormalMode_u8'
                                                   * '<S234>/PowerSaveMod_tIGBT'
                                                   * '<S234>/CAL_Tpc_NormalMode_u8'
                                                   * '<S235>/PowerSaveMod_tRiseIGBT'
                                                   * '<S235>/CAL_Tpc_NormalMode_u8'
                                                   * '<S203>/PowerSaveMod_tCoolant'
                                                   * '<S203>/CAL_Tpc_NormalMode_u8'
                                                   * '<S216>/PowerSaveMod_tDbc'
                                                   * '<S216>/CAL_Tpc_NormalMode_u8'
                                                   * '<S217>/PowerSaveMod_tRiseDbc'
                                                   * '<S217>/CAL_Tpc_NormalMode_u8'
                                                   */
extern const volatile uint8 CAL_Tpc_OverheatingMode_u8;/* Referenced by:
                                                        * '<S130>/PowerSaveMod_tRiseIGBT'
                                                        * '<S130>/CAL_Tpc_OverheatingMode_u8'
                                                        * '<S131>/PowerSaveMod_tSttr'
                                                        * '<S131>/CAL_Tpc_OverheatingMode_u8'
                                                        * '<S234>/PowerSaveMod_tIGBT'
                                                        * '<S234>/CAL_Tpc_OverheatingMode_u8'
                                                        * '<S235>/PowerSaveMod_tRiseIGBT'
                                                        * '<S235>/CAL_Tpc_OverheatingMode_u8'
                                                        * '<S203>/PowerSaveMod_tCoolant'
                                                        * '<S203>/CAL_Tpc_OverheatingMode_u8'
                                                        * '<S216>/PowerSaveMod_tDbc'
                                                        * '<S216>/CAL_Tpc_OverheatingMode_u8'
                                                        * '<S217>/PowerSaveMod_tRiseDbc'
                                                        * '<S217>/CAL_Tpc_OverheatingMode_u8'
                                                        */
extern const volatile uint8 CAL_Tpc_Powersave1Mode_u8;/* Referenced by:
                                                       * '<S130>/PowerSaveMod_tRiseIGBT'
                                                       * '<S130>/CAL_Tpc_Powersave1Mode_u8'
                                                       * '<S131>/PowerSaveMod_tSttr'
                                                       * '<S131>/CAL_Tpc_Powersave1Mode_u8'
                                                       * '<S234>/PowerSaveMod_tIGBT'
                                                       * '<S234>/CAL_Tpc_Powersave1Mode_u8'
                                                       * '<S235>/PowerSaveMod_tRiseIGBT'
                                                       * '<S235>/CAL_Tpc_Powersave1Mode_u8'
                                                       * '<S203>/PowerSaveMod_tCoolant'
                                                       * '<S203>/CAL_Tpc_Powersave1Mode_u8'
                                                       * '<S216>/PowerSaveMod_tDbc'
                                                       * '<S216>/CAL_Tpc_Powersave1Mode_u8'
                                                       * '<S217>/PowerSaveMod_tRiseDbc'
                                                       * '<S217>/CAL_Tpc_Powersave1Mode_u8'
                                                       */
extern const volatile uint8 CAL_Tpc_Powersave2Mode_u8;/* Referenced by:
                                                       * '<S130>/PowerSaveMod_tRiseIGBT'
                                                       * '<S130>/CAL_Tpc_Powersave2Mode_u8'
                                                       * '<S131>/PowerSaveMod_tSttr'
                                                       * '<S131>/CAL_Tpc_Powersave2Mode_u8'
                                                       * '<S234>/PowerSaveMod_tIGBT'
                                                       * '<S234>/CAL_Tpc_Powersave2Mode_u8'
                                                       * '<S235>/PowerSaveMod_tRiseIGBT'
                                                       * '<S235>/CAL_Tpc_Powersave2Mode_u8'
                                                       * '<S203>/PowerSaveMod_tCoolant'
                                                       * '<S203>/CAL_Tpc_Powersave2Mode_u8'
                                                       * '<S216>/PowerSaveMod_tDbc'
                                                       * '<S216>/CAL_Tpc_Powersave2Mode_u8'
                                                       * '<S217>/PowerSaveMod_tRiseDbc'
                                                       * '<S217>/CAL_Tpc_Powersave2Mode_u8'
                                                       */
extern const volatile float32 CAL_Tpc_TrqReduceRevStep_f32;/* Referenced by:
                                                            * '<S124>/CAL_Tpc_TrqReduceRevStep_f32'
                                                            * '<S125>/CAL_Tpc_TrqReduceRevStep_f32'
                                                            */
extern const volatile float32 CAL_Tpc_TrqRevStep_f32;/* Referenced by:
                                                      * '<S21>/CAL_Tpc_TrqRevStep_f32'
                                                      * '<S21>/CAL_Tpc_TrqRevStep_f321'
                                                      * '<S22>/CAL_Tpc_TrqRevStep_f32'
                                                      * '<S22>/CAL_Tpc_TrqRevStep_f321'
                                                      */

/* 扭矩限值恢复slop */
extern const volatile float32 CAL_Tpc_TrqRiseRevStep_f32;/* Referenced by:
                                                          * '<S124>/CAL_Tpc_TrqRiseRevStep_f32'
                                                          * '<S125>/CAL_Tpc_TrqRiseRevStep_f32'
                                                          */
extern const volatile uint8 CAL_Tpcmot_CofuDclnk_u8;
                           /* Referenced by: '<S116>/CAL_Tpcmot_CofuDclnk_u8' */
extern const volatile float32 CAL_Tpcmot_TrqDiffExc_f32;
                         /* Referenced by: '<S116>/CAL_Tpcmot_TrqDiffExc_f32' */
extern const volatile float32 CAL_Tpcmot_TrqDiffGen_f32;
                         /* Referenced by: '<S116>/CAL_Tpcmot_TrqDiffGen_f32' */
extern const volatile boolean CAL_Tpcmot_flgOpenExcLimRamp_b;
                    /* Referenced by: '<S116>/CAL_Tpcmot_flgOpenExcLimRamp_b' */
extern const volatile float32 CAL_Tpcmot_uDcHiset_f32;
                           /* Referenced by: '<S116>/CAL_Tpcmot_uDcHiset_f32' */
extern const volatile float32 CAL_Tpcmot_uDcLoset_f32;
                           /* Referenced by: '<S116>/CAL_Tpcmot_uDcLoset_f32' */

#pragma section

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S7>/Add' : Unused code path elimination
 * Block '<S7>/Constant' : Unused code path elimination
 * Block '<S21>/Add3' : Unused code path elimination
 * Block '<S21>/Constant1' : Unused code path elimination
 * Block '<S21>/Relational Operator3' : Unused code path elimination
 * Block '<S21>/Switch4' : Unused code path elimination
 * Block '<S22>/Add3' : Unused code path elimination
 * Block '<S22>/Constant1' : Unused code path elimination
 * Block '<S22>/Relational Operator3' : Unused code path elimination
 * Block '<S22>/Switch4' : Unused code path elimination
 * Block '<S156>/Data Type Duplicate' : Unused code path elimination
 * Block '<S156>/Data Type Propagation' : Unused code path elimination
 * Block '<S157>/Data Type Duplicate' : Unused code path elimination
 * Block '<S157>/Data Type Propagation' : Unused code path elimination
 * Block '<S165>/Data Type Duplicate' : Unused code path elimination
 * Block '<S165>/Data Type Propagation' : Unused code path elimination
 * Block '<S166>/Data Type Duplicate' : Unused code path elimination
 * Block '<S166>/Data Type Propagation' : Unused code path elimination
 * Block '<S175>/Data Type Duplicate' : Unused code path elimination
 * Block '<S175>/Data Type Propagation' : Unused code path elimination
 * Block '<S176>/Data Type Duplicate' : Unused code path elimination
 * Block '<S176>/Data Type Propagation' : Unused code path elimination
 * Block '<S183>/Data Type Duplicate' : Unused code path elimination
 * Block '<S183>/Data Type Propagation' : Unused code path elimination
 * Block '<S184>/Data Type Duplicate' : Unused code path elimination
 * Block '<S184>/Data Type Propagation' : Unused code path elimination
 * Block '<S188>/Data Type Duplicate' : Unused code path elimination
 * Block '<S188>/Data Type Propagation' : Unused code path elimination
 * Block '<S189>/Data Type Duplicate' : Unused code path elimination
 * Block '<S189>/Data Type Propagation' : Unused code path elimination
 * Block '<S190>/Data Type Duplicate' : Unused code path elimination
 * Block '<S190>/Data Type Propagation' : Unused code path elimination
 * Block '<S191>/Data Type Duplicate' : Unused code path elimination
 * Block '<S191>/Data Type Propagation' : Unused code path elimination
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
 * '<Root>' : 'SWC_TPC'
 * '<S1>'   : 'SWC_TPC/RE_SWC_TPC_10ms_sys'
 * '<S2>'   : 'SWC_TPC/RE_SWC_TPC_Init'
 * '<S3>'   : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC'
 * '<S4>'   : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/Model Info'
 * '<S5>'   : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod'
 * '<S6>'   : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge'
 * '<S7>'   : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/CoolantFlowControl'
 * '<S8>'   : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/Coordinate'
 * '<S9>'   : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/GetDeratigStatus'
 * '<S10>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/GetElecAndGenTrqLim'
 * '<S11>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/Model Info'
 * '<S12>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/MotorModeJudgement'
 * '<S13>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason'
 * '<S14>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/CoolantFlowControl/Chart'
 * '<S15>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/CoolantFlowControl/GetPowerIncreasrRate'
 * '<S16>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/CoolantFlowControl/Subsystem1'
 * '<S17>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/Coordinate/If Action Subsystem'
 * '<S18>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/Coordinate/If Action Subsystem1'
 * '<S19>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/Coordinate/RestInitSet'
 * '<S20>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/Coordinate/RestInitSet1'
 * '<S21>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/Coordinate/TrqLimRampSet'
 * '<S22>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/Coordinate/TrqLimRampSet1'
 * '<S23>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/Coordinate/If Action Subsystem/Chart'
 * '<S24>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/Coordinate/If Action Subsystem/Chart/fun'
 * '<S25>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/Coordinate/If Action Subsystem1/Chart'
 * '<S26>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/Coordinate/If Action Subsystem1/Chart/fun'
 * '<S27>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/GetDeratigStatus/FlgDeratigStatus'
 * '<S28>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/GetDeratigStatus/FlgDeratigStatus/Compare To Constant'
 * '<S29>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/GetDeratigStatus/FlgDeratigStatus/Compare To Constant1'
 * '<S30>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/GetDeratigStatus/FlgDeratigStatus/Compare To Constant2'
 * '<S31>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/GetDeratigStatus/FlgDeratigStatus/Compare To Constant3'
 * '<S32>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/GetDeratigStatus/FlgDeratigStatus/Compare To Constant4'
 * '<S33>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/GetElecAndGenTrqLim/GetElecTorqueLim'
 * '<S34>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/GetElecAndGenTrqLim/GetGenTorqueLim'
 * '<S35>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/GetElecAndGenTrqLim/GetElecTorqueLim/GetMinValue'
 * '<S36>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/GetElecAndGenTrqLim/GetElecTorqueLim/GetTDbcTrqMax'
 * '<S37>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/GetElecAndGenTrqLim/GetElecTorqueLim/GetTrqFromPwr'
 * '<S38>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/GetElecAndGenTrqLim/GetElecTorqueLim/GetTrqFromPwr1'
 * '<S39>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/GetElecAndGenTrqLim/GetElecTorqueLim/GetTrqFromPwr2'
 * '<S40>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/GetElecAndGenTrqLim/GetGenTorqueLim/GetMaxValue'
 * '<S41>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/GetElecAndGenTrqLim/GetGenTorqueLim/GetTrqFromPwr'
 * '<S42>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/GetElecAndGenTrqLim/GetGenTorqueLim/GetTrqFromPwr1'
 * '<S43>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/GetElecAndGenTrqLim/GetGenTorqueLim/GetTrqFromPwr2'
 * '<S44>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/MotorModeJudgement/GetMotorMode'
 * '<S45>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/MotorModeJudgement/GetSpdDirection'
 * '<S46>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/MotorModeJudgement/GetTorqueDirection'
 * '<S47>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/MotorModeJudgement/GetMotorMode/If Action Subsystem'
 * '<S48>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/MotorModeJudgement/GetMotorMode/If Action Subsystem1'
 * '<S49>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/MotorModeJudgement/GetMotorMode/If Action Subsystem2'
 * '<S50>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/MotorModeJudgement/GetMotorMode/If Action Subsystem3'
 * '<S51>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/Chart2'
 * '<S52>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/Chart4'
 * '<S53>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge'
 * '<S54>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/Subsystem10'
 * '<S55>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_Can'
 * '<S56>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_ExcTrq'
 * '<S57>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_Idc'
 * '<S58>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_MtrSpd'
 * '<S59>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_OvUdc'
 * '<S60>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_TCool'
 * '<S61>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_TDbc'
 * '<S62>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_TDrvBoard'
 * '<S63>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_TIGBT'
 * '<S64>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_Tsttr'
 * '<S65>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_UnUdc'
 * '<S66>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_Can/AEqualB24'
 * '<S67>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_Can/AEqualB33'
 * '<S68>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_ExcTrq/AEqualB1'
 * '<S69>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_ExcTrq/AEqualB25'
 * '<S70>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_ExcTrq/AEqualB8'
 * '<S71>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_ExcTrq/AEqualB9'
 * '<S72>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_Idc/AEqualB20'
 * '<S73>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_Idc/AEqualB21'
 * '<S74>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_Idc/AEqualB31'
 * '<S75>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_Idc/AEqualB6'
 * '<S76>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_MtrSpd/AEqualB'
 * '<S77>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_MtrSpd/AEqualB18'
 * '<S78>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_MtrSpd/AEqualB19'
 * '<S79>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_MtrSpd/AEqualB30'
 * '<S80>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_OvUdc/AEqualB23'
 * '<S81>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_OvUdc/AEqualB32'
 * '<S82>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_TCool/AEqualB14'
 * '<S83>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_TCool/AEqualB15'
 * '<S84>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_TCool/AEqualB28'
 * '<S85>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_TCool/AEqualB4'
 * '<S86>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_TDbc/AEqualB12'
 * '<S87>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_TDbc/AEqualB13'
 * '<S88>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_TDbc/AEqualB27'
 * '<S89>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_TDbc/AEqualB3'
 * '<S90>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_TDrvBoard/AEqualB16'
 * '<S91>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_TDrvBoard/AEqualB17'
 * '<S92>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_TDrvBoard/AEqualB29'
 * '<S93>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_TDrvBoard/AEqualB5'
 * '<S94>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_TIGBT/AEqualB16'
 * '<S95>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_TIGBT/AEqualB17'
 * '<S96>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_TIGBT/AEqualB29'
 * '<S97>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_TIGBT/AEqualB5'
 * '<S98>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_Tsttr/AEqualB10'
 * '<S99>'  : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_Tsttr/AEqualB11'
 * '<S100>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_Tsttr/AEqualB2'
 * '<S101>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_Tsttr/AEqualB26'
 * '<S102>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_UnUdc/AEqualB22'
 * '<S103>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcCod/TorqueLimitationReason/TorqLimReasonJudge/TorqLimReason_UnUdc/AEqualB7'
 * '<S104>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/Model Info'
 * '<S105>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcBlk'
 * '<S106>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcFuv'
 * '<S107>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcMot'
 * '<S108>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp'
 * '<S109>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp'
 * '<S110>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcBlk/Chart'
 * '<S111>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcFuv/DeratingStrategy_FultLv'
 * '<S112>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcFuv/GetFaultLevelStatus'
 * '<S113>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcFuv/Model Info'
 * '<S114>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcFuv/DeratingStrategy_FultLv/tpcfuv_PwrLim'
 * '<S115>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcFuv/DeratingStrategy_FultLv/tpcfuv_TorqLim'
 * '<S116>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcMot/ExternalCharacteristicDerating'
 * '<S117>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcMot/GetTrqPwrBenchmark'
 * '<S118>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcMot/Model Info'
 * '<S119>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcMot/SttrTemperatureDerating'
 * '<S120>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcMot/ExternalCharacteristicDerating/RestInitSet'
 * '<S121>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcMot/ExternalCharacteristicDerating/RestInitSet1'
 * '<S122>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcMot/ExternalCharacteristicDerating/TrqLimRampRiseAndReduceSet'
 * '<S123>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcMot/ExternalCharacteristicDerating/TrqLimRampRiseAndReduceSet1'
 * '<S124>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcMot/ExternalCharacteristicDerating/TrqLimRampRiseAndReduceSet/Subsystem1'
 * '<S125>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcMot/ExternalCharacteristicDerating/TrqLimRampRiseAndReduceSet1/Subsystem1'
 * '<S126>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcMot/SttrTemperatureDerating/DemStatorTemperature'
 * '<S127>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcMot/SttrTemperatureDerating/GetRampElecTrqLim'
 * '<S128>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcMot/SttrTemperatureDerating/GetRampGenTrqLim'
 * '<S129>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcMot/SttrTemperatureDerating/GetSttrTempLimTorq'
 * '<S130>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcMot/SttrTemperatureDerating/GetTRiseSttrDeratingCof'
 * '<S131>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcMot/SttrTemperatureDerating/GetTsttrDeratingCof'
 * '<S132>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcMot/SttrTemperatureDerating/SttrTempFlt'
 * '<S133>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcMot/SttrTemperatureDerating/GetSttrTempLimTorq/GetDeratingFlag_TIGBT'
 * '<S134>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcMot/SttrTemperatureDerating/GetTRiseSttrDeratingCof/GetHighTemp'
 * '<S135>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcMot/SttrTemperatureDerating/GetTRiseSttrDeratingCof/PowerSaveMod_tRiseIGBT'
 * '<S136>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcMot/SttrTemperatureDerating/GetTsttrDeratingCof/GetHighTemp'
 * '<S137>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcMot/SttrTemperatureDerating/GetTsttrDeratingCof/PowerSaveMod_tSttr'
 * '<S138>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcMot/SttrTemperatureDerating/SttrTempFlt/Compare To Constant'
 * '<S139>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcMot/SttrTemperatureDerating/SttrTempFlt/Compare To Constant1'
 * '<S140>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyCurrent'
 * '<S141>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyVoltage'
 * '<S142>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategy_OverSpeed'
 * '<S143>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/GetBatteryCapacity'
 * '<S144>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/GetVcuTrqDertCommand'
 * '<S145>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/Model Info'
 * '<S146>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyCurrent/DemBusCurrent'
 * '<S147>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyCurrent/DeratingStrategy_OvercurrentElec'
 * '<S148>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyCurrent/DeratingStrategy_OvercurrentGen'
 * '<S149>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyCurrent/DeratingStrategy_OvercurrentElec/Coordinate'
 * '<S150>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyCurrent/DeratingStrategy_OvercurrentElec/GetPositiveCurrent'
 * '<S151>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyCurrent/DeratingStrategy_OvercurrentElec/LinearRegionPowerDerating'
 * '<S152>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyCurrent/DeratingStrategy_OvercurrentElec/PIRegionPowerDerting'
 * '<S153>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyCurrent/DeratingStrategy_OvercurrentElec/Subsystem'
 * '<S154>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyCurrent/DeratingStrategy_OvercurrentElec/Coordinate/Debounce'
 * '<S155>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyCurrent/DeratingStrategy_OvercurrentElec/PIRegionPowerDerting/PI'
 * '<S156>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyCurrent/DeratingStrategy_OvercurrentElec/PIRegionPowerDerting/PI/Saturation Dynamic3'
 * '<S157>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyCurrent/DeratingStrategy_OvercurrentElec/PIRegionPowerDerting/PI/Saturation Dynamic4'
 * '<S158>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyCurrent/DeratingStrategy_OvercurrentGen/Coordinate'
 * '<S159>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyCurrent/DeratingStrategy_OvercurrentGen/GetNegativeCurrent'
 * '<S160>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyCurrent/DeratingStrategy_OvercurrentGen/LinearRegionPowerDerating'
 * '<S161>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyCurrent/DeratingStrategy_OvercurrentGen/PIRegionPowerDerting'
 * '<S162>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyCurrent/DeratingStrategy_OvercurrentGen/Subsystem'
 * '<S163>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyCurrent/DeratingStrategy_OvercurrentGen/Coordinate/Debounce'
 * '<S164>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyCurrent/DeratingStrategy_OvercurrentGen/PIRegionPowerDerting/PI'
 * '<S165>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyCurrent/DeratingStrategy_OvercurrentGen/PIRegionPowerDerting/PI/Saturation Dynamic3'
 * '<S166>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyCurrent/DeratingStrategy_OvercurrentGen/PIRegionPowerDerting/PI/Saturation Dynamic4'
 * '<S167>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyVoltage/DeratingStrategy_Overvoltage'
 * '<S168>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyVoltage/DeratingStrategy_Undervoltage'
 * '<S169>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyVoltage/DeratingStrategy_Overvoltage/Coordinate'
 * '<S170>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyVoltage/DeratingStrategy_Overvoltage/DemBusOvrVoltage'
 * '<S171>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyVoltage/DeratingStrategy_Overvoltage/LinearRegionPowerDerating'
 * '<S172>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyVoltage/DeratingStrategy_Overvoltage/PIRegionPowerDerting'
 * '<S173>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyVoltage/DeratingStrategy_Overvoltage/Coordinate/Debounce'
 * '<S174>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyVoltage/DeratingStrategy_Overvoltage/PIRegionPowerDerting/PI'
 * '<S175>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyVoltage/DeratingStrategy_Overvoltage/PIRegionPowerDerting/PI/Saturation Dynamic3'
 * '<S176>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyVoltage/DeratingStrategy_Overvoltage/PIRegionPowerDerting/PI/Saturation Dynamic4'
 * '<S177>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyVoltage/DeratingStrategy_Undervoltage/Coordinate'
 * '<S178>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyVoltage/DeratingStrategy_Undervoltage/DemBusUndrVoltage'
 * '<S179>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyVoltage/DeratingStrategy_Undervoltage/LinearRegionPowerDerating'
 * '<S180>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyVoltage/DeratingStrategy_Undervoltage/PIRegionPowerDerting'
 * '<S181>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyVoltage/DeratingStrategy_Undervoltage/Coordinate/Debounce'
 * '<S182>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyVoltage/DeratingStrategy_Undervoltage/PIRegionPowerDerting/PI'
 * '<S183>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyVoltage/DeratingStrategy_Undervoltage/PIRegionPowerDerting/PI/Saturation Dynamic3'
 * '<S184>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategyVoltage/DeratingStrategy_Undervoltage/PIRegionPowerDerting/PI/Saturation Dynamic4'
 * '<S185>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategy_OverSpeed/Subsystem'
 * '<S186>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategy_OverSpeed/Subsystem1'
 * '<S187>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/DeratingStrategy_OverSpeed/Subsystem1/Hysteresis'
 * '<S188>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/GetBatteryCapacity/Saturation Dynamic'
 * '<S189>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/GetBatteryCapacity/Saturation Dynamic1'
 * '<S190>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/GetBatteryCapacity/Saturation Dynamic2'
 * '<S191>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/GetBatteryCapacity/Saturation Dynamic3'
 * '<S192>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/GetVcuTrqDertCommand/CAL_TpcSmp_nCtlExtReq_u8'
 * '<S193>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcSmp/GetVcuTrqDertCommand/CAL_TpcSmp_nCtlIntReq_u8'
 * '<S194>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/CoolantTemperatureDerating'
 * '<S195>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/DbcTemperatureDerating'
 * '<S196>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/DrvBoardTemperatureDerating'
 * '<S197>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/IGBTTemperatureDerating'
 * '<S198>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/Model Info'
 * '<S199>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/CoolantTemperatureDerating/DemCoolantTemperature'
 * '<S200>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/CoolantTemperatureDerating/DeratingStrategy_TCoolant'
 * '<S201>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/CoolantTemperatureDerating/GetDeratingFlag_TCoolant'
 * '<S202>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/CoolantTemperatureDerating/DeratingStrategy_TCoolant/CoolantTempFlt'
 * '<S203>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/CoolantTemperatureDerating/DeratingStrategy_TCoolant/GetTDbcDeratingCof'
 * '<S204>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/CoolantTemperatureDerating/DeratingStrategy_TCoolant/CoolantTempFlt/Compare To Constant'
 * '<S205>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/CoolantTemperatureDerating/DeratingStrategy_TCoolant/CoolantTempFlt/Compare To Constant1'
 * '<S206>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/CoolantTemperatureDerating/DeratingStrategy_TCoolant/GetTDbcDeratingCof/GetHighTemp'
 * '<S207>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/CoolantTemperatureDerating/DeratingStrategy_TCoolant/GetTDbcDeratingCof/PowerSaveMod_tCoolant'
 * '<S208>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/DbcTemperatureDerating/DBCTemperatureDerating'
 * '<S209>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/DbcTemperatureDerating/DbcTempFlt'
 * '<S210>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/DbcTemperatureDerating/DemDbcTemperature'
 * '<S211>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/DbcTemperatureDerating/GetDeratingFlag_Tdbc'
 * '<S212>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/DbcTemperatureDerating/GetMaxDbcTemp'
 * '<S213>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/DbcTemperatureDerating/GetRampElecTrqLim'
 * '<S214>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/DbcTemperatureDerating/GetRampGenTrqLim'
 * '<S215>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/DbcTemperatureDerating/DBCTemperatureDerating/GetDbcTempLimTorq'
 * '<S216>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/DbcTemperatureDerating/DBCTemperatureDerating/GetTDbcDeratingCof'
 * '<S217>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/DbcTemperatureDerating/DBCTemperatureDerating/GetTRiseDbcDeratingCof'
 * '<S218>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/DbcTemperatureDerating/DBCTemperatureDerating/GetTDbcDeratingCof/GetHighTemp'
 * '<S219>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/DbcTemperatureDerating/DBCTemperatureDerating/GetTDbcDeratingCof/PowerSaveMod_tDbc'
 * '<S220>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/DbcTemperatureDerating/DBCTemperatureDerating/GetTRiseDbcDeratingCof/DbcTempFlt'
 * '<S221>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/DbcTemperatureDerating/DBCTemperatureDerating/GetTRiseDbcDeratingCof/GetHighTemp'
 * '<S222>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/DbcTemperatureDerating/DBCTemperatureDerating/GetTRiseDbcDeratingCof/PowerSaveMod_tRiseDbc'
 * '<S223>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/DbcTemperatureDerating/DBCTemperatureDerating/GetTRiseDbcDeratingCof/DbcTempFlt/Compare To Constant'
 * '<S224>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/DbcTemperatureDerating/DBCTemperatureDerating/GetTRiseDbcDeratingCof/DbcTempFlt/Compare To Constant1'
 * '<S225>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/DbcTemperatureDerating/DbcTempFlt/Compare To Constant'
 * '<S226>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/DbcTemperatureDerating/DbcTempFlt/Compare To Constant1'
 * '<S227>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/DrvBoardTemperatureDerating/DemDrvBoardTemperature'
 * '<S228>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/DrvBoardTemperatureDerating/DeratingStrategy_TDrvBoard'
 * '<S229>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/DrvBoardTemperatureDerating/GetDeratingFlag_TDrvBoard'
 * '<S230>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/IGBTTemperatureDerating/DemIGBTTemperature'
 * '<S231>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/IGBTTemperatureDerating/GetIGBTTempLimTorq'
 * '<S232>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/IGBTTemperatureDerating/GetRampElecTrqLim'
 * '<S233>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/IGBTTemperatureDerating/GetRampGenTrqLim'
 * '<S234>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/IGBTTemperatureDerating/GetTIGBTDeratingCof'
 * '<S235>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/IGBTTemperatureDerating/GetTRiseIGBTDeratingCof'
 * '<S236>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/IGBTTemperatureDerating/IgbtTempFlt'
 * '<S237>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/IGBTTemperatureDerating/GetIGBTTempLimTorq/GetDeratingFlag_TIGBT'
 * '<S238>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/IGBTTemperatureDerating/GetTIGBTDeratingCof/GetHighTemp'
 * '<S239>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/IGBTTemperatureDerating/GetTIGBTDeratingCof/PowerSaveMod_tIGBT'
 * '<S240>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/IGBTTemperatureDerating/GetTRiseIGBTDeratingCof/GetHighTemp'
 * '<S241>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/IGBTTemperatureDerating/GetTRiseIGBTDeratingCof/IgbtTempFlt'
 * '<S242>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/IGBTTemperatureDerating/GetTRiseIGBTDeratingCof/PowerSaveMod_tRiseIGBT'
 * '<S243>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/IGBTTemperatureDerating/GetTRiseIGBTDeratingCof/IgbtTempFlt/Compare To Constant'
 * '<S244>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/IGBTTemperatureDerating/GetTRiseIGBTDeratingCof/IgbtTempFlt/Compare To Constant1'
 * '<S245>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/IGBTTemperatureDerating/IgbtTempFlt/Compare To Constant'
 * '<S246>' : 'SWC_TPC/RE_SWC_TPC_10ms_sys/TPC/TpcJudge/TpcTmp/IGBTTemperatureDerating/IgbtTempFlt/Compare To Constant1'
 */
#endif                                 /* RTW_HEADER_SWC_TPC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
