#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_nimble_hci.h"
#include "driver/gpio.h"

#include "bluetooth.h"


void app_main()
{
    gpio_set_direction(GPIO_NUM_0, GPIO_MODE_INPUT); // boot button
    gpio_set_direction(GPIO_NUM_2, GPIO_MODE_INPUT);

    gpio_config_t io_conf;
    memset(&io_conf, 0, sizeof(io_conf));

    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = (1ULL << 15);

    gpio_set_level(GPIO_NUM_15, 1);

    connect_ble();
    xTaskCreate(boot_creds_clear, "boot_creds_clear", 2048, NULL, 5, NULL);
}