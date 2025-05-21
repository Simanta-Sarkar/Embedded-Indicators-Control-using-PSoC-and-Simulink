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
#include "project.h"
#include "indicator_control_model.h"  // Simulink logic
#include <stdbool.h>  // Needed for bool type

// Simulink model I/O variables (must be defined once globally)
boolean_T left_btn;
boolean_T right_btn;
boolean_T left_led_pwm;
boolean_T right_led_pwm;
uint8_T uart_status;
// Timer flag for 100ms tick (used in main loop and set by ISR)
volatile bool tick_100ms_flag = false;

// --- Timer ISR definition ---
CY_ISR(Timer_1_ISR_Handler)
{
    tick_100ms_flag = true;
    Timer_1_ReadStatusRegister();  // Clear interrupt flag (if required)
}

int main(void)
{
    CyGlobalIntEnable;

    UART_1_Start();     // Initialize UART
    PWM_1_Start();      // Left LED PWM
    PWM_2_Start();      // Right LED PWM
    Timer_1_Start();    // 100 ms timer

    UART_1_PutString("System Initialized\r\n");

    indicator_control_model_initialize();  // Simulink init

    for (;;)
    {
        if (tick_100ms_flag)  // Set in your Timer ISR
        {
            tick_100ms_flag = false;

            // --- Read inputs from buttons ---
            left_btn = Left_Button_Read();     // Reads 0 or 1
            right_btn = Right_Button_Read();

            // --- Run Simulink logic ---
            indicator_control_model_step();

            // --- Apply Simulink outputs ---
            if (left_led_pwm)
                PWM_1_Enable();
            else
                PWM_1_Stop();

            if (right_led_pwm)
                PWM_2_Enable();
            else
                PWM_2_Stop();

            // --- UART status output ---
            if (uart_status == 1)
                UART_1_PutString("Indicator ON\r\n");
            else if (uart_status == 2)
                UART_1_PutString("Hazard ON\r\n");
            else
                UART_1_PutString("OFF\r\n");
        }
    }

    // Optional (not typically reached)
    UART_1_Stop();
    return 0;
}


/* [] END OF FILE */