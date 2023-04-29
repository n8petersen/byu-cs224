#include <stdio.h>

long fun0(long x, long y, long z)
{
    long val = 0;
    if (x < y)
    {
        if (x < z)
        {
            val = x;
        }
        else
        {
            val = y;
        }
    }
    else if (z < y)
    {
        val = z;
    }
    return val;
}

long fun1(long x, long y, long z)
{
    long val = 0;
    if (x <= y)
    {
        if (x <= z)
        {
            val = x;
        }
        else
        {
            val = y;
        }
    }
    else if (z <= y)
    {
        val = z;
    }
    return val;
}

long fun2(long x, long y, long z)
{
    long val = 0;
    if (x > y)
    {
        if (x > z)
        {
            val = x;
        }
        else
        {
            val = y;
        }
    }
    else if (z > y)
    {
        val = z;
    }
    return val;
}

int main()
{
    long x = 1;
    long y = 5;
    long z = 1;

    long result0 = fun0(x, y, z);
    long result1 = fun1(x, y, z);
    long result2 = fun2(x, y, z);
    printf("fun0: %ld\n", result0);
    printf("fun1: %ld\n", result1);
    printf("fun2: %ld\n", result2);
}