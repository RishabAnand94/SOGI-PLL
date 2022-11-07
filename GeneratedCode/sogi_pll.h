/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sogi_pll.h
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

#ifndef RTW_HEADER_sogi_pll_h_
#define RTW_HEADER_sogi_pll_h_
#ifndef sogi_pll_COMMON_INCLUDES_
#define sogi_pll_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* sogi_pll_COMMON_INCLUDES_ */

#include <string.h>

/* Model Code Variants */

/* Block signals and states (default storage) for system '<Root>/SOGI-PLL' */
typedef struct {
  real_T UnitDelay_PI2_DSTATE;         /* '<S6>/UnitDelay_PI2' */
  real32_T UnitDelay_v_2_DSTATE;       /* '<S4>/UnitDelay_v_2' */
  real32_T UnitDelay_valpha_2_DSTATE;  /* '<S4>/UnitDelay_valpha_2' */
  real32_T UnitDelay_valpha_1_DSTATE;  /* '<S4>/UnitDelay_valpha_1' */
  real32_T UnitDelay_v_1_DSTATE;       /* '<S4>/UnitDelay_v_1' */
  real32_T UnitDelay_vbeta_2_DSTATE;   /* '<S4>/UnitDelay_vbeta_2' */
  real32_T UnitDelay_vbeta_1_DSTATE;   /* '<S4>/UnitDelay_vbeta_1' */
  real32_T UnitDelay_wt_DSTATE;        /* '<S1>/UnitDelay_wt' */
  real32_T UnitDelay_v_2_DSTATE_h;     /* '<S5>/UnitDelay_v_2' */
  real32_T UnitDelay_valpha_2_DSTATE_f;/* '<S5>/UnitDelay_valpha_2' */
  real32_T UnitDelay_valpha_1_DSTATE_d;/* '<S5>/UnitDelay_valpha_1' */
  real32_T UnitDelay_v_1_DSTATE_n;     /* '<S5>/UnitDelay_v_1' */
  real32_T UnitDelay_vbeta_2_DSTATE_i; /* '<S5>/UnitDelay_vbeta_2' */
  real32_T UnitDelay_vbeta_1_DSTATE_i; /* '<S5>/UnitDelay_vbeta_1' */
  real32_T STInt_DSTATE;               /* '<S1>/STInt' */
  real32_T UnitDelay_PI1_DSTATE;       /* '<S6>/UnitDelay_PI1' */
  real32_T UnitDelay_wInt_DSTATE;      /* '<S1>/UnitDelay_wInt' */
  int16_T STInt_PrevResetState;        /* '<S1>/STInt' */
  boolean_T Memory_PreviousInput;      /* '<S7>/Memory' */
} DW_SOGIPLL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_SOGIPLL SOGIPLL_g;                /* '<Root>/SOGI-PLL' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Logic_table
   * Referenced by: '<S7>/Logic'
   */
  boolean_T Logic_table[16];
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T vsa;                        /* '<Root>/vsa' */
  real32_T ia;                         /* '<Root>/ia' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T theta;                      /* '<Root>/theta' */
  real32_T omega;                      /* '<Root>/omega' */
  real32_T vdq[2];                     /* '<Root>/vdq' */
  real32_T idq[2];                     /* '<Root>/idq' */
  boolean_T lock;                      /* '<Root>/lock' */
  real32_T sinCos[2];                  /* '<Root>/sinCos' */
} ExtY;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void sogi_pll_initialize(void);
extern void sogi_pll_step(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope2' : Unused code path elimination
 * Block '<S1>/Scope3' : Unused code path elimination
 * Block '<S4>/Gain6' : Eliminated nontunable gain of 1
 * Block '<S5>/Gain6' : Eliminated nontunable gain of 1
 */

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
 * '<Root>' : 'sogi_pll'
 * '<S1>'   : 'sogi_pll/SOGI-PLL'
 * '<S2>'   : 'sogi_pll/SOGI-PLL/Alpha-Beta-Zero to dq1'
 * '<S3>'   : 'sogi_pll/SOGI-PLL/Alpha-Beta-Zero to dq3'
 * '<S4>'   : 'sogi_pll/SOGI-PLL/OSGv2_'
 * '<S5>'   : 'sogi_pll/SOGI-PLL/OSGv2_1'
 * '<S6>'   : 'sogi_pll/SOGI-PLL/PI'
 * '<S7>'   : 'sogi_pll/SOGI-PLL/S-R Flip-Flop'
 */
#endif                                 /* RTW_HEADER_sogi_pll_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
