#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>    // For open()
#include <unistd.h>   // For close()

int main() {
    struct stat fileStat;
    const char *filename = "example.txt";
    
    // Open the file to get its file descriptor
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    // Use fstat() to get information about the open file descriptor
    if (fstat(fd, &fileStat) < 0) {
        perror("Failed to get file status");
        close(fd);
        return EXIT_FAILURE;
    }

    // Print file information
    printf("File: %s\n", filename);
    printf("Size: %lld bytes\n", (long long) fileStat.st_size);
    printf("Permissions: %o (octal)\n", fileStat.st_mode & 0777);

    // Close the file descriptor
    close(fd);

    return EXIT_SUCCESS;
}
