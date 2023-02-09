/*
 * dc_microgrid_6_1_sm_circuit.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "dc_microgrid_6_1_sm_circuit".
 *
 * Model version              : 13.74
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Fri Feb  3 15:17:54 2023
 *
 * Target selection: rtlab_rtmodel.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "dc_microgrid_6_1_sm_circuit.h"
#include "dc_microgrid_6_1_sm_circuit_private.h"

/* Block signals (default storage) */
B_dc_microgrid_6_1_sm_circuit_T dc_microgrid_6_1_sm_circuit_B;

/* Continuous states */
X_dc_microgrid_6_1_sm_circuit_T dc_microgrid_6_1_sm_circuit_X;

/* Block states (default storage) */
DW_dc_microgrid_6_1_sm_circuit_T dc_microgrid_6_1_sm_circuit_DW;

/* Real-time model */
static RT_MODEL_dc_microgrid_6_1_sm_circuit_T dc_microgrid_6_1_sm_circuit_M_;
RT_MODEL_dc_microgrid_6_1_sm_circuit_T *const dc_microgrid_6_1_sm_circuit_M =
  &dc_microgrid_6_1_sm_circuit_M_;

/*
 * Time delay interpolation routine
 *
 * The linear interpolation is performed using the formula:
 *
 * (t2 - tMinusDelay)         (tMinusDelay - t1)
 * u(t)  =  ----------------- * u1  +  ------------------- * u2
 * (t2 - t1)                  (t2 - t1)
 */
real_T rt_TDelayInterpolate(
  real_T tMinusDelay,                 /* tMinusDelay = currentSimTime - delay */
  real_T tStart,
  real_T *uBuf,
  int_T bufSz,
  int_T *lastIdx,
  int_T oldestIdx,
  int_T newIdx,
  real_T initOutput,
  boolean_T discrete,
  boolean_T minorStepAndTAtLastMajorOutput)
{
  int_T i;
  real_T yout, t1, t2, u1, u2;
  real_T* tBuf = uBuf + bufSz;

  /*
   * If there is only one data point in the buffer, this data point must be
   * the t= 0 and tMinusDelay > t0, it ask for something unknown. The best
   * guess if initial output as well
   */
  if ((newIdx == 0) && (oldestIdx ==0 ) && (tMinusDelay > tStart))
    return initOutput;

  /*
   * If tMinusDelay is less than zero, should output initial value
   */
  if (tMinusDelay <= tStart)
    return initOutput;

  /* For fixed buffer extrapolation:
   * if tMinusDelay is small than the time at oldestIdx, if discrete, output
   * tailptr value,  else use tailptr and tailptr+1 value to extrapolate
   * It is also for fixed buffer. Note: The same condition can happen for transport delay block where
   * use tStart and and t[tail] other than using t[tail] and t[tail+1].
   * See below
   */
  if ((tMinusDelay <= tBuf[oldestIdx] ) ) {
    if (discrete) {
      return(uBuf[oldestIdx]);
    } else {
      int_T tempIdx= oldestIdx + 1;
      if (oldestIdx == bufSz-1)
        tempIdx = 0;
      t1= tBuf[oldestIdx];
      t2= tBuf[tempIdx];
      u1= uBuf[oldestIdx];
      u2= uBuf[tempIdx];
      if (t2 == t1) {
        if (tMinusDelay >= t2) {
          yout = u2;
        } else {
          yout = u1;
        }
      } else {
        real_T f1 = (t2-tMinusDelay) / (t2-t1);
        real_T f2 = 1.0 - f1;

        /*
         * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
         */
        yout = f1*u1 + f2*u2;
      }

      return yout;
    }
  }

  /*
   * When block does not have direct feedthrough, we use the table of
   * values to extrapolate off the end of the table for delays that are less
   * than 0 (less then step size).  This is not completely accurate.  The
   * chain of events is as follows for a given time t.  Major output - look
   * in table.  Update - add entry to table.  Now, if we call the output at
   * time t again, there is a new entry in the table. For very small delays,
   * this means that we will have a different answer from the previous call
   * to the output fcn at the same time t.  The following code prevents this
   * from happening.
   */
  if (minorStepAndTAtLastMajorOutput) {
    /* pretend that the new entry has not been added to table */
    if (newIdx != 0) {
      if (*lastIdx == newIdx) {
        (*lastIdx)--;
      }

      newIdx--;
    } else {
      if (*lastIdx == newIdx) {
        *lastIdx = bufSz-1;
      }

      newIdx = bufSz - 1;
    }
  }

  i = *lastIdx;
  if (tBuf[i] < tMinusDelay) {
    /* Look forward starting at last index */
    while (tBuf[i] < tMinusDelay) {
      /* May occur if the delay is less than step-size - extrapolate */
      if (i == newIdx)
        break;
      i = ( i < (bufSz-1) ) ? (i+1) : 0;/* move through buffer */
    }
  } else {
    /*
     * Look backwards starting at last index which can happen when the
     * delay time increases.
     */
    while (tBuf[i] >= tMinusDelay) {
      /*
       * Due to the entry condition at top of function, we
       * should never hit the end.
       */
      i = (i > 0) ? i-1 : (bufSz-1);   /* move through buffer */
    }

    i = ( i < (bufSz-1) ) ? (i+1) : 0;
  }

  *lastIdx = i;
  if (discrete) {
    /*
     * tempEps = 128 * eps;
     * localEps = max(tempEps, tempEps*fabs(tBuf[i]))/2;
     */
    double tempEps = (DBL_EPSILON) * 128.0;
    double localEps = tempEps * fabs(tBuf[i]);
    if (tempEps > localEps) {
      localEps = tempEps;
    }

    localEps = localEps / 2.0;
    if (tMinusDelay >= (tBuf[i] - localEps)) {
      yout = uBuf[i];
    } else {
      if (i == 0) {
        yout = uBuf[bufSz-1];
      } else {
        yout = uBuf[i-1];
      }
    }
  } else {
    if (i == 0) {
      t1 = tBuf[bufSz-1];
      u1 = uBuf[bufSz-1];
    } else {
      t1 = tBuf[i-1];
      u1 = uBuf[i-1];
    }

    t2 = tBuf[i];
    u2 = uBuf[i];
    if (t2 == t1) {
      if (tMinusDelay >= t2) {
        yout = u2;
      } else {
        yout = u1;
      }
    } else {
      real_T f1 = (t2-tMinusDelay) / (t2-t1);
      real_T f2 = 1.0 - f1;

      /*
       * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
       */
      yout = f1*u1 + f2*u2;
    }
  }

  return(yout);
}

