/*
 * File: SWC_SWD.h
 *
 * Code generated for Simulink model 'SWC_SWD'.
 *
 * Model version                  : 1.555
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Jan 12 17:55:55 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_SWD_h_
#define RTW_HEADER_SWC_SWD_h_
#include <math.h>
#ifndef SWC_SWD_COMMON_INCLUDES_
# define SWC_SWD_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* SWC_SWD_COMMON_INCLUDES_ */

#include "SWC_SWD_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Exported data define */

/* Definition for custom storage class: Define */
#define GLB_SWD_CircAge_f32            360.0F                    /* Referenced by:
                                                                  * '<S5>/GLB_SWD_CircAge_f32'
                                                                  * '<S5>/GLB_TOM_CircAge_f1'
                                                                  * '<S5>/GLB_TOM_CircAge_f2'
                                                                  * '<S12>/GLB_TOM_CircAge_f1'
                                                                  * '<S12>/GLB_TOM_CircAge_f2'
                                                                  * '<S12>/GLB_TOM_CircAge_f6'
                                                                  */
#define GLB_SWD_MotorPole_u8           4U                        /* Referenced by: '<S5>/GLB_SWD_MotorPole_u8' */
#define GLB_SWD_OneHalf_f32            0.5F                      /* Referenced by: '<S12>/GLB_TOM_CircAge_f5' */
#define GLB_SWD_Sixty_f32              60.0F                     /* Referenced by: '<S5>/GLB_SWD_Sixty_f32' */
#define GLB_SWD_pi_f32                 3.14159203F               /* Referenced by: '<S5>/Constant6' */

/* Block states (default storage) for system '<Root>' */
typedef struct {
  float32 Delay1_DSTATE;               /* '<S13>/Delay1' */
  float32 Delay10_DSTATE[2];           /* '<S13>/Delay10' */
  float32 Delay9_DSTATE[3];            /* '<S13>/Delay9' */
  float32 Delay7_DSTATE[4];            /* '<S13>/Delay7' */
  float32 Delay6_DSTATE[5];            /* '<S13>/Delay6' */
  float32 Delay5_DSTATE[6];            /* '<S13>/Delay5' */
  float32 Delay4_DSTATE[7];            /* '<S13>/Delay4' */
  float32 Delay3_DSTATE[8];            /* '<S13>/Delay3' */
  float32 Delay2_DSTATE[9];            /* '<S13>/Delay2' */
  float32 Delay8_DSTATE;               /* '<S13>/Delay8' */
  float32 Delay11_DSTATE[2];           /* '<S13>/Delay11' */
  float32 Delay18_DSTATE[3];           /* '<S13>/Delay18' */
  float32 Delay17_DSTATE[4];           /* '<S13>/Delay17' */
  float32 Delay16_DSTATE[5];           /* '<S13>/Delay16' */
  float32 Delay15_DSTATE[6];           /* '<S13>/Delay15' */
  float32 Delay14_DSTATE[7];           /* '<S13>/Delay14' */
  float32 Delay13_DSTATE[8];           /* '<S13>/Delay13' */
  float32 Delay12_DSTATE[9];           /* '<S13>/Delay12' */
  float32 UnitDelay_DSTATE;            /* '<S12>/Unit Delay' */
} DW_SWC_SWD_T;

/* Real-time Model Data Structure */
struct tag_RTM_SWC_SWD_T {
  const char_T *errorStatus;
};

/* Block states (default storage) */
extern DW_SWC_SWD_T SWC_SWD_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern float32 VAR_SWD_Spd_f32;        /* '<S13>/Divide' */
extern float32 VAR_SWD_AgRslvDelta0_f32;/* '<S12>/Add2' */
extern float32 VAR_SWD_AgRslvDelta_f32;/* '<S12>/Switch2' */
extern float32 VAR_SWD_Tan_f32;        /* '<S6>/Abs2' */
extern float32 VAR_SWD_AgRslv45_f32;   /* '<S5>/Data Type Conversion1' */
extern float32 VAR_SWD_AgRslv_f32;     /* '<S5>/Switch' */

/* Model entry point functions */
extern void SWC_SWD_initialize(void);
extern void SWC_SWD_terminate(void);

/* Exported entry point function */
extern void SWC_SWD_100us(void);

/* Exported data declaration */
#pragma section ".rodata.Calib_32"

/* Declaration for custom storage class: iEDS_Parameter */
extern const volatile float32 CAL_SWD_AgrslvCompCnt_f32;
                           /* Referenced by: '<S5>/CAL_SWD_AgrslvCompCnt_f32' */
extern const volatile uint8 CAL_SWD_MotorPole_u8;
                               /* Referenced by: '<S13>/GLB_TOM_MotorPole_u8' */
extern const volatile uint16 CAL_SWD_Radian_u16[1025];
                           /* Referenced by: '<S5>/Direct Lookup Table (n-D)' */

#pragma section

/* Real-time Model object */
extern RT_MODEL_SWC_SWD_T *const SWC_SWD_M;

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
 * '<Root>' : 'SWC_SWD'
 * '<S1>'   : 'SWC_SWD/SWC_SWD_100us_sys'
 * '<S2>'   : 'SWC_SWD/SWC_SWD_Init'
 * '<S3>'   : 'SWC_SWD/SWC_SWD_100us_sys/SWDecode'
 * '<S4>'   : 'SWC_SWD/SWC_SWD_100us_sys/SpdCalc'
 * '<S5>'   : 'SWC_SWD/SWC_SWD_100us_sys/SWDecode/AgRslvCalc'
 * '<S6>'   : 'SWC_SWD/SWC_SWD_100us_sys/SWDecode/TanCalc'
 * '<S7>'   : 'SWC_SWD/SWC_SWD_100us_sys/SWDecode/AgRslvCalc/Compare To Constant2'
 * '<S8>'   : 'SWC_SWD/SWC_SWD_100us_sys/SWDecode/AgRslvCalc/Compare To Constant3'
 * '<S9>'   : 'SWC_SWD/SWC_SWD_100us_sys/SWDecode/AgRslvCalc/Compare To Constant4'
 * '<S10>'  : 'SWC_SWD/SWC_SWD_100us_sys/SWDecode/AgRslvCalc/Compare To Constant5'
 * '<S11>'  : 'SWC_SWD/SWC_SWD_100us_sys/SWDecode/TanCalc/Compare To Constant1'
 * '<S12>'  : 'SWC_SWD/SWC_SWD_100us_sys/SpdCalc/AgRslvDeltaCalc'
 * '<S13>'  : 'SWC_SWD/SWC_SWD_100us_sys/SpdCalc/SpdCalc'
 */
#endif                                 /* RTW_HEADER_SWC_SWD_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
