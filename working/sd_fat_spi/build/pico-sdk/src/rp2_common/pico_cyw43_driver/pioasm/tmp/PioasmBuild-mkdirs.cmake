# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/aldrininbaraj/Documents/Pico/pico-sdk/tools/pioasm"
  "/Users/aldrininbaraj/Desktop/DORA_cubesat_project/coconut_coding/sd_fat_spi/build/pioasm"
  "/Users/aldrininbaraj/Desktop/DORA_cubesat_project/coconut_coding/sd_fat_spi/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm"
  "/Users/aldrininbaraj/Desktop/DORA_cubesat_project/coconut_coding/sd_fat_spi/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/tmp"
  "/Users/aldrininbaraj/Desktop/DORA_cubesat_project/coconut_coding/sd_fat_spi/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp"
  "/Users/aldrininbaraj/Desktop/DORA_cubesat_project/coconut_coding/sd_fat_spi/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src"
  "/Users/aldrininbaraj/Desktop/DORA_cubesat_project/coconut_coding/sd_fat_spi/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/aldrininbaraj/Desktop/DORA_cubesat_project/coconut_coding/sd_fat_spi/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/aldrininbaraj/Desktop/DORA_cubesat_project/coconut_coding/sd_fat_spi/build/pico-sdk/src/rp2_common/pico_cyw43_driver/pioasm/src/PioasmBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
