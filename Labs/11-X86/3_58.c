#include <stdio.h>

long decode2(long x, long y, long z) {
   y = y - z;
   x = x * y;
   long ans = y;
   ans = ans << 63;
   ans = ans >> 63;
   ans = ans ^ y;
   return ans; 

   // long temp = y - z;
   // return (temp << 63 >> 63) ^ (temp * x);

}

int main() {
   long x = 1;
   long y = 2;
   long z = 3;

   long ans = decode2(x,y,z);

   printf("%ld \n", ans);
   return 0;
}