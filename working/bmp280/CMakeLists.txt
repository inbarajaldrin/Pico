cmake_minimum_required(VERSION 3.12)

# Specify the path to the Pico SDK
set(PICO_SDK_PATH "/Users/aldrininbaraj/documents/pico/pico-sdk")

# Include the Pico SDK in the build
include(pico_sdk_import.cmake)

project(FeatherRP2040_BMP280 C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# Tell CMake where to find the executable source file
add_executable(${PROJECT_NAME}
    main.c
)

# Tell CMake to link the executable with the pico_stdlib (standard library for the Pico)
target_link_libraries(${PROJECT_NAME} pico_stdlib hardware_i2c)

# Enable USB output, disable UART output
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

# Create map/bin/hex/uf2 files etc.
pico_add_extra_outputs(${PROJECT_NAME})
