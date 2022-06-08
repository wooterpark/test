/*
 * File: binsearch_u32f.c
 *
 * Code generated for Simulink model 'SWC_MCF'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Jun 30 11:04:24 2020
 */

#include "rtwtypes.h"
#include "binsearch_u32f.h"

uint32 binsearch_u32f(float32 u, const float32 bp[], uint32 startIndex,
  uint32 maxIndex)
{
  uint32 bpIndex;
  uint32 iRght;
  uint32 bpIdx;

  /* Binary Search */
  bpIdx = startIndex;
  bpIndex = 0U;
  iRght = maxIndex;
  while (iRght - bpIndex > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      bpIndex = bpIdx;
    }

    bpIdx = (iRght + bpIndex) >> 1U;
  }

  return bpIndex;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
