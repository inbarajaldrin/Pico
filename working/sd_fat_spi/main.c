#include <stdio.h>
#include "pico/stdlib.h"
#include "write_to_sd.h"
#include "read_from_sd.h"

int main() {
    stdio_init_all();

    printf("\r\nSD card test. Press 'w' to write or 'r' to read.\r\n");
    char ch = getchar();
    if (ch == 'w') {
        write_to_sd();
    } else if (ch == 'r') {
        read_from_sd();
    } else {
        printf("Invalid input.\r\n");
    }

    // Loop forever doing nothing
    while (true) {
        tight_loop_contents();
    }
}
