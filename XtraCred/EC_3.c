#include <stdio.h>
#define STR_BUFFER 16

int main() {
    char first[STR_BUFFER], last[STR_BUFFER];
    printf("Enter your fullname:\t");

    // Uing scanf to obtain multiple values //
    scanf("%16s %16s", &first, &last);
    printf("\nGreetings %s, %s", last, first);
    return 0;
}