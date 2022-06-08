/*
 * File: RDC.h
 *
 * Code generated for Simulink model 'RDC'.
 *
 * Model version                  : 1.335
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Dec 24 13:01:34 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_RDC_h_
#define RTW_HEADER_RDC_h_
#include <math.h>
#ifndef RDC_COMMON_INCLUDES_
# define RDC_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* RDC_COMMON_INCLUDES_ */

#include "RDC_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Exported data define */

/* Definition for custom storage class: Define */
#define GLB_RDC_CircAge_f32            360.0F                    /* Referenced by:
                                                                  * '<S5>/GLB_RDC_CircAge_f32'
                                                                  * '<S7>/GLB_RDC_CircAge_f32'
                                                                  * '<S14>/GLB_RDC_CircAge_f32'
                                                                  * '<S19>/GLB_RDC_CircAge_f32'
                                                                  */
#define GLB_RDC_MotorPole_u8           4U                        /* Referenced by:
                                                                  * '<S1>/GLB_RDC_MotorPole_u8'
                                                                  * '<S15>/GLB_RDC_MotorPole_u8'
                                                                  */
#define GLB_RDC_OneHalf_f32            0.5F                      /* Referenced by:
                                                                  * '<S6>/GLB_RDC_OneHalf_f32'
                                                                  * '<S14>/GLB_RDC_OneHalf_f32'
                                                                  */
#define GLB_RDC_Sixty_f32              60.0F                     /* Referenced by: '<S5>/GLB_RDC_Sixty_f32' */

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE_c;         /* '<S14>/Unit Delay' */
  real32_T Delay1_DSTATE;              /* '<S15>/Delay1' */
  real32_T Delay10_DSTATE[2];          /* '<S15>/Delay10' */
  real32_T Delay9_DSTATE[3];           /* '<S15>/Delay9' */
  real32_T Delay7_DSTATE[4];           /* '<S15>/Delay7' */
  real32_T Delay6_DSTATE[5];           /* '<S15>/Delay6' */
  real32_T Delay5_DSTATE[6];           /* '<S15>/Delay5' */
  real32_T Delay4_DSTATE[7];           /* '<S15>/Delay4' */
  real32_T Delay3_DSTATE[8];           /* '<S15>/Delay3' */
  real32_T Delay2_DSTATE[9];           /* '<S15>/Delay2' */
  real32_T Delay8_DSTATE;              /* '<S15>/Delay8' */
  real32_T Delay11_DSTATE[2];          /* '<S15>/Delay11' */
  real32_T Delay18_DSTATE[3];          /* '<S15>/Delay18' */
  real32_T Delay17_DSTATE[4];          /* '<S15>/Delay17' */
  real32_T Delay16_DSTATE[5];          /* '<S15>/Delay16' */
  real32_T Delay15_DSTATE[6];          /* '<S15>/Delay15' */
  real32_T Delay14_DSTATE[7];          /* '<S15>/Delay14' */
  real32_T Delay13_DSTATE[8];          /* '<S15>/Delay13' */
  real32_T Delay12_DSTATE[9];          /* '<S15>/Delay12' */
  real32_T UnitDelay_DSTATE_o;         /* '<S4>/Unit Delay' */
  uint16_T UnitDelay_DSTATE_h;         /* '<S15>/Unit Delay' */
} DW_RDC_T;

/* Real-time Model Data Structure */
struct tag_RTM_RDC_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_RDC_T RDC_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T VAR_CDD_Rslv_Sin_f32;  /* '<Root>/CDD_Rslv_Sin' */
extern real32_T VAR_CDD_Rslv_Cos_f32;  /* '<Root>/CDD_Rslv_Cos' */
extern real32_T VAR_CDD_RslvTimeStamp_f32;/* '<Root>/CDD_RslvTimeStamp' */
extern real32_T VAR_CDD_Rslv_TimeGp_f32;/* '<Root>/CDD_Rslv_TimeGp' */
extern real32_T VAR_CDD_Rslv_SinMax_f32;/* '<Root>/CDD_Rslv_SinMax' */
extern real32_T VAR_CDD_Rslv_SinMin_f32;/* '<Root>/CDD_Rslv_SinMin' */
extern real32_T VAR_CDD_Rslv_CosMax_f32;/* '<Root>/CDD_Rslv_CosMax' */
extern real32_T VAR_CDD_Rslv_CosMin_f32;/* '<Root>/CDD_Rslv_CosMin' */
extern real32_T VAR_MCF_cofFrqPwm_f32; /* '<Root>/MCF_cofFrqPwm' */
extern uint8_T VAR_LvPower_PowerUpFnh_u8;/* '<Root>/LvPower_LvPowerUpFnh' */
extern real32_T VAR_RDC_nWoFlt_f32;    /* '<S4>/Switch' */
extern real32_T VAR_RDC_ArctanAgRtr_f32;/* '<S19>/Switch' */
extern boolean_T VAR_RDC_flgSpdHorL_b; /* '<S18>/Switch1' */
extern boolean_T VAR_RDC_flgLotErr_b;  /* '<S14>/Relational Operator4' */

