#ifndef XV_FUNCTIONS_H

#define XV_FUNCTIONS_H

#include "main.h"
#include <stdio.h>
#include <stdarg.h>

void xv_redirect_printf(UART_HandleTypeDef *huartn);
void xv_print(const char *format, ...);

#endif
