#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char *input;

    // Read a line from standard input with a prompt
    input = readline("Minishell: ");

    // Check if input is NULL (EOF or error)
    if (input == NULL) {
        fprintf(stderr, "Error reading input or EOF reached.\n");
        return 1;
    }

    // Print the input
    printf("You entered: %s\n", input);

    // Add the input to history (optional)
    add_history(input);

    // Free the allocated memory for the input
    free(input);

    return 0;
}
