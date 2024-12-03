#include <stdio.h>
#include "get_next_line_bonus.h"
int main() {
    const char *filenames[] = {"file1.txt", "file2.txt", "file3.txt"};
    int fds[3]; // Array to hold file descriptors
    char *line;
    int i;

    // Open multiple files
    for (i = 0; i < 3; i++) {
        fds[i] = open(filenames[i], O_RDONLY);
        if (fds[i] < 0) {
            perror("Error opening file");
            return EXIT_FAILURE;
        }
    }

    // Read lines from each file descriptor in a loop
    while (1) {
        int all_done = 1; // Flag to check if all files are done reading

        for (i = 0; i < 3; i++) {
            line = get_next_line(fds[i]);
            if (line) {
                printf("From %s: %s", filenames[i], line);
                free(line); // Free the allocated line after printing
                all_done = 0; // At least one file still has lines to read
            }
        }

        // If all files are done, break the loop
        if (all_done) {
            break;
        }
    }

    // Close all file descriptors
    for (i = 0; i < 3; i++) {
        close(fds[i]);
    }

    return EXIT_SUCCESS;
}
