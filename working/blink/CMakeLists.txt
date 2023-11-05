cmake_minimum_required(VERSION 3.21)

include(pico_sdk_import.cmake)

project(blink)

pico_sdk_init()

add_executable(blink
        blink.c
        )

# pull in common dependencies
target_link_libraries(blink pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(blink)