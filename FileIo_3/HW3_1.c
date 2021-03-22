#include <stdio.h>

int main(int argc, char *argv[]) {
    // Create pointer to filename passed in as arg //
    FILE *filePtr = fopen(argv[1], "r");

    // Checks to make sure the file pointer
    // points to an existing file //
    if (filePtr == NULL) {
        printf("* File doesn't exist *\n");
        return -1;
    }

    // Set the file stream to scan through file //
    fseek(filePtr, 0L, SEEK_END);
    
    // Get the position of the pointer since stream init // 
    long int result = ftell(filePtr);
    
    // Close file stream //
    fclose(filePtr);
    
    // Print results //
    printf("The filename %s is %li bytes in size.\n", argv[1], result);
    return 0;   
}