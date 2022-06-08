/*
 * File: plook_u32f_binckan.c
 *
 * Code generated for Simulink model 'SWC_MCF'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Jun 30 11:04:24 2020
 */

#include "rtwtypes.h"
#include "binsearch_u32f.h"
#include "plook_u32f_binckan.h"

uint32 plook_u32f_binckan(float32 u, const float32 bp[], uint32 maxIndex)
{
  uint32 bpIndex;

  /* Prelookup - Index only
     Index Search method: 'binary'
     Interpolation method: 'Use nearest'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0U]) {
    bpIndex = 0U;
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32f(u, bp, maxIndex >> 1U, maxIndex);
    if ((bpIndex < maxIndex) && (bp[bpIndex + 1U] - u <= u - bp[bpIndex])) {
      bpIndex++;
    }
  } else {
    bpIndex = maxIndex;
  }

  return bpIndex;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
