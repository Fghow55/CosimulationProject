/*
 * dc_microgrid_6_1_sm_circuit.h
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

#ifndef RTW_HEADER_dc_microgrid_6_1_sm_circuit_h_
#define RTW_HEADER_dc_microgrid_6_1_sm_circuit_h_
#include <stddef.h>
#include <float.h>
#include <math.h>
#include <string.h>
#ifndef dc_microgrid_6_1_sm_circuit_COMMON_INCLUDES_
#define dc_microgrid_6_1_sm_circuit_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                        /* dc_microgrid_6_1_sm_circuit_COMMON_INCLUDES_ */

#include "dc_microgrid_6_1_sm_circuit_types.h"

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
#define dc_microgrid_6_1_sm_circuit_rtModel RT_MODEL_dc_microgrid_6_1_sm_circuit_T

/* user code (top of header file) */
/* System '<Root>' */
/* Opal-RT Technologies */
extern int opalSizeDwork;
extern unsigned int opalSizeBlockIO;
extern unsigned int opalSizeRTP;
extern void * pRtModel;                //pointer on the RTmodel struc
int_T Opal_rtmGetNumBlockParams(void *ptr);
int_T Opal_rtmGetNumBlockIO(void *ptr);

/* Block signals (default storage) */
typedef struct {
  creal_T RealImagtoComplex[3];   /* '<S61>/Real-Imag to Complex' (Output 1)  */
  creal_T RealImagtoComplex_e[3]; /* '<S62>/Real-Imag to Complex' (Output 1)  */
  creal_T RealImagtoComplex_a;    /* '<S73>/Real-Imag to Complex' (Output 1)  */
  real_T SFunction;                    /* '<S1>/S-Function' (Output 1)  */
  real_T Sum;                          /* '<S1>/Sum' (Output 1)  */
  real_T SineWave3;                    /* '<S3>/Sine Wave3' (Output 1)  */
  real_T SFunction_d[2];               /* '<S57>/S-Function' (Output 1)  */
  real_T Product6;                     /* '<S3>/Product6' (Output 1)  */
  real_T Product5;                     /* '<S3>/Product5' (Output 1)  */
  real_T SineWave4;                    /* '<S3>/Sine Wave4' (Output 1)  */
  real_T Product7;                     /* '<S3>/Product7' (Output 1)  */
  real_T SineWave5;                    /* '<S3>/Sine Wave5' (Output 1)  */
  real_T Product8;                     /* '<S3>/Product8' (Output 1)  */
  real_T Delay1;                       /* '<S3>/Delay1' (Output 1)  */
  real_T Divide1;                      /* '<S3>/Divide1' (Output 1)  */
  real_T StateSpace_o1[20];            /* '<S4>/State-Space' (Output 1)  */
  real_T StateSpace_o2[6];             /* '<S4>/State-Space' (Output 2)  */
  real_T integrator[3];                /* '<S66>/integrator' (Output 1)  */
  real_T TransportDelay[3];            /* '<S66>/Transport Delay' (Output 1)  */
  real_T Clock;                        /* '<S66>/Clock' (Output 1)  */
  real_T Memory[3];                    /* '<S66>/Memory' (Output 1)  */
  real_T Switch[3];                    /* '<S66>/Switch' (Output 1)  */
  real_T integrator_p[3];              /* '<S65>/integrator' (Output 1)  */
  real_T TransportDelay_n[3];          /* '<S65>/Transport Delay' (Output 1)  */
  real_T Clock_p;                      /* '<S65>/Clock' (Output 1)  */
  real_T Memory_j[3];                  /* '<S65>/Memory' (Output 1)  */
  real_T Switch_h[3];                  /* '<S65>/Switch' (Output 1)  */
  real_T ComplextoMagnitudeAngle_o1[3];
                            /* '<S61>/Complex to Magnitude-Angle' (Output 1)  */
  real_T ComplextoMagnitudeAngle_o2[3];
                            /* '<S61>/Complex to Magnitude-Angle' (Output 2)  */
  real_T integrator_f[3];              /* '<S70>/integrator' (Output 1)  */
  real_T TransportDelay_a[3];          /* '<S70>/Transport Delay' (Output 1)  */
  real_T Clock_g;                      /* '<S70>/Clock' (Output 1)  */
  real_T Memory_g[3];                  /* '<S70>/Memory' (Output 1)  */
  real_T Switch_k[3];                  /* '<S70>/Switch' (Output 1)  */
  real_T integrator_b[3];              /* '<S69>/integrator' (Output 1)  */
  real_T TransportDelay_b[3];          /* '<S69>/Transport Delay' (Output 1)  */
  real_T Clock_k;                      /* '<S69>/Clock' (Output 1)  */
  real_T Memory_p[3];                  /* '<S69>/Memory' (Output 1)  */
  real_T Switch_d[3];                  /* '<S69>/Switch' (Output 1)  */
  real_T ComplextoMagnitudeAngle_o1_d[3];
                            /* '<S62>/Complex to Magnitude-Angle' (Output 1)  */
  real_T ComplextoMagnitudeAngle_o2_f[3];
                            /* '<S62>/Complex to Magnitude-Angle' (Output 2)  */
  real_T VfundIfund[3];                /* '<S17>/Product' (Output 1)  */
  real_T Gain1[3];                     /* '<S17>/Gain1' (Output 1)  */
  real_T RadDeg[3];                    /* '<S61>/Rad->Deg.' (Output 1)  */
  real_T RadDeg_n[3];                  /* '<S62>/Rad->Deg.' (Output 1)  */
  real_T Sum_d[3];                     /* '<S17>/Sum' (Output 1)  */
  real_T phi[3];                       /* '<S17>/Deg->Rad' (Output 1)  */
  real_T TrigonometricFunction2_o1[3];
                               /* '<S17>/Trigonometric Function2' (Output 1)  */
  real_T TrigonometricFunction2_o2[3];
                               /* '<S17>/Trigonometric Function2' (Output 2)  */
  real_T Product1[3];                  /* '<S17>/Product1' (Output 1)  */
  real_T Add;                          /* '<S3>/Add' (Output 1)  */
  real_T donotdeletethisgain;  /* '<S83>/do not delete this gain' (Output 1)  */
  real_T donotdeletethisgain_j;/* '<S84>/do not delete this gain' (Output 1)  */
  real_T donotdeletethisgain_p;/* '<S85>/do not delete this gain' (Output 1)  */
  real_T Kv[3];                        /* '<S19>/Kv' (Output 1)  */
  real_T Switch_m;                     /* '<S18>/Switch' (Output 1)  */
  real_T donotdeletethisgain_l;/* '<S86>/do not delete this gain' (Output 1)  */
  real_T donotdeletethisgain_jm;
                               /* '<S87>/do not delete this gain' (Output 1)  */
  real_T donotdeletethisgain_jz;
                               /* '<S88>/do not delete this gain' (Output 1)  */
  real_T Kv1[3];                       /* '<S19>/Kv1' (Output 1)  */
  real_T sinwt;                        /* '<S61>/sin(wt)' (Output 1)  */
  real_T Product[3];                   /* '<S61>/Product' (Output 1)  */
  real_T coswt;                        /* '<S61>/cos(wt)' (Output 1)  */
  real_T Product1_o[3];                /* '<S61>/Product1' (Output 1)  */
  real_T sinwt_b;                      /* '<S62>/sin(wt)' (Output 1)  */
  real_T Product_l[3];                 /* '<S62>/Product' (Output 1)  */
  real_T coswt_e;                      /* '<S62>/cos(wt)' (Output 1)  */
  real_T Product1_oy[3];               /* '<S62>/Product1' (Output 1)  */
  real_T Product3[3];                  /* '<S17>/Product3' (Output 1)  */
  real_T Sign;                         /* '<S3>/Sign' (Output 1)  */
  real_T Product_e;                    /* '<S3>/Product' (Output 1)  */
  real_T donotdeletethisgain_pt;
                               /* '<S20>/do not delete this gain' (Output 1)  */
  real_T donotdeletethisgain_i;/* '<S13>/do not delete this gain' (Output 1)  */
  real_T Product4;                     /* '<S3>/Product4' (Output 1)  */
  real_T UnitDelay4[6];                /* '<S23>/Unit Delay4' (Output 1)  */
  real_T DataTypeConversion[6];   /* '<S31>/Data Type Conversion' (Output 1)  */
  real_T donotdeletethisgain_j4;
                               /* '<S33>/do not delete this gain' (Output 1)  */
  real_T donotdeletethisgain_o;/* '<S38>/do not delete this gain' (Output 1)  */
  real_T donotdeletethisgain_c;/* '<S39>/do not delete this gain' (Output 1)  */
  real_T Product_d[3];                 /* '<S36>/Product' (Output 1)  */
  real_T Integ4[3];                    /* '<S48>/Integ4' (Output 1)  */
  real_T SFunction_p[3];               /* '<S49>/S-Function ' (Output 1)  */
  real_T UnitDelay[3];                 /* '<S48>/Unit Delay' (Output 1)  */
  real_T Step;                         /* '<S48>/Step' (Output 1)  */
  real_T Switch_c[3];                  /* '<S48>/Switch' (Output 1)  */
  real_T SaturationAjoutPBpourevitersqrt[3];
       /* '<S36>/Saturation Ajout P.B pour eviter  sqrt(negatif)' (Output 1)  */
  real_T Sqrt[3];                      /* '<S36>/Sqrt' (Output 1)  */
  real_T donotdeletethisgain_or;
                               /* '<S40>/do not delete this gain' (Output 1)  */
  real_T donotdeletethisgain_c0;
                               /* '<S41>/do not delete this gain' (Output 1)  */
  real_T donotdeletethisgain_a;/* '<S42>/do not delete this gain' (Output 1)  */
  real_T Product_o;                    /* '<S37>/Product' (Output 1)  */
  real_T Integ4_e;                     /* '<S50>/Integ4' (Output 1)  */
  real_T SFunction_m;                  /* '<S51>/S-Function ' (Output 1)  */
  real_T UnitDelay_m;                  /* '<S50>/Unit Delay' (Output 1)  */
  real_T Step_l;                       /* '<S50>/Step' (Output 1)  */
  real_T Switch_b;                     /* '<S50>/Switch' (Output 1)  */
  real_T SaturationAjoutPBpourevitersq_h;
       /* '<S37>/Saturation Ajout P.B pour eviter  sqrt(negatif)' (Output 1)  */
  real_T Sqrt_e;                       /* '<S37>/Sqrt' (Output 1)  */
  real_T Product_er;                   /* '<S34>/Product' (Output 1)  */
  real_T Integ4_b;                     /* '<S44>/Integ4' (Output 1)  */
  real_T SFunction_j;                  /* '<S45>/S-Function ' (Output 1)  */
  real_T UnitDelay_o;                  /* '<S44>/Unit Delay' (Output 1)  */
  real_T Step_m;                       /* '<S44>/Step' (Output 1)  */
  real_T Switch_a;                     /* '<S44>/Switch' (Output 1)  */
  real_T SaturationAjoutPBpourevitersq_j;
       /* '<S34>/Saturation Ajout P.B pour eviter  sqrt(negatif)' (Output 1)  */
  real_T Sqrt_b;                       /* '<S34>/Sqrt' (Output 1)  */
  real_T Product_k;                    /* '<S35>/Product' (Output 1)  */
  real_T Integ4_d;                     /* '<S46>/Integ4' (Output 1)  */
  real_T SFunction_k;                  /* '<S47>/S-Function ' (Output 1)  */
  real_T UnitDelay_n;                  /* '<S46>/Unit Delay' (Output 1)  */
  real_T Step_k;                       /* '<S46>/Step' (Output 1)  */
  real_T Switch_j;                     /* '<S46>/Switch' (Output 1)  */
  real_T SaturationAjoutPBpourevitersq_n;
       /* '<S35>/Saturation Ajout P.B pour eviter  sqrt(negatif)' (Output 1)  */
  real_T Sqrt_d;                       /* '<S35>/Sqrt' (Output 1)  */
  real_T Switch2;                      /* '<S28>/Switch2' (Output 1)  */
  real_T t;                            /* '<S25>/t' (Output 1)  */
  real_T t_o;                          /* '<S30>/t' (Output 1)  */
  real_T Switch_l[3];                  /* '<S25>/Switch' (Output 1)  */
  real_T Clock_j;                      /* '<S27>/Clock' (Output 1)  */
  real_T Sum_b;                        /* '<S27>/Sum' (Output 1)  */
  real_T MathFunction;                 /* '<S27>/Math Function' (Output 1)  */
  real_T LookUpTable1;                 /* '<S27>/Look-Up Table1' (Output 1)  */
  real_T Output;                       /* '<S27>/Output' (Output 1)  */
  real_T Gain3[3];                     /* '<S25>/Gain3' (Output 1)  */
  real_T DataTypeConversion_i[6];/* '<S25>/Data Type  Conversion' (Output 1)  */
  real_T Clock_h;                      /* '<S79>/Clock' (Output 1)  */
  real_T integrator_k;                 /* '<S79>/integrator' (Output 1)  */
  real_T TransportDelay_j;             /* '<S79>/Transport Delay' (Output 1)  */
  real_T Memory_c;                     /* '<S79>/Memory' (Output 1)  */
  real_T Switch_cu;                    /* '<S79>/Switch' (Output 1)  */
  real_T Product_kk;                   /* '<S72>/Product' (Output 1)  */
  real_T Saturationtoavoidnegativesqrt;
                     /* '<S72>/Saturation to avoid negative sqrt' (Output 1)  */
  real_T Sqrt_p;                       /* '<S72>/Sqrt' (Output 1)  */
  real_T Sum_a;                        /* '<S79>/Sum' (Output 1)  */
  real_T Gain;                         /* '<S79>/Gain' (Output 1)  */
  real_T integrator_h;                 /* '<S77>/integrator' (Output 1)  */
  real_T TransportDelay_c;             /* '<S77>/Transport Delay' (Output 1)  */
  real_T Clock_js;                     /* '<S77>/Clock' (Output 1)  */
  real_T Memory_m;                     /* '<S77>/Memory' (Output 1)  */
  real_T Switch_k1;                    /* '<S77>/Switch' (Output 1)  */
  real_T integrator_a;                 /* '<S76>/integrator' (Output 1)  */
  real_T TransportDelay_an;            /* '<S76>/Transport Delay' (Output 1)  */
  real_T Clock_a;                      /* '<S76>/Clock' (Output 1)  */
  real_T Memory_h;                     /* '<S76>/Memory' (Output 1)  */
  real_T Switch_o;                     /* '<S76>/Switch' (Output 1)  */
  real_T ComplextoMagnitudeAngle_o1_h;
                            /* '<S73>/Complex to Magnitude-Angle' (Output 1)  */
  real_T ComplextoMagnitudeAngle_o2_fx;
                            /* '<S73>/Complex to Magnitude-Angle' (Output 2)  */
  real_T sinwt_g;                      /* '<S73>/sin(wt)' (Output 1)  */
  real_T Product_c;                    /* '<S73>/Product' (Output 1)  */
  real_T coswt_a;                      /* '<S73>/cos(wt)' (Output 1)  */
  real_T Product1_d;                   /* '<S73>/Product1' (Output 1)  */
  real_T RadDeg_p;                     /* '<S73>/Rad->Deg.' (Output 1)  */
  real_T Gain_b;                       /* '<S71>/Gain' (Output 1)  */
  real_T Sum_e;                        /* '<S77>/Sum' (Output 1)  */
  real_T Gain_e;                       /* '<S77>/Gain' (Output 1)  */
  real_T Sum_g;                        /* '<S76>/Sum' (Output 1)  */
  real_T Gain_m;                       /* '<S76>/Gain' (Output 1)  */
  real_T Sum_bj[3];                    /* '<S70>/Sum' (Output 1)  */
  real_T Gain_l[3];                    /* '<S70>/Gain' (Output 1)  */
  real_T Sum_dn[3];                    /* '<S69>/Sum' (Output 1)  */
  real_T Gain_ej[3];                   /* '<S69>/Gain' (Output 1)  */
  real_T Sum_db[3];                    /* '<S66>/Sum' (Output 1)  */
  real_T Gain_g[3];                    /* '<S66>/Gain' (Output 1)  */
  real_T Sum_n[3];                     /* '<S65>/Sum' (Output 1)  */
  real_T Gain_eh[3];                   /* '<S65>/Gain' (Output 1)  */
  real_T Gain_n;                       /* '<S50>/Gain' (Output 1)  */
  real_T Gain1_i;                      /* '<S50>/Gain1' (Output 1)  */
  real_T Correction;                   /* '<S50>/Sum1' (Output 1)  */
  real_T Sum7;                         /* '<S50>/Sum7' (Output 1)  */
  real_T Meanvalue;                    /* '<S50>/Product' (Output 1)  */
  real_T Sum5;                         /* '<S50>/Sum5' (Output 1)  */
  real_T Gain_bl[3];                   /* '<S48>/Gain' (Output 1)  */
  real_T Gain1_b[3];                   /* '<S48>/Gain1' (Output 1)  */
  real_T Correction_o[3];              /* '<S48>/Sum1' (Output 1)  */
  real_T Sum7_h[3];                    /* '<S48>/Sum7' (Output 1)  */
  real_T Meanvalue_m[3];               /* '<S48>/Product' (Output 1)  */
  real_T Sum5_c[3];                    /* '<S48>/Sum5' (Output 1)  */
  real_T Gain_bd;                      /* '<S46>/Gain' (Output 1)  */
  real_T Gain1_e;                      /* '<S46>/Gain1' (Output 1)  */
  real_T Correction_h;                 /* '<S46>/Sum1' (Output 1)  */
  real_T Sum7_b;                       /* '<S46>/Sum7' (Output 1)  */
  real_T Meanvalue_n;                  /* '<S46>/Product' (Output 1)  */
  real_T Sum5_a;                       /* '<S46>/Sum5' (Output 1)  */
  real_T Gain_j;                       /* '<S44>/Gain' (Output 1)  */
  real_T Gain1_c;                      /* '<S44>/Gain1' (Output 1)  */
  real_T Correction_b;                 /* '<S44>/Sum1' (Output 1)  */
  real_T Sum7_m;                       /* '<S44>/Sum7' (Output 1)  */
  real_T Meanvalue_d;                  /* '<S44>/Product' (Output 1)  */
  real_T Sum5_m;                       /* '<S44>/Sum5' (Output 1)  */
  real_T Switch2_c;                    /* '<S30>/Switch2' (Output 1)  */
  real_T DegRad;                       /* '<S30>/Deg->Rad' (Output 1)  */
  real_T Product7_d;                   /* '<S30>/Product7' (Output 1)  */
  real_T Sum_k;                        /* '<S30>/Sum' (Output 1)  */
  real_T MathFunction_h;               /* '<S30>/Math Function' (Output 1)  */
  real_T TrigonometricFunction; /* '<S30>/Trigonometric Function' (Output 1)  */
  real_T Product2;                     /* '<S29>/Product2' (Output 1)  */
  real_T TrigonometricFunction1;
                               /* '<S30>/Trigonometric Function1' (Output 1)  */
  real_T Product3_e;                   /* '<S29>/Product3' (Output 1)  */
  real_T coswt2pi3;                    /* '<S29>/Sum1' (Output 1)  */
  real_T coswt2pi3_j;                  /* '<S29>/Sum3' (Output 1)  */
  real_T Product1_n;                   /* '<S29>/Product1' (Output 1)  */
  real_T Product_n;                    /* '<S29>/Product' (Output 1)  */
  real_T sinwt2pi3;                    /* '<S29>/Sum' (Output 1)  */
  real_T sinwt2pi3_p;                  /* '<S29>/Sum2' (Output 1)  */
  real_T Fcn2;                         /* '<S29>/Fcn2' (Output 1)  */
  real_T Product_a;                    /* '<S26>/Product' (Output 1)  */
  real_T Fcn4;                         /* '<S29>/Fcn4' (Output 1)  */
  real_T Product1_j;                   /* '<S26>/Product1' (Output 1)  */
  real_T Fcn5;                         /* '<S29>/Fcn5' (Output 1)  */
  real_T Product2_h;                   /* '<S26>/Product2' (Output 1)  */
  real_T Gain2;                        /* '<S25>/Gain2' (Output 1)  */
  real_T Gain_d;                       /* '<S25>/Gain' (Output 1)  */
  real_T Sum_o[3];                     /* '<S25>/Sum' (Output 1)  */
  real_T TrigonometricFunction_i[3];
                                /* '<S25>/Trigonometric Function' (Output 1)  */
  real_T Product_m[3];                 /* '<S25>/Product' (Output 1)  */
  boolean_T RelationalOperator;    /* '<S66>/Relational Operator' (Output 1)  */
  boolean_T RelationalOperator_e;  /* '<S65>/Relational Operator' (Output 1)  */
  boolean_T RelationalOperator_c;  /* '<S70>/Relational Operator' (Output 1)  */
  boolean_T RelationalOperator_b;  /* '<S69>/Relational Operator' (Output 1)  */
  boolean_T DataTypeConversion_l; /* '<S18>/Data Type Conversion' (Output 1)  */
  boolean_T LogicalOperator;          /* '<S18>/Logical Operator' (Output 1)  */
  boolean_T RelationalOperator_f[3];
                                   /* '<S25>/Relational Operator' (Output 1)  */
  boolean_T DataTypeConversion1[3];
                                /* '<S25>/Data Type  Conversion1' (Output 1)  */
  boolean_T BL4[3];                    /* '<S25>/BL4' (Output 1)  */
  boolean_T RelationalOperator1[3];
                                  /* '<S25>/Relational Operator1' (Output 1)  */
  boolean_T DataTypeConversion2[3];
                                /* '<S25>/Data Type  Conversion2' (Output 1)  */
  boolean_T BL5[3];                    /* '<S25>/BL5' (Output 1)  */
  boolean_T RelationalOperator_ej; /* '<S79>/Relational Operator' (Output 1)  */
  boolean_T RelationalOperator_fc; /* '<S77>/Relational Operator' (Output 1)  */
  boolean_T RelationalOperator_a;  /* '<S76>/Relational Operator' (Output 1)  */
} B_dc_microgrid_6_1_sm_circuit_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay1_DSTATE[2];             /* '<S3>/Delay1' (DWork 1)  */
  real_T StateSpace_DSTATE[6];         /* '<S4>/State-Space' (DWork 3)  */
  real_T UnitDelay4_DSTATE[6];         /* '<S23>/Unit Delay4' (DWork 1)  */
  real_T Integ4_DSTATE[3];             /* '<S48>/Integ4' (DWork 1)  */
  real_T UnitDelay_DSTATE[3];          /* '<S48>/Unit Delay' (DWork 1)  */
  real_T Integ4_DSTATE_a;              /* '<S50>/Integ4' (DWork 1)  */
  real_T UnitDelay_DSTATE_b;           /* '<S50>/Unit Delay' (DWork 1)  */
  real_T Integ4_DSTATE_e;              /* '<S44>/Integ4' (DWork 1)  */
  real_T UnitDelay_DSTATE_n;           /* '<S44>/Unit Delay' (DWork 1)  */
  real_T Integ4_DSTATE_l;              /* '<S46>/Integ4' (DWork 1)  */
  real_T UnitDelay_DSTATE_h;           /* '<S46>/Unit Delay' (DWork 1)  */
  real_T SFunction_PreviousInput;      /* '<S1>/S-Function' (DWork 1)  */
  real_T Memory_PreviousInput[3];      /* '<S66>/Memory' (DWork 1)  */
  real_T Memory_PreviousInput_d[3];    /* '<S65>/Memory' (DWork 1)  */
  real_T Memory_PreviousInput_g[3];    /* '<S70>/Memory' (DWork 1)  */
  real_T Memory_PreviousInput_l[3];    /* '<S69>/Memory' (DWork 1)  */
  real_T Memory_PreviousInput_f;       /* '<S79>/Memory' (DWork 1)  */
  real_T Memory_PreviousInput_da;      /* '<S77>/Memory' (DWork 1)  */
  real_T Memory_PreviousInput_i;       /* '<S76>/Memory' (DWork 1)  */
  struct {
    real_T modelTStart;
    real_T TUbufferArea[49152];
  } TransportDelay_RWORK;              /* '<S66>/Transport Delay' (DWork 1)  */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[49152];
  } TransportDelay_RWORK_h;            /* '<S65>/Transport Delay' (DWork 1)  */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[49152];
  } TransportDelay_RWORK_n;            /* '<S70>/Transport Delay' (DWork 1)  */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[49152];
  } TransportDelay_RWORK_hd;           /* '<S69>/Transport Delay' (DWork 1)  */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[16384];
  } TransportDelay_RWORK_n2;           /* '<S79>/Transport Delay' (DWork 1)  */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[16384];
  } TransportDelay_RWORK_j;            /* '<S77>/Transport Delay' (DWork 1)  */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[16384];
  } TransportDelay_RWORK_ju;           /* '<S76>/Transport Delay' (DWork 1)  */

  struct {
    void *AS;
    void *BS;
    void *CS;
    void *DS;
    void *DX_COL;
    void *BD_COL;
    void *TMP1;
    void *TMP2;
    void *XTMP;
    void *SWITCH_STATUS;
    void *SWITCH_STATUS_INIT;
    void *SW_CHG;
    void *G_STATE;
    void *USWLAST;
    void *XKM12;
    void *XKP12;
    void *XLAST;
    void *ULAST;
    void *IDX_SW_CHG;
    void *Y_SWITCH;
    void *SWITCH_TYPES;
    void *IDX_OUT_SW;
    void *SWITCH_TOPO_SAVED_IDX;
    void *SWITCH_MAP;
  } StateSpace_PWORK;                  /* '<S4>/State-Space' (DWork 2)  */

  struct {
    void *TUbufferPtrs[6];
  } TransportDelay_PWORK;              /* '<S66>/Transport Delay' (DWork 3)  */

  struct {
    void *TUbufferPtrs[6];
  } TransportDelay_PWORK_n;            /* '<S65>/Transport Delay' (DWork 3)  */

  struct {
    void *TUbufferPtrs[6];
  } TransportDelay_PWORK_d;            /* '<S70>/Transport Delay' (DWork 3)  */

  struct {
    void *TUbufferPtrs[6];
  } TransportDelay_PWORK_j;            /* '<S69>/Transport Delay' (DWork 3)  */

  struct {
    void *uBuffers[3];
  } SFunction_PWORK;                   /* '<S49>/S-Function ' (DWork 2)  */

  struct {
    void *uBuffers;
  } SFunction_PWORK_p;                 /* '<S51>/S-Function ' (DWork 2)  */

  struct {
    void *uBuffers;
  } SFunction_PWORK_g;                 /* '<S45>/S-Function ' (DWork 2)  */

  struct {
    void *uBuffers;
  } SFunction_PWORK_i;                 /* '<S47>/S-Function ' (DWork 2)  */

  struct {
    void *TUbufferPtrs[2];
  } TransportDelay_PWORK_f;            /* '<S79>/Transport Delay' (DWork 3)  */

  struct {
    void *TUbufferPtrs[2];
  } TransportDelay_PWORK_ny;           /* '<S77>/Transport Delay' (DWork 3)  */

  struct {
    void *TUbufferPtrs[2];
  } TransportDelay_PWORK_nz;           /* '<S76>/Transport Delay' (DWork 3)  */

  int_T StateSpace_IWORK[11];          /* '<S4>/State-Space' (DWork 1)  */
  struct {
    int_T Tail[3];
    int_T Head[3];
    int_T Last[3];
    int_T CircularBufSize[3];
  } TransportDelay_IWORK;              /* '<S66>/Transport Delay' (DWork 2)  */

  struct {
    int_T Tail[3];
    int_T Head[3];
    int_T Last[3];
    int_T CircularBufSize[3];
  } TransportDelay_IWORK_n;            /* '<S65>/Transport Delay' (DWork 2)  */

  struct {
    int_T Tail[3];
    int_T Head[3];
    int_T Last[3];
    int_T CircularBufSize[3];
  } TransportDelay_IWORK_p;            /* '<S70>/Transport Delay' (DWork 2)  */

  struct {
    int_T Tail[3];
    int_T Head[3];
    int_T Last[3];
    int_T CircularBufSize[3];
  } TransportDelay_IWORK_b;            /* '<S69>/Transport Delay' (DWork 2)  */

  int_T SFunction_IWORK[5];            /* '<S97>/S-Function' (DWork 1)  */
  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_k;                 /* '<S49>/S-Function ' (DWork 1)  */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_n;                 /* '<S51>/S-Function ' (DWork 1)  */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_g;                 /* '<S45>/S-Function ' (DWork 1)  */

  struct {
    int_T indBeg;
    int_T indEnd;
    int_T bufSz;
    int_T maxDiscrDelay;
  } SFunction_IWORK_ka;                /* '<S47>/S-Function ' (DWork 1)  */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TransportDelay_IWORK_o;            /* '<S79>/Transport Delay' (DWork 2)  */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TransportDelay_IWORK_ns;           /* '<S77>/Transport Delay' (DWork 2)  */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TransportDelay_IWORK_bl;           /* '<S76>/Transport Delay' (DWork 2)  */

  uint8_T Integ4_SYSTEM_ENABLE;        /* '<S48>/Integ4' (DWork 2)  */
  uint8_T Integ4_SYSTEM_ENABLE_b;      /* '<S50>/Integ4' (DWork 2)  */
  uint8_T Integ4_SYSTEM_ENABLE_g;      /* '<S44>/Integ4' (DWork 2)  */
  uint8_T Integ4_SYSTEM_ENABLE_bk;     /* '<S46>/Integ4' (DWork 2)  */
  boolean_T TrueRMS_MODE;              /* '<S18>/TrueRMS ' (DWork 1)  */
  boolean_T RMS_MODE;                  /* '<S18>/RMS ' (DWork 1)  */
} DW_dc_microgrid_6_1_sm_circuit_T;

