#include <stdio.h>
#include <stdlib.h>
#include <termcap.h>    // For tgetent, tgoto, tputs
#include <unistd.h>     // For STDOUT_FILENO

int main() {
    char buffer[1024];
    char *move_cursor;
    char *term_type = getenv("TERM");

    if (term_type == NULL) {
        fprintf(stderr, "TERM environment variable not set.\n");
        return 1;
    }

    // Initialize the terminal capabilities
    if (tgetent(buffer, term_type) < 0) {
        fprintf(stderr, "Could not load terminal type %s\n", term_type);
        return 1;
    }

    // Get the capability string for cursor movement
    move_cursor = tgetstr("cm", NULL);  // "cm" is the termcap code for cursor movement

    if (move_cursor == NULL) {
        fprintf(stderr, "Terminal does not support cursor movement.\n");
        return 1;
    }

    // Use tgoto() to generate the string to move the cursor to row 10, column 20
    char *cursor_move_str = tgoto(move_cursor, 20, 10);

    // Output the cursor movement string using tputs()
    tputs(cursor_move_str, 1, putchar);

    printf("Cursor moved to row 10, column 20.\n");

    return 0;
}
