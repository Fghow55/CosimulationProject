/*
 * ac_der_basic_model_1_sm_circuit_private.h
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

#ifndef RTW_HEADER_ac_der_basic_model_1_sm_circuit_private_h_
#define RTW_HEADER_ac_der_basic_model_1_sm_circuit_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "ac_der_basic_model_1_sm_circuit.h"

extern real_T rt_hypotd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
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
  ;
extern void RECV_Param(SimStruct *rts);
extern void OP_SEND(SimStruct *rts);
extern void ac_der_basic_model_1_s_RMS_Init(DW_RMS_ac_der_basic_model_1_s_T
  *localDW, P_RMS_ac_der_basic_model_1_sm_T *localP,
  X_RMS_ac_der_basic_model_1_sm_T *localX);
extern void ac_der_basic_model_1__RMS_Start
  (RT_MODEL_ac_der_basic_model_1_sm_circuit_T * const
   ac_der_basic_model_1_sm_circuit_M, DW_RMS_ac_der_basic_model_1_s_T *localDW,
   P_RMS_ac_der_basic_model_1_sm_T *localP);
extern void ac_der_basic_model_1__RMS_Deriv(B_RMS_ac_der_basic_model_1_sm_T
  *localB, DW_RMS_ac_der_basic_model_1_s_T *localDW,
  XDot_RMS_ac_der_basic_model_1_T *localXdot);
extern void ac_der_basic_model__RMS_Disable(DW_RMS_ac_der_basic_model_1_s_T
  *localDW);
extern void ac_der_basic_model_1_RMS_Update
  (RT_MODEL_ac_der_basic_model_1_sm_circuit_T * const
   ac_der_basic_model_1_sm_circuit_M, B_RMS_ac_der_basic_model_1_sm_T *localB,
   DW_RMS_ac_der_basic_model_1_s_T *localDW);
extern void ac_der_basic_model_1_sm_cir_RMS
  (RT_MODEL_ac_der_basic_model_1_sm_circuit_T * const
   ac_der_basic_model_1_sm_circuit_M, boolean_T rtu_Enable, real_T rtu_In,
   B_RMS_ac_der_basic_model_1_sm_T *localB, DW_RMS_ac_der_basic_model_1_s_T
   *localDW, P_RMS_ac_der_basic_model_1_sm_T *localP,
   X_RMS_ac_der_basic_model_1_sm_T *localX);
extern void ac_der_basic_model_TrueRMS_Init(DW_TrueRMS_ac_der_basic_model_T
  *localDW, P_TrueRMS_ac_der_basic_model__T *localP,
  X_TrueRMS_ac_der_basic_model__T *localX);
extern void ac_der_basic_mode_TrueRMS_Start
  (RT_MODEL_ac_der_basic_model_1_sm_circuit_T * const
   ac_der_basic_model_1_sm_circuit_M, DW_TrueRMS_ac_der_basic_model_T *localDW,
   P_TrueRMS_ac_der_basic_model__T *localP);
extern void ac_der_basic_mode_TrueRMS_Deriv(B_TrueRMS_ac_der_basic_model__T
  *localB, DW_TrueRMS_ac_der_basic_model_T *localDW,
  XDot_TrueRMS_ac_der_basic_mod_T *localXdot);
extern void ac_der_basic_mo_TrueRMS_Disable(DW_TrueRMS_ac_der_basic_model_T
  *localDW);
extern void ac_der_basic_mod_TrueRMS_Update
  (RT_MODEL_ac_der_basic_model_1_sm_circuit_T * const
   ac_der_basic_model_1_sm_circuit_M, B_TrueRMS_ac_der_basic_model__T *localB,
   DW_TrueRMS_ac_der_basic_model_T *localDW);
extern void ac_der_basic_model_1_sm_TrueRMS
  (RT_MODEL_ac_der_basic_model_1_sm_circuit_T * const
   ac_der_basic_model_1_sm_circuit_M, boolean_T rtu_Enable, real_T rtu_In,
   B_TrueRMS_ac_der_basic_model__T *localB, DW_TrueRMS_ac_der_basic_model_T
   *localDW, P_TrueRMS_ac_der_basic_model__T *localP,
   X_TrueRMS_ac_der_basic_model__T *localX);

/* private model entry point functions */
extern void ac_der_basic_model_1_sm_circuit_derivatives(void);

#endif               /* RTW_HEADER_ac_der_basic_model_1_sm_circuit_private_h_ */
