#include <stdio.h>
int main() {
    printf("CS224 - Lab 2 | Tasks 3 & 4 - Nathan Petersen \n\n");

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


    return 0;
}