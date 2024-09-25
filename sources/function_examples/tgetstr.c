#include <stdio.h>
#include <stdlib.h>
#include <term.h>

int main() {
    const char *termtype = "xterm";  // Specify terminal type
    char buffer[1024];                // Buffer for terminal capabilities
    char *clear_screen_2;               // Pointer for clear screen string

    // Initialize the terminal database
    if (tgetent(buffer, termtype) <= 0) {
        fprintf(stderr, "Could not find terminal type: %s\n", termtype);
        return EXIT_FAILURE;
    }

    // Get the clear screen string
    clear_screen_2 = tgetstr("cl", NULL); // Get clear screen capability

    // Check if the capability was found
    if (clear_screen_2 == NULL) {
        fprintf(stderr, "Clear screen capability not found.\n");
        return EXIT_FAILURE;
    }

    // Output the clear screen command
    printf("Clear screen command: %s", clear_screen_2);
    
    // Optionally, clear the screen
    tputs(clear_screen_2, 1, putchar); // Execute the clear screen command

    return EXIT_SUCCESS;
}
