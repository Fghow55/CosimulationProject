/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'ssc_bridge_rectifier_1_sm_circuit/sm_circuit/Solver Configuration'.
 */

#include "ne_ds.h"
#include "ssc_bridge_rectifier_1_sm_circuit_a2b15696_1_ds_sys_struct.h"
#include "ssc_bridge_rectifier_1_sm_circuit_a2b15696_1_ds_f.h"
#include "ssc_bridge_rectifier_1_sm_circuit_a2b15696_1_ds.h"
#include "ssc_bridge_rectifier_1_sm_circuit_a2b15696_1_ds_externals.h"
#include "ssc_bridge_rectifier_1_sm_circuit_a2b15696_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T ssc_bridge_rectifier_1_sm_circuit_a2b15696_1_ds_f(const NeDynamicSystem *
  sys, const NeDynamicSystemInput *t8, NeDsMethodOutput *t9)
{
  PmRealVector out;
  real_T U_idx_0;
  real_T X_idx_0;
  real_T X_idx_1;
  real_T X_idx_2;
  real_T X_idx_3;
  real_T X_idx_4;
  real_T sm_circuit_Diode_4_v;
  real_T t1;
  real_T t3;
  real_T t7;
  int32_T M_idx_0;
  int32_T M_idx_1;
  int32_T M_idx_2;
  int32_T M_idx_3;
  M_idx_0 = t8->mM.mX[0];
  M_idx_1 = t8->mM.mX[1];
  M_idx_2 = t8->mM.mX[2];
  M_idx_3 = t8->mM.mX[3];
  U_idx_0 = t8->mU.mX[0];
  X_idx_0 = t8->mX.mX[0];
  X_idx_1 = t8->mX.mX[1];
  X_idx_2 = t8->mX.mX[2];
  X_idx_3 = t8->mX.mX[3];
  X_idx_4 = t8->mX.mX[4];
  out = t9->mF;
  t1 = -X_idx_1 + U_idx_0 * 0.071428571428571425;
  t3 = ((-X_idx_0 + X_idx_2 * -1.0E-6) + U_idx_0 * -0.071428571428571425) +
    X_idx_1;
  sm_circuit_Diode_4_v = (-X_idx_0 + X_idx_2 * -1.0E-6) + X_idx_1;
  t7 = (X_idx_0 * 0.01 + X_idx_2 * 1.00000001) + -X_idx_3;
  U_idx_0 = (X_idx_0 * 0.01 + X_idx_2 * 1.00000001) + -X_idx_4;
  if (M_idx_0 != 0) {
    X_idx_0 = t7 - (t1 - 0.59999999819999994) / 0.3;
  } else {
    X_idx_0 = t7 - t1 * 1.0E-8;
  }

  if (M_idx_1 != 0) {
    t1 = X_idx_3 - (-X_idx_1 - 0.59999999819999994) / 0.3;
  } else {
    t1 = X_idx_3 - -X_idx_1 * 1.0E-8;
  }

  if (M_idx_2 != 0) {
    U_idx_0 -= (t3 - 0.59999999819999994) / 0.3;
  } else {
    U_idx_0 -= t3 * 1.0E-8;
  }

  if (M_idx_3 != 0) {
    t3 = X_idx_4 - (sm_circuit_Diode_4_v - 0.59999999819999994) / 0.3;
  } else {
    t3 = X_idx_4 - sm_circuit_Diode_4_v * 1.0E-8;
  }

  out.mX[0] = -0.0;
  out.mX[1] = X_idx_0;
  out.mX[2] = t1;
  out.mX[3] = U_idx_0;
  out.mX[4] = t3;
  (void)sys;
  (void)t9;
  return 0;
}
