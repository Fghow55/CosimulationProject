/*
 * ac_der_basic_model_1_sm_circuit.h
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

#ifndef RTW_HEADER_ac_der_basic_model_1_sm_circuit_h_
#define RTW_HEADER_ac_der_basic_model_1_sm_circuit_h_
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef ac_der_basic_model_1_sm_circuit_COMMON_INCLUDES_
#define ac_der_basic_model_1_sm_circuit_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                    /* ac_der_basic_model_1_sm_circuit_COMMON_INCLUDES_ */

#include "ac_der_basic_model_1_sm_circuit_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
#define rtmGetChecksums(rtm)           ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
#define rtmSetChecksums(rtm, val)      ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
#define rtmGetConstBlockIO(rtm)        ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
#define rtmSetConstBlockIO(rtm, val)   ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->ModelData.CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->ModelData.CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetCtrlRateMdlRefTiming
#define rtmGetCtrlRateMdlRefTiming(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTiming
#define rtmSetCtrlRateMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateMdlRefTimingPtr
#define rtmGetCtrlRateMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTimingPtr
#define rtmSetCtrlRateMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateNumTicksToNextHit
#define rtmGetCtrlRateNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetCtrlRateNumTicksToNextHit
#define rtmSetCtrlRateNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         ()
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)    ()
#endif

#ifndef rtmGetDefaultParam
#define rtmGetDefaultParam(rtm)        ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
#define rtmSetDefaultParam(rtm, val)   ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
#define rtmGetDirectFeedThrough(rtm)   ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
#define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
#define rtmGetErrorStatusFlag(rtm)     ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
#define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
#define rtmSetFinalTime(rtm, val)      ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
#define rtmGetFirstInitCondFlag(rtm)   ()
#endif

#ifndef rtmSetFirstInitCondFlag
#define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalRuntimeEventIndices
#define rtmGetMdlRefGlobalRuntimeEventIndices(rtm) ()
#endif

#ifndef rtmSetMdlRefGlobalRuntimeEventIndices
#define rtmSetMdlRefGlobalRuntimeEventIndices(rtm, val) ()
#endif

#ifndef rtmGetMdlRefGlobalTID
#define rtmGetMdlRefGlobalTID(rtm)     ()
#endif

#ifndef rtmSetMdlRefGlobalTID
#define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
#define rtmGetMdlRefTriggerTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefTriggerTID
#define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
#define rtmGetModelMappingInfo(rtm)    ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
#define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
#define rtmGetModelName(rtm)           ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
#define rtmSetModelName(rtm, val)      ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
#define rtmGetNonInlinedSFcns(rtm)     ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
#define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
#define rtmGetNumBlockIO(rtm)          ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
#define rtmSetNumBlockIO(rtm, val)     ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
#define rtmGetNumBlockParams(rtm)      ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
#define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
#define rtmGetNumBlocks(rtm)           ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
#define rtmSetNumBlocks(rtm, val)      ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
#define rtmGetNumContStates(rtm)       ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
#define rtmSetNumContStates(rtm, val)  ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
#define rtmGetNumDWork(rtm)            ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
#define rtmSetNumDWork(rtm, val)       ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
#define rtmGetNumInputPorts(rtm)       ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
#define rtmSetNumInputPorts(rtm, val)  ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
#define rtmGetNumNonSampledZCs(rtm)    ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
#define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
#define rtmGetNumOutputPorts(rtm)      ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
#define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
#define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
#define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
#define rtmGetNumSFcnParams(rtm)       ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
#define rtmSetNumSFcnParams(rtm, val)  ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
#define rtmGetNumSFunctions(rtm)       ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
#define rtmSetNumSFunctions(rtm, val)  ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
#define rtmGetNumSampleTimes(rtm)      ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
#define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
#define rtmGetNumU(rtm)                ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
#define rtmSetNumU(rtm, val)           ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
#define rtmGetNumY(rtm)                ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
#define rtmSetNumY(rtm, val)           ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
#define rtmGetOffsetTimeArray(rtm)     ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
#define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
#define rtmGetOffsetTimePtr(rtm)       ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
#define rtmSetOffsetTimePtr(rtm, val)  ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
#define rtmGetOptions(rtm)             ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
#define rtmSetOptions(rtm, val)        ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
#define rtmGetParamIsMalloced(rtm)     ()
#endif

#ifndef rtmSetParamIsMalloced
#define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
#define rtmGetPath(rtm)                ((rtm)->path)
#endif

#ifndef rtmSetPath
#define rtmSetPath(rtm, val)           ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
#define rtmGetPerTaskSampleHits(rtm)   ()
#endif

#ifndef rtmSetPerTaskSampleHits
#define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
#define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
#define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
#define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
#define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
#define rtmGetPrevZCSigState(rtm)      ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
#define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
#define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
#define rtmGetRTWGeneratedSFcn(rtm)    ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
#define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
#define rtmSetRTWLogInfo(rtm, val)     ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
#define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
#define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
#define rtmGetRTWSfcnInfo(rtm)         ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
#define rtmSetRTWSfcnInfo(rtm, val)    ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
#define rtmGetRTWSolverInfo(rtm)       ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
#define rtmSetRTWSolverInfo(rtm, val)  ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
#define rtmGetRTWSolverInfoPtr(rtm)    ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
#define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
#define rtmGetReservedForXPC(rtm)      ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
#define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
#define rtmGetRootDWork(rtm)           ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
#define rtmSetRootDWork(rtm, val)      ((rtm)->ModelData.dwork = (val))
#endif

