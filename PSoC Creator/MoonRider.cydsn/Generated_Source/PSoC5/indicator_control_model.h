/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: indicator_control_model.h
 *
 * Code generated for Simulink model 'indicator_control_model'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Tue May 20 23:18:10 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef indicator_control_model_h_
#define indicator_control_model_h_
#ifndef indicator_control_model_COMMON_INCLUDES_
#define indicator_control_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                            /* indicator_control_model_COMMON_INCLUDES_ */

#include "indicator_control_model_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_indicator_control_;/* '<Root>/Chart' */
  uint8_T is_c3_indicator_control_model;/* '<Root>/Chart' */
} DW_indicator_control_model_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  boolean_T left_btn;                  /* '<Root>/left_btn' */
  boolean_T right_btn;                 /* '<Root>/right_btn' */
} ExtU_indicator_control_model_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T left_led_pwm;              /* '<Root>/left_led_pwm' */
  boolean_T right_led_pwm;             /* '<Root>/right_led_pwm' */
  uint8_T uart_status;                 /* '<Root>/uart_status' */
} ExtY_indicator_control_model_T;

/* Real-time Model Data Structure */
struct tag_RTM_indicator_control_mod_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_indicator_control_model_T indicator_control_model_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_indicator_control_model_T indicator_control_model_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_indicator_control_model_T indicator_control_model_Y;

/* Model entry point functions */
extern void indicator_control_model_initialize(void);
extern void indicator_control_model_step(void);
extern void indicator_control_model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_indicator_control_mo_T *const indicator_control_model_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * '<Root>' : 'indicator_control_model'
 * '<S1>'   : 'indicator_control_model/Chart'
 */
#endif                                 /* indicator_control_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
