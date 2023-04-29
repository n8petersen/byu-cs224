#include <stdio.h>


//Functions for Task 6 Sorting
void swap(int *x, int *y);
int* bubble_sort(int arr[], int n);



int main() {
    // printf("Hello World!\n");
    printf("CS224 - Lab 2 - Nathan Petersen \n\n");



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



// Task 3: Create (at least) 2 arrays of different variable types and initialize them.
    char grades[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int scores[] = {90, 80, 70, 60, 50, 0};
    // int scores[] = {0, 1, 2, 3, 4, 5};



// Task 4. Combine the ideas from the previous tasks to print out the the addresses of every variable in both of your arrays.
    int grades_length = sizeof(grades) / sizeof(grades[0]);
    int scores_length = sizeof(scores) / sizeof(scores[0]);

    printf("Grades Length: %i \n", grades_length);
    for (int i = 0; i < grades_length; i++) {
        printf("grades[%i]: %p \n", i, &grades[i]);
    }

    printf("\n");

    printf("Scores Length: %i \n", scores_length);
    for (int i = 0; i < scores_length; i++) {
        printf("scores[%i]: %p \n", i, &scores[i]);
    }

    printf("\n");



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



// Task 6. Read in 5 numbers from the user and then print them out in sorted order using Bubble-sort.
    int arr[5];

    printf("\nInteger Sorter v1.0");
    printf("\n Please enter 5 values, seperated by commas");
    printf("\n (i.e:  1, 2, 10, 20, 4)");
    printf("\n Enter values here: ");
    scanf("%d, %d, %d, %d, %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);
    printf("\n");


    printf("Unsorted array:  ");
    int arr_n = sizeof(arr) / sizeof(arr[0]); // Should always be 5 since the array is initialized with size 5.
    for (int i = 0; i < arr_n; i++) {
        printf("%d", arr[i]);
        if (i < arr_n - 1) { printf(", "); } // print comma only if not the last in list.
    }
    printf("\n");
    
    int* sorted_arr = bubble_sort(arr, arr_n); // This is not a deep copy, so original array will be modified as well.
    //bubble_sort(arr, arr_n); // Because no deep copy is made, this should technically do the same thing.

    printf("Sorted array:   ");
    for (int i = 0; i < arr_n; i++) {
       printf("%d", sorted_arr[i]);
       if (i < arr_n - 1) { printf(", "); } // print comma only if not the last in list.
    }
    printf("\n");

    return 0;
}



//Functions for Task 6 Sorting
void swap(int *x, int *y) {
    int temp; 
    temp = *x;
    *x = *y;
    *y = temp;

    return;
}

int* bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
    return arr;
}