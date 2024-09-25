#include <stdio.h>
#include <stdlib.h>
#include <term.h>

int main() {
    const char *termtype = "xterm";  // Specify terminal type
    char buffer[1024];                // Buffer for terminal capabilities

    // Initialize the terminal database
    if (tgetent(buffer, termtype) <= 0) {
        fprintf(stderr, "Could not find terminal type: %s\n", termtype);
        return EXIT_FAILURE;
    }

    // Check for the number of lines and columns
    int num_lines = tgetnum("li");  // Get number of lines
    int num_columns = tgetnum("co"); // Get number of columns

    // Output the results
    printf("Terminal: %s\n", termtype);
    printf("Number of lines: %d\n", num_lines);
    printf("Number of columns: %d\n", num_columns);

    return EXIT_SUCCESS;
}
