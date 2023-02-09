/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'ssc_bridge_rectifier_1_sm_circuit/sm_circuit/Solver Configuration'.
 */

#include "ne_ds.h"
#include "ssc_bridge_rectifier_1_sm_circuit_a2b15696_1_ds_sys_struct.h"
#include "ssc_bridge_rectifier_1_sm_circuit_a2b15696_1_ds_log.h"
#include "ssc_bridge_rectifier_1_sm_circuit_a2b15696_1_ds.h"
#include "ssc_bridge_rectifier_1_sm_circuit_a2b15696_1_ds_externals.h"
#include "ssc_bridge_rectifier_1_sm_circuit_a2b15696_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T ssc_bridge_rectifier_1_sm_circuit_a2b15696_1_ds_log(const
  NeDynamicSystem *sys, const NeDynamicSystemInput *t2, NeDsMethodOutput *t3)
{
  PmRealVector out;
  real_T U_idx_0;
  real_T X_idx_0;
  real_T X_idx_1;
  real_T X_idx_2;
  real_T X_idx_3;
  real_T X_idx_4;
  real_T sm_circuit_Diode_1_i;
  real_T sm_circuit_Diode_1_p_v;
  real_T sm_circuit_Diode_1_v;
  real_T sm_circuit_Diode_3_i;
  real_T sm_circuit_Diode_3_v;
  real_T sm_circuit_Diode_4_v;
  real_T sm_circuit_Ideal_Transformer_i1;
  real_T sm_circuit_Load_i;
  real_T t1;
  U_idx_0 = t2->mU.mX[0];
  X_idx_0 = t2->mX.mX[0];
  X_idx_1 = t2->mX.mX[1];
  X_idx_2 = t2->mX.mX[2];
  X_idx_3 = t2->mX.mX[3];
  X_idx_4 = t2->mX.mX[4];
  out = t3->mLOG;
  sm_circuit_Diode_1_v = -X_idx_1 + U_idx_0 * 0.071428571428571425;
  sm_circuit_Diode_3_v = ((-X_idx_0 + X_idx_2 * -1.0E-6) + U_idx_0 *
    -0.071428571428571425) + X_idx_1;
  sm_circuit_Diode_4_v = (-X_idx_0 + X_idx_2 * -1.0E-6) + X_idx_1;
  sm_circuit_Diode_1_i = (X_idx_0 * 0.01 + X_idx_2 * 1.00000001) + -X_idx_3;
  sm_circuit_Diode_1_p_v = U_idx_0 * 0.071428571428571425;
  sm_circuit_Diode_3_i = (X_idx_0 * 0.01 + X_idx_2 * 1.00000001) + -X_idx_4;
  sm_circuit_Ideal_Transformer_i1 = X_idx_3 * -0.071428571428571425 + X_idx_4 *
    0.071428571428571425;
  sm_circuit_Load_i = X_idx_0 * 0.01 + X_idx_2 * 1.0E-8;
  t1 = -(X_idx_1 - sm_circuit_Diode_4_v);
  out.mX[0] = X_idx_2;
  out.mX[1] = sm_circuit_Diode_4_v;
  out.mX[2] = X_idx_1;
  out.mX[3] = X_idx_2 * 1.0E-6 + X_idx_0;
  out.mX[4] = X_idx_0;
  out.mX[5] = X_idx_2 * X_idx_2 * 1.0E-9;
  out.mX[6] = sm_circuit_Diode_1_i;
  out.mX[7] = X_idx_1;
  out.mX[8] = sm_circuit_Diode_1_p_v;
  out.mX[9] = sm_circuit_Diode_1_v;
  out.mX[10] = sm_circuit_Diode_1_i * sm_circuit_Diode_1_v;
  out.mX[11] = X_idx_3;
  out.mX[12] = X_idx_1;
  out.mX[13] = -X_idx_1;
  out.mX[14] = X_idx_3 * -X_idx_1;
  out.mX[15] = sm_circuit_Diode_3_i;
  out.mX[16] = sm_circuit_Diode_1_p_v;
  out.mX[17] = sm_circuit_Diode_4_v;
  out.mX[18] = sm_circuit_Diode_3_v;
  out.mX[19] = sm_circuit_Diode_3_i * sm_circuit_Diode_3_v;
  out.mX[20] = X_idx_4;
  out.mX[21] = sm_circuit_Diode_4_v;
  out.mX[22] = sm_circuit_Diode_4_v;
  out.mX[23] = X_idx_4 * sm_circuit_Diode_4_v;
  out.mX[24] = sm_circuit_Ideal_Transformer_i1;
  out.mX[25] = sm_circuit_Ideal_Transformer_i1 * -14.0;
  out.mX[26] = U_idx_0;
  out.mX[27] = sm_circuit_Diode_1_p_v;
  out.mX[28] = U_idx_0;
  out.mX[29] = U_idx_0 * 0.071428571428571425;
  out.mX[30] = sm_circuit_Load_i;
  out.mX[31] = sm_circuit_Diode_4_v;
  out.mX[32] = X_idx_1;
  out.mX[33] = sm_circuit_Load_i * 100.0;
  out.mX[34] = sm_circuit_Load_i * sm_circuit_Load_i * 100.0;
  out.mX[35] = U_idx_0;
  out.mX[36] = -sm_circuit_Ideal_Transformer_i1;
  out.mX[37] = U_idx_0;
  out.mX[38] = U_idx_0;
  out.mX[39] = U_idx_0;
  out.mX[40] = -t1;
  out.mX[41] = sm_circuit_Diode_4_v;
  out.mX[42] = X_idx_1;
  out.mX[43] = -t1;
  (void)sys;
  (void)t3;
  return 0;
}
