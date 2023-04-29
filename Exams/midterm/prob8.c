#include <stdio.h>

int main(int argc, char* argv[]) {
    unsigned char c = 0xc2;
    int x = 0xbeef52d1;

    printf("%x\n", (unsigned int)c);
    printf("%x\n", (int)c);
    printf("%x\n", (int)((char)c));
    printf("%x\n", (int)((unsigned char)x));
    printf("%x\n", (unsigned int)((char)x));
    printf("%x\n", *((int *)((char *) &x)));
    printf("%x\n", *((unsigned char*) &x));
    printf("%x\n", (int)(*((char*) &x)));
    
    return 0;
}
