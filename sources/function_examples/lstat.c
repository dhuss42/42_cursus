#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    struct stat fileStat;
    const char *filename = "example_symlink"; // symbolic link

    // Use lstat() to get the status of the symbolic link
    if (lstat(filename, &fileStat) < 0) {
        perror("Failed to get symbolic link status");
        return EXIT_FAILURE;
    }

    // Check if the file is a symbolic link
    if (S_ISLNK(fileStat.st_mode)) {
        printf("%s is a symbolic link.\n", filename);
    } else {
        printf("%s is not a symbolic link.\n", filename);
    }

    // Print file information
    printf("File: %s\n", filename);
    printf("Size: %lld bytes\n", (long long) fileStat.st_size);
    printf("Permissions: %o (octal)\n", fileStat.st_mode & 0777);
    printf("Last accessed: %s", ctime(&fileStat.st_atime));
    printf("Last modified: %s", ctime(&fileStat.st_mtime));

    return EXIT_SUCCESS;
}
