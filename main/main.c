#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "bluetooth.h"

#include "gpio_manip.h"


void app_main()
{
    connect_ble();
    xTaskCreate(boot_creds_clear, "boot_creds_clear", 2048, NULL, 5, NULL);
}