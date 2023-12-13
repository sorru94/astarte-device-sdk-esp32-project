#include <esp_log.h>
#include <inttypes.h>
#include <nvs_flash.h>

#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/queue.h"
#include "freertos/task.h"

#include "example_task.h"
#include "wifi_cfg.h"

/************************************************
 * Constants/Defines
 ***********************************************/

#define TAG "ASTARTE_PROJECT_APP_MAIN"

/************************************************
 * Main function definition
 ***********************************************/

void app_main()
{
    ESP_LOGI(TAG, "Startup..");
    ESP_LOGI(TAG, "Free memory: %" PRIu32 " bytes", esp_get_free_heap_size());
    ESP_LOGI(TAG, "IDF version: %s", esp_get_idf_version());

    esp_log_level_set("*", ESP_LOG_INFO);

    nvs_flash_init();
    wifi_init();

    const configSTACK_DEPTH_TYPE stack_depth = 6000;
    xTaskCreate(
        astarte_example_task, "astarte_example_task", stack_depth, NULL, tskIDLE_PRIORITY, NULL);
}