/* Model entry point functions */
extern void RDC_initialize(void);
extern void RDC_step(void);
extern void RDC_terminate(void);

/* Exported data declaration */
#pragma section ".rodata.Calib_32"

/* Declaration for custom storage class: iEDS_Parameter */
extern const volatile real32_T CAL_RDC_NRestrict_f32;
                               /* Referenced by: '<S6>/CAL_RDC_NRestrict_f32' */
extern const volatile real32_T CAL_RDC_Nset_f32;
                                    /* Referenced by: '<S4>/CAL_RDC_Nset_f32' */
extern const volatile real32_T CAL_RDC_SpdHiHyst_f32;
                              /* Referenced by: '<S18>/CAL_RDC_SpdHiHyst_f32' */
extern const volatile real32_T CAL_RDC_SpdHi_f32;
                                  /* Referenced by: '<S18>/CAL_RDC_SpdHi_f32' */
extern const volatile boolean_T CAL_RDC_flgCorrectOrReal_b;
                          /* Referenced by: '<S6>/CAL_RDC_flgCorrectOrReal_b' */
extern const volatile boolean_T CAL_RDC_flgNrealOrNset_b;
                            /* Referenced by: '<S4>/CAL_RDC_flgNrealOrNset_b' */
extern const volatile uint16_T CAL_RDC_nWofltDelay_u16;
                            /* Referenced by: '<S15>/CAL_RDC_nWofltDelay_u16' */
extern const volatile real32_T CAL_RDC_tiRsvlAngleSample_f32;
                        /* Referenced by: '<S5>/CAL_RDC_tiRsvlAngleSample_f1' */

#pragma section

/* Real-time Model object */
extern RT_MODEL_RDC_T *const RDC_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Propagation' : Unused code path elimination
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
 * '<Root>' : 'RDC'
 * '<S1>'   : 'RDC/RDC'
 * '<S2>'   : 'RDC/RDC/ResolverSoftDecoding'
 * '<S3>'   : 'RDC/RDC/SpdCal'
 * '<S4>'   : 'RDC/RDC/agRtrCmp'
 * '<S5>'   : 'RDC/RDC/ResolverSoftDecoding/CompTheta'
 * '<S6>'   : 'RDC/RDC/ResolverSoftDecoding/SinOrCosCal'
 * '<S7>'   : 'RDC/RDC/ResolverSoftDecoding/Theta_Real'
 * '<S8>'   : 'RDC/RDC/ResolverSoftDecoding/SinOrCosCal/Subsystem1'
 * '<S9>'   : 'RDC/RDC/ResolverSoftDecoding/SinOrCosCal/Subsystem1/Compare To Constant'
 * '<S10>'  : 'RDC/RDC/ResolverSoftDecoding/SinOrCosCal/Subsystem1/Compare To Constant1'
 * '<S11>'  : 'RDC/RDC/ResolverSoftDecoding/SinOrCosCal/Subsystem1/Compare To Constant2'
 * '<S12>'  : 'RDC/RDC/ResolverSoftDecoding/SinOrCosCal/Subsystem1/Compare To Constant3'
 * '<S13>'  : 'RDC/RDC/ResolverSoftDecoding/SinOrCosCal/Subsystem1/Compare To Constant4'
 * '<S14>'  : 'RDC/RDC/SpdCal/Delta_Theta'
 * '<S15>'  : 'RDC/RDC/SpdCal/nCalcaulate'
 * '<S16>'  : 'RDC/RDC/SpdCal/nCalcaulate/Saturation Dynamic'
 * '<S17>'  : 'RDC/RDC/agRtrCmp/Rem360'
 * '<S18>'  : 'RDC/RDC/agRtrCmp/Subsystem'
 * '<S19>'  : 'RDC/RDC/agRtrCmp/agRtr'
 */
#endif                                 /* RTW_HEADER_RDC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
