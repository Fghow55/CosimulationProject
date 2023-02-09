/*
 * ac_der_basic_model_1_sm_circuit.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ac_der_basic_model_1_sm_circuit".
 *
 * Model version              : 13.32
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Mon Jan 23 14:33:22 2023
 *
 * Target selection: rtlab_rtmodel.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ac_der_basic_model_1_sm_circuit.h"
#include "ac_der_basic_model_1_sm_circuit_private.h"
#define ac_der_basic_model_1_sm_ci_ir_n (0)

const int_T ac_der_basic_model_1_sm_ci_jc_n[7] = { 0, 0, 0, 1, 1, 1, 1 };

#define ac_der_basic_model_1_sm_ci_pr_n (1.0)

const int_T ac_der_basic_model_1_sm_circ_ir[2] = { 0, 0 };

const int_T ac_der_basic_model_1_sm_circ_jc[7] = { 0, 1, 1, 1, 2, 2, 2 };

const real_T ac_der_basic_model_1_sm_circ_pr[2] = { 1.0E-6, -1.0 };

/* Block signals (default storage) */
B_ac_der_basic_model_1_sm_circuit_T ac_der_basic_model_1_sm_circuit_B;

/* Continuous states */
X_ac_der_basic_model_1_sm_circuit_T ac_der_basic_model_1_sm_circuit_X;

/* Block states (default storage) */
DW_ac_der_basic_model_1_sm_circuit_T ac_der_basic_model_1_sm_circuit_DW;

/* Real-time model */
static RT_MODEL_ac_der_basic_model_1_sm_circuit_T
  ac_der_basic_model_1_sm_circuit_M_;
RT_MODEL_ac_der_basic_model_1_sm_circuit_T *const
  ac_der_basic_model_1_sm_circuit_M = &ac_der_basic_model_1_sm_circuit_M_;

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
  int_T nXc = 9;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ac_der_basic_model_1_sm_circuit_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ac_der_basic_model_1_sm_circuit_output();
  ac_der_basic_model_1_sm_circuit_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ac_der_basic_model_1_sm_circuit_output();
  ac_der_basic_model_1_sm_circuit_derivatives();

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

/*
 * System initialize for enable system:
 *    '<S6>/RMS '
 *    '<S7>/RMS '
 */
void ac_der_basic_model_1_s_RMS_Init(DW_RMS_ac_der_basic_model_1_s_T *localDW,
  P_RMS_ac_der_basic_model_1_sm_T *localP, X_RMS_ac_der_basic_model_1_sm_T
  *localX)
{
  /* InitializeConditions for Integrator: '<S24>/integrator' */
  localX->integrator_CSTATE_e = localP->integrator_IC;

  /* InitializeConditions for Memory: '<S24>/Memory' */
  localDW->Memory_PreviousInput = localP->Memory_InitialCondition;

  /* InitializeConditions for Integrator: '<S23>/integrator' */
  localX->integrator_CSTATE_n = localP->integrator_IC_o;

  /* InitializeConditions for Memory: '<S23>/Memory' */
  localDW->Memory_PreviousInput_i = localP->Memory_InitialCondition_l;
}

/*
 * Disable for enable system:
 *    '<S6>/RMS '
 *    '<S7>/RMS '
 */
void ac_der_basic_model__RMS_Disable(DW_RMS_ac_der_basic_model_1_s_T *localDW)
{
  localDW->RMS_MODE = false;
}

/*
 * Start for enable system:
 *    '<S6>/RMS '
 *    '<S7>/RMS '
 */
void ac_der_basic_model_1__RMS_Start(RT_MODEL_ac_der_basic_model_1_sm_circuit_T *
  const ac_der_basic_model_1_sm_circuit_M, DW_RMS_ac_der_basic_model_1_s_T
  *localDW, P_RMS_ac_der_basic_model_1_sm_T *localP)
{
  /* Start for TransportDelay: '<S24>/Transport Delay' */
  {
    real_T *pBuffer = &localDW->TransportDelay_RWORK.TUbufferArea[0];
    localDW->TransportDelay_IWORK.Tail = 0;
    localDW->TransportDelay_IWORK.Head = 0;
    localDW->TransportDelay_IWORK.Last = 0;
    localDW->TransportDelay_IWORK.CircularBufSize = 8192;
    pBuffer[0] = localP->TransportDelay_InitOutput;
    pBuffer[8192] = ac_der_basic_model_1_sm_circuit_M->Timing.t[0];
    localDW->TransportDelay_PWORK.TUbufferPtrs[0] = (void *) &pBuffer[0];
  }

  /* Start for TransportDelay: '<S23>/Transport Delay' */
  {
    real_T *pBuffer = &localDW->TransportDelay_RWORK_p.TUbufferArea[0];
    localDW->TransportDelay_IWORK_d.Tail = 0;
    localDW->TransportDelay_IWORK_d.Head = 0;
    localDW->TransportDelay_IWORK_d.Last = 0;
    localDW->TransportDelay_IWORK_d.CircularBufSize = 8192;
    pBuffer[0] = localP->TransportDelay_InitOutput_o;
    pBuffer[8192] = ac_der_basic_model_1_sm_circuit_M->Timing.t[0];
    localDW->TransportDelay_PWORK_f.TUbufferPtrs[0] = (void *) &pBuffer[0];
  }
}

/*
 * Outputs for enable system:
 *    '<S6>/RMS '
 *    '<S7>/RMS '
 */
void ac_der_basic_model_1_sm_cir_RMS(RT_MODEL_ac_der_basic_model_1_sm_circuit_T *
  const ac_der_basic_model_1_sm_circuit_M, boolean_T rtu_Enable, real_T rtu_In,
  B_RMS_ac_der_basic_model_1_sm_T *localB, DW_RMS_ac_der_basic_model_1_s_T
  *localDW, P_RMS_ac_der_basic_model_1_sm_T *localP,
  X_RMS_ac_der_basic_model_1_sm_T *localX)
{
  real_T tmp;

  /* Outputs for Enabled SubSystem: '<S6>/RMS ' incorporates:
   *  EnablePort: '<S18>/Enable'
   */
  if (rtmIsMajorTimeStep(ac_der_basic_model_1_sm_circuit_M) &&
      rtmIsMajorTimeStep(ac_der_basic_model_1_sm_circuit_M)) {
    if (rtu_Enable) {
      if (!localDW->RMS_MODE) {
        localDW->RMS_MODE = true;
      }
    } else if (localDW->RMS_MODE) {
      ac_der_basic_model__RMS_Disable(localDW);
    }
  }

  if (localDW->RMS_MODE) {
    /* Integrator: '<S24>/integrator' */
    localB->integrator = localX->integrator_CSTATE_e;

    /* TransportDelay: '<S24>/Transport Delay' */
    {
      real_T **uBuffer = (real_T**)&localDW->TransportDelay_PWORK.TUbufferPtrs[0];
      real_T simTime = ac_der_basic_model_1_sm_circuit_M->Timing.t[0];
      real_T tMinusDelay = simTime - (localP->TransportDelay_Delay);
      localB->TransportDelay = rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *uBuffer,
        localDW->TransportDelay_IWORK.CircularBufSize,
        &localDW->TransportDelay_IWORK.Last,
        localDW->TransportDelay_IWORK.Tail,
        localDW->TransportDelay_IWORK.Head,
        localP->TransportDelay_InitOutput,
        0,
        0);
    }

    /* Clock: '<S24>/Clock' */
    localB->Clock = ac_der_basic_model_1_sm_circuit_M->Timing.t[0];

    /* RelationalOperator: '<S24>/Relational Operator' incorporates:
     *  Constant: '<S24>/K1'
     */
    localB->RelationalOperator = (localB->Clock >= localP->K1_Value);
    if (rtmIsMajorTimeStep(ac_der_basic_model_1_sm_circuit_M)) {
      /* Memory: '<S24>/Memory' */
      localB->Memory = localDW->Memory_PreviousInput;
    }

    /* Switch: '<S24>/Switch' */
    if (localB->RelationalOperator) {
      /* Sum: '<S24>/Sum' */
      localB->Sum = localB->integrator - localB->TransportDelay;

      /* Gain: '<S24>/Gain' */
      localB->Gain_d = localP->Gain_Gain_m * localB->Sum;

      /* Switch: '<S24>/Switch' */
      localB->Switch = localB->Gain_d;
    } else {
      /* Switch: '<S24>/Switch' */
      localB->Switch = localB->Memory;
    }

    /* End of Switch: '<S24>/Switch' */

    /* Integrator: '<S23>/integrator' */
    localB->integrator_g = localX->integrator_CSTATE_n;

    /* TransportDelay: '<S23>/Transport Delay' */
    {
      real_T **uBuffer = (real_T**)&localDW->
        TransportDelay_PWORK_f.TUbufferPtrs[0];
      real_T simTime = ac_der_basic_model_1_sm_circuit_M->Timing.t[0];
      real_T tMinusDelay = simTime - (localP->TransportDelay_Delay_l);
      localB->TransportDelay_d = rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *uBuffer,
        localDW->TransportDelay_IWORK_d.CircularBufSize,
        &localDW->TransportDelay_IWORK_d.Last,
        localDW->TransportDelay_IWORK_d.Tail,
        localDW->TransportDelay_IWORK_d.Head,
        localP->TransportDelay_InitOutput_o,
        0,
        0);
    }

    /* Clock: '<S23>/Clock' */
    localB->Clock_i = ac_der_basic_model_1_sm_circuit_M->Timing.t[0];

    /* RelationalOperator: '<S23>/Relational Operator' incorporates:
     *  Constant: '<S23>/K1'
     */
    localB->RelationalOperator_j = (localB->Clock_i >= localP->K1_Value_g);
    if (rtmIsMajorTimeStep(ac_der_basic_model_1_sm_circuit_M)) {
      /* Memory: '<S23>/Memory' */
      localB->Memory_o = localDW->Memory_PreviousInput_i;
    }

    /* Switch: '<S23>/Switch' */
    if (localB->RelationalOperator_j) {
      /* Sum: '<S23>/Sum' */
      localB->Sum_o = localB->integrator_g - localB->TransportDelay_d;

      /* Gain: '<S23>/Gain' */
      localB->Gain_l = localP->Gain_Gain * localB->Sum_o;

      /* Switch: '<S23>/Switch' */
      localB->Switch_p = localB->Gain_l;
    } else {
      /* Switch: '<S23>/Switch' */
      localB->Switch_p = localB->Memory_o;
    }

    /* End of Switch: '<S23>/Switch' */

    /* RealImagToComplex: '<S20>/Real-Imag to Complex' */
    localB->RealImagtoComplex.re = localB->Switch;
    localB->RealImagtoComplex.im = localB->Switch_p;

    /* ComplexToMagnitudeAngle: '<S20>/Complex to Magnitude-Angle' incorporates:
     *  RealImagToComplex: '<S20>/Real-Imag to Complex'
     */
    localB->ComplextoMagnitudeAngle_o1 = rt_hypotd_snf
      (localB->RealImagtoComplex.re, localB->RealImagtoComplex.im);

    /* ComplexToMagnitudeAngle: '<S20>/Complex to Magnitude-Angle' incorporates:
     *  RealImagToComplex: '<S20>/Real-Imag to Complex'
     */
    localB->ComplextoMagnitudeAngle_o2 = rt_atan2d_snf
      (localB->RealImagtoComplex.im, localB->RealImagtoComplex.re);

    /* Sin: '<S20>/sin(wt)' */
    tmp = 2.0 * 3.1415926535897931 * localP->Fourier1_Freq;

    /* Sin: '<S20>/sin(wt)' */
    localB->sinwt = sin(tmp * ac_der_basic_model_1_sm_circuit_M->Timing.t[0] +
                        localP->sinwt_Phase) * localP->sinwt_Amp +
      localP->sinwt_Bias;

    /* Product: '<S20>/Product' */
    localB->Product = rtu_In * localB->sinwt;

    /* Sin: '<S20>/cos(wt)' */
    tmp = 2.0 * 3.1415926535897931 * localP->Fourier1_Freq;

    /* Sin: '<S20>/cos(wt)' */
    localB->coswt = sin(tmp * ac_der_basic_model_1_sm_circuit_M->Timing.t[0] +
                        localP->coswt_Phase) * localP->coswt_Amp +
      localP->coswt_Bias;

    /* Product: '<S20>/Product1' */
    localB->Product1 = rtu_In * localB->coswt;

    /* Gain: '<S20>/Rad->Deg.' */
    localB->RadDeg = localP->RadDeg_Gain * localB->ComplextoMagnitudeAngle_o2;

    /* Gain: '<S18>/Gain' */
    localB->Gain = localP->Gain_Gain_b * localB->ComplextoMagnitudeAngle_o1;
  }

  /* End of Outputs for SubSystem: '<S6>/RMS ' */
}