/* Continuous states (default storage) */
typedef struct {
  real_T integrator_CSTATE[3];         /* '<S66>/integrator' */
  real_T integrator_CSTATE_m[3];       /* '<S65>/integrator' */
  real_T integrator_CSTATE_p[3];       /* '<S70>/integrator' */
  real_T integrator_CSTATE_me[3];      /* '<S69>/integrator' */
  real_T integrator_CSTATE_c;          /* '<S79>/integrator' */
  real_T integrator_CSTATE_a;          /* '<S77>/integrator' */
  real_T integrator_CSTATE_ao;         /* '<S76>/integrator' */
} X_dc_microgrid_6_1_sm_circuit_T;

/* State derivatives (default storage) */
typedef struct {
  real_T integrator_CSTATE[3];         /* '<S66>/integrator' */
  real_T integrator_CSTATE_m[3];       /* '<S65>/integrator' */
  real_T integrator_CSTATE_p[3];       /* '<S70>/integrator' */
  real_T integrator_CSTATE_me[3];      /* '<S69>/integrator' */
  real_T integrator_CSTATE_c;          /* '<S79>/integrator' */
  real_T integrator_CSTATE_a;          /* '<S77>/integrator' */
  real_T integrator_CSTATE_ao;         /* '<S76>/integrator' */
} XDot_dc_microgrid_6_1_sm_circuit_T;

