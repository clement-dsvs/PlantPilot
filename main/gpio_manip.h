#ifndef GPIO_MANIP_H
#define GPIO_MANIP_H

#include "freertos/FreeRTOS.h"
#include <soc/gpio_reg.h>
#include <soc/gpio_num.h>

void gpio_enable_output(gpio_num_t gpio_num);

void gpio_set_output(gpio_num_t gpio_num, uint32_t level);

#endif