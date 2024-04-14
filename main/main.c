#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/adc.h"

#include "bluetooth.h"
#include "gpio_manip.h"

#define GPIO_PUMP 5

void setup();

void app_main()
{
    setup();
    connect_ble();
    xTaskCreate(boot_creds_clear, "boot_creds_clear", 2048, NULL, 5, NULL);
}

void setup()
{
    // PUMP
    gpio_enable_output(GPIO_PUMP);
    gpio_set_output(GPIO_PUMP, 0);

    // HUMIDITY SENSOR
    adc1_config_width(ADC_WIDTH_BIT_12); // Résolution de 12 bits
    adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_DB_0); // Utiliser GPIO36 (ADC1_CHANNEL_0) avec une atténuation de 0 dB

    gpio_enable_output(GPIO_NUM_19);
    gpio_set_output(GPIO_NUM_19, 1);

}