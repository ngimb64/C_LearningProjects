#include <stdio.h>

int main() {                      /* prints sizeof data type */
    printf("sizeof(char) = %u\n", sizeof(char));
    printf("sizeof(unsigned char) = %u\n", sizeof(unsigned char));
    printf("sizeof(short) = %u\n", sizeof(short));
    printf("sizeof(unsigned short) = %u\n", sizeof(unsigned short));
    printf("sizeof(int) = %u\n", sizeof(int));
    printf("sizeof(unsigned int) = %u\n", sizeof(unsigned int));
    printf("sizeof(long) = %u\n", sizeof(long));
    printf("sizeof(unsigned long) = %u\n", sizeof(unsigned long));
    printf("sizeof(float) = %u\n", sizeof(float));
    printf("sizeof(double) = %u", sizeof(double));
    return 0;
}
