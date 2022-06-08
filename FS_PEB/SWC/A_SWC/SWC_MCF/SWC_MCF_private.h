/*
 * File: SWC_MCF_private.h
 *
 * Code generated for Simulink model 'SWC_MCF'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Mon Jan 25 16:58:23 2021
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_MCF_private_h_
#define RTW_HEADER_SWC_MCF_private_h_
#include "rtwtypes.h"
#include "SWC_MCF.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

extern const float32 rtCP_pooled_lRa8o5hRGBX2[4096];
extern const float32 rtCP_pooled_7EBUHCewpktf[4096];
extern const float32 rtCP_pooled_Bh75GlUU3XVK[6];
extern const float32 rtCP_pooled_AF8s6d0pwfT5[6];
extern const float32 rtCP_pooled_HX74WORaU2Uv[6];
extern const float32 rtCP_pooled_d0Rw9Fa8SJyj[6];
extern const float32 rtCP_pooled_1mfAfq82KMlL[7168];
extern const float32 rtCP_pooled_I3FPh32EaiBC[1024];
extern const float32 rtCP_pooled_SWe1yiAh0Q0i[7];
extern const float32 rtCP_pooled_WZltfjIEz15y[1024];
extern const uint32 rtCP_pooled_ILBMoq4R8vx2[2];
extern const uint16 rtCP_pooled_5tL1grgvQpCw[1025];

#define rtCP_Constant_Value_d          rtCP_pooled_lRa8o5hRGBX2  /* Expression: MCF_COSTABLE
                                                                  * Referenced by: '<S50>/Constant'
                                                                  */
#define rtCP_McFwc_SinTable_table      rtCP_pooled_7EBUHCewpktf  /* Expression: MCF_SINTABLE
                                                                  * Referenced by: '<S54>/McFwc_SinTable'
                                                                  */
#define rtCP_DirectLookupTablenD_table rtCP_pooled_Bh75GlUU3XVK  /* Expression: MCF_CoefDeadCpnTabY_Alpha1_af32
                                                                  * Referenced by: '<S65>/Direct Lookup Table (n-D)'
                                                                  */
#define rtCP_DirectLookupTablenD1_table rtCP_pooled_AF8s6d0pwfT5 /* Expression: MCF_CoefDeadCpnTabY_Alpha2_af32
                                                                  * Referenced by: '<S65>/Direct Lookup Table (n-D)1'
                                                                  */
#define rtCP_DirectLookupTablenD2_table rtCP_pooled_HX74WORaU2Uv /* Expression: MCF_CoefDeadCpnTabY_Beta1_af32
                                                                  * Referenced by: '<S65>/Direct Lookup Table (n-D)2'
                                                                  */
#define rtCP_DirectLookupTablenD3_table rtCP_pooled_d0Rw9Fa8SJyj /* Expression: MCF_CoefDeadCpnTabY_Beta2_af32
                                                                  * Referenced by: '<S65>/Direct Lookup Table (n-D)3'
                                                                  */
#define rtCP_LookupCosTable_table      rtCP_pooled_lRa8o5hRGBX2  /* Expression: MCF_COSTABLE

                                                                  * Referenced by: '<S87>/LookupCosTable'
                                                                  */
#define rtCP_LookupCosineTab_table     rtCP_pooled_lRa8o5hRGBX2  /* Expression: MCF_COSTABLE
                                                                  * Referenced by: '<S89>/LookupCosineTab'
                                                                  */
#define rtCP_LookupSineTab_table       rtCP_pooled_7EBUHCewpktf  /* Expression: MCF_SINTABLE
                                                                  * Referenced by: '<S89>/LookupSineTab'
                                                                  */
#define rtCP_LookupSinTable_table      rtCP_pooled_7EBUHCewpktf  /* Expression: MCF_SINTABLE

                                                                  * Referenced by: '<S87>/LookupSinTable'
                                                                  */
#define rtCP_OmTable_tableData         rtCP_pooled_1mfAfq82KMlL  /* Expression: MCF_OmTable_af32
                                                                  * Referenced by: '<S168>/OmTable'
                                                                  */
#define rtCP_OmTable_bp01Data          rtCP_pooled_I3FPh32EaiBC  /* Computed Parameter: rtCP_OmTable_bp01Data
                                                                  * Referenced by: '<S168>/OmTable'
                                                                  */
#define rtCP_OmTable_bp02Data          rtCP_pooled_SWe1yiAh0Q0i  /* Computed Parameter: rtCP_OmTable_bp02Data
                                                                  * Referenced by: '<S168>/OmTable'
                                                                  */
#define rtCP_Constant_Value_o0         rtCP_pooled_WZltfjIEz15y  /* Computed Parameter: rtCP_Constant_Value_o0
                                                                  * Referenced by: '<S119>/Constant'
                                                                  */
#define rtCP_LookupCosTable_table_j    rtCP_pooled_lRa8o5hRGBX2  /* Expression: MCF_COSTABLE
                                                                  * Referenced by: '<S14>/LookupCosTable'
                                                                  */
#define rtCP_LookupSinTable_table_o    rtCP_pooled_7EBUHCewpktf  /* Expression: MCF_SINTABLE
                                                                  * Referenced by: '<S14>/LookupSinTable'
                                                                  */
#define rtCP_LookupCosTable_table_k    rtCP_pooled_lRa8o5hRGBX2  /* Expression: MCF_COSTABLE
                                                                  * Referenced by: '<S177>/LookupCosTable'
                                                                  */
#define rtCP_LookupSinTable_table_k    rtCP_pooled_7EBUHCewpktf  /* Expression: MCF_SINTABLE
                                                                  * Referenced by: '<S177>/LookupSinTable'
                                                                  */
#define rtCP_OmTable_maxIndex          rtCP_pooled_ILBMoq4R8vx2  /* Computed Parameter: rtCP_OmTable_maxIndex
                                                                  * Referenced by: '<S168>/OmTable'
                                                                  */
#define rtCP_DirectLookupTablenD_table_ rtCP_pooled_5tL1grgvQpCw /* Computed Parameter: rtCP_DirectLookupTablenD_table_
                                                                  * Referenced by: '<S74>/Direct Lookup Table (n-D)'
                                                                  */
#define rtCP_DirectLookupTablenD_tabl_h rtCP_pooled_5tL1grgvQpCw /* Computed Parameter: rtCP_DirectLookupTablenD_tabl_h
                                                                  * Referenced by: '<S171>/Direct Lookup Table (n-D)'
                                                                  */

extern void SWC_MCF_Osc_nrN6(float32 rtu_MCF_tiY, float32 rtu_MCF_tiZ, float32
  *rty_MCF_tiYout, float32 *rty_MCF_tiZout);

#endif                                 /* RTW_HEADER_SWC_MCF_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
