/* C Program to Find Highest Common Factor. */
#include <stdlib.h>

int OBF_FUNC(int num1, int num2)
{
    int i;
    int hcf;
    i=1;
    for(; i<=num1 || i<=num2;)
    {
        if(num1%i==0 && num2%i==0)   /* Checking whether i is a factor of both number */
            hcf=i;
        ++i;
    }
    return hcf;
}

int main(int argc, char **argv) {
  return OBF_FUNC(atoi(argv[1]), atoi(argv[2]));
}
