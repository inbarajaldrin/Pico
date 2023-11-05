cmake_minimum_required(VERSION 3.21)

# Include the pico_sdk_import.cmake file. This assumes it's in the same directory level.
# If it's not, you'll need to adjust the path.
include(pico_sdk_import.cmake)

# Set the project name and the languages used.
project(sd_fat_spi C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the Raspberry Pi Pico SDK.
pico_sdk_init()

# Add the executable target with source files.
add_executable(sd_fat_spi
        main.c
        write_to_sd.c
        read_from_sd.c
        )

# Include the FatFs_SPI library directory and specify the output directory for builds.
# Adjust the path as necessary.
add_subdirectory(lib/no-OS-FatFS-SD-SPI-RPi-Pico/FatFs_SPI build)

# Link the executable with the necessary libraries.
# Ensure that 'FatFs_SPI' is the correct target name for the FatFs library.
target_link_libraries(sd_fat_spi 
        pico_stdlib
        FatFs_SPI)

# Generate additional output files (map, bin, hex, etc.).
pico_add_extra_outputs(sd_fat_spi)

# Enable USB and disable UART for stdio.
pico_enable_stdio_usb(sd_fat_spi 1)
pico_enable_stdio_uart(sd_fat_spi 0)
