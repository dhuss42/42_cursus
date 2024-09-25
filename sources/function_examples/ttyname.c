#include <stdio.h>
#include <unistd.h>

int main() {
    // Get the name of the terminal associated with standard input (fd 0)
    char *terminal_name = ttyname(0); // 0 is for stdin

    // Check if ttyname succeeded
    if (terminal_name != NULL) {
        printf("The terminal name is: %s\n", terminal_name);
    } else {
        perror("ttyname failed");
        return 1;
    }

    return 0;
}
