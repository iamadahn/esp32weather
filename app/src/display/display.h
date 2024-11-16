#ifndef DISPLAY_H_
#define DISPLAY_H_ 

#include "zephyr/kernel.h"

void display_handler(void *, void *, void *);

int display_init(void);

#endif