/* State disabled  */
typedef struct {
  boolean_T integrator_CSTATE[3];      /* '<S66>/integrator' */
  boolean_T integrator_CSTATE_m[3];    /* '<S65>/integrator' */
  boolean_T integrator_CSTATE_p[3];    /* '<S70>/integrator' */
  boolean_T integrator_CSTATE_me[3];   /* '<S69>/integrator' */
  boolean_T integrator_CSTATE_c;       /* '<S79>/integrator' */
  boolean_T integrator_CSTATE_a;       /* '<S77>/integrator' */
  boolean_T integrator_CSTATE_ao;      /* '<S76>/integrator' */
} XDis_dc_microgrid_6_1_sm_circuit_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            dc_microgrid_6_1_sm_circuit_B
#define BlockIO                        B_dc_microgrid_6_1_sm_circuit_T
#define rtX                            dc_microgrid_6_1_sm_circuit_X
#define ContinuousStates               X_dc_microgrid_6_1_sm_circuit_T
#define rtXdot                         dc_microgrid_6_1_sm_circuit_XDot
#define StateDerivatives               XDot_dc_microgrid_6_1_sm_circuit_T
#define tXdis                          dc_microgrid_6_1_sm_circuit_XDis
#define StateDisabled                  XDis_dc_microgrid_6_1_sm_circuit_T
#define rtP                            dc_microgrid_6_1_sm_circuit_P
#define Parameters                     P_dc_microgrid_6_1_sm_circuit_T
#define rtDWork                        dc_microgrid_6_1_sm_circuit_DW
#define D_Work                         DW_dc_microgrid_6_1_sm_circuit_T

