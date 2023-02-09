/*
 * ssc_bridge_rectifier_1_sm_circuit.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ssc_bridge_rectifier_1_sm_circuit".
 *
 * Model version              : 13.1
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Mon Jan  9 14:34:02 2023
 *
 * Target selection: rtlab_rtmodel.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ssc_bridge_rectifier_1_sm_circuit.h"
#include "ssc_bridge_rectifier_1_sm_circuit_private.h"

/* Block signals (default storage) */
B_ssc_bridge_rectifier_1_sm_circuit_T ssc_bridge_rectifier_1_sm_circuit_B;

/* Continuous states */
X_ssc_bridge_rectifier_1_sm_circuit_T ssc_bridge_rectifier_1_sm_circuit_X;

/* Block states (default storage) */
DW_ssc_bridge_rectifier_1_sm_circuit_T ssc_bridge_rectifier_1_sm_circuit_DW;

/* Real-time model */
static RT_MODEL_ssc_bridge_rectifier_1_sm_circuit_T
  ssc_bridge_rectifier_1_sm_circuit_M_;
RT_MODEL_ssc_bridge_rectifier_1_sm_circuit_T *const
  ssc_bridge_rectifier_1_sm_circuit_M = &ssc_bridge_rectifier_1_sm_circuit_M_;

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
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ssc_bridge_rectifier_1_sm_circuit_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ssc_bridge_rectifier_1_sm_circuit_output();
  ssc_bridge_rectifier_1_sm_circuit_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ssc_bridge_rectifier_1_sm_circuit_output();
  ssc_bridge_rectifier_1_sm_circuit_derivatives();

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

