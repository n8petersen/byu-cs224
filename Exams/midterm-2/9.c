#include <stdio.h>

long int rfun(long int x, long int y)
{
    long int nx = x - 1;
    long int ny = y - 2;
    long int rv = 0;
    if (nx <= 0)
    {
        return y;
    }
    rv = rfun(nx, ny);
    return rv + y;
}

int main()
{
    long x = 5;
    long y = 12;

    long int result = rfun(x, y);

    printf("%ld\n", result);
}



// 6
// 4
// 2