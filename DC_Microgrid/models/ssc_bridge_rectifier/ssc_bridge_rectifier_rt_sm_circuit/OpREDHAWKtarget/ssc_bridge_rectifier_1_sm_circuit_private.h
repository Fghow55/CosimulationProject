/*
 * ssc_bridge_rectifier_1_sm_circuit_private.h
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

#ifndef RTW_HEADER_ssc_bridge_rectifier_1_sm_circuit_private_h_
#define RTW_HEADER_ssc_bridge_rectifier_1_sm_circuit_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern void RECV_Param(SimStruct *rts);
extern void opmonitor(SimStruct *rts);
extern void OP_SEND(SimStruct *rts);

/* private model entry point functions */
extern void ssc_bridge_rectifier_1_sm_circuit_derivatives(void);

#endif             /* RTW_HEADER_ssc_bridge_rectifier_1_sm_circuit_private_h_ */
