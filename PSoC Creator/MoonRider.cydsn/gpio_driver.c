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
#include "gpio_driver.h"

void GPIO_Init(void) {
    // You can initialize pins here if needed, or leave empty
}

void GPIO_ReadButtons(ButtonState *left, ButtonState *right) {
    left->prev_state = left->state;
    right->prev_state = right->state;

    // Active-low buttons: 0 = pressed, 1 = not pressed
    left->state = Left_Button_Read();
    right->state = Right_Button_Read();
}

void GPIO_SetLED(uint8_t led_id, uint8_t state) {
    if (led_id == LED_LEFT) {
        PWM_1_Enable();
        if (!state) PWM_1_Stop();
    } else if (led_id == LED_RIGHT) {
        PWM_2_Enable();
        if (!state) PWM_2_Stop();
    }
}

/* [] END OF FILE */
