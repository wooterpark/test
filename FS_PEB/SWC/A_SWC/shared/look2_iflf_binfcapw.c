/*
 * File: look2_iflf_binfcapw.c
 *
 * Code generated for Simulink model 'SWC_MCF'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Jun 30 11:04:24 2020
 */

#include "rtwtypes.h"
#include "look2_iflf_binfcapw.h"

float32 look2_iflf_binfcapw(float32 u0, float32 u1, const float32 bp0[],
  const float32 bp1[], const float32 table[], const uint32 maxIndex[],
  uint32 stride)
{
  uint32 bpIndices[2];
  uint32 iRght;
  uint32 bpIdx;
  uint32 iLeft;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Flat'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index only
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }
  } else {
    iLeft = maxIndex[0U];
  }

  bpIndices[0U] = iLeft;

  /* Prelookup - Index only
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }
  } else {
    iLeft = maxIndex[1U];
  }

  return table[iLeft * stride + bpIndices[0]];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