/* Model output function */
void ssc_bridge_rectifier_1_sm_circuit_output(void)
{
  NeParameterBundle parameterBundle;
  NeslRtpManager *rtpManager;
  NeslSimulationData *simulationData;
  NeslSimulator *simulator;
  NeuDiagnosticManager *diag;
  NeuDiagnosticTree *diagTree;
  char *msg;
  real_T tmp_2[15];
  real_T tmp_0[4];
  real_T time;
  real_T time_0;
  real_T tmp;
  int_T tmp_3[3];
  int_T tmp_1[2];
  int_T j;
  boolean_T ok;
  if (rtmIsMajorTimeStep(ssc_bridge_rectifier_1_sm_circuit_M)) {
    /* set solver stop time */
    if (!(ssc_bridge_rectifier_1_sm_circuit_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ssc_bridge_rectifier_1_sm_circuit_M->solverInfo,
                            ((ssc_bridge_rectifier_1_sm_circuit_M->Timing.clockTickH0
        + 1) * ssc_bridge_rectifier_1_sm_circuit_M->Timing.stepSize0 *
        4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ssc_bridge_rectifier_1_sm_circuit_M->solverInfo,
                            ((ssc_bridge_rectifier_1_sm_circuit_M->Timing.clockTick0
        + 1) * ssc_bridge_rectifier_1_sm_circuit_M->Timing.stepSize0 +
        ssc_bridge_rectifier_1_sm_circuit_M->Timing.clockTickH0 *
        ssc_bridge_rectifier_1_sm_circuit_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ssc_bridge_rectifier_1_sm_circuit_M)) {
    ssc_bridge_rectifier_1_sm_circuit_M->Timing.t[0] = rtsiGetT
      (&ssc_bridge_rectifier_1_sm_circuit_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ssc_bridge_rectifier_1_sm_circuit_M)) {
    /* Memory: '<S1>/S-Function' */
    ssc_bridge_rectifier_1_sm_circuit_B.SFunction =
      ssc_bridge_rectifier_1_sm_circuit_DW.SFunction_PreviousInput;

    /* Sum: '<S1>/Sum' incorporates:
     *  Constant: '<S1>/S-Function1'
     */
    ssc_bridge_rectifier_1_sm_circuit_B.Sum =
      ssc_bridge_rectifier_1_sm_circuit_P.SFunction1_Value +
      ssc_bridge_rectifier_1_sm_circuit_B.SFunction;

    /* Stop: '<S1>/Stop Simulation' */
    if (ssc_bridge_rectifier_1_sm_circuit_B.Sum != 0.0) {
      rtmSetStopRequested(ssc_bridge_rectifier_1_sm_circuit_M, 1);
    }

    /* End of Stop: '<S1>/Stop Simulation' */

    /* S-Function (RECV_Param): '<S8>/S-Function' */

    /* Level2 S-Function Block: '<S8>/S-Function' (RECV_Param) */
    {
      SimStruct *rts = ssc_bridge_rectifier_1_sm_circuit_M->childSfunctions[0];
      sfcnOutputs(rts,0);
    }
  }

  /* Sin: '<S2>/Sine Wave' */
  ssc_bridge_rectifier_1_sm_circuit_B.SineWave = sin
    (ssc_bridge_rectifier_1_sm_circuit_P.SineWave_Freq *
     ssc_bridge_rectifier_1_sm_circuit_M->Timing.t[0] +
     ssc_bridge_rectifier_1_sm_circuit_P.SineWave_Phase) *
    ssc_bridge_rectifier_1_sm_circuit_P.SineWave_Amp +
    ssc_bridge_rectifier_1_sm_circuit_P.SineWave_Bias;

  /* Product: '<S2>/Product' */
  ssc_bridge_rectifier_1_sm_circuit_B.Product =
    ssc_bridge_rectifier_1_sm_circuit_B.SFunction_f[0] *
    ssc_bridge_rectifier_1_sm_circuit_B.SineWave;

  /* SimscapeInputBlock: '<S13>/INPUT_1_1_1' */
  ssc_bridge_rectifier_1_sm_circuit_B.INPUT_1_1_1[0] = 1.0 *
    ssc_bridge_rectifier_1_sm_circuit_B.Product + 0.0;
  ssc_bridge_rectifier_1_sm_circuit_B.INPUT_1_1_1[1] = 1.0 * 0.0;
  ssc_bridge_rectifier_1_sm_circuit_B.INPUT_1_1_1[2] = 1.0 * 0.0;
  ssc_bridge_rectifier_1_sm_circuit_B.INPUT_1_1_1[3] = 0.0;
  if (rtmIsMajorTimeStep(ssc_bridge_rectifier_1_sm_circuit_M)) {
    /* SimscapeRtp: '<S6>/RTP_1' incorporates:
     *  Constant: '<S2>/Subsystem_around_RTP_983F50E8_vc'
     */
    if (ssc_bridge_rectifier_1_sm_circuit_DW.RTP_1_SetParametersNeeded) {
      parameterBundle.mLogicalParameters.mN = 0;
      parameterBundle.mLogicalParameters.mX = NULL;
      parameterBundle.mIntegerParameters.mN = 0;
      parameterBundle.mIntegerParameters.mX = NULL;
      parameterBundle.mIndexParameters.mN = 0;
      parameterBundle.mIndexParameters.mX = NULL;
      j = 0;
      tmp = ssc_bridge_rectifier_1_sm_circuit_P.RTP_983F50E8_vc_Value;
      parameterBundle.mRealParameters.mN = 1;
      parameterBundle.mRealParameters.mX = &tmp;
      rtpManager = (NeslRtpManager *)
        ssc_bridge_rectifier_1_sm_circuit_DW.RTP_1_RtpManager;
      diag = rtw_create_diagnostics();
      diagTree = neu_diagnostic_manager_get_initial_tree(diag);
      ok = nesl_rtp_manager_set_rtps(rtpManager,
        ssc_bridge_rectifier_1_sm_circuit_M->Timing.t[0], parameterBundle, diag);
      if (!ok) {
        ok = error_buffer_is_empty(rtmGetErrorStatus
          (ssc_bridge_rectifier_1_sm_circuit_M));
        if (ok) {
          msg = rtw_diagnostics_msg(diagTree);
          rtmSetErrorStatus(ssc_bridge_rectifier_1_sm_circuit_M, msg);
        }
      }
    }

    ssc_bridge_rectifier_1_sm_circuit_DW.RTP_1_SetParametersNeeded = false;

    /* End of SimscapeRtp: '<S6>/RTP_1' */
  }

  /* SimscapeExecutionBlock: '<S13>/STATE_1' */
  simulationData = (NeslSimulationData *)
    ssc_bridge_rectifier_1_sm_circuit_DW.STATE_1_SimData;
  time = ssc_bridge_rectifier_1_sm_circuit_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 1;
  simulationData->mData->mContStates.mX =
    &ssc_bridge_rectifier_1_sm_circuit_X.ssc_bridge_rectifier_1_sm_circu;
  simulationData->mData->mDiscStates.mN = 6;
  simulationData->mData->mDiscStates.mX =
    &ssc_bridge_rectifier_1_sm_circuit_DW.STATE_1_Discrete[0];
  simulationData->mData->mModeVector.mN = 4;
  simulationData->mData->mModeVector.mX =
    &ssc_bridge_rectifier_1_sm_circuit_DW.STATE_1_Modes[0];
  ok = false;
  simulationData->mData->mFoundZcEvents = ok;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
    (ssc_bridge_rectifier_1_sm_circuit_M);
  ok = false;
  simulationData->mData->mIsSolverAssertCheck = ok;
  simulationData->mData->mIsSolverCheckingCIC = false;
  ok = rtsiIsSolverComputingJacobian
    (&ssc_bridge_rectifier_1_sm_circuit_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = ok;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsOkayToUpdateMode = rtmIsMajorTimeStep
    (ssc_bridge_rectifier_1_sm_circuit_M);
  tmp_1[0] = 0;
  tmp_0[0] = ssc_bridge_rectifier_1_sm_circuit_B.INPUT_1_1_1[0];
  tmp_0[1] = ssc_bridge_rectifier_1_sm_circuit_B.INPUT_1_1_1[1];
  tmp_0[2] = ssc_bridge_rectifier_1_sm_circuit_B.INPUT_1_1_1[2];
  tmp_0[3] = ssc_bridge_rectifier_1_sm_circuit_B.INPUT_1_1_1[3];
  tmp_1[1] = 4;
  simulationData->mData->mInputValues.mN = 4;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 2;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  simulationData->mData->mOutputs.mN = 11;
  simulationData->mData->mOutputs.mX =
    &ssc_bridge_rectifier_1_sm_circuit_B.STATE_1[0];
  simulationData->mData->mSampleHits.mN = 0;
  simulationData->mData->mSampleHits.mX = NULL;
  simulationData->mData->mIsFundamentalSampleHit = false;
  simulationData->mData->mTolerances.mN = 0;
  simulationData->mData->mTolerances.mX = NULL;
  simulationData->mData->mCstateHasChanged = false;
  simulator = (NeslSimulator *)
    ssc_bridge_rectifier_1_sm_circuit_DW.STATE_1_Simulator;
  diag = (NeuDiagnosticManager *)
    ssc_bridge_rectifier_1_sm_circuit_DW.STATE_1_DiagMgr;
  diagTree = neu_diagnostic_manager_get_initial_tree(diag);
  j = ne_simulator_method(simulator, NESL_SIM_OUTPUTS, simulationData, diag);
  if (j != 0) {
    ok = error_buffer_is_empty(rtmGetErrorStatus
      (ssc_bridge_rectifier_1_sm_circuit_M));
    if (ok) {
      msg = rtw_diagnostics_msg(diagTree);
      rtmSetErrorStatus(ssc_bridge_rectifier_1_sm_circuit_M, msg);
    }
  }

  /* End of SimscapeExecutionBlock: '<S13>/STATE_1' */

  /* SimscapeExecutionBlock: '<S13>/OUTPUT_1_0' */
  simulationData = (NeslSimulationData *)
    ssc_bridge_rectifier_1_sm_circuit_DW.OUTPUT_1_0_SimData;
  time_0 = ssc_bridge_rectifier_1_sm_circuit_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time_0;
  simulationData->mData->mContStates.mN = 0;
  simulationData->mData->mContStates.mX = NULL;
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX =
    &ssc_bridge_rectifier_1_sm_circuit_DW.OUTPUT_1_0_Discrete;
  simulationData->mData->mModeVector.mN = 0;
  simulationData->mData->mModeVector.mX =
    &ssc_bridge_rectifier_1_sm_circuit_DW.OUTPUT_1_0_Modes;
  ok = false;
  simulationData->mData->mFoundZcEvents = ok;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
    (ssc_bridge_rectifier_1_sm_circuit_M);
  ok = false;
  simulationData->mData->mIsSolverAssertCheck = ok;
  simulationData->mData->mIsSolverCheckingCIC = false;
  simulationData->mData->mIsComputingJacobian = false;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsOkayToUpdateMode = rtmIsMajorTimeStep
    (ssc_bridge_rectifier_1_sm_circuit_M);
  tmp_3[0] = 0;
  tmp_2[0] = ssc_bridge_rectifier_1_sm_circuit_B.INPUT_1_1_1[0];
  tmp_2[1] = ssc_bridge_rectifier_1_sm_circuit_B.INPUT_1_1_1[1];
  tmp_2[2] = ssc_bridge_rectifier_1_sm_circuit_B.INPUT_1_1_1[2];
  tmp_2[3] = ssc_bridge_rectifier_1_sm_circuit_B.INPUT_1_1_1[3];
  tmp_3[1] = 4;
  memcpy(&tmp_2[4], &ssc_bridge_rectifier_1_sm_circuit_B.STATE_1[0], 11U *
         sizeof(real_T));
  tmp_3[2] = 15;
  simulationData->mData->mInputValues.mN = 15;
  simulationData->mData->mInputValues.mX = &tmp_2[0];
  simulationData->mData->mInputOffsets.mN = 3;
  simulationData->mData->mInputOffsets.mX = &tmp_3[0];
  simulationData->mData->mOutputs.mN = 1;

  /* SimscapeExecutionBlock: '<S13>/OUTPUT_1_0' */
  simulationData->mData->mOutputs.mX =
    &ssc_bridge_rectifier_1_sm_circuit_B.OUTPUT_1_0;

  /* SimscapeExecutionBlock: '<S13>/OUTPUT_1_0' */
  simulationData->mData->mSampleHits.mN = 0;
  simulationData->mData->mSampleHits.mX = NULL;
  simulationData->mData->mIsFundamentalSampleHit = false;
  simulationData->mData->mTolerances.mN = 0;
  simulationData->mData->mTolerances.mX = NULL;
  simulationData->mData->mCstateHasChanged = false;
  simulator = (NeslSimulator *)
    ssc_bridge_rectifier_1_sm_circuit_DW.OUTPUT_1_0_Simulator;
  diag = (NeuDiagnosticManager *)
    ssc_bridge_rectifier_1_sm_circuit_DW.OUTPUT_1_0_DiagMgr;
  diagTree = neu_diagnostic_manager_get_initial_tree(diag);
  j = ne_simulator_method(simulator, NESL_SIM_OUTPUTS, simulationData, diag);
  if (j != 0) {
    ok = error_buffer_is_empty(rtmGetErrorStatus
      (ssc_bridge_rectifier_1_sm_circuit_M));
    if (ok) {
      msg = rtw_diagnostics_msg(diagTree);
      rtmSetErrorStatus(ssc_bridge_rectifier_1_sm_circuit_M, msg);
    }
  }

  if (rtmIsMajorTimeStep(ssc_bridge_rectifier_1_sm_circuit_M)) {
    /* S-Function (opmonitor): '<S2>/OpMonitor' */

    /* Level2 S-Function Block: '<S2>/OpMonitor' (opmonitor) */
    {
      SimStruct *rts = ssc_bridge_rectifier_1_sm_circuit_M->childSfunctions[1];
      sfcnOutputs(rts,0);
    }

    /* S-Function (OP_SEND): '<S15>/S-Function' */

    /* Level2 S-Function Block: '<S15>/S-Function' (OP_SEND) */
    {
      SimStruct *rts = ssc_bridge_rectifier_1_sm_circuit_M->childSfunctions[2];
      sfcnOutputs(rts,0);
    }
  }
}

/* Model update function */
void ssc_bridge_rectifier_1_sm_circuit_update(void)
{
  NeslSimulationData *simulationData;
  NeslSimulator *simulator;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  char *msg;
  real_T tmp_0[4];
  real_T time;
  int32_T tmp_2;
  int_T tmp_1[2];
  boolean_T tmp;
  if (rtmIsMajorTimeStep(ssc_bridge_rectifier_1_sm_circuit_M)) {
    /* Update for Memory: '<S1>/S-Function' */
    ssc_bridge_rectifier_1_sm_circuit_DW.SFunction_PreviousInput =
      ssc_bridge_rectifier_1_sm_circuit_B.Sum;
  }

  /* Update for SimscapeExecutionBlock: '<S13>/STATE_1' */
  simulationData = (NeslSimulationData *)
    ssc_bridge_rectifier_1_sm_circuit_DW.STATE_1_SimData;
  time = ssc_bridge_rectifier_1_sm_circuit_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 1;
  simulationData->mData->mContStates.mX =
    &ssc_bridge_rectifier_1_sm_circuit_X.ssc_bridge_rectifier_1_sm_circu;
  simulationData->mData->mDiscStates.mN = 6;
  simulationData->mData->mDiscStates.mX =
    &ssc_bridge_rectifier_1_sm_circuit_DW.STATE_1_Discrete[0];
  simulationData->mData->mModeVector.mN = 4;
  simulationData->mData->mModeVector.mX =
    &ssc_bridge_rectifier_1_sm_circuit_DW.STATE_1_Modes[0];
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
    (ssc_bridge_rectifier_1_sm_circuit_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian
    (&ssc_bridge_rectifier_1_sm_circuit_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsOkayToUpdateMode = rtmIsMajorTimeStep
    (ssc_bridge_rectifier_1_sm_circuit_M);
  tmp_1[0] = 0;
  tmp_0[0] = ssc_bridge_rectifier_1_sm_circuit_B.INPUT_1_1_1[0];
  tmp_0[1] = ssc_bridge_rectifier_1_sm_circuit_B.INPUT_1_1_1[1];
  tmp_0[2] = ssc_bridge_rectifier_1_sm_circuit_B.INPUT_1_1_1[2];
  tmp_0[3] = ssc_bridge_rectifier_1_sm_circuit_B.INPUT_1_1_1[3];
  tmp_1[1] = 4;
  simulationData->mData->mInputValues.mN = 4;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 2;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  simulator = (NeslSimulator *)
    ssc_bridge_rectifier_1_sm_circuit_DW.STATE_1_Simulator;
  diagnosticManager = (NeuDiagnosticManager *)
    ssc_bridge_rectifier_1_sm_circuit_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method(simulator, NESL_SIM_UPDATE, simulationData,
    diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus
      (ssc_bridge_rectifier_1_sm_circuit_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(ssc_bridge_rectifier_1_sm_circuit_M, msg);
    }
  }

  /* End of Update for SimscapeExecutionBlock: '<S13>/STATE_1' */
  if (rtmIsMajorTimeStep(ssc_bridge_rectifier_1_sm_circuit_M)) {
    rt_ertODEUpdateContinuousStates
      (&ssc_bridge_rectifier_1_sm_circuit_M->solverInfo);
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
  if (!(++ssc_bridge_rectifier_1_sm_circuit_M->Timing.clockTick0)) {
    ++ssc_bridge_rectifier_1_sm_circuit_M->Timing.clockTickH0;
  }

  ssc_bridge_rectifier_1_sm_circuit_M->Timing.t[0] = rtsiGetSolverStopTime
    (&ssc_bridge_rectifier_1_sm_circuit_M->solverInfo);

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
    if (!(++ssc_bridge_rectifier_1_sm_circuit_M->Timing.clockTick1)) {
      ++ssc_bridge_rectifier_1_sm_circuit_M->Timing.clockTickH1;
    }

    ssc_bridge_rectifier_1_sm_circuit_M->Timing.t[1] =
      ssc_bridge_rectifier_1_sm_circuit_M->Timing.clockTick1 *
      ssc_bridge_rectifier_1_sm_circuit_M->Timing.stepSize1 +
      ssc_bridge_rectifier_1_sm_circuit_M->Timing.clockTickH1 *
      ssc_bridge_rectifier_1_sm_circuit_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ssc_bridge_rectifier_1_sm_circuit_derivatives(void)
{
  NeslSimulationData *simulationData;
  NeslSimulator *simulator;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  XDot_ssc_bridge_rectifier_1_sm_circuit_T *_rtXdot;
  char *msg;
  real_T tmp_0[4];
  real_T time;
  int32_T tmp_2;
  int_T tmp_1[2];
  boolean_T tmp;
  _rtXdot = ((XDot_ssc_bridge_rectifier_1_sm_circuit_T *)
             ssc_bridge_rectifier_1_sm_circuit_M->ModelData.derivs);

  /* Derivatives for SimscapeExecutionBlock: '<S13>/STATE_1' */
  simulationData = (NeslSimulationData *)
    ssc_bridge_rectifier_1_sm_circuit_DW.STATE_1_SimData;
  time = ssc_bridge_rectifier_1_sm_circuit_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 1;
  simulationData->mData->mContStates.mX =
    &ssc_bridge_rectifier_1_sm_circuit_X.ssc_bridge_rectifier_1_sm_circu;
  simulationData->mData->mDiscStates.mN = 6;
  simulationData->mData->mDiscStates.mX =
    &ssc_bridge_rectifier_1_sm_circuit_DW.STATE_1_Discrete[0];
  simulationData->mData->mModeVector.mN = 4;
  simulationData->mData->mModeVector.mX =
    &ssc_bridge_rectifier_1_sm_circuit_DW.STATE_1_Modes[0];
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
    (ssc_bridge_rectifier_1_sm_circuit_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian
    (&ssc_bridge_rectifier_1_sm_circuit_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  simulationData->mData->mIsOkayToUpdateMode = rtmIsMajorTimeStep
    (ssc_bridge_rectifier_1_sm_circuit_M);
  tmp_1[0] = 0;
  tmp_0[0] = ssc_bridge_rectifier_1_sm_circuit_B.INPUT_1_1_1[0];
  tmp_0[1] = ssc_bridge_rectifier_1_sm_circuit_B.INPUT_1_1_1[1];
  tmp_0[2] = ssc_bridge_rectifier_1_sm_circuit_B.INPUT_1_1_1[2];
  tmp_0[3] = ssc_bridge_rectifier_1_sm_circuit_B.INPUT_1_1_1[3];
  tmp_1[1] = 4;
  simulationData->mData->mInputValues.mN = 4;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 2;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  simulationData->mData->mDx.mN = 1;
  simulationData->mData->mDx.mX = &_rtXdot->ssc_bridge_rectifier_1_sm_circu;
  simulator = (NeslSimulator *)
    ssc_bridge_rectifier_1_sm_circuit_DW.STATE_1_Simulator;
  diagnosticManager = (NeuDiagnosticManager *)
    ssc_bridge_rectifier_1_sm_circuit_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_2 = ne_simulator_method(simulator, NESL_SIM_DERIVATIVES, simulationData,
    diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus
      (ssc_bridge_rectifier_1_sm_circuit_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(ssc_bridge_rectifier_1_sm_circuit_M, msg);
    }
  }

  /* End of Derivatives for SimscapeExecutionBlock: '<S13>/STATE_1' */
}

/* Model initialize function */
void ssc_bridge_rectifier_1_sm_circuit_initialize(void)
{
  {
    NeModelParameters modelParameters;
    NeModelParameters modelParameters_0;
    NeslRtpManager *manager;
    NeslSimulationData *tmp;
    NeslSimulator *simulator;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    char *msg;
    real_T tmp_0;
    int32_T tmp_1;
    boolean_T val;

    /* Start for SimscapeRtp: '<S6>/RTP_1' */
    manager = nesl_lease_rtp_manager(
      "ssc_bridge_rectifier_1_sm_circuit/sm_circuit/Solver Configuration_1", 0);
    val = pointer_is_null(manager);
    if (val) {
      ssc_bridge_rectifier_1_sm_circuit_a2b15696_1_gateway();
      manager = nesl_lease_rtp_manager(
        "ssc_bridge_rectifier_1_sm_circuit/sm_circuit/Solver Configuration_1", 0);
    }

    ssc_bridge_rectifier_1_sm_circuit_DW.RTP_1_RtpManager = (void *)manager;
    ssc_bridge_rectifier_1_sm_circuit_DW.RTP_1_SetParametersNeeded = true;

    /* End of Start for SimscapeRtp: '<S6>/RTP_1' */

    /* Start for SimscapeExecutionBlock: '<S13>/STATE_1' */
    simulator = nesl_lease_simulator(
      "ssc_bridge_rectifier_1_sm_circuit/sm_circuit/Solver Configuration_1", 0,
      0);
    ssc_bridge_rectifier_1_sm_circuit_DW.STATE_1_Simulator = (void *)simulator;
    val = pointer_is_null(ssc_bridge_rectifier_1_sm_circuit_DW.STATE_1_Simulator);
    if (val) {
      ssc_bridge_rectifier_1_sm_circuit_a2b15696_1_gateway();
      simulator = nesl_lease_simulator(
        "ssc_bridge_rectifier_1_sm_circuit/sm_circuit/Solver Configuration_1", 0,
        0);
      ssc_bridge_rectifier_1_sm_circuit_DW.STATE_1_Simulator = (void *)simulator;
    }

    tmp = nesl_create_simulation_data();
    ssc_bridge_rectifier_1_sm_circuit_DW.STATE_1_SimData = (void *)tmp;
    diagnosticManager = rtw_create_diagnostics();
    ssc_bridge_rectifier_1_sm_circuit_DW.STATE_1_DiagMgr = (void *)
      diagnosticManager;
    modelParameters.mSolverType = NE_SOLVER_TYPE_ODE;
    modelParameters.mSolverTolerance = 0.001;
    modelParameters.mVariableStepSolver = false;
    modelParameters.mIsUsingODEN = false;
    modelParameters.mFixedStepSize = 0.0001;
    modelParameters.mStartTime = 0.0;
    modelParameters.mLoadInitialState = false;
    modelParameters.mUseSimState = false;
    modelParameters.mLinTrimCompile = false;
    modelParameters.mLoggingMode = SSC_LOGGING_NONE;
    modelParameters.mRTWModifiedTimeStamp = 5.95175634E+8;
    modelParameters.mZcDisabled = false;
    tmp_0 = 0.001;
    modelParameters.mSolverTolerance = tmp_0;
    tmp_0 = 0.0001;
    modelParameters.mFixedStepSize = tmp_0;
    val = false;
    modelParameters.mVariableStepSolver = val;
    val = false;
    modelParameters.mIsUsingODEN = val;
    val = false;
    modelParameters.mLoadInitialState = val;
    val = true;
    modelParameters.mZcDisabled = val;
    simulator = (NeslSimulator *)
      ssc_bridge_rectifier_1_sm_circuit_DW.STATE_1_Simulator;
    diagnosticManager = (NeuDiagnosticManager *)
      ssc_bridge_rectifier_1_sm_circuit_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_1 = nesl_initialize_simulator(simulator, &modelParameters,
      diagnosticManager);
    if (tmp_1 != 0) {
      val = error_buffer_is_empty(rtmGetErrorStatus
        (ssc_bridge_rectifier_1_sm_circuit_M));
      if (val) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(ssc_bridge_rectifier_1_sm_circuit_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S13>/STATE_1' */

    /* Start for SimscapeExecutionBlock: '<S13>/OUTPUT_1_0' */
    simulator = nesl_lease_simulator(
      "ssc_bridge_rectifier_1_sm_circuit/sm_circuit/Solver Configuration_1", 1,
      0);
    ssc_bridge_rectifier_1_sm_circuit_DW.OUTPUT_1_0_Simulator = (void *)
      simulator;
    val = pointer_is_null
      (ssc_bridge_rectifier_1_sm_circuit_DW.OUTPUT_1_0_Simulator);
    if (val) {
      ssc_bridge_rectifier_1_sm_circuit_a2b15696_1_gateway();
      simulator = nesl_lease_simulator(
        "ssc_bridge_rectifier_1_sm_circuit/sm_circuit/Solver Configuration_1", 1,
        0);
      ssc_bridge_rectifier_1_sm_circuit_DW.OUTPUT_1_0_Simulator = (void *)
        simulator;
    }

    tmp = nesl_create_simulation_data();
    ssc_bridge_rectifier_1_sm_circuit_DW.OUTPUT_1_0_SimData = (void *)tmp;
    diagnosticManager = rtw_create_diagnostics();
    ssc_bridge_rectifier_1_sm_circuit_DW.OUTPUT_1_0_DiagMgr = (void *)
      diagnosticManager;
    modelParameters_0.mSolverType = NE_SOLVER_TYPE_ODE;
    modelParameters_0.mSolverTolerance = 0.001;
    modelParameters_0.mVariableStepSolver = false;
    modelParameters_0.mIsUsingODEN = false;
    modelParameters_0.mFixedStepSize = 0.0001;
    modelParameters_0.mStartTime = 0.0;
    modelParameters_0.mLoadInitialState = false;
    modelParameters_0.mUseSimState = false;
    modelParameters_0.mLinTrimCompile = false;
    modelParameters_0.mLoggingMode = SSC_LOGGING_NONE;
    modelParameters_0.mRTWModifiedTimeStamp = 5.95175634E+8;
    modelParameters_0.mZcDisabled = false;
    tmp_0 = 0.001;
    modelParameters_0.mSolverTolerance = tmp_0;
    tmp_0 = 0.0001;
    modelParameters_0.mFixedStepSize = tmp_0;
    val = false;
    modelParameters_0.mVariableStepSolver = val;
    val = false;
    modelParameters_0.mIsUsingODEN = val;
    val = false;
    modelParameters_0.mLoadInitialState = val;
    val = true;
    modelParameters_0.mZcDisabled = val;
    simulator = (NeslSimulator *)
      ssc_bridge_rectifier_1_sm_circuit_DW.OUTPUT_1_0_Simulator;
    diagnosticManager = (NeuDiagnosticManager *)
      ssc_bridge_rectifier_1_sm_circuit_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_1 = nesl_initialize_simulator(simulator, &modelParameters_0,
      diagnosticManager);
    if (tmp_1 != 0) {
      val = error_buffer_is_empty(rtmGetErrorStatus
        (ssc_bridge_rectifier_1_sm_circuit_M));
      if (val) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(ssc_bridge_rectifier_1_sm_circuit_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S13>/OUTPUT_1_0' */
  }

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
  ssc_bridge_rectifier_1_sm_circuit_DW.SFunction_PreviousInput =
    ssc_bridge_rectifier_1_sm_circuit_P.SFunction_InitialCondition;

  /* InitializeConditions for S-Function (RECV_Param): '<S8>/S-Function' */
  /* Level2 S-Function Block: '<S8>/S-Function' (RECV_Param) */
  {
    SimStruct *rts = ssc_bridge_rectifier_1_sm_circuit_M->childSfunctions[0];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for S-Function (opmonitor): '<S2>/OpMonitor' */
  /* Level2 S-Function Block: '<S2>/OpMonitor' (opmonitor) */
  {
    SimStruct *rts = ssc_bridge_rectifier_1_sm_circuit_M->childSfunctions[1];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for S-Function (OP_SEND): '<S15>/S-Function' */
  /* Level2 S-Function Block: '<S15>/S-Function' (OP_SEND) */
  {
    SimStruct *rts = ssc_bridge_rectifier_1_sm_circuit_M->childSfunctions[2];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
void ssc_bridge_rectifier_1_sm_circuit_terminate(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;

  /* Terminate for S-Function (RECV_Param): '<S8>/S-Function' */
  /* Level2 S-Function Block: '<S8>/S-Function' (RECV_Param) */
  {
    SimStruct *rts = ssc_bridge_rectifier_1_sm_circuit_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for SimscapeExecutionBlock: '<S13>/STATE_1' */
  diagnosticManager = (NeuDiagnosticManager *)
    ssc_bridge_rectifier_1_sm_circuit_DW.STATE_1_DiagMgr;
  neu_destroy_diagnostic_manager(diagnosticManager);
  simulationData = (NeslSimulationData *)
    ssc_bridge_rectifier_1_sm_circuit_DW.STATE_1_SimData;
  nesl_destroy_simulation_data(simulationData);
  nesl_erase_simulator("ssc_bridge_rectifier_1_sm_circuit/sm_circuit/Solver Configuration_1");
  nesl_destroy_registry();

  /* Terminate for SimscapeExecutionBlock: '<S13>/OUTPUT_1_0' */
  diagnosticManager = (NeuDiagnosticManager *)
    ssc_bridge_rectifier_1_sm_circuit_DW.OUTPUT_1_0_DiagMgr;
  neu_destroy_diagnostic_manager(diagnosticManager);
  simulationData = (NeslSimulationData *)
    ssc_bridge_rectifier_1_sm_circuit_DW.OUTPUT_1_0_SimData;
  nesl_destroy_simulation_data(simulationData);
  nesl_erase_simulator("ssc_bridge_rectifier_1_sm_circuit/sm_circuit/Solver Configuration_1");
  nesl_destroy_registry();

  /* Terminate for S-Function (opmonitor): '<S2>/OpMonitor' */
  /* Level2 S-Function Block: '<S2>/OpMonitor' (opmonitor) */
  {
    SimStruct *rts = ssc_bridge_rectifier_1_sm_circuit_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (OP_SEND): '<S15>/S-Function' */
  /* Level2 S-Function Block: '<S15>/S-Function' (OP_SEND) */
  {
    SimStruct *rts = ssc_bridge_rectifier_1_sm_circuit_M->childSfunctions[2];
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
  ssc_bridge_rectifier_1_sm_circuit_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ssc_bridge_rectifier_1_sm_circuit_update();
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
  ssc_bridge_rectifier_1_sm_circuit_initialize();
}

void MdlTerminate(void)
{
  ssc_bridge_rectifier_1_sm_circuit_terminate();
}

/* Registration function */
RT_MODEL_ssc_bridge_rectifier_1_sm_circuit_T *ssc_bridge_rectifier_1_sm_circuit
  (void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ssc_bridge_rectifier_1_sm_circuit_M, 0,
                sizeof(RT_MODEL_ssc_bridge_rectifier_1_sm_circuit_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ssc_bridge_rectifier_1_sm_circuit_M->solverInfo,
                          &ssc_bridge_rectifier_1_sm_circuit_M->Timing.simTimeStep);
    rtsiSetTPtr(&ssc_bridge_rectifier_1_sm_circuit_M->solverInfo, &rtmGetTPtr
                (ssc_bridge_rectifier_1_sm_circuit_M));
    rtsiSetStepSizePtr(&ssc_bridge_rectifier_1_sm_circuit_M->solverInfo,
                       &ssc_bridge_rectifier_1_sm_circuit_M->Timing.stepSize0);
    rtsiSetdXPtr(&ssc_bridge_rectifier_1_sm_circuit_M->solverInfo,
                 &ssc_bridge_rectifier_1_sm_circuit_M->ModelData.derivs);
    rtsiSetContStatesPtr(&ssc_bridge_rectifier_1_sm_circuit_M->solverInfo,
                         (real_T **)
                         &ssc_bridge_rectifier_1_sm_circuit_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&ssc_bridge_rectifier_1_sm_circuit_M->solverInfo,
      &ssc_bridge_rectifier_1_sm_circuit_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr
      (&ssc_bridge_rectifier_1_sm_circuit_M->solverInfo,
       &ssc_bridge_rectifier_1_sm_circuit_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&ssc_bridge_rectifier_1_sm_circuit_M->solverInfo,
       &ssc_bridge_rectifier_1_sm_circuit_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&ssc_bridge_rectifier_1_sm_circuit_M->solverInfo,
       &ssc_bridge_rectifier_1_sm_circuit_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&ssc_bridge_rectifier_1_sm_circuit_M->solverInfo,
                          (&rtmGetErrorStatus
      (ssc_bridge_rectifier_1_sm_circuit_M)));
    rtsiSetRTModelPtr(&ssc_bridge_rectifier_1_sm_circuit_M->solverInfo,
                      ssc_bridge_rectifier_1_sm_circuit_M);
  }

  rtsiSetSimTimeStep(&ssc_bridge_rectifier_1_sm_circuit_M->solverInfo,
                     MAJOR_TIME_STEP);
  ssc_bridge_rectifier_1_sm_circuit_M->ModelData.intgData.y =
    ssc_bridge_rectifier_1_sm_circuit_M->ModelData.odeY;
  ssc_bridge_rectifier_1_sm_circuit_M->ModelData.intgData.f[0] =
    ssc_bridge_rectifier_1_sm_circuit_M->ModelData.odeF[0];
  ssc_bridge_rectifier_1_sm_circuit_M->ModelData.intgData.f[1] =
    ssc_bridge_rectifier_1_sm_circuit_M->ModelData.odeF[1];
  ssc_bridge_rectifier_1_sm_circuit_M->ModelData.intgData.f[2] =
    ssc_bridge_rectifier_1_sm_circuit_M->ModelData.odeF[2];
  ssc_bridge_rectifier_1_sm_circuit_M->ModelData.contStates = ((real_T *)
    &ssc_bridge_rectifier_1_sm_circuit_X);
  rtsiSetSolverData(&ssc_bridge_rectifier_1_sm_circuit_M->solverInfo, (void *)
                    &ssc_bridge_rectifier_1_sm_circuit_M->ModelData.intgData);
  rtsiSetSolverName(&ssc_bridge_rectifier_1_sm_circuit_M->solverInfo,"ode3");
  ssc_bridge_rectifier_1_sm_circuit_M->solverInfoPtr =
    (&ssc_bridge_rectifier_1_sm_circuit_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      ssc_bridge_rectifier_1_sm_circuit_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "ssc_bridge_rectifier_1_sm_circuit_M points to
       static memory which is guaranteed to be non-NULL" */
    ssc_bridge_rectifier_1_sm_circuit_M->Timing.sampleTimeTaskIDPtr =
      (&mdlTsMap[0]);
    ssc_bridge_rectifier_1_sm_circuit_M->Timing.sampleTimes =
      (&ssc_bridge_rectifier_1_sm_circuit_M->Timing.sampleTimesArray[0]);
    ssc_bridge_rectifier_1_sm_circuit_M->Timing.offsetTimes =
      (&ssc_bridge_rectifier_1_sm_circuit_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ssc_bridge_rectifier_1_sm_circuit_M->Timing.sampleTimes[0] = (0.0);
    ssc_bridge_rectifier_1_sm_circuit_M->Timing.sampleTimes[1] = (0.0001);

    /* task offsets */
    ssc_bridge_rectifier_1_sm_circuit_M->Timing.offsetTimes[0] = (0.0);
    ssc_bridge_rectifier_1_sm_circuit_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ssc_bridge_rectifier_1_sm_circuit_M,
             &ssc_bridge_rectifier_1_sm_circuit_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      ssc_bridge_rectifier_1_sm_circuit_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ssc_bridge_rectifier_1_sm_circuit_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ssc_bridge_rectifier_1_sm_circuit_M, 0.05);
  ssc_bridge_rectifier_1_sm_circuit_M->Timing.stepSize0 = 0.0001;
  ssc_bridge_rectifier_1_sm_circuit_M->Timing.stepSize1 = 0.0001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    ssc_bridge_rectifier_1_sm_circuit_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ssc_bridge_rectifier_1_sm_circuit_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ssc_bridge_rectifier_1_sm_circuit_M->rtwLogInfo, (NULL));
    rtliSetLogT(ssc_bridge_rectifier_1_sm_circuit_M->rtwLogInfo, "");
    rtliSetLogX(ssc_bridge_rectifier_1_sm_circuit_M->rtwLogInfo, "");
    rtliSetLogXFinal(ssc_bridge_rectifier_1_sm_circuit_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ssc_bridge_rectifier_1_sm_circuit_M->rtwLogInfo,
      "rt_");
    rtliSetLogFormat(ssc_bridge_rectifier_1_sm_circuit_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ssc_bridge_rectifier_1_sm_circuit_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ssc_bridge_rectifier_1_sm_circuit_M->rtwLogInfo, 1);
    rtliSetLogY(ssc_bridge_rectifier_1_sm_circuit_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ssc_bridge_rectifier_1_sm_circuit_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ssc_bridge_rectifier_1_sm_circuit_M->rtwLogInfo, (NULL));
  }

  ssc_bridge_rectifier_1_sm_circuit_M->solverInfoPtr =
    (&ssc_bridge_rectifier_1_sm_circuit_M->solverInfo);
  ssc_bridge_rectifier_1_sm_circuit_M->Timing.stepSize = (0.0001);
  rtsiSetFixedStepSize(&ssc_bridge_rectifier_1_sm_circuit_M->solverInfo, 0.0001);
  rtsiSetSolverMode(&ssc_bridge_rectifier_1_sm_circuit_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ssc_bridge_rectifier_1_sm_circuit_M->ModelData.blockIO = ((void *)
    &ssc_bridge_rectifier_1_sm_circuit_B);

  {
    int32_T i;
    for (i = 0; i < 11; i++) {
      ssc_bridge_rectifier_1_sm_circuit_B.STATE_1[i] = 0.0;
    }

    ssc_bridge_rectifier_1_sm_circuit_B.SFunction = 0.0;
    ssc_bridge_rectifier_1_sm_circuit_B.Sum = 0.0;
    ssc_bridge_rectifier_1_sm_circuit_B.SFunction_f[0] = 0.0;
    ssc_bridge_rectifier_1_sm_circuit_B.SFunction_f[1] = 0.0;
    ssc_bridge_rectifier_1_sm_circuit_B.SineWave = 0.0;
    ssc_bridge_rectifier_1_sm_circuit_B.Product = 0.0;
    ssc_bridge_rectifier_1_sm_circuit_B.INPUT_1_1_1[0] = 0.0;
    ssc_bridge_rectifier_1_sm_circuit_B.INPUT_1_1_1[1] = 0.0;
    ssc_bridge_rectifier_1_sm_circuit_B.INPUT_1_1_1[2] = 0.0;
    ssc_bridge_rectifier_1_sm_circuit_B.INPUT_1_1_1[3] = 0.0;
    ssc_bridge_rectifier_1_sm_circuit_B.RTP_1 = 0.0;
    ssc_bridge_rectifier_1_sm_circuit_B.OUTPUT_1_0 = 0.0;
    ssc_bridge_rectifier_1_sm_circuit_B.OpMonitor_o1 = 0.0;
    ssc_bridge_rectifier_1_sm_circuit_B.OpMonitor_o2 = 0.0;
    ssc_bridge_rectifier_1_sm_circuit_B.OpMonitor_o3 = 0.0;
    ssc_bridge_rectifier_1_sm_circuit_B.OpMonitor_o4 = 0.0;
  }

  /* parameters */
  ssc_bridge_rectifier_1_sm_circuit_M->ModelData.defaultParam = ((real_T *)
    &ssc_bridge_rectifier_1_sm_circuit_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ssc_bridge_rectifier_1_sm_circuit_X;
    ssc_bridge_rectifier_1_sm_circuit_M->ModelData.contStates = (x);
    (void) memset((void *)&ssc_bridge_rectifier_1_sm_circuit_X, 0,
                  sizeof(X_ssc_bridge_rectifier_1_sm_circuit_T));
  }

  /* states (dwork) */
  ssc_bridge_rectifier_1_sm_circuit_M->ModelData.dwork = ((void *)
    &ssc_bridge_rectifier_1_sm_circuit_DW);
  (void) memset((void *)&ssc_bridge_rectifier_1_sm_circuit_DW, 0,
                sizeof(DW_ssc_bridge_rectifier_1_sm_circuit_T));
  ssc_bridge_rectifier_1_sm_circuit_DW.INPUT_1_1_1_Discrete[0] = 0.0;
  ssc_bridge_rectifier_1_sm_circuit_DW.INPUT_1_1_1_Discrete[1] = 0.0;

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      ssc_bridge_rectifier_1_sm_circuit_DW.STATE_1_Discrete[i] = 0.0;
    }
  }

  ssc_bridge_rectifier_1_sm_circuit_DW.SFunction_PreviousInput = 0.0;
  ssc_bridge_rectifier_1_sm_circuit_DW.OUTPUT_1_0_Discrete = 0.0;

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo =
      &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.sfcnInfo;
    ssc_bridge_rectifier_1_sm_circuit_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus
      (ssc_bridge_rectifier_1_sm_circuit_M)));
    ssc_bridge_rectifier_1_sm_circuit_M->Sizes.numSampTimes = (2);
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &ssc_bridge_rectifier_1_sm_circuit_M->Sizes.numSampTimes);
    ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.taskTimePtrs[0] =
      &(rtmGetTPtr(ssc_bridge_rectifier_1_sm_circuit_M)[0]);
    ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.taskTimePtrs[1] =
      &(rtmGetTPtr(ssc_bridge_rectifier_1_sm_circuit_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,
                   ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(ssc_bridge_rectifier_1_sm_circuit_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(ssc_bridge_rectifier_1_sm_circuit_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (ssc_bridge_rectifier_1_sm_circuit_M));
    rtssSetStepSizePtr(sfcnInfo,
                       &ssc_bridge_rectifier_1_sm_circuit_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (ssc_bridge_rectifier_1_sm_circuit_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &ssc_bridge_rectifier_1_sm_circuit_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &ssc_bridge_rectifier_1_sm_circuit_M->ModelData.zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &ssc_bridge_rectifier_1_sm_circuit_M->ModelData.CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo,
                         &ssc_bridge_rectifier_1_sm_circuit_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &ssc_bridge_rectifier_1_sm_circuit_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &ssc_bridge_rectifier_1_sm_circuit_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo,
                         &ssc_bridge_rectifier_1_sm_circuit_M->solverInfoPtr);
  }

  ssc_bridge_rectifier_1_sm_circuit_M->Sizes.numSFcns = (3);

  /* register each child */
  {
    (void) memset((void *)
                  &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.childSFunctions
                  [0], 0,
                  3*sizeof(SimStruct));
    ssc_bridge_rectifier_1_sm_circuit_M->childSfunctions =
      (&ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.childSFunctionPtrs
       [0]);
    ssc_bridge_rectifier_1_sm_circuit_M->childSfunctions[0] =
      (&ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.childSFunctions[0]);
    ssc_bridge_rectifier_1_sm_circuit_M->childSfunctions[1] =
      (&ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.childSFunctions[1]);
    ssc_bridge_rectifier_1_sm_circuit_M->childSfunctions[2] =
      (&ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.childSFunctions[2]);

    /* Level2 S-Function Block: ssc_bridge_rectifier_1_sm_circuit/<S8>/S-Function (RECV_Param) */
    {
      SimStruct *rts = ssc_bridge_rectifier_1_sm_circuit_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.blkInfo2
                         [0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.inputOutputPortInfo2
        [0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, ssc_bridge_rectifier_1_sm_circuit_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.methods2
                           [0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.methods3
                           [0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.methods4
                           [0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.periodicStatesInfo
          [0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn0.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn0.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            ssc_bridge_rectifier_1_sm_circuit_B.SFunction_f));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "ssc_bridge_rectifier_1_sm_circuit/sm_circuit/OpComm/Receive/S-Function");
      ssSetRTModel(rts,ssc_bridge_rectifier_1_sm_circuit_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       ssc_bridge_rectifier_1_sm_circuit_P.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       ssc_bridge_rectifier_1_sm_circuit_P.SFunction_P2_Size);
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

    /* Level2 S-Function Block: ssc_bridge_rectifier_1_sm_circuit/<S2>/OpMonitor (opmonitor) */
    {
      SimStruct *rts = ssc_bridge_rectifier_1_sm_circuit_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.blkInfo2
                         [1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.inputOutputPortInfo2
        [1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, ssc_bridge_rectifier_1_sm_circuit_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.methods2
                           [1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.methods3
                           [1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.methods4
                           [1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.statesInfo2
                         [1]);
        ssSetPeriodicStatesInfo(rts,
          &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.periodicStatesInfo
          [1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &ssc_bridge_rectifier_1_sm_circuit_B.SFunction_f[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 4);
        _ssSetPortInfo2ForOutputUnits(rts,
          &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        ssSetOutputPortUnit(rts, 2, 0);
        ssSetOutputPortUnit(rts, 3, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 2, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 3, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &ssc_bridge_rectifier_1_sm_circuit_B.OpMonitor_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &ssc_bridge_rectifier_1_sm_circuit_B.OpMonitor_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &ssc_bridge_rectifier_1_sm_circuit_B.OpMonitor_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &ssc_bridge_rectifier_1_sm_circuit_B.OpMonitor_o4));
        }
      }

      /* path info */
      ssSetModelName(rts, "OpMonitor");
      ssSetPath(rts, "ssc_bridge_rectifier_1_sm_circuit/sm_circuit/OpMonitor");
      ssSetRTModel(rts,ssc_bridge_rectifier_1_sm_circuit_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       ssc_bridge_rectifier_1_sm_circuit_P.OpMonitor_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       ssc_bridge_rectifier_1_sm_circuit_P.OpMonitor_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       ssc_bridge_rectifier_1_sm_circuit_P.OpMonitor_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       ssc_bridge_rectifier_1_sm_circuit_P.OpMonitor_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       ssc_bridge_rectifier_1_sm_circuit_P.OpMonitor_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       ssc_bridge_rectifier_1_sm_circuit_P.OpMonitor_P6_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &ssc_bridge_rectifier_1_sm_circuit_DW.OpMonitor_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &ssc_bridge_rectifier_1_sm_circuit_DW.OpMonitor_PWORK);
      }

      /* registration */
      opmonitor(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: ssc_bridge_rectifier_1_sm_circuit/<S15>/S-Function (OP_SEND) */
    {
      SimStruct *rts = ssc_bridge_rectifier_1_sm_circuit_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap =
        ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.blkInfo2
                         [2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.inputOutputPortInfo2
        [2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, ssc_bridge_rectifier_1_sm_circuit_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.methods2
                           [2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.methods3
                           [2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.methods4
                           [2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.statesInfo2
                         [2]);
        ssSetPeriodicStatesInfo(rts,
          &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.periodicStatesInfo
          [2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn2.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn2.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &ssc_bridge_rectifier_1_sm_circuit_B.OUTPUT_1_0;
          sfcnUPtrs[1] = &ssc_bridge_rectifier_1_sm_circuit_B.OpMonitor_o1;
          sfcnUPtrs[2] = &ssc_bridge_rectifier_1_sm_circuit_B.OpMonitor_o2;
          sfcnUPtrs[3] = &ssc_bridge_rectifier_1_sm_circuit_B.OpMonitor_o3;
          sfcnUPtrs[4] = &ssc_bridge_rectifier_1_sm_circuit_B.OpMonitor_o4;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 5);
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "ssc_bridge_rectifier_1_sm_circuit/sm_circuit/rtlab_send_subsystem/Subsystem1/Send1/S-Function");
      ssSetRTModel(rts,ssc_bridge_rectifier_1_sm_circuit_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       ssc_bridge_rectifier_1_sm_circuit_P.SFunction_P1_Size_g);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *)
                 &ssc_bridge_rectifier_1_sm_circuit_DW.SFunction_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &ssc_bridge_rectifier_1_sm_circuit_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 5);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &ssc_bridge_rectifier_1_sm_circuit_DW.SFunction_IWORK[0]);
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
      ssSetInputPortWidth(rts, 0, 5);
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
  ssc_bridge_rectifier_1_sm_circuit_M->Sizes.numContStates = (1);/* Number of continuous states */
  ssc_bridge_rectifier_1_sm_circuit_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  ssc_bridge_rectifier_1_sm_circuit_M->Sizes.numY = (0);/* Number of model outputs */
  ssc_bridge_rectifier_1_sm_circuit_M->Sizes.numU = (0);/* Number of model inputs */
  ssc_bridge_rectifier_1_sm_circuit_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ssc_bridge_rectifier_1_sm_circuit_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ssc_bridge_rectifier_1_sm_circuit_M->Sizes.numBlocks = (28);/* Number of blocks */
  ssc_bridge_rectifier_1_sm_circuit_M->Sizes.numBlockIO = (13);/* Number of block outputs */
  ssc_bridge_rectifier_1_sm_circuit_M->Sizes.numBlockPrms = (66);/* Sum of parameter "widths" */
  return ssc_bridge_rectifier_1_sm_circuit_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