/*
 * Update for enable system:
 *    '<S6>/RMS '
 *    '<S7>/RMS '
 */
void ac_der_basic_model_1_RMS_Update(RT_MODEL_ac_der_basic_model_1_sm_circuit_T *
  const ac_der_basic_model_1_sm_circuit_M, B_RMS_ac_der_basic_model_1_sm_T
  *localB, DW_RMS_ac_der_basic_model_1_s_T *localDW)
{
  /* Update for Enabled SubSystem: '<S6>/RMS ' incorporates:
   *  EnablePort: '<S18>/Enable'
   */
  if (localDW->RMS_MODE) {
    /* Update for TransportDelay: '<S24>/Transport Delay' */
    {
      real_T **uBuffer = (real_T**)&localDW->TransportDelay_PWORK.TUbufferPtrs[0];
      real_T simTime = ac_der_basic_model_1_sm_circuit_M->Timing.t[0];
      localDW->TransportDelay_IWORK.Head = ((localDW->TransportDelay_IWORK.Head <
        (localDW->TransportDelay_IWORK.CircularBufSize-1)) ?
        (localDW->TransportDelay_IWORK.Head+1) : 0);
      if (localDW->TransportDelay_IWORK.Head ==
          localDW->TransportDelay_IWORK.Tail) {
        localDW->TransportDelay_IWORK.Tail =
          ((localDW->TransportDelay_IWORK.Tail <
            (localDW->TransportDelay_IWORK.CircularBufSize-1)) ?
           (localDW->TransportDelay_IWORK.Tail+1) : 0);
      }

      (*uBuffer + localDW->TransportDelay_IWORK.CircularBufSize)
        [localDW->TransportDelay_IWORK.Head] = simTime;
      (*uBuffer)[localDW->TransportDelay_IWORK.Head] = localB->integrator;
    }

    if (rtmIsMajorTimeStep(ac_der_basic_model_1_sm_circuit_M)) {
      /* Update for Memory: '<S24>/Memory' */
      localDW->Memory_PreviousInput = localB->Switch;
    }

    /* Update for TransportDelay: '<S23>/Transport Delay' */
    {
      real_T **uBuffer = (real_T**)&localDW->
        TransportDelay_PWORK_f.TUbufferPtrs[0];
      real_T simTime = ac_der_basic_model_1_sm_circuit_M->Timing.t[0];
      localDW->TransportDelay_IWORK_d.Head =
        ((localDW->TransportDelay_IWORK_d.Head <
          (localDW->TransportDelay_IWORK_d.CircularBufSize-1)) ?
         (localDW->TransportDelay_IWORK_d.Head+1) : 0);
      if (localDW->TransportDelay_IWORK_d.Head ==
          localDW->TransportDelay_IWORK_d.Tail) {
        localDW->TransportDelay_IWORK_d.Tail =
          ((localDW->TransportDelay_IWORK_d.Tail <
            (localDW->TransportDelay_IWORK_d.CircularBufSize-1)) ?
           (localDW->TransportDelay_IWORK_d.Tail+1) : 0);
      }

      (*uBuffer + localDW->TransportDelay_IWORK_d.CircularBufSize)
        [localDW->TransportDelay_IWORK_d.Head] = simTime;
      (*uBuffer)[localDW->TransportDelay_IWORK_d.Head] = localB->integrator_g;
    }

    if (rtmIsMajorTimeStep(ac_der_basic_model_1_sm_circuit_M)) {
      /* Update for Memory: '<S23>/Memory' */
      localDW->Memory_PreviousInput_i = localB->Switch_p;
    }
  }

  /* End of Update for SubSystem: '<S6>/RMS ' */
}

/*
 * Derivatives for enable system:
 *    '<S6>/RMS '
 *    '<S7>/RMS '
 */
void ac_der_basic_model_1__RMS_Deriv(B_RMS_ac_der_basic_model_1_sm_T *localB,
  DW_RMS_ac_der_basic_model_1_s_T *localDW, XDot_RMS_ac_der_basic_model_1_T
  *localXdot)
{
  if (localDW->RMS_MODE) {
    /* Derivatives for Integrator: '<S24>/integrator' */
    localXdot->integrator_CSTATE_e = localB->Product;

    /* Derivatives for Integrator: '<S23>/integrator' */
    localXdot->integrator_CSTATE_n = localB->Product1;
  } else {
    {
      real_T *dx;
      int_T i;
      dx = &(localXdot->integrator_CSTATE_e);
      for (i=0; i < 2; i++) {
        dx[i] = 0.0;
      }
    }
  }
}

/*
 * System initialize for enable system:
 *    '<S6>/TrueRMS '
 *    '<S7>/TrueRMS '
 */
void ac_der_basic_model_TrueRMS_Init(DW_TrueRMS_ac_der_basic_model_T *localDW,
  P_TrueRMS_ac_der_basic_model__T *localP, X_TrueRMS_ac_der_basic_model__T
  *localX)
{
  /* InitializeConditions for Integrator: '<S26>/integrator' */
  localX->integrator_CSTATE = localP->integrator_IC;

  /* InitializeConditions for Memory: '<S26>/Memory' */
  localDW->Memory_PreviousInput = localP->Memory_InitialCondition;
}

/*
 * Disable for enable system:
 *    '<S6>/TrueRMS '
 *    '<S7>/TrueRMS '
 */
void ac_der_basic_mo_TrueRMS_Disable(DW_TrueRMS_ac_der_basic_model_T *localDW)
{
  localDW->TrueRMS_MODE = false;
}

/*
 * Start for enable system:
 *    '<S6>/TrueRMS '
 *    '<S7>/TrueRMS '
 */
void ac_der_basic_mode_TrueRMS_Start(RT_MODEL_ac_der_basic_model_1_sm_circuit_T *
  const ac_der_basic_model_1_sm_circuit_M, DW_TrueRMS_ac_der_basic_model_T
  *localDW, P_TrueRMS_ac_der_basic_model__T *localP)
{
  /* Start for TransportDelay: '<S26>/Transport Delay' */
  {
    real_T *pBuffer = &localDW->TransportDelay_RWORK.TUbufferArea[0];
    localDW->TransportDelay_IWORK.Tail = 0;
    localDW->TransportDelay_IWORK.Head = 0;
    localDW->TransportDelay_IWORK.Last = 0;
    localDW->TransportDelay_IWORK.CircularBufSize = 8192;
    pBuffer[0] = localP->TransportDelay_InitOutput;
    pBuffer[8192] = ac_der_basic_model_1_sm_circuit_M->Timing.t[0];
    localDW->TransportDelay_PWORK.TUbufferPtrs[0] = (void *) &pBuffer[0];
  }
}

/*
 * Outputs for enable system:
 *    '<S6>/TrueRMS '
 *    '<S7>/TrueRMS '
 */
