/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'ssc_bridge_rectifier_1_sm_circuit/sm_circuit/Solver Configuration'.
 */

#include "ne_ds.h"
#include "ssc_bridge_rectifier_1_sm_circuit_a2b15696_1_ds_sys_struct.h"
#include "ssc_bridge_rectifier_1_sm_circuit_a2b15696_1_ds_dxf.h"
#include "ssc_bridge_rectifier_1_sm_circuit_a2b15696_1_ds.h"
#include "ssc_bridge_rectifier_1_sm_circuit_a2b15696_1_ds_externals.h"
#include "ssc_bridge_rectifier_1_sm_circuit_a2b15696_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T ssc_bridge_rectifier_1_sm_circuit_a2b15696_1_ds_dxf(const
  NeDynamicSystem *sys, const NeDynamicSystemInput *t16, NeDsMethodOutput *t17)
{
  PmRealVector out;
  real_T t8[14];
  real_T t10[4];
  real_T t0;
  real_T t1;
  real_T t2;
  real_T t3;
  real_T t4;
  real_T t5;
  real_T t6;
  real_T t7;
  size_t t15;
  int32_T M_idx_0;
  int32_T M_idx_1;
  int32_T M_idx_2;
  int32_T M_idx_3;
  M_idx_0 = t16->mM.mX[0];
  M_idx_1 = t16->mM.mX[1];
  M_idx_2 = t16->mM.mX[2];
  M_idx_3 = t16->mM.mX[3];
  out = t17->mDXF;
  if (M_idx_2 != 0) {
    t0 = 3.3433333333333333;
  } else {
    t0 = 0.01000001;
  }

  if (M_idx_3 != 0) {
    t1 = 3.3333333333333335;
  } else {
    t1 = 1.0E-8;
  }

  if (M_idx_0 != 0) {
    t2 = 3.3333333333333335;
  } else {
    t2 = 1.0E-8;
  }

  if (M_idx_1 != 0) {
    t3 = 3.3333333333333335;
  } else {
    t3 = 1.0E-8;
  }

  if (M_idx_2 != 0) {
    t4 = -3.3333333333333335;
  } else {
    t4 = -1.0E-8;
  }

  if (M_idx_3 != 0) {
    t5 = -3.3333333333333335;
  } else {
    t5 = -1.0E-8;
  }

  if (M_idx_2 != 0) {
    t6 = 1.0000033433333333;
  } else {
    t6 = 1.00000001000001;
  }

  if (M_idx_3 != 0) {
    t7 = 3.3333333333333333E-6;
  } else {
    t7 = 1.0E-14;
  }

  t10[0ULL] = t2;
  t10[1ULL] = t3;
  t10[2ULL] = t4;
  t10[3ULL] = t5;
  t8[0ULL] = 0.01;
  t8[1ULL] = t0;
  t8[2ULL] = t1;
  for (t15 = 0ULL; t15 < 4ULL; t15++) {
    t8[t15 + 3ULL] = t10[t15];
  }

  out.mX[0] = t8[0];
  out.mX[1] = t8[1];
  out.mX[2] = t8[2];
  out.mX[3] = t8[3];
  out.mX[4] = t8[4];
  out.mX[5] = t8[5];
  out.mX[6] = t8[6];
  out.mX[7] = 1.00000001;
  out.mX[8] = t6;
  out.mX[9] = t7;
  out.mX[10] = -1.0;
  out.mX[11] = 1.0;
  out.mX[12] = -1.0;
  out.mX[13] = 1.0;
  (void)sys;
  (void)t17;
  return 0;
}
