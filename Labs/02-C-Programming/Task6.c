#include <stdio.h>

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


int main() {
    // printf("Hello World!\n");
    printf("CS224 - Lab 2 | Task 6 - Nathan Petersen \n\n");

// Task 6. Read in 5 numbers from the user and then print them out in sorted order using Bubble-sort.
    int arr[5];

    printf("Integer Sorter v1.0");
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



