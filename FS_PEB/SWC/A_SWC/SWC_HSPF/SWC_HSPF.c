/*
 * File: SWC_HSPF.c
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

#include "SWC_HSPF.h"
#include "SWC_HSPF_private.h"
#include "look2_iflf_binlxpw.h"

/* Named constants for Chart: '<S21>/UIPhaSenOffCal' */
#define SWC_HSPF_IN_OffstCalFishd      ((uint8)1U)
#define SWC_HSPF_IN_OffstCalInit       ((uint8)2U)
#define SWC_HSPF_IN_OffstCalRun        ((uint8)3U)

/* Exported block signals */
float32 VAR_Bsw_Hwver_f32;
               /* '<S1>/RP_SWC_IoHwAb_ADC_BSW_HwVer_IoHwAb_ADC_GetPhyVoltage' */
float32 VAR_Hspf_tDBCTempU_f32;        /* '<S53>/Switch2' */
float32 VAR_Hspf_tDBCTempV_f32;        /* '<S55>/Switch2' */
float32 VAR_Hspf_tDBCTempW_f32;        /* '<S64>/Switch2' */
float32 VAR_Bsw_tCoolantTemp_f32;
        /* '<S1>/RP_SWC_IoHwAb_ADC_BSW_tCoolantTemp_IoHwAb_ADC_GetPhyVoltage' */
float32 VAR_Hspf_uKl30_f32;
               /* '<S1>/RP_SWC_IoHwAb_ADC_BSW_uKl30_IoHwAb_ADC_GetPhyVoltage' */
float32 VAR_Hspf_tCoolantTemp_f32;     /* '<S52>/tCoolantTem_Table' */
float32 VAR_Hspf_tDrvBoardTemp_f32;    /* '<S48>/PCBTem_Table' */
float32 VAR_Hspf_uDcLnk_f32;           /* '<S9>/Gain' */
uint16 VAR_Bsw_tStrrTemp1_u16;         /* '<S9>/Data Type Conversion1' */
uint16 VAR_Bsw_tStrrTemp2_u16;         /* '<S9>/Data Type Conversion' */
uint16 VAR_Bsw_tDBCTempU_u16;          /* '<S9>/Gain1' */
uint16 VAR_Bsw_tDBCTempV_u16;          /* '<S9>/Gain2' */
uint16 VAR_Bsw_tDBCTempW_u16;          /* '<S9>/Gain3' */
uint16 VAR_Bsw_tDrvBoardTemp_u16;      /* '<S9>/Gain4' */
sint16 VAR_Hspf_tStrrTemp1_s16;        /* '<S65>/Switch' */
sint16 VAR_Hspf_tStrrTemp2_s16;        /* '<S61>/Switch' */
uint8 VAR_Hspf_stVerChk_u8;            /* '<S43>/Switch4' */
uint8 VAR_Hspf_VerMatchFailureErr_u8;  /* '<S43>/Add1' */
uint8 VAR_Hspf_HWVer_u8;               /* '<S43>/Data Type Conversion' */
boolean VAR_Hspf_bSwtTempSttr1_b;      /* '<S65>/Logical Operator' */
boolean VAR_Hspf_bSwtTempSttr2_b;      /* '<S61>/Logical Operator' */
boolean VAR_Bsw_INV_Open_b;
                /* '<S1>/RP_SWC_IoHwAb_DIO_Get_BSW_flgMcuOpen_IoHwAb_DIO_Get' */
boolean VAR_Bsw_Motor_Open_b;
              /* '<S1>/RP_SWC_IoHwAb_DIO_Get_BSW_flgMotorOpen_IoHwAb_DIO_Get' */
boolean VAR_Hspf_tDBCCmpErrDelay_b;    /* '<S20>/Relational Operator' */
boolean VAR_Bsw_Wake_b;
                      /* '<S1>/RP_SWC_IoHwAb_DIO_Get_BSW_Wake_IoHwAb_DIO_Get' */
boolean VAR_Bsw_bt15_b;
                      /* '<S1>/RP_SWC_IoHwAb_DIO_Get_BSW_bt15_IoHwAb_DIO_Get' */
boolean VAR_Bsw_Crash_b;
                  /* '<S1>/RP_SWC_IoHwAb_DIO_Get_BSW_flgCrash_IoHwAb_DIO_Get' */
boolean VAR_Hspf_flgSttr2NoErr_b;      /* '<S11>/Logical Operator1' */
boolean VAR_Hspf_flgSttr1NoErr_b;      /* '<S11>/Logical Operator' */
float32 GLB_HSPF_iDcLnkEstFlt_f32;
/* Exported data definition */
#pragma section ".rodata.Calib_32"

/* Definition for custom storage class: iEDS_Parameter */
const volatile float32 CAL_Hspf_CPLDProjectNumTable_af32[6] = { 0.0F, 1.0F, 2.0F,
  3.0F, 4.0F, 5.0F } ;            /* Referenced by: '<S43>/2-D Lookup Table1' */

/* CPLD项目号 */
const volatile float32 CAL_Hspf_CltInletTempFltFrq_f32 = 10.0F;
                     /* Referenced by: '<S9>/CAL_Hspf_CltInletTempFltFrq_f32' */
