/*
 * File: SWC_TPC.c
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

#include "SWC_TPC.h"
#include "SWC_TPC_private.h"
#include "look1_iflf_binlcapw.h"
#include "look1_iflf_binlxpw.h"
#include "look2_iflf_binlcapw.h"

/* Named constants for Chart: '<S7>/Chart' */
#define SWC_TPC_IN_CoolantFolw2L       ((uint8)1U)
#define SWC_TPC_IN_CoolantFolw4L       ((uint8)2U)
#define SWC_TPC_IN_CoolantFolw6L       ((uint8)3U)
#define SWC_TPC_IN_CoolantFolw8L       ((uint8)4U)

/* Named constants for Chart: '<S130>/PowerSaveMod_tRiseIGBT' */
#define SWC_TPC_IN_NormalMode          ((uint8)1U)
#define SWC_TPC_IN_Overheating         ((uint8)2U)
#define SWC_TPC_IN_PowerSave1          ((uint8)3U)
#define SWC_TPC_IN_PowerSave2          ((uint8)4U)

/* Exported block signals */
float32 VAR_TpcTmp_tCoolantTempFlt_f32;/* '<S202>/Add3' */
float32 VAR_TpcTmp_CofDertTCoolantSave1_f32;
                                    /* '<S203>/CoolantTempDeratingSave1Table' */
float32 VAR_TpcTmp_CofDertTCoolantSave2_f32;
                                    /* '<S203>/CoolantTempDeratingSave2Table' */
float32 VAR_TpcTmp_CofDertTcoolant_f32;/* '<S203>/Switch1'
                                        * 冷却水温度限扭Derating系数
                                        */
float32 VAR_TpcTmp_tDbcMax_f32;        /* '<S212>/Switch1'
                                        * 三相Dbc温度最大值
                                        */
float32 VAR_TpcTmp_tDbcTempFlt_f32;    /* '<S209>/Add3' */
float32 VAR_TpcTmp_CofDertTDbcSave1_f32;/* '<S216>/DbcTempDeratingSave1Table' */
float32 VAR_TpcTmp_CofDertTDbcSave2_f32;/* '<S216>/DbcTempDeratingSave2Table' */
float32 VAR_TpcTmp_CofDertDbc_f32;     /* '<S216>/Switch1' */
float32 VAR_TpcTmp_tRiseDbc_f32;       /* '<S217>/Add' */
float32 VAR_TpcTmp_tRiseDbcFlt_f32;    /* '<S220>/Add3' */
float32 VAR_TpcTmp_CofDertTRiseDbcSave1_f32;
                                    /* '<S217>/DbcRiseTempDeratingSave1Table' */
float32 VAR_TpcTmp_CofDertTRiseDbcSave2_f32;
                                    /* '<S217>/DbcRiseTempDeratingSave2Table' */
float32 VAR_TpcTmp_CofDertTRiseDbc_f32;/* '<S217>/Switch1' */
float32 VAR_TpcTmp_CofDertTdrvboard_f32;/* '<S228>/DrvBoardTempDeratingTable'
                                         * 驱动板温度限扭Derating系数
                                         */
float32 VAR_TpcTmp_tIGBTTempFlt_f32;   /* '<S236>/Add3' */
float32 VAR_TpcTmp_CofDertTIGBTSave1_f32;/* '<S234>/IGBTTempDeratingSave1Table' */
float32 VAR_TpcTmp_CofDertTIGBTSave2_f32;/* '<S234>/IGBTTempDeratingSave2Table' */
float32 VAR_TpcTmp_CofDertIGBT_f32;    /* '<S234>/Switch1' */
float32 VAR_TpcTmp_tRiseIGBT_f32;      /* '<S235>/Add' */
float32 VAR_TpcTmp_tRiseIGBTFlt_f32;   /* '<S241>/Add3' */
float32 VAR_TpcTmp_CofDertTRiseIGBTSave1_f32;
                                   /* '<S235>/IGBTRiseTempDeratingSave1Table' */
float32 VAR_TpcTmp_CofDertTRiseIGBTSave2_f32;
                                   /* '<S235>/IGBTRiseTempDeratingSave2Table' */
float32 VAR_TpcTmp_CofDertTRiseIGBT_f32;/* '<S235>/Switch1' */
float32 VAR_TpcMot_tSttrTempFlt_f32;   /* '<S132>/Add3' */
float32 VAR_TpcMot_CofDertTSttrSave1_f32;/* '<S131>/SttrTempDeratingSave1Table' */
float32 VAR_TpcMot_CofDertTSttrSave2_f32;/* '<S131>/SttrTempDeratingSave2Table' */
float32 VAR_TpcMot_CofDertTsttr_f32;   /* '<S131>/Switch1'
                                        * 定子温度限扭derating系数
                                        */
float32 VAR_TpcMot_tRiseSttr_f32;      /* '<S130>/Add' */
float32 VAR_TpcMot_CofDertTRiseSttrSave1_f32;
                                   /* '<S130>/SttrRiseTempDeratingSave1Table' */
float32 VAR_TpcMot_CofDertTRiseSttrSave2_f32;
                                   /* '<S130>/SttrRiseTempDeratingSave2Table' */
float32 VAR_TpcMot_CofDertTRiseSttr_f32;/* '<S130>/Switch1' */
float32 VAR_TpcSmp_iDcLnkMax_f32;      /* '<S188>/Switch2'
                                        * 限幅的电池允许最大放电电流
                                        */
float32 VAR_TpcSmp_cofDertOvrCurtElec_f32;/* '<S151>/BusCurrentDertElecTable'
                                           * 母线过流线性降电动功率derating系数
                                           */
float32 VAR_tpcsmp_yiDelay_f32;        /* '<S155>/Unit Delay' */
float32 VAR_TpcSmp_ElecPwrAlowMax_f32; /* '<S152>/Divide'
                                        * 电池允许最大放电功率
                                        */
float32 VAR_TpcSmp_ErrElecOvrCurt_f32; /* '<S152>/Add'
                                        * 过流降电动功率PI模块差值输入
                                        */
float32 VAR_tpcsmp_KiProduct_f32;      /* '<S155>/Product1' */
float32 VAR_tpcsmp_KiProductSum_f32;   /* '<S155>/Add6' */
float32 VAR_tpcsmp_KpProduct_f32;      /* '<S155>/Product' */
float32 VAR_tpcsmp_KpProductSau_f32;   /* '<S156>/Switch2' */
float32 VAR_tpcsmp_PIOutput_f32;       /* '<S155>/Add3' */
float32 VAR_tpcsmp_PwrLoss_f32;        /* '<S152>/Switch1' */
float32 VAR_tpcsmp_AddPwrElecOvrCurt_f32;/* '<S152>/Switch' */
float32 VAR_tpcsmp_RefPwrElecOvrCurt_f32;/* '<S152>/Add1' */
float32 VAR_TpcSmp_ElecPwrPIDertOvrCurt_f32;/* '<S155>/Add7'
                                             * 母线过流PI降电动功率
                                             */
float32 VAR_TpcSmp_iDcLnkMin_f32;      /* '<S189>/Switch2'
                                        * 限幅的电池允许最大充电电流
                                        */
float32 VAR_TpcSmp_cofDertOvrCurtGen_f32;/* '<S160>/BusCurrentDertGenTable'
                                          * 母线过流线性降发电功率derating系数
                                          */
float32 VAR_TpcSmp_GenPwrAlowMax_f32;  /* '<S161>/Abs' */
float32 VAR_TpcSmp_ErrGenOvrCurt_f32;  /* '<S161>/Add' */
float32 VAR_tpcsmp_PwrLossGen_f32;     /* '<S161>/Switch1' */
float32 VAR_tpcsmp_RefPwrGenOvrCurt_f32;/* '<S161>/Add1' */
float32 VAR_TpcSmp_uDcLnkMax_f32;      /* '<S190>/Switch2'
                                        * 限幅的电池允许最大充电电压
                                        */
float32 VAR_TpcSmp_cofDertOvrVoltGen_f32;/* '<S171>/BusVoltageDertGenTable'
                                          * 母线过压线性降发电功率derating系数
                                          */
float32 VAR_TpcMot_TrqGenExCOrg_f32;   /* '<S116>/Negate' */
float32 VAR_TpcMot_TrqElecExCOrg_f32;  /* '<S116>/ElecExCTable' */
float32 VAR_TpcMot_TrqGenExC_f32;      /* '<S116>/Switch1'
                                        * 外特性限制发电扭矩
                                        */
float32 VAR_TpcMot_GenPwrRef_f32;      /* '<S117>/Switch1'
                                        * TpcMot限扭基准发电功率
                                        */
float32 VAR_TpcSmp_uDcLnkMin_f32;      /* '<S191>/Switch2'
                                        * 限幅的电池允许最小放电电压
                                        */
float32 VAR_TpcSmp_cofDertUdrVoltElec_f32;/* '<S179>/BusVoltageDertElecTable'
                                           * 母线欠压线性降电动功率derating系数
                                           */
float32 VAR_TpcMot_TrqElecExC_f32;     /* '<S116>/Switch'
                                        * 外特性限制电动扭矩
                                        */
float32 VAR_TpcMot_ElecPwrRef_f32;     /* '<S117>/Switch'
                                        * TpcMot限扭基准电动功率
                                        */
float32 VAR_TpcSmp_ElecPwrPIDertUdrVolt_f32;/* '<S184>/Switch2'
                                             * 母线欠压PI降电动功率
                                             */
float32 VAR_TpcCod_PowerAdd_f32;       /* '<S15>/Add' */
float32 VAR_TpcCod_PowerIncreaseRate_f32;/* '<S15>/Divide1' */
float32 VAR_TpcCod_CoolantFlowFinReq_f32;/* '<S7>/Switch' */
float32 VAR_TpcMot_ElecTrqRef_f32;     /* '<S117>/Switch2'
                                        * TpcMot模块基准电动扭矩
                                        */
float32 VAR_TpcMot_ElecTrqLimTsttrWoRamp_f32;/* '<S129>/Product' */
float32 VAR_TpcMot_ElecTrqLimTsttr_f32;/* '<S127>/Switch2'
                                        * 定子温度限扭电动扭矩
                                        */
float32 VAR_TpcTmp_ElecTrqLimTdbcWoRamp_f32;/* '<S215>/Product' */
float32 VAR_TpcTmp_ElecTrqLimTdbc_f32; /* '<S213>/Switch2'
                                        * Dbc温度限扭电动扭矩
                                        */
float32 VAR_TpcTmp_ElecTrqLimTcoolant_f32;/* '<S200>/Product'
                                           * 冷却水温度限扭电动扭矩
                                           */
float32 VAR_TpcTmp_ElecTrqLimTdrvboard_f32;/* '<S228>/Product'
                                            * 驱动板温度限扭电动扭矩
                                            */
float32 VAR_TpcTmp_ElecTrqLimTIGBTWoRamp_f32;/* '<S231>/Product' */
float32 VAR_TpcTmp_ElecTrqLimTIGBT_f32;/* '<S232>/Switch2' */
float32 VAR_TpcSmp_cofDertOvrSpdElecQuad1_f32;/* '<S185>/OvSpdDertQurd1Table'
                                               * 超速限扭第一象限查表Derating系数
                                               */
float32 VAR_TpcSmp_cofDertOvrSpdElecQuad3_f32;/* '<S185>/OvSpdDertQurd3Table'
                                               * 超速限扭第三象限查表Derating系数
                                               */
float32 VAR_TpcSmp_ElecTrqLimOvrSpd_f32;/* '<S185>/Product'
                                         * 超速限扭电动扭矩
                                         */
float32 VAR_TpcMot_GenTrqRef_f32;      /* '<S117>/Switch3'
                                        * TpcMot模块基准发电扭矩
                                        */
float32 VAR_tpcsmp_ElecPwrDert_f32;    /* '<S153>/Product' */
float32 VAR_TpcSmp_ElecPwrLinearDertOvrCurt_f32;/* '<S151>/Product'
                                                 * 母线过流线性降电动功率
                                                 */
float32 VAR_TpcSmp_ElecPwrLimOvrCurt_f32;/* '<S149>/Switch1'
                                          * 母线过流降电动功率
                                          */
float32 VAR_TpcCod_ElecTrqCalcOvrCurt_f32;/* '<S37>/Switch1'
                                           * 过流降电动功率值计算扭矩
                                           */
float32 VAR_TpcSmp_ElecPwrLinearDertUdrVolt_f32;/* '<S179>/Product'
                                                 * 母线欠压线性降电动功率
                                                 */
float32 VAR_TpcSmp_ElecPwrLimUdrVolt_f32;/* '<S177>/Switch1'
                                          * 母线欠压降电动功率
                                          */
float32 VAR_TpcCod_ElecTrqCalcUdrVolt_f32;/* '<S38>/Switch1'
                                           * 欠压降电动功率值计算扭矩
                                           */
float32 VAR_TpcCod_ElecTrqCalcDiag_f32;/* '<S39>/Switch1'
                                        * 故障等级降电动功率值计算扭矩
                                        */
float32 VAR_TpcMot_GenTrqLimTsttrWoRamp_f32;/* '<S129>/Product1' */
float32 VAR_TpcMot_GenTrqLimTsttr_f32; /* '<S128>/Switch2'
                                        * 定子温度限扭发电扭矩
                                        */
float32 VAR_TpcTmp_GenTrqLimTdbcWoRamp_f32;/* '<S215>/Product1' */
float32 VAR_TpcTmp_GenTrqLimTdbc_f32;  /* '<S214>/Switch2'
                                        * Dbc温度限扭发电扭矩
                                        */
float32 VAR_TpcTmp_GenTrqLimTcoolant_f32;/* '<S200>/Product1'
                                          * 冷却水温度限扭发电扭矩
                                          */
float32 VAR_TpcTmp_GenTrqLimTdrvboard_f32;/* '<S228>/Product1'
                                           * 驱动板温度限扭发电扭矩
                                           */
float32 VAR_TpcTmp_GenTrqLimTIGBTWoRamp_f32;/* '<S231>/Product1' */
float32 VAR_TpcTmp_GenTrqLimTIGBT_f32; /* '<S233>/Switch2' */
float32 VAR_TpcSmp_cofDertOvrSpdGenQuad4_f32;/* '<S185>/OvSpdDertQurd4Table'
                                              * 超速限扭第四象限查表Derating系数
                                              */
float32 VAR_TpcSmp_cofDertOvrSpdGenQuad2_f32;/* '<S185>/OvSpdDertQurd2Table'
                                              * 超速限扭第二象限查表Derating系数
                                              */
float32 VAR_TpcSmp_GenTrqLimOvrSpd_f32;/* '<S185>/Product1'
                                        * 超速限扭发电扭矩
                                        */
float32 VAR_tpcsmp_GenPwrDert_f32;     /* '<S162>/Product' */
float32 VAR_TpcSmp_GenPwrPIDertOvrCurt_f32;/* '<S164>/Gain10'
                                            * 母线过流PI降发电功率
                                            */
float32 VAR_TpcSmp_GenPwrLinearDertOvrCurt_f32;/* '<S160>/Product'
                                                * 母线过流线性降发电功率
                                                */
float32 VAR_TpcSmp_GenPwrLimOvrCurt_f32;/* '<S158>/Switch1'
                                         * 母线过流降发电功率
                                         */
float32 VAR_TpcCod_GenTrqCalcOvrCurt_f32;/* '<S41>/Switch1'
                                          * 过流降发电功率值计算扭矩
                                          */
float32 VAR_TpcSmp_GenPwrLinearDertOvrVolt_f32;/* '<S171>/Product'
                                                * 母线过压线性降发电功率
                                                */
float32 VAR_TpcSmp_GenPwrPIDertOvrVolt_f32;/* '<S174>/Gain6'
                                            * 母线过压PI降发电功率
                                            */
float32 VAR_TpcSmp_GenPwrLimOvrVolt_f32;/* '<S169>/Switch'
                                         * 母线过压降发电功率
                                         */
float32 VAR_TpcCod_GenTrqCalcOvrVolt_f32;/* '<S42>/Switch1'
                                          * 欠压降发电功率值计算扭矩
                                          */
float32 VAR_TpcCod_GenTrqCalcDiag_f32; /* '<S43>/Switch1'
                                        * 故障等级降发电功率值计算扭矩
                                        */
float32 VAR_TpcSmp_TrqMaxCanSet_f32;   /* '<S144>/Switch'
                                        * CAN指令限扭最大扭矩
                                        */
float32 VAR_TpcSmp_TrqMinCanSet_f32;   /* '<S144>/Switch1'
                                        * CAN指令限扭最小扭矩
                                        */
float32 VAR_TpcBlk_IsValid_f32;        /* '<S105>/Divide' */
float32 VAR_Tpcblk_TrqLim_f32;         /* '<S105>/Switch2' */
float32 VAR_Tpcblk_TrqLim01_f32;       /* '<S105>/Switch6' */
float32 VAR_Tpcblk_TrqMax_f32;         /* '<S105>/Switch4' */
float32 VAR_Tpcblk_TrqMin_f32;         /* '<S105>/Product1' */
float32 VAR_tpcsmp_posOutputjudge_f32; /* '<S155>/Switch2' */
float32 VAR_tpcsmp_negOutputjudge_f32; /* '<S155>/Switch3' */
float32 VAR_tpcsmp_yi_f32;             /* '<S155>/Switch' */
float32 VAR_TpcFuv_ElecTrqLimDiag_f32; /* '<S111>/tpcfuv_TorqLim'
                                        * 故障等级限扭电动扭矩
                                        */
float32 VAR_TpcFuv_GenTrqLimDiag_f32;  /* '<S111>/tpcfuv_TorqLim'
                                        * 故障等级限扭发电扭矩
                                        */
float32 VAR_TpcFuv_ElecPwrLimDiag_f32; /* '<S111>/tpcfuv_PwrLim'
                                        * 故障等级限扭电动功率
                                        */
float32 VAR_TpcFuv_GenPwrLimDiag_f32;  /* '<S111>/tpcfuv_PwrLim'
                                        * 故障等级限扭发电功率
                                        */
float32 VAR_TpcBlk_IsSum_f32;          /* '<S105>/Chart' */
float32 VAR_TpcCod_GenTrqLim_f32;      /* '<S34>/GetMaxValue'
                                        * 发电扭矩限值
                                        */
float32 VAR_TpcCod_ElecTrqLim_f32;     /* '<S33>/GetMinValue'
                                        * 电动扭矩限值
                                        */
float32 VAR_TpcCod_CoolantFlowReq_f32; /* '<S7>/Chart' */
sint16 VAR_TpcTmp_tCoolTempFlt_u16;    /* '<S109>/Data Type Conversion' */
sint16 VAR_TpcTmp_TCoolStableDiff_u16; /* '<S202>/Switch2' */
sint16 VAR_TpcTmp_tDbcTempFlt_u16;     /* '<S209>/Data Type Conversion' */
sint16 VAR_TpcTmp_TDbcStableDiff_u16;  /* '<S209>/Switch2' */
sint16 VAR_TpcTmp_tDbcRiseTempFlt_u16; /* '<S220>/Data Type Conversion' */
sint16 VAR_TpcTmp_TDbcRiseStableDiff_u16;/* '<S220>/Switch2' */
sint16 VAR_TpcTmp_tIgbtTempFlt_u16;    /* '<S236>/Data Type Conversion' */
sint16 VAR_TpcTmp_TIgbtStableDiff_u16; /* '<S236>/Switch2' */
sint16 VAR_TpcTmp_tIgbtRiseTempFlt_u16;/* '<S241>/Data Type Conversion' */
sint16 VAR_TpcTmp_TIgbtRiseStableDiff_u16;/* '<S241>/Switch2' */
sint16 VAR_TpcMot_tSttrTempFlt_u16;    /* '<S132>/Data Type Conversion' */
sint16 VAR_TpcMot_TsttrStableDiff_u16; /* '<S132>/Switch2' */
uint8 VAR_TpcSmp_SpdOvHiLimErrState_u8;/* '<S186>/Add3'
                                        * DEM触发状态_超速故障
                                        */
uint8 VAR_TpcSmp_SpdOvHiWarnState_u8;  /* '<S186>/Add2'
                                        * DEM触发状态_超速报警
                                        */
uint8 VAR_TpcTmp_TCoolantOvHiWarnState_u8;/* '<S199>/Add'
                                           * DEM触发状态_冷却水过温报警
                                           */
uint8 VAR_TpcTmp_TDbcOvHiWarnState_u8; /* '<S210>/Add'
                                        * DEM触发状态_DBC过温报警
                                        */
uint8 VAR_TpcTmp_TDbcOvLoWarnState_u8; /* '<S210>/Add1'
                                        * DEM触发状态_DBC温度过低报警
                                        */
uint8 VAR_TpcTmp_TDbcUHiLimErrState_u8;/* '<S210>/Add2'
                                        * DEM触发状态_U相过温故障
                                        */
uint8 VAR_TpcTmp_TDbcULoLimErrState_u8;/* '<S210>/Add3'
                                        * DEM触发状态_U相温度过低故障
                                        */
uint8 VAR_TpcTmp_TDbcVHiLimErrState_u8;/* '<S210>/Add4'
                                        * DEM触发状态_V相过温故障
                                        */
uint8 VAR_TpcTmp_TDbcVLoLimErrState_u8;/* '<S210>/Add5'
                                        * DEM触发状态_V相温度过低故障
                                        */
uint8 VAR_TpcTmp_TDbcWHiLimErrState_u8;/* '<S210>/Add6'
                                        * DEM触发状态_W相过温故障
                                        */
uint8 VAR_TpcTmp_TDbcWLoLimErrState_u8;/* '<S210>/Add7'
                                        * DEM触发状态_W相温度过低故障
                                        */
uint8 VAR_TpcTmp_TDrvBoardOvHiWarnState_u8;/* '<S227>/Add'
                                            * DEM触发状态_驱动板过温报警
                                            */
uint8 VAR_TpcTmp_TIGBTOvHiErrState_u8; /* '<S230>/Add2' */
uint8 VAR_TpcTmp_TIGBTOvHiWarnState_u8;/* '<S230>/Add' */
uint8 VAR_TpcTmp_TIGBTOvLoWarnState_u8;/* '<S230>/Add1' */
uint8 VAR_TpcMot_TSttrOvHiLimErrState_u8;/* '<S126>/Add1'
                                          * DEM触发状态_定子过温故障
                                          */
uint8 VAR_TpcMot_TSttrOvHiWarnState_u8;/* '<S126>/Add'
                                        * DEM触发状态_定子过温报警
                                        */
uint8 VAR_TpcMot_TSttrOvLoWarnState_u8;/* '<S126>/Add2'
                                        * DEM触发状态_定子温度过低报警
                                        */
uint8 VAR_TpcSmp_iDcLnkOvCLimErrState_u8;/* '<S146>/Add1'
                                          * DEM触发状态_过流故障
                                          */
uint8 VAR_TpcSmp_iDcLnkOvcWarnState_u8;/* '<S146>/Add'
                                        * DEM触发状态_过流报警
                                        */
uint8 VAR_TpcSmp_uDcLnkOvVLimErrState_u8;/* '<S170>/Add1'
                                          * DEM触发状态_过压故障
                                          */
uint8 VAR_TpcSmp_uDcLnkOvWarnState_u8; /* '<S170>/Add'
                                        * DEM触发状态_过压报警
                                        */
uint8 VAR_TpcSmp_uDcLnkUnVLimErrState_u8;/* '<S178>/Add1'
                                          * DEM触发状态_欠压故障
                                          */
uint8 VAR_TpcSmp_uDcLnkUnvWarnState_u8;/* '<S178>/Add'
                                        * DEM触发状态_欠压报警
                                        */
uint8 VAR_TpcTmp_tRiseIGBTOperationMode_u8;/* '<S235>/PowerSaveMod_tRiseIGBT' */
uint8 VAR_TpcTmp_tIGBTOperationMode_u8;/* '<S234>/PowerSaveMod_tIGBT' */
uint8 VAR_TpcTmp_tRiseDbcOperationMode_u8;/* '<S217>/PowerSaveMod_tRiseDbc' */
uint8 VAR_TpcTmp_tDbcOperationMode_u8; /* '<S216>/PowerSaveMod_tDbc' */
uint8 VAR_TpcTmp_tCoolantOperationMode_u8;/* '<S203>/PowerSaveMod_tCoolant' */
uint8 VAR_TpcMot_tSttrOperationMode_u8;/* '<S131>/PowerSaveMod_tSttr' */
uint8 VAR_TpcMot_tRiseSttrOperationMode_u8;/* '<S130>/PowerSaveMod_tRiseIGBT' */
boolean VAR_TpcTmp_flgTrqLimTcoolantActv_b;/* '<S201>/Relational Operator'
                                            * 冷却水温度限扭触发状态标志位
                                            */
boolean VAR_TpcTmp_flgTrqLimTdbcActv_b;/* '<S211>/Relational Operator'
                                        * Dbc温度限扭触发状态标志位
                                        */
boolean VAR_TpcTmp_flgTrqLimTdrvboardActv_b;/* '<S229>/Relational Operator'
                                             * 驱动板温度限扭触发状态标志位
                                             */
boolean VAR_TpcTmp_flgTrqLimTIGBTActv_b;/* '<S237>/Relational Operator' */
boolean VAR_TpcMot_flgTrqLimTsttrActv_b;/* '<S133>/Relational Operator'
                                         * 定子温度限扭触发状态标志位
                                         */
boolean VAR_TpcSmp_flgLinearDertOvrCurtElec_b;/* '<S151>/Relational Operator'
                                               * 母线过流线性降电动功率触发状态标志位
                                               */
boolean VAR_TpcSmp_flgPIDertOvrCurtElec_b;/* '<S155>/Relational Operator5'
                                           * 母线过流PI降电动功率触发状态标志位
                                           */
boolean VAR_TpcSmp_flgElecPwrLimOvrCurtActv_b;/* '<S154>/Relational Operator1'
                                               * 母线过流降电动功率触发状态标志
                                               */
boolean VAR_TpcSmp_flgLinearDertOveCurtGen_b;/* '<S160>/Relational Operator'
                                              * 母线过流线性降发电功率触发状态标志位
                                              */
boolean VAR_TpcSmp_flgPIDertOvrCurtGen_b;/* '<S164>/Relational Operator5'
                                          * 母线过流PI降发电功率触发状态标志位
                                          */
boolean VAR_TpcSmp_flgGenPwrLimCurtActv_b;/* '<S163>/Relational Operator1'
                                           * 母线过流降发电功率触发状态标志
                                           */
boolean VAR_TpcSmp_flgLinearDertOvrVoltGen_b;/* '<S171>/Relational Operator'
                                              * 母线过压线性降发电功率触发状态标志位
                                              */
boolean VAR_TpcMot_flgStartExcLimRamp_b;/* '<S116>/Switch2' */
boolean VAR_TpcSmp_flgPIDertOvrVoltGen_b;/* '<S174>/Relational Operator5'
                                          * 母线过压PI降发电功率触发状态标志位
                                          */
boolean VAR_TpcSmp_flgGenPwrLimOvrVoltActv_b;/* '<S173>/Relational Operator1'
                                              * 母线过压降发电功率触发状态标志
                                              */
boolean VAR_TpcSmp_flgLinearDertUdrVoltElec_b;/* '<S179>/Relational Operator'
                                               * 母线欠压线性降电动功率触发状态标志位
                                               */
boolean VAR_TpcSmp_flgPIDertUdrVoltElec_b;/* '<S182>/Relational Operator5'
                                           * 母线欠压PI降电动功率触发状态标志位
                                           */
boolean VAR_TpcSmp_flgElecPwrLimUdrVoltActv_b;/* '<S177>/Logical Operator1'
                                               * 母线欠压降电动功率触发状态标志
                                               */
boolean VAR_TpcCod_flgMotorElecMode_b; /* '<S8>/Logical Operator'
                                        * 电机处于电动模式标志位
                                        */
boolean VAR_TpcFuv_FimTrqLimLv1_b;     /* '<S112>/Logical Operator'
                                        * 一级故障限扭矩FIM状态
                                        */
boolean VAR_TpcFuv_FimTrqLimLv2_b;     /* '<S112>/Logical Operator1'
                                        * 二级故障限扭矩FIM状态
                                        */
boolean VAR_TpcFuv_FimTrqLimLv3_b;     /* '<S112>/Logical Operator2'
                                        * 三级故障限扭矩FIM状态
                                        */
boolean VAR_TpcFuv_FimTrqLimLv4_b;     /* '<S112>/Logical Operator3'
                                        * 四级故障限扭矩FIM状态
                                        */
boolean VAR_TpcFuv_FimPwrLimLv1_b;     /* '<S112>/Logical Operator4'
                                        * 一级故障限功率FIM状态
                                        */
boolean VAR_TpcFuv_FimPwrLimLv2_b;     /* '<S112>/Logical Operator5'
                                        * 二级故障限功率FIM状态
                                        */
boolean VAR_TpcFuv_FimPwrLimLv3_b;     /* '<S112>/Logical Operator6'
                                        * 三级故障限功率FIM状态
                                        */
boolean VAR_TpcFuv_FimPwrLimLv4_b;     /* '<S112>/Logical Operator7'
                                        * 四级故障限功率FIM状态
                                        */
boolean VAR_TpcSmp_flgElecTrqLimOvrSpdActv_b;/* '<S185>/Relational Operator5'
                                              * 超速降电动扭矩触发状态标志位
                                              */
boolean VAR_TpcSmp_flgGenTrqLimOvrSpdActv_b;/* '<S185>/Relational Operator7'
                                             * 超速降发电扭矩触发状态标志位
                                             */
boolean VAR_tpccod_flgMaxDertExCTrq_b; /* '<S56>/Switch' */
boolean VAR_tpccod_flgMaxDertStrTemp_b;/* '<S64>/Switch1' */
boolean VAR_tpccod_flgMaxDertTempDBC_b;/* '<S61>/Switch2' */
boolean VAR_tpccod_flgMaxDertTCoolant_b;/* '<S60>/Switch3' */
boolean VAR_tpccod_flgMaxDertTDrvBoard_b;/* '<S62>/Switch4' */
boolean VAR_tpccod_flgMaxDertTIGBT_b;  /* '<S63>/Switch4' */
boolean VAR_tpccod_flgMaxDertMtrSpd_b; /* '<S58>/Switch5' */
boolean VAR_tpccod_flgMaxDertOvrIdc_b; /* '<S57>/Switch6' */
boolean VAR_tpccod_flgMaxDertUndrUdc_b;/* '<S65>/Switch7' */
boolean VAR_tpccod_flgMaxDertOvrUdc_b; /* '<S59>/Switch8' */
boolean VAR_tpccod_flgMaxDertCAN_b;    /* '<S66>/Relational Operator' */
boolean VAR_tpccod_flgMinDertExCTrq_b; /* '<S56>/Switch9' */
boolean VAR_tpccod_flgMinDertStrTemp_b;/* '<S64>/Switch10' */
boolean VAR_tpccod_flgMinDertTempDBC_b;/* '<S61>/Switch11' */
boolean VAR_tpccod_flgMinDertTCoolant_b;/* '<S60>/Switch12' */
boolean VAR_tpccod_flgMinDertTDrvBoard_b;/* '<S62>/Switch13' */
boolean VAR_tpccod_flgMinDertTIGBT_b;  /* '<S63>/Switch13' */
boolean VAR_tpccod_flgMinDertMtrSpd_b; /* '<S58>/Switch14' */
boolean VAR_tpccod_flgMinDertOvrIdc_b; /* '<S57>/Switch15' */
boolean VAR_tpccod_flgMinDertUndrUdc_b;/* '<S65>/Switch16' */
boolean VAR_tpccod_flgMinDertOvrUdc_b; /* '<S59>/Switch17' */
boolean VAR_tpccod_flgMinDertCAN_b;    /* '<S67>/Relational Operator' */

/* Exported data definition */
#pragma section ".rodata.Calib_32"

/* Definition for custom storage class: iEDS_Parameter */
const volatile uint16 CAL_TpcBlk_BlkRevTimSet_u16 = 3000U;
                       /* Referenced by: '<S105>/CAL_TpcBlk_BlkRevTimSet_u16' */
const volatile uint16 CAL_TpcBlk_BlkTimSet_u16 = 3000U;
                          /* Referenced by: '<S105>/CAL_TpcBlk_BlkTimSet_u16' */
const volatile float32 CAL_TpcBlk_MtrBlkIsFirstSet_f32 = 200.0F;/* Referenced by:
                                                                 * '<S105>/Chart'
                                                                 * '<S105>/CAL_TpcBlk_MtrBlkIsFirstSet_f32'
                                                                 */
const volatile float32 CAL_TpcBlk_MtrBlkIsSecondSet_f32 = 180.0F;/* Referenced by:
                                                                  * '<S105>/Chart'
                                                                  * '<S105>/CAL_TpcBlk_MtrBlkIsSecondSet_f32'
                                                                  */
const volatile float32 CAL_TpcBlk_MtrBlkSpdHighSet_f32 = 30.0F;
                   /* Referenced by: '<S105>/CAL_TpcBlk_MtrBlkSpdHighSet_f32' */
const volatile float32 CAL_TpcBlk_MtrBlkSpdLowSet_f32 = 20.0F;
                    /* Referenced by: '<S105>/CAL_TpcBlk_MtrBlkSpdLowSet_f32' */
const volatile float32 CAL_TpcBlk_TrqBlkStab_f32 = 120.0F;
                         /* Referenced by: '<S105>/CAL_TpcBlk_TrqBlkStab_f32' */
const volatile float32 CAL_TpcBlk_TrqDecRamp_f32 = 1.0F;
                         /* Referenced by: '<S105>/CAL_TpcBlk_TrqDecRamp_f32' */
const volatile float32 CAL_TpcBlk_TrqIncRamp_f32 = 1.0F;
                         /* Referenced by: '<S105>/CAL_TpcBlk_TrqIncRamp_f32' */
const volatile boolean CAL_TpcBlk_flgEnBlkFun_b = 0;
                          /* Referenced by: '<S105>/CAL_TpcBlk_flgEnBlkFun_b' */
const volatile uint16 CAL_TpcCod_CntHysteresislop_u16 = 3000U;/* Referenced by: '<S7>/Chart' */
const volatile float32 CAL_TpcCod_CoolFlow1LReq_f32 = 1.0F;
                        /* Referenced by: '<S7>/CAL_TpcCod_CoolFlow1LReq_f32' */
const volatile float32 CAL_TpcCod_CoolFlow2LTableX_Udc_af32[5] = { 100.0F,
  200.0F, 300.0F, 400.0F, 500.0F } ;   /* Referenced by: '<S7>/CoolantFlow2L' */

const volatile float32 CAL_TpcCod_CoolFlow2LTableY_Spd_af32[8] = { 0.0F, 2000.0F,
  4000.0F, 6000.0F, 10000.0F, 12000.0F, 14000.0F, 16000.0F } ;/* Referenced by: '<S7>/CoolantFlow2L' */

const volatile float32 CAL_TpcCod_CoolFlow2LTableZ_Trq_af32[40] = { 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;/* Referenced by: '<S7>/CoolantFlow2L' */

const volatile float32 CAL_TpcCod_CoolFlow4LTableX_Udc_af32[5] = { 100.0F,
  200.0F, 300.0F, 400.0F, 500.0F } ;   /* Referenced by: '<S7>/CoolantFlow4L' */

const volatile float32 CAL_TpcCod_CoolFlow4LTableY_Spd_af32[8] = { 0.0F, 2000.0F,
  4000.0F, 6000.0F, 10000.0F, 12000.0F, 14000.0F, 16000.0F } ;/* Referenced by: '<S7>/CoolantFlow4L' */

const volatile float32 CAL_TpcCod_CoolFlow4LTableZ_Trq_af32[40] = { 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;/* Referenced by: '<S7>/CoolantFlow4L' */

const volatile float32 CAL_TpcCod_CoolFlow6LTableX_Udc_af32[5] = { 100.0F,
  200.0F, 300.0F, 400.0F, 500.0F } ;   /* Referenced by: '<S7>/CoolantFlow6L' */

const volatile float32 CAL_TpcCod_CoolFlow6LTableY_Spd_af32[8] = { 0.0F, 2000.0F,
  4000.0F, 6000.0F, 10000.0F, 12000.0F, 14000.0F, 16000.0F } ;/* Referenced by: '<S7>/CoolantFlow6L' */

const volatile float32 CAL_TpcCod_CoolFlow6LTableZ_Trq_af32[40] = { 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;/* Referenced by: '<S7>/CoolantFlow6L' */

const volatile boolean CAL_TpcCod_FlgUseTrqLimRampSet_b = 0;
                    /* Referenced by: '<S8>/CAL_TpcCod_FlgUseTrqLimRampSet_b' */
const volatile boolean CAL_TpcCod_IGBTSampErr_b = 0;
                            /* Referenced by: '<S7>/CAL_TpcCod_IGBTSampErr_b' */
const volatile boolean CAL_TpcCod_MotorSampErr_b = 0;
                           /* Referenced by: '<S7>/CAL_TpcCod_MotorSampErr_b' */
const volatile boolean CAL_TpcCod_MotorStallWarn_b = 0;
                         /* Referenced by: '<S7>/CAL_TpcCod_MotorStallWarn_b' */
const volatile float32 CAL_TpcCod_NTCHighTemp_f32 = 15.0F;
                         /* Referenced by: '<S16>/CAL_TpcCod_NTCHighTemp_f32' */
const volatile float32 CAL_TpcCod_NTCLowTemp_f32 = 10.0F;
                          /* Referenced by: '<S16>/CAL_TpcCod_NTCLowTemp_f32' */
const volatile float32 CAL_TpcCod_NegSpdDirStop_f32 = -10.0F;
                       /* Referenced by: '<S45>/CAL_TpcCod_NegSpdDirStop_f32' */

/* 电机转速判定为0阈值下限 */
const volatile float32 CAL_TpcCod_NegTrqDirStop_f32 = -3.0F;
                       /* Referenced by: '<S46>/CAL_TpcCod_NegTrqDirStop_f32' */

/* 电机扭矩判定为0阈值下限 */
const volatile float32 CAL_TpcCod_PosSpdDirStop_f32 = 10.0F;
                       /* Referenced by: '<S45>/CAL_TpcCod_PosSpdDirStop_f32' */

/* 电机转速判定为0阈值上限 */
const volatile float32 CAL_TpcCod_PosSpdHold_f32 = 200.0F;/* Referenced by:
                                                           * '<S17>/Chart'
                                                           * '<S18>/Chart'
                                                           * '<S24>/CAL_TpcCod_PosSpdHold_f32'
                                                           * '<S26>/CAL_TpcCod_PosSpdHold_f32'
                                                           */

/* 扭矩限值Mapping的转速阈值下限 */
const volatile float32 CAL_TpcCod_PosSpdStart_f32 = 300.0F;/* Referenced by:
                                                            * '<S17>/Chart'
                                                            * '<S18>/Chart'
                                                            * '<S24>/CAL_TpcCod_PosSpdStart_f32'
                                                            * '<S26>/CAL_TpcCod_PosSpdStart_f32'
                                                            */

/* 扭矩限值Mapping的转速阈值上限 */
const volatile float32 CAL_TpcCod_PosTrqDirStop_f32 = 3.0F;
                       /* Referenced by: '<S46>/CAL_TpcCod_PosTrqDirStop_f32' */

/* 电机扭矩判定为0阈值上限 */
const volatile float32 CAL_TpcCod_PowIncRatLim_f32 = 20.0F;/* Referenced by: '<S7>/Chart' */
const volatile float32 CAL_TpcCod_TrqRelay_f32 = 10.0F;/* Referenced by: '<S7>/Chart' */
const volatile float32 CAL_TpcFuv_CofPwrLimLv1_f32 = 0.9F;
                       /* Referenced by: '<S111>/CAL_TpcFuv_CofPwrLimLv1_f32' */

/* 一级故障功率限值系数 */
const volatile float32 CAL_TpcFuv_CofPwrLimLv2_f32 = 0.5F;
                       /* Referenced by: '<S111>/CAL_TpcFuv_CofPwrLimLv2_f32' */

/* 二级故障功率限值系数 */
const volatile float32 CAL_TpcFuv_CofPwrLimLv3_f32 = 0.2F;
                       /* Referenced by: '<S111>/CAL_TpcFuv_CofPwrLimLv3_f32' */

/* 三级故障功率限值系数 */
const volatile float32 CAL_TpcFuv_CofPwrLimLv4_f32 = 0.0F;
                       /* Referenced by: '<S111>/CAL_TpcFuv_CofPwrLimLv4_f32' */

/* 四级故障功率限值系数 */
const volatile float32 CAL_TpcFuv_CofTrqLimLv1_f32 = 0.9F;
                       /* Referenced by: '<S111>/CAL_TpcFuv_CofTrqLimLv1_f32' */

/* 一级故障扭矩限值系数 */
const volatile float32 CAL_TpcFuv_CofTrqLimLv2_f32 = 0.5F;
                       /* Referenced by: '<S111>/CAL_TpcFuv_CofTrqLimLv2_f32' */

/* 二级故障扭矩限值系数 */
const volatile float32 CAL_TpcFuv_CofTrqLimLv3_f32 = 0.2F;
                       /* Referenced by: '<S111>/CAL_TpcFuv_CofTrqLimLv3_f32' */

/* 三级故障扭矩限值系数 */
const volatile float32 CAL_TpcFuv_CofTrqLimLv4_f32 = 0.0F;
                       /* Referenced by: '<S111>/CAL_TpcFuv_CofTrqLimLv4_f32' */

/* 四级故障扭矩限值系数 */
const volatile float32 CAL_TpcMot_ExCElecTableX_Udc_af32[10] = { 0.0F, 100.0F,
  150.0F, 210.0F, 280.0F, 320.0F, 350.0F, 450.0F, 480.0F, 485.0F } ;
                                      /* Referenced by: '<S116>/ElecExCTable' */

/* 外特性查表母线电压输入-电动模式 */
const volatile float32 CAL_TpcMot_ExCElecTableY_Spd_af32[17] = { 0.0F, 1000.0F,
  2000.0F, 3000.0F, 4000.0F, 5000.0F, 6000.0F, 7000.0F, 8000.0F, 9000.0F,
  10000.0F, 11000.0F, 12000.0F, 13000.0F, 14000.0F, 15000.0F, 16000.0F } ;
                                      /* Referenced by: '<S116>/ElecExCTable' */

/* 外特性查表电机转速输入-电动模式 */
const volatile float32 CAL_TpcMot_ExCElecTableZ_Trq_af32[170] = { 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 295.0F, 295.0F,
  290.0F, 255.0F, 185.0F, 150.0F, 125.0F, 105.0F, 85.0F, 75.0F, 65.0F, 57.0F,
  50.0F, 42.0F, 35.0F, 20.0F, 20.0F, 305.0F, 305.0F, 300.0F, 293.0F, 238.0F,
  210.0F, 190.0F, 150.0F, 130.0F, 110.0F, 95.0F, 85.0F, 75.0F, 65.0F, 60.0F,
  50.0F, 40.0F, 305.0F, 305.0F, 305.0F, 303.0F, 298.0F, 262.0F, 218.0F, 183.0F,
  155.0F, 133.0F, 116.0F, 103.0F, 92.0F, 83.0F, 76.0F, 68.0F, 63.0F, 305.0F,
  305.0F, 305.0F, 303.0F, 300.0F, 282.0F, 243.0F, 208.0F, 176.0F, 152.0F, 133.0F,
  118.0F, 106.0F, 93.0F, 85.0F, 78.0F, 72.0F, 305.0F, 305.0F, 305.0F, 303.0F,
  300.0F, 290.0F, 244.0F, 207.0F, 180.0F, 160.0F, 144.0F, 131.0F, 120.0F, 111.0F,
  103.0F, 96.0F, 90.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;
                                      /* Referenced by: '<S116>/ElecExCTable' */

/* 外特性查表扭矩输出-电动模式 */
const volatile float32 CAL_TpcMot_ExCGenTableX_Udc_af32[10] = { 0.0F, 100.0F,
  150.0F, 210.0F, 280.0F, 320.0F, 350.0F, 450.0F, 480.0F, 485.0F } ;/* Referenced by: '<S116>/GenExCTable' */

/* 外特性查表母线电压输入-发电模式 */
const volatile float32 CAL_TpcMot_ExCGenTableY_Spd_af32[17] = { 0.0F, 1000.0F,
  2000.0F, 3000.0F, 4000.0F, 5000.0F, 6000.0F, 7000.0F, 8000.0F, 9000.0F,
  10000.0F, 11000.0F, 12000.0F, 13000.0F, 14000.0F, 15000.0F, 16000.0F } ;/* Referenced by: '<S116>/GenExCTable' */

/* 外特性查表电机转速输入-发电模式 */
const volatile float32 CAL_TpcMot_ExCGenTableZ_Trq_af32[170] = { 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 295.0F, 295.0F,
  290.0F, 255.0F, 185.0F, 150.0F, 125.0F, 105.0F, 85.0F, 75.0F, 65.0F, 57.0F,
  50.0F, 42.0F, 35.0F, 20.0F, 20.0F, 305.0F, 305.0F, 300.0F, 293.0F, 238.0F,
  210.0F, 190.0F, 150.0F, 130.0F, 110.0F, 95.0F, 85.0F, 75.0F, 65.0F, 60.0F,
  50.0F, 40.0F, 305.0F, 305.0F, 305.0F, 303.0F, 298.0F, 262.0F, 218.0F, 183.0F,
  155.0F, 133.0F, 116.0F, 103.0F, 92.0F, 83.0F, 76.0F, 68.0F, 63.0F, 305.0F,
  305.0F, 305.0F, 303.0F, 300.0F, 282.0F, 243.0F, 208.0F, 176.0F, 152.0F, 133.0F,
  118.0F, 106.0F, 93.0F, 85.0F, 78.0F, 72.0F, 305.0F, 305.0F, 305.0F, 303.0F,
  300.0F, 290.0F, 244.0F, 207.0F, 180.0F, 160.0F, 144.0F, 131.0F, 120.0F, 111.0F,
  103.0F, 96.0F, 90.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;/* Referenced by: '<S116>/GenExCTable' */

/* 外特性查表扭矩输出-发电模式 */
const volatile float32 CAL_TpcMot_SttrChgTempDownDiff_f32 = -2.0F;/* Referenced by: '<S139>/Constant' */
const volatile float32 CAL_TpcMot_SttrChgTempUpDiff_f32 = 0.1F;/* Referenced by: '<S138>/Constant' */
const volatile float32 CAL_TpcMot_SttrTempAdds_f32 = 1.0F;
                       /* Referenced by: '<S119>/CAL_TpcMot_SttrTempAdds_f32' */
const volatile float32 CAL_TpcMot_SttrTempDecDiff_f32 = -2.0F;
                    /* Referenced by: '<S119>/CAL_TpcMot_SttrTempDecDiff_f32' */

/* 定子温度下降步长 */
const volatile float32 CAL_TpcMot_SttrTempKp_f32 = 0.2F;
                         /* Referenced by: '<S119>/CAL_TpcMot_SttrTempKp_f32' */
const volatile float32 CAL_TpcMot_SttrTempMinus_f32 = -1.0F;
                      /* Referenced by: '<S119>/CAL_TpcMot_SttrTempMinus_f32' */
const volatile float32 CAL_TpcMot_SttrTempRiseDiff_f32 = 2.0F;
                   /* Referenced by: '<S119>/CAL_TpcMot_SttrTempRiseDiff_f32' */
const volatile boolean CAL_TpcMot_flgPwrRefSwt_b = 1;
                         /* Referenced by: '<S117>/CAL_TpcMot_flgPwrRefSwt_b' */

/* 使用外特性功率标志-tpcmot */
const volatile boolean CAL_TpcMot_flgTrqRefSwt_b = 1;
                         /* Referenced by: '<S117>/CAL_TpcMot_flgTrqRefSwt_b' */

/* 使用外特性扭矩标志-tpcmot */
const volatile float32 CAL_TpcMot_tRiseSttrDertSave1TableX_tSttr_af32[9] = {
  0.0F, 30.0F, 80.0F, 90.0F, 95.0F, 100.0F, 105.0F, 110.0F, 120.0F } ;
                    /* Referenced by: '<S130>/SttrRiseTempDeratingSave1Table' */

const volatile float32 CAL_TpcMot_tRiseSttrDertSave1TableY_Cof_af32[9] = { 1.0F,
  1.0F, 1.0F, 0.8F, 0.6F, 0.4F, 0.2F, 0.0F, 0.0F } ;
                    /* Referenced by: '<S130>/SttrRiseTempDeratingSave1Table' */

const volatile float32 CAL_TpcMot_tRiseSttrDertSave2TableX_tSttr_af32[9] = {
  0.0F, 30.0F, 80.0F, 90.0F, 95.0F, 100.0F, 105.0F, 110.0F, 120.0F } ;
                    /* Referenced by: '<S130>/SttrRiseTempDeratingSave2Table' */

const volatile float32 CAL_TpcMot_tRiseSttrDertSave2TableY_Cof_af32[9] = { 1.0F,
  1.0F, 1.0F, 0.8F, 0.6F, 0.4F, 0.2F, 0.0F, 0.0F } ;
                    /* Referenced by: '<S130>/SttrRiseTempDeratingSave2Table' */

const volatile float32 CAL_TpcMot_tRiseSttrTraNormalToSave1_f32 = 100.0F;
                            /* Referenced by: '<S130>/PowerSaveMod_tRiseIGBT' */
const volatile float32 CAL_TpcMot_tRiseSttrTraSave1ToNormal_f32 = 105.0F;
                            /* Referenced by: '<S130>/PowerSaveMod_tRiseIGBT' */
const volatile float32 CAL_TpcMot_tRiseSttrTraSave1ToSave2_f32 = 107.0F;
                            /* Referenced by: '<S130>/PowerSaveMod_tRiseIGBT' */
const volatile float32 CAL_TpcMot_tRiseSttrTraSave2ToOverheating_f32 = 109.0F;
                            /* Referenced by: '<S130>/PowerSaveMod_tRiseIGBT' */
const volatile float32 CAL_TpcMot_tSttrDertSave1TableX_tSttr_af32[9] = { -50.0F,
  0.0F, 170.0F, 172.0F, 174.0F, 176.0F, 178.0F, 180.0F, 182.0F } ;
                        /* Referenced by: '<S131>/SttrTempDeratingSave1Table' */

const volatile float32 CAL_TpcMot_tSttrDertSave1TableY_Cof_af32[9] = { 1.0F,
  1.0F, 1.0F, 0.8F, 0.6F, 0.4F, 0.2F, 0.0F, 0.0F } ;
                        /* Referenced by: '<S131>/SttrTempDeratingSave1Table' */

const volatile float32 CAL_TpcMot_tSttrDertSave2TableX_tSttr_af32[9] = { -50.0F,
  0.0F, 170.0F, 172.0F, 174.0F, 176.0F, 178.0F, 180.0F, 182.0F } ;
                        /* Referenced by: '<S131>/SttrTempDeratingSave2Table' */

const volatile float32 CAL_TpcMot_tSttrDertSave2TableY_Cof_af32[9] = { 1.0F,
  1.0F, 1.0F, 0.8F, 0.6F, 0.4F, 0.2F, 0.0F, 0.0F } ;
                        /* Referenced by: '<S131>/SttrTempDeratingSave2Table' */

const volatile float32 CAL_TpcMot_tSttrHiLim_f32 = 179.0F;
                         /* Referenced by: '<S126>/CAL_TpcMot_tSttrHiLim_f32' */

/* 定子温度过高故障阈值 */
const volatile float32 CAL_TpcMot_tSttrLoLim_f32 = -40.0F;
                         /* Referenced by: '<S126>/CAL_TpcMot_tSttrLoLim_f32' */

/* 定子温度过低报警阈值 */
const volatile float32 CAL_TpcMot_tSttrTraNormalToSave1_f32 = 170.0F;
                                /* Referenced by: '<S131>/PowerSaveMod_tSttr' */
const volatile float32 CAL_TpcMot_tSttrTraSave1ToNormal_f32 = 165.0F;
                                /* Referenced by: '<S131>/PowerSaveMod_tSttr' */
const volatile float32 CAL_TpcMot_tSttrTraSave1ToSave2_f32 = 176.0F;
                                /* Referenced by: '<S131>/PowerSaveMod_tSttr' */
const volatile float32 CAL_TpcMot_tSttrTraSave2ToOverheating_f32 = 179.0F;
                                /* Referenced by: '<S131>/PowerSaveMod_tSttr' */
const volatile float32 CAL_TpcMot_tSttrTrqLimRamp_f32 = 0.05F;/* Referenced by:
                                                               * '<S119>/CAL_TpcMot_tSttrTrqLimRamp_f1'
                                                               * '<S119>/CAL_TpcMot_tSttrTrqLimRamp_f32'
                                                               */

/* 定子温度扭矩限值slop */
const volatile uint8 CAL_TpcSmp_CntElecOvrCurt_u8 = 10U;
                      /* Referenced by: '<S149>/CAL_TpcSmp_CntElecOvrCurt_u8' */

/* 电动过流derating触发标志Debounce模块计数 */
const volatile uint8 CAL_TpcSmp_CntElecUdrVolt_u8 = 10U;
                      /* Referenced by: '<S177>/CAL_TpcSmp_CntElecUdrVolt_u8' */

/* 电动欠压derating触发标志Debounce模块计数 */
const volatile uint8 CAL_TpcSmp_CntGenOvrCurt_u8 = 10U;
                       /* Referenced by: '<S158>/CAL_TpcSmp_CntGenOvrCurt_u8' */

/* 发电过流derating触发标志Debounce模块计数 */
const volatile uint8 CAL_TpcSmp_CntGenOvrVolt_u8 = 10U;
                       /* Referenced by: '<S169>/CAL_TpcSmp_CntGenOvrVolt_u8' */

/* 发电过压derating触发标志Debounce模块计数 */
const volatile boolean CAL_TpcSmp_CurtModeSelc_b = 0;/* Referenced by:
                                                      * '<S149>/CAL_TpcSmp_CurtModeSelc_b'
                                                      * '<S158>/CAL_TpcSmp_CurtModeSelc_b'
                                                      */
const volatile float32 CAL_TpcSmp_ElecOvrCurtKi_f32 = 0.5F;
                      /* Referenced by: '<S152>/CAL_TpcSmp_ElecOvrCurtKi_f32' */

/* 电动过流限功率PI模块Ki */
const volatile float32 CAL_TpcSmp_ElecOvrCurtKp_f32 = 1.0F;
                      /* Referenced by: '<S152>/CAL_TpcSmp_ElecOvrCurtKp_f32' */

/* 电动过流限功率PI模块Kp */
const volatile float32 CAL_TpcSmp_ElecOvrCurtypLim_f32 = 100.0F;
                   /* Referenced by: '<S152>/CAL_TpcSmp_ElecOvrCurtypLim_f32' */

/* 电动过流限功率PI模块限幅 */
const volatile float32 CAL_TpcSmp_ElecUdrVoltKi_f32 = 0.5F;
                      /* Referenced by: '<S180>/CAL_TpcSmp_ElecUdrVoltKi_f32' */

/* 电动欠压限功率PI模块Ki */
const volatile float32 CAL_TpcSmp_ElecUdrVoltKp_f32 = 1.0F;
                      /* Referenced by: '<S180>/CAL_TpcSmp_ElecUdrVoltKp_f32' */

/* 电动欠压限功率PI模块Kp */
const volatile float32 CAL_TpcSmp_ElecUdrVoltypLim_f32 = 100.0F;
                   /* Referenced by: '<S180>/CAL_TpcSmp_ElecUdrVoltypLim_f32' */

/* 电动欠压限功率PI模块限幅 */
const volatile uint8 CAL_TpcSmp_FacElecOvrCurt_u8 = 1U;
                      /* Referenced by: '<S149>/CAL_TpcSmp_FacElecOvrCurt_u8' */

/* 电动过流derating触发标志Debounce模块系数 */
const volatile uint8 CAL_TpcSmp_FacElecUdrVolt_u8 = 1U;
                      /* Referenced by: '<S177>/CAL_TpcSmp_FacElecUdrVolt_u8' */

/* 电动欠压derating触发标志Debounce模块系数 */
const volatile uint8 CAL_TpcSmp_FacGenOvrCurt_u8 = 1U;
                       /* Referenced by: '<S158>/CAL_TpcSmp_FacGenOvrCurt_u8' */

/* 发电过流derating触发标志Debounce模块系数 */
const volatile uint8 CAL_TpcSmp_FacGenOvrVolt_u8 = 1U;
                       /* Referenced by: '<S169>/CAL_TpcSmp_FacGenOvrVolt_u8' */

/* 发电过压derating触发标志Debounce模块系数 */
const volatile float32 CAL_TpcSmp_GenOvrCurtKi_f32 = 0.5F;
                       /* Referenced by: '<S161>/CAL_TpcSmp_GenOvrCurtKi_f32' */

/* 发电过流限功率PI模块Ki */
const volatile float32 CAL_TpcSmp_GenOvrCurtKp_f32 = 1.0F;
                       /* Referenced by: '<S161>/CAL_TpcSmp_GenOvrCurtKp_f32' */

/* 发电过流限功率PI模块Kp */
const volatile float32 CAL_TpcSmp_GenOvrCurtypLim_f32 = 100.0F;
                    /* Referenced by: '<S161>/CAL_TpcSmp_GenOvrCurtypLim_f32' */

/* 发电过流限功率PI模块限幅 */
const volatile float32 CAL_TpcSmp_GenOvrVoltKi_f32 = 0.5F;
                       /* Referenced by: '<S172>/CAL_TpcSmp_GenOvrVoltKi_f32' */

/* 发电过压限功率PI模块Ki */
const volatile float32 CAL_TpcSmp_GenOvrVoltKp_f32 = 1.0F;
                       /* Referenced by: '<S172>/CAL_TpcSmp_GenOvrVoltKp_f32' */

/* 发电过压限功率PI模块Kp */
const volatile float32 CAL_TpcSmp_GenOvrVoltypLim_f32 = 100.0F;
                    /* Referenced by: '<S172>/CAL_TpcSmp_GenOvrVoltypLim_f32' */

/* 发电过压限功率PI模块限幅 */
const volatile float32 CAL_TpcSmp_OvSpdWarnHiLim_f32 = 16200.0F;
                     /* Referenced by: '<S186>/CAL_TpcSmp_OvSpdWarnHiLim_f32' */

/* 电机转速超速报警触发阈值 */
const volatile float32 CAL_TpcSmp_OvSpdWarnLoLim_f32 = 16000.0F;
                     /* Referenced by: '<S186>/CAL_TpcSmp_OvSpdWarnLoLim_f32' */

/* 电机转速超速报警恢复阈值 */
const volatile float32 CAL_TpcSmp_OvrCurtLimElecTableX_iDc_af32[5] = { 10.0F,
  30.0F, 40.0F, 50.0F, 60.0F } ;
                           /* Referenced by: '<S151>/BusCurrentDertElecTable' */

/* 电动过流线性降功率查表电流输入 */
const volatile float32 CAL_TpcSmp_OvrCurtLimElecTableY_Cof_af32[5] = { 0.2F,
  0.2F, 0.6F, 1.0F, 1.0F } ;
                           /* Referenced by: '<S151>/BusCurrentDertElecTable' */

/* 电动过流线性降功率查表derating系数输出 */
const volatile float32 CAL_TpcSmp_OvrCurtLimGenTableX_iDc_af32[5] = { 10.0F,
  30.0F, 40.0F, 50.0F, 60.0F } ;
                            /* Referenced by: '<S160>/BusCurrentDertGenTable' */

/* 发电过流线性降功率查表电流输入 */
const volatile float32 CAL_TpcSmp_OvrCurtLimGenTableY_Cof_af32[5] = { 0.2F, 0.2F,
  0.6F, 1.0F, 1.0F } ;      /* Referenced by: '<S160>/BusCurrentDertGenTable' */

/* 发电过流线性降功率查表derating系数输出 */
const volatile float32 CAL_TpcSmp_OvrSpdQurd1TableX_Spd_af32[7] = { 0.0F, 150.0F,
  6000.0F, 16000.0F, 16200.0F, 17000.0F, 17200.0F } ;
                               /* Referenced by: '<S185>/OvSpdDertQurd1Table' */

/* 超速限扭转速输入_第一象限 */
const volatile float32 CAL_TpcSmp_OvrSpdQurd1TableY_Cof_af32[7] = { 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F } ;
                               /* Referenced by: '<S185>/OvSpdDertQurd1Table' */

/* 超速限扭系数输出_第一象限 */
const volatile float32 CAL_TpcSmp_OvrSpdQurd2TableX_Spd_af32[7] = { 0.0F, 150.0F,
  6000.0F, 16000.0F, 16200.0F, 17000.0F, 17200.0F } ;
                               /* Referenced by: '<S185>/OvSpdDertQurd2Table' */

/* 超速限扭转速输入_第二象限 */
const volatile float32 CAL_TpcSmp_OvrSpdQurd2TableY_Cof_af32[7] = { 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F } ;
                               /* Referenced by: '<S185>/OvSpdDertQurd2Table' */

/* 超速限扭系数输出_第二象限 */
const volatile float32 CAL_TpcSmp_OvrSpdQurd3TableX_Spd_af32[7] = { 0.0F, 150.0F,
  6000.0F, 16000.0F, 16200.0F, 17000.0F, 17200.0F } ;
                               /* Referenced by: '<S185>/OvSpdDertQurd3Table' */

/* 超速限扭转速输入_第三象限 */
const volatile float32 CAL_TpcSmp_OvrSpdQurd3TableY_Cof_af32[7] = { 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F } ;
                               /* Referenced by: '<S185>/OvSpdDertQurd3Table' */

/* 超速限扭系数输出_第三象限 */
const volatile float32 CAL_TpcSmp_OvrSpdQurd4TableX_Spd_af32[7] = { 0.0F, 150.0F,
  6000.0F, 16000.0F, 16200.0F, 17000.0F, 17200.0F } ;
                               /* Referenced by: '<S185>/OvSpdDertQurd4Table' */

/* 超速限扭转速输入_第四象限 */
const volatile float32 CAL_TpcSmp_OvrSpdQurd4TableY_Cof_af32[7] = { 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F } ;
                               /* Referenced by: '<S185>/OvSpdDertQurd4Table' */

/* 超速限扭系数输出_第四象限 */
const volatile float32 CAL_TpcSmp_OvrVoltGenTableX_uDc_af32[5] = { 1.0F, 5.0F,
  15.0F, 30.0F, 80.0F } ;   /* Referenced by: '<S171>/BusVoltageDertGenTable' */

/* 过压线性降功率查表电压输入 */
const volatile float32 CAL_TpcSmp_OvrVoltGenTableY_Cof_af32[5] = { 0.2F, 0.2F,
  0.6F, 1.0F, 1.0F } ;      /* Referenced by: '<S171>/BusVoltageDertGenTable' */

/* 过压线性降功率查表derating系数输出 */
const volatile float32 CAL_TpcSmp_PwrAddMaxGen_f32 = 0.0F;
                       /* Referenced by: '<S161>/CAL_TpcSmp_PwrAddMaxGen_f32' */
const volatile float32 CAL_TpcSmp_PwrAddMax_f32 = 3.0F;
                          /* Referenced by: '<S152>/CAL_TpcSmp_PwrAddMax_f32' */

/* 电动过流测试补偿功率 */
const volatile float32 CAL_TpcSmp_SystemEffiElec_f32 = 1.0F;
                     /* Referenced by: '<S153>/CAL_TpcSmp_SystemEffiElec_f32' */
const volatile float32 CAL_TpcSmp_SystemEffiGen_f32 = 1.0F;
                      /* Referenced by: '<S162>/CAL_TpcSmp_SystemEffiGen_f32' */
const volatile float32 CAL_TpcSmp_ThresOverSpd_f32 = 17500.0F;
                       /* Referenced by: '<S186>/CAL_TpcSmp_ThresOverSpd_f32' */

/* 电机转速超速故障阈值 */
const volatile float32 CAL_TpcSmp_TrqAddMaxGen_f32 = 0.0F;
                       /* Referenced by: '<S161>/CAL_TpcSmp_TrqAddMaxGen_f32' */
const volatile float32 CAL_TpcSmp_TrqAddMax_f32 = 10.0F;
                          /* Referenced by: '<S152>/CAL_TpcSmp_TrqAddMax_f32' */

/* 电动过流测试补偿扭矩 */
const volatile float32 CAL_TpcSmp_UdrVoltElecTableX_uDc_af32[5] = { 10.0F, 40.0F,
  60.0F, 80.0F, 100.0F } ; /* Referenced by: '<S179>/BusVoltageDertElecTable' */

/* 欠压线性降功率查表电压输入 */
const volatile float32 CAL_TpcSmp_UdrVoltElecTableY_Cof_af32[5] = { 0.2F, 0.2F,
  0.6F, 1.0F, 1.0F } ;     /* Referenced by: '<S179>/BusVoltageDertElecTable' */

/* 欠压线性降功率查表derating系数输出 */
const volatile boolean CAL_TpcSmp_flgUsePwrLossGen_b = 0;
                     /* Referenced by: '<S161>/CAL_TpcSmp_flgUsePwrLossGen_b' */
const volatile boolean CAL_TpcSmp_flgUsePwrLoss_b = 0;
                        /* Referenced by: '<S152>/CAL_TpcSmp_flgUsePwrLoss_b' */
const volatile float32 CAL_TpcSmp_iDcLnkMaxMax_f32 = 800.0F;
                       /* Referenced by: '<S143>/CAL_TpcSmp_iDcLnkMaxMax_f32' */

/* 电池允许最大电流最大值 */
const volatile float32 CAL_TpcSmp_iDcLnkMaxMin_f32 = 0.0F;
                       /* Referenced by: '<S143>/CAL_TpcSmp_iDcLnkMaxMin_f32' */

/* 电池允许最大电流最小值 */
const volatile float32 CAL_TpcSmp_iDcLnkMinMax_f32 = 0.0F;
                       /* Referenced by: '<S143>/CAL_TpcSmp_iDcLnkMinMax_f32' */

/* 电池允许最小电流最大值 */
const volatile float32 CAL_TpcSmp_iDcLnkMinMin_f32 = -800.0F;
                       /* Referenced by: '<S143>/CAL_TpcSmp_iDcLnkMinMin_f32' */

/* 电池允许最小电流最小值 */
const volatile float32 CAL_TpcSmp_iDcLnkOvCElecLim_f32 = 560.0F;
                   /* Referenced by: '<S146>/CAL_TpcSmp_iDcLnkOvCElecLim_f32' */

/* 母线电流电动过流故障阈值 */
const volatile float32 CAL_TpcSmp_iDcLnkOvCGenLim_f32 = -560.0F;
                    /* Referenced by: '<S146>/CAL_TpcSmp_iDcLnkOvCGenLim_f32' */

/* 母线电流发电过流故障阈值 */
const volatile uint8 CAL_TpcSmp_nCtlExtReq_u8 = 1U;/* Referenced by: '<S192>/Constant' */

/* VCU请求外部速度环控制 */
const volatile uint8 CAL_TpcSmp_nCtlIntReq_u8 = 9U;/* Referenced by: '<S193>/Constant' */

/* VCU请求内部速度环控制 */
const volatile float32 CAL_TpcSmp_uDcLnkMaxMax_f32 = 550.0F;
                       /* Referenced by: '<S143>/CAL_TpcSmp_uDcLnkMaxMax_f32' */

/* 电池允许最大电压最大值 */
const volatile float32 CAL_TpcSmp_uDcLnkMaxMin_f32 = 0.0F;
                       /* Referenced by: '<S143>/CAL_TpcSmp_uDcLnkMaxMin_f32' */

/* 电池允许最大电压最小值 */
const volatile float32 CAL_TpcSmp_uDcLnkMinMax_f32 = 550.0F;
                       /* Referenced by: '<S143>/CAL_TpcSmp_uDcLnkMinMax_f32' */

/* 电池允许最小电压最大值 */
const volatile float32 CAL_TpcSmp_uDcLnkMinMin_f32 = 0.0F;
                       /* Referenced by: '<S143>/CAL_TpcSmp_uDcLnkMinMin_f32' */

/* 电池允许最小电压最小值 */
const volatile float32 CAL_TpcSmp_uDcLnkOvVLim_f32 = 485.0F;
                       /* Referenced by: '<S170>/CAL_TpcSmp_uDcLnkOvVLim_f32' */

/* 母线电压过压故障阈值 */
const volatile float32 CAL_TpcSmp_uDcLnkUnVLim_f32 = 200.0F;
                       /* Referenced by: '<S178>/CAL_TpcSmp_uDcLnkUnVLim_f32' */

/* 母线电压欠压故障阈值 */
const volatile float32 CAL_TpcTmp_CoolChgTempDownDiff_f32 = -2.0F;/* Referenced by: '<S205>/Constant' */
const volatile float32 CAL_TpcTmp_CoolChgTempUpDiff_f32 = 0.01F;/* Referenced by: '<S204>/Constant' */
const volatile float32 CAL_TpcTmp_CoolTempAdds_f32 = 1.0F;
                       /* Referenced by: '<S200>/CAL_TpcTmp_CoolTempAdds_f32' */
const volatile float32 CAL_TpcTmp_CoolTempDecDiff_f32 = -2.0F;
                    /* Referenced by: '<S200>/CAL_TpcTmp_CoolTempDecDiff_f32' */
const volatile float32 CAL_TpcTmp_CoolTempKp_f32 = 0.2F;
                         /* Referenced by: '<S200>/CAL_TpcTmp_CoolTempKp_f32' */
const volatile float32 CAL_TpcTmp_CoolTempMinus_f32 = -1.0F;
                      /* Referenced by: '<S200>/CAL_TpcTmp_CoolTempMinus_f32' */
const volatile float32 CAL_TpcTmp_CoolTempRiseDiff_f32 = 2.0F;
                   /* Referenced by: '<S200>/CAL_TpcTmp_CoolTempRiseDiff_f32' */
const volatile float32 CAL_TpcTmp_DBCRiseTempAdds_f32 = 1.0F;
                    /* Referenced by: '<S217>/CAL_TpcTmp_DBCRiseTempAdds_f32' */
const volatile float32 CAL_TpcTmp_DBCRiseTempDecDiff_f32 = -2.0F;
                 /* Referenced by: '<S217>/CAL_TpcTmp_DBCRiseTempDecDiff_f32' */
const volatile float32 CAL_TpcTmp_DBCRiseTempKp_f32 = 0.2F;
                      /* Referenced by: '<S217>/CAL_TpcTmp_DBCRiseTempKp_f32' */
const volatile float32 CAL_TpcTmp_DBCRiseTempMinus_f32 = -1.0F;
                   /* Referenced by: '<S217>/CAL_TpcTmp_DBCRiseTempMinus_f32' */
const volatile float32 CAL_TpcTmp_DBCRiseTempRiseDiff_f32 = 2.0F;
                /* Referenced by: '<S217>/CAL_TpcTmp_DBCRiseTempRiseDiff_f32' */
const volatile float32 CAL_TpcTmp_DBCTempAdds_f32 = 1.0F;
                        /* Referenced by: '<S195>/CAL_TpcTmp_DBCTempAdds_f32' */
const volatile float32 CAL_TpcTmp_DBCTempDecDiff_f32 = -2.0F;
                     /* Referenced by: '<S195>/CAL_TpcTmp_DBCTempDecDiff_f32' */
const volatile float32 CAL_TpcTmp_DBCTempKp_f32 = 0.2F;
                          /* Referenced by: '<S195>/CAL_TpcTmp_DBCTempKp_f32' */
const volatile float32 CAL_TpcTmp_DBCTempMinus_f32 = -1.0F;
                       /* Referenced by: '<S195>/CAL_TpcTmp_DBCTempMinus_f32' */
const volatile float32 CAL_TpcTmp_DBCTempRiseDiff_f32 = 2.0F;
                    /* Referenced by: '<S195>/CAL_TpcTmp_DBCTempRiseDiff_f32' */
const volatile float32 CAL_TpcTmp_DbcChgTempDownDiff_f32 = -2.0F;/* Referenced by: '<S226>/Constant' */
const volatile float32 CAL_TpcTmp_DbcChgTempUpDiff_f32 = 0.01F;/* Referenced by: '<S225>/Constant' */
const volatile float32 CAL_TpcTmp_DbcRiseChgTempDownDiff_f32 = -2.0F;/* Referenced by: '<S224>/Constant' */
const volatile float32 CAL_TpcTmp_DbcRiseChgTempUpDiff_f32 = 0.01F;/* Referenced by: '<S223>/Constant' */
const volatile float32 CAL_TpcTmp_IGBRiseTTempAdds_f32 = 1.0F;
                   /* Referenced by: '<S235>/CAL_TpcTmp_IGBRiseTTempAdds_f32' */
const volatile float32 CAL_TpcTmp_IGBTRiseTempDecDiff_f32 = -2.0F;
                /* Referenced by: '<S235>/CAL_TpcTmp_IGBTRiseTempDecDiff_f32' */
const volatile float32 CAL_TpcTmp_IGBTRiseTempKp_f32 = 0.2F;
                     /* Referenced by: '<S235>/CAL_TpcTmp_IGBTRiseTempKp_f32' */
const volatile float32 CAL_TpcTmp_IGBTRiseTempMinus_f32 = -1.0F;
                  /* Referenced by: '<S235>/CAL_TpcTmp_IGBTRiseTempMinus_f32' */
const volatile float32 CAL_TpcTmp_IGBTRiseTempRiseDiff_f32 = 2.0F;
               /* Referenced by: '<S235>/CAL_TpcTmp_IGBTRiseTempRiseDiff_f32' */
const volatile float32 CAL_TpcTmp_IGBTTempAdds_f32 = 1.0F;
                       /* Referenced by: '<S197>/CAL_TpcTmp_IGBTTempAdds_f32' */
const volatile float32 CAL_TpcTmp_IGBTTempDecDiff_f32 = -2.0F;
                    /* Referenced by: '<S197>/CAL_TpcTmp_IGBTTempDecDiff_f32' */
const volatile float32 CAL_TpcTmp_IGBTTempKp_f32 = 0.2F;
                         /* Referenced by: '<S197>/CAL_TpcTmp_IGBTTempKp_f32' */
const volatile float32 CAL_TpcTmp_IGBTTempMinus_f32 = -1.0F;
                      /* Referenced by: '<S197>/CAL_TpcTmp_IGBTTempMinus_f32' */
const volatile float32 CAL_TpcTmp_IGBTTempRiseDiff_f32 = 2.0F;
                   /* Referenced by: '<S197>/CAL_TpcTmp_IGBTTempRiseDiff_f32' */
const volatile float32 CAL_TpcTmp_IgbtChgTempDownDiff_f32 = -2.0F;/* Referenced by: '<S246>/Constant' */
const volatile float32 CAL_TpcTmp_IgbtChgTempUpDiff_f32 = 0.01F;/* Referenced by: '<S245>/Constant' */
const volatile float32 CAL_TpcTmp_IgbtRiseChgTempDownDiff_f32 = -2.0F;/* Referenced by: '<S244>/Constant' */
const volatile float32 CAL_TpcTmp_IgbtRiseChgTempUpDiff_f32 = 0.01F;/* Referenced by: '<S243>/Constant' */
const volatile float32 CAL_TpcTmp_tCoolantDertSave1TableX_tSttr_af32[9] = { 0.0F,
  30.0F, 65.0F, 66.0F, 67.0F, 68.0F, 69.0F, 70.0F, 75.0F } ;
                     /* Referenced by: '<S203>/CoolantTempDeratingSave1Table' */

const volatile float32 CAL_TpcTmp_tCoolantDertSave1TableY_Cof_af32[9] = { 1.0F,
  1.0F, 1.0F, 0.8F, 0.6F, 0.4F, 0.2F, 0.0F, 0.0F } ;
                     /* Referenced by: '<S203>/CoolantTempDeratingSave1Table' */

const volatile float32 CAL_TpcTmp_tCoolantDertSave2TableX_tSttr_af32[9] = { 0.0F,
  30.0F, 65.0F, 66.0F, 67.0F, 68.0F, 69.0F, 70.0F, 75.0F } ;
                     /* Referenced by: '<S203>/CoolantTempDeratingSave2Table' */

const volatile float32 CAL_TpcTmp_tCoolantDertSave2TableY_Cof_af32[9] = { 1.0F,
  1.0F, 1.0F, 0.8F, 0.6F, 0.4F, 0.2F, 0.0F, 0.0F } ;
                     /* Referenced by: '<S203>/CoolantTempDeratingSave2Table' */

const volatile float32 CAL_TpcTmp_tCoolantTraNormalToSave1_f32 = 65.0F;
                             /* Referenced by: '<S203>/PowerSaveMod_tCoolant' */
const volatile float32 CAL_TpcTmp_tCoolantTraSave1ToNormal_f32 = 64.0F;
                             /* Referenced by: '<S203>/PowerSaveMod_tCoolant' */
const volatile float32 CAL_TpcTmp_tCoolantTraSave1ToSave2_f32 = 70.0F;
                             /* Referenced by: '<S203>/PowerSaveMod_tCoolant' */
const volatile float32 CAL_TpcTmp_tCoolantTraSave2ToOverheating_f32 = 75.0F;
                             /* Referenced by: '<S203>/PowerSaveMod_tCoolant' */
const volatile float32 CAL_TpcTmp_tDBCTrqLimRamp_f32 = 0.5F;/* Referenced by:
                                                             * '<S195>/CAL_TpcTmp_tDBCTrqLimRamp_f1'
                                                             * '<S195>/CAL_TpcTmp_tDBCTrqLimRamp_f32'
                                                             */
const volatile float32 CAL_TpcTmp_tDbcDertSave1TableX_tSttr_af32[9] = { 0.0F,
  30.0F, 90.0F, 92.0F, 94.0F, 96.0F, 98.0F, 100.0F, 102.0F } ;
                         /* Referenced by: '<S216>/DbcTempDeratingSave1Table' */

const volatile float32 CAL_TpcTmp_tDbcDertSave1TableY_Cof_af32[9] = { 1.0F, 1.0F,
  1.0F, 0.8F, 0.6F, 0.4F, 0.2F, 0.0F, 0.0F } ;
                         /* Referenced by: '<S216>/DbcTempDeratingSave1Table' */

const volatile float32 CAL_TpcTmp_tDbcDertSave2TableX_tSttr_af32[9] = { 0.0F,
  30.0F, 90.0F, 92.0F, 94.0F, 96.0F, 98.0F, 100.0F, 102.0F } ;
                         /* Referenced by: '<S216>/DbcTempDeratingSave2Table' */

const volatile float32 CAL_TpcTmp_tDbcDertSave2TableY_Cof_af32[9] = { 1.0F, 1.0F,
  1.0F, 0.8F, 0.6F, 0.4F, 0.2F, 0.0F, 0.0F } ;
                         /* Referenced by: '<S216>/DbcTempDeratingSave2Table' */

const volatile float32 CAL_TpcTmp_tDbcTempUHiLim_f32 = 102.0F;
                     /* Referenced by: '<S210>/CAL_TpcTmp_tDbcTempUHiLim_f32' */

/* U相温度超高限 */
const volatile float32 CAL_TpcTmp_tDbcTempULoLim_f32 = -40.0F;
                     /* Referenced by: '<S210>/CAL_TpcTmp_tDbcTempULoLim_f32' */

/* U相温度超低限 */
const volatile float32 CAL_TpcTmp_tDbcTempVHiLim_f32 = 102.0F;
                     /* Referenced by: '<S210>/CAL_TpcTmp_tDbcTempVHiLim_f32' */

/* V相温度超高限 */
const volatile float32 CAL_TpcTmp_tDbcTempVLoLim_f32 = -40.0F;
                     /* Referenced by: '<S210>/CAL_TpcTmp_tDbcTempVLoLim_f32' */

/* V相温度超低限 */
const volatile float32 CAL_TpcTmp_tDbcTempWHiLim_f32 = 102.0F;
                     /* Referenced by: '<S210>/CAL_TpcTmp_tDbcTempWHiLim_f32' */

/* W相温度超高限 */
const volatile float32 CAL_TpcTmp_tDbcTempWLoLim_f32 = -40.0F;
                     /* Referenced by: '<S210>/CAL_TpcTmp_tDbcTempWLoLim_f32' */

/* W相温度超低限 */
const volatile float32 CAL_TpcTmp_tDbcThrPhLoLim_f32 = -35.0F;
                     /* Referenced by: '<S210>/CAL_TpcTmp_tDbcThrPhLoLim_f32' */

/* DBC温度过低报警阈值 */
const volatile float32 CAL_TpcTmp_tDbcTraNormalToSave1_f32 = 90.0F;
                                 /* Referenced by: '<S216>/PowerSaveMod_tDbc' */
const volatile float32 CAL_TpcTmp_tDbcTraSave1ToNormal_f32 = 85.0F;
                                 /* Referenced by: '<S216>/PowerSaveMod_tDbc' */
const volatile float32 CAL_TpcTmp_tDbcTraSave1ToSave2_f32 = 95.0F;
                                 /* Referenced by: '<S216>/PowerSaveMod_tDbc' */
const volatile float32 CAL_TpcTmp_tDbcTraSave2ToOverheating_f32 = 99.0F;
                                 /* Referenced by: '<S216>/PowerSaveMod_tDbc' */
const volatile float32 CAL_TpcTmp_tDrvboardDertTableX_tDrv_af32[9] = { -50.0F,
  0.0F, 50.0F, 100.0F, 120.0F, 125.0F, 130.0F, 140.0F, 150.0F } ;
                         /* Referenced by: '<S228>/DrvBoardTempDeratingTable' */

/* 驱动板温度查表温度输入 */
const volatile float32 CAL_TpcTmp_tDrvboardDertTableY_Cof_af32[9] = { 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 0.5F, 0.0F, 0.0F, 0.0F } ;
                         /* Referenced by: '<S228>/DrvBoardTempDeratingTable' */

/* 驱动板温度查表derating系数输出 */
const volatile float32 CAL_TpcTmp_tIGBTDertSave1TableX_tSttr_af32[9] = { 0.0F,
  30.0F, 140.0F, 145.0F, 155.0F, 160.0F, 165.0F, 170.0F, 175.0F } ;
                        /* Referenced by: '<S234>/IGBTTempDeratingSave1Table' */

const volatile float32 CAL_TpcTmp_tIGBTDertSave1TableY_Cof_af32[9] = { 1.0F,
  1.0F, 1.0F, 0.8F, 0.6F, 0.4F, 0.2F, 0.0F, 0.0F } ;
                        /* Referenced by: '<S234>/IGBTTempDeratingSave1Table' */

const volatile float32 CAL_TpcTmp_tIGBTDertSave2TableX_tSttr_af32[9] = { 0.0F,
  30.0F, 140.0F, 145.0F, 155.0F, 160.0F, 165.0F, 170.0F, 175.0F } ;
                        /* Referenced by: '<S234>/IGBTTempDeratingSave2Table' */

const volatile float32 CAL_TpcTmp_tIGBTDertSave2TableY_Cof_af32[9] = { 1.0F,
  1.0F, 1.0F, 0.8F, 0.6F, 0.4F, 0.2F, 0.0F, 0.0F } ;
                        /* Referenced by: '<S234>/IGBTTempDeratingSave2Table' */

const volatile float32 CAL_TpcTmp_tIGBTTempHiLim_f32 = 175.0F;
                     /* Referenced by: '<S230>/CAL_TpcTmp_tIGBTTempHiLim_f32' */
const volatile float32 CAL_TpcTmp_tIGBTTempLoLim_f32 = -40.0F;
                     /* Referenced by: '<S230>/CAL_TpcTmp_tIGBTTempLoLim_f32' */
const volatile float32 CAL_TpcTmp_tIGBTTraNormalToSave1_f32 = 140.0F;
                                /* Referenced by: '<S234>/PowerSaveMod_tIGBT' */
const volatile float32 CAL_TpcTmp_tIGBTTraSave1ToNormal_f32 = 135.0F;
                                /* Referenced by: '<S234>/PowerSaveMod_tIGBT' */
const volatile float32 CAL_TpcTmp_tIGBTTraSave1ToSave2_f32 = 150.0F;
                                /* Referenced by: '<S234>/PowerSaveMod_tIGBT' */
const volatile float32 CAL_TpcTmp_tIGBTTraSave2ToOverheating_f32 = 155.0F;
                                /* Referenced by: '<S234>/PowerSaveMod_tIGBT' */
const volatile float32 CAL_TpcTmp_tIGBTTrqLimRamp_f32 = 0.05F;/* Referenced by:
                                                               * '<S197>/CAL_TpcTmp_tIGBTTrqLimRamp_f1'
                                                               * '<S197>/CAL_TpcTmp_tIGBTTrqLimRamp_f32'
                                                               */
const volatile float32 CAL_TpcTmp_tRiseDbcDertSave1TableX_tSttr_af32[9] = { 0.0F,
  30.0F, 50.0F, 52.0F, 54.0F, 56.0F, 58.0F, 60.0F, 62.0F } ;
                     /* Referenced by: '<S217>/DbcRiseTempDeratingSave1Table' */

const volatile float32 CAL_TpcTmp_tRiseDbcDertSave1TableY_Cof_af32[9] = { 1.0F,
  1.0F, 1.0F, 0.8F, 0.6F, 0.4F, 0.2F, 0.0F, 0.0F } ;
                     /* Referenced by: '<S217>/DbcRiseTempDeratingSave1Table' */

const volatile float32 CAL_TpcTmp_tRiseDbcDertSave2TableX_tSttr_af32[9] = { 0.0F,
  30.0F, 50.0F, 52.0F, 54.0F, 56.0F, 58.0F, 60.0F, 62.0F } ;
                     /* Referenced by: '<S217>/DbcRiseTempDeratingSave2Table' */

const volatile float32 CAL_TpcTmp_tRiseDbcDertSave2TableY_Cof_af32[9] = { 1.0F,
  1.0F, 1.0F, 0.8F, 0.6F, 0.4F, 0.2F, 0.0F, 0.0F } ;
                     /* Referenced by: '<S217>/DbcRiseTempDeratingSave2Table' */

const volatile float32 CAL_TpcTmp_tRiseDbcTraNormalToSave1_f32 = 50.0F;
                             /* Referenced by: '<S217>/PowerSaveMod_tRiseDbc' */
const volatile float32 CAL_TpcTmp_tRiseDbcTraSave1ToNormal_f32 = 45.0F;
                             /* Referenced by: '<S217>/PowerSaveMod_tRiseDbc' */
const volatile float32 CAL_TpcTmp_tRiseDbcTraSave1ToSave2_f32 = 55.0F;
                             /* Referenced by: '<S217>/PowerSaveMod_tRiseDbc' */
const volatile float32 CAL_TpcTmp_tRiseDbcTraSave2ToOverheating_f32 = 59.0F;
                             /* Referenced by: '<S217>/PowerSaveMod_tRiseDbc' */
const volatile float32 CAL_TpcTmp_tRiseIGBTDertSave1TableX_tSttr_af32[9] = {
  0.0F, 30.0F, 80.0F, 85.0F, 90.0F, 95.0F, 100.0F, 105.0F, 110.0F } ;
                    /* Referenced by: '<S235>/IGBTRiseTempDeratingSave1Table' */

const volatile float32 CAL_TpcTmp_tRiseIGBTDertSave1TableY_Cof_af32[9] = { 1.0F,
  1.0F, 1.0F, 0.8F, 0.6F, 0.4F, 0.2F, 0.0F, 0.0F } ;
                    /* Referenced by: '<S235>/IGBTRiseTempDeratingSave1Table' */

const volatile float32 CAL_TpcTmp_tRiseIGBTDertSave2TableX_tSttr_af32[9] = {
  0.0F, 30.0F, 80.0F, 85.0F, 90.0F, 95.0F, 100.0F, 105.0F, 110.0F } ;
                    /* Referenced by: '<S235>/IGBTRiseTempDeratingSave2Table' */

const volatile float32 CAL_TpcTmp_tRiseIGBTDertSave2TableY_Cof_af32[9] = { 1.0F,
  1.0F, 1.0F, 0.8F, 0.6F, 0.4F, 0.2F, 0.0F, 0.0F } ;
                    /* Referenced by: '<S235>/IGBTRiseTempDeratingSave2Table' */

const volatile float32 CAL_TpcTmp_tRiseIGBTTraNormalToSave1_f32 = 80.0F;
                            /* Referenced by: '<S235>/PowerSaveMod_tRiseIGBT' */
const volatile float32 CAL_TpcTmp_tRiseIGBTTraSave1ToNormal_f32 = 75.0F;
                            /* Referenced by: '<S235>/PowerSaveMod_tRiseIGBT' */
const volatile float32 CAL_TpcTmp_tRiseIGBTTraSave1ToSave2_f32 = 90.0F;
                            /* Referenced by: '<S235>/PowerSaveMod_tRiseIGBT' */
const volatile float32 CAL_TpcTmp_tRiseIGBTTraSave2ToOverheating_f32 = 95.0F;
                            /* Referenced by: '<S235>/PowerSaveMod_tRiseIGBT' */
const volatile uint8 CAL_Tpc_NormalMode_u8 = 0U;/* Referenced by:
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
const volatile uint8 CAL_Tpc_OverheatingMode_u8 = 3U;/* Referenced by:
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
const volatile uint8 CAL_Tpc_Powersave1Mode_u8 = 1U;/* Referenced by:
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
const volatile uint8 CAL_Tpc_Powersave2Mode_u8 = 2U;/* Referenced by:
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
const volatile float32 CAL_Tpc_TrqReduceRevStep_f32 = 4.0F;/* Referenced by:
                                                            * '<S124>/CAL_Tpc_TrqReduceRevStep_f32'
                                                            * '<S125>/CAL_Tpc_TrqReduceRevStep_f32'
                                                            */
const volatile float32 CAL_Tpc_TrqRevStep_f32 = 0.75F;/* Referenced by:
                                                       * '<S21>/CAL_Tpc_TrqRevStep_f32'
                                                       * '<S21>/CAL_Tpc_TrqRevStep_f321'
                                                       * '<S22>/CAL_Tpc_TrqRevStep_f32'
                                                       * '<S22>/CAL_Tpc_TrqRevStep_f321'
                                                       */

/* 扭矩限值恢复slop */
const volatile float32 CAL_Tpc_TrqRiseRevStep_f32 = 4.0F;/* Referenced by:
                                                          * '<S124>/CAL_Tpc_TrqRiseRevStep_f32'
                                                          * '<S125>/CAL_Tpc_TrqRiseRevStep_f32'
                                                          */
const volatile uint8 CAL_Tpcmot_CofuDclnk_u8 = 2U;
                           /* Referenced by: '<S116>/CAL_Tpcmot_CofuDclnk_u8' */
const volatile float32 CAL_Tpcmot_TrqDiffExc_f32 = 5.0F;
                         /* Referenced by: '<S116>/CAL_Tpcmot_TrqDiffExc_f32' */
const volatile float32 CAL_Tpcmot_TrqDiffGen_f32 = 5.0F;
                         /* Referenced by: '<S116>/CAL_Tpcmot_TrqDiffGen_f32' */
const volatile boolean CAL_Tpcmot_flgOpenExcLimRamp_b = 0;
                    /* Referenced by: '<S116>/CAL_Tpcmot_flgOpenExcLimRamp_b' */
const volatile float32 CAL_Tpcmot_uDcHiset_f32 = 455.0F;
                           /* Referenced by: '<S116>/CAL_Tpcmot_uDcHiset_f32' */
const volatile float32 CAL_Tpcmot_uDcLoset_f32 = 275.0F;
                           /* Referenced by: '<S116>/CAL_Tpcmot_uDcLoset_f32' */

#pragma section

/* Block states (default storage) */
DW_SWC_TPC_T SWC_TPC_DW;

/*
 * System initialize for atomic system:
 *    '<S130>/GetHighTemp'
 *    '<S131>/GetHighTemp'
 *    '<S203>/GetHighTemp'
 *    '<S216>/GetHighTemp'
 *    '<S217>/GetHighTemp'
 *    '<S234>/GetHighTemp'
 *    '<S235>/GetHighTemp'
 */
void SWC_TPC_GetHighTemp_Init(float32 *rty_TModuleTempHighest)
{
  *rty_TModuleTempHighest = 0.0F;
}

/*
 * Output and update for atomic system:
 *    '<S130>/GetHighTemp'
 *    '<S131>/GetHighTemp'
 *    '<S203>/GetHighTemp'
 *    '<S216>/GetHighTemp'
 *    '<S217>/GetHighTemp'
 *    '<S234>/GetHighTemp'
 *    '<S235>/GetHighTemp'
 */
void SWC_TPC_GetHighTemp(float32 rtu_TModuletemp, float32 rtu_TModuletempDly,
  float32 *rty_TModuleTempHighest)
{
  /* Chart: '<S130>/GetHighTemp' */
  *rty_TModuleTempHighest = fmaxf(rtu_TModuletemp, rtu_TModuletempDly);
}

/* Model step function for TID1 */
void SWC_TPC_10ms(void)                /* Explicit Task: RE_SWC_TPC_10ms */
{
  /* local block i/o variables */
  float32 rtb_TModuleTempHighest;
  float32 rtb_TModuleTempHighest_p;
  float32 rtb_TModuleTempHighest_j;
  float32 rtb_TModuleTempHighest_m;
  float32 rtb_TModuleTempHighest_l;
  float32 rtb_TModuleTempHighest_h;
  float32 rtb_TModuleTempHighest_e;
  sint32 idxDelay;
  float32 tmpRead;
  float32 tmpRead_0;
  float32 rtb_Switch_iq;
  float32 rtb_Switch_ba;
  float32 rtb_Switch_f4;
  float32 rtb_TmpSignalConversionAtRP_S_f;
  float32 rtb_Switch4_d;
  float32 rtb_Product1_o;
  float32 rtb_Product_g;
  float32 rtb_TmpSignalConversionAtRP_SWC;
  boolean rtb_FIM_PwrLimLvFour;
  float32 rtb_TmpSignalConversionAtRP__k0;
  float32 rtb_Add;
  float32 rtb_TmpSignalConversionAtRP_S_i;
  float32 rtb_TmpSignalConversionAtRP_S_k;
  float32 rtb_TmpSignalConversionAtRP__jn;
  float32 rtb_TmpSignalConversionAtRP__na;
  float32 rtb_DataTypeConversion1;
  boolean rtb_TmpSignalConversionAtRP_S_d;
  boolean rtb_LogicalOperator_g;
  float32 rtb_TmpSignalConversionAtRP_S_n;
  float32 rtb_TmpSignalConversionAtRP__n1;
  boolean rtb_RelationalOperator4_o;
  boolean rtb_RelationalOperator1_cn;
  boolean rtb_RelationalOperator3_kx;
  boolean rtb_FIM_TrqLimLvFour;
  boolean rtb_FIM_PwrLimLvOne;
  boolean rtb_FIM_PwrLimLvTwo;
  boolean rtb_FIM_PwrLimLvThree;
  uint8 rtb_TmpSignalConversionAtRP_S_e;
  float32 rtb_CoolantFlow4L;
  float32 rtb_CoolantFlow6L;
  float32 rtb_Subtract_gc;
  float32 rtb_Subtract_kw;
  float32 rtb_Add_m3;
  uint8 tpccod_stMotorMod;
  uint8 tpccod_SgnRotDir;
  uint8 tpccod_SgnTrqMechDir;
  iEDS_Enum_stTrqEm_def tmp;
  float32 rtb_Divide_b_tmp;
  boolean guard1 = false;
  boolean guard2 = false;

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_TPC_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_TPC_10ms_sys'
   */
  /* SignalConversion generated from: '<S1>/RP_SWC_HSPF_HSPF_nSlowFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_nSlowFlt'
   */
  Rte_Read_RP_SWC_HSPF_HSPF_nSlowFlt(&rtb_TmpSignalConversionAtRP_SWC);

  /* Abs: '<S186>/Abs2' incorporates:
   *  Abs: '<S105>/Abs'
   *  Abs: '<S116>/Abs'
   *  Abs: '<S117>/Abs'
   *  Abs: '<S152>/Abs'
   *  Abs: '<S161>/Abs2'
   */
  rtb_Product_g = fabsf(rtb_TmpSignalConversionAtRP_SWC);

  /* Sum: '<S186>/Add3' incorporates:
   *  Abs: '<S186>/Abs2'
   *  Constant: '<S186>/CAL_TpcSmp_ThresOverSpd_f32'
   *  Constant: '<S186>/Constant1'
   *  RelationalOperator: '<S186>/Relational Operator8'
   */
  VAR_TpcSmp_SpdOvHiLimErrState_u8 = (uint8)((rtb_Product_g >=
    CAL_TpcSmp_ThresOverSpd_f32) + 2U);

  /* FunctionCaller: '<S1>/RP_SWC_Dem_TPC_SpdOvHiLimFail_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_TPC_SpdOvHiLimFail_SetEventStatus
    (VAR_TpcSmp_SpdOvHiLimErrState_u8);

  /* Switch: '<S187>/Switch' incorporates:
   *  Abs: '<S186>/Abs2'
   *  Constant: '<S186>/CAL_TpcSmp_OvSpdWarnHiLim_f32'
   *  Constant: '<S186>/CAL_TpcSmp_OvSpdWarnLoLim_f32'
   *  Constant: '<S187>/True'
   *  RelationalOperator: '<S187>/Relational Operator'
   *  RelationalOperator: '<S187>/Relational Operator1'
   *  UnitDelay: '<S187>/Unit Delay'
   */
  if (rtb_Product_g > CAL_TpcSmp_OvSpdWarnHiLim_f32) {
    SWC_TPC_DW.UnitDelay_DSTATE_au = true;
  } else {
    SWC_TPC_DW.UnitDelay_DSTATE_au = ((rtb_Product_g >=
      CAL_TpcSmp_OvSpdWarnLoLim_f32) && SWC_TPC_DW.UnitDelay_DSTATE_au);
  }

  /* End of Switch: '<S187>/Switch' */

  /* Sum: '<S186>/Add2' incorporates:
   *  Constant: '<S186>/Constant'
   *  DataTypeConversion: '<S186>/Data Type Conversion'
   *  UnitDelay: '<S187>/Unit Delay'
   */
  VAR_TpcSmp_SpdOvHiWarnState_u8 = (uint8)(SWC_TPC_DW.UnitDelay_DSTATE_au + 2U);

  /* FunctionCaller: '<S1>/RP_SWC_Dem_TPC_SpdOvHiWarn_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_TPC_SpdOvHiWarn_SetEventStatus
    (VAR_TpcSmp_SpdOvHiWarnState_u8);

  /* SignalConversion generated from: '<S1>/RP_SWC_HSPF_HSPF_tCoolantTjFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_tCoolantTjFlt'
   */
  Rte_Read_RP_SWC_HSPF_HSPF_tCoolantTjFlt(&rtb_TmpSignalConversionAtRP__k0);

  /* DataTypeConversion: '<S109>/Data Type Conversion' */
  rtb_Add = fmodf(roundf(rtb_TmpSignalConversionAtRP__k0), 65536.0F);
  VAR_TpcTmp_tCoolTempFlt_u16 = (sint16)(rtb_Add < 0.0F ? (sint32)(sint16)-
    (sint16)(uint16)-rtb_Add : (sint32)(sint16)(uint16)rtb_Add);

  /* Sum: '<S202>/Add' incorporates:
   *  UnitDelay: '<S202>/Unit Delay1'
   */
  rtb_Add = (float32)VAR_TpcTmp_tCoolTempFlt_u16 - SWC_TPC_DW.UnitDelay1_DSTATE;

  /* Switch: '<S202>/Switch1' incorporates:
   *  Constant: '<S200>/CAL_TpcTmp_CoolTempAdds_f32'
   *  Constant: '<S200>/CAL_TpcTmp_CoolTempDecDiff_f32'
   *  Constant: '<S200>/CAL_TpcTmp_CoolTempRiseDiff_f32'
   *  RelationalOperator: '<S202>/Relational Operator'
   *  RelationalOperator: '<S202>/Relational Operator1'
   *  Sum: '<S202>/Add1'
   *  Switch: '<S202>/Switch'
   *  UnitDelay: '<S202>/Unit Delay1'
   */
  if (rtb_Add >= CAL_TpcTmp_CoolTempRiseDiff_f32) {
    SWC_TPC_DW.UnitDelay1_DSTATE += CAL_TpcTmp_CoolTempAdds_f32;
  } else {
    if (rtb_Add <= CAL_TpcTmp_CoolTempDecDiff_f32) {
      /* UnitDelay: '<S202>/Unit Delay1' incorporates:
       *  Constant: '<S200>/CAL_TpcTmp_CoolTempMinus_f32'
       *  Sum: '<S202>/Add2'
       *  Switch: '<S202>/Switch'
       */
      SWC_TPC_DW.UnitDelay1_DSTATE += CAL_TpcTmp_CoolTempMinus_f32;
    }
  }

  /* End of Switch: '<S202>/Switch1' */

  /* Sum: '<S202>/Add4' */
  rtb_Switch_iq = rtb_Add - (float32)VAR_TpcTmp_TCoolStableDiff_u16;

  /* Switch: '<S202>/Switch2' incorporates:
   *  Constant: '<S204>/Constant'
   *  Constant: '<S205>/Constant'
   *  Logic: '<S202>/Logical Operator'
   *  RelationalOperator: '<S204>/Compare'
   *  RelationalOperator: '<S205>/Compare'
   */
  if ((rtb_Switch_iq >= CAL_TpcTmp_CoolChgTempUpDiff_f32) || (rtb_Switch_iq <=
       CAL_TpcTmp_CoolChgTempDownDiff_f32)) {
    rtb_Add = fmodf(floorf(rtb_Add), 65536.0F);
    VAR_TpcTmp_TCoolStableDiff_u16 = (sint16)(rtb_Add < 0.0F ? (sint32)(sint16)-
      (sint16)(uint16)-rtb_Add : (sint32)(sint16)(uint16)rtb_Add);
  }

  /* End of Switch: '<S202>/Switch2' */

  /* Product: '<S202>/Product' incorporates:
   *  Constant: '<S200>/CAL_TpcTmp_CoolTempKp_f32'
   */
  rtb_Add = CAL_TpcTmp_CoolTempKp_f32 * (float32)VAR_TpcTmp_TCoolStableDiff_u16;

  /* Saturate: '<S202>/Saturation' */
  if (rtb_Add > 0.9F) {
    rtb_Add = 0.9F;
  } else {
    if (rtb_Add < -0.9F) {
      rtb_Add = -0.9F;
    }
  }

  /* End of Saturate: '<S202>/Saturation' */

  /* Sum: '<S202>/Add3' incorporates:
   *  UnitDelay: '<S202>/Unit Delay1'
   */
  VAR_TpcTmp_tCoolantTempFlt_f32 = SWC_TPC_DW.UnitDelay1_DSTATE + rtb_Add;

  /* Lookup_n-D: '<S203>/CoolantTempDeratingSave1Table' */
  VAR_TpcTmp_CofDertTCoolantSave1_f32 = look1_iflf_binlxpw
    (VAR_TpcTmp_tCoolantTempFlt_f32, ((const float32 *)
      &(CAL_TpcTmp_tCoolantDertSave1TableX_tSttr_af32[0])), ((const float32 *)
      &(CAL_TpcTmp_tCoolantDertSave1TableY_Cof_af32[0])), 8U);

  /* Chart: '<S203>/PowerSaveMod_tCoolant' */
  if (SWC_TPC_DW.is_active_c22_SWC_TPC == 0U) {
    SWC_TPC_DW.is_active_c22_SWC_TPC = 1U;
    SWC_TPC_DW.is_c22_SWC_TPC = SWC_TPC_IN_NormalMode;
    VAR_TpcTmp_tCoolantOperationMode_u8 = CAL_Tpc_NormalMode_u8;
  } else {
    switch (SWC_TPC_DW.is_c22_SWC_TPC) {
     case SWC_TPC_IN_NormalMode:
      if (VAR_TpcTmp_tCoolantTempFlt_f32 >
          CAL_TpcTmp_tCoolantTraNormalToSave1_f32) {
        SWC_TPC_DW.is_c22_SWC_TPC = SWC_TPC_IN_PowerSave1;
        VAR_TpcTmp_tCoolantOperationMode_u8 = CAL_Tpc_Powersave1Mode_u8;
      }
      break;

     case SWC_TPC_IN_Overheating:
      break;

     case SWC_TPC_IN_PowerSave1:
      if (VAR_TpcTmp_tCoolantTempFlt_f32 <
          CAL_TpcTmp_tCoolantTraSave1ToNormal_f32) {
        SWC_TPC_DW.is_c22_SWC_TPC = SWC_TPC_IN_NormalMode;
        VAR_TpcTmp_tCoolantOperationMode_u8 = CAL_Tpc_NormalMode_u8;
      } else {
        if (VAR_TpcTmp_tCoolantTempFlt_f32 >
            CAL_TpcTmp_tCoolantTraSave1ToSave2_f32) {
          SWC_TPC_DW.is_c22_SWC_TPC = SWC_TPC_IN_PowerSave2;
          VAR_TpcTmp_tCoolantOperationMode_u8 = CAL_Tpc_Powersave2Mode_u8;
        }
      }
      break;

     default:
      /* case IN_PowerSave2: */
      if (VAR_TpcTmp_tCoolantTempFlt_f32 >
          CAL_TpcTmp_tCoolantTraSave2ToOverheating_f32) {
        SWC_TPC_DW.is_c22_SWC_TPC = SWC_TPC_IN_Overheating;
        VAR_TpcTmp_tCoolantOperationMode_u8 = CAL_Tpc_OverheatingMode_u8;
      }
      break;
    }
  }

  /* End of Chart: '<S203>/PowerSaveMod_tCoolant' */

  /* Chart: '<S203>/GetHighTemp' incorporates:
   *  UnitDelay: '<S203>/Unit Delay2'
   */
  SWC_TPC_GetHighTemp(VAR_TpcTmp_tCoolantTempFlt_f32,
                      SWC_TPC_DW.UnitDelay2_DSTATE, &rtb_TModuleTempHighest_l);

  /* Lookup_n-D: '<S203>/CoolantTempDeratingSave2Table' */
  VAR_TpcTmp_CofDertTCoolantSave2_f32 = look1_iflf_binlxpw
    (rtb_TModuleTempHighest_l, ((const float32 *)
      &(CAL_TpcTmp_tCoolantDertSave2TableX_tSttr_af32[0])), ((const float32 *)
      &(CAL_TpcTmp_tCoolantDertSave2TableY_Cof_af32[0])), 8U);

  /* Switch: '<S203>/Switch1' incorporates:
   *  Constant: '<S203>/CAL_Tpc_NormalMode_u8'
   *  Constant: '<S203>/CAL_Tpc_OverheatingMode_u8'
   *  Constant: '<S203>/CAL_Tpc_Powersave1Mode_u8'
   *  Constant: '<S203>/CAL_Tpc_Powersave2Mode_u8'
   *  Logic: '<S203>/Logical Operator'
   *  Logic: '<S203>/Logical Operator1'
   *  RelationalOperator: '<S203>/Relational Operator'
   *  RelationalOperator: '<S203>/Relational Operator1'
   *  RelationalOperator: '<S203>/Relational Operator2'
   *  RelationalOperator: '<S203>/Relational Operator3'
   *  Switch: '<S203>/Switch2'
   */
  if ((VAR_TpcTmp_tCoolantOperationMode_u8 == CAL_Tpc_NormalMode_u8) ||
      (VAR_TpcTmp_tCoolantOperationMode_u8 == CAL_Tpc_Powersave1Mode_u8)) {
    VAR_TpcTmp_CofDertTcoolant_f32 = VAR_TpcTmp_CofDertTCoolantSave1_f32;
  } else {
    if ((VAR_TpcTmp_tCoolantOperationMode_u8 == CAL_Tpc_Powersave2Mode_u8) ||
        (VAR_TpcTmp_tCoolantOperationMode_u8 == CAL_Tpc_OverheatingMode_u8)) {
      /* Switch: '<S203>/Switch2' */
      VAR_TpcTmp_CofDertTcoolant_f32 = VAR_TpcTmp_CofDertTCoolantSave2_f32;
    }
  }

  /* End of Switch: '<S203>/Switch1' */

  /* RelationalOperator: '<S201>/Relational Operator' incorporates:
   *  Constant: '<S201>/Coefficient1.0'
   *  Constant: '<S201>/ZeroValue'
   *  Sum: '<S201>/Add'
   */
  VAR_TpcTmp_flgTrqLimTcoolantActv_b = (1.0F - VAR_TpcTmp_CofDertTcoolant_f32 >
    1.0E-6F);

  /* Sum: '<S199>/Add' incorporates:
   *  Constant: '<S199>/Constant'
   *  DataTypeConversion: '<S199>/Data Type Conversion'
   */
  VAR_TpcTmp_TCoolantOvHiWarnState_u8 = (uint8)
    (VAR_TpcTmp_flgTrqLimTcoolantActv_b + 2U);

  /* FunctionCaller: '<S1>/RP_SWC_Dem_TPC_TCoolantOvHiWarn_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_TPC_TCoolantOvHiWarn_SetEventStatus
    (VAR_TpcTmp_TCoolantOvHiWarnState_u8);

  /* SignalConversion generated from: '<S1>/RP_SWC_HSPF_HSPF_tDBCTempUFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_tDBCTempUFlt'
   */
  Rte_Read_RP_SWC_HSPF_HSPF_tDBCTempUFlt(&rtb_TmpSignalConversionAtRP_S_k);

  /* SignalConversion generated from: '<S1>/RP_SWC_HSPF_HSPF_tDBCTempVFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_tDBCTempVFlt'
   */
  Rte_Read_RP_SWC_HSPF_HSPF_tDBCTempVFlt(&rtb_TmpSignalConversionAtRP_S_i);

  /* Switch: '<S212>/Switch' incorporates:
   *  RelationalOperator: '<S212>/Relational Operator'
   */
  if (rtb_TmpSignalConversionAtRP_S_k >= rtb_TmpSignalConversionAtRP_S_i) {
    rtb_Switch_iq = rtb_TmpSignalConversionAtRP_S_k;
  } else {
    rtb_Switch_iq = rtb_TmpSignalConversionAtRP_S_i;
  }

  /* End of Switch: '<S212>/Switch' */

  /* SignalConversion generated from: '<S1>/RP_SWC_HSPF_HSPF_tDBCTempWFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_tDBCTempWFlt'
   */
  Rte_Read_RP_SWC_HSPF_HSPF_tDBCTempWFlt(&rtb_TmpSignalConversionAtRP__jn);

  /* Switch: '<S212>/Switch1' incorporates:
   *  RelationalOperator: '<S212>/Relational Operator1'
   */
  if (rtb_Switch_iq >= rtb_TmpSignalConversionAtRP__jn) {
    VAR_TpcTmp_tDbcMax_f32 = rtb_Switch_iq;
  } else {
    VAR_TpcTmp_tDbcMax_f32 = rtb_TmpSignalConversionAtRP__jn;
  }

  /* End of Switch: '<S212>/Switch1' */

  /* DataTypeConversion: '<S209>/Data Type Conversion' */
  rtb_Add = fmodf(roundf(VAR_TpcTmp_tDbcMax_f32), 65536.0F);
  VAR_TpcTmp_tDbcTempFlt_u16 = (sint16)(rtb_Add < 0.0F ? (sint32)(sint16)-
    (sint16)(uint16)-rtb_Add : (sint32)(sint16)(uint16)rtb_Add);

  /* Sum: '<S209>/Add' incorporates:
   *  UnitDelay: '<S209>/Unit Delay1'
   */
  rtb_Add = (float32)VAR_TpcTmp_tDbcTempFlt_u16 - SWC_TPC_DW.UnitDelay1_DSTATE_c;

  /* Switch: '<S209>/Switch1' incorporates:
   *  Constant: '<S195>/CAL_TpcTmp_DBCTempAdds_f32'
   *  Constant: '<S195>/CAL_TpcTmp_DBCTempDecDiff_f32'
   *  Constant: '<S195>/CAL_TpcTmp_DBCTempRiseDiff_f32'
   *  RelationalOperator: '<S209>/Relational Operator'
   *  RelationalOperator: '<S209>/Relational Operator1'
   *  Sum: '<S209>/Add1'
   *  Switch: '<S209>/Switch'
   *  UnitDelay: '<S209>/Unit Delay1'
   */
  if (rtb_Add >= CAL_TpcTmp_DBCTempRiseDiff_f32) {
    SWC_TPC_DW.UnitDelay1_DSTATE_c += CAL_TpcTmp_DBCTempAdds_f32;
  } else {
    if (rtb_Add <= CAL_TpcTmp_DBCTempDecDiff_f32) {
      /* UnitDelay: '<S209>/Unit Delay1' incorporates:
       *  Constant: '<S195>/CAL_TpcTmp_DBCTempMinus_f32'
       *  Sum: '<S209>/Add2'
       *  Switch: '<S209>/Switch'
       */
      SWC_TPC_DW.UnitDelay1_DSTATE_c += CAL_TpcTmp_DBCTempMinus_f32;
    }
  }

  /* End of Switch: '<S209>/Switch1' */

  /* Sum: '<S209>/Add4' */
  rtb_Switch_iq = rtb_Add - (float32)VAR_TpcTmp_TDbcStableDiff_u16;

  /* Switch: '<S209>/Switch2' incorporates:
   *  Constant: '<S225>/Constant'
   *  Constant: '<S226>/Constant'
   *  Logic: '<S209>/Logical Operator'
   *  RelationalOperator: '<S225>/Compare'
   *  RelationalOperator: '<S226>/Compare'
   */
  if ((rtb_Switch_iq >= CAL_TpcTmp_DbcChgTempUpDiff_f32) || (rtb_Switch_iq <=
       CAL_TpcTmp_DbcChgTempDownDiff_f32)) {
    rtb_Add = fmodf(floorf(rtb_Add), 65536.0F);
    VAR_TpcTmp_TDbcStableDiff_u16 = (sint16)(rtb_Add < 0.0F ? (sint32)(sint16)-
      (sint16)(uint16)-rtb_Add : (sint32)(sint16)(uint16)rtb_Add);
  }

  /* End of Switch: '<S209>/Switch2' */

  /* Product: '<S209>/Product' incorporates:
   *  Constant: '<S195>/CAL_TpcTmp_DBCTempKp_f32'
   */
  rtb_Add = CAL_TpcTmp_DBCTempKp_f32 * (float32)VAR_TpcTmp_TDbcStableDiff_u16;

  /* Saturate: '<S209>/Saturation' */
  if (rtb_Add > 0.9F) {
    rtb_Add = 0.9F;
  } else {
    if (rtb_Add < -0.9F) {
      rtb_Add = -0.9F;
    }
  }

  /* End of Saturate: '<S209>/Saturation' */

  /* Sum: '<S209>/Add3' incorporates:
   *  UnitDelay: '<S209>/Unit Delay1'
   */
  VAR_TpcTmp_tDbcTempFlt_f32 = SWC_TPC_DW.UnitDelay1_DSTATE_c + rtb_Add;

  /* Lookup_n-D: '<S216>/DbcTempDeratingSave1Table' */
  VAR_TpcTmp_CofDertTDbcSave1_f32 = look1_iflf_binlxpw
    (VAR_TpcTmp_tDbcTempFlt_f32, ((const float32 *)
      &(CAL_TpcTmp_tDbcDertSave1TableX_tSttr_af32[0])), ((const float32 *)
      &(CAL_TpcTmp_tDbcDertSave1TableY_Cof_af32[0])), 8U);

  /* Chart: '<S216>/PowerSaveMod_tDbc' */
  if (SWC_TPC_DW.is_active_c16_SWC_TPC == 0U) {
    SWC_TPC_DW.is_active_c16_SWC_TPC = 1U;
    SWC_TPC_DW.is_c16_SWC_TPC = SWC_TPC_IN_NormalMode;
    VAR_TpcTmp_tDbcOperationMode_u8 = CAL_Tpc_NormalMode_u8;
  } else {
    switch (SWC_TPC_DW.is_c16_SWC_TPC) {
     case SWC_TPC_IN_NormalMode:
      if (VAR_TpcTmp_tDbcTempFlt_f32 > CAL_TpcTmp_tDbcTraNormalToSave1_f32) {
        SWC_TPC_DW.is_c16_SWC_TPC = SWC_TPC_IN_PowerSave1;
        VAR_TpcTmp_tDbcOperationMode_u8 = CAL_Tpc_Powersave1Mode_u8;
      }
      break;

     case SWC_TPC_IN_Overheating:
      break;

     case SWC_TPC_IN_PowerSave1:
      if (VAR_TpcTmp_tDbcTempFlt_f32 < CAL_TpcTmp_tDbcTraSave1ToNormal_f32) {
        SWC_TPC_DW.is_c16_SWC_TPC = SWC_TPC_IN_NormalMode;
        VAR_TpcTmp_tDbcOperationMode_u8 = CAL_Tpc_NormalMode_u8;
      } else {
        if (VAR_TpcTmp_tDbcTempFlt_f32 > CAL_TpcTmp_tDbcTraSave1ToSave2_f32) {
          SWC_TPC_DW.is_c16_SWC_TPC = SWC_TPC_IN_PowerSave2;
          VAR_TpcTmp_tDbcOperationMode_u8 = CAL_Tpc_Powersave2Mode_u8;
        }
      }
      break;

     default:
      /* case IN_PowerSave2: */
      if (VAR_TpcTmp_tDbcTempFlt_f32 > CAL_TpcTmp_tDbcTraSave2ToOverheating_f32)
      {
        SWC_TPC_DW.is_c16_SWC_TPC = SWC_TPC_IN_Overheating;
        VAR_TpcTmp_tDbcOperationMode_u8 = CAL_Tpc_OverheatingMode_u8;
      }
      break;
    }
  }

  /* End of Chart: '<S216>/PowerSaveMod_tDbc' */

  /* Chart: '<S216>/GetHighTemp' incorporates:
   *  UnitDelay: '<S216>/Unit Delay2'
   */
  SWC_TPC_GetHighTemp(VAR_TpcTmp_tDbcTempFlt_f32, SWC_TPC_DW.UnitDelay2_DSTATE_b,
                      &rtb_TModuleTempHighest_m);

  /* Lookup_n-D: '<S216>/DbcTempDeratingSave2Table' */
  VAR_TpcTmp_CofDertTDbcSave2_f32 = look1_iflf_binlxpw(rtb_TModuleTempHighest_m,
    ((const float32 *)&(CAL_TpcTmp_tDbcDertSave2TableX_tSttr_af32[0])), ((const
    float32 *)&(CAL_TpcTmp_tDbcDertSave2TableY_Cof_af32[0])), 8U);

  /* Switch: '<S216>/Switch1' incorporates:
   *  Constant: '<S216>/CAL_Tpc_NormalMode_u8'
   *  Constant: '<S216>/CAL_Tpc_OverheatingMode_u8'
   *  Constant: '<S216>/CAL_Tpc_Powersave1Mode_u8'
   *  Constant: '<S216>/CAL_Tpc_Powersave2Mode_u8'
   *  Logic: '<S216>/Logical Operator'
   *  Logic: '<S216>/Logical Operator1'
   *  RelationalOperator: '<S216>/Relational Operator'
   *  RelationalOperator: '<S216>/Relational Operator1'
   *  RelationalOperator: '<S216>/Relational Operator2'
   *  RelationalOperator: '<S216>/Relational Operator3'
   *  Switch: '<S216>/Switch2'
   */
  if ((VAR_TpcTmp_tDbcOperationMode_u8 == CAL_Tpc_NormalMode_u8) ||
      (VAR_TpcTmp_tDbcOperationMode_u8 == CAL_Tpc_Powersave1Mode_u8)) {
    VAR_TpcTmp_CofDertDbc_f32 = VAR_TpcTmp_CofDertTDbcSave1_f32;
  } else {
    if ((VAR_TpcTmp_tDbcOperationMode_u8 == CAL_Tpc_Powersave2Mode_u8) ||
        (VAR_TpcTmp_tDbcOperationMode_u8 == CAL_Tpc_OverheatingMode_u8)) {
      /* Switch: '<S216>/Switch2' */
      VAR_TpcTmp_CofDertDbc_f32 = VAR_TpcTmp_CofDertTDbcSave2_f32;
    }
  }

  /* End of Switch: '<S216>/Switch1' */

  /* Sum: '<S217>/Add' */
  VAR_TpcTmp_tRiseDbc_f32 = VAR_TpcTmp_tDbcTempFlt_f32 - (float32)
    VAR_TpcTmp_tCoolTempFlt_u16;

  /* DataTypeConversion: '<S220>/Data Type Conversion' */
  rtb_Add = fmodf(roundf(VAR_TpcTmp_tRiseDbc_f32), 65536.0F);
  VAR_TpcTmp_tDbcRiseTempFlt_u16 = (sint16)(rtb_Add < 0.0F ? (sint32)(sint16)-
    (sint16)(uint16)-rtb_Add : (sint32)(sint16)(uint16)rtb_Add);

  /* Sum: '<S220>/Add' incorporates:
   *  UnitDelay: '<S220>/Unit Delay1'
   */
  rtb_Add = (float32)VAR_TpcTmp_tDbcRiseTempFlt_u16 -
    SWC_TPC_DW.UnitDelay1_DSTATE_e;

  /* Switch: '<S220>/Switch1' incorporates:
   *  Constant: '<S217>/CAL_TpcTmp_DBCRiseTempAdds_f32'
   *  Constant: '<S217>/CAL_TpcTmp_DBCRiseTempDecDiff_f32'
   *  Constant: '<S217>/CAL_TpcTmp_DBCRiseTempRiseDiff_f32'
   *  RelationalOperator: '<S220>/Relational Operator'
   *  RelationalOperator: '<S220>/Relational Operator1'
   *  Sum: '<S220>/Add1'
   *  Switch: '<S220>/Switch'
   *  UnitDelay: '<S220>/Unit Delay1'
   */
  if (rtb_Add >= CAL_TpcTmp_DBCRiseTempRiseDiff_f32) {
    SWC_TPC_DW.UnitDelay1_DSTATE_e += CAL_TpcTmp_DBCRiseTempAdds_f32;
  } else {
    if (rtb_Add <= CAL_TpcTmp_DBCRiseTempDecDiff_f32) {
      /* UnitDelay: '<S220>/Unit Delay1' incorporates:
       *  Constant: '<S217>/CAL_TpcTmp_DBCRiseTempMinus_f32'
       *  Sum: '<S220>/Add2'
       *  Switch: '<S220>/Switch'
       */
      SWC_TPC_DW.UnitDelay1_DSTATE_e += CAL_TpcTmp_DBCRiseTempMinus_f32;
    }
  }

  /* End of Switch: '<S220>/Switch1' */

  /* Sum: '<S220>/Add4' */
  rtb_Switch_iq = rtb_Add - (float32)VAR_TpcTmp_TDbcRiseStableDiff_u16;

  /* Switch: '<S220>/Switch2' incorporates:
   *  Constant: '<S223>/Constant'
   *  Constant: '<S224>/Constant'
   *  Logic: '<S220>/Logical Operator'
   *  RelationalOperator: '<S223>/Compare'
   *  RelationalOperator: '<S224>/Compare'
   */
  if ((rtb_Switch_iq >= CAL_TpcTmp_DbcRiseChgTempUpDiff_f32) || (rtb_Switch_iq <=
       CAL_TpcTmp_DbcRiseChgTempDownDiff_f32)) {
    rtb_Add = fmodf(floorf(rtb_Add), 65536.0F);
    VAR_TpcTmp_TDbcRiseStableDiff_u16 = (sint16)(rtb_Add < 0.0F ? (sint32)
      (sint16)-(sint16)(uint16)-rtb_Add : (sint32)(sint16)(uint16)rtb_Add);
  }

  /* End of Switch: '<S220>/Switch2' */

  /* Product: '<S220>/Product' incorporates:
   *  Constant: '<S217>/CAL_TpcTmp_DBCRiseTempKp_f32'
   */
  rtb_Add = CAL_TpcTmp_DBCRiseTempKp_f32 * (float32)
    VAR_TpcTmp_TDbcRiseStableDiff_u16;

  /* Saturate: '<S220>/Saturation' */
  if (rtb_Add > 0.9F) {
    rtb_Add = 0.9F;
  } else {
    if (rtb_Add < -0.9F) {
      rtb_Add = -0.9F;
    }
  }

  /* End of Saturate: '<S220>/Saturation' */

  /* Sum: '<S220>/Add3' incorporates:
   *  UnitDelay: '<S220>/Unit Delay1'
   */
  VAR_TpcTmp_tRiseDbcFlt_f32 = SWC_TPC_DW.UnitDelay1_DSTATE_e + rtb_Add;

  /* Lookup_n-D: '<S217>/DbcRiseTempDeratingSave1Table' */
  VAR_TpcTmp_CofDertTRiseDbcSave1_f32 = look1_iflf_binlxpw
    (VAR_TpcTmp_tRiseDbcFlt_f32, ((const float32 *)
      &(CAL_TpcTmp_tRiseDbcDertSave1TableX_tSttr_af32[0])), ((const float32 *)
      &(CAL_TpcTmp_tRiseDbcDertSave1TableY_Cof_af32[0])), 8U);

  /* Chart: '<S217>/PowerSaveMod_tRiseDbc' */
  if (SWC_TPC_DW.is_active_c18_SWC_TPC == 0U) {
    SWC_TPC_DW.is_active_c18_SWC_TPC = 1U;
    SWC_TPC_DW.is_c18_SWC_TPC = SWC_TPC_IN_NormalMode;
    VAR_TpcTmp_tRiseDbcOperationMode_u8 = CAL_Tpc_NormalMode_u8;
  } else {
    switch (SWC_TPC_DW.is_c18_SWC_TPC) {
     case SWC_TPC_IN_NormalMode:
      if (VAR_TpcTmp_tRiseDbcFlt_f32 > CAL_TpcTmp_tRiseDbcTraNormalToSave1_f32)
      {
        SWC_TPC_DW.is_c18_SWC_TPC = SWC_TPC_IN_PowerSave1;
        VAR_TpcTmp_tRiseDbcOperationMode_u8 = CAL_Tpc_Powersave1Mode_u8;
      }
      break;

     case SWC_TPC_IN_Overheating:
      break;

     case SWC_TPC_IN_PowerSave1:
      if (VAR_TpcTmp_tRiseDbcFlt_f32 < CAL_TpcTmp_tRiseDbcTraSave1ToNormal_f32)
      {
        SWC_TPC_DW.is_c18_SWC_TPC = SWC_TPC_IN_NormalMode;
        VAR_TpcTmp_tRiseDbcOperationMode_u8 = CAL_Tpc_NormalMode_u8;
      } else {
        if (VAR_TpcTmp_tRiseDbcFlt_f32 > CAL_TpcTmp_tRiseDbcTraSave1ToSave2_f32)
        {
          SWC_TPC_DW.is_c18_SWC_TPC = SWC_TPC_IN_PowerSave2;
          VAR_TpcTmp_tRiseDbcOperationMode_u8 = CAL_Tpc_Powersave2Mode_u8;
        }
      }
      break;

     default:
      /* case IN_PowerSave2: */
      if (VAR_TpcTmp_tRiseDbcFlt_f32 >
          CAL_TpcTmp_tRiseDbcTraSave2ToOverheating_f32) {
        SWC_TPC_DW.is_c18_SWC_TPC = SWC_TPC_IN_Overheating;
        VAR_TpcTmp_tRiseDbcOperationMode_u8 = CAL_Tpc_OverheatingMode_u8;
      }
      break;
    }
  }

  /* End of Chart: '<S217>/PowerSaveMod_tRiseDbc' */

  /* Chart: '<S217>/GetHighTemp' incorporates:
   *  UnitDelay: '<S217>/Unit Delay2'
   */
  SWC_TPC_GetHighTemp(VAR_TpcTmp_tRiseDbcFlt_f32, SWC_TPC_DW.UnitDelay2_DSTATE_m,
                      &rtb_TModuleTempHighest_j);

  /* Lookup_n-D: '<S217>/DbcRiseTempDeratingSave2Table' */
  VAR_TpcTmp_CofDertTRiseDbcSave2_f32 = look1_iflf_binlxpw
    (rtb_TModuleTempHighest_j, ((const float32 *)
      &(CAL_TpcTmp_tRiseDbcDertSave2TableX_tSttr_af32[0])), ((const float32 *)
      &(CAL_TpcTmp_tRiseDbcDertSave2TableY_Cof_af32[0])), 8U);

  /* Switch: '<S217>/Switch1' incorporates:
   *  Constant: '<S217>/CAL_Tpc_NormalMode_u8'
   *  Constant: '<S217>/CAL_Tpc_OverheatingMode_u8'
   *  Constant: '<S217>/CAL_Tpc_Powersave1Mode_u8'
   *  Constant: '<S217>/CAL_Tpc_Powersave2Mode_u8'
   *  Logic: '<S217>/Logical Operator'
   *  Logic: '<S217>/Logical Operator1'
   *  RelationalOperator: '<S217>/Relational Operator'
   *  RelationalOperator: '<S217>/Relational Operator1'
   *  RelationalOperator: '<S217>/Relational Operator2'
   *  RelationalOperator: '<S217>/Relational Operator3'
   *  Switch: '<S217>/Switch2'
   */
  if ((VAR_TpcTmp_tRiseDbcOperationMode_u8 == CAL_Tpc_NormalMode_u8) ||
      (VAR_TpcTmp_tRiseDbcOperationMode_u8 == CAL_Tpc_Powersave1Mode_u8)) {
    VAR_TpcTmp_CofDertTRiseDbc_f32 = VAR_TpcTmp_CofDertTRiseDbcSave1_f32;
  } else {
    if ((VAR_TpcTmp_tRiseDbcOperationMode_u8 == CAL_Tpc_Powersave2Mode_u8) ||
        (VAR_TpcTmp_tRiseDbcOperationMode_u8 == CAL_Tpc_OverheatingMode_u8)) {
      /* Switch: '<S217>/Switch2' */
      VAR_TpcTmp_CofDertTRiseDbc_f32 = VAR_TpcTmp_CofDertTRiseDbcSave2_f32;
    }
  }

  /* End of Switch: '<S217>/Switch1' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_TPC_10ms' */

  /* Inport: '<Root>/RP_SWC_HSPF_HSPF_tIgbtTjFlt' */
  Rte_Read_RP_SWC_HSPF_HSPF_tIgbtTjFlt(&rtb_DataTypeConversion1);

  /* Inport: '<Root>/RP_SWC_HSPF_HSPF_tDrvBoardTempFlt' */
  Rte_Read_RP_SWC_HSPF_HSPF_tDrvBoardTempFlt(&rtb_Subtract_gc);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_TPC_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_TPC_10ms_sys'
   */
  /* Switch: '<S215>/Switch' incorporates:
   *  RelationalOperator: '<S215>/Relational Operator'
   */
  if (VAR_TpcTmp_CofDertDbc_f32 <= VAR_TpcTmp_CofDertTRiseDbc_f32) {
    rtb_Switch_iq = VAR_TpcTmp_CofDertDbc_f32;
  } else {
    rtb_Switch_iq = VAR_TpcTmp_CofDertTRiseDbc_f32;
  }

  /* End of Switch: '<S215>/Switch' */

  /* RelationalOperator: '<S211>/Relational Operator' incorporates:
   *  Constant: '<S211>/Coefficient1.0'
   *  Constant: '<S211>/ZeroValue'
   *  Sum: '<S211>/Add'
   */
  VAR_TpcTmp_flgTrqLimTdbcActv_b = (1.0F - rtb_Switch_iq > 1.0E-6F);

  /* Sum: '<S210>/Add' incorporates:
   *  Constant: '<S210>/Constant'
   *  DataTypeConversion: '<S210>/Data Type Conversion'
   */
  VAR_TpcTmp_TDbcOvHiWarnState_u8 = (uint8)(VAR_TpcTmp_flgTrqLimTdbcActv_b + 2U);

  /* FunctionCaller: '<S1>/RP_SWC_Dem_TPC_TDbcOvHiWarn_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_TPC_TDbcOvHiWarn_SetEventStatus
    (VAR_TpcTmp_TDbcOvHiWarnState_u8);

  /* Switch: '<S210>/Switch' incorporates:
   *  RelationalOperator: '<S210>/Relational Operator'
   */
  if (rtb_TmpSignalConversionAtRP_S_k <= rtb_TmpSignalConversionAtRP_S_i) {
    rtb_Switch_ba = rtb_TmpSignalConversionAtRP_S_k;
  } else {
    rtb_Switch_ba = rtb_TmpSignalConversionAtRP_S_i;
  }

  /* End of Switch: '<S210>/Switch' */

  /* Switch: '<S210>/Switch1' incorporates:
   *  RelationalOperator: '<S210>/Relational Operator1'
   */
  if (rtb_Switch_ba > rtb_TmpSignalConversionAtRP__jn) {
    rtb_Switch_ba = rtb_TmpSignalConversionAtRP__jn;
  }

  /* End of Switch: '<S210>/Switch1' */

  /* Sum: '<S210>/Add1' incorporates:
   *  Constant: '<S210>/CAL_TpcTmp_tDbcThrPhLoLim_f32'
   *  Constant: '<S210>/Constant1'
   *  RelationalOperator: '<S210>/Relational Operator2'
   */
  VAR_TpcTmp_TDbcOvLoWarnState_u8 = (uint8)((rtb_Switch_ba <=
    CAL_TpcTmp_tDbcThrPhLoLim_f32) + 2U);

  /* FunctionCaller: '<S1>/RP_SWC_Dem_TPC_TDbcOvLoWarn_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_TPC_TDbcOvLoWarn_SetEventStatus
    (VAR_TpcTmp_TDbcOvLoWarnState_u8);

  /* Sum: '<S210>/Add2' incorporates:
   *  Constant: '<S210>/CAL_TpcTmp_tDbcTempUHiLim_f32'
   *  Constant: '<S210>/Constant2'
   *  RelationalOperator: '<S210>/Relational Operator3'
   */
  VAR_TpcTmp_TDbcUHiLimErrState_u8 = (uint8)((rtb_TmpSignalConversionAtRP_S_k >=
    CAL_TpcTmp_tDbcTempUHiLim_f32) + 2U);

  /* FunctionCaller: '<S1>/RP_SWC_Dem_TPC_TDbcUHiLimFail_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_TPC_TDbcUHiLimFail_SetEventStatus
    (VAR_TpcTmp_TDbcUHiLimErrState_u8);

  /* Sum: '<S210>/Add3' incorporates:
   *  Constant: '<S210>/CAL_TpcTmp_tDbcTempULoLim_f32'
   *  Constant: '<S210>/Constant3'
   *  RelationalOperator: '<S210>/Relational Operator4'
   */
  VAR_TpcTmp_TDbcULoLimErrState_u8 = (uint8)((rtb_TmpSignalConversionAtRP_S_k <=
    CAL_TpcTmp_tDbcTempULoLim_f32) + 2U);

  /* FunctionCaller: '<S1>/RP_SWC_Dem_TPC_TDbcULoLimFail_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_TPC_TDbcULoLimFail_SetEventStatus
    (VAR_TpcTmp_TDbcULoLimErrState_u8);

  /* Sum: '<S210>/Add4' incorporates:
   *  Constant: '<S210>/CAL_TpcTmp_tDbcTempVHiLim_f32'
   *  Constant: '<S210>/Constant4'
   *  RelationalOperator: '<S210>/Relational Operator5'
   */
  VAR_TpcTmp_TDbcVHiLimErrState_u8 = (uint8)((rtb_TmpSignalConversionAtRP_S_i >=
    CAL_TpcTmp_tDbcTempVHiLim_f32) + 2U);

  /* FunctionCaller: '<S1>/RP_SWC_Dem_TPC_TDbcVHiLimFail_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_TPC_TDbcVHiLimFail_SetEventStatus
    (VAR_TpcTmp_TDbcVHiLimErrState_u8);

  /* Sum: '<S210>/Add5' incorporates:
   *  Constant: '<S210>/CAL_TpcTmp_tDbcTempVLoLim_f32'
   *  Constant: '<S210>/Constant5'
   *  RelationalOperator: '<S210>/Relational Operator6'
   */
  VAR_TpcTmp_TDbcVLoLimErrState_u8 = (uint8)((rtb_TmpSignalConversionAtRP_S_i <=
    CAL_TpcTmp_tDbcTempVLoLim_f32) + 2U);

  /* FunctionCaller: '<S1>/RP_SWC_Dem_TPC_TDbcVLoLimFail_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_TPC_TDbcVLoLimFail_SetEventStatus
    (VAR_TpcTmp_TDbcVLoLimErrState_u8);

  /* Sum: '<S210>/Add6' incorporates:
   *  Constant: '<S210>/CAL_TpcTmp_tDbcTempWHiLim_f32'
   *  Constant: '<S210>/Constant6'
   *  RelationalOperator: '<S210>/Relational Operator7'
   */
  VAR_TpcTmp_TDbcWHiLimErrState_u8 = (uint8)((rtb_TmpSignalConversionAtRP__jn >=
    CAL_TpcTmp_tDbcTempWHiLim_f32) + 2U);

  /* FunctionCaller: '<S1>/RP_SWC_Dem_TPC_TDbcWHiLimFail_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_TPC_TDbcWHiLimFail_SetEventStatus
    (VAR_TpcTmp_TDbcWHiLimErrState_u8);

  /* Sum: '<S210>/Add7' incorporates:
   *  Constant: '<S210>/CAL_TpcTmp_tDbcTempWLoLim_f32'
   *  Constant: '<S210>/Constant7'
   *  RelationalOperator: '<S210>/Relational Operator8'
   */
  VAR_TpcTmp_TDbcWLoLimErrState_u8 = (uint8)((rtb_TmpSignalConversionAtRP__jn <=
    CAL_TpcTmp_tDbcTempWLoLim_f32) + 2U);

  /* FunctionCaller: '<S1>/RP_SWC_Dem_TPC_TDbcWLoLimFail_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_TPC_TDbcWLoLimFail_SetEventStatus
    (VAR_TpcTmp_TDbcWLoLimErrState_u8);

  /* Lookup_n-D: '<S228>/DrvBoardTempDeratingTable' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_tDrvBoardTempFlt'
   */
  VAR_TpcTmp_CofDertTdrvboard_f32 = look1_iflf_binlcapw(rtb_Subtract_gc, ((const
    float32 *)&(CAL_TpcTmp_tDrvboardDertTableX_tDrv_af32[0])), ((const float32 *)
    &(CAL_TpcTmp_tDrvboardDertTableY_Cof_af32[0])), 8U);

  /* RelationalOperator: '<S229>/Relational Operator' incorporates:
   *  Constant: '<S229>/Coefficient1.0'
   *  Constant: '<S229>/ZeroValue'
   *  Sum: '<S229>/Add'
   */
  VAR_TpcTmp_flgTrqLimTdrvboardActv_b = (1.0F - VAR_TpcTmp_CofDertTdrvboard_f32 >
    1.0E-6F);

  /* Sum: '<S227>/Add' incorporates:
   *  Constant: '<S227>/Constant'
   *  DataTypeConversion: '<S227>/Data Type Conversion'
   */
  VAR_TpcTmp_TDrvBoardOvHiWarnState_u8 = (uint8)
    (VAR_TpcTmp_flgTrqLimTdrvboardActv_b + 2U);

  /* FunctionCaller: '<S1>/RP_SWC_Dem_TPC_TDrvBoardOvHiWarn_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_TPC_TDrvBoardOvHiWarn_SetEventStatus
    (VAR_TpcTmp_TDrvBoardOvHiWarnState_u8);

  /* DataTypeConversion: '<S236>/Data Type Conversion' */
  rtb_Add = fmodf(roundf(rtb_DataTypeConversion1), 65536.0F);
  VAR_TpcTmp_tIgbtTempFlt_u16 = (sint16)(rtb_Add < 0.0F ? (sint32)(sint16)-
    (sint16)(uint16)-rtb_Add : (sint32)(sint16)(uint16)rtb_Add);

  /* Sum: '<S236>/Add' incorporates:
   *  UnitDelay: '<S236>/Unit Delay1'
   */
  rtb_Add = (float32)VAR_TpcTmp_tIgbtTempFlt_u16 -
    SWC_TPC_DW.UnitDelay1_DSTATE_h;

  /* Switch: '<S236>/Switch1' incorporates:
   *  Constant: '<S197>/CAL_TpcTmp_IGBTTempAdds_f32'
   *  Constant: '<S197>/CAL_TpcTmp_IGBTTempDecDiff_f32'
   *  Constant: '<S197>/CAL_TpcTmp_IGBTTempRiseDiff_f32'
   *  RelationalOperator: '<S236>/Relational Operator'
   *  RelationalOperator: '<S236>/Relational Operator1'
   *  Sum: '<S236>/Add1'
   *  Switch: '<S236>/Switch'
   *  UnitDelay: '<S236>/Unit Delay1'
   */
  if (rtb_Add >= CAL_TpcTmp_IGBTTempRiseDiff_f32) {
    SWC_TPC_DW.UnitDelay1_DSTATE_h += CAL_TpcTmp_IGBTTempAdds_f32;
  } else {
    if (rtb_Add <= CAL_TpcTmp_IGBTTempDecDiff_f32) {
      /* UnitDelay: '<S236>/Unit Delay1' incorporates:
       *  Constant: '<S197>/CAL_TpcTmp_IGBTTempMinus_f32'
       *  Sum: '<S236>/Add2'
       *  Switch: '<S236>/Switch'
       */
      SWC_TPC_DW.UnitDelay1_DSTATE_h += CAL_TpcTmp_IGBTTempMinus_f32;
    }
  }

  /* End of Switch: '<S236>/Switch1' */

  /* Sum: '<S236>/Add4' */
  rtb_Switch_ba = rtb_Add - (float32)VAR_TpcTmp_TIgbtStableDiff_u16;

  /* Switch: '<S236>/Switch2' incorporates:
   *  Constant: '<S245>/Constant'
   *  Constant: '<S246>/Constant'
   *  Logic: '<S236>/Logical Operator'
   *  RelationalOperator: '<S245>/Compare'
   *  RelationalOperator: '<S246>/Compare'
   */
  if ((rtb_Switch_ba >= CAL_TpcTmp_IgbtChgTempUpDiff_f32) || (rtb_Switch_ba <=
       CAL_TpcTmp_IgbtChgTempDownDiff_f32)) {
    rtb_Add = fmodf(floorf(rtb_Add), 65536.0F);
    VAR_TpcTmp_TIgbtStableDiff_u16 = (sint16)(rtb_Add < 0.0F ? (sint32)(sint16)-
      (sint16)(uint16)-rtb_Add : (sint32)(sint16)(uint16)rtb_Add);
  }

  /* End of Switch: '<S236>/Switch2' */

  /* Product: '<S236>/Product' incorporates:
   *  Constant: '<S197>/CAL_TpcTmp_IGBTTempKp_f32'
   */
  rtb_Add = CAL_TpcTmp_IGBTTempKp_f32 * (float32)VAR_TpcTmp_TIgbtStableDiff_u16;

  /* Saturate: '<S236>/Saturation' */
  if (rtb_Add > 0.9F) {
    rtb_Add = 0.9F;
  } else {
    if (rtb_Add < -0.9F) {
      rtb_Add = -0.9F;
    }
  }

  /* End of Saturate: '<S236>/Saturation' */

  /* Sum: '<S236>/Add3' incorporates:
   *  UnitDelay: '<S236>/Unit Delay1'
   */
  VAR_TpcTmp_tIGBTTempFlt_f32 = SWC_TPC_DW.UnitDelay1_DSTATE_h + rtb_Add;

  /* Sum: '<S230>/Add2' incorporates:
   *  Constant: '<S230>/CAL_TpcTmp_tIGBTTempHiLim_f32'
   *  Constant: '<S230>/Constant2'
   *  RelationalOperator: '<S230>/Relational Operator9'
   */
  VAR_TpcTmp_TIGBTOvHiErrState_u8 = (uint8)((VAR_TpcTmp_tIGBTTempFlt_f32 >=
    CAL_TpcTmp_tIGBTTempHiLim_f32) + 2U);

  /* FunctionCaller: '<S1>/RP_SWC_Dem_TPC_TIGBTOvHiLimFail_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_TPC_TIGBTOvHiLimFail_SetEventStatus
    (VAR_TpcTmp_TIGBTOvHiErrState_u8);

  /* Lookup_n-D: '<S234>/IGBTTempDeratingSave1Table' */
  VAR_TpcTmp_CofDertTIGBTSave1_f32 = look1_iflf_binlxpw
    (VAR_TpcTmp_tIGBTTempFlt_f32, ((const float32 *)
      &(CAL_TpcTmp_tIGBTDertSave1TableX_tSttr_af32[0])), ((const float32 *)
      &(CAL_TpcTmp_tIGBTDertSave1TableY_Cof_af32[0])), 8U);

  /* Chart: '<S234>/PowerSaveMod_tIGBT' */
  if (SWC_TPC_DW.is_active_c6_SWC_TPC == 0U) {
    SWC_TPC_DW.is_active_c6_SWC_TPC = 1U;
    SWC_TPC_DW.is_c6_SWC_TPC = SWC_TPC_IN_NormalMode;
    VAR_TpcTmp_tIGBTOperationMode_u8 = CAL_Tpc_NormalMode_u8;
  } else {
    switch (SWC_TPC_DW.is_c6_SWC_TPC) {
     case SWC_TPC_IN_NormalMode:
      if (VAR_TpcTmp_tIGBTTempFlt_f32 > CAL_TpcTmp_tIGBTTraNormalToSave1_f32) {
        SWC_TPC_DW.is_c6_SWC_TPC = SWC_TPC_IN_PowerSave1;
        VAR_TpcTmp_tIGBTOperationMode_u8 = CAL_Tpc_Powersave1Mode_u8;
      }
      break;

     case SWC_TPC_IN_Overheating:
      break;

     case SWC_TPC_IN_PowerSave1:
      if (VAR_TpcTmp_tIGBTTempFlt_f32 < CAL_TpcTmp_tIGBTTraSave1ToNormal_f32) {
        SWC_TPC_DW.is_c6_SWC_TPC = SWC_TPC_IN_NormalMode;
        VAR_TpcTmp_tIGBTOperationMode_u8 = CAL_Tpc_NormalMode_u8;
      } else {
        if (VAR_TpcTmp_tIGBTTempFlt_f32 > CAL_TpcTmp_tIGBTTraSave1ToSave2_f32) {
          SWC_TPC_DW.is_c6_SWC_TPC = SWC_TPC_IN_PowerSave2;
          VAR_TpcTmp_tIGBTOperationMode_u8 = CAL_Tpc_Powersave2Mode_u8;
        }
      }
      break;

     default:
      /* case IN_PowerSave2: */
      if (VAR_TpcTmp_tIGBTTempFlt_f32 >
          CAL_TpcTmp_tIGBTTraSave2ToOverheating_f32) {
        SWC_TPC_DW.is_c6_SWC_TPC = SWC_TPC_IN_Overheating;
        VAR_TpcTmp_tIGBTOperationMode_u8 = CAL_Tpc_OverheatingMode_u8;
      }
      break;
    }
  }

  /* End of Chart: '<S234>/PowerSaveMod_tIGBT' */

  /* Chart: '<S234>/GetHighTemp' incorporates:
   *  UnitDelay: '<S234>/Unit Delay2'
   */
  SWC_TPC_GetHighTemp(VAR_TpcTmp_tIGBTTempFlt_f32,
                      SWC_TPC_DW.UnitDelay2_DSTATE_bo, &rtb_TModuleTempHighest_p);

  /* Lookup_n-D: '<S234>/IGBTTempDeratingSave2Table' */
  VAR_TpcTmp_CofDertTIGBTSave2_f32 = look1_iflf_binlxpw(rtb_TModuleTempHighest_p,
    ((const float32 *)&(CAL_TpcTmp_tIGBTDertSave2TableX_tSttr_af32[0])), ((const
    float32 *)&(CAL_TpcTmp_tIGBTDertSave2TableY_Cof_af32[0])), 8U);

  /* Switch: '<S234>/Switch1' incorporates:
   *  Constant: '<S234>/CAL_Tpc_NormalMode_u8'
   *  Constant: '<S234>/CAL_Tpc_OverheatingMode_u8'
   *  Constant: '<S234>/CAL_Tpc_Powersave1Mode_u8'
   *  Constant: '<S234>/CAL_Tpc_Powersave2Mode_u8'
   *  Logic: '<S234>/Logical Operator'
   *  Logic: '<S234>/Logical Operator1'
   *  RelationalOperator: '<S234>/Relational Operator'
   *  RelationalOperator: '<S234>/Relational Operator1'
   *  RelationalOperator: '<S234>/Relational Operator2'
   *  RelationalOperator: '<S234>/Relational Operator3'
   *  Switch: '<S234>/Switch2'
   */
  if ((VAR_TpcTmp_tIGBTOperationMode_u8 == CAL_Tpc_NormalMode_u8) ||
      (VAR_TpcTmp_tIGBTOperationMode_u8 == CAL_Tpc_Powersave1Mode_u8)) {
    VAR_TpcTmp_CofDertIGBT_f32 = VAR_TpcTmp_CofDertTIGBTSave1_f32;
  } else {
    if ((VAR_TpcTmp_tIGBTOperationMode_u8 == CAL_Tpc_Powersave2Mode_u8) ||
        (VAR_TpcTmp_tIGBTOperationMode_u8 == CAL_Tpc_OverheatingMode_u8)) {
      /* Switch: '<S234>/Switch2' */
      VAR_TpcTmp_CofDertIGBT_f32 = VAR_TpcTmp_CofDertTIGBTSave2_f32;
    }
  }

  /* End of Switch: '<S234>/Switch1' */

  /* Sum: '<S235>/Add' */
  VAR_TpcTmp_tRiseIGBT_f32 = VAR_TpcTmp_tIGBTTempFlt_f32 - (float32)
    VAR_TpcTmp_tCoolTempFlt_u16;

  /* DataTypeConversion: '<S241>/Data Type Conversion' */
  rtb_Add = fmodf(roundf(VAR_TpcTmp_tRiseIGBT_f32), 65536.0F);
  VAR_TpcTmp_tIgbtRiseTempFlt_u16 = (sint16)(rtb_Add < 0.0F ? (sint32)(sint16)-
    (sint16)(uint16)-rtb_Add : (sint32)(sint16)(uint16)rtb_Add);

  /* Sum: '<S241>/Add' incorporates:
   *  UnitDelay: '<S241>/Unit Delay1'
   */
  rtb_Add = (float32)VAR_TpcTmp_tIgbtRiseTempFlt_u16 -
    SWC_TPC_DW.UnitDelay1_DSTATE_n;

  /* Switch: '<S241>/Switch1' incorporates:
   *  Constant: '<S235>/CAL_TpcTmp_IGBRiseTTempAdds_f32'
   *  Constant: '<S235>/CAL_TpcTmp_IGBTRiseTempDecDiff_f32'
   *  Constant: '<S235>/CAL_TpcTmp_IGBTRiseTempRiseDiff_f32'
   *  RelationalOperator: '<S241>/Relational Operator'
   *  RelationalOperator: '<S241>/Relational Operator1'
   *  Sum: '<S241>/Add1'
   *  Switch: '<S241>/Switch'
   *  UnitDelay: '<S241>/Unit Delay1'
   */
  if (rtb_Add >= CAL_TpcTmp_IGBTRiseTempRiseDiff_f32) {
    SWC_TPC_DW.UnitDelay1_DSTATE_n += CAL_TpcTmp_IGBRiseTTempAdds_f32;
  } else {
    if (rtb_Add <= CAL_TpcTmp_IGBTRiseTempDecDiff_f32) {
      /* UnitDelay: '<S241>/Unit Delay1' incorporates:
       *  Constant: '<S235>/CAL_TpcTmp_IGBTRiseTempMinus_f32'
       *  Sum: '<S241>/Add2'
       *  Switch: '<S241>/Switch'
       */
      SWC_TPC_DW.UnitDelay1_DSTATE_n += CAL_TpcTmp_IGBTRiseTempMinus_f32;
    }
  }

  /* End of Switch: '<S241>/Switch1' */

  /* Sum: '<S241>/Add4' */
  rtb_Switch_ba = rtb_Add - (float32)VAR_TpcTmp_TIgbtRiseStableDiff_u16;

  /* Switch: '<S241>/Switch2' incorporates:
   *  Constant: '<S243>/Constant'
   *  Constant: '<S244>/Constant'
   *  Logic: '<S241>/Logical Operator'
   *  RelationalOperator: '<S243>/Compare'
   *  RelationalOperator: '<S244>/Compare'
   */
  if ((rtb_Switch_ba >= CAL_TpcTmp_IgbtRiseChgTempUpDiff_f32) || (rtb_Switch_ba <=
       CAL_TpcTmp_IgbtRiseChgTempDownDiff_f32)) {
    rtb_Add = fmodf(floorf(rtb_Add), 65536.0F);
    VAR_TpcTmp_TIgbtRiseStableDiff_u16 = (sint16)(rtb_Add < 0.0F ? (sint32)
      (sint16)-(sint16)(uint16)-rtb_Add : (sint32)(sint16)(uint16)rtb_Add);
  }

  /* End of Switch: '<S241>/Switch2' */

  /* Product: '<S241>/Product' incorporates:
   *  Constant: '<S235>/CAL_TpcTmp_IGBTRiseTempKp_f32'
   */
  rtb_Add = CAL_TpcTmp_IGBTRiseTempKp_f32 * (float32)
    VAR_TpcTmp_TIgbtRiseStableDiff_u16;

  /* Saturate: '<S241>/Saturation' */
  if (rtb_Add > 0.9F) {
    rtb_Add = 0.9F;
  } else {
    if (rtb_Add < -0.9F) {
      rtb_Add = -0.9F;
    }
  }

  /* End of Saturate: '<S241>/Saturation' */

  /* Sum: '<S241>/Add3' incorporates:
   *  UnitDelay: '<S241>/Unit Delay1'
   */
  VAR_TpcTmp_tRiseIGBTFlt_f32 = SWC_TPC_DW.UnitDelay1_DSTATE_n + rtb_Add;

  /* Lookup_n-D: '<S235>/IGBTRiseTempDeratingSave1Table' */
  VAR_TpcTmp_CofDertTRiseIGBTSave1_f32 = look1_iflf_binlxpw
    (VAR_TpcTmp_tRiseIGBTFlt_f32, ((const float32 *)
      &(CAL_TpcTmp_tRiseIGBTDertSave1TableX_tSttr_af32[0])), ((const float32 *)
      &(CAL_TpcTmp_tRiseIGBTDertSave1TableY_Cof_af32[0])), 8U);

  /* Chart: '<S235>/PowerSaveMod_tRiseIGBT' */
  if (SWC_TPC_DW.is_active_c7_SWC_TPC == 0U) {
    SWC_TPC_DW.is_active_c7_SWC_TPC = 1U;
    SWC_TPC_DW.is_c7_SWC_TPC = SWC_TPC_IN_NormalMode;
    VAR_TpcTmp_tRiseIGBTOperationMode_u8 = CAL_Tpc_NormalMode_u8;
  } else {
    switch (SWC_TPC_DW.is_c7_SWC_TPC) {
     case SWC_TPC_IN_NormalMode:
      if (VAR_TpcTmp_tRiseIGBTFlt_f32 > CAL_TpcTmp_tRiseIGBTTraNormalToSave1_f32)
      {
        SWC_TPC_DW.is_c7_SWC_TPC = SWC_TPC_IN_PowerSave1;
        VAR_TpcTmp_tRiseIGBTOperationMode_u8 = CAL_Tpc_Powersave1Mode_u8;
      }
      break;

     case SWC_TPC_IN_Overheating:
      break;

     case SWC_TPC_IN_PowerSave1:
      if (VAR_TpcTmp_tRiseIGBTFlt_f32 < CAL_TpcTmp_tRiseIGBTTraSave1ToNormal_f32)
      {
        SWC_TPC_DW.is_c7_SWC_TPC = SWC_TPC_IN_NormalMode;
        VAR_TpcTmp_tRiseIGBTOperationMode_u8 = CAL_Tpc_NormalMode_u8;
      } else {
        if (VAR_TpcTmp_tRiseIGBTFlt_f32 >
            CAL_TpcTmp_tRiseIGBTTraSave1ToSave2_f32) {
          SWC_TPC_DW.is_c7_SWC_TPC = SWC_TPC_IN_PowerSave2;
          VAR_TpcTmp_tRiseIGBTOperationMode_u8 = CAL_Tpc_Powersave2Mode_u8;
        }
      }
      break;

     default:
      /* case IN_PowerSave2: */
      if (VAR_TpcTmp_tRiseIGBTFlt_f32 >
          CAL_TpcTmp_tRiseIGBTTraSave2ToOverheating_f32) {
        SWC_TPC_DW.is_c7_SWC_TPC = SWC_TPC_IN_Overheating;
        VAR_TpcTmp_tRiseIGBTOperationMode_u8 = CAL_Tpc_OverheatingMode_u8;
      }
      break;
    }
  }

  /* End of Chart: '<S235>/PowerSaveMod_tRiseIGBT' */

  /* Chart: '<S235>/GetHighTemp' incorporates:
   *  UnitDelay: '<S235>/Unit Delay2'
   */
  SWC_TPC_GetHighTemp(VAR_TpcTmp_tRiseIGBTFlt_f32,
                      SWC_TPC_DW.UnitDelay2_DSTATE_a, &rtb_TModuleTempHighest);

  /* Lookup_n-D: '<S235>/IGBTRiseTempDeratingSave2Table' */
  VAR_TpcTmp_CofDertTRiseIGBTSave2_f32 = look1_iflf_binlxpw
    (rtb_TModuleTempHighest, ((const float32 *)
      &(CAL_TpcTmp_tRiseIGBTDertSave2TableX_tSttr_af32[0])), ((const float32 *)
      &(CAL_TpcTmp_tRiseIGBTDertSave2TableY_Cof_af32[0])), 8U);

  /* Switch: '<S235>/Switch1' incorporates:
   *  Constant: '<S235>/CAL_Tpc_NormalMode_u8'
   *  Constant: '<S235>/CAL_Tpc_OverheatingMode_u8'
   *  Constant: '<S235>/CAL_Tpc_Powersave1Mode_u8'
   *  Constant: '<S235>/CAL_Tpc_Powersave2Mode_u8'
   *  Logic: '<S235>/Logical Operator'
   *  Logic: '<S235>/Logical Operator1'
   *  RelationalOperator: '<S235>/Relational Operator'
   *  RelationalOperator: '<S235>/Relational Operator1'
   *  RelationalOperator: '<S235>/Relational Operator2'
   *  RelationalOperator: '<S235>/Relational Operator3'
   *  Switch: '<S235>/Switch2'
   */
  if ((VAR_TpcTmp_tRiseIGBTOperationMode_u8 == CAL_Tpc_NormalMode_u8) ||
      (VAR_TpcTmp_tRiseIGBTOperationMode_u8 == CAL_Tpc_Powersave1Mode_u8)) {
    VAR_TpcTmp_CofDertTRiseIGBT_f32 = VAR_TpcTmp_CofDertTRiseIGBTSave1_f32;
  } else {
    if ((VAR_TpcTmp_tRiseIGBTOperationMode_u8 == CAL_Tpc_Powersave2Mode_u8) ||
        (VAR_TpcTmp_tRiseIGBTOperationMode_u8 == CAL_Tpc_OverheatingMode_u8)) {
      /* Switch: '<S235>/Switch2' */
      VAR_TpcTmp_CofDertTRiseIGBT_f32 = VAR_TpcTmp_CofDertTRiseIGBTSave2_f32;
    }
  }

  /* End of Switch: '<S235>/Switch1' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_TPC_10ms' */

  /* Inport: '<Root>/RP_SWC_HSPF_HSPF_tStrrTempFlt' */
  Rte_Read_RP_SWC_HSPF_HSPF_tStrrTempFlt(&rtb_Product1_o);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_TPC_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_TPC_10ms_sys'
   */
  /* Switch: '<S231>/Switch' incorporates:
   *  RelationalOperator: '<S231>/Relational Operator'
   */
  if (VAR_TpcTmp_CofDertIGBT_f32 <= VAR_TpcTmp_CofDertTRiseIGBT_f32) {
    rtb_Switch_ba = VAR_TpcTmp_CofDertIGBT_f32;
  } else {
    rtb_Switch_ba = VAR_TpcTmp_CofDertTRiseIGBT_f32;
  }

  /* End of Switch: '<S231>/Switch' */

  /* RelationalOperator: '<S237>/Relational Operator' incorporates:
   *  Constant: '<S237>/Coefficient1.0'
   *  Constant: '<S237>/ZeroValue'
   *  Sum: '<S237>/Add'
   */
  VAR_TpcTmp_flgTrqLimTIGBTActv_b = (1.0F - rtb_Switch_ba > 1.0E-6F);

  /* Sum: '<S230>/Add' incorporates:
   *  Constant: '<S230>/Constant'
   *  DataTypeConversion: '<S230>/Data Type Conversion'
   */
  VAR_TpcTmp_TIGBTOvHiWarnState_u8 = (uint8)(VAR_TpcTmp_flgTrqLimTIGBTActv_b +
    2U);

  /* FunctionCaller: '<S1>/RP_SWC_Dem_TPC_TIGBTOvHiWarn_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_TPC_TIGBTOvHiWarn_SetEventStatus
    (VAR_TpcTmp_TIGBTOvHiWarnState_u8);

  /* Sum: '<S230>/Add1' incorporates:
   *  Constant: '<S230>/CAL_TpcTmp_tIGBTTempLoLim_f32'
   *  Constant: '<S230>/Constant1'
   *  RelationalOperator: '<S230>/Relational Operator1'
   */
  VAR_TpcTmp_TIGBTOvLoWarnState_u8 = (uint8)((VAR_TpcTmp_tIGBTTempFlt_f32 <=
    CAL_TpcTmp_tIGBTTempLoLim_f32) + 2U);

  /* FunctionCaller: '<S1>/RP_SWC_Dem_TPC_TIGBTOvLoWarn_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_TPC_TIGBTOvLoWarn_SetEventStatus
    (VAR_TpcTmp_TIGBTOvLoWarnState_u8);

  /* DataTypeConversion: '<S132>/Data Type Conversion' */
  rtb_Add = fmodf(roundf(rtb_Product1_o), 65536.0F);
  VAR_TpcMot_tSttrTempFlt_u16 = (sint16)(rtb_Add < 0.0F ? (sint32)(sint16)-
    (sint16)(uint16)-rtb_Add : (sint32)(sint16)(uint16)rtb_Add);

  /* Sum: '<S132>/Add' incorporates:
   *  UnitDelay: '<S132>/Unit Delay1'
   */
  rtb_Add = (float32)VAR_TpcMot_tSttrTempFlt_u16 -
    SWC_TPC_DW.UnitDelay1_DSTATE_a;

  /* Switch: '<S132>/Switch1' incorporates:
   *  Constant: '<S119>/CAL_TpcMot_SttrTempAdds_f32'
   *  Constant: '<S119>/CAL_TpcMot_SttrTempDecDiff_f32'
   *  Constant: '<S119>/CAL_TpcMot_SttrTempRiseDiff_f32'
   *  RelationalOperator: '<S132>/Relational Operator'
   *  RelationalOperator: '<S132>/Relational Operator1'
   *  Sum: '<S132>/Add1'
   *  Switch: '<S132>/Switch'
   *  UnitDelay: '<S132>/Unit Delay1'
   */
  if (rtb_Add >= CAL_TpcMot_SttrTempRiseDiff_f32) {
    SWC_TPC_DW.UnitDelay1_DSTATE_a += CAL_TpcMot_SttrTempAdds_f32;
  } else {
    if (rtb_Add <= CAL_TpcMot_SttrTempDecDiff_f32) {
      /* UnitDelay: '<S132>/Unit Delay1' incorporates:
       *  Constant: '<S119>/CAL_TpcMot_SttrTempMinus_f32'
       *  Sum: '<S132>/Add2'
       *  Switch: '<S132>/Switch'
       */
      SWC_TPC_DW.UnitDelay1_DSTATE_a += CAL_TpcMot_SttrTempMinus_f32;
    }
  }

  /* End of Switch: '<S132>/Switch1' */

  /* Sum: '<S132>/Add4' */
  rtb_Switch_f4 = rtb_Add - (float32)VAR_TpcMot_TsttrStableDiff_u16;

  /* Switch: '<S132>/Switch2' incorporates:
   *  Constant: '<S138>/Constant'
   *  Constant: '<S139>/Constant'
   *  Logic: '<S132>/Logical Operator'
   *  RelationalOperator: '<S138>/Compare'
   *  RelationalOperator: '<S139>/Compare'
   */
  if ((rtb_Switch_f4 >= CAL_TpcMot_SttrChgTempUpDiff_f32) || (rtb_Switch_f4 <=
       CAL_TpcMot_SttrChgTempDownDiff_f32)) {
    rtb_Add = fmodf(floorf(rtb_Add), 65536.0F);
    VAR_TpcMot_TsttrStableDiff_u16 = (sint16)(rtb_Add < 0.0F ? (sint32)(sint16)-
      (sint16)(uint16)-rtb_Add : (sint32)(sint16)(uint16)rtb_Add);
  }

  /* End of Switch: '<S132>/Switch2' */

  /* Product: '<S132>/Product' incorporates:
   *  Constant: '<S119>/CAL_TpcMot_SttrTempKp_f32'
   */
  rtb_Add = CAL_TpcMot_SttrTempKp_f32 * (float32)VAR_TpcMot_TsttrStableDiff_u16;

  /* Saturate: '<S132>/Saturation' */
  if (rtb_Add > 0.9F) {
    rtb_Add = 0.9F;
  } else {
    if (rtb_Add < -0.9F) {
      rtb_Add = -0.9F;
    }
  }

  /* End of Saturate: '<S132>/Saturation' */

  /* Sum: '<S132>/Add3' incorporates:
   *  UnitDelay: '<S132>/Unit Delay1'
   */
  VAR_TpcMot_tSttrTempFlt_f32 = SWC_TPC_DW.UnitDelay1_DSTATE_a + rtb_Add;

  /* Sum: '<S126>/Add1' incorporates:
   *  Constant: '<S126>/CAL_TpcMot_tSttrHiLim_f32'
   *  Constant: '<S126>/Constant1'
   *  RelationalOperator: '<S126>/Relational Operator'
   */
  VAR_TpcMot_TSttrOvHiLimErrState_u8 = (uint8)((VAR_TpcMot_tSttrTempFlt_f32 >=
    CAL_TpcMot_tSttrHiLim_f32) + 2U);

  /* FunctionCaller: '<S1>/RP_SWC_Dem_TPC_TSttrOvHiLimFail_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_TPC_TSttrOvHiLimFail_SetEventStatus
    (VAR_TpcMot_TSttrOvHiLimErrState_u8);

  /* Lookup_n-D: '<S131>/SttrTempDeratingSave1Table' */
  VAR_TpcMot_CofDertTSttrSave1_f32 = look1_iflf_binlxpw
    (VAR_TpcMot_tSttrTempFlt_f32, ((const float32 *)
      &(CAL_TpcMot_tSttrDertSave1TableX_tSttr_af32[0])), ((const float32 *)
      &(CAL_TpcMot_tSttrDertSave1TableY_Cof_af32[0])), 8U);

  /* Chart: '<S131>/PowerSaveMod_tSttr' */
  if (SWC_TPC_DW.is_active_c12_SWC_TPC == 0U) {
    SWC_TPC_DW.is_active_c12_SWC_TPC = 1U;
    SWC_TPC_DW.is_c12_SWC_TPC = SWC_TPC_IN_NormalMode;
    VAR_TpcMot_tSttrOperationMode_u8 = CAL_Tpc_NormalMode_u8;
  } else {
    switch (SWC_TPC_DW.is_c12_SWC_TPC) {
     case SWC_TPC_IN_NormalMode:
      if (VAR_TpcMot_tSttrTempFlt_f32 > CAL_TpcMot_tSttrTraNormalToSave1_f32) {
        SWC_TPC_DW.is_c12_SWC_TPC = SWC_TPC_IN_PowerSave1;
        VAR_TpcMot_tSttrOperationMode_u8 = CAL_Tpc_Powersave1Mode_u8;
      }
      break;

     case SWC_TPC_IN_Overheating:
      break;

     case SWC_TPC_IN_PowerSave1:
      if (VAR_TpcMot_tSttrTempFlt_f32 < CAL_TpcMot_tSttrTraSave1ToNormal_f32) {
        SWC_TPC_DW.is_c12_SWC_TPC = SWC_TPC_IN_NormalMode;
        VAR_TpcMot_tSttrOperationMode_u8 = CAL_Tpc_NormalMode_u8;
      } else {
        if (VAR_TpcMot_tSttrTempFlt_f32 > CAL_TpcMot_tSttrTraSave1ToSave2_f32) {
          SWC_TPC_DW.is_c12_SWC_TPC = SWC_TPC_IN_PowerSave2;
          VAR_TpcMot_tSttrOperationMode_u8 = CAL_Tpc_Powersave2Mode_u8;
        }
      }
      break;

     default:
      /* case IN_PowerSave2: */
      if (VAR_TpcMot_tSttrTempFlt_f32 >
          CAL_TpcMot_tSttrTraSave2ToOverheating_f32) {
        SWC_TPC_DW.is_c12_SWC_TPC = SWC_TPC_IN_Overheating;
        VAR_TpcMot_tSttrOperationMode_u8 = CAL_Tpc_OverheatingMode_u8;
      }
      break;
    }
  }

  /* End of Chart: '<S131>/PowerSaveMod_tSttr' */

  /* Chart: '<S131>/GetHighTemp' incorporates:
   *  UnitDelay: '<S131>/Unit Delay2'
   */
  SWC_TPC_GetHighTemp(VAR_TpcMot_tSttrTempFlt_f32,
                      SWC_TPC_DW.UnitDelay2_DSTATE_k, &rtb_TModuleTempHighest_h);

  /* Lookup_n-D: '<S131>/SttrTempDeratingSave2Table' */
  VAR_TpcMot_CofDertTSttrSave2_f32 = look1_iflf_binlxpw(rtb_TModuleTempHighest_h,
    ((const float32 *)&(CAL_TpcMot_tSttrDertSave2TableX_tSttr_af32[0])), ((const
    float32 *)&(CAL_TpcMot_tSttrDertSave2TableY_Cof_af32[0])), 8U);

  /* Switch: '<S131>/Switch1' incorporates:
   *  Constant: '<S131>/CAL_Tpc_NormalMode_u8'
   *  Constant: '<S131>/CAL_Tpc_OverheatingMode_u8'
   *  Constant: '<S131>/CAL_Tpc_Powersave1Mode_u8'
   *  Constant: '<S131>/CAL_Tpc_Powersave2Mode_u8'
   *  Logic: '<S131>/Logical Operator'
   *  Logic: '<S131>/Logical Operator1'
   *  RelationalOperator: '<S131>/Relational Operator'
   *  RelationalOperator: '<S131>/Relational Operator1'
   *  RelationalOperator: '<S131>/Relational Operator2'
   *  RelationalOperator: '<S131>/Relational Operator3'
   *  Switch: '<S131>/Switch2'
   */
  if ((VAR_TpcMot_tSttrOperationMode_u8 == CAL_Tpc_NormalMode_u8) ||
      (VAR_TpcMot_tSttrOperationMode_u8 == CAL_Tpc_Powersave1Mode_u8)) {
    VAR_TpcMot_CofDertTsttr_f32 = VAR_TpcMot_CofDertTSttrSave1_f32;
  } else {
    if ((VAR_TpcMot_tSttrOperationMode_u8 == CAL_Tpc_Powersave2Mode_u8) ||
        (VAR_TpcMot_tSttrOperationMode_u8 == CAL_Tpc_OverheatingMode_u8)) {
      /* Switch: '<S131>/Switch2' */
      VAR_TpcMot_CofDertTsttr_f32 = VAR_TpcMot_CofDertTSttrSave2_f32;
    }
  }

  /* End of Switch: '<S131>/Switch1' */

  /* Sum: '<S130>/Add' */
  VAR_TpcMot_tRiseSttr_f32 = VAR_TpcMot_tSttrTempFlt_f32 -
    rtb_TmpSignalConversionAtRP__k0;

  /* Lookup_n-D: '<S130>/SttrRiseTempDeratingSave1Table' */
  VAR_TpcMot_CofDertTRiseSttrSave1_f32 = look1_iflf_binlxpw
    (VAR_TpcMot_tRiseSttr_f32, ((const float32 *)
      &(CAL_TpcMot_tRiseSttrDertSave1TableX_tSttr_af32[0])), ((const float32 *)
      &(CAL_TpcMot_tRiseSttrDertSave1TableY_Cof_af32[0])), 8U);

  /* Chart: '<S130>/PowerSaveMod_tRiseIGBT' */
  if (SWC_TPC_DW.is_active_c14_SWC_TPC == 0U) {
    SWC_TPC_DW.is_active_c14_SWC_TPC = 1U;
    SWC_TPC_DW.is_c14_SWC_TPC = SWC_TPC_IN_NormalMode;
    VAR_TpcMot_tRiseSttrOperationMode_u8 = CAL_Tpc_NormalMode_u8;
  } else {
    switch (SWC_TPC_DW.is_c14_SWC_TPC) {
     case SWC_TPC_IN_NormalMode:
      if (VAR_TpcMot_tRiseSttr_f32 > CAL_TpcMot_tRiseSttrTraNormalToSave1_f32) {
        SWC_TPC_DW.is_c14_SWC_TPC = SWC_TPC_IN_PowerSave1;
        VAR_TpcMot_tRiseSttrOperationMode_u8 = CAL_Tpc_Powersave1Mode_u8;
      }
      break;

     case SWC_TPC_IN_Overheating:
      break;

     case SWC_TPC_IN_PowerSave1:
      if (VAR_TpcMot_tRiseSttr_f32 < CAL_TpcMot_tRiseSttrTraSave1ToNormal_f32) {
        SWC_TPC_DW.is_c14_SWC_TPC = SWC_TPC_IN_NormalMode;
        VAR_TpcMot_tRiseSttrOperationMode_u8 = CAL_Tpc_NormalMode_u8;
      } else {
        if (VAR_TpcMot_tRiseSttr_f32 > CAL_TpcMot_tRiseSttrTraSave1ToSave2_f32)
        {
          SWC_TPC_DW.is_c14_SWC_TPC = SWC_TPC_IN_PowerSave2;
          VAR_TpcMot_tRiseSttrOperationMode_u8 = CAL_Tpc_Powersave2Mode_u8;
        }
      }
      break;

     default:
      /* case IN_PowerSave2: */
      if (VAR_TpcMot_tRiseSttr_f32 >
          CAL_TpcMot_tRiseSttrTraSave2ToOverheating_f32) {
        SWC_TPC_DW.is_c14_SWC_TPC = SWC_TPC_IN_Overheating;
        VAR_TpcMot_tRiseSttrOperationMode_u8 = CAL_Tpc_OverheatingMode_u8;
      }
      break;
    }
  }

  /* End of Chart: '<S130>/PowerSaveMod_tRiseIGBT' */

  /* Chart: '<S130>/GetHighTemp' incorporates:
   *  UnitDelay: '<S130>/Unit Delay2'
   */
  SWC_TPC_GetHighTemp(VAR_TpcMot_tRiseSttr_f32, SWC_TPC_DW.UnitDelay2_DSTATE_mz,
                      &rtb_TModuleTempHighest_e);

  /* Lookup_n-D: '<S130>/SttrRiseTempDeratingSave2Table' */
  VAR_TpcMot_CofDertTRiseSttrSave2_f32 = look1_iflf_binlxpw
    (rtb_TModuleTempHighest_e, ((const float32 *)
      &(CAL_TpcMot_tRiseSttrDertSave2TableX_tSttr_af32[0])), ((const float32 *)
      &(CAL_TpcMot_tRiseSttrDertSave2TableY_Cof_af32[0])), 8U);

  /* Switch: '<S130>/Switch1' incorporates:
   *  Constant: '<S130>/CAL_Tpc_NormalMode_u8'
   *  Constant: '<S130>/CAL_Tpc_OverheatingMode_u8'
   *  Constant: '<S130>/CAL_Tpc_Powersave1Mode_u8'
   *  Constant: '<S130>/CAL_Tpc_Powersave2Mode_u8'
   *  Logic: '<S130>/Logical Operator'
   *  Logic: '<S130>/Logical Operator1'
   *  RelationalOperator: '<S130>/Relational Operator'
   *  RelationalOperator: '<S130>/Relational Operator1'
   *  RelationalOperator: '<S130>/Relational Operator2'
   *  RelationalOperator: '<S130>/Relational Operator3'
   *  Switch: '<S130>/Switch2'
   */
  if ((VAR_TpcMot_tRiseSttrOperationMode_u8 == CAL_Tpc_NormalMode_u8) ||
      (VAR_TpcMot_tRiseSttrOperationMode_u8 == CAL_Tpc_Powersave1Mode_u8)) {
    VAR_TpcMot_CofDertTRiseSttr_f32 = VAR_TpcMot_CofDertTRiseSttrSave1_f32;
  } else {
    if ((VAR_TpcMot_tRiseSttrOperationMode_u8 == CAL_Tpc_Powersave2Mode_u8) ||
        (VAR_TpcMot_tRiseSttrOperationMode_u8 == CAL_Tpc_OverheatingMode_u8)) {
      /* Switch: '<S130>/Switch2' */
      VAR_TpcMot_CofDertTRiseSttr_f32 = VAR_TpcMot_CofDertTRiseSttrSave2_f32;
    }
  }

  /* End of Switch: '<S130>/Switch1' */

  /* Switch: '<S129>/Switch' incorporates:
   *  RelationalOperator: '<S129>/Relational Operator'
   */
  if (VAR_TpcMot_CofDertTsttr_f32 <= VAR_TpcMot_CofDertTRiseSttr_f32) {
    rtb_Switch_f4 = VAR_TpcMot_CofDertTsttr_f32;
  } else {
    rtb_Switch_f4 = VAR_TpcMot_CofDertTRiseSttr_f32;
  }

  /* End of Switch: '<S129>/Switch' */

  /* RelationalOperator: '<S133>/Relational Operator' incorporates:
   *  Constant: '<S133>/Coefficient1.0'
   *  Constant: '<S133>/ZeroValue'
   *  Sum: '<S133>/Add'
   */
  VAR_TpcMot_flgTrqLimTsttrActv_b = (1.0F - rtb_Switch_f4 > 1.0E-6F);

  /* Sum: '<S126>/Add' incorporates:
   *  Constant: '<S126>/Constant'
   *  DataTypeConversion: '<S126>/Data Type Conversion'
   */
  VAR_TpcMot_TSttrOvHiWarnState_u8 = (uint8)(VAR_TpcMot_flgTrqLimTsttrActv_b +
    2U);

  /* FunctionCaller: '<S1>/RP_SWC_Dem_TPC_TSttrOvHiWarn_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_TPC_TSttrOvHiWarn_SetEventStatus
    (VAR_TpcMot_TSttrOvHiWarnState_u8);

  /* Sum: '<S126>/Add2' incorporates:
   *  Constant: '<S126>/CAL_TpcMot_tSttrLoLim_f32'
   *  Constant: '<S126>/Constant2'
   *  RelationalOperator: '<S126>/Relational Operator1'
   */
  VAR_TpcMot_TSttrOvLoWarnState_u8 = (uint8)((VAR_TpcMot_tSttrTempFlt_f32 <=
    CAL_TpcMot_tSttrLoLim_f32) + 2U);

  /* FunctionCaller: '<S1>/RP_SWC_Dem_TPC_TSttrOvLoWarn_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_TPC_TSttrOvLoWarn_SetEventStatus
    (VAR_TpcMot_TSttrOvLoWarnState_u8);

  /* SignalConversion generated from: '<S1>/RP_SWC_HSPF_HSPF_iDcLnkEstFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_iDcLnkEstFlt'
   */
  Rte_Read_RP_SWC_HSPF_HSPF_iDcLnkEstFlt(&rtb_TmpSignalConversionAtRP__na);

  /* Sum: '<S146>/Add1' incorporates:
   *  Constant: '<S146>/CAL_TpcSmp_iDcLnkOvCElecLim_f32'
   *  Constant: '<S146>/CAL_TpcSmp_iDcLnkOvCGenLim_f32'
   *  Constant: '<S146>/Constant1'
   *  Logic: '<S146>/Logical Operator1'
   *  RelationalOperator: '<S146>/Relational Operator'
   *  RelationalOperator: '<S146>/Relational Operator1'
   */
  VAR_TpcSmp_iDcLnkOvCLimErrState_u8 = (uint8)(((rtb_TmpSignalConversionAtRP__na
    >= CAL_TpcSmp_iDcLnkOvCElecLim_f32) || (rtb_TmpSignalConversionAtRP__na <=
    CAL_TpcSmp_iDcLnkOvCGenLim_f32)) + 2U);

  /* FunctionCaller: '<S1>/RP_SWC_Dem_TPC_iDcLnkOvCLimFail_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_TPC_iDcLnkOvCLimFail_SetEventStatus
    (VAR_TpcSmp_iDcLnkOvCLimErrState_u8);

  /* SignalConversion generated from: '<S1>/RP_SWC_CSPF_CSPF_RecidcMax_read' incorporates:
   *  Inport: '<Root>/RP_SWC_CSPF_CSPF_RecidcMax'
   */
  Rte_Read_RP_SWC_CSPF_CSPF_RecidcMax(&VAR_TpcSmp_iDcLnkMax_f32);

  /* Switch: '<S188>/Switch2' incorporates:
   *  Constant: '<S143>/CAL_TpcSmp_iDcLnkMaxMax_f32'
   *  Constant: '<S143>/CAL_TpcSmp_iDcLnkMaxMin_f32'
   *  RelationalOperator: '<S188>/LowerRelop1'
   *  RelationalOperator: '<S188>/UpperRelop'
   *  Switch: '<S188>/Switch'
   */
  if (VAR_TpcSmp_iDcLnkMax_f32 > CAL_TpcSmp_iDcLnkMaxMax_f32) {
    VAR_TpcSmp_iDcLnkMax_f32 = CAL_TpcSmp_iDcLnkMaxMax_f32;
  } else {
    if (VAR_TpcSmp_iDcLnkMax_f32 < CAL_TpcSmp_iDcLnkMaxMin_f32) {
      /* Switch: '<S188>/Switch' incorporates:
       *  Constant: '<S143>/CAL_TpcSmp_iDcLnkMaxMin_f32'
       */
      VAR_TpcSmp_iDcLnkMax_f32 = CAL_TpcSmp_iDcLnkMaxMin_f32;
    }
  }

  /* End of Switch: '<S188>/Switch2' */

  /* Switch: '<S150>/Switch' incorporates:
   *  Constant: '<S150>/ZERO'
   *  RelationalOperator: '<S150>/Relational Operator'
   */
  if (rtb_TmpSignalConversionAtRP__na >= 0.0F) {
    rtb_Switch4_d = rtb_TmpSignalConversionAtRP__na;
  } else {
    rtb_Switch4_d = 0.0F;
  }

  /* End of Switch: '<S150>/Switch' */

  /* Lookup_n-D: '<S151>/BusCurrentDertElecTable' incorporates:
   *  Sum: '<S151>/Add1'
   */
  VAR_TpcSmp_cofDertOvrCurtElec_f32 = look1_iflf_binlcapw
    (VAR_TpcSmp_iDcLnkMax_f32 - rtb_Switch4_d, ((const float32 *)
      &(CAL_TpcSmp_OvrCurtLimElecTableX_iDc_af32[0])), ((const float32 *)
      &(CAL_TpcSmp_OvrCurtLimElecTableY_Cof_af32[0])), 4U);

  /* RelationalOperator: '<S151>/Relational Operator' incorporates:
   *  Constant: '<S151>/Coefficient1.0'
   *  Constant: '<S151>/ZeroValue'
   *  Sum: '<S151>/Add'
   */
  VAR_TpcSmp_flgLinearDertOvrCurtElec_b = (1.0F -
    VAR_TpcSmp_cofDertOvrCurtElec_f32 > 1.0E-6F);

  /* UnitDelay: '<S155>/Unit Delay' */
  VAR_tpcsmp_yiDelay_f32 = VAR_tpcsmp_yi_f32;

  /* SignalConversion generated from: '<S1>/RP_SWC_HSPF_HSPF_uDcLnkSlowFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_uDcLnkSlowFlt'
   */
  Rte_Read_RP_SWC_HSPF_HSPF_uDcLnkSlowFlt(&rtb_TmpSignalConversionAtRP_S_f);

  /* Product: '<S152>/Divide' incorporates:
   *  Constant: '<S152>/UnitConversion'
   */
  VAR_TpcSmp_ElecPwrAlowMax_f32 = VAR_TpcSmp_iDcLnkMax_f32 *
    rtb_TmpSignalConversionAtRP_S_f / 1000.0F;

  /* Sum: '<S152>/Add' incorporates:
   *  Constant: '<S152>/UnitConversion1'
   *  Product: '<S152>/Divide1'
   */
  VAR_TpcSmp_ErrElecOvrCurt_f32 = VAR_TpcSmp_ElecPwrAlowMax_f32 -
    rtb_TmpSignalConversionAtRP_S_f * rtb_Switch4_d / 1000.0F;

  /* Product: '<S155>/Product1' incorporates:
   *  Constant: '<S152>/CAL_TpcSmp_ElecOvrCurtKi_f32'
   */
  VAR_tpcsmp_KiProduct_f32 = VAR_TpcSmp_ErrElecOvrCurt_f32 *
    CAL_TpcSmp_ElecOvrCurtKi_f32;

  /* Sum: '<S155>/Add6' */
  VAR_tpcsmp_KiProductSum_f32 = VAR_tpcsmp_yiDelay_f32 +
    VAR_tpcsmp_KiProduct_f32;

  /* Product: '<S155>/Product' incorporates:
   *  Constant: '<S152>/CAL_TpcSmp_ElecOvrCurtKp_f32'
   */
  VAR_tpcsmp_KpProduct_f32 = VAR_TpcSmp_ErrElecOvrCurt_f32 *
    CAL_TpcSmp_ElecOvrCurtKp_f32;

  /* Switch: '<S156>/Switch2' incorporates:
   *  Constant: '<S152>/CAL_TpcSmp_ElecOvrCurtypLim_f32'
   *  Gain: '<S155>/Gain4'
   *  RelationalOperator: '<S156>/LowerRelop1'
   *  RelationalOperator: '<S156>/UpperRelop'
   *  Switch: '<S156>/Switch'
   */
  if (VAR_tpcsmp_KpProduct_f32 > CAL_TpcSmp_ElecOvrCurtypLim_f32) {
    VAR_tpcsmp_KpProductSau_f32 = CAL_TpcSmp_ElecOvrCurtypLim_f32;
  } else if (VAR_tpcsmp_KpProduct_f32 < -CAL_TpcSmp_ElecOvrCurtypLim_f32) {
    /* Switch: '<S156>/Switch' incorporates:
     *  Gain: '<S155>/Gain4'
     */
    VAR_tpcsmp_KpProductSau_f32 = -CAL_TpcSmp_ElecOvrCurtypLim_f32;
  } else {
    VAR_tpcsmp_KpProductSau_f32 = VAR_tpcsmp_KpProduct_f32;
  }

  /* End of Switch: '<S156>/Switch2' */

  /* Sum: '<S155>/Add3' */
  VAR_tpcsmp_PIOutput_f32 = VAR_tpcsmp_KiProductSum_f32 +
    VAR_tpcsmp_KpProductSau_f32;

  /* Switch: '<S152>/Switch1' incorporates:
   *  Constant: '<S152>/CAL_TpcSmp_flgUsePwrLoss_b'
   *  Constant: '<S152>/Constant1'
   *  Lookup_n-D: '<S152>/2-D Lookup Table'
   */
  if (CAL_TpcSmp_flgUsePwrLoss_b) {
    VAR_tpcsmp_PwrLoss_f32 = look2_iflf_binlcapw(VAR_TpcSmp_ElecPwrAlowMax_f32,
      rtb_Product_g, rtCP_uDLookupTable_bp01Data, rtCP_uDLookupTable_bp02Data,
      rtCP_uDLookupTable_tableData, rtCP_uDLookupTable_maxIndex, 33U);
  } else {
    VAR_tpcsmp_PwrLoss_f32 = 0.0F;
  }

  /* End of Switch: '<S152>/Switch1' */

  /* Product: '<S152>/Divide2' incorporates:
   *  Constant: '<S152>/CAL_TpcSmp_TrqAddMax_f32'
   *  Constant: '<S152>/Constant'
   */
  rtb_Add = rtb_Product_g * CAL_TpcSmp_TrqAddMax_f32 / 9550.0F;

  /* Switch: '<S152>/Switch' incorporates:
   *  Constant: '<S152>/CAL_TpcSmp_PwrAddMax_f32'
   *  RelationalOperator: '<S152>/Relational Operator'
   */
  if (rtb_Add < CAL_TpcSmp_PwrAddMax_f32) {
    VAR_tpcsmp_AddPwrElecOvrCurt_f32 = rtb_Add;
  } else {
    VAR_tpcsmp_AddPwrElecOvrCurt_f32 = CAL_TpcSmp_PwrAddMax_f32;
  }

  /* End of Switch: '<S152>/Switch' */

  /* Sum: '<S152>/Add1' */
  VAR_tpcsmp_RefPwrElecOvrCurt_f32 = (VAR_TpcSmp_ElecPwrAlowMax_f32 -
    VAR_tpcsmp_PwrLoss_f32) + VAR_tpcsmp_AddPwrElecOvrCurt_f32;

  /* Switch: '<S157>/Switch2' incorporates:
   *  Constant: '<S155>/yMax'
   *  Gain: '<S155>/Gain5'
   *  RelationalOperator: '<S157>/LowerRelop1'
   *  RelationalOperator: '<S157>/UpperRelop'
   *  Switch: '<S157>/Switch'
   */
  if (VAR_tpcsmp_PIOutput_f32 > 0.0F) {
    rtb_Add = 0.0F;
  } else if (VAR_tpcsmp_PIOutput_f32 < -VAR_tpcsmp_RefPwrElecOvrCurt_f32) {
    /* Switch: '<S157>/Switch' incorporates:
     *  Gain: '<S155>/Gain5'
     */
    rtb_Add = -VAR_tpcsmp_RefPwrElecOvrCurt_f32;
  } else {
    rtb_Add = VAR_tpcsmp_PIOutput_f32;
  }

  /* End of Switch: '<S157>/Switch2' */

  /* Sum: '<S155>/Add7' */
  VAR_TpcSmp_ElecPwrPIDertOvrCurt_f32 = rtb_Add +
    VAR_tpcsmp_RefPwrElecOvrCurt_f32;

  /* RelationalOperator: '<S155>/Relational Operator5' */
  VAR_TpcSmp_flgPIDertOvrCurtElec_b = (VAR_TpcSmp_ElecPwrPIDertOvrCurt_f32 !=
    VAR_tpcsmp_RefPwrElecOvrCurt_f32);

  /* Switch: '<S154>/Switch1' incorporates:
   *  Constant: '<S154>/Zero'
   *  Logic: '<S149>/Logical Operator'
   *  UnitDelay: '<S154>/Unit Delay'
   */
  if (VAR_TpcSmp_flgLinearDertOvrCurtElec_b || VAR_TpcSmp_flgPIDertOvrCurtElec_b)
  {
    /* Sum: '<S154>/Add' incorporates:
     *  UnitDelay: '<S154>/Unit Delay'
     *  UnitDelay: '<S154>/Unit Delay1'
     */
    SWC_TPC_DW.UnitDelay_DSTATE_k = (uint16)((uint32)
      !VAR_TpcSmp_flgElecPwrLimOvrCurtActv_b + SWC_TPC_DW.UnitDelay_DSTATE_k);

    /* Switch: '<S154>/Switch' incorporates:
     *  Constant: '<S154>/MaxValue'
     *  RelationalOperator: '<S154>/Relational Operator'
     *  UnitDelay: '<S154>/Unit Delay'
     */
    if (SWC_TPC_DW.UnitDelay_DSTATE_k >= 65535) {
      SWC_TPC_DW.UnitDelay_DSTATE_k = MAX_uint16_T;
    }

    /* End of Switch: '<S154>/Switch' */
  } else {
    SWC_TPC_DW.UnitDelay_DSTATE_k = 0U;
  }

  /* End of Switch: '<S154>/Switch1' */

  /* RelationalOperator: '<S154>/Relational Operator1' incorporates:
   *  Constant: '<S149>/CAL_TpcSmp_CntElecOvrCurt_u8'
   *  Constant: '<S149>/CAL_TpcSmp_FacElecOvrCurt_u8'
   *  Product: '<S154>/Product'
   *  UnitDelay: '<S154>/Unit Delay'
   */
  VAR_TpcSmp_flgElecPwrLimOvrCurtActv_b = ((uint32)SWC_TPC_DW.UnitDelay_DSTATE_k
    * CAL_TpcSmp_FacElecOvrCurt_u8 > CAL_TpcSmp_CntElecOvrCurt_u8);

  /* Switch: '<S159>/Switch' incorporates:
   *  Constant: '<S159>/ZERO'
   *  RelationalOperator: '<S159>/Relational Operator'
   */
  if (rtb_TmpSignalConversionAtRP__na <= 0.0F) {
    rtb_Add = rtb_TmpSignalConversionAtRP__na;
  } else {
    rtb_Add = 0.0F;
  }

  /* End of Switch: '<S159>/Switch' */

  /* SignalConversion generated from: '<S1>/RP_SWC_CSPF_CSPF_RecidcMin_read' incorporates:
   *  Inport: '<Root>/RP_SWC_CSPF_CSPF_RecidcMin'
   */
  Rte_Read_RP_SWC_CSPF_CSPF_RecidcMin(&VAR_TpcSmp_iDcLnkMin_f32);

  /* Switch: '<S189>/Switch2' incorporates:
   *  Constant: '<S143>/CAL_TpcSmp_iDcLnkMinMax_f32'
   *  Constant: '<S143>/CAL_TpcSmp_iDcLnkMinMin_f32'
   *  RelationalOperator: '<S189>/LowerRelop1'
   *  RelationalOperator: '<S189>/UpperRelop'
   *  Switch: '<S189>/Switch'
   */
  if (VAR_TpcSmp_iDcLnkMin_f32 > CAL_TpcSmp_iDcLnkMinMax_f32) {
    VAR_TpcSmp_iDcLnkMin_f32 = CAL_TpcSmp_iDcLnkMinMax_f32;
  } else {
    if (VAR_TpcSmp_iDcLnkMin_f32 < CAL_TpcSmp_iDcLnkMinMin_f32) {
      /* Switch: '<S189>/Switch' incorporates:
       *  Constant: '<S143>/CAL_TpcSmp_iDcLnkMinMin_f32'
       */
      VAR_TpcSmp_iDcLnkMin_f32 = CAL_TpcSmp_iDcLnkMinMin_f32;
    }
  }

  /* End of Switch: '<S189>/Switch2' */

  /* Lookup_n-D: '<S160>/BusCurrentDertGenTable' incorporates:
   *  Abs: '<S160>/Abs'
   *  Abs: '<S160>/Abs1'
   *  Sum: '<S160>/Add1'
   */
  VAR_TpcSmp_cofDertOvrCurtGen_f32 = look1_iflf_binlcapw(fabsf
    (VAR_TpcSmp_iDcLnkMin_f32) - fabsf(rtb_Add), ((const float32 *)
    &(CAL_TpcSmp_OvrCurtLimGenTableX_iDc_af32[0])), ((const float32 *)
    &(CAL_TpcSmp_OvrCurtLimGenTableY_Cof_af32[0])), 4U);

  /* RelationalOperator: '<S160>/Relational Operator' incorporates:
   *  Constant: '<S160>/Coefficient1.0'
   *  Constant: '<S160>/ZeroValue'
   *  Sum: '<S160>/Add'
   */
  VAR_TpcSmp_flgLinearDertOveCurtGen_b = (1.0F -
    VAR_TpcSmp_cofDertOvrCurtGen_f32 > 1.0E-6F);

  /* Product: '<S161>/Divide' incorporates:
   *  Constant: '<S161>/UnitConversion'
   *  Product: '<S162>/Divide'
   */
  rtb_Divide_b_tmp = VAR_TpcSmp_iDcLnkMin_f32 * rtb_TmpSignalConversionAtRP_S_f /
    1000.0F;

  /* Abs: '<S161>/Abs' incorporates:
   *  Product: '<S161>/Divide'
   */
  VAR_TpcSmp_GenPwrAlowMax_f32 = fabsf(rtb_Divide_b_tmp);

  /* Product: '<S161>/Divide1' incorporates:
   *  Constant: '<S161>/UnitConversion1'
   */
  rtb_Add = rtb_TmpSignalConversionAtRP_S_f * rtb_Add / 1000.0F;

  /* Abs: '<S161>/Abs1' */
  rtb_Add = fabsf(rtb_Add);

  /* Sum: '<S161>/Add' */
  VAR_TpcSmp_ErrGenOvrCurt_f32 = VAR_TpcSmp_GenPwrAlowMax_f32 - rtb_Add;

  /* Sum: '<S164>/Add6' incorporates:
   *  Constant: '<S161>/CAL_TpcSmp_GenOvrCurtKi_f32'
   *  Product: '<S164>/Product1'
   *  UnitDelay: '<S164>/Unit Delay1'
   */
  SWC_TPC_DW.UnitDelay1_DSTATE_b += VAR_TpcSmp_ErrGenOvrCurt_f32 *
    CAL_TpcSmp_GenOvrCurtKi_f32;

  /* Product: '<S164>/Product' incorporates:
   *  Constant: '<S161>/CAL_TpcSmp_GenOvrCurtKp_f32'
   */
  rtb_TmpSignalConversionAtRP__na = VAR_TpcSmp_ErrGenOvrCurt_f32 *
    CAL_TpcSmp_GenOvrCurtKp_f32;

  /* Switch: '<S165>/Switch2' incorporates:
   *  Constant: '<S161>/CAL_TpcSmp_GenOvrCurtypLim_f32'
   *  Gain: '<S164>/Gain6'
   *  RelationalOperator: '<S165>/LowerRelop1'
   *  RelationalOperator: '<S165>/UpperRelop'
   *  Switch: '<S165>/Switch'
   */
  if (rtb_TmpSignalConversionAtRP__na > CAL_TpcSmp_GenOvrCurtypLim_f32) {
    rtb_TmpSignalConversionAtRP__na = CAL_TpcSmp_GenOvrCurtypLim_f32;
  } else {
    if (rtb_TmpSignalConversionAtRP__na < -CAL_TpcSmp_GenOvrCurtypLim_f32) {
      /* Switch: '<S165>/Switch' incorporates:
       *  Gain: '<S164>/Gain6'
       */
      rtb_TmpSignalConversionAtRP__na = -CAL_TpcSmp_GenOvrCurtypLim_f32;
    }
  }

  /* End of Switch: '<S165>/Switch2' */

  /* Sum: '<S164>/Add3' */
  rtb_TmpSignalConversionAtRP__k0 = SWC_TPC_DW.UnitDelay1_DSTATE_b +
    rtb_TmpSignalConversionAtRP__na;

  /* Switch: '<S161>/Switch1' incorporates:
   *  Constant: '<S161>/CAL_TpcSmp_flgUsePwrLossGen_b'
   *  Constant: '<S161>/Constant1'
   *  Lookup_n-D: '<S161>/2-D Lookup Table'
   *  Product: '<S161>/Divide'
   */
  if (CAL_TpcSmp_flgUsePwrLossGen_b) {
    VAR_tpcsmp_PwrLossGen_f32 = look2_iflf_binlcapw(rtb_Divide_b_tmp,
      rtb_Product_g, rtCP_uDLookupTable_bp01Data_b,
      rtCP_uDLookupTable_bp02Data_b, rtCP_uDLookupTable_tableData_d,
      rtCP_uDLookupTable_maxIndex_c, 33U);
  } else {
    VAR_tpcsmp_PwrLossGen_f32 = 0.0F;
  }

  /* End of Switch: '<S161>/Switch1' */

  /* Product: '<S161>/Divide2' incorporates:
   *  Constant: '<S161>/CAL_TpcSmp_TrqAddMaxGen_f32'
   *  Constant: '<S161>/Constant'
   */
  VAR_tpcsmp_negOutputjudge_f32 = (float32)(rtb_Product_g *
    CAL_TpcSmp_TrqAddMaxGen_f32 / 9550.0);

  /* Switch: '<S161>/Switch' incorporates:
   *  Constant: '<S161>/CAL_TpcSmp_PwrAddMaxGen_f32'
   *  RelationalOperator: '<S161>/Relational Operator'
   */
  if (VAR_tpcsmp_negOutputjudge_f32 >= CAL_TpcSmp_PwrAddMaxGen_f32) {
    VAR_tpcsmp_negOutputjudge_f32 = CAL_TpcSmp_PwrAddMaxGen_f32;
  }

  /* End of Switch: '<S161>/Switch' */

  /* Sum: '<S161>/Add1' */
  VAR_tpcsmp_RefPwrGenOvrCurt_f32 = (VAR_TpcSmp_GenPwrAlowMax_f32 +
    VAR_tpcsmp_PwrLossGen_f32) + VAR_tpcsmp_negOutputjudge_f32;

  /* Switch: '<S166>/Switch2' incorporates:
   *  Constant: '<S164>/yMax'
   *  Gain: '<S164>/Gain7'
   *  RelationalOperator: '<S166>/LowerRelop1'
   *  RelationalOperator: '<S166>/UpperRelop'
   *  Switch: '<S166>/Switch'
   */
  if (rtb_TmpSignalConversionAtRP__k0 > 0.0F) {
    rtb_Add = 0.0F;
  } else if (rtb_TmpSignalConversionAtRP__k0 < -VAR_tpcsmp_RefPwrGenOvrCurt_f32)
  {
    /* Switch: '<S166>/Switch' incorporates:
     *  Gain: '<S164>/Gain7'
     */
    rtb_Add = -VAR_tpcsmp_RefPwrGenOvrCurt_f32;
  } else {
    rtb_Add = rtb_TmpSignalConversionAtRP__k0;
  }

  /* End of Switch: '<S166>/Switch2' */

  /* Sum: '<S164>/Add7' */
  VAR_tpcsmp_negOutputjudge_f32 = rtb_Add + VAR_tpcsmp_RefPwrGenOvrCurt_f32;

  /* RelationalOperator: '<S164>/Relational Operator5' */
  VAR_TpcSmp_flgPIDertOvrCurtGen_b = (VAR_tpcsmp_negOutputjudge_f32 !=
    VAR_tpcsmp_RefPwrGenOvrCurt_f32);

  /* Switch: '<S163>/Switch1' incorporates:
   *  Constant: '<S163>/Zero'
   *  Logic: '<S158>/Logical Operator'
   *  UnitDelay: '<S163>/Unit Delay'
   */
  if (VAR_TpcSmp_flgLinearDertOveCurtGen_b || VAR_TpcSmp_flgPIDertOvrCurtGen_b)
  {
    /* Sum: '<S163>/Add' incorporates:
     *  UnitDelay: '<S163>/Unit Delay'
     *  UnitDelay: '<S163>/Unit Delay1'
     */
    SWC_TPC_DW.UnitDelay_DSTATE_gd = (uint16)((uint32)
      !VAR_TpcSmp_flgGenPwrLimCurtActv_b + SWC_TPC_DW.UnitDelay_DSTATE_gd);

    /* Switch: '<S163>/Switch' incorporates:
     *  Constant: '<S163>/MaxValue'
     *  RelationalOperator: '<S163>/Relational Operator'
     *  UnitDelay: '<S163>/Unit Delay'
     */
    if (SWC_TPC_DW.UnitDelay_DSTATE_gd >= 65535) {
      SWC_TPC_DW.UnitDelay_DSTATE_gd = MAX_uint16_T;
    }

    /* End of Switch: '<S163>/Switch' */
  } else {
    SWC_TPC_DW.UnitDelay_DSTATE_gd = 0U;
  }

  /* End of Switch: '<S163>/Switch1' */

  /* RelationalOperator: '<S163>/Relational Operator1' incorporates:
   *  Constant: '<S158>/CAL_TpcSmp_CntGenOvrCurt_u8'
   *  Constant: '<S158>/CAL_TpcSmp_FacGenOvrCurt_u8'
   *  Product: '<S163>/Product'
   *  UnitDelay: '<S163>/Unit Delay'
   */
  VAR_TpcSmp_flgGenPwrLimCurtActv_b = ((uint32)SWC_TPC_DW.UnitDelay_DSTATE_gd *
    CAL_TpcSmp_FacGenOvrCurt_u8 > CAL_TpcSmp_CntGenOvrCurt_u8);

  /* Sum: '<S146>/Add' incorporates:
   *  Constant: '<S146>/Constant'
   *  Logic: '<S146>/Logical Operator'
   */
  VAR_TpcSmp_iDcLnkOvcWarnState_u8 = (uint8)
    ((VAR_TpcSmp_flgElecPwrLimOvrCurtActv_b || VAR_TpcSmp_flgGenPwrLimCurtActv_b)
     + 2U);

  /* FunctionCaller: '<S1>/RP_SWC_Dem_TPC_iDcLnkOvcWarn_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_TPC_iDcLnkOvcWarn_SetEventStatus
    (VAR_TpcSmp_iDcLnkOvcWarnState_u8);

  /* RelationalOperator: '<S170>/Relational Operator' incorporates:
   *  Constant: '<S170>/CAL_TpcSmp_uDcLnkOvVLim_f32'
   */
  rtb_FIM_PwrLimLvFour = (rtb_TmpSignalConversionAtRP_S_f >=
    CAL_TpcSmp_uDcLnkOvVLim_f32);

  /* Sum: '<S170>/Add1' incorporates:
   *  Constant: '<S170>/Constant1'
   *  DataTypeConversion: '<S170>/Data Type Conversion1'
   */
  VAR_TpcSmp_uDcLnkOvVLimErrState_u8 = (uint8)(rtb_FIM_PwrLimLvFour + 2U);

  /* FunctionCaller: '<S1>/RP_SWC_Dem_TPC_uDcLnkOvVLimFail_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_TPC_uDcLnkOvVLimFail_SetEventStatus
    (VAR_TpcSmp_uDcLnkOvVLimErrState_u8);

  /* SignalConversion generated from: '<S1>/RP_SWC_CSPF_CSPF_RecUdcMax_read' incorporates:
   *  Inport: '<Root>/RP_SWC_CSPF_CSPF_RecUdcMax'
   */
  Rte_Read_RP_SWC_CSPF_CSPF_RecUdcMax(&VAR_TpcSmp_uDcLnkMax_f32);

  /* Switch: '<S190>/Switch2' incorporates:
   *  Constant: '<S143>/CAL_TpcSmp_uDcLnkMaxMax_f32'
   *  Constant: '<S143>/CAL_TpcSmp_uDcLnkMaxMin_f32'
   *  RelationalOperator: '<S190>/LowerRelop1'
   *  RelationalOperator: '<S190>/UpperRelop'
   *  Switch: '<S190>/Switch'
   */
  if (VAR_TpcSmp_uDcLnkMax_f32 > CAL_TpcSmp_uDcLnkMaxMax_f32) {
    VAR_TpcSmp_uDcLnkMax_f32 = CAL_TpcSmp_uDcLnkMaxMax_f32;
  } else {
    if (VAR_TpcSmp_uDcLnkMax_f32 < CAL_TpcSmp_uDcLnkMaxMin_f32) {
      /* Switch: '<S190>/Switch' incorporates:
       *  Constant: '<S143>/CAL_TpcSmp_uDcLnkMaxMin_f32'
       */
      VAR_TpcSmp_uDcLnkMax_f32 = CAL_TpcSmp_uDcLnkMaxMin_f32;
    }
  }

  /* End of Switch: '<S190>/Switch2' */

  /* Sum: '<S171>/Add1' incorporates:
   *  Sum: '<S172>/Add'
   */
  rtb_Product1_o = VAR_TpcSmp_uDcLnkMax_f32 - rtb_TmpSignalConversionAtRP_S_f;

  /* Lookup_n-D: '<S171>/BusVoltageDertGenTable' incorporates:
   *  Sum: '<S171>/Add1'
   */
  VAR_TpcSmp_cofDertOvrVoltGen_f32 = look1_iflf_binlcapw(rtb_Product1_o, ((const
    float32 *)&(CAL_TpcSmp_OvrVoltGenTableX_uDc_af32[0])), ((const float32 *)
    &(CAL_TpcSmp_OvrVoltGenTableY_Cof_af32[0])), 4U);

  /* RelationalOperator: '<S171>/Relational Operator' incorporates:
   *  Constant: '<S171>/Coefficient1.0'
   *  Constant: '<S171>/ZeroValue'
   *  Sum: '<S171>/Add'
   */
  VAR_TpcSmp_flgLinearDertOvrVoltGen_b = (1.0F -
    VAR_TpcSmp_cofDertOvrVoltGen_f32 > 1.0E-6F);

  /* DataTypeConversion: '<S116>/Data Type Conversion' incorporates:
   *  Constant: '<S116>/CAL_Tpcmot_CofuDclnk_u8'
   *  Product: '<S116>/Divide'
   */
  rtb_Add = fmodf(roundf(rtb_TmpSignalConversionAtRP_S_f / (float32)
    CAL_Tpcmot_CofuDclnk_u8), 65536.0F);

  /* DataTypeConversion: '<S116>/Data Type Conversion1' incorporates:
   *  Constant: '<S116>/CAL_Tpcmot_CofuDclnk_u8'
   *  DataTypeConversion: '<S116>/Data Type Conversion'
   *  Product: '<S116>/Divide1'
   *  Product: '<S116>/Divide2'
   *  Sum: '<S116>/Add2'
   */
  rtb_DataTypeConversion1 = (float32)((uint32)(rtb_Add < 0.0F ? (sint32)(uint16)
    -(sint16)(uint16)-rtb_Add : (sint32)(uint16)rtb_Add) *
    CAL_Tpcmot_CofuDclnk_u8 + ((uint32)CAL_Tpcmot_CofuDclnk_u8 >> 1));

  /* Gain: '<S116>/Negate' incorporates:
   *  Lookup_n-D: '<S116>/GenExCTable'
   */
  VAR_TpcMot_TrqGenExCOrg_f32 = -look2_iflf_binlcapw(rtb_Product_g,
    rtb_DataTypeConversion1, ((const float32 *)
    &(CAL_TpcMot_ExCGenTableY_Spd_af32[0])), ((const float32 *)
    &(CAL_TpcMot_ExCGenTableX_Udc_af32[0])), ((const float32 *)
    &(CAL_TpcMot_ExCGenTableZ_Trq_af32[0])), rtCP_GenExCTable_maxIndex, 17U);

  /* Switch: '<S125>/Switch' incorporates:
   *  Logic: '<S121>/Logical Operator'
   *  UnitDelay: '<S121>/Unit Delay'
   *  UnitDelay: '<S125>/Unit Delay2'
   */
  if (!SWC_TPC_DW.UnitDelay_DSTATE_l) {
    SWC_TPC_DW.UnitDelay2_DSTATE_l = VAR_TpcMot_TrqGenExCOrg_f32;
  } else {
    /* Sum: '<S125>/Subtract' incorporates:
     *  UnitDelay: '<S125>/Unit Delay2'
     */
    rtb_Subtract_gc = VAR_TpcMot_TrqGenExCOrg_f32 -
      SWC_TPC_DW.UnitDelay2_DSTATE_l;

    /* Switch: '<S125>/Switch2' incorporates:
     *  Constant: '<S125>/CAL_Tpc_TrqRiseRevStep_f32'
     *  RelationalOperator: '<S125>/Relational Operator'
     */
    if (rtb_Subtract_gc <= CAL_Tpc_TrqRiseRevStep_f32) {
      /* Switch: '<S125>/Switch3' incorporates:
       *  Constant: '<S125>/CAL_Tpc_TrqReduceRevStep_f32'
       *  Product: '<S125>/Product'
       *  RelationalOperator: '<S125>/Relational Operator1'
       */
      if (-rtb_Subtract_gc <= CAL_Tpc_TrqReduceRevStep_f32) {
        /* UnitDelay: '<S125>/Unit Delay2' */
        SWC_TPC_DW.UnitDelay2_DSTATE_l = VAR_TpcMot_TrqGenExCOrg_f32;
      } else {
        /* UnitDelay: '<S125>/Unit Delay2' incorporates:
         *  Sum: '<S125>/Add2'
         */
        SWC_TPC_DW.UnitDelay2_DSTATE_l -= CAL_Tpc_TrqReduceRevStep_f32;
      }

      /* End of Switch: '<S125>/Switch3' */
    } else {
      /* UnitDelay: '<S125>/Unit Delay2' incorporates:
       *  Sum: '<S125>/Add1'
       */
      SWC_TPC_DW.UnitDelay2_DSTATE_l += CAL_Tpc_TrqRiseRevStep_f32;
    }

    /* End of Switch: '<S125>/Switch2' */
  }

  /* End of Switch: '<S125>/Switch' */

  /* Lookup_n-D: '<S116>/ElecExCTable' incorporates:
   *  Constant: '<S116>/CAL_Tpcmot_CofuDclnk_u8'
   *  DataTypeConversion: '<S116>/Data Type Conversion'
   *  DataTypeConversion: '<S116>/Data Type Conversion1'
   *  Product: '<S116>/Divide1'
   *  Product: '<S116>/Divide2'
   *  Sum: '<S116>/Add2'
   */
  VAR_TpcMot_TrqElecExCOrg_f32 = look2_iflf_binlcapw(rtb_Product_g, (float32)
    ((uint32)(rtb_Add < 0.0F ? (sint32)(uint16)-(sint16)(uint16)-rtb_Add :
              (sint32)(uint16)rtb_Add) * CAL_Tpcmot_CofuDclnk_u8 + ((uint32)
    CAL_Tpcmot_CofuDclnk_u8 >> 1)), ((const float32 *)
    &(CAL_TpcMot_ExCElecTableY_Spd_af32[0])), ((const float32 *)
    &(CAL_TpcMot_ExCElecTableX_Udc_af32[0])), ((const float32 *)
    &(CAL_TpcMot_ExCElecTableZ_Trq_af32[0])), rtCP_ElecExCTable_maxIndex, 17U);

  /* SignalConversion generated from: '<S1>/RP_SWC_VCF_VCF_TrqDes_read' incorporates:
   *  Inport: '<Root>/RP_SWC_VCF_VCF_TrqDes'
   */
  Rte_Read_RP_SWC_VCF_VCF_TrqDes(&rtb_TmpSignalConversionAtRP_S_n);

  /* Switch: '<S116>/Switch2' incorporates:
   *  Constant: '<S116>/CAL_Tpcmot_TrqDiffExc_f32'
   *  Constant: '<S116>/CAL_Tpcmot_TrqDiffGen_f32'
   *  Constant: '<S116>/CAL_Tpcmot_flgOpenExcLimRamp_b'
   *  Constant: '<S116>/CAL_Tpcmot_uDcHiset_f32'
   *  Constant: '<S116>/CAL_Tpcmot_uDcLoset_f32'
   *  Constant: '<S116>/Constant'
   *  Logic: '<S116>/Logical Operator'
   *  Logic: '<S116>/Logical Operator1'
   *  Logic: '<S116>/Logical Operator2'
   *  RelationalOperator: '<S116>/Relational Operator'
   *  RelationalOperator: '<S116>/Relational Operator1'
   *  RelationalOperator: '<S116>/Relational Operator2'
   *  RelationalOperator: '<S116>/Relational Operator3'
   *  Sum: '<S116>/Add'
   *  Sum: '<S116>/Add1'
   */
  if (CAL_Tpcmot_flgOpenExcLimRamp_b) {
    VAR_TpcMot_flgStartExcLimRamp_b = (((rtb_DataTypeConversion1 <=
      CAL_Tpcmot_uDcLoset_f32) || (rtb_DataTypeConversion1 >=
      CAL_Tpcmot_uDcHiset_f32)) && ((VAR_TpcMot_TrqElecExCOrg_f32 -
      rtb_TmpSignalConversionAtRP_S_n <= CAL_Tpcmot_TrqDiffExc_f32) ||
      (rtb_TmpSignalConversionAtRP_S_n - VAR_TpcMot_TrqGenExCOrg_f32 <=
       CAL_Tpcmot_TrqDiffGen_f32)));
  } else {
    VAR_TpcMot_flgStartExcLimRamp_b = false;
  }

  /* End of Switch: '<S116>/Switch2' */

  /* Switch: '<S116>/Switch1' incorporates:
   *  UnitDelay: '<S125>/Unit Delay2'
   */
  if (VAR_TpcMot_flgStartExcLimRamp_b) {
    VAR_TpcMot_TrqGenExC_f32 = SWC_TPC_DW.UnitDelay2_DSTATE_l;
  } else {
    VAR_TpcMot_TrqGenExC_f32 = VAR_TpcMot_TrqGenExCOrg_f32;
  }

  /* End of Switch: '<S116>/Switch1' */

  /* Switch: '<S117>/Switch1' incorporates:
   *  Constant: '<S117>/CAL_TpcMot_flgPwrRefSwt_b'
   *  Constant: '<S117>/CofPwrCalc'
   *  Constant: '<S117>/GLB_Tpc_MaximumPower_f32'
   *  Gain: '<S117>/Negate'
   *  Product: '<S117>/Divide1'
   */
  if (CAL_TpcMot_flgPwrRefSwt_b) {
    VAR_TpcMot_GenPwrRef_f32 = rtb_Product_g * VAR_TpcMot_TrqGenExC_f32 /
      9550.0F;
  } else {
    VAR_TpcMot_GenPwrRef_f32 = -GLB_Tpc_MaximumPower_f32;
  }

  /* End of Switch: '<S117>/Switch1' */

  /* Sum: '<S174>/Add6' incorporates:
   *  Constant: '<S172>/CAL_TpcSmp_GenOvrVoltKi_f32'
   *  Product: '<S174>/Product'
   *  UnitDelay: '<S174>/Unit Delay2'
   */
  SWC_TPC_DW.UnitDelay2_DSTATE_c += rtb_Product1_o * CAL_TpcSmp_GenOvrVoltKi_f32;

  /* Product: '<S174>/Product1' incorporates:
   *  Constant: '<S172>/CAL_TpcSmp_GenOvrVoltKp_f32'
   */
  rtb_Product1_o *= CAL_TpcSmp_GenOvrVoltKp_f32;

  /* Switch: '<S175>/Switch2' incorporates:
   *  Constant: '<S172>/CAL_TpcSmp_GenOvrVoltypLim_f32'
   *  Gain: '<S174>/Gain7'
   *  RelationalOperator: '<S175>/LowerRelop1'
   *  RelationalOperator: '<S175>/UpperRelop'
   *  Switch: '<S175>/Switch'
   */
  if (rtb_Product1_o > CAL_TpcSmp_GenOvrVoltypLim_f32) {
    rtb_Product1_o = CAL_TpcSmp_GenOvrVoltypLim_f32;
  } else {
    if (rtb_Product1_o < -CAL_TpcSmp_GenOvrVoltypLim_f32) {
      /* Switch: '<S175>/Switch' incorporates:
       *  Gain: '<S174>/Gain7'
       */
      rtb_Product1_o = -CAL_TpcSmp_GenOvrVoltypLim_f32;
    }
  }

  /* End of Switch: '<S175>/Switch2' */

  /* Sum: '<S174>/Add3' */
  rtb_DataTypeConversion1 = SWC_TPC_DW.UnitDelay2_DSTATE_c + rtb_Product1_o;

  /* Switch: '<S176>/Switch2' incorporates:
   *  Constant: '<S174>/Constant4'
   *  Gain: '<S174>/Gain1'
   *  RelationalOperator: '<S176>/LowerRelop1'
   *  RelationalOperator: '<S176>/UpperRelop'
   *  Switch: '<S176>/Switch'
   */
  if (rtb_DataTypeConversion1 > -VAR_TpcMot_GenPwrRef_f32) {
    rtb_Add = -VAR_TpcMot_GenPwrRef_f32;
  } else if (rtb_DataTypeConversion1 < 0.0F) {
    /* Switch: '<S176>/Switch' incorporates:
     *  Constant: '<S174>/Constant4'
     */
    rtb_Add = 0.0F;
  } else {
    rtb_Add = rtb_DataTypeConversion1;
  }

  /* End of Switch: '<S176>/Switch2' */

  /* RelationalOperator: '<S174>/Relational Operator5' incorporates:
   *  Gain: '<S174>/Gain1'
   */
  VAR_TpcSmp_flgPIDertOvrVoltGen_b = (rtb_Add != -VAR_TpcMot_GenPwrRef_f32);

  /* Switch: '<S173>/Switch1' incorporates:
   *  Constant: '<S173>/Zero'
   *  Logic: '<S169>/Logical Operator'
   *  UnitDelay: '<S173>/Unit Delay'
   */
  if (VAR_TpcSmp_flgLinearDertOvrVoltGen_b || VAR_TpcSmp_flgPIDertOvrVoltGen_b)
  {
    /* Sum: '<S173>/Add' incorporates:
     *  UnitDelay: '<S173>/Unit Delay'
     *  UnitDelay: '<S173>/Unit Delay1'
     */
    SWC_TPC_DW.UnitDelay_DSTATE_di = (uint16)((uint32)
      !VAR_TpcSmp_flgGenPwrLimOvrVoltActv_b + SWC_TPC_DW.UnitDelay_DSTATE_di);

    /* Switch: '<S173>/Switch' incorporates:
     *  Constant: '<S173>/MaxValue'
     *  RelationalOperator: '<S173>/Relational Operator'
     *  UnitDelay: '<S173>/Unit Delay'
     */
    if (SWC_TPC_DW.UnitDelay_DSTATE_di >= 65535) {
      SWC_TPC_DW.UnitDelay_DSTATE_di = MAX_uint16_T;
    }

    /* End of Switch: '<S173>/Switch' */
  } else {
    SWC_TPC_DW.UnitDelay_DSTATE_di = 0U;
  }

  /* End of Switch: '<S173>/Switch1' */

  /* RelationalOperator: '<S173>/Relational Operator1' incorporates:
   *  Constant: '<S169>/CAL_TpcSmp_CntGenOvrVolt_u8'
   *  Constant: '<S169>/CAL_TpcSmp_FacGenOvrVolt_u8'
   *  Product: '<S173>/Product'
   *  UnitDelay: '<S173>/Unit Delay'
   */
  VAR_TpcSmp_flgGenPwrLimOvrVoltActv_b = ((uint32)SWC_TPC_DW.UnitDelay_DSTATE_di
    * CAL_TpcSmp_FacGenOvrVolt_u8 > CAL_TpcSmp_CntGenOvrVolt_u8);

  /* Sum: '<S170>/Add' incorporates:
   *  Constant: '<S170>/Constant'
   *  DataTypeConversion: '<S170>/Data Type Conversion'
   */
  VAR_TpcSmp_uDcLnkOvWarnState_u8 = (uint8)(VAR_TpcSmp_flgGenPwrLimOvrVoltActv_b
    + 2U);

  /* FunctionCaller: '<S1>/RP_SWC_Dem_TPC_uDcLnkOvWarn_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_TPC_uDcLnkOvWarn_SetEventStatus
    (VAR_TpcSmp_uDcLnkOvWarnState_u8);

  /* SignalConversion generated from: '<S1>/RP_SWC_SCF_SCF_flgUdcLowToTpc_read' incorporates:
   *  Inport: '<Root>/RP_SWC_SCF_SCF_flgUdcLowToTpc'
   */
  Rte_Read_RP_SWC_SCF_SCF_flgUdcLowToTpc(&rtb_TmpSignalConversionAtRP_S_d);

  /* Switch: '<S178>/Switch' incorporates:
   *  Constant: '<S178>/CAL_TpcSmp_uDcLnkUnVLim_f32'
   *  Logic: '<S178>/Logical Operator'
   *  RelationalOperator: '<S178>/Relational Operator'
   *  UnitDelay: '<S178>/Unit Delay'
   */
  SWC_TPC_DW.UnitDelay_DSTATE_kx = (((rtb_TmpSignalConversionAtRP_S_f <=
    CAL_TpcSmp_uDcLnkUnVLim_f32) && rtb_TmpSignalConversionAtRP_S_d) ||
    SWC_TPC_DW.UnitDelay_DSTATE_kx);

  /* Sum: '<S178>/Add1' incorporates:
   *  Constant: '<S178>/Constant1'
   *  DataTypeConversion: '<S178>/Data Type Conversion1'
   *  UnitDelay: '<S178>/Unit Delay'
   */
  VAR_TpcSmp_uDcLnkUnVLimErrState_u8 = (uint8)(SWC_TPC_DW.UnitDelay_DSTATE_kx +
    2U);

  /* FunctionCaller: '<S1>/RP_SWC_Dem_TPC_uDcLnkUnVLimFail_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_TPC_uDcLnkUnVLimFail_SetEventStatus
    (VAR_TpcSmp_uDcLnkUnVLimErrState_u8);

  /* SignalConversion generated from: '<S1>/RP_SWC_CSPF_CSPF_RecUdcMin_read' incorporates:
   *  Inport: '<Root>/RP_SWC_CSPF_CSPF_RecUdcMin'
   */
  Rte_Read_RP_SWC_CSPF_CSPF_RecUdcMin(&VAR_TpcSmp_uDcLnkMin_f32);

  /* Switch: '<S191>/Switch2' incorporates:
   *  Constant: '<S143>/CAL_TpcSmp_uDcLnkMinMax_f32'
   *  Constant: '<S143>/CAL_TpcSmp_uDcLnkMinMin_f32'
   *  RelationalOperator: '<S191>/LowerRelop1'
   *  RelationalOperator: '<S191>/UpperRelop'
   *  Switch: '<S191>/Switch'
   */
  if (VAR_TpcSmp_uDcLnkMin_f32 > CAL_TpcSmp_uDcLnkMinMax_f32) {
    VAR_TpcSmp_uDcLnkMin_f32 = CAL_TpcSmp_uDcLnkMinMax_f32;
  } else {
    if (VAR_TpcSmp_uDcLnkMin_f32 < CAL_TpcSmp_uDcLnkMinMin_f32) {
      /* Switch: '<S191>/Switch' incorporates:
       *  Constant: '<S143>/CAL_TpcSmp_uDcLnkMinMin_f32'
       */
      VAR_TpcSmp_uDcLnkMin_f32 = CAL_TpcSmp_uDcLnkMinMin_f32;
    }
  }

  /* End of Switch: '<S191>/Switch2' */

  /* Sum: '<S179>/Add1' incorporates:
   *  Sum: '<S180>/Add'
   */
  rtb_Subtract_gc = rtb_TmpSignalConversionAtRP_S_f - VAR_TpcSmp_uDcLnkMin_f32;

  /* Lookup_n-D: '<S179>/BusVoltageDertElecTable' incorporates:
   *  Sum: '<S179>/Add1'
   */
  VAR_TpcSmp_cofDertUdrVoltElec_f32 = look1_iflf_binlcapw(rtb_Subtract_gc, ((
    const float32 *)&(CAL_TpcSmp_UdrVoltElecTableX_uDc_af32[0])), ((const
    float32 *)&(CAL_TpcSmp_UdrVoltElecTableY_Cof_af32[0])), 4U);

  /* RelationalOperator: '<S179>/Relational Operator' incorporates:
   *  Constant: '<S179>/Coefficient1.0'
   *  Constant: '<S179>/ZeroValue'
   *  Sum: '<S179>/Add'
   */
  VAR_TpcSmp_flgLinearDertUdrVoltElec_b = (1.0F -
    VAR_TpcSmp_cofDertUdrVoltElec_f32 > 1.0E-6F);

  /* Switch: '<S124>/Switch' incorporates:
   *  Logic: '<S120>/Logical Operator'
   *  UnitDelay: '<S120>/Unit Delay'
   *  UnitDelay: '<S124>/Unit Delay2'
   */
  if (!SWC_TPC_DW.UnitDelay_DSTATE_de) {
    SWC_TPC_DW.UnitDelay2_DSTATE_d = VAR_TpcMot_TrqElecExCOrg_f32;
  } else {
    /* Sum: '<S124>/Subtract' incorporates:
     *  UnitDelay: '<S124>/Unit Delay2'
     */
    rtb_Subtract_kw = VAR_TpcMot_TrqElecExCOrg_f32 -
      SWC_TPC_DW.UnitDelay2_DSTATE_d;

    /* Switch: '<S124>/Switch2' incorporates:
     *  Constant: '<S124>/CAL_Tpc_TrqRiseRevStep_f32'
     *  RelationalOperator: '<S124>/Relational Operator'
     */
    if (rtb_Subtract_kw <= CAL_Tpc_TrqRiseRevStep_f32) {
      /* Switch: '<S124>/Switch3' incorporates:
       *  Constant: '<S124>/CAL_Tpc_TrqReduceRevStep_f32'
       *  Product: '<S124>/Product'
       *  RelationalOperator: '<S124>/Relational Operator1'
       */
      if (-rtb_Subtract_kw <= CAL_Tpc_TrqReduceRevStep_f32) {
        /* UnitDelay: '<S124>/Unit Delay2' */
        SWC_TPC_DW.UnitDelay2_DSTATE_d = VAR_TpcMot_TrqElecExCOrg_f32;
      } else {
        /* UnitDelay: '<S124>/Unit Delay2' incorporates:
         *  Sum: '<S124>/Add2'
         */
        SWC_TPC_DW.UnitDelay2_DSTATE_d -= CAL_Tpc_TrqReduceRevStep_f32;
      }

      /* End of Switch: '<S124>/Switch3' */
    } else {
      /* UnitDelay: '<S124>/Unit Delay2' incorporates:
       *  Sum: '<S124>/Add1'
       */
      SWC_TPC_DW.UnitDelay2_DSTATE_d += CAL_Tpc_TrqRiseRevStep_f32;
    }

    /* End of Switch: '<S124>/Switch2' */
  }

  /* End of Switch: '<S124>/Switch' */

  /* Switch: '<S116>/Switch' incorporates:
   *  UnitDelay: '<S124>/Unit Delay2'
   */
  if (VAR_TpcMot_flgStartExcLimRamp_b) {
    VAR_TpcMot_TrqElecExC_f32 = SWC_TPC_DW.UnitDelay2_DSTATE_d;
  } else {
    VAR_TpcMot_TrqElecExC_f32 = VAR_TpcMot_TrqElecExCOrg_f32;
  }

  /* End of Switch: '<S116>/Switch' */

  /* Switch: '<S117>/Switch' incorporates:
   *  Constant: '<S117>/CAL_TpcMot_flgPwrRefSwt_b'
   *  Constant: '<S117>/CofPwrCalc'
   *  Constant: '<S117>/GLB_Tpc_MaximumPower_f32'
   *  Product: '<S117>/Divide'
   */
  if (CAL_TpcMot_flgPwrRefSwt_b) {
    VAR_TpcMot_ElecPwrRef_f32 = rtb_Product_g * VAR_TpcMot_TrqElecExC_f32 /
      9550.0F;
  } else {
    VAR_TpcMot_ElecPwrRef_f32 = GLB_Tpc_MaximumPower_f32;
  }

  /* End of Switch: '<S117>/Switch' */

  /* Sum: '<S182>/Add6' incorporates:
   *  Constant: '<S180>/CAL_TpcSmp_ElecUdrVoltKi_f32'
   *  Product: '<S182>/Product'
   *  UnitDelay: '<S182>/Unit Delay2'
   */
  SWC_TPC_DW.UnitDelay2_DSTATE_g += rtb_Subtract_gc *
    CAL_TpcSmp_ElecUdrVoltKi_f32;

  /* Product: '<S182>/Product1' incorporates:
   *  Constant: '<S180>/CAL_TpcSmp_ElecUdrVoltKp_f32'
   */
  rtb_Subtract_gc *= CAL_TpcSmp_ElecUdrVoltKp_f32;

  /* Switch: '<S183>/Switch2' incorporates:
   *  Constant: '<S180>/CAL_TpcSmp_ElecUdrVoltypLim_f32'
   *  Gain: '<S182>/Gain6'
   *  RelationalOperator: '<S183>/LowerRelop1'
   *  RelationalOperator: '<S183>/UpperRelop'
   *  Switch: '<S183>/Switch'
   */
  if (rtb_Subtract_gc > CAL_TpcSmp_ElecUdrVoltypLim_f32) {
    rtb_Subtract_gc = CAL_TpcSmp_ElecUdrVoltypLim_f32;
  } else {
    if (rtb_Subtract_gc < -CAL_TpcSmp_ElecUdrVoltypLim_f32) {
      /* Switch: '<S183>/Switch' incorporates:
       *  Gain: '<S182>/Gain6'
       */
      rtb_Subtract_gc = -CAL_TpcSmp_ElecUdrVoltypLim_f32;
    }
  }

  /* End of Switch: '<S183>/Switch2' */

  /* Sum: '<S182>/Add3' */
  rtb_Subtract_kw = SWC_TPC_DW.UnitDelay2_DSTATE_g + rtb_Subtract_gc;

  /* Switch: '<S184>/Switch2' incorporates:
   *  Constant: '<S182>/Constant4'
   *  RelationalOperator: '<S184>/LowerRelop1'
   *  RelationalOperator: '<S184>/UpperRelop'
   *  Switch: '<S184>/Switch'
   */
  if (rtb_Subtract_kw > VAR_TpcMot_ElecPwrRef_f32) {
    VAR_TpcSmp_ElecPwrPIDertUdrVolt_f32 = VAR_TpcMot_ElecPwrRef_f32;
  } else if (rtb_Subtract_kw < 0.0F) {
    /* Switch: '<S184>/Switch' incorporates:
     *  Constant: '<S182>/Constant4'
     */
    VAR_TpcSmp_ElecPwrPIDertUdrVolt_f32 = 0.0F;
  } else {
    VAR_TpcSmp_ElecPwrPIDertUdrVolt_f32 = rtb_Subtract_kw;
  }

  /* End of Switch: '<S184>/Switch2' */

  /* RelationalOperator: '<S182>/Relational Operator5' */
  VAR_TpcSmp_flgPIDertUdrVoltElec_b = (VAR_TpcSmp_ElecPwrPIDertUdrVolt_f32 !=
    VAR_TpcMot_ElecPwrRef_f32);

  /* Switch: '<S181>/Switch1' incorporates:
   *  Constant: '<S181>/Zero'
   *  Logic: '<S177>/Logical Operator'
   *  UnitDelay: '<S181>/Unit Delay'
   */
  if (VAR_TpcSmp_flgLinearDertUdrVoltElec_b || VAR_TpcSmp_flgPIDertUdrVoltElec_b)
  {
    /* Sum: '<S181>/Add' incorporates:
     *  UnitDelay: '<S181>/Unit Delay'
     *  UnitDelay: '<S181>/Unit Delay1'
     */
    SWC_TPC_DW.UnitDelay_DSTATE_c = (uint16)((uint32)
      !SWC_TPC_DW.UnitDelay1_DSTATE_ew + SWC_TPC_DW.UnitDelay_DSTATE_c);

    /* Switch: '<S181>/Switch' incorporates:
     *  Constant: '<S181>/MaxValue'
     *  RelationalOperator: '<S181>/Relational Operator'
     *  UnitDelay: '<S181>/Unit Delay'
     */
    if (SWC_TPC_DW.UnitDelay_DSTATE_c >= 65535) {
      SWC_TPC_DW.UnitDelay_DSTATE_c = MAX_uint16_T;
    }

    /* End of Switch: '<S181>/Switch' */
  } else {
    SWC_TPC_DW.UnitDelay_DSTATE_c = 0U;
  }

  /* End of Switch: '<S181>/Switch1' */

  /* RelationalOperator: '<S181>/Relational Operator1' incorporates:
   *  Constant: '<S177>/CAL_TpcSmp_CntElecUdrVolt_u8'
   *  Constant: '<S177>/CAL_TpcSmp_FacElecUdrVolt_u8'
   *  Product: '<S181>/Product'
   *  UnitDelay: '<S181>/Unit Delay'
   *  UnitDelay: '<S181>/Unit Delay1'
   */
  SWC_TPC_DW.UnitDelay1_DSTATE_ew = ((uint32)SWC_TPC_DW.UnitDelay_DSTATE_c *
    CAL_TpcSmp_FacElecUdrVolt_u8 > CAL_TpcSmp_CntElecUdrVolt_u8);

  /* Logic: '<S177>/Logical Operator1' incorporates:
   *  UnitDelay: '<S181>/Unit Delay1'
   */
  VAR_TpcSmp_flgElecPwrLimUdrVoltActv_b = (rtb_TmpSignalConversionAtRP_S_d &&
    SWC_TPC_DW.UnitDelay1_DSTATE_ew);

  /* Sum: '<S178>/Add' incorporates:
   *  Constant: '<S178>/Constant'
   *  DataTypeConversion: '<S178>/Data Type Conversion'
   */
  VAR_TpcSmp_uDcLnkUnvWarnState_u8 = (uint8)
    (VAR_TpcSmp_flgElecPwrLimUdrVoltActv_b + 2U);

  /* FunctionCaller: '<S1>/RP_SWC_Dem_TPC_uDcLnkUnvWarn_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_TPC_uDcLnkUnvWarn_SetEventStatus
    (VAR_TpcSmp_uDcLnkUnvWarnState_u8);

  /* FunctionCaller: '<S1>/RP_SWC_FIM_PwrLimLvFour_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_PwrLimLvFour_GetFunctionPermission(&rtb_FIM_PwrLimLvFour);

  /* FunctionCaller: '<S1>/RP_SWC_FIM_PwrLimLvOne_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_PwrLimLvOne_GetFunctionPermission(&rtb_FIM_PwrLimLvOne);

  /* FunctionCaller: '<S1>/RP_SWC_FIM_PwrLimLvThree_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_PwrLimLvThree_GetFunctionPermission(&rtb_FIM_PwrLimLvThree);

  /* FunctionCaller: '<S1>/RP_SWC_FIM_PwrLimLvTwo_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_PwrLimLvTwo_GetFunctionPermission(&rtb_FIM_PwrLimLvTwo);

  /* FunctionCaller: '<S1>/RP_SWC_FIM_TrqLimLvFour_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_TrqLimLvFour_GetFunctionPermission(&rtb_FIM_TrqLimLvFour);

  /* FunctionCaller: '<S1>/RP_SWC_FIM_TrqLimLvOne_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_TrqLimLvOne_GetFunctionPermission
    (&rtb_RelationalOperator4_o);

  /* FunctionCaller: '<S1>/RP_SWC_FIM_TrqLimLvThree_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_TrqLimLvThree_GetFunctionPermission
    (&rtb_RelationalOperator3_kx);

  /* FunctionCaller: '<S1>/RP_SWC_FIM_TrqLimLvTwo_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_TrqLimLvTwo_GetFunctionPermission
    (&rtb_RelationalOperator1_cn);

  /* Lookup_n-D: '<S7>/CoolantFlow2L' */
  rtb_Switch4_d = look2_iflf_binlcapw(rtb_TmpSignalConversionAtRP_SWC,
    rtb_TmpSignalConversionAtRP_S_f, ((const float32 *)
    &(CAL_TpcCod_CoolFlow2LTableY_Spd_af32[0])), ((const float32 *)
    &(CAL_TpcCod_CoolFlow2LTableX_Udc_af32[0])), ((const float32 *)
    &(CAL_TpcCod_CoolFlow2LTableZ_Trq_af32[0])), rtCP_CoolantFlow2L_maxIndex, 8U);

  /* Lookup_n-D: '<S7>/CoolantFlow4L' */
  rtb_CoolantFlow4L = look2_iflf_binlcapw(rtb_TmpSignalConversionAtRP_SWC,
    rtb_TmpSignalConversionAtRP_S_f, ((const float32 *)
    &(CAL_TpcCod_CoolFlow4LTableY_Spd_af32[0])), ((const float32 *)
    &(CAL_TpcCod_CoolFlow4LTableX_Udc_af32[0])), ((const float32 *)
    &(CAL_TpcCod_CoolFlow4LTableZ_Trq_af32[0])), rtCP_CoolantFlow4L_maxIndex, 8U);

  /* Lookup_n-D: '<S7>/CoolantFlow6L' */
  rtb_CoolantFlow6L = look2_iflf_binlcapw(rtb_TmpSignalConversionAtRP_SWC,
    rtb_TmpSignalConversionAtRP_S_f, ((const float32 *)
    &(CAL_TpcCod_CoolFlow6LTableY_Spd_af32[0])), ((const float32 *)
    &(CAL_TpcCod_CoolFlow6LTableX_Udc_af32[0])), ((const float32 *)
    &(CAL_TpcCod_CoolFlow6LTableZ_Trq_af32[0])), rtCP_CoolantFlow6L_maxIndex, 8U);

  /* Logic: '<S7>/Logical Operator' incorporates:
   *  Constant: '<S7>/CAL_TpcCod_IGBTSampErr_b'
   *  Constant: '<S7>/CAL_TpcCod_MotorSampErr_b'
   *  Constant: '<S7>/CAL_TpcCod_MotorStallWarn_b'
   */
  rtb_LogicalOperator_g = (CAL_TpcCod_MotorStallWarn_b ||
    CAL_TpcCod_MotorSampErr_b || CAL_TpcCod_IGBTSampErr_b);

  /* Sum: '<S15>/Add' incorporates:
   *  UnitDelay: '<S15>/Unit Delay'
   */
  VAR_TpcCod_PowerAdd_f32 = rtb_TmpSignalConversionAtRP_S_n -
    SWC_TPC_DW.UnitDelay_DSTATE_eh;

  /* Product: '<S15>/Divide1' incorporates:
   *  Constant: '<S15>/Constant1'
   *  Delay: '<S15>/Delay1'
   *  Delay: '<S15>/Delay10'
   *  Delay: '<S15>/Delay2'
   *  Delay: '<S15>/Delay3'
   *  Delay: '<S15>/Delay4'
   *  Delay: '<S15>/Delay5'
   *  Delay: '<S15>/Delay6'
   *  Delay: '<S15>/Delay7'
   *  Delay: '<S15>/Delay9'
   *  Sum: '<S15>/Add7'
   */
  VAR_TpcCod_PowerIncreaseRate_f32 = (((((((((VAR_TpcCod_PowerAdd_f32 +
    SWC_TPC_DW.Delay1_DSTATE) + SWC_TPC_DW.Delay10_DSTATE[0]) +
    SWC_TPC_DW.Delay9_DSTATE[0]) + SWC_TPC_DW.Delay7_DSTATE[0]) +
    SWC_TPC_DW.Delay6_DSTATE[0]) + SWC_TPC_DW.Delay5_DSTATE[0]) +
    SWC_TPC_DW.Delay4_DSTATE[0]) + SWC_TPC_DW.Delay3_DSTATE[0]) +
    SWC_TPC_DW.Delay2_DSTATE[0]) / 10.0F;

  /* Chart: '<S7>/Chart' */
  if (SWC_TPC_DW.is_active_c19_SWC_TPC == 0U) {
    SWC_TPC_DW.is_active_c19_SWC_TPC = 1U;
    SWC_TPC_DW.is_c19_SWC_TPC = SWC_TPC_IN_CoolantFolw2L;
    VAR_TpcCod_CoolantFlowReq_f32 = 2.0F;
  } else {
    guard1 = false;
    guard2 = false;
    switch (SWC_TPC_DW.is_c19_SWC_TPC) {
     case SWC_TPC_IN_CoolantFolw2L:
      if (rtb_LogicalOperator_g || (VAR_TpcCod_PowerIncreaseRate_f32 >=
           CAL_TpcCod_PowIncRatLim_f32)) {
        SWC_TPC_DW.is_c19_SWC_TPC = SWC_TPC_IN_CoolantFolw8L;
        VAR_TpcCod_CoolantFlowReq_f32 = 8.0F;
        SWC_TPC_DW.Cnt6L = 0U;
      } else {
        if (rtb_TmpSignalConversionAtRP_S_n >= rtb_Switch4_d) {
          SWC_TPC_DW.is_c19_SWC_TPC = SWC_TPC_IN_CoolantFolw4L;
          VAR_TpcCod_CoolantFlowReq_f32 = 4.0F;
          SWC_TPC_DW.Cnt2L = 0U;
        }
      }
      break;

     case SWC_TPC_IN_CoolantFolw4L:
      if (rtb_LogicalOperator_g || (VAR_TpcCod_PowerIncreaseRate_f32 >=
           CAL_TpcCod_PowIncRatLim_f32)) {
        SWC_TPC_DW.is_c19_SWC_TPC = SWC_TPC_IN_CoolantFolw8L;
        VAR_TpcCod_CoolantFlowReq_f32 = 8.0F;
        SWC_TPC_DW.Cnt6L = 0U;
      } else if (rtb_TmpSignalConversionAtRP_S_n < rtb_Switch4_d -
                 CAL_TpcCod_TrqRelay_f32) {
        idxDelay = SWC_TPC_DW.Cnt2L + 1;
        if (idxDelay > 65535) {
          idxDelay = 65535;
        }

        SWC_TPC_DW.Cnt2L = (uint16)idxDelay;
        if (SWC_TPC_DW.Cnt2L > CAL_TpcCod_CntHysteresislop_u16) {
          SWC_TPC_DW.is_c19_SWC_TPC = SWC_TPC_IN_CoolantFolw2L;
          VAR_TpcCod_CoolantFlowReq_f32 = 2.0F;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      break;

     case SWC_TPC_IN_CoolantFolw6L:
      if (rtb_TmpSignalConversionAtRP_S_n < rtb_CoolantFlow4L -
          CAL_TpcCod_TrqRelay_f32) {
        idxDelay = SWC_TPC_DW.Cnt4L + 1;
        if (idxDelay > 65535) {
          idxDelay = 65535;
        }

        SWC_TPC_DW.Cnt4L = (uint16)idxDelay;
        if (SWC_TPC_DW.Cnt4L > CAL_TpcCod_CntHysteresislop_u16) {
          SWC_TPC_DW.is_c19_SWC_TPC = SWC_TPC_IN_CoolantFolw4L;
          VAR_TpcCod_CoolantFlowReq_f32 = 4.0F;
          SWC_TPC_DW.Cnt2L = 0U;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }
      break;

     default:
      /* case IN_CoolantFolw8L: */
      if ((rtb_TmpSignalConversionAtRP_S_n < rtb_CoolantFlow6L -
           CAL_TpcCod_TrqRelay_f32) && (!rtb_LogicalOperator_g)) {
        idxDelay = SWC_TPC_DW.Cnt6L + 1;
        if (idxDelay > 65535) {
          idxDelay = 65535;
        }

        SWC_TPC_DW.Cnt6L = (uint16)idxDelay;
        if (SWC_TPC_DW.Cnt6L > CAL_TpcCod_CntHysteresislop_u16) {
          SWC_TPC_DW.is_c19_SWC_TPC = SWC_TPC_IN_CoolantFolw6L;
          VAR_TpcCod_CoolantFlowReq_f32 = 6.0F;
          SWC_TPC_DW.Cnt4L = 0U;
        }
      }
      break;
    }

    if (guard2) {
      if ((rtb_TmpSignalConversionAtRP_S_n >= rtb_CoolantFlow6L) ||
          rtb_LogicalOperator_g || (VAR_TpcCod_PowerIncreaseRate_f32 >=
           CAL_TpcCod_PowIncRatLim_f32)) {
        SWC_TPC_DW.is_c19_SWC_TPC = SWC_TPC_IN_CoolantFolw8L;
        VAR_TpcCod_CoolantFlowReq_f32 = 8.0F;
        SWC_TPC_DW.Cnt6L = 0U;
      }
    }

    if (guard1) {
      if (rtb_TmpSignalConversionAtRP_S_n >= rtb_CoolantFlow4L) {
        SWC_TPC_DW.is_c19_SWC_TPC = SWC_TPC_IN_CoolantFolw6L;
        VAR_TpcCod_CoolantFlowReq_f32 = 6.0F;
        SWC_TPC_DW.Cnt4L = 0U;
      }
    }
  }

  /* End of Chart: '<S7>/Chart' */

  /* Switch: '<S16>/Switch' incorporates:
   *  RelationalOperator: '<S16>/Relational Operator'
   */
  if (rtb_TmpSignalConversionAtRP_S_k <= rtb_TmpSignalConversionAtRP_S_i) {
    rtb_Switch4_d = rtb_TmpSignalConversionAtRP_S_k;
  } else {
    rtb_Switch4_d = rtb_TmpSignalConversionAtRP_S_i;
  }

  /* End of Switch: '<S16>/Switch' */

  /* Switch: '<S16>/Switch1' incorporates:
   *  RelationalOperator: '<S16>/Relational Operator1'
   */
  if (rtb_Switch4_d <= rtb_TmpSignalConversionAtRP__jn) {
    rtb_TmpSignalConversionAtRP__jn = rtb_Switch4_d;
  }

  /* End of Switch: '<S16>/Switch1' */

  /* Switch: '<S16>/Switch2' incorporates:
   *  Constant: '<S16>/CAL_TpcCod_NTCHighTemp_f32'
   *  Constant: '<S16>/CAL_TpcCod_NTCLowTemp_f32'
   *  Constant: '<S16>/Constant'
   *  RelationalOperator: '<S16>/Relational Operator2'
   *  RelationalOperator: '<S16>/Relational Operator3'
   *  UnitDelay: '<S16>/Unit Delay'
   */
  if (rtb_TmpSignalConversionAtRP__jn <= CAL_TpcCod_NTCLowTemp_f32) {
    SWC_TPC_DW.UnitDelay_DSTATE_kk = true;
  } else {
    SWC_TPC_DW.UnitDelay_DSTATE_kk = ((rtb_TmpSignalConversionAtRP__jn <
      CAL_TpcCod_NTCHighTemp_f32) && SWC_TPC_DW.UnitDelay_DSTATE_kk);
  }

  /* End of Switch: '<S16>/Switch2' */

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S7>/CAL_TpcCod_CoolFlow1LReq_f32'
   *  UnitDelay: '<S16>/Unit Delay'
   */
  if (SWC_TPC_DW.UnitDelay_DSTATE_kk) {
    VAR_TpcCod_CoolantFlowFinReq_f32 = CAL_TpcCod_CoolFlow1LReq_f32;
  } else {
    VAR_TpcCod_CoolantFlowFinReq_f32 = VAR_TpcCod_CoolantFlowReq_f32;
  }

  /* End of Switch: '<S7>/Switch' */

  /* Switch: '<S45>/Switch' incorporates:
   *  Constant: '<S45>/CAL_TpcCod_NegSpdDirStop_f32'
   *  Constant: '<S45>/CAL_TpcCod_PosSpdDirStop_f32'
   *  Constant: '<S45>/GLB_TpcCod_MotorBw_u8'
   *  Constant: '<S45>/GLB_TpcCod_MotorStop_u8'
   *  Logic: '<S45>/Logical Operator'
   *  RelationalOperator: '<S45>/Relational Operator'
   *  RelationalOperator: '<S45>/Relational Operator1'
   *  RelationalOperator: '<S45>/Relational Operator2'
   *  Switch: '<S45>/Switch1'
   */
  if ((rtb_TmpSignalConversionAtRP_SWC >= CAL_TpcCod_NegSpdDirStop_f32) &&
      (rtb_TmpSignalConversionAtRP_SWC <= CAL_TpcCod_PosSpdDirStop_f32)) {
    tpccod_SgnRotDir = ((uint8)GLB_TpcCod_MotorStop_u8);
  } else if (rtb_TmpSignalConversionAtRP_SWC > CAL_TpcCod_PosSpdDirStop_f32) {
    /* Switch: '<S45>/Switch1' incorporates:
     *  Constant: '<S45>/GLB_TpcCod_MotorFw_u8'
     */
    tpccod_SgnRotDir = ((uint8)GLB_TpcCod_MotorFw_u8);
  } else {
    tpccod_SgnRotDir = ((uint8)GLB_TpcCod_MotorBw_u8);
  }

  /* End of Switch: '<S45>/Switch' */

  /* SignalConversion generated from: '<S1>/RP_SWC_MPC_MPC_TrqMechFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MPC_MPC_TrqMechFlt'
   */
  Rte_Read_RP_SWC_MPC_MPC_TrqMechFlt(&rtb_TmpSignalConversionAtRP__n1);

  /* Switch: '<S46>/Switch' incorporates:
   *  Constant: '<S46>/CAL_TpcCod_NegTrqDirStop_f32'
   *  Constant: '<S46>/CAL_TpcCod_PosTrqDirStop_f32'
   *  Constant: '<S46>/GLB_TpcCod_NegvTrq_u8'
   *  Constant: '<S46>/GLB_TpcCod_ZeroTrq_u8'
   *  Logic: '<S46>/Logical Operator'
   *  RelationalOperator: '<S46>/Relational Operator'
   *  RelationalOperator: '<S46>/Relational Operator1'
   *  RelationalOperator: '<S46>/Relational Operator2'
   *  Switch: '<S46>/Switch1'
   */
  if ((rtb_TmpSignalConversionAtRP__n1 >= CAL_TpcCod_NegTrqDirStop_f32) &&
      (rtb_TmpSignalConversionAtRP__n1 <= CAL_TpcCod_PosTrqDirStop_f32)) {
    tpccod_SgnTrqMechDir = ((uint8)GLB_TpcCod_ZeroTrq_u8);
  } else if (rtb_TmpSignalConversionAtRP__n1 > CAL_TpcCod_PosTrqDirStop_f32) {
    /* Switch: '<S46>/Switch1' incorporates:
     *  Constant: '<S46>/GLB_TpcCod_PosvTrq_u8'
     */
    tpccod_SgnTrqMechDir = ((uint8)GLB_TpcCod_PosvTrq_u8);
  } else {
    tpccod_SgnTrqMechDir = ((uint8)GLB_TpcCod_NegvTrq_u8);
  }

  /* End of Switch: '<S46>/Switch' */

  /* If: '<S44>/If' incorporates:
   *  Constant: '<S44>/GLB_TpcCod_MotorBw_u8'
   *  Constant: '<S44>/GLB_TpcCod_MotorFw_u8'
   *  Constant: '<S44>/GLB_TpcCod_NegvTrq_u8'
   *  Constant: '<S44>/GLB_TpcCod_PosvTrq_u8'
   */
  if ((tpccod_SgnRotDir != ((uint8)GLB_TpcCod_MotorBw_u8)) &&
      (tpccod_SgnTrqMechDir != ((uint8)GLB_TpcCod_NegvTrq_u8))) {
    /* Outputs for IfAction SubSystem: '<S44>/If Action Subsystem' incorporates:
     *  ActionPort: '<S47>/Action Port'
     */
    /* SignalConversion generated from: '<S47>/Out1' incorporates:
     *  Constant: '<S47>/GLB_TpcCod_FwELect_u8'
     */
    tpccod_stMotorMod = ((uint8)GLB_TpcCod_FwELect_u8);

    /* End of Outputs for SubSystem: '<S44>/If Action Subsystem' */
  } else if ((tpccod_SgnRotDir == ((uint8)GLB_TpcCod_MotorBw_u8)) &&
             (tpccod_SgnTrqMechDir == ((uint8)GLB_TpcCod_PosvTrq_u8))) {
    /* Outputs for IfAction SubSystem: '<S44>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S48>/Action Port'
     */
    /* SignalConversion generated from: '<S48>/Out1' incorporates:
     *  Constant: '<S48>/GLB_TpcCod_BwGene_u8'
     */
    tpccod_stMotorMod = ((uint8)GLB_TpcCod_BwGene_u8);

    /* End of Outputs for SubSystem: '<S44>/If Action Subsystem1' */
  } else if ((tpccod_SgnRotDir == ((uint8)GLB_TpcCod_MotorFw_u8)) &&
             (tpccod_SgnTrqMechDir == ((uint8)GLB_TpcCod_NegvTrq_u8))) {
    /* Outputs for IfAction SubSystem: '<S44>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S49>/Action Port'
     */
    /* SignalConversion generated from: '<S49>/Out1' incorporates:
     *  Constant: '<S49>/GLB_TpcCod_FwGene_u8'
     */
    tpccod_stMotorMod = ((uint8)GLB_TpcCod_FwGene_u8);

    /* End of Outputs for SubSystem: '<S44>/If Action Subsystem2' */
  } else {
    /* Outputs for IfAction SubSystem: '<S44>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S50>/Action Port'
     */
    /* SignalConversion generated from: '<S50>/Out1' incorporates:
     *  Constant: '<S50>/GLB_TpcCod_BwELect_u8'
     */
    tpccod_stMotorMod = ((uint8)GLB_TpcCod_BwELect_u8);

    /* End of Outputs for SubSystem: '<S44>/If Action Subsystem3' */
  }

  /* End of If: '<S44>/If' */

  /* Logic: '<S8>/Logical Operator' incorporates:
   *  Constant: '<S8>/GLB_TpcCod_FwELect_u8'
   *  Constant: '<S8>/GLB_TpcCod_FwGene_u8'
   *  RelationalOperator: '<S8>/Relational Operator'
   *  RelationalOperator: '<S8>/Relational Operator1'
   */
  VAR_TpcCod_flgMotorElecMode_b = ((tpccod_stMotorMod == ((uint8)
    GLB_TpcCod_FwELect_u8)) || (tpccod_stMotorMod == ((uint8)
    GLB_TpcCod_FwGene_u8)));

  /* Switch: '<S117>/Switch2' incorporates:
   *  Constant: '<S117>/CAL_TpcMot_flgTrqRefSwt_b'
   *  Constant: '<S117>/GLB_Tpc_MaximumTorque_f32'
   */
  if (CAL_TpcMot_flgTrqRefSwt_b) {
    VAR_TpcMot_ElecTrqRef_f32 = VAR_TpcMot_TrqElecExC_f32;
  } else {
    VAR_TpcMot_ElecTrqRef_f32 = GLB_Tpc_MaximumTorque_f32;
  }

  /* End of Switch: '<S117>/Switch2' */

  /* Product: '<S129>/Product' */
  VAR_TpcMot_ElecTrqLimTsttrWoRamp_f32 = rtb_Switch_f4 *
    VAR_TpcMot_ElecTrqRef_f32;

  /* Sum: '<S127>/Subtract' incorporates:
   *  UnitDelay: '<S127>/Unit Delay2'
   */
  rtb_Switch4_d = VAR_TpcMot_ElecTrqLimTsttrWoRamp_f32 -
    VAR_TpcMot_ElecTrqLimTsttr_f32;

  /* Switch: '<S127>/Switch2' incorporates:
   *  Constant: '<S119>/CAL_TpcMot_tSttrTrqLimRamp_f32'
   *  RelationalOperator: '<S127>/Relational Operator'
   *  Sum: '<S127>/Add1'
   *  UnitDelay: '<S127>/Unit Delay2'
   */
  if (rtb_Switch4_d <= CAL_TpcMot_tSttrTrqLimRamp_f32) {
    /* Switch: '<S127>/Switch3' incorporates:
     *  Product: '<S127>/Product'
     *  RelationalOperator: '<S127>/Relational Operator1'
     *  Sum: '<S127>/Add2'
     *  UnitDelay: '<S127>/Unit Delay2'
     */
    if (-rtb_Switch4_d <= CAL_TpcMot_tSttrTrqLimRamp_f32) {
      VAR_TpcMot_ElecTrqLimTsttr_f32 = VAR_TpcMot_ElecTrqLimTsttrWoRamp_f32;
    } else {
      VAR_TpcMot_ElecTrqLimTsttr_f32 -= CAL_TpcMot_tSttrTrqLimRamp_f32;
    }

    /* End of Switch: '<S127>/Switch3' */
  } else {
    VAR_TpcMot_ElecTrqLimTsttr_f32 += CAL_TpcMot_tSttrTrqLimRamp_f32;
  }

  /* End of Switch: '<S127>/Switch2' */

  /* Product: '<S215>/Product' */
  VAR_TpcTmp_ElecTrqLimTdbcWoRamp_f32 = rtb_Switch_iq *
    VAR_TpcMot_ElecTrqRef_f32;

  /* Sum: '<S213>/Subtract' incorporates:
   *  UnitDelay: '<S213>/Unit Delay2'
   */
  rtb_Switch4_d = VAR_TpcTmp_ElecTrqLimTdbcWoRamp_f32 -
    VAR_TpcTmp_ElecTrqLimTdbc_f32;

  /* Switch: '<S213>/Switch2' incorporates:
   *  Constant: '<S195>/CAL_TpcTmp_tDBCTrqLimRamp_f32'
   *  RelationalOperator: '<S213>/Relational Operator'
   *  Sum: '<S213>/Add1'
   *  UnitDelay: '<S213>/Unit Delay2'
   */
  if (rtb_Switch4_d <= CAL_TpcTmp_tDBCTrqLimRamp_f32) {
    /* Switch: '<S213>/Switch3' incorporates:
     *  Product: '<S213>/Product'
     *  RelationalOperator: '<S213>/Relational Operator1'
     *  Sum: '<S213>/Add2'
     *  UnitDelay: '<S213>/Unit Delay2'
     */
    if (-rtb_Switch4_d <= CAL_TpcTmp_tDBCTrqLimRamp_f32) {
      VAR_TpcTmp_ElecTrqLimTdbc_f32 = VAR_TpcTmp_ElecTrqLimTdbcWoRamp_f32;
    } else {
      VAR_TpcTmp_ElecTrqLimTdbc_f32 -= CAL_TpcTmp_tDBCTrqLimRamp_f32;
    }

    /* End of Switch: '<S213>/Switch3' */
  } else {
    VAR_TpcTmp_ElecTrqLimTdbc_f32 += CAL_TpcTmp_tDBCTrqLimRamp_f32;
  }

  /* End of Switch: '<S213>/Switch2' */

  /* Product: '<S200>/Product' */
  VAR_TpcTmp_ElecTrqLimTcoolant_f32 = VAR_TpcTmp_CofDertTcoolant_f32 *
    VAR_TpcMot_ElecTrqRef_f32;

  /* Product: '<S228>/Product' */
  VAR_TpcTmp_ElecTrqLimTdrvboard_f32 = VAR_TpcTmp_CofDertTdrvboard_f32 *
    VAR_TpcMot_ElecTrqRef_f32;

  /* Product: '<S231>/Product' */
  VAR_TpcTmp_ElecTrqLimTIGBTWoRamp_f32 = rtb_Switch_ba *
    VAR_TpcMot_ElecTrqRef_f32;

  /* Sum: '<S232>/Subtract' incorporates:
   *  UnitDelay: '<S232>/Unit Delay2'
   */
  rtb_Switch4_d = VAR_TpcTmp_ElecTrqLimTIGBTWoRamp_f32 -
    VAR_TpcTmp_ElecTrqLimTIGBT_f32;

  /* Switch: '<S232>/Switch2' incorporates:
   *  Constant: '<S197>/CAL_TpcTmp_tIGBTTrqLimRamp_f32'
   *  RelationalOperator: '<S232>/Relational Operator'
   *  Sum: '<S232>/Add1'
   *  UnitDelay: '<S232>/Unit Delay2'
   */
  if (rtb_Switch4_d <= CAL_TpcTmp_tIGBTTrqLimRamp_f32) {
    /* Switch: '<S232>/Switch3' incorporates:
     *  Product: '<S232>/Product'
     *  RelationalOperator: '<S232>/Relational Operator1'
     *  Sum: '<S232>/Add2'
     *  UnitDelay: '<S232>/Unit Delay2'
     */
    if (-rtb_Switch4_d <= CAL_TpcTmp_tIGBTTrqLimRamp_f32) {
      VAR_TpcTmp_ElecTrqLimTIGBT_f32 = VAR_TpcTmp_ElecTrqLimTIGBTWoRamp_f32;
    } else {
      VAR_TpcTmp_ElecTrqLimTIGBT_f32 -= CAL_TpcTmp_tIGBTTrqLimRamp_f32;
    }

    /* End of Switch: '<S232>/Switch3' */
  } else {
    VAR_TpcTmp_ElecTrqLimTIGBT_f32 += CAL_TpcTmp_tIGBTTrqLimRamp_f32;
  }

  /* End of Switch: '<S232>/Switch2' */

  /* Switch: '<S185>/Switch' incorporates:
   *  Constant: '<S185>/Zero'
   *  RelationalOperator: '<S185>/Relational Operator'
   */
  if (rtb_TmpSignalConversionAtRP_SWC >= 0.0F) {
    rtb_TmpSignalConversionAtRP_S_k = rtb_TmpSignalConversionAtRP_SWC;
  } else {
    rtb_TmpSignalConversionAtRP_S_k = 0.0F;
  }

  /* End of Switch: '<S185>/Switch' */

  /* Lookup_n-D: '<S185>/OvSpdDertQurd1Table' */
  VAR_TpcSmp_cofDertOvrSpdElecQuad1_f32 = look1_iflf_binlcapw
    (rtb_TmpSignalConversionAtRP_S_k, ((const float32 *)
      &(CAL_TpcSmp_OvrSpdQurd1TableX_Spd_af32[0])), ((const float32 *)
      &(CAL_TpcSmp_OvrSpdQurd1TableY_Cof_af32[0])), 6U);

  /* Switch: '<S185>/Switch1' incorporates:
   *  Constant: '<S185>/Zero1'
   *  RelationalOperator: '<S185>/Relational Operator1'
   */
  if (rtb_TmpSignalConversionAtRP_SWC <= 0.0F) {
    rtb_TmpSignalConversionAtRP_S_k = rtb_TmpSignalConversionAtRP_SWC;
  } else {
    rtb_TmpSignalConversionAtRP_S_k = 0.0F;
  }

  /* End of Switch: '<S185>/Switch1' */

  /* Lookup_n-D: '<S185>/OvSpdDertQurd3Table' incorporates:
   *  Abs: '<S185>/Abs'
   */
  VAR_TpcSmp_cofDertOvrSpdElecQuad3_f32 = look1_iflf_binlcapw(fabsf
    (rtb_TmpSignalConversionAtRP_S_k), ((const float32 *)
    &(CAL_TpcSmp_OvrSpdQurd3TableX_Spd_af32[0])), ((const float32 *)
    &(CAL_TpcSmp_OvrSpdQurd3TableY_Cof_af32[0])), 6U);

  /* Switch: '<S185>/Switch4' incorporates:
   *  RelationalOperator: '<S185>/Relational Operator4'
   */
  if (VAR_TpcSmp_cofDertOvrSpdElecQuad1_f32 <=
      VAR_TpcSmp_cofDertOvrSpdElecQuad3_f32) {
    rtb_Switch4_d = VAR_TpcSmp_cofDertOvrSpdElecQuad1_f32;
  } else {
    rtb_Switch4_d = VAR_TpcSmp_cofDertOvrSpdElecQuad3_f32;
  }

  /* End of Switch: '<S185>/Switch4' */

  /* Product: '<S185>/Product' */
  VAR_TpcSmp_ElecTrqLimOvrSpd_f32 = rtb_Switch4_d * VAR_TpcMot_ElecTrqRef_f32;

  /* Logic: '<S112>/Logical Operator' */
  VAR_TpcFuv_FimTrqLimLv1_b = !rtb_RelationalOperator4_o;

  /* Logic: '<S112>/Logical Operator1' */
  VAR_TpcFuv_FimTrqLimLv2_b = !rtb_RelationalOperator1_cn;

  /* Logic: '<S112>/Logical Operator2' */
  VAR_TpcFuv_FimTrqLimLv3_b = !rtb_RelationalOperator3_kx;

  /* Logic: '<S112>/Logical Operator3' */
  VAR_TpcFuv_FimTrqLimLv4_b = !rtb_FIM_TrqLimLvFour;

  /* Switch: '<S117>/Switch3' incorporates:
   *  Constant: '<S117>/CAL_TpcMot_flgTrqRefSwt_b'
   *  Constant: '<S117>/GLB_Tpc_MaximumTorque_f32'
   *  Gain: '<S117>/Negate1'
   */
  if (CAL_TpcMot_flgTrqRefSwt_b) {
    VAR_TpcMot_GenTrqRef_f32 = VAR_TpcMot_TrqGenExC_f32;
  } else {
    VAR_TpcMot_GenTrqRef_f32 = -GLB_Tpc_MaximumTorque_f32;
  }

  /* End of Switch: '<S117>/Switch3' */

  /* Chart: '<S111>/tpcfuv_TorqLim' incorporates:
   *  Constant: '<S111>/CAL_TpcFuv_CofTrqLimLv1_f32'
   *  Constant: '<S111>/CAL_TpcFuv_CofTrqLimLv2_f32'
   *  Constant: '<S111>/CAL_TpcFuv_CofTrqLimLv3_f32'
   *  Constant: '<S111>/CAL_TpcFuv_CofTrqLimLv4_f32'
   */
  if (VAR_TpcFuv_FimTrqLimLv4_b) {
    VAR_TpcFuv_ElecTrqLimDiag_f32 = CAL_TpcFuv_CofTrqLimLv4_f32 *
      VAR_TpcMot_ElecTrqRef_f32;
    VAR_TpcFuv_GenTrqLimDiag_f32 = CAL_TpcFuv_CofTrqLimLv4_f32 *
      VAR_TpcMot_GenTrqRef_f32;
  } else if (VAR_TpcFuv_FimTrqLimLv3_b) {
    VAR_TpcFuv_ElecTrqLimDiag_f32 = CAL_TpcFuv_CofTrqLimLv3_f32 *
      VAR_TpcMot_ElecTrqRef_f32;
    VAR_TpcFuv_GenTrqLimDiag_f32 = CAL_TpcFuv_CofTrqLimLv3_f32 *
      VAR_TpcMot_GenTrqRef_f32;
  } else if (VAR_TpcFuv_FimTrqLimLv2_b) {
    VAR_TpcFuv_ElecTrqLimDiag_f32 = CAL_TpcFuv_CofTrqLimLv2_f32 *
      VAR_TpcMot_ElecTrqRef_f32;
    VAR_TpcFuv_GenTrqLimDiag_f32 = CAL_TpcFuv_CofTrqLimLv2_f32 *
      VAR_TpcMot_GenTrqRef_f32;
  } else if (VAR_TpcFuv_FimTrqLimLv1_b) {
    VAR_TpcFuv_ElecTrqLimDiag_f32 = CAL_TpcFuv_CofTrqLimLv1_f32 *
      VAR_TpcMot_ElecTrqRef_f32;
    VAR_TpcFuv_GenTrqLimDiag_f32 = CAL_TpcFuv_CofTrqLimLv1_f32 *
      VAR_TpcMot_GenTrqRef_f32;
  } else {
    VAR_TpcFuv_ElecTrqLimDiag_f32 = VAR_TpcMot_ElecTrqRef_f32;
    VAR_TpcFuv_GenTrqLimDiag_f32 = VAR_TpcMot_GenTrqRef_f32;
  }

  /* End of Chart: '<S111>/tpcfuv_TorqLim' */

  /* Product: '<S153>/Product' incorporates:
   *  Constant: '<S153>/CAL_TpcSmp_SystemEffiElec_f32'
   *  Constant: '<S153>/Constant'
   *  Product: '<S153>/Divide'
   *  Sum: '<S153>/Add'
   */
  VAR_tpcsmp_ElecPwrDert_f32 = (VAR_TpcSmp_iDcLnkMax_f32 *
    rtb_TmpSignalConversionAtRP_S_f / 1000.0F - VAR_tpcsmp_PwrLoss_f32) *
    CAL_TpcSmp_SystemEffiElec_f32;

  /* Product: '<S151>/Product' */
  VAR_TpcSmp_ElecPwrLinearDertOvrCurt_f32 = VAR_TpcSmp_cofDertOvrCurtElec_f32 *
    VAR_TpcMot_ElecPwrRef_f32;

  /* Switch: '<S149>/Switch1' incorporates:
   *  Constant: '<S149>/CAL_TpcSmp_CurtModeSelc_b'
   *  RelationalOperator: '<S149>/Relational Operator'
   *  Switch: '<S149>/Switch'
   */
  if (CAL_TpcSmp_CurtModeSelc_b) {
    VAR_TpcSmp_ElecPwrLimOvrCurt_f32 = VAR_tpcsmp_ElecPwrDert_f32;
  } else if (VAR_TpcSmp_ElecPwrPIDertOvrCurt_f32 <
             VAR_TpcSmp_ElecPwrLinearDertOvrCurt_f32) {
    /* Switch: '<S149>/Switch' */
    VAR_TpcSmp_ElecPwrLimOvrCurt_f32 = VAR_TpcSmp_ElecPwrPIDertOvrCurt_f32;
  } else {
    VAR_TpcSmp_ElecPwrLimOvrCurt_f32 = VAR_TpcSmp_ElecPwrLinearDertOvrCurt_f32;
  }

  /* End of Switch: '<S149>/Switch1' */

  /* Switch: '<S37>/Switch' incorporates:
   *  Constant: '<S37>/GLB_TpcCod_MotorStop_u8'
   *  Constant: '<S37>/ZeroSpd'
   *  RelationalOperator: '<S37>/Relational Operator'
   */
  if (tpccod_SgnRotDir != ((uint8)GLB_TpcCod_MotorStop_u8)) {
    rtb_TmpSignalConversionAtRP_S_f = rtb_TmpSignalConversionAtRP_SWC;
  } else {
    rtb_TmpSignalConversionAtRP_S_f = 0.0F;
  }

  /* End of Switch: '<S37>/Switch' */

  /* Abs: '<S37>/Abs' */
  rtb_TmpSignalConversionAtRP_S_f = fabsf(rtb_TmpSignalConversionAtRP_S_f);

  /* Switch: '<S37>/Switch1' incorporates:
   *  Constant: '<S37>/CofPwrCalc'
   *  Constant: '<S37>/GLB_Tpc_MaximumTorque_f32'
   *  Constant: '<S37>/ZeroSpd'
   *  Product: '<S37>/Divide'
   *  RelationalOperator: '<S37>/Relational Operator1'
   */
  if (rtb_TmpSignalConversionAtRP_S_f != 0.0F) {
    VAR_TpcCod_ElecTrqCalcOvrCurt_f32 = VAR_TpcSmp_ElecPwrLimOvrCurt_f32 *
      9550.0F / rtb_TmpSignalConversionAtRP_S_f;
  } else {
    VAR_TpcCod_ElecTrqCalcOvrCurt_f32 = GLB_Tpc_MaximumTorque_f32;
  }

  /* End of Switch: '<S37>/Switch1' */

  /* Product: '<S179>/Product' */
  VAR_TpcSmp_ElecPwrLinearDertUdrVolt_f32 = VAR_TpcSmp_cofDertUdrVoltElec_f32 *
    VAR_TpcMot_ElecPwrRef_f32;

  /* Switch: '<S177>/Switch1' incorporates:
   *  Constant: '<S177>/GLB_Tpc_MaximumPower_f32'
   */
  if (rtb_TmpSignalConversionAtRP_S_d) {
    /* Switch: '<S177>/Switch' incorporates:
     *  RelationalOperator: '<S177>/Relational Operator'
     */
    if (VAR_TpcSmp_ElecPwrLinearDertUdrVolt_f32 <
        VAR_TpcSmp_ElecPwrPIDertUdrVolt_f32) {
      VAR_TpcSmp_ElecPwrLimUdrVolt_f32 = VAR_TpcSmp_ElecPwrLinearDertUdrVolt_f32;
    } else {
      VAR_TpcSmp_ElecPwrLimUdrVolt_f32 = VAR_TpcSmp_ElecPwrPIDertUdrVolt_f32;
    }

    /* End of Switch: '<S177>/Switch' */
  } else {
    VAR_TpcSmp_ElecPwrLimUdrVolt_f32 = GLB_Tpc_MaximumPower_f32;
  }

  /* End of Switch: '<S177>/Switch1' */

  /* Switch: '<S38>/Switch' incorporates:
   *  Constant: '<S38>/GLB_TpcCod_MotorStop_u8'
   *  Constant: '<S38>/ZeroSpd'
   *  RelationalOperator: '<S38>/Relational Operator'
   */
  if (tpccod_SgnRotDir != ((uint8)GLB_TpcCod_MotorStop_u8)) {
    rtb_TmpSignalConversionAtRP_S_f = rtb_TmpSignalConversionAtRP_SWC;
  } else {
    rtb_TmpSignalConversionAtRP_S_f = 0.0F;
  }

  /* End of Switch: '<S38>/Switch' */

  /* Abs: '<S38>/Abs' */
  rtb_TmpSignalConversionAtRP_S_f = fabsf(rtb_TmpSignalConversionAtRP_S_f);

  /* Switch: '<S38>/Switch1' incorporates:
   *  Constant: '<S38>/CofPwrCalc'
   *  Constant: '<S38>/GLB_Tpc_MaximumTorque_f32'
   *  Constant: '<S38>/ZeroSpd'
   *  Product: '<S38>/Divide'
   *  RelationalOperator: '<S38>/Relational Operator1'
   */
  if (rtb_TmpSignalConversionAtRP_S_f != 0.0F) {
    VAR_TpcCod_ElecTrqCalcUdrVolt_f32 = VAR_TpcSmp_ElecPwrLimUdrVolt_f32 *
      9550.0F / rtb_TmpSignalConversionAtRP_S_f;
  } else {
    VAR_TpcCod_ElecTrqCalcUdrVolt_f32 = GLB_Tpc_MaximumTorque_f32;
  }

  /* End of Switch: '<S38>/Switch1' */

  /* Logic: '<S112>/Logical Operator4' */
  VAR_TpcFuv_FimPwrLimLv1_b = !rtb_FIM_PwrLimLvOne;

  /* Logic: '<S112>/Logical Operator5' */
  VAR_TpcFuv_FimPwrLimLv2_b = !rtb_FIM_PwrLimLvTwo;

  /* Logic: '<S112>/Logical Operator6' */
  VAR_TpcFuv_FimPwrLimLv3_b = !rtb_FIM_PwrLimLvThree;

  /* Logic: '<S112>/Logical Operator7' */
  VAR_TpcFuv_FimPwrLimLv4_b = !rtb_FIM_PwrLimLvFour;

  /* Chart: '<S111>/tpcfuv_PwrLim' incorporates:
   *  Constant: '<S111>/CAL_TpcFuv_CofPwrLimLv1_f32'
   *  Constant: '<S111>/CAL_TpcFuv_CofPwrLimLv2_f32'
   *  Constant: '<S111>/CAL_TpcFuv_CofPwrLimLv3_f32'
   *  Constant: '<S111>/CAL_TpcFuv_CofPwrLimLv4_f32'
   */
  if (VAR_TpcFuv_FimPwrLimLv4_b) {
    VAR_TpcFuv_ElecPwrLimDiag_f32 = CAL_TpcFuv_CofPwrLimLv4_f32 *
      VAR_TpcMot_ElecPwrRef_f32;
    VAR_TpcFuv_GenPwrLimDiag_f32 = CAL_TpcFuv_CofPwrLimLv4_f32 *
      VAR_TpcMot_GenPwrRef_f32;
  } else if (VAR_TpcFuv_FimPwrLimLv3_b) {
    VAR_TpcFuv_ElecPwrLimDiag_f32 = CAL_TpcFuv_CofPwrLimLv3_f32 *
      VAR_TpcMot_ElecPwrRef_f32;
    VAR_TpcFuv_GenPwrLimDiag_f32 = CAL_TpcFuv_CofPwrLimLv3_f32 *
      VAR_TpcMot_GenPwrRef_f32;
  } else if (VAR_TpcFuv_FimPwrLimLv2_b) {
    VAR_TpcFuv_ElecPwrLimDiag_f32 = CAL_TpcFuv_CofPwrLimLv2_f32 *
      VAR_TpcMot_ElecPwrRef_f32;
    VAR_TpcFuv_GenPwrLimDiag_f32 = CAL_TpcFuv_CofPwrLimLv2_f32 *
      VAR_TpcMot_GenPwrRef_f32;
  } else if (VAR_TpcFuv_FimPwrLimLv1_b) {
    VAR_TpcFuv_ElecPwrLimDiag_f32 = CAL_TpcFuv_CofPwrLimLv1_f32 *
      VAR_TpcMot_ElecPwrRef_f32;
    VAR_TpcFuv_GenPwrLimDiag_f32 = CAL_TpcFuv_CofPwrLimLv1_f32 *
      VAR_TpcMot_GenPwrRef_f32;
  } else {
    VAR_TpcFuv_ElecPwrLimDiag_f32 = VAR_TpcMot_ElecPwrRef_f32;
    VAR_TpcFuv_GenPwrLimDiag_f32 = VAR_TpcMot_GenPwrRef_f32;
  }

  /* End of Chart: '<S111>/tpcfuv_PwrLim' */

  /* Switch: '<S39>/Switch' incorporates:
   *  Constant: '<S39>/GLB_TpcCod_MotorStop_u8'
   *  Constant: '<S39>/ZeroSpd'
   *  RelationalOperator: '<S39>/Relational Operator'
   */
  if (tpccod_SgnRotDir != ((uint8)GLB_TpcCod_MotorStop_u8)) {
    rtb_TmpSignalConversionAtRP_S_f = rtb_TmpSignalConversionAtRP_SWC;
  } else {
    rtb_TmpSignalConversionAtRP_S_f = 0.0F;
  }

  /* End of Switch: '<S39>/Switch' */

  /* Abs: '<S39>/Abs' */
  rtb_TmpSignalConversionAtRP_S_f = fabsf(rtb_TmpSignalConversionAtRP_S_f);

  /* Switch: '<S39>/Switch1' incorporates:
   *  Constant: '<S39>/CofPwrCalc'
   *  Constant: '<S39>/GLB_Tpc_MaximumTorque_f32'
   *  Constant: '<S39>/ZeroSpd'
   *  Product: '<S39>/Divide'
   *  RelationalOperator: '<S39>/Relational Operator1'
   */
  if (rtb_TmpSignalConversionAtRP_S_f != 0.0F) {
    VAR_TpcCod_ElecTrqCalcDiag_f32 = VAR_TpcFuv_ElecPwrLimDiag_f32 * 9550.0F /
      rtb_TmpSignalConversionAtRP_S_f;
  } else {
    VAR_TpcCod_ElecTrqCalcDiag_f32 = GLB_Tpc_MaximumTorque_f32;
  }

  /* End of Switch: '<S39>/Switch1' */

  /* Chart: '<S33>/GetMinValue' */
  VAR_TpcCod_ElecTrqLim_f32 = fminf(VAR_TpcMot_TrqElecExC_f32,
    VAR_TpcMot_ElecTrqLimTsttr_f32);
  if (VAR_TpcTmp_ElecTrqLimTdbc_f32 < VAR_TpcCod_ElecTrqLim_f32) {
    VAR_TpcCod_ElecTrqLim_f32 = VAR_TpcTmp_ElecTrqLimTdbc_f32;
  }

  if (VAR_TpcTmp_ElecTrqLimTcoolant_f32 < VAR_TpcCod_ElecTrqLim_f32) {
    VAR_TpcCod_ElecTrqLim_f32 = VAR_TpcTmp_ElecTrqLimTcoolant_f32;
  }

  if (VAR_TpcTmp_ElecTrqLimTdrvboard_f32 < VAR_TpcCod_ElecTrqLim_f32) {
    VAR_TpcCod_ElecTrqLim_f32 = VAR_TpcTmp_ElecTrqLimTdrvboard_f32;
  }

  if (VAR_TpcTmp_ElecTrqLimTIGBT_f32 < VAR_TpcCod_ElecTrqLim_f32) {
    VAR_TpcCod_ElecTrqLim_f32 = VAR_TpcTmp_ElecTrqLimTIGBT_f32;
  }

  if (VAR_TpcSmp_ElecTrqLimOvrSpd_f32 < VAR_TpcCod_ElecTrqLim_f32) {
    VAR_TpcCod_ElecTrqLim_f32 = VAR_TpcSmp_ElecTrqLimOvrSpd_f32;
  }

  if (VAR_TpcFuv_ElecTrqLimDiag_f32 < VAR_TpcCod_ElecTrqLim_f32) {
    VAR_TpcCod_ElecTrqLim_f32 = VAR_TpcFuv_ElecTrqLimDiag_f32;
  }

  if (VAR_TpcCod_ElecTrqCalcOvrCurt_f32 < VAR_TpcCod_ElecTrqLim_f32) {
    VAR_TpcCod_ElecTrqLim_f32 = VAR_TpcCod_ElecTrqCalcOvrCurt_f32;
  }

  if (VAR_TpcCod_ElecTrqCalcUdrVolt_f32 < VAR_TpcCod_ElecTrqLim_f32) {
    VAR_TpcCod_ElecTrqLim_f32 = VAR_TpcCod_ElecTrqCalcUdrVolt_f32;
  }

  if (VAR_TpcCod_ElecTrqCalcDiag_f32 < VAR_TpcCod_ElecTrqLim_f32) {
    VAR_TpcCod_ElecTrqLim_f32 = VAR_TpcCod_ElecTrqCalcDiag_f32;
  }

  /* End of Chart: '<S33>/GetMinValue' */

  /* Product: '<S129>/Product1' */
  VAR_TpcMot_GenTrqLimTsttrWoRamp_f32 = rtb_Switch_f4 * VAR_TpcMot_GenTrqRef_f32;

  /* Sum: '<S128>/Subtract' incorporates:
   *  UnitDelay: '<S128>/Unit Delay2'
   */
  rtb_Switch_f4 = VAR_TpcMot_GenTrqLimTsttrWoRamp_f32 -
    VAR_TpcMot_GenTrqLimTsttr_f32;

  /* Switch: '<S128>/Switch2' incorporates:
   *  Constant: '<S119>/CAL_TpcMot_tSttrTrqLimRamp_f1'
   *  RelationalOperator: '<S128>/Relational Operator'
   *  Sum: '<S128>/Add1'
   *  UnitDelay: '<S128>/Unit Delay2'
   */
  if (rtb_Switch_f4 <= CAL_TpcMot_tSttrTrqLimRamp_f32) {
    /* Switch: '<S128>/Switch3' incorporates:
     *  Product: '<S128>/Product'
     *  RelationalOperator: '<S128>/Relational Operator1'
     *  Sum: '<S128>/Add2'
     *  UnitDelay: '<S128>/Unit Delay2'
     */
    if (-rtb_Switch_f4 <= CAL_TpcMot_tSttrTrqLimRamp_f32) {
      VAR_TpcMot_GenTrqLimTsttr_f32 = VAR_TpcMot_GenTrqLimTsttrWoRamp_f32;
    } else {
      VAR_TpcMot_GenTrqLimTsttr_f32 -= CAL_TpcMot_tSttrTrqLimRamp_f32;
    }

    /* End of Switch: '<S128>/Switch3' */
  } else {
    VAR_TpcMot_GenTrqLimTsttr_f32 += CAL_TpcMot_tSttrTrqLimRamp_f32;
  }

  /* End of Switch: '<S128>/Switch2' */

  /* Product: '<S215>/Product1' */
  VAR_TpcTmp_GenTrqLimTdbcWoRamp_f32 = rtb_Switch_iq * VAR_TpcMot_GenTrqRef_f32;

  /* Sum: '<S214>/Subtract' incorporates:
   *  UnitDelay: '<S214>/Unit Delay2'
   */
  rtb_Switch_iq = VAR_TpcTmp_GenTrqLimTdbcWoRamp_f32 -
    VAR_TpcTmp_GenTrqLimTdbc_f32;

  /* Switch: '<S214>/Switch2' incorporates:
   *  Constant: '<S195>/CAL_TpcTmp_tDBCTrqLimRamp_f1'
   *  RelationalOperator: '<S214>/Relational Operator'
   *  Sum: '<S214>/Add1'
   *  UnitDelay: '<S214>/Unit Delay2'
   */
  if (rtb_Switch_iq <= CAL_TpcTmp_tDBCTrqLimRamp_f32) {
    /* Switch: '<S214>/Switch3' incorporates:
     *  Product: '<S214>/Product'
     *  RelationalOperator: '<S214>/Relational Operator1'
     *  Sum: '<S214>/Add2'
     *  UnitDelay: '<S214>/Unit Delay2'
     */
    if (-rtb_Switch_iq <= CAL_TpcTmp_tDBCTrqLimRamp_f32) {
      VAR_TpcTmp_GenTrqLimTdbc_f32 = VAR_TpcTmp_GenTrqLimTdbcWoRamp_f32;
    } else {
      VAR_TpcTmp_GenTrqLimTdbc_f32 -= CAL_TpcTmp_tDBCTrqLimRamp_f32;
    }

    /* End of Switch: '<S214>/Switch3' */
  } else {
    VAR_TpcTmp_GenTrqLimTdbc_f32 += CAL_TpcTmp_tDBCTrqLimRamp_f32;
  }

  /* End of Switch: '<S214>/Switch2' */

  /* Product: '<S200>/Product1' */
  VAR_TpcTmp_GenTrqLimTcoolant_f32 = VAR_TpcTmp_CofDertTcoolant_f32 *
    VAR_TpcMot_GenTrqRef_f32;

  /* Product: '<S228>/Product1' */
  VAR_TpcTmp_GenTrqLimTdrvboard_f32 = VAR_TpcTmp_CofDertTdrvboard_f32 *
    VAR_TpcMot_GenTrqRef_f32;

  /* Product: '<S231>/Product1' */
  VAR_TpcTmp_GenTrqLimTIGBTWoRamp_f32 = rtb_Switch_ba * VAR_TpcMot_GenTrqRef_f32;

  /* Sum: '<S233>/Subtract' incorporates:
   *  UnitDelay: '<S233>/Unit Delay2'
   */
  rtb_Switch_iq = VAR_TpcTmp_GenTrqLimTIGBTWoRamp_f32 -
    VAR_TpcTmp_GenTrqLimTIGBT_f32;

  /* Switch: '<S233>/Switch2' incorporates:
   *  Constant: '<S197>/CAL_TpcTmp_tIGBTTrqLimRamp_f1'
   *  RelationalOperator: '<S233>/Relational Operator'
   *  Sum: '<S233>/Add1'
   *  UnitDelay: '<S233>/Unit Delay2'
   */
  if (rtb_Switch_iq <= CAL_TpcTmp_tIGBTTrqLimRamp_f32) {
    /* Switch: '<S233>/Switch3' incorporates:
     *  Product: '<S233>/Product'
     *  RelationalOperator: '<S233>/Relational Operator1'
     *  Sum: '<S233>/Add2'
     *  UnitDelay: '<S233>/Unit Delay2'
     */
    if (-rtb_Switch_iq <= CAL_TpcTmp_tIGBTTrqLimRamp_f32) {
      VAR_TpcTmp_GenTrqLimTIGBT_f32 = VAR_TpcTmp_GenTrqLimTIGBTWoRamp_f32;
    } else {
      VAR_TpcTmp_GenTrqLimTIGBT_f32 -= CAL_TpcTmp_tIGBTTrqLimRamp_f32;
    }

    /* End of Switch: '<S233>/Switch3' */
  } else {
    VAR_TpcTmp_GenTrqLimTIGBT_f32 += CAL_TpcTmp_tIGBTTrqLimRamp_f32;
  }

  /* End of Switch: '<S233>/Switch2' */

  /* Switch: '<S185>/Switch2' incorporates:
   *  Constant: '<S185>/Zero2'
   *  RelationalOperator: '<S185>/Relational Operator2'
   */
  if (rtb_TmpSignalConversionAtRP_SWC >= 0.0F) {
    rtb_TmpSignalConversionAtRP_S_k = rtb_TmpSignalConversionAtRP_SWC;
  } else {
    rtb_TmpSignalConversionAtRP_S_k = 0.0F;
  }

  /* End of Switch: '<S185>/Switch2' */

  /* Lookup_n-D: '<S185>/OvSpdDertQurd4Table' */
  VAR_TpcSmp_cofDertOvrSpdGenQuad4_f32 = look1_iflf_binlcapw
    (rtb_TmpSignalConversionAtRP_S_k, ((const float32 *)
      &(CAL_TpcSmp_OvrSpdQurd4TableX_Spd_af32[0])), ((const float32 *)
      &(CAL_TpcSmp_OvrSpdQurd4TableY_Cof_af32[0])), 6U);

  /* Switch: '<S185>/Switch3' incorporates:
   *  Constant: '<S185>/Zero3'
   *  RelationalOperator: '<S185>/Relational Operator3'
   */
  if (rtb_TmpSignalConversionAtRP_SWC <= 0.0F) {
    rtb_TmpSignalConversionAtRP_S_k = rtb_TmpSignalConversionAtRP_SWC;
  } else {
    rtb_TmpSignalConversionAtRP_S_k = 0.0F;
  }

  /* End of Switch: '<S185>/Switch3' */

  /* Lookup_n-D: '<S185>/OvSpdDertQurd2Table' incorporates:
   *  Abs: '<S185>/Abs1'
   */
  VAR_TpcSmp_cofDertOvrSpdGenQuad2_f32 = look1_iflf_binlcapw(fabsf
    (rtb_TmpSignalConversionAtRP_S_k), ((const float32 *)
    &(CAL_TpcSmp_OvrSpdQurd2TableX_Spd_af32[0])), ((const float32 *)
    &(CAL_TpcSmp_OvrSpdQurd2TableY_Cof_af32[0])), 6U);

  /* Switch: '<S185>/Switch5' incorporates:
   *  RelationalOperator: '<S185>/Relational Operator6'
   */
  if (VAR_TpcSmp_cofDertOvrSpdGenQuad4_f32 <=
      VAR_TpcSmp_cofDertOvrSpdGenQuad2_f32) {
    rtb_Switch_ba = VAR_TpcSmp_cofDertOvrSpdGenQuad4_f32;
  } else {
    rtb_Switch_ba = VAR_TpcSmp_cofDertOvrSpdGenQuad2_f32;
  }

  /* End of Switch: '<S185>/Switch5' */

  /* Product: '<S185>/Product1' */
  VAR_TpcSmp_GenTrqLimOvrSpd_f32 = rtb_Switch_ba * VAR_TpcMot_GenTrqRef_f32;

  /* Product: '<S162>/Product' incorporates:
   *  Constant: '<S162>/CAL_TpcSmp_SystemEffiGen_f32'
   *  Sum: '<S162>/Add'
   */
  VAR_tpcsmp_GenPwrDert_f32 = (rtb_Divide_b_tmp - VAR_tpcsmp_PwrLossGen_f32) *
    CAL_TpcSmp_SystemEffiGen_f32;

  /* Gain: '<S164>/Gain10' */
  VAR_TpcSmp_GenPwrPIDertOvrCurt_f32 = -VAR_tpcsmp_negOutputjudge_f32;

  /* Product: '<S160>/Product' */
  VAR_TpcSmp_GenPwrLinearDertOvrCurt_f32 = VAR_TpcSmp_cofDertOvrCurtGen_f32 *
    VAR_TpcMot_GenPwrRef_f32;

  /* Switch: '<S158>/Switch1' incorporates:
   *  Constant: '<S158>/CAL_TpcSmp_CurtModeSelc_b'
   *  RelationalOperator: '<S158>/Relational Operator'
   *  Switch: '<S158>/Switch'
   */
  if (CAL_TpcSmp_CurtModeSelc_b) {
    VAR_TpcSmp_GenPwrLimOvrCurt_f32 = VAR_tpcsmp_GenPwrDert_f32;
  } else if (VAR_TpcSmp_GenPwrPIDertOvrCurt_f32 >
             VAR_TpcSmp_GenPwrLinearDertOvrCurt_f32) {
    /* Switch: '<S158>/Switch' */
    VAR_TpcSmp_GenPwrLimOvrCurt_f32 = VAR_TpcSmp_GenPwrPIDertOvrCurt_f32;
  } else {
    VAR_TpcSmp_GenPwrLimOvrCurt_f32 = VAR_TpcSmp_GenPwrLinearDertOvrCurt_f32;
  }

  /* End of Switch: '<S158>/Switch1' */

  /* Switch: '<S41>/Switch' incorporates:
   *  Constant: '<S41>/GLB_TpcCod_MotorStop_u8'
   *  Constant: '<S41>/ZeroSpd'
   *  RelationalOperator: '<S41>/Relational Operator'
   */
  if (tpccod_SgnRotDir != ((uint8)GLB_TpcCod_MotorStop_u8)) {
    rtb_TmpSignalConversionAtRP_S_f = rtb_TmpSignalConversionAtRP_SWC;
  } else {
    rtb_TmpSignalConversionAtRP_S_f = 0.0F;
  }

  /* End of Switch: '<S41>/Switch' */

  /* Abs: '<S41>/Abs' */
  rtb_Switch_iq = fabsf(rtb_TmpSignalConversionAtRP_S_f);

  /* Switch: '<S41>/Switch1' incorporates:
   *  Constant: '<S41>/CofPwrCalc'
   *  Constant: '<S41>/GLB_Tpc_MaximumTorque_f32'
   *  Constant: '<S41>/ZeroSpd'
   *  Gain: '<S41>/Negate'
   *  Product: '<S41>/Divide'
   *  RelationalOperator: '<S41>/Relational Operator1'
   */
  if (rtb_Switch_iq != 0.0F) {
    VAR_TpcCod_GenTrqCalcOvrCurt_f32 = VAR_TpcSmp_GenPwrLimOvrCurt_f32 * 9550.0F
      / rtb_Switch_iq;
  } else {
    VAR_TpcCod_GenTrqCalcOvrCurt_f32 = -GLB_Tpc_MaximumTorque_f32;
  }

  /* End of Switch: '<S41>/Switch1' */

  /* Product: '<S171>/Product' */
  VAR_TpcSmp_GenPwrLinearDertOvrVolt_f32 = VAR_TpcSmp_cofDertOvrVoltGen_f32 *
    VAR_TpcMot_GenPwrRef_f32;

  /* Gain: '<S174>/Gain6' */
  VAR_TpcSmp_GenPwrPIDertOvrVolt_f32 = -rtb_Add;

  /* Switch: '<S169>/Switch' incorporates:
   *  RelationalOperator: '<S169>/Relational Operator'
   */
  if (VAR_TpcSmp_GenPwrLinearDertOvrVolt_f32 >
      VAR_TpcSmp_GenPwrPIDertOvrVolt_f32) {
    VAR_TpcSmp_GenPwrLimOvrVolt_f32 = VAR_TpcSmp_GenPwrLinearDertOvrVolt_f32;
  } else {
    VAR_TpcSmp_GenPwrLimOvrVolt_f32 = VAR_TpcSmp_GenPwrPIDertOvrVolt_f32;
  }

  /* End of Switch: '<S169>/Switch' */

  /* Switch: '<S42>/Switch' incorporates:
   *  Constant: '<S42>/GLB_TpcCod_MotorStop_u8'
   *  Constant: '<S42>/ZeroSpd'
   *  RelationalOperator: '<S42>/Relational Operator'
   */
  if (tpccod_SgnRotDir != ((uint8)GLB_TpcCod_MotorStop_u8)) {
    rtb_TmpSignalConversionAtRP_S_f = rtb_TmpSignalConversionAtRP_SWC;
  } else {
    rtb_TmpSignalConversionAtRP_S_f = 0.0F;
  }

  /* End of Switch: '<S42>/Switch' */

  /* Abs: '<S42>/Abs' */
  rtb_Add = fabsf(rtb_TmpSignalConversionAtRP_S_f);

  /* Switch: '<S42>/Switch1' incorporates:
   *  Constant: '<S42>/CofPwrCalc'
   *  Constant: '<S42>/GLB_Tpc_MaximumTorque_f32'
   *  Constant: '<S42>/ZeroSpd'
   *  Gain: '<S42>/Negate'
   *  Product: '<S42>/Divide'
   *  RelationalOperator: '<S42>/Relational Operator1'
   */
  if (rtb_Add != 0.0F) {
    VAR_TpcCod_GenTrqCalcOvrVolt_f32 = VAR_TpcSmp_GenPwrLimOvrVolt_f32 * 9550.0F
      / rtb_Add;
  } else {
    VAR_TpcCod_GenTrqCalcOvrVolt_f32 = -GLB_Tpc_MaximumTorque_f32;
  }

  /* End of Switch: '<S42>/Switch1' */

  /* Switch: '<S43>/Switch' incorporates:
   *  Constant: '<S43>/GLB_TpcCod_MotorStop_u8'
   *  Constant: '<S43>/ZeroSpd'
   *  RelationalOperator: '<S43>/Relational Operator'
   */
  if (tpccod_SgnRotDir != ((uint8)GLB_TpcCod_MotorStop_u8)) {
    rtb_TmpSignalConversionAtRP_S_f = rtb_TmpSignalConversionAtRP_SWC;
  } else {
    rtb_TmpSignalConversionAtRP_S_f = 0.0F;
  }

  /* End of Switch: '<S43>/Switch' */

  /* Abs: '<S43>/Abs' */
  rtb_Add = fabsf(rtb_TmpSignalConversionAtRP_S_f);

  /* Switch: '<S43>/Switch1' incorporates:
   *  Constant: '<S43>/CofPwrCalc'
   *  Constant: '<S43>/GLB_Tpc_MaximumTorque_f32'
   *  Constant: '<S43>/ZeroSpd'
   *  Gain: '<S43>/Negate'
   *  Product: '<S43>/Divide'
   *  RelationalOperator: '<S43>/Relational Operator1'
   */
  if (rtb_Add != 0.0F) {
    VAR_TpcCod_GenTrqCalcDiag_f32 = VAR_TpcFuv_GenPwrLimDiag_f32 * 9550.0F /
      rtb_Add;
  } else {
    VAR_TpcCod_GenTrqCalcDiag_f32 = -GLB_Tpc_MaximumTorque_f32;
  }

  /* End of Switch: '<S43>/Switch1' */

  /* Chart: '<S34>/GetMaxValue' */
  VAR_TpcCod_GenTrqLim_f32 = fmaxf(VAR_TpcMot_TrqGenExC_f32,
    VAR_TpcMot_GenTrqLimTsttr_f32);
  if (VAR_TpcTmp_GenTrqLimTdbc_f32 > VAR_TpcCod_GenTrqLim_f32) {
    VAR_TpcCod_GenTrqLim_f32 = VAR_TpcTmp_GenTrqLimTdbc_f32;
  }

  if (VAR_TpcTmp_GenTrqLimTcoolant_f32 > VAR_TpcCod_GenTrqLim_f32) {
    VAR_TpcCod_GenTrqLim_f32 = VAR_TpcTmp_GenTrqLimTcoolant_f32;
  }

  if (VAR_TpcTmp_GenTrqLimTdrvboard_f32 > VAR_TpcCod_GenTrqLim_f32) {
    VAR_TpcCod_GenTrqLim_f32 = VAR_TpcTmp_GenTrqLimTdrvboard_f32;
  }

  if (VAR_TpcTmp_GenTrqLimTIGBT_f32 > VAR_TpcCod_GenTrqLim_f32) {
    VAR_TpcCod_GenTrqLim_f32 = VAR_TpcTmp_GenTrqLimTIGBT_f32;
  }

  if (VAR_TpcSmp_GenTrqLimOvrSpd_f32 > VAR_TpcCod_GenTrqLim_f32) {
    VAR_TpcCod_GenTrqLim_f32 = VAR_TpcSmp_GenTrqLimOvrSpd_f32;
  }

  if (VAR_TpcFuv_GenTrqLimDiag_f32 > VAR_TpcCod_GenTrqLim_f32) {
    VAR_TpcCod_GenTrqLim_f32 = VAR_TpcFuv_GenTrqLimDiag_f32;
  }

  if (VAR_TpcCod_GenTrqCalcOvrCurt_f32 > VAR_TpcCod_GenTrqLim_f32) {
    VAR_TpcCod_GenTrqLim_f32 = VAR_TpcCod_GenTrqCalcOvrCurt_f32;
  }

  if (VAR_TpcCod_GenTrqCalcOvrVolt_f32 > VAR_TpcCod_GenTrqLim_f32) {
    VAR_TpcCod_GenTrqLim_f32 = VAR_TpcCod_GenTrqCalcOvrVolt_f32;
  }

  if (VAR_TpcCod_GenTrqCalcDiag_f32 > VAR_TpcCod_GenTrqLim_f32) {
    VAR_TpcCod_GenTrqLim_f32 = VAR_TpcCod_GenTrqCalcDiag_f32;
  }

  /* End of Chart: '<S34>/GetMaxValue' */

  /* If: '<S8>/If' incorporates:
   *  Abs: '<S18>/Abs'
   *  Abs: '<S18>/Abs1'
   *  Chart: '<S18>/Chart'
   *  Constant: '<S18>/ZeroValue'
   *  RelationalOperator: '<S18>/Relational Operator'
   *  Sum: '<S18>/Add'
   */
  if (VAR_TpcCod_flgMotorElecMode_b) {
    /* Outputs for IfAction SubSystem: '<S8>/If Action Subsystem' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    /* SignalConversion generated from: '<S17>/tpccod_TrqMaxCod' incorporates:
     *  Inport: '<S17>/tpccod_ElecTrqLim'
     */
    rtb_Switch_iq = VAR_TpcCod_ElecTrqLim_f32;

    /* Chart: '<S17>/Chart' incorporates:
     *  Abs: '<S17>/Abs'
     *  Abs: '<S17>/Abs1'
     *  Constant: '<S17>/ZeroValue'
     *  Inport: '<S17>/tpccod_ElecTrqLim'
     *  RelationalOperator: '<S17>/Relational Operator'
     *  Sum: '<S17>/Add'
     */
    if (fabsf(VAR_TpcCod_ElecTrqLim_f32) - fabsf(VAR_TpcCod_GenTrqLim_f32) >
        -1.0E-6F) {
      if (rtb_TmpSignalConversionAtRP_SWC < CAL_TpcCod_PosSpdHold_f32) {
        /* SignalConversion generated from: '<S17>/tpccod_TrqMinCod' */
        rtb_TmpSignalConversionAtRP_SWC = -VAR_TpcCod_ElecTrqLim_f32;
      } else if (rtb_TmpSignalConversionAtRP_SWC > CAL_TpcCod_PosSpdStart_f32) {
        /* SignalConversion generated from: '<S17>/tpccod_TrqMinCod' */
        rtb_TmpSignalConversionAtRP_SWC = VAR_TpcCod_GenTrqLim_f32;
      } else {
        /* Outputs for Function Call SubSystem: '<S23>/fun' */
        /* SignalConversion generated from: '<S17>/tpccod_TrqMinCod' incorporates:
         *  Constant: '<S24>/CAL_TpcCod_PosSpdHold_f32'
         *  Constant: '<S24>/CAL_TpcCod_PosSpdStart_f32'
         *  Gain: '<S24>/Gain'
         *  Product: '<S24>/Divide'
         *  Product: '<S24>/Product'
         *  Sum: '<S24>/Add'
         *  Sum: '<S24>/Add1'
         *  Sum: '<S24>/Add2'
         *  Sum: '<S24>/Add3'
         */
        rtb_TmpSignalConversionAtRP_SWC = (float32)(((float64)
          VAR_TpcCod_GenTrqLim_f32 + VAR_TpcCod_ElecTrqLim_f32) /
          (CAL_TpcCod_PosSpdStart_f32 - CAL_TpcCod_PosSpdHold_f32) * ((float64)
          rtb_TmpSignalConversionAtRP_SWC - CAL_TpcCod_PosSpdHold_f32) +
          -(float64)VAR_TpcCod_ElecTrqLim_f32);

        /* End of Outputs for SubSystem: '<S23>/fun' */
      }
    } else {
      /* SignalConversion generated from: '<S17>/tpccod_TrqMinCod' */
      rtb_TmpSignalConversionAtRP_SWC = VAR_TpcCod_GenTrqLim_f32;
    }

    /* End of Chart: '<S17>/Chart' */
    /* End of Outputs for SubSystem: '<S8>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S8>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    if (fabsf(VAR_TpcCod_ElecTrqLim_f32) - fabsf(VAR_TpcCod_GenTrqLim_f32) >
        -1.0E-6F) {
      /* Chart: '<S18>/Chart' */
      if (rtb_TmpSignalConversionAtRP_SWC > -CAL_TpcCod_PosSpdHold_f32) {
        /* SignalConversion generated from: '<S18>/tpccod_TrqMaxCod' */
        rtb_Switch_iq = VAR_TpcCod_ElecTrqLim_f32;
      } else if (rtb_TmpSignalConversionAtRP_SWC < -CAL_TpcCod_PosSpdStart_f32)
      {
        /* SignalConversion generated from: '<S18>/tpccod_TrqMaxCod' */
        rtb_Switch_iq = -VAR_TpcCod_GenTrqLim_f32;
      } else {
        /* Outputs for Function Call SubSystem: '<S25>/fun' */
        /* SignalConversion generated from: '<S18>/tpccod_TrqMaxCod' incorporates:
         *  Constant: '<S26>/CAL_TpcCod_PosSpdHold_f32'
         *  Constant: '<S26>/CAL_TpcCod_PosSpdStart_f32'
         *  Gain: '<S26>/Gain'
         *  Product: '<S26>/Divide'
         *  Product: '<S26>/Product'
         *  Sum: '<S26>/Add'
         *  Sum: '<S26>/Add1'
         *  Sum: '<S26>/Add2'
         *  Sum: '<S26>/Add3'
         */
        rtb_Switch_iq = (float32)(((float64)VAR_TpcCod_ElecTrqLim_f32 +
          VAR_TpcCod_GenTrqLim_f32) / (CAL_TpcCod_PosSpdStart_f32 -
          CAL_TpcCod_PosSpdHold_f32) * ((float64)rtb_TmpSignalConversionAtRP_SWC
          + CAL_TpcCod_PosSpdStart_f32) + -(float64)VAR_TpcCod_GenTrqLim_f32);

        /* End of Outputs for SubSystem: '<S25>/fun' */
      }
    } else {
      /* SignalConversion generated from: '<S18>/tpccod_TrqMaxCod' incorporates:
       *  Chart: '<S18>/Chart'
       */
      rtb_Switch_iq = -VAR_TpcCod_GenTrqLim_f32;
    }

    /* Gain: '<S18>/Gain' */
    rtb_TmpSignalConversionAtRP_SWC = -VAR_TpcCod_ElecTrqLim_f32;

    /* End of Outputs for SubSystem: '<S8>/If Action Subsystem1' */
  }

  /* End of If: '<S8>/If' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_TPC_10ms' */

  /* Inport: '<Root>/RP_SWC_CSPF_CSPF_RecTrqMin' */
  Rte_Read_RP_SWC_CSPF_CSPF_RecTrqMin(&VAR_TpcSmp_TrqMinCanSet_f32);

  /* Inport: '<Root>/RP_SWC_CSPF_CSPF_RecTrqMax' */
  Rte_Read_RP_SWC_CSPF_CSPF_RecTrqMax(&VAR_TpcSmp_TrqMaxCanSet_f32);

  /* Inport: '<Root>/RP_SWC_CSPF_CSPF_RecTrqMinNCtL' */
  Rte_Read_RP_SWC_CSPF_CSPF_RecTrqMinNCtL(&rtb_Add_m3);

  /* Inport: '<Root>/RP_SWC_CSPF_CSPF_RecTrqMaxNCtL' */
  Rte_Read_RP_SWC_CSPF_CSPF_RecTrqMaxNCtL(&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_TPC_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_TPC_10ms_sys'
   */
  /* SignalConversion generated from: '<S1>/RP_SWC_VCF_VCF_stModeReq_read' incorporates:
   *  Inport: '<Root>/RP_SWC_VCF_VCF_stModeReq'
   */
  Rte_Read_RP_SWC_VCF_VCF_stModeReq(&rtb_TmpSignalConversionAtRP_S_e);

  /* Switch: '<S144>/Switch' incorporates:
   *  Constant: '<S192>/Constant'
   *  Constant: '<S193>/Constant'
   *  Inport: '<Root>/RP_SWC_CSPF_CSPF_RecTrqMax'
   *  Inport: '<Root>/RP_SWC_CSPF_CSPF_RecTrqMin'
   *  Logic: '<S144>/Logical Operator'
   *  RelationalOperator: '<S192>/Compare'
   *  RelationalOperator: '<S193>/Compare'
   *  Switch: '<S144>/Switch1'
   */
  if ((rtb_TmpSignalConversionAtRP_S_e == CAL_TpcSmp_nCtlExtReq_u8) ||
      (rtb_TmpSignalConversionAtRP_S_e == CAL_TpcSmp_nCtlIntReq_u8)) {
    VAR_TpcSmp_TrqMaxCanSet_f32 = tmpRead;
    VAR_TpcSmp_TrqMinCanSet_f32 = rtb_Add_m3;
  }

  /* End of Switch: '<S144>/Switch' */

  /* Switch: '<S8>/Switch1' incorporates:
   *  RelationalOperator: '<S8>/Relational Operator2'
   */
  if (rtb_Switch_iq <= VAR_TpcSmp_TrqMaxCanSet_f32) {
    VAR_tpcsmp_negOutputjudge_f32 = rtb_Switch_iq;
  } else {
    VAR_tpcsmp_negOutputjudge_f32 = VAR_TpcSmp_TrqMaxCanSet_f32;
  }

  /* End of Switch: '<S8>/Switch1' */

  /* Switch: '<S105>/Switch' incorporates:
   *  Constant: '<S105>/CAL_TpcBlk_MtrBlkSpdHighSet_f32'
   *  Constant: '<S105>/CAL_TpcBlk_MtrBlkSpdLowSet_f32'
   *  Constant: '<S105>/Constant'
   *  RelationalOperator: '<S105>/Relational Operator'
   *  RelationalOperator: '<S105>/Relational Operator1'
   *  UnitDelay: '<S105>/Unit Delay'
   */
  if (rtb_Product_g <= CAL_TpcBlk_MtrBlkSpdLowSet_f32) {
    SWC_TPC_DW.UnitDelay_DSTATE_m = true;
  } else {
    SWC_TPC_DW.UnitDelay_DSTATE_m = ((rtb_Product_g <
      CAL_TpcBlk_MtrBlkSpdHighSet_f32) && SWC_TPC_DW.UnitDelay_DSTATE_m);
  }

  /* End of Switch: '<S105>/Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_TPC_10ms' */

  /* Inport: '<Root>/RP_SWC_MCF_MCF_Is' */
  Rte_Read_RP_SWC_MCF_MCF_Is(&tmpRead_0);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_TPC_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_TPC_10ms_sys'
   */
  /* Product: '<S105>/Divide' incorporates:
   *  Constant: '<S105>/Constant2'
   */
  VAR_TpcBlk_IsValid_f32 = tmpRead_0 / 1.414F;

  /* Product: '<S105>/Product' incorporates:
   *  Constant: '<S105>/CAL_TpcBlk_BlkTimSet_u16'
   *  Constant: '<S105>/CAL_TpcBlk_MtrBlkIsFirstSet_f32'
   */
  rtb_Product_g = CAL_TpcBlk_MtrBlkIsFirstSet_f32 * (float32)
    CAL_TpcBlk_BlkTimSet_u16;

  /* Chart: '<S105>/Chart' incorporates:
   *  UnitDelay: '<S105>/Unit Delay'
   */
  if (SWC_TPC_DW.UnitDelay_DSTATE_m) {
    if (VAR_TpcBlk_IsValid_f32 > CAL_TpcBlk_MtrBlkIsFirstSet_f32) {
      SWC_TPC_DW.Is_Sum += VAR_TpcBlk_IsValid_f32;
    } else {
      if (VAR_TpcBlk_IsValid_f32 < CAL_TpcBlk_MtrBlkIsSecondSet_f32) {
        SWC_TPC_DW.Is_Sum -= VAR_TpcBlk_IsValid_f32;
      }
    }
  } else {
    SWC_TPC_DW.Is_Sum -= VAR_TpcBlk_IsValid_f32;
  }

  if (SWC_TPC_DW.Is_Sum < 0.0F) {
    SWC_TPC_DW.Is_Sum = 0.0F;
  }

  if (SWC_TPC_DW.Is_Sum > rtb_Product_g) {
    SWC_TPC_DW.Is_Sum = (float32)(rtb_Product_g + 1.0);
  }

  VAR_TpcBlk_IsSum_f32 = SWC_TPC_DW.Is_Sum;

  /* End of Chart: '<S105>/Chart' */

  /* Switch: '<S105>/Switch2' incorporates:
   *  RelationalOperator: '<S105>/Relational Operator2'
   *  UnitDelay: '<S105>/Unit Delay3'
   */
  if (VAR_TpcBlk_IsSum_f32 >= rtb_Product_g) {
    /* Sum: '<S105>/Add1' incorporates:
     *  Constant: '<S105>/CAL_TpcBlk_TrqDecRamp_f32'
     *  UnitDelay: '<S105>/Unit Delay2'
     */
    VAR_Tpcblk_TrqLim_f32 = SWC_TPC_DW.UnitDelay2_DSTATE_al -
      CAL_TpcBlk_TrqDecRamp_f32;

    /* Switch: '<S105>/Switch5' incorporates:
     *  Constant: '<S105>/CAL_TpcBlk_TrqBlkStab_f32'
     *  RelationalOperator: '<S105>/Relational Operator4'
     */
    if (VAR_Tpcblk_TrqLim_f32 <= CAL_TpcBlk_TrqBlkStab_f32) {
      VAR_Tpcblk_TrqLim_f32 = CAL_TpcBlk_TrqBlkStab_f32;
    }

    /* End of Switch: '<S105>/Switch5' */
  } else {
    VAR_Tpcblk_TrqLim_f32 = SWC_TPC_DW.UnitDelay3_DSTATE;
  }

  /* End of Switch: '<S105>/Switch2' */

  /* Switch: '<S105>/Switch6' incorporates:
   *  Constant: '<S105>/CAL_TpcBlk_BlkRevTimSet_u16'
   *  Constant: '<S105>/CAL_TpcBlk_MtrBlkIsSecondSet_f32'
   *  Product: '<S105>/Product2'
   *  RelationalOperator: '<S105>/Relational Operator5'
   */
  if (VAR_TpcBlk_IsSum_f32 <= CAL_TpcBlk_MtrBlkIsSecondSet_f32 * (float32)
      CAL_TpcBlk_BlkRevTimSet_u16) {
    /* Sum: '<S105>/Add' incorporates:
     *  Constant: '<S105>/CAL_TpcBlk_TrqIncRamp_f32'
     *  UnitDelay: '<S105>/Unit Delay3'
     */
    VAR_Tpcblk_TrqLim01_f32 = CAL_TpcBlk_TrqIncRamp_f32 +
      SWC_TPC_DW.UnitDelay3_DSTATE;

    /* Switch: '<S105>/Switch3' incorporates:
     *  Constant: '<S105>/GLB_Tpc_MaximumTorque_f1'
     *  RelationalOperator: '<S105>/Relational Operator3'
     */
    if (VAR_Tpcblk_TrqLim01_f32 >= GLB_Tpc_MaximumTorque_f32) {
      VAR_Tpcblk_TrqLim01_f32 = GLB_Tpc_MaximumTorque_f32;
    }

    /* End of Switch: '<S105>/Switch3' */
  } else {
    VAR_Tpcblk_TrqLim01_f32 = VAR_Tpcblk_TrqLim_f32;
  }

  /* End of Switch: '<S105>/Switch6' */

  /* Switch: '<S105>/Switch4' incorporates:
   *  Constant: '<S105>/CAL_TpcBlk_flgEnBlkFun_b'
   *  Constant: '<S105>/GLB_Tpc_MaximumTorque_f32'
   */
  if (CAL_TpcBlk_flgEnBlkFun_b) {
    VAR_Tpcblk_TrqMax_f32 = VAR_Tpcblk_TrqLim01_f32;
  } else {
    VAR_Tpcblk_TrqMax_f32 = GLB_Tpc_MaximumTorque_f32;
  }

  /* End of Switch: '<S105>/Switch4' */

  /* Switch: '<S8>/Switch2' incorporates:
   *  RelationalOperator: '<S8>/Relational Operator3'
   */
  if (rtb_TmpSignalConversionAtRP_SWC >= VAR_TpcSmp_TrqMinCanSet_f32) {
    rtb_Add = rtb_TmpSignalConversionAtRP_SWC;
  } else {
    rtb_Add = VAR_TpcSmp_TrqMinCanSet_f32;
  }

  /* End of Switch: '<S8>/Switch2' */

  /* Product: '<S105>/Product1' */
  VAR_Tpcblk_TrqMin_f32 = -VAR_Tpcblk_TrqMax_f32;

  /* Switch: '<S8>/Switch4' incorporates:
   *  RelationalOperator: '<S8>/Relational Operator4'
   */
  if (VAR_tpcsmp_negOutputjudge_f32 > VAR_Tpcblk_TrqMax_f32) {
    VAR_tpcsmp_negOutputjudge_f32 = VAR_Tpcblk_TrqMax_f32;
  }

  /* End of Switch: '<S8>/Switch4' */

  /* Switch: '<S21>/Switch2' incorporates:
   *  Constant: '<S21>/Constant'
   *  Constant: '<S21>/Constant5'
   *  Logic: '<S19>/Logical Operator'
   *  RelationalOperator: '<S21>/Relational Operator'
   *  RelationalOperator: '<S21>/Relational Operator5'
   *  Sum: '<S21>/Add2'
   *  Switch: '<S21>/Switch'
   *  Switch: '<S21>/Switch6'
   *  UnitDelay: '<S19>/Unit Delay'
   *  UnitDelay: '<S21>/Unit Delay'
   */
  if (!SWC_TPC_DW.UnitDelay_DSTATE_in) {
    SWC_TPC_DW.UnitDelay_DSTATE_hx = VAR_tpcsmp_negOutputjudge_f32;
  } else {
    if (VAR_tpcsmp_negOutputjudge_f32 >= 0.0F) {
      /* Switch: '<S21>/Switch5' incorporates:
       *  Constant: '<S21>/Constant4'
       *  Gain: '<S21>/Gain1'
       *  RelationalOperator: '<S21>/Relational Operator4'
       *  Switch: '<S21>/Switch'
       *  UnitDelay: '<S21>/Unit Delay'
       */
      if (SWC_TPC_DW.UnitDelay_DSTATE_hx >= 0.0F) {
        /* Sum: '<S21>/Add' */
        rtb_Product_g = VAR_tpcsmp_negOutputjudge_f32 -
          SWC_TPC_DW.UnitDelay_DSTATE_hx;

        /* Switch: '<S21>/Switch3' incorporates:
         *  Constant: '<S21>/CAL_Tpc_TrqRevStep_f32'
         *  RelationalOperator: '<S21>/Relational Operator2'
         */
        if (rtb_Product_g > CAL_Tpc_TrqRevStep_f32) {
          rtb_Product_g = CAL_Tpc_TrqRevStep_f32;
        }

        /* End of Switch: '<S21>/Switch3' */
      } else {
        rtb_Product_g = -SWC_TPC_DW.UnitDelay_DSTATE_hx;
      }

      /* End of Switch: '<S21>/Switch5' */
    } else if (SWC_TPC_DW.UnitDelay_DSTATE_hx > 0.0F) {
      /* Switch: '<S21>/Switch' incorporates:
       *  Gain: '<S21>/Gain1'
       *  Switch: '<S21>/Switch6'
       *  UnitDelay: '<S21>/Unit Delay'
       */
      rtb_Product_g = -SWC_TPC_DW.UnitDelay_DSTATE_hx;
    } else {
      /* Sum: '<S21>/Add1' incorporates:
       *  Switch: '<S21>/Switch'
       *  Switch: '<S21>/Switch6'
       *  UnitDelay: '<S21>/Unit Delay'
       */
      rtb_Product_g = VAR_tpcsmp_negOutputjudge_f32 -
        SWC_TPC_DW.UnitDelay_DSTATE_hx;

      /* Switch: '<S21>/Switch1' incorporates:
       *  Constant: '<S21>/CAL_Tpc_TrqRevStep_f321'
       *  Gain: '<S21>/Gain'
       *  RelationalOperator: '<S21>/Relational Operator1'
       *  Switch: '<S21>/Switch'
       *  Switch: '<S21>/Switch6'
       */
      if (rtb_Product_g <= -CAL_Tpc_TrqRevStep_f32) {
        rtb_Product_g = -CAL_Tpc_TrqRevStep_f32;
      }

      /* End of Switch: '<S21>/Switch1' */
    }

    SWC_TPC_DW.UnitDelay_DSTATE_hx += rtb_Product_g;
  }

  /* End of Switch: '<S21>/Switch2' */

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/CAL_TpcCod_FlgUseTrqLimRampSet_b'
   *  UnitDelay: '<S21>/Unit Delay'
   */
  if (CAL_TpcCod_FlgUseTrqLimRampSet_b) {
    rtb_Product_g = SWC_TPC_DW.UnitDelay_DSTATE_hx;
  } else {
    rtb_Product_g = VAR_tpcsmp_negOutputjudge_f32;
  }

  /* End of Switch: '<S8>/Switch' */

  /* Switch: '<S8>/Switch5' incorporates:
   *  RelationalOperator: '<S8>/Relational Operator5'
   */
  if (rtb_Add < VAR_Tpcblk_TrqMin_f32) {
    rtb_Add = VAR_Tpcblk_TrqMin_f32;
  }

  /* End of Switch: '<S8>/Switch5' */

  /* Switch: '<S22>/Switch2' incorporates:
   *  Constant: '<S22>/Constant'
   *  Constant: '<S22>/Constant5'
   *  Logic: '<S20>/Logical Operator'
   *  RelationalOperator: '<S22>/Relational Operator'
   *  RelationalOperator: '<S22>/Relational Operator5'
   *  Sum: '<S22>/Add2'
   *  Switch: '<S22>/Switch'
   *  Switch: '<S22>/Switch6'
   *  UnitDelay: '<S20>/Unit Delay'
   *  UnitDelay: '<S22>/Unit Delay'
   */
  if (!SWC_TPC_DW.UnitDelay_DSTATE_kxy) {
    SWC_TPC_DW.UnitDelay_DSTATE_gh = rtb_Add;
  } else {
    if (rtb_Add >= 0.0F) {
      /* Switch: '<S22>/Switch5' incorporates:
       *  Constant: '<S22>/Constant4'
       *  Gain: '<S22>/Gain1'
       *  RelationalOperator: '<S22>/Relational Operator4'
       *  Switch: '<S22>/Switch'
       *  UnitDelay: '<S22>/Unit Delay'
       */
      if (SWC_TPC_DW.UnitDelay_DSTATE_gh >= 0.0F) {
        /* Sum: '<S22>/Add' */
        rtb_Add_m3 = rtb_Add - SWC_TPC_DW.UnitDelay_DSTATE_gh;

        /* Switch: '<S22>/Switch3' incorporates:
         *  Constant: '<S22>/CAL_Tpc_TrqRevStep_f32'
         *  RelationalOperator: '<S22>/Relational Operator2'
         */
        if (rtb_Add_m3 > CAL_Tpc_TrqRevStep_f32) {
          rtb_Add_m3 = CAL_Tpc_TrqRevStep_f32;
        }

        /* End of Switch: '<S22>/Switch3' */
      } else {
        rtb_Add_m3 = -SWC_TPC_DW.UnitDelay_DSTATE_gh;
      }

      /* End of Switch: '<S22>/Switch5' */
    } else if (SWC_TPC_DW.UnitDelay_DSTATE_gh > 0.0F) {
      /* Switch: '<S22>/Switch' incorporates:
       *  Gain: '<S22>/Gain1'
       *  Switch: '<S22>/Switch6'
       *  UnitDelay: '<S22>/Unit Delay'
       */
      rtb_Add_m3 = -SWC_TPC_DW.UnitDelay_DSTATE_gh;
    } else {
      /* Sum: '<S22>/Add1' incorporates:
       *  Switch: '<S22>/Switch'
       *  Switch: '<S22>/Switch6'
       *  UnitDelay: '<S22>/Unit Delay'
       */
      rtb_Add_m3 = rtb_Add - SWC_TPC_DW.UnitDelay_DSTATE_gh;

      /* Switch: '<S22>/Switch1' incorporates:
       *  Constant: '<S22>/CAL_Tpc_TrqRevStep_f321'
       *  Gain: '<S22>/Gain'
       *  RelationalOperator: '<S22>/Relational Operator1'
       *  Switch: '<S22>/Switch'
       *  Switch: '<S22>/Switch6'
       */
      if (rtb_Add_m3 <= -CAL_Tpc_TrqRevStep_f32) {
        rtb_Add_m3 = -CAL_Tpc_TrqRevStep_f32;
      }

      /* End of Switch: '<S22>/Switch1' */
    }

    SWC_TPC_DW.UnitDelay_DSTATE_gh += rtb_Add_m3;
  }

  /* End of Switch: '<S22>/Switch2' */

  /* Switch: '<S8>/Switch3' incorporates:
   *  Constant: '<S8>/CAL_TpcCod_FlgUseTrqLimRampSet_b'
   *  UnitDelay: '<S22>/Unit Delay'
   */
  if (CAL_TpcCod_FlgUseTrqLimRampSet_b) {
    rtb_Add = SWC_TPC_DW.UnitDelay_DSTATE_gh;
  }

  /* End of Switch: '<S8>/Switch3' */

  /* Switch: '<S27>/Switch' incorporates:
   *  Constant: '<S27>/GLB_TpcCod_FwELect_u8'
   *  Constant: '<S27>/GLB_TpcCod_FwGene_u8'
   *  Logic: '<S27>/Logical Operator32'
   *  RelationalOperator: '<S27>/Relational Operator38'
   *  RelationalOperator: '<S27>/Relational Operator39'
   *  Switch: '<S27>/Switch1'
   */
  if ((tpccod_stMotorMod == ((uint8)GLB_TpcCod_FwELect_u8)) ||
      (tpccod_stMotorMod == ((uint8)GLB_TpcCod_FwGene_u8))) {
    /* Outport: '<Root>/PP_SWC_TPC_TPC_bDernExcMax' incorporates:
     *  RelationalOperator: '<S27>/Relational Operator1'
     */
    (void) Rte_Write_PP_SWC_TPC_TPC_bDernExcMax(rtb_TmpSignalConversionAtRP_S_n >=
      VAR_TpcMot_TrqElecExC_f32);

    /* Outport: '<Root>/PP_SWC_TPC_TPC_bDernExcMin' incorporates:
     *  RelationalOperator: '<S27>/Relational Operator2'
     */
    (void) Rte_Write_PP_SWC_TPC_TPC_bDernExcMin(rtb_TmpSignalConversionAtRP_S_n <=
      VAR_TpcMot_TrqGenExC_f32);
  } else {
    /* Outport: '<Root>/PP_SWC_TPC_TPC_bDernExcMax' incorporates:
     *  Abs: '<S27>/Abs'
     *  RelationalOperator: '<S27>/Relational Operator5'
     */
    (void) Rte_Write_PP_SWC_TPC_TPC_bDernExcMax(rtb_TmpSignalConversionAtRP_S_n >=
      fabsf(VAR_TpcMot_TrqGenExC_f32));

    /* Outport: '<Root>/PP_SWC_TPC_TPC_bDernExcMin' incorporates:
     *  Product: '<S27>/Product'
     *  RelationalOperator: '<S27>/Relational Operator6'
     */
    (void) Rte_Write_PP_SWC_TPC_TPC_bDernExcMin(rtb_TmpSignalConversionAtRP_S_n <=
      -(float64)VAR_TpcMot_TrqElecExC_f32);
  }

  /* End of Switch: '<S27>/Switch' */

  /* Outport: '<Root>/PP_SWC_TPC_TPC_bDernStrTemp' incorporates:
   *  RelationalOperator: '<S28>/Compare'
   */
  (void) Rte_Write_PP_SWC_TPC_TPC_bDernStrTemp(VAR_TpcMot_flgTrqLimTsttrActv_b);

  /* Outport: '<Root>/PP_SWC_TPC_TPC_bDernDbcTemp' incorporates:
   *  RelationalOperator: '<S29>/Compare'
   */
  (void) Rte_Write_PP_SWC_TPC_TPC_bDernDbcTemp(VAR_TpcTmp_flgTrqLimTdbcActv_b);

  /* Outport: '<Root>/PP_SWC_TPC_TPC_bDernCoolantTemp' incorporates:
   *  RelationalOperator: '<S30>/Compare'
   */
  (void) Rte_Write_PP_SWC_TPC_TPC_bDernCoolantTemp
    (VAR_TpcTmp_flgTrqLimTcoolantActv_b);

  /* Outport: '<Root>/PP_SWC_TPC_TPC_bDernDrvBoardTemp' incorporates:
   *  RelationalOperator: '<S31>/Compare'
   */
  (void) Rte_Write_PP_SWC_TPC_TPC_bDernDrvBoardTemp
    (VAR_TpcTmp_flgTrqLimTdrvboardActv_b);

  /* Outport: '<Root>/PP_SWC_TPC_TPC_bDernIGBTTemp' incorporates:
   *  RelationalOperator: '<S32>/Compare'
   */
  (void) Rte_Write_PP_SWC_TPC_TPC_bDernIGBTTemp(VAR_TpcTmp_flgTrqLimTIGBTActv_b);

  /* RelationalOperator: '<S185>/Relational Operator5' incorporates:
   *  Constant: '<S185>/Coefficient1.0'
   *  Constant: '<S185>/ZeroValue'
   *  Sum: '<S185>/Add'
   */
  VAR_TpcSmp_flgElecTrqLimOvrSpdActv_b = (1.0F - rtb_Switch4_d > 1.0E-6F);

  /* RelationalOperator: '<S185>/Relational Operator7' incorporates:
   *  Constant: '<S185>/Coefficient1.1'
   *  Constant: '<S185>/ZeroValue1'
   *  Sum: '<S185>/Add1'
   */
  VAR_TpcSmp_flgGenTrqLimOvrSpdActv_b = (1.0F - rtb_Switch_ba > 1.0E-6F);

  /* Outport: '<Root>/PP_SWC_TPC_TPC_bDernMtrSpd' incorporates:
   *  Logic: '<S27>/Logical Operator'
   */
  (void) Rte_Write_PP_SWC_TPC_TPC_bDernMtrSpd
    (VAR_TpcSmp_flgElecTrqLimOvrSpdActv_b || VAR_TpcSmp_flgGenTrqLimOvrSpdActv_b);

  /* RelationalOperator: '<S27>/Relational Operator' incorporates:
   *  Constant: '<S27>/GLB_TpcCod_MotorStop_u8'
   */
  rtb_RelationalOperator1_cn = (tpccod_SgnRotDir != ((uint8)
    GLB_TpcCod_MotorStop_u8));

  /* Outport: '<Root>/PP_SWC_TPC_TPC_bDernUndrUdc' incorporates:
   *  Logic: '<S27>/Logical Operator1'
   */
  (void) Rte_Write_PP_SWC_TPC_TPC_bDernUndrUdc(rtb_RelationalOperator1_cn &&
    VAR_TpcSmp_flgElecPwrLimUdrVoltActv_b);

  /* Logic: '<S27>/Logical Operator2' */
  rtb_FIM_PwrLimLvFour = (rtb_RelationalOperator1_cn &&
    VAR_TpcSmp_flgGenPwrLimCurtActv_b);

  /* Logic: '<S27>/Logical Operator3' */
  rtb_FIM_PwrLimLvThree = (rtb_RelationalOperator1_cn &&
    VAR_TpcSmp_flgElecPwrLimOvrCurtActv_b);

  /* Outport: '<Root>/PP_SWC_TPC_TPC_bDernOvrUdc' incorporates:
   *  Logic: '<S27>/Logical Operator4'
   */
  (void) Rte_Write_PP_SWC_TPC_TPC_bDernOvrUdc(rtb_RelationalOperator1_cn &&
    VAR_TpcSmp_flgGenPwrLimOvrVoltActv_b);

  /* Outport: '<Root>/PP_SWC_TPC_TPC_bDernOvrIdc' incorporates:
   *  Logic: '<S27>/Logical Operator6'
   */
  (void) Rte_Write_PP_SWC_TPC_TPC_bDernOvrIdc(rtb_FIM_PwrLimLvThree ||
    rtb_FIM_PwrLimLvFour);

  /* Outport: '<Root>/PP_SWC_TPC_TPC_bDernCAN' incorporates:
   *  Logic: '<S27>/Logical Operator5'
   *  RelationalOperator: '<S27>/Relational Operator3'
   *  RelationalOperator: '<S27>/Relational Operator4'
   */
  (void) Rte_Write_PP_SWC_TPC_TPC_bDernCAN((rtb_Product_g ==
    VAR_TpcSmp_TrqMaxCanSet_f32) || (rtb_Add == VAR_TpcSmp_TrqMinCanSet_f32));

  /* Outport: '<Root>/PP_SWC_TPC_TPC_TDbcTrqMax' incorporates:
   *  Gain: '<S36>/Gain'
   */
  (void) Rte_Write_PP_SWC_TPC_TPC_TDbcTrqMax(VAR_TpcTmp_ElecTrqLimTdbc_f32);

  /* Logic: '<S54>/Logical Operator32' incorporates:
   *  Constant: '<S54>/GLB_TpcCod_FwELect_u8'
   *  Constant: '<S54>/GLB_TpcCod_FwGene_u8'
   *  RelationalOperator: '<S54>/Relational Operator38'
   *  RelationalOperator: '<S54>/Relational Operator39'
   */
  rtb_RelationalOperator1_cn = ((tpccod_stMotorMod == ((uint8)
    GLB_TpcCod_FwELect_u8)) || (tpccod_stMotorMod == ((uint8)
    GLB_TpcCod_FwGene_u8)));

  /* Switch: '<S56>/Switch' incorporates:
   *  Abs: '<S100>/Abs'
   *  Abs: '<S101>/Abs'
   *  Abs: '<S102>/Abs'
   *  Abs: '<S103>/Abs'
   *  Abs: '<S57>/Abs6'
   *  Abs: '<S58>/Abs5'
   *  Abs: '<S59>/Abs7'
   *  Abs: '<S60>/Abs3'
   *  Abs: '<S61>/Abs2'
   *  Abs: '<S62>/Abs4'
   *  Abs: '<S63>/Abs4'
   *  Abs: '<S64>/Abs1'
   *  Abs: '<S68>/Abs'
   *  Abs: '<S69>/Abs'
   *  Abs: '<S70>/Abs'
   *  Abs: '<S72>/Abs'
   *  Abs: '<S73>/Abs'
   *  Abs: '<S74>/Abs'
   *  Abs: '<S75>/Abs'
   *  Abs: '<S76>/Abs'
   *  Abs: '<S77>/Abs'
   *  Abs: '<S78>/Abs'
   *  Abs: '<S79>/Abs'
   *  Abs: '<S80>/Abs'
   *  Abs: '<S81>/Abs'
   *  Abs: '<S82>/Abs'
   *  Abs: '<S83>/Abs'
   *  Abs: '<S84>/Abs'
   *  Abs: '<S85>/Abs'
   *  Abs: '<S86>/Abs'
   *  Abs: '<S87>/Abs'
   *  Abs: '<S88>/Abs'
   *  Abs: '<S89>/Abs'
   *  Abs: '<S90>/Abs'
   *  Abs: '<S91>/Abs'
   *  Abs: '<S92>/Abs'
   *  Abs: '<S93>/Abs'
   *  Abs: '<S94>/Abs'
   *  Abs: '<S95>/Abs'
   *  Abs: '<S96>/Abs'
   *  Abs: '<S97>/Abs'
   *  Abs: '<S98>/Abs'
   *  Abs: '<S99>/Abs'
   *  Constant: '<S100>/Constant'
   *  Constant: '<S101>/Constant'
   *  Constant: '<S102>/Constant'
   *  Constant: '<S103>/Constant'
   *  Constant: '<S59>/Constant1'
   *  Constant: '<S59>/Constant10'
   *  Constant: '<S65>/Constant'
   *  Constant: '<S65>/Constant9'
   *  Constant: '<S68>/Constant'
   *  Constant: '<S69>/Constant'
   *  Constant: '<S70>/Constant'
   *  Constant: '<S71>/Constant'
   *  Constant: '<S72>/Constant'
   *  Constant: '<S73>/Constant'
   *  Constant: '<S74>/Constant'
   *  Constant: '<S75>/Constant'
   *  Constant: '<S76>/Constant'
   *  Constant: '<S77>/Constant'
   *  Constant: '<S78>/Constant'
   *  Constant: '<S79>/Constant'
   *  Constant: '<S80>/Constant'
   *  Constant: '<S81>/Constant'
   *  Constant: '<S82>/Constant'
   *  Constant: '<S83>/Constant'
   *  Constant: '<S84>/Constant'
   *  Constant: '<S85>/Constant'
   *  Constant: '<S86>/Constant'
   *  Constant: '<S87>/Constant'
   *  Constant: '<S88>/Constant'
   *  Constant: '<S89>/Constant'
   *  Constant: '<S90>/Constant'
   *  Constant: '<S91>/Constant'
   *  Constant: '<S92>/Constant'
   *  Constant: '<S93>/Constant'
   *  Constant: '<S94>/Constant'
   *  Constant: '<S95>/Constant'
   *  Constant: '<S96>/Constant'
   *  Constant: '<S97>/Constant'
   *  Constant: '<S98>/Constant'
   *  Constant: '<S99>/Constant'
   *  Logic: '<S56>/Logical Operator'
   *  Logic: '<S56>/Logical Operator16'
   *  Logic: '<S56>/Logical Operator17'
   *  Logic: '<S56>/Logical Operator2'
   *  Logic: '<S57>/Logical Operator12'
   *  Logic: '<S57>/Logical Operator13'
   *  Logic: '<S57>/Logical Operator28'
   *  Logic: '<S57>/Logical Operator29'
   *  Logic: '<S58>/Logical Operator10'
   *  Logic: '<S58>/Logical Operator11'
   *  Logic: '<S58>/Logical Operator26'
   *  Logic: '<S58>/Logical Operator27'
   *  Logic: '<S59>/Logical Operator15'
   *  Logic: '<S59>/Logical Operator31'
   *  Logic: '<S60>/Logical Operator22'
   *  Logic: '<S60>/Logical Operator23'
   *  Logic: '<S60>/Logical Operator6'
   *  Logic: '<S60>/Logical Operator7'
   *  Logic: '<S61>/Logical Operator20'
   *  Logic: '<S61>/Logical Operator21'
   *  Logic: '<S61>/Logical Operator4'
   *  Logic: '<S61>/Logical Operator5'
   *  Logic: '<S62>/Logical Operator24'
   *  Logic: '<S62>/Logical Operator25'
   *  Logic: '<S62>/Logical Operator8'
   *  Logic: '<S62>/Logical Operator9'
   *  Logic: '<S63>/Logical Operator24'
   *  Logic: '<S63>/Logical Operator25'
   *  Logic: '<S63>/Logical Operator8'
   *  Logic: '<S63>/Logical Operator9'
   *  Logic: '<S64>/Logical Operator1'
   *  Logic: '<S64>/Logical Operator18'
   *  Logic: '<S64>/Logical Operator19'
   *  Logic: '<S64>/Logical Operator3'
   *  Logic: '<S65>/Logical Operator14'
   *  Logic: '<S65>/Logical Operator30'
   *  Product: '<S56>/Product'
   *  Product: '<S57>/Product6'
   *  Product: '<S58>/Product5'
   *  Product: '<S60>/Product3'
   *  Product: '<S61>/Product2'
   *  Product: '<S62>/Product4'
   *  Product: '<S63>/Product4'
   *  Product: '<S64>/Product1'
   *  Product: '<S65>/Product7'
   *  RelationalOperator: '<S100>/Relational Operator'
   *  RelationalOperator: '<S101>/Relational Operator'
   *  RelationalOperator: '<S102>/Relational Operator'
   *  RelationalOperator: '<S103>/Relational Operator'
   *  RelationalOperator: '<S56>/Relational Operator1'
   *  RelationalOperator: '<S56>/Relational Operator21'
   *  RelationalOperator: '<S56>/Relational Operator22'
   *  RelationalOperator: '<S68>/Relational Operator'
   *  RelationalOperator: '<S69>/Relational Operator'
   *  RelationalOperator: '<S70>/Relational Operator'
   *  RelationalOperator: '<S71>/Relational Operator'
   *  RelationalOperator: '<S72>/Relational Operator'
   *  RelationalOperator: '<S73>/Relational Operator'
   *  RelationalOperator: '<S74>/Relational Operator'
   *  RelationalOperator: '<S75>/Relational Operator'
   *  RelationalOperator: '<S76>/Relational Operator'
   *  RelationalOperator: '<S77>/Relational Operator'
   *  RelationalOperator: '<S78>/Relational Operator'
   *  RelationalOperator: '<S79>/Relational Operator'
   *  RelationalOperator: '<S80>/Relational Operator'
   *  RelationalOperator: '<S81>/Relational Operator'
   *  RelationalOperator: '<S82>/Relational Operator'
   *  RelationalOperator: '<S83>/Relational Operator'
   *  RelationalOperator: '<S84>/Relational Operator'
   *  RelationalOperator: '<S85>/Relational Operator'
   *  RelationalOperator: '<S86>/Relational Operator'
   *  RelationalOperator: '<S87>/Relational Operator'
   *  RelationalOperator: '<S88>/Relational Operator'
   *  RelationalOperator: '<S89>/Relational Operator'
   *  RelationalOperator: '<S90>/Relational Operator'
   *  RelationalOperator: '<S91>/Relational Operator'
   *  RelationalOperator: '<S92>/Relational Operator'
   *  RelationalOperator: '<S93>/Relational Operator'
   *  RelationalOperator: '<S94>/Relational Operator'
   *  RelationalOperator: '<S95>/Relational Operator'
   *  RelationalOperator: '<S96>/Relational Operator'
   *  RelationalOperator: '<S97>/Relational Operator'
   *  RelationalOperator: '<S98>/Relational Operator'
   *  RelationalOperator: '<S99>/Relational Operator'
   *  Sum: '<S100>/Add'
   *  Sum: '<S101>/Add'
   *  Sum: '<S102>/Add'
   *  Sum: '<S103>/Add'
   *  Sum: '<S68>/Add'
   *  Sum: '<S69>/Add'
   *  Sum: '<S70>/Add'
   *  Sum: '<S72>/Add'
   *  Sum: '<S73>/Add'
   *  Sum: '<S74>/Add'
   *  Sum: '<S75>/Add'
   *  Sum: '<S76>/Add'
   *  Sum: '<S77>/Add'
   *  Sum: '<S78>/Add'
   *  Sum: '<S79>/Add'
   *  Sum: '<S80>/Add'
   *  Sum: '<S81>/Add'
   *  Sum: '<S82>/Add'
   *  Sum: '<S83>/Add'
   *  Sum: '<S84>/Add'
   *  Sum: '<S85>/Add'
   *  Sum: '<S86>/Add'
   *  Sum: '<S87>/Add'
   *  Sum: '<S88>/Add'
   *  Sum: '<S89>/Add'
   *  Sum: '<S90>/Add'
   *  Sum: '<S91>/Add'
   *  Sum: '<S92>/Add'
   *  Sum: '<S93>/Add'
   *  Sum: '<S94>/Add'
   *  Sum: '<S95>/Add'
   *  Sum: '<S96>/Add'
   *  Sum: '<S97>/Add'
   *  Sum: '<S98>/Add'
   *  Sum: '<S99>/Add'
   *  Switch: '<S56>/Switch9'
   *  Switch: '<S57>/Switch15'
   *  Switch: '<S57>/Switch6'
   *  Switch: '<S58>/Switch14'
   *  Switch: '<S58>/Switch5'
   *  Switch: '<S59>/Switch17'
   *  Switch: '<S59>/Switch8'
   *  Switch: '<S60>/Switch12'
   *  Switch: '<S60>/Switch3'
   *  Switch: '<S61>/Switch11'
   *  Switch: '<S61>/Switch2'
   *  Switch: '<S62>/Switch13'
   *  Switch: '<S62>/Switch4'
   *  Switch: '<S63>/Switch13'
   *  Switch: '<S63>/Switch4'
   *  Switch: '<S64>/Switch1'
   *  Switch: '<S64>/Switch10'
   *  Switch: '<S65>/Switch16'
   *  Switch: '<S65>/Switch7'
   */
  if (rtb_RelationalOperator1_cn) {
    VAR_tpccod_flgMaxDertExCTrq_b = ((fabsf(rtb_Product_g -
      VAR_TpcMot_TrqElecExC_f32) <= 0.001F) && (rtb_TmpSignalConversionAtRP_S_n >
      VAR_TpcMot_TrqElecExC_f32));
    VAR_tpccod_flgMaxDertStrTemp_b = ((fabsf(VAR_TpcMot_ElecTrqLimTsttr_f32 -
      rtb_Product_g) <= 0.001F) && VAR_TpcMot_flgTrqLimTsttrActv_b);
    VAR_tpccod_flgMaxDertTempDBC_b = ((fabsf(VAR_TpcTmp_ElecTrqLimTdbc_f32 -
      rtb_Product_g) <= 0.001F) && VAR_TpcTmp_flgTrqLimTdbcActv_b);
    VAR_tpccod_flgMaxDertTCoolant_b = ((fabsf(VAR_TpcTmp_ElecTrqLimTcoolant_f32
      - rtb_Product_g) <= 0.001F) && VAR_TpcTmp_flgTrqLimTcoolantActv_b);
    VAR_tpccod_flgMaxDertTDrvBoard_b = ((fabsf
      (VAR_TpcTmp_ElecTrqLimTdrvboard_f32 - rtb_Product_g) <= 0.001F) &&
      VAR_TpcTmp_flgTrqLimTdrvboardActv_b);
    VAR_tpccod_flgMaxDertTIGBT_b = ((fabsf(VAR_TpcTmp_ElecTrqLimTIGBT_f32 -
      rtb_Product_g) <= 0.001F) && VAR_TpcTmp_flgTrqLimTIGBTActv_b);
    VAR_tpccod_flgMaxDertMtrSpd_b = ((fabsf(VAR_TpcSmp_ElecTrqLimOvrSpd_f32 -
      rtb_Product_g) <= 0.001F) && VAR_TpcSmp_flgElecTrqLimOvrSpdActv_b);
    VAR_tpccod_flgMaxDertOvrIdc_b = ((fabsf(VAR_TpcCod_ElecTrqCalcOvrCurt_f32 -
      rtb_Product_g) <= 0.001F) && VAR_TpcSmp_flgElecPwrLimOvrCurtActv_b);
    VAR_tpccod_flgMaxDertUndrUdc_b = ((fabsf(VAR_TpcCod_ElecTrqCalcUdrVolt_f32 -
      rtb_Product_g) <= 0.001F) && VAR_TpcSmp_flgElecPwrLimUdrVoltActv_b);
    VAR_tpccod_flgMaxDertOvrUdc_b = false;
    VAR_tpccod_flgMinDertExCTrq_b = ((fabsf(rtb_Add - VAR_TpcMot_TrqGenExC_f32) <=
      0.001F) && (rtb_TmpSignalConversionAtRP_S_n < VAR_TpcMot_TrqGenExC_f32));
    VAR_tpccod_flgMinDertStrTemp_b = ((fabsf(VAR_TpcMot_GenTrqLimTsttr_f32 -
      rtb_Add) <= 0.001F) && VAR_TpcMot_flgTrqLimTsttrActv_b);
    VAR_tpccod_flgMinDertTempDBC_b = ((fabsf(VAR_TpcTmp_GenTrqLimTdbc_f32 -
      rtb_Add) <= 0.001F) && VAR_TpcTmp_flgTrqLimTdbcActv_b);
    VAR_tpccod_flgMinDertTCoolant_b = ((fabsf(VAR_TpcTmp_GenTrqLimTcoolant_f32 -
      rtb_Add) <= 0.001F) && VAR_TpcTmp_flgTrqLimTcoolantActv_b);
    VAR_tpccod_flgMinDertTDrvBoard_b = ((fabsf(VAR_TpcTmp_GenTrqLimTdrvboard_f32
      - rtb_Add) <= 0.001F) && VAR_TpcTmp_flgTrqLimTdrvboardActv_b);
    VAR_tpccod_flgMinDertTIGBT_b = ((fabsf(VAR_TpcTmp_GenTrqLimTIGBT_f32 -
      rtb_Add) <= 0.001F) && VAR_TpcTmp_flgTrqLimTIGBTActv_b);
    VAR_tpccod_flgMinDertMtrSpd_b = ((fabsf(VAR_TpcSmp_GenTrqLimOvrSpd_f32 -
      rtb_Add) <= 0.001F) && VAR_TpcSmp_flgGenTrqLimOvrSpdActv_b);
    VAR_tpccod_flgMinDertOvrIdc_b = ((fabsf(VAR_TpcCod_GenTrqCalcOvrCurt_f32 -
      rtb_Add) <= 0.001F) && VAR_TpcSmp_flgGenPwrLimCurtActv_b);
    VAR_tpccod_flgMinDertUndrUdc_b = false;
    VAR_tpccod_flgMinDertOvrUdc_b = ((fabsf(VAR_TpcCod_GenTrqCalcOvrVolt_f32 -
      rtb_Add) <= 0.001F) && VAR_TpcSmp_flgGenPwrLimOvrVoltActv_b);
  } else {
    /* Abs: '<S56>/Abs' */
    rtb_Add_m3 = fabsf(VAR_TpcMot_TrqGenExC_f32);

    /* RelationalOperator: '<S56>/Relational Operator3' */
    rtb_TmpSignalConversionAtRP_S_d = (rtb_TmpSignalConversionAtRP_S_n >
      rtb_Add_m3);

    /* Sum: '<S71>/Add' */
    rtb_Add_m3 -= rtb_Product_g;

    /* Abs: '<S71>/Abs' */
    rtb_Add_m3 = fabsf(rtb_Add_m3);
    VAR_tpccod_flgMaxDertExCTrq_b = ((rtb_Add_m3 <= 0.001F) &&
      rtb_TmpSignalConversionAtRP_S_d);
    VAR_tpccod_flgMaxDertStrTemp_b = (VAR_TpcMot_flgTrqLimTsttrActv_b && (fabsf
      (fabsf(VAR_TpcMot_GenTrqLimTsttr_f32) - rtb_Product_g) <= 0.001F));
    VAR_tpccod_flgMaxDertTempDBC_b = (VAR_TpcTmp_flgTrqLimTdbcActv_b && (fabsf
      (fabsf(VAR_TpcTmp_GenTrqLimTdbc_f32) - rtb_Product_g) <= 0.001F));
    VAR_tpccod_flgMaxDertTCoolant_b = (VAR_TpcTmp_flgTrqLimTcoolantActv_b &&
      (fabsf(fabsf(VAR_TpcTmp_GenTrqLimTcoolant_f32) - rtb_Product_g) <= 0.001F));
    VAR_tpccod_flgMaxDertTDrvBoard_b = (VAR_TpcTmp_flgTrqLimTdrvboardActv_b &&
      (fabsf(fabsf(VAR_TpcTmp_GenTrqLimTdrvboard_f32) - rtb_Product_g) <= 0.001F));
    VAR_tpccod_flgMaxDertTIGBT_b = (VAR_TpcTmp_flgTrqLimTIGBTActv_b && (fabsf
      (fabsf(VAR_TpcTmp_GenTrqLimTIGBT_f32) - rtb_Product_g) <= 0.001F));
    VAR_tpccod_flgMaxDertMtrSpd_b = ((fabsf(fabsf(VAR_TpcSmp_GenTrqLimOvrSpd_f32)
      - rtb_Product_g) <= 0.001F) && VAR_TpcSmp_flgGenTrqLimOvrSpdActv_b);
    VAR_tpccod_flgMaxDertOvrIdc_b = ((fabsf(fabsf
      (VAR_TpcCod_GenTrqCalcOvrCurt_f32) - rtb_Product_g) <= 0.001F) &&
      VAR_TpcSmp_flgGenPwrLimCurtActv_b);
    VAR_tpccod_flgMaxDertUndrUdc_b = false;
    VAR_tpccod_flgMaxDertOvrUdc_b = ((fabsf(fabsf
      (VAR_TpcCod_GenTrqCalcOvrVolt_f32) - rtb_Product_g) <= 0.001F) &&
      VAR_TpcSmp_flgGenPwrLimOvrVoltActv_b);
    VAR_tpccod_flgMinDertExCTrq_b = ((fabsf(rtb_Add -
      (-VAR_TpcMot_TrqElecExC_f32)) <= 0.001F) &&
      (rtb_TmpSignalConversionAtRP_S_n < -VAR_TpcMot_TrqElecExC_f32));
    VAR_tpccod_flgMinDertStrTemp_b = (VAR_TpcMot_flgTrqLimTsttrActv_b && (fabsf(
      -VAR_TpcMot_ElecTrqLimTsttr_f32 - rtb_Add) <= 0.001F));
    VAR_tpccod_flgMinDertTempDBC_b = (VAR_TpcTmp_flgTrqLimTdbcActv_b && (fabsf
      (-VAR_TpcTmp_ElecTrqLimTdbc_f32 - rtb_Add) <= 0.001F));
    VAR_tpccod_flgMinDertTCoolant_b = (VAR_TpcTmp_flgTrqLimTcoolantActv_b &&
      (fabsf(-VAR_TpcTmp_ElecTrqLimTcoolant_f32 - rtb_Add) <= 0.001F));
    VAR_tpccod_flgMinDertTDrvBoard_b = (VAR_TpcTmp_flgTrqLimTdrvboardActv_b &&
      (fabsf(-VAR_TpcTmp_ElecTrqLimTdrvboard_f32 - rtb_Add) <= 0.001F));
    VAR_tpccod_flgMinDertTIGBT_b = (VAR_TpcTmp_flgTrqLimTIGBTActv_b && (fabsf
      (-VAR_TpcTmp_ElecTrqLimTIGBT_f32 - rtb_Add) <= 0.001F));
    VAR_tpccod_flgMinDertMtrSpd_b = ((fabsf(-VAR_TpcSmp_ElecTrqLimOvrSpd_f32 -
      rtb_Add) <= 0.001F) && VAR_TpcSmp_flgElecTrqLimOvrSpdActv_b);
    VAR_tpccod_flgMinDertOvrIdc_b = ((fabsf(-VAR_TpcCod_ElecTrqCalcOvrCurt_f32 -
      rtb_Add) <= 0.001F) && VAR_TpcSmp_flgElecPwrLimOvrCurtActv_b);
    VAR_tpccod_flgMinDertUndrUdc_b = ((fabsf(-VAR_TpcCod_ElecTrqCalcUdrVolt_f32
      - rtb_Add) <= 0.001F) && VAR_TpcSmp_flgElecPwrLimUdrVoltActv_b);
    VAR_tpccod_flgMinDertOvrUdc_b = false;
  }

  /* End of Switch: '<S56>/Switch' */

  /* RelationalOperator: '<S66>/Relational Operator' incorporates:
   *  Abs: '<S66>/Abs'
   *  Constant: '<S66>/Constant'
   *  Sum: '<S66>/Add'
   */
  VAR_tpccod_flgMaxDertCAN_b = (fabsf(VAR_TpcSmp_TrqMaxCanSet_f32 -
    rtb_Product_g) <= 0.001F);

  /* RelationalOperator: '<S67>/Relational Operator' incorporates:
   *  Abs: '<S67>/Abs'
   *  Constant: '<S67>/Constant'
   *  Sum: '<S67>/Add'
   */
  VAR_tpccod_flgMinDertCAN_b = (fabsf(VAR_TpcSmp_TrqMinCanSet_f32 - rtb_Add) <=
    0.001F);

  /* Sum: '<S155>/Add5' incorporates:
   *  Gain: '<S155>/Gain5'
   */
  VAR_tpcsmp_negOutputjudge_f32 = -VAR_tpcsmp_RefPwrElecOvrCurt_f32 -
    VAR_tpcsmp_KpProductSau_f32;

  /* Switch: '<S155>/Switch2' incorporates:
   *  Constant: '<S155>/Constant1'
   *  Constant: '<S155>/yMax'
   *  RelationalOperator: '<S155>/Relational Operator3'
   *  Sum: '<S155>/Add4'
   */
  if (0.0F - VAR_tpcsmp_KpProductSau_f32 >= 0.0F) {
    VAR_tpcsmp_posOutputjudge_f32 = 0.0F - VAR_tpcsmp_KpProductSau_f32;
  } else {
    VAR_tpcsmp_posOutputjudge_f32 = 0.0F;
  }

  /* End of Switch: '<S155>/Switch2' */

  /* Switch: '<S155>/Switch3' incorporates:
   *  Constant: '<S155>/Constant2'
   *  RelationalOperator: '<S155>/Relational Operator4'
   */
  if (VAR_tpcsmp_negOutputjudge_f32 > 0.0F) {
    VAR_tpcsmp_negOutputjudge_f32 = 0.0F;
  }

  /* End of Switch: '<S155>/Switch3' */

  /* Switch: '<S155>/Switch' incorporates:
   *  Gain: '<S155>/Gain5'
   *  RelationalOperator: '<S155>/Relational Operator1'
   *  RelationalOperator: '<S155>/Relational Operator2'
   *  Switch: '<S155>/Switch1'
   */
  if (VAR_tpcsmp_PIOutput_f32 >= 0.0F) {
    VAR_tpcsmp_yi_f32 = VAR_tpcsmp_posOutputjudge_f32;
  } else if (VAR_tpcsmp_PIOutput_f32 <= -VAR_tpcsmp_RefPwrElecOvrCurt_f32) {
    /* Switch: '<S155>/Switch1' */
    VAR_tpcsmp_yi_f32 = VAR_tpcsmp_negOutputjudge_f32;
  } else {
    VAR_tpcsmp_yi_f32 = VAR_tpcsmp_KiProductSum_f32;
  }

  /* End of Switch: '<S155>/Switch' */

  /* Switch: '<S164>/Switch' incorporates:
   *  Gain: '<S164>/Gain7'
   *  RelationalOperator: '<S164>/Relational Operator1'
   *  RelationalOperator: '<S164>/Relational Operator2'
   *  Switch: '<S164>/Switch1'
   */
  if (rtb_TmpSignalConversionAtRP__k0 >= 0.0F) {
    /* Switch: '<S164>/Switch2' incorporates:
     *  Constant: '<S164>/Constant1 '
     *  Constant: '<S164>/yMax'
     *  RelationalOperator: '<S164>/Relational Operator3'
     *  Sum: '<S164>/Add4'
     *  UnitDelay: '<S164>/Unit Delay1'
     */
    if (0.0F - rtb_TmpSignalConversionAtRP__na >= 0.0F) {
      SWC_TPC_DW.UnitDelay1_DSTATE_b = 0.0F - rtb_TmpSignalConversionAtRP__na;
    } else {
      SWC_TPC_DW.UnitDelay1_DSTATE_b = 0.0F;
    }

    /* End of Switch: '<S164>/Switch2' */
  } else {
    if (rtb_TmpSignalConversionAtRP__k0 <= -VAR_tpcsmp_RefPwrGenOvrCurt_f32) {
      /* Sum: '<S164>/Add5' incorporates:
       *  Gain: '<S164>/Gain7'
       *  Switch: '<S164>/Switch1'
       */
      SWC_TPC_DW.UnitDelay1_DSTATE_b = -VAR_tpcsmp_RefPwrGenOvrCurt_f32 -
        rtb_TmpSignalConversionAtRP__na;

      /* Switch: '<S164>/Switch3' incorporates:
       *  RelationalOperator: '<S164>/Relational Operator4'
       *  Switch: '<S164>/Switch1'
       */
      if (SWC_TPC_DW.UnitDelay1_DSTATE_b > 0.0F) {
        /* UnitDelay: '<S164>/Unit Delay1' incorporates:
         *  Constant: '<S164>/Constant2'
         */
        SWC_TPC_DW.UnitDelay1_DSTATE_b = 0.0F;
      }

      /* End of Switch: '<S164>/Switch3' */
    }
  }

  /* End of Switch: '<S164>/Switch' */

  /* Switch: '<S174>/Switch' incorporates:
   *  Constant: '<S174>/Constant4'
   *  Gain: '<S174>/Gain1'
   *  RelationalOperator: '<S174>/Relational Operator1'
   *  RelationalOperator: '<S174>/Relational Operator2'
   *  Switch: '<S174>/Switch1'
   */
  if (rtb_DataTypeConversion1 >= -VAR_TpcMot_GenPwrRef_f32) {
    /* Sum: '<S174>/Add4' */
    SWC_TPC_DW.UnitDelay2_DSTATE_c = -VAR_TpcMot_GenPwrRef_f32 - rtb_Product1_o;

    /* Switch: '<S174>/Switch2' incorporates:
     *  Constant: '<S174>/Constant2'
     *  RelationalOperator: '<S174>/Relational Operator3'
     *  UnitDelay: '<S174>/Unit Delay2'
     */
    if (SWC_TPC_DW.UnitDelay2_DSTATE_c < 0.0F) {
      SWC_TPC_DW.UnitDelay2_DSTATE_c = 0.0F;
    }

    /* End of Switch: '<S174>/Switch2' */
  } else {
    if (rtb_DataTypeConversion1 <= 0.0F) {
      /* Switch: '<S174>/Switch3' incorporates:
       *  Constant: '<S174>/Constant4'
       *  RelationalOperator: '<S174>/Relational Operator4'
       *  Sum: '<S174>/Add5'
       *  Switch: '<S174>/Switch1'
       */
      if (0.0F - rtb_Product1_o <= 0.0F) {
        /* UnitDelay: '<S174>/Unit Delay2' */
        SWC_TPC_DW.UnitDelay2_DSTATE_c = 0.0F - rtb_Product1_o;
      } else {
        /* UnitDelay: '<S174>/Unit Delay2' incorporates:
         *  Constant: '<S174>/Constant3'
         */
        SWC_TPC_DW.UnitDelay2_DSTATE_c = 0.0F;
      }

      /* End of Switch: '<S174>/Switch3' */
    }
  }

  /* End of Switch: '<S174>/Switch' */

  /* Switch: '<S182>/Switch' incorporates:
   *  Constant: '<S182>/Constant4'
   *  RelationalOperator: '<S182>/Relational Operator1'
   *  RelationalOperator: '<S182>/Relational Operator2'
   *  Switch: '<S182>/Switch1'
   */
  if (rtb_Subtract_kw >= VAR_TpcMot_ElecPwrRef_f32) {
    /* Sum: '<S182>/Add4' */
    SWC_TPC_DW.UnitDelay2_DSTATE_g = VAR_TpcMot_ElecPwrRef_f32 - rtb_Subtract_gc;

    /* Switch: '<S182>/Switch2' incorporates:
     *  Constant: '<S182>/Constant2'
     *  RelationalOperator: '<S182>/Relational Operator3'
     *  UnitDelay: '<S182>/Unit Delay2'
     */
    if (SWC_TPC_DW.UnitDelay2_DSTATE_g < 0.0F) {
      SWC_TPC_DW.UnitDelay2_DSTATE_g = 0.0F;
    }

    /* End of Switch: '<S182>/Switch2' */
  } else {
    if (rtb_Subtract_kw <= 0.0F) {
      /* Switch: '<S182>/Switch3' incorporates:
       *  Constant: '<S182>/Constant4'
       *  RelationalOperator: '<S182>/Relational Operator4'
       *  Sum: '<S182>/Add5'
       *  Switch: '<S182>/Switch1'
       */
      if (0.0F - rtb_Subtract_gc <= 0.0F) {
        /* UnitDelay: '<S182>/Unit Delay2' */
        SWC_TPC_DW.UnitDelay2_DSTATE_g = 0.0F - rtb_Subtract_gc;
      } else {
        /* UnitDelay: '<S182>/Unit Delay2' incorporates:
         *  Constant: '<S182>/Constant3'
         */
        SWC_TPC_DW.UnitDelay2_DSTATE_g = 0.0F;
      }

      /* End of Switch: '<S182>/Switch3' */
    }
  }

  /* End of Switch: '<S182>/Switch' */

  /* Update for UnitDelay: '<S203>/Unit Delay2' */
  SWC_TPC_DW.UnitDelay2_DSTATE = rtb_TModuleTempHighest_l;

  /* Update for UnitDelay: '<S216>/Unit Delay2' */
  SWC_TPC_DW.UnitDelay2_DSTATE_b = rtb_TModuleTempHighest_m;

  /* Update for UnitDelay: '<S217>/Unit Delay2' */
  SWC_TPC_DW.UnitDelay2_DSTATE_m = rtb_TModuleTempHighest_j;

  /* Update for UnitDelay: '<S234>/Unit Delay2' */
  SWC_TPC_DW.UnitDelay2_DSTATE_bo = rtb_TModuleTempHighest_p;

  /* Update for UnitDelay: '<S235>/Unit Delay2' */
  SWC_TPC_DW.UnitDelay2_DSTATE_a = rtb_TModuleTempHighest;

  /* Update for UnitDelay: '<S131>/Unit Delay2' */
  SWC_TPC_DW.UnitDelay2_DSTATE_k = rtb_TModuleTempHighest_h;

  /* Update for UnitDelay: '<S130>/Unit Delay2' */
  SWC_TPC_DW.UnitDelay2_DSTATE_mz = rtb_TModuleTempHighest_e;

  /* Update for UnitDelay: '<S121>/Unit Delay' incorporates:
   *  Constant: '<S121>/Constant'
   */
  SWC_TPC_DW.UnitDelay_DSTATE_l = true;

  /* Update for UnitDelay: '<S120>/Unit Delay' incorporates:
   *  Constant: '<S120>/Constant'
   */
  SWC_TPC_DW.UnitDelay_DSTATE_de = true;

  /* Update for UnitDelay: '<S15>/Unit Delay' */
  SWC_TPC_DW.UnitDelay_DSTATE_eh = rtb_TmpSignalConversionAtRP_S_n;

  /* Update for Delay: '<S15>/Delay1' */
  SWC_TPC_DW.Delay1_DSTATE = VAR_TpcCod_PowerAdd_f32;

  /* Update for Delay: '<S15>/Delay10' */
  SWC_TPC_DW.Delay10_DSTATE[0] = SWC_TPC_DW.Delay10_DSTATE[1];
  SWC_TPC_DW.Delay10_DSTATE[1] = VAR_TpcCod_PowerAdd_f32;

  /* Update for Delay: '<S15>/Delay9' */
  SWC_TPC_DW.Delay9_DSTATE[0] = SWC_TPC_DW.Delay9_DSTATE[1];
  SWC_TPC_DW.Delay9_DSTATE[1] = SWC_TPC_DW.Delay9_DSTATE[2];
  SWC_TPC_DW.Delay9_DSTATE[2] = VAR_TpcCod_PowerAdd_f32;

  /* Update for Delay: '<S15>/Delay7' */
  SWC_TPC_DW.Delay7_DSTATE[0] = SWC_TPC_DW.Delay7_DSTATE[1];
  SWC_TPC_DW.Delay7_DSTATE[1] = SWC_TPC_DW.Delay7_DSTATE[2];
  SWC_TPC_DW.Delay7_DSTATE[2] = SWC_TPC_DW.Delay7_DSTATE[3];
  SWC_TPC_DW.Delay7_DSTATE[3] = VAR_TpcCod_PowerAdd_f32;

  /* Update for Delay: '<S15>/Delay6' */
  SWC_TPC_DW.Delay6_DSTATE[0] = SWC_TPC_DW.Delay6_DSTATE[1];
  SWC_TPC_DW.Delay6_DSTATE[1] = SWC_TPC_DW.Delay6_DSTATE[2];
  SWC_TPC_DW.Delay6_DSTATE[2] = SWC_TPC_DW.Delay6_DSTATE[3];
  SWC_TPC_DW.Delay6_DSTATE[3] = SWC_TPC_DW.Delay6_DSTATE[4];
  SWC_TPC_DW.Delay6_DSTATE[4] = VAR_TpcCod_PowerAdd_f32;

  /* Update for Delay: '<S15>/Delay5' */
  for (idxDelay = 0; idxDelay < 5; idxDelay++) {
    SWC_TPC_DW.Delay5_DSTATE[idxDelay] = SWC_TPC_DW.Delay5_DSTATE[idxDelay + 1];
  }

  SWC_TPC_DW.Delay5_DSTATE[5] = VAR_TpcCod_PowerAdd_f32;

  /* End of Update for Delay: '<S15>/Delay5' */

  /* Update for Delay: '<S15>/Delay4' */
  for (idxDelay = 0; idxDelay < 6; idxDelay++) {
    SWC_TPC_DW.Delay4_DSTATE[idxDelay] = SWC_TPC_DW.Delay4_DSTATE[idxDelay + 1];
  }

  SWC_TPC_DW.Delay4_DSTATE[6] = VAR_TpcCod_PowerAdd_f32;

  /* End of Update for Delay: '<S15>/Delay4' */

  /* Update for Delay: '<S15>/Delay3' */
  for (idxDelay = 0; idxDelay < 7; idxDelay++) {
    SWC_TPC_DW.Delay3_DSTATE[idxDelay] = SWC_TPC_DW.Delay3_DSTATE[idxDelay + 1];
  }

  SWC_TPC_DW.Delay3_DSTATE[7] = VAR_TpcCod_PowerAdd_f32;

  /* End of Update for Delay: '<S15>/Delay3' */

  /* Update for Delay: '<S15>/Delay2' */
  for (idxDelay = 0; idxDelay < 8; idxDelay++) {
    SWC_TPC_DW.Delay2_DSTATE[idxDelay] = SWC_TPC_DW.Delay2_DSTATE[idxDelay + 1];
  }

  SWC_TPC_DW.Delay2_DSTATE[8] = VAR_TpcCod_PowerAdd_f32;

  /* End of Update for Delay: '<S15>/Delay2' */

  /* Update for UnitDelay: '<S105>/Unit Delay3' */
  SWC_TPC_DW.UnitDelay3_DSTATE = VAR_Tpcblk_TrqLim01_f32;

  /* Update for UnitDelay: '<S105>/Unit Delay2' */
  SWC_TPC_DW.UnitDelay2_DSTATE_al = VAR_Tpcblk_TrqLim_f32;

  /* Update for UnitDelay: '<S19>/Unit Delay' incorporates:
   *  Constant: '<S19>/Constant'
   */
  SWC_TPC_DW.UnitDelay_DSTATE_in = true;

  /* Update for UnitDelay: '<S20>/Unit Delay' incorporates:
   *  Constant: '<S20>/Constant'
   */
  SWC_TPC_DW.UnitDelay_DSTATE_kxy = true;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_TPC_10ms' */

  /* Outport: '<Root>/PP_SWC_TPC_TPC_TrqMax' */
  (void) Rte_Write_PP_SWC_TPC_TPC_TrqMax(rtb_Product_g);

  /* Outport: '<Root>/PP_SWC_TPC_TPC_TrqMin' */
  (void) Rte_Write_PP_SWC_TPC_TPC_TrqMin(rtb_Add);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_TPC_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_TPC_10ms_sys'
   */
  /* Chart: '<S13>/Chart2' */
  if (VAR_tpccod_flgMaxDertExCTrq_b) {
    tmp = bDern_ExCTrq;
  } else if (VAR_tpccod_flgMaxDertStrTemp_b) {
    tmp = bDern_StrTemp;
  } else if (VAR_tpccod_flgMaxDertTempDBC_b) {
    tmp = bDern_TempDBC;
  } else if (VAR_tpccod_flgMaxDertTCoolant_b) {
    tmp = bDern_TCoolant;
  } else if (VAR_tpccod_flgMaxDertTDrvBoard_b) {
    tmp = bDern_TDrvBoard;
  } else if (VAR_tpccod_flgMaxDertTIGBT_b) {
    tmp = bDern_TempIGBT;
  } else if (VAR_tpccod_flgMaxDertMtrSpd_b) {
    tmp = bDern_N;
  } else if (VAR_tpccod_flgMaxDertOvrIdc_b) {
    tmp = bDern_OvrIdc;
  } else if (VAR_tpccod_flgMaxDertUndrUdc_b) {
    tmp = bDern_UndrUdc;
  } else if (VAR_tpccod_flgMaxDertOvrUdc_b) {
    tmp = bDern_OvrUdc;
  } else if (VAR_tpccod_flgMaxDertCAN_b) {
    tmp = bDern_CAN;
  } else {
    tmp = bDern_Inactive;
  }

  /* End of Chart: '<S13>/Chart2' */

  /* Outport: '<Root>/PP_SWC_TPC_TPC_stTrqEmMax' incorporates:
   *  DataTypeConversion: '<S13>/Data Type Conversion'
   */
  (void) Rte_Write_PP_SWC_TPC_TPC_stTrqEmMax((uint8)tmp);

  /* Chart: '<S13>/Chart4' */
  if (VAR_tpccod_flgMinDertExCTrq_b) {
    tmp = bDern_ExCTrq;
  } else if (VAR_tpccod_flgMinDertStrTemp_b) {
    tmp = bDern_StrTemp;
  } else if (VAR_tpccod_flgMinDertTempDBC_b) {
    tmp = bDern_TempDBC;
  } else if (VAR_tpccod_flgMinDertTCoolant_b) {
    tmp = bDern_TCoolant;
  } else if (VAR_tpccod_flgMinDertTDrvBoard_b) {
    tmp = bDern_TDrvBoard;
  } else if (VAR_tpccod_flgMinDertTIGBT_b) {
    tmp = bDern_TempIGBT;
  } else if (VAR_tpccod_flgMinDertMtrSpd_b) {
    tmp = bDern_N;
  } else if (VAR_tpccod_flgMinDertOvrIdc_b) {
    tmp = bDern_OvrIdc;
  } else if (VAR_tpccod_flgMinDertUndrUdc_b) {
    tmp = bDern_UndrUdc;
  } else if (VAR_tpccod_flgMinDertOvrUdc_b) {
    tmp = bDern_OvrUdc;
  } else if (VAR_tpccod_flgMinDertCAN_b) {
    tmp = bDern_CAN;
  } else {
    tmp = bDern_Inactive;
  }

  /* End of Chart: '<S13>/Chart4' */

  /* Outport: '<Root>/PP_SWC_TPC_TPC_stTrqEmMin' incorporates:
   *  DataTypeConversion: '<S13>/Data Type Conversion1'
   */
  (void) Rte_Write_PP_SWC_TPC_TPC_stTrqEmMin((uint8)tmp);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_TPC_10ms' */

  /* Outport: '<Root>/PP_SWC_TPC_TPC_stMotorMod' */
  (void) Rte_Write_PP_SWC_TPC_TPC_stMotorMod(tpccod_stMotorMod);

  /* Outport: '<Root>/PP_SWC_TPC_TPC_SgnRotDir' */
  (void) Rte_Write_PP_SWC_TPC_TPC_SgnRotDir(tpccod_SgnRotDir);

  /* Outport: '<Root>/PP_SWC_TPC_TPC_SgnTrqMechDir' */
  (void) Rte_Write_PP_SWC_TPC_TPC_SgnTrqMechDir(tpccod_SgnTrqMechDir);

  /* Outport: '<Root>/PP_SWC_TPC_TPC_bDernElecOvrIdc' */
  (void) Rte_Write_PP_SWC_TPC_TPC_bDernElecOvrIdc(rtb_FIM_PwrLimLvThree);

  /* Outport: '<Root>/PP_SWC_TPC_TPC_bDernGenOvrIdc' */
  (void) Rte_Write_PP_SWC_TPC_TPC_bDernGenOvrIdc(rtb_FIM_PwrLimLvFour);

  /* Outport: '<Root>/PP_SWC_TPC_TPC_TrqMaxTrans' */
  (void) Rte_Write_PP_SWC_TPC_TPC_TrqMaxTrans(rtb_Switch_iq);

  /* Outport: '<Root>/PP_SWC_TPC_TPC_TrqMinTrans' */
  (void) Rte_Write_PP_SWC_TPC_TPC_TrqMinTrans(rtb_TmpSignalConversionAtRP_SWC);
}

/* Model initialize function */
void SWC_TPC_Init(void)
{
  {
    /* local block i/o variables */
    float32 rtb_TModuleTempHighest;
    float32 rtb_TModuleTempHighest_p;
    float32 rtb_TModuleTempHighest_j;
    float32 rtb_TModuleTempHighest_m;
    float32 rtb_TModuleTempHighest_l;
    float32 rtb_TModuleTempHighest_h;
    float32 rtb_TModuleTempHighest_e;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_TPC_10ms' incorporates:
     *  SubSystem: '<Root>/RE_SWC_TPC_10ms_sys'
     */
    /* InitializeConditions for UnitDelay: '<S125>/Unit Delay2' */
    SWC_TPC_DW.UnitDelay2_DSTATE_l = 300.0F;

    /* InitializeConditions for UnitDelay: '<S124>/Unit Delay2' */
    SWC_TPC_DW.UnitDelay2_DSTATE_d = 300.0F;

    /* InitializeConditions for UnitDelay: '<S105>/Unit Delay3' */
    SWC_TPC_DW.UnitDelay3_DSTATE = 310.0F;

    /* InitializeConditions for UnitDelay: '<S105>/Unit Delay2' */
    SWC_TPC_DW.UnitDelay2_DSTATE_al = 310.0F;

    /* SystemInitialize for Chart: '<S130>/GetHighTemp' */
    SWC_TPC_GetHighTemp_Init(&rtb_TModuleTempHighest_e);

    /* SystemInitialize for Chart: '<S131>/GetHighTemp' */
    SWC_TPC_GetHighTemp_Init(&rtb_TModuleTempHighest_h);

    /* SystemInitialize for Chart: '<S203>/GetHighTemp' */
    SWC_TPC_GetHighTemp_Init(&rtb_TModuleTempHighest_l);

    /* SystemInitialize for Chart: '<S216>/GetHighTemp' */
    SWC_TPC_GetHighTemp_Init(&rtb_TModuleTempHighest_m);

    /* SystemInitialize for Chart: '<S217>/GetHighTemp' */
    SWC_TPC_GetHighTemp_Init(&rtb_TModuleTempHighest_j);

    /* SystemInitialize for Chart: '<S234>/GetHighTemp' */
    SWC_TPC_GetHighTemp_Init(&rtb_TModuleTempHighest_p);

    /* SystemInitialize for Chart: '<S235>/GetHighTemp' */
    SWC_TPC_GetHighTemp_Init(&rtb_TModuleTempHighest);

    /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_TPC_10ms' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
