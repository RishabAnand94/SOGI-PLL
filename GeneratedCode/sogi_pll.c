/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sogi_pll.c
 *
 * Code generated for Simulink model 'sogi_pll'.
 *
 * Model version                  : 7.20
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Sep  9 00:24:43 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "sogi_pll.h"
#include "rtwtypes.h"
#include <math.h>
#include <float.h>
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFFFU) ) || ( SCHAR_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFU) ) || ( INT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFUL) ) || ( LONG_MAX != (0x7FFFFFFFL) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;
extern real32_T rt_modf(real32_T u0, real32_T u1);
static void SOGIPLL_Init(DW_SOGIPLL *localDW);
static void SOGIPLL(real32_T rtu_v, real32_T rtu_i, real32_T *rty_wt, real32_T
                    *rty_omega, real32_T *rty_v_dq, real32_T *rty_v_dq_n,
                    real32_T *rty_i_dq, real32_T *rty_i_dq_i, boolean_T
                    rty_lock[2], real32_T *rty_sinCos, real32_T *rty_sinCos_n,
                    real32_T rtp_K, real32_T rtp_fNom, real_T rtp_B0, real_T
                    rtp_B1, DW_SOGIPLL *localDW);
real32_T rt_modf(real32_T u0, real32_T u1)
{
  real32_T y;
  y = u0;
  if (u1 == 0.0F) {
    if (u0 == 0.0F) {
      y = u1;
    }
  } else if (u0 == 0.0F) {
    y = 0.0F / u1;
  } else {
    boolean_T yEq;
    y = fmodf(u0, u1);
    yEq = (y == 0.0F);
    if ((!yEq) && (u1 > floorf(u1))) {
      real32_T q;
      q = fabsf(u0 / u1);
      yEq = (fabsf(q - floorf(q + 0.5F)) <= FLT_EPSILON * q);
    }

    if (yEq) {
      y = 0.0F;
    } else if ((u0 < 0.0F) != (u1 < 0.0F)) {
      y += u1;
    }
  }

  return y;
}

/* System initialize for atomic system: '<Root>/SOGI-PLL' */
static void SOGIPLL_Init(DW_SOGIPLL *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S1>/STInt' */
  localDW->STInt_PrevResetState = 2;
}

/* Output and update for atomic system: '<Root>/SOGI-PLL' */
static void SOGIPLL(real32_T rtu_v, real32_T rtu_i, real32_T *rty_wt, real32_T
                    *rty_omega, real32_T *rty_v_dq, real32_T *rty_v_dq_n,
                    real32_T *rty_i_dq, real32_T *rty_i_dq_i, boolean_T
                    rty_lock[2], real32_T *rty_sinCos, real32_T *rty_sinCos_n,
                    real32_T rtp_K, real32_T rtp_fNom, real_T rtp_B0, real_T
                    rtp_B1, DW_SOGIPLL *localDW)
{
  real_T rtb_Saturation_PI;
  real32_T rtb_Product1;
  real32_T rtb_Product1_a;
  real32_T rtb_STInt;
  real32_T rtb_Sum3_n;
  real32_T rtb_Ts;
  real32_T rtb_b2;
  real32_T rtb_b2_i;
  uint16_T rowIdx;
  boolean_T rtb_LTEqSP;
  boolean_T rtb_rst;

  /* SampleTimeMath: '<S4>/WeightedSampleTime_yCalc' incorporates:
   *  Constant: '<S1>/Constant'
   *  Gain: '<S4>/Gain_fnToWn'
   *  SampleTimeMath: '<S5>/WeightedSampleTime_yCalc'
   *
   * About '<S4>/WeightedSampleTime_yCalc':
   *  y = u * K where K = ( w * Ts )
   *
   * About '<S5>/WeightedSampleTime_yCalc':
   *  y = u * K where K = ( w * Ts )
   */
  rtb_Sum3_n = 6.28318548F * rtp_fNom * 0.0001;
  *rty_v_dq = rtb_Sum3_n;

  /* Product: '<S4>/Product_xCalc' incorporates:
   *  Constant: '<S4>/Constant_xCalc'
   *  Gain: '<S4>/Gain_sogiK'
   */
  rtb_Ts = rtp_K * 2.0F * *rty_v_dq;

  /* Math: '<S4>/Square_yCalc' */
  *rty_v_dq *= *rty_v_dq;

  /* Sum: '<S4>/Add1' incorporates:
   *  Constant: '<S4>/Constant_b0Calc'
   */
  *rty_sinCos_n = (rtb_Ts + *rty_v_dq) + 4.0F;

  /* Product: '<S4>/Divide_b0Calc' */
  *rty_sinCos = rtb_Ts / *rty_sinCos_n;

  /* Product: '<S4>/Product1' */
  rtb_Product1 = *rty_sinCos * rtu_v;

  /* Gain: '<S4>/Gain_b2Calc' */
  rtb_b2 = -*rty_sinCos;

  /* UnitDelay: '<S4>/UnitDelay_v_2' */
  *rty_sinCos = localDW->UnitDelay_v_2_DSTATE;

  /* Product: '<S4>/Divide_a2Calc' incorporates:
   *  Constant: '<S4>/Constant_a2Calc'
   *  Sum: '<S4>/Add2'
   */
  rtb_Ts = ((rtb_Ts - *rty_v_dq) - 4.0F) / *rty_sinCos_n;

  /* UnitDelay: '<S4>/UnitDelay_valpha_2' */
  *rty_wt = localDW->UnitDelay_valpha_2_DSTATE;

  /* Sum: '<S4>/Sum4' incorporates:
   *  Product: '<S4>/Product2'
   *  Product: '<S4>/Product6'
   */
  rtb_b2 = rtb_b2 * *rty_sinCos + rtb_Ts * *rty_wt;

  /* Product: '<S4>/Divide_a1Calc' incorporates:
   *  Constant: '<S4>/Constant_a1Calc'
   *  Gain: '<S4>/Gain_a1Calc'
   *  Sum: '<S4>/Subtract1'
   */
  *rty_wt = (4.0F - *rty_v_dq) * 2.0F / *rty_sinCos_n;

  /* Sum: '<S4>/Sum' incorporates:
   *  Product: '<S4>/Product9'
   *  Sum: '<S4>/Sum1'
   *  UnitDelay: '<S4>/UnitDelay_valpha_1'
   */
  rtb_Product1 += *rty_wt * localDW->UnitDelay_valpha_1_DSTATE + rtb_b2;

  /* Product: '<S4>/Divide_qb0Calc' incorporates:
   *  Gain: '<S4>/Gain_sogiK_2'
   */
  *rty_sinCos_n = rtp_K * *rty_v_dq / *rty_sinCos_n;

  /* Product: '<S4>/Product3' */
  rtb_b2 = *rty_sinCos_n * *rty_sinCos;

  /* UnitDelay: '<S4>/UnitDelay_vbeta_2' */
  *rty_sinCos = localDW->UnitDelay_vbeta_2_DSTATE;

  /* Sum: '<S4>/Sum2' incorporates:
   *  Gain: '<S4>/Gain4'
   *  Product: '<S4>/Product4'
   *  Product: '<S4>/Product5'
   *  Product: '<S4>/Product7'
   *  Product: '<S4>/Product8'
   *  Sum: '<S4>/Sum3'
   *  Sum: '<S4>/Sum5'
   *  UnitDelay: '<S4>/UnitDelay_v_1'
   *  UnitDelay: '<S4>/UnitDelay_vbeta_1'
   */
  rtb_b2 = ((2.0F * *rty_sinCos_n * localDW->UnitDelay_v_1_DSTATE + (rtb_Ts *
              *rty_sinCos + rtb_b2)) + *rty_wt *
            localDW->UnitDelay_vbeta_1_DSTATE) + *rty_sinCos_n * rtu_v;

  /* UnitDelay: '<S1>/UnitDelay_wt' */
  *rty_wt = localDW->UnitDelay_wt_DSTATE;

  /* Trigonometry: '<S1>/Sin' */
  *rty_sinCos = sinf(*rty_wt);

  /* Trigonometry: '<S1>/Cos1' */
  *rty_sinCos_n = cosf(*rty_wt);

  /* Fcn: '<S2>/Fcn2' */
  *rty_v_dq = rtb_Product1 * *rty_sinCos - rtb_b2 * *rty_sinCos_n;

  /* Abs: '<S1>/Abs' incorporates:
   *  Product: '<S1>/Product'
   *  Sum: '<S1>/Subtract'
   */
  rtb_Ts = fabsf(rtb_Product1 - *rty_v_dq * *rty_sinCos);

  /* Fcn: '<S2>/Fcn3' */
  *rty_v_dq_n = rtb_Product1 * *rty_sinCos_n + rtb_b2 * *rty_sinCos;

  /* SampleTimeMath: '<S5>/WeightedSampleTime_yCalc'
   *
   * About '<S5>/WeightedSampleTime_yCalc':
   *  y = u * K where K = ( w * Ts )
   */
  *rty_omega = rtb_Sum3_n;

  /* Product: '<S5>/Product_xCalc' incorporates:
   *  Constant: '<S5>/Constant_xCalc'
   *  Gain: '<S5>/Gain_sogiK'
   */
  rtb_Sum3_n = rtp_K * 2.0F * *rty_omega;

  /* Math: '<S5>/Square_yCalc' */
  *rty_omega *= *rty_omega;

  /* Sum: '<S5>/Add1' incorporates:
   *  Constant: '<S5>/Constant_b0Calc'
   */
  rtb_STInt = (rtb_Sum3_n + *rty_omega) + 4.0F;

  /* Product: '<S5>/Divide_b0Calc' */
  *rty_i_dq_i = rtb_Sum3_n / rtb_STInt;

  /* Product: '<S5>/Product1' */
  rtb_Product1_a = *rty_i_dq_i * rtu_i;

  /* Gain: '<S5>/Gain_b2Calc' */
  rtb_b2_i = -*rty_i_dq_i;

  /* UnitDelay: '<S5>/UnitDelay_v_2' */
  *rty_i_dq_i = localDW->UnitDelay_v_2_DSTATE_h;

  /* Product: '<S5>/Divide_a2Calc' incorporates:
   *  Constant: '<S5>/Constant_a2Calc'
   *  Sum: '<S5>/Add2'
   */
  rtb_Sum3_n = ((rtb_Sum3_n - *rty_omega) - 4.0F) / rtb_STInt;

  /* UnitDelay: '<S5>/UnitDelay_valpha_2' */
  *rty_i_dq = localDW->UnitDelay_valpha_2_DSTATE_f;

  /* Sum: '<S5>/Sum4' incorporates:
   *  Product: '<S5>/Product2'
   *  Product: '<S5>/Product6'
   */
  rtb_b2_i = rtb_b2_i * *rty_i_dq_i + rtb_Sum3_n * *rty_i_dq;

  /* Product: '<S5>/Divide_a1Calc' incorporates:
   *  Constant: '<S5>/Constant_a1Calc'
   *  Gain: '<S5>/Gain_a1Calc'
   *  Sum: '<S5>/Subtract1'
   */
  *rty_i_dq = (4.0F - *rty_omega) * 2.0F / rtb_STInt;

  /* Sum: '<S5>/Sum' incorporates:
   *  Product: '<S5>/Product9'
   *  Sum: '<S5>/Sum1'
   *  UnitDelay: '<S5>/UnitDelay_valpha_1'
   */
  rtb_Product1_a += *rty_i_dq * localDW->UnitDelay_valpha_1_DSTATE_d + rtb_b2_i;

  /* Product: '<S5>/Divide_qb0Calc' incorporates:
   *  Gain: '<S5>/Gain_sogiK_2'
   */
  rtb_STInt = rtp_K * *rty_omega / rtb_STInt;

  /* Product: '<S5>/Product3' */
  rtb_b2_i = rtb_STInt * *rty_i_dq_i;

  /* UnitDelay: '<S5>/UnitDelay_vbeta_2' */
  *rty_i_dq_i = localDW->UnitDelay_vbeta_2_DSTATE_i;

  /* Sum: '<S5>/Sum2' incorporates:
   *  Gain: '<S5>/Gain4'
   *  Product: '<S5>/Product4'
   *  Product: '<S5>/Product5'
   *  Product: '<S5>/Product7'
   *  Product: '<S5>/Product8'
   *  Sum: '<S5>/Sum3'
   *  Sum: '<S5>/Sum5'
   *  UnitDelay: '<S5>/UnitDelay_v_1'
   *  UnitDelay: '<S5>/UnitDelay_vbeta_1'
   */
  rtb_Sum3_n = ((2.0F * rtb_STInt * localDW->UnitDelay_v_1_DSTATE_n +
                 (rtb_Sum3_n * *rty_i_dq_i + rtb_b2_i)) + *rty_i_dq *
                localDW->UnitDelay_vbeta_1_DSTATE_i) + rtb_STInt * rtu_i;

  /* Fcn: '<S3>/Fcn2' */
  *rty_i_dq = rtb_Product1_a * *rty_sinCos - rtb_Sum3_n * *rty_sinCos_n;

  /* Fcn: '<S3>/Fcn3' */
  *rty_i_dq_i = rtb_Product1_a * *rty_sinCos_n + rtb_Sum3_n * *rty_sinCos;

  /* Gain: '<S1>/Gain1' */
  rtb_STInt = 0.1F * *rty_v_dq;

  /* RelationalOperator: '<S1>/GTCP' */
  rtb_rst = (rtb_Ts > rtb_STInt);

  /* RelationalOperator: '<S1>/LTEqSP' */
  rtb_LTEqSP = (rtb_Ts <= rtb_STInt);

  /* DiscreteIntegrator: '<S1>/STInt' */
  if ((!rtb_LTEqSP) && (localDW->STInt_PrevResetState == 1)) {
    localDW->STInt_DSTATE = 0.0F;
  }

  if (localDW->STInt_DSTATE >= 1.0F) {
    localDW->STInt_DSTATE = 1.0F;
  } else if (localDW->STInt_DSTATE <= 0.0F) {
    localDW->STInt_DSTATE = 0.0F;
  }

  /* UnitDelay: '<S6>/UnitDelay_PI1' */
  *rty_omega = localDW->UnitDelay_PI1_DSTATE;

  /* Sum: '<S6>/Sum' incorporates:
   *  Constant: '<S6>/Constant_B0'
   *  Constant: '<S6>/Constant_B1'
   *  Product: '<S6>/Product1'
   *  Product: '<S6>/Product8'
   *  Sum: '<S6>/Sum1'
   *  UnitDelay: '<S6>/UnitDelay_PI2'
   */
  rtb_Saturation_PI = (rtp_B1 * *rty_omega + localDW->UnitDelay_PI2_DSTATE) +
    rtp_B0 * *rty_v_dq_n;

  /* Saturate: '<S6>/Saturation_PI' */
  if (rtb_Saturation_PI > 20.0) {
    rtb_Saturation_PI = 20.0;
  } else if (rtb_Saturation_PI < -20.0) {
    rtb_Saturation_PI = -20.0;
  }

  /* End of Saturate: '<S6>/Saturation_PI' */

  /* Gain: '<S1>/Gain' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Sum: '<S1>/Sum2'
   */
  *rty_omega = (real32_T)((rtb_Saturation_PI + rtp_fNom) * 6.2831853071795862);

  /* Math: '<S1>/Math Function' incorporates:
   *  Constant: '<S1>/cst'
   *  SampleTimeMath: '<S1>/Ts'
   *  Sum: '<S1>/Sum3'
   *  UnitDelay: '<S1>/UnitDelay_wInt'
   *
   * About '<S1>/Ts':
   *  y = u * K where K = ( w * Ts )
   */
  rtb_Ts = rt_modf(*rty_omega * 0.0001 + localDW->UnitDelay_wInt_DSTATE,
                   6.28318548F);

  /* CombinatorialLogic: '<S7>/Logic' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/ST'
   *  DiscreteIntegrator: '<S1>/STInt'
   *  Memory: '<S7>/Memory'
   *  Product: '<S1>/Divide'
   *  RelationalOperator: '<S1>/GTEqST'
   */
  rowIdx = ((((uint16_T)(localDW->STInt_DSTATE >= 2.0 / rtp_fNom) << 1) +
             rtb_rst) << 1) + localDW->Memory_PreviousInput;
  rty_lock[0U] = rtConstP.Logic_table[rowIdx];
  rty_lock[1U] = rtConstP.Logic_table[rowIdx + 8U];

  /* Update for UnitDelay: '<S4>/UnitDelay_v_2' incorporates:
   *  UnitDelay: '<S4>/UnitDelay_v_1'
   */
  localDW->UnitDelay_v_2_DSTATE = localDW->UnitDelay_v_1_DSTATE;

  /* Update for UnitDelay: '<S4>/UnitDelay_valpha_2' incorporates:
   *  UnitDelay: '<S4>/UnitDelay_valpha_1'
   */
  localDW->UnitDelay_valpha_2_DSTATE = localDW->UnitDelay_valpha_1_DSTATE;

  /* Update for UnitDelay: '<S4>/UnitDelay_valpha_1' */
  localDW->UnitDelay_valpha_1_DSTATE = rtb_Product1;

  /* Update for UnitDelay: '<S4>/UnitDelay_v_1' */
  localDW->UnitDelay_v_1_DSTATE = rtu_v;

  /* Update for UnitDelay: '<S4>/UnitDelay_vbeta_2' incorporates:
   *  UnitDelay: '<S4>/UnitDelay_vbeta_1'
   */
  localDW->UnitDelay_vbeta_2_DSTATE = localDW->UnitDelay_vbeta_1_DSTATE;

  /* Update for UnitDelay: '<S4>/UnitDelay_vbeta_1' */
  localDW->UnitDelay_vbeta_1_DSTATE = rtb_b2;

  /* Update for UnitDelay: '<S1>/UnitDelay_wt' */
  localDW->UnitDelay_wt_DSTATE = rtb_Ts;

  /* Update for UnitDelay: '<S5>/UnitDelay_v_2' incorporates:
   *  UnitDelay: '<S5>/UnitDelay_v_1'
   */
  localDW->UnitDelay_v_2_DSTATE_h = localDW->UnitDelay_v_1_DSTATE_n;

  /* Update for UnitDelay: '<S5>/UnitDelay_valpha_2' incorporates:
   *  UnitDelay: '<S5>/UnitDelay_valpha_1'
   */
  localDW->UnitDelay_valpha_2_DSTATE_f = localDW->UnitDelay_valpha_1_DSTATE_d;

  /* Update for UnitDelay: '<S5>/UnitDelay_valpha_1' */
  localDW->UnitDelay_valpha_1_DSTATE_d = rtb_Product1_a;

  /* Update for UnitDelay: '<S5>/UnitDelay_v_1' */
  localDW->UnitDelay_v_1_DSTATE_n = rtu_i;

  /* Update for UnitDelay: '<S5>/UnitDelay_vbeta_2' incorporates:
   *  UnitDelay: '<S5>/UnitDelay_vbeta_1'
   */
  localDW->UnitDelay_vbeta_2_DSTATE_i = localDW->UnitDelay_vbeta_1_DSTATE_i;

  /* Update for UnitDelay: '<S5>/UnitDelay_vbeta_1' */
  localDW->UnitDelay_vbeta_1_DSTATE_i = rtb_Sum3_n;

  /* Update for DiscreteIntegrator: '<S1>/STInt' */
  localDW->STInt_DSTATE += rtb_LTEqSP ? 0.0001 : 0.0F;
  if (localDW->STInt_DSTATE >= 1.0F) {
    localDW->STInt_DSTATE = 1.0F;
  }

  localDW->STInt_PrevResetState = (int16_T)rtb_LTEqSP;

  /* End of Update for DiscreteIntegrator: '<S1>/STInt' */

  /* Update for UnitDelay: '<S6>/UnitDelay_PI1' */
  localDW->UnitDelay_PI1_DSTATE = *rty_v_dq_n;

  /* Update for UnitDelay: '<S6>/UnitDelay_PI2' */
  localDW->UnitDelay_PI2_DSTATE = rtb_Saturation_PI;

  /* Update for UnitDelay: '<S1>/UnitDelay_wInt' */
  localDW->UnitDelay_wInt_DSTATE = rtb_Ts;

  /* Update for Memory: '<S7>/Memory' */
  localDW->Memory_PreviousInput = rty_lock[0];
}

/* Model step function */
void sogi_pll_step(void)
{
  boolean_T rtb_Logic[2];

  /* Outputs for Atomic SubSystem: '<Root>/SOGI-PLL' */

  /* Outport: '<Root>/sinCos' incorporates:
   *  Inport: '<Root>/ia'
   *  Inport: '<Root>/vsa'
   *  Outport: '<Root>/idq'
   *  Outport: '<Root>/omega'
   *  Outport: '<Root>/theta'
   *  Outport: '<Root>/vdq'
   */
  SOGIPLL(rtU.vsa, rtU.ia, &rtY.theta, &rtY.omega, &rtY.vdq[0], &rtY.vdq[1],
          &rtY.idq[0], &rtY.idq[1], rtb_Logic, &rtY.sinCos[0], &rtY.sinCos[1],
          0.5F, 60.0F, 166.877556, -166.322444, &rtDW.SOGIPLL_g);

  /* End of Outputs for SubSystem: '<Root>/SOGI-PLL' */

  /* Outport: '<Root>/lock' */
  rtY.lock = rtb_Logic[0];
}

/* Model initialize function */
void sogi_pll_initialize(void)
{
  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)&rtDW, 0,
                sizeof(DW));

  /* SystemInitialize for Atomic SubSystem: '<Root>/SOGI-PLL' */
  SOGIPLL_Init(&rtDW.SOGIPLL_g);

  /* End of SystemInitialize for SubSystem: '<Root>/SOGI-PLL' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