/* Parameters (default storage) */
struct P_dc_microgrid_6_1_sm_circuit_T_ {
  real_T Fnom;                         /* Variable: Fnom
                                        * Referenced by: '<S30>/Freq1' (Parameter: Value)
                                        */
  real_T max_min;                      /* Variable: max_min
                                        * Referenced by: '<S30>/Constant1' (Parameter: Value)
                                        */
  real_T Fourier1_Freq;                /* Mask Parameter: Fourier1_Freq
                                        * Referenced by:
                                        *   '<S73>/cos(wt)' (Parameter: Frequency)
                                        *   '<S73>/sin(wt)' (Parameter: Frequency)
                                        */
  real_T Fourier_Freq;                 /* Mask Parameter: Fourier_Freq
                                        * Referenced by:
                                        *   '<S61>/cos(wt)' (Parameter: Frequency)
                                        *   '<S61>/sin(wt)' (Parameter: Frequency)
                                        */
  real_T Fourier1_Freq_g;              /* Mask Parameter: Fourier1_Freq_g
                                        * Referenced by:
                                        *   '<S62>/cos(wt)' (Parameter: Frequency)
                                        *   '<S62>/sin(wt)' (Parameter: Frequency)
                                        */
  real_T Vab3_Freq;                    /* Mask Parameter: Vab3_Freq
                                        * Referenced by:
                                        *   '<S48>/K2' (Parameter: Value)
                                        *   '<S48>/Step' (Parameter: Time)
                                        */
  real_T Vab5_Freq;                    /* Mask Parameter: Vab5_Freq
                                        * Referenced by:
                                        *   '<S50>/K2' (Parameter: Value)
                                        *   '<S50>/Step' (Parameter: Time)
                                        */
  real_T Vab1_Freq;                    /* Mask Parameter: Vab1_Freq
                                        * Referenced by:
                                        *   '<S44>/K2' (Parameter: Value)
                                        *   '<S44>/Step' (Parameter: Time)
                                        */
  real_T Vab2_Freq;                    /* Mask Parameter: Vab2_Freq
                                        * Referenced by:
                                        *   '<S46>/K2' (Parameter: Value)
                                        *   '<S46>/Step' (Parameter: Time)
                                        */
  real_T DiscretePWMGenerator1_Internal;
                               /* Mask Parameter: DiscretePWMGenerator1_Internal
                                * Referenced by: '<S25>/Constant1' (Parameter: Value)
                                */
  real_T Vab3_Mag_Init;                /* Mask Parameter: Vab3_Mag_Init
                                        * Referenced by: '<S48>/Constant' (Parameter: Value)
                                        */
  real_T Vab5_Mag_Init;                /* Mask Parameter: Vab5_Mag_Init
                                        * Referenced by: '<S50>/Constant' (Parameter: Value)
                                        */
  real_T Vab1_Mag_Init;                /* Mask Parameter: Vab1_Mag_Init
                                        * Referenced by: '<S44>/Constant' (Parameter: Value)
                                        */
  real_T Vab2_Mag_Init;                /* Mask Parameter: Vab2_Mag_Init
                                        * Referenced by: '<S46>/Constant' (Parameter: Value)
                                        */
  real_T RMS1_TrueRMS;                 /* Mask Parameter: RMS1_TrueRMS
                                        * Referenced by: '<S18>/Constant' (Parameter: Value)
                                        */
  real_T Triangle_rep_seq_y[4];        /* Mask Parameter: Triangle_rep_seq_y
                                        * Referenced by: '<S27>/Look-Up Table1' (Parameter: Table)
                                        */
  real_T Constant_Value[3];            /* Expression: Internal_Phase
                                        * Referenced by: '<S25>/Constant' (Parameter: Value)
                                        */
  real_T m3_Value;                     /* Expression: Phase
                                        * Referenced by: '<S25>/m3' (Parameter: Value)
                                        */
  real_T Gain2_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S25>/Gain2' (Parameter: Gain)
                                        */
  real_T Gain_Gain;                    /* Expression: 2*pi*Freq
                                        * Referenced by: '<S25>/Gain' (Parameter: Gain)
                                        */
  real_T m4_Value;                     /* Expression: mIndex
                                        * Referenced by: '<S25>/m4' (Parameter: Value)
                                        */
  real_T OP_max1_Value;                /* Expression: 0
                                        * Referenced by: '<S30>/OP_max1' (Parameter: Value)
                                        */
  real_T OP_min1_Value;                /* Expression: 228
                                        * Referenced by: '<S30>/OP_min1' (Parameter: Value)
                                        */
  real_T K2_Value;                     /* Expression: sqrt(3)/2
                                        * Referenced by: '<S29>/K2' (Parameter: Value)
                                        */
  real_T Constant2_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S30>/Constant2' (Parameter: Value)
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S30>/Switch2' (Parameter: Threshold)
                                        */
  real_T DegRad_Gain;                  /* Expression: pi/180
                                        * Referenced by: '<S30>/Deg->Rad' (Parameter: Gain)
                                        */
  real_T Freq2_Value;                  /* Expression: 2*pi
                                        * Referenced by: '<S30>/Freq2' (Parameter: Value)
                                        */
  real_T K1_Value;                     /* Expression: 0.5
                                        * Referenced by: '<S29>/K1' (Parameter: Value)
                                        */
  real_T OP_max1_Value_g;              /* Expression: 1.2
                                        * Referenced by: '<S28>/OP_max1' (Parameter: Value)
                                        */
  real_T OP_min1_Value_g;              /* Expression: 1
                                        * Referenced by: '<S28>/OP_min1' (Parameter: Value)
                                        */
  real_T Gain_Gain_i;                  /* Expression: K1
                                        * Referenced by: '<S44>/Gain' (Parameter: Gain)
                                        */
  real_T Gain1_Gain;                   /* Expression: K2
                                        * Referenced by: '<S44>/Gain1' (Parameter: Gain)
                                        */
  real_T Gain_Gain_h;                  /* Expression: K1
                                        * Referenced by: '<S46>/Gain' (Parameter: Gain)
                                        */
  real_T Gain1_Gain_n;                 /* Expression: K2
                                        * Referenced by: '<S46>/Gain1' (Parameter: Gain)
                                        */
  real_T Gain_Gain_il;                 /* Expression: K1
                                        * Referenced by: '<S48>/Gain' (Parameter: Gain)
                                        */
  real_T Gain1_Gain_c;                 /* Expression: K2
                                        * Referenced by: '<S48>/Gain1' (Parameter: Gain)
                                        */
  real_T Gain_Gain_f;                  /* Expression: K1
                                        * Referenced by: '<S50>/Gain' (Parameter: Gain)
                                        */
  real_T Gain1_Gain_nq;                /* Expression: K2
                                        * Referenced by: '<S50>/Gain1' (Parameter: Gain)
                                        */
  real_T Gain_Gain_o;                  /* Expression: sps.Freq
                                        * Referenced by: '<S65>/Gain' (Parameter: Gain)
                                        */
  real_T Gain_Gain_g;                  /* Expression: sps.Freq
                                        * Referenced by: '<S66>/Gain' (Parameter: Gain)
                                        */
  real_T Gain_Gain_c;                  /* Expression: sps.Freq
                                        * Referenced by: '<S69>/Gain' (Parameter: Gain)
                                        */
  real_T Gain_Gain_cc;                 /* Expression: sps.Freq
                                        * Referenced by: '<S70>/Gain' (Parameter: Gain)
                                        */
  real_T Gain_Gain_m;                  /* Expression: sps.Freq
                                        * Referenced by: '<S76>/Gain' (Parameter: Gain)
                                        */
  real_T Gain_Gain_id;                 /* Expression: sps.Freq
                                        * Referenced by: '<S77>/Gain' (Parameter: Gain)
                                        */
  real_T integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S77>/integrator' (Parameter: InitialCondition)
                                        */
  real_T TransportDelay_Delay;         /* Expression: 1./sps.Freq
                                        * Referenced by: '<S77>/Transport Delay' (Parameter: DelayTime)
                                        */
  real_T TransportDelay_InitOutput;    /* Expression: 0
                                        * Referenced by: '<S77>/Transport Delay' (Parameter: InitialOutput)
                                        */
  real_T K1_Value_m;                   /* Expression: 1./sps.Freq
                                        * Referenced by: '<S77>/K1' (Parameter: Value)
                                        */
  real_T Memory_InitialCondition;      /* Expression: sps.Vinit
                                        * Referenced by: '<S77>/Memory' (Parameter: InitialCondition)
                                        */
  real_T integrator_IC_f;              /* Expression: 0
                                        * Referenced by: '<S76>/integrator' (Parameter: InitialCondition)
                                        */
  real_T TransportDelay_Delay_a;       /* Expression: 1./sps.Freq
                                        * Referenced by: '<S76>/Transport Delay' (Parameter: DelayTime)
                                        */
  real_T TransportDelay_InitOutput_n;  /* Expression: 0
                                        * Referenced by: '<S76>/Transport Delay' (Parameter: InitialOutput)
                                        */
  real_T K1_Value_l;                   /* Expression: 1./sps.Freq
                                        * Referenced by: '<S76>/K1' (Parameter: Value)
                                        */
  real_T Memory_InitialCondition_h;    /* Expression: sps.Vinit
                                        * Referenced by: '<S76>/Memory' (Parameter: InitialCondition)
                                        */
  real_T sinwt_Amp;                    /* Expression: sps.k
                                        * Referenced by: '<S73>/sin(wt)' (Parameter: Amplitude)
                                        */
  real_T sinwt_Bias;                   /* Expression: 0
                                        * Referenced by: '<S73>/sin(wt)' (Parameter: Bias)
                                        */
  real_T sinwt_Phase;                  /* Expression: 0
                                        * Referenced by: '<S73>/sin(wt)' (Parameter: Phase)
                                        */
  real_T coswt_Amp;                    /* Expression: sps.k
                                        * Referenced by: '<S73>/cos(wt)' (Parameter: Amplitude)
                                        */
  real_T coswt_Bias;                   /* Expression: 0
                                        * Referenced by: '<S73>/cos(wt)' (Parameter: Bias)
                                        */
  real_T coswt_Phase;                  /* Expression: pi/2
                                        * Referenced by: '<S73>/cos(wt)' (Parameter: Phase)
                                        */
  real_T RadDeg_Gain;                  /* Expression: 180/pi
                                        * Referenced by: '<S73>/Rad->Deg.' (Parameter: Gain)
                                        */
  real_T Gain_Gain_e;                  /* Expression: 1/sqrt(2)
                                        * Referenced by: '<S71>/Gain' (Parameter: Gain)
                                        */
  real_T Gain_Gain_l;                  /* Expression: sps.Freq
                                        * Referenced by: '<S79>/Gain' (Parameter: Gain)
                                        */
  real_T integrator_IC_d;              /* Expression: 0
                                        * Referenced by: '<S79>/integrator' (Parameter: InitialCondition)
                                        */
  real_T TransportDelay_Delay_f;       /* Expression: 1./sps.Freq
                                        * Referenced by: '<S79>/Transport Delay' (Parameter: DelayTime)
                                        */
  real_T TransportDelay_InitOutput_a;  /* Expression: 0
                                        * Referenced by: '<S79>/Transport Delay' (Parameter: InitialOutput)
                                        */
  real_T K1_Value_p;                   /* Expression: 1./sps.Freq
                                        * Referenced by: '<S79>/K1' (Parameter: Value)
                                        */
  real_T Memory_InitialCondition_o;    /* Expression: sps.Vinit
                                        * Referenced by: '<S79>/Memory' (Parameter: InitialCondition)
                                        */
  real_T Saturationtoavoidnegativesqrt_U;/* Expression: Inf
                                          * Referenced by: '<S72>/Saturation to avoid negative sqrt' (Parameter: UpperLimit)
                                          */
  real_T Saturationtoavoidnegativesqrt_L;/* Expression: 0
                                          * Referenced by: '<S72>/Saturation to avoid negative sqrt' (Parameter: LowerLimit)
                                          */
  real_T SFunction1_Value;             /* Expression: 0
                                        * Referenced by: '<S1>/S-Function1' (Parameter: Value)
                                        */
  real_T SFunction_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S1>/S-Function' (Parameter: InitialCondition)
                                        */
  real_T Constant_Value_g[6];          /* Expression: zeros(1,Switches)
                                        * Referenced by: '<S31>/Constant' (Parameter: Value)
                                        */
  real_T SineWave3_Amp;                /* Expression: 1
                                        * Referenced by: '<S3>/Sine Wave3' (Parameter: Amplitude)
                                        */
  real_T SineWave3_Bias;               /* Expression: 0
                                        * Referenced by: '<S3>/Sine Wave3' (Parameter: Bias)
                                        */
  real_T SineWave3_Freq;               /* Expression: 2*pi*50
                                        * Referenced by: '<S3>/Sine Wave3' (Parameter: Frequency)
                                        */
  real_T SineWave3_Phase;              /* Expression: 0
                                        * Referenced by: '<S3>/Sine Wave3' (Parameter: Phase)
                                        */
  real_T SFunction_P1_Size[2];         /* Computed Parameter: SFunction_P1_Size
                                        * Referenced by: '<S57>/S-Function' (Parameter: P1Size)
                                        */
  real_T SFunction_P1;                 /* Expression: Data_width
                                        * Referenced by: '<S57>/S-Function' (Parameter: P1)
                                        */
  real_T SFunction_P2_Size[2];         /* Computed Parameter: SFunction_P2_Size
                                        * Referenced by: '<S57>/S-Function' (Parameter: P2Size)
                                        */
  real_T SFunction_P2[2];              /* Expression: InitialConditions
                                        * Referenced by: '<S57>/S-Function' (Parameter: P2)
                                        */
  real_T Constant_Value_h;             /* Expression: sqrt(2)
                                        * Referenced by: '<S3>/Constant' (Parameter: Value)
                                        */
  real_T SineWave4_Amp;                /* Expression: 1
                                        * Referenced by: '<S3>/Sine Wave4' (Parameter: Amplitude)
                                        */
  real_T SineWave4_Bias;               /* Expression: 0
                                        * Referenced by: '<S3>/Sine Wave4' (Parameter: Bias)
                                        */
  real_T SineWave4_Freq;               /* Expression: 2*pi*50
                                        * Referenced by: '<S3>/Sine Wave4' (Parameter: Frequency)
                                        */
  real_T SineWave4_Phase;              /* Expression: -2*pi/3
                                        * Referenced by: '<S3>/Sine Wave4' (Parameter: Phase)
                                        */
  real_T SineWave5_Amp;                /* Expression: 1
                                        * Referenced by: '<S3>/Sine Wave5' (Parameter: Amplitude)
                                        */
  real_T SineWave5_Bias;               /* Expression: 0
                                        * Referenced by: '<S3>/Sine Wave5' (Parameter: Bias)
                                        */
  real_T SineWave5_Freq;               /* Expression: 2*pi*50
                                        * Referenced by: '<S3>/Sine Wave5' (Parameter: Frequency)
                                        */
  real_T SineWave5_Phase;              /* Expression: 2*pi/3
                                        * Referenced by: '<S3>/Sine Wave5' (Parameter: Phase)
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 1e9
                                        * Referenced by: '<S3>/Delay1' (Parameter: InitialCondition)
                                        */
  real_T StateSpace_AS_param[36];      /* Expression: S.A
                                        * Referenced by: '<S4>/State-Space' (Parameter: AS_param)
                                        */
  real_T StateSpace_BS_param[60];      /* Expression: S.B
                                        * Referenced by: '<S4>/State-Space' (Parameter: BS_param)
                                        */
  real_T StateSpace_CS_param[120];     /* Expression: S.C
                                        * Referenced by: '<S4>/State-Space' (Parameter: CS_param)
                                        */
  real_T StateSpace_DS_param[200];     /* Expression: S.D
                                        * Referenced by: '<S4>/State-Space' (Parameter: DS_param)
                                        */
  real_T StateSpace_X0_param[6];       /* Expression: S.x0
                                        * Referenced by: '<S4>/State-Space' (Parameter: X0_param)
                                        */
  real_T integrator_IC_l;              /* Expression: 0
                                        * Referenced by: '<S66>/integrator' (Parameter: InitialCondition)
                                        */
  real_T TransportDelay_Delay_l;       /* Expression: 1./sps.Freq
                                        * Referenced by: '<S66>/Transport Delay' (Parameter: DelayTime)
                                        */
  real_T TransportDelay_InitOutput_e;  /* Expression: 0
                                        * Referenced by: '<S66>/Transport Delay' (Parameter: InitialOutput)
                                        */
  real_T K1_Value_f;                   /* Expression: 1./sps.Freq
                                        * Referenced by: '<S66>/K1' (Parameter: Value)
                                        */
  real_T Memory_InitialCondition_f;    /* Expression: sps.Vinit
                                        * Referenced by: '<S66>/Memory' (Parameter: InitialCondition)
                                        */
  real_T integrator_IC_c;              /* Expression: 0
                                        * Referenced by: '<S65>/integrator' (Parameter: InitialCondition)
                                        */
  real_T TransportDelay_Delay_fa;      /* Expression: 1./sps.Freq
                                        * Referenced by: '<S65>/Transport Delay' (Parameter: DelayTime)
                                        */
  real_T TransportDelay_InitOutput_f;  /* Expression: 0
                                        * Referenced by: '<S65>/Transport Delay' (Parameter: InitialOutput)
                                        */
  real_T K1_Value_h;                   /* Expression: 1./sps.Freq
                                        * Referenced by: '<S65>/K1' (Parameter: Value)
                                        */
  real_T Memory_InitialCondition_c;    /* Expression: sps.Vinit
                                        * Referenced by: '<S65>/Memory' (Parameter: InitialCondition)
                                        */
  real_T integrator_IC_cp;             /* Expression: 0
                                        * Referenced by: '<S70>/integrator' (Parameter: InitialCondition)
                                        */
  real_T TransportDelay_Delay_d;       /* Expression: 1./sps.Freq
                                        * Referenced by: '<S70>/Transport Delay' (Parameter: DelayTime)
                                        */
  real_T TransportDelay_InitOutput_d;  /* Expression: 0
                                        * Referenced by: '<S70>/Transport Delay' (Parameter: InitialOutput)
                                        */
  real_T K1_Value_pv;                  /* Expression: 1./sps.Freq
                                        * Referenced by: '<S70>/K1' (Parameter: Value)
                                        */
  real_T Memory_InitialCondition_b;    /* Expression: sps.Vinit
                                        * Referenced by: '<S70>/Memory' (Parameter: InitialCondition)
                                        */
  real_T integrator_IC_j;              /* Expression: 0
                                        * Referenced by: '<S69>/integrator' (Parameter: InitialCondition)
                                        */
  real_T TransportDelay_Delay_n;       /* Expression: 1./sps.Freq
                                        * Referenced by: '<S69>/Transport Delay' (Parameter: DelayTime)
                                        */
  real_T TransportDelay_InitOutput_fm; /* Expression: 0
                                        * Referenced by: '<S69>/Transport Delay' (Parameter: InitialOutput)
                                        */
  real_T K1_Value_f3;                  /* Expression: 1./sps.Freq
                                        * Referenced by: '<S69>/K1' (Parameter: Value)
                                        */
  real_T Memory_InitialCondition_l;    /* Expression: sps.Vinit
                                        * Referenced by: '<S69>/Memory' (Parameter: InitialCondition)
                                        */
  real_T Gain1_Gain_nh;                /* Expression: 1/2
                                        * Referenced by: '<S17>/Gain1' (Parameter: Gain)
                                        */
  real_T RadDeg_Gain_i;                /* Expression: 180/pi
                                        * Referenced by: '<S61>/Rad->Deg.' (Parameter: Gain)
                                        */
  real_T RadDeg_Gain_f;                /* Expression: 180/pi
                                        * Referenced by: '<S62>/Rad->Deg.' (Parameter: Gain)
                                        */
  real_T DegRad_Gain_g;                /* Expression: pi/180
                                        * Referenced by: '<S17>/Deg->Rad' (Parameter: Gain)
                                        */
  real_T donotdeletethisgain_Gain;     /* Expression: 1
                                        * Referenced by: '<S83>/do not delete this gain' (Parameter: Gain)
                                        */
  real_T donotdeletethisgain_Gain_n;   /* Expression: 1
                                        * Referenced by: '<S84>/do not delete this gain' (Parameter: Gain)
                                        */
  real_T donotdeletethisgain_Gain_i;   /* Expression: 1
                                        * Referenced by: '<S85>/do not delete this gain' (Parameter: Gain)
                                        */
  real_T Kv_Gain;                      /* Expression: Ki
                                        * Referenced by: '<S19>/Kv' (Parameter: Gain)
                                        */
  real_T SFunction_P1_Size_h[2];      /* Computed Parameter: SFunction_P1_Size_h
                                       * Referenced by: '<S97>/S-Function' (Parameter: P1Size)
                                       */
  real_T SFunction_P1_g;               /* Expression: Acqu_group
                                        * Referenced by: '<S97>/S-Function' (Parameter: P1)
                                        */
  real_T donotdeletethisgain_Gain_d;   /* Expression: 1
                                        * Referenced by: '<S86>/do not delete this gain' (Parameter: Gain)
                                        */
  real_T donotdeletethisgain_Gain_dt;  /* Expression: 1
                                        * Referenced by: '<S87>/do not delete this gain' (Parameter: Gain)
                                        */
  real_T donotdeletethisgain_Gain_h;   /* Expression: 1
                                        * Referenced by: '<S88>/do not delete this gain' (Parameter: Gain)
                                        */
  real_T Kv1_Gain;                     /* Expression: Kv
                                        * Referenced by: '<S19>/Kv1' (Parameter: Gain)
                                        */
  real_T sinwt_Amp_h;                  /* Expression: sps.k
                                        * Referenced by: '<S61>/sin(wt)' (Parameter: Amplitude)
                                        */
  real_T sinwt_Bias_b;                 /* Expression: 0
                                        * Referenced by: '<S61>/sin(wt)' (Parameter: Bias)
                                        */
  real_T sinwt_Phase_i;                /* Expression: 0
                                        * Referenced by: '<S61>/sin(wt)' (Parameter: Phase)
                                        */
  real_T coswt_Amp_f;                  /* Expression: sps.k
                                        * Referenced by: '<S61>/cos(wt)' (Parameter: Amplitude)
                                        */
  real_T coswt_Bias_a;                 /* Expression: 0
                                        * Referenced by: '<S61>/cos(wt)' (Parameter: Bias)
                                        */
  real_T coswt_Phase_o;                /* Expression: pi/2
                                        * Referenced by: '<S61>/cos(wt)' (Parameter: Phase)
                                        */
  real_T sinwt_Amp_f;                  /* Expression: sps.k
                                        * Referenced by: '<S62>/sin(wt)' (Parameter: Amplitude)
                                        */
  real_T sinwt_Bias_c;                 /* Expression: 0
                                        * Referenced by: '<S62>/sin(wt)' (Parameter: Bias)
                                        */
  real_T sinwt_Phase_h;                /* Expression: 0
                                        * Referenced by: '<S62>/sin(wt)' (Parameter: Phase)
                                        */
  real_T coswt_Amp_j;                  /* Expression: sps.k
                                        * Referenced by: '<S62>/cos(wt)' (Parameter: Amplitude)
                                        */
  real_T coswt_Bias_j;                 /* Expression: 0
                                        * Referenced by: '<S62>/cos(wt)' (Parameter: Bias)
                                        */
  real_T coswt_Phase_h;                /* Expression: pi/2
                                        * Referenced by: '<S62>/cos(wt)' (Parameter: Phase)
                                        */
  real_T donotdeletethisgain_Gain_c;   /* Expression: 1
                                        * Referenced by: '<S20>/do not delete this gain' (Parameter: Gain)
                                        */
  real_T donotdeletethisgain_Gain_o;   /* Expression: 1
                                        * Referenced by: '<S13>/do not delete this gain' (Parameter: Gain)
                                        */
  real_T UnitDelay4_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S23>/Unit Delay4' (Parameter: InitialCondition)
                                        */
  real_T donotdeletethisgain_Gain_ox;  /* Expression: 1
                                        * Referenced by: '<S33>/do not delete this gain' (Parameter: Gain)
                                        */
  real_T donotdeletethisgain_Gain_m;   /* Expression: 1
                                        * Referenced by: '<S38>/do not delete this gain' (Parameter: Gain)
                                        */
  real_T donotdeletethisgain_Gain_mc;  /* Expression: 1
                                        * Referenced by: '<S39>/do not delete this gain' (Parameter: Gain)
                                        */
  real_T Integ4_gainval;               /* Computed Parameter: Integ4_gainval
                                        * Referenced by: '<S48>/Integ4' (Parameter: gainval)
                                        */
  real_T Integ4_IC;                    /* Expression: 0
                                        * Referenced by: '<S48>/Integ4' (Parameter: InitialCondition)
                                        */
  real_T K1_Value_e;                   /* Expression: Delay
                                        * Referenced by: '<S48>/K1' (Parameter: Value)
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S48>/Unit Delay' (Parameter: InitialCondition)
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S48>/Step' (Parameter: Before)
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<S48>/Step' (Parameter: After)
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S48>/Switch' (Parameter: Threshold)
                                        */
  real_T SaturationAjoutPBpourevitersqrt;/* Expression: Inf
                                          * Referenced by: '<S36>/Saturation Ajout P.B pour eviter  sqrt(negatif)' (Parameter: UpperLimit)
                                          */
  real_T SaturationAjoutPBpourevitersq_o;/* Expression: 0
                                          * Referenced by: '<S36>/Saturation Ajout P.B pour eviter  sqrt(negatif)' (Parameter: LowerLimit)
                                          */
  real_T donotdeletethisgain_Gain_ne;  /* Expression: 1
                                        * Referenced by: '<S40>/do not delete this gain' (Parameter: Gain)
                                        */
  real_T donotdeletethisgain_Gain_e;   /* Expression: 1
                                        * Referenced by: '<S41>/do not delete this gain' (Parameter: Gain)
                                        */
  real_T donotdeletethisgain_Gain_cw;  /* Expression: 1
                                        * Referenced by: '<S42>/do not delete this gain' (Parameter: Gain)
                                        */
  real_T Integ4_gainval_b;             /* Computed Parameter: Integ4_gainval_b
                                        * Referenced by: '<S50>/Integ4' (Parameter: gainval)
                                        */
  real_T Integ4_IC_f;                  /* Expression: 0
                                        * Referenced by: '<S50>/Integ4' (Parameter: InitialCondition)
                                        */
  real_T K1_Value_hd;                  /* Expression: Delay
                                        * Referenced by: '<S50>/K1' (Parameter: Value)
                                        */
  real_T UnitDelay_InitialCondition_i; /* Expression: 0
                                        * Referenced by: '<S50>/Unit Delay' (Parameter: InitialCondition)
                                        */
  real_T Step_Y0_i;                    /* Expression: 0
                                        * Referenced by: '<S50>/Step' (Parameter: Before)
                                        */
  real_T Step_YFinal_m;                /* Expression: 1
                                        * Referenced by: '<S50>/Step' (Parameter: After)
                                        */
  real_T Switch_Threshold_k;           /* Expression: 0.5
                                        * Referenced by: '<S50>/Switch' (Parameter: Threshold)
                                        */
  real_T SaturationAjoutPBpourevitersq_d;/* Expression: Inf
                                          * Referenced by: '<S37>/Saturation Ajout P.B pour eviter  sqrt(negatif)' (Parameter: UpperLimit)
                                          */
  real_T SaturationAjoutPBpourevitersq_h;/* Expression: 0
                                          * Referenced by: '<S37>/Saturation Ajout P.B pour eviter  sqrt(negatif)' (Parameter: LowerLimit)
                                          */
  real_T Integ4_gainval_b4;            /* Computed Parameter: Integ4_gainval_b4
                                        * Referenced by: '<S44>/Integ4' (Parameter: gainval)
                                        */
  real_T Integ4_IC_d;                  /* Expression: 0
                                        * Referenced by: '<S44>/Integ4' (Parameter: InitialCondition)
                                        */
  real_T K1_Value_e2;                  /* Expression: Delay
                                        * Referenced by: '<S44>/K1' (Parameter: Value)
                                        */
  real_T UnitDelay_InitialCondition_m; /* Expression: 0
                                        * Referenced by: '<S44>/Unit Delay' (Parameter: InitialCondition)
                                        */
  real_T Step_Y0_n;                    /* Expression: 0
                                        * Referenced by: '<S44>/Step' (Parameter: Before)
                                        */
  real_T Step_YFinal_c;                /* Expression: 1
                                        * Referenced by: '<S44>/Step' (Parameter: After)
                                        */
  real_T Switch_Threshold_f;           /* Expression: 0.5
                                        * Referenced by: '<S44>/Switch' (Parameter: Threshold)
                                        */
  real_T SaturationAjoutPBpourevitersq_f;/* Expression: Inf
                                          * Referenced by: '<S34>/Saturation Ajout P.B pour eviter  sqrt(negatif)' (Parameter: UpperLimit)
                                          */
  real_T SaturationAjoutPBpourevitersq_m;/* Expression: 0
                                          * Referenced by: '<S34>/Saturation Ajout P.B pour eviter  sqrt(negatif)' (Parameter: LowerLimit)
                                          */
  real_T Integ4_gainval_n;             /* Computed Parameter: Integ4_gainval_n
                                        * Referenced by: '<S46>/Integ4' (Parameter: gainval)
                                        */
  real_T Integ4_IC_a;                  /* Expression: 0
                                        * Referenced by: '<S46>/Integ4' (Parameter: InitialCondition)
                                        */
  real_T K1_Value_a;                   /* Expression: Delay
                                        * Referenced by: '<S46>/K1' (Parameter: Value)
                                        */
  real_T UnitDelay_InitialCondition_a; /* Expression: 0
                                        * Referenced by: '<S46>/Unit Delay' (Parameter: InitialCondition)
                                        */
  real_T Step_Y0_iz;                   /* Expression: 0
                                        * Referenced by: '<S46>/Step' (Parameter: Before)
                                        */
  real_T Step_YFinal_cj;               /* Expression: 1
                                        * Referenced by: '<S46>/Step' (Parameter: After)
                                        */
  real_T Switch_Threshold_n;           /* Expression: 0.5
                                        * Referenced by: '<S46>/Switch' (Parameter: Threshold)
                                        */
  real_T SaturationAjoutPBpoureviters_oi;/* Expression: Inf
                                          * Referenced by: '<S35>/Saturation Ajout P.B pour eviter  sqrt(negatif)' (Parameter: UpperLimit)
                                          */
  real_T SaturationAjoutPBpourevitersq_c;/* Expression: 0
                                          * Referenced by: '<S35>/Saturation Ajout P.B pour eviter  sqrt(negatif)' (Parameter: LowerLimit)
                                          */
  real_T uformaxload0formin_Value;     /* Expression: 1
                                        * Referenced by: '<S28>/1 for max load, 0 for min' (Parameter: Value)
                                        */
  real_T Switch2_Threshold_b;          /* Expression: 0
                                        * Referenced by: '<S28>/Switch2' (Parameter: Threshold)
                                        */
  real_T Switch_Threshold_a;           /* Expression: 0
                                        * Referenced by: '<S25>/Switch' (Parameter: Threshold)
                                        */
  real_T Constant_Value_gx;            /* Expression: period
                                        * Referenced by: '<S27>/Constant' (Parameter: Value)
                                        */
  real_T LookUpTable1_bp01Data[4];     /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S27>/Look-Up Table1' (Parameter: BreakpointsForDimension1)
                                        */
  real_T Gain3_Gain;                   /* Expression: -1
                                        * Referenced by: '<S25>/Gain3' (Parameter: Gain)
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_dc_microgrid_6_1_sm_circuit_T {
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
      real_T const *UPtrs0[2];
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
    real_T odeY[15];
    real_T odeF[3][15];
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
extern P_dc_microgrid_6_1_sm_circuit_T dc_microgrid_6_1_sm_circuit_P;

/* Block signals (default storage) */
extern B_dc_microgrid_6_1_sm_circuit_T dc_microgrid_6_1_sm_circuit_B;

/* Continuous states (default storage) */
extern X_dc_microgrid_6_1_sm_circuit_T dc_microgrid_6_1_sm_circuit_X;

/* Block states (default storage) */
extern DW_dc_microgrid_6_1_sm_circuit_T dc_microgrid_6_1_sm_circuit_DW;

/* Model entry point functions */
extern void dc_microgrid_6_1_sm_circuit_initialize(void);
extern void dc_microgrid_6_1_sm_circuit_output(void);
extern void dc_microgrid_6_1_sm_circuit_update(void);
extern void dc_microgrid_6_1_sm_circuit_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern dc_microgrid_6_1_sm_circuit_rtModel *dc_microgrid_6_1_sm_circuit(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_dc_microgrid_6_1_sm_circuit_T *const
  dc_microgrid_6_1_sm_circuit_M;

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
 * '<Root>' : 'dc_microgrid_6_1_sm_circuit'
 * '<S1>'   : 'dc_microgrid_6_1_sm_circuit/OpCCode_do_not_touch'
 * '<S2>'   : 'dc_microgrid_6_1_sm_circuit/powergui'
 * '<S3>'   : 'dc_microgrid_6_1_sm_circuit/sm_circuit'
 * '<S4>'   : 'dc_microgrid_6_1_sm_circuit/powergui/EquivalentModel1'
 * '<S5>'   : 'dc_microgrid_6_1_sm_circuit/powergui/EquivalentModel1/Gates'
 * '<S6>'   : 'dc_microgrid_6_1_sm_circuit/powergui/EquivalentModel1/Sources'
 * '<S7>'   : 'dc_microgrid_6_1_sm_circuit/powergui/EquivalentModel1/Status'
 * '<S8>'   : 'dc_microgrid_6_1_sm_circuit/powergui/EquivalentModel1/Yout'
 * '<S9>'   : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Controlled Current Source2'
 * '<S10>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Controlled Voltage Source1'
 * '<S11>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Controlled Voltage Source2'
 * '<S12>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Controlled Voltage Source4'
 * '<S13>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Current Measurement7'
 * '<S14>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Grid Bi-directional Converter 1.1   300 (DC)  150 V (AC) P_nom 3kW1'
 * '<S15>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Inv. control measurement'
 * '<S16>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/OpComm'
 * '<S17>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Power1'
 * '<S18>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/RMS1'
 * '<S19>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Three-Phase V-I Measurement1'
 * '<S20>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Voltage Measurement2'
 * '<S21>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/rtlab_send_subsystem'
 * '<S22>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Current Measurement7/Model'
 * '<S23>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Grid Bi-directional Converter 1.1   300 (DC)  150 V (AC) P_nom 3kW1/Control of  Inverter'
 * '<S24>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Grid Bi-directional Converter 1.1   300 (DC)  150 V (AC) P_nom 3kW1/Universal Bridge1'
 * '<S25>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Grid Bi-directional Converter 1.1   300 (DC)  150 V (AC) P_nom 3kW1/Control of  Inverter/Discrete PWM Generator1'
 * '<S26>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Grid Bi-directional Converter 1.1   300 (DC)  150 V (AC) P_nom 3kW1/Control of  Inverter/MI Controller'
 * '<S27>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Grid Bi-directional Converter 1.1   300 (DC)  150 V (AC) P_nom 3kW1/Control of  Inverter/Discrete PWM Generator1/Triangle'
 * '<S28>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Grid Bi-directional Converter 1.1   300 (DC)  150 V (AC) P_nom 3kW1/Control of  Inverter/MI Controller/OP max // min'
 * '<S29>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Grid Bi-directional Converter 1.1   300 (DC)  150 V (AC) P_nom 3kW1/Control of  Inverter/MI Controller/Subsystem'
 * '<S30>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Grid Bi-directional Converter 1.1   300 (DC)  150 V (AC) P_nom 3kW1/Control of  Inverter/MI Controller/Subsystem1'
 * '<S31>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Grid Bi-directional Converter 1.1   300 (DC)  150 V (AC) P_nom 3kW1/Universal Bridge1/Model'
 * '<S32>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Inv. control measurement/measurement'
 * '<S33>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Inv. control measurement/measurement/Vab'
 * '<S34>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Inv. control measurement/measurement/Vab1'
 * '<S35>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Inv. control measurement/measurement/Vab2'
 * '<S36>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Inv. control measurement/measurement/Vab3'
 * '<S37>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Inv. control measurement/measurement/Vab5'
 * '<S38>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Inv. control measurement/measurement/Vbc'
 * '<S39>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Inv. control measurement/measurement/Vca'
 * '<S40>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Inv. control measurement/measurement/a'
 * '<S41>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Inv. control measurement/measurement/b'
 * '<S42>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Inv. control measurement/measurement/c'
 * '<S43>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Inv. control measurement/measurement/Vab/Model'
 * '<S44>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Inv. control measurement/measurement/Vab1/Discrete  Mean value'
 * '<S45>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Inv. control measurement/measurement/Vab1/Discrete  Mean value/Discrete Variable Transport Delay'
 * '<S46>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Inv. control measurement/measurement/Vab2/Discrete  Mean value'
 * '<S47>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Inv. control measurement/measurement/Vab2/Discrete  Mean value/Discrete Variable Transport Delay'
 * '<S48>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Inv. control measurement/measurement/Vab3/Discrete  Mean value'
 * '<S49>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Inv. control measurement/measurement/Vab3/Discrete  Mean value/Discrete Variable Transport Delay'
 * '<S50>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Inv. control measurement/measurement/Vab5/Discrete  Mean value'
 * '<S51>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Inv. control measurement/measurement/Vab5/Discrete  Mean value/Discrete Variable Transport Delay'
 * '<S52>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Inv. control measurement/measurement/Vbc/Model'
 * '<S53>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Inv. control measurement/measurement/Vca/Model'
 * '<S54>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Inv. control measurement/measurement/a/Model'
 * '<S55>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Inv. control measurement/measurement/b/Model'
 * '<S56>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Inv. control measurement/measurement/c/Model'
 * '<S57>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/OpComm/Receive'
 * '<S58>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/OpComm/busStruct'
 * '<S59>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/OpComm/busStruct/Sub1'
 * '<S60>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/OpComm/busStruct/Sub2'
 * '<S61>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Power1/Fourier'
 * '<S62>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Power1/Fourier1'
 * '<S63>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Power1/Fourier/Mean'
 * '<S64>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Power1/Fourier/Mean value1'
 * '<S65>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Power1/Fourier/Mean/Model'
 * '<S66>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Power1/Fourier/Mean value1/Model'
 * '<S67>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Power1/Fourier1/Mean'
 * '<S68>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Power1/Fourier1/Mean value1'
 * '<S69>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Power1/Fourier1/Mean/Model'
 * '<S70>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Power1/Fourier1/Mean value1/Model'
 * '<S71>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/RMS1/RMS '
 * '<S72>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/RMS1/TrueRMS '
 * '<S73>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/RMS1/RMS /Fourier1'
 * '<S74>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/RMS1/RMS /Fourier1/Mean'
 * '<S75>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/RMS1/RMS /Fourier1/Mean value1'
 * '<S76>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/RMS1/RMS /Fourier1/Mean/Model'
 * '<S77>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/RMS1/RMS /Fourier1/Mean value1/Model'
 * '<S78>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/RMS1/TrueRMS /Mean value'
 * '<S79>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/RMS1/TrueRMS /Mean value/Model'
 * '<S80>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Three-Phase V-I Measurement1/Mode I'
 * '<S81>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Three-Phase V-I Measurement1/Mode V'
 * '<S82>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Three-Phase V-I Measurement1/Model'
 * '<S83>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Three-Phase V-I Measurement1/Model/I A:'
 * '<S84>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Three-Phase V-I Measurement1/Model/I B:'
 * '<S85>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Three-Phase V-I Measurement1/Model/I C:'
 * '<S86>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Three-Phase V-I Measurement1/Model/U A:'
 * '<S87>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Three-Phase V-I Measurement1/Model/U B:'
 * '<S88>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Three-Phase V-I Measurement1/Model/U C:'
 * '<S89>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Three-Phase V-I Measurement1/Model/I A:/Model'
 * '<S90>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Three-Phase V-I Measurement1/Model/I B:/Model'
 * '<S91>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Three-Phase V-I Measurement1/Model/I C:/Model'
 * '<S92>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Three-Phase V-I Measurement1/Model/U A:/Model'
 * '<S93>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Three-Phase V-I Measurement1/Model/U B:/Model'
 * '<S94>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Three-Phase V-I Measurement1/Model/U C:/Model'
 * '<S95>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/Voltage Measurement2/Model'
 * '<S96>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/rtlab_send_subsystem/Subsystem1'
 * '<S97>'  : 'dc_microgrid_6_1_sm_circuit/sm_circuit/rtlab_send_subsystem/Subsystem1/Send1'
 */
#endif                           /* RTW_HEADER_dc_microgrid_6_1_sm_circuit_h_ */
