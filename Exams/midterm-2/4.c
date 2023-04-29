#include <stdio.h>

long int loopy0(long int x, long int y)
{
    long int i, result = 0;
    for (i = 0; i < x; i++)
    {
        result += x;
    }
    return result;
}

long int loopy1(long int x, long int y)
{
    long int i, result = 0;
    for (i = y; i > x; i--)
    {
        result += i;
    }
    return result;
}

long int loopy2(long int x, long int y)
{
    long int i, result = 0;
    for (i = y; i > 0; i--)
    {
        result += 1;
    }
    return result;
}

int main()
{
    long x = -1;
    long y = 20;

    long result0 = loopy0(x, y);
    long result1 = loopy1(x, y);
    long result2 = loopy2(x, y);
    printf("loopy0: %ld\n", result0);
    printf("loopy1: %ld\n", result1);
    printf("loopy2: %ld\n", result2);
}