#ifndef rtmGetSFunctions
#define rtmGetSFunctions(rtm)          ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
#define rtmSetSFunctions(rtm, val)     ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
#define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
#define rtmGetSampleHitPtr(rtm)        ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
#define rtmSetSampleHitPtr(rtm, val)   ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
#define rtmGetSampleTimeArray(rtm)     ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
#define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
#define rtmGetSampleTimePtr(rtm)       ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
#define rtmSetSampleTimePtr(rtm, val)  ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
#define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
#define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
#define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
#define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
#define rtmGetSelf(rtm)                ()
#endif

#ifndef rtmSetSelf
#define rtmSetSelf(rtm, val)           ()
#endif

#ifndef rtmGetSimMode
#define rtmGetSimMode(rtm)             ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
#define rtmSetSimMode(rtm, val)        ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
#define rtmGetSimTimeStep(rtm)         ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
#define rtmSetSimTimeStep(rtm, val)    ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
#define rtmGetStartTime(rtm)           ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
#define rtmSetStartTime(rtm, val)      ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
#define rtmSetStepSize(rtm, val)       ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
#define rtmGetStopRequestedFlag(rtm)   ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
#define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
#define rtmGetTaskCounters(rtm)        ()
#endif

#ifndef rtmSetTaskCounters
#define rtmSetTaskCounters(rtm, val)   ()
#endif

#ifndef rtmGetTaskTimeArray
#define rtmGetTaskTimeArray(rtm)       ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
#define rtmSetTaskTimeArray(rtm, val)  ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
#define rtmGetTimePtr(rtm)             ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
#define rtmSetTimePtr(rtm, val)        ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
#define rtmGetTimingData(rtm)          ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
#define rtmSetTimingData(rtm, val)     ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
#define rtmGetU(rtm)                   ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
#define rtmSetU(rtm, val)              ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
#define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
#define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
#define rtmGetY(rtm)                   ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
#define rtmSetY(rtm, val)              ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
#define rtmGetZCSignalValues(rtm)      ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
#define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
#define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGettimingBridge
#define rtmGettimingBridge(rtm)        ()
#endif

#ifndef rtmSettimingBridge
#define rtmSettimingBridge(rtm, val)   ()
#endif

#ifndef rtmGetChecksumVal
#define rtmGetChecksumVal(rtm, idx)    ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
#define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
#define rtmGetDWork(rtm, idx)          ((rtm)->ModelData.dwork[idx])
#endif

#ifndef rtmSetDWork
#define rtmSetDWork(rtm, idx, val)     ((rtm)->ModelData.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
#define rtmGetOffsetTime(rtm, idx)     ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
#define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
#define rtmGetSFunction(rtm, idx)      ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
#define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
#define rtmGetSampleTime(rtm, idx)     ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
#define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
#define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
#define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
#define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
#define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
#define rtmIsContinuousTask(rtm, tid)  ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
#define rtmIsSampleHit(rtm, sti, tid)  ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
#define rtmSetT(rtm, val)                                        /* Do Nothing */
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
#define rtmSetTStart(rtm, val)         ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
#define rtmGetTaskTime(rtm, sti)       (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
#define rtmSetTaskTime(rtm, sti, val)  (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define ac_der_basic_model_1_sm_circuit_rtModel RT_MODEL_ac_der_basic_model_1_sm_circuit_T

/* user code (top of header file) */
/* System '<Root>' */
/* Opal-RT Technologies */
extern int opalSizeDwork;
extern unsigned int opalSizeBlockIO;
extern unsigned int opalSizeRTP;
extern void * pRtModel;                //pointer on the RTmodel struc
int_T Opal_rtmGetNumBlockParams(void *ptr);
int_T Opal_rtmGetNumBlockIO(void *ptr);

/* Block signals for system '<S6>/RMS ' */
typedef struct {
  creal_T RealImagtoComplex;      /* '<S20>/Real-Imag to Complex' (Output 1)  */
  real_T integrator;                   /* '<S24>/integrator' (Output 1)  */
  real_T TransportDelay;               /* '<S24>/Transport Delay' (Output 1)  */
  real_T Clock;                        /* '<S24>/Clock' (Output 1)  */
  real_T Memory;                       /* '<S24>/Memory' (Output 1)  */
  real_T Switch;                       /* '<S24>/Switch' (Output 1)  */
  real_T integrator_g;                 /* '<S23>/integrator' (Output 1)  */
  real_T TransportDelay_d;             /* '<S23>/Transport Delay' (Output 1)  */
  real_T Clock_i;                      /* '<S23>/Clock' (Output 1)  */
  real_T Memory_o;                     /* '<S23>/Memory' (Output 1)  */
  real_T Switch_p;                     /* '<S23>/Switch' (Output 1)  */
  real_T ComplextoMagnitudeAngle_o1;
                            /* '<S20>/Complex to Magnitude-Angle' (Output 1)  */
  real_T ComplextoMagnitudeAngle_o2;
                            /* '<S20>/Complex to Magnitude-Angle' (Output 2)  */
  real_T sinwt;                        /* '<S20>/sin(wt)' (Output 1)  */
  real_T Product;                      /* '<S20>/Product' (Output 1)  */
  real_T coswt;                        /* '<S20>/cos(wt)' (Output 1)  */
  real_T Product1;                     /* '<S20>/Product1' (Output 1)  */
  real_T RadDeg;                       /* '<S20>/Rad->Deg.' (Output 1)  */
  real_T Gain;                         /* '<S18>/Gain' (Output 1)  */
  real_T Sum;                          /* '<S24>/Sum' (Output 1)  */
  real_T Gain_d;                       /* '<S24>/Gain' (Output 1)  */
  real_T Sum_o;                        /* '<S23>/Sum' (Output 1)  */
  real_T Gain_l;                       /* '<S23>/Gain' (Output 1)  */
  boolean_T RelationalOperator;    /* '<S24>/Relational Operator' (Output 1)  */
  boolean_T RelationalOperator_j;  /* '<S23>/Relational Operator' (Output 1)  */
} B_RMS_ac_der_basic_model_1_sm_T;

