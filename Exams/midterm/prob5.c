#include <stdio.h>

int main() {
    char str[16];
    int *i_ptr = (int *)str;
    long *u_ptr = (long *)(i_ptr + 1);
    char *c_ptr = (char *)(u_ptr + 1);

    scanf("%x", i_ptr);
    scanf("%lx", u_ptr);
    scanf("%s", c_ptr);

    printf("str = %s\n", str);
    return 0;
}
