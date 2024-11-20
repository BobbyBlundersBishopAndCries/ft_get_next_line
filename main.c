#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int main() {
    char *b; // Buffer to hold data
    int fd = open("file.txt", O_RDONLY); // Open the file in read/write mode

    // Check if the file was opened successfully
    if (fd == -1) {
        perror("Error opening file");
        return 1; // Exit with error code
    }

    while ((b = get_next_line(fd)) != NULL)
    {
        printf("%s", b);
        free(b);
    }

    close(fd);
    return (0);
}

