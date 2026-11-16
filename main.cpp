#include "definitions.h"
extern "C" void app_main()
{
    snprintf(mensaje, sizeof(mensaje),
             "Hola desde %s\n", DEVICE_NAME);
    ultimo_envio = esp_timer_get_time();

    while (1)
    {
        if (esp_timer_get_time() - ultimo_envio >= dt)
        {
            uart.write(mensaje, strlen(mensaje));
            ESP_LOGI(DEVICE_NAME, "Mensaje enviado");

            ultimo_envio = esp_timer_get_time();
        }

        if (uart.available() > 0)
        {
            int len = uart.read(recibido, sizeof(recibido));

            if (len > 0)
            {
                ESP_LOGI(DEVICE_NAME, "Recibido: %s", recibido);
            }
        }
    }
}