/* Block states (default storage) for system '<S6>/RMS ' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<S24>/Memory' (DWork 1)  */
  real_T Memory_PreviousInput_i;       /* '<S23>/Memory' (DWork 1)  */
  struct {
    real_T modelTStart;
    real_T TUbufferArea[16384];
  } TransportDelay_RWORK;              /* '<S24>/Transport Delay' (DWork 1)  */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[16384];
  } TransportDelay_RWORK_p;            /* '<S23>/Transport Delay' (DWork 1)  */

  struct {
    void *TUbufferPtrs[2];
  } TransportDelay_PWORK;              /* '<S24>/Transport Delay' (DWork 3)  */

  struct {
    void *TUbufferPtrs[2];
  } TransportDelay_PWORK_f;            /* '<S23>/Transport Delay' (DWork 3)  */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TransportDelay_IWORK;              /* '<S24>/Transport Delay' (DWork 2)  */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TransportDelay_IWORK_d;            /* '<S23>/Transport Delay' (DWork 2)  */

  boolean_T RMS_MODE;                  /* '<S6>/RMS ' (DWork 1)  */
} DW_RMS_ac_der_basic_model_1_s_T;

/* Continuous states for system '<S6>/RMS ' */
typedef struct {
  real_T integrator_CSTATE_e;          /* '<S24>/integrator' */
  real_T integrator_CSTATE_n;          /* '<S23>/integrator' */
} X_RMS_ac_der_basic_model_1_sm_T;

/* State derivatives for system '<S6>/RMS ' */
typedef struct {
  real_T integrator_CSTATE_e;          /* '<S24>/integrator' */
  real_T integrator_CSTATE_n;          /* '<S23>/integrator' */
} XDot_RMS_ac_der_basic_model_1_T;

/* State Disabled for system '<S6>/RMS ' */
typedef struct {
  boolean_T integrator_CSTATE_e;       /* '<S24>/integrator' */
  boolean_T integrator_CSTATE_n;       /* '<S23>/integrator' */
} XDis_RMS_ac_der_basic_model_1_T;

/* Block signals for system '<S6>/TrueRMS ' */
typedef struct {
  real_T Clock;                        /* '<S26>/Clock' (Output 1)  */
  real_T integrator;                   /* '<S26>/integrator' (Output 1)  */
  real_T TransportDelay;               /* '<S26>/Transport Delay' (Output 1)  */
  real_T Memory;                       /* '<S26>/Memory' (Output 1)  */
  real_T Switch;                       /* '<S26>/Switch' (Output 1)  */
  real_T Product;                      /* '<S19>/Product' (Output 1)  */
  real_T Saturationtoavoidnegativesqrt;
                     /* '<S19>/Saturation to avoid negative sqrt' (Output 1)  */
  real_T Sqrt;                         /* '<S19>/Sqrt' (Output 1)  */
  real_T Sum;                          /* '<S26>/Sum' (Output 1)  */
  real_T Gain;                         /* '<S26>/Gain' (Output 1)  */
  boolean_T RelationalOperator;    /* '<S26>/Relational Operator' (Output 1)  */
} B_TrueRMS_ac_der_basic_model__T;

/* Block states (default storage) for system '<S6>/TrueRMS ' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<S26>/Memory' (DWork 1)  */
  struct {
    real_T modelTStart;
    real_T TUbufferArea[16384];
  } TransportDelay_RWORK;              /* '<S26>/Transport Delay' (DWork 1)  */

  struct {
    void *TUbufferPtrs[2];
  } TransportDelay_PWORK;              /* '<S26>/Transport Delay' (DWork 3)  */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TransportDelay_IWORK;              /* '<S26>/Transport Delay' (DWork 2)  */

  boolean_T TrueRMS_MODE;              /* '<S6>/TrueRMS ' (DWork 1)  */
} DW_TrueRMS_ac_der_basic_model_T;

/* Continuous states for system '<S6>/TrueRMS ' */
typedef struct {
  real_T integrator_CSTATE;            /* '<S26>/integrator' */
} X_TrueRMS_ac_der_basic_model__T;

/* State derivatives for system '<S6>/TrueRMS ' */
typedef struct {
  real_T integrator_CSTATE;            /* '<S26>/integrator' */
} XDot_TrueRMS_ac_der_basic_mod_T;

/* State Disabled for system '<S6>/TrueRMS ' */
typedef struct {
  boolean_T integrator_CSTATE;         /* '<S26>/integrator' */
} XDis_TrueRMS_ac_der_basic_mod_T;

