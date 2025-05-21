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
#include "indicator_app.h"

static ButtonState left_button = {0, 0, 0};
static ButtonState right_button = {0, 0, 0};

void Scheduler_Init(void) {
    GPIO_Init();
    UART_Init();
    PWM_Init();
    Timer_Init();
    IndicatorApp_Init();
    UART_Log("System Initialized");
}

void Scheduler_Run(void) {
    static uint32_t last_tick = 0;
    uint32_t current_tick = Timer_GetTicks();
    
    if (current_tick != last_tick) {
        last_tick = current_tick;
        
        // Read buttons
        GPIO_ReadButtons(&left_button, &right_button);
        
        // Call application logic (to be replaced by Simulink)
        IndicatorApp_Run(&left_button, &right_button, current_tick);
    }
}
/* [] END OF FILE */
