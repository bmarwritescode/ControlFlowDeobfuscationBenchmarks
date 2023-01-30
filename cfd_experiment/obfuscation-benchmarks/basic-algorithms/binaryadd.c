#include <stdio.h>

long int binaryadd(long int binary1, long int binary2)
{
     int i = 0, remainder = 0, sum[20];
     int binarySum = 0;
     while (binary1 != 0 || binary2 != 0)
     {
          sum[i++] = (binary1 % 10 + binary2 % 10 + remainder) % 2;
          remainder = (binary1 % 10 + binary2 % 10 + remainder) / 2;
          binary1 = binary1 / 10;
          binary2 = binary2 / 10;
     }
     if (remainder != 0)
          sum[i++] = remainder;
     --i;
    while(i>=0)
         binarySum = binarySum*10 + sum[i--];

    return binarySum;
}
