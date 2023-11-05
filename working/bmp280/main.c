#include "pico/stdlib.h"
#include "hardware/i2c.h"

// Define I2C instance for RP2040 (usually 0 or 1)
#define I2C_PORT i2c0
// Define the default I2C address for BMP280
#define BMP280_ADDR 0x76

int main() {
    stdio_init_all();
    printf("BMP280 test\n");

    // Initialize I2C
    i2c_init(I2C_PORT, 100 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);

    // Initialize BMP280
    // Note: You need to implement the bmp280_init function according to your sensor's interface
    if (!bmp280_init(I2C_PORT, BMP280_ADDR)) {
        printf("Could not find a valid BMP280 sensor, check wiring!\n");
        while (1);
    }

    // Main loop
    while (1) {
        // Read temperature, pressure, etc.
        float temperature, pressure;
        bmp280_read(&temperature, &pressure);

        printf("Temperature = %f *C\n", temperature);
        printf("Pressure = %f Pa\n", pressure);

        sleep_ms(2000);
    }

    return 0;
}
