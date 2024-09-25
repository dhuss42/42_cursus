#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    int slot_number = ttyslot(); // Get the terminal slot number

    // Check if ttyslot succeeded
    if (slot_number != -1) {
        printf("The terminal slot number is: %d\n", slot_number);
    } else {
        perror("ttyslot failed");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
