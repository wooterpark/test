/*
 * File: SWC_BCC_private.h
 *
 * Code generated for Simulink model 'SWC_BCC'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Fri Nov  6 11:38:53 2020
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_BCC_private_h_
#define RTW_HEADER_SWC_BCC_private_h_
#include "rtwtypes.h"
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

extern const float32 rtCP_pooled_L1EYruj6sQ1k[68];
extern const float32 rtCP_pooled_DqHckVIEEV7X[17];
extern const float32 rtCP_pooled_6GvjCyock7wm[4];
extern const float32 rtCP_pooled_q5ZyQfGjIXKJ[68];
extern const float32 rtCP_pooled_IAP8ccyn3DOT[17];
extern const float32 rtCP_pooled_lRa8o5hRGBX2[4096];
extern const float32 rtCP_pooled_7EBUHCewpktf[4096];
extern const uint32 rtCP_pooled_nyEQAg4QO5wu[2];

#define rtCP_uDLookupTable_tableData   rtCP_pooled_L1EYruj6sQ1k  /* Computed Parameter: rtCP_uDLookupTable_tableData
                                                                  * Referenced by: '<S59>/2-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp01Data    rtCP_pooled_DqHckVIEEV7X  /* Computed Parameter: rtCP_uDLookupTable_bp01Data
                                                                  * Referenced by: '<S59>/2-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp02Data    rtCP_pooled_6GvjCyock7wm  /* Computed Parameter: rtCP_uDLookupTable_bp02Data
                                                                  * Referenced by: '<S59>/2-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable1_tableData  rtCP_pooled_q5ZyQfGjIXKJ  /* Computed Parameter: rtCP_uDLookupTable1_tableData
                                                                  * Referenced by: '<S59>/2-D Lookup Table1'
                                                                  */
#define rtCP_uDLookupTable1_bp01Data   rtCP_pooled_IAP8ccyn3DOT  /* Computed Parameter: rtCP_uDLookupTable1_bp01Data
                                                                  * Referenced by: '<S59>/2-D Lookup Table1'
                                                                  */
#define rtCP_uDLookupTable1_bp02Data   rtCP_pooled_6GvjCyock7wm  /* Computed Parameter: rtCP_uDLookupTable1_bp02Data
                                                                  * Referenced by: '<S59>/2-D Lookup Table1'
                                                                  */
#define rtCP_uDLookupTable_tableData_l rtCP_pooled_L1EYruj6sQ1k  /* Computed Parameter: rtCP_uDLookupTable_tableData_l
                                                                  * Referenced by: '<S60>/2-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp01Data_l  rtCP_pooled_DqHckVIEEV7X  /* Computed Parameter: rtCP_uDLookupTable_bp01Data_l
                                                                  * Referenced by: '<S60>/2-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp02Data_k  rtCP_pooled_6GvjCyock7wm  /* Computed Parameter: rtCP_uDLookupTable_bp02Data_k
                                                                  * Referenced by: '<S60>/2-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable1_tableData_g rtCP_pooled_q5ZyQfGjIXKJ /* Computed Parameter: rtCP_uDLookupTable1_tableData_g
                                                                  * Referenced by: '<S60>/2-D Lookup Table1'
                                                                  */
#define rtCP_uDLookupTable1_bp01Data_b rtCP_pooled_IAP8ccyn3DOT  /* Computed Parameter: rtCP_uDLookupTable1_bp01Data_b
                                                                  * Referenced by: '<S60>/2-D Lookup Table1'
                                                                  */
#define rtCP_uDLookupTable1_bp02Data_l rtCP_pooled_6GvjCyock7wm  /* Computed Parameter: rtCP_uDLookupTable1_bp02Data_l
                                                                  * Referenced by: '<S60>/2-D Lookup Table1'
                                                                  */
#define rtCP_uDLookupTable_tableData_c rtCP_pooled_L1EYruj6sQ1k  /* Computed Parameter: rtCP_uDLookupTable_tableData_c
                                                                  * Referenced by: '<S61>/2-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp01Data_lw rtCP_pooled_DqHckVIEEV7X  /* Computed Parameter: rtCP_uDLookupTable_bp01Data_lw
                                                                  * Referenced by: '<S61>/2-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp02Data_d  rtCP_pooled_6GvjCyock7wm  /* Computed Parameter: rtCP_uDLookupTable_bp02Data_d
                                                                  * Referenced by: '<S61>/2-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable1_tableData_j rtCP_pooled_q5ZyQfGjIXKJ /* Computed Parameter: rtCP_uDLookupTable1_tableData_j
                                                                  * Referenced by: '<S61>/2-D Lookup Table1'
                                                                  */
#define rtCP_uDLookupTable1_bp01Data_e rtCP_pooled_IAP8ccyn3DOT  /* Computed Parameter: rtCP_uDLookupTable1_bp01Data_e
                                                                  * Referenced by: '<S61>/2-D Lookup Table1'
                                                                  */
#define rtCP_uDLookupTable1_bp02Data_f rtCP_pooled_6GvjCyock7wm  /* Computed Parameter: rtCP_uDLookupTable1_bp02Data_f
                                                                  * Referenced by: '<S61>/2-D Lookup Table1'
                                                                  */
#define rtCP_DirectLookupTablenD1_table rtCP_pooled_lRa8o5hRGBX2 /* Expression: CAL_BCC_Pro_agCosTab_f32
                                                                  * Referenced by: '<S165>/Direct Lookup Table (n-D)1'
                                                                  */
#define rtCP_DirectLookupTablenD_table rtCP_pooled_7EBUHCewpktf  /* Expression: CAL_BCC_Pro_agSinTab_f32
                                                                  * Referenced by: '<S165>/Direct Lookup Table (n-D)'
                                                                  */
#define rtCP_uDLookupTable_maxIndex    rtCP_pooled_nyEQAg4QO5wu  /* Computed Parameter: rtCP_uDLookupTable_maxIndex
                                                                  * Referenced by: '<S59>/2-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable1_maxIndex   rtCP_pooled_nyEQAg4QO5wu  /* Computed Parameter: rtCP_uDLookupTable1_maxIndex
                                                                  * Referenced by: '<S59>/2-D Lookup Table1'
                                                                  */
#define rtCP_uDLookupTable_maxIndex_g  rtCP_pooled_nyEQAg4QO5wu  /* Computed Parameter: rtCP_uDLookupTable_maxIndex_g
                                                                  * Referenced by: '<S60>/2-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable1_maxIndex_c rtCP_pooled_nyEQAg4QO5wu  /* Computed Parameter: rtCP_uDLookupTable1_maxIndex_c
                                                                  * Referenced by: '<S60>/2-D Lookup Table1'
                                                                  */
#define rtCP_uDLookupTable_maxIndex_p  rtCP_pooled_nyEQAg4QO5wu  /* Computed Parameter: rtCP_uDLookupTable_maxIndex_p
                                                                  * Referenced by: '<S61>/2-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable1_maxIndex_m rtCP_pooled_nyEQAg4QO5wu  /* Computed Parameter: rtCP_uDLookupTable1_maxIndex_m
                                                                  * Referenced by: '<S61>/2-D Lookup Table1'
                                                                  */
#endif                                 /* RTW_HEADER_SWC_BCC_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
