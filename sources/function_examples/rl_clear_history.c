#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char *input;

    // Read some input from the user
    while ((input = readline("Input (type 'exit' to quit): ")) != NULL) {
        // If the input is not empty, add it to history
        if (*input) {
            add_history(input);
        }

        // Check if the user wants to exit
        if (strcmp(input, "exit") == 0) {
            free(input);
            break;
        }

        // Print the input
        printf("You entered: %s\n", input);
        free(input); // Free the memory allocated by readline
    }

    // Clear the command history before exiting
    clear_history();
    printf("History cleared.\n");

    return 0;
}
