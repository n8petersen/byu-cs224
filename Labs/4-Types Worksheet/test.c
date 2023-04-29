#include <stdio.h>

int main() {
    int var = 0x49;
    int *p = &var;
    long *a = (long *)p;
    printf("%lx", *a);
    printf("\n");
}

// // Problem 9
// #include <stdio.h>
// #define SIZE 4

// int main() {
//     int a[SIZE];
//     char *s_ptr = (char *)a;

//     scanf("%s", s_ptr);

//     for(int i = 0; i < SIZE - 1; i++) {
//         printf("a[%d] = %x\n", i, a[i]);
//     }

// return 0;
// }

// // Problem 10
// #include <stdio.h>
// #define SIZE 4

// int main() {
//     int a[SIZE];
//     char *s_ptr = (char *)(a+1);

//     scanf("%x", a);
//     scanf("%s", s_ptr);
//     scanf("%x", &a[3]);
//     printf("%s", (char *)a);

//     return 0;
// }

// // Problem 11
// #include <stdio.h>
// #define SIZE 24

// int main() {
//     char str[SIZE];
//     long *u_ptr = (long*)str;
//     int *i_ptr = (int *)(u_ptr + 1);
//     char *c_ptr = (char *)(i_ptr + 2);

//     scanf("%lx %x %x %s", u_ptr, i_ptr, i_ptr + 1, c_ptr);

//     printf("str = %s\n", str);
//     return 0;
// }