real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
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
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 15;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  dc_microgrid_6_1_sm_circuit_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  dc_microgrid_6_1_sm_circuit_output();
  dc_microgrid_6_1_sm_circuit_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  dc_microgrid_6_1_sm_circuit_output();
  dc_microgrid_6_1_sm_circuit_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T y;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a = a / y;
    y = y * sqrt(a * a + 1.0);
  } else if (a > y) {
    y = y / a;
    y = a * sqrt(y * y + 1.0);
  } else if (!rtIsNaN(y)) {
    y = a * 1.4142135623730951;
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T tmp;
  real_T tmp_0;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtGetNaN();
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u1 > 0.0) {
      tmp = 1.0;
    } else {
      tmp = -1.0;
    }

    if (u0 > 0.0) {
      tmp_0 = 1.0;
    } else {
      tmp_0 = -1.0;
    }

    y = atan2(tmp_0, tmp);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = rtGetNaN();
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y = y + u1;
    }
  }

  return y;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T u;
  real_T y;
  real_T y_0;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = rtGetNaN();
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    u = u1;
    if (u < 0.0) {
      y_0 = ceil(u);
    } else {
      y_0 = floor(u);
    }

    if ((u1 != 0.0) && (u1 != y_0)) {
      q = fabs(u0 / u1);
      if (!(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/* Model output function */
void dc_microgrid_6_1_sm_circuit_output(void)
{
  real_T Bias;
  real_T u;
  real_T u0;
  real_T u0_0;
  real_T u0_1;
  real_T u_0;
  real_T y;
  real_T y_0;
  real_T y_1;
  int32_T i;
  int32_T iU;
  int32_T i_0;
  if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
    /* set solver stop time */
    if (!(dc_microgrid_6_1_sm_circuit_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&dc_microgrid_6_1_sm_circuit_M->solverInfo,
                            ((dc_microgrid_6_1_sm_circuit_M->Timing.clockTickH0
        + 1) * dc_microgrid_6_1_sm_circuit_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&dc_microgrid_6_1_sm_circuit_M->solverInfo,
                            ((dc_microgrid_6_1_sm_circuit_M->Timing.clockTick0 +
        1) * dc_microgrid_6_1_sm_circuit_M->Timing.stepSize0 +
        dc_microgrid_6_1_sm_circuit_M->Timing.clockTickH0 *
        dc_microgrid_6_1_sm_circuit_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
    dc_microgrid_6_1_sm_circuit_M->Timing.t[0] = rtsiGetT
      (&dc_microgrid_6_1_sm_circuit_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
    /* Memory: '<S1>/S-Function' */
    dc_microgrid_6_1_sm_circuit_B.SFunction =
      dc_microgrid_6_1_sm_circuit_DW.SFunction_PreviousInput;

    /* Sum: '<S1>/Sum' incorporates:
     *  Constant: '<S1>/S-Function1'
     */
    dc_microgrid_6_1_sm_circuit_B.Sum =
      dc_microgrid_6_1_sm_circuit_P.SFunction1_Value +
      dc_microgrid_6_1_sm_circuit_B.SFunction;

    /* Stop: '<S1>/Stop Simulation' */
    if (dc_microgrid_6_1_sm_circuit_B.Sum != 0.0) {
      rtmSetStopRequested(dc_microgrid_6_1_sm_circuit_M, 1);
    }

    /* End of Stop: '<S1>/Stop Simulation' */
  }

  /* Sin: '<S3>/Sine Wave3' */
  dc_microgrid_6_1_sm_circuit_B.SineWave3 = sin
    (dc_microgrid_6_1_sm_circuit_P.SineWave3_Freq *
     dc_microgrid_6_1_sm_circuit_M->Timing.t[0] +
     dc_microgrid_6_1_sm_circuit_P.SineWave3_Phase) *
    dc_microgrid_6_1_sm_circuit_P.SineWave3_Amp +
    dc_microgrid_6_1_sm_circuit_P.SineWave3_Bias;
  if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
    /* S-Function (RECV_Param): '<S57>/S-Function' */

    /* Level2 S-Function Block: '<S57>/S-Function' (RECV_Param) */
    {
      SimStruct *rts = dc_microgrid_6_1_sm_circuit_M->childSfunctions[0];
      sfcnOutputs(rts,0);
    }

    /* Product: '<S3>/Product6' incorporates:
     *  Constant: '<S3>/Constant'
     */
    dc_microgrid_6_1_sm_circuit_B.Product6 =
      dc_microgrid_6_1_sm_circuit_B.SFunction_d[1] *
      dc_microgrid_6_1_sm_circuit_P.Constant_Value_h;
  }

  /* Product: '<S3>/Product5' */
  dc_microgrid_6_1_sm_circuit_B.Product5 =
    dc_microgrid_6_1_sm_circuit_B.SineWave3 *
    dc_microgrid_6_1_sm_circuit_B.Product6;

  /* Sin: '<S3>/Sine Wave4' */
  dc_microgrid_6_1_sm_circuit_B.SineWave4 = sin
    (dc_microgrid_6_1_sm_circuit_P.SineWave4_Freq *
     dc_microgrid_6_1_sm_circuit_M->Timing.t[0] +
     dc_microgrid_6_1_sm_circuit_P.SineWave4_Phase) *
    dc_microgrid_6_1_sm_circuit_P.SineWave4_Amp +
    dc_microgrid_6_1_sm_circuit_P.SineWave4_Bias;

  /* Product: '<S3>/Product7' */
  dc_microgrid_6_1_sm_circuit_B.Product7 =
    dc_microgrid_6_1_sm_circuit_B.SineWave4 *
    dc_microgrid_6_1_sm_circuit_B.Product6;

  /* Sin: '<S3>/Sine Wave5' */
  dc_microgrid_6_1_sm_circuit_B.SineWave5 = sin
    (dc_microgrid_6_1_sm_circuit_P.SineWave5_Freq *
     dc_microgrid_6_1_sm_circuit_M->Timing.t[0] +
     dc_microgrid_6_1_sm_circuit_P.SineWave5_Phase) *
    dc_microgrid_6_1_sm_circuit_P.SineWave5_Amp +
    dc_microgrid_6_1_sm_circuit_P.SineWave5_Bias;

  /* Product: '<S3>/Product8' */
  dc_microgrid_6_1_sm_circuit_B.Product8 =
    dc_microgrid_6_1_sm_circuit_B.SineWave5 *
    dc_microgrid_6_1_sm_circuit_B.Product6;
  if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
    /* Delay: '<S3>/Delay1' */
    dc_microgrid_6_1_sm_circuit_B.Delay1 =
      dc_microgrid_6_1_sm_circuit_DW.Delay1_DSTATE[0];

    /* Product: '<S3>/Divide1' */
    dc_microgrid_6_1_sm_circuit_B.Divide1 =
      dc_microgrid_6_1_sm_circuit_B.SFunction_d[0] /
      dc_microgrid_6_1_sm_circuit_B.Delay1;

    /* S-Function (sfun_spssw_discc): '<S4>/State-Space' incorporates:
     *  Constant: '<S31>/Constant'
     */

    /* S-Function block: <S4>/State-Space */
    {
      real_T accum;

      /* Circuit has switches */
      int_T *switch_status = (int_T*)
        dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.SWITCH_STATUS;
      int_T *switch_status_init = (int_T*)
        dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.SWITCH_STATUS_INIT;
      int_T *SwitchChange = (int_T*)
        dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.SW_CHG;
      int_T *gState = (int_T*)
        dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.G_STATE;
      real_T *yswitch = (real_T*)
        dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.Y_SWITCH;
      int_T *switchTypes = (int_T*)
        dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.SWITCH_TYPES;
      int_T *idxOutSw = (int_T*)
        dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.IDX_OUT_SW;
      real_T *DxCol = (real_T*)
        dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.DX_COL;
      real_T *tmp2 = (real_T*)
        dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.TMP2;
      real_T *BDcol = (real_T*)
        dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.BD_COL;
      real_T *tmp1 = (real_T*)
        dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.TMP1;
      real_T *uswlast = (real_T*)
        dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.USWLAST;
      int_T newState;
      int_T swChanged = 0;
      int loopsToDo = 20;
      real_T temp;

      /* keep an initial copy of switch_status*/
      memcpy(switch_status_init, switch_status, 6 * sizeof(int_T));
      memcpy(uswlast, &dc_microgrid_6_1_sm_circuit_B.StateSpace_o1[0], 6*sizeof
             (real_T));
      do {
        if (loopsToDo == 1) {          /* Need to reset some variables: */
          swChanged = 0;

          /* return to the original switch status*/
          {
            int_T i1;
            for (i1=0; i1 < 6; i1++) {
              swChanged = ((SwitchChange[i1] = switch_status_init[i1] -
                            switch_status[i1]) != 0) ? 1 : swChanged;
              switch_status[i1] = switch_status_init[i1];
            }
          }
        } else {
          /*
           * Compute outputs:
           * ---------------
           */
          real_T *Cs = (real_T*)
            dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.CS;
          real_T *Ds = (real_T*)
            dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.DS;

          {
            int_T i1;
            real_T *y0 = &dc_microgrid_6_1_sm_circuit_B.StateSpace_o1[0];
            for (i1=0; i1 < 20; i1++) {
              accum = 0.0;

              {
                int_T i2;
                real_T *xd = &dc_microgrid_6_1_sm_circuit_DW.StateSpace_DSTATE[0];
                for (i2=0; i2 < 6; i2++) {
                  accum += *(Cs++) * xd[i2];
                }
              }

              {
                int_T i2;
                const real_T *u0 =
                  &dc_microgrid_6_1_sm_circuit_P.Constant_Value_g[0];
                for (i2=0; i2 < 6; i2++) {
                  accum += *(Ds++) * u0[i2];
                }

                accum += *(Ds++) * dc_microgrid_6_1_sm_circuit_B.Product5;
                accum += *(Ds++) * dc_microgrid_6_1_sm_circuit_B.Product7;
                accum += *(Ds++) * dc_microgrid_6_1_sm_circuit_B.Product8;
                accum += *(Ds++) * dc_microgrid_6_1_sm_circuit_B.Divide1;
              }

              y0[i1] = accum;
            }
          }

          swChanged = 0;

          {
            int_T i1;
            real_T *y0 = &dc_microgrid_6_1_sm_circuit_B.StateSpace_o1[0];
            for (i1=0; i1 < 6; i1++) {
              newState = ((y0[i1] > 0.0) && (gState[i1] > 0)) || (y0[i1] < 0.0) ?
                1 : (((y0[i1] > 0.0) && gState[i1] == 0) ? 0 : switch_status[i1]);
              swChanged = ((SwitchChange[i1] = newState - switch_status[i1]) !=
                           0) ? 1 : swChanged;
              switch_status[i1] = newState;/* Keep new state */
            }
          }
        }

        /*
         * Compute new As, Bs, Cs and Ds matrixes:
         * --------------------------------------
         */
        if (swChanged) {
          real_T *As = (real_T*)
            dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.AS;
          real_T *Cs = (real_T*)
            dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.CS;
          real_T *Bs = (real_T*)
            dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.BS;
          real_T *Ds = (real_T*)
            dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.DS;
          real_T a1;

          {
            int_T i1;
            for (i1=0; i1 < 6; i1++) {
              if (SwitchChange[i1] != 0) {
                a1 = 1000.0*SwitchChange[i1];
                temp = 1/(1-Ds[i1*11]*a1);

                {
                  int_T i2;
                  for (i2=0; i2 < 20; i2++) {
                    DxCol[i2]= Ds[i2 * 10 + i1]*temp*a1;
                  }
                }

                DxCol[i1] = temp;

                {
                  int_T i2;
                  for (i2=0; i2 < 6; i2++) {
                    BDcol[i2]= Bs[i2 * 10 + i1]*a1;
                  }
                }

                /* Copy row nSw of Cs into tmp1 and zero it out in Cs */
                memcpy(tmp1, &Cs[i1 * 6], 6 * sizeof(real_T));
                memset(&Cs[i1 * 6], '\0', 6 * sizeof(real_T));

                /* Copy row nSw of Ds into tmp2 and zero it out in Ds */
                memcpy(tmp2, &Ds[i1 * 10], 10 * sizeof(real_T));
                memset(&Ds[i1 * 10], '\0', 10 * sizeof(real_T));

                /* Cs = Cs + DxCol * tmp1, Ds = Ds + DxCol * tmp2 *******************/
                {
                  int_T i2;
                  for (i2=0; i2 < 20; i2++) {
                    a1 = DxCol[i2];

                    {
                      int_T i3;
                      for (i3=0; i3 < 6; i3++) {
                        Cs[i2 * 6 + i3] += a1 * tmp1[i3];
                      }
                    }

                    {
                      int_T i3;
                      for (i3=0; i3 < 10; i3++) {
                        Ds[i2 * 10 + i3] += a1 * tmp2[i3];
                      }
                    }
                  }
                }

                /* As = As + BdCol*Cs(nSw,:), Bs = Bs + BdCol*Ds(nSw,:) *************/
                {
                  int_T i2;
                  for (i2=0; i2 < 6; i2++) {
                    a1 = BDcol[i2];

                    {
                      int_T i3;
                      for (i3=0; i3 < 6; i3++) {
                        As[i2 * 6 + i3] += a1 * Cs[i1 * 6 + i3];
                      }
                    }

                    {
                      int_T i3;
                      for (i3=0; i3 < 10; i3++) {
                        Bs[i2 * 10 + i3] += a1 * Ds[i1 * 10 + i3];
                      }
                    }
                  }
                }
              }
            }
          }
        }                              /* if (swChanged) */
      } while (swChanged > 0 && --loopsToDo > 0);

      if (loopsToDo == 0) {
        real_T *Cs = (real_T*)dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.CS;
        real_T *Ds = (real_T*)dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.DS;

        {
          int_T i1;
          real_T *y0 = &dc_microgrid_6_1_sm_circuit_B.StateSpace_o1[0];
          for (i1=0; i1 < 20; i1++) {
            accum = 0.0;

            {
              int_T i2;
              real_T *xd = &dc_microgrid_6_1_sm_circuit_DW.StateSpace_DSTATE[0];
              for (i2=0; i2 < 6; i2++) {
                accum += *(Cs++) * xd[i2];
              }
            }

            {
              int_T i2;
              const real_T *u0 =
                &dc_microgrid_6_1_sm_circuit_P.Constant_Value_g[0];
              for (i2=0; i2 < 6; i2++) {
                accum += *(Ds++) * u0[i2];
              }

              accum += *(Ds++) * dc_microgrid_6_1_sm_circuit_B.Product5;
              accum += *(Ds++) * dc_microgrid_6_1_sm_circuit_B.Product7;
              accum += *(Ds++) * dc_microgrid_6_1_sm_circuit_B.Product8;
              accum += *(Ds++) * dc_microgrid_6_1_sm_circuit_B.Divide1;
            }

            y0[i1] = accum;
          }
        }
      }

      /* Output new switches states */
      {
        int_T i1;
        real_T *y1 = &dc_microgrid_6_1_sm_circuit_B.StateSpace_o2[0];
        for (i1=0; i1 < 6; i1++) {
          y1[i1] = (real_T)switch_status[i1];
        }
      }
    }
  }

  /* Integrator: '<S66>/integrator' */
  dc_microgrid_6_1_sm_circuit_B.integrator[0] =
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE[0];
  dc_microgrid_6_1_sm_circuit_B.integrator[1] =
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE[1];
  dc_microgrid_6_1_sm_circuit_B.integrator[2] =
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE[2];

  /* TransportDelay: '<S66>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_PWORK.TUbufferPtrs[0];
    real_T simTime = dc_microgrid_6_1_sm_circuit_M->Timing.t[0];
    real_T tMinusDelay ;

    {
      int_T i1;
      real_T *y0 = &dc_microgrid_6_1_sm_circuit_B.TransportDelay[0];
      int_T *iw_Tail =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Tail[0];
      int_T *iw_Head =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Head[0];
      int_T *iw_Last =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Last[0];
      int_T *iw_CircularBufSize =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.CircularBufSize[0];
      for (i1=0; i1 < 3; i1++) {
        tMinusDelay = (((dc_microgrid_6_1_sm_circuit_P.TransportDelay_Delay_l) >
                        0.0) ?
                       (dc_microgrid_6_1_sm_circuit_P.TransportDelay_Delay_l) :
                       0.0);
        tMinusDelay = simTime - tMinusDelay;
        y0[i1] = rt_TDelayInterpolate(
          tMinusDelay,
          0.0,
          *uBuffer,
          iw_CircularBufSize[i1],
          &iw_Last[i1],
          iw_Tail[i1],
          iw_Head[i1],
          dc_microgrid_6_1_sm_circuit_P.TransportDelay_InitOutput_e,
          0,
          0);
        uBuffer++;
      }
    }
  }

  /* Clock: '<S66>/Clock' */
  dc_microgrid_6_1_sm_circuit_B.Clock = dc_microgrid_6_1_sm_circuit_M->Timing.t
    [0];

  /* RelationalOperator: '<S66>/Relational Operator' incorporates:
   *  Constant: '<S66>/K1'
   */
  dc_microgrid_6_1_sm_circuit_B.RelationalOperator =
    (dc_microgrid_6_1_sm_circuit_B.Clock >=
     dc_microgrid_6_1_sm_circuit_P.K1_Value_f);
  if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
    /* Memory: '<S66>/Memory' */
    dc_microgrid_6_1_sm_circuit_B.Memory[0] =
      dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput[0];
    dc_microgrid_6_1_sm_circuit_B.Memory[1] =
      dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput[1];
    dc_microgrid_6_1_sm_circuit_B.Memory[2] =
      dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput[2];
  }

  /* Switch: '<S66>/Switch' */
  if (dc_microgrid_6_1_sm_circuit_B.RelationalOperator) {
    /* Sum: '<S66>/Sum' */
    dc_microgrid_6_1_sm_circuit_B.Sum_db[0] =
      dc_microgrid_6_1_sm_circuit_B.integrator[0] -
      dc_microgrid_6_1_sm_circuit_B.TransportDelay[0];
    dc_microgrid_6_1_sm_circuit_B.Sum_db[1] =
      dc_microgrid_6_1_sm_circuit_B.integrator[1] -
      dc_microgrid_6_1_sm_circuit_B.TransportDelay[1];
    dc_microgrid_6_1_sm_circuit_B.Sum_db[2] =
      dc_microgrid_6_1_sm_circuit_B.integrator[2] -
      dc_microgrid_6_1_sm_circuit_B.TransportDelay[2];

    /* Gain: '<S66>/Gain' */
    dc_microgrid_6_1_sm_circuit_B.Gain_g[0] =
      dc_microgrid_6_1_sm_circuit_P.Gain_Gain_g *
      dc_microgrid_6_1_sm_circuit_B.Sum_db[0];
    dc_microgrid_6_1_sm_circuit_B.Gain_g[1] =
      dc_microgrid_6_1_sm_circuit_P.Gain_Gain_g *
      dc_microgrid_6_1_sm_circuit_B.Sum_db[1];
    dc_microgrid_6_1_sm_circuit_B.Gain_g[2] =
      dc_microgrid_6_1_sm_circuit_P.Gain_Gain_g *
      dc_microgrid_6_1_sm_circuit_B.Sum_db[2];

    /* Switch: '<S66>/Switch' */
    dc_microgrid_6_1_sm_circuit_B.Switch[0] =
      dc_microgrid_6_1_sm_circuit_B.Gain_g[0];
    dc_microgrid_6_1_sm_circuit_B.Switch[1] =
      dc_microgrid_6_1_sm_circuit_B.Gain_g[1];
    dc_microgrid_6_1_sm_circuit_B.Switch[2] =
      dc_microgrid_6_1_sm_circuit_B.Gain_g[2];
  } else {
    /* Switch: '<S66>/Switch' */
    dc_microgrid_6_1_sm_circuit_B.Switch[0] =
      dc_microgrid_6_1_sm_circuit_B.Memory[0];
    dc_microgrid_6_1_sm_circuit_B.Switch[1] =
      dc_microgrid_6_1_sm_circuit_B.Memory[1];
    dc_microgrid_6_1_sm_circuit_B.Switch[2] =
      dc_microgrid_6_1_sm_circuit_B.Memory[2];
  }

  /* End of Switch: '<S66>/Switch' */

  /* Integrator: '<S65>/integrator' */
  dc_microgrid_6_1_sm_circuit_B.integrator_p[0] =
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE_m[0];
  dc_microgrid_6_1_sm_circuit_B.integrator_p[1] =
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE_m[1];
  dc_microgrid_6_1_sm_circuit_B.integrator_p[2] =
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE_m[2];

  /* TransportDelay: '<S65>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_PWORK_n.TUbufferPtrs[0];
    real_T simTime = dc_microgrid_6_1_sm_circuit_M->Timing.t[0];
    real_T tMinusDelay ;

    {
      int_T i1;
      real_T *y0 = &dc_microgrid_6_1_sm_circuit_B.TransportDelay_n[0];
      int_T *iw_Tail =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Tail[0];
      int_T *iw_Head =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Head[0];
      int_T *iw_Last =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Last[0];
      int_T *iw_CircularBufSize =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.CircularBufSize[0];
      for (i1=0; i1 < 3; i1++) {
        tMinusDelay = (((dc_microgrid_6_1_sm_circuit_P.TransportDelay_Delay_fa) >
                        0.0) ?
                       (dc_microgrid_6_1_sm_circuit_P.TransportDelay_Delay_fa) :
                       0.0);
        tMinusDelay = simTime - tMinusDelay;
        y0[i1] = rt_TDelayInterpolate(
          tMinusDelay,
          0.0,
          *uBuffer,
          iw_CircularBufSize[i1],
          &iw_Last[i1],
          iw_Tail[i1],
          iw_Head[i1],
          dc_microgrid_6_1_sm_circuit_P.TransportDelay_InitOutput_f,
          0,
          0);
        uBuffer++;
      }
    }
  }

  /* Clock: '<S65>/Clock' */
  dc_microgrid_6_1_sm_circuit_B.Clock_p =
    dc_microgrid_6_1_sm_circuit_M->Timing.t[0];

  /* RelationalOperator: '<S65>/Relational Operator' incorporates:
   *  Constant: '<S65>/K1'
   */
  dc_microgrid_6_1_sm_circuit_B.RelationalOperator_e =
    (dc_microgrid_6_1_sm_circuit_B.Clock_p >=
     dc_microgrid_6_1_sm_circuit_P.K1_Value_h);
  if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
    /* Memory: '<S65>/Memory' */
    dc_microgrid_6_1_sm_circuit_B.Memory_j[0] =
      dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_d[0];
    dc_microgrid_6_1_sm_circuit_B.Memory_j[1] =
      dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_d[1];
    dc_microgrid_6_1_sm_circuit_B.Memory_j[2] =
      dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_d[2];
  }

  /* Switch: '<S65>/Switch' */
  if (dc_microgrid_6_1_sm_circuit_B.RelationalOperator_e) {
    /* Sum: '<S65>/Sum' */
    dc_microgrid_6_1_sm_circuit_B.Sum_n[0] =
      dc_microgrid_6_1_sm_circuit_B.integrator_p[0] -
      dc_microgrid_6_1_sm_circuit_B.TransportDelay_n[0];
    dc_microgrid_6_1_sm_circuit_B.Sum_n[1] =
      dc_microgrid_6_1_sm_circuit_B.integrator_p[1] -
      dc_microgrid_6_1_sm_circuit_B.TransportDelay_n[1];
    dc_microgrid_6_1_sm_circuit_B.Sum_n[2] =
      dc_microgrid_6_1_sm_circuit_B.integrator_p[2] -
      dc_microgrid_6_1_sm_circuit_B.TransportDelay_n[2];

    /* Gain: '<S65>/Gain' */
    dc_microgrid_6_1_sm_circuit_B.Gain_eh[0] =
      dc_microgrid_6_1_sm_circuit_P.Gain_Gain_o *
      dc_microgrid_6_1_sm_circuit_B.Sum_n[0];
    dc_microgrid_6_1_sm_circuit_B.Gain_eh[1] =
      dc_microgrid_6_1_sm_circuit_P.Gain_Gain_o *
      dc_microgrid_6_1_sm_circuit_B.Sum_n[1];
    dc_microgrid_6_1_sm_circuit_B.Gain_eh[2] =
      dc_microgrid_6_1_sm_circuit_P.Gain_Gain_o *
      dc_microgrid_6_1_sm_circuit_B.Sum_n[2];

    /* Switch: '<S65>/Switch' */
    dc_microgrid_6_1_sm_circuit_B.Switch_h[0] =
      dc_microgrid_6_1_sm_circuit_B.Gain_eh[0];
    dc_microgrid_6_1_sm_circuit_B.Switch_h[1] =
      dc_microgrid_6_1_sm_circuit_B.Gain_eh[1];
    dc_microgrid_6_1_sm_circuit_B.Switch_h[2] =
      dc_microgrid_6_1_sm_circuit_B.Gain_eh[2];
  } else {
    /* Switch: '<S65>/Switch' */
    dc_microgrid_6_1_sm_circuit_B.Switch_h[0] =
      dc_microgrid_6_1_sm_circuit_B.Memory_j[0];
    dc_microgrid_6_1_sm_circuit_B.Switch_h[1] =
      dc_microgrid_6_1_sm_circuit_B.Memory_j[1];
    dc_microgrid_6_1_sm_circuit_B.Switch_h[2] =
      dc_microgrid_6_1_sm_circuit_B.Memory_j[2];
  }

  /* End of Switch: '<S65>/Switch' */

  /* RealImagToComplex: '<S61>/Real-Imag to Complex' */
  dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex[0].re =
    dc_microgrid_6_1_sm_circuit_B.Switch[0];
  dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex[0].im =
    dc_microgrid_6_1_sm_circuit_B.Switch_h[0];
  dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex[1].re =
    dc_microgrid_6_1_sm_circuit_B.Switch[1];
  dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex[1].im =
    dc_microgrid_6_1_sm_circuit_B.Switch_h[1];
  dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex[2].re =
    dc_microgrid_6_1_sm_circuit_B.Switch[2];
  dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex[2].im =
    dc_microgrid_6_1_sm_circuit_B.Switch_h[2];

  /* ComplexToMagnitudeAngle: '<S61>/Complex to Magnitude-Angle' incorporates:
   *  RealImagToComplex: '<S61>/Real-Imag to Complex'
   */
  dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o1[0] = rt_hypotd_snf
    (dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex[0].re,
     dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex[0].im);
  dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o1[1] = rt_hypotd_snf
    (dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex[1].re,
     dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex[1].im);
  dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o1[2] = rt_hypotd_snf
    (dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex[2].re,
     dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex[2].im);

  /* ComplexToMagnitudeAngle: '<S61>/Complex to Magnitude-Angle' incorporates:
   *  RealImagToComplex: '<S61>/Real-Imag to Complex'
   */
  dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o2[0] = rt_atan2d_snf
    (dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex[0].im,
     dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex[0].re);
  dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o2[1] = rt_atan2d_snf
    (dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex[1].im,
     dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex[1].re);
  dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o2[2] = rt_atan2d_snf
    (dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex[2].im,
     dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex[2].re);

  /* Integrator: '<S70>/integrator' */
  dc_microgrid_6_1_sm_circuit_B.integrator_f[0] =
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE_p[0];
  dc_microgrid_6_1_sm_circuit_B.integrator_f[1] =
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE_p[1];
  dc_microgrid_6_1_sm_circuit_B.integrator_f[2] =
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE_p[2];

  /* TransportDelay: '<S70>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_PWORK_d.TUbufferPtrs[0];
    real_T simTime = dc_microgrid_6_1_sm_circuit_M->Timing.t[0];
    real_T tMinusDelay ;

    {
      int_T i1;
      real_T *y0 = &dc_microgrid_6_1_sm_circuit_B.TransportDelay_a[0];
      int_T *iw_Tail =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Tail[0];
      int_T *iw_Head =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Head[0];
      int_T *iw_Last =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Last[0];
      int_T *iw_CircularBufSize =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.CircularBufSize[0];
      for (i1=0; i1 < 3; i1++) {
        tMinusDelay = (((dc_microgrid_6_1_sm_circuit_P.TransportDelay_Delay_d) >
                        0.0) ?
                       (dc_microgrid_6_1_sm_circuit_P.TransportDelay_Delay_d) :
                       0.0);
        tMinusDelay = simTime - tMinusDelay;
        y0[i1] = rt_TDelayInterpolate(
          tMinusDelay,
          0.0,
          *uBuffer,
          iw_CircularBufSize[i1],
          &iw_Last[i1],
          iw_Tail[i1],
          iw_Head[i1],
          dc_microgrid_6_1_sm_circuit_P.TransportDelay_InitOutput_d,
          0,
          0);
        uBuffer++;
      }
    }
  }

  /* Clock: '<S70>/Clock' */
  dc_microgrid_6_1_sm_circuit_B.Clock_g =
    dc_microgrid_6_1_sm_circuit_M->Timing.t[0];

  /* RelationalOperator: '<S70>/Relational Operator' incorporates:
   *  Constant: '<S70>/K1'
   */
  dc_microgrid_6_1_sm_circuit_B.RelationalOperator_c =
    (dc_microgrid_6_1_sm_circuit_B.Clock_g >=
     dc_microgrid_6_1_sm_circuit_P.K1_Value_pv);
  if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
    /* Memory: '<S70>/Memory' */
    dc_microgrid_6_1_sm_circuit_B.Memory_g[0] =
      dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_g[0];
    dc_microgrid_6_1_sm_circuit_B.Memory_g[1] =
      dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_g[1];
    dc_microgrid_6_1_sm_circuit_B.Memory_g[2] =
      dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_g[2];
  }

  /* Switch: '<S70>/Switch' */
  if (dc_microgrid_6_1_sm_circuit_B.RelationalOperator_c) {
    /* Sum: '<S70>/Sum' */
    dc_microgrid_6_1_sm_circuit_B.Sum_bj[0] =
      dc_microgrid_6_1_sm_circuit_B.integrator_f[0] -
      dc_microgrid_6_1_sm_circuit_B.TransportDelay_a[0];
    dc_microgrid_6_1_sm_circuit_B.Sum_bj[1] =
      dc_microgrid_6_1_sm_circuit_B.integrator_f[1] -
      dc_microgrid_6_1_sm_circuit_B.TransportDelay_a[1];
    dc_microgrid_6_1_sm_circuit_B.Sum_bj[2] =
      dc_microgrid_6_1_sm_circuit_B.integrator_f[2] -
      dc_microgrid_6_1_sm_circuit_B.TransportDelay_a[2];

    /* Gain: '<S70>/Gain' */
    dc_microgrid_6_1_sm_circuit_B.Gain_l[0] =
      dc_microgrid_6_1_sm_circuit_P.Gain_Gain_cc *
      dc_microgrid_6_1_sm_circuit_B.Sum_bj[0];
    dc_microgrid_6_1_sm_circuit_B.Gain_l[1] =
      dc_microgrid_6_1_sm_circuit_P.Gain_Gain_cc *
      dc_microgrid_6_1_sm_circuit_B.Sum_bj[1];
    dc_microgrid_6_1_sm_circuit_B.Gain_l[2] =
      dc_microgrid_6_1_sm_circuit_P.Gain_Gain_cc *
      dc_microgrid_6_1_sm_circuit_B.Sum_bj[2];

    /* Switch: '<S70>/Switch' */
    dc_microgrid_6_1_sm_circuit_B.Switch_k[0] =
      dc_microgrid_6_1_sm_circuit_B.Gain_l[0];
    dc_microgrid_6_1_sm_circuit_B.Switch_k[1] =
      dc_microgrid_6_1_sm_circuit_B.Gain_l[1];
    dc_microgrid_6_1_sm_circuit_B.Switch_k[2] =
      dc_microgrid_6_1_sm_circuit_B.Gain_l[2];
  } else {
    /* Switch: '<S70>/Switch' */
    dc_microgrid_6_1_sm_circuit_B.Switch_k[0] =
      dc_microgrid_6_1_sm_circuit_B.Memory_g[0];
    dc_microgrid_6_1_sm_circuit_B.Switch_k[1] =
      dc_microgrid_6_1_sm_circuit_B.Memory_g[1];
    dc_microgrid_6_1_sm_circuit_B.Switch_k[2] =
      dc_microgrid_6_1_sm_circuit_B.Memory_g[2];
  }

  /* End of Switch: '<S70>/Switch' */

  /* Integrator: '<S69>/integrator' */
  dc_microgrid_6_1_sm_circuit_B.integrator_b[0] =
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE_me[0];
  dc_microgrid_6_1_sm_circuit_B.integrator_b[1] =
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE_me[1];
  dc_microgrid_6_1_sm_circuit_B.integrator_b[2] =
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE_me[2];

  /* TransportDelay: '<S69>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_PWORK_j.TUbufferPtrs[0];
    real_T simTime = dc_microgrid_6_1_sm_circuit_M->Timing.t[0];
    real_T tMinusDelay ;

    {
      int_T i1;
      real_T *y0 = &dc_microgrid_6_1_sm_circuit_B.TransportDelay_b[0];
      int_T *iw_Tail =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Tail[0];
      int_T *iw_Head =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Head[0];
      int_T *iw_Last =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Last[0];
      int_T *iw_CircularBufSize =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.CircularBufSize[0];
      for (i1=0; i1 < 3; i1++) {
        tMinusDelay = (((dc_microgrid_6_1_sm_circuit_P.TransportDelay_Delay_n) >
                        0.0) ?
                       (dc_microgrid_6_1_sm_circuit_P.TransportDelay_Delay_n) :
                       0.0);
        tMinusDelay = simTime - tMinusDelay;
        y0[i1] = rt_TDelayInterpolate(
          tMinusDelay,
          0.0,
          *uBuffer,
          iw_CircularBufSize[i1],
          &iw_Last[i1],
          iw_Tail[i1],
          iw_Head[i1],
          dc_microgrid_6_1_sm_circuit_P.TransportDelay_InitOutput_fm,
          0,
          0);
        uBuffer++;
      }
    }
  }

  /* Clock: '<S69>/Clock' */
  dc_microgrid_6_1_sm_circuit_B.Clock_k =
    dc_microgrid_6_1_sm_circuit_M->Timing.t[0];

  /* RelationalOperator: '<S69>/Relational Operator' incorporates:
   *  Constant: '<S69>/K1'
   */
  dc_microgrid_6_1_sm_circuit_B.RelationalOperator_b =
    (dc_microgrid_6_1_sm_circuit_B.Clock_k >=
     dc_microgrid_6_1_sm_circuit_P.K1_Value_f3);
  if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
    /* Memory: '<S69>/Memory' */
    dc_microgrid_6_1_sm_circuit_B.Memory_p[0] =
      dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_l[0];
    dc_microgrid_6_1_sm_circuit_B.Memory_p[1] =
      dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_l[1];
    dc_microgrid_6_1_sm_circuit_B.Memory_p[2] =
      dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_l[2];
  }

  /* Switch: '<S69>/Switch' */
  if (dc_microgrid_6_1_sm_circuit_B.RelationalOperator_b) {
    /* Sum: '<S69>/Sum' */
    dc_microgrid_6_1_sm_circuit_B.Sum_dn[0] =
      dc_microgrid_6_1_sm_circuit_B.integrator_b[0] -
      dc_microgrid_6_1_sm_circuit_B.TransportDelay_b[0];
    dc_microgrid_6_1_sm_circuit_B.Sum_dn[1] =
      dc_microgrid_6_1_sm_circuit_B.integrator_b[1] -
      dc_microgrid_6_1_sm_circuit_B.TransportDelay_b[1];
    dc_microgrid_6_1_sm_circuit_B.Sum_dn[2] =
      dc_microgrid_6_1_sm_circuit_B.integrator_b[2] -
      dc_microgrid_6_1_sm_circuit_B.TransportDelay_b[2];

    /* Gain: '<S69>/Gain' */
    dc_microgrid_6_1_sm_circuit_B.Gain_ej[0] =
      dc_microgrid_6_1_sm_circuit_P.Gain_Gain_c *
      dc_microgrid_6_1_sm_circuit_B.Sum_dn[0];
    dc_microgrid_6_1_sm_circuit_B.Gain_ej[1] =
      dc_microgrid_6_1_sm_circuit_P.Gain_Gain_c *
      dc_microgrid_6_1_sm_circuit_B.Sum_dn[1];
    dc_microgrid_6_1_sm_circuit_B.Gain_ej[2] =
      dc_microgrid_6_1_sm_circuit_P.Gain_Gain_c *
      dc_microgrid_6_1_sm_circuit_B.Sum_dn[2];

    /* Switch: '<S69>/Switch' */
    dc_microgrid_6_1_sm_circuit_B.Switch_d[0] =
      dc_microgrid_6_1_sm_circuit_B.Gain_ej[0];
    dc_microgrid_6_1_sm_circuit_B.Switch_d[1] =
      dc_microgrid_6_1_sm_circuit_B.Gain_ej[1];
    dc_microgrid_6_1_sm_circuit_B.Switch_d[2] =
      dc_microgrid_6_1_sm_circuit_B.Gain_ej[2];
  } else {
    /* Switch: '<S69>/Switch' */
    dc_microgrid_6_1_sm_circuit_B.Switch_d[0] =
      dc_microgrid_6_1_sm_circuit_B.Memory_p[0];
    dc_microgrid_6_1_sm_circuit_B.Switch_d[1] =
      dc_microgrid_6_1_sm_circuit_B.Memory_p[1];
    dc_microgrid_6_1_sm_circuit_B.Switch_d[2] =
      dc_microgrid_6_1_sm_circuit_B.Memory_p[2];
  }

  /* End of Switch: '<S69>/Switch' */

  /* RealImagToComplex: '<S62>/Real-Imag to Complex' */
  dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_e[0].re =
    dc_microgrid_6_1_sm_circuit_B.Switch_k[0];
  dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_e[0].im =
    dc_microgrid_6_1_sm_circuit_B.Switch_d[0];
  dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_e[1].re =
    dc_microgrid_6_1_sm_circuit_B.Switch_k[1];
  dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_e[1].im =
    dc_microgrid_6_1_sm_circuit_B.Switch_d[1];
  dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_e[2].re =
    dc_microgrid_6_1_sm_circuit_B.Switch_k[2];
  dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_e[2].im =
    dc_microgrid_6_1_sm_circuit_B.Switch_d[2];

  /* ComplexToMagnitudeAngle: '<S62>/Complex to Magnitude-Angle' incorporates:
   *  RealImagToComplex: '<S62>/Real-Imag to Complex'
   */
  dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o1_d[0] = rt_hypotd_snf
    (dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_e[0].re,
     dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_e[0].im);
  dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o1_d[1] = rt_hypotd_snf
    (dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_e[1].re,
     dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_e[1].im);
  dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o1_d[2] = rt_hypotd_snf
    (dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_e[2].re,
     dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_e[2].im);

  /* ComplexToMagnitudeAngle: '<S62>/Complex to Magnitude-Angle' incorporates:
   *  RealImagToComplex: '<S62>/Real-Imag to Complex'
   */
  dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o2_f[0] = rt_atan2d_snf
    (dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_e[0].im,
     dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_e[0].re);
  dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o2_f[1] = rt_atan2d_snf
    (dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_e[1].im,
     dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_e[1].re);
  dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o2_f[2] = rt_atan2d_snf
    (dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_e[2].im,
     dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_e[2].re);

  /* Product: '<S17>/Product' */
  dc_microgrid_6_1_sm_circuit_B.VfundIfund[0] =
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o1[0] *
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o1_d[0];
  dc_microgrid_6_1_sm_circuit_B.VfundIfund[1] =
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o1[1] *
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o1_d[1];
  dc_microgrid_6_1_sm_circuit_B.VfundIfund[2] =
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o1[2] *
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o1_d[2];

  /* Gain: '<S17>/Gain1' */
  dc_microgrid_6_1_sm_circuit_B.Gain1[0] =
    dc_microgrid_6_1_sm_circuit_P.Gain1_Gain_nh *
    dc_microgrid_6_1_sm_circuit_B.VfundIfund[0];
  dc_microgrid_6_1_sm_circuit_B.Gain1[1] =
    dc_microgrid_6_1_sm_circuit_P.Gain1_Gain_nh *
    dc_microgrid_6_1_sm_circuit_B.VfundIfund[1];
  dc_microgrid_6_1_sm_circuit_B.Gain1[2] =
    dc_microgrid_6_1_sm_circuit_P.Gain1_Gain_nh *
    dc_microgrid_6_1_sm_circuit_B.VfundIfund[2];

  /* Gain: '<S61>/Rad->Deg.' */
  dc_microgrid_6_1_sm_circuit_B.RadDeg[0] =
    dc_microgrid_6_1_sm_circuit_P.RadDeg_Gain_i *
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o2[0];
  dc_microgrid_6_1_sm_circuit_B.RadDeg[1] =
    dc_microgrid_6_1_sm_circuit_P.RadDeg_Gain_i *
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o2[1];
  dc_microgrid_6_1_sm_circuit_B.RadDeg[2] =
    dc_microgrid_6_1_sm_circuit_P.RadDeg_Gain_i *
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o2[2];

  /* Gain: '<S62>/Rad->Deg.' */
  dc_microgrid_6_1_sm_circuit_B.RadDeg_n[0] =
    dc_microgrid_6_1_sm_circuit_P.RadDeg_Gain_f *
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o2_f[0];
  dc_microgrid_6_1_sm_circuit_B.RadDeg_n[1] =
    dc_microgrid_6_1_sm_circuit_P.RadDeg_Gain_f *
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o2_f[1];
  dc_microgrid_6_1_sm_circuit_B.RadDeg_n[2] =
    dc_microgrid_6_1_sm_circuit_P.RadDeg_Gain_f *
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o2_f[2];

  /* Sum: '<S17>/Sum' */
  dc_microgrid_6_1_sm_circuit_B.Sum_d[0] = dc_microgrid_6_1_sm_circuit_B.RadDeg
    [0] - dc_microgrid_6_1_sm_circuit_B.RadDeg_n[0];
  dc_microgrid_6_1_sm_circuit_B.Sum_d[1] = dc_microgrid_6_1_sm_circuit_B.RadDeg
    [1] - dc_microgrid_6_1_sm_circuit_B.RadDeg_n[1];
  dc_microgrid_6_1_sm_circuit_B.Sum_d[2] = dc_microgrid_6_1_sm_circuit_B.RadDeg
    [2] - dc_microgrid_6_1_sm_circuit_B.RadDeg_n[2];

  /* Gain: '<S17>/Deg->Rad' */
  dc_microgrid_6_1_sm_circuit_B.phi[0] =
    dc_microgrid_6_1_sm_circuit_P.DegRad_Gain_g *
    dc_microgrid_6_1_sm_circuit_B.Sum_d[0];
  dc_microgrid_6_1_sm_circuit_B.phi[1] =
    dc_microgrid_6_1_sm_circuit_P.DegRad_Gain_g *
    dc_microgrid_6_1_sm_circuit_B.Sum_d[1];
  dc_microgrid_6_1_sm_circuit_B.phi[2] =
    dc_microgrid_6_1_sm_circuit_P.DegRad_Gain_g *
    dc_microgrid_6_1_sm_circuit_B.Sum_d[2];

  /* Trigonometry: '<S17>/Trigonometric Function2' */
  for (iU = 0; iU < 3; iU = iU + 1) {
    u = dc_microgrid_6_1_sm_circuit_B.phi[iU];
    Bias = sin(u);
    u = cos(u);
    dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction2_o1[iU] = Bias;
    dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction2_o2[iU] = u;
  }

  /* End of Trigonometry: '<S17>/Trigonometric Function2' */

  /* Product: '<S17>/Product1' */
  dc_microgrid_6_1_sm_circuit_B.Product1[0] =
    dc_microgrid_6_1_sm_circuit_B.Gain1[0] *
    dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction2_o2[0];
  dc_microgrid_6_1_sm_circuit_B.Product1[1] =
    dc_microgrid_6_1_sm_circuit_B.Gain1[1] *
    dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction2_o2[1];
  dc_microgrid_6_1_sm_circuit_B.Product1[2] =
    dc_microgrid_6_1_sm_circuit_B.Gain1[2] *
    dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction2_o2[2];

  /* Sum: '<S3>/Add' */
  dc_microgrid_6_1_sm_circuit_B.Add = (dc_microgrid_6_1_sm_circuit_B.Product1[0]
    + dc_microgrid_6_1_sm_circuit_B.Product1[1]) +
    dc_microgrid_6_1_sm_circuit_B.Product1[2];
  if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
    /* Gain: '<S83>/do not delete this gain' */
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain =
      dc_microgrid_6_1_sm_circuit_P.donotdeletethisgain_Gain *
      dc_microgrid_6_1_sm_circuit_B.StateSpace_o1[17];

    /* Gain: '<S84>/do not delete this gain' */
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_j =
      dc_microgrid_6_1_sm_circuit_P.donotdeletethisgain_Gain_n *
      dc_microgrid_6_1_sm_circuit_B.StateSpace_o1[18];

    /* Gain: '<S85>/do not delete this gain' */
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_p =
      dc_microgrid_6_1_sm_circuit_P.donotdeletethisgain_Gain_i *
      dc_microgrid_6_1_sm_circuit_B.StateSpace_o1[19];

    /* Gain: '<S19>/Kv' */
    dc_microgrid_6_1_sm_circuit_B.Kv[0] = dc_microgrid_6_1_sm_circuit_P.Kv_Gain *
      dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain;
    dc_microgrid_6_1_sm_circuit_B.Kv[1] = dc_microgrid_6_1_sm_circuit_P.Kv_Gain *
      dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_j;
    dc_microgrid_6_1_sm_circuit_B.Kv[2] = dc_microgrid_6_1_sm_circuit_P.Kv_Gain *
      dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_p;

    /* DataTypeConversion: '<S18>/Data Type Conversion' incorporates:
     *  Constant: '<S18>/Constant'
     */
    dc_microgrid_6_1_sm_circuit_B.DataTypeConversion_l =
      (dc_microgrid_6_1_sm_circuit_P.RMS1_TrueRMS != 0.0);

    /* Outputs for Enabled SubSystem: '<S18>/TrueRMS ' incorporates:
     *  EnablePort: '<S72>/Enable'
     */
    if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
      if (dc_microgrid_6_1_sm_circuit_B.DataTypeConversion_l) {
        if (!dc_microgrid_6_1_sm_circuit_DW.TrueRMS_MODE) {
          dc_microgrid_6_1_sm_circuit_DW.TrueRMS_MODE = true;
        }
      } else if (dc_microgrid_6_1_sm_circuit_DW.TrueRMS_MODE) {
        dc_microgrid_6_1_sm_circuit_DW.TrueRMS_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S18>/TrueRMS ' */
  }

  /* Outputs for Enabled SubSystem: '<S18>/TrueRMS ' incorporates:
   *  EnablePort: '<S72>/Enable'
   */
  if (dc_microgrid_6_1_sm_circuit_DW.TrueRMS_MODE) {
    /* Clock: '<S79>/Clock' */
    dc_microgrid_6_1_sm_circuit_B.Clock_h =
      dc_microgrid_6_1_sm_circuit_M->Timing.t[0];

    /* Integrator: '<S79>/integrator' */
    dc_microgrid_6_1_sm_circuit_B.integrator_k =
      dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE_c;

    /* TransportDelay: '<S79>/Transport Delay' */
    {
      real_T **uBuffer = (real_T**)
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_PWORK_f.TUbufferPtrs[0];
      real_T simTime = dc_microgrid_6_1_sm_circuit_M->Timing.t[0];
      real_T tMinusDelay = simTime -
        (dc_microgrid_6_1_sm_circuit_P.TransportDelay_Delay_f);
      dc_microgrid_6_1_sm_circuit_B.TransportDelay_j = rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *uBuffer,
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_o.CircularBufSize,
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_o.Last,
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_o.Tail,
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_o.Head,
        dc_microgrid_6_1_sm_circuit_P.TransportDelay_InitOutput_a,
        0,
        0);
    }

    if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
      /* Memory: '<S79>/Memory' */
      dc_microgrid_6_1_sm_circuit_B.Memory_c =
        dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_f;
    }

    /* RelationalOperator: '<S79>/Relational Operator' incorporates:
     *  Constant: '<S79>/K1'
     */
    dc_microgrid_6_1_sm_circuit_B.RelationalOperator_ej =
      (dc_microgrid_6_1_sm_circuit_B.Clock_h >=
       dc_microgrid_6_1_sm_circuit_P.K1_Value_p);

    /* Switch: '<S79>/Switch' */
    if (dc_microgrid_6_1_sm_circuit_B.RelationalOperator_ej) {
      /* Sum: '<S79>/Sum' */
      dc_microgrid_6_1_sm_circuit_B.Sum_a =
        dc_microgrid_6_1_sm_circuit_B.integrator_k -
        dc_microgrid_6_1_sm_circuit_B.TransportDelay_j;

      /* Gain: '<S79>/Gain' */
      dc_microgrid_6_1_sm_circuit_B.Gain =
        dc_microgrid_6_1_sm_circuit_P.Gain_Gain_l *
        dc_microgrid_6_1_sm_circuit_B.Sum_a;

      /* Switch: '<S79>/Switch' */
      dc_microgrid_6_1_sm_circuit_B.Switch_cu =
        dc_microgrid_6_1_sm_circuit_B.Gain;
    } else {
      /* Switch: '<S79>/Switch' */
      dc_microgrid_6_1_sm_circuit_B.Switch_cu =
        dc_microgrid_6_1_sm_circuit_B.Memory_c;
    }

    /* End of Switch: '<S79>/Switch' */

    /* Product: '<S72>/Product' */
    dc_microgrid_6_1_sm_circuit_B.Product_kk = dc_microgrid_6_1_sm_circuit_B.Kv
      [1] * dc_microgrid_6_1_sm_circuit_B.Kv[1];

    /* Saturate: '<S72>/Saturation to avoid negative sqrt' */
    if (dc_microgrid_6_1_sm_circuit_B.Switch_cu >
        dc_microgrid_6_1_sm_circuit_P.Saturationtoavoidnegativesqrt_U) {
      /* Saturate: '<S72>/Saturation to avoid negative sqrt' */
      dc_microgrid_6_1_sm_circuit_B.Saturationtoavoidnegativesqrt =
        dc_microgrid_6_1_sm_circuit_P.Saturationtoavoidnegativesqrt_U;
    } else if (dc_microgrid_6_1_sm_circuit_B.Switch_cu <
               dc_microgrid_6_1_sm_circuit_P.Saturationtoavoidnegativesqrt_L) {
      /* Saturate: '<S72>/Saturation to avoid negative sqrt' */
      dc_microgrid_6_1_sm_circuit_B.Saturationtoavoidnegativesqrt =
        dc_microgrid_6_1_sm_circuit_P.Saturationtoavoidnegativesqrt_L;
    } else {
      /* Saturate: '<S72>/Saturation to avoid negative sqrt' */
      dc_microgrid_6_1_sm_circuit_B.Saturationtoavoidnegativesqrt =
        dc_microgrid_6_1_sm_circuit_B.Switch_cu;
    }

    /* End of Saturate: '<S72>/Saturation to avoid negative sqrt' */

    /* Sqrt: '<S72>/Sqrt' */
    dc_microgrid_6_1_sm_circuit_B.Sqrt_p = sqrt
      (dc_microgrid_6_1_sm_circuit_B.Saturationtoavoidnegativesqrt);
  }

  /* End of Outputs for SubSystem: '<S18>/TrueRMS ' */
  if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
    /* Logic: '<S18>/Logical Operator' */
    dc_microgrid_6_1_sm_circuit_B.LogicalOperator =
      !dc_microgrid_6_1_sm_circuit_B.DataTypeConversion_l;

    /* Outputs for Enabled SubSystem: '<S18>/RMS ' incorporates:
     *  EnablePort: '<S71>/Enable'
     */
    if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
      if (dc_microgrid_6_1_sm_circuit_B.LogicalOperator) {
        if (!dc_microgrid_6_1_sm_circuit_DW.RMS_MODE) {
          dc_microgrid_6_1_sm_circuit_DW.RMS_MODE = true;
        }
      } else if (dc_microgrid_6_1_sm_circuit_DW.RMS_MODE) {
        dc_microgrid_6_1_sm_circuit_DW.RMS_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S18>/RMS ' */
  }

  /* Outputs for Enabled SubSystem: '<S18>/RMS ' incorporates:
   *  EnablePort: '<S71>/Enable'
   */
  if (dc_microgrid_6_1_sm_circuit_DW.RMS_MODE) {
    /* Integrator: '<S77>/integrator' */
    dc_microgrid_6_1_sm_circuit_B.integrator_h =
      dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE_a;

    /* TransportDelay: '<S77>/Transport Delay' */
    {
      real_T **uBuffer = (real_T**)
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_PWORK_ny.TUbufferPtrs[0];
      real_T simTime = dc_microgrid_6_1_sm_circuit_M->Timing.t[0];
      real_T tMinusDelay = simTime -
        (dc_microgrid_6_1_sm_circuit_P.TransportDelay_Delay);
      dc_microgrid_6_1_sm_circuit_B.TransportDelay_c = rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *uBuffer,
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_ns.CircularBufSize,
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_ns.Last,
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_ns.Tail,
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_ns.Head,
        dc_microgrid_6_1_sm_circuit_P.TransportDelay_InitOutput,
        0,
        0);
    }

    /* Clock: '<S77>/Clock' */
    dc_microgrid_6_1_sm_circuit_B.Clock_js =
      dc_microgrid_6_1_sm_circuit_M->Timing.t[0];

    /* RelationalOperator: '<S77>/Relational Operator' incorporates:
     *  Constant: '<S77>/K1'
     */
    dc_microgrid_6_1_sm_circuit_B.RelationalOperator_fc =
      (dc_microgrid_6_1_sm_circuit_B.Clock_js >=
       dc_microgrid_6_1_sm_circuit_P.K1_Value_m);
    if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
      /* Memory: '<S77>/Memory' */
      dc_microgrid_6_1_sm_circuit_B.Memory_m =
        dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_da;
    }

    /* Switch: '<S77>/Switch' */
    if (dc_microgrid_6_1_sm_circuit_B.RelationalOperator_fc) {
      /* Sum: '<S77>/Sum' */
      dc_microgrid_6_1_sm_circuit_B.Sum_e =
        dc_microgrid_6_1_sm_circuit_B.integrator_h -
        dc_microgrid_6_1_sm_circuit_B.TransportDelay_c;

      /* Gain: '<S77>/Gain' */
      dc_microgrid_6_1_sm_circuit_B.Gain_e =
        dc_microgrid_6_1_sm_circuit_P.Gain_Gain_id *
        dc_microgrid_6_1_sm_circuit_B.Sum_e;

      /* Switch: '<S77>/Switch' */
      dc_microgrid_6_1_sm_circuit_B.Switch_k1 =
        dc_microgrid_6_1_sm_circuit_B.Gain_e;
    } else {
      /* Switch: '<S77>/Switch' */
      dc_microgrid_6_1_sm_circuit_B.Switch_k1 =
        dc_microgrid_6_1_sm_circuit_B.Memory_m;
    }

    /* End of Switch: '<S77>/Switch' */

    /* Integrator: '<S76>/integrator' */
    dc_microgrid_6_1_sm_circuit_B.integrator_a =
      dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE_ao;

    /* TransportDelay: '<S76>/Transport Delay' */
    {
      real_T **uBuffer = (real_T**)
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_PWORK_nz.TUbufferPtrs[0];
      real_T simTime = dc_microgrid_6_1_sm_circuit_M->Timing.t[0];
      real_T tMinusDelay = simTime -
        (dc_microgrid_6_1_sm_circuit_P.TransportDelay_Delay_a);
      dc_microgrid_6_1_sm_circuit_B.TransportDelay_an = rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *uBuffer,
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_bl.CircularBufSize,
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_bl.Last,
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_bl.Tail,
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_bl.Head,
        dc_microgrid_6_1_sm_circuit_P.TransportDelay_InitOutput_n,
        0,
        0);
    }

    /* Clock: '<S76>/Clock' */
    dc_microgrid_6_1_sm_circuit_B.Clock_a =
      dc_microgrid_6_1_sm_circuit_M->Timing.t[0];

    /* RelationalOperator: '<S76>/Relational Operator' incorporates:
     *  Constant: '<S76>/K1'
     */
    dc_microgrid_6_1_sm_circuit_B.RelationalOperator_a =
      (dc_microgrid_6_1_sm_circuit_B.Clock_a >=
       dc_microgrid_6_1_sm_circuit_P.K1_Value_l);
    if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
      /* Memory: '<S76>/Memory' */
      dc_microgrid_6_1_sm_circuit_B.Memory_h =
        dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_i;
    }

    /* Switch: '<S76>/Switch' */
    if (dc_microgrid_6_1_sm_circuit_B.RelationalOperator_a) {
      /* Sum: '<S76>/Sum' */
      dc_microgrid_6_1_sm_circuit_B.Sum_g =
        dc_microgrid_6_1_sm_circuit_B.integrator_a -
        dc_microgrid_6_1_sm_circuit_B.TransportDelay_an;

      /* Gain: '<S76>/Gain' */
      dc_microgrid_6_1_sm_circuit_B.Gain_m =
        dc_microgrid_6_1_sm_circuit_P.Gain_Gain_m *
        dc_microgrid_6_1_sm_circuit_B.Sum_g;

      /* Switch: '<S76>/Switch' */
      dc_microgrid_6_1_sm_circuit_B.Switch_o =
        dc_microgrid_6_1_sm_circuit_B.Gain_m;
    } else {
      /* Switch: '<S76>/Switch' */
      dc_microgrid_6_1_sm_circuit_B.Switch_o =
        dc_microgrid_6_1_sm_circuit_B.Memory_h;
    }

    /* End of Switch: '<S76>/Switch' */

    /* RealImagToComplex: '<S73>/Real-Imag to Complex' */
    dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_a.re =
      dc_microgrid_6_1_sm_circuit_B.Switch_k1;
    dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_a.im =
      dc_microgrid_6_1_sm_circuit_B.Switch_o;

    /* ComplexToMagnitudeAngle: '<S73>/Complex to Magnitude-Angle' incorporates:
     *  RealImagToComplex: '<S73>/Real-Imag to Complex'
     */
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o1_h = rt_hypotd_snf
      (dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_a.re,
       dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_a.im);

    /* ComplexToMagnitudeAngle: '<S73>/Complex to Magnitude-Angle' incorporates:
     *  RealImagToComplex: '<S73>/Real-Imag to Complex'
     */
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o2_fx = rt_atan2d_snf
      (dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_a.im,
       dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_a.re);

    /* Sin: '<S73>/sin(wt)' */
    Bias = 6.2831853071795862 * dc_microgrid_6_1_sm_circuit_P.Fourier1_Freq;

    /* Sin: '<S73>/sin(wt)' */
    dc_microgrid_6_1_sm_circuit_B.sinwt_g = sin(Bias *
      dc_microgrid_6_1_sm_circuit_M->Timing.t[0] +
      dc_microgrid_6_1_sm_circuit_P.sinwt_Phase) *
      dc_microgrid_6_1_sm_circuit_P.sinwt_Amp +
      dc_microgrid_6_1_sm_circuit_P.sinwt_Bias;

    /* Product: '<S73>/Product' */
    dc_microgrid_6_1_sm_circuit_B.Product_c = dc_microgrid_6_1_sm_circuit_B.Kv[1]
      * dc_microgrid_6_1_sm_circuit_B.sinwt_g;

    /* Sin: '<S73>/cos(wt)' */
    Bias = 6.2831853071795862 * dc_microgrid_6_1_sm_circuit_P.Fourier1_Freq;

    /* Sin: '<S73>/cos(wt)' */
    dc_microgrid_6_1_sm_circuit_B.coswt_a = sin(Bias *
      dc_microgrid_6_1_sm_circuit_M->Timing.t[0] +
      dc_microgrid_6_1_sm_circuit_P.coswt_Phase) *
      dc_microgrid_6_1_sm_circuit_P.coswt_Amp +
      dc_microgrid_6_1_sm_circuit_P.coswt_Bias;

    /* Product: '<S73>/Product1' */
    dc_microgrid_6_1_sm_circuit_B.Product1_d = dc_microgrid_6_1_sm_circuit_B.Kv
      [1] * dc_microgrid_6_1_sm_circuit_B.coswt_a;

    /* Gain: '<S73>/Rad->Deg.' */
    dc_microgrid_6_1_sm_circuit_B.RadDeg_p =
      dc_microgrid_6_1_sm_circuit_P.RadDeg_Gain *
      dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o2_fx;

    /* Gain: '<S71>/Gain' */
    dc_microgrid_6_1_sm_circuit_B.Gain_b =
      dc_microgrid_6_1_sm_circuit_P.Gain_Gain_e *
      dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o1_h;
  }

  /* End of Outputs for SubSystem: '<S18>/RMS ' */

  /* Switch: '<S18>/Switch' */
  if (dc_microgrid_6_1_sm_circuit_B.DataTypeConversion_l) {
    /* Switch: '<S18>/Switch' */
    dc_microgrid_6_1_sm_circuit_B.Switch_m =
      dc_microgrid_6_1_sm_circuit_B.Sqrt_p;
  } else {
    /* Switch: '<S18>/Switch' */
    dc_microgrid_6_1_sm_circuit_B.Switch_m =
      dc_microgrid_6_1_sm_circuit_B.Gain_b;
  }

  /* End of Switch: '<S18>/Switch' */
  if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
    /* S-Function (OP_SEND): '<S97>/S-Function' */

    /* Level2 S-Function Block: '<S97>/S-Function' (OP_SEND) */
    {
      SimStruct *rts = dc_microgrid_6_1_sm_circuit_M->childSfunctions[1];
      sfcnOutputs(rts,0);
    }

    /* Gain: '<S86>/do not delete this gain' */
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_l =
      dc_microgrid_6_1_sm_circuit_P.donotdeletethisgain_Gain_d *
      dc_microgrid_6_1_sm_circuit_B.StateSpace_o1[12];

    /* Gain: '<S87>/do not delete this gain' */
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_jm =
      dc_microgrid_6_1_sm_circuit_P.donotdeletethisgain_Gain_dt *
      dc_microgrid_6_1_sm_circuit_B.StateSpace_o1[13];

    /* Gain: '<S88>/do not delete this gain' */
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_jz =
      dc_microgrid_6_1_sm_circuit_P.donotdeletethisgain_Gain_h *
      dc_microgrid_6_1_sm_circuit_B.StateSpace_o1[14];

    /* Gain: '<S19>/Kv1' */
    dc_microgrid_6_1_sm_circuit_B.Kv1[0] =
      dc_microgrid_6_1_sm_circuit_P.Kv1_Gain *
      dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_l;
    dc_microgrid_6_1_sm_circuit_B.Kv1[1] =
      dc_microgrid_6_1_sm_circuit_P.Kv1_Gain *
      dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_jm;
    dc_microgrid_6_1_sm_circuit_B.Kv1[2] =
      dc_microgrid_6_1_sm_circuit_P.Kv1_Gain *
      dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_jz;
  }

  /* Sin: '<S61>/sin(wt)' */
  Bias = 6.2831853071795862 * dc_microgrid_6_1_sm_circuit_P.Fourier_Freq;

  /* Sin: '<S61>/sin(wt)' */
  dc_microgrid_6_1_sm_circuit_B.sinwt = sin(Bias *
    dc_microgrid_6_1_sm_circuit_M->Timing.t[0] +
    dc_microgrid_6_1_sm_circuit_P.sinwt_Phase_i) *
    dc_microgrid_6_1_sm_circuit_P.sinwt_Amp_h +
    dc_microgrid_6_1_sm_circuit_P.sinwt_Bias_b;

  /* Product: '<S61>/Product' */
  dc_microgrid_6_1_sm_circuit_B.Product[0] = dc_microgrid_6_1_sm_circuit_B.Kv1[0]
    * dc_microgrid_6_1_sm_circuit_B.sinwt;
  dc_microgrid_6_1_sm_circuit_B.Product[1] = dc_microgrid_6_1_sm_circuit_B.Kv1[1]
    * dc_microgrid_6_1_sm_circuit_B.sinwt;
  dc_microgrid_6_1_sm_circuit_B.Product[2] = dc_microgrid_6_1_sm_circuit_B.Kv1[2]
    * dc_microgrid_6_1_sm_circuit_B.sinwt;

  /* Sin: '<S61>/cos(wt)' */
  Bias = 6.2831853071795862 * dc_microgrid_6_1_sm_circuit_P.Fourier_Freq;

  /* Sin: '<S61>/cos(wt)' */
  dc_microgrid_6_1_sm_circuit_B.coswt = sin(Bias *
    dc_microgrid_6_1_sm_circuit_M->Timing.t[0] +
    dc_microgrid_6_1_sm_circuit_P.coswt_Phase_o) *
    dc_microgrid_6_1_sm_circuit_P.coswt_Amp_f +
    dc_microgrid_6_1_sm_circuit_P.coswt_Bias_a;

  /* Product: '<S61>/Product1' */
  dc_microgrid_6_1_sm_circuit_B.Product1_o[0] =
    dc_microgrid_6_1_sm_circuit_B.Kv1[0] * dc_microgrid_6_1_sm_circuit_B.coswt;
  dc_microgrid_6_1_sm_circuit_B.Product1_o[1] =
    dc_microgrid_6_1_sm_circuit_B.Kv1[1] * dc_microgrid_6_1_sm_circuit_B.coswt;
  dc_microgrid_6_1_sm_circuit_B.Product1_o[2] =
    dc_microgrid_6_1_sm_circuit_B.Kv1[2] * dc_microgrid_6_1_sm_circuit_B.coswt;

  /* Sin: '<S62>/sin(wt)' */
  Bias = 6.2831853071795862 * dc_microgrid_6_1_sm_circuit_P.Fourier1_Freq_g;

  /* Sin: '<S62>/sin(wt)' */
  dc_microgrid_6_1_sm_circuit_B.sinwt_b = sin(Bias *
    dc_microgrid_6_1_sm_circuit_M->Timing.t[0] +
    dc_microgrid_6_1_sm_circuit_P.sinwt_Phase_h) *
    dc_microgrid_6_1_sm_circuit_P.sinwt_Amp_f +
    dc_microgrid_6_1_sm_circuit_P.sinwt_Bias_c;

  /* Product: '<S62>/Product' */
  dc_microgrid_6_1_sm_circuit_B.Product_l[0] = dc_microgrid_6_1_sm_circuit_B.Kv
    [0] * dc_microgrid_6_1_sm_circuit_B.sinwt_b;
  dc_microgrid_6_1_sm_circuit_B.Product_l[1] = dc_microgrid_6_1_sm_circuit_B.Kv
    [1] * dc_microgrid_6_1_sm_circuit_B.sinwt_b;
  dc_microgrid_6_1_sm_circuit_B.Product_l[2] = dc_microgrid_6_1_sm_circuit_B.Kv
    [2] * dc_microgrid_6_1_sm_circuit_B.sinwt_b;

  /* Sin: '<S62>/cos(wt)' */
  Bias = 6.2831853071795862 * dc_microgrid_6_1_sm_circuit_P.Fourier1_Freq_g;

  /* Sin: '<S62>/cos(wt)' */
  dc_microgrid_6_1_sm_circuit_B.coswt_e = sin(Bias *
    dc_microgrid_6_1_sm_circuit_M->Timing.t[0] +
    dc_microgrid_6_1_sm_circuit_P.coswt_Phase_h) *
    dc_microgrid_6_1_sm_circuit_P.coswt_Amp_j +
    dc_microgrid_6_1_sm_circuit_P.coswt_Bias_j;

  /* Product: '<S62>/Product1' */
  dc_microgrid_6_1_sm_circuit_B.Product1_oy[0] =
    dc_microgrid_6_1_sm_circuit_B.Kv[0] * dc_microgrid_6_1_sm_circuit_B.coswt_e;
  dc_microgrid_6_1_sm_circuit_B.Product1_oy[1] =
    dc_microgrid_6_1_sm_circuit_B.Kv[1] * dc_microgrid_6_1_sm_circuit_B.coswt_e;
  dc_microgrid_6_1_sm_circuit_B.Product1_oy[2] =
    dc_microgrid_6_1_sm_circuit_B.Kv[2] * dc_microgrid_6_1_sm_circuit_B.coswt_e;

  /* Product: '<S17>/Product3' */
  dc_microgrid_6_1_sm_circuit_B.Product3[0] =
    dc_microgrid_6_1_sm_circuit_B.Gain1[0] *
    dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction2_o1[0];
  dc_microgrid_6_1_sm_circuit_B.Product3[1] =
    dc_microgrid_6_1_sm_circuit_B.Gain1[1] *
    dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction2_o1[1];
  dc_microgrid_6_1_sm_circuit_B.Product3[2] =
    dc_microgrid_6_1_sm_circuit_B.Gain1[2] *
    dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction2_o1[2];

  /* Signum: '<S3>/Sign' */
  u_0 = dc_microgrid_6_1_sm_circuit_B.Add;
  if (u_0 < 0.0) {
    /* Signum: '<S3>/Sign' */
    dc_microgrid_6_1_sm_circuit_B.Sign = -1.0;
  } else if (u_0 > 0.0) {
    /* Signum: '<S3>/Sign' */
    dc_microgrid_6_1_sm_circuit_B.Sign = 1.0;
  } else if (u_0 == 0.0) {
    /* Signum: '<S3>/Sign' */
    dc_microgrid_6_1_sm_circuit_B.Sign = 0.0;
  } else {
    /* Signum: '<S3>/Sign' */
    dc_microgrid_6_1_sm_circuit_B.Sign = u_0;
  }

  /* End of Signum: '<S3>/Sign' */

  /* Product: '<S3>/Product' */
  dc_microgrid_6_1_sm_circuit_B.Product_e = dc_microgrid_6_1_sm_circuit_B.Sign *
    0.0;
  if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
    /* Gain: '<S20>/do not delete this gain' */
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_pt =
      dc_microgrid_6_1_sm_circuit_P.donotdeletethisgain_Gain_c *
      dc_microgrid_6_1_sm_circuit_B.StateSpace_o1[15];

    /* Gain: '<S13>/do not delete this gain' */
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_i =
      dc_microgrid_6_1_sm_circuit_P.donotdeletethisgain_Gain_o *
      dc_microgrid_6_1_sm_circuit_B.StateSpace_o1[16];

    /* Product: '<S3>/Product4' */
    dc_microgrid_6_1_sm_circuit_B.Product4 =
      dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_pt *
      dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_i;
    for (i_0 = 0; i_0 < 6; i_0 = i_0 + 1) {
      /* UnitDelay: '<S23>/Unit Delay4' */
      dc_microgrid_6_1_sm_circuit_B.UnitDelay4[i_0] =
        dc_microgrid_6_1_sm_circuit_DW.UnitDelay4_DSTATE[i_0];
    }

    for (i = 0; i < 6; i = i + 1) {
      /* DataTypeConversion: '<S31>/Data Type Conversion' */
      dc_microgrid_6_1_sm_circuit_B.DataTypeConversion[i] =
        dc_microgrid_6_1_sm_circuit_B.UnitDelay4[i];
    }

    /* Gain: '<S33>/do not delete this gain' */
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_j4 =
      dc_microgrid_6_1_sm_circuit_P.donotdeletethisgain_Gain_ox *
      dc_microgrid_6_1_sm_circuit_B.StateSpace_o1[6];

    /* Gain: '<S38>/do not delete this gain' */
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_o =
      dc_microgrid_6_1_sm_circuit_P.donotdeletethisgain_Gain_m *
      dc_microgrid_6_1_sm_circuit_B.StateSpace_o1[7];

    /* Gain: '<S39>/do not delete this gain' */
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_c =
      dc_microgrid_6_1_sm_circuit_P.donotdeletethisgain_Gain_mc *
      dc_microgrid_6_1_sm_circuit_B.StateSpace_o1[8];

    /* Product: '<S36>/Product' */
    dc_microgrid_6_1_sm_circuit_B.Product_d[0] =
      dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_j4 *
      dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_j4;
    dc_microgrid_6_1_sm_circuit_B.Product_d[1] =
      dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_o *
      dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_o;
    dc_microgrid_6_1_sm_circuit_B.Product_d[2] =
      dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_c *
      dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_c;

    /* DiscreteIntegrator: '<S48>/Integ4' */
    if (dc_microgrid_6_1_sm_circuit_DW.Integ4_SYSTEM_ENABLE != 0) {
      /* DiscreteIntegrator: '<S48>/Integ4' */
      dc_microgrid_6_1_sm_circuit_B.Integ4[0] =
        dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE[0];
      dc_microgrid_6_1_sm_circuit_B.Integ4[1] =
        dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE[1];
      dc_microgrid_6_1_sm_circuit_B.Integ4[2] =
        dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE[2];
    } else {
      /* DiscreteIntegrator: '<S48>/Integ4' */
      dc_microgrid_6_1_sm_circuit_B.Integ4[0] =
        dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE[0] +
        dc_microgrid_6_1_sm_circuit_P.Integ4_gainval *
        dc_microgrid_6_1_sm_circuit_B.Product_d[0];
      dc_microgrid_6_1_sm_circuit_B.Integ4[1] =
        dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE[1] +
        dc_microgrid_6_1_sm_circuit_P.Integ4_gainval *
        dc_microgrid_6_1_sm_circuit_B.Product_d[1];
      dc_microgrid_6_1_sm_circuit_B.Integ4[2] =
        dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE[2] +
        dc_microgrid_6_1_sm_circuit_P.Integ4_gainval *
        dc_microgrid_6_1_sm_circuit_B.Product_d[2];
    }

    /* End of DiscreteIntegrator: '<S48>/Integ4' */

    /* S-Function (discreteVariableTransportDelay): '<S49>/S-Function ' incorporates:
     *  Constant: '<S48>/K1'
     */
    /* S-Function block: <S49>/S-Function  */
    {
      int_T indDelayed;
      int_T discreteDelay;

      /* Input present value(s) */
      ((real_T *)dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK.uBuffers[0])
        [dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_k.indEnd] =
        dc_microgrid_6_1_sm_circuit_B.Integ4[0];
      ((real_T *)dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK.uBuffers[1])
        [dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_k.indEnd] =
        dc_microgrid_6_1_sm_circuit_B.Integ4[1];
      ((real_T *)dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK.uBuffers[2])
        [dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_k.indEnd] =
        dc_microgrid_6_1_sm_circuit_B.Integ4[2];

      /* Calculate delayed index */
      discreteDelay =
        (int_T)floor((dc_microgrid_6_1_sm_circuit_P.K1_Value_e/0.0001) + 0.5);
      if (discreteDelay >
          dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_k.maxDiscrDelay)
        discreteDelay =
          dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_k.maxDiscrDelay;
      indDelayed = dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_k.indEnd -
        ((discreteDelay > 0) ? discreteDelay : 0);
      if (indDelayed < 0) {
        if (dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_k.indBeg == 0 )
          indDelayed = 0;
        else
          indDelayed += dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_k.bufSz;
      }

      /* Output past value(s) */
      dc_microgrid_6_1_sm_circuit_B.SFunction_p[0] = ((real_T *)
        dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK.uBuffers[0])[indDelayed];
      dc_microgrid_6_1_sm_circuit_B.SFunction_p[1] = ((real_T *)
        dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK.uBuffers[1])[indDelayed];
      dc_microgrid_6_1_sm_circuit_B.SFunction_p[2] = ((real_T *)
        dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK.uBuffers[2])[indDelayed];
    }

    /* UnitDelay: '<S48>/Unit Delay' */
    dc_microgrid_6_1_sm_circuit_B.UnitDelay[0] =
      dc_microgrid_6_1_sm_circuit_DW.UnitDelay_DSTATE[0];
    dc_microgrid_6_1_sm_circuit_B.UnitDelay[1] =
      dc_microgrid_6_1_sm_circuit_DW.UnitDelay_DSTATE[1];
    dc_microgrid_6_1_sm_circuit_B.UnitDelay[2] =
      dc_microgrid_6_1_sm_circuit_DW.UnitDelay_DSTATE[2];

    /* Step: '<S48>/Step' */
    u = dc_microgrid_6_1_sm_circuit_M->Timing.t[1];
    Bias = 1.0 / dc_microgrid_6_1_sm_circuit_P.Vab3_Freq;
    if (u < Bias) {
      /* Step: '<S48>/Step' */
      dc_microgrid_6_1_sm_circuit_B.Step = dc_microgrid_6_1_sm_circuit_P.Step_Y0;
    } else {
      /* Step: '<S48>/Step' */
      dc_microgrid_6_1_sm_circuit_B.Step =
        dc_microgrid_6_1_sm_circuit_P.Step_YFinal;
    }

    /* End of Step: '<S48>/Step' */

    /* Switch: '<S48>/Switch' incorporates:
     *  Constant: '<S48>/Constant'
     */
    if (dc_microgrid_6_1_sm_circuit_B.Step >=
        dc_microgrid_6_1_sm_circuit_P.Switch_Threshold) {
      /* Gain: '<S48>/Gain' */
      dc_microgrid_6_1_sm_circuit_B.Gain_bl[0] =
        dc_microgrid_6_1_sm_circuit_P.Gain_Gain_il *
        dc_microgrid_6_1_sm_circuit_B.UnitDelay[0];
      dc_microgrid_6_1_sm_circuit_B.Gain_bl[1] =
        dc_microgrid_6_1_sm_circuit_P.Gain_Gain_il *
        dc_microgrid_6_1_sm_circuit_B.UnitDelay[1];
      dc_microgrid_6_1_sm_circuit_B.Gain_bl[2] =
        dc_microgrid_6_1_sm_circuit_P.Gain_Gain_il *
        dc_microgrid_6_1_sm_circuit_B.UnitDelay[2];

      /* Gain: '<S48>/Gain1' */
      dc_microgrid_6_1_sm_circuit_B.Gain1_b[0] =
        dc_microgrid_6_1_sm_circuit_P.Gain1_Gain_c *
        dc_microgrid_6_1_sm_circuit_B.Product_d[0];
      dc_microgrid_6_1_sm_circuit_B.Gain1_b[1] =
        dc_microgrid_6_1_sm_circuit_P.Gain1_Gain_c *
        dc_microgrid_6_1_sm_circuit_B.Product_d[1];
      dc_microgrid_6_1_sm_circuit_B.Gain1_b[2] =
        dc_microgrid_6_1_sm_circuit_P.Gain1_Gain_c *
        dc_microgrid_6_1_sm_circuit_B.Product_d[2];

      /* Sum: '<S48>/Sum1' */
      dc_microgrid_6_1_sm_circuit_B.Correction_o[0] =
        dc_microgrid_6_1_sm_circuit_B.Gain1_b[0] -
        dc_microgrid_6_1_sm_circuit_B.Gain_bl[0];
      dc_microgrid_6_1_sm_circuit_B.Correction_o[1] =
        dc_microgrid_6_1_sm_circuit_B.Gain1_b[1] -
        dc_microgrid_6_1_sm_circuit_B.Gain_bl[1];
      dc_microgrid_6_1_sm_circuit_B.Correction_o[2] =
        dc_microgrid_6_1_sm_circuit_B.Gain1_b[2] -
        dc_microgrid_6_1_sm_circuit_B.Gain_bl[2];

      /* Sum: '<S48>/Sum7' */
      dc_microgrid_6_1_sm_circuit_B.Sum7_h[0] =
        dc_microgrid_6_1_sm_circuit_B.Integ4[0] -
        dc_microgrid_6_1_sm_circuit_B.SFunction_p[0];
      dc_microgrid_6_1_sm_circuit_B.Sum7_h[1] =
        dc_microgrid_6_1_sm_circuit_B.Integ4[1] -
        dc_microgrid_6_1_sm_circuit_B.SFunction_p[1];
      dc_microgrid_6_1_sm_circuit_B.Sum7_h[2] =
        dc_microgrid_6_1_sm_circuit_B.Integ4[2] -
        dc_microgrid_6_1_sm_circuit_B.SFunction_p[2];

      /* Product: '<S48>/Product' incorporates:
       *  Constant: '<S48>/K2'
       */
      dc_microgrid_6_1_sm_circuit_B.Meanvalue_m[0] =
        dc_microgrid_6_1_sm_circuit_B.Sum7_h[0] *
        dc_microgrid_6_1_sm_circuit_P.Vab3_Freq;
      dc_microgrid_6_1_sm_circuit_B.Meanvalue_m[1] =
        dc_microgrid_6_1_sm_circuit_B.Sum7_h[1] *
        dc_microgrid_6_1_sm_circuit_P.Vab3_Freq;
      dc_microgrid_6_1_sm_circuit_B.Meanvalue_m[2] =
        dc_microgrid_6_1_sm_circuit_B.Sum7_h[2] *
        dc_microgrid_6_1_sm_circuit_P.Vab3_Freq;

      /* Sum: '<S48>/Sum5' */
      dc_microgrid_6_1_sm_circuit_B.Sum5_c[0] =
        dc_microgrid_6_1_sm_circuit_B.Meanvalue_m[0] +
        dc_microgrid_6_1_sm_circuit_B.Correction_o[0];
      dc_microgrid_6_1_sm_circuit_B.Sum5_c[1] =
        dc_microgrid_6_1_sm_circuit_B.Meanvalue_m[1] +
        dc_microgrid_6_1_sm_circuit_B.Correction_o[1];
      dc_microgrid_6_1_sm_circuit_B.Sum5_c[2] =
        dc_microgrid_6_1_sm_circuit_B.Meanvalue_m[2] +
        dc_microgrid_6_1_sm_circuit_B.Correction_o[2];

      /* Switch: '<S48>/Switch' */
      dc_microgrid_6_1_sm_circuit_B.Switch_c[0] =
        dc_microgrid_6_1_sm_circuit_B.Sum5_c[0];
      dc_microgrid_6_1_sm_circuit_B.Switch_c[1] =
        dc_microgrid_6_1_sm_circuit_B.Sum5_c[1];
      dc_microgrid_6_1_sm_circuit_B.Switch_c[2] =
        dc_microgrid_6_1_sm_circuit_B.Sum5_c[2];
    } else {
      Bias = dc_microgrid_6_1_sm_circuit_P.Vab3_Mag_Init *
        dc_microgrid_6_1_sm_circuit_P.Vab3_Mag_Init;

      /* Switch: '<S48>/Switch' incorporates:
       *  Constant: '<S48>/Constant'
       */
      dc_microgrid_6_1_sm_circuit_B.Switch_c[0] = Bias;
      dc_microgrid_6_1_sm_circuit_B.Switch_c[1] = Bias;
      dc_microgrid_6_1_sm_circuit_B.Switch_c[2] = Bias;
    }

    /* End of Switch: '<S48>/Switch' */

    /* Saturate: '<S36>/Saturation Ajout P.B pour eviter  sqrt(negatif)' */
    u0 = dc_microgrid_6_1_sm_circuit_B.Switch_c[0];
    if (u0 > dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpourevitersqrt) {
      y = dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpourevitersqrt;
    } else if (u0 <
               dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpourevitersq_o) {
      y = dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpourevitersq_o;
    } else {
      y = u0;
    }

    /* Saturate: '<S36>/Saturation Ajout P.B pour eviter  sqrt(negatif)' */
    dc_microgrid_6_1_sm_circuit_B.SaturationAjoutPBpourevitersqrt[0] = y;

    /* Saturate: '<S36>/Saturation Ajout P.B pour eviter  sqrt(negatif)' */
    u0_0 = dc_microgrid_6_1_sm_circuit_B.Switch_c[1];
    if (u0_0 > dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpourevitersqrt) {
      y_0 = dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpourevitersqrt;
    } else if (u0_0 <
               dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpourevitersq_o) {
      y_0 = dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpourevitersq_o;
    } else {
      y_0 = u0_0;
    }

    /* Saturate: '<S36>/Saturation Ajout P.B pour eviter  sqrt(negatif)' */
    dc_microgrid_6_1_sm_circuit_B.SaturationAjoutPBpourevitersqrt[1] = y_0;

    /* Saturate: '<S36>/Saturation Ajout P.B pour eviter  sqrt(negatif)' */
    u0_1 = dc_microgrid_6_1_sm_circuit_B.Switch_c[2];
    if (u0_1 > dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpourevitersqrt) {
      y_1 = dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpourevitersqrt;
    } else if (u0_1 <
               dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpourevitersq_o) {
      y_1 = dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpourevitersq_o;
    } else {
      y_1 = u0_1;
    }

    /* Saturate: '<S36>/Saturation Ajout P.B pour eviter  sqrt(negatif)' */
    dc_microgrid_6_1_sm_circuit_B.SaturationAjoutPBpourevitersqrt[2] = y_1;

    /* Sqrt: '<S36>/Sqrt' */
    dc_microgrid_6_1_sm_circuit_B.Sqrt[0] = sqrt
      (dc_microgrid_6_1_sm_circuit_B.SaturationAjoutPBpourevitersqrt[0]);
    dc_microgrid_6_1_sm_circuit_B.Sqrt[1] = sqrt
      (dc_microgrid_6_1_sm_circuit_B.SaturationAjoutPBpourevitersqrt[1]);
    dc_microgrid_6_1_sm_circuit_B.Sqrt[2] = sqrt
      (dc_microgrid_6_1_sm_circuit_B.SaturationAjoutPBpourevitersqrt[2]);

    /* Gain: '<S40>/do not delete this gain' */
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_or =
      dc_microgrid_6_1_sm_circuit_P.donotdeletethisgain_Gain_ne *
      dc_microgrid_6_1_sm_circuit_B.StateSpace_o1[9];

    /* Gain: '<S41>/do not delete this gain' */
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_c0 =
      dc_microgrid_6_1_sm_circuit_P.donotdeletethisgain_Gain_e *
      dc_microgrid_6_1_sm_circuit_B.StateSpace_o1[10];

    /* Gain: '<S42>/do not delete this gain' */
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_a =
      dc_microgrid_6_1_sm_circuit_P.donotdeletethisgain_Gain_cw *
      dc_microgrid_6_1_sm_circuit_B.StateSpace_o1[11];

    /* Product: '<S37>/Product' */
    dc_microgrid_6_1_sm_circuit_B.Product_o =
      dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_or *
      dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_or;

    /* DiscreteIntegrator: '<S50>/Integ4' */
    if (dc_microgrid_6_1_sm_circuit_DW.Integ4_SYSTEM_ENABLE_b != 0) {
      /* DiscreteIntegrator: '<S50>/Integ4' */
      dc_microgrid_6_1_sm_circuit_B.Integ4_e =
        dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE_a;
    } else {
      /* DiscreteIntegrator: '<S50>/Integ4' */
      dc_microgrid_6_1_sm_circuit_B.Integ4_e =
        dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE_a +
        dc_microgrid_6_1_sm_circuit_P.Integ4_gainval_b *
        dc_microgrid_6_1_sm_circuit_B.Product_o;
    }

    /* End of DiscreteIntegrator: '<S50>/Integ4' */

    /* S-Function (discreteVariableTransportDelay): '<S51>/S-Function ' incorporates:
     *  Constant: '<S50>/K1'
     */
    /* S-Function block: <S51>/S-Function  */
    {
      int_T indDelayed;
      int_T discreteDelay;

      /* Input present value(s) */
      ((real_T *)dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK_p.uBuffers)
        [dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_n.indEnd] =
        dc_microgrid_6_1_sm_circuit_B.Integ4_e;

      /* Calculate delayed index */
      discreteDelay =
        (int_T)floor((dc_microgrid_6_1_sm_circuit_P.K1_Value_hd/0.0001) + 0.5);
      if (discreteDelay >
          dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_n.maxDiscrDelay)
        discreteDelay =
          dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_n.maxDiscrDelay;
      indDelayed = dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_n.indEnd -
        ((discreteDelay > 0) ? discreteDelay : 0);
      if (indDelayed < 0) {
        if (dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_n.indBeg == 0 )
          indDelayed = 0;
        else
          indDelayed += dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_n.bufSz;
      }

      /* Output past value(s) */
      dc_microgrid_6_1_sm_circuit_B.SFunction_m = ((real_T *)
        dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK_p.uBuffers)[indDelayed];
    }

    /* UnitDelay: '<S50>/Unit Delay' */
    dc_microgrid_6_1_sm_circuit_B.UnitDelay_m =
      dc_microgrid_6_1_sm_circuit_DW.UnitDelay_DSTATE_b;

    /* Step: '<S50>/Step' */
    u = dc_microgrid_6_1_sm_circuit_M->Timing.t[1];
    Bias = 1.0 / dc_microgrid_6_1_sm_circuit_P.Vab5_Freq;
    if (u < Bias) {
      /* Step: '<S50>/Step' */
      dc_microgrid_6_1_sm_circuit_B.Step_l =
        dc_microgrid_6_1_sm_circuit_P.Step_Y0_i;
    } else {
      /* Step: '<S50>/Step' */
      dc_microgrid_6_1_sm_circuit_B.Step_l =
        dc_microgrid_6_1_sm_circuit_P.Step_YFinal_m;
    }

    /* End of Step: '<S50>/Step' */

    /* Switch: '<S50>/Switch' */
    if (dc_microgrid_6_1_sm_circuit_B.Step_l >=
        dc_microgrid_6_1_sm_circuit_P.Switch_Threshold_k) {
      /* Gain: '<S50>/Gain' */
      dc_microgrid_6_1_sm_circuit_B.Gain_n =
        dc_microgrid_6_1_sm_circuit_P.Gain_Gain_f *
        dc_microgrid_6_1_sm_circuit_B.UnitDelay_m;

      /* Gain: '<S50>/Gain1' */
      dc_microgrid_6_1_sm_circuit_B.Gain1_i =
        dc_microgrid_6_1_sm_circuit_P.Gain1_Gain_nq *
        dc_microgrid_6_1_sm_circuit_B.Product_o;

      /* Sum: '<S50>/Sum1' */
      dc_microgrid_6_1_sm_circuit_B.Correction =
        dc_microgrid_6_1_sm_circuit_B.Gain1_i -
        dc_microgrid_6_1_sm_circuit_B.Gain_n;

      /* Sum: '<S50>/Sum7' */
      dc_microgrid_6_1_sm_circuit_B.Sum7 =
        dc_microgrid_6_1_sm_circuit_B.Integ4_e -
        dc_microgrid_6_1_sm_circuit_B.SFunction_m;

      /* Product: '<S50>/Product' incorporates:
       *  Constant: '<S50>/K2'
       */
      dc_microgrid_6_1_sm_circuit_B.Meanvalue =
        dc_microgrid_6_1_sm_circuit_B.Sum7 *
        dc_microgrid_6_1_sm_circuit_P.Vab5_Freq;

      /* Sum: '<S50>/Sum5' */
      dc_microgrid_6_1_sm_circuit_B.Sum5 =
        dc_microgrid_6_1_sm_circuit_B.Meanvalue +
        dc_microgrid_6_1_sm_circuit_B.Correction;

      /* Switch: '<S50>/Switch' */
      dc_microgrid_6_1_sm_circuit_B.Switch_b =
        dc_microgrid_6_1_sm_circuit_B.Sum5;
    } else {
      /* Switch: '<S50>/Switch' incorporates:
       *  Constant: '<S50>/Constant'
       */
      dc_microgrid_6_1_sm_circuit_B.Switch_b =
        dc_microgrid_6_1_sm_circuit_P.Vab5_Mag_Init *
        dc_microgrid_6_1_sm_circuit_P.Vab5_Mag_Init;
    }

    /* End of Switch: '<S50>/Switch' */

    /* Saturate: '<S37>/Saturation Ajout P.B pour eviter  sqrt(negatif)' */
    if (dc_microgrid_6_1_sm_circuit_B.Switch_b >
        dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpourevitersq_d) {
      /* Saturate: '<S37>/Saturation Ajout P.B pour eviter  sqrt(negatif)' */
      dc_microgrid_6_1_sm_circuit_B.SaturationAjoutPBpourevitersq_h =
        dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpourevitersq_d;
    } else if (dc_microgrid_6_1_sm_circuit_B.Switch_b <
               dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpourevitersq_h) {
      /* Saturate: '<S37>/Saturation Ajout P.B pour eviter  sqrt(negatif)' */
      dc_microgrid_6_1_sm_circuit_B.SaturationAjoutPBpourevitersq_h =
        dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpourevitersq_h;
    } else {
      /* Saturate: '<S37>/Saturation Ajout P.B pour eviter  sqrt(negatif)' */
      dc_microgrid_6_1_sm_circuit_B.SaturationAjoutPBpourevitersq_h =
        dc_microgrid_6_1_sm_circuit_B.Switch_b;
    }

    /* End of Saturate: '<S37>/Saturation Ajout P.B pour eviter  sqrt(negatif)' */

    /* Sqrt: '<S37>/Sqrt' */
    dc_microgrid_6_1_sm_circuit_B.Sqrt_e = sqrt
      (dc_microgrid_6_1_sm_circuit_B.SaturationAjoutPBpourevitersq_h);

    /* Product: '<S34>/Product' */
    dc_microgrid_6_1_sm_circuit_B.Product_er =
      dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_c0 *
      dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_c0;

    /* DiscreteIntegrator: '<S44>/Integ4' */
    if (dc_microgrid_6_1_sm_circuit_DW.Integ4_SYSTEM_ENABLE_g != 0) {
      /* DiscreteIntegrator: '<S44>/Integ4' */
      dc_microgrid_6_1_sm_circuit_B.Integ4_b =
        dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE_e;
    } else {
      /* DiscreteIntegrator: '<S44>/Integ4' */
      dc_microgrid_6_1_sm_circuit_B.Integ4_b =
        dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE_e +
        dc_microgrid_6_1_sm_circuit_P.Integ4_gainval_b4 *
        dc_microgrid_6_1_sm_circuit_B.Product_er;
    }

    /* End of DiscreteIntegrator: '<S44>/Integ4' */

    /* S-Function (discreteVariableTransportDelay): '<S45>/S-Function ' incorporates:
     *  Constant: '<S44>/K1'
     */
    /* S-Function block: <S45>/S-Function  */
    {
      int_T indDelayed;
      int_T discreteDelay;

      /* Input present value(s) */
      ((real_T *)dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK_g.uBuffers)
        [dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_g.indEnd] =
        dc_microgrid_6_1_sm_circuit_B.Integ4_b;

      /* Calculate delayed index */
      discreteDelay =
        (int_T)floor((dc_microgrid_6_1_sm_circuit_P.K1_Value_e2/0.0001) + 0.5);
      if (discreteDelay >
          dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_g.maxDiscrDelay)
        discreteDelay =
          dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_g.maxDiscrDelay;
      indDelayed = dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_g.indEnd -
        ((discreteDelay > 0) ? discreteDelay : 0);
      if (indDelayed < 0) {
        if (dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_g.indBeg == 0 )
          indDelayed = 0;
        else
          indDelayed += dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_g.bufSz;
      }

      /* Output past value(s) */
      dc_microgrid_6_1_sm_circuit_B.SFunction_j = ((real_T *)
        dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK_g.uBuffers)[indDelayed];
    }

    /* UnitDelay: '<S44>/Unit Delay' */
    dc_microgrid_6_1_sm_circuit_B.UnitDelay_o =
      dc_microgrid_6_1_sm_circuit_DW.UnitDelay_DSTATE_n;

    /* Step: '<S44>/Step' */
    u = dc_microgrid_6_1_sm_circuit_M->Timing.t[1];
    Bias = 1.0 / dc_microgrid_6_1_sm_circuit_P.Vab1_Freq;
    if (u < Bias) {
      /* Step: '<S44>/Step' */
      dc_microgrid_6_1_sm_circuit_B.Step_m =
        dc_microgrid_6_1_sm_circuit_P.Step_Y0_n;
    } else {
      /* Step: '<S44>/Step' */
      dc_microgrid_6_1_sm_circuit_B.Step_m =
        dc_microgrid_6_1_sm_circuit_P.Step_YFinal_c;
    }

    /* End of Step: '<S44>/Step' */

    /* Switch: '<S44>/Switch' */
    if (dc_microgrid_6_1_sm_circuit_B.Step_m >=
        dc_microgrid_6_1_sm_circuit_P.Switch_Threshold_f) {
      /* Gain: '<S44>/Gain' */
      dc_microgrid_6_1_sm_circuit_B.Gain_j =
        dc_microgrid_6_1_sm_circuit_P.Gain_Gain_i *
        dc_microgrid_6_1_sm_circuit_B.UnitDelay_o;

      /* Gain: '<S44>/Gain1' */
      dc_microgrid_6_1_sm_circuit_B.Gain1_c =
        dc_microgrid_6_1_sm_circuit_P.Gain1_Gain *
        dc_microgrid_6_1_sm_circuit_B.Product_er;

      /* Sum: '<S44>/Sum1' */
      dc_microgrid_6_1_sm_circuit_B.Correction_b =
        dc_microgrid_6_1_sm_circuit_B.Gain1_c -
        dc_microgrid_6_1_sm_circuit_B.Gain_j;

      /* Sum: '<S44>/Sum7' */
      dc_microgrid_6_1_sm_circuit_B.Sum7_m =
        dc_microgrid_6_1_sm_circuit_B.Integ4_b -
        dc_microgrid_6_1_sm_circuit_B.SFunction_j;

      /* Product: '<S44>/Product' incorporates:
       *  Constant: '<S44>/K2'
       */
      dc_microgrid_6_1_sm_circuit_B.Meanvalue_d =
        dc_microgrid_6_1_sm_circuit_B.Sum7_m *
        dc_microgrid_6_1_sm_circuit_P.Vab1_Freq;

      /* Sum: '<S44>/Sum5' */
      dc_microgrid_6_1_sm_circuit_B.Sum5_m =
        dc_microgrid_6_1_sm_circuit_B.Meanvalue_d +
        dc_microgrid_6_1_sm_circuit_B.Correction_b;

      /* Switch: '<S44>/Switch' */
      dc_microgrid_6_1_sm_circuit_B.Switch_a =
        dc_microgrid_6_1_sm_circuit_B.Sum5_m;
    } else {
      /* Switch: '<S44>/Switch' incorporates:
       *  Constant: '<S44>/Constant'
       */
      dc_microgrid_6_1_sm_circuit_B.Switch_a =
        dc_microgrid_6_1_sm_circuit_P.Vab1_Mag_Init *
        dc_microgrid_6_1_sm_circuit_P.Vab1_Mag_Init;
    }

    /* End of Switch: '<S44>/Switch' */

    /* Saturate: '<S34>/Saturation Ajout P.B pour eviter  sqrt(negatif)' */
    if (dc_microgrid_6_1_sm_circuit_B.Switch_a >
        dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpourevitersq_f) {
      /* Saturate: '<S34>/Saturation Ajout P.B pour eviter  sqrt(negatif)' */
      dc_microgrid_6_1_sm_circuit_B.SaturationAjoutPBpourevitersq_j =
        dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpourevitersq_f;
    } else if (dc_microgrid_6_1_sm_circuit_B.Switch_a <
               dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpourevitersq_m) {
      /* Saturate: '<S34>/Saturation Ajout P.B pour eviter  sqrt(negatif)' */
      dc_microgrid_6_1_sm_circuit_B.SaturationAjoutPBpourevitersq_j =
        dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpourevitersq_m;
    } else {
      /* Saturate: '<S34>/Saturation Ajout P.B pour eviter  sqrt(negatif)' */
      dc_microgrid_6_1_sm_circuit_B.SaturationAjoutPBpourevitersq_j =
        dc_microgrid_6_1_sm_circuit_B.Switch_a;
    }

    /* End of Saturate: '<S34>/Saturation Ajout P.B pour eviter  sqrt(negatif)' */

    /* Sqrt: '<S34>/Sqrt' */
    dc_microgrid_6_1_sm_circuit_B.Sqrt_b = sqrt
      (dc_microgrid_6_1_sm_circuit_B.SaturationAjoutPBpourevitersq_j);

    /* Product: '<S35>/Product' */
    dc_microgrid_6_1_sm_circuit_B.Product_k =
      dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_a *
      dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_a;

    /* DiscreteIntegrator: '<S46>/Integ4' */
    if (dc_microgrid_6_1_sm_circuit_DW.Integ4_SYSTEM_ENABLE_bk != 0) {
      /* DiscreteIntegrator: '<S46>/Integ4' */
      dc_microgrid_6_1_sm_circuit_B.Integ4_d =
        dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE_l;
    } else {
      /* DiscreteIntegrator: '<S46>/Integ4' */
      dc_microgrid_6_1_sm_circuit_B.Integ4_d =
        dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE_l +
        dc_microgrid_6_1_sm_circuit_P.Integ4_gainval_n *
        dc_microgrid_6_1_sm_circuit_B.Product_k;
    }

    /* End of DiscreteIntegrator: '<S46>/Integ4' */

    /* S-Function (discreteVariableTransportDelay): '<S47>/S-Function ' incorporates:
     *  Constant: '<S46>/K1'
     */
    /* S-Function block: <S47>/S-Function  */
    {
      int_T indDelayed;
      int_T discreteDelay;

      /* Input present value(s) */
      ((real_T *)dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK_i.uBuffers)
        [dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_ka.indEnd] =
        dc_microgrid_6_1_sm_circuit_B.Integ4_d;

      /* Calculate delayed index */
      discreteDelay =
        (int_T)floor((dc_microgrid_6_1_sm_circuit_P.K1_Value_a/0.0001) + 0.5);
      if (discreteDelay >
          dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_ka.maxDiscrDelay)
        discreteDelay =
          dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_ka.maxDiscrDelay;
      indDelayed = dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_ka.indEnd -
        ((discreteDelay > 0) ? discreteDelay : 0);
      if (indDelayed < 0) {
        if (dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_ka.indBeg == 0 )
          indDelayed = 0;
        else
          indDelayed += dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_ka.bufSz;
      }

      /* Output past value(s) */
      dc_microgrid_6_1_sm_circuit_B.SFunction_k = ((real_T *)
        dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK_i.uBuffers)[indDelayed];
    }

    /* UnitDelay: '<S46>/Unit Delay' */
    dc_microgrid_6_1_sm_circuit_B.UnitDelay_n =
      dc_microgrid_6_1_sm_circuit_DW.UnitDelay_DSTATE_h;

    /* Step: '<S46>/Step' */
    u = dc_microgrid_6_1_sm_circuit_M->Timing.t[1];
    Bias = 1.0 / dc_microgrid_6_1_sm_circuit_P.Vab2_Freq;
    if (u < Bias) {
      /* Step: '<S46>/Step' */
      dc_microgrid_6_1_sm_circuit_B.Step_k =
        dc_microgrid_6_1_sm_circuit_P.Step_Y0_iz;
    } else {
      /* Step: '<S46>/Step' */
      dc_microgrid_6_1_sm_circuit_B.Step_k =
        dc_microgrid_6_1_sm_circuit_P.Step_YFinal_cj;
    }

    /* End of Step: '<S46>/Step' */

    /* Switch: '<S46>/Switch' */
    if (dc_microgrid_6_1_sm_circuit_B.Step_k >=
        dc_microgrid_6_1_sm_circuit_P.Switch_Threshold_n) {
      /* Gain: '<S46>/Gain' */
      dc_microgrid_6_1_sm_circuit_B.Gain_bd =
        dc_microgrid_6_1_sm_circuit_P.Gain_Gain_h *
        dc_microgrid_6_1_sm_circuit_B.UnitDelay_n;

      /* Gain: '<S46>/Gain1' */
      dc_microgrid_6_1_sm_circuit_B.Gain1_e =
        dc_microgrid_6_1_sm_circuit_P.Gain1_Gain_n *
        dc_microgrid_6_1_sm_circuit_B.Product_k;

      /* Sum: '<S46>/Sum1' */
      dc_microgrid_6_1_sm_circuit_B.Correction_h =
        dc_microgrid_6_1_sm_circuit_B.Gain1_e -
        dc_microgrid_6_1_sm_circuit_B.Gain_bd;

      /* Sum: '<S46>/Sum7' */
      dc_microgrid_6_1_sm_circuit_B.Sum7_b =
        dc_microgrid_6_1_sm_circuit_B.Integ4_d -
        dc_microgrid_6_1_sm_circuit_B.SFunction_k;

      /* Product: '<S46>/Product' incorporates:
       *  Constant: '<S46>/K2'
       */
      dc_microgrid_6_1_sm_circuit_B.Meanvalue_n =
        dc_microgrid_6_1_sm_circuit_B.Sum7_b *
        dc_microgrid_6_1_sm_circuit_P.Vab2_Freq;

      /* Sum: '<S46>/Sum5' */
      dc_microgrid_6_1_sm_circuit_B.Sum5_a =
        dc_microgrid_6_1_sm_circuit_B.Meanvalue_n +
        dc_microgrid_6_1_sm_circuit_B.Correction_h;

      /* Switch: '<S46>/Switch' */
      dc_microgrid_6_1_sm_circuit_B.Switch_j =
        dc_microgrid_6_1_sm_circuit_B.Sum5_a;
    } else {
      /* Switch: '<S46>/Switch' incorporates:
       *  Constant: '<S46>/Constant'
       */
      dc_microgrid_6_1_sm_circuit_B.Switch_j =
        dc_microgrid_6_1_sm_circuit_P.Vab2_Mag_Init *
        dc_microgrid_6_1_sm_circuit_P.Vab2_Mag_Init;
    }

    /* End of Switch: '<S46>/Switch' */

    /* Saturate: '<S35>/Saturation Ajout P.B pour eviter  sqrt(negatif)' */
    if (dc_microgrid_6_1_sm_circuit_B.Switch_j >
        dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpoureviters_oi) {
      /* Saturate: '<S35>/Saturation Ajout P.B pour eviter  sqrt(negatif)' */
      dc_microgrid_6_1_sm_circuit_B.SaturationAjoutPBpourevitersq_n =
        dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpoureviters_oi;
    } else if (dc_microgrid_6_1_sm_circuit_B.Switch_j <
               dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpourevitersq_c) {
      /* Saturate: '<S35>/Saturation Ajout P.B pour eviter  sqrt(negatif)' */
      dc_microgrid_6_1_sm_circuit_B.SaturationAjoutPBpourevitersq_n =
        dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpourevitersq_c;
    } else {
      /* Saturate: '<S35>/Saturation Ajout P.B pour eviter  sqrt(negatif)' */
      dc_microgrid_6_1_sm_circuit_B.SaturationAjoutPBpourevitersq_n =
        dc_microgrid_6_1_sm_circuit_B.Switch_j;
    }

    /* End of Saturate: '<S35>/Saturation Ajout P.B pour eviter  sqrt(negatif)' */

    /* Sqrt: '<S35>/Sqrt' */
    dc_microgrid_6_1_sm_circuit_B.Sqrt_d = sqrt
      (dc_microgrid_6_1_sm_circuit_B.SaturationAjoutPBpourevitersq_n);

    /* Switch: '<S28>/Switch2' incorporates:
     *  Constant: '<S28>/1 for max load, 0 for min'
     */
    if (dc_microgrid_6_1_sm_circuit_P.uformaxload0formin_Value >
        dc_microgrid_6_1_sm_circuit_P.Switch2_Threshold_b) {
      /* Switch: '<S28>/Switch2' incorporates:
       *  Constant: '<S28>/OP_max1'
       */
      dc_microgrid_6_1_sm_circuit_B.Switch2 =
        dc_microgrid_6_1_sm_circuit_P.OP_max1_Value_g;
    } else {
      /* Switch: '<S28>/Switch2' incorporates:
       *  Constant: '<S28>/OP_min1'
       */
      dc_microgrid_6_1_sm_circuit_B.Switch2 =
        dc_microgrid_6_1_sm_circuit_P.OP_min1_Value_g;
    }

    /* End of Switch: '<S28>/Switch2' */
    /* DigitalClock: '<S25>/t' */
    dc_microgrid_6_1_sm_circuit_B.t = dc_microgrid_6_1_sm_circuit_M->Timing.t[1];

    /* DigitalClock: '<S30>/t' */
    dc_microgrid_6_1_sm_circuit_B.t_o = dc_microgrid_6_1_sm_circuit_M->Timing.t
      [1];

    /* Switch: '<S25>/Switch' incorporates:
     *  Constant: '<S25>/Constant1'
     *  Constant: '<S30>/Constant1'
     *  Switch: '<S30>/Switch2'
     */
    if (dc_microgrid_6_1_sm_circuit_P.DiscretePWMGenerator1_Internal >
        dc_microgrid_6_1_sm_circuit_P.Switch_Threshold_a) {
      /* Gain: '<S25>/Gain2' incorporates:
       *  Constant: '<S25>/m3'
       */
      dc_microgrid_6_1_sm_circuit_B.Gain2 =
        dc_microgrid_6_1_sm_circuit_P.Gain2_Gain *
        dc_microgrid_6_1_sm_circuit_P.m3_Value;

      /* Gain: '<S25>/Gain' */
      dc_microgrid_6_1_sm_circuit_B.Gain_d =
        dc_microgrid_6_1_sm_circuit_P.Gain_Gain *
        dc_microgrid_6_1_sm_circuit_B.t;

      /* Sum: '<S25>/Sum' incorporates:
       *  Constant: '<S25>/Constant'
       */
      dc_microgrid_6_1_sm_circuit_B.Sum_o[0] =
        (dc_microgrid_6_1_sm_circuit_B.Gain_d +
         dc_microgrid_6_1_sm_circuit_B.Gain2) +
        dc_microgrid_6_1_sm_circuit_P.Constant_Value[0];
      dc_microgrid_6_1_sm_circuit_B.Sum_o[1] =
        (dc_microgrid_6_1_sm_circuit_B.Gain_d +
         dc_microgrid_6_1_sm_circuit_B.Gain2) +
        dc_microgrid_6_1_sm_circuit_P.Constant_Value[1];
      dc_microgrid_6_1_sm_circuit_B.Sum_o[2] =
        (dc_microgrid_6_1_sm_circuit_B.Gain_d +
         dc_microgrid_6_1_sm_circuit_B.Gain2) +
        dc_microgrid_6_1_sm_circuit_P.Constant_Value[2];

      /* Trigonometry: '<S25>/Trigonometric Function' */
      dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction_i[0] = sin
        (dc_microgrid_6_1_sm_circuit_B.Sum_o[0]);
      dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction_i[1] = sin
        (dc_microgrid_6_1_sm_circuit_B.Sum_o[1]);
      dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction_i[2] = sin
        (dc_microgrid_6_1_sm_circuit_B.Sum_o[2]);

      /* Product: '<S25>/Product' incorporates:
       *  Constant: '<S25>/m4'
       */
      dc_microgrid_6_1_sm_circuit_B.Product_m[0] =
        dc_microgrid_6_1_sm_circuit_P.m4_Value *
        dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction_i[0];
      dc_microgrid_6_1_sm_circuit_B.Product_m[1] =
        dc_microgrid_6_1_sm_circuit_P.m4_Value *
        dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction_i[1];
      dc_microgrid_6_1_sm_circuit_B.Product_m[2] =
        dc_microgrid_6_1_sm_circuit_P.m4_Value *
        dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction_i[2];

      /* Switch: '<S25>/Switch' */
      dc_microgrid_6_1_sm_circuit_B.Switch_l[0] =
        dc_microgrid_6_1_sm_circuit_B.Product_m[0];
      dc_microgrid_6_1_sm_circuit_B.Switch_l[1] =
        dc_microgrid_6_1_sm_circuit_B.Product_m[1];
      dc_microgrid_6_1_sm_circuit_B.Switch_l[2] =
        dc_microgrid_6_1_sm_circuit_B.Product_m[2];
    } else {
      if (dc_microgrid_6_1_sm_circuit_P.max_min >
          dc_microgrid_6_1_sm_circuit_P.Switch2_Threshold) {
        /* Switch: '<S30>/Switch2' incorporates:
         *  Constant: '<S30>/OP_max1'
         */
        dc_microgrid_6_1_sm_circuit_B.Switch2_c =
          dc_microgrid_6_1_sm_circuit_P.OP_max1_Value;
      } else {
        /* Switch: '<S30>/Switch2' incorporates:
         *  Constant: '<S30>/OP_min1'
         */
        dc_microgrid_6_1_sm_circuit_B.Switch2_c =
          dc_microgrid_6_1_sm_circuit_P.OP_min1_Value;
      }

      /* Gain: '<S30>/Deg->Rad' */
      dc_microgrid_6_1_sm_circuit_B.DegRad =
        dc_microgrid_6_1_sm_circuit_P.DegRad_Gain *
        dc_microgrid_6_1_sm_circuit_B.Switch2_c;

      /* Product: '<S30>/Product7' incorporates:
       *  Constant: '<S30>/Freq1'
       *  Constant: '<S30>/Freq2'
       */
      dc_microgrid_6_1_sm_circuit_B.Product7_d =
        dc_microgrid_6_1_sm_circuit_P.Fnom * dc_microgrid_6_1_sm_circuit_B.t_o *
        dc_microgrid_6_1_sm_circuit_P.Freq2_Value;

      /* Sum: '<S30>/Sum' */
      dc_microgrid_6_1_sm_circuit_B.Sum_k =
        dc_microgrid_6_1_sm_circuit_B.Product7_d +
        dc_microgrid_6_1_sm_circuit_B.DegRad;

      /* Math: '<S30>/Math Function' incorporates:
       *  Constant: '<S30>/Constant2'
       */
      dc_microgrid_6_1_sm_circuit_B.MathFunction_h = rt_modd_snf
        (dc_microgrid_6_1_sm_circuit_B.Sum_k,
         dc_microgrid_6_1_sm_circuit_P.Constant2_Value);

      /* Trigonometry: '<S30>/Trigonometric Function' */
      dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction = sin
        (dc_microgrid_6_1_sm_circuit_B.MathFunction_h);

      /* Product: '<S29>/Product2' incorporates:
       *  Constant: '<S29>/K2'
       */
      dc_microgrid_6_1_sm_circuit_B.Product2 =
        dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction *
        dc_microgrid_6_1_sm_circuit_P.K2_Value;

      /* Trigonometry: '<S30>/Trigonometric Function1' */
      dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction1 = cos
        (dc_microgrid_6_1_sm_circuit_B.MathFunction_h);

      /* Product: '<S29>/Product3' incorporates:
       *  Constant: '<S29>/K1'
       */
      dc_microgrid_6_1_sm_circuit_B.Product3_e =
        dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction1 *
        dc_microgrid_6_1_sm_circuit_P.K1_Value;

      /* Sum: '<S29>/Sum1' */
      dc_microgrid_6_1_sm_circuit_B.coswt2pi3 =
        dc_microgrid_6_1_sm_circuit_B.Product2 -
        dc_microgrid_6_1_sm_circuit_B.Product3_e;

      /* Sum: '<S29>/Sum3' */
      Bias = 0.0;

      /* Sum: '<S29>/Sum3' */
      dc_microgrid_6_1_sm_circuit_B.coswt2pi3_j = (Bias -
        dc_microgrid_6_1_sm_circuit_B.coswt2pi3) -
        dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction1;

      /* Product: '<S29>/Product1' incorporates:
       *  Constant: '<S29>/K2'
       */
      dc_microgrid_6_1_sm_circuit_B.Product1_n =
        dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction1 *
        dc_microgrid_6_1_sm_circuit_P.K2_Value;

      /* Product: '<S29>/Product' incorporates:
       *  Constant: '<S29>/K1'
       */
      dc_microgrid_6_1_sm_circuit_B.Product_n =
        dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction *
        dc_microgrid_6_1_sm_circuit_P.K1_Value;

      /* Sum: '<S29>/Sum' */
      Bias = 0.0;

      /* Sum: '<S29>/Sum' */
      dc_microgrid_6_1_sm_circuit_B.sinwt2pi3 = (Bias -
        dc_microgrid_6_1_sm_circuit_B.Product_n) -
        dc_microgrid_6_1_sm_circuit_B.Product1_n;

      /* Sum: '<S29>/Sum2' */
      Bias = 0.0;

      /* Sum: '<S29>/Sum2' */
      dc_microgrid_6_1_sm_circuit_B.sinwt2pi3_p = (Bias -
        dc_microgrid_6_1_sm_circuit_B.sinwt2pi3) -
        dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction;

      /* Fcn: '<S29>/Fcn2' */
      dc_microgrid_6_1_sm_circuit_B.Fcn2 = 1.0 *
        dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction;

      /* Product: '<S26>/Product' */
      dc_microgrid_6_1_sm_circuit_B.Product_a =
        dc_microgrid_6_1_sm_circuit_B.Switch2 *
        dc_microgrid_6_1_sm_circuit_B.Fcn2;

      /* Fcn: '<S29>/Fcn4' */
      dc_microgrid_6_1_sm_circuit_B.Fcn4 = 1.0 *
        dc_microgrid_6_1_sm_circuit_B.sinwt2pi3;

      /* Product: '<S26>/Product1' */
      dc_microgrid_6_1_sm_circuit_B.Product1_j =
        dc_microgrid_6_1_sm_circuit_B.Switch2 *
        dc_microgrid_6_1_sm_circuit_B.Fcn4;

      /* Fcn: '<S29>/Fcn5' */
      dc_microgrid_6_1_sm_circuit_B.Fcn5 = 1.0 *
        dc_microgrid_6_1_sm_circuit_B.sinwt2pi3_p;

      /* Product: '<S26>/Product2' */
      dc_microgrid_6_1_sm_circuit_B.Product2_h =
        dc_microgrid_6_1_sm_circuit_B.Switch2 *
        dc_microgrid_6_1_sm_circuit_B.Fcn5;

      /* Switch: '<S25>/Switch' */
      dc_microgrid_6_1_sm_circuit_B.Switch_l[0] =
        dc_microgrid_6_1_sm_circuit_B.Product_a;
      dc_microgrid_6_1_sm_circuit_B.Switch_l[1] =
        dc_microgrid_6_1_sm_circuit_B.Product1_j;
      dc_microgrid_6_1_sm_circuit_B.Switch_l[2] =
        dc_microgrid_6_1_sm_circuit_B.Product2_h;
    }

    /* End of Switch: '<S25>/Switch' */
  }

  /* Clock: '<S27>/Clock' */
  dc_microgrid_6_1_sm_circuit_B.Clock_j =
    dc_microgrid_6_1_sm_circuit_M->Timing.t[0];

  /* Sum: '<S27>/Sum' incorporates:
   *  S-Function (sfun_tstart): '<S27>/startTime'
   */
  dc_microgrid_6_1_sm_circuit_B.Sum_b = dc_microgrid_6_1_sm_circuit_B.Clock_j -
    (0.0);

  /* Math: '<S27>/Math Function' incorporates:
   *  Constant: '<S27>/Constant'
   */
  dc_microgrid_6_1_sm_circuit_B.MathFunction = rt_remd_snf
    (dc_microgrid_6_1_sm_circuit_B.Sum_b,
     dc_microgrid_6_1_sm_circuit_P.Constant_Value_gx);

  /* Lookup_n-D: '<S27>/Look-Up Table1' incorporates:
   *  Math: '<S27>/Math Function'
   */
  dc_microgrid_6_1_sm_circuit_B.LookUpTable1 = look1_binlxpw
    (dc_microgrid_6_1_sm_circuit_B.MathFunction,
     dc_microgrid_6_1_sm_circuit_P.LookUpTable1_bp01Data,
     dc_microgrid_6_1_sm_circuit_P.Triangle_rep_seq_y, 3U);

  /* SignalConversion: '<S27>/Output' */
  dc_microgrid_6_1_sm_circuit_B.Output =
    dc_microgrid_6_1_sm_circuit_B.LookUpTable1;

  /* RelationalOperator: '<S25>/Relational Operator' */
  dc_microgrid_6_1_sm_circuit_B.RelationalOperator_f[0] =
    (dc_microgrid_6_1_sm_circuit_B.Switch_l[0] >=
     dc_microgrid_6_1_sm_circuit_B.Output);
  dc_microgrid_6_1_sm_circuit_B.RelationalOperator_f[1] =
    (dc_microgrid_6_1_sm_circuit_B.Switch_l[1] >=
     dc_microgrid_6_1_sm_circuit_B.Output);
  dc_microgrid_6_1_sm_circuit_B.RelationalOperator_f[2] =
    (dc_microgrid_6_1_sm_circuit_B.Switch_l[2] >=
     dc_microgrid_6_1_sm_circuit_B.Output);

  /* DataTypeConversion: '<S25>/Data Type  Conversion1' */
  dc_microgrid_6_1_sm_circuit_B.DataTypeConversion1[0] =
    dc_microgrid_6_1_sm_circuit_B.RelationalOperator_f[0];
  dc_microgrid_6_1_sm_circuit_B.DataTypeConversion1[1] =
    dc_microgrid_6_1_sm_circuit_B.RelationalOperator_f[1];
  dc_microgrid_6_1_sm_circuit_B.DataTypeConversion1[2] =
    dc_microgrid_6_1_sm_circuit_B.RelationalOperator_f[2];

  /* Logic: '<S25>/BL4' */
  dc_microgrid_6_1_sm_circuit_B.BL4[0] =
    !dc_microgrid_6_1_sm_circuit_B.DataTypeConversion1[0];
  dc_microgrid_6_1_sm_circuit_B.BL4[1] =
    !dc_microgrid_6_1_sm_circuit_B.DataTypeConversion1[1];
  dc_microgrid_6_1_sm_circuit_B.BL4[2] =
    !dc_microgrid_6_1_sm_circuit_B.DataTypeConversion1[2];
  if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
    /* Gain: '<S25>/Gain3' */
    dc_microgrid_6_1_sm_circuit_B.Gain3[0] =
      dc_microgrid_6_1_sm_circuit_P.Gain3_Gain *
      dc_microgrid_6_1_sm_circuit_B.Switch_l[0];
    dc_microgrid_6_1_sm_circuit_B.Gain3[1] =
      dc_microgrid_6_1_sm_circuit_P.Gain3_Gain *
      dc_microgrid_6_1_sm_circuit_B.Switch_l[1];
    dc_microgrid_6_1_sm_circuit_B.Gain3[2] =
      dc_microgrid_6_1_sm_circuit_P.Gain3_Gain *
      dc_microgrid_6_1_sm_circuit_B.Switch_l[2];
  }

  /* RelationalOperator: '<S25>/Relational Operator1' */
  dc_microgrid_6_1_sm_circuit_B.RelationalOperator1[0] =
    (dc_microgrid_6_1_sm_circuit_B.Gain3[0] >=
     dc_microgrid_6_1_sm_circuit_B.Output);
  dc_microgrid_6_1_sm_circuit_B.RelationalOperator1[1] =
    (dc_microgrid_6_1_sm_circuit_B.Gain3[1] >=
     dc_microgrid_6_1_sm_circuit_B.Output);
  dc_microgrid_6_1_sm_circuit_B.RelationalOperator1[2] =
    (dc_microgrid_6_1_sm_circuit_B.Gain3[2] >=
     dc_microgrid_6_1_sm_circuit_B.Output);

  /* DataTypeConversion: '<S25>/Data Type  Conversion2' */
  dc_microgrid_6_1_sm_circuit_B.DataTypeConversion2[0] =
    dc_microgrid_6_1_sm_circuit_B.RelationalOperator1[0];
  dc_microgrid_6_1_sm_circuit_B.DataTypeConversion2[1] =
    dc_microgrid_6_1_sm_circuit_B.RelationalOperator1[1];
  dc_microgrid_6_1_sm_circuit_B.DataTypeConversion2[2] =
    dc_microgrid_6_1_sm_circuit_B.RelationalOperator1[2];

  /* Logic: '<S25>/BL5' */
  dc_microgrid_6_1_sm_circuit_B.BL5[0] =
    !dc_microgrid_6_1_sm_circuit_B.DataTypeConversion2[0];
  dc_microgrid_6_1_sm_circuit_B.BL5[1] =
    !dc_microgrid_6_1_sm_circuit_B.DataTypeConversion2[1];
  dc_microgrid_6_1_sm_circuit_B.BL5[2] =
    !dc_microgrid_6_1_sm_circuit_B.DataTypeConversion2[2];

  /* DataTypeConversion: '<S25>/Data Type  Conversion' */
  dc_microgrid_6_1_sm_circuit_B.DataTypeConversion_i[0] = (real_T)
    dc_microgrid_6_1_sm_circuit_B.DataTypeConversion1[0];
  dc_microgrid_6_1_sm_circuit_B.DataTypeConversion_i[1] = (real_T)
    dc_microgrid_6_1_sm_circuit_B.BL4[0];
  dc_microgrid_6_1_sm_circuit_B.DataTypeConversion_i[2] = (real_T)
    dc_microgrid_6_1_sm_circuit_B.DataTypeConversion1[1];
  dc_microgrid_6_1_sm_circuit_B.DataTypeConversion_i[3] = (real_T)
    dc_microgrid_6_1_sm_circuit_B.BL4[1];
  dc_microgrid_6_1_sm_circuit_B.DataTypeConversion_i[4] = (real_T)
    dc_microgrid_6_1_sm_circuit_B.DataTypeConversion1[2];
  dc_microgrid_6_1_sm_circuit_B.DataTypeConversion_i[5] = (real_T)
    dc_microgrid_6_1_sm_circuit_B.BL4[2];
  if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
  }
}

