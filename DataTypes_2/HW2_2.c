#include <stdio.h>

void one_three();
void two();

int main() {
    printf("Starting now:\n");
    /* push new function to stack */
    one_three();
    /* one_three() popped off stack  */
    printf("Done!!");
    return 0;
}

void one_three() {
    printf("One\n");i
    /* push new function to stack inside another function  */
    two();
    /* two() popped off stack  */
    printf("Three\n");
}

void two() {
    printf("Two\n");
}
