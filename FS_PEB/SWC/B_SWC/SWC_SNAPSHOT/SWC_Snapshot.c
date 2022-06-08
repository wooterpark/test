/*
 * File: SWC_Snapshot.c
 *
 * Code generated for Simulink model 'SWC_Snapshot'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Jul 29 16:06:59 2020
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWC_Snapshot.h"
#include "SWC_Snapshot_private.h"

/* Model step function for TID1 */
void SWC_SnapshotRam_FastInfoMainFunction_Task_100us(void)
                  /* Explicit Task: RE_SnapshotRam_FastInfoMainFunction_100us */
{
  uint16 tmpRead;
  uint16 tmpRead_0;
  uint16 tmpRead_1;
  float32 tmpRead_2;
  float32 tmpRead_3;
  SnapshotFastRam_RteInfo_S rtb_BusConversion_InsertedFor_l;

  /* Inport: '<Root>/RP_SWC_Rdc_Rdc_ArctanAgRtr' */
  Rte_Read_RP_SWC_Rdc_Rdc_ArctanAgRtr(&tmpRead_3);

  /* Inport: '<Root>/RP_SWC_HvMcu_HvMcu_uDcLnkHvMcu' */
  Rte_Read_RP_SWC_HvMcu_HvMcu_uDcLnkHvMcu(&tmpRead_2);

  /* Inport: '<Root>/RP_SWC_PhC_PhC_iWNoOff' */
  Rte_Read_RP_SWC_PhC_PhC_iWNoOff(&tmpRead_1);

  /* Inport: '<Root>/RP_SWC_PhC_PhC_iVNoOff' */
  Rte_Read_RP_SWC_PhC_PhC_iVNoOff(&tmpRead_0);

  /* Inport: '<Root>/RP_SWC_PhC_PhC_iUNoOff' */
  Rte_Read_RP_SWC_PhC_PhC_iUNoOff(&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SnapshotRam_FastInfoMainFunction_100us' incorporates:
   *  SubSystem: '<Root>/RE_SnapshotRam_FastInfoMainFunction_100us_sys'
   */
  /* BusCreator generated from: '<S1>/C Caller' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion1'
   *  DataTypeConversion: '<S1>/Data Type Conversion2'
   *  DataTypeConversion: '<S1>/Data Type Conversion3'
   */
  rtb_BusConversion_InsertedFor_l.FastVar0 = tmpRead_2;
  rtb_BusConversion_InsertedFor_l.FastVar1 = tmpRead;
  rtb_BusConversion_InsertedFor_l.FastVar2 = tmpRead_0;
  rtb_BusConversion_InsertedFor_l.FastVar3 = tmpRead_1;
  rtb_BusConversion_InsertedFor_l.FastVar4 = tmpRead_3;

  /* CCaller: '<S1>/C Caller' */
  SnapshotRam_UpdateFastInfo(&rtb_BusConversion_InsertedFor_l);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SnapshotRam_FastInfoMainFunction_100us' */
}

/* Model step function for TID2 */
void SWC_SnapshotCan_MainFunction_Task_10ms(void)
                              /* Explicit Task: RE_Snapshot_MainFunction_10ms */
{
  uint16 tmpRead;
  SnapshotSlowRam_RteInfo_S rtb_BusConversion_InsertedFor_C;
  float32 rtb_RP_SWC_IoHwAb_ADC_BSW_UBR_V;
  float32 rtb_RP_SWC_IoHwAb_ADC_BSW_VDD18;
  float32 rtb_RP_SWC_IoHwAb_ADC_BSW_VDD5T;
  float32 rtb_RP_SWC_IoHwAb_ADC_BSW_VDD_f;

  /* Inport: '<Root>/RP_SWC_HvMcu_HvMcu_VDD15L_Vol' */
  Rte_Read_RP_SWC_HvMcu_HvMcu_VDD15L_Vol(&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_Snapshot_MainFunction_10ms' incorporates:
   *  SubSystem: '<Root>/RE_Snapshot_MainFunction_10ms_sys'
   */
  /* FunctionCaller: '<S2>/RP_SWC_IoHwAb_ADC_BSW_UBR_Vol_IoHwAb_ADC_GetPhyVoltage' incorporates:
   *  Constant: '<S2>/Constant'
   */
  Rte_Call_RP_SWC_IoHwAb_ADC_BSW_UBR_Vol_IoHwAb_ADC_GetPhyVoltage(0,
    &rtb_RP_SWC_IoHwAb_ADC_BSW_UBR_V);

  /* FunctionCaller: '<S2>/RP_SWC_IoHwAb_ADC_BSW_VDD18L_Vol_IoHwAb_ADC_GetPhyVoltage' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  Rte_Call_RP_SWC_IoHwAb_ADC_BSW_VDD18L_Vol_IoHwAb_ADC_GetPhyVoltage(25,
    &rtb_RP_SWC_IoHwAb_ADC_BSW_VDD18);

  /* FunctionCaller: '<S2>/RP_SWC_IoHwAb_ADC_BSW_VDD5T1_Vol_IoHwAb_ADC_GetPhyVoltage' incorporates:
   *  Constant: '<S2>/Constant2'
   */
  Rte_Call_RP_SWC_IoHwAb_ADC_BSW_VDD5T1_Vol_IoHwAb_ADC_GetPhyVoltage(3,
    &rtb_RP_SWC_IoHwAb_ADC_BSW_VDD5T);

  /* FunctionCaller: '<S2>/RP_SWC_IoHwAb_ADC_BSW_VDD5T2_Vol_IoHwAb_ADC_GetPhyVoltage' incorporates:
   *  Constant: '<S2>/Constant3'
   */
  Rte_Call_RP_SWC_IoHwAb_ADC_BSW_VDD5T2_Vol_IoHwAb_ADC_GetPhyVoltage(5,
    &rtb_RP_SWC_IoHwAb_ADC_BSW_VDD_f);

  /* BusCreator generated from: '<S2>/C Caller1' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion4'
   */
  rtb_BusConversion_InsertedFor_C.SlowVar0 = tmpRead;
  rtb_BusConversion_InsertedFor_C.SlowVar1 = rtb_RP_SWC_IoHwAb_ADC_BSW_UBR_V;
  rtb_BusConversion_InsertedFor_C.SlowVar2 = rtb_RP_SWC_IoHwAb_ADC_BSW_VDD18;
  rtb_BusConversion_InsertedFor_C.SlowVar3 = rtb_RP_SWC_IoHwAb_ADC_BSW_VDD5T;
  rtb_BusConversion_InsertedFor_C.SlowVar4 = rtb_RP_SWC_IoHwAb_ADC_BSW_VDD_f;

  /* CCaller: '<S2>/C Caller1' */
  SnapshotRam_UpdateSlowInfo(&rtb_BusConversion_InsertedFor_C);

  /* CCaller: '<S2>/C Caller2' */
  SnapshotCan_MainFunction();

  /* CCaller: '<S2>/C Caller3' */
  //SnapshotDu_MainFunction();

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_Snapshot_MainFunction_10ms' */
}

/* Model initialize function */
void SWC_Snapshot_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
