/*
 * File: SWC_HSPF_private.h
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

#ifndef RTW_HEADER_SWC_HSPF_private_h_
#define RTW_HEADER_SWC_HSPF_private_h_
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

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */
extern const float32 rtCP_pooled_blT28re8j7Gu[4096];
extern const float32 rtCP_pooled_ezPYTl0pGECu[4096];
extern const float32 rtCP_pooled_5PT1eyDNhv1z[4096];
extern const uint32 rtCP_pooled_NSDl96FvyFEt[2];
extern const uint32 rtCP_pooled_4hNgvNMnvIwM[2];
extern const uint32 rtCP_pooled_woXwApprzU92[2];

#define rtCP_CAL_DBCTemLow_Table_table rtCP_pooled_blT28re8j7Gu  /* Expression: DBCTemTable
                                                                  * Referenced by: '<S53>/CAL_DBCTemLow_Table'
                                                                  */
#define rtCP_CAL_DBCTemLow_Table_table_ rtCP_pooled_blT28re8j7Gu /* Expression: DBCTemTable
                                                                  * Referenced by: '<S55>/CAL_DBCTemLow_Table'
                                                                  */
#define rtCP_CAL_DBCTemLow_Table_tabl_m rtCP_pooled_blT28re8j7Gu /* Expression: DBCTemTable
                                                                  * Referenced by: '<S64>/CAL_DBCTemLow_Table'
                                                                  */
#define rtCP_tCoolantTem_Table_table   rtCP_pooled_ezPYTl0pGECu  /* Expression: WaterTemp_Table_C
                                                                  * Referenced by: '<S52>/tCoolantTem_Table'
                                                                  */
#define rtCP_PCBTem_Table_table        rtCP_pooled_5PT1eyDNhv1z  /* Expression: PCBTemp_Table_C
                                                                  * Referenced by: '<S48>/PCBTem_Table'
                                                                  */
#define rtCP_uDLookupTable1_maxIndex   rtCP_pooled_NSDl96FvyFEt  /* Computed Parameter: rtCP_uDLookupTable1_maxIndex
                                                                  * Referenced by: '<S43>/2-D Lookup Table1'
                                                                  */
#define rtCP_uDLookupTable4_maxIndex   rtCP_pooled_4hNgvNMnvIwM  /* Computed Parameter: rtCP_uDLookupTable4_maxIndex
                                                                  * Referenced by: '<S43>/2-D Lookup Table4'
                                                                  */
#define rtCP_uDLookupTable3_maxIndex   rtCP_pooled_NSDl96FvyFEt  /* Computed Parameter: rtCP_uDLookupTable3_maxIndex
                                                                  * Referenced by: '<S43>/2-D Lookup Table3'
                                                                  */
#define rtCP_uDLookupTable2_maxIndex   rtCP_pooled_woXwApprzU92  /* Computed Parameter: rtCP_uDLookupTable2_maxIndex
                                                                  * Referenced by: '<S43>/2-D Lookup Table2'
                                                                  */
#define rtCP_uDLookupTable_maxIndex    rtCP_pooled_NSDl96FvyFEt  /* Computed Parameter: rtCP_uDLookupTable_maxIndex
                                                                  * Referenced by: '<S43>/2-D Lookup Table'
                                                                  */
#endif                                 /* RTW_HEADER_SWC_HSPF_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
