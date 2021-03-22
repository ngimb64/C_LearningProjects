#include <stdio.h>
#include <conio.h>
#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {
    // Create line sized buffer //
    char line[BUFFER_SIZE];
    FILE *filePtr = fopen(argv[1], "r");
    if (filePtr == NULL) {
        printf("* File doesn't exist *\n");
        return -1;
    }

    // While the file pointer is not at end of file //
    while (!feof(filePtr )) {
        // Creates pointer to fgets() method //
        char *linePtr = fgets(line, BUFFER_SIZE, filePtr);
        // Prints hexidecimal memory address with its contents //
        printf("0x%08x address contains: %s\n", linePtr, linePtr);
    }

    fclose(filePtr);
    return 0;
}