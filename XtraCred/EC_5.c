#include <stdio.h>

int main() {
    int days, years, month;
    // Prompt user for input //
    printf("Enter age in years & month of the year: <37> <03>\n");
    scanf("%3d %3d", &years, &month);

    // Input validaion //
    if (years < 1 || years > 99 || month < 1  || month > 12) {
        printf("\n* Improper format .. check your input *");
        return -1;
    }
    // Calculate total days //
    days = (years * 365) + (month * 30);
    printf("Your age in days is %d", days);
    return 0;
}