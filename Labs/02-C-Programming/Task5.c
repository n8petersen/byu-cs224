#include <stdio.h>
int main() {
    // printf("Hello World!\n");
    printf("CS224 - Lab 2 | Task 5 - Nathan Petersen \n\n");

// Task 5. Read in 5 numbers from the user and compute their average. Display the numbers and the average to the user.
    int nums[5];

    printf("Average Calculator v1.0");
    printf("\n Please enter 5 values, seperated by commas");
    printf("\n (i.e:  1, 2, 10, 20, 4)");
    printf("\n Enter values here: ");
    scanf("%d, %d, %d, %d, %d", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4]);
    
    int sum = 0;

    int nums_length = sizeof(nums) / sizeof(nums[0]); // Should always be 5 since the array is initialized with size 5.
    for (int i = 0; i < nums_length; i++) {
        sum += nums[i];
    }

    int average = sum / 5;
    printf("\n average: %d", average);
    printf("\n");


    return 0;
}