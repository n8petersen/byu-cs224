#include <stdio.h>

int main() {
    long x = 0x12345678;
    printf("0x%lx \n", x);

    char new_x = (x >> 2);
    printf("0x%x \n", new_x);


    printf("\n");


    long y = 0xffffffff;
    printf("0x%lx \n", y);

    y = y & ~(0x38 << 4);
    printf("0x%lx \n", y);


    return 0;
}