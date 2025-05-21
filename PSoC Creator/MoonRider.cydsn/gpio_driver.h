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
#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include <project.h>

#define BUTTON_LEFT     0
#define BUTTON_RIGHT    1
#define BUTTON_PRESSED  0 // Active-low buttons
#define DEBOUNCE_TIME   50 // 50 msec debounce (not used in simulation)

#define LED_LEFT   0
#define LED_RIGHT  1

typedef struct {
    uint8_t state;        // Current state (0 = pressed, 1 = not pressed)
    uint8_t prev_state;   // Previous state
    uint32_t press_time;  // Time when the button was pressed
} ButtonState;

void GPIO_Init(void);
void GPIO_ReadButtons(ButtonState *left, ButtonState *right);
void Sim_SetButtonState(uint8_t button, uint8_t state);

// NEW: LED control function
void GPIO_SetLED(uint8_t led_id, uint8_t state);

#endif


/* [] END OF FILE */
