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

    // Check some capabilities with renamed variables
    int auto_right_margin_flag = tgetflag("am"); // Automatic right margin
    int num_lines = tgetnum("li");               // Number of lines
    int num_columns = tgetnum("co");             // Number of columns

    printf("Terminal: %s\n", termtype);
    printf("Automatic right margin: %s\n", auto_right_margin_flag ? "Yes" : "No");
    printf("Lines: %d\n", num_lines);
    printf("Columns: %d\n", num_columns);

    return EXIT_SUCCESS;
}