/* Block signals (default storage) */
typedef struct {
  real_T SFunction;                    /* '<S1>/S-Function' (Output 1)  */
  real_T Sum;                          /* '<S1>/Sum' (Output 1)  */
  real_T SFunction_c[2];               /* '<S12>/S-Function' (Output 1)  */
  real_T Sign;                         /* '<S2>/Sign' (Output 1)  */
  real_T Product1;                     /* '<S2>/Product1' (Output 1)  */
  real_T SineWave1;                    /* '<S2>/Sine Wave1' (Output 1)  */
  real_T SineWave2;                    /* '<S2>/Sine Wave2' (Output 1)  */
  real_T SineWave3;                    /* '<S2>/Sine Wave3' (Output 1)  */
  real_T Product2[3];                  /* '<S2>/Product2' (Output 1)  */
  real_T INPUT_1_1_1[4];               /* '<S38>/INPUT_1_1_1' (Output 1)  */
  real_T Product3;                     /* '<S2>/Product3' (Output 1)  */
  real_T SineWave4;                    /* '<S2>/Sine Wave4' (Output 1)  */
  real_T SineWave5;                    /* '<S2>/Sine Wave5' (Output 1)  */
  real_T SineWave6;                    /* '<S2>/Sine Wave6' (Output 1)  */
  real_T Delay;                        /* '<S2>/Delay' (Output 1)  */
  real_T Switch;                       /* '<S7>/Switch' (Output 1)  */
  real_T Divide[3];                    /* '<S2>/Divide' (Output 1)  */
  real_T Product6[3];                  /* '<S2>/Product6' (Output 1)  */
  real_T INPUT_2_1_1[4];               /* '<S38>/INPUT_2_1_1' (Output 1)  */
  real_T LTI_OUTPUT_1_1;               /* '<S38>/LTI_OUTPUT_1_1' (Output 1)  */
  real_T Switch_c;                     /* '<S6>/Switch' (Output 1)  */
  real_T Product4;                     /* '<S2>/Product4' (Output 1)  */
  real_T INPUT_1_1_2[4];               /* '<S38>/INPUT_1_1_2' (Output 1)  */
  real_T INPUT_1_1_3[4];               /* '<S38>/INPUT_1_1_3' (Output 1)  */
  real_T INPUT_2_1_2[4];               /* '<S38>/INPUT_2_1_2' (Output 1)  */
  real_T INPUT_2_1_3[4];               /* '<S38>/INPUT_2_1_3' (Output 1)  */
  real_T LTI_OUTPUT_1_2;               /* '<S38>/LTI_OUTPUT_1_2' (Output 1)  */
  boolean_T DataTypeConversion;    /* '<S7>/Data Type Conversion' (Output 1)  */
  boolean_T LogicalOperator;           /* '<S7>/Logical Operator' (Output 1)  */
  boolean_T DataTypeConversion_n;  /* '<S6>/Data Type Conversion' (Output 1)  */
  boolean_T LogicalOperator_l;         /* '<S6>/Logical Operator' (Output 1)  */
  B_TrueRMS_ac_der_basic_model__T TrueRMS_f;/* '<S7>/TrueRMS ' */
  B_RMS_ac_der_basic_model_1_sm_T RMS_l;/* '<S7>/RMS ' */
  B_TrueRMS_ac_der_basic_model__T TrueRMS;/* '<S6>/TrueRMS ' */
  B_RMS_ac_der_basic_model_1_sm_T RMS; /* '<S6>/RMS ' */
} B_ac_der_basic_model_1_sm_circuit_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T INPUT_1_1_1_Discrete;         /* '<S38>/INPUT_1_1_1' (DWork 1)  */
  real_T INPUT_1_1_1_FirstOutput;      /* '<S38>/INPUT_1_1_1' (DWork 2)  */
  real_T Delay_DSTATE;                 /* '<S2>/Delay' (DWork 1)  */
  real_T INPUT_2_1_1_Discrete[2];      /* '<S38>/INPUT_2_1_1' (DWork 1)  */
  real_T LTI_STATE_1_FirstOutput;      /* '<S38>/LTI_STATE_1' (DWork 1)  */
  real_T INPUT_1_1_2_Discrete;         /* '<S38>/INPUT_1_1_2' (DWork 1)  */
  real_T INPUT_1_1_2_FirstOutput;      /* '<S38>/INPUT_1_1_2' (DWork 2)  */
  real_T INPUT_1_1_3_Discrete;         /* '<S38>/INPUT_1_1_3' (DWork 1)  */
  real_T INPUT_1_1_3_FirstOutput;      /* '<S38>/INPUT_1_1_3' (DWork 2)  */
  real_T INPUT_2_1_2_Discrete[2];      /* '<S38>/INPUT_2_1_2' (DWork 1)  */
  real_T INPUT_2_1_3_Discrete[2];      /* '<S38>/INPUT_2_1_3' (DWork 1)  */
  real_T SFunction_PreviousInput;      /* '<S1>/S-Function' (DWork 1)  */
  int_T SFunction_IWORK[5];            /* '<S40>/S-Function' (DWork 1)  */
  DW_TrueRMS_ac_der_basic_model_T TrueRMS_f;/* '<S7>/TrueRMS ' */
  DW_RMS_ac_der_basic_model_1_s_T RMS_l;/* '<S7>/RMS ' */
  DW_TrueRMS_ac_der_basic_model_T TrueRMS;/* '<S6>/TrueRMS ' */
  DW_RMS_ac_der_basic_model_1_s_T RMS; /* '<S6>/RMS ' */
} DW_ac_der_basic_model_1_sm_circuit_T;

