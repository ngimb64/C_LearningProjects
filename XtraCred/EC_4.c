#include <stdio.h>
#include <string.h>
#define ARR_SIZE 128
#define SPACE " "

// Function Prototypes //
void printOutput(char* value);
char* trimRight(char* str, const char* trimChars);

int main(int argc, char *argv[]) {
    char input[ARR_SIZE];

    // If args is greater than 1 //
    if (argc > 1) {
        // Copy first arg to beginning of array //
        strcpy(input, argv[1]);
        // For the remainer args //
        for (int i=2; i < argc; i++) {
            // Concatenate remainer args //
            strcat(input, SPACE);
            strcat(input, argv[i]);
        }
    }
    // If no args, user is prompted for input //
    else {
    printf("Enter a string:\t");
    fgets(input, ARR_SIZE, stdin);
    }

    printOutput(input);
    return 0;
}

void printOutput(char* value){
    // Trim extra whitespace and print result //
    trimRight(value, NULL);
    printf("\n%d : %s", strlen(value), value);
}

char* trimRight(char* str, const char* trimChars) {
	if (trimChars == NULL) {
		trimChars = "\t\n\v\f\r";
	}
	int i = strlen(str) - 1;
	while (i >= 0 && strchr(trimChars, str[i]) != NULL) {
        str[i] = '\0';
		i--;
	}
	return str;
}