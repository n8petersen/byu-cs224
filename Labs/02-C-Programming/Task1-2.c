#include <stdio.h>
int main() {
    printf("CS224 - Lab 2 | Tasks 1 & 2 - Nathan Petersen \n\n");

// Task 1: Create at least one variable of each type in your main function and assign each a value.
    char character = 'a';
    short shortint = 30000;
    int intint = 100000;
    long longint = 5000000000;
    float floatdigit = 10.11111;
    double doubledigit = 1.22222222;
    
// Task 2: Print out the address of each of the variables that you created for Task 1.
    // // Method 1: Create pointers and print the pointers
    // char *character_pointer = &character;
    // short *shortint_pointer = &shortint;
    // int *intint_pointer = &intint;
    // long *longint_pointer = &longint;
    // float *floatdigit_pointer = &floatdigit;
    // double *doubledigit_pointer = &doubledigit;
    // printf("character_pointer: %p \n", character_pointer);
    // printf("shortint_pointer: %p \n", shortint_pointer);
    // printf("intint_pointer: %p \n", intint_pointer);
    // printf("longint_pointer: %p \n", longint_pointer);
    // printf("floatdigit_pointer: %p \n", floatdigit_pointer);
    // printf("doubledigit_pointer: %p \n", doubledigit_pointer);

    // printf("\n");

    // Method 2: Print the address of the variables directly (easier)
    printf("character_pointer: %p \n", &character);
    printf("shortint_pointer: %p \n", &shortint);
    printf("intint_pointer: %p \n", &intint);
    printf("longint_pointer: %p \n", &longint);
    printf("floatdigit_pointer: %p \n", &floatdigit);
    printf("doubledigit_pointer: %p \n", &doubledigit);
    printf("\n");

    return 0;
}