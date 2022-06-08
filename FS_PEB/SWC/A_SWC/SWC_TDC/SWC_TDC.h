#ifndef RTW_HEADER_SWC_TDC_h_
#define RTW_HEADER_SWC_TDC_h_
#include <math.h>
#ifndef SWC_TDC_COMMON_INCLUDES_
# define SWC_TDC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_SWC_TDC.h"
#endif

#include "SWC_TDC_types.h"

#define CAL_TDC_go_nCtlExtReq_u8       1U

typedef struct tag_DW_SWC_TDC_T {
  float32 UnitDelay_DSTATE;
  float32 UnitDelay_DSTATE_c;
  float32 UnitDelay2_DSTATE;
} DW_SWC_TDC_T;

extern DW_SWC_TDC_T SWC_TDC_DW;
extern float32 VAR_TDC_trqRmp_f32;

#pragma section ".rodata.Calib_32"

extern const volatile float32 CAL_TDC_DeltaT_f32;
extern const volatile float32 CAL_TDC_KiNCtl_Y_Af32[10];
extern const volatile float32 CAL_TDC_KpNCtl_Y_Af32[10];
extern const volatile float32 CAL_TDC_n_Error_X_Af32[10];
extern const volatile float32 CAL_TDC_trqIncMax_f32;

#pragma section

#endif

