/* C program to find multiplication table up to 10. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void OBF_FUNC(int n)
{
    int i = 1;
    for(;i<=10;)
    {
        printf("%d * %d = %d\n", n, i, n*i);
        ++i;
    }
}

int main(int argc, char* argv[])
{
    return 0;
}
