#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main() {
    struct termios oldt, newt;

    // Get the current terminal attributes and store them in 'oldt'
    tcgetattr(STDIN_FILENO, &oldt);
    
    // Make a copy of the current settings in 'newt'
    newt = oldt;

    // Modify 'newt' to disable echo (ECHO)
    newt.c_lflag &= ~(ECHO);

    // Apply the new attributes immediately
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Prompt the user for input
    printf("Enter your password: ");
    char password[100];
    fgets(password, 100, stdin);

    // Restore the original terminal attributes
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    printf("\nPassword entered: %s", password);

    return 0;
}
