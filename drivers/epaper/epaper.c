#include "epaper.h"
#include "driver/spi_common.h"
#include "esp_err.h"
#include "esp_system.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"

void
epaper_init(epaper_t* epaper) {
    esp_err_t err;

    spi_bus_config_t buscfg = {
        .miso_io_num = epaper->miso_pin,
        .mosi_io_num = epaper->mosi_pin,
        .sclk_io_num = epaper->clk_pin,
        .quadhd_io_num = -1,
        .quadwp_io_num = -1,
        .max_transfer_sz = 16 * 320 * 2 + 8,
    };

    spi_device_interface_config_t devcfg = {
        .clock_speed_hz = 10000000,
        .mode = 0,
        .spics_io_num = epaper->cs_pin,
        .queue_size = 7,
    };
    
    err = spi_bus_initialize(epaper->spi_host, &buscfg, SPI_DMA_CH_AUTO);
    ESP_ERROR_CHECK(err);

    err = spi_bus_add_device(epaper->spi_host, &devcfg, &epaper->spi_handle);
    ESP_ERROR_CHECK(err);
}

