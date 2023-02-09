/**
 * This function is generated by RT-LAB during model compilation (at 'generation' step).
 * This function copies data from src to dst, ignoring pointers.
 * Note that only PWork are supposed to be pointers within a DWork structure
 * and that sub-structures are copied in one operation since they do not contain pointers.
 */
int OpalSnapshot_Copy_DWork(void * src, void * dst) {
   D_Work * pSrc = (D_Work*)src;
   D_Work * pDst = (D_Work*)dst;
   int size = 0, eltSize = 0;

   eltSize = sizeof(pSrc->INPUT_1_1_1_Discrete);
   memcpy(&pDst->INPUT_1_1_1_Discrete, &pSrc->INPUT_1_1_1_Discrete, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->INPUT_1_1_1_FirstOutput);
   memcpy(&pDst->INPUT_1_1_1_FirstOutput, &pSrc->INPUT_1_1_1_FirstOutput, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->Delay_DSTATE);
   memcpy(&pDst->Delay_DSTATE, &pSrc->Delay_DSTATE, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->INPUT_2_1_1_Discrete);
   memcpy(&pDst->INPUT_2_1_1_Discrete, &pSrc->INPUT_2_1_1_Discrete, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->LTI_STATE_1_FirstOutput);
   memcpy(&pDst->LTI_STATE_1_FirstOutput, &pSrc->LTI_STATE_1_FirstOutput, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->INPUT_1_1_2_Discrete);
   memcpy(&pDst->INPUT_1_1_2_Discrete, &pSrc->INPUT_1_1_2_Discrete, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->INPUT_1_1_2_FirstOutput);
   memcpy(&pDst->INPUT_1_1_2_FirstOutput, &pSrc->INPUT_1_1_2_FirstOutput, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->INPUT_1_1_3_Discrete);
   memcpy(&pDst->INPUT_1_1_3_Discrete, &pSrc->INPUT_1_1_3_Discrete, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->INPUT_1_1_3_FirstOutput);
   memcpy(&pDst->INPUT_1_1_3_FirstOutput, &pSrc->INPUT_1_1_3_FirstOutput, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->INPUT_2_1_2_Discrete);
   memcpy(&pDst->INPUT_2_1_2_Discrete, &pSrc->INPUT_2_1_2_Discrete, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->INPUT_2_1_3_Discrete);
   memcpy(&pDst->INPUT_2_1_3_Discrete, &pSrc->INPUT_2_1_3_Discrete, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->SFunction_PreviousInput);
   memcpy(&pDst->SFunction_PreviousInput, &pSrc->SFunction_PreviousInput, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->SFunction_IWORK);
   memcpy(&pDst->SFunction_IWORK, &pSrc->SFunction_IWORK, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->TrueRMS_f);
   memcpy(&pDst->TrueRMS_f, &pSrc->TrueRMS_f, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->RMS_l);
   memcpy(&pDst->RMS_l, &pSrc->RMS_l, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->TrueRMS);
   memcpy(&pDst->TrueRMS, &pSrc->TrueRMS, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->RMS);
   memcpy(&pDst->RMS, &pSrc->RMS, eltSize);
   size += eltSize;

   return size;
}

/**
 * This function is generated by RT-LAB during model compilation (at 'generation' step).
 * This function copies data from a raw buffer (src) 
 * to an RT_MODEL structure(dst), ignoring pointers.
 * Note that sub-structures are copied in one operation since they cannot contain pointers.
 */