/* Continuous states (default storage) */
typedef struct {
  real_T ac_der_basic_model_1_sm_circuit;/* '<S38>/INPUT_1_1_1' */
  real_T ac_der_basic_model_1_sm_circu_c;/* '<S38>/INPUT_1_1_2' */
  real_T ac_der_basic_model_1_sm_circu_m;/* '<S38>/INPUT_1_1_3' */
  X_TrueRMS_ac_der_basic_model__T TrueRMS_f;/* '<S6>/TrueRMS ' */
  X_RMS_ac_der_basic_model_1_sm_T RMS_l;/* '<S6>/RMS ' */
  X_TrueRMS_ac_der_basic_model__T TrueRMS;/* '<S6>/TrueRMS ' */
  X_RMS_ac_der_basic_model_1_sm_T RMS; /* '<S6>/RMS ' */
} X_ac_der_basic_model_1_sm_circuit_T;

/* State derivatives (default storage) */
typedef struct {
  real_T ac_der_basic_model_1_sm_circuit;/* '<S38>/INPUT_1_1_1' */
  real_T ac_der_basic_model_1_sm_circu_c;/* '<S38>/INPUT_1_1_2' */
  real_T ac_der_basic_model_1_sm_circu_m;/* '<S38>/INPUT_1_1_3' */
  XDot_TrueRMS_ac_der_basic_mod_T TrueRMS_f;/* '<S6>/TrueRMS ' */
  XDot_RMS_ac_der_basic_model_1_T RMS_l;/* '<S6>/RMS ' */
  XDot_TrueRMS_ac_der_basic_mod_T TrueRMS;/* '<S6>/TrueRMS ' */
  XDot_RMS_ac_der_basic_model_1_T RMS; /* '<S6>/RMS ' */
} XDot_ac_der_basic_model_1_sm_circuit_T;

/* State disabled  */
typedef struct {
  boolean_T ac_der_basic_model_1_sm_circuit;/* '<S38>/INPUT_1_1_1' */
  boolean_T ac_der_basic_model_1_sm_circu_c;/* '<S38>/INPUT_1_1_2' */
  boolean_T ac_der_basic_model_1_sm_circu_m;/* '<S38>/INPUT_1_1_3' */
  XDis_TrueRMS_ac_der_basic_mod_T TrueRMS_f;/* '<S6>/TrueRMS ' */
  XDis_RMS_ac_der_basic_model_1_T RMS_l;/* '<S6>/RMS ' */
  XDis_TrueRMS_ac_der_basic_mod_T TrueRMS;/* '<S6>/TrueRMS ' */
  XDis_RMS_ac_der_basic_model_1_T RMS; /* '<S6>/RMS ' */
} XDis_ac_der_basic_model_1_sm_circuit_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            ac_der_basic_model_1_sm_circuit_B
#define BlockIO                        B_ac_der_basic_model_1_sm_circuit_T
#define rtX                            ac_der_basic_model_1_sm_circuit_X
#define ContinuousStates               X_ac_der_basic_model_1_sm_circuit_T
#define rtXdot                         ac_der_basic_model_1_sm_circuit_XDot
#define StateDerivatives               XDot_ac_der_basic_model_1_sm_circuit_T
#define tXdis                          ac_der_basic_model_1_sm_circuit_XDis
#define StateDisabled                  XDis_ac_der_basic_model_1_sm_circuit_T
#define rtP                            ac_der_basic_model_1_sm_circuit_P
#define Parameters                     P_ac_der_basic_model_1_sm_circuit_T
#define rtDWork                        ac_der_basic_model_1_sm_circuit_DW
#define D_Work                         DW_ac_der_basic_model_1_sm_circuit_T

