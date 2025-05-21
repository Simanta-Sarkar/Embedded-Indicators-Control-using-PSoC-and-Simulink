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
#include "scheduler.h"
#include "gpio_driver.h"
#include "uart_driver.h"
#include "pwm_driver.h"
#include "timer_driver.h"
#include "indicator_control_model.h"
#include <stdbool.h>

// Simulink model I/O variables
boolean_T left_btn;
boolean_T right_btn;
boolean_T left_led_pwm;
boolean_T right_led_pwm;
uint8_T uart_status;

static ButtonState left_button = {0, 0, 0};
static ButtonState right_button = {0, 0, 0};

void Scheduler_Init(void) {
    GPIO_Init();
    UART_Init();
    PWM_Init();
    Timer_Init();
    indicator_control_model_initialize();
    UART_Log("System Initialized");
}

void Scheduler_Run(void) {
    static uint32_t last_tick = 0;
    uint32_t current_tick = Timer_GetTicks();

    if (current_tick != last_tick) {
        last_tick = current_tick;

        // Read buttons
        GPIO_ReadButtons(&left_button, &right_button);

        // Use button state (active-low logic)
        left_btn = (left_button.state == BUTTON_PRESSED);
        right_btn = (right_button.state == BUTTON_PRESSED);

        // Call Simulink logic
        indicator_control_model_step();

        // Update LEDs
        GPIO_SetLED(LED_LEFT, left_led_pwm);
        GPIO_SetLED(LED_RIGHT, right_led_pwm);

        // Log UART status
        if (uart_status == 1)
            UART_Log("Indicator ON");
        else if (uart_status == 2)
            UART_Log("Hazard ON");
        else
            UART_Log("OFF");
    }
}

/* [] END OF FILE */
