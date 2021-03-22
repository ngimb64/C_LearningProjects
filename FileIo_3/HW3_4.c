#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARR_SIZE 64
#define SPACE " "
#define NEWLINE "\n"
#define DATA_FILE "output.txt"

// Function Protoytypes //
void error(char *message);

// Main function //
int main(int argc, char *argv[]) {
    char input[ARR_SIZE];

    // Copy signle arg to array & append new line //
    if (argc == 2) { 
    strncpy(input, argv[1], strlen(argv[1] - 1));
    strncat(input, NEWLINE, strlen(NEWLINE));
    }
    // Get input if no args provided //
    else if (argc < 2) {
        printf("Enter a string:\t");
        fgets(input, ARR_SIZE, stdin);
    }
    // If multiple args are passed in //
    else {
        // Copy first arg to beginning of array //
        strncpy(input, argv[1], strlen(argv[1] - 1));
        // For remaider args //
        for (int i=2; i < argc; i++) {
            // Concatenate remainder args //
            strncat(input, SPACE, strlen(SPACE));
            strncat(input, argv[i], strlen(argv[i]));
        }
        strncat(input, NEWLINE, strlen(NEWLINE));
    }

    // Open file & confirm it exists //
    FILE *filePtr = fopen(DATA_FILE, "a+");
    if (filePtr == NULL) {
        error("* Error occured allocating file pointer *\n");
    }
    int i, c;
    // Iterate through array indexes based on length //
    for (i=0; i < strlen(input); i++) {
        c = (int)input[i];
        // Write arg to file //
        fputc(c, filePtr);
    }
    fclose(filePtr);
    return 0;
}

// Error handler //
void error(char *message) {
    printf(message);
    exit(-1);
}