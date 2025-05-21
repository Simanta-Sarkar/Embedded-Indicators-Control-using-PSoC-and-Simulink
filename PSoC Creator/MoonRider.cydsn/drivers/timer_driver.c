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
#include "timer_driver.h"

static uint32_t ticks = 0;

void Timer_Init(void) {
    ticks = 0;
}

uint32_t Timer_GetTicks(void) {
    return ticks++;
}
/* [] END OF FILE */