/* Parameters for system: '<S6>/RMS ' */
struct P_RMS_ac_der_basic_model_1_sm_T_ {
  real_T Fourier1_Freq;                /* Mask Parameter: Fourier1_Freq
                                        * Referenced by:
                                        *   '<S20>/cos(wt)' (Parameter: Frequency)
                                        *   '<S20>/sin(wt)' (Parameter: Frequency)
                                        */
  real_T Gain_Gain;                    /* Expression: sps.Freq
                                        * Referenced by: '<S23>/Gain' (Parameter: Gain)
                                        */
  real_T Gain_Gain_m;                  /* Expression: sps.Freq
                                        * Referenced by: '<S24>/Gain' (Parameter: Gain)
                                        */
  real_T integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S24>/integrator' (Parameter: InitialCondition)
                                        */
  real_T TransportDelay_Delay;         /* Expression: 1./sps.Freq
                                        * Referenced by: '<S24>/Transport Delay' (Parameter: DelayTime)
                                        */
  real_T TransportDelay_InitOutput;    /* Expression: 0
                                        * Referenced by: '<S24>/Transport Delay' (Parameter: InitialOutput)
                                        */
  real_T K1_Value;                     /* Expression: 1./sps.Freq
                                        * Referenced by: '<S24>/K1' (Parameter: Value)
                                        */
  real_T Memory_InitialCondition;      /* Expression: sps.Vinit
                                        * Referenced by: '<S24>/Memory' (Parameter: InitialCondition)
                                        */
  real_T integrator_IC_o;              /* Expression: 0
                                        * Referenced by: '<S23>/integrator' (Parameter: InitialCondition)
                                        */
  real_T TransportDelay_Delay_l;       /* Expression: 1./sps.Freq
                                        * Referenced by: '<S23>/Transport Delay' (Parameter: DelayTime)
                                        */
  real_T TransportDelay_InitOutput_o;  /* Expression: 0
                                        * Referenced by: '<S23>/Transport Delay' (Parameter: InitialOutput)
                                        */
  real_T K1_Value_g;                   /* Expression: 1./sps.Freq
                                        * Referenced by: '<S23>/K1' (Parameter: Value)
                                        */
  real_T Memory_InitialCondition_l;    /* Expression: sps.Vinit
                                        * Referenced by: '<S23>/Memory' (Parameter: InitialCondition)
                                        */
  real_T sinwt_Amp;                    /* Expression: sps.k
                                        * Referenced by: '<S20>/sin(wt)' (Parameter: Amplitude)
                                        */
  real_T sinwt_Bias;                   /* Expression: 0
                                        * Referenced by: '<S20>/sin(wt)' (Parameter: Bias)
                                        */
  real_T sinwt_Phase;                  /* Expression: 0
                                        * Referenced by: '<S20>/sin(wt)' (Parameter: Phase)
                                        */
  real_T coswt_Amp;                    /* Expression: sps.k
                                        * Referenced by: '<S20>/cos(wt)' (Parameter: Amplitude)
                                        */
  real_T coswt_Bias;                   /* Expression: 0
                                        * Referenced by: '<S20>/cos(wt)' (Parameter: Bias)
                                        */
  real_T coswt_Phase;                  /* Expression: pi/2
                                        * Referenced by: '<S20>/cos(wt)' (Parameter: Phase)
                                        */
  real_T RadDeg_Gain;                  /* Expression: 180/pi
                                        * Referenced by: '<S20>/Rad->Deg.' (Parameter: Gain)
                                        */
  real_T Gain_Gain_b;                  /* Expression: 1/sqrt(2)
                                        * Referenced by: '<S18>/Gain' (Parameter: Gain)
                                        */
};

/* Parameters for system: '<S6>/TrueRMS ' */
struct P_TrueRMS_ac_der_basic_model__T_ {
  real_T Gain_Gain;                    /* Expression: sps.Freq
                                        * Referenced by: '<S26>/Gain' (Parameter: Gain)
                                        */
  real_T integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S26>/integrator' (Parameter: InitialCondition)
                                        */
  real_T TransportDelay_Delay;         /* Expression: 1./sps.Freq
                                        * Referenced by: '<S26>/Transport Delay' (Parameter: DelayTime)
                                        */
  real_T TransportDelay_InitOutput;    /* Expression: 0
                                        * Referenced by: '<S26>/Transport Delay' (Parameter: InitialOutput)
                                        */
  real_T K1_Value;                     /* Expression: 1./sps.Freq
                                        * Referenced by: '<S26>/K1' (Parameter: Value)
                                        */
  real_T Memory_InitialCondition;      /* Expression: sps.Vinit
                                        * Referenced by: '<S26>/Memory' (Parameter: InitialCondition)
                                        */
  real_T Saturationtoavoidnegativesqrt_U;/* Expression: Inf
                                          * Referenced by: '<S19>/Saturation to avoid negative sqrt' (Parameter: UpperLimit)
                                          */
  real_T Saturationtoavoidnegativesqrt_L;/* Expression: 0
                                          * Referenced by: '<S19>/Saturation to avoid negative sqrt' (Parameter: LowerLimit)
                                          */
};

