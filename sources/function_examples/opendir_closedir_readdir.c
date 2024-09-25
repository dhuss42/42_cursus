#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    DIR *dir;                   // Pointer to the directory
    struct dirent *entry;      // Pointer to directory entries

    // Open the directory (replace "path/to/directory" with your target path)
    dir = opendir("../function_examples");
    if (dir == NULL) {
        perror("Unable to open directory");
        return EXIT_FAILURE;
    }

    // Read entries from the directory
    while ((entry = readdir(dir)) != NULL) {
        // Print the name of each entry
        printf("%hu\n", entry->d_namlen);
    }

    // Close the directory
    closedir(dir);

    return EXIT_SUCCESS;
}