/* Model update function */
void dc_microgrid_6_1_sm_circuit_update(void)
{
  int32_T i;
  int_T idxDelay;
  int_T idxWidth;
  if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
    /* Update for Memory: '<S1>/S-Function' */
    dc_microgrid_6_1_sm_circuit_DW.SFunction_PreviousInput =
      dc_microgrid_6_1_sm_circuit_B.Sum;

    /* Update for Delay: '<S3>/Delay1' */
    idxDelay = 0;
    idxWidth = 0;
    dc_microgrid_6_1_sm_circuit_DW.Delay1_DSTATE[idxDelay + idxWidth] =
      dc_microgrid_6_1_sm_circuit_DW.Delay1_DSTATE[(idxDelay + 1) + idxWidth];
    dc_microgrid_6_1_sm_circuit_DW.Delay1_DSTATE[1 + 0] =
      dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_pt;

    /* Update for S-Function (sfun_spssw_discc): '<S4>/State-Space' incorporates:
     *  Constant: '<S31>/Constant'
     */

    /* S-Function block: <S4>/State-Space */
    {
      const real_T *As = (real_T*)
        dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.AS;
      const real_T *Bs = (real_T*)
        dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.BS;
      real_T *xtmp = (real_T*)
        dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.XTMP;
      real_T accum;

      /* Calculate new states... */
      {
        int_T i1;
        real_T *xd = &dc_microgrid_6_1_sm_circuit_DW.StateSpace_DSTATE[0];
        for (i1=0; i1 < 6; i1++) {
          accum = 0.0;

          {
            int_T i2;
            real_T *xd = &dc_microgrid_6_1_sm_circuit_DW.StateSpace_DSTATE[0];
            for (i2=0; i2 < 6; i2++) {
              accum += *(As++) * xd[i2];
            }
          }

          {
            int_T i2;
            const real_T *u0 = &dc_microgrid_6_1_sm_circuit_P.Constant_Value_g[0];
            for (i2=0; i2 < 6; i2++) {
              accum += *(Bs++) * u0[i2];
            }

            accum += *(Bs++) * dc_microgrid_6_1_sm_circuit_B.Product5;
            accum += *(Bs++) * dc_microgrid_6_1_sm_circuit_B.Product7;
            accum += *(Bs++) * dc_microgrid_6_1_sm_circuit_B.Product8;
            accum += *(Bs++) * dc_microgrid_6_1_sm_circuit_B.Divide1;
          }

          xtmp[i1] = accum;
        }
      }

      {
        int_T i1;
        real_T *xd = &dc_microgrid_6_1_sm_circuit_DW.StateSpace_DSTATE[0];
        for (i1=0; i1 < 6; i1++) {
          xd[i1] = xtmp[i1];
        }
      }

      {
        int_T *gState = (int_T*)
          dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.G_STATE;

        /* Store switch gates values for next step */
        {
          int_T i1;
          const real_T *u1 = &dc_microgrid_6_1_sm_circuit_B.DataTypeConversion[0];
          for (i1=0; i1 < 6; i1++) {
            *(gState++) = (int_T) u1[i1];
          }
        }
      }
    }
  }

  /* Update for TransportDelay: '<S66>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_PWORK.TUbufferPtrs[0];
    real_T simTime = dc_microgrid_6_1_sm_circuit_M->Timing.t[0];
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Head[0] =
      ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Head[0] <
        (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.CircularBufSize[0]-
         1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Head[0]+1) :
       0);
    if (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Head[0] ==
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Tail[0]) {
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Tail[0] =
        ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Tail[0] <
          (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.CircularBufSize[0]
           -1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Tail[0]+1)
         : 0);
    }

    (*uBuffer +
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.CircularBufSize[0])
      [dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Head[0]] = simTime;
    (*uBuffer++)[dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Head[0]] =
      dc_microgrid_6_1_sm_circuit_B.integrator[0];
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Head[1] =
      ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Head[1] <
        (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.CircularBufSize[1]-
         1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Head[1]+1) :
       0);
    if (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Head[1] ==
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Tail[1]) {
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Tail[1] =
        ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Tail[1] <
          (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.CircularBufSize[1]
           -1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Tail[1]+1)
         : 0);
    }

    (*uBuffer +
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.CircularBufSize[1])
      [dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Head[1]] = simTime;
    (*uBuffer++)[dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Head[1]] =
      dc_microgrid_6_1_sm_circuit_B.integrator[1];
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Head[2] =
      ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Head[2] <
        (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.CircularBufSize[2]-
         1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Head[2]+1) :
       0);
    if (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Head[2] ==
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Tail[2]) {
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Tail[2] =
        ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Tail[2] <
          (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.CircularBufSize[2]
           -1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Tail[2]+1)
         : 0);
    }

    (*uBuffer +
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.CircularBufSize[2])
      [dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Head[2]] = simTime;
    (*uBuffer)[dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Head[2]] =
      dc_microgrid_6_1_sm_circuit_B.integrator[2];
  }

  if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
    /* Update for Memory: '<S66>/Memory' */
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput[0] =
      dc_microgrid_6_1_sm_circuit_B.Switch[0];
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput[1] =
      dc_microgrid_6_1_sm_circuit_B.Switch[1];
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput[2] =
      dc_microgrid_6_1_sm_circuit_B.Switch[2];
  }

  /* Update for TransportDelay: '<S65>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_PWORK_n.TUbufferPtrs[0];
    real_T simTime = dc_microgrid_6_1_sm_circuit_M->Timing.t[0];
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Head[0] =
      ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Head[0] <
        (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.CircularBufSize[0]
         -1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Head[0]+1)
       : 0);
    if (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Head[0] ==
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Tail[0]) {
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Tail[0] =
        ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Tail[0] <
          (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.CircularBufSize[
           0]-1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Tail
                     [0]+1) : 0);
    }

    (*uBuffer +
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.CircularBufSize[0])
      [dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Head[0]] = simTime;
    (*uBuffer++)[dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Head[0]] =
      dc_microgrid_6_1_sm_circuit_B.integrator_p[0];
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Head[1] =
      ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Head[1] <
        (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.CircularBufSize[1]
         -1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Head[1]+1)
       : 0);
    if (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Head[1] ==
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Tail[1]) {
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Tail[1] =
        ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Tail[1] <
          (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.CircularBufSize[
           1]-1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Tail
                     [1]+1) : 0);
    }

    (*uBuffer +
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.CircularBufSize[1])
      [dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Head[1]] = simTime;
    (*uBuffer++)[dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Head[1]] =
      dc_microgrid_6_1_sm_circuit_B.integrator_p[1];
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Head[2] =
      ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Head[2] <
        (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.CircularBufSize[2]
         -1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Head[2]+1)
       : 0);
    if (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Head[2] ==
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Tail[2]) {
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Tail[2] =
        ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Tail[2] <
          (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.CircularBufSize[
           2]-1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Tail
                     [2]+1) : 0);
    }

    (*uBuffer +
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.CircularBufSize[2])
      [dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Head[2]] = simTime;
    (*uBuffer)[dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Head[2]] =
      dc_microgrid_6_1_sm_circuit_B.integrator_p[2];
  }

  if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
    /* Update for Memory: '<S65>/Memory' */
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_d[0] =
      dc_microgrid_6_1_sm_circuit_B.Switch_h[0];
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_d[1] =
      dc_microgrid_6_1_sm_circuit_B.Switch_h[1];
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_d[2] =
      dc_microgrid_6_1_sm_circuit_B.Switch_h[2];
  }

  /* Update for TransportDelay: '<S70>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_PWORK_d.TUbufferPtrs[0];
    real_T simTime = dc_microgrid_6_1_sm_circuit_M->Timing.t[0];
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Head[0] =
      ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Head[0] <
        (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.CircularBufSize[0]
         -1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Head[0]+1)
       : 0);
    if (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Head[0] ==
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Tail[0]) {
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Tail[0] =
        ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Tail[0] <
          (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.CircularBufSize[
           0]-1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Tail
                     [0]+1) : 0);
    }

    (*uBuffer +
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.CircularBufSize[0])
      [dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Head[0]] = simTime;
    (*uBuffer++)[dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Head[0]] =
      dc_microgrid_6_1_sm_circuit_B.integrator_f[0];
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Head[1] =
      ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Head[1] <
        (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.CircularBufSize[1]
         -1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Head[1]+1)
       : 0);
    if (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Head[1] ==
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Tail[1]) {
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Tail[1] =
        ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Tail[1] <
          (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.CircularBufSize[
           1]-1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Tail
                     [1]+1) : 0);
    }

    (*uBuffer +
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.CircularBufSize[1])
      [dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Head[1]] = simTime;
    (*uBuffer++)[dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Head[1]] =
      dc_microgrid_6_1_sm_circuit_B.integrator_f[1];
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Head[2] =
      ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Head[2] <
        (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.CircularBufSize[2]
         -1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Head[2]+1)
       : 0);
    if (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Head[2] ==
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Tail[2]) {
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Tail[2] =
        ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Tail[2] <
          (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.CircularBufSize[
           2]-1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Tail
                     [2]+1) : 0);
    }

    (*uBuffer +
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.CircularBufSize[2])
      [dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Head[2]] = simTime;
    (*uBuffer)[dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Head[2]] =
      dc_microgrid_6_1_sm_circuit_B.integrator_f[2];
  }

  if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
    /* Update for Memory: '<S70>/Memory' */
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_g[0] =
      dc_microgrid_6_1_sm_circuit_B.Switch_k[0];
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_g[1] =
      dc_microgrid_6_1_sm_circuit_B.Switch_k[1];
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_g[2] =
      dc_microgrid_6_1_sm_circuit_B.Switch_k[2];
  }

  /* Update for TransportDelay: '<S69>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_PWORK_j.TUbufferPtrs[0];
    real_T simTime = dc_microgrid_6_1_sm_circuit_M->Timing.t[0];
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Head[0] =
      ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Head[0] <
        (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.CircularBufSize[0]
         -1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Head[0]+1)
       : 0);
    if (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Head[0] ==
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Tail[0]) {
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Tail[0] =
        ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Tail[0] <
          (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.CircularBufSize[
           0]-1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Tail
                     [0]+1) : 0);
    }

    (*uBuffer +
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.CircularBufSize[0])
      [dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Head[0]] = simTime;
    (*uBuffer++)[dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Head[0]] =
      dc_microgrid_6_1_sm_circuit_B.integrator_b[0];
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Head[1] =
      ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Head[1] <
        (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.CircularBufSize[1]
         -1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Head[1]+1)
       : 0);
    if (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Head[1] ==
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Tail[1]) {
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Tail[1] =
        ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Tail[1] <
          (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.CircularBufSize[
           1]-1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Tail
                     [1]+1) : 0);
    }

    (*uBuffer +
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.CircularBufSize[1])
      [dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Head[1]] = simTime;
    (*uBuffer++)[dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Head[1]] =
      dc_microgrid_6_1_sm_circuit_B.integrator_b[1];
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Head[2] =
      ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Head[2] <
        (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.CircularBufSize[2]
         -1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Head[2]+1)
       : 0);
    if (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Head[2] ==
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Tail[2]) {
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Tail[2] =
        ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Tail[2] <
          (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.CircularBufSize[
           2]-1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Tail
                     [2]+1) : 0);
    }

    (*uBuffer +
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.CircularBufSize[2])
      [dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Head[2]] = simTime;
    (*uBuffer)[dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Head[2]] =
      dc_microgrid_6_1_sm_circuit_B.integrator_b[2];
  }

  if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
    /* Update for Memory: '<S69>/Memory' */
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_l[0] =
      dc_microgrid_6_1_sm_circuit_B.Switch_d[0];
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_l[1] =
      dc_microgrid_6_1_sm_circuit_B.Switch_d[1];
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_l[2] =
      dc_microgrid_6_1_sm_circuit_B.Switch_d[2];
  }

  /* Update for Enabled SubSystem: '<S18>/TrueRMS ' incorporates:
   *  EnablePort: '<S72>/Enable'
   */
  if (dc_microgrid_6_1_sm_circuit_DW.TrueRMS_MODE) {
    /* Update for TransportDelay: '<S79>/Transport Delay' */
    {
      real_T **uBuffer = (real_T**)
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_PWORK_f.TUbufferPtrs[0];
      real_T simTime = dc_microgrid_6_1_sm_circuit_M->Timing.t[0];
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_o.Head =
        ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_o.Head <
          (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_o.CircularBufSize
           -1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_o.Head+1)
         : 0);
      if (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_o.Head ==
          dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_o.Tail) {
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_o.Tail =
          ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_o.Tail <
            (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_o.CircularBufSize
             -1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_o.Tail+
                     1) : 0);
      }

      (*uBuffer +
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_o.CircularBufSize)
        [dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_o.Head] = simTime;
      (*uBuffer)[dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_o.Head] =
        dc_microgrid_6_1_sm_circuit_B.integrator_k;
    }

    if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
      /* Update for Memory: '<S79>/Memory' */
      dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_f =
        dc_microgrid_6_1_sm_circuit_B.Switch_cu;
    }
  }

  /* End of Update for SubSystem: '<S18>/TrueRMS ' */

  /* Update for Enabled SubSystem: '<S18>/RMS ' incorporates:
   *  EnablePort: '<S71>/Enable'
   */
  if (dc_microgrid_6_1_sm_circuit_DW.RMS_MODE) {
    /* Update for TransportDelay: '<S77>/Transport Delay' */
    {
      real_T **uBuffer = (real_T**)
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_PWORK_ny.TUbufferPtrs[0];
      real_T simTime = dc_microgrid_6_1_sm_circuit_M->Timing.t[0];
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_ns.Head =
        ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_ns.Head <
          (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_ns.CircularBufSize
           -1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_ns.Head+1)
         : 0);
      if (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_ns.Head ==
          dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_ns.Tail) {
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_ns.Tail =
          ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_ns.Tail <
            (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_ns.CircularBufSize
             -1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_ns.Tail
                     +1) : 0);
      }

      (*uBuffer +
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_ns.CircularBufSize)
        [dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_ns.Head] = simTime;
      (*uBuffer)[dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_ns.Head] =
        dc_microgrid_6_1_sm_circuit_B.integrator_h;
    }

    if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
      /* Update for Memory: '<S77>/Memory' */
      dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_da =
        dc_microgrid_6_1_sm_circuit_B.Switch_k1;
    }

    /* Update for TransportDelay: '<S76>/Transport Delay' */
    {
      real_T **uBuffer = (real_T**)
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_PWORK_nz.TUbufferPtrs[0];
      real_T simTime = dc_microgrid_6_1_sm_circuit_M->Timing.t[0];
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_bl.Head =
        ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_bl.Head <
          (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_bl.CircularBufSize
           -1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_bl.Head+1)
         : 0);
      if (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_bl.Head ==
          dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_bl.Tail) {
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_bl.Tail =
          ((dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_bl.Tail <
            (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_bl.CircularBufSize
             -1)) ? (dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_bl.Tail
                     +1) : 0);
      }

      (*uBuffer +
        dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_bl.CircularBufSize)
        [dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_bl.Head] = simTime;
      (*uBuffer)[dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_bl.Head] =
        dc_microgrid_6_1_sm_circuit_B.integrator_a;
    }

    if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
      /* Update for Memory: '<S76>/Memory' */
      dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_i =
        dc_microgrid_6_1_sm_circuit_B.Switch_o;
    }
  }

  /* End of Update for SubSystem: '<S18>/RMS ' */
  if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
    /* Update for UnitDelay: '<S23>/Unit Delay4' */
    for (i = 0; i < 6; i = i + 1) {
      dc_microgrid_6_1_sm_circuit_DW.UnitDelay4_DSTATE[i] =
        dc_microgrid_6_1_sm_circuit_B.DataTypeConversion_i[i];
    }

    /* End of Update for UnitDelay: '<S23>/Unit Delay4' */

    /* Update for DiscreteIntegrator: '<S48>/Integ4' */
    dc_microgrid_6_1_sm_circuit_DW.Integ4_SYSTEM_ENABLE = 0;
    dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE[0] =
      dc_microgrid_6_1_sm_circuit_B.Integ4[0] +
      dc_microgrid_6_1_sm_circuit_P.Integ4_gainval *
      dc_microgrid_6_1_sm_circuit_B.Product_d[0];
    dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE[1] =
      dc_microgrid_6_1_sm_circuit_B.Integ4[1] +
      dc_microgrid_6_1_sm_circuit_P.Integ4_gainval *
      dc_microgrid_6_1_sm_circuit_B.Product_d[1];
    dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE[2] =
      dc_microgrid_6_1_sm_circuit_B.Integ4[2] +
      dc_microgrid_6_1_sm_circuit_P.Integ4_gainval *
      dc_microgrid_6_1_sm_circuit_B.Product_d[2];

    /* Update for S-Function (discreteVariableTransportDelay): '<S49>/S-Function ' incorporates:
     *  Constant: '<S48>/K1'
     */

    /* S-Function block: <S49>/S-Function  */
    {
      int_T indBeg = dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_k.indBeg;
      int_T indEnd = dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_k.indEnd;
      int_T bufSz = dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_k.bufSz;
      indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
      if (indEnd == indBeg) {
        indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
      }

      dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_k.indBeg = indBeg;
      dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_k.indEnd = indEnd;
    }

    /* Update for UnitDelay: '<S48>/Unit Delay' */
    dc_microgrid_6_1_sm_circuit_DW.UnitDelay_DSTATE[0] =
      dc_microgrid_6_1_sm_circuit_B.Product_d[0];
    dc_microgrid_6_1_sm_circuit_DW.UnitDelay_DSTATE[1] =
      dc_microgrid_6_1_sm_circuit_B.Product_d[1];
    dc_microgrid_6_1_sm_circuit_DW.UnitDelay_DSTATE[1 << 1] =
      dc_microgrid_6_1_sm_circuit_B.Product_d[2];

    /* Update for DiscreteIntegrator: '<S50>/Integ4' */
    dc_microgrid_6_1_sm_circuit_DW.Integ4_SYSTEM_ENABLE_b = 0;
    dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE_a =
      dc_microgrid_6_1_sm_circuit_B.Integ4_e +
      dc_microgrid_6_1_sm_circuit_P.Integ4_gainval_b *
      dc_microgrid_6_1_sm_circuit_B.Product_o;

    /* Update for S-Function (discreteVariableTransportDelay): '<S51>/S-Function ' incorporates:
     *  Constant: '<S50>/K1'
     */

    /* S-Function block: <S51>/S-Function  */
    {
      int_T indBeg = dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_n.indBeg;
      int_T indEnd = dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_n.indEnd;
      int_T bufSz = dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_n.bufSz;
      indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
      if (indEnd == indBeg) {
        indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
      }

      dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_n.indBeg = indBeg;
      dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_n.indEnd = indEnd;
    }

    /* Update for UnitDelay: '<S50>/Unit Delay' */
    dc_microgrid_6_1_sm_circuit_DW.UnitDelay_DSTATE_b =
      dc_microgrid_6_1_sm_circuit_B.Product_o;

    /* Update for DiscreteIntegrator: '<S44>/Integ4' */
    dc_microgrid_6_1_sm_circuit_DW.Integ4_SYSTEM_ENABLE_g = 0;
    dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE_e =
      dc_microgrid_6_1_sm_circuit_B.Integ4_b +
      dc_microgrid_6_1_sm_circuit_P.Integ4_gainval_b4 *
      dc_microgrid_6_1_sm_circuit_B.Product_er;

    /* Update for S-Function (discreteVariableTransportDelay): '<S45>/S-Function ' incorporates:
     *  Constant: '<S44>/K1'
     */

    /* S-Function block: <S45>/S-Function  */
    {
      int_T indBeg = dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_g.indBeg;
      int_T indEnd = dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_g.indEnd;
      int_T bufSz = dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_g.bufSz;
      indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
      if (indEnd == indBeg) {
        indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
      }

      dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_g.indBeg = indBeg;
      dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_g.indEnd = indEnd;
    }

    /* Update for UnitDelay: '<S44>/Unit Delay' */
    dc_microgrid_6_1_sm_circuit_DW.UnitDelay_DSTATE_n =
      dc_microgrid_6_1_sm_circuit_B.Product_er;

    /* Update for DiscreteIntegrator: '<S46>/Integ4' */
    dc_microgrid_6_1_sm_circuit_DW.Integ4_SYSTEM_ENABLE_bk = 0;
    dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE_l =
      dc_microgrid_6_1_sm_circuit_B.Integ4_d +
      dc_microgrid_6_1_sm_circuit_P.Integ4_gainval_n *
      dc_microgrid_6_1_sm_circuit_B.Product_k;

    /* Update for S-Function (discreteVariableTransportDelay): '<S47>/S-Function ' incorporates:
     *  Constant: '<S46>/K1'
     */

    /* S-Function block: <S47>/S-Function  */
    {
      int_T indBeg = dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_ka.indBeg;
      int_T indEnd = dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_ka.indEnd;
      int_T bufSz = dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_ka.bufSz;
      indEnd = indEnd < bufSz-1 ? indEnd+1 : 0;
      if (indEnd == indBeg) {
        indBeg = indBeg < bufSz-1 ? indBeg+1 : 0;
      }

      dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_ka.indBeg = indBeg;
      dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_ka.indEnd = indEnd;
    }

    /* Update for UnitDelay: '<S46>/Unit Delay' */
    dc_microgrid_6_1_sm_circuit_DW.UnitDelay_DSTATE_h =
      dc_microgrid_6_1_sm_circuit_B.Product_k;
  }

  if (rtmIsMajorTimeStep(dc_microgrid_6_1_sm_circuit_M)) {
    rt_ertODEUpdateContinuousStates(&dc_microgrid_6_1_sm_circuit_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++dc_microgrid_6_1_sm_circuit_M->Timing.clockTick0)) {
    ++dc_microgrid_6_1_sm_circuit_M->Timing.clockTickH0;
  }

  dc_microgrid_6_1_sm_circuit_M->Timing.t[0] = rtsiGetSolverStopTime
    (&dc_microgrid_6_1_sm_circuit_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.0001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++dc_microgrid_6_1_sm_circuit_M->Timing.clockTick1)) {
      ++dc_microgrid_6_1_sm_circuit_M->Timing.clockTickH1;
    }

    dc_microgrid_6_1_sm_circuit_M->Timing.t[1] =
      dc_microgrid_6_1_sm_circuit_M->Timing.clockTick1 *
      dc_microgrid_6_1_sm_circuit_M->Timing.stepSize1 +
      dc_microgrid_6_1_sm_circuit_M->Timing.clockTickH1 *
      dc_microgrid_6_1_sm_circuit_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void dc_microgrid_6_1_sm_circuit_derivatives(void)
{
  XDot_dc_microgrid_6_1_sm_circuit_T *_rtXdot;
  _rtXdot = ((XDot_dc_microgrid_6_1_sm_circuit_T *)
             dc_microgrid_6_1_sm_circuit_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S66>/integrator' */
  _rtXdot->integrator_CSTATE[0] = dc_microgrid_6_1_sm_circuit_B.Product[0];
  _rtXdot->integrator_CSTATE[1] = dc_microgrid_6_1_sm_circuit_B.Product[1];
  _rtXdot->integrator_CSTATE[2] = dc_microgrid_6_1_sm_circuit_B.Product[2];

  /* Derivatives for Integrator: '<S65>/integrator' */
  _rtXdot->integrator_CSTATE_m[0] = dc_microgrid_6_1_sm_circuit_B.Product1_o[0];
  _rtXdot->integrator_CSTATE_m[1] = dc_microgrid_6_1_sm_circuit_B.Product1_o[1];
  _rtXdot->integrator_CSTATE_m[2] = dc_microgrid_6_1_sm_circuit_B.Product1_o[2];

  /* Derivatives for Integrator: '<S70>/integrator' */
  _rtXdot->integrator_CSTATE_p[0] = dc_microgrid_6_1_sm_circuit_B.Product_l[0];
  _rtXdot->integrator_CSTATE_p[1] = dc_microgrid_6_1_sm_circuit_B.Product_l[1];
  _rtXdot->integrator_CSTATE_p[2] = dc_microgrid_6_1_sm_circuit_B.Product_l[2];

  /* Derivatives for Integrator: '<S69>/integrator' */
  _rtXdot->integrator_CSTATE_me[0] = dc_microgrid_6_1_sm_circuit_B.Product1_oy[0];
  _rtXdot->integrator_CSTATE_me[1] = dc_microgrid_6_1_sm_circuit_B.Product1_oy[1];
  _rtXdot->integrator_CSTATE_me[2] = dc_microgrid_6_1_sm_circuit_B.Product1_oy[2];

  /* Derivatives for Enabled SubSystem: '<S18>/TrueRMS ' */
  if (dc_microgrid_6_1_sm_circuit_DW.TrueRMS_MODE) {
    /* Derivatives for Integrator: '<S79>/integrator' */
    _rtXdot->integrator_CSTATE_c = dc_microgrid_6_1_sm_circuit_B.Product_kk;
  } else {
    ((XDot_dc_microgrid_6_1_sm_circuit_T *)
      dc_microgrid_6_1_sm_circuit_M->ModelData.derivs)->integrator_CSTATE_c =
      0.0;
  }

  /* End of Derivatives for SubSystem: '<S18>/TrueRMS ' */

  /* Derivatives for Enabled SubSystem: '<S18>/RMS ' */
  if (dc_microgrid_6_1_sm_circuit_DW.RMS_MODE) {
    /* Derivatives for Integrator: '<S77>/integrator' */
    _rtXdot->integrator_CSTATE_a = dc_microgrid_6_1_sm_circuit_B.Product_c;

    /* Derivatives for Integrator: '<S76>/integrator' */
    _rtXdot->integrator_CSTATE_ao = dc_microgrid_6_1_sm_circuit_B.Product1_d;
  } else {
    {
      real_T *dx;
      int_T i;
      dx = &(((XDot_dc_microgrid_6_1_sm_circuit_T *)
              dc_microgrid_6_1_sm_circuit_M->ModelData.derivs)
             ->integrator_CSTATE_a);
      for (i=0; i < 2; i++) {
        dx[i] = 0.0;
      }
    }
  }

  /* End of Derivatives for SubSystem: '<S18>/RMS ' */
}

/* Model initialize function */
void dc_microgrid_6_1_sm_circuit_initialize(void)
{
  /* Start for S-Function (sfun_spssw_discc): '<S4>/State-Space' incorporates:
   *  Constant: '<S31>/Constant'
   */

  /* S-Function block: <S4>/State-Space */
  {
    dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.AS = (real_T*)calloc(6 * 6,
      sizeof(real_T));
    dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.BS = (real_T*)calloc(6 * 10,
      sizeof(real_T));
    dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.CS = (real_T*)calloc(20 * 6,
      sizeof(real_T));
    dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.DS = (real_T*)calloc(20 * 10,
      sizeof(real_T));
    dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.DX_COL = (real_T*)calloc(20,
      sizeof(real_T));
    dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.TMP2 = (real_T*)calloc(10,
      sizeof(real_T));
    dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.BD_COL = (real_T*)calloc(6,
      sizeof(real_T));
    dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.TMP1 = (real_T*)calloc(6,
      sizeof(real_T));
    dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.XTMP = (real_T*)calloc(6,
      sizeof(real_T));
    dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.SWITCH_STATUS = (int_T*)
      calloc(6, sizeof(int_T));
    dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.SW_CHG = (int_T*)calloc(6,
      sizeof(int_T));
    dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.G_STATE = (int_T*)calloc(6,
      sizeof(int_T));
    dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.Y_SWITCH = (real_T*)calloc(6,
      sizeof(real_T));
    dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.SWITCH_TYPES = (int_T*)
      calloc(6, sizeof(int_T));
    dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.IDX_OUT_SW = (int_T*)calloc
      (6, sizeof(int_T));
    dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.SWITCH_STATUS_INIT = (int_T*)
      calloc(6, sizeof(int_T));
    dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.USWLAST = (real_T*)calloc(6,
      sizeof(real_T));
  }

  /* Start for TransportDelay: '<S66>/Transport Delay' */
  {
    real_T *pBuffer =
      &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_RWORK.TUbufferArea[0];

    {
      int_T i1;
      int_T *iw_Tail =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Tail[0];
      int_T *iw_Head =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Head[0];
      int_T *iw_Last =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.Last[0];
      int_T *iw_CircularBufSize =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK.CircularBufSize[0];
      void **pw_TUbufferPtrs =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_PWORK.TUbufferPtrs[0];
      for (i1=0; i1 < 3; i1++) {
        iw_Tail[i1] = 0;
        iw_Head[i1] = 0;
        iw_Last[i1] = 0;
        iw_CircularBufSize[i1] = 8192;
        pBuffer[0] = dc_microgrid_6_1_sm_circuit_P.TransportDelay_InitOutput_e;
        pBuffer[8192] = dc_microgrid_6_1_sm_circuit_M->Timing.t[0];
        pw_TUbufferPtrs[i1] = (void *) &pBuffer[0];
        pBuffer += 16384;
      }
    }
  }

  /* Start for TransportDelay: '<S65>/Transport Delay' */
  {
    real_T *pBuffer =
      &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_RWORK_h.TUbufferArea[0];

    {
      int_T i1;
      int_T *iw_Tail =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Tail[0];
      int_T *iw_Head =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Head[0];
      int_T *iw_Last =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.Last[0];
      int_T *iw_CircularBufSize =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_n.CircularBufSize[0];
      void **pw_TUbufferPtrs =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_PWORK_n.TUbufferPtrs[0];
      for (i1=0; i1 < 3; i1++) {
        iw_Tail[i1] = 0;
        iw_Head[i1] = 0;
        iw_Last[i1] = 0;
        iw_CircularBufSize[i1] = 8192;
        pBuffer[0] = dc_microgrid_6_1_sm_circuit_P.TransportDelay_InitOutput_f;
        pBuffer[8192] = dc_microgrid_6_1_sm_circuit_M->Timing.t[0];
        pw_TUbufferPtrs[i1] = (void *) &pBuffer[0];
        pBuffer += 16384;
      }
    }
  }

  /* Start for TransportDelay: '<S70>/Transport Delay' */
  {
    real_T *pBuffer =
      &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_RWORK_n.TUbufferArea[0];

    {
      int_T i1;
      int_T *iw_Tail =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Tail[0];
      int_T *iw_Head =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Head[0];
      int_T *iw_Last =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.Last[0];
      int_T *iw_CircularBufSize =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_p.CircularBufSize[0];
      void **pw_TUbufferPtrs =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_PWORK_d.TUbufferPtrs[0];
      for (i1=0; i1 < 3; i1++) {
        iw_Tail[i1] = 0;
        iw_Head[i1] = 0;
        iw_Last[i1] = 0;
        iw_CircularBufSize[i1] = 8192;
        pBuffer[0] = dc_microgrid_6_1_sm_circuit_P.TransportDelay_InitOutput_d;
        pBuffer[8192] = dc_microgrid_6_1_sm_circuit_M->Timing.t[0];
        pw_TUbufferPtrs[i1] = (void *) &pBuffer[0];
        pBuffer += 16384;
      }
    }
  }

  /* Start for TransportDelay: '<S69>/Transport Delay' */
  {
    real_T *pBuffer =
      &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_RWORK_hd.TUbufferArea[0];

    {
      int_T i1;
      int_T *iw_Tail =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Tail[0];
      int_T *iw_Head =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Head[0];
      int_T *iw_Last =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.Last[0];
      int_T *iw_CircularBufSize =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_b.CircularBufSize[0];
      void **pw_TUbufferPtrs =
        &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_PWORK_j.TUbufferPtrs[0];
      for (i1=0; i1 < 3; i1++) {
        iw_Tail[i1] = 0;
        iw_Head[i1] = 0;
        iw_Last[i1] = 0;
        iw_CircularBufSize[i1] = 8192;
        pBuffer[0] = dc_microgrid_6_1_sm_circuit_P.TransportDelay_InitOutput_fm;
        pBuffer[8192] = dc_microgrid_6_1_sm_circuit_M->Timing.t[0];
        pw_TUbufferPtrs[i1] = (void *) &pBuffer[0];
        pBuffer += 16384;
      }
    }
  }

  /* Start for Enabled SubSystem: '<S18>/TrueRMS ' */

  /* Start for TransportDelay: '<S79>/Transport Delay' */
  {
    real_T *pBuffer =
      &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_RWORK_n2.TUbufferArea[0];
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_o.Tail = 0;
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_o.Head = 0;
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_o.Last = 0;
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_o.CircularBufSize = 8192;
    pBuffer[0] = dc_microgrid_6_1_sm_circuit_P.TransportDelay_InitOutput_a;
    pBuffer[8192] = dc_microgrid_6_1_sm_circuit_M->Timing.t[0];
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_PWORK_f.TUbufferPtrs[0] =
      (void *) &pBuffer[0];
  }

  /* End of Start for SubSystem: '<S18>/TrueRMS ' */

  /* Start for Enabled SubSystem: '<S18>/RMS ' */

  /* Start for TransportDelay: '<S77>/Transport Delay' */
  {
    real_T *pBuffer =
      &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_RWORK_j.TUbufferArea[0];
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_ns.Tail = 0;
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_ns.Head = 0;
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_ns.Last = 0;
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_ns.CircularBufSize =
      8192;
    pBuffer[0] = dc_microgrid_6_1_sm_circuit_P.TransportDelay_InitOutput;
    pBuffer[8192] = dc_microgrid_6_1_sm_circuit_M->Timing.t[0];
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_PWORK_ny.TUbufferPtrs[0] =
      (void *) &pBuffer[0];
  }

  /* Start for TransportDelay: '<S76>/Transport Delay' */
  {
    real_T *pBuffer =
      &dc_microgrid_6_1_sm_circuit_DW.TransportDelay_RWORK_ju.TUbufferArea[0];
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_bl.Tail = 0;
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_bl.Head = 0;
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_bl.Last = 0;
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_IWORK_bl.CircularBufSize =
      8192;
    pBuffer[0] = dc_microgrid_6_1_sm_circuit_P.TransportDelay_InitOutput_n;
    pBuffer[8192] = dc_microgrid_6_1_sm_circuit_M->Timing.t[0];
    dc_microgrid_6_1_sm_circuit_DW.TransportDelay_PWORK_nz.TUbufferPtrs[0] =
      (void *) &pBuffer[0];
  }

  /* End of Start for SubSystem: '<S18>/RMS ' */

  /* Start for S-Function (discreteVariableTransportDelay): '<S49>/S-Function ' incorporates:
   *  Constant: '<S48>/K1'
   */

  /* S-Function Block: <S49>/S-Function  */
  {
    static real_T dvtd_buffer[3 * 168];
    dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_k.bufSz = 168;
    dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK.uBuffers[0] = (void *)
      &dvtd_buffer[0];
    dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK.uBuffers[1] = (void *)
      &dvtd_buffer[168];
    dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK.uBuffers[2] = (void *)
      &dvtd_buffer[336];
  }

  {
    dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_k.maxDiscrDelay =
      dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_k.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK.uBuffers[0] != NULL)
      *((real_T *)dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK.uBuffers[0]) =
        (real_T)0.0;
    if (dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK.uBuffers[1] != NULL)
      *((real_T *)dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK.uBuffers[1]) =
        (real_T)0.0;
    if (dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK.uBuffers[2] != NULL)
      *((real_T *)dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK.uBuffers[2]) =
        (real_T)0.0;

    /* Set work values */
    dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_k.indBeg = 0;
    dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_k.indEnd = 1;
  }

  /* Start for S-Function (discreteVariableTransportDelay): '<S51>/S-Function ' incorporates:
   *  Constant: '<S50>/K1'
   */

  /* S-Function Block: <S51>/S-Function  */
  {
    static real_T dvtd_buffer[1 * 168];
    dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_n.bufSz = 168;
    dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK_p.uBuffers = (void *)
      &dvtd_buffer[0];
  }

  {
    dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_n.maxDiscrDelay =
      dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_n.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK_p.uBuffers != NULL)
      *((real_T *)dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK_p.uBuffers) =
        (real_T)0.0;

    /* Set work values */
    dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_n.indBeg = 0;
    dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_n.indEnd = 1;
  }

  /* Start for S-Function (discreteVariableTransportDelay): '<S45>/S-Function ' incorporates:
   *  Constant: '<S44>/K1'
   */

  /* S-Function Block: <S45>/S-Function  */
  {
    static real_T dvtd_buffer[1 * 168];
    dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_g.bufSz = 168;
    dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK_g.uBuffers = (void *)
      &dvtd_buffer[0];
  }

  {
    dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_g.maxDiscrDelay =
      dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_g.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK_g.uBuffers != NULL)
      *((real_T *)dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK_g.uBuffers) =
        (real_T)0.0;

    /* Set work values */
    dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_g.indBeg = 0;
    dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_g.indEnd = 1;
  }

  /* Start for S-Function (discreteVariableTransportDelay): '<S47>/S-Function ' incorporates:
   *  Constant: '<S46>/K1'
   */

  /* S-Function Block: <S47>/S-Function  */
  {
    static real_T dvtd_buffer[1 * 168];
    dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_ka.bufSz = 168;
    dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK_i.uBuffers = (void *)
      &dvtd_buffer[0];
  }

  {
    dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_ka.maxDiscrDelay =
      dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_ka.bufSz - 1;

    /* Assign default sample(s) */
    /* Single initial value */
    if (dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK_i.uBuffers != NULL)
      *((real_T *)dc_microgrid_6_1_sm_circuit_DW.SFunction_PWORK_i.uBuffers) =
        (real_T)0.0;

    /* Set work values */
    dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_ka.indBeg = 0;
    dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK_ka.indEnd = 1;
  }

  {
    int32_T i;

    /* user code (Initialize function Body) */

    /* System '<Root>' */

    /* Opal-RT Technologies */
    opalSizeDwork = sizeof(rtDWork);
    if (Opal_rtmGetNumBlockIO(pRtModel) != 0)
      opalSizeBlockIO = sizeof(rtB);
    else
      opalSizeBlockIO = 0;
    if (Opal_rtmGetNumBlockParams(pRtModel) != 0)
      opalSizeRTP = sizeof(rtP);
    else
      opalSizeRTP = 0;

    /* InitializeConditions for Memory: '<S1>/S-Function' */
    dc_microgrid_6_1_sm_circuit_DW.SFunction_PreviousInput =
      dc_microgrid_6_1_sm_circuit_P.SFunction_InitialCondition;

    /* InitializeConditions for S-Function (RECV_Param): '<S57>/S-Function' */
    /* Level2 S-Function Block: '<S57>/S-Function' (RECV_Param) */
    {
      SimStruct *rts = dc_microgrid_6_1_sm_circuit_M->childSfunctions[0];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* InitializeConditions for Delay: '<S3>/Delay1' */
    dc_microgrid_6_1_sm_circuit_DW.Delay1_DSTATE[0] =
      dc_microgrid_6_1_sm_circuit_P.Delay1_InitialCondition;
    dc_microgrid_6_1_sm_circuit_DW.Delay1_DSTATE[1] =
      dc_microgrid_6_1_sm_circuit_P.Delay1_InitialCondition;

    /* InitializeConditions for S-Function (sfun_spssw_discc): '<S4>/State-Space' incorporates:
     *  Constant: '<S31>/Constant'
     */
    {
      int32_T i, j;
      real_T *As = (real_T*)dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.AS;
      real_T *Bs = (real_T*)dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.BS;
      real_T *Cs = (real_T*)dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.CS;
      real_T *Ds = (real_T*)dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.DS;
      real_T *X0 = (real_T*)&dc_microgrid_6_1_sm_circuit_DW.StateSpace_DSTATE[0];
      for (i = 0; i < 6; i++) {
        X0[i] = (dc_microgrid_6_1_sm_circuit_P.StateSpace_X0_param[i]);
      }

      /* Copy and transpose A and B */
      for (i=0; i<6; i++) {
        for (j=0; j<6; j++)
          As[i*6 + j] = (dc_microgrid_6_1_sm_circuit_P.StateSpace_AS_param[i + j*
                         6]);
        for (j=0; j<10; j++)
          Bs[i*10 + j] = (dc_microgrid_6_1_sm_circuit_P.StateSpace_BS_param[i +
                          j*6]);
      }

      /* Copy and transpose C */
      for (i=0; i<20; i++) {
        for (j=0; j<6; j++)
          Cs[i*6 + j] = (dc_microgrid_6_1_sm_circuit_P.StateSpace_CS_param[i + j*
                         20]);
      }

      /* Copy and transpose D */
      for (i=0; i<20; i++) {
        for (j=0; j<10; j++)
          Ds[i*10 + j] = (dc_microgrid_6_1_sm_circuit_P.StateSpace_DS_param[i +
                          j*20]);
      }

      {
        /* Switches work vectors */
        int_T *switch_status = (int_T*)
          dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.SWITCH_STATUS;
        int_T *gState = (int_T*)
          dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.G_STATE;
        real_T *yswitch = (real_T*)
          dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.Y_SWITCH;
        int_T *switchTypes = (int_T*)
          dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.SWITCH_TYPES;
        int_T *idxOutSw = (int_T*)
          dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.IDX_OUT_SW;
        int_T *switch_status_init = (int_T*)
          dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.SWITCH_STATUS_INIT;

        /* Initialize work vectors */
        switch_status[0] = 0;
        switch_status_init[0] = 0;
        gState[0] = (int_T) 0.0;
        yswitch[0] = 1/0.001;
        switchTypes[0] = (int_T)7.0;
        idxOutSw[0] = ((int_T)0.0) - 1;
        switch_status[1] = 0;
        switch_status_init[1] = 0;
        gState[1] = (int_T) 0.0;
        yswitch[1] = 1/0.001;
        switchTypes[1] = (int_T)7.0;
        idxOutSw[1] = ((int_T)0.0) - 1;
        switch_status[2] = 0;
        switch_status_init[2] = 0;
        gState[2] = (int_T) 0.0;
        yswitch[2] = 1/0.001;
        switchTypes[2] = (int_T)7.0;
        idxOutSw[2] = ((int_T)0.0) - 1;
        switch_status[3] = 0;
        switch_status_init[3] = 0;
        gState[3] = (int_T) 0.0;
        yswitch[3] = 1/0.001;
        switchTypes[3] = (int_T)7.0;
        idxOutSw[3] = ((int_T)0.0) - 1;
        switch_status[4] = 0;
        switch_status_init[4] = 0;
        gState[4] = (int_T) 0.0;
        yswitch[4] = 1/0.001;
        switchTypes[4] = (int_T)7.0;
        idxOutSw[4] = ((int_T)0.0) - 1;
        switch_status[5] = 0;
        switch_status_init[5] = 0;
        gState[5] = (int_T) 0.0;
        yswitch[5] = 1/0.001;
        switchTypes[5] = (int_T)7.0;
        idxOutSw[5] = ((int_T)0.0) - 1;
      }
    }

    /* InitializeConditions for Integrator: '<S66>/integrator' */
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE[0] =
      dc_microgrid_6_1_sm_circuit_P.integrator_IC_l;
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE[1] =
      dc_microgrid_6_1_sm_circuit_P.integrator_IC_l;
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE[2] =
      dc_microgrid_6_1_sm_circuit_P.integrator_IC_l;

    /* InitializeConditions for Memory: '<S66>/Memory' */
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput[0] =
      dc_microgrid_6_1_sm_circuit_P.Memory_InitialCondition_f;
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput[1] =
      dc_microgrid_6_1_sm_circuit_P.Memory_InitialCondition_f;
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput[2] =
      dc_microgrid_6_1_sm_circuit_P.Memory_InitialCondition_f;

    /* InitializeConditions for Integrator: '<S65>/integrator' */
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE_m[0] =
      dc_microgrid_6_1_sm_circuit_P.integrator_IC_c;
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE_m[1] =
      dc_microgrid_6_1_sm_circuit_P.integrator_IC_c;
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE_m[2] =
      dc_microgrid_6_1_sm_circuit_P.integrator_IC_c;

    /* InitializeConditions for Memory: '<S65>/Memory' */
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_d[0] =
      dc_microgrid_6_1_sm_circuit_P.Memory_InitialCondition_c;
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_d[1] =
      dc_microgrid_6_1_sm_circuit_P.Memory_InitialCondition_c;
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_d[2] =
      dc_microgrid_6_1_sm_circuit_P.Memory_InitialCondition_c;

    /* InitializeConditions for Integrator: '<S70>/integrator' */
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE_p[0] =
      dc_microgrid_6_1_sm_circuit_P.integrator_IC_cp;
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE_p[1] =
      dc_microgrid_6_1_sm_circuit_P.integrator_IC_cp;
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE_p[2] =
      dc_microgrid_6_1_sm_circuit_P.integrator_IC_cp;

    /* InitializeConditions for Memory: '<S70>/Memory' */
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_g[0] =
      dc_microgrid_6_1_sm_circuit_P.Memory_InitialCondition_b;
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_g[1] =
      dc_microgrid_6_1_sm_circuit_P.Memory_InitialCondition_b;
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_g[2] =
      dc_microgrid_6_1_sm_circuit_P.Memory_InitialCondition_b;

    /* InitializeConditions for Integrator: '<S69>/integrator' */
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE_me[0] =
      dc_microgrid_6_1_sm_circuit_P.integrator_IC_j;
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE_me[1] =
      dc_microgrid_6_1_sm_circuit_P.integrator_IC_j;
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE_me[2] =
      dc_microgrid_6_1_sm_circuit_P.integrator_IC_j;

    /* InitializeConditions for Memory: '<S69>/Memory' */
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_l[0] =
      dc_microgrid_6_1_sm_circuit_P.Memory_InitialCondition_l;
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_l[1] =
      dc_microgrid_6_1_sm_circuit_P.Memory_InitialCondition_l;
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_l[2] =
      dc_microgrid_6_1_sm_circuit_P.Memory_InitialCondition_l;

    /* InitializeConditions for S-Function (OP_SEND): '<S97>/S-Function' */
    /* Level2 S-Function Block: '<S97>/S-Function' (OP_SEND) */
    {
      SimStruct *rts = dc_microgrid_6_1_sm_circuit_M->childSfunctions[1];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* InitializeConditions for UnitDelay: '<S23>/Unit Delay4' */
    for (i = 0; i < 6; i = i + 1) {
      dc_microgrid_6_1_sm_circuit_DW.UnitDelay4_DSTATE[i] =
        dc_microgrid_6_1_sm_circuit_P.UnitDelay4_InitialCondition;
    }

    /* End of InitializeConditions for UnitDelay: '<S23>/Unit Delay4' */

    /* InitializeConditions for DiscreteIntegrator: '<S48>/Integ4' */
    dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE[0] =
      dc_microgrid_6_1_sm_circuit_P.Integ4_IC;
    dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE[1] =
      dc_microgrid_6_1_sm_circuit_P.Integ4_IC;
    dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE[2] =
      dc_microgrid_6_1_sm_circuit_P.Integ4_IC;

    /* InitializeConditions for UnitDelay: '<S48>/Unit Delay' */
    dc_microgrid_6_1_sm_circuit_DW.UnitDelay_DSTATE[0] =
      dc_microgrid_6_1_sm_circuit_P.UnitDelay_InitialCondition;
    dc_microgrid_6_1_sm_circuit_DW.UnitDelay_DSTATE[1] =
      dc_microgrid_6_1_sm_circuit_P.UnitDelay_InitialCondition;
    dc_microgrid_6_1_sm_circuit_DW.UnitDelay_DSTATE[2] =
      dc_microgrid_6_1_sm_circuit_P.UnitDelay_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S50>/Integ4' */
    dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE_a =
      dc_microgrid_6_1_sm_circuit_P.Integ4_IC_f;

    /* InitializeConditions for UnitDelay: '<S50>/Unit Delay' */
    dc_microgrid_6_1_sm_circuit_DW.UnitDelay_DSTATE_b =
      dc_microgrid_6_1_sm_circuit_P.UnitDelay_InitialCondition_i;

    /* InitializeConditions for DiscreteIntegrator: '<S44>/Integ4' */
    dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE_e =
      dc_microgrid_6_1_sm_circuit_P.Integ4_IC_d;

    /* InitializeConditions for UnitDelay: '<S44>/Unit Delay' */
    dc_microgrid_6_1_sm_circuit_DW.UnitDelay_DSTATE_n =
      dc_microgrid_6_1_sm_circuit_P.UnitDelay_InitialCondition_m;

    /* InitializeConditions for DiscreteIntegrator: '<S46>/Integ4' */
    dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE_l =
      dc_microgrid_6_1_sm_circuit_P.Integ4_IC_a;

    /* InitializeConditions for UnitDelay: '<S46>/Unit Delay' */
    dc_microgrid_6_1_sm_circuit_DW.UnitDelay_DSTATE_h =
      dc_microgrid_6_1_sm_circuit_P.UnitDelay_InitialCondition_a;

    /* SystemInitialize for Enabled SubSystem: '<S18>/TrueRMS ' */
    /* InitializeConditions for Integrator: '<S79>/integrator' */
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE_c =
      dc_microgrid_6_1_sm_circuit_P.integrator_IC_d;

    /* InitializeConditions for Memory: '<S79>/Memory' */
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_f =
      dc_microgrid_6_1_sm_circuit_P.Memory_InitialCondition_o;

    /* End of SystemInitialize for SubSystem: '<S18>/TrueRMS ' */

    /* SystemInitialize for Enabled SubSystem: '<S18>/RMS ' */
    /* InitializeConditions for Integrator: '<S77>/integrator' */
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE_a =
      dc_microgrid_6_1_sm_circuit_P.integrator_IC;

    /* InitializeConditions for Memory: '<S77>/Memory' */
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_da =
      dc_microgrid_6_1_sm_circuit_P.Memory_InitialCondition;

    /* InitializeConditions for Integrator: '<S76>/integrator' */
    dc_microgrid_6_1_sm_circuit_X.integrator_CSTATE_ao =
      dc_microgrid_6_1_sm_circuit_P.integrator_IC_f;

    /* InitializeConditions for Memory: '<S76>/Memory' */
    dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_i =
      dc_microgrid_6_1_sm_circuit_P.Memory_InitialCondition_h;

    /* End of SystemInitialize for SubSystem: '<S18>/RMS ' */
  }

  /* Enable for DiscreteIntegrator: '<S48>/Integ4' */
  dc_microgrid_6_1_sm_circuit_DW.Integ4_SYSTEM_ENABLE = 1;

  /* Enable for DiscreteIntegrator: '<S50>/Integ4' */
  dc_microgrid_6_1_sm_circuit_DW.Integ4_SYSTEM_ENABLE_b = 1;

  /* Enable for DiscreteIntegrator: '<S44>/Integ4' */
  dc_microgrid_6_1_sm_circuit_DW.Integ4_SYSTEM_ENABLE_g = 1;

  /* Enable for DiscreteIntegrator: '<S46>/Integ4' */
  dc_microgrid_6_1_sm_circuit_DW.Integ4_SYSTEM_ENABLE_bk = 1;
}

/* Model terminate function */
void dc_microgrid_6_1_sm_circuit_terminate(void)
{
  /* Terminate for S-Function (RECV_Param): '<S57>/S-Function' */
  /* Level2 S-Function Block: '<S57>/S-Function' (RECV_Param) */
  {
    SimStruct *rts = dc_microgrid_6_1_sm_circuit_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sfun_spssw_discc): '<S4>/State-Space' incorporates:
   *  Constant: '<S31>/Constant'
   */

  /* S-Function block: <S4>/State-Space */
  {
    /* Free memory */
    free(dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.AS);
    free(dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.BS);
    free(dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.CS);
    free(dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.DS);
    free(dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.DX_COL);
    free(dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.TMP2);
    free(dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.BD_COL);
    free(dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.TMP1);
    free(dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.XTMP);

    /*
     * Circuit has switches*/
    free(dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.G_STATE);
    free(dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.SWITCH_STATUS);
    free(dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.SW_CHG);
    free(dc_microgrid_6_1_sm_circuit_DW.StateSpace_PWORK.SWITCH_STATUS_INIT);
  }

  /* Terminate for S-Function (OP_SEND): '<S97>/S-Function' */
  /* Level2 S-Function Block: '<S97>/S-Function' (OP_SEND) */
  {
    SimStruct *rts = dc_microgrid_6_1_sm_circuit_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (discreteVariableTransportDelay): '<S49>/S-Function ' incorporates:
   *  Constant: '<S48>/K1'
   */

  /* S-Function block: <S49>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* Terminate for S-Function (discreteVariableTransportDelay): '<S51>/S-Function ' incorporates:
   *  Constant: '<S50>/K1'
   */

  /* S-Function block: <S51>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* Terminate for S-Function (discreteVariableTransportDelay): '<S45>/S-Function ' incorporates:
   *  Constant: '<S44>/K1'
   */

  /* S-Function block: <S45>/S-Function  */
  {
    /* Nothing to do! */
  }

  /* Terminate for S-Function (discreteVariableTransportDelay): '<S47>/S-Function ' incorporates:
   *  Constant: '<S46>/K1'
   */

  /* S-Function block: <S47>/S-Function  */
  {
    /* Nothing to do! */
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  dc_microgrid_6_1_sm_circuit_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  dc_microgrid_6_1_sm_circuit_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  dc_microgrid_6_1_sm_circuit_initialize();
}

void MdlTerminate(void)
{
  dc_microgrid_6_1_sm_circuit_terminate();
}

/* Registration function */
RT_MODEL_dc_microgrid_6_1_sm_circuit_T *dc_microgrid_6_1_sm_circuit(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  dc_microgrid_6_1_sm_circuit_P.Saturationtoavoidnegativesqrt_U = rtInf;
  dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpourevitersqrt = rtInf;
  dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpourevitersq_d = rtInf;
  dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpourevitersq_f = rtInf;
  dc_microgrid_6_1_sm_circuit_P.SaturationAjoutPBpoureviters_oi = rtInf;

  /* initialize real-time model */
  (void) memset((void *)dc_microgrid_6_1_sm_circuit_M, 0,
                sizeof(RT_MODEL_dc_microgrid_6_1_sm_circuit_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&dc_microgrid_6_1_sm_circuit_M->solverInfo,
                          &dc_microgrid_6_1_sm_circuit_M->Timing.simTimeStep);
    rtsiSetTPtr(&dc_microgrid_6_1_sm_circuit_M->solverInfo, &rtmGetTPtr
                (dc_microgrid_6_1_sm_circuit_M));
    rtsiSetStepSizePtr(&dc_microgrid_6_1_sm_circuit_M->solverInfo,
                       &dc_microgrid_6_1_sm_circuit_M->Timing.stepSize0);
    rtsiSetdXPtr(&dc_microgrid_6_1_sm_circuit_M->solverInfo,
                 &dc_microgrid_6_1_sm_circuit_M->ModelData.derivs);
    rtsiSetContStatesPtr(&dc_microgrid_6_1_sm_circuit_M->solverInfo, (real_T **)
                         &dc_microgrid_6_1_sm_circuit_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&dc_microgrid_6_1_sm_circuit_M->solverInfo,
      &dc_microgrid_6_1_sm_circuit_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&dc_microgrid_6_1_sm_circuit_M->solverInfo,
      &dc_microgrid_6_1_sm_circuit_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&dc_microgrid_6_1_sm_circuit_M->solverInfo,
       &dc_microgrid_6_1_sm_circuit_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&dc_microgrid_6_1_sm_circuit_M->solverInfo,
      &dc_microgrid_6_1_sm_circuit_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&dc_microgrid_6_1_sm_circuit_M->solverInfo,
                          (&rtmGetErrorStatus(dc_microgrid_6_1_sm_circuit_M)));
    rtsiSetRTModelPtr(&dc_microgrid_6_1_sm_circuit_M->solverInfo,
                      dc_microgrid_6_1_sm_circuit_M);
  }

  rtsiSetSimTimeStep(&dc_microgrid_6_1_sm_circuit_M->solverInfo, MAJOR_TIME_STEP);
  dc_microgrid_6_1_sm_circuit_M->ModelData.intgData.y =
    dc_microgrid_6_1_sm_circuit_M->ModelData.odeY;
  dc_microgrid_6_1_sm_circuit_M->ModelData.intgData.f[0] =
    dc_microgrid_6_1_sm_circuit_M->ModelData.odeF[0];
  dc_microgrid_6_1_sm_circuit_M->ModelData.intgData.f[1] =
    dc_microgrid_6_1_sm_circuit_M->ModelData.odeF[1];
  dc_microgrid_6_1_sm_circuit_M->ModelData.intgData.f[2] =
    dc_microgrid_6_1_sm_circuit_M->ModelData.odeF[2];
  dc_microgrid_6_1_sm_circuit_M->ModelData.contStates = ((real_T *)
    &dc_microgrid_6_1_sm_circuit_X);
  rtsiSetSolverData(&dc_microgrid_6_1_sm_circuit_M->solverInfo, (void *)
                    &dc_microgrid_6_1_sm_circuit_M->ModelData.intgData);
  rtsiSetSolverName(&dc_microgrid_6_1_sm_circuit_M->solverInfo,"ode3");
  dc_microgrid_6_1_sm_circuit_M->solverInfoPtr =
    (&dc_microgrid_6_1_sm_circuit_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      dc_microgrid_6_1_sm_circuit_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "dc_microgrid_6_1_sm_circuit_M points to
       static memory which is guaranteed to be non-NULL" */
    dc_microgrid_6_1_sm_circuit_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    dc_microgrid_6_1_sm_circuit_M->Timing.sampleTimes =
      (&dc_microgrid_6_1_sm_circuit_M->Timing.sampleTimesArray[0]);
    dc_microgrid_6_1_sm_circuit_M->Timing.offsetTimes =
      (&dc_microgrid_6_1_sm_circuit_M->Timing.offsetTimesArray[0]);

    /* task periods */
    dc_microgrid_6_1_sm_circuit_M->Timing.sampleTimes[0] = (0.0);
    dc_microgrid_6_1_sm_circuit_M->Timing.sampleTimes[1] = (0.0001);

    /* task offsets */
    dc_microgrid_6_1_sm_circuit_M->Timing.offsetTimes[0] = (0.0);
    dc_microgrid_6_1_sm_circuit_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(dc_microgrid_6_1_sm_circuit_M,
             &dc_microgrid_6_1_sm_circuit_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = dc_microgrid_6_1_sm_circuit_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    dc_microgrid_6_1_sm_circuit_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(dc_microgrid_6_1_sm_circuit_M, 0.4);
  dc_microgrid_6_1_sm_circuit_M->Timing.stepSize0 = 0.0001;
  dc_microgrid_6_1_sm_circuit_M->Timing.stepSize1 = 0.0001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    dc_microgrid_6_1_sm_circuit_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(dc_microgrid_6_1_sm_circuit_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(dc_microgrid_6_1_sm_circuit_M->rtwLogInfo, (NULL));
    rtliSetLogT(dc_microgrid_6_1_sm_circuit_M->rtwLogInfo, "");
    rtliSetLogX(dc_microgrid_6_1_sm_circuit_M->rtwLogInfo, "");
    rtliSetLogXFinal(dc_microgrid_6_1_sm_circuit_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(dc_microgrid_6_1_sm_circuit_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(dc_microgrid_6_1_sm_circuit_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(dc_microgrid_6_1_sm_circuit_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(dc_microgrid_6_1_sm_circuit_M->rtwLogInfo, 1);
    rtliSetLogY(dc_microgrid_6_1_sm_circuit_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(dc_microgrid_6_1_sm_circuit_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(dc_microgrid_6_1_sm_circuit_M->rtwLogInfo, (NULL));
  }

  dc_microgrid_6_1_sm_circuit_M->solverInfoPtr =
    (&dc_microgrid_6_1_sm_circuit_M->solverInfo);
  dc_microgrid_6_1_sm_circuit_M->Timing.stepSize = (0.0001);
  rtsiSetFixedStepSize(&dc_microgrid_6_1_sm_circuit_M->solverInfo, 0.0001);
  rtsiSetSolverMode(&dc_microgrid_6_1_sm_circuit_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  dc_microgrid_6_1_sm_circuit_M->ModelData.blockIO = ((void *)
    &dc_microgrid_6_1_sm_circuit_B);
  (void) memset(((void *) &dc_microgrid_6_1_sm_circuit_B), 0,
                sizeof(B_dc_microgrid_6_1_sm_circuit_T));

  {
    int32_T i;
    for (i = 0; i < 20; i++) {
      dc_microgrid_6_1_sm_circuit_B.StateSpace_o1[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      dc_microgrid_6_1_sm_circuit_B.StateSpace_o2[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      dc_microgrid_6_1_sm_circuit_B.UnitDelay4[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      dc_microgrid_6_1_sm_circuit_B.DataTypeConversion[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      dc_microgrid_6_1_sm_circuit_B.DataTypeConversion_i[i] = 0.0;
    }

    dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex[0].re = 0.0;
    dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex[0].im = 0.0;
    dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex[1].re = 0.0;
    dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex[1].im = 0.0;
    dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex[2].re = 0.0;
    dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex[2].im = 0.0;
    dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_e[0].re = 0.0;
    dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_e[0].im = 0.0;
    dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_e[1].re = 0.0;
    dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_e[1].im = 0.0;
    dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_e[2].re = 0.0;
    dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_e[2].im = 0.0;
    dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_a.re = 0.0;
    dc_microgrid_6_1_sm_circuit_B.RealImagtoComplex_a.im = 0.0;
    dc_microgrid_6_1_sm_circuit_B.SFunction = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum = 0.0;
    dc_microgrid_6_1_sm_circuit_B.SineWave3 = 0.0;
    dc_microgrid_6_1_sm_circuit_B.SFunction_d[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.SFunction_d[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product6 = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product5 = 0.0;
    dc_microgrid_6_1_sm_circuit_B.SineWave4 = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product7 = 0.0;
    dc_microgrid_6_1_sm_circuit_B.SineWave5 = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product8 = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Delay1 = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Divide1 = 0.0;
    dc_microgrid_6_1_sm_circuit_B.integrator[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.integrator[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.integrator[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.TransportDelay[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.TransportDelay[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.TransportDelay[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Clock = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Memory[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Memory[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Memory[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.integrator_p[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.integrator_p[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.integrator_p[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.TransportDelay_n[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.TransportDelay_n[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.TransportDelay_n[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Clock_p = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Memory_j[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Memory_j[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Memory_j[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch_h[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch_h[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch_h[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o1[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o1[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o1[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o2[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o2[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o2[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.integrator_f[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.integrator_f[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.integrator_f[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.TransportDelay_a[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.TransportDelay_a[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.TransportDelay_a[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Clock_g = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Memory_g[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Memory_g[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Memory_g[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch_k[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch_k[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch_k[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.integrator_b[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.integrator_b[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.integrator_b[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.TransportDelay_b[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.TransportDelay_b[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.TransportDelay_b[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Clock_k = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Memory_p[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Memory_p[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Memory_p[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch_d[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch_d[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch_d[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o1_d[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o1_d[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o1_d[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o2_f[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o2_f[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o2_f[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.VfundIfund[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.VfundIfund[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.VfundIfund[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain1[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain1[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain1[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.RadDeg[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.RadDeg[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.RadDeg[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.RadDeg_n[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.RadDeg_n[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.RadDeg_n[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum_d[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum_d[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum_d[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.phi[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.phi[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.phi[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction2_o1[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction2_o1[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction2_o1[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction2_o2[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction2_o2[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction2_o2[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product1[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product1[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product1[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Add = 0.0;
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain = 0.0;
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_j = 0.0;
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_p = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Kv[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Kv[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Kv[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch_m = 0.0;
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_l = 0.0;
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_jm = 0.0;
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_jz = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Kv1[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Kv1[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Kv1[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.sinwt = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.coswt = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product1_o[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product1_o[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product1_o[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.sinwt_b = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product_l[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product_l[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product_l[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.coswt_e = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product1_oy[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product1_oy[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product1_oy[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product3[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product3[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product3[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sign = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product_e = 0.0;
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_pt = 0.0;
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_i = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product4 = 0.0;
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_j4 = 0.0;
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_o = 0.0;
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_c = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product_d[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product_d[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product_d[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Integ4[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Integ4[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Integ4[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.SFunction_p[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.SFunction_p[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.SFunction_p[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.UnitDelay[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.UnitDelay[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.UnitDelay[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Step = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch_c[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch_c[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch_c[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.SaturationAjoutPBpourevitersqrt[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.SaturationAjoutPBpourevitersqrt[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.SaturationAjoutPBpourevitersqrt[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sqrt[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sqrt[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sqrt[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_or = 0.0;
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_c0 = 0.0;
    dc_microgrid_6_1_sm_circuit_B.donotdeletethisgain_a = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product_o = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Integ4_e = 0.0;
    dc_microgrid_6_1_sm_circuit_B.SFunction_m = 0.0;
    dc_microgrid_6_1_sm_circuit_B.UnitDelay_m = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Step_l = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch_b = 0.0;
    dc_microgrid_6_1_sm_circuit_B.SaturationAjoutPBpourevitersq_h = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sqrt_e = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product_er = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Integ4_b = 0.0;
    dc_microgrid_6_1_sm_circuit_B.SFunction_j = 0.0;
    dc_microgrid_6_1_sm_circuit_B.UnitDelay_o = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Step_m = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch_a = 0.0;
    dc_microgrid_6_1_sm_circuit_B.SaturationAjoutPBpourevitersq_j = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sqrt_b = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product_k = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Integ4_d = 0.0;
    dc_microgrid_6_1_sm_circuit_B.SFunction_k = 0.0;
    dc_microgrid_6_1_sm_circuit_B.UnitDelay_n = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Step_k = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch_j = 0.0;
    dc_microgrid_6_1_sm_circuit_B.SaturationAjoutPBpourevitersq_n = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sqrt_d = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch2 = 0.0;
    dc_microgrid_6_1_sm_circuit_B.t = 0.0;
    dc_microgrid_6_1_sm_circuit_B.t_o = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch_l[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch_l[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch_l[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Clock_j = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum_b = 0.0;
    dc_microgrid_6_1_sm_circuit_B.MathFunction = 0.0;
    dc_microgrid_6_1_sm_circuit_B.LookUpTable1 = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Output = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain3[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain3[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain3[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Clock_h = 0.0;
    dc_microgrid_6_1_sm_circuit_B.integrator_k = 0.0;
    dc_microgrid_6_1_sm_circuit_B.TransportDelay_j = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Memory_c = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch_cu = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product_kk = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Saturationtoavoidnegativesqrt = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sqrt_p = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum_a = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain = 0.0;
    dc_microgrid_6_1_sm_circuit_B.integrator_h = 0.0;
    dc_microgrid_6_1_sm_circuit_B.TransportDelay_c = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Clock_js = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Memory_m = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch_k1 = 0.0;
    dc_microgrid_6_1_sm_circuit_B.integrator_a = 0.0;
    dc_microgrid_6_1_sm_circuit_B.TransportDelay_an = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Clock_a = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Memory_h = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch_o = 0.0;
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o1_h = 0.0;
    dc_microgrid_6_1_sm_circuit_B.ComplextoMagnitudeAngle_o2_fx = 0.0;
    dc_microgrid_6_1_sm_circuit_B.sinwt_g = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product_c = 0.0;
    dc_microgrid_6_1_sm_circuit_B.coswt_a = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product1_d = 0.0;
    dc_microgrid_6_1_sm_circuit_B.RadDeg_p = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain_b = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum_e = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain_e = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum_g = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain_m = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum_bj[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum_bj[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum_bj[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain_l[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain_l[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain_l[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum_dn[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum_dn[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum_dn[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain_ej[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain_ej[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain_ej[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum_db[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum_db[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum_db[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain_g[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain_g[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain_g[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum_n[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum_n[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum_n[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain_eh[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain_eh[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain_eh[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain_n = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain1_i = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Correction = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum7 = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Meanvalue = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum5 = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain_bl[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain_bl[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain_bl[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain1_b[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain1_b[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain1_b[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Correction_o[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Correction_o[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Correction_o[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum7_h[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum7_h[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum7_h[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Meanvalue_m[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Meanvalue_m[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Meanvalue_m[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum5_c[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum5_c[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum5_c[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain_bd = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain1_e = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Correction_h = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum7_b = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Meanvalue_n = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum5_a = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain_j = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain1_c = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Correction_b = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum7_m = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Meanvalue_d = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum5_m = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Switch2_c = 0.0;
    dc_microgrid_6_1_sm_circuit_B.DegRad = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product7_d = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum_k = 0.0;
    dc_microgrid_6_1_sm_circuit_B.MathFunction_h = 0.0;
    dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product2 = 0.0;
    dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction1 = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product3_e = 0.0;
    dc_microgrid_6_1_sm_circuit_B.coswt2pi3 = 0.0;
    dc_microgrid_6_1_sm_circuit_B.coswt2pi3_j = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product1_n = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product_n = 0.0;
    dc_microgrid_6_1_sm_circuit_B.sinwt2pi3 = 0.0;
    dc_microgrid_6_1_sm_circuit_B.sinwt2pi3_p = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Fcn2 = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product_a = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Fcn4 = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product1_j = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Fcn5 = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product2_h = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain2 = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Gain_d = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum_o[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum_o[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Sum_o[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction_i[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction_i[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.TrigonometricFunction_i[2] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product_m[0] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product_m[1] = 0.0;
    dc_microgrid_6_1_sm_circuit_B.Product_m[2] = 0.0;
  }

  /* parameters */
  dc_microgrid_6_1_sm_circuit_M->ModelData.defaultParam = ((real_T *)
    &dc_microgrid_6_1_sm_circuit_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &dc_microgrid_6_1_sm_circuit_X;
    dc_microgrid_6_1_sm_circuit_M->ModelData.contStates = (x);
    (void) memset((void *)&dc_microgrid_6_1_sm_circuit_X, 0,
                  sizeof(X_dc_microgrid_6_1_sm_circuit_T));
  }

  /* states (dwork) */
  dc_microgrid_6_1_sm_circuit_M->ModelData.dwork = ((void *)
    &dc_microgrid_6_1_sm_circuit_DW);
  (void) memset((void *)&dc_microgrid_6_1_sm_circuit_DW, 0,
                sizeof(DW_dc_microgrid_6_1_sm_circuit_T));
  dc_microgrid_6_1_sm_circuit_DW.Delay1_DSTATE[0] = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.Delay1_DSTATE[1] = 0.0;

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      dc_microgrid_6_1_sm_circuit_DW.StateSpace_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      dc_microgrid_6_1_sm_circuit_DW.UnitDelay4_DSTATE[i] = 0.0;
    }
  }

  dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE[0] = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE[1] = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE[2] = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.UnitDelay_DSTATE[0] = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.UnitDelay_DSTATE[1] = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.UnitDelay_DSTATE[2] = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE_a = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.UnitDelay_DSTATE_b = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE_e = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.UnitDelay_DSTATE_n = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.Integ4_DSTATE_l = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.UnitDelay_DSTATE_h = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.SFunction_PreviousInput = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput[0] = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput[1] = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput[2] = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_d[0] = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_d[1] = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_d[2] = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_g[0] = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_g[1] = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_g[2] = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_l[0] = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_l[1] = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_l[2] = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_f = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_da = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.Memory_PreviousInput_i = 0.0;
  dc_microgrid_6_1_sm_circuit_DW.TransportDelay_RWORK.modelTStart = 0.0;

  {
    int32_T i;
    for (i = 0; i < 49152; i++) {
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_RWORK.TUbufferArea[i] = 0.0;
    }
  }

  dc_microgrid_6_1_sm_circuit_DW.TransportDelay_RWORK_h.modelTStart = 0.0;

  {
    int32_T i;
    for (i = 0; i < 49152; i++) {
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_RWORK_h.TUbufferArea[i] =
        0.0;
    }
  }

  dc_microgrid_6_1_sm_circuit_DW.TransportDelay_RWORK_n.modelTStart = 0.0;

  {
    int32_T i;
    for (i = 0; i < 49152; i++) {
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_RWORK_n.TUbufferArea[i] =
        0.0;
    }
  }

  dc_microgrid_6_1_sm_circuit_DW.TransportDelay_RWORK_hd.modelTStart = 0.0;

  {
    int32_T i;
    for (i = 0; i < 49152; i++) {
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_RWORK_hd.TUbufferArea[i] =
        0.0;
    }
  }

  dc_microgrid_6_1_sm_circuit_DW.TransportDelay_RWORK_n2.modelTStart = 0.0;

  {
    int32_T i;
    for (i = 0; i < 16384; i++) {
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_RWORK_n2.TUbufferArea[i] =
        0.0;
    }
  }

  dc_microgrid_6_1_sm_circuit_DW.TransportDelay_RWORK_j.modelTStart = 0.0;

  {
    int32_T i;
    for (i = 0; i < 16384; i++) {
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_RWORK_j.TUbufferArea[i] =
        0.0;
    }
  }

  dc_microgrid_6_1_sm_circuit_DW.TransportDelay_RWORK_ju.modelTStart = 0.0;

  {
    int32_T i;
    for (i = 0; i < 16384; i++) {
      dc_microgrid_6_1_sm_circuit_DW.TransportDelay_RWORK_ju.TUbufferArea[i] =
        0.0;
    }
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo =
      &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.sfcnInfo;
    dc_microgrid_6_1_sm_circuit_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus
      (dc_microgrid_6_1_sm_circuit_M)));
    dc_microgrid_6_1_sm_circuit_M->Sizes.numSampTimes = (2);
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &dc_microgrid_6_1_sm_circuit_M->Sizes.numSampTimes);
    dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.taskTimePtrs[0] =
      &(rtmGetTPtr(dc_microgrid_6_1_sm_circuit_M)[0]);
    dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.taskTimePtrs[1] =
      &(rtmGetTPtr(dc_microgrid_6_1_sm_circuit_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,
                   dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(dc_microgrid_6_1_sm_circuit_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(dc_microgrid_6_1_sm_circuit_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (dc_microgrid_6_1_sm_circuit_M));
    rtssSetStepSizePtr(sfcnInfo, &dc_microgrid_6_1_sm_circuit_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (dc_microgrid_6_1_sm_circuit_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &dc_microgrid_6_1_sm_circuit_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &dc_microgrid_6_1_sm_circuit_M->ModelData.zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &dc_microgrid_6_1_sm_circuit_M->ModelData.CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo,
                         &dc_microgrid_6_1_sm_circuit_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &dc_microgrid_6_1_sm_circuit_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &dc_microgrid_6_1_sm_circuit_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &dc_microgrid_6_1_sm_circuit_M->solverInfoPtr);
  }

  dc_microgrid_6_1_sm_circuit_M->Sizes.numSFcns = (2);

  /* register each child */
  {
    (void) memset((void *)
                  &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.childSFunctions
                  [0], 0,
                  2*sizeof(SimStruct));
    dc_microgrid_6_1_sm_circuit_M->childSfunctions =
      (&dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    dc_microgrid_6_1_sm_circuit_M->childSfunctions[0] =
      (&dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.childSFunctions[0]);
    dc_microgrid_6_1_sm_circuit_M->childSfunctions[1] =
      (&dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.childSFunctions[1]);

    /* Level2 S-Function Block: dc_microgrid_6_1_sm_circuit/<S57>/S-Function (RECV_Param) */
    {
      SimStruct *rts = dc_microgrid_6_1_sm_circuit_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.blkInfo2
                         [0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, dc_microgrid_6_1_sm_circuit_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.methods2
                           [0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.methods3
                           [0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.methods4
                           [0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.Sfcn0.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            dc_microgrid_6_1_sm_circuit_B.SFunction_d));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "dc_microgrid_6_1_sm_circuit/sm_circuit/OpComm/Receive/S-Function");
      ssSetRTModel(rts,dc_microgrid_6_1_sm_circuit_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       dc_microgrid_6_1_sm_circuit_P.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       dc_microgrid_6_1_sm_circuit_P.SFunction_P2_Size);
      }

      /* registration */
      RECV_Param(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: dc_microgrid_6_1_sm_circuit/<S97>/S-Function (OP_SEND) */
    {
      SimStruct *rts = dc_microgrid_6_1_sm_circuit_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.blkInfo2
                         [1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, dc_microgrid_6_1_sm_circuit_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.methods2
                           [1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.methods3
                           [1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.methods4
                           [1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.statesInfo2
                         [1]);
        ssSetPeriodicStatesInfo(rts,
          &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &dc_microgrid_6_1_sm_circuit_B.Add;
          sfcnUPtrs[1] = &dc_microgrid_6_1_sm_circuit_B.Switch_m;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "dc_microgrid_6_1_sm_circuit/sm_circuit/rtlab_send_subsystem/Subsystem1/Send1/S-Function");
      ssSetRTModel(rts,dc_microgrid_6_1_sm_circuit_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       dc_microgrid_6_1_sm_circuit_P.SFunction_P1_Size_h);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK
                 [0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &dc_microgrid_6_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 5);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &dc_microgrid_6_1_sm_circuit_DW.SFunction_IWORK[0]);
      }

      /* registration */
      OP_SEND(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 2);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Initialize Sizes */
  dc_microgrid_6_1_sm_circuit_M->Sizes.numContStates = (15);/* Number of continuous states */
  dc_microgrid_6_1_sm_circuit_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  dc_microgrid_6_1_sm_circuit_M->Sizes.numY = (0);/* Number of model outputs */
  dc_microgrid_6_1_sm_circuit_M->Sizes.numU = (0);/* Number of model inputs */
  dc_microgrid_6_1_sm_circuit_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  dc_microgrid_6_1_sm_circuit_M->Sizes.numSampTimes = (2);/* Number of sample times */
  dc_microgrid_6_1_sm_circuit_M->Sizes.numBlocks = (395);/* Number of blocks */
  dc_microgrid_6_1_sm_circuit_M->Sizes.numBlockIO = (230);/* Number of block outputs */
  dc_microgrid_6_1_sm_circuit_M->Sizes.numBlockPrms = (628);/* Sum of parameter "widths" */
  return dc_microgrid_6_1_sm_circuit_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
