#include <stdio.h>

int main()
{

    // Task 5: Write the code to print out a single char in binary. Use the other test cases, shown below, to make sure it is working.

    // This is our char being converted
    // unsigned char c = 'o';
    unsigned char c;

    printf("Input a char: ");
    scanf("%c", &c);


    // You'll also need an array to store the bit string,
    // either chars or ints will work
    // int bits[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int bits[8];

    printf("character: %c\n", c);
    printf("int: %d\n", c);
    

    // Add your binary conversion code 
    unsigned int x = c;
    for (int i = 0; i < 8; i++) {
        if (x % 2 == 1) {
            bits[7 - i] = 1;
        }
        else {
            bits[7 - i] = 0;
        }
        x = x / 2;
    }


    // Print out the resulting binary number
    printf("binary: ");
    for (int i = 0; i < 8; i++) {
        printf("%d", bits[i]);
    }
    printf("\n");


    return 0;
}    
    
