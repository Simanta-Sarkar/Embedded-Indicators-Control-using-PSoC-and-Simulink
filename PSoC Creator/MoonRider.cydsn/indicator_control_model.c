/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: indicator_control_model.c
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

#include "indicator_control_model.h"
#include "rtwtypes.h"

/* Named constants for Chart: '<Root>/Chart' */
#define indicator_control_m_IN_RIGHT_ON ((uint8_T)4U)
#define indicator_control_mo_IN_LEFT_ON ((uint8_T)2U)
#define indicator_control_mod_IN_HAZARD ((uint8_T)1U)
#define indicator_control_model_IN_OFF ((uint8_T)3U)

/* Block states (default storage) */
DW_indicator_control_model_T indicator_control_model_DW;

/* External inputs (root inport signals with default storage) */
ExtU_indicator_control_model_T indicator_control_model_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_indicator_control_model_T indicator_control_model_Y;

/* Real-time model */
static RT_MODEL_indicator_control_mo_T indicator_control_model_M_;
RT_MODEL_indicator_control_mo_T *const indicator_control_model_M =
  &indicator_control_model_M_;

/* Model step function */
void indicator_control_model_step(void)
{
  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/left_btn'
   *  Inport: '<Root>/right_btn'
   */
  if (indicator_control_model_DW.is_active_c3_indicator_control_ == 0) {
    indicator_control_model_DW.is_active_c3_indicator_control_ = 1U;
    indicator_control_model_DW.is_c3_indicator_control_model =
      indicator_control_model_IN_OFF;

    /* Outport: '<Root>/left_led_pwm' */
    indicator_control_model_Y.left_led_pwm = false;

    /* Outport: '<Root>/right_led_pwm' */
    indicator_control_model_Y.right_led_pwm = false;

    /* Outport: '<Root>/uart_status' */
    indicator_control_model_Y.uart_status = 0U;
  } else {
    switch (indicator_control_model_DW.is_c3_indicator_control_model) {
     case indicator_control_mod_IN_HAZARD:
      if (indicator_control_model_U.left_btn &&
          (!indicator_control_model_U.right_btn)) {
        indicator_control_model_DW.is_c3_indicator_control_model =
          indicator_control_mo_IN_LEFT_ON;

        /* Outport: '<Root>/left_led_pwm' */
        indicator_control_model_Y.left_led_pwm =
          !indicator_control_model_Y.left_led_pwm;

        /* Outport: '<Root>/right_led_pwm' */
        indicator_control_model_Y.right_led_pwm = false;
      } else if (indicator_control_model_U.right_btn &&
                 (!indicator_control_model_U.left_btn)) {
        indicator_control_model_DW.is_c3_indicator_control_model =
          indicator_control_m_IN_RIGHT_ON;

        /* Outport: '<Root>/right_led_pwm' */
        indicator_control_model_Y.right_led_pwm =
          !indicator_control_model_Y.right_led_pwm;

        /* Outport: '<Root>/left_led_pwm' */
        indicator_control_model_Y.left_led_pwm = false;
      }
      break;

     case indicator_control_mo_IN_LEFT_ON:
      if ((!indicator_control_model_U.left_btn) &&
          (!indicator_control_model_U.right_btn)) {
        indicator_control_model_DW.is_c3_indicator_control_model =
          indicator_control_model_IN_OFF;

        /* Outport: '<Root>/left_led_pwm' */
        indicator_control_model_Y.left_led_pwm = false;

        /* Outport: '<Root>/right_led_pwm' */
        indicator_control_model_Y.right_led_pwm = false;

        /* Outport: '<Root>/uart_status' */
        indicator_control_model_Y.uart_status = 0U;
      }
      break;

     case indicator_control_model_IN_OFF:
      /* Outport: '<Root>/uart_status' */
      indicator_control_model_Y.uart_status = 0U;
      if (indicator_control_model_U.left_btn &&
          (!indicator_control_model_U.right_btn)) {
        indicator_control_model_DW.is_c3_indicator_control_model =
          indicator_control_mo_IN_LEFT_ON;

        /* Outport: '<Root>/left_led_pwm' */
        indicator_control_model_Y.left_led_pwm =
          !indicator_control_model_Y.left_led_pwm;

        /* Outport: '<Root>/right_led_pwm' */
        indicator_control_model_Y.right_led_pwm = false;
      } else if (indicator_control_model_U.left_btn &&
                 indicator_control_model_U.right_btn) {
        indicator_control_model_DW.is_c3_indicator_control_model =
          indicator_control_mod_IN_HAZARD;

        /* Outport: '<Root>/left_led_pwm' */
        indicator_control_model_Y.left_led_pwm =
          !indicator_control_model_Y.left_led_pwm;

        /* Outport: '<Root>/right_led_pwm' */
        indicator_control_model_Y.right_led_pwm =
          !indicator_control_model_Y.right_led_pwm;
      } else if (indicator_control_model_U.right_btn &&
                 (!indicator_control_model_U.left_btn)) {
        indicator_control_model_DW.is_c3_indicator_control_model =
          indicator_control_m_IN_RIGHT_ON;

        /* Outport: '<Root>/right_led_pwm' */
        indicator_control_model_Y.right_led_pwm =
          !indicator_control_model_Y.right_led_pwm;

        /* Outport: '<Root>/left_led_pwm' */
        indicator_control_model_Y.left_led_pwm = false;
      }
      break;

     default:
      /* case IN_RIGHT_ON: */
      if ((!indicator_control_model_U.left_btn) &&
          (!indicator_control_model_U.right_btn)) {
        indicator_control_model_DW.is_c3_indicator_control_model =
          indicator_control_model_IN_OFF;

        /* Outport: '<Root>/left_led_pwm' */
        indicator_control_model_Y.left_led_pwm = false;

        /* Outport: '<Root>/right_led_pwm' */
        indicator_control_model_Y.right_led_pwm = false;

        /* Outport: '<Root>/uart_status' */
        indicator_control_model_Y.uart_status = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */
}

/* Model initialize function */
void indicator_control_model_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void indicator_control_model_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
