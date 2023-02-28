#include <stdio.h>
#include<stdlib.h>

long int OBF_FUNC(long int binary1, long int binary2)
{
     int i = 0;
     int remainder = 0;
     int sum[20];
     int binarySum = 0;
     while (binary1 != 0 || binary2 != 0)
     {
          sum[i] = (binary1 % 10 + binary2 % 10 + remainder) % 2;
          remainder = (binary1 % 10 + binary2 % 10 + remainder) / 2;
          binary1 = binary1 / 10;
          binary2 = binary2 / 10;
          i++;
     }
     if (remainder != 0) {
          sum[i] = remainder;
          i++;
     }
     --i;
    while(i>=0) {
     binarySum = binarySum*10 + sum[i];
         i -= 1;
    }

    return binarySum;
}

int main(int argc, char* argv[]) {
    long int binary1;
    long int binary2;
    binary1 = atol(argv[1]);
    binary2 = atol(argv[2]);
    printf("%ld", OBF_FUNC(binary1, binary2));
    return 0;
}
