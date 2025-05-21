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

static uint8_t sim_left_button_state = 1;  // 1 = not pressed, 0 = pressed (active-low)
static uint8_t sim_right_button_state = 1;

void GPIO_Init(void) {
    // No hardware initialization needed for simulation
}

void GPIO_ReadButtons(ButtonState *left, ButtonState *right) {
    left->prev_state = left->state;
    right->prev_state = right->state;
    left->state = sim_left_button_state;
    right->state = sim_right_button_state;
}

void Sim_SetButtonState(uint8_t button, uint8_t state) {
    if (button == BUTTON_LEFT) {
        sim_left_button_state = state;
    } else if (button == BUTTON_RIGHT) {
        sim_right_button_state = state;
    }
}
/* [] END OF FILE */
