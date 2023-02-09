#include "ac_der_basic_model_1_sm_circuit.h"
#include <stdlib.h>
#include <stdint.h>

// Declared in OpalSimCore
extern uint32_t opalNumParameters;
extern uint32_t opalNumSignals;
extern void** opalParametersAdressMapping;
extern uint32_t* opalParametersSizeMapping;
extern uint32_t* opalParametersNumElementsMapping;
extern void** opalSignalsAdressMapping;
extern uint32_t* opalSignalsSizeMapping;
extern uint32_t* opalSignalsNumElementsMapping;
void OpalUnInitAdress(void)
{
  opalNumParameters = 0;
  opalNumSignals = 0;
  if (opalParametersAdressMapping)
    free(opalParametersAdressMapping);
  if (opalParametersSizeMapping)
    free(opalParametersSizeMapping);
  if (opalParametersNumElementsMapping)
    free(opalParametersNumElementsMapping);
  if (opalSignalsAdressMapping)
    free(opalSignalsAdressMapping);
  if (opalSignalsSizeMapping)
    free(opalSignalsSizeMapping);
  if (opalSignalsNumElementsMapping)
    free(opalSignalsNumElementsMapping);
}

void OpalInitAdress(void)
{
  OpalUnInitAdress();
  opalParametersAdressMapping = (void**)malloc(sizeof(void*) * 97);
  opalParametersSizeMapping = (uint32_t*)malloc(sizeof(uint32_t) * 97);
  opalParametersNumElementsMapping = (uint32_t*)malloc(sizeof(uint32_t) * 97);
  opalSignalsAdressMapping = (void**)malloc(sizeof(void*) * 103);
  opalSignalsSizeMapping = (uint32_t*)malloc(sizeof(uint32_t) * 103);
  opalSignalsNumElementsMapping = (uint32_t*)malloc(sizeof(uint32_t) * 103);
  opalParametersAdressMapping[0] = (void*)&rtP.RMS2_TrueRMS;
  opalParametersSizeMapping[0] = sizeof(rtP.RMS2_TrueRMS);
  opalParametersNumElementsMapping[0] = 1;
  opalParametersAdressMapping[1] = (void*)&rtP.RMS1_TrueRMS;
  opalParametersSizeMapping[1] = sizeof(rtP.RMS1_TrueRMS);
  opalParametersNumElementsMapping[1] = 1;
  opalParametersAdressMapping[2] = (void*)&rtP.SFunction1_Value;
  opalParametersSizeMapping[2] = sizeof(rtP.SFunction1_Value);
  opalParametersNumElementsMapping[2] = 1;
  opalParametersAdressMapping[3] = (void*)&rtP.SFunction_InitialCondition;
  opalParametersSizeMapping[3] = sizeof(rtP.SFunction_InitialCondition);
  opalParametersNumElementsMapping[3] = 1;
  opalParametersAdressMapping[4] = (void*)&rtP.SFunction_P1_Size;
  opalParametersSizeMapping[4] = sizeof(rtP.SFunction_P1_Size[0]);
  opalParametersNumElementsMapping[4] = 2;
  opalParametersAdressMapping[5] = (void*)&rtP.SFunction_P1;
  opalParametersSizeMapping[5] = sizeof(rtP.SFunction_P1);
  opalParametersNumElementsMapping[5] = 1;
  opalParametersAdressMapping[6] = (void*)&rtP.SFunction_P2_Size;
  opalParametersSizeMapping[6] = sizeof(rtP.SFunction_P2_Size[0]);
  opalParametersNumElementsMapping[6] = 2;
  opalParametersAdressMapping[7] = (void*)&rtP.SFunction_P2;
  opalParametersSizeMapping[7] = sizeof(rtP.SFunction_P2[0]);
  opalParametersNumElementsMapping[7] = 2;
  opalParametersAdressMapping[8] = (void*)&rtP.Constant_Value;
  opalParametersSizeMapping[8] = sizeof(rtP.Constant_Value);
  opalParametersNumElementsMapping[8] = 1;
  opalParametersAdressMapping[9] = (void*)&rtP.SineWave1_Amp;
  opalParametersSizeMapping[9] = sizeof(rtP.SineWave1_Amp);
  opalParametersNumElementsMapping[9] = 1;
  opalParametersAdressMapping[10] = (void*)&rtP.SineWave1_Bias;
  opalParametersSizeMapping[10] = sizeof(rtP.SineWave1_Bias);
  opalParametersNumElementsMapping[10] = 1;
  opalParametersAdressMapping[11] = (void*)&rtP.SineWave1_Freq;
  opalParametersSizeMapping[11] = sizeof(rtP.SineWave1_Freq);
  opalParametersNumElementsMapping[11] = 1;
  opalParametersAdressMapping[12] = (void*)&rtP.SineWave1_Phase;
  opalParametersSizeMapping[12] = sizeof(rtP.SineWave1_Phase);
  opalParametersNumElementsMapping[12] = 1;
  opalParametersAdressMapping[13] = (void*)&rtP.SineWave2_Amp;
  opalParametersSizeMapping[13] = sizeof(rtP.SineWave2_Amp);
  opalParametersNumElementsMapping[13] = 1;
  opalParametersAdressMapping[14] = (void*)&rtP.SineWave2_Bias;
  opalParametersSizeMapping[14] = sizeof(rtP.SineWave2_Bias);
  opalParametersNumElementsMapping[14] = 1;
  opalParametersAdressMapping[15] = (void*)&rtP.SineWave2_Freq;
  opalParametersSizeMapping[15] = sizeof(rtP.SineWave2_Freq);
  opalParametersNumElementsMapping[15] = 1;
  opalParametersAdressMapping[16] = (void*)&rtP.SineWave2_Phase;
  opalParametersSizeMapping[16] = sizeof(rtP.SineWave2_Phase);
  opalParametersNumElementsMapping[16] = 1;
  opalParametersAdressMapping[17] = (void*)&rtP.SineWave3_Amp;
  opalParametersSizeMapping[17] = sizeof(rtP.SineWave3_Amp);
  opalParametersNumElementsMapping[17] = 1;
  opalParametersAdressMapping[18] = (void*)&rtP.SineWave3_Bias;
  opalParametersSizeMapping[18] = sizeof(rtP.SineWave3_Bias);
  opalParametersNumElementsMapping[18] = 1;
  opalParametersAdressMapping[19] = (void*)&rtP.SineWave3_Freq;
  opalParametersSizeMapping[19] = sizeof(rtP.SineWave3_Freq);
  opalParametersNumElementsMapping[19] = 1;
  opalParametersAdressMapping[20] = (void*)&rtP.SineWave3_Phase;
  opalParametersSizeMapping[20] = sizeof(rtP.SineWave3_Phase);
  opalParametersNumElementsMapping[20] = 1;
  opalParametersAdressMapping[21] = (void*)&rtP.Constant1_Value;
  opalParametersSizeMapping[21] = sizeof(rtP.Constant1_Value);
  opalParametersNumElementsMapping[21] = 1;
  opalParametersAdressMapping[22] = (void*)&rtP.Constant2_Value;
  opalParametersSizeMapping[22] = sizeof(rtP.Constant2_Value);
  opalParametersNumElementsMapping[22] = 1;
  opalParametersAdressMapping[23] = (void*)&rtP.SineWave4_Amp;
  opalParametersSizeMapping[23] = sizeof(rtP.SineWave4_Amp);
  opalParametersNumElementsMapping[23] = 1;
  opalParametersAdressMapping[24] = (void*)&rtP.SineWave4_Bias;
  opalParametersSizeMapping[24] = sizeof(rtP.SineWave4_Bias);
  opalParametersNumElementsMapping[24] = 1;
  opalParametersAdressMapping[25] = (void*)&rtP.SineWave4_Freq;
  opalParametersSizeMapping[25] = sizeof(rtP.SineWave4_Freq);
  opalParametersNumElementsMapping[25] = 1;
  opalParametersAdressMapping[26] = (void*)&rtP.SineWave4_Phase;
  opalParametersSizeMapping[26] = sizeof(rtP.SineWave4_Phase);
  opalParametersNumElementsMapping[26] = 1;
  opalParametersAdressMapping[27] = (void*)&rtP.SineWave5_Amp;
  opalParametersSizeMapping[27] = sizeof(rtP.SineWave5_Amp);
  opalParametersNumElementsMapping[27] = 1;
  opalParametersAdressMapping[28] = (void*)&rtP.SineWave5_Bias;
  opalParametersSizeMapping[28] = sizeof(rtP.SineWave5_Bias);
  opalParametersNumElementsMapping[28] = 1;
  opalParametersAdressMapping[29] = (void*)&rtP.SineWave5_Freq;
  opalParametersSizeMapping[29] = sizeof(rtP.SineWave5_Freq);
  opalParametersNumElementsMapping[29] = 1;
  opalParametersAdressMapping[30] = (void*)&rtP.SineWave5_Phase;
  opalParametersSizeMapping[30] = sizeof(rtP.SineWave5_Phase);
  opalParametersNumElementsMapping[30] = 1;
  opalParametersAdressMapping[31] = (void*)&rtP.SineWave6_Amp;
  opalParametersSizeMapping[31] = sizeof(rtP.SineWave6_Amp);
  opalParametersNumElementsMapping[31] = 1;
  opalParametersAdressMapping[32] = (void*)&rtP.SineWave6_Bias;
  opalParametersSizeMapping[32] = sizeof(rtP.SineWave6_Bias);
  opalParametersNumElementsMapping[32] = 1;
  opalParametersAdressMapping[33] = (void*)&rtP.SineWave6_Freq;
  opalParametersSizeMapping[33] = sizeof(rtP.SineWave6_Freq);
  opalParametersNumElementsMapping[33] = 1;
  opalParametersAdressMapping[34] = (void*)&rtP.SineWave6_Phase;
  opalParametersSizeMapping[34] = sizeof(rtP.SineWave6_Phase);
  opalParametersNumElementsMapping[34] = 1;
  opalParametersAdressMapping[35] = (void*)&rtP.Delay_InitialCondition;
  opalParametersSizeMapping[35] = sizeof(rtP.Delay_InitialCondition);
  opalParametersNumElementsMapping[35] = 1;
  opalParametersAdressMapping[36] = (void*)&rtP.Constant3_Value;
  opalParametersSizeMapping[36] = sizeof(rtP.Constant3_Value);
  opalParametersNumElementsMapping[36] = 1;
  opalParametersAdressMapping[37] = (void*)&rtP.SFunction_P1_Size_a;
  opalParametersSizeMapping[37] = sizeof(rtP.SFunction_P1_Size_a[0]);
  opalParametersNumElementsMapping[37] = 2;
  opalParametersAdressMapping[38] = (void*)&rtP.SFunction_P1_h;
  opalParametersSizeMapping[38] = sizeof(rtP.SFunction_P1_h);
  opalParametersNumElementsMapping[38] = 1;
  opalParametersAdressMapping[39] = (void*)&rtP.TrueRMS_f.Gain_Gain;
  opalParametersSizeMapping[39] = sizeof(rtP.TrueRMS_f.Gain_Gain);
  opalParametersNumElementsMapping[39] = 1;
  opalParametersAdressMapping[40] = (void*)&rtP.TrueRMS_f.integrator_IC;
  opalParametersSizeMapping[40] = sizeof(rtP.TrueRMS_f.integrator_IC);
  opalParametersNumElementsMapping[40] = 1;
  opalParametersAdressMapping[41] = (void*)&rtP.TrueRMS_f.TransportDelay_Delay;
  opalParametersSizeMapping[41] = sizeof(rtP.TrueRMS_f.TransportDelay_Delay);
  opalParametersNumElementsMapping[41] = 1;
  opalParametersAdressMapping[42] = (void*)
    &rtP.TrueRMS_f.TransportDelay_InitOutput;
  opalParametersSizeMapping[42] = sizeof(rtP.TrueRMS_f.TransportDelay_InitOutput);
  opalParametersNumElementsMapping[42] = 1;
  opalParametersAdressMapping[43] = (void*)&rtP.TrueRMS_f.K1_Value;
  opalParametersSizeMapping[43] = sizeof(rtP.TrueRMS_f.K1_Value);
  opalParametersNumElementsMapping[43] = 1;
  opalParametersAdressMapping[44] = (void*)
    &rtP.TrueRMS_f.Memory_InitialCondition;
  opalParametersSizeMapping[44] = sizeof(rtP.TrueRMS_f.Memory_InitialCondition);
  opalParametersNumElementsMapping[44] = 1;
  opalParametersAdressMapping[45] = (void*)
    &rtP.TrueRMS_f.Saturationtoavoidnegativesqrt_U;
  opalParametersSizeMapping[45] = sizeof
    (rtP.TrueRMS_f.Saturationtoavoidnegativesqrt_U);
  opalParametersNumElementsMapping[45] = 1;
  opalParametersAdressMapping[46] = (void*)
    &rtP.TrueRMS_f.Saturationtoavoidnegativesqrt_L;
  opalParametersSizeMapping[46] = sizeof
    (rtP.TrueRMS_f.Saturationtoavoidnegativesqrt_L);
  opalParametersNumElementsMapping[46] = 1;
  opalParametersAdressMapping[47] = (void*)&rtP.RMS_l.Fourier1_Freq;
  opalParametersSizeMapping[47] = sizeof(rtP.RMS_l.Fourier1_Freq);
  opalParametersNumElementsMapping[47] = 1;
  opalParametersAdressMapping[48] = (void*)&rtP.RMS_l.Gain_Gain;
  opalParametersSizeMapping[48] = sizeof(rtP.RMS_l.Gain_Gain);
  opalParametersNumElementsMapping[48] = 1;
  opalParametersAdressMapping[49] = (void*)&rtP.RMS_l.Gain_Gain_m;
  opalParametersSizeMapping[49] = sizeof(rtP.RMS_l.Gain_Gain_m);
  opalParametersNumElementsMapping[49] = 1;
  opalParametersAdressMapping[50] = (void*)&rtP.RMS_l.integrator_IC;
  opalParametersSizeMapping[50] = sizeof(rtP.RMS_l.integrator_IC);
  opalParametersNumElementsMapping[50] = 1;
  opalParametersAdressMapping[51] = (void*)&rtP.RMS_l.TransportDelay_Delay;
  opalParametersSizeMapping[51] = sizeof(rtP.RMS_l.TransportDelay_Delay);
  opalParametersNumElementsMapping[51] = 1;
  opalParametersAdressMapping[52] = (void*)&rtP.RMS_l.TransportDelay_InitOutput;
  opalParametersSizeMapping[52] = sizeof(rtP.RMS_l.TransportDelay_InitOutput);
  opalParametersNumElementsMapping[52] = 1;
  opalParametersAdressMapping[53] = (void*)&rtP.RMS_l.K1_Value;
  opalParametersSizeMapping[53] = sizeof(rtP.RMS_l.K1_Value);
  opalParametersNumElementsMapping[53] = 1;
  opalParametersAdressMapping[54] = (void*)&rtP.RMS_l.Memory_InitialCondition;
  opalParametersSizeMapping[54] = sizeof(rtP.RMS_l.Memory_InitialCondition);
  opalParametersNumElementsMapping[54] = 1;
  opalParametersAdressMapping[55] = (void*)&rtP.RMS_l.integrator_IC_o;
  opalParametersSizeMapping[55] = sizeof(rtP.RMS_l.integrator_IC_o);
  opalParametersNumElementsMapping[55] = 1;
  opalParametersAdressMapping[56] = (void*)&rtP.RMS_l.TransportDelay_Delay_l;
  opalParametersSizeMapping[56] = sizeof(rtP.RMS_l.TransportDelay_Delay_l);
  opalParametersNumElementsMapping[56] = 1;
  opalParametersAdressMapping[57] = (void*)
    &rtP.RMS_l.TransportDelay_InitOutput_o;
  opalParametersSizeMapping[57] = sizeof(rtP.RMS_l.TransportDelay_InitOutput_o);
  opalParametersNumElementsMapping[57] = 1;
  opalParametersAdressMapping[58] = (void*)&rtP.RMS_l.K1_Value_g;
  opalParametersSizeMapping[58] = sizeof(rtP.RMS_l.K1_Value_g);
  opalParametersNumElementsMapping[58] = 1;
  opalParametersAdressMapping[59] = (void*)&rtP.RMS_l.Memory_InitialCondition_l;
  opalParametersSizeMapping[59] = sizeof(rtP.RMS_l.Memory_InitialCondition_l);
  opalParametersNumElementsMapping[59] = 1;
  opalParametersAdressMapping[60] = (void*)&rtP.RMS_l.sinwt_Amp;
  opalParametersSizeMapping[60] = sizeof(rtP.RMS_l.sinwt_Amp);
  opalParametersNumElementsMapping[60] = 1;
  opalParametersAdressMapping[61] = (void*)&rtP.RMS_l.sinwt_Bias;
  opalParametersSizeMapping[61] = sizeof(rtP.RMS_l.sinwt_Bias);
  opalParametersNumElementsMapping[61] = 1;
  opalParametersAdressMapping[62] = (void*)&rtP.RMS_l.sinwt_Phase;
  opalParametersSizeMapping[62] = sizeof(rtP.RMS_l.sinwt_Phase);
  opalParametersNumElementsMapping[62] = 1;
  opalParametersAdressMapping[63] = (void*)&rtP.RMS_l.coswt_Amp;
  opalParametersSizeMapping[63] = sizeof(rtP.RMS_l.coswt_Amp);
  opalParametersNumElementsMapping[63] = 1;
  opalParametersAdressMapping[64] = (void*)&rtP.RMS_l.coswt_Bias;
  opalParametersSizeMapping[64] = sizeof(rtP.RMS_l.coswt_Bias);
  opalParametersNumElementsMapping[64] = 1;
  opalParametersAdressMapping[65] = (void*)&rtP.RMS_l.coswt_Phase;
  opalParametersSizeMapping[65] = sizeof(rtP.RMS_l.coswt_Phase);
  opalParametersNumElementsMapping[65] = 1;
  opalParametersAdressMapping[66] = (void*)&rtP.RMS_l.RadDeg_Gain;
  opalParametersSizeMapping[66] = sizeof(rtP.RMS_l.RadDeg_Gain);
  opalParametersNumElementsMapping[66] = 1;
  opalParametersAdressMapping[67] = (void*)&rtP.RMS_l.Gain_Gain_b;
  opalParametersSizeMapping[67] = sizeof(rtP.RMS_l.Gain_Gain_b);
  opalParametersNumElementsMapping[67] = 1;
  opalParametersAdressMapping[68] = (void*)&rtP.TrueRMS.Gain_Gain;
  opalParametersSizeMapping[68] = sizeof(rtP.TrueRMS.Gain_Gain);
  opalParametersNumElementsMapping[68] = 1;
  opalParametersAdressMapping[69] = (void*)&rtP.TrueRMS.integrator_IC;
  opalParametersSizeMapping[69] = sizeof(rtP.TrueRMS.integrator_IC);
  opalParametersNumElementsMapping[69] = 1;
  opalParametersAdressMapping[70] = (void*)&rtP.TrueRMS.TransportDelay_Delay;
  opalParametersSizeMapping[70] = sizeof(rtP.TrueRMS.TransportDelay_Delay);
  opalParametersNumElementsMapping[70] = 1;
  opalParametersAdressMapping[71] = (void*)
    &rtP.TrueRMS.TransportDelay_InitOutput;
  opalParametersSizeMapping[71] = sizeof(rtP.TrueRMS.TransportDelay_InitOutput);
  opalParametersNumElementsMapping[71] = 1;
  opalParametersAdressMapping[72] = (void*)&rtP.TrueRMS.K1_Value;
  opalParametersSizeMapping[72] = sizeof(rtP.TrueRMS.K1_Value);
  opalParametersNumElementsMapping[72] = 1;
  opalParametersAdressMapping[73] = (void*)&rtP.TrueRMS.Memory_InitialCondition;
  opalParametersSizeMapping[73] = sizeof(rtP.TrueRMS.Memory_InitialCondition);
  opalParametersNumElementsMapping[73] = 1;
  opalParametersAdressMapping[74] = (void*)
    &rtP.TrueRMS.Saturationtoavoidnegativesqrt_U;
  opalParametersSizeMapping[74] = sizeof
    (rtP.TrueRMS.Saturationtoavoidnegativesqrt_U);
  opalParametersNumElementsMapping[74] = 1;
  opalParametersAdressMapping[75] = (void*)
    &rtP.TrueRMS.Saturationtoavoidnegativesqrt_L;
  opalParametersSizeMapping[75] = sizeof
    (rtP.TrueRMS.Saturationtoavoidnegativesqrt_L);
  opalParametersNumElementsMapping[75] = 1;
  opalParametersAdressMapping[76] = (void*)&rtP.RMS.Fourier1_Freq;
  opalParametersSizeMapping[76] = sizeof(rtP.RMS.Fourier1_Freq);
  opalParametersNumElementsMapping[76] = 1;
  opalParametersAdressMapping[77] = (void*)&rtP.RMS.Gain_Gain;
  opalParametersSizeMapping[77] = sizeof(rtP.RMS.Gain_Gain);
  opalParametersNumElementsMapping[77] = 1;
  opalParametersAdressMapping[78] = (void*)&rtP.RMS.Gain_Gain_m;
  opalParametersSizeMapping[78] = sizeof(rtP.RMS.Gain_Gain_m);
  opalParametersNumElementsMapping[78] = 1;
  opalParametersAdressMapping[79] = (void*)&rtP.RMS.integrator_IC;
  opalParametersSizeMapping[79] = sizeof(rtP.RMS.integrator_IC);
  opalParametersNumElementsMapping[79] = 1;
  opalParametersAdressMapping[80] = (void*)&rtP.RMS.TransportDelay_Delay;
  opalParametersSizeMapping[80] = sizeof(rtP.RMS.TransportDelay_Delay);
  opalParametersNumElementsMapping[80] = 1;
  opalParametersAdressMapping[81] = (void*)&rtP.RMS.TransportDelay_InitOutput;
  opalParametersSizeMapping[81] = sizeof(rtP.RMS.TransportDelay_InitOutput);
  opalParametersNumElementsMapping[81] = 1;
  opalParametersAdressMapping[82] = (void*)&rtP.RMS.K1_Value;
  opalParametersSizeMapping[82] = sizeof(rtP.RMS.K1_Value);
  opalParametersNumElementsMapping[82] = 1;
  opalParametersAdressMapping[83] = (void*)&rtP.RMS.Memory_InitialCondition;
  opalParametersSizeMapping[83] = sizeof(rtP.RMS.Memory_InitialCondition);
  opalParametersNumElementsMapping[83] = 1;
  opalParametersAdressMapping[84] = (void*)&rtP.RMS.integrator_IC_o;
  opalParametersSizeMapping[84] = sizeof(rtP.RMS.integrator_IC_o);
  opalParametersNumElementsMapping[84] = 1;
  opalParametersAdressMapping[85] = (void*)&rtP.RMS.TransportDelay_Delay_l;
  opalParametersSizeMapping[85] = sizeof(rtP.RMS.TransportDelay_Delay_l);
  opalParametersNumElementsMapping[85] = 1;
  opalParametersAdressMapping[86] = (void*)&rtP.RMS.TransportDelay_InitOutput_o;
  opalParametersSizeMapping[86] = sizeof(rtP.RMS.TransportDelay_InitOutput_o);
  opalParametersNumElementsMapping[86] = 1;
  opalParametersAdressMapping[87] = (void*)&rtP.RMS.K1_Value_g;
  opalParametersSizeMapping[87] = sizeof(rtP.RMS.K1_Value_g);
  opalParametersNumElementsMapping[87] = 1;
  opalParametersAdressMapping[88] = (void*)&rtP.RMS.Memory_InitialCondition_l;
  opalParametersSizeMapping[88] = sizeof(rtP.RMS.Memory_InitialCondition_l);
  opalParametersNumElementsMapping[88] = 1;
  opalParametersAdressMapping[89] = (void*)&rtP.RMS.sinwt_Amp;
  opalParametersSizeMapping[89] = sizeof(rtP.RMS.sinwt_Amp);
  opalParametersNumElementsMapping[89] = 1;
  opalParametersAdressMapping[90] = (void*)&rtP.RMS.sinwt_Bias;
  opalParametersSizeMapping[90] = sizeof(rtP.RMS.sinwt_Bias);
  opalParametersNumElementsMapping[90] = 1;
  opalParametersAdressMapping[91] = (void*)&rtP.RMS.sinwt_Phase;
  opalParametersSizeMapping[91] = sizeof(rtP.RMS.sinwt_Phase);
  opalParametersNumElementsMapping[91] = 1;
  opalParametersAdressMapping[92] = (void*)&rtP.RMS.coswt_Amp;
  opalParametersSizeMapping[92] = sizeof(rtP.RMS.coswt_Amp);
  opalParametersNumElementsMapping[92] = 1;
  opalParametersAdressMapping[93] = (void*)&rtP.RMS.coswt_Bias;
  opalParametersSizeMapping[93] = sizeof(rtP.RMS.coswt_Bias);
  opalParametersNumElementsMapping[93] = 1;
  opalParametersAdressMapping[94] = (void*)&rtP.RMS.coswt_Phase;
  opalParametersSizeMapping[94] = sizeof(rtP.RMS.coswt_Phase);
  opalParametersNumElementsMapping[94] = 1;
  opalParametersAdressMapping[95] = (void*)&rtP.RMS.RadDeg_Gain;
  opalParametersSizeMapping[95] = sizeof(rtP.RMS.RadDeg_Gain);
  opalParametersNumElementsMapping[95] = 1;
  opalParametersAdressMapping[96] = (void*)&rtP.RMS.Gain_Gain_b;
  opalParametersSizeMapping[96] = sizeof(rtP.RMS.Gain_Gain_b);
  opalParametersNumElementsMapping[96] = 1;
  opalSignalsAdressMapping[0] = (void*)&rtB.SFunction;
  opalSignalsSizeMapping[0] = sizeof(rtB.SFunction);
  opalSignalsNumElementsMapping[0] = 1;
  opalSignalsAdressMapping[1] = (void*)&rtB.Sum;
  opalSignalsSizeMapping[1] = sizeof(rtB.Sum);
  opalSignalsNumElementsMapping[1] = 1;
  opalSignalsAdressMapping[2] = (void*)&rtB.SFunction_c;
  opalSignalsSizeMapping[2] = sizeof(rtB.SFunction_c[0]);
  opalSignalsNumElementsMapping[2] = 2;
  opalSignalsAdressMapping[3] = (void*)&rtB.Sign;
  opalSignalsSizeMapping[3] = sizeof(rtB.Sign);
  opalSignalsNumElementsMapping[3] = 1;
  opalSignalsAdressMapping[4] = (void*)&rtB.Product1;
  opalSignalsSizeMapping[4] = sizeof(rtB.Product1);
  opalSignalsNumElementsMapping[4] = 1;
  opalSignalsAdressMapping[5] = (void*)&rtB.SineWave1;
  opalSignalsSizeMapping[5] = sizeof(rtB.SineWave1);
  opalSignalsNumElementsMapping[5] = 1;
  opalSignalsAdressMapping[6] = (void*)&rtB.SineWave2;
  opalSignalsSizeMapping[6] = sizeof(rtB.SineWave2);
  opalSignalsNumElementsMapping[6] = 1;
  opalSignalsAdressMapping[7] = (void*)&rtB.SineWave3;
  opalSignalsSizeMapping[7] = sizeof(rtB.SineWave3);
  opalSignalsNumElementsMapping[7] = 1;
  opalSignalsAdressMapping[8] = (void*)&rtB.Product2;
  opalSignalsSizeMapping[8] = sizeof(rtB.Product2[0]);
  opalSignalsNumElementsMapping[8] = 3;
  opalSignalsAdressMapping[9] = (void*)&rtB.INPUT_1_1_1;
  opalSignalsSizeMapping[9] = sizeof(rtB.INPUT_1_1_1[0]);
  opalSignalsNumElementsMapping[9] = 4;
  opalSignalsAdressMapping[10] = (void*)&rtB.Product3;
  opalSignalsSizeMapping[10] = sizeof(rtB.Product3);
  opalSignalsNumElementsMapping[10] = 1;
  opalSignalsAdressMapping[11] = (void*)&rtB.SineWave4;
  opalSignalsSizeMapping[11] = sizeof(rtB.SineWave4);
  opalSignalsNumElementsMapping[11] = 1;
  opalSignalsAdressMapping[12] = (void*)&rtB.SineWave5;
  opalSignalsSizeMapping[12] = sizeof(rtB.SineWave5);
  opalSignalsNumElementsMapping[12] = 1;
  opalSignalsAdressMapping[13] = (void*)&rtB.SineWave6;
  opalSignalsSizeMapping[13] = sizeof(rtB.SineWave6);
  opalSignalsNumElementsMapping[13] = 1;
  opalSignalsAdressMapping[14] = (void*)&rtB.Delay;
  opalSignalsSizeMapping[14] = sizeof(rtB.Delay);
  opalSignalsNumElementsMapping[14] = 1;
  opalSignalsAdressMapping[15] = (void*)&rtB.Switch;
  opalSignalsSizeMapping[15] = sizeof(rtB.Switch);
  opalSignalsNumElementsMapping[15] = 1;
  opalSignalsAdressMapping[16] = (void*)&rtB.Divide;
  opalSignalsSizeMapping[16] = sizeof(rtB.Divide[0]);
  opalSignalsNumElementsMapping[16] = 3;
  opalSignalsAdressMapping[17] = (void*)&rtB.Product6;
  opalSignalsSizeMapping[17] = sizeof(rtB.Product6[0]);
  opalSignalsNumElementsMapping[17] = 3;
  opalSignalsAdressMapping[18] = (void*)&rtB.INPUT_2_1_1;
  opalSignalsSizeMapping[18] = sizeof(rtB.INPUT_2_1_1[0]);
  opalSignalsNumElementsMapping[18] = 4;
  opalSignalsAdressMapping[19] = (void*)&rtB.LTI_OUTPUT_1_1;
  opalSignalsSizeMapping[19] = sizeof(rtB.LTI_OUTPUT_1_1);
  opalSignalsNumElementsMapping[19] = 1;
  opalSignalsAdressMapping[20] = (void*)&rtB.Switch_c;
  opalSignalsSizeMapping[20] = sizeof(rtB.Switch_c);
  opalSignalsNumElementsMapping[20] = 1;
  opalSignalsAdressMapping[21] = (void*)&rtB.Product4;
  opalSignalsSizeMapping[21] = sizeof(rtB.Product4);
  opalSignalsNumElementsMapping[21] = 1;
  opalSignalsAdressMapping[22] = (void*)&rtB.INPUT_1_1_2;
  opalSignalsSizeMapping[22] = sizeof(rtB.INPUT_1_1_2[0]);
  opalSignalsNumElementsMapping[22] = 4;
  opalSignalsAdressMapping[23] = (void*)&rtB.INPUT_1_1_3;
  opalSignalsSizeMapping[23] = sizeof(rtB.INPUT_1_1_3[0]);
  opalSignalsNumElementsMapping[23] = 4;
  opalSignalsAdressMapping[24] = (void*)&rtB.INPUT_2_1_2;
  opalSignalsSizeMapping[24] = sizeof(rtB.INPUT_2_1_2[0]);
  opalSignalsNumElementsMapping[24] = 4;
  opalSignalsAdressMapping[25] = (void*)&rtB.INPUT_2_1_3;
  opalSignalsSizeMapping[25] = sizeof(rtB.INPUT_2_1_3[0]);
  opalSignalsNumElementsMapping[25] = 4;
  opalSignalsAdressMapping[26] = (void*)&rtB.LTI_OUTPUT_1_2;
  opalSignalsSizeMapping[26] = sizeof(rtB.LTI_OUTPUT_1_2);
  opalSignalsNumElementsMapping[26] = 1;
  opalSignalsAdressMapping[27] = (void*)&rtB.DataTypeConversion;
  opalSignalsSizeMapping[27] = sizeof(rtB.DataTypeConversion);
  opalSignalsNumElementsMapping[27] = 1;
  opalSignalsAdressMapping[28] = (void*)&rtB.LogicalOperator;
  opalSignalsSizeMapping[28] = sizeof(rtB.LogicalOperator);
  opalSignalsNumElementsMapping[28] = 1;
  opalSignalsAdressMapping[29] = (void*)&rtB.DataTypeConversion_n;
  opalSignalsSizeMapping[29] = sizeof(rtB.DataTypeConversion_n);
  opalSignalsNumElementsMapping[29] = 1;
  opalSignalsAdressMapping[30] = (void*)&rtB.LogicalOperator_l;
  opalSignalsSizeMapping[30] = sizeof(rtB.LogicalOperator_l);
  opalSignalsNumElementsMapping[30] = 1;
  opalSignalsAdressMapping[31] = (void*)&rtB.TrueRMS_f.Clock;
  opalSignalsSizeMapping[31] = sizeof(rtB.TrueRMS_f.Clock);
  opalSignalsNumElementsMapping[31] = 1;
  opalSignalsAdressMapping[32] = (void*)&rtB.TrueRMS_f.integrator;
  opalSignalsSizeMapping[32] = sizeof(rtB.TrueRMS_f.integrator);
  opalSignalsNumElementsMapping[32] = 1;
  opalSignalsAdressMapping[33] = (void*)&rtB.TrueRMS_f.TransportDelay;
  opalSignalsSizeMapping[33] = sizeof(rtB.TrueRMS_f.TransportDelay);
  opalSignalsNumElementsMapping[33] = 1;
  opalSignalsAdressMapping[34] = (void*)&rtB.TrueRMS_f.Memory;
  opalSignalsSizeMapping[34] = sizeof(rtB.TrueRMS_f.Memory);
  opalSignalsNumElementsMapping[34] = 1;
  opalSignalsAdressMapping[35] = (void*)&rtB.TrueRMS_f.Switch;
  opalSignalsSizeMapping[35] = sizeof(rtB.TrueRMS_f.Switch);
  opalSignalsNumElementsMapping[35] = 1;
  opalSignalsAdressMapping[36] = (void*)&rtB.TrueRMS_f.Product;
  opalSignalsSizeMapping[36] = sizeof(rtB.TrueRMS_f.Product);
  opalSignalsNumElementsMapping[36] = 1;
  opalSignalsAdressMapping[37] = (void*)
    &rtB.TrueRMS_f.Saturationtoavoidnegativesqrt;
  opalSignalsSizeMapping[37] = sizeof
    (rtB.TrueRMS_f.Saturationtoavoidnegativesqrt);
  opalSignalsNumElementsMapping[37] = 1;
  opalSignalsAdressMapping[38] = (void*)&rtB.TrueRMS_f.Sqrt;
  opalSignalsSizeMapping[38] = sizeof(rtB.TrueRMS_f.Sqrt);
  opalSignalsNumElementsMapping[38] = 1;
  opalSignalsAdressMapping[39] = (void*)&rtB.TrueRMS_f.Sum;
  opalSignalsSizeMapping[39] = sizeof(rtB.TrueRMS_f.Sum);
  opalSignalsNumElementsMapping[39] = 1;
  opalSignalsAdressMapping[40] = (void*)&rtB.TrueRMS_f.Gain;
  opalSignalsSizeMapping[40] = sizeof(rtB.TrueRMS_f.Gain);
  opalSignalsNumElementsMapping[40] = 1;
  opalSignalsAdressMapping[41] = (void*)&rtB.TrueRMS_f.RelationalOperator;
  opalSignalsSizeMapping[41] = sizeof(rtB.TrueRMS_f.RelationalOperator);
  opalSignalsNumElementsMapping[41] = 1;
  opalSignalsAdressMapping[42] = (void*)&rtB.RMS_l.RealImagtoComplex;
  opalSignalsSizeMapping[42] = sizeof(((real_T*)(&rtB.RMS_l.RealImagtoComplex))
    [0]);
  opalSignalsNumElementsMapping[42] = 2;
  opalSignalsAdressMapping[43] = (void*)&rtB.RMS_l.integrator;
  opalSignalsSizeMapping[43] = sizeof(rtB.RMS_l.integrator);
  opalSignalsNumElementsMapping[43] = 1;
  opalSignalsAdressMapping[44] = (void*)&rtB.RMS_l.TransportDelay;
  opalSignalsSizeMapping[44] = sizeof(rtB.RMS_l.TransportDelay);
  opalSignalsNumElementsMapping[44] = 1;
  opalSignalsAdressMapping[45] = (void*)&rtB.RMS_l.Clock;
  opalSignalsSizeMapping[45] = sizeof(rtB.RMS_l.Clock);
  opalSignalsNumElementsMapping[45] = 1;
  opalSignalsAdressMapping[46] = (void*)&rtB.RMS_l.Memory;
  opalSignalsSizeMapping[46] = sizeof(rtB.RMS_l.Memory);
  opalSignalsNumElementsMapping[46] = 1;
  opalSignalsAdressMapping[47] = (void*)&rtB.RMS_l.Switch;
  opalSignalsSizeMapping[47] = sizeof(rtB.RMS_l.Switch);
  opalSignalsNumElementsMapping[47] = 1;
  opalSignalsAdressMapping[48] = (void*)&rtB.RMS_l.integrator_g;
  opalSignalsSizeMapping[48] = sizeof(rtB.RMS_l.integrator_g);
  opalSignalsNumElementsMapping[48] = 1;
  opalSignalsAdressMapping[49] = (void*)&rtB.RMS_l.TransportDelay_d;
  opalSignalsSizeMapping[49] = sizeof(rtB.RMS_l.TransportDelay_d);
  opalSignalsNumElementsMapping[49] = 1;
  opalSignalsAdressMapping[50] = (void*)&rtB.RMS_l.Clock_i;
  opalSignalsSizeMapping[50] = sizeof(rtB.RMS_l.Clock_i);
  opalSignalsNumElementsMapping[50] = 1;
  opalSignalsAdressMapping[51] = (void*)&rtB.RMS_l.Memory_o;
  opalSignalsSizeMapping[51] = sizeof(rtB.RMS_l.Memory_o);
  opalSignalsNumElementsMapping[51] = 1;
  opalSignalsAdressMapping[52] = (void*)&rtB.RMS_l.Switch_p;
  opalSignalsSizeMapping[52] = sizeof(rtB.RMS_l.Switch_p);
  opalSignalsNumElementsMapping[52] = 1;
  opalSignalsAdressMapping[53] = (void*)&rtB.RMS_l.ComplextoMagnitudeAngle_o1;
  opalSignalsSizeMapping[53] = sizeof(rtB.RMS_l.ComplextoMagnitudeAngle_o1);
  opalSignalsNumElementsMapping[53] = 1;
  opalSignalsAdressMapping[54] = (void*)&rtB.RMS_l.ComplextoMagnitudeAngle_o2;
  opalSignalsSizeMapping[54] = sizeof(rtB.RMS_l.ComplextoMagnitudeAngle_o2);
  opalSignalsNumElementsMapping[54] = 1;
  opalSignalsAdressMapping[55] = (void*)&rtB.RMS_l.sinwt;
  opalSignalsSizeMapping[55] = sizeof(rtB.RMS_l.sinwt);
  opalSignalsNumElementsMapping[55] = 1;
  opalSignalsAdressMapping[56] = (void*)&rtB.RMS_l.Product;
  opalSignalsSizeMapping[56] = sizeof(rtB.RMS_l.Product);
  opalSignalsNumElementsMapping[56] = 1;
  opalSignalsAdressMapping[57] = (void*)&rtB.RMS_l.coswt;
  opalSignalsSizeMapping[57] = sizeof(rtB.RMS_l.coswt);
  opalSignalsNumElementsMapping[57] = 1;
  opalSignalsAdressMapping[58] = (void*)&rtB.RMS_l.Product1;
  opalSignalsSizeMapping[58] = sizeof(rtB.RMS_l.Product1);
  opalSignalsNumElementsMapping[58] = 1;
  opalSignalsAdressMapping[59] = (void*)&rtB.RMS_l.RadDeg;
  opalSignalsSizeMapping[59] = sizeof(rtB.RMS_l.RadDeg);
  opalSignalsNumElementsMapping[59] = 1;
  opalSignalsAdressMapping[60] = (void*)&rtB.RMS_l.Gain;
  opalSignalsSizeMapping[60] = sizeof(rtB.RMS_l.Gain);
  opalSignalsNumElementsMapping[60] = 1;
  opalSignalsAdressMapping[61] = (void*)&rtB.RMS_l.Sum;
  opalSignalsSizeMapping[61] = sizeof(rtB.RMS_l.Sum);
  opalSignalsNumElementsMapping[61] = 1;
  opalSignalsAdressMapping[62] = (void*)&rtB.RMS_l.Gain_d;
  opalSignalsSizeMapping[62] = sizeof(rtB.RMS_l.Gain_d);
  opalSignalsNumElementsMapping[62] = 1;
  opalSignalsAdressMapping[63] = (void*)&rtB.RMS_l.Sum_o;
  opalSignalsSizeMapping[63] = sizeof(rtB.RMS_l.Sum_o);
  opalSignalsNumElementsMapping[63] = 1;
  opalSignalsAdressMapping[64] = (void*)&rtB.RMS_l.Gain_l;
  opalSignalsSizeMapping[64] = sizeof(rtB.RMS_l.Gain_l);
  opalSignalsNumElementsMapping[64] = 1;
  opalSignalsAdressMapping[65] = (void*)&rtB.RMS_l.RelationalOperator;
  opalSignalsSizeMapping[65] = sizeof(rtB.RMS_l.RelationalOperator);
  opalSignalsNumElementsMapping[65] = 1;
  opalSignalsAdressMapping[66] = (void*)&rtB.RMS_l.RelationalOperator_j;
  opalSignalsSizeMapping[66] = sizeof(rtB.RMS_l.RelationalOperator_j);
  opalSignalsNumElementsMapping[66] = 1;
  opalSignalsAdressMapping[67] = (void*)&rtB.TrueRMS.Clock;
  opalSignalsSizeMapping[67] = sizeof(rtB.TrueRMS.Clock);
  opalSignalsNumElementsMapping[67] = 1;
  opalSignalsAdressMapping[68] = (void*)&rtB.TrueRMS.integrator;
  opalSignalsSizeMapping[68] = sizeof(rtB.TrueRMS.integrator);
  opalSignalsNumElementsMapping[68] = 1;
  opalSignalsAdressMapping[69] = (void*)&rtB.TrueRMS.TransportDelay;
  opalSignalsSizeMapping[69] = sizeof(rtB.TrueRMS.TransportDelay);
  opalSignalsNumElementsMapping[69] = 1;
  opalSignalsAdressMapping[70] = (void*)&rtB.TrueRMS.Memory;
  opalSignalsSizeMapping[70] = sizeof(rtB.TrueRMS.Memory);
  opalSignalsNumElementsMapping[70] = 1;
  opalSignalsAdressMapping[71] = (void*)&rtB.TrueRMS.Switch;
  opalSignalsSizeMapping[71] = sizeof(rtB.TrueRMS.Switch);
  opalSignalsNumElementsMapping[71] = 1;
  opalSignalsAdressMapping[72] = (void*)&rtB.TrueRMS.Product;
  opalSignalsSizeMapping[72] = sizeof(rtB.TrueRMS.Product);
  opalSignalsNumElementsMapping[72] = 1;
  opalSignalsAdressMapping[73] = (void*)
    &rtB.TrueRMS.Saturationtoavoidnegativesqrt;
  opalSignalsSizeMapping[73] = sizeof(rtB.TrueRMS.Saturationtoavoidnegativesqrt);
  opalSignalsNumElementsMapping[73] = 1;
  opalSignalsAdressMapping[74] = (void*)&rtB.TrueRMS.Sqrt;
  opalSignalsSizeMapping[74] = sizeof(rtB.TrueRMS.Sqrt);
  opalSignalsNumElementsMapping[74] = 1;
  opalSignalsAdressMapping[75] = (void*)&rtB.TrueRMS.Sum;
  opalSignalsSizeMapping[75] = sizeof(rtB.TrueRMS.Sum);
  opalSignalsNumElementsMapping[75] = 1;
  opalSignalsAdressMapping[76] = (void*)&rtB.TrueRMS.Gain;
  opalSignalsSizeMapping[76] = sizeof(rtB.TrueRMS.Gain);
  opalSignalsNumElementsMapping[76] = 1;
  opalSignalsAdressMapping[77] = (void*)&rtB.TrueRMS.RelationalOperator;
  opalSignalsSizeMapping[77] = sizeof(rtB.TrueRMS.RelationalOperator);
  opalSignalsNumElementsMapping[77] = 1;
  opalSignalsAdressMapping[78] = (void*)&rtB.RMS.RealImagtoComplex;
  opalSignalsSizeMapping[78] = sizeof(((real_T*)(&rtB.RMS.RealImagtoComplex))[0]);
  opalSignalsNumElementsMapping[78] = 2;
  opalSignalsAdressMapping[79] = (void*)&rtB.RMS.integrator;
  opalSignalsSizeMapping[79] = sizeof(rtB.RMS.integrator);
  opalSignalsNumElementsMapping[79] = 1;
  opalSignalsAdressMapping[80] = (void*)&rtB.RMS.TransportDelay;
  opalSignalsSizeMapping[80] = sizeof(rtB.RMS.TransportDelay);
  opalSignalsNumElementsMapping[80] = 1;
  opalSignalsAdressMapping[81] = (void*)&rtB.RMS.Clock;
  opalSignalsSizeMapping[81] = sizeof(rtB.RMS.Clock);
  opalSignalsNumElementsMapping[81] = 1;
  opalSignalsAdressMapping[82] = (void*)&rtB.RMS.Memory;
  opalSignalsSizeMapping[82] = sizeof(rtB.RMS.Memory);
  opalSignalsNumElementsMapping[82] = 1;
  opalSignalsAdressMapping[83] = (void*)&rtB.RMS.Switch;
  opalSignalsSizeMapping[83] = sizeof(rtB.RMS.Switch);
  opalSignalsNumElementsMapping[83] = 1;
  opalSignalsAdressMapping[84] = (void*)&rtB.RMS.integrator_g;
  opalSignalsSizeMapping[84] = sizeof(rtB.RMS.integrator_g);
  opalSignalsNumElementsMapping[84] = 1;
  opalSignalsAdressMapping[85] = (void*)&rtB.RMS.TransportDelay_d;
  opalSignalsSizeMapping[85] = sizeof(rtB.RMS.TransportDelay_d);
  opalSignalsNumElementsMapping[85] = 1;
  opalSignalsAdressMapping[86] = (void*)&rtB.RMS.Clock_i;
  opalSignalsSizeMapping[86] = sizeof(rtB.RMS.Clock_i);
  opalSignalsNumElementsMapping[86] = 1;
  opalSignalsAdressMapping[87] = (void*)&rtB.RMS.Memory_o;
  opalSignalsSizeMapping[87] = sizeof(rtB.RMS.Memory_o);
  opalSignalsNumElementsMapping[87] = 1;
  opalSignalsAdressMapping[88] = (void*)&rtB.RMS.Switch_p;
  opalSignalsSizeMapping[88] = sizeof(rtB.RMS.Switch_p);
  opalSignalsNumElementsMapping[88] = 1;
  opalSignalsAdressMapping[89] = (void*)&rtB.RMS.ComplextoMagnitudeAngle_o1;
  opalSignalsSizeMapping[89] = sizeof(rtB.RMS.ComplextoMagnitudeAngle_o1);
  opalSignalsNumElementsMapping[89] = 1;
  opalSignalsAdressMapping[90] = (void*)&rtB.RMS.ComplextoMagnitudeAngle_o2;
  opalSignalsSizeMapping[90] = sizeof(rtB.RMS.ComplextoMagnitudeAngle_o2);
  opalSignalsNumElementsMapping[90] = 1;
  opalSignalsAdressMapping[91] = (void*)&rtB.RMS.sinwt;
  opalSignalsSizeMapping[91] = sizeof(rtB.RMS.sinwt);
  opalSignalsNumElementsMapping[91] = 1;
  opalSignalsAdressMapping[92] = (void*)&rtB.RMS.Product;
  opalSignalsSizeMapping[92] = sizeof(rtB.RMS.Product);
  opalSignalsNumElementsMapping[92] = 1;
  opalSignalsAdressMapping[93] = (void*)&rtB.RMS.coswt;
  opalSignalsSizeMapping[93] = sizeof(rtB.RMS.coswt);
  opalSignalsNumElementsMapping[93] = 1;
  opalSignalsAdressMapping[94] = (void*)&rtB.RMS.Product1;
  opalSignalsSizeMapping[94] = sizeof(rtB.RMS.Product1);
  opalSignalsNumElementsMapping[94] = 1;
  opalSignalsAdressMapping[95] = (void*)&rtB.RMS.RadDeg;
  opalSignalsSizeMapping[95] = sizeof(rtB.RMS.RadDeg);
  opalSignalsNumElementsMapping[95] = 1;
  opalSignalsAdressMapping[96] = (void*)&rtB.RMS.Gain;
  opalSignalsSizeMapping[96] = sizeof(rtB.RMS.Gain);
  opalSignalsNumElementsMapping[96] = 1;
  opalSignalsAdressMapping[97] = (void*)&rtB.RMS.Sum;
  opalSignalsSizeMapping[97] = sizeof(rtB.RMS.Sum);
  opalSignalsNumElementsMapping[97] = 1;
  opalSignalsAdressMapping[98] = (void*)&rtB.RMS.Gain_d;
  opalSignalsSizeMapping[98] = sizeof(rtB.RMS.Gain_d);
  opalSignalsNumElementsMapping[98] = 1;
  opalSignalsAdressMapping[99] = (void*)&rtB.RMS.Sum_o;
  opalSignalsSizeMapping[99] = sizeof(rtB.RMS.Sum_o);
  opalSignalsNumElementsMapping[99] = 1;
  opalSignalsAdressMapping[100] = (void*)&rtB.RMS.Gain_l;
  opalSignalsSizeMapping[100] = sizeof(rtB.RMS.Gain_l);
  opalSignalsNumElementsMapping[100] = 1;
  opalSignalsAdressMapping[101] = (void*)&rtB.RMS.RelationalOperator;
  opalSignalsSizeMapping[101] = sizeof(rtB.RMS.RelationalOperator);
  opalSignalsNumElementsMapping[101] = 1;
  opalSignalsAdressMapping[102] = (void*)&rtB.RMS.RelationalOperator_j;
  opalSignalsSizeMapping[102] = sizeof(rtB.RMS.RelationalOperator_j);
  opalSignalsNumElementsMapping[102] = 1;
  opalNumParameters = 97;
  opalNumSignals = 103;
}
