/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "pwm_driver.h"
#include "uart_driver.h"

static uint8_t left_led_state = 0;
static uint8_t right_led_state = 0;

void PWM_Init(void) {
    PWM_SetState(PWM_LEFT, 0);
    PWM_SetState(PWM_RIGHT, 0);
}

void PWM_SetState(uint8_t channel, uint8_t state) {
    if (channel == PWM_LEFT) {
        if (left_led_state != state) {
            left_led_state = state;
            UART_Log(state ? "Left LED: ON" : "Left LED: OFF");
        }
    } else if (channel == PWM_RIGHT) {
        if (right_led_state != state) {
            right_led_state = state;
            UART_Log(state ? "Right LED: ON" : "Right LED: OFF");
        }
    }
}

void PWM_Toggle(uint8_t channel) {
    if (channel == PWM_LEFT) {
        left_led_state = !left_led_state;
        UART_Log(left_led_state ? "Left LED: ON (Toggled)" : "Left LED: OFF (Toggled)");
    } else if (channel == PWM_RIGHT) {
        right_led_state = !right_led_state;
        UART_Log(right_led_state ? "Right LED: ON (Toggled)" : "Right LED: OFF (Toggled)");
    }
}

uint8_t PWM_GetState(uint8_t channel) {
    return (channel == PWM_LEFT) ? left_led_state : right_led_state;
}
/* [] END OF FILE */