/* Parameters (default storage) */
struct P_ac_der_basic_model_1_sm_circuit_T_ {
  real_T RMS2_TrueRMS;                 /* Mask Parameter: RMS2_TrueRMS
                                        * Referenced by: '<S7>/Constant' (Parameter: Value)
                                        */
  real_T RMS1_TrueRMS;                 /* Mask Parameter: RMS1_TrueRMS
                                        * Referenced by: '<S6>/Constant' (Parameter: Value)
                                        */
  real_T SFunction1_Value;             /* Expression: 0
                                        * Referenced by: '<S1>/S-Function1' (Parameter: Value)
                                        */
  real_T SFunction_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S1>/S-Function' (Parameter: InitialCondition)
                                        */
  real_T SFunction_P1_Size[2];         /* Computed Parameter: SFunction_P1_Size
                                        * Referenced by: '<S12>/S-Function' (Parameter: P1Size)
                                        */
  real_T SFunction_P1;                 /* Expression: Data_width
                                        * Referenced by: '<S12>/S-Function' (Parameter: P1)
                                        */
  real_T SFunction_P2_Size[2];         /* Computed Parameter: SFunction_P2_Size
                                        * Referenced by: '<S12>/S-Function' (Parameter: P2Size)
                                        */
  real_T SFunction_P2[2];              /* Expression: InitialConditions
                                        * Referenced by: '<S12>/S-Function' (Parameter: P2)
                                        */
  real_T Constant_Value;               /* Expression: sqrt(2)
                                        * Referenced by: '<S2>/Constant' (Parameter: Value)
                                        */
  real_T SineWave1_Amp;                /* Expression: 1
                                        * Referenced by: '<S2>/Sine Wave1' (Parameter: Amplitude)
                                        */
  real_T SineWave1_Bias;               /* Expression: 0
                                        * Referenced by: '<S2>/Sine Wave1' (Parameter: Bias)
                                        */
  real_T SineWave1_Freq;               /* Expression: 2*pi*50
                                        * Referenced by: '<S2>/Sine Wave1' (Parameter: Frequency)
                                        */
  real_T SineWave1_Phase;              /* Expression: 0
                                        * Referenced by: '<S2>/Sine Wave1' (Parameter: Phase)
                                        */
  real_T SineWave2_Amp;                /* Expression: 1
                                        * Referenced by: '<S2>/Sine Wave2' (Parameter: Amplitude)
                                        */
  real_T SineWave2_Bias;               /* Expression: 0
                                        * Referenced by: '<S2>/Sine Wave2' (Parameter: Bias)
                                        */
  real_T SineWave2_Freq;               /* Expression: 2*pi*50
                                        * Referenced by: '<S2>/Sine Wave2' (Parameter: Frequency)
                                        */
  real_T SineWave2_Phase;              /* Expression: -2*pi/3
                                        * Referenced by: '<S2>/Sine Wave2' (Parameter: Phase)
                                        */
  real_T SineWave3_Amp;                /* Expression: 1
                                        * Referenced by: '<S2>/Sine Wave3' (Parameter: Amplitude)
                                        */
  real_T SineWave3_Bias;               /* Expression: 0
                                        * Referenced by: '<S2>/Sine Wave3' (Parameter: Bias)
                                        */
  real_T SineWave3_Freq;               /* Expression: 2*pi*50
                                        * Referenced by: '<S2>/Sine Wave3' (Parameter: Frequency)
                                        */
  real_T SineWave3_Phase;              /* Expression: 2*pi/3
                                        * Referenced by: '<S2>/Sine Wave3' (Parameter: Phase)
                                        */
  real_T Constant1_Value;              /* Expression: 1/3
                                        * Referenced by: '<S2>/Constant1' (Parameter: Value)
                                        */
  real_T Constant2_Value;              /* Expression: sqrt(2)
                                        * Referenced by: '<S2>/Constant2' (Parameter: Value)
                                        */
  real_T SineWave4_Amp;                /* Expression: 1
                                        * Referenced by: '<S2>/Sine Wave4' (Parameter: Amplitude)
                                        */
  real_T SineWave4_Bias;               /* Expression: 0
                                        * Referenced by: '<S2>/Sine Wave4' (Parameter: Bias)
                                        */
  real_T SineWave4_Freq;               /* Expression: 2*pi*50
                                        * Referenced by: '<S2>/Sine Wave4' (Parameter: Frequency)
                                        */
  real_T SineWave4_Phase;              /* Expression: 0
                                        * Referenced by: '<S2>/Sine Wave4' (Parameter: Phase)
                                        */
  real_T SineWave5_Amp;                /* Expression: 1
                                        * Referenced by: '<S2>/Sine Wave5' (Parameter: Amplitude)
                                        */
  real_T SineWave5_Bias;               /* Expression: 0
                                        * Referenced by: '<S2>/Sine Wave5' (Parameter: Bias)
                                        */
  real_T SineWave5_Freq;               /* Expression: 2*pi*50
                                        * Referenced by: '<S2>/Sine Wave5' (Parameter: Frequency)
                                        */
  real_T SineWave5_Phase;              /* Expression: -2*pi/3
                                        * Referenced by: '<S2>/Sine Wave5' (Parameter: Phase)
                                        */
  real_T SineWave6_Amp;                /* Expression: 1
                                        * Referenced by: '<S2>/Sine Wave6' (Parameter: Amplitude)
                                        */
  real_T SineWave6_Bias;               /* Expression: 0
                                        * Referenced by: '<S2>/Sine Wave6' (Parameter: Bias)
                                        */
  real_T SineWave6_Freq;               /* Expression: 2*pi*50
                                        * Referenced by: '<S2>/Sine Wave6' (Parameter: Frequency)
                                        */
  real_T SineWave6_Phase;              /* Expression: 2*pi/3
                                        * Referenced by: '<S2>/Sine Wave6' (Parameter: Phase)
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S2>/Delay' (Parameter: InitialCondition)
                                        */
  real_T Constant3_Value;              /* Expression: 3
                                        * Referenced by: '<S2>/Constant3' (Parameter: Value)
                                        */
  real_T SFunction_P1_Size_a[2];      /* Computed Parameter: SFunction_P1_Size_a
                                       * Referenced by: '<S40>/S-Function' (Parameter: P1Size)
                                       */
  real_T SFunction_P1_h;               /* Expression: Acqu_group
                                        * Referenced by: '<S40>/S-Function' (Parameter: P1)
                                        */
  P_TrueRMS_ac_der_basic_model__T TrueRMS_f;/* '<S7>/TrueRMS ' */
  P_RMS_ac_der_basic_model_1_sm_T RMS_l;/* '<S7>/RMS ' */
  P_TrueRMS_ac_der_basic_model__T TrueRMS;/* '<S6>/TrueRMS ' */
  P_RMS_ac_der_basic_model_1_sm_T RMS; /* '<S6>/RMS ' */
};

