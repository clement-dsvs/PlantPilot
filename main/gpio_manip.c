#include <driver/gpio.h>
#include "gpio_manip.h"

// s for set
// every bit that is set in this registry will enable the corresponding GPIO
volatile uint32_t* gpio_out_w1ts_reg = (volatile uint32_t*) GPIO_OUT_W1TS_REG;

// c for clear
// every bit that is set in this registry will clear the corresponding GPIO
volatile uint32_t* gpio_out_w1tc_reg = (volatile uint32_t*) GPIO_OUT_W1TC_REG;

// every bit that is set in this registry will enable output on the corresponding GPIO
volatile uint32_t* gpio_enable_reg = (volatile uint32_t*) GPIO_ENABLE_REG;

void gpio_enable_output(gpio_num_t gpio_num)
{
    *gpio_enable_reg += (1 << gpio_num);
    // FIXME
}

void gpio_set_output(gpio_num_t gpio_num, uint32_t level)
{
    if (level == 1)
    {
        // HIGH
        *gpio_out_w1ts_reg = (1 << gpio_num);
    }
    else if (level == 0)
    {
        *gpio_out_w1tc_reg = (1 << gpio_num);
    }
    else {
        // ERROR
    }
}
