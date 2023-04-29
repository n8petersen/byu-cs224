#include <stdio.h>

int main()
{
    // unsigned char u = 51;
    // unsigned char c = '3';

    // Task 1: Find more combinations of ways to initialize u and c such that they are equal, but initialized using different methods.
    //  These two are the same, even though one is decimal and one is hex.
    unsigned char u = 90;
    unsigned char c = 0x5a;
    
    if (u == c) {
        printf("They are the same!\n");
    }
    else {
        printf("They are different!\n");
    }
    return 0;
}

