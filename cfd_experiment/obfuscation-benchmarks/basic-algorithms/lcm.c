/* C program to find LCM of two positive integers entered by user */

#include <stdlib.h>

int OBF_FUNC(int num1, int num2)
{
    int max;
    max=(num1>num2) ? num1 : num2; /* maximum value is stored in variable max */
    while(1)                       /* Always true. */
    {
        if(max%num1==0 && max%num2==0)
        {
            return max;
            break;          /* while loop terminates. */
        }
        ++max;
    }
}

int main(int argc, char **argv) {
  return OBF_FUNC(atoi(argv[1]), atoi(argv[2]));
}
