/*
 * ssc_bridge_rectifier_1_sm_circuit_data.c
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

/* Block parameters (default storage) */
P_ssc_bridge_rectifier_1_sm_circuit_T ssc_bridge_rectifier_1_sm_circuit_P = {
  /* Expression: 0
   * Referenced by: '<S1>/S-Function1' (Parameter: Value)
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/S-Function' (Parameter: InitialCondition)
   */
  0.0,

  /* Computed Parameter: SFunction_P1_Size
   * Referenced by: '<S8>/S-Function' (Parameter: P1Size)
   */
  { 1.0, 1.0 },

  /* Expression: Data_width
   * Referenced by: '<S8>/S-Function' (Parameter: P1)
   */
  2.0,

  /* Computed Parameter: SFunction_P2_Size
   * Referenced by: '<S8>/S-Function' (Parameter: P2Size)
   */
  { 2.0, 1.0 },

  /* Expression: InitialConditions
   * Referenced by: '<S8>/S-Function' (Parameter: P2)
   */
  { 169.705627484771, 1.0 },

  /* Expression: 1
   * Referenced by: '<S2>/Sine Wave' (Parameter: Amplitude)
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Sine Wave' (Parameter: Bias)
   */
  0.0,

  /* Expression: 2*pi*60
   * Referenced by: '<S2>/Sine Wave' (Parameter: Frequency)
   */
  376.99111843077515,

  /* Expression: 0
   * Referenced by: '<S2>/Sine Wave' (Parameter: Phase)
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Subsystem_around_RTP_983F50E8_vc' (Parameter: Value)
   */
  0.0,

  /* Computed Parameter: OpMonitor_P1_Size
   * Referenced by: '<S2>/OpMonitor' (Parameter: P1Size)
   */
  { 1.0, 1.0 },

  /* Expression: compute_time
   * Referenced by: '<S2>/OpMonitor' (Parameter: P1)
   */
  1.0,

  /* Computed Parameter: OpMonitor_P2_Size
   * Referenced by: '<S2>/OpMonitor' (Parameter: P2Size)
   */
  { 1.0, 1.0 },

  /* Expression: real_step
   * Referenced by: '<S2>/OpMonitor' (Parameter: P2)
   */
  1.0,

  /* Computed Parameter: OpMonitor_P3_Size
   * Referenced by: '<S2>/OpMonitor' (Parameter: P3Size)
   */
  { 1.0, 1.0 },

  /* Expression: idle_time
   * Referenced by: '<S2>/OpMonitor' (Parameter: P3)
   */
  1.0,

  /* Computed Parameter: OpMonitor_P4_Size
   * Referenced by: '<S2>/OpMonitor' (Parameter: P4Size)
   */
  { 1.0, 1.0 },

  /* Expression: nb_overruns
   * Referenced by: '<S2>/OpMonitor' (Parameter: P4)
   */
  1.0,

  /* Computed Parameter: OpMonitor_P5_Size
   * Referenced by: '<S2>/OpMonitor' (Parameter: P5Size)
   */
  { 1.0, 1.0 },

  /* Expression: user_time
   * Referenced by: '<S2>/OpMonitor' (Parameter: P5)
   */
  0.0,

  /* Computed Parameter: OpMonitor_P6_Size
   * Referenced by: '<S2>/OpMonitor' (Parameter: P6Size)
   */
  { 1.0, 32.0 },

  /* Computed Parameter: OpMonitor_P6
   * Referenced by: '<S2>/OpMonitor' (Parameter: P6)
   */
  { 109.0, 121.0, 95.0, 101.0, 118.0, 101.0, 110.0, 116.0, 95.0, 110.0, 97.0,
    109.0, 101.0, 44.0, 97.0, 110.0, 111.0, 116.0, 104.0, 101.0, 114.0, 95.0,
    101.0, 118.0, 101.0, 110.0, 116.0, 95.0, 110.0, 97.0, 109.0, 101.0 },

  /* Computed Parameter: SFunction_P1_Size_g
   * Referenced by: '<S15>/S-Function' (Parameter: P1Size)
   */
  { 1.0, 1.0 },

  /* Expression: Acqu_group
   * Referenced by: '<S15>/S-Function' (Parameter: P1)
   */
  1.0
};
