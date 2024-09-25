#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char *input;

    // Read input in a loop
    while ((input = readline("Input (type 'exit' to quit): ")) != NULL) {
        // If input is not empty, add it to history
        if (*input) {
            add_history(input);
        }

        // Check for the exit command
        if (strcmp(input, "exit") == 0) {
            free(input);
            break;
        }

        // Replace the current line with a modified version
        char *new_line = "This line has been replaced!";
        rl_replace_line(new_line, 1); // Replace line and clear undo history
        
        // Print the modified line
        printf("Replaced line: %s\n", new_line);
        
        // Clear the input buffer for the next input
        free(input); // Free the memory allocated by readline
    }

    return 0;
}
