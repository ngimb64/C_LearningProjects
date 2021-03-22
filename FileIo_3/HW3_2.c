#include <stdio.h>
#include <conio.h>

int main(int argc, char *argv[]) {
    // Create file stream with passed in arg //
    FILE *filePtr = fopen(argv[1], "r");

    // Confirm file pointer points to existing file //
    if (filePtr == NULL) {
        printf("* File doesn't exist *\n");
        return -1;
    }
    // While the file pointer is not at the end of file //
    while (!feof(filePtr)) {
        // File stream pointer get next character //
        char c = fgetc(filePtr);
        printf("%c", c);
    }
    fclose(filePtr);
    return 0;
} 