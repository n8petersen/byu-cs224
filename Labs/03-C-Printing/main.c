#include <stdio.h>

int main()
{
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
    printf("\n");


    // Task 2: Initialize several different variables, of different types, and print their values out using each of the different formats shown above.
    unsigned char l = 'p';
    unsigned int m = 54;
    unsigned int n = 0x4f;

    printf("l as char: %c", l);
    printf("\nl as int: %d", l);
    printf("\nl as hex: 0x%x", l);
    printf("\n");

    printf("\nm as char: %c", m);
    printf("\nm as int: %d", m);
    printf("\nm as hex: 0x%x", m);
    printf("\n");

    printf("\nn as char: %c", n);
    printf("\nn as int: %d", n);
    printf("\nn as hex: 0x%x", n);
    printf("\n");


    // Task 3: Figure out the correct 9 decimal numbers to input to the previous code so that it prints out Go Cougs!
    // 71 111 32 67 111 117 103 115 33

    char s[10] = {71, 111, 32, 67, 111, 117, 103, 115, 33};     

    // Output the array as a C-string
    printf("\n%s", s);
    printf("\n");


    // Task 4: Write a loop to print out the hexadecimal representation of each char in the array s, after the Go Cougs! prints out.
    int s_length = sizeof(s) / sizeof(s[0]);
    for(int i = 0; i < 9; i++){
        printf("%x", s[i]);
    }
    printf("\n");



    return 0;
}    
    
