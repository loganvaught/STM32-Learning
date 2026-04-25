#include "xv_functions.h"

// Helper function that uses code found on stm32world.com

UART_HandleTypeDef *current_huartn;

// Code from stm32world.com
int _write(int fd, char* ptr, int len) {
  HAL_StatusTypeDef hstatus;

  if (fd == 1 || fd == 2) {
    hstatus = HAL_UART_Transmit(current_huartn, (uint8_t *) ptr, len, HAL_MAX_DELAY);
    if (hstatus == HAL_OK)
      return len;
    else
      return -1;
  }
  return -1;
}

void xv_redirect_printf(UART_HandleTypeDef *huartn) {
	// Avoid double call
	if (huartn == current_huartn) return;

	if (huartn != current_huartn) {
      xv_print("XV: printf redirecting...");
      current_huartn = huartn;
      xv_print("XV: printf redirected");
    }
}

void xv_print(const char *msg) {
	if (current_huartn != NULL) {
		printf("%s\r\n", msg);
	}
}
