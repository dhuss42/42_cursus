#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main() {
    const char *path = "../new/";

    // Try to change the working directory
    if (chdir(path) == 0) {
        printf("Directory successfully changed to: %s\n", path);
    } else {
        // Print an error message if chdir fails
        perror("chdir() error");
        return 1;
    }

    // Print the current working directory to verify the change
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s\n", cwd);
    } else {
        perror("getcwd() error");
        return 1;
    }

    return 0;
}
