#include <stdio.h>
#define STRING_1 "For he's a jolly good fellow!"
#define STRING_2 "That nobody can deny!"

// Function protypes //
void jolly();
void deny();

int main() {
    jolly();
    jolly();
    jolly();
    deny();
    return 0;
}

void jolly() {
    printf("%s\n", STRING_1);
}

void deny() {
    printf("%s\n", STRING_2);
}