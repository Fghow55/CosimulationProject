/*
 * dc_microgrid_6_1_sm_circuit_data.c
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

/* Block parameters (default storage) */
P_dc_microgrid_6_1_sm_circuit_T dc_microgrid_6_1_sm_circuit_P = {
  /* Variable: Fnom
   * Referenced by: '<S30>/Freq1' (Parameter: Value)
   */
  50.0,

  /* Variable: max_min
   * Referenced by: '<S30>/Constant1' (Parameter: Value)
   */
  1.0,

  /* Mask Parameter: Fourier1_Freq
   * Referenced by:
   *   '<S73>/cos(wt)' (Parameter: Frequency)
   *   '<S73>/sin(wt)' (Parameter: Frequency)
   */
  50.0,

  /* Mask Parameter: Fourier_Freq
   * Referenced by:
   *   '<S61>/cos(wt)' (Parameter: Frequency)
   *   '<S61>/sin(wt)' (Parameter: Frequency)
   */
  50.0,

  /* Mask Parameter: Fourier1_Freq_g
   * Referenced by:
   *   '<S62>/cos(wt)' (Parameter: Frequency)
   *   '<S62>/sin(wt)' (Parameter: Frequency)
   */
  50.0,

  /* Mask Parameter: Vab3_Freq
   * Referenced by:
   *   '<S48>/K2' (Parameter: Value)
   *   '<S48>/Step' (Parameter: Time)
   */
  60.0,

  /* Mask Parameter: Vab5_Freq
   * Referenced by:
   *   '<S50>/K2' (Parameter: Value)
   *   '<S50>/Step' (Parameter: Time)
   */
  60.0,

  /* Mask Parameter: Vab1_Freq
   * Referenced by:
   *   '<S44>/K2' (Parameter: Value)
   *   '<S44>/Step' (Parameter: Time)
   */
  60.0,

  /* Mask Parameter: Vab2_Freq
   * Referenced by:
   *   '<S46>/K2' (Parameter: Value)
   *   '<S46>/Step' (Parameter: Time)
   */
  60.0,

  /* Mask Parameter: DiscretePWMGenerator1_Internal
   * Referenced by: '<S25>/Constant1' (Parameter: Value)
   */
  0.0,

  /* Mask Parameter: Vab3_Mag_Init
   * Referenced by: '<S48>/Constant' (Parameter: Value)
   */
  0.0,

  /* Mask Parameter: Vab5_Mag_Init
   * Referenced by: '<S50>/Constant' (Parameter: Value)
   */
  0.0,

  /* Mask Parameter: Vab1_Mag_Init
   * Referenced by: '<S44>/Constant' (Parameter: Value)
   */
  0.0,

  /* Mask Parameter: Vab2_Mag_Init
   * Referenced by: '<S46>/Constant' (Parameter: Value)
   */
  0.0,

  /* Mask Parameter: RMS1_TrueRMS
   * Referenced by: '<S18>/Constant' (Parameter: Value)
   */
  1.0,

  /* Mask Parameter: Triangle_rep_seq_y
   * Referenced by: '<S27>/Look-Up Table1' (Parameter: Table)
   */
  { 0.0, -1.0, 1.0, 0.0 },

  /* Expression: Internal_Phase
   * Referenced by: '<S25>/Constant' (Parameter: Value)
   */
  { 0.0, -2.0943951023931953, 2.0943951023931953 },

  /* Expression: Phase
   * Referenced by: '<S25>/m3' (Parameter: Value)
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<S25>/Gain2' (Parameter: Gain)
   */
  0.017453292519943295,

  /* Expression: 2*pi*Freq
   * Referenced by: '<S25>/Gain' (Parameter: Gain)
   */
  376.99111843077515,

  /* Expression: mIndex
   * Referenced by: '<S25>/m4' (Parameter: Value)
   */
  0.99,

  /* Expression: 0
   * Referenced by: '<S30>/OP_max1' (Parameter: Value)
   */
  0.0,

  /* Expression: 228
   * Referenced by: '<S30>/OP_min1' (Parameter: Value)
   */
  228.0,

  /* Expression: sqrt(3)/2
   * Referenced by: '<S29>/K2' (Parameter: Value)
   */
  0.8660254037844386,

  /* Expression: 2*pi
   * Referenced by: '<S30>/Constant2' (Parameter: Value)
   */
  6.2831853071795862,

  /* Expression: 0
   * Referenced by: '<S30>/Switch2' (Parameter: Threshold)
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<S30>/Deg->Rad' (Parameter: Gain)
   */
  0.017453292519943295,

  /* Expression: 2*pi
   * Referenced by: '<S30>/Freq2' (Parameter: Value)
   */
  6.2831853071795862,

  /* Expression: 0.5
   * Referenced by: '<S29>/K1' (Parameter: Value)
   */
  0.5,

  /* Expression: 1.2
   * Referenced by: '<S28>/OP_max1' (Parameter: Value)
   */
  1.2,

  /* Expression: 1
   * Referenced by: '<S28>/OP_min1' (Parameter: Value)
   */
  1.0,

  /* Expression: K1
   * Referenced by: '<S44>/Gain' (Parameter: Gain)
   */
  0.0003333333333333523,

  /* Expression: K2
   * Referenced by: '<S44>/Gain1' (Parameter: Gain)
   */
  -0.0016666666666667045,

  /* Expression: K1
   * Referenced by: '<S46>/Gain' (Parameter: Gain)
   */
  0.0003333333333333523,

  /* Expression: K2
   * Referenced by: '<S46>/Gain1' (Parameter: Gain)
   */
  -0.0016666666666667045,

  /* Expression: K1
   * Referenced by: '<S48>/Gain' (Parameter: Gain)
   */
  0.0003333333333333523,

  /* Expression: K2
   * Referenced by: '<S48>/Gain1' (Parameter: Gain)
   */
  -0.0016666666666667045,

  /* Expression: K1
   * Referenced by: '<S50>/Gain' (Parameter: Gain)
   */
  0.0003333333333333523,

  /* Expression: K2
   * Referenced by: '<S50>/Gain1' (Parameter: Gain)
   */
  -0.0016666666666667045,

  /* Expression: sps.Freq
   * Referenced by: '<S65>/Gain' (Parameter: Gain)
   */
  50.0,

  /* Expression: sps.Freq
   * Referenced by: '<S66>/Gain' (Parameter: Gain)
   */
  50.0,

  /* Expression: sps.Freq
   * Referenced by: '<S69>/Gain' (Parameter: Gain)
   */
  50.0,

  /* Expression: sps.Freq
   * Referenced by: '<S70>/Gain' (Parameter: Gain)
   */
  50.0,

  /* Expression: sps.Freq
   * Referenced by: '<S76>/Gain' (Parameter: Gain)
   */
  50.0,

  /* Expression: sps.Freq
   * Referenced by: '<S77>/Gain' (Parameter: Gain)
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<S77>/integrator' (Parameter: InitialCondition)
   */
  0.0,

  /* Expression: 1./sps.Freq
   * Referenced by: '<S77>/Transport Delay' (Parameter: DelayTime)
   */
  0.02,

  /* Expression: 0
   * Referenced by: '<S77>/Transport Delay' (Parameter: InitialOutput)
   */
  0.0,

  /* Expression: 1./sps.Freq
   * Referenced by: '<S77>/K1' (Parameter: Value)
   */
  0.02,

  /* Expression: sps.Vinit
   * Referenced by: '<S77>/Memory' (Parameter: InitialCondition)
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S76>/integrator' (Parameter: InitialCondition)
   */
  0.0,

  /* Expression: 1./sps.Freq
   * Referenced by: '<S76>/Transport Delay' (Parameter: DelayTime)
   */
  0.02,

  /* Expression: 0
   * Referenced by: '<S76>/Transport Delay' (Parameter: InitialOutput)
   */
  0.0,

  /* Expression: 1./sps.Freq
   * Referenced by: '<S76>/K1' (Parameter: Value)
   */
  0.02,

  /* Expression: sps.Vinit
   * Referenced by: '<S76>/Memory' (Parameter: InitialCondition)
   */
  0.0,

  /* Expression: sps.k
   * Referenced by: '<S73>/sin(wt)' (Parameter: Amplitude)
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S73>/sin(wt)' (Parameter: Bias)
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S73>/sin(wt)' (Parameter: Phase)
   */
  0.0,

  /* Expression: sps.k
   * Referenced by: '<S73>/cos(wt)' (Parameter: Amplitude)
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S73>/cos(wt)' (Parameter: Bias)
   */
  0.0,

  /* Expression: pi/2
   * Referenced by: '<S73>/cos(wt)' (Parameter: Phase)
   */
  1.5707963267948966,

  /* Expression: 180/pi
   * Referenced by: '<S73>/Rad->Deg.' (Parameter: Gain)
   */
  57.295779513082323,

  /* Expression: 1/sqrt(2)
   * Referenced by: '<S71>/Gain' (Parameter: Gain)
   */
  0.70710678118654746,

  /* Expression: sps.Freq
   * Referenced by: '<S79>/Gain' (Parameter: Gain)
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<S79>/integrator' (Parameter: InitialCondition)
   */
  0.0,

  /* Expression: 1./sps.Freq
   * Referenced by: '<S79>/Transport Delay' (Parameter: DelayTime)
   */
  0.02,

  /* Expression: 0
   * Referenced by: '<S79>/Transport Delay' (Parameter: InitialOutput)
   */
  0.0,

  /* Expression: 1./sps.Freq
   * Referenced by: '<S79>/K1' (Parameter: Value)
   */
  0.02,

  /* Expression: sps.Vinit
   * Referenced by: '<S79>/Memory' (Parameter: InitialCondition)
   */
  0.0,

  /* Expression: Inf
   * Referenced by: '<S72>/Saturation to avoid negative sqrt' (Parameter: UpperLimit)
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S72>/Saturation to avoid negative sqrt' (Parameter: LowerLimit)
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/S-Function1' (Parameter: Value)
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/S-Function' (Parameter: InitialCondition)
   */
  0.0,

  /* Expression: zeros(1,Switches)
   * Referenced by: '<S31>/Constant' (Parameter: Value)
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<S3>/Sine Wave3' (Parameter: Amplitude)
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S3>/Sine Wave3' (Parameter: Bias)
   */
  0.0,

  /* Expression: 2*pi*50
   * Referenced by: '<S3>/Sine Wave3' (Parameter: Frequency)
   */
  314.15926535897933,

  /* Expression: 0
   * Referenced by: '<S3>/Sine Wave3' (Parameter: Phase)
   */
  0.0,

  /* Computed Parameter: SFunction_P1_Size
   * Referenced by: '<S57>/S-Function' (Parameter: P1Size)
   */
  { 1.0, 1.0 },

  /* Expression: Data_width
   * Referenced by: '<S57>/S-Function' (Parameter: P1)
   */
  2.0,

  /* Computed Parameter: SFunction_P2_Size
   * Referenced by: '<S57>/S-Function' (Parameter: P2Size)
   */
  { 2.0, 1.0 },

  /* Expression: InitialConditions
   * Referenced by: '<S57>/S-Function' (Parameter: P2)
   */
  { -5000.0, 400.0 },

  /* Expression: sqrt(2)
   * Referenced by: '<S3>/Constant' (Parameter: Value)
   */
  1.4142135623730951,

  /* Expression: 1
   * Referenced by: '<S3>/Sine Wave4' (Parameter: Amplitude)
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S3>/Sine Wave4' (Parameter: Bias)
   */
  0.0,

  /* Expression: 2*pi*50
   * Referenced by: '<S3>/Sine Wave4' (Parameter: Frequency)
   */
  314.15926535897933,

  /* Expression: -2*pi/3
   * Referenced by: '<S3>/Sine Wave4' (Parameter: Phase)
   */
  -2.0943951023931953,

  /* Expression: 1
   * Referenced by: '<S3>/Sine Wave5' (Parameter: Amplitude)
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S3>/Sine Wave5' (Parameter: Bias)
   */
  0.0,

  /* Expression: 2*pi*50
   * Referenced by: '<S3>/Sine Wave5' (Parameter: Frequency)
   */
  314.15926535897933,

  /* Expression: 2*pi/3
   * Referenced by: '<S3>/Sine Wave5' (Parameter: Phase)
   */
  2.0943951023931953,

  /* Expression: 1e9
   * Referenced by: '<S3>/Delay1' (Parameter: InitialCondition)
   */
  1.0E+9,

  /* Expression: S.A
   * Referenced by: '<S4>/State-Space' (Parameter: AS_param)
   */
  { 0.99999875000182292, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.99203250733628945,
    -9.41900637346782E-19, -0.015933296398002915, 0.015933296398003005,
    -6.3696877633523385E-19, 0.0, -5.7687292171443526E-17, -0.99203250733628934,
    -0.015933296398003005, 1.9176395328172843E-16, 0.015933296398003005, 0.0,
    1.407441110596487E-9, 1.4074410705018268E-9, -0.99978802809878609,
    2.8145840781753405E-9, 2.8145839482638253E-9, 0.0, -2.814882437267699E-9,
    1.4074411295899981E-9, 2.8145841635491073E-9, -0.9997880280987862,
    2.8145839883234015E-9, 0.0, 1.4074411818234197E-9, -2.8148823617844853E-9,
    2.8145839944491438E-9, 2.8145840177418045E-9, -0.99978802809878609 },

  /* Expression: S.B
   * Referenced by: '<S4>/State-Space' (Parameter: BS_param)
   */
  { -416.666059028664, -6639.5772197588722, -6639.5772197588713,
    26555.493996671845, -13277.746998335922, -13277.746998335921,
    -416.666059028664, 6639.5772197588722, 6639.5772197588713,
    -26555.493996671845, 13277.746998335922, 13277.746998335921,
    -416.666059028664, 13279.154439517746, -6639.577219758874,
    -13277.746998335924, 26555.493996671845, -13277.746998335922,
    -416.666059028664, -13279.154439517746, 6639.577219758874,
    13277.746998335924, -26555.493996671845, 13277.746998335922,
    -416.666059028664, -6639.577219758874, 13279.154439517744,
    -13277.746998335919, -13277.746998335924, 26555.493996671841,
    -416.666059028664, 6639.577219758874, -13279.154439517744,
    13277.746998335919, 13277.746998335924, -26555.493996671841, 0.0,
    0.13277746998478393, 0.13277746998558587, 19997.349171107926,
    0.26552679412533226, 0.26552679412793073, 0.0, -0.26555493996524593,
    0.13277746998440404, 0.26552679412362468, 19997.34917110793,
    0.26552679412712948, 0.0, 0.13277746998335926, -0.26555493996675567,
    0.26552679412700692, 0.26552679412654112, 19997.349171107926,
    -833.332118057328, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: S.C
   * Referenced by: '<S4>/State-Space' (Parameter: CS_param)
   */
  { 4.9999968750045576E-5, 4.9999968750045576E-5, 4.9999968750045576E-5,
    4.9999968750045576E-5, 4.9999968750045576E-5, 4.9999968750045576E-5, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 9.9999937500091151E-5,
    -1.2499981770859925E-15, 0.0, 0.0, 0.0, -0.019918731659276621,
    0.019918731659276621, 0.019918731659276625, -0.019918731659276625,
    -2.3541420338770195E-18, 2.3541420338770195E-18, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.9833240995007773E-7, -3.9833240995007773E-7,
    1.5960170884855082E-23, -0.019918731659276618, 0.019918731659276618,
    -1.7023078462460194E-18, 1.7023078462460194E-18, 0.019918731659276618,
    -0.019918731659276618, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    3.9833240995007768E-7, 1.423182415352901E-23, -3.9833240995007768E-7,
    -7.0372059092148E-9, 7.0372059092148E-9, 3.5186029545967745E-9,
    -3.5186029545967745E-9, 3.518602954618026E-9, -3.518602954618026E-9, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -5.299297530343601E-9,
    -7.036460044321305E-14, -7.0364600443901657E-14, 3.5186029544923103E-9,
    -3.5186029544923103E-9, -7.0372059090790176E-9, 7.0372059090790176E-9,
    3.5186029545867073E-9, -3.5186029545867073E-9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, -7.0364600442760547E-14, -5.2992975303436018E-9,
    -7.0364600443689321E-14, 3.5186029545600051E-9, -3.5186029545600051E-9,
    3.5186029545590212E-9, -3.5186029545590212E-9, -7.0372059091190259E-9,
    7.0372059091190259E-9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -7.0364600443656832E-14, -7.03646004435334E-14, -5.299297530343601E-9 },

  /* Expression: S.D
   * Referenced by: '<S4>/State-Space' (Parameter: DS_param)
   */
  { -16802.124317857117, 16802.103484554165, -16598.953466048661,
    16598.932632745709, -16598.953466048653, 16598.932632745702, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0208333029514332, -4.16666059028664E-7,
    -0.6638873499167961, 0.33194367495839805, 0.33194367495839805,
    16802.103484554165, -16802.124317857117, 16598.932632745709,
    -16598.953466048661, 16598.932632745702, -16598.953466048653, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0208333029514332, -4.16666059028664E-7,
    0.6638873499167961, -0.33194367495839805, -0.33194367495839805,
    -16598.953466048661, 16598.932632745709, -16802.124317857109,
    16802.103484554158, -16598.953466048657, 16598.932632745709, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0208333029514332, -4.16666059028664E-7,
    0.33194367495839811, -0.6638873499167961, 0.33194367495839805,
    16598.932632745709, -16598.953466048661, 16802.103484554158,
    -16802.124317857109, 16598.932632745709, -16598.953466048657, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0208333029514332, -4.16666059028664E-7,
    -0.33194367495839811, 0.6638873499167961, -0.33194367495839805,
    -16598.953466048653, 16598.932632745702, -16598.953466048664,
    16598.932632745709, -16802.124317857117, 16802.103484554165, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0208333029514332, -4.16666059028664E-7,
    0.331943674958398, 0.33194367495839811, -0.6638873499167961,
    16598.932632745702, -16598.953466048653, 16598.932632745709,
    -16598.953466048664, 16802.103484554165, -16802.124317857117, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0208333029514332, -4.16666059028664E-7,
    -0.331943674958398, -0.33194367495839811, 0.6638873499167961,
    -0.66388734992592457, 0.66388734992592457, 0.33194367496195981,
    -0.33194367496195981, 0.33194367496396471, -0.33194367496396471, 1.0, 0.0,
    -1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 6.627072230180886E-5,
    -6.6381698531333069E-6, -6.6381698531982684E-6, 0.33194367495210469,
    -0.33194367495210469, -0.66388734991311482, 0.66388734991311482,
    0.33194367496101013, -0.33194367496101013, -1.0, 1.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, -6.6381698530906173E-6, 6.6270722301753349E-5,
    -6.6381698531782378E-6, 0.33194367495849103, -0.33194367495849103,
    0.33194367495839822, -0.33194367495839822, -0.66388734991688925,
    0.66388734991688925, 0.0, -1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    -6.6381698531751732E-6, -6.6381698531635282E-6, 6.627072230180886E-5,
    -0.0208333029514332, -0.0208333029514332, -0.0208333029514332,
    -0.0208333029514332, -0.0208333029514332, -0.0208333029514332, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0416666059028664, 0.99999916666788191, 0.0,
    0.0, 0.0 },

  /* Expression: S.x0
   * Referenced by: '<S4>/State-Space' (Parameter: X0_param)
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S66>/integrator' (Parameter: InitialCondition)
   */
  0.0,

  /* Expression: 1./sps.Freq
   * Referenced by: '<S66>/Transport Delay' (Parameter: DelayTime)
   */
  0.02,

  /* Expression: 0
   * Referenced by: '<S66>/Transport Delay' (Parameter: InitialOutput)
   */
  0.0,

  /* Expression: 1./sps.Freq
   * Referenced by: '<S66>/K1' (Parameter: Value)
   */
  0.02,

  /* Expression: sps.Vinit
   * Referenced by: '<S66>/Memory' (Parameter: InitialCondition)
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S65>/integrator' (Parameter: InitialCondition)
   */
  0.0,

  /* Expression: 1./sps.Freq
   * Referenced by: '<S65>/Transport Delay' (Parameter: DelayTime)
   */
  0.02,

  /* Expression: 0
   * Referenced by: '<S65>/Transport Delay' (Parameter: InitialOutput)
   */
  0.0,

  /* Expression: 1./sps.Freq
   * Referenced by: '<S65>/K1' (Parameter: Value)
   */
  0.02,

  /* Expression: sps.Vinit
   * Referenced by: '<S65>/Memory' (Parameter: InitialCondition)
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S70>/integrator' (Parameter: InitialCondition)
   */
  0.0,

  /* Expression: 1./sps.Freq
   * Referenced by: '<S70>/Transport Delay' (Parameter: DelayTime)
   */
  0.02,

  /* Expression: 0
   * Referenced by: '<S70>/Transport Delay' (Parameter: InitialOutput)
   */
  0.0,

  /* Expression: 1./sps.Freq
   * Referenced by: '<S70>/K1' (Parameter: Value)
   */
  0.02,

  /* Expression: sps.Vinit
   * Referenced by: '<S70>/Memory' (Parameter: InitialCondition)
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S69>/integrator' (Parameter: InitialCondition)
   */
  0.0,

  /* Expression: 1./sps.Freq
   * Referenced by: '<S69>/Transport Delay' (Parameter: DelayTime)
   */
  0.02,

  /* Expression: 0
   * Referenced by: '<S69>/Transport Delay' (Parameter: InitialOutput)
   */
  0.0,

  /* Expression: 1./sps.Freq
   * Referenced by: '<S69>/K1' (Parameter: Value)
   */
  0.02,

  /* Expression: sps.Vinit
   * Referenced by: '<S69>/Memory' (Parameter: InitialCondition)
   */
  0.0,

  /* Expression: 1/2
   * Referenced by: '<S17>/Gain1' (Parameter: Gain)
   */
  0.5,

  /* Expression: 180/pi
   * Referenced by: '<S61>/Rad->Deg.' (Parameter: Gain)
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S62>/Rad->Deg.' (Parameter: Gain)
   */
  57.295779513082323,

  /* Expression: pi/180
   * Referenced by: '<S17>/Deg->Rad' (Parameter: Gain)
   */
  0.017453292519943295,

  /* Expression: 1
   * Referenced by: '<S83>/do not delete this gain' (Parameter: Gain)
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S84>/do not delete this gain' (Parameter: Gain)
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S85>/do not delete this gain' (Parameter: Gain)
   */
  1.0,

  /* Expression: Ki
   * Referenced by: '<S19>/Kv' (Parameter: Gain)
   */
  1.0,

  /* Computed Parameter: SFunction_P1_Size_h
   * Referenced by: '<S97>/S-Function' (Parameter: P1Size)
   */
  { 1.0, 1.0 },

  /* Expression: Acqu_group
   * Referenced by: '<S97>/S-Function' (Parameter: P1)
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S86>/do not delete this gain' (Parameter: Gain)
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S87>/do not delete this gain' (Parameter: Gain)
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S88>/do not delete this gain' (Parameter: Gain)
   */
  1.0,

  /* Expression: Kv
   * Referenced by: '<S19>/Kv1' (Parameter: Gain)
   */
  1.0,

  /* Expression: sps.k
   * Referenced by: '<S61>/sin(wt)' (Parameter: Amplitude)
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S61>/sin(wt)' (Parameter: Bias)
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S61>/sin(wt)' (Parameter: Phase)
   */
  0.0,

  /* Expression: sps.k
   * Referenced by: '<S61>/cos(wt)' (Parameter: Amplitude)
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S61>/cos(wt)' (Parameter: Bias)
   */
  0.0,

  /* Expression: pi/2
   * Referenced by: '<S61>/cos(wt)' (Parameter: Phase)
   */
  1.5707963267948966,

  /* Expression: sps.k
   * Referenced by: '<S62>/sin(wt)' (Parameter: Amplitude)
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S62>/sin(wt)' (Parameter: Bias)
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S62>/sin(wt)' (Parameter: Phase)
   */
  0.0,

  /* Expression: sps.k
   * Referenced by: '<S62>/cos(wt)' (Parameter: Amplitude)
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S62>/cos(wt)' (Parameter: Bias)
   */
  0.0,

  /* Expression: pi/2
   * Referenced by: '<S62>/cos(wt)' (Parameter: Phase)
   */
  1.5707963267948966,

  /* Expression: 1
   * Referenced by: '<S20>/do not delete this gain' (Parameter: Gain)
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S13>/do not delete this gain' (Parameter: Gain)
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S23>/Unit Delay4' (Parameter: InitialCondition)
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S33>/do not delete this gain' (Parameter: Gain)
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S38>/do not delete this gain' (Parameter: Gain)
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S39>/do not delete this gain' (Parameter: Gain)
   */
  1.0,

  /* Computed Parameter: Integ4_gainval
   * Referenced by: '<S48>/Integ4' (Parameter: gainval)
   */
  5.0E-5,

  /* Expression: 0
   * Referenced by: '<S48>/Integ4' (Parameter: InitialCondition)
   */
  0.0,

  /* Expression: Delay
   * Referenced by: '<S48>/K1' (Parameter: Value)
   */
  0.0167,

  /* Expression: 0
   * Referenced by: '<S48>/Unit Delay' (Parameter: InitialCondition)
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S48>/Step' (Parameter: Before)
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S48>/Step' (Parameter: After)
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<S48>/Switch' (Parameter: Threshold)
   */
  0.5,

  /* Expression: Inf
   * Referenced by: '<S36>/Saturation Ajout P.B pour eviter  sqrt(negatif)' (Parameter: UpperLimit)
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S36>/Saturation Ajout P.B pour eviter  sqrt(negatif)' (Parameter: LowerLimit)
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S40>/do not delete this gain' (Parameter: Gain)
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S41>/do not delete this gain' (Parameter: Gain)
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S42>/do not delete this gain' (Parameter: Gain)
   */
  1.0,

  /* Computed Parameter: Integ4_gainval_b
   * Referenced by: '<S50>/Integ4' (Parameter: gainval)
   */
  5.0E-5,

  /* Expression: 0
   * Referenced by: '<S50>/Integ4' (Parameter: InitialCondition)
   */
  0.0,

  /* Expression: Delay
   * Referenced by: '<S50>/K1' (Parameter: Value)
   */
  0.0167,

  /* Expression: 0
   * Referenced by: '<S50>/Unit Delay' (Parameter: InitialCondition)
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S50>/Step' (Parameter: Before)
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S50>/Step' (Parameter: After)
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<S50>/Switch' (Parameter: Threshold)
   */
  0.5,

  /* Expression: Inf
   * Referenced by: '<S37>/Saturation Ajout P.B pour eviter  sqrt(negatif)' (Parameter: UpperLimit)
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S37>/Saturation Ajout P.B pour eviter  sqrt(negatif)' (Parameter: LowerLimit)
   */
  0.0,

  /* Computed Parameter: Integ4_gainval_b4
   * Referenced by: '<S44>/Integ4' (Parameter: gainval)
   */
  5.0E-5,

  /* Expression: 0
   * Referenced by: '<S44>/Integ4' (Parameter: InitialCondition)
   */
  0.0,

  /* Expression: Delay
   * Referenced by: '<S44>/K1' (Parameter: Value)
   */
  0.0167,

  /* Expression: 0
   * Referenced by: '<S44>/Unit Delay' (Parameter: InitialCondition)
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S44>/Step' (Parameter: Before)
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S44>/Step' (Parameter: After)
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<S44>/Switch' (Parameter: Threshold)
   */
  0.5,

  /* Expression: Inf
   * Referenced by: '<S34>/Saturation Ajout P.B pour eviter  sqrt(negatif)' (Parameter: UpperLimit)
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S34>/Saturation Ajout P.B pour eviter  sqrt(negatif)' (Parameter: LowerLimit)
   */
  0.0,

  /* Computed Parameter: Integ4_gainval_n
   * Referenced by: '<S46>/Integ4' (Parameter: gainval)
   */
  5.0E-5,

  /* Expression: 0
   * Referenced by: '<S46>/Integ4' (Parameter: InitialCondition)
   */
  0.0,

  /* Expression: Delay
   * Referenced by: '<S46>/K1' (Parameter: Value)
   */
  0.0167,

  /* Expression: 0
   * Referenced by: '<S46>/Unit Delay' (Parameter: InitialCondition)
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S46>/Step' (Parameter: Before)
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S46>/Step' (Parameter: After)
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<S46>/Switch' (Parameter: Threshold)
   */
  0.5,

  /* Expression: Inf
   * Referenced by: '<S35>/Saturation Ajout P.B pour eviter  sqrt(negatif)' (Parameter: UpperLimit)
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S35>/Saturation Ajout P.B pour eviter  sqrt(negatif)' (Parameter: LowerLimit)
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S28>/1 for max load, 0 for min' (Parameter: Value)
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S28>/Switch2' (Parameter: Threshold)
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S25>/Switch' (Parameter: Threshold)
   */
  0.0,

  /* Expression: period
   * Referenced by: '<S27>/Constant' (Parameter: Value)
   */
  0.00025,

  /* Expression: rep_seq_t - min(rep_seq_t)
   * Referenced by: '<S27>/Look-Up Table1' (Parameter: BreakpointsForDimension1)
   */
  { 0.0, 6.25E-5, 0.0001875, 0.00025 },

  /* Expression: -1
   * Referenced by: '<S25>/Gain3' (Parameter: Gain)
   */
  -1.0
};