int OpalSnapshot_Copy_TimingData(void * src, void * dst) {
   RT_MODEL	tmpBuffer;
   RT_MODEL * pSrc = &tmpBuffer;
   RT_MODEL * pDst = (RT_MODEL *)dst;
   int TimingSize = sizeof(tmpBuffer.Timing);
   int size = 0, eltSize = 0;

   memcpy(&tmpBuffer.Timing, src, TimingSize);

   eltSize = sizeof(pSrc->Timing.clockTick0);
   memcpy(&pDst->Timing.clockTick0, &pSrc->Timing.clockTick0, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->Timing.clockTick1);
   memcpy(&pDst->Timing.clockTick1, &pSrc->Timing.clockTick1, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->Timing.clockTickH0);
   memcpy(&pDst->Timing.clockTickH0, &pSrc->Timing.clockTickH0, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->Timing.clockTickH1);
   memcpy(&pDst->Timing.clockTickH1, &pSrc->Timing.clockTickH1, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->Timing.tFinal);
   memcpy(&pDst->Timing.tFinal, &pSrc->Timing.tFinal, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->Timing.offsetTimesArray);
   memcpy(&pDst->Timing.offsetTimesArray, &pSrc->Timing.offsetTimesArray, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->Timing.perTaskSampleHitsArray);
   memcpy(&pDst->Timing.perTaskSampleHitsArray, &pSrc->Timing.perTaskSampleHitsArray, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->Timing.sampleHitArray);
   memcpy(&pDst->Timing.sampleHitArray, &pSrc->Timing.sampleHitArray, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->Timing.sampleTimesArray);
   memcpy(&pDst->Timing.sampleTimesArray, &pSrc->Timing.sampleTimesArray, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->Timing.sampleTimeTaskIDArray);
   memcpy(&pDst->Timing.sampleTimeTaskIDArray, &pSrc->Timing.sampleTimeTaskIDArray, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->Timing.simTimeStep);
   memcpy(&pDst->Timing.simTimeStep, &pSrc->Timing.simTimeStep, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->Timing.tStart);
   memcpy(&pDst->Timing.tStart, &pSrc->Timing.tStart, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->Timing.stepSize);
   memcpy(&pDst->Timing.stepSize, &pSrc->Timing.stepSize, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->Timing.stepSize0);
   memcpy(&pDst->Timing.stepSize0, &pSrc->Timing.stepSize0, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->Timing.stepSize1);
   memcpy(&pDst->Timing.stepSize1, &pSrc->Timing.stepSize1, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->Timing.stopRequestedFlag);
   memcpy(&pDst->Timing.stopRequestedFlag, &pSrc->Timing.stopRequestedFlag, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->Timing.tArray);
   memcpy(&pDst->Timing.tArray, &pSrc->Timing.tArray, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->Timing.timeOfLastOutput);
   memcpy(&pDst->Timing.timeOfLastOutput, &pSrc->Timing.timeOfLastOutput, eltSize);
   size += eltSize;

   return size;
}

/**
 * This function is generated by RT-LAB during model compilation (at 'generation' step).
 * This function copies data from a raw buffer (src) 
 * to an RT_MODEL structure(dst), ignoring pointers.
 * Note that ingData must not be copied since it contains pointers.
 */
int OpalSnapshot_Copy_ModelData(void * src, void * dst) {
   RT_MODEL	tmpBuffer;
   RT_MODEL * pSrc = &tmpBuffer;
   RT_MODEL * pDst = (RT_MODEL *)dst;
   int ModelDataSize = sizeof(tmpBuffer.ModelData);
   int size = 0, eltSize = 0;

   memcpy(&tmpBuffer.ModelData, src, ModelDataSize);

   eltSize = sizeof(pSrc->ModelData.CTOutputIncnstWithState);
   memcpy(&pDst->ModelData.CTOutputIncnstWithState, &pSrc->ModelData.CTOutputIncnstWithState, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->ModelData.derivCacheNeedsReset);
   memcpy(&pDst->ModelData.derivCacheNeedsReset, &pSrc->ModelData.derivCacheNeedsReset, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->ModelData.odeF);
   memcpy(&pDst->ModelData.odeF, &pSrc->ModelData.odeF, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->ModelData.odeY);
   memcpy(&pDst->ModelData.odeY, &pSrc->ModelData.odeY, eltSize);
   size += eltSize;

   eltSize = sizeof(pSrc->ModelData.zCCacheNeedsReset);
   memcpy(&pDst->ModelData.zCCacheNeedsReset, &pSrc->ModelData.zCCacheNeedsReset, eltSize);
   size += eltSize;

   return size;
}

