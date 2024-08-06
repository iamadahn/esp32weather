#include "epaper.h"
#include "driver/spi_common.h"
#include "esp_err.h"
#include "esp_system.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"

extern void delay_ms(uint32_t ms);

void
epaper_init(epaper_t* epaper) {
    esp_err_t err;

    spi_bus_config_t buscfg = {
        .miso_io_num = -1,
        .mosi_io_num = epaper->sda_pin,
        .sclk_io_num = epaper->scl_pin,
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

static void
epd_delay(uint32_t ms) {
    delay_ms(ms);
}

static void
epd_res_set(epaper_t* epaper) {
    gpio_set_level(epaper->res_pin, 1);
}

static void
epd_res_reset(epaper_t* epaper) {
    gpio_set_level(epaper->res_pin, 0);
}

static void
epd_dc_set(epaper_t* epaper) {
    gpio_set_level(epaper->dc_pin, 1);
}

static void
epd_dc_reset(epaper_t* epaper) {
    gpio_set_level(epaper->dc_pin, 0);
}

static void
epd_cs_set(epaper_t* epaper) {
    gpio_set_level(epaper->cs_pin, 1);
}

static void
epd_cs_reset(epaper_t* epaper) {
    gpio_set_level(epaper->dc_pin, 0);
}

static uint8_t
epd_is_busy(epaper_t* epaper) {
    return gpio_get_level(epaper->busy_pin);
}

static void
epd_write_reg(epaper_t* epaper, uint8_t reg) {
    epd_dc_reset(epaper);
    epd_cs_reset(epaper);

    uint8_t buf = reg;
    spi_transaction_t t = {
        .tx_buffer = &buf,
        .length = 1 * 8,
    };
    
    spi_device_polling_transmit(epaper->spi_handle, &t);

    epd_cs_set(epaper);
    epd_dc_set(epaper);
}

static void
epd_write_data(epaper_t* epaper, uint8_t data) {
    epd_cs_reset(epaper);

    uint8_t buf = data;
    spi_transaction_t t = {
        .tx_buffer = &buf,
        .length = 1 * 8,
    };
    
    spi_device_polling_transmit(epaper->spi_handle, &t);

    epd_cs_set(epaper);
}

static void
_epd_write_data(epaper_t* epaper, uint8_t data) {
    uint8_t buf = data;
    spi_transaction_t t = {
        .tx_buffer = &buf,
        .length = 1 * 8,
    };
    
    spi_device_polling_transmit(epaper->spi_handle, &t);
}

static void
_epd_write_data_over(epaper_t* epaper) {
    ;
}

static uint8_t
epd_wait_busy(epaper_t* epaper) {
    uint32_t timeout = 0;
    while (epd_is_busy(epaper)) {
        timeout++;
        if (timeout > 40000) {
            return 1;
        }
        epd_delay(1);
    }
    return 0;
}

static void
epd_reset(epaper_t* epaper) {
    epd_res_reset(epaper);
    epd_delay(50);
    epd_res_set(epaper);
    epd_delay(50);
}


uint8_t
epd_init(epaper_t* epaper)
{
    epd_reset(epaper);

    if (epd_wait_busy(epaper)) {
        return 1;
    }
    

    epd_write_reg(epaper, 0x12); // SWRESET

	epd_delay(10);

    if (epd_wait_busy(epaper)) {
        return 1;
    }
    
#if defined(EPD_29) || defined(EPD_213) || defined(EPD_154) 
    epd_write_reg(epaper, 0x01); // Driver output control
#if defined(EPD_29) || defined(EPD_213)
    epd_write_data(epaper, 0x27);
    epd_write_data(epaper, 0x01);
    epd_write_data(epaper, 0x01);
#else
    epd_write_data(epaper, 0xC7);
    epd_write_data(epaper, 0x00);
    epd_write_data(epaper, 0x01);
#endif

    epd_write_reg(epaper, 0x11); // data entry mode
    epd_write_data(epaper, 0x01);

#ifdef EPD_154
    epd_write_reg(epaper, 0x44); // set Ram-X address start/end position
    epd_write_data(epaper, 0x00);
    epd_write_data(epaper, 0x18);

    epd_write_reg(epaper, 0x45);  // set Ram-Y address start/end position
    epd_write_data(epaper, 0xC7);
    epd_write_data(epaper, 0x00);
    epd_write_data(epaper, 0x00);
    epd_write_data(epaper, 0x00);
#else
    epd_write_reg(epaper, 0x44); // set Ram-X address start/end position
    epd_write_data(epaper, 0x00);
    epd_write_data(epaper, 0x0F); // 0x0F-->(15+1)*8=128

    epd_write_reg(epaper, 0x45);  // set Ram-Y address start/end position
    epd_write_data(epaper, 0x27); // 0x127-->(295+1)=296
    epd_write_data(epaper, 0x01);
    epd_write_data(epaper, 0x00);
    epd_write_data(epaper, 0x00);
#endif

    epd_write_reg(epaper, 0x3C); // BorderWavefrom
    epd_write_data(epaper, 0x05);

#if defined(EPD_29) || defined(EPD_213)
    epd_write_reg(epaper, 0x21); //  Display update control
    epd_write_data(epaper, 0x00);
    epd_write_data(epaper, 0x80);
#endif

#elif defined(EPD_42)
	epd_write_reg(epaper, 0x21); // Display Update Controll
	epd_write_data(epaper, 0x40);
	epd_write_data(epaper, 0x00);
	epd_write_reg(epaper, 0x01);  // Set MUX as 300
	epd_write_data(epaper, 0x2B);
	epd_write_data(epaper, 0x01);
	epd_write_data(epaper, 0x00);
	epd_write_reg(epaper, 0x3C); //BorderWavefrom
	epd_write_data(epaper, 0x01);	
	epd_write_reg(epaper, 0x11);	// data  entry  mode
	epd_write_data(epaper, 0x03);		// X-mode
	epd_address_set(epaper, 0,0,EPD_W-1,EPD_H-1);
#endif

    epd_write_reg(epaper, 0x18); // Read built-in temperature sensor
    epd_write_data(epaper, 0x80);

    epd_setpos(epaper, 0, 0);

    if (epd_power_on(epaper)) {
        return 1;
    }

    return 0;
}

uint8_t
epd_power_on(epaper_t* epaper) {
#if defined EPD_42
	epd_write_reg(epaper, 0x22); // Display Update Control
	epd_write_data(epaper, 0xe0);
#else
	epd_write_reg(epaper, 0x22); // Display Update Control
	epd_write_data(epaper, 0xf8);
#endif
    epd_write_reg(epaper, 0x20); // Activate Display Update Sequence

    return epd_wait_busy(epaper);
}

uint8_t
epd_power_off(epaper_t* epaper) {
	epd_write_reg(epaper, 0x22); // Display Update Control
	epd_write_data(epaper, 0x83);
    epd_write_reg(epaper, 0x20); // Activate Display Update Sequence

    return epd_wait_busy(epaper);
}
