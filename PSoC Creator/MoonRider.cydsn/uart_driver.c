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
#include "uart_driver.h"
#include <stdio.h>

static FILE *log_file = NULL;

void UART_Init(void) {
    log_file = fopen("uart_log.txt", "w");
    if (log_file == NULL) {
        printf("Error: Could not open uart_log.txt for writing\n");
    }
}

void UART_Log(const char *message) {
    if (log_file != NULL) {
        fprintf(log_file, "%s\n", message);
        fflush(log_file);
    }
    printf("%s\n", message);
}

void UART_Close(void) {
    if (log_file != NULL) {
        fclose(log_file);
        log_file = NULL;
    }
}
/* [] END OF FILE */
