#include <stdio.h>
#include <unistd.h>

int main() {
    const char *filename = "example.txt";

    // Check if the file is readable
    if (access(filename, R_OK) == 0) {
        printf("%s is readable.\n", filename);
    } else {
        perror("Error");
    }

    // Check if the file is writable
    if (access(filename, W_OK) == 0) {
        printf("%s is writable.\n", filename);
    } else {
        perror("Error");
    }

    // Check if the file is executable
    if (access(filename, X_OK) == 0) {
        printf("%s is executable.\n", filename);
    } else {
        perror("Error");
    }

    // Check if the file exists
    if (access(filename, F_OK) == 0) {
        printf("%s exists.\n", filename);
    } else {
        perror("Error");
    }

    return 0;
}