void ac_der_basic_model_1_sm_TrueRMS(RT_MODEL_ac_der_basic_model_1_sm_circuit_T *
  const ac_der_basic_model_1_sm_circuit_M, boolean_T rtu_Enable, real_T rtu_In,
  B_TrueRMS_ac_der_basic_model__T *localB, DW_TrueRMS_ac_der_basic_model_T
  *localDW, P_TrueRMS_ac_der_basic_model__T *localP,
  X_TrueRMS_ac_der_basic_model__T *localX)
{
  real_T u0;
  real_T u1;
  real_T u2;

  /* Outputs for Enabled SubSystem: '<S6>/TrueRMS ' incorporates:
   *  EnablePort: '<S19>/Enable'
   */
  if (rtmIsMajorTimeStep(ac_der_basic_model_1_sm_circuit_M) &&
      rtmIsMajorTimeStep(ac_der_basic_model_1_sm_circuit_M)) {
    if (rtu_Enable) {
      if (!localDW->TrueRMS_MODE) {
        localDW->TrueRMS_MODE = true;
      }
    } else if (localDW->TrueRMS_MODE) {
      ac_der_basic_mo_TrueRMS_Disable(localDW);
    }
  }

  if (localDW->TrueRMS_MODE) {
    /* Clock: '<S26>/Clock' */
    localB->Clock = ac_der_basic_model_1_sm_circuit_M->Timing.t[0];

    /* Integrator: '<S26>/integrator' */
    localB->integrator = localX->integrator_CSTATE;

    /* TransportDelay: '<S26>/Transport Delay' */
    {
      real_T **uBuffer = (real_T**)&localDW->TransportDelay_PWORK.TUbufferPtrs[0];
      real_T simTime = ac_der_basic_model_1_sm_circuit_M->Timing.t[0];
      real_T tMinusDelay = simTime - (localP->TransportDelay_Delay);
      localB->TransportDelay = rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *uBuffer,
        localDW->TransportDelay_IWORK.CircularBufSize,
        &localDW->TransportDelay_IWORK.Last,
        localDW->TransportDelay_IWORK.Tail,
        localDW->TransportDelay_IWORK.Head,
        localP->TransportDelay_InitOutput,
        0,
        0);
    }

    if (rtmIsMajorTimeStep(ac_der_basic_model_1_sm_circuit_M)) {
      /* Memory: '<S26>/Memory' */
      localB->Memory = localDW->Memory_PreviousInput;
    }

    /* RelationalOperator: '<S26>/Relational Operator' incorporates:
     *  Constant: '<S26>/K1'
     */
    localB->RelationalOperator = (localB->Clock >= localP->K1_Value);

    /* Switch: '<S26>/Switch' */
    if (localB->RelationalOperator) {
      /* Sum: '<S26>/Sum' */
      localB->Sum = localB->integrator - localB->TransportDelay;

      /* Gain: '<S26>/Gain' */
      localB->Gain = localP->Gain_Gain * localB->Sum;

      /* Switch: '<S26>/Switch' */
      localB->Switch = localB->Gain;
    } else {
      /* Switch: '<S26>/Switch' */
      localB->Switch = localB->Memory;
    }

    /* End of Switch: '<S26>/Switch' */

    /* Product: '<S19>/Product' */
    localB->Product = rtu_In * rtu_In;

    /* Saturate: '<S19>/Saturation to avoid negative sqrt' */
    u0 = localB->Switch;
    u1 = localP->Saturationtoavoidnegativesqrt_L;
    u2 = localP->Saturationtoavoidnegativesqrt_U;
    if (u0 > u2) {
      /* Saturate: '<S19>/Saturation to avoid negative sqrt' */
      localB->Saturationtoavoidnegativesqrt = u2;
    } else if (u0 < u1) {
      /* Saturate: '<S19>/Saturation to avoid negative sqrt' */
      localB->Saturationtoavoidnegativesqrt = u1;
    } else {
      /* Saturate: '<S19>/Saturation to avoid negative sqrt' */
      localB->Saturationtoavoidnegativesqrt = u0;
    }

    /* End of Saturate: '<S19>/Saturation to avoid negative sqrt' */

    /* Sqrt: '<S19>/Sqrt' */
    localB->Sqrt = sqrt(localB->Saturationtoavoidnegativesqrt);
  }

  /* End of Outputs for SubSystem: '<S6>/TrueRMS ' */
}

/*
 * Update for enable system:
 *    '<S6>/TrueRMS '
 *    '<S7>/TrueRMS '
 */
void ac_der_basic_mod_TrueRMS_Update(RT_MODEL_ac_der_basic_model_1_sm_circuit_T *
  const ac_der_basic_model_1_sm_circuit_M, B_TrueRMS_ac_der_basic_model__T
  *localB, DW_TrueRMS_ac_der_basic_model_T *localDW)
{
  /* Update for Enabled SubSystem: '<S6>/TrueRMS ' incorporates:
   *  EnablePort: '<S19>/Enable'
   */
  if (localDW->TrueRMS_MODE) {
    /* Update for TransportDelay: '<S26>/Transport Delay' */
    {
      real_T **uBuffer = (real_T**)&localDW->TransportDelay_PWORK.TUbufferPtrs[0];
      real_T simTime = ac_der_basic_model_1_sm_circuit_M->Timing.t[0];
      localDW->TransportDelay_IWORK.Head = ((localDW->TransportDelay_IWORK.Head <
        (localDW->TransportDelay_IWORK.CircularBufSize-1)) ?
        (localDW->TransportDelay_IWORK.Head+1) : 0);
      if (localDW->TransportDelay_IWORK.Head ==
          localDW->TransportDelay_IWORK.Tail) {
        localDW->TransportDelay_IWORK.Tail =
          ((localDW->TransportDelay_IWORK.Tail <
            (localDW->TransportDelay_IWORK.CircularBufSize-1)) ?
           (localDW->TransportDelay_IWORK.Tail+1) : 0);
      }

      (*uBuffer + localDW->TransportDelay_IWORK.CircularBufSize)
        [localDW->TransportDelay_IWORK.Head] = simTime;
      (*uBuffer)[localDW->TransportDelay_IWORK.Head] = localB->integrator;
    }

    if (rtmIsMajorTimeStep(ac_der_basic_model_1_sm_circuit_M)) {
      /* Update for Memory: '<S26>/Memory' */
      localDW->Memory_PreviousInput = localB->Switch;
    }
  }

  /* End of Update for SubSystem: '<S6>/TrueRMS ' */
}

/*
 * Derivatives for enable system:
 *    '<S6>/TrueRMS '
 *    '<S7>/TrueRMS '
 */
void ac_der_basic_mode_TrueRMS_Deriv(B_TrueRMS_ac_der_basic_model__T *localB,
  DW_TrueRMS_ac_der_basic_model_T *localDW, XDot_TrueRMS_ac_der_basic_mod_T
  *localXdot)
{
  if (localDW->TrueRMS_MODE) {
    /* Derivatives for Integrator: '<S26>/integrator' */
    localXdot->integrator_CSTATE = localB->Product;
  } else {
    localXdot->integrator_CSTATE = 0.0;
  }
}

