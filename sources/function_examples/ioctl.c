#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main() {
    struct winsize w;

    // Use ioctl to get the size of the terminal window
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1) {
        perror("ioctl");
        return 1;
    }

    printf("Terminal rows: %d, columns: %d\n", w.ws_row, w.ws_col);
    return 0;
}