/* Real-time Model Data Structure */
struct tag_RTM_ac_der_basic_model_1_sm_circuit_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[2];
    SimStruct *childSFunctionPtrs[2];
    struct _ssBlkInfo2 blkInfo2[2];
    struct _ssSFcnModelMethods2 methods2[2];
    struct _ssSFcnModelMethods3 methods3[2];
    struct _ssSFcnModelMethods4 methods4[2];
    struct _ssStatesInfo2 statesInfo2[2];
    ssPeriodicStatesInfo periodicStatesInfo[2];
    struct _ssPortInfo2 inputOutputPortInfo2[2];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      uint_T attribs[1];
      mxArray *params[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn1;
  } NonInlinedSFcns;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T CTOutputIncnstWithState;
    real_T odeY[9];
    real_T odeF[3][9];
    ODE3_IntgData intgData;
    void *dwork;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_ac_der_basic_model_1_sm_circuit_T ac_der_basic_model_1_sm_circuit_P;

/* Block signals (default storage) */
extern B_ac_der_basic_model_1_sm_circuit_T ac_der_basic_model_1_sm_circuit_B;

/* Continuous states (default storage) */
extern X_ac_der_basic_model_1_sm_circuit_T ac_der_basic_model_1_sm_circuit_X;

/* Block states (default storage) */
extern DW_ac_der_basic_model_1_sm_circuit_T ac_der_basic_model_1_sm_circuit_DW;

/* Model entry point functions */
extern void ac_der_basic_model_1_sm_circuit_initialize(void);
extern void ac_der_basic_model_1_sm_circuit_output(void);
extern void ac_der_basic_model_1_sm_circuit_update(void);
extern void ac_der_basic_model_1_sm_circuit_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern ac_der_basic_model_1_sm_circuit_rtModel *ac_der_basic_model_1_sm_circuit
  (void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_ac_der_basic_model_1_sm_circuit_T *const
  ac_der_basic_model_1_sm_circuit_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ac_der_basic_model_1_sm_circuit'
 * '<S1>'   : 'ac_der_basic_model_1_sm_circuit/OpCCode_do_not_touch'
 * '<S2>'   : 'ac_der_basic_model_1_sm_circuit/sm_circuit'
 * '<S3>'   : 'ac_der_basic_model_1_sm_circuit/sm_circuit/OpComm1'
 * '<S4>'   : 'ac_der_basic_model_1_sm_circuit/sm_circuit/PS-Simulink Converter1'
 * '<S5>'   : 'ac_der_basic_model_1_sm_circuit/sm_circuit/PS-Simulink Converter2'
 * '<S6>'   : 'ac_der_basic_model_1_sm_circuit/sm_circuit/RMS1'
 * '<S7>'   : 'ac_der_basic_model_1_sm_circuit/sm_circuit/RMS2'
 * '<S8>'   : 'ac_der_basic_model_1_sm_circuit/sm_circuit/Simulink-PS Converter1'
 * '<S9>'   : 'ac_der_basic_model_1_sm_circuit/sm_circuit/Simulink-PS Converter3'
 * '<S10>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/Solver Configuration1'
 * '<S11>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/rtlab_send_subsystem'
 * '<S12>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/OpComm1/Receive'
 * '<S13>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/OpComm1/busStruct'
 * '<S14>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/OpComm1/busStruct/Sub1'
 * '<S15>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/OpComm1/busStruct/Sub2'
 * '<S16>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/PS-Simulink Converter1/EVAL_KEY'
 * '<S17>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/PS-Simulink Converter2/EVAL_KEY'
 * '<S18>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/RMS1/RMS '
 * '<S19>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/RMS1/TrueRMS '
 * '<S20>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/RMS1/RMS /Fourier1'
 * '<S21>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/RMS1/RMS /Fourier1/Mean'
 * '<S22>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/RMS1/RMS /Fourier1/Mean value1'
 * '<S23>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/RMS1/RMS /Fourier1/Mean/Model'
 * '<S24>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/RMS1/RMS /Fourier1/Mean value1/Model'
 * '<S25>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/RMS1/TrueRMS /Mean value'
 * '<S26>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/RMS1/TrueRMS /Mean value/Model'
 * '<S27>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/RMS2/RMS '
 * '<S28>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/RMS2/TrueRMS '
 * '<S29>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/RMS2/RMS /Fourier1'
 * '<S30>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/RMS2/RMS /Fourier1/Mean'
 * '<S31>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/RMS2/RMS /Fourier1/Mean value1'
 * '<S32>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/RMS2/RMS /Fourier1/Mean/Model'
 * '<S33>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/RMS2/RMS /Fourier1/Mean value1/Model'
 * '<S34>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/RMS2/TrueRMS /Mean value'
 * '<S35>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/RMS2/TrueRMS /Mean value/Model'
 * '<S36>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/Simulink-PS Converter1/EVAL_KEY'
 * '<S37>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/Simulink-PS Converter3/EVAL_KEY'
 * '<S38>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/Solver Configuration1/EVAL_KEY'
 * '<S39>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/rtlab_send_subsystem/Subsystem1'
 * '<S40>'  : 'ac_der_basic_model_1_sm_circuit/sm_circuit/rtlab_send_subsystem/Subsystem1/Send1'
 */
#endif                       /* RTW_HEADER_ac_der_basic_model_1_sm_circuit_h_ */
