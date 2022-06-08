/*
 * File: SWC_HvMcu.c
 *
 * Code generated for Simulink model 'SWC_HvMcu'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sun Jun 28 17:21:32 2020
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWC_HvMcu.h"
#include "SWC_HvMcu_private.h"

/* Block signals (default storage) */
B_SWC_HvMcu_T SWC_HvMcu_B;

/* Model step function for TID1 */
void SWC_HvMcu_Task_100us(void)        /* Explicit Task: RE_HvMcu_100us */
{
  boolean tmpRead;
  HvMcu_InPut_S rtb_BusConversion_InsertedFor_l;

  /* Inport: '<Root>/RP_SWC_SCF_SCF_flgEmgReqInvDcha' */
  Rte_Read_RP_SWC_SCF_SCF_flgEmgReqInvDcha(&tmpRead);
  rtb_BusConversion_InsertedFor_l.EmDisChrgFlg = tmpRead;
  /*hlj Mannul modified due to the generation err of Matlab */
  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_HvMcu_100us' incorporates:
   *  SubSystem: '<Root>/RE_HvMcu_100us_sys'
   */
  /* CCaller: '<S1>/C Caller1' */
  HvMcu_Com_Uart(&rtb_BusConversion_InsertedFor_l, &SWC_HvMcu_B.CCaller);
  /* CCaller: '<S1>/C Caller' */
  PosLearn_Inter_Ctrl(&SWC_HvMcu_B.CCaller1);

  /* Outport: '<Root>/PP_SWC_HvMcu_HvMcu_flgUphaEdgeRiseCo' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion4'
   */
  (void) Rte_Write_PP_SWC_HvMcu_HvMcu_flgUphaEdgeRiseCo
    (SWC_HvMcu_B.CCaller1.SampleValid != 0);

  /* BusCreator generated from: '<S1>/C Caller' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion5'
   */
  //rtb_BusConversion_InsertedFor_l.EmDisChrgFlg = tmpRead;
  /*hlj Mannul modified due to the generation err of Matlab */
  /* CCaller: '<S1>/C Caller' */
  /* Outport: '<Root>/PP_SWC_HvMcu_HvMcu_uBackEMF_U' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion1'
   */
  (void) Rte_Write_PP_SWC_HvMcu_HvMcu_uBackEMF_U(SWC_HvMcu_B.CCaller.EMF_Voltg_U);

  /* Outport: '<Root>/PP_SWC_HvMcu_HvMcu_uBackEMF_V' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion2'
   */
  (void) Rte_Write_PP_SWC_HvMcu_HvMcu_uBackEMF_V(SWC_HvMcu_B.CCaller.EMF_Voltg_V);

  /* Outport: '<Root>/PP_SWC_HvMcu_HvMcu_uBackEMF_W' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion3'
   */
  (void) Rte_Write_PP_SWC_HvMcu_HvMcu_uBackEMF_W(SWC_HvMcu_B.CCaller.EMF_Voltg_W);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_HvMcu_100us' */

  /* Outport: '<Root>/PP_SWC_HvMcu_HvMcu_AlOfsClb_TimeStamp' */
  (void) Rte_Write_PP_SWC_HvMcu_HvMcu_AlOfsClb_TimeStamp
    (SWC_HvMcu_B.CCaller1.TimeCompAll);

  /* Outport: '<Root>/PP_SWC_HvMcu_HvMcu_uDcLnkHvMcu' */
  (void) Rte_Write_PP_SWC_HvMcu_HvMcu_uDcLnkHvMcu(SWC_HvMcu_B.CCaller.UdcValue);

  /* Outport: '<Root>/PP_SWC_HvMcu_HvMcu_tDBCTempU' */
  (void) Rte_Write_PP_SWC_HvMcu_HvMcu_tDBCTempU(SWC_HvMcu_B.CCaller.IGBT_Temp_U);

  /* Outport: '<Root>/PP_SWC_HvMcu_HvMcu_tDBCTempV' */
  (void) Rte_Write_PP_SWC_HvMcu_HvMcu_tDBCTempV(SWC_HvMcu_B.CCaller.IGBT_Temp_V);

  /* Outport: '<Root>/PP_SWC_HvMcu_HvMcu_tDBCTempW' */
  (void) Rte_Write_PP_SWC_HvMcu_HvMcu_tDBCTempW(SWC_HvMcu_B.CCaller.IGBT_Temp_W);

  /* Outport: '<Root>/PP_SWC_HvMcu_HvMcu_HvMcuVer' */
  (void) Rte_Write_PP_SWC_HvMcu_HvMcu_HvMcuVer(SWC_HvMcu_B.CCaller.Sw_Version);

  /* Outport: '<Root>/PP_SWC_HvMcu_HvMcu_tDrvBoardTemp' */
  (void) Rte_Write_PP_SWC_HvMcu_HvMcu_tDrvBoardTemp
    (SWC_HvMcu_B.CCaller.DrvBoard_Temp);

  /* Outport: '<Root>/PP_SWC_HvMcu_HvMcu_VDD15L_Vol' */
  (void) Rte_Write_PP_SWC_HvMcu_HvMcu_VDD15L_Vol(SWC_HvMcu_B.CCaller.VDD15L_Vol);
}

/* Model step function for TID2 */
void SWC_HvMcu_Task_2ms(void)          /* Explicit Task: RE_HvMcu_2ms */
{
  uint8 tmpRead;
  PosCal_InPut_S rtb_BusConversion_InsertedFor_C;

  /* Inport: '<Root>/RP_SWC_RCF_RCF_stAgRtrOfsCal' */
  Rte_Read_RP_SWC_RCF_RCF_stAgRtrOfsCal(&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_HvMcu_2ms' incorporates:
   *  SubSystem: '<Root>/RE_HvMcu_2ms_sys'
   */
  /* BusCreator generated from: '<S2>/C Caller' */
  rtb_BusConversion_InsertedFor_C.App_Ctrl = tmpRead;

  /* CCaller: '<S2>/C Caller' */
  PosLearn_Task_Ctrl(&rtb_BusConversion_InsertedFor_C);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_HvMcu_2ms' */
}

/* Model initialize function */
void SWC_HvMcu_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
