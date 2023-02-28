/* C program to display factorial of an integer if user enters non-negative integer. */

#include <stdlib.h>

long long int OBF_FUNC(int n)
{
    if (n <= 0) {
      return 1;
    }
    int count;
    long long int factorial=1;

    count = 1;
    for (;count<=n;)
    {
        factorial*=count;              /* factorial=factorial*count */
        ++count;
    }
    return factorial;
}

int main(int argc, char **argv) {
  return (int) OBF_FUNC(atoi(argv[1]));
}

