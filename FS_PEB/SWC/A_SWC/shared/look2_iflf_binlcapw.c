/*
 * File: look2_iflf_binlcapw.c
 *
 * Code generated for Simulink model 'SWC_TPC'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sun Jun 28 09:56:21 2020
 */

#include "rtwtypes.h"
#include "look2_iflf_binlcapw.h"

float32 look2_iflf_binlcapw(float32 u0, float32 u1, const float32 bp0[],
  const float32 bp1[], const float32 table[], const uint32 maxIndex[],
  uint32 stride)
{
  float32 y;
  float32 frac;
  uint32 bpIndices[2];
  float32 fractions[2];
  float32 yR_1d;
  uint32 iRght;
  uint32 bpIdx;
  uint32 iLeft;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
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

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0U];
    frac = 0.0F;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = 0.0F;
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

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U];
    frac = 0.0F;
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'portable wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  if (bpIndices[0U] == maxIndex[0U]) {
    y = table[bpIdx];
  } else {
    y = (table[bpIdx + 1U] - table[bpIdx]) * fractions[0U] + table[bpIdx];
  }

  if (iLeft == maxIndex[1U]) {
  } else {
    bpIdx += stride;
    if (bpIndices[0U] == maxIndex[0U]) {
      yR_1d = table[bpIdx];
    } else {
      yR_1d = (table[bpIdx + 1U] - table[bpIdx]) * fractions[0U] + table[bpIdx];
    }

    y += (yR_1d - y) * frac;
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
