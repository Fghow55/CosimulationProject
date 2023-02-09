/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'ac_der_basic_model_1_sm_circuit/sm_circuit/Solver Configuration'.
 */

#include "ne_std.h"
#include "pm_default_allocator.h"
#include "ne_dae_fwd.h"
#include "ne_profiler_fwd.h"
#include "ne_dae_construct.h"
#include "nesl_la.h"
#include "ac_der_basic_model_1_sm_circuit_a2b15696_1.h"
#include "ac_der_basic_model_1_sm_circuit_a2b15696_1_ds.h"

void ac_der_basic_model_1_sm_circuit_a2b15696_1_dae( NeDae **dae, const
  NeModelParameters *modelParams,
  const NeSolverParameters *solverParams)
{
  PmAllocator *ne_allocator;
  const McLinearAlgebraFactory *linear_algebra_ptr =
    (solverParams->mLinearAlgebra == NE_FULL_LA) ?
    get_rtw_linear_algebra() :
    ((solverParams->mLinearAlgebra == NE_SPARSE_LA) ?
     mc_get_csparse_linear_algebra() :
     get_auto_linear_algebra());
  NeRtpValues *rtpValues = NULL;
  ne_allocator = pm_default_allocator();
  ne_dae_create( dae,
                ac_der_basic_model_1_sm_circuit_a2b15696_1_dae_ds( ne_allocator ),
                NULL,
                FALSE,
                rtpValues,
                *solverParams,
                *modelParams,
                linear_algebra_ptr,
                NULL,
                NULL,
                NULL,
                ne_allocator,
                DAEMON_CHOICE_NONE);
}
