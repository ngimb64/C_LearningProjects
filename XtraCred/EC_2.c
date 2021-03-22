#include <stdio.h>

int main() {
    char input;
    printf("Please enter the character for ascii conversion:\t");
    // Uses scanf() to prompt user for input //
    scanf("%2c", &input);

    // The conversion merely prints the char in a different format //
    printf("The ascii conversion of %c is .. %d", input, input);
    return 0;
}