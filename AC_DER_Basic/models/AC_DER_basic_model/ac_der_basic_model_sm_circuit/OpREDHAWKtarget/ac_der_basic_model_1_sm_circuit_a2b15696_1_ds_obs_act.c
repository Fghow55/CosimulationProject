/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'ac_der_basic_model_1_sm_circuit/sm_circuit/Solver Configuration'.
 */

#include "ne_ds.h"
#include "ac_der_basic_model_1_sm_circuit_a2b15696_1_ds_sys_struct.h"
#include "ac_der_basic_model_1_sm_circuit_a2b15696_1_ds_obs_act.h"
#include "ac_der_basic_model_1_sm_circuit_a2b15696_1_ds.h"
#include "ac_der_basic_model_1_sm_circuit_a2b15696_1_ds_externals.h"
#include "ac_der_basic_model_1_sm_circuit_a2b15696_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T ac_der_basic_model_1_sm_circuit_a2b15696_1_ds_obs_act(const
  NeDynamicSystem *sys, const NeDynamicSystemInput *t2, NeDsMethodOutput *t3)
{
  PmRealVector out;
  real_T U_idx_0;
  real_T X_idx_0;
  real_T X_idx_1;
  real_T X_idx_2;
  real_T X_idx_3;
  real_T X_idx_4;
  real_T sm_circuit_Diode_1_p_v;
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
  out = t3->mOBS_ACT;
  sm_circuit_Diode_4_v = (-X_idx_0 + X_idx_2 * -1.0E-6) + X_idx_1;
  sm_circuit_Diode_1_p_v = U_idx_0 * 0.071428571428571425;
  sm_circuit_Ideal_Transformer_i1 = X_idx_3 * -0.071428571428571425 + X_idx_4 *
    0.071428571428571425;
  sm_circuit_Load_i = X_idx_0 * 0.01 + X_idx_2 * 1.0E-8;
  t1 = -(X_idx_1 - sm_circuit_Diode_4_v);
  out.mX[0] = X_idx_2;
  out.mX[1] = sm_circuit_Diode_4_v;
  out.mX[2] = X_idx_1;
  out.mX[3] = X_idx_2 * 1.0E-6 + X_idx_0;
  out.mX[4] = X_idx_0;
  out.mX[5] = (X_idx_0 * 0.01 + X_idx_2 * 1.00000001) + -X_idx_3;
  out.mX[6] = X_idx_1;
  out.mX[7] = sm_circuit_Diode_1_p_v;
  out.mX[8] = -X_idx_1 + U_idx_0 * 0.071428571428571425;
  out.mX[9] = X_idx_3;
  out.mX[10] = X_idx_1;
  out.mX[11] = 0.0;
  out.mX[12] = -X_idx_1;
  out.mX[13] = (X_idx_0 * 0.01 + X_idx_2 * 1.00000001) + -X_idx_4;
  out.mX[14] = sm_circuit_Diode_1_p_v;
  out.mX[15] = sm_circuit_Diode_4_v;
  out.mX[16] = ((-X_idx_0 + X_idx_2 * -1.0E-6) + U_idx_0 * -0.071428571428571425)
    + X_idx_1;
  out.mX[17] = X_idx_4;
  out.mX[18] = 0.0;
  out.mX[19] = sm_circuit_Diode_4_v;
  out.mX[20] = sm_circuit_Diode_4_v;
  out.mX[21] = 0.0;
  out.mX[22] = 0.0;
  out.mX[23] = sm_circuit_Ideal_Transformer_i1;
  out.mX[24] = sm_circuit_Ideal_Transformer_i1 * -14.0;
  out.mX[25] = 0.0;
  out.mX[26] = 0.0;
  out.mX[27] = U_idx_0;
  out.mX[28] = sm_circuit_Diode_1_p_v;
  out.mX[29] = U_idx_0;
  out.mX[30] = U_idx_0 * 0.071428571428571425;
  out.mX[31] = sm_circuit_Load_i;
  out.mX[32] = sm_circuit_Diode_4_v;
  out.mX[33] = X_idx_1;
  out.mX[34] = sm_circuit_Load_i * 100.0;
  out.mX[35] = U_idx_0;
  out.mX[36] = -sm_circuit_Ideal_Transformer_i1;
  out.mX[37] = 0.0;
  out.mX[38] = U_idx_0;
  out.mX[39] = U_idx_0;
  out.mX[40] = U_idx_0;
  out.mX[41] = -t1;
  out.mX[42] = sm_circuit_Diode_4_v;
  out.mX[43] = X_idx_1;
  out.mX[44] = -t1;
  (void)sys;
  (void)t3;
  return 0;
}
