#include <stdio.h>

int main()
{
    // Task 3: Figure out the correct 9 decimal numbers to input to the previous code so that it prints out Go Cougs!
    // 71 111 32 67 111 117 103 115 33

    // This is our array of chars
    char s[10];
    int t;
    
    // Input the char values
    for(int i = 0; i < 9; i++){
        scanf("%d", &t); // scan the int 
        s[i] = t;        // save in the char 
    }
    
    s[9] = 0; // Set the NULL character
    
    // Output the array as a C-string
    printf("%s\n", s);


    // Task 4: Write a loop to print out the hexadecimal representation of each char in the array s, after the Go Cougs! prints out.
    int s_length = sizeof(s) / sizeof(s[0]);
    for(int i = 0; i < 9; i++){
        printf("%x", s[i]);
    }
    printf("\n");


    return 0;
}

