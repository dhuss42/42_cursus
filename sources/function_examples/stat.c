#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    struct stat fileStat;
    const char *filename = "example.txt";

    // Get file information
    if (stat(filename, &fileStat) < 0) {
        perror("Failed to get file status");
        return EXIT_FAILURE;
    }

    // Print file information
    printf("File: %s\n", filename);
    printf("Size: %lld bytes\n", (long long) fileStat.st_size);
    printf("Permissions: %o (octal)\n", fileStat.st_mode & 0777);
    printf("Last accessed: %s", ctime(&fileStat.st_atime));
    printf("Last modified: %s", ctime(&fileStat.st_mtime));

    return EXIT_SUCCESS;
}
