/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'ac_der_basic_model_1_sm_circuit/sm_circuit/Solver Configuration'.
 */

#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

#include "nesl_rtw.h"
#include "ac_der_basic_model_1_sm_circuit_a2b15696_1.h"
#include "ac_der_basic_model_1_sm_circuit_a2b15696_1_gateway.h"

void ac_der_basic_model_1_sm_circuit_a2b15696_1_gateway(void)
{
  NeModelParameters modelparams = { (NeSolverType) 1, 0.001, 0, 0, 0.0001, 0, 0,
    0, 0, (SscLoggingSetting) 0, 595424411, 0, };

  NeSolverParameters solverparams = { 0, 0, 1, 0, 0, 0.001, 1e-06, 1e-09, 0, 0,
    100, 0, 1, 0, 1e-09, 0, (NeLocalSolverChoice) 0, 0.001, 0, 12, 2, 0, 2,
    (NeLinearAlgebraChoice) 1, (NeEquationFormulationChoice) 0, 1024, 1, 0.001,
    (NePartitionStorageMethod) 0, 1024, (NePartitionMethod) 1, };

  const NeOutputParameters* outputparameters = NULL;
  NeDae* dae;
  size_t numOutputs = 0;
  int rtpDaes[1] = { 0 };

  int* rtwLogDaes = NULL;

  {
    static const NeOutputParameters outputparameters_init[] = { { 0, 0, }, };

    outputparameters = outputparameters_init;
    numOutputs = sizeof(outputparameters_init)/sizeof(outputparameters_init[0]);
  }

  ac_der_basic_model_1_sm_circuit_a2b15696_1_dae(&dae,
    &modelparams,
    &solverparams);
  nesl_register_simulator_group(
    "ac_der_basic_model_1_sm_circuit/sm_circuit/Solver Configuration_1",
    1,
    &dae,
    &solverparams,
    &modelparams,
    numOutputs,
    outputparameters,
    1,
    rtpDaes,
    0,
    rtwLogDaes);
}
