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
#ifndef UART_DRIVER_H
#define UART_DRIVER_H

#include <project.h>

void UART_Init(void);
void UART_Log(const char *message);
void UART_Close(void);

#endif
/* [] END OF FILE */
