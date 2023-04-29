/*
 * NukeJr - Dr. Evil’s baby nuke
 */
#include <stdio.h>
#include <stdlib.h>

int overflow(void);
int one = 1;

/* main - NukeJr’s main routine */
int main()
{
    int val = overflow();

    val += one;
    if (val != 15213)
        printf("Boom!\n");
    else
        printf("Curses! You’ve defused NukeJr!\n");
    _exit(0); /* syscall version of exit that doesn’t need %ebp */
    // _exit(0); /* syscall version of exit that doesn’t need %ebp */
    // return 0;
}

/* overflow - writes to stack buffer and returns 15213 */
int overflow()
{
    char buf[4];
    int val, i = 0;

    while (scanf("%x", &val) != EOF)
        buf[i++] = (char)val;
    return 15213;
}
