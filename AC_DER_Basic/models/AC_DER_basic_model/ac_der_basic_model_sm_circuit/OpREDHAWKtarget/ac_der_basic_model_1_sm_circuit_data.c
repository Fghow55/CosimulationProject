/*
 * ac_der_basic_model_1_sm_circuit_data.c
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

/* Block parameters (default storage) */
P_ac_der_basic_model_1_sm_circuit_T ac_der_basic_model_1_sm_circuit_P = {
  /* Mask Parameter: RMS2_TrueRMS
   * Referenced by: '<S7>/Constant' (Parameter: Value)
   */
  1.0,

  /* Mask Parameter: RMS1_TrueRMS
   * Referenced by: '<S6>/Constant' (Parameter: Value)
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/S-Function1' (Parameter: Value)
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/S-Function' (Parameter: InitialCondition)
   */
  0.0,

  /* Computed Parameter: SFunction_P1_Size
   * Referenced by: '<S12>/S-Function' (Parameter: P1Size)
   */
  { 1.0, 1.0 },

  /* Expression: Data_width
   * Referenced by: '<S12>/S-Function' (Parameter: P1)
   */
  2.0,

  /* Computed Parameter: SFunction_P2_Size
   * Referenced by: '<S12>/S-Function' (Parameter: P2Size)
   */
  { 2.0, 1.0 },

  /* Expression: InitialConditions
   * Referenced by: '<S12>/S-Function' (Parameter: P2)
   */
  { -1000.0, 400.0 },

  /* Expression: sqrt(2)
   * Referenced by: '<S2>/Constant' (Parameter: Value)
   */
  1.4142135623730951,

  /* Expression: 1
   * Referenced by: '<S2>/Sine Wave1' (Parameter: Amplitude)
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Sine Wave1' (Parameter: Bias)
   */
  0.0,

  /* Expression: 2*pi*50
   * Referenced by: '<S2>/Sine Wave1' (Parameter: Frequency)
   */
  314.15926535897933,

  /* Expression: 0
   * Referenced by: '<S2>/Sine Wave1' (Parameter: Phase)
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/Sine Wave2' (Parameter: Amplitude)
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Sine Wave2' (Parameter: Bias)
   */
  0.0,

  /* Expression: 2*pi*50
   * Referenced by: '<S2>/Sine Wave2' (Parameter: Frequency)
   */
  314.15926535897933,

  /* Expression: -2*pi/3
   * Referenced by: '<S2>/Sine Wave2' (Parameter: Phase)
   */
  -2.0943951023931953,

  /* Expression: 1
   * Referenced by: '<S2>/Sine Wave3' (Parameter: Amplitude)
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Sine Wave3' (Parameter: Bias)
   */
  0.0,

  /* Expression: 2*pi*50
   * Referenced by: '<S2>/Sine Wave3' (Parameter: Frequency)
   */
  314.15926535897933,

  /* Expression: 2*pi/3
   * Referenced by: '<S2>/Sine Wave3' (Parameter: Phase)
   */
  2.0943951023931953,

  /* Expression: 1/3
   * Referenced by: '<S2>/Constant1' (Parameter: Value)
   */
  0.33333333333333331,

  /* Expression: sqrt(2)
   * Referenced by: '<S2>/Constant2' (Parameter: Value)
   */
  1.4142135623730951,

  /* Expression: 1
   * Referenced by: '<S2>/Sine Wave4' (Parameter: Amplitude)
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Sine Wave4' (Parameter: Bias)
   */
  0.0,

  /* Expression: 2*pi*50
   * Referenced by: '<S2>/Sine Wave4' (Parameter: Frequency)
   */
  314.15926535897933,

  /* Expression: 0
   * Referenced by: '<S2>/Sine Wave4' (Parameter: Phase)
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/Sine Wave5' (Parameter: Amplitude)
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Sine Wave5' (Parameter: Bias)
   */
  0.0,

  /* Expression: 2*pi*50
   * Referenced by: '<S2>/Sine Wave5' (Parameter: Frequency)
   */
  314.15926535897933,

  /* Expression: -2*pi/3
   * Referenced by: '<S2>/Sine Wave5' (Parameter: Phase)
   */
  -2.0943951023931953,

  /* Expression: 1
   * Referenced by: '<S2>/Sine Wave6' (Parameter: Amplitude)
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Sine Wave6' (Parameter: Bias)
   */
  0.0,

  /* Expression: 2*pi*50
   * Referenced by: '<S2>/Sine Wave6' (Parameter: Frequency)
   */
  314.15926535897933,

  /* Expression: 2*pi/3
   * Referenced by: '<S2>/Sine Wave6' (Parameter: Phase)
   */
  2.0943951023931953,

  /* Expression: 0
   * Referenced by: '<S2>/Delay' (Parameter: InitialCondition)
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<S2>/Constant3' (Parameter: Value)
   */
  3.0,

  /* Computed Parameter: SFunction_P1_Size_a
   * Referenced by: '<S40>/S-Function' (Parameter: P1Size)
   */
  { 1.0, 1.0 },

  /* Expression: Acqu_group
   * Referenced by: '<S40>/S-Function' (Parameter: P1)
   */
  1.0,

  /* Start of '<S7>/TrueRMS ' */
  {
    /* Expression: sps.Freq
     * Referenced by: '<S35>/Gain' (Parameter: Gain)
     */
    50.0,

    /* Expression: 0
     * Referenced by: '<S35>/integrator' (Parameter: InitialCondition)
     */
    0.0,

    /* Expression: 1./sps.Freq
     * Referenced by: '<S35>/Transport Delay' (Parameter: DelayTime)
     */
    0.02,

    /* Expression: 0
     * Referenced by: '<S35>/Transport Delay' (Parameter: InitialOutput)
     */
    0.0,

    /* Expression: 1./sps.Freq
     * Referenced by: '<S35>/K1' (Parameter: Value)
     */
    0.02,

    /* Expression: sps.Vinit
     * Referenced by: '<S35>/Memory' (Parameter: InitialCondition)
     */
    160000.0,

    /* Expression: Inf
     * Referenced by: '<S28>/Saturation to avoid negative sqrt' (Parameter: UpperLimit)
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S28>/Saturation to avoid negative sqrt' (Parameter: LowerLimit)
     */
    0.0
  }
  ,

  /* End of '<S7>/TrueRMS ' */

  /* Start of '<S7>/RMS ' */
  {
    /* Mask Parameter: Fourier1_Freq
     * Referenced by:
     *   '<S29>/cos(wt)' (Parameter: Frequency)
     *   '<S29>/sin(wt)' (Parameter: Frequency)
     */
    50.0,

    /* Expression: sps.Freq
     * Referenced by: '<S32>/Gain' (Parameter: Gain)
     */
    50.0,

    /* Expression: sps.Freq
     * Referenced by: '<S33>/Gain' (Parameter: Gain)
     */
    50.0,

    /* Expression: 0
     * Referenced by: '<S33>/integrator' (Parameter: InitialCondition)
     */
    0.0,

    /* Expression: 1./sps.Freq
     * Referenced by: '<S33>/Transport Delay' (Parameter: DelayTime)
     */
    0.02,

    /* Expression: 0
     * Referenced by: '<S33>/Transport Delay' (Parameter: InitialOutput)
     */
    0.0,

    /* Expression: 1./sps.Freq
     * Referenced by: '<S33>/K1' (Parameter: Value)
     */
    0.02,

    /* Expression: sps.Vinit
     * Referenced by: '<S33>/Memory' (Parameter: InitialCondition)
     */
    565.685424949238,

    /* Expression: 0
     * Referenced by: '<S32>/integrator' (Parameter: InitialCondition)
     */
    0.0,

    /* Expression: 1./sps.Freq
     * Referenced by: '<S32>/Transport Delay' (Parameter: DelayTime)
     */
    0.02,

    /* Expression: 0
     * Referenced by: '<S32>/Transport Delay' (Parameter: InitialOutput)
     */
    0.0,

    /* Expression: 1./sps.Freq
     * Referenced by: '<S32>/K1' (Parameter: Value)
     */
    0.02,

    /* Expression: sps.Vinit
     * Referenced by: '<S32>/Memory' (Parameter: InitialCondition)
     */
    0.0,

    /* Expression: sps.k
     * Referenced by: '<S29>/sin(wt)' (Parameter: Amplitude)
     */
    2.0,

    /* Expression: 0
     * Referenced by: '<S29>/sin(wt)' (Parameter: Bias)
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S29>/sin(wt)' (Parameter: Phase)
     */
    0.0,

    /* Expression: sps.k
     * Referenced by: '<S29>/cos(wt)' (Parameter: Amplitude)
     */
    2.0,

    /* Expression: 0
     * Referenced by: '<S29>/cos(wt)' (Parameter: Bias)
     */
    0.0,

    /* Expression: pi/2
     * Referenced by: '<S29>/cos(wt)' (Parameter: Phase)
     */
    1.5707963267948966,

    /* Expression: 180/pi
     * Referenced by: '<S29>/Rad->Deg.' (Parameter: Gain)
     */
    57.295779513082323,

    /* Expression: 1/sqrt(2)
     * Referenced by: '<S27>/Gain' (Parameter: Gain)
     */
    0.70710678118654746
  }
  ,

  /* End of '<S7>/RMS ' */

  /* Start of '<S6>/TrueRMS ' */
  {
    /* Expression: sps.Freq
     * Referenced by: '<S26>/Gain' (Parameter: Gain)
     */
    50.0,

    /* Expression: 0
     * Referenced by: '<S26>/integrator' (Parameter: InitialCondition)
     */
    0.0,

    /* Expression: 1./sps.Freq
     * Referenced by: '<S26>/Transport Delay' (Parameter: DelayTime)
     */
    0.02,

    /* Expression: 0
     * Referenced by: '<S26>/Transport Delay' (Parameter: InitialOutput)
     */
    0.0,

    /* Expression: 1./sps.Freq
     * Referenced by: '<S26>/K1' (Parameter: Value)
     */
    0.02,

    /* Expression: sps.Vinit
     * Referenced by: '<S26>/Memory' (Parameter: InitialCondition)
     */
    0.69444444444444453,

    /* Expression: Inf
     * Referenced by: '<S19>/Saturation to avoid negative sqrt' (Parameter: UpperLimit)
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S19>/Saturation to avoid negative sqrt' (Parameter: LowerLimit)
     */
    0.0
  }
  ,

  /* End of '<S6>/TrueRMS ' */

  /* Start of '<S6>/RMS ' */
  {
    /* Mask Parameter: Fourier1_Freq
     * Referenced by:
     *   '<S20>/cos(wt)' (Parameter: Frequency)
     *   '<S20>/sin(wt)' (Parameter: Frequency)
     */
    50.0,

    /* Expression: sps.Freq
     * Referenced by: '<S23>/Gain' (Parameter: Gain)
     */
    50.0,

    /* Expression: sps.Freq
     * Referenced by: '<S24>/Gain' (Parameter: Gain)
     */
    50.0,

    /* Expression: 0
     * Referenced by: '<S24>/integrator' (Parameter: InitialCondition)
     */
    0.0,

    /* Expression: 1./sps.Freq
     * Referenced by: '<S24>/Transport Delay' (Parameter: DelayTime)
     */
    0.02,

    /* Expression: 0
     * Referenced by: '<S24>/Transport Delay' (Parameter: InitialOutput)
     */
    0.0,

    /* Expression: 1./sps.Freq
     * Referenced by: '<S24>/K1' (Parameter: Value)
     */
    0.02,

    /* Expression: sps.Vinit
     * Referenced by: '<S24>/Memory' (Parameter: InitialCondition)
     */
    1.1785113019775793,

    /* Expression: 0
     * Referenced by: '<S23>/integrator' (Parameter: InitialCondition)
     */
    0.0,

    /* Expression: 1./sps.Freq
     * Referenced by: '<S23>/Transport Delay' (Parameter: DelayTime)
     */
    0.02,

    /* Expression: 0
     * Referenced by: '<S23>/Transport Delay' (Parameter: InitialOutput)
     */
    0.0,

    /* Expression: 1./sps.Freq
     * Referenced by: '<S23>/K1' (Parameter: Value)
     */
    0.02,

    /* Expression: sps.Vinit
     * Referenced by: '<S23>/Memory' (Parameter: InitialCondition)
     */
    0.0,

    /* Expression: sps.k
     * Referenced by: '<S20>/sin(wt)' (Parameter: Amplitude)
     */
    2.0,

    /* Expression: 0
     * Referenced by: '<S20>/sin(wt)' (Parameter: Bias)
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S20>/sin(wt)' (Parameter: Phase)
     */
    0.0,

    /* Expression: sps.k
     * Referenced by: '<S20>/cos(wt)' (Parameter: Amplitude)
     */
    2.0,

    /* Expression: 0
     * Referenced by: '<S20>/cos(wt)' (Parameter: Bias)
     */
    0.0,

    /* Expression: pi/2
     * Referenced by: '<S20>/cos(wt)' (Parameter: Phase)
     */
    1.5707963267948966,

    /* Expression: 180/pi
     * Referenced by: '<S20>/Rad->Deg.' (Parameter: Gain)
     */
    57.295779513082323,

    /* Expression: 1/sqrt(2)
     * Referenced by: '<S18>/Gain' (Parameter: Gain)
     */
    0.70710678118654746
  }
  /* End of '<S6>/RMS ' */
};
