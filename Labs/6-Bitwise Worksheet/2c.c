#include <stdio.h>

int main() {
    int x = 0x12345678;

    x = (char)(x << (3 * 4) >> (7 * 4));
    printf("%x", x);
    printf("\n");

    x = 0x12345678;
    
    x = (x | (0xa) << (4 * 4));
    printf("%x", x);
    printf("\n");
    


    return 0;
}