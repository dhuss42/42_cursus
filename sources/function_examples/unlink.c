#include <stdio.h>
#include <unistd.h>

int main() {
    // The file to be deleted
    const char *filename = "example.txt";

    // Attempt to delete the file
    if (unlink(filename) == 0) {
        printf("File %s deleted successfully.\n", filename);
    } else {
        perror("Error deleting file");
    }

    return 0;
}