/* Model output function */
void ac_der_basic_model_1_sm_circuit_output(void)
{
  real_T u[6];
  real_T u_0[6];
  int_T c;
  int_T k;
  boolean_T first_output;
  static const int_T jc[7] = { 0, 1, 1, 1, 2, 2, 2 };

  static const int_T jc_0[7] = { 0, 0, 0, 1, 1, 1, 1 };

  static const real_T pr = 1.0;
  static const real_T pr_0[2] = { 1.0E-6, -1.0 };

  real_T u_1;
  if (rtmIsMajorTimeStep(ac_der_basic_model_1_sm_circuit_M)) {
    /* set solver stop time */
    if (!(ac_der_basic_model_1_sm_circuit_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ac_der_basic_model_1_sm_circuit_M->solverInfo,
                            ((ac_der_basic_model_1_sm_circuit_M->Timing.clockTickH0
        + 1) * ac_der_basic_model_1_sm_circuit_M->Timing.stepSize0 *
        4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ac_der_basic_model_1_sm_circuit_M->solverInfo,
                            ((ac_der_basic_model_1_sm_circuit_M->Timing.clockTick0
        + 1) * ac_der_basic_model_1_sm_circuit_M->Timing.stepSize0 +
        ac_der_basic_model_1_sm_circuit_M->Timing.clockTickH0 *
        ac_der_basic_model_1_sm_circuit_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ac_der_basic_model_1_sm_circuit_M)) {
    ac_der_basic_model_1_sm_circuit_M->Timing.t[0] = rtsiGetT
      (&ac_der_basic_model_1_sm_circuit_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ac_der_basic_model_1_sm_circuit_M)) {
    /* Memory: '<S1>/S-Function' */
    ac_der_basic_model_1_sm_circuit_B.SFunction =
      ac_der_basic_model_1_sm_circuit_DW.SFunction_PreviousInput;

    /* Sum: '<S1>/Sum' incorporates:
     *  Constant: '<S1>/S-Function1'
     */
    ac_der_basic_model_1_sm_circuit_B.Sum =
      ac_der_basic_model_1_sm_circuit_P.SFunction1_Value +
      ac_der_basic_model_1_sm_circuit_B.SFunction;

    /* Stop: '<S1>/Stop Simulation' */
    if (ac_der_basic_model_1_sm_circuit_B.Sum != 0.0) {
      rtmSetStopRequested(ac_der_basic_model_1_sm_circuit_M, 1);
    }

    /* End of Stop: '<S1>/Stop Simulation' */

    /* S-Function (RECV_Param): '<S12>/S-Function' */

    /* Level2 S-Function Block: '<S12>/S-Function' (RECV_Param) */
    {
      SimStruct *rts = ac_der_basic_model_1_sm_circuit_M->childSfunctions[0];
      sfcnOutputs(rts,0);
    }

    /* Signum: '<S2>/Sign' */
    u_1 = ac_der_basic_model_1_sm_circuit_B.SFunction_c[0];
    if (u_1 < 0.0) {
      /* Signum: '<S2>/Sign' */
      ac_der_basic_model_1_sm_circuit_B.Sign = -1.0;
    } else if (u_1 > 0.0) {
      /* Signum: '<S2>/Sign' */
      ac_der_basic_model_1_sm_circuit_B.Sign = 1.0;
    } else if (u_1 == 0.0) {
      /* Signum: '<S2>/Sign' */
      ac_der_basic_model_1_sm_circuit_B.Sign = 0.0;
    } else {
      /* Signum: '<S2>/Sign' */
      ac_der_basic_model_1_sm_circuit_B.Sign = u_1;
    }

    /* End of Signum: '<S2>/Sign' */

    /* Product: '<S2>/Product1' incorporates:
     *  Constant: '<S2>/Constant'
     */
    ac_der_basic_model_1_sm_circuit_B.Product1 =
      ac_der_basic_model_1_sm_circuit_B.SFunction_c[1] *
      ac_der_basic_model_1_sm_circuit_P.Constant_Value;
  }

  /* Sin: '<S2>/Sine Wave1' */
  ac_der_basic_model_1_sm_circuit_B.SineWave1 = sin
    (ac_der_basic_model_1_sm_circuit_P.SineWave1_Freq *
     ac_der_basic_model_1_sm_circuit_M->Timing.t[0] +
     ac_der_basic_model_1_sm_circuit_P.SineWave1_Phase) *
    ac_der_basic_model_1_sm_circuit_P.SineWave1_Amp +
    ac_der_basic_model_1_sm_circuit_P.SineWave1_Bias;

  /* Sin: '<S2>/Sine Wave2' */
  ac_der_basic_model_1_sm_circuit_B.SineWave2 = sin
    (ac_der_basic_model_1_sm_circuit_P.SineWave2_Freq *
     ac_der_basic_model_1_sm_circuit_M->Timing.t[0] +
     ac_der_basic_model_1_sm_circuit_P.SineWave2_Phase) *
    ac_der_basic_model_1_sm_circuit_P.SineWave2_Amp +
    ac_der_basic_model_1_sm_circuit_P.SineWave2_Bias;

  /* Sin: '<S2>/Sine Wave3' */
  ac_der_basic_model_1_sm_circuit_B.SineWave3 = sin
    (ac_der_basic_model_1_sm_circuit_P.SineWave3_Freq *
     ac_der_basic_model_1_sm_circuit_M->Timing.t[0] +
     ac_der_basic_model_1_sm_circuit_P.SineWave3_Phase) *
    ac_der_basic_model_1_sm_circuit_P.SineWave3_Amp +
    ac_der_basic_model_1_sm_circuit_P.SineWave3_Bias;

  /* Product: '<S2>/Product2' */
  ac_der_basic_model_1_sm_circuit_B.Product2[0] =
    ac_der_basic_model_1_sm_circuit_B.Product1 *
    ac_der_basic_model_1_sm_circuit_B.SineWave1;
  ac_der_basic_model_1_sm_circuit_B.Product2[1] =
    ac_der_basic_model_1_sm_circuit_B.Product1 *
    ac_der_basic_model_1_sm_circuit_B.SineWave2;
  ac_der_basic_model_1_sm_circuit_B.Product2[2] =
    ac_der_basic_model_1_sm_circuit_B.Product1 *
    ac_der_basic_model_1_sm_circuit_B.SineWave3;

  /* SimscapeInputBlock: '<S38>/INPUT_1_1_1' */
  first_output = false;
  if (ac_der_basic_model_1_sm_circuit_DW.INPUT_1_1_1_FirstOutput == 0.0) {
    ac_der_basic_model_1_sm_circuit_DW.INPUT_1_1_1_FirstOutput = 1.0;
    first_output = true;
  }

  if (first_output) {
    ac_der_basic_model_1_sm_circuit_X.ac_der_basic_model_1_sm_circuit = 1.0 *
      ac_der_basic_model_1_sm_circuit_B.Product2[0] + 0.0;
  }

  ac_der_basic_model_1_sm_circuit_B.INPUT_1_1_1[0] =
    ac_der_basic_model_1_sm_circuit_X.ac_der_basic_model_1_sm_circuit;
  ac_der_basic_model_1_sm_circuit_B.INPUT_1_1_1[1] = 1000.0 * ((1.0 *
    ac_der_basic_model_1_sm_circuit_B.Product2[0] + 0.0) -
    ac_der_basic_model_1_sm_circuit_X.ac_der_basic_model_1_sm_circuit);
  ac_der_basic_model_1_sm_circuit_B.INPUT_1_1_1[2] = 0.0;
  ac_der_basic_model_1_sm_circuit_B.INPUT_1_1_1[3] = 0.0;

  /* End of SimscapeInputBlock: '<S38>/INPUT_1_1_1' */
  if (rtmIsMajorTimeStep(ac_der_basic_model_1_sm_circuit_M)) {
    /* Product: '<S2>/Product3' incorporates:
     *  Constant: '<S2>/Constant1'
     *  Constant: '<S2>/Constant2'
     */
    ac_der_basic_model_1_sm_circuit_B.Product3 =
      ac_der_basic_model_1_sm_circuit_B.SFunction_c[0] *
      ac_der_basic_model_1_sm_circuit_P.Constant1_Value *
      ac_der_basic_model_1_sm_circuit_P.Constant2_Value;

    /* Delay: '<S2>/Delay' */
    ac_der_basic_model_1_sm_circuit_B.Delay =
      ac_der_basic_model_1_sm_circuit_DW.Delay_DSTATE;

    /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
     *  Constant: '<S7>/Constant'
     */
    ac_der_basic_model_1_sm_circuit_B.DataTypeConversion =
      (ac_der_basic_model_1_sm_circuit_P.RMS2_TrueRMS != 0.0);
  }

  /* Sin: '<S2>/Sine Wave4' */
  ac_der_basic_model_1_sm_circuit_B.SineWave4 = sin
    (ac_der_basic_model_1_sm_circuit_P.SineWave4_Freq *
     ac_der_basic_model_1_sm_circuit_M->Timing.t[0] +
     ac_der_basic_model_1_sm_circuit_P.SineWave4_Phase) *
    ac_der_basic_model_1_sm_circuit_P.SineWave4_Amp +
    ac_der_basic_model_1_sm_circuit_P.SineWave4_Bias;

  /* Sin: '<S2>/Sine Wave5' */
  ac_der_basic_model_1_sm_circuit_B.SineWave5 = sin
    (ac_der_basic_model_1_sm_circuit_P.SineWave5_Freq *
     ac_der_basic_model_1_sm_circuit_M->Timing.t[0] +
     ac_der_basic_model_1_sm_circuit_P.SineWave5_Phase) *
    ac_der_basic_model_1_sm_circuit_P.SineWave5_Amp +
    ac_der_basic_model_1_sm_circuit_P.SineWave5_Bias;

  /* Sin: '<S2>/Sine Wave6' */
  ac_der_basic_model_1_sm_circuit_B.SineWave6 = sin
    (ac_der_basic_model_1_sm_circuit_P.SineWave6_Freq *
     ac_der_basic_model_1_sm_circuit_M->Timing.t[0] +
     ac_der_basic_model_1_sm_circuit_P.SineWave6_Phase) *
    ac_der_basic_model_1_sm_circuit_P.SineWave6_Amp +
    ac_der_basic_model_1_sm_circuit_P.SineWave6_Bias;

  /* Outputs for Enabled SubSystem: '<S7>/TrueRMS ' */
  ac_der_basic_model_1_sm_TrueRMS(ac_der_basic_model_1_sm_circuit_M,
    ac_der_basic_model_1_sm_circuit_B.DataTypeConversion,
    ac_der_basic_model_1_sm_circuit_B.Delay,
    &ac_der_basic_model_1_sm_circuit_B.TrueRMS_f,
    &ac_der_basic_model_1_sm_circuit_DW.TrueRMS_f,
    &ac_der_basic_model_1_sm_circuit_P.TrueRMS_f,
    &ac_der_basic_model_1_sm_circuit_X.TrueRMS_f);

  /* End of Outputs for SubSystem: '<S7>/TrueRMS ' */
  if (rtmIsMajorTimeStep(ac_der_basic_model_1_sm_circuit_M)) {
    /* Logic: '<S7>/Logical Operator' */
    ac_der_basic_model_1_sm_circuit_B.LogicalOperator =
      !ac_der_basic_model_1_sm_circuit_B.DataTypeConversion;
  }

  /* Outputs for Enabled SubSystem: '<S7>/RMS ' */
  ac_der_basic_model_1_sm_cir_RMS(ac_der_basic_model_1_sm_circuit_M,
    ac_der_basic_model_1_sm_circuit_B.LogicalOperator,
    ac_der_basic_model_1_sm_circuit_B.Delay,
    &ac_der_basic_model_1_sm_circuit_B.RMS_l,
    &ac_der_basic_model_1_sm_circuit_DW.RMS_l,
    &ac_der_basic_model_1_sm_circuit_P.RMS_l,
    &ac_der_basic_model_1_sm_circuit_X.RMS_l);

  /* End of Outputs for SubSystem: '<S7>/RMS ' */

  /* Switch: '<S7>/Switch' */
  if (ac_der_basic_model_1_sm_circuit_B.DataTypeConversion) {
    /* Switch: '<S7>/Switch' */
    ac_der_basic_model_1_sm_circuit_B.Switch =
      ac_der_basic_model_1_sm_circuit_B.TrueRMS_f.Sqrt;
  } else {
    /* Switch: '<S7>/Switch' */
    ac_der_basic_model_1_sm_circuit_B.Switch =
      ac_der_basic_model_1_sm_circuit_B.RMS_l.Gain;
  }

  /* End of Switch: '<S7>/Switch' */

  /* Product: '<S2>/Divide' */
  ac_der_basic_model_1_sm_circuit_B.Divide[0] =
    ac_der_basic_model_1_sm_circuit_B.SineWave4 /
    ac_der_basic_model_1_sm_circuit_B.Switch;
  ac_der_basic_model_1_sm_circuit_B.Divide[1] =
    ac_der_basic_model_1_sm_circuit_B.SineWave5 /
    ac_der_basic_model_1_sm_circuit_B.Switch;
  ac_der_basic_model_1_sm_circuit_B.Divide[2] =
    ac_der_basic_model_1_sm_circuit_B.SineWave6 /
    ac_der_basic_model_1_sm_circuit_B.Switch;

  /* Product: '<S2>/Product6' */
  ac_der_basic_model_1_sm_circuit_B.Product6[0] =
    ac_der_basic_model_1_sm_circuit_B.Product3 *
    ac_der_basic_model_1_sm_circuit_B.Divide[0];
  ac_der_basic_model_1_sm_circuit_B.Product6[1] =
    ac_der_basic_model_1_sm_circuit_B.Product3 *
    ac_der_basic_model_1_sm_circuit_B.Divide[1];
  ac_der_basic_model_1_sm_circuit_B.Product6[2] =
    ac_der_basic_model_1_sm_circuit_B.Product3 *
    ac_der_basic_model_1_sm_circuit_B.Divide[2];

  /* SimscapeInputBlock: '<S38>/INPUT_2_1_1' */
  ac_der_basic_model_1_sm_circuit_B.INPUT_2_1_1[0] = 1.0 *
    ac_der_basic_model_1_sm_circuit_B.Product6[0] + 0.0;
  ac_der_basic_model_1_sm_circuit_B.INPUT_2_1_1[1] = 0.0;
  ac_der_basic_model_1_sm_circuit_B.INPUT_2_1_1[2] = 0.0;
  ac_der_basic_model_1_sm_circuit_B.INPUT_2_1_1[3] = 0.0;

  /* SimscapeLtiOutput: '<S38>/LTI_OUTPUT_1_1' */
  ac_der_basic_model_1_sm_circuit_B.LTI_OUTPUT_1_1 = 0.0;

  /* SimscapeLtiOutput: '<S38>/LTI_OUTPUT_1_1' */
  u[0] = ac_der_basic_model_1_sm_circuit_B.INPUT_1_1_1[0];
  u[1] = 0.0;
  u[2] = 0.0;
  u[3] = ac_der_basic_model_1_sm_circuit_B.INPUT_2_1_1[0];
  u[4] = 0.0;
  u[5] = 0.0;
  for (c = 0; c < 6; c = c + 1) {
    for (k = jc[c]; k < jc[c + 1]; k = k + 1) {
      /* SimscapeLtiOutput: '<S38>/LTI_OUTPUT_1_1' */
      ac_der_basic_model_1_sm_circuit_B.LTI_OUTPUT_1_1 =
        ac_der_basic_model_1_sm_circuit_B.LTI_OUTPUT_1_1 + pr_0[k] * u[c];
    }
  }

  if (rtmIsMajorTimeStep(ac_der_basic_model_1_sm_circuit_M)) {
    /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
     *  Constant: '<S6>/Constant'
     */
    ac_der_basic_model_1_sm_circuit_B.DataTypeConversion_n =
      (ac_der_basic_model_1_sm_circuit_P.RMS1_TrueRMS != 0.0);
  }

  /* Outputs for Enabled SubSystem: '<S6>/TrueRMS ' */
  ac_der_basic_model_1_sm_TrueRMS(ac_der_basic_model_1_sm_circuit_M,
    ac_der_basic_model_1_sm_circuit_B.DataTypeConversion_n,
    ac_der_basic_model_1_sm_circuit_B.LTI_OUTPUT_1_1,
    &ac_der_basic_model_1_sm_circuit_B.TrueRMS,
    &ac_der_basic_model_1_sm_circuit_DW.TrueRMS,
    &ac_der_basic_model_1_sm_circuit_P.TrueRMS,
    &ac_der_basic_model_1_sm_circuit_X.TrueRMS);

  /* End of Outputs for SubSystem: '<S6>/TrueRMS ' */
  if (rtmIsMajorTimeStep(ac_der_basic_model_1_sm_circuit_M)) {
    /* Logic: '<S6>/Logical Operator' */
    ac_der_basic_model_1_sm_circuit_B.LogicalOperator_l =
      !ac_der_basic_model_1_sm_circuit_B.DataTypeConversion_n;
  }

  /* Outputs for Enabled SubSystem: '<S6>/RMS ' */
  ac_der_basic_model_1_sm_cir_RMS(ac_der_basic_model_1_sm_circuit_M,
    ac_der_basic_model_1_sm_circuit_B.LogicalOperator_l,
    ac_der_basic_model_1_sm_circuit_B.LTI_OUTPUT_1_1,
    &ac_der_basic_model_1_sm_circuit_B.RMS,
    &ac_der_basic_model_1_sm_circuit_DW.RMS,
    &ac_der_basic_model_1_sm_circuit_P.RMS,
    &ac_der_basic_model_1_sm_circuit_X.RMS);

  /* End of Outputs for SubSystem: '<S6>/RMS ' */

  /* Switch: '<S6>/Switch' */
  if (ac_der_basic_model_1_sm_circuit_B.DataTypeConversion_n) {
    /* Switch: '<S6>/Switch' */
    ac_der_basic_model_1_sm_circuit_B.Switch_c =
      ac_der_basic_model_1_sm_circuit_B.TrueRMS.Sqrt;
  } else {
    /* Switch: '<S6>/Switch' */
    ac_der_basic_model_1_sm_circuit_B.Switch_c =
      ac_der_basic_model_1_sm_circuit_B.RMS.Gain;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Product: '<S2>/Product4' incorporates:
   *  Constant: '<S2>/Constant3'
   */
  ac_der_basic_model_1_sm_circuit_B.Product4 =
    ac_der_basic_model_1_sm_circuit_B.Sign *
    ac_der_basic_model_1_sm_circuit_B.Switch_c *
    ac_der_basic_model_1_sm_circuit_P.Constant3_Value;
  if (rtmIsMajorTimeStep(ac_der_basic_model_1_sm_circuit_M)) {
    /* S-Function (OP_SEND): '<S40>/S-Function' */

    /* Level2 S-Function Block: '<S40>/S-Function' (OP_SEND) */
    {
      SimStruct *rts = ac_der_basic_model_1_sm_circuit_M->childSfunctions[1];
      sfcnOutputs(rts,0);
    }
  }

  /* SimscapeInputBlock: '<S38>/INPUT_1_1_2' */
  first_output = false;
  if (ac_der_basic_model_1_sm_circuit_DW.INPUT_1_1_2_FirstOutput == 0.0) {
    ac_der_basic_model_1_sm_circuit_DW.INPUT_1_1_2_FirstOutput = 1.0;
    first_output = true;
  }

  if (first_output) {
    ac_der_basic_model_1_sm_circuit_X.ac_der_basic_model_1_sm_circu_c = 1.0 *
      ac_der_basic_model_1_sm_circuit_B.Product2[1] + 0.0;
  }

  ac_der_basic_model_1_sm_circuit_B.INPUT_1_1_2[0] =
    ac_der_basic_model_1_sm_circuit_X.ac_der_basic_model_1_sm_circu_c;
  ac_der_basic_model_1_sm_circuit_B.INPUT_1_1_2[1] = 1000.0 * ((1.0 *
    ac_der_basic_model_1_sm_circuit_B.Product2[1] + 0.0) -
    ac_der_basic_model_1_sm_circuit_X.ac_der_basic_model_1_sm_circu_c);
  ac_der_basic_model_1_sm_circuit_B.INPUT_1_1_2[2] = 0.0;
  ac_der_basic_model_1_sm_circuit_B.INPUT_1_1_2[3] = 0.0;

  /* End of SimscapeInputBlock: '<S38>/INPUT_1_1_2' */

  /* SimscapeInputBlock: '<S38>/INPUT_1_1_3' */
  first_output = false;
  if (ac_der_basic_model_1_sm_circuit_DW.INPUT_1_1_3_FirstOutput == 0.0) {
    ac_der_basic_model_1_sm_circuit_DW.INPUT_1_1_3_FirstOutput = 1.0;
    first_output = true;
  }

  if (first_output) {
    ac_der_basic_model_1_sm_circuit_X.ac_der_basic_model_1_sm_circu_m = 1.0 *
      ac_der_basic_model_1_sm_circuit_B.Product2[2] + 0.0;
  }

  ac_der_basic_model_1_sm_circuit_B.INPUT_1_1_3[0] =
    ac_der_basic_model_1_sm_circuit_X.ac_der_basic_model_1_sm_circu_m;
  ac_der_basic_model_1_sm_circuit_B.INPUT_1_1_3[1] = 1000.0 * ((1.0 *
    ac_der_basic_model_1_sm_circuit_B.Product2[2] + 0.0) -
    ac_der_basic_model_1_sm_circuit_X.ac_der_basic_model_1_sm_circu_m);
  ac_der_basic_model_1_sm_circuit_B.INPUT_1_1_3[2] = 0.0;
  ac_der_basic_model_1_sm_circuit_B.INPUT_1_1_3[3] = 0.0;

  /* End of SimscapeInputBlock: '<S38>/INPUT_1_1_3' */

  /* SimscapeInputBlock: '<S38>/INPUT_2_1_2' */
  ac_der_basic_model_1_sm_circuit_B.INPUT_2_1_2[0] = 1.0 *
    ac_der_basic_model_1_sm_circuit_B.Product6[1] + 0.0;
  ac_der_basic_model_1_sm_circuit_B.INPUT_2_1_2[1] = 0.0;
  ac_der_basic_model_1_sm_circuit_B.INPUT_2_1_2[2] = 0.0;
  ac_der_basic_model_1_sm_circuit_B.INPUT_2_1_2[3] = 0.0;

  /* SimscapeInputBlock: '<S38>/INPUT_2_1_3' */
  ac_der_basic_model_1_sm_circuit_B.INPUT_2_1_3[0] = 1.0 *
    ac_der_basic_model_1_sm_circuit_B.Product6[2] + 0.0;
  ac_der_basic_model_1_sm_circuit_B.INPUT_2_1_3[1] = 0.0;
  ac_der_basic_model_1_sm_circuit_B.INPUT_2_1_3[2] = 0.0;
  ac_der_basic_model_1_sm_circuit_B.INPUT_2_1_3[3] = 0.0;

  /* SimscapeLtiOutput: '<S38>/LTI_OUTPUT_1_2' */
  ac_der_basic_model_1_sm_circuit_B.LTI_OUTPUT_1_2 = -0.0;

  /* SimscapeLtiOutput: '<S38>/LTI_OUTPUT_1_2' */
  u_0[0] = 0.0;
  u_0[1] = 0.0;
  u_0[2] = ac_der_basic_model_1_sm_circuit_B.INPUT_1_1_3[0];
  u_0[3] = 0.0;
  u_0[4] = 0.0;
  u_0[5] = 0.0;
  for (c = 0; c < 6; c = c + 1) {
    for (k = jc_0[c]; k < jc_0[c + 1]; k = k + 1) {
      /* SimscapeLtiOutput: '<S38>/LTI_OUTPUT_1_2' */
      ac_der_basic_model_1_sm_circuit_B.LTI_OUTPUT_1_2 =
        ac_der_basic_model_1_sm_circuit_B.LTI_OUTPUT_1_2 + pr * u_0[c];
    }
  }
}

/* Model update function */
void ac_der_basic_model_1_sm_circuit_update(void)
{
  if (rtmIsMajorTimeStep(ac_der_basic_model_1_sm_circuit_M)) {
    /* Update for Memory: '<S1>/S-Function' */
    ac_der_basic_model_1_sm_circuit_DW.SFunction_PreviousInput =
      ac_der_basic_model_1_sm_circuit_B.Sum;

    /* Update for Delay: '<S2>/Delay' */
    ac_der_basic_model_1_sm_circuit_DW.Delay_DSTATE =
      ac_der_basic_model_1_sm_circuit_B.LTI_OUTPUT_1_2;
  }

  /* Update for Enabled SubSystem: '<S7>/TrueRMS ' */
  ac_der_basic_mod_TrueRMS_Update(ac_der_basic_model_1_sm_circuit_M,
    &ac_der_basic_model_1_sm_circuit_B.TrueRMS_f,
    &ac_der_basic_model_1_sm_circuit_DW.TrueRMS_f);

  /* End of Update for SubSystem: '<S7>/TrueRMS ' */

  /* Update for Enabled SubSystem: '<S7>/RMS ' */
  ac_der_basic_model_1_RMS_Update(ac_der_basic_model_1_sm_circuit_M,
    &ac_der_basic_model_1_sm_circuit_B.RMS_l,
    &ac_der_basic_model_1_sm_circuit_DW.RMS_l);

  /* End of Update for SubSystem: '<S7>/RMS ' */

  /* Update for Enabled SubSystem: '<S6>/TrueRMS ' */
  ac_der_basic_mod_TrueRMS_Update(ac_der_basic_model_1_sm_circuit_M,
    &ac_der_basic_model_1_sm_circuit_B.TrueRMS,
    &ac_der_basic_model_1_sm_circuit_DW.TrueRMS);

  /* End of Update for SubSystem: '<S6>/TrueRMS ' */

  /* Update for Enabled SubSystem: '<S6>/RMS ' */
  ac_der_basic_model_1_RMS_Update(ac_der_basic_model_1_sm_circuit_M,
    &ac_der_basic_model_1_sm_circuit_B.RMS,
    &ac_der_basic_model_1_sm_circuit_DW.RMS);

  /* End of Update for SubSystem: '<S6>/RMS ' */
  if (rtmIsMajorTimeStep(ac_der_basic_model_1_sm_circuit_M)) {
    rt_ertODEUpdateContinuousStates
      (&ac_der_basic_model_1_sm_circuit_M->solverInfo);
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
  if (!(++ac_der_basic_model_1_sm_circuit_M->Timing.clockTick0)) {
    ++ac_der_basic_model_1_sm_circuit_M->Timing.clockTickH0;
  }

  ac_der_basic_model_1_sm_circuit_M->Timing.t[0] = rtsiGetSolverStopTime
    (&ac_der_basic_model_1_sm_circuit_M->solverInfo);

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
    if (!(++ac_der_basic_model_1_sm_circuit_M->Timing.clockTick1)) {
      ++ac_der_basic_model_1_sm_circuit_M->Timing.clockTickH1;
    }

    ac_der_basic_model_1_sm_circuit_M->Timing.t[1] =
      ac_der_basic_model_1_sm_circuit_M->Timing.clockTick1 *
      ac_der_basic_model_1_sm_circuit_M->Timing.stepSize1 +
      ac_der_basic_model_1_sm_circuit_M->Timing.clockTickH1 *
      ac_der_basic_model_1_sm_circuit_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ac_der_basic_model_1_sm_circuit_derivatives(void)
{
  XDot_ac_der_basic_model_1_sm_circuit_T *_rtXdot;
  _rtXdot = ((XDot_ac_der_basic_model_1_sm_circuit_T *)
             ac_der_basic_model_1_sm_circuit_M->ModelData.derivs);

  /* Derivatives for SimscapeInputBlock: '<S38>/INPUT_1_1_1' */
  _rtXdot->ac_der_basic_model_1_sm_circuit = 1000.0 * ((1.0 *
    ac_der_basic_model_1_sm_circuit_B.Product2[0] + 0.0) -
    ac_der_basic_model_1_sm_circuit_X.ac_der_basic_model_1_sm_circuit);

  /* Derivatives for Enabled SubSystem: '<S7>/TrueRMS ' */
  ac_der_basic_mode_TrueRMS_Deriv(&ac_der_basic_model_1_sm_circuit_B.TrueRMS_f,
    &ac_der_basic_model_1_sm_circuit_DW.TrueRMS_f, &_rtXdot->TrueRMS_f);

  /* End of Derivatives for SubSystem: '<S7>/TrueRMS ' */

  /* Derivatives for Enabled SubSystem: '<S7>/RMS ' */
  ac_der_basic_model_1__RMS_Deriv(&ac_der_basic_model_1_sm_circuit_B.RMS_l,
    &ac_der_basic_model_1_sm_circuit_DW.RMS_l, &_rtXdot->RMS_l);

  /* End of Derivatives for SubSystem: '<S7>/RMS ' */

  /* Derivatives for Enabled SubSystem: '<S6>/TrueRMS ' */
  ac_der_basic_mode_TrueRMS_Deriv(&ac_der_basic_model_1_sm_circuit_B.TrueRMS,
    &ac_der_basic_model_1_sm_circuit_DW.TrueRMS, &_rtXdot->TrueRMS);

  /* End of Derivatives for SubSystem: '<S6>/TrueRMS ' */

  /* Derivatives for Enabled SubSystem: '<S6>/RMS ' */
  ac_der_basic_model_1__RMS_Deriv(&ac_der_basic_model_1_sm_circuit_B.RMS,
    &ac_der_basic_model_1_sm_circuit_DW.RMS, &_rtXdot->RMS);

  /* End of Derivatives for SubSystem: '<S6>/RMS ' */

  /* Derivatives for SimscapeInputBlock: '<S38>/INPUT_1_1_2' */
  _rtXdot->ac_der_basic_model_1_sm_circu_c = 1000.0 * ((1.0 *
    ac_der_basic_model_1_sm_circuit_B.Product2[1] + 0.0) -
    ac_der_basic_model_1_sm_circuit_X.ac_der_basic_model_1_sm_circu_c);

  /* Derivatives for SimscapeInputBlock: '<S38>/INPUT_1_1_3' */
  _rtXdot->ac_der_basic_model_1_sm_circu_m = 1000.0 * ((1.0 *
    ac_der_basic_model_1_sm_circuit_B.Product2[2] + 0.0) -
    ac_der_basic_model_1_sm_circuit_X.ac_der_basic_model_1_sm_circu_m);
}

/* Model initialize function */
void ac_der_basic_model_1_sm_circuit_initialize(void)
{
  /* Start for Enabled SubSystem: '<S7>/TrueRMS ' */
  ac_der_basic_mode_TrueRMS_Start(ac_der_basic_model_1_sm_circuit_M,
    &ac_der_basic_model_1_sm_circuit_DW.TrueRMS_f,
    &ac_der_basic_model_1_sm_circuit_P.TrueRMS_f);

  /* End of Start for SubSystem: '<S7>/TrueRMS ' */

  /* Start for Enabled SubSystem: '<S7>/RMS ' */
  ac_der_basic_model_1__RMS_Start(ac_der_basic_model_1_sm_circuit_M,
    &ac_der_basic_model_1_sm_circuit_DW.RMS_l,
    &ac_der_basic_model_1_sm_circuit_P.RMS_l);

  /* End of Start for SubSystem: '<S7>/RMS ' */

  /* Start for Enabled SubSystem: '<S6>/TrueRMS ' */
  ac_der_basic_mode_TrueRMS_Start(ac_der_basic_model_1_sm_circuit_M,
    &ac_der_basic_model_1_sm_circuit_DW.TrueRMS,
    &ac_der_basic_model_1_sm_circuit_P.TrueRMS);

  /* End of Start for SubSystem: '<S6>/TrueRMS ' */

  /* Start for Enabled SubSystem: '<S6>/RMS ' */
  ac_der_basic_model_1__RMS_Start(ac_der_basic_model_1_sm_circuit_M,
    &ac_der_basic_model_1_sm_circuit_DW.RMS,
    &ac_der_basic_model_1_sm_circuit_P.RMS);

  /* End of Start for SubSystem: '<S6>/RMS ' */

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
  ac_der_basic_model_1_sm_circuit_DW.SFunction_PreviousInput =
    ac_der_basic_model_1_sm_circuit_P.SFunction_InitialCondition;

  /* InitializeConditions for S-Function (RECV_Param): '<S12>/S-Function' */
  /* Level2 S-Function Block: '<S12>/S-Function' (RECV_Param) */
  {
    SimStruct *rts = ac_der_basic_model_1_sm_circuit_M->childSfunctions[0];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for Delay: '<S2>/Delay' */
  ac_der_basic_model_1_sm_circuit_DW.Delay_DSTATE =
    ac_der_basic_model_1_sm_circuit_P.Delay_InitialCondition;

  /* InitializeConditions for S-Function (OP_SEND): '<S40>/S-Function' */
  /* Level2 S-Function Block: '<S40>/S-Function' (OP_SEND) */
  {
    SimStruct *rts = ac_der_basic_model_1_sm_circuit_M->childSfunctions[1];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* SystemInitialize for Enabled SubSystem: '<S7>/TrueRMS ' */
  ac_der_basic_model_TrueRMS_Init(&ac_der_basic_model_1_sm_circuit_DW.TrueRMS_f,
    &ac_der_basic_model_1_sm_circuit_P.TrueRMS_f,
    &ac_der_basic_model_1_sm_circuit_X.TrueRMS_f);

  /* End of SystemInitialize for SubSystem: '<S7>/TrueRMS ' */

  /* SystemInitialize for Enabled SubSystem: '<S7>/RMS ' */
  ac_der_basic_model_1_s_RMS_Init(&ac_der_basic_model_1_sm_circuit_DW.RMS_l,
    &ac_der_basic_model_1_sm_circuit_P.RMS_l,
    &ac_der_basic_model_1_sm_circuit_X.RMS_l);

  /* End of SystemInitialize for SubSystem: '<S7>/RMS ' */

  /* SystemInitialize for Enabled SubSystem: '<S6>/TrueRMS ' */
  ac_der_basic_model_TrueRMS_Init(&ac_der_basic_model_1_sm_circuit_DW.TrueRMS,
    &ac_der_basic_model_1_sm_circuit_P.TrueRMS,
    &ac_der_basic_model_1_sm_circuit_X.TrueRMS);

  /* End of SystemInitialize for SubSystem: '<S6>/TrueRMS ' */

  /* SystemInitialize for Enabled SubSystem: '<S6>/RMS ' */
  ac_der_basic_model_1_s_RMS_Init(&ac_der_basic_model_1_sm_circuit_DW.RMS,
    &ac_der_basic_model_1_sm_circuit_P.RMS,
    &ac_der_basic_model_1_sm_circuit_X.RMS);

  /* End of SystemInitialize for SubSystem: '<S6>/RMS ' */
}

/* Model terminate function */
void ac_der_basic_model_1_sm_circuit_terminate(void)
{
  /* Terminate for S-Function (RECV_Param): '<S12>/S-Function' */
  /* Level2 S-Function Block: '<S12>/S-Function' (RECV_Param) */
  {
    SimStruct *rts = ac_der_basic_model_1_sm_circuit_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (OP_SEND): '<S40>/S-Function' */
  /* Level2 S-Function Block: '<S40>/S-Function' (OP_SEND) */
  {
    SimStruct *rts = ac_der_basic_model_1_sm_circuit_M->childSfunctions[1];
    sfcnTerminate(rts);
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
  ac_der_basic_model_1_sm_circuit_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ac_der_basic_model_1_sm_circuit_update();
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
  ac_der_basic_model_1_sm_circuit_initialize();
}

void MdlTerminate(void)
{
  ac_der_basic_model_1_sm_circuit_terminate();
}

/* Registration function */
RT_MODEL_ac_der_basic_model_1_sm_circuit_T *ac_der_basic_model_1_sm_circuit(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  ac_der_basic_model_1_sm_circuit_P.TrueRMS_f.Saturationtoavoidnegativesqrt_U =
    rtInf;
  ac_der_basic_model_1_sm_circuit_P.TrueRMS.Saturationtoavoidnegativesqrt_U =
    rtInf;

  /* initialize real-time model */
  (void) memset((void *)ac_der_basic_model_1_sm_circuit_M, 0,
                sizeof(RT_MODEL_ac_der_basic_model_1_sm_circuit_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ac_der_basic_model_1_sm_circuit_M->solverInfo,
                          &ac_der_basic_model_1_sm_circuit_M->Timing.simTimeStep);
    rtsiSetTPtr(&ac_der_basic_model_1_sm_circuit_M->solverInfo, &rtmGetTPtr
                (ac_der_basic_model_1_sm_circuit_M));
    rtsiSetStepSizePtr(&ac_der_basic_model_1_sm_circuit_M->solverInfo,
                       &ac_der_basic_model_1_sm_circuit_M->Timing.stepSize0);
    rtsiSetdXPtr(&ac_der_basic_model_1_sm_circuit_M->solverInfo,
                 &ac_der_basic_model_1_sm_circuit_M->ModelData.derivs);
    rtsiSetContStatesPtr(&ac_der_basic_model_1_sm_circuit_M->solverInfo, (real_T
      **) &ac_der_basic_model_1_sm_circuit_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&ac_der_basic_model_1_sm_circuit_M->solverInfo,
      &ac_der_basic_model_1_sm_circuit_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr
      (&ac_der_basic_model_1_sm_circuit_M->solverInfo,
       &ac_der_basic_model_1_sm_circuit_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&ac_der_basic_model_1_sm_circuit_M->solverInfo,
       &ac_der_basic_model_1_sm_circuit_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&ac_der_basic_model_1_sm_circuit_M->solverInfo,
       &ac_der_basic_model_1_sm_circuit_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&ac_der_basic_model_1_sm_circuit_M->solverInfo,
                          (&rtmGetErrorStatus(ac_der_basic_model_1_sm_circuit_M)));
    rtsiSetRTModelPtr(&ac_der_basic_model_1_sm_circuit_M->solverInfo,
                      ac_der_basic_model_1_sm_circuit_M);
  }

  rtsiSetSimTimeStep(&ac_der_basic_model_1_sm_circuit_M->solverInfo,
                     MAJOR_TIME_STEP);
  ac_der_basic_model_1_sm_circuit_M->ModelData.intgData.y =
    ac_der_basic_model_1_sm_circuit_M->ModelData.odeY;
  ac_der_basic_model_1_sm_circuit_M->ModelData.intgData.f[0] =
    ac_der_basic_model_1_sm_circuit_M->ModelData.odeF[0];
  ac_der_basic_model_1_sm_circuit_M->ModelData.intgData.f[1] =
    ac_der_basic_model_1_sm_circuit_M->ModelData.odeF[1];
  ac_der_basic_model_1_sm_circuit_M->ModelData.intgData.f[2] =
    ac_der_basic_model_1_sm_circuit_M->ModelData.odeF[2];
  ac_der_basic_model_1_sm_circuit_M->ModelData.contStates = ((real_T *)
    &ac_der_basic_model_1_sm_circuit_X);
  rtsiSetSolverData(&ac_der_basic_model_1_sm_circuit_M->solverInfo, (void *)
                    &ac_der_basic_model_1_sm_circuit_M->ModelData.intgData);
  rtsiSetSolverName(&ac_der_basic_model_1_sm_circuit_M->solverInfo,"ode3");
  ac_der_basic_model_1_sm_circuit_M->solverInfoPtr =
    (&ac_der_basic_model_1_sm_circuit_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      ac_der_basic_model_1_sm_circuit_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "ac_der_basic_model_1_sm_circuit_M points to
       static memory which is guaranteed to be non-NULL" */
    ac_der_basic_model_1_sm_circuit_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ac_der_basic_model_1_sm_circuit_M->Timing.sampleTimes =
      (&ac_der_basic_model_1_sm_circuit_M->Timing.sampleTimesArray[0]);
    ac_der_basic_model_1_sm_circuit_M->Timing.offsetTimes =
      (&ac_der_basic_model_1_sm_circuit_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ac_der_basic_model_1_sm_circuit_M->Timing.sampleTimes[0] = (0.0);
    ac_der_basic_model_1_sm_circuit_M->Timing.sampleTimes[1] = (0.0001);

    /* task offsets */
    ac_der_basic_model_1_sm_circuit_M->Timing.offsetTimes[0] = (0.0);
    ac_der_basic_model_1_sm_circuit_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ac_der_basic_model_1_sm_circuit_M,
             &ac_der_basic_model_1_sm_circuit_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      ac_der_basic_model_1_sm_circuit_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ac_der_basic_model_1_sm_circuit_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ac_der_basic_model_1_sm_circuit_M, 0.1);
  ac_der_basic_model_1_sm_circuit_M->Timing.stepSize0 = 0.0001;
  ac_der_basic_model_1_sm_circuit_M->Timing.stepSize1 = 0.0001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    ac_der_basic_model_1_sm_circuit_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ac_der_basic_model_1_sm_circuit_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ac_der_basic_model_1_sm_circuit_M->rtwLogInfo, (NULL));
    rtliSetLogT(ac_der_basic_model_1_sm_circuit_M->rtwLogInfo, "");
    rtliSetLogX(ac_der_basic_model_1_sm_circuit_M->rtwLogInfo, "");
    rtliSetLogXFinal(ac_der_basic_model_1_sm_circuit_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ac_der_basic_model_1_sm_circuit_M->rtwLogInfo,
      "rt_");
    rtliSetLogFormat(ac_der_basic_model_1_sm_circuit_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ac_der_basic_model_1_sm_circuit_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ac_der_basic_model_1_sm_circuit_M->rtwLogInfo, 1);
    rtliSetLogY(ac_der_basic_model_1_sm_circuit_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ac_der_basic_model_1_sm_circuit_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ac_der_basic_model_1_sm_circuit_M->rtwLogInfo, (NULL));
  }

  ac_der_basic_model_1_sm_circuit_M->solverInfoPtr =
    (&ac_der_basic_model_1_sm_circuit_M->solverInfo);
  ac_der_basic_model_1_sm_circuit_M->Timing.stepSize = (0.0001);
  rtsiSetFixedStepSize(&ac_der_basic_model_1_sm_circuit_M->solverInfo, 0.0001);
  rtsiSetSolverMode(&ac_der_basic_model_1_sm_circuit_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ac_der_basic_model_1_sm_circuit_M->ModelData.blockIO = ((void *)
    &ac_der_basic_model_1_sm_circuit_B);
  (void) memset(((void *) &ac_der_basic_model_1_sm_circuit_B), 0,
                sizeof(B_ac_der_basic_model_1_sm_circuit_T));

  {
    ac_der_basic_model_1_sm_circuit_B.SFunction = 0.0;
    ac_der_basic_model_1_sm_circuit_B.Sum = 0.0;
    ac_der_basic_model_1_sm_circuit_B.SFunction_c[0] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.SFunction_c[1] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.Sign = 0.0;
    ac_der_basic_model_1_sm_circuit_B.Product1 = 0.0;
    ac_der_basic_model_1_sm_circuit_B.SineWave1 = 0.0;
    ac_der_basic_model_1_sm_circuit_B.SineWave2 = 0.0;
    ac_der_basic_model_1_sm_circuit_B.SineWave3 = 0.0;
    ac_der_basic_model_1_sm_circuit_B.Product2[0] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.Product2[1] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.Product2[2] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.INPUT_1_1_1[0] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.INPUT_1_1_1[1] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.INPUT_1_1_1[2] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.INPUT_1_1_1[3] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.Product3 = 0.0;
    ac_der_basic_model_1_sm_circuit_B.SineWave4 = 0.0;
    ac_der_basic_model_1_sm_circuit_B.SineWave5 = 0.0;
    ac_der_basic_model_1_sm_circuit_B.SineWave6 = 0.0;
    ac_der_basic_model_1_sm_circuit_B.Delay = 0.0;
    ac_der_basic_model_1_sm_circuit_B.Switch = 0.0;
    ac_der_basic_model_1_sm_circuit_B.Divide[0] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.Divide[1] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.Divide[2] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.Product6[0] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.Product6[1] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.Product6[2] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.INPUT_2_1_1[0] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.INPUT_2_1_1[1] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.INPUT_2_1_1[2] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.INPUT_2_1_1[3] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.LTI_OUTPUT_1_1 = 0.0;
    ac_der_basic_model_1_sm_circuit_B.Switch_c = 0.0;
    ac_der_basic_model_1_sm_circuit_B.Product4 = 0.0;
    ac_der_basic_model_1_sm_circuit_B.INPUT_1_1_2[0] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.INPUT_1_1_2[1] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.INPUT_1_1_2[2] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.INPUT_1_1_2[3] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.INPUT_1_1_3[0] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.INPUT_1_1_3[1] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.INPUT_1_1_3[2] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.INPUT_1_1_3[3] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.INPUT_2_1_2[0] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.INPUT_2_1_2[1] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.INPUT_2_1_2[2] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.INPUT_2_1_2[3] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.INPUT_2_1_3[0] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.INPUT_2_1_3[1] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.INPUT_2_1_3[2] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.INPUT_2_1_3[3] = 0.0;
    ac_der_basic_model_1_sm_circuit_B.LTI_OUTPUT_1_2 = 0.0;
    ac_der_basic_model_1_sm_circuit_B.TrueRMS_f.Clock = 0.0;
    ac_der_basic_model_1_sm_circuit_B.TrueRMS_f.integrator = 0.0;
    ac_der_basic_model_1_sm_circuit_B.TrueRMS_f.TransportDelay = 0.0;
    ac_der_basic_model_1_sm_circuit_B.TrueRMS_f.Memory = 0.0;
    ac_der_basic_model_1_sm_circuit_B.TrueRMS_f.Switch = 0.0;
    ac_der_basic_model_1_sm_circuit_B.TrueRMS_f.Product = 0.0;
    ac_der_basic_model_1_sm_circuit_B.TrueRMS_f.Saturationtoavoidnegativesqrt =
      0.0;
    ac_der_basic_model_1_sm_circuit_B.TrueRMS_f.Sqrt = 0.0;
    ac_der_basic_model_1_sm_circuit_B.TrueRMS_f.Sum = 0.0;
    ac_der_basic_model_1_sm_circuit_B.TrueRMS_f.Gain = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS_l.RealImagtoComplex.re = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS_l.RealImagtoComplex.im = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS_l.integrator = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS_l.TransportDelay = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS_l.Clock = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS_l.Memory = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS_l.Switch = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS_l.integrator_g = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS_l.TransportDelay_d = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS_l.Clock_i = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS_l.Memory_o = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS_l.Switch_p = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS_l.ComplextoMagnitudeAngle_o1 = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS_l.ComplextoMagnitudeAngle_o2 = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS_l.sinwt = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS_l.Product = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS_l.coswt = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS_l.Product1 = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS_l.RadDeg = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS_l.Gain = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS_l.Sum = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS_l.Gain_d = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS_l.Sum_o = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS_l.Gain_l = 0.0;
    ac_der_basic_model_1_sm_circuit_B.TrueRMS.Clock = 0.0;
    ac_der_basic_model_1_sm_circuit_B.TrueRMS.integrator = 0.0;
    ac_der_basic_model_1_sm_circuit_B.TrueRMS.TransportDelay = 0.0;
    ac_der_basic_model_1_sm_circuit_B.TrueRMS.Memory = 0.0;
    ac_der_basic_model_1_sm_circuit_B.TrueRMS.Switch = 0.0;
    ac_der_basic_model_1_sm_circuit_B.TrueRMS.Product = 0.0;
    ac_der_basic_model_1_sm_circuit_B.TrueRMS.Saturationtoavoidnegativesqrt =
      0.0;
    ac_der_basic_model_1_sm_circuit_B.TrueRMS.Sqrt = 0.0;
    ac_der_basic_model_1_sm_circuit_B.TrueRMS.Sum = 0.0;
    ac_der_basic_model_1_sm_circuit_B.TrueRMS.Gain = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS.RealImagtoComplex.re = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS.RealImagtoComplex.im = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS.integrator = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS.TransportDelay = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS.Clock = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS.Memory = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS.Switch = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS.integrator_g = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS.TransportDelay_d = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS.Clock_i = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS.Memory_o = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS.Switch_p = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS.ComplextoMagnitudeAngle_o1 = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS.ComplextoMagnitudeAngle_o2 = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS.sinwt = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS.Product = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS.coswt = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS.Product1 = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS.RadDeg = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS.Gain = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS.Sum = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS.Gain_d = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS.Sum_o = 0.0;
    ac_der_basic_model_1_sm_circuit_B.RMS.Gain_l = 0.0;
  }

  /* parameters */
  ac_der_basic_model_1_sm_circuit_M->ModelData.defaultParam = ((real_T *)
    &ac_der_basic_model_1_sm_circuit_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ac_der_basic_model_1_sm_circuit_X;
    ac_der_basic_model_1_sm_circuit_M->ModelData.contStates = (x);
    (void) memset((void *)&ac_der_basic_model_1_sm_circuit_X, 0,
                  sizeof(X_ac_der_basic_model_1_sm_circuit_T));
  }

  /* states (dwork) */
  ac_der_basic_model_1_sm_circuit_M->ModelData.dwork = ((void *)
    &ac_der_basic_model_1_sm_circuit_DW);
  (void) memset((void *)&ac_der_basic_model_1_sm_circuit_DW, 0,
                sizeof(DW_ac_der_basic_model_1_sm_circuit_T));
  ac_der_basic_model_1_sm_circuit_DW.INPUT_1_1_1_Discrete = 0.0;
  ac_der_basic_model_1_sm_circuit_DW.INPUT_1_1_1_FirstOutput = 0.0;
  ac_der_basic_model_1_sm_circuit_DW.Delay_DSTATE = 0.0;
  ac_der_basic_model_1_sm_circuit_DW.INPUT_2_1_1_Discrete[0] = 0.0;
  ac_der_basic_model_1_sm_circuit_DW.INPUT_2_1_1_Discrete[1] = 0.0;
  ac_der_basic_model_1_sm_circuit_DW.LTI_STATE_1_FirstOutput = 0.0;
  ac_der_basic_model_1_sm_circuit_DW.INPUT_1_1_2_Discrete = 0.0;
  ac_der_basic_model_1_sm_circuit_DW.INPUT_1_1_2_FirstOutput = 0.0;
  ac_der_basic_model_1_sm_circuit_DW.INPUT_1_1_3_Discrete = 0.0;
  ac_der_basic_model_1_sm_circuit_DW.INPUT_1_1_3_FirstOutput = 0.0;
  ac_der_basic_model_1_sm_circuit_DW.INPUT_2_1_2_Discrete[0] = 0.0;
  ac_der_basic_model_1_sm_circuit_DW.INPUT_2_1_2_Discrete[1] = 0.0;
  ac_der_basic_model_1_sm_circuit_DW.INPUT_2_1_3_Discrete[0] = 0.0;
  ac_der_basic_model_1_sm_circuit_DW.INPUT_2_1_3_Discrete[1] = 0.0;
  ac_der_basic_model_1_sm_circuit_DW.SFunction_PreviousInput = 0.0;
  ac_der_basic_model_1_sm_circuit_DW.TrueRMS_f.Memory_PreviousInput = 0.0;
  ac_der_basic_model_1_sm_circuit_DW.TrueRMS_f.TransportDelay_RWORK.modelTStart =
    0.0;

  {
    int32_T i;
    for (i = 0; i < 16384; i++) {
      ac_der_basic_model_1_sm_circuit_DW.TrueRMS_f.TransportDelay_RWORK.TUbufferArea
        [i] = 0.0;
    }
  }

  ac_der_basic_model_1_sm_circuit_DW.RMS_l.Memory_PreviousInput = 0.0;
  ac_der_basic_model_1_sm_circuit_DW.RMS_l.Memory_PreviousInput_i = 0.0;
  ac_der_basic_model_1_sm_circuit_DW.RMS_l.TransportDelay_RWORK.modelTStart =
    0.0;

  {
    int32_T i;
    for (i = 0; i < 16384; i++) {
      ac_der_basic_model_1_sm_circuit_DW.RMS_l.TransportDelay_RWORK.TUbufferArea[
        i] = 0.0;
    }
  }

  ac_der_basic_model_1_sm_circuit_DW.RMS_l.TransportDelay_RWORK_p.modelTStart =
    0.0;

  {
    int32_T i;
    for (i = 0; i < 16384; i++) {
      ac_der_basic_model_1_sm_circuit_DW.RMS_l.TransportDelay_RWORK_p.TUbufferArea
        [i] = 0.0;
    }
  }

  ac_der_basic_model_1_sm_circuit_DW.TrueRMS.Memory_PreviousInput = 0.0;
  ac_der_basic_model_1_sm_circuit_DW.TrueRMS.TransportDelay_RWORK.modelTStart =
    0.0;

  {
    int32_T i;
    for (i = 0; i < 16384; i++) {
      ac_der_basic_model_1_sm_circuit_DW.TrueRMS.TransportDelay_RWORK.TUbufferArea
        [i] = 0.0;
    }
  }

  ac_der_basic_model_1_sm_circuit_DW.RMS.Memory_PreviousInput = 0.0;
  ac_der_basic_model_1_sm_circuit_DW.RMS.Memory_PreviousInput_i = 0.0;
  ac_der_basic_model_1_sm_circuit_DW.RMS.TransportDelay_RWORK.modelTStart = 0.0;

  {
    int32_T i;
    for (i = 0; i < 16384; i++) {
      ac_der_basic_model_1_sm_circuit_DW.RMS.TransportDelay_RWORK.TUbufferArea[i]
        = 0.0;
    }
  }

  ac_der_basic_model_1_sm_circuit_DW.RMS.TransportDelay_RWORK_p.modelTStart =
    0.0;

  {
    int32_T i;
    for (i = 0; i < 16384; i++) {
      ac_der_basic_model_1_sm_circuit_DW.RMS.TransportDelay_RWORK_p.TUbufferArea[
        i] = 0.0;
    }
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo =
      &ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.sfcnInfo;
    ac_der_basic_model_1_sm_circuit_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus
      (ac_der_basic_model_1_sm_circuit_M)));
    ac_der_basic_model_1_sm_circuit_M->Sizes.numSampTimes = (2);
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &ac_der_basic_model_1_sm_circuit_M->Sizes.numSampTimes);
    ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.taskTimePtrs[0] =
      &(rtmGetTPtr(ac_der_basic_model_1_sm_circuit_M)[0]);
    ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.taskTimePtrs[1] =
      &(rtmGetTPtr(ac_der_basic_model_1_sm_circuit_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,
                   ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(ac_der_basic_model_1_sm_circuit_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(ac_der_basic_model_1_sm_circuit_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (ac_der_basic_model_1_sm_circuit_M));
    rtssSetStepSizePtr(sfcnInfo,
                       &ac_der_basic_model_1_sm_circuit_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (ac_der_basic_model_1_sm_circuit_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &ac_der_basic_model_1_sm_circuit_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &ac_der_basic_model_1_sm_circuit_M->ModelData.zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &ac_der_basic_model_1_sm_circuit_M->ModelData.CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo,
                         &ac_der_basic_model_1_sm_circuit_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &ac_der_basic_model_1_sm_circuit_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &ac_der_basic_model_1_sm_circuit_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo,
                         &ac_der_basic_model_1_sm_circuit_M->solverInfoPtr);
  }

  ac_der_basic_model_1_sm_circuit_M->Sizes.numSFcns = (2);

  /* register each child */
  {
    (void) memset((void *)
                  &ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.childSFunctions
                  [0], 0,
                  2*sizeof(SimStruct));
    ac_der_basic_model_1_sm_circuit_M->childSfunctions =
      (&ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    ac_der_basic_model_1_sm_circuit_M->childSfunctions[0] =
      (&ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.childSFunctions[0]);
    ac_der_basic_model_1_sm_circuit_M->childSfunctions[1] =
      (&ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.childSFunctions[1]);

    /* Level2 S-Function Block: ac_der_basic_model_1_sm_circuit/<S12>/S-Function (RECV_Param) */
    {
      SimStruct *rts = ac_der_basic_model_1_sm_circuit_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.blkInfo2
                         [0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &ac_der_basic_model_1_sm_circuit_M->
        NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, ac_der_basic_model_1_sm_circuit_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.methods2
                           [0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.methods3
                           [0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.methods4
                           [0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &ac_der_basic_model_1_sm_circuit_M->
          NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.Sfcn0.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.Sfcn0.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            ac_der_basic_model_1_sm_circuit_B.SFunction_c));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "ac_der_basic_model_1_sm_circuit/sm_circuit/OpComm1/Receive/S-Function");
      ssSetRTModel(rts,ac_der_basic_model_1_sm_circuit_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       ac_der_basic_model_1_sm_circuit_P.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       ac_der_basic_model_1_sm_circuit_P.SFunction_P2_Size);
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

    /* Level2 S-Function Block: ac_der_basic_model_1_sm_circuit/<S40>/S-Function (OP_SEND) */
    {
      SimStruct *rts = ac_der_basic_model_1_sm_circuit_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.blkInfo2
                         [1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &ac_der_basic_model_1_sm_circuit_M->
        NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, ac_der_basic_model_1_sm_circuit_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.methods2
                           [1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.methods3
                           [1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.methods4
                           [1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.statesInfo2
                         [1]);
        ssSetPeriodicStatesInfo(rts,
          &ac_der_basic_model_1_sm_circuit_M->
          NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &ac_der_basic_model_1_sm_circuit_B.Product4;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "ac_der_basic_model_1_sm_circuit/sm_circuit/rtlab_send_subsystem/Subsystem1/Send1/S-Function");
      ssSetRTModel(rts,ac_der_basic_model_1_sm_circuit_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       ac_der_basic_model_1_sm_circuit_P.SFunction_P1_Size_a);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *)
                 &ac_der_basic_model_1_sm_circuit_DW.SFunction_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &ac_der_basic_model_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 5);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &ac_der_basic_model_1_sm_circuit_DW.SFunction_IWORK[0]);
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
      ssSetInputPortWidth(rts, 0, 1);
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
  ac_der_basic_model_1_sm_circuit_M->Sizes.numContStates = (9);/* Number of continuous states */
  ac_der_basic_model_1_sm_circuit_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  ac_der_basic_model_1_sm_circuit_M->Sizes.numY = (0);/* Number of model outputs */
  ac_der_basic_model_1_sm_circuit_M->Sizes.numU = (0);/* Number of model inputs */
  ac_der_basic_model_1_sm_circuit_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ac_der_basic_model_1_sm_circuit_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ac_der_basic_model_1_sm_circuit_M->Sizes.numBlocks = (98);/* Number of blocks */
  ac_der_basic_model_1_sm_circuit_M->Sizes.numBlockIO = (103);/* Number of block outputs */
  ac_der_basic_model_1_sm_circuit_M->Sizes.numBlockPrms = (101);/* Sum of parameter "widths" */
  return ac_der_basic_model_1_sm_circuit_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
