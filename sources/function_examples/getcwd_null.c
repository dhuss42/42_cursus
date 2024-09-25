#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    char *cwd;

    // Call getcwd with NULL to dynamically allocate the buffer
    cwd = getcwd(NULL, 0);
    if (cwd == NULL) {
        perror("getcwd() error");
        return EXIT_FAILURE;
    }

    // Print the current working directory
    printf("Current working directory: %s\n", cwd);

    // Free the dynamically allocated memory
    free(cwd);

    return EXIT_SUCCESS;
}
