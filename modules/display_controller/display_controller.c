#include "display_controller.h"
#include "stdint.h"
#include "stdio.h"

extern void delay_ms(uint32_t ms);

void
display_controller_task(void* argument) {
  printf("display_controller task started\n");
  while (1) {
    delay_ms(10);
  }
}
