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
#ifndef PWM_DRIVER_H
#define PWM_DRIVER_H

#include <project.h>

#define PWM_LEFT    0
#define PWM_RIGHT   1

void PWM_Init(void);
void PWM_SetState(uint8_t channel, uint8_t state);
void PWM_Toggle(uint8_t channel);
uint8_t PWM_GetState(uint8_t channel);

#endif
/* [] END OF FILE */