const volatile float32 CAL_Hspf_CodeCpldSwMatchTable_af32[28] = { 0.0F, 0.0F,
  0.0F, 0.0F, 100.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
;                                 /* Referenced by: '<S43>/2-D Lookup Table2' */

/* 软件和CPLD软件版本号匹配表 */
const volatile float32 CAL_Hspf_CodeDataMatchTable_af32[42] = { 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 100.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
;                                  /* Referenced by: '<S43>/2-D Lookup Table' */

/* 软件和数据匹配表 */
const volatile float32 CAL_Hspf_CodeHvMcuMatchTable_af32[42] = { 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 100.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F } ;                        /* Referenced by: '<S43>/2-D Lookup Table3' */

/* 软件和高压MCU版本号匹配表 */
const volatile float32 CAL_Hspf_CodeTable_af32[7] = { 1.0F, 2.0F, 3.0F, 4.0F,
  5.0F, 6.0F, 7.0F } ;                 /* Referenced by:
                                        * '<S43>/2-D Lookup Table'
                                        * '<S43>/2-D Lookup Table2'
                                        * '<S43>/2-D Lookup Table3'
                                        */

/* 软件版本号 */
const volatile float32 CAL_Hspf_CpldSwTable_af32[4] = { 3.0F, 4.0F, 5.0F, 6.0F }
;                                 /* Referenced by: '<S43>/2-D Lookup Table2' */

/* CPLD软件版本 */
const volatile uint8 CAL_Hspf_CrashChkAddCnt_u8 = 1U;
                         /* Referenced by: '<S25>/CAL_Hspf_CrashChkAddCnt_u8' */
const volatile uint8 CAL_Hspf_CrashChkCntHiLim_u8 = 5U;
                       /* Referenced by: '<S25>/CAL_Hspf_CrashChkCntHiLim_u8' */
const volatile sint8 CAL_Hspf_CrashChkCntLoLim_s8 = 0;
                       /* Referenced by: '<S25>/CAL_Hspf_CrashChkCntLoLim_s8' */
const volatile sint8 CAL_Hspf_CrashChkSubCnt_s8 = -1;
                         /* Referenced by: '<S25>/CAL_Hspf_CrashChkSubCnt_u8' */
const volatile uint8 CAL_Hspf_DBCTempROCLimChkCnt_u8 = 10U;/* Referenced by:
                                                            * '<S53>/CAL_Hspf_DBCTempROCLimChkCnt_u8'
                                                            * '<S55>/CAL_Hspf_DBCTempROCLimChkCnt_u8'
                                                            * '<S64>/CAL_Hspf_DBCTempROCLimChkCnt_u8'
                                                            */
const volatile float32 CAL_Hspf_DataTable_af32[6] = { 0.0F, 1.0F, 2.0F, 3.0F,
  4.0F, 5.0F } ;                   /* Referenced by: '<S43>/2-D Lookup Table' */

/* 数据版本号 */
const volatile float32 CAL_Hspf_HvMcuTable_af32[6] = { 4.0F, 5.0F, 6.0F, 7.0F,
  8.0F, 9.0F } ;                  /* Referenced by: '<S43>/2-D Lookup Table3' */

/* 高压MCU版本号 */
const volatile float32 CAL_Hspf_HwAnalHwVerMatchTable_af32[12] = { 0.0F, 0.0F,
  0.0F, 100.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;
                                  /* Referenced by: '<S43>/2-D Lookup Table4' */

/* 硬件匹配表 */
const volatile float32 CAL_Hspf_HwAnalTable_af32[2] = { 0.0F, 1.0F } ;
                                  /* Referenced by: '<S43>/2-D Lookup Table4' */

/* 解析匹配 */
const volatile float32 CAL_Hspf_HwVerTable_af32[6] = { 4.0F, 5.0F, 6.0F, 7.0F,
  8.0F, 9.0F } ;                  /* Referenced by: '<S43>/2-D Lookup Table4' */

/* 硬件版本号 */
const volatile uint8 CAL_Hspf_INVOpenChkAddCnt_u8 = 1U;
                       /* Referenced by: '<S26>/CAL_Hspf_INVOpenChkAddCnt_u8' */
const volatile uint8 CAL_Hspf_INVOpenChkCntHiLim_u8 = 5U;
                     /* Referenced by: '<S26>/CAL_Hspf_INVOpenChkCntHiLim_u8' */
const volatile sint8 CAL_Hspf_INVOpenChkCntLoLim_s8 = 0;
                     /* Referenced by: '<S26>/CAL_Hspf_INVOpenChkCntLoLim_s8' */
const volatile sint8 CAL_Hspf_INVOpenChkSubCnt_s8 = -1;
                       /* Referenced by: '<S26>/CAL_Hspf_INVOpenChkSubCnt_s8' */
const volatile uint64 CAL_Hspf_McuName_u64 = (41897230848ULL);
                               /* Referenced by: '<S43>/CAL_Hspf_McuName_u64' */

/* 6位MCU规范命名解析的十进制数 */
const volatile uint8 CAL_Hspf_MotTemHigTable_af32[1024] = { 200U, 200U, 200U,
  200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U,
  200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U,
  200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U,
  200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U,
  200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U,
  200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U,
  200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U,
  200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U,
  200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U,
  200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U,
  200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 200U, 199U, 199U, 198U,
  198U, 197U, 197U, 197U, 196U, 196U, 195U, 195U, 195U, 194U, 194U, 193U, 193U,
  193U, 192U, 192U, 191U, 191U, 191U, 190U, 190U, 190U, 189U, 189U, 189U, 188U,
  188U, 187U, 187U, 187U, 186U, 186U, 186U, 185U, 185U, 185U, 184U, 184U, 184U,
  183U, 183U, 183U, 182U, 182U, 182U, 182U, 181U, 181U, 181U, 180U, 180U, 180U,
  179U, 179U, 179U, 178U, 178U, 178U, 178U, 177U, 177U, 177U, 176U, 176U, 176U,
  176U, 175U, 175U, 175U, 174U, 174U, 174U, 174U, 173U, 173U, 173U, 172U, 172U,
  172U, 172U, 171U, 171U, 171U, 171U, 170U, 170U, 170U, 170U, 169U, 169U, 169U,
  168U, 168U, 168U, 168U, 167U, 167U, 167U, 167U, 166U, 166U, 166U, 166U, 165U,
  165U, 165U, 165U, 165U, 164U, 164U, 164U, 164U, 163U, 163U, 163U, 163U, 162U,
  162U, 162U, 162U, 161U, 161U, 161U, 161U, 161U, 160U, 160U, 160U, 160U, 159U,
  159U, 159U, 159U, 159U, 158U, 158U, 158U, 158U, 157U, 157U, 157U, 157U, 157U,
  156U, 156U, 156U, 156U, 156U, 155U, 155U, 155U, 155U, 154U, 154U, 154U, 154U,
  154U, 153U, 153U, 153U, 153U, 153U, 152U, 152U, 152U, 152U, 152U, 151U, 151U,
  151U, 151U, 151U, 150U, 150U, 150U, 150U, 150U, 149U, 149U, 149U, 149U, 149U,
  149U, 148U, 148U, 148U, 148U, 148U, 147U, 147U, 147U, 147U, 147U, 146U, 146U,
  146U, 146U, 146U, 146U, 145U, 145U, 145U, 145U, 145U, 144U, 144U, 144U, 144U,
  144U, 144U, 143U, 143U, 143U, 143U, 143U, 142U, 142U, 142U, 142U, 142U, 142U,
  141U, 141U, 141U, 141U, 141U, 141U, 140U, 140U, 140U, 140U, 140U, 139U, 139U,
  139U, 139U, 139U, 139U, 138U, 138U, 138U, 138U, 138U, 138U, 137U, 137U, 137U,
  137U, 137U, 137U, 136U, 136U, 136U, 136U, 136U, 136U, 135U, 135U, 135U, 135U,
  135U, 135U, 134U, 134U, 134U, 134U, 134U, 134U, 133U, 133U, 133U, 133U, 133U,
  133U, 133U, 132U, 132U, 132U, 132U, 132U, 132U, 131U, 131U, 131U, 131U, 131U,
  131U, 130U, 130U, 130U, 130U, 130U, 130U, 129U, 129U, 129U, 129U, 129U, 129U,
  129U, 128U, 128U, 128U, 128U, 128U, 128U, 127U, 127U, 127U, 127U, 127U, 127U,
  127U, 126U, 126U, 126U, 126U, 126U, 126U, 125U, 125U, 125U, 125U, 125U, 125U,
  125U, 124U, 124U, 124U, 124U, 124U, 124U, 124U, 123U, 123U, 123U, 123U, 123U,
  123U, 122U, 122U, 122U, 122U, 122U, 122U, 122U, 121U, 121U, 121U, 121U, 121U,
  121U, 121U, 120U, 120U, 120U, 120U, 120U, 120U, 120U, 119U, 119U, 119U, 119U,
  119U, 119U, 119U, 118U, 118U, 118U, 118U, 118U, 118U, 118U, 117U, 117U, 117U,
  117U, 117U, 117U, 117U, 116U, 116U, 116U, 116U, 116U, 116U, 116U, 115U, 115U,
  115U, 115U, 115U, 115U, 115U, 114U, 114U, 114U, 114U, 114U, 114U, 113U, 113U,
  113U, 113U, 113U, 113U, 113U, 112U, 112U, 112U, 112U, 112U, 112U, 112U, 111U,
  111U, 111U, 111U, 111U, 111U, 111U, 111U, 110U, 110U, 110U, 110U, 110U, 110U,
  110U, 109U, 109U, 109U, 109U, 109U, 109U, 109U, 108U, 108U, 108U, 108U, 108U,
  108U, 108U, 107U, 107U, 107U, 107U, 107U, 107U, 107U, 106U, 106U, 106U, 106U,
  106U, 106U, 106U, 105U, 105U, 105U, 105U, 105U, 105U, 105U, 104U, 104U, 104U,
  104U, 104U, 104U, 104U, 103U, 103U, 103U, 103U, 103U, 103U, 103U, 102U, 102U,
  102U, 102U, 102U, 102U, 102U, 101U, 101U, 101U, 101U, 101U, 101U, 101U, 100U,
  100U, 100U, 100U, 100U, 100U, 100U, 99U, 99U, 99U, 99U, 99U, 99U, 99U, 98U,
  98U, 98U, 98U, 98U, 98U, 98U, 97U, 97U, 97U, 97U, 97U, 97U, 97U, 96U, 96U, 96U,
  96U, 96U, 96U, 96U, 95U, 95U, 95U, 95U, 95U, 95U, 95U, 94U, 94U, 94U, 94U, 94U,
  94U, 94U, 93U, 93U, 93U, 93U, 93U, 93U, 93U, 92U, 92U, 92U, 92U, 92U, 92U, 91U,
  91U, 91U, 91U, 91U, 91U, 91U, 90U, 90U, 90U, 90U, 90U, 90U, 90U, 89U, 89U, 89U,
  89U, 89U, 89U, 89U, 88U, 88U, 88U, 88U, 88U, 88U, 87U, 87U, 87U, 87U, 87U, 87U,
  87U, 86U, 86U, 86U, 86U, 86U, 86U, 85U, 85U, 85U, 85U, 85U, 85U, 85U, 84U, 84U,
  84U, 84U, 84U, 84U, 83U, 83U, 83U, 83U, 83U, 83U, 82U, 82U, 82U, 82U, 82U, 82U,
  82U, 81U, 81U, 81U, 81U, 81U, 81U, 80U, 80U, 80U, 80U, 80U, 80U, 79U, 79U, 79U,
  79U, 79U, 79U, 78U, 78U, 78U, 78U, 78U, 78U, 77U, 77U, 77U, 77U, 77U, 77U, 76U,
  76U, 76U, 76U, 76U, 76U, 75U, 75U, 75U, 75U, 75U, 74U, 74U, 74U, 74U, 74U, 74U,
  73U, 73U, 73U, 73U, 73U, 73U, 72U, 72U, 72U, 72U, 72U, 71U, 71U, 71U, 71U, 71U,
  71U, 70U, 70U, 70U, 70U, 70U, 69U, 69U, 69U, 69U, 69U, 68U, 68U, 68U, 68U, 68U,
  67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U,
  67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U,
  67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U,
  67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U,
  67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U,
  67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U,
  67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U,
  67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U,
  67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U,
  67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U,
  67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U, 67U,
  67U, 67U } ;                         /* Referenced by:
                                        * '<S61>/Constant'
                                        * '<S65>/Constant'
                                        */

const volatile sint8 CAL_Hspf_MotTemLowTable_af32[1024] = { 105, 105, 105, 105,
  105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105,
  105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105,
  105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105,
  105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105,
  105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105,
  105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105,
  105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105,
  105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105,
  105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105,
  105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105,
  105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105,
  105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 104, 104, 104, 104, 103,
  103, 103, 103, 103, 102, 102, 102, 102, 102, 101, 101, 101, 101, 101, 100, 100,
  100, 100, 100, 99, 99, 99, 99, 99, 98, 98, 98, 98, 98, 97, 97, 97, 97, 97, 96,
  96, 96, 96, 96, 95, 95, 95, 95, 95, 95, 94, 94, 94, 94, 94, 93, 93, 93, 93, 93,
  93, 92, 92, 92, 92, 92, 92, 91, 91, 91, 91, 91, 91, 90, 90, 90, 90, 90, 90, 89,
  89, 89, 89, 89, 89, 88, 88, 88, 88, 88, 88, 88, 87, 87, 87, 87, 87, 87, 86, 86,
  86, 86, 86, 86, 86, 85, 85, 85, 85, 85, 85, 84, 84, 84, 84, 84, 84, 84, 83, 83,
  83, 83, 83, 83, 83, 82, 82, 82, 82, 82, 82, 82, 81, 81, 81, 81, 81, 81, 81, 80,
  80, 80, 80, 80, 80, 80, 80, 79, 79, 79, 79, 79, 79, 79, 78, 78, 78, 78, 78, 78,
  78, 78, 77, 77, 77, 77, 77, 77, 77, 76, 76, 76, 76, 76, 76, 76, 76, 75, 75, 75,
  75, 75, 75, 75, 75, 74, 74, 74, 74, 74, 74, 74, 74, 73, 73, 73, 73, 73, 73, 73,
  73, 72, 72, 72, 72, 72, 72, 72, 72, 71, 71, 71, 71, 71, 71, 71, 71, 71, 70, 70,
  70, 70, 70, 70, 70, 70, 69, 69, 69, 69, 69, 69, 69, 69, 69, 68, 68, 68, 68, 68,
  68, 68, 68, 67, 67, 67, 67, 67, 67, 67, 67, 67, 66, 66, 66, 66, 66, 66, 66, 66,
  66, 65, 65, 65, 65, 65, 65, 65, 65, 64, 64, 64, 64, 64, 64, 64, 64, 64, 63, 63,
  63, 63, 63, 63, 63, 63, 63, 63, 62, 62, 62, 62, 62, 62, 62, 62, 62, 61, 61, 61,
  61, 61, 61, 61, 61, 61, 60, 60, 60, 60, 60, 60, 60, 60, 60, 59, 59, 59, 59, 59,
  59, 59, 59, 59, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 57, 57, 57, 57, 57, 57,
  57, 57, 57, 56, 56, 56, 56, 56, 56, 56, 56, 56, 56, 55, 55, 55, 55, 55, 55, 55,
  55, 55, 54, 54, 54, 54, 54, 54, 54, 54, 54, 53, 53, 53, 53, 53, 53, 53, 53, 53,
  53, 52, 52, 52, 52, 52, 52, 52, 52, 52, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51,
  50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 49, 49, 49, 49, 49, 49, 49, 49, 49, 48,
  48, 48, 48, 48, 48, 48, 48, 48, 48, 47, 47, 47, 47, 47, 47, 47, 47, 47, 46, 46,
  46, 46, 46, 46, 46, 46, 46, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 44, 44, 44,
  44, 44, 44, 44, 44, 44, 43, 43, 43, 43, 43, 43, 43, 43, 43, 42, 42, 42, 42, 42,
  42, 42, 42, 42, 42, 41, 41, 41, 41, 41, 41, 41, 41, 41, 40, 40, 40, 40, 40, 40,
  40, 40, 40, 39, 39, 39, 39, 39, 39, 39, 39, 39, 38, 38, 38, 38, 38, 38, 38, 38,
  38, 37, 37, 37, 37, 37, 37, 37, 37, 37, 36, 36, 36, 36, 36, 36, 36, 36, 35, 35,
  35, 35, 35, 35, 35, 35, 35, 34, 34, 34, 34, 34, 34, 34, 34, 34, 33, 33, 33, 33,
  33, 33, 33, 33, 32, 32, 32, 32, 32, 32, 32, 32, 31, 31, 31, 31, 31, 31, 31, 31,
  31, 30, 30, 30, 30, 30, 30, 30, 30, 29, 29, 29, 29, 29, 29, 29, 29, 28, 28, 28,
  28, 28, 28, 28, 27, 27, 27, 27, 27, 27, 27, 27, 26, 26, 26, 26, 26, 26, 26, 26,
  25, 25, 25, 25, 25, 25, 25, 24, 24, 24, 24, 24, 24, 24, 23, 23, 23, 23, 23, 23,
  23, 22, 22, 22, 22, 22, 22, 22, 21, 21, 21, 21, 21, 21, 21, 20, 20, 20, 20, 20,
  20, 20, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 17, 17, 17, 17, 17, 17,
  16, 16, 16, 16, 16, 16, 15, 15, 15, 15, 15, 15, 14, 14, 14, 14, 14, 14, 13, 13,
  13, 13, 13, 12, 12, 12, 12, 12, 12, 11, 11, 11, 11, 11, 10, 10, 10, 10, 10, 9,
  9, 9, 9, 9, 8, 8, 8, 8, 7, 7, 7, 7, 7, 6, 6, 6, 6, 5, 5, 5, 5, 5, 4, 4, 4, 4,
  3, 3, 3, 3, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, -1, -1, -1, -1, -2, -2, -2, -3, -3,
  -3, -4, -4, -4, -5, -5, -5, -6, -6, -6, -7, -7, -7, -8, -8, -9, -9, -9, -10,
  -10, -11, -11, -11, -12, -12, -13, -13, -14, -14, -15, -15, -16, -17, -17, -18,
  -18, -19, -20, -20, -21, -22, -22, -23, -24, -25, -26, -27, -28, -29, -30, -31,
  -32, -33, -35, -36, -38, -40, -40, -40, -40, -40, -40, -40, -40 } ;/* Referenced by:
                                                                      * '<S61>/Constant1'
                                                                      * '<S65>/Constant1'
                                                                      */

const volatile uint8 CAL_Hspf_MotorOpenChkAddCnt_u8 = 1U;
                     /* Referenced by: '<S27>/CAL_Hspf_MotorOpenChkAddCnt_u8' */
const volatile uint8 CAL_Hspf_MotorOpenChkCntHiLim_u8 = 5U;
                   /* Referenced by: '<S27>/CAL_Hspf_MotorOpenChkCntHiLim_u8' */
const volatile sint8 CAL_Hspf_MotorOpenChkCntLoLim_s8 = 0;
                   /* Referenced by: '<S27>/CAL_Hspf_MotorOpenChkCntLoLim_s8' */
const volatile sint8 CAL_Hspf_MototOpenChkSubCnt_s8 = -1;
                     /* Referenced by: '<S27>/CAL_Hspf_MototOpenChkSubCnt_s8' */
const volatile uint8 CAL_Hspf_Multiple_u8 = 2U;/* Referenced by:
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
const volatile float32 CAL_Hspf_ProjectNumMatchTable_af32[42] = { 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 100.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F } ;                        /* Referenced by: '<S43>/2-D Lookup Table1' */

/* 项目匹配表 */
const volatile float32 CAL_Hspf_ProjectNuminSWTable_af32[7] = { 6.0F, 7.0F, 8.0F,
  9.0F, 10.0F, 11.0F, 12.0F } ;   /* Referenced by: '<S43>/2-D Lookup Table1' */

/* 解析出来的项目号 */
const volatile uint64 CAL_Hspf_Tc277Name_u64 = (41893036544ULL);/* Referenced by:
                                                                 * '<S43>/CAL_Hspf_Tc277Name_u64'
                                                                 * '<S43>/CAL_Hspf_Tc277Name_u64_2'
                                                                 * '<S43>/CAL_Hspf_Tc277Name_u64_3'
                                                                 * '<S43>/CAL_Hspf_Tc277Name_u64_4'
                                                                 */

/* 8位软件规范命名解析的十进制数 */
const volatile float32 CAL_Hspf_TmpCoolanTjFltFrq_f32 = 10.0F;
                             /* Referenced by: '<S7>/CAL_Hspf_TmpUFltFrq_f32' */

/* 估算水温滤波频率 */
const volatile float32 CAL_Hspf_TmpUFltFrq_f32 = 10.0F;
                             /* Referenced by: '<S9>/CAL_Hspf_TmpUFltFrq_f32' */

/* Temperature filter cut off frequency */
const volatile float32 CAL_Hspf_TmpVFltFrq_f32 = 10.0F;
                             /* Referenced by: '<S9>/CAL_Hspf_TmpVFltFrq_f32' */
const volatile float32 CAL_Hspf_TmpWFltFrq_f32 = 10.0F;
                             /* Referenced by: '<S9>/CAL_Hspf_TmpWFltFrq_f32' */
const volatile uint16 CAL_Hspf_VerChkTime_u16 = 200U;/* Referenced by: '<S45>/Constant' */

/* 软件匹配超时 */
const volatile uint8 CAL_Hspf_VerMatchFailure_u8 = 3U;/* Referenced by:
                                                       * '<S43>/CAL_Hspf_VerMatchFailure_u8'
                                                       * '<S43>/CAL_Spf_VerMatchFailure_u8'
                                                       */

/* 自检失败 */
const volatile uint8 CAL_Hspf_VerMatchSucceed_u8 = 2U;
                        /* Referenced by: '<S43>/CAL_Hspf_VerMatchSucceed_u8' */

/* 自检成功 */
const volatile uint8 CAL_Hspf_VerMatchTimeOutErr_u8 = 1U;/* Referenced by: '<S43>/Constant11 ' */

/* 自检进行中 */
const volatile uint8 CAL_Hspf_VerMatchUncheck_u8 = 0U;/* Referenced by:
                                                       * '<S42>/Constant'
                                                       * '<S43>/CAL_Hspf_VerMatchUncheck_u8'
                                                       * '<S44>/Constant'
                                                       */

/* 自检未进行 */
const volatile uint8 CAL_Hspf_bt15ChkAddCnt_u8 = 1U;/* Referenced by:
                                                     * '<S28>/CAL_Hspf_bt15ChkAddCnt_u8'
                                                     * '<S29>/CAL_Hspf_bt15ChkAddCnt_u8'
                                                     */

/* 点火信号确认上加个数 */
const volatile uint8 CAL_Hspf_bt15ChkCntHiLim_u8 = 5U;/* Referenced by:
                                                       * '<S28>/CAL_Hspf_bt15ChkCntHiLim_u8'
                                                       * '<S29>/CAL_Hspf_bt15ChkCntHiLim_u8'
                                                       */

/* 点火信号确认上限限值 */
const volatile sint8 CAL_Hspf_bt15ChkCntLoLim_s8 = 0;/* Referenced by:
                                                      * '<S28>/CAL_Hspf_bt15ChkCntLoLim_s8'
                                                      * '<S29>/CAL_Hspf_bt15ChkCntLoLim_s8'
                                                      */

/* 点火信号消除下限限值 */
const volatile sint8 CAL_Hspf_bt15ChkSubCnt_s8 = -1;/* Referenced by:
                                                     * '<S28>/CAL_Hspf_bt15ChkSubCnt_s8'
                                                     * '<S29>/CAL_Hspf_bt15ChkSubCnt_s8'
                                                     */

/* 点火信号确认下减个数 */
const volatile uint16 CAL_Hspf_cntIPhCalOffTolCnt_u16 = 128U;
                     /* Referenced by: '<S21>/CAL_CSP_cntIPhCalOffTolCnt_u16' */

/* 相电流采样总计数 */
const volatile uint16 CAL_Hspf_cntIPhCalOffValCnt_u16 = 32U;
                     /* Referenced by: '<S21>/CAL_CSP_cntIPhCalOffValCnt_u16' */

/* 相电流采样有效计数 */
const volatile float32 CAL_Hspf_iDcLnkEstFltFrq_f32 = 10.0F;
                      /* Referenced by: '<S9>/CAL_Hspf_CltInletTempFltFrq_f1' */

/* 母线电流慢滤波值 */
const volatile uint16 CAL_Hspf_iPhaHighSet_u16 = 3000U;
                           /* Referenced by: '<S21>/CAL_Hspf_iPhaHighSet_u16' */

/* 相电流采样有效上限 */
const volatile uint16 CAL_Hspf_iPhaLowSet_u16 = 1000U;
                            /* Referenced by: '<S21>/CAL_Hspf_iPhaLowSet_u16' */

/* 相电流采样有效下限 */
const volatile float32 CAL_Hspf_nFltFrq_f32 = 10.0F;
                                /* Referenced by: '<S9>/CAL_Hspf_nFltFrq_f32' */

/* 电机转速慢滤波截止频率  */
const volatile uint8 CAL_Hspf_stPreDrvCtl_u8 = 3U;
                            /* Referenced by: '<S21>/CAL_Hspf_stPreDrvCtl_u8' */
const volatile float32 CAL_Hspf_tCoolantFltFrq_f32 = 10.0F;
                         /* Referenced by: '<S9>/CAL_Hspf_tCoolantFltFrq_f32' */

/* 冷却水滤波截止频率 */
const volatile uint16 CAL_Hspf_tDBCCmpTime_u16 = 300U;/* Referenced by: '<S20>/Constant' */
const volatile uint8 CAL_Hspf_tDBCTempROCLim_u8 = 5U;/* Referenced by:
                                                      * '<S53>/CAL_Hspf_tDBCTempROCLim_u8'
                                                      * '<S55>/CAL_Hspf_tDBCTempROCLim_u8'
                                                      * '<S64>/CAL_Hspf_tDBCTempROCLim_u8'
                                                      */
const volatile uint8 CAL_Hspf_tDBCtempOffset_u8 = 10U;
                          /* Referenced by: '<S12>/CAL_SDF_tDBCtempOffset_u8' */

/* IGBT温度偏差阈值 */
const volatile float32 CAL_Hspf_tStrrTmp1FltFrq_f32 = 10.0F;
                        /* Referenced by: '<S9>/CAL_Hspf_tStrrTmp1FltFrq_f32' */
const volatile float32 CAL_Hspf_tStrrTmp2FltFrq_f32 = 10.0F;
                        /* Referenced by: '<S9>/CAL_Hspf_tStrrTmp2FltFrq_f32' */
const volatile float32 CAL_Hspf_tSwtTempSttrHiLim_f32 = 88.0F;/* Referenced by:
                                                               * '<S61>/CAL_Hspf_tSwtTempSttrHiLim_f32'
                                                               * '<S65>/CAL_Hspf_tSwtTempSttrHiLim_f32'
                                                               */
const volatile float32 CAL_Hspf_tSwtTempSttrLoLim_f32 = 84.0F;/* Referenced by:
                                                               * '<S61>/CAL_Hspf_tSwtTempSttrLoLim_f32'
                                                               * '<S65>/CAL_Hspf_tSwtTempSttrLoLim_f32'
                                                               */
const volatile float32 CAL_Hspf_uDcLnkFltFrq_f32 = 50.0F;
                           /* Referenced by: '<S9>/CAL_Hspf_uDcLnkFltFrq_f32' */

/* 母线电压慢滤波截止频率  */
const volatile float32 CAL_Hspf_uKl30FltFrq_f32 = 100.0F;
                            /* Referenced by: '<S9>/CAL_Hspf_uKl30FltFrq_f32' */

#pragma section

/* Block signals (default storage) */
B_SWC_HSPF_T SWC_HSPF_B;

/* Block states (default storage) */
DW_SWC_HSPF_T SWC_HSPF_DW;

/* Model step function for TID1 */
void SWC_HSPF_10ms(void)               /* Explicit Task: RE_SWC_HSPF_10ms */
{
  uint8 tmpRead;
  uint16 tmpRead_0;
  uint16 tmpRead_1;
  uint16 tmpRead_2;
  uint8 tmpRead_3;
  float32 rtb_Divide;
  float32 rtb_Divide_j4;
  float32 rtb_Divide_lv;
  boolean rtb_Compare_os;
  boolean rtb_RP_SWC_FIM_HSPF_Sttr2Err__o;
  float32 rtb_TmpSignalConversionAtRP_SWC;
  float32 rtb_UnitDelay_bz;
  float32 rtb_UnitDelay1_j1;
  float32 rtb_UnitDelay5;
  float32 rtb_UnitDelay6;
  float32 rtb_UnitDelay7;
  uint16 rtb_TmpSignalConversionAtRP_S_e;
  uint8 rtb_TmpSignalConversionAtRP_S_g;
  boolean rtb_Compare_p;
  uint8 rtb_TmpSignalConversionAtRP_S_o;
  uint64 rtb_BitwiseOperator3;
  uint32 qY;
  float64 tmp;
  uint16 tmp_0;
  sint32 tmp_1;
  boolean guard1 = false;

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_HSPF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_HSPF_10ms_sys'
   */
  /* FunctionCaller: '<S1>/RP_SWC_IoHwAb_ADC_BSW_tStrrTemp1_IoHwAb_ADC_GetPhyVoltage' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  Rte_Call_RP_SWC_IoHwAb_ADC_BSW_tStrrTemp1_IoHwAb_ADC_GetPhyVoltage(2,
    &rtb_Divide);

  /* DataTypeConversion: '<S9>/Data Type Conversion1' incorporates:
   *  Constant: '<S9>/Constant'
   *  Product: '<S9>/Divide'
   */
  tmp = fmod(floor(rtb_Divide / 4.0), 65536.0);
  VAR_Bsw_tStrrTemp1_u16 = (uint16)(tmp < 0.0 ? (sint32)(uint16)-(sint16)(uint16)
    -tmp : (sint32)(uint16)tmp);

  /* Switch: '<S65>/Switch' incorporates:
   *  Constant: '<S65>/Constant'
   *  Constant: '<S65>/Constant1'
   *  LookupNDDirect: '<S65>/MotTemHig_Table'
   *  LookupNDDirect: '<S65>/MotTemLow_Table'
   *  UnitDelay: '<S65>/Unit Delay'
   *
   * About '<S65>/MotTemHig_Table':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   *
   * About '<S65>/MotTemLow_Table':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  if (SWC_HSPF_DW.UnitDelay_DSTATE_iz) {
    /* LookupNDDirect: '<S65>/MotTemHig_Table'
     *
     * About '<S65>/MotTemHig_Table':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    if (VAR_Bsw_tStrrTemp1_u16 < 1023) {
      tmp_0 = VAR_Bsw_tStrrTemp1_u16;
    } else {
      tmp_0 = 1023U;
    }

    VAR_Hspf_tStrrTemp1_s16 = CAL_Hspf_MotTemHigTable_af32[tmp_0];
  } else {
    if (VAR_Bsw_tStrrTemp1_u16 < 1023) {
      /* LookupNDDirect: '<S65>/MotTemLow_Table'
       *
       * About '<S65>/MotTemLow_Table':
       *  1-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      tmp_0 = VAR_Bsw_tStrrTemp1_u16;
    } else {
      /* LookupNDDirect: '<S65>/MotTemLow_Table'
       *
       * About '<S65>/MotTemLow_Table':
       *  1-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      tmp_0 = 1023U;
    }

    VAR_Hspf_tStrrTemp1_s16 = CAL_Hspf_MotTemLowTable_af32[tmp_0];
  }

  /* End of Switch: '<S65>/Switch' */

  /* Switch: '<S65>/Switch1' incorporates:
   *  Constant: '<S65>/CAL_Hspf_tSwtTempSttrHiLim_f32'
   *  Constant: '<S65>/CAL_Hspf_tSwtTempSttrLoLim_f32'
   *  Constant: '<S65>/Constant2'
   *  RelationalOperator: '<S65>/Relational Operator'
   *  RelationalOperator: '<S65>/Relational Operator1'
   *  UnitDelay: '<S65>/Unit Delay'
   */
  if (VAR_Hspf_tStrrTemp1_s16 >= CAL_Hspf_tSwtTempSttrHiLim_f32) {
    SWC_HSPF_DW.UnitDelay_DSTATE_iz = true;
  } else {
    SWC_HSPF_DW.UnitDelay_DSTATE_iz = ((VAR_Hspf_tStrrTemp1_s16 >
      CAL_Hspf_tSwtTempSttrLoLim_f32) && SWC_HSPF_DW.UnitDelay_DSTATE_iz);
  }

  /* End of Switch: '<S65>/Switch1' */

  /* Logic: '<S65>/Logical Operator' incorporates:
   *  UnitDelay: '<S65>/Unit Delay'
   */
  VAR_Hspf_bSwtTempSttr1_b = !SWC_HSPF_DW.UnitDelay_DSTATE_iz;

  /* FunctionCaller: '<S1>/RP_SWC_IoHwAb_DIO_Set_HSPF_flgSwtTSttr1_IoHwAb_DIO_Set' incorporates:
   *  Constant: '<S1>/Constant10'
   */
  Rte_Call_RP_SWC_IoHwAb_DIO_Set_HSPF_flgSwtTSttr1_IoHwAb_DIO_Set(21,
    VAR_Hspf_bSwtTempSttr1_b);

  /* FunctionCaller: '<S1>/RP_SWC_IoHwAb_ADC_BSW_tStrrTemp2_IoHwAb_ADC_GetPhyVoltage' incorporates:
   *  Constant: '<S1>/Constant2'
   */
  Rte_Call_RP_SWC_IoHwAb_ADC_BSW_tStrrTemp2_IoHwAb_ADC_GetPhyVoltage(6,
    &rtb_Divide);

  /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
   *  Constant: '<S9>/Constant1'
   *  Product: '<S9>/Divide1'
   */
  tmp = fmod(floor(rtb_Divide / 4.0), 65536.0);
  VAR_Bsw_tStrrTemp2_u16 = (uint16)(tmp < 0.0 ? (sint32)(uint16)-(sint16)(uint16)
    -tmp : (sint32)(uint16)tmp);

  /* Switch: '<S61>/Switch' incorporates:
   *  Constant: '<S61>/Constant'
   *  Constant: '<S61>/Constant1'
   *  LookupNDDirect: '<S61>/MotTemHig_Table'
   *  LookupNDDirect: '<S61>/MotTemLow_Table'
   *  UnitDelay: '<S61>/Unit Delay'
   *
   * About '<S61>/MotTemHig_Table':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   *
   * About '<S61>/MotTemLow_Table':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  if (SWC_HSPF_DW.UnitDelay_DSTATE != 0.0) {
    /* LookupNDDirect: '<S61>/MotTemHig_Table'
     *
     * About '<S61>/MotTemHig_Table':
     *  1-dimensional Direct Look-Up returning a Scalar,
     *
     *     Remove protection against out-of-range input in generated code: 'off'
     */
    if (VAR_Bsw_tStrrTemp2_u16 < 1023) {
      tmp_0 = VAR_Bsw_tStrrTemp2_u16;
    } else {
      tmp_0 = 1023U;
    }

    VAR_Hspf_tStrrTemp2_s16 = CAL_Hspf_MotTemHigTable_af32[tmp_0];
  } else {
    if (VAR_Bsw_tStrrTemp2_u16 < 1023) {
      /* LookupNDDirect: '<S61>/MotTemLow_Table'
       *
       * About '<S61>/MotTemLow_Table':
       *  1-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      tmp_0 = VAR_Bsw_tStrrTemp2_u16;
    } else {
      /* LookupNDDirect: '<S61>/MotTemLow_Table'
       *
       * About '<S61>/MotTemLow_Table':
       *  1-dimensional Direct Look-Up returning a Scalar,
       *
       *     Remove protection against out-of-range input in generated code: 'off'
       */
      tmp_0 = 1023U;
    }

    VAR_Hspf_tStrrTemp2_s16 = CAL_Hspf_MotTemLowTable_af32[tmp_0];
  }

  /* End of Switch: '<S61>/Switch' */

  /* Switch: '<S61>/Switch1' incorporates:
   *  Constant: '<S61>/CAL_Hspf_tSwtTempSttrHiLim_f32'
   *  Constant: '<S61>/CAL_Hspf_tSwtTempSttrLoLim_f32'
   *  Constant: '<S61>/Constant2'
   *  RelationalOperator: '<S61>/Relational Operator'
   *  RelationalOperator: '<S61>/Relational Operator1'
   *  Switch: '<S61>/Switch2'
   *  UnitDelay: '<S61>/Unit Delay'
   */
  if (VAR_Hspf_tStrrTemp2_s16 >= CAL_Hspf_tSwtTempSttrHiLim_f32) {
    SWC_HSPF_DW.UnitDelay_DSTATE = 1.0;
  } else {
    if (VAR_Hspf_tStrrTemp2_s16 <= CAL_Hspf_tSwtTempSttrLoLim_f32) {
      /* Switch: '<S61>/Switch2' incorporates:
       *  Constant: '<S61>/Constant3'
       *  UnitDelay: '<S61>/Unit Delay'
       */
      SWC_HSPF_DW.UnitDelay_DSTATE = 0.0;
    }
  }

  /* End of Switch: '<S61>/Switch1' */

  /* Logic: '<S61>/Logical Operator' incorporates:
   *  UnitDelay: '<S61>/Unit Delay'
   */
  VAR_Hspf_bSwtTempSttr2_b = (SWC_HSPF_DW.UnitDelay_DSTATE == 0.0);

  /* FunctionCaller: '<S1>/RP_SWC_IoHwAb_DIO_Set_HSPF_flgSwtTSttr2_IoHwAb_DIO_Set' incorporates:
   *  Constant: '<S1>/Constant11'
   */
  Rte_Call_RP_SWC_IoHwAb_DIO_Set_HSPF_flgSwtTSttr2_IoHwAb_DIO_Set(22,
    VAR_Hspf_bSwtTempSttr2_b);

  /* FunctionCaller: '<S1>/RP_SWC_IoHwAb_ADC_BSW_HwVer_IoHwAb_ADC_GetPhyVoltage' incorporates:
   *  Constant: '<S1>/Constant9'
   */
  Rte_Call_RP_SWC_IoHwAb_ADC_BSW_HwVer_IoHwAb_ADC_GetPhyVoltage(29,
    &VAR_Bsw_Hwver_f32);

  /* SignalConversion generated from: '<S1>/RP_SWC_Cpld_Cpld_CpldSwVer_read' incorporates:
   *  Inport: '<Root>/RP_SWC_Cpld_Cpld_CpldSwVer'
   */
  Rte_Read_RP_SWC_Cpld_Cpld_CpldSwVer(&rtb_TmpSignalConversionAtRP_S_g);

  /* SignalConversion generated from: '<S1>/RP_SWC_HvMcu_HvMcu_HvMcuVer_read' incorporates:
   *  Inport: '<Root>/RP_SWC_HvMcu_HvMcu_HvMcuVer'
   */
  Rte_Read_RP_SWC_HvMcu_HvMcu_HvMcuVer(&rtb_TmpSignalConversionAtRP_S_e);

  /* Outputs for Enabled SubSystem: '<S8>/HspfVerChk' incorporates:
   *  EnablePort: '<S43>/Enable'
   */
  /* RelationalOperator: '<S42>/Compare' incorporates:
   *  Constant: '<S42>/Constant'
   *  UnitDelay: '<S8>/Unit Delay2'
   */
  if (VAR_Hspf_stVerChk_u8 == CAL_Hspf_VerMatchUncheck_u8) {
    /* Switch: '<S43>/Switch3' incorporates:
     *  Constant: '<S43>/CAL_Hspf_VerMatchUncheck_u8'
     *  Constant: '<S46>/Constant'
     *  Constant: '<S47>/Constant'
     *  Inport: '<Root>/RP_SWC_Cpld_Cpld_ProjectNum'
     *  Logic: '<S43>/Logical Operator3'
     *  RelationalOperator: '<S46>/Compare'
     *  RelationalOperator: '<S47>/Compare'
     */
    if ((rtb_TmpSignalConversionAtRP_S_e == 0) ||
        (rtb_TmpSignalConversionAtRP_S_g == 0)) {
      VAR_Hspf_stVerChk_u8 = CAL_Hspf_VerMatchUncheck_u8;
    } else {
      Rte_Read_RP_SWC_Cpld_Cpld_ProjectNum(&tmpRead);

      /* S-Function (sfix_bitop): '<S43>/Bitwise Operator2' incorporates:
       *  ArithShift: '<S43>/c2'
       *  Constant: '<S43>/CAL_Hspf_Tc277Name_u64_3'
       *  Constant: '<S43>/sample2'
       *  Inport: '<Root>/RP_SWC_Cpld_Cpld_ProjectNum'
       */
      rtb_BitwiseOperator3 = CAL_Hspf_Tc277Name_u64 >> 8 & 4095ULL;

      /* Switch: '<S43>/Switch1' incorporates:
       *  ArithShift: '<S43>/c'
       *  ArithShift: '<S43>/c1'
       *  ArithShift: '<S43>/c3'
       *  Constant: '<S43>/CAL_Hspf_McuName_u64'
       *  Constant: '<S43>/CAL_Hspf_Tc277Name_u64'
       *  Constant: '<S43>/CAL_Hspf_Tc277Name_u64_2'
       *  Constant: '<S43>/CAL_Hspf_Tc277Name_u64_4'
       *  Constant: '<S43>/CAL_Hspf_VerMatchSucceed_u8'
       *  Constant: '<S43>/CAL_Spf_VerMatchFailure_u8'
       *  Constant: '<S43>/Constant11'
       *  Constant: '<S43>/Constant12'
       *  Constant: '<S43>/Constant13'
       *  Constant: '<S43>/Constant15'
       *  Constant: '<S43>/Constant2'
       *  Constant: '<S43>/sample'
       *  Constant: '<S43>/sample1'
       *  Constant: '<S43>/sample3'
       *  Constant: '<S43>/sample4'
       *  DataTypeConversion: '<S43>/Data Type Conversion1'
       *  DataTypeConversion: '<S43>/Data Type Conversion10'
       *  DataTypeConversion: '<S43>/Data Type Conversion2'
       *  DataTypeConversion: '<S43>/Data Type Conversion3'
       *  DataTypeConversion: '<S43>/Data Type Conversion4'
       *  DataTypeConversion: '<S43>/Data Type Conversion5'
       *  DataTypeConversion: '<S43>/Data Type Conversion6'
       *  DataTypeConversion: '<S43>/Data Type Conversion7'
       *  DataTypeConversion: '<S43>/Data Type Conversion8'
       *  Logic: '<S43>/Logical Operator'
       *  Lookup_n-D: '<S43>/2-D Lookup Table'
       *  Lookup_n-D: '<S43>/2-D Lookup Table1'
       *  Lookup_n-D: '<S43>/2-D Lookup Table2'
       *  Lookup_n-D: '<S43>/2-D Lookup Table3'
       *  Lookup_n-D: '<S43>/2-D Lookup Table4'
       *  RelationalOperator: '<S43>/Relational Operator'
       *  RelationalOperator: '<S43>/Relational Operator1'
       *  RelationalOperator: '<S43>/Relational Operator2'
       *  RelationalOperator: '<S43>/Relational Operator3'
       *  RelationalOperator: '<S43>/Relational Operator4'
       *  RelationalOperator: '<S43>/Relational Operator5'
       *  S-Function (sfix_bitop): '<S43>/Bitwise Operator'
       *  S-Function (sfix_bitop): '<S43>/Bitwise Operator1'
       *  S-Function (sfix_bitop): '<S43>/Bitwise Operator3'
       *  S-Function (sfix_bitop): '<S43>/Bitwise Operator4'
       */
      if ((look2_iflf_binlxpw(rtb_TmpSignalConversionAtRP_S_g, (float32)
                              rtb_BitwiseOperator3, ((const float32 *)
             &(CAL_Hspf_CpldSwTable_af32[0])), ((const float32 *)
             &(CAL_Hspf_CodeTable_af32[0])), ((const float32 *)
             &(CAL_Hspf_CodeCpldSwMatchTable_af32[0])),
                              rtCP_uDLookupTable2_maxIndex, 4U) == 100.0F) &&
          (look2_iflf_binlxpw(rtb_TmpSignalConversionAtRP_S_e, (float32)
                              rtb_BitwiseOperator3, ((const float32 *)
             &(CAL_Hspf_HvMcuTable_af32[0])), ((const float32 *)
             &(CAL_Hspf_CodeTable_af32[0])), ((const float32 *)
             &(CAL_Hspf_CodeHvMcuMatchTable_af32[0])),
                              rtCP_uDLookupTable3_maxIndex, 6U) == 100.0F) &&
          (look2_iflf_binlxpw((float32)(CAL_Hspf_Tc277Name_u64 & 15ULL),
                              (float32)rtb_BitwiseOperator3, ((const float32 *)
             &(CAL_Hspf_DataTable_af32[0])), ((const float32 *)
             &(CAL_Hspf_CodeTable_af32[0])), ((const float32 *)
             &(CAL_Hspf_CodeDataMatchTable_af32[0])),
                              rtCP_uDLookupTable_maxIndex, 6U) == 100.0F) &&
          (look2_iflf_binlxpw((float32)((CAL_Hspf_McuName_u64 >> 24 & 255ULL) ==
             (CAL_Hspf_Tc277Name_u64 >> 24 & 255ULL)), VAR_Bsw_Hwver_f32, ((
              const float32 *)&(CAL_Hspf_HwAnalTable_af32[0])), ((const float32 *)
             &(CAL_Hspf_HwVerTable_af32[0])), ((const float32 *)
             &(CAL_Hspf_HwAnalHwVerMatchTable_af32[0])),
                              rtCP_uDLookupTable4_maxIndex, 2U) == 100.0F) &&
          (look2_iflf_binlxpw(tmpRead, (float32)(CAL_Hspf_Tc277Name_u64 >> 32 &
             15ULL), ((const float32 *)&(CAL_Hspf_CPLDProjectNumTable_af32[0])),
            ((const float32 *)&(CAL_Hspf_ProjectNuminSWTable_af32[0])), ((const
              float32 *)&(CAL_Hspf_ProjectNumMatchTable_af32[0])),
                              rtCP_uDLookupTable1_maxIndex, 6U) == 100.0F)) {
        VAR_Hspf_stVerChk_u8 = CAL_Hspf_VerMatchSucceed_u8;
      } else {
        VAR_Hspf_stVerChk_u8 = CAL_Hspf_VerMatchFailure_u8;
      }

      /* End of Switch: '<S43>/Switch1' */
    }

    /* End of Switch: '<S43>/Switch3' */

    /* RelationalOperator: '<S44>/Compare' incorporates:
     *  Constant: '<S44>/Constant'
     */
    rtb_Compare_p = (VAR_Hspf_stVerChk_u8 == CAL_Hspf_VerMatchUncheck_u8);

    /* Sum: '<S43>/Add4' incorporates:
     *  Switch: '<S43>/Switch5'
     *  UnitDelay: '<S43>/Unit Delay'
     */
    SWC_HSPF_DW.UnitDelay_DSTATE_nh = (uint16)((uint32)rtb_Compare_p +
      SWC_HSPF_DW.UnitDelay_DSTATE_nh);

    /* Switch: '<S43>/Switch4' */
    if (rtb_Compare_p) {
      /* Switch: '<S43>/Switch6' incorporates:
       *  Constant: '<S43>/Constant11 '
       *  Constant: '<S45>/Constant'
       *  RelationalOperator: '<S45>/Compare'
       *  UnitDelay: '<S43>/Unit Delay'
       */
      if (SWC_HSPF_DW.UnitDelay_DSTATE_nh >= CAL_Hspf_VerChkTime_u16) {
        VAR_Hspf_stVerChk_u8 = CAL_Hspf_VerMatchTimeOutErr_u8;
      }

      /* End of Switch: '<S43>/Switch6' */
    }

    /* End of Switch: '<S43>/Switch4' */

    /* Sum: '<S43>/Add1' incorporates:
     *  Constant: '<S43>/CAL_Hspf_VerMatchFailure_u8'
     *  Constant: '<S43>/Constant3'
     *  RelationalOperator: '<S43>/Relational Operator8'
     */
    VAR_Hspf_VerMatchFailureErr_u8 = (uint8)((VAR_Hspf_stVerChk_u8 ==
      CAL_Hspf_VerMatchFailure_u8) + 2U);

    /* DataTypeConversion: '<S43>/Data Type Conversion' */
    rtb_Divide = fmodf(floorf(VAR_Bsw_Hwver_f32), 256.0F);
    VAR_Hspf_HWVer_u8 = (uint8)(rtb_Divide < 0.0F ? (sint32)(uint8)-(sint8)
      (uint8)-rtb_Divide : (sint32)(uint8)rtb_Divide);
  }

  /* End of RelationalOperator: '<S42>/Compare' */
  /* End of Outputs for SubSystem: '<S8>/HspfVerChk' */

  /* FunctionCaller: '<S1>/RP_SWC_DEM_HSPF_VerMatchFailureFail_SetEventStatus' */
  Rte_Call_RP_SWC_DEM_HSPF_VerMatchFailureFail_SetEventStatus
    (VAR_Hspf_VerMatchFailureErr_u8);

  /* FunctionCaller: '<S1>/RP_SWC_IoHwAb_DIO_Get_BSW_flgMcuOpen_IoHwAb_DIO_Get' incorporates:
   *  Constant: '<S1>/Constant7'
   */
  Rte_Call_RP_SWC_IoHwAb_DIO_Get_BSW_flgMcuOpen_IoHwAb_DIO_Get(340,
    &VAR_Bsw_INV_Open_b);

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S26>/CAL_Hspf_INVOpenChkSubCnt_s8'
   *  Switch: '<S26>/Switch1'
   *  UnitDelay: '<S26>/Unit Delay3'
   */
  if (VAR_Bsw_INV_Open_b) {
    /* Switch: '<S26>/Switch2' incorporates:
     *  Constant: '<S26>/CAL_Hspf_INVOpenChkAddCnt_u8'
     *  Constant: '<S26>/Constant3'
     *  UnitDelay: '<S26>/Unit Delay1'
     */
    if (SWC_HSPF_DW.UnitDelay1_DSTATE_mm) {
      tmp_1 = 0;
    } else {
      tmp_1 = CAL_Hspf_INVOpenChkAddCnt_u8;
    }

    /* End of Switch: '<S26>/Switch2' */
  } else if (SWC_HSPF_DW.UnitDelay3_DSTATE_a5) {
    /* Switch: '<S26>/Switch1' incorporates:
     *  Constant: '<S26>/Constant2'
     */
    tmp_1 = 0;
  } else {
    tmp_1 = CAL_Hspf_INVOpenChkSubCnt_s8;
  }

  /* End of Switch: '<S26>/Switch' */

  /* Sum: '<S26>/Add' incorporates:
   *  UnitDelay: '<S26>/Unit Delay'
   */
  SWC_HSPF_DW.UnitDelay_DSTATE_a += (float64)tmp_1;

  /* RelationalOperator: '<S26>/Relational Operator' incorporates:
   *  Constant: '<S26>/CAL_Hspf_INVOpenChkCntHiLim_u8'
   *  UnitDelay: '<S26>/Unit Delay'
   *  UnitDelay: '<S26>/Unit Delay1'
   */
  SWC_HSPF_DW.UnitDelay1_DSTATE_mm = (SWC_HSPF_DW.UnitDelay_DSTATE_a >=
    CAL_Hspf_INVOpenChkCntHiLim_u8);

  /* RelationalOperator: '<S26>/Relational Operator1' incorporates:
   *  Constant: '<S26>/CAL_Hspf_INVOpenChkCntLoLim_s8'
   *  UnitDelay: '<S26>/Unit Delay'
   *  UnitDelay: '<S26>/Unit Delay3'
   */
  SWC_HSPF_DW.UnitDelay3_DSTATE_a5 = (SWC_HSPF_DW.UnitDelay_DSTATE_a <=
    CAL_Hspf_INVOpenChkCntLoLim_s8);

  /* Switch: '<S26>/Switch3' incorporates:
   *  Constant: '<S26>/Constant4'
   *  Switch: '<S26>/Switch4'
   *  UnitDelay: '<S26>/Unit Delay1'
   *  UnitDelay: '<S26>/Unit Delay2'
   *  UnitDelay: '<S26>/Unit Delay3'
   */
  if (SWC_HSPF_DW.UnitDelay1_DSTATE_mm) {
    SWC_HSPF_DW.UnitDelay2_DSTATE_o = true;
  } else {
    SWC_HSPF_DW.UnitDelay2_DSTATE_o = ((!SWC_HSPF_DW.UnitDelay3_DSTATE_a5) &&
      SWC_HSPF_DW.UnitDelay2_DSTATE_o);
  }

  /* End of Switch: '<S26>/Switch3' */

  /* FunctionCaller: '<S1>/RP_SWC_Dem_HSPF_InvOpenFail_SetEventStatus' incorporates:
   *  Constant: '<S14>/Constant29'
   *  RelationalOperator: '<S16>/Compare'
   *  Sum: '<S14>/Add4'
   */
  Rte_Call_RP_SWC_Dem_HSPF_InvOpenFail_SetEventStatus((uint8)
    (!SWC_HSPF_DW.UnitDelay2_DSTATE_o + 2U));

  /* SignalConversion generated from: '<S1>/RP_SWC_SCF_SCF_stPreDrvCtl_read' incorporates:
   *  Inport: '<Root>/RP_SWC_SCF_SCF_stPreDrvCtl'
   */
  Rte_Read_RP_SWC_SCF_SCF_stPreDrvCtl(&rtb_TmpSignalConversionAtRP_S_o);

  /* Outputs for Enabled SubSystem: '<S5>/IPhaSenOffCal1' incorporates:
   *  EnablePort: '<S21>/Enable'
   */
  /* UnitDelay: '<S5>/Unit Delay' */
  if (SWC_HSPF_DW.UnitDelay_DSTATE_e) {
    /* Chart: '<S21>/UIPhaSenOffCal' incorporates:
     *  Constant: '<S21>/CAL_CSP_cntIPhCalOffValCnt_u16'
     *  Constant: '<S21>/CAL_Hspf_stPreDrvCtl_u8'
     *  Inport: '<Root>/RP_SWC_PhC_PhC_iUNoOff'
     */
    if (SWC_HSPF_DW.is_active_c2_SWC_HSPF == 0U) {
      SWC_HSPF_DW.is_active_c2_SWC_HSPF = 1U;
      SWC_HSPF_DW.is_c2_SWC_HSPF = SWC_HSPF_IN_OffstCalInit;
    } else {
      Rte_Read_RP_SWC_PhC_PhC_iUNoOff(&tmpRead_0);
      guard1 = false;
      switch (SWC_HSPF_DW.is_c2_SWC_HSPF) {
       case SWC_HSPF_IN_OffstCalFishd:
        if (rtb_TmpSignalConversionAtRP_S_o != CAL_Hspf_stPreDrvCtl_u8) {
          SWC_HSPF_DW.is_c2_SWC_HSPF = SWC_HSPF_IN_OffstCalInit;
        }
        break;

       case SWC_HSPF_IN_OffstCalInit:
        if (rtb_TmpSignalConversionAtRP_S_o == CAL_Hspf_stPreDrvCtl_u8) {
          SWC_HSPF_DW.cntSelfChkTolCnt_f = 0U;
          SWC_HSPF_B.HSPF_iOffset_c = 0.0F;
          SWC_HSPF_B.flgOfsClb_n = false;
          SWC_HSPF_B.stiOfsClb_o = ((uint8)CAL_Hspf_Uncheck_u8);
          SWC_HSPF_DW.is_c2_SWC_HSPF = SWC_HSPF_IN_OffstCalRun;
          SWC_HSPF_DW.cntSelfChkValCnt_n = 0U;
          SWC_HSPF_DW.iValSum_i = 0U;
        }
        break;

       default:
        /* case IN_OffstCalRun: */
        if (rtb_TmpSignalConversionAtRP_S_o != CAL_Hspf_stPreDrvCtl_u8) {
          SWC_HSPF_DW.is_c2_SWC_HSPF = SWC_HSPF_IN_OffstCalInit;
        } else if (((tmpRead_0 > CAL_Hspf_iPhaHighSet_u16) || (tmpRead_0 <
                     CAL_Hspf_iPhaLowSet_u16)) &&
                   (SWC_HSPF_DW.cntSelfChkTolCnt_f <
                    CAL_Hspf_cntIPhCalOffTolCnt_u16)) {
          tmp_1 = SWC_HSPF_DW.cntSelfChkTolCnt_f + 1;
          if (tmp_1 > 65535) {
            tmp_1 = 65535;
          }

          SWC_HSPF_DW.cntSelfChkTolCnt_f = (uint16)tmp_1;
          SWC_HSPF_DW.is_c2_SWC_HSPF = SWC_HSPF_IN_OffstCalRun;
          SWC_HSPF_DW.cntSelfChkValCnt_n = 0U;
          SWC_HSPF_DW.iValSum_i = 0U;
        } else {
          tmp_1 = SWC_HSPF_DW.cntSelfChkTolCnt_f + 1;
          if (tmp_1 > 65535) {
            tmp_1 = 65535;
          }

          SWC_HSPF_DW.cntSelfChkTolCnt_f = (uint16)tmp_1;
          tmp_1 = SWC_HSPF_DW.cntSelfChkValCnt_n + 1;
          if (tmp_1 > 65535) {
            tmp_1 = 65535;
          }

          SWC_HSPF_DW.cntSelfChkValCnt_n = (uint16)tmp_1;
          qY = SWC_HSPF_DW.iValSum_i + /*MW:OvSatOk*/ tmpRead_0;
          if (qY < SWC_HSPF_DW.iValSum_i) {
            qY = MAX_uint32_T;
          }

          SWC_HSPF_DW.iValSum_i = qY;
          if (SWC_HSPF_DW.cntSelfChkTolCnt_f > CAL_Hspf_cntIPhCalOffTolCnt_u16)
          {
            SWC_HSPF_B.stiOfsClb_o = ((uint8)CAL_Hspf_Failure_u8);
            guard1 = true;
          } else {
            if (SWC_HSPF_DW.cntSelfChkValCnt_n >=
                CAL_Hspf_cntIPhCalOffValCnt_u16) {
              SWC_HSPF_B.stiOfsClb_o = ((uint8)CAL_Hspf_Succeed_u8);
              SWC_HSPF_B.HSPF_iOffset_c = (float32)SWC_HSPF_DW.iValSum_i /
                (float32)CAL_Hspf_cntIPhCalOffValCnt_u16;
              guard1 = true;
            }
          }
        }
        break;
      }

      if (guard1) {
        SWC_HSPF_DW.is_c2_SWC_HSPF = SWC_HSPF_IN_OffstCalFishd;
        SWC_HSPF_B.flgOfsClb_n = true;
      }
    }

    /* End of Chart: '<S21>/UIPhaSenOffCal' */

    /* Chart: '<S21>/VIPhaSenOffCal' incorporates:
     *  Constant: '<S21>/CAL_CSP_cntIPhCalOffValCnt_u16'
     *  Constant: '<S21>/CAL_Hspf_stPreDrvCtl_u8'
     *  Inport: '<Root>/RP_SWC_PhC_PhC_iVNoOff'
     */
    if (SWC_HSPF_DW.is_active_c1_SWC_HSPF == 0U) {
      SWC_HSPF_DW.is_active_c1_SWC_HSPF = 1U;
      SWC_HSPF_DW.is_c1_SWC_HSPF = SWC_HSPF_IN_OffstCalInit;
    } else {
      Rte_Read_RP_SWC_PhC_PhC_iVNoOff(&tmpRead_1);
      guard1 = false;
      switch (SWC_HSPF_DW.is_c1_SWC_HSPF) {
       case SWC_HSPF_IN_OffstCalFishd:
        if (rtb_TmpSignalConversionAtRP_S_o != CAL_Hspf_stPreDrvCtl_u8) {
          SWC_HSPF_DW.is_c1_SWC_HSPF = SWC_HSPF_IN_OffstCalInit;
        }
        break;

       case SWC_HSPF_IN_OffstCalInit:
        if (rtb_TmpSignalConversionAtRP_S_o == CAL_Hspf_stPreDrvCtl_u8) {
          SWC_HSPF_DW.cntSelfChkTolCnt_n = 0U;
          SWC_HSPF_B.HSPF_iOffset_i = 0.0F;
          SWC_HSPF_B.flgOfsClb_a = false;
          SWC_HSPF_B.stiOfsClb_n = ((uint8)CAL_Hspf_Uncheck_u8);
          SWC_HSPF_DW.is_c1_SWC_HSPF = SWC_HSPF_IN_OffstCalRun;
          SWC_HSPF_DW.cntSelfChkValCnt_i = 0U;
          SWC_HSPF_DW.iValSum_e = 0U;
        }
        break;

       default:
        /* case IN_OffstCalRun: */
        if (rtb_TmpSignalConversionAtRP_S_o != CAL_Hspf_stPreDrvCtl_u8) {
          SWC_HSPF_DW.is_c1_SWC_HSPF = SWC_HSPF_IN_OffstCalInit;
        } else if (((tmpRead_1 > CAL_Hspf_iPhaHighSet_u16) || (tmpRead_1 <
                     CAL_Hspf_iPhaLowSet_u16)) &&
                   (SWC_HSPF_DW.cntSelfChkTolCnt_n <
                    CAL_Hspf_cntIPhCalOffTolCnt_u16)) {
          tmp_1 = SWC_HSPF_DW.cntSelfChkTolCnt_n + 1;
          if (tmp_1 > 65535) {
            tmp_1 = 65535;
          }

          SWC_HSPF_DW.cntSelfChkTolCnt_n = (uint16)tmp_1;
          SWC_HSPF_DW.is_c1_SWC_HSPF = SWC_HSPF_IN_OffstCalRun;
          SWC_HSPF_DW.cntSelfChkValCnt_i = 0U;
          SWC_HSPF_DW.iValSum_e = 0U;
        } else {
          tmp_1 = SWC_HSPF_DW.cntSelfChkTolCnt_n + 1;
          if (tmp_1 > 65535) {
            tmp_1 = 65535;
          }

          SWC_HSPF_DW.cntSelfChkTolCnt_n = (uint16)tmp_1;
          tmp_1 = SWC_HSPF_DW.cntSelfChkValCnt_i + 1;
          if (tmp_1 > 65535) {
            tmp_1 = 65535;
          }

          SWC_HSPF_DW.cntSelfChkValCnt_i = (uint16)tmp_1;
          qY = SWC_HSPF_DW.iValSum_e + /*MW:OvSatOk*/ tmpRead_1;
          if (qY < SWC_HSPF_DW.iValSum_e) {
            qY = MAX_uint32_T;
          }

          SWC_HSPF_DW.iValSum_e = qY;
          if (SWC_HSPF_DW.cntSelfChkTolCnt_n > CAL_Hspf_cntIPhCalOffTolCnt_u16)
          {
            SWC_HSPF_B.stiOfsClb_n = ((uint8)CAL_Hspf_Failure_u8);
            guard1 = true;
          } else {
            if (SWC_HSPF_DW.cntSelfChkValCnt_i >=
                CAL_Hspf_cntIPhCalOffValCnt_u16) {
              SWC_HSPF_B.stiOfsClb_n = ((uint8)CAL_Hspf_Succeed_u8);
              SWC_HSPF_B.HSPF_iOffset_i = (float32)SWC_HSPF_DW.iValSum_e /
                (float32)CAL_Hspf_cntIPhCalOffValCnt_u16;
              guard1 = true;
            }
          }
        }
        break;
      }

      if (guard1) {
        SWC_HSPF_DW.is_c1_SWC_HSPF = SWC_HSPF_IN_OffstCalFishd;
        SWC_HSPF_B.flgOfsClb_a = true;
      }
    }

    /* End of Chart: '<S21>/VIPhaSenOffCal' */

    /* Chart: '<S21>/WIPhaSenOffCal' incorporates:
     *  Constant: '<S21>/CAL_CSP_cntIPhCalOffValCnt_u16'
     *  Constant: '<S21>/CAL_Hspf_stPreDrvCtl_u8'
     *  Inport: '<Root>/RP_SWC_PhC_PhC_iWNoOff'
     */
    if (SWC_HSPF_DW.is_active_c5_SWC_HSPF == 0U) {
      SWC_HSPF_DW.is_active_c5_SWC_HSPF = 1U;
      SWC_HSPF_DW.is_c5_SWC_HSPF = SWC_HSPF_IN_OffstCalInit;
    } else {
      Rte_Read_RP_SWC_PhC_PhC_iWNoOff(&tmpRead_2);
      guard1 = false;
      switch (SWC_HSPF_DW.is_c5_SWC_HSPF) {
       case SWC_HSPF_IN_OffstCalFishd:
        if (rtb_TmpSignalConversionAtRP_S_o != CAL_Hspf_stPreDrvCtl_u8) {
          SWC_HSPF_DW.is_c5_SWC_HSPF = SWC_HSPF_IN_OffstCalInit;
        }
        break;

       case SWC_HSPF_IN_OffstCalInit:
        if (rtb_TmpSignalConversionAtRP_S_o == CAL_Hspf_stPreDrvCtl_u8) {
          SWC_HSPF_DW.cntSelfChkTolCnt = 0U;
          SWC_HSPF_B.HSPF_iOffset = 0.0F;
          SWC_HSPF_B.flgOfsClb = false;
          SWC_HSPF_B.stiOfsClb = ((uint8)CAL_Hspf_Uncheck_u8);
          SWC_HSPF_DW.is_c5_SWC_HSPF = SWC_HSPF_IN_OffstCalRun;
          SWC_HSPF_DW.cntSelfChkValCnt = 0U;
          SWC_HSPF_DW.iValSum = 0U;
        }
        break;

       default:
        /* case IN_OffstCalRun: */
        if (rtb_TmpSignalConversionAtRP_S_o != CAL_Hspf_stPreDrvCtl_u8) {
          SWC_HSPF_DW.is_c5_SWC_HSPF = SWC_HSPF_IN_OffstCalInit;
        } else if (((tmpRead_2 > CAL_Hspf_iPhaHighSet_u16) || (tmpRead_2 <
                     CAL_Hspf_iPhaLowSet_u16)) && (SWC_HSPF_DW.cntSelfChkTolCnt <
                    CAL_Hspf_cntIPhCalOffTolCnt_u16)) {
          tmp_1 = SWC_HSPF_DW.cntSelfChkTolCnt + 1;
          if (tmp_1 > 65535) {
            tmp_1 = 65535;
          }

          SWC_HSPF_DW.cntSelfChkTolCnt = (uint16)tmp_1;
          SWC_HSPF_DW.is_c5_SWC_HSPF = SWC_HSPF_IN_OffstCalRun;
          SWC_HSPF_DW.cntSelfChkValCnt = 0U;
          SWC_HSPF_DW.iValSum = 0U;
        } else {
          tmp_1 = SWC_HSPF_DW.cntSelfChkTolCnt + 1;
          if (tmp_1 > 65535) {
            tmp_1 = 65535;
          }

          SWC_HSPF_DW.cntSelfChkTolCnt = (uint16)tmp_1;
          tmp_1 = SWC_HSPF_DW.cntSelfChkValCnt + 1;
          if (tmp_1 > 65535) {
            tmp_1 = 65535;
          }

          SWC_HSPF_DW.cntSelfChkValCnt = (uint16)tmp_1;
          qY = SWC_HSPF_DW.iValSum + /*MW:OvSatOk*/ tmpRead_2;
          if (qY < SWC_HSPF_DW.iValSum) {
            qY = MAX_uint32_T;
          }

          SWC_HSPF_DW.iValSum = qY;
          if (SWC_HSPF_DW.cntSelfChkTolCnt > CAL_Hspf_cntIPhCalOffTolCnt_u16) {
            SWC_HSPF_B.stiOfsClb = ((uint8)CAL_Hspf_Failure_u8);
            guard1 = true;
          } else {
            if (SWC_HSPF_DW.cntSelfChkValCnt >= CAL_Hspf_cntIPhCalOffValCnt_u16)
            {
              SWC_HSPF_B.stiOfsClb = ((uint8)CAL_Hspf_Succeed_u8);
              SWC_HSPF_B.HSPF_iOffset = (float32)SWC_HSPF_DW.iValSum / (float32)
                CAL_Hspf_cntIPhCalOffValCnt_u16;
              guard1 = true;
            }
          }
        }
        break;
      }

      if (guard1) {
        SWC_HSPF_DW.is_c5_SWC_HSPF = SWC_HSPF_IN_OffstCalFishd;
        SWC_HSPF_B.flgOfsClb = true;
      }
    }

    /* End of Chart: '<S21>/WIPhaSenOffCal' */

    /* Logic: '<S21>/Logical Operator' */
    rtb_Compare_p = (SWC_HSPF_B.flgOfsClb_n && SWC_HSPF_B.flgOfsClb_a &&
                     SWC_HSPF_B.flgOfsClb);

    /* Logic: '<S21>/Logical Operator2' */
    SWC_HSPF_B.LogicalOperator2 = !rtb_Compare_p;

    /* Switch: '<S21>/Switch' incorporates:
     *  Constant: '<S21>/CAL_Hspf_Uncheck_u8'
     */
    if (rtb_Compare_p) {
      /* Switch: '<S21>/Switch1' incorporates:
       *  Constant: '<S21>/CAL_Hspf_Failure_u8'
       *  Constant: '<S21>/CAL_Hspf_Succeed_u8'
       *  Logic: '<S21>/Logical Operator1'
       *  RelationalOperator: '<S21>/Relational Operator'
       *  RelationalOperator: '<S21>/Relational Operator1'
       *  RelationalOperator: '<S21>/Relational Operator2'
       */
      if ((SWC_HSPF_B.stiOfsClb_n == ((uint8)CAL_Hspf_Succeed_u8)) &&
          (SWC_HSPF_B.stiOfsClb == ((uint8)CAL_Hspf_Succeed_u8)) &&
          (SWC_HSPF_B.stiOfsClb_o == ((uint8)CAL_Hspf_Succeed_u8))) {
        SWC_HSPF_B.Switch = ((uint8)CAL_Hspf_Succeed_u8);
      } else {
        SWC_HSPF_B.Switch = ((uint8)CAL_Hspf_Failure_u8);
      }

      /* End of Switch: '<S21>/Switch1' */
    } else {
      SWC_HSPF_B.Switch = ((uint8)CAL_Hspf_Uncheck_u8);
    }

    /* End of Switch: '<S21>/Switch' */

    /* Switch: '<S21>/Switch2' incorporates:
     *  Constant: '<S21>/CAL_Hspf_Failure_u8'
     *  Constant: '<S21>/failure'
     *  Constant: '<S21>/pass'
     *  RelationalOperator: '<S21>/Relational Operator3'
     */
    if (SWC_HSPF_B.Switch == ((uint8)CAL_Hspf_Failure_u8)) {
      SWC_HSPF_B.Switch2 = 3U;
    } else {
      SWC_HSPF_B.Switch2 = 2U;
    }

    /* End of Switch: '<S21>/Switch2' */
  }

  /* End of UnitDelay: '<S5>/Unit Delay' */
  /* End of Outputs for SubSystem: '<S5>/IPhaSenOffCal1' */

  /* FunctionCaller: '<S1>/RP_SWC_Dem_HSPF_IphaOffCalFail_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_HSPF_IphaOffCalFail_SetEventStatus(SWC_HSPF_B.Switch2);

  /* FunctionCaller: '<S1>/RP_SWC_IoHwAb_DIO_Get_BSW_flgMotorOpen_IoHwAb_DIO_Get' incorporates:
   *  Constant: '<S1>/Constant8'
   */
  Rte_Call_RP_SWC_IoHwAb_DIO_Get_BSW_flgMotorOpen_IoHwAb_DIO_Get(19,
    &VAR_Bsw_Motor_Open_b);

  /* Switch: '<S27>/Switch' incorporates:
   *  Constant: '<S27>/CAL_Hspf_MototOpenChkSubCnt_s8'
   *  Switch: '<S27>/Switch1'
   *  UnitDelay: '<S27>/Unit Delay3'
   */
  if (VAR_Bsw_Motor_Open_b) {
    /* Switch: '<S27>/Switch2' incorporates:
     *  Constant: '<S27>/CAL_Hspf_MotorOpenChkAddCnt_u8'
     *  Constant: '<S27>/Constant3'
     *  UnitDelay: '<S27>/Unit Delay1'
     */
    if (SWC_HSPF_DW.UnitDelay1_DSTATE_a) {
      tmp_1 = 0;
    } else {
      tmp_1 = CAL_Hspf_MotorOpenChkAddCnt_u8;
    }

    /* End of Switch: '<S27>/Switch2' */
  } else if (SWC_HSPF_DW.UnitDelay3_DSTATE_e) {
    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S27>/Constant2'
     */
    tmp_1 = 0;
  } else {
    tmp_1 = CAL_Hspf_MototOpenChkSubCnt_s8;
  }

  /* End of Switch: '<S27>/Switch' */

  /* Sum: '<S27>/Add' incorporates:
   *  UnitDelay: '<S27>/Unit Delay'
   */
  SWC_HSPF_DW.UnitDelay_DSTATE_d += (float64)tmp_1;

  /* RelationalOperator: '<S27>/Relational Operator' incorporates:
   *  Constant: '<S27>/CAL_Hspf_MotorOpenChkCntHiLim_u8'
   *  UnitDelay: '<S27>/Unit Delay'
   *  UnitDelay: '<S27>/Unit Delay1'
   */
  SWC_HSPF_DW.UnitDelay1_DSTATE_a = (SWC_HSPF_DW.UnitDelay_DSTATE_d >=
    CAL_Hspf_MotorOpenChkCntHiLim_u8);

  /* RelationalOperator: '<S27>/Relational Operator1' incorporates:
   *  Constant: '<S27>/CAL_Hspf_MotorOpenChkCntLoLim_s8'
   *  UnitDelay: '<S27>/Unit Delay'
   *  UnitDelay: '<S27>/Unit Delay3'
   */
  SWC_HSPF_DW.UnitDelay3_DSTATE_e = (SWC_HSPF_DW.UnitDelay_DSTATE_d <=
    CAL_Hspf_MotorOpenChkCntLoLim_s8);

  /* Switch: '<S27>/Switch3' incorporates:
   *  Constant: '<S27>/Constant4'
   *  Switch: '<S27>/Switch4'
   *  UnitDelay: '<S27>/Unit Delay1'
   *  UnitDelay: '<S27>/Unit Delay2'
   *  UnitDelay: '<S27>/Unit Delay3'
   */
  if (SWC_HSPF_DW.UnitDelay1_DSTATE_a) {
    SWC_HSPF_DW.UnitDelay2_DSTATE_l = true;
  } else {
    SWC_HSPF_DW.UnitDelay2_DSTATE_l = ((!SWC_HSPF_DW.UnitDelay3_DSTATE_e) &&
      SWC_HSPF_DW.UnitDelay2_DSTATE_l);
  }

  /* End of Switch: '<S27>/Switch3' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_HSPF_10ms' */

  /* Inport: '<Root>/RP_SWC_MDF_MDF_bFaultEMBlkWarnSt' */
  Rte_Read_RP_SWC_MDF_MDF_bFaultEMBlkWarnSt(&tmpRead_3);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_HSPF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_HSPF_10ms_sys'
   */
  /* Gain: '<S9>/Gain1' incorporates:
   *  Inport: '<Root>/RP_SWC_HvMcu_HvMcu_tDBCTempU'
   */
  Rte_Read_RP_SWC_HvMcu_HvMcu_tDBCTempU(&VAR_Bsw_tDBCTempU_u16);

  /* RelationalOperator: '<S15>/Compare' */
  rtb_Compare_p = !SWC_HSPF_DW.UnitDelay2_DSTATE_l;

  /* FunctionCaller: '<S1>/RP_SWC_Dem_HSPF_MotorOpenFail_SetEventStatus' incorporates:
   *  Constant: '<S13>/Constant29'
   *  DataTypeConversion: '<S13>/Data Type Conversion'
   *  Sum: '<S13>/Add4'
   */
  Rte_Call_RP_SWC_Dem_HSPF_MotorOpenFail_SetEventStatus((uint8)(rtb_Compare_p +
    2U));

  /* FunctionCaller: '<S1>/RP_SWC_FIM_HSPF_tDBCTempCmpErr_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_HSPF_tDBCTempCmpErr_GetFunctionPermission(&rtb_Compare_p);

  /* RelationalOperator: '<S19>/Compare' */
  rtb_Compare_os = rtb_Compare_p;

  /* LookupNDDirect: '<S53>/CAL_DBCTemLow_Table'
   *
   * About '<S53>/CAL_DBCTemLow_Table':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  if (VAR_Bsw_tDBCTempU_u16 < 4095) {
    rtb_TmpSignalConversionAtRP_S_e = VAR_Bsw_tDBCTempU_u16;
  } else {
    rtb_TmpSignalConversionAtRP_S_e = 4095U;
  }

  if (VAR_Bsw_tDBCTempU_u16 < 4095) {
    tmp_0 = VAR_Bsw_tDBCTempU_u16;
  } else {
    tmp_0 = 4095U;
  }

  /* Switch: '<S53>/Switch1' incorporates:
   *  Abs: '<S53>/Abs'
   *  Constant: '<S53>/CAL_Hspf_tDBCTempROCLim_u8'
   *  Constant: '<S53>/Constant6'
   *  LookupNDDirect: '<S53>/CAL_DBCTemLow_Table'
   *  RelationalOperator: '<S53>/Relational Operator4'
   *  Sum: '<S53>/Add'
   *  Sum: '<S53>/Subtract1'
   *  Switch: '<S53>/Switch3'
   *  UnitDelay: '<S53>/Unit Delay1'
   *  UnitDelay: '<S53>/Unit Delay2'
   *  UnitDelay: '<S53>/Unit Delay4'
   *
   * About '<S53>/CAL_DBCTemLow_Table':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  if (fabsf(rtCP_CAL_DBCTemLow_Table_table[tmp_0] -
            SWC_HSPF_DW.UnitDelay1_DSTATE_n) > CAL_Hspf_tDBCTempROCLim_u8) {
    SWC_HSPF_DW.UnitDelay2_DSTATE = 0.0;
  }

  SWC_HSPF_DW.UnitDelay2_DSTATE += (float64)!SWC_HSPF_DW.UnitDelay4_DSTATE_c;

  /* End of Switch: '<S53>/Switch1' */

  /* RelationalOperator: '<S53>/Relational Operator3' incorporates:
   *  Constant: '<S53>/CAL_Hspf_DBCTempROCLimChkCnt_u8'
   *  UnitDelay: '<S53>/Unit Delay2'
   *  UnitDelay: '<S53>/Unit Delay4'
   */
  SWC_HSPF_DW.UnitDelay4_DSTATE_c = (SWC_HSPF_DW.UnitDelay2_DSTATE >=
    CAL_Hspf_DBCTempROCLimChkCnt_u8);

  /* Switch: '<S53>/Switch2' incorporates:
   *  LookupNDDirect: '<S53>/CAL_DBCTemLow_Table'
   *  UnitDelay: '<S53>/Unit Delay4'
   *
   * About '<S53>/CAL_DBCTemLow_Table':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  if (SWC_HSPF_DW.UnitDelay4_DSTATE_c) {
    VAR_Hspf_tDBCTempU_f32 =
      rtCP_CAL_DBCTemLow_Table_table[rtb_TmpSignalConversionAtRP_S_e];
  }

  /* End of Switch: '<S53>/Switch2' */

  /* Product: '<S54>/Divide' incorporates:
   *  Constant: '<S9>/CAL_Hspf_TmpUFltFrq_f32'
   *  Constant: '<S9>/PRV_CalFltFrq_10ms_2'
   */
  rtb_Divide = (float32)((uint8)PRV_CalFltFrq_10ms) / CAL_Hspf_TmpUFltFrq_f32;

  /* Switch: '<S69>/Switch' incorporates:
   *  Constant: '<S54>/Constant'
   *  RelationalOperator: '<S69>/UpperRelop'
   *  Switch: '<S69>/Switch2'
   */
  if (rtb_Divide < 1.0F) {
    rtb_Divide = 1.0F;
  }

  /* End of Switch: '<S69>/Switch' */

  /* Gain: '<S9>/Gain2' incorporates:
   *  Inport: '<Root>/RP_SWC_HvMcu_HvMcu_tDBCTempV'
   */
  Rte_Read_RP_SWC_HvMcu_HvMcu_tDBCTempV(&VAR_Bsw_tDBCTempV_u16);

  /* Product: '<S54>/Product2' incorporates:
   *  Constant: '<S54>/CAL_Hspf_Multiple_u8'
   *  Constant: '<S54>/Constant2'
   *  Product: '<S30>/Product2'
   *  Product: '<S49>/Product2'
   *  Product: '<S50>/Product2'
   *  Product: '<S51>/Product2'
   *  Product: '<S56>/Product2'
   *  Product: '<S57>/Product2'
   *  Product: '<S58>/Product2'
   *  Product: '<S59>/Product2'
   *  Product: '<S60>/Product2'
   *  Product: '<S62>/Product2'
   *  Product: '<S63>/Product2'
   */
  rtb_UnitDelay_bz = GLB_HspfFlt_pi_f32 * (float32)CAL_Hspf_Multiple_u8;

  /* Product: '<S54>/Divide1' incorporates:
   *  Product: '<S54>/Product2'
   *  Sum: '<S54>/Add'
   */
  rtb_Divide /= rtb_UnitDelay_bz + rtb_Divide;

  /* Sum: '<S54>/Sum1' incorporates:
   *  Constant: '<S54>/One'
   *  Product: '<S54>/Product'
   *  Product: '<S54>/Product1'
   *  Sum: '<S54>/Subtract1'
   *  UnitDelay: '<S54>/Unit Delay'
   */
  SWC_HSPF_DW.UnitDelay_DSTATE_ci = (1.0F - rtb_Divide) * VAR_Hspf_tDBCTempU_f32
    + rtb_Divide * SWC_HSPF_DW.UnitDelay_DSTATE_ci;

  /* LookupNDDirect: '<S55>/CAL_DBCTemLow_Table'
   *
   * About '<S55>/CAL_DBCTemLow_Table':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  if (VAR_Bsw_tDBCTempV_u16 < 4095) {
    tmpRead_0 = VAR_Bsw_tDBCTempV_u16;
  } else {
    tmpRead_0 = 4095U;
  }

  if (VAR_Bsw_tDBCTempV_u16 < 4095) {
    tmp_0 = VAR_Bsw_tDBCTempV_u16;
  } else {
    tmp_0 = 4095U;
  }

  /* Switch: '<S55>/Switch1' incorporates:
   *  Abs: '<S55>/Abs'
   *  Constant: '<S55>/CAL_Hspf_tDBCTempROCLim_u8'
   *  Constant: '<S55>/Constant6'
   *  LookupNDDirect: '<S55>/CAL_DBCTemLow_Table'
   *  RelationalOperator: '<S55>/Relational Operator4'
   *  Sum: '<S55>/Add'
   *  Sum: '<S55>/Subtract1'
   *  Switch: '<S55>/Switch3'
   *  UnitDelay: '<S55>/Unit Delay1'
   *  UnitDelay: '<S55>/Unit Delay2'
   *  UnitDelay: '<S55>/Unit Delay4'
   *
   * About '<S55>/CAL_DBCTemLow_Table':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  if (fabsf(rtCP_CAL_DBCTemLow_Table_table_[tmp_0] -
            SWC_HSPF_DW.UnitDelay1_DSTATE_m) > CAL_Hspf_tDBCTempROCLim_u8) {
    SWC_HSPF_DW.UnitDelay2_DSTATE_i = 0.0;
  }

  SWC_HSPF_DW.UnitDelay2_DSTATE_i += (float64)!SWC_HSPF_DW.UnitDelay4_DSTATE_a;

  /* End of Switch: '<S55>/Switch1' */

  /* RelationalOperator: '<S55>/Relational Operator3' incorporates:
   *  Constant: '<S55>/CAL_Hspf_DBCTempROCLimChkCnt_u8'
   *  UnitDelay: '<S55>/Unit Delay2'
   *  UnitDelay: '<S55>/Unit Delay4'
   */
  SWC_HSPF_DW.UnitDelay4_DSTATE_a = (SWC_HSPF_DW.UnitDelay2_DSTATE_i >=
    CAL_Hspf_DBCTempROCLimChkCnt_u8);

  /* Switch: '<S55>/Switch2' incorporates:
   *  LookupNDDirect: '<S55>/CAL_DBCTemLow_Table'
   *  UnitDelay: '<S55>/Unit Delay4'
   *
   * About '<S55>/CAL_DBCTemLow_Table':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  if (SWC_HSPF_DW.UnitDelay4_DSTATE_a) {
    VAR_Hspf_tDBCTempV_f32 = rtCP_CAL_DBCTemLow_Table_table_[tmpRead_0];
  }

  /* End of Switch: '<S55>/Switch2' */

  /* Product: '<S56>/Divide' incorporates:
   *  Constant: '<S9>/CAL_Hspf_TmpVFltFrq_f32'
   *  Constant: '<S9>/PRV_CalFltFrq_10ms_3'
   */
  rtb_Divide = (float32)((uint8)PRV_CalFltFrq_10ms) / CAL_Hspf_TmpVFltFrq_f32;

  /* Switch: '<S70>/Switch' incorporates:
   *  Constant: '<S56>/Constant'
   *  RelationalOperator: '<S70>/UpperRelop'
   *  Switch: '<S70>/Switch2'
   */
  if (rtb_Divide < 1.0F) {
    rtb_Divide = 1.0F;
  }

  /* End of Switch: '<S70>/Switch' */

  /* Gain: '<S9>/Gain3' incorporates:
   *  Inport: '<Root>/RP_SWC_HvMcu_HvMcu_tDBCTempW'
   */
  Rte_Read_RP_SWC_HvMcu_HvMcu_tDBCTempW(&VAR_Bsw_tDBCTempW_u16);

  /* Product: '<S56>/Divide1' incorporates:
   *  Sum: '<S56>/Add'
   */
  rtb_Divide /= rtb_UnitDelay_bz + rtb_Divide;

  /* Sum: '<S56>/Sum1' incorporates:
   *  Constant: '<S56>/One'
   *  Product: '<S56>/Product'
   *  Product: '<S56>/Product1'
   *  Sum: '<S56>/Subtract1'
   *  UnitDelay: '<S56>/Unit Delay'
   */
  SWC_HSPF_DW.UnitDelay_DSTATE_g = (1.0F - rtb_Divide) * VAR_Hspf_tDBCTempV_f32
    + rtb_Divide * SWC_HSPF_DW.UnitDelay_DSTATE_g;

  /* LookupNDDirect: '<S64>/CAL_DBCTemLow_Table'
   *
   * About '<S64>/CAL_DBCTemLow_Table':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  if (VAR_Bsw_tDBCTempW_u16 < 4095) {
    tmpRead_1 = VAR_Bsw_tDBCTempW_u16;
  } else {
    tmpRead_1 = 4095U;
  }

  if (VAR_Bsw_tDBCTempW_u16 < 4095) {
    tmp_0 = VAR_Bsw_tDBCTempW_u16;
  } else {
    tmp_0 = 4095U;
  }

  /* Switch: '<S64>/Switch1' incorporates:
   *  Abs: '<S64>/Abs'
   *  Constant: '<S64>/CAL_Hspf_tDBCTempROCLim_u8'
   *  Constant: '<S64>/Constant6'
   *  LookupNDDirect: '<S64>/CAL_DBCTemLow_Table'
   *  RelationalOperator: '<S64>/Relational Operator4'
   *  Sum: '<S64>/Add'
   *  Sum: '<S64>/Subtract1'
   *  Switch: '<S64>/Switch3'
   *  UnitDelay: '<S64>/Unit Delay1'
   *  UnitDelay: '<S64>/Unit Delay2'
   *  UnitDelay: '<S64>/Unit Delay4'
   *
   * About '<S64>/CAL_DBCTemLow_Table':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  if (fabsf(rtCP_CAL_DBCTemLow_Table_tabl_m[tmp_0] -
            SWC_HSPF_DW.UnitDelay1_DSTATE_g) > CAL_Hspf_tDBCTempROCLim_u8) {
    SWC_HSPF_DW.UnitDelay2_DSTATE_a = 0.0;
  }

  SWC_HSPF_DW.UnitDelay2_DSTATE_a += (float64)!SWC_HSPF_DW.UnitDelay4_DSTATE_e;

  /* End of Switch: '<S64>/Switch1' */

  /* RelationalOperator: '<S64>/Relational Operator3' incorporates:
   *  Constant: '<S64>/CAL_Hspf_DBCTempROCLimChkCnt_u8'
   *  UnitDelay: '<S64>/Unit Delay2'
   *  UnitDelay: '<S64>/Unit Delay4'
   */
  SWC_HSPF_DW.UnitDelay4_DSTATE_e = (SWC_HSPF_DW.UnitDelay2_DSTATE_a >=
    CAL_Hspf_DBCTempROCLimChkCnt_u8);

  /* Switch: '<S64>/Switch2' incorporates:
   *  LookupNDDirect: '<S64>/CAL_DBCTemLow_Table'
   *  UnitDelay: '<S64>/Unit Delay4'
   *
   * About '<S64>/CAL_DBCTemLow_Table':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  if (SWC_HSPF_DW.UnitDelay4_DSTATE_e) {
    VAR_Hspf_tDBCTempW_f32 = rtCP_CAL_DBCTemLow_Table_tabl_m[tmpRead_1];
  }

  /* End of Switch: '<S64>/Switch2' */

  /* Product: '<S57>/Divide' incorporates:
   *  Constant: '<S9>/CAL_Hspf_TmpWFltFrq_f32'
   *  Constant: '<S9>/PRV_CalFltFrq_10ms_4'
   */
  rtb_Divide = (float32)((uint8)PRV_CalFltFrq_10ms) / CAL_Hspf_TmpWFltFrq_f32;

  /* Switch: '<S71>/Switch' incorporates:
   *  Constant: '<S57>/Constant'
   *  RelationalOperator: '<S71>/UpperRelop'
   *  Switch: '<S71>/Switch2'
   */
  if (rtb_Divide < 1.0F) {
    rtb_Divide = 1.0F;
  }

  /* End of Switch: '<S71>/Switch' */

  /* Product: '<S57>/Divide1' incorporates:
   *  Sum: '<S57>/Add'
   */
  rtb_Divide /= rtb_UnitDelay_bz + rtb_Divide;

  /* Sum: '<S57>/Sum1' incorporates:
   *  Constant: '<S57>/One'
   *  Product: '<S57>/Product'
   *  Product: '<S57>/Product1'
   *  Sum: '<S57>/Subtract1'
   *  UnitDelay: '<S57>/Unit Delay'
   */
  SWC_HSPF_DW.UnitDelay_DSTATE_j = (1.0F - rtb_Divide) * VAR_Hspf_tDBCTempW_f32
    + rtb_Divide * SWC_HSPF_DW.UnitDelay_DSTATE_j;

  /* Logic: '<S12>/Logical Operator' incorporates:
   *  Abs: '<S12>/Abs'
   *  Abs: '<S12>/Abs1'
   *  Abs: '<S12>/Abs2'
   *  Constant: '<S12>/CAL_SDF_tDBCtempOffset_u8'
   *  DataTypeConversion: '<S12>/Data Type Conversion'
   *  RelationalOperator: '<S12>/Relational Operator'
   *  RelationalOperator: '<S12>/Relational Operator1'
   *  RelationalOperator: '<S12>/Relational Operator2'
   *  Sum: '<S12>/Add'
   *  Sum: '<S12>/Add1'
   *  Sum: '<S12>/Add2'
   */
  rtb_Compare_p = ((fabsf(SWC_HSPF_DW.UnitDelay_DSTATE_ci -
    SWC_HSPF_DW.UnitDelay_DSTATE_g) >= CAL_Hspf_tDBCtempOffset_u8) || (fabsf
    (SWC_HSPF_DW.UnitDelay_DSTATE_ci - SWC_HSPF_DW.UnitDelay_DSTATE_j) >=
    CAL_Hspf_tDBCtempOffset_u8) || (fabsf(SWC_HSPF_DW.UnitDelay_DSTATE_g -
    SWC_HSPF_DW.UnitDelay_DSTATE_j) >= CAL_Hspf_tDBCtempOffset_u8));

  /* Switch: '<S20>/Switch3' incorporates:
   *  Constant: '<S20>/Constant7'
   *  Sum: '<S20>/Add'
   *  Switch: '<S20>/Switch2'
   *  UnitDelay: '<S20>/Unit Delay1'
   */
  if (!rtb_Compare_p) {
    SWC_HSPF_DW.UnitDelay1_DSTATE = 0.0;
  }

  SWC_HSPF_DW.UnitDelay1_DSTATE += (float64)rtb_Compare_p;

  /* End of Switch: '<S20>/Switch3' */

  /* RelationalOperator: '<S20>/Relational Operator' incorporates:
   *  Constant: '<S20>/Constant'
   *  UnitDelay: '<S20>/Unit Delay1'
   */
  VAR_Hspf_tDBCCmpErrDelay_b = (SWC_HSPF_DW.UnitDelay1_DSTATE >=
    CAL_Hspf_tDBCCmpTime_u16);

  /* Switch: '<S12>/Switch' incorporates:
   *  Constant: '<S12>/Constant1'
   *  Constant: '<S12>/Constant5'
   *  Constant: '<S18>/Constant'
   *  DataTypeConversion: '<S12>/Data Type Conversion2'
   *  Logic: '<S12>/Logical Operator1'
   *  RelationalOperator: '<S18>/Compare'
   *  Sum: '<S12>/Add3'
   */
  if ((tmpRead_3 == 2) && rtb_Compare_os) {
    tmpRead = (uint8)(VAR_Hspf_tDBCCmpErrDelay_b + 2U);
  } else {
    tmpRead = 2U;
  }

  /* End of Switch: '<S12>/Switch' */

  /* FunctionCaller: '<S1>/RP_SWC_Dem_HSPF_tDBCTempCmpFail_SetEventStatus' */
  Rte_Call_RP_SWC_Dem_HSPF_tDBCTempCmpFail_SetEventStatus(tmpRead);

  /* FunctionCaller: '<S1>/RP_SWC_FIM_HSPF_Sttr1Err_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_HSPF_Sttr1Err_GetFunctionPermission(&rtb_Compare_p);

  /* FunctionCaller: '<S1>/RP_SWC_FIM_HSPF_Sttr2Err_GetFunctionPermission' */
  Rte_Call_RP_SWC_FIM_HSPF_Sttr2Err_GetFunctionPermission
    (&rtb_RP_SWC_FIM_HSPF_Sttr2Err__o);

  /* FunctionCaller: '<S1>/RP_SWC_IoHwAb_ADC_BSW_tCoolantTemp_IoHwAb_ADC_GetPhyVoltage' incorporates:
   *  Constant: '<S1>/Constant3'
   */
  Rte_Call_RP_SWC_IoHwAb_ADC_BSW_tCoolantTemp_IoHwAb_ADC_GetPhyVoltage(21,
    &VAR_Bsw_tCoolantTemp_f32);

  /* FunctionCaller: '<S1>/RP_SWC_IoHwAb_ADC_BSW_uKl30_IoHwAb_ADC_GetPhyVoltage' incorporates:
   *  Constant: '<S1>/Constant'
   */
  Rte_Call_RP_SWC_IoHwAb_ADC_BSW_uKl30_IoHwAb_ADC_GetPhyVoltage(20,
    &VAR_Hspf_uKl30_f32);

  /* FunctionCaller: '<S1>/RP_SWC_IoHwAb_DIO_Get_BSW_Wake_IoHwAb_DIO_Get' incorporates:
   *  Constant: '<S1>/Constant5'
   */
  Rte_Call_RP_SWC_IoHwAb_DIO_Get_BSW_Wake_IoHwAb_DIO_Get(360, &VAR_Bsw_Wake_b);

  /* FunctionCaller: '<S1>/RP_SWC_IoHwAb_DIO_Get_BSW_bt15_IoHwAb_DIO_Get' incorporates:
   *  Constant: '<S1>/Constant4'
   */
  Rte_Call_RP_SWC_IoHwAb_DIO_Get_BSW_bt15_IoHwAb_DIO_Get(341, &VAR_Bsw_bt15_b);

  /* FunctionCaller: '<S1>/RP_SWC_IoHwAb_DIO_Get_BSW_flgCrash_IoHwAb_DIO_Get' incorporates:
   *  Constant: '<S1>/Constant6'
   */
  Rte_Call_RP_SWC_IoHwAb_DIO_Get_BSW_flgCrash_IoHwAb_DIO_Get(370,
    &VAR_Bsw_Crash_b);

  /* Switch: '<S25>/Switch' incorporates:
   *  Constant: '<S25>/CAL_Hspf_CrashChkSubCnt_u8'
   *  Switch: '<S25>/Switch1'
   *  UnitDelay: '<S25>/Unit Delay3'
   */
  if (VAR_Bsw_Crash_b) {
    /* Switch: '<S25>/Switch2' incorporates:
     *  Constant: '<S25>/CAL_Hspf_CrashChkAddCnt_u8'
     *  Constant: '<S25>/Constant3'
     *  UnitDelay: '<S25>/Unit Delay1'
     */
    if (SWC_HSPF_DW.UnitDelay1_DSTATE_j) {
      tmp_1 = 0;
    } else {
      tmp_1 = CAL_Hspf_CrashChkAddCnt_u8;
    }

    /* End of Switch: '<S25>/Switch2' */
  } else if (SWC_HSPF_DW.UnitDelay3_DSTATE_pc) {
    /* Switch: '<S25>/Switch1' incorporates:
     *  Constant: '<S25>/Constant2'
     */
    tmp_1 = 0;
  } else {
    tmp_1 = CAL_Hspf_CrashChkSubCnt_s8;
  }

  /* End of Switch: '<S25>/Switch' */

  /* Sum: '<S25>/Add' incorporates:
   *  UnitDelay: '<S25>/Unit Delay'
   */
  SWC_HSPF_DW.UnitDelay_DSTATE_c += (float64)tmp_1;

  /* RelationalOperator: '<S25>/Relational Operator' incorporates:
   *  Constant: '<S25>/CAL_Hspf_CrashChkCntHiLim_u8'
   *  UnitDelay: '<S25>/Unit Delay'
   *  UnitDelay: '<S25>/Unit Delay1'
   */
  SWC_HSPF_DW.UnitDelay1_DSTATE_j = (SWC_HSPF_DW.UnitDelay_DSTATE_c >=
    CAL_Hspf_CrashChkCntHiLim_u8);

  /* RelationalOperator: '<S25>/Relational Operator1' incorporates:
   *  Constant: '<S25>/CAL_Hspf_CrashChkCntLoLim_s8'
   *  UnitDelay: '<S25>/Unit Delay'
   *  UnitDelay: '<S25>/Unit Delay3'
   */
  SWC_HSPF_DW.UnitDelay3_DSTATE_pc = (SWC_HSPF_DW.UnitDelay_DSTATE_c <=
    CAL_Hspf_CrashChkCntLoLim_s8);

  /* Switch: '<S25>/Switch3' incorporates:
   *  Constant: '<S25>/Constant4'
   *  Switch: '<S25>/Switch4'
   *  UnitDelay: '<S25>/Unit Delay1'
   *  UnitDelay: '<S25>/Unit Delay2'
   *  UnitDelay: '<S25>/Unit Delay3'
   */
  if (SWC_HSPF_DW.UnitDelay1_DSTATE_j) {
    SWC_HSPF_DW.UnitDelay2_DSTATE_ns = true;
  } else {
    SWC_HSPF_DW.UnitDelay2_DSTATE_ns = ((!SWC_HSPF_DW.UnitDelay3_DSTATE_pc) &&
      SWC_HSPF_DW.UnitDelay2_DSTATE_ns);
  }

  /* End of Switch: '<S25>/Switch3' */

  /* Switch: '<S29>/Switch' incorporates:
   *  Constant: '<S29>/CAL_Hspf_bt15ChkSubCnt_s8'
   *  Switch: '<S29>/Switch1'
   *  UnitDelay: '<S29>/Unit Delay3'
   */
  if (VAR_Bsw_bt15_b) {
    /* Switch: '<S29>/Switch2' incorporates:
     *  Constant: '<S29>/CAL_Hspf_bt15ChkAddCnt_u8'
     *  Constant: '<S29>/Constant3'
     *  UnitDelay: '<S29>/Unit Delay1'
     */
    if (SWC_HSPF_DW.UnitDelay1_DSTATE_i) {
      tmp_1 = 0;
    } else {
      tmp_1 = CAL_Hspf_bt15ChkAddCnt_u8;
    }

    /* End of Switch: '<S29>/Switch2' */
  } else if (SWC_HSPF_DW.UnitDelay3_DSTATE_h) {
    /* Switch: '<S29>/Switch1' incorporates:
     *  Constant: '<S29>/Constant2'
     */
    tmp_1 = 0;
  } else {
    tmp_1 = CAL_Hspf_bt15ChkSubCnt_s8;
  }

  /* End of Switch: '<S29>/Switch' */

  /* Sum: '<S29>/Add' incorporates:
   *  UnitDelay: '<S29>/Unit Delay'
   */
  SWC_HSPF_DW.UnitDelay_DSTATE_cf += (float64)tmp_1;

  /* RelationalOperator: '<S29>/Relational Operator' incorporates:
   *  Constant: '<S29>/CAL_Hspf_bt15ChkCntHiLim_u8'
   *  UnitDelay: '<S29>/Unit Delay'
   *  UnitDelay: '<S29>/Unit Delay1'
   */
  SWC_HSPF_DW.UnitDelay1_DSTATE_i = (SWC_HSPF_DW.UnitDelay_DSTATE_cf >=
    CAL_Hspf_bt15ChkCntHiLim_u8);

  /* RelationalOperator: '<S29>/Relational Operator1' incorporates:
   *  Constant: '<S29>/CAL_Hspf_bt15ChkCntLoLim_s8'
   *  UnitDelay: '<S29>/Unit Delay'
   *  UnitDelay: '<S29>/Unit Delay3'
   */
  SWC_HSPF_DW.UnitDelay3_DSTATE_h = (SWC_HSPF_DW.UnitDelay_DSTATE_cf <=
    CAL_Hspf_bt15ChkCntLoLim_s8);

  /* Switch: '<S29>/Switch3' incorporates:
   *  Constant: '<S29>/Constant4'
   *  Switch: '<S29>/Switch4'
   *  UnitDelay: '<S29>/Unit Delay1'
   *  UnitDelay: '<S29>/Unit Delay2'
   *  UnitDelay: '<S29>/Unit Delay3'
   */
  if (SWC_HSPF_DW.UnitDelay1_DSTATE_i) {
    SWC_HSPF_DW.UnitDelay2_DSTATE_f = true;
  } else {
    SWC_HSPF_DW.UnitDelay2_DSTATE_f = ((!SWC_HSPF_DW.UnitDelay3_DSTATE_h) &&
      SWC_HSPF_DW.UnitDelay2_DSTATE_f);
  }

  /* End of Switch: '<S29>/Switch3' */

  /* Switch: '<S28>/Switch' incorporates:
   *  Constant: '<S28>/CAL_Hspf_bt15ChkSubCnt_s8'
   *  Switch: '<S28>/Switch1'
   *  UnitDelay: '<S28>/Unit Delay3'
   */
  if (VAR_Bsw_Wake_b) {
    /* Switch: '<S28>/Switch2' incorporates:
     *  Constant: '<S28>/CAL_Hspf_bt15ChkAddCnt_u8'
     *  Constant: '<S28>/Constant3'
     *  UnitDelay: '<S28>/Unit Delay1'
     */
    if (SWC_HSPF_DW.UnitDelay1_DSTATE_p) {
      tmp_1 = 0;
    } else {
      tmp_1 = CAL_Hspf_bt15ChkAddCnt_u8;
    }

    /* End of Switch: '<S28>/Switch2' */
  } else if (SWC_HSPF_DW.UnitDelay3_DSTATE_m) {
    /* Switch: '<S28>/Switch1' incorporates:
     *  Constant: '<S28>/Constant2'
     */
    tmp_1 = 0;
  } else {
    tmp_1 = CAL_Hspf_bt15ChkSubCnt_s8;
  }

  /* End of Switch: '<S28>/Switch' */

  /* Sum: '<S28>/Add' incorporates:
   *  UnitDelay: '<S28>/Unit Delay'
   */
  SWC_HSPF_DW.UnitDelay_DSTATE_f += (float64)tmp_1;

  /* RelationalOperator: '<S28>/Relational Operator' incorporates:
   *  Constant: '<S28>/CAL_Hspf_bt15ChkCntHiLim_u8'
   *  UnitDelay: '<S28>/Unit Delay'
   *  UnitDelay: '<S28>/Unit Delay1'
   */
  SWC_HSPF_DW.UnitDelay1_DSTATE_p = (SWC_HSPF_DW.UnitDelay_DSTATE_f >=
    CAL_Hspf_bt15ChkCntHiLim_u8);

  /* RelationalOperator: '<S28>/Relational Operator1' incorporates:
   *  Constant: '<S28>/CAL_Hspf_bt15ChkCntLoLim_s8'
   *  UnitDelay: '<S28>/Unit Delay'
   *  UnitDelay: '<S28>/Unit Delay3'
   */
  SWC_HSPF_DW.UnitDelay3_DSTATE_m = (SWC_HSPF_DW.UnitDelay_DSTATE_f <=
    CAL_Hspf_bt15ChkCntLoLim_s8);

  /* Switch: '<S28>/Switch3' incorporates:
   *  Constant: '<S28>/Constant4'
   *  Switch: '<S28>/Switch4'
   *  UnitDelay: '<S28>/Unit Delay1'
   *  UnitDelay: '<S28>/Unit Delay2'
   *  UnitDelay: '<S28>/Unit Delay3'
   */
  if (SWC_HSPF_DW.UnitDelay1_DSTATE_p) {
    SWC_HSPF_DW.UnitDelay2_DSTATE_fs = true;
  } else {
    SWC_HSPF_DW.UnitDelay2_DSTATE_fs = ((!SWC_HSPF_DW.UnitDelay3_DSTATE_m) &&
      SWC_HSPF_DW.UnitDelay2_DSTATE_fs);
  }

  /* End of Switch: '<S28>/Switch3' */

  /* Product: '<S63>/Divide' incorporates:
   *  Constant: '<S9>/CAL_Hspf_uKl30FltFrq_f32'
   *  Constant: '<S9>/PRV_CalFltFrq_10ms_1'
   */
  rtb_Divide = (float32)((uint8)PRV_CalFltFrq_10ms) / CAL_Hspf_uKl30FltFrq_f32;

  /* Switch: '<S76>/Switch' incorporates:
   *  Constant: '<S63>/Constant'
   *  RelationalOperator: '<S76>/UpperRelop'
   *  Switch: '<S76>/Switch2'
   */
  if (rtb_Divide < 1.0F) {
    rtb_Divide = 1.0F;
  }

  /* End of Switch: '<S76>/Switch' */

  /* Product: '<S63>/Divide1' incorporates:
   *  Sum: '<S63>/Add'
   */
  rtb_Divide /= rtb_UnitDelay_bz + rtb_Divide;

  /* Sum: '<S63>/Sum1' incorporates:
   *  Constant: '<S63>/Constant1'
   *  Product: '<S63>/Product'
   *  Product: '<S63>/Product1'
   *  Sum: '<S63>/Subtract1'
   *  UnitDelay: '<S63>/Unit Delay'
   */
  SWC_HSPF_DW.UnitDelay_DSTATE_l = (1.0F - rtb_Divide) * VAR_Hspf_uKl30_f32 +
    rtb_Divide * SWC_HSPF_DW.UnitDelay_DSTATE_l;

  /* LookupNDDirect: '<S52>/tCoolantTem_Table'
   *
   * About '<S52>/tCoolantTem_Table':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  if (VAR_Bsw_tCoolantTemp_f32 > 4095.0F) {
    rtb_Divide = 4095.0F;
  } else if (VAR_Bsw_tCoolantTemp_f32 < 0.0F) {
    rtb_Divide = 0.0F;
  } else {
    rtb_Divide = VAR_Bsw_tCoolantTemp_f32;
  }

  VAR_Hspf_tCoolantTemp_f32 = rtCP_tCoolantTem_Table_table[(sint32)rtb_Divide];

  /* End of LookupNDDirect: '<S52>/tCoolantTem_Table' */

  /* Product: '<S50>/Divide' incorporates:
   *  Constant: '<S9>/CAL_Hspf_tCoolantFltFrq_f32'
   *  Constant: '<S9>/PRV_CalFltFrq_10ms_11'
   */
  rtb_Divide = (float32)((uint8)PRV_CalFltFrq_10ms) /
    CAL_Hspf_tCoolantFltFrq_f32;

  /* Switch: '<S67>/Switch' incorporates:
   *  Constant: '<S50>/Constant'
   *  RelationalOperator: '<S67>/UpperRelop'
   *  Switch: '<S67>/Switch2'
   */
  if (rtb_Divide < 1.0F) {
    rtb_Divide = 1.0F;
  }

  /* End of Switch: '<S67>/Switch' */

  /* Product: '<S50>/Divide1' incorporates:
   *  Sum: '<S50>/Add'
   */
  rtb_Divide /= rtb_UnitDelay_bz + rtb_Divide;

  /* Sum: '<S50>/Sum1' incorporates:
   *  Constant: '<S50>/One'
   *  Product: '<S50>/Product'
   *  Product: '<S50>/Product1'
   *  Sum: '<S50>/Subtract1'
   *  UnitDelay: '<S50>/Unit Delay'
   */
  SWC_HSPF_DW.UnitDelay_DSTATE_n = (1.0F - rtb_Divide) *
    VAR_Hspf_tCoolantTemp_f32 + rtb_Divide * SWC_HSPF_DW.UnitDelay_DSTATE_n;

  /* Logic: '<S11>/Logical Operator1' */
  VAR_Hspf_flgSttr2NoErr_b = !rtb_RP_SWC_FIM_HSPF_Sttr2Err__o;

  /* Logic: '<S11>/Logical Operator' */
  VAR_Hspf_flgSttr1NoErr_b = !rtb_Compare_p;

  /* Product: '<S60>/Divide' incorporates:
   *  Constant: '<S9>/CAL_Hspf_tStrrTmp2FltFrq_f32'
   *  Constant: '<S9>/PRV_CalFltFrq_10ms_6'
   */
  rtb_Divide = (float32)((uint8)PRV_CalFltFrq_10ms) /
    CAL_Hspf_tStrrTmp2FltFrq_f32;

  /* Switch: '<S74>/Switch' incorporates:
   *  Constant: '<S60>/Constant'
   *  RelationalOperator: '<S74>/UpperRelop'
   *  Switch: '<S74>/Switch2'
   */
  if (rtb_Divide < 1.0F) {
    rtb_Divide = 1.0F;
  }

  /* End of Switch: '<S74>/Switch' */

  /* Product: '<S60>/Divide1' incorporates:
   *  Sum: '<S60>/Add'
   */
  rtb_Divide /= rtb_UnitDelay_bz + rtb_Divide;

  /* Sum: '<S60>/Sum1' incorporates:
   *  Constant: '<S60>/One'
   *  Product: '<S60>/Product'
   *  Product: '<S60>/Product1'
   *  Sum: '<S60>/Subtract1'
   *  UnitDelay: '<S60>/Unit Delay'
   */
  SWC_HSPF_DW.UnitDelay_DSTATE_h = (1.0F - rtb_Divide) * (float32)
    VAR_Hspf_tStrrTemp2_s16 + rtb_Divide * SWC_HSPF_DW.UnitDelay_DSTATE_h;

  /* Product: '<S59>/Divide' incorporates:
   *  Constant: '<S9>/CAL_Hspf_tStrrTmp1FltFrq_f32'
   *  Constant: '<S9>/PRV_CalFltFrq_10ms_5'
   */
  rtb_Divide = (float32)((uint8)PRV_CalFltFrq_10ms) /
    CAL_Hspf_tStrrTmp1FltFrq_f32;

  /* Switch: '<S73>/Switch' incorporates:
   *  Constant: '<S59>/Constant'
   *  RelationalOperator: '<S73>/UpperRelop'
   *  Switch: '<S73>/Switch2'
   */
  if (rtb_Divide < 1.0F) {
    rtb_Divide = 1.0F;
  }

  /* End of Switch: '<S73>/Switch' */

  /* Product: '<S59>/Divide1' incorporates:
   *  Sum: '<S59>/Add'
   */
  rtb_Divide /= rtb_UnitDelay_bz + rtb_Divide;

  /* Sum: '<S59>/Sum1' incorporates:
   *  Constant: '<S59>/One'
   *  Product: '<S59>/Product'
   *  Product: '<S59>/Product1'
   *  Sum: '<S59>/Subtract1'
   *  UnitDelay: '<S59>/Unit Delay'
   */
  SWC_HSPF_DW.UnitDelay_DSTATE_dp = (1.0F - rtb_Divide) * (float32)
    VAR_Hspf_tStrrTemp1_s16 + rtb_Divide * SWC_HSPF_DW.UnitDelay_DSTATE_dp;

  /* Logic: '<S17>/Logical Operator1' incorporates:
   *  Logic: '<S17>/Logical Operator6'
   *  Switch: '<S17>/Switch1'
   *  Switch: '<S17>/Switch2'
   */
  rtb_RP_SWC_FIM_HSPF_Sttr2Err__o = !VAR_Hspf_flgSttr2NoErr_b;

  /* Switch: '<S17>/Switch1' incorporates:
   *  Logic: '<S17>/Logical Operator'
   *  Logic: '<S17>/Logical Operator1'
   */
  if (VAR_Hspf_flgSttr1NoErr_b && rtb_RP_SWC_FIM_HSPF_Sttr2Err__o) {
    /* Outport: '<Root>/PP_SWC_HSPF_HSPF_tStrrTempFlt' */
    (void) Rte_Write_PP_SWC_HSPF_HSPF_tStrrTempFlt
      (SWC_HSPF_DW.UnitDelay_DSTATE_h);
  } else {
    /* Logic: '<S17>/Logical Operator4' incorporates:
     *  Logic: '<S17>/Logical Operator5'
     *  Switch: '<S17>/Switch2'
     */
    rtb_Compare_p = !VAR_Hspf_flgSttr1NoErr_b;

    /* Switch: '<S17>/Switch2' incorporates:
     *  Logic: '<S17>/Logical Operator2'
     *  Logic: '<S17>/Logical Operator3'
     *  Logic: '<S17>/Logical Operator4'
     *  Switch: '<S17>/Switch3'
     */
    if (rtb_Compare_p && VAR_Hspf_flgSttr2NoErr_b) {
      /* Outport: '<Root>/PP_SWC_HSPF_HSPF_tStrrTempFlt' */
      (void) Rte_Write_PP_SWC_HSPF_HSPF_tStrrTempFlt
        (SWC_HSPF_DW.UnitDelay_DSTATE_dp);
    } else if (rtb_Compare_p && rtb_RP_SWC_FIM_HSPF_Sttr2Err__o) {
      /* Switch: '<S17>/Switch' incorporates:
       *  RelationalOperator: '<S17>/Relational Operator'
       *  Switch: '<S17>/Switch3'
       */
      if (SWC_HSPF_DW.UnitDelay_DSTATE_dp >= SWC_HSPF_DW.UnitDelay_DSTATE_h) {
        /* Outport: '<Root>/PP_SWC_HSPF_HSPF_tStrrTempFlt' */
        (void) Rte_Write_PP_SWC_HSPF_HSPF_tStrrTempFlt
          (SWC_HSPF_DW.UnitDelay_DSTATE_dp);
      } else {
        /* Outport: '<Root>/PP_SWC_HSPF_HSPF_tStrrTempFlt' */
        (void) Rte_Write_PP_SWC_HSPF_HSPF_tStrrTempFlt
          (SWC_HSPF_DW.UnitDelay_DSTATE_h);
      }

      /* End of Switch: '<S17>/Switch' */
    } else {
      /* Outport: '<Root>/PP_SWC_HSPF_HSPF_tStrrTempFlt' incorporates:
       *  Switch: '<S17>/Switch3'
       */
      (void) Rte_Write_PP_SWC_HSPF_HSPF_tStrrTempFlt
        (SWC_HSPF_DW.UnitDelay_DSTATE_dp);
    }
  }

  /* Product: '<S49>/Divide' incorporates:
   *  Constant: '<S9>/CAL_Hspf_nFltFrq_f32'
   *  Constant: '<S9>/PRV_CalFltFrq_10ms_10'
   */
  rtb_Divide = (float32)((uint8)PRV_CalFltFrq_10ms) / CAL_Hspf_nFltFrq_f32;

  /* Switch: '<S66>/Switch' incorporates:
   *  Constant: '<S49>/Constant'
   *  RelationalOperator: '<S66>/UpperRelop'
   *  Switch: '<S66>/Switch2'
   */
  if (rtb_Divide < 1.0F) {
    rtb_Divide = 1.0F;
  }

  /* End of Switch: '<S66>/Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_HSPF_10ms' */

  /* Inport: '<Root>/RP_SWC_Rdc_Rdc_nWoFlt' */
  Rte_Read_RP_SWC_Rdc_Rdc_nWoFlt(&rtb_Divide_j4);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_HSPF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_HSPF_10ms_sys'
   */
  /* Product: '<S49>/Divide1' incorporates:
   *  Sum: '<S49>/Add'
   */
  rtb_Divide /= rtb_UnitDelay_bz + rtb_Divide;

  /* Sum: '<S49>/Sum1' incorporates:
   *  Constant: '<S49>/One'
   *  Product: '<S49>/Product'
   *  Product: '<S49>/Product1'
   *  Sum: '<S49>/Subtract1'
   *  UnitDelay: '<S49>/Unit Delay'
   */
  SWC_HSPF_DW.UnitDelay_DSTATE_b = (1.0F - rtb_Divide) * rtb_Divide_j4 +
    rtb_Divide * SWC_HSPF_DW.UnitDelay_DSTATE_b;

  /* Product: '<S58>/Divide' incorporates:
   *  Constant: '<S9>/CAL_Hspf_CltInletTempFltFrq_f32'
   *  Constant: '<S9>/PRV_CalFltFrq_10ms_12'
   */
  rtb_Divide_j4 = (float32)((uint8)PRV_CalFltFrq_10ms) /
    CAL_Hspf_CltInletTempFltFrq_f32;

  /* Switch: '<S72>/Switch' incorporates:
   *  Constant: '<S58>/Constant'
   *  RelationalOperator: '<S72>/UpperRelop'
   *  Switch: '<S72>/Switch2'
   */
  if (rtb_Divide_j4 < 1.0F) {
    rtb_Divide_j4 = 1.0F;
  }

  /* End of Switch: '<S72>/Switch' */

  /* Gain: '<S9>/Gain4' incorporates:
   *  Inport: '<Root>/RP_SWC_HvMcu_HvMcu_tDrvBoardTemp'
   */
  Rte_Read_RP_SWC_HvMcu_HvMcu_tDrvBoardTemp(&VAR_Bsw_tDrvBoardTemp_u16);

  /* Product: '<S58>/Divide1' incorporates:
   *  Sum: '<S58>/Add'
   */
  rtb_Divide_j4 /= rtb_UnitDelay_bz + rtb_Divide_j4;

  /* LookupNDDirect: '<S48>/PCBTem_Table'
   *
   * About '<S48>/PCBTem_Table':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  if (VAR_Bsw_tDrvBoardTemp_u16 < 4095) {
    tmp_0 = VAR_Bsw_tDrvBoardTemp_u16;
  } else {
    tmp_0 = 4095U;
  }

  VAR_Hspf_tDrvBoardTemp_f32 = rtCP_PCBTem_Table_table[tmp_0];

  /* End of LookupNDDirect: '<S48>/PCBTem_Table' */

  /* Sum: '<S58>/Sum1' incorporates:
   *  Constant: '<S58>/One'
   *  Product: '<S58>/Product'
   *  Product: '<S58>/Product1'
   *  Sum: '<S58>/Subtract1'
   *  UnitDelay: '<S58>/Unit Delay'
   */
  SWC_HSPF_DW.UnitDelay_DSTATE_nl = (1.0F - rtb_Divide_j4) *
    VAR_Hspf_tDrvBoardTemp_f32 + rtb_Divide_j4 * SWC_HSPF_DW.UnitDelay_DSTATE_nl;

  /* Product: '<S51>/Divide' incorporates:
   *  Constant: '<S9>/CAL_Hspf_CltInletTempFltFrq_f1'
   *  Constant: '<S9>/PRV_CalFltFrq_10ms_13'
   */
  rtb_Divide_j4 = (float32)((uint8)PRV_CalFltFrq_10ms) /
    CAL_Hspf_iDcLnkEstFltFrq_f32;

  /* Switch: '<S68>/Switch' incorporates:
   *  Constant: '<S51>/Constant'
   *  RelationalOperator: '<S68>/UpperRelop'
   *  Switch: '<S68>/Switch2'
   */
  if (rtb_Divide_j4 < 1.0F) {
    rtb_Divide_j4 = 1.0F;
  }

  /* End of Switch: '<S68>/Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_HSPF_10ms' */

  /* Inport: '<Root>/RP_SWC_BCC_BCC_iDcLnkEstFlt' */
  Rte_Read_RP_SWC_BCC_BCC_iDcLnkEstFlt(&rtb_Divide_lv);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_HSPF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_HSPF_10ms_sys'
   */
  /* Gain: '<S9>/Gain' incorporates:
   *  Inport: '<Root>/RP_SWC_MCF_MCF_uDcLnk'
   */
  Rte_Read_RP_SWC_MCF_MCF_uDcLnk(&VAR_Hspf_uDcLnk_f32);

  /* Product: '<S51>/Divide1' incorporates:
   *  Sum: '<S51>/Add'
   */
  rtb_Divide_j4 /= rtb_UnitDelay_bz + rtb_Divide_j4;

  /* Sum: '<S51>/Sum1' incorporates:
   *  Constant: '<S51>/One'
   *  Product: '<S51>/Product'
   *  Product: '<S51>/Product1'
   *  Sum: '<S51>/Subtract1'
   *  UnitDelay: '<S51>/Unit Delay'
   */
  SWC_HSPF_DW.UnitDelay_DSTATE_bm = (1.0F - rtb_Divide_j4) * rtb_Divide_lv +
    rtb_Divide_j4 * SWC_HSPF_DW.UnitDelay_DSTATE_bm;

  /* Product: '<S62>/Divide' incorporates:
   *  Constant: '<S9>/CAL_Hspf_uDcLnkFltFrq_f32'
   *  Constant: '<S9>/PRV_CalFltFrq_10ms_7'
   */
  rtb_Divide_lv = (float32)((uint8)PRV_CalFltFrq_10ms) /
    CAL_Hspf_uDcLnkFltFrq_f32;

  /* Switch: '<S75>/Switch' incorporates:
   *  Constant: '<S62>/Constant'
   *  RelationalOperator: '<S75>/UpperRelop'
   *  Switch: '<S75>/Switch2'
   */
  if (rtb_Divide_lv < 1.0F) {
    rtb_Divide_lv = 1.0F;
  }

  /* End of Switch: '<S75>/Switch' */

  /* Product: '<S62>/Divide1' incorporates:
   *  Sum: '<S62>/Add'
   */
  rtb_Divide_lv /= rtb_UnitDelay_bz + rtb_Divide_lv;

  /* Sum: '<S62>/Sum1' incorporates:
   *  Constant: '<S62>/One'
   *  Product: '<S62>/Product'
   *  Product: '<S62>/Product1'
   *  Sum: '<S62>/Subtract1'
   *  UnitDelay: '<S62>/Unit Delay'
   */
  SWC_HSPF_DW.UnitDelay_DSTATE_ji = (1.0F - rtb_Divide_lv) * VAR_Hspf_uDcLnk_f32
    + rtb_Divide_lv * SWC_HSPF_DW.UnitDelay_DSTATE_ji;

  /* Outport: '<Root>/PP_SWC_HSPF_HSPF_PwrDcLnk' incorporates:
   *  Product: '<S51>/Product3'
   */
  (void) Rte_Write_PP_SWC_HSPF_HSPF_PwrDcLnk(SWC_HSPF_DW.UnitDelay_DSTATE_ji *
    SWC_HSPF_DW.UnitDelay_DSTATE_bm);

  /* Product: '<S30>/Divide' incorporates:
   *  Constant: '<S7>/CAL_Hspf_TmpUFltFrq_f32'
   *  Constant: '<S7>/PRV_CalFltFrq_10ms_2'
   */
  rtb_Divide_lv = (float32)((uint8)PRV_CalFltFrq_10ms) /
    CAL_Hspf_TmpCoolanTjFltFrq_f32;

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S30>/Constant'
   *  RelationalOperator: '<S32>/UpperRelop'
   *  Switch: '<S32>/Switch2'
   */
  if (rtb_Divide_lv < 1.0F) {
    rtb_Divide_lv = 1.0F;
  }

  /* End of Switch: '<S32>/Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_HSPF_10ms' */

  /* Inport: '<Root>/RP_SWC_BCC_BCC_tCoolantTj' */
  Rte_Read_RP_SWC_BCC_BCC_tCoolantTj(&rtb_UnitDelay1_j1);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_HSPF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_HSPF_10ms_sys'
   */
  /* Product: '<S30>/Divide1' incorporates:
   *  Sum: '<S30>/Add'
   */
  rtb_Divide_lv /= rtb_UnitDelay_bz + rtb_Divide_lv;

  /* Sum: '<S30>/Sum1' incorporates:
   *  Constant: '<S30>/One'
   *  Product: '<S30>/Product'
   *  Product: '<S30>/Product1'
   *  Sum: '<S30>/Subtract1'
   *  UnitDelay: '<S30>/Unit Delay'
   */
  SWC_HSPF_DW.UnitDelay_DSTATE_o = (1.0F - rtb_Divide_lv) * rtb_UnitDelay1_j1 +
    rtb_Divide_lv * SWC_HSPF_DW.UnitDelay_DSTATE_o;

  /* SignalConversion generated from: '<S1>/RP_SWC_BCC_BCC_tIgbtTj_read' incorporates:
   *  Inport: '<Root>/RP_SWC_BCC_BCC_tIgbtTj'
   */
  Rte_Read_RP_SWC_BCC_BCC_tIgbtTj(&rtb_TmpSignalConversionAtRP_SWC);

  /* UnitDelay: '<S31>/Unit Delay' */
  rtb_UnitDelay_bz = SWC_HSPF_DW.UnitDelay_DSTATE_i;

  /* Switch: '<S33>/Switch' incorporates:
   *  Sum: '<S33>/Add'
   *  UnitDelay: '<S31>/Unit Delay'
   */
  if (rtb_TmpSignalConversionAtRP_SWC - SWC_HSPF_DW.UnitDelay_DSTATE_i >= 0.0F)
  {
    SWC_HSPF_DW.UnitDelay_DSTATE_i = rtb_TmpSignalConversionAtRP_SWC;
  }

  /* End of Switch: '<S33>/Switch' */

  /* UnitDelay: '<S31>/Unit Delay1' */
  rtb_UnitDelay1_j1 = SWC_HSPF_DW.UnitDelay1_DSTATE_e;

  /* Switch: '<S34>/Switch' incorporates:
   *  Sum: '<S34>/Add'
   *  UnitDelay: '<S31>/Unit Delay1'
   */
  if (SWC_HSPF_DW.UnitDelay_DSTATE_i - SWC_HSPF_DW.UnitDelay1_DSTATE_e < 0.0F) {
    SWC_HSPF_DW.UnitDelay_DSTATE_i = SWC_HSPF_DW.UnitDelay1_DSTATE_e;
  }

  /* End of Switch: '<S34>/Switch' */

  /* UnitDelay: '<S31>/Unit Delay2' */
  rtb_Divide_lv = SWC_HSPF_DW.UnitDelay2_DSTATE_ix;

  /* Switch: '<S35>/Switch' incorporates:
   *  Sum: '<S35>/Add'
   *  UnitDelay: '<S31>/Unit Delay2'
   */
  if (SWC_HSPF_DW.UnitDelay_DSTATE_i - SWC_HSPF_DW.UnitDelay2_DSTATE_ix < 0.0F)
  {
    SWC_HSPF_DW.UnitDelay_DSTATE_i = SWC_HSPF_DW.UnitDelay2_DSTATE_ix;
  }

  /* End of Switch: '<S35>/Switch' */

  /* UnitDelay: '<S31>/Unit Delay3' */
  rtb_Divide_j4 = SWC_HSPF_DW.UnitDelay3_DSTATE_b;

  /* Switch: '<S36>/Switch' incorporates:
   *  Sum: '<S36>/Add'
   *  UnitDelay: '<S31>/Unit Delay3'
   */
  if (SWC_HSPF_DW.UnitDelay_DSTATE_i - SWC_HSPF_DW.UnitDelay3_DSTATE_b < 0.0F) {
    SWC_HSPF_DW.UnitDelay_DSTATE_i = SWC_HSPF_DW.UnitDelay3_DSTATE_b;
  }

  /* End of Switch: '<S36>/Switch' */

  /* UnitDelay: '<S31>/Unit Delay4' */
  rtb_Divide = SWC_HSPF_DW.UnitDelay4_DSTATE;

  /* Switch: '<S37>/Switch' incorporates:
   *  Sum: '<S37>/Add'
   *  UnitDelay: '<S31>/Unit Delay4'
   */
  if (SWC_HSPF_DW.UnitDelay_DSTATE_i - SWC_HSPF_DW.UnitDelay4_DSTATE < 0.0F) {
    SWC_HSPF_DW.UnitDelay_DSTATE_i = SWC_HSPF_DW.UnitDelay4_DSTATE;
  }

  /* End of Switch: '<S37>/Switch' */

  /* UnitDelay: '<S31>/Unit Delay5' */
  rtb_UnitDelay5 = SWC_HSPF_DW.UnitDelay5_DSTATE;

  /* Switch: '<S38>/Switch' incorporates:
   *  Sum: '<S38>/Add'
   *  UnitDelay: '<S31>/Unit Delay5'
   */
  if (SWC_HSPF_DW.UnitDelay_DSTATE_i - SWC_HSPF_DW.UnitDelay5_DSTATE < 0.0F) {
    SWC_HSPF_DW.UnitDelay_DSTATE_i = SWC_HSPF_DW.UnitDelay5_DSTATE;
  }

  /* End of Switch: '<S38>/Switch' */

  /* UnitDelay: '<S31>/Unit Delay6' */
  rtb_UnitDelay6 = SWC_HSPF_DW.UnitDelay6_DSTATE;

  /* Switch: '<S39>/Switch' incorporates:
   *  Sum: '<S39>/Add'
   *  UnitDelay: '<S31>/Unit Delay6'
   */
  if (SWC_HSPF_DW.UnitDelay_DSTATE_i - SWC_HSPF_DW.UnitDelay6_DSTATE < 0.0F) {
    SWC_HSPF_DW.UnitDelay_DSTATE_i = SWC_HSPF_DW.UnitDelay6_DSTATE;
  }

  /* End of Switch: '<S39>/Switch' */

  /* UnitDelay: '<S31>/Unit Delay7' */
  rtb_UnitDelay7 = SWC_HSPF_DW.UnitDelay7_DSTATE;

  /* Switch: '<S40>/Switch' incorporates:
   *  Sum: '<S40>/Add'
   *  UnitDelay: '<S31>/Unit Delay7'
   */
  if (SWC_HSPF_DW.UnitDelay_DSTATE_i - SWC_HSPF_DW.UnitDelay7_DSTATE < 0.0F) {
    SWC_HSPF_DW.UnitDelay_DSTATE_i = SWC_HSPF_DW.UnitDelay7_DSTATE;
  }

  /* End of Switch: '<S40>/Switch' */

  /* Switch: '<S41>/Switch' incorporates:
   *  Sum: '<S41>/Add'
   *  UnitDelay: '<S31>/Unit Delay8'
   */
  if (SWC_HSPF_DW.UnitDelay_DSTATE_i - SWC_HSPF_DW.UnitDelay8_DSTATE >= 0.0F) {
    /* Outport: '<Root>/PP_SWC_HSPF_HSPF_tIgbtTjFlt' */
    (void) Rte_Write_PP_SWC_HSPF_HSPF_tIgbtTjFlt(SWC_HSPF_DW.UnitDelay_DSTATE_i);
  } else {
    /* Outport: '<Root>/PP_SWC_HSPF_HSPF_tIgbtTjFlt' */
    (void) Rte_Write_PP_SWC_HSPF_HSPF_tIgbtTjFlt(SWC_HSPF_DW.UnitDelay8_DSTATE);
  }

  /* End of Switch: '<S41>/Switch' */

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  SWC_HSPF_DW.UnitDelay_DSTATE_e = SWC_HSPF_B.LogicalOperator2;

  /* Update for UnitDelay: '<S53>/Unit Delay1' incorporates:
   *  LookupNDDirect: '<S53>/CAL_DBCTemLow_Table'
   *
   * About '<S53>/CAL_DBCTemLow_Table':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  SWC_HSPF_DW.UnitDelay1_DSTATE_n =
    rtCP_CAL_DBCTemLow_Table_table[rtb_TmpSignalConversionAtRP_S_e];

  /* Update for UnitDelay: '<S55>/Unit Delay1' incorporates:
   *  LookupNDDirect: '<S55>/CAL_DBCTemLow_Table'
   *
   * About '<S55>/CAL_DBCTemLow_Table':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  SWC_HSPF_DW.UnitDelay1_DSTATE_m = rtCP_CAL_DBCTemLow_Table_table_[tmpRead_0];

  /* Update for UnitDelay: '<S64>/Unit Delay1' incorporates:
   *  LookupNDDirect: '<S64>/CAL_DBCTemLow_Table'
   *
   * About '<S64>/CAL_DBCTemLow_Table':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  SWC_HSPF_DW.UnitDelay1_DSTATE_g = rtCP_CAL_DBCTemLow_Table_tabl_m[tmpRead_1];

  /* Update for UnitDelay: '<S31>/Unit Delay' */
  SWC_HSPF_DW.UnitDelay_DSTATE_i = rtb_TmpSignalConversionAtRP_SWC;

  /* Update for UnitDelay: '<S31>/Unit Delay1' */
  SWC_HSPF_DW.UnitDelay1_DSTATE_e = rtb_UnitDelay_bz;

  /* Update for UnitDelay: '<S31>/Unit Delay2' */
  SWC_HSPF_DW.UnitDelay2_DSTATE_ix = rtb_UnitDelay1_j1;

  /* Update for UnitDelay: '<S31>/Unit Delay3' */
  SWC_HSPF_DW.UnitDelay3_DSTATE_b = rtb_Divide_lv;

  /* Update for UnitDelay: '<S31>/Unit Delay4' */
  SWC_HSPF_DW.UnitDelay4_DSTATE = rtb_Divide_j4;

  /* Update for UnitDelay: '<S31>/Unit Delay5' */
  SWC_HSPF_DW.UnitDelay5_DSTATE = rtb_Divide;

  /* Update for UnitDelay: '<S31>/Unit Delay6' */
  SWC_HSPF_DW.UnitDelay6_DSTATE = rtb_UnitDelay5;

  /* Update for UnitDelay: '<S31>/Unit Delay7' */
  SWC_HSPF_DW.UnitDelay7_DSTATE = rtb_UnitDelay6;

  /* Update for UnitDelay: '<S31>/Unit Delay8' */
  SWC_HSPF_DW.UnitDelay8_DSTATE = rtb_UnitDelay7;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_HSPF_10ms' */
  GLB_HSPF_iDcLnkEstFlt_f32 = SWC_HSPF_DW.UnitDelay_DSTATE_bm;
  /* Outport: '<Root>/PP_SWC_HSPF_HSPF_uKl30Flt' */
  (void) Rte_Write_PP_SWC_HSPF_HSPF_uKl30Flt(SWC_HSPF_DW.UnitDelay_DSTATE_l);

  /* Outport: '<Root>/PP_SWC_HSPF_HSPF_tDBCTempUFlt' */
  (void) Rte_Write_PP_SWC_HSPF_HSPF_tDBCTempUFlt(SWC_HSPF_DW.UnitDelay_DSTATE_ci);

  /* Outport: '<Root>/PP_SWC_HSPF_HSPF_tDBCTempVFlt' */
  (void) Rte_Write_PP_SWC_HSPF_HSPF_tDBCTempVFlt(SWC_HSPF_DW.UnitDelay_DSTATE_g);

  /* Outport: '<Root>/PP_SWC_HSPF_HSPF_tDBCTempWFlt' */
  (void) Rte_Write_PP_SWC_HSPF_HSPF_tDBCTempWFlt(SWC_HSPF_DW.UnitDelay_DSTATE_j);

  /* Outport: '<Root>/PP_SWC_HSPF_HSPF_tStrrTemp1Flt' */
  (void) Rte_Write_PP_SWC_HSPF_HSPF_tStrrTemp1Flt
    (SWC_HSPF_DW.UnitDelay_DSTATE_dp);

  /* Outport: '<Root>/PP_SWC_HSPF_HSPF_tStrrTemp2Flt' */
  (void) Rte_Write_PP_SWC_HSPF_HSPF_tStrrTemp2Flt(SWC_HSPF_DW.UnitDelay_DSTATE_h);

  /* Outport: '<Root>/PP_SWC_HSPF_HSPF_nSlowFlt' */
  (void) Rte_Write_PP_SWC_HSPF_HSPF_nSlowFlt(SWC_HSPF_DW.UnitDelay_DSTATE_b);

  /* Outport: '<Root>/PP_SWC_HSPF_HSPF_tCoolantTempFlt' */
  (void) Rte_Write_PP_SWC_HSPF_HSPF_tCoolantTempFlt
    (SWC_HSPF_DW.UnitDelay_DSTATE_n);

  /* Outport: '<Root>/PP_SWC_HSPF_HSPF_tDrvBoardTempFlt' */
  (void) Rte_Write_PP_SWC_HSPF_HSPF_tDrvBoardTempFlt
    (SWC_HSPF_DW.UnitDelay_DSTATE_nl);

  /* Outport: '<Root>/PP_SWC_HSPF_HSPF_iDcLnkEstFlt' */
  (void) Rte_Write_PP_SWC_HSPF_HSPF_iDcLnkEstFlt(SWC_HSPF_DW.UnitDelay_DSTATE_bm);

  /* Outport: '<Root>/PP_SWC_HSPF_HSPF_bt15' */
  (void) Rte_Write_PP_SWC_HSPF_HSPF_bt15(SWC_HSPF_DW.UnitDelay2_DSTATE_f);

  /* Outport: '<Root>/PP_SWC_HSPF_HSPF_flgCrash' */
  (void) Rte_Write_PP_SWC_HSPF_HSPF_flgCrash(SWC_HSPF_DW.UnitDelay2_DSTATE_ns);

  /* Outport: '<Root>/PP_SWC_HSPF_HSPF_INV_Open' */
  (void) Rte_Write_PP_SWC_HSPF_HSPF_INV_Open(SWC_HSPF_DW.UnitDelay2_DSTATE_o);

  /* Outport: '<Root>/PP_SWC_HSPF_HSPF_Motor_Open' */
  (void) Rte_Write_PP_SWC_HSPF_HSPF_Motor_Open(SWC_HSPF_DW.UnitDelay2_DSTATE_l);

  /* Outport: '<Root>/PP_SWC_HSPF_HSPF_uDcLnkSlowFlt' */
  (void) Rte_Write_PP_SWC_HSPF_HSPF_uDcLnkSlowFlt
    (SWC_HSPF_DW.UnitDelay_DSTATE_ji);

  /* Outport: '<Root>/PP_SWC_HSPF_HSPF_Wake' */
  (void) Rte_Write_PP_SWC_HSPF_HSPF_Wake(SWC_HSPF_DW.UnitDelay2_DSTATE_fs);

  /* Outport: '<Root>/PP_SWC_HSPF_HSPF_iPhaUOffset' */
  (void) Rte_Write_PP_SWC_HSPF_HSPF_iPhaUOffset(SWC_HSPF_B.HSPF_iOffset_c);

  /* Outport: '<Root>/PP_SWC_HSPF_HSPF_iPhaVOffset' */
  (void) Rte_Write_PP_SWC_HSPF_HSPF_iPhaVOffset(SWC_HSPF_B.HSPF_iOffset_i);

  /* Outport: '<Root>/PP_SWC_HSPF_HSPF_iPhaWOffset' */
  (void) Rte_Write_PP_SWC_HSPF_HSPF_iPhaWOffset(SWC_HSPF_B.HSPF_iOffset);

  /* Outport: '<Root>/PP_SWC_HSPF_HSPF_stIphaOffCal' */
  (void) Rte_Write_PP_SWC_HSPF_HSPF_stIphaOffCal(SWC_HSPF_B.Switch);

  /* Outport: '<Root>/PP_SWC_HSPF_HSPF_tCoolantTjFlt' */
  (void) Rte_Write_PP_SWC_HSPF_HSPF_tCoolantTjFlt(SWC_HSPF_DW.UnitDelay_DSTATE_o);
}

/* Model initialize function */
void SWC_HSPF_Init(void)
{
  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_HSPF_10ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_HSPF_10ms_sys'
   */
  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay' */
  SWC_HSPF_DW.UnitDelay_DSTATE_e = true;

  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_HSPF_10ms' */

  /* SystemInitialize for Outport: '<Root>/PP_SWC_HSPF_HSPF_iPhaUOffset' */
  (void) Rte_Write_PP_SWC_HSPF_HSPF_iPhaUOffset(SWC_HSPF_B.HSPF_iOffset_c);

  /* SystemInitialize for Outport: '<Root>/PP_SWC_HSPF_HSPF_iPhaVOffset' */
  (void) Rte_Write_PP_SWC_HSPF_HSPF_iPhaVOffset(SWC_HSPF_B.HSPF_iOffset_i);

  /* SystemInitialize for Outport: '<Root>/PP_SWC_HSPF_HSPF_iPhaWOffset' */
  (void) Rte_Write_PP_SWC_HSPF_HSPF_iPhaWOffset(SWC_HSPF_B.HSPF_iOffset);

  /* SystemInitialize for Outport: '<Root>/PP_SWC_HSPF_HSPF_stIphaOffCal' */
  (void) Rte_Write_PP_SWC_HSPF_HSPF_stIphaOffCal(SWC_HSPF_B.Switch);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
