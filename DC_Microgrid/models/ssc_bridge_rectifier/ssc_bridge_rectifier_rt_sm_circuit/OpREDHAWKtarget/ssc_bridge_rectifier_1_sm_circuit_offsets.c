#include "ssc_bridge_rectifier_1_sm_circuit.h"
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
  opalParametersAdressMapping = (void**)malloc(sizeof(void*) * 25);
  opalParametersSizeMapping = (uint32_t*)malloc(sizeof(uint32_t) * 25);
  opalParametersNumElementsMapping = (uint32_t*)malloc(sizeof(uint32_t) * 25);
  opalSignalsAdressMapping = (void**)malloc(sizeof(void*) * 13);
  opalSignalsSizeMapping = (uint32_t*)malloc(sizeof(uint32_t) * 13);
  opalSignalsNumElementsMapping = (uint32_t*)malloc(sizeof(uint32_t) * 13);
  opalParametersAdressMapping[0] = (void*)&rtP.SFunction1_Value;
  opalParametersSizeMapping[0] = sizeof(rtP.SFunction1_Value);
  opalParametersNumElementsMapping[0] = 1;
  opalParametersAdressMapping[1] = (void*)&rtP.SFunction_InitialCondition;
  opalParametersSizeMapping[1] = sizeof(rtP.SFunction_InitialCondition);
  opalParametersNumElementsMapping[1] = 1;
  opalParametersAdressMapping[2] = (void*)&rtP.SFunction_P1_Size;
  opalParametersSizeMapping[2] = sizeof(rtP.SFunction_P1_Size[0]);
  opalParametersNumElementsMapping[2] = 2;
  opalParametersAdressMapping[3] = (void*)&rtP.SFunction_P1;
  opalParametersSizeMapping[3] = sizeof(rtP.SFunction_P1);
  opalParametersNumElementsMapping[3] = 1;
  opalParametersAdressMapping[4] = (void*)&rtP.SFunction_P2_Size;
  opalParametersSizeMapping[4] = sizeof(rtP.SFunction_P2_Size[0]);
  opalParametersNumElementsMapping[4] = 2;
  opalParametersAdressMapping[5] = (void*)&rtP.SFunction_P2;
  opalParametersSizeMapping[5] = sizeof(rtP.SFunction_P2[0]);
  opalParametersNumElementsMapping[5] = 2;
  opalParametersAdressMapping[6] = (void*)&rtP.SineWave_Amp;
  opalParametersSizeMapping[6] = sizeof(rtP.SineWave_Amp);
  opalParametersNumElementsMapping[6] = 1;
  opalParametersAdressMapping[7] = (void*)&rtP.SineWave_Bias;
  opalParametersSizeMapping[7] = sizeof(rtP.SineWave_Bias);
  opalParametersNumElementsMapping[7] = 1;
  opalParametersAdressMapping[8] = (void*)&rtP.SineWave_Freq;
  opalParametersSizeMapping[8] = sizeof(rtP.SineWave_Freq);
  opalParametersNumElementsMapping[8] = 1;
  opalParametersAdressMapping[9] = (void*)&rtP.SineWave_Phase;
  opalParametersSizeMapping[9] = sizeof(rtP.SineWave_Phase);
  opalParametersNumElementsMapping[9] = 1;
  opalParametersAdressMapping[10] = (void*)&rtP.RTP_983F50E8_vc_Value;
  opalParametersSizeMapping[10] = sizeof(rtP.RTP_983F50E8_vc_Value);
  opalParametersNumElementsMapping[10] = 1;
  opalParametersAdressMapping[11] = (void*)&rtP.OpMonitor_P1_Size;
  opalParametersSizeMapping[11] = sizeof(rtP.OpMonitor_P1_Size[0]);
  opalParametersNumElementsMapping[11] = 2;
  opalParametersAdressMapping[12] = (void*)&rtP.OpMonitor_P1;
  opalParametersSizeMapping[12] = sizeof(rtP.OpMonitor_P1);
  opalParametersNumElementsMapping[12] = 1;
  opalParametersAdressMapping[13] = (void*)&rtP.OpMonitor_P2_Size;
  opalParametersSizeMapping[13] = sizeof(rtP.OpMonitor_P2_Size[0]);
  opalParametersNumElementsMapping[13] = 2;
  opalParametersAdressMapping[14] = (void*)&rtP.OpMonitor_P2;
  opalParametersSizeMapping[14] = sizeof(rtP.OpMonitor_P2);
  opalParametersNumElementsMapping[14] = 1;
  opalParametersAdressMapping[15] = (void*)&rtP.OpMonitor_P3_Size;
  opalParametersSizeMapping[15] = sizeof(rtP.OpMonitor_P3_Size[0]);
  opalParametersNumElementsMapping[15] = 2;
  opalParametersAdressMapping[16] = (void*)&rtP.OpMonitor_P3;
  opalParametersSizeMapping[16] = sizeof(rtP.OpMonitor_P3);
  opalParametersNumElementsMapping[16] = 1;
  opalParametersAdressMapping[17] = (void*)&rtP.OpMonitor_P4_Size;
  opalParametersSizeMapping[17] = sizeof(rtP.OpMonitor_P4_Size[0]);
  opalParametersNumElementsMapping[17] = 2;
  opalParametersAdressMapping[18] = (void*)&rtP.OpMonitor_P4;
  opalParametersSizeMapping[18] = sizeof(rtP.OpMonitor_P4);
  opalParametersNumElementsMapping[18] = 1;
  opalParametersAdressMapping[19] = (void*)&rtP.OpMonitor_P5_Size;
  opalParametersSizeMapping[19] = sizeof(rtP.OpMonitor_P5_Size[0]);
  opalParametersNumElementsMapping[19] = 2;
  opalParametersAdressMapping[20] = (void*)&rtP.OpMonitor_P5;
  opalParametersSizeMapping[20] = sizeof(rtP.OpMonitor_P5);
  opalParametersNumElementsMapping[20] = 1;
  opalParametersAdressMapping[21] = (void*)&rtP.OpMonitor_P6_Size;
  opalParametersSizeMapping[21] = sizeof(rtP.OpMonitor_P6_Size[0]);
  opalParametersNumElementsMapping[21] = 2;
  opalParametersAdressMapping[22] = (void*)&rtP.OpMonitor_P6;
  opalParametersSizeMapping[22] = sizeof(rtP.OpMonitor_P6[0]);
  opalParametersNumElementsMapping[22] = 32;
  opalParametersAdressMapping[23] = (void*)&rtP.SFunction_P1_Size_g;
  opalParametersSizeMapping[23] = sizeof(rtP.SFunction_P1_Size_g[0]);
  opalParametersNumElementsMapping[23] = 2;
  opalParametersAdressMapping[24] = (void*)&rtP.SFunction_P1_i;
  opalParametersSizeMapping[24] = sizeof(rtP.SFunction_P1_i);
  opalParametersNumElementsMapping[24] = 1;
  opalSignalsAdressMapping[0] = (void*)&rtB.SFunction;
  opalSignalsSizeMapping[0] = sizeof(rtB.SFunction);
  opalSignalsNumElementsMapping[0] = 1;
  opalSignalsAdressMapping[1] = (void*)&rtB.Sum;
  opalSignalsSizeMapping[1] = sizeof(rtB.Sum);
  opalSignalsNumElementsMapping[1] = 1;
  opalSignalsAdressMapping[2] = (void*)&rtB.SFunction_f;
  opalSignalsSizeMapping[2] = sizeof(rtB.SFunction_f[0]);
  opalSignalsNumElementsMapping[2] = 2;
  opalSignalsAdressMapping[3] = (void*)&rtB.SineWave;
  opalSignalsSizeMapping[3] = sizeof(rtB.SineWave);
  opalSignalsNumElementsMapping[3] = 1;
  opalSignalsAdressMapping[4] = (void*)&rtB.Product;
  opalSignalsSizeMapping[4] = sizeof(rtB.Product);
  opalSignalsNumElementsMapping[4] = 1;
  opalSignalsAdressMapping[5] = (void*)&rtB.INPUT_1_1_1;
  opalSignalsSizeMapping[5] = sizeof(rtB.INPUT_1_1_1[0]);
  opalSignalsNumElementsMapping[5] = 4;
  opalSignalsAdressMapping[6] = (void*)&rtB.RTP_1;
  opalSignalsSizeMapping[6] = sizeof(rtB.RTP_1);
  opalSignalsNumElementsMapping[6] = 1;
  opalSignalsAdressMapping[7] = (void*)&rtB.STATE_1;
  opalSignalsSizeMapping[7] = sizeof(rtB.STATE_1[0]);
  opalSignalsNumElementsMapping[7] = 11;
  opalSignalsAdressMapping[8] = (void*)&rtB.OUTPUT_1_0;
  opalSignalsSizeMapping[8] = sizeof(rtB.OUTPUT_1_0);
  opalSignalsNumElementsMapping[8] = 1;
  opalSignalsAdressMapping[9] = (void*)&rtB.OpMonitor_o1;
  opalSignalsSizeMapping[9] = sizeof(rtB.OpMonitor_o1);
  opalSignalsNumElementsMapping[9] = 1;
  opalSignalsAdressMapping[10] = (void*)&rtB.OpMonitor_o2;
  opalSignalsSizeMapping[10] = sizeof(rtB.OpMonitor_o2);
  opalSignalsNumElementsMapping[10] = 1;
  opalSignalsAdressMapping[11] = (void*)&rtB.OpMonitor_o3;
  opalSignalsSizeMapping[11] = sizeof(rtB.OpMonitor_o3);
  opalSignalsNumElementsMapping[11] = 1;
  opalSignalsAdressMapping[12] = (void*)&rtB.OpMonitor_o4;
  opalSignalsSizeMapping[12] = sizeof(rtB.OpMonitor_o4);
  opalSignalsNumElementsMapping[12] = 1;
  opalNumParameters = 25;
  opalNumSignals = 13;
}
