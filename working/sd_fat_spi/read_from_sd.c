#include "read_from_sd.h"
#include "sd_card.h"
#include "ff.h"

void read_from_sd() {
    FRESULT fr;
    FATFS fs;
    FIL fil;
    char buf[100];
    char filename[] = "test01.txt";

    // Initialize SD card
    if (!sd_init_driver()) {
        printf("ERROR: Could not initialize SD card\r\n");
        return;
    }

    // Mount drive
    fr = f_mount(&fs, "0:", 1);
    if (fr != FR_OK) {
        printf("ERROR: Could not mount filesystem (%d)\r\n", fr);
        return;
    }

    // Open file for reading
    fr = f_open(&fil, filename, FA_READ);
    if (fr != FR_OK) {
        printf("ERROR: Could not open file (%d)\r\n", fr);
        return;
    }

    // Print every line in file over serial
    printf("Reading from file '%s':\r\n", filename);
    printf("---\r\n");
    while (f_gets(buf, sizeof(buf), &fil)) {
        printf("%s", buf); // use '%s' format specifier for strings
    }
    printf("---\r\n");

    // Close file
    fr = f_close(&fil);
    if (fr != FR_OK) {
        printf("ERROR: Could not close file (%d)\r\n", fr);
        return;
    }

    // Unmount drive
    f_unmount("0:");